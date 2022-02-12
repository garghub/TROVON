void
col_setup(column_info *cinfo, const gint num_cols)
{
int i;
cinfo->num_cols = num_cols;
cinfo->col_fmt = g_new(gint, num_cols);
cinfo->fmt_matx = g_new(gboolean*, num_cols);
cinfo->col_first = g_new(int, NUM_COL_FMTS);
cinfo->col_last = g_new(int, NUM_COL_FMTS);
cinfo->col_title = g_new(gchar*, num_cols);
cinfo->col_custom_field = g_new(gchar*, num_cols);
cinfo->col_custom_occurrence = g_new(gint, num_cols);
cinfo->col_custom_field_id = g_new(int, num_cols);
cinfo->col_custom_dfilter = g_new(dfilter_t*, num_cols);
cinfo->col_data = (const gchar **)g_new(gchar*, num_cols);
cinfo->col_buf = g_new(gchar*, num_cols);
cinfo->col_fence = g_new(int, num_cols);
cinfo->col_expr.col_expr = (const gchar **) g_new(gchar*, num_cols + 1);
cinfo->col_expr.col_expr_val = g_new(gchar*, num_cols + 1);
for (i = 0; i < NUM_COL_FMTS; i++) {
cinfo->col_first[i] = -1;
cinfo->col_last[i] = -1;
}
}
void
col_cleanup(column_info *cinfo)
{
g_free(cinfo->col_fmt);
g_free(cinfo->fmt_matx);
g_free(cinfo->col_first);
g_free(cinfo->col_last);
g_free(cinfo->col_title);
g_free(cinfo->col_custom_field);
g_free(cinfo->col_custom_occurrence);
g_free(cinfo->col_custom_field_id);
g_free(cinfo->col_custom_dfilter);
g_free((gchar **)cinfo->col_data);
g_free(cinfo->col_buf);
g_free(cinfo->col_fence);
g_free((gchar **)cinfo->col_expr.col_expr);
g_free(cinfo->col_expr.col_expr_val);
}
void
col_init(column_info *cinfo)
{
int i;
if (!cinfo)
return;
for (i = 0; i < cinfo->num_cols; i++) {
cinfo->col_buf[i][0] = '\0';
cinfo->col_data[i] = cinfo->col_buf[i];
cinfo->col_fence[i] = 0;
cinfo->col_expr.col_expr[i] = "";
cinfo->col_expr.col_expr_val[i][0] = '\0';
}
cinfo->writable = TRUE;
}
gboolean
col_get_writable(column_info *cinfo)
{
return COL_GET_WRITABLE(cinfo);
}
void
col_set_writable(column_info *cinfo, const gboolean writable)
{
if (cinfo)
cinfo->writable = writable;
}
gint
check_col(column_info *cinfo, const gint el)
{
return CHECK_COL(cinfo, el);
}
void
col_set_fence(column_info *cinfo, const gint el)
{
int i;
if (!CHECK_COL(cinfo, el))
return;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
cinfo->col_fence[i] = (int)strlen(cinfo->col_data[i]);
}
}
}
const gchar *
col_get_text(column_info *cinfo, const gint el)
{
int i;
const gchar* text = NULL;
if (!(cinfo && (cinfo)->col_first[el] >= 0)) {
return NULL;
}
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
text = (cinfo->col_data[i]);
}
}
return text;
}
void
col_clear(column_info *cinfo, const gint el)
{
int i;
int fence;
if (!CHECK_COL(cinfo, el))
return;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
fence = cinfo->col_fence[i];
if (cinfo->col_buf[i] == cinfo->col_data[i] || fence == 0) {
cinfo->col_buf[i][fence] = '\0';
cinfo->col_data[i] = cinfo->col_buf[i];
}
cinfo->col_expr.col_expr[i] = "";
cinfo->col_expr.col_expr_val[i][0] = '\0';
}
}
}
gboolean
have_custom_cols(column_info *cinfo)
{
return HAVE_CUSTOM_COLS(cinfo);
}
void col_custom_set_edt(epan_dissect_t *edt, column_info *cinfo)
{
int i;
if(!HAVE_CUSTOM_COLS(cinfo))
return;
for (i = cinfo->col_first[COL_CUSTOM];
i <= cinfo->col_last[COL_CUSTOM]; i++) {
if (cinfo->fmt_matx[i][COL_CUSTOM] &&
cinfo->col_custom_field[i] &&
cinfo->col_custom_field_id[i] != -1) {
cinfo->col_data[i] = cinfo->col_buf[i];
cinfo->col_expr.col_expr[i] = epan_custom_set(edt, cinfo->col_custom_field_id[i],
cinfo->col_custom_occurrence[i],
cinfo->col_buf[i],
cinfo->col_expr.col_expr_val[i],
COL_MAX_LEN);
}
}
}
void
col_custom_prime_edt(epan_dissect_t *edt, column_info *cinfo)
{
int i;
if(!HAVE_CUSTOM_COLS(cinfo))
return;
for (i = cinfo->col_first[COL_CUSTOM];
i <= cinfo->col_last[COL_CUSTOM]; i++) {
cinfo->col_custom_field_id[i] = -1;
if (cinfo->fmt_matx[i][COL_CUSTOM] &&
cinfo->col_custom_dfilter[i]){
epan_dissect_prime_dfilter(edt, cinfo->col_custom_dfilter[i]);
if (cinfo->col_custom_field) {
header_field_info* hfinfo = proto_registrar_get_byname(cinfo->col_custom_field[i]);
cinfo->col_custom_field_id[i] = hfinfo ? hfinfo->id : -1;
}
}
}
}
void
col_append_fstr(column_info *cinfo, const gint el, const gchar *format, ...)
{
int i;
int len, max_len;
va_list ap;
if (!CHECK_COL(cinfo, el))
return;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
COL_CHECK_APPEND(cinfo, i, max_len);
len = (int) strlen(cinfo->col_buf[i]);
va_start(ap, format);
g_vsnprintf(&cinfo->col_buf[i][len], max_len - len, format, ap);
va_end(ap);
}
}
}
void
col_append_sep_fstr(column_info *cinfo, const gint el, const gchar *separator,
const gchar *format, ...)
{
int i;
int len, max_len, sep_len;
va_list ap;
if (!CHECK_COL(cinfo, el))
return;
if (separator == NULL)
separator = ", ";
sep_len = (int) strlen(separator);
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
COL_CHECK_APPEND(cinfo, i, max_len);
len = (int) strlen(cinfo->col_buf[i]);
if (sep_len != 0) {
if (len != 0) {
g_strlcat(cinfo->col_buf[i], separator, max_len);
len += sep_len;
}
}
va_start(ap, format);
g_vsnprintf(&cinfo->col_buf[i][len], max_len - len, format, ap);
va_end(ap);
}
}
}
void
col_prepend_fstr(column_info *cinfo, const gint el, const gchar *format, ...)
{
va_list ap;
int i;
char orig_buf[COL_BUF_MAX_LEN];
const char *orig;
int max_len;
if (!CHECK_COL(cinfo, el))
return;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
if (cinfo->col_data[i] != cinfo->col_buf[i]) {
orig = cinfo->col_data[i];
} else {
g_strlcpy(orig_buf, cinfo->col_buf[i], max_len);
orig = orig_buf;
}
va_start(ap, format);
g_vsnprintf(cinfo->col_buf[i], max_len, format, ap);
va_end(ap);
if (cinfo->col_fence[i] > 0)
cinfo->col_fence[i] += (int) strlen(cinfo->col_buf[i]);
g_strlcat(cinfo->col_buf[i], orig, max_len);
cinfo->col_data[i] = cinfo->col_buf[i];
}
}
}
void
col_prepend_fence_fstr(column_info *cinfo, const gint el, const gchar *format, ...)
{
va_list ap;
int i;
char orig_buf[COL_BUF_MAX_LEN];
const char *orig;
int max_len;
if (!CHECK_COL(cinfo, el))
return;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
if (cinfo->col_data[i] != cinfo->col_buf[i]) {
orig = cinfo->col_data[i];
} else {
g_strlcpy(orig_buf, cinfo->col_buf[i], max_len);
orig = orig_buf;
}
va_start(ap, format);
g_vsnprintf(cinfo->col_buf[i], max_len, format, ap);
va_end(ap);
if (cinfo->col_fence[i] > 0) {
cinfo->col_fence[i] += (int) strlen(cinfo->col_buf[i]);
} else {
cinfo->col_fence[i] = (int) strlen(cinfo->col_buf[i]);
}
g_strlcat(cinfo->col_buf[i], orig, max_len);
cinfo->col_data[i] = cinfo->col_buf[i];
}
}
}
void
col_add_str(column_info *cinfo, const gint el, const gchar* str)
{
int i;
int fence;
size_t max_len;
if (!CHECK_COL(cinfo, el))
return;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
fence = cinfo->col_fence[i];
if (fence != 0) {
COL_CHECK_APPEND(cinfo, i, max_len);
} else {
cinfo->col_data[i] = cinfo->col_buf[i];
}
g_strlcpy(&cinfo->col_buf[i][fence], str, max_len - fence);
}
}
}
void
col_set_str(column_info *cinfo, const gint el, const gchar* str)
{
int i;
int fence;
size_t max_len;
DISSECTOR_ASSERT(str);
DISSECTOR_ASSERT(!ep_verify_pointer(str));
if (!CHECK_COL(cinfo, el))
return;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
fence = cinfo->col_fence[i];
if (fence != 0) {
COL_CHECK_APPEND(cinfo, i, max_len);
g_strlcpy(&cinfo->col_buf[i][fence], str, max_len - fence);
} else {
cinfo->col_data[i] = str;
}
}
}
}
void
col_add_fstr(column_info *cinfo, const gint el, const gchar *format, ...) {
va_list ap;
int i;
int fence;
int max_len;
if (!CHECK_COL(cinfo, el))
return;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
fence = cinfo->col_fence[i];
if (fence != 0) {
COL_CHECK_APPEND(cinfo, i, max_len);
} else {
cinfo->col_data[i] = cinfo->col_buf[i];
}
va_start(ap, format);
g_vsnprintf(&cinfo->col_buf[i][fence], max_len - fence, format, ap);
va_end(ap);
}
}
}
static void
col_do_append_str(column_info *cinfo, const gint el, const gchar* separator,
const gchar* str)
{
int i;
size_t len, max_len;
if (el == COL_INFO)
max_len = COL_MAX_INFO_LEN;
else
max_len = COL_MAX_LEN;
for (i = cinfo->col_first[el]; i <= cinfo->col_last[el]; i++) {
if (cinfo->fmt_matx[i][el]) {
COL_CHECK_APPEND(cinfo, i, max_len);
len = cinfo->col_buf[i][0];
if (separator != NULL) {
if (len != 0) {
g_strlcat(cinfo->col_buf[i], separator, max_len);
}
}
g_strlcat(cinfo->col_buf[i], str, max_len);
}
}
}
void
col_append_str(column_info *cinfo, const gint el, const gchar* str)
{
if (!CHECK_COL(cinfo, el))
return;
col_do_append_str(cinfo, el, NULL, str);
}
void
col_append_sep_str(column_info *cinfo, const gint el, const gchar* separator,
const gchar* str)
{
if (!CHECK_COL(cinfo, el))
return;
if (separator == NULL)
separator = ", ";
col_do_append_str(cinfo, el, separator, str);
}
gboolean
col_has_time_fmt(column_info *cinfo, const gint col)
{
return ((cinfo->fmt_matx[col][COL_CLS_TIME]) ||
(cinfo->fmt_matx[col][COL_ABS_TIME]) ||
(cinfo->fmt_matx[col][COL_ABS_DATE_TIME]) ||
(cinfo->fmt_matx[col][COL_UTC_TIME]) ||
(cinfo->fmt_matx[col][COL_UTC_DATE_TIME]) ||
(cinfo->fmt_matx[col][COL_REL_TIME]) ||
(cinfo->fmt_matx[col][COL_DELTA_TIME]) ||
(cinfo->fmt_matx[col][COL_DELTA_TIME_DIS]));
}
static void
set_abs_date_time(const frame_data *fd, gchar *buf, gboolean local)
{
struct tm *tmp;
time_t then;
if (fd->flags.has_ts) {
then = fd->abs_ts.secs;
if (local)
tmp = localtime(&then);
else
tmp = gmtime(&then);
} else
tmp = NULL;
if (tmp != NULL) {
switch(timestamp_get_precision()) {
case TS_PREC_FIXED_SEC:
case TS_PREC_AUTO_SEC:
g_snprintf(buf, COL_MAX_LEN,"%04d-%02d-%02d %02d:%02d:%02d",
tmp->tm_year + 1900,
tmp->tm_mon + 1,
tmp->tm_mday,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec);
break;
case TS_PREC_FIXED_DSEC:
case TS_PREC_AUTO_DSEC:
g_snprintf(buf, COL_MAX_LEN,"%04d-%02d-%02d %02d:%02d:%02d.%01d",
tmp->tm_year + 1900,
tmp->tm_mon + 1,
tmp->tm_mday,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 100000000);
break;
case TS_PREC_FIXED_CSEC:
case TS_PREC_AUTO_CSEC:
g_snprintf(buf, COL_MAX_LEN,"%04d-%02d-%02d %02d:%02d:%02d.%02d",
tmp->tm_year + 1900,
tmp->tm_mon + 1,
tmp->tm_mday,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 10000000);
break;
case TS_PREC_FIXED_MSEC:
case TS_PREC_AUTO_MSEC:
g_snprintf(buf, COL_MAX_LEN, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
tmp->tm_year + 1900,
tmp->tm_mon + 1,
tmp->tm_mday,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 1000000);
break;
case TS_PREC_FIXED_USEC:
case TS_PREC_AUTO_USEC:
g_snprintf(buf, COL_MAX_LEN, "%04d-%02d-%02d %02d:%02d:%02d.%06d",
tmp->tm_year + 1900,
tmp->tm_mon + 1,
tmp->tm_mday,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 1000);
break;
case TS_PREC_FIXED_NSEC:
case TS_PREC_AUTO_NSEC:
g_snprintf(buf, COL_MAX_LEN, "%04d-%02d-%02d %02d:%02d:%02d.%09d",
tmp->tm_year + 1900,
tmp->tm_mon + 1,
tmp->tm_mday,
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs);
break;
default:
g_assert_not_reached();
}
} else {
buf[0] = '\0';
}
}
static void
col_set_abs_date_time(const frame_data *fd, column_info *cinfo, const int col)
{
set_abs_date_time(fd, cinfo->col_buf[col], TRUE);
cinfo->col_expr.col_expr[col] = "frame.time";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
}
static void
col_set_utc_date_time(const frame_data *fd, column_info *cinfo, const int col)
{
set_abs_date_time(fd, cinfo->col_buf[col], FALSE);
cinfo->col_expr.col_expr[col] = "frame.time";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
}
static void
set_time_seconds(const nstime_t *ts, gchar *buf)
{
switch(timestamp_get_precision()) {
case TS_PREC_FIXED_SEC:
case TS_PREC_AUTO_SEC:
display_signed_time(buf, COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 1000000000, TO_STR_TIME_RES_T_SECS);
break;
case TS_PREC_FIXED_DSEC:
case TS_PREC_AUTO_DSEC:
display_signed_time(buf, COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 100000000, TO_STR_TIME_RES_T_DSECS);
break;
case TS_PREC_FIXED_CSEC:
case TS_PREC_AUTO_CSEC:
display_signed_time(buf, COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 10000000, TO_STR_TIME_RES_T_CSECS);
break;
case TS_PREC_FIXED_MSEC:
case TS_PREC_AUTO_MSEC:
display_signed_time(buf, COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 1000000, TO_STR_TIME_RES_T_MSECS);
break;
case TS_PREC_FIXED_USEC:
case TS_PREC_AUTO_USEC:
display_signed_time(buf, COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 1000, TO_STR_TIME_RES_T_USECS);
break;
case TS_PREC_FIXED_NSEC:
case TS_PREC_AUTO_NSEC:
display_signed_time(buf, COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs, TO_STR_TIME_RES_T_NSECS);
break;
default:
g_assert_not_reached();
}
}
static void
set_time_hour_min_sec(const nstime_t *ts, gchar *buf)
{
time_t secs = ts->secs;
long nsecs = (long) ts->nsecs;
gboolean negative = FALSE;
if (secs < 0) {
secs = -secs;
negative = TRUE;
}
if (nsecs < 0) {
nsecs = -nsecs;
negative = TRUE;
}
switch(timestamp_get_precision()) {
case TS_PREC_FIXED_SEC:
case TS_PREC_AUTO_SEC:
if (secs >= (60*60)) {
g_snprintf(buf, COL_MAX_LEN, "%s%dh %2dm %2ds",
negative ? "- " : "",
(gint32) secs / (60 * 60),
(gint32) (secs / 60) % 60,
(gint32) secs % 60);
} else if (secs >= 60) {
g_snprintf(buf, COL_MAX_LEN, "%s%dm %2ds",
negative ? "- " : "",
(gint32) secs / 60,
(gint32) secs % 60);
} else {
g_snprintf(buf, COL_MAX_LEN, "%s%ds",
negative ? "- " : "",
(gint32) secs);
}
break;
case TS_PREC_FIXED_DSEC:
case TS_PREC_AUTO_DSEC:
if (secs >= (60*60)) {
g_snprintf(buf, COL_MAX_LEN, "%s%dh %2dm %2d.%01lds",
negative ? "- " : "",
(gint32) secs / (60 * 60),
(gint32) (secs / 60) % 60,
(gint32) secs % 60,
nsecs / 100000000);
} else if (secs >= 60) {
g_snprintf(buf, COL_MAX_LEN, "%s%dm %2d.%01lds",
negative ? "- " : "",
(gint32) secs / 60,
(gint32) secs % 60,
nsecs / 100000000);
} else {
g_snprintf(buf, COL_MAX_LEN, "%s%d.%01lds",
negative ? "- " : "",
(gint32) secs,
nsecs / 100000000);
}
break;
case TS_PREC_FIXED_CSEC:
case TS_PREC_AUTO_CSEC:
if (secs >= (60*60)) {
g_snprintf(buf, COL_MAX_LEN, "%s%dh %2dm %2d.%02lds",
negative ? "- " : "",
(gint32) secs / (60 * 60),
(gint32) (secs / 60) % 60,
(gint32) secs % 60,
nsecs / 10000000);
} else if (secs >= 60) {
g_snprintf(buf, COL_MAX_LEN, "%s%dm %2d.%02lds",
negative ? "- " : "",
(gint32) secs / 60,
(gint32) secs % 60,
nsecs / 10000000);
} else {
g_snprintf(buf, COL_MAX_LEN, "%s%d.%02lds",
negative ? "- " : "",
(gint32) secs,
nsecs / 10000000);
}
break;
case TS_PREC_FIXED_MSEC:
case TS_PREC_AUTO_MSEC:
if (secs >= (60*60)) {
g_snprintf(buf, COL_MAX_LEN, "%s%dh %2dm %2d.%03lds",
negative ? "- " : "",
(gint32) secs / (60 * 60),
(gint32) (secs / 60) % 60,
(gint32) secs % 60,
nsecs / 1000000);
} else if (secs >= 60) {
g_snprintf(buf, COL_MAX_LEN, "%s%dm %2d.%03lds",
negative ? "- " : "",
(gint32) secs / 60,
(gint32) secs % 60,
nsecs / 1000000);
} else {
g_snprintf(buf, COL_MAX_LEN, "%s%d.%03lds",
negative ? "- " : "",
(gint32) secs,
nsecs / 1000000);
}
break;
case TS_PREC_FIXED_USEC:
case TS_PREC_AUTO_USEC:
if (secs >= (60*60)) {
g_snprintf(buf, COL_MAX_LEN, "%s%dh %2dm %2d.%06lds",
negative ? "- " : "",
(gint32) secs / (60 * 60),
(gint32) (secs / 60) % 60,
(gint32) secs % 60,
nsecs / 1000);
} else if (secs >= 60) {
g_snprintf(buf, COL_MAX_LEN, "%s%dm %2d.%06lds",
negative ? "- " : "",
(gint32) secs / 60,
(gint32) secs % 60,
nsecs / 1000);
} else {
g_snprintf(buf, COL_MAX_LEN, "%s%d.%06lds",
negative ? "- " : "",
(gint32) secs,
nsecs / 1000);
}
break;
case TS_PREC_FIXED_NSEC:
case TS_PREC_AUTO_NSEC:
if (secs >= (60*60)) {
g_snprintf(buf, COL_MAX_LEN, "%s%dh %2dm %2d.%09lds",
negative ? "- " : "",
(gint32) secs / (60 * 60),
(gint32) (secs / 60) % 60,
(gint32) secs % 60,
nsecs);
} else if (secs >= 60) {
g_snprintf(buf, COL_MAX_LEN, "%s%dm %2d.%09lds",
negative ? "- " : "",
(gint32) secs / 60,
(gint32) secs % 60,
nsecs);
} else {
g_snprintf(buf, COL_MAX_LEN, "%s%d.%09lds",
negative ? "- " : "",
(gint32) secs,
nsecs);
}
break;
default:
g_assert_not_reached();
}
}
static void
col_set_rel_time(const frame_data *fd, column_info *cinfo, const int col)
{
if (!fd->flags.has_ts) {
cinfo->col_buf[col][0] = '\0';
return;
}
switch (timestamp_get_seconds_type()) {
case TS_SECONDS_DEFAULT:
set_time_seconds(&fd->rel_ts, cinfo->col_buf[col]);
cinfo->col_expr.col_expr[col] = "frame.time_relative";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
break;
case TS_SECONDS_HOUR_MIN_SEC:
set_time_hour_min_sec(&fd->rel_ts, cinfo->col_buf[col]);
cinfo->col_expr.col_expr[col] = "frame.time_relative";
set_time_seconds(&fd->rel_ts, cinfo->col_expr.col_expr_val[col]);
break;
default:
g_assert_not_reached();
}
cinfo->col_data[col] = cinfo->col_buf[col];
}
static void
col_set_delta_time(const frame_data *fd, column_info *cinfo, const int col)
{
nstime_t del_cap_ts;
frame_delta_abs_time(fd, fd->prev_cap, &del_cap_ts);
switch (timestamp_get_seconds_type()) {
case TS_SECONDS_DEFAULT:
set_time_seconds(&del_cap_ts, cinfo->col_buf[col]);
cinfo->col_expr.col_expr[col] = "frame.time_delta";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
break;
case TS_SECONDS_HOUR_MIN_SEC:
set_time_hour_min_sec(&del_cap_ts, cinfo->col_buf[col]);
cinfo->col_expr.col_expr[col] = "frame.time_delta";
set_time_seconds(&del_cap_ts, cinfo->col_expr.col_expr_val[col]);
break;
default:
g_assert_not_reached();
}
cinfo->col_data[col] = cinfo->col_buf[col];
}
static void
col_set_delta_time_dis(const frame_data *fd, column_info *cinfo, const int col)
{
nstime_t del_dis_ts;
if (!fd->flags.has_ts) {
cinfo->col_buf[col][0] = '\0';
return;
}
frame_delta_abs_time(fd, fd->prev_dis, &del_dis_ts);
switch (timestamp_get_seconds_type()) {
case TS_SECONDS_DEFAULT:
set_time_seconds(&del_dis_ts, cinfo->col_buf[col]);
cinfo->col_expr.col_expr[col] = "frame.time_delta_displayed";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
break;
case TS_SECONDS_HOUR_MIN_SEC:
set_time_hour_min_sec(&del_dis_ts, cinfo->col_buf[col]);
cinfo->col_expr.col_expr[col] = "frame.time_delta_displayed";
set_time_seconds(&del_dis_ts, cinfo->col_expr.col_expr_val[col]);
break;
default:
g_assert_not_reached();
}
cinfo->col_data[col] = cinfo->col_buf[col];
}
static void
set_abs_time(const frame_data *fd, gchar *buf, gboolean local)
{
struct tm *tmp;
time_t then;
if (fd->flags.has_ts) {
then = fd->abs_ts.secs;
if (local)
tmp = localtime(&then);
else
tmp = gmtime(&then);
} else
tmp = NULL;
if (tmp != NULL) {
switch(timestamp_get_precision()) {
case TS_PREC_FIXED_SEC:
case TS_PREC_AUTO_SEC:
g_snprintf(buf, COL_MAX_LEN,"%02d:%02d:%02d",
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec);
break;
case TS_PREC_FIXED_DSEC:
case TS_PREC_AUTO_DSEC:
g_snprintf(buf, COL_MAX_LEN,"%02d:%02d:%02d.%01d",
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 100000000);
break;
case TS_PREC_FIXED_CSEC:
case TS_PREC_AUTO_CSEC:
g_snprintf(buf, COL_MAX_LEN,"%02d:%02d:%02d.%02d",
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 10000000);
break;
case TS_PREC_FIXED_MSEC:
case TS_PREC_AUTO_MSEC:
g_snprintf(buf, COL_MAX_LEN,"%02d:%02d:%02d.%03d",
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 1000000);
break;
case TS_PREC_FIXED_USEC:
case TS_PREC_AUTO_USEC:
g_snprintf(buf, COL_MAX_LEN,"%02d:%02d:%02d.%06d",
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs / 1000);
break;
case TS_PREC_FIXED_NSEC:
case TS_PREC_AUTO_NSEC:
g_snprintf(buf, COL_MAX_LEN, "%02d:%02d:%02d.%09d",
tmp->tm_hour,
tmp->tm_min,
tmp->tm_sec,
fd->abs_ts.nsecs);
break;
default:
g_assert_not_reached();
}
} else {
*buf = '\0';
}
}
static void
col_set_abs_time(const frame_data *fd, column_info *cinfo, const int col)
{
set_abs_time(fd, cinfo->col_buf[col], TRUE);
cinfo->col_expr.col_expr[col] = "frame.time";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
}
static void
col_set_utc_time(const frame_data *fd, column_info *cinfo, const int col)
{
set_abs_time(fd, cinfo->col_buf[col], FALSE);
cinfo->col_expr.col_expr[col] = "frame.time";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
}
static gboolean
set_epoch_time(const frame_data *fd, gchar *buf)
{
if (!fd->flags.has_ts) {
buf[0] = '\0';
return FALSE;
}
switch(timestamp_get_precision()) {
case TS_PREC_FIXED_SEC:
case TS_PREC_AUTO_SEC:
display_epoch_time(buf, COL_MAX_LEN,
fd->abs_ts.secs, fd->abs_ts.nsecs / 1000000000, TO_STR_TIME_RES_T_SECS);
break;
case TS_PREC_FIXED_DSEC:
case TS_PREC_AUTO_DSEC:
display_epoch_time(buf, COL_MAX_LEN,
fd->abs_ts.secs, fd->abs_ts.nsecs / 100000000, TO_STR_TIME_RES_T_DSECS);
break;
case TS_PREC_FIXED_CSEC:
case TS_PREC_AUTO_CSEC:
display_epoch_time(buf, COL_MAX_LEN,
fd->abs_ts.secs, fd->abs_ts.nsecs / 10000000, TO_STR_TIME_RES_T_CSECS);
break;
case TS_PREC_FIXED_MSEC:
case TS_PREC_AUTO_MSEC:
display_epoch_time(buf, COL_MAX_LEN,
fd->abs_ts.secs, fd->abs_ts.nsecs / 1000000, TO_STR_TIME_RES_T_MSECS);
break;
case TS_PREC_FIXED_USEC:
case TS_PREC_AUTO_USEC:
display_epoch_time(buf, COL_MAX_LEN,
fd->abs_ts.secs, fd->abs_ts.nsecs / 1000, TO_STR_TIME_RES_T_USECS);
break;
case TS_PREC_FIXED_NSEC:
case TS_PREC_AUTO_NSEC:
display_epoch_time(buf, COL_MAX_LEN,
fd->abs_ts.secs, fd->abs_ts.nsecs, TO_STR_TIME_RES_T_NSECS);
break;
default:
g_assert_not_reached();
}
return TRUE;
}
static void
col_set_epoch_time(const frame_data *fd, column_info *cinfo, const int col)
{
if (set_epoch_time(fd, cinfo->col_buf[col])) {
cinfo->col_expr.col_expr[col] = "frame.time_delta";
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
}
cinfo->col_data[col] = cinfo->col_buf[col];
}
void
set_fd_time(frame_data *fd, gchar *buf)
{
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
set_abs_time(fd, buf, TRUE);
break;
case TS_ABSOLUTE_WITH_DATE:
set_abs_date_time(fd, buf, TRUE);
break;
case TS_RELATIVE:
if (fd->flags.has_ts) {
switch (timestamp_get_seconds_type()) {
case TS_SECONDS_DEFAULT:
set_time_seconds(&fd->rel_ts, buf);
break;
case TS_SECONDS_HOUR_MIN_SEC:
set_time_seconds(&fd->rel_ts, buf);
break;
default:
g_assert_not_reached();
}
} else {
buf[0] = '\0';
}
break;
case TS_DELTA:
if (fd->flags.has_ts) {
nstime_t del_cap_ts;
frame_delta_abs_time(fd, fd->prev_cap, &del_cap_ts);
switch (timestamp_get_seconds_type()) {
case TS_SECONDS_DEFAULT:
set_time_seconds(&del_cap_ts, buf);
break;
case TS_SECONDS_HOUR_MIN_SEC:
set_time_hour_min_sec(&del_cap_ts, buf);
break;
default:
g_assert_not_reached();
}
} else {
buf[0] = '\0';
}
break;
case TS_DELTA_DIS:
if (fd->flags.has_ts) {
nstime_t del_dis_ts;
frame_delta_abs_time(fd, fd->prev_dis, &del_dis_ts);
switch (timestamp_get_seconds_type()) {
case TS_SECONDS_DEFAULT:
set_time_seconds(&del_dis_ts, buf);
break;
case TS_SECONDS_HOUR_MIN_SEC:
set_time_hour_min_sec(&del_dis_ts, buf);
break;
default:
g_assert_not_reached();
}
} else {
buf[0] = '\0';
}
break;
case TS_EPOCH:
set_epoch_time(fd, buf);
break;
case TS_UTC:
set_abs_time(fd, buf, FALSE);
break;
case TS_UTC_WITH_DATE:
set_abs_date_time(fd, buf, FALSE);
break;
case TS_NOT_SET:
g_assert(FALSE);
break;
}
}
static void
col_set_cls_time(const frame_data *fd, column_info *cinfo, const gint col)
{
switch (timestamp_get_type()) {
case TS_ABSOLUTE:
col_set_abs_time(fd, cinfo, col);
break;
case TS_ABSOLUTE_WITH_DATE:
col_set_abs_date_time(fd, cinfo, col);
break;
case TS_RELATIVE:
col_set_rel_time(fd, cinfo, col);
break;
case TS_DELTA:
col_set_delta_time(fd, cinfo, col);
break;
case TS_DELTA_DIS:
col_set_delta_time_dis(fd, cinfo, col);
break;
case TS_EPOCH:
col_set_epoch_time(fd, cinfo, col);
break;
case TS_UTC:
col_set_utc_time(fd, cinfo, col);
break;
case TS_UTC_WITH_DATE:
col_set_utc_date_time(fd, cinfo, col);
break;
case TS_NOT_SET:
g_assert_not_reached();
break;
}
}
static void
col_set_fmt_time(const frame_data *fd, column_info *cinfo, const gint fmt, const gint col)
{
COL_CHECK_REF_TIME(fd, cinfo->col_buf[col]);
switch (fmt) {
case COL_CLS_TIME:
col_set_cls_time(fd, cinfo, col);
break;
case COL_ABS_TIME:
col_set_abs_time(fd, cinfo, col);
break;
case COL_ABS_DATE_TIME:
col_set_abs_date_time(fd, cinfo, col);
break;
case COL_REL_TIME:
col_set_rel_time(fd, cinfo, col);
break;
case COL_DELTA_TIME:
col_set_delta_time(fd, cinfo, col);
break;
case COL_DELTA_TIME_DIS:
col_set_delta_time_dis(fd, cinfo, col);
break;
case COL_UTC_TIME:
col_set_utc_time(fd, cinfo, col);
break;
case COL_UTC_DATE_TIME:
col_set_utc_date_time(fd, cinfo, col);
break;
default:
g_assert_not_reached();
break;
}
}
void
col_set_time(column_info *cinfo, const gint el, const nstime_t *ts, const char *fieldname)
{
int col;
if (!CHECK_COL(cinfo, el))
return;
for (col = cinfo->col_first[el]; col <= cinfo->col_last[el]; col++) {
if (cinfo->fmt_matx[col][el]) {
switch(timestamp_get_precision()) {
case TS_PREC_FIXED_SEC:
case TS_PREC_AUTO_SEC:
display_signed_time(cinfo->col_buf[col], COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 1000000000, TO_STR_TIME_RES_T_SECS);
break;
case TS_PREC_FIXED_DSEC:
case TS_PREC_AUTO_DSEC:
display_signed_time(cinfo->col_buf[col], COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 100000000, TO_STR_TIME_RES_T_DSECS);
break;
case TS_PREC_FIXED_CSEC:
case TS_PREC_AUTO_CSEC:
display_signed_time(cinfo->col_buf[col], COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 10000000, TO_STR_TIME_RES_T_CSECS);
break;
case TS_PREC_FIXED_MSEC:
case TS_PREC_AUTO_MSEC:
display_signed_time(cinfo->col_buf[col], COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 1000000, TO_STR_TIME_RES_T_MSECS);
break;
case TS_PREC_FIXED_USEC:
case TS_PREC_AUTO_USEC:
display_signed_time(cinfo->col_buf[col], COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs / 1000, TO_STR_TIME_RES_T_USECS);
break;
case TS_PREC_FIXED_NSEC:
case TS_PREC_AUTO_NSEC:
display_signed_time(cinfo->col_buf[col], COL_MAX_LEN,
(gint32) ts->secs, ts->nsecs, TO_STR_TIME_RES_T_NSECS);
break;
default:
g_assert_not_reached();
}
cinfo->col_data[col] = cinfo->col_buf[col];
cinfo->col_expr.col_expr[col] = fieldname;
g_strlcpy(cinfo->col_expr.col_expr_val[col],cinfo->col_buf[col],COL_MAX_LEN);
}
}
}
static void
col_set_addr(packet_info *pinfo, const int col, const address *addr, const gboolean is_src,
const gboolean fill_col_exprs, const gboolean res)
{
if (addr->type == AT_NONE) {
return;
}
if (res)
pinfo->cinfo->col_data[col] = se_get_addr_name(addr);
else
pinfo->cinfo->col_data[col] = se_address_to_str(addr);
if (!fill_col_exprs)
return;
switch (addr->type) {
case AT_AX25:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "ax25.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "ax25.dst";
g_strlcpy(pinfo->cinfo->col_expr.col_expr_val[col], ax25_to_str((guint8 *)addr->data), COL_MAX_LEN);
break;
case AT_ETHER:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "eth.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "eth.dst";
address_to_str_buf(addr, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
break;
case AT_IPv4:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "ip.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "ip.dst";
ip_to_str_buf((guint8 *)addr->data, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
break;
case AT_IPv6:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "ipv6.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "ipv6.dst";
address_to_str_buf(addr, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
break;
case AT_ATALK:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "ddp.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "ddp.dst";
g_strlcpy(pinfo->cinfo->col_expr.col_expr_val[col], pinfo->cinfo->col_buf[col], COL_MAX_LEN);
break;
case AT_ARCNET:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "arcnet.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "arcnet.dst";
g_strlcpy(pinfo->cinfo->col_expr.col_expr_val[col], pinfo->cinfo->col_buf[col], COL_MAX_LEN);
break;
case AT_URI:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "uri.src";
else
pinfo->cinfo->col_expr.col_expr[col] = "uri.dst";
address_to_str_buf(addr, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
break;
default:
break;
}
if (addr->hf != -1) {
pinfo->cinfo->col_expr.col_expr[col] = proto_registrar_get_nth(addr->hf)->abbrev;
}
}
static void
col_set_port(packet_info *pinfo, const int col, const gboolean is_res, const gboolean is_src, const gboolean fill_col_exprs _U_)
{
guint32 port;
if (is_src)
port = pinfo->srcport;
else
port = pinfo->destport;
switch (pinfo->ptype) {
case PT_SCTP:
if (is_res)
g_strlcpy(pinfo->cinfo->col_buf[col], get_sctp_port(port), COL_MAX_LEN);
else
guint32_to_str_buf(port, pinfo->cinfo->col_buf[col], COL_MAX_LEN);
break;
case PT_TCP:
guint32_to_str_buf(port, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
if (is_res)
g_strlcpy(pinfo->cinfo->col_buf[col], get_tcp_port(port), COL_MAX_LEN);
else
g_strlcpy(pinfo->cinfo->col_buf[col], pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "tcp.srcport";
else
pinfo->cinfo->col_expr.col_expr[col] = "tcp.dstport";
break;
case PT_UDP:
guint32_to_str_buf(port, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
if (is_res)
g_strlcpy(pinfo->cinfo->col_buf[col], get_udp_port(port), COL_MAX_LEN);
else
g_strlcpy(pinfo->cinfo->col_buf[col], pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "udp.srcport";
else
pinfo->cinfo->col_expr.col_expr[col] = "udp.dstport";
break;
case PT_DDP:
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "ddp.src_socket";
else
pinfo->cinfo->col_expr.col_expr[col] = "ddp.dst_socket";
guint32_to_str_buf(port, pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
g_strlcpy(pinfo->cinfo->col_buf[col], pinfo->cinfo->col_expr.col_expr_val[col], COL_MAX_LEN);
break;
case PT_IPX:
g_snprintf(pinfo->cinfo->col_buf[col], COL_MAX_LEN, "0x%04x", port);
g_strlcpy(pinfo->cinfo->col_expr.col_expr_val[col], pinfo->cinfo->col_buf[col],COL_MAX_LEN);
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "ipx.src.socket";
else
pinfo->cinfo->col_expr.col_expr[col] = "ipx.dst.socket";
break;
case PT_IDP:
g_snprintf(pinfo->cinfo->col_buf[col], COL_MAX_LEN, "0x%04x", port);
g_strlcpy(pinfo->cinfo->col_expr.col_expr_val[col], pinfo->cinfo->col_buf[col],COL_MAX_LEN);
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "idp.src.socket";
else
pinfo->cinfo->col_expr.col_expr[col] = "idp.dst.socket";
break;
case PT_USB:
g_snprintf(pinfo->cinfo->col_buf[col], COL_MAX_LEN, "0x%08x", port);
g_strlcpy(pinfo->cinfo->col_expr.col_expr_val[col], pinfo->cinfo->col_buf[col],COL_MAX_LEN);
if (is_src)
pinfo->cinfo->col_expr.col_expr[col] = "usb.src.endpoint";
else
pinfo->cinfo->col_expr.col_expr[col] = "usb.dst.endpoint";
break;
default:
break;
}
pinfo->cinfo->col_data[col] = pinfo->cinfo->col_buf[col];
}
gboolean
col_based_on_frame_data(column_info *cinfo, const gint col)
{
g_assert(cinfo);
g_assert(col < cinfo->num_cols);
switch (cinfo->col_fmt[col]) {
case COL_NUMBER:
case COL_CLS_TIME:
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
case COL_REL_TIME:
case COL_DELTA_TIME:
case COL_DELTA_TIME_DIS:
case COL_PACKET_LENGTH:
case COL_CUMULATIVE_BYTES:
return TRUE;
default:
return FALSE;
}
}
void
col_fill_in_frame_data(const frame_data *fd, column_info *cinfo, const gint col, const gboolean fill_col_exprs)
{
switch (cinfo->col_fmt[col]) {
case COL_NUMBER:
guint32_to_str_buf(fd->num, cinfo->col_buf[col], COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
break;
case COL_CLS_TIME:
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
case COL_REL_TIME:
case COL_DELTA_TIME:
case COL_DELTA_TIME_DIS:
col_set_fmt_time(fd, cinfo, cinfo->col_fmt[col], col);
break;
case COL_PACKET_LENGTH:
guint32_to_str_buf(fd->pkt_len, cinfo->col_buf[col], COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
break;
case COL_CUMULATIVE_BYTES:
guint32_to_str_buf(fd->cum_bytes, cinfo->col_buf[col], COL_MAX_LEN);
cinfo->col_data[col] = cinfo->col_buf[col];
break;
default:
break;
}
if (!fill_col_exprs)
return;
switch (cinfo->col_fmt[col]) {
case COL_NUMBER:
cinfo->col_expr.col_expr[col] = "frame.number";
g_strlcpy(cinfo->col_expr.col_expr_val[col], cinfo->col_buf[col], COL_MAX_LEN);
break;
case COL_CLS_TIME:
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
case COL_REL_TIME:
case COL_DELTA_TIME:
case COL_DELTA_TIME_DIS:
break;
case COL_PACKET_LENGTH:
cinfo->col_expr.col_expr[col] = "frame.len";
g_strlcpy(cinfo->col_expr.col_expr_val[col], cinfo->col_buf[col], COL_MAX_LEN);
break;
case COL_CUMULATIVE_BYTES:
break;
default:
break;
}
}
void
col_fill_in(packet_info *pinfo, const gboolean fill_col_exprs, const gboolean fill_fd_colums)
{
int i;
if (!pinfo->cinfo)
return;
for (i = 0; i < pinfo->cinfo->num_cols; i++) {
switch (pinfo->cinfo->col_fmt[i]) {
case COL_NUMBER:
case COL_CLS_TIME:
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
case COL_REL_TIME:
case COL_DELTA_TIME:
case COL_DELTA_TIME_DIS:
case COL_PACKET_LENGTH:
case COL_CUMULATIVE_BYTES:
if (fill_fd_colums)
col_fill_in_frame_data(pinfo->fd, pinfo->cinfo, i, fill_col_exprs);
break;
case COL_DEF_SRC:
case COL_RES_SRC:
col_set_addr(pinfo, i, &pinfo->src, TRUE, fill_col_exprs, TRUE);
break;
case COL_UNRES_SRC:
col_set_addr(pinfo, i, &pinfo->src, TRUE, fill_col_exprs, FALSE);
break;
case COL_DEF_DL_SRC:
case COL_RES_DL_SRC:
col_set_addr(pinfo, i, &pinfo->dl_src, TRUE, fill_col_exprs, TRUE);
break;
case COL_UNRES_DL_SRC:
col_set_addr(pinfo, i, &pinfo->dl_src, TRUE, fill_col_exprs, FALSE);
break;
case COL_DEF_NET_SRC:
case COL_RES_NET_SRC:
col_set_addr(pinfo, i, &pinfo->net_src, TRUE, fill_col_exprs, TRUE);
break;
case COL_UNRES_NET_SRC:
col_set_addr(pinfo, i, &pinfo->net_src, TRUE, fill_col_exprs, FALSE);
break;
case COL_DEF_DST:
case COL_RES_DST:
col_set_addr(pinfo, i, &pinfo->dst, FALSE, fill_col_exprs, TRUE);
break;
case COL_UNRES_DST:
col_set_addr(pinfo, i, &pinfo->dst, FALSE, fill_col_exprs, FALSE);
break;
case COL_DEF_DL_DST:
case COL_RES_DL_DST:
col_set_addr(pinfo, i, &pinfo->dl_dst, FALSE, fill_col_exprs, TRUE);
break;
case COL_UNRES_DL_DST:
col_set_addr(pinfo, i, &pinfo->dl_dst, FALSE, fill_col_exprs, FALSE);
break;
case COL_DEF_NET_DST:
case COL_RES_NET_DST:
col_set_addr(pinfo, i, &pinfo->net_dst, FALSE, fill_col_exprs, TRUE);
break;
case COL_UNRES_NET_DST:
col_set_addr(pinfo, i, &pinfo->net_dst, FALSE, fill_col_exprs, FALSE);
break;
case COL_DEF_SRC_PORT:
case COL_RES_SRC_PORT:
col_set_port(pinfo, i, TRUE, TRUE, fill_col_exprs);
break;
case COL_UNRES_SRC_PORT:
col_set_port(pinfo, i, FALSE, TRUE, fill_col_exprs);
break;
case COL_DEF_DST_PORT:
case COL_RES_DST_PORT:
col_set_port(pinfo, i, TRUE, FALSE, fill_col_exprs);
break;
case COL_UNRES_DST_PORT:
col_set_port(pinfo, i, FALSE, FALSE, fill_col_exprs);
break;
case COL_VSAN:
guint32_to_str_buf(pinfo->vsan, pinfo->cinfo->col_buf[i], COL_MAX_LEN);
pinfo->cinfo->col_data[i] = pinfo->cinfo->col_buf[i];
break;
case NUM_COL_FMTS:
g_assert_not_reached();
break;
default:
if (pinfo->cinfo->col_fmt[i] >= NUM_COL_FMTS) {
g_assert_not_reached();
}
break;
}
}
}
void
col_fill_in_error(column_info *cinfo, frame_data *fdata, const gboolean fill_col_exprs, const gboolean fill_fd_colums)
{
int i;
if (!cinfo)
return;
for (i = 0; i < cinfo->num_cols; i++) {
switch (cinfo->col_fmt[i]) {
case COL_NUMBER:
case COL_CLS_TIME:
case COL_ABS_TIME:
case COL_ABS_DATE_TIME:
case COL_UTC_TIME:
case COL_UTC_DATE_TIME:
case COL_REL_TIME:
case COL_DELTA_TIME:
case COL_DELTA_TIME_DIS:
case COL_PACKET_LENGTH:
case COL_CUMULATIVE_BYTES:
if (fill_fd_colums)
col_fill_in_frame_data(fdata, cinfo, i, fill_col_exprs);
break;
case COL_INFO:
cinfo->col_data[i] = "Read error";
break;
case NUM_COL_FMTS:
g_assert_not_reached();
break;
default:
if (cinfo->col_fmt[i] >= NUM_COL_FMTS) {
g_assert_not_reached();
}
cinfo->col_data[i] = "???";
break;
}
}
}
