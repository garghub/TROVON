DSO_METHOD *DSO_METHOD_dlfcn(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_dlfcn(void)
{
return(&dso_meth_dlfcn);
}
static int dlfcn_load(DSO *dso, const char *filename)
{
void *ptr;
char translated[DSO_MAX_TRANSLATED_SIZE];
int len;
len = strlen(filename);
if((dso->flags & DSO_FLAG_NAME_TRANSLATION) &&
(len + 6 < DSO_MAX_TRANSLATED_SIZE) &&
(strstr(filename, "/") == NULL))
{
sprintf(translated, "lib%s.so", filename);
ptr = dlopen(translated, DLOPEN_FLAG);
}
else
{
ptr = dlopen(filename, DLOPEN_FLAG);
}
if(ptr == NULL)
{
DSOerr(DSO_F_DLFCN_LOAD,DSO_R_LOAD_FAILED);
return(0);
}
if(!sk_push(dso->meth_data, (char *)ptr))
{
DSOerr(DSO_F_DLFCN_LOAD,DSO_R_STACK_ERROR);
dlclose(ptr);
return(0);
}
return(1);
}
static int dlfcn_unload(DSO *dso)
{
void *ptr;
if(dso == NULL)
{
DSOerr(DSO_F_DLFCN_UNLOAD,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(sk_num(dso->meth_data) < 1)
return(1);
ptr = (void *)sk_pop(dso->meth_data);
if(ptr == NULL)
{
DSOerr(DSO_F_DLFCN_UNLOAD,DSO_R_NULL_HANDLE);
sk_push(dso->meth_data, (char *)ptr);
return(0);
}
dlclose(ptr);
return(1);
}
static void *dlfcn_bind_var(DSO *dso, const char *symname)
{
void *ptr, *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_DLFCN_BIND_VAR,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_DLFCN_BIND_VAR,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (void *)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_DLFCN_BIND_VAR,DSO_R_NULL_HANDLE);
return(NULL);
}
sym = dlsym(ptr, symname);
if(sym == NULL)
{
DSOerr(DSO_F_DLFCN_BIND_VAR,DSO_R_SYM_FAILURE);
return(NULL);
}
return(sym);
}
static DSO_FUNC_TYPE dlfcn_bind_func(DSO *dso, const char *symname)
{
void *ptr;
DSO_FUNC_TYPE sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_DLFCN_BIND_FUNC,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_DLFCN_BIND_FUNC,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (void *)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_DLFCN_BIND_FUNC,DSO_R_NULL_HANDLE);
return(NULL);
}
sym = (DSO_FUNC_TYPE)dlsym(ptr, symname);
if(sym == NULL)
{
DSOerr(DSO_F_DLFCN_BIND_FUNC,DSO_R_SYM_FAILURE);
return(NULL);
}
return(sym);
}
static long dlfcn_ctrl(DSO *dso, int cmd, long larg, void *parg)
{
if(dso == NULL)
{
DSOerr(DSO_F_DLFCN_CTRL,ERR_R_PASSED_NULL_PARAMETER);
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
DSOerr(DSO_F_DLFCN_CTRL,DSO_R_UNKNOWN_COMMAND);
return(-1);
}
