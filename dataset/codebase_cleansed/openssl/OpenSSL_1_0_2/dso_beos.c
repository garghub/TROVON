DSO_METHOD *DSO_METHOD_beos(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_beos(void)
{
return (&dso_meth_beos);
}
static int beos_load(DSO *dso)
{
image_id id;
char *filename = DSO_convert_filename(dso, NULL);
if (filename == NULL) {
DSOerr(DSO_F_BEOS_LOAD, DSO_R_NO_FILENAME);
goto err;
}
id = load_add_on(filename);
if (id < 1) {
DSOerr(DSO_F_BEOS_LOAD, DSO_R_LOAD_FAILED);
ERR_add_error_data(3, "filename(", filename, ")");
goto err;
}
if (!sk_push(dso->meth_data, (char *)id)) {
DSOerr(DSO_F_BEOS_LOAD, DSO_R_STACK_ERROR);
goto err;
}
dso->loaded_filename = filename;
return (1);
err:
if (filename != NULL)
OPENSSL_free(filename);
if (id > 0)
unload_add_on(id);
return (0);
}
static int beos_unload(DSO *dso)
{
image_id id;
if (dso == NULL) {
DSOerr(DSO_F_BEOS_UNLOAD, ERR_R_PASSED_NULL_PARAMETER);
return (0);
}
if (sk_num(dso->meth_data) < 1)
return (1);
id = (image_id) sk_pop(dso->meth_data);
if (id < 1) {
DSOerr(DSO_F_BEOS_UNLOAD, DSO_R_NULL_HANDLE);
return (0);
}
if (unload_add_on(id) != B_OK) {
DSOerr(DSO_F_BEOS_UNLOAD, DSO_R_UNLOAD_FAILED);
sk_push(dso->meth_data, (char *)id);
return (0);
}
return (1);
}
static void *beos_bind_var(DSO *dso, const char *symname)
{
image_id id;
void *sym;
if ((dso == NULL) || (symname == NULL)) {
DSOerr(DSO_F_BEOS_BIND_VAR, ERR_R_PASSED_NULL_PARAMETER);
return (NULL);
}
if (sk_num(dso->meth_data) < 1) {
DSOerr(DSO_F_BEOS_BIND_VAR, DSO_R_STACK_ERROR);
return (NULL);
}
id = (image_id) sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if (id < 1) {
DSOerr(DSO_F_BEOS_BIND_VAR, DSO_R_NULL_HANDLE);
return (NULL);
}
if (get_image_symbol(id, symname, B_SYMBOL_TYPE_DATA, &sym) != B_OK) {
DSOerr(DSO_F_BEOS_BIND_VAR, DSO_R_SYM_FAILURE);
ERR_add_error_data(3, "symname(", symname, ")");
return (NULL);
}
return (sym);
}
static DSO_FUNC_TYPE beos_bind_func(DSO *dso, const char *symname)
{
image_id id;
void *sym;
if ((dso == NULL) || (symname == NULL)) {
DSOerr(DSO_F_BEOS_BIND_FUNC, ERR_R_PASSED_NULL_PARAMETER);
return (NULL);
}
if (sk_num(dso->meth_data) < 1) {
DSOerr(DSO_F_BEOS_BIND_FUNC, DSO_R_STACK_ERROR);
return (NULL);
}
id = (image_id) sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if (id < 1) {
DSOerr(DSO_F_BEOS_BIND_FUNC, DSO_R_NULL_HANDLE);
return (NULL);
}
if (get_image_symbol(id, symname, B_SYMBOL_TYPE_TEXT, &sym) != B_OK) {
DSOerr(DSO_F_BEOS_BIND_FUNC, DSO_R_SYM_FAILURE);
ERR_add_error_data(3, "symname(", symname, ")");
return (NULL);
}
return ((DSO_FUNC_TYPE)sym);
}
static char *beos_name_converter(DSO *dso, const char *filename)
{
char *translated;
int len, rsize, transform;
len = strlen(filename);
rsize = len + 1;
transform = (strstr(filename, "/") == NULL);
if (transform) {
rsize += 3;
if ((DSO_flags(dso) & DSO_FLAG_NAME_TRANSLATION_EXT_ONLY) == 0)
rsize += 3;
}
translated = OPENSSL_malloc(rsize);
if (translated == NULL) {
DSOerr(DSO_F_BEOS_NAME_CONVERTER, DSO_R_NAME_TRANSLATION_FAILED);
return (NULL);
}
if (transform) {
if ((DSO_flags(dso) & DSO_FLAG_NAME_TRANSLATION_EXT_ONLY) == 0)
sprintf(translated, "lib%s.so", filename);
else
sprintf(translated, "%s.so", filename);
} else
sprintf(translated, "%s", filename);
return (translated);
}
