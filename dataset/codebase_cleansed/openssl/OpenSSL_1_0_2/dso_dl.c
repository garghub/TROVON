DSO_METHOD *DSO_METHOD_dl(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_dl(void)
{
return (&dso_meth_dl);
}
static int dl_load(DSO *dso)
{
shl_t ptr = NULL;
char *filename = DSO_convert_filename(dso, NULL);
if (filename == NULL) {
DSOerr(DSO_F_DL_LOAD, DSO_R_NO_FILENAME);
goto err;
}
ptr = shl_load(filename, BIND_IMMEDIATE |
(dso->flags & DSO_FLAG_NO_NAME_TRANSLATION ? 0 :
DYNAMIC_PATH), 0L);
if (ptr == NULL) {
DSOerr(DSO_F_DL_LOAD, DSO_R_LOAD_FAILED);
ERR_add_error_data(4, "filename(", filename, "): ", strerror(errno));
goto err;
}
if (!sk_push(dso->meth_data, (char *)ptr)) {
DSOerr(DSO_F_DL_LOAD, DSO_R_STACK_ERROR);
goto err;
}
dso->loaded_filename = filename;
return (1);
err:
if (filename != NULL)
OPENSSL_free(filename);
if (ptr != NULL)
shl_unload(ptr);
return (0);
}
static int dl_unload(DSO *dso)
{
shl_t ptr;
if (dso == NULL) {
DSOerr(DSO_F_DL_UNLOAD, ERR_R_PASSED_NULL_PARAMETER);
return (0);
}
if (sk_num(dso->meth_data) < 1)
return (1);
ptr = (shl_t) sk_pop(dso->meth_data);
if (ptr == NULL) {
DSOerr(DSO_F_DL_UNLOAD, DSO_R_NULL_HANDLE);
sk_push(dso->meth_data, (char *)ptr);
return (0);
}
shl_unload(ptr);
return (1);
}
static void *dl_bind_var(DSO *dso, const char *symname)
{
shl_t ptr;
void *sym;
if ((dso == NULL) || (symname == NULL)) {
DSOerr(DSO_F_DL_BIND_VAR, ERR_R_PASSED_NULL_PARAMETER);
return (NULL);
}
if (sk_num(dso->meth_data) < 1) {
DSOerr(DSO_F_DL_BIND_VAR, DSO_R_STACK_ERROR);
return (NULL);
}
ptr = (shl_t) sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if (ptr == NULL) {
DSOerr(DSO_F_DL_BIND_VAR, DSO_R_NULL_HANDLE);
return (NULL);
}
if (shl_findsym(&ptr, symname, TYPE_UNDEFINED, &sym) < 0) {
DSOerr(DSO_F_DL_BIND_VAR, DSO_R_SYM_FAILURE);
ERR_add_error_data(4, "symname(", symname, "): ", strerror(errno));
return (NULL);
}
return (sym);
}
static DSO_FUNC_TYPE dl_bind_func(DSO *dso, const char *symname)
{
shl_t ptr;
void *sym;
if ((dso == NULL) || (symname == NULL)) {
DSOerr(DSO_F_DL_BIND_FUNC, ERR_R_PASSED_NULL_PARAMETER);
return (NULL);
}
if (sk_num(dso->meth_data) < 1) {
DSOerr(DSO_F_DL_BIND_FUNC, DSO_R_STACK_ERROR);
return (NULL);
}
ptr = (shl_t) sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if (ptr == NULL) {
DSOerr(DSO_F_DL_BIND_FUNC, DSO_R_NULL_HANDLE);
return (NULL);
}
if (shl_findsym(&ptr, symname, TYPE_UNDEFINED, &sym) < 0) {
DSOerr(DSO_F_DL_BIND_FUNC, DSO_R_SYM_FAILURE);
ERR_add_error_data(4, "symname(", symname, "): ", strerror(errno));
return (NULL);
}
return ((DSO_FUNC_TYPE)sym);
}
static char *dl_merger(DSO *dso, const char *filespec1, const char *filespec2)
{
char *merged;
if (!filespec1 && !filespec2) {
DSOerr(DSO_F_DL_MERGER, ERR_R_PASSED_NULL_PARAMETER);
return (NULL);
}
if (!filespec2 || filespec1[0] == '/') {
merged = OPENSSL_malloc(strlen(filespec1) + 1);
if (!merged) {
DSOerr(DSO_F_DL_MERGER, ERR_R_MALLOC_FAILURE);
return (NULL);
}
strcpy(merged, filespec1);
}
else if (!filespec1) {
merged = OPENSSL_malloc(strlen(filespec2) + 1);
if (!merged) {
DSOerr(DSO_F_DL_MERGER, ERR_R_MALLOC_FAILURE);
return (NULL);
}
strcpy(merged, filespec2);
} else
{
int spec2len, len;
spec2len = (filespec2 ? strlen(filespec2) : 0);
len = spec2len + (filespec1 ? strlen(filespec1) : 0);
if (filespec2 && filespec2[spec2len - 1] == '/') {
spec2len--;
len--;
}
merged = OPENSSL_malloc(len + 2);
if (!merged) {
DSOerr(DSO_F_DL_MERGER, ERR_R_MALLOC_FAILURE);
return (NULL);
}
strcpy(merged, filespec2);
merged[spec2len] = '/';
strcpy(&merged[spec2len + 1], filespec1);
}
return (merged);
}
static char *dl_name_converter(DSO *dso, const char *filename)
{
char *translated;
int len, rsize, transform;
len = strlen(filename);
rsize = len + 1;
transform = (strstr(filename, "/") == NULL);
{
rsize += strlen(extension);
if ((DSO_flags(dso) & DSO_FLAG_NAME_TRANSLATION_EXT_ONLY) == 0)
rsize += 3;
}
translated = OPENSSL_malloc(rsize);
if (translated == NULL) {
DSOerr(DSO_F_DL_NAME_CONVERTER, DSO_R_NAME_TRANSLATION_FAILED);
return (NULL);
}
if (transform) {
if ((DSO_flags(dso) & DSO_FLAG_NAME_TRANSLATION_EXT_ONLY) == 0)
sprintf(translated, "lib%s%s", filename, extension);
else
sprintf(translated, "%s%s", filename, extension);
} else
sprintf(translated, "%s", filename);
return (translated);
}
static int dl_pathbyaddr(void *addr, char *path, int sz)
{
struct shl_descriptor inf;
int i, len;
if (addr == NULL) {
union {
int (*f) (void *, char *, int);
void *p;
} t = {
dl_pathbyaddr
};
addr = t.p;
}
for (i = -1; shl_get_r(i, &inf) == 0; i++) {
if (((size_t)addr >= inf.tstart && (size_t)addr < inf.tend) ||
((size_t)addr >= inf.dstart && (size_t)addr < inf.dend)) {
len = (int)strlen(inf.filename);
if (sz <= 0)
return len + 1;
if (len >= sz)
len = sz - 1;
memcpy(path, inf.filename, len);
path[len++] = 0;
return len;
}
}
return -1;
}
static void *dl_globallookup(const char *name)
{
void *ret;
shl_t h = NULL;
return shl_findsym(&h, name, TYPE_UNDEFINED, &ret) ? NULL : ret;
}
