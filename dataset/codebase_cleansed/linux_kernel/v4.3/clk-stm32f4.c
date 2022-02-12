static unsigned long clk_apb_mul_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_apb_mul *am = to_clk_apb_mul(hw);
if (readl(base + STM32F4_RCC_CFGR) & BIT(am->bit_idx))
return parent_rate * 2;
return parent_rate;
}
static long clk_apb_mul_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_apb_mul *am = to_clk_apb_mul(hw);
unsigned long mult = 1;
if (readl(base + STM32F4_RCC_CFGR) & BIT(am->bit_idx))
mult = 2;
if (clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT) {
unsigned long best_parent = rate / mult;
*prate = clk_hw_round_rate(clk_hw_get_parent(hw), best_parent);
}
return *prate * mult;
}
static int clk_apb_mul_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return 0;
}
static struct clk *clk_register_apb_mul(struct device *dev, const char *name,
const char *parent_name,
unsigned long flags, u8 bit_idx)
{
struct clk_apb_mul *am;
struct clk_init_data init;
struct clk *clk;
am = kzalloc(sizeof(*am), GFP_KERNEL);
if (!am)
return ERR_PTR(-ENOMEM);
am->bit_idx = bit_idx;
am->hw.init = &init;
init.name = name;
init.ops = &clk_apb_mul_factor_ops;
init.flags = flags;
init.parent_names = &parent_name;
init.num_parents = 1;
clk = clk_register(dev, &am->hw);
if (IS_ERR(clk))
kfree(am);
return clk;
}
static void stm32f4_rcc_register_pll(const char *hse_clk, const char *hsi_clk)
{
unsigned long pllcfgr = readl(base + STM32F4_RCC_PLLCFGR);
unsigned long pllm = pllcfgr & 0x3f;
unsigned long plln = (pllcfgr >> 6) & 0x1ff;
unsigned long pllp = BIT(((pllcfgr >> 16) & 3) + 1);
const char *pllsrc = pllcfgr & BIT(22) ? hse_clk : hsi_clk;
unsigned long pllq = (pllcfgr >> 24) & 0xf;
clk_register_fixed_factor(NULL, "vco", pllsrc, 0, plln, pllm);
clk_register_fixed_factor(NULL, "pll", "vco", 0, 1, pllp);
clk_register_fixed_factor(NULL, "pll48", "vco", 0, 1, pllq);
}
static int stm32f4_rcc_lookup_clk_idx(u8 primary, u8 secondary)
{
u64 table[ARRAY_SIZE(stm32f42xx_gate_map)];
if (primary == 1) {
if (WARN_ON(secondary > FCLK))
return -EINVAL;
return secondary;
}
memcpy(table, stm32f42xx_gate_map, sizeof(table));
if (WARN_ON(secondary >= BITS_PER_BYTE * sizeof(table) ||
0 == (table[BIT_ULL_WORD(secondary)] &
BIT_ULL_MASK(secondary))))
return -EINVAL;
table[BIT_ULL_WORD(secondary)] &=
GENMASK_ULL(secondary % BITS_PER_LONG_LONG, 0);
return FCLK + hweight64(table[0]) +
(BIT_ULL_WORD(secondary) >= 1 ? hweight64(table[1]) : 0) +
(BIT_ULL_WORD(secondary) >= 2 ? hweight64(table[2]) : 0);
}
static struct clk *
stm32f4_rcc_lookup_clk(struct of_phandle_args *clkspec, void *data)
{
int i = stm32f4_rcc_lookup_clk_idx(clkspec->args[0], clkspec->args[1]);
if (i < 0)
return ERR_PTR(-EINVAL);
return clks[i];
}
static void __init stm32f4_rcc_init(struct device_node *np)
{
const char *hse_clk;
int n;
base = of_iomap(np, 0);
if (!base) {
pr_err("%s: unable to map resource", np->name);
return;
}
hse_clk = of_clk_get_parent_name(np, 0);
clk_register_fixed_rate_with_accuracy(NULL, "hsi", NULL, 0,
16000000, 160000);
stm32f4_rcc_register_pll(hse_clk, "hsi");
sys_parents[1] = hse_clk;
clk_register_mux_table(
NULL, "sys", sys_parents, ARRAY_SIZE(sys_parents), 0,
base + STM32F4_RCC_CFGR, 0, 3, 0, NULL, &stm32f4_clk_lock);
clk_register_divider_table(NULL, "ahb_div", "sys",
CLK_SET_RATE_PARENT, base + STM32F4_RCC_CFGR,
4, 4, 0, ahb_div_table, &stm32f4_clk_lock);
clk_register_divider_table(NULL, "apb1_div", "ahb_div",
CLK_SET_RATE_PARENT, base + STM32F4_RCC_CFGR,
10, 3, 0, apb_div_table, &stm32f4_clk_lock);
clk_register_apb_mul(NULL, "apb1_mul", "apb1_div",
CLK_SET_RATE_PARENT, 12);
clk_register_divider_table(NULL, "apb2_div", "ahb_div",
CLK_SET_RATE_PARENT, base + STM32F4_RCC_CFGR,
13, 3, 0, apb_div_table, &stm32f4_clk_lock);
clk_register_apb_mul(NULL, "apb2_mul", "apb2_div",
CLK_SET_RATE_PARENT, 15);
clks[SYSTICK] = clk_register_fixed_factor(NULL, "systick", "ahb_div",
0, 1, 8);
clks[FCLK] = clk_register_fixed_factor(NULL, "fclk", "ahb_div",
0, 1, 1);
for (n = 0; n < ARRAY_SIZE(stm32f4_gates); n++) {
const struct stm32f4_gate_data *gd = &stm32f4_gates[n];
unsigned int secondary =
8 * (gd->offset - STM32F4_RCC_AHB1ENR) + gd->bit_idx;
int idx = stm32f4_rcc_lookup_clk_idx(0, secondary);
if (idx < 0)
goto fail;
clks[idx] = clk_register_gate(
NULL, gd->name, gd->parent_name, gd->flags,
base + gd->offset, gd->bit_idx, 0, &stm32f4_clk_lock);
if (IS_ERR(clks[n])) {
pr_err("%s: Unable to register leaf clock %s\n",
np->full_name, gd->name);
goto fail;
}
}
of_clk_add_provider(np, stm32f4_rcc_lookup_clk, NULL);
return;
fail:
iounmap(base);
}
