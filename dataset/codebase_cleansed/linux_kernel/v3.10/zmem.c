void exit (void)
{
for (;;);
}
void *zalloc(unsigned size)
{
void *p = avail_ram;
size = (size + 7) & -8;
avail_ram += size;
if (avail_ram > end_avail) {
exit ();
}
return p;
}
void gunzip (void *dst, int dstlen, unsigned char *src, int *lenp)
{
z_stream s;
int r, i, flags;
i = 10;
flags = src[3];
if (src[2] != DEFLATED || (flags & RESERVED) != 0) {
exit();
}
if ((flags & EXTRA_FIELD) != 0)
i = 12 + src[10] + (src[11] << 8);
if ((flags & ORIG_NAME) != 0)
while (src[i++] != 0)
;
if ((flags & COMMENT) != 0)
while (src[i++] != 0)
;
if ((flags & HEAD_CRC) != 0)
i += 2;
if (i >= *lenp) {
exit();
}
s.workspace = zalloc(zlib_inflate_workspacesize());
r = zlib_inflateInit2(&s, -MAX_WBITS);
if (r != Z_OK) {
exit();
}
s.next_in = src + i;
s.avail_in = *lenp - i;
s.next_out = dst;
s.avail_out = dstlen;
r = zlib_inflate(&s, Z_FINISH);
if (r != Z_OK && r != Z_STREAM_END) {
exit();
}
*lenp = s.next_out - (unsigned char *) dst;
zlib_inflateEnd(&s);
}
