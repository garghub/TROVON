void
acpi_db_set_method_breakpoint(char *location,
struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
u32 address;
u32 aml_offset;
if (!op) {
acpi_os_printf("There is no method currently executing\n");
return;
}
address = strtoul(location, NULL, 16);
aml_offset = (u32)ACPI_PTR_DIFF(op->common.aml,
walk_state->parser_state.aml_start);
if (address <= aml_offset) {
acpi_os_printf("Breakpoint %X is beyond current address %X\n",
address, aml_offset);
}
walk_state->user_breakpoint = address;
acpi_os_printf("Breakpoint set at AML offset %X\n", address);
}
void acpi_db_set_method_call_breakpoint(union acpi_parse_object *op)
{
if (!op) {
acpi_os_printf("There is no method currently executing\n");
return;
}
acpi_gbl_step_to_next_call = TRUE;
}
void acpi_db_set_method_data(char *type_arg, char *index_arg, char *value_arg)
{
char type;
u32 index;
u32 value;
struct acpi_walk_state *walk_state;
union acpi_operand_object *obj_desc;
acpi_status status;
struct acpi_namespace_node *node;
acpi_ut_strupr(type_arg);
type = type_arg[0];
if ((type != 'L') && (type != 'A') && (type != 'N')) {
acpi_os_printf("Invalid SET operand: %s\n", type_arg);
return;
}
value = strtoul(value_arg, NULL, 16);
if (type == 'N') {
node = acpi_db_convert_to_node(index_arg);
if (!node) {
return;
}
if (node->type != ACPI_TYPE_INTEGER) {
acpi_os_printf("Can only set Integer nodes\n");
return;
}
obj_desc = node->object;
obj_desc->integer.value = value;
return;
}
index = strtoul(index_arg, NULL, 16);
walk_state = acpi_ds_get_current_walk_state(acpi_gbl_current_walk_list);
if (!walk_state) {
acpi_os_printf("There is no method currently executing\n");
return;
}
obj_desc = acpi_ut_create_integer_object((u64)value);
if (!obj_desc) {
acpi_os_printf("Could not create an internal object\n");
return;
}
switch (type) {
case 'A':
if (index > ACPI_METHOD_MAX_ARG) {
acpi_os_printf("Arg%u - Invalid argument name\n",
index);
goto cleanup;
}
status = acpi_ds_store_object_to_local(ACPI_REFCLASS_ARG,
index, obj_desc,
walk_state);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
obj_desc = walk_state->arguments[index].object;
acpi_os_printf("Arg%u: ", index);
acpi_db_display_internal_object(obj_desc, walk_state);
break;
case 'L':
if (index > ACPI_METHOD_MAX_LOCAL) {
acpi_os_printf
("Local%u - Invalid local variable name\n", index);
goto cleanup;
}
status = acpi_ds_store_object_to_local(ACPI_REFCLASS_LOCAL,
index, obj_desc,
walk_state);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
obj_desc = walk_state->local_variables[index].object;
acpi_os_printf("Local%u: ", index);
acpi_db_display_internal_object(obj_desc, walk_state);
break;
default:
break;
}
cleanup:
acpi_ut_remove_reference(obj_desc);
}
void acpi_db_disassemble_aml(char *statements, union acpi_parse_object *op)
{
u32 num_statements = 8;
if (!op) {
acpi_os_printf("There is no method currently executing\n");
return;
}
if (statements) {
num_statements = strtoul(statements, NULL, 0);
}
#ifdef ACPI_DISASSEMBLER
acpi_dm_disassemble(NULL, op, num_statements);
#endif
}
acpi_status acpi_db_disassemble_method(char *name)
{
acpi_status status;
union acpi_parse_object *op;
struct acpi_walk_state *walk_state;
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *method;
method = acpi_db_convert_to_node(name);
if (!method) {
return (AE_BAD_PARAMETER);
}
if (method->type != ACPI_TYPE_METHOD) {
ACPI_ERROR((AE_INFO, "%s (%s): Object must be a control method",
name, acpi_ut_get_type_name(method->type)));
return (AE_BAD_PARAMETER);
}
obj_desc = method->object;
op = acpi_ps_create_scope_op(obj_desc->method.aml_start);
if (!op) {
return (AE_NO_MEMORY);
}
walk_state = acpi_ds_create_walk_state(0, op, NULL, NULL);
if (!walk_state) {
return (AE_NO_MEMORY);
}
status = acpi_ds_init_aml_walk(walk_state, op, NULL,
obj_desc->method.aml_start,
obj_desc->method.aml_length, NULL,
ACPI_IMODE_LOAD_PASS1);
if (ACPI_FAILURE(status)) {
return (status);
}
status = acpi_ut_allocate_owner_id(&obj_desc->method.owner_id);
walk_state->owner_id = obj_desc->method.owner_id;
status = acpi_ds_scope_stack_push(method, method->type, walk_state);
if (ACPI_FAILURE(status)) {
return (status);
}
walk_state->parse_flags &= ~ACPI_PARSE_DELETE_TREE;
walk_state->parse_flags |= ACPI_PARSE_DISASSEMBLE;
status = acpi_ps_parse_aml(walk_state);
#ifdef ACPI_DISASSEMBLER
(void)acpi_dm_parse_deferred_ops(op);
acpi_gbl_dm_opt_verbose = FALSE;
acpi_dm_disassemble(NULL, op, 0);
acpi_gbl_dm_opt_verbose = TRUE;
#endif
acpi_ps_delete_parse_tree(op);
acpi_ns_delete_namespace_subtree(method);
acpi_ns_delete_namespace_by_owner(obj_desc->method.owner_id);
acpi_ut_release_owner_id(&obj_desc->method.owner_id);
return (AE_OK);
}
