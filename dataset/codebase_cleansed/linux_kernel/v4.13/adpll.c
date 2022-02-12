static const char *ti_adpll_clk_get_name(struct ti_adpll_data *d,
int output_index,
const char *postfix)
{
const char *name;
int err;
if (output_index >= 0) {
err = of_property_read_string_index(d->np,
"clock-output-names",
output_index,
&name);
if (err)
return NULL;
} else {
const char *base_name = "adpll";
char *buf;
buf = devm_kzalloc(d->dev, 8 + 1 + strlen(base_name) + 1 +
strlen(postfix), GFP_KERNEL);
if (!buf)
return NULL;
sprintf(buf, "%08lx.%s.%s", d->pa, base_name, postfix);
name = buf;
}
return name;
}
static int ti_adpll_setup_clock(struct ti_adpll_data *d, struct clk *clock,
int index, int output_index, const char *name,
void (*unregister)(struct clk *clk))
{
struct clk_lookup *cl;
const char *postfix = NULL;
char con_id[ADPLL_MAX_CON_ID];
d->clocks[index].clk = clock;
d->clocks[index].unregister = unregister;
postfix = strrchr(name, '.');
if (strlen(postfix) > 1) {
if (strlen(postfix) > ADPLL_MAX_CON_ID)
dev_warn(d->dev, "clock %s con_id lookup may fail\n",
name);
snprintf(con_id, 16, "pll%03lx%s", d->pa & 0xfff, postfix + 1);
cl = clkdev_create(clock, con_id, NULL);
if (!cl)
return -ENOMEM;
d->clocks[index].cl = cl;
} else {
dev_warn(d->dev, "no con_id for clock %s\n", name);
}
if (output_index < 0)
return 0;
d->outputs.clks[output_index] = clock;
d->outputs.clk_num++;
return 0;
}
static int ti_adpll_init_divider(struct ti_adpll_data *d,
enum ti_adpll_clocks index,
int output_index, char *name,
struct clk *parent_clock,
void __iomem *reg,
u8 shift, u8 width,
u8 clk_divider_flags)
{
const char *child_name;
const char *parent_name;
struct clk *clock;
child_name = ti_adpll_clk_get_name(d, output_index, name);
if (!child_name)
return -EINVAL;
parent_name = __clk_get_name(parent_clock);
clock = clk_register_divider(d->dev, child_name, parent_name, 0,
reg, shift, width, clk_divider_flags,
&d->lock);
if (IS_ERR(clock)) {
dev_err(d->dev, "failed to register divider %s: %li\n",
name, PTR_ERR(clock));
return PTR_ERR(clock);
}
return ti_adpll_setup_clock(d, clock, index, output_index, child_name,
clk_unregister_divider);
}
static int ti_adpll_init_mux(struct ti_adpll_data *d,
enum ti_adpll_clocks index,
char *name, struct clk *clk0,
struct clk *clk1,
void __iomem *reg,
u8 shift)
{
const char *child_name;
const char *parents[2];
struct clk *clock;
child_name = ti_adpll_clk_get_name(d, -ENODEV, name);
if (!child_name)
return -ENOMEM;
parents[0] = __clk_get_name(clk0);
parents[1] = __clk_get_name(clk1);
clock = clk_register_mux(d->dev, child_name, parents, 2, 0,
reg, shift, 1, 0, &d->lock);
if (IS_ERR(clock)) {
dev_err(d->dev, "failed to register mux %s: %li\n",
name, PTR_ERR(clock));
return PTR_ERR(clock);
}
return ti_adpll_setup_clock(d, clock, index, -ENODEV, child_name,
clk_unregister_mux);
}
static int ti_adpll_init_gate(struct ti_adpll_data *d,
enum ti_adpll_clocks index,
int output_index, char *name,
struct clk *parent_clock,
void __iomem *reg,
u8 bit_idx,
u8 clk_gate_flags)
{
const char *child_name;
const char *parent_name;
struct clk *clock;
child_name = ti_adpll_clk_get_name(d, output_index, name);
if (!child_name)
return -EINVAL;
parent_name = __clk_get_name(parent_clock);
clock = clk_register_gate(d->dev, child_name, parent_name, 0,
reg, bit_idx, clk_gate_flags,
&d->lock);
if (IS_ERR(clock)) {
dev_err(d->dev, "failed to register gate %s: %li\n",
name, PTR_ERR(clock));
return PTR_ERR(clock);
}
return ti_adpll_setup_clock(d, clock, index, output_index, child_name,
clk_unregister_gate);
}
static int ti_adpll_init_fixed_factor(struct ti_adpll_data *d,
enum ti_adpll_clocks index,
char *name,
struct clk *parent_clock,
unsigned int mult,
unsigned int div)
{
const char *child_name;
const char *parent_name;
struct clk *clock;
child_name = ti_adpll_clk_get_name(d, -ENODEV, name);
if (!child_name)
return -ENOMEM;
parent_name = __clk_get_name(parent_clock);
clock = clk_register_fixed_factor(d->dev, child_name, parent_name,
0, mult, div);
if (IS_ERR(clock))
return PTR_ERR(clock);
return ti_adpll_setup_clock(d, clock, index, -ENODEV, child_name,
clk_unregister);
}
static void ti_adpll_set_idle_bypass(struct ti_adpll_data *d)
{
unsigned long flags;
u32 v;
spin_lock_irqsave(&d->lock, flags);
v = readl_relaxed(d->regs + ADPLL_CLKCTRL_OFFSET);
v |= BIT(ADPLL_CLKCTRL_IDLE);
writel_relaxed(v, d->regs + ADPLL_CLKCTRL_OFFSET);
spin_unlock_irqrestore(&d->lock, flags);
}
static void ti_adpll_clear_idle_bypass(struct ti_adpll_data *d)
{
unsigned long flags;
u32 v;
spin_lock_irqsave(&d->lock, flags);
v = readl_relaxed(d->regs + ADPLL_CLKCTRL_OFFSET);
v &= ~BIT(ADPLL_CLKCTRL_IDLE);
writel_relaxed(v, d->regs + ADPLL_CLKCTRL_OFFSET);
spin_unlock_irqrestore(&d->lock, flags);
}
static bool ti_adpll_clock_is_bypass(struct ti_adpll_data *d)
{
u32 v;
v = readl_relaxed(d->regs + ADPLL_STATUS_OFFSET);
return v & BIT(ADPLL_STATUS_BYPASS);
}
static bool ti_adpll_is_locked(struct ti_adpll_data *d)
{
u32 v = readl_relaxed(d->regs + ADPLL_STATUS_OFFSET);
return (v & ADPLL_STATUS_PREPARED_MASK) == ADPLL_STATUS_PREPARED_MASK;
}
static int ti_adpll_wait_lock(struct ti_adpll_data *d)
{
int retries = ADPLL_MAX_RETRIES;
do {
if (ti_adpll_is_locked(d))
return 0;
usleep_range(200, 300);
} while (retries--);
dev_err(d->dev, "pll failed to lock\n");
return -ETIMEDOUT;
}
static int ti_adpll_prepare(struct clk_hw *hw)
{
struct ti_adpll_dco_data *dco = to_dco(hw);
struct ti_adpll_data *d = to_adpll(dco);
ti_adpll_clear_idle_bypass(d);
ti_adpll_wait_lock(d);
return 0;
}
static void ti_adpll_unprepare(struct clk_hw *hw)
{
struct ti_adpll_dco_data *dco = to_dco(hw);
struct ti_adpll_data *d = to_adpll(dco);
ti_adpll_set_idle_bypass(d);
}
static int ti_adpll_is_prepared(struct clk_hw *hw)
{
struct ti_adpll_dco_data *dco = to_dco(hw);
struct ti_adpll_data *d = to_adpll(dco);
return ti_adpll_is_locked(d);
}
static unsigned long ti_adpll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ti_adpll_dco_data *dco = to_dco(hw);
struct ti_adpll_data *d = to_adpll(dco);
u32 frac_m, divider, v;
u64 rate;
unsigned long flags;
if (ti_adpll_clock_is_bypass(d))
return 0;
spin_lock_irqsave(&d->lock, flags);
frac_m = readl_relaxed(d->regs + ADPLL_FRACDIV_OFFSET);
frac_m &= ADPLL_FRACDIV_FRACTIONALM_MASK;
rate = (u64)readw_relaxed(d->regs + ADPLL_MN2DIV_OFFSET) << 18;
rate += frac_m;
rate *= parent_rate;
divider = (readw_relaxed(d->regs + ADPLL_M2NDIV_OFFSET) + 1) << 18;
spin_unlock_irqrestore(&d->lock, flags);
do_div(rate, divider);
if (d->c->is_type_s) {
v = readl_relaxed(d->regs + ADPLL_CLKCTRL_OFFSET);
if (v & BIT(ADPLL_CLKCTRL_REGM4XEN_ADPLL_S))
rate *= 4;
rate *= 2;
}
return rate;
}
static u8 ti_adpll_get_parent(struct clk_hw *hw)
{
return 0;
}
static int ti_adpll_init_dco(struct ti_adpll_data *d)
{
struct clk_init_data init;
struct clk *clock;
const char *postfix;
int width, err;
d->outputs.clks = devm_kzalloc(d->dev, sizeof(struct clk *) *
MAX_ADPLL_OUTPUTS,
GFP_KERNEL);
if (!d->outputs.clks)
return -ENOMEM;
if (d->c->output_index < 0)
postfix = "dco";
else
postfix = NULL;
init.name = ti_adpll_clk_get_name(d, d->c->output_index, postfix);
if (!init.name)
return -EINVAL;
init.parent_names = d->parent_names;
init.num_parents = d->c->nr_max_inputs;
init.ops = &ti_adpll_ops;
init.flags = CLK_GET_RATE_NOCACHE;
d->dco.hw.init = &init;
if (d->c->is_type_s)
width = 5;
else
width = 4;
err = ti_adpll_init_divider(d, TI_ADPLL_N2, -ENODEV, "n2",
d->parent_clocks[TI_ADPLL_CLKINP],
d->regs + ADPLL_MN2DIV_OFFSET,
ADPLL_MN2DIV_N2, width, 0);
if (err)
return err;
clock = devm_clk_register(d->dev, &d->dco.hw);
if (IS_ERR(clock))
return PTR_ERR(clock);
return ti_adpll_setup_clock(d, clock, TI_ADPLL_DCO, d->c->output_index,
init.name, NULL);
}
static int ti_adpll_clkout_enable(struct clk_hw *hw)
{
struct ti_adpll_clkout_data *co = to_clkout(hw);
struct clk_hw *gate_hw = &co->gate.hw;
__clk_hw_set_clk(gate_hw, hw);
return clk_gate_ops.enable(gate_hw);
}
static void ti_adpll_clkout_disable(struct clk_hw *hw)
{
struct ti_adpll_clkout_data *co = to_clkout(hw);
struct clk_hw *gate_hw = &co->gate.hw;
__clk_hw_set_clk(gate_hw, hw);
clk_gate_ops.disable(gate_hw);
}
static int ti_adpll_clkout_is_enabled(struct clk_hw *hw)
{
struct ti_adpll_clkout_data *co = to_clkout(hw);
struct clk_hw *gate_hw = &co->gate.hw;
__clk_hw_set_clk(gate_hw, hw);
return clk_gate_ops.is_enabled(gate_hw);
}
static u8 ti_adpll_clkout_get_parent(struct clk_hw *hw)
{
struct ti_adpll_clkout_data *co = to_clkout(hw);
struct ti_adpll_data *d = co->adpll;
return ti_adpll_clock_is_bypass(d);
}
static int ti_adpll_init_clkout(struct ti_adpll_data *d,
enum ti_adpll_clocks index,
int output_index, int gate_bit,
char *name, struct clk *clk0,
struct clk *clk1)
{
struct ti_adpll_clkout_data *co;
struct clk_init_data init;
struct clk_ops *ops;
const char *parent_names[2];
const char *child_name;
struct clk *clock;
int err;
co = devm_kzalloc(d->dev, sizeof(*co), GFP_KERNEL);
if (!co)
return -ENOMEM;
co->adpll = d;
err = of_property_read_string_index(d->np,
"clock-output-names",
output_index,
&child_name);
if (err)
return err;
ops = devm_kzalloc(d->dev, sizeof(*ops), GFP_KERNEL);
if (!ops)
return -ENOMEM;
init.name = child_name;
init.ops = ops;
init.flags = CLK_IS_BASIC;
co->hw.init = &init;
parent_names[0] = __clk_get_name(clk0);
parent_names[1] = __clk_get_name(clk1);
init.parent_names = parent_names;
init.num_parents = 2;
ops->get_parent = ti_adpll_clkout_get_parent;
ops->determine_rate = __clk_mux_determine_rate;
if (gate_bit) {
co->gate.lock = &d->lock;
co->gate.reg = d->regs + ADPLL_CLKCTRL_OFFSET;
co->gate.bit_idx = gate_bit;
ops->enable = ti_adpll_clkout_enable;
ops->disable = ti_adpll_clkout_disable;
ops->is_enabled = ti_adpll_clkout_is_enabled;
}
clock = devm_clk_register(d->dev, &co->hw);
if (IS_ERR(clock)) {
dev_err(d->dev, "failed to register output %s: %li\n",
name, PTR_ERR(clock));
return PTR_ERR(clock);
}
return ti_adpll_setup_clock(d, clock, index, output_index, child_name,
NULL);
}
static int ti_adpll_init_children_adpll_s(struct ti_adpll_data *d)
{
int err;
if (!d->c->is_type_s)
return 0;
err = ti_adpll_init_mux(d, TI_ADPLL_BYPASS, "bypass",
d->clocks[TI_ADPLL_N2].clk,
d->parent_clocks[TI_ADPLL_CLKINPULOW],
d->regs + ADPLL_CLKCTRL_OFFSET,
ADPLL_CLKCTRL_ULOWCLKEN);
if (err)
return err;
err = ti_adpll_init_divider(d, TI_ADPLL_M2, -ENODEV, "m2",
d->clocks[TI_ADPLL_DCO].clk,
d->regs + ADPLL_M2NDIV_OFFSET,
ADPLL_M2NDIV_M2,
ADPLL_M2NDIV_M2_ADPLL_S_WIDTH,
CLK_DIVIDER_ONE_BASED);
if (err)
return err;
err = ti_adpll_init_fixed_factor(d, TI_ADPLL_DIV2, "div2",
d->clocks[TI_ADPLL_M2].clk,
1, 2);
if (err)
return err;
err = ti_adpll_init_clkout(d, TI_ADPLL_CLKOUT, TI_ADPLL_S_CLKOUT,
ADPLL_CLKCTRL_CLKOUTEN, "clkout",
d->clocks[TI_ADPLL_DIV2].clk,
d->clocks[TI_ADPLL_BYPASS].clk);
if (err)
return err;
err = ti_adpll_init_clkout(d, TI_ADPLL_CLKOUT2, TI_ADPLL_S_CLKOUTX2, 0,
"clkout2", d->clocks[TI_ADPLL_M2].clk,
d->clocks[TI_ADPLL_BYPASS].clk);
if (err)
return err;
if (d->parent_clocks[TI_ADPLL_CLKINPHIF]) {
err = ti_adpll_init_mux(d, TI_ADPLL_HIF, "hif",
d->clocks[TI_ADPLL_DCO].clk,
d->parent_clocks[TI_ADPLL_CLKINPHIF],
d->regs + ADPLL_CLKCTRL_OFFSET,
ADPLL_CLKINPHIFSEL_ADPLL_S);
if (err)
return err;
}
err = ti_adpll_init_divider(d, TI_ADPLL_M3, TI_ADPLL_S_CLKOUTHIF, "m3",
d->clocks[TI_ADPLL_HIF].clk,
d->regs + ADPLL_M3DIV_OFFSET,
ADPLL_M3DIV_M3,
ADPLL_M3DIV_M3_WIDTH,
CLK_DIVIDER_ONE_BASED);
if (err)
return err;
return 0;
}
static int ti_adpll_init_children_adpll_lj(struct ti_adpll_data *d)
{
int err;
if (d->c->is_type_s)
return 0;
err = ti_adpll_init_gate(d, TI_ADPLL_DCO_GATE, TI_ADPLL_LJ_CLKDCOLDO,
"clkdcoldo", d->clocks[TI_ADPLL_DCO].clk,
d->regs + ADPLL_CLKCTRL_OFFSET,
ADPLL_CLKCTRL_CLKDCOLDOEN, 0);
if (err)
return err;
err = ti_adpll_init_divider(d, TI_ADPLL_M2, -ENODEV,
"m2", d->clocks[TI_ADPLL_DCO].clk,
d->regs + ADPLL_M2NDIV_OFFSET,
ADPLL_M2NDIV_M2,
ADPLL_M2NDIV_M2_ADPLL_LJ_WIDTH,
CLK_DIVIDER_ONE_BASED);
if (err)
return err;
err = ti_adpll_init_gate(d, TI_ADPLL_M2_GATE, TI_ADPLL_LJ_CLKOUTLDO,
"clkoutldo", d->clocks[TI_ADPLL_M2].clk,
d->regs + ADPLL_CLKCTRL_OFFSET,
ADPLL_CLKCTRL_CLKOUTLDOEN_ADPLL_LJ,
0);
if (err)
return err;
err = ti_adpll_init_mux(d, TI_ADPLL_BYPASS, "bypass",
d->clocks[TI_ADPLL_N2].clk,
d->parent_clocks[TI_ADPLL_CLKINPULOW],
d->regs + ADPLL_CLKCTRL_OFFSET,
ADPLL_CLKCTRL_ULOWCLKEN);
if (err)
return err;
err = ti_adpll_init_clkout(d, TI_ADPLL_CLKOUT, TI_ADPLL_S_CLKOUT,
ADPLL_CLKCTRL_CLKOUTEN, "clkout",
d->clocks[TI_ADPLL_M2].clk,
d->clocks[TI_ADPLL_BYPASS].clk);
if (err)
return err;
return 0;
}
static void ti_adpll_free_resources(struct ti_adpll_data *d)
{
int i;
for (i = TI_ADPLL_M3; i >= 0; i--) {
struct ti_adpll_clock *ac = &d->clocks[i];
if (!ac || IS_ERR_OR_NULL(ac->clk))
continue;
if (ac->cl)
clkdev_drop(ac->cl);
if (ac->unregister)
ac->unregister(ac->clk);
}
}
static void ti_adpll_unlock_all(void __iomem *reg)
{
u32 v;
v = readl_relaxed(reg);
if (v == ADPLL_PLLSS_MMR_LOCK_ENABLED)
writel_relaxed(ADPLL_PLLSS_MMR_UNLOCK_MAGIC, reg);
}
static int ti_adpll_init_registers(struct ti_adpll_data *d)
{
int register_offset = 0;
if (d->c->is_type_s) {
register_offset = 8;
ti_adpll_unlock_all(d->iobase + ADPLL_PLLSS_MMR_LOCK_OFFSET);
}
d->regs = d->iobase + register_offset + ADPLL_PWRCTRL_OFFSET;
return 0;
}
static int ti_adpll_init_inputs(struct ti_adpll_data *d)
{
const char *error = "need at least %i inputs";
struct clk *clock;
int nr_inputs;
nr_inputs = of_clk_get_parent_count(d->np);
if (nr_inputs < d->c->nr_max_inputs) {
dev_err(d->dev, error, nr_inputs);
return -EINVAL;
}
of_clk_parent_fill(d->np, d->parent_names, nr_inputs);
clock = devm_clk_get(d->dev, d->parent_names[0]);
if (IS_ERR(clock)) {
dev_err(d->dev, "could not get clkinp\n");
return PTR_ERR(clock);
}
d->parent_clocks[TI_ADPLL_CLKINP] = clock;
clock = devm_clk_get(d->dev, d->parent_names[1]);
if (IS_ERR(clock)) {
dev_err(d->dev, "could not get clkinpulow clock\n");
return PTR_ERR(clock);
}
d->parent_clocks[TI_ADPLL_CLKINPULOW] = clock;
if (d->c->is_type_s) {
clock = devm_clk_get(d->dev, d->parent_names[2]);
if (IS_ERR(clock)) {
dev_err(d->dev, "could not get clkinphif clock\n");
return PTR_ERR(clock);
}
d->parent_clocks[TI_ADPLL_CLKINPHIF] = clock;
}
return 0;
}
static int ti_adpll_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct device *dev = &pdev->dev;
const struct of_device_id *match;
const struct ti_adpll_platform_data *pdata;
struct ti_adpll_data *d;
struct resource *res;
int err;
match = of_match_device(ti_adpll_match, dev);
if (match)
pdata = match->data;
else
return -ENODEV;
d = devm_kzalloc(dev, sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->dev = dev;
d->np = node;
d->c = pdata;
dev_set_drvdata(d->dev, d);
spin_lock_init(&d->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
d->pa = res->start;
d->iobase = devm_ioremap_resource(dev, res);
if (IS_ERR(d->iobase)) {
dev_err(dev, "could not get IO base: %li\n",
PTR_ERR(d->iobase));
return PTR_ERR(d->iobase);
}
err = ti_adpll_init_registers(d);
if (err)
return err;
err = ti_adpll_init_inputs(d);
if (err)
return err;
d->clocks = devm_kzalloc(d->dev, sizeof(struct ti_adpll_clock) *
TI_ADPLL_NR_CLOCKS,
GFP_KERNEL);
if (!d->clocks)
return -ENOMEM;
err = ti_adpll_init_dco(d);
if (err) {
dev_err(dev, "could not register dco: %i\n", err);
goto free;
}
err = ti_adpll_init_children_adpll_s(d);
if (err)
goto free;
err = ti_adpll_init_children_adpll_lj(d);
if (err)
goto free;
err = of_clk_add_provider(d->np, of_clk_src_onecell_get, &d->outputs);
if (err)
goto free;
return 0;
free:
WARN_ON(1);
ti_adpll_free_resources(d);
return err;
}
static int ti_adpll_remove(struct platform_device *pdev)
{
struct ti_adpll_data *d = dev_get_drvdata(&pdev->dev);
ti_adpll_free_resources(d);
return 0;
}
static int __init ti_adpll_init(void)
{
return platform_driver_register(&ti_adpll_driver);
}
static void __exit ti_adpll_exit(void)
{
platform_driver_unregister(&ti_adpll_driver);
}
