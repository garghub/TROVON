acpi_status
acpi_ds_init_callbacks(struct acpi_walk_state *walk_state, u32 pass_number)
{
switch (pass_number) {
case 0:
walk_state->parse_flags = ACPI_PARSE_LOAD_PASS1 |
ACPI_PARSE_DELETE_TREE | ACPI_PARSE_DISASSEMBLE;
walk_state->descending_callback = NULL;
walk_state->ascending_callback = NULL;
break;
case 1:
walk_state->parse_flags = ACPI_PARSE_LOAD_PASS1 |
ACPI_PARSE_DELETE_TREE;
walk_state->descending_callback = acpi_ds_load1_begin_op;
walk_state->ascending_callback = acpi_ds_load1_end_op;
break;
case 2:
walk_state->parse_flags = ACPI_PARSE_LOAD_PASS1 |
ACPI_PARSE_DELETE_TREE;
walk_state->descending_callback = acpi_ds_load2_begin_op;
walk_state->ascending_callback = acpi_ds_load2_end_op;
break;
case 3:
#ifndef ACPI_NO_METHOD_EXECUTION
walk_state->parse_flags |= ACPI_PARSE_EXECUTE |
ACPI_PARSE_DELETE_TREE;
walk_state->descending_callback = acpi_ds_exec_begin_op;
walk_state->ascending_callback = acpi_ds_exec_end_op;
#endif
break;
default:
return (AE_BAD_PARAMETER);
}
return (AE_OK);
}
acpi_status
acpi_ds_load1_begin_op(struct acpi_walk_state *walk_state,
union acpi_parse_object **out_op)
{
union acpi_parse_object *op;
struct acpi_namespace_node *node;
acpi_status status;
acpi_object_type object_type;
char *path;
u32 flags;
ACPI_FUNCTION_TRACE(ds_load1_begin_op);
op = walk_state->op;
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "Op=%p State=%p\n", op,
walk_state));
if (op) {
if (!(walk_state->op_info->flags & AML_NAMED)) {
*out_op = op;
return_ACPI_STATUS(AE_OK);
}
if (op->common.node) {
*out_op = op;
return_ACPI_STATUS(AE_OK);
}
}
path = acpi_ps_get_next_namestring(&walk_state->parser_state);
object_type = walk_state->op_info->object_type;
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"State=%p Op=%p [%s]\n", walk_state, op,
acpi_ut_get_type_name(object_type)));
switch (walk_state->opcode) {
case AML_SCOPE_OP:
status =
acpi_ns_lookup(walk_state->scope_info, path, object_type,
ACPI_IMODE_EXECUTE, ACPI_NS_SEARCH_PARENT,
walk_state, &(node));
#ifdef ACPI_ASL_COMPILER
if (status == AE_NOT_FOUND) {
acpi_dm_add_op_to_external_list(op, path,
ACPI_TYPE_DEVICE, 0, 0);
status =
acpi_ns_lookup(walk_state->scope_info, path,
object_type, ACPI_IMODE_LOAD_PASS1,
ACPI_NS_SEARCH_PARENT, walk_state,
&node);
}
#endif
if (ACPI_FAILURE(status)) {
ACPI_ERROR_NAMESPACE(path, status);
return_ACPI_STATUS(status);
}
switch (node->type) {
case ACPI_TYPE_ANY:
case ACPI_TYPE_LOCAL_SCOPE:
case ACPI_TYPE_DEVICE:
case ACPI_TYPE_POWER:
case ACPI_TYPE_PROCESSOR:
case ACPI_TYPE_THERMAL:
break;
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_BUFFER:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Type override - [%4.4s] had invalid type (%s) "
"for Scope operator, changed to type ANY\n",
acpi_ut_get_node_name(node),
acpi_ut_get_type_name(node->type)));
node->type = ACPI_TYPE_ANY;
walk_state->scope_info->common.value = ACPI_TYPE_ANY;
break;
case ACPI_TYPE_METHOD:
if ((node == acpi_gbl_root_node) &&
(walk_state->
parse_flags & ACPI_PARSE_MODULE_LEVEL)) {
break;
}
default:
ACPI_ERROR((AE_INFO,
"Invalid type (%s) for target of "
"Scope operator [%4.4s] (Cannot override)",
acpi_ut_get_type_name(node->type),
acpi_ut_get_node_name(node)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
break;
default:
if (walk_state->deferred_node) {
node = walk_state->deferred_node;
status = AE_OK;
break;
}
if (walk_state->method_node) {
node = NULL;
status = AE_OK;
break;
}
flags = ACPI_NS_NO_UPSEARCH;
if ((walk_state->opcode != AML_SCOPE_OP) &&
(!(walk_state->parse_flags & ACPI_PARSE_DEFERRED_OP))) {
if (walk_state->namespace_override) {
flags |= ACPI_NS_OVERRIDE_IF_FOUND;
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"[%s] Override allowed\n",
acpi_ut_get_type_name
(object_type)));
} else {
flags |= ACPI_NS_ERROR_IF_FOUND;
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"[%s] Cannot already exist\n",
acpi_ut_get_type_name
(object_type)));
}
} else {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"[%s] Both Find or Create allowed\n",
acpi_ut_get_type_name(object_type)));
}
status =
acpi_ns_lookup(walk_state->scope_info, path, object_type,
ACPI_IMODE_LOAD_PASS1, flags, walk_state,
&node);
if (ACPI_FAILURE(status)) {
if (status == AE_ALREADY_EXISTS) {
if (node->flags & ANOBJ_IS_EXTERNAL) {
node->flags &= ~ANOBJ_IS_EXTERNAL;
node->type = (u8) object_type;
if (acpi_ns_opens_scope(object_type)) {
status =
acpi_ds_scope_stack_push
(node, object_type,
walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS
(status);
}
}
status = AE_OK;
}
}
if (ACPI_FAILURE(status)) {
ACPI_ERROR_NAMESPACE(path, status);
return_ACPI_STATUS(status);
}
}
break;
}
if (!op) {
op = acpi_ps_alloc_op(walk_state->opcode, walk_state->aml);
if (!op) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
}
#if (defined (ACPI_NO_METHOD_EXECUTION) || defined (ACPI_CONSTANT_EVAL_ONLY))
op->named.path = path;
#endif
if (node) {
op->common.node = node;
op->named.name = node->name.integer;
}
acpi_ps_append_arg(acpi_ps_get_parent_scope(&walk_state->parser_state),
op);
*out_op = op;
return_ACPI_STATUS(status);
}
acpi_status acpi_ds_load1_end_op(struct acpi_walk_state *walk_state)
{
union acpi_parse_object *op;
acpi_object_type object_type;
acpi_status status = AE_OK;
#ifdef ACPI_ASL_COMPILER
u8 param_count;
#endif
ACPI_FUNCTION_TRACE(ds_load1_end_op);
op = walk_state->op;
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "Op=%p State=%p\n", op,
walk_state));
if (!(walk_state->op_info->flags & (AML_NAMED | AML_FIELD))) {
return_ACPI_STATUS(AE_OK);
}
object_type = walk_state->op_info->object_type;
#ifndef ACPI_NO_METHOD_EXECUTION
if (walk_state->op_info->flags & AML_FIELD) {
if (!walk_state->method_node) {
if (walk_state->opcode == AML_FIELD_OP ||
walk_state->opcode == AML_BANK_FIELD_OP ||
walk_state->opcode == AML_INDEX_FIELD_OP) {
status =
acpi_ds_init_field_objects(op, walk_state);
}
}
return_ACPI_STATUS(status);
}
if (!walk_state->method_node) {
if (op->common.aml_opcode == AML_REGION_OP) {
status =
acpi_ex_create_region(op->named.data,
op->named.length,
(acpi_adr_space_type)
((op->common.value.arg)->
common.value.integer),
walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
} else if (op->common.aml_opcode == AML_DATA_REGION_OP) {
status =
acpi_ex_create_region(op->named.data,
op->named.length,
ACPI_ADR_SPACE_DATA_TABLE,
walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
}
#endif
if (op->common.aml_opcode == AML_NAME_OP) {
if (op->common.value.arg) {
object_type = (acpi_ps_get_opcode_info((op->common.
value.arg)->
common.
aml_opcode))->
object_type;
if (op->common.node) {
op->common.node->type = (u8) object_type;
}
}
}
#ifdef ACPI_ASL_COMPILER
if (acpi_gbl_disasm_flag &&
op->common.node && op->common.aml_opcode == AML_EXTERNAL_OP) {
param_count =
(u8)op->common.value.arg->common.next->common.value.integer;
object_type = (u8)op->common.value.arg->common.value.integer;
op->common.node->flags |= ANOBJ_IS_EXTERNAL;
op->common.node->type = (u8)object_type;
acpi_dm_create_subobject_for_external((u8)object_type,
&op->common.node,
param_count);
acpi_dm_add_op_to_external_list(op, op->named.path,
(u8)object_type, param_count,
ACPI_EXT_ORIGIN_FROM_OPCODE |
ACPI_EXT_RESOLVED_REFERENCE);
}
#endif
if (!walk_state->method_node) {
if (op->common.aml_opcode == AML_METHOD_OP) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"LOADING-Method: State=%p Op=%p NamedObj=%p\n",
walk_state, op, op->named.node));
if (!acpi_ns_get_attached_object(op->named.node)) {
walk_state->operands[0] =
ACPI_CAST_PTR(void, op->named.node);
walk_state->num_operands = 1;
status =
acpi_ds_create_operands(walk_state,
op->common.value.
arg);
if (ACPI_SUCCESS(status)) {
status =
acpi_ex_create_method(op->named.
data,
op->named.
length,
walk_state);
}
walk_state->operands[0] = NULL;
walk_state->num_operands = 0;
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
}
}
if (!walk_state->method_node &&
op->common.aml_opcode != AML_EXTERNAL_OP &&
acpi_ns_opens_scope(object_type)) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"(%s): Popping scope for Op %p\n",
acpi_ut_get_type_name(object_type), op));
status = acpi_ds_scope_stack_pop(walk_state);
}
return_ACPI_STATUS(status);
}
