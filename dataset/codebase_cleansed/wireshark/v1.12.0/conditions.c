condition *cnd_new(const char *class_id, ...) {
va_list ap;
condition *cnd = NULL;
condition *cnd_ref = NULL;
_cnd_class *cls = NULL;
char *id = NULL;
_cnd_init();
if ((cls = (_cnd_class *)g_hash_table_lookup(classes, class_id)) == NULL) {
g_warning("cnd_new: Couldn't find class ID \"%s\"", class_id);
return NULL;
}
if ((cnd_ref = (condition *)g_malloc(sizeof(condition))) == NULL)
return NULL;
cnd_ref->user_data = NULL;
cnd_ref->eval_func = cls->eval_func;
cnd_ref->reset_func = cls->reset_func;
cnd_ref->class_id = g_strdup(class_id);
va_start(ap, class_id);
cnd = (cls->constr_func)(cnd_ref, ap);
va_end(ap);
if (cnd == NULL) {
g_free(cnd_ref);
g_free(id);
}
return cnd;
}
void cnd_delete(condition *cnd) {
_cnd_class *cls = NULL;
const char* class_id;
if (cnd == NULL)
return;
class_id = cnd->class_id;
_cnd_init();
cls = (_cnd_class *)g_hash_table_lookup(classes, class_id);
if (cls != NULL)
(cls->destr_func)(cnd);
g_free(cnd->class_id);
g_free(cnd);
}
gboolean cnd_eval(condition *cnd, ...) {
va_list ap;
gboolean ret_val = FALSE;
if (cnd == NULL)
return FALSE;
va_start(ap, cnd);
ret_val = (cnd->eval_func)(cnd, ap);
va_end(ap);
return ret_val;
}
void cnd_reset(condition *cnd) {
if (cnd != NULL)
(cnd->reset_func)(cnd);
}
void* cnd_get_user_data(condition *cnd) {
return cnd->user_data;
}
void cnd_set_user_data(condition *cnd, void *user_data) {
cnd->user_data = user_data;
}
gboolean cnd_register_class(const char *class_id,
_cnd_constr constr_func,
_cnd_destr destr_func,
_cnd_eval eval_func,
_cnd_reset reset_func) {
char *key = NULL;
_cnd_class *cls = NULL;
if ((constr_func == NULL) || (destr_func == NULL) ||
(eval_func == NULL) || (reset_func == NULL) || (class_id == NULL))
return FALSE;
_cnd_init();
if (g_hash_table_lookup(classes, class_id) != NULL) {
g_warning("cnd_register_class: Duplicate class ID \"%s\"", class_id);
return FALSE;
}
key = g_strdup(class_id);
if ((cls = (_cnd_class*)g_malloc(sizeof(_cnd_class))) == NULL) {
g_free(key);
return FALSE;
}
cls->constr_func = constr_func;
cls->destr_func = destr_func;
cls->eval_func = eval_func;
cls->reset_func = reset_func;
g_hash_table_insert(classes, key, cls);
return TRUE;
}
void cnd_unregister_class(const char* class_id) {
const char *key = (const char*)class_id;
_cnd_class *cls = NULL;
_cnd_init();
g_hash_table_foreach(classes,
_cnd_find_hash_key_for_class_id,
(gpointer)key);
cls = (_cnd_class*)g_hash_table_lookup(classes, class_id);
g_hash_table_remove(classes, class_id);
g_free(pkey);
pkey = NULL;
g_free(cls);
}
static void _cnd_init(void) {
if (classes != NULL)
return;
classes = g_hash_table_new(g_str_hash, g_str_equal);
}
void _cnd_find_hash_key_for_class_id(gpointer key,
gpointer value _U_,
gpointer user_data) {
char *class_id = (char *)user_data;
char *key_value = (char *)key;
if (strcmp(class_id, key_value) == 0)
pkey = key_value;
}
