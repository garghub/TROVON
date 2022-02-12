static inline
struct rmobile_pm_domain *to_rmobile_pd(struct generic_pm_domain *d)
{
return container_of(d, struct rmobile_pm_domain, genpd);
}
static int rmobile_pd_power_down(struct generic_pm_domain *genpd)
{
struct rmobile_pm_domain *rmobile_pd = to_rmobile_pd(genpd);
unsigned int mask;
if (rmobile_pd->bit_shift == ~0)
return -EBUSY;
mask = BIT(rmobile_pd->bit_shift);
if (rmobile_pd->suspend) {
int ret = rmobile_pd->suspend();
if (ret)
return ret;
}
if (__raw_readl(rmobile_pd->base + PSTR) & mask) {
unsigned int retry_count;
__raw_writel(mask, rmobile_pd->base + SPDCR);
for (retry_count = PSTR_RETRIES; retry_count; retry_count--) {
if (!(__raw_readl(rmobile_pd->base + SPDCR) & mask))
break;
cpu_relax();
}
}
if (!rmobile_pd->no_debug)
pr_debug("%s: Power off, 0x%08x -> PSTR = 0x%08x\n",
genpd->name, mask,
__raw_readl(rmobile_pd->base + PSTR));
return 0;
}
static int __rmobile_pd_power_up(struct rmobile_pm_domain *rmobile_pd,
bool do_resume)
{
unsigned int mask;
unsigned int retry_count;
int ret = 0;
if (rmobile_pd->bit_shift == ~0)
return 0;
mask = BIT(rmobile_pd->bit_shift);
if (__raw_readl(rmobile_pd->base + PSTR) & mask)
goto out;
__raw_writel(mask, rmobile_pd->base + SWUCR);
for (retry_count = 2 * PSTR_RETRIES; retry_count; retry_count--) {
if (!(__raw_readl(rmobile_pd->base + SWUCR) & mask))
break;
if (retry_count > PSTR_RETRIES)
udelay(PSTR_DELAY_US);
else
cpu_relax();
}
if (!retry_count)
ret = -EIO;
if (!rmobile_pd->no_debug)
pr_debug("%s: Power on, 0x%08x -> PSTR = 0x%08x\n",
rmobile_pd->genpd.name, mask,
__raw_readl(rmobile_pd->base + PSTR));
out:
if (ret == 0 && rmobile_pd->resume && do_resume)
rmobile_pd->resume();
return ret;
}
static int rmobile_pd_power_up(struct generic_pm_domain *genpd)
{
return __rmobile_pd_power_up(to_rmobile_pd(genpd), true);
}
static bool rmobile_pd_active_wakeup(struct device *dev)
{
return true;
}
static void rmobile_init_pm_domain(struct rmobile_pm_domain *rmobile_pd)
{
struct generic_pm_domain *genpd = &rmobile_pd->genpd;
struct dev_power_governor *gov = rmobile_pd->gov;
genpd->flags |= GENPD_FLAG_PM_CLK;
genpd->dev_ops.active_wakeup = rmobile_pd_active_wakeup;
genpd->power_off = rmobile_pd_power_down;
genpd->power_on = rmobile_pd_power_up;
genpd->attach_dev = cpg_mstp_attach_dev;
genpd->detach_dev = cpg_mstp_detach_dev;
__rmobile_pd_power_up(rmobile_pd, false);
pm_genpd_init(genpd, gov ? : &simple_qos_governor, false);
}
static int rmobile_pd_suspend_console(void)
{
return console_suspend_enabled ? 0 : -EBUSY;
}
static void __init add_special_pd(struct device_node *np, enum pd_types type)
{
unsigned int i;
struct device_node *pd;
pd = of_parse_phandle(np, "power-domains", 0);
if (!pd)
return;
for (i = 0; i < num_special_pds; i++)
if (pd == special_pds[i].pd && type == special_pds[i].type) {
of_node_put(pd);
return;
}
if (num_special_pds == ARRAY_SIZE(special_pds)) {
pr_warn("Too many special PM domains\n");
of_node_put(pd);
return;
}
pr_debug("Special PM domain %s type %d for %pOF\n", pd->name, type, np);
special_pds[num_special_pds].pd = pd;
special_pds[num_special_pds].type = type;
num_special_pds++;
}
static void __init get_special_pds(void)
{
struct device_node *np;
const struct of_device_id *id;
for_each_node_by_type(np, "cpu")
add_special_pd(np, PD_CPU);
if (of_stdout)
add_special_pd(of_stdout, PD_CONSOLE);
for_each_matching_node_and_match(np, special_ids, &id)
add_special_pd(np, (enum pd_types)id->data);
}
static void __init put_special_pds(void)
{
unsigned int i;
for (i = 0; i < num_special_pds; i++)
of_node_put(special_pds[i].pd);
}
static enum pd_types __init pd_type(const struct device_node *pd)
{
unsigned int i;
for (i = 0; i < num_special_pds; i++)
if (pd == special_pds[i].pd)
return special_pds[i].type;
return PD_NORMAL;
}
static void __init rmobile_setup_pm_domain(struct device_node *np,
struct rmobile_pm_domain *pd)
{
const char *name = pd->genpd.name;
switch (pd_type(np)) {
case PD_CPU:
pr_debug("PM domain %s contains CPU\n", name);
pd->genpd.flags |= GENPD_FLAG_ALWAYS_ON;
break;
case PD_CONSOLE:
pr_debug("PM domain %s contains serial console\n", name);
pd->gov = &pm_domain_always_on_gov;
pd->suspend = rmobile_pd_suspend_console;
break;
case PD_DEBUG:
pr_debug("PM domain %s contains Coresight-ETM\n", name);
pd->genpd.flags |= GENPD_FLAG_ALWAYS_ON;
break;
case PD_MEMCTL:
pr_debug("PM domain %s contains MEMCTL\n", name);
pd->genpd.flags |= GENPD_FLAG_ALWAYS_ON;
break;
case PD_NORMAL:
break;
}
rmobile_init_pm_domain(pd);
}
static int __init rmobile_add_pm_domains(void __iomem *base,
struct device_node *parent,
struct generic_pm_domain *genpd_parent)
{
struct device_node *np;
for_each_child_of_node(parent, np) {
struct rmobile_pm_domain *pd;
u32 idx = ~0;
if (of_property_read_u32(np, "reg", &idx)) {
}
pd = kzalloc(sizeof(*pd), GFP_KERNEL);
if (!pd) {
of_node_put(np);
return -ENOMEM;
}
pd->genpd.name = np->name;
pd->base = base;
pd->bit_shift = idx;
rmobile_setup_pm_domain(np, pd);
if (genpd_parent)
pm_genpd_add_subdomain(genpd_parent, &pd->genpd);
of_genpd_add_provider_simple(np, &pd->genpd);
rmobile_add_pm_domains(base, np, &pd->genpd);
}
return 0;
}
static int __init rmobile_init_pm_domains(void)
{
struct device_node *np, *pmd;
bool scanned = false;
void __iomem *base;
int ret = 0;
for_each_compatible_node(np, NULL, "renesas,sysc-rmobile") {
base = of_iomap(np, 0);
if (!base) {
pr_warn("%pOF cannot map reg 0\n", np);
continue;
}
pmd = of_get_child_by_name(np, "pm-domains");
if (!pmd) {
pr_warn("%pOF lacks pm-domains node\n", np);
continue;
}
if (!scanned) {
get_special_pds();
scanned = true;
}
ret = rmobile_add_pm_domains(base, pmd, NULL);
of_node_put(pmd);
if (ret) {
of_node_put(np);
break;
}
}
put_special_pds();
return ret;
}
