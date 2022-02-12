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
#ifdef ACPI_DEBUGGER
status = acpi_db_initialize();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During Debugger initialization"));
return_ACPI_STATUS(status);
}
#endif
return_ACPI_STATUS(AE_OK);
}
acpi_status __init acpi_enable_subsystem(u32 flags)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(acpi_enable_subsystem);
#if (!ACPI_REDUCED_HARDWARE)
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
if (!(flags & ACPI_NO_FACS_INIT)) {
status = acpi_tb_initialize_facs();
if (ACPI_FAILURE(status)) {
ACPI_WARNING((AE_INFO, "Could not map the FACS table"));
return_ACPI_STATUS(status);
}
}
#endif
if (!(flags & ACPI_NO_ADDRESS_SPACE_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Installing default address space handlers\n"));
status = acpi_ev_install_region_handlers();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
#if (!ACPI_REDUCED_HARDWARE)
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
#endif
return_ACPI_STATUS(status);
}
acpi_status __init acpi_initialize_objects(u32 flags)
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
#ifdef ACPI_EXEC_APP
ae_do_object_overrides();
#endif
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
