void acpi_ut_strlwr(char *src_string)
{
char *string;
ACPI_FUNCTION_ENTRY();
if (!src_string) {
return;
}
for (string = src_string; *string; string++) {
*string = (char)ACPI_TOLOWER(*string);
}
return;
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
void acpi_ut_strupr(char *src_string)
{
char *string;
ACPI_FUNCTION_ENTRY();
if (!src_string) {
return;
}
for (string = src_string; *string; string++) {
*string = (char)ACPI_TOUPPER(*string);
}
return;
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
while ((*string) && (ACPI_IS_SPACE(*string) || *string == '\t')) {
string++;
}
if (to_integer_op) {
if ((*string == '0') && (ACPI_TOLOWER(*(string + 1)) == 'x')) {
sign_of0x = 1;
base = 16;
string += 2;
} else {
base = 10;
}
}
if (!(*string) || ACPI_IS_SPACE(*string) || *string == '\t') {
if (to_integer_op) {
goto error_exit;
} else {
goto all_done;
}
}
dividend = (mode32) ? ACPI_UINT32_MAX : ACPI_UINT64_MAX;
while (*string) {
if (ACPI_IS_DIGIT(*string)) {
this_digit = ((u8)*string) - '0';
} else if (base == 10) {
term = 1;
} else {
this_digit = (u8)ACPI_TOUPPER(*string);
if (ACPI_IS_XDIGIT((char)this_digit)) {
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
void acpi_ut_print_string(char *string, u8 max_length)
{
u32 i;
if (!string) {
acpi_os_printf("<\"NULL STRING PTR\">");
return;
}
acpi_os_printf("\"");
for (i = 0; string[i] && (i < max_length); i++) {
switch (string[i]) {
case 0x07:
acpi_os_printf("\\a");
break;
case 0x08:
acpi_os_printf("\\b");
break;
case 0x0C:
acpi_os_printf("\\f");
break;
case 0x0A:
acpi_os_printf("\\n");
break;
case 0x0D:
acpi_os_printf("\\r");
break;
case 0x09:
acpi_os_printf("\\t");
break;
case 0x0B:
acpi_os_printf("\\v");
break;
case '\'':
case '\"':
case '\\':
acpi_os_printf("\\%c", (int)string[i]);
break;
default:
if (ACPI_IS_PRINT(string[i])) {
acpi_os_printf("%c", (int)string[i]);
} else {
acpi_os_printf("\\x%2.2X", (s32) string[i]);
}
break;
}
}
acpi_os_printf("\"");
if (i == max_length && string[i]) {
acpi_os_printf("...");
}
}
u8 acpi_ut_valid_acpi_char(char character, u32 position)
{
if (!((character >= 'A' && character <= 'Z') ||
(character >= '0' && character <= '9') || (character == '_'))) {
if (character == '!' && position == 3) {
return (TRUE);
}
return (FALSE);
}
return (TRUE);
}
u8 acpi_ut_valid_acpi_name(u32 name)
{
u32 i;
ACPI_FUNCTION_ENTRY();
for (i = 0; i < ACPI_NAME_SIZE; i++) {
if (!acpi_ut_valid_acpi_char
((ACPI_CAST_PTR(char, &name))[i], i)) {
return (FALSE);
}
}
return (TRUE);
}
void acpi_ut_repair_name(char *name)
{
u32 i;
u8 found_bad_char = FALSE;
u32 original_name;
ACPI_FUNCTION_NAME(ut_repair_name);
ACPI_MOVE_NAME(&original_name, name);
for (i = 0; i < ACPI_NAME_SIZE; i++) {
if (acpi_ut_valid_acpi_char(name[i], i)) {
continue;
}
name[i] = '*';
found_bad_char = TRUE;
}
if (found_bad_char) {
if (!acpi_gbl_enable_interpreter_slack) {
ACPI_WARNING((AE_INFO,
"Invalid character(s) in name (0x%.8X), repaired: [%4.4s]",
original_name, name));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Invalid character(s) in name (0x%.8X), repaired: [%4.4s]",
original_name, name));
}
}
}
void ut_convert_backslashes(char *pathname)
{
if (!pathname) {
return;
}
while (*pathname) {
if (*pathname == '\\') {
*pathname = '/';
}
pathname++;
}
}
