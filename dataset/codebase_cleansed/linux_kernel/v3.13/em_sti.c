static inline unsigned long em_sti_read(struct em_sti_priv *p, int offs)
{
return ioread32(p->base + offs);
}
static inline void em_sti_write(struct em_sti_priv *p, int offs,
unsigned long value)
{
iowrite32(value, p->base + offs);
}
static int em_sti_enable(struct em_sti_priv *p)
{
int ret;
ret = clk_prepare_enable(p->clk);
if (ret) {
dev_err(&p->pdev->dev, "cannot enable clock\n");
return ret;
}
p->rate = clk_get_rate(p->clk);
em_sti_write(p, STI_SET_H, 0x40000000);
em_sti_write(p, STI_SET_L, 0x00000000);
em_sti_write(p, STI_INTENCLR, 3);
em_sti_write(p, STI_INTFFCLR, 3);
em_sti_write(p, STI_CONTROL, 1);
return 0;
}
static void em_sti_disable(struct em_sti_priv *p)
{
em_sti_write(p, STI_INTENCLR, 3);
clk_disable_unprepare(p->clk);
}
static cycle_t em_sti_count(struct em_sti_priv *p)
{
cycle_t ticks;
unsigned long flags;
raw_spin_lock_irqsave(&p->lock, flags);
ticks = (cycle_t)(em_sti_read(p, STI_COUNT_H) & 0xffff) << 32;
ticks |= em_sti_read(p, STI_COUNT_L);
raw_spin_unlock_irqrestore(&p->lock, flags);
return ticks;
}
static cycle_t em_sti_set_next(struct em_sti_priv *p, cycle_t next)
{
unsigned long flags;
raw_spin_lock_irqsave(&p->lock, flags);
em_sti_write(p, STI_INTENCLR, 1);
em_sti_write(p, STI_COMPA_H, next >> 32);
em_sti_write(p, STI_COMPA_L, next & 0xffffffff);
em_sti_write(p, STI_INTFFCLR, 1);
em_sti_write(p, STI_INTENSET, 1);
raw_spin_unlock_irqrestore(&p->lock, flags);
return next;
}
static irqreturn_t em_sti_interrupt(int irq, void *dev_id)
{
struct em_sti_priv *p = dev_id;
p->ced.event_handler(&p->ced);
return IRQ_HANDLED;
}
static int em_sti_start(struct em_sti_priv *p, unsigned int user)
{
unsigned long flags;
int used_before;
int ret = 0;
raw_spin_lock_irqsave(&p->lock, flags);
used_before = p->active[USER_CLOCKSOURCE] | p->active[USER_CLOCKEVENT];
if (!used_before)
ret = em_sti_enable(p);
if (!ret)
p->active[user] = 1;
raw_spin_unlock_irqrestore(&p->lock, flags);
return ret;
}
static void em_sti_stop(struct em_sti_priv *p, unsigned int user)
{
unsigned long flags;
int used_before, used_after;
raw_spin_lock_irqsave(&p->lock, flags);
used_before = p->active[USER_CLOCKSOURCE] | p->active[USER_CLOCKEVENT];
p->active[user] = 0;
used_after = p->active[USER_CLOCKSOURCE] | p->active[USER_CLOCKEVENT];
if (used_before && !used_after)
em_sti_disable(p);
raw_spin_unlock_irqrestore(&p->lock, flags);
}
static struct em_sti_priv *cs_to_em_sti(struct clocksource *cs)
{
return container_of(cs, struct em_sti_priv, cs);
}
static cycle_t em_sti_clocksource_read(struct clocksource *cs)
{
return em_sti_count(cs_to_em_sti(cs));
}
static int em_sti_clocksource_enable(struct clocksource *cs)
{
int ret;
struct em_sti_priv *p = cs_to_em_sti(cs);
ret = em_sti_start(p, USER_CLOCKSOURCE);
if (!ret)
__clocksource_updatefreq_hz(cs, p->rate);
return ret;
}
static void em_sti_clocksource_disable(struct clocksource *cs)
{
em_sti_stop(cs_to_em_sti(cs), USER_CLOCKSOURCE);
}
static void em_sti_clocksource_resume(struct clocksource *cs)
{
em_sti_clocksource_enable(cs);
}
static int em_sti_register_clocksource(struct em_sti_priv *p)
{
struct clocksource *cs = &p->cs;
memset(cs, 0, sizeof(*cs));
cs->name = dev_name(&p->pdev->dev);
cs->rating = 200;
cs->read = em_sti_clocksource_read;
cs->enable = em_sti_clocksource_enable;
cs->disable = em_sti_clocksource_disable;
cs->suspend = em_sti_clocksource_disable;
cs->resume = em_sti_clocksource_resume;
cs->mask = CLOCKSOURCE_MASK(48);
cs->flags = CLOCK_SOURCE_IS_CONTINUOUS;
dev_info(&p->pdev->dev, "used as clock source\n");
clocksource_register_hz(cs, 1);
return 0;
}
static struct em_sti_priv *ced_to_em_sti(struct clock_event_device *ced)
{
return container_of(ced, struct em_sti_priv, ced);
}
static void em_sti_clock_event_mode(enum clock_event_mode mode,
struct clock_event_device *ced)
{
struct em_sti_priv *p = ced_to_em_sti(ced);
switch (ced->mode) {
case CLOCK_EVT_MODE_ONESHOT:
em_sti_stop(p, USER_CLOCKEVENT);
break;
default:
break;
}
switch (mode) {
case CLOCK_EVT_MODE_ONESHOT:
dev_info(&p->pdev->dev, "used for oneshot clock events\n");
em_sti_start(p, USER_CLOCKEVENT);
clockevents_config(&p->ced, p->rate);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
em_sti_stop(p, USER_CLOCKEVENT);
break;
default:
break;
}
}
static int em_sti_clock_event_next(unsigned long delta,
struct clock_event_device *ced)
{
struct em_sti_priv *p = ced_to_em_sti(ced);
cycle_t next;
int safe;
next = em_sti_set_next(p, em_sti_count(p) + delta);
safe = em_sti_count(p) < (next - 1);
return !safe;
}
static void em_sti_register_clockevent(struct em_sti_priv *p)
{
struct clock_event_device *ced = &p->ced;
memset(ced, 0, sizeof(*ced));
ced->name = dev_name(&p->pdev->dev);
ced->features = CLOCK_EVT_FEAT_ONESHOT;
ced->rating = 200;
ced->cpumask = cpu_possible_mask;
ced->set_next_event = em_sti_clock_event_next;
ced->set_mode = em_sti_clock_event_mode;
dev_info(&p->pdev->dev, "used for clock events\n");
clockevents_config_and_register(ced, 1, 2, 0xffffffff);
}
static int em_sti_probe(struct platform_device *pdev)
{
struct em_sti_priv *p;
struct resource *res;
int irq;
p = devm_kzalloc(&pdev->dev, sizeof(*p), GFP_KERNEL);
if (p == NULL) {
dev_err(&pdev->dev, "failed to allocate driver data\n");
return -ENOMEM;
}
p->pdev = pdev;
platform_set_drvdata(pdev, p);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
p->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(p->base))
return PTR_ERR(p->base);
p->clk = devm_clk_get(&pdev->dev, "sclk");
if (IS_ERR(p->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return PTR_ERR(p->clk);
}
if (devm_request_irq(&pdev->dev, irq, em_sti_interrupt,
IRQF_TIMER | IRQF_IRQPOLL | IRQF_NOBALANCING,
dev_name(&pdev->dev), p)) {
dev_err(&pdev->dev, "failed to request low IRQ\n");
return -ENOENT;
}
raw_spin_lock_init(&p->lock);
em_sti_register_clockevent(p);
em_sti_register_clocksource(p);
return 0;
}
static int em_sti_remove(struct platform_device *pdev)
{
return -EBUSY;
}
static int __init em_sti_init(void)
{
return platform_driver_register(&em_sti_device_driver);
}
static void __exit em_sti_exit(void)
{
platform_driver_unregister(&em_sti_device_driver);
}
