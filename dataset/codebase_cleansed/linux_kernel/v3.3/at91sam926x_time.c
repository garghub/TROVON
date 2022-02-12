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
static void at91sam926x_pit_reset(void)
{
pit_write(AT91_PIT_MR, 0);
while (PIT_CPIV(pit_read(AT91_PIT_PIVR)) != 0)
cpu_relax();
pit_write(AT91_PIT_MR, (pit_cycle - 1) | AT91_PIT_PITEN);
}
static void __init at91sam926x_pit_init(void)
{
unsigned long pit_rate;
unsigned bits;
pit_rate = clk_get_rate(clk_get(NULL, "mck")) / 16;
pit_cycle = (pit_rate + HZ/2) / HZ;
WARN_ON(((pit_cycle - 1) & ~AT91_PIT_PIV) != 0);
at91sam926x_pit_reset();
bits = 12 + ilog2(pit_cycle) ;
pit_clk.mask = CLOCKSOURCE_MASK(bits);
clocksource_register_hz(&pit_clk, pit_rate);
setup_irq(AT91_ID_SYS, &at91sam926x_pit_irq);
pit_clkevt.mult = div_sc(pit_rate, NSEC_PER_SEC, pit_clkevt.shift);
pit_clkevt.cpumask = cpumask_of(0);
clockevents_register_device(&pit_clkevt);
}
static void at91sam926x_pit_suspend(void)
{
pit_write(AT91_PIT_MR, 0);
}
void __init at91sam926x_ioremap_pit(u32 addr)
{
pit_base_addr = ioremap(addr, 16);
if (!pit_base_addr)
panic("Impossible to ioremap PIT\n");
}
