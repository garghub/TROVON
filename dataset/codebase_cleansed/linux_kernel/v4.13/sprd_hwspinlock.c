static int sprd_hwspinlock_trylock(struct hwspinlock *lock)
{
struct sprd_hwspinlock_dev *sprd_hwlock =
dev_get_drvdata(lock->bank->dev);
void __iomem *addr = lock->priv;
int user_id, lock_id;
if (!readl(addr))
return 1;
lock_id = hwlock_to_id(lock);
user_id = readl(sprd_hwlock->base + HWSPINLOCK_MASTERID(lock_id));
dev_warn(sprd_hwlock->bank.dev,
"hwspinlock [%d] lock failed and master/user id = %d!\n",
lock_id, user_id);
return 0;
}
static void sprd_hwspinlock_unlock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
writel(HWSPINLOCK_NOTTAKEN, lock_addr);
}
static void sprd_hwspinlock_relax(struct hwspinlock *lock)
{
ndelay(10);
}
static int sprd_hwspinlock_probe(struct platform_device *pdev)
{
struct sprd_hwspinlock_dev *sprd_hwlock;
struct hwspinlock *lock;
struct resource *res;
int i, ret;
if (!pdev->dev.of_node)
return -ENODEV;
sprd_hwlock = devm_kzalloc(&pdev->dev,
sizeof(struct sprd_hwspinlock_dev) +
SPRD_HWLOCKS_NUM * sizeof(*lock),
GFP_KERNEL);
if (!sprd_hwlock)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sprd_hwlock->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sprd_hwlock->base))
return PTR_ERR(sprd_hwlock->base);
sprd_hwlock->clk = devm_clk_get(&pdev->dev, "enable");
if (IS_ERR(sprd_hwlock->clk)) {
dev_err(&pdev->dev, "get hwspinlock clock failed!\n");
return PTR_ERR(sprd_hwlock->clk);
}
clk_prepare_enable(sprd_hwlock->clk);
writel(HWSPINLOCK_USER_BITS, sprd_hwlock->base + HWSPINLOCK_RECCTRL);
for (i = 0; i < SPRD_HWLOCKS_NUM; i++) {
lock = &sprd_hwlock->bank.lock[i];
lock->priv = sprd_hwlock->base + HWSPINLOCK_TOKEN(i);
}
platform_set_drvdata(pdev, sprd_hwlock);
pm_runtime_enable(&pdev->dev);
ret = hwspin_lock_register(&sprd_hwlock->bank, &pdev->dev,
&sprd_hwspinlock_ops, 0, SPRD_HWLOCKS_NUM);
if (ret) {
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(sprd_hwlock->clk);
return ret;
}
return 0;
}
static int sprd_hwspinlock_remove(struct platform_device *pdev)
{
struct sprd_hwspinlock_dev *sprd_hwlock = platform_get_drvdata(pdev);
hwspin_lock_unregister(&sprd_hwlock->bank);
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(sprd_hwlock->clk);
return 0;
}
static int __init sprd_hwspinlock_init(void)
{
return platform_driver_register(&sprd_hwspinlock_driver);
}
static void __exit sprd_hwspinlock_exit(void)
{
platform_driver_unregister(&sprd_hwspinlock_driver);
}
