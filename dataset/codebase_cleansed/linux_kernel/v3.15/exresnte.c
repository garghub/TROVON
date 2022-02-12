acpi_status
acpi_ex_resolve_node_to_value(struct acpi_namespace_node **object_ptr,
struct acpi_walk_state *walk_state)
{
acpi_status status = AE_OK;
union acpi_operand_object *source_desc;
union acpi_operand_object *obj_desc = NULL;
struct acpi_namespace_node *node;
acpi_object_type entry_type;
ACPI_FUNCTION_TRACE(ex_resolve_node_to_value);
node = *object_ptr;
source_desc = acpi_ns_get_attached_object(node);
entry_type = acpi_ns_get_type((acpi_handle) node);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Entry=%p SourceDesc=%p [%s]\n",
node, source_desc,
acpi_ut_get_type_name(entry_type)));
if ((entry_type == ACPI_TYPE_LOCAL_ALIAS) ||
(entry_type == ACPI_TYPE_LOCAL_METHOD_ALIAS)) {
node = ACPI_CAST_PTR(struct acpi_namespace_node, node->object);
source_desc = acpi_ns_get_attached_object(node);
entry_type = acpi_ns_get_type((acpi_handle) node);
*object_ptr = node;
}
if ((entry_type == ACPI_TYPE_DEVICE) ||
(entry_type == ACPI_TYPE_THERMAL) ||
(entry_type == ACPI_TYPE_METHOD) ||
(node->flags & (ANOBJ_METHOD_ARG | ANOBJ_METHOD_LOCAL))) {
return_ACPI_STATUS(AE_OK);
}
if (!source_desc) {
ACPI_ERROR((AE_INFO, "No object attached to node [%4.4s] %p",
node->name.ascii, node));
return_ACPI_STATUS(AE_AML_NO_OPERAND);
}
switch (entry_type) {
case ACPI_TYPE_PACKAGE:
if (source_desc->common.type != ACPI_TYPE_PACKAGE) {
ACPI_ERROR((AE_INFO, "Object not a Package, type %s",
acpi_ut_get_object_type_name(source_desc)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
status = acpi_ds_get_package_arguments(source_desc);
if (ACPI_SUCCESS(status)) {
obj_desc = source_desc;
acpi_ut_add_reference(obj_desc);
}
break;
case ACPI_TYPE_BUFFER:
if (source_desc->common.type != ACPI_TYPE_BUFFER) {
ACPI_ERROR((AE_INFO, "Object not a Buffer, type %s",
acpi_ut_get_object_type_name(source_desc)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
status = acpi_ds_get_buffer_arguments(source_desc);
if (ACPI_SUCCESS(status)) {
obj_desc = source_desc;
acpi_ut_add_reference(obj_desc);
}
break;
case ACPI_TYPE_STRING:
if (source_desc->common.type != ACPI_TYPE_STRING) {
ACPI_ERROR((AE_INFO, "Object not a String, type %s",
acpi_ut_get_object_type_name(source_desc)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
obj_desc = source_desc;
acpi_ut_add_reference(obj_desc);
break;
case ACPI_TYPE_INTEGER:
if (source_desc->common.type != ACPI_TYPE_INTEGER) {
ACPI_ERROR((AE_INFO, "Object not a Integer, type %s",
acpi_ut_get_object_type_name(source_desc)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
obj_desc = source_desc;
acpi_ut_add_reference(obj_desc);
break;
case ACPI_TYPE_BUFFER_FIELD:
case ACPI_TYPE_LOCAL_REGION_FIELD:
case ACPI_TYPE_LOCAL_BANK_FIELD:
case ACPI_TYPE_LOCAL_INDEX_FIELD:
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"FieldRead Node=%p SourceDesc=%p Type=%X\n",
node, source_desc, entry_type));
status =
acpi_ex_read_data_from_field(walk_state, source_desc,
&obj_desc);
break;
case ACPI_TYPE_MUTEX:
case ACPI_TYPE_POWER:
case ACPI_TYPE_PROCESSOR:
case ACPI_TYPE_EVENT:
case ACPI_TYPE_REGION:
obj_desc = source_desc;
acpi_ut_add_reference(obj_desc);
break;
case ACPI_TYPE_ANY:
ACPI_ERROR((AE_INFO,
"Untyped entry %p, no attached object!", node));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
case ACPI_TYPE_LOCAL_REFERENCE:
switch (source_desc->reference.class) {
case ACPI_REFCLASS_TABLE:
case ACPI_REFCLASS_REFOF:
case ACPI_REFCLASS_INDEX:
obj_desc = source_desc;
acpi_ut_add_reference(obj_desc);
break;
default:
ACPI_ERROR((AE_INFO,
"Unsupported Reference type 0x%X",
source_desc->reference.class));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
break;
default:
ACPI_ERROR((AE_INFO,
"Node %p - Unknown object type 0x%X",
node, entry_type));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
*object_ptr = (void *)obj_desc;
return_ACPI_STATUS(status);
}
