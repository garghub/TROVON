void
acpi_ex_do_debug_object(union acpi_operand_object *source_desc,
u32 level, u32 index)
{
u32 i;
u32 timer;
union acpi_operand_object *object_desc;
u32 value;
ACPI_FUNCTION_TRACE_PTR(ex_do_debug_object, source_desc);
if (!acpi_gbl_enable_aml_debug_object &&
!(acpi_dbg_level & ACPI_LV_DEBUG_OBJECT)) {
return_VOID;
}
timer = ((u32)acpi_os_get_timer() / 10);
timer &= 0x03FFFFFF;
if (!((level > 0) && index == 0)) {
acpi_os_printf("[ACPI Debug %.8u] %*s", timer, level, " ");
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
object_desc = source_desc->reference.object;
value = source_desc->reference.value;
switch (object_desc->common.type) {
case ACPI_TYPE_BUFFER:
acpi_os_printf("Buffer[%u] = 0x%2.2X\n",
value,
*source_desc->reference.
index_pointer);
break;
case ACPI_TYPE_STRING:
acpi_os_printf
("String[%u] = \"%c\" (0x%2.2X)\n",
value,
*source_desc->reference.
index_pointer,
*source_desc->reference.
index_pointer);
break;
case ACPI_TYPE_PACKAGE:
acpi_os_printf("Package[%u] = ", value);
acpi_ex_do_debug_object(*source_desc->
reference.where,
level + 4, 0);
break;
default:
acpi_os_printf
("Unknown Reference object type %X\n",
object_desc->common.type);
break;
}
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
static u8 acpi_ex_interpreter_trace_enabled(char *name)
{
if (!(acpi_gbl_trace_flags & ACPI_TRACE_ENABLED)) {
return (FALSE);
}
if (acpi_gbl_trace_method_object) {
return (TRUE);
}
if (name &&
(acpi_gbl_trace_method_name &&
strcmp(acpi_gbl_trace_method_name, name))) {
return (FALSE);
}
if ((acpi_gbl_trace_flags & ACPI_TRACE_ONESHOT) &&
!acpi_gbl_trace_method_name) {
return (FALSE);
}
return (TRUE);
}
static const char *acpi_ex_get_trace_event_name(acpi_trace_event_type type)
{
switch (type) {
case ACPI_TRACE_AML_METHOD:
return "Method";
case ACPI_TRACE_AML_OPCODE:
return "Opcode";
case ACPI_TRACE_AML_REGION:
return "Region";
default:
return "";
}
}
void
acpi_ex_trace_point(acpi_trace_event_type type,
u8 begin, u8 *aml, char *pathname)
{
ACPI_FUNCTION_NAME(ex_trace_point);
if (pathname) {
ACPI_DEBUG_PRINT((ACPI_DB_TRACE_POINT,
"%s %s [0x%p:%s] execution.\n",
acpi_ex_get_trace_event_name(type),
begin ? "Begin" : "End", aml, pathname));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_TRACE_POINT,
"%s %s [0x%p] execution.\n",
acpi_ex_get_trace_event_name(type),
begin ? "Begin" : "End", aml));
}
}
void
acpi_ex_start_trace_method(struct acpi_namespace_node *method_node,
union acpi_operand_object *obj_desc,
struct acpi_walk_state *walk_state)
{
acpi_status status;
char *pathname = NULL;
u8 enabled = FALSE;
ACPI_FUNCTION_NAME(ex_start_trace_method);
if (method_node) {
pathname = acpi_ns_get_normalized_pathname(method_node, TRUE);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
goto exit;
}
enabled = acpi_ex_interpreter_trace_enabled(pathname);
if (enabled && !acpi_gbl_trace_method_object) {
acpi_gbl_trace_method_object = obj_desc;
acpi_gbl_original_dbg_level = acpi_dbg_level;
acpi_gbl_original_dbg_layer = acpi_dbg_layer;
acpi_dbg_level = ACPI_TRACE_LEVEL_ALL;
acpi_dbg_layer = ACPI_TRACE_LAYER_ALL;
if (acpi_gbl_trace_dbg_level) {
acpi_dbg_level = acpi_gbl_trace_dbg_level;
}
if (acpi_gbl_trace_dbg_layer) {
acpi_dbg_layer = acpi_gbl_trace_dbg_layer;
}
}
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
exit:
if (enabled) {
ACPI_TRACE_POINT(ACPI_TRACE_AML_METHOD, TRUE,
obj_desc ? obj_desc->method.aml_start : NULL,
pathname);
}
if (pathname) {
ACPI_FREE(pathname);
}
}
void
acpi_ex_stop_trace_method(struct acpi_namespace_node *method_node,
union acpi_operand_object *obj_desc,
struct acpi_walk_state *walk_state)
{
acpi_status status;
char *pathname = NULL;
u8 enabled;
ACPI_FUNCTION_NAME(ex_stop_trace_method);
if (method_node) {
pathname = acpi_ns_get_normalized_pathname(method_node, TRUE);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
goto exit_path;
}
enabled = acpi_ex_interpreter_trace_enabled(NULL);
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
if (enabled) {
ACPI_TRACE_POINT(ACPI_TRACE_AML_METHOD, FALSE,
obj_desc ? obj_desc->method.aml_start : NULL,
pathname);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
goto exit_path;
}
if (acpi_gbl_trace_method_object == obj_desc) {
if (acpi_gbl_trace_flags & ACPI_TRACE_ONESHOT) {
acpi_gbl_trace_method_name = NULL;
}
acpi_dbg_level = acpi_gbl_original_dbg_level;
acpi_dbg_layer = acpi_gbl_original_dbg_layer;
acpi_gbl_trace_method_object = NULL;
}
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
exit_path:
if (pathname) {
ACPI_FREE(pathname);
}
}
void
acpi_ex_start_trace_opcode(union acpi_parse_object *op,
struct acpi_walk_state *walk_state)
{
ACPI_FUNCTION_NAME(ex_start_trace_opcode);
if (acpi_ex_interpreter_trace_enabled(NULL) &&
(acpi_gbl_trace_flags & ACPI_TRACE_OPCODE)) {
ACPI_TRACE_POINT(ACPI_TRACE_AML_OPCODE, TRUE,
op->common.aml, op->common.aml_op_name);
}
}
void
acpi_ex_stop_trace_opcode(union acpi_parse_object *op,
struct acpi_walk_state *walk_state)
{
ACPI_FUNCTION_NAME(ex_stop_trace_opcode);
if (acpi_ex_interpreter_trace_enabled(NULL) &&
(acpi_gbl_trace_flags & ACPI_TRACE_OPCODE)) {
ACPI_TRACE_POINT(ACPI_TRACE_AML_OPCODE, FALSE,
op->common.aml, op->common.aml_op_name);
}
}
