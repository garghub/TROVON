void __init *xlp_dt_init(void *fdtp)
{
if (!fdtp) {
switch (current_cpu_data.processor_id & PRID_IMP_MASK) {
#ifdef CONFIG_DT_XLP_RVP
case PRID_IMP_NETLOGIC_XLP5XX:
fdtp = __dtb_xlp_rvp_begin;
break;
#endif
#ifdef CONFIG_DT_XLP_GVP
case PRID_IMP_NETLOGIC_XLP9XX:
fdtp = __dtb_xlp_gvp_begin;
break;
#endif
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
}
void __init device_tree_init(void)
{
unflatten_and_copy_device_tree();
}
int __init xlp8xx_ds_publish_devices(void)
{
if (!of_have_populated_dt())
return 0;
return of_platform_bus_probe(NULL, xlp_ids, NULL);
}
