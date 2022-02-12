ASN1_TIME *ASN1_TIME_set(ASN1_TIME *s, time_t t)
{
struct tm *ts;
struct tm data;
ts=OPENSSL_gmtime(&t,&data);
if (ts == NULL)
{
ASN1err(ASN1_F_ASN1_TIME_SET, ASN1_R_ERROR_GETTING_TIME);
return NULL;
}
if((ts->tm_year >= 50) && (ts->tm_year < 150))
return ASN1_UTCTIME_set(s, t);
return ASN1_GENERALIZEDTIME_set(s,t);
}
int ASN1_TIME_check(ASN1_TIME *t)
{
if (t->type == V_ASN1_GENERALIZEDTIME)
return ASN1_GENERALIZEDTIME_check(t);
else if (t->type == V_ASN1_UTCTIME)
return ASN1_UTCTIME_check(t);
return 0;
}
ASN1_GENERALIZEDTIME *ASN1_TIME_to_generalizedtime(ASN1_TIME *t, ASN1_GENERALIZEDTIME **out)
{
ASN1_GENERALIZEDTIME *ret;
char *str;
int newlen;
if (!ASN1_TIME_check(t)) return NULL;
if (!out || !*out)
{
if (!(ret = ASN1_GENERALIZEDTIME_new ()))
return NULL;
if (out) *out = ret;
}
else ret = *out;
if (t->type == V_ASN1_GENERALIZEDTIME)
{
if(!ASN1_STRING_set(ret, t->data, t->length))
return NULL;
return ret;
}
if (!ASN1_STRING_set(ret, NULL, t->length + 2))
return NULL;
newlen = t->length + 2 + 1;
str = (char *)ret->data;
if (t->data[0] >= '5') BUF_strlcpy(str, "19", newlen);
else BUF_strlcpy(str, "20", newlen);
BUF_strlcat(str, (char *)t->data, newlen);
return ret;
}
