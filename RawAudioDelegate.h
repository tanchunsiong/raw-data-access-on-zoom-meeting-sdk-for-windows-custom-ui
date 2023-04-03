//added for raw data access
#pragma once
#include "stdafx.h"
#include "rawdata/rawdata_audio_helper_interface.h"
#include "zoom_sdk.h"
#include "zoom_sdk_raw_data_def.h"
#include <iostream>


//added for raw data access
using namespace std;
using namespace ZOOM_SDK_NAMESPACE;

class RawAudioDelegate :
	public ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataDelegate
{
public:
	virtual void onMixedAudioRawDataReceived(AudioRawData* data_);
	virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, uint32_t node_id);
};
