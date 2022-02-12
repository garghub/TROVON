static void
acpi_ds_print_node_pathname(struct acpi_namespace_node *node,
const char *message)
{
struct acpi_buffer buffer;
acpi_status status;
ACPI_FUNCTION_TRACE(ds_print_node_pathname);
if (!node) {
ACPI_DEBUG_PRINT_RAW((ACPI_DB_DISPATCH, "[NULL NAME]"));
return_VOID;
}
buffer.length = ACPI_ALLOCATE_LOCAL_BUFFER;
status = acpi_ns_handle_to_pathname(node, &buffer, TRUE);
if (ACPI_SUCCESS(status)) {
if (message) {
ACPI_DEBUG_PRINT_RAW((ACPI_DB_DISPATCH, "%s ",
message));
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_DISPATCH, "[%s] (Node %p)",
(char *)buffer.pointer, node));
ACPI_FREE(buffer.pointer);
}
return_VOID;
}
void
acpi_ds_dump_method_stack(acpi_status status,
struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
union acpi_parse_object *next;
struct acpi_thread_state *thread;
struct acpi_walk_state *next_walk_state;
struct acpi_namespace_node *previous_method = NULL;
union acpi_operand_object *method_desc;
ACPI_FUNCTION_TRACE(ds_dump_method_stack);
if ((status & AE_CODE_MASK) == AE_CODE_CONTROL) {
return_VOID;
}
if (walk_state->deferred_node) {
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"Executing subtree for Buffer/Package/Region\n"));
return_VOID;
}
thread = walk_state->thread;
if (!thread) {
return_VOID;
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"\n**** Exception %s during execution of method ",
acpi_format_exception(status)));
acpi_ds_print_node_pathname(walk_state->method_node, NULL);
ACPI_DEBUG_PRINT_RAW((ACPI_DB_DISPATCH,
"\n\nMethod Execution Stack:\n"));
next_walk_state = thread->walk_state_list;
while (next_walk_state) {
method_desc = next_walk_state->method_desc;
if (method_desc) {
acpi_ex_stop_trace_method((struct acpi_namespace_node *)
method_desc->method.node,
method_desc, walk_state);
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
" Method [%4.4s] executing: ",
acpi_ut_get_node_name(next_walk_state->
method_node)));
if (next_walk_state == walk_state) {
if (op) {
next = op->common.next;
op->common.next = NULL;
#ifdef ACPI_DISASSEMBLER
acpi_os_printf("Failed at ");
acpi_dm_disassemble(next_walk_state, op,
ACPI_UINT32_MAX);
#endif
op->common.next = next;
}
} else {
ACPI_DEBUG_PRINT_RAW((ACPI_DB_DISPATCH,
"Call to method "));
acpi_ds_print_node_pathname(previous_method, NULL);
}
previous_method = next_walk_state->method_node;
next_walk_state = next_walk_state->next;
ACPI_DEBUG_PRINT_RAW((ACPI_DB_DISPATCH, "\n"));
}
return_VOID;
}
void
acpi_ds_dump_method_stack(acpi_status status,
struct acpi_walk_state *walk_state,
union acpi_parse_object *op)
{
return;
}
