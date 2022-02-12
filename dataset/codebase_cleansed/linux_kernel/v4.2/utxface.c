acpi_status __init acpi_terminate(void)
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
acpi_status acpi_get_statistics(struct acpi_statistics *stats)
{
ACPI_FUNCTION_TRACE(acpi_get_statistics);
if (!stats) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
stats->sci_count = acpi_sci_count;
stats->gpe_count = acpi_gpe_count;
memcpy(stats->fixed_event_count, acpi_fixed_event_count,
sizeof(acpi_fixed_event_count));
stats->method_count = acpi_method_count;
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
return (AE_OK);
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
if (!interface_name || (strlen(interface_name) == 0)) {
return (AE_BAD_PARAMETER);
}
status = acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
if (ACPI_FAILURE(status)) {
return (status);
}
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
if (!interface_name || (strlen(interface_name) == 0)) {
return (AE_BAD_PARAMETER);
}
status = acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
if (ACPI_FAILURE(status)) {
return (status);
}
status = acpi_ut_remove_interface(interface_name);
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return (status);
}
acpi_status acpi_install_interface_handler(acpi_interface_handler handler)
{
acpi_status status;
status = acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
if (ACPI_FAILURE(status)) {
return (status);
}
if (handler && acpi_gbl_interface_handler) {
status = AE_ALREADY_EXISTS;
} else {
acpi_gbl_interface_handler = handler;
}
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return (status);
}
acpi_status acpi_update_interfaces(u8 action)
{
acpi_status status;
status = acpi_os_acquire_mutex(acpi_gbl_osi_mutex, ACPI_WAIT_FOREVER);
if (ACPI_FAILURE(status)) {
return (status);
}
status = acpi_ut_update_interfaces(action);
acpi_os_release_mutex(acpi_gbl_osi_mutex);
return (status);
}
u32
acpi_check_address_range(acpi_adr_space_type space_id,
acpi_physical_address address,
acpi_size length, u8 warn)
{
u32 overlaps;
acpi_status status;
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (0);
}
overlaps = acpi_ut_check_address_range(space_id, address,
(u32)length, warn);
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (overlaps);
}
acpi_status
acpi_decode_pld_buffer(u8 *in_buffer,
acpi_size length, struct acpi_pld_info ** return_buffer)
{
struct acpi_pld_info *pld_info;
u32 *buffer = ACPI_CAST_PTR(u32, in_buffer);
u32 dword;
if (!in_buffer || !return_buffer || (length < 16)) {
return (AE_BAD_PARAMETER);
}
pld_info = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_pld_info));
if (!pld_info) {
return (AE_NO_MEMORY);
}
ACPI_MOVE_32_TO_32(&dword, &buffer[0]);
pld_info->revision = ACPI_PLD_GET_REVISION(&dword);
pld_info->ignore_color = ACPI_PLD_GET_IGNORE_COLOR(&dword);
pld_info->red = ACPI_PLD_GET_RED(&dword);
pld_info->green = ACPI_PLD_GET_GREEN(&dword);
pld_info->blue = ACPI_PLD_GET_BLUE(&dword);
ACPI_MOVE_32_TO_32(&dword, &buffer[1]);
pld_info->width = ACPI_PLD_GET_WIDTH(&dword);
pld_info->height = ACPI_PLD_GET_HEIGHT(&dword);
ACPI_MOVE_32_TO_32(&dword, &buffer[2]);
pld_info->user_visible = ACPI_PLD_GET_USER_VISIBLE(&dword);
pld_info->dock = ACPI_PLD_GET_DOCK(&dword);
pld_info->lid = ACPI_PLD_GET_LID(&dword);
pld_info->panel = ACPI_PLD_GET_PANEL(&dword);
pld_info->vertical_position = ACPI_PLD_GET_VERTICAL(&dword);
pld_info->horizontal_position = ACPI_PLD_GET_HORIZONTAL(&dword);
pld_info->shape = ACPI_PLD_GET_SHAPE(&dword);
pld_info->group_orientation = ACPI_PLD_GET_ORIENTATION(&dword);
pld_info->group_token = ACPI_PLD_GET_TOKEN(&dword);
pld_info->group_position = ACPI_PLD_GET_POSITION(&dword);
pld_info->bay = ACPI_PLD_GET_BAY(&dword);
ACPI_MOVE_32_TO_32(&dword, &buffer[3]);
pld_info->ejectable = ACPI_PLD_GET_EJECTABLE(&dword);
pld_info->ospm_eject_required = ACPI_PLD_GET_OSPM_EJECT(&dword);
pld_info->cabinet_number = ACPI_PLD_GET_CABINET(&dword);
pld_info->card_cage_number = ACPI_PLD_GET_CARD_CAGE(&dword);
pld_info->reference = ACPI_PLD_GET_REFERENCE(&dword);
pld_info->rotation = ACPI_PLD_GET_ROTATION(&dword);
pld_info->order = ACPI_PLD_GET_ORDER(&dword);
if (length >= ACPI_PLD_BUFFER_SIZE) {
ACPI_MOVE_32_TO_32(&dword, &buffer[4]);
pld_info->vertical_offset = ACPI_PLD_GET_VERT_OFFSET(&dword);
pld_info->horizontal_offset = ACPI_PLD_GET_HORIZ_OFFSET(&dword);
}
*return_buffer = pld_info;
return (AE_OK);
}
