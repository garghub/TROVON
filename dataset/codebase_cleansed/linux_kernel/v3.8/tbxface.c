acpi_status acpi_allocate_root_table(u32 initial_table_count)
{
acpi_gbl_root_table_list.max_table_count = initial_table_count;
acpi_gbl_root_table_list.flags = ACPI_ROOT_ALLOW_RESIZE;
return (acpi_tb_resize_root_table_list());
}
acpi_status __init
acpi_initialize_tables(struct acpi_table_desc * initial_table_array,
u32 initial_table_count, u8 allow_resize)
{
acpi_physical_address rsdp_address;
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_initialize_tables);
if (!initial_table_array) {
status = acpi_allocate_root_table(initial_table_count);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
} else {
ACPI_MEMSET(initial_table_array, 0,
(acpi_size) initial_table_count *
sizeof(struct acpi_table_desc));
acpi_gbl_root_table_list.tables = initial_table_array;
acpi_gbl_root_table_list.max_table_count = initial_table_count;
acpi_gbl_root_table_list.flags = ACPI_ROOT_ORIGIN_UNKNOWN;
if (allow_resize) {
acpi_gbl_root_table_list.flags |=
ACPI_ROOT_ALLOW_RESIZE;
}
}
rsdp_address = acpi_os_get_root_pointer();
if (!rsdp_address) {
return_ACPI_STATUS(AE_NOT_FOUND);
}
status = acpi_tb_parse_root_table(rsdp_address);
return_ACPI_STATUS(status);
}
acpi_status acpi_reallocate_root_table(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_reallocate_root_table);
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
return_ACPI_STATUS(AE_SUPPORT);
}
acpi_gbl_root_table_list.flags |= ACPI_ROOT_ALLOW_RESIZE;
status = acpi_tb_resize_root_table_list();
return_ACPI_STATUS(status);
}
acpi_status
acpi_get_table_header(char *signature,
u32 instance, struct acpi_table_header *out_table_header)
{
u32 i;
u32 j;
struct acpi_table_header *header;
if (!signature || !out_table_header) {
return (AE_BAD_PARAMETER);
}
for (i = 0, j = 0; i < acpi_gbl_root_table_list.current_table_count;
i++) {
if (!ACPI_COMPARE_NAME
(&(acpi_gbl_root_table_list.tables[i].signature),
signature)) {
continue;
}
if (++j < instance) {
continue;
}
if (!acpi_gbl_root_table_list.tables[i].pointer) {
if ((acpi_gbl_root_table_list.tables[i].flags &
ACPI_TABLE_ORIGIN_MASK) ==
ACPI_TABLE_ORIGIN_MAPPED) {
header =
acpi_os_map_memory(acpi_gbl_root_table_list.
tables[i].address,
sizeof(struct
acpi_table_header));
if (!header) {
return (AE_NO_MEMORY);
}
ACPI_MEMCPY(out_table_header, header,
sizeof(struct acpi_table_header));
acpi_os_unmap_memory(header,
sizeof(struct
acpi_table_header));
} else {
return (AE_NOT_FOUND);
}
} else {
ACPI_MEMCPY(out_table_header,
acpi_gbl_root_table_list.tables[i].pointer,
sizeof(struct acpi_table_header));
}
return (AE_OK);
}
return (AE_NOT_FOUND);
}
acpi_status acpi_unload_table_id(acpi_owner_id id)
{
int i;
acpi_status status = AE_NOT_EXIST;
ACPI_FUNCTION_TRACE(acpi_unload_table_id);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
if (id != acpi_gbl_root_table_list.tables[i].owner_id) {
continue;
}
acpi_tb_delete_namespace_by_owner(i);
status = acpi_tb_release_owner_id(i);
acpi_tb_set_table_loaded_flag(i, FALSE);
break;
}
return_ACPI_STATUS(status);
}
acpi_status
acpi_get_table_with_size(char *signature,
u32 instance, struct acpi_table_header **out_table,
acpi_size *tbl_size)
{
u32 i;
u32 j;
acpi_status status;
if (!signature || !out_table) {
return (AE_BAD_PARAMETER);
}
for (i = 0, j = 0; i < acpi_gbl_root_table_list.current_table_count;
i++) {
if (!ACPI_COMPARE_NAME
(&(acpi_gbl_root_table_list.tables[i].signature),
signature)) {
continue;
}
if (++j < instance) {
continue;
}
status =
acpi_tb_verify_table(&acpi_gbl_root_table_list.tables[i]);
if (ACPI_SUCCESS(status)) {
*out_table = acpi_gbl_root_table_list.tables[i].pointer;
*tbl_size = acpi_gbl_root_table_list.tables[i].length;
}
if (!acpi_gbl_permanent_mmap) {
acpi_gbl_root_table_list.tables[i].pointer = NULL;
}
return (status);
}
return (AE_NOT_FOUND);
}
acpi_status
acpi_get_table(char *signature,
u32 instance, struct acpi_table_header **out_table)
{
acpi_size tbl_size;
return acpi_get_table_with_size(signature,
instance, out_table, &tbl_size);
}
acpi_status
acpi_get_table_by_index(u32 table_index, struct acpi_table_header **table)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_get_table_by_index);
if (!table) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index >= acpi_gbl_root_table_list.current_table_count) {
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (!acpi_gbl_root_table_list.tables[table_index].pointer) {
status =
acpi_tb_verify_table(&acpi_gbl_root_table_list.
tables[table_index]);
if (ACPI_FAILURE(status)) {
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
}
*table = acpi_gbl_root_table_list.tables[table_index].pointer;
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_install_table_handler(acpi_tbl_handler handler, void *context)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_install_table_handler);
if (!handler) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (acpi_gbl_table_handler) {
status = AE_ALREADY_EXISTS;
goto cleanup;
}
acpi_gbl_table_handler = handler;
acpi_gbl_table_handler_context = context;
cleanup:
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
acpi_status acpi_remove_table_handler(acpi_tbl_handler handler)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_remove_table_handler);
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (!handler || handler != acpi_gbl_table_handler) {
status = AE_BAD_PARAMETER;
goto cleanup;
}
acpi_gbl_table_handler = NULL;
cleanup:
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
