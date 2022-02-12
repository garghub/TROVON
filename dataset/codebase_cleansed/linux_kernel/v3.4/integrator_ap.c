static void __init ap_map_io(void)
{
iotable_init(ap_io_desc, ARRAY_SIZE(ap_io_desc));
vga_base = PCI_MEMORY_VADDR;
}
static void __init ap_init_irq(void)
{
writel(-1, VA_CMIC_BASE + IRQ_ENABLE_CLEAR);
writel(-1, VA_IC_BASE + IRQ_ENABLE_CLEAR);
writel(-1, VA_IC_BASE + FIQ_ENABLE_CLEAR);
fpga_irq_init(-1, INTEGRATOR_SC_VALID_INT, &sc_irq_data);
}
static int irq_suspend(void)
{
ic_irq_enable = readl(VA_IC_BASE + IRQ_ENABLE);
return 0;
}
static void irq_resume(void)
{
writel(-1, VA_CMIC_BASE + IRQ_ENABLE_CLEAR);
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
writel(INTEGRATOR_SC_CTRL_nFLVPPEN | INTEGRATOR_SC_CTRL_nFLWP, SC_CTRLC);
tmp = readl(EBI_CSR1) | INTEGRATOR_EBI_WRITE_ENABLE;
writel(tmp, EBI_CSR1);
if (!(readl(EBI_CSR1) & INTEGRATOR_EBI_WRITE_ENABLE)) {
writel(0xa05f, EBI_LOCK);
writel(tmp, EBI_CSR1);
writel(0, EBI_LOCK);
}
return 0;
}
static void ap_flash_exit(struct platform_device *dev)
{
u32 tmp;
writel(INTEGRATOR_SC_CTRL_nFLVPPEN | INTEGRATOR_SC_CTRL_nFLWP, SC_CTRLC);
tmp = readl(EBI_CSR1) & ~INTEGRATOR_EBI_WRITE_ENABLE;
writel(tmp, EBI_CSR1);
if (readl(EBI_CSR1) & INTEGRATOR_EBI_WRITE_ENABLE) {
writel(0xa05f, EBI_LOCK);
writel(tmp, EBI_CSR1);
writel(0, EBI_LOCK);
}
}
static void ap_flash_set_vpp(struct platform_device *pdev, int on)
{
void __iomem *reg = on ? SC_CTRLS : SC_CTRLC;
writel(INTEGRATOR_SC_CTRL_nFLVPPEN, reg);
}
static void __init ap_init(void)
{
unsigned long sc_dec;
int i;
platform_device_register(&cfi_flash_device);
sc_dec = readl(VA_SC_BASE + INTEGRATOR_SC_DEC_OFFSET);
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
lmdev->irq = IRQ_AP_EXPINT0 + i;
lmdev->id = i;
lm_device_register(lmdev);
}
}
static u32 notrace integrator_read_sched_clock(void)
{
return -readl((void __iomem *) TIMER2_VA_BASE + TIMER_VALUE);
}
static void integrator_clocksource_init(unsigned long inrate)
{
void __iomem *base = (void __iomem *)TIMER2_VA_BASE;
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
setup_sched_clock(integrator_read_sched_clock, 16, rate);
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
static void integrator_clockevent_init(unsigned long inrate)
{
unsigned long rate = inrate;
unsigned int ctrl = 0;
if (rate > 0x100000 * HZ) {
rate /= 256;
ctrl |= TIMER_CTRL_DIV256;
} else if (rate > 0x10000 * HZ) {
rate /= 16;
ctrl |= TIMER_CTRL_DIV16;
}
timer_reload = rate / HZ;
writel(ctrl, clkevt_base + TIMER_CTRL);
setup_irq(IRQ_TIMERINT1, &integrator_timer_irq);
clockevents_config_and_register(&integrator_clockevent,
rate,
1,
0xffffU);
}
static void __init ap_init_timer(void)
{
struct clk *clk;
unsigned long rate;
clk = clk_get_sys("ap_timer", NULL);
BUG_ON(IS_ERR(clk));
clk_enable(clk);
rate = clk_get_rate(clk);
writel(0, TIMER0_VA_BASE + TIMER_CTRL);
writel(0, TIMER1_VA_BASE + TIMER_CTRL);
writel(0, TIMER2_VA_BASE + TIMER_CTRL);
integrator_clocksource_init(rate);
integrator_clockevent_init(rate);
}
