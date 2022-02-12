static int berlin2_avpll_vco_is_enabled(struct clk_hw *hw)
{
struct berlin2_avpll_vco *vco = to_avpll_vco(hw);
u32 reg;
reg = readl_relaxed(vco->base + VCO_CTRL0);
if (vco->flags & BERLIN2_AVPLL_BIT_QUIRK)
reg >>= 4;
return !!(reg & VCO_POWERUP);
}
static int berlin2_avpll_vco_enable(struct clk_hw *hw)
{
struct berlin2_avpll_vco *vco = to_avpll_vco(hw);
u32 reg;
reg = readl_relaxed(vco->base + VCO_CTRL0);
if (vco->flags & BERLIN2_AVPLL_BIT_QUIRK)
reg |= VCO_POWERUP << 4;
else
reg |= VCO_POWERUP;
writel_relaxed(reg, vco->base + VCO_CTRL0);
return 0;
}
static void berlin2_avpll_vco_disable(struct clk_hw *hw)
{
struct berlin2_avpll_vco *vco = to_avpll_vco(hw);
u32 reg;
reg = readl_relaxed(vco->base + VCO_CTRL0);
if (vco->flags & BERLIN2_AVPLL_BIT_QUIRK)
reg &= ~(VCO_POWERUP << 4);
else
reg &= ~VCO_POWERUP;
writel_relaxed(reg, vco->base + VCO_CTRL0);
}
static unsigned long
berlin2_avpll_vco_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct berlin2_avpll_vco *vco = to_avpll_vco(hw);
u32 reg, refdiv, fbdiv;
u64 freq = parent_rate;
reg = readl_relaxed(vco->base + VCO_CTRL1);
refdiv = (reg & VCO_REFDIV_MASK) >> VCO_REFDIV_SHIFT;
refdiv = vco_refdiv[refdiv];
fbdiv = (reg & VCO_FBDIV_MASK) >> VCO_FBDIV_SHIFT;
freq *= fbdiv;
do_div(freq, refdiv);
return (unsigned long)freq;
}
struct clk * __init berlin2_avpll_vco_register(void __iomem *base,
const char *name, const char *parent_name,
u8 vco_flags, unsigned long flags)
{
struct berlin2_avpll_vco *vco;
struct clk_init_data init;
vco = kzalloc(sizeof(*vco), GFP_KERNEL);
if (!vco)
return ERR_PTR(-ENOMEM);
vco->base = base;
vco->flags = vco_flags;
vco->hw.init = &init;
init.name = name;
init.ops = &berlin2_avpll_vco_ops;
init.parent_names = &parent_name;
init.num_parents = 1;
init.flags = flags;
return clk_register(NULL, &vco->hw);
}
static int berlin2_avpll_channel_is_enabled(struct clk_hw *hw)
{
struct berlin2_avpll_channel *ch = to_avpll_channel(hw);
u32 reg;
if (ch->index == 7)
return 1;
reg = readl_relaxed(ch->base + VCO_CTRL10);
reg &= VCO_POWERUP_CH1 << ch->index;
return !!reg;
}
static int berlin2_avpll_channel_enable(struct clk_hw *hw)
{
struct berlin2_avpll_channel *ch = to_avpll_channel(hw);
u32 reg;
reg = readl_relaxed(ch->base + VCO_CTRL10);
reg |= VCO_POWERUP_CH1 << ch->index;
writel_relaxed(reg, ch->base + VCO_CTRL10);
return 0;
}
static void berlin2_avpll_channel_disable(struct clk_hw *hw)
{
struct berlin2_avpll_channel *ch = to_avpll_channel(hw);
u32 reg;
reg = readl_relaxed(ch->base + VCO_CTRL10);
reg &= ~(VCO_POWERUP_CH1 << ch->index);
writel_relaxed(reg, ch->base + VCO_CTRL10);
}
static unsigned long
berlin2_avpll_channel_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct berlin2_avpll_channel *ch = to_avpll_channel(hw);
u32 reg, div_av2, div_av3, divider = 1;
u64 freq = parent_rate;
reg = readl_relaxed(ch->base + VCO_CTRL30);
if ((reg & (VCO_DPLL_CH1_ENABLE << ch->index)) == 0)
goto skip_div;
reg = readl_relaxed(ch->base + VCO_SYNC1n(ch->index));
if (ch->flags & BERLIN2_AVPLL_BIT_QUIRK && ch->index == 0)
reg >>= 4;
divider = reg & VCO_SYNC1_MASK;
reg = readl_relaxed(ch->base + VCO_SYNC2n(ch->index));
freq *= reg & VCO_SYNC2_MASK;
if (ch->index == 7)
goto skip_div;
reg = readl_relaxed(ch->base + VCO_CTRL11) >> 7;
reg = (reg >> (ch->index * 3));
if (reg & BIT(2))
divider *= div_hdmi[reg & 0x3];
if (ch->index == 0) {
reg = readl_relaxed(ch->base + VCO_CTRL11);
reg >>= 28;
} else {
reg = readl_relaxed(ch->base + VCO_CTRL12);
reg >>= (ch->index-1) * 3;
}
if (reg & BIT(2))
divider *= div_av1[reg & 0x3];
if (ch->index < 2) {
reg = readl_relaxed(ch->base + VCO_CTRL12);
reg >>= 18 + (ch->index * 7);
} else if (ch->index < 7) {
reg = readl_relaxed(ch->base + VCO_CTRL13);
reg >>= (ch->index - 2) * 7;
} else {
reg = readl_relaxed(ch->base + VCO_CTRL14);
}
div_av2 = reg & 0x7f;
if (div_av2)
divider *= div_av2;
if (ch->index < 6) {
reg = readl_relaxed(ch->base + VCO_CTRL14);
reg >>= 7 + (ch->index * 4);
} else {
reg = readl_relaxed(ch->base + VCO_CTRL15);
}
div_av3 = reg & 0xf;
if (div_av2 && div_av3)
freq *= 2;
skip_div:
do_div(freq, divider);
return (unsigned long)freq;
}
struct clk * __init berlin2_avpll_channel_register(void __iomem *base,
const char *name, u8 index, const char *parent_name,
u8 ch_flags, unsigned long flags)
{
struct berlin2_avpll_channel *ch;
struct clk_init_data init;
ch = kzalloc(sizeof(*ch), GFP_KERNEL);
if (!ch)
return ERR_PTR(-ENOMEM);
ch->base = base;
if (ch_flags & BERLIN2_AVPLL_SCRAMBLE_QUIRK)
ch->index = quirk_index[index];
else
ch->index = index;
ch->flags = ch_flags;
ch->hw.init = &init;
init.name = name;
init.ops = &berlin2_avpll_channel_ops;
init.parent_names = &parent_name;
init.num_parents = 1;
init.flags = flags;
return clk_register(NULL, &ch->hw);
}
