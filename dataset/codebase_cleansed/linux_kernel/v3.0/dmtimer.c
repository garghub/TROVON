static inline u32 omap_dm_timer_read_reg(struct omap_dm_timer *timer, u32 reg)
{
if (timer->posted)
while (readl(timer->io_base + (OMAP_TIMER_WRITE_PEND_REG & 0xff))
& (reg >> WPSHIFT))
cpu_relax();
return readl(timer->io_base + (reg & 0xff));
}
static void omap_dm_timer_write_reg(struct omap_dm_timer *timer, u32 reg,
u32 value)
{
if (timer->posted)
while (readl(timer->io_base + (OMAP_TIMER_WRITE_PEND_REG & 0xff))
& (reg >> WPSHIFT))
cpu_relax();
writel(value, timer->io_base + (reg & 0xff));
}
static void omap_dm_timer_wait_for_reset(struct omap_dm_timer *timer)
{
int c;
c = 0;
while (!(omap_dm_timer_read_reg(timer, OMAP_TIMER_SYS_STAT_REG) & 1)) {
c++;
if (c > 100000) {
printk(KERN_ERR "Timer failed to reset\n");
return;
}
}
}
static void omap_dm_timer_reset(struct omap_dm_timer *timer)
{
u32 l;
if (!cpu_class_is_omap2() || timer != &dm_timers[0]) {
omap_dm_timer_write_reg(timer, OMAP_TIMER_IF_CTRL_REG, 0x06);
omap_dm_timer_wait_for_reset(timer);
}
omap_dm_timer_set_source(timer, OMAP_TIMER_SRC_32_KHZ);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_OCP_CFG_REG);
l |= 0x02 << 3;
l |= 0x2 << 8;
if (cpu_is_omap24xx() || cpu_is_omap34xx())
l |= 0x1 << 0;
if (cpu_class_is_omap2())
l |= 1 << 2;
omap_dm_timer_write_reg(timer, OMAP_TIMER_OCP_CFG_REG, l);
omap_dm_timer_write_reg(timer, OMAP_TIMER_IF_CTRL_REG,
OMAP_TIMER_CTRL_POSTED);
timer->posted = 1;
}
static void omap_dm_timer_prepare(struct omap_dm_timer *timer)
{
omap_dm_timer_enable(timer);
omap_dm_timer_reset(timer);
}
struct omap_dm_timer *omap_dm_timer_request(void)
{
struct omap_dm_timer *timer = NULL;
unsigned long flags;
int i;
spin_lock_irqsave(&dm_timer_lock, flags);
for (i = 0; i < dm_timer_count; i++) {
if (dm_timers[i].reserved)
continue;
timer = &dm_timers[i];
timer->reserved = 1;
break;
}
spin_unlock_irqrestore(&dm_timer_lock, flags);
if (timer != NULL)
omap_dm_timer_prepare(timer);
return timer;
}
struct omap_dm_timer *omap_dm_timer_request_specific(int id)
{
struct omap_dm_timer *timer;
unsigned long flags;
spin_lock_irqsave(&dm_timer_lock, flags);
if (id <= 0 || id > dm_timer_count || dm_timers[id-1].reserved) {
spin_unlock_irqrestore(&dm_timer_lock, flags);
printk("BUG: warning at %s:%d/%s(): unable to get timer %d\n",
__FILE__, __LINE__, __func__, id);
dump_stack();
return NULL;
}
timer = &dm_timers[id-1];
timer->reserved = 1;
spin_unlock_irqrestore(&dm_timer_lock, flags);
omap_dm_timer_prepare(timer);
return timer;
}
void omap_dm_timer_free(struct omap_dm_timer *timer)
{
omap_dm_timer_enable(timer);
omap_dm_timer_reset(timer);
omap_dm_timer_disable(timer);
WARN_ON(!timer->reserved);
timer->reserved = 0;
}
void omap_dm_timer_enable(struct omap_dm_timer *timer)
{
if (timer->enabled)
return;
#ifdef CONFIG_ARCH_OMAP2PLUS
if (cpu_class_is_omap2()) {
clk_enable(timer->fclk);
clk_enable(timer->iclk);
}
#endif
timer->enabled = 1;
}
void omap_dm_timer_disable(struct omap_dm_timer *timer)
{
if (!timer->enabled)
return;
#ifdef CONFIG_ARCH_OMAP2PLUS
if (cpu_class_is_omap2()) {
clk_disable(timer->iclk);
clk_disable(timer->fclk);
}
#endif
timer->enabled = 0;
}
int omap_dm_timer_get_irq(struct omap_dm_timer *timer)
{
return timer->irq;
}
__u32 omap_dm_timer_modify_idlect_mask(__u32 inputmask)
{
int i;
if (!(inputmask & (1 << 1)))
return inputmask;
for (i = 0; i < dm_timer_count; i++) {
u32 l;
l = omap_dm_timer_read_reg(&dm_timers[i], OMAP_TIMER_CTRL_REG);
if (l & OMAP_TIMER_CTRL_ST) {
if (((omap_readl(MOD_CONF_CTRL_1) >> (i * 2)) & 0x03) == 0)
inputmask &= ~(1 << 1);
else
inputmask &= ~(1 << 2);
}
}
return inputmask;
}
struct clk *omap_dm_timer_get_fclk(struct omap_dm_timer *timer)
{
return timer->fclk;
}
__u32 omap_dm_timer_modify_idlect_mask(__u32 inputmask)
{
BUG();
return 0;
}
void omap_dm_timer_trigger(struct omap_dm_timer *timer)
{
omap_dm_timer_write_reg(timer, OMAP_TIMER_TRIGGER_REG, 0);
}
void omap_dm_timer_start(struct omap_dm_timer *timer)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (!(l & OMAP_TIMER_CTRL_ST)) {
l |= OMAP_TIMER_CTRL_ST;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
}
}
void omap_dm_timer_stop(struct omap_dm_timer *timer)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (l & OMAP_TIMER_CTRL_ST) {
l &= ~0x1;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
#ifdef CONFIG_ARCH_OMAP2PLUS
omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
udelay(3500000 / clk_get_rate(timer->fclk) + 1);
#endif
}
omap_dm_timer_write_reg(timer, OMAP_TIMER_STAT_REG,
OMAP_TIMER_INT_OVERFLOW);
}
int omap_dm_timer_set_source(struct omap_dm_timer *timer, int source)
{
int n = (timer - dm_timers) << 1;
u32 l;
l = omap_readl(MOD_CONF_CTRL_1) & ~(0x03 << n);
l |= source << n;
omap_writel(l, MOD_CONF_CTRL_1);
return 0;
}
int omap_dm_timer_set_source(struct omap_dm_timer *timer, int source)
{
int ret = -EINVAL;
if (source < 0 || source >= 3)
return -EINVAL;
clk_disable(timer->fclk);
ret = clk_set_parent(timer->fclk, dm_source_clocks[source]);
clk_enable(timer->fclk);
__delay(300000);
return ret;
}
void omap_dm_timer_set_load(struct omap_dm_timer *timer, int autoreload,
unsigned int load)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (autoreload)
l |= OMAP_TIMER_CTRL_AR;
else
l &= ~OMAP_TIMER_CTRL_AR;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
omap_dm_timer_write_reg(timer, OMAP_TIMER_LOAD_REG, load);
omap_dm_timer_write_reg(timer, OMAP_TIMER_TRIGGER_REG, 0);
}
void omap_dm_timer_set_load_start(struct omap_dm_timer *timer, int autoreload,
unsigned int load)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (autoreload) {
l |= OMAP_TIMER_CTRL_AR;
omap_dm_timer_write_reg(timer, OMAP_TIMER_LOAD_REG, load);
} else {
l &= ~OMAP_TIMER_CTRL_AR;
}
l |= OMAP_TIMER_CTRL_ST;
omap_dm_timer_write_reg(timer, OMAP_TIMER_COUNTER_REG, load);
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
}
void omap_dm_timer_set_match(struct omap_dm_timer *timer, int enable,
unsigned int match)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (enable)
l |= OMAP_TIMER_CTRL_CE;
else
l &= ~OMAP_TIMER_CTRL_CE;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
omap_dm_timer_write_reg(timer, OMAP_TIMER_MATCH_REG, match);
}
void omap_dm_timer_set_pwm(struct omap_dm_timer *timer, int def_on,
int toggle, int trigger)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
l &= ~(OMAP_TIMER_CTRL_GPOCFG | OMAP_TIMER_CTRL_SCPWM |
OMAP_TIMER_CTRL_PT | (0x03 << 10));
if (def_on)
l |= OMAP_TIMER_CTRL_SCPWM;
if (toggle)
l |= OMAP_TIMER_CTRL_PT;
l |= trigger << 10;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
}
void omap_dm_timer_set_prescaler(struct omap_dm_timer *timer, int prescaler)
{
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
l &= ~(OMAP_TIMER_CTRL_PRE | (0x07 << 2));
if (prescaler >= 0x00 && prescaler <= 0x07) {
l |= OMAP_TIMER_CTRL_PRE;
l |= prescaler << 2;
}
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
}
void omap_dm_timer_set_int_enable(struct omap_dm_timer *timer,
unsigned int value)
{
omap_dm_timer_write_reg(timer, OMAP_TIMER_INT_EN_REG, value);
omap_dm_timer_write_reg(timer, OMAP_TIMER_WAKEUP_EN_REG, value);
}
unsigned int omap_dm_timer_read_status(struct omap_dm_timer *timer)
{
unsigned int l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_STAT_REG);
return l;
}
void omap_dm_timer_write_status(struct omap_dm_timer *timer, unsigned int value)
{
omap_dm_timer_write_reg(timer, OMAP_TIMER_STAT_REG, value);
}
unsigned int omap_dm_timer_read_counter(struct omap_dm_timer *timer)
{
unsigned int l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_COUNTER_REG);
return l;
}
void omap_dm_timer_write_counter(struct omap_dm_timer *timer, unsigned int value)
{
omap_dm_timer_write_reg(timer, OMAP_TIMER_COUNTER_REG, value);
}
int omap_dm_timers_active(void)
{
int i;
for (i = 0; i < dm_timer_count; i++) {
struct omap_dm_timer *timer;
timer = &dm_timers[i];
if (!timer->enabled)
continue;
if (omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG) &
OMAP_TIMER_CTRL_ST) {
return 1;
}
}
return 0;
}
int __init omap_dm_timer_init(void)
{
struct omap_dm_timer *timer;
int i, map_size = SZ_8K;
if (!(cpu_is_omap16xx() || cpu_class_is_omap2()))
return -ENODEV;
spin_lock_init(&dm_timer_lock);
if (cpu_class_is_omap1()) {
dm_timers = omap1_dm_timers;
dm_timer_count = omap1_dm_timer_count;
map_size = SZ_2K;
} else if (cpu_is_omap24xx()) {
dm_timers = omap2_dm_timers;
dm_timer_count = omap2_dm_timer_count;
dm_source_names = omap2_dm_source_names;
dm_source_clocks = omap2_dm_source_clocks;
} else if (cpu_is_omap34xx()) {
dm_timers = omap3_dm_timers;
dm_timer_count = omap3_dm_timer_count;
dm_source_names = omap3_dm_source_names;
dm_source_clocks = omap3_dm_source_clocks;
} else if (cpu_is_omap44xx()) {
dm_timers = omap4_dm_timers;
dm_timer_count = omap4_dm_timer_count;
dm_source_names = omap4_dm_source_names;
dm_source_clocks = omap4_dm_source_clocks;
}
if (cpu_class_is_omap2())
for (i = 0; dm_source_names[i] != NULL; i++)
dm_source_clocks[i] = clk_get(NULL, dm_source_names[i]);
if (cpu_is_omap243x())
dm_timers[0].phys_base = 0x49018000;
for (i = 0; i < dm_timer_count; i++) {
timer = &dm_timers[i];
timer->io_base = ioremap(timer->phys_base, map_size);
BUG_ON(!timer->io_base);
#ifdef CONFIG_ARCH_OMAP2PLUS
if (cpu_class_is_omap2()) {
char clk_name[16];
sprintf(clk_name, "gpt%d_ick", i + 1);
timer->iclk = clk_get(NULL, clk_name);
sprintf(clk_name, "gpt%d_fck", i + 1);
timer->fclk = clk_get(NULL, clk_name);
}
#endif
}
return 0;
}
