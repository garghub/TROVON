asmlinkage void plat_irq_dispatch(void)
{
unsigned long pending;
int irq;
pending = read_c0_status() & read_c0_cause() & ST0_IM;
if (!pending) {
spurious_interrupt();
return;
}
pending >>= CAUSEB_IP;
while (pending) {
irq = fls(pending) - 1;
if (irq < ARRAY_SIZE(irq_wb_chan) && irq_wb_chan[irq] != -1)
ath79_ddr_wb_flush(irq_wb_chan[irq]);
do_IRQ(MIPS_CPU_IRQ_BASE + irq);
pending &= ~BIT(irq);
}
}
static int __init ar79_cpu_intc_of_init(
struct device_node *node, struct device_node *parent)
{
int err, i, count;
count = of_count_phandle_with_args(
node, "qca,ddr-wb-channels", "#qca,ddr-wb-channel-cells");
for (i = 0; i < count; i++) {
struct of_phandle_args args;
u32 irq = i;
of_property_read_u32_index(
node, "qca,ddr-wb-channel-interrupts", i, &irq);
if (irq >= ARRAY_SIZE(irq_wb_chan))
continue;
err = of_parse_phandle_with_args(
node, "qca,ddr-wb-channels",
"#qca,ddr-wb-channel-cells",
i, &args);
if (err)
return err;
irq_wb_chan[irq] = args.args[0];
}
return mips_cpu_irq_of_init(node, parent);
}
void __init ath79_cpu_irq_init(unsigned irq_wb_chan2, unsigned irq_wb_chan3)
{
irq_wb_chan[2] = irq_wb_chan2;
irq_wb_chan[3] = irq_wb_chan3;
mips_cpu_irq_init();
}
