int tegra_asoc_utils_set_rate(struct tegra_asoc_utils_data *data, int srate,
int mclk)
{
int new_baseclock;
bool clk_change;
int err;
switch (srate) {
case 11025:
case 22050:
case 44100:
case 88200:
new_baseclock = 56448000;
break;
case 8000:
case 16000:
case 32000:
case 48000:
case 64000:
case 96000:
new_baseclock = 73728000;
break;
default:
return -EINVAL;
}
clk_change = ((new_baseclock != data->set_baseclock) ||
(mclk != data->set_mclk));
if (!clk_change)
return 0;
data->set_baseclock = 0;
data->set_mclk = 0;
clk_disable(data->clk_cdev1);
clk_disable(data->clk_pll_a_out0);
clk_disable(data->clk_pll_a);
err = clk_set_rate(data->clk_pll_a, new_baseclock);
if (err) {
dev_err(data->dev, "Can't set pll_a rate: %d\n", err);
return err;
}
err = clk_set_rate(data->clk_pll_a_out0, mclk);
if (err) {
dev_err(data->dev, "Can't set pll_a_out0 rate: %d\n", err);
return err;
}
err = clk_enable(data->clk_pll_a);
if (err) {
dev_err(data->dev, "Can't enable pll_a: %d\n", err);
return err;
}
err = clk_enable(data->clk_pll_a_out0);
if (err) {
dev_err(data->dev, "Can't enable pll_a_out0: %d\n", err);
return err;
}
err = clk_enable(data->clk_cdev1);
if (err) {
dev_err(data->dev, "Can't enable cdev1: %d\n", err);
return err;
}
data->set_baseclock = new_baseclock;
data->set_mclk = mclk;
return 0;
}
int tegra_asoc_utils_init(struct tegra_asoc_utils_data *data,
struct device *dev)
{
int ret;
data->dev = dev;
data->clk_pll_a = clk_get_sys(NULL, "pll_a");
if (IS_ERR(data->clk_pll_a)) {
dev_err(data->dev, "Can't retrieve clk pll_a\n");
ret = PTR_ERR(data->clk_pll_a);
goto err;
}
data->clk_pll_a_out0 = clk_get_sys(NULL, "pll_a_out0");
if (IS_ERR(data->clk_pll_a_out0)) {
dev_err(data->dev, "Can't retrieve clk pll_a_out0\n");
ret = PTR_ERR(data->clk_pll_a_out0);
goto err_put_pll_a;
}
data->clk_cdev1 = clk_get_sys(NULL, "cdev1");
if (IS_ERR(data->clk_cdev1)) {
dev_err(data->dev, "Can't retrieve clk cdev1\n");
ret = PTR_ERR(data->clk_cdev1);
goto err_put_pll_a_out0;
}
return 0;
err_put_pll_a_out0:
clk_put(data->clk_pll_a_out0);
err_put_pll_a:
clk_put(data->clk_pll_a);
err:
return ret;
}
void tegra_asoc_utils_fini(struct tegra_asoc_utils_data *data)
{
clk_put(data->clk_cdev1);
clk_put(data->clk_pll_a_out0);
clk_put(data->clk_pll_a);
}
