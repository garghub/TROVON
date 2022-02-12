static void cg_out(struct clockgen *cg, u32 val, u32 __iomem *reg)
{
if (cg->info.flags & CG_LITTLE_ENDIAN)
iowrite32(val, reg);
else
iowrite32be(val, reg);
}
static u32 cg_in(struct clockgen *cg, u32 __iomem *reg)
{
u32 val;
if (cg->info.flags & CG_LITTLE_ENDIAN)
val = ioread32(reg);
else
val = ioread32be(reg);
return val;
}
static void __init p2041_init_periph(struct clockgen *cg)
{
u32 reg;
reg = ioread32be(&cg->guts->rcwsr[7]);
if (reg & RCWSR7_FM1_CLK_SEL)
cg->fman[0] = cg->pll[CGA_PLL2].div[PLL_DIV2].clk;
else
cg->fman[0] = cg->pll[PLATFORM_PLL].div[PLL_DIV2].clk;
}
static void __init p4080_init_periph(struct clockgen *cg)
{
u32 reg;
reg = ioread32be(&cg->guts->rcwsr[7]);
if (reg & RCWSR7_FM1_CLK_SEL)
cg->fman[0] = cg->pll[CGA_PLL3].div[PLL_DIV2].clk;
else
cg->fman[0] = cg->pll[PLATFORM_PLL].div[PLL_DIV2].clk;
if (reg & RCWSR7_FM2_CLK_SEL)
cg->fman[1] = cg->pll[CGA_PLL3].div[PLL_DIV2].clk;
else
cg->fman[1] = cg->pll[PLATFORM_PLL].div[PLL_DIV2].clk;
}
static void __init p5020_init_periph(struct clockgen *cg)
{
u32 reg;
int div = PLL_DIV2;
reg = ioread32be(&cg->guts->rcwsr[7]);
if (reg & RCWSR7_HWA_ASYNC_DIV)
div = PLL_DIV4;
if (reg & RCWSR7_FM1_CLK_SEL)
cg->fman[0] = cg->pll[CGA_PLL2].div[div].clk;
else
cg->fman[0] = cg->pll[PLATFORM_PLL].div[PLL_DIV2].clk;
}
static void __init p5040_init_periph(struct clockgen *cg)
{
u32 reg;
int div = PLL_DIV2;
reg = ioread32be(&cg->guts->rcwsr[7]);
if (reg & RCWSR7_HWA_ASYNC_DIV)
div = PLL_DIV4;
if (reg & RCWSR7_FM1_CLK_SEL)
cg->fman[0] = cg->pll[CGA_PLL3].div[div].clk;
else
cg->fman[0] = cg->pll[PLATFORM_PLL].div[PLL_DIV2].clk;
if (reg & RCWSR7_FM2_CLK_SEL)
cg->fman[1] = cg->pll[CGA_PLL3].div[div].clk;
else
cg->fman[1] = cg->pll[PLATFORM_PLL].div[PLL_DIV2].clk;
}
static void __init t1023_init_periph(struct clockgen *cg)
{
cg->fman[0] = cg->hwaccel[1];
}
static void __init t1040_init_periph(struct clockgen *cg)
{
cg->fman[0] = cg->pll[PLATFORM_PLL].div[PLL_DIV1].clk;
}
static void __init t2080_init_periph(struct clockgen *cg)
{
cg->fman[0] = cg->hwaccel[0];
}
static void __init t4240_init_periph(struct clockgen *cg)
{
cg->fman[0] = cg->hwaccel[3];
cg->fman[1] = cg->hwaccel[4];
}
static int mux_set_parent(struct clk_hw *hw, u8 idx)
{
struct mux_hwclock *hwc = to_mux_hwclock(hw);
u32 clksel;
if (idx >= hwc->num_parents)
return -EINVAL;
clksel = hwc->parent_to_clksel[idx];
cg_out(hwc->cg, (clksel << CLKSEL_SHIFT) & CLKSEL_MASK, hwc->reg);
return 0;
}
static u8 mux_get_parent(struct clk_hw *hw)
{
struct mux_hwclock *hwc = to_mux_hwclock(hw);
u32 clksel;
s8 ret;
clksel = (cg_in(hwc->cg, hwc->reg) & CLKSEL_MASK) >> CLKSEL_SHIFT;
ret = hwc->clksel_to_parent[clksel];
if (ret < 0) {
pr_err("%s: mux at %p has bad clksel\n", __func__, hwc->reg);
return 0;
}
return ret;
}
static const struct clockgen_pll_div *get_pll_div(struct clockgen *cg,
struct mux_hwclock *hwc,
int idx)
{
int pll, div;
if (!(hwc->info->clksel[idx].flags & CLKSEL_VALID))
return NULL;
pll = hwc->info->clksel[idx].pll;
div = hwc->info->clksel[idx].div;
return &cg->pll[pll].div[div];
}
static struct clk * __init create_mux_common(struct clockgen *cg,
struct mux_hwclock *hwc,
const struct clk_ops *ops,
unsigned long min_rate,
unsigned long max_rate,
unsigned long pct80_rate,
const char *fmt, int idx)
{
struct clk_init_data init = {};
struct clk *clk;
const struct clockgen_pll_div *div;
const char *parent_names[NUM_MUX_PARENTS];
char name[32];
int i, j;
snprintf(name, sizeof(name), fmt, idx);
for (i = 0, j = 0; i < NUM_MUX_PARENTS; i++) {
unsigned long rate;
hwc->clksel_to_parent[i] = -1;
div = get_pll_div(cg, hwc, i);
if (!div)
continue;
rate = clk_get_rate(div->clk);
if (hwc->info->clksel[i].flags & CLKSEL_80PCT &&
rate > pct80_rate)
continue;
if (rate < min_rate)
continue;
if (rate > max_rate)
continue;
parent_names[j] = div->name;
hwc->parent_to_clksel[j] = i;
hwc->clksel_to_parent[i] = j;
j++;
}
init.name = name;
init.ops = ops;
init.parent_names = parent_names;
init.num_parents = hwc->num_parents = j;
init.flags = 0;
hwc->hw.init = &init;
hwc->cg = cg;
clk = clk_register(NULL, &hwc->hw);
if (IS_ERR(clk)) {
pr_err("%s: Couldn't register %s: %ld\n", __func__, name,
PTR_ERR(clk));
kfree(hwc);
return NULL;
}
return clk;
}
static struct clk * __init create_one_cmux(struct clockgen *cg, int idx)
{
struct mux_hwclock *hwc;
const struct clockgen_pll_div *div;
unsigned long plat_rate, min_rate;
u64 max_rate, pct80_rate;
u32 clksel;
hwc = kzalloc(sizeof(*hwc), GFP_KERNEL);
if (!hwc)
return NULL;
if (cg->info.flags & CG_VER3)
hwc->reg = cg->regs + 0x70000 + 0x20 * idx;
else
hwc->reg = cg->regs + 0x20 * idx;
hwc->info = cg->info.cmux_groups[cg->info.cmux_to_group[idx]];
clksel = (cg_in(cg, hwc->reg) & CLKSEL_MASK) >> CLKSEL_SHIFT;
div = get_pll_div(cg, hwc, clksel);
if (!div) {
kfree(hwc);
return NULL;
}
max_rate = clk_get_rate(div->clk);
pct80_rate = max_rate * 8;
do_div(pct80_rate, 10);
plat_rate = clk_get_rate(cg->pll[PLATFORM_PLL].div[PLL_DIV1].clk);
if (cg->info.flags & CG_CMUX_GE_PLAT)
min_rate = plat_rate;
else
min_rate = plat_rate / 2;
return create_mux_common(cg, hwc, &cmux_ops, min_rate, max_rate,
pct80_rate, "cg-cmux%d", idx);
}
static struct clk * __init create_one_hwaccel(struct clockgen *cg, int idx)
{
struct mux_hwclock *hwc;
hwc = kzalloc(sizeof(*hwc), GFP_KERNEL);
if (!hwc)
return NULL;
hwc->reg = cg->regs + 0x20 * idx + 0x10;
hwc->info = cg->info.hwaccel[idx];
return create_mux_common(cg, hwc, &hwaccel_ops, 0, ULONG_MAX, 0,
"cg-hwaccel%d", idx);
}
static void __init create_muxes(struct clockgen *cg)
{
int i;
for (i = 0; i < ARRAY_SIZE(cg->cmux); i++) {
if (cg->info.cmux_to_group[i] < 0)
break;
if (cg->info.cmux_to_group[i] >=
ARRAY_SIZE(cg->info.cmux_groups)) {
WARN_ON_ONCE(1);
continue;
}
cg->cmux[i] = create_one_cmux(cg, i);
}
for (i = 0; i < ARRAY_SIZE(cg->hwaccel); i++) {
if (!cg->info.hwaccel[i])
continue;
cg->hwaccel[i] = create_one_hwaccel(cg, i);
}
}
static void __init legacy_init_clockgen(struct device_node *np)
{
if (!clockgen.node)
clockgen_init(of_get_parent(np));
}
static void __init core_mux_init(struct device_node *np)
{
struct clk *clk;
struct resource res;
int idx, rc;
legacy_init_clockgen(np);
if (of_address_to_resource(np, 0, &res))
return;
idx = (res.start & 0xf0) >> 5;
clk = clockgen.cmux[idx];
rc = of_clk_add_provider(np, of_clk_src_simple_get, clk);
if (rc) {
pr_err("%s: Couldn't register clk provider for node %s: %d\n",
__func__, np->name, rc);
return;
}
}
static struct clk __init
*sysclk_from_fixed(struct device_node *node, const char *name)
{
u32 rate;
if (of_property_read_u32(node, "clock-frequency", &rate))
return ERR_PTR(-ENODEV);
return clk_register_fixed_rate(NULL, name, NULL, 0, rate);
}
static struct clk __init *input_clock(const char *name, struct clk *clk)
{
const char *input_name;
input_name = __clk_get_name(clk);
clk = clk_register_fixed_factor(NULL, name, input_name,
0, 1, 1);
if (IS_ERR(clk))
pr_err("%s: Couldn't register %s: %ld\n", __func__, name,
PTR_ERR(clk));
return clk;
}
static struct clk __init *input_clock_by_name(const char *name,
const char *dtname)
{
struct clk *clk;
clk = of_clk_get_by_name(clockgen.node, dtname);
if (IS_ERR(clk))
return clk;
return input_clock(name, clk);
}
static struct clk __init *input_clock_by_index(const char *name, int idx)
{
struct clk *clk;
clk = of_clk_get(clockgen.node, 0);
if (IS_ERR(clk))
return clk;
return input_clock(name, clk);
}
static struct clk * __init create_sysclk(const char *name)
{
struct device_node *sysclk;
struct clk *clk;
clk = sysclk_from_fixed(clockgen.node, name);
if (!IS_ERR(clk))
return clk;
clk = input_clock_by_name(name, "sysclk");
if (!IS_ERR(clk))
return clk;
clk = input_clock_by_index(name, 0);
if (!IS_ERR(clk))
return clk;
sysclk = of_get_child_by_name(clockgen.node, "sysclk");
if (sysclk) {
clk = sysclk_from_fixed(sysclk, name);
if (!IS_ERR(clk))
return clk;
}
pr_err("%s: No input sysclk\n", __func__);
return NULL;
}
static struct clk * __init create_coreclk(const char *name)
{
struct clk *clk;
clk = input_clock_by_name(name, "coreclk");
if (!IS_ERR(clk))
return clk;
if (WARN_ON(PTR_ERR(clk) == -EPROBE_DEFER))
return clk;
return NULL;
}
static void __init sysclk_init(struct device_node *node)
{
struct clk *clk;
legacy_init_clockgen(node);
clk = clockgen.sysclk;
if (clk)
of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
static void __init create_one_pll(struct clockgen *cg, int idx)
{
u32 __iomem *reg;
u32 mult;
struct clockgen_pll *pll = &cg->pll[idx];
const char *input = "cg-sysclk";
int i;
if (!(cg->info.pll_mask & (1 << idx)))
return;
if (cg->coreclk && idx != PLATFORM_PLL) {
if (IS_ERR(cg->coreclk))
return;
input = "cg-coreclk";
}
if (cg->info.flags & CG_VER3) {
switch (idx) {
case PLATFORM_PLL:
reg = cg->regs + 0x60080;
break;
case CGA_PLL1:
reg = cg->regs + 0x80;
break;
case CGA_PLL2:
reg = cg->regs + 0xa0;
break;
case CGB_PLL1:
reg = cg->regs + 0x10080;
break;
case CGB_PLL2:
reg = cg->regs + 0x100a0;
break;
default:
WARN_ONCE(1, "index %d\n", idx);
return;
}
} else {
if (idx == PLATFORM_PLL)
reg = cg->regs + 0xc00;
else
reg = cg->regs + 0x800 + 0x20 * (idx - 1);
}
mult = cg_in(cg, reg);
if (mult & PLL_KILL) {
pr_debug("%s(): pll %p disabled\n", __func__, reg);
return;
}
if ((cg->info.flags & CG_VER3) ||
((cg->info.flags & CG_PLL_8BIT) && idx != PLATFORM_PLL))
mult = (mult & GENMASK(8, 1)) >> 1;
else
mult = (mult & GENMASK(6, 1)) >> 1;
for (i = 0; i < ARRAY_SIZE(pll->div); i++) {
struct clk *clk;
snprintf(pll->div[i].name, sizeof(pll->div[i].name),
"cg-pll%d-div%d", idx, i + 1);
clk = clk_register_fixed_factor(NULL,
pll->div[i].name, input, 0, mult, i + 1);
if (IS_ERR(clk)) {
pr_err("%s: %s: register failed %ld\n",
__func__, pll->div[i].name, PTR_ERR(clk));
continue;
}
pll->div[i].clk = clk;
}
}
static void __init create_plls(struct clockgen *cg)
{
int i;
for (i = 0; i < ARRAY_SIZE(cg->pll); i++)
create_one_pll(cg, i);
}
static void __init legacy_pll_init(struct device_node *np, int idx)
{
struct clockgen_pll *pll;
struct clk_onecell_data *onecell_data;
struct clk **subclks;
int count, rc;
legacy_init_clockgen(np);
pll = &clockgen.pll[idx];
count = of_property_count_strings(np, "clock-output-names");
BUILD_BUG_ON(ARRAY_SIZE(pll->div) < 4);
subclks = kcalloc(4, sizeof(struct clk *), GFP_KERNEL);
if (!subclks)
return;
onecell_data = kmalloc(sizeof(*onecell_data), GFP_KERNEL);
if (!onecell_data)
goto err_clks;
if (count <= 3) {
subclks[0] = pll->div[0].clk;
subclks[1] = pll->div[1].clk;
subclks[2] = pll->div[3].clk;
} else {
subclks[0] = pll->div[0].clk;
subclks[1] = pll->div[1].clk;
subclks[2] = pll->div[2].clk;
subclks[3] = pll->div[3].clk;
}
onecell_data->clks = subclks;
onecell_data->clk_num = count;
rc = of_clk_add_provider(np, of_clk_src_onecell_get, onecell_data);
if (rc) {
pr_err("%s: Couldn't register clk provider for node %s: %d\n",
__func__, np->name, rc);
goto err_cell;
}
return;
err_cell:
kfree(onecell_data);
err_clks:
kfree(subclks);
}
static void __init pltfrm_pll_init(struct device_node *np)
{
legacy_pll_init(np, PLATFORM_PLL);
}
static void __init core_pll_init(struct device_node *np)
{
struct resource res;
int idx;
if (of_address_to_resource(np, 0, &res))
return;
if ((res.start & 0xfff) == 0xc00) {
pltfrm_pll_init(np);
} else {
idx = (res.start & 0xf0) >> 5;
legacy_pll_init(np, CGA_PLL1 + idx);
}
}
static struct clk *clockgen_clk_get(struct of_phandle_args *clkspec, void *data)
{
struct clockgen *cg = data;
struct clk *clk;
struct clockgen_pll *pll;
u32 type, idx;
if (clkspec->args_count < 2) {
pr_err("%s: insufficient phandle args\n", __func__);
return ERR_PTR(-EINVAL);
}
type = clkspec->args[0];
idx = clkspec->args[1];
switch (type) {
case 0:
if (idx != 0)
goto bad_args;
clk = cg->sysclk;
break;
case 1:
if (idx >= ARRAY_SIZE(cg->cmux))
goto bad_args;
clk = cg->cmux[idx];
break;
case 2:
if (idx >= ARRAY_SIZE(cg->hwaccel))
goto bad_args;
clk = cg->hwaccel[idx];
break;
case 3:
if (idx >= ARRAY_SIZE(cg->fman))
goto bad_args;
clk = cg->fman[idx];
break;
case 4:
pll = &cg->pll[PLATFORM_PLL];
if (idx >= ARRAY_SIZE(pll->div))
goto bad_args;
clk = pll->div[idx].clk;
break;
case 5:
if (idx != 0)
goto bad_args;
clk = cg->coreclk;
if (IS_ERR(clk))
clk = NULL;
break;
default:
goto bad_args;
}
if (!clk)
return ERR_PTR(-ENOENT);
return clk;
bad_args:
pr_err("%s: Bad phandle args %u %u\n", __func__, type, idx);
return ERR_PTR(-EINVAL);
}
static bool __init has_erratum_a4510(void)
{
u32 svr = mfspr(SPRN_SVR);
int i;
svr &= ~SVR_SECURITY;
for (i = 0; i < ARRAY_SIZE(a4510_svrs); i++) {
if (svr == a4510_svrs[i])
return true;
}
return false;
}
static bool __init has_erratum_a4510(void)
{
return false;
}
static void __init clockgen_init(struct device_node *np)
{
int i, ret;
bool is_old_ls1021a = false;
if (clockgen.node)
return;
clockgen.node = np;
clockgen.regs = of_iomap(np, 0);
if (!clockgen.regs &&
of_device_is_compatible(of_root, "fsl,ls1021a")) {
clockgen.regs = ioremap(0x1ee1000, 0x1000);
is_old_ls1021a = true;
}
if (!clockgen.regs) {
pr_err("%s(): %s: of_iomap() failed\n", __func__, np->name);
return;
}
for (i = 0; i < ARRAY_SIZE(chipinfo); i++) {
if (of_device_is_compatible(np, chipinfo[i].compat))
break;
if (is_old_ls1021a &&
!strcmp(chipinfo[i].compat, "fsl,ls1021a-clockgen"))
break;
}
if (i == ARRAY_SIZE(chipinfo)) {
pr_err("%s: unknown clockgen node %s\n", __func__,
np->full_name);
goto err;
}
clockgen.info = chipinfo[i];
if (clockgen.info.guts_compat) {
struct device_node *guts;
guts = of_find_compatible_node(NULL, NULL,
clockgen.info.guts_compat);
if (guts) {
clockgen.guts = of_iomap(guts, 0);
if (!clockgen.guts) {
pr_err("%s: Couldn't map %s regs\n", __func__,
guts->full_name);
}
}
}
if (has_erratum_a4510())
clockgen.info.flags |= CG_CMUX_GE_PLAT;
clockgen.sysclk = create_sysclk("cg-sysclk");
clockgen.coreclk = create_coreclk("cg-coreclk");
create_plls(&clockgen);
create_muxes(&clockgen);
if (clockgen.info.init_periph)
clockgen.info.init_periph(&clockgen);
ret = of_clk_add_provider(np, clockgen_clk_get, &clockgen);
if (ret) {
pr_err("%s: Couldn't register clk provider for node %s: %d\n",
__func__, np->name, ret);
}
return;
err:
iounmap(clockgen.regs);
clockgen.regs = NULL;
}
