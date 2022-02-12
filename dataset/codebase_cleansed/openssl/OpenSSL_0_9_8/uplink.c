static void unimplemented (void)
{ OPENSSL_showfatal (sizeof(TCHAR)==sizeof(char)?"%s\n":"%S\n",msg);
ExitProcess (1);
}
void OPENSSL_Uplink (volatile void **table, int index)
{ static HMODULE volatile apphandle=NULL;
static void ** volatile applinktable=NULL;
int len;
void (*func)(void)=unimplemented;
HANDLE h;
void **p;
do {
len = _stprintf (msg,_T("OPENSSL_Uplink(%p,%02X): "),table,index);
_tcscpy (msg+len,_T("unimplemented function"));
if ((h=apphandle)==NULL)
{ if ((h=GetModuleHandle(NULL))==NULL)
{ apphandle=(HMODULE)-1;
_tcscpy (msg+len,_T("no host application"));
break;
}
apphandle = h;
}
if ((h=apphandle)==(HMODULE)-1)
break;
if (applinktable==NULL)
{ void**(*applink)();
applink=(void**(*)())GetProcAddress(h,"OPENSSL_Applink");
if (applink==NULL)
{ apphandle=(HMODULE)-1;
_tcscpy (msg+len,_T("no OPENSSL_Applink"));
break;
}
p = (*applink)();
if (p==NULL)
{ apphandle=(HMODULE)-1;
_tcscpy (msg+len,_T("no ApplinkTable"));
break;
}
applinktable = p;
}
if (index > (int)p[0])
break;
if (p[index]) func = p[index];
} while (0);
table[index] = func;
}
main() { UP_fprintf(UP_stdout,"hello, world!\n"); }
