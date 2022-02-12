acpi_status
acpi_debug_trace(const char *name, u32 debug_level, u32 debug_layer, u32 flags)
{
acpi_status status;
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
acpi_gbl_trace_method_name = name;
acpi_gbl_trace_flags = flags;
acpi_gbl_trace_dbg_level = debug_level;
acpi_gbl_trace_dbg_layer = debug_layer;
status = AE_OK;
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
acpi_status acpi_ps_execute_method(struct acpi_evaluate_info * info)
{
acpi_status status;
union acpi_parse_object *op;
struct acpi_walk_state *walk_state;
ACPI_FUNCTION_TRACE(ps_execute_method);
acpi_tb_check_dsdt_header();
if (!info || !info->node) {
return_ACPI_STATUS(AE_NULL_ENTRY);
}
status =
acpi_ds_begin_method_execution(info->node, info->obj_desc, NULL);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_ps_update_parameter_list(info, REF_INCREMENT);
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"**** Begin Method Parse/Execute [%4.4s] **** Node=%p Obj=%p\n",
info->node->name.ascii, info->node, info->obj_desc));
op = acpi_ps_create_scope_op(info->obj_desc->method.aml_start);
if (!op) {
status = AE_NO_MEMORY;
goto cleanup;
}
info->pass_number = ACPI_IMODE_EXECUTE;
walk_state =
acpi_ds_create_walk_state(info->obj_desc->method.owner_id, NULL,
NULL, NULL);
if (!walk_state) {
status = AE_NO_MEMORY;
goto cleanup;
}
status = acpi_ds_init_aml_walk(walk_state, op, info->node,
info->obj_desc->method.aml_start,
info->obj_desc->method.aml_length, info,
info->pass_number);
if (ACPI_FAILURE(status)) {
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
if (info->obj_desc->method.info_flags & ACPI_METHOD_MODULE_LEVEL) {
walk_state->parse_flags |= ACPI_PARSE_MODULE_LEVEL;
}
if (info->obj_desc->method.info_flags & ACPI_METHOD_INTERNAL_ONLY) {
status =
info->obj_desc->method.dispatch.implementation(walk_state);
info->return_object = walk_state->return_desc;
acpi_ds_scope_stack_clear(walk_state);
acpi_ps_cleanup_scope(&walk_state->parser_state);
acpi_ds_terminate_control_method(walk_state->method_desc,
walk_state);
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
if (acpi_gbl_enable_interpreter_slack) {
walk_state->implicit_return_obj =
acpi_ut_create_integer_object((u64) 0);
if (!walk_state->implicit_return_obj) {
status = AE_NO_MEMORY;
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
}
status = acpi_ps_parse_aml(walk_state);
cleanup:
acpi_ps_delete_parse_tree(op);
acpi_ps_update_parameter_list(info, REF_DECREMENT);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (info->return_object) {
ACPI_DEBUG_PRINT((ACPI_DB_PARSE, "Method returned ObjDesc=%p\n",
info->return_object));
ACPI_DUMP_STACK_ENTRY(info->return_object);
status = AE_CTRL_RETURN_VALUE;
}
return_ACPI_STATUS(status);
}
static void
acpi_ps_update_parameter_list(struct acpi_evaluate_info *info, u16 action)
{
u32 i;
if (info->parameters) {
for (i = 0; info->parameters[i]; i++) {
(void)acpi_ut_update_object_reference(info->
parameters[i],
action);
}
}
}
