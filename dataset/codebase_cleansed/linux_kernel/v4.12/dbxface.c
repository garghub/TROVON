static acpi_status
acpi_db_start_command(struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
acpi_status status;
acpi_gbl_method_executing = TRUE;
status = AE_CTRL_TRUE;
while (status == AE_CTRL_TRUE) {
status = acpi_os_notify_command_complete();
if (ACPI_FAILURE(status)) {
goto error_exit;
}
status = acpi_os_wait_command_ready();
if (ACPI_FAILURE(status)) {
goto error_exit;
}
status =
acpi_db_command_dispatch(acpi_gbl_db_line_buf, walk_state,
op);
}
error_exit:
if (ACPI_FAILURE(status) && status != AE_CTRL_TERMINATE) {
ACPI_EXCEPTION((AE_INFO, status,
"While parsing/handling command line"));
}
return (status);
}
void acpi_db_signal_break_point(struct acpi_walk_state *walk_state)
{
#ifndef ACPI_APPLICATION
if (acpi_gbl_db_thread_id != acpi_os_get_thread_id()) {
return;
}
#endif
acpi_gbl_cm_single_step = TRUE;
acpi_os_printf("**break** Executed AML BreakPoint opcode\n");
}
acpi_status
acpi_db_single_step(struct acpi_walk_state *walk_state,
union acpi_parse_object *op, u32 opcode_class)
{
union acpi_parse_object *next;
acpi_status status = AE_OK;
u32 original_debug_level;
union acpi_parse_object *display_op;
union acpi_parse_object *parent_op;
u32 aml_offset;
ACPI_FUNCTION_ENTRY();
#ifndef ACPI_APPLICATION
if (acpi_gbl_db_thread_id != acpi_os_get_thread_id()) {
return (AE_OK);
}
#endif
if (acpi_gbl_abort_method) {
acpi_gbl_abort_method = FALSE;
return (AE_ABORT_METHOD);
}
aml_offset = (u32)ACPI_PTR_DIFF(op->common.aml,
walk_state->parser_state.aml_start);
if (walk_state->method_breakpoint &&
(walk_state->method_breakpoint <= aml_offset)) {
acpi_os_printf("***Break*** at AML offset %X\n", aml_offset);
acpi_gbl_cm_single_step = TRUE;
acpi_gbl_step_to_next_call = FALSE;
walk_state->method_breakpoint = 0;
}
else if (walk_state->user_breakpoint &&
(walk_state->user_breakpoint == aml_offset)) {
acpi_os_printf("***UserBreakpoint*** at AML offset %X\n",
aml_offset);
acpi_gbl_cm_single_step = TRUE;
acpi_gbl_step_to_next_call = FALSE;
walk_state->method_breakpoint = 0;
}
if (op->common.aml_opcode == AML_INT_NAMEDFIELD_OP) {
return (AE_OK);
}
switch (opcode_class) {
case AML_CLASS_UNKNOWN:
case AML_CLASS_ARGUMENT:
return (AE_OK);
default:
break;
}
if ((acpi_gbl_db_output_to_file) ||
(acpi_gbl_cm_single_step) || (acpi_dbg_level & ACPI_LV_PARSE)) {
if ((acpi_gbl_db_output_to_file) ||
(acpi_dbg_level & ACPI_LV_PARSE)) {
acpi_os_printf
("\n[AmlDebug] Next AML Opcode to execute:\n");
}
original_debug_level = acpi_dbg_level;
acpi_dbg_level &= ~(ACPI_LV_PARSE | ACPI_LV_FUNCTIONS);
next = op->common.next;
op->common.next = NULL;
display_op = op;
parent_op = op->common.parent;
if (parent_op) {
if ((walk_state->control_state) &&
(walk_state->control_state->common.state ==
ACPI_CONTROL_PREDICATE_EXECUTING)) {
while (parent_op) {
if ((parent_op->common.aml_opcode ==
AML_IF_OP)
|| (parent_op->common.aml_opcode ==
AML_WHILE_OP)) {
display_op = parent_op;
break;
}
parent_op = parent_op->common.parent;
}
} else {
while (parent_op) {
if ((parent_op->common.aml_opcode ==
AML_IF_OP)
|| (parent_op->common.aml_opcode ==
AML_ELSE_OP)
|| (parent_op->common.aml_opcode ==
AML_SCOPE_OP)
|| (parent_op->common.aml_opcode ==
AML_METHOD_OP)
|| (parent_op->common.aml_opcode ==
AML_WHILE_OP)) {
break;
}
display_op = parent_op;
parent_op = parent_op->common.parent;
}
}
}
#ifdef ACPI_DISASSEMBLER
acpi_dm_disassemble(walk_state, display_op, ACPI_UINT32_MAX);
#endif
if ((op->common.aml_opcode == AML_IF_OP) ||
(op->common.aml_opcode == AML_WHILE_OP)) {
if (walk_state->control_state->common.value) {
acpi_os_printf
("Predicate = [True], IF block was executed\n");
} else {
acpi_os_printf
("Predicate = [False], Skipping IF block\n");
}
} else if (op->common.aml_opcode == AML_ELSE_OP) {
acpi_os_printf
("Predicate = [False], ELSE block was executed\n");
}
op->common.next = next;
acpi_os_printf("\n");
if ((acpi_gbl_db_output_to_file) ||
(acpi_dbg_level & ACPI_LV_PARSE)) {
acpi_os_printf("\n");
}
acpi_dbg_level = original_debug_level;
}
if (!acpi_gbl_cm_single_step) {
return (AE_OK);
}
if (acpi_gbl_step_to_next_call) {
if (op->common.aml_opcode != AML_INT_METHODCALL_OP) {
return (AE_OK);
}
acpi_gbl_step_to_next_call = FALSE;
}
if (op->common.aml_opcode == AML_INT_METHODCALL_OP) {
acpi_gbl_cm_single_step = FALSE;
walk_state->method_breakpoint = 1;
}
acpi_ex_exit_interpreter();
status = acpi_db_start_command(walk_state, op);
acpi_ex_enter_interpreter();
return (status);
}
acpi_status acpi_initialize_debugger(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_initialize_debugger);
acpi_gbl_db_buffer = NULL;
acpi_gbl_db_filename = NULL;
acpi_gbl_db_output_to_file = FALSE;
acpi_gbl_db_debug_level = ACPI_LV_VERBOSITY2;
acpi_gbl_db_console_debug_level = ACPI_NORMAL_DEFAULT | ACPI_LV_TABLES;
acpi_gbl_db_output_flags = ACPI_DB_CONSOLE_OUTPUT;
acpi_gbl_db_opt_no_ini_methods = FALSE;
acpi_gbl_db_buffer = acpi_os_allocate(ACPI_DEBUG_BUFFER_SIZE);
if (!acpi_gbl_db_buffer) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
memset(acpi_gbl_db_buffer, 0, ACPI_DEBUG_BUFFER_SIZE);
acpi_gbl_db_scope_buf[0] = AML_ROOT_PREFIX;
acpi_gbl_db_scope_buf[1] = 0;
acpi_gbl_db_scope_node = acpi_gbl_root_node;
acpi_gbl_db_terminate_loop = FALSE;
if (acpi_gbl_debugger_configuration & DEBUGGER_MULTI_THREADED) {
status = acpi_os_initialize_debugger();
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not get debugger mutex\n");
return_ACPI_STATUS(status);
}
acpi_gbl_db_threads_terminated = FALSE;
status = acpi_os_execute(OSL_DEBUGGER_MAIN_THREAD,
acpi_db_execute_thread, NULL);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Could not start debugger thread"));
acpi_gbl_db_threads_terminated = TRUE;
return_ACPI_STATUS(status);
}
} else {
acpi_gbl_db_thread_id = acpi_os_get_thread_id();
}
return_ACPI_STATUS(AE_OK);
}
void acpi_terminate_debugger(void)
{
acpi_gbl_db_terminate_loop = TRUE;
if (acpi_gbl_debugger_configuration & DEBUGGER_MULTI_THREADED) {
while (!acpi_gbl_db_threads_terminated) {
acpi_os_sleep(100);
}
acpi_os_terminate_debugger();
}
if (acpi_gbl_db_buffer) {
acpi_os_free(acpi_gbl_db_buffer);
acpi_gbl_db_buffer = NULL;
}
acpi_gbl_db_output_flags = ACPI_DB_DISABLE_OUTPUT;
}
void acpi_set_debugger_thread_id(acpi_thread_id thread_id)
{
acpi_gbl_db_thread_id = thread_id;
}
