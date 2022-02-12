__iomem void *plat_of_remap_node(const char *node)
{
struct resource res;
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, node);
if (!np)
panic("Failed to find %s node", node);
if (of_address_to_resource(np, 0, &res))
panic("Failed to get resource for %s", node);
if ((request_mem_region(res.start,
resource_size(&res),
res.name) < 0))
panic("Failed to request resources for %s", node);
return ioremap_nocache(res.start, resource_size(&res));
}
void __init device_tree_init(void)
{
unsigned long base, size;
void *fdt_copy;
if (!initial_boot_params)
return;
base = virt_to_phys((void *)initial_boot_params);
size = be32_to_cpu(initial_boot_params->totalsize);
reserve_bootmem(base, size, BOOTMEM_DEFAULT);
fdt_copy = alloc_bootmem(size);
memcpy(fdt_copy, initial_boot_params, size);
initial_boot_params = fdt_copy;
unflatten_device_tree();
free_bootmem(base, size);
}
void __init plat_mem_setup(void)
{
set_io_port_base(KSEG1);
__dt_setup_arch(&__dtb_start);
if (soc_info.mem_size)
add_memory_region(soc_info.mem_base, soc_info.mem_size * SZ_1M,
BOOT_MEM_RAM);
else
detect_memory_region(soc_info.mem_base,
soc_info.mem_size_min * SZ_1M,
soc_info.mem_size_max * SZ_1M);
}
static int __init plat_of_setup(void)
{
static struct of_device_id of_ids[3];
int len = sizeof(of_ids[0].compatible);
if (!of_have_populated_dt())
panic("device tree not present");
strncpy(of_ids[0].compatible, soc_info.compatible, len);
strncpy(of_ids[1].compatible, "palmbus", len);
if (of_platform_populate(NULL, of_ids, NULL, NULL))
panic("failed to populate DT\n");
return 0;
}
