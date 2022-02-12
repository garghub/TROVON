static int uni2char(const wchar_t uni,
unsigned char *out, int boundlen)
{
const unsigned char *uni2charset;
unsigned char cl = uni&0xFF;
unsigned char ch = (uni>>8)&0xFF;
int n;
if (boundlen <= 0)
return -ENAMETOOLONG;
uni2charset = page_uni2charset[ch];
if (uni2charset) {
if (boundlen <= 1)
return -ENAMETOOLONG;
out[0] = uni2charset[cl*2];
out[1] = uni2charset[cl*2+1];
if (out[0] == 0x00 && out[1] == 0x00)
return -EINVAL;
n = 2;
} else if (ch==0 && cl) {
out[0] = cl;
n = 1;
}
else
return -EINVAL;
return n;
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
*uni = rawstring[0];
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
*uni = ch;
n = 1;
}
return n;
}
static int __init init_nls_cp950(void)
{
return register_nls(&table);
}
static void __exit exit_nls_cp950(void)
{
unregister_nls(&table);
}
