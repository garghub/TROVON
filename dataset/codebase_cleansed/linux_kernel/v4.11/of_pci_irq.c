int of_irq_parse_pci(const struct pci_dev *pdev, struct of_phandle_args *out_irq)
{
struct device_node *dn, *ppnode;
struct pci_dev *ppdev;
__be32 laddr[3];
u8 pin;
int rc;
dn = pci_device_to_OF_node(pdev);
if (dn) {
rc = of_irq_parse_one(dn, 0, out_irq);
if (!rc)
return rc;
}
rc = pci_read_config_byte(pdev, PCI_INTERRUPT_PIN, &pin);
if (rc != 0)
goto err;
if (pin == 0)
return -ENODEV;
for (;;) {
ppdev = pdev->bus->self;
if (ppdev == NULL) {
ppnode = pci_bus_to_OF_node(pdev->bus);
if (ppnode == NULL) {
rc = -EINVAL;
goto err;
}
} else {
ppnode = pci_device_to_OF_node(ppdev);
}
if (ppnode)
break;
pin = pci_swizzle_interrupt_pin(pdev, pin);
pdev = ppdev;
}
out_irq->np = ppnode;
out_irq->args_count = 1;
out_irq->args[0] = pin;
laddr[0] = cpu_to_be32((pdev->bus->number << 16) | (pdev->devfn << 8));
laddr[1] = laddr[2] = cpu_to_be32(0);
rc = of_irq_parse_raw(laddr, out_irq);
if (rc)
goto err;
return 0;
err:
if (rc == -ENOENT) {
dev_warn(&pdev->dev,
"%s: no interrupt-map found, INTx interrupts not available\n",
__func__);
pr_warn_once("%s: possibly some PCI slots don't have level triggered interrupts capability\n",
__func__);
} else {
dev_err(&pdev->dev, "%s: failed with rc=%d\n", __func__, rc);
}
return rc;
}
int of_irq_parse_and_map_pci(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct of_phandle_args oirq;
int ret;
ret = of_irq_parse_pci(dev, &oirq);
if (ret)
return 0;
return irq_create_of_mapping(&oirq);
}
