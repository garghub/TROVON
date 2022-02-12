static inline struct clocksource_mmio *to_mmio_clksrc(struct clocksource *c)
{
return container_of(c, struct clocksource_mmio, clksrc);
}
cycle_t clocksource_mmio_readl_up(struct clocksource *c)
{
return readl_relaxed(to_mmio_clksrc(c)->reg);
}
cycle_t clocksource_mmio_readl_down(struct clocksource *c)
{
return ~readl_relaxed(to_mmio_clksrc(c)->reg);
}
cycle_t clocksource_mmio_readw_up(struct clocksource *c)
{
return readw_relaxed(to_mmio_clksrc(c)->reg);
}
cycle_t clocksource_mmio_readw_down(struct clocksource *c)
{
return ~(unsigned)readw_relaxed(to_mmio_clksrc(c)->reg);
}
int __init clocksource_mmio_init(void __iomem *base, const char *name,
unsigned long hz, int rating, unsigned bits,
cycle_t (*read)(struct clocksource *))
{
struct clocksource_mmio *cs;
if (bits > 32 || bits < 16)
return -EINVAL;
cs = kzalloc(sizeof(struct clocksource_mmio), GFP_KERNEL);
if (!cs)
return -ENOMEM;
cs->reg = base;
cs->clksrc.name = name;
cs->clksrc.rating = rating;
cs->clksrc.read = read;
cs->clksrc.mask = CLOCKSOURCE_MASK(bits);
cs->clksrc.flags = CLOCK_SOURCE_IS_CONTINUOUS;
return clocksource_register_hz(&cs->clksrc, hz);
}
