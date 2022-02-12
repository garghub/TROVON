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
ret->meth_data = sk_new_null();
if((ret->meth_data = sk_new_null()) == NULL)
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
sk_free(dso->meth_data);
OPENSSL_free(dso);
return(1);
}
int DSO_flags(DSO *dso)
{
return((dso == NULL) ? 0 : dso->flags);
}
int DSO_up(DSO *dso)
{
if (dso == NULL)
{
DSOerr(DSO_F_DSO_UP,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
CRYPTO_add(&dso->references,1,CRYPTO_LOCK_DSO);
return(1);
}
DSO *DSO_load(DSO *dso, const char *filename, DSO_METHOD *meth, int flags)
{
DSO *ret;
int allocated = 0;
if(filename == NULL)
{
DSOerr(DSO_F_DSO_LOAD,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(dso == NULL)
{
ret = DSO_new_method(meth);
if(ret == NULL)
{
DSOerr(DSO_F_DSO_LOAD,ERR_R_MALLOC_FAILURE);
return(NULL);
}
allocated = 1;
}
else
ret = dso;
if(DSO_ctrl(ret, DSO_CTRL_SET_FLAGS, flags, NULL) < 0)
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_CTRL_FAILED);
if(allocated)
DSO_free(ret);
return(NULL);
}
if(ret->meth->dso_load == NULL)
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_UNSUPPORTED);
if(allocated)
DSO_free(ret);
return(NULL);
}
if(!ret->meth->dso_load(ret, filename))
{
DSOerr(DSO_F_DSO_LOAD,DSO_R_LOAD_FAILED);
if(allocated)
DSO_free(ret);
return(NULL);
}
return(ret);
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
if((dso->meth == NULL) || (dso->meth->dso_ctrl == NULL))
{
DSOerr(DSO_F_DSO_CTRL,DSO_R_UNSUPPORTED);
return(-1);
}
return(dso->meth->dso_ctrl(dso,cmd,larg,parg));
}
