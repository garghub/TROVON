int kvm_irq_map_gsi(struct kvm *kvm,
struct kvm_kernel_irq_routing_entry *entries,
int gsi)
{
return 0;
}
int kvm_irq_map_chip_pin(struct kvm *kvm, unsigned int irqchip,
unsigned int pin)
{
return pin;
}
int kvm_set_irq(struct kvm *kvm, int irq_source_id,
u32 irq, int level, bool line_status)
{
unsigned int spi = irq + VGIC_NR_PRIVATE_IRQS;
trace_kvm_set_irq(irq, level, irq_source_id);
BUG_ON(!vgic_initialized(kvm));
return kvm_vgic_inject_irq(kvm, 0, spi, level);
}
int kvm_set_msi(struct kvm_kernel_irq_routing_entry *e,
struct kvm *kvm, int irq_source_id,
int level, bool line_status)
{
return 0;
}
