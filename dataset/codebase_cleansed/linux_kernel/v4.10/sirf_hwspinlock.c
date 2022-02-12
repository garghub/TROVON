static int sirf_hwspinlock_trylock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
return !!readl(lock_addr);
}
static void sirf_hwspinlock_unlock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
writel(0, lock_addr);
}
static int sirf_hwspinlock_probe(struct platform_device *pdev)
{
struct sirf_hwspinlock *hwspin;
struct hwspinlock *hwlock;
int idx, ret;
if (!pdev->dev.of_node)
return -ENODEV;
hwspin = devm_kzalloc(&pdev->dev, sizeof(*hwspin) +
sizeof(*hwlock) * HW_SPINLOCK_NUMBER, GFP_KERNEL);
if (!hwspin)
return -ENOMEM;
hwspin->io_base = of_iomap(pdev->dev.of_node, 0);
if (!hwspin->io_base)
return -ENOMEM;
for (idx = 0; idx < HW_SPINLOCK_NUMBER; idx++) {
hwlock = &hwspin->bank.lock[idx];
hwlock->priv = hwspin->io_base + HW_SPINLOCK_OFFSET(idx);
}
platform_set_drvdata(pdev, hwspin);
pm_runtime_enable(&pdev->dev);
ret = hwspin_lock_register(&hwspin->bank, &pdev->dev,
&sirf_hwspinlock_ops, 0,
HW_SPINLOCK_NUMBER);
if (ret)
goto reg_failed;
return 0;
reg_failed:
pm_runtime_disable(&pdev->dev);
iounmap(hwspin->io_base);
return ret;
}
static int sirf_hwspinlock_remove(struct platform_device *pdev)
{
struct sirf_hwspinlock *hwspin = platform_get_drvdata(pdev);
int ret;
ret = hwspin_lock_unregister(&hwspin->bank);
if (ret) {
dev_err(&pdev->dev, "%s failed: %d\n", __func__, ret);
return ret;
}
pm_runtime_disable(&pdev->dev);
iounmap(hwspin->io_base);
return 0;
}
