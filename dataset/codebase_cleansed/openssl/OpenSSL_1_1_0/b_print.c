static int
_dopr(char **sbuffer,
char **buffer,
size_t *maxlen,
size_t *retlen, int *truncated, const char *format, va_list args)
{
char ch;
LLONG value;
LDOUBLE fvalue;
char *strvalue;
int min;
int max;
int state;
int flags;
int cflags;
size_t currlen;
state = DP_S_DEFAULT;
flags = currlen = cflags = min = 0;
max = -1;
ch = *format++;
while (state != DP_S_DONE) {
if (ch == '\0' || (buffer == NULL && currlen >= *maxlen))
state = DP_S_DONE;
switch (state) {
case DP_S_DEFAULT:
if (ch == '%')
state = DP_S_FLAGS;
else
if(!doapr_outch(sbuffer, buffer, &currlen, maxlen, ch))
return 0;
ch = *format++;
break;
case DP_S_FLAGS:
switch (ch) {
case '-':
flags |= DP_F_MINUS;
ch = *format++;
break;
case '+':
flags |= DP_F_PLUS;
ch = *format++;
break;
case ' ':
flags |= DP_F_SPACE;
ch = *format++;
break;
case '#':
flags |= DP_F_NUM;
ch = *format++;
break;
case '0':
flags |= DP_F_ZERO;
ch = *format++;
break;
default:
state = DP_S_MIN;
break;
}
break;
case DP_S_MIN:
if (isdigit((unsigned char)ch)) {
min = 10 * min + char_to_int(ch);
ch = *format++;
} else if (ch == '*') {
min = va_arg(args, int);
ch = *format++;
state = DP_S_DOT;
} else
state = DP_S_DOT;
break;
case DP_S_DOT:
if (ch == '.') {
state = DP_S_MAX;
ch = *format++;
} else
state = DP_S_MOD;
break;
case DP_S_MAX:
if (isdigit((unsigned char)ch)) {
if (max < 0)
max = 0;
max = 10 * max + char_to_int(ch);
ch = *format++;
} else if (ch == '*') {
max = va_arg(args, int);
ch = *format++;
state = DP_S_MOD;
} else
state = DP_S_MOD;
break;
case DP_S_MOD:
switch (ch) {
case 'h':
cflags = DP_C_SHORT;
ch = *format++;
break;
case 'l':
if (*format == 'l') {
cflags = DP_C_LLONG;
format++;
} else
cflags = DP_C_LONG;
ch = *format++;
break;
case 'q':
cflags = DP_C_LLONG;
ch = *format++;
break;
case 'L':
cflags = DP_C_LDOUBLE;
ch = *format++;
break;
default:
break;
}
state = DP_S_CONV;
break;
case DP_S_CONV:
switch (ch) {
case 'd':
case 'i':
switch (cflags) {
case DP_C_SHORT:
value = (short int)va_arg(args, int);
break;
case DP_C_LONG:
value = va_arg(args, long int);
break;
case DP_C_LLONG:
value = va_arg(args, LLONG);
break;
default:
value = va_arg(args, int);
break;
}
if (!fmtint(sbuffer, buffer, &currlen, maxlen, value, 10, min,
max, flags))
return 0;
break;
case 'X':
flags |= DP_F_UP;
case 'x':
case 'o':
case 'u':
flags |= DP_F_UNSIGNED;
switch (cflags) {
case DP_C_SHORT:
value = (unsigned short int)va_arg(args, unsigned int);
break;
case DP_C_LONG:
value = (LLONG) va_arg(args, unsigned long int);
break;
case DP_C_LLONG:
value = va_arg(args, unsigned LLONG);
break;
default:
value = (LLONG) va_arg(args, unsigned int);
break;
}
if (!fmtint(sbuffer, buffer, &currlen, maxlen, value,
ch == 'o' ? 8 : (ch == 'u' ? 10 : 16),
min, max, flags))
return 0;
break;
case 'f':
if (cflags == DP_C_LDOUBLE)
fvalue = va_arg(args, LDOUBLE);
else
fvalue = va_arg(args, double);
if (!fmtfp(sbuffer, buffer, &currlen, maxlen, fvalue, min, max,
flags, F_FORMAT))
return 0;
break;
case 'E':
flags |= DP_F_UP;
case 'e':
if (cflags == DP_C_LDOUBLE)
fvalue = va_arg(args, LDOUBLE);
else
fvalue = va_arg(args, double);
if (!fmtfp(sbuffer, buffer, &currlen, maxlen, fvalue, min, max,
flags, E_FORMAT))
return 0;
break;
case 'G':
flags |= DP_F_UP;
case 'g':
if (cflags == DP_C_LDOUBLE)
fvalue = va_arg(args, LDOUBLE);
else
fvalue = va_arg(args, double);
if (!fmtfp(sbuffer, buffer, &currlen, maxlen, fvalue, min, max,
flags, G_FORMAT))
return 0;
break;
case 'c':
if(!doapr_outch(sbuffer, buffer, &currlen, maxlen,
va_arg(args, int)))
return 0;
break;
case 's':
strvalue = va_arg(args, char *);
if (max < 0) {
if (buffer)
max = INT_MAX;
else
max = *maxlen;
}
if (!fmtstr(sbuffer, buffer, &currlen, maxlen, strvalue,
flags, min, max))
return 0;
break;
case 'p':
value = (size_t)va_arg(args, void *);
if (!fmtint(sbuffer, buffer, &currlen, maxlen,
value, 16, min, max, flags | DP_F_NUM))
return 0;
break;
case 'n':
if (cflags == DP_C_SHORT) {
short int *num;
num = va_arg(args, short int *);
*num = currlen;
} else if (cflags == DP_C_LONG) {
long int *num;
num = va_arg(args, long int *);
*num = (long int)currlen;
} else if (cflags == DP_C_LLONG) {
LLONG *num;
num = va_arg(args, LLONG *);
*num = (LLONG) currlen;
} else {
int *num;
num = va_arg(args, int *);
*num = currlen;
}
break;
case '%':
if(!doapr_outch(sbuffer, buffer, &currlen, maxlen, ch))
return 0;
break;
case 'w':
ch = *format++;
break;
default:
break;
}
ch = *format++;
state = DP_S_DEFAULT;
flags = cflags = min = 0;
max = -1;
break;
case DP_S_DONE:
break;
default:
break;
}
}
if (buffer == NULL) {
*truncated = (currlen > *maxlen - 1);
if (*truncated)
currlen = *maxlen - 1;
}
if(!doapr_outch(sbuffer, buffer, &currlen, maxlen, '\0'))
return 0;
*retlen = currlen - 1;
return 1;
}
static int
fmtstr(char **sbuffer,
char **buffer,
size_t *currlen,
size_t *maxlen, const char *value, int flags, int min, int max)
{
int padlen;
size_t strln;
int cnt = 0;
if (value == 0)
value = "<NULL>";
strln = OPENSSL_strnlen(value, max < 0 ? SIZE_MAX : (size_t)max);
padlen = min - strln;
if (min < 0 || padlen < 0)
padlen = 0;
if (max >= 0) {
if (max < INT_MAX - padlen)
max += padlen;
else
max = INT_MAX;
}
if (flags & DP_F_MINUS)
padlen = -padlen;
while ((padlen > 0) && (max < 0 || cnt < max)) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, ' '))
return 0;
--padlen;
++cnt;
}
while (strln > 0 && (max < 0 || cnt < max)) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, *value++))
return 0;
--strln;
++cnt;
}
while ((padlen < 0) && (max < 0 || cnt < max)) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, ' '))
return 0;
++padlen;
++cnt;
}
return 1;
}
static int
fmtint(char **sbuffer,
char **buffer,
size_t *currlen,
size_t *maxlen, LLONG value, int base, int min, int max, int flags)
{
int signvalue = 0;
const char *prefix = "";
unsigned LLONG uvalue;
char convert[DECIMAL_SIZE(value) + 3];
int place = 0;
int spadlen = 0;
int zpadlen = 0;
int caps = 0;
if (max < 0)
max = 0;
uvalue = value;
if (!(flags & DP_F_UNSIGNED)) {
if (value < 0) {
signvalue = '-';
uvalue = -(unsigned LLONG)value;
} else if (flags & DP_F_PLUS)
signvalue = '+';
else if (flags & DP_F_SPACE)
signvalue = ' ';
}
if (flags & DP_F_NUM) {
if (base == 8)
prefix = "0";
if (base == 16)
prefix = "0x";
}
if (flags & DP_F_UP)
caps = 1;
do {
convert[place++] = (caps ? "0123456789ABCDEF" : "0123456789abcdef")
[uvalue % (unsigned)base];
uvalue = (uvalue / (unsigned)base);
} while (uvalue && (place < (int)sizeof(convert)));
if (place == sizeof(convert))
place--;
convert[place] = 0;
zpadlen = max - place;
spadlen =
min - OSSL_MAX(max, place) - (signvalue ? 1 : 0) - strlen(prefix);
if (zpadlen < 0)
zpadlen = 0;
if (spadlen < 0)
spadlen = 0;
if (flags & DP_F_ZERO) {
zpadlen = OSSL_MAX(zpadlen, spadlen);
spadlen = 0;
}
if (flags & DP_F_MINUS)
spadlen = -spadlen;
while (spadlen > 0) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, ' '))
return 0;
--spadlen;
}
if (signvalue)
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, signvalue))
return 0;
while (*prefix) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, *prefix))
return 0;
prefix++;
}
if (zpadlen > 0) {
while (zpadlen > 0) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen, '0'))
return 0;
--zpadlen;
}
}
while (place > 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, convert[--place]))
return 0;
}
while (spadlen < 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, ' '))
return 0;
++spadlen;
}
return 1;
}
static LDOUBLE abs_val(LDOUBLE value)
{
LDOUBLE result = value;
if (value < 0)
result = -value;
return result;
}
static LDOUBLE pow_10(int in_exp)
{
LDOUBLE result = 1;
while (in_exp) {
result *= 10;
in_exp--;
}
return result;
}
static long roundv(LDOUBLE value)
{
long intpart;
intpart = (long)value;
value = value - intpart;
if (value >= 0.5)
intpart++;
return intpart;
}
static int
fmtfp(char **sbuffer,
char **buffer,
size_t *currlen,
size_t *maxlen, LDOUBLE fvalue, int min, int max, int flags, int style)
{
int signvalue = 0;
LDOUBLE ufvalue;
LDOUBLE tmpvalue;
char iconvert[20];
char fconvert[20];
char econvert[20];
int iplace = 0;
int fplace = 0;
int eplace = 0;
int padlen = 0;
int zpadlen = 0;
long exp = 0;
unsigned long intpart;
unsigned long fracpart;
unsigned long max10;
int realstyle;
if (max < 0)
max = 6;
if (fvalue < 0)
signvalue = '-';
else if (flags & DP_F_PLUS)
signvalue = '+';
else if (flags & DP_F_SPACE)
signvalue = ' ';
if (style == G_FORMAT) {
if (fvalue == 0.0) {
realstyle = F_FORMAT;
} else if (fvalue < 0.0001) {
realstyle = E_FORMAT;
} else if ((max == 0 && fvalue >= 10)
|| (max > 0 && fvalue >= pow_10(max))) {
realstyle = E_FORMAT;
} else {
realstyle = F_FORMAT;
}
} else {
realstyle = style;
}
if (style != F_FORMAT) {
tmpvalue = fvalue;
if (fvalue != 0.0) {
while (tmpvalue < 1) {
tmpvalue *= 10;
exp--;
}
while (tmpvalue > 10) {
tmpvalue /= 10;
exp++;
}
}
if (style == G_FORMAT) {
if (max == 0)
max = 1;
if (realstyle == F_FORMAT) {
max -= (exp + 1);
if (max < 0) {
return 0;
}
} else {
max--;
}
}
if (realstyle == E_FORMAT)
fvalue = tmpvalue;
}
ufvalue = abs_val(fvalue);
if (ufvalue > ULONG_MAX) {
return 0;
}
intpart = (unsigned long)ufvalue;
if (max > 9)
max = 9;
max10 = roundv(pow_10(max));
fracpart = roundv(pow_10(max) * (ufvalue - intpart));
if (fracpart >= max10) {
intpart++;
fracpart -= max10;
}
do {
iconvert[iplace++] = "0123456789"[intpart % 10];
intpart = (intpart / 10);
} while (intpart && (iplace < (int)sizeof(iconvert)));
if (iplace == sizeof iconvert)
iplace--;
iconvert[iplace] = 0;
while (fplace < max) {
if (style == G_FORMAT && fplace == 0 && (fracpart % 10) == 0) {
max--;
fracpart = fracpart / 10;
if (fplace < max)
continue;
break;
}
fconvert[fplace++] = "0123456789"[fracpart % 10];
fracpart = (fracpart / 10);
}
if (fplace == sizeof fconvert)
fplace--;
fconvert[fplace] = 0;
if (realstyle == E_FORMAT) {
int tmpexp;
if (exp < 0)
tmpexp = -exp;
else
tmpexp = exp;
do {
econvert[eplace++] = "0123456789"[tmpexp % 10];
tmpexp = (tmpexp / 10);
} while (tmpexp > 0 && eplace < (int)sizeof(econvert));
if (tmpexp > 0)
return 0;
if (eplace == 1)
econvert[eplace++] = '0';
}
padlen = min - iplace - max - (max > 0 ? 1 : 0) - ((signvalue) ? 1 : 0);
if (realstyle == E_FORMAT)
padlen -= 2 + eplace;
zpadlen = max - fplace;
if (zpadlen < 0)
zpadlen = 0;
if (padlen < 0)
padlen = 0;
if (flags & DP_F_MINUS)
padlen = -padlen;
if ((flags & DP_F_ZERO) && (padlen > 0)) {
if (signvalue) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, signvalue))
return 0;
--padlen;
signvalue = 0;
}
while (padlen > 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, '0'))
return 0;
--padlen;
}
}
while (padlen > 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, ' '))
return 0;
--padlen;
}
if (signvalue && !doapr_outch(sbuffer, buffer, currlen, maxlen, signvalue))
return 0;
while (iplace > 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, iconvert[--iplace]))
return 0;
}
if (max > 0 || (flags & DP_F_NUM)) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, '.'))
return 0;
while (fplace > 0) {
if(!doapr_outch(sbuffer, buffer, currlen, maxlen,
fconvert[--fplace]))
return 0;
}
}
while (zpadlen > 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, '0'))
return 0;
--zpadlen;
}
if (realstyle == E_FORMAT) {
char ech;
if ((flags & DP_F_UP) == 0)
ech = 'e';
else
ech = 'E';
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, ech))
return 0;
if (exp < 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, '-'))
return 0;
} else {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, '+'))
return 0;
}
while (eplace > 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen,
econvert[--eplace]))
return 0;
}
}
while (padlen < 0) {
if (!doapr_outch(sbuffer, buffer, currlen, maxlen, ' '))
return 0;
++padlen;
}
return 1;
}
static int
doapr_outch(char **sbuffer,
char **buffer, size_t *currlen, size_t *maxlen, int c)
{
OPENSSL_assert(*sbuffer != NULL || buffer != NULL);
OPENSSL_assert(*currlen <= *maxlen);
if (buffer && *currlen == *maxlen) {
if (*maxlen > INT_MAX - BUFFER_INC)
return 0;
*maxlen += BUFFER_INC;
if (*buffer == NULL) {
*buffer = OPENSSL_malloc(*maxlen);
if (*buffer == NULL)
return 0;
if (*currlen > 0) {
OPENSSL_assert(*sbuffer != NULL);
memcpy(*buffer, *sbuffer, *currlen);
}
*sbuffer = NULL;
} else {
char *tmpbuf;
tmpbuf = OPENSSL_realloc(*buffer, *maxlen);
if (tmpbuf == NULL)
return 0;
*buffer = tmpbuf;
}
}
if (*currlen < *maxlen) {
if (*sbuffer)
(*sbuffer)[(*currlen)++] = (char)c;
else
(*buffer)[(*currlen)++] = (char)c;
}
return 1;
}
int BIO_printf(BIO *bio, const char *format, ...)
{
va_list args;
int ret;
va_start(args, format);
ret = BIO_vprintf(bio, format, args);
va_end(args);
return (ret);
}
int BIO_vprintf(BIO *bio, const char *format, va_list args)
{
int ret;
size_t retlen;
char hugebuf[1024 * 2];
char *hugebufp = hugebuf;
size_t hugebufsize = sizeof(hugebuf);
char *dynbuf = NULL;
int ignored;
dynbuf = NULL;
if (!_dopr(&hugebufp, &dynbuf, &hugebufsize, &retlen, &ignored, format,
args)) {
OPENSSL_free(dynbuf);
return -1;
}
if (dynbuf) {
ret = BIO_write(bio, dynbuf, (int)retlen);
OPENSSL_free(dynbuf);
} else {
ret = BIO_write(bio, hugebuf, (int)retlen);
}
return (ret);
}
int BIO_snprintf(char *buf, size_t n, const char *format, ...)
{
va_list args;
int ret;
va_start(args, format);
ret = BIO_vsnprintf(buf, n, format, args);
va_end(args);
return (ret);
}
int BIO_vsnprintf(char *buf, size_t n, const char *format, va_list args)
{
size_t retlen;
int truncated;
if(!_dopr(&buf, NULL, &n, &retlen, &truncated, format, args))
return -1;
if (truncated)
return -1;
else
return (retlen <= INT_MAX) ? (int)retlen : -1;
}
