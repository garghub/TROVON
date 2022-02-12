acpi_status
acpi_ns_one_complete_parse(u32 pass_number,
u32 table_index,
struct acpi_namespace_node *start_node)
{
union acpi_parse_object *parse_root;
acpi_status status;
u32 aml_length;
u8 *aml_start;
struct acpi_walk_state *walk_state;
struct acpi_table_header *table;
acpi_owner_id owner_id;
ACPI_FUNCTION_TRACE(ns_one_complete_parse);
status = acpi_get_table_by_index(table_index, &table);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (table->length < sizeof(struct acpi_table_header)) {
return_ACPI_STATUS(AE_BAD_HEADER);
}
aml_start = (u8 *)table + sizeof(struct acpi_table_header);
aml_length = table->length - sizeof(struct acpi_table_header);
status = acpi_tb_get_owner_id(table_index, &owner_id);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
parse_root = acpi_ps_create_scope_op(aml_start);
if (!parse_root) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
walk_state = acpi_ds_create_walk_state(owner_id, NULL, NULL, NULL);
if (!walk_state) {
acpi_ps_free_op(parse_root);
return_ACPI_STATUS(AE_NO_MEMORY);
}
status = acpi_ds_init_aml_walk(walk_state, parse_root, NULL,
aml_start, aml_length, NULL,
(u8)pass_number);
if (ACPI_FAILURE(status)) {
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
if (ACPI_COMPARE_NAME(table->signature, ACPI_SIG_OSDT) &&
pass_number == ACPI_IMODE_LOAD_PASS1) {
walk_state->namespace_override = TRUE;
}
if (start_node && start_node != acpi_gbl_root_node) {
status =
acpi_ds_scope_stack_push(start_node, ACPI_TYPE_METHOD,
walk_state);
if (ACPI_FAILURE(status)) {
acpi_ds_delete_walk_state(walk_state);
goto cleanup;
}
}
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"*PARSE* pass %u parse\n", pass_number));
status = acpi_ps_parse_aml(walk_state);
cleanup:
acpi_ps_delete_parse_tree(parse_root);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ns_parse_table(u32 table_index, struct acpi_namespace_node *start_node)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ns_parse_table);
ACPI_DEBUG_PRINT((ACPI_DB_PARSE, "**** Start pass 1\n"));
status = acpi_ns_one_complete_parse(ACPI_IMODE_LOAD_PASS1,
table_index, start_node);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_PARSE, "**** Start pass 2\n"));
status = acpi_ns_one_complete_parse(ACPI_IMODE_LOAD_PASS2,
table_index, start_node);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
return_ACPI_STATUS(status);
}
