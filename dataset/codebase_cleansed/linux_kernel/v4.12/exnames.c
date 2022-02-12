static char *acpi_ex_allocate_name_string(u32 prefix_count, u32 num_name_segs)
{
char *temp_ptr;
char *name_string;
u32 size_needed;
ACPI_FUNCTION_TRACE(ex_allocate_name_string);
if (prefix_count == ACPI_UINT32_MAX) {
size_needed = 1 + (ACPI_NAME_SIZE * num_name_segs) + 2 + 1;
} else {
size_needed =
prefix_count + (ACPI_NAME_SIZE * num_name_segs) + 2 + 1;
}
name_string = ACPI_ALLOCATE(size_needed);
if (!name_string) {
ACPI_ERROR((AE_INFO,
"Could not allocate size %u", size_needed));
return_PTR(NULL);
}
temp_ptr = name_string;
if (prefix_count == ACPI_UINT32_MAX) {
*temp_ptr++ = AML_ROOT_PREFIX;
} else {
while (prefix_count--) {
*temp_ptr++ = AML_PARENT_PREFIX;
}
}
if (num_name_segs > 2) {
*temp_ptr++ = AML_MULTI_NAME_PREFIX;
*temp_ptr++ = (char)num_name_segs;
} else if (2 == num_name_segs) {
*temp_ptr++ = AML_DUAL_NAME_PREFIX;
}
*temp_ptr = 0;
return_PTR(name_string);
}
static acpi_status acpi_ex_name_segment(u8 ** in_aml_address, char *name_string)
{
char *aml_address = (void *)*in_aml_address;
acpi_status status = AE_OK;
u32 index;
char char_buf[5];
ACPI_FUNCTION_TRACE(ex_name_segment);
char_buf[0] = *aml_address;
if ('0' <= char_buf[0] && char_buf[0] <= '9') {
ACPI_ERROR((AE_INFO, "Invalid leading digit: %c", char_buf[0]));
return_ACPI_STATUS(AE_CTRL_PENDING);
}
ACPI_DEBUG_PRINT((ACPI_DB_LOAD, "Bytes from stream:\n"));
for (index = 0;
(index < ACPI_NAME_SIZE)
&& (acpi_ut_valid_name_char(*aml_address, 0)); index++) {
char_buf[index] = *aml_address++;
ACPI_DEBUG_PRINT((ACPI_DB_LOAD, "%c\n", char_buf[index]));
}
if (index == 4) {
char_buf[4] = '\0';
if (name_string) {
strcat(name_string, char_buf);
ACPI_DEBUG_PRINT((ACPI_DB_NAMES,
"Appended to - %s\n", name_string));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_NAMES,
"No Name string - %s\n", char_buf));
}
} else if (index == 0) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Leading character is not alpha: %02Xh (not a name)\n",
char_buf[0]));
status = AE_CTRL_PENDING;
} else {
status = AE_AML_BAD_NAME;
ACPI_ERROR((AE_INFO,
"Bad character 0x%02x in name, at %p",
*aml_address, aml_address));
}
*in_aml_address = ACPI_CAST_PTR(u8, aml_address);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ex_get_name_string(acpi_object_type data_type,
u8 * in_aml_address,
char **out_name_string, u32 * out_name_length)
{
acpi_status status = AE_OK;
u8 *aml_address = in_aml_address;
char *name_string = NULL;
u32 num_segments;
u32 prefix_count = 0;
u8 has_prefix = FALSE;
ACPI_FUNCTION_TRACE_PTR(ex_get_name_string, aml_address);
if (ACPI_TYPE_LOCAL_REGION_FIELD == data_type ||
ACPI_TYPE_LOCAL_BANK_FIELD == data_type ||
ACPI_TYPE_LOCAL_INDEX_FIELD == data_type) {
name_string = acpi_ex_allocate_name_string(0, 1);
if (!name_string) {
status = AE_NO_MEMORY;
} else {
status =
acpi_ex_name_segment(&aml_address, name_string);
}
} else {
switch (*aml_address) {
case AML_ROOT_PREFIX:
ACPI_DEBUG_PRINT((ACPI_DB_LOAD,
"RootPrefix(\\) at %p\n",
aml_address));
aml_address++;
prefix_count = ACPI_UINT32_MAX;
has_prefix = TRUE;
break;
case AML_PARENT_PREFIX:
do {
ACPI_DEBUG_PRINT((ACPI_DB_LOAD,
"ParentPrefix (^) at %p\n",
aml_address));
aml_address++;
prefix_count++;
} while (*aml_address == AML_PARENT_PREFIX);
has_prefix = TRUE;
break;
default:
break;
}
switch (*aml_address) {
case AML_DUAL_NAME_PREFIX:
ACPI_DEBUG_PRINT((ACPI_DB_LOAD,
"DualNamePrefix at %p\n",
aml_address));
aml_address++;
name_string =
acpi_ex_allocate_name_string(prefix_count, 2);
if (!name_string) {
status = AE_NO_MEMORY;
break;
}
has_prefix = TRUE;
status =
acpi_ex_name_segment(&aml_address, name_string);
if (ACPI_SUCCESS(status)) {
status =
acpi_ex_name_segment(&aml_address,
name_string);
}
break;
case AML_MULTI_NAME_PREFIX:
ACPI_DEBUG_PRINT((ACPI_DB_LOAD,
"MultiNamePrefix at %p\n",
aml_address));
aml_address++;
num_segments = *aml_address;
name_string =
acpi_ex_allocate_name_string(prefix_count,
num_segments);
if (!name_string) {
status = AE_NO_MEMORY;
break;
}
aml_address++;
has_prefix = TRUE;
while (num_segments &&
(status =
acpi_ex_name_segment(&aml_address,
name_string)) == AE_OK) {
num_segments--;
}
break;
case 0:
if (prefix_count == ACPI_UINT32_MAX) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"NameSeg is \"\\\" followed by NULL\n"));
}
aml_address++;
name_string =
acpi_ex_allocate_name_string(prefix_count, 0);
if (!name_string) {
status = AE_NO_MEMORY;
break;
}
break;
default:
name_string =
acpi_ex_allocate_name_string(prefix_count, 1);
if (!name_string) {
status = AE_NO_MEMORY;
break;
}
status =
acpi_ex_name_segment(&aml_address, name_string);
break;
}
}
if (AE_CTRL_PENDING == status && has_prefix) {
ACPI_ERROR((AE_INFO, "Malformed Name at %p", name_string));
status = AE_AML_BAD_NAME;
}
if (ACPI_FAILURE(status)) {
if (name_string) {
ACPI_FREE(name_string);
}
return_ACPI_STATUS(status);
}
*out_name_string = name_string;
*out_name_length = (u32) (aml_address - in_aml_address);
return_ACPI_STATUS(status);
}
