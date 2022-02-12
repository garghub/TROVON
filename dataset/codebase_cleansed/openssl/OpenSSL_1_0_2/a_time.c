ASN1_TIME *ASN1_TIME_set(ASN1_TIME *s, time_t t)
{
return ASN1_TIME_adj(s, t, 0, 0);
}
ASN1_TIME *ASN1_TIME_adj(ASN1_TIME *s, time_t t,
int offset_day, long offset_sec)
{
struct tm *ts;
struct tm data;
ts = OPENSSL_gmtime(&t, &data);
if (ts == NULL) {
ASN1err(ASN1_F_ASN1_TIME_ADJ, ASN1_R_ERROR_GETTING_TIME);
return NULL;
}
if (offset_day || offset_sec) {
if (!OPENSSL_gmtime_adj(ts, offset_day, offset_sec))
return NULL;
}
if ((ts->tm_year >= 50) && (ts->tm_year < 150))
return ASN1_UTCTIME_adj(s, t, offset_day, offset_sec);
return ASN1_GENERALIZEDTIME_adj(s, t, offset_day, offset_sec);
}
int ASN1_TIME_check(ASN1_TIME *t)
{
if (t->type == V_ASN1_GENERALIZEDTIME)
return ASN1_GENERALIZEDTIME_check(t);
else if (t->type == V_ASN1_UTCTIME)
return ASN1_UTCTIME_check(t);
return 0;
}
ASN1_GENERALIZEDTIME *ASN1_TIME_to_generalizedtime(ASN1_TIME *t,
ASN1_GENERALIZEDTIME **out)
{
ASN1_GENERALIZEDTIME *ret;
char *str;
int newlen;
if (!ASN1_TIME_check(t))
return NULL;
if (!out || !*out) {
if (!(ret = ASN1_GENERALIZEDTIME_new()))
return NULL;
if (out)
*out = ret;
} else
ret = *out;
if (t->type == V_ASN1_GENERALIZEDTIME) {
if (!ASN1_STRING_set(ret, t->data, t->length))
return NULL;
return ret;
}
if (!ASN1_STRING_set(ret, NULL, t->length + 2))
return NULL;
newlen = t->length + 2 + 1;
str = (char *)ret->data;
if (t->data[0] >= '5')
BUF_strlcpy(str, "19", newlen);
else
BUF_strlcpy(str, "20", newlen);
BUF_strlcat(str, (char *)t->data, newlen);
return ret;
}
int ASN1_TIME_set_string(ASN1_TIME *s, const char *str)
{
ASN1_TIME t;
t.length = strlen(str);
t.data = (unsigned char *)str;
t.flags = 0;
t.type = V_ASN1_UTCTIME;
if (!ASN1_TIME_check(&t)) {
t.type = V_ASN1_GENERALIZEDTIME;
if (!ASN1_TIME_check(&t))
return 0;
}
if (s && !ASN1_STRING_copy((ASN1_STRING *)s, (ASN1_STRING *)&t))
return 0;
return 1;
}
static int asn1_time_to_tm(struct tm *tm, const ASN1_TIME *t)
{
if (t == NULL) {
time_t now_t;
time(&now_t);
if (OPENSSL_gmtime(&now_t, tm))
return 1;
return 0;
}
if (t->type == V_ASN1_UTCTIME)
return asn1_utctime_to_tm(tm, t);
else if (t->type == V_ASN1_GENERALIZEDTIME)
return asn1_generalizedtime_to_tm(tm, t);
return 0;
}
int ASN1_TIME_diff(int *pday, int *psec,
const ASN1_TIME *from, const ASN1_TIME *to)
{
struct tm tm_from, tm_to;
if (!asn1_time_to_tm(&tm_from, from))
return 0;
if (!asn1_time_to_tm(&tm_to, to))
return 0;
return OPENSSL_gmtime_diff(pday, psec, &tm_from, &tm_to);
}
