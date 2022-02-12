static u32 ACPI_SYSTEM_XFACE acpi_ev_sci_xrupt_handler(void *context)
{
struct acpi_gpe_xrupt_info *gpe_xrupt_list = context;
u32 interrupt_handled = ACPI_INTERRUPT_NOT_HANDLED;
ACPI_FUNCTION_TRACE(ev_sci_xrupt_handler);
interrupt_handled |= acpi_ev_fixed_event_detect();
interrupt_handled |= acpi_ev_gpe_detect(gpe_xrupt_list);
return_VALUE(interrupt_handled);
}
u32 ACPI_SYSTEM_XFACE acpi_ev_gpe_xrupt_handler(void *context)
{
struct acpi_gpe_xrupt_info *gpe_xrupt_list = context;
u32 interrupt_handled = ACPI_INTERRUPT_NOT_HANDLED;
ACPI_FUNCTION_TRACE(ev_gpe_xrupt_handler);
interrupt_handled |= acpi_ev_gpe_detect(gpe_xrupt_list);
return_VALUE(interrupt_handled);
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
acpi_status acpi_ev_remove_sci_handler(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ev_remove_sci_handler);
status =
acpi_os_remove_interrupt_handler((u32) acpi_gbl_FADT.sci_interrupt,
acpi_ev_sci_xrupt_handler);
return_ACPI_STATUS(status);
}
