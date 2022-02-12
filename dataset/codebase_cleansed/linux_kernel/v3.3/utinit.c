static void acpi_ut_terminate(void)
{
struct acpi_gpe_block_info *gpe_block;
struct acpi_gpe_block_info *next_gpe_block;
struct acpi_gpe_xrupt_info *gpe_xrupt_info;
struct acpi_gpe_xrupt_info *next_gpe_xrupt_info;
ACPI_FUNCTION_TRACE(ut_terminate);
gpe_xrupt_info = acpi_gbl_gpe_xrupt_list_head;
while (gpe_xrupt_info) {
gpe_block = gpe_xrupt_info->gpe_block_list_head;
while (gpe_block) {
next_gpe_block = gpe_block->next;
ACPI_FREE(gpe_block->event_info);
ACPI_FREE(gpe_block->register_info);
ACPI_FREE(gpe_block);
gpe_block = next_gpe_block;
}
next_gpe_xrupt_info = gpe_xrupt_info->next;
ACPI_FREE(gpe_xrupt_info);
gpe_xrupt_info = next_gpe_xrupt_info;
}
acpi_ut_delete_address_lists();
return_VOID;
}
void acpi_ut_subsystem_shutdown(void)
{
ACPI_FUNCTION_TRACE(ut_subsystem_shutdown);
#ifndef ACPI_ASL_COMPILER
acpi_ev_terminate();
acpi_ut_interface_terminate();
#endif
acpi_ns_terminate();
acpi_tb_terminate();
acpi_ut_terminate();
(void)acpi_ut_delete_caches();
return_VOID;
}
