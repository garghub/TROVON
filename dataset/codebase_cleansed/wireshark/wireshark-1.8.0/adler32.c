unsigned long update_adler32(unsigned long adler, const unsigned char *buf, int len)
{
unsigned long s1 = adler & 0xffff;
unsigned long s2 = (adler >> 16) & 0xffff;
int n;
for (n = 0; n < len; n++) {
s1 = (s1 + buf[n]) % BASE;
s2 = (s2 + s1) % BASE;
}
return (s2 << 16) + s1;
}
unsigned long adler32_bytes(const unsigned char *buf, int len)
{
return update_adler32(1L, buf, len);
}
unsigned long adler32_str(const char *buf)
{
return update_adler32(1L, (const unsigned char*)buf, (int)strlen(buf));
}
