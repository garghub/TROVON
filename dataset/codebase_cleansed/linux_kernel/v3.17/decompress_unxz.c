static bool memeq(const void *a, const void *b, size_t size)
{
const uint8_t *x = a;
const uint8_t *y = b;
size_t i;
for (i = 0; i < size; ++i)
if (x[i] != y[i])
return false;
return true;
}
static void memzero(void *buf, size_t size)
{
uint8_t *b = buf;
uint8_t *e = b + size;
while (b != e)
*b++ = '\0';
}
void *memmove(void *dest, const void *src, size_t size)
{
uint8_t *d = dest;
const uint8_t *s = src;
size_t i;
if (d < s) {
for (i = 0; i < size; ++i)
d[i] = s[i];
} else if (d > s) {
i = size;
while (i-- > 0)
d[i] = s[i];
}
return dest;
}
STATIC int INIT unxz(unsigned char *in, long in_size,
long (*fill)(void *dest, unsigned long size),
long (*flush)(void *src, unsigned long size),
unsigned char *out, long *in_used,
void (*error)(char *x))
{
struct xz_buf b;
struct xz_dec *s;
enum xz_ret ret;
bool must_free_in = false;
#if XZ_INTERNAL_CRC32
xz_crc32_init();
#endif
if (in_used != NULL)
*in_used = 0;
if (fill == NULL && flush == NULL)
s = xz_dec_init(XZ_SINGLE, 0);
else
s = xz_dec_init(XZ_DYNALLOC, (uint32_t)-1);
if (s == NULL)
goto error_alloc_state;
if (flush == NULL) {
b.out = out;
b.out_size = (size_t)-1;
} else {
b.out_size = XZ_IOBUF_SIZE;
b.out = malloc(XZ_IOBUF_SIZE);
if (b.out == NULL)
goto error_alloc_out;
}
if (in == NULL) {
must_free_in = true;
in = malloc(XZ_IOBUF_SIZE);
if (in == NULL)
goto error_alloc_in;
}
b.in = in;
b.in_pos = 0;
b.in_size = in_size;
b.out_pos = 0;
if (fill == NULL && flush == NULL) {
ret = xz_dec_run(s, &b);
} else {
do {
if (b.in_pos == b.in_size && fill != NULL) {
if (in_used != NULL)
*in_used += b.in_pos;
b.in_pos = 0;
in_size = fill(in, XZ_IOBUF_SIZE);
if (in_size < 0) {
ret = XZ_BUF_ERROR;
break;
}
b.in_size = in_size;
}
ret = xz_dec_run(s, &b);
if (flush != NULL && (b.out_pos == b.out_size
|| (ret != XZ_OK && b.out_pos > 0))) {
if (flush(b.out, b.out_pos) != (long)b.out_pos)
ret = XZ_BUF_ERROR;
b.out_pos = 0;
}
} while (ret == XZ_OK);
if (must_free_in)
free(in);
if (flush != NULL)
free(b.out);
}
if (in_used != NULL)
*in_used += b.in_pos;
xz_dec_end(s);
switch (ret) {
case XZ_STREAM_END:
return 0;
case XZ_MEM_ERROR:
error("XZ decompressor ran out of memory");
break;
case XZ_FORMAT_ERROR:
error("Input is not in the XZ format (wrong magic bytes)");
break;
case XZ_OPTIONS_ERROR:
error("Input was encoded with settings that are not "
"supported by this XZ decoder");
break;
case XZ_DATA_ERROR:
case XZ_BUF_ERROR:
error("XZ-compressed data is corrupt");
break;
default:
error("Bug in the XZ decompressor");
break;
}
return -1;
error_alloc_in:
if (flush != NULL)
free(b.out);
error_alloc_out:
xz_dec_end(s);
error_alloc_state:
error("XZ decompressor ran out of memory");
return -1;
}
