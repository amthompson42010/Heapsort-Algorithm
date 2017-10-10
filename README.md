This is the First project in my Data Structures and Algorithms class.

#Description:

For your first Algorithm's programming assignment, you are to implement a heapsort algorithm using a binary tree structure. Since a 
heap can be efficiently stored in an array, there is never a need to implement a heap as a binary tree, even though heaps are often 
drawn that way. However, implementing a heap as a tree will give you needed practice in manipulating trees. 

To make this task more challenging, tree nodes will be restricted to left, right, and parent pointers, plus a field to store the 
integer value of the node. You may, however, use auxilliary data structures. Full credit will be reserved for implementations that use 
the fewest and most appropriate auxilliary data structures. All tree-based heap operations must be as efficient as those for a heap 
implemented as an array: 
    
    reading in a value and adding it to the heap (constant time)
    ordering the heap (linear time)
    extracting the extreme value (logarithmic time)

You may not use an array anywhere in your implementation. 

#I/O

Your executable must be named: 

    heapsort

The executable will take a file name as a command-line argument and will produce, on stdout, the integers found in the given file in 
sorted order. The output must be all integers on a single line, each integer separated from the next by a single space. Here is an 
example invocation: 

    $ for i in {1..5}; do echo $RANDOM; done > integers
    $ heapsort integers
    4106 6986 9883 19357 27330
    $ heapsort -d integers
    27330 19357 9883 6986 4106 
    $ heapsort -v
    My heapsort works in n log n time because...
    ...
    $

where $ is the system prompt. The file to be sorted is a free-format text file. That is, the integers within are separated by arbitrary 
amounts of whitespace and every line ends with a newline. 

The executable must handle the following options: 
    
    option	action
    -v	give author's name and explanation on how the implementation performs the sorting in θ(nlogn) time -- In particular 
    explain how adding a value to theap takes constant time, how ordering the heap takes linear time, and how extracting the min/max 
    takes logarithmic time
    — also give some empirical evidence (such as a table of input sizes versus time) that indicates your sort runs in θ	(	n	log	n	)	
    time — then immediately exit
    -d	sort in decreasing order (default is increasing order)
