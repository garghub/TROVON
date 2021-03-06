static acpi_status
acpi_ex_add_table(u32 table_index,
struct acpi_namespace_node *parent_node,
union acpi_operand_object **ddb_handle)
{
union acpi_operand_object *obj_desc;
acpi_status status;
acpi_owner_id owner_id;
ACPI_FUNCTION_TRACE(ex_add_table);
obj_desc = acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_REFERENCE);
if (!obj_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
obj_desc->common.flags |= AOPOBJ_DATA_VALID;
obj_desc->reference.class = ACPI_REFCLASS_TABLE;
*ddb_handle = obj_desc;
obj_desc->reference.value = table_index;
status = acpi_ns_load_table(table_index, parent_node);
if (ACPI_FAILURE(status)) {
acpi_ut_remove_reference(obj_desc);
*ddb_handle = NULL;
return_ACPI_STATUS(status);
}
acpi_ex_exit_interpreter();
acpi_ns_exec_module_code_list();
acpi_ex_enter_interpreter();
status = acpi_tb_get_owner_id(table_index, &owner_id);
if (ACPI_SUCCESS(status)) {
acpi_ev_update_gpes(owner_id);
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ex_load_table_op(struct acpi_walk_state *walk_state,
union acpi_operand_object **return_desc)
{
acpi_status status;
union acpi_operand_object **operand = &walk_state->operands[0];
struct acpi_namespace_node *parent_node;
struct acpi_namespace_node *start_node;
struct acpi_namespace_node *parameter_node = NULL;
union acpi_operand_object *ddb_handle;
struct acpi_table_header *table;
u32 table_index;
ACPI_FUNCTION_TRACE(ex_load_table_op);
if ((operand[0]->string.length > ACPI_NAME_SIZE) ||
(operand[1]->string.length > ACPI_OEM_ID_SIZE) ||
(operand[2]->string.length > ACPI_OEM_TABLE_ID_SIZE)) {
return_ACPI_STATUS(AE_AML_STRING_LIMIT);
}
status = acpi_tb_find_table(operand[0]->string.pointer,
operand[1]->string.pointer,
operand[2]->string.pointer, &table_index);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND) {
return_ACPI_STATUS(status);
}
ddb_handle = acpi_ut_create_integer_object((u64) 0);
if (!ddb_handle) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
*return_desc = ddb_handle;
return_ACPI_STATUS(AE_OK);
}
start_node = walk_state->scope_info->scope.node;
parent_node = acpi_gbl_root_node;
if (operand[3]->string.length > 0) {
status =
acpi_ns_get_node(start_node, operand[3]->string.pointer,
ACPI_NS_SEARCH_PARENT, &parent_node);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (operand[4]->string.length > 0) {
if ((operand[4]->string.pointer[0] != AML_ROOT_PREFIX) &&
(operand[4]->string.pointer[0] != AML_PARENT_PREFIX)) {
start_node = parent_node;
}
status =
acpi_ns_get_node(start_node, operand[4]->string.pointer,
ACPI_NS_SEARCH_PARENT, &parameter_node);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
status = acpi_ex_add_table(table_index, parent_node, &ddb_handle);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (parameter_node) {
status = acpi_ex_store(operand[5],
ACPI_CAST_PTR(union acpi_operand_object,
parameter_node),
walk_state);
if (ACPI_FAILURE(status)) {
(void)acpi_ex_unload_table(ddb_handle);
acpi_ut_remove_reference(ddb_handle);
return_ACPI_STATUS(status);
}
}
status = acpi_get_table_by_index(table_index, &table);
if (ACPI_SUCCESS(status)) {
ACPI_INFO((AE_INFO, "Dynamic OEM Table Load:"));
acpi_tb_print_table_header(0, table);
}
if (acpi_gbl_table_handler) {
(void)acpi_gbl_table_handler(ACPI_TABLE_EVENT_LOAD, table,
acpi_gbl_table_handler_context);
}
*return_desc = ddb_handle;
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ex_region_read(union acpi_operand_object *obj_desc, u32 length, u8 *buffer)
{
acpi_status status;
u64 value;
u32 region_offset = 0;
u32 i;
for (i = 0; i < length; i++) {
status =
acpi_ev_address_space_dispatch(obj_desc, NULL, ACPI_READ,
region_offset, 8, &value);
if (ACPI_FAILURE(status)) {
return (status);
}
*buffer = (u8)value;
buffer++;
region_offset++;
}
return (AE_OK);
}
acpi_status
acpi_ex_load_op(union acpi_operand_object *obj_desc,
union acpi_operand_object *target,
struct acpi_walk_state *walk_state)
{
union acpi_operand_object *ddb_handle;
struct acpi_table_header *table_header;
struct acpi_table_header *table;
u32 table_index;
acpi_status status;
u32 length;
ACPI_FUNCTION_TRACE(ex_load_op);
switch (obj_desc->common.type) {
case ACPI_TYPE_REGION:
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Load table from Region %p\n", obj_desc));
if (obj_desc->region.space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY) {
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
if (!(obj_desc->common.flags & AOPOBJ_DATA_VALID)) {
status = acpi_ds_get_region_arguments(obj_desc);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
table_header = ACPI_ALLOCATE(sizeof(struct acpi_table_header));
if (!table_header) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
status =
acpi_ex_region_read(obj_desc,
sizeof(struct acpi_table_header),
ACPI_CAST_PTR(u8, table_header));
length = table_header->length;
ACPI_FREE(table_header);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (length < sizeof(struct acpi_table_header)) {
return_ACPI_STATUS(AE_INVALID_TABLE_LENGTH);
}
table = ACPI_ALLOCATE(length);
if (!table) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
status = acpi_ex_region_read(obj_desc, length,
ACPI_CAST_PTR(u8, table));
if (ACPI_FAILURE(status)) {
ACPI_FREE(table);
return_ACPI_STATUS(status);
}
break;
case ACPI_TYPE_BUFFER:
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Load table from Buffer or Field %p\n",
obj_desc));
if (obj_desc->buffer.length < sizeof(struct acpi_table_header)) {
return_ACPI_STATUS(AE_INVALID_TABLE_LENGTH);
}
table_header =
ACPI_CAST_PTR(struct acpi_table_header,
obj_desc->buffer.pointer);
length = table_header->length;
if (length > obj_desc->buffer.length) {
return_ACPI_STATUS(AE_AML_BUFFER_LIMIT);
}
if (length < sizeof(struct acpi_table_header)) {
return_ACPI_STATUS(AE_INVALID_TABLE_LENGTH);
}
table = ACPI_ALLOCATE(length);
if (!table) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
memcpy(table, table_header, length);
break;
default:
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
ACPI_INFO((AE_INFO, "Dynamic OEM Table Load:"));
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
status = acpi_tb_install_standard_table(ACPI_PTR_TO_PHYSADDR(table),
ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL,
TRUE, TRUE, &table_index);
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
if (ACPI_FAILURE(status)) {
ACPI_FREE(table);
return_ACPI_STATUS(status);
}
status =
acpi_tb_validate_table(&acpi_gbl_root_table_list.
tables[table_index]);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status =
acpi_ex_add_table(table_index, acpi_gbl_root_node, &ddb_handle);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ex_store(ddb_handle, target, walk_state);
if (ACPI_FAILURE(status)) {
(void)acpi_ex_unload_table(ddb_handle);
acpi_ut_remove_reference(ddb_handle);
return_ACPI_STATUS(status);
}
acpi_ut_remove_reference(ddb_handle);
if (acpi_gbl_table_handler) {
(void)acpi_gbl_table_handler(ACPI_TABLE_EVENT_LOAD, table,
acpi_gbl_table_handler_context);
}
return_ACPI_STATUS(status);
}
acpi_status acpi_ex_unload_table(union acpi_operand_object *ddb_handle)
{
acpi_status status = AE_OK;
union acpi_operand_object *table_desc = ddb_handle;
u32 table_index;
struct acpi_table_header *table;
ACPI_FUNCTION_TRACE(ex_unload_table);
ACPI_WARNING((AE_INFO, "Received request to unload an ACPI table"));
if ((!ddb_handle) ||
(ACPI_GET_DESCRIPTOR_TYPE(ddb_handle) != ACPI_DESC_TYPE_OPERAND) ||
(ddb_handle->common.type != ACPI_TYPE_LOCAL_REFERENCE) ||
(!(ddb_handle->common.flags & AOPOBJ_DATA_VALID))) {
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
table_index = table_desc->reference.value;
if (!acpi_tb_is_table_loaded(table_index)) {
return_ACPI_STATUS(AE_NOT_EXIST);
}
if (acpi_gbl_table_handler) {
status = acpi_get_table_by_index(table_index, &table);
if (ACPI_SUCCESS(status)) {
(void)acpi_gbl_table_handler(ACPI_TABLE_EVENT_UNLOAD,
table,
acpi_gbl_table_handler_context);
}
}
status = acpi_tb_delete_namespace_by_owner(table_index);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
(void)acpi_tb_release_owner_id(table_index);
acpi_tb_set_table_loaded_flag(table_index, FALSE);
ddb_handle->common.flags &= ~AOPOBJ_DATA_VALID;
return_ACPI_STATUS(AE_OK);
}
