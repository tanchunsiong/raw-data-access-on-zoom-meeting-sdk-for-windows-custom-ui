//added for raw data access
#pragma once
#include "rawdata/rawdata_video_source_helper_interface.h"
#include "rawdata/rawdata_renderer_interface.h"
#include "zoom_sdk.h"
#include "zoom_sdk_raw_data_def.h"

//added for raw data access
using namespace std;
using namespace ZOOMSDK;

//added for raw data access
class RawVideoDelegate :
	public IZoomSDKRendererDelegate
{
//added for raw data access
public:
	virtual void onRawDataFrameReceived(YUVRawDataI420* data);
	virtual void onRawDataStatusChanged(RawDataStatus	status);

	virtual void onRendererBeDestroyed();

};
