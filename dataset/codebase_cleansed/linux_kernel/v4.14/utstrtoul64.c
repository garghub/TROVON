acpi_status acpi_ut_strtoul64(char *string, u32 flags, u64 *return_value)
{
acpi_status status = AE_OK;
u32 base;
ACPI_FUNCTION_TRACE_STR(ut_strtoul64, string);
if (!string || !return_value) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
*return_value = 0;
if (*string == 0) {
return_ACPI_STATUS(AE_OK);
}
while (isspace((int)*string)) {
string++;
}
if (*string == 0) {
return_ACPI_STATUS(AE_OK);
}
if ((*string == ACPI_ASCII_ZERO) &&
(tolower((int)*(string + 1)) == 'x')) {
string += 2;
if (*string == 0) {
return_ACPI_STATUS(AE_OK);
}
base = 16;
}
else if (flags & ACPI_STRTOUL_BASE16) {
base = 16;
}
else {
base = 10;
}
while (*string == ACPI_ASCII_ZERO) {
string++;
if (*string == 0) {
return_ACPI_STATUS(AE_OK);
}
}
if (base == 16) {
*return_value = acpi_ut_strtoul_base16(string, flags);
} else {
*return_value = acpi_ut_strtoul_base10(string, flags);
}
return_ACPI_STATUS(status);
}
static u64 acpi_ut_strtoul_base10(char *string, u32 flags)
{
int ascii_digit;
u64 next_value;
u64 return_value = 0;
while (*string) {
ascii_digit = *string;
if (!isdigit(ascii_digit)) {
goto exit;
}
acpi_ut_short_multiply(return_value, 10, &next_value);
next_value += (ascii_digit - ACPI_ASCII_ZERO);
if (((flags & ACPI_STRTOUL_32BIT) && (next_value > ACPI_UINT32_MAX)) || (next_value < return_value)) {
goto exit;
}
return_value = next_value;
string++;
}
exit:
return (return_value);
}
static u64 acpi_ut_strtoul_base16(char *string, u32 flags)
{
int ascii_digit;
u32 valid_digits = 1;
u64 return_value = 0;
while (*string) {
if ((valid_digits > 16) ||
((valid_digits > 8) && (flags & ACPI_STRTOUL_32BIT))) {
goto exit;
}
ascii_digit = *string;
if (!isxdigit(ascii_digit)) {
goto exit;
}
acpi_ut_short_shift_left(return_value, 4, &return_value);
return_value |= acpi_ut_ascii_char_to_hex(ascii_digit);
string++;
valid_digits++;
}
exit:
return (return_value);
}
