void acpi_ps_delete_parse_tree(union acpi_parse_object *subtree_root)
{
union acpi_parse_object *op = subtree_root;
union acpi_parse_object *next = NULL;
union acpi_parse_object *parent = NULL;
ACPI_FUNCTION_TRACE_PTR(ps_delete_parse_tree, subtree_root);
while (op) {
if (op != parent) {
next = acpi_ps_get_arg(op, 0);
if (next) {
op = next;
continue;
}
}
next = op->common.next;
parent = op->common.parent;
acpi_ps_free_op(op);
if (op == subtree_root) {
return_VOID;
}
if (next) {
op = next;
} else {
op = parent;
}
}
return_VOID;
}
