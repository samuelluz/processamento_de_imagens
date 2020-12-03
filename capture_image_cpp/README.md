# comando para compilar
```
g++ src/webcam.cpp src/camera.cpp -o wecam -std=c++11 `pkg-config --cflags --libs opencv` -I inc/
```