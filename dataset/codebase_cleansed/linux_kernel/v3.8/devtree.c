void __init early_init_dt_add_memory_arch(u64 base, u64 size)
{
arm_add_memory(base, size);
}
void * __init early_init_dt_alloc_memory_arch(u64 size, u64 align)
{
return alloc_bootmem_align(size, align);
}
void __init arm_dt_memblock_reserve(void)
{
u64 *reserve_map, base, size;
if (!initial_boot_params)
return;
memblock_reserve(virt_to_phys(initial_boot_params),
be32_to_cpu(initial_boot_params->totalsize));
reserve_map = ((void*)initial_boot_params) +
be32_to_cpu(initial_boot_params->off_mem_rsvmap);
while (1) {
base = be64_to_cpup(reserve_map++);
size = be64_to_cpup(reserve_map++);
if (!size)
break;
memblock_reserve(base, size);
}
}
void __init arm_dt_init_cpu_maps(void)
{
struct device_node *cpu, *cpus;
u32 i, j, cpuidx = 1;
u32 mpidr = is_smp() ? read_cpuid_mpidr() & MPIDR_HWID_BITMASK : 0;
u32 tmp_map[NR_CPUS] = { [0 ... NR_CPUS-1] = UINT_MAX };
bool bootcpu_valid = false;
cpus = of_find_node_by_path("/cpus");
if (!cpus)
return;
for_each_child_of_node(cpus, cpu) {
u32 hwid;
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
}
if (WARN(!bootcpu_valid, "DT missing boot CPU MPIDR[23:0], "
"fall back to default cpu_logical_map\n"))
return;
for (i = 0; i < cpuidx; i++) {
set_cpu_possible(i, true);
cpu_logical_map(i) = tmp_map[i];
pr_debug("cpu logical map 0x%x\n", cpu_logical_map(i));
}
}
struct machine_desc * __init setup_machine_fdt(unsigned int dt_phys)
{
struct boot_param_header *devtree;
struct machine_desc *mdesc, *mdesc_best = NULL;
unsigned int score, mdesc_score = ~1;
unsigned long dt_root;
const char *model;
if (!dt_phys)
return NULL;
devtree = phys_to_virt(dt_phys);
if (be32_to_cpu(devtree->magic) != OF_DT_HEADER)
return NULL;
initial_boot_params = devtree;
dt_root = of_get_flat_dt_root();
for_each_machine_desc(mdesc) {
score = of_flat_dt_match(dt_root, mdesc->dt_compat);
if (score > 0 && score < mdesc_score) {
mdesc_best = mdesc;
mdesc_score = score;
}
}
if (!mdesc_best) {
const char *prop;
long size;
early_print("\nError: unrecognized/unsupported "
"device tree compatible list:\n[ ");
prop = of_get_flat_dt_prop(dt_root, "compatible", &size);
while (size > 0) {
early_print("'%s' ", prop);
size -= strlen(prop) + 1;
prop += strlen(prop) + 1;
}
early_print("]\n\n");
dump_machine_table();
}
model = of_get_flat_dt_prop(dt_root, "model", NULL);
if (!model)
model = of_get_flat_dt_prop(dt_root, "compatible", NULL);
if (!model)
model = "<unknown>";
pr_info("Machine: %s, model: %s\n", mdesc_best->name, model);
of_scan_flat_dt(early_init_dt_scan_chosen, boot_command_line);
of_scan_flat_dt(early_init_dt_scan_root, NULL);
of_scan_flat_dt(early_init_dt_scan_memory, NULL);
__machine_arch_type = mdesc_best->nr;
return mdesc_best;
}
