## Demo of Raw Audio and Raw Video access over Zoom Meeting SDK, Custom UI

This is a  sample code of how you can access raw audio and raw video using Custom UI
It is based on Meeting SDK for Windows, Version 5.14.0

Here are some assumptions

- The user who is accessing raw audio and raw video has host, co-host, or recording permission
- The SDK has successfully joined the meeting, subsequently has an "in meeting" status, and "start recording status" before raw audio and raw video can be access
- The code snipplets' starting point happens when user clicks on the "local record" button in Custom UI

There are a total of 6 files which have been altered and created.
I will not provided the full SDK here, you will need to download Meeting SDK for Windows Version 5.14 from marketplace.zoom.us
Add / alter the code listed below.

To help you understand the code, I've used the comments in these source and header files
`//added for raw data access`

- Altered: CustomizedUIRecordMgr.h
- Altered: CustomizedUIRecordMgr.cpp
- Added: RawAudioDelegate.cpp
- Added: RawAudioDelegate.h
- Added: RawVideoDelegate.cpp
- Added: RawVideoDelegate.h

The output file will be audio.pcm and output.yuv found in the root directory
Convert audio.pcm to a playable wav file by using `ffmpeg -f s16le -ar 32k -ac 1 -i audio.pcm audio.wav`
Convert output.yuv to a playable mp4 file by using either
 - `ffmpeg -f rawvideo -vcodec rawvideo -s 640x360 -r 25 -pix_fmt yuv420p -i 360.yuv -c:v libx264 360.mp4`
 - `ffmpeg -f rawvideo -vcodec rawvideo -s 1280x720 -r 25 -pix_fmt yuv420p -i 720.yuv -c:v libx264 720.mp4`
 - `ffmpeg -f rawvideo -vcodec rawvideo -s 1920x1080 -r 25 -pix_fmt yuv420p -i 1080.yuv -c:v libx264 1080.mp4`

## Troubleshooting

Why does my YUV video looks distorted?
