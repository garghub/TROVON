static void mpic_pasemi_msi_mask_irq(struct irq_data *data)
{
pr_debug("mpic_pasemi_msi_mask_irq %d\n", data->irq);
mask_msi_irq(data);
mpic_mask_irq(data);
}
static void mpic_pasemi_msi_unmask_irq(struct irq_data *data)
{
pr_debug("mpic_pasemi_msi_unmask_irq %d\n", data->irq);
mpic_unmask_irq(data);
unmask_msi_irq(data);
}
static int pasemi_msi_check_device(struct pci_dev *pdev, int nvec, int type)
{
if (type == PCI_CAP_ID_MSIX)
pr_debug("pasemi_msi: MSI-X untested, trying anyway\n");
return 0;
}
static void pasemi_msi_teardown_msi_irqs(struct pci_dev *pdev)
{
struct msi_desc *entry;
pr_debug("pasemi_msi_teardown_msi_irqs, pdev %p\n", pdev);
list_for_each_entry(entry, &pdev->msi_list, list) {
if (entry->irq == NO_IRQ)
continue;
irq_set_msi_desc(entry->irq, NULL);
msi_bitmap_free_hwirqs(&msi_mpic->msi_bitmap,
virq_to_hw(entry->irq), ALLOC_CHUNK);
irq_dispose_mapping(entry->irq);
}
return;
}
static int pasemi_msi_setup_msi_irqs(struct pci_dev *pdev, int nvec, int type)
{
unsigned int virq;
struct msi_desc *entry;
struct msi_msg msg;
int hwirq;
pr_debug("pasemi_msi_setup_msi_irqs, pdev %p nvec %d type %d\n",
pdev, nvec, type);
msg.address_hi = 0;
msg.address_lo = PASEMI_MSI_ADDR;
list_for_each_entry(entry, &pdev->msi_list, list) {
hwirq = msi_bitmap_alloc_hwirqs(&msi_mpic->msi_bitmap,
ALLOC_CHUNK);
if (hwirq < 0) {
pr_debug("pasemi_msi: failed allocating hwirq\n");
return hwirq;
}
virq = irq_create_mapping(msi_mpic->irqhost, hwirq);
if (virq == NO_IRQ) {
pr_debug("pasemi_msi: failed mapping hwirq 0x%x\n",
hwirq);
msi_bitmap_free_hwirqs(&msi_mpic->msi_bitmap, hwirq,
ALLOC_CHUNK);
return -ENOSPC;
}
mpic_set_vector(virq, 0);
irq_set_msi_desc(virq, entry);
irq_set_chip(virq, &mpic_pasemi_msi_chip);
irq_set_irq_type(virq, IRQ_TYPE_EDGE_RISING);
pr_debug("pasemi_msi: allocated virq 0x%x (hw 0x%x) " \
"addr 0x%x\n", virq, hwirq, msg.address_lo);
msg.data = hwirq-0x200;
write_msi_msg(virq, &msg);
}
return 0;
}
int mpic_pasemi_msi_init(struct mpic *mpic)
{
int rc;
if (!mpic->irqhost->of_node ||
!of_device_is_compatible(mpic->irqhost->of_node,
"pasemi,pwrficient-openpic"))
return -ENODEV;
rc = mpic_msi_init_allocator(mpic);
if (rc) {
pr_debug("pasemi_msi: Error allocating bitmap!\n");
return rc;
}
pr_debug("pasemi_msi: Registering PA Semi MPIC MSI callbacks\n");
msi_mpic = mpic;
WARN_ON(ppc_md.setup_msi_irqs);
ppc_md.setup_msi_irqs = pasemi_msi_setup_msi_irqs;
ppc_md.teardown_msi_irqs = pasemi_msi_teardown_msi_irqs;
ppc_md.msi_check_device = pasemi_msi_check_device;
return 0;
}
