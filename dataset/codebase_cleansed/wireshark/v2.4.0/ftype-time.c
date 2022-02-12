static gboolean
cmp_eq(const fvalue_t *a, const fvalue_t *b)
{
return ((a->value.time.secs) ==(b->value.time.secs))
&&((a->value.time.nsecs)==(b->value.time.nsecs));
}
static gboolean
cmp_ne(const fvalue_t *a, const fvalue_t *b)
{
return (a->value.time.secs !=b->value.time.secs)
||(a->value.time.nsecs!=b->value.time.nsecs);
}
static gboolean
cmp_gt(const fvalue_t *a, const fvalue_t *b)
{
if (a->value.time.secs > b->value.time.secs) {
return TRUE;
}
if (a->value.time.secs < b->value.time.secs) {
return FALSE;
}
return a->value.time.nsecs > b->value.time.nsecs;
}
static gboolean
cmp_ge(const fvalue_t *a, const fvalue_t *b)
{
if (a->value.time.secs > b->value.time.secs) {
return TRUE;
}
if (a->value.time.secs < b->value.time.secs) {
return FALSE;
}
return a->value.time.nsecs >= b->value.time.nsecs;
}
static gboolean
cmp_lt(const fvalue_t *a, const fvalue_t *b)
{
if (a->value.time.secs < b->value.time.secs) {
return TRUE;
}
if (a->value.time.secs > b->value.time.secs) {
return FALSE;
}
return a->value.time.nsecs < b->value.time.nsecs;
}
static gboolean
cmp_le(const fvalue_t *a, const fvalue_t *b)
{
if (a->value.time.secs < b->value.time.secs) {
return TRUE;
}
if (a->value.time.secs > b->value.time.secs) {
return FALSE;
}
return a->value.time.nsecs <= b->value.time.nsecs;
}
static gboolean
get_nsecs(const char *startp, int *nsecs)
{
int ndigits;
int scale;
const char *p;
int val;
int digit;
int i;
ndigits = (int)strlen(startp);
scale = 9 - ndigits;
p = startp + ndigits;
val = 0;
while (p != startp) {
p--;
if (!g_ascii_isdigit(*p)) {
return FALSE;
}
digit = *p - '0';
if (digit != 0) {
if (scale < 0)
return FALSE;
for (i = 0; i < scale; i++)
digit *= 10;
val += digit;
}
scale++;
}
*nsecs = val;
return TRUE;
}
static gboolean
relative_val_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
const char *curptr;
char *endptr;
gboolean negative = FALSE;
curptr = s;
if(*curptr == '-') {
negative = TRUE;
curptr++;
}
if (*curptr != '.') {
fv->value.time.secs = strtoul(curptr, &endptr, 10);
if (endptr == curptr || (*endptr != '\0' && *endptr != '.'))
goto fail;
curptr = endptr;
if (*curptr == '.')
curptr++;
} else {
fv->value.time.secs = 0;
curptr++;
}
if (*curptr != '\0') {
if (!get_nsecs(curptr, &fv->value.time.nsecs))
goto fail;
} else {
fv->value.time.nsecs = 0;
}
if(negative) {
fv->value.time.secs = -fv->value.time.secs;
fv->value.time.nsecs = -fv->value.time.nsecs;
}
return TRUE;
fail:
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid time.", s);
return FALSE;
}
static gboolean
absolute_val_from_string(fvalue_t *fv, const char *s, gchar **err_msg)
{
struct tm tm;
char *curptr;
memset(&tm, 0, sizeof(tm));
curptr = strptime(s,"%b %d, %Y %H:%M:%S", &tm);
if (curptr == NULL)
curptr = strptime(s,"%Y-%m-%dT%H:%M:%S", &tm);
if (curptr == NULL)
curptr = strptime(s,"%Y-%m-%d %H:%M:%S", &tm);
if (curptr == NULL)
curptr = strptime(s,"%Y-%m-%d %H:%M", &tm);
if (curptr == NULL)
curptr = strptime(s,"%Y-%m-%d %H", &tm);
if (curptr == NULL)
curptr = strptime(s,"%Y-%m-%d", &tm);
if (curptr == NULL)
goto fail;
tm.tm_isdst = -1;
fv->value.time.secs = mktime(&tm);
if (*curptr != '\0') {
if (*curptr != '.')
goto fail;
curptr++;
if (!g_ascii_isdigit((unsigned char)*curptr))
goto fail;
if (!get_nsecs(curptr, &fv->value.time.nsecs))
goto fail;
} else {
fv->value.time.nsecs = 0;
}
if (fv->value.time.secs == -1) {
goto fail;
}
return TRUE;
fail:
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid absolute time. Example: \"Nov 12, 1999 08:55:44.123\" or \"2011-07-04 12:34:56\"",
s);
return FALSE;
}
static gboolean
absolute_val_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
return absolute_val_from_string(fv, s, err_msg);
}
static void
time_fvalue_new(fvalue_t *fv)
{
fv->value.time.secs = 0;
fv->value.time.nsecs = 0;
}
static void
time_fvalue_set(fvalue_t *fv, const nstime_t *value)
{
fv->value.time = *value;
}
static gpointer
value_get(fvalue_t *fv)
{
return &(fv->value.time);
}
static int
absolute_val_repr_len(fvalue_t *fv, ftrepr_t rtype, int field_display _U_)
{
gchar *rep;
int ret;
rep = abs_time_to_str(NULL, &fv->value.time, ABSOLUTE_TIME_LOCAL,
rtype == FTREPR_DISPLAY);
ret = (int)strlen(rep) + ((rtype == FTREPR_DFILTER) ? 2 : 0);
wmem_free(NULL, rep);
return ret;
}
static void
absolute_val_to_repr(fvalue_t *fv, ftrepr_t rtype, int field_display _U_, char *buf, unsigned int size)
{
gchar *rep = abs_time_to_str(NULL, &fv->value.time, ABSOLUTE_TIME_LOCAL,
rtype == FTREPR_DISPLAY);
if (rtype == FTREPR_DFILTER) {
*buf++ = '\"';
}
g_strlcpy(buf, rep, size);
if (rtype == FTREPR_DFILTER) {
buf += strlen(rep);
*buf++ = '\"';
*buf++ = '\0';
}
wmem_free(NULL, rep);
}
static int
relative_val_repr_len(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_)
{
gchar *rep;
int ret;
rep = rel_time_to_secs_str(NULL, &fv->value.time);
ret = (int)strlen(rep);
wmem_free(NULL, rep);
return ret;
}
static void
relative_val_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf, unsigned int size)
{
gchar *rep;
rep = rel_time_to_secs_str(NULL, &fv->value.time);
g_strlcpy(buf, rep, size);
wmem_free(NULL, rep);
}
void
ftype_register_time(void)
{
static ftype_t abstime_type = {
FT_ABSOLUTE_TIME,
"FT_ABSOLUTE_TIME",
"Date and time",
0,
time_fvalue_new,
NULL,
absolute_val_from_unparsed,
absolute_val_from_string,
absolute_val_to_repr,
absolute_val_repr_len,
{ .set_value_time = time_fvalue_set },
{ .get_value_ptr = value_get },
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
NULL,
NULL,
NULL,
NULL,
NULL
};
static ftype_t reltime_type = {
FT_RELATIVE_TIME,
"FT_RELATIVE_TIME",
"Time offset",
0,
time_fvalue_new,
NULL,
relative_val_from_unparsed,
NULL,
relative_val_to_repr,
relative_val_repr_len,
{ .set_value_time = time_fvalue_set },
{ .get_value_ptr = value_get },
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
NULL,
NULL,
NULL,
NULL,
NULL
};
ftype_register(FT_ABSOLUTE_TIME, &abstime_type);
ftype_register(FT_RELATIVE_TIME, &reltime_type);
}
