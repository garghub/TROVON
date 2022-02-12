static int qcom_hwspinlock_trylock(struct hwspinlock *lock)
{
struct regmap_field *field = lock->priv;
u32 lock_owner;
int ret;
ret = regmap_field_write(field, QCOM_MUTEX_APPS_PROC_ID);
if (ret)
return ret;
ret = regmap_field_read(field, &lock_owner);
if (ret)
return ret;
return lock_owner == QCOM_MUTEX_APPS_PROC_ID;
}
static void qcom_hwspinlock_unlock(struct hwspinlock *lock)
{
struct regmap_field *field = lock->priv;
u32 lock_owner;
int ret;
ret = regmap_field_read(field, &lock_owner);
if (ret) {
pr_err("%s: unable to query spinlock owner\n", __func__);
return;
}
if (lock_owner != QCOM_MUTEX_APPS_PROC_ID) {
pr_err("%s: spinlock not owned by us (actual owner is %d)\n",
__func__, lock_owner);
}
ret = regmap_field_write(field, 0);
if (ret)
pr_err("%s: failed to unlock spinlock\n", __func__);
}
static int qcom_hwspinlock_probe(struct platform_device *pdev)
{
struct hwspinlock_device *bank;
struct device_node *syscon;
struct reg_field field;
struct regmap *regmap;
size_t array_size;
u32 stride;
u32 base;
int ret;
int i;
syscon = of_parse_phandle(pdev->dev.of_node, "syscon", 0);
if (!syscon) {
dev_err(&pdev->dev, "no syscon property\n");
return -ENODEV;
}
regmap = syscon_node_to_regmap(syscon);
of_node_put(syscon);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ret = of_property_read_u32_index(pdev->dev.of_node, "syscon", 1, &base);
if (ret < 0) {
dev_err(&pdev->dev, "no offset in syscon\n");
return -EINVAL;
}
ret = of_property_read_u32_index(pdev->dev.of_node, "syscon", 2, &stride);
if (ret < 0) {
dev_err(&pdev->dev, "no stride syscon\n");
return -EINVAL;
}
array_size = QCOM_MUTEX_NUM_LOCKS * sizeof(struct hwspinlock);
bank = devm_kzalloc(&pdev->dev, sizeof(*bank) + array_size, GFP_KERNEL);
if (!bank)
return -ENOMEM;
platform_set_drvdata(pdev, bank);
for (i = 0; i < QCOM_MUTEX_NUM_LOCKS; i++) {
field.reg = base + i * stride;
field.lsb = 0;
field.msb = 31;
bank->lock[i].priv = devm_regmap_field_alloc(&pdev->dev,
regmap, field);
}
pm_runtime_enable(&pdev->dev);
ret = hwspin_lock_register(bank, &pdev->dev, &qcom_hwspinlock_ops,
0, QCOM_MUTEX_NUM_LOCKS);
if (ret)
pm_runtime_disable(&pdev->dev);
return ret;
}
static int qcom_hwspinlock_remove(struct platform_device *pdev)
{
struct hwspinlock_device *bank = platform_get_drvdata(pdev);
int ret;
ret = hwspin_lock_unregister(bank);
if (ret) {
dev_err(&pdev->dev, "%s failed: %d\n", __func__, ret);
return ret;
}
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __init qcom_hwspinlock_init(void)
{
return platform_driver_register(&qcom_hwspinlock_driver);
}
static void __exit qcom_hwspinlock_exit(void)
{
platform_driver_unregister(&qcom_hwspinlock_driver);
}
