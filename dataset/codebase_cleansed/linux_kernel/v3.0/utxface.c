acpi_status __init acpi_initialize_subsystem(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_initialize_subsystem);
acpi_gbl_startup_flags = ACPI_SUBSYSTEM_INITIALIZE;
ACPI_DEBUG_EXEC(acpi_ut_init_stack_ptr_trace());
status = acpi_os_initialize();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "During OSL initialization"));
return_ACPI_STATUS(status);
}
status = acpi_ut_init_globals();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During initialization of globals"));
return_ACPI_STATUS(status);
}
status = acpi_ut_mutex_initialize();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During Global Mutex creation"));
return_ACPI_STATUS(status);
}
status = acpi_ns_root_initialize();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During Namespace initialization"));
return_ACPI_STATUS(status);
}
status = acpi_ut_initialize_interfaces();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During OSI interfaces initialization"));
return_ACPI_STATUS(status);
}
ACPI_DEBUGGER_EXEC(status = acpi_db_initialize());
return_ACPI_STATUS(status);
}
acpi_status acpi_enable_subsystem(u32 flags)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(acpi_enable_subsystem);
if (!(flags & ACPI_NO_ACPI_ENABLE)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Going into ACPI mode\n"));
acpi_gbl_original_mode = acpi_hw_get_mode();
status = acpi_enable();
if (ACPI_FAILURE(status)) {
ACPI_WARNING((AE_INFO, "AcpiEnable failed"));
return_ACPI_STATUS(status);
}
}
status = acpi_tb_initialize_facs();
if (ACPI_FAILURE(status)) {
ACPI_WARNING((AE_INFO, "Could not map the FACS table"));
return_ACPI_STATUS(status);
}
if (!(flags & ACPI_NO_ADDRESS_SPACE_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Installing default address space handlers\n"));
status = acpi_ev_install_region_handlers();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (!(flags & ACPI_NO_EVENT_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Initializing ACPI events\n"));
status = acpi_ev_initialize_events();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (!(flags & ACPI_NO_HANDLER_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Installing SCI/GL handlers\n"));
status = acpi_ev_install_xrupt_handlers();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
return_ACPI_STATUS(status);
}
acpi_status acpi_initialize_objects(u32 flags)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(acpi_initialize_objects);
if (!(flags & ACPI_NO_ADDRESS_SPACE_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Executing _REG OpRegion methods\n"));
status = acpi_ev_initialize_op_regions();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
acpi_ns_exec_module_code_list();
if (!(flags & ACPI_NO_OBJECT_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Completing Initialization of ACPI Objects\n"));
status = acpi_ns_initialize_objects();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (!(flags & ACPI_NO_DEVICE_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Initializing ACPI Devices\n"));
status = acpi_ns_initialize_devices();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
status = acpi_purge_cached_objects();
acpi_gbl_startup_flags |= ACPI_INITIALIZED_OK;
return_ACPI_STATUS(status);
}
acpi_status acpi_terminate(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_terminate);
if (acpi_gbl_shutdown) {
ACPI_ERROR((AE_INFO, "ACPI Subsystem is already terminated"));
return_ACPI_STATUS(AE_OK);
}
acpi_gbl_shutdown = TRUE;
acpi_gbl_startup_flags = 0;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Shutting down ACPI Subsystem\n"));
ACPI_DEBUGGER_EXEC(acpi_gbl_db_terminate_threads = TRUE);
acpi_ut_subsystem_shutdown();
acpi_ut_mutex_terminate();
#ifdef ACPI_DEBUGGER
acpi_db_terminate();
#endif
status = acpi_os_terminate();
return_ACPI_STATUS(status);
}
acpi_status acpi_subsystem_status(void)
{
if (acpi_gbl_startup_flags & ACPI_INITIALIZED_OK) {
return (AE_OK);
} else {
return (AE_ERROR);
}
}
acpi_status acpi_get_system_info(struct acpi_buffer * out_buffer)
{
struct acpi_system_info *info_ptr;
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_get_system_info);
status = acpi_ut_validate_buffer(out_buffer);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status =
acpi_ut_initialize_buffer(out_buffer,
sizeof(struct acpi_system_info));
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
info_ptr = (struct acpi_system_info *)out_buffer->pointer;
info_ptr->acpi_ca_version = ACPI_CA_VERSION;
info_ptr->flags = ACPI_SYS_MODE_ACPI;
if (acpi_gbl_FADT.flags & ACPI_FADT_32BIT_TIMER) {
info_ptr->timer_resolution = 24;
} else {
info_ptr->timer_resolution = 32;
}
info_ptr->reserved1 = 0;
info_ptr->reserved2 = 0;
info_ptr->debug_layer = acpi_dbg_layer;
info_ptr->debug_level = acpi_dbg_level;
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_install_initialization_handler(acpi_init_handler handler, u32 function)
{
if (!handler) {
return (AE_BAD_PARAMETER);
}
if (acpi_gbl_init_handler) {
return (AE_ALREADY_EXISTS);
}
acpi_gbl_init_handler = handler;
return AE_OK;
}
acpi_status acpi_purge_cached_objects(void)
{
ACPI_FUNCTION_TRACE(acpi_purge_cached_objects);
(void)acpi_os_purge_cache(acpi_gbl_state_cache);
(void)acpi_os_purge_cache(acpi_gbl_operand_cache);
(void)acpi_os_purge_cache(acpi_gbl_ps_node_cache);
(void)acpi_os_purge_cache(acpi_gbl_ps_node_ext_cache);
return_ACPI_STATUS(AE_OK);
}
acpi_status acpi_install_interface(acpi_string interface_name)
{
acpi_status status;
struct acpi_interface_info *interface_info;
if (!interface_name || (ACPI_STRLEN(interface_name) == 0)) {
return (AE_BAD_PARAMETER);
}
(void)acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
interface_info = acpi_ut_get_interface(interface_name);
if (interface_info) {
if (interface_info->flags & ACPI_OSI_INVALID) {
interface_info->flags &= ~ACPI_OSI_INVALID;
status = AE_OK;
} else {
status = AE_ALREADY_EXISTS;
}
} else {
status = acpi_ut_install_interface(interface_name);
}
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return (status);
}
acpi_status acpi_remove_interface(acpi_string interface_name)
{
acpi_status status;
if (!interface_name || (ACPI_STRLEN(interface_name) == 0)) {
return (AE_BAD_PARAMETER);
}
(void)acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
status = acpi_ut_remove_interface(interface_name);
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return (status);
}
acpi_status acpi_install_interface_handler(acpi_interface_handler handler)
{
acpi_status status = AE_OK;
(void)acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
if (handler && acpi_gbl_interface_handler) {
status = AE_ALREADY_EXISTS;
} else {
acpi_gbl_interface_handler = handler;
}
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return (status);
}
