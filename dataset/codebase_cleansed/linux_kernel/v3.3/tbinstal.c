acpi_status acpi_tb_verify_table(struct acpi_table_desc *table_desc)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(tb_verify_table);
if (!table_desc->pointer) {
if ((table_desc->flags & ACPI_TABLE_ORIGIN_MASK) ==
ACPI_TABLE_ORIGIN_MAPPED) {
table_desc->pointer =
acpi_os_map_memory(table_desc->address,
table_desc->length);
}
if (!table_desc->pointer) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
}
if (!ACPI_COMPARE_NAME(&table_desc->signature, ACPI_SIG_FACS)) {
status =
acpi_tb_verify_checksum(table_desc->pointer,
table_desc->length);
}
return_ACPI_STATUS(status);
}
acpi_status
acpi_tb_add_table(struct acpi_table_desc *table_desc, u32 *table_index)
{
u32 i;
acpi_status status = AE_OK;
struct acpi_table_header *override_table = NULL;
ACPI_FUNCTION_TRACE(tb_add_table);
if (!table_desc->pointer) {
status = acpi_tb_verify_table(table_desc);
if (ACPI_FAILURE(status) || !table_desc->pointer) {
return_ACPI_STATUS(status);
}
}
if ((table_desc->pointer->signature[0] != 0x00) &&
(!ACPI_COMPARE_NAME(table_desc->pointer->signature, ACPI_SIG_SSDT))
&& (ACPI_STRNCMP(table_desc->pointer->signature, "OEM", 3))) {
ACPI_ERROR((AE_INFO,
"Table has invalid signature [%4.4s] (0x%8.8X), must be SSDT or OEMx",
acpi_ut_valid_acpi_name(*(u32 *)table_desc->
pointer->
signature) ? table_desc->
pointer->signature : "????",
*(u32 *)table_desc->pointer->signature));
return_ACPI_STATUS(AE_BAD_SIGNATURE);
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
if (!acpi_gbl_root_table_list.tables[i].pointer) {
status =
acpi_tb_verify_table(&acpi_gbl_root_table_list.
tables[i]);
if (ACPI_FAILURE(status)
|| !acpi_gbl_root_table_list.tables[i].pointer) {
continue;
}
}
if (table_desc->length !=
acpi_gbl_root_table_list.tables[i].length) {
continue;
}
if (ACPI_MEMCMP(table_desc->pointer,
acpi_gbl_root_table_list.tables[i].pointer,
acpi_gbl_root_table_list.tables[i].length)) {
continue;
}
acpi_tb_delete_table(table_desc);
*table_index = i;
if (acpi_gbl_root_table_list.tables[i].
flags & ACPI_TABLE_IS_LOADED) {
status = AE_ALREADY_EXISTS;
goto release;
} else {
table_desc->pointer =
acpi_gbl_root_table_list.tables[i].pointer;
table_desc->address =
acpi_gbl_root_table_list.tables[i].address;
status = AE_OK;
goto print_header;
}
}
status = acpi_os_table_override(table_desc->pointer, &override_table);
if (ACPI_SUCCESS(status) && override_table) {
ACPI_INFO((AE_INFO,
"%4.4s @ 0x%p Table override, replaced with:",
table_desc->pointer->signature,
ACPI_CAST_PTR(void, table_desc->address)));
acpi_tb_delete_table(table_desc);
table_desc->address = ACPI_PTR_TO_PHYSADDR(override_table);
table_desc->pointer = override_table;
table_desc->length = override_table->length;
table_desc->flags = ACPI_TABLE_ORIGIN_OVERRIDE;
}
status = acpi_tb_store_table(table_desc->address, table_desc->pointer,
table_desc->length, table_desc->flags,
table_index);
if (ACPI_FAILURE(status)) {
goto release;
}
print_header:
acpi_tb_print_table_header(table_desc->address, table_desc->pointer);
release:
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
acpi_status acpi_tb_resize_root_table_list(void)
{
struct acpi_table_desc *tables;
ACPI_FUNCTION_TRACE(tb_resize_root_table_list);
if (!(acpi_gbl_root_table_list.flags & ACPI_ROOT_ALLOW_RESIZE)) {
ACPI_ERROR((AE_INFO,
"Resize of Root Table Array is not allowed"));
return_ACPI_STATUS(AE_SUPPORT);
}
tables = ACPI_ALLOCATE_ZEROED(((acpi_size) acpi_gbl_root_table_list.
max_table_count +
ACPI_ROOT_TABLE_SIZE_INCREMENT) *
sizeof(struct acpi_table_desc));
if (!tables) {
ACPI_ERROR((AE_INFO,
"Could not allocate new root table array"));
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (acpi_gbl_root_table_list.tables) {
ACPI_MEMCPY(tables, acpi_gbl_root_table_list.tables,
(acpi_size) acpi_gbl_root_table_list.
max_table_count * sizeof(struct acpi_table_desc));
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
ACPI_FREE(acpi_gbl_root_table_list.tables);
}
}
acpi_gbl_root_table_list.tables = tables;
acpi_gbl_root_table_list.max_table_count +=
ACPI_ROOT_TABLE_SIZE_INCREMENT;
acpi_gbl_root_table_list.flags |= (u8)ACPI_ROOT_ORIGIN_ALLOCATED;
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_tb_store_table(acpi_physical_address address,
struct acpi_table_header *table,
u32 length, u8 flags, u32 *table_index)
{
acpi_status status;
struct acpi_table_desc *new_table;
if (acpi_gbl_root_table_list.current_table_count >=
acpi_gbl_root_table_list.max_table_count) {
status = acpi_tb_resize_root_table_list();
if (ACPI_FAILURE(status)) {
return (status);
}
}
new_table =
&acpi_gbl_root_table_list.tables[acpi_gbl_root_table_list.
current_table_count];
new_table->address = address;
new_table->pointer = table;
new_table->length = length;
new_table->owner_id = 0;
new_table->flags = flags;
ACPI_MOVE_32_TO_32(&new_table->signature, table->signature);
*table_index = acpi_gbl_root_table_list.current_table_count;
acpi_gbl_root_table_list.current_table_count++;
return (AE_OK);
}
void acpi_tb_delete_table(struct acpi_table_desc *table_desc)
{
if (!table_desc->pointer) {
return;
}
switch (table_desc->flags & ACPI_TABLE_ORIGIN_MASK) {
case ACPI_TABLE_ORIGIN_MAPPED:
acpi_os_unmap_memory(table_desc->pointer, table_desc->length);
break;
case ACPI_TABLE_ORIGIN_ALLOCATED:
ACPI_FREE(table_desc->pointer);
break;
default:;
}
table_desc->pointer = NULL;
}
void acpi_tb_terminate(void)
{
u32 i;
ACPI_FUNCTION_TRACE(tb_terminate);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; i++) {
acpi_tb_delete_table(&acpi_gbl_root_table_list.tables[i]);
}
if (acpi_gbl_root_table_list.flags & ACPI_ROOT_ORIGIN_ALLOCATED) {
ACPI_FREE(acpi_gbl_root_table_list.tables);
}
acpi_gbl_root_table_list.tables = NULL;
acpi_gbl_root_table_list.flags = 0;
acpi_gbl_root_table_list.current_table_count = 0;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "ACPI Tables freed\n"));
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
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
status = acpi_ut_allocate_owner_id
(&(acpi_gbl_root_table_list.tables[table_index].owner_id));
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
acpi_status acpi_tb_get_owner_id(u32 table_index, acpi_owner_id *owner_id)
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
