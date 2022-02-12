union acpi_parse_object *acpi_ps_create_scope_op(void)
{
union acpi_parse_object *scope_op;
scope_op = acpi_ps_alloc_op(AML_SCOPE_OP);
if (!scope_op) {
return (NULL);
}
scope_op->named.name = ACPI_ROOT_NAME;
return (scope_op);
}
void acpi_ps_init_op(union acpi_parse_object *op, u16 opcode)
{
ACPI_FUNCTION_ENTRY();
op->common.descriptor_type = ACPI_DESC_TYPE_PARSER;
op->common.aml_opcode = opcode;
ACPI_DISASM_ONLY_MEMBERS(ACPI_STRNCPY(op->common.aml_op_name,
(acpi_ps_get_opcode_info
(opcode))->name,
sizeof(op->common.aml_op_name)));
}
union acpi_parse_object *acpi_ps_alloc_op(u16 opcode)
{
union acpi_parse_object *op;
const struct acpi_opcode_info *op_info;
u8 flags = ACPI_PARSEOP_GENERIC;
ACPI_FUNCTION_ENTRY();
op_info = acpi_ps_get_opcode_info(opcode);
if (op_info->flags & AML_DEFER) {
flags = ACPI_PARSEOP_DEFERRED;
} else if (op_info->flags & AML_NAMED) {
flags = ACPI_PARSEOP_NAMED;
} else if (opcode == AML_INT_BYTELIST_OP) {
flags = ACPI_PARSEOP_BYTELIST;
}
if (flags == ACPI_PARSEOP_GENERIC) {
op = acpi_os_acquire_object(acpi_gbl_ps_node_cache);
} else {
op = acpi_os_acquire_object(acpi_gbl_ps_node_ext_cache);
}
if (op) {
acpi_ps_init_op(op, opcode);
op->common.flags = flags;
}
return (op);
}
void acpi_ps_free_op(union acpi_parse_object *op)
{
ACPI_FUNCTION_NAME(ps_free_op);
if (op->common.aml_opcode == AML_INT_RETURN_VALUE_OP) {
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS, "Free retval op: %p\n",
op));
}
if (op->common.flags & ACPI_PARSEOP_GENERIC) {
(void)acpi_os_release_object(acpi_gbl_ps_node_cache, op);
} else {
(void)acpi_os_release_object(acpi_gbl_ps_node_ext_cache, op);
}
}
u8 acpi_ps_is_leading_char(u32 c)
{
return ((u8) (c == '_' || (c >= 'A' && c <= 'Z')));
}
u32 acpi_ps_get_name(union acpi_parse_object * op)
{
if (op->common.flags & ACPI_PARSEOP_GENERIC) {
return (0);
}
return (op->named.name);
}
void acpi_ps_set_name(union acpi_parse_object *op, u32 name)
{
if (op->common.flags & ACPI_PARSEOP_GENERIC) {
return;
}
op->named.name = name;
}
