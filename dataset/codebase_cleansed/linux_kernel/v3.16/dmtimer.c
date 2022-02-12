static inline u32 omap_dm_timer_read_reg(struct omap_dm_timer *timer, u32 reg)
{
WARN_ON((reg & 0xff) < _OMAP_TIMER_WAKEUP_EN_OFFSET);
return __omap_dm_timer_read(timer, reg, timer->posted);
}
static void omap_dm_timer_write_reg(struct omap_dm_timer *timer, u32 reg,
u32 value)
{
WARN_ON((reg & 0xff) < _OMAP_TIMER_WAKEUP_EN_OFFSET);
__omap_dm_timer_write(timer, reg, value, timer->posted);
}
static void omap_timer_restore_context(struct omap_dm_timer *timer)
{
omap_dm_timer_write_reg(timer, OMAP_TIMER_WAKEUP_EN_REG,
timer->context.twer);
omap_dm_timer_write_reg(timer, OMAP_TIMER_COUNTER_REG,
timer->context.tcrr);
omap_dm_timer_write_reg(timer, OMAP_TIMER_LOAD_REG,
timer->context.tldr);
omap_dm_timer_write_reg(timer, OMAP_TIMER_MATCH_REG,
timer->context.tmar);
omap_dm_timer_write_reg(timer, OMAP_TIMER_IF_CTRL_REG,
timer->context.tsicr);
writel_relaxed(timer->context.tier, timer->irq_ena);
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG,
timer->context.tclr);
}
static int omap_dm_timer_reset(struct omap_dm_timer *timer)
{
u32 l, timeout = 100000;
if (timer->revision != 1)
return -EINVAL;
omap_dm_timer_write_reg(timer, OMAP_TIMER_IF_CTRL_REG, 0x06);
do {
l = __omap_dm_timer_read(timer,
OMAP_TIMER_V1_SYS_STAT_OFFSET, 0);
} while (!l && timeout--);
if (!timeout) {
dev_err(&timer->pdev->dev, "Timer failed to reset\n");
return -ETIMEDOUT;
}
l = __omap_dm_timer_read(timer, OMAP_TIMER_OCP_CFG_OFFSET, 0);
l |= 0x2 << 0x3;
__omap_dm_timer_write(timer, OMAP_TIMER_OCP_CFG_OFFSET, l, 0);
timer->posted = 0;
return 0;
}
static int omap_dm_timer_prepare(struct omap_dm_timer *timer)
{
int rc;
if (!(timer->capability & OMAP_TIMER_NEEDS_RESET)) {
timer->fclk = clk_get(&timer->pdev->dev, "fck");
if (WARN_ON_ONCE(IS_ERR(timer->fclk))) {
dev_err(&timer->pdev->dev, ": No fclk handle.\n");
return -EINVAL;
}
}
omap_dm_timer_enable(timer);
if (timer->capability & OMAP_TIMER_NEEDS_RESET) {
rc = omap_dm_timer_reset(timer);
if (rc) {
omap_dm_timer_disable(timer);
return rc;
}
}
__omap_dm_timer_enable_posted(timer);
omap_dm_timer_disable(timer);
return omap_dm_timer_set_source(timer, OMAP_TIMER_SRC_32_KHZ);
}
static inline u32 omap_dm_timer_reserved_systimer(int id)
{
return (omap_reserved_systimers & (1 << (id - 1))) ? 1 : 0;
}
int omap_dm_timer_reserve_systimer(int id)
{
if (omap_dm_timer_reserved_systimer(id))
return -ENODEV;
omap_reserved_systimers |= (1 << (id - 1));
return 0;
}
static struct omap_dm_timer *_omap_dm_timer_request(int req_type, void *data)
{
struct omap_dm_timer *timer = NULL, *t;
struct device_node *np = NULL;
unsigned long flags;
u32 cap = 0;
int id = 0;
switch (req_type) {
case REQUEST_BY_ID:
id = *(int *)data;
break;
case REQUEST_BY_CAP:
cap = *(u32 *)data;
break;
case REQUEST_BY_NODE:
np = (struct device_node *)data;
break;
default:
break;
}
spin_lock_irqsave(&dm_timer_lock, flags);
list_for_each_entry(t, &omap_timer_list, node) {
if (t->reserved)
continue;
switch (req_type) {
case REQUEST_BY_ID:
if (id == t->pdev->id) {
timer = t;
timer->reserved = 1;
goto found;
}
break;
case REQUEST_BY_CAP:
if (cap == (t->capability & cap)) {
if (timer)
timer->reserved = 0;
timer = t;
timer->reserved = 1;
if (t->capability == cap)
goto found;
}
break;
case REQUEST_BY_NODE:
if (np == t->pdev->dev.of_node) {
timer = t;
timer->reserved = 1;
goto found;
}
break;
default:
timer = t;
timer->reserved = 1;
goto found;
}
}
found:
spin_unlock_irqrestore(&dm_timer_lock, flags);
if (timer && omap_dm_timer_prepare(timer)) {
timer->reserved = 0;
timer = NULL;
}
if (!timer)
pr_debug("%s: timer request failed!\n", __func__);
return timer;
}
struct omap_dm_timer *omap_dm_timer_request(void)
{
return _omap_dm_timer_request(REQUEST_ANY, NULL);
}
struct omap_dm_timer *omap_dm_timer_request_specific(int id)
{
if (of_have_populated_dt()) {
pr_warn("%s: Please use omap_dm_timer_request_by_cap/node()\n",
__func__);
return NULL;
}
return _omap_dm_timer_request(REQUEST_BY_ID, &id);
}
struct omap_dm_timer *omap_dm_timer_request_by_cap(u32 cap)
{
return _omap_dm_timer_request(REQUEST_BY_CAP, &cap);
}
struct omap_dm_timer *omap_dm_timer_request_by_node(struct device_node *np)
{
if (!np)
return NULL;
return _omap_dm_timer_request(REQUEST_BY_NODE, np);
}
int omap_dm_timer_free(struct omap_dm_timer *timer)
{
if (unlikely(!timer))
return -EINVAL;
clk_put(timer->fclk);
WARN_ON(!timer->reserved);
timer->reserved = 0;
return 0;
}
void omap_dm_timer_enable(struct omap_dm_timer *timer)
{
int c;
pm_runtime_get_sync(&timer->pdev->dev);
if (!(timer->capability & OMAP_TIMER_ALWON)) {
if (timer->get_context_loss_count) {
c = timer->get_context_loss_count(&timer->pdev->dev);
if (c != timer->ctx_loss_count) {
omap_timer_restore_context(timer);
timer->ctx_loss_count = c;
}
} else {
omap_timer_restore_context(timer);
}
}
}
void omap_dm_timer_disable(struct omap_dm_timer *timer)
{
pm_runtime_put_sync(&timer->pdev->dev);
}
int omap_dm_timer_get_irq(struct omap_dm_timer *timer)
{
if (timer)
return timer->irq;
return -EINVAL;
}
__u32 omap_dm_timer_modify_idlect_mask(__u32 inputmask)
{
int i = 0;
struct omap_dm_timer *timer = NULL;
unsigned long flags;
if (!(inputmask & (1 << 1)))
return inputmask;
spin_lock_irqsave(&dm_timer_lock, flags);
list_for_each_entry(timer, &omap_timer_list, node) {
u32 l;
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (l & OMAP_TIMER_CTRL_ST) {
if (((omap_readl(MOD_CONF_CTRL_1) >> (i * 2)) & 0x03) == 0)
inputmask &= ~(1 << 1);
else
inputmask &= ~(1 << 2);
}
i++;
}
spin_unlock_irqrestore(&dm_timer_lock, flags);
return inputmask;
}
struct clk *omap_dm_timer_get_fclk(struct omap_dm_timer *timer)
{
if (timer && !IS_ERR(timer->fclk))
return timer->fclk;
return NULL;
}
__u32 omap_dm_timer_modify_idlect_mask(__u32 inputmask)
{
BUG();
return 0;
}
int omap_dm_timer_trigger(struct omap_dm_timer *timer)
{
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev))) {
pr_err("%s: timer not available or enabled.\n", __func__);
return -EINVAL;
}
omap_dm_timer_write_reg(timer, OMAP_TIMER_TRIGGER_REG, 0);
return 0;
}
int omap_dm_timer_start(struct omap_dm_timer *timer)
{
u32 l;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (!(l & OMAP_TIMER_CTRL_ST)) {
l |= OMAP_TIMER_CTRL_ST;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
}
timer->context.tclr = l;
return 0;
}
int omap_dm_timer_stop(struct omap_dm_timer *timer)
{
unsigned long rate = 0;
if (unlikely(!timer))
return -EINVAL;
if (!(timer->capability & OMAP_TIMER_NEEDS_RESET))
rate = clk_get_rate(timer->fclk);
__omap_dm_timer_stop(timer, timer->posted, rate);
timer->context.tclr =
omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
omap_dm_timer_disable(timer);
return 0;
}
int omap_dm_timer_set_source(struct omap_dm_timer *timer, int source)
{
int ret;
char *parent_name = NULL;
struct clk *parent;
struct dmtimer_platform_data *pdata;
if (unlikely(!timer))
return -EINVAL;
pdata = timer->pdev->dev.platform_data;
if (source < 0 || source >= 3)
return -EINVAL;
if (pdata && pdata->set_timer_src)
return pdata->set_timer_src(timer->pdev, source);
if (IS_ERR(timer->fclk))
return -EINVAL;
switch (source) {
case OMAP_TIMER_SRC_SYS_CLK:
parent_name = "timer_sys_ck";
break;
case OMAP_TIMER_SRC_32_KHZ:
parent_name = "timer_32k_ck";
break;
case OMAP_TIMER_SRC_EXT_CLK:
parent_name = "timer_ext_ck";
break;
}
parent = clk_get(&timer->pdev->dev, parent_name);
if (IS_ERR(parent)) {
pr_err("%s: %s not found\n", __func__, parent_name);
return -EINVAL;
}
ret = clk_set_parent(timer->fclk, parent);
if (ret < 0)
pr_err("%s: failed to set %s as parent\n", __func__,
parent_name);
clk_put(parent);
return ret;
}
int omap_dm_timer_set_load(struct omap_dm_timer *timer, int autoreload,
unsigned int load)
{
u32 l;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (autoreload)
l |= OMAP_TIMER_CTRL_AR;
else
l &= ~OMAP_TIMER_CTRL_AR;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
omap_dm_timer_write_reg(timer, OMAP_TIMER_LOAD_REG, load);
omap_dm_timer_write_reg(timer, OMAP_TIMER_TRIGGER_REG, 0);
timer->context.tclr = l;
timer->context.tldr = load;
omap_dm_timer_disable(timer);
return 0;
}
int omap_dm_timer_set_load_start(struct omap_dm_timer *timer, int autoreload,
unsigned int load)
{
u32 l;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (autoreload) {
l |= OMAP_TIMER_CTRL_AR;
omap_dm_timer_write_reg(timer, OMAP_TIMER_LOAD_REG, load);
} else {
l &= ~OMAP_TIMER_CTRL_AR;
}
l |= OMAP_TIMER_CTRL_ST;
__omap_dm_timer_load_start(timer, l, load, timer->posted);
timer->context.tclr = l;
timer->context.tldr = load;
timer->context.tcrr = load;
return 0;
}
int omap_dm_timer_set_match(struct omap_dm_timer *timer, int enable,
unsigned int match)
{
u32 l;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
if (enable)
l |= OMAP_TIMER_CTRL_CE;
else
l &= ~OMAP_TIMER_CTRL_CE;
omap_dm_timer_write_reg(timer, OMAP_TIMER_MATCH_REG, match);
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
timer->context.tclr = l;
timer->context.tmar = match;
omap_dm_timer_disable(timer);
return 0;
}
int omap_dm_timer_set_pwm(struct omap_dm_timer *timer, int def_on,
int toggle, int trigger)
{
u32 l;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
l &= ~(OMAP_TIMER_CTRL_GPOCFG | OMAP_TIMER_CTRL_SCPWM |
OMAP_TIMER_CTRL_PT | (0x03 << 10));
if (def_on)
l |= OMAP_TIMER_CTRL_SCPWM;
if (toggle)
l |= OMAP_TIMER_CTRL_PT;
l |= trigger << 10;
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
timer->context.tclr = l;
omap_dm_timer_disable(timer);
return 0;
}
int omap_dm_timer_set_prescaler(struct omap_dm_timer *timer, int prescaler)
{
u32 l;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG);
l &= ~(OMAP_TIMER_CTRL_PRE | (0x07 << 2));
if (prescaler >= 0x00 && prescaler <= 0x07) {
l |= OMAP_TIMER_CTRL_PRE;
l |= prescaler << 2;
}
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
timer->context.tclr = l;
omap_dm_timer_disable(timer);
return 0;
}
int omap_dm_timer_set_int_enable(struct omap_dm_timer *timer,
unsigned int value)
{
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
__omap_dm_timer_int_enable(timer, value);
timer->context.tier = value;
timer->context.twer = value;
omap_dm_timer_disable(timer);
return 0;
}
int omap_dm_timer_set_int_disable(struct omap_dm_timer *timer, u32 mask)
{
u32 l = mask;
if (unlikely(!timer))
return -EINVAL;
omap_dm_timer_enable(timer);
if (timer->revision == 1)
l = readl_relaxed(timer->irq_ena) & ~mask;
writel_relaxed(l, timer->irq_dis);
l = omap_dm_timer_read_reg(timer, OMAP_TIMER_WAKEUP_EN_REG) & ~mask;
omap_dm_timer_write_reg(timer, OMAP_TIMER_WAKEUP_EN_REG, l);
timer->context.tier &= ~mask;
timer->context.twer &= ~mask;
omap_dm_timer_disable(timer);
return 0;
}
unsigned int omap_dm_timer_read_status(struct omap_dm_timer *timer)
{
unsigned int l;
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev))) {
pr_err("%s: timer not available or enabled.\n", __func__);
return 0;
}
l = readl_relaxed(timer->irq_stat);
return l;
}
int omap_dm_timer_write_status(struct omap_dm_timer *timer, unsigned int value)
{
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev)))
return -EINVAL;
__omap_dm_timer_write_status(timer, value);
return 0;
}
unsigned int omap_dm_timer_read_counter(struct omap_dm_timer *timer)
{
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev))) {
pr_err("%s: timer not iavailable or enabled.\n", __func__);
return 0;
}
return __omap_dm_timer_read_counter(timer, timer->posted);
}
int omap_dm_timer_write_counter(struct omap_dm_timer *timer, unsigned int value)
{
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev))) {
pr_err("%s: timer not available or enabled.\n", __func__);
return -EINVAL;
}
omap_dm_timer_write_reg(timer, OMAP_TIMER_COUNTER_REG, value);
timer->context.tcrr = value;
return 0;
}
int omap_dm_timers_active(void)
{
struct omap_dm_timer *timer;
list_for_each_entry(timer, &omap_timer_list, node) {
if (!timer->reserved)
continue;
if (omap_dm_timer_read_reg(timer, OMAP_TIMER_CTRL_REG) &
OMAP_TIMER_CTRL_ST) {
return 1;
}
}
return 0;
}
static int omap_dm_timer_probe(struct platform_device *pdev)
{
unsigned long flags;
struct omap_dm_timer *timer;
struct resource *mem, *irq;
struct device *dev = &pdev->dev;
const struct of_device_id *match;
const struct dmtimer_platform_data *pdata;
match = of_match_device(of_match_ptr(omap_timer_match), dev);
pdata = match ? match->data : dev->platform_data;
if (!pdata && !dev->of_node) {
dev_err(dev, "%s: no platform data.\n", __func__);
return -ENODEV;
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (unlikely(!irq)) {
dev_err(dev, "%s: no IRQ resource.\n", __func__);
return -ENODEV;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!mem)) {
dev_err(dev, "%s: no memory resource.\n", __func__);
return -ENODEV;
}
timer = devm_kzalloc(dev, sizeof(struct omap_dm_timer), GFP_KERNEL);
if (!timer) {
dev_err(dev, "%s: memory alloc failed!\n", __func__);
return -ENOMEM;
}
timer->fclk = ERR_PTR(-ENODEV);
timer->io_base = devm_ioremap_resource(dev, mem);
if (IS_ERR(timer->io_base))
return PTR_ERR(timer->io_base);
if (dev->of_node) {
if (of_find_property(dev->of_node, "ti,timer-alwon", NULL))
timer->capability |= OMAP_TIMER_ALWON;
if (of_find_property(dev->of_node, "ti,timer-dsp", NULL))
timer->capability |= OMAP_TIMER_HAS_DSP_IRQ;
if (of_find_property(dev->of_node, "ti,timer-pwm", NULL))
timer->capability |= OMAP_TIMER_HAS_PWM;
if (of_find_property(dev->of_node, "ti,timer-secure", NULL))
timer->capability |= OMAP_TIMER_SECURE;
} else {
timer->id = pdev->id;
timer->capability = pdata->timer_capability;
timer->reserved = omap_dm_timer_reserved_systimer(timer->id);
timer->get_context_loss_count = pdata->get_context_loss_count;
}
if (pdata)
timer->errata = pdata->timer_errata;
timer->irq = irq->start;
timer->pdev = pdev;
if (!(timer->capability & OMAP_TIMER_NEEDS_RESET)) {
pm_runtime_enable(dev);
pm_runtime_irq_safe(dev);
}
if (!timer->reserved) {
pm_runtime_get_sync(dev);
__omap_dm_timer_init_regs(timer);
pm_runtime_put(dev);
}
spin_lock_irqsave(&dm_timer_lock, flags);
list_add_tail(&timer->node, &omap_timer_list);
spin_unlock_irqrestore(&dm_timer_lock, flags);
dev_dbg(dev, "Device Probed.\n");
return 0;
}
static int omap_dm_timer_remove(struct platform_device *pdev)
{
struct omap_dm_timer *timer;
unsigned long flags;
int ret = -EINVAL;
spin_lock_irqsave(&dm_timer_lock, flags);
list_for_each_entry(timer, &omap_timer_list, node)
if (!strcmp(dev_name(&timer->pdev->dev),
dev_name(&pdev->dev))) {
list_del(&timer->node);
ret = 0;
break;
}
spin_unlock_irqrestore(&dm_timer_lock, flags);
return ret;
}
