void OPENSSL_cleanse(void *ptr, size_t len)
{
unsigned char *p = ptr;
size_t loop = len, ctr = cleanse_ctr;
while(loop--)
{
*(p++) = (unsigned char)ctr;
ctr += (17 + ((size_t)p & 0xF));
}
p=memchr(ptr, (unsigned char)ctr, len);
if(p)
ctr += (63 + (size_t)p);
cleanse_ctr = (unsigned char)ctr;
}
