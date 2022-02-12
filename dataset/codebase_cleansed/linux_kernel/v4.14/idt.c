static inline void idt_init_desc(gate_desc *gate, const struct idt_data *d)
{
unsigned long addr = (unsigned long) d->addr;
gate->offset_low = (u16) addr;
gate->segment = (u16) d->segment;
gate->bits = d->bits;
gate->offset_middle = (u16) (addr >> 16);
#ifdef CONFIG_X86_64
gate->offset_high = (u32) (addr >> 32);
gate->reserved = 0;
#endif
}
static void
idt_setup_from_table(gate_desc *idt, const struct idt_data *t, int size, bool sys)
{
gate_desc desc;
for (; size > 0; t++, size--) {
idt_init_desc(&desc, t);
write_idt_entry(idt, t->vector, &desc);
if (sys)
set_bit(t->vector, used_vectors);
}
}
static void set_intr_gate(unsigned int n, const void *addr)
{
struct idt_data data;
BUG_ON(n > 0xFF);
memset(&data, 0, sizeof(data));
data.vector = n;
data.addr = addr;
data.segment = __KERNEL_CS;
data.bits.type = GATE_INTERRUPT;
data.bits.p = 1;
idt_setup_from_table(idt_table, &data, 1, false);
}
void __init idt_setup_early_traps(void)
{
idt_setup_from_table(idt_table, early_idts, ARRAY_SIZE(early_idts),
true);
load_idt(&idt_descr);
}
void __init idt_setup_traps(void)
{
idt_setup_from_table(idt_table, def_idts, ARRAY_SIZE(def_idts), true);
}
void __init idt_setup_early_pf(void)
{
idt_setup_from_table(idt_table, early_pf_idts,
ARRAY_SIZE(early_pf_idts), true);
}
void __init idt_setup_ist_traps(void)
{
idt_setup_from_table(idt_table, ist_idts, ARRAY_SIZE(ist_idts), true);
}
void __init idt_setup_debugidt_traps(void)
{
memcpy(&debug_idt_table, &idt_table, IDT_ENTRIES * 16);
idt_setup_from_table(debug_idt_table, dbg_idts, ARRAY_SIZE(dbg_idts), false);
}
void __init idt_setup_apic_and_irq_gates(void)
{
int i = FIRST_EXTERNAL_VECTOR;
void *entry;
idt_setup_from_table(idt_table, apic_idts, ARRAY_SIZE(apic_idts), true);
for_each_clear_bit_from(i, used_vectors, FIRST_SYSTEM_VECTOR) {
entry = irq_entries_start + 8 * (i - FIRST_EXTERNAL_VECTOR);
set_intr_gate(i, entry);
}
for_each_clear_bit_from(i, used_vectors, NR_VECTORS) {
#ifdef CONFIG_X86_LOCAL_APIC
set_bit(i, used_vectors);
set_intr_gate(i, spurious_interrupt);
#else
entry = irq_entries_start + 8 * (i - FIRST_EXTERNAL_VECTOR);
set_intr_gate(i, entry);
#endif
}
}
void __init idt_setup_early_handler(void)
{
int i;
for (i = 0; i < NUM_EXCEPTION_VECTORS; i++)
set_intr_gate(i, early_idt_handler_array[i]);
#ifdef CONFIG_X86_32
for ( ; i < NR_VECTORS; i++)
set_intr_gate(i, early_ignore_irq);
#endif
load_idt(&idt_descr);
}
void idt_invalidate(void *addr)
{
struct desc_ptr idt = { .address = (unsigned long) addr, .size = 0 };
load_idt(&idt);
}
void __init update_intr_gate(unsigned int n, const void *addr)
{
if (WARN_ON_ONCE(!test_bit(n, used_vectors)))
return;
set_intr_gate(n, addr);
}
void alloc_intr_gate(unsigned int n, const void *addr)
{
BUG_ON(n < FIRST_SYSTEM_VECTOR);
if (!test_and_set_bit(n, used_vectors))
set_intr_gate(n, addr);
}
