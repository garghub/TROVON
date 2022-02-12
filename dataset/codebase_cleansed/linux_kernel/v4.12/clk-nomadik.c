static int nomadik_clk_reboot_handler(struct notifier_block *this,
unsigned long code,
void *unused)
{
u32 val;
val = readl(src_base + SRC_XTALCR);
val &= ~SRC_XTALCR_MXTALOVER;
val |= SRC_XTALCR_MXTALEN;
pr_crit("force-enabling MXTALO\n");
writel(val, src_base + SRC_XTALCR);
return NOTIFY_OK;
}
static void __init nomadik_src_init(void)
{
struct device_node *np;
u32 val;
np = of_find_matching_node(NULL, nomadik_src_match);
if (!np) {
pr_crit("no matching node for SRC, aborting clock init\n");
return;
}
src_base = of_iomap(np, 0);
if (!src_base) {
pr_err("%s: must have src parent node with REGS (%s)\n",
__func__, np->name);
return;
}
val = readl(src_base + SRC_CR);
val |= SRC_CR_T0_ENSEL;
val |= SRC_CR_T1_ENSEL;
val |= SRC_CR_T2_ENSEL;
val |= SRC_CR_T3_ENSEL;
val |= SRC_CR_T4_ENSEL;
val |= SRC_CR_T5_ENSEL;
val |= SRC_CR_T6_ENSEL;
val |= SRC_CR_T7_ENSEL;
writel(val, src_base + SRC_CR);
val = readl(src_base + SRC_XTALCR);
pr_info("SXTALO is %s\n",
(val & SRC_XTALCR_SXTALDIS) ? "disabled" : "enabled");
pr_info("MXTAL is %s\n",
(val & SRC_XTALCR_MXTALSTAT) ? "enabled" : "disabled");
if (of_property_read_bool(np, "disable-sxtalo")) {
val |= SRC_XTALCR_SXTALDIS;
pr_info("disabling SXTALO\n");
}
if (of_property_read_bool(np, "disable-mxtalo")) {
val |= SRC_XTALCR_MXTALOVER;
val &= ~SRC_XTALCR_MXTALEN;
pr_info("disabling MXTALO\n");
}
writel(val, src_base + SRC_XTALCR);
register_reboot_notifier(&nomadik_clk_reboot_notifier);
}
static int pll_clk_enable(struct clk_hw *hw)
{
struct clk_pll *pll = to_pll(hw);
u32 val;
spin_lock(&src_lock);
val = readl(src_base + SRC_PLLCR);
if (pll->id == 1) {
if (val & SRC_PLLCR_PLL1OVER) {
val |= SRC_PLLCR_PLL1EN;
writel(val, src_base + SRC_PLLCR);
}
} else if (pll->id == 2) {
val |= SRC_PLLCR_PLL2EN;
writel(val, src_base + SRC_PLLCR);
}
spin_unlock(&src_lock);
return 0;
}
static void pll_clk_disable(struct clk_hw *hw)
{
struct clk_pll *pll = to_pll(hw);
u32 val;
spin_lock(&src_lock);
val = readl(src_base + SRC_PLLCR);
if (pll->id == 1) {
if (val & SRC_PLLCR_PLL1OVER) {
val &= ~SRC_PLLCR_PLL1EN;
writel(val, src_base + SRC_PLLCR);
}
} else if (pll->id == 2) {
val &= ~SRC_PLLCR_PLL2EN;
writel(val, src_base + SRC_PLLCR);
}
spin_unlock(&src_lock);
}
static int pll_clk_is_enabled(struct clk_hw *hw)
{
struct clk_pll *pll = to_pll(hw);
u32 val;
val = readl(src_base + SRC_PLLCR);
if (pll->id == 1) {
if (val & SRC_PLLCR_PLL1OVER)
return !!(val & SRC_PLLCR_PLL1EN);
} else if (pll->id == 2) {
return !!(val & SRC_PLLCR_PLL2EN);
}
return 1;
}
static unsigned long pll_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pll *pll = to_pll(hw);
u32 val;
val = readl(src_base + SRC_PLLFR);
if (pll->id == 1) {
u8 mul;
u8 div;
mul = (val >> 8) & 0x3FU;
mul += 2;
div = val & 0x07U;
return (parent_rate * mul) >> div;
}
if (pll->id == 2) {
u8 mul;
mul = (val >> 24) & 0x3FU;
mul += 2;
return (parent_rate * mul);
}
return 0;
}
static struct clk_hw * __init
pll_clk_register(struct device *dev, const char *name,
const char *parent_name, u32 id)
{
int ret;
struct clk_pll *pll;
struct clk_init_data init;
if (id != 1 && id != 2) {
pr_err("%s: the Nomadik has only PLL 1 & 2\n", __func__);
return ERR_PTR(-EINVAL);
}
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &pll_clk_ops;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
pll->hw.init = &init;
pll->id = id;
pr_debug("register PLL1 clock \"%s\"\n", name);
ret = clk_hw_register(dev, &pll->hw);
if (ret) {
kfree(pll);
return ERR_PTR(ret);
}
return &pll->hw;
}
static int src_clk_enable(struct clk_hw *hw)
{
struct clk_src *sclk = to_src(hw);
u32 enreg = sclk->group1 ? SRC_PCKEN1 : SRC_PCKEN0;
u32 sreg = sclk->group1 ? SRC_PCKSR1 : SRC_PCKSR0;
writel(sclk->clkbit, src_base + enreg);
while (!(readl(src_base + sreg) & sclk->clkbit))
cpu_relax();
return 0;
}
static void src_clk_disable(struct clk_hw *hw)
{
struct clk_src *sclk = to_src(hw);
u32 disreg = sclk->group1 ? SRC_PCKDIS1 : SRC_PCKDIS0;
u32 sreg = sclk->group1 ? SRC_PCKSR1 : SRC_PCKSR0;
writel(sclk->clkbit, src_base + disreg);
while (readl(src_base + sreg) & sclk->clkbit)
cpu_relax();
}
static int src_clk_is_enabled(struct clk_hw *hw)
{
struct clk_src *sclk = to_src(hw);
u32 sreg = sclk->group1 ? SRC_PCKSR1 : SRC_PCKSR0;
u32 val = readl(src_base + sreg);
return !!(val & sclk->clkbit);
}
static unsigned long
src_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate;
}
static struct clk_hw * __init
src_clk_register(struct device *dev, const char *name,
const char *parent_name, u8 id)
{
int ret;
struct clk_src *sclk;
struct clk_init_data init;
sclk = kzalloc(sizeof(*sclk), GFP_KERNEL);
if (!sclk)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &src_clk_ops;
if (id == 2)
init.flags = CLK_IGNORE_UNUSED;
else
init.flags = 0;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
sclk->hw.init = &init;
sclk->id = id;
sclk->group1 = (id > 31);
sclk->clkbit = BIT(id & 0x1f);
pr_debug("register clock \"%s\" ID: %d group: %d bits: %08x\n",
name, id, sclk->group1, sclk->clkbit);
ret = clk_hw_register(dev, &sclk->hw);
if (ret) {
kfree(sclk);
return ERR_PTR(ret);
}
return &sclk->hw;
}
static int nomadik_src_clk_show(struct seq_file *s, void *what)
{
int i;
u32 src_pcksr0 = readl(src_base + SRC_PCKSR0);
u32 src_pcksr1 = readl(src_base + SRC_PCKSR1);
u32 src_pckensr0 = readl(src_base + SRC_PCKENSR0);
u32 src_pckensr1 = readl(src_base + SRC_PCKENSR1);
seq_puts(s, "Clock: Boot: Now: Request: ASKED:\n");
for (i = 0; i < ARRAY_SIZE(src_clk_names); i++) {
u32 pcksrb = (i < 0x20) ? src_pcksr0_boot : src_pcksr1_boot;
u32 pcksr = (i < 0x20) ? src_pcksr0 : src_pcksr1;
u32 pckreq = (i < 0x20) ? src_pckensr0 : src_pckensr1;
u32 mask = BIT(i & 0x1f);
seq_printf(s, "%s %s %s %s\n",
src_clk_names[i],
(pcksrb & mask) ? "on " : "off",
(pcksr & mask) ? "on " : "off",
(pckreq & mask) ? "on " : "off");
}
return 0;
}
static int nomadik_src_clk_open(struct inode *inode, struct file *file)
{
return single_open(file, nomadik_src_clk_show, NULL);
}
static int __init nomadik_src_clk_init_debugfs(void)
{
if (!src_base)
return -ENODEV;
src_pcksr0_boot = readl(src_base + SRC_PCKSR0);
src_pcksr1_boot = readl(src_base + SRC_PCKSR1);
debugfs_create_file("nomadik-src-clk", S_IFREG | S_IRUGO,
NULL, NULL, &nomadik_src_clk_debugfs_ops);
return 0;
}
static void __init of_nomadik_pll_setup(struct device_node *np)
{
struct clk_hw *hw;
const char *clk_name = np->name;
const char *parent_name;
u32 pll_id;
if (!src_base)
nomadik_src_init();
if (of_property_read_u32(np, "pll-id", &pll_id)) {
pr_err("%s: PLL \"%s\" missing pll-id property\n",
__func__, clk_name);
return;
}
parent_name = of_clk_get_parent_name(np, 0);
hw = pll_clk_register(NULL, clk_name, parent_name, pll_id);
if (!IS_ERR(hw))
of_clk_add_hw_provider(np, of_clk_hw_simple_get, hw);
}
static void __init of_nomadik_hclk_setup(struct device_node *np)
{
struct clk_hw *hw;
const char *clk_name = np->name;
const char *parent_name;
if (!src_base)
nomadik_src_init();
parent_name = of_clk_get_parent_name(np, 0);
hw = clk_hw_register_divider(NULL, clk_name, parent_name,
0, src_base + SRC_CR,
13, 2,
CLK_DIVIDER_ONE_BASED | CLK_DIVIDER_ALLOW_ZERO,
&src_lock);
if (!IS_ERR(hw))
of_clk_add_hw_provider(np, of_clk_hw_simple_get, hw);
}
static void __init of_nomadik_src_clk_setup(struct device_node *np)
{
struct clk_hw *hw;
const char *clk_name = np->name;
const char *parent_name;
u32 clk_id;
if (!src_base)
nomadik_src_init();
if (of_property_read_u32(np, "clock-id", &clk_id)) {
pr_err("%s: SRC clock \"%s\" missing clock-id property\n",
__func__, clk_name);
return;
}
parent_name = of_clk_get_parent_name(np, 0);
hw = src_clk_register(NULL, clk_name, parent_name, clk_id);
if (!IS_ERR(hw))
of_clk_add_hw_provider(np, of_clk_hw_simple_get, hw);
}
