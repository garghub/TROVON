void x86_init_noop(void) { }
void __init x86_init_uint_noop(unsigned int unused) { }
int __init iommu_init_noop(void) { return 0; }
void iommu_shutdown_noop(void) { }
static void default_nmi_init(void) { }
static int default_i8042_detect(void) { return 1; }
int arch_setup_msi_irqs(struct pci_dev *dev, int nvec, int type)
{
return x86_msi.setup_msi_irqs(dev, nvec, type);
}
void arch_teardown_msi_irqs(struct pci_dev *dev)
{
x86_msi.teardown_msi_irqs(dev);
}
void arch_teardown_msi_irq(unsigned int irq)
{
x86_msi.teardown_msi_irq(irq);
}
void arch_restore_msi_irqs(struct pci_dev *dev, int irq)
{
x86_msi.restore_msi_irqs(dev, irq);
}
