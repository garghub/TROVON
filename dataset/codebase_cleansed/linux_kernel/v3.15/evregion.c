acpi_status acpi_ev_initialize_op_regions(void)
{
acpi_status status;
u32 i;
ACPI_FUNCTION_TRACE(ev_initialize_op_regions);
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
for (i = 0; i < ACPI_NUM_DEFAULT_SPACES; i++) {
if (acpi_ev_has_default_handler(acpi_gbl_root_node,
acpi_gbl_default_address_spaces
[i])) {
status =
acpi_ev_execute_reg_methods(acpi_gbl_root_node,
acpi_gbl_default_address_spaces
[i]);
}
}
acpi_gbl_reg_methods_executed = TRUE;
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ev_address_space_dispatch(union acpi_operand_object *region_obj,
union acpi_operand_object *field_obj,
u32 function,
u32 region_offset, u32 bit_width, u64 *value)
{
acpi_status status;
acpi_adr_space_handler handler;
acpi_adr_space_setup region_setup;
union acpi_operand_object *handler_desc;
union acpi_operand_object *region_obj2;
void *region_context = NULL;
struct acpi_connection_info *context;
ACPI_FUNCTION_TRACE(ev_address_space_dispatch);
region_obj2 = acpi_ns_get_secondary_object(region_obj);
if (!region_obj2) {
return_ACPI_STATUS(AE_NOT_EXIST);
}
handler_desc = region_obj->region.handler;
if (!handler_desc) {
ACPI_ERROR((AE_INFO,
"No handler for Region [%4.4s] (%p) [%s]",
acpi_ut_get_node_name(region_obj->region.node),
region_obj,
acpi_ut_get_region_name(region_obj->region.
space_id)));
return_ACPI_STATUS(AE_NOT_EXIST);
}
context = handler_desc->address_space.context;
if (!(region_obj->region.flags & AOPOBJ_SETUP_COMPLETE)) {
region_setup = handler_desc->address_space.setup;
if (!region_setup) {
ACPI_ERROR((AE_INFO,
"No init routine for region(%p) [%s]",
region_obj,
acpi_ut_get_region_name(region_obj->region.
space_id)));
return_ACPI_STATUS(AE_NOT_EXIST);
}
acpi_ex_exit_interpreter();
status = region_setup(region_obj, ACPI_REGION_ACTIVATE,
context, &region_context);
acpi_ex_enter_interpreter();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During region initialization: [%s]",
acpi_ut_get_region_name(region_obj->
region.
space_id)));
return_ACPI_STATUS(status);
}
if (!(region_obj->region.flags & AOPOBJ_SETUP_COMPLETE)) {
region_obj->region.flags |= AOPOBJ_SETUP_COMPLETE;
if (!(region_obj2->extra.region_context)) {
region_obj2->extra.region_context =
region_context;
}
}
}
handler = handler_desc->address_space.handler;
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Handler %p (@%p) Address %8.8X%8.8X [%s]\n",
&region_obj->region.handler->address_space, handler,
ACPI_FORMAT_NATIVE_UINT(region_obj->region.address +
region_offset),
acpi_ut_get_region_name(region_obj->region.
space_id)));
if (((region_obj->region.space_id == ACPI_ADR_SPACE_GSBUS) ||
(region_obj->region.space_id == ACPI_ADR_SPACE_GPIO)) &&
context && field_obj) {
context->connection = field_obj->field.resource_buffer;
context->length = field_obj->field.resource_length;
context->access_length = field_obj->field.access_length;
}
if (!(handler_desc->address_space.handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED)) {
acpi_ex_exit_interpreter();
}
status = handler(function,
(region_obj->region.address + region_offset),
bit_width, value, context,
region_obj2->extra.region_context);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Returned by Handler for [%s]",
acpi_ut_get_region_name(region_obj->region.
space_id)));
}
if (!(handler_desc->address_space.handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED)) {
acpi_ex_enter_interpreter();
}
return_ACPI_STATUS(status);
}
void
acpi_ev_detach_region(union acpi_operand_object *region_obj,
u8 acpi_ns_is_locked)
{
union acpi_operand_object *handler_obj;
union acpi_operand_object *obj_desc;
union acpi_operand_object *start_desc;
union acpi_operand_object **last_obj_ptr;
acpi_adr_space_setup region_setup;
void **region_context;
union acpi_operand_object *region_obj2;
acpi_status status;
ACPI_FUNCTION_TRACE(ev_detach_region);
region_obj2 = acpi_ns_get_secondary_object(region_obj);
if (!region_obj2) {
return_VOID;
}
region_context = &region_obj2->extra.region_context;
handler_obj = region_obj->region.handler;
if (!handler_obj) {
return_VOID;
}
obj_desc = handler_obj->address_space.region_list;
start_desc = obj_desc;
last_obj_ptr = &handler_obj->address_space.region_list;
while (obj_desc) {
if (obj_desc == region_obj) {
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Removing Region %p from address handler %p\n",
region_obj, handler_obj));
*last_obj_ptr = obj_desc->region.next;
obj_desc->region.next = NULL;
if (acpi_ns_is_locked) {
status =
acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_VOID;
}
}
status =
acpi_ev_execute_reg_method(region_obj,
ACPI_REG_DISCONNECT);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"from region _REG, [%s]",
acpi_ut_get_region_name
(region_obj->region.space_id)));
}
if (acpi_ns_is_locked) {
status =
acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_VOID;
}
}
if (region_obj->region.flags & AOPOBJ_SETUP_COMPLETE) {
region_setup = handler_obj->address_space.setup;
status =
region_setup(region_obj,
ACPI_REGION_DEACTIVATE,
handler_obj->address_space.
context, region_context);
if (region_context) {
*region_context = NULL;
}
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"from region handler - deactivate, [%s]",
acpi_ut_get_region_name
(region_obj->region.
space_id)));
}
region_obj->region.flags &=
~(AOPOBJ_SETUP_COMPLETE);
}
region_obj->region.handler = NULL;
acpi_ut_remove_reference(handler_obj);
return_VOID;
}
last_obj_ptr = &obj_desc->region.next;
obj_desc = obj_desc->region.next;
if (obj_desc == start_desc) {
ACPI_ERROR((AE_INFO,
"Circular handler list in region object %p",
region_obj));
return_VOID;
}
}
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Cannot remove region %p from address handler %p\n",
region_obj, handler_obj));
return_VOID;
}
acpi_status
acpi_ev_attach_region(union acpi_operand_object *handler_obj,
union acpi_operand_object *region_obj,
u8 acpi_ns_is_locked)
{
ACPI_FUNCTION_TRACE(ev_attach_region);
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Adding Region [%4.4s] %p to address handler %p [%s]\n",
acpi_ut_get_node_name(region_obj->region.node),
region_obj, handler_obj,
acpi_ut_get_region_name(region_obj->region.
space_id)));
region_obj->region.next = handler_obj->address_space.region_list;
handler_obj->address_space.region_list = region_obj;
if (region_obj->region.handler) {
return_ACPI_STATUS(AE_ALREADY_EXISTS);
}
region_obj->region.handler = handler_obj;
acpi_ut_add_reference(handler_obj);
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ev_execute_reg_method(union acpi_operand_object *region_obj, u32 function)
{
struct acpi_evaluate_info *info;
union acpi_operand_object *args[3];
union acpi_operand_object *region_obj2;
acpi_status status;
ACPI_FUNCTION_TRACE(ev_execute_reg_method);
region_obj2 = acpi_ns_get_secondary_object(region_obj);
if (!region_obj2) {
return_ACPI_STATUS(AE_NOT_EXIST);
}
if (region_obj2->extra.method_REG == NULL) {
return_ACPI_STATUS(AE_OK);
}
info = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_evaluate_info));
if (!info) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
info->prefix_node = region_obj2->extra.method_REG;
info->relative_pathname = NULL;
info->parameters = args;
info->flags = ACPI_IGNORE_RETURN_VALUE;
args[0] =
acpi_ut_create_integer_object((u64)region_obj->region.space_id);
if (!args[0]) {
status = AE_NO_MEMORY;
goto cleanup1;
}
args[1] = acpi_ut_create_integer_object((u64)function);
if (!args[1]) {
status = AE_NO_MEMORY;
goto cleanup2;
}
args[2] = NULL;
ACPI_DEBUG_EXEC(acpi_ut_display_init_pathname
(ACPI_TYPE_METHOD, info->prefix_node, NULL));
status = acpi_ns_evaluate(info);
acpi_ut_remove_reference(args[1]);
cleanup2:
acpi_ut_remove_reference(args[0]);
cleanup1:
ACPI_FREE(info);
return_ACPI_STATUS(status);
}
acpi_status
acpi_ev_execute_reg_methods(struct acpi_namespace_node *node,
acpi_adr_space_type space_id)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ev_execute_reg_methods);
status = acpi_ns_walk_namespace(ACPI_TYPE_ANY, node, ACPI_UINT32_MAX,
ACPI_NS_WALK_UNLOCK, acpi_ev_reg_run,
NULL, &space_id, NULL);
if (space_id == ACPI_ADR_SPACE_EC) {
acpi_ev_orphan_ec_reg_method(node);
}
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ev_reg_run(acpi_handle obj_handle,
u32 level, void *context, void **return_value)
{
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *node;
acpi_adr_space_type space_id;
acpi_status status;
space_id = *ACPI_CAST_PTR(acpi_adr_space_type, context);
node = acpi_ns_validate_handle(obj_handle);
if (!node) {
return (AE_BAD_PARAMETER);
}
if ((node->type != ACPI_TYPE_REGION) && (node != acpi_gbl_root_node)) {
return (AE_OK);
}
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
return (AE_OK);
}
if (obj_desc->region.space_id != space_id) {
return (AE_OK);
}
status = acpi_ev_execute_reg_method(obj_desc, ACPI_REG_CONNECT);
return (status);
}
static void
acpi_ev_orphan_ec_reg_method(struct acpi_namespace_node *ec_device_node)
{
acpi_handle reg_method;
struct acpi_namespace_node *next_node;
acpi_status status;
struct acpi_object_list args;
union acpi_object objects[2];
ACPI_FUNCTION_TRACE(ev_orphan_ec_reg_method);
if (!ec_device_node) {
return_VOID;
}
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
status = acpi_get_handle(ec_device_node, METHOD_NAME__REG, &reg_method);
if (ACPI_FAILURE(status)) {
goto exit;
}
next_node = acpi_ns_get_next_node(ec_device_node, NULL);
while (next_node) {
if ((next_node->type == ACPI_TYPE_REGION) &&
(next_node->object) &&
(next_node->object->region.space_id == ACPI_ADR_SPACE_EC)) {
goto exit;
}
next_node = acpi_ns_get_next_node(ec_device_node, next_node);
}
args.count = 2;
args.pointer = objects;
objects[0].type = ACPI_TYPE_INTEGER;
objects[0].integer.value = ACPI_ADR_SPACE_EC;
objects[1].type = ACPI_TYPE_INTEGER;
objects[1].integer.value = ACPI_REG_CONNECT;
status = acpi_evaluate_object(reg_method, NULL, &args, NULL);
exit:
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
return_VOID;
}
