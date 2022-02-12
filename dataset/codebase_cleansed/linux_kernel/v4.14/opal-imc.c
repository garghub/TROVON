static int imc_get_mem_addr_nest(struct device_node *node,
struct imc_pmu *pmu_ptr,
u32 offset)
{
int nr_chips = 0, i;
u64 *base_addr_arr, baddr;
u32 *chipid_arr;
nr_chips = of_property_count_u32_elems(node, "chip-id");
if (nr_chips <= 0)
return -ENODEV;
base_addr_arr = kcalloc(nr_chips, sizeof(u64), GFP_KERNEL);
if (!base_addr_arr)
return -ENOMEM;
chipid_arr = kcalloc(nr_chips, sizeof(u32), GFP_KERNEL);
if (!chipid_arr)
return -ENOMEM;
if (of_property_read_u32_array(node, "chip-id", chipid_arr, nr_chips))
goto error;
if (of_property_read_u64_array(node, "base-addr", base_addr_arr,
nr_chips))
goto error;
pmu_ptr->mem_info = kcalloc(nr_chips, sizeof(struct imc_mem_info),
GFP_KERNEL);
if (!pmu_ptr->mem_info)
goto error;
for (i = 0; i < nr_chips; i++) {
pmu_ptr->mem_info[i].id = chipid_arr[i];
baddr = base_addr_arr[i] + offset;
pmu_ptr->mem_info[i].vbase = phys_to_virt(baddr);
}
pmu_ptr->imc_counter_mmaped = true;
kfree(base_addr_arr);
kfree(chipid_arr);
return 0;
error:
kfree(pmu_ptr->mem_info);
kfree(base_addr_arr);
kfree(chipid_arr);
return -1;
}
static int imc_pmu_create(struct device_node *parent, int pmu_index, int domain)
{
int ret = 0;
struct imc_pmu *pmu_ptr;
u32 offset;
pmu_ptr = kzalloc(sizeof(struct imc_pmu), GFP_KERNEL);
if (!pmu_ptr)
return -ENOMEM;
pmu_ptr->domain = domain;
ret = of_property_read_u32(parent, "size", &pmu_ptr->counter_mem_size);
if (ret) {
ret = -EINVAL;
goto free_pmu;
}
if (!of_property_read_u32(parent, "offset", &offset)) {
if (imc_get_mem_addr_nest(parent, pmu_ptr, offset)) {
ret = -EINVAL;
goto free_pmu;
}
}
ret = init_imc_pmu(parent, pmu_ptr, pmu_index);
if (ret)
pr_err("IMC PMU %s Register failed\n", pmu_ptr->pmu.name);
return 0;
free_pmu:
kfree(pmu_ptr);
return ret;
}
static void disable_nest_pmu_counters(void)
{
int nid, cpu;
const struct cpumask *l_cpumask;
get_online_cpus();
for_each_online_node(nid) {
l_cpumask = cpumask_of_node(nid);
cpu = cpumask_first(l_cpumask);
opal_imc_counters_stop(OPAL_IMC_COUNTERS_NEST,
get_hard_smp_processor_id(cpu));
}
put_online_cpus();
}
static void disable_core_pmu_counters(void)
{
cpumask_t cores_map;
int cpu, rc;
get_online_cpus();
cores_map = cpu_online_cores_map();
for_each_cpu(cpu, &cores_map) {
rc = opal_imc_counters_stop(OPAL_IMC_COUNTERS_CORE,
get_hard_smp_processor_id(cpu));
if (rc)
pr_err("%s: Failed to stop Core (cpu = %d)\n",
__FUNCTION__, cpu);
}
put_online_cpus();
}
static int opal_imc_counters_probe(struct platform_device *pdev)
{
struct device_node *imc_dev = pdev->dev.of_node;
int pmu_count = 0, domain;
u32 type;
if (is_kdump_kernel()) {
disable_nest_pmu_counters();
disable_core_pmu_counters();
return -ENODEV;
}
for_each_compatible_node(imc_dev, NULL, IMC_DTB_UNIT_COMPAT) {
if (of_property_read_u32(imc_dev, "type", &type)) {
pr_warn("IMC Device without type property\n");
continue;
}
switch (type) {
case IMC_TYPE_CHIP:
domain = IMC_DOMAIN_NEST;
break;
case IMC_TYPE_CORE:
domain =IMC_DOMAIN_CORE;
break;
case IMC_TYPE_THREAD:
domain = IMC_DOMAIN_THREAD;
break;
default:
pr_warn("IMC Unknown Device type \n");
domain = -1;
break;
}
if (!imc_pmu_create(imc_dev, pmu_count, domain))
pmu_count++;
}
return 0;
}
static void opal_imc_counters_shutdown(struct platform_device *pdev)
{
disable_nest_pmu_counters();
disable_core_pmu_counters();
}
