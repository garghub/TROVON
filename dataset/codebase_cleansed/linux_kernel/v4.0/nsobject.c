acpi_status
acpi_ns_attach_object(struct acpi_namespace_node *node,
union acpi_operand_object *object, acpi_object_type type)
{
union acpi_operand_object *obj_desc;
union acpi_operand_object *last_obj_desc;
acpi_object_type object_type = ACPI_TYPE_ANY;
ACPI_FUNCTION_TRACE(ns_attach_object);
if (!node) {
ACPI_ERROR((AE_INFO, "Null NamedObj handle"));
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (!object && (ACPI_TYPE_ANY != type)) {
ACPI_ERROR((AE_INFO,
"Null object, but type not ACPI_TYPE_ANY"));
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (ACPI_GET_DESCRIPTOR_TYPE(node) != ACPI_DESC_TYPE_NAMED) {
ACPI_ERROR((AE_INFO, "Invalid handle %p [%s]",
node, acpi_ut_get_descriptor_name(node)));
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (node->object == object) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Obj %p already installed in NameObj %p\n",
object, node));
return_ACPI_STATUS(AE_OK);
}
if (!object) {
obj_desc = NULL;
object_type = ACPI_TYPE_ANY;
}
else if ((ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED) &&
((struct acpi_namespace_node *)object)->object) {
obj_desc = ((struct acpi_namespace_node *)object)->object;
object_type = ((struct acpi_namespace_node *)object)->type;
}
else {
obj_desc = (union acpi_operand_object *)object;
object_type = type;
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Installing %p into Node %p [%4.4s]\n",
obj_desc, node, acpi_ut_get_node_name(node)));
if (node->object) {
acpi_ns_detach_object(node);
}
if (obj_desc) {
acpi_ut_add_reference(obj_desc);
last_obj_desc = obj_desc;
while (last_obj_desc->common.next_object) {
last_obj_desc = last_obj_desc->common.next_object;
}
last_obj_desc->common.next_object = node->object;
}
node->type = (u8) object_type;
node->object = obj_desc;
return_ACPI_STATUS(AE_OK);
}
void acpi_ns_detach_object(struct acpi_namespace_node *node)
{
union acpi_operand_object *obj_desc;
ACPI_FUNCTION_TRACE(ns_detach_object);
obj_desc = node->object;
if (!obj_desc || (obj_desc->common.type == ACPI_TYPE_LOCAL_DATA)) {
return_VOID;
}
if (node->flags & ANOBJ_ALLOCATED_BUFFER) {
if (obj_desc->common.type == ACPI_TYPE_METHOD) {
ACPI_FREE(obj_desc->method.aml_start);
}
}
node->object = NULL;
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) == ACPI_DESC_TYPE_OPERAND) {
node->object = obj_desc->common.next_object;
if (node->object &&
(node->object->common.type != ACPI_TYPE_LOCAL_DATA)) {
node->object = node->object->common.next_object;
}
if (obj_desc->common.next_object &&
((obj_desc->common.next_object)->common.type ==
ACPI_TYPE_LOCAL_DATA)) {
obj_desc->common.next_object = NULL;
}
}
node->type = ACPI_TYPE_ANY;
ACPI_DEBUG_PRINT((ACPI_DB_NAMES, "Node %p [%4.4s] Object %p\n",
node, acpi_ut_get_node_name(node), obj_desc));
acpi_ut_remove_reference(obj_desc);
return_VOID;
}
union acpi_operand_object *acpi_ns_get_attached_object(struct
acpi_namespace_node
*node)
{
ACPI_FUNCTION_TRACE_PTR(ns_get_attached_object, node);
if (!node) {
ACPI_WARNING((AE_INFO, "Null Node ptr"));
return_PTR(NULL);
}
if (!node->object ||
((ACPI_GET_DESCRIPTOR_TYPE(node->object) != ACPI_DESC_TYPE_OPERAND)
&& (ACPI_GET_DESCRIPTOR_TYPE(node->object) !=
ACPI_DESC_TYPE_NAMED))
|| ((node->object)->common.type == ACPI_TYPE_LOCAL_DATA)) {
return_PTR(NULL);
}
return_PTR(node->object);
}
union acpi_operand_object *acpi_ns_get_secondary_object(union
acpi_operand_object
*obj_desc)
{
ACPI_FUNCTION_TRACE_PTR(ns_get_secondary_object, obj_desc);
if ((!obj_desc) ||
(obj_desc->common.type == ACPI_TYPE_LOCAL_DATA) ||
(!obj_desc->common.next_object) ||
((obj_desc->common.next_object)->common.type ==
ACPI_TYPE_LOCAL_DATA)) {
return_PTR(NULL);
}
return_PTR(obj_desc->common.next_object);
}
acpi_status
acpi_ns_attach_data(struct acpi_namespace_node *node,
acpi_object_handler handler, void *data)
{
union acpi_operand_object *prev_obj_desc;
union acpi_operand_object *obj_desc;
union acpi_operand_object *data_desc;
prev_obj_desc = NULL;
obj_desc = node->object;
while (obj_desc) {
if ((obj_desc->common.type == ACPI_TYPE_LOCAL_DATA) &&
(obj_desc->data.handler == handler)) {
return (AE_ALREADY_EXISTS);
}
prev_obj_desc = obj_desc;
obj_desc = obj_desc->common.next_object;
}
data_desc = acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_DATA);
if (!data_desc) {
return (AE_NO_MEMORY);
}
data_desc->data.handler = handler;
data_desc->data.pointer = data;
if (prev_obj_desc) {
prev_obj_desc->common.next_object = data_desc;
} else {
node->object = data_desc;
}
return (AE_OK);
}
acpi_status
acpi_ns_detach_data(struct acpi_namespace_node * node,
acpi_object_handler handler)
{
union acpi_operand_object *obj_desc;
union acpi_operand_object *prev_obj_desc;
prev_obj_desc = NULL;
obj_desc = node->object;
while (obj_desc) {
if ((obj_desc->common.type == ACPI_TYPE_LOCAL_DATA) &&
(obj_desc->data.handler == handler)) {
if (prev_obj_desc) {
prev_obj_desc->common.next_object =
obj_desc->common.next_object;
} else {
node->object = obj_desc->common.next_object;
}
acpi_ut_remove_reference(obj_desc);
return (AE_OK);
}
prev_obj_desc = obj_desc;
obj_desc = obj_desc->common.next_object;
}
return (AE_NOT_FOUND);
}
acpi_status
acpi_ns_get_attached_data(struct acpi_namespace_node * node,
acpi_object_handler handler, void **data)
{
union acpi_operand_object *obj_desc;
obj_desc = node->object;
while (obj_desc) {
if ((obj_desc->common.type == ACPI_TYPE_LOCAL_DATA) &&
(obj_desc->data.handler == handler)) {
*data = obj_desc->data.pointer;
return (AE_OK);
}
obj_desc = obj_desc->common.next_object;
}
return (AE_NOT_FOUND);
}
