void __init default_setup_apic_routing(void)
{
struct apic **drv;
enable_IR_x2apic();
for (drv = __apicdrivers; drv < __apicdrivers_end; drv++) {
if ((*drv)->probe && (*drv)->probe()) {
if (apic != *drv) {
apic = *drv;
pr_info("Switched APIC routing to %s.\n",
apic->name);
}
break;
}
}
if (x86_platform.apic_post_init)
x86_platform.apic_post_init();
}
void apic_send_IPI_self(int vector)
{
__default_send_IPI_shortcut(APIC_DEST_SELF, vector, APIC_DEST_PHYSICAL);
}
int __init default_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
struct apic **drv;
for (drv = __apicdrivers; drv < __apicdrivers_end; drv++) {
if ((*drv)->acpi_madt_oem_check(oem_id, oem_table_id)) {
if (apic != *drv) {
apic = *drv;
pr_info("Setting APIC routing to %s.\n",
apic->name);
}
return 1;
}
}
return 0;
}
