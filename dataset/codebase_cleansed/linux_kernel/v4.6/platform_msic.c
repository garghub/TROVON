static int msic_scu_status_change(struct notifier_block *nb,
unsigned long code, void *data)
{
if (code == SCU_DOWN) {
platform_device_unregister(&msic_device);
return 0;
}
return platform_device_register(&msic_device);
}
static int __init msic_init(void)
{
static struct notifier_block msic_scu_notifier = {
.notifier_call = msic_scu_status_change,
};
if (intel_mid_has_msic())
intel_scu_notifier_add(&msic_scu_notifier);
return 0;
}
void *msic_generic_platform_data(void *info, enum intel_msic_block block)
{
struct sfi_device_table_entry *entry = info;
BUG_ON(block < 0 || block >= INTEL_MSIC_BLOCK_LAST);
msic_pdata.irq[block] = entry->irq;
return NULL;
}
