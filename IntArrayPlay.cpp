//Sakif Chowdhury
//CISC 2000
//Professor Dakota Hernandez

#include <iostream>
#include <algorithm>
using namespace std;

const int CAPACITY=20;

void displayArray(int array[], int numElements){
   for(int i=0; i < numElements; i++){
      cout << array[i] << " ";
   }
   cout << endl;
}

//ToDo: Declare a function fillArray that fills an int array with values entered
//by the user. Stop reading when the user inputs -1 or you reach CAPACITY.
// fillArray - read a list of positive integers ending with -1 or until CAPACITY
// @param: int array[] is an array of integers when leaving this function
// @param: int& numElements is the number of Elements in the array when done
// @returns void.

void fillArray(int array[], int& numElements){
   int index=0;
   int num;

   cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;
   cin >> num;

   while((num>=0) && (index< CAPACITY)){
      array[index]=num;
      index++;
      cin >> num;
   }
   numElements = index;
}

bool isArraySorted(int array[], int numElements){
   int counterNum = array[0];
   for (int i=1; i<numElements; i++){
      if(counterNum > array[i]){
         return false;
      }
      counterNum = array[i];
   }
   return true;
}

//ToDo: Declare a function that finds the insert position for a given value
//in an ordered array.
// findPosition - looks thru an ordered array to find the position of
// the value to insert. All values before are less than the target value.
// Value after should be greater than the target value. [No need to sort] 
// @param: int array[] is an ordered array
// @param: int numElements
// @param: int value to insert
// @return index of the position where the element should be inserted

int findPosition(int array[], int numElements, int insertValue){
   if(numElements == CAPACITY){
      return -1;
   }
    int i=0;
    while(i< numElements && array[i]<insertValue){
      i++;
    }
    return i;
   }

//ToDo: Declare a funcxtion that searches for an element in the given array
// searchElement - searches for the element in the given array.
// @param int array[] is an unordered array of integers
// @param int numberOfElements
// @param int element
// @returns index of element or -1 if not found.

int searchElement(int array[], int numberOfElements, int element){
   int pos = -1; 
   for (int i=0; i< numberOfElements; i++){
      if (array[i] == element){
         return i;
         pos = i;
         break;
      }
   }
   return pos;
}

//ToDo: Declare a function that removes (i.e., deletes) the element
// removeElement - removes the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int&amp; numberElements
// @param: int position of element to delete
// @returns: true if delete was successful, false otherwise

bool removeElement(int array[], int& numberElements, int deletePosition ){
   if (deletePosition >= numberElements || deletePosition<0){ // need like a prelim statement that disregards function if user has alr reached capacity 
      return false;
   }
   for(int i=deletePosition; i<numberElements-1;i++){
      array[i] = array[i+1];
   }

   numberElements--;
   return true;
}
bool insertElement(int array[], int& numElements, int insertPos, int target){
   if(numElements >= CAPACITY){
      return false;
   }
   for(int i=numElements; i>insertPos; i--){
      array[i] = array[i-1];
   }
   array[insertPos] = target;
   numElements++;
   return true;
}

int main()
{
   int numArray[CAPACITY];	
   int numArrayElems=0;    
   
   int addVal;
   int removeVal;

   // 1. ToDo: Call your fillArray function to read in a sequence of integer values,
   // separated by space, and ending with -1. Store the values in the numArray array 
   // and the number of elements in numArrayElems.
   // Display the content of the array afterwards 

   fillArray(numArray, numArrayElems);
   displayArray(numArray, numArrayElems);

   // 2. ToDo: Read in a value from the user. Call your findPosition function
   // to get the position to insert, then call insertElement to insert the value
   // into the position of the array. 
   // Display the contents of the array afterwards 
   cout << "Enter a value to insert: ";
   cin >> addVal;// this value is being added to the program

   int insertPosition = findPosition(numArray, numArrayElems, addVal); 
   if(insertElement(numArray, numArrayElems,insertPosition, addVal)){
      displayArray(numArray, numArrayElems);
   }
   else{
      cout << "Error: array is full" << endl;
      displayArray(numArray, numArrayElems); //Even though there is an error message, the array needs to be displayed again therefore the function is called once more
   }

   // 3. ToDo: Use your isArraySorted function to tell whether the array is sorted.
   if(isArraySorted(numArray, numArrayElems)){ //if this is true that means its sorted
      cout << "Array is sorted" << endl;
   }
   else{
      cout << "Array is not sorted" << endl;
   }

   // 4. ToDo: Read in a value from the user. Call your searchElement function
   // to get the position to remove, then call removeElement to delete it.
   // a value to the end of the array 
   // Display the content of the array afterwards 
   cout << "Enter a value to remove: ";
   cin >> removeVal;

   int removePosition = searchElement(numArray, numArrayElems, removeVal); 
      if((removeElement(numArray, numArrayElems,removePosition))){
         displayArray(numArray, numArrayElems);
      }
      else{
         cout << "Error: position out of range: -1" << endl;
         displayArray(numArray, numArrayElems);
      }
      return 0;
   }