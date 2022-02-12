void acpi_ut_print_string(char *string, u16 max_length)
{
u32 i;
if (!string) {
acpi_os_printf("<\"NULL STRING PTR\">");
return;
}
acpi_os_printf("\"");
for (i = 0; (i < max_length) && string[i]; i++) {
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
if (isprint((int)string[i])) {
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
u8 acpi_ut_valid_acpi_name(char *name)
{
u32 i;
ACPI_FUNCTION_ENTRY();
for (i = 0; i < ACPI_NAME_SIZE; i++) {
if (!acpi_ut_valid_acpi_char(name[i], i)) {
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
