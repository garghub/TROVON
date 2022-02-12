void
acpi_ex_do_debug_object(union acpi_operand_object *source_desc,
u32 level, u32 index)
{
u32 i;
ACPI_FUNCTION_TRACE_PTR(ex_do_debug_object, source_desc);
if (!acpi_gbl_enable_aml_debug_object &&
!(acpi_dbg_level & ACPI_LV_DEBUG_OBJECT)) {
return_VOID;
}
if (!((level > 0) && index == 0)) {
acpi_os_printf("[ACPI Debug] %*s", level, " ");
}
if (index > 0) {
acpi_os_printf("(%.2u) ", index - 1);
}
if (!source_desc) {
acpi_os_printf("[Null Object]\n");
return_VOID;
}
if (ACPI_GET_DESCRIPTOR_TYPE(source_desc) == ACPI_DESC_TYPE_OPERAND) {
acpi_os_printf("%s ",
acpi_ut_get_object_type_name(source_desc));
if (!acpi_ut_valid_internal_object(source_desc)) {
acpi_os_printf("%p, Invalid Internal Object!\n",
source_desc);
return_VOID;
}
} else if (ACPI_GET_DESCRIPTOR_TYPE(source_desc) ==
ACPI_DESC_TYPE_NAMED) {
acpi_os_printf("%s: %p\n",
acpi_ut_get_type_name(((struct
acpi_namespace_node *)
source_desc)->type),
source_desc);
return_VOID;
} else {
return_VOID;
}
switch (source_desc->common.type) {
case ACPI_TYPE_INTEGER:
if (acpi_gbl_integer_byte_width == 4) {
acpi_os_printf("0x%8.8X\n",
(u32)source_desc->integer.value);
} else {
acpi_os_printf("0x%8.8X%8.8X\n",
ACPI_FORMAT_UINT64(source_desc->integer.
value));
}
break;
case ACPI_TYPE_BUFFER:
acpi_os_printf("[0x%.2X]\n", (u32)source_desc->buffer.length);
acpi_ut_dump_buffer(source_desc->buffer.pointer,
(source_desc->buffer.length < 256) ?
source_desc->buffer.length : 256,
DB_BYTE_DISPLAY, 0);
break;
case ACPI_TYPE_STRING:
acpi_os_printf("[0x%.2X] \"%s\"\n",
source_desc->string.length,
source_desc->string.pointer);
break;
case ACPI_TYPE_PACKAGE:
acpi_os_printf("[Contains 0x%.2X Elements]\n",
source_desc->package.count);
for (i = 0; i < source_desc->package.count; i++) {
acpi_ex_do_debug_object(source_desc->package.
elements[i], level + 4, i + 1);
}
break;
case ACPI_TYPE_LOCAL_REFERENCE:
acpi_os_printf("[%s] ",
acpi_ut_get_reference_name(source_desc));
switch (source_desc->reference.class) {
case ACPI_REFCLASS_INDEX:
acpi_os_printf("0x%X\n", source_desc->reference.value);
break;
case ACPI_REFCLASS_TABLE:
acpi_os_printf("Table Index 0x%X\n",
source_desc->reference.value);
return_VOID;
default:
break;
}
acpi_os_printf(" ");
if (source_desc->reference.node) {
if (ACPI_GET_DESCRIPTOR_TYPE
(source_desc->reference.node) !=
ACPI_DESC_TYPE_NAMED) {
acpi_os_printf
(" %p - Not a valid namespace node\n",
source_desc->reference.node);
} else {
acpi_os_printf("Node %p [%4.4s] ",
source_desc->reference.node,
(source_desc->reference.node)->
name.ascii);
switch ((source_desc->reference.node)->type) {
case ACPI_TYPE_DEVICE:
acpi_os_printf("Device\n");
break;
case ACPI_TYPE_THERMAL:
acpi_os_printf("Thermal Zone\n");
break;
default:
acpi_ex_do_debug_object((source_desc->
reference.
node)->object,
level + 4, 0);
break;
}
}
} else if (source_desc->reference.object) {
if (ACPI_GET_DESCRIPTOR_TYPE
(source_desc->reference.object) ==
ACPI_DESC_TYPE_NAMED) {
acpi_ex_do_debug_object(((struct
acpi_namespace_node *)
source_desc->reference.
object)->object,
level + 4, 0);
} else {
acpi_ex_do_debug_object(source_desc->reference.
object, level + 4, 0);
}
}
break;
default:
acpi_os_printf("%p\n", source_desc);
break;
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_EXEC, "\n"));
return_VOID;
}
