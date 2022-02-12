DSO_METHOD *DSO_METHOD_win32(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_win32(void)
{
return(&dso_meth_win32);
}
static int win32_load(DSO *dso, const char *filename)
{
HINSTANCE h, *p;
char translated[DSO_MAX_TRANSLATED_SIZE];
int len;
len = strlen(filename);
if((dso->flags & DSO_FLAG_NAME_TRANSLATION) &&
(len + 4 < DSO_MAX_TRANSLATED_SIZE) &&
(strstr(filename, "/") == NULL) &&
(strstr(filename, "\\") == NULL) &&
(strstr(filename, ":") == NULL))
{
sprintf(translated, "%s.dll", filename);
h = LoadLibrary(translated);
}
else
h = LoadLibrary(filename);
if(h == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_LOAD_FAILED);
return(0);
}
p = (HINSTANCE *)OPENSSL_malloc(sizeof(HINSTANCE));
if(p == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,ERR_R_MALLOC_FAILURE);
FreeLibrary(h);
return(0);
}
*p = h;
if(!sk_push(dso->meth_data, (char *)p))
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_STACK_ERROR);
FreeLibrary(h);
OPENSSL_free(p);
return(0);
}
return(1);
}
static int win32_unload(DSO *dso)
{
HINSTANCE *p;
if(dso == NULL)
{
DSOerr(DSO_F_WIN32_UNLOAD,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(sk_num(dso->meth_data) < 1)
return(1);
p = (HINSTANCE *)sk_pop(dso->meth_data);
if(p == NULL)
{
DSOerr(DSO_F_WIN32_UNLOAD,DSO_R_NULL_HANDLE);
return(0);
}
if(!FreeLibrary(*p))
{
DSOerr(DSO_F_WIN32_UNLOAD,DSO_R_UNLOAD_FAILED);
sk_push(dso->meth_data, (char *)p);
return(0);
}
OPENSSL_free(p);
return(1);
}
static void *win32_bind_var(DSO *dso, const char *symname)
{
HINSTANCE *ptr;
void *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_WIN32_BIND_VAR,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_WIN32_BIND_VAR,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (HINSTANCE *)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_WIN32_BIND_VAR,DSO_R_NULL_HANDLE);
return(NULL);
}
sym = GetProcAddress(*ptr, symname);
if(sym == NULL)
{
DSOerr(DSO_F_WIN32_BIND_VAR,DSO_R_SYM_FAILURE);
return(NULL);
}
return(sym);
}
static DSO_FUNC_TYPE win32_bind_func(DSO *dso, const char *symname)
{
HINSTANCE *ptr;
void *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_WIN32_BIND_FUNC,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_WIN32_BIND_FUNC,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (HINSTANCE *)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_WIN32_BIND_FUNC,DSO_R_NULL_HANDLE);
return(NULL);
}
sym = GetProcAddress(*ptr, symname);
if(sym == NULL)
{
DSOerr(DSO_F_WIN32_BIND_FUNC,DSO_R_SYM_FAILURE);
return(NULL);
}
return((DSO_FUNC_TYPE)sym);
}
static long win32_ctrl(DSO *dso, int cmd, long larg, void *parg)
{
if(dso == NULL)
{
DSOerr(DSO_F_WIN32_CTRL,ERR_R_PASSED_NULL_PARAMETER);
return(-1);
}
switch(cmd)
{
case DSO_CTRL_GET_FLAGS:
return dso->flags;
case DSO_CTRL_SET_FLAGS:
dso->flags = (int)larg;
return(0);
case DSO_CTRL_OR_FLAGS:
dso->flags |= (int)larg;
return(0);
default:
break;
}
DSOerr(DSO_F_WIN32_CTRL,DSO_R_UNKNOWN_COMMAND);
return(-1);
}
