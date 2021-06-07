#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    ; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    /*
     * Why uses two move operation but not just passed in as a reference and do the move semantic once like my previous implementation.
     */
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    //_chatBot = std::make_shared<ChatBot>(chatbot);
    _chatBot = std::move(chatbot); 
    /*
     * Why passing the chatbot instance all around, but not just using a shared pointer of it like my previous implementation.
     * This way the chatlogic doesn't have to own the resources, and it would be easier than passing back the current chatbot address.
     */
    auto chatLogic = _chatBot.GetChatLogicHandle(); 
    chatLogic->SetChatbotHandle(&_chatBot);   
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source)
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
