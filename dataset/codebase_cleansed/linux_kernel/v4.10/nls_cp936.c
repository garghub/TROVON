static int uni2char(const wchar_t uni,
unsigned char *out, int boundlen)
{
const unsigned char *uni2charset;
unsigned char cl = uni&0xFF;
unsigned char ch = (uni>>8)&0xFF;
unsigned char out0,out1;
if (boundlen <= 0)
return -ENAMETOOLONG;
if (uni == 0x20ac) {
out[0] = 0x80;
return 1;
}
if (ch == 0) {
out0 = u2c_00[cl*2];
out1 = u2c_00[cl*2+1];
if (out0 == 0x00 && out1 == 0x00) {
if (cl<0x80) {
out[0] = cl;
return 1;
}
return -EINVAL;
} else {
if (boundlen <= 1)
return -ENAMETOOLONG;
out[0] = out0;
out[1] = out1;
return 2;
}
}
uni2charset = page_uni2charset[ch];
if (uni2charset) {
if (boundlen <= 1)
return -ENAMETOOLONG;
out[0] = uni2charset[cl*2];
out[1] = uni2charset[cl*2+1];
if (out[0] == 0x00 && out[1] == 0x00)
return -EINVAL;
return 2;
}
else
return -EINVAL;
}
static int char2uni(const unsigned char *rawstring, int boundlen,
wchar_t *uni)
{
unsigned char ch, cl;
const wchar_t *charset2uni;
int n;
if (boundlen <= 0)
return -ENAMETOOLONG;
if (boundlen == 1) {
if (rawstring[0]==0x80) {
*uni = 0x20ac;
} else {
*uni = rawstring[0];
}
return 1;
}
ch = rawstring[0];
cl = rawstring[1];
charset2uni = page_charset2uni[ch];
if (charset2uni && cl) {
*uni = charset2uni[cl];
if (*uni == 0x0000)
return -EINVAL;
n = 2;
} else{
if (ch==0x80) {
*uni = 0x20ac;
} else {
*uni = ch;
}
n = 1;
}
return n;
}
static int __init init_nls_cp936(void)
{
return register_nls(&table);
}
static void __exit exit_nls_cp936(void)
{
unregister_nls(&table);
}
