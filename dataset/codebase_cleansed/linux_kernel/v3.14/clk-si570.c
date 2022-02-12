static int si570_get_divs(struct clk_si570 *data, u64 *rfreq,
unsigned int *n1, unsigned int *hs_div)
{
int err;
u8 reg[6];
u64 tmp;
err = regmap_bulk_read(data->regmap, SI570_REG_HS_N1 + data->div_offset,
reg, ARRAY_SIZE(reg));
if (err)
return err;
*hs_div = ((reg[0] & HS_DIV_MASK) >> HS_DIV_SHIFT) + HS_DIV_OFFSET;
*n1 = ((reg[0] & N1_6_2_MASK) << 2) + ((reg[1] & N1_1_0_MASK) >> 6) + 1;
if (*n1 > 1)
*n1 &= ~1;
tmp = reg[1] & RFREQ_37_32_MASK;
tmp = (tmp << 8) + reg[2];
tmp = (tmp << 8) + reg[3];
tmp = (tmp << 8) + reg[4];
tmp = (tmp << 8) + reg[5];
*rfreq = tmp;
return 0;
}
static int si570_get_defaults(struct clk_si570 *data, u64 fout)
{
int err;
u64 fdco;
regmap_write(data->regmap, SI570_REG_CONTROL, SI570_CNTRL_RECALL);
err = si570_get_divs(data, &data->rfreq, &data->n1, &data->hs_div);
if (err)
return err;
fdco = fout * data->n1 * data->hs_div;
if (fdco >= (1LL << 36))
data->fxtal = div64_u64(fdco << 24, data->rfreq >> 4);
else
data->fxtal = div64_u64(fdco << 28, data->rfreq);
data->frequency = fout;
return 0;
}
static int si570_update_rfreq(struct clk_si570 *data)
{
u8 reg[5];
reg[0] = ((data->n1 - 1) << 6) |
((data->rfreq >> 32) & RFREQ_37_32_MASK);
reg[1] = (data->rfreq >> 24) & 0xff;
reg[2] = (data->rfreq >> 16) & 0xff;
reg[3] = (data->rfreq >> 8) & 0xff;
reg[4] = data->rfreq & 0xff;
return regmap_bulk_write(data->regmap, SI570_REG_N1_RFREQ0 +
data->div_offset, reg, ARRAY_SIZE(reg));
}
static int si570_calc_divs(unsigned long frequency, struct clk_si570 *data,
u64 *out_rfreq, unsigned int *out_n1, unsigned int *out_hs_div)
{
int i;
unsigned int n1, hs_div;
u64 fdco, best_fdco = ULLONG_MAX;
static const uint8_t si570_hs_div_values[] = { 11, 9, 7, 6, 5, 4 };
for (i = 0; i < ARRAY_SIZE(si570_hs_div_values); i++) {
hs_div = si570_hs_div_values[i];
n1 = div_u64(div_u64(FDCO_MIN, hs_div), frequency);
if (!n1 || (n1 & 1))
n1++;
while (n1 <= 128) {
fdco = (u64)frequency * (u64)hs_div * (u64)n1;
if (fdco > FDCO_MAX)
break;
if (fdco >= FDCO_MIN && fdco < best_fdco) {
*out_n1 = n1;
*out_hs_div = hs_div;
*out_rfreq = div64_u64(fdco << 28, data->fxtal);
best_fdco = fdco;
}
n1 += (n1 == 1 ? 1 : 2);
}
}
if (best_fdco == ULLONG_MAX)
return -EINVAL;
return 0;
}
static unsigned long si570_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
int err;
u64 rfreq, rate;
unsigned int n1, hs_div;
struct clk_si570 *data = to_clk_si570(hw);
err = si570_get_divs(data, &rfreq, &n1, &hs_div);
if (err) {
dev_err(&data->i2c_client->dev, "unable to recalc rate\n");
return data->frequency;
}
rfreq = div_u64(rfreq, hs_div * n1);
rate = (data->fxtal * rfreq) >> 28;
return rate;
}
static long si570_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
int err;
u64 rfreq;
unsigned int n1, hs_div;
struct clk_si570 *data = to_clk_si570(hw);
if (!rate)
return 0;
if (div64_u64(abs(rate - data->frequency) * 10000LL,
data->frequency) < 35) {
rfreq = div64_u64((data->rfreq * rate) +
div64_u64(data->frequency, 2), data->frequency);
n1 = data->n1;
hs_div = data->hs_div;
} else {
err = si570_calc_divs(rate, data, &rfreq, &n1, &hs_div);
if (err) {
dev_err(&data->i2c_client->dev,
"unable to round rate\n");
return 0;
}
}
return rate;
}
static int si570_set_frequency(struct clk_si570 *data, unsigned long frequency)
{
int err;
err = si570_calc_divs(frequency, data, &data->rfreq, &data->n1,
&data->hs_div);
if (err)
return err;
regmap_write(data->regmap, SI570_REG_FREEZE_DCO, SI570_FREEZE_DCO);
regmap_write(data->regmap, SI570_REG_HS_N1 + data->div_offset,
((data->hs_div - HS_DIV_OFFSET) << HS_DIV_SHIFT) |
(((data->n1 - 1) >> 2) & N1_6_2_MASK));
si570_update_rfreq(data);
regmap_write(data->regmap, SI570_REG_FREEZE_DCO, 0);
regmap_write(data->regmap, SI570_REG_CONTROL, SI570_CNTRL_NEWFREQ);
usleep_range(10000, 12000);
return 0;
}
static int si570_set_frequency_small(struct clk_si570 *data,
unsigned long frequency)
{
data->rfreq = div64_u64((data->rfreq * frequency) +
div_u64(data->frequency, 2), data->frequency);
regmap_write(data->regmap, SI570_REG_CONTROL, SI570_CNTRL_FREEZE_M);
si570_update_rfreq(data);
regmap_write(data->regmap, SI570_REG_CONTROL, 0);
usleep_range(100, 200);
return 0;
}
static int si570_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_si570 *data = to_clk_si570(hw);
struct i2c_client *client = data->i2c_client;
int err;
if (rate < SI570_MIN_FREQ || rate > data->max_freq) {
dev_err(&client->dev,
"requested frequency %lu Hz is out of range\n", rate);
return -EINVAL;
}
if (div64_u64(abs(rate - data->frequency) * 10000LL,
data->frequency) < 35)
err = si570_set_frequency_small(data, rate);
else
err = si570_set_frequency(data, rate);
if (err)
return err;
data->frequency = rate;
return 0;
}
static bool si570_regmap_is_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case SI570_REG_CONTROL:
return true;
default:
return false;
}
}
static bool si570_regmap_is_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case SI570_REG_HS_N1 ... (SI570_REG_RFREQ4 + SI570_DIV_OFFSET_7PPM):
case SI570_REG_CONTROL:
case SI570_REG_FREEZE_DCO:
return true;
default:
return false;
}
}
static int si570_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct clk_si570 *data;
struct clk_init_data init;
struct clk *clk;
u32 initial_fout, factory_fout, stability;
int err;
enum clk_si570_variant variant = id->driver_data;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
init.ops = &si570_clk_ops;
init.flags = CLK_IS_ROOT;
init.num_parents = 0;
data->hw.init = &init;
data->i2c_client = client;
if (variant == si57x) {
err = of_property_read_u32(client->dev.of_node,
"temperature-stability", &stability);
if (err) {
dev_err(&client->dev,
"'temperature-stability' property missing\n");
return err;
}
if (stability == 7)
data->div_offset = SI570_DIV_OFFSET_7PPM;
data->max_freq = SI570_MAX_FREQ;
} else {
data->max_freq = SI598_MAX_FREQ;
}
if (of_property_read_string(client->dev.of_node, "clock-output-names",
&init.name))
init.name = client->dev.of_node->name;
err = of_property_read_u32(client->dev.of_node, "factory-fout",
&factory_fout);
if (err) {
dev_err(&client->dev, "'factory-fout' property missing\n");
return err;
}
data->regmap = devm_regmap_init_i2c(client, &si570_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
i2c_set_clientdata(client, data);
err = si570_get_defaults(data, factory_fout);
if (err)
return err;
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
if (!of_property_read_u32(client->dev.of_node, "clock-frequency",
&initial_fout)) {
err = clk_set_rate(clk, initial_fout);
if (err) {
of_clk_del_provider(client->dev.of_node);
return err;
}
}
dev_info(&client->dev, "registered, current frequency %llu Hz\n",
data->frequency);
return 0;
}
static int si570_remove(struct i2c_client *client)
{
of_clk_del_provider(client->dev.of_node);
return 0;
}
