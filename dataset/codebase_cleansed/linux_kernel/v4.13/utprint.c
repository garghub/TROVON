static acpi_size
acpi_ut_bound_string_length(const char *string, acpi_size count)
{
u32 length = 0;
while (*string && count) {
length++;
string++;
count--;
}
return (length);
}
static char *acpi_ut_bound_string_output(char *string, const char *end, char c)
{
if (string < end) {
*string = c;
}
++string;
return (string);
}
static char *acpi_ut_put_number(char *string, u64 number, u8 base, u8 upper)
{
const char *digits;
u64 digit_index;
char *pos;
pos = string;
digits = upper ? acpi_gbl_upper_hex_digits : acpi_gbl_lower_hex_digits;
if (number == 0) {
*(pos++) = '0';
} else {
while (number) {
(void)acpi_ut_divide(number, base, &number,
&digit_index);
*(pos++) = digits[digit_index];
}
}
return (pos);
}
const char *acpi_ut_scan_number(const char *string, u64 *number_ptr)
{
u64 number = 0;
while (isdigit((int)*string)) {
number *= 10;
number += *(string++) - '0';
}
*number_ptr = number;
return (string);
}
const char *acpi_ut_print_number(char *string, u64 number)
{
char ascii_string[20];
const char *pos1;
char *pos2;
pos1 = acpi_ut_put_number(ascii_string, number, 10, FALSE);
pos2 = string;
while (pos1 != ascii_string) {
*(pos2++) = *(--pos1);
}
*pos2 = 0;
return (string);
}
static char *acpi_ut_format_number(char *string,
char *end,
u64 number,
u8 base, s32 width, s32 precision, u8 type)
{
char *pos;
char sign;
char zero;
u8 need_prefix;
u8 upper;
s32 i;
char reversed_string[66];
if (base < 2 || base > 16) {
return (NULL);
}
if (type & ACPI_FORMAT_LEFT) {
type &= ~ACPI_FORMAT_ZERO;
}
need_prefix = ((type & ACPI_FORMAT_PREFIX)
&& base != 10) ? TRUE : FALSE;
upper = (type & ACPI_FORMAT_UPPER) ? TRUE : FALSE;
zero = (type & ACPI_FORMAT_ZERO) ? '0' : ' ';
sign = '\0';
if (type & ACPI_FORMAT_SIGN) {
if ((s64)number < 0) {
sign = '-';
number = -(s64)number;
width--;
} else if (type & ACPI_FORMAT_SIGN_PLUS) {
sign = '+';
width--;
} else if (type & ACPI_FORMAT_SIGN_PLUS_SPACE) {
sign = ' ';
width--;
}
}
if (need_prefix) {
width--;
if (base == 16) {
width--;
}
}
pos = acpi_ut_put_number(reversed_string, number, base, upper);
i = ACPI_PTR_DIFF(pos, reversed_string);
if (i > precision) {
precision = i;
}
width -= precision;
if (!(type & (ACPI_FORMAT_ZERO | ACPI_FORMAT_LEFT))) {
while (--width >= 0) {
string = acpi_ut_bound_string_output(string, end, ' ');
}
}
if (sign) {
string = acpi_ut_bound_string_output(string, end, sign);
}
if (need_prefix) {
string = acpi_ut_bound_string_output(string, end, '0');
if (base == 16) {
string =
acpi_ut_bound_string_output(string, end,
upper ? 'X' : 'x');
}
}
if (!(type & ACPI_FORMAT_LEFT)) {
while (--width >= 0) {
string = acpi_ut_bound_string_output(string, end, zero);
}
}
while (i <= --precision) {
string = acpi_ut_bound_string_output(string, end, '0');
}
while (--i >= 0) {
string = acpi_ut_bound_string_output(string, end,
reversed_string[i]);
}
while (--width >= 0) {
string = acpi_ut_bound_string_output(string, end, ' ');
}
return (string);
}
int vsnprintf(char *string, acpi_size size, const char *format, va_list args)
{
u8 base;
u8 type;
s32 width;
s32 precision;
char qualifier;
u64 number;
char *pos;
char *end;
char c;
const char *s;
const void *p;
s32 length;
int i;
pos = string;
end = string + size;
for (; *format; ++format) {
if (*format != '%') {
pos = acpi_ut_bound_string_output(pos, end, *format);
continue;
}
type = 0;
base = 10;
do {
++format;
if (*format == '#') {
type |= ACPI_FORMAT_PREFIX;
} else if (*format == '0') {
type |= ACPI_FORMAT_ZERO;
} else if (*format == '+') {
type |= ACPI_FORMAT_SIGN_PLUS;
} else if (*format == ' ') {
type |= ACPI_FORMAT_SIGN_PLUS_SPACE;
} else if (*format == '-') {
type |= ACPI_FORMAT_LEFT;
} else {
break;
}
} while (1);
width = -1;
if (isdigit((int)*format)) {
format = acpi_ut_scan_number(format, &number);
width = (s32)number;
} else if (*format == '*') {
++format;
width = va_arg(args, int);
if (width < 0) {
width = -width;
type |= ACPI_FORMAT_LEFT;
}
}
precision = -1;
if (*format == '.') {
++format;
if (isdigit((int)*format)) {
format = acpi_ut_scan_number(format, &number);
precision = (s32)number;
} else if (*format == '*') {
++format;
precision = va_arg(args, int);
}
if (precision < 0) {
precision = 0;
}
}
qualifier = -1;
if (*format == 'h' || *format == 'l' || *format == 'L') {
qualifier = *format;
++format;
if (qualifier == 'l' && *format == 'l') {
qualifier = 'L';
++format;
}
}
switch (*format) {
case '%':
pos = acpi_ut_bound_string_output(pos, end, '%');
continue;
case 'c':
if (!(type & ACPI_FORMAT_LEFT)) {
while (--width > 0) {
pos =
acpi_ut_bound_string_output(pos,
end,
' ');
}
}
c = (char)va_arg(args, int);
pos = acpi_ut_bound_string_output(pos, end, c);
while (--width > 0) {
pos =
acpi_ut_bound_string_output(pos, end, ' ');
}
continue;
case 's':
s = va_arg(args, char *);
if (!s) {
s = "<NULL>";
}
length = acpi_ut_bound_string_length(s, precision);
if (!(type & ACPI_FORMAT_LEFT)) {
while (length < width--) {
pos =
acpi_ut_bound_string_output(pos,
end,
' ');
}
}
for (i = 0; i < length; ++i) {
pos = acpi_ut_bound_string_output(pos, end, *s);
++s;
}
while (length < width--) {
pos =
acpi_ut_bound_string_output(pos, end, ' ');
}
continue;
case 'o':
base = 8;
break;
case 'X':
type |= ACPI_FORMAT_UPPER;
case 'x':
base = 16;
break;
case 'd':
case 'i':
type |= ACPI_FORMAT_SIGN;
case 'u':
break;
case 'p':
if (width == -1) {
width = 2 * sizeof(void *);
type |= ACPI_FORMAT_ZERO;
}
p = va_arg(args, void *);
pos =
acpi_ut_format_number(pos, end, ACPI_TO_INTEGER(p),
16, width, precision, type);
continue;
default:
pos = acpi_ut_bound_string_output(pos, end, '%');
if (*format) {
pos =
acpi_ut_bound_string_output(pos, end,
*format);
} else {
--format;
}
continue;
}
if (qualifier == 'L') {
number = va_arg(args, u64);
if (type & ACPI_FORMAT_SIGN) {
number = (s64)number;
}
} else if (qualifier == 'l') {
number = va_arg(args, unsigned long);
if (type & ACPI_FORMAT_SIGN) {
number = (s32)number;
}
} else if (qualifier == 'h') {
number = (u16)va_arg(args, int);
if (type & ACPI_FORMAT_SIGN) {
number = (s16)number;
}
} else {
number = va_arg(args, unsigned int);
if (type & ACPI_FORMAT_SIGN) {
number = (signed int)number;
}
}
pos = acpi_ut_format_number(pos, end, number, base,
width, precision, type);
}
if (size > 0) {
if (pos < end) {
*pos = '\0';
} else {
end[-1] = '\0';
}
}
return (ACPI_PTR_DIFF(pos, string));
}
int snprintf(char *string, acpi_size size, const char *format, ...)
{
va_list args;
int length;
va_start(args, format);
length = vsnprintf(string, size, format, args);
va_end(args);
return (length);
}
int sprintf(char *string, const char *format, ...)
{
va_list args;
int length;
va_start(args, format);
length = vsnprintf(string, ACPI_UINT32_MAX, format, args);
va_end(args);
return (length);
}
int vprintf(const char *format, va_list args)
{
acpi_cpu_flags flags;
int length;
flags = acpi_os_acquire_lock(acpi_gbl_print_lock);
length = vsnprintf(acpi_gbl_print_buffer,
sizeof(acpi_gbl_print_buffer), format, args);
(void)fwrite(acpi_gbl_print_buffer, length, 1, ACPI_FILE_OUT);
acpi_os_release_lock(acpi_gbl_print_lock, flags);
return (length);
}
int printf(const char *format, ...)
{
va_list args;
int length;
va_start(args, format);
length = vprintf(format, args);
va_end(args);
return (length);
}
int vfprintf(FILE * file, const char *format, va_list args)
{
acpi_cpu_flags flags;
int length;
flags = acpi_os_acquire_lock(acpi_gbl_print_lock);
length = vsnprintf(acpi_gbl_print_buffer,
sizeof(acpi_gbl_print_buffer), format, args);
(void)fwrite(acpi_gbl_print_buffer, length, 1, file);
acpi_os_release_lock(acpi_gbl_print_lock, flags);
return (length);
}
int fprintf(FILE * file, const char *format, ...)
{
va_list args;
int length;
va_start(args, format);
length = vfprintf(file, format, args);
va_end(args);
return (length);
}
