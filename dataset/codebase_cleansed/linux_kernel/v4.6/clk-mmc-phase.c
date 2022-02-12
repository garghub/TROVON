static unsigned long rockchip_mmc_recalc(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate / RK3288_MMC_CLKGEN_DIV;
}
static int rockchip_mmc_get_phase(struct clk_hw *hw)
{
struct rockchip_mmc_clock *mmc_clock = to_mmc_clock(hw);
unsigned long rate = clk_get_rate(hw->clk);
u32 raw_value;
u16 degrees;
u32 delay_num = 0;
raw_value = readl(mmc_clock->reg) >> (mmc_clock->shift);
degrees = (raw_value & ROCKCHIP_MMC_DEGREE_MASK) * 90;
if (raw_value & ROCKCHIP_MMC_DELAY_SEL) {
unsigned long factor = (ROCKCHIP_MMC_DELAY_ELEMENT_PSEC / 10) *
36 * (rate / 1000000);
delay_num = (raw_value & ROCKCHIP_MMC_DELAYNUM_MASK);
delay_num >>= ROCKCHIP_MMC_DELAYNUM_OFFSET;
degrees += DIV_ROUND_CLOSEST(delay_num * factor, 10000);
}
return degrees % 360;
}
static int rockchip_mmc_set_phase(struct clk_hw *hw, int degrees)
{
struct rockchip_mmc_clock *mmc_clock = to_mmc_clock(hw);
unsigned long rate = clk_get_rate(hw->clk);
u8 nineties, remainder;
u8 delay_num;
u32 raw_value;
u32 delay;
nineties = degrees / 90;
remainder = (degrees % 90);
delay = 10000000;
delay *= remainder;
delay = DIV_ROUND_CLOSEST(delay,
(rate / 1000) * 36 *
(ROCKCHIP_MMC_DELAY_ELEMENT_PSEC / 10));
delay_num = (u8) min_t(u32, delay, 255);
raw_value = delay_num ? ROCKCHIP_MMC_DELAY_SEL : 0;
raw_value |= delay_num << ROCKCHIP_MMC_DELAYNUM_OFFSET;
raw_value |= nineties;
writel(HIWORD_UPDATE(raw_value, 0x07ff, mmc_clock->shift), mmc_clock->reg);
pr_debug("%s->set_phase(%d) delay_nums=%u reg[0x%p]=0x%03x actual_degrees=%d\n",
clk_hw_get_name(hw), degrees, delay_num,
mmc_clock->reg, raw_value>>(mmc_clock->shift),
rockchip_mmc_get_phase(hw)
);
return 0;
}
struct clk *rockchip_clk_register_mmc(const char *name,
const char *const *parent_names, u8 num_parents,
void __iomem *reg, int shift)
{
struct clk_init_data init;
struct rockchip_mmc_clock *mmc_clock;
struct clk *clk;
mmc_clock = kmalloc(sizeof(*mmc_clock), GFP_KERNEL);
if (!mmc_clock)
return ERR_PTR(-ENOMEM);
init.name = name;
init.num_parents = num_parents;
init.parent_names = parent_names;
init.ops = &rockchip_mmc_clk_ops;
mmc_clock->hw.init = &init;
mmc_clock->reg = reg;
mmc_clock->shift = shift;
if (mmc_clock->shift == ROCKCHIP_MMC_INIT_STATE_SHIFT)
writel(HIWORD_UPDATE(ROCKCHIP_MMC_INIT_STATE_RESET,
ROCKCHIP_MMC_INIT_STATE_RESET,
mmc_clock->shift), mmc_clock->reg);
clk = clk_register(NULL, &mmc_clock->hw);
if (IS_ERR(clk))
kfree(mmc_clock);
return clk;
}
