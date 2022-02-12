acpi_status acpi_ev_install_region_handlers(void)
{
acpi_status status;
u32 i;
ACPI_FUNCTION_TRACE(ev_install_region_handlers);
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
for (i = 0; i < ACPI_NUM_DEFAULT_SPACES; i++) {
status = acpi_ev_install_space_handler(acpi_gbl_root_node,
acpi_gbl_default_address_spaces
[i],
ACPI_DEFAULT_HANDLER,
NULL, NULL);
switch (status) {
case AE_OK:
case AE_SAME_HANDLER:
case AE_ALREADY_EXISTS:
status = AE_OK;
break;
default:
goto unlock_and_exit;
}
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return_ACPI_STATUS(status);
}
u8
acpi_ev_has_default_handler(struct acpi_namespace_node *node,
acpi_adr_space_type space_id)
{
union acpi_operand_object *obj_desc;
union acpi_operand_object *handler_obj;
obj_desc = acpi_ns_get_attached_object(node);
if (obj_desc) {
handler_obj = obj_desc->device.handler;
while (handler_obj) {
if (handler_obj->address_space.space_id == space_id) {
if (handler_obj->address_space.handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED) {
return (TRUE);
}
}
handler_obj = handler_obj->address_space.next;
}
}
return (FALSE);
}
static acpi_status
acpi_ev_install_handler(acpi_handle obj_handle,
u32 level, void *context, void **return_value)
{
union acpi_operand_object *handler_obj;
union acpi_operand_object *next_handler_obj;
union acpi_operand_object *obj_desc;
struct acpi_namespace_node *node;
acpi_status status;
ACPI_FUNCTION_NAME(ev_install_handler);
handler_obj = (union acpi_operand_object *)context;
if (!handler_obj) {
return (AE_OK);
}
node = acpi_ns_validate_handle(obj_handle);
if (!node) {
return (AE_BAD_PARAMETER);
}
if ((node->type != ACPI_TYPE_DEVICE) &&
(node->type != ACPI_TYPE_REGION) && (node != acpi_gbl_root_node)) {
return (AE_OK);
}
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
return (AE_OK);
}
if (obj_desc->common.type == ACPI_TYPE_DEVICE) {
next_handler_obj = obj_desc->device.handler;
while (next_handler_obj) {
if (next_handler_obj->address_space.space_id ==
handler_obj->address_space.space_id) {
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Found handler for region [%s] in device %p(%p) "
"handler %p\n",
acpi_ut_get_region_name
(handler_obj->address_space.
space_id), obj_desc,
next_handler_obj,
handler_obj));
return (AE_CTRL_DEPTH);
}
next_handler_obj = next_handler_obj->address_space.next;
}
return (AE_OK);
}
if (obj_desc->region.space_id != handler_obj->address_space.space_id) {
return (AE_OK);
}
acpi_ev_detach_region(obj_desc, FALSE);
status = acpi_ev_attach_region(handler_obj, obj_desc, FALSE);
return (status);
}
acpi_status
acpi_ev_install_space_handler(struct acpi_namespace_node * node,
acpi_adr_space_type space_id,
acpi_adr_space_handler handler,
acpi_adr_space_setup setup, void *context)
{
union acpi_operand_object *obj_desc;
union acpi_operand_object *handler_obj;
acpi_status status;
acpi_object_type type;
u8 flags = 0;
ACPI_FUNCTION_TRACE(ev_install_space_handler);
if ((node->type != ACPI_TYPE_DEVICE) &&
(node->type != ACPI_TYPE_PROCESSOR) &&
(node->type != ACPI_TYPE_THERMAL) && (node != acpi_gbl_root_node)) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
if (handler == ACPI_DEFAULT_HANDLER) {
flags = ACPI_ADDR_HANDLER_DEFAULT_INSTALLED;
switch (space_id) {
case ACPI_ADR_SPACE_SYSTEM_MEMORY:
handler = acpi_ex_system_memory_space_handler;
setup = acpi_ev_system_memory_region_setup;
break;
case ACPI_ADR_SPACE_SYSTEM_IO:
handler = acpi_ex_system_io_space_handler;
setup = acpi_ev_io_space_region_setup;
break;
case ACPI_ADR_SPACE_PCI_CONFIG:
handler = acpi_ex_pci_config_space_handler;
setup = acpi_ev_pci_config_region_setup;
break;
case ACPI_ADR_SPACE_CMOS:
handler = acpi_ex_cmos_space_handler;
setup = acpi_ev_cmos_region_setup;
break;
case ACPI_ADR_SPACE_PCI_BAR_TARGET:
handler = acpi_ex_pci_bar_space_handler;
setup = acpi_ev_pci_bar_region_setup;
break;
case ACPI_ADR_SPACE_DATA_TABLE:
handler = acpi_ex_data_table_space_handler;
setup = NULL;
break;
default:
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
}
if (!setup) {
setup = acpi_ev_default_region_setup;
}
obj_desc = acpi_ns_get_attached_object(node);
if (obj_desc) {
handler_obj = obj_desc->device.handler;
while (handler_obj) {
if (handler_obj->address_space.space_id == space_id) {
if (handler_obj->address_space.handler ==
handler) {
status = AE_SAME_HANDLER;
goto unlock_and_exit;
} else {
status = AE_ALREADY_EXISTS;
}
goto unlock_and_exit;
}
handler_obj = handler_obj->address_space.next;
}
} else {
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Creating object on Device %p while installing handler\n",
node));
if (node->type == ACPI_TYPE_ANY) {
type = ACPI_TYPE_DEVICE;
} else {
type = node->type;
}
obj_desc = acpi_ut_create_internal_object(type);
if (!obj_desc) {
status = AE_NO_MEMORY;
goto unlock_and_exit;
}
obj_desc->common.type = (u8)type;
status = acpi_ns_attach_object(node, obj_desc, type);
acpi_ut_remove_reference(obj_desc);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
}
ACPI_DEBUG_PRINT((ACPI_DB_OPREGION,
"Installing address handler for region %s(%X) on Device %4.4s %p(%p)\n",
acpi_ut_get_region_name(space_id), space_id,
acpi_ut_get_node_name(node), node, obj_desc));
handler_obj =
acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_ADDRESS_HANDLER);
if (!handler_obj) {
status = AE_NO_MEMORY;
goto unlock_and_exit;
}
handler_obj->address_space.space_id = (u8)space_id;
handler_obj->address_space.handler_flags = flags;
handler_obj->address_space.region_list = NULL;
handler_obj->address_space.node = node;
handler_obj->address_space.handler = handler;
handler_obj->address_space.context = context;
handler_obj->address_space.setup = setup;
handler_obj->address_space.next = obj_desc->device.handler;
obj_desc->device.handler = handler_obj;
status = acpi_ns_walk_namespace(ACPI_TYPE_ANY, node, ACPI_UINT32_MAX,
ACPI_NS_WALK_UNLOCK,
acpi_ev_install_handler, NULL,
handler_obj, NULL);
unlock_and_exit:
return_ACPI_STATUS(status);
}
