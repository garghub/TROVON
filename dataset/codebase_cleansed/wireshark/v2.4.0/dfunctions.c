static gboolean
string_walk(GList* arg1list, GList **retval, gchar(*conv_func)(gchar))
{
GList *arg1;
fvalue_t *arg_fvalue;
fvalue_t *new_ft_string;
char *s, *c;
arg1 = arg1list;
while (arg1) {
arg_fvalue = (fvalue_t *)arg1->data;
if (IS_FT_STRING(fvalue_type_ftenum(arg_fvalue))) {
s = (char *)wmem_strdup(NULL, (gchar *)fvalue_get(arg_fvalue));
for (c = s; *c; c++) {
*c = conv_func(*c);
}
new_ft_string = fvalue_new(FT_STRING);
fvalue_set_string(new_ft_string, s);
wmem_free(NULL, s);
*retval = g_list_append(*retval, new_ft_string);
}
arg1 = arg1->next;
}
return TRUE;
}
static gboolean
df_func_lower(GList* arg1list, GList *arg2junk _U_, GList **retval)
{
return string_walk(arg1list, retval, g_ascii_tolower);
}
static gboolean
df_func_upper(GList* arg1list, GList *arg2junk _U_, GList **retval)
{
return string_walk(arg1list, retval, g_ascii_toupper);
}
static gboolean
df_func_len(GList* arg1list, GList *arg2junk _U_, GList **retval)
{
GList *arg1;
fvalue_t *arg_fvalue;
fvalue_t *ft_len;
arg1 = arg1list;
while (arg1) {
arg_fvalue = (fvalue_t *)arg1->data;
switch (fvalue_type_ftenum(arg_fvalue))
{
case FT_STRING:
case FT_STRINGZ:
case FT_STRINGZPAD:
case FT_UINT_STRING:
case FT_BYTES:
case FT_UINT_BYTES:
ft_len = fvalue_new(FT_UINT32);
fvalue_set_uinteger(ft_len, fvalue_length(arg_fvalue));
*retval = g_list_append(*retval, ft_len);
break;
default:
break;
}
arg1 = arg1->next;
}
return TRUE;
}
static gboolean
df_func_size(GList* arg1list, GList *arg2junk _U_, GList **retval)
{
GList *arg1;
fvalue_t *arg_fvalue;
fvalue_t *ft_len;
arg1 = arg1list;
while (arg1) {
arg_fvalue = (fvalue_t *)arg1->data;
ft_len = fvalue_new(FT_UINT32);
fvalue_set_uinteger(ft_len, fvalue_length(arg_fvalue));
*retval = g_list_append(*retval, ft_len);
arg1 = arg1->next;
}
return TRUE;
}
static gboolean
df_func_count(GList* arg1list, GList *arg2junk _U_, GList **retval)
{
fvalue_t *ft_ret;
guint32 num_items;
num_items = (guint32)g_list_length(arg1list);
ft_ret = fvalue_new(FT_UINT32);
fvalue_set_uinteger(ft_ret, num_items);
*retval = g_list_append(*retval, ft_ret);
return TRUE;
}
static void
ul_semcheck_params(dfwork_t *dfw, int param_num, stnode_t *st_node)
{
sttype_id_t type;
ftenum_t ftype;
header_field_info *hfinfo;
type = stnode_type_id(st_node);
if (param_num == 0) {
switch(type) {
case STTYPE_FIELD:
hfinfo = (header_field_info *)stnode_data(st_node);
ftype = hfinfo->type;
if (!IS_FT_STRING(ftype)) {
dfilter_fail(dfw, "Only strings can be used in upper() or lower() or len()");
THROW(TypeError);
}
break;
default:
dfilter_fail(dfw, "Only string-type fields can be used in upper() or lower() or len()");
THROW(TypeError);
}
}
else {
g_assert_not_reached();
}
}
static void
ul_semcheck_len_params(dfwork_t *dfw, int param_num, stnode_t *st_node)
{
sttype_id_t type;
ftenum_t ftype;
header_field_info *hfinfo;
type = stnode_type_id(st_node);
if (param_num == 0) {
switch(type) {
case STTYPE_FIELD:
hfinfo = (header_field_info *)stnode_data(st_node);
ftype = hfinfo->type;
switch (ftype)
{
case FT_STRING:
case FT_STRINGZ:
case FT_STRINGZPAD:
case FT_UINT_STRING:
case FT_BYTES:
case FT_UINT_BYTES:
break;
default:
dfilter_fail(dfw, "Only string and byte type fields can be used in len()");
THROW(TypeError);
break;
}
break;
default:
dfilter_fail(dfw, "Only string and byte type fields can be used in len()");
THROW(TypeError);
}
}
else {
g_assert_not_reached();
}
}
static void
ul_semcheck_field_param(dfwork_t *dfw, int param_num, stnode_t *st_node)
{
sttype_id_t type;
type = stnode_type_id(st_node);
if (param_num == 0) {
switch(type) {
case STTYPE_FIELD:
break;
default:
dfilter_fail(dfw, "Only type fields can be used as parameter "
"for size() or count()");
THROW(TypeError);
}
}
else {
g_assert_not_reached();
}
}
df_func_def_t*
df_func_lookup(char *name)
{
df_func_def_t *func_def;
func_def = df_functions;
while (func_def->function != NULL) {
if (strcmp(func_def->name, name) == 0) {
return func_def;
}
func_def++;
}
return NULL;
}
