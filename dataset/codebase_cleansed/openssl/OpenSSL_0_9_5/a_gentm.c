ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_new(void)
{ return M_ASN1_GENERALIZEDTIME_new(); }
void ASN1_GENERALIZEDTIME_free(ASN1_GENERALIZEDTIME *x)
{ M_ASN1_GENERALIZEDTIME_free(x); }
int i2d_ASN1_GENERALIZEDTIME(ASN1_GENERALIZEDTIME *a, unsigned char **pp)
{
#ifdef CHARSET_EBCDIC
int len;
char tmp[24];
ASN1_STRING tmpstr = *(ASN1_STRING *)a;
len = tmpstr.length;
ebcdic2ascii(tmp, tmpstr.data, (len >= sizeof tmp) ? sizeof tmp : len);
tmpstr.data = tmp;
a = (ASN1_GENERALIZEDTIME *) &tmpstr;
#endif
return(i2d_ASN1_bytes((ASN1_STRING *)a,pp,
V_ASN1_GENERALIZEDTIME,V_ASN1_UNIVERSAL));
}
ASN1_GENERALIZEDTIME *d2i_ASN1_GENERALIZEDTIME(ASN1_GENERALIZEDTIME **a,
unsigned char **pp, long length)
{
ASN1_GENERALIZEDTIME *ret=NULL;
ret=(ASN1_GENERALIZEDTIME *)d2i_ASN1_bytes((ASN1_STRING **)a,pp,length,
V_ASN1_GENERALIZEDTIME,V_ASN1_UNIVERSAL);
if (ret == NULL)
{
ASN1err(ASN1_F_D2I_ASN1_GENERALIZEDTIME,ERR_R_NESTED_ASN1_ERROR);
return(NULL);
}
#ifdef CHARSET_EBCDIC
ascii2ebcdic(ret->data, ret->data, ret->length);
#endif
if (!ASN1_GENERALIZEDTIME_check(ret))
{
ASN1err(ASN1_F_D2I_ASN1_GENERALIZEDTIME,ASN1_R_INVALID_TIME_FORMAT);
goto err;
}
return(ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
M_ASN1_GENERALIZEDTIME_free(ret);
return(NULL);
}
int ASN1_GENERALIZEDTIME_check(ASN1_GENERALIZEDTIME *d)
{
static int min[9]={ 0, 0, 1, 1, 0, 0, 0, 0, 0};
static int max[9]={99, 99,12,31,23,59,59,12,59};
char *a;
int n,i,l,o;
if (d->type != V_ASN1_GENERALIZEDTIME) return(0);
l=d->length;
a=(char *)d->data;
o=0;
if (l < 13) goto err;
for (i=0; i<7; i++)
{
if ((i == 6) && ((a[o] == 'Z') ||
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
for (i=7; i<9; i++)
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
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s, char *str)
{
ASN1_GENERALIZEDTIME t;
t.type=V_ASN1_GENERALIZEDTIME;
t.length=strlen(str);
t.data=(unsigned char *)str;
if (ASN1_GENERALIZEDTIME_check(&t))
{
if (s != NULL)
{
ASN1_STRING_set((ASN1_STRING *)s,
(unsigned char *)str,t.length);
}
return(1);
}
else
return(0);
}
ASN1_GENERALIZEDTIME *ASN1_GENERALIZEDTIME_set(ASN1_GENERALIZEDTIME *s,
time_t t)
{
char *p;
struct tm *ts;
#if defined(THREADS) && !defined(WIN32)
struct tm data;
#endif
if (s == NULL)
s=M_ASN1_GENERALIZEDTIME_new();
if (s == NULL)
return(NULL);
#if defined(THREADS) && !defined(WIN32)
gmtime_r(&t,&data);
ts=&data;
#else
ts=gmtime(&t);
#endif
p=(char *)s->data;
if ((p == NULL) || (s->length < 16))
{
p=Malloc(20);
if (p == NULL) return(NULL);
if (s->data != NULL)
Free(s->data);
s->data=(unsigned char *)p;
}
sprintf(p,"%04d%02d%02d%02d%02d%02dZ",ts->tm_year + 1900,
ts->tm_mon+1,ts->tm_mday,ts->tm_hour,ts->tm_min,ts->tm_sec);
s->length=strlen(p);
s->type=V_ASN1_GENERALIZEDTIME;
#ifdef CHARSET_EBCDIC_not
ebcdic2ascii(s->data, s->data, s->length);
#endif
return(s);
}
