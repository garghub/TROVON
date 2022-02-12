static int dwc3_pci_quirks(struct pci_dev *pdev)
{
if (pdev->vendor == PCI_VENDOR_ID_AMD &&
pdev->device == PCI_DEVICE_ID_AMD_NL_USB) {
struct dwc3_platform_data pdata;
memset(&pdata, 0, sizeof(pdata));
pdata.has_lpm_erratum = true;
pdata.lpm_nyet_threshold = 0xf;
pdata.u2exit_lfps_quirk = true;
pdata.u2ss_inp3_quirk = true;
pdata.req_p1p2p3_quirk = true;
pdata.del_p1p2p3_quirk = true;
pdata.del_phy_power_chg_quirk = true;
pdata.lfps_filter_quirk = true;
pdata.rx_detect_poll_quirk = true;
pdata.tx_de_emphasis_quirk = true;
pdata.tx_de_emphasis = 1;
pdata.disable_scramble_quirk = true;
pdata.dis_u3_susphy_quirk = true;
pdata.dis_u2_susphy_quirk = true;
return platform_device_add_data(pci_get_drvdata(pdev), &pdata,
sizeof(pdata));
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
pdev->device == PCI_DEVICE_ID_INTEL_BYT) {
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
pci_set_drvdata(pci, dwc3);
ret = dwc3_pci_quirks(pci);
if (ret)
goto err;
dwc3->dev.parent = dev;
ret = platform_device_add(dwc3);
if (ret) {
dev_err(dev, "failed to register dwc3 device\n");
goto err;
}
return 0;
err:
platform_device_put(dwc3);
return ret;
}
static void dwc3_pci_remove(struct pci_dev *pci)
{
acpi_dev_remove_driver_gpios(ACPI_COMPANION(&pci->dev));
platform_device_unregister(pci_get_drvdata(pci));
}
