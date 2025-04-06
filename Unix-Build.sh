BUILT_TARGET="Debug"

cd $(dirname "$0")
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE="$BUILD_TARGET" ../
make
./NxEngine
