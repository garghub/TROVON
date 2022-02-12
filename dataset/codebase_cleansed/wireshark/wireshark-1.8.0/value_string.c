const gchar*
val_to_str(const guint32 val, const value_string *vs, const char *fmt) {
const gchar *ret;
g_assert(fmt != NULL);
ret = match_strval(val, vs);
if (ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar*
val_to_str_const(const guint32 val, const value_string *vs, const char *unknown_str) {
const gchar *ret;
g_assert(unknown_str != NULL);
ret = match_strval(val, vs);
if (ret != NULL)
return ret;
return unknown_str;
}
const gchar*
match_strval_idx(const guint32 val, const value_string *vs, gint *idx) {
gint i = 0;
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
match_strval(const guint32 val, const value_string *vs) {
gint ignore_me;
return match_strval_idx(val, vs, &ignore_me);
}
value_string_ext *
value_string_ext_new(value_string *vs, guint vs_tot_num_entries, gchar *vs_name) {
value_string_ext *vse;
g_assert (vs_name != NULL);
g_assert (vs_tot_num_entries > 0);
g_assert (vs[vs_tot_num_entries-1].strptr == NULL);
vse = g_malloc(sizeof (value_string_ext));
vse->_vs_p = vs;
vse->_vs_num_entries = vs_tot_num_entries - 1;
vse->_vs_first_value = 0;
vse->_vs_match2 = _match_strval_ext_init;
vse->_vs_name = vs_name;
return vse;
}
const gchar*
match_strval_ext(const guint32 val, const value_string_ext *vse) {
if (vse) {
const value_string *vs = vse->_vs_match2(val, vse);
if (vs)
return vs->strptr;
}
return NULL;
}
const gchar*
match_strval_idx_ext(const guint32 val, value_string_ext *vse, gint *idx) {
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
val_to_str_ext(const guint32 val, const value_string_ext *vse, const char *fmt) {
const gchar *ret;
g_assert(fmt != NULL);
ret = match_strval_ext(val, vse);
if (ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar*
val_to_str_ext_const(const guint32 val, const value_string_ext *vse, const char *unknown_str) {
const gchar *ret;
g_assert(unknown_str != NULL);
ret = match_strval_ext(val, vse);
if (ret != NULL)
return ret;
return unknown_str;
}
static const value_string *
_match_strval_linear(const guint32 val, const value_string_ext *vse)
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
_match_strval_index(const guint32 val, const value_string_ext *vse)
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
_match_strval_bsearch(const guint32 val, const value_string_ext *vse)
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
_match_strval_ext_init(const guint32 val, const value_string_ext *a_vse)
{
value_string_ext *vse = (value_string_ext *)a_vse;
const value_string *vs_p = vse->_vs_p;
const guint vs_num_entries = vse->_vs_num_entries;
enum { VS_SEARCH = 0, VS_BIN_TREE, VS_INDEX } type = VS_INDEX;
guint32 prev_value;
guint first_value;
guint i;
g_assert((vs_p[vs_num_entries].value==0) && (vs_p[vs_num_entries].strptr==NULL));
vse->_vs_first_value = vs_p[0].value;
first_value = vs_p[0].value;
prev_value = first_value;
for (i = 0; i < vs_num_entries; i++) {
g_assert(vs_p[i].strptr != NULL);
if ((type == VS_INDEX) && (vs_p[i].value != (i + first_value))) {
type = VS_BIN_TREE;
}
if ((type == VS_BIN_TREE) && (prev_value > vs_p[i].value)) {
type = VS_SEARCH;
break;
}
prev_value = vs_p[i].value;
}
switch (type) {
case VS_SEARCH:
vse->_vs_match2 = _match_strval_linear;
break;
case VS_BIN_TREE:
vse->_vs_match2 = _match_strval_bsearch;
break;
case VS_INDEX:
vse->_vs_match2 = _match_strval_index;
break;
default:
g_assert_not_reached();
break;
}
return vse->_vs_match2(val, vse);
}
gboolean
value_string_ext_validate(const value_string_ext *vse) {
if (vse == NULL)
return FALSE;
if ((vse->_vs_match2 == _match_strval_ext_init) ||
(vse->_vs_match2 == _match_strval_linear) ||
(vse->_vs_match2 == _match_strval_bsearch) ||
(vse->_vs_match2 == _match_strval_index))
return TRUE;
return FALSE;
}
const gchar *
value_string_ext_match_type_str(const value_string_ext *vse) {
if (vse->_vs_match2 == _match_strval_linear)
return "[Linear Search]";
if (vse->_vs_match2 == _match_strval_bsearch)
return "[Binary Search]";
if (vse->_vs_match2 == _match_strval_index)
return "[Direct (indexed) Access]";
return "[Match Type not initialized or invalid]";
}
const gchar*
str_to_str(const gchar *val, const string_string *vs, const char *fmt) {
const gchar *ret;
g_assert(fmt != NULL);
ret = match_strstr(val, vs);
if (ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar*
match_strstr_idx(const gchar *val, const string_string *vs, gint *idx) {
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
match_strstr(const gchar *val, const string_string *vs) {
gint ignore_me;
return match_strstr_idx(val, vs, &ignore_me);
}
const char *
decode_enumerated_bitfield(const guint32 val, const guint32 mask, const int width,
const value_string *tab, const char *fmt)
{
static char buf[1025];
char *p;
p = decode_bitfield_value(buf, val, mask, width);
g_snprintf(p, (gulong) (1024-(p-buf)), fmt, val_to_str(val & mask, tab, "Unknown"));
return buf;
}
const char *
decode_enumerated_bitfield_shifted(const guint32 val, const guint32 mask, const int width,
const value_string *tab, const char *fmt)
{
static char buf[1025];
char *p;
int shift = 0;
while ((mask & (1<<shift)) == 0)
shift++;
p = decode_bitfield_value(buf, val, mask, width);
g_snprintf(p, (gulong) (1024-(p-buf)), fmt, val_to_str((val & mask) >> shift, tab, "Unknown"));
return buf;
}
const gchar *rval_to_str(const guint32 val, const range_string *rs, const char *fmt)
{
const gchar *ret = NULL;
g_assert(fmt != NULL);
ret = match_strrval(val, rs);
if(ret != NULL)
return ret;
return ep_strdup_printf(fmt, val);
}
const gchar *match_strrval_idx(const guint32 val, const range_string *rs, gint *idx)
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
const gchar *match_strrval(const guint32 val, const range_string *rs)
{
gint ignore_me = 0;
return match_strrval_idx(val, rs, &ignore_me);
}
