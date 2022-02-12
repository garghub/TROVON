int i2d_ASN1_TIME(ASN1_TIME *a, unsigned char **pp)
{
if(a->type == V_ASN1_UTCTIME || a->type == V_ASN1_GENERALIZEDTIME)
return(i2d_ASN1_bytes((ASN1_STRING *)a,pp,
a->type ,V_ASN1_UNIVERSAL));
ASN1err(ASN1_F_I2D_ASN1_TIME,ASN1_R_EXPECTING_A_TIME);
return -1;
}
ASN1_TIME *d2i_ASN1_TIME(ASN1_TIME **a, unsigned char **pp, long length)
{
unsigned char tag;
tag = **pp & ~V_ASN1_CONSTRUCTED;
if(tag == (V_ASN1_UTCTIME|V_ASN1_UNIVERSAL))
return d2i_ASN1_UTCTIME(a, pp, length);
if(tag == (V_ASN1_GENERALIZEDTIME|V_ASN1_UNIVERSAL))
return d2i_ASN1_GENERALIZEDTIME(a, pp, length);
ASN1err(ASN1_F_D2I_ASN1_TIME,ASN1_R_EXPECTING_A_TIME);
return(NULL);
}
ASN1_TIME *ASN1_TIME_set(ASN1_TIME *s, time_t t)
{
struct tm *ts;
#if defined(THREADS) && !defined(WIN32)
struct tm data;
#endif
#if defined(THREADS) && !defined(WIN32)
gmtime_r(&t,&data);
ts=&data;
#else
ts=gmtime(&t);
#endif
if((ts->tm_year >= 50) && (ts->tm_year < 150))
return ASN1_UTCTIME_set(s, t);
return ASN1_GENERALIZEDTIME_set(s,t);
}
