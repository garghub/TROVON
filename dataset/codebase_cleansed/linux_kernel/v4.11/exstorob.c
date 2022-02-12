acpi_status
acpi_ex_store_buffer_to_buffer(union acpi_operand_object *source_desc,
union acpi_operand_object *target_desc)
{
u32 length;
u8 *buffer;
ACPI_FUNCTION_TRACE_PTR(ex_store_buffer_to_buffer, source_desc);
if (source_desc == target_desc) {
return_ACPI_STATUS(AE_OK);
}
buffer = ACPI_CAST_PTR(u8, source_desc->buffer.pointer);
length = source_desc->buffer.length;
if ((target_desc->buffer.length == 0) ||
(target_desc->common.flags & AOPOBJ_STATIC_POINTER)) {
target_desc->buffer.pointer = ACPI_ALLOCATE(length);
if (!target_desc->buffer.pointer) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
target_desc->buffer.length = length;
}
if (length <= target_desc->buffer.length) {
memset(target_desc->buffer.pointer, 0,
target_desc->buffer.length);
memcpy(target_desc->buffer.pointer, buffer, length);
#ifdef ACPI_OBSOLETE_BEHAVIOR
if (original_src_type == ACPI_TYPE_STRING) {
target_desc->buffer.length = length;
}
#endif
} else {
memcpy(target_desc->buffer.pointer, buffer,
target_desc->buffer.length);
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Truncating source buffer from %X to %X\n",
length, target_desc->buffer.length));
}
target_desc->buffer.flags = source_desc->buffer.flags;
target_desc->common.flags &= ~AOPOBJ_STATIC_POINTER;
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ex_store_string_to_string(union acpi_operand_object *source_desc,
union acpi_operand_object *target_desc)
{
u32 length;
u8 *buffer;
ACPI_FUNCTION_TRACE_PTR(ex_store_string_to_string, source_desc);
if (source_desc == target_desc) {
return_ACPI_STATUS(AE_OK);
}
buffer = ACPI_CAST_PTR(u8, source_desc->string.pointer);
length = source_desc->string.length;
if ((length < target_desc->string.length) &&
(!(target_desc->common.flags & AOPOBJ_STATIC_POINTER))) {
memset(target_desc->string.pointer, 0,
(acpi_size)target_desc->string.length + 1);
memcpy(target_desc->string.pointer, buffer, length);
} else {
if (target_desc->string.pointer &&
(!(target_desc->common.flags & AOPOBJ_STATIC_POINTER))) {
ACPI_FREE(target_desc->string.pointer);
}
target_desc->string.pointer =
ACPI_ALLOCATE_ZEROED((acpi_size)length + 1);
if (!target_desc->string.pointer) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
target_desc->common.flags &= ~AOPOBJ_STATIC_POINTER;
memcpy(target_desc->string.pointer, buffer, length);
}
target_desc->string.length = length;
return_ACPI_STATUS(AE_OK);
}
