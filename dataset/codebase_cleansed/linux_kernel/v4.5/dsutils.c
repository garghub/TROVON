void acpi_ds_clear_implicit_return(struct acpi_walk_state *walk_state)
{
ACPI_FUNCTION_NAME(ds_clear_implicit_return);
if (!acpi_gbl_enable_interpreter_slack) {
return;
}
if (walk_state->implicit_return_obj) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Removing reference on stale implicit return obj %p\n",
walk_state->implicit_return_obj));
acpi_ut_remove_reference(walk_state->implicit_return_obj);
walk_state->implicit_return_obj = NULL;
}
}
u8
acpi_ds_do_implicit_return(union acpi_operand_object *return_desc,
struct acpi_walk_state *walk_state, u8 add_reference)
{
ACPI_FUNCTION_NAME(ds_do_implicit_return);
if ((!acpi_gbl_enable_interpreter_slack) || (!return_desc)) {
return (FALSE);
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Result %p will be implicitly returned; Prev=%p\n",
return_desc, walk_state->implicit_return_obj));
if (walk_state->implicit_return_obj) {
if (walk_state->implicit_return_obj == return_desc) {
return (TRUE);
}
acpi_ds_clear_implicit_return(walk_state);
}
walk_state->implicit_return_obj = return_desc;
if (add_reference) {
acpi_ut_add_reference(return_desc);
}
return (TRUE);
}
u8
acpi_ds_is_result_used(union acpi_parse_object * op,
struct acpi_walk_state * walk_state)
{
const struct acpi_opcode_info *parent_info;
ACPI_FUNCTION_TRACE_PTR(ds_is_result_used, op);
if (!op) {
ACPI_ERROR((AE_INFO, "Null Op"));
return_UINT8(TRUE);
}
(void)acpi_ds_do_implicit_return(walk_state->result_obj, walk_state,
TRUE);
if ((!op->common.parent) ||
(op->common.parent->common.aml_opcode == AML_SCOPE_OP)) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"At Method level, result of [%s] not used\n",
acpi_ps_get_opcode_name(op->common.
aml_opcode)));
return_UINT8(FALSE);
}
parent_info =
acpi_ps_get_opcode_info(op->common.parent->common.aml_opcode);
if (parent_info->class == AML_CLASS_UNKNOWN) {
ACPI_ERROR((AE_INFO, "Unknown parent opcode Op=%p", op));
return_UINT8(FALSE);
}
switch (parent_info->class) {
case AML_CLASS_CONTROL:
switch (op->common.parent->common.aml_opcode) {
case AML_RETURN_OP:
goto result_used;
case AML_IF_OP:
case AML_WHILE_OP:
if ((walk_state->control_state->common.state ==
ACPI_CONTROL_PREDICATE_EXECUTING) &&
(walk_state->control_state->control.predicate_op ==
op)) {
goto result_used;
}
break;
default:
break;
}
goto result_not_used;
case AML_CLASS_CREATE:
goto result_used;
case AML_CLASS_NAMED_OBJECT:
if ((op->common.parent->common.aml_opcode == AML_REGION_OP) ||
(op->common.parent->common.aml_opcode == AML_DATA_REGION_OP)
|| (op->common.parent->common.aml_opcode == AML_PACKAGE_OP)
|| (op->common.parent->common.aml_opcode ==
AML_VAR_PACKAGE_OP)
|| (op->common.parent->common.aml_opcode == AML_BUFFER_OP)
|| (op->common.parent->common.aml_opcode ==
AML_INT_EVAL_SUBTREE_OP)
|| (op->common.parent->common.aml_opcode ==
AML_BANK_FIELD_OP)) {
goto result_used;
}
goto result_not_used;
default:
goto result_used;
}
result_used:
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Result of [%s] used by Parent [%s] Op=%p\n",
acpi_ps_get_opcode_name(op->common.aml_opcode),
acpi_ps_get_opcode_name(op->common.parent->common.
aml_opcode), op));
return_UINT8(TRUE);
result_not_used:
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Result of [%s] not used by Parent [%s] Op=%p\n",
acpi_ps_get_opcode_name(op->common.aml_opcode),
acpi_ps_get_opcode_name(op->common.parent->common.
aml_opcode), op));
return_UINT8(FALSE);
}
void
acpi_ds_delete_result_if_not_used(union acpi_parse_object *op,
union acpi_operand_object *result_obj,
struct acpi_walk_state *walk_state)
{
union acpi_operand_object *obj_desc;
acpi_status status;
ACPI_FUNCTION_TRACE_PTR(ds_delete_result_if_not_used, result_obj);
if (!op) {
ACPI_ERROR((AE_INFO, "Null Op"));
return_VOID;
}
if (!result_obj) {
return_VOID;
}
if (!acpi_ds_is_result_used(op, walk_state)) {
status = acpi_ds_result_pop(&obj_desc, walk_state);
if (ACPI_SUCCESS(status)) {
acpi_ut_remove_reference(result_obj);
}
}
return_VOID;
}
acpi_status acpi_ds_resolve_operands(struct acpi_walk_state *walk_state)
{
u32 i;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE_PTR(ds_resolve_operands, walk_state);
for (i = 0; i < walk_state->num_operands; i++) {
status =
acpi_ex_resolve_to_value(&walk_state->operands[i],
walk_state);
if (ACPI_FAILURE(status)) {
break;
}
}
return_ACPI_STATUS(status);
}
void acpi_ds_clear_operands(struct acpi_walk_state *walk_state)
{
u32 i;
ACPI_FUNCTION_TRACE_PTR(ds_clear_operands, walk_state);
for (i = 0; i < walk_state->num_operands; i++) {
acpi_ut_remove_reference(walk_state->operands[i]);
walk_state->operands[i] = NULL;
}
walk_state->num_operands = 0;
return_VOID;
}
acpi_status
acpi_ds_create_operand(struct acpi_walk_state *walk_state,
union acpi_parse_object *arg, u32 arg_index)
{
acpi_status status = AE_OK;
char *name_string;
u32 name_length;
union acpi_operand_object *obj_desc;
union acpi_parse_object *parent_op;
u16 opcode;
acpi_interpreter_mode interpreter_mode;
const struct acpi_opcode_info *op_info;
ACPI_FUNCTION_TRACE_PTR(ds_create_operand, arg);
if ((arg->common.aml_opcode == AML_INT_NAMEPATH_OP) &&
(arg->common.value.string) &&
!(arg->common.flags & ACPI_PARSEOP_IN_STACK)) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "Getting a name: Arg=%p\n",
arg));
status = acpi_ex_get_name_string(ACPI_TYPE_ANY,
arg->common.value.buffer,
&name_string, &name_length);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if ((walk_state->deferred_node) &&
(walk_state->deferred_node->type == ACPI_TYPE_BUFFER_FIELD)
&& (arg_index == (u32)
((walk_state->opcode == AML_CREATE_FIELD_OP) ? 3 : 2))) {
obj_desc =
ACPI_CAST_PTR(union acpi_operand_object,
walk_state->deferred_node);
status = AE_OK;
} else {
parent_op = arg->common.parent;
op_info =
acpi_ps_get_opcode_info(parent_op->common.
aml_opcode);
if ((op_info->flags & AML_NSNODE) &&
(parent_op->common.aml_opcode !=
AML_INT_METHODCALL_OP)
&& (parent_op->common.aml_opcode != AML_REGION_OP)
&& (parent_op->common.aml_opcode !=
AML_INT_NAMEPATH_OP)) {
interpreter_mode = ACPI_IMODE_LOAD_PASS2;
} else {
interpreter_mode = ACPI_IMODE_EXECUTE;
}
status =
acpi_ns_lookup(walk_state->scope_info, name_string,
ACPI_TYPE_ANY, interpreter_mode,
ACPI_NS_SEARCH_PARENT |
ACPI_NS_DONT_OPEN_SCOPE, walk_state,
ACPI_CAST_INDIRECT_PTR(struct
acpi_namespace_node,
&obj_desc));
if (status == AE_NOT_FOUND) {
if (parent_op->common.aml_opcode ==
AML_COND_REF_OF_OP) {
obj_desc =
ACPI_CAST_PTR(union
acpi_operand_object,
acpi_gbl_root_node);
status = AE_OK;
} else if (parent_op->common.aml_opcode ==
AML_EXTERNAL_OP) {
obj_desc =
acpi_ut_create_string_object((acpi_size) name_length);
strncpy(obj_desc->string.pointer,
name_string, name_length);
status = AE_OK;
} else {
status = AE_AML_NAME_NOT_FOUND;
}
}
if (ACPI_FAILURE(status)) {
ACPI_ERROR_NAMESPACE(name_string, status);
}
}
ACPI_FREE(name_string);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ds_obj_stack_push(obj_desc, walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_db_display_argument_object(obj_desc, walk_state);
} else {
if ((arg->common.aml_opcode == AML_INT_NAMEPATH_OP) &&
!(arg->common.flags & ACPI_PARSEOP_IN_STACK)) {
opcode = AML_ZERO_OP;
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Null namepath: Arg=%p\n", arg));
} else {
opcode = arg->common.aml_opcode;
}
op_info = acpi_ps_get_opcode_info(opcode);
if (op_info->object_type == ACPI_TYPE_INVALID) {
return_ACPI_STATUS(AE_NOT_IMPLEMENTED);
}
if ((op_info->flags & AML_HAS_RETVAL) ||
(arg->common.flags & ACPI_PARSEOP_IN_STACK)) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Argument previously created, already stacked\n"));
acpi_db_display_argument_object(walk_state->
operands[walk_state->
num_operands -
1],
walk_state);
status = acpi_ds_result_pop(&obj_desc, walk_state);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Missing or null operand"));
return_ACPI_STATUS(status);
}
} else {
obj_desc =
acpi_ut_create_internal_object(op_info->
object_type);
if (!obj_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
status =
acpi_ds_init_object_from_op(walk_state, arg, opcode,
&obj_desc);
if (ACPI_FAILURE(status)) {
acpi_ut_delete_object_desc(obj_desc);
return_ACPI_STATUS(status);
}
}
status = acpi_ds_obj_stack_push(obj_desc, walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_db_display_argument_object(obj_desc, walk_state);
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ds_create_operands(struct acpi_walk_state *walk_state,
union acpi_parse_object *first_arg)
{
acpi_status status = AE_OK;
union acpi_parse_object *arg;
union acpi_parse_object *arguments[ACPI_OBJ_NUM_OPERANDS];
u32 arg_count = 0;
u32 index = walk_state->num_operands;
u32 i;
ACPI_FUNCTION_TRACE_PTR(ds_create_operands, first_arg);
arg = first_arg;
while (arg) {
if (index >= ACPI_OBJ_NUM_OPERANDS) {
return_ACPI_STATUS(AE_BAD_DATA);
}
arguments[index] = arg;
walk_state->operands[index] = NULL;
arg = arg->common.next;
arg_count++;
index++;
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"NumOperands %d, ArgCount %d, Index %d\n",
walk_state->num_operands, arg_count, index));
index--;
for (i = 0; i < arg_count; i++) {
arg = arguments[index];
walk_state->operand_index = (u8)index;
status = acpi_ds_create_operand(walk_state, arg, index);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Created Arg #%u (%p) %u args total\n",
index, arg, arg_count));
index--;
}
return_ACPI_STATUS(status);
cleanup:
acpi_ds_obj_stack_pop_and_delete(arg_count, walk_state);
ACPI_EXCEPTION((AE_INFO, status, "While creating Arg %u", index));
return_ACPI_STATUS(status);
}
acpi_status acpi_ds_evaluate_name_path(struct acpi_walk_state *walk_state)
{
acpi_status status = AE_OK;
union acpi_parse_object *op = walk_state->op;
union acpi_operand_object **operand = &walk_state->operands[0];
union acpi_operand_object *new_obj_desc;
u8 type;
ACPI_FUNCTION_TRACE_PTR(ds_evaluate_name_path, walk_state);
if (!op->common.parent) {
goto exit;
}
if ((op->common.parent->common.aml_opcode == AML_PACKAGE_OP) ||
(op->common.parent->common.aml_opcode == AML_VAR_PACKAGE_OP) ||
(op->common.parent->common.aml_opcode == AML_REF_OF_OP)) {
goto exit;
}
status = acpi_ds_create_operand(walk_state, op, 0);
if (ACPI_FAILURE(status)) {
goto exit;
}
if (op->common.flags & ACPI_PARSEOP_TARGET) {
new_obj_desc = *operand;
goto push_result;
}
type = (*operand)->common.type;
status = acpi_ex_resolve_to_value(operand, walk_state);
if (ACPI_FAILURE(status)) {
goto exit;
}
if (type == ACPI_TYPE_INTEGER) {
acpi_ut_remove_reference(*operand);
status =
acpi_ut_copy_iobject_to_iobject(*operand, &new_obj_desc,
walk_state);
if (ACPI_FAILURE(status)) {
goto exit;
}
} else {
new_obj_desc = *operand;
}
status = acpi_ds_obj_stack_pop(1, walk_state);
if (ACPI_FAILURE(status)) {
walk_state->result_obj = new_obj_desc;
goto exit;
}
push_result:
walk_state->result_obj = new_obj_desc;
status = acpi_ds_result_push(walk_state->result_obj, walk_state);
if (ACPI_SUCCESS(status)) {
op->common.flags |= ACPI_PARSEOP_IN_STACK;
}
exit:
return_ACPI_STATUS(status);
}
