int ASN1_UTCTIME_check(ASN1_UTCTIME *d)
{
static int min[8]={ 0, 1, 1, 0, 0, 0, 0, 0};
static int max[8]={99,12,31,23,59,59,12,59};
char *a;
int n,i,l,o;
if (d->type != V_ASN1_UTCTIME) return(0);
l=d->length;
a=(char *)d->data;
o=0;
if (l < 11) goto err;
for (i=0; i<6; i++)
{
if ((i == 5) && ((a[o] == 'Z') ||
(a[o] == '+') || (a[o] == '-')))
{ i++; break; }
if ((a[o] < '0') || (a[o] > '9')) goto err;
n= a[o]-'0';
if (++o > l) goto err;
if ((a[o] < '0') || (a[o] > '9')) goto err;
n=(n*10)+ a[o]-'0';
if (++o > l) goto err;
if ((n < min[i]) || (n > max[i])) goto err;
}
if (a[o] == 'Z')
o++;
else if ((a[o] == '+') || (a[o] == '-'))
{
o++;
if (o+4 > l) goto err;
for (i=6; i<8; i++)
{
if ((a[o] < '0') || (a[o] > '9')) goto err;
n= a[o]-'0';
o++;
if ((a[o] < '0') || (a[o] > '9')) goto err;
n=(n*10)+ a[o]-'0';
if ((n < min[i]) || (n > max[i])) goto err;
o++;
}
}
return(o == l);
err:
return(0);
}
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s, const char *str)
{
ASN1_UTCTIME t;
t.type=V_ASN1_UTCTIME;
t.length=strlen(str);
t.data=(unsigned char *)str;
if (ASN1_UTCTIME_check(&t))
{
if (s != NULL)
{
if (!ASN1_STRING_set((ASN1_STRING *)s,
(unsigned char *)str,t.length))
return 0;
s->type = V_ASN1_UTCTIME;
}
return(1);
}
else
return(0);
}
ASN1_UTCTIME *ASN1_UTCTIME_set(ASN1_UTCTIME *s, time_t t)
{
char *p;
struct tm *ts;
struct tm data;
size_t len = 20;
if (s == NULL)
s=M_ASN1_UTCTIME_new();
if (s == NULL)
return(NULL);
ts=OPENSSL_gmtime(&t, &data);
if (ts == NULL)
return(NULL);
p=(char *)s->data;
if ((p == NULL) || ((size_t)s->length < len))
{
p=OPENSSL_malloc(len);
if (p == NULL)
{
ASN1err(ASN1_F_ASN1_UTCTIME_SET,ERR_R_MALLOC_FAILURE);
return(NULL);
}
if (s->data != NULL)
OPENSSL_free(s->data);
s->data=(unsigned char *)p;
}
BIO_snprintf(p,len,"%02d%02d%02d%02d%02d%02dZ",ts->tm_year%100,
ts->tm_mon+1,ts->tm_mday,ts->tm_hour,ts->tm_min,ts->tm_sec);
s->length=strlen(p);
s->type=V_ASN1_UTCTIME;
#ifdef CHARSET_EBCDIC_not
ebcdic2ascii(s->data, s->data, s->length);
#endif
return(s);
}
int ASN1_UTCTIME_cmp_time_t(const ASN1_UTCTIME *s, time_t t)
{
struct tm *tm;
struct tm data;
int offset;
int year;
#define g2(p) (((p)[0]-'0')*10+(p)[1]-'0')
if (s->data[12] == 'Z')
offset=0;
else
{
offset = g2(s->data+13)*60+g2(s->data+15);
if (s->data[12] == '-')
offset = -offset;
}
t -= offset*60;
tm = OPENSSL_gmtime(&t, &data);
#define return_cmp(a,b) if ((a)<(b)) return -1; else if ((a)>(b)) return 1
year = g2(s->data);
if (year < 50)
year += 100;
return_cmp(year, tm->tm_year);
return_cmp(g2(s->data+2) - 1, tm->tm_mon);
return_cmp(g2(s->data+4), tm->tm_mday);
return_cmp(g2(s->data+6), tm->tm_hour);
return_cmp(g2(s->data+8), tm->tm_min);
return_cmp(g2(s->data+10), tm->tm_sec);
#undef g2
#undef return_cmp
return 0;
}
