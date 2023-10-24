#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <winsock.h>
#ifndef EMAILS_H
#define EMAILS_H
#define MAX_ID 10
#define MAX_DATA_SIZE 128
#define MAX_BODY_SIZE 1024

#pragma once
using namespace std;

class Emails
{
public:
    Emails();
    void setIdentifier(const char* identifier);
    const char* getIdentifier() const;
    void  setDateTime();
    const char* getDateTime() const;
    void setFrom(const char* from);
    const char* getFrom() const;
    void setTo(const char* to);
    const char* getTo() const;
    void setCc(const char* cc);
    const char* getCc() const;
    void setBcc(const char* bcc);
    const char* getBcc() const;
    void setSubject(const char* subject);
    const char* getSubject() const;
    void setBody(const char* body);
    const char* getBody() const;
    void readFromUser();

private:
    char identifier[MAX_ID];
    char dateTime[MAX_DATA_SIZE];
    char from[MAX_DATA_SIZE];
    char to[MAX_DATA_SIZE];
    char cc[MAX_DATA_SIZE];
    char bcc[MAX_DATA_SIZE];
    char subject[MAX_DATA_SIZE];
    char body[MAX_BODY_SIZE];
    char bodyMail[MAX_BODY_SIZE];
};

#endif
