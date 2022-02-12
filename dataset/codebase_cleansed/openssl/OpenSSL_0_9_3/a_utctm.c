int i2d_ASN1_UTCTIME(ASN1_UTCTIME *a, unsigned char **pp)
{
return(i2d_ASN1_bytes((ASN1_STRING *)a,pp,
V_ASN1_UTCTIME,V_ASN1_UNIVERSAL));
}
ASN1_UTCTIME *d2i_ASN1_UTCTIME(ASN1_UTCTIME **a, unsigned char **pp,
long length)
{
ASN1_UTCTIME *ret=NULL;
ret=(ASN1_UTCTIME *)d2i_ASN1_bytes((ASN1_STRING **)a,pp,length,
V_ASN1_UTCTIME,V_ASN1_UNIVERSAL);
if (ret == NULL)
{
ASN1err(ASN1_F_D2I_ASN1_UTCTIME,ERR_R_NESTED_ASN1_ERROR);
return(NULL);
}
if (!ASN1_UTCTIME_check(ret))
{
ASN1err(ASN1_F_D2I_ASN1_UTCTIME,ASN1_R_INVALID_TIME_FORMAT);
goto err;
}
return(ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_UTCTIME_free(ret);
return(NULL);
}
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
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s, char *str)
{
ASN1_UTCTIME t;
t.type=V_ASN1_UTCTIME;
t.length=strlen(str);
t.data=(unsigned char *)str;
if (ASN1_UTCTIME_check(&t))
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
ASN1_UTCTIME *ASN1_UTCTIME_set(ASN1_UTCTIME *s, time_t t)
{
char *p;
struct tm *ts;
#if defined(THREADS) && !defined(WIN32)
struct tm data;
#endif
if (s == NULL)
s=ASN1_UTCTIME_new();
if (s == NULL)
return(NULL);
#if defined(THREADS) && !defined(WIN32)
gmtime_r(&t,&data);
ts=&data;
#else
ts=gmtime(&t);
#endif
#ifdef VMS
if (ts == NULL)
{
static $DESCRIPTOR(tabnam,"LNM$DCL_LOGICAL");
static $DESCRIPTOR(lognam,"SYS$TIMEZONE_DIFFERENTIAL");
char result[256];
unsigned int reslen = 0;
struct {
short buflen;
short code;
void *bufaddr;
unsigned int *reslen;
} itemlist[] = {
{ 0, LNM$_STRING, 0, 0 },
{ 0, 0, 0, 0 },
};
int status;
itemlist[0].buflen = sizeof(result);
itemlist[0].bufaddr = result;
itemlist[0].reslen = &reslen;
status = sys$trnlnm(0, &tabnam, &lognam, 0, itemlist);
if (!(status & 1))
return NULL;
result[reslen] = '\0';
status = atoi(result);
t -= status;
ts=(struct tm *)localtime(&t);
}
#endif
p=(char *)s->data;
if ((p == NULL) || (s->length < 14))
{
p=Malloc(20);
if (p == NULL) return(NULL);
if (s->data != NULL)
Free(s->data);
s->data=(unsigned char *)p;
}
sprintf(p,"%02d%02d%02d%02d%02d%02dZ",ts->tm_year%100,
ts->tm_mon+1,ts->tm_mday,ts->tm_hour,ts->tm_min,ts->tm_sec);
s->length=strlen(p);
s->type=V_ASN1_UTCTIME;
return(s);
}
