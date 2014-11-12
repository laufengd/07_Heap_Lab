#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	numItems = 0;
	arrSize = START_SIZE;
	backingArray = new std::pair<Pri, T>[arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete[] backingArray;
	backingArray = NULL;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	unsigned int newSize = arrSize*2;
	std::pair<Pri, T>* myNewArray = new std::pair<Pri, T>[newSize];

	//Copy over the old items
	for(int i=0; i < arrSize; i++){
		myNewArray[i] = backingArray[i];
}	

	backingArray = myNewArray;
	arrSize = newSize;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
	if(numItems+1 > arrSize) grow();
	backingArray[numItems] = toAdd;
	bubbleUp(numItems);

	numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	int p = (index-1)/2; // gives the index for parent
	
	while(index > 0 && backingArray[index] < backingArray[p]){
		
		//switches parent and child pair if the parent is greater than the child
		std::pair<Pri, T> temp = backingArray[p];
		backingArray[p] = backingArray[index];
		backingArray[index] = temp;
	}
	
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	bool s;
	do{
		int j = -1;
		s = false; //tells whether or not a value has been swapped
		int r = 2*index+2;
		
		if( r < numItems && backingArray[r] < backingArray[index]){  //check right to see if right child is less than parent
			
			int l = (2*index)+1;
				
			if(backingArray[l] < backingArray[r]){ //check if left child is less than right child and assigns j = to the value of the lesser one
				j = l;
				s = true;
			}else{
				j = r;
				s = true;
			}
		
		
		
		}else{
			int l = (2*index)+1;
			if(l < numItems && backingArray[l] < backingArray[index]){
				j = l;
				s = true;
			}
		}

		
		if(j >= 0){
			
			//swaps the pairs of indexes j and 'index'
			std::pair<Pri, T> temp = backingArray[index];
			backingArray[index] = backingArray[j];
			backingArray[j] = temp;
		}

		index = j;
	
	} while (s == true); // if no swap occurs then function is finished
	
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
  std::pair<Pri,T> tmp = backingArray[0];
  backingArray[0] = backingArray[numItems-1];
  trickleDown(0);
  numItems--;
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems;
}

