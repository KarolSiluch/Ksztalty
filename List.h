#pragma once

template<typename T>
class List
{
private:
	class Node
	{
	public:
		Node(T* value)
		{
			this->value = value;
			this->next = nullptr;
		}
		T* value;
		Node* next;
	};

	class Iterator
	{
	public:
		Iterator(Node* node) : current(node) {}

		bool operator!=(const Iterator& other) const
		{
			return current != other.current;
		}

		T* operator*() const
		{
			return current->value;
		}

		Iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		Node* current;
	};

	Node* head;
	Node* tail;
	int size;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~List()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	List(const List& other)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
		*this = other;
	}

	void add(T* value)
	{
		Node* newNode = new Node(value);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void add(T* value, int index)
	{
		if (index < 0 || index > size)
			return;
		Node* newNode = new Node(value);
		if (index == 0)
		{
			newNode->next = head;
			head = newNode;
			if (tail == nullptr)
				tail = newNode;
		}
		else
		{
			Node* current = head;
			for (int i = 0; i < index - 1; i++)
				current = current->next;
			newNode->next = current->next;
			current->next = newNode;
			if (newNode->next == nullptr)
				tail = newNode;
		}
		size++;
	}

	int getSize() const
	{
		return size;
	}

	T* get(int index) const
	{
		if (index < 0 || index >= size)
			return nullptr;
		Node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		return current->value;
	}

	Iterator begin() const
	{
		return Iterator(head);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}
};

