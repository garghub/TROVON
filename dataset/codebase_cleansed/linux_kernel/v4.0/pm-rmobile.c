static int rmobile_pd_power_down(struct generic_pm_domain *genpd)
{
struct rmobile_pm_domain *rmobile_pd = to_rmobile_pd(genpd);
unsigned int mask;
if (rmobile_pd->bit_shift == ~0)
return -EBUSY;
mask = 1 << rmobile_pd->bit_shift;
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
mask = 1 << rmobile_pd->bit_shift;
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
static int rmobile_pd_attach_dev(struct generic_pm_domain *domain,
struct device *dev)
{
int error;
error = pm_clk_create(dev);
if (error) {
dev_err(dev, "pm_clk_create failed %d\n", error);
return error;
}
error = pm_clk_add(dev, NULL);
if (error) {
dev_err(dev, "pm_clk_add failed %d\n", error);
goto fail;
}
return 0;
fail:
pm_clk_destroy(dev);
return error;
}
static void rmobile_pd_detach_dev(struct generic_pm_domain *domain,
struct device *dev)
{
pm_clk_destroy(dev);
}
static void rmobile_init_pm_domain(struct rmobile_pm_domain *rmobile_pd)
{
struct generic_pm_domain *genpd = &rmobile_pd->genpd;
struct dev_power_governor *gov = rmobile_pd->gov;
genpd->flags = GENPD_FLAG_PM_CLK;
pm_genpd_init(genpd, gov ? : &simple_qos_governor, false);
genpd->dev_ops.active_wakeup = rmobile_pd_active_wakeup;
genpd->power_off = rmobile_pd_power_down;
genpd->power_on = rmobile_pd_power_up;
genpd->attach_dev = rmobile_pd_attach_dev;
genpd->detach_dev = rmobile_pd_detach_dev;
__rmobile_pd_power_up(rmobile_pd, false);
}
void rmobile_init_domains(struct rmobile_pm_domain domains[], int num)
{
int j;
for (j = 0; j < num; j++)
rmobile_init_pm_domain(&domains[j]);
}
void rmobile_add_device_to_domain_td(const char *domain_name,
struct platform_device *pdev,
struct gpd_timing_data *td)
{
struct device *dev = &pdev->dev;
__pm_genpd_name_add_device(domain_name, dev, td);
}
void rmobile_add_devices_to_domains(struct pm_domain_device data[],
int size)
{
struct gpd_timing_data latencies = {
.stop_latency_ns = DEFAULT_DEV_LATENCY_NS,
.start_latency_ns = DEFAULT_DEV_LATENCY_NS,
.save_state_latency_ns = DEFAULT_DEV_LATENCY_NS,
.restore_state_latency_ns = DEFAULT_DEV_LATENCY_NS,
};
int j;
for (j = 0; j < size; j++)
rmobile_add_device_to_domain_td(data[j].domain_name,
data[j].pdev, &latencies);
}
static int rmobile_pd_suspend_busy(void)
{
return -EBUSY;
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
pr_debug("Special PM domain %s type %d for %s\n", pd->name, type,
np->full_name);
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
pd->gov = &pm_domain_always_on_gov;
pd->suspend = rmobile_pd_suspend_busy;
break;
case PD_CONSOLE:
pr_debug("PM domain %s contains serial console\n", name);
pd->gov = &pm_domain_always_on_gov;
pd->suspend = rmobile_pd_suspend_console;
break;
case PD_DEBUG:
pr_debug("PM domain %s contains Coresight-ETM\n", name);
pd->gov = &pm_domain_always_on_gov;
pd->suspend = rmobile_pd_suspend_busy;
break;
case PD_MEMCTL:
pr_debug("PM domain %s contains MEMCTL\n", name);
pd->gov = &pm_domain_always_on_gov;
pd->suspend = rmobile_pd_suspend_busy;
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
if (!pd)
return -ENOMEM;
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
pr_warn("%s cannot map reg 0\n", np->full_name);
continue;
}
pmd = of_get_child_by_name(np, "pm-domains");
if (!pmd) {
pr_warn("%s lacks pm-domains node\n", np->full_name);
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
