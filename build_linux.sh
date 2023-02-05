dir="build"

if [[ ! -e $dir ]]; then
    echo "Creating $dir"
    mkdir $dir
elif [[ -e $dir ]]; then
    echo "Removing $dir"
    rm -r $dir
    echo "Creating $dir"
    mkdir $dir
elif [[ ! -d $dir ]]; then
    echo "$dir already exists but is not a directory"
fi
cd build
cmake ../source -G "MinGW Makefiles"
make -j