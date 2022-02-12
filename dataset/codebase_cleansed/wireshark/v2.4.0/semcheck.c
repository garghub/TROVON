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
case FT_IEEE_11073_SFLOAT:
case FT_IEEE_11073_FLOAT:
case FT_IPv4:
case FT_IPv6:
case FT_IPXNET:
case FT_INT40:
case FT_UINT40:
case FT_INT48:
case FT_UINT48:
case FT_INT56:
case FT_UINT56:
case FT_INT64:
case FT_UINT64:
case FT_EUI64:
return a == b;
case FT_ETHER:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_GUID:
case FT_OID:
case FT_AX25:
case FT_VINES:
case FT_FCWWN:
case FT_REL_OID:
case FT_SYSTEM_ID:
return (b == FT_ETHER || b == FT_BYTES || b == FT_UINT_BYTES || b == FT_GUID || b == FT_OID || b == FT_AX25 || b == FT_VINES || b == FT_FCWWN || b == FT_REL_OID || b == FT_SYSTEM_ID);
case FT_BOOLEAN:
case FT_FRAMENUM:
case FT_CHAR:
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
case FT_CHAR:
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
case FT_STRINGZPAD:
switch (b) {
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
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
dfilter_fvalue_from_unparsed(dfwork_t *dfw, ftenum_t ftype, const char *s, gboolean allow_partial_value)
{
return fvalue_from_unparsed(ftype, s, allow_partial_value,
dfw->error_message == NULL ? &dfw->error_message : NULL);
}
static fvalue_t*
dfilter_fvalue_from_string(dfwork_t *dfw, ftenum_t ftype, const char *s)
{
return fvalue_from_string(ftype, s,
dfw->error_message == NULL ? &dfw->error_message : NULL);
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
mk_uint64_fvalue(guint64 val)
{
fvalue_t *fv;
fv = fvalue_new(FT_UINT64);
fvalue_set_uinteger64(fv, val);
return fv;
}
static fvalue_t*
mk_fvalue_from_val_string(dfwork_t *dfw, header_field_info *hfinfo, char *s)
{
static const true_false_string default_tf = { "True", "False" };
const true_false_string *tf = &default_tf;
switch(hfinfo->type) {
case FT_NONE:
case FT_PROTOCOL:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IEEE_11073_SFLOAT:
case FT_IEEE_11073_FLOAT:
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
case FT_IPv4:
case FT_IPv6:
case FT_IPXNET:
case FT_AX25:
case FT_VINES:
case FT_FCWWN:
case FT_ETHER:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
case FT_EUI64:
case FT_PCRE:
case FT_GUID:
case FT_OID:
case FT_REL_OID:
case FT_SYSTEM_ID:
case FT_FRAMENUM:
return NULL;
case FT_BOOLEAN:
case FT_CHAR:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
case FT_INT64:
break;
case FT_NUM_TYPES:
g_assert_not_reached();
}
if (hfinfo->type == FT_BOOLEAN) {
if (hfinfo->strings) {
tf = (const true_false_string *)hfinfo->strings;
}
if (g_ascii_strcasecmp(s, tf->true_string) == 0) {
return mk_uint64_fvalue(TRUE);
}
else if (g_ascii_strcasecmp(s, tf->false_string) == 0) {
return mk_uint64_fvalue(FALSE);
}
else {
g_free(dfw->error_message);
dfw->error_message = NULL;
dfilter_fail(dfw, "\"%s\" cannot be found among the possible values for %s.",
s, hfinfo->abbrev);
return NULL;
}
}
if (!hfinfo->strings) {
dfilter_fail(dfw, "%s cannot accept strings as values.",
hfinfo->abbrev);
return NULL;
}
g_free(dfw->error_message);
dfw->error_message = NULL;
if (hfinfo->display & BASE_RANGE_STRING) {
dfilter_fail(dfw, "\"%s\" cannot accept [range] strings as values.",
hfinfo->abbrev);
}
else if (hfinfo->display & BASE_VAL64_STRING) {
const val64_string *vals = (const val64_string *)hfinfo->strings;
while (vals->strptr != NULL) {
if (g_ascii_strcasecmp(s, vals->strptr) == 0) {
return mk_uint64_fvalue(vals->value);
}
vals++;
}
dfilter_fail(dfw, "\"%s\" cannot be found among the possible values for %s.",
s, hfinfo->abbrev);
}
else if (hfinfo->display == BASE_CUSTOM) {
dfilter_fail(dfw, "\"%s\" cannot accept [custom] strings as values.",
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
dfilter_fail(dfw, "\"%s\" cannot be found among the possible values for %s.",
s, hfinfo->abbrev);
}
return NULL;
}
static gboolean
is_bytes_type(enum ftenum type)
{
switch(type) {
case FT_AX25:
case FT_VINES:
case FT_FCWWN:
case FT_ETHER:
case FT_BYTES:
case FT_UINT_BYTES:
case FT_IPv6:
case FT_GUID:
case FT_OID:
case FT_REL_OID:
case FT_SYSTEM_ID:
return TRUE;
case FT_NONE:
case FT_PROTOCOL:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IEEE_11073_SFLOAT:
case FT_IEEE_11073_FLOAT:
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
case FT_IPv4:
case FT_IPXNET:
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
case FT_BOOLEAN:
case FT_FRAMENUM:
case FT_CHAR:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT40:
case FT_UINT48:
case FT_UINT56:
case FT_UINT64:
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT40:
case FT_INT48:
case FT_INT56:
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
check_exists(dfwork_t *dfw, stnode_t *st_arg1)
{
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog((" 4 check_exists() [%u]\n", i++));
switch (stnode_type_id(st_arg1)) {
case STTYPE_FIELD:
break;
case STTYPE_STRING:
case STTYPE_CHARCONST:
case STTYPE_UNPARSED:
dfilter_fail(dfw, "\"%s\" is neither a field nor a protocol name.",
(char *)stnode_data(st_arg1));
THROW(TypeError);
break;
case STTYPE_RANGE:
dfilter_fail(dfw, "You cannot test whether a range is present.");
THROW(TypeError);
break;
case STTYPE_FUNCTION:
dfilter_fail(dfw, "You cannot test whether a function is present.");
THROW(TypeError);
break;
case STTYPE_UNINITIALIZED:
case STTYPE_TEST:
case STTYPE_INTEGER:
case STTYPE_FVALUE:
case STTYPE_SET:
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
stnode_t *entity;
header_field_info *hfinfo;
switch (drange_node_get_ending(drnode)) {
case DRANGE_NODE_END_T_LENGTH:
length = drange_node_get_length(drnode);
if (length <= 0) {
if (!args->err) {
args->err = TRUE;
start_offset = drange_node_get_start_offset(drnode);
entity = sttype_range_entity(args->st);
if (entity && stnode_type_id(entity) == STTYPE_FIELD) {
hfinfo = (header_field_info *)stnode_data(entity);
dfilter_fail(args->dfw, "Range %d:%d specified for \"%s\" isn't valid, "
"as length %d isn't positive",
start_offset, length,
hfinfo->abbrev,
length);
} else
dfilter_fail(args->dfw, "Range %d:%d isn't valid, "
"as length %d isn't positive",
start_offset, length,
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
entity = sttype_range_entity(args->st);
if (entity && stnode_type_id(entity) == STTYPE_FIELD) {
hfinfo = (header_field_info *)stnode_data(entity);
dfilter_fail(args->dfw, "Range %d-%d specified for \"%s\" isn't valid, "
"as %d is greater than %d",
start_offset, end_offset,
hfinfo->abbrev,
start_offset, end_offset);
} else
dfilter_fail(args->dfw, "Range %d-%d isn't valid, "
"as %d is greater than %d",
start_offset, end_offset,
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
check_drange_sanity(dfwork_t *dfw, stnode_t *st)
{
struct check_drange_sanity_args args;
args.dfw = dfw;
args.st = st;
args.err = FALSE;
drange_foreach_drange_node(sttype_range_drange(st),
check_drange_node_sanity, &args);
if (args.err) {
THROW(TypeError);
}
}
static stnode_t *
convert_to_bytes(stnode_t *arg)
{
stnode_t *new_st;
drange_node *rn;
new_st = stnode_new(STTYPE_RANGE, NULL);
rn = drange_node_new();
drange_node_set_start_offset(rn, 0);
drange_node_set_to_the_end(rn);
sttype_range_set1(new_st, arg, rn);
return new_st;
}
static void
check_function(dfwork_t *dfw, stnode_t *st_node)
{
df_func_def_t *funcdef;
GSList *params;
guint iparam;
guint nparams;
funcdef = sttype_function_funcdef(st_node);
params = sttype_function_params(st_node);
nparams = g_slist_length(params);
if (nparams < funcdef->min_nargs) {
dfilter_fail(dfw, "Function %s needs at least %u arguments.",
funcdef->name, funcdef->min_nargs);
THROW(TypeError);
} else if (nparams > funcdef->max_nargs) {
dfilter_fail(dfw, "Function %s can only accept %u arguments.",
funcdef->name, funcdef->max_nargs);
THROW(TypeError);
}
iparam = 0;
while (params) {
params->data = check_param_entity(dfw, (stnode_t *)params->data);
funcdef->semcheck_param_function(dfw, iparam, (stnode_t *)params->data);
params = params->next;
iparam++;
}
}
static fvalue_t *
charconst_to_bytes(dfwork_t *dfw, char *s, gboolean allow_partial_value)
{
fvalue_t *fvalue;
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_CHAR, s, allow_partial_value);
if (fvalue) {
char *temp_string;
temp_string = g_strdup_printf("%02x", fvalue->value.uinteger);
FVALUE_FREE(fvalue);
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_BYTES, temp_string, allow_partial_value);
g_free(temp_string);
}
return (fvalue);
}
static void
check_relation_LHS_FIELD(dfwork_t *dfw, const char *relation_string,
FtypeCanFunc can_func, gboolean allow_partial_value,
stnode_t *st_node, stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo1, *hfinfo2;
df_func_def_t *funcdef;
ftenum_t ftype1, ftype2;
fvalue_t *fvalue;
char *s;
type2 = stnode_type_id(st_arg2);
hfinfo1 = (header_field_info*)stnode_data(st_arg1);
ftype1 = hfinfo1->type;
if (stnode_type_id(st_node) == STTYPE_TEST) {
DebugLog((" 5 check_relation_LHS_FIELD(%s)\n", relation_string));
} else {
DebugLog((" 6 check_relation_LHS_FIELD(%s)\n", relation_string));
}
if (!can_func(ftype1)) {
dfilter_fail(dfw, "%s (type=%s) cannot participate in '%s' comparison.",
hfinfo1->abbrev, ftype_pretty_name(ftype1),
relation_string);
THROW(TypeError);
}
if (type2 == STTYPE_FIELD) {
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail(dfw, "%s and %s are not of compatible types.",
hfinfo1->abbrev, hfinfo2->abbrev);
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail(dfw, "%s (type=%s) cannot participate in specified comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2));
THROW(TypeError);
}
}
else if (type2 == STTYPE_STRING || type2 == STTYPE_UNPARSED ||
type2 == STTYPE_CHARCONST) {
s = (char *)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
if (type2 == STTYPE_STRING)
fvalue = dfilter_fvalue_from_string(dfw, FT_PCRE, s);
else
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_PCRE, s, FALSE);
} else {
while (hfinfo1->same_name_prev_id != -1 &&
((type2 == STTYPE_STRING && ftype1 != FT_STRING && ftype1!= FT_STRINGZ) ||
(type2 != STTYPE_STRING && (ftype1 == FT_STRING || ftype1== FT_STRINGZ)))) {
hfinfo1 = proto_registrar_get_nth(hfinfo1->same_name_prev_id);
ftype1 = hfinfo1->type;
}
if (type2 == STTYPE_STRING)
fvalue = dfilter_fvalue_from_string(dfw, ftype1, s);
else if (type2 == STTYPE_CHARCONST &&
strcmp(relation_string, "contains") == 0) {
fvalue = charconst_to_bytes(dfw, s, allow_partial_value);
} else
fvalue = dfilter_fvalue_from_unparsed(dfw, ftype1, s, allow_partial_value);
if (!fvalue && type2 != STTYPE_CHARCONST) {
fvalue = mk_fvalue_from_val_string(dfw, hfinfo1, s);
if (fvalue && dfw->error_message) {
g_free(dfw->error_message);
dfw->error_message = NULL;
}
}
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
if (stnode_type_id(st_node) == STTYPE_TEST) {
sttype_test_set2_args(st_node, st_arg1, new_st);
} else {
sttype_set_replace_element(st_node, st_arg2, new_st);
}
stnode_free(st_arg2);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(dfw, st_arg2);
if (!is_bytes_type(ftype1)) {
if (!ftype_can_slice(ftype1)) {
dfilter_fail(dfw, "\"%s\" is a %s and cannot be converted into a sequence of bytes.",
hfinfo1->abbrev,
ftype_pretty_name(ftype1));
THROW(TypeError);
}
new_st = convert_to_bytes(st_arg1);
sttype_test_set2_args(st_node, new_st, st_arg2);
}
}
else if (type2 == STTYPE_FUNCTION) {
funcdef = sttype_function_funcdef(st_arg2);
ftype2 = funcdef->retval_ftype;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail(dfw, "%s (type=%s) and return value of %s() (type=%s) are not of compatible types.",
hfinfo1->abbrev, ftype_pretty_name(ftype1),
funcdef->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail(dfw, "return value of %s() (type=%s) cannot participate in specified comparison.",
funcdef->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
check_function(dfw, st_arg2);
}
else if (type2 == STTYPE_SET) {
GSList *nodelist;
if (strcmp(relation_string, "in") != 0) {
g_assert_not_reached();
}
nodelist = (GSList*)stnode_data(st_arg2);
while (nodelist) {
stnode_t *node = (stnode_t*)nodelist->data;
if (stnode_type_id(node) == STTYPE_RANGE) {
dfilter_fail(dfw, "A range may not appear inside a set.");
THROW(TypeError);
break;
}
check_relation_LHS_FIELD(dfw, "==", can_func,
allow_partial_value, st_arg2, st_arg1, node);
nodelist = g_slist_next(nodelist);
}
}
else {
g_assert_not_reached();
}
}
static void
check_relation_LHS_STRING(dfwork_t *dfw, const char* relation_string,
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
dfilter_fail(dfw, "%s (type=%s) cannot participate in '%s' comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2),
relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = dfilter_fvalue_from_string(dfw, ftype2, s);
if (!fvalue) {
fvalue = mk_fvalue_from_val_string(dfw, hfinfo2, s);
if (!fvalue) {
THROW(TypeError);
}
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_STRING || type2 == STTYPE_UNPARSED ||
type2 == STTYPE_CHARCONST) {
dfilter_fail(dfw, "Neither \"%s\" nor \"%s\" are field or protocol names.",
(char *)stnode_data(st_arg1),
(char *)stnode_data(st_arg2));
THROW(TypeError);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(dfw, st_arg2);
s = (char*)stnode_data(st_arg1);
fvalue = dfilter_fvalue_from_string(dfw, FT_BYTES, s);
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
dfilter_fail(dfw, "Return value of function %s (type=%s) cannot participate in '%s' comparison.",
funcdef->name, ftype_pretty_name(ftype2),
relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = dfilter_fvalue_from_string(dfw, ftype2, s);
if (!fvalue) {
THROW(TypeError);
}
check_function(dfw, st_arg2);
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_SET) {
dfilter_fail(dfw, "Only a field may be tested for membership in a set.");
THROW(TypeError);
}
else {
g_assert_not_reached();
}
}
static void
check_relation_LHS_UNPARSED(dfwork_t *dfw, const char* relation_string,
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
dfilter_fail(dfw, "%s (type=%s) cannot participate in '%s' comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2),
relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = dfilter_fvalue_from_unparsed(dfw, ftype2, s, allow_partial_value);
if (!fvalue) {
fvalue = mk_fvalue_from_val_string(dfw, hfinfo2, s);
if (!fvalue) {
THROW(TypeError);
}
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_STRING || type2 == STTYPE_UNPARSED ||
type2 == STTYPE_CHARCONST) {
dfilter_fail(dfw, "Neither \"%s\" nor \"%s\" are field or protocol names.",
(char *)stnode_data(st_arg1),
(char *)stnode_data(st_arg2));
THROW(TypeError);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(dfw, st_arg2);
s = (char*)stnode_data(st_arg1);
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_BYTES, s, allow_partial_value);
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
dfilter_fail(dfw, "return value of function %s() (type=%s) cannot participate in '%s' comparison.",
funcdef->name, ftype_pretty_name(ftype2), relation_string);
THROW(TypeError);
}
s = (char*)stnode_data(st_arg1);
fvalue = dfilter_fvalue_from_unparsed(dfw, ftype2, s, allow_partial_value);
if (!fvalue) {
THROW(TypeError);
}
check_function(dfw, st_arg2);
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, new_st, st_arg2);
stnode_free(st_arg1);
}
else if (type2 == STTYPE_SET) {
dfilter_fail(dfw, "Only a field may be tested for membership in a set.");
THROW(TypeError);
}
else {
g_assert_not_reached();
}
}
static void
check_relation_LHS_RANGE(dfwork_t *dfw, const char *relation_string,
FtypeCanFunc can_func _U_,
gboolean allow_partial_value,
stnode_t *st_node,
stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
stnode_t *entity1;
header_field_info *hfinfo1, *hfinfo2;
ftenum_t ftype1, ftype2;
fvalue_t *fvalue;
char *s;
int len_range;
DebugLog((" 5 check_relation_LHS_RANGE(%s)\n", relation_string));
type2 = stnode_type_id(st_arg2);
entity1 = sttype_range_entity(st_arg1);
if (entity1 && stnode_type_id(entity1) == STTYPE_FIELD) {
hfinfo1 = (header_field_info *)stnode_data(entity1);
ftype1 = hfinfo1->type;
if (!ftype_can_slice(ftype1)) {
dfilter_fail(dfw, "\"%s\" is a %s and cannot be sliced into a sequence of bytes.",
hfinfo1->abbrev, ftype_pretty_name(ftype1));
THROW(TypeError);
}
} else if (entity1 && stnode_type_id(entity1) == STTYPE_FUNCTION) {
df_func_def_t *funcdef = sttype_function_funcdef(entity1);
ftype1 = funcdef->retval_ftype;
if (!ftype_can_slice(ftype1)) {
dfilter_fail(dfw, "Return value of function \"%s\" is a %s and cannot be converted into a sequence of bytes.",
funcdef->name, ftype_pretty_name(ftype1));
THROW(TypeError);
}
check_function(dfw, entity1);
} else {
if (entity1 == NULL) {
dfilter_fail(dfw, "Range is not supported, details: " G_STRLOC " entity: NULL");
} else {
dfilter_fail(dfw, "Range is not supported, details: " G_STRLOC " entity: %p of type %d",
(void *)entity1, stnode_type_id(entity1));
}
THROW(TypeError);
}
check_drange_sanity(dfw, st_arg1);
if (type2 == STTYPE_FIELD) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_FIELD)\n"));
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!is_bytes_type(ftype2)) {
if (!ftype_can_slice(ftype2)) {
dfilter_fail(dfw, "\"%s\" is a %s and cannot be converted into a sequence of bytes.",
hfinfo2->abbrev,
ftype_pretty_name(ftype2));
THROW(TypeError);
}
new_st = convert_to_bytes(st_arg2);
sttype_test_set2_args(st_node, st_arg1, new_st);
}
}
else if (type2 == STTYPE_STRING) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_STRING)\n"));
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = dfilter_fvalue_from_string(dfw, FT_PCRE, s);
} else {
fvalue = dfilter_fvalue_from_string(dfw, FT_BYTES, s);
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
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_PCRE, s, FALSE);
}
else if (len_range == 1 && strlen(s) == 4 && strncmp(s, "0x", 2) == 0) {
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_UINT8, s, allow_partial_value);
if (fvalue) {
FVALUE_FREE(fvalue);
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_BYTES, s+2, allow_partial_value);
}
}
else {
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_BYTES, s, allow_partial_value);
}
if (!fvalue) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_UNPARSED): Could not convert from string!\n"));
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_CHARCONST) {
DebugLog((" 5 check_relation_LHS_RANGE(type2 = STTYPE_CHARCONST)\n"));
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_PCRE, s, FALSE);
} else {
fvalue = charconst_to_bytes(dfw, s, allow_partial_value);
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
check_drange_sanity(dfw, st_arg2);
}
else if (type2 == STTYPE_FUNCTION) {
df_func_def_t *funcdef = sttype_function_funcdef(st_arg2);
ftype2 = funcdef->retval_ftype;
if (!is_bytes_type(ftype2)) {
if (!ftype_can_slice(ftype2)) {
dfilter_fail(dfw, "Return value of function \"%s\" is a %s and cannot be converted into a sequence of bytes.",
funcdef->name,
ftype_pretty_name(ftype2));
THROW(TypeError);
}
new_st = convert_to_bytes(st_arg2);
sttype_test_set2_args(st_node, st_arg1, new_st);
}
check_function(dfw, st_arg2);
}
else if (type2 == STTYPE_SET) {
dfilter_fail(dfw, "Only a field may be tested for membership in a set.");
THROW(TypeError);
}
else {
g_assert_not_reached();
}
}
static stnode_t*
check_param_entity(dfwork_t *dfw, stnode_t *st_node)
{
sttype_id_t e_type;
stnode_t *new_st;
fvalue_t *fvalue;
char *s;
e_type = stnode_type_id(st_node);
if (e_type == STTYPE_UNPARSED || e_type == STTYPE_CHARCONST) {
s = (char*)stnode_data(st_node);
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_STRING, s, FALSE);
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
check_relation_LHS_FUNCTION(dfwork_t *dfw, const char *relation_string,
FtypeCanFunc can_func,
gboolean allow_partial_value,
stnode_t *st_node, stnode_t *st_arg1, stnode_t *st_arg2)
{
stnode_t *new_st;
sttype_id_t type2;
header_field_info *hfinfo2;
ftenum_t ftype1, ftype2;
fvalue_t *fvalue;
char *s;
df_func_def_t *funcdef;
df_func_def_t *funcdef2;
check_function(dfw, st_arg1);
type2 = stnode_type_id(st_arg2);
funcdef = sttype_function_funcdef(st_arg1);
ftype1 = funcdef->retval_ftype;
sttype_function_params(st_arg1);
DebugLog((" 5 check_relation_LHS_FUNCTION(%s)\n", relation_string));
if (!can_func(ftype1)) {
dfilter_fail(dfw, "Function %s (type=%s) cannot participate in '%s' comparison.",
funcdef->name, ftype_pretty_name(ftype1),
relation_string);
THROW(TypeError);
}
if (type2 == STTYPE_FIELD) {
hfinfo2 = (header_field_info*)stnode_data(st_arg2);
ftype2 = hfinfo2->type;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail(dfw, "Function %s and %s are not of compatible types.",
funcdef->name, hfinfo2->abbrev);
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail(dfw, "%s (type=%s) cannot participate in specified comparison.",
hfinfo2->abbrev, ftype_pretty_name(ftype2));
THROW(TypeError);
}
}
else if (type2 == STTYPE_STRING) {
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = dfilter_fvalue_from_string(dfw, FT_PCRE, s);
} else {
fvalue = dfilter_fvalue_from_string(dfw, ftype1, s);
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_UNPARSED || type2 == STTYPE_CHARCONST) {
s = (char*)stnode_data(st_arg2);
if (strcmp(relation_string, "matches") == 0) {
fvalue = dfilter_fvalue_from_unparsed(dfw, FT_PCRE, s, FALSE);
} else {
fvalue = dfilter_fvalue_from_unparsed(dfw, ftype1, s, allow_partial_value);
}
if (!fvalue) {
THROW(TypeError);
}
new_st = stnode_new(STTYPE_FVALUE, fvalue);
sttype_test_set2_args(st_node, st_arg1, new_st);
stnode_free(st_arg2);
}
else if (type2 == STTYPE_RANGE) {
check_drange_sanity(dfw, st_arg2);
if (!is_bytes_type(ftype1)) {
if (!ftype_can_slice(ftype1)) {
dfilter_fail(dfw, "Function \"%s\" is a %s and cannot be converted into a sequence of bytes.",
funcdef->name,
ftype_pretty_name(ftype1));
THROW(TypeError);
}
new_st = convert_to_bytes(st_arg1);
sttype_test_set2_args(st_node, new_st, st_arg2);
}
}
else if (type2 == STTYPE_FUNCTION) {
funcdef2 = sttype_function_funcdef(st_arg2);
ftype2 = funcdef2->retval_ftype;
if (!compatible_ftypes(ftype1, ftype2)) {
dfilter_fail(dfw, "Return values of function %s (type=%s) and function %s (type=%s) are not of compatible types.",
funcdef->name, ftype_pretty_name(ftype1), funcdef2->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
if (!can_func(ftype2)) {
dfilter_fail(dfw, "Return value of %s (type=%s) cannot participate in specified comparison.",
funcdef2->name, ftype_pretty_name(ftype2));
THROW(TypeError);
}
check_function(dfw, st_arg2);
}
else if (type2 == STTYPE_SET) {
dfilter_fail(dfw, "Only a field may be tested for membership in a set.");
THROW(TypeError);
}
else {
g_assert_not_reached();
}
}
static void
check_relation(dfwork_t *dfw, const char *relation_string,
gboolean allow_partial_value,
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
dfilter_fail(dfw, "Protocol (\"%s\") cannot appear on right-hand side of comparison.", hfinfo->abbrev);
THROW(TypeError);
}
}
switch (stnode_type_id(st_arg1)) {
case STTYPE_FIELD:
check_relation_LHS_FIELD(dfw, relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_STRING:
check_relation_LHS_STRING(dfw, relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_RANGE:
check_relation_LHS_RANGE(dfw, relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_UNPARSED:
case STTYPE_CHARCONST:
check_relation_LHS_UNPARSED(dfw, relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_FUNCTION:
check_relation_LHS_FUNCTION(dfw, relation_string, can_func,
allow_partial_value, st_node, st_arg1, st_arg2);
break;
case STTYPE_UNINITIALIZED:
case STTYPE_TEST:
case STTYPE_INTEGER:
case STTYPE_FVALUE:
case STTYPE_SET:
default:
g_assert_not_reached();
}
}
static void
check_test(dfwork_t *dfw, stnode_t *st_node, GPtrArray *deprecated)
{
test_op_t st_op, st_arg_op;
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
check_exists(dfw, st_arg1);
break;
case TEST_OP_NOT:
semcheck(dfw, st_arg1, deprecated);
break;
case TEST_OP_AND:
case TEST_OP_OR:
if (stnode_type_id(st_arg1) == STTYPE_TEST) {
sttype_test_get(st_arg1, &st_arg_op, NULL, NULL);
if (st_arg_op == TEST_OP_AND || st_arg_op == TEST_OP_OR) {
if (st_op != st_arg_op && !st_arg1->inside_brackets)
g_ptr_array_add(deprecated, g_strdup("suggest parentheses around '&&' within '||'"));
}
}
if (stnode_type_id(st_arg2) == STTYPE_TEST) {
sttype_test_get(st_arg2, &st_arg_op, NULL, NULL);
if (st_arg_op == TEST_OP_AND || st_arg_op == TEST_OP_OR) {
if (st_op != st_arg_op && !st_arg2->inside_brackets)
g_ptr_array_add(deprecated, g_strdup("suggest parentheses around '&&' within '||'"));
}
}
semcheck(dfw, st_arg1, deprecated);
semcheck(dfw, st_arg2, deprecated);
break;
case TEST_OP_EQ:
check_relation(dfw, "==", FALSE, ftype_can_eq, st_node, st_arg1, st_arg2);
break;
case TEST_OP_NE:
check_relation(dfw, "!=", FALSE, ftype_can_ne, st_node, st_arg1, st_arg2);
break;
case TEST_OP_GT:
check_relation(dfw, ">", FALSE, ftype_can_gt, st_node, st_arg1, st_arg2);
break;
case TEST_OP_GE:
check_relation(dfw, ">=", FALSE, ftype_can_ge, st_node, st_arg1, st_arg2);
break;
case TEST_OP_LT:
check_relation(dfw, "<", FALSE, ftype_can_lt, st_node, st_arg1, st_arg2);
break;
case TEST_OP_LE:
check_relation(dfw, "<=", FALSE, ftype_can_le, st_node, st_arg1, st_arg2);
break;
case TEST_OP_BITWISE_AND:
check_relation(dfw, "&", FALSE, ftype_can_bitwise_and, st_node, st_arg1, st_arg2);
break;
case TEST_OP_CONTAINS:
check_relation(dfw, "contains", TRUE, ftype_can_contains, st_node, st_arg1, st_arg2);
break;
case TEST_OP_MATCHES:
check_relation(dfw, "matches", TRUE, ftype_can_matches, st_node, st_arg1, st_arg2);
break;
case TEST_OP_IN:
check_relation(dfw, "in", FALSE, ftype_can_eq, st_node, st_arg1, st_arg2);
break;
default:
g_assert_not_reached();
}
DebugLog((" 3 check_test(stnode_t *st_node = %p) [%u] - End\n", st_node, i++));
}
static void
semcheck(dfwork_t *dfw, stnode_t *st_node, GPtrArray *deprecated)
{
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog((" 2 semcheck(stnode_t *st_node = %p) [%u]\n", st_node, i++));
switch (stnode_type_id(st_node)) {
case STTYPE_TEST:
check_test(dfw, st_node, deprecated);
break;
default:
g_assert_not_reached();
}
}
gboolean
dfw_semcheck(dfwork_t *dfw, GPtrArray *deprecated)
{
volatile gboolean ok_filter = TRUE;
#ifdef DEBUG_dfilter
static guint i = 0;
#endif
DebugLog(("1 dfw_semcheck(dfwork_t *dfw = %p) [%u]\n", dfw, i));
TRY {
semcheck(dfw, dfw->st_root, deprecated);
}
CATCH(TypeError) {
ok_filter = FALSE;
}
ENDTRY;
DebugLog(("1 dfw_semcheck(dfwork_t *dfw = %p) [%u] - Returns %d\n",
dfw, i++,ok_filter));
return ok_filter;
}
