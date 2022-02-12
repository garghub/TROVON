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
