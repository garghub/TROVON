void
acpi_db_dump_method_info(acpi_status status, struct acpi_walk_state *walk_state)
{
struct acpi_thread_state *thread;
if ((status & AE_CODE_MASK) == AE_CODE_CONTROL) {
return;
}
if (walk_state->deferred_node) {
acpi_os_printf("Executing subtree for Buffer/Package/Region\n");
return;
}
thread = walk_state->thread;
if (!thread) {
return;
}
acpi_os_printf("\n");
acpi_db_decode_locals(walk_state);
acpi_os_printf("\n");
acpi_db_decode_arguments(walk_state);
acpi_os_printf("\n");
}
void acpi_db_decode_internal_object(union acpi_operand_object *obj_desc)
{
u32 i;
if (!obj_desc) {
acpi_os_printf(" Uninitialized");
return;
}
if (ACPI_GET_DESCRIPTOR_TYPE(obj_desc) != ACPI_DESC_TYPE_OPERAND) {
acpi_os_printf(" %p [%s]", obj_desc,
acpi_ut_get_descriptor_name(obj_desc));
return;
}
acpi_os_printf(" %s", acpi_ut_get_object_type_name(obj_desc));
switch (obj_desc->common.type) {
case ACPI_TYPE_INTEGER:
acpi_os_printf(" %8.8X%8.8X",
ACPI_FORMAT_UINT64(obj_desc->integer.value));
break;
case ACPI_TYPE_STRING:
acpi_os_printf("(%u) \"%.24s",
obj_desc->string.length,
obj_desc->string.pointer);
if (obj_desc->string.length > 24) {
acpi_os_printf("...");
} else {
acpi_os_printf("\"");
}
break;
case ACPI_TYPE_BUFFER:
acpi_os_printf("(%u)", obj_desc->buffer.length);
for (i = 0; (i < 8) && (i < obj_desc->buffer.length); i++) {
acpi_os_printf(" %2.2X", obj_desc->buffer.pointer[i]);
}
break;
default:
acpi_os_printf(" %p", obj_desc);
break;
}
}
static void acpi_db_decode_node(struct acpi_namespace_node *node)
{
acpi_os_printf("<Node> Name %4.4s",
acpi_ut_get_node_name(node));
if (node->flags & ANOBJ_METHOD_ARG) {
acpi_os_printf(" [Method Arg]");
}
if (node->flags & ANOBJ_METHOD_LOCAL) {
acpi_os_printf(" [Method Local]");
}
switch (node->type) {
case ACPI_TYPE_DEVICE:
acpi_os_printf(" Device");
break;
case ACPI_TYPE_THERMAL:
acpi_os_printf(" Thermal Zone");
break;
default:
acpi_db_decode_internal_object(acpi_ns_get_attached_object
(node));
break;
}
}
void
acpi_db_display_internal_object(union acpi_operand_object *obj_desc,
struct acpi_walk_state *walk_state)
{
u8 type;
acpi_os_printf("%p ", obj_desc);
if (!obj_desc) {
acpi_os_printf("<Null Object>\n");
return;
}
switch (ACPI_GET_DESCRIPTOR_TYPE(obj_desc)) {
case ACPI_DESC_TYPE_PARSER:
acpi_os_printf("<Parser> ");
break;
case ACPI_DESC_TYPE_NAMED:
acpi_db_decode_node((struct acpi_namespace_node *)obj_desc);
break;
case ACPI_DESC_TYPE_OPERAND:
type = obj_desc->common.type;
if (type > ACPI_TYPE_LOCAL_MAX) {
acpi_os_printf(" Type %X [Invalid Type]", (u32)type);
return;
}
switch (obj_desc->common.type) {
case ACPI_TYPE_LOCAL_REFERENCE:
acpi_os_printf("[%s] ",
acpi_ut_get_reference_name(obj_desc));
switch (obj_desc->reference.class) {
case ACPI_REFCLASS_LOCAL:
acpi_os_printf("%X ",
obj_desc->reference.value);
if (walk_state) {
obj_desc = walk_state->local_variables
[obj_desc->reference.value].object;
acpi_os_printf("%p", obj_desc);
acpi_db_decode_internal_object
(obj_desc);
}
break;
case ACPI_REFCLASS_ARG:
acpi_os_printf("%X ",
obj_desc->reference.value);
if (walk_state) {
obj_desc = walk_state->arguments
[obj_desc->reference.value].object;
acpi_os_printf("%p", obj_desc);
acpi_db_decode_internal_object
(obj_desc);
}
break;
case ACPI_REFCLASS_INDEX:
switch (obj_desc->reference.target_type) {
case ACPI_TYPE_BUFFER_FIELD:
acpi_os_printf("%p",
obj_desc->reference.
object);
acpi_db_decode_internal_object
(obj_desc->reference.object);
break;
case ACPI_TYPE_PACKAGE:
acpi_os_printf("%p",
obj_desc->reference.
where);
if (!obj_desc->reference.where) {
acpi_os_printf
(" Uninitialized WHERE pointer");
} else {
acpi_db_decode_internal_object(*
(obj_desc->
reference.
where));
}
break;
default:
acpi_os_printf
("Unknown index target type");
break;
}
break;
case ACPI_REFCLASS_REFOF:
if (!obj_desc->reference.object) {
acpi_os_printf
("Uninitialized reference subobject pointer");
break;
}
switch (ACPI_GET_DESCRIPTOR_TYPE
(obj_desc->reference.object)) {
case ACPI_DESC_TYPE_NAMED:
acpi_db_decode_node(obj_desc->reference.
object);
break;
case ACPI_DESC_TYPE_OPERAND:
acpi_db_decode_internal_object
(obj_desc->reference.object);
break;
default:
break;
}
break;
case ACPI_REFCLASS_NAME:
acpi_db_decode_node(obj_desc->reference.node);
break;
case ACPI_REFCLASS_DEBUG:
case ACPI_REFCLASS_TABLE:
acpi_os_printf("\n");
break;
default:
acpi_os_printf("%2.2X\n",
obj_desc->reference.class);
break;
}
break;
default:
acpi_os_printf("<Obj> ");
acpi_db_decode_internal_object(obj_desc);
break;
}
break;
default:
acpi_os_printf("<Not a valid ACPI Object Descriptor> [%s]",
acpi_ut_get_descriptor_name(obj_desc));
break;
}
acpi_os_printf("\n");
}
void acpi_db_decode_locals(struct acpi_walk_state *walk_state)
{
u32 i;
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *node;
u8 display_locals = FALSE;
obj_desc = walk_state->method_desc;
node = walk_state->method_node;
if (!node) {
acpi_os_printf
("No method node (Executing subtree for buffer or opregion)\n");
return;
}
if (node->type != ACPI_TYPE_METHOD) {
acpi_os_printf("Executing subtree for Buffer/Package/Region\n");
return;
}
for (i = 0; i < ACPI_METHOD_NUM_LOCALS; i++) {
obj_desc = walk_state->local_variables[i].object;
if (obj_desc) {
display_locals = TRUE;
break;
}
}
if (display_locals) {
acpi_os_printf
("\nInitialized Local Variables for method [%4.4s]:\n",
acpi_ut_get_node_name(node));
for (i = 0; i < ACPI_METHOD_NUM_LOCALS; i++) {
obj_desc = walk_state->local_variables[i].object;
if (obj_desc) {
acpi_os_printf(" Local%X: ", i);
acpi_db_display_internal_object(obj_desc,
walk_state);
}
}
} else {
acpi_os_printf
("No Local Variables are initialized for method [%4.4s]\n",
acpi_ut_get_node_name(node));
}
}
void acpi_db_decode_arguments(struct acpi_walk_state *walk_state)
{
u32 i;
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *node;
u8 display_args = FALSE;
node = walk_state->method_node;
obj_desc = walk_state->method_desc;
if (!node) {
acpi_os_printf
("No method node (Executing subtree for buffer or opregion)\n");
return;
}
if (node->type != ACPI_TYPE_METHOD) {
acpi_os_printf("Executing subtree for Buffer/Package/Region\n");
return;
}
for (i = 0; i < ACPI_METHOD_NUM_ARGS; i++) {
obj_desc = walk_state->arguments[i].object;
if (obj_desc) {
display_args = TRUE;
break;
}
}
if (display_args) {
acpi_os_printf("Initialized Arguments for Method [%4.4s]: "
"(%X arguments defined for method invocation)\n",
acpi_ut_get_node_name(node),
obj_desc->method.param_count);
for (i = 0; i < ACPI_METHOD_NUM_ARGS; i++) {
obj_desc = walk_state->arguments[i].object;
if (obj_desc) {
acpi_os_printf(" Arg%u: ", i);
acpi_db_display_internal_object(obj_desc,
walk_state);
}
}
} else {
acpi_os_printf
("No Arguments are initialized for method [%4.4s]\n",
acpi_ut_get_node_name(node));
}
}
