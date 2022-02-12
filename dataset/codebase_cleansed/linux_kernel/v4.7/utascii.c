u8 acpi_ut_valid_nameseg(char *name)
{
u32 i;
for (i = 0; i < ACPI_NAME_SIZE; i++) {
if (!acpi_ut_valid_name_char(name[i], i)) {
return (FALSE);
}
}
return (TRUE);
}
u8 acpi_ut_valid_name_char(char character, u32 position)
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
void acpi_ut_check_and_repair_ascii(u8 *name, char *repaired_name, u32 count)
{
u32 i;
for (i = 0; i < count; i++) {
repaired_name[i] = (char)name[i];
if (!name[i]) {
return;
}
if (!isprint(name[i])) {
repaired_name[i] = ' ';
}
}
}
