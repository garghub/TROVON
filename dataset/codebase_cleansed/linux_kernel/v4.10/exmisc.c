acpi_status
acpi_ex_get_object_reference(union acpi_operand_object *obj_desc,
union acpi_operand_object **return_desc,
struct acpi_walk_state *walk_state)
{
union acpi_operand_object *reference_obj;
union acpi_operand_object *referenced_obj;
ACPI_FUNCTION_TRACE_PTR(ex_get_object_reference, obj_desc);
*return_desc = NULL;
switch (ACPI_GET_DESCRIPTOR_TYPE(obj_desc)) {
case ACPI_DESC_TYPE_OPERAND:
if (obj_desc->common.type != ACPI_TYPE_LOCAL_REFERENCE) {
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
switch (obj_desc->reference.class) {
case ACPI_REFCLASS_LOCAL:
case ACPI_REFCLASS_ARG:
case ACPI_REFCLASS_DEBUG:
referenced_obj = obj_desc->reference.object;
break;
default:
ACPI_ERROR((AE_INFO, "Invalid Reference Class 0x%2.2X",
obj_desc->reference.class));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
break;
case ACPI_DESC_TYPE_NAMED:
referenced_obj = obj_desc;
break;
default:
ACPI_ERROR((AE_INFO, "Invalid descriptor type 0x%X",
ACPI_GET_DESCRIPTOR_TYPE(obj_desc)));
return_ACPI_STATUS(AE_TYPE);
}
reference_obj =
acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_REFERENCE);
if (!reference_obj) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
reference_obj->reference.class = ACPI_REFCLASS_REFOF;
reference_obj->reference.object = referenced_obj;
*return_desc = reference_obj;
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Object %p Type [%s], returning Reference %p\n",
obj_desc, acpi_ut_get_object_type_name(obj_desc),
*return_desc));
return_ACPI_STATUS(AE_OK);
}
u64 acpi_ex_do_math_op(u16 opcode, u64 integer0, u64 integer1)
{
ACPI_FUNCTION_ENTRY();
switch (opcode) {
case AML_ADD_OP:
return (integer0 + integer1);
case AML_BIT_AND_OP:
return (integer0 & integer1);
case AML_BIT_NAND_OP:
return (~(integer0 & integer1));
case AML_BIT_OR_OP:
return (integer0 | integer1);
case AML_BIT_NOR_OP:
return (~(integer0 | integer1));
case AML_BIT_XOR_OP:
return (integer0 ^ integer1);
case AML_MULTIPLY_OP:
return (integer0 * integer1);
case AML_SHIFT_LEFT_OP:
if (integer1 >= acpi_gbl_integer_bit_width) {
return (0);
}
return (integer0 << integer1);
case AML_SHIFT_RIGHT_OP:
if (integer1 >= acpi_gbl_integer_bit_width) {
return (0);
}
return (integer0 >> integer1);
case AML_SUBTRACT_OP:
return (integer0 - integer1);
default:
return (0);
}
}
acpi_status
acpi_ex_do_logical_numeric_op(u16 opcode,
u64 integer0, u64 integer1, u8 *logical_result)
{
acpi_status status = AE_OK;
u8 local_result = FALSE;
ACPI_FUNCTION_TRACE(ex_do_logical_numeric_op);
switch (opcode) {
case AML_LAND_OP:
if (integer0 && integer1) {
local_result = TRUE;
}
break;
case AML_LOR_OP:
if (integer0 || integer1) {
local_result = TRUE;
}
break;
default:
status = AE_AML_INTERNAL;
break;
}
*logical_result = local_result;
return_ACPI_STATUS(status);
}
acpi_status
acpi_ex_do_logical_op(u16 opcode,
union acpi_operand_object *operand0,
union acpi_operand_object *operand1, u8 * logical_result)
{
union acpi_operand_object *local_operand1 = operand1;
u64 integer0;
u64 integer1;
u32 length0;
u32 length1;
acpi_status status = AE_OK;
u8 local_result = FALSE;
int compare;
ACPI_FUNCTION_TRACE(ex_do_logical_op);
switch (operand0->common.type) {
case ACPI_TYPE_INTEGER:
status = acpi_ex_convert_to_integer(operand1, &local_operand1,
ACPI_STRTOUL_BASE16);
break;
case ACPI_TYPE_STRING:
status =
acpi_ex_convert_to_string(operand1, &local_operand1,
ACPI_IMPLICIT_CONVERT_HEX);
break;
case ACPI_TYPE_BUFFER:
status = acpi_ex_convert_to_buffer(operand1, &local_operand1);
break;
default:
status = AE_AML_INTERNAL;
break;
}
if (ACPI_FAILURE(status)) {
goto cleanup;
}
if (operand0->common.type == ACPI_TYPE_INTEGER) {
integer0 = operand0->integer.value;
integer1 = local_operand1->integer.value;
switch (opcode) {
case AML_LEQUAL_OP:
if (integer0 == integer1) {
local_result = TRUE;
}
break;
case AML_LGREATER_OP:
if (integer0 > integer1) {
local_result = TRUE;
}
break;
case AML_LLESS_OP:
if (integer0 < integer1) {
local_result = TRUE;
}
break;
default:
status = AE_AML_INTERNAL;
break;
}
} else {
length0 = operand0->buffer.length;
length1 = local_operand1->buffer.length;
compare = memcmp(operand0->buffer.pointer,
local_operand1->buffer.pointer,
(length0 > length1) ? length1 : length0);
switch (opcode) {
case AML_LEQUAL_OP:
if ((length0 == length1) && (compare == 0)) {
local_result = TRUE;
}
break;
case AML_LGREATER_OP:
if (compare > 0) {
local_result = TRUE;
goto cleanup;
}
if (compare < 0) {
goto cleanup;
}
if (length0 > length1) {
local_result = TRUE;
}
break;
case AML_LLESS_OP:
if (compare > 0) {
goto cleanup;
}
if (compare < 0) {
local_result = TRUE;
goto cleanup;
}
if (length0 < length1) {
local_result = TRUE;
}
break;
default:
status = AE_AML_INTERNAL;
break;
}
}
cleanup:
if (local_operand1 != operand1) {
acpi_ut_remove_reference(local_operand1);
}
*logical_result = local_result;
return_ACPI_STATUS(status);
}
