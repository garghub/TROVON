static unsigned int get_div(void __iomem *reg, int shift)
{
u32 val;
val = (readl(reg) >> shift) & 0x7;
if (val > 6)
return 0;
return val;
}
static unsigned long clk_double_div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_double_div *double_div = to_clk_double_div(hw);
unsigned int div;
div = get_div(double_div->reg1, double_div->shift1);
div *= get_div(double_div->reg2, double_div->shift2);
return DIV_ROUND_UP_ULL((u64)parent_rate, div);
}
static int armada_3700_add_composite_clk(const struct clk_periph_data *data,
void __iomem *reg, spinlock_t *lock,
struct device *dev, struct clk_hw **hw)
{
const struct clk_ops *mux_ops = NULL, *gate_ops = NULL,
*rate_ops = NULL;
struct clk_hw *mux_hw = NULL, *gate_hw = NULL, *rate_hw = NULL;
if (data->mux_hw) {
struct clk_mux *mux;
mux_hw = data->mux_hw;
mux = to_clk_mux(mux_hw);
mux->lock = lock;
mux_ops = mux_hw->init->ops;
mux->reg = reg + (u64)mux->reg;
}
if (data->gate_hw) {
struct clk_gate *gate;
gate_hw = data->gate_hw;
gate = to_clk_gate(gate_hw);
gate->lock = lock;
gate_ops = gate_hw->init->ops;
gate->reg = reg + (u64)gate->reg;
gate->flags = CLK_GATE_SET_TO_DISABLE;
}
if (data->rate_hw) {
rate_hw = data->rate_hw;
rate_ops = rate_hw->init->ops;
if (data->is_double_div) {
struct clk_double_div *rate;
rate = to_clk_double_div(rate_hw);
rate->reg1 = reg + (u64)rate->reg1;
rate->reg2 = reg + (u64)rate->reg2;
} else {
struct clk_divider *rate = to_clk_divider(rate_hw);
const struct clk_div_table *clkt;
int table_size = 0;
rate->reg = reg + (u64)rate->reg;
for (clkt = rate->table; clkt->div; clkt++)
table_size++;
rate->width = order_base_2(table_size);
rate->lock = lock;
}
}
*hw = clk_hw_register_composite(dev, data->name, data->parent_names,
data->num_parents, mux_hw,
mux_ops, rate_hw, rate_ops,
gate_hw, gate_ops, CLK_IGNORE_UNUSED);
if (IS_ERR(*hw))
return PTR_ERR(*hw);
return 0;
}
static int armada_3700_periph_clock_probe(struct platform_device *pdev)
{
struct clk_periph_driver_data *driver_data;
struct device_node *np = pdev->dev.of_node;
const struct clk_periph_data *data;
struct device *dev = &pdev->dev;
int num_periph = 0, i, ret;
struct resource *res;
void __iomem *reg;
data = of_device_get_match_data(dev);
if (!data)
return -ENODEV;
while (data[num_periph].name)
num_periph++;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
driver_data = devm_kzalloc(dev, sizeof(*driver_data), GFP_KERNEL);
if (!driver_data)
return -ENOMEM;
driver_data->hw_data = devm_kzalloc(dev, sizeof(*driver_data->hw_data) +
sizeof(*driver_data->hw_data->hws) * num_periph,
GFP_KERNEL);
if (!driver_data->hw_data)
return -ENOMEM;
driver_data->hw_data->num = num_periph;
spin_lock_init(&driver_data->lock);
for (i = 0; i < num_periph; i++) {
struct clk_hw **hw = &driver_data->hw_data->hws[i];
if (armada_3700_add_composite_clk(&data[i], reg,
&driver_data->lock, dev, hw))
dev_err(dev, "Can't register periph clock %s\n",
data[i].name);
}
ret = of_clk_add_hw_provider(np, of_clk_hw_onecell_get,
driver_data->hw_data);
if (ret) {
for (i = 0; i < num_periph; i++)
clk_hw_unregister(driver_data->hw_data->hws[i]);
return ret;
}
platform_set_drvdata(pdev, driver_data);
return 0;
}
static int armada_3700_periph_clock_remove(struct platform_device *pdev)
{
struct clk_periph_driver_data *data = platform_get_drvdata(pdev);
struct clk_hw_onecell_data *hw_data = data->hw_data;
int i;
of_clk_del_provider(pdev->dev.of_node);
for (i = 0; i < hw_data->num; i++)
clk_hw_unregister(hw_data->hws[i]);
return 0;
}
