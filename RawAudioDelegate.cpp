
//added for raw data access
#include "stdafx.h"
#include "rawdata/rawdata_audio_helper_interface.h"
#include "RawAudioDelegate.h"
#include "zoom_sdk_def.h"


#include <fstream>

//added for raw data access
using namespace std;
using namespace ZOOM_SDK_NAMESPACE;

//added for raw data access
void RawAudioDelegate::onOneWayAudioRawDataReceived(AudioRawData* data_, uint32_t node_id)
{
    std::cout << "+++ data received from node:" << node_id << std::endl;
    //int buffer_len = data_->GetBufferLen();
    //std::cout << buffer_len;
}

//added for raw data access
void RawAudioDelegate::onMixedAudioRawDataReceived(AudioRawData* data_)
{
    std::cout << "Received onMixedAudioRawDataReceived" << std::endl;
    //int buffer_len = data_->GetBufferLen();
    //std::cout << buffer_len;

	static ofstream pcmFile;
	pcmFile.open("audio.pcm", ios::out | ios::binary | ios::app);

	if (!pcmFile.is_open()) {
		cout << "Failed to open wave file" << endl;
		return;
	}
	try {
		// Write the audio data to the file
		pcmFile.write((char*)data_->GetBuffer(), data_->GetBufferLen());
		//std::cout << "buffer length: " << audioRawData->GetBufferLen() << std::endl;
		std::cout << "buffer : " << data_->GetBuffer() << std::endl;

		// Close the wave file
		pcmFile.close();
		pcmFile.flush();
	}
	catch (exception e)
	{
		cout << "Failed to write wave file" << endl;
	}

}

