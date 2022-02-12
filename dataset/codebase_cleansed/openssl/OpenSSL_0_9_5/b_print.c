int BIO_printf (BIO *bio, ...)
{
va_list args;
char *format;
int ret;
size_t retlen;
MS_STATIC char hugebuf[1024*2];
va_start(args, bio);
format=va_arg(args, char *);
hugebuf[0]='\0';
dopr(hugebuf, sizeof(hugebuf), &retlen, format, args);
ret=BIO_write(bio, hugebuf, (int)retlen);
va_end(args);
return(ret);
}
static void
dopr(
char *buffer,
size_t maxlen,
size_t *retlen,
const char *format,
va_list args)
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
if ((ch == '\0') || (currlen >= maxlen))
state = DP_S_DONE;
switch (state) {
case DP_S_DEFAULT:
if (ch == '%')
state = DP_S_FLAGS;
else
dopr_outch(buffer, &currlen, maxlen, ch);
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
fmtint(buffer, &currlen, maxlen, value, 10, min, max, flags);
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
value = (LLONG) va_arg(args,
unsigned long int);
break;
case DP_C_LLONG:
value = va_arg(args, unsigned LLONG);
break;
default:
value = (LLONG) va_arg(args,
unsigned int);
break;
}
fmtint(buffer, &currlen, maxlen, value,
ch == 'o' ? 8 : (ch == 'u' ? 10 : 16),
min, max, flags);
break;
case 'f':
if (cflags == DP_C_LDOUBLE)
fvalue = va_arg(args, LDOUBLE);
else
fvalue = va_arg(args, double);
fmtfp(buffer, &currlen, maxlen, fvalue, min, max, flags);
break;
case 'E':
flags |= DP_F_UP;
case 'e':
if (cflags == DP_C_LDOUBLE)
fvalue = va_arg(args, LDOUBLE);
else
fvalue = va_arg(args, double);
break;
case 'G':
flags |= DP_F_UP;
case 'g':
if (cflags == DP_C_LDOUBLE)
fvalue = va_arg(args, LDOUBLE);
else
fvalue = va_arg(args, double);
break;
case 'c':
dopr_outch(buffer, &currlen, maxlen,
va_arg(args, int));
break;
case 's':
strvalue = va_arg(args, char *);
if (max < 0)
max = maxlen;
fmtstr(buffer, &currlen, maxlen, strvalue,
flags, min, max);
break;
case 'p':
value = (long)va_arg(args, void *);
fmtint(buffer, &currlen, maxlen,
value, 16, min, max, flags);
break;
case 'n':
if (cflags == DP_C_SHORT) {
short int *num;
num = va_arg(args, short int *);
*num = currlen;
} else if (cflags == DP_C_LONG) {
long int *num;
num = va_arg(args, long int *);
*num = (long int) currlen;
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
dopr_outch(buffer, &currlen, maxlen, ch);
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
if (currlen >= maxlen - 1)
currlen = maxlen - 1;
buffer[currlen] = '\0';
*retlen = currlen;
return;
}
static void
fmtstr(
char *buffer,
size_t *currlen,
size_t maxlen,
char *value,
int flags,
int min,
int max)
{
int padlen, strln;
int cnt = 0;
if (value == 0)
value = "<NULL>";
for (strln = 0; value[strln]; ++strln)
;
padlen = min - strln;
if (padlen < 0)
padlen = 0;
if (flags & DP_F_MINUS)
padlen = -padlen;
while ((padlen > 0) && (cnt < max)) {
dopr_outch(buffer, currlen, maxlen, ' ');
--padlen;
++cnt;
}
while (*value && (cnt < max)) {
dopr_outch(buffer, currlen, maxlen, *value++);
++cnt;
}
while ((padlen < 0) && (cnt < max)) {
dopr_outch(buffer, currlen, maxlen, ' ');
++padlen;
++cnt;
}
}
static void
fmtint(
char *buffer,
size_t *currlen,
size_t maxlen,
LLONG value,
int base,
int min,
int max,
int flags)
{
int signvalue = 0;
unsigned LLONG uvalue;
char convert[20];
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
uvalue = -value;
} else if (flags & DP_F_PLUS)
signvalue = '+';
else if (flags & DP_F_SPACE)
signvalue = ' ';
}
if (flags & DP_F_UP)
caps = 1;
do {
convert[place++] =
(caps ? "0123456789ABCDEF" : "0123456789abcdef")
[uvalue % (unsigned) base];
uvalue = (uvalue / (unsigned) base);
} while (uvalue && (place < 20));
if (place == 20)
place--;
convert[place] = 0;
zpadlen = max - place;
spadlen = min - MAX(max, place) - (signvalue ? 1 : 0);
if (zpadlen < 0)
zpadlen = 0;
if (spadlen < 0)
spadlen = 0;
if (flags & DP_F_ZERO) {
zpadlen = MAX(zpadlen, spadlen);
spadlen = 0;
}
if (flags & DP_F_MINUS)
spadlen = -spadlen;
while (spadlen > 0) {
dopr_outch(buffer, currlen, maxlen, ' ');
--spadlen;
}
if (signvalue)
dopr_outch(buffer, currlen, maxlen, signvalue);
if (zpadlen > 0) {
while (zpadlen > 0) {
dopr_outch(buffer, currlen, maxlen, '0');
--zpadlen;
}
}
while (place > 0)
dopr_outch(buffer, currlen, maxlen, convert[--place]);
while (spadlen < 0) {
dopr_outch(buffer, currlen, maxlen, ' ');
++spadlen;
}
return;
}
static LDOUBLE
abs_val(LDOUBLE value)
{
LDOUBLE result = value;
if (value < 0)
result = -value;
return result;
}
static LDOUBLE
pow10(int exp)
{
LDOUBLE result = 1;
while (exp) {
result *= 10;
exp--;
}
return result;
}
static long
round(LDOUBLE value)
{
long intpart;
intpart = (long) value;
value = value - intpart;
if (value >= 0.5)
intpart++;
return intpart;
}
static void
fmtfp(
char *buffer,
size_t *currlen,
size_t maxlen,
LDOUBLE fvalue,
int min,
int max,
int flags)
{
int signvalue = 0;
LDOUBLE ufvalue;
char iconvert[20];
char fconvert[20];
int iplace = 0;
int fplace = 0;
int padlen = 0;
int zpadlen = 0;
int caps = 0;
long intpart;
long fracpart;
if (max < 0)
max = 6;
ufvalue = abs_val(fvalue);
if (fvalue < 0)
signvalue = '-';
else if (flags & DP_F_PLUS)
signvalue = '+';
else if (flags & DP_F_SPACE)
signvalue = ' ';
intpart = (long)ufvalue;
if (max > 9)
max = 9;
fracpart = round((pow10(max)) * (ufvalue - intpart));
if (fracpart >= pow10(max)) {
intpart++;
fracpart -= (long)pow10(max);
}
do {
iconvert[iplace++] =
(caps ? "0123456789ABCDEF"
: "0123456789abcdef")[intpart % 10];
intpart = (intpart / 10);
} while (intpart && (iplace < 20));
if (iplace == 20)
iplace--;
iconvert[iplace] = 0;
do {
fconvert[fplace++] =
(caps ? "0123456789ABCDEF"
: "0123456789abcdef")[fracpart % 10];
fracpart = (fracpart / 10);
} while (fracpart && (fplace < 20));
if (fplace == 20)
fplace--;
fconvert[fplace] = 0;
padlen = min - iplace - max - 1 - ((signvalue) ? 1 : 0);
zpadlen = max - fplace;
if (zpadlen < 0)
zpadlen = 0;
if (padlen < 0)
padlen = 0;
if (flags & DP_F_MINUS)
padlen = -padlen;
if ((flags & DP_F_ZERO) && (padlen > 0)) {
if (signvalue) {
dopr_outch(buffer, currlen, maxlen, signvalue);
--padlen;
signvalue = 0;
}
while (padlen > 0) {
dopr_outch(buffer, currlen, maxlen, '0');
--padlen;
}
}
while (padlen > 0) {
dopr_outch(buffer, currlen, maxlen, ' ');
--padlen;
}
if (signvalue)
dopr_outch(buffer, currlen, maxlen, signvalue);
while (iplace > 0)
dopr_outch(buffer, currlen, maxlen, iconvert[--iplace]);
if (max > 0) {
dopr_outch(buffer, currlen, maxlen, '.');
while (fplace > 0)
dopr_outch(buffer, currlen, maxlen, fconvert[--fplace]);
}
while (zpadlen > 0) {
dopr_outch(buffer, currlen, maxlen, '0');
--zpadlen;
}
while (padlen < 0) {
dopr_outch(buffer, currlen, maxlen, ' ');
++padlen;
}
}
static void
dopr_outch(
char *buffer,
size_t *currlen,
size_t maxlen,
int c)
{
if (*currlen < maxlen)
buffer[(*currlen)++] = (char)c;
return;
}
