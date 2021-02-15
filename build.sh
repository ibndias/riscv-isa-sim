rm -rf ./build
mkdir build
cd build
../configure --prefix=/home/derry/riscv
make -j16
sudo make install