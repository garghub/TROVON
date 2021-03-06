static void
acpi_ex_dump_object(union acpi_operand_object *obj_desc,
struct acpi_exdump_info *info)
{
u8 *target;
char *name;
const char *reference_name;
u8 count;
if (!info) {
acpi_os_printf
("ExDumpObject: Display not implemented for object type %s\n",
acpi_ut_get_object_type_name(obj_desc));
return;
}
count = info->offset;
while (count) {
target = ACPI_ADD_PTR(u8, obj_desc, info->offset);
name = info->name;
switch (info->opcode) {
case ACPI_EXD_INIT:
break;
case ACPI_EXD_TYPE:
acpi_ex_out_string("Type",
acpi_ut_get_object_type_name
(obj_desc));
break;
case ACPI_EXD_UINT8:
acpi_os_printf("%20s : %2.2X\n", name, *target);
break;
case ACPI_EXD_UINT16:
acpi_os_printf("%20s : %4.4X\n", name,
ACPI_GET16(target));
break;
case ACPI_EXD_UINT32:
acpi_os_printf("%20s : %8.8X\n", name,
ACPI_GET32(target));
break;
case ACPI_EXD_UINT64:
acpi_os_printf("%20s : %8.8X%8.8X\n", "Value",
ACPI_FORMAT_UINT64(ACPI_GET64(target)));
break;
case ACPI_EXD_POINTER:
case ACPI_EXD_ADDRESS:
acpi_ex_out_pointer(name,
*ACPI_CAST_PTR(void *, target));
break;
case ACPI_EXD_STRING:
acpi_ut_print_string(obj_desc->string.pointer,
ACPI_UINT8_MAX);
acpi_os_printf("\n");
break;
case ACPI_EXD_BUFFER:
ACPI_DUMP_BUFFER(obj_desc->buffer.pointer,
obj_desc->buffer.length);
break;
case ACPI_EXD_PACKAGE:
acpi_os_printf("\nPackage Contents:\n");
acpi_ex_dump_package_obj(obj_desc, 0, 0);
break;
case ACPI_EXD_FIELD:
acpi_ex_dump_object(obj_desc,
acpi_ex_dump_field_common);
break;
case ACPI_EXD_REFERENCE:
reference_name = acpi_ut_get_reference_name(obj_desc);
acpi_ex_out_string("Class Name",
ACPI_CAST_PTR(char, reference_name));
acpi_ex_dump_reference_obj(obj_desc);
break;
default:
acpi_os_printf("**** Invalid table opcode [%X] ****\n",
info->opcode);
return;
}
info++;
count--;
}
}
void acpi_ex_dump_operand(union acpi_operand_object *obj_desc, u32 depth)
{
u32 length;
u32 index;
ACPI_FUNCTION_NAME(ex_dump_operand)
if (!ACPI_IS_DEBUG_ENABLED(ACPI_LV_EXEC, _COMPONENT)) {
return;
}
if (!obj_desc) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "Null Object Descriptor\n"));
return;
}
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) == ACPI_DESC_TYPE_NAMED) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "%p Namespace Node: ",
obj_desc));
ACPI_DUMP_ENTRY(obj_desc, ACPI_LV_EXEC);
return;
}
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) != ACPI_DESC_TYPE_OPERAND) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"%p is not a node or operand object: [%s]\n",
obj_desc,
acpi_ut_get_descriptor_name(obj_desc)));
ACPI_DUMP_BUFFER(obj_desc, sizeof(union acpi_operand_object));
return;
}
if (depth > 0) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "%*s[%u] %p ",
depth, " ", depth, obj_desc));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "%p ", obj_desc));
}
switch (obj_desc->common.type) {
case ACPI_TYPE_LOCAL_REFERENCE:
acpi_os_printf("Reference: [%s] ",
acpi_ut_get_reference_name(obj_desc));
switch (obj_desc->reference.class) {
case ACPI_REFCLASS_DEBUG:
acpi_os_printf("\n");
break;
case ACPI_REFCLASS_INDEX:
acpi_os_printf("%p\n", obj_desc->reference.object);
break;
case ACPI_REFCLASS_TABLE:
acpi_os_printf("Table Index %X\n",
obj_desc->reference.value);
break;
case ACPI_REFCLASS_REFOF:
acpi_os_printf("%p [%s]\n", obj_desc->reference.object,
acpi_ut_get_type_name(((union
acpi_operand_object
*)
obj_desc->
reference.
object)->common.
type));
break;
case ACPI_REFCLASS_NAME:
acpi_os_printf("- [%4.4s]\n",
obj_desc->reference.node->name.ascii);
break;
case ACPI_REFCLASS_ARG:
case ACPI_REFCLASS_LOCAL:
acpi_os_printf("%X\n", obj_desc->reference.value);
break;
default:
acpi_os_printf("%2.2X\n", obj_desc->reference.class);
break;
}
break;
case ACPI_TYPE_BUFFER:
acpi_os_printf("Buffer length %.2X @ %p\n",
obj_desc->buffer.length,
obj_desc->buffer.pointer);
if (obj_desc->buffer.pointer) {
length = obj_desc->buffer.length;
if (length > 128) {
length = 128;
}
acpi_os_printf
("Buffer Contents: (displaying length 0x%.2X)\n",
length);
ACPI_DUMP_BUFFER(obj_desc->buffer.pointer, length);
}
break;
case ACPI_TYPE_INTEGER:
acpi_os_printf("Integer %8.8X%8.8X\n",
ACPI_FORMAT_UINT64(obj_desc->integer.value));
break;
case ACPI_TYPE_PACKAGE:
acpi_os_printf("Package [Len %X] ElementArray %p\n",
obj_desc->package.count,
obj_desc->package.elements);
if (obj_desc->package.count &&
obj_desc->package.elements && acpi_dbg_level > 1) {
for (index = 0; index < obj_desc->package.count;
index++) {
acpi_ex_dump_operand(obj_desc->package.
elements[index],
depth + 1);
}
}
break;
case ACPI_TYPE_REGION:
acpi_os_printf("Region %s (%X)",
acpi_ut_get_region_name(obj_desc->region.
space_id),
obj_desc->region.space_id);
if (!(obj_desc->region.flags & AOPOBJ_DATA_VALID)) {
acpi_os_printf("\n");
} else {
acpi_os_printf(" base %8.8X%8.8X Length %X\n",
ACPI_FORMAT_NATIVE_UINT(obj_desc->region.
address),
obj_desc->region.length);
}
break;
case ACPI_TYPE_STRING:
acpi_os_printf("String length %X @ %p ",
obj_desc->string.length,
obj_desc->string.pointer);
acpi_ut_print_string(obj_desc->string.pointer, ACPI_UINT8_MAX);
acpi_os_printf("\n");
break;
case ACPI_TYPE_LOCAL_BANK_FIELD:
acpi_os_printf("BankField\n");
break;
case ACPI_TYPE_LOCAL_REGION_FIELD:
acpi_os_printf
("RegionField: Bits=%X AccWidth=%X Lock=%X Update=%X at "
"byte=%X bit=%X of below:\n", obj_desc->field.bit_length,
obj_desc->field.access_byte_width,
obj_desc->field.field_flags & AML_FIELD_LOCK_RULE_MASK,
obj_desc->field.field_flags & AML_FIELD_UPDATE_RULE_MASK,
obj_desc->field.base_byte_offset,
obj_desc->field.start_field_bit_offset);
acpi_ex_dump_operand(obj_desc->field.region_obj, depth + 1);
break;
case ACPI_TYPE_LOCAL_INDEX_FIELD:
acpi_os_printf("IndexField\n");
break;
case ACPI_TYPE_BUFFER_FIELD:
acpi_os_printf("BufferField: %X bits at byte %X bit %X of\n",
obj_desc->buffer_field.bit_length,
obj_desc->buffer_field.base_byte_offset,
obj_desc->buffer_field.start_field_bit_offset);
if (!obj_desc->buffer_field.buffer_obj) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "*NULL*\n"));
} else if ((obj_desc->buffer_field.buffer_obj)->common.type !=
ACPI_TYPE_BUFFER) {
acpi_os_printf("*not a Buffer*\n");
} else {
acpi_ex_dump_operand(obj_desc->buffer_field.buffer_obj,
depth + 1);
}
break;
case ACPI_TYPE_EVENT:
acpi_os_printf("Event\n");
break;
case ACPI_TYPE_METHOD:
acpi_os_printf("Method(%X) @ %p:%X\n",
obj_desc->method.param_count,
obj_desc->method.aml_start,
obj_desc->method.aml_length);
break;
case ACPI_TYPE_MUTEX:
acpi_os_printf("Mutex\n");
break;
case ACPI_TYPE_DEVICE:
acpi_os_printf("Device\n");
break;
case ACPI_TYPE_POWER:
acpi_os_printf("Power\n");
break;
case ACPI_TYPE_PROCESSOR:
acpi_os_printf("Processor\n");
break;
case ACPI_TYPE_THERMAL:
acpi_os_printf("Thermal\n");
break;
default:
acpi_os_printf("Unknown Type %X\n", obj_desc->common.type);
break;
}
return;
}
void
acpi_ex_dump_operands(union acpi_operand_object **operands,
const char *opcode_name, u32 num_operands)
{
ACPI_FUNCTION_NAME(ex_dump_operands);
if (!opcode_name) {
opcode_name = "UNKNOWN";
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"**** Start operand dump for opcode [%s], %u operands\n",
opcode_name, num_operands));
if (num_operands == 0) {
num_operands = 1;
}
while (num_operands) {
acpi_ex_dump_operand(*operands, 0);
operands++;
num_operands--;
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"**** End operand dump for [%s]\n", opcode_name));
return;
}
static void acpi_ex_out_string(char *title, char *value)
{
acpi_os_printf("%20s : %s\n", title, value);
}
static void acpi_ex_out_pointer(char *title, void *value)
{
acpi_os_printf("%20s : %p\n", title, value);
}
void acpi_ex_dump_namespace_node(struct acpi_namespace_node *node, u32 flags)
{
ACPI_FUNCTION_ENTRY();
if (!flags) {
if (!ACPI_IS_DEBUG_ENABLED(ACPI_LV_OBJECTS, _COMPONENT)) {
return;
}
}
acpi_os_printf("%20s : %4.4s\n", "Name", acpi_ut_get_node_name(node));
acpi_ex_out_string("Type", acpi_ut_get_type_name(node->type));
acpi_ex_out_pointer("Attached Object",
acpi_ns_get_attached_object(node));
acpi_ex_out_pointer("Parent", node->parent);
acpi_ex_dump_object(ACPI_CAST_PTR(union acpi_operand_object, node),
acpi_ex_dump_node);
}
static void acpi_ex_dump_reference_obj(union acpi_operand_object *obj_desc)
{
struct acpi_buffer ret_buf;
acpi_status status;
ret_buf.length = ACPI_ALLOCATE_LOCAL_BUFFER;
if (obj_desc->reference.class == ACPI_REFCLASS_NAME) {
acpi_os_printf(" %p ", obj_desc->reference.node);
status =
acpi_ns_handle_to_pathname(obj_desc->reference.node,
&ret_buf);
if (ACPI_FAILURE(status)) {
acpi_os_printf(" Could not convert name to pathname\n");
} else {
acpi_os_printf("%s\n", (char *)ret_buf.pointer);
ACPI_FREE(ret_buf.pointer);
}
} else if (obj_desc->reference.object) {
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) ==
ACPI_DESC_TYPE_OPERAND) {
acpi_os_printf(" Target: %p",
obj_desc->reference.object);
if (obj_desc->reference.class == ACPI_REFCLASS_TABLE) {
acpi_os_printf(" Table Index: %X\n",
obj_desc->reference.value);
} else {
acpi_os_printf(" Target: %p [%s]\n",
obj_desc->reference.object,
acpi_ut_get_type_name(((union
acpi_operand_object
*)
obj_desc->
reference.
object)->
common.
type));
}
} else {
acpi_os_printf(" Target: %p\n",
obj_desc->reference.object);
}
}
}
static void
acpi_ex_dump_package_obj(union acpi_operand_object *obj_desc,
u32 level, u32 index)
{
u32 i;
if (level > 0) {
for (i = 0; i < level; i++) {
acpi_os_printf(" ");
}
acpi_os_printf("[%.2d] ", index);
}
acpi_os_printf("%p ", obj_desc);
if (!obj_desc) {
acpi_os_printf("[Null Object]\n");
return;
}
switch (obj_desc->common.type) {
case ACPI_TYPE_INTEGER:
acpi_os_printf("[Integer] = %8.8X%8.8X\n",
ACPI_FORMAT_UINT64(obj_desc->integer.value));
break;
case ACPI_TYPE_STRING:
acpi_os_printf("[String] Value: ");
acpi_ut_print_string(obj_desc->string.pointer, ACPI_UINT8_MAX);
acpi_os_printf("\n");
break;
case ACPI_TYPE_BUFFER:
acpi_os_printf("[Buffer] Length %.2X = ",
obj_desc->buffer.length);
if (obj_desc->buffer.length) {
acpi_ut_debug_dump_buffer(ACPI_CAST_PTR
(u8,
obj_desc->buffer.pointer),
obj_desc->buffer.length,
DB_DWORD_DISPLAY, _COMPONENT);
} else {
acpi_os_printf("\n");
}
break;
case ACPI_TYPE_PACKAGE:
acpi_os_printf("[Package] Contains %u Elements:\n",
obj_desc->package.count);
for (i = 0; i < obj_desc->package.count; i++) {
acpi_ex_dump_package_obj(obj_desc->package.elements[i],
level + 1, i);
}
break;
case ACPI_TYPE_LOCAL_REFERENCE:
acpi_os_printf("[Object Reference] Type [%s] %2.2X",
acpi_ut_get_reference_name(obj_desc),
obj_desc->reference.class);
acpi_ex_dump_reference_obj(obj_desc);
break;
default:
acpi_os_printf("[Unknown Type] %X\n", obj_desc->common.type);
break;
}
}
void
acpi_ex_dump_object_descriptor(union acpi_operand_object *obj_desc, u32 flags)
{
ACPI_FUNCTION_TRACE(ex_dump_object_descriptor);
if (!obj_desc) {
return_VOID;
}
if (!flags) {
if (!ACPI_IS_DEBUG_ENABLED(ACPI_LV_OBJECTS, _COMPONENT)) {
return_VOID;
}
}
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) == ACPI_DESC_TYPE_NAMED) {
acpi_ex_dump_namespace_node((struct acpi_namespace_node *)
obj_desc, flags);
acpi_os_printf("\nAttached Object (%p):\n",
((struct acpi_namespace_node *)obj_desc)->
object);
acpi_ex_dump_object_descriptor(((struct acpi_namespace_node *)
obj_desc)->object, flags);
return_VOID;
}
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) != ACPI_DESC_TYPE_OPERAND) {
acpi_os_printf
("ExDumpObjectDescriptor: %p is not an ACPI operand object: [%s]\n",
obj_desc, acpi_ut_get_descriptor_name(obj_desc));
return_VOID;
}
if (obj_desc->common.type > ACPI_TYPE_NS_NODE_MAX) {
return_VOID;
}
acpi_ex_dump_object(obj_desc, acpi_ex_dump_common);
acpi_ex_dump_object(obj_desc, acpi_ex_dump_info[obj_desc->common.type]);
return_VOID;
}
