#pragma once

class AbstractBST
{
    public:
    virtual bool isEmpty() = 0;
    virtual bool add(int key, int value) = 0;
    virtual void max(int &output) = 0;
    virtual void min(int &output) = 0;
    virtual bool exists(int targetkey) = 0;
    virtual bool remove(int delete_key) = 0;

    virtual void inorder() = 0;
};