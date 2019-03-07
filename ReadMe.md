This is a project use dlib and OpenCV to implement a log system.

You need to install OpenCV firstly.
dlib.19.16 has been in the folder.

build your log system by
```bash
cd log_system
mkdir build
cd build
cmake ..
make
```
then run ./log_test
follow the indication

you can use pictures in the faces folder to test.

Code is based on dlib example `dnn_face_recognition_ex`. Save data and read data to XML file by OpenCV's FileStorage. It has been tested under Ubuntu1404 64bit, and all is well.

Code is easy to understand, at least I think so.

@ 2019.03.07
* change to build .so file, so add below command to CMakeLists.txt of dlib to fix bug
`add_compile_options(-fPIC)`
* change to use OpenCV to load image, so we don't need to add sub cmake
* you can use dlib load and .a version before this day


**Thank you for your star! (grinning)**