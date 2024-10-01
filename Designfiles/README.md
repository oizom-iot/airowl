# Example squareline demo on ESP32 and ESP32-S3

 platforms: M5Stack Core2 and CoreS3, Lilygo T-S3, Sunton 8048S070
 stacks: LVGL, Arduino_GFX, Squareline, Arduino

works, but not the final word - this represents my learning curve
for instance, I did not even try the [canonical ESP32 LVGL support](https://github.com/lvgl/lv_port_esp32)

![alt core2](https://i.imgur.com/bSeJPyV.png)

credits to [RileyCornelius](https://github.com/RileyCornelius/M5Stack-Core2-Lvgl-Example)


## Build

This repo uses lvgl and other libraries as a git submodule:

````
git clone  https://github.com/mhaberler/squareline-esp32.git
cd squareline-esp32/
git submodule update --init --recursive

````

Choose target and build.


