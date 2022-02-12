static int dwc3_pci_quirks(struct pci_dev *pdev, struct platform_device *dwc3)
{
if (pdev->vendor == PCI_VENDOR_ID_AMD &&
pdev->device == PCI_DEVICE_ID_AMD_NL_USB) {
struct property_entry properties[] = {
PROPERTY_ENTRY_BOOL("snps,has-lpm-erratum"),
PROPERTY_ENTRY_U8("snps,lpm-nyet-threshold", 0xf),
PROPERTY_ENTRY_BOOL("snps,u2exit_lfps_quirk"),
PROPERTY_ENTRY_BOOL("snps,u2ss_inp3_quirk"),
PROPERTY_ENTRY_BOOL("snps,req_p1p2p3_quirk"),
PROPERTY_ENTRY_BOOL("snps,del_p1p2p3_quirk"),
PROPERTY_ENTRY_BOOL("snps,del_phy_power_chg_quirk"),
PROPERTY_ENTRY_BOOL("snps,lfps_filter_quirk"),
PROPERTY_ENTRY_BOOL("snps,rx_detect_poll_quirk"),
PROPERTY_ENTRY_BOOL("snps,tx_de_emphasis_quirk"),
PROPERTY_ENTRY_U8("snps,tx_de_emphasis", 1),
PROPERTY_ENTRY_BOOL("snps,disable_scramble_quirk"),
PROPERTY_ENTRY_BOOL("snps,dis_u3_susphy_quirk"),
PROPERTY_ENTRY_BOOL("snps,dis_u2_susphy_quirk"),
{ },
};
return platform_device_add_properties(dwc3, properties);
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL) {
int ret;
struct property_entry properties[] = {
PROPERTY_ENTRY_STRING("dr-mode", "peripheral"),
{ }
};
ret = platform_device_add_properties(dwc3, properties);
if (ret < 0)
return ret;
if (pdev->device == PCI_DEVICE_ID_INTEL_BYT) {
struct gpio_desc *gpio;
acpi_dev_add_driver_gpios(ACPI_COMPANION(&pdev->dev),
acpi_dwc3_byt_gpios);
gpio = gpiod_get_optional(&pdev->dev, "cs", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
gpiod_set_value_cansleep(gpio, 1);
gpiod_put(gpio);
gpio = gpiod_get_optional(&pdev->dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
if (gpio) {
gpiod_set_value_cansleep(gpio, 1);
gpiod_put(gpio);
usleep_range(10000, 11000);
}
}
}
if (pdev->vendor == PCI_VENDOR_ID_SYNOPSYS &&
(pdev->device == PCI_DEVICE_ID_SYNOPSYS_HAPSUSB3 ||
pdev->device == PCI_DEVICE_ID_SYNOPSYS_HAPSUSB3_AXI ||
pdev->device == PCI_DEVICE_ID_SYNOPSYS_HAPSUSB31)) {
struct property_entry properties[] = {
PROPERTY_ENTRY_BOOL("snps,usb3_lpm_capable"),
PROPERTY_ENTRY_BOOL("snps,has-lpm-erratum"),
PROPERTY_ENTRY_BOOL("snps,dis_enblslpm_quirk"),
{ },
};
return platform_device_add_properties(dwc3, properties);
}
return 0;
}
static int dwc3_pci_probe(struct pci_dev *pci,
const struct pci_device_id *id)
{
struct resource res[2];
struct platform_device *dwc3;
int ret;
struct device *dev = &pci->dev;
ret = pcim_enable_device(pci);
if (ret) {
dev_err(dev, "failed to enable pci device\n");
return -ENODEV;
}
pci_set_master(pci);
dwc3 = platform_device_alloc("dwc3", PLATFORM_DEVID_AUTO);
if (!dwc3) {
dev_err(dev, "couldn't allocate dwc3 device\n");
return -ENOMEM;
}
memset(res, 0x00, sizeof(struct resource) * ARRAY_SIZE(res));
res[0].start = pci_resource_start(pci, 0);
res[0].end = pci_resource_end(pci, 0);
res[0].name = "dwc_usb3";
res[0].flags = IORESOURCE_MEM;
res[1].start = pci->irq;
res[1].name = "dwc_usb3";
res[1].flags = IORESOURCE_IRQ;
ret = platform_device_add_resources(dwc3, res, ARRAY_SIZE(res));
if (ret) {
dev_err(dev, "couldn't add resources to dwc3 device\n");
return ret;
}
dwc3->dev.parent = dev;
ACPI_COMPANION_SET(&dwc3->dev, ACPI_COMPANION(dev));
ret = dwc3_pci_quirks(pci, dwc3);
if (ret)
goto err;
ret = platform_device_add(dwc3);
if (ret) {
dev_err(dev, "failed to register dwc3 device\n");
goto err;
}
device_init_wakeup(dev, true);
device_set_run_wake(dev, true);
pci_set_drvdata(pci, dwc3);
pm_runtime_put(dev);
return 0;
err:
platform_device_put(dwc3);
return ret;
}
static void dwc3_pci_remove(struct pci_dev *pci)
{
device_init_wakeup(&pci->dev, false);
pm_runtime_get(&pci->dev);
acpi_dev_remove_driver_gpios(ACPI_COMPANION(&pci->dev));
platform_device_unregister(pci_get_drvdata(pci));
}
static int dwc3_pci_runtime_suspend(struct device *dev)
{
if (device_run_wake(dev))
return 0;
return -EBUSY;
}
static int dwc3_pci_runtime_resume(struct device *dev)
{
struct platform_device *dwc3 = dev_get_drvdata(dev);
return pm_runtime_get(&dwc3->dev);
}
static int dwc3_pci_pm_dummy(struct device *dev)
{
return 0;
}
