//
// Created by Apple on 2022/2/23.
//

#ifndef C__PRIMER_COPY_STRFOLDER_H
#define C__PRIMER_COPY_STRFOLDER_H

#include <bits/stdc++.h>
#include "String.h"

using namespace std;

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend class Folder;

public:
    explicit Message(const String &str = ""):
        contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    Message(Message&&);
    Message& operator=(Message&&);

    void save(Folder&);
    void remove(Folder&);
    void debug_print();

private:
    String contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void move_Folders(Message*);
    void remove_frome_Folder();
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message&, Message&);

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


#endif //C__PRIMER_COPY_STRFOLDER_H
