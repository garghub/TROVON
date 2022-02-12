const gchar *
col_format_to_string(const gint fmt) {
static const gchar *const slist[NUM_COL_FMTS] = {
"%q",
"%Yt",
"%YDOYt",
"%At",
"%V",
"%B",
"%Cus",
"%y",
"%Tt",
"%Gt",
"%rd",
"%ud",
"%rD",
"%uD",
"%d",
"%D",
"%a",
"%I",
"%F",
"%hd",
"%hs",
"%rhd",
"%uhd",
"%rhs",
"%uhs",
"%e",
"%x",
"%f",
"%i",
"%rnd",
"%und",
"%rns",
"%uns",
"%nd",
"%ns",
"%m",
"%L",
"%p",
"%Rt",
"%s",
"%S",
"%rs",
"%us",
"%rS",
"%uS",
"%E",
"%Yut",
"%YDOYut",
"%Aut",
"%t"
};
if (fmt < 0 || fmt >= NUM_COL_FMTS)
return NULL;
return(slist[fmt]);
}
const gchar *
col_format_desc(const gint fmt) {
static const gchar *const dlist[NUM_COL_FMTS] = {
"802.1Q VLAN id",
"Absolute date, as YYYY-MM-DD, and time",
"Absolute date, as YYYY/DOY, and time",
"Absolute time",
"Cisco VSAN",
"Cumulative Bytes" ,
"Custom",
"DCE/RPC call (cn_call_id / dg_seqnum)",
"Delta time",
"Delta time displayed",
"Dest addr (resolved)",
"Dest addr (unresolved)",
"Dest port (resolved)",
"Dest port (unresolved)",
"Destination address",
"Destination port",
"Expert Info Severity",
"FW-1 monitor if/direction",
"Frequency/Channel",
"Hardware dest addr",
"Hardware src addr",
"Hw dest addr (resolved)",
"Hw dest addr (unresolved)",
"Hw src addr (resolved)",
"Hw src addr (unresolved)",
"IEEE 802.11 RSSI",
"IEEE 802.11 TX rate",
"IP DSCP Value",
"Information",
"Net dest addr (resolved)",
"Net dest addr (unresolved)",
"Net src addr (resolved)",
"Net src addr (unresolved)",
"Network dest addr",
"Network src addr",
"Number",
"Packet length (bytes)" ,
"Protocol",
"Relative time",
"Source address",
"Source port",
"Src addr (resolved)",
"Src addr (unresolved)",
"Src port (resolved)",
"Src port (unresolved)",
"TEI",
"UTC date, as YYYY-MM-DD, and time",
"UTC date, as YYYY/DOY, and time",
"UTC time",
"Time (format as specified)"
};
g_assert((fmt >= 0) && (fmt < NUM_COL_FMTS));
return(dlist[fmt]);
}
void
column_dump_column_formats(void)
{
gint fmt;
for (fmt = 0; fmt < NUM_COL_FMTS; fmt++) {
ws_debug_printf("%s\t%s\n", col_format_to_string(fmt), col_format_desc(fmt));
}
ws_debug_printf("\nFor example, to print Wireshark's default columns with tshark:\n\n"
#ifdef _WIN32
"tshark.exe -o \"gui.column.format:"
"\\\"No.\\\",\\\"%%m\\\","
"\\\"Time\\\",\\\"%%t\\\","
"\\\"Source\\\",\\\"%%s\\\","
"\\\"Destination\\\",\\\"%%d\\\","
"\\\"Protocol\\\",\\\"%%p\\\","
"\\\"Length\\\",\\\"%%L\\\","
"\\\"Info\\\",\\\"%%i\\\"\"\n");
#else
"tshark -o 'gui.column.format:"
"\"No.\",\"%%m\","
"\"Time\",\"%%t\","
"\"Source\",\"%%s\","
"\"Destination\",\"%%d\","
"\"Protocol\",\"%%p\","
"\"Length\",\"%%L\","
"\"Info\",\"%%i\"'\n");
static const char *
get_timestamp_column_longest_string(const gint type, const gint precision)
{
switch(type) {
case(TS_ABSOLUTE_WITH_YMD):
case(TS_UTC_WITH_YMD):
switch(precision) {
case(TS_PREC_FIXED_SEC):
return "0000-00-00 00:00:00";
break;
case(TS_PREC_FIXED_DSEC):
return "0000-00-00 00:00:00.0";
break;
case(TS_PREC_FIXED_CSEC):
return "0000-00-00 00:00:00.00";
break;
case(TS_PREC_FIXED_MSEC):
return "0000-00-00 00:00:00.000";
break;
case(TS_PREC_FIXED_USEC):
return "0000-00-00 00:00:00.000000";
break;
case(TS_PREC_FIXED_NSEC):
case(TS_PREC_AUTO):
return "0000-00-00 00:00:00.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_ABSOLUTE_WITH_YDOY):
case(TS_UTC_WITH_YDOY):
switch(precision) {
case(TS_PREC_FIXED_SEC):
return "0000/000 00:00:00";
break;
case(TS_PREC_FIXED_DSEC):
return "0000/000 00:00:00.0";
break;
case(TS_PREC_FIXED_CSEC):
return "0000/000 00:00:00.00";
break;
case(TS_PREC_FIXED_MSEC):
return "0000/000 00:00:00.000";
break;
case(TS_PREC_FIXED_USEC):
return "0000/000 00:00:00.000000";
break;
case(TS_PREC_FIXED_NSEC):
case(TS_PREC_AUTO):
return "0000/000 00:00:00.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_ABSOLUTE):
case(TS_UTC):
switch(precision) {
case(TS_PREC_FIXED_SEC):
return "00:00:00";
break;
case(TS_PREC_FIXED_DSEC):
return "00:00:00.0";
break;
case(TS_PREC_FIXED_CSEC):
return "00:00:00.00";
break;
case(TS_PREC_FIXED_MSEC):
return "00:00:00.000";
break;
case(TS_PREC_FIXED_USEC):
return "00:00:00.000000";
break;
case(TS_PREC_FIXED_NSEC):
case(TS_PREC_AUTO):
return "00:00:00.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_RELATIVE):
case(TS_DELTA):
case(TS_DELTA_DIS):
switch(precision) {
case(TS_PREC_FIXED_SEC):
return "0000";
break;
case(TS_PREC_FIXED_DSEC):
return "0000.0";
break;
case(TS_PREC_FIXED_CSEC):
return "0000.00";
break;
case(TS_PREC_FIXED_MSEC):
return "0000.000";
break;
case(TS_PREC_FIXED_USEC):
return "0000.000000";
break;
case(TS_PREC_FIXED_NSEC):
case(TS_PREC_AUTO):
return "0000.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_EPOCH):
switch(precision) {
case(TS_PREC_FIXED_SEC):
return "0000000000000000000";
break;
case(TS_PREC_FIXED_DSEC):
return "0000000000000000000.0";
break;
case(TS_PREC_FIXED_CSEC):
return "0000000000000000000.00";
break;
case(TS_PREC_FIXED_MSEC):
return "0000000000000000000.000";
break;
case(TS_PREC_FIXED_USEC):
return "0000000000000000000.000000";
break;
case(TS_PREC_FIXED_NSEC):
case(TS_PREC_AUTO):
return "0000000000000000000.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_NOT_SET):
return "0000.000000";
break;
default:
g_assert_not_reached();
}
return "";
}
static const char *
get_column_longest_string(const gint format)
{
switch (format) {
case COL_NUMBER:
return "0000000";
break;
case COL_CLS_TIME:
return get_timestamp_column_longest_string(timestamp_get_type(), timestamp_get_precision());
break;
case COL_ABS_YMD_TIME:
return get_timestamp_column_longest_string(TS_ABSOLUTE_WITH_YMD, timestamp_get_precision());
break;
case COL_ABS_YDOY_TIME:
return get_timestamp_column_longest_string(TS_ABSOLUTE_WITH_YDOY, timestamp_get_precision());
break;
case COL_UTC_YMD_TIME:
return get_timestamp_column_longest_string(TS_UTC_WITH_YMD, timestamp_get_precision());
break;
case COL_UTC_YDOY_TIME:
return get_timestamp_column_longest_string(TS_UTC_WITH_YDOY, timestamp_get_precision());
break;
case COL_ABS_TIME:
return get_timestamp_column_longest_string(TS_ABSOLUTE, timestamp_get_precision());
break;
case COL_UTC_TIME:
return get_timestamp_column_longest_string(TS_UTC, timestamp_get_precision());
break;
case COL_REL_TIME:
return get_timestamp_column_longest_string(TS_RELATIVE, timestamp_get_precision());
break;
case COL_DELTA_TIME:
return get_timestamp_column_longest_string(TS_DELTA, timestamp_get_precision());
break;
case COL_DELTA_TIME_DIS:
return get_timestamp_column_longest_string(TS_DELTA_DIS, timestamp_get_precision());
break;
case COL_DEF_SRC:
case COL_RES_SRC:
case COL_UNRES_SRC:
case COL_DEF_DL_SRC:
case COL_RES_DL_SRC:
case COL_UNRES_DL_SRC:
case COL_DEF_NET_SRC:
case COL_RES_NET_SRC:
case COL_UNRES_NET_SRC:
case COL_DEF_DST:
case COL_RES_DST:
case COL_UNRES_DST:
case COL_DEF_DL_DST:
case COL_RES_DL_DST:
case COL_UNRES_DL_DST:
case COL_DEF_NET_DST:
case COL_RES_NET_DST:
case COL_UNRES_NET_DST:
return "00000000.000000000000";
break;
case COL_DEF_SRC_PORT:
case COL_RES_SRC_PORT:
case COL_UNRES_SRC_PORT:
case COL_DEF_DST_PORT:
case COL_RES_DST_PORT:
case COL_UNRES_DST_PORT:
return "000000";
break;
case COL_PROTOCOL:
return "Protocol";
break;
case COL_PACKET_LENGTH:
return "00000";
break;
case COL_CUMULATIVE_BYTES:
return "00000000";
break;
case COL_IF_DIR:
return "i 00000000 I";
break;
case COL_VSAN:
return "000000";
break;
case COL_TX_RATE:
return "108.0";
break;
case COL_RSSI:
return "100";
break;
case COL_DCE_CALL:
return "0000";
break;
case COL_8021Q_VLAN_ID:
return "0000";
break;
case COL_DSCP_VALUE:
return "AAA BBB";
break;
case COL_TEI:
return "127";
break;
case COL_EXPERT:
return "ERROR";
break;
case COL_FREQ_CHAN:
return "9999 MHz [A 999]";
break;
case COL_CUSTOM:
return "0000000000";
break;
default:
return "Source port: kerberos-master Destination port: kerberos-master";
break;
}
}
const gchar *
get_column_width_string(const gint format, const gint col)
{
if(strlen(get_column_longest_string(format)) >
strlen(get_column_title(col)))
return get_column_longest_string(format);
else
return get_column_title(col);
}
gint
get_column_char_width(const gint format)
{
return (gint)strlen(get_column_longest_string(format));
}
gint
get_column_format(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return -1;
cfmt = (fmt_data *) clp->data;
return(cfmt->fmt);
}
void
set_column_format(const gint col, const gint fmt)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
cfmt->fmt = fmt;
}
gint
get_column_format_from_str(const gchar *str)
{
gint i;
for (i = 0; i < NUM_COL_FMTS; i++) {
if (strcmp(str, col_format_to_string(i)) == 0)
return i;
}
return -1;
}
gchar *
get_column_title(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return NULL;
cfmt = (fmt_data *) clp->data;
return(cfmt->title);
}
void
set_column_title(const gint col, const gchar *title)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
g_free (cfmt->title);
cfmt->title = g_strdup (title);
}
gboolean
get_column_visible(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return TRUE;
cfmt = (fmt_data *) clp->data;
return(cfmt->visible);
}
void
set_column_visible(const gint col, gboolean visible)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
cfmt->visible = visible;
}
gboolean
get_column_resolved(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return TRUE;
cfmt = (fmt_data *) clp->data;
return(cfmt->resolved);
}
void
set_column_resolved(const gint col, gboolean resolved)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
cfmt->resolved = resolved;
}
const gchar *
get_column_custom_fields(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return NULL;
cfmt = (fmt_data *) clp->data;
return(cfmt->custom_fields);
}
void
set_column_custom_fields(const gint col, const char *custom_fields)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
g_free (cfmt->custom_fields);
cfmt->custom_fields = g_strdup (custom_fields);
}
gint
get_column_custom_occurrence(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return 0;
cfmt = (fmt_data *) clp->data;
return(cfmt->custom_occurrence);
}
void
set_column_custom_occurrence(const gint col, const gint custom_occurrence)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
cfmt->custom_occurrence = custom_occurrence;
}
static gchar *
get_custom_field_tooltip (gchar *custom_field, gint occurrence)
{
header_field_info *hfi = proto_registrar_get_byname(custom_field);
if (hfi == NULL) {
return g_strdup_printf("Unknown Field: %s", custom_field);
}
if (hfi->parent == -1) {
return g_strdup_printf("%s (%s)", hfi->name, hfi->abbrev);
}
if (occurrence == 0) {
return g_strdup_printf("%s\n%s (%s)", proto_get_protocol_name(hfi->parent), hfi->name, hfi->abbrev);
}
return g_strdup_printf("%s\n%s (%s#%d)", proto_get_protocol_name(hfi->parent), hfi->name, hfi->abbrev, occurrence);
}
gchar *
get_column_tooltip(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
gchar **fields;
gboolean first = TRUE;
GString *column_tooltip;
guint i;
if (!clp)
return NULL;
cfmt = (fmt_data *) clp->data;
if (cfmt->fmt != COL_CUSTOM) {
return g_strdup(col_format_desc(cfmt->fmt));
}
fields = g_regex_split_simple(COL_CUSTOM_PRIME_REGEX, cfmt->custom_fields,
G_REGEX_ANCHORED, G_REGEX_MATCH_ANCHORED);
column_tooltip = g_string_new("");
for (i = 0; i < g_strv_length(fields); i++) {
if (fields[i] && *fields[i]) {
gchar *field_tooltip = get_custom_field_tooltip(fields[i], cfmt->custom_occurrence);
if (!first) {
g_string_append(column_tooltip, "\n\nOR\n\n");
}
g_string_append(column_tooltip, field_tooltip);
g_free (field_tooltip);
first = FALSE;
}
}
g_strfreev(fields);
return g_string_free (column_tooltip, FALSE);
}
void
build_column_format_array(column_info *cinfo, const gint num_cols, const gboolean reset_fences)
{
int i;
col_item_t* col_item;
col_setup(cinfo, num_cols);
for (i = 0; i < cinfo->num_cols; i++) {
col_item = &cinfo->columns[i];
col_item->col_fmt = get_column_format(i);
col_item->col_title = g_strdup(get_column_title(i));
if (col_item->col_fmt == COL_CUSTOM) {
col_item->col_custom_fields = g_strdup(get_column_custom_fields(i));
col_item->col_custom_occurrence = get_column_custom_occurrence(i);
if(!dfilter_compile(col_item->col_custom_fields, &col_item->col_custom_dfilter, NULL)) {
g_free(col_item->col_custom_fields);
col_item->col_custom_fields = NULL;
col_item->col_custom_occurrence = 0;
col_item->col_custom_dfilter = NULL;
}
if (col_item->col_custom_fields) {
gchar **fields = g_regex_split(cinfo->prime_regex, col_item->col_custom_fields,
G_REGEX_MATCH_ANCHORED);
guint i_field;
for (i_field = 0; i_field < g_strv_length(fields); i_field++) {
if (fields[i_field] && *fields[i_field]) {
header_field_info *hfinfo = proto_registrar_get_byname(fields[i_field]);
if (hfinfo) {
int *idx = g_new(int, 1);
*idx = hfinfo->id;
col_item->col_custom_fields_ids = g_slist_append(col_item->col_custom_fields_ids, idx);
}
}
}
g_strfreev(fields);
}
} else {
col_item->col_custom_fields = NULL;
col_item->col_custom_occurrence = 0;
col_item->col_custom_dfilter = NULL;
}
col_item->fmt_matx = (gboolean *) g_malloc0(sizeof(gboolean) * NUM_COL_FMTS);
get_column_format_matches(col_item->fmt_matx, col_item->col_fmt);
col_item->col_data = NULL;
if (col_item->col_fmt == COL_INFO)
col_item->col_buf = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_INFO_LEN);
else
col_item->col_buf = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
if(reset_fences)
col_item->col_fence = 0;
cinfo->col_expr.col_expr[i] = "";
cinfo->col_expr.col_expr_val[i] = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
}
cinfo->col_expr.col_expr[i] = NULL;
cinfo->col_expr.col_expr_val[i] = NULL;
for (i = 0; i < cinfo->num_cols; i++) {
int j;
for (j = 0; j < NUM_COL_FMTS; j++) {
if (!cinfo->columns[i].fmt_matx[j])
continue;
if (cinfo->col_first[j] == -1)
cinfo->col_first[j] = i;
cinfo->col_last[j] = i;
}
}
}
