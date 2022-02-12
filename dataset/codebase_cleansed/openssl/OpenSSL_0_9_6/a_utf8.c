ASN1_UTF8STRING *ASN1_UTF8STRING_new(void)
{ return M_ASN1_UTF8STRING_new();}
void ASN1_UTF8STRING_free(ASN1_UTF8STRING *x)
{ M_ASN1_UTF8STRING_free(x);}
int i2d_ASN1_UTF8STRING(ASN1_UTF8STRING *a, unsigned char **pp)
{
return(i2d_ASN1_bytes((ASN1_STRING *)a,pp,
V_ASN1_UTF8STRING,V_ASN1_UNIVERSAL));
}
ASN1_UTF8STRING *d2i_ASN1_UTF8STRING(ASN1_UTF8STRING **a, unsigned char **pp,
long length)
{
ASN1_UTF8STRING *ret=NULL;
ret=(ASN1_UTF8STRING *)d2i_ASN1_bytes((ASN1_STRING **)a,
pp,length,V_ASN1_UTF8STRING,V_ASN1_UNIVERSAL);
if (ret == NULL)
{
ASN1err(ASN1_F_D2I_ASN1_UTF8STRING,ERR_R_NESTED_ASN1_ERROR);
return(NULL);
}
return(ret);
}
int UTF8_getc(const unsigned char *str, int len, unsigned long *val)
{
const unsigned char *p;
unsigned long value;
int ret;
if(len <= 0) return 0;
p = str;
if((*p & 0x80) == 0) {
value = *p++ & 0x7f;
ret = 1;
} else if((*p & 0xe0) == 0xc0) {
if(len < 2) return -1;
if((p[1] & 0xc0) != 0x80) return -3;
value = (*p++ & 0x1f) << 6;
value |= *p++ & 0x3f;
if(value < 0x80) return -4;
ret = 2;
} else if((*p & 0xf0) == 0xe0) {
if(len < 3) return -1;
if( ((p[1] & 0xc0) != 0x80)
|| ((p[2] & 0xc0) != 0x80) ) return -3;
value = (*p++ & 0xf) << 12;
value |= (*p++ & 0x3f) << 6;
value |= *p++ & 0x3f;
if(value < 0x800) return -4;
ret = 3;
} else if((*p & 0xf8) == 0xf0) {
if(len < 4) return -1;
if( ((p[1] & 0xc0) != 0x80)
|| ((p[2] & 0xc0) != 0x80)
|| ((p[3] & 0xc0) != 0x80) ) return -3;
value = ((unsigned long)(*p++ & 0x7)) << 18;
value |= (*p++ & 0x3f) << 12;
value |= (*p++ & 0x3f) << 6;
value |= *p++ & 0x3f;
if(value < 0x10000) return -4;
ret = 4;
} else if((*p & 0xfc) == 0xf8) {
if(len < 5) return -1;
if( ((p[1] & 0xc0) != 0x80)
|| ((p[2] & 0xc0) != 0x80)
|| ((p[3] & 0xc0) != 0x80)
|| ((p[4] & 0xc0) != 0x80) ) return -3;
value = ((unsigned long)(*p++ & 0x3)) << 24;
value |= ((unsigned long)(*p++ & 0x3f)) << 18;
value |= ((unsigned long)(*p++ & 0x3f)) << 12;
value |= (*p++ & 0x3f) << 6;
value |= *p++ & 0x3f;
if(value < 0x200000) return -4;
ret = 5;
} else if((*p & 0xfe) == 0xfc) {
if(len < 6) return -1;
if( ((p[1] & 0xc0) != 0x80)
|| ((p[2] & 0xc0) != 0x80)
|| ((p[3] & 0xc0) != 0x80)
|| ((p[4] & 0xc0) != 0x80)
|| ((p[5] & 0xc0) != 0x80) ) return -3;
value = ((unsigned long)(*p++ & 0x1)) << 30;
value |= ((unsigned long)(*p++ & 0x3f)) << 24;
value |= ((unsigned long)(*p++ & 0x3f)) << 18;
value |= ((unsigned long)(*p++ & 0x3f)) << 12;
value |= (*p++ & 0x3f) << 6;
value |= *p++ & 0x3f;
if(value < 0x4000000) return -4;
ret = 6;
} else return -2;
*val = value;
return ret;
}
int UTF8_putc(unsigned char *str, int len, unsigned long value)
{
if(!str) len = 6;
else if(len <= 0) return -1;
if(value < 0x80) {
if(str) *str = (unsigned char)value;
return 1;
}
if(value < 0x800) {
if(len < 2) return -1;
if(str) {
*str++ = (unsigned char)(((value >> 6) & 0x1f) | 0xc0);
*str = (unsigned char)((value & 0x3f) | 0x80);
}
return 2;
}
if(value < 0x10000) {
if(len < 3) return -1;
if(str) {
*str++ = (unsigned char)(((value >> 12) & 0xf) | 0xe0);
*str++ = (unsigned char)(((value >> 6) & 0x3f) | 0x80);
*str = (unsigned char)((value & 0x3f) | 0x80);
}
return 3;
}
if(value < 0x200000) {
if(len < 4) return -1;
if(str) {
*str++ = (unsigned char)(((value >> 18) & 0x7) | 0xf0);
*str++ = (unsigned char)(((value >> 12) & 0x3f) | 0x80);
*str++ = (unsigned char)(((value >> 6) & 0x3f) | 0x80);
*str = (unsigned char)((value & 0x3f) | 0x80);
}
return 4;
}
if(value < 0x4000000) {
if(len < 5) return -1;
if(str) {
*str++ = (unsigned char)(((value >> 24) & 0x3) | 0xf8);
*str++ = (unsigned char)(((value >> 18) & 0x3f) | 0x80);
*str++ = (unsigned char)(((value >> 12) & 0x3f) | 0x80);
*str++ = (unsigned char)(((value >> 6) & 0x3f) | 0x80);
*str = (unsigned char)((value & 0x3f) | 0x80);
}
return 5;
}
if(len < 6) return -1;
if(str) {
*str++ = (unsigned char)(((value >> 30) & 0x1) | 0xfc);
*str++ = (unsigned char)(((value >> 24) & 0x3f) | 0x80);
*str++ = (unsigned char)(((value >> 18) & 0x3f) | 0x80);
*str++ = (unsigned char)(((value >> 12) & 0x3f) | 0x80);
*str++ = (unsigned char)(((value >> 6) & 0x3f) | 0x80);
*str = (unsigned char)((value & 0x3f) | 0x80);
}
return 6;
}
