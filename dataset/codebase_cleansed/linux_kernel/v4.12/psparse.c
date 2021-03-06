u32 acpi_ps_get_opcode_size(u32 opcode)
{
if (opcode > 0x00FF) {
return (2);
}
return (1);
}
u16 acpi_ps_peek_opcode(struct acpi_parse_state * parser_state)
{
u8 *aml;
u16 opcode;
aml = parser_state->aml;
opcode = (u16) ACPI_GET8(aml);
if (opcode == AML_EXTENDED_PREFIX) {
aml++;
opcode = (u16) ((opcode << 8) | ACPI_GET8(aml));
}
return (opcode);
}
acpi_status
acpi_ps_complete_this_op(struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
union acpi_parse_object *prev;
union acpi_parse_object *next;
const struct acpi_opcode_info *parent_info;
union acpi_parse_object *replacement_op = NULL;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE_PTR(ps_complete_this_op, op);
if (!op) {
return_ACPI_STATUS(AE_OK);
}
acpi_ex_stop_trace_opcode(op, walk_state);
if (((walk_state->parse_flags & ACPI_PARSE_TREE_MASK) !=
ACPI_PARSE_DELETE_TREE)
|| (walk_state->op_info->class == AML_CLASS_ARGUMENT)) {
return_ACPI_STATUS(AE_OK);
}
if (op->common.parent) {
prev = op->common.parent->common.value.arg;
if (!prev) {
goto cleanup;
}
parent_info =
acpi_ps_get_opcode_info(op->common.parent->common.
aml_opcode);
switch (parent_info->class) {
case AML_CLASS_CONTROL:
break;
case AML_CLASS_CREATE:
replacement_op =
acpi_ps_alloc_op(AML_INT_RETURN_VALUE_OP,
op->common.aml);
if (!replacement_op) {
status = AE_NO_MEMORY;
}
break;
case AML_CLASS_NAMED_OBJECT:
if ((op->common.parent->common.aml_opcode ==
AML_REGION_OP)
|| (op->common.parent->common.aml_opcode ==
AML_DATA_REGION_OP)
|| (op->common.parent->common.aml_opcode ==
AML_BUFFER_OP)
|| (op->common.parent->common.aml_opcode ==
AML_PACKAGE_OP)
|| (op->common.parent->common.aml_opcode ==
AML_BANK_FIELD_OP)
|| (op->common.parent->common.aml_opcode ==
AML_VARIABLE_PACKAGE_OP)) {
replacement_op =
acpi_ps_alloc_op(AML_INT_RETURN_VALUE_OP,
op->common.aml);
if (!replacement_op) {
status = AE_NO_MEMORY;
}
} else
if ((op->common.parent->common.aml_opcode ==
AML_NAME_OP)
&& (walk_state->pass_number <=
ACPI_IMODE_LOAD_PASS2)) {
if ((op->common.aml_opcode == AML_BUFFER_OP)
|| (op->common.aml_opcode == AML_PACKAGE_OP)
|| (op->common.aml_opcode ==
AML_VARIABLE_PACKAGE_OP)) {
replacement_op =
acpi_ps_alloc_op(op->common.
aml_opcode,
op->common.aml);
if (!replacement_op) {
status = AE_NO_MEMORY;
} else {
replacement_op->named.data =
op->named.data;
replacement_op->named.length =
op->named.length;
}
}
}
break;
default:
replacement_op =
acpi_ps_alloc_op(AML_INT_RETURN_VALUE_OP,
op->common.aml);
if (!replacement_op) {
status = AE_NO_MEMORY;
}
}
if (prev == op) {
if (replacement_op) {
replacement_op->common.parent =
op->common.parent;
replacement_op->common.value.arg = NULL;
replacement_op->common.node = op->common.node;
op->common.parent->common.value.arg =
replacement_op;
replacement_op->common.next = op->common.next;
} else {
op->common.parent->common.value.arg =
op->common.next;
}
}
else
while (prev) {
next = prev->common.next;
if (next == op) {
if (replacement_op) {
replacement_op->common.parent =
op->common.parent;
replacement_op->common.value.
arg = NULL;
replacement_op->common.node =
op->common.node;
prev->common.next =
replacement_op;
replacement_op->common.next =
op->common.next;
next = NULL;
} else {
prev->common.next =
op->common.next;
next = NULL;
}
}
prev = next;
}
}
cleanup:
acpi_ps_delete_parse_tree(op);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ps_next_parse_state(struct acpi_walk_state *walk_state,
union acpi_parse_object *op,
acpi_status callback_status)
{
struct acpi_parse_state *parser_state = &walk_state->parser_state;
acpi_status status = AE_CTRL_PENDING;
ACPI_FUNCTION_TRACE_PTR(ps_next_parse_state, op);
switch (callback_status) {
case AE_CTRL_TERMINATE:
parser_state->aml = parser_state->aml_end;
status = AE_CTRL_TERMINATE;
break;
case AE_CTRL_BREAK:
parser_state->aml = walk_state->aml_last_while;
walk_state->control_state->common.value = FALSE;
status = AE_CTRL_BREAK;
break;
case AE_CTRL_CONTINUE:
parser_state->aml = walk_state->aml_last_while;
status = AE_CTRL_CONTINUE;
break;
case AE_CTRL_PENDING:
parser_state->aml = walk_state->aml_last_while;
break;
#if 0
case AE_CTRL_SKIP:
parser_state->aml = parser_state->scope->parse_scope.pkg_end;
status = AE_OK;
break;
#endif
case AE_CTRL_TRUE:
parser_state->aml = acpi_ps_get_next_package_end(parser_state);
status = AE_CTRL_PENDING;
break;
case AE_CTRL_FALSE:
parser_state->aml = parser_state->scope->parse_scope.pkg_end;
walk_state->control_state->common.value = FALSE;
status = AE_CTRL_END;
break;
case AE_CTRL_TRANSFER:
status = AE_CTRL_TRANSFER;
walk_state->prev_op = op;
walk_state->method_call_op = op;
walk_state->method_call_node =
(op->common.value.arg)->common.node;
walk_state->return_used =
acpi_ds_is_result_used(op, walk_state);
break;
default:
status = callback_status;
if ((callback_status & AE_CODE_MASK) == AE_CODE_CONTROL) {
status = AE_OK;
}
break;
}
return_ACPI_STATUS(status);
}
acpi_status acpi_ps_parse_aml(struct acpi_walk_state *walk_state)
{
acpi_status status;
struct acpi_thread_state *thread;
struct acpi_thread_state *prev_walk_list = acpi_gbl_current_walk_list;
struct acpi_walk_state *previous_walk_state;
ACPI_FUNCTION_TRACE(ps_parse_aml);
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"Entered with WalkState=%p Aml=%p size=%X\n",
walk_state, walk_state->parser_state.aml,
walk_state->parser_state.aml_size));
if (!walk_state->parser_state.aml) {
return_ACPI_STATUS(AE_NULL_OBJECT);
}
thread = acpi_ut_create_thread_state();
if (!thread) {
if (walk_state->method_desc) {
acpi_ds_terminate_control_method(walk_state->
method_desc,
walk_state);
}
acpi_ds_delete_walk_state(walk_state);
return_ACPI_STATUS(AE_NO_MEMORY);
}
walk_state->thread = thread;
if (walk_state->method_desc) {
walk_state->thread->current_sync_level =
walk_state->method_desc->method.sync_level;
}
acpi_ds_push_walk_state(walk_state, thread);
acpi_gbl_current_walk_list = thread;
ACPI_DEBUG_PRINT((ACPI_DB_PARSE, "State=%p\n", walk_state));
status = AE_OK;
while (walk_state) {
if (ACPI_SUCCESS(status)) {
status = acpi_ps_parse_loop(walk_state);
}
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"Completed one call to walk loop, %s State=%p\n",
acpi_format_exception(status), walk_state));
if (status == AE_CTRL_TRANSFER) {
status =
acpi_ds_call_control_method(thread, walk_state,
NULL);
if (ACPI_FAILURE(status)) {
status =
acpi_ds_method_error(status, walk_state);
}
walk_state = acpi_ds_get_current_walk_state(thread);
continue;
} else if (status == AE_CTRL_TERMINATE) {
status = AE_OK;
} else if ((status != AE_OK) && (walk_state->method_desc)) {
acpi_ex_exit_interpreter();
ACPI_ERROR_METHOD("Method parse/execution failed",
walk_state->method_node, NULL,
status);
acpi_ex_enter_interpreter();
if ((status == AE_ALREADY_EXISTS) &&
(!(walk_state->method_desc->method.info_flags &
ACPI_METHOD_SERIALIZED))) {
walk_state->method_desc->method.info_flags |=
ACPI_METHOD_SERIALIZED_PENDING;
}
}
walk_state = acpi_ds_pop_walk_state(thread);
acpi_ds_scope_stack_clear(walk_state);
if (((walk_state->parse_flags & ACPI_PARSE_MODE_MASK) ==
ACPI_PARSE_EXECUTE &&
!(walk_state->parse_flags & ACPI_PARSE_MODULE_LEVEL)) ||
(ACPI_FAILURE(status))) {
acpi_ds_terminate_control_method(walk_state->
method_desc,
walk_state);
}
acpi_ps_cleanup_scope(&walk_state->parser_state);
previous_walk_state = walk_state;
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"ReturnValue=%p, ImplicitValue=%p State=%p\n",
walk_state->return_desc,
walk_state->implicit_return_obj, walk_state));
walk_state = acpi_ds_get_current_walk_state(thread);
if (walk_state) {
if (ACPI_SUCCESS(status)) {
if (!previous_walk_state->return_desc) {
if (acpi_gbl_enable_interpreter_slack &&
!previous_walk_state->
implicit_return_obj) {
previous_walk_state->
implicit_return_obj =
acpi_ut_create_integer_object
((u64) 0);
if (!previous_walk_state->
implicit_return_obj) {
return_ACPI_STATUS
(AE_NO_MEMORY);
}
}
status =
acpi_ds_restart_control_method
(walk_state,
previous_walk_state->
implicit_return_obj);
} else {
acpi_ds_clear_implicit_return
(previous_walk_state);
status =
acpi_ds_restart_control_method
(walk_state,
previous_walk_state->return_desc);
}
if (ACPI_SUCCESS(status)) {
walk_state->walk_type |=
ACPI_WALK_METHOD_RESTART;
}
} else {
acpi_ut_remove_reference(previous_walk_state->
return_desc);
acpi_ds_clear_implicit_return
(previous_walk_state);
}
}
else if (previous_walk_state->caller_return_desc) {
if (previous_walk_state->implicit_return_obj) {
*(previous_walk_state->caller_return_desc) =
previous_walk_state->implicit_return_obj;
} else {
*(previous_walk_state->caller_return_desc) =
previous_walk_state->return_desc;
}
} else {
if (previous_walk_state->return_desc) {
acpi_ut_remove_reference(previous_walk_state->
return_desc);
}
if (previous_walk_state->implicit_return_obj) {
acpi_ut_remove_reference(previous_walk_state->
implicit_return_obj);
}
}
acpi_ds_delete_walk_state(previous_walk_state);
}
acpi_ex_release_all_mutexes(thread);
acpi_ut_delete_generic_state(ACPI_CAST_PTR
(union acpi_generic_state, thread));
acpi_gbl_current_walk_list = prev_walk_list;
return_ACPI_STATUS(status);
}
