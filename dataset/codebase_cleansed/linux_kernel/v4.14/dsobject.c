acpi_status
acpi_ds_build_internal_object(struct acpi_walk_state *walk_state,
union acpi_parse_object *op,
union acpi_operand_object **obj_desc_ptr)
{
union acpi_operand_object *obj_desc;
acpi_status status;
ACPI_FUNCTION_TRACE(ds_build_internal_object);
*obj_desc_ptr = NULL;
if (op->common.aml_opcode == AML_INT_NAMEPATH_OP) {
if (!op->common.node) {
if ((op->common.parent->common.aml_opcode ==
AML_PACKAGE_OP)
|| (op->common.parent->common.aml_opcode ==
AML_VARIABLE_PACKAGE_OP)) {
goto create_new_object;
} else {
status = acpi_ns_lookup(walk_state->scope_info,
op->common.value.string,
ACPI_TYPE_ANY,
ACPI_IMODE_EXECUTE,
ACPI_NS_SEARCH_PARENT |
ACPI_NS_DONT_OPEN_SCOPE,
NULL,
ACPI_CAST_INDIRECT_PTR
(struct
acpi_namespace_node,
&(op->common.node)));
if (ACPI_FAILURE(status)) {
ACPI_ERROR_NAMESPACE(op->common.value.
string, status);
return_ACPI_STATUS(status);
}
}
}
}
create_new_object:
obj_desc = acpi_ut_create_internal_object((acpi_ps_get_opcode_info
(op->common.aml_opcode))->
object_type);
if (!obj_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
status =
acpi_ds_init_object_from_op(walk_state, op, op->common.aml_opcode,
&obj_desc);
if (ACPI_FAILURE(status)) {
acpi_ut_remove_reference(obj_desc);
return_ACPI_STATUS(status);
}
if ((op->common.parent->common.aml_opcode == AML_PACKAGE_OP) ||
(op->common.parent->common.aml_opcode == AML_VARIABLE_PACKAGE_OP)) {
obj_desc->reference.resolved = TRUE;
if ((op->common.aml_opcode == AML_INT_NAMEPATH_OP) &&
!obj_desc->reference.node) {
obj_desc->reference.node =
walk_state->scope_info->scope.node;
obj_desc->reference.aml = op->common.aml;
obj_desc->reference.resolved = FALSE;
}
}
*obj_desc_ptr = obj_desc;
return_ACPI_STATUS(status);
}
acpi_status
acpi_ds_build_internal_buffer_obj(struct acpi_walk_state *walk_state,
union acpi_parse_object *op,
u32 buffer_length,
union acpi_operand_object **obj_desc_ptr)
{
union acpi_parse_object *arg;
union acpi_operand_object *obj_desc;
union acpi_parse_object *byte_list;
u32 byte_list_length = 0;
ACPI_FUNCTION_TRACE(ds_build_internal_buffer_obj);
obj_desc = *obj_desc_ptr;
if (!obj_desc) {
obj_desc = acpi_ut_create_internal_object(ACPI_TYPE_BUFFER);
*obj_desc_ptr = obj_desc;
if (!obj_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
}
arg = op->common.value.arg;
byte_list = arg->named.next;
if (byte_list) {
if (byte_list->common.aml_opcode != AML_INT_BYTELIST_OP) {
ACPI_ERROR((AE_INFO,
"Expecting bytelist, found AML opcode 0x%X in op %p",
byte_list->common.aml_opcode, byte_list));
acpi_ut_remove_reference(obj_desc);
return (AE_TYPE);
}
byte_list_length = (u32) byte_list->common.value.integer;
}
obj_desc->buffer.length = buffer_length;
if (byte_list_length > buffer_length) {
obj_desc->buffer.length = byte_list_length;
}
if (obj_desc->buffer.length == 0) {
obj_desc->buffer.pointer = NULL;
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Buffer defined with zero length in AML, creating\n"));
} else {
obj_desc->buffer.pointer =
ACPI_ALLOCATE_ZEROED(obj_desc->buffer.length);
if (!obj_desc->buffer.pointer) {
acpi_ut_delete_object_desc(obj_desc);
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (byte_list) {
memcpy(obj_desc->buffer.pointer, byte_list->named.data,
byte_list_length);
}
}
obj_desc->buffer.flags |= AOPOBJ_DATA_VALID;
op->common.node = ACPI_CAST_PTR(struct acpi_namespace_node, obj_desc);
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ds_create_node(struct acpi_walk_state *walk_state,
struct acpi_namespace_node *node,
union acpi_parse_object *op)
{
acpi_status status;
union acpi_operand_object *obj_desc;
ACPI_FUNCTION_TRACE_PTR(ds_create_node, op);
if (acpi_ns_get_attached_object(node)) {
return_ACPI_STATUS(AE_OK);
}
if (!op->common.value.arg) {
return_ACPI_STATUS(AE_OK);
}
status =
acpi_ds_build_internal_object(walk_state, op->common.value.arg,
&obj_desc);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
node->type = obj_desc->common.type;
status = acpi_ns_attach_object(node, obj_desc, node->type);
acpi_ut_remove_reference(obj_desc);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ds_init_object_from_op(struct acpi_walk_state *walk_state,
union acpi_parse_object *op,
u16 opcode,
union acpi_operand_object **ret_obj_desc)
{
const struct acpi_opcode_info *op_info;
union acpi_operand_object *obj_desc;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(ds_init_object_from_op);
obj_desc = *ret_obj_desc;
op_info = acpi_ps_get_opcode_info(opcode);
if (op_info->class == AML_CLASS_UNKNOWN) {
return_ACPI_STATUS(AE_TYPE);
}
switch (obj_desc->common.type) {
case ACPI_TYPE_BUFFER:
obj_desc->buffer.node =
ACPI_CAST_PTR(struct acpi_namespace_node,
walk_state->operands[0]);
obj_desc->buffer.aml_start = op->named.data;
obj_desc->buffer.aml_length = op->named.length;
break;
case ACPI_TYPE_PACKAGE:
obj_desc->package.node =
ACPI_CAST_PTR(struct acpi_namespace_node,
walk_state->operands[0]);
if (!op->named.data) {
return_ACPI_STATUS(AE_OK);
}
obj_desc->package.aml_start = op->named.data;
obj_desc->package.aml_length = op->named.length;
break;
case ACPI_TYPE_INTEGER:
switch (op_info->type) {
case AML_TYPE_CONSTANT:
obj_desc->common.flags = AOPOBJ_AML_CONSTANT;
switch (opcode) {
case AML_ZERO_OP:
obj_desc->integer.value = 0;
break;
case AML_ONE_OP:
obj_desc->integer.value = 1;
break;
case AML_ONES_OP:
obj_desc->integer.value = ACPI_UINT64_MAX;
#ifndef ACPI_NO_METHOD_EXECUTION
(void)acpi_ex_truncate_for32bit_table(obj_desc);
#endif
break;
case AML_REVISION_OP:
obj_desc->integer.value = ACPI_CA_VERSION;
break;
default:
ACPI_ERROR((AE_INFO,
"Unknown constant opcode 0x%X",
opcode));
status = AE_AML_OPERAND_TYPE;
break;
}
break;
case AML_TYPE_LITERAL:
obj_desc->integer.value = op->common.value.integer;
#ifndef ACPI_NO_METHOD_EXECUTION
if (acpi_ex_truncate_for32bit_table(obj_desc)) {
ACPI_WARNING((AE_INFO,
"Truncated 64-bit constant found in 32-bit table: %8.8X%8.8X => %8.8X",
ACPI_FORMAT_UINT64(op->common.
value.integer),
(u32)obj_desc->integer.value));
}
#endif
break;
default:
ACPI_ERROR((AE_INFO, "Unknown Integer type 0x%X",
op_info->type));
status = AE_AML_OPERAND_TYPE;
break;
}
break;
case ACPI_TYPE_STRING:
obj_desc->string.pointer = op->common.value.string;
obj_desc->string.length = (u32)strlen(op->common.value.string);
obj_desc->common.flags |= AOPOBJ_STATIC_POINTER;
break;
case ACPI_TYPE_METHOD:
break;
case ACPI_TYPE_LOCAL_REFERENCE:
switch (op_info->type) {
case AML_TYPE_LOCAL_VARIABLE:
obj_desc->reference.value =
((u32)opcode) - AML_FIRST_LOCAL_OP;
obj_desc->reference.class = ACPI_REFCLASS_LOCAL;
#ifndef ACPI_NO_METHOD_EXECUTION
status =
acpi_ds_method_data_get_node(ACPI_REFCLASS_LOCAL,
obj_desc->reference.
value, walk_state,
ACPI_CAST_INDIRECT_PTR
(struct
acpi_namespace_node,
&obj_desc->reference.
object));
#endif
break;
case AML_TYPE_METHOD_ARGUMENT:
obj_desc->reference.value =
((u32)opcode) - AML_FIRST_ARG_OP;
obj_desc->reference.class = ACPI_REFCLASS_ARG;
#ifndef ACPI_NO_METHOD_EXECUTION
status = acpi_ds_method_data_get_node(ACPI_REFCLASS_ARG,
obj_desc->
reference.value,
walk_state,
ACPI_CAST_INDIRECT_PTR
(struct
acpi_namespace_node,
&obj_desc->
reference.
object));
#endif
break;
default:
switch (op->common.aml_opcode) {
case AML_INT_NAMEPATH_OP:
obj_desc->reference.node = op->common.node;
obj_desc->reference.class = ACPI_REFCLASS_NAME;
if (op->common.node) {
obj_desc->reference.object =
op->common.node->object;
}
break;
case AML_DEBUG_OP:
obj_desc->reference.class = ACPI_REFCLASS_DEBUG;
break;
default:
ACPI_ERROR((AE_INFO,
"Unimplemented reference type for AML opcode: 0x%4.4X",
opcode));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
break;
}
break;
default:
ACPI_ERROR((AE_INFO, "Unimplemented data type: 0x%X",
obj_desc->common.type));
status = AE_AML_OPERAND_TYPE;
break;
}
return_ACPI_STATUS(status);
}
