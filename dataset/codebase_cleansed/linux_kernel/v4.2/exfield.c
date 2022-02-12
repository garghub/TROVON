static u32
acpi_ex_get_serial_access_length(u32 accessor_type, u32 access_length)
{
u32 length;
switch (accessor_type) {
case AML_FIELD_ATTRIB_QUICK:
length = 0;
break;
case AML_FIELD_ATTRIB_SEND_RCV:
case AML_FIELD_ATTRIB_BYTE:
length = 1;
break;
case AML_FIELD_ATTRIB_WORD:
case AML_FIELD_ATTRIB_WORD_CALL:
length = 2;
break;
case AML_FIELD_ATTRIB_MULTIBYTE:
case AML_FIELD_ATTRIB_RAW_BYTES:
case AML_FIELD_ATTRIB_RAW_PROCESS:
length = access_length;
break;
case AML_FIELD_ATTRIB_BLOCK:
case AML_FIELD_ATTRIB_BLOCK_CALL:
default:
length = ACPI_GSBUS_BUFFER_SIZE - 2;
break;
}
return (length);
}
acpi_status
acpi_ex_read_data_from_field(struct acpi_walk_state * walk_state,
union acpi_operand_object *obj_desc,
union acpi_operand_object **ret_buffer_desc)
{
acpi_status status;
union acpi_operand_object *buffer_desc;
acpi_size length;
void *buffer;
u32 function;
u16 accessor_type;
ACPI_FUNCTION_TRACE_PTR(ex_read_data_from_field, obj_desc);
if (!obj_desc) {
return_ACPI_STATUS(AE_AML_NO_OPERAND);
}
if (!ret_buffer_desc) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (obj_desc->common.type == ACPI_TYPE_BUFFER_FIELD) {
if (!(obj_desc->common.flags & AOPOBJ_DATA_VALID)) {
status = acpi_ds_get_buffer_field_arguments(obj_desc);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
} else if ((obj_desc->common.type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
(obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_SMBUS
|| obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_GSBUS
|| obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_IPMI)) {
if (obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_SMBUS) {
length = ACPI_SMBUS_BUFFER_SIZE;
function =
ACPI_READ | (obj_desc->field.attribute << 16);
} else if (obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_GSBUS) {
accessor_type = obj_desc->field.attribute;
length = acpi_ex_get_serial_access_length(accessor_type,
obj_desc->
field.
access_length);
length += 2;
function = ACPI_READ | (accessor_type << 16);
} else {
length = ACPI_IPMI_BUFFER_SIZE;
function = ACPI_READ;
}
buffer_desc = acpi_ut_create_buffer_object(length);
if (!buffer_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
acpi_ex_acquire_global_lock(obj_desc->common_field.field_flags);
status = acpi_ex_access_region(obj_desc, 0,
ACPI_CAST_PTR(u64,
buffer_desc->
buffer.pointer),
function);
acpi_ex_release_global_lock(obj_desc->common_field.field_flags);
goto exit;
}
length =
(acpi_size) ACPI_ROUND_BITS_UP_TO_BYTES(obj_desc->field.bit_length);
if (length > acpi_gbl_integer_byte_width) {
buffer_desc = acpi_ut_create_buffer_object(length);
if (!buffer_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
buffer = buffer_desc->buffer.pointer;
} else {
buffer_desc = acpi_ut_create_integer_object((u64) 0);
if (!buffer_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
length = acpi_gbl_integer_byte_width;
buffer = &buffer_desc->integer.value;
}
if ((obj_desc->common.type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
(obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_GPIO)) {
ACPI_DEBUG_PRINT((ACPI_DB_BFIELD,
"GPIO FieldRead [FROM]: Pin %u Bits %u\n",
obj_desc->field.pin_number_index,
obj_desc->field.bit_length));
acpi_ex_acquire_global_lock(obj_desc->common_field.field_flags);
status = acpi_ex_access_region(obj_desc, 0,
(u64 *)buffer, ACPI_READ);
acpi_ex_release_global_lock(obj_desc->common_field.field_flags);
if (ACPI_FAILURE(status)) {
acpi_ut_remove_reference(buffer_desc);
} else {
*ret_buffer_desc = buffer_desc;
}
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_BFIELD,
"FieldRead [TO]: Obj %p, Type %X, Buf %p, ByteLen %X\n",
obj_desc, obj_desc->common.type, buffer,
(u32) length));
ACPI_DEBUG_PRINT((ACPI_DB_BFIELD,
"FieldRead [FROM]: BitLen %X, BitOff %X, ByteOff %X\n",
obj_desc->common_field.bit_length,
obj_desc->common_field.start_field_bit_offset,
obj_desc->common_field.base_byte_offset));
acpi_ex_acquire_global_lock(obj_desc->common_field.field_flags);
status = acpi_ex_extract_from_field(obj_desc, buffer, (u32) length);
acpi_ex_release_global_lock(obj_desc->common_field.field_flags);
exit:
if (ACPI_FAILURE(status)) {
acpi_ut_remove_reference(buffer_desc);
} else {
*ret_buffer_desc = buffer_desc;
}
return_ACPI_STATUS(status);
}
acpi_status
acpi_ex_write_data_to_field(union acpi_operand_object *source_desc,
union acpi_operand_object *obj_desc,
union acpi_operand_object **result_desc)
{
acpi_status status;
u32 length;
void *buffer;
union acpi_operand_object *buffer_desc;
u32 function;
u16 accessor_type;
ACPI_FUNCTION_TRACE_PTR(ex_write_data_to_field, obj_desc);
if (!source_desc || !obj_desc) {
return_ACPI_STATUS(AE_AML_NO_OPERAND);
}
if (obj_desc->common.type == ACPI_TYPE_BUFFER_FIELD) {
if (!(obj_desc->common.flags & AOPOBJ_DATA_VALID)) {
status = acpi_ds_get_buffer_field_arguments(obj_desc);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
} else if ((obj_desc->common.type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
(obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_SMBUS
|| obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_GSBUS
|| obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_IPMI)) {
if (source_desc->common.type != ACPI_TYPE_BUFFER) {
ACPI_ERROR((AE_INFO,
"SMBus/IPMI/GenericSerialBus write requires Buffer, found type %s",
acpi_ut_get_object_type_name(source_desc)));
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
if (obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_SMBUS) {
length = ACPI_SMBUS_BUFFER_SIZE;
function =
ACPI_WRITE | (obj_desc->field.attribute << 16);
} else if (obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_GSBUS) {
accessor_type = obj_desc->field.attribute;
length = acpi_ex_get_serial_access_length(accessor_type,
obj_desc->
field.
access_length);
length += 2;
function = ACPI_WRITE | (accessor_type << 16);
} else {
length = ACPI_IPMI_BUFFER_SIZE;
function = ACPI_WRITE;
}
if (source_desc->buffer.length < length) {
ACPI_ERROR((AE_INFO,
"SMBus/IPMI/GenericSerialBus write requires Buffer of length %u, found length %u",
length, source_desc->buffer.length));
return_ACPI_STATUS(AE_AML_BUFFER_LIMIT);
}
buffer_desc = acpi_ut_create_buffer_object(length);
if (!buffer_desc) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
buffer = buffer_desc->buffer.pointer;
memcpy(buffer, source_desc->buffer.pointer, length);
acpi_ex_acquire_global_lock(obj_desc->common_field.field_flags);
status = acpi_ex_access_region(obj_desc, 0,
(u64 *) buffer, function);
acpi_ex_release_global_lock(obj_desc->common_field.field_flags);
*result_desc = buffer_desc;
return_ACPI_STATUS(status);
} else if ((obj_desc->common.type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
(obj_desc->field.region_obj->region.space_id ==
ACPI_ADR_SPACE_GPIO)) {
if (source_desc->common.type != ACPI_TYPE_INTEGER) {
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
ACPI_DEBUG_PRINT((ACPI_DB_BFIELD,
"GPIO FieldWrite [FROM]: (%s:%X), Val %.8X [TO]: Pin %u Bits %u\n",
acpi_ut_get_type_name(source_desc->common.
type),
source_desc->common.type,
(u32)source_desc->integer.value,
obj_desc->field.pin_number_index,
obj_desc->field.bit_length));
buffer = &source_desc->integer.value;
acpi_ex_acquire_global_lock(obj_desc->common_field.field_flags);
status = acpi_ex_access_region(obj_desc, 0,
(u64 *)buffer, ACPI_WRITE);
acpi_ex_release_global_lock(obj_desc->common_field.field_flags);
return_ACPI_STATUS(status);
}
switch (source_desc->common.type) {
case ACPI_TYPE_INTEGER:
buffer = &source_desc->integer.value;
length = sizeof(source_desc->integer.value);
break;
case ACPI_TYPE_BUFFER:
buffer = source_desc->buffer.pointer;
length = source_desc->buffer.length;
break;
case ACPI_TYPE_STRING:
buffer = source_desc->string.pointer;
length = source_desc->string.length;
break;
default:
return_ACPI_STATUS(AE_AML_OPERAND_TYPE);
}
ACPI_DEBUG_PRINT((ACPI_DB_BFIELD,
"FieldWrite [FROM]: Obj %p (%s:%X), Buf %p, ByteLen %X\n",
source_desc,
acpi_ut_get_type_name(source_desc->common.type),
source_desc->common.type, buffer, length));
ACPI_DEBUG_PRINT((ACPI_DB_BFIELD,
"FieldWrite [TO]: Obj %p (%s:%X), BitLen %X, BitOff %X, ByteOff %X\n",
obj_desc,
acpi_ut_get_type_name(obj_desc->common.type),
obj_desc->common.type,
obj_desc->common_field.bit_length,
obj_desc->common_field.start_field_bit_offset,
obj_desc->common_field.base_byte_offset));
acpi_ex_acquire_global_lock(obj_desc->common_field.field_flags);
status = acpi_ex_insert_into_field(obj_desc, buffer, length);
acpi_ex_release_global_lock(obj_desc->common_field.field_flags);
return_ACPI_STATUS(status);
}
