07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add and remove function in log(n) as are in the text.
2. deleted backing array in constructor and in other functions that create temporary pairs

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1    
	
	add(7) 	
	index	0 1 2 3  4  5  6  7  8  9  10 11 12 13 14  

	Pri  	4 9 6 17 26 8  16 19 69 32 93 55 50 (7)
	
	bubbleUp(){
	swap(a[6], a[13])
	}
	
	add(3){
	Pri->index = 14;
	}
	
	bubbleUP(){
		swap(a[14], a[6])
		swap(a[6], a[2])
		swap(a[0], a[2])
	}
	

	
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

		findDChildrent(index){
		int p = (index-1)/2;
		int left = 2p + 1;
		int right = 2p + 2;
	}

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Read the text for this, it makes the assignment much simpler.