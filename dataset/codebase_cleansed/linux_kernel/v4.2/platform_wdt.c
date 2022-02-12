static int tangier_probe(struct platform_device *pdev)
{
int gsi;
struct irq_alloc_info info;
struct intel_mid_wdt_pdata *pdata = pdev->dev.platform_data;
if (!pdata)
return -EINVAL;
gsi = pdata->irq;
ioapic_set_alloc_attr(&info, cpu_to_node(0), 1, 0);
if (mp_map_gsi_to_irq(gsi, IOAPIC_MAP_ALLOC, &info) <= 0) {
dev_warn(&pdev->dev, "cannot find interrupt %d in ioapic\n",
gsi);
return -EINVAL;
}
return 0;
}
static int __init register_mid_wdt(void)
{
if (intel_mid_identify_cpu() == INTEL_MID_CPU_CHIP_TANGIER) {
wdt_dev.dev.platform_data = &tangier_pdata;
return platform_device_register(&wdt_dev);
}
return -ENODEV;
}
