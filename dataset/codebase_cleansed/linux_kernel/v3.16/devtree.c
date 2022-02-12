static int __init set_smp_ops_by_method(struct device_node *node)
{
const char *method;
struct of_cpu_method *m = __cpu_method_of_table;
if (of_property_read_string(node, "enable-method", &method))
return 0;
for (; m->method; m++)
if (!strcmp(m->method, method)) {
smp_set_ops(m->ops);
return 1;
}
return 0;
}
static inline int set_smp_ops_by_method(struct device_node *node)
{
return 1;
}
void __init arm_dt_init_cpu_maps(void)
{
struct device_node *cpu, *cpus;
int found_method = 0;
u32 i, j, cpuidx = 1;
u32 mpidr = is_smp() ? read_cpuid_mpidr() & MPIDR_HWID_BITMASK : 0;
u32 tmp_map[NR_CPUS] = { [0 ... NR_CPUS-1] = MPIDR_INVALID };
bool bootcpu_valid = false;
cpus = of_find_node_by_path("/cpus");
if (!cpus)
return;
for_each_child_of_node(cpus, cpu) {
u32 hwid;
if (of_node_cmp(cpu->type, "cpu"))
continue;
pr_debug(" * %s...\n", cpu->full_name);
if (of_property_read_u32(cpu, "reg", &hwid)) {
pr_debug(" * %s missing reg property\n",
cpu->full_name);
return;
}
if (hwid & ~MPIDR_HWID_BITMASK)
return;
for (j = 0; j < cpuidx; j++)
if (WARN(tmp_map[j] == hwid, "Duplicate /cpu reg "
"properties in the DT\n"))
return;
if (hwid == mpidr) {
i = 0;
bootcpu_valid = true;
} else {
i = cpuidx++;
}
if (WARN(cpuidx > nr_cpu_ids, "DT /cpu %u nodes greater than "
"max cores %u, capping them\n",
cpuidx, nr_cpu_ids)) {
cpuidx = nr_cpu_ids;
break;
}
tmp_map[i] = hwid;
if (!found_method)
found_method = set_smp_ops_by_method(cpu);
}
if (!found_method)
set_smp_ops_by_method(cpus);
if (!bootcpu_valid) {
pr_warn("DT missing boot CPU MPIDR[23:0], fall back to default cpu_logical_map\n");
return;
}
for (i = 0; i < cpuidx; i++) {
set_cpu_possible(i, true);
cpu_logical_map(i) = tmp_map[i];
pr_debug("cpu logical map 0x%x\n", cpu_logical_map(i));
}
}
bool arch_match_cpu_phys_id(int cpu, u64 phys_id)
{
return phys_id == cpu_logical_map(cpu);
}
static const void * __init arch_get_next_mach(const char *const **match)
{
static const struct machine_desc *mdesc = __arch_info_begin;
const struct machine_desc *m = mdesc;
if (m >= __arch_info_end)
return NULL;
mdesc++;
*match = m->dt_compat;
return m;
}
const struct machine_desc * __init setup_machine_fdt(unsigned int dt_phys)
{
const struct machine_desc *mdesc, *mdesc_best = NULL;
#ifdef CONFIG_ARCH_MULTIPLATFORM
DT_MACHINE_START(GENERIC_DT, "Generic DT based system")
MACHINE_END
mdesc_best = &__mach_desc_GENERIC_DT;
#endif
if (!dt_phys || !early_init_dt_verify(phys_to_virt(dt_phys)))
return NULL;
mdesc = of_flat_dt_match_machine(mdesc_best, arch_get_next_mach);
if (!mdesc) {
const char *prop;
int size;
unsigned long dt_root;
early_print("\nError: unrecognized/unsupported "
"device tree compatible list:\n[ ");
dt_root = of_get_flat_dt_root();
prop = of_get_flat_dt_prop(dt_root, "compatible", &size);
while (size > 0) {
early_print("'%s' ", prop);
size -= strlen(prop) + 1;
prop += strlen(prop) + 1;
}
early_print("]\n\n");
dump_machine_table();
}
if (mdesc->dt_fixup)
mdesc->dt_fixup();
early_init_dt_scan_nodes();
__machine_arch_type = mdesc->nr;
return mdesc;
}
