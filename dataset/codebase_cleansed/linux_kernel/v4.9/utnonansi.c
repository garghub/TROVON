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
