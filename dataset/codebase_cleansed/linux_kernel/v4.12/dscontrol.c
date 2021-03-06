acpi_status
acpi_ds_exec_begin_control_op(struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
acpi_status status = AE_OK;
union acpi_generic_state *control_state;
ACPI_FUNCTION_NAME(ds_exec_begin_control_op);
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "Op=%p Opcode=%2.2X State=%p\n",
op, op->common.aml_opcode, walk_state));
switch (op->common.aml_opcode) {
case AML_WHILE_OP:
if (walk_state->control_state) {
if (walk_state->control_state->control.
aml_predicate_start ==
(walk_state->parser_state.aml - 1)) {
walk_state->control_state->common.state =
ACPI_CONTROL_CONDITIONAL_EXECUTING;
break;
}
}
case AML_IF_OP:
control_state = acpi_ut_create_control_state();
if (!control_state) {
status = AE_NO_MEMORY;
break;
}
control_state->control.aml_predicate_start =
walk_state->parser_state.aml - 1;
control_state->control.package_end =
walk_state->parser_state.pkg_end;
control_state->control.opcode = op->common.aml_opcode;
acpi_ut_push_generic_state(&walk_state->control_state,
control_state);
break;
case AML_ELSE_OP:
if (walk_state->last_predicate) {
status = AE_CTRL_TRUE;
}
break;
case AML_RETURN_OP:
break;
default:
break;
}
return (status);
}
acpi_status
acpi_ds_exec_end_control_op(struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
acpi_status status = AE_OK;
union acpi_generic_state *control_state;
ACPI_FUNCTION_NAME(ds_exec_end_control_op);
switch (op->common.aml_opcode) {
case AML_IF_OP:
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "[IF_OP] Op=%p\n", op));
walk_state->last_predicate =
(u8)walk_state->control_state->common.value;
control_state =
acpi_ut_pop_generic_state(&walk_state->control_state);
acpi_ut_delete_generic_state(control_state);
break;
case AML_ELSE_OP:
break;
case AML_WHILE_OP:
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "[WHILE_OP] Op=%p\n", op));
control_state = walk_state->control_state;
if (control_state->common.value) {
control_state->control.loop_count++;
if (control_state->control.loop_count >
acpi_gbl_max_loop_iterations) {
status = AE_AML_INFINITE_LOOP;
break;
}
status = AE_CTRL_PENDING;
walk_state->aml_last_while =
control_state->control.aml_predicate_start;
break;
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"[WHILE_OP] termination! Op=%p\n", op));
control_state =
acpi_ut_pop_generic_state(&walk_state->control_state);
acpi_ut_delete_generic_state(control_state);
break;
case AML_RETURN_OP:
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"[RETURN_OP] Op=%p Arg=%p\n", op,
op->common.value.arg));
if (op->common.value.arg) {
acpi_ds_clear_implicit_return(walk_state);
status =
acpi_ds_create_operands(walk_state,
op->common.value.arg);
if (ACPI_FAILURE(status)) {
return (status);
}
status =
acpi_ex_resolve_to_value(&walk_state->operands[0],
walk_state);
if (ACPI_FAILURE(status)) {
return (status);
}
walk_state->return_desc = walk_state->operands[0];
} else if (walk_state->result_count) {
acpi_ds_clear_implicit_return(walk_state);
if ((ACPI_GET_DESCRIPTOR_TYPE
(walk_state->results->results.obj_desc[0]) ==
ACPI_DESC_TYPE_OPERAND)
&& ((walk_state->results->results.obj_desc[0])->
common.type == ACPI_TYPE_LOCAL_REFERENCE)
&& ((walk_state->results->results.obj_desc[0])->
reference.class != ACPI_REFCLASS_INDEX)) {
status =
acpi_ex_resolve_to_value(&walk_state->
results->results.
obj_desc[0],
walk_state);
if (ACPI_FAILURE(status)) {
return (status);
}
}
walk_state->return_desc =
walk_state->results->results.obj_desc[0];
} else {
if (walk_state->num_operands) {
acpi_ut_remove_reference(walk_state->
operands[0]);
}
walk_state->operands[0] = NULL;
walk_state->num_operands = 0;
walk_state->return_desc = NULL;
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Completed RETURN_OP State=%p, RetVal=%p\n",
walk_state, walk_state->return_desc));
status = AE_CTRL_TERMINATE;
break;
case AML_NOOP_OP:
break;
case AML_BREAKPOINT_OP:
acpi_db_signal_break_point(walk_state);
status = acpi_os_signal(ACPI_SIGNAL_BREAKPOINT,
"Executed AML Breakpoint opcode");
break;
case AML_BREAK_OP:
case AML_CONTINUE_OP:
while (walk_state->control_state &&
(walk_state->control_state->control.opcode !=
AML_WHILE_OP)) {
control_state =
acpi_ut_pop_generic_state(&walk_state->
control_state);
acpi_ut_delete_generic_state(control_state);
}
if (!walk_state->control_state) {
return (AE_AML_NO_WHILE);
}
walk_state->aml_last_while =
walk_state->control_state->control.package_end;
if (op->common.aml_opcode == AML_BREAK_OP) {
status = AE_CTRL_BREAK;
} else {
status = AE_CTRL_CONTINUE;
}
break;
default:
ACPI_ERROR((AE_INFO, "Unknown control opcode=0x%X Op=%p",
op->common.aml_opcode, op));
status = AE_AML_BAD_OPCODE;
break;
}
return (status);
}
