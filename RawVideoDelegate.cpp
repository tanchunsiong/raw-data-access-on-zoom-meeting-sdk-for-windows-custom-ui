//added for raw data access
#include "stdafx.h"
#include "rawdata/rawdata_video_source_helper_interface.h"
#include "RawVideoDelegate.h"
#include "zoom_sdk_def.h" 
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <cstdio>

//added for raw data access
using namespace std;
using namespace ZOOM_SDK_NAMESPACE;

//added for raw data access
void RawVideoDelegate::onRawDataFrameReceived(YUVRawDataI420* data)
{
	cout << "onRawDataFrameReceived." << endl;
	
	cout << "width." << data->GetStreamWidth() << endl;
	cout << "height." << data->GetStreamHeight() << endl;


	/////////////////////////////////////////////////////////////////////////
	////traditional method 2
	// // Open the output file
	//std::ofstream outFileY("outputY.yuv", ios::out | ios::binary | ios::app);

	//if (!outFileY.is_open())
	//{
	//	std::cerr << "Failed to open the output file" << std::endl;
	//	return;
	//}

	//// Write the video data
	//outFileY.write((char*)data->GetBuffer(), data->GetBufferLen());


	//// Close the file
	////outFileY.close();
	//outFileY.flush();

	////cout << "YUV420 buffer saved to file." << endl;


	////end traditional method 2
	///////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////
	// traditional method 1


	std::string filename="output.yuv";

	// Open the file for writing
	if (data->GetStreamHeight() == 1080) {
		filename = "1080.yuv";
	}
	if (data->GetStreamHeight() == 720) {
		filename = "720.yuv";
	}
	else if (data->GetStreamHeight() == 360) {
		filename = "360.yuv";
	}
	else if (data->GetStreamHeight() == 180) {
		filename = "180.yuv";
	}
	else if (data->GetStreamWidth() == 90) {
		filename = "90.yuv";
	}

	ofstream outputFile1(filename, ios::out | ios::binary | ios::app);
	if (!outputFile1.is_open())
	{
		cout << "Error opening file." << endl;
		return;
	}
	char* _data1 = new char[data->GetStreamHeight() * data->GetStreamWidth() * 3 / 2];

	memset(_data1, 0, data->GetStreamHeight() * data->GetStreamWidth() * 3 / 2);

	// Copy Y buffer
	memcpy(_data1, data->GetYBuffer(), data->GetStreamHeight() * data->GetStreamWidth());

	// Copy U buffer
	size_t loc1 = data->GetStreamHeight() * data->GetStreamWidth();
	memcpy(&_data1[loc1], data->GetUBuffer(), data->GetStreamHeight() * data->GetStreamWidth() / 4);


	// Copy V buffer
	loc1 = (data->GetStreamHeight() * data->GetStreamWidth()) + (data->GetStreamHeight() * data->GetStreamWidth() / 4);
	memcpy(&_data1[loc1], data->GetVBuffer(), data->GetStreamHeight() * data->GetStreamWidth() / 4);



	//outputFile.write((char*)data->GetBuffer(), data->GetBufferLen());
	// Write the Y plane
	outputFile1.write(_data1, data->GetStreamHeight() * data->GetStreamWidth() * 3 / 2);
	
	// Close the file
	//outputFile1.close();
	outputFile1.flush();
	//cout << "YUV420 buffer saved to file." << endl;

	//end traditional method
	/////////////////////////////////////////////////////////////////////
 
	

	

}
void RawVideoDelegate::onRawDataStatusChanged(RawDataStatus status)
{
	cout << "onRawDataStatusChanged." << endl;
}

void RawVideoDelegate::onRendererBeDestroyed()
{
	cout << "onRendererBeDestroyed ." << endl;
}