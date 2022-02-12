acpi_status acpi_enable(void)
{
acpi_status status;
int retry;
ACPI_FUNCTION_TRACE(acpi_enable);
if (acpi_gbl_fadt_index == ACPI_INVALID_TABLE_INDEX) {
return_ACPI_STATUS(AE_NO_ACPI_TABLES);
}
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
if (acpi_hw_get_mode() == ACPI_SYS_MODE_ACPI) {
ACPI_DEBUG_PRINT((ACPI_DB_INIT,
"System is already in ACPI mode\n"));
return_ACPI_STATUS(AE_OK);
}
status = acpi_hw_set_mode(ACPI_SYS_MODE_ACPI);
if (ACPI_FAILURE(status)) {
ACPI_ERROR((AE_INFO,
"Could not transition to ACPI mode"));
return_ACPI_STATUS(status);
}
for (retry = 0; retry < 30000; ++retry) {
if (acpi_hw_get_mode() == ACPI_SYS_MODE_ACPI) {
if (retry != 0)
ACPI_WARNING((AE_INFO,
"Platform took > %d00 usec to enter ACPI mode", retry));
return_ACPI_STATUS(AE_OK);
}
acpi_os_stall(100);
}
ACPI_ERROR((AE_INFO, "Hardware did not enter ACPI mode"));
return_ACPI_STATUS(AE_NO_HARDWARE_RESPONSE);
}
acpi_status acpi_disable(void)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(acpi_disable);
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
if (acpi_hw_get_mode() == ACPI_SYS_MODE_LEGACY) {
ACPI_DEBUG_PRINT((ACPI_DB_INIT,
"System is already in legacy (non-ACPI) mode\n"));
} else {
status = acpi_hw_set_mode(ACPI_SYS_MODE_LEGACY);
if (ACPI_FAILURE(status)) {
ACPI_ERROR((AE_INFO,
"Could not exit ACPI mode to legacy mode"));
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_INIT, "ACPI mode disabled\n"));
}
return_ACPI_STATUS(status);
}
acpi_status acpi_enable_event(u32 event, u32 flags)
{
acpi_status status = AE_OK;
u32 value;
ACPI_FUNCTION_TRACE(acpi_enable_event);
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
if (event > ACPI_EVENT_MAX) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status =
acpi_write_bit_register(acpi_gbl_fixed_event_info[event].
enable_register_id, ACPI_ENABLE_EVENT);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status =
acpi_read_bit_register(acpi_gbl_fixed_event_info[event].
enable_register_id, &value);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (value != 1) {
ACPI_ERROR((AE_INFO,
"Could not enable %s event",
acpi_ut_get_event_name(event)));
return_ACPI_STATUS(AE_NO_HARDWARE_RESPONSE);
}
return_ACPI_STATUS(status);
}
acpi_status acpi_disable_event(u32 event, u32 flags)
{
acpi_status status = AE_OK;
u32 value;
ACPI_FUNCTION_TRACE(acpi_disable_event);
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
if (event > ACPI_EVENT_MAX) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status =
acpi_write_bit_register(acpi_gbl_fixed_event_info[event].
enable_register_id, ACPI_DISABLE_EVENT);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status =
acpi_read_bit_register(acpi_gbl_fixed_event_info[event].
enable_register_id, &value);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (value != 0) {
ACPI_ERROR((AE_INFO,
"Could not disable %s events",
acpi_ut_get_event_name(event)));
return_ACPI_STATUS(AE_NO_HARDWARE_RESPONSE);
}
return_ACPI_STATUS(status);
}
acpi_status acpi_clear_event(u32 event)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(acpi_clear_event);
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
if (event > ACPI_EVENT_MAX) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status =
acpi_write_bit_register(acpi_gbl_fixed_event_info[event].
status_register_id, ACPI_CLEAR_STATUS);
return_ACPI_STATUS(status);
}
acpi_status acpi_get_event_status(u32 event, acpi_event_status * event_status)
{
acpi_status status;
acpi_event_status local_event_status = 0;
u32 in_byte;
ACPI_FUNCTION_TRACE(acpi_get_event_status);
if (!event_status) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (event > ACPI_EVENT_MAX) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (acpi_gbl_fixed_event_handlers[event].handler) {
local_event_status |= ACPI_EVENT_FLAG_HAS_HANDLER;
}
status =
acpi_read_bit_register(acpi_gbl_fixed_event_info[event].
enable_register_id, &in_byte);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (in_byte) {
local_event_status |=
(ACPI_EVENT_FLAG_ENABLED | ACPI_EVENT_FLAG_ENABLE_SET);
}
status =
acpi_read_bit_register(acpi_gbl_fixed_event_info[event].
status_register_id, &in_byte);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (in_byte) {
local_event_status |= ACPI_EVENT_FLAG_STATUS_SET;
}
(*event_status) = local_event_status;
return_ACPI_STATUS(AE_OK);
}
