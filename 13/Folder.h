//
// Created by Apple on 2022/2/21.
//

#ifndef C__PRIMER_COPY_FOLDER_H
#define C__PRIMER_COPY_FOLDER_H

#include <bits/stdc++.h>

using namespace std;

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend class Folder;
public:
    //文件夹被隐式初始化为空集
    explicit Message(const std::string &str = " "):
        contents(str){ };

    //拷贝控制用来管理信息指针
    Message(const Message&); //拷贝构造函数
    Message& operator=(const Message&); //拷贝赋值
    ~Message(); //析构
    Message(Message&&); //移动构造函数
    Message& operator=(Message&&); //移动赋值

    //从特定文件夹中添加或删除信息
    void save(Folder&);
    void remove(Folder&);
    void debug_print(); //打印内容和他的文件夹列表
                        //也打印文件夹
private:
    string contents; //实际消息文本
    set<Folder*> folders; //拥有此条信息的文件夹

    //工具函数，通过拷贝构造函数，分配和析构
    //将信息添加到文件夹指向某一段
    void add_to_Folders(const Message&);
    void move_Folders(Message*);
    //从每个文件夹中移除这段信息
    void remove_from_Folders();

    //文件夹类将自己添加到所有信息集合中
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

//swap声明应该在同一个头部

class Folder {
    friend void swap(Message&, Message&);
    friend class Message;
public:
    ~Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);

    Folder(Folder&&);
    Folder& operator=(Folder&&);

    Folder() = default;

    void save(Message&);
    void remove(Message&);

    void debug_print();

private:
    set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void move_Messages(Folder*);
};


#endif //C__PRIMER_COPY_FOLDER_H
