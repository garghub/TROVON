union acpi_parse_object *acpi_ps_get_parent_scope(struct acpi_parse_state
*parser_state)
{
return (parser_state->scope->parse_scope.op);
}
u8 acpi_ps_has_completed_scope(struct acpi_parse_state * parser_state)
{
return ((u8)
((parser_state->aml >= parser_state->scope->parse_scope.arg_end
|| !parser_state->scope->parse_scope.arg_count)));
}
acpi_status
acpi_ps_init_scope(struct acpi_parse_state * parser_state,
union acpi_parse_object * root_op)
{
union acpi_generic_state *scope;
ACPI_FUNCTION_TRACE_PTR(ps_init_scope, root_op);
scope = acpi_ut_create_generic_state();
if (!scope) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
scope->common.descriptor_type = ACPI_DESC_TYPE_STATE_RPSCOPE;
scope->parse_scope.op = root_op;
scope->parse_scope.arg_count = ACPI_VAR_ARGS;
scope->parse_scope.arg_end = parser_state->aml_end;
scope->parse_scope.pkg_end = parser_state->aml_end;
parser_state->scope = scope;
parser_state->start_op = root_op;
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ps_push_scope(struct acpi_parse_state *parser_state,
union acpi_parse_object *op,
u32 remaining_args, u32 arg_count)
{
union acpi_generic_state *scope;
ACPI_FUNCTION_TRACE_PTR(ps_push_scope, op);
scope = acpi_ut_create_generic_state();
if (!scope) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
scope->common.descriptor_type = ACPI_DESC_TYPE_STATE_PSCOPE;
scope->parse_scope.op = op;
scope->parse_scope.arg_list = remaining_args;
scope->parse_scope.arg_count = arg_count;
scope->parse_scope.pkg_end = parser_state->pkg_end;
acpi_ut_push_generic_state(&parser_state->scope, scope);
if (arg_count == ACPI_VAR_ARGS) {
scope->parse_scope.arg_end = parser_state->pkg_end;
} else {
scope->parse_scope.arg_end = ACPI_TO_POINTER(ACPI_MAX_PTR);
}
return_ACPI_STATUS(AE_OK);
}
void
acpi_ps_pop_scope(struct acpi_parse_state *parser_state,
union acpi_parse_object **op, u32 * arg_list, u32 * arg_count)
{
union acpi_generic_state *scope = parser_state->scope;
ACPI_FUNCTION_TRACE(ps_pop_scope);
if (scope->common.next) {
scope = acpi_ut_pop_generic_state(&parser_state->scope);
*op = scope->parse_scope.op;
*arg_list = scope->parse_scope.arg_list;
*arg_count = scope->parse_scope.arg_count;
parser_state->pkg_end = scope->parse_scope.pkg_end;
acpi_ut_delete_generic_state(scope);
} else {
*op = NULL;
*arg_list = 0;
*arg_count = 0;
}
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"Popped Op %p Args %X\n", *op, *arg_count));
return_VOID;
}
void acpi_ps_cleanup_scope(struct acpi_parse_state *parser_state)
{
union acpi_generic_state *scope;
ACPI_FUNCTION_TRACE_PTR(ps_cleanup_scope, parser_state);
if (!parser_state) {
return_VOID;
}
while (parser_state->scope) {
scope = acpi_ut_pop_generic_state(&parser_state->scope);
acpi_ut_delete_generic_state(scope);
}
return_VOID;
}
