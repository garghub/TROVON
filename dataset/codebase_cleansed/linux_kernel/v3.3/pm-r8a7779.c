static int r8a7779_sysc_pwr_on_off(struct r8a7779_pm_ch *r8a7779_ch,
int sr_bit, int reg_offs)
{
int k;
for (k = 0; k < SYSCSR_RETRIES; k++) {
if (ioread32(r8a7779_sysc_base + SYSCSR) & (1 << sr_bit))
break;
udelay(SYSCSR_DELAY_US);
}
if (k == SYSCSR_RETRIES)
return -EAGAIN;
iowrite32(1 << r8a7779_ch->chan_bit,
r8a7779_sysc_base + r8a7779_ch->chan_offs + reg_offs);
return 0;
}
static int r8a7779_sysc_pwr_off(struct r8a7779_pm_ch *r8a7779_ch)
{
return r8a7779_sysc_pwr_on_off(r8a7779_ch, 0, PWROFFCR_OFFS);
}
static int r8a7779_sysc_pwr_on(struct r8a7779_pm_ch *r8a7779_ch)
{
return r8a7779_sysc_pwr_on_off(r8a7779_ch, 1, PWRONCR_OFFS);
}
static int r8a7779_sysc_update(struct r8a7779_pm_ch *r8a7779_ch,
int (*on_off_fn)(struct r8a7779_pm_ch *))
{
unsigned int isr_mask = 1 << r8a7779_ch->isr_bit;
unsigned int chan_mask = 1 << r8a7779_ch->chan_bit;
unsigned int status;
unsigned long flags;
int ret = 0;
int k;
spin_lock_irqsave(&r8a7779_sysc_lock, flags);
iowrite32(isr_mask, r8a7779_sysc_base + SYSCISCR);
do {
ret = on_off_fn(r8a7779_ch);
if (ret)
goto out;
status = ioread32(r8a7779_sysc_base +
r8a7779_ch->chan_offs + PWRER_OFFS);
} while (status & chan_mask);
for (k = 0; k < SYSCISR_RETRIES; k++) {
if (ioread32(r8a7779_sysc_base + SYSCISR) & isr_mask)
break;
udelay(SYSCISR_DELAY_US);
}
if (k == SYSCISR_RETRIES)
ret = -EIO;
iowrite32(isr_mask, r8a7779_sysc_base + SYSCISCR);
out:
spin_unlock_irqrestore(&r8a7779_sysc_lock, flags);
pr_debug("r8a7779 power domain %d: %02x %02x %02x %02x %02x -> %d\n",
r8a7779_ch->isr_bit, ioread32(r8a7779_sysc_base + PWRSR0),
ioread32(r8a7779_sysc_base + PWRSR1),
ioread32(r8a7779_sysc_base + PWRSR2),
ioread32(r8a7779_sysc_base + PWRSR3),
ioread32(r8a7779_sysc_base + PWRSR4), ret);
return ret;
}
int r8a7779_sysc_power_down(struct r8a7779_pm_ch *r8a7779_ch)
{
return r8a7779_sysc_update(r8a7779_ch, r8a7779_sysc_pwr_off);
}
int r8a7779_sysc_power_up(struct r8a7779_pm_ch *r8a7779_ch)
{
return r8a7779_sysc_update(r8a7779_ch, r8a7779_sysc_pwr_on);
}
static void __init r8a7779_sysc_init(void)
{
r8a7779_sysc_base = ioremap_nocache(0xffd85000, PAGE_SIZE);
if (!r8a7779_sysc_base)
panic("unable to ioremap r8a7779 SYSC hardware block\n");
iowrite32(0x0131000e, r8a7779_sysc_base + SYSCIER);
iowrite32(0, r8a7779_sysc_base + SYSCIMR);
}
static inline void r8a7779_sysc_init(void) {}
static int pd_power_down(struct generic_pm_domain *genpd)
{
return r8a7779_sysc_power_down(to_r8a7779_ch(genpd));
}
static int pd_power_up(struct generic_pm_domain *genpd)
{
return r8a7779_sysc_power_up(to_r8a7779_ch(genpd));
}
static bool pd_is_off(struct generic_pm_domain *genpd)
{
struct r8a7779_pm_ch *r8a7779_ch = to_r8a7779_ch(genpd);
unsigned int st;
st = ioread32(r8a7779_sysc_base + r8a7779_ch->chan_offs + PWRSR_OFFS);
if (st & (1 << r8a7779_ch->chan_bit))
return true;
return false;
}
static bool pd_active_wakeup(struct device *dev)
{
return true;
}
void r8a7779_init_pm_domain(struct r8a7779_pm_domain *r8a7779_pd)
{
struct generic_pm_domain *genpd = &r8a7779_pd->genpd;
pm_genpd_init(genpd, NULL, false);
genpd->dev_ops.stop = pm_clk_suspend;
genpd->dev_ops.start = pm_clk_resume;
genpd->dev_ops.active_wakeup = pd_active_wakeup;
genpd->dev_irq_safe = true;
genpd->power_off = pd_power_down;
genpd->power_on = pd_power_up;
if (pd_is_off(&r8a7779_pd->genpd))
pd_power_up(&r8a7779_pd->genpd);
}
void r8a7779_add_device_to_domain(struct r8a7779_pm_domain *r8a7779_pd,
struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
pm_genpd_add_device(&r8a7779_pd->genpd, dev);
if (pm_clk_no_clocks(dev))
pm_clk_add(dev, NULL);
}
void __init r8a7779_pm_init(void)
{
static int once;
if (!once++)
r8a7779_sysc_init();
}
