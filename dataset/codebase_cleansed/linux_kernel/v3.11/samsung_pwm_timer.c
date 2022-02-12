static void samsung_timer_set_prescale(unsigned int channel, u16 prescale)
{
unsigned long flags;
u8 shift = 0;
u32 reg;
if (channel >= 2)
shift = TCFG0_PRESCALER1_SHIFT;
spin_lock_irqsave(&samsung_pwm_lock, flags);
reg = readl(pwm.base + REG_TCFG0);
reg &= ~(TCFG0_PRESCALER_MASK << shift);
reg |= (prescale - 1) << shift;
writel(reg, pwm.base + REG_TCFG0);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static void samsung_timer_set_divisor(unsigned int channel, u8 divisor)
{
u8 shift = TCFG1_SHIFT(channel);
unsigned long flags;
u32 reg;
u8 bits;
bits = (fls(divisor) - 1) - pwm.variant.div_base;
spin_lock_irqsave(&samsung_pwm_lock, flags);
reg = readl(pwm.base + REG_TCFG1);
reg &= ~(TCFG1_MUX_MASK << shift);
reg |= bits << shift;
writel(reg, pwm.base + REG_TCFG1);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static void samsung_time_stop(unsigned int channel)
{
unsigned long tcon;
unsigned long flags;
if (channel > 0)
++channel;
spin_lock_irqsave(&samsung_pwm_lock, flags);
tcon = __raw_readl(pwm.base + REG_TCON);
tcon &= ~TCON_START(channel);
__raw_writel(tcon, pwm.base + REG_TCON);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static void samsung_time_setup(unsigned int channel, unsigned long tcnt)
{
unsigned long tcon;
unsigned long flags;
unsigned int tcon_chan = channel;
if (tcon_chan > 0)
++tcon_chan;
spin_lock_irqsave(&samsung_pwm_lock, flags);
tcon = __raw_readl(pwm.base + REG_TCON);
tcon &= ~(TCON_START(tcon_chan) | TCON_AUTORELOAD(tcon_chan));
tcon |= TCON_MANUALUPDATE(tcon_chan);
__raw_writel(tcnt, pwm.base + REG_TCNTB(channel));
__raw_writel(tcnt, pwm.base + REG_TCMPB(channel));
__raw_writel(tcon, pwm.base + REG_TCON);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static void samsung_time_start(unsigned int channel, bool periodic)
{
unsigned long tcon;
unsigned long flags;
if (channel > 0)
++channel;
spin_lock_irqsave(&samsung_pwm_lock, flags);
tcon = __raw_readl(pwm.base + REG_TCON);
tcon &= ~TCON_MANUALUPDATE(channel);
tcon |= TCON_START(channel);
if (periodic)
tcon |= TCON_AUTORELOAD(channel);
else
tcon &= ~TCON_AUTORELOAD(channel);
__raw_writel(tcon, pwm.base + REG_TCON);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static int samsung_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
if (!cycles)
cycles = 1;
samsung_time_setup(pwm.event_id, cycles);
samsung_time_start(pwm.event_id, false);
return 0;
}
static void samsung_timer_resume(void)
{
samsung_time_setup(pwm.event_id, pwm.clock_count_per_tick - 1);
samsung_time_start(pwm.event_id, true);
samsung_time_setup(pwm.source_id, pwm.tcnt_max);
samsung_time_start(pwm.source_id, true);
}
static void samsung_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
samsung_time_stop(pwm.event_id);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
samsung_time_setup(pwm.event_id, pwm.clock_count_per_tick - 1);
samsung_time_start(pwm.event_id, true);
break;
case CLOCK_EVT_MODE_ONESHOT:
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
break;
case CLOCK_EVT_MODE_RESUME:
samsung_timer_resume();
break;
}
}
static irqreturn_t samsung_clock_event_isr(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
if (pwm.variant.has_tint_cstat) {
u32 mask = (1 << pwm.event_id);
writel(mask | (mask << 5), pwm.base + REG_TINT_CSTAT);
}
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init samsung_clockevent_init(void)
{
unsigned long pclk;
unsigned long clock_rate;
unsigned int irq_number;
pclk = clk_get_rate(pwm.timerclk);
samsung_timer_set_prescale(pwm.event_id, pwm.tscaler_div);
samsung_timer_set_divisor(pwm.event_id, pwm.tdiv);
clock_rate = pclk / (pwm.tscaler_div * pwm.tdiv);
pwm.clock_count_per_tick = clock_rate / HZ;
time_event_device.cpumask = cpumask_of(0);
clockevents_config_and_register(&time_event_device,
clock_rate, 1, pwm.tcnt_max);
irq_number = pwm.irq[pwm.event_id];
setup_irq(irq_number, &samsung_clock_event_irq);
if (pwm.variant.has_tint_cstat) {
u32 mask = (1 << pwm.event_id);
writel(mask | (mask << 5), pwm.base + REG_TINT_CSTAT);
}
}
static void __iomem *samsung_timer_reg(void)
{
switch (pwm.source_id) {
case 0:
case 1:
case 2:
case 3:
return pwm.base + pwm.source_id * 0x0c + 0x14;
case 4:
return pwm.base + 0x40;
default:
BUG();
}
}
static u32 notrace samsung_read_sched_clock(void)
{
void __iomem *reg = samsung_timer_reg();
if (!reg)
return 0;
return ~__raw_readl(reg);
}
static void __init samsung_clocksource_init(void)
{
void __iomem *reg = samsung_timer_reg();
unsigned long pclk;
unsigned long clock_rate;
int ret;
pclk = clk_get_rate(pwm.timerclk);
samsung_timer_set_prescale(pwm.source_id, pwm.tscaler_div);
samsung_timer_set_divisor(pwm.source_id, pwm.tdiv);
clock_rate = pclk / (pwm.tscaler_div * pwm.tdiv);
samsung_time_setup(pwm.source_id, pwm.tcnt_max);
samsung_time_start(pwm.source_id, true);
setup_sched_clock(samsung_read_sched_clock,
pwm.variant.bits, clock_rate);
ret = clocksource_mmio_init(reg, "samsung_clocksource_timer",
clock_rate, 250, pwm.variant.bits,
clocksource_mmio_readl_down);
if (ret)
panic("samsung_clocksource_timer: can't register clocksource\n");
}
static void __init samsung_timer_resources(void)
{
pwm.timerclk = clk_get(NULL, "timers");
if (IS_ERR(pwm.timerclk))
panic("failed to get timers clock for timer");
clk_prepare_enable(pwm.timerclk);
pwm.tcnt_max = (1UL << pwm.variant.bits) - 1;
if (pwm.variant.bits == 16) {
pwm.tscaler_div = 25;
pwm.tdiv = 2;
} else {
pwm.tscaler_div = 2;
pwm.tdiv = 1;
}
}
static void __init _samsung_pwm_clocksource_init(void)
{
u8 mask;
int channel;
mask = ~pwm.variant.output_mask & ((1 << SAMSUNG_PWM_NUM) - 1);
channel = fls(mask) - 1;
if (channel < 0)
panic("failed to find PWM channel for clocksource");
pwm.source_id = channel;
mask &= ~(1 << channel);
channel = fls(mask) - 1;
if (channel < 0)
panic("failed to find PWM channel for clock event");
pwm.event_id = channel;
samsung_timer_resources();
samsung_clockevent_init();
samsung_clocksource_init();
}
void __init samsung_pwm_clocksource_init(void __iomem *base,
unsigned int *irqs, struct samsung_pwm_variant *variant)
{
pwm.base = base;
memcpy(&pwm.variant, variant, sizeof(pwm.variant));
memcpy(pwm.irq, irqs, SAMSUNG_PWM_NUM * sizeof(*irqs));
_samsung_pwm_clocksource_init();
}
static void __init samsung_pwm_alloc(struct device_node *np,
const struct samsung_pwm_variant *variant)
{
struct resource res;
struct property *prop;
const __be32 *cur;
u32 val;
int i;
memcpy(&pwm.variant, variant, sizeof(pwm.variant));
for (i = 0; i < SAMSUNG_PWM_NUM; ++i)
pwm.irq[i] = irq_of_parse_and_map(np, i);
of_property_for_each_u32(np, "samsung,pwm-outputs", prop, cur, val) {
if (val >= SAMSUNG_PWM_NUM) {
pr_warning("%s: invalid channel index in samsung,pwm-outputs property\n",
__func__);
continue;
}
pwm.variant.output_mask |= 1 << val;
}
of_address_to_resource(np, 0, &res);
if (!request_mem_region(res.start,
resource_size(&res), "samsung-pwm")) {
pr_err("%s: failed to request IO mem region\n", __func__);
return;
}
pwm.base = ioremap(res.start, resource_size(&res));
if (!pwm.base) {
pr_err("%s: failed to map PWM registers\n", __func__);
release_mem_region(res.start, resource_size(&res));
return;
}
_samsung_pwm_clocksource_init();
}
static void __init s3c2410_pwm_clocksource_init(struct device_node *np)
{
samsung_pwm_alloc(np, &s3c24xx_variant);
}
static void __init s3c64xx_pwm_clocksource_init(struct device_node *np)
{
samsung_pwm_alloc(np, &s3c64xx_variant);
}
static void __init s5p64x0_pwm_clocksource_init(struct device_node *np)
{
samsung_pwm_alloc(np, &s5p64x0_variant);
}
static void __init s5p_pwm_clocksource_init(struct device_node *np)
{
samsung_pwm_alloc(np, &s5p_variant);
}
