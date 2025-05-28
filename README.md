# TODO
Document some stuff

## Boost library
Boost library can either be installed system wide:
```sh
# For Ubuntu/WSL
sudo apt install libboost-all-dev
```

Or alternatively it can be installed only for this project:
```sh
# compile and install boost into the project dir
./init-boost.sh

# set the necessary environmental variables
# Note: Doing it this way may not work work for an IDE such as VSCode
#       there are probably other/better ways to do it there but idk.
source boost.env
```

