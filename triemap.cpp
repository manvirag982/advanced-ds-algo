#include<bits/stdc++.h>
using namespace std;

// A Trie node
struct Trie
{
	// true when node is a leaf node
	bool isLeaf;

	// each node stores a map to its child nodes
	unordered_map<char, Trie*> map;
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->isLeaf = false;

	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie* head, string str)
{

	// start from root node
	Trie* curr = head;
    int i=0;
	while (i<str.size())
	{
		// create a new node if path doesn't exists
		if (curr->map.find(str[i]) == curr->map.end())
			curr->map[str[i]] = getNewTrieNode();

		// go to next node
		curr = curr->map[str[i]];

		// move to next character
		i++;
	}

	// mark current node as leaf
	curr->isLeaf = true;
}


// Recursive function to delete a string in Trie.
Trie* deletion(Trie* curr, string str ,int depth=0)
{
	// return if Trie is empty
	if (curr == NULL)
		return NULL;

	if(depth==str.size()){

        curr->isLeaf=false;

        if(curr->map.empty()){

        	delete (curr);
        	curr=NULL;
        	
        }
        return curr;


	}

	curr->map[str[depth]]=deletion(curr->map[str[depth]],str,depth+1);

	if(!curr->map[str[depth]]&&curr->isLeaf==false)
	{
		delete curr;
		curr=NULL;
	}

	
	return curr;
}

// Iterative function to search a string in Trie. It returns true
// if the string is found in the Trie, else it returns false
bool search(Trie* head, string  str)
{
	// return false if Trie is empty
	
	Trie* curr = head;
	int i=0;
	while (i<str.size())
	{
		// go to next node
		curr = curr->map[str[i]];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;

		// move to next character
		i++;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return true
	return curr->isLeaf;
}

// Memory efficient Trie Implementation in C++ using Map
int main()
{
	Trie* head = getNewTrieNode();
	// head->end

	insert(head, "hello");
	cout << search(head, "hello") << " "<<endl;   	// print 1

	insert(head, "helloworld");
	cout << search(head, "helloworld") << " "<<endl;  // print 1

	cout << search(head, "helll") << " "<<endl;   	// print 0 (Not present)


	insert(head, "hell");
	cout << search(head, "hell") << " "<<endl;		// print 1

	insert(head, "h");
	cout << search(head, "h") << endl;  		// print 1 + newline

	deletion(head, "hello");
	cout << search(head, "hello") << " "<<endl;   	// print 0 (hello deleted)
	cout << search(head, "helloworld") << " "<<endl;  // print 1
	cout << search(head, "hell") << endl;   	// print 1 + newline

	deletion(head, "h");
	cout << search(head, "h") << " "<<endl;   		// print 0 (h deleted)
	cout << search(head, "hell") << " "<<endl;		// print 1
	cout << search(head, "helloworld") << endl; // print 1 + newline

	deletion(head, "helloworld");
	cout << search(head, "helloworld") << " "<<endl;  // print 0
	cout << search(head, "hell") << " "<<endl;		// print 1

	deletion(head, "hell");
	cout << search(head, "hell") << endl;   	// print 0 + newline

	if (head == nullptr)
		cout << "Trie empty!!\n";   			// Trie is empty now

	cout << search(head, "hell");   			// print 0

	return 0;
}