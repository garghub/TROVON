static unsigned long sh_cmt_read16(void __iomem *base, unsigned long offs)
{
return ioread16(base + (offs << 1));
}
static unsigned long sh_cmt_read32(void __iomem *base, unsigned long offs)
{
return ioread32(base + (offs << 2));
}
static void sh_cmt_write16(void __iomem *base, unsigned long offs,
unsigned long value)
{
iowrite16(value, base + (offs << 1));
}
static void sh_cmt_write32(void __iomem *base, unsigned long offs,
unsigned long value)
{
iowrite32(value, base + (offs << 2));
}
static inline unsigned long sh_cmt_read_cmstr(struct sh_cmt_priv *p)
{
return p->read_control(p->mapbase_str, 0);
}
static inline unsigned long sh_cmt_read_cmcsr(struct sh_cmt_priv *p)
{
return p->read_control(p->mapbase, CMCSR);
}
static inline unsigned long sh_cmt_read_cmcnt(struct sh_cmt_priv *p)
{
return p->read_count(p->mapbase, CMCNT);
}
static inline void sh_cmt_write_cmstr(struct sh_cmt_priv *p,
unsigned long value)
{
p->write_control(p->mapbase_str, 0, value);
}
static inline void sh_cmt_write_cmcsr(struct sh_cmt_priv *p,
unsigned long value)
{
p->write_control(p->mapbase, CMCSR, value);
}
static inline void sh_cmt_write_cmcnt(struct sh_cmt_priv *p,
unsigned long value)
{
p->write_count(p->mapbase, CMCNT, value);
}
static inline void sh_cmt_write_cmcor(struct sh_cmt_priv *p,
unsigned long value)
{
p->write_count(p->mapbase, CMCOR, value);
}
static unsigned long sh_cmt_get_counter(struct sh_cmt_priv *p,
int *has_wrapped)
{
unsigned long v1, v2, v3;
int o1, o2;
o1 = sh_cmt_read_cmcsr(p) & p->overflow_bit;
do {
o2 = o1;
v1 = sh_cmt_read_cmcnt(p);
v2 = sh_cmt_read_cmcnt(p);
v3 = sh_cmt_read_cmcnt(p);
o1 = sh_cmt_read_cmcsr(p) & p->overflow_bit;
} while (unlikely((o1 != o2) || (v1 > v2 && v1 < v3)
|| (v2 > v3 && v2 < v1) || (v3 > v1 && v3 < v2)));
*has_wrapped = o1;
return v2;
}
static void sh_cmt_start_stop_ch(struct sh_cmt_priv *p, int start)
{
struct sh_timer_config *cfg = p->pdev->dev.platform_data;
unsigned long flags, value;
raw_spin_lock_irqsave(&sh_cmt_lock, flags);
value = sh_cmt_read_cmstr(p);
if (start)
value |= 1 << cfg->timer_bit;
else
value &= ~(1 << cfg->timer_bit);
sh_cmt_write_cmstr(p, value);
raw_spin_unlock_irqrestore(&sh_cmt_lock, flags);
}
static int sh_cmt_enable(struct sh_cmt_priv *p, unsigned long *rate)
{
int k, ret;
pm_runtime_get_sync(&p->pdev->dev);
dev_pm_syscore_device(&p->pdev->dev, true);
ret = clk_enable(p->clk);
if (ret) {
dev_err(&p->pdev->dev, "cannot enable clock\n");
goto err0;
}
sh_cmt_start_stop_ch(p, 0);
if (p->width == 16) {
*rate = clk_get_rate(p->clk) / 512;
sh_cmt_write_cmcsr(p, 0x43);
} else {
*rate = clk_get_rate(p->clk) / 8;
sh_cmt_write_cmcsr(p, 0x01a4);
}
sh_cmt_write_cmcor(p, 0xffffffff);
sh_cmt_write_cmcnt(p, 0);
for (k = 0; k < 100; k++) {
if (!sh_cmt_read_cmcnt(p))
break;
udelay(1);
}
if (sh_cmt_read_cmcnt(p)) {
dev_err(&p->pdev->dev, "cannot clear CMCNT\n");
ret = -ETIMEDOUT;
goto err1;
}
sh_cmt_start_stop_ch(p, 1);
return 0;
err1:
clk_disable(p->clk);
err0:
return ret;
}
static void sh_cmt_disable(struct sh_cmt_priv *p)
{
sh_cmt_start_stop_ch(p, 0);
sh_cmt_write_cmcsr(p, 0);
clk_disable(p->clk);
dev_pm_syscore_device(&p->pdev->dev, false);
pm_runtime_put(&p->pdev->dev);
}
static void sh_cmt_clock_event_program_verify(struct sh_cmt_priv *p,
int absolute)
{
unsigned long new_match;
unsigned long value = p->next_match_value;
unsigned long delay = 0;
unsigned long now = 0;
int has_wrapped;
now = sh_cmt_get_counter(p, &has_wrapped);
p->flags |= FLAG_REPROGRAM;
if (has_wrapped) {
p->flags |= FLAG_SKIPEVENT;
return;
}
if (absolute)
now = 0;
do {
new_match = now + value + delay;
if (new_match > p->max_match_value)
new_match = p->max_match_value;
sh_cmt_write_cmcor(p, new_match);
now = sh_cmt_get_counter(p, &has_wrapped);
if (has_wrapped && (new_match > p->match_value)) {
p->flags |= FLAG_SKIPEVENT;
break;
}
if (has_wrapped) {
p->match_value = new_match;
break;
}
if (now < new_match) {
p->match_value = new_match;
break;
}
if (delay)
delay <<= 1;
else
delay = 1;
if (!delay)
dev_warn(&p->pdev->dev, "too long delay\n");
} while (delay);
}
static void __sh_cmt_set_next(struct sh_cmt_priv *p, unsigned long delta)
{
if (delta > p->max_match_value)
dev_warn(&p->pdev->dev, "delta out of range\n");
p->next_match_value = delta;
sh_cmt_clock_event_program_verify(p, 0);
}
static void sh_cmt_set_next(struct sh_cmt_priv *p, unsigned long delta)
{
unsigned long flags;
raw_spin_lock_irqsave(&p->lock, flags);
__sh_cmt_set_next(p, delta);
raw_spin_unlock_irqrestore(&p->lock, flags);
}
static irqreturn_t sh_cmt_interrupt(int irq, void *dev_id)
{
struct sh_cmt_priv *p = dev_id;
sh_cmt_write_cmcsr(p, sh_cmt_read_cmcsr(p) & p->clear_bits);
if (p->flags & FLAG_CLOCKSOURCE)
p->total_cycles += p->match_value + 1;
if (!(p->flags & FLAG_REPROGRAM))
p->next_match_value = p->max_match_value;
p->flags |= FLAG_IRQCONTEXT;
if (p->flags & FLAG_CLOCKEVENT) {
if (!(p->flags & FLAG_SKIPEVENT)) {
if (p->ced.mode == CLOCK_EVT_MODE_ONESHOT) {
p->next_match_value = p->max_match_value;
p->flags |= FLAG_REPROGRAM;
}
p->ced.event_handler(&p->ced);
}
}
p->flags &= ~FLAG_SKIPEVENT;
if (p->flags & FLAG_REPROGRAM) {
p->flags &= ~FLAG_REPROGRAM;
sh_cmt_clock_event_program_verify(p, 1);
if (p->flags & FLAG_CLOCKEVENT)
if ((p->ced.mode == CLOCK_EVT_MODE_SHUTDOWN)
|| (p->match_value == p->next_match_value))
p->flags &= ~FLAG_REPROGRAM;
}
p->flags &= ~FLAG_IRQCONTEXT;
return IRQ_HANDLED;
}
static int sh_cmt_start(struct sh_cmt_priv *p, unsigned long flag)
{
int ret = 0;
unsigned long flags;
raw_spin_lock_irqsave(&p->lock, flags);
if (!(p->flags & (FLAG_CLOCKEVENT | FLAG_CLOCKSOURCE)))
ret = sh_cmt_enable(p, &p->rate);
if (ret)
goto out;
p->flags |= flag;
if ((flag == FLAG_CLOCKSOURCE) && (!(p->flags & FLAG_CLOCKEVENT)))
__sh_cmt_set_next(p, p->max_match_value);
out:
raw_spin_unlock_irqrestore(&p->lock, flags);
return ret;
}
static void sh_cmt_stop(struct sh_cmt_priv *p, unsigned long flag)
{
unsigned long flags;
unsigned long f;
raw_spin_lock_irqsave(&p->lock, flags);
f = p->flags & (FLAG_CLOCKEVENT | FLAG_CLOCKSOURCE);
p->flags &= ~flag;
if (f && !(p->flags & (FLAG_CLOCKEVENT | FLAG_CLOCKSOURCE)))
sh_cmt_disable(p);
if ((flag == FLAG_CLOCKEVENT) && (p->flags & FLAG_CLOCKSOURCE))
__sh_cmt_set_next(p, p->max_match_value);
raw_spin_unlock_irqrestore(&p->lock, flags);
}
static struct sh_cmt_priv *cs_to_sh_cmt(struct clocksource *cs)
{
return container_of(cs, struct sh_cmt_priv, cs);
}
static cycle_t sh_cmt_clocksource_read(struct clocksource *cs)
{
struct sh_cmt_priv *p = cs_to_sh_cmt(cs);
unsigned long flags, raw;
unsigned long value;
int has_wrapped;
raw_spin_lock_irqsave(&p->lock, flags);
value = p->total_cycles;
raw = sh_cmt_get_counter(p, &has_wrapped);
if (unlikely(has_wrapped))
raw += p->match_value + 1;
raw_spin_unlock_irqrestore(&p->lock, flags);
return value + raw;
}
static int sh_cmt_clocksource_enable(struct clocksource *cs)
{
int ret;
struct sh_cmt_priv *p = cs_to_sh_cmt(cs);
WARN_ON(p->cs_enabled);
p->total_cycles = 0;
ret = sh_cmt_start(p, FLAG_CLOCKSOURCE);
if (!ret) {
__clocksource_updatefreq_hz(cs, p->rate);
p->cs_enabled = true;
}
return ret;
}
static void sh_cmt_clocksource_disable(struct clocksource *cs)
{
struct sh_cmt_priv *p = cs_to_sh_cmt(cs);
WARN_ON(!p->cs_enabled);
sh_cmt_stop(p, FLAG_CLOCKSOURCE);
p->cs_enabled = false;
}
static void sh_cmt_clocksource_suspend(struct clocksource *cs)
{
struct sh_cmt_priv *p = cs_to_sh_cmt(cs);
sh_cmt_stop(p, FLAG_CLOCKSOURCE);
pm_genpd_syscore_poweroff(&p->pdev->dev);
}
static void sh_cmt_clocksource_resume(struct clocksource *cs)
{
struct sh_cmt_priv *p = cs_to_sh_cmt(cs);
pm_genpd_syscore_poweron(&p->pdev->dev);
sh_cmt_start(p, FLAG_CLOCKSOURCE);
}
static int sh_cmt_register_clocksource(struct sh_cmt_priv *p,
char *name, unsigned long rating)
{
struct clocksource *cs = &p->cs;
cs->name = name;
cs->rating = rating;
cs->read = sh_cmt_clocksource_read;
cs->enable = sh_cmt_clocksource_enable;
cs->disable = sh_cmt_clocksource_disable;
cs->suspend = sh_cmt_clocksource_suspend;
cs->resume = sh_cmt_clocksource_resume;
cs->mask = CLOCKSOURCE_MASK(sizeof(unsigned long) * 8);
cs->flags = CLOCK_SOURCE_IS_CONTINUOUS;
dev_info(&p->pdev->dev, "used as clock source\n");
clocksource_register_hz(cs, 1);
return 0;
}
static struct sh_cmt_priv *ced_to_sh_cmt(struct clock_event_device *ced)
{
return container_of(ced, struct sh_cmt_priv, ced);
}
static void sh_cmt_clock_event_start(struct sh_cmt_priv *p, int periodic)
{
struct clock_event_device *ced = &p->ced;
sh_cmt_start(p, FLAG_CLOCKEVENT);
ced->shift = 32;
ced->mult = div_sc(p->rate, NSEC_PER_SEC, ced->shift);
ced->max_delta_ns = clockevent_delta2ns(p->max_match_value, ced);
ced->min_delta_ns = clockevent_delta2ns(0x1f, ced);
if (periodic)
sh_cmt_set_next(p, ((p->rate + HZ/2) / HZ) - 1);
else
sh_cmt_set_next(p, p->max_match_value);
}
static void sh_cmt_clock_event_mode(enum clock_event_mode mode,
struct clock_event_device *ced)
{
struct sh_cmt_priv *p = ced_to_sh_cmt(ced);
switch (ced->mode) {
case CLOCK_EVT_MODE_PERIODIC:
case CLOCK_EVT_MODE_ONESHOT:
sh_cmt_stop(p, FLAG_CLOCKEVENT);
break;
default:
break;
}
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
dev_info(&p->pdev->dev, "used for periodic clock events\n");
sh_cmt_clock_event_start(p, 1);
break;
case CLOCK_EVT_MODE_ONESHOT:
dev_info(&p->pdev->dev, "used for oneshot clock events\n");
sh_cmt_clock_event_start(p, 0);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
sh_cmt_stop(p, FLAG_CLOCKEVENT);
break;
default:
break;
}
}
static int sh_cmt_clock_event_next(unsigned long delta,
struct clock_event_device *ced)
{
struct sh_cmt_priv *p = ced_to_sh_cmt(ced);
BUG_ON(ced->mode != CLOCK_EVT_MODE_ONESHOT);
if (likely(p->flags & FLAG_IRQCONTEXT))
p->next_match_value = delta - 1;
else
sh_cmt_set_next(p, delta - 1);
return 0;
}
static void sh_cmt_clock_event_suspend(struct clock_event_device *ced)
{
pm_genpd_syscore_poweroff(&ced_to_sh_cmt(ced)->pdev->dev);
}
static void sh_cmt_clock_event_resume(struct clock_event_device *ced)
{
pm_genpd_syscore_poweron(&ced_to_sh_cmt(ced)->pdev->dev);
}
static void sh_cmt_register_clockevent(struct sh_cmt_priv *p,
char *name, unsigned long rating)
{
struct clock_event_device *ced = &p->ced;
memset(ced, 0, sizeof(*ced));
ced->name = name;
ced->features = CLOCK_EVT_FEAT_PERIODIC;
ced->features |= CLOCK_EVT_FEAT_ONESHOT;
ced->rating = rating;
ced->cpumask = cpumask_of(0);
ced->set_next_event = sh_cmt_clock_event_next;
ced->set_mode = sh_cmt_clock_event_mode;
ced->suspend = sh_cmt_clock_event_suspend;
ced->resume = sh_cmt_clock_event_resume;
dev_info(&p->pdev->dev, "used for clock events\n");
clockevents_register_device(ced);
}
static int sh_cmt_register(struct sh_cmt_priv *p, char *name,
unsigned long clockevent_rating,
unsigned long clocksource_rating)
{
if (clockevent_rating)
sh_cmt_register_clockevent(p, name, clockevent_rating);
if (clocksource_rating)
sh_cmt_register_clocksource(p, name, clocksource_rating);
return 0;
}
static int sh_cmt_setup(struct sh_cmt_priv *p, struct platform_device *pdev)
{
struct sh_timer_config *cfg = pdev->dev.platform_data;
struct resource *res, *res2;
int irq, ret;
ret = -ENXIO;
memset(p, 0, sizeof(*p));
p->pdev = pdev;
if (!cfg) {
dev_err(&p->pdev->dev, "missing platform data\n");
goto err0;
}
res = platform_get_resource(p->pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&p->pdev->dev, "failed to get I/O memory\n");
goto err0;
}
res2 = platform_get_resource(p->pdev, IORESOURCE_MEM, 1);
irq = platform_get_irq(p->pdev, 0);
if (irq < 0) {
dev_err(&p->pdev->dev, "failed to get irq\n");
goto err0;
}
p->mapbase = ioremap_nocache(res->start, resource_size(res));
if (p->mapbase == NULL) {
dev_err(&p->pdev->dev, "failed to remap I/O memory\n");
goto err0;
}
p->mapbase_str = ioremap_nocache(res2 ? res2->start :
res->start - cfg->channel_offset,
res2 ? resource_size(res2) : 2);
if (p->mapbase_str == NULL) {
dev_err(&p->pdev->dev, "failed to remap I/O second memory\n");
goto err1;
}
p->irqaction.name = dev_name(&p->pdev->dev);
p->irqaction.handler = sh_cmt_interrupt;
p->irqaction.dev_id = p;
p->irqaction.flags = IRQF_DISABLED | IRQF_TIMER | \
IRQF_IRQPOLL | IRQF_NOBALANCING;
p->clk = clk_get(&p->pdev->dev, "cmt_fck");
if (IS_ERR(p->clk)) {
dev_err(&p->pdev->dev, "cannot get clock\n");
ret = PTR_ERR(p->clk);
goto err2;
}
if (res2 && (resource_size(res2) == 4)) {
p->read_control = sh_cmt_read32;
p->write_control = sh_cmt_write32;
} else {
p->read_control = sh_cmt_read16;
p->write_control = sh_cmt_write16;
}
if (resource_size(res) == 6) {
p->width = 16;
p->read_count = sh_cmt_read16;
p->write_count = sh_cmt_write16;
p->overflow_bit = 0x80;
p->clear_bits = ~0x80;
} else {
p->width = 32;
p->read_count = sh_cmt_read32;
p->write_count = sh_cmt_write32;
p->overflow_bit = 0x8000;
p->clear_bits = ~0xc000;
}
if (p->width == (sizeof(p->max_match_value) * 8))
p->max_match_value = ~0;
else
p->max_match_value = (1 << p->width) - 1;
p->match_value = p->max_match_value;
raw_spin_lock_init(&p->lock);
ret = sh_cmt_register(p, (char *)dev_name(&p->pdev->dev),
cfg->clockevent_rating,
cfg->clocksource_rating);
if (ret) {
dev_err(&p->pdev->dev, "registration failed\n");
goto err3;
}
p->cs_enabled = false;
ret = setup_irq(irq, &p->irqaction);
if (ret) {
dev_err(&p->pdev->dev, "failed to request irq %d\n", irq);
goto err3;
}
platform_set_drvdata(pdev, p);
return 0;
err3:
clk_put(p->clk);
err2:
iounmap(p->mapbase_str);
err1:
iounmap(p->mapbase);
err0:
return ret;
}
static int sh_cmt_probe(struct platform_device *pdev)
{
struct sh_cmt_priv *p = platform_get_drvdata(pdev);
struct sh_timer_config *cfg = pdev->dev.platform_data;
int ret;
if (!is_early_platform_device(pdev)) {
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
}
if (p) {
dev_info(&pdev->dev, "kept as earlytimer\n");
goto out;
}
p = kmalloc(sizeof(*p), GFP_KERNEL);
if (p == NULL) {
dev_err(&pdev->dev, "failed to allocate driver data\n");
return -ENOMEM;
}
ret = sh_cmt_setup(p, pdev);
if (ret) {
kfree(p);
pm_runtime_idle(&pdev->dev);
return ret;
}
if (is_early_platform_device(pdev))
return 0;
out:
if (cfg->clockevent_rating || cfg->clocksource_rating)
pm_runtime_irq_safe(&pdev->dev);
else
pm_runtime_idle(&pdev->dev);
return 0;
}
static int sh_cmt_remove(struct platform_device *pdev)
{
return -EBUSY;
}
static int __init sh_cmt_init(void)
{
return platform_driver_register(&sh_cmt_device_driver);
}
static void __exit sh_cmt_exit(void)
{
platform_driver_unregister(&sh_cmt_device_driver);
}
