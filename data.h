#ifndef DATA_H
#define DATA_H
typedef struct _Header_Upload
{
    ushort work_tags;
    ushort protocol_tags;
    ushort length;
    uchar unit_tags;
    uchar fun_code;
} Header_Upload;

#endif // DATA_H
