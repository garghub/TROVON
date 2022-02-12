static int gdsc_is_enabled(struct gdsc *sc)
{
u32 val;
int ret;
ret = regmap_read(sc->regmap, sc->gdscr, &val);
if (ret)
return ret;
return !!(val & PWR_ON_MASK);
}
static int gdsc_toggle_logic(struct gdsc *sc, bool en)
{
int ret;
u32 val = en ? 0 : SW_COLLAPSE_MASK;
u32 check = en ? PWR_ON_MASK : 0;
unsigned long timeout;
ret = regmap_update_bits(sc->regmap, sc->gdscr, SW_COLLAPSE_MASK, val);
if (ret)
return ret;
timeout = jiffies + usecs_to_jiffies(TIMEOUT_US);
do {
ret = regmap_read(sc->regmap, sc->gdscr, &val);
if (ret)
return ret;
if ((val & PWR_ON_MASK) == check)
return 0;
} while (time_before(jiffies, timeout));
ret = regmap_read(sc->regmap, sc->gdscr, &val);
if (ret)
return ret;
if ((val & PWR_ON_MASK) == check)
return 0;
return -ETIMEDOUT;
}
static inline int gdsc_deassert_reset(struct gdsc *sc)
{
int i;
for (i = 0; i < sc->reset_count; i++)
sc->rcdev->ops->deassert(sc->rcdev, sc->resets[i]);
return 0;
}
static inline int gdsc_assert_reset(struct gdsc *sc)
{
int i;
for (i = 0; i < sc->reset_count; i++)
sc->rcdev->ops->assert(sc->rcdev, sc->resets[i]);
return 0;
}
static inline void gdsc_force_mem_on(struct gdsc *sc)
{
int i;
u32 mask = RETAIN_MEM | RETAIN_PERIPH;
for (i = 0; i < sc->cxc_count; i++)
regmap_update_bits(sc->regmap, sc->cxcs[i], mask, mask);
}
static inline void gdsc_clear_mem_on(struct gdsc *sc)
{
int i;
u32 mask = RETAIN_MEM | RETAIN_PERIPH;
for (i = 0; i < sc->cxc_count; i++)
regmap_update_bits(sc->regmap, sc->cxcs[i], mask, 0);
}
static int gdsc_enable(struct generic_pm_domain *domain)
{
struct gdsc *sc = domain_to_gdsc(domain);
int ret;
if (sc->pwrsts == PWRSTS_ON)
return gdsc_deassert_reset(sc);
ret = gdsc_toggle_logic(sc, true);
if (ret)
return ret;
if (sc->pwrsts & PWRSTS_OFF)
gdsc_force_mem_on(sc);
udelay(1);
return 0;
}
static int gdsc_disable(struct generic_pm_domain *domain)
{
struct gdsc *sc = domain_to_gdsc(domain);
if (sc->pwrsts == PWRSTS_ON)
return gdsc_assert_reset(sc);
if (sc->pwrsts & PWRSTS_OFF)
gdsc_clear_mem_on(sc);
return gdsc_toggle_logic(sc, false);
}
static int gdsc_init(struct gdsc *sc)
{
u32 mask, val;
int on, ret;
mask = HW_CONTROL_MASK | SW_OVERRIDE_MASK |
EN_REST_WAIT_MASK | EN_FEW_WAIT_MASK | CLK_DIS_WAIT_MASK;
val = EN_REST_WAIT_VAL | EN_FEW_WAIT_VAL | CLK_DIS_WAIT_VAL;
ret = regmap_update_bits(sc->regmap, sc->gdscr, mask, val);
if (ret)
return ret;
if (sc->pwrsts == PWRSTS_ON) {
ret = gdsc_toggle_logic(sc, true);
if (ret)
return ret;
}
on = gdsc_is_enabled(sc);
if (on < 0)
return on;
if (on || (sc->pwrsts & PWRSTS_RET))
gdsc_force_mem_on(sc);
else
gdsc_clear_mem_on(sc);
sc->pd.power_off = gdsc_disable;
sc->pd.power_on = gdsc_enable;
pm_genpd_init(&sc->pd, NULL, !on);
return 0;
}
int gdsc_register(struct device *dev, struct gdsc **scs, size_t num,
struct reset_controller_dev *rcdev, struct regmap *regmap)
{
int i, ret;
struct genpd_onecell_data *data;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->domains = devm_kcalloc(dev, num, sizeof(*data->domains),
GFP_KERNEL);
if (!data->domains)
return -ENOMEM;
data->num_domains = num;
for (i = 0; i < num; i++) {
if (!scs[i])
continue;
scs[i]->regmap = regmap;
scs[i]->rcdev = rcdev;
ret = gdsc_init(scs[i]);
if (ret)
return ret;
data->domains[i] = &scs[i]->pd;
}
return of_genpd_add_provider_onecell(dev->of_node, data);
}
void gdsc_unregister(struct device *dev)
{
of_genpd_del_provider(dev->of_node);
}
