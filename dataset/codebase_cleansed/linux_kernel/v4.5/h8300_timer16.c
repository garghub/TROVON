static unsigned long timer16_get_counter(struct timer16_priv *p)
{
unsigned short v1, v2, v3;
unsigned char o1, o2;
o1 = ioread8(p->mapcommon + TISRC) & p->ovf;
do {
o2 = o1;
v1 = ioread16be(p->mapbase + TCNT);
v2 = ioread16be(p->mapbase + TCNT);
v3 = ioread16be(p->mapbase + TCNT);
o1 = ioread8(p->mapcommon + TISRC) & p->ovf;
} while (unlikely((o1 != o2) || (v1 > v2 && v1 < v3)
|| (v2 > v3 && v2 < v1) || (v3 > v1 && v3 < v2)));
if (likely(!o1))
return v2;
else
return v2 + 0x10000;
}
static irqreturn_t timer16_interrupt(int irq, void *dev_id)
{
struct timer16_priv *p = (struct timer16_priv *)dev_id;
bclr(p->ovf, p->mapcommon + TISRC);
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
unsigned long raw, value;
value = p->total_cycles;
raw = timer16_get_counter(p);
return value + raw;
}
static int timer16_enable(struct clocksource *cs)
{
struct timer16_priv *p = cs_to_priv(cs);
WARN_ON(p->cs_enabled);
p->total_cycles = 0;
iowrite16be(0x0000, p->mapbase + TCNT);
iowrite8(0x83, p->mapbase + TCR);
bset(p->ovie, p->mapcommon + TISRC);
bset(p->enb, p->mapcommon + TSTR);
p->cs_enabled = true;
return 0;
}
static void timer16_disable(struct clocksource *cs)
{
struct timer16_priv *p = cs_to_priv(cs);
WARN_ON(!p->cs_enabled);
bclr(p->ovie, p->mapcommon + TISRC);
bclr(p->enb, p->mapcommon + TSTR);
p->cs_enabled = false;
}
static void __init h8300_16timer_init(struct device_node *node)
{
void __iomem *base[2];
int ret, irq;
unsigned int ch;
struct clk *clk;
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("failed to get clock for clocksource\n");
return;
}
base[REG_CH] = of_iomap(node, 0);
if (!base[REG_CH]) {
pr_err("failed to map registers for clocksource\n");
goto free_clk;
}
base[REG_COMM] = of_iomap(node, 1);
if (!base[REG_COMM]) {
pr_err("failed to map registers for clocksource\n");
goto unmap_ch;
}
irq = irq_of_parse_and_map(node, 0);
if (!irq) {
pr_err("failed to get irq for clockevent\n");
goto unmap_comm;
}
of_property_read_u32(node, "renesas,channel", &ch);
timer16_priv.mapbase = base[REG_CH];
timer16_priv.mapcommon = base[REG_COMM];
timer16_priv.enb = ch;
timer16_priv.ovf = ch;
timer16_priv.ovie = 4 + ch;
ret = request_irq(irq, timer16_interrupt,
IRQF_TIMER, timer16_priv.cs.name, &timer16_priv);
if (ret < 0) {
pr_err("failed to request irq %d of clocksource\n", irq);
goto unmap_comm;
}
clocksource_register_hz(&timer16_priv.cs,
clk_get_rate(clk) / 8);
return;
unmap_comm:
iounmap(base[REG_COMM]);
unmap_ch:
iounmap(base[REG_CH]);
free_clk:
clk_put(clk);
}
