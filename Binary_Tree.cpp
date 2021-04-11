#include <iostream>

//이진트리의 구현!

using namespace std;

class TreeNode{

  private:

    TreeNode* left;
    TreeNode* right;

    int data;

    public:
    
        TreeNode(){
            left = NULL;
            right = NULL;
            data = 0;
        }

    void SetData(int pData){
      data = pData;
    }

    void SetLeftNode(TreeNode* pLeft){
      left = pLeft;
    }

    void SetRightNode(TreeNode* pRight){
      right = pRight;
    }

    TreeNode* GetLeftNode(){
      return left;
    }

    TreeNode* GetRightNode(){
      return right;
    }

    int GetData(){
      return data;
    }

};

/*
이진 트리의 순회 3가지 방법 존재!
1. 전위 순회(Preorder Traversal)
2. 중위 순회(InorderTraversal)
3. 후위 순회(Postorder Traversal)
*/

void PreorderTraverse(TreeNode* rootNode){

    if(rootNode == NULL) return;

    cout<<rootNode->GetData()<<'\n';
    PreorderTraverse(rootNode->GetLeftNode());
    PreorderTraverse(rootNode->GetRightNode());

}

void InorderTraverse(TreeNode* rootNode){

    if(rootNode == NULL) return;

    InorderTraverse(rootNode->GetLeftNode());
    cout<<rootNode->GetData()<<'\n';
    InorderTraverse(rootNode->GetRightNode());

}

void PostorderTraverse(TreeNode* rootNode){

    if(rootNode == NULL) return;

    PostorderTraverse(rootNode->GetLeftNode());
    PostorderTraverse(rootNode->GetRightNode());
    cout<<rootNode->GetData()<<'\n';

}


int main(void){

    //노드 생성
    TreeNode* first = new TreeNode();
    TreeNode* second = new TreeNode();
    TreeNode* third = new TreeNode();

    //노드에 data 추가!
    first->SetData(1);
    second->SetData(2);
    third->SetData(3);

    first->SetLeftNode(second);
    first->SetRightNode(third);

    // cout<<first->GetLeftNode()->GetData();
    
    cout<<"inorder"<<'\n';
    InorderTraverse(first);

    cout<<"Postorder"<<'\n';
    PostorderTraverse(first);

    cout<<"Preorder"<<'\n';
    PreorderTraverse(first);

}
