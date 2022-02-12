static int exynos5_int_setvolt(struct busfreq_data_int *data,
unsigned long volt)
{
return regulator_set_voltage(data->vdd_int, volt, MAX_SAFEVOLT);
}
static int exynos5_busfreq_int_target(struct device *dev, unsigned long *_freq,
u32 flags)
{
int err = 0;
struct platform_device *pdev = container_of(dev, struct platform_device,
dev);
struct busfreq_data_int *data = platform_get_drvdata(pdev);
struct dev_pm_opp *opp;
unsigned long old_freq, freq;
unsigned long volt;
rcu_read_lock();
opp = devfreq_recommended_opp(dev, _freq, flags);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(dev, "%s: Invalid OPP.\n", __func__);
return PTR_ERR(opp);
}
freq = dev_pm_opp_get_freq(opp);
volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
old_freq = data->curr_freq;
if (old_freq == freq)
return 0;
dev_dbg(dev, "targeting %lukHz %luuV\n", freq, volt);
mutex_lock(&data->lock);
if (data->disabled)
goto out;
if (freq > exynos5_int_opp_table[0].clk)
pm_qos_update_request(&data->int_req, freq * 16 / 1000);
else
pm_qos_update_request(&data->int_req, -1);
if (old_freq < freq)
err = exynos5_int_setvolt(data, volt);
if (err)
goto out;
err = clk_set_rate(data->int_clk, freq * 1000);
if (err)
goto out;
if (old_freq > freq)
err = exynos5_int_setvolt(data, volt);
if (err)
goto out;
data->curr_freq = freq;
out:
mutex_unlock(&data->lock);
return err;
}
static int exynos5_int_get_dev_status(struct device *dev,
struct devfreq_dev_status *stat)
{
struct platform_device *pdev = container_of(dev, struct platform_device,
dev);
struct busfreq_data_int *data = platform_get_drvdata(pdev);
struct busfreq_ppmu_data *ppmu_data = &data->ppmu_data;
int busier_dmc;
exynos_read_ppmu(ppmu_data);
busier_dmc = exynos_get_busier_ppmu(ppmu_data);
stat->current_frequency = data->curr_freq;
stat->busy_time = ppmu_data->ppmu[busier_dmc].count[PPMU_PMNCNT3];
stat->busy_time *= 100 / INT_BUS_SATURATION_RATIO;
stat->total_time = ppmu_data->ppmu[busier_dmc].ccnt;
return 0;
}
static int exynos5250_init_int_tables(struct busfreq_data_int *data)
{
int i, err = 0;
for (i = LV_0; i < _LV_END; i++) {
err = dev_pm_opp_add(data->dev, exynos5_int_opp_table[i].clk,
exynos5_int_opp_table[i].volt);
if (err) {
dev_err(data->dev, "Cannot add opp entries.\n");
return err;
}
}
return 0;
}
static int exynos5_busfreq_int_pm_notifier_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct busfreq_data_int *data = container_of(this,
struct busfreq_data_int, pm_notifier);
struct dev_pm_opp *opp;
unsigned long maxfreq = ULONG_MAX;
unsigned long freq;
unsigned long volt;
int err = 0;
switch (event) {
case PM_SUSPEND_PREPARE:
mutex_lock(&data->lock);
data->disabled = true;
rcu_read_lock();
opp = dev_pm_opp_find_freq_floor(data->dev, &maxfreq);
if (IS_ERR(opp)) {
rcu_read_unlock();
err = PTR_ERR(opp);
goto unlock;
}
freq = dev_pm_opp_get_freq(opp);
volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
err = exynos5_int_setvolt(data, volt);
if (err)
goto unlock;
err = clk_set_rate(data->int_clk, freq * 1000);
if (err)
goto unlock;
data->curr_freq = freq;
unlock:
mutex_unlock(&data->lock);
if (err)
return NOTIFY_BAD;
return NOTIFY_OK;
case PM_POST_RESTORE:
case PM_POST_SUSPEND:
mutex_lock(&data->lock);
data->disabled = false;
mutex_unlock(&data->lock);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static int exynos5_busfreq_int_probe(struct platform_device *pdev)
{
struct busfreq_data_int *data;
struct busfreq_ppmu_data *ppmu_data;
struct dev_pm_opp *opp;
struct device *dev = &pdev->dev;
struct device_node *np;
unsigned long initial_freq;
unsigned long initial_volt;
int err = 0;
int i;
data = devm_kzalloc(&pdev->dev, sizeof(struct busfreq_data_int),
GFP_KERNEL);
if (data == NULL) {
dev_err(dev, "Cannot allocate memory.\n");
return -ENOMEM;
}
ppmu_data = &data->ppmu_data;
ppmu_data->ppmu_end = PPMU_END;
ppmu_data->ppmu = devm_kzalloc(dev,
sizeof(struct exynos_ppmu) * PPMU_END,
GFP_KERNEL);
if (!ppmu_data->ppmu) {
dev_err(dev, "Failed to allocate memory for exynos_ppmu\n");
return -ENOMEM;
}
np = of_find_compatible_node(NULL, NULL, "samsung,exynos5250-ppmu");
if (np == NULL) {
pr_err("Unable to find PPMU node\n");
return -ENOENT;
}
for (i = 0; i < ppmu_data->ppmu_end; i++) {
ppmu_data->ppmu[i].hw_base = of_iomap(np, i);
if (ppmu_data->ppmu[i].hw_base == NULL) {
dev_err(&pdev->dev, "failed to map memory region\n");
return -ENOMEM;
}
}
data->pm_notifier.notifier_call = exynos5_busfreq_int_pm_notifier_event;
data->dev = dev;
mutex_init(&data->lock);
err = exynos5250_init_int_tables(data);
if (err)
return err;
data->vdd_int = devm_regulator_get(dev, "vdd_int");
if (IS_ERR(data->vdd_int)) {
dev_err(dev, "Cannot get the regulator \"vdd_int\"\n");
return PTR_ERR(data->vdd_int);
}
data->int_clk = devm_clk_get(dev, "int_clk");
if (IS_ERR(data->int_clk)) {
dev_err(dev, "Cannot get clock \"int_clk\"\n");
return PTR_ERR(data->int_clk);
}
rcu_read_lock();
opp = dev_pm_opp_find_freq_floor(dev,
&exynos5_devfreq_int_profile.initial_freq);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(dev, "Invalid initial frequency %lu kHz.\n",
exynos5_devfreq_int_profile.initial_freq);
return PTR_ERR(opp);
}
initial_freq = dev_pm_opp_get_freq(opp);
initial_volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
data->curr_freq = initial_freq;
err = clk_set_rate(data->int_clk, initial_freq * 1000);
if (err) {
dev_err(dev, "Failed to set initial frequency\n");
return err;
}
err = exynos5_int_setvolt(data, initial_volt);
if (err)
return err;
platform_set_drvdata(pdev, data);
busfreq_mon_reset(ppmu_data);
data->devfreq = devm_devfreq_add_device(dev, &exynos5_devfreq_int_profile,
"simple_ondemand", NULL);
if (IS_ERR(data->devfreq))
return PTR_ERR(data->devfreq);
err = devm_devfreq_register_opp_notifier(dev, data->devfreq);
if (err < 0) {
dev_err(dev, "Failed to register opp notifier\n");
return err;
}
err = register_pm_notifier(&data->pm_notifier);
if (err) {
dev_err(dev, "Failed to setup pm notifier\n");
return err;
}
pm_qos_add_request(&data->int_req, PM_QOS_NETWORK_THROUGHPUT, -1);
return 0;
}
static int exynos5_busfreq_int_remove(struct platform_device *pdev)
{
struct busfreq_data_int *data = platform_get_drvdata(pdev);
pm_qos_remove_request(&data->int_req);
unregister_pm_notifier(&data->pm_notifier);
return 0;
}
static int exynos5_busfreq_int_resume(struct device *dev)
{
struct platform_device *pdev = container_of(dev, struct platform_device,
dev);
struct busfreq_data_int *data = platform_get_drvdata(pdev);
struct busfreq_ppmu_data *ppmu_data = &data->ppmu_data;
busfreq_mon_reset(ppmu_data);
return 0;
}
static int __init exynos5_busfreq_int_init(void)
{
int ret;
ret = platform_driver_register(&exynos5_busfreq_int_driver);
if (ret < 0)
goto out;
exynos5_devfreq_pdev =
platform_device_register_simple("exynos5-bus-int", -1, NULL, 0);
if (IS_ERR(exynos5_devfreq_pdev)) {
ret = PTR_ERR(exynos5_devfreq_pdev);
goto out1;
}
return 0;
out1:
platform_driver_unregister(&exynos5_busfreq_int_driver);
out:
return ret;
}
static void __exit exynos5_busfreq_int_exit(void)
{
platform_device_unregister(exynos5_devfreq_pdev);
platform_driver_unregister(&exynos5_busfreq_int_driver);
}
