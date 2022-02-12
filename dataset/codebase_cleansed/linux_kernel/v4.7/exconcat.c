acpi_status
acpi_ex_do_concatenate(union acpi_operand_object *operand0,
union acpi_operand_object *operand1,
union acpi_operand_object **actual_return_desc,
struct acpi_walk_state *walk_state)
{
union acpi_operand_object *local_operand0 = operand0;
union acpi_operand_object *local_operand1 = operand1;
union acpi_operand_object *temp_operand1 = NULL;
union acpi_operand_object *return_desc;
char *buffer;
acpi_object_type operand0_type;
acpi_object_type operand1_type;
acpi_status status;
ACPI_FUNCTION_TRACE(ex_do_concatenate);
switch (operand0->common.type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_BUFFER:
operand0_type = operand0->common.type;
break;
default:
status =
acpi_ex_convert_to_object_type_string(operand0,
&local_operand0);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
operand0_type = ACPI_TYPE_STRING;
break;
}
switch (operand1->common.type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_BUFFER:
operand1_type = operand1->common.type;
break;
default:
status =
acpi_ex_convert_to_object_type_string(operand1,
&local_operand1);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
operand1_type = ACPI_TYPE_STRING;
break;
}
switch (operand0_type) {
case ACPI_TYPE_INTEGER:
status =
acpi_ex_convert_to_integer(local_operand1, &temp_operand1,
16);
break;
case ACPI_TYPE_BUFFER:
status =
acpi_ex_convert_to_buffer(local_operand1, &temp_operand1);
break;
case ACPI_TYPE_STRING:
switch (operand1_type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_BUFFER:
status =
acpi_ex_convert_to_string(local_operand1,
&temp_operand1,
ACPI_IMPLICIT_CONVERT_HEX);
break;
default:
status = AE_OK;
break;
}
break;
default:
ACPI_ERROR((AE_INFO, "Invalid object type: 0x%X",
operand0->common.type));
status = AE_AML_INTERNAL;
}
if (ACPI_FAILURE(status)) {
goto cleanup;
}
if ((local_operand1 != operand1) && (local_operand1 != temp_operand1)) {
acpi_ut_remove_reference(local_operand1);
}
local_operand1 = temp_operand1;
switch (operand0_type) {
case ACPI_TYPE_INTEGER:
return_desc = acpi_ut_create_buffer_object((acpi_size)
ACPI_MUL_2
(acpi_gbl_integer_byte_width));
if (!return_desc) {
status = AE_NO_MEMORY;
goto cleanup;
}
buffer = (char *)return_desc->buffer.pointer;
memcpy(buffer, &operand0->integer.value,
acpi_gbl_integer_byte_width);
memcpy(buffer + acpi_gbl_integer_byte_width,
&local_operand1->integer.value,
acpi_gbl_integer_byte_width);
break;
case ACPI_TYPE_STRING:
return_desc = acpi_ut_create_string_object(((acpi_size)
local_operand0->
string.length +
local_operand1->
string.length));
if (!return_desc) {
status = AE_NO_MEMORY;
goto cleanup;
}
buffer = return_desc->string.pointer;
strcpy(buffer, local_operand0->string.pointer);
strcat(buffer, local_operand1->string.pointer);
break;
case ACPI_TYPE_BUFFER:
return_desc = acpi_ut_create_buffer_object(((acpi_size)
operand0->buffer.
length +
local_operand1->
buffer.length));
if (!return_desc) {
status = AE_NO_MEMORY;
goto cleanup;
}
buffer = (char *)return_desc->buffer.pointer;
memcpy(buffer, operand0->buffer.pointer,
operand0->buffer.length);
memcpy(buffer + operand0->buffer.length,
local_operand1->buffer.pointer,
local_operand1->buffer.length);
break;
default:
ACPI_ERROR((AE_INFO, "Invalid object type: 0x%X",
operand0->common.type));
status = AE_AML_INTERNAL;
goto cleanup;
}
*actual_return_desc = return_desc;
cleanup:
if (local_operand0 != operand0) {
acpi_ut_remove_reference(local_operand0);
}
if (local_operand1 != operand1) {
acpi_ut_remove_reference(local_operand1);
}
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ex_convert_to_object_type_string(union acpi_operand_object *obj_desc,
union acpi_operand_object **result_desc)
{
union acpi_operand_object *return_desc;
const char *type_string;
type_string = acpi_ut_get_type_name(obj_desc->common.type);
return_desc = acpi_ut_create_string_object(((acpi_size)strlen(type_string) + 9));
if (!return_desc) {
return (AE_NO_MEMORY);
}
strcpy(return_desc->string.pointer, "[");
strcat(return_desc->string.pointer, type_string);
strcat(return_desc->string.pointer, " Object]");
*result_desc = return_desc;
return (AE_OK);
}
acpi_status
acpi_ex_concat_template(union acpi_operand_object *operand0,
union acpi_operand_object *operand1,
union acpi_operand_object **actual_return_desc,
struct acpi_walk_state *walk_state)
{
acpi_status status;
union acpi_operand_object *return_desc;
u8 *new_buf;
u8 *end_tag;
acpi_size length0;
acpi_size length1;
acpi_size new_length;
ACPI_FUNCTION_TRACE(ex_concat_template);
status = acpi_ut_get_resource_end_tag(operand0, &end_tag);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
length0 = ACPI_PTR_DIFF(end_tag, operand0->buffer.pointer);
status = acpi_ut_get_resource_end_tag(operand1, &end_tag);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
length1 = ACPI_PTR_DIFF(end_tag, operand1->buffer.pointer);
new_length = length0 + length1 + sizeof(struct aml_resource_end_tag);
return_desc = acpi_ut_create_buffer_object(new_length);
if (!return_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
new_buf = return_desc->buffer.pointer;
memcpy(new_buf, operand0->buffer.pointer, length0);
memcpy(new_buf + length0, operand1->buffer.pointer, length1);
new_buf[new_length - 1] = 0;
new_buf[new_length - 2] = ACPI_RESOURCE_NAME_END_TAG | 1;
*actual_return_desc = return_desc;
return_ACPI_STATUS(AE_OK);
}
