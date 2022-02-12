static inline struct rcar_sysc_ch *to_r8a7779_ch(struct generic_pm_domain *d)
{
return &container_of(d, struct r8a7779_pm_domain, genpd)->ch;
}
static void __init r8a7779_sysc_init(void)
{
void __iomem *base = rcar_sysc_init(0xffd85000);
iowrite32(0x0131000e, base + SYSCIER);
iowrite32(0, base + SYSCIMR);
}
static inline void r8a7779_sysc_init(void) {}
static int pd_power_down(struct generic_pm_domain *genpd)
{
return rcar_sysc_power_down(to_r8a7779_ch(genpd));
}
static int pd_power_up(struct generic_pm_domain *genpd)
{
return rcar_sysc_power_up(to_r8a7779_ch(genpd));
}
static bool pd_is_off(struct generic_pm_domain *genpd)
{
return rcar_sysc_power_is_off(to_r8a7779_ch(genpd));
}
static bool pd_active_wakeup(struct device *dev)
{
return true;
}
static void r8a7779_init_pm_domain(struct r8a7779_pm_domain *r8a7779_pd)
{
struct generic_pm_domain *genpd = &r8a7779_pd->genpd;
pm_genpd_init(genpd, NULL, false);
genpd->dev_ops.stop = pm_clk_suspend;
genpd->dev_ops.start = pm_clk_resume;
genpd->dev_ops.active_wakeup = pd_active_wakeup;
genpd->power_off = pd_power_down;
genpd->power_on = pd_power_up;
if (pd_is_off(&r8a7779_pd->genpd))
pd_power_up(&r8a7779_pd->genpd);
}
void __init r8a7779_init_pm_domains(void)
{
int j;
for (j = 0; j < ARRAY_SIZE(r8a7779_pm_domains); j++)
r8a7779_init_pm_domain(&r8a7779_pm_domains[j]);
}
void __init r8a7779_pm_init(void)
{
static int once;
if (!once++)
r8a7779_sysc_init();
}
