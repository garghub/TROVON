static void __init ap_map_io(void)
{
iotable_init(ap_io_desc, ARRAY_SIZE(ap_io_desc));
pci_v3_early_init();
}
static int irq_suspend(void)
{
ic_irq_enable = readl(VA_IC_BASE + IRQ_ENABLE);
return 0;
}
static void irq_resume(void)
{
cm_clear_irqs();
writel(-1, VA_IC_BASE + IRQ_ENABLE_CLEAR);
writel(-1, VA_IC_BASE + FIQ_ENABLE_CLEAR);
writel(ic_irq_enable, VA_IC_BASE + IRQ_ENABLE_SET);
}
static int __init irq_syscore_init(void)
{
register_syscore_ops(&irq_syscore_ops);
return 0;
}
static void integrator_uart_set_mctrl(struct amba_device *dev,
void __iomem *base, unsigned int mctrl)
{
unsigned int ctrls = 0, ctrlc = 0, rts_mask, dtr_mask;
u32 phybase = dev->res.start;
if (phybase == INTEGRATOR_UART0_BASE) {
rts_mask = 1 << 4;
dtr_mask = 1 << 5;
} else {
rts_mask = 1 << 6;
dtr_mask = 1 << 7;
}
if (mctrl & TIOCM_RTS)
ctrlc |= rts_mask;
else
ctrls |= rts_mask;
if (mctrl & TIOCM_DTR)
ctrlc |= dtr_mask;
else
ctrls |= dtr_mask;
__raw_writel(ctrls, ap_syscon_base + INTEGRATOR_SC_CTRLS_OFFSET);
__raw_writel(ctrlc, ap_syscon_base + INTEGRATOR_SC_CTRLC_OFFSET);
}
void __init ap_init_early(void)
{
}
static void __init ap_init_irq_of(void)
{
cm_init();
irqchip_init();
}
static void __init ap_init_of(void)
{
unsigned long sc_dec;
struct device_node *syscon;
struct device_node *ebi;
int i;
syscon = of_find_matching_node(NULL, ap_syscon_match);
if (!syscon)
return;
ebi = of_find_matching_node(NULL, ebi_match);
if (!ebi)
return;
ap_syscon_base = of_iomap(syscon, 0);
if (!ap_syscon_base)
return;
ebi_base = of_iomap(ebi, 0);
if (!ebi_base)
return;
of_platform_default_populate(NULL, ap_auxdata_lookup, NULL);
sc_dec = readl(ap_syscon_base + INTEGRATOR_SC_DEC_OFFSET);
for (i = 0; i < 4; i++) {
struct lm_device *lmdev;
if ((sc_dec & (16 << i)) == 0)
continue;
lmdev = kzalloc(sizeof(struct lm_device), GFP_KERNEL);
if (!lmdev)
continue;
lmdev->resource.start = 0xc0000000 + 0x10000000 * i;
lmdev->resource.end = lmdev->resource.start + 0x0fffffff;
lmdev->resource.flags = IORESOURCE_MEM;
lmdev->irq = irq_of_parse_and_map(syscon, i);
lmdev->id = i;
lm_device_register(lmdev);
}
}
