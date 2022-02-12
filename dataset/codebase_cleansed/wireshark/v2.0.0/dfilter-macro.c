static gboolean free_value(gpointer k _U_, gpointer v, gpointer u _U_) {
fvt_cache_entry_t* e = (fvt_cache_entry_t*)v;
g_free(e->repr);
g_free(e);
return TRUE;
}
static gboolean fvt_cache_cb(proto_node * node, gpointer data _U_) {
field_info* finfo = PNODE_FINFO(node);
fvt_cache_entry_t* e;
if (!finfo) return FALSE;
if ((e = (fvt_cache_entry_t*)g_hash_table_lookup(fvt_cache,finfo->hfinfo->abbrev))) {
e->usable = FALSE;
} else if (finfo->value.ftype->val_to_string_repr) {
switch (finfo->hfinfo->type) {
case FT_NONE:
case FT_PROTOCOL:
return FALSE;
default:
break;
}
e = g_new(fvt_cache_entry_t,1);
e->name = finfo->hfinfo->abbrev,
e->repr = fvalue_to_string_repr(&(finfo->value), FTREPR_DFILTER, finfo->hfinfo->display, NULL);
e->usable = TRUE;
g_hash_table_insert(fvt_cache,(void*)finfo->hfinfo->abbrev,e);
}
return FALSE;
}
void dfilter_macro_build_ftv_cache(void* tree_root) {
g_hash_table_foreach_remove(fvt_cache,free_value,NULL);
proto_tree_traverse_post_order((proto_tree *)tree_root, fvt_cache_cb, NULL);
}
static gchar* dfilter_macro_resolve(gchar* name, gchar** args, gchar** error) {
GString* text;
int argc = 0;
dfilter_macro_t* m = NULL;
fvt_cache_entry_t* e;
int* arg_pos_p;
gchar** parts;
gchar* ret;
guint i;
for (i = 0; i < num_macros; i++) {
dfilter_macro_t* c = &(macros[i]);
if ( c->usable && g_str_equal(c->name,name) ) {
m = c;
break;
}
}
if (!m) {
if (fvt_cache &&
(e = (fvt_cache_entry_t *)g_hash_table_lookup(fvt_cache,name)) != NULL) {
if(e->usable) {
return wmem_strdup(NULL, e->repr);
} else {
if (error != NULL)
*error = g_strdup_printf("macro '%s' is unusable", name);
return NULL;
}
} else {
if (error != NULL)
*error = g_strdup_printf("macro '%s' does not exist", name);
return NULL;
}
}
DUMP_MACRO(m);
if (args) {
while(args[argc]) argc++;
}
if (argc != m->argc) {
if (error != NULL) {
*error = g_strdup_printf("wrong number of arguments for macro '%s', expecting %d instead of %d",
name, m->argc, argc);
}
return NULL;
}
arg_pos_p = m->args_pos;
parts = m->parts;
text = g_string_new(*(parts++));
if (args) {
while (*parts) {
g_string_append_printf(text,"%s%s",
args[*(arg_pos_p++)],
*(parts++));
}
}
ret = wmem_strdup(NULL, text->str);
g_string_free(text,TRUE);
return ret;
}
static const gchar* dfilter_macro_apply_recurse(const gchar* text, guint depth, gchar** error) {
enum { OUTSIDE, STARTING, NAME, ARGS } state = OUTSIDE;
GString* out;
GString* name = NULL;
GString* arg = NULL;
GPtrArray* args = NULL;
gchar c;
const gchar* r = text;
gboolean changed = FALSE;
if ( depth > 31) {
if (error != NULL)
*error = g_strdup("too much nesting in macros");
return NULL;
}
#define FGS(n) if (n) g_string_free(n,TRUE); n = NULL
#define FREE_ALL() \
do { \
FGS(name); \
FGS(arg); \
if (args) { \
while(args->len) { void* p = g_ptr_array_remove_index_fast(args,0); if (p) g_free(p); } \
g_ptr_array_free(args,TRUE); \
args = NULL; \
} \
} while(0)
if (error != NULL)
*error = NULL;
out = g_string_sized_new(64);
while(1) {
c = *r++;
switch(state) {
case OUTSIDE: {
switch(c) {
case '\0': {
goto finish;
} case '$': {
state = STARTING;
break;
} default: {
g_string_append_c(out,c);
break;
}
}
break;
} case STARTING: {
switch (c) {
case '{': {
args = g_ptr_array_new();
arg = g_string_sized_new(32);
name = g_string_sized_new(32);
state = NAME;
break;
} case '\0': {
g_string_append_c(out,'$');
goto finish;
} default: {
g_string_append_c(out,'$');
g_string_append_c(out,c);
state = OUTSIDE;
break;
}
}
break;
} case NAME: {
if ( g_ascii_isalnum(c) || c == '_' || c == '-' || c == '.' ) {
g_string_append_c(name,c);
} else if ( c == ':') {
state = ARGS;
} else if ( c == '}') {
gchar* resolved;
g_ptr_array_add(args,NULL);
resolved = dfilter_macro_resolve(name->str, (gchar**)args->pdata, error);
if (resolved == NULL)
goto on_error;
changed = TRUE;
g_string_append(out,resolved);
wmem_free(NULL, resolved);
FREE_ALL();
state = OUTSIDE;
} else if ( c == '\0') {
if (error != NULL)
*error = g_strdup("end of filter in the middle of a macro expression");
goto on_error;
} else {
if (error != NULL)
*error = g_strdup("invalid character in macro name");
goto on_error;
}
break;
} case ARGS: {
switch(c) {
case '\0': {
if (error != NULL)
*error = g_strdup("end of filter in the middle of a macro expression");
goto on_error;
} case ';': {
g_ptr_array_add(args,g_string_free(arg,FALSE));
arg = g_string_sized_new(32);
break;
} case '\\': {
c = *r++;
if (c) {
g_string_append_c(arg,c);
break;
} else {
if (error != NULL)
*error = g_strdup("end of filter in the middle of a macro expression");
goto on_error;
}
} default: {
g_string_append_c(arg,c);
break;
} case '}': {
gchar* resolved;
g_ptr_array_add(args,g_string_free(arg,FALSE));
g_ptr_array_add(args,NULL);
arg = NULL;
resolved = dfilter_macro_resolve(name->str, (gchar**)args->pdata, error);
if (resolved == NULL)
goto on_error;
changed = TRUE;
g_string_append(out,resolved);
wmem_free(NULL, resolved);
FREE_ALL();
state = OUTSIDE;
break;
}
}
break;
}
}
}
finish:
{
FREE_ALL();
if (changed) {
const gchar* resolved = dfilter_macro_apply_recurse(out->str, depth + 1, error);
g_string_free(out,TRUE);
return resolved;
} else {
const gchar* out_str = wmem_strdup(NULL, out->str);
g_string_free(out,TRUE);
return out_str;
}
}
on_error:
{
FREE_ALL();
if (error != NULL) {
if (*error == NULL)
*error = g_strdup("unknown error in macro expression");
}
g_string_free(out,TRUE);
return NULL;
}
}
const gchar* dfilter_macro_apply(const gchar* text, gchar** error) {
return dfilter_macro_apply_recurse(text, 0, error);
}
static gboolean macro_update(void* mp, gchar** error) {
dfilter_macro_t* m = (dfilter_macro_t*)mp;
GPtrArray* parts;
GArray* args_pos;
const gchar* r;
gchar* w;
gchar* part;
int argc = 0;
DUMP_MACRO(m);
*error = NULL;
if (dfilter_macro_uat && dfilter_macro_uat->post_update_cb)
dfilter_macro_uat->post_update_cb();
parts = g_ptr_array_new();
args_pos = g_array_new(FALSE,FALSE,sizeof(int));
m->priv = part = w = g_strdup(m->text);
r = m->text;
g_ptr_array_add(parts,part);
while (r && *r) {
switch (*r) {
default:
*(w++) = *(r++);
break;
case '\0':
*w = *r;
goto done;
case '\\':
*(w++) = *(++r);
r++;
break;
case '$': {
int cnt = 0;
int arg_pos = 0;
do {
char c = *(r+1);
if (c >= '0' && c <= '9') {
cnt++;
r++;
*(w++) = '\0';
arg_pos *= 10;
arg_pos += c - '0';
} else {
break;
}
} while(*r);
if (cnt) {
*(w++) = '\0';
r++;
argc = argc < arg_pos ? arg_pos : argc;
arg_pos--;
g_array_append_val(args_pos,arg_pos);
g_ptr_array_add(parts,w);
} else {
*(w++) = *(r++);
}
break;
}
}
}
done:
g_ptr_array_add(parts,NULL);
g_free(m->parts);
m->parts = (gchar**)parts->pdata;
g_free(m->args_pos);
m->args_pos = (int*)(void *)args_pos->data;
g_ptr_array_free(parts,FALSE);
g_array_free(args_pos,FALSE);
m->argc = argc;
m->usable = TRUE;
DUMP_MACRO(m);
return TRUE;
}
static void macro_free(void* r) {
dfilter_macro_t* m = (dfilter_macro_t*)r;
DUMP_MACRO(r);
g_free(m->name);
g_free(m->text);
g_free(m->priv);
g_free(m->parts);
g_free(m->args_pos);
}
static void* macro_copy(void* dest, const void* orig, size_t len _U_) {
dfilter_macro_t* d = (dfilter_macro_t*)dest;
const dfilter_macro_t* m = (const dfilter_macro_t*)orig;
DUMP_MACRO(m);
d->name = g_strdup(m->name);
d->text = g_strdup(m->text);
d->usable = m->usable;
if (m->parts) {
guint nparts = 0;
d->priv = g_strdup(m->text);
{
const gchar* oldText = m->text;
const gchar* oldPriv = (const gchar*)m->priv;
gchar* newPriv = (gchar*)d->priv;
while(oldText && *oldText) {
*(newPriv++) = *(oldPriv++);
oldText++;
}
}
do nparts++; while (m->parts[nparts]);
d->parts = (gchar **)g_memdup(m->parts,(nparts+1)*(guint)sizeof(void*));
nparts = 0;
while(m->parts[nparts]) {
if(nparts) {
d->parts[nparts] = d->parts[nparts - 1] + (m->parts[nparts] - m->parts[nparts - 1]);
} else {
d->parts[nparts] = (gchar *)d->priv;
}
nparts++;
}
d->args_pos = (int *)g_memdup(m->args_pos,(--nparts)*(guint)sizeof(int));
}
DUMP_MACRO(d);
return d;
}
static gboolean macro_name_chk(void *mp, const char *in_name, guint name_len,
const void *u1 _U_, const void *u2 _U_, char **error) {
dfilter_macro_t* m = (dfilter_macro_t*)mp;
guint i;
if (name_len == 0) {
*error = g_strdup("invalid name");
return FALSE;
}
for (i=0; i < name_len; i++) {
if (!(in_name[i] == '_' || g_ascii_isalnum(in_name[i]) ) ) {
*error = g_strdup("invalid char in name");
return FALSE;
}
}
if (!m->name || g_strcmp0(m->name, in_name)) {
for (i = 0; i < num_macros; i++) {
if (!g_strcmp0(in_name, macros[i].name)) {
*error = g_strdup_printf("macro '%s' already exists",
in_name);
return FALSE;
}
}
}
return TRUE;
}
void dfilter_macro_init(void) {
static uat_field_t uat_fields[] = {
UAT_FLD_CSTRING_OTHER(macro,name,"Name",macro_name_chk,"The name of the macro."),
UAT_FLD_CSTRING_ISPRINT(macro,text,"Text","The text this macro resolves to."),
UAT_END_FIELDS
};
dfilter_macro_uat = uat_new("Display Filter Macros",
sizeof(dfilter_macro_t),
DFILTER_MACRO_FILENAME,
TRUE,
&macros,
&num_macros,
0,
"ChDisplayFilterMacrosSection",
macro_copy,
macro_update,
macro_free,
NULL,
uat_fields);
fvt_cache = g_hash_table_new(g_str_hash,g_str_equal);
}
void dfilter_macro_get_uat(uat_t **dfmu_ptr_ptr) {
*dfmu_ptr_ptr = dfilter_macro_uat;
}
void dump_dfilter_macro_t(const dfilter_macro_t *m, const char *function, const char *file, int line)
{
printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
if(m == NULL) {
printf(" dfilter_macro_t * == NULL! (via: %s(): %s:%d)\n", function, file, line);
printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}
printf("DUMP of dfilter_macro_t: %p (via: %s(): %s:%d)\n", m, function, file, line);
printf(" &dfilter_macro->name == %p\n", &m->name);
if(m->name == NULL) {
printf(" ->name == NULL\n");
} else {
printf(" ->name == %p\n", m->name);
printf(" ->name == <%s>\n", m->name);
}
printf(" &dfilter_macro->text == %p\n", &m->text);
if(m->text == NULL) {
printf(" ->text == NULL\n");
} else {
printf(" ->text == %p\n", m->text);
printf(" ->text == <%s>\n", m->text);
}
printf(" &dfilter_macro->usable == %p\n", &m->usable);
printf(" ->usable == %u\n", m->usable);
printf(" &dfilter_macro->parts == %p\n", &m->parts);
if(m->parts == NULL) {
printf(" ->parts == NULL\n");
} else {
int i = 0;
while (m->parts[i]) {
printf(" ->parts[%d] == %p\n", i, m->parts[i]);
printf(" ->parts[%d] == <%s>\n", i, m->parts[i]);
i++;
}
printf(" ->parts[%d] == NULL\n", i);
}
printf(" &dfilter_macro->args_pos == %p\n", &m->args_pos);
if(m->args_pos == NULL) {
printf(" ->args_pos == NULL\n");
} else {
printf(" ->args_pos == %p\n", m->args_pos);
}
printf(" &dfilter_macro->argc == %p\n", &m->argc);
printf(" ->argc == %d\n", m->argc);
printf(" &dfilter_macro->priv == %p\n", &m->priv);
if(m->priv == NULL) {
printf(" ->priv == NULL\n");
} else {
printf(" ->priv == %p\n", m->priv);
printf(" ->priv == <%s>\n", (char *)m->priv);
}
printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}
