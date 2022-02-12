const gchar *
col_format_to_string(const gint fmt) {
const gchar *slist[] = {
"%q",
"%Yt",
"%At",
"%c",
"%Xd",
"%Xs",
"%V",
"%B",
"%Cus",
"%y",
"%z",
"%Tt",
"%dct",
"%Gt",
"%rd",
"%ud",
"%rD",
"%uD",
"%d",
"%D",
"%a",
"%I",
"%XO",
"%XR",
"%C",
"%F",
"%l",
"%P",
"%H",
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
"%U",
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
"%rct",
"%s",
"%S",
"%rs",
"%us",
"%rS",
"%uS",
"%E",
"%Yut",
"%Aut",
"%t"
};
if (fmt < 0 || fmt >= NUM_COL_FMTS)
return NULL;
return(slist[fmt]);
}
const gchar *
col_format_desc(const gint fmt) {
g_assert((fmt >= 0) && (fmt < NUM_COL_FMTS));
return(dlist[fmt]);
}
void
get_column_format_matches(gboolean *fmt_list, const gint format) {
if ((format >= 0) && (format < NUM_COL_FMTS))
fmt_list[format] = TRUE;
switch (format) {
case COL_DEF_SRC:
fmt_list[COL_RES_DL_SRC] = TRUE;
fmt_list[COL_RES_NET_SRC] = TRUE;
break;
case COL_RES_SRC:
fmt_list[COL_RES_DL_SRC] = TRUE;
fmt_list[COL_RES_NET_SRC] = TRUE;
break;
case COL_UNRES_SRC:
fmt_list[COL_UNRES_DL_SRC] = TRUE;
fmt_list[COL_UNRES_NET_SRC] = TRUE;
break;
case COL_DEF_DST:
fmt_list[COL_RES_DL_DST] = TRUE;
fmt_list[COL_RES_NET_DST] = TRUE;
break;
case COL_RES_DST:
fmt_list[COL_RES_DL_DST] = TRUE;
fmt_list[COL_RES_NET_DST] = TRUE;
break;
case COL_UNRES_DST:
fmt_list[COL_UNRES_DL_DST] = TRUE;
fmt_list[COL_UNRES_NET_DST] = TRUE;
break;
case COL_DEF_DL_SRC:
fmt_list[COL_RES_DL_SRC] = TRUE;
break;
case COL_DEF_DL_DST:
fmt_list[COL_RES_DL_DST] = TRUE;
break;
case COL_DEF_NET_SRC:
fmt_list[COL_RES_NET_SRC] = TRUE;
break;
case COL_DEF_NET_DST:
fmt_list[COL_RES_NET_DST] = TRUE;
break;
case COL_DEF_SRC_PORT:
fmt_list[COL_RES_SRC_PORT] = TRUE;
break;
case COL_DEF_DST_PORT:
fmt_list[COL_RES_DST_PORT] = TRUE;
break;
default:
break;
}
}
static const char *
get_timestamp_column_longest_string(const gint type, const gint precision)
{
switch(type) {
case(TS_ABSOLUTE_WITH_DATE):
case(TS_UTC_WITH_DATE):
switch(precision) {
case(TS_PREC_AUTO_SEC):
case(TS_PREC_FIXED_SEC):
return "0000-00-00 00:00:00";
break;
case(TS_PREC_AUTO_DSEC):
case(TS_PREC_FIXED_DSEC):
return "0000-00-00 00:00:00.0";
break;
case(TS_PREC_AUTO_CSEC):
case(TS_PREC_FIXED_CSEC):
return "0000-00-00 00:00:00.00";
break;
case(TS_PREC_AUTO_MSEC):
case(TS_PREC_FIXED_MSEC):
return "0000-00-00 00:00:00.000";
break;
case(TS_PREC_AUTO_USEC):
case(TS_PREC_FIXED_USEC):
return "0000-00-00 00:00:00.000000";
break;
case(TS_PREC_AUTO_NSEC):
case(TS_PREC_FIXED_NSEC):
return "0000-00-00 00:00:00.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_ABSOLUTE):
case(TS_UTC):
switch(precision) {
case(TS_PREC_AUTO_SEC):
case(TS_PREC_FIXED_SEC):
return "00:00:00";
break;
case(TS_PREC_AUTO_DSEC):
case(TS_PREC_FIXED_DSEC):
return "00:00:00.0";
break;
case(TS_PREC_AUTO_CSEC):
case(TS_PREC_FIXED_CSEC):
return "00:00:00.00";
break;
case(TS_PREC_AUTO_MSEC):
case(TS_PREC_FIXED_MSEC):
return "00:00:00.000";
break;
case(TS_PREC_AUTO_USEC):
case(TS_PREC_FIXED_USEC):
return "00:00:00.000000";
break;
case(TS_PREC_AUTO_NSEC):
case(TS_PREC_FIXED_NSEC):
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
case(TS_PREC_AUTO_SEC):
case(TS_PREC_FIXED_SEC):
return "0000";
break;
case(TS_PREC_AUTO_DSEC):
case(TS_PREC_FIXED_DSEC):
return "0000.0";
break;
case(TS_PREC_AUTO_CSEC):
case(TS_PREC_FIXED_CSEC):
return "0000.00";
break;
case(TS_PREC_AUTO_MSEC):
case(TS_PREC_FIXED_MSEC):
return "0000.000";
break;
case(TS_PREC_AUTO_USEC):
case(TS_PREC_FIXED_USEC):
return "0000.000000";
break;
case(TS_PREC_AUTO_NSEC):
case(TS_PREC_FIXED_NSEC):
return "0000.000000000";
break;
default:
g_assert_not_reached();
}
break;
case(TS_EPOCH):
switch(precision) {
case(TS_PREC_AUTO_SEC):
case(TS_PREC_FIXED_SEC):
return "0000000000000000000";
break;
case(TS_PREC_AUTO_DSEC):
case(TS_PREC_FIXED_DSEC):
return "0000000000000000000.0";
break;
case(TS_PREC_AUTO_CSEC):
case(TS_PREC_FIXED_CSEC):
return "0000000000000000000.00";
break;
case(TS_PREC_AUTO_MSEC):
case(TS_PREC_FIXED_MSEC):
return "0000000000000000000.000";
break;
case(TS_PREC_AUTO_USEC):
case(TS_PREC_FIXED_USEC):
return "0000000000000000000.000000";
break;
case(TS_PREC_AUTO_NSEC):
case(TS_PREC_FIXED_NSEC):
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
const gchar *
get_column_width_string(const gint format, const gint col)
{
if(strlen(get_column_longest_string(format)) >
strlen(get_column_title(col)))
return get_column_longest_string(format);
else
return get_column_title(col);
}
const char *
get_column_longest_string(const gint format)
{
switch (format) {
case COL_NUMBER:
return "0000000";
break;
case COL_CLS_TIME:
return get_timestamp_column_longest_string(timestamp_get_type(), timestamp_get_precision());
break;
case COL_ABS_DATE_TIME:
return get_timestamp_column_longest_string(TS_ABSOLUTE_WITH_DATE, timestamp_get_precision());
break;
case COL_UTC_DATE_TIME:
return get_timestamp_column_longest_string(TS_UTC_WITH_DATE, timestamp_get_precision());
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
case COL_REL_CONV_TIME:
case COL_DELTA_CONV_TIME:
return get_timestamp_column_longest_string(TS_RELATIVE, timestamp_get_precision());
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
case COL_RXID:
case COL_OXID:
return "000000";
break;
case COL_IF_DIR:
return "i 00000000 I";
break;
case COL_CIRCUIT_ID:
return "000000";
break;
case COL_SRCIDX:
case COL_DSTIDX:
return "0000000";
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
case COL_HPUX_SUBSYS:
return "OTS9000-TRANSPORT";
break;
case COL_HPUX_DEVID:
return "0000";
break;
case COL_DCE_CALL:
return "0000";
break;
case COL_DCE_CTX:
return "0000";
break;
case COL_8021Q_VLAN_ID:
return "0000";
break;
case COL_DSCP_VALUE:
return "00";
break;
case COL_COS_VALUE:
return "0";
break;
case COL_TEI:
return "127";
break;
case COL_FR_DLCI:
return "8388608";
break;
case COL_BSSGP_TLLI:
return "0xffffffff";
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
get_column_custom_field(const gint col)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return NULL;
cfmt = (fmt_data *) clp->data;
return(cfmt->custom_field);
}
void
set_column_custom_field(const gint col, const char *custom_field)
{
GList *clp = g_list_nth(prefs.col_list, col);
fmt_data *cfmt;
if (!clp)
return;
cfmt = (fmt_data *) clp->data;
g_free (cfmt->custom_field);
cfmt->custom_field = g_strdup (custom_field);
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
void
build_column_format_array(column_info *cinfo, const gint num_cols, const gboolean reset_fences)
{
int i;
col_setup(cinfo, num_cols);
for (i = 0; i < cinfo->num_cols; i++) {
cinfo->col_fmt[i] = get_column_format(i);
cinfo->col_title[i] = g_strdup(get_column_title(i));
if (cinfo->col_fmt[i] == COL_CUSTOM) {
cinfo->col_custom_field[i] = g_strdup(get_column_custom_field(i));
cinfo->col_custom_occurrence[i] = get_column_custom_occurrence(i);
if(!dfilter_compile(cinfo->col_custom_field[i], &cinfo->col_custom_dfilter[i])) {
g_free(cinfo->col_custom_field[i]);
cinfo->col_custom_field[i] = NULL;
cinfo->col_custom_occurrence[i] = 0;
cinfo->col_custom_dfilter[i] = NULL;
}
} else {
cinfo->col_custom_field[i] = NULL;
cinfo->col_custom_occurrence[i] = 0;
cinfo->col_custom_dfilter[i] = NULL;
}
cinfo->fmt_matx[i] = (gboolean *) g_malloc0(sizeof(gboolean) * NUM_COL_FMTS);
get_column_format_matches(cinfo->fmt_matx[i], cinfo->col_fmt[i]);
cinfo->col_data[i] = NULL;
if (cinfo->col_fmt[i] == COL_INFO)
cinfo->col_buf[i] = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_INFO_LEN);
else
cinfo->col_buf[i] = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
if(reset_fences)
cinfo->col_fence[i] = 0;
cinfo->col_expr.col_expr[i] = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
cinfo->col_expr.col_expr_val[i] = (gchar *) g_malloc(sizeof(gchar) * COL_MAX_LEN);
}
cinfo->col_expr.col_expr[i] = NULL;
cinfo->col_expr.col_expr_val[i] = NULL;
for (i = 0; i < cinfo->num_cols; i++) {
int j;
for (j = 0; j < NUM_COL_FMTS; j++) {
if (!cinfo->fmt_matx[i][j])
continue;
if (cinfo->col_first[j] == -1)
cinfo->col_first[j] = i;
cinfo->col_last[j] = i;
}
}
}
