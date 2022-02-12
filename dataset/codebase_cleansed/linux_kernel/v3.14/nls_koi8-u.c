static int uni2char(wchar_t uni, unsigned char *out, int boundlen)
{
const unsigned char *uni2charset;
unsigned char cl = uni & 0x00ff;
unsigned char ch = (uni & 0xff00) >> 8;
if (boundlen <= 0)
return -ENAMETOOLONG;
uni2charset = page_uni2charset[ch];
if (uni2charset && uni2charset[cl])
out[0] = uni2charset[cl];
else
return -EINVAL;
return 1;
}
static int char2uni(const unsigned char *rawstring, int boundlen, wchar_t *uni)
{
*uni = charset2uni[*rawstring];
if (*uni == 0x0000)
return -EINVAL;
return 1;
}
static int __init init_nls_koi8_u(void)
{
return register_nls(&table);
}
static void __exit exit_nls_koi8_u(void)
{
unregister_nls(&table);
}
