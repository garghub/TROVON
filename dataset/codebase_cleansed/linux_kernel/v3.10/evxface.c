acpi_status
acpi_install_notify_handler(acpi_handle device,
u32 handler_type,
acpi_notify_handler handler, void *context)
{
struct acpi_namespace_node *node =
ACPI_CAST_PTR(struct acpi_namespace_node, device);
union acpi_operand_object *obj_desc;
union acpi_operand_object *handler_obj;
acpi_status status;
u32 i;
ACPI_FUNCTION_TRACE(acpi_install_notify_handler);
if ((!device) || (!handler) || (!handler_type) ||
(handler_type > ACPI_MAX_NOTIFY_HANDLER_TYPE)) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (device == ACPI_ROOT_OBJECT) {
for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
if (handler_type & (i + 1)) {
if (acpi_gbl_global_notify[i].handler) {
status = AE_ALREADY_EXISTS;
goto unlock_and_exit;
}
acpi_gbl_global_notify[i].handler = handler;
acpi_gbl_global_notify[i].context = context;
}
}
goto unlock_and_exit;
}
if (!acpi_ev_is_notify_object(node)) {
status = AE_TYPE;
goto unlock_and_exit;
}
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
obj_desc = acpi_ut_create_internal_object(node->type);
if (!obj_desc) {
status = AE_NO_MEMORY;
goto unlock_and_exit;
}
status = acpi_ns_attach_object(device, obj_desc, node->type);
acpi_ut_remove_reference(obj_desc);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
}
for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
if (handler_type & (i + 1)) {
handler_obj = obj_desc->common_notify.notify_list[i];
while (handler_obj) {
if (handler_obj->notify.handler == handler) {
status = AE_ALREADY_EXISTS;
goto unlock_and_exit;
}
handler_obj = handler_obj->notify.next[i];
}
}
}
handler_obj = acpi_ut_create_internal_object(ACPI_TYPE_LOCAL_NOTIFY);
if (!handler_obj) {
status = AE_NO_MEMORY;
goto unlock_and_exit;
}
handler_obj->notify.node = node;
handler_obj->notify.handler_type = handler_type;
handler_obj->notify.handler = handler;
handler_obj->notify.context = context;
for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
if (handler_type & (i + 1)) {
handler_obj->notify.next[i] =
obj_desc->common_notify.notify_list[i];
obj_desc->common_notify.notify_list[i] = handler_obj;
}
}
if (handler_type == ACPI_ALL_NOTIFY) {
acpi_ut_add_reference(handler_obj);
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return_ACPI_STATUS(status);
}
acpi_status
acpi_remove_notify_handler(acpi_handle device,
u32 handler_type, acpi_notify_handler handler)
{
struct acpi_namespace_node *node =
ACPI_CAST_PTR(struct acpi_namespace_node, device);
union acpi_operand_object *obj_desc;
union acpi_operand_object *handler_obj;
union acpi_operand_object *previous_handler_obj;
acpi_status status;
u32 i;
ACPI_FUNCTION_TRACE(acpi_remove_notify_handler);
if ((!device) || (!handler) || (!handler_type) ||
(handler_type > ACPI_MAX_NOTIFY_HANDLER_TYPE)) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
acpi_os_wait_events_complete();
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (device == ACPI_ROOT_OBJECT) {
for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
if (handler_type & (i + 1)) {
if (!acpi_gbl_global_notify[i].handler ||
(acpi_gbl_global_notify[i].handler !=
handler)) {
status = AE_NOT_EXIST;
goto unlock_and_exit;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Removing global notify handler\n"));
acpi_gbl_global_notify[i].handler = NULL;
acpi_gbl_global_notify[i].context = NULL;
}
}
goto unlock_and_exit;
}
if (!acpi_ev_is_notify_object(node)) {
status = AE_TYPE;
goto unlock_and_exit;
}
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
status = AE_NOT_EXIST;
goto unlock_and_exit;
}
for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
if (handler_type & (i + 1)) {
handler_obj = obj_desc->common_notify.notify_list[i];
previous_handler_obj = NULL;
while (handler_obj &&
(handler_obj->notify.handler != handler)) {
previous_handler_obj = handler_obj;
handler_obj = handler_obj->notify.next[i];
}
if (!handler_obj) {
status = AE_NOT_EXIST;
goto unlock_and_exit;
}
if (previous_handler_obj) {
previous_handler_obj->notify.next[i] =
handler_obj->notify.next[i];
} else {
obj_desc->common_notify.notify_list[i] =
handler_obj->notify.next[i];
}
acpi_ut_remove_reference(handler_obj);
}
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return_ACPI_STATUS(status);
}
acpi_status acpi_install_exception_handler(acpi_exception_handler handler)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_install_exception_handler);
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (acpi_gbl_exception_handler) {
status = AE_ALREADY_EXISTS;
goto cleanup;
}
acpi_gbl_exception_handler = handler;
cleanup:
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
acpi_status
acpi_install_global_event_handler(acpi_gbl_event_handler handler, void *context)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_install_global_event_handler);
if (!handler) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (acpi_gbl_global_event_handler) {
status = AE_ALREADY_EXISTS;
goto cleanup;
}
acpi_gbl_global_event_handler = handler;
acpi_gbl_global_event_handler_context = context;
cleanup:
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
acpi_status
acpi_install_fixed_event_handler(u32 event,
acpi_event_handler handler, void *context)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_install_fixed_event_handler);
if (event > ACPI_EVENT_MAX) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (acpi_gbl_fixed_event_handlers[event].handler) {
status = AE_ALREADY_EXISTS;
goto cleanup;
}
acpi_gbl_fixed_event_handlers[event].handler = handler;
acpi_gbl_fixed_event_handlers[event].context = context;
status = acpi_clear_event(event);
if (ACPI_SUCCESS(status))
status = acpi_enable_event(event, 0);
if (ACPI_FAILURE(status)) {
ACPI_WARNING((AE_INFO,
"Could not enable fixed event - %s (%u)",
acpi_ut_get_event_name(event), event));
acpi_gbl_fixed_event_handlers[event].handler = NULL;
acpi_gbl_fixed_event_handlers[event].context = NULL;
} else {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Enabled fixed event %s (%X), Handler=%p\n",
acpi_ut_get_event_name(event), event,
handler));
}
cleanup:
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
acpi_status
acpi_remove_fixed_event_handler(u32 event, acpi_event_handler handler)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(acpi_remove_fixed_event_handler);
if (event > ACPI_EVENT_MAX) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_disable_event(event, 0);
acpi_gbl_fixed_event_handlers[event].handler = NULL;
acpi_gbl_fixed_event_handlers[event].context = NULL;
if (ACPI_FAILURE(status)) {
ACPI_WARNING((AE_INFO,
"Could not disable fixed event - %s (%u)",
acpi_ut_get_event_name(event), event));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Disabled fixed event - %s (%X)\n",
acpi_ut_get_event_name(event), event));
}
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
acpi_status
acpi_install_gpe_handler(acpi_handle gpe_device,
u32 gpe_number,
u32 type, acpi_gpe_handler address, void *context)
{
struct acpi_gpe_event_info *gpe_event_info;
struct acpi_gpe_handler_info *handler;
acpi_status status;
acpi_cpu_flags flags;
ACPI_FUNCTION_TRACE(acpi_install_gpe_handler);
if ((!address) || (type & ~ACPI_GPE_XRUPT_TYPE_MASK)) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
handler = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_gpe_handler_info));
if (!handler) {
status = AE_NO_MEMORY;
goto unlock_and_exit;
}
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
gpe_event_info = acpi_ev_get_gpe_event_info(gpe_device, gpe_number);
if (!gpe_event_info) {
status = AE_BAD_PARAMETER;
goto free_and_exit;
}
if ((gpe_event_info->flags & ACPI_GPE_DISPATCH_MASK) ==
ACPI_GPE_DISPATCH_HANDLER) {
status = AE_ALREADY_EXISTS;
goto free_and_exit;
}
handler->address = address;
handler->context = context;
handler->method_node = gpe_event_info->dispatch.method_node;
handler->original_flags = (u8)(gpe_event_info->flags &
(ACPI_GPE_XRUPT_TYPE_MASK |
ACPI_GPE_DISPATCH_MASK));
if ((handler->original_flags & ACPI_GPE_DISPATCH_METHOD)
&& gpe_event_info->runtime_count) {
handler->originally_enabled = 1;
(void)acpi_ev_remove_gpe_reference(gpe_event_info);
}
gpe_event_info->dispatch.handler = handler;
gpe_event_info->flags &=
~(ACPI_GPE_XRUPT_TYPE_MASK | ACPI_GPE_DISPATCH_MASK);
gpe_event_info->flags |= (u8) (type | ACPI_GPE_DISPATCH_HANDLER);
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
free_and_exit:
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
ACPI_FREE(handler);
goto unlock_and_exit;
}
acpi_status
acpi_remove_gpe_handler(acpi_handle gpe_device,
u32 gpe_number, acpi_gpe_handler address)
{
struct acpi_gpe_event_info *gpe_event_info;
struct acpi_gpe_handler_info *handler;
acpi_status status;
acpi_cpu_flags flags;
ACPI_FUNCTION_TRACE(acpi_remove_gpe_handler);
if (!address) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
acpi_os_wait_events_complete();
status = acpi_ut_acquire_mutex(ACPI_MTX_EVENTS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
gpe_event_info = acpi_ev_get_gpe_event_info(gpe_device, gpe_number);
if (!gpe_event_info) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
if ((gpe_event_info->flags & ACPI_GPE_DISPATCH_MASK) !=
ACPI_GPE_DISPATCH_HANDLER) {
status = AE_NOT_EXIST;
goto unlock_and_exit;
}
if (gpe_event_info->dispatch.handler->address != address) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
handler = gpe_event_info->dispatch.handler;
gpe_event_info->dispatch.method_node = handler->method_node;
gpe_event_info->flags &=
~(ACPI_GPE_XRUPT_TYPE_MASK | ACPI_GPE_DISPATCH_MASK);
gpe_event_info->flags |= handler->original_flags;
if ((handler->original_flags & ACPI_GPE_DISPATCH_METHOD) &&
handler->originally_enabled) {
(void)acpi_ev_add_gpe_reference(gpe_event_info);
}
ACPI_FREE(handler);
unlock_and_exit:
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
(void)acpi_ut_release_mutex(ACPI_MTX_EVENTS);
return_ACPI_STATUS(status);
}
acpi_status acpi_acquire_global_lock(u16 timeout, u32 * handle)
{
acpi_status status;
if (!handle) {
return (AE_BAD_PARAMETER);
}
acpi_ex_enter_interpreter();
status = acpi_ex_acquire_mutex_object(timeout,
acpi_gbl_global_lock_mutex,
acpi_os_get_thread_id());
if (ACPI_SUCCESS(status)) {
*handle = acpi_gbl_global_lock_handle;
}
acpi_ex_exit_interpreter();
return (status);
}
acpi_status acpi_release_global_lock(u32 handle)
{
acpi_status status;
if (!handle || (handle != acpi_gbl_global_lock_handle)) {
return (AE_NOT_ACQUIRED);
}
status = acpi_ex_release_mutex_object(acpi_gbl_global_lock_mutex);
return (status);
}
