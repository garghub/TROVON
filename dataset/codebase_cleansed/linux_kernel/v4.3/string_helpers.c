void string_get_size(u64 size, u64 blk_size, const enum string_size_units units,
char *buf, int len)
{
static const char *const units_10[] = {
"B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"
};
static const char *const units_2[] = {
"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"
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
u32 remainder = 0, sf_cap, exp;
char tmp[8];
const char *unit;
tmp[0] = '\0';
i = 0;
if (!size)
goto out;
while (blk_size >= divisor[units]) {
remainder = do_div(blk_size, divisor[units]);
i++;
}
exp = divisor[units] / (u32)blk_size;
if (size > exp) {
remainder = do_div(size, divisor[units]);
remainder *= blk_size;
i++;
} else {
remainder *= size;
}
size *= blk_size;
size += remainder / divisor[units];
remainder %= divisor[units];
while (size >= divisor[units]) {
remainder = do_div(size, divisor[units]);
i++;
}
sf_cap = size;
for (j = 0; sf_cap*10 < 1000; j++)
sf_cap *= 10;
if (j) {
remainder *= 1000;
remainder /= divisor[units];
snprintf(tmp, sizeof(tmp), ".%03u", remainder);
tmp[j+1] = '\0';
}
out:
if (i >= ARRAY_SIZE(units_2))
unit = "UNK";
else
unit = units_str[units][i];
snprintf(buf, len, "%u%s %s", (u32)size,
tmp, unit);
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
static bool escape_passthrough(unsigned char c, char **dst, char *end)
{
char *out = *dst;
if (out < end)
*out = c;
*dst = out + 1;
return true;
}
static bool escape_space(unsigned char c, char **dst, char *end)
{
char *out = *dst;
unsigned char to;
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
return false;
}
if (out < end)
*out = '\\';
++out;
if (out < end)
*out = to;
++out;
*dst = out;
return true;
}
static bool escape_special(unsigned char c, char **dst, char *end)
{
char *out = *dst;
unsigned char to;
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
return false;
}
if (out < end)
*out = '\\';
++out;
if (out < end)
*out = to;
++out;
*dst = out;
return true;
}
static bool escape_null(unsigned char c, char **dst, char *end)
{
char *out = *dst;
if (c)
return false;
if (out < end)
*out = '\\';
++out;
if (out < end)
*out = '0';
++out;
*dst = out;
return true;
}
static bool escape_octal(unsigned char c, char **dst, char *end)
{
char *out = *dst;
if (out < end)
*out = '\\';
++out;
if (out < end)
*out = ((c >> 6) & 0x07) + '0';
++out;
if (out < end)
*out = ((c >> 3) & 0x07) + '0';
++out;
if (out < end)
*out = ((c >> 0) & 0x07) + '0';
++out;
*dst = out;
return true;
}
static bool escape_hex(unsigned char c, char **dst, char *end)
{
char *out = *dst;
if (out < end)
*out = '\\';
++out;
if (out < end)
*out = 'x';
++out;
if (out < end)
*out = hex_asc_hi(c);
++out;
if (out < end)
*out = hex_asc_lo(c);
++out;
*dst = out;
return true;
}
int string_escape_mem(const char *src, size_t isz, char *dst, size_t osz,
unsigned int flags, const char *only)
{
char *p = dst;
char *end = p + osz;
bool is_dict = only && *only;
while (isz--) {
unsigned char c = *src++;
if ((flags & ESCAPE_NP && isprint(c)) ||
(is_dict && !strchr(only, c))) {
} else {
if (flags & ESCAPE_SPACE && escape_space(c, &p, end))
continue;
if (flags & ESCAPE_SPECIAL && escape_special(c, &p, end))
continue;
if (flags & ESCAPE_NULL && escape_null(c, &p, end))
continue;
if (flags & ESCAPE_OCTAL && escape_octal(c, &p, end))
continue;
if (flags & ESCAPE_HEX && escape_hex(c, &p, end))
continue;
}
escape_passthrough(c, &p, end);
}
return p - dst;
}
