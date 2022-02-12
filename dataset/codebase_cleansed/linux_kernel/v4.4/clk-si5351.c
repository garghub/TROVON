static inline u8 si5351_reg_read(struct si5351_driver_data *drvdata, u8 reg)
{
u32 val;
int ret;
ret = regmap_read(drvdata->regmap, reg, &val);
if (ret) {
dev_err(&drvdata->client->dev,
"unable to read from reg%02x\n", reg);
return 0;
}
return (u8)val;
}
static inline int si5351_bulk_read(struct si5351_driver_data *drvdata,
u8 reg, u8 count, u8 *buf)
{
return regmap_bulk_read(drvdata->regmap, reg, buf, count);
}
static inline int si5351_reg_write(struct si5351_driver_data *drvdata,
u8 reg, u8 val)
{
return regmap_write(drvdata->regmap, reg, val);
}
static inline int si5351_bulk_write(struct si5351_driver_data *drvdata,
u8 reg, u8 count, const u8 *buf)
{
return regmap_raw_write(drvdata->regmap, reg, buf, count);
}
static inline int si5351_set_bits(struct si5351_driver_data *drvdata,
u8 reg, u8 mask, u8 val)
{
return regmap_update_bits(drvdata->regmap, reg, mask, val);
}
static inline u8 si5351_msynth_params_address(int num)
{
if (num > 5)
return SI5351_CLK6_PARAMETERS + (num - 6);
return SI5351_CLK0_PARAMETERS + (SI5351_PARAMETERS_LENGTH * num);
}
static void si5351_read_parameters(struct si5351_driver_data *drvdata,
u8 reg, struct si5351_parameters *params)
{
u8 buf[SI5351_PARAMETERS_LENGTH];
switch (reg) {
case SI5351_CLK6_PARAMETERS:
case SI5351_CLK7_PARAMETERS:
buf[0] = si5351_reg_read(drvdata, reg);
params->p1 = buf[0];
params->p2 = 0;
params->p3 = 1;
break;
default:
si5351_bulk_read(drvdata, reg, SI5351_PARAMETERS_LENGTH, buf);
params->p1 = ((buf[2] & 0x03) << 16) | (buf[3] << 8) | buf[4];
params->p2 = ((buf[5] & 0x0f) << 16) | (buf[6] << 8) | buf[7];
params->p3 = ((buf[5] & 0xf0) << 12) | (buf[0] << 8) | buf[1];
}
params->valid = 1;
}
static void si5351_write_parameters(struct si5351_driver_data *drvdata,
u8 reg, struct si5351_parameters *params)
{
u8 buf[SI5351_PARAMETERS_LENGTH];
switch (reg) {
case SI5351_CLK6_PARAMETERS:
case SI5351_CLK7_PARAMETERS:
buf[0] = params->p1 & 0xff;
si5351_reg_write(drvdata, reg, buf[0]);
break;
default:
buf[0] = ((params->p3 & 0x0ff00) >> 8) & 0xff;
buf[1] = params->p3 & 0xff;
buf[2] = si5351_reg_read(drvdata, reg + 2) & ~0x03;
buf[2] |= ((params->p1 & 0x30000) >> 16) & 0x03;
buf[3] = ((params->p1 & 0x0ff00) >> 8) & 0xff;
buf[4] = params->p1 & 0xff;
buf[5] = ((params->p3 & 0xf0000) >> 12) |
((params->p2 & 0xf0000) >> 16);
buf[6] = ((params->p2 & 0x0ff00) >> 8) & 0xff;
buf[7] = params->p2 & 0xff;
si5351_bulk_write(drvdata, reg, SI5351_PARAMETERS_LENGTH, buf);
}
}
static bool si5351_regmap_is_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case SI5351_DEVICE_STATUS:
case SI5351_INTERRUPT_STATUS:
case SI5351_PLL_RESET:
return true;
}
return false;
}
static bool si5351_regmap_is_writeable(struct device *dev, unsigned int reg)
{
if (reg >= 4 && reg <= 8)
return false;
if (reg >= 10 && reg <= 14)
return false;
if (reg >= 173 && reg <= 176)
return false;
if (reg >= 178 && reg <= 182)
return false;
if (reg == SI5351_DEVICE_STATUS)
return false;
return true;
}
static int si5351_xtal_prepare(struct clk_hw *hw)
{
struct si5351_driver_data *drvdata =
container_of(hw, struct si5351_driver_data, xtal);
si5351_set_bits(drvdata, SI5351_FANOUT_ENABLE,
SI5351_XTAL_ENABLE, SI5351_XTAL_ENABLE);
return 0;
}
static void si5351_xtal_unprepare(struct clk_hw *hw)
{
struct si5351_driver_data *drvdata =
container_of(hw, struct si5351_driver_data, xtal);
si5351_set_bits(drvdata, SI5351_FANOUT_ENABLE,
SI5351_XTAL_ENABLE, 0);
}
static int si5351_clkin_prepare(struct clk_hw *hw)
{
struct si5351_driver_data *drvdata =
container_of(hw, struct si5351_driver_data, clkin);
si5351_set_bits(drvdata, SI5351_FANOUT_ENABLE,
SI5351_CLKIN_ENABLE, SI5351_CLKIN_ENABLE);
return 0;
}
static void si5351_clkin_unprepare(struct clk_hw *hw)
{
struct si5351_driver_data *drvdata =
container_of(hw, struct si5351_driver_data, clkin);
si5351_set_bits(drvdata, SI5351_FANOUT_ENABLE,
SI5351_CLKIN_ENABLE, 0);
}
static unsigned long si5351_clkin_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct si5351_driver_data *drvdata =
container_of(hw, struct si5351_driver_data, clkin);
unsigned long rate;
unsigned char idiv;
rate = parent_rate;
if (parent_rate > 160000000) {
idiv = SI5351_CLKIN_DIV_8;
rate /= 8;
} else if (parent_rate > 80000000) {
idiv = SI5351_CLKIN_DIV_4;
rate /= 4;
} else if (parent_rate > 40000000) {
idiv = SI5351_CLKIN_DIV_2;
rate /= 2;
} else {
idiv = SI5351_CLKIN_DIV_1;
}
si5351_set_bits(drvdata, SI5351_PLL_INPUT_SOURCE,
SI5351_CLKIN_DIV_MASK, idiv);
dev_dbg(&drvdata->client->dev, "%s - clkin div = %d, rate = %lu\n",
__func__, (1 << (idiv >> 6)), rate);
return rate;
}
static int si5351_vxco_prepare(struct clk_hw *hw)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
dev_warn(&hwdata->drvdata->client->dev, "VXCO currently unsupported\n");
return 0;
}
static void si5351_vxco_unprepare(struct clk_hw *hw)
{
}
static unsigned long si5351_vxco_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 0;
}
static int si5351_vxco_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent)
{
return 0;
}
static int _si5351_pll_reparent(struct si5351_driver_data *drvdata,
int num, enum si5351_pll_src parent)
{
u8 mask = (num == 0) ? SI5351_PLLA_SOURCE : SI5351_PLLB_SOURCE;
if (parent == SI5351_PLL_SRC_DEFAULT)
return 0;
if (num > 2)
return -EINVAL;
if (drvdata->variant != SI5351_VARIANT_C &&
parent != SI5351_PLL_SRC_XTAL)
return -EINVAL;
si5351_set_bits(drvdata, SI5351_PLL_INPUT_SOURCE, mask,
(parent == SI5351_PLL_SRC_XTAL) ? 0 : mask);
return 0;
}
static unsigned char si5351_pll_get_parent(struct clk_hw *hw)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
u8 mask = (hwdata->num == 0) ? SI5351_PLLA_SOURCE : SI5351_PLLB_SOURCE;
u8 val;
val = si5351_reg_read(hwdata->drvdata, SI5351_PLL_INPUT_SOURCE);
return (val & mask) ? 1 : 0;
}
static int si5351_pll_set_parent(struct clk_hw *hw, u8 index)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
if (hwdata->drvdata->variant != SI5351_VARIANT_C &&
index > 0)
return -EPERM;
if (index > 1)
return -EINVAL;
return _si5351_pll_reparent(hwdata->drvdata, hwdata->num,
(index == 0) ? SI5351_PLL_SRC_XTAL :
SI5351_PLL_SRC_CLKIN);
}
static unsigned long si5351_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
u8 reg = (hwdata->num == 0) ? SI5351_PLLA_PARAMETERS :
SI5351_PLLB_PARAMETERS;
unsigned long long rate;
if (!hwdata->params.valid)
si5351_read_parameters(hwdata->drvdata, reg, &hwdata->params);
if (hwdata->params.p3 == 0)
return parent_rate;
rate = hwdata->params.p1 * hwdata->params.p3;
rate += 512 * hwdata->params.p3;
rate += hwdata->params.p2;
rate *= parent_rate;
do_div(rate, 128 * hwdata->params.p3);
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: p1 = %lu, p2 = %lu, p3 = %lu, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw),
hwdata->params.p1, hwdata->params.p2, hwdata->params.p3,
parent_rate, (unsigned long)rate);
return (unsigned long)rate;
}
static long si5351_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
unsigned long rfrac, denom, a, b, c;
unsigned long long lltmp;
if (rate < SI5351_PLL_VCO_MIN)
rate = SI5351_PLL_VCO_MIN;
if (rate > SI5351_PLL_VCO_MAX)
rate = SI5351_PLL_VCO_MAX;
a = rate / *parent_rate;
if (a < SI5351_PLL_A_MIN)
rate = *parent_rate * SI5351_PLL_A_MIN;
if (a > SI5351_PLL_A_MAX)
rate = *parent_rate * SI5351_PLL_A_MAX;
denom = 1000 * 1000;
lltmp = rate % (*parent_rate);
lltmp *= denom;
do_div(lltmp, *parent_rate);
rfrac = (unsigned long)lltmp;
b = 0;
c = 1;
if (rfrac)
rational_best_approximation(rfrac, denom,
SI5351_PLL_B_MAX, SI5351_PLL_C_MAX, &b, &c);
hwdata->params.p3 = c;
hwdata->params.p2 = (128 * b) % c;
hwdata->params.p1 = 128 * a;
hwdata->params.p1 += (128 * b / c);
hwdata->params.p1 -= 512;
lltmp = *parent_rate;
lltmp *= b;
do_div(lltmp, c);
rate = (unsigned long)lltmp;
rate += *parent_rate * a;
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: a = %lu, b = %lu, c = %lu, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw), a, b, c,
*parent_rate, rate);
return rate;
}
static int si5351_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
u8 reg = (hwdata->num == 0) ? SI5351_PLLA_PARAMETERS :
SI5351_PLLB_PARAMETERS;
si5351_write_parameters(hwdata->drvdata, reg, &hwdata->params);
si5351_set_bits(hwdata->drvdata, SI5351_CLK6_CTRL + hwdata->num,
SI5351_CLK_INTEGER_MODE,
(hwdata->params.p2 == 0) ? SI5351_CLK_INTEGER_MODE : 0);
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: p1 = %lu, p2 = %lu, p3 = %lu, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw),
hwdata->params.p1, hwdata->params.p2, hwdata->params.p3,
parent_rate, rate);
return 0;
}
static int _si5351_msynth_reparent(struct si5351_driver_data *drvdata,
int num, enum si5351_multisynth_src parent)
{
if (parent == SI5351_MULTISYNTH_SRC_DEFAULT)
return 0;
if (num > 8)
return -EINVAL;
si5351_set_bits(drvdata, SI5351_CLK0_CTRL + num, SI5351_CLK_PLL_SELECT,
(parent == SI5351_MULTISYNTH_SRC_VCO0) ? 0 :
SI5351_CLK_PLL_SELECT);
return 0;
}
static unsigned char si5351_msynth_get_parent(struct clk_hw *hw)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
u8 val;
val = si5351_reg_read(hwdata->drvdata, SI5351_CLK0_CTRL + hwdata->num);
return (val & SI5351_CLK_PLL_SELECT) ? 1 : 0;
}
static int si5351_msynth_set_parent(struct clk_hw *hw, u8 index)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
return _si5351_msynth_reparent(hwdata->drvdata, hwdata->num,
(index == 0) ? SI5351_MULTISYNTH_SRC_VCO0 :
SI5351_MULTISYNTH_SRC_VCO1);
}
static unsigned long si5351_msynth_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
u8 reg = si5351_msynth_params_address(hwdata->num);
unsigned long long rate;
unsigned long m;
if (!hwdata->params.valid)
si5351_read_parameters(hwdata->drvdata, reg, &hwdata->params);
rate = parent_rate;
if (hwdata->num > 5) {
m = hwdata->params.p1;
} else if (hwdata->params.p3 == 0) {
return parent_rate;
} else if ((si5351_reg_read(hwdata->drvdata, reg + 2) &
SI5351_OUTPUT_CLK_DIVBY4) == SI5351_OUTPUT_CLK_DIVBY4) {
m = 4;
} else {
rate *= 128 * hwdata->params.p3;
m = hwdata->params.p1 * hwdata->params.p3;
m += hwdata->params.p2;
m += 512 * hwdata->params.p3;
}
if (m == 0)
return 0;
do_div(rate, m);
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: p1 = %lu, p2 = %lu, p3 = %lu, m = %lu, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw),
hwdata->params.p1, hwdata->params.p2, hwdata->params.p3,
m, parent_rate, (unsigned long)rate);
return (unsigned long)rate;
}
static long si5351_msynth_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
unsigned long long lltmp;
unsigned long a, b, c;
int divby4;
if (hwdata->num >= 6 && rate > SI5351_MULTISYNTH67_MAX_FREQ)
rate = SI5351_MULTISYNTH67_MAX_FREQ;
if (rate > SI5351_MULTISYNTH_MAX_FREQ)
rate = SI5351_MULTISYNTH_MAX_FREQ;
if (rate < SI5351_MULTISYNTH_MIN_FREQ)
rate = SI5351_MULTISYNTH_MIN_FREQ;
divby4 = 0;
if (rate > SI5351_MULTISYNTH_DIVBY4_FREQ)
divby4 = 1;
if (clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT) {
if (divby4 == 0) {
lltmp = SI5351_PLL_VCO_MAX;
do_div(lltmp, rate);
a = (unsigned long)lltmp;
} else
a = 4;
b = 0;
c = 1;
*parent_rate = a * rate;
} else if (hwdata->num >= 6) {
a = DIV_ROUND_CLOSEST(*parent_rate, rate);
if (a < SI5351_MULTISYNTH_A_MIN)
a = SI5351_MULTISYNTH_A_MIN;
if (a > SI5351_MULTISYNTH67_A_MAX)
a = SI5351_MULTISYNTH67_A_MAX;
b = 0;
c = 1;
} else {
unsigned long rfrac, denom;
if (divby4) {
rate = SI5351_MULTISYNTH_DIVBY4_FREQ;
divby4 = 0;
}
a = *parent_rate / rate;
if (a < SI5351_MULTISYNTH_A_MIN)
a = SI5351_MULTISYNTH_A_MIN;
if (a > SI5351_MULTISYNTH_A_MAX)
a = SI5351_MULTISYNTH_A_MAX;
denom = 1000 * 1000;
lltmp = (*parent_rate) % rate;
lltmp *= denom;
do_div(lltmp, rate);
rfrac = (unsigned long)lltmp;
b = 0;
c = 1;
if (rfrac)
rational_best_approximation(rfrac, denom,
SI5351_MULTISYNTH_B_MAX, SI5351_MULTISYNTH_C_MAX,
&b, &c);
}
lltmp = *parent_rate;
lltmp *= c;
do_div(lltmp, a * c + b);
rate = (unsigned long)lltmp;
if (divby4) {
hwdata->params.p3 = 1;
hwdata->params.p2 = 0;
hwdata->params.p1 = 0;
} else if (hwdata->num >= 6) {
hwdata->params.p3 = 0;
hwdata->params.p2 = 0;
hwdata->params.p1 = a;
} else {
hwdata->params.p3 = c;
hwdata->params.p2 = (128 * b) % c;
hwdata->params.p1 = 128 * a;
hwdata->params.p1 += (128 * b / c);
hwdata->params.p1 -= 512;
}
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: a = %lu, b = %lu, c = %lu, divby4 = %d, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw), a, b, c, divby4,
*parent_rate, rate);
return rate;
}
static int si5351_msynth_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
u8 reg = si5351_msynth_params_address(hwdata->num);
int divby4 = 0;
si5351_write_parameters(hwdata->drvdata, reg, &hwdata->params);
if (rate > SI5351_MULTISYNTH_DIVBY4_FREQ)
divby4 = 1;
if (hwdata->num < 6) {
si5351_set_bits(hwdata->drvdata, reg + 2,
SI5351_OUTPUT_CLK_DIVBY4,
(divby4) ? SI5351_OUTPUT_CLK_DIVBY4 : 0);
si5351_set_bits(hwdata->drvdata, SI5351_CLK0_CTRL + hwdata->num,
SI5351_CLK_INTEGER_MODE,
(hwdata->params.p2 == 0) ? SI5351_CLK_INTEGER_MODE : 0);
}
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: p1 = %lu, p2 = %lu, p3 = %lu, divby4 = %d, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw),
hwdata->params.p1, hwdata->params.p2, hwdata->params.p3,
divby4, parent_rate, rate);
return 0;
}
static int _si5351_clkout_reparent(struct si5351_driver_data *drvdata,
int num, enum si5351_clkout_src parent)
{
u8 val;
if (num > 8)
return -EINVAL;
switch (parent) {
case SI5351_CLKOUT_SRC_MSYNTH_N:
val = SI5351_CLK_INPUT_MULTISYNTH_N;
break;
case SI5351_CLKOUT_SRC_MSYNTH_0_4:
if (num == 0 || num == 4)
val = SI5351_CLK_INPUT_MULTISYNTH_N;
else
val = SI5351_CLK_INPUT_MULTISYNTH_0_4;
break;
case SI5351_CLKOUT_SRC_XTAL:
val = SI5351_CLK_INPUT_XTAL;
break;
case SI5351_CLKOUT_SRC_CLKIN:
if (drvdata->variant != SI5351_VARIANT_C)
return -EINVAL;
val = SI5351_CLK_INPUT_CLKIN;
break;
default:
return 0;
}
si5351_set_bits(drvdata, SI5351_CLK0_CTRL + num,
SI5351_CLK_INPUT_MASK, val);
return 0;
}
static int _si5351_clkout_set_drive_strength(
struct si5351_driver_data *drvdata, int num,
enum si5351_drive_strength drive)
{
u8 mask;
if (num > 8)
return -EINVAL;
switch (drive) {
case SI5351_DRIVE_2MA:
mask = SI5351_CLK_DRIVE_STRENGTH_2MA;
break;
case SI5351_DRIVE_4MA:
mask = SI5351_CLK_DRIVE_STRENGTH_4MA;
break;
case SI5351_DRIVE_6MA:
mask = SI5351_CLK_DRIVE_STRENGTH_6MA;
break;
case SI5351_DRIVE_8MA:
mask = SI5351_CLK_DRIVE_STRENGTH_8MA;
break;
default:
return 0;
}
si5351_set_bits(drvdata, SI5351_CLK0_CTRL + num,
SI5351_CLK_DRIVE_STRENGTH_MASK, mask);
return 0;
}
static int _si5351_clkout_set_disable_state(
struct si5351_driver_data *drvdata, int num,
enum si5351_disable_state state)
{
u8 reg = (num < 4) ? SI5351_CLK3_0_DISABLE_STATE :
SI5351_CLK7_4_DISABLE_STATE;
u8 shift = (num < 4) ? (2 * num) : (2 * (num-4));
u8 mask = SI5351_CLK_DISABLE_STATE_MASK << shift;
u8 val;
if (num > 8)
return -EINVAL;
switch (state) {
case SI5351_DISABLE_LOW:
val = SI5351_CLK_DISABLE_STATE_LOW;
break;
case SI5351_DISABLE_HIGH:
val = SI5351_CLK_DISABLE_STATE_HIGH;
break;
case SI5351_DISABLE_FLOATING:
val = SI5351_CLK_DISABLE_STATE_FLOAT;
break;
case SI5351_DISABLE_NEVER:
val = SI5351_CLK_DISABLE_STATE_NEVER;
break;
default:
return 0;
}
si5351_set_bits(drvdata, reg, mask, val << shift);
return 0;
}
static int si5351_clkout_prepare(struct clk_hw *hw)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
si5351_set_bits(hwdata->drvdata, SI5351_CLK0_CTRL + hwdata->num,
SI5351_CLK_POWERDOWN, 0);
si5351_set_bits(hwdata->drvdata, SI5351_OUTPUT_ENABLE_CTRL,
(1 << hwdata->num), 0);
return 0;
}
static void si5351_clkout_unprepare(struct clk_hw *hw)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
si5351_set_bits(hwdata->drvdata, SI5351_CLK0_CTRL + hwdata->num,
SI5351_CLK_POWERDOWN, SI5351_CLK_POWERDOWN);
si5351_set_bits(hwdata->drvdata, SI5351_OUTPUT_ENABLE_CTRL,
(1 << hwdata->num), (1 << hwdata->num));
}
static u8 si5351_clkout_get_parent(struct clk_hw *hw)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
int index = 0;
unsigned char val;
val = si5351_reg_read(hwdata->drvdata, SI5351_CLK0_CTRL + hwdata->num);
switch (val & SI5351_CLK_INPUT_MASK) {
case SI5351_CLK_INPUT_MULTISYNTH_N:
index = 0;
break;
case SI5351_CLK_INPUT_MULTISYNTH_0_4:
index = 1;
break;
case SI5351_CLK_INPUT_XTAL:
index = 2;
break;
case SI5351_CLK_INPUT_CLKIN:
index = 3;
break;
}
return index;
}
static int si5351_clkout_set_parent(struct clk_hw *hw, u8 index)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
enum si5351_clkout_src parent = SI5351_CLKOUT_SRC_DEFAULT;
switch (index) {
case 0:
parent = SI5351_CLKOUT_SRC_MSYNTH_N;
break;
case 1:
parent = SI5351_CLKOUT_SRC_MSYNTH_0_4;
break;
case 2:
parent = SI5351_CLKOUT_SRC_XTAL;
break;
case 3:
parent = SI5351_CLKOUT_SRC_CLKIN;
break;
}
return _si5351_clkout_reparent(hwdata->drvdata, hwdata->num, parent);
}
static unsigned long si5351_clkout_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
unsigned char reg;
unsigned char rdiv;
if (hwdata->num <= 5)
reg = si5351_msynth_params_address(hwdata->num) + 2;
else
reg = SI5351_CLK6_7_OUTPUT_DIVIDER;
rdiv = si5351_reg_read(hwdata->drvdata, reg);
if (hwdata->num == 6) {
rdiv &= SI5351_OUTPUT_CLK6_DIV_MASK;
} else {
rdiv &= SI5351_OUTPUT_CLK_DIV_MASK;
rdiv >>= SI5351_OUTPUT_CLK_DIV_SHIFT;
}
return parent_rate >> rdiv;
}
static long si5351_clkout_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
unsigned char rdiv;
if (hwdata->num >= 6 && rate > SI5351_CLKOUT67_MAX_FREQ)
rate = SI5351_CLKOUT67_MAX_FREQ;
if (rate > SI5351_CLKOUT_MAX_FREQ)
rate = SI5351_CLKOUT_MAX_FREQ;
if (rate < SI5351_CLKOUT_MIN_FREQ)
rate = SI5351_CLKOUT_MIN_FREQ;
if (clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT) {
rdiv = SI5351_OUTPUT_CLK_DIV_1;
while (rate < SI5351_MULTISYNTH_MIN_FREQ &&
rdiv < SI5351_OUTPUT_CLK_DIV_128) {
rdiv += 1;
rate *= 2;
}
*parent_rate = rate;
} else {
unsigned long new_rate, new_err, err;
rdiv = SI5351_OUTPUT_CLK_DIV_1;
new_rate = *parent_rate;
err = abs(new_rate - rate);
do {
new_rate >>= 1;
new_err = abs(new_rate - rate);
if (new_err > err || rdiv == SI5351_OUTPUT_CLK_DIV_128)
break;
rdiv++;
err = new_err;
} while (1);
}
rate = *parent_rate >> rdiv;
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: rdiv = %u, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw), (1 << rdiv),
*parent_rate, rate);
return rate;
}
static int si5351_clkout_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct si5351_hw_data *hwdata =
container_of(hw, struct si5351_hw_data, hw);
unsigned long new_rate, new_err, err;
unsigned char rdiv;
rdiv = SI5351_OUTPUT_CLK_DIV_1;
new_rate = parent_rate;
err = abs(new_rate - rate);
do {
new_rate >>= 1;
new_err = abs(new_rate - rate);
if (new_err > err || rdiv == SI5351_OUTPUT_CLK_DIV_128)
break;
rdiv++;
err = new_err;
} while (1);
switch (hwdata->num) {
case 6:
si5351_set_bits(hwdata->drvdata, SI5351_CLK6_7_OUTPUT_DIVIDER,
SI5351_OUTPUT_CLK6_DIV_MASK, rdiv);
break;
case 7:
si5351_set_bits(hwdata->drvdata, SI5351_CLK6_7_OUTPUT_DIVIDER,
SI5351_OUTPUT_CLK_DIV_MASK,
rdiv << SI5351_OUTPUT_CLK_DIV_SHIFT);
break;
default:
si5351_set_bits(hwdata->drvdata,
si5351_msynth_params_address(hwdata->num) + 2,
SI5351_OUTPUT_CLK_DIV_MASK,
rdiv << SI5351_OUTPUT_CLK_DIV_SHIFT);
}
si5351_set_bits(hwdata->drvdata, SI5351_CLK0_CTRL + hwdata->num,
SI5351_CLK_POWERDOWN, 0);
dev_dbg(&hwdata->drvdata->client->dev,
"%s - %s: rdiv = %u, parent_rate = %lu, rate = %lu\n",
__func__, clk_hw_get_name(hw), (1 << rdiv),
parent_rate, rate);
return 0;
}
static int si5351_dt_parse(struct i2c_client *client,
enum si5351_variant variant)
{
struct device_node *child, *np = client->dev.of_node;
struct si5351_platform_data *pdata;
struct property *prop;
const __be32 *p;
int num = 0;
u32 val;
if (np == NULL)
return 0;
pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
of_property_for_each_u32(np, "silabs,pll-source", prop, p, num) {
if (num >= 2) {
dev_err(&client->dev,
"invalid pll %d on pll-source prop\n", num);
return -EINVAL;
}
p = of_prop_next_u32(prop, p, &val);
if (!p) {
dev_err(&client->dev,
"missing pll-source for pll %d\n", num);
return -EINVAL;
}
switch (val) {
case 0:
pdata->pll_src[num] = SI5351_PLL_SRC_XTAL;
break;
case 1:
if (variant != SI5351_VARIANT_C) {
dev_err(&client->dev,
"invalid parent %d for pll %d\n",
val, num);
return -EINVAL;
}
pdata->pll_src[num] = SI5351_PLL_SRC_CLKIN;
break;
default:
dev_err(&client->dev,
"invalid parent %d for pll %d\n", val, num);
return -EINVAL;
}
}
for_each_child_of_node(np, child) {
if (of_property_read_u32(child, "reg", &num)) {
dev_err(&client->dev, "missing reg property of %s\n",
child->name);
goto put_child;
}
if (num >= 8 ||
(variant == SI5351_VARIANT_A3 && num >= 3)) {
dev_err(&client->dev, "invalid clkout %d\n", num);
goto put_child;
}
if (!of_property_read_u32(child, "silabs,multisynth-source",
&val)) {
switch (val) {
case 0:
pdata->clkout[num].multisynth_src =
SI5351_MULTISYNTH_SRC_VCO0;
break;
case 1:
pdata->clkout[num].multisynth_src =
SI5351_MULTISYNTH_SRC_VCO1;
break;
default:
dev_err(&client->dev,
"invalid parent %d for multisynth %d\n",
val, num);
goto put_child;
}
}
if (!of_property_read_u32(child, "silabs,clock-source", &val)) {
switch (val) {
case 0:
pdata->clkout[num].clkout_src =
SI5351_CLKOUT_SRC_MSYNTH_N;
break;
case 1:
pdata->clkout[num].clkout_src =
SI5351_CLKOUT_SRC_MSYNTH_0_4;
break;
case 2:
pdata->clkout[num].clkout_src =
SI5351_CLKOUT_SRC_XTAL;
break;
case 3:
if (variant != SI5351_VARIANT_C) {
dev_err(&client->dev,
"invalid parent %d for clkout %d\n",
val, num);
goto put_child;
}
pdata->clkout[num].clkout_src =
SI5351_CLKOUT_SRC_CLKIN;
break;
default:
dev_err(&client->dev,
"invalid parent %d for clkout %d\n",
val, num);
goto put_child;
}
}
if (!of_property_read_u32(child, "silabs,drive-strength",
&val)) {
switch (val) {
case SI5351_DRIVE_2MA:
case SI5351_DRIVE_4MA:
case SI5351_DRIVE_6MA:
case SI5351_DRIVE_8MA:
pdata->clkout[num].drive = val;
break;
default:
dev_err(&client->dev,
"invalid drive strength %d for clkout %d\n",
val, num);
goto put_child;
}
}
if (!of_property_read_u32(child, "silabs,disable-state",
&val)) {
switch (val) {
case 0:
pdata->clkout[num].disable_state =
SI5351_DISABLE_LOW;
break;
case 1:
pdata->clkout[num].disable_state =
SI5351_DISABLE_HIGH;
break;
case 2:
pdata->clkout[num].disable_state =
SI5351_DISABLE_FLOATING;
break;
case 3:
pdata->clkout[num].disable_state =
SI5351_DISABLE_NEVER;
break;
default:
dev_err(&client->dev,
"invalid disable state %d for clkout %d\n",
val, num);
goto put_child;
}
}
if (!of_property_read_u32(child, "clock-frequency", &val))
pdata->clkout[num].rate = val;
pdata->clkout[num].pll_master =
of_property_read_bool(child, "silabs,pll-master");
}
client->dev.platform_data = pdata;
return 0;
put_child:
of_node_put(child);
return -EINVAL;
}
static int si5351_dt_parse(struct i2c_client *client, enum si5351_variant variant)
{
return 0;
}
static int si5351_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
enum si5351_variant variant = (enum si5351_variant)id->driver_data;
struct si5351_platform_data *pdata;
struct si5351_driver_data *drvdata;
struct clk_init_data init;
struct clk *clk;
const char *parent_names[4];
u8 num_parents, num_clocks;
int ret, n;
ret = si5351_dt_parse(client, variant);
if (ret)
return ret;
pdata = client->dev.platform_data;
if (!pdata)
return -EINVAL;
drvdata = devm_kzalloc(&client->dev, sizeof(*drvdata), GFP_KERNEL);
if (drvdata == NULL) {
dev_err(&client->dev, "unable to allocate driver data\n");
return -ENOMEM;
}
i2c_set_clientdata(client, drvdata);
drvdata->client = client;
drvdata->variant = variant;
drvdata->pxtal = devm_clk_get(&client->dev, "xtal");
drvdata->pclkin = devm_clk_get(&client->dev, "clkin");
if (PTR_ERR(drvdata->pxtal) == -EPROBE_DEFER ||
PTR_ERR(drvdata->pclkin) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (IS_ERR(drvdata->pxtal) &&
(drvdata->variant != SI5351_VARIANT_C || IS_ERR(drvdata->pclkin))) {
dev_err(&client->dev, "missing parent clock\n");
return -EINVAL;
}
drvdata->regmap = devm_regmap_init_i2c(client, &si5351_regmap_config);
if (IS_ERR(drvdata->regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(drvdata->regmap);
}
si5351_reg_write(drvdata, SI5351_INTERRUPT_MASK, 0xf0);
if (drvdata->variant != SI5351_VARIANT_C)
si5351_set_bits(drvdata, SI5351_PLL_INPUT_SOURCE,
SI5351_PLLA_SOURCE | SI5351_PLLB_SOURCE, 0);
for (n = 0; n < 2; n++) {
ret = _si5351_pll_reparent(drvdata, n, pdata->pll_src[n]);
if (ret) {
dev_err(&client->dev,
"failed to reparent pll %d to %d\n",
n, pdata->pll_src[n]);
return ret;
}
}
for (n = 0; n < 8; n++) {
ret = _si5351_msynth_reparent(drvdata, n,
pdata->clkout[n].multisynth_src);
if (ret) {
dev_err(&client->dev,
"failed to reparent multisynth %d to %d\n",
n, pdata->clkout[n].multisynth_src);
return ret;
}
ret = _si5351_clkout_reparent(drvdata, n,
pdata->clkout[n].clkout_src);
if (ret) {
dev_err(&client->dev,
"failed to reparent clkout %d to %d\n",
n, pdata->clkout[n].clkout_src);
return ret;
}
ret = _si5351_clkout_set_drive_strength(drvdata, n,
pdata->clkout[n].drive);
if (ret) {
dev_err(&client->dev,
"failed set drive strength of clkout%d to %d\n",
n, pdata->clkout[n].drive);
return ret;
}
ret = _si5351_clkout_set_disable_state(drvdata, n,
pdata->clkout[n].disable_state);
if (ret) {
dev_err(&client->dev,
"failed set disable state of clkout%d to %d\n",
n, pdata->clkout[n].disable_state);
return ret;
}
}
if (!IS_ERR(drvdata->pxtal))
clk_prepare_enable(drvdata->pxtal);
if (!IS_ERR(drvdata->pclkin))
clk_prepare_enable(drvdata->pclkin);
memset(&init, 0, sizeof(init));
init.name = si5351_input_names[0];
init.ops = &si5351_xtal_ops;
init.flags = 0;
if (!IS_ERR(drvdata->pxtal)) {
drvdata->pxtal_name = __clk_get_name(drvdata->pxtal);
init.parent_names = &drvdata->pxtal_name;
init.num_parents = 1;
}
drvdata->xtal.init = &init;
clk = devm_clk_register(&client->dev, &drvdata->xtal);
if (IS_ERR(clk)) {
dev_err(&client->dev, "unable to register %s\n", init.name);
ret = PTR_ERR(clk);
goto err_clk;
}
if (drvdata->variant == SI5351_VARIANT_C) {
memset(&init, 0, sizeof(init));
init.name = si5351_input_names[1];
init.ops = &si5351_clkin_ops;
if (!IS_ERR(drvdata->pclkin)) {
drvdata->pclkin_name = __clk_get_name(drvdata->pclkin);
init.parent_names = &drvdata->pclkin_name;
init.num_parents = 1;
}
drvdata->clkin.init = &init;
clk = devm_clk_register(&client->dev, &drvdata->clkin);
if (IS_ERR(clk)) {
dev_err(&client->dev, "unable to register %s\n",
init.name);
ret = PTR_ERR(clk);
goto err_clk;
}
}
num_parents = (drvdata->variant == SI5351_VARIANT_C) ? 2 : 1;
parent_names[0] = si5351_input_names[0];
parent_names[1] = si5351_input_names[1];
drvdata->pll[0].num = 0;
drvdata->pll[0].drvdata = drvdata;
drvdata->pll[0].hw.init = &init;
memset(&init, 0, sizeof(init));
init.name = si5351_pll_names[0];
init.ops = &si5351_pll_ops;
init.flags = 0;
init.parent_names = parent_names;
init.num_parents = num_parents;
clk = devm_clk_register(&client->dev, &drvdata->pll[0].hw);
if (IS_ERR(clk)) {
dev_err(&client->dev, "unable to register %s\n", init.name);
ret = PTR_ERR(clk);
goto err_clk;
}
drvdata->pll[1].num = 1;
drvdata->pll[1].drvdata = drvdata;
drvdata->pll[1].hw.init = &init;
memset(&init, 0, sizeof(init));
if (drvdata->variant == SI5351_VARIANT_B) {
init.name = si5351_pll_names[2];
init.ops = &si5351_vxco_ops;
init.flags = CLK_IS_ROOT;
init.parent_names = NULL;
init.num_parents = 0;
} else {
init.name = si5351_pll_names[1];
init.ops = &si5351_pll_ops;
init.flags = 0;
init.parent_names = parent_names;
init.num_parents = num_parents;
}
clk = devm_clk_register(&client->dev, &drvdata->pll[1].hw);
if (IS_ERR(clk)) {
dev_err(&client->dev, "unable to register %s\n", init.name);
ret = PTR_ERR(clk);
goto err_clk;
}
num_clocks = (drvdata->variant == SI5351_VARIANT_A3) ? 3 : 8;
parent_names[0] = si5351_pll_names[0];
if (drvdata->variant == SI5351_VARIANT_B)
parent_names[1] = si5351_pll_names[2];
else
parent_names[1] = si5351_pll_names[1];
drvdata->msynth = devm_kzalloc(&client->dev, num_clocks *
sizeof(*drvdata->msynth), GFP_KERNEL);
drvdata->clkout = devm_kzalloc(&client->dev, num_clocks *
sizeof(*drvdata->clkout), GFP_KERNEL);
drvdata->onecell.clk_num = num_clocks;
drvdata->onecell.clks = devm_kzalloc(&client->dev,
num_clocks * sizeof(*drvdata->onecell.clks), GFP_KERNEL);
if (WARN_ON(!drvdata->msynth || !drvdata->clkout ||
!drvdata->onecell.clks)) {
ret = -ENOMEM;
goto err_clk;
}
for (n = 0; n < num_clocks; n++) {
drvdata->msynth[n].num = n;
drvdata->msynth[n].drvdata = drvdata;
drvdata->msynth[n].hw.init = &init;
memset(&init, 0, sizeof(init));
init.name = si5351_msynth_names[n];
init.ops = &si5351_msynth_ops;
init.flags = 0;
if (pdata->clkout[n].pll_master)
init.flags |= CLK_SET_RATE_PARENT;
init.parent_names = parent_names;
init.num_parents = 2;
clk = devm_clk_register(&client->dev, &drvdata->msynth[n].hw);
if (IS_ERR(clk)) {
dev_err(&client->dev, "unable to register %s\n",
init.name);
ret = PTR_ERR(clk);
goto err_clk;
}
}
num_parents = (drvdata->variant == SI5351_VARIANT_C) ? 4 : 3;
parent_names[2] = si5351_input_names[0];
parent_names[3] = si5351_input_names[1];
for (n = 0; n < num_clocks; n++) {
parent_names[0] = si5351_msynth_names[n];
parent_names[1] = (n < 4) ? si5351_msynth_names[0] :
si5351_msynth_names[4];
drvdata->clkout[n].num = n;
drvdata->clkout[n].drvdata = drvdata;
drvdata->clkout[n].hw.init = &init;
memset(&init, 0, sizeof(init));
init.name = si5351_clkout_names[n];
init.ops = &si5351_clkout_ops;
init.flags = 0;
if (pdata->clkout[n].clkout_src == SI5351_CLKOUT_SRC_MSYNTH_N)
init.flags |= CLK_SET_RATE_PARENT;
init.parent_names = parent_names;
init.num_parents = num_parents;
clk = devm_clk_register(&client->dev, &drvdata->clkout[n].hw);
if (IS_ERR(clk)) {
dev_err(&client->dev, "unable to register %s\n",
init.name);
ret = PTR_ERR(clk);
goto err_clk;
}
drvdata->onecell.clks[n] = clk;
if (pdata->clkout[n].rate != 0) {
int ret;
ret = clk_set_rate(clk, pdata->clkout[n].rate);
if (ret != 0) {
dev_err(&client->dev, "Cannot set rate : %d\n",
ret);
}
}
}
ret = of_clk_add_provider(client->dev.of_node, of_clk_src_onecell_get,
&drvdata->onecell);
if (ret) {
dev_err(&client->dev, "unable to add clk provider\n");
goto err_clk;
}
return 0;
err_clk:
if (!IS_ERR(drvdata->pxtal))
clk_disable_unprepare(drvdata->pxtal);
if (!IS_ERR(drvdata->pclkin))
clk_disable_unprepare(drvdata->pclkin);
return ret;
}
