#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val) {
	// empty
	if ((head_ == nullptr) && (tail_ == nullptr)) {
		head_ = new Item;
		tail_ = head_;
		tail_->first = 0;
		tail_->val[tail_->first] = val;
		tail_->last = 1;
		size_ += 1;
		tail_->prev = nullptr;
		tail_->next = nullptr;
	}
	// scenario 1: normal
	else if (tail_->last < ARRSIZE) {
		tail_->val[tail_->last] = val;
		size_ += 1;
		tail_->last += 1;
	}
	// full
	else {
		Item* temp = tail_;
		tail_ = new Item;
		tail_->first = 0;
		tail_->val[tail_->first] = val;
		tail_->last = 1;
		size_ += 1;
		temp->next = tail_;
		temp->next->prev = temp;
		temp->next->next = nullptr;
	}
}

/**
	* Removes a value from the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_back() {
	if (tail_->last == ((tail_->first)+1)) {
		if (head_ == tail_) {
			size_ -= 1;
			delete head_;
		}
		else {
			Item* temp = tail_;
			tail_ = tail_->prev;
			tail_->next = nullptr;
			size_ -= 1;
			delete temp;
		}
	}
	else {
		tail_->last -= 1;
		size_ -= 1;
	}
}
  
/**
	* Adds a new value to the front of the list.
	* If there is room before the 'first' value in
	* the head node add it there, otherwise, 
	* allocate a new head node.
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_front(const std::string& val) {
	// scenario 1: empty
	if ((head_ == nullptr) && (tail_ == nullptr)) {
		head_ = new Item;
		tail_ = head_;
		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		head_->val[head_->first] = val;
		size_ += 1;
		head_->prev = nullptr;
		head_->next = nullptr;
	}
	// scenario 2: normal
	else if ((head_->first)-1 > 0) {
		head_->first -= 1;
		head_->val[head_->first] = val;
		size_ += 1;
	}
	// scenario 3: front is full
	else {
		Item* temp = head_;
		head_ = new Item;
		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		head_->val[head_->first] = val;
		size_ += 1;
		head_->prev = nullptr;
		head_->next = temp;
		head_->next->prev = head_;
	}
}

/**
	* Removes a value from the front of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_front() {
	if (head_->last == ((head_->first)+1)) {
		if (head_ == tail_) {
			size_ -= 1;
			delete head_;
		}
		else {
			Item* temp = head_;
			head_ = head_->next;
			head_->prev = nullptr;
			size_ -= 1;
			delete temp;
		}
	}
	else {
		size_ -= 1;
		head_->first += 1;
	}
}

/**
	* Returns a const reference to the back element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::back() const {
	return tail_->val[(tail_->last)-1];
}

/**
	* Returns a const reference to the front element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::front() const {
	return head_->val[head_->first];
}

/** 
	* Returns a pointer to the item at index, loc,
	*  if loc is valid and NULL otherwise
	*   - MUST RUN in O(n) 
	*/
std::string* ULListStr::getValAtLoc(size_t loc) const {
	if ((loc >= 0) && (loc <= size_-1)) {
		if (loc == 0) {
			return &(head_->val[head_->first]);
		}
		int indexCtr = 0;
		Item* temp = head_;
		int firstCopy = temp->first;
		int lastCopy = temp->last;
		while (indexCtr != loc) {
			while (firstCopy <= lastCopy-1) {
				if (indexCtr == loc) {
					return &(temp->val[firstCopy]);
				}
				firstCopy += 1;
				indexCtr++;
			}
			temp = temp->next;
			firstCopy = temp->first;
			lastCopy = temp->last;
		}
		return &(temp->val[firstCopy]);
	}
	return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
