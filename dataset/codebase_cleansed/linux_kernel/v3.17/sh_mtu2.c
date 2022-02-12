static inline unsigned long sh_mtu2_read(struct sh_mtu2_channel *ch, int reg_nr)
{
unsigned long offs;
if (reg_nr == TSTR)
return ioread8(ch->mtu->mapbase + 0x280);
offs = mtu2_reg_offs[reg_nr];
if ((reg_nr == TCNT) || (reg_nr == TGR))
return ioread16(ch->base + offs);
else
return ioread8(ch->base + offs);
}
static inline void sh_mtu2_write(struct sh_mtu2_channel *ch, int reg_nr,
unsigned long value)
{
unsigned long offs;
if (reg_nr == TSTR)
return iowrite8(value, ch->mtu->mapbase + 0x280);
offs = mtu2_reg_offs[reg_nr];
if ((reg_nr == TCNT) || (reg_nr == TGR))
iowrite16(value, ch->base + offs);
else
iowrite8(value, ch->base + offs);
}
static void sh_mtu2_start_stop_ch(struct sh_mtu2_channel *ch, int start)
{
unsigned long flags, value;
raw_spin_lock_irqsave(&ch->mtu->lock, flags);
value = sh_mtu2_read(ch, TSTR);
if (start)
value |= 1 << ch->index;
else
value &= ~(1 << ch->index);
sh_mtu2_write(ch, TSTR, value);
raw_spin_unlock_irqrestore(&ch->mtu->lock, flags);
}
static int sh_mtu2_enable(struct sh_mtu2_channel *ch)
{
unsigned long periodic;
unsigned long rate;
int ret;
pm_runtime_get_sync(&ch->mtu->pdev->dev);
dev_pm_syscore_device(&ch->mtu->pdev->dev, true);
ret = clk_enable(ch->mtu->clk);
if (ret) {
dev_err(&ch->mtu->pdev->dev, "ch%u: cannot enable clock\n",
ch->index);
return ret;
}
sh_mtu2_start_stop_ch(ch, 0);
rate = clk_get_rate(ch->mtu->clk) / 64;
periodic = (rate + HZ/2) / HZ;
sh_mtu2_write(ch, TCR, TCR_CCLR_TGRA | TCR_TPSC_P64);
sh_mtu2_write(ch, TIOR, TIOC_IOCH(TIOR_OC_0_CLEAR) |
TIOC_IOCL(TIOR_OC_0_CLEAR));
sh_mtu2_write(ch, TGR, periodic);
sh_mtu2_write(ch, TCNT, 0);
sh_mtu2_write(ch, TMDR, TMDR_MD_NORMAL);
sh_mtu2_write(ch, TIER, TIER_TGIEA);
sh_mtu2_start_stop_ch(ch, 1);
return 0;
}
static void sh_mtu2_disable(struct sh_mtu2_channel *ch)
{
sh_mtu2_start_stop_ch(ch, 0);
clk_disable(ch->mtu->clk);
dev_pm_syscore_device(&ch->mtu->pdev->dev, false);
pm_runtime_put(&ch->mtu->pdev->dev);
}
static irqreturn_t sh_mtu2_interrupt(int irq, void *dev_id)
{
struct sh_mtu2_channel *ch = dev_id;
sh_mtu2_read(ch, TSR);
sh_mtu2_write(ch, TSR, ~TSR_TGFA);
ch->ced.event_handler(&ch->ced);
return IRQ_HANDLED;
}
static struct sh_mtu2_channel *ced_to_sh_mtu2(struct clock_event_device *ced)
{
return container_of(ced, struct sh_mtu2_channel, ced);
}
static void sh_mtu2_clock_event_mode(enum clock_event_mode mode,
struct clock_event_device *ced)
{
struct sh_mtu2_channel *ch = ced_to_sh_mtu2(ced);
int disabled = 0;
switch (ced->mode) {
case CLOCK_EVT_MODE_PERIODIC:
sh_mtu2_disable(ch);
disabled = 1;
break;
default:
break;
}
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
dev_info(&ch->mtu->pdev->dev,
"ch%u: used for periodic clock events\n", ch->index);
sh_mtu2_enable(ch);
break;
case CLOCK_EVT_MODE_UNUSED:
if (!disabled)
sh_mtu2_disable(ch);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
default:
break;
}
}
static void sh_mtu2_clock_event_suspend(struct clock_event_device *ced)
{
pm_genpd_syscore_poweroff(&ced_to_sh_mtu2(ced)->mtu->pdev->dev);
}
static void sh_mtu2_clock_event_resume(struct clock_event_device *ced)
{
pm_genpd_syscore_poweron(&ced_to_sh_mtu2(ced)->mtu->pdev->dev);
}
static void sh_mtu2_register_clockevent(struct sh_mtu2_channel *ch,
const char *name)
{
struct clock_event_device *ced = &ch->ced;
ced->name = name;
ced->features = CLOCK_EVT_FEAT_PERIODIC;
ced->rating = 200;
ced->cpumask = cpu_possible_mask;
ced->set_mode = sh_mtu2_clock_event_mode;
ced->suspend = sh_mtu2_clock_event_suspend;
ced->resume = sh_mtu2_clock_event_resume;
dev_info(&ch->mtu->pdev->dev, "ch%u: used for clock events\n",
ch->index);
clockevents_register_device(ced);
}
static int sh_mtu2_register(struct sh_mtu2_channel *ch, const char *name)
{
ch->mtu->has_clockevent = true;
sh_mtu2_register_clockevent(ch, name);
return 0;
}
static int sh_mtu2_setup_channel(struct sh_mtu2_channel *ch, unsigned int index,
struct sh_mtu2_device *mtu)
{
static const unsigned int channel_offsets[] = {
0x300, 0x380, 0x000,
};
char name[6];
int irq;
int ret;
ch->mtu = mtu;
sprintf(name, "tgi%ua", index);
irq = platform_get_irq_byname(mtu->pdev, name);
if (irq < 0) {
return 0;
}
ret = request_irq(irq, sh_mtu2_interrupt,
IRQF_TIMER | IRQF_IRQPOLL | IRQF_NOBALANCING,
dev_name(&ch->mtu->pdev->dev), ch);
if (ret) {
dev_err(&ch->mtu->pdev->dev, "ch%u: failed to request irq %d\n",
index, irq);
return ret;
}
ch->base = mtu->mapbase + channel_offsets[index];
ch->index = index;
return sh_mtu2_register(ch, dev_name(&mtu->pdev->dev));
}
static int sh_mtu2_map_memory(struct sh_mtu2_device *mtu)
{
struct resource *res;
res = platform_get_resource(mtu->pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&mtu->pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
mtu->mapbase = ioremap_nocache(res->start, resource_size(res));
if (mtu->mapbase == NULL)
return -ENXIO;
return 0;
}
static int sh_mtu2_setup(struct sh_mtu2_device *mtu,
struct platform_device *pdev)
{
unsigned int i;
int ret;
mtu->pdev = pdev;
raw_spin_lock_init(&mtu->lock);
mtu->clk = clk_get(&mtu->pdev->dev, "fck");
if (IS_ERR(mtu->clk)) {
dev_err(&mtu->pdev->dev, "cannot get clock\n");
return PTR_ERR(mtu->clk);
}
ret = clk_prepare(mtu->clk);
if (ret < 0)
goto err_clk_put;
ret = sh_mtu2_map_memory(mtu);
if (ret < 0) {
dev_err(&mtu->pdev->dev, "failed to remap I/O memory\n");
goto err_clk_unprepare;
}
mtu->num_channels = 3;
mtu->channels = kzalloc(sizeof(*mtu->channels) * mtu->num_channels,
GFP_KERNEL);
if (mtu->channels == NULL) {
ret = -ENOMEM;
goto err_unmap;
}
for (i = 0; i < mtu->num_channels; ++i) {
ret = sh_mtu2_setup_channel(&mtu->channels[i], i, mtu);
if (ret < 0)
goto err_unmap;
}
platform_set_drvdata(pdev, mtu);
return 0;
err_unmap:
kfree(mtu->channels);
iounmap(mtu->mapbase);
err_clk_unprepare:
clk_unprepare(mtu->clk);
err_clk_put:
clk_put(mtu->clk);
return ret;
}
static int sh_mtu2_probe(struct platform_device *pdev)
{
struct sh_mtu2_device *mtu = platform_get_drvdata(pdev);
int ret;
if (!is_early_platform_device(pdev)) {
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
}
if (mtu) {
dev_info(&pdev->dev, "kept as earlytimer\n");
goto out;
}
mtu = kzalloc(sizeof(*mtu), GFP_KERNEL);
if (mtu == NULL)
return -ENOMEM;
ret = sh_mtu2_setup(mtu, pdev);
if (ret) {
kfree(mtu);
pm_runtime_idle(&pdev->dev);
return ret;
}
if (is_early_platform_device(pdev))
return 0;
out:
if (mtu->has_clockevent)
pm_runtime_irq_safe(&pdev->dev);
else
pm_runtime_idle(&pdev->dev);
return 0;
}
static int sh_mtu2_remove(struct platform_device *pdev)
{
return -EBUSY;
}
static int __init sh_mtu2_init(void)
{
return platform_driver_register(&sh_mtu2_device_driver);
}
static void __exit sh_mtu2_exit(void)
{
platform_driver_unregister(&sh_mtu2_device_driver);
}
