static int apicid_phys_pkg_id(int initial_apic_id, int index_msb)
{
return hard_smp_processor_id() >> index_msb;
}
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
if (is_vsmp_box()) {
apic->phys_pkg_id = apicid_phys_pkg_id;
}
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
