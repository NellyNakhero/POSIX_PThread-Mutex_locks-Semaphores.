# POSIX_PThread-Mutex_locks-Semaphores.
Process/Thread synchronization using the Mutex locks, and Semaphores, Usage of POSIX PThread library, Read/Write to files with C/C++

<h1> Objectives </h1>
<ol>
<li> Process/Thread synchronization using the Mutex locks, and Semaphores.  </li>
<li>  Usage of POSIX PThread library. </li>
<li> Read/Write to files  </li>
</ol>

<hr/>
<br/>

<h1> Deliverables </h1>
<h2> Part-1 </h2>
<ol>
<li> C/C++ file implementing Part-1 of the problem </li>
<li>  Input file </li>
<li> Output file from a sample run  </li>
</ol>
<br/>

<h2> Part-2 </h2>
<ol>
<li> C/C++ file implementing Part-2 of the problem </li>
<li>  Three output files from three sample runs </li>
<li> Response to Part-2(2). </li>
</ol>
<br/>

<h2> Part-3 </h2>
<ol>
<li> C/C++ file implementing Part-3 of the problem </li>
<li> Output file from a sample run </li>
<li> Response to Part-3(2).  </li>
</ol>
<br/>

<h2> Execution instructions, if any. </h2>
<br/>
<br/>
<br/>

<h2> Problem: Distribution. </h2>
<img src="problem dist.png">
<br/>
<br/>
<br/>

<h2> Part–1 </h2>
<ol>
<li>Write a program in C/C++ that computes the distribution as follows:
    <ol type="a">
        <li>Read 100 integers from given input file </li>
        <li> For each integer,
            <ul>
                <li> Identify the group (bin) that it belongs to, and </li> 
                <li> Increment the respective group count.</li>
            </ul>
        </li>
        <li> Print to the output file in following format:
            <br/>
            Group 1 (0..9) Count:
            <br/>
            Group 2 (10..19) Count:
            <br/>
            Group 3 (20..29) Count:
            <br/>
            Group 4 (30..39) Count:
            <br/>
            Group 5 (40..49) Count:
            <br/>
            Group 6 (50..59) Count:
            <br/>
            Group 7 (60..69) Count:
            <br/>
            Group 8 (70..79) Count:
            <br/>
            Group 9 (80..89) Count:
            <br/>
            Group 10 (90..99) Count:   
            <br/>     
        </li>
        <li> </li>
    </ol>    
 </li>
<li> Provide following:
<br/>  
Output from a sample run.
<br/>  
</li>
</ol>
<br/>
<br/>
<br/>

<h2> Part–2 </h2>
<ol>
<li> Re-implement Part – 1 with POSIX Pthreads as follows. 
    <ol type="a">
        <li> Read 100 integers from given input file into an array, or a list.</li>
        <li> Create 10 concurrent threads.</li>
        <li>Partition the list into 10 parts comprising 10 integers each and assign one part to each thread. Pass the starting index of sub-list as parameter. For example:
            <br/>
            Thread 6 processes the array elements [50]..[59]; hence, pass the starting
            index 50 as a parameter.
        </li>
        <li>Each thread performs following task:
            <ol type="i">
                <li> For each integer in the assigned sub-list:
                    <br/>
                        Identify the group (bin) that it belongs to, and
                    <br/>
                        Increment the respective group count (global variable).
                </li>
                <li>Terminate the thread. </li>
            </ol>
         </li>
        <li>Prints to the output file in the format specified in Part-1(1)(c). </li>
    </ol>
</li>
<li> Provide following:
<br/>
Provide output from three sample runs.
</li>
<li> </li>
</ol>
<br/>
<br/>
<br/>

<h2> Part–3 </h2>
<ol>
<li> Re-implement Part – 2(1)(d) as follows implementing synchronization mechanisms
    discussed in class to ensure that each thread atomically updates the group counts. 
    <ol type="a">
        <li> Declare and initialize 10 mutex locks, or 10 semaphores (based on the
            synchronization mechanism you choose). Each mutex lock / semaphore
            represents one group-count global variable.</li>
        <li>Each thread performs following task:
            <ol type="i">
                <li> For each integer in the assigned sub-list:
                <br/>
                        Identify the group (bin) that it belongs to, and
                <br/>
                        Acquire exclusive access to the group-count global variable by
                        acquiring respective mutex lock / semaphore.
                <br/>
                    Increment the respective group count (global variable).
                <br/>
                    Explicitly release the lock.
                <br/>
                </li>
                <li>Terminate the thread</li>
            </ol>
         </li>
        <li>Prints to the output file in the format specified in Part-1(1)(c).. </li>
    </ol>
</li>
<li> Provide following:
<br/>
Output from a sample run.
</li>
<li> </li>
</ol>
<br/>
<br/>
<br/>
