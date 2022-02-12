DSO_METHOD *DSO_METHOD_win32(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_win32(void)
{
return(&dso_meth_win32);
}
static int win32_load(DSO *dso)
{
HINSTANCE h = NULL, *p = NULL;
char *filename = DSO_convert_filename(dso, NULL);
if(filename == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_NO_FILENAME);
goto err;
}
h = LoadLibrary(filename);
if(h == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_LOAD_FAILED);
ERR_add_error_data(3, "filename(", filename, ")");
goto err;
}
p = (HINSTANCE *)OPENSSL_malloc(sizeof(HINSTANCE));
if(p == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,ERR_R_MALLOC_FAILURE);
goto err;
}
*p = h;
if(!sk_push(dso->meth_data, (char *)p))
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_STACK_ERROR);
goto err;
}
dso->loaded_filename = filename;
return(1);
err:
if(filename != NULL)
OPENSSL_free(filename);
if(p != NULL)
OPENSSL_free(p);
if(h != NULL)
FreeLibrary(h);
return(0);
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
ERR_add_error_data(3, "symname(", symname, ")");
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
ERR_add_error_data(3, "symname(", symname, ")");
return(NULL);
}
return((DSO_FUNC_TYPE)sym);
}
static char *win32_name_converter(DSO *dso, const char *filename)
{
char *translated;
int len, transform;
len = strlen(filename);
transform = ((strstr(filename, "/") == NULL) &&
(strstr(filename, "\\") == NULL) &&
(strstr(filename, ":") == NULL));
if(transform)
translated = OPENSSL_malloc(len + 5);
else
translated = OPENSSL_malloc(len + 1);
if(translated == NULL)
{
DSOerr(DSO_F_WIN32_NAME_CONVERTER,
DSO_R_NAME_TRANSLATION_FAILED);
return(NULL);
}
if(transform)
sprintf(translated, "%s.dll", filename);
else
sprintf(translated, "%s", filename);
return(translated);
}
