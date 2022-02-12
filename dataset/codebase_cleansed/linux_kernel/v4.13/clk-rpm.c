static int clk_rpm_handoff(struct clk_rpm *r)
{
int ret;
u32 value = INT_MAX;
ret = qcom_rpm_write(r->rpm, QCOM_RPM_ACTIVE_STATE,
r->rpm_clk_id, &value, 1);
if (ret)
return ret;
ret = qcom_rpm_write(r->rpm, QCOM_RPM_SLEEP_STATE,
r->rpm_clk_id, &value, 1);
if (ret)
return ret;
return 0;
}
static int clk_rpm_set_rate_active(struct clk_rpm *r, unsigned long rate)
{
u32 value = DIV_ROUND_UP(rate, 1000);
return qcom_rpm_write(r->rpm, QCOM_RPM_ACTIVE_STATE,
r->rpm_clk_id, &value, 1);
}
static int clk_rpm_set_rate_sleep(struct clk_rpm *r, unsigned long rate)
{
u32 value = DIV_ROUND_UP(rate, 1000);
return qcom_rpm_write(r->rpm, QCOM_RPM_SLEEP_STATE,
r->rpm_clk_id, &value, 1);
}
static void to_active_sleep(struct clk_rpm *r, unsigned long rate,
unsigned long *active, unsigned long *sleep)
{
*active = rate;
if (r->active_only)
*sleep = 0;
else
*sleep = *active;
}
static int clk_rpm_prepare(struct clk_hw *hw)
{
struct clk_rpm *r = to_clk_rpm(hw);
struct clk_rpm *peer = r->peer;
unsigned long this_rate = 0, this_sleep_rate = 0;
unsigned long peer_rate = 0, peer_sleep_rate = 0;
unsigned long active_rate, sleep_rate;
int ret = 0;
mutex_lock(&rpm_clk_lock);
if (!r->rate)
goto out;
to_active_sleep(r, r->rate, &this_rate, &this_sleep_rate);
if (peer->enabled)
to_active_sleep(peer, peer->rate,
&peer_rate, &peer_sleep_rate);
active_rate = max(this_rate, peer_rate);
if (r->branch)
active_rate = !!active_rate;
ret = clk_rpm_set_rate_active(r, active_rate);
if (ret)
goto out;
sleep_rate = max(this_sleep_rate, peer_sleep_rate);
if (r->branch)
sleep_rate = !!sleep_rate;
ret = clk_rpm_set_rate_sleep(r, sleep_rate);
if (ret)
ret = clk_rpm_set_rate_active(r, peer_rate);
out:
if (!ret)
r->enabled = true;
mutex_unlock(&rpm_clk_lock);
return ret;
}
static void clk_rpm_unprepare(struct clk_hw *hw)
{
struct clk_rpm *r = to_clk_rpm(hw);
struct clk_rpm *peer = r->peer;
unsigned long peer_rate = 0, peer_sleep_rate = 0;
unsigned long active_rate, sleep_rate;
int ret;
mutex_lock(&rpm_clk_lock);
if (!r->rate)
goto out;
if (peer->enabled)
to_active_sleep(peer, peer->rate, &peer_rate,
&peer_sleep_rate);
active_rate = r->branch ? !!peer_rate : peer_rate;
ret = clk_rpm_set_rate_active(r, active_rate);
if (ret)
goto out;
sleep_rate = r->branch ? !!peer_sleep_rate : peer_sleep_rate;
ret = clk_rpm_set_rate_sleep(r, sleep_rate);
if (ret)
goto out;
r->enabled = false;
out:
mutex_unlock(&rpm_clk_lock);
}
static int clk_rpm_set_rate(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate)
{
struct clk_rpm *r = to_clk_rpm(hw);
struct clk_rpm *peer = r->peer;
unsigned long active_rate, sleep_rate;
unsigned long this_rate = 0, this_sleep_rate = 0;
unsigned long peer_rate = 0, peer_sleep_rate = 0;
int ret = 0;
mutex_lock(&rpm_clk_lock);
if (!r->enabled)
goto out;
to_active_sleep(r, rate, &this_rate, &this_sleep_rate);
if (peer->enabled)
to_active_sleep(peer, peer->rate,
&peer_rate, &peer_sleep_rate);
active_rate = max(this_rate, peer_rate);
ret = clk_rpm_set_rate_active(r, active_rate);
if (ret)
goto out;
sleep_rate = max(this_sleep_rate, peer_sleep_rate);
ret = clk_rpm_set_rate_sleep(r, sleep_rate);
if (ret)
goto out;
r->rate = rate;
out:
mutex_unlock(&rpm_clk_lock);
return ret;
}
static long clk_rpm_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
return rate;
}
static unsigned long clk_rpm_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_rpm *r = to_clk_rpm(hw);
return r->rate;
}
static struct clk_hw *qcom_rpm_clk_hw_get(struct of_phandle_args *clkspec,
void *data)
{
struct rpm_cc *rcc = data;
unsigned int idx = clkspec->args[0];
if (idx >= rcc->num_clks) {
pr_err("%s: invalid index %u\n", __func__, idx);
return ERR_PTR(-EINVAL);
}
return rcc->clks[idx] ? &rcc->clks[idx]->hw : ERR_PTR(-ENOENT);
}
static int rpm_clk_probe(struct platform_device *pdev)
{
struct rpm_cc *rcc;
int ret;
size_t num_clks, i;
struct qcom_rpm *rpm;
struct clk_rpm **rpm_clks;
const struct rpm_clk_desc *desc;
rpm = dev_get_drvdata(pdev->dev.parent);
if (!rpm) {
dev_err(&pdev->dev, "Unable to retrieve handle to RPM\n");
return -ENODEV;
}
desc = of_device_get_match_data(&pdev->dev);
if (!desc)
return -EINVAL;
rpm_clks = desc->clks;
num_clks = desc->num_clks;
rcc = devm_kzalloc(&pdev->dev, sizeof(*rcc), GFP_KERNEL);
if (!rcc)
return -ENOMEM;
rcc->clks = rpm_clks;
rcc->num_clks = num_clks;
for (i = 0; i < num_clks; i++) {
if (!rpm_clks[i])
continue;
rpm_clks[i]->rpm = rpm;
ret = clk_rpm_handoff(rpm_clks[i]);
if (ret)
goto err;
}
for (i = 0; i < num_clks; i++) {
if (!rpm_clks[i])
continue;
ret = devm_clk_hw_register(&pdev->dev, &rpm_clks[i]->hw);
if (ret)
goto err;
}
ret = of_clk_add_hw_provider(pdev->dev.of_node, qcom_rpm_clk_hw_get,
rcc);
if (ret)
goto err;
return 0;
err:
dev_err(&pdev->dev, "Error registering RPM Clock driver (%d)\n", ret);
return ret;
}
static int rpm_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
static int __init rpm_clk_init(void)
{
return platform_driver_register(&rpm_clk_driver);
}
static void __exit rpm_clk_exit(void)
{
platform_driver_unregister(&rpm_clk_driver);
}
