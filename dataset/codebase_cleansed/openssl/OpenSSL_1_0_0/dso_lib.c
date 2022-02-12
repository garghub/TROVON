DSO *DSO_new(void)
{
return(DSO_new_method(NULL));
}
void DSO_set_default_method(DSO_METHOD *meth)
{
default_DSO_meth = meth;
}
DSO_METHOD *DSO_get_default_method(void)
{
return(default_DSO_meth);
}
DSO_METHOD *DSO_get_method(DSO *dso)
{
return(dso->meth);
}
DSO_METHOD *DSO_set_method(DSO *dso, DSO_METHOD *meth)
{
DSO_METHOD *mtmp;
mtmp = dso->meth;
dso->meth = meth;
return(mtmp);
}
DSO *DSO_new_method(DSO_METHOD *meth)
{
DSO *ret;
if(default_DSO_meth == NULL)
default_DSO_meth = DSO_METHOD_openssl();
ret = (DSO *)OPENSSL_malloc(sizeof(DSO));
if(ret == NULL)
{
DSOerr(DSO_F_DSO_NEW_METHOD,ERR_R_MALLOC_FAILURE);
return(NULL);
}
memset(ret, 0, sizeof(DSO));
ret->meth_data = sk_void_new_null();
if(ret->meth_data == NULL)
{
DSOerr(DSO_F_DSO_NEW_METHOD,ERR_R_MALLOC_FAILURE);
OPENSSL_free(ret);
return(NULL);
}
if(meth == NULL)
ret->meth = default_DSO_meth;
else
ret->meth = meth;
ret->references = 1;
if((ret->meth->init != NULL) && !ret->meth->init(ret))
{
OPENSSL_free(ret);
ret=NULL;
}
return(ret);
}
int DSO_free(DSO *dso)
{
int i;
if(dso == NULL)
{
DSOerr(DSO_F_DSO_FREE,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
i=CRYPTO_add(&dso->references,-1,CRYPTO_LOCK_DSO);
#ifdef REF_PRINT
REF_PRINT("DSO",dso);
#endif
if(i > 0) return(1);
#ifdef REF_CHECK
if(i < 0)
{
fprintf(stderr,"DSO_free, bad reference count\n");
abort();
}
#endif
if((dso->meth->dso_unload != NULL) && !dso->meth->dso_unload(dso))
{
DSOerr(DSO_F_DSO_FREE,DSO_R_UNLOAD_FAILED);
return(0);
}
if((dso->meth->finish != NULL) && !dso->meth->finish(dso))
{
DSOerr(DSO_F_DSO_FREE,DSO_R_FINISH_FAILED);
return(0);
}
sk_void_free(dso->meth_data);
if(dso->filename != NULL)
OPENSSL_free(dso->filename);
if(dso->loaded_filename != NULL)
OPENSSL_free(dso->loaded_filename);
OPENSSL_free(dso);
return(1);
}
int DSO_flags(DSO *dso)
{
return((dso == NULL) ? 0 : dso->flags);
}
int DSO_up_ref(DSO *dso)
{
if (dso == NULL)
{
DSOerr(DSO_F_DSO_UP_REF,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
CRYPTO_add(&dso->references,1,CRYPTO_LOCK_DSO);
return(1);
}
DSO *DSO_load(DSO *dso, const char *filename, DSO_METHOD *meth, int flags)
{
DSO *ret;
int allocated = 0;
if(dso == NULL)
{
ret = DSO_new_method(meth);
if(ret == NULL)
{
DSOerr(DSO_F_DSO_LOAD,ERR_R_MALLOC_FAILURE);
goto err;
}
allocated = 1;
if(DSO_ctrl(ret, DSO_CTRL_SET_FLAGS, flags, NULL) < 0)
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_CTRL_FAILED);
goto err;
}
}
else
ret = dso;
if(ret->filename != NULL)
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_DSO_ALREADY_LOADED);
goto err;
}
if(filename != NULL)
if(!DSO_set_filename(ret, filename))
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_SET_FILENAME_FAILED);
goto err;
}
filename = ret->filename;
if(filename == NULL)
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_NO_FILENAME);
goto err;
}
if(ret->meth->dso_load == NULL)
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_UNSUPPORTED);
goto err;
}
if(!ret->meth->dso_load(ret))
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_LOAD_FAILED);
goto err;
}
return(ret);
err:
if(allocated)
DSO_free(ret);
return(NULL);
}
void *DSO_bind_var(DSO *dso, const char *symname)
{
void *ret = NULL;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_DSO_BIND_VAR,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(dso->meth->dso_bind_var == NULL)
{
DSOerr(DSO_F_DSO_BIND_VAR,DSO_R_UNSUPPORTED);
return(NULL);
}
if((ret = dso->meth->dso_bind_var(dso, symname)) == NULL)
{
DSOerr(DSO_F_DSO_BIND_VAR,DSO_R_SYM_FAILURE);
return(NULL);
}
return(ret);
}
DSO_FUNC_TYPE DSO_bind_func(DSO *dso, const char *symname)
{
DSO_FUNC_TYPE ret = NULL;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_DSO_BIND_FUNC,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(dso->meth->dso_bind_func == NULL)
{
DSOerr(DSO_F_DSO_BIND_FUNC,DSO_R_UNSUPPORTED);
return(NULL);
}
if((ret = dso->meth->dso_bind_func(dso, symname)) == NULL)
{
DSOerr(DSO_F_DSO_BIND_FUNC,DSO_R_SYM_FAILURE);
return(NULL);
}
return(ret);
}
long DSO_ctrl(DSO *dso, int cmd, long larg, void *parg)
{
if(dso == NULL)
{
DSOerr(DSO_F_DSO_CTRL,ERR_R_PASSED_NULL_PARAMETER);
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
if((dso->meth == NULL) || (dso->meth->dso_ctrl == NULL))
{
DSOerr(DSO_F_DSO_CTRL,DSO_R_UNSUPPORTED);
return(-1);
}
return(dso->meth->dso_ctrl(dso,cmd,larg,parg));
}
int DSO_set_name_converter(DSO *dso, DSO_NAME_CONVERTER_FUNC cb,
DSO_NAME_CONVERTER_FUNC *oldcb)
{
if(dso == NULL)
{
DSOerr(DSO_F_DSO_SET_NAME_CONVERTER,
ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(oldcb)
*oldcb = dso->name_converter;
dso->name_converter = cb;
return(1);
}
const char *DSO_get_filename(DSO *dso)
{
if(dso == NULL)
{
DSOerr(DSO_F_DSO_GET_FILENAME,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
return(dso->filename);
}
int DSO_set_filename(DSO *dso, const char *filename)
{
char *copied;
if((dso == NULL) || (filename == NULL))
{
DSOerr(DSO_F_DSO_SET_FILENAME,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(dso->loaded_filename)
{
DSOerr(DSO_F_DSO_SET_FILENAME,DSO_R_DSO_ALREADY_LOADED);
return(0);
}
copied = OPENSSL_malloc(strlen(filename) + 1);
if(copied == NULL)
{
DSOerr(DSO_F_DSO_SET_FILENAME,ERR_R_MALLOC_FAILURE);
return(0);
}
BUF_strlcpy(copied, filename, strlen(filename) + 1);
if(dso->filename)
OPENSSL_free(dso->filename);
dso->filename = copied;
return(1);
}
char *DSO_merge(DSO *dso, const char *filespec1, const char *filespec2)
{
char *result = NULL;
if(dso == NULL || filespec1 == NULL)
{
DSOerr(DSO_F_DSO_MERGE,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if((dso->flags & DSO_FLAG_NO_NAME_TRANSLATION) == 0)
{
if(dso->merger != NULL)
result = dso->merger(dso, filespec1, filespec2);
else if(dso->meth->dso_merger != NULL)
result = dso->meth->dso_merger(dso,
filespec1, filespec2);
}
return(result);
}
char *DSO_convert_filename(DSO *dso, const char *filename)
{
char *result = NULL;
if(dso == NULL)
{
DSOerr(DSO_F_DSO_CONVERT_FILENAME,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(filename == NULL)
filename = dso->filename;
if(filename == NULL)
{
DSOerr(DSO_F_DSO_CONVERT_FILENAME,DSO_R_NO_FILENAME);
return(NULL);
}
if((dso->flags & DSO_FLAG_NO_NAME_TRANSLATION) == 0)
{
if(dso->name_converter != NULL)
result = dso->name_converter(dso, filename);
else if(dso->meth->dso_name_converter != NULL)
result = dso->meth->dso_name_converter(dso, filename);
}
if(result == NULL)
{
result = OPENSSL_malloc(strlen(filename) + 1);
if(result == NULL)
{
DSOerr(DSO_F_DSO_CONVERT_FILENAME,
ERR_R_MALLOC_FAILURE);
return(NULL);
}
BUF_strlcpy(result, filename, strlen(filename) + 1);
}
return(result);
}
const char *DSO_get_loaded_filename(DSO *dso)
{
if(dso == NULL)
{
DSOerr(DSO_F_DSO_GET_LOADED_FILENAME,
ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
return(dso->loaded_filename);
}
int DSO_pathbyaddr(void *addr,char *path,int sz)
{
DSO_METHOD *meth = default_DSO_meth;
if (meth == NULL) meth = DSO_METHOD_openssl();
if (meth->pathbyaddr == NULL)
{
DSOerr(DSO_F_DSO_PATHBYADDR,DSO_R_UNSUPPORTED);
return -1;
}
return (*meth->pathbyaddr)(addr,path,sz);
}
void *DSO_global_lookup(const char *name)
{
DSO_METHOD *meth = default_DSO_meth;
if (meth == NULL) meth = DSO_METHOD_openssl();
if (meth->globallookup == NULL)
{
DSOerr(DSO_F_DSO_GLOBAL_LOOKUP,DSO_R_UNSUPPORTED);
return NULL;
}
return (*meth->globallookup)(name);
}
