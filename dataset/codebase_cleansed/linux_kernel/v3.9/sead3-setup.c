const char *get_system_type(void)
{
return "MIPS SEAD3";
}
void __init plat_mem_setup(void)
{
__dt_setup_arch(&__dtb_start);
}
void __init device_tree_init(void)
{
unsigned long base, size;
if (!initial_boot_params)
return;
base = virt_to_phys((void *)initial_boot_params);
size = be32_to_cpu(initial_boot_params->totalsize);
reserve_bootmem(base, size, BOOTMEM_DEFAULT);
unflatten_device_tree();
}
