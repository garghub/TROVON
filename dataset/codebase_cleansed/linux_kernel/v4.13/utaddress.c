acpi_status
acpi_ut_add_address_range(acpi_adr_space_type space_id,
acpi_physical_address address,
u32 length, struct acpi_namespace_node *region_node)
{
struct acpi_address_range *range_info;
ACPI_FUNCTION_TRACE(ut_add_address_range);
if ((space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY) &&
(space_id != ACPI_ADR_SPACE_SYSTEM_IO)) {
return_ACPI_STATUS(AE_OK);
}
range_info = ACPI_ALLOCATE(sizeof(struct acpi_address_range));
if (!range_info) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
range_info->start_address = address;
range_info->end_address = (address + length - 1);
range_info->region_node = region_node;
range_info->next = acpi_gbl_address_range_list[space_id];
acpi_gbl_address_range_list[space_id] = range_info;
ACPI_DEBUG_PRINT((ACPI_DB_NAMES,
"\nAdded [%4.4s] address range: 0x%8.8X%8.8X-0x%8.8X%8.8X\n",
acpi_ut_get_node_name(range_info->region_node),
ACPI_FORMAT_UINT64(address),
ACPI_FORMAT_UINT64(range_info->end_address)));
return_ACPI_STATUS(AE_OK);
}
void
acpi_ut_remove_address_range(acpi_adr_space_type space_id,
struct acpi_namespace_node *region_node)
{
struct acpi_address_range *range_info;
struct acpi_address_range *prev;
ACPI_FUNCTION_TRACE(ut_remove_address_range);
if ((space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY) &&
(space_id != ACPI_ADR_SPACE_SYSTEM_IO)) {
return_VOID;
}
range_info = prev = acpi_gbl_address_range_list[space_id];
while (range_info) {
if (range_info->region_node == region_node) {
if (range_info == prev) {
acpi_gbl_address_range_list[space_id] =
range_info->next;
} else {
prev->next = range_info->next;
}
ACPI_DEBUG_PRINT((ACPI_DB_NAMES,
"\nRemoved [%4.4s] address range: 0x%8.8X%8.8X-0x%8.8X%8.8X\n",
acpi_ut_get_node_name(range_info->
region_node),
ACPI_FORMAT_UINT64(range_info->
start_address),
ACPI_FORMAT_UINT64(range_info->
end_address)));
ACPI_FREE(range_info);
return_VOID;
}
prev = range_info;
range_info = range_info->next;
}
return_VOID;
}
u32
acpi_ut_check_address_range(acpi_adr_space_type space_id,
acpi_physical_address address, u32 length, u8 warn)
{
struct acpi_address_range *range_info;
acpi_physical_address end_address;
char *pathname;
u32 overlap_count = 0;
ACPI_FUNCTION_TRACE(ut_check_address_range);
if ((space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY) &&
(space_id != ACPI_ADR_SPACE_SYSTEM_IO)) {
return_UINT32(0);
}
range_info = acpi_gbl_address_range_list[space_id];
end_address = address + length - 1;
while (range_info) {
if ((address <= range_info->end_address) &&
(end_address >= range_info->start_address)) {
overlap_count++;
if (warn) {
pathname =
acpi_ns_get_normalized_pathname(range_info->
region_node,
TRUE);
ACPI_WARNING((AE_INFO,
"%s range 0x%8.8X%8.8X-0x%8.8X%8.8X conflicts with OpRegion 0x%8.8X%8.8X-0x%8.8X%8.8X (%s)",
acpi_ut_get_region_name(space_id),
ACPI_FORMAT_UINT64(address),
ACPI_FORMAT_UINT64(end_address),
ACPI_FORMAT_UINT64(range_info->
start_address),
ACPI_FORMAT_UINT64(range_info->
end_address),
pathname));
ACPI_FREE(pathname);
}
}
range_info = range_info->next;
}
return_UINT32(overlap_count);
}
void acpi_ut_delete_address_lists(void)
{
struct acpi_address_range *next;
struct acpi_address_range *range_info;
int i;
for (i = 0; i < ACPI_ADDRESS_RANGE_MAX; i++) {
next = acpi_gbl_address_range_list[i];
while (next) {
range_info = next;
next = range_info->next;
ACPI_FREE(range_info);
}
acpi_gbl_address_range_list[i] = NULL;
}
}
