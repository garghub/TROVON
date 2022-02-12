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
omap_dm_timer_write_reg(timer, OMAP_TIMER_OCP_CFG_OFFSET,
timer->context.tiocp_cfg);
if (timer->revision > 1)
__raw_writel(timer->context.tistat, timer->sys_stat);
__raw_writel(timer->context.tisr, timer->irq_stat);
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
__raw_writel(timer->context.tier, timer->irq_ena);
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG,
timer->context.tclr);
}
static void omap_dm_timer_wait_for_reset(struct omap_dm_timer *timer)
{
int c;
if (!timer->sys_stat)
return;
c = 0;
while (!(__raw_readl(timer->sys_stat) & 1)) {
c++;
if (c > 100000) {
printk(KERN_ERR "Timer failed to reset\n");
return;
}
}
}
static void omap_dm_timer_reset(struct omap_dm_timer *timer)
{
omap_dm_timer_enable(timer);
if (timer->pdev->id != 1) {
omap_dm_timer_write_reg(timer, OMAP_TIMER_IF_CTRL_REG, 0x06);
omap_dm_timer_wait_for_reset(timer);
}
__omap_dm_timer_reset(timer, 0, 0);
omap_dm_timer_disable(timer);
timer->posted = 1;
}
int omap_dm_timer_prepare(struct omap_dm_timer *timer)
{
struct dmtimer_platform_data *pdata = timer->pdev->dev.platform_data;
int ret;
timer->fclk = clk_get(&timer->pdev->dev, "fck");
if (WARN_ON_ONCE(IS_ERR_OR_NULL(timer->fclk))) {
timer->fclk = NULL;
dev_err(&timer->pdev->dev, ": No fclk handle.\n");
return -EINVAL;
}
if (pdata->needs_manual_reset)
omap_dm_timer_reset(timer);
ret = omap_dm_timer_set_source(timer, OMAP_TIMER_SRC_32_KHZ);
timer->posted = 1;
return ret;
}
struct omap_dm_timer *omap_dm_timer_request(void)
{
struct omap_dm_timer *timer = NULL, *t;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&dm_timer_lock, flags);
list_for_each_entry(t, &omap_timer_list, node) {
if (t->reserved)
continue;
timer = t;
timer->reserved = 1;
break;
}
if (timer) {
ret = omap_dm_timer_prepare(timer);
if (ret) {
timer->reserved = 0;
timer = NULL;
}
}
spin_unlock_irqrestore(&dm_timer_lock, flags);
if (!timer)
pr_debug("%s: timer request failed!\n", __func__);
return timer;
}
struct omap_dm_timer *omap_dm_timer_request_specific(int id)
{
struct omap_dm_timer *timer = NULL, *t;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&dm_timer_lock, flags);
list_for_each_entry(t, &omap_timer_list, node) {
if (t->pdev->id == id && !t->reserved) {
timer = t;
timer->reserved = 1;
break;
}
}
if (timer) {
ret = omap_dm_timer_prepare(timer);
if (ret) {
timer->reserved = 0;
timer = NULL;
}
}
spin_unlock_irqrestore(&dm_timer_lock, flags);
if (!timer)
pr_debug("%s: timer%d request failed!\n", __func__, id);
return timer;
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
pm_runtime_get_sync(&timer->pdev->dev);
}
void omap_dm_timer_disable(struct omap_dm_timer *timer)
{
pm_runtime_put(&timer->pdev->dev);
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
if (timer)
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
if (timer->loses_context) {
u32 ctx_loss_cnt_after =
timer->get_context_loss_count(&timer->pdev->dev);
if (ctx_loss_cnt_after != timer->ctx_loss_count)
omap_timer_restore_context(timer);
}
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
struct dmtimer_platform_data *pdata = timer->pdev->dev.platform_data;
if (unlikely(!timer))
return -EINVAL;
if (!pdata->needs_manual_reset)
rate = clk_get_rate(timer->fclk);
__omap_dm_timer_stop(timer, timer->posted, rate);
return 0;
}
int omap_dm_timer_set_source(struct omap_dm_timer *timer, int source)
{
int ret;
struct dmtimer_platform_data *pdata;
if (unlikely(!timer))
return -EINVAL;
pdata = timer->pdev->dev.platform_data;
if (source < 0 || source >= 3)
return -EINVAL;
ret = pdata->set_timer_src(timer->pdev, source);
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
if (timer->loses_context) {
u32 ctx_loss_cnt_after =
timer->get_context_loss_count(&timer->pdev->dev);
if (ctx_loss_cnt_after != timer->ctx_loss_count)
omap_timer_restore_context(timer);
}
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
omap_dm_timer_write_reg(timer, OMAP_TIMER_CTRL_REG, l);
omap_dm_timer_write_reg(timer, OMAP_TIMER_MATCH_REG, match);
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
unsigned int omap_dm_timer_read_status(struct omap_dm_timer *timer)
{
unsigned int l;
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev))) {
pr_err("%s: timer not available or enabled.\n", __func__);
return 0;
}
l = __raw_readl(timer->irq_stat);
return l;
}
int omap_dm_timer_write_status(struct omap_dm_timer *timer, unsigned int value)
{
if (unlikely(!timer || pm_runtime_suspended(&timer->pdev->dev)))
return -EINVAL;
__omap_dm_timer_write_status(timer, value);
timer->context.tisr = value;
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
static int __devinit omap_dm_timer_probe(struct platform_device *pdev)
{
int ret;
unsigned long flags;
struct omap_dm_timer *timer;
struct resource *mem, *irq, *ioarea;
struct dmtimer_platform_data *pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "%s: no platform data.\n", __func__);
return -ENODEV;
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (unlikely(!irq)) {
dev_err(&pdev->dev, "%s: no IRQ resource.\n", __func__);
return -ENODEV;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!mem)) {
dev_err(&pdev->dev, "%s: no memory resource.\n", __func__);
return -ENODEV;
}
ioarea = request_mem_region(mem->start, resource_size(mem),
pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "%s: region already claimed.\n", __func__);
return -EBUSY;
}
timer = kzalloc(sizeof(struct omap_dm_timer), GFP_KERNEL);
if (!timer) {
dev_err(&pdev->dev, "%s: no memory for omap_dm_timer.\n",
__func__);
ret = -ENOMEM;
goto err_free_ioregion;
}
timer->io_base = ioremap(mem->start, resource_size(mem));
if (!timer->io_base) {
dev_err(&pdev->dev, "%s: ioremap failed.\n", __func__);
ret = -ENOMEM;
goto err_free_mem;
}
timer->id = pdev->id;
timer->irq = irq->start;
timer->reserved = pdata->reserved;
timer->pdev = pdev;
timer->loses_context = pdata->loses_context;
timer->get_context_loss_count = pdata->get_context_loss_count;
if (!pdata->needs_manual_reset) {
pm_runtime_enable(&pdev->dev);
pm_runtime_irq_safe(&pdev->dev);
}
if (!timer->reserved) {
pm_runtime_get_sync(&pdev->dev);
__omap_dm_timer_init_regs(timer);
pm_runtime_put(&pdev->dev);
}
spin_lock_irqsave(&dm_timer_lock, flags);
list_add_tail(&timer->node, &omap_timer_list);
spin_unlock_irqrestore(&dm_timer_lock, flags);
dev_dbg(&pdev->dev, "Device Probed.\n");
return 0;
err_free_mem:
kfree(timer);
err_free_ioregion:
release_mem_region(mem->start, resource_size(mem));
return ret;
}
static int __devexit omap_dm_timer_remove(struct platform_device *pdev)
{
struct omap_dm_timer *timer;
unsigned long flags;
int ret = -EINVAL;
spin_lock_irqsave(&dm_timer_lock, flags);
list_for_each_entry(timer, &omap_timer_list, node)
if (timer->pdev->id == pdev->id) {
list_del(&timer->node);
kfree(timer);
ret = 0;
break;
}
spin_unlock_irqrestore(&dm_timer_lock, flags);
return ret;
}
static int __init omap_dm_timer_driver_init(void)
{
return platform_driver_register(&omap_dm_timer_driver);
}
static void __exit omap_dm_timer_driver_exit(void)
{
platform_driver_unregister(&omap_dm_timer_driver);
}
