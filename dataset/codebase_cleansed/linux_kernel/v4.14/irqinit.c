void __init init_ISA_irqs(void)
{
struct irq_chip *chip = legacy_pic->chip;
int i;
#if defined(CONFIG_X86_64) || defined(CONFIG_X86_LOCAL_APIC)
init_bsp_APIC();
#endif
legacy_pic->init(0);
for (i = 0; i < nr_legacy_irqs(); i++)
irq_set_chip_and_handler(i, chip, handle_level_irq);
}
void __init init_IRQ(void)
{
int i;
for (i = 0; i < nr_legacy_irqs(); i++)
per_cpu(vector_irq, 0)[ISA_IRQ_VECTOR(i)] = irq_to_desc(i);
x86_init.irqs.intr_init();
}
void __init native_init_IRQ(void)
{
x86_init.irqs.pre_vector_init();
idt_setup_apic_and_irq_gates();
if (!acpi_ioapic && !of_ioapic && nr_legacy_irqs())
setup_irq(2, &irq2);
irq_ctx_init(smp_processor_id());
}
