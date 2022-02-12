const union acpi_predefined_info *acpi_ut_get_next_predefined_method(const union
acpi_predefined_info
*this_name)
{
if ((this_name->info.expected_btypes & ACPI_RTYPE_PACKAGE) &&
(this_name->info.expected_btypes != ACPI_RTYPE_ALL)) {
this_name++;
}
this_name++;
return (this_name);
}
const union acpi_predefined_info *acpi_ut_match_predefined_method(char *name)
{
const union acpi_predefined_info *this_name;
if (name[0] != '_') {
return (NULL);
}
this_name = acpi_gbl_predefined_methods;
while (this_name->info.name[0]) {
if (ACPI_COMPARE_NAME(name, this_name->info.name)) {
return (this_name);
}
this_name = acpi_ut_get_next_predefined_method(this_name);
}
return (NULL);
}
void acpi_ut_get_expected_return_types(char *buffer, u32 expected_btypes)
{
u32 this_rtype;
u32 i;
u32 j;
if (!expected_btypes) {
strcpy(buffer, "NONE");
return;
}
j = 1;
buffer[0] = 0;
this_rtype = ACPI_RTYPE_INTEGER;
for (i = 0; i < ACPI_NUM_RTYPES; i++) {
if (expected_btypes & this_rtype) {
strcat(buffer, &ut_rtype_names[i][j]);
j = 0;
}
this_rtype <<= 1;
}
}
const union acpi_predefined_info *acpi_ut_match_resource_name(char *name)
{
const union acpi_predefined_info *this_name;
if (name[0] != '_') {
return (NULL);
}
this_name = acpi_gbl_resource_names;
while (this_name->info.name[0]) {
if (ACPI_COMPARE_NAME(name, this_name->info.name)) {
return (this_name);
}
this_name++;
}
return (NULL);
}
void
acpi_ut_display_predefined_method(char *buffer,
const union acpi_predefined_info *this_name,
u8 multi_line)
{
u32 arg_count;
arg_count = acpi_ut_get_argument_types(buffer,
this_name->info.argument_list);
if (multi_line) {
printf(" ");
}
printf("%4.4s Requires %s%u argument%s",
this_name->info.name,
(this_name->info.argument_list & ARG_COUNT_IS_MINIMUM) ?
"(at least) " : "", arg_count, arg_count != 1 ? "s" : "");
if (arg_count > 0) {
printf(" (%s)", buffer);
}
if (multi_line) {
printf("\n ");
}
if (this_name->info.expected_btypes) {
acpi_ut_get_expected_return_types(buffer,
this_name->info.
expected_btypes);
printf(" Return value types: %s\n", buffer);
} else {
printf(" No return value\n");
}
}
static u32 acpi_ut_get_argument_types(char *buffer, u16 argument_types)
{
u16 this_argument_type;
u16 sub_index;
u16 arg_count;
u32 i;
*buffer = 0;
sub_index = 2;
arg_count = METHOD_GET_ARG_COUNT(argument_types);
if (arg_count > METHOD_PREDEF_ARGS_MAX) {
printf("**** Invalid argument count (%u) "
"in predefined info structure\n", arg_count);
return (arg_count);
}
for (i = 0; i < arg_count; i++) {
this_argument_type = METHOD_GET_NEXT_TYPE(argument_types);
if (!this_argument_type
|| (this_argument_type > METHOD_MAX_ARG_TYPE)) {
printf("**** Invalid argument type (%u) "
"in predefined info structure\n",
this_argument_type);
return (arg_count);
}
strcat(buffer,
ut_external_type_names[this_argument_type] + sub_index);
sub_index = 0;
}
return (arg_count);
}
u32 acpi_ut_get_resource_bit_width(char *buffer, u16 types)
{
u32 i;
u16 sub_index;
u32 found;
*buffer = 0;
sub_index = 1;
found = 0;
for (i = 0; i < NUM_RESOURCE_WIDTHS; i++) {
if (types & 1) {
strcat(buffer, &(ut_resource_type_names[i][sub_index]));
sub_index = 0;
found++;
}
types >>= 1;
}
return (found);
}
