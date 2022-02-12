static gboolean
compatible_ftypes(ftenum_t a, ftenum_t b)
{
switch (a) {
case FT_NONE:
case FT_PROTOCOL:
case FT_FLOAT:
case FT_DOUBLE:
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
case FT_IPv4:
case FT_IPv6:
case FT_IPXNET:
case FT_INT64:
case FT_UINT64:
case FT_EUI64:
return a == b;
case FT_ETHER:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_GUID:
case FT_OID:
return (b == FT_ETHER || b == FT_BYTES || b == FT_UINT_BYTES || b == FT_GUID || b == FT_OID);
case FT_BOOLEAN:
case FT_FRAMENUM:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
switch (b) {
case FT_BOOLEAN:
case FT_FRAMENUM:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
return TRUE;
default:
return FALSE;
}
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
switch (b) {
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
return TRUE;
default:
return FALSE;
}
case FT_PCRE:
case FT_NUM_TYPES:
g_assert_not_reached();
}
g_assert_not_reached();
return FALSE;
}
static fvalue_t*
mk_uint32_fvalue(guint32 val)
{
fvalue_t *fv;
fv = fvalue_new(FT_UINT32);
fvalue_set_uinteger(fv, val);
return fv;
}
static fvalue_t*
mk_fvalue_from_val_string(header_field_info *hfinfo, char *s)
{
static const true_false_string default_tf = { "True", "False" };
const true_false_string *tf = &default_tf;
switch(hfinfo->type) {
case FT_NONE:
case FT_PROTOCOL:
case FT_FLOAT:
case FT_DOUBLE:
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
case FT_IPv4:
case FT_IPv6:
case FT_IPXNET:
case FT_ETHER:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_UINT64:
case FT_INT64:
case FT_EUI64:
case FT_PCRE:
case FT_GUID:
case FT_OID:
return NULL;
case FT_BOOLEAN:
case FT_FRAMENUM:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
break;
case FT_NUM_TYPES:
g_assert_not_reached();
}
if (hfinfo->type == FT_BOOLEAN) {
if (hfinfo->strings) {
tf = (true_false_string *)hfinfo->strings;
}
if (g_ascii_strcasecmp(s, tf->true_string) == 0) {
return mk_uint32_fvalue(TRUE);
}
else if (g_ascii_strcasecmp(s, tf->false_string) == 0) {
return mk_uint32_fvalue(FALSE);
}
else {
dfilter_error_msg = NULL;
dfilter_fail("\"%s\" cannot be found among the possible values for %s.",
s, hfinfo->abbrev);
return NULL;
}
}
if (!hfinfo->strings) {
dfilter_fail("%s cannot accept strings as values.",
hfinfo->abbrev);
return NULL;
}
dfilter_error_msg = NULL;
if (hfinfo->display & BASE_RANGE_STRING) {
dfilter_fail("\"%s\" cannot accept [range] strings as values.",
hfinfo->abbrev);
}
else if (hfinfo->display == BASE_CUSTOM) {
dfilter_fail("\"%s\" cannot accept [custom] strings as values.",
hfinfo->abbrev);
}
else {
const value_string *vals = (const value_string *)hfinfo->strings;
if (hfinfo->display & BASE_EXT_STRING)
vals = VALUE_STRING_EXT_VS_P((const value_string_ext *) vals);
while (vals->strptr != NULL) {
if (g_ascii_strcasecmp(s, vals->strptr) == 0) {
return mk_uint32_fvalue(vals->value);
}
vals++;
}
dfilter_fail("\"%s\" cannot be found among the possible values for %s.",
s, hfinfo->abbrev);
}
return NULL;
}
static gboolean
is_bytes_type(enum ftenum type)
{
switch(type) {
case FT_ETHER:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_IPv6:
case FT_GUID:
case FT_OID:
return TRUE;
case FT_NONE:
case FT_PROTOCOL:
case FT_FLOAT:
case FT_DOUBLE:
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
case FT_IPv4:
case FT_IPXNET:
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_BOOLEAN:
case FT_FRAMENUM:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_PCRE:
case FT_EUI64:
return FALSE;
case FT_NUM_TYPES:
g_assert_not_reached();
}
g_assert_not_reached();
return FALSE;
}
static void
check_exists(stnode_t *st_arg1)
{
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog((" 4 check_exists() [%u]\n", i++));
switch (stnode_type_id(st_arg1)) {
case STTYPE_FIELD:
break;
case STTYPE_STRING:
case STTYPE_UNPARSED:
dfilter_fail("\"%s\" is neither a field nor a protocol name.",
stnode_data(st_arg1));
THROW(TypeError);
break;
case STTYPE_RANGE:
dfilter_fail("You cannot test whether a range is present.");
THROW(TypeError);
break;
case STTYPE_FUNCTION:
dfilter_fail("You cannot test whether a function is present.");
THROW(TypeError);
break;
case STTYPE_UNINITIALIZED:
case STTYPE_TEST:
case STTYPE_INTEGER:
case STTYPE_FVALUE:
case STTYPE_NUM_TYPES:
g_assert_not_reached();
}
}
static void
check_drange_node_sanity(gpointer data, gpointer user_data)
{
drange_node* drnode = (drange_node*)data;
struct check_drange_sanity_args *args = (struct check_drange_sanity_args*)user_data;
gint start_offset, end_offset, length;
header_field_info *hfinfo;
switch (drange_node_get_ending(drnode)) {
case DRANGE_NODE_END_T_LENGTH:
length = drange_node_get_length(drnode);
if (length <= 0) {
if (!args->err) {
args->err = TRUE;
start_offset = drange_node_get_start_offset(drnode);
hfinfo = sttype_range_hfinfo(args->st);
dfilter_fail("Range %d:%d specified for \"%s\" isn't valid, "
"as length %d isn't positive",
start_offset, length,
hfinfo->abbrev,
length);
}
}
break;
case DRANGE_NODE_END_T_OFFSET:
start_offset = drange_node_get_start_offset(drnode);
end_offset = drange_node_get_end_offset(drnode);
if (start_offset > end_offset) {
if (!args->err) {
args->err = TRUE;
hfinfo = sttype_range_hfinfo(args->st);
dfilter_fail("Range %d-%d specified for \"%s\" isn't valid, "
"as %d is greater than %d",
start_offset, end_offset,
hfinfo->abbrev,
start_offset, end_offset);
}
}
break;
case DRANGE_NODE_END_T_TO_THE_END:
break;
case DRANGE_NODE_END_T_UNINITIALIZED:
default:
g_assert_not_reached();
}
}
static void
check_drange_sanity(stnode_t *st)
{
struct check_drange_sanity_args args;
args.st = st;
args.err = FALSE;
drange_foreach_drange_node(sttype_range_drange(st),
check_drange_node_sanity, &args);
if (args.err) {
THROW(TypeError);
}
}
static void
check_function(stnode_t *st_node)
{
df_func_def_t *funcdef;
GSList *params;
guint iparam;
guint nparams;
funcdef = sttype_function_funcdef(st_node);
params = sttype_function_params(st_node);
nparams = g_slist_length(params);
if (nparams < funcdef->min_nargs) {
dfilter_fail("Function %s needs at least %u arguments.",
funcdef->name, funcdef->min_nargs);
THROW(TypeError);
} else if (nparams > funcdef->max_nargs) {
dfilter_fail("Function %s can only accept %u arguments.",
funcdef->name, funcdef->max_nargs);
THROW(TypeError);
}
iparam = 0;
while (params) {
params->data = check_param_entity((stnode_t *)params->data);
funcdef->semcheck_param_function(iparam, (stnode_t *)params->data);
params = params->next;
iparam++;
}
}
static void
check_relation_LHS_FIELD(const char *relation_string, FtypeCanFunc can_func,
gboolean allow_partial_value,
stnode_t *st_node, stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo1, *hfinfo2;
df_func_def_t *funcdef;
ftenum_t ftype1, ftype2;
fvalue_t *fvalue;
char *s;
drange_node *rn;
type2 = stnode_type_id(st_arg2);
hfinfo1 = (header_field_info*)stnode_data(st_arg1);
ftype1 = hfinfo1->type;
DebugLog((" 5 check_relation_LHS_FIELD(%s)\n", relation_string));
if (!can_func(ftype1)) {
dfilter_fail("%s (type=%s) cannot participate in '%s' comparison.",
hfinfo1->abbrev, ftype_pretty_name(ftype1),
relation_string);
THROW(TypeError);
}
if (type2 == STTYPE_FIELD) {
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail("%s and %s are not of compatible types.",
hfinfo1->abbrev, hfinfo2->abbrev);
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail("%s (type=%s) cannot participate in specified comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2));
THROW(TypeError);
}
}
else if (type2 == STTYPE_STRING) {
s = (char *)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = fvalue_from_string(FT_PCRE, s, dfilter_fail);
} else {
fvalue = fvalue_from_string(ftype1, s, dfilter_fail);
if (!fvalue) {
fvalue = mk_fvalue_from_val_string(hfinfo1, s);
}
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_UNPARSED) {
s = (char *)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = fvalue_from_unparsed(FT_PCRE, s, FALSE, dfilter_fail);
} else {
do {
fvalue = fvalue_from_unparsed(ftype1, s, allow_partial_value, dfilter_fail);
if (!fvalue) {
fvalue = mk_fvalue_from_val_string(hfinfo1, s);
}
if (!fvalue) {
if (hfinfo1->same_name_prev) {
hfinfo1 = hfinfo1->same_name_prev;
ftype1 = hfinfo1->type;
} else {
break;
}
}
} while (!fvalue);
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(st_arg2);
if (!is_bytes_type(ftype1)) {
if (!ftype_can_slice(ftype1)) {
dfilter_fail("\"%s\" is a %s and cannot be converted into a sequence of bytes.",
hfinfo1->abbrev,
ftype_pretty_name(ftype1));
THROW(TypeError);
}
new_st = stnode_new(STTYPE_RANGE, NULL);
rn = drange_node_new();
drange_node_set_start_offset(rn, 0);
drange_node_set_to_the_end(rn);
sttype_range_set1(new_st, st_arg1, rn);
sttype_test_set2_args(st_node, new_st, st_arg2);
}
}
else if (type2 == STTYPE_FUNCTION) {
funcdef = sttype_function_funcdef(st_arg2);
ftype2 = funcdef->retval_ftype;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail("%s (type=%s) and return value of %s() (type=%s) are not of compatible types.",
hfinfo1->abbrev, ftype_pretty_name(ftype1),
funcdef->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail("return value of %s() (type=%s) cannot participate in specified comparison.",
funcdef->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
check_function(st_arg2);
}
else {
g_assert_not_reached();
}
}
static void
check_relation_LHS_STRING(const char* relation_string,
FtypeCanFunc can_func, gboolean allow_partial_value _U_,
stnode_t *st_node,
stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo2;
df_func_def_t *funcdef;
ftenum_t ftype2;
fvalue_t *fvalue;
char *s;
type2 = stnode_type_id(st_arg2);
DebugLog((" 5 check_relation_LHS_STRING()\n"));
if (type2 == STTYPE_FIELD) {
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!can_func(ftype2)) {
dfilter_fail("%s (type=%s) cannot participate in '%s' comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2),
relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = fvalue_from_string(ftype2, s, dfilter_fail);
if (!fvalue) {
fvalue = mk_fvalue_from_val_string(hfinfo2, s);
if (!fvalue) {
THROW(TypeError);
}
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_STRING || type2 == STTYPE_UNPARSED) {
dfilter_fail("Neither \"%s\" nor \"%s\" are field or protocol names.",
stnode_data(st_arg1),
stnode_data(st_arg2));
THROW(TypeError);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(st_arg2);
s = (char*)stnode_data(st_arg1);
fvalue = fvalue_from_string(FT_BYTES, s, dfilter_fail);
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_FUNCTION) {
funcdef = sttype_function_funcdef(st_arg2);
ftype2 = funcdef->retval_ftype;
if (!can_func(ftype2)) {
dfilter_fail("Return value of function %s (type=%s) cannot participate in '%s' comparison.",
funcdef->name, ftype_pretty_name(ftype2),
relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = fvalue_from_string(ftype2, s, dfilter_fail);
if (!fvalue) {
THROW(TypeError);
}
check_function(st_arg2);
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else {
g_assert_not_reached();
}
}
static void
check_relation_LHS_UNPARSED(const char* relation_string,
FtypeCanFunc can_func, gboolean allow_partial_value,
stnode_t *st_node,
stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo2;
df_func_def_t *funcdef;
ftenum_t ftype2;
fvalue_t *fvalue;
char *s;
type2 = stnode_type_id(st_arg2);
DebugLog((" 5 check_relation_LHS_UNPARSED()\n"));
if (type2 == STTYPE_FIELD) {
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!can_func(ftype2)) {
dfilter_fail("%s (type=%s) cannot participate in '%s' comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2),
relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = fvalue_from_unparsed(ftype2, s, allow_partial_value, dfilter_fail);
if (!fvalue) {
fvalue = mk_fvalue_from_val_string(hfinfo2, s);
if (!fvalue) {
THROW(TypeError);
}
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_STRING || type2 == STTYPE_UNPARSED) {
dfilter_fail("Neither \"%s\" nor \"%s\" are field or protocol names.",
stnode_data(st_arg1),
stnode_data(st_arg2));
THROW(TypeError);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(st_arg2);
s = (char*)stnode_data(st_arg1);
fvalue = fvalue_from_unparsed(FT_BYTES, s, allow_partial_value, dfilter_fail);
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_FUNCTION) {
funcdef = sttype_function_funcdef(st_arg2);
ftype2 = funcdef->retval_ftype;
if (!can_func(ftype2)) {
dfilter_fail("return value of function %s() (type=%s) cannot participate in '%s' comparison.",
funcdef->name, ftype_pretty_name(ftype2), relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = fvalue_from_unparsed(ftype2, s, allow_partial_value, dfilter_fail);
if (!fvalue) {
THROW(TypeError);
}
check_function(st_arg2);
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else {
g_assert_not_reached();
}
}
static void
check_relation_LHS_RANGE(const char *relation_string, FtypeCanFunc can_func _U_,
gboolean allow_partial_value,
stnode_t *st_node,
stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo1, *hfinfo2;
df_func_def_t *funcdef;
ftenum_t ftype1, ftype2;
fvalue_t *fvalue;
char *s;
drange_node *rn;
int len_range;
type2 = stnode_type_id(st_arg2);
hfinfo1 = sttype_range_hfinfo(st_arg1);
ftype1 = hfinfo1->type;
DebugLog((" 5 check_relation_LHS_RANGE(%s)\n", relation_string));
if (!ftype_can_slice(ftype1)) {
dfilter_fail("\"%s\" is a %s and cannot be sliced into a sequence of bytes.",
hfinfo1->abbrev, ftype_pretty_name(ftype1));
THROW(TypeError);
}
check_drange_sanity(st_arg1);
if (type2 == STTYPE_FIELD) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_FIELD)\n"));
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!is_bytes_type(ftype2)) {
if (!ftype_can_slice(ftype2)) {
dfilter_fail("\"%s\" is a %s and cannot be converted into a sequence of bytes.",
hfinfo2->abbrev,
ftype_pretty_name(ftype2));
THROW(TypeError);
}
new_st = stnode_new(STTYPE_RANGE, NULL);
rn = drange_node_new();
drange_node_set_start_offset(rn, 0);
drange_node_set_to_the_end(rn);
sttype_range_set1(new_st, st_arg2, rn);
sttype_test_set2_args(st_node, st_arg1, new_st);
}
}
else if (type2 == STTYPE_STRING) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_STRING)\n"));
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = fvalue_from_string(FT_PCRE, s, dfilter_fail);
} else {
fvalue = fvalue_from_string(FT_BYTES, s, dfilter_fail);
}
if (!fvalue) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_STRING): Could not convert from string!\n"));
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_UNPARSED) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_UNPARSED)\n"));
s = (char*)stnode_data(st_arg2);
len_range = drange_get_total_length(sttype_range_drange(st_arg1));
if (strcmp(relation_string, "matches") == 0) {
fvalue = fvalue_from_unparsed(FT_PCRE, s, FALSE, dfilter_fail);
}
else if (len_range == 1 && strlen(s) == 4 && strncmp(s, "0x", 2) == 0) {
fvalue = fvalue_from_unparsed(FT_UINT8, s, allow_partial_value, dfilter_fail);
if (fvalue) {
FVALUE_FREE(fvalue);
fvalue = fvalue_from_unparsed(FT_BYTES, s+2, allow_partial_value, dfilter_fail);
}
}
else {
fvalue = fvalue_from_unparsed(FT_BYTES, s, allow_partial_value, dfilter_fail);
}
if (!fvalue) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_UNPARSED): Could not convert from string!\n"));
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_RANGE) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_RANGE)\n"));
check_drange_sanity(st_arg2);
}
else if (type2 == STTYPE_FUNCTION) {
funcdef = sttype_function_funcdef(st_arg2);
ftype2 = funcdef->retval_ftype;
if (!is_bytes_type(ftype2)) {
if (!ftype_can_slice(ftype2)) {
dfilter_fail("Return value of function \"%s\" is a %s and cannot be converted into a sequence of bytes.",
funcdef->name,
ftype_pretty_name(ftype2));
THROW(TypeError);
}
}
check_function(st_arg2);
}
else {
g_assert_not_reached();
}
}
static stnode_t*
check_param_entity(stnode_t *st_node)
{
sttype_id_t e_type;
stnode_t *new_st;
fvalue_t *fvalue;
char *s;
e_type = stnode_type_id(st_node);
if (e_type == STTYPE_UNPARSED) {
s = (char*)stnode_data(st_node);
fvalue = fvalue_from_unparsed(FT_STRING, s, FALSE, dfilter_fail);
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
stnode_free(st_node);
return new_st;
}
return st_node;
}
static void
check_relation_LHS_FUNCTION(const char *relation_string, FtypeCanFunc can_func,
gboolean allow_partial_value,
stnode_t *st_node, stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo2;
ftenum_t ftype1, ftype2;
fvalue_t *fvalue;
char *s;
drange_node *rn;
df_func_def_t *funcdef;
df_func_def_t *funcdef2;
check_function(st_arg1);
type2 = stnode_type_id(st_arg2);
funcdef = sttype_function_funcdef(st_arg1);
ftype1 = funcdef->retval_ftype;
sttype_function_params(st_arg1);
DebugLog((" 5 check_relation_LHS_FUNCTION(%s)\n", relation_string));
if (!can_func(ftype1)) {
dfilter_fail("Function %s (type=%s) cannot participate in '%s' comparison.",
funcdef->name, ftype_pretty_name(ftype1),
relation_string);
THROW(TypeError);
}
if (type2 == STTYPE_FIELD) {
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail("Function %s and %s are not of compatible types.",
funcdef->name, hfinfo2->abbrev);
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail("%s (type=%s) cannot participate in specified comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2));
THROW(TypeError);
}
}
else if (type2 == STTYPE_STRING) {
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = fvalue_from_string(FT_PCRE, s, dfilter_fail);
} else {
fvalue = fvalue_from_string(ftype1, s, dfilter_fail);
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_UNPARSED) {
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = fvalue_from_unparsed(FT_PCRE, s, FALSE, dfilter_fail);
} else {
fvalue = fvalue_from_unparsed(ftype1, s, allow_partial_value, dfilter_fail);
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(st_arg2);
if (!is_bytes_type(ftype1)) {
if (!ftype_can_slice(ftype1)) {
dfilter_fail("Function \"%s\" is a %s and cannot be converted into a sequence of bytes.",
funcdef->name,
ftype_pretty_name(ftype1));
THROW(TypeError);
}
new_st = stnode_new(STTYPE_RANGE, NULL);
rn = drange_node_new();
drange_node_set_start_offset(rn, 0);
drange_node_set_to_the_end(rn);
sttype_range_set1(new_st, st_arg1, rn);
sttype_test_set2_args(st_node, new_st, st_arg2);
}
}
else if (type2 == STTYPE_FUNCTION) {
funcdef2 = sttype_function_funcdef(st_arg2);
ftype2 = funcdef2->retval_ftype;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail("Return values of function %s (type=%s) and function %s (type=%s) are not of compatible types.",
funcdef->name, ftype_pretty_name(ftype1), funcdef2->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail("Return value of %s (type=%s) cannot participate in specified comparison.",
funcdef2->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
check_function(st_arg2);
}
else {
g_assert_not_reached();
}
}
static void
check_relation(const char *relation_string, gboolean allow_partial_value,
FtypeCanFunc can_func, stnode_t *st_node,
stnode_t *st_arg1, stnode_t *st_arg2)
{
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
header_field_info *hfinfo;
DebugLog((" 4 check_relation(\"%s\") [%u]\n", relation_string, i++));
if (stnode_type_id(st_arg2) == STTYPE_FIELD) {
hfinfo = (header_field_info*)stnode_data(st_arg2);
if (hfinfo->type == FT_PROTOCOL) {
dfilter_fail("Protocol (\"%s\") cannot appear on right-hand side of comparison.", hfinfo->abbrev);
THROW(TypeError);
}
}
switch (stnode_type_id(st_arg1)) {
case STTYPE_FIELD:
check_relation_LHS_FIELD(relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_STRING:
check_relation_LHS_STRING(relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_RANGE:
check_relation_LHS_RANGE(relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_UNPARSED:
check_relation_LHS_UNPARSED(relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_FUNCTION:
check_relation_LHS_FUNCTION(relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_UNINITIALIZED:
case STTYPE_TEST:
case STTYPE_INTEGER:
case STTYPE_FVALUE:
default:
g_assert_not_reached();
}
}
static void
check_test(stnode_t *st_node)
{
test_op_t st_op;
stnode_t *st_arg1, *st_arg2;
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog((" 3 check_test(stnode_t *st_node = %p) [%u]\n", st_node, i));
sttype_test_get(st_node, &st_op, &st_arg1, &st_arg2);
switch (st_op) {
case TEST_OP_UNINITIALIZED:
g_assert_not_reached();
break;
case TEST_OP_EXISTS:
check_exists(st_arg1);
break;
case TEST_OP_NOT:
semcheck(st_arg1);
break;
case TEST_OP_AND:
case TEST_OP_OR:
semcheck(st_arg1);
semcheck(st_arg2);
break;
case TEST_OP_EQ:
check_relation("==", FALSE, ftype_can_eq, st_node, st_arg1, st_arg2);
break;
case TEST_OP_NE:
check_relation("!=", FALSE, ftype_can_ne, st_node, st_arg1, st_arg2);
break;
case TEST_OP_GT:
check_relation(">", FALSE, ftype_can_gt, st_node, st_arg1, st_arg2);
break;
case TEST_OP_GE:
check_relation(">=", FALSE, ftype_can_ge, st_node, st_arg1, st_arg2);
break;
case TEST_OP_LT:
check_relation("<", FALSE, ftype_can_lt, st_node, st_arg1, st_arg2);
break;
case TEST_OP_LE:
check_relation("<=", FALSE, ftype_can_le, st_node, st_arg1, st_arg2);
break;
case TEST_OP_BITWISE_AND:
check_relation("&", FALSE, ftype_can_bitwise_and, st_node, st_arg1, st_arg2);
break;
case TEST_OP_CONTAINS:
check_relation("contains", TRUE, ftype_can_contains, st_node, st_arg1, st_arg2);
break;
case TEST_OP_MATCHES:
check_relation("matches", TRUE, ftype_can_matches, st_node, st_arg1, st_arg2); break;
default:
g_assert_not_reached();
}
DebugLog((" 3 check_test(stnode_t *st_node = %p) [%u] - End\n", st_node, i++));
}
static void
semcheck(stnode_t *st_node)
{
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog((" 2 semcheck(stnode_t *st_node = %p) [%u]\n", st_node, i++));
switch (stnode_type_id(st_node)) {
case STTYPE_TEST:
check_test(st_node);
break;
default:
g_assert_not_reached();
}
}
gboolean
dfw_semcheck(dfwork_t *dfw)
{
volatile gboolean ok_filter = TRUE;
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog(("1 dfw_semcheck(dfwork_t *dfw = %p) [%u]\n", dfw, i));
TRY {
semcheck(dfw->st_root);
}
CATCH(TypeError) {
ok_filter = FALSE;
}
ENDTRY;
DebugLog(("1 dfw_semcheck(dfwork_t *dfw = %p) [%u] - Returns %d\n",
dfw, i++,ok_filter));
return ok_filter;
}
