static int si514_enable_output(struct clk_si514 *data, bool enable)
{
return regmap_update_bits(data->regmap, SI514_REG_CONTROL,
SI514_CONTROL_OE, enable ? SI514_CONTROL_OE : 0);
}
static int si514_get_muldiv(struct clk_si514 *data,
struct clk_si514_muldiv *settings)
{
int err;
u8 reg[7];
err = regmap_bulk_read(data->regmap, SI514_REG_M_FRAC1,
reg, ARRAY_SIZE(reg));
if (err)
return err;
settings->m_frac = reg[0] | reg[1] << 8 | reg[2] << 16 |
(reg[3] & 0x1F) << 24;
settings->m_int = (reg[4] & 0x3f) << 3 | reg[3] >> 5;
settings->ls_div_bits = (reg[6] >> 4) & 0x07;
settings->hs_div = (reg[6] & 0x03) << 8 | reg[5];
return 0;
}
static int si514_set_muldiv(struct clk_si514 *data,
struct clk_si514_muldiv *settings)
{
u8 lp;
u8 reg[7];
int err;
if (settings->m_int < 65 ||
(settings->m_int == 65 && settings->m_frac <= 139575831))
lp = 0x22;
else if (settings->m_int < 67 ||
(settings->m_int == 67 && settings->m_frac <= 461581994))
lp = 0x23;
else if (settings->m_int < 72 ||
(settings->m_int == 72 && settings->m_frac <= 503383578))
lp = 0x33;
else if (settings->m_int < 75 ||
(settings->m_int == 75 && settings->m_frac <= 452724474))
lp = 0x34;
else
lp = 0x44;
err = regmap_write(data->regmap, SI514_REG_LP, lp);
if (err < 0)
return err;
reg[0] = settings->m_frac;
reg[1] = settings->m_frac >> 8;
reg[2] = settings->m_frac >> 16;
reg[3] = settings->m_frac >> 24 | settings->m_int << 5;
reg[4] = settings->m_int >> 3;
reg[5] = settings->hs_div;
reg[6] = (settings->hs_div >> 8) | (settings->ls_div_bits << 4);
err = regmap_bulk_write(data->regmap, SI514_REG_HS_DIV, reg + 5, 2);
if (err < 0)
return err;
return regmap_bulk_write(data->regmap, SI514_REG_M_FRAC1, reg, 5);
}
static int si514_calc_muldiv(struct clk_si514_muldiv *settings,
unsigned long frequency)
{
u64 m;
u32 ls_freq;
u32 tmp;
u8 res;
if ((frequency < SI514_MIN_FREQ) || (frequency > SI514_MAX_FREQ))
return -EINVAL;
ls_freq = frequency;
if (frequency >= (FVCO_MIN / HS_DIV_MAX))
settings->ls_div_bits = 0;
else {
res = 1;
tmp = 2 * HS_DIV_MAX;
while (tmp <= (HS_DIV_MAX * 32)) {
if ((frequency * tmp) >= FVCO_MIN)
break;
++res;
tmp <<= 1;
}
settings->ls_div_bits = res;
ls_freq = frequency << res;
}
settings->hs_div = DIV_ROUND_UP(FVCO_MIN >> 1, ls_freq) << 1;
m = ((u64)(ls_freq * settings->hs_div) << 29) + (FXO / 2);
do_div(m, FXO);
settings->m_frac = (u32)m & (BIT(29) - 1);
settings->m_int = (u32)(m >> 29);
return 0;
}
static unsigned long si514_calc_rate(struct clk_si514_muldiv *settings)
{
u64 m = settings->m_frac | ((u64)settings->m_int << 29);
u32 d = settings->hs_div * BIT(settings->ls_div_bits);
return ((u32)(((m * FXO) + (FXO / 2)) >> 29)) / d;
}
static unsigned long si514_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_si514 *data = to_clk_si514(hw);
struct clk_si514_muldiv settings;
int err;
err = si514_get_muldiv(data, &settings);
if (err) {
dev_err(&data->i2c_client->dev, "unable to retrieve settings\n");
return 0;
}
return si514_calc_rate(&settings);
}
static long si514_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct clk_si514_muldiv settings;
int err;
if (!rate)
return 0;
err = si514_calc_muldiv(&settings, rate);
if (err)
return err;
return si514_calc_rate(&settings);
}
static int si514_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_si514 *data = to_clk_si514(hw);
struct clk_si514_muldiv settings;
int err;
err = si514_calc_muldiv(&settings, rate);
if (err)
return err;
si514_enable_output(data, false);
err = si514_set_muldiv(data, &settings);
if (err < 0)
return err;
err = regmap_write(data->regmap, SI514_REG_CONTROL, SI514_CONTROL_FCAL);
if (err < 0)
return err;
usleep_range(10000, 12000);
si514_enable_output(data, true);
return err;
}
static bool si514_regmap_is_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case SI514_REG_CONTROL:
case SI514_REG_RESET:
return true;
default:
return false;
}
}
static bool si514_regmap_is_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case SI514_REG_LP:
case SI514_REG_M_FRAC1 ... SI514_REG_LS_HS_DIV:
case SI514_REG_OE_STATE:
case SI514_REG_RESET:
case SI514_REG_CONTROL:
return true;
default:
return false;
}
}
static int si514_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct clk_si514 *data;
struct clk_init_data init;
struct clk *clk;
int err;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
init.ops = &si514_clk_ops;
init.flags = 0;
init.num_parents = 0;
data->hw.init = &init;
data->i2c_client = client;
if (of_property_read_string(client->dev.of_node, "clock-output-names",
&init.name))
init.name = client->dev.of_node->name;
data->regmap = devm_regmap_init_i2c(client, &si514_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
i2c_set_clientdata(client, data);
clk = devm_clk_register(&client->dev, &data->hw);
if (IS_ERR(clk)) {
dev_err(&client->dev, "clock registration failed\n");
return PTR_ERR(clk);
}
err = of_clk_add_provider(client->dev.of_node, of_clk_src_simple_get,
clk);
if (err) {
dev_err(&client->dev, "unable to add clk provider\n");
return err;
}
return 0;
}
static int si514_remove(struct i2c_client *client)
{
of_clk_del_provider(client->dev.of_node);
return 0;
}
