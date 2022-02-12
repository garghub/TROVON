DSO_METHOD *DSO_METHOD_dlfcn(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_dlfcn(void)
{
return(&dso_meth_dlfcn);
}
static int dlfcn_load(DSO *dso)
{
void *ptr = NULL;
char *filename = DSO_convert_filename(dso, NULL);
if(filename == NULL)
{
DSOerr(DSO_F_DLFCN_LOAD,DSO_R_NO_FILENAME);
goto err;
}
ptr = dlopen(filename, DLOPEN_FLAG);
if(ptr == NULL)
{
DSOerr(DSO_F_DLFCN_LOAD,DSO_R_LOAD_FAILED);
ERR_add_error_data(4, "filename(", filename, "): ", dlerror());
goto err;
}
if(!sk_push(dso->meth_data, (char *)ptr))
{
DSOerr(DSO_F_DLFCN_LOAD,DSO_R_STACK_ERROR);
goto err;
}
dso->loaded_filename = filename;
return(1);
err:
if(filename != NULL)
OPENSSL_free(filename);
if(ptr != NULL)
dlclose(ptr);
return(0);
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
ERR_add_error_data(4, "symname(", symname, "): ", dlerror());
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
ERR_add_error_data(4, "symname(", symname, "): ", dlerror());
return(NULL);
}
return(sym);
}
static char *dlfcn_name_converter(DSO *dso, const char *filename)
{
char *translated;
int len, rsize, transform;
len = strlen(filename);
rsize = len + 1;
transform = (strstr(filename, "/") == NULL);
if(transform)
{
rsize += 3;
if ((DSO_flags(dso) & DSO_FLAG_NAME_TRANSLATION_EXT_ONLY) == 0)
rsize += 3;
}
translated = OPENSSL_malloc(rsize);
if(translated == NULL)
{
DSOerr(DSO_F_DLFCN_NAME_CONVERTER,
DSO_R_NAME_TRANSLATION_FAILED);
return(NULL);
}
if(transform)
{
if ((DSO_flags(dso) & DSO_FLAG_NAME_TRANSLATION_EXT_ONLY) == 0)
sprintf(translated, "lib%s.so", filename);
else
sprintf(translated, "%s.so", filename);
}
else
sprintf(translated, "%s", filename);
return(translated);
}
