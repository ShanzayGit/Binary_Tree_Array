#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<math.h>
#include<iostream>
#include"Queue.h"
using namespace std;
template <typename T>
class BinaryTree
{
	int maxHeight;
	int arrayCapacity;
	T* data;
	bool* nodeStatus;
	void displayEView(int i)
	{
		cout << '\n';
		int l = findLevelOfNode(data[i]);
		for (int i = 0; i < l; i++)
			cout << '\t';
		cout << data[i];
		if (i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true)
			displayEView(i * 2 + 1);
		if (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
			displayEView(i * 2 + 2);
	}
	void displayPView(int i)
	{
		cout << data[i];
		if ((i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true) || (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true))
			cout << "(";
		if (i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true)
			displayPView(i * 2 + 1);
		if ((i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true) || (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true))
			cout << ",";
		if (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
			displayPView(i * 2 + 2);
		if ((i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true) || (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true))
			cout << ")";
	}
	void levelOrdering(Queue<T>& q)
	{
		if (q.isEmpty())
			return;
		T temp = q.deQueue();
		cout << temp << "  ";
		int ind = search(0, temp);
		if (ind * 2 + 1 < arrayCapacity && nodeStatus[ind * 2 + 1] == true)
			q.enQueue(data[ind * 2 + 1]);
		if (ind * 2 + 2 < arrayCapacity && nodeStatus[ind * 2 + 2] == true)
			q.enQueue(data[ind * 2 + 2]);
		levelOrdering(q);
	}
	void VLR(int i)
	{
		cout << data[i]<< "  ";
		if (i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true)
			VLR(i * 2 + 1);
		if (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
			VLR(i * 2 + 2);
	}
	void LVR(int i)
	{
		if (i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true)
			LVR(i * 2 + 1);
		cout << data[i]<<"  ";
		if (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
			LVR(i * 2 + 2);
	}
	void LRV(int i)
	{
		if (i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true)
			LRV(i * 2 + 1);
		if (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
			LRV(i * 2 + 2);		
		cout << data[i] << "  ";
	}

	int getHeight(int i)
	{
		int left = 0;
		int right = 0;
		if (i * 2 + 1 < arrayCapacity && nodeStatus[i * 2 + 1] == true)
			left = getHeight(i * 2 + 1);
		if (i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
			right = getHeight(i * 2 + 2);
		return  left <= right ? right + 1 : left + 1;

	}
	int search(int ind,T key)
	{
		int index = -1;
		if (data[ind] == key)
			index = ind;
		if (2 * ind + 1 < arrayCapacity && nodeStatus[2 * ind + 1] == true&&index==-1)
			index = search(2 * ind + 1, key);
		if (2 * ind + 2 < arrayCapacity && nodeStatus[2 * ind + 2] == true&&index==-1)
			index = search(2 * ind + 2, key);
		return index;
	}
	void removingNodes(int index)
	{
		nodeStatus[index] = false;
		if (index * 2 + 1 < arrayCapacity && nodeStatus[index * 2 + 1] == true)
			removingNodes(index * 2 + 1);
		if (index * 2 + 2 < arrayCapacity && nodeStatus[index * 2 + 2] == true)
			removingNodes(index * 2 + 2);

	}
public:
	BinaryTree():maxHeight(0),arrayCapacity(0),data(nullptr),nodeStatus(nullptr)
	{}
	BinaryTree(int H)
	{
		arrayCapacity = pow(2, H) - 1;
		data = new T[arrayCapacity];
		nodeStatus = new bool[arrayCapacity];
		for (int i = 0; i < arrayCapacity; i++)
			nodeStatus[i] = false;
		maxHeight = H;

	}
	void setRoot(T val)
	{
		data[0] = val;
		nodeStatus[0] = true;
	}
	T getRoot()
	{
		if (arrayCapacity != 0 && nodeStatus[0] != false)
			return data[0];
		else
			exit(0);
	}
	void setLeftChild(T par, T chi)
	{
		int i = search(0, par);
		if (i != -1 && i * 2 + 1 < arrayCapacity)
		{
			data[i * 2 + 1] = chi;
			nodeStatus[2 * i + 1] = true;
		}
		else
			return;

	}
	void setRightChild(T par, T chi)
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		int i = search(0, par);
		if (i == -1)
			return;
		if ( i * 2 + 2 < arrayCapacity)
		{
			data[i * 2 + 2] = chi;
			nodeStatus[2 * i + 2] = true;
		}
		
	}
	T getParent(T node)
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			exit(0);
		int i = search(0, node);
		if (i != -1 && ((i + 1) / 2 - 1) >= 0)
		    return data[(i + 1) / 2 - 1];
		else
			exit(0);
	}
	void displayAncestors(T node)
	{
		T Node=getParent(node);
		cout << Node << "\t";
		if (Node == data[0])
			return;
		displayAncestors(Node);
	}
	void displayDescendants(T node)
	{
		int i = search(0, node);
		if (i != -1 && i * 2 + 1 < arrayCapacity&& nodeStatus[i * 2 + 1] == true)
		{
			cout << data[i * 2 + 1];
			displayDescendants(data[i * 2 + 1]);
		}
		if (i != -1 && i * 2 + 2 < arrayCapacity && nodeStatus[i * 2 + 2] == true)
		{
			cout << data[i * 2 + 2];
			displayDescendants(data[i * 2 + 2]);
		}
	}
	int heightOfTree()
	{
		if (nodeStatus[0] == false)
			return 0;
		return getHeight(0);
	}
	void remove(T key)
	{
		if (arrayCapacity <= 0||nodeStatus[0]==false)
			return;
		int i = search(0, key);
		if (i != -1)
		{
			removingNodes(i);
		}
	}
	void preOrder()//VLR
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		VLR(0);
	}
	void postOrder()//LRV
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		LRV(0);
	}
	void inOrder()//LVR
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		LVR(0);
	}
	void levelOrder()
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		Queue<int> q;
		q.enQueue(data[0]);
		levelOrdering(q);
	}
	void displayLevel(int levelNo)
	{
		if (levelNo<0||levelNo>=maxHeight)
			return;
		int start = 0;
		for (int i = 0; i < levelNo; i++)
		{
			start = start + pow(2, i);
		}
		int after = 0;
		for (int i = levelNo + 1; i < maxHeight; i++)
		{
			after = after + pow(2, i);
		}
		int noOfElementsOnLevel = arrayCapacity - (start + after);
		int i = start;
		while (i < start + noOfElementsOnLevel)
		{
			if (nodeStatus[i] == true)
				cout << data[i]<<"  ";
			i++;
		}
	}
	int findLevelOfNode(T node)
	{
		int i = search(0, node);
		if (i == -1)
			exit(0);
		i = i+1 ;//for starting of each level e.g index 1 as at level 1
		int level = 0;
		while (i / 2 != 0)
		{
			level++;
			i = i / 2;
		}
		return level;
	}
	void displayParenthesizedView()
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		displayPView(0);
	}

	void displayExplorerView()
	{
		if (arrayCapacity <= 0 || nodeStatus[0] == false)
			return;
		displayEView(0);
	}
};
#endif // !BINARYTREE_H
