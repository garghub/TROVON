acpi_status
acpi_ex_store(union acpi_operand_object *source_desc,
union acpi_operand_object *dest_desc,
struct acpi_walk_state *walk_state)
{
acpi_status status = AE_OK;
union acpi_operand_object *ref_desc = dest_desc;
ACPI_FUNCTION_TRACE_PTR(ex_store, dest_desc);
if (!source_desc || !dest_desc) {
ACPI_ERROR((AE_INFO, "Null parameter"));
return_ACPI_STATUS(AE_AML_NO_OPERAND);
}
if (ACPI_GET_DESCRIPTOR_TYPE(dest_desc) == ACPI_DESC_TYPE_NAMED) {
status = acpi_ex_store_object_to_node(source_desc,
(struct
acpi_namespace_node *)
dest_desc, walk_state,
ACPI_IMPLICIT_CONVERSION);
return_ACPI_STATUS(status);
}
switch (dest_desc->common.type) {
case ACPI_TYPE_LOCAL_REFERENCE:
break;
case ACPI_TYPE_INTEGER:
if (dest_desc->common.flags & AOPOBJ_AML_CONSTANT) {
return_ACPI_STATUS(AE_OK);
}
default:
ACPI_ERROR((AE_INFO,
"Target is not a Reference or Constant object - %s [%p]",
acpi_ut_get_object_type_name(dest_desc),
dest_desc));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
switch (ref_desc->reference.class) {
case ACPI_REFCLASS_REFOF:
status = acpi_ex_store_object_to_node(source_desc,
ref_desc->reference.
object, walk_state,
ACPI_IMPLICIT_CONVERSION);
break;
case ACPI_REFCLASS_INDEX:
status =
acpi_ex_store_object_to_index(source_desc, ref_desc,
walk_state);
break;
case ACPI_REFCLASS_LOCAL:
case ACPI_REFCLASS_ARG:
status =
acpi_ds_store_object_to_local(ref_desc->reference.class,
ref_desc->reference.value,
source_desc, walk_state);
break;
case ACPI_REFCLASS_DEBUG:
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"**** Write to Debug Object: Object %p %s ****:\n\n",
source_desc,
acpi_ut_get_object_type_name(source_desc)));
ACPI_DEBUG_OBJECT(source_desc, 0, 0);
break;
default:
ACPI_ERROR((AE_INFO, "Unknown Reference Class 0x%2.2X",
ref_desc->reference.class));
ACPI_DUMP_ENTRY(ref_desc, ACPI_LV_INFO);
status = AE_AML_INTERNAL;
break;
}
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ex_store_object_to_index(union acpi_operand_object *source_desc,
union acpi_operand_object *index_desc,
struct acpi_walk_state *walk_state)
{
acpi_status status = AE_OK;
union acpi_operand_object *obj_desc;
union acpi_operand_object *new_desc;
u8 value = 0;
u32 i;
ACPI_FUNCTION_TRACE(ex_store_object_to_index);
switch (index_desc->reference.target_type) {
case ACPI_TYPE_PACKAGE:
obj_desc = *(index_desc->reference.where);
if (source_desc->common.type == ACPI_TYPE_LOCAL_REFERENCE &&
source_desc->reference.class == ACPI_REFCLASS_TABLE) {
acpi_ut_add_reference(source_desc);
new_desc = source_desc;
} else {
status =
acpi_ut_copy_iobject_to_iobject(source_desc,
&new_desc,
walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (obj_desc) {
for (i = 0; i < ((union acpi_operand_object *)
index_desc->reference.object)->common.
reference_count; i++) {
acpi_ut_remove_reference(obj_desc);
}
}
*(index_desc->reference.where) = new_desc;
for (i = 1; i < ((union acpi_operand_object *)
index_desc->reference.object)->common.
reference_count; i++) {
acpi_ut_add_reference(new_desc);
}
break;
case ACPI_TYPE_BUFFER_FIELD:
obj_desc = index_desc->reference.object;
if ((obj_desc->common.type != ACPI_TYPE_BUFFER) &&
(obj_desc->common.type != ACPI_TYPE_STRING)) {
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
switch (source_desc->common.type) {
case ACPI_TYPE_INTEGER:
value = (u8) (source_desc->integer.value);
break;
case ACPI_TYPE_BUFFER:
case ACPI_TYPE_STRING:
value = source_desc->buffer.pointer[0];
break;
default:
ACPI_ERROR((AE_INFO,
"Source must be Integer/Buffer/String type, not %s",
acpi_ut_get_object_type_name(source_desc)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
obj_desc->buffer.pointer[index_desc->reference.value] = value;
break;
default:
ACPI_ERROR((AE_INFO, "Target is not a Package or BufferField"));
status = AE_AML_OPERAND_TYPE;
break;
}
return_ACPI_STATUS(status);
}
acpi_status
acpi_ex_store_object_to_node(union acpi_operand_object *source_desc,
struct acpi_namespace_node *node,
struct acpi_walk_state *walk_state,
u8 implicit_conversion)
{
acpi_status status = AE_OK;
union acpi_operand_object *target_desc;
union acpi_operand_object *new_desc;
acpi_object_type target_type;
ACPI_FUNCTION_TRACE_PTR(ex_store_object_to_node, source_desc);
target_type = acpi_ns_get_type(node);
target_desc = acpi_ns_get_attached_object(node);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Storing %p (%s) to node %p (%s)\n",
source_desc,
acpi_ut_get_object_type_name(source_desc), node,
acpi_ut_get_type_name(target_type)));
status = acpi_ex_resolve_object(&source_desc, target_type, walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
switch (target_type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_BUFFER:
if ((walk_state->opcode == AML_COPY_OP) || !implicit_conversion) {
status = acpi_ex_store_direct_to_node(source_desc, node,
walk_state);
break;
}
status =
acpi_ex_store_object_to_object(source_desc, target_desc,
&new_desc, walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (new_desc != target_desc) {
status = acpi_ns_attach_object(node, new_desc,
new_desc->common.type);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Store %s into %s via Convert/Attach\n",
acpi_ut_get_object_type_name
(source_desc),
acpi_ut_get_object_type_name
(new_desc)));
}
break;
case ACPI_TYPE_BUFFER_FIELD:
case ACPI_TYPE_LOCAL_REGION_FIELD:
case ACPI_TYPE_LOCAL_BANK_FIELD:
case ACPI_TYPE_LOCAL_INDEX_FIELD:
status = acpi_ex_write_data_to_field(source_desc, target_desc,
&walk_state->result_obj);
break;
default:
status = acpi_ex_store_direct_to_node(source_desc, node,
walk_state);
break;
}
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ex_store_direct_to_node(union acpi_operand_object *source_desc,
struct acpi_namespace_node *node,
struct acpi_walk_state *walk_state)
{
acpi_status status;
union acpi_operand_object *new_desc;
ACPI_FUNCTION_TRACE(ex_store_direct_to_node);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Storing [%s] (%p) directly into node [%s] (%p)"
" with no implicit conversion\n",
acpi_ut_get_object_type_name(source_desc),
source_desc, acpi_ut_get_type_name(node->type),
node));
status =
acpi_ut_copy_iobject_to_iobject(source_desc, &new_desc, walk_state);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ns_attach_object(node, new_desc, new_desc->common.type);
acpi_ut_remove_reference(new_desc);
return_ACPI_STATUS(status);
}
