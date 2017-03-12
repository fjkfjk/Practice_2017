//重载全局的new与delete符号
List ptrLst;

void* operator new(size_t size)
{
    void* mem = malloc(size);
    if(!mem)
    {
        puts("allocate memory error!");
        return 1;
    }
    ptrLst.push_back((int)mem);
    return mem;
}

void* operator delete(void* addr)
{
    free(addr);
    ptrLst.remove((int)addr);
}

//true representative memory leak has been happened.
bool isMemLeak()
{
    return ptrLst.size() != 0;
}

class List
{
private:
    LinkNode* preHead;
    LinkNode* curNode;
    int count;

public:
    List():count(0)
    {
        preHead = new LinkNode();
        curNode = preHead;
    }

public:
    struct LinkNode
    {
        int val;
        LinkNode* next;

        LinkNode():val(0),next(nullptr){}
        LinkNode(int _val,LinkNode* _next):val(_val),next(_next){}
    };

public:
    void push_back(int addr);
    void remove(int addr);
    int size()
    {
        return count;
    }
}

void List::push_back(int addr)
{
    curNode->next = new LinkNode(addr,nullptr);
    curNode = curNode->next;
    ++count;
}

void List::remove(int addr)
{
    LinkNode* node = preNode;
    for(int i = 0; i < count; i++)
    {
        if(node->next == addr)
        {
            LinkNode* cnod = node->next;
            node->next = cnod->next;
            delete(cnod);
            cnod = nullptr;
            --count;
            break;
        }
    }
};