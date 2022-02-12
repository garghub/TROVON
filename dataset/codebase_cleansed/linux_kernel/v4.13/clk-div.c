static inline struct clk_div *to_clk_div(struct clk_hw *hw)
{
struct clk_divider *divider = to_clk_divider(hw);
return container_of(divider, struct clk_div, divider);
}
static unsigned long clk_div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_div *div = to_clk_div(hw);
return div->ops->recalc_rate(&div->divider.hw, parent_rate);
}
static long clk_div_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_div *div = to_clk_div(hw);
return div->ops->round_rate(&div->divider.hw, rate, prate);
}
static int clk_div_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_div *div = to_clk_div(hw);
int ret;
ret = div->ops->set_rate(&div->divider.hw, rate, parent_rate);
if (!ret)
ret = mxs_clk_wait(div->reg, div->busy);
return ret;
}
struct clk *mxs_clk_div(const char *name, const char *parent_name,
void __iomem *reg, u8 shift, u8 width, u8 busy)
{
struct clk_div *div;
struct clk *clk;
struct clk_init_data init;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &clk_div_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
div->reg = reg;
div->busy = busy;
div->divider.reg = reg;
div->divider.shift = shift;
div->divider.width = width;
div->divider.flags = CLK_DIVIDER_ONE_BASED;
div->divider.lock = &mxs_lock;
div->divider.hw.init = &init;
div->ops = &clk_divider_ops;
clk = clk_register(NULL, &div->divider.hw);
if (IS_ERR(clk))
kfree(div);
return clk;
}
