#include "Emails.h"

Emails::Emails()
{

}

void Emails::setIdentifier(const char *identifier)
{
    // Omitir el dato "Identifier" ingresado por el usuario
    // strcpy(this->identifier, identifier);
    // this->identifier[MAX_ID - 1] = '\0';

    // Obtener el dato "Identifier" de forma automática ascendente comenzanco por 0000000000 de 1 en 1
    static int id = 0;
    sprintf(this->identifier, "%010d", id++);
    this->identifier[MAX_ID - 1] = '\0';
}

const char *Emails::getIdentifier() const
{
    return identifier;
}

void Emails::setDateTime()
{
    // Obtener la fecha y hora actual del sistema
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);

    // Formatear la fecha
    ostringstream dateTimeStream;
    dateTimeStream << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    strncpy(dateTime, dateTimeStream.str().c_str(), sizeof(dateTime));
}

const char *Emails::getDateTime() const
{
    return dateTime;
}

void Emails::setFrom(const char *from)
{
    // Obtener el dato "From" ingresado por el usuario
    // strcpy(this->from, from);
    // this->from[MAX_DATA_SIZE - 1] = '\0';

    // Obtener el dato "From" desde el nombre de la máquina
    if (strcmp(this->from, "") == 0)
    {
        char hostname[MAX_DATA_SIZE];
        gethostname(hostname, sizeof(hostname));
        strcpy(this->from, hostname);
        this->from[MAX_DATA_SIZE - 1] = '\0';
    }
}

const char *Emails::getFrom() const
{
    return from;
}

void Emails::setTo(const char *to)
{
    strcpy(this->to, to);
    this->to[MAX_DATA_SIZE - 1] = '\0';
}

const char *Emails::getTo() const
{
    return to;
}

void Emails::setCc(const char *cc)
{
    strcpy(this->cc, cc);
    this->cc[MAX_DATA_SIZE - 1] = '\0';
}

const char *Emails::getCc() const
{
    return cc;
}

void Emails::setBcc(const char *bcc)
{
    strcpy(this->bcc, bcc);
    this->bcc[MAX_DATA_SIZE - 1] = '\0';
}

const char *Emails::getBcc() const
{
    return bcc;
}

void Emails::setSubject(const char *subject)
{
    strcpy(this->subject, subject);
    this->subject[MAX_DATA_SIZE - 1] = '\0';
}

const char *Emails::getSubject() const
{
    return subject;
}

void Emails::setBody(const char *body)
{
    strcpy(this->body, body);
    this->body[MAX_BODY_SIZE - 1] = '\0';
}

const char *Emails::getBody() const
{
    return body;
}

void Emails::readFromUser()
{
    cout << "Identifier (MAX LENGHT 10 CHAR): ";
    cin >> identifier;

    // Omitir el dato "From" ingresado por el usuario
    // cout << "From: ";
    // cin.ignore();
    // cin.getline(from, sizeof(from));

    cout << "To: ";
    cin.ignore();
    cin.getline(to, sizeof(to));
    cout << "CC: ";
    cin.ignore();
    cin.getline(cc, sizeof(cc));
    cout << "BCC: ";
    cin.ignore();
    cin.getline(bcc, sizeof(bcc));
    cout << "Subject: ";
    cin.ignore();
    cin.getline(subject, sizeof(subject));
    cout << "Mail content: ";
    cin.ignore();
    int size = 0;
    while (cin.getline(body, sizeof(body)) && strcmp(body, "") != 0)
    {
        if ((size + strlen(body) + 1) < sizeof(body))
        {
            strcpy(body + size, bodyMail);
            size += strlen(body);
            bodyMail[size++];
        }
        else
        {
            cout << "Mail too large. It will truncate.";
            break;
        }
    }
}

