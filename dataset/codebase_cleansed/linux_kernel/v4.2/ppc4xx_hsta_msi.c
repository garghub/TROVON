static int hsta_setup_msi_irqs(struct pci_dev *dev, int nvec, int type)
{
struct msi_msg msg;
struct msi_desc *entry;
int irq, hwirq;
u64 addr;
if (type == PCI_CAP_ID_MSIX) {
pr_debug("%s: MSI-X not supported.\n", __func__);
return -EINVAL;
}
list_for_each_entry(entry, &dev->msi_list, list) {
irq = msi_bitmap_alloc_hwirqs(&ppc4xx_hsta_msi.bmp, 1);
if (irq < 0) {
pr_debug("%s: Failed to allocate msi interrupt\n",
__func__);
return irq;
}
hwirq = ppc4xx_hsta_msi.irq_map[irq];
if (hwirq == NO_IRQ) {
pr_err("%s: Failed mapping irq %d\n", __func__, irq);
return -EINVAL;
}
addr = ppc4xx_hsta_msi.address + irq*0x10;
msg.address_hi = upper_32_bits(addr);
msg.address_lo = lower_32_bits(addr);
msg.data = 0;
pr_debug("%s: Setup irq %d (0x%0llx)\n", __func__, hwirq,
(((u64) msg.address_hi) << 32) | msg.address_lo);
if (irq_set_msi_desc(hwirq, entry)) {
pr_err(
"%s: Invalid hwirq %d specified in device tree\n",
__func__, hwirq);
msi_bitmap_free_hwirqs(&ppc4xx_hsta_msi.bmp, irq, 1);
return -EINVAL;
}
pci_write_msi_msg(hwirq, &msg);
}
return 0;
}
static int hsta_find_hwirq_offset(int hwirq)
{
int irq;
for (irq = 0; irq < ppc4xx_hsta_msi.irq_count; irq++)
if (ppc4xx_hsta_msi.irq_map[irq] == hwirq)
return irq;
return -EINVAL;
}
static void hsta_teardown_msi_irqs(struct pci_dev *dev)
{
struct msi_desc *entry;
int irq;
list_for_each_entry(entry, &dev->msi_list, list) {
if (entry->irq == NO_IRQ)
continue;
irq = hsta_find_hwirq_offset(entry->irq);
BUG_ON(irq < 0);
irq_set_msi_desc(entry->irq, NULL);
msi_bitmap_free_hwirqs(&ppc4xx_hsta_msi.bmp, irq, 1);
pr_debug("%s: Teardown IRQ %u (index %u)\n", __func__,
entry->irq, irq);
}
}
static int hsta_msi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *mem;
int irq, ret, irq_count;
struct pci_controller *phb;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (IS_ERR(mem)) {
dev_err(dev, "Unable to get mmio space\n");
return -EINVAL;
}
irq_count = of_irq_count(dev->of_node);
if (!irq_count) {
dev_err(dev, "Unable to find IRQ range\n");
return -EINVAL;
}
ppc4xx_hsta_msi.dev = dev;
ppc4xx_hsta_msi.address = mem->start;
ppc4xx_hsta_msi.data = ioremap(mem->start, resource_size(mem));
ppc4xx_hsta_msi.irq_count = irq_count;
if (!ppc4xx_hsta_msi.data) {
dev_err(dev, "Unable to map memory\n");
return -ENOMEM;
}
ret = msi_bitmap_alloc(&ppc4xx_hsta_msi.bmp, irq_count, dev->of_node);
if (ret)
goto out;
ppc4xx_hsta_msi.irq_map = kmalloc(sizeof(int) * irq_count, GFP_KERNEL);
if (IS_ERR(ppc4xx_hsta_msi.irq_map)) {
ret = -ENOMEM;
goto out1;
}
for (irq = 0; irq < irq_count; irq++) {
ppc4xx_hsta_msi.irq_map[irq] =
irq_of_parse_and_map(dev->of_node, irq);
if (ppc4xx_hsta_msi.irq_map[irq] == NO_IRQ) {
dev_err(dev, "Unable to map IRQ\n");
ret = -EINVAL;
goto out2;
}
}
list_for_each_entry(phb, &hose_list, list_node) {
phb->controller_ops.setup_msi_irqs = hsta_setup_msi_irqs;
phb->controller_ops.teardown_msi_irqs = hsta_teardown_msi_irqs;
}
return 0;
out2:
kfree(ppc4xx_hsta_msi.irq_map);
out1:
msi_bitmap_free(&ppc4xx_hsta_msi.bmp);
out:
iounmap(ppc4xx_hsta_msi.data);
return ret;
}
static int hsta_msi_init(void)
{
return platform_driver_register(&hsta_msi_driver);
}
