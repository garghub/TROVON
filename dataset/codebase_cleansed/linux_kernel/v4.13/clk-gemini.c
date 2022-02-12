static unsigned long gemini_pci_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_gemini_pci *pciclk = to_pciclk(hw);
u32 val;
regmap_read(pciclk->map, GEMINI_GLOBAL_MISC_CONTROL, &val);
if (val & PCI_CLK_66MHZ)
return 66000000;
return 33000000;
}
static long gemini_pci_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
if (rate < 48000000)
return 33000000;
return 66000000;
}
static int gemini_pci_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_gemini_pci *pciclk = to_pciclk(hw);
if (rate == 33000000)
return regmap_update_bits(pciclk->map,
GEMINI_GLOBAL_MISC_CONTROL,
PCI_CLK_66MHZ, 0);
if (rate == 66000000)
return regmap_update_bits(pciclk->map,
GEMINI_GLOBAL_MISC_CONTROL,
0, PCI_CLK_66MHZ);
return -EINVAL;
}
static int gemini_pci_enable(struct clk_hw *hw)
{
struct clk_gemini_pci *pciclk = to_pciclk(hw);
regmap_update_bits(pciclk->map, GEMINI_GLOBAL_CLOCK_CONTROL,
0, PCI_CLKRUN_EN);
regmap_update_bits(pciclk->map,
GEMINI_GLOBAL_MISC_CONTROL,
0, PCI_CLK_OE);
return 0;
}
static void gemini_pci_disable(struct clk_hw *hw)
{
struct clk_gemini_pci *pciclk = to_pciclk(hw);
regmap_update_bits(pciclk->map,
GEMINI_GLOBAL_MISC_CONTROL,
PCI_CLK_OE, 0);
regmap_update_bits(pciclk->map, GEMINI_GLOBAL_CLOCK_CONTROL,
PCI_CLKRUN_EN, 0);
}
static int gemini_pci_is_enabled(struct clk_hw *hw)
{
struct clk_gemini_pci *pciclk = to_pciclk(hw);
unsigned int val;
regmap_read(pciclk->map, GEMINI_GLOBAL_CLOCK_CONTROL, &val);
return !!(val & PCI_CLKRUN_EN);
}
static struct clk_hw *gemini_pci_clk_setup(const char *name,
const char *parent_name,
struct regmap *map)
{
struct clk_gemini_pci *pciclk;
struct clk_init_data init;
int ret;
pciclk = kzalloc(sizeof(*pciclk), GFP_KERNEL);
if (!pciclk)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &gemini_pci_clk_ops;
init.flags = 0;
init.parent_names = &parent_name;
init.num_parents = 1;
pciclk->map = map;
pciclk->hw.init = &init;
ret = clk_hw_register(NULL, &pciclk->hw);
if (ret) {
kfree(pciclk);
return ERR_PTR(ret);
}
return &pciclk->hw;
}
static int gemini_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gemini_reset *gr = to_gemini_reset(rcdev);
return regmap_write(gr->map,
GEMINI_GLOBAL_SOFT_RESET,
BIT(GEMINI_RESET_CPU1) | BIT(id));
}
static int gemini_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return 0;
}
static int gemini_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return 0;
}
static int gemini_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gemini_reset *gr = to_gemini_reset(rcdev);
u32 val;
int ret;
ret = regmap_read(gr->map, GEMINI_GLOBAL_SOFT_RESET, &val);
if (ret)
return ret;
return !!(val & BIT(id));
}
static int gemini_clk_probe(struct platform_device *pdev)
{
unsigned int cpu_ahb_mult[4] = { 1, 3, 24, 2 };
unsigned int cpu_ahb_div[4] = { 1, 2, 13, 1 };
void __iomem *base;
struct gemini_reset *gr;
struct regmap *map;
struct clk_hw *hw;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
unsigned int mult, div;
struct resource *res;
u32 val;
int ret;
int i;
gr = devm_kzalloc(dev, sizeof(*gr), GFP_KERNEL);
if (!gr)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
map = syscon_node_to_regmap(np);
if (IS_ERR(map)) {
dev_err(dev, "no syscon regmap\n");
return PTR_ERR(map);
}
gr->map = map;
gr->rcdev.owner = THIS_MODULE;
gr->rcdev.nr_resets = 32;
gr->rcdev.ops = &gemini_reset_ops;
gr->rcdev.of_node = np;
ret = devm_reset_controller_register(dev, &gr->rcdev);
if (ret) {
dev_err(dev, "could not register reset controller\n");
return ret;
}
hw = clk_hw_register_fixed_rate(NULL, "rtc", NULL, 0, 32768);
gemini_clk_data->hws[GEMINI_CLK_RTC] = hw;
regmap_read(map, GEMINI_GLOBAL_STATUS, &val);
val >>= CPU_AHB_RATIO_SHIFT;
val &= CPU_AHB_RATIO_MASK;
hw = clk_hw_register_fixed_factor(NULL, "cpu", "ahb", 0,
cpu_ahb_mult[val],
cpu_ahb_div[val]);
gemini_clk_data->hws[GEMINI_CLK_CPU] = hw;
regmap_read(map, GEMINI_GLOBAL_CLOCK_CONTROL, &val);
if (val & SECURITY_CLK_SEL) {
mult = 1;
div = 1;
} else {
mult = 3;
div = 4;
}
hw = clk_hw_register_fixed_factor(NULL, "secdiv", "ahb", 0, mult, div);
for (i = 0; i < ARRAY_SIZE(gemini_gates); i++) {
const struct gemini_gate_data *gd;
gd = &gemini_gates[i];
gemini_clk_data->hws[GEMINI_CLK_GATES + i] =
clk_hw_register_gate(NULL, gd->name,
gd->parent_name,
gd->flags,
base + GEMINI_GLOBAL_CLOCK_CONTROL,
gd->bit_idx,
CLK_GATE_SET_TO_DISABLE,
&gemini_clk_lock);
}
mult = 1;
div = ((val >> TVC_HALFDIV_SHIFT) & TVC_HALFDIV_MASK);
dev_dbg(dev, "TVC half divider value = %d\n", div);
div += 1;
hw = clk_hw_register_fixed_rate(NULL, "tvcdiv", "xtal", 0, 27000000);
gemini_clk_data->hws[GEMINI_CLK_TVC] = hw;
hw = gemini_pci_clk_setup("PCI", "xtal", map);
gemini_clk_data->hws[GEMINI_CLK_PCI] = hw;
hw = clk_hw_register_fixed_rate(NULL, "uart", "xtal", 0, 48000000);
gemini_clk_data->hws[GEMINI_CLK_UART] = hw;
return 0;
}
static void __init gemini_cc_init(struct device_node *np)
{
struct regmap *map;
struct clk_hw *hw;
unsigned long freq;
unsigned int mult, div;
u32 val;
int ret;
int i;
gemini_clk_data = kzalloc(sizeof(*gemini_clk_data) +
sizeof(*gemini_clk_data->hws) * GEMINI_NUM_CLKS,
GFP_KERNEL);
if (!gemini_clk_data)
return;
for (i = 0; i < GEMINI_NUM_CLKS; i++)
gemini_clk_data->hws[i] = ERR_PTR(-EPROBE_DEFER);
map = syscon_node_to_regmap(np);
if (IS_ERR(map)) {
pr_err("no syscon regmap\n");
return;
}
ret = regmap_read(map, GEMINI_GLOBAL_STATUS, &val);
if (ret) {
pr_err("failed to read global status register\n");
return;
}
if (val & PLL_OSC_SEL)
freq = 30000000;
else
freq = 60000000;
hw = clk_hw_register_fixed_rate(NULL, "xtal", NULL, 0, freq);
pr_debug("main crystal @%lu MHz\n", freq / 1000000);
mult = 13 + ((val >> AHBSPEED_SHIFT) & AHBSPEED_MASK);
div = 2;
if (val & PLL_OSC_SEL)
mult *= 2;
hw = clk_hw_register_fixed_factor(NULL, "vco", "xtal", 0, mult, div);
hw = clk_hw_register_fixed_factor(NULL, "ahb", "vco", 0, 1, 3);
gemini_clk_data->hws[GEMINI_CLK_AHB] = hw;
hw = clk_hw_register_fixed_factor(NULL, "apb", "ahb", 0, 1, 6);
gemini_clk_data->hws[GEMINI_CLK_APB] = hw;
gemini_clk_data->num = GEMINI_NUM_CLKS;
of_clk_add_hw_provider(np, of_clk_hw_onecell_get, gemini_clk_data);
}
