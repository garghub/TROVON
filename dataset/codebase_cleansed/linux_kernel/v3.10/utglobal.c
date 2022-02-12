acpi_status acpi_ut_init_globals(void)
{
acpi_status status;
u32 i;
ACPI_FUNCTION_TRACE(ut_init_globals);
status = acpi_ut_create_caches();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
for (i = 0; i < ACPI_ADDRESS_RANGE_MAX; i++) {
acpi_gbl_address_range_list[i] = NULL;
}
for (i = 0; i < ACPI_NUM_MUTEX; i++) {
acpi_gbl_mutex_info[i].mutex = NULL;
acpi_gbl_mutex_info[i].thread_id = ACPI_MUTEX_NOT_ACQUIRED;
acpi_gbl_mutex_info[i].use_count = 0;
}
for (i = 0; i < ACPI_NUM_OWNERID_MASKS; i++) {
acpi_gbl_owner_id_mask[i] = 0;
}
acpi_gbl_owner_id_mask[ACPI_NUM_OWNERID_MASKS - 1] = 0x80000000;
#if (!ACPI_REDUCED_HARDWARE)
acpi_gbl_all_gpes_initialized = FALSE;
acpi_gbl_gpe_xrupt_list_head = NULL;
acpi_gbl_gpe_fadt_blocks[0] = NULL;
acpi_gbl_gpe_fadt_blocks[1] = NULL;
acpi_current_gpe_count = 0;
acpi_gbl_global_event_handler = NULL;
#endif
acpi_gbl_global_notify[0].handler = NULL;
acpi_gbl_global_notify[1].handler = NULL;
acpi_gbl_exception_handler = NULL;
acpi_gbl_init_handler = NULL;
acpi_gbl_table_handler = NULL;
acpi_gbl_interface_handler = NULL;
acpi_gbl_global_lock_semaphore = NULL;
acpi_gbl_global_lock_mutex = NULL;
acpi_gbl_global_lock_acquired = FALSE;
acpi_gbl_global_lock_handle = 0;
acpi_gbl_global_lock_present = FALSE;
acpi_gbl_DSDT = NULL;
acpi_gbl_cm_single_step = FALSE;
acpi_gbl_db_terminate_threads = FALSE;
acpi_gbl_shutdown = FALSE;
acpi_gbl_ns_lookup_count = 0;
acpi_gbl_ps_find_count = 0;
acpi_gbl_acpi_hardware_present = TRUE;
acpi_gbl_last_owner_id_index = 0;
acpi_gbl_next_owner_id_offset = 0;
acpi_gbl_trace_method_name = 0;
acpi_gbl_trace_dbg_level = 0;
acpi_gbl_trace_dbg_layer = 0;
acpi_gbl_debugger_configuration = DEBUGGER_THREADING;
acpi_gbl_db_output_flags = ACPI_DB_CONSOLE_OUTPUT;
acpi_gbl_osi_data = 0;
acpi_gbl_osi_mutex = NULL;
acpi_gbl_reg_methods_executed = FALSE;
acpi_gbl_events_initialized = FALSE;
acpi_gbl_system_awake_and_running = TRUE;
acpi_gbl_module_code_list = NULL;
acpi_gbl_root_node = NULL;
acpi_gbl_root_node_struct.name.integer = ACPI_ROOT_NAME;
acpi_gbl_root_node_struct.descriptor_type = ACPI_DESC_TYPE_NAMED;
acpi_gbl_root_node_struct.type = ACPI_TYPE_DEVICE;
acpi_gbl_root_node_struct.parent = NULL;
acpi_gbl_root_node_struct.child = NULL;
acpi_gbl_root_node_struct.peer = NULL;
acpi_gbl_root_node_struct.object = NULL;
#ifdef ACPI_DISASSEMBLER
acpi_gbl_external_list = NULL;
acpi_gbl_num_external_methods = 0;
acpi_gbl_resolved_external_methods = 0;
#endif
#ifdef ACPI_DEBUG_OUTPUT
acpi_gbl_lowest_stack_pointer = ACPI_CAST_PTR(acpi_size, ACPI_SIZE_MAX);
#endif
#ifdef ACPI_DBG_TRACK_ALLOCATIONS
acpi_gbl_display_final_mem_stats = FALSE;
acpi_gbl_disable_mem_tracking = FALSE;
#endif
return_ACPI_STATUS(AE_OK);
}
