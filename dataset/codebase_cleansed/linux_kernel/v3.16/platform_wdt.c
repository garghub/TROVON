static int tangier_probe(struct platform_device *pdev)
{
int ioapic;
int irq;
struct intel_mid_wdt_pdata *pdata = pdev->dev.platform_data;
struct io_apic_irq_attr irq_attr = { 0 };
if (!pdata)
return -EINVAL;
irq = pdata->irq;
ioapic = mp_find_ioapic(irq);
if (ioapic >= 0) {
int ret;
irq_attr.ioapic = ioapic;
irq_attr.ioapic_pin = irq;
irq_attr.trigger = 1;
ret = io_apic_set_pci_routing(NULL, irq, &irq_attr);
if (ret)
return ret;
} else {
dev_warn(&pdev->dev, "cannot find interrupt %d in ioapic\n",
irq);
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
