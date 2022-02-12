static int __init reserve_mem_mach(unsigned long addr, unsigned long size)
{
return reserve_bootmem(addr, size, BOOTMEM_DEFAULT);
}
void __init free_mem_mach(unsigned long addr, unsigned long size)
{
return free_bootmem(addr, size);
}
void __init device_tree_init(void)
{
unsigned long base, size;
if (!initial_boot_params)
return;
base = virt_to_phys((void *)initial_boot_params);
size = be32_to_cpu(initial_boot_params->totalsize);
reserve_mem_mach(base, size);
unflatten_device_tree();
free_mem_mach(base, size);
}
