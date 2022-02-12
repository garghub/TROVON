int asn1_generalizedtime_to_tm(struct tm *tm, const ASN1_GENERALIZEDTIME *d)
{
static const int min[9] = { 0, 0, 1, 1, 0, 0, 0, 0, 0 };
static const int max[9] = { 99, 99, 12, 31, 23, 59, 59, 12, 59 };
char *a;
int n, i, l, o;
if (d->type != V_ASN1_GENERALIZEDTIME)
return (0);
l = d->length;
a = (char *)d->data;
o = 0;
if (l < 13)
goto err;
for (i = 0; i < 7; i++) {
if ((i == 6) && ((a[o] == 'Z') || (a[o] == '+') || (a[o] == '-'))) {
i++;
if (tm)
tm->tm_sec = 0;
break;
}
if ((a[o] < '0') || (a[o] > '9'))
goto err;
n = a[o] - '0';
if (++o > l)
goto err;
if ((a[o] < '0') || (a[o] > '9'))
goto err;
n = (n * 10) + a[o] - '0';
if (++o > l)
goto err;
if ((n < min[i]) || (n > max[i]))
goto err;
if (tm) {
switch (i) {
case 0:
tm->tm_year = n * 100 - 1900;
break;
case 1:
tm->tm_year += n;
break;
case 2:
tm->tm_mon = n - 1;
break;
case 3:
tm->tm_mday = n;
break;
case 4:
tm->tm_hour = n;
break;
case 5:
tm->tm_min = n;
break;
case 6:
tm->tm_sec = n;
break;
}
}
}
if (a[o] == '.') {
if (++o > l)
goto err;
i = o;
while ((a[o] >= '0') && (a[o] <= '9') && (o <= l))
o++;
if (i == o)
goto err;
}
if (a[o] == 'Z')
o++;
else if ((a[o] == '+') || (a[o] == '-')) {
int offsign = a[o] == '-' ? -1 : 1, offset = 0;
o++;
if (o + 4 > l)
goto err;
for (i = 7; i < 9; i++) {
if ((a[o] < '0') || (a[o] > '9'))
goto err;
n = a[o] - '0';
o++;
if ((a[o] < '0') || (a[o] > '9'))
goto err;
n = (n * 10) + a[o] - '0';
if ((n < min[i]) || (n > max[i]))
goto err;
if (tm) {
if (i == 7)
offset = n * 3600;
else if (i == 8)
offset += n * 60;
}
o++;
}
if (offset && !OPENSSL_gmtime_adj(tm, 0, offset * offsign))
return 0;
} else if (a[o]) {
goto err;
}
return (o == l);
err:
return (0);
}
int ASN1_GENERALIZEDTIME_check(const ASN1_GENERALIZEDTIME *d)
{
return asn1_generalizedtime_to_tm(NULL, d);
}
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s, const char *str)
{
ASN1_GENERALIZEDTIME t;
t.type = V_ASN1_GENERALIZEDTIME;
t.length = strlen(str);
t.data = (unsigned char *)str;
if (ASN1_GENERALIZEDTIME_check(&t)) {
if (s != NULL) {
if (!ASN1_STRING_set((ASN1_STRING *)s,
(unsigned char *)str, t.length))
return 0;
s->type = V_ASN1_GENERALIZEDTIME;
}
return (1);
} else
return (0);
}
ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_set(ASN1_GENERALIZEDTIME *s,
time_t t)
{
return ASN1_GENERALIZEDTIME_adj(s, t, 0, 0);
}
ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_adj(ASN1_GENERALIZEDTIME *s,
time_t t, int offset_day,
long offset_sec)
{
char *p;
struct tm *ts;
struct tm data;
size_t len = 20;
if (s == NULL)
s = M_ASN1_GENERALIZEDTIME_new();
if (s == NULL)
return (NULL);
ts = OPENSSL_gmtime(&t, &data);
if (ts == NULL)
return (NULL);
if (offset_day || offset_sec) {
if (!OPENSSL_gmtime_adj(ts, offset_day, offset_sec))
return NULL;
}
p = (char *)s->data;
if ((p == NULL) || ((size_t)s->length < len)) {
p = OPENSSL_malloc(len);
if (p == NULL) {
ASN1err(ASN1_F_ASN1_GENERALIZEDTIME_ADJ, ERR_R_MALLOC_FAILURE);
return (NULL);
}
if (s->data != NULL)
OPENSSL_free(s->data);
s->data = (unsigned char *)p;
}
BIO_snprintf(p, len, "%04d%02d%02d%02d%02d%02dZ", ts->tm_year + 1900,
ts->tm_mon + 1, ts->tm_mday, ts->tm_hour, ts->tm_min,
ts->tm_sec);
s->length = strlen(p);
s->type = V_ASN1_GENERALIZEDTIME;
#ifdef CHARSET_EBCDIC_not
ebcdic2ascii(s->data, s->data, s->length);
#endif
return (s);
}
