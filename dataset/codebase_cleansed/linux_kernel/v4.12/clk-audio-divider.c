static int _div_round(unsigned long parent_rate, unsigned long rate,
unsigned long flags)
{
if (flags & CLK_DIVIDER_ROUND_CLOSEST)
return DIV_ROUND_CLOSEST_ULL((u64)parent_rate, rate);
return DIV_ROUND_UP_ULL((u64)parent_rate, rate);
}
static int _get_val(unsigned long parent_rate, unsigned long rate)
{
return DIV_ROUND_UP_ULL((u64)parent_rate, rate) - 1;
}
static int _valid_divider(struct clk_hw *hw, int divider)
{
struct meson_clk_audio_divider *adiv =
to_meson_clk_audio_divider(hw);
int max_divider;
u8 width;
width = adiv->div.width;
max_divider = 1 << width;
return clamp(divider, 1, max_divider);
}
static unsigned long audio_divider_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct meson_clk_audio_divider *adiv =
to_meson_clk_audio_divider(hw);
struct parm *p;
unsigned long reg, divider;
p = &adiv->div;
reg = readl(adiv->base + p->reg_off);
divider = PARM_GET(p->width, p->shift, reg) + 1;
return DIV_ROUND_UP_ULL((u64)parent_rate, divider);
}
static long audio_divider_round_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long *parent_rate)
{
struct meson_clk_audio_divider *adiv =
to_meson_clk_audio_divider(hw);
unsigned long max_prate;
int divider;
if (!(clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT)) {
divider = _div_round(*parent_rate, rate, adiv->flags);
divider = _valid_divider(hw, divider);
return DIV_ROUND_UP_ULL((u64)*parent_rate, divider);
}
max_prate = clk_hw_round_rate(clk_hw_get_parent(hw), ULONG_MAX);
divider = max_prate / rate;
divider = _valid_divider(hw, divider);
*parent_rate = clk_hw_round_rate(clk_hw_get_parent(hw),
divider * rate);
return DIV_ROUND_UP_ULL((u64)*parent_rate, divider);
}
static int audio_divider_set_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long parent_rate)
{
struct meson_clk_audio_divider *adiv =
to_meson_clk_audio_divider(hw);
struct parm *p;
unsigned long reg, flags = 0;
int val;
val = _get_val(parent_rate, rate);
if (adiv->lock)
spin_lock_irqsave(adiv->lock, flags);
else
__acquire(adiv->lock);
p = &adiv->div;
reg = readl(adiv->base + p->reg_off);
reg = PARM_SET(p->width, p->shift, reg, val);
writel(reg, adiv->base + p->reg_off);
if (adiv->lock)
spin_unlock_irqrestore(adiv->lock, flags);
else
__release(adiv->lock);
return 0;
}
