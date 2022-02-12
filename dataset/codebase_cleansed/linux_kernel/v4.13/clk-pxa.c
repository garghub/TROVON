static unsigned long cken_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct pxa_clk *pclk = to_pxa_clk(hw);
struct clk_fixed_factor *fix;
if (!pclk->is_in_low_power || pclk->is_in_low_power())
fix = &pclk->lp;
else
fix = &pclk->hp;
__clk_hw_set_clk(&fix->hw, hw);
return clk_fixed_factor_ops.recalc_rate(&fix->hw, parent_rate);
}
static u8 cken_get_parent(struct clk_hw *hw)
{
struct pxa_clk *pclk = to_pxa_clk(hw);
if (!pclk->is_in_low_power)
return 0;
return pclk->is_in_low_power() ? 0 : 1;
}
void __init clkdev_pxa_register(int ckid, const char *con_id,
const char *dev_id, struct clk *clk)
{
if (!IS_ERR(clk) && (ckid != CLK_NONE))
pxa_clocks[ckid] = clk;
if (!IS_ERR(clk))
clk_register_clkdev(clk, con_id, dev_id);
}
int __init clk_pxa_cken_init(const struct desc_clk_cken *clks, int nb_clks)
{
int i;
struct pxa_clk *pxa_clk;
struct clk *clk;
for (i = 0; i < nb_clks; i++) {
pxa_clk = kzalloc(sizeof(*pxa_clk), GFP_KERNEL);
pxa_clk->is_in_low_power = clks[i].is_in_low_power;
pxa_clk->lp = clks[i].lp;
pxa_clk->hp = clks[i].hp;
pxa_clk->gate = clks[i].gate;
pxa_clk->gate.lock = &pxa_clk_lock;
clk = clk_register_composite(NULL, clks[i].name,
clks[i].parent_names, 2,
&pxa_clk->hw, &cken_mux_ops,
&pxa_clk->hw, &cken_rate_ops,
&pxa_clk->gate.hw, &clk_gate_ops,
clks[i].flags);
clkdev_pxa_register(clks[i].ckid, clks[i].con_id,
clks[i].dev_id, clk);
}
return 0;
}
void __init clk_pxa_dt_common_init(struct device_node *np)
{
of_clk_add_provider(np, of_clk_src_onecell_get, &onecell_data);
}
void pxa2xx_core_turbo_switch(bool on)
{
unsigned long flags;
unsigned int unused, clkcfg;
local_irq_save(flags);
asm("mrc p14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
clkcfg &= ~CLKCFG_TURBO & ~CLKCFG_HALFTURBO;
if (on)
clkcfg |= CLKCFG_TURBO;
clkcfg |= CLKCFG_FCS;
asm volatile(
" b 2f\n"
" .align 5\n"
"1: mcr p14, 0, %1, c6, c0, 0\n"
" b 3f\n"
"2: b 1b\n"
"3: nop\n"
: "=&r" (unused)
: "r" (clkcfg)
: );
local_irq_restore(flags);
}
void pxa2xx_cpll_change(struct pxa2xx_freq *freq,
u32 (*mdrefr_dri)(unsigned int), void __iomem *mdrefr,
void __iomem *cccr)
{
unsigned int clkcfg = freq->clkcfg;
unsigned int unused, preset_mdrefr, postset_mdrefr;
unsigned long flags;
local_irq_save(flags);
preset_mdrefr = postset_mdrefr = readl(mdrefr);
if ((preset_mdrefr & MDREFR_DRI_MASK) > mdrefr_dri(freq->membus_khz)) {
preset_mdrefr = (preset_mdrefr & ~MDREFR_DRI_MASK);
preset_mdrefr |= mdrefr_dri(freq->membus_khz);
}
postset_mdrefr =
(postset_mdrefr & ~MDREFR_DRI_MASK) |
mdrefr_dri(freq->membus_khz);
if (freq->div2) {
preset_mdrefr |= MDREFR_DB2_MASK;
postset_mdrefr |= MDREFR_DB2_MASK;
} else {
postset_mdrefr &= ~MDREFR_DB2_MASK;
}
writel(freq->cccr, cccr);
asm volatile(
" ldr r4, [%1]\n"
" b 2f\n"
" .align 5\n"
"1: str %3, [%1] /* preset the MDREFR */\n"
" mcr p14, 0, %2, c6, c0, 0 /* set CLKCFG[FCS] */\n"
" str %4, [%1] /* postset the MDREFR */\n"
" b 3f\n"
"2: b 1b\n"
"3: nop\n"
: "=&r" (unused)
: "r" (mdrefr), "r" (clkcfg), "r" (preset_mdrefr),
"r" (postset_mdrefr)
: "r4", "r5");
local_irq_restore(flags);
}
int pxa2xx_determine_rate(struct clk_rate_request *req,
struct pxa2xx_freq *freqs, int nb_freqs)
{
int i, closest_below = -1, closest_above = -1;
unsigned long rate;
for (i = 0; i < nb_freqs; i++) {
rate = freqs[i].cpll;
if (rate == req->rate)
break;
if (rate < req->min_rate)
continue;
if (rate > req->max_rate)
continue;
if (rate <= req->rate)
closest_below = i;
if ((rate >= req->rate) && (closest_above == -1))
closest_above = i;
}
req->best_parent_hw = NULL;
if (i < nb_freqs) {
rate = req->rate;
} else if (closest_below >= 0) {
rate = freqs[closest_below].cpll;
} else if (closest_above >= 0) {
rate = freqs[closest_above].cpll;
} else {
pr_debug("%s(rate=%lu) no match\n", __func__, req->rate);
return -EINVAL;
}
pr_debug("%s(rate=%lu) rate=%lu\n", __func__, req->rate, rate);
req->rate = rate;
return 0;
}
