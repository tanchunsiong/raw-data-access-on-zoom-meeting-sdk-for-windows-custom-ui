## Demo of Raw Audio and Raw Video access over Zoom Meeting SDK, Custom UI

This is a sample code of how you can access raw audio and raw video using Custom UI
It is based on Meeting SDK for Windows, Version 5.15.7

Here are some assumptions

- The user who use the bot choose the customized interface
- The user who is accessing raw audio and raw video has host, co-host, or recording permission
- The SDK has successfully joined the meeting, subsequently has an "in meeting" status, and "start recording status" before raw audio and raw video can be access
- The code snipplets' starting point happens when user clicks on the "local record" button in Custom UI

There are a total of 6 files which have been altered and created.

I will not provided the full SDK here, you will need to download Meeting SDK for Windows Version 5.15.7 from marketplace.zoom.us


Add the code listed below.

- Added: RawAudioDelegate.cpp
- Added: RawAudioDelegate.h
- Added: RawVideoDelegate.cpp
- Added: RawVideoDelegate.h

Alter the code listed below

- Replace: CustomizedUIRecordMgr.h
- Replace: CustomizedUIRecordMgr.cpp

To help you understand the code, I've used the comments in these source and header files
`//added for raw data access` in `CustomizedUIRecordMgr.h` and `CustomizedUIRecordMgr.cpp`


The output file will be audio.pcm and output.yuv found in the root directory `zoom-sdk-windows-5.15.7.20385\x64\demo\sdk_demo_v2\`

Convert `audio.pcm` to a playable wav file by using `ffmpeg -f s16le -ar 32k -ac 1 -i audio.pcm audio.wav`. You will need to install ffmpeg if you have not already done so.

Convert `360.yuv`, `720.yuv` and `1080.yuv` to a playable mp4 file by using either
 - `ffmpeg -f rawvideo -vcodec rawvideo -s 640x360 -r 25 -pix_fmt yuv420p -i 360.yuv -c:v libx264 360.mp4`
 - `ffmpeg -f rawvideo -vcodec rawvideo -s 1280x720 -r 25 -pix_fmt yuv420p -i 720.yuv -c:v libx264 720.mp4`
 - `ffmpeg -f rawvideo -vcodec rawvideo -s 1920x1080 -r 25 -pix_fmt yuv420p -i 1080.yuv -c:v libx264 1080.mp4`
You will need to install ffmpeg if you have not already done so.

> If in RawVideoDelegate.cpp, on RawDataFrameReceive the name is output.yuv name a command that can be used to convert is the same as

 - `ffmpeg -s 640x480 -i .\output.yuv -ss 00:00:00 -c:v libx264 -s:v 640x480 -t 00:08:20 output.mp4`

## Troubleshooting

Why does my YUV video looks distorted?

Why are there 3 different YUV (360,720,1080) files above?
