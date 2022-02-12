int string_get_size(u64 size, const enum string_size_units units,
char *buf, int len)
{
static const char *const units_10[] = {
"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB", NULL
};
static const char *const units_2[] = {
"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB",
NULL
};
static const char *const *const units_str[] = {
[STRING_UNITS_10] = units_10,
[STRING_UNITS_2] = units_2,
};
static const unsigned int divisor[] = {
[STRING_UNITS_10] = 1000,
[STRING_UNITS_2] = 1024,
};
int i, j;
u64 remainder = 0, sf_cap;
char tmp[8];
tmp[0] = '\0';
i = 0;
if (size >= divisor[units]) {
while (size >= divisor[units] && units_str[units][i]) {
remainder = do_div(size, divisor[units]);
i++;
}
sf_cap = size;
for (j = 0; sf_cap*10 < 1000; j++)
sf_cap *= 10;
if (j) {
remainder *= 1000;
do_div(remainder, divisor[units]);
snprintf(tmp, sizeof(tmp), ".%03lld",
(unsigned long long)remainder);
tmp[j+1] = '\0';
}
}
snprintf(buf, len, "%lld%s %s", (unsigned long long)size,
tmp, units_str[units][i]);
return 0;
}
static bool unescape_space(char **src, char **dst)
{
char *p = *dst, *q = *src;
switch (*q) {
case 'n':
*p = '\n';
break;
case 'r':
*p = '\r';
break;
case 't':
*p = '\t';
break;
case 'v':
*p = '\v';
break;
case 'f':
*p = '\f';
break;
default:
return false;
}
*dst += 1;
*src += 1;
return true;
}
static bool unescape_octal(char **src, char **dst)
{
char *p = *dst, *q = *src;
u8 num;
if (isodigit(*q) == 0)
return false;
num = (*q++) & 7;
while (num < 32 && isodigit(*q) && (q - *src < 3)) {
num <<= 3;
num += (*q++) & 7;
}
*p = num;
*dst += 1;
*src = q;
return true;
}
static bool unescape_hex(char **src, char **dst)
{
char *p = *dst, *q = *src;
int digit;
u8 num;
if (*q++ != 'x')
return false;
num = digit = hex_to_bin(*q++);
if (digit < 0)
return false;
digit = hex_to_bin(*q);
if (digit >= 0) {
q++;
num = (num << 4) | digit;
}
*p = num;
*dst += 1;
*src = q;
return true;
}
static bool unescape_special(char **src, char **dst)
{
char *p = *dst, *q = *src;
switch (*q) {
case '\"':
*p = '\"';
break;
case '\\':
*p = '\\';
break;
case 'a':
*p = '\a';
break;
case 'e':
*p = '\e';
break;
default:
return false;
}
*dst += 1;
*src += 1;
return true;
}
int string_unescape(char *src, char *dst, size_t size, unsigned int flags)
{
char *out = dst;
while (*src && --size) {
if (src[0] == '\\' && src[1] != '\0' && size > 1) {
src++;
size--;
if (flags & UNESCAPE_SPACE &&
unescape_space(&src, &out))
continue;
if (flags & UNESCAPE_OCTAL &&
unescape_octal(&src, &out))
continue;
if (flags & UNESCAPE_HEX &&
unescape_hex(&src, &out))
continue;
if (flags & UNESCAPE_SPECIAL &&
unescape_special(&src, &out))
continue;
*out++ = '\\';
}
*out++ = *src++;
}
*out = '\0';
return out - dst;
}
static int escape_passthrough(unsigned char c, char **dst, size_t *osz)
{
char *out = *dst;
if (*osz < 1)
return -ENOMEM;
*out++ = c;
*dst = out;
*osz -= 1;
return 1;
}
static int escape_space(unsigned char c, char **dst, size_t *osz)
{
char *out = *dst;
unsigned char to;
if (*osz < 2)
return -ENOMEM;
switch (c) {
case '\n':
to = 'n';
break;
case '\r':
to = 'r';
break;
case '\t':
to = 't';
break;
case '\v':
to = 'v';
break;
case '\f':
to = 'f';
break;
default:
return 0;
}
*out++ = '\\';
*out++ = to;
*dst = out;
*osz -= 2;
return 1;
}
static int escape_special(unsigned char c, char **dst, size_t *osz)
{
char *out = *dst;
unsigned char to;
if (*osz < 2)
return -ENOMEM;
switch (c) {
case '\\':
to = '\\';
break;
case '\a':
to = 'a';
break;
case '\e':
to = 'e';
break;
default:
return 0;
}
*out++ = '\\';
*out++ = to;
*dst = out;
*osz -= 2;
return 1;
}
static int escape_null(unsigned char c, char **dst, size_t *osz)
{
char *out = *dst;
if (*osz < 2)
return -ENOMEM;
if (c)
return 0;
*out++ = '\\';
*out++ = '0';
*dst = out;
*osz -= 2;
return 1;
}
static int escape_octal(unsigned char c, char **dst, size_t *osz)
{
char *out = *dst;
if (*osz < 4)
return -ENOMEM;
*out++ = '\\';
*out++ = ((c >> 6) & 0x07) + '0';
*out++ = ((c >> 3) & 0x07) + '0';
*out++ = ((c >> 0) & 0x07) + '0';
*dst = out;
*osz -= 4;
return 1;
}
static int escape_hex(unsigned char c, char **dst, size_t *osz)
{
char *out = *dst;
if (*osz < 4)
return -ENOMEM;
*out++ = '\\';
*out++ = 'x';
*out++ = hex_asc_hi(c);
*out++ = hex_asc_lo(c);
*dst = out;
*osz -= 4;
return 1;
}
int string_escape_mem(const char *src, size_t isz, char **dst, size_t osz,
unsigned int flags, const char *esc)
{
char *out = *dst, *p = out;
bool is_dict = esc && *esc;
int ret = 0;
while (isz--) {
unsigned char c = *src++;
if ((flags & ESCAPE_NP && isprint(c)) ||
(is_dict && !strchr(esc, c))) {
} else {
if (flags & ESCAPE_SPACE) {
ret = escape_space(c, &p, &osz);
if (ret < 0)
break;
if (ret > 0)
continue;
}
if (flags & ESCAPE_SPECIAL) {
ret = escape_special(c, &p, &osz);
if (ret < 0)
break;
if (ret > 0)
continue;
}
if (flags & ESCAPE_NULL) {
ret = escape_null(c, &p, &osz);
if (ret < 0)
break;
if (ret > 0)
continue;
}
if (flags & ESCAPE_OCTAL) {
ret = escape_octal(c, &p, &osz);
if (ret < 0)
break;
continue;
}
if (flags & ESCAPE_HEX) {
ret = escape_hex(c, &p, &osz);
if (ret < 0)
break;
continue;
}
}
ret = escape_passthrough(c, &p, &osz);
if (ret < 0)
break;
}
*dst = p;
if (ret < 0)
return ret;
return p - out;
}
