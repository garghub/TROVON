static void *acpi_db_get_pointer(void *target)
{
void *obj_ptr;
acpi_size address;
address = strtoul(target, NULL, 16);
obj_ptr = ACPI_TO_POINTER(address);
return (obj_ptr);
}
static void acpi_db_dump_parser_descriptor(union acpi_parse_object *op)
{
const struct acpi_opcode_info *info;
info = acpi_ps_get_opcode_info(op->common.aml_opcode);
acpi_os_printf("Parser Op Descriptor:\n");
acpi_os_printf("%20.20s : %4.4X\n", "Opcode", op->common.aml_opcode);
ACPI_DEBUG_ONLY_MEMBERS(acpi_os_printf("%20.20s : %s\n", "Opcode Name",
info->name));
acpi_os_printf("%20.20s : %p\n", "Value/ArgList", op->common.value.arg);
acpi_os_printf("%20.20s : %p\n", "Parent", op->common.parent);
acpi_os_printf("%20.20s : %p\n", "NextOp", op->common.next);
}
void acpi_db_decode_and_display_object(char *target, char *output_type)
{
void *obj_ptr;
struct acpi_namespace_node *node;
union acpi_operand_object *obj_desc;
u32 display = DB_BYTE_DISPLAY;
char buffer[80];
struct acpi_buffer ret_buf;
acpi_status status;
u32 size;
if (!target) {
return;
}
if (output_type) {
acpi_ut_strupr(output_type);
if (output_type[0] == 'W') {
display = DB_WORD_DISPLAY;
} else if (output_type[0] == 'D') {
display = DB_DWORD_DISPLAY;
} else if (output_type[0] == 'Q') {
display = DB_QWORD_DISPLAY;
}
}
ret_buf.length = sizeof(buffer);
ret_buf.pointer = buffer;
if ((target[0] >= 0x30) && (target[0] <= 0x39)) {
obj_ptr = acpi_db_get_pointer(target);
if (!acpi_os_readable(obj_ptr, 16)) {
acpi_os_printf
("Address %p is invalid in this address space\n",
obj_ptr);
return;
}
switch (ACPI_GET_DESCRIPTOR_TYPE(obj_ptr)) {
case ACPI_DESC_TYPE_NAMED:
if (!acpi_os_readable
(obj_ptr, sizeof(struct acpi_namespace_node))) {
acpi_os_printf
("Cannot read entire Named object at address %p\n",
obj_ptr);
return;
}
node = obj_ptr;
goto dump_node;
case ACPI_DESC_TYPE_OPERAND:
if (!acpi_os_readable
(obj_ptr, sizeof(union acpi_operand_object))) {
acpi_os_printf
("Cannot read entire ACPI object at address %p\n",
obj_ptr);
return;
}
acpi_ut_debug_dump_buffer(obj_ptr,
sizeof(union
acpi_operand_object),
display, ACPI_UINT32_MAX);
acpi_ex_dump_object_descriptor(obj_ptr, 1);
break;
case ACPI_DESC_TYPE_PARSER:
if (!acpi_os_readable
(obj_ptr, sizeof(union acpi_parse_object))) {
acpi_os_printf
("Cannot read entire Parser object at address %p\n",
obj_ptr);
return;
}
acpi_ut_debug_dump_buffer(obj_ptr,
sizeof(union
acpi_parse_object),
display, ACPI_UINT32_MAX);
acpi_db_dump_parser_descriptor((union acpi_parse_object
*)obj_ptr);
break;
default:
acpi_os_printf
("Not a known ACPI internal object, descriptor type %2.2X\n",
ACPI_GET_DESCRIPTOR_TYPE(obj_ptr));
size = 16;
if (acpi_os_readable(obj_ptr, 64)) {
size = 64;
}
acpi_ut_debug_dump_buffer(obj_ptr, size, display,
ACPI_UINT32_MAX);
break;
}
return;
}
node = acpi_db_local_ns_lookup(target);
if (!node) {
return;
}
dump_node:
status = acpi_get_name(node, ACPI_FULL_PATHNAME_NO_TRAILING, &ret_buf);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not convert name to pathname\n");
}
else {
acpi_os_printf("Object (%p) Pathname: %s\n",
node, (char *)ret_buf.pointer);
}
if (!acpi_os_readable(node, sizeof(struct acpi_namespace_node))) {
acpi_os_printf("Invalid Named object at address %p\n", node);
return;
}
acpi_ut_debug_dump_buffer((void *)node,
sizeof(struct acpi_namespace_node), display,
ACPI_UINT32_MAX);
acpi_ex_dump_namespace_node(node, 1);
obj_desc = acpi_ns_get_attached_object(node);
if (obj_desc) {
acpi_os_printf("\nAttached Object (%p):\n", obj_desc);
if (!acpi_os_readable
(obj_desc, sizeof(union acpi_operand_object))) {
acpi_os_printf
("Invalid internal ACPI Object at address %p\n",
obj_desc);
return;
}
acpi_ut_debug_dump_buffer((void *)obj_desc,
sizeof(union acpi_operand_object),
display, ACPI_UINT32_MAX);
acpi_ex_dump_object_descriptor(obj_desc, 1);
}
}
void acpi_db_display_method_info(union acpi_parse_object *start_op)
{
struct acpi_walk_state *walk_state;
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *node;
union acpi_parse_object *root_op;
union acpi_parse_object *op;
const struct acpi_opcode_info *op_info;
u32 num_ops = 0;
u32 num_operands = 0;
u32 num_operators = 0;
u32 num_remaining_ops = 0;
u32 num_remaining_operands = 0;
u32 num_remaining_operators = 0;
u8 count_remaining = FALSE;
walk_state = acpi_ds_get_current_walk_state(acpi_gbl_current_walk_list);
if (!walk_state) {
acpi_os_printf("There is no method currently executing\n");
return;
}
obj_desc = walk_state->method_desc;
node = walk_state->method_node;
acpi_os_printf("Currently executing control method is [%4.4s]\n",
acpi_ut_get_node_name(node));
acpi_os_printf("%X Arguments, SyncLevel = %X\n",
(u32)obj_desc->method.param_count,
(u32)obj_desc->method.sync_level);
root_op = start_op;
while (root_op->common.parent) {
root_op = root_op->common.parent;
}
op = root_op;
while (op) {
if (op == start_op) {
count_remaining = TRUE;
}
num_ops++;
if (count_remaining) {
num_remaining_ops++;
}
op_info = acpi_ps_get_opcode_info(op->common.aml_opcode);
switch (op_info->class) {
case AML_CLASS_ARGUMENT:
if (count_remaining) {
num_remaining_operands++;
}
num_operands++;
break;
case AML_CLASS_UNKNOWN:
continue;
default:
if (count_remaining) {
num_remaining_operators++;
}
num_operators++;
break;
}
op = acpi_ps_get_depth_next(start_op, op);
}
acpi_os_printf
("Method contains: %X AML Opcodes - %X Operators, %X Operands\n",
num_ops, num_operators, num_operands);
acpi_os_printf
("Remaining to execute: %X AML Opcodes - %X Operators, %X Operands\n",
num_remaining_ops, num_remaining_operators,
num_remaining_operands);
}
void acpi_db_display_locals(void)
{
struct acpi_walk_state *walk_state;
walk_state = acpi_ds_get_current_walk_state(acpi_gbl_current_walk_list);
if (!walk_state) {
acpi_os_printf("There is no method currently executing\n");
return;
}
acpi_db_decode_locals(walk_state);
}
void acpi_db_display_arguments(void)
{
struct acpi_walk_state *walk_state;
walk_state = acpi_ds_get_current_walk_state(acpi_gbl_current_walk_list);
if (!walk_state) {
acpi_os_printf("There is no method currently executing\n");
return;
}
acpi_db_decode_arguments(walk_state);
}
void acpi_db_display_results(void)
{
u32 i;
struct acpi_walk_state *walk_state;
union acpi_operand_object *obj_desc;
u32 result_count = 0;
struct acpi_namespace_node *node;
union acpi_generic_state *frame;
u32 index;
walk_state = acpi_ds_get_current_walk_state(acpi_gbl_current_walk_list);
if (!walk_state) {
acpi_os_printf("There is no method currently executing\n");
return;
}
obj_desc = walk_state->method_desc;
node = walk_state->method_node;
if (walk_state->results) {
result_count = walk_state->result_count;
}
acpi_os_printf("Method [%4.4s] has %X stacked result objects\n",
acpi_ut_get_node_name(node), result_count);
frame = walk_state->results;
index = (result_count - 1) % ACPI_RESULTS_FRAME_OBJ_NUM;
for (i = 0; i < result_count; i++) {
obj_desc = frame->results.obj_desc[index];
acpi_os_printf("Result%u: ", i);
acpi_db_display_internal_object(obj_desc, walk_state);
if (index == 0) {
frame = frame->results.next;
index = ACPI_RESULTS_FRAME_OBJ_NUM;
}
index--;
}
}
void acpi_db_display_calling_tree(void)
{
struct acpi_walk_state *walk_state;
struct acpi_namespace_node *node;
walk_state = acpi_ds_get_current_walk_state(acpi_gbl_current_walk_list);
if (!walk_state) {
acpi_os_printf("There is no method currently executing\n");
return;
}
node = walk_state->method_node;
acpi_os_printf("Current Control Method Call Tree\n");
while (walk_state) {
node = walk_state->method_node;
acpi_os_printf(" [%4.4s]\n", acpi_ut_get_node_name(node));
walk_state = walk_state->next;
}
}
void acpi_db_display_object_type(char *name)
{
struct acpi_namespace_node *node;
struct acpi_device_info *info;
acpi_status status;
u32 i;
node = acpi_db_convert_to_node(name);
if (!node) {
return;
}
status = acpi_get_object_info(ACPI_CAST_PTR(acpi_handle, node), &info);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not get object info, %s\n",
acpi_format_exception(status));
return;
}
if (info->valid & ACPI_VALID_ADR) {
acpi_os_printf("ADR: %8.8X%8.8X, STA: %8.8X, Flags: %X\n",
ACPI_FORMAT_UINT64(info->address),
info->current_status, info->flags);
}
if (info->valid & ACPI_VALID_SXDS) {
acpi_os_printf("S1D-%2.2X S2D-%2.2X S3D-%2.2X S4D-%2.2X\n",
info->highest_dstates[0],
info->highest_dstates[1],
info->highest_dstates[2],
info->highest_dstates[3]);
}
if (info->valid & ACPI_VALID_SXWS) {
acpi_os_printf
("S0W-%2.2X S1W-%2.2X S2W-%2.2X S3W-%2.2X S4W-%2.2X\n",
info->lowest_dstates[0], info->lowest_dstates[1],
info->lowest_dstates[2], info->lowest_dstates[3],
info->lowest_dstates[4]);
}
if (info->valid & ACPI_VALID_HID) {
acpi_os_printf("HID: %s\n", info->hardware_id.string);
}
if (info->valid & ACPI_VALID_UID) {
acpi_os_printf("UID: %s\n", info->unique_id.string);
}
if (info->valid & ACPI_VALID_SUB) {
acpi_os_printf("SUB: %s\n", info->subsystem_id.string);
}
if (info->valid & ACPI_VALID_CID) {
for (i = 0; i < info->compatible_id_list.count; i++) {
acpi_os_printf("CID %u: %s\n", i,
info->compatible_id_list.ids[i].string);
}
}
ACPI_FREE(info);
}
void
acpi_db_display_result_object(union acpi_operand_object *obj_desc,
struct acpi_walk_state *walk_state)
{
if (!acpi_gbl_cm_single_step) {
return;
}
acpi_os_printf("ResultObj: ");
acpi_db_display_internal_object(obj_desc, walk_state);
acpi_os_printf("\n");
}
void
acpi_db_display_argument_object(union acpi_operand_object *obj_desc,
struct acpi_walk_state *walk_state)
{
if (!acpi_gbl_cm_single_step) {
return;
}
acpi_os_printf("ArgObj: ");
acpi_db_display_internal_object(obj_desc, walk_state);
}
void acpi_db_display_gpes(void)
{
struct acpi_gpe_block_info *gpe_block;
struct acpi_gpe_xrupt_info *gpe_xrupt_info;
struct acpi_gpe_event_info *gpe_event_info;
struct acpi_gpe_register_info *gpe_register_info;
char *gpe_type;
struct acpi_gpe_notify_info *notify;
u32 gpe_index;
u32 block = 0;
u32 i;
u32 j;
u32 count;
char buffer[80];
struct acpi_buffer ret_buf;
acpi_status status;
ret_buf.length = sizeof(buffer);
ret_buf.pointer = buffer;
block = 0;
gpe_xrupt_info = acpi_gbl_gpe_xrupt_list_head;
while (gpe_xrupt_info) {
gpe_block = gpe_xrupt_info->gpe_block_list_head;
while (gpe_block) {
status = acpi_get_name(gpe_block->node,
ACPI_FULL_PATHNAME_NO_TRAILING,
&ret_buf);
if (ACPI_FAILURE(status)) {
acpi_os_printf
("Could not convert name to pathname\n");
}
if (gpe_block->node == acpi_gbl_fadt_gpe_device) {
gpe_type = "FADT-defined GPE block";
} else {
gpe_type = "GPE Block Device";
}
acpi_os_printf
("\nBlock %u - Info %p DeviceNode %p [%s] - %s\n",
block, gpe_block, gpe_block->node, buffer,
gpe_type);
acpi_os_printf(" Registers: %u (%u GPEs)\n",
gpe_block->register_count,
gpe_block->gpe_count);
acpi_os_printf
(" GPE range: 0x%X to 0x%X on interrupt %u\n",
gpe_block->block_base_number,
gpe_block->block_base_number +
(gpe_block->gpe_count - 1),
gpe_xrupt_info->interrupt_number);
acpi_os_printf
(" RegisterInfo: %p Status %8.8X%8.8X Enable %8.8X%8.8X\n",
gpe_block->register_info,
ACPI_FORMAT_UINT64(gpe_block->register_info->
status_address.address),
ACPI_FORMAT_UINT64(gpe_block->register_info->
enable_address.address));
acpi_os_printf(" EventInfo: %p\n",
gpe_block->event_info);
for (i = 0; i < gpe_block->register_count; i++) {
gpe_register_info =
&gpe_block->register_info[i];
acpi_os_printf(" Reg %u: (GPE %.2X-%.2X) "
"RunEnable %2.2X WakeEnable %2.2X"
" Status %8.8X%8.8X Enable %8.8X%8.8X\n",
i,
gpe_register_info->
base_gpe_number,
gpe_register_info->
base_gpe_number +
(ACPI_GPE_REGISTER_WIDTH - 1),
gpe_register_info->
enable_for_run,
gpe_register_info->
enable_for_wake,
ACPI_FORMAT_UINT64
(gpe_register_info->
status_address.address),
ACPI_FORMAT_UINT64
(gpe_register_info->
enable_address.address));
for (j = 0; j < ACPI_GPE_REGISTER_WIDTH; j++) {
gpe_index =
(i * ACPI_GPE_REGISTER_WIDTH) + j;
gpe_event_info =
&gpe_block->event_info[gpe_index];
if (ACPI_GPE_DISPATCH_TYPE
(gpe_event_info->flags) ==
ACPI_GPE_DISPATCH_NONE) {
continue;
}
acpi_os_printf
(" GPE %.2X: %p RunRefs %2.2X Flags %2.2X (",
gpe_block->block_base_number +
gpe_index, gpe_event_info,
gpe_event_info->runtime_count,
gpe_event_info->flags);
if (gpe_event_info->
flags & ACPI_GPE_LEVEL_TRIGGERED) {
acpi_os_printf("Level, ");
} else {
acpi_os_printf("Edge, ");
}
if (gpe_event_info->
flags & ACPI_GPE_CAN_WAKE) {
acpi_os_printf("CanWake, ");
} else {
acpi_os_printf("RunOnly, ");
}
switch (ACPI_GPE_DISPATCH_TYPE
(gpe_event_info->flags)) {
case ACPI_GPE_DISPATCH_NONE:
acpi_os_printf("NotUsed");
break;
case ACPI_GPE_DISPATCH_METHOD:
acpi_os_printf("Method");
break;
case ACPI_GPE_DISPATCH_HANDLER:
acpi_os_printf("Handler");
break;
case ACPI_GPE_DISPATCH_NOTIFY:
count = 0;
notify =
gpe_event_info->dispatch.
notify_list;
while (notify) {
count++;
notify = notify->next;
}
acpi_os_printf
("Implicit Notify on %u devices",
count);
break;
case ACPI_GPE_DISPATCH_RAW_HANDLER:
acpi_os_printf("RawHandler");
break;
default:
acpi_os_printf("UNKNOWN: %X",
ACPI_GPE_DISPATCH_TYPE
(gpe_event_info->
flags));
break;
}
acpi_os_printf(")\n");
}
}
block++;
gpe_block = gpe_block->next;
}
gpe_xrupt_info = gpe_xrupt_info->next;
}
}
void acpi_db_display_handlers(void)
{
union acpi_operand_object *obj_desc;
union acpi_operand_object *handler_obj;
acpi_adr_space_type space_id;
u32 i;
acpi_os_printf("\nOperation Region Handlers at the namespace root:\n");
obj_desc = acpi_ns_get_attached_object(acpi_gbl_root_node);
if (obj_desc) {
for (i = 0; i < ACPI_ARRAY_LENGTH(acpi_gbl_space_id_list); i++) {
space_id = acpi_gbl_space_id_list[i];
handler_obj = obj_desc->device.handler;
acpi_os_printf(ACPI_PREDEFINED_PREFIX,
acpi_ut_get_region_name((u8)space_id),
space_id);
while (handler_obj) {
if (acpi_gbl_space_id_list[i] ==
handler_obj->address_space.space_id) {
acpi_os_printf
(ACPI_HANDLER_PRESENT_STRING,
(handler_obj->address_space.
handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED)
? "Default" : "User",
handler_obj->address_space.
handler);
goto found_handler;
}
handler_obj = handler_obj->address_space.next;
}
acpi_os_printf("None\n");
found_handler: ;
}
handler_obj = obj_desc->device.handler;
while (handler_obj) {
if (handler_obj->address_space.space_id >=
ACPI_USER_REGION_BEGIN) {
acpi_os_printf(ACPI_PREDEFINED_PREFIX,
"User-defined ID",
handler_obj->address_space.
space_id);
acpi_os_printf(ACPI_HANDLER_PRESENT_STRING,
(handler_obj->address_space.
handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED)
? "Default" : "User",
handler_obj->address_space.
handler);
}
handler_obj = handler_obj->address_space.next;
}
}
#if (!ACPI_REDUCED_HARDWARE)
acpi_os_printf("\nFixed Event Handlers:\n");
for (i = 0; i < ACPI_NUM_FIXED_EVENTS; i++) {
acpi_os_printf(ACPI_PREDEFINED_PREFIX,
acpi_ut_get_event_name(i), i);
if (acpi_gbl_fixed_event_handlers[i].handler) {
acpi_os_printf(ACPI_HANDLER_PRESENT_STRING, "User",
acpi_gbl_fixed_event_handlers[i].
handler);
} else {
acpi_os_printf(ACPI_HANDLER_NOT_PRESENT_STRING, "None");
}
}
#endif
acpi_os_printf("\nMiscellaneous Global Handlers:\n");
for (i = 0; i < ACPI_ARRAY_LENGTH(acpi_gbl_handler_list); i++) {
acpi_os_printf(ACPI_HANDLER_NAME_STRING,
acpi_gbl_handler_list[i].name);
if (acpi_gbl_handler_list[i].handler) {
acpi_os_printf(ACPI_HANDLER_PRESENT_STRING, "User",
acpi_gbl_handler_list[i].handler);
} else {
acpi_os_printf(ACPI_HANDLER_NOT_PRESENT_STRING, "None");
}
}
acpi_os_printf("\nOperation Region Handlers for specific devices:\n");
(void)acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_db_display_non_root_handlers, NULL, NULL,
NULL);
}
static acpi_status
acpi_db_display_non_root_handlers(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
struct acpi_namespace_node *node =
ACPI_CAST_PTR(struct acpi_namespace_node, obj_handle);
union acpi_operand_object *obj_desc;
union acpi_operand_object *handler_obj;
char *pathname;
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
return (AE_OK);
}
pathname = acpi_ns_get_external_pathname(node);
if (!pathname) {
return (AE_OK);
}
handler_obj = obj_desc->device.handler;
while (handler_obj) {
acpi_os_printf(ACPI_PREDEFINED_PREFIX,
acpi_ut_get_region_name((u8)handler_obj->
address_space.space_id),
handler_obj->address_space.space_id);
acpi_os_printf(ACPI_HANDLER_PRESENT_STRING2,
(handler_obj->address_space.handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED) ? "Default"
: "User", handler_obj->address_space.handler);
acpi_os_printf(" Device Name: %s (%p)\n", pathname, node);
handler_obj = handler_obj->address_space.next;
}
ACPI_FREE(pathname);
return (AE_OK);
}
