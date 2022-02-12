void
acpi_tb_init_table_descriptor(struct acpi_table_desc *table_desc,
acpi_physical_address address,
u8 flags, struct acpi_table_header *table)
{
memset(table_desc, 0, sizeof(struct acpi_table_desc));
table_desc->address = address;
table_desc->length = table->length;
table_desc->flags = flags;
ACPI_MOVE_32_TO_32(table_desc->signature.ascii, table->signature);
}
acpi_status
acpi_tb_acquire_table(struct acpi_table_desc *table_desc,
struct acpi_table_header **table_ptr,
u32 *table_length, u8 *table_flags)
{
struct acpi_table_header *table = NULL;
switch (table_desc->flags & ACPI_TABLE_ORIGIN_MASK) {
case ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL:
table =
acpi_os_map_memory(table_desc->address, table_desc->length);
break;
case ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL:
case ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL:
table = ACPI_CAST_PTR(struct acpi_table_header,
ACPI_PHYSADDR_TO_PTR(table_desc->
address));
break;
default:
break;
}
if (!table) {
return (AE_NO_MEMORY);
}
*table_ptr = table;
*table_length = table_desc->length;
*table_flags = table_desc->flags;
return (AE_OK);
}
void
acpi_tb_release_table(struct acpi_table_header *table,
u32 table_length, u8 table_flags)
{
switch (table_flags & ACPI_TABLE_ORIGIN_MASK) {
case ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL:
acpi_os_unmap_memory(table, table_length);
break;
case ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL:
case ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL:
default:
break;
}
}
acpi_status
acpi_tb_acquire_temp_table(struct acpi_table_desc *table_desc,
acpi_physical_address address, u8 flags)
{
struct acpi_table_header *table_header;
switch (flags & ACPI_TABLE_ORIGIN_MASK) {
case ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL:
table_header =
acpi_os_map_memory(address,
sizeof(struct acpi_table_header));
if (!table_header) {
return (AE_NO_MEMORY);
}
acpi_tb_init_table_descriptor(table_desc, address, flags,
table_header);
acpi_os_unmap_memory(table_header,
sizeof(struct acpi_table_header));
return (AE_OK);
case ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL:
case ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL:
table_header = ACPI_CAST_PTR(struct acpi_table_header,
ACPI_PHYSADDR_TO_PTR(address));
if (!table_header) {
return (AE_NO_MEMORY);
}
acpi_tb_init_table_descriptor(table_desc, address, flags,
table_header);
return (AE_OK);
default:
break;
}
return (AE_NO_MEMORY);
}
void acpi_tb_release_temp_table(struct acpi_table_desc *table_desc)
{
acpi_tb_invalidate_table(table_desc);
}
acpi_status acpi_tb_validate_table(struct acpi_table_desc *table_desc)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(tb_validate_table);
if (!table_desc->pointer) {
status = acpi_tb_acquire_table(table_desc, &table_desc->pointer,
&table_desc->length,
&table_desc->flags);
if (!table_desc->pointer) {
status = AE_NO_MEMORY;
}
}
return_ACPI_STATUS(status);
}
void acpi_tb_invalidate_table(struct acpi_table_desc *table_desc)
{
ACPI_FUNCTION_TRACE(tb_invalidate_table);
if (!table_desc->pointer) {
return_VOID;
}
acpi_tb_release_table(table_desc->pointer, table_desc->length,
table_desc->flags);
table_desc->pointer = NULL;
return_VOID;
}
acpi_status acpi_tb_validate_temp_table(struct acpi_table_desc *table_desc)
{
if (!table_desc->pointer && !acpi_gbl_verify_table_checksum) {
table_desc->length = sizeof(struct acpi_table_header);
}
return (acpi_tb_validate_table(table_desc));
}
acpi_status
acpi_tb_verify_temp_table(struct acpi_table_desc * table_desc, char *signature)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(tb_verify_temp_table);
status = acpi_tb_validate_temp_table(table_desc);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (signature && !ACPI_COMPARE_NAME(&table_desc->signature, signature)) {
ACPI_BIOS_ERROR((AE_INFO,
"Invalid signature 0x%X for ACPI table, expected [%s]",
table_desc->signature.integer, signature));
status = AE_BAD_SIGNATURE;
goto invalidate_and_exit;
}
if (acpi_gbl_verify_table_checksum) {
status =
acpi_tb_verify_checksum(table_desc->pointer,
table_desc->length);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, AE_NO_MEMORY,
"%4.4s 0x%8.8X%8.8X"
" Attempted table install failed",
acpi_ut_valid_acpi_name(table_desc->
signature.
ascii) ?
table_desc->signature.ascii : "????",
ACPI_FORMAT_UINT64(table_desc->
address)));
goto invalidate_and_exit;
}
}
return_ACPI_STATUS(AE_OK);
invalidate_and_exit:
acpi_tb_invalidate_table(table_desc);
return_ACPI_STATUS(status);
}
acpi_status acpi_tb_resize_root_table_list(void)
{
struct acpi_table_desc *tables;
u32 table_count;
ACPI_FUNCTION_TRACE(tb_resize_root_table_list);
if (!(acpi_gbl_root_table_list.flags & ACPI_ROOT_ALLOW_RESIZE)) {
ACPI_ERROR((AE_INFO,
"Resize of Root Table Array is not allowed"));
return_ACPI_STATUS(AE_SUPPORT);
}
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
table_count = acpi_gbl_root_table_list.max_table_count;
} else {
table_count = acpi_gbl_root_table_list.current_table_count;
}
tables = ACPI_ALLOCATE_ZEROED(((acpi_size) table_count +
ACPI_ROOT_TABLE_SIZE_INCREMENT) *
sizeof(struct acpi_table_desc));
if (!tables) {
ACPI_ERROR((AE_INFO,
"Could not allocate new root table array"));
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (acpi_gbl_root_table_list.tables) {
memcpy(tables, acpi_gbl_root_table_list.tables,
(acpi_size) table_count *
sizeof(struct acpi_table_desc));
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
ACPI_FREE(acpi_gbl_root_table_list.tables);
}
}
acpi_gbl_root_table_list.tables = tables;
acpi_gbl_root_table_list.max_table_count =
table_count + ACPI_ROOT_TABLE_SIZE_INCREMENT;
acpi_gbl_root_table_list.flags |= ACPI_ROOT_ORIGIN_ALLOCATED;
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_tb_get_next_table_descriptor(u32 *table_index,
struct acpi_table_desc **table_desc)
{
acpi_status status;
u32 i;
if (acpi_gbl_root_table_list.current_table_count >=
acpi_gbl_root_table_list.max_table_count) {
status = acpi_tb_resize_root_table_list();
if (ACPI_FAILURE(status)) {
return (status);
}
}
i = acpi_gbl_root_table_list.current_table_count;
acpi_gbl_root_table_list.current_table_count++;
if (table_index) {
*table_index = i;
}
if (table_desc) {
*table_desc = &acpi_gbl_root_table_list.tables[i];
}
return (AE_OK);
}
void acpi_tb_terminate(void)
{
u32 i;
ACPI_FUNCTION_TRACE(tb_terminate);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; i++) {
acpi_tb_uninstall_table(&acpi_gbl_root_table_list.tables[i]);
}
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
ACPI_FREE(acpi_gbl_root_table_list.tables);
}
acpi_gbl_root_table_list.tables = NULL;
acpi_gbl_root_table_list.flags = 0;
acpi_gbl_root_table_list.current_table_count = 0;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "ACPI Tables freed\n"));
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_VOID;
}
acpi_status acpi_tb_delete_namespace_by_owner(u32 table_index)
{
acpi_owner_id owner_id;
acpi_status status;
ACPI_FUNCTION_TRACE(tb_delete_namespace_by_owner);
status = acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (table_index >= acpi_gbl_root_table_list.current_table_count) {
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(AE_NOT_EXIST);
}
owner_id = acpi_gbl_root_table_list.tables[table_index].owner_id;
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
(void)acpi_ut_release_mutex(ACPI_MTX_INTERPRETER);
status = acpi_ut_acquire_write_lock(&acpi_gbl_namespace_rw_lock);
acpi_ns_delete_namespace_by_owner(owner_id);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_ut_release_write_lock(&acpi_gbl_namespace_rw_lock);
status = acpi_ut_acquire_mutex(ACPI_MTX_INTERPRETER);
return_ACPI_STATUS(status);
}
acpi_status acpi_tb_allocate_owner_id(u32 table_index)
{
acpi_status status = AE_BAD_PARAMETER;
ACPI_FUNCTION_TRACE(tb_allocate_owner_id);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index < acpi_gbl_root_table_list.current_table_count) {
status =
acpi_ut_allocate_owner_id(&
(acpi_gbl_root_table_list.
tables[table_index].owner_id));
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
acpi_status acpi_tb_release_owner_id(u32 table_index)
{
acpi_status status = AE_BAD_PARAMETER;
ACPI_FUNCTION_TRACE(tb_release_owner_id);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index < acpi_gbl_root_table_list.current_table_count) {
acpi_ut_release_owner_id(&
(acpi_gbl_root_table_list.
tables[table_index].owner_id));
status = AE_OK;
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
acpi_status acpi_tb_get_owner_id(u32 table_index, acpi_owner_id * owner_id)
{
acpi_status status = AE_BAD_PARAMETER;
ACPI_FUNCTION_TRACE(tb_get_owner_id);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index < acpi_gbl_root_table_list.current_table_count) {
*owner_id =
acpi_gbl_root_table_list.tables[table_index].owner_id;
status = AE_OK;
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
u8 acpi_tb_is_table_loaded(u32 table_index)
{
u8 is_loaded = FALSE;
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index < acpi_gbl_root_table_list.current_table_count) {
is_loaded = (u8)
(acpi_gbl_root_table_list.tables[table_index].flags &
ACPI_TABLE_IS_LOADED);
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return (is_loaded);
}
void acpi_tb_set_table_loaded_flag(u32 table_index, u8 is_loaded)
{
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (table_index < acpi_gbl_root_table_list.current_table_count) {
if (is_loaded) {
acpi_gbl_root_table_list.tables[table_index].flags |=
ACPI_TABLE_IS_LOADED;
} else {
acpi_gbl_root_table_list.tables[table_index].flags &=
~ACPI_TABLE_IS_LOADED;
}
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
}
