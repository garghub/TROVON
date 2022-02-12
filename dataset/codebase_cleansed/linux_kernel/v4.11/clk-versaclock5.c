static bool vc5_regmap_is_writeable(struct device *dev, unsigned int reg)
{
if (reg <= 0xf)
return false;
if (reg == 0x14 || reg == 0x1c || reg == 0x1d)
return false;
return true;
}
static unsigned char vc5_mux_get_parent(struct clk_hw *hw)
{
struct vc5_driver_data *vc5 =
container_of(hw, struct vc5_driver_data, clk_mux);
const u8 mask = VC5_PRIM_SRC_SHDN_EN_XTAL | VC5_PRIM_SRC_SHDN_EN_CLKIN;
unsigned int src;
regmap_read(vc5->regmap, VC5_PRIM_SRC_SHDN, &src);
src &= mask;
if (src == VC5_PRIM_SRC_SHDN_EN_XTAL)
return 0;
if (src == VC5_PRIM_SRC_SHDN_EN_CLKIN)
return 1;
dev_warn(&vc5->client->dev,
"Invalid clock input configuration (%02x)\n", src);
return 0;
}
static int vc5_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct vc5_driver_data *vc5 =
container_of(hw, struct vc5_driver_data, clk_mux);
const u8 mask = VC5_PRIM_SRC_SHDN_EN_XTAL | VC5_PRIM_SRC_SHDN_EN_CLKIN;
u8 src;
if ((index > 1) || !vc5->clk_mux_ins)
return -EINVAL;
if (vc5->clk_mux_ins == (VC5_MUX_IN_CLKIN | VC5_MUX_IN_XIN)) {
if (index == 0)
src = VC5_PRIM_SRC_SHDN_EN_XTAL;
if (index == 1)
src = VC5_PRIM_SRC_SHDN_EN_CLKIN;
} else {
if (index != 0)
return -EINVAL;
if (vc5->clk_mux_ins == VC5_MUX_IN_XIN)
src = VC5_PRIM_SRC_SHDN_EN_XTAL;
if (vc5->clk_mux_ins == VC5_MUX_IN_CLKIN)
src = VC5_PRIM_SRC_SHDN_EN_CLKIN;
}
return regmap_update_bits(vc5->regmap, VC5_PRIM_SRC_SHDN, mask, src);
}
static unsigned long vc5_mux_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct vc5_driver_data *vc5 =
container_of(hw, struct vc5_driver_data, clk_mux);
unsigned int prediv, div;
regmap_read(vc5->regmap, VC5_VCO_CTRL_AND_PREDIV, &prediv);
if (prediv & VC5_VCO_CTRL_AND_PREDIV_BYPASS_PREDIV)
return parent_rate;
regmap_read(vc5->regmap, VC5_REF_DIVIDER, &div);
if (div & VC5_REF_DIVIDER_SEL_PREDIV2)
return parent_rate / 2;
else
return parent_rate / VC5_REF_DIVIDER_REF_DIV(div);
}
static long vc5_mux_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long idiv;
if (rate > 50000000)
return -EINVAL;
if (*parent_rate <= 50000000)
return *parent_rate;
idiv = DIV_ROUND_UP(*parent_rate, rate);
if (idiv > 127)
return -EINVAL;
return *parent_rate / idiv;
}
static int vc5_mux_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct vc5_driver_data *vc5 =
container_of(hw, struct vc5_driver_data, clk_mux);
unsigned long idiv;
u8 div;
if (parent_rate <= 50000000) {
regmap_update_bits(vc5->regmap, VC5_VCO_CTRL_AND_PREDIV,
VC5_VCO_CTRL_AND_PREDIV_BYPASS_PREDIV,
VC5_VCO_CTRL_AND_PREDIV_BYPASS_PREDIV);
regmap_update_bits(vc5->regmap, VC5_REF_DIVIDER, 0xff, 0x00);
return 0;
}
idiv = DIV_ROUND_UP(parent_rate, rate);
if (idiv == 2)
div = VC5_REF_DIVIDER_SEL_PREDIV2;
else
div = VC5_REF_DIVIDER_REF_DIV(idiv);
regmap_update_bits(vc5->regmap, VC5_REF_DIVIDER, 0xff, div);
regmap_update_bits(vc5->regmap, VC5_VCO_CTRL_AND_PREDIV,
VC5_VCO_CTRL_AND_PREDIV_BYPASS_PREDIV, 0);
return 0;
}
static unsigned long vc5_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
u32 div_int, div_frc;
u8 fb[5];
regmap_bulk_read(vc5->regmap, VC5_FEEDBACK_INT_DIV, fb, 5);
div_int = (fb[0] << 4) | (fb[1] >> 4);
div_frc = (fb[2] << 16) | (fb[3] << 8) | fb[4];
return (parent_rate * div_int) + ((parent_rate * div_frc) >> 24);
}
static long vc5_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
u32 div_int;
u64 div_frc;
if (rate < VC5_PLL_VCO_MIN)
rate = VC5_PLL_VCO_MIN;
if (rate > VC5_PLL_VCO_MAX)
rate = VC5_PLL_VCO_MAX;
div_int = rate / *parent_rate;
if (div_int > 0xfff)
rate = *parent_rate * 0xfff;
div_frc = rate % *parent_rate;
div_frc *= BIT(24) - 1;
do_div(div_frc, *parent_rate);
hwdata->div_int = div_int;
hwdata->div_frc = (u32)div_frc;
return (*parent_rate * div_int) + ((*parent_rate * div_frc) >> 24);
}
static int vc5_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
u8 fb[5];
fb[0] = hwdata->div_int >> 4;
fb[1] = hwdata->div_int << 4;
fb[2] = hwdata->div_frc >> 16;
fb[3] = hwdata->div_frc >> 8;
fb[4] = hwdata->div_frc;
return regmap_bulk_write(vc5->regmap, VC5_FEEDBACK_INT_DIV, fb, 5);
}
static unsigned long vc5_fod_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
u32 f_in = parent_rate / 2;
u32 div_int, div_frc;
u8 od_int[2];
u8 od_frc[4];
regmap_bulk_read(vc5->regmap, VC5_OUT_DIV_INT(hwdata->num, 0),
od_int, 2);
regmap_bulk_read(vc5->regmap, VC5_OUT_DIV_FRAC(hwdata->num, 0),
od_frc, 4);
div_int = (od_int[0] << 4) | (od_int[1] >> 4);
div_frc = (od_frc[0] << 22) | (od_frc[1] << 14) |
(od_frc[2] << 6) | (od_frc[3] >> 2);
return div64_u64((u64)f_in << 24ULL, ((u64)div_int << 24ULL) + div_frc);
}
static long vc5_fod_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
u32 f_in = *parent_rate / 2;
u32 div_int;
u64 div_frc;
div_int = f_in / rate;
if (div_int > 0xffe) {
div_int = 0xffe;
rate = f_in / div_int;
}
div_frc = f_in % rate;
div_frc <<= 24;
do_div(div_frc, rate);
hwdata->div_int = div_int;
hwdata->div_frc = (u32)div_frc;
return div64_u64((u64)f_in << 24ULL, ((u64)div_int << 24ULL) + div_frc);
}
static int vc5_fod_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
u8 data[14] = {
hwdata->div_frc >> 22, hwdata->div_frc >> 14,
hwdata->div_frc >> 6, hwdata->div_frc << 2,
0, 0, 0, 0, 0,
0, 0,
hwdata->div_int >> 4, hwdata->div_int << 4,
0
};
regmap_bulk_write(vc5->regmap, VC5_OUT_DIV_FRAC(hwdata->num, 0),
data, 14);
regmap_update_bits(vc5->regmap, VC5_GLOBAL_REGISTER,
VC5_GLOBAL_REGISTER_GLOBAL_RESET, 0);
regmap_update_bits(vc5->regmap, VC5_GLOBAL_REGISTER,
VC5_GLOBAL_REGISTER_GLOBAL_RESET,
VC5_GLOBAL_REGISTER_GLOBAL_RESET);
return 0;
}
static int vc5_clk_out_prepare(struct clk_hw *hw)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
regmap_update_bits(vc5->regmap, VC5_CLK_OUTPUT_CFG(hwdata->num, 1),
VC5_CLK_OUTPUT_CFG1_EN_CLKBUF,
VC5_CLK_OUTPUT_CFG1_EN_CLKBUF);
return 0;
}
static void vc5_clk_out_unprepare(struct clk_hw *hw)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
regmap_update_bits(vc5->regmap, VC5_CLK_OUTPUT_CFG(hwdata->num, 1),
VC5_CLK_OUTPUT_CFG1_EN_CLKBUF, 0);
}
static unsigned char vc5_clk_out_get_parent(struct clk_hw *hw)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
const u8 mask = VC5_OUT_DIV_CONTROL_SELB_NORM |
VC5_OUT_DIV_CONTROL_SEL_EXT |
VC5_OUT_DIV_CONTROL_EN_FOD;
const u8 fodclkmask = VC5_OUT_DIV_CONTROL_SELB_NORM |
VC5_OUT_DIV_CONTROL_EN_FOD;
const u8 extclk = VC5_OUT_DIV_CONTROL_SELB_NORM |
VC5_OUT_DIV_CONTROL_SEL_EXT;
unsigned int src;
regmap_read(vc5->regmap, VC5_OUT_DIV_CONTROL(hwdata->num), &src);
src &= mask;
if ((src & fodclkmask) == VC5_OUT_DIV_CONTROL_EN_FOD)
return 0;
if (src == extclk)
return 1;
dev_warn(&vc5->client->dev,
"Invalid clock output configuration (%02x)\n", src);
return 0;
}
static int vc5_clk_out_set_parent(struct clk_hw *hw, u8 index)
{
struct vc5_hw_data *hwdata = container_of(hw, struct vc5_hw_data, hw);
struct vc5_driver_data *vc5 = hwdata->vc5;
const u8 mask = VC5_OUT_DIV_CONTROL_RESET |
VC5_OUT_DIV_CONTROL_SELB_NORM |
VC5_OUT_DIV_CONTROL_SEL_EXT |
VC5_OUT_DIV_CONTROL_EN_FOD;
const u8 extclk = VC5_OUT_DIV_CONTROL_SELB_NORM |
VC5_OUT_DIV_CONTROL_SEL_EXT;
u8 src = VC5_OUT_DIV_CONTROL_RESET;
if (index == 0)
src |= VC5_OUT_DIV_CONTROL_EN_FOD;
else
src |= extclk;
return regmap_update_bits(vc5->regmap, VC5_OUT_DIV_CONTROL(hwdata->num),
mask, src);
}
static struct clk_hw *vc5_of_clk_get(struct of_phandle_args *clkspec,
void *data)
{
struct vc5_driver_data *vc5 = data;
unsigned int idx = clkspec->args[0];
if (idx > 2)
return ERR_PTR(-EINVAL);
return &vc5->clk_out[idx].hw;
}
static int vc5_map_index_to_output(const enum vc5_model model,
const unsigned int n)
{
switch (model) {
case IDT_VC5_5P49V5933:
return (n == 0) ? 0 : 3;
case IDT_VC5_5P49V5923:
default:
return n;
}
}
static int vc5_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct of_device_id *of_id =
of_match_device(clk_vc5_of_match, &client->dev);
struct vc5_driver_data *vc5;
struct clk_init_data init;
const char *parent_names[2];
unsigned int n, idx;
int ret;
vc5 = devm_kzalloc(&client->dev, sizeof(*vc5), GFP_KERNEL);
if (vc5 == NULL)
return -ENOMEM;
i2c_set_clientdata(client, vc5);
vc5->client = client;
vc5->model = (enum vc5_model)of_id->data;
vc5->pin_xin = devm_clk_get(&client->dev, "xin");
if (PTR_ERR(vc5->pin_xin) == -EPROBE_DEFER)
return -EPROBE_DEFER;
vc5->pin_clkin = devm_clk_get(&client->dev, "clkin");
if (PTR_ERR(vc5->pin_clkin) == -EPROBE_DEFER)
return -EPROBE_DEFER;
vc5->regmap = devm_regmap_init_i2c(client, &vc5_regmap_config);
if (IS_ERR(vc5->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(vc5->regmap);
}
memset(&init, 0, sizeof(init));
if (!IS_ERR(vc5->pin_xin)) {
vc5->clk_mux_ins |= VC5_MUX_IN_XIN;
parent_names[init.num_parents++] = __clk_get_name(vc5->pin_xin);
} else if (vc5->model == IDT_VC5_5P49V5933) {
vc5->pin_xin = clk_register_fixed_rate(&client->dev,
"internal-xtal", NULL,
0, 25000000);
if (IS_ERR(vc5->pin_xin))
return PTR_ERR(vc5->pin_xin);
vc5->clk_mux_ins |= VC5_MUX_IN_XIN;
parent_names[init.num_parents++] = __clk_get_name(vc5->pin_xin);
}
if (!IS_ERR(vc5->pin_clkin)) {
vc5->clk_mux_ins |= VC5_MUX_IN_CLKIN;
parent_names[init.num_parents++] =
__clk_get_name(vc5->pin_clkin);
}
if (!init.num_parents) {
dev_err(&client->dev, "no input clock specified!\n");
return -EINVAL;
}
init.name = vc5_mux_names[0];
init.ops = &vc5_mux_ops;
init.flags = 0;
init.parent_names = parent_names;
vc5->clk_mux.init = &init;
ret = devm_clk_hw_register(&client->dev, &vc5->clk_mux);
if (ret) {
dev_err(&client->dev, "unable to register %s\n", init.name);
goto err_clk;
}
memset(&init, 0, sizeof(init));
init.name = vc5_pll_names[0];
init.ops = &vc5_pll_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = vc5_mux_names;
init.num_parents = 1;
vc5->clk_pll.num = 0;
vc5->clk_pll.vc5 = vc5;
vc5->clk_pll.hw.init = &init;
ret = devm_clk_hw_register(&client->dev, &vc5->clk_pll.hw);
if (ret) {
dev_err(&client->dev, "unable to register %s\n", init.name);
goto err_clk;
}
for (n = 0; n < 2; n++) {
idx = vc5_map_index_to_output(vc5->model, n);
memset(&init, 0, sizeof(init));
init.name = vc5_fod_names[idx];
init.ops = &vc5_fod_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = vc5_pll_names;
init.num_parents = 1;
vc5->clk_fod[n].num = idx;
vc5->clk_fod[n].vc5 = vc5;
vc5->clk_fod[n].hw.init = &init;
ret = devm_clk_hw_register(&client->dev, &vc5->clk_fod[n].hw);
if (ret) {
dev_err(&client->dev, "unable to register %s\n",
init.name);
goto err_clk;
}
}
memset(&init, 0, sizeof(init));
init.name = vc5_clk_out_names[0];
init.ops = &vc5_clk_out_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = vc5_mux_names;
init.num_parents = 1;
vc5->clk_out[0].num = idx;
vc5->clk_out[0].vc5 = vc5;
vc5->clk_out[0].hw.init = &init;
ret = devm_clk_hw_register(&client->dev, &vc5->clk_out[0].hw);
if (ret) {
dev_err(&client->dev, "unable to register %s\n",
init.name);
goto err_clk;
}
for (n = 1; n < 3; n++) {
idx = vc5_map_index_to_output(vc5->model, n - 1);
parent_names[0] = vc5_fod_names[idx];
if (n == 1)
parent_names[1] = vc5_mux_names[0];
else
parent_names[1] = vc5_clk_out_names[n - 1];
memset(&init, 0, sizeof(init));
init.name = vc5_clk_out_names[idx + 1];
init.ops = &vc5_clk_out_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = parent_names;
init.num_parents = 2;
vc5->clk_out[n].num = idx;
vc5->clk_out[n].vc5 = vc5;
vc5->clk_out[n].hw.init = &init;
ret = devm_clk_hw_register(&client->dev,
&vc5->clk_out[n].hw);
if (ret) {
dev_err(&client->dev, "unable to register %s\n",
init.name);
goto err_clk;
}
}
ret = of_clk_add_hw_provider(client->dev.of_node, vc5_of_clk_get, vc5);
if (ret) {
dev_err(&client->dev, "unable to add clk provider\n");
goto err_clk;
}
return 0;
err_clk:
if (vc5->model == IDT_VC5_5P49V5933)
clk_unregister_fixed_rate(vc5->pin_xin);
return ret;
}
static int vc5_remove(struct i2c_client *client)
{
struct vc5_driver_data *vc5 = i2c_get_clientdata(client);
of_clk_del_provider(client->dev.of_node);
if (vc5->model == IDT_VC5_5P49V5933)
clk_unregister_fixed_rate(vc5->pin_xin);
return 0;
}
