# Sorting Algorithms
--
This is a list of easy C++ basic sorting algorithms as well as a way to benchmark them one to another.
Feel free to reuse this bits of code in any future project !

## Comparison

Algorithms in speed order asymptotically (tested on random array data, c.f. benchmarks)
<table>
    <tr>
        <th>Algorithm</th>
        <th>Worst time complexity</th>
        <th>Average time complexity</th>
        <th>Best time complexity</th>
        <th>Memory usage</th>
        <th>Implementation difficulty</th>
        <th>Speed on random arrays</th>
    </tr>
    <tr>
        <td>Quick Sort</td>
        <td><code>O(n^2)</code></td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(logn)</code></td>
        <td>★★★★</td>
        <td>The fastest overall, beats all the other, even Merge Sort (by a thin margin though).</td>
    </tr>
    <tr>
        <td>Merge Sort</td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(n)</code></td>
        <td>★★★</td>
        <td>Almost as fast as Quick Sort, beats also all the others below, is quite a lot faster than
        Heap Sort strangely enough.</td>
    </tr>
        <tr>
        <td>Heap Sort</td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(nlogn)</code></td>
        <td><code>O(1)</code></td>
        <td>★★★★★</td>
        <td>Theoretically the fastest of all, but in reality it's beaten by Quick Sort and Merge Sort
        though it still beats Insertion/Selection/Bubble sort by a mile anytime, plus it's a nice algorithm IMO.</td>
    </tr>
    </tr>
        <tr>
        <td>Selection Sort</td>
        <td><code>O(n^2)</code></td>
        <td><code>O(n^2)</code></td>
        <td><code>O(n^2)</code></td>
        <td><code>O(1)</code></td>
        <td>★★</td>
        <td>Quite slow, but beats Insertion Sort (by a thin margin) and of course beats Bubble Sort.</td>
    </tr>
    </tr>
        <tr>
        <td>Insertion Sort</td>
        <td><code>O(n)</code></td>
        <td><code>O(n^2)</code></td>
        <td><code>O(n^2)</code></td>
        <td><code>O(1)</code></td>
        <td>★★</td>
        <td>Same as selection sort in all aspects, except that in the best case it's linear which
        means it beats every other algorithm if the array is already sorted, therefore it's nice to use
        on small arrays at the end of a Merge Sort for instance.</td>
    </tr>
    </tr>
        <tr>
        <td>Bubble Sort</td>
        <td><code>O(n^2)</code></td>
        <td><code>O(n^2)</code></td>
        <td><code>O(n^2)</code></td>
        <td><code>O(1)</code></td>
        <td>★</td>
        <td>Arguably the slower of all sorting algorithm (except esotheric attempts like Boggo Sort). Many consider this the easiest to implement, though I'd say Insertion/Selection is a more obvious
        way of doing it intuitively.</td>
    </tr>
</table>

## The three major competitors 🏆
<object data="plots/benchmark_3_funcs.pdf" type="application/pdf" width="700px" height="400px">
    <embed src="plots/benchmark_3_funcs.pdf">
        <p>This browser does not support PDFs. Please download the PDF to view it: <a href="plots/benchmark_3_funcs.pdf">Download PDF</a>.</p>
    </embed>
</object>

# The other attempt… 🏳️

<object data="plots/benchmark_6_funcs.pdf" type="application/pdf" width="700px" height="400px">
    <embed src="plots/benchmark_6_funcs.pdf">
        <p>This browser does not support PDFs. Please download the PDF to view it: <a href="plots/benchmark_6_funcs.pdf">Download PDF</a>.</p>
    </embed>
</object>