static void syscon_block_reset_enable(struct clk_syscon *sclk)
{
unsigned long iflags;
u16 val;
if (!sclk->res_reg)
return;
spin_lock_irqsave(&syscon_resetreg_lock, iflags);
val = readw(sclk->res_reg);
val |= BIT(sclk->res_bit);
writew(val, sclk->res_reg);
spin_unlock_irqrestore(&syscon_resetreg_lock, iflags);
sclk->reset = true;
}
static void syscon_block_reset_disable(struct clk_syscon *sclk)
{
unsigned long iflags;
u16 val;
if (!sclk->res_reg)
return;
spin_lock_irqsave(&syscon_resetreg_lock, iflags);
val = readw(sclk->res_reg);
val &= ~BIT(sclk->res_bit);
writew(val, sclk->res_reg);
spin_unlock_irqrestore(&syscon_resetreg_lock, iflags);
sclk->reset = false;
}
static int syscon_clk_prepare(struct clk_hw *hw)
{
struct clk_syscon *sclk = to_syscon(hw);
if (sclk->reset)
syscon_block_reset_disable(sclk);
return 0;
}
static void syscon_clk_unprepare(struct clk_hw *hw)
{
struct clk_syscon *sclk = to_syscon(hw);
if (sclk->clk_val == U300_SYSCON_SBCER_UART_CLK_EN)
return;
if (!sclk->reset)
syscon_block_reset_enable(sclk);
}
static int syscon_clk_enable(struct clk_hw *hw)
{
struct clk_syscon *sclk = to_syscon(hw);
if (sclk->hw_ctrld)
return 0;
if (sclk->clk_val == 0xFFFFU)
return 0;
writew(sclk->clk_val, syscon_vbase + U300_SYSCON_SBCER);
return 0;
}
static void syscon_clk_disable(struct clk_hw *hw)
{
struct clk_syscon *sclk = to_syscon(hw);
if (sclk->hw_ctrld)
return;
if (sclk->clk_val == 0xFFFFU)
return;
if (sclk->clk_val == U300_SYSCON_SBCER_UART_CLK_EN)
return;
writew(sclk->clk_val, syscon_vbase + U300_SYSCON_SBCDR);
}
static int syscon_clk_is_enabled(struct clk_hw *hw)
{
struct clk_syscon *sclk = to_syscon(hw);
u16 val;
if (!sclk->en_reg)
return 1;
val = readw(sclk->en_reg);
val &= BIT(sclk->en_bit);
return val ? 1 : 0;
}
static u16 syscon_get_perf(void)
{
u16 val;
val = readw(syscon_vbase + U300_SYSCON_CCR);
val &= U300_SYSCON_CCR_CLKING_PERFORMANCE_MASK;
return val;
}
static unsigned long
syscon_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_syscon *sclk = to_syscon(hw);
u16 perf = syscon_get_perf();
switch(sclk->clk_val) {
case U300_SYSCON_SBCER_FAST_BRIDGE_CLK_EN:
case U300_SYSCON_SBCER_I2C0_CLK_EN:
case U300_SYSCON_SBCER_I2C1_CLK_EN:
case U300_SYSCON_SBCER_MMC_CLK_EN:
case U300_SYSCON_SBCER_SPI_CLK_EN:
switch(perf) {
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW:
return 13000000;
default:
return parent_rate;
}
case U300_SYSCON_SBCER_DMAC_CLK_EN:
case U300_SYSCON_SBCER_NANDIF_CLK_EN:
case U300_SYSCON_SBCER_XGAM_CLK_EN:
switch(perf) {
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW:
return 6500000;
case U300_SYSCON_CCR_CLKING_PERFORMANCE_INTERMEDIATE:
return 26000000;
default:
return parent_rate;
}
case U300_SYSCON_SBCER_SEMI_CLK_EN:
case U300_SYSCON_SBCER_EMIF_CLK_EN:
switch(perf) {
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW:
return 13000000;
case U300_SYSCON_CCR_CLKING_PERFORMANCE_INTERMEDIATE:
return 52000000;
default:
return 104000000;
}
case U300_SYSCON_SBCER_CPU_CLK_EN:
switch(perf) {
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW:
return 13000000;
case U300_SYSCON_CCR_CLKING_PERFORMANCE_INTERMEDIATE:
return 52000000;
case U300_SYSCON_CCR_CLKING_PERFORMANCE_HIGH:
return 104000000;
default:
return parent_rate;
}
default:
return parent_rate;
}
}
static long
syscon_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_syscon *sclk = to_syscon(hw);
if (sclk->clk_val != U300_SYSCON_SBCER_CPU_CLK_EN)
return *prate;
if (rate <= 13000000)
return 13000000;
if (rate <= 52000000)
return 52000000;
if (rate <= 104000000)
return 104000000;
return 208000000;
}
static int syscon_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_syscon *sclk = to_syscon(hw);
u16 val;
if (sclk->clk_val != U300_SYSCON_SBCER_CPU_CLK_EN)
return -EINVAL;
switch (rate) {
case 13000000:
val = U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER;
break;
case 52000000:
val = U300_SYSCON_CCR_CLKING_PERFORMANCE_INTERMEDIATE;
break;
case 104000000:
val = U300_SYSCON_CCR_CLKING_PERFORMANCE_HIGH;
break;
case 208000000:
val = U300_SYSCON_CCR_CLKING_PERFORMANCE_BEST;
break;
default:
return -EINVAL;
}
val |= readw(syscon_vbase + U300_SYSCON_CCR) &
~U300_SYSCON_CCR_CLKING_PERFORMANCE_MASK ;
writew(val, syscon_vbase + U300_SYSCON_CCR);
return 0;
}
static struct clk * __init
syscon_clk_register(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
bool hw_ctrld,
void __iomem *res_reg, u8 res_bit,
void __iomem *en_reg, u8 en_bit,
u16 clk_val)
{
struct clk *clk;
struct clk_syscon *sclk;
struct clk_init_data init;
sclk = kzalloc(sizeof(struct clk_syscon), GFP_KERNEL);
if (!sclk) {
pr_err("could not allocate syscon clock %s\n",
name);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &syscon_clk_ops;
init.flags = flags;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
sclk->hw.init = &init;
sclk->hw_ctrld = hw_ctrld;
sclk->reset = true;
sclk->res_reg = res_reg;
sclk->res_bit = res_bit;
sclk->en_reg = en_reg;
sclk->en_bit = en_bit;
sclk->clk_val = clk_val;
clk = clk_register(dev, &sclk->hw);
if (IS_ERR(clk))
kfree(sclk);
return clk;
}
static void __init of_u300_syscon_clk_init(struct device_node *np)
{
struct clk *clk = ERR_PTR(-EINVAL);
const char *clk_name = np->name;
const char *parent_name;
void __iomem *res_reg;
void __iomem *en_reg;
u32 clk_type;
u32 clk_id;
int i;
if (of_property_read_u32(np, "clock-type", &clk_type)) {
pr_err("%s: syscon clock \"%s\" missing clock-type property\n",
__func__, clk_name);
return;
}
if (of_property_read_u32(np, "clock-id", &clk_id)) {
pr_err("%s: syscon clock \"%s\" missing clock-id property\n",
__func__, clk_name);
return;
}
parent_name = of_clk_get_parent_name(np, 0);
switch (clk_type) {
case U300_CLK_TYPE_SLOW:
res_reg = syscon_vbase + U300_SYSCON_RSR;
en_reg = syscon_vbase + U300_SYSCON_CESR;
break;
case U300_CLK_TYPE_FAST:
res_reg = syscon_vbase + U300_SYSCON_RFR;
en_reg = syscon_vbase + U300_SYSCON_CEFR;
break;
case U300_CLK_TYPE_REST:
res_reg = syscon_vbase + U300_SYSCON_RRR;
en_reg = syscon_vbase + U300_SYSCON_CERR;
break;
default:
pr_err("unknown clock type %x specified\n", clk_type);
return;
}
for (i = 0; i < ARRAY_SIZE(u300_clk_lookup); i++) {
const struct u300_clock *u3clk = &u300_clk_lookup[i];
if (u3clk->type == clk_type && u3clk->id == clk_id)
clk = syscon_clk_register(NULL,
clk_name, parent_name,
0, u3clk->hw_ctrld,
res_reg, u3clk->id,
en_reg, u3clk->id,
u3clk->clk_val);
}
if (!IS_ERR(clk)) {
of_clk_add_provider(np, of_clk_src_simple_get, clk);
if (clk_type == U300_CLK_TYPE_REST && clk_id == 5)
clk_register_clkdev(clk, NULL, "pl172");
if (clk_type == U300_CLK_TYPE_REST && clk_id == 9)
clk_register_clkdev(clk, NULL, "semi");
if (clk_type == U300_CLK_TYPE_REST && clk_id == 12)
clk_register_clkdev(clk, NULL, "intcon");
}
}
static int mclk_clk_prepare(struct clk_hw *hw)
{
struct clk_mclk *mclk = to_mclk(hw);
u16 val;
if (!mclk->is_mspro) {
writew(0x0054U, syscon_vbase + U300_SYSCON_MMF0R);
val = readw(syscon_vbase + U300_SYSCON_MMCR);
val &= ~U300_SYSCON_MMCR_MMC_FB_CLK_SEL_ENABLE;
val &= ~U300_SYSCON_MMCR_MSPRO_FREQSEL_ENABLE;
writew(val, syscon_vbase + U300_SYSCON_MMCR);
} else {
val = readw(syscon_vbase + U300_SYSCON_MMCR);
val &= ~U300_SYSCON_MMCR_MMC_FB_CLK_SEL_ENABLE;
val |= U300_SYSCON_MMCR_MSPRO_FREQSEL_ENABLE;
writew(val, syscon_vbase + U300_SYSCON_MMCR);
}
return 0;
}
static unsigned long
mclk_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u16 perf = syscon_get_perf();
switch (perf) {
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER:
return 13000000;
case U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_INTERMEDIATE:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_HIGH:
case U300_SYSCON_CCR_CLKING_PERFORMANCE_BEST:
{
u16 val = readw(syscon_vbase + U300_SYSCON_MMF0R) &
U300_SYSCON_MMF0R_MASK;
switch (val) {
case 0x0054:
return 18900000;
case 0x0044:
return 20800000;
case 0x0043:
return 23100000;
case 0x0033:
return 26000000;
case 0x0032:
return 29700000;
case 0x0022:
return 34700000;
case 0x0021:
return 41600000;
case 0x0011:
return 52000000;
case 0x0000:
return 104000000;
default:
break;
}
}
default:
break;
}
return parent_rate;
}
static long
mclk_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
if (rate <= 18900000)
return 18900000;
if (rate <= 20800000)
return 20800000;
if (rate <= 23100000)
return 23100000;
if (rate <= 26000000)
return 26000000;
if (rate <= 29700000)
return 29700000;
if (rate <= 34700000)
return 34700000;
if (rate <= 41600000)
return 41600000;
return 52000000;
}
static int mclk_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
u16 val;
u16 reg;
switch (rate) {
case 18900000:
val = 0x0054;
break;
case 20800000:
val = 0x0044;
break;
case 23100000:
val = 0x0043;
break;
case 26000000:
val = 0x0033;
break;
case 29700000:
val = 0x0032;
break;
case 34700000:
val = 0x0022;
break;
case 41600000:
val = 0x0021;
break;
case 52000000:
val = 0x0011;
break;
case 104000000:
val = 0x0000;
break;
default:
return -EINVAL;
}
reg = readw(syscon_vbase + U300_SYSCON_MMF0R) &
~U300_SYSCON_MMF0R_MASK;
writew(reg | val, syscon_vbase + U300_SYSCON_MMF0R);
return 0;
}
static struct clk * __init
mclk_clk_register(struct device *dev, const char *name,
const char *parent_name, bool is_mspro)
{
struct clk *clk;
struct clk_mclk *mclk;
struct clk_init_data init;
mclk = kzalloc(sizeof(struct clk_mclk), GFP_KERNEL);
if (!mclk) {
pr_err("could not allocate MMC/SD clock %s\n",
name);
return ERR_PTR(-ENOMEM);
}
init.name = "mclk";
init.ops = &mclk_ops;
init.flags = 0;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
mclk->hw.init = &init;
mclk->is_mspro = is_mspro;
clk = clk_register(dev, &mclk->hw);
if (IS_ERR(clk))
kfree(mclk);
return clk;
}
static void __init of_u300_syscon_mclk_init(struct device_node *np)
{
struct clk *clk = ERR_PTR(-EINVAL);
const char *clk_name = np->name;
const char *parent_name;
parent_name = of_clk_get_parent_name(np, 0);
clk = mclk_clk_register(NULL, clk_name, parent_name, false);
if (!IS_ERR(clk))
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
void __init u300_clk_init(void __iomem *base)
{
u16 val;
syscon_vbase = base;
val = readw(syscon_vbase + U300_SYSCON_CCR);
val &= ~U300_SYSCON_CCR_CLKING_PERFORMANCE_MASK;
writew(val, syscon_vbase + U300_SYSCON_CCR);
while (!(readw(syscon_vbase + U300_SYSCON_CSR) &
U300_SYSCON_CSR_PLL208_LOCK_IND));
val = readw(syscon_vbase + U300_SYSCON_PMCR);
val |= U300_SYSCON_PMCR_PWR_MGNT_ENABLE;
writew(val, syscon_vbase + U300_SYSCON_PMCR);
of_clk_init(u300_clk_match);
}
