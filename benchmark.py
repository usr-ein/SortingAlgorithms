#!/usr/bin/env python3
"""
 Copyright (c) 2020 Samuel Prevost.
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
"""
import pandas as pd
from matplotlib import pyplot as plt
import numpy as np
from sys import argv
import os.path

def main():
    if len(argv) < 3:
        print(f"Usage {argv[0]} benchmark.csv plot_folder")
        exit()

    benchmark_csv = argv[1]
    plot_folder = argv[2]
    df = pd.read_csv(benchmark_csv, index_col=0)
    df.drop(axis=1, labels=df.columns[-1], inplace=True) # Drop the one empty col at the end
    cols = [int(i.strip()) for i in df.columns.to_list()]
    for j in range(len(df)):
        plt.figure(figsize=(16, 9))
        for i in range(len(df)-j):
            plt.plot(cols, df.to_numpy()[i]/1e3, label=df.index[i])
        plt.legend()
        plt.title("Benchmark of sorting algorithms")
        plt.xlabel("Array size")
        plt.ylabel("time in ms")
        plt.savefig(os.path.join(plot_folder, f"benchmark_{len(df)-j}_funcs.pdf"))
        plt.close()

if __name__ == '__main__':
    main()