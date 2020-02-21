#!/usr/bin/env bash
# Copyright (c) 2020 Samuel Prevost.
# Licensed under the Apacyhe License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This script compiles the benchmark CMake target, run it with make, run the benchmaring
# program with the following parameters and then feeds the resulting CSV to Python for plotting
# Feel free to change the parameters of the benchmark

max_val=$((2**30))  # Max val in test arrays
seed=42             # Seed for reproducibility
min_size=0          # Min size of the array
max_size=$((2**14)) # Max size of the array
step=2              # Step in the size of the array
exp_step=1          # Whether the next size should be n := n * step or n := n + step
                    # usually should be exp_step=1 to avoid long testing time

PLOT_FOLDER=plots                           # Folder where to put the plots
CMAKE_BUILD_FOLDER=cmake-build-benchmark    # Folder to create for the build

###########################################

BASE_PWD=$PWD
if [[ ! -d $PLOT_FOLDER ]]; then
    mkdir $PLOT_FOLDER
fi

if [[ ! -d $CMAKE_BUILD_FOLDER ]]; then
    mkdir $CMAKE_BUILD_FOLDER
fi
cd $CMAKE_BUILD_FOLDER  
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ..
make benchmark -j 4

echo "Benchmarking with the following parameters:"
echo -e "max_val =\t $max_val"
echo -e "seed =\t\t $seed"
echo -e "min_size =\t $min_size"
echo -e "max_size =\t $max_size"
echo -e "step =\t\t $step"
echo -e "exp_step =\t $exp_step"

./benchmark $max_val $seed $min_size $max_size $step $exp_step > benchmark.csv
echo "Done."
echo "Generating plots under $BASE_PWD/$PLOT_FOLDER"
$(which python3) ../benchmark.py benchmark.csv ../$PLOT_FOLDER
echo "Done."

# Only macOs from now on
if [[ ! $(uname -s) == Darwin* ]]; then
    exit
fi

function open_plots(){
    for plot in ../$PLOT_FOLDER/*.pdf; do
        open $plot
    done
}

while true; do
    read -p "Would you like to open the plots ?[Yy/Nn]" yn
    case $yn in
        [Yy]* ) open_plots; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
