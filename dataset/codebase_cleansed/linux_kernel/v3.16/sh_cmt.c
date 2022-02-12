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
static inline unsigned long sh_cmt_read_cmstr(struct sh_cmt_channel *ch)
{
if (ch->iostart)
return ch->cmt->info->read_control(ch->iostart, 0);
else
return ch->cmt->info->read_control(ch->cmt->mapbase, 0);
}
static inline void sh_cmt_write_cmstr(struct sh_cmt_channel *ch,
unsigned long value)
{
if (ch->iostart)
ch->cmt->info->write_control(ch->iostart, 0, value);
else
ch->cmt->info->write_control(ch->cmt->mapbase, 0, value);
}
static inline unsigned long sh_cmt_read_cmcsr(struct sh_cmt_channel *ch)
{
return ch->cmt->info->read_control(ch->ioctrl, CMCSR);
}
static inline void sh_cmt_write_cmcsr(struct sh_cmt_channel *ch,
unsigned long value)
{
ch->cmt->info->write_control(ch->ioctrl, CMCSR, value);
}
static inline unsigned long sh_cmt_read_cmcnt(struct sh_cmt_channel *ch)
{
return ch->cmt->info->read_count(ch->ioctrl, CMCNT);
}
static inline void sh_cmt_write_cmcnt(struct sh_cmt_channel *ch,
unsigned long value)
{
ch->cmt->info->write_count(ch->ioctrl, CMCNT, value);
}
static inline void sh_cmt_write_cmcor(struct sh_cmt_channel *ch,
unsigned long value)
{
ch->cmt->info->write_count(ch->ioctrl, CMCOR, value);
}
static unsigned long sh_cmt_get_counter(struct sh_cmt_channel *ch,
int *has_wrapped)
{
unsigned long v1, v2, v3;
int o1, o2;
o1 = sh_cmt_read_cmcsr(ch) & ch->cmt->info->overflow_bit;
do {
o2 = o1;
v1 = sh_cmt_read_cmcnt(ch);
v2 = sh_cmt_read_cmcnt(ch);
v3 = sh_cmt_read_cmcnt(ch);
o1 = sh_cmt_read_cmcsr(ch) & ch->cmt->info->overflow_bit;
} while (unlikely((o1 != o2) || (v1 > v2 && v1 < v3)
|| (v2 > v3 && v2 < v1) || (v3 > v1 && v3 < v2)));
*has_wrapped = o1;
return v2;
}
static void sh_cmt_start_stop_ch(struct sh_cmt_channel *ch, int start)
{
unsigned long flags, value;
raw_spin_lock_irqsave(&sh_cmt_lock, flags);
value = sh_cmt_read_cmstr(ch);
if (start)
value |= 1 << ch->timer_bit;
else
value &= ~(1 << ch->timer_bit);
sh_cmt_write_cmstr(ch, value);
raw_spin_unlock_irqrestore(&sh_cmt_lock, flags);
}
static int sh_cmt_enable(struct sh_cmt_channel *ch, unsigned long *rate)
{
int k, ret;
pm_runtime_get_sync(&ch->cmt->pdev->dev);
dev_pm_syscore_device(&ch->cmt->pdev->dev, true);
ret = clk_enable(ch->cmt->clk);
if (ret) {
dev_err(&ch->cmt->pdev->dev, "ch%u: cannot enable clock\n",
ch->index);
goto err0;
}
sh_cmt_start_stop_ch(ch, 0);
if (ch->cmt->info->width == 16) {
*rate = clk_get_rate(ch->cmt->clk) / 512;
sh_cmt_write_cmcsr(ch, SH_CMT16_CMCSR_CMIE |
SH_CMT16_CMCSR_CKS512);
} else {
*rate = clk_get_rate(ch->cmt->clk) / 8;
sh_cmt_write_cmcsr(ch, SH_CMT32_CMCSR_CMM |
SH_CMT32_CMCSR_CMTOUT_IE |
SH_CMT32_CMCSR_CMR_IRQ |
SH_CMT32_CMCSR_CKS_RCLK8);
}
sh_cmt_write_cmcor(ch, 0xffffffff);
sh_cmt_write_cmcnt(ch, 0);
for (k = 0; k < 100; k++) {
if (!sh_cmt_read_cmcnt(ch))
break;
udelay(1);
}
if (sh_cmt_read_cmcnt(ch)) {
dev_err(&ch->cmt->pdev->dev, "ch%u: cannot clear CMCNT\n",
ch->index);
ret = -ETIMEDOUT;
goto err1;
}
sh_cmt_start_stop_ch(ch, 1);
return 0;
err1:
clk_disable(ch->cmt->clk);
err0:
return ret;
}
static void sh_cmt_disable(struct sh_cmt_channel *ch)
{
sh_cmt_start_stop_ch(ch, 0);
sh_cmt_write_cmcsr(ch, 0);
clk_disable(ch->cmt->clk);
dev_pm_syscore_device(&ch->cmt->pdev->dev, false);
pm_runtime_put(&ch->cmt->pdev->dev);
}
static void sh_cmt_clock_event_program_verify(struct sh_cmt_channel *ch,
int absolute)
{
unsigned long new_match;
unsigned long value = ch->next_match_value;
unsigned long delay = 0;
unsigned long now = 0;
int has_wrapped;
now = sh_cmt_get_counter(ch, &has_wrapped);
ch->flags |= FLAG_REPROGRAM;
if (has_wrapped) {
ch->flags |= FLAG_SKIPEVENT;
return;
}
if (absolute)
now = 0;
do {
new_match = now + value + delay;
if (new_match > ch->max_match_value)
new_match = ch->max_match_value;
sh_cmt_write_cmcor(ch, new_match);
now = sh_cmt_get_counter(ch, &has_wrapped);
if (has_wrapped && (new_match > ch->match_value)) {
ch->flags |= FLAG_SKIPEVENT;
break;
}
if (has_wrapped) {
ch->match_value = new_match;
break;
}
if (now < new_match) {
ch->match_value = new_match;
break;
}
if (delay)
delay <<= 1;
else
delay = 1;
if (!delay)
dev_warn(&ch->cmt->pdev->dev, "ch%u: too long delay\n",
ch->index);
} while (delay);
}
static void __sh_cmt_set_next(struct sh_cmt_channel *ch, unsigned long delta)
{
if (delta > ch->max_match_value)
dev_warn(&ch->cmt->pdev->dev, "ch%u: delta out of range\n",
ch->index);
ch->next_match_value = delta;
sh_cmt_clock_event_program_verify(ch, 0);
}
static void sh_cmt_set_next(struct sh_cmt_channel *ch, unsigned long delta)
{
unsigned long flags;
raw_spin_lock_irqsave(&ch->lock, flags);
__sh_cmt_set_next(ch, delta);
raw_spin_unlock_irqrestore(&ch->lock, flags);
}
static irqreturn_t sh_cmt_interrupt(int irq, void *dev_id)
{
struct sh_cmt_channel *ch = dev_id;
sh_cmt_write_cmcsr(ch, sh_cmt_read_cmcsr(ch) &
ch->cmt->info->clear_bits);
if (ch->flags & FLAG_CLOCKSOURCE)
ch->total_cycles += ch->match_value + 1;
if (!(ch->flags & FLAG_REPROGRAM))
ch->next_match_value = ch->max_match_value;
ch->flags |= FLAG_IRQCONTEXT;
if (ch->flags & FLAG_CLOCKEVENT) {
if (!(ch->flags & FLAG_SKIPEVENT)) {
if (ch->ced.mode == CLOCK_EVT_MODE_ONESHOT) {
ch->next_match_value = ch->max_match_value;
ch->flags |= FLAG_REPROGRAM;
}
ch->ced.event_handler(&ch->ced);
}
}
ch->flags &= ~FLAG_SKIPEVENT;
if (ch->flags & FLAG_REPROGRAM) {
ch->flags &= ~FLAG_REPROGRAM;
sh_cmt_clock_event_program_verify(ch, 1);
if (ch->flags & FLAG_CLOCKEVENT)
if ((ch->ced.mode == CLOCK_EVT_MODE_SHUTDOWN)
|| (ch->match_value == ch->next_match_value))
ch->flags &= ~FLAG_REPROGRAM;
}
ch->flags &= ~FLAG_IRQCONTEXT;
return IRQ_HANDLED;
}
static int sh_cmt_start(struct sh_cmt_channel *ch, unsigned long flag)
{
int ret = 0;
unsigned long flags;
raw_spin_lock_irqsave(&ch->lock, flags);
if (!(ch->flags & (FLAG_CLOCKEVENT | FLAG_CLOCKSOURCE)))
ret = sh_cmt_enable(ch, &ch->rate);
if (ret)
goto out;
ch->flags |= flag;
if ((flag == FLAG_CLOCKSOURCE) && (!(ch->flags & FLAG_CLOCKEVENT)))
__sh_cmt_set_next(ch, ch->max_match_value);
out:
raw_spin_unlock_irqrestore(&ch->lock, flags);
return ret;
}
static void sh_cmt_stop(struct sh_cmt_channel *ch, unsigned long flag)
{
unsigned long flags;
unsigned long f;
raw_spin_lock_irqsave(&ch->lock, flags);
f = ch->flags & (FLAG_CLOCKEVENT | FLAG_CLOCKSOURCE);
ch->flags &= ~flag;
if (f && !(ch->flags & (FLAG_CLOCKEVENT | FLAG_CLOCKSOURCE)))
sh_cmt_disable(ch);
if ((flag == FLAG_CLOCKEVENT) && (ch->flags & FLAG_CLOCKSOURCE))
__sh_cmt_set_next(ch, ch->max_match_value);
raw_spin_unlock_irqrestore(&ch->lock, flags);
}
static struct sh_cmt_channel *cs_to_sh_cmt(struct clocksource *cs)
{
return container_of(cs, struct sh_cmt_channel, cs);
}
static cycle_t sh_cmt_clocksource_read(struct clocksource *cs)
{
struct sh_cmt_channel *ch = cs_to_sh_cmt(cs);
unsigned long flags, raw;
unsigned long value;
int has_wrapped;
raw_spin_lock_irqsave(&ch->lock, flags);
value = ch->total_cycles;
raw = sh_cmt_get_counter(ch, &has_wrapped);
if (unlikely(has_wrapped))
raw += ch->match_value + 1;
raw_spin_unlock_irqrestore(&ch->lock, flags);
return value + raw;
}
static int sh_cmt_clocksource_enable(struct clocksource *cs)
{
int ret;
struct sh_cmt_channel *ch = cs_to_sh_cmt(cs);
WARN_ON(ch->cs_enabled);
ch->total_cycles = 0;
ret = sh_cmt_start(ch, FLAG_CLOCKSOURCE);
if (!ret) {
__clocksource_updatefreq_hz(cs, ch->rate);
ch->cs_enabled = true;
}
return ret;
}
static void sh_cmt_clocksource_disable(struct clocksource *cs)
{
struct sh_cmt_channel *ch = cs_to_sh_cmt(cs);
WARN_ON(!ch->cs_enabled);
sh_cmt_stop(ch, FLAG_CLOCKSOURCE);
ch->cs_enabled = false;
}
static void sh_cmt_clocksource_suspend(struct clocksource *cs)
{
struct sh_cmt_channel *ch = cs_to_sh_cmt(cs);
sh_cmt_stop(ch, FLAG_CLOCKSOURCE);
pm_genpd_syscore_poweroff(&ch->cmt->pdev->dev);
}
static void sh_cmt_clocksource_resume(struct clocksource *cs)
{
struct sh_cmt_channel *ch = cs_to_sh_cmt(cs);
pm_genpd_syscore_poweron(&ch->cmt->pdev->dev);
sh_cmt_start(ch, FLAG_CLOCKSOURCE);
}
static int sh_cmt_register_clocksource(struct sh_cmt_channel *ch,
const char *name)
{
struct clocksource *cs = &ch->cs;
cs->name = name;
cs->rating = 125;
cs->read = sh_cmt_clocksource_read;
cs->enable = sh_cmt_clocksource_enable;
cs->disable = sh_cmt_clocksource_disable;
cs->suspend = sh_cmt_clocksource_suspend;
cs->resume = sh_cmt_clocksource_resume;
cs->mask = CLOCKSOURCE_MASK(sizeof(unsigned long) * 8);
cs->flags = CLOCK_SOURCE_IS_CONTINUOUS;
dev_info(&ch->cmt->pdev->dev, "ch%u: used as clock source\n",
ch->index);
clocksource_register_hz(cs, 1);
return 0;
}
static struct sh_cmt_channel *ced_to_sh_cmt(struct clock_event_device *ced)
{
return container_of(ced, struct sh_cmt_channel, ced);
}
static void sh_cmt_clock_event_start(struct sh_cmt_channel *ch, int periodic)
{
struct clock_event_device *ced = &ch->ced;
sh_cmt_start(ch, FLAG_CLOCKEVENT);
ced->shift = 32;
ced->mult = div_sc(ch->rate, NSEC_PER_SEC, ced->shift);
ced->max_delta_ns = clockevent_delta2ns(ch->max_match_value, ced);
ced->min_delta_ns = clockevent_delta2ns(0x1f, ced);
if (periodic)
sh_cmt_set_next(ch, ((ch->rate + HZ/2) / HZ) - 1);
else
sh_cmt_set_next(ch, ch->max_match_value);
}
static void sh_cmt_clock_event_mode(enum clock_event_mode mode,
struct clock_event_device *ced)
{
struct sh_cmt_channel *ch = ced_to_sh_cmt(ced);
switch (ced->mode) {
case CLOCK_EVT_MODE_PERIODIC:
case CLOCK_EVT_MODE_ONESHOT:
sh_cmt_stop(ch, FLAG_CLOCKEVENT);
break;
default:
break;
}
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
dev_info(&ch->cmt->pdev->dev,
"ch%u: used for periodic clock events\n", ch->index);
sh_cmt_clock_event_start(ch, 1);
break;
case CLOCK_EVT_MODE_ONESHOT:
dev_info(&ch->cmt->pdev->dev,
"ch%u: used for oneshot clock events\n", ch->index);
sh_cmt_clock_event_start(ch, 0);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
sh_cmt_stop(ch, FLAG_CLOCKEVENT);
break;
default:
break;
}
}
static int sh_cmt_clock_event_next(unsigned long delta,
struct clock_event_device *ced)
{
struct sh_cmt_channel *ch = ced_to_sh_cmt(ced);
BUG_ON(ced->mode != CLOCK_EVT_MODE_ONESHOT);
if (likely(ch->flags & FLAG_IRQCONTEXT))
ch->next_match_value = delta - 1;
else
sh_cmt_set_next(ch, delta - 1);
return 0;
}
static void sh_cmt_clock_event_suspend(struct clock_event_device *ced)
{
struct sh_cmt_channel *ch = ced_to_sh_cmt(ced);
pm_genpd_syscore_poweroff(&ch->cmt->pdev->dev);
clk_unprepare(ch->cmt->clk);
}
static void sh_cmt_clock_event_resume(struct clock_event_device *ced)
{
struct sh_cmt_channel *ch = ced_to_sh_cmt(ced);
clk_prepare(ch->cmt->clk);
pm_genpd_syscore_poweron(&ch->cmt->pdev->dev);
}
static int sh_cmt_register_clockevent(struct sh_cmt_channel *ch,
const char *name)
{
struct clock_event_device *ced = &ch->ced;
int irq;
int ret;
irq = platform_get_irq(ch->cmt->pdev, ch->cmt->legacy ? 0 : ch->index);
if (irq < 0) {
dev_err(&ch->cmt->pdev->dev, "ch%u: failed to get irq\n",
ch->index);
return irq;
}
ret = request_irq(irq, sh_cmt_interrupt,
IRQF_TIMER | IRQF_IRQPOLL | IRQF_NOBALANCING,
dev_name(&ch->cmt->pdev->dev), ch);
if (ret) {
dev_err(&ch->cmt->pdev->dev, "ch%u: failed to request irq %d\n",
ch->index, irq);
return ret;
}
ced->name = name;
ced->features = CLOCK_EVT_FEAT_PERIODIC;
ced->features |= CLOCK_EVT_FEAT_ONESHOT;
ced->rating = 125;
ced->cpumask = cpu_possible_mask;
ced->set_next_event = sh_cmt_clock_event_next;
ced->set_mode = sh_cmt_clock_event_mode;
ced->suspend = sh_cmt_clock_event_suspend;
ced->resume = sh_cmt_clock_event_resume;
dev_info(&ch->cmt->pdev->dev, "ch%u: used for clock events\n",
ch->index);
clockevents_register_device(ced);
return 0;
}
static int sh_cmt_register(struct sh_cmt_channel *ch, const char *name,
bool clockevent, bool clocksource)
{
int ret;
if (clockevent) {
ch->cmt->has_clockevent = true;
ret = sh_cmt_register_clockevent(ch, name);
if (ret < 0)
return ret;
}
if (clocksource) {
ch->cmt->has_clocksource = true;
sh_cmt_register_clocksource(ch, name);
}
return 0;
}
static int sh_cmt_setup_channel(struct sh_cmt_channel *ch, unsigned int index,
unsigned int hwidx, bool clockevent,
bool clocksource, struct sh_cmt_device *cmt)
{
int ret;
if (!clockevent && !clocksource)
return 0;
ch->cmt = cmt;
ch->index = index;
ch->hwidx = hwidx;
if (cmt->legacy) {
ch->ioctrl = cmt->mapbase_ch;
} else {
switch (cmt->info->model) {
case SH_CMT_16BIT:
ch->ioctrl = cmt->mapbase + 2 + ch->hwidx * 6;
break;
case SH_CMT_32BIT:
case SH_CMT_48BIT:
ch->ioctrl = cmt->mapbase + 0x10 + ch->hwidx * 0x10;
break;
case SH_CMT_32BIT_FAST:
ch->ioctrl = cmt->mapbase + 0x40;
break;
case SH_CMT_48BIT_GEN2:
ch->iostart = cmt->mapbase + ch->hwidx * 0x100;
ch->ioctrl = ch->iostart + 0x10;
break;
}
}
if (cmt->info->width == (sizeof(ch->max_match_value) * 8))
ch->max_match_value = ~0;
else
ch->max_match_value = (1 << cmt->info->width) - 1;
ch->match_value = ch->max_match_value;
raw_spin_lock_init(&ch->lock);
if (cmt->legacy) {
ch->timer_bit = ch->hwidx;
} else {
ch->timer_bit = cmt->info->model == SH_CMT_48BIT_GEN2
? 0 : ch->hwidx;
}
ret = sh_cmt_register(ch, dev_name(&cmt->pdev->dev),
clockevent, clocksource);
if (ret) {
dev_err(&cmt->pdev->dev, "ch%u: registration failed\n",
ch->index);
return ret;
}
ch->cs_enabled = false;
return 0;
}
static int sh_cmt_map_memory(struct sh_cmt_device *cmt)
{
struct resource *mem;
mem = platform_get_resource(cmt->pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&cmt->pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
cmt->mapbase = ioremap_nocache(mem->start, resource_size(mem));
if (cmt->mapbase == NULL) {
dev_err(&cmt->pdev->dev, "failed to remap I/O memory\n");
return -ENXIO;
}
return 0;
}
static int sh_cmt_map_memory_legacy(struct sh_cmt_device *cmt)
{
struct sh_timer_config *cfg = cmt->pdev->dev.platform_data;
struct resource *res, *res2;
res = platform_get_resource(cmt->pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&cmt->pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
cmt->mapbase_ch = ioremap_nocache(res->start, resource_size(res));
if (cmt->mapbase_ch == NULL) {
dev_err(&cmt->pdev->dev, "failed to remap I/O memory\n");
return -ENXIO;
}
res2 = platform_get_resource(cmt->pdev, IORESOURCE_MEM, 1);
cmt->mapbase = ioremap_nocache(res2 ? res2->start :
res->start - cfg->channel_offset,
res2 ? resource_size(res2) : 2);
if (cmt->mapbase == NULL) {
dev_err(&cmt->pdev->dev, "failed to remap I/O second memory\n");
iounmap(cmt->mapbase_ch);
return -ENXIO;
}
if (resource_size(res) == 6)
cmt->info = &sh_cmt_info[SH_CMT_16BIT];
else if (res2 && (resource_size(res2) == 4))
cmt->info = &sh_cmt_info[SH_CMT_48BIT_GEN2];
else
cmt->info = &sh_cmt_info[SH_CMT_32BIT];
return 0;
}
static void sh_cmt_unmap_memory(struct sh_cmt_device *cmt)
{
iounmap(cmt->mapbase);
if (cmt->mapbase_ch)
iounmap(cmt->mapbase_ch);
}
static int sh_cmt_setup(struct sh_cmt_device *cmt, struct platform_device *pdev)
{
struct sh_timer_config *cfg = pdev->dev.platform_data;
const struct platform_device_id *id = pdev->id_entry;
unsigned int hw_channels;
int ret;
memset(cmt, 0, sizeof(*cmt));
cmt->pdev = pdev;
if (!cfg) {
dev_err(&cmt->pdev->dev, "missing platform data\n");
return -ENXIO;
}
cmt->info = (const struct sh_cmt_info *)id->driver_data;
cmt->legacy = cmt->info ? false : true;
cmt->clk = clk_get(&cmt->pdev->dev, cmt->legacy ? "cmt_fck" : "fck");
if (IS_ERR(cmt->clk)) {
dev_err(&cmt->pdev->dev, "cannot get clock\n");
return PTR_ERR(cmt->clk);
}
ret = clk_prepare(cmt->clk);
if (ret < 0)
goto err_clk_put;
if (cmt->legacy)
ret = sh_cmt_map_memory_legacy(cmt);
else
ret = sh_cmt_map_memory(cmt);
if (ret < 0)
goto err_clk_unprepare;
if (cmt->legacy) {
cmt->num_channels = 1;
hw_channels = 0;
} else {
cmt->num_channels = hweight8(cfg->channels_mask);
hw_channels = cfg->channels_mask;
}
cmt->channels = kzalloc(cmt->num_channels * sizeof(*cmt->channels),
GFP_KERNEL);
if (cmt->channels == NULL) {
ret = -ENOMEM;
goto err_unmap;
}
if (cmt->legacy) {
ret = sh_cmt_setup_channel(&cmt->channels[0],
cfg->timer_bit, cfg->timer_bit,
cfg->clockevent_rating != 0,
cfg->clocksource_rating != 0, cmt);
if (ret < 0)
goto err_unmap;
} else {
unsigned int mask = hw_channels;
unsigned int i;
for (i = 0; i < cmt->num_channels; ++i) {
unsigned int hwidx = ffs(mask) - 1;
bool clocksource = i == 1 || cmt->num_channels == 1;
bool clockevent = i == 0;
ret = sh_cmt_setup_channel(&cmt->channels[i], i, hwidx,
clockevent, clocksource,
cmt);
if (ret < 0)
goto err_unmap;
mask &= ~(1 << hwidx);
}
}
platform_set_drvdata(pdev, cmt);
return 0;
err_unmap:
kfree(cmt->channels);
sh_cmt_unmap_memory(cmt);
err_clk_unprepare:
clk_unprepare(cmt->clk);
err_clk_put:
clk_put(cmt->clk);
return ret;
}
static int sh_cmt_probe(struct platform_device *pdev)
{
struct sh_cmt_device *cmt = platform_get_drvdata(pdev);
int ret;
if (!is_early_platform_device(pdev)) {
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
}
if (cmt) {
dev_info(&pdev->dev, "kept as earlytimer\n");
goto out;
}
cmt = kzalloc(sizeof(*cmt), GFP_KERNEL);
if (cmt == NULL)
return -ENOMEM;
ret = sh_cmt_setup(cmt, pdev);
if (ret) {
kfree(cmt);
pm_runtime_idle(&pdev->dev);
return ret;
}
if (is_early_platform_device(pdev))
return 0;
out:
if (cmt->has_clockevent || cmt->has_clocksource)
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
