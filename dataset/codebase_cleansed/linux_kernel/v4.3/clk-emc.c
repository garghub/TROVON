static unsigned long emc_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct tegra_clk_emc *tegra;
u32 val, div;
tegra = container_of(hw, struct tegra_clk_emc, hw);
parent_rate = clk_hw_get_rate(clk_hw_get_parent(hw));
val = readl(tegra->clk_regs + CLK_SOURCE_EMC);
div = val & CLK_SOURCE_EMC_EMC_2X_CLK_DIVISOR_MASK;
return parent_rate / (div + 2) * 2;
}
static int emc_determine_rate(struct clk_hw *hw, struct clk_rate_request *req)
{
struct tegra_clk_emc *tegra;
u8 ram_code = tegra_read_ram_code();
struct emc_timing *timing = NULL;
int i;
tegra = container_of(hw, struct tegra_clk_emc, hw);
for (i = 0; i < tegra->num_timings; i++) {
if (tegra->timings[i].ram_code != ram_code)
continue;
timing = tegra->timings + i;
if (timing->rate > req->max_rate) {
i = min(i, 1);
req->rate = tegra->timings[i - 1].rate;
return 0;
}
if (timing->rate < req->min_rate)
continue;
if (timing->rate >= req->rate) {
req->rate = timing->rate;
return 0;
}
}
if (timing) {
req->rate = timing->rate;
return 0;
}
req->rate = clk_hw_get_rate(hw);
return 0;
}
static u8 emc_get_parent(struct clk_hw *hw)
{
struct tegra_clk_emc *tegra;
u32 val;
tegra = container_of(hw, struct tegra_clk_emc, hw);
val = readl(tegra->clk_regs + CLK_SOURCE_EMC);
return (val >> CLK_SOURCE_EMC_EMC_2X_CLK_SRC_SHIFT)
& CLK_SOURCE_EMC_EMC_2X_CLK_SRC_MASK;
}
static struct tegra_emc *emc_ensure_emc_driver(struct tegra_clk_emc *tegra)
{
struct platform_device *pdev;
if (tegra->emc)
return tegra->emc;
if (!tegra->emc_node)
return NULL;
pdev = of_find_device_by_node(tegra->emc_node);
if (!pdev) {
pr_err("%s: could not get external memory controller\n",
__func__);
return NULL;
}
of_node_put(tegra->emc_node);
tegra->emc_node = NULL;
tegra->emc = platform_get_drvdata(pdev);
if (!tegra->emc) {
pr_err("%s: cannot find EMC driver\n", __func__);
return NULL;
}
return tegra->emc;
}
static int emc_set_timing(struct tegra_clk_emc *tegra,
struct emc_timing *timing)
{
int err;
u8 div;
u32 car_value;
unsigned long flags = 0;
struct tegra_emc *emc = emc_ensure_emc_driver(tegra);
if (!emc)
return -ENOENT;
pr_debug("going to rate %ld prate %ld p %s\n", timing->rate,
timing->parent_rate, __clk_get_name(timing->parent));
if (emc_get_parent(&tegra->hw) == timing->parent_index &&
clk_get_rate(timing->parent) != timing->parent_rate) {
BUG();
return -EINVAL;
}
tegra->changing_timing = true;
err = clk_set_rate(timing->parent, timing->parent_rate);
if (err) {
pr_err("cannot change parent %s rate to %ld: %d\n",
__clk_get_name(timing->parent), timing->parent_rate,
err);
return err;
}
err = clk_prepare_enable(timing->parent);
if (err) {
pr_err("cannot enable parent clock: %d\n", err);
return err;
}
div = timing->parent_rate / (timing->rate / 2) - 2;
err = tegra_emc_prepare_timing_change(emc, timing->rate);
if (err)
return err;
spin_lock_irqsave(tegra->lock, flags);
car_value = readl(tegra->clk_regs + CLK_SOURCE_EMC);
car_value &= ~CLK_SOURCE_EMC_EMC_2X_CLK_SRC(~0);
car_value |= CLK_SOURCE_EMC_EMC_2X_CLK_SRC(timing->parent_index);
car_value &= ~CLK_SOURCE_EMC_EMC_2X_CLK_DIVISOR(~0);
car_value |= CLK_SOURCE_EMC_EMC_2X_CLK_DIVISOR(div);
writel(car_value, tegra->clk_regs + CLK_SOURCE_EMC);
spin_unlock_irqrestore(tegra->lock, flags);
tegra_emc_complete_timing_change(emc, timing->rate);
clk_hw_reparent(&tegra->hw, __clk_get_hw(timing->parent));
clk_disable_unprepare(tegra->prev_parent);
tegra->prev_parent = timing->parent;
tegra->changing_timing = false;
return 0;
}
static struct emc_timing *get_backup_timing(struct tegra_clk_emc *tegra,
int timing_index)
{
int i;
u32 ram_code = tegra_read_ram_code();
struct emc_timing *timing;
for (i = timing_index+1; i < tegra->num_timings; i++) {
timing = tegra->timings + i;
if (timing->ram_code != ram_code)
continue;
if (emc_parent_clk_sources[timing->parent_index] !=
emc_parent_clk_sources[
tegra->timings[timing_index].parent_index])
return timing;
}
for (i = timing_index-1; i >= 0; --i) {
timing = tegra->timings + i;
if (timing->ram_code != ram_code)
continue;
if (emc_parent_clk_sources[timing->parent_index] !=
emc_parent_clk_sources[
tegra->timings[timing_index].parent_index])
return timing;
}
return NULL;
}
static int emc_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct tegra_clk_emc *tegra;
struct emc_timing *timing = NULL;
int i, err;
u32 ram_code = tegra_read_ram_code();
tegra = container_of(hw, struct tegra_clk_emc, hw);
if (clk_hw_get_rate(hw) == rate)
return 0;
if (tegra->changing_timing)
return 0;
for (i = 0; i < tegra->num_timings; i++) {
if (tegra->timings[i].rate == rate &&
tegra->timings[i].ram_code == ram_code) {
timing = tegra->timings + i;
break;
}
}
if (!timing) {
pr_err("cannot switch to rate %ld without emc table\n", rate);
return -EINVAL;
}
if (emc_parent_clk_sources[emc_get_parent(hw)] ==
emc_parent_clk_sources[timing->parent_index] &&
clk_get_rate(timing->parent) != timing->parent_rate) {
struct emc_timing *backup_timing;
backup_timing = get_backup_timing(tegra, i);
if (!backup_timing) {
pr_err("cannot find backup timing\n");
return -EINVAL;
}
pr_debug("using %ld as backup rate when going to %ld\n",
backup_timing->rate, rate);
err = emc_set_timing(tegra, backup_timing);
if (err) {
pr_err("cannot set backup timing: %d\n", err);
return err;
}
}
return emc_set_timing(tegra, timing);
}
static int load_one_timing_from_dt(struct tegra_clk_emc *tegra,
struct emc_timing *timing,
struct device_node *node)
{
int err, i;
u32 tmp;
err = of_property_read_u32(node, "clock-frequency", &tmp);
if (err) {
pr_err("timing %s: failed to read rate\n", node->full_name);
return err;
}
timing->rate = tmp;
err = of_property_read_u32(node, "nvidia,parent-clock-frequency", &tmp);
if (err) {
pr_err("timing %s: failed to read parent rate\n",
node->full_name);
return err;
}
timing->parent_rate = tmp;
timing->parent = of_clk_get_by_name(node, "emc-parent");
if (IS_ERR(timing->parent)) {
pr_err("timing %s: failed to get parent clock\n",
node->full_name);
return PTR_ERR(timing->parent);
}
timing->parent_index = 0xff;
for (i = 0; i < ARRAY_SIZE(emc_parent_clk_names); i++) {
if (!strcmp(emc_parent_clk_names[i],
__clk_get_name(timing->parent))) {
timing->parent_index = i;
break;
}
}
if (timing->parent_index == 0xff) {
pr_err("timing %s: %s is not a valid parent\n",
node->full_name, __clk_get_name(timing->parent));
clk_put(timing->parent);
return -EINVAL;
}
return 0;
}
static int cmp_timings(const void *_a, const void *_b)
{
const struct emc_timing *a = _a;
const struct emc_timing *b = _b;
if (a->rate < b->rate)
return -1;
else if (a->rate == b->rate)
return 0;
else
return 1;
}
static int load_timings_from_dt(struct tegra_clk_emc *tegra,
struct device_node *node,
u32 ram_code)
{
struct device_node *child;
int child_count = of_get_child_count(node);
int i = 0, err;
tegra->timings = kcalloc(child_count, sizeof(struct emc_timing),
GFP_KERNEL);
if (!tegra->timings)
return -ENOMEM;
tegra->num_timings = child_count;
for_each_child_of_node(node, child) {
struct emc_timing *timing = tegra->timings + (i++);
err = load_one_timing_from_dt(tegra, timing, child);
if (err)
return err;
timing->ram_code = ram_code;
}
sort(tegra->timings, tegra->num_timings, sizeof(struct emc_timing),
cmp_timings, NULL);
return 0;
}
struct clk *tegra_clk_register_emc(void __iomem *base, struct device_node *np,
spinlock_t *lock)
{
struct tegra_clk_emc *tegra;
struct clk_init_data init;
struct device_node *node;
u32 node_ram_code;
struct clk *clk;
int err;
tegra = kcalloc(1, sizeof(*tegra), GFP_KERNEL);
if (!tegra)
return ERR_PTR(-ENOMEM);
tegra->clk_regs = base;
tegra->lock = lock;
tegra->num_timings = 0;
for_each_child_of_node(np, node) {
err = of_property_read_u32(node, "nvidia,ram-code",
&node_ram_code);
if (err) {
of_node_put(node);
continue;
}
err = load_timings_from_dt(tegra, node, node_ram_code);
if (err)
return ERR_PTR(err);
of_node_put(node);
break;
}
if (tegra->num_timings == 0)
pr_warn("%s: no memory timings registered\n", __func__);
tegra->emc_node = of_parse_phandle(np,
"nvidia,external-memory-controller", 0);
if (!tegra->emc_node)
pr_warn("%s: couldn't find node for EMC driver\n", __func__);
init.name = "emc";
init.ops = &tegra_clk_emc_ops;
init.flags = 0;
init.parent_names = emc_parent_clk_names;
init.num_parents = ARRAY_SIZE(emc_parent_clk_names);
tegra->hw.init = &init;
clk = clk_register(NULL, &tegra->hw);
if (IS_ERR(clk))
return clk;
tegra->prev_parent = clk_hw_get_parent_by_index(
&tegra->hw, emc_get_parent(&tegra->hw))->clk;
tegra->changing_timing = false;
clk_register_clkdev(clk, "emc", "tegra-clk-debug");
clk_prepare_enable(clk);
return clk;
}
