static inline unsigned long read_tcnt32(struct tpu_priv *p)
{
unsigned long tcnt;
tcnt = ctrl_inw(p->mapbase1 + TCNT) << 16;
tcnt |= ctrl_inw(p->mapbase2 + TCNT);
return tcnt;
}
static int tpu_get_counter(struct tpu_priv *p, unsigned long long *val)
{
unsigned long v1, v2, v3;
int o1, o2;
o1 = ctrl_inb(p->mapbase1 + TSR) & 0x10;
do {
o2 = o1;
v1 = read_tcnt32(p);
v2 = read_tcnt32(p);
v3 = read_tcnt32(p);
o1 = ctrl_inb(p->mapbase1 + TSR) & 0x10;
} while (unlikely((o1 != o2) || (v1 > v2 && v1 < v3)
|| (v2 > v3 && v2 < v1) || (v3 > v1 && v3 < v2)));
*val = v2;
return o1;
}
static inline struct tpu_priv *cs_to_priv(struct clocksource *cs)
{
return container_of(cs, struct tpu_priv, cs);
}
static cycle_t tpu_clocksource_read(struct clocksource *cs)
{
struct tpu_priv *p = cs_to_priv(cs);
unsigned long flags;
unsigned long long value;
raw_spin_lock_irqsave(&p->lock, flags);
if (tpu_get_counter(p, &value))
value += 0x100000000;
raw_spin_unlock_irqrestore(&p->lock, flags);
return value;
}
static int tpu_clocksource_enable(struct clocksource *cs)
{
struct tpu_priv *p = cs_to_priv(cs);
WARN_ON(p->cs_enabled);
ctrl_outw(0, p->mapbase1 + TCNT);
ctrl_outw(0, p->mapbase2 + TCNT);
ctrl_outb(0x0f, p->mapbase1 + TCR);
ctrl_outb(0x03, p->mapbase2 + TCR);
p->cs_enabled = true;
return 0;
}
static void tpu_clocksource_disable(struct clocksource *cs)
{
struct tpu_priv *p = cs_to_priv(cs);
WARN_ON(!p->cs_enabled);
ctrl_outb(0, p->mapbase1 + TCR);
ctrl_outb(0, p->mapbase2 + TCR);
p->cs_enabled = false;
}
static int __init tpu_setup(struct tpu_priv *p, struct platform_device *pdev)
{
struct resource *res[2];
memset(p, 0, sizeof(*p));
p->pdev = pdev;
res[CH_L] = platform_get_resource(p->pdev, IORESOURCE_MEM, CH_L);
res[CH_H] = platform_get_resource(p->pdev, IORESOURCE_MEM, CH_H);
if (!res[CH_L] || !res[CH_H]) {
dev_err(&p->pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
p->clk = clk_get(&p->pdev->dev, "fck");
if (IS_ERR(p->clk)) {
dev_err(&p->pdev->dev, "can't get clk\n");
return PTR_ERR(p->clk);
}
p->mapbase1 = res[CH_L]->start;
p->mapbase2 = res[CH_H]->start;
p->cs.name = pdev->name;
p->cs.rating = 200;
p->cs.read = tpu_clocksource_read;
p->cs.enable = tpu_clocksource_enable;
p->cs.disable = tpu_clocksource_disable;
p->cs.mask = CLOCKSOURCE_MASK(sizeof(unsigned long) * 8);
p->cs.flags = CLOCK_SOURCE_IS_CONTINUOUS;
clocksource_register_hz(&p->cs, clk_get_rate(p->clk) / 64);
platform_set_drvdata(pdev, p);
return 0;
}
static int tpu_probe(struct platform_device *pdev)
{
struct tpu_priv *p = platform_get_drvdata(pdev);
if (p) {
dev_info(&pdev->dev, "kept as earlytimer\n");
return 0;
}
p = devm_kzalloc(&pdev->dev, sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
return tpu_setup(p, pdev);
}
static int tpu_remove(struct platform_device *pdev)
{
return -EBUSY;
}
static int __init tpu_init(void)
{
return platform_driver_register(&tpu_driver);
}
static void __exit tpu_exit(void)
{
platform_driver_unregister(&tpu_driver);
}
