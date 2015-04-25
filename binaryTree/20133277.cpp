// HW 2 : Binary Search Tree
// Name : Seongsil Heo
// Student ID : 20133277


template <class T>
bool  BinaryST<T>::Insert(T item)  {
	BSTNode<T> *insert = new BSTNode<T>(item); //point item
	BSTNode<T> *ptrI; 
	ptrI = root; //point root

	while(1)
	{
		if(root == NULL)
		{
			root = insert;
			return true;
		}
		else if(insert->data.key < ptrI->data.key)
		{
			if(ptrI->lC == NULL)
			{
				ptrI->lC = insert;
				return true;
			}

			ptrI = ptrI->lC;

		}
		else if(insert->data.key > ptrI->data.key)
		{
			if(ptrI->rC == NULL)
			{
				ptrI->rC = insert;
				return true;
			}

			ptrI = ptrI->rC;
		}  
		else
		{
			ptrI->data.val = insert->data.val;
			return false;
		}
	}
}


template <class T>
T BinaryST<T>::Get(T item)  {

	BSTNode<T> *get = new BSTNode<T>(item);
	BSTNode<T> *ptrG;
	ptrG = root;


	while(1)
	{
		if(root==NULL)
		{
			return T(-1);
		}

		else if(get->data.key < ptrG->data.key)
		{
			if(ptrG->lC == NULL)  {return T(-1);}
			ptrG = ptrG->lC;
		}
		else if(get->data.key > ptrG->data.key)
		{
			if(ptrG->rC == NULL) {return T(-1);}
			ptrG = ptrG->rC;
		}
		else
		{
			return ptrG->data;
		}
		//return ptrG->data;
	}

} 


template <class T>
bool  BinaryST<T>::Delete(T item)  {
	BSTNode<T> *del = new BSTNode<T>(item); 
	BSTNode<T> *ptr;   //delete node
	BSTNode<T> *beforeDel = NULL;
        BSTNode<T> *parDel = NULL;
        BSTNode<T> *insteadDel = NULL;
	ptr = root; //root

	if(root == NULL)
		return false;

	while(1) //search where is delete node
	{
                if(ptr->data.key == del->data.key) break;
                beforeDel = ptr;
		if(ptr->data.key > del->data.key) {ptr = ptr->lC;}
		else if(ptr->data.key < del->data.key) { ptr = ptr->rC; }

                if(ptr==NULL) break;
	}
        if(ptr==NULL) return false;

		if((ptr->lC!=NULL) && (ptr->rC!=NULL))
		{  
                        parDel = ptr;
                        insteadDel = ptr->rC;
                   
		    while((insteadDel->lC)!=NULL)
				{
                                  parDel = insteadDel; 
                                  insteadDel = insteadDel->lC;
                                 }

				ptr->data.key= insteadDel->data.key;
                                ptr->data.val = insteadDel->data.val;
                          
                                if(ptr==parDel){ 
                                   if(insteadDel->rC==NULL) { parDel->rC=NULL;}
                                   else {parDel->rC=insteadDel->rC;}
                                   }
                                else if(insteadDel->rC==NULL)
                                   parDel->lC=NULL;
                                else
                                   parDel->lC=insteadDel->rC;

		}

	else if((ptr->lC!=NULL) || (ptr->rC!=NULL)) //degree=1
	{
		if(beforeDel == NULL) //when delete root node
		{ 
			if(ptr->lC!=NULL)  
                        {   
                            ptr = ptr->lC;  
                            
                        }
			else  
                        { 
                            ptr = ptr->rC; 
                            
                        }   
                        root = ptr;
		}
                
		else if(ptr->lC!=NULL) //ptr has lC
		{
			if(beforeDel->lC == ptr)
			    beforeDel->lC = ptr->lC;
			else
			    beforeDel->rC = ptr->lC;
                     //   root = beforeDel;
		}
		else //ptr has rC
		{
			if(beforeDel->lC == ptr)
				beforeDel->lC = ptr->rC;
			else
				beforeDel->rC = ptr->rC;
		}
           //root = ptr;
 
	}

	else //0 degree
	{ 
                 if(beforeDel==NULL)
                   root=NULL;                
		else if(beforeDel->lC == ptr)
		  beforeDel->lC= NULL;
		else
		beforeDel->rC= NULL;
	}
        //delete ptr;
	return true;
}

template <class T>
void  BinaryST<T>::PreOrder(BSTNode<T> *ptr)  {
	if(ptr!=NULL)
	{
		cout << ptr->data.key << "(" << ptr->data.val << ")" << " ";
		PreOrder(ptr->lC);
		PreOrder(ptr->rC);
	}

}

template <class T>
void  BinaryST<T>::InOrder(BSTNode<T> *ptr)  {
	if(ptr!=NULL)
	{
		InOrder(ptr->lC);
		cout << ptr->data.key << "(" << ptr->data.val << ")"<< " ";
		InOrder(ptr->rC);
	}

}

template <class T>
void  BinaryST<T>::PostOrder(BSTNode<T> *ptr)  {
	if(ptr != NULL)
	{
		PostOrder(ptr->lC);
		PostOrder(ptr->rC);
		cout << ptr->data.key << "(" << ptr->data.val << ")" << " ";
	}


}

template <class T>
int  BinaryST<T>::Count(BSTNode<T> *ptr)  {
	if(ptr == NULL)
		return 0;

	return 1+Count(ptr->lC)+Count(ptr->rC);
}

template <class T>
int  BinaryST<T>::Height(BSTNode<T> *ptr)  {
	if(ptr == NULL)
		return 0; 

	else if(1+Height(ptr->lC) > 1+Height(ptr->rC))
		return 1+Height(ptr->lC);
	else
		return 1+Height(ptr->rC);
}



