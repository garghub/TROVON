static inline unsigned int pit_read(unsigned int reg_offset)
{
return __raw_readl(pit_base_addr + reg_offset);
}
static inline void pit_write(unsigned int reg_offset, unsigned long value)
{
__raw_writel(value, pit_base_addr + reg_offset);
}
static cycle_t read_pit_clk(struct clocksource *cs)
{
unsigned long flags;
u32 elapsed;
u32 t;
raw_local_irq_save(flags);
elapsed = pit_cnt;
t = pit_read(AT91_PIT_PIIR);
raw_local_irq_restore(flags);
elapsed += PIT_PICNT(t) * pit_cycle;
elapsed += PIT_CPIV(t);
return elapsed;
}
static void
pit_clkevt_mode(enum clock_event_mode mode, struct clock_event_device *dev)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
pit_cnt += pit_cycle * PIT_PICNT(pit_read(AT91_PIT_PIVR));
pit_write(AT91_PIT_MR, (pit_cycle - 1) | AT91_PIT_PITEN
| AT91_PIT_PITIEN);
break;
case CLOCK_EVT_MODE_ONESHOT:
BUG();
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
pit_write(AT91_PIT_MR, (pit_cycle - 1) | AT91_PIT_PITEN);
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static void at91sam926x_pit_suspend(struct clock_event_device *cedev)
{
pit_write(AT91_PIT_MR, 0);
}
static void at91sam926x_pit_reset(void)
{
pit_write(AT91_PIT_MR, 0);
while (PIT_CPIV(pit_read(AT91_PIT_PIVR)) != 0)
cpu_relax();
pit_write(AT91_PIT_MR, (pit_cycle - 1) | AT91_PIT_PITEN);
}
static void at91sam926x_pit_resume(struct clock_event_device *cedev)
{
at91sam926x_pit_reset();
}
static irqreturn_t at91sam926x_pit_interrupt(int irq, void *dev_id)
{
WARN_ON_ONCE(!irqs_disabled());
if ((pit_clkevt.mode == CLOCK_EVT_MODE_PERIODIC)
&& (pit_read(AT91_PIT_SR) & AT91_PIT_PITS)) {
unsigned nr_ticks;
nr_ticks = PIT_PICNT(pit_read(AT91_PIT_PIVR));
do {
pit_cnt += pit_cycle;
pit_clkevt.event_handler(&pit_clkevt);
nr_ticks--;
} while (nr_ticks);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int __init of_at91sam926x_pit_init(void)
{
struct device_node *np;
int ret;
np = of_find_matching_node(NULL, pit_timer_ids);
if (!np)
goto err;
pit_base_addr = of_iomap(np, 0);
if (!pit_base_addr)
goto node_err;
ret = irq_of_parse_and_map(np, 0);
if (!ret) {
pr_crit("AT91: PIT: Unable to get IRQ from DT\n");
goto ioremap_err;
}
at91sam926x_pit_irq.irq = ret;
of_node_put(np);
return 0;
ioremap_err:
iounmap(pit_base_addr);
node_err:
of_node_put(np);
err:
return -EINVAL;
}
static int __init of_at91sam926x_pit_init(void)
{
return -EINVAL;
}
void __init at91sam926x_pit_init(void)
{
unsigned long pit_rate;
unsigned bits;
int ret;
of_at91sam926x_pit_init();
pit_rate = clk_get_rate(clk_get(NULL, "mck")) / 16;
pit_cycle = (pit_rate + HZ/2) / HZ;
WARN_ON(((pit_cycle - 1) & ~AT91_PIT_PIV) != 0);
at91sam926x_pit_reset();
bits = 12 + ilog2(pit_cycle) ;
pit_clk.mask = CLOCKSOURCE_MASK(bits);
clocksource_register_hz(&pit_clk, pit_rate);
ret = setup_irq(at91sam926x_pit_irq.irq, &at91sam926x_pit_irq);
if (ret)
pr_crit("AT91: PIT: Unable to setup IRQ\n");
pit_clkevt.mult = div_sc(pit_rate, NSEC_PER_SEC, pit_clkevt.shift);
pit_clkevt.cpumask = cpumask_of(0);
clockevents_register_device(&pit_clkevt);
}
void __init at91sam926x_ioremap_pit(u32 addr)
{
#if defined(CONFIG_OF)
struct device_node *np =
of_find_matching_node(NULL, pit_timer_ids);
if (np) {
of_node_put(np);
return;
}
#endif
pit_base_addr = ioremap(addr, 16);
if (!pit_base_addr)
panic("Impossible to ioremap PIT\n");
}
