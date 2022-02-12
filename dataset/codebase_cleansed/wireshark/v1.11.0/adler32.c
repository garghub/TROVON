guint32 update_adler32(guint32 adler, const guint8 *buf, size_t len)
{
guint32 s1 = adler & 0xffff;
guint32 s2 = (adler >> 16) & 0xffff;
size_t n;
for (n = 0; n < len; n++) {
s1 = (s1 + buf[n]) % BASE;
s2 = (s2 + s1) % BASE;
}
return (s2 << 16) + s1;
}
guint32 adler32_bytes(const guint8 *buf, size_t len)
{
return update_adler32(1, buf, len);
}
guint32 adler32_str(const char *buf)
{
return update_adler32(1, (const guint8*)buf, strlen(buf));
}
