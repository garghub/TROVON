void __init ipc_device_handler(struct sfi_device_table_entry *pentry,
struct devs_id *dev)
{
struct platform_device *pdev;
void *pdata = NULL;
static struct resource res __initdata = {
.name = "IRQ",
.flags = IORESOURCE_IRQ,
};
pr_debug("IPC bus, name = %16.16s, irq = 0x%2x\n",
pentry->name, pentry->irq);
if (dev != NULL)
pdata = dev->get_platform_data(pentry);
if (intel_mid_has_msic())
return;
pdev = platform_device_alloc(pentry->name, 0);
if (pdev == NULL) {
pr_err("out of memory for SFI platform device '%s'.\n",
pentry->name);
return;
}
res.start = pentry->irq;
platform_device_add_resources(pdev, &res, 1);
pdev->dev.platform_data = pdata;
intel_scu_device_register(pdev);
}
