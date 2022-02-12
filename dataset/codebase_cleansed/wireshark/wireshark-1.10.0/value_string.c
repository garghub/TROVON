const gchar*
val_to_str(const guint32 val, const value_string *vs, const char *fmt)
{
const gchar *ret;
DISSECTOR_ASSERT(fmt != NULL);
ret = try_val_to_str(val, vs);
if (ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar*
val_to_str_const(const guint32 val, const value_string *vs,
const char *unknown_str)
{
const gchar *ret;
DISSECTOR_ASSERT(unknown_str != NULL);
ret = try_val_to_str(val, vs);
if (ret != NULL)
return ret;
return unknown_str;
}
const gchar*
try_val_to_str_idx(const guint32 val, const value_string *vs, gint *idx)
{
gint i = 0;
DISSECTOR_ASSERT(idx != NULL);
if(vs) {
while (vs[i].strptr) {
if (vs[i].value == val) {
*idx = i;
return(vs[i].strptr);
}
i++;
}
}
*idx = -1;
return NULL;
}
const gchar*
try_val_to_str(const guint32 val, const value_string *vs)
{
gint ignore_me;
return try_val_to_str_idx(val, vs, &ignore_me);
}
guint32
str_to_val(const gchar *val, const value_string *vs, const guint32 err_val)
{
gint i;
i = str_to_val_idx(val, vs);
if (i >= 0) {
return vs[i].value;
}
return err_val;
}
gint
str_to_val_idx(const gchar *val, const value_string *vs)
{
gint i = 0;
if(vs) {
while (vs[i].strptr) {
if (strcmp(vs[i].strptr, val) == 0) {
return i;
}
i++;
}
}
return -1;
}
value_string_ext *
value_string_ext_new(value_string *vs, guint vs_tot_num_entries,
const gchar *vs_name)
{
value_string_ext *vse;
DISSECTOR_ASSERT (vs_name != NULL);
DISSECTOR_ASSERT (vs_tot_num_entries > 0);
DISSECTOR_ASSERT (vs[vs_tot_num_entries-1].strptr == NULL);
vse = g_new(value_string_ext, 1);
vse->_vs_p = vs;
vse->_vs_num_entries = vs_tot_num_entries - 1;
vse->_vs_first_value = 0;
vse->_vs_match2 = _try_val_to_str_ext_init;
vse->_vs_name = vs_name;
return vse;
}
const gchar*
try_val_to_str_ext(const guint32 val, const value_string_ext *vse)
{
if (vse) {
const value_string *vs = vse->_vs_match2(val, vse);
if (vs) {
return vs->strptr;
}
}
return NULL;
}
const gchar*
try_val_to_str_idx_ext(const guint32 val, value_string_ext *vse, gint *idx)
{
if (vse) {
const value_string *vs = vse->_vs_match2(val, vse);
if (vs) {
*idx = (gint) (vs - vse->_vs_p);
return vs->strptr;
}
}
*idx = -1;
return NULL;
}
const gchar*
val_to_str_ext(const guint32 val, const value_string_ext *vse, const char *fmt)
{
const gchar *ret;
DISSECTOR_ASSERT(fmt != NULL);
ret = try_val_to_str_ext(val, vse);
if (ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar*
val_to_str_ext_const(const guint32 val, const value_string_ext *vse,
const char *unknown_str)
{
const gchar *ret;
DISSECTOR_ASSERT(unknown_str != NULL);
ret = try_val_to_str_ext(val, vse);
if (ret != NULL)
return ret;
return unknown_str;
}
static const value_string *
_try_val_to_str_linear(const guint32 val, const value_string_ext *vse)
{
const value_string *vs_p = vse->_vs_p;
guint i;
for (i=0; i<vse->_vs_num_entries; i++) {
if (vs_p[i].value == val)
return &(vs_p[i]);
}
return NULL;
}
static const value_string *
_try_val_to_str_index(const guint32 val, const value_string_ext *vse)
{
guint i;
i = val - vse->_vs_first_value;
if (i < vse->_vs_num_entries) {
g_assert (val == vse->_vs_p[i].value);
return &(vse->_vs_p[i]);
}
return NULL;
}
static const value_string *
_try_val_to_str_bsearch(const guint32 val, const value_string_ext *vse)
{
guint low, i, max;
guint32 item;
for (low = 0, max = vse->_vs_num_entries; low < max; ) {
i = (low + max) / 2;
item = vse->_vs_p[i].value;
if (val < item)
max = i;
else if (val > item)
low = i + 1;
else
return &(vse->_vs_p[i]);
}
return NULL;
}
const value_string *
_try_val_to_str_ext_init(const guint32 val, const value_string_ext *a_vse)
{
value_string_ext *vse = (value_string_ext *)a_vse;
const value_string *vs_p = vse->_vs_p;
const guint vs_num_entries = vse->_vs_num_entries;
enum { VS_SEARCH, VS_BIN_TREE, VS_INDEX } type = VS_INDEX;
guint32 prev_value;
guint first_value;
guint i;
DISSECTOR_ASSERT((vs_p[vs_num_entries].value == 0) &&
(vs_p[vs_num_entries].strptr == NULL));
vse->_vs_first_value = vs_p[0].value;
first_value = vs_p[0].value;
prev_value = first_value;
for (i = 0; i < vs_num_entries; i++) {
DISSECTOR_ASSERT(vs_p[i].strptr != NULL);
if ((type == VS_INDEX) && (vs_p[i].value != (i + first_value))) {
type = VS_BIN_TREE;
}
if (type == VS_BIN_TREE) {
if (prev_value > vs_p[i].value) {
g_warning("Extended value string %s forced to fall back to linear search: entry %u, value %u < previous entry, value %u",
vse->_vs_name, i, vs_p[i].value, prev_value);
type = VS_SEARCH;
break;
}
if (first_value > vs_p[i].value) {
g_warning("Extended value string %s forced to fall back to linear search: entry %u, value %u < first entry, value %u",
vse->_vs_name, i, vs_p[i].value, first_value);
type = VS_SEARCH;
break;
}
}
prev_value = vs_p[i].value;
}
switch (type) {
case VS_SEARCH:
vse->_vs_match2 = _try_val_to_str_linear;
break;
case VS_BIN_TREE:
vse->_vs_match2 = _try_val_to_str_bsearch;
break;
case VS_INDEX:
vse->_vs_match2 = _try_val_to_str_index;
break;
default:
g_assert_not_reached();
break;
}
return vse->_vs_match2(val, vse);
}
const gchar*
str_to_str(const gchar *val, const string_string *vs, const char *fmt)
{
const gchar *ret;
DISSECTOR_ASSERT(fmt != NULL);
ret = try_str_to_str(val, vs);
if (ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar*
try_str_to_str_idx(const gchar *val, const string_string *vs, gint *idx)
{
gint i = 0;
if(vs) {
while (vs[i].strptr) {
if (!strcmp(vs[i].value,val)) {
*idx = i;
return(vs[i].strptr);
}
i++;
}
}
*idx = -1;
return NULL;
}
const gchar*
try_str_to_str(const gchar *val, const string_string *vs)
{
gint ignore_me;
return try_str_to_str_idx(val, vs, &ignore_me);
}
const gchar *
rval_to_str(const guint32 val, const range_string *rs, const char *fmt)
{
const gchar *ret = NULL;
DISSECTOR_ASSERT(fmt != NULL);
ret = try_rval_to_str(val, rs);
if(ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar *
try_rval_to_str_idx(const guint32 val, const range_string *rs, gint *idx)
{
gint i = 0;
if(rs) {
while(rs[i].strptr) {
if( (val >= rs[i].value_min) && (val <= rs[i].value_max) ) {
*idx = i;
return (rs[i].strptr);
}
i++;
}
}
*idx = -1;
return NULL;
}
const gchar *
try_rval_to_str(const guint32 val, const range_string *rs)
{
gint ignore_me = 0;
return try_rval_to_str_idx(val, rs, &ignore_me);
}
gboolean
value_string_ext_validate(const value_string_ext *vse)
{
if (vse == NULL)
return FALSE;
if ((vse->_vs_match2 == _try_val_to_str_ext_init) ||
(vse->_vs_match2 == _try_val_to_str_linear) ||
(vse->_vs_match2 == _try_val_to_str_bsearch) ||
(vse->_vs_match2 == _try_val_to_str_index))
return TRUE;
return FALSE;
}
const gchar *
value_string_ext_match_type_str(const value_string_ext *vse)
{
if (vse->_vs_match2 == _try_val_to_str_linear)
return "[Linear Search]";
if (vse->_vs_match2 == _try_val_to_str_bsearch)
return "[Binary Search]";
if (vse->_vs_match2 == _try_val_to_str_index)
return "[Direct (indexed) Access]";
return "[Match Type not initialized or invalid]";
}
