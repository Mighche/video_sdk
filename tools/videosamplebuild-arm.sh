#/bin/sh
cd ..
mkdir video_sample_build_arm
cd video_sample_build_arm
cmake .. -DCMAKE_BUILD_TYPE=Debug  -D_MP4V2=1 -D_ONVIF=1 -D_SAMPLE=1 -DCMAKE_TOOLCHAIN_FILE=../linux-arm.txt  -DARM-LINUX=1
make -j4