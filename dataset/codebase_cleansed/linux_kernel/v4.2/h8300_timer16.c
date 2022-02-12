static unsigned long timer16_get_counter(struct timer16_priv *p)
{
unsigned long v1, v2, v3;
int o1, o2;
o1 = ctrl_inb(p->mapcommon + TISRC) & p->ovf;
do {
o2 = o1;
v1 = ctrl_inw(p->mapbase + TCNT);
v2 = ctrl_inw(p->mapbase + TCNT);
v3 = ctrl_inw(p->mapbase + TCNT);
o1 = ctrl_inb(p->mapcommon + TISRC) & p->ovf;
} while (unlikely((o1 != o2) || (v1 > v2 && v1 < v3)
|| (v2 > v3 && v2 < v1) || (v3 > v1 && v3 < v2)));
v2 |= 0x10000;
return v2;
}
static irqreturn_t timer16_interrupt(int irq, void *dev_id)
{
struct timer16_priv *p = (struct timer16_priv *)dev_id;
ctrl_outb(ctrl_inb(p->mapcommon + TISRA) & ~p->imfa,
p->mapcommon + TISRA);
p->total_cycles += 0x10000;
return IRQ_HANDLED;
}
static inline struct timer16_priv *cs_to_priv(struct clocksource *cs)
{
return container_of(cs, struct timer16_priv, cs);
}
static cycle_t timer16_clocksource_read(struct clocksource *cs)
{
struct timer16_priv *p = cs_to_priv(cs);
unsigned long flags, raw;
unsigned long value;
raw_spin_lock_irqsave(&p->lock, flags);
value = p->total_cycles;
raw = timer16_get_counter(p);
raw_spin_unlock_irqrestore(&p->lock, flags);
return value + raw;
}
static int timer16_enable(struct clocksource *cs)
{
struct timer16_priv *p = cs_to_priv(cs);
WARN_ON(p->cs_enabled);
p->total_cycles = 0;
ctrl_outw(0x0000, p->mapbase + TCNT);
ctrl_outb(0x83, p->mapbase + TCR);
ctrl_outb(ctrl_inb(p->mapcommon + TSTR) | p->enb,
p->mapcommon + TSTR);
p->cs_enabled = true;
return 0;
}
static void timer16_disable(struct clocksource *cs)
{
struct timer16_priv *p = cs_to_priv(cs);
WARN_ON(!p->cs_enabled);
ctrl_outb(ctrl_inb(p->mapcommon + TSTR) & ~p->enb,
p->mapcommon + TSTR);
p->cs_enabled = false;
}
static int timer16_setup(struct timer16_priv *p, struct platform_device *pdev)
{
struct resource *res[2];
int ret, irq;
unsigned int ch;
memset(p, 0, sizeof(*p));
p->pdev = pdev;
res[REG_CH] = platform_get_resource(p->pdev,
IORESOURCE_MEM, REG_CH);
res[REG_COMM] = platform_get_resource(p->pdev,
IORESOURCE_MEM, REG_COMM);
if (!res[REG_CH] || !res[REG_COMM]) {
dev_err(&p->pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
irq = platform_get_irq(p->pdev, 0);
if (irq < 0) {
dev_err(&p->pdev->dev, "failed to get irq\n");
return irq;
}
p->clk = clk_get(&p->pdev->dev, "fck");
if (IS_ERR(p->clk)) {
dev_err(&p->pdev->dev, "can't get clk\n");
return PTR_ERR(p->clk);
}
of_property_read_u32(p->pdev->dev.of_node, "renesas,channel", &ch);
p->pdev = pdev;
p->mapbase = res[REG_CH]->start;
p->mapcommon = res[REG_COMM]->start;
p->enb = 1 << ch;
p->imfa = 1 << ch;
p->imiea = 1 << (4 + ch);
p->cs.name = pdev->name;
p->cs.rating = 200;
p->cs.read = timer16_clocksource_read;
p->cs.enable = timer16_enable;
p->cs.disable = timer16_disable;
p->cs.mask = CLOCKSOURCE_MASK(sizeof(unsigned long) * 8);
p->cs.flags = CLOCK_SOURCE_IS_CONTINUOUS;
ret = request_irq(irq, timer16_interrupt,
IRQF_TIMER, pdev->name, p);
if (ret < 0) {
dev_err(&p->pdev->dev, "failed to request irq %d\n", irq);
return ret;
}
clocksource_register_hz(&p->cs, clk_get_rate(p->clk) / 8);
return 0;
}
static int timer16_probe(struct platform_device *pdev)
{
struct timer16_priv *p = platform_get_drvdata(pdev);
if (p) {
dev_info(&pdev->dev, "kept as earlytimer\n");
return 0;
}
p = devm_kzalloc(&pdev->dev, sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
return timer16_setup(p, pdev);
}
static int timer16_remove(struct platform_device *pdev)
{
return -EBUSY;
}
static int __init timer16_init(void)
{
return platform_driver_register(&timer16_driver);
}
static void __exit timer16_exit(void)
{
platform_driver_unregister(&timer16_driver);
}
