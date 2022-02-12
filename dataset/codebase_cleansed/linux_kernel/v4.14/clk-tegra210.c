void tegra210_xusb_pll_hw_control_enable(void)
{
u32 val;
val = readl_relaxed(clk_base + XUSBIO_PLL_CFG0);
val &= ~(XUSBIO_PLL_CFG0_CLK_ENABLE_SWCTL |
XUSBIO_PLL_CFG0_PADPLL_RESET_SWCTL);
val |= XUSBIO_PLL_CFG0_PADPLL_USE_LOCKDET |
XUSBIO_PLL_CFG0_PADPLL_SLEEP_IDDQ;
writel_relaxed(val, clk_base + XUSBIO_PLL_CFG0);
}
void tegra210_xusb_pll_hw_sequence_start(void)
{
u32 val;
val = readl_relaxed(clk_base + XUSBIO_PLL_CFG0);
val |= XUSBIO_PLL_CFG0_SEQ_ENABLE;
writel_relaxed(val, clk_base + XUSBIO_PLL_CFG0);
}
void tegra210_sata_pll_hw_control_enable(void)
{
u32 val;
val = readl_relaxed(clk_base + SATA_PLL_CFG0);
val &= ~SATA_PLL_CFG0_PADPLL_RESET_SWCTL;
val |= SATA_PLL_CFG0_PADPLL_USE_LOCKDET |
SATA_PLL_CFG0_PADPLL_SLEEP_IDDQ;
writel_relaxed(val, clk_base + SATA_PLL_CFG0);
}
void tegra210_sata_pll_hw_sequence_start(void)
{
u32 val;
val = readl_relaxed(clk_base + SATA_PLL_CFG0);
val |= SATA_PLL_CFG0_SEQ_ENABLE;
writel_relaxed(val, clk_base + SATA_PLL_CFG0);
}
void tegra210_set_sata_pll_seq_sw(bool state)
{
u32 val;
val = readl_relaxed(clk_base + SATA_PLL_CFG0);
if (state) {
val |= SATA_PLL_CFG0_SATA_SEQ_IN_SWCTL;
val |= SATA_PLL_CFG0_SATA_SEQ_RESET_INPUT_VALUE;
val |= SATA_PLL_CFG0_SATA_SEQ_LANE_PD_INPUT_VALUE;
val |= SATA_PLL_CFG0_SATA_SEQ_PADPLL_PD_INPUT_VALUE;
} else {
val &= ~SATA_PLL_CFG0_SATA_SEQ_IN_SWCTL;
val &= ~SATA_PLL_CFG0_SATA_SEQ_RESET_INPUT_VALUE;
val &= ~SATA_PLL_CFG0_SATA_SEQ_LANE_PD_INPUT_VALUE;
val &= ~SATA_PLL_CFG0_SATA_SEQ_PADPLL_PD_INPUT_VALUE;
}
writel_relaxed(val, clk_base + SATA_PLL_CFG0);
}
static inline void _pll_misc_chk_default(void __iomem *base,
struct tegra_clk_pll_params *params,
u8 misc_num, u32 default_val, u32 mask)
{
u32 boot_val = readl_relaxed(base + params->ext_misc_reg[misc_num]);
boot_val &= mask;
default_val &= mask;
if (boot_val != default_val) {
pr_warn("boot misc%d 0x%x: expected 0x%x\n",
misc_num, boot_val, default_val);
pr_warn(" (comparison mask = 0x%x)\n", mask);
params->defaults_set = false;
}
}
static void pllcx_check_defaults(struct tegra_clk_pll_params *params)
{
u32 default_val;
default_val = PLLCX_MISC0_DEFAULT_VALUE & (~PLLCX_MISC0_RESET);
_pll_misc_chk_default(clk_base, params, 0, default_val,
PLLCX_MISC0_WRITE_MASK);
default_val = PLLCX_MISC1_DEFAULT_VALUE & (~PLLCX_MISC1_IDDQ);
_pll_misc_chk_default(clk_base, params, 1, default_val,
PLLCX_MISC1_WRITE_MASK);
default_val = PLLCX_MISC2_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, params, 2, default_val,
PLLCX_MISC2_WRITE_MASK);
default_val = PLLCX_MISC3_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, params, 3, default_val,
PLLCX_MISC3_WRITE_MASK);
}
static void tegra210_pllcx_set_defaults(const char *name,
struct tegra_clk_pll *pllcx)
{
pllcx->params->defaults_set = true;
if (readl_relaxed(clk_base + pllcx->params->base_reg) & PLL_ENABLE) {
pllcx_check_defaults(pllcx->params);
if (!pllcx->params->defaults_set)
pr_warn("%s already enabled. Postponing set full defaults\n",
name);
return;
}
writel_relaxed(PLLCX_MISC0_DEFAULT_VALUE,
clk_base + pllcx->params->ext_misc_reg[0]);
writel_relaxed(PLLCX_MISC1_DEFAULT_VALUE,
clk_base + pllcx->params->ext_misc_reg[1]);
writel_relaxed(PLLCX_MISC2_DEFAULT_VALUE,
clk_base + pllcx->params->ext_misc_reg[2]);
writel_relaxed(PLLCX_MISC3_DEFAULT_VALUE,
clk_base + pllcx->params->ext_misc_reg[3]);
udelay(1);
}
static void _pllc_set_defaults(struct tegra_clk_pll *pllcx)
{
tegra210_pllcx_set_defaults("PLL_C", pllcx);
}
static void _pllc2_set_defaults(struct tegra_clk_pll *pllcx)
{
tegra210_pllcx_set_defaults("PLL_C2", pllcx);
}
static void _pllc3_set_defaults(struct tegra_clk_pll *pllcx)
{
tegra210_pllcx_set_defaults("PLL_C3", pllcx);
}
static void _plla1_set_defaults(struct tegra_clk_pll *pllcx)
{
tegra210_pllcx_set_defaults("PLL_A1", pllcx);
}
static void tegra210_plla_set_defaults(struct tegra_clk_pll *plla)
{
u32 mask;
u32 val = readl_relaxed(clk_base + plla->params->base_reg);
plla->params->defaults_set = true;
if (val & PLL_ENABLE) {
if (val & PLLA_BASE_IDDQ) {
pr_warn("PLL_A boot enabled with IDDQ set\n");
plla->params->defaults_set = false;
}
pr_warn("PLL_A already enabled. Postponing set full defaults\n");
val = PLLA_MISC0_DEFAULT_VALUE;
mask = PLLA_MISC0_LOCK_ENABLE | PLLA_MISC0_LOCK_OVERRIDE;
_pll_misc_chk_default(clk_base, plla->params, 0, val,
~mask & PLLA_MISC0_WRITE_MASK);
val = PLLA_MISC2_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, plla->params, 2, val,
PLLA_MISC2_EN_DYNRAMP);
val = readl_relaxed(clk_base + plla->params->ext_misc_reg[0]);
val &= ~mask;
val |= PLLA_MISC0_DEFAULT_VALUE & mask;
writel_relaxed(val, clk_base + plla->params->ext_misc_reg[0]);
udelay(1);
return;
}
val |= PLLA_BASE_IDDQ;
writel_relaxed(val, clk_base + plla->params->base_reg);
writel_relaxed(PLLA_MISC0_DEFAULT_VALUE,
clk_base + plla->params->ext_misc_reg[0]);
writel_relaxed(PLLA_MISC2_DEFAULT_VALUE,
clk_base + plla->params->ext_misc_reg[2]);
udelay(1);
}
static void tegra210_plld_set_defaults(struct tegra_clk_pll *plld)
{
u32 val;
u32 mask = 0xffff;
plld->params->defaults_set = true;
if (readl_relaxed(clk_base + plld->params->base_reg) &
PLL_ENABLE) {
val = PLLD_MISC1_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, plld->params, 1,
val, PLLD_MISC1_WRITE_MASK);
val = PLLD_MISC0_DEFAULT_VALUE & (~PLLD_MISC0_IDDQ);
mask |= PLLD_MISC0_DSI_CLKENABLE | PLLD_MISC0_LOCK_ENABLE |
PLLD_MISC0_LOCK_OVERRIDE | PLLD_MISC0_EN_SDM;
_pll_misc_chk_default(clk_base, plld->params, 0, val,
~mask & PLLD_MISC0_WRITE_MASK);
if (!plld->params->defaults_set)
pr_warn("PLL_D already enabled. Postponing set full defaults\n");
mask = PLLD_MISC0_LOCK_ENABLE | PLLD_MISC0_LOCK_OVERRIDE;
val = readl_relaxed(clk_base + plld->params->ext_misc_reg[0]);
val &= ~mask;
val |= PLLD_MISC0_DEFAULT_VALUE & mask;
writel_relaxed(val, clk_base + plld->params->ext_misc_reg[0]);
udelay(1);
return;
}
val = readl_relaxed(clk_base + plld->params->ext_misc_reg[0]);
val &= PLLD_MISC0_DSI_CLKENABLE;
val |= PLLD_MISC0_DEFAULT_VALUE;
writel_relaxed(val, clk_base + plld->params->ext_misc_reg[0]);
writel_relaxed(PLLD_MISC1_DEFAULT_VALUE, clk_base +
plld->params->ext_misc_reg[1]);
udelay(1);
}
static void plldss_defaults(const char *pll_name, struct tegra_clk_pll *plldss,
u32 misc0_val, u32 misc1_val, u32 misc2_val, u32 misc3_val)
{
u32 default_val;
u32 val = readl_relaxed(clk_base + plldss->params->base_reg);
plldss->params->defaults_set = true;
if (val & PLL_ENABLE) {
if (val & PLLDSS_BASE_IDDQ) {
pr_warn("plldss boot enabled with IDDQ set\n");
plldss->params->defaults_set = false;
}
default_val = misc0_val;
_pll_misc_chk_default(clk_base, plldss->params, 0, default_val,
PLLDSS_MISC0_WRITE_MASK &
(~PLLDSS_MISC0_LOCK_ENABLE));
if (plldss->params->ssc_ctrl_en_mask) {
default_val = misc1_val;
_pll_misc_chk_default(clk_base, plldss->params, 1,
default_val, PLLDSS_MISC1_CFG_WRITE_MASK);
default_val = misc2_val;
_pll_misc_chk_default(clk_base, plldss->params, 2,
default_val, PLLDSS_MISC2_CTRL1_WRITE_MASK);
default_val = misc3_val;
_pll_misc_chk_default(clk_base, plldss->params, 3,
default_val, PLLDSS_MISC3_CTRL2_WRITE_MASK);
} else if (plldss->params->ext_misc_reg[1]) {
default_val = misc1_val;
_pll_misc_chk_default(clk_base, plldss->params, 1,
default_val, PLLDSS_MISC1_CFG_WRITE_MASK &
(~PLLDSS_MISC1_CFG_EN_SDM));
}
if (!plldss->params->defaults_set)
pr_warn("%s already enabled. Postponing set full defaults\n",
pll_name);
if (val & PLLDSS_BASE_LOCK_OVERRIDE) {
val &= ~PLLDSS_BASE_LOCK_OVERRIDE;
writel_relaxed(val, clk_base +
plldss->params->base_reg);
}
val = readl_relaxed(clk_base + plldss->params->ext_misc_reg[0]);
val &= ~PLLDSS_MISC0_LOCK_ENABLE;
val |= misc0_val & PLLDSS_MISC0_LOCK_ENABLE;
writel_relaxed(val, clk_base + plldss->params->ext_misc_reg[0]);
udelay(1);
return;
}
val |= PLLDSS_BASE_IDDQ;
val &= ~PLLDSS_BASE_LOCK_OVERRIDE;
writel_relaxed(val, clk_base + plldss->params->base_reg);
if (!plldss->params->ext_misc_reg[1]) {
writel_relaxed(misc0_val, clk_base +
plldss->params->ext_misc_reg[0]);
udelay(1);
return;
}
writel_relaxed(misc0_val, clk_base +
plldss->params->ext_misc_reg[0]);
writel_relaxed(misc1_val & (~PLLDSS_MISC1_CFG_EN_SSC),
clk_base + plldss->params->ext_misc_reg[1]);
writel_relaxed(misc2_val, clk_base + plldss->params->ext_misc_reg[2]);
writel_relaxed(misc3_val, clk_base + plldss->params->ext_misc_reg[3]);
udelay(1);
}
static void tegra210_plld2_set_defaults(struct tegra_clk_pll *plld2)
{
plldss_defaults("PLL_D2", plld2, PLLD2_MISC0_DEFAULT_VALUE,
PLLD2_MISC1_CFG_DEFAULT_VALUE,
PLLD2_MISC2_CTRL1_DEFAULT_VALUE,
PLLD2_MISC3_CTRL2_DEFAULT_VALUE);
}
static void tegra210_plldp_set_defaults(struct tegra_clk_pll *plldp)
{
plldss_defaults("PLL_DP", plldp, PLLDP_MISC0_DEFAULT_VALUE,
PLLDP_MISC1_CFG_DEFAULT_VALUE,
PLLDP_MISC2_CTRL1_DEFAULT_VALUE,
PLLDP_MISC3_CTRL2_DEFAULT_VALUE);
}
static void tegra210_pllc4_set_defaults(struct tegra_clk_pll *pllc4)
{
plldss_defaults("PLL_C4", pllc4, PLLC4_MISC0_DEFAULT_VALUE, 0, 0, 0);
}
static void tegra210_pllre_set_defaults(struct tegra_clk_pll *pllre)
{
u32 mask;
u32 val = readl_relaxed(clk_base + pllre->params->base_reg);
pllre->params->defaults_set = true;
if (val & PLL_ENABLE) {
pr_warn("PLL_RE already enabled. Postponing set full defaults\n");
val &= PLLRE_BASE_DEFAULT_MASK;
if (val != PLLRE_BASE_DEFAULT_VALUE) {
pr_warn("pllre boot base 0x%x : expected 0x%x\n",
val, PLLRE_BASE_DEFAULT_VALUE);
pr_warn("(comparison mask = 0x%x)\n",
PLLRE_BASE_DEFAULT_MASK);
pllre->params->defaults_set = false;
}
val = PLLRE_MISC0_DEFAULT_VALUE & (~PLLRE_MISC0_IDDQ);
mask = PLLRE_MISC0_LOCK_ENABLE | PLLRE_MISC0_LOCK_OVERRIDE;
_pll_misc_chk_default(clk_base, pllre->params, 0, val,
~mask & PLLRE_MISC0_WRITE_MASK);
val = readl_relaxed(clk_base + pllre->params->ext_misc_reg[0]);
val &= ~mask;
val |= PLLRE_MISC0_DEFAULT_VALUE & mask;
writel_relaxed(val, clk_base + pllre->params->ext_misc_reg[0]);
udelay(1);
return;
}
val &= ~PLLRE_BASE_DEFAULT_MASK;
val |= PLLRE_BASE_DEFAULT_VALUE & PLLRE_BASE_DEFAULT_MASK;
writel_relaxed(val, clk_base + pllre->params->base_reg);
writel_relaxed(PLLRE_MISC0_DEFAULT_VALUE,
clk_base + pllre->params->ext_misc_reg[0]);
udelay(1);
}
static void pllx_get_dyn_steps(struct clk_hw *hw, u32 *step_a, u32 *step_b)
{
unsigned long input_rate;
if (!IS_ERR_OR_NULL(hw->clk))
input_rate = clk_hw_get_rate(clk_hw_get_parent(hw));
else
input_rate = 38400000;
input_rate /= tegra_pll_get_fixed_mdiv(hw, input_rate);
switch (input_rate) {
case 12000000:
case 12800000:
case 13000000:
*step_a = 0x2B;
*step_b = 0x0B;
return;
case 19200000:
*step_a = 0x12;
*step_b = 0x08;
return;
case 38400000:
*step_a = 0x04;
*step_b = 0x05;
return;
default:
pr_err("%s: Unexpected reference rate %lu\n",
__func__, input_rate);
BUG();
}
}
static void pllx_check_defaults(struct tegra_clk_pll *pll)
{
u32 default_val;
default_val = PLLX_MISC0_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, pll->params, 0, default_val,
PLLX_MISC0_WRITE_MASK & (~PLLX_MISC0_LOCK_ENABLE));
default_val = PLLX_MISC1_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, pll->params, 1, default_val,
PLLX_MISC1_WRITE_MASK);
default_val = PLLX_MISC2_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, pll->params, 2,
default_val, PLLX_MISC2_EN_DYNRAMP);
default_val = PLLX_MISC3_DEFAULT_VALUE & (~PLLX_MISC3_IDDQ);
_pll_misc_chk_default(clk_base, pll->params, 3, default_val,
PLLX_MISC3_WRITE_MASK);
default_val = PLLX_MISC4_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, pll->params, 4, default_val,
PLLX_MISC4_WRITE_MASK);
default_val = PLLX_MISC5_DEFAULT_VALUE;
_pll_misc_chk_default(clk_base, pll->params, 5, default_val,
PLLX_MISC5_WRITE_MASK);
}
static void tegra210_pllx_set_defaults(struct tegra_clk_pll *pllx)
{
u32 val;
u32 step_a, step_b;
pllx->params->defaults_set = true;
pllx_get_dyn_steps(&pllx->hw, &step_a, &step_b);
val = PLLX_MISC2_DEFAULT_VALUE & (~PLLX_MISC2_DYNRAMP_STEPA_MASK) &
(~PLLX_MISC2_DYNRAMP_STEPB_MASK);
val |= step_a << PLLX_MISC2_DYNRAMP_STEPA_SHIFT;
val |= step_b << PLLX_MISC2_DYNRAMP_STEPB_SHIFT;
if (readl_relaxed(clk_base + pllx->params->base_reg) & PLL_ENABLE) {
pllx_check_defaults(pllx);
if (!pllx->params->defaults_set)
pr_warn("PLL_X already enabled. Postponing set full defaults\n");
writel_relaxed(val, clk_base + pllx->params->ext_misc_reg[2]);
val = readl_relaxed(clk_base + pllx->params->ext_misc_reg[0]);
val &= ~PLLX_MISC0_LOCK_ENABLE;
val |= PLLX_MISC0_DEFAULT_VALUE & PLLX_MISC0_LOCK_ENABLE;
writel_relaxed(val, clk_base + pllx->params->ext_misc_reg[0]);
udelay(1);
return;
}
writel_relaxed(PLLX_MISC0_DEFAULT_VALUE, clk_base +
pllx->params->ext_misc_reg[0]);
writel_relaxed(PLLX_MISC1_DEFAULT_VALUE, clk_base +
pllx->params->ext_misc_reg[1]);
writel_relaxed(val, clk_base + pllx->params->ext_misc_reg[2]);
writel_relaxed(PLLX_MISC3_DEFAULT_VALUE, clk_base +
pllx->params->ext_misc_reg[3]);
writel_relaxed(PLLX_MISC4_DEFAULT_VALUE, clk_base +
pllx->params->ext_misc_reg[4]);
writel_relaxed(PLLX_MISC5_DEFAULT_VALUE, clk_base +
pllx->params->ext_misc_reg[5]);
udelay(1);
}
static void tegra210_pllmb_set_defaults(struct tegra_clk_pll *pllmb)
{
u32 mask, val = readl_relaxed(clk_base + pllmb->params->base_reg);
pllmb->params->defaults_set = true;
if (val & PLL_ENABLE) {
val = PLLMB_MISC1_DEFAULT_VALUE & (~PLLMB_MISC1_IDDQ);
mask = PLLMB_MISC1_LOCK_ENABLE | PLLMB_MISC1_LOCK_OVERRIDE;
_pll_misc_chk_default(clk_base, pllmb->params, 0, val,
~mask & PLLMB_MISC1_WRITE_MASK);
if (!pllmb->params->defaults_set)
pr_warn("PLL_MB already enabled. Postponing set full defaults\n");
val = readl_relaxed(clk_base + pllmb->params->ext_misc_reg[0]);
val &= ~mask;
val |= PLLMB_MISC1_DEFAULT_VALUE & mask;
writel_relaxed(val, clk_base + pllmb->params->ext_misc_reg[0]);
udelay(1);
return;
}
writel_relaxed(PLLMB_MISC1_DEFAULT_VALUE,
clk_base + pllmb->params->ext_misc_reg[0]);
udelay(1);
}
static void pllp_check_defaults(struct tegra_clk_pll *pll, bool enabled)
{
u32 val, mask;
val = PLLP_MISC0_DEFAULT_VALUE & (~PLLP_MISC0_IDDQ);
mask = PLLP_MISC0_LOCK_ENABLE | PLLP_MISC0_LOCK_OVERRIDE;
if (!enabled)
mask |= PLLP_MISC0_IDDQ;
_pll_misc_chk_default(clk_base, pll->params, 0, val,
~mask & PLLP_MISC0_WRITE_MASK);
val = PLLP_MISC1_DEFAULT_VALUE;
mask = PLLP_MISC1_HSIO_EN | PLLP_MISC1_XUSB_EN;
_pll_misc_chk_default(clk_base, pll->params, 1, val,
~mask & PLLP_MISC1_WRITE_MASK);
}
static void tegra210_pllp_set_defaults(struct tegra_clk_pll *pllp)
{
u32 mask;
u32 val = readl_relaxed(clk_base + pllp->params->base_reg);
pllp->params->defaults_set = true;
if (val & PLL_ENABLE) {
pllp_check_defaults(pllp, true);
if (!pllp->params->defaults_set)
pr_warn("PLL_P already enabled. Postponing set full defaults\n");
val = readl_relaxed(clk_base + pllp->params->ext_misc_reg[0]);
mask = PLLP_MISC0_LOCK_ENABLE | PLLP_MISC0_LOCK_OVERRIDE;
val &= ~mask;
val |= PLLP_MISC0_DEFAULT_VALUE & mask;
writel_relaxed(val, clk_base + pllp->params->ext_misc_reg[0]);
udelay(1);
return;
}
writel_relaxed(PLLP_MISC0_DEFAULT_VALUE,
clk_base + pllp->params->ext_misc_reg[0]);
val = readl_relaxed(clk_base + pllp->params->ext_misc_reg[1]);
mask = PLLP_MISC1_HSIO_EN | PLLP_MISC1_XUSB_EN;
val &= mask;
val |= ~mask & PLLP_MISC1_DEFAULT_VALUE;
writel_relaxed(val, clk_base + pllp->params->ext_misc_reg[1]);
udelay(1);
}
static void pllu_check_defaults(struct tegra_clk_pll_params *params,
bool hw_control)
{
u32 val, mask;
val = PLLU_MISC0_DEFAULT_VALUE & (~PLLU_MISC0_IDDQ);
mask = PLLU_MISC0_LOCK_ENABLE | (hw_control ? PLLU_MISC0_IDDQ : 0);
_pll_misc_chk_default(clk_base, params, 0, val,
~mask & PLLU_MISC0_WRITE_MASK);
val = PLLU_MISC1_DEFAULT_VALUE;
mask = PLLU_MISC1_LOCK_OVERRIDE;
_pll_misc_chk_default(clk_base, params, 1, val,
~mask & PLLU_MISC1_WRITE_MASK);
}
static void tegra210_pllu_set_defaults(struct tegra_clk_pll_params *pllu)
{
u32 val = readl_relaxed(clk_base + pllu->base_reg);
pllu->defaults_set = true;
if (val & PLL_ENABLE) {
pllu_check_defaults(pllu, false);
if (!pllu->defaults_set)
pr_warn("PLL_U already enabled. Postponing set full defaults\n");
val = readl_relaxed(clk_base + pllu->ext_misc_reg[0]);
val &= ~PLLU_MISC0_LOCK_ENABLE;
val |= PLLU_MISC0_DEFAULT_VALUE & PLLU_MISC0_LOCK_ENABLE;
writel_relaxed(val, clk_base + pllu->ext_misc_reg[0]);
val = readl_relaxed(clk_base + pllu->ext_misc_reg[1]);
val &= ~PLLU_MISC1_LOCK_OVERRIDE;
val |= PLLU_MISC1_DEFAULT_VALUE & PLLU_MISC1_LOCK_OVERRIDE;
writel_relaxed(val, clk_base + pllu->ext_misc_reg[1]);
udelay(1);
return;
}
writel_relaxed(PLLU_MISC0_DEFAULT_VALUE,
clk_base + pllu->ext_misc_reg[0]);
writel_relaxed(PLLU_MISC1_DEFAULT_VALUE,
clk_base + pllu->ext_misc_reg[1]);
udelay(1);
}
static int tegra210_wait_for_mask(struct tegra_clk_pll *pll,
u32 reg, u32 mask)
{
int i;
u32 val = 0;
for (i = 0; i < pll->params->lock_delay / PLL_LOCKDET_DELAY + 1; i++) {
udelay(PLL_LOCKDET_DELAY);
val = readl_relaxed(clk_base + reg);
if ((val & mask) == mask) {
udelay(PLL_LOCKDET_DELAY);
return 0;
}
}
return -ETIMEDOUT;
}
static int tegra210_pllx_dyn_ramp(struct tegra_clk_pll *pllx,
struct tegra_clk_pll_freq_table *cfg)
{
u32 val, base, ndiv_new_mask;
ndiv_new_mask = (divn_mask(pllx) >> pllx->params->div_nmp->divn_shift)
<< PLLX_MISC2_NDIV_NEW_SHIFT;
val = readl_relaxed(clk_base + pllx->params->ext_misc_reg[2]);
val &= (~ndiv_new_mask);
val |= cfg->n << PLLX_MISC2_NDIV_NEW_SHIFT;
writel_relaxed(val, clk_base + pllx->params->ext_misc_reg[2]);
udelay(1);
val = readl_relaxed(clk_base + pllx->params->ext_misc_reg[2]);
val |= PLLX_MISC2_EN_DYNRAMP;
writel_relaxed(val, clk_base + pllx->params->ext_misc_reg[2]);
udelay(1);
tegra210_wait_for_mask(pllx, pllx->params->ext_misc_reg[2],
PLLX_MISC2_DYNRAMP_DONE);
base = readl_relaxed(clk_base + pllx->params->base_reg) &
(~divn_mask_shifted(pllx));
base |= cfg->n << pllx->params->div_nmp->divn_shift;
writel_relaxed(base, clk_base + pllx->params->base_reg);
udelay(1);
val &= ~PLLX_MISC2_EN_DYNRAMP;
writel_relaxed(val, clk_base + pllx->params->ext_misc_reg[2]);
udelay(1);
pr_debug("%s: dynamic ramp to m = %u n = %u p = %u, Fout = %lu kHz\n",
__clk_get_name(pllx->hw.clk), cfg->m, cfg->n, cfg->p,
cfg->input_rate / cfg->m * cfg->n /
pllx->params->pdiv_tohw[cfg->p].pdiv / 1000);
return 0;
}
static int tegra210_pll_fixed_mdiv_cfg(struct clk_hw *hw,
struct tegra_clk_pll_freq_table *cfg,
unsigned long rate, unsigned long input_rate)
{
struct tegra_clk_pll *pll = to_clk_pll(hw);
struct tegra_clk_pll_params *params = pll->params;
int p;
unsigned long cf, p_rate;
u32 pdiv;
if (!rate)
return -EINVAL;
if (!(params->flags & TEGRA_PLL_VCO_OUT)) {
p = DIV_ROUND_UP(params->vco_min, rate);
p = params->round_p_to_pdiv(p, &pdiv);
} else {
p = rate >= params->vco_min ? 1 : -EINVAL;
}
if (p < 0)
return -EINVAL;
cfg->m = tegra_pll_get_fixed_mdiv(hw, input_rate);
cfg->p = p;
cfg->p = tegra_pll_p_div_to_hw(pll, cfg->p);
p_rate = rate * p;
if (p_rate > params->vco_max)
p_rate = params->vco_max;
cf = input_rate / cfg->m;
cfg->n = p_rate / cf;
cfg->sdm_data = 0;
cfg->output_rate = input_rate;
if (params->sdm_ctrl_reg) {
unsigned long rem = p_rate - cf * cfg->n;
if (rem || params->ssc_ctrl_reg) {
u64 s = rem * PLL_SDM_COEFF;
do_div(s, cf);
s -= PLL_SDM_COEFF / 2;
cfg->sdm_data = sdin_din_to_data(s);
}
cfg->output_rate *= sdin_get_n_eff(cfg);
cfg->output_rate /= p * cfg->m * PLL_SDM_COEFF;
} else {
cfg->output_rate *= cfg->n;
cfg->output_rate /= p * cfg->m;
}
cfg->input_rate = input_rate;
return 0;
}
static void tegra210_clk_pll_set_gain(struct tegra_clk_pll_freq_table *cfg)
{
cfg->n = sdin_get_n_eff(cfg);
cfg->m *= PLL_SDM_COEFF;
}
static unsigned long
tegra210_clk_adjust_vco_min(struct tegra_clk_pll_params *params,
unsigned long parent_rate)
{
unsigned long vco_min = params->vco_min;
params->vco_min += DIV_ROUND_UP(parent_rate, PLL_SDM_COEFF);
vco_min = min(vco_min, params->vco_min);
return vco_min;
}
static u32 pll_qlin_p_to_pdiv(u32 p, u32 *pdiv)
{
int i;
if (p) {
for (i = 0; i <= PLL_QLIN_PDIV_MAX; i++) {
if (p <= pll_qlin_pdiv_to_hw[i].pdiv) {
if (pdiv)
*pdiv = i;
return pll_qlin_pdiv_to_hw[i].pdiv;
}
}
}
return -EINVAL;
}
static u32 pll_expo_p_to_pdiv(u32 p, u32 *pdiv)
{
if (p) {
u32 i = fls(p);
if (i == ffs(p))
i--;
if (i <= PLL_EXPO_PDIV_MAX) {
if (pdiv)
*pdiv = i;
return 1 << i;
}
}
return -EINVAL;
}
void tegra210_put_utmipll_in_iddq(void)
{
u32 reg;
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
if (reg & UTMIPLL_HW_PWRDN_CFG0_UTMIPLL_LOCK) {
pr_err("trying to assert IDDQ while UTMIPLL is locked\n");
return;
}
reg |= UTMIPLL_HW_PWRDN_CFG0_IDDQ_OVERRIDE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
}
void tegra210_put_utmipll_out_iddq(void)
{
u32 reg;
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg &= ~UTMIPLL_HW_PWRDN_CFG0_IDDQ_OVERRIDE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
}
static void tegra210_utmi_param_configure(void)
{
u32 reg;
int i;
for (i = 0; i < ARRAY_SIZE(utmi_parameters); i++) {
if (osc_freq == utmi_parameters[i].osc_frequency)
break;
}
if (i >= ARRAY_SIZE(utmi_parameters)) {
pr_err("%s: Unexpected oscillator freq %lu\n", __func__,
osc_freq);
return;
}
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg &= ~UTMIPLL_HW_PWRDN_CFG0_IDDQ_OVERRIDE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
udelay(10);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG2);
reg &= ~UTMIP_PLL_CFG2_STABLE_COUNT(~0);
reg |= UTMIP_PLL_CFG2_STABLE_COUNT(utmi_parameters[i].stable_count);
reg &= ~UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(~0);
reg |=
UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(utmi_parameters[i].active_delay_count);
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG2);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(~0);
reg |=
UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(utmi_parameters[i].enable_delay_count);
reg &= ~UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(~0);
reg |=
UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(utmi_parameters[i].xtal_freq_count);
reg |= UTMIP_PLL_CFG1_FORCE_PLLU_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG1);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN;
reg |= UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERUP;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG1);
udelay(20);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG2);
reg |= UTMIP_PLL_CFG2_FORCE_PD_SAMP_A_POWERUP;
reg |= UTMIP_PLL_CFG2_FORCE_PD_SAMP_B_POWERUP;
reg |= UTMIP_PLL_CFG2_FORCE_PD_SAMP_D_POWERUP;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_A_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_B_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_D_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG2);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERUP;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG1);
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg |= UTMIPLL_HW_PWRDN_CFG0_USE_LOCKDET;
reg &= ~UTMIPLL_HW_PWRDN_CFG0_CLK_ENABLE_SWCTL;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
udelay(1);
reg = readl_relaxed(clk_base + XUSB_PLL_CFG0);
reg &= ~XUSB_PLL_CFG0_UTMIPLL_LOCK_DLY;
writel_relaxed(reg, clk_base + XUSB_PLL_CFG0);
udelay(1);
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg |= UTMIPLL_HW_PWRDN_CFG0_SEQ_ENABLE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
}
static int tegra210_enable_pllu(void)
{
struct tegra_clk_pll_freq_table *fentry;
struct tegra_clk_pll pllu;
u32 reg;
for (fentry = pll_u_freq_table; fentry->input_rate; fentry++) {
if (fentry->input_rate == pll_ref_freq)
break;
}
if (!fentry->input_rate) {
pr_err("Unknown PLL_U reference frequency %lu\n", pll_ref_freq);
return -EINVAL;
}
pllu.params = &pll_u_vco_params;
reg = readl_relaxed(clk_base + pllu.params->ext_misc_reg[0]);
reg &= ~BIT(pllu.params->iddq_bit_idx);
writel_relaxed(reg, clk_base + pllu.params->ext_misc_reg[0]);
udelay(5);
reg = readl_relaxed(clk_base + PLLU_BASE);
reg &= ~GENMASK(20, 0);
reg |= fentry->m;
reg |= fentry->n << 8;
reg |= fentry->p << 16;
writel(reg, clk_base + PLLU_BASE);
udelay(1);
reg |= PLL_ENABLE;
writel(reg, clk_base + PLLU_BASE);
readl_relaxed_poll_timeout(clk_base + PLLU_BASE, reg,
reg & PLL_BASE_LOCK, 2, 1000);
if (!(reg & PLL_BASE_LOCK)) {
pr_err("Timed out waiting for PLL_U to lock\n");
return -ETIMEDOUT;
}
return 0;
}
static int tegra210_init_pllu(void)
{
u32 reg;
int err;
tegra210_pllu_set_defaults(&pll_u_vco_params);
reg = readl_relaxed(clk_base + PLLU_BASE);
if (reg & PLLU_BASE_OVERRIDE) {
if (!(reg & PLL_ENABLE)) {
err = tegra210_enable_pllu();
if (err < 0) {
WARN_ON(1);
return err;
}
}
reg = readl_relaxed(clk_base + PLLU_BASE);
reg &= ~PLLU_BASE_OVERRIDE;
writel(reg, clk_base + PLLU_BASE);
reg = readl_relaxed(clk_base + PLLU_HW_PWRDN_CFG0);
reg |= PLLU_HW_PWRDN_CFG0_IDDQ_PD_INCLUDE |
PLLU_HW_PWRDN_CFG0_USE_SWITCH_DETECT |
PLLU_HW_PWRDN_CFG0_USE_LOCKDET;
reg &= ~(PLLU_HW_PWRDN_CFG0_CLK_ENABLE_SWCTL |
PLLU_HW_PWRDN_CFG0_CLK_SWITCH_SWCTL);
writel_relaxed(reg, clk_base + PLLU_HW_PWRDN_CFG0);
reg = readl_relaxed(clk_base + XUSB_PLL_CFG0);
reg &= ~XUSB_PLL_CFG0_PLLU_LOCK_DLY_MASK;
writel_relaxed(reg, clk_base + XUSB_PLL_CFG0);
udelay(1);
reg = readl_relaxed(clk_base + PLLU_HW_PWRDN_CFG0);
reg |= PLLU_HW_PWRDN_CFG0_SEQ_ENABLE;
writel_relaxed(reg, clk_base + PLLU_HW_PWRDN_CFG0);
udelay(1);
reg = readl_relaxed(clk_base + PLLU_BASE);
reg &= ~PLLU_BASE_CLKENABLE_USB;
writel_relaxed(reg, clk_base + PLLU_BASE);
}
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
if (!(reg & UTMIPLL_HW_PWRDN_CFG0_SEQ_ENABLE))
tegra210_utmi_param_configure();
return 0;
}
static __init void tegra210_periph_clk_init(void __iomem *clk_base,
void __iomem *pmc_base)
{
struct clk *clk;
clk = clk_register_fixed_factor(NULL, "xusb_ss_div2", "xusb_ss_src", 0,
1, 2);
clks[TEGRA210_CLK_XUSB_SS_DIV2] = clk;
clk = tegra_clk_register_periph_fixed("sor_safe", "pll_p", 0, clk_base,
1, 17, 222);
clks[TEGRA210_CLK_SOR_SAFE] = clk;
clk = tegra_clk_register_periph_fixed("dpaux", "sor_safe", 0, clk_base,
1, 17, 181);
clks[TEGRA210_CLK_DPAUX] = clk;
clk = tegra_clk_register_periph_fixed("dpaux1", "sor_safe", 0, clk_base,
1, 17, 207);
clks[TEGRA210_CLK_DPAUX1] = clk;
clk = clk_register_gate(NULL, "pll_d_dsi_out", "pll_d_out0", 0,
clk_base + PLLD_MISC0, 21, 0, &pll_d_lock);
clks[TEGRA210_CLK_PLL_D_DSI_OUT] = clk;
clk = tegra_clk_register_periph_gate("dsia", "pll_d_dsi_out", 0,
clk_base, 0, 48,
periph_clk_enb_refcnt);
clks[TEGRA210_CLK_DSIA] = clk;
clk = tegra_clk_register_periph_gate("dsib", "pll_d_dsi_out", 0,
clk_base, 0, 82,
periph_clk_enb_refcnt);
clks[TEGRA210_CLK_DSIB] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm), 0,
clk_base + CLK_SOURCE_EMC,
29, 3, 0, &emc_lock);
clk = tegra_clk_register_mc("mc", "emc_mux", clk_base + CLK_SOURCE_EMC,
&emc_lock);
clks[TEGRA210_CLK_MC] = clk;
clk = clk_register_gate(NULL, "cml0", "pll_e", 0, clk_base + PLLE_AUX,
0, 0, &pll_e_lock);
clk_register_clkdev(clk, "cml0", NULL);
clks[TEGRA210_CLK_CML0] = clk;
clk = clk_register_gate(NULL, "cml1", "pll_e", 0, clk_base + PLLE_AUX,
1, 0, &pll_e_lock);
clk_register_clkdev(clk, "cml1", NULL);
clks[TEGRA210_CLK_CML1] = clk;
clk = tegra_clk_register_super_clk("aclk", aclk_parents,
ARRAY_SIZE(aclk_parents), 0, clk_base + 0x6e0,
0, NULL);
clks[TEGRA210_CLK_ACLK] = clk;
tegra_periph_clk_init(clk_base, pmc_base, tegra210_clks, &pll_p_params);
}
static void __init tegra210_pll_init(void __iomem *clk_base,
void __iomem *pmc)
{
struct clk *clk;
clk = tegra_clk_register_pllc_tegra210("pll_c", "pll_ref", clk_base,
pmc, 0, &pll_c_params, NULL);
if (!WARN_ON(IS_ERR(clk)))
clk_register_clkdev(clk, "pll_c", NULL);
clks[TEGRA210_CLK_PLL_C] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0,
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_c_out1", NULL);
clks[TEGRA210_CLK_PLL_C_OUT1] = clk;
clk = clk_register_fixed_factor(NULL, "pll_c_ud", "pll_c",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "pll_c_ud", NULL);
clks[TEGRA210_CLK_PLL_C_UD] = clk;
clk = tegra_clk_register_pllc_tegra210("pll_c2", "pll_ref", clk_base,
pmc, 0, &pll_c2_params, NULL);
clk_register_clkdev(clk, "pll_c2", NULL);
clks[TEGRA210_CLK_PLL_C2] = clk;
clk = tegra_clk_register_pllc_tegra210("pll_c3", "pll_ref", clk_base,
pmc, 0, &pll_c3_params, NULL);
clk_register_clkdev(clk, "pll_c3", NULL);
clks[TEGRA210_CLK_PLL_C3] = clk;
clk = tegra_clk_register_pllm("pll_m", "osc", clk_base, pmc,
CLK_SET_RATE_GATE, &pll_m_params, NULL);
clk_register_clkdev(clk, "pll_m", NULL);
clks[TEGRA210_CLK_PLL_M] = clk;
clk = tegra_clk_register_pllmb("pll_mb", "osc", clk_base, pmc,
CLK_SET_RATE_GATE, &pll_mb_params, NULL);
clk_register_clkdev(clk, "pll_mb", NULL);
clks[TEGRA210_CLK_PLL_MB] = clk;
clk = clk_register_fixed_factor(NULL, "pll_m_ud", "pll_m",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "pll_m_ud", NULL);
clks[TEGRA210_CLK_PLL_M_UD] = clk;
if (!tegra210_init_pllu()) {
clk = clk_register_fixed_rate(NULL, "pll_u_vco", "pll_ref", 0,
480*1000*1000);
clk_register_clkdev(clk, "pll_u_vco", NULL);
clks[TEGRA210_CLK_PLL_U] = clk;
}
clk = clk_register_divider_table(NULL, "pll_u_out", "pll_u_vco", 0,
clk_base + PLLU_BASE, 16, 4, 0,
pll_vco_post_div_table, NULL);
clk_register_clkdev(clk, "pll_u_out", NULL);
clks[TEGRA210_CLK_PLL_U_OUT] = clk;
clk = tegra_clk_register_divider("pll_u_out1_div", "pll_u_out",
clk_base + PLLU_OUTA, 0,
TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, &pll_u_lock);
clk = tegra_clk_register_pll_out("pll_u_out1", "pll_u_out1_div",
clk_base + PLLU_OUTA, 1, 0,
CLK_SET_RATE_PARENT, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_out1", NULL);
clks[TEGRA210_CLK_PLL_U_OUT1] = clk;
clk = tegra_clk_register_divider("pll_u_out2_div", "pll_u_out",
clk_base + PLLU_OUTA, 0,
TEGRA_DIVIDER_ROUND_UP,
24, 8, 1, &pll_u_lock);
clk = tegra_clk_register_pll_out("pll_u_out2", "pll_u_out2_div",
clk_base + PLLU_OUTA, 17, 16,
CLK_SET_RATE_PARENT, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_out2", NULL);
clks[TEGRA210_CLK_PLL_U_OUT2] = clk;
clk = clk_register_gate(NULL, "pll_u_480M", "pll_u_vco",
CLK_SET_RATE_PARENT, clk_base + PLLU_BASE,
22, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_480M", NULL);
clks[TEGRA210_CLK_PLL_U_480M] = clk;
clk = clk_register_gate(NULL, "pll_u_60M", "pll_u_out2",
CLK_SET_RATE_PARENT, clk_base + PLLU_BASE,
23, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_60M", NULL);
clks[TEGRA210_CLK_PLL_U_60M] = clk;
clk = clk_register_gate(NULL, "pll_u_48M", "pll_u_out1",
CLK_SET_RATE_PARENT, clk_base + PLLU_BASE,
25, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_48M", NULL);
clks[TEGRA210_CLK_PLL_U_48M] = clk;
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, pmc, 0,
&pll_d_params, &pll_d_lock);
clk_register_clkdev(clk, "pll_d", NULL);
clks[TEGRA210_CLK_PLL_D] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d_out0", NULL);
clks[TEGRA210_CLK_PLL_D_OUT0] = clk;
clk = tegra_clk_register_pllre_tegra210("pll_re_vco", "pll_ref",
clk_base, pmc, 0,
&pll_re_vco_params,
&pll_re_lock, pll_ref_freq);
clk_register_clkdev(clk, "pll_re_vco", NULL);
clks[TEGRA210_CLK_PLL_RE_VCO] = clk;
clk = clk_register_divider_table(NULL, "pll_re_out", "pll_re_vco", 0,
clk_base + PLLRE_BASE, 16, 5, 0,
pll_vco_post_div_table, &pll_re_lock);
clk_register_clkdev(clk, "pll_re_out", NULL);
clks[TEGRA210_CLK_PLL_RE_OUT] = clk;
clk = tegra_clk_register_divider("pll_re_out1_div", "pll_re_vco",
clk_base + PLLRE_OUT1, 0,
TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_re_out1", "pll_re_out1_div",
clk_base + PLLRE_OUT1, 1, 0,
CLK_SET_RATE_PARENT, 0, NULL);
clks[TEGRA210_CLK_PLL_RE_OUT1] = clk;
clk = tegra_clk_register_plle_tegra210("pll_e", "pll_ref",
clk_base, 0, &pll_e_params, NULL);
clk_register_clkdev(clk, "pll_e", NULL);
clks[TEGRA210_CLK_PLL_E] = clk;
clk = tegra_clk_register_pllre("pll_c4_vco", "pll_ref", clk_base, pmc,
0, &pll_c4_vco_params, NULL, pll_ref_freq);
clk_register_clkdev(clk, "pll_c4_vco", NULL);
clks[TEGRA210_CLK_PLL_C4] = clk;
clk = clk_register_divider_table(NULL, "pll_c4_out0", "pll_c4_vco", 0,
clk_base + PLLC4_BASE, 19, 4, 0,
pll_vco_post_div_table, NULL);
clk_register_clkdev(clk, "pll_c4_out0", NULL);
clks[TEGRA210_CLK_PLL_C4_OUT0] = clk;
clk = clk_register_fixed_factor(NULL, "pll_c4_out1", "pll_c4_vco",
CLK_SET_RATE_PARENT, 1, 3);
clk_register_clkdev(clk, "pll_c4_out1", NULL);
clks[TEGRA210_CLK_PLL_C4_OUT1] = clk;
clk = clk_register_fixed_factor(NULL, "pll_c4_out2", "pll_c4_vco",
CLK_SET_RATE_PARENT, 1, 5);
clk_register_clkdev(clk, "pll_c4_out2", NULL);
clks[TEGRA210_CLK_PLL_C4_OUT2] = clk;
clk = tegra_clk_register_divider("pll_c4_out3_div", "pll_c4_out0",
clk_base + PLLC4_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c4_out3", "pll_c4_out3_div",
clk_base + PLLC4_OUT, 1, 0,
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_c4_out3", NULL);
clks[TEGRA210_CLK_PLL_C4_OUT3] = clk;
clk = tegra_clk_register_pllss_tegra210("pll_dp", "pll_ref", clk_base,
0, &pll_dp_params, NULL);
clk_register_clkdev(clk, "pll_dp", NULL);
clks[TEGRA210_CLK_PLL_DP] = clk;
clk = tegra_clk_register_pllss_tegra210("pll_d2", "pll_ref", clk_base,
0, &pll_d2_params, NULL);
clk_register_clkdev(clk, "pll_d2", NULL);
clks[TEGRA210_CLK_PLL_D2] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d2_out0", "pll_d2",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "pll_d2_out0", NULL);
clks[TEGRA210_CLK_PLL_D2_OUT0] = clk;
clk = clk_register_fixed_factor(NULL, "pll_p_out2", "pll_p",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_p_out2", NULL);
clks[TEGRA210_CLK_PLL_P_OUT2] = clk;
}
static void tegra210_wait_cpu_in_reset(u32 cpu)
{
unsigned int reg;
do {
reg = readl(clk_base + CLK_RST_CONTROLLER_CPU_CMPLX_STATUS);
cpu_relax();
} while (!(reg & (1 << cpu)));
}
static void tegra210_disable_cpu_clock(u32 cpu)
{
}
static void tegra210_cpu_clock_suspend(void)
{
tegra210_cpu_clk_sctx.clk_csite_src =
readl(clk_base + CLK_SOURCE_CSITE);
writel(3 << 30, clk_base + CLK_SOURCE_CSITE);
}
static void tegra210_cpu_clock_resume(void)
{
writel(tegra210_cpu_clk_sctx.clk_csite_src,
clk_base + CLK_SOURCE_CSITE);
}
static void __init tegra210_clock_apply_init_table(void)
{
tegra_init_from_table(init_table, clks, TEGRA210_CLK_CLK_MAX);
}
static void tegra210_car_barrier(void)
{
readl_relaxed(clk_base + RST_DFLL_DVCO);
}
static void tegra210_clock_assert_dfll_dvco_reset(void)
{
u32 v;
v = readl_relaxed(clk_base + RST_DFLL_DVCO);
v |= (1 << DVFS_DFLL_RESET_SHIFT);
writel_relaxed(v, clk_base + RST_DFLL_DVCO);
tegra210_car_barrier();
}
static void tegra210_clock_deassert_dfll_dvco_reset(void)
{
u32 v;
v = readl_relaxed(clk_base + RST_DFLL_DVCO);
v &= ~(1 << DVFS_DFLL_RESET_SHIFT);
writel_relaxed(v, clk_base + RST_DFLL_DVCO);
tegra210_car_barrier();
}
static int tegra210_reset_assert(unsigned long id)
{
if (id == TEGRA210_RST_DFLL_DVCO)
tegra210_clock_assert_dfll_dvco_reset();
else if (id == TEGRA210_RST_ADSP)
writel(GENMASK(26, 21) | BIT(7),
clk_base + CLK_RST_CONTROLLER_RST_DEV_Y_SET);
else
return -EINVAL;
return 0;
}
static int tegra210_reset_deassert(unsigned long id)
{
if (id == TEGRA210_RST_DFLL_DVCO)
tegra210_clock_deassert_dfll_dvco_reset();
else if (id == TEGRA210_RST_ADSP) {
writel(BIT(21), clk_base + CLK_RST_CONTROLLER_RST_DEV_Y_CLR);
udelay(5);
writel(GENMASK(26, 22) | BIT(7),
clk_base + CLK_RST_CONTROLLER_RST_DEV_Y_CLR);
} else
return -EINVAL;
return 0;
}
static void __init tegra210_clock_init(struct device_node *np)
{
struct device_node *node;
u32 value, clk_m_div;
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("ioremap tegra210 CAR failed\n");
return;
}
node = of_find_matching_node(NULL, pmc_match);
if (!node) {
pr_err("Failed to find pmc node\n");
WARN_ON(1);
return;
}
pmc_base = of_iomap(node, 0);
if (!pmc_base) {
pr_err("Can't map pmc registers\n");
WARN_ON(1);
return;
}
clks = tegra_clk_init(clk_base, TEGRA210_CLK_CLK_MAX,
TEGRA210_CAR_BANK_COUNT);
if (!clks)
return;
value = clk_readl(clk_base + SPARE_REG0) >> CLK_M_DIVISOR_SHIFT;
clk_m_div = (value & CLK_M_DIVISOR_MASK) + 1;
if (tegra_osc_clk_init(clk_base, tegra210_clks, tegra210_input_freq,
ARRAY_SIZE(tegra210_input_freq), clk_m_div,
&osc_freq, &pll_ref_freq) < 0)
return;
tegra_fixed_clk_init(tegra210_clks);
tegra210_pll_init(clk_base, pmc_base);
tegra210_periph_clk_init(clk_base, pmc_base);
tegra_audio_clk_init(clk_base, pmc_base, tegra210_clks,
tegra210_audio_plls,
ARRAY_SIZE(tegra210_audio_plls));
tegra_pmc_clk_init(pmc_base, tegra210_clks);
value = clk_readl(clk_base + PLLD_BASE);
value &= ~BIT(25);
clk_writel(value, clk_base + PLLD_BASE);
tegra_clk_apply_init_table = tegra210_clock_apply_init_table;
tegra_super_clk_gen5_init(clk_base, pmc_base, tegra210_clks,
&pll_x_params);
tegra_init_special_resets(2, tegra210_reset_assert,
tegra210_reset_deassert);
tegra_add_of_provider(np);
tegra_register_devclks(devclks, ARRAY_SIZE(devclks));
tegra_cpu_car_ops = &tegra210_cpu_car_ops;
}
