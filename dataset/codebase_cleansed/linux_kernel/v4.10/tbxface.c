acpi_status acpi_allocate_root_table(u32 initial_table_count)
{
acpi_gbl_root_table_list.max_table_count = initial_table_count;
acpi_gbl_root_table_list.flags = ACPI_ROOT_ALLOW_RESIZE;
return (acpi_tb_resize_root_table_list());
}
acpi_status ACPI_INIT_FUNCTION
acpi_initialize_tables(struct acpi_table_desc *initial_table_array,
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
memset(initial_table_array, 0,
(acpi_size)initial_table_count *
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
acpi_status ACPI_INIT_FUNCTION acpi_reallocate_root_table(void)
{
acpi_status status;
u32 i;
ACPI_FUNCTION_TRACE(acpi_reallocate_root_table);
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
return_ACPI_STATUS(AE_SUPPORT);
}
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
if (acpi_gbl_root_table_list.tables[i].pointer) {
ACPI_ERROR((AE_INFO,
"Table [%4.4s] is not invalidated during early boot stage",
acpi_gbl_root_table_list.tables[i].
signature.ascii));
}
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
ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL) {
header =
acpi_os_map_memory(acpi_gbl_root_table_list.
tables[i].address,
sizeof(struct
acpi_table_header));
if (!header) {
return (AE_NO_MEMORY);
}
memcpy(out_table_header, header,
sizeof(struct acpi_table_header));
acpi_os_unmap_memory(header,
sizeof(struct
acpi_table_header));
} else {
return (AE_NOT_FOUND);
}
} else {
memcpy(out_table_header,
acpi_gbl_root_table_list.tables[i].pointer,
sizeof(struct acpi_table_header));
}
return (AE_OK);
}
return (AE_NOT_FOUND);
}
acpi_status
acpi_get_table(char *signature,
u32 instance, struct acpi_table_header ** out_table)
{
u32 i;
u32 j;
acpi_status status = AE_NOT_FOUND;
struct acpi_table_desc *table_desc;
if (!signature || !out_table) {
return (AE_BAD_PARAMETER);
}
*out_table = NULL;
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0, j = 0; i < acpi_gbl_root_table_list.current_table_count;
i++) {
table_desc = &acpi_gbl_root_table_list.tables[i];
if (!ACPI_COMPARE_NAME(&table_desc->signature, signature)) {
continue;
}
if (++j < instance) {
continue;
}
status = acpi_tb_get_table(table_desc, out_table);
break;
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return (status);
}
void acpi_put_table(struct acpi_table_header *table)
{
u32 i;
struct acpi_table_desc *table_desc;
ACPI_FUNCTION_TRACE(acpi_put_table);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; i++) {
table_desc = &acpi_gbl_root_table_list.tables[i];
if (table_desc->pointer != table) {
continue;
}
acpi_tb_put_table(table_desc);
break;
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_VOID;
}
acpi_status
acpi_get_table_by_index(u32 table_index, struct acpi_table_header **out_table)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_get_table_by_index);
if (!out_table) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
*out_table = NULL;
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index >= acpi_gbl_root_table_list.current_table_count) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
status =
acpi_tb_get_table(&acpi_gbl_root_table_list.tables[table_index],
out_table);
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
acpi_status
acpi_install_table_handler(acpi_table_handler handler, void *context)
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
acpi_status acpi_remove_table_handler(acpi_table_handler handler)
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
