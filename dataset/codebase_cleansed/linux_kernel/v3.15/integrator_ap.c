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
static int ap_flash_init(struct platform_device *dev)
{
u32 tmp;
writel(INTEGRATOR_SC_CTRL_nFLVPPEN | INTEGRATOR_SC_CTRL_nFLWP,
ap_syscon_base + INTEGRATOR_SC_CTRLC_OFFSET);
tmp = readl(ebi_base + INTEGRATOR_EBI_CSR1_OFFSET) |
INTEGRATOR_EBI_WRITE_ENABLE;
writel(tmp, ebi_base + INTEGRATOR_EBI_CSR1_OFFSET);
if (!(readl(ebi_base + INTEGRATOR_EBI_CSR1_OFFSET)
& INTEGRATOR_EBI_WRITE_ENABLE)) {
writel(0xa05f, ebi_base + INTEGRATOR_EBI_LOCK_OFFSET);
writel(tmp, ebi_base + INTEGRATOR_EBI_CSR1_OFFSET);
writel(0, ebi_base + INTEGRATOR_EBI_LOCK_OFFSET);
}
return 0;
}
static void ap_flash_exit(struct platform_device *dev)
{
u32 tmp;
writel(INTEGRATOR_SC_CTRL_nFLVPPEN | INTEGRATOR_SC_CTRL_nFLWP,
ap_syscon_base + INTEGRATOR_SC_CTRLC_OFFSET);
tmp = readl(ebi_base + INTEGRATOR_EBI_CSR1_OFFSET) &
~INTEGRATOR_EBI_WRITE_ENABLE;
writel(tmp, ebi_base + INTEGRATOR_EBI_CSR1_OFFSET);
if (readl(ebi_base + INTEGRATOR_EBI_CSR1_OFFSET) &
INTEGRATOR_EBI_WRITE_ENABLE) {
writel(0xa05f, ebi_base + INTEGRATOR_EBI_LOCK_OFFSET);
writel(tmp, ebi_base + INTEGRATOR_EBI_CSR1_OFFSET);
writel(0, ebi_base + INTEGRATOR_EBI_LOCK_OFFSET);
}
}
static void ap_flash_set_vpp(struct platform_device *pdev, int on)
{
if (on)
writel(INTEGRATOR_SC_CTRL_nFLVPPEN,
ap_syscon_base + INTEGRATOR_SC_CTRLS_OFFSET);
else
writel(INTEGRATOR_SC_CTRL_nFLVPPEN,
ap_syscon_base + INTEGRATOR_SC_CTRLC_OFFSET);
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
static u64 notrace integrator_read_sched_clock(void)
{
return -readl((void __iomem *) TIMER2_VA_BASE + TIMER_VALUE);
}
static void integrator_clocksource_init(unsigned long inrate,
void __iomem *base)
{
u32 ctrl = TIMER_CTRL_ENABLE | TIMER_CTRL_PERIODIC;
unsigned long rate = inrate;
if (rate >= 1500000) {
rate /= 16;
ctrl |= TIMER_CTRL_DIV16;
}
writel(0xffff, base + TIMER_LOAD);
writel(ctrl, base + TIMER_CTRL);
clocksource_mmio_init(base + TIMER_VALUE, "timer2",
rate, 200, 16, clocksource_mmio_readl_down);
sched_clock_register(integrator_read_sched_clock, 16, rate);
}
static irqreturn_t integrator_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(1, clkevt_base + TIMER_INTCLR);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void clkevt_set_mode(enum clock_event_mode mode, struct clock_event_device *evt)
{
u32 ctrl = readl(clkevt_base + TIMER_CTRL) & ~TIMER_CTRL_ENABLE;
writel(ctrl, clkevt_base + TIMER_CTRL);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
writel(timer_reload, clkevt_base + TIMER_LOAD);
ctrl |= TIMER_CTRL_PERIODIC | TIMER_CTRL_ENABLE;
writel(ctrl, clkevt_base + TIMER_CTRL);
break;
case CLOCK_EVT_MODE_ONESHOT:
ctrl &= ~TIMER_CTRL_PERIODIC;
writel(ctrl, clkevt_base + TIMER_CTRL);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
default:
break;
}
}
static int clkevt_set_next_event(unsigned long next, struct clock_event_device *evt)
{
unsigned long ctrl = readl(clkevt_base + TIMER_CTRL);
writel(ctrl & ~TIMER_CTRL_ENABLE, clkevt_base + TIMER_CTRL);
writel(next, clkevt_base + TIMER_LOAD);
writel(ctrl | TIMER_CTRL_ENABLE, clkevt_base + TIMER_CTRL);
return 0;
}
static void integrator_clockevent_init(unsigned long inrate,
void __iomem *base, int irq)
{
unsigned long rate = inrate;
unsigned int ctrl = 0;
clkevt_base = base;
if (rate > 0x100000 * HZ) {
rate /= 256;
ctrl |= TIMER_CTRL_DIV256;
} else if (rate > 0x10000 * HZ) {
rate /= 16;
ctrl |= TIMER_CTRL_DIV16;
}
timer_reload = rate / HZ;
writel(ctrl, clkevt_base + TIMER_CTRL);
setup_irq(irq, &integrator_timer_irq);
clockevents_config_and_register(&integrator_clockevent,
rate,
1,
0xffffU);
}
void __init ap_init_early(void)
{
}
static void __init ap_of_timer_init(void)
{
struct device_node *node;
const char *path;
void __iomem *base;
int err;
int irq;
struct clk *clk;
unsigned long rate;
of_clk_init(NULL);
err = of_property_read_string(of_aliases,
"arm,timer-primary", &path);
if (WARN_ON(err))
return;
node = of_find_node_by_path(path);
base = of_iomap(node, 0);
if (WARN_ON(!base))
return;
clk = of_clk_get(node, 0);
BUG_ON(IS_ERR(clk));
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
writel(0, base + TIMER_CTRL);
integrator_clocksource_init(rate, base);
err = of_property_read_string(of_aliases,
"arm,timer-secondary", &path);
if (WARN_ON(err))
return;
node = of_find_node_by_path(path);
base = of_iomap(node, 0);
if (WARN_ON(!base))
return;
irq = irq_of_parse_and_map(node, 0);
clk = of_clk_get(node, 0);
BUG_ON(IS_ERR(clk));
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
writel(0, base + TIMER_CTRL);
integrator_clockevent_init(rate, base, irq);
}
static void __init ap_init_irq_of(void)
{
cm_init();
of_irq_init(fpga_irq_of_match);
}
static void __init ap_init_of(void)
{
unsigned long sc_dec;
struct device_node *root;
struct device_node *syscon;
struct device_node *ebi;
struct device *parent;
struct soc_device *soc_dev;
struct soc_device_attribute *soc_dev_attr;
u32 ap_sc_id;
int err;
int i;
root = of_find_node_by_path("/");
if (!root)
return;
syscon = of_find_matching_node(root, ap_syscon_match);
if (!syscon)
return;
ebi = of_find_matching_node(root, ebi_match);
if (!ebi)
return;
ap_syscon_base = of_iomap(syscon, 0);
if (!ap_syscon_base)
return;
ebi_base = of_iomap(ebi, 0);
if (!ebi_base)
return;
ap_sc_id = readl(ap_syscon_base);
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
return;
err = of_property_read_string(root, "compatible",
&soc_dev_attr->soc_id);
if (err)
return;
err = of_property_read_string(root, "model", &soc_dev_attr->machine);
if (err)
return;
soc_dev_attr->family = "Integrator";
soc_dev_attr->revision = kasprintf(GFP_KERNEL, "%c",
'A' + (ap_sc_id & 0x0f));
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr->revision);
kfree(soc_dev_attr);
return;
}
parent = soc_device_to_device(soc_dev);
integrator_init_sysfs(parent, ap_sc_id);
of_platform_populate(root, of_default_bus_match_table,
ap_auxdata_lookup, parent);
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
