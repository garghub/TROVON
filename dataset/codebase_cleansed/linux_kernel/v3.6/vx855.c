static __devinit int vx855_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int ret;
u16 gpio_io_offset;
ret = pci_enable_device(pdev);
if (ret)
return -ENODEV;
pci_read_config_word(pdev, VX855_CFG_PMIO_OFFSET, &gpio_io_offset);
if (!gpio_io_offset) {
dev_warn(&pdev->dev,
"BIOS did not assign PMIO base offset?!?\n");
ret = -ENODEV;
goto out;
}
gpio_io_offset &= 0xff80;
vx855_gpio_resources[0].start = gpio_io_offset + VX855_PMIO_R_GPI;
vx855_gpio_resources[0].end = vx855_gpio_resources[0].start + 3;
vx855_gpio_resources[1].start = gpio_io_offset + VX855_PMIO_R_GPO;
vx855_gpio_resources[1].end = vx855_gpio_resources[1].start + 3;
ret = mfd_add_devices(&pdev->dev, -1, vx855_cells, ARRAY_SIZE(vx855_cells),
NULL, 0, NULL);
return -ENODEV;
out:
pci_disable_device(pdev);
return ret;
}
static void __devexit vx855_remove(struct pci_dev *pdev)
{
mfd_remove_devices(&pdev->dev);
pci_disable_device(pdev);
}
