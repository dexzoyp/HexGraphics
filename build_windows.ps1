if(Test-Path -Path "build"){
    Remove-Item "build" -Recurse
}
mkdir build
cd build
cmake ..\source -G "MinGW Makefiles"
mingw32-make.exe -j
mingw32-make.exe install
