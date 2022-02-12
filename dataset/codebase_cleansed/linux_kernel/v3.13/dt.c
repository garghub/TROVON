void __init *xlp_dt_init(void *fdtp)
{
if (!fdtp) {
switch (current_cpu_data.processor_id & 0xff00) {
#ifdef CONFIG_DT_XLP_FVP
case PRID_IMP_NETLOGIC_XLP2XX:
fdtp = __dtb_xlp_fvp_begin;
break;
#endif
#ifdef CONFIG_DT_XLP_SVP
case PRID_IMP_NETLOGIC_XLP3XX:
fdtp = __dtb_xlp_svp_begin;
break;
#endif
#ifdef CONFIG_DT_XLP_EVP
case PRID_IMP_NETLOGIC_XLP8XX:
fdtp = __dtb_xlp_evp_begin;
break;
#endif
default:
fdtp = __dtb_start;
break;
}
}
xlp_fdt_blob = fdtp;
return fdtp;
}
void __init xlp_early_init_devtree(void)
{
__dt_setup_arch(xlp_fdt_blob);
strlcpy(arcs_cmdline, boot_command_line, COMMAND_LINE_SIZE);
}
void __init device_tree_init(void)
{
unsigned long base, size;
struct boot_param_header *fdtp = xlp_fdt_blob;
if (!fdtp)
return;
base = virt_to_phys(fdtp);
size = be32_to_cpu(fdtp->totalsize);
reserve_bootmem(base, size, BOOTMEM_DEFAULT);
unflatten_device_tree();
free_bootmem(base, size);
}
int __init xlp8xx_ds_publish_devices(void)
{
if (!of_have_populated_dt())
return 0;
return of_platform_bus_probe(NULL, xlp_ids, NULL);
}
