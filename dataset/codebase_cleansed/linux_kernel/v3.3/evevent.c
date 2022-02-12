acpi_status acpi_ev_initialize_events(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ev_initialize_events);
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
status = acpi_ev_fixed_event_initialize();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Unable to initialize fixed events"));
return_ACPI_STATUS(status);
}
status = acpi_ev_gpe_initialize();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Unable to initialize general purpose events"));
return_ACPI_STATUS(status);
}
return_ACPI_STATUS(status);
}
acpi_status acpi_ev_install_xrupt_handlers(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ev_install_xrupt_handlers);
if (acpi_gbl_reduced_hardware) {
return_ACPI_STATUS(AE_OK);
}
status = acpi_ev_install_sci_handler();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Unable to install System Control Interrupt handler"));
return_ACPI_STATUS(status);
}
status = acpi_ev_init_global_lock_handler();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Unable to initialize Global Lock handler"));
return_ACPI_STATUS(status);
}
acpi_gbl_events_initialized = TRUE;
return_ACPI_STATUS(status);
}
static acpi_status acpi_ev_fixed_event_initialize(void)
{
u32 i;
acpi_status status;
for (i = 0; i < ACPI_NUM_FIXED_EVENTS; i++) {
acpi_gbl_fixed_event_handlers[i].handler = NULL;
acpi_gbl_fixed_event_handlers[i].context = NULL;
if (acpi_gbl_fixed_event_info[i].enable_register_id != 0xFF) {
status =
acpi_write_bit_register(acpi_gbl_fixed_event_info
[i].enable_register_id,
ACPI_DISABLE_EVENT);
if (ACPI_FAILURE(status)) {
return (status);
}
}
}
return (AE_OK);
}
u32 acpi_ev_fixed_event_detect(void)
{
u32 int_status = ACPI_INTERRUPT_NOT_HANDLED;
u32 fixed_status;
u32 fixed_enable;
u32 i;
ACPI_FUNCTION_NAME(ev_fixed_event_detect);
(void)acpi_hw_register_read(ACPI_REGISTER_PM1_STATUS, &fixed_status);
(void)acpi_hw_register_read(ACPI_REGISTER_PM1_ENABLE, &fixed_enable);
ACPI_DEBUG_PRINT((ACPI_DB_INTERRUPTS,
"Fixed Event Block: Enable %08X Status %08X\n",
fixed_enable, fixed_status));
for (i = 0; i < ACPI_NUM_FIXED_EVENTS; i++) {
if ((fixed_status & acpi_gbl_fixed_event_info[i].
status_bit_mask)
&& (fixed_enable & acpi_gbl_fixed_event_info[i].
enable_bit_mask)) {
acpi_fixed_event_count[i]++;
if (acpi_gbl_global_event_handler) {
acpi_gbl_global_event_handler
(ACPI_EVENT_TYPE_FIXED, NULL, i,
acpi_gbl_global_event_handler_context);
}
int_status |= acpi_ev_fixed_event_dispatch(i);
}
}
return (int_status);
}
static u32 acpi_ev_fixed_event_dispatch(u32 event)
{
ACPI_FUNCTION_ENTRY();
(void)acpi_write_bit_register(acpi_gbl_fixed_event_info[event].
status_register_id, ACPI_CLEAR_STATUS);
if (NULL == acpi_gbl_fixed_event_handlers[event].handler) {
(void)acpi_write_bit_register(acpi_gbl_fixed_event_info[event].
enable_register_id,
ACPI_DISABLE_EVENT);
ACPI_ERROR((AE_INFO,
"No installed handler for fixed event [0x%08X]",
event));
return (ACPI_INTERRUPT_NOT_HANDLED);
}
return ((acpi_gbl_fixed_event_handlers[event].
handler) (acpi_gbl_fixed_event_handlers[event].context));
}
