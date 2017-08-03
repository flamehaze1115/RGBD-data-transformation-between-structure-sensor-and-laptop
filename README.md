# RGBD-data-transformation-between-structure-sensor-and-laptop
This code is aim to transfer RGBD data between iPad and laptop.
The Server side is simple, just send an image, then receive RGB data and depth data respectively.
The Client side is based on structure sensor SDK, use GCDAsyncSocket to connect to Server. The image which is sent by Server will replace surface normals view.