static int dwc3_pci_quirks(struct dwc3_pci *dwc)
{
struct platform_device *dwc3 = dwc->dwc3;
struct pci_dev *pdev = dwc->pci;
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
PROPERTY_ENTRY_BOOL("linux,sysdev_is_parent"),
{ },
};
return platform_device_add_properties(dwc3, properties);
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL) {
int ret;
struct property_entry properties[] = {
PROPERTY_ENTRY_STRING("dr_mode", "peripheral"),
PROPERTY_ENTRY_BOOL("linux,sysdev_is_parent"),
{ }
};
ret = platform_device_add_properties(dwc3, properties);
if (ret < 0)
return ret;
if (pdev->device == PCI_DEVICE_ID_INTEL_BXT ||
pdev->device == PCI_DEVICE_ID_INTEL_BXT_M) {
guid_parse(PCI_INTEL_BXT_DSM_GUID, &dwc->guid);
dwc->has_dsm_for_pm = true;
}
if (pdev->device == PCI_DEVICE_ID_INTEL_BYT) {
struct gpio_desc *gpio;
ret = devm_acpi_dev_add_driver_gpios(&pdev->dev,
acpi_dwc3_byt_gpios);
if (ret)
dev_dbg(&pdev->dev, "failed to add mapping table\n");
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
PROPERTY_ENTRY_BOOL("linux,sysdev_is_parent"),
{ },
};
return platform_device_add_properties(dwc3, properties);
}
return 0;
}
static int dwc3_pci_probe(struct pci_dev *pci,
const struct pci_device_id *id)
{
struct dwc3_pci *dwc;
struct resource res[2];
int ret;
struct device *dev = &pci->dev;
ret = pcim_enable_device(pci);
if (ret) {
dev_err(dev, "failed to enable pci device\n");
return -ENODEV;
}
pci_set_master(pci);
dwc = devm_kzalloc(dev, sizeof(*dwc), GFP_KERNEL);
if (!dwc)
return -ENOMEM;
dwc->dwc3 = platform_device_alloc("dwc3", PLATFORM_DEVID_AUTO);
if (!dwc->dwc3)
return -ENOMEM;
memset(res, 0x00, sizeof(struct resource) * ARRAY_SIZE(res));
res[0].start = pci_resource_start(pci, 0);
res[0].end = pci_resource_end(pci, 0);
res[0].name = "dwc_usb3";
res[0].flags = IORESOURCE_MEM;
res[1].start = pci->irq;
res[1].name = "dwc_usb3";
res[1].flags = IORESOURCE_IRQ;
ret = platform_device_add_resources(dwc->dwc3, res, ARRAY_SIZE(res));
if (ret) {
dev_err(dev, "couldn't add resources to dwc3 device\n");
return ret;
}
dwc->pci = pci;
dwc->dwc3->dev.parent = dev;
ACPI_COMPANION_SET(&dwc->dwc3->dev, ACPI_COMPANION(dev));
ret = dwc3_pci_quirks(dwc);
if (ret)
goto err;
ret = platform_device_add(dwc->dwc3);
if (ret) {
dev_err(dev, "failed to register dwc3 device\n");
goto err;
}
device_init_wakeup(dev, true);
pci_set_drvdata(pci, dwc);
pm_runtime_put(dev);
return 0;
err:
platform_device_put(dwc->dwc3);
return ret;
}
static void dwc3_pci_remove(struct pci_dev *pci)
{
struct dwc3_pci *dwc = pci_get_drvdata(pci);
device_init_wakeup(&pci->dev, false);
pm_runtime_get(&pci->dev);
platform_device_unregister(dwc->dwc3);
}
static int dwc3_pci_dsm(struct dwc3_pci *dwc, int param)
{
union acpi_object *obj;
union acpi_object tmp;
union acpi_object argv4 = ACPI_INIT_DSM_ARGV4(1, &tmp);
if (!dwc->has_dsm_for_pm)
return 0;
tmp.type = ACPI_TYPE_INTEGER;
tmp.integer.value = param;
obj = acpi_evaluate_dsm(ACPI_HANDLE(&dwc->pci->dev), &dwc->guid,
1, PCI_INTEL_BXT_FUNC_PMU_PWR, &argv4);
if (!obj) {
dev_err(&dwc->pci->dev, "failed to evaluate _DSM\n");
return -EIO;
}
ACPI_FREE(obj);
return 0;
}
static int dwc3_pci_runtime_suspend(struct device *dev)
{
struct dwc3_pci *dwc = dev_get_drvdata(dev);
if (device_can_wakeup(dev))
return dwc3_pci_dsm(dwc, PCI_INTEL_BXT_STATE_D3);
return -EBUSY;
}
static int dwc3_pci_runtime_resume(struct device *dev)
{
struct dwc3_pci *dwc = dev_get_drvdata(dev);
struct platform_device *dwc3 = dwc->dwc3;
int ret;
ret = dwc3_pci_dsm(dwc, PCI_INTEL_BXT_STATE_D0);
if (ret)
return ret;
return pm_runtime_get(&dwc3->dev);
}
static int dwc3_pci_suspend(struct device *dev)
{
struct dwc3_pci *dwc = dev_get_drvdata(dev);
return dwc3_pci_dsm(dwc, PCI_INTEL_BXT_STATE_D3);
}
static int dwc3_pci_resume(struct device *dev)
{
struct dwc3_pci *dwc = dev_get_drvdata(dev);
return dwc3_pci_dsm(dwc, PCI_INTEL_BXT_STATE_D0);
}
