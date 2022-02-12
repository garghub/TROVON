int vector_used_by_percpu_irq(unsigned int vector)
{
int cpu;
for_each_online_cpu(cpu) {
if (per_cpu(vector_irq, cpu)[vector] > VECTOR_UNDEFINED)
return 1;
}
return 0;
}
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
per_cpu(vector_irq, 0)[IRQ0_VECTOR + i] = i;
x86_init.irqs.intr_init();
}
static void __init smp_intr_init(void)
{
#ifdef CONFIG_SMP
alloc_intr_gate(RESCHEDULE_VECTOR, reschedule_interrupt);
alloc_intr_gate(CALL_FUNCTION_VECTOR, call_function_interrupt);
alloc_intr_gate(CALL_FUNCTION_SINGLE_VECTOR,
call_function_single_interrupt);
set_intr_gate(IRQ_MOVE_CLEANUP_VECTOR, irq_move_cleanup_interrupt);
set_bit(IRQ_MOVE_CLEANUP_VECTOR, used_vectors);
alloc_intr_gate(REBOOT_VECTOR, reboot_interrupt);
#endif
}
static void __init apic_intr_init(void)
{
smp_intr_init();
#ifdef CONFIG_X86_THERMAL_VECTOR
alloc_intr_gate(THERMAL_APIC_VECTOR, thermal_interrupt);
#endif
#ifdef CONFIG_X86_MCE_THRESHOLD
alloc_intr_gate(THRESHOLD_APIC_VECTOR, threshold_interrupt);
#endif
#ifdef CONFIG_X86_LOCAL_APIC
alloc_intr_gate(LOCAL_TIMER_VECTOR, apic_timer_interrupt);
alloc_intr_gate(X86_PLATFORM_IPI_VECTOR, x86_platform_ipi);
#ifdef CONFIG_HAVE_KVM
alloc_intr_gate(POSTED_INTR_VECTOR, kvm_posted_intr_ipi);
#endif
alloc_intr_gate(SPURIOUS_APIC_VECTOR, spurious_interrupt);
alloc_intr_gate(ERROR_APIC_VECTOR, error_interrupt);
# ifdef CONFIG_IRQ_WORK
alloc_intr_gate(IRQ_WORK_VECTOR, irq_work_interrupt);
# endif
#endif
}
void __init native_init_IRQ(void)
{
int i;
x86_init.irqs.pre_vector_init();
apic_intr_init();
i = FIRST_EXTERNAL_VECTOR;
#ifndef CONFIG_X86_LOCAL_APIC
#define first_system_vector NR_VECTORS
#endif
for_each_clear_bit_from(i, used_vectors, first_system_vector) {
set_intr_gate(i, interrupt[i - FIRST_EXTERNAL_VECTOR]);
}
#ifdef CONFIG_X86_LOCAL_APIC
for_each_clear_bit_from(i, used_vectors, NR_VECTORS)
set_intr_gate(i, spurious_interrupt);
#endif
if (!acpi_ioapic && !of_ioapic && nr_legacy_irqs())
setup_irq(2, &irq2);
#ifdef CONFIG_X86_32
irq_ctx_init(smp_processor_id());
#endif
}
