static inline struct pit_data *clksrc_to_pit_data(struct clocksource *clksrc)
{
return container_of(clksrc, struct pit_data, clksrc);
}
static inline struct pit_data *clkevt_to_pit_data(struct clock_event_device *clkevt)
{
return container_of(clkevt, struct pit_data, clkevt);
}
static inline unsigned int pit_read(void __iomem *base, unsigned int reg_offset)
{
return __raw_readl(base + reg_offset);
}
static inline void pit_write(void __iomem *base, unsigned int reg_offset, unsigned long value)
{
__raw_writel(value, base + reg_offset);
}
static cycle_t read_pit_clk(struct clocksource *cs)
{
struct pit_data *data = clksrc_to_pit_data(cs);
unsigned long flags;
u32 elapsed;
u32 t;
raw_local_irq_save(flags);
elapsed = data->cnt;
t = pit_read(data->base, AT91_PIT_PIIR);
raw_local_irq_restore(flags);
elapsed += PIT_PICNT(t) * data->cycle;
elapsed += PIT_CPIV(t);
return elapsed;
}
static void
pit_clkevt_mode(enum clock_event_mode mode, struct clock_event_device *dev)
{
struct pit_data *data = clkevt_to_pit_data(dev);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
data->cnt += data->cycle * PIT_PICNT(pit_read(data->base, AT91_PIT_PIVR));
pit_write(data->base, AT91_PIT_MR,
(data->cycle - 1) | AT91_PIT_PITEN | AT91_PIT_PITIEN);
break;
case CLOCK_EVT_MODE_ONESHOT:
BUG();
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
pit_write(data->base, AT91_PIT_MR,
(data->cycle - 1) | AT91_PIT_PITEN);
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static void at91sam926x_pit_suspend(struct clock_event_device *cedev)
{
struct pit_data *data = clkevt_to_pit_data(cedev);
pit_write(data->base, AT91_PIT_MR, 0);
}
static void at91sam926x_pit_reset(struct pit_data *data)
{
pit_write(data->base, AT91_PIT_MR, 0);
while (PIT_CPIV(pit_read(data->base, AT91_PIT_PIVR)) != 0)
cpu_relax();
pit_write(data->base, AT91_PIT_MR,
(data->cycle - 1) | AT91_PIT_PITEN);
}
static void at91sam926x_pit_resume(struct clock_event_device *cedev)
{
struct pit_data *data = clkevt_to_pit_data(cedev);
at91sam926x_pit_reset(data);
}
static irqreturn_t at91sam926x_pit_interrupt(int irq, void *dev_id)
{
struct pit_data *data = dev_id;
WARN_ON_ONCE(!irqs_disabled());
if ((data->clkevt.mode == CLOCK_EVT_MODE_PERIODIC) &&
(pit_read(data->base, AT91_PIT_SR) & AT91_PIT_PITS)) {
unsigned nr_ticks;
nr_ticks = PIT_PICNT(pit_read(data->base, AT91_PIT_PIVR));
do {
data->cnt += data->cycle;
data->clkevt.event_handler(&data->clkevt);
nr_ticks--;
} while (nr_ticks);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void __init at91sam926x_pit_common_init(struct pit_data *data)
{
unsigned long pit_rate;
unsigned bits;
int ret;
pit_rate = clk_get_rate(data->mck) / 16;
data->cycle = DIV_ROUND_CLOSEST(pit_rate, HZ);
WARN_ON(((data->cycle - 1) & ~AT91_PIT_PIV) != 0);
at91sam926x_pit_reset(data);
bits = 12 + ilog2(data->cycle) ;
data->clksrc.mask = CLOCKSOURCE_MASK(bits);
data->clksrc.name = "pit";
data->clksrc.rating = 175;
data->clksrc.read = read_pit_clk,
data->clksrc.flags = CLOCK_SOURCE_IS_CONTINUOUS,
clocksource_register_hz(&data->clksrc, pit_rate);
ret = request_irq(data->irq, at91sam926x_pit_interrupt,
IRQF_SHARED | IRQF_TIMER | IRQF_IRQPOLL,
"at91_tick", data);
if (ret)
panic(pr_fmt("Unable to setup IRQ\n"));
data->clkevt.name = "pit";
data->clkevt.features = CLOCK_EVT_FEAT_PERIODIC;
data->clkevt.shift = 32;
data->clkevt.mult = div_sc(pit_rate, NSEC_PER_SEC, data->clkevt.shift);
data->clkevt.rating = 100;
data->clkevt.cpumask = cpumask_of(0);
data->clkevt.set_mode = pit_clkevt_mode;
data->clkevt.resume = at91sam926x_pit_resume;
data->clkevt.suspend = at91sam926x_pit_suspend;
clockevents_register_device(&data->clkevt);
}
static void __init at91sam926x_pit_dt_init(struct device_node *node)
{
struct pit_data *data;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
panic(pr_fmt("Unable to allocate memory\n"));
data->base = of_iomap(node, 0);
if (!data->base)
panic(pr_fmt("Could not map PIT address\n"));
data->mck = of_clk_get(node, 0);
if (IS_ERR(data->mck))
data->mck = clk_get(NULL, "mck");
if (IS_ERR(data->mck))
panic(pr_fmt("Unable to get mck clk\n"));
data->irq = irq_of_parse_and_map(node, 0);
if (!data->irq)
panic(pr_fmt("Unable to get IRQ from DT\n"));
at91sam926x_pit_common_init(data);
}
