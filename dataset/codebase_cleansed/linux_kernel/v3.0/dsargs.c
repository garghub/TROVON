static acpi_status
acpi_ds_execute_arguments(struct acpi_namespace_node *node,
struct acpi_namespace_node *scope_node,
u32 aml_length, u8 *aml_start)
{
acpi_status status;
union acpi_parse_object *op;
struct acpi_walk_state *walk_state;
ACPI_FUNCTION_TRACE(ds_execute_arguments);
op = acpi_ps_alloc_op(AML_INT_EVAL_SUBTREE_OP);
if (!op) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
op->common.node = scope_node;
walk_state = acpi_ds_create_walk_state(0, NULL, NULL, NULL);
if (!walk_state) {
status = AE_NO_MEMORY;
goto cleanup;
}
status = acpi_ds_init_aml_walk(walk_state, op, NULL, aml_start,
aml_length, NULL, ACPI_IMODE_LOAD_PASS1);
if (ACPI_FAILURE(status)) {
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
walk_state->parse_flags = ACPI_PARSE_DEFERRED_OP;
walk_state->deferred_node = node;
status = acpi_ps_parse_aml(walk_state);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
op->common.node = node;
acpi_ps_delete_parse_tree(op);
op = acpi_ps_alloc_op(AML_INT_EVAL_SUBTREE_OP);
if (!op) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
op->common.node = scope_node;
walk_state = acpi_ds_create_walk_state(0, NULL, NULL, NULL);
if (!walk_state) {
status = AE_NO_MEMORY;
goto cleanup;
}
status = acpi_ds_init_aml_walk(walk_state, op, NULL, aml_start,
aml_length, NULL, ACPI_IMODE_EXECUTE);
if (ACPI_FAILURE(status)) {
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
walk_state->deferred_node = node;
status = acpi_ps_parse_aml(walk_state);
cleanup:
acpi_ps_delete_parse_tree(op);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ds_get_buffer_field_arguments(union acpi_operand_object *obj_desc)
{
union acpi_operand_object *extra_desc;
struct acpi_namespace_node *node;
acpi_status status;
ACPI_FUNCTION_TRACE_PTR(ds_get_buffer_field_arguments, obj_desc);
if (obj_desc->common.flags & AOPOBJ_DATA_VALID) {
return_ACPI_STATUS(AE_OK);
}
extra_desc = acpi_ns_get_secondary_object(obj_desc);
node = obj_desc->buffer_field.node;
ACPI_DEBUG_EXEC(acpi_ut_display_init_pathname(ACPI_TYPE_BUFFER_FIELD,
node, NULL));
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "[%4.4s] BufferField Arg Init\n",
acpi_ut_get_node_name(node)));
status = acpi_ds_execute_arguments(node, node->parent,
extra_desc->extra.aml_length,
extra_desc->extra.aml_start);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ds_get_bank_field_arguments(union acpi_operand_object *obj_desc)
{
union acpi_operand_object *extra_desc;
struct acpi_namespace_node *node;
acpi_status status;
ACPI_FUNCTION_TRACE_PTR(ds_get_bank_field_arguments, obj_desc);
if (obj_desc->common.flags & AOPOBJ_DATA_VALID) {
return_ACPI_STATUS(AE_OK);
}
extra_desc = acpi_ns_get_secondary_object(obj_desc);
node = obj_desc->bank_field.node;
ACPI_DEBUG_EXEC(acpi_ut_display_init_pathname
(ACPI_TYPE_LOCAL_BANK_FIELD, node, NULL));
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "[%4.4s] BankField Arg Init\n",
acpi_ut_get_node_name(node)));
status = acpi_ds_execute_arguments(node, node->parent,
extra_desc->extra.aml_length,
extra_desc->extra.aml_start);
return_ACPI_STATUS(status);
}
acpi_status acpi_ds_get_buffer_arguments(union acpi_operand_object *obj_desc)
{
struct acpi_namespace_node *node;
acpi_status status;
ACPI_FUNCTION_TRACE_PTR(ds_get_buffer_arguments, obj_desc);
if (obj_desc->common.flags & AOPOBJ_DATA_VALID) {
return_ACPI_STATUS(AE_OK);
}
node = obj_desc->buffer.node;
if (!node) {
ACPI_ERROR((AE_INFO,
"No pointer back to namespace node in buffer object %p",
obj_desc));
return_ACPI_STATUS(AE_AML_INTERNAL);
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Buffer Arg Init\n"));
status = acpi_ds_execute_arguments(node, node,
obj_desc->buffer.aml_length,
obj_desc->buffer.aml_start);
return_ACPI_STATUS(status);
}
acpi_status acpi_ds_get_package_arguments(union acpi_operand_object *obj_desc)
{
struct acpi_namespace_node *node;
acpi_status status;
ACPI_FUNCTION_TRACE_PTR(ds_get_package_arguments, obj_desc);
if (obj_desc->common.flags & AOPOBJ_DATA_VALID) {
return_ACPI_STATUS(AE_OK);
}
node = obj_desc->package.node;
if (!node) {
ACPI_ERROR((AE_INFO,
"No pointer back to namespace node in package %p",
obj_desc));
return_ACPI_STATUS(AE_AML_INTERNAL);
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Package Arg Init\n"));
status = acpi_ds_execute_arguments(node, node,
obj_desc->package.aml_length,
obj_desc->package.aml_start);
return_ACPI_STATUS(status);
}
acpi_status acpi_ds_get_region_arguments(union acpi_operand_object *obj_desc)
{
struct acpi_namespace_node *node;
acpi_status status;
union acpi_operand_object *extra_desc;
ACPI_FUNCTION_TRACE_PTR(ds_get_region_arguments, obj_desc);
if (obj_desc->region.flags & AOPOBJ_DATA_VALID) {
return_ACPI_STATUS(AE_OK);
}
extra_desc = acpi_ns_get_secondary_object(obj_desc);
if (!extra_desc) {
return_ACPI_STATUS(AE_NOT_EXIST);
}
node = obj_desc->region.node;
ACPI_DEBUG_EXEC(acpi_ut_display_init_pathname
(ACPI_TYPE_REGION, node, NULL));
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "[%4.4s] OpRegion Arg Init at AML %p\n",
acpi_ut_get_node_name(node),
extra_desc->extra.aml_start));
status = acpi_ds_execute_arguments(node, node->parent,
extra_desc->extra.aml_length,
extra_desc->extra.aml_start);
return_ACPI_STATUS(status);
}
