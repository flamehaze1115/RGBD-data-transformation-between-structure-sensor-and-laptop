# RGBD-data-transformation-between-structure-sensor-and-laptop
This code is aim to transfer RGBD data between iPad with [Structure sensor](https://structure.io/) and laptop. A software called Skanect also can transfer RGBD data, but it’s not open source and we can’t get raw data from Skanect. <br>
The Server side is simple, just send an image as a signal, then receive RGB data and depth data respectively. It needs Visual Studio 2015, OpenCV and link ws2_32.lib (Project->properties->linker->input->additional dependence). <br>
The Client side is based on structure sensor SDK viewer, use GCDAsyncSocket to connect to Server. It will send RGB and depth data after receiving something from server side. The image which is sent by Server will replace surface normals view. It needs latest iOS and Xcode.
This is a simple demo, I use Structure sensor and SLAM on laptop to build a simple AR system which contains simple physical engine. <br>
https://www.youtube.com/playlist?list=PLTokjwc7iHxxjVWzjbYXtoQQa_gu0Drbu <br>
If you have any questions, please contact me. 
