static __init int no_ipi_broadcast(char *str)
{
get_option(&str, &no_broadcast);
pr_info("Using %s mode\n",
no_broadcast ? "No IPI Broadcast" : "IPI Broadcast");
return 1;
}
static int __init print_ipi_mode(void)
{
pr_info("Using IPI %s mode\n",
no_broadcast ? "No-Shortcut" : "Shortcut");
return 0;
}
static int default_x86_32_early_logical_apicid(int cpu)
{
return 1 << cpu;
}
static void setup_apic_flat_routing(void)
{
#ifdef CONFIG_X86_IO_APIC
printk(KERN_INFO
"Enabling APIC mode: Flat. Using %d I/O APICs\n",
nr_ioapics);
#endif
}
static int probe_default(void)
{
return 1;
}
static int __init parse_apic(char *arg)
{
struct apic **drv;
if (!arg)
return -EINVAL;
for (drv = __apicdrivers; drv < __apicdrivers_end; drv++) {
if (!strcmp((*drv)->name, arg)) {
apic = *drv;
cmdline_apic = 1;
return 0;
}
}
return 0;
}
void __init default_setup_apic_routing(void)
{
int version = apic_version[boot_cpu_physical_apicid];
if (num_possible_cpus() > 8) {
switch (boot_cpu_data.x86_vendor) {
case X86_VENDOR_INTEL:
if (!APIC_XAPIC(version)) {
def_to_bigsmp = 0;
break;
}
case X86_VENDOR_AMD:
def_to_bigsmp = 1;
}
}
#ifdef CONFIG_X86_BIGSMP
if (!cmdline_apic && apic == &apic_default)
generic_bigsmp_probe();
#endif
if (apic->setup_apic_routing)
apic->setup_apic_routing();
if (x86_platform.apic_post_init)
x86_platform.apic_post_init();
}
void __init generic_apic_probe(void)
{
if (!cmdline_apic) {
struct apic **drv;
for (drv = __apicdrivers; drv < __apicdrivers_end; drv++) {
if ((*drv)->probe()) {
apic = *drv;
break;
}
}
if (drv == __apicdrivers_end)
panic("Didn't find an APIC driver");
}
printk(KERN_INFO "Using APIC driver %s\n", apic->name);
}
int __init default_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
struct apic **drv;
for (drv = __apicdrivers; drv < __apicdrivers_end; drv++) {
if (!(*drv)->acpi_madt_oem_check)
continue;
if (!(*drv)->acpi_madt_oem_check(oem_id, oem_table_id))
continue;
if (!cmdline_apic) {
apic = *drv;
printk(KERN_INFO "Switched to APIC driver `%s'.\n",
apic->name);
}
return 1;
}
return 0;
}
