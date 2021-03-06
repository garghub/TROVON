static int ppc4xx_msi_init_allocator(struct platform_device *dev,
struct ppc4xx_msi *msi_data)
{
int err;
err = msi_bitmap_alloc(&msi_data->bitmap, msi_irqs,
dev->dev.of_node);
if (err)
return err;
err = msi_bitmap_reserve_dt_hwirqs(&msi_data->bitmap);
if (err < 0) {
msi_bitmap_free(&msi_data->bitmap);
return err;
}
return 0;
}
static int ppc4xx_setup_msi_irqs(struct pci_dev *dev, int nvec, int type)
{
int int_no = -ENOMEM;
unsigned int virq;
struct msi_msg msg;
struct msi_desc *entry;
struct ppc4xx_msi *msi_data = &ppc4xx_msi;
dev_dbg(&dev->dev, "PCIE-MSI:%s called. vec %x type %d\n",
__func__, nvec, type);
if (type == PCI_CAP_ID_MSIX)
pr_debug("ppc4xx msi: MSI-X untested, trying anyway.\n");
msi_data->msi_virqs = kmalloc((msi_irqs) * sizeof(int), GFP_KERNEL);
if (!msi_data->msi_virqs)
return -ENOMEM;
list_for_each_entry(entry, &dev->msi_list, list) {
int_no = msi_bitmap_alloc_hwirqs(&msi_data->bitmap, 1);
if (int_no >= 0)
break;
if (int_no < 0) {
pr_debug("%s: fail allocating msi interrupt\n",
__func__);
}
virq = irq_of_parse_and_map(msi_data->msi_dev, int_no);
if (virq == NO_IRQ) {
dev_err(&dev->dev, "%s: fail mapping irq\n", __func__);
msi_bitmap_free_hwirqs(&msi_data->bitmap, int_no, 1);
return -ENOSPC;
}
dev_dbg(&dev->dev, "%s: virq = %d\n", __func__, virq);
msg.address_hi = msi_data->msi_addr_hi;
msg.address_lo = msi_data->msi_addr_lo;
irq_set_msi_desc(virq, entry);
msg.data = int_no;
pci_write_msi_msg(virq, &msg);
}
return 0;
}
void ppc4xx_teardown_msi_irqs(struct pci_dev *dev)
{
struct msi_desc *entry;
struct ppc4xx_msi *msi_data = &ppc4xx_msi;
dev_dbg(&dev->dev, "PCIE-MSI: tearing down msi irqs\n");
list_for_each_entry(entry, &dev->msi_list, list) {
if (entry->irq == NO_IRQ)
continue;
irq_set_msi_desc(entry->irq, NULL);
msi_bitmap_free_hwirqs(&msi_data->bitmap,
virq_to_hw(entry->irq), 1);
irq_dispose_mapping(entry->irq);
}
}
static int ppc4xx_setup_pcieh_hw(struct platform_device *dev,
struct resource res, struct ppc4xx_msi *msi)
{
const u32 *msi_data;
const u32 *msi_mask;
const u32 *sdr_addr;
dma_addr_t msi_phys;
void *msi_virt;
sdr_addr = of_get_property(dev->dev.of_node, "sdr-base", NULL);
if (!sdr_addr)
return -1;
mtdcri(SDR0, *sdr_addr, upper_32_bits(res.start));
mtdcri(SDR0, *sdr_addr + 1, lower_32_bits(res.start));
msi->msi_dev = of_find_node_by_name(NULL, "ppc4xx-msi");
if (!msi->msi_dev)
return -ENODEV;
msi->msi_regs = of_iomap(msi->msi_dev, 0);
if (!msi->msi_regs) {
dev_err(&dev->dev, "of_iomap problem failed\n");
return -ENOMEM;
}
dev_dbg(&dev->dev, "PCIE-MSI: msi register mapped 0x%x 0x%x\n",
(u32) (msi->msi_regs + PEIH_TERMADH), (u32) (msi->msi_regs));
msi_virt = dma_alloc_coherent(&dev->dev, 64, &msi_phys, GFP_KERNEL);
if (!msi_virt)
return -ENOMEM;
msi->msi_addr_hi = upper_32_bits(msi_phys);
msi->msi_addr_lo = lower_32_bits(msi_phys & 0xffffffff);
dev_dbg(&dev->dev, "PCIE-MSI: msi address high 0x%x, low 0x%x\n",
msi->msi_addr_hi, msi->msi_addr_lo);
out_be32(msi->msi_regs + PEIH_TERMADH, msi->msi_addr_hi);
out_be32(msi->msi_regs + PEIH_TERMADL, msi->msi_addr_lo);
msi_data = of_get_property(dev->dev.of_node, "msi-data", NULL);
if (!msi_data)
return -1;
msi_mask = of_get_property(dev->dev.of_node, "msi-mask", NULL);
if (!msi_mask)
return -1;
out_be32(msi->msi_regs + PEIH_MSIED, *msi_data);
out_be32(msi->msi_regs + PEIH_MSIMK, *msi_mask);
dma_free_coherent(&dev->dev, 64, msi_virt, msi_phys);
return 0;
}
static int ppc4xx_of_msi_remove(struct platform_device *dev)
{
struct ppc4xx_msi *msi = dev->dev.platform_data;
int i;
int virq;
for (i = 0; i < msi_irqs; i++) {
virq = msi->msi_virqs[i];
if (virq != NO_IRQ)
irq_dispose_mapping(virq);
}
if (msi->bitmap.bitmap)
msi_bitmap_free(&msi->bitmap);
iounmap(msi->msi_regs);
of_node_put(msi->msi_dev);
kfree(msi);
return 0;
}
static int ppc4xx_msi_probe(struct platform_device *dev)
{
struct ppc4xx_msi *msi;
struct resource res;
int err = 0;
dev_dbg(&dev->dev, "PCIE-MSI: Setting up MSI support...\n");
msi = kzalloc(sizeof(struct ppc4xx_msi), GFP_KERNEL);
if (!msi) {
dev_err(&dev->dev, "No memory for MSI structure\n");
return -ENOMEM;
}
dev->dev.platform_data = msi;
err = of_address_to_resource(dev->dev.of_node, 0, &res);
if (err) {
dev_err(&dev->dev, "%s resource error!\n",
dev->dev.of_node->full_name);
goto error_out;
}
msi_irqs = of_irq_count(dev->dev.of_node);
if (!msi_irqs)
return -ENODEV;
if (ppc4xx_setup_pcieh_hw(dev, res, msi))
goto error_out;
err = ppc4xx_msi_init_allocator(dev, msi);
if (err) {
dev_err(&dev->dev, "Error allocating MSI bitmap\n");
goto error_out;
}
ppc4xx_msi = *msi;
ppc_md.setup_msi_irqs = ppc4xx_setup_msi_irqs;
ppc_md.teardown_msi_irqs = ppc4xx_teardown_msi_irqs;
return err;
error_out:
ppc4xx_of_msi_remove(dev);
return err;
}
static __init int ppc4xx_msi_init(void)
{
return platform_driver_register(&ppc4xx_msi_driver);
}
