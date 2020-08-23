//代码迁移自红黑树项目
#pragma once
#define __FOREST __forest
namespace __FOREST
{
	//仿函数部分
	//less小根堆，greater大根堆
	template <typename T> class Less
	{
	public:
		bool operator()(const T& arg1, const T& arg2)
		{
			return arg1.weight < arg2.weight;
		}
	};
	template <typename T> class Less<T*>
	{
		bool operator()(const T* arg1, const T* arg2)
		{
			return arg1->weight < arg2->weight;
		}
	};
	template <typename T> class Greater
	{
	public:
		bool operator()(const T& arg1, const T& arg2)
		{
			return arg1.weight > arg2.weight;
		}
	};
	template <typename T> class Greater<T*>
	{
		bool operator()(const T* arg1, const T* arg2)
		{
			return arg1->weight > arg2->weight;
		}
	};

	//二叉堆部分
	template <typename element, typename Compare = Less<element>>
	class Heap
	{
	public:
		//friend class iterator<element>;
		Heap(int capacity)
		{
			this->capacity = capacity;
			array = new element[capacity];
			size = 0;
		}
		//插入
		void insert(const element item)
		{
			if (size == capacity)
			{
				return;
			}
			else
			{
				array[size] = item;
				size++;
				heapifyUp();
			}
		}
		//删除
		void poll()
		{
			if (size == 0)
			{
				return;
			}
			else
			{
				array[0] = array[size - 1];
				size--;
				heapifyDown();
			}

		}
		//展示
		element peek()
		{
			if (size == 0)
			{
				exit(0);
			}
			else
			{
				return array[0];
			}
		}

		//迭代器
		class iterator
		{
		private:
			element* element_ptr;
			int cur_index;
		public:
			iterator(Heap<element>* heap_ptr, int index = 0)
			{
				element_ptr = &(heap_ptr->array[index]);
				cur_index = index;
			}
			iterator(Heap<element> heap, int index = 0)
			{
				element_ptr = &(heap.array[index]);
				cur_index = index;
			}
			iterator& operator++()
			{
				element_ptr++;
				cur_index++;
				return *this;
			}
			iterator operator++(int i)//这个一般不加引用。
			{
				element_ptr++;
				cur_index++;
				return *this;
			}
			element& operator*()
			{
				return *element_ptr;
			}
			bool operator<(iterator iter)
			{
				return cur_index < iter.cur_index;
			}
		};

		iterator begin()
		{
			return iterator(this, 0);
		}
		iterator end()
		{
			return iterator(this, this->size);
		}
	private:
		int capacity;	//最大容量
		int size;		//大小
		element* array;	//元素的数组，以后改成向量会更好。

	private:
		const int getLeftChildIndex(const int parentIndex)
		{
			return 2 * parentIndex + 1;
		}
		const int getRightChildIndex(const int parentIndex)
		{
			return 2 * parentIndex + 2;
		}
		const int getParentIndex(const int childIndex)
		{
			return (childIndex - 1) / 2;
		}

		bool isExistLeftChild(const int parentIndex)
		{
			return getLeftChildIndex(parentIndex) < size;
		}
		bool isExistRightChild(const int parentIndex)
		{
			return getRightChildIndex(parentIndex) < size;
		}
		bool isExistParent(const int childIndex)
		{
			return getParentIndex(childIndex) >= 0;
		}

		element& leftChild(const int parentIndex)
		{
			if (isExistLeftChild(parentIndex))
			{
				return array[getLeftChildIndex(parentIndex)];
			}
			else return array[0];

		}
		element& rightChild(const int parentIndex)
		{
			if (isExistRightChild(parentIndex))
			{
				return array[getRightChildIndex(parentIndex)];
			}
			else return array[0];
		}
		element& parent(const int childIndex)
		{
			if (isExistParent(childIndex))
			{
				return array[getParentIndex(childIndex)];
			}
			else return array[0];

		}

		void swap(const int index1, const int index2)
		{
			element temp;
			temp = array[index1];
			array[index1] = array[index2];
			array[index2] = temp;
		}
		void heapifyUp()
		{
			int index = size - 1;
			Compare compare;
			while (isExistParent(index) && compare(array[index], parent(index)))
			{
				swap(getParentIndex(index), index);
				index = getParentIndex(index);
			}
		}
		void heapifyDown()
		{
			Compare compare;
			int index = 0;
			while (isExistLeftChild(index))
			{
				int largerChildIndex = getLeftChildIndex(index);

				if (isExistRightChild(index) && compare(rightChild(index), leftChild(index)))
				{
					largerChildIndex = getRightChildIndex(index);
				}

				if (compare(array[largerChildIndex], array[index]))
				{
					swap(index, largerChildIndex);
				}
				else
				{
					break;
				}

				index = largerChildIndex;
			}
		}
	};
}
