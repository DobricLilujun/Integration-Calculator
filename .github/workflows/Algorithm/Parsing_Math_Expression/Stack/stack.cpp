#ifdef STACK_REALIZE

template<typename DataType>
Stack<DataType>::Stack()
{
	head = new StackNode<DataType>;
	if(!head)
	{
		cerr << "Failed to allocate memory!" << endl;
		exit(-1);
	}
	head->link = NULL;
}

template<typename DataType>
Stack<DataType>::Stack(const Stack<DataType>& X)
{
	head = new StackNode<DataType>;
	if(!head)
	{
		cerr << "Failed to allocate memory!" << endl;
		exit(-1);
	}

	StackNode<DataType> *p = head;
	StackNode<DataType> *q = X.head;
	while(q->link != NULL)
	{
		StackNode<DataType> *newNode = new StackNode<DataType>;
		if(!newNode)
		{
			cerr << "Failed to allocate memory!" << endl;
			exit(-1);
		}

		newNode->data = (q->link)->data;
		newNode->link = NULL;
		p->link = newNode;

		p = p->link;
		q = q->link;
	}
}

template<typename DataType>
Stack<DataType>::~Stack<DataType>()
{
	while(!empty())
	{
		pop();
	}
}

template<typename DataType>
void Stack<DataType>::clear()
{
	this->~Stack<DataType>();
}

template<typename DataType>
Stack<DataType>& Stack<DataType>::operator =(const Stack<DataType>& X)
{
	clear();

	StackNode<DataType> *p = head;
	StackNode<DataType> *q = X.head;
	while(q->link != NULL)
	{
		StackNode<DataType> *newNode = new StackNode<DataType>;
		if(!newNode)
		{
			cerr << "Failed to allocate memory!" << endl;
			exit(-1);
		}
		newNode->data = (q->link)->data;
		newNode->link = NULL;
		p->link = newNode;

		p = p->link;
		q = q->link;
	}

	return *this;
}

template<typename DataType>
void Stack<DataType>::push(DataType x)
{
	StackNode<DataType> *newNode = new StackNode<DataType>;
	if(!newNode)
	{
		cerr << "Failed to allocate memory!" << endl;
		exit(-1);
	}

	newNode->data = x;
	newNode->link = (head)->link;
	(head)->link = newNode;
}

template<typename DataType>
DataType Stack<DataType>::pop()
{
	int __NaN = 0xFFC00000;
	const DataType NaN = *((DataType *)&__NaN);
	if(empty())
	{
		cout << "Error in Stack::pop! The stack is empty!" << endl;
		return NaN;
	}
	DataType element = head->link->data;
	StackNode<DataType> *p = head->link;
	head->link = head->link->link;
	delete p;
	return element;
}

template<typename DataType>
DataType Stack<DataType>::top()const
{
	int __NaN = 0xFFC00000;
	const DataType NaN = *((DataType *)&__NaN);
	if(empty())
	{
		cout << "Error in Stack::top! The stack is empty!" << endl;
		return NaN;
	}
	return head->link->data;
}

template<typename DataType>
bool Stack<DataType>::empty()const
{
	if(head->link == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename DataType>
int Stack<DataType>::length()const
{
	int n = 0;

	StackNode<DataType> *p = head;
	while(p->link != NULL)
	{
		n++;
		p = p->link;
	}

	return n;
}

template<typename DataType>
Stack<DataType>& Stack<DataType>::inverse()
{
	Stack<DataType> stackTemp;
	while(!empty())
	{
		stackTemp.push( pop() );
	}
	*this = stackTemp;
	return *this;
}

#endif
