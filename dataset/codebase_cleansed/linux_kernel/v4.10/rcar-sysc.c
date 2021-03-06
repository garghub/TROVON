static int rcar_sysc_pwr_on_off(const struct rcar_sysc_ch *sysc_ch, bool on)
{
unsigned int sr_bit, reg_offs;
int k;
if (on) {
sr_bit = SYSCSR_PONENB;
reg_offs = PWRONCR_OFFS;
} else {
sr_bit = SYSCSR_POFFENB;
reg_offs = PWROFFCR_OFFS;
}
for (k = 0; k < SYSCSR_RETRIES; k++) {
if (ioread32(rcar_sysc_base + SYSCSR) & BIT(sr_bit))
break;
udelay(SYSCSR_DELAY_US);
}
if (k == SYSCSR_RETRIES)
return -EAGAIN;
iowrite32(BIT(sysc_ch->chan_bit),
rcar_sysc_base + sysc_ch->chan_offs + reg_offs);
return 0;
}
static int rcar_sysc_power(const struct rcar_sysc_ch *sysc_ch, bool on)
{
unsigned int isr_mask = BIT(sysc_ch->isr_bit);
unsigned int chan_mask = BIT(sysc_ch->chan_bit);
unsigned int status;
unsigned long flags;
int ret = 0;
int k;
spin_lock_irqsave(&rcar_sysc_lock, flags);
iowrite32(isr_mask, rcar_sysc_base + SYSCISCR);
for (k = 0; k < PWRER_RETRIES; k++) {
ret = rcar_sysc_pwr_on_off(sysc_ch, on);
if (ret)
goto out;
status = ioread32(rcar_sysc_base +
sysc_ch->chan_offs + PWRER_OFFS);
if (!(status & chan_mask))
break;
udelay(PWRER_DELAY_US);
}
if (k == PWRER_RETRIES) {
ret = -EIO;
goto out;
}
for (k = 0; k < SYSCISR_RETRIES; k++) {
if (ioread32(rcar_sysc_base + SYSCISR) & isr_mask)
break;
udelay(SYSCISR_DELAY_US);
}
if (k == SYSCISR_RETRIES)
ret = -EIO;
iowrite32(isr_mask, rcar_sysc_base + SYSCISCR);
out:
spin_unlock_irqrestore(&rcar_sysc_lock, flags);
pr_debug("sysc power %s domain %d: %08x -> %d\n", on ? "on" : "off",
sysc_ch->isr_bit, ioread32(rcar_sysc_base + SYSCISR), ret);
return ret;
}
int rcar_sysc_power_down(const struct rcar_sysc_ch *sysc_ch)
{
return rcar_sysc_power(sysc_ch, false);
}
int rcar_sysc_power_up(const struct rcar_sysc_ch *sysc_ch)
{
return rcar_sysc_power(sysc_ch, true);
}
static bool rcar_sysc_power_is_off(const struct rcar_sysc_ch *sysc_ch)
{
unsigned int st;
st = ioread32(rcar_sysc_base + sysc_ch->chan_offs + PWRSR_OFFS);
if (st & BIT(sysc_ch->chan_bit))
return true;
return false;
}
static inline struct rcar_sysc_pd *to_rcar_pd(struct generic_pm_domain *d)
{
return container_of(d, struct rcar_sysc_pd, genpd);
}
static int rcar_sysc_pd_power_off(struct generic_pm_domain *genpd)
{
struct rcar_sysc_pd *pd = to_rcar_pd(genpd);
pr_debug("%s: %s\n", __func__, genpd->name);
if (pd->flags & PD_NO_CR) {
pr_debug("%s: Cannot control %s\n", __func__, genpd->name);
return -EBUSY;
}
if (pd->flags & PD_BUSY) {
pr_debug("%s: %s busy\n", __func__, genpd->name);
return -EBUSY;
}
return rcar_sysc_power_down(&pd->ch);
}
static int rcar_sysc_pd_power_on(struct generic_pm_domain *genpd)
{
struct rcar_sysc_pd *pd = to_rcar_pd(genpd);
pr_debug("%s: %s\n", __func__, genpd->name);
if (pd->flags & PD_NO_CR) {
pr_debug("%s: Cannot control %s\n", __func__, genpd->name);
return 0;
}
return rcar_sysc_power_up(&pd->ch);
}
static void __init rcar_sysc_pd_setup(struct rcar_sysc_pd *pd)
{
struct generic_pm_domain *genpd = &pd->genpd;
const char *name = pd->genpd.name;
struct dev_power_governor *gov = &simple_qos_governor;
if (pd->flags & PD_CPU) {
pr_debug("PM domain %s contains %s\n", name, "CPU");
pd->flags |= PD_BUSY;
gov = &pm_domain_always_on_gov;
} else if (pd->flags & PD_SCU) {
pr_debug("PM domain %s contains %s\n", name, "SCU");
pd->flags |= PD_BUSY;
gov = &pm_domain_always_on_gov;
} else if (pd->flags & PD_NO_CR) {
pd->flags |= PD_BUSY;
gov = &pm_domain_always_on_gov;
}
if (!(pd->flags & (PD_CPU | PD_SCU))) {
genpd->flags = GENPD_FLAG_PM_CLK;
if (has_cpg_mstp) {
genpd->attach_dev = cpg_mstp_attach_dev;
genpd->detach_dev = cpg_mstp_detach_dev;
} else {
genpd->attach_dev = cpg_mssr_attach_dev;
genpd->detach_dev = cpg_mssr_detach_dev;
}
}
genpd->power_off = rcar_sysc_pd_power_off;
genpd->power_on = rcar_sysc_pd_power_on;
if (pd->flags & (PD_CPU | PD_NO_CR)) {
pr_debug("%s: Not touching %s\n", __func__, genpd->name);
goto finalize;
}
if (!rcar_sysc_power_is_off(&pd->ch)) {
pr_debug("%s: %s is already powered\n", __func__, genpd->name);
goto finalize;
}
rcar_sysc_power_up(&pd->ch);
finalize:
pm_genpd_init(genpd, gov, false);
}
static int __init rcar_sysc_pd_init(void)
{
const struct rcar_sysc_info *info;
const struct of_device_id *match;
struct rcar_pm_domains *domains;
struct device_node *np;
u32 syscier, syscimr;
void __iomem *base;
unsigned int i;
int error;
if (rcar_sysc_base)
return 0;
np = of_find_matching_node_and_match(NULL, rcar_sysc_matches, &match);
if (!np)
return -ENODEV;
info = match->data;
has_cpg_mstp = of_find_compatible_node(NULL, NULL,
"renesas,cpg-mstp-clocks");
base = of_iomap(np, 0);
if (!base) {
pr_warn("%s: Cannot map regs\n", np->full_name);
error = -ENOMEM;
goto out_put;
}
rcar_sysc_base = base;
domains = kzalloc(sizeof(*domains), GFP_KERNEL);
if (!domains) {
error = -ENOMEM;
goto out_put;
}
domains->onecell_data.domains = domains->domains;
domains->onecell_data.num_domains = ARRAY_SIZE(domains->domains);
for (i = 0, syscier = 0; i < info->num_areas; i++)
syscier |= BIT(info->areas[i].isr_bit);
syscimr = ioread32(base + SYSCIMR);
syscimr |= syscier;
pr_debug("%s: syscimr = 0x%08x\n", np->full_name, syscimr);
iowrite32(syscimr, base + SYSCIMR);
pr_debug("%s: syscier = 0x%08x\n", np->full_name, syscier);
iowrite32(syscier, base + SYSCIER);
for (i = 0; i < info->num_areas; i++) {
const struct rcar_sysc_area *area = &info->areas[i];
struct rcar_sysc_pd *pd;
pd = kzalloc(sizeof(*pd) + strlen(area->name) + 1, GFP_KERNEL);
if (!pd) {
error = -ENOMEM;
goto out_put;
}
strcpy(pd->name, area->name);
pd->genpd.name = pd->name;
pd->ch.chan_offs = area->chan_offs;
pd->ch.chan_bit = area->chan_bit;
pd->ch.isr_bit = area->isr_bit;
pd->flags = area->flags;
rcar_sysc_pd_setup(pd);
if (area->parent >= 0)
pm_genpd_add_subdomain(domains->domains[area->parent],
&pd->genpd);
domains->domains[area->isr_bit] = &pd->genpd;
}
error = of_genpd_add_provider_onecell(np, &domains->onecell_data);
out_put:
of_node_put(np);
return error;
}
void __init rcar_sysc_init(phys_addr_t base, u32 syscier)
{
u32 syscimr;
if (!rcar_sysc_pd_init())
return;
rcar_sysc_base = ioremap_nocache(base, PAGE_SIZE);
syscimr = ioread32(rcar_sysc_base + SYSCIMR);
syscimr |= syscier;
pr_debug("%s: syscimr = 0x%08x\n", __func__, syscimr);
iowrite32(syscimr, rcar_sysc_base + SYSCIMR);
pr_debug("%s: syscier = 0x%08x\n", __func__, syscier);
iowrite32(syscier, rcar_sysc_base + SYSCIER);
}
