void acpi_ut_strlwr(char *src_string)
{
char *string;
ACPI_FUNCTION_ENTRY();
if (!src_string) {
return;
}
for (string = src_string; *string; string++) {
*string = (char)tolower((int)*string);
}
}
void acpi_ut_strupr(char *src_string)
{
char *string;
ACPI_FUNCTION_ENTRY();
if (!src_string) {
return;
}
for (string = src_string; *string; string++) {
*string = (char)toupper((int)*string);
}
}
int acpi_ut_stricmp(char *string1, char *string2)
{
int c1;
int c2;
do {
c1 = tolower((int)*string1);
c2 = tolower((int)*string2);
string1++;
string2++;
}
while ((c1 == c2) && (c1));
return (c1 - c2);
}
acpi_status acpi_ut_strtoul64(char *string, u32 base, u64 *ret_integer)
{
u32 this_digit = 0;
u64 return_value = 0;
u64 quotient;
u64 dividend;
u32 to_integer_op = (base == ACPI_ANY_BASE);
u32 mode32 = (acpi_gbl_integer_byte_width == 4);
u8 valid_digits = 0;
u8 sign_of0x = 0;
u8 term = 0;
ACPI_FUNCTION_TRACE_STR(ut_stroul64, string);
switch (base) {
case ACPI_ANY_BASE:
case 16:
break;
default:
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (!string) {
goto error_exit;
}
while ((*string) && (isspace((int)*string) || *string == '\t')) {
string++;
}
if (to_integer_op) {
if ((*string == '0') && (tolower((int)*(string + 1)) == 'x')) {
sign_of0x = 1;
base = 16;
string += 2;
} else {
base = 10;
}
}
if (!(*string) || isspace((int)*string) || *string == '\t') {
if (to_integer_op) {
goto error_exit;
} else {
goto all_done;
}
}
dividend = (mode32) ? ACPI_UINT32_MAX : ACPI_UINT64_MAX;
while (*string) {
if (isdigit((int)*string)) {
this_digit = ((u8)*string) - '0';
} else if (base == 10) {
term = 1;
} else {
this_digit = (u8)toupper((int)*string);
if (isxdigit((int)this_digit)) {
this_digit = this_digit - 'A' + 10;
} else {
term = 1;
}
}
if (term) {
if (to_integer_op) {
goto error_exit;
} else {
break;
}
} else if ((valid_digits == 0) && (this_digit == 0)
&& !sign_of0x) {
string++;
continue;
}
valid_digits++;
if (sign_of0x
&& ((valid_digits > 16)
|| ((valid_digits > 8) && mode32))) {
goto error_exit;
}
(void)acpi_ut_short_divide((dividend - (u64)this_digit),
base, &quotient, NULL);
if (return_value > quotient) {
if (to_integer_op) {
goto error_exit;
} else {
break;
}
}
return_value *= base;
return_value += this_digit;
string++;
}
all_done:
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Converted value: %8.8X%8.8X\n",
ACPI_FORMAT_UINT64(return_value)));
*ret_integer = return_value;
return_ACPI_STATUS(AE_OK);
error_exit:
if (base == 10) {
return_ACPI_STATUS(AE_BAD_DECIMAL_CONSTANT);
} else {
return_ACPI_STATUS(AE_BAD_HEX_CONSTANT);
}
}
u8 acpi_ut_safe_strcpy(char *dest, acpi_size dest_size, char *source)
{
if (strlen(source) >= dest_size) {
return (TRUE);
}
strcpy(dest, source);
return (FALSE);
}
u8 acpi_ut_safe_strcat(char *dest, acpi_size dest_size, char *source)
{
if ((strlen(dest) + strlen(source)) >= dest_size) {
return (TRUE);
}
strcat(dest, source);
return (FALSE);
}
u8
acpi_ut_safe_strncat(char *dest,
acpi_size dest_size,
char *source, acpi_size max_transfer_length)
{
acpi_size actual_transfer_length;
actual_transfer_length = ACPI_MIN(max_transfer_length, strlen(source));
if ((strlen(dest) + actual_transfer_length) >= dest_size) {
return (TRUE);
}
strncat(dest, source, max_transfer_length);
return (FALSE);
}
