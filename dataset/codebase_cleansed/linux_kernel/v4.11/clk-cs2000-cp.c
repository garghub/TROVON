static int cs2000_bset(struct cs2000_priv *priv, u8 addr, u8 mask, u8 val)
{
s32 data;
data = cs2000_read(priv, addr);
if (data < 0)
return data;
data &= ~mask;
data |= (val & mask);
return cs2000_write(priv, addr, data);
}
static int cs2000_enable_dev_config(struct cs2000_priv *priv, bool enable)
{
int ret;
ret = cs2000_bset(priv, DEVICE_CFG1, ENDEV1,
enable ? ENDEV1 : 0);
if (ret < 0)
return ret;
ret = cs2000_bset(priv, GLOBAL_CFG, ENDEV2,
enable ? ENDEV2 : 0);
if (ret < 0)
return ret;
return 0;
}
static int cs2000_clk_in_bound_rate(struct cs2000_priv *priv,
u32 rate_in)
{
u32 val;
if (rate_in >= 32000000 && rate_in < 56000000)
val = 0x0;
else if (rate_in >= 16000000 && rate_in < 28000000)
val = 0x1;
else if (rate_in >= 8000000 && rate_in < 14000000)
val = 0x2;
else
return -EINVAL;
return cs2000_bset(priv, FUNC_CFG1, 0x3 << 3, val << 3);
}
static int cs2000_wait_pll_lock(struct cs2000_priv *priv)
{
struct device *dev = priv_to_dev(priv);
s32 val;
unsigned int i;
for (i = 0; i < 256; i++) {
val = cs2000_read(priv, DEVICE_CTRL);
if (val < 0)
return val;
if (!(val & PLL_UNLOCK))
return 0;
udelay(1);
}
dev_err(dev, "pll lock failed\n");
return -ETIMEDOUT;
}
static int cs2000_clk_out_enable(struct cs2000_priv *priv, bool enable)
{
return cs2000_write(priv, DEVICE_CTRL, enable ? 0 : 0x3);
}
static u32 cs2000_rate_to_ratio(u32 rate_in, u32 rate_out)
{
u64 ratio;
ratio = (u64)rate_out << 20;
do_div(ratio, rate_in);
return ratio;
}
static unsigned long cs2000_ratio_to_rate(u32 ratio, u32 rate_in)
{
u64 rate_out;
rate_out = (u64)ratio * rate_in;
return rate_out >> 20;
}
static int cs2000_ratio_set(struct cs2000_priv *priv,
int ch, u32 rate_in, u32 rate_out)
{
u32 val;
unsigned int i;
int ret;
if (CH_SIZE_ERR(ch))
return -EINVAL;
val = cs2000_rate_to_ratio(rate_in, rate_out);
for (i = 0; i < RATIO_REG_SIZE; i++) {
ret = cs2000_write(priv,
Ratio_Add(ch, i),
Ratio_Val(val, i));
if (ret < 0)
return ret;
}
return 0;
}
static u32 cs2000_ratio_get(struct cs2000_priv *priv, int ch)
{
s32 tmp;
u32 val;
unsigned int i;
val = 0;
for (i = 0; i < RATIO_REG_SIZE; i++) {
tmp = cs2000_read(priv, Ratio_Add(ch, i));
if (tmp < 0)
return 0;
val |= Val_Ratio(tmp, i);
}
return val;
}
static int cs2000_ratio_select(struct cs2000_priv *priv, int ch)
{
int ret;
if (CH_SIZE_ERR(ch))
return -EINVAL;
ret = cs2000_bset(priv, DEVICE_CFG1, RSEL_MASK, RSEL(ch));
if (ret < 0)
return ret;
ret = cs2000_write(priv, DEVICE_CFG2, 0x0);
if (ret < 0)
return ret;
return 0;
}
static unsigned long cs2000_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct cs2000_priv *priv = hw_to_priv(hw);
int ch = 0;
u32 ratio;
ratio = cs2000_ratio_get(priv, ch);
return cs2000_ratio_to_rate(ratio, parent_rate);
}
static long cs2000_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
u32 ratio;
ratio = cs2000_rate_to_ratio(*parent_rate, rate);
return cs2000_ratio_to_rate(ratio, *parent_rate);
}
static int __cs2000_set_rate(struct cs2000_priv *priv, int ch,
unsigned long rate, unsigned long parent_rate)
{
int ret;
ret = cs2000_clk_in_bound_rate(priv, parent_rate);
if (ret < 0)
return ret;
ret = cs2000_ratio_set(priv, ch, parent_rate, rate);
if (ret < 0)
return ret;
ret = cs2000_ratio_select(priv, ch);
if (ret < 0)
return ret;
priv->saved_rate = rate;
priv->saved_parent_rate = parent_rate;
return 0;
}
static int cs2000_set_rate(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate)
{
struct cs2000_priv *priv = hw_to_priv(hw);
int ch = 0;
return __cs2000_set_rate(priv, ch, rate, parent_rate);
}
static int cs2000_enable(struct clk_hw *hw)
{
struct cs2000_priv *priv = hw_to_priv(hw);
int ret;
ret = cs2000_enable_dev_config(priv, true);
if (ret < 0)
return ret;
ret = cs2000_clk_out_enable(priv, true);
if (ret < 0)
return ret;
ret = cs2000_wait_pll_lock(priv);
if (ret < 0)
return ret;
return ret;
}
static void cs2000_disable(struct clk_hw *hw)
{
struct cs2000_priv *priv = hw_to_priv(hw);
cs2000_enable_dev_config(priv, false);
cs2000_clk_out_enable(priv, false);
}
static u8 cs2000_get_parent(struct clk_hw *hw)
{
return REF_CLK;
}
static int cs2000_clk_get(struct cs2000_priv *priv)
{
struct i2c_client *client = priv_to_client(priv);
struct device *dev = &client->dev;
struct clk *clk_in, *ref_clk;
clk_in = devm_clk_get(dev, "clk_in");
if (IS_ERR(clk_in))
return -EPROBE_DEFER;
ref_clk = devm_clk_get(dev, "ref_clk");
if (IS_ERR(ref_clk))
return -EPROBE_DEFER;
priv->clk_in = clk_in;
priv->ref_clk = ref_clk;
return 0;
}
static int cs2000_clk_register(struct cs2000_priv *priv)
{
struct device *dev = priv_to_dev(priv);
struct device_node *np = dev->of_node;
struct clk_init_data init;
const char *name = np->name;
static const char *parent_names[CLK_MAX];
int ch = 0;
int rate;
int ret;
of_property_read_string(np, "clock-output-names", &name);
rate = clk_get_rate(priv->ref_clk);
ret = __cs2000_set_rate(priv, ch, rate, rate);
if (ret < 0)
return ret;
parent_names[CLK_IN] = __clk_get_name(priv->clk_in);
parent_names[REF_CLK] = __clk_get_name(priv->ref_clk);
init.name = name;
init.ops = &cs2000_ops;
init.flags = CLK_SET_RATE_GATE;
init.parent_names = parent_names;
init.num_parents = ARRAY_SIZE(parent_names);
priv->hw.init = &init;
ret = clk_hw_register(dev, &priv->hw);
if (ret)
return ret;
ret = of_clk_add_hw_provider(np, of_clk_hw_simple_get, &priv->hw);
if (ret < 0) {
clk_hw_unregister(&priv->hw);
return ret;
}
return 0;
}
static int cs2000_version_print(struct cs2000_priv *priv)
{
struct i2c_client *client = priv_to_client(priv);
struct device *dev = &client->dev;
s32 val;
const char *revision;
val = cs2000_read(priv, DEVICE_ID);
if (val < 0)
return val;
if (val >> 3)
return -EIO;
switch (val & REVISION_MASK) {
case REVISION_B2_B3:
revision = "B2 / B3";
break;
case REVISION_C1:
revision = "C1";
break;
default:
return -EIO;
}
dev_info(dev, "revision - %s\n", revision);
return 0;
}
static int cs2000_remove(struct i2c_client *client)
{
struct cs2000_priv *priv = i2c_get_clientdata(client);
struct device *dev = &client->dev;
struct device_node *np = dev->of_node;
of_clk_del_provider(np);
clk_hw_unregister(&priv->hw);
return 0;
}
static int cs2000_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cs2000_priv *priv;
struct device *dev = &client->dev;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->client = client;
i2c_set_clientdata(client, priv);
ret = cs2000_clk_get(priv);
if (ret < 0)
return ret;
ret = cs2000_clk_register(priv);
if (ret < 0)
return ret;
ret = cs2000_version_print(priv);
if (ret < 0)
goto probe_err;
return 0;
probe_err:
cs2000_remove(client);
return ret;
}
static int cs2000_resume(struct device *dev)
{
struct cs2000_priv *priv = dev_get_drvdata(dev);
int ch = 0;
return __cs2000_set_rate(priv, ch,
priv->saved_rate,
priv->saved_parent_rate);
}
