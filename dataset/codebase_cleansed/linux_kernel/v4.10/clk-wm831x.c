static int wm831x_xtal_is_prepared(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
xtal_hw);
return clkdata->xtal_ena;
}
static unsigned long wm831x_xtal_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
xtal_hw);
if (clkdata->xtal_ena)
return 32768;
else
return 0;
}
static int wm831x_fll_is_prepared(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
fll_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_read(wm831x, WM831X_FLL_CONTROL_1);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read FLL_CONTROL_1: %d\n",
ret);
return true;
}
return (ret & WM831X_FLL_ENA) != 0;
}
static int wm831x_fll_prepare(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
fll_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_set_bits(wm831x, WM831X_FLL_CONTROL_1,
WM831X_FLL_ENA, WM831X_FLL_ENA);
if (ret != 0)
dev_crit(wm831x->dev, "Failed to enable FLL: %d\n", ret);
usleep_range(2000, 2000);
return ret;
}
static void wm831x_fll_unprepare(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
fll_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_set_bits(wm831x, WM831X_FLL_CONTROL_1, WM831X_FLL_ENA, 0);
if (ret != 0)
dev_crit(wm831x->dev, "Failed to disable FLL: %d\n", ret);
}
static unsigned long wm831x_fll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
fll_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_read(wm831x, WM831X_CLOCK_CONTROL_2);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read CLOCK_CONTROL_2: %d\n",
ret);
return 0;
}
if (ret & WM831X_FLL_AUTO)
return wm831x_fll_auto_rates[ret & WM831X_FLL_AUTO_FREQ_MASK];
dev_err(wm831x->dev, "FLL only supported in AUTO mode\n");
return 0;
}
static long wm831x_fll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *unused)
{
int best = 0;
int i;
for (i = 0; i < ARRAY_SIZE(wm831x_fll_auto_rates); i++)
if (abs(wm831x_fll_auto_rates[i] - rate) <
abs(wm831x_fll_auto_rates[best] - rate))
best = i;
return wm831x_fll_auto_rates[best];
}
static int wm831x_fll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
fll_hw);
struct wm831x *wm831x = clkdata->wm831x;
int i;
for (i = 0; i < ARRAY_SIZE(wm831x_fll_auto_rates); i++)
if (wm831x_fll_auto_rates[i] == rate)
break;
if (i == ARRAY_SIZE(wm831x_fll_auto_rates))
return -EINVAL;
if (wm831x_fll_is_prepared(hw))
return -EPERM;
return wm831x_set_bits(wm831x, WM831X_CLOCK_CONTROL_2,
WM831X_FLL_AUTO_FREQ_MASK, i);
}
static u8 wm831x_fll_get_parent(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
fll_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_read(wm831x, WM831X_CLOCK_CONTROL_2);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read CLOCK_CONTROL_2: %d\n",
ret);
return 0;
}
if (ret & WM831X_FLL_AUTO)
return 0;
ret = wm831x_reg_read(wm831x, WM831X_FLL_CONTROL_5);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read FLL_CONTROL_5: %d\n",
ret);
return 0;
}
switch (ret & WM831X_FLL_CLK_SRC_MASK) {
case 0:
return 0;
case 1:
return 1;
default:
dev_err(wm831x->dev, "Unsupported FLL clock source %d\n",
ret & WM831X_FLL_CLK_SRC_MASK);
return 0;
}
}
static int wm831x_clkout_is_prepared(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
clkout_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_read(wm831x, WM831X_CLOCK_CONTROL_1);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read CLOCK_CONTROL_1: %d\n",
ret);
return false;
}
return (ret & WM831X_CLKOUT_ENA) != 0;
}
static int wm831x_clkout_prepare(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
clkout_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_unlock(wm831x);
if (ret != 0) {
dev_crit(wm831x->dev, "Failed to lock registers: %d\n", ret);
return ret;
}
ret = wm831x_set_bits(wm831x, WM831X_CLOCK_CONTROL_1,
WM831X_CLKOUT_ENA, WM831X_CLKOUT_ENA);
if (ret != 0)
dev_crit(wm831x->dev, "Failed to enable CLKOUT: %d\n", ret);
wm831x_reg_lock(wm831x);
return ret;
}
static void wm831x_clkout_unprepare(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
clkout_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_unlock(wm831x);
if (ret != 0) {
dev_crit(wm831x->dev, "Failed to lock registers: %d\n", ret);
return;
}
ret = wm831x_set_bits(wm831x, WM831X_CLOCK_CONTROL_1,
WM831X_CLKOUT_ENA, 0);
if (ret != 0)
dev_crit(wm831x->dev, "Failed to disable CLKOUT: %d\n", ret);
wm831x_reg_lock(wm831x);
}
static u8 wm831x_clkout_get_parent(struct clk_hw *hw)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
clkout_hw);
struct wm831x *wm831x = clkdata->wm831x;
int ret;
ret = wm831x_reg_read(wm831x, WM831X_CLOCK_CONTROL_1);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read CLOCK_CONTROL_1: %d\n",
ret);
return 0;
}
if (ret & WM831X_CLKOUT_SRC)
return 1;
else
return 0;
}
static int wm831x_clkout_set_parent(struct clk_hw *hw, u8 parent)
{
struct wm831x_clk *clkdata = container_of(hw, struct wm831x_clk,
clkout_hw);
struct wm831x *wm831x = clkdata->wm831x;
return wm831x_set_bits(wm831x, WM831X_CLOCK_CONTROL_1,
WM831X_CLKOUT_SRC,
parent << WM831X_CLKOUT_SRC_SHIFT);
}
static int wm831x_clk_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_clk *clkdata;
int ret;
clkdata = devm_kzalloc(&pdev->dev, sizeof(*clkdata), GFP_KERNEL);
if (!clkdata)
return -ENOMEM;
clkdata->wm831x = wm831x;
ret = wm831x_reg_read(wm831x, WM831X_CLOCK_CONTROL_2);
if (ret < 0) {
dev_err(wm831x->dev, "Unable to read CLOCK_CONTROL_2: %d\n",
ret);
return ret;
}
clkdata->xtal_ena = ret & WM831X_XTAL_ENA;
clkdata->xtal_hw.init = &wm831x_xtal_init;
ret = devm_clk_hw_register(&pdev->dev, &clkdata->xtal_hw);
if (ret)
return ret;
clkdata->fll_hw.init = &wm831x_fll_init;
ret = devm_clk_hw_register(&pdev->dev, &clkdata->fll_hw);
if (ret)
return ret;
clkdata->clkout_hw.init = &wm831x_clkout_init;
ret = devm_clk_hw_register(&pdev->dev, &clkdata->clkout_hw);
if (ret)
return ret;
platform_set_drvdata(pdev, clkdata);
return 0;
}
