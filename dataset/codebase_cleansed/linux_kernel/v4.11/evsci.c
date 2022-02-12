u32 acpi_ev_sci_dispatch(void)
{
struct acpi_sci_handler_info *sci_handler;
acpi_cpu_flags flags;
u32 int_status = ACPI_INTERRUPT_NOT_HANDLED;
ACPI_FUNCTION_NAME(ev_sci_dispatch);
if (!acpi_gbl_sci_handler_list) {
return (int_status);
}
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
sci_handler = acpi_gbl_sci_handler_list;
while (sci_handler) {
int_status |= sci_handler->address(sci_handler->context);
sci_handler = sci_handler->next;
}
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
return (int_status);
}
static u32 ACPI_SYSTEM_XFACE acpi_ev_sci_xrupt_handler(void *context)
{
struct acpi_gpe_xrupt_info *gpe_xrupt_list = context;
u32 interrupt_handled = ACPI_INTERRUPT_NOT_HANDLED;
ACPI_FUNCTION_TRACE(ev_sci_xrupt_handler);
interrupt_handled |= acpi_ev_fixed_event_detect();
interrupt_handled |= acpi_ev_gpe_detect(gpe_xrupt_list);
interrupt_handled |= acpi_ev_sci_dispatch();
acpi_sci_count++;
return_UINT32(interrupt_handled);
}
u32 ACPI_SYSTEM_XFACE acpi_ev_gpe_xrupt_handler(void *context)
{
struct acpi_gpe_xrupt_info *gpe_xrupt_list = context;
u32 interrupt_handled = ACPI_INTERRUPT_NOT_HANDLED;
ACPI_FUNCTION_TRACE(ev_gpe_xrupt_handler);
interrupt_handled |= acpi_ev_gpe_detect(gpe_xrupt_list);
return_UINT32(interrupt_handled);
}
u32 acpi_ev_install_sci_handler(void)
{
u32 status = AE_OK;
ACPI_FUNCTION_TRACE(ev_install_sci_handler);
status =
acpi_os_install_interrupt_handler((u32) acpi_gbl_FADT.sci_interrupt,
acpi_ev_sci_xrupt_handler,
acpi_gbl_gpe_xrupt_list_head);
return_ACPI_STATUS(status);
}
acpi_status acpi_ev_remove_all_sci_handlers(void)
{
struct acpi_sci_handler_info *sci_handler;
acpi_cpu_flags flags;
acpi_status status;
ACPI_FUNCTION_TRACE(ev_remove_all_sci_handlers);
status =
acpi_os_remove_interrupt_handler((u32) acpi_gbl_FADT.sci_interrupt,
acpi_ev_sci_xrupt_handler);
if (!acpi_gbl_sci_handler_list) {
return (status);
}
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
while (acpi_gbl_sci_handler_list) {
sci_handler = acpi_gbl_sci_handler_list;
acpi_gbl_sci_handler_list = sci_handler->next;
ACPI_FREE(sci_handler);
}
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
return_ACPI_STATUS(status);
}
