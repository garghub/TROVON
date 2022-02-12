static int mrfld_power_btn_scu_status_change(struct notifier_block *nb,
unsigned long code, void *data)
{
if (code == SCU_DOWN) {
platform_device_unregister(&mrfld_power_btn_dev);
return 0;
}
return platform_device_register(&mrfld_power_btn_dev);
}
static int __init register_mrfld_power_btn(void)
{
if (intel_mid_identify_cpu() != INTEL_MID_CPU_CHIP_TANGIER)
return -ENODEV;
intel_scu_notifier_add(&mrfld_power_btn_scu_notifier);
return 0;
}
static void __init *mrfld_power_btn_platform_data(void *info)
{
struct resource *res = mrfld_power_btn_resources;
struct sfi_device_table_entry *pentry = info;
res->start = res->end = pentry->irq;
return NULL;
}
