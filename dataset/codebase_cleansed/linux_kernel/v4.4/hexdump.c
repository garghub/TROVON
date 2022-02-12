int hex_to_bin(char ch)
{
if ((ch >= '0') && (ch <= '9'))
return ch - '0';
ch = tolower(ch);
if ((ch >= 'a') && (ch <= 'f'))
return ch - 'a' + 10;
return -1;
}
int hex2bin(u8 *dst, const char *src, size_t count)
{
while (count--) {
int hi = hex_to_bin(*src++);
int lo = hex_to_bin(*src++);
if ((hi < 0) || (lo < 0))
return -1;
*dst++ = (hi << 4) | lo;
}
return 0;
}
char *bin2hex(char *dst, const void *src, size_t count)
{
const unsigned char *_src = src;
while (count--)
dst = hex_byte_pack(dst, *_src++);
return dst;
}
int hex_dump_to_buffer(const void *buf, size_t len, int rowsize, int groupsize,
char *linebuf, size_t linebuflen, bool ascii)
{
const u8 *ptr = buf;
int ngroups;
u8 ch;
int j, lx = 0;
int ascii_column;
int ret;
if (rowsize != 16 && rowsize != 32)
rowsize = 16;
if (len > rowsize)
len = rowsize;
if (!is_power_of_2(groupsize) || groupsize > 8)
groupsize = 1;
if ((len % groupsize) != 0)
groupsize = 1;
ngroups = len / groupsize;
ascii_column = rowsize * 2 + rowsize / groupsize + 1;
if (!linebuflen)
goto overflow1;
if (!len)
goto nil;
if (groupsize == 8) {
const u64 *ptr8 = buf;
for (j = 0; j < ngroups; j++) {
ret = snprintf(linebuf + lx, linebuflen - lx,
"%s%16.16llx", j ? " " : "",
get_unaligned(ptr8 + j));
if (ret >= linebuflen - lx)
goto overflow1;
lx += ret;
}
} else if (groupsize == 4) {
const u32 *ptr4 = buf;
for (j = 0; j < ngroups; j++) {
ret = snprintf(linebuf + lx, linebuflen - lx,
"%s%8.8x", j ? " " : "",
get_unaligned(ptr4 + j));
if (ret >= linebuflen - lx)
goto overflow1;
lx += ret;
}
} else if (groupsize == 2) {
const u16 *ptr2 = buf;
for (j = 0; j < ngroups; j++) {
ret = snprintf(linebuf + lx, linebuflen - lx,
"%s%4.4x", j ? " " : "",
get_unaligned(ptr2 + j));
if (ret >= linebuflen - lx)
goto overflow1;
lx += ret;
}
} else {
for (j = 0; j < len; j++) {
if (linebuflen < lx + 2)
goto overflow2;
ch = ptr[j];
linebuf[lx++] = hex_asc_hi(ch);
if (linebuflen < lx + 2)
goto overflow2;
linebuf[lx++] = hex_asc_lo(ch);
if (linebuflen < lx + 2)
goto overflow2;
linebuf[lx++] = ' ';
}
if (j)
lx--;
}
if (!ascii)
goto nil;
while (lx < ascii_column) {
if (linebuflen < lx + 2)
goto overflow2;
linebuf[lx++] = ' ';
}
for (j = 0; j < len; j++) {
if (linebuflen < lx + 2)
goto overflow2;
ch = ptr[j];
linebuf[lx++] = (isascii(ch) && isprint(ch)) ? ch : '.';
}
nil:
linebuf[lx] = '\0';
return lx;
overflow2:
linebuf[lx++] = '\0';
overflow1:
return ascii ? ascii_column + len : (groupsize * 2 + 1) * ngroups - 1;
}
void print_hex_dump(const char *level, const char *prefix_str, int prefix_type,
int rowsize, int groupsize,
const void *buf, size_t len, bool ascii)
{
const u8 *ptr = buf;
int i, linelen, remaining = len;
unsigned char linebuf[32 * 3 + 2 + 32 + 1];
if (rowsize != 16 && rowsize != 32)
rowsize = 16;
for (i = 0; i < len; i += rowsize) {
linelen = min(remaining, rowsize);
remaining -= rowsize;
hex_dump_to_buffer(ptr + i, linelen, rowsize, groupsize,
linebuf, sizeof(linebuf), ascii);
switch (prefix_type) {
case DUMP_PREFIX_ADDRESS:
printk("%s%s%p: %s\n",
level, prefix_str, ptr + i, linebuf);
break;
case DUMP_PREFIX_OFFSET:
printk("%s%s%.8x: %s\n", level, prefix_str, i, linebuf);
break;
default:
printk("%s%s%s\n", level, prefix_str, linebuf);
break;
}
}
}
void print_hex_dump_bytes(const char *prefix_str, int prefix_type,
const void *buf, size_t len)
{
print_hex_dump(KERN_DEBUG, prefix_str, prefix_type, 16, 1,
buf, len, true);
}
