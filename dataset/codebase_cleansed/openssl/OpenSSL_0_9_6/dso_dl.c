DSO_METHOD *DSO_METHOD_dl(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_dl(void)
{
return(&dso_meth_dl);
}
static int dl_load(DSO *dso, const char *filename)
{
shl_t ptr;
char translated[DSO_MAX_TRANSLATED_SIZE];
int len;
len = strlen(filename);
if((dso->flags & DSO_FLAG_NAME_TRANSLATION) &&
(len + 6 < DSO_MAX_TRANSLATED_SIZE) &&
(strstr(filename, "/") == NULL))
{
sprintf(translated, "lib%s.so", filename);
ptr = shl_load(translated, BIND_IMMEDIATE, NULL);
}
else
ptr = shl_load(filename, BIND_IMMEDIATE, NULL);
if(ptr == NULL)
{
DSOerr(DSO_F_DL_LOAD,DSO_R_LOAD_FAILED);
return(0);
}
if(!sk_push(dso->meth_data, (char *)ptr))
{
DSOerr(DSO_F_DL_LOAD,DSO_R_STACK_ERROR);
shl_unload(ptr);
return(0);
}
return(1);
}
static int dl_unload(DSO *dso)
{
shl_t ptr;
if(dso == NULL)
{
DSOerr(DSO_F_DL_UNLOAD,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(sk_num(dso->meth_data) < 1)
return(1);
ptr = (shl_t)sk_pop(dso->meth_data);
if(ptr == NULL)
{
DSOerr(DSO_F_DL_UNLOAD,DSO_R_NULL_HANDLE);
sk_push(dso->meth_data, (char *)ptr);
return(0);
}
shl_unload(ptr);
return(1);
}
static void *dl_bind_var(DSO *dso, const char *symname)
{
shl_t ptr;
void *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_DL_BIND_VAR,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_DL_BIND_VAR,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (shl_t)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_DL_BIND_VAR,DSO_R_NULL_HANDLE);
return(NULL);
}
if (shl_findsym(ptr, symname, TYPE_UNDEFINED, &sym) < 0)
{
DSOerr(DSO_F_DL_BIND_VAR,DSO_R_SYM_FAILURE);
return(NULL);
}
return(sym);
}
static DSO_FUNC_TYPE dl_bind_func(DSO *dso, const char *symname)
{
shl_t ptr;
void *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_DL_BIND_FUNC,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_DL_BIND_FUNC,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (shl_t)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_DL_BIND_FUNC,DSO_R_NULL_HANDLE);
return(NULL);
}
if (shl_findsym(ptr, symname, TYPE_UNDEFINED, &sym) < 0)
{
DSOerr(DSO_F_DL_BIND_FUNC,DSO_R_SYM_FAILURE);
return(NULL);
}
return((DSO_FUNC_TYPE)sym);
}
static int dl_ctrl(DSO *dso, int cmd, long larg, void *parg)
{
if(dso == NULL)
{
DSOerr(DSO_F_DL_CTRL,ERR_R_PASSED_NULL_PARAMETER);
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
DSOerr(DSO_F_DL_CTRL,DSO_R_UNKNOWN_COMMAND);
return(-1);
}
