static int omap_hwspinlock_trylock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
return (SPINLOCK_NOTTAKEN == readl(lock_addr));
}
static void omap_hwspinlock_unlock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
writel(SPINLOCK_NOTTAKEN, lock_addr);
}
static void omap_hwspinlock_relax(struct hwspinlock *lock)
{
ndelay(50);
}
static int __devinit omap_hwspinlock_probe(struct platform_device *pdev)
{
struct hwspinlock_pdata *pdata = pdev->dev.platform_data;
struct hwspinlock_device *bank;
struct hwspinlock *hwlock;
struct resource *res;
void __iomem *io_base;
int num_locks, i, ret;
if (!pdata)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
io_base = ioremap(res->start, resource_size(res));
if (!io_base)
return -ENOMEM;
i = readl(io_base + SYSSTATUS_OFFSET);
i >>= SPINLOCK_NUMLOCKS_BIT_OFFSET;
if (hweight_long(i & 0xf) != 1 || i > 8) {
ret = -EINVAL;
goto iounmap_base;
}
num_locks = i * 32;
bank = kzalloc(sizeof(*bank) + num_locks * sizeof(*hwlock), GFP_KERNEL);
if (!bank) {
ret = -ENOMEM;
goto iounmap_base;
}
platform_set_drvdata(pdev, bank);
for (i = 0, hwlock = &bank->lock[0]; i < num_locks; i++, hwlock++)
hwlock->priv = io_base + LOCK_BASE_OFFSET + sizeof(u32) * i;
pm_runtime_enable(&pdev->dev);
ret = hwspin_lock_register(bank, &pdev->dev, &omap_hwspinlock_ops,
pdata->base_id, num_locks);
if (ret)
goto reg_fail;
return 0;
reg_fail:
pm_runtime_disable(&pdev->dev);
kfree(bank);
iounmap_base:
iounmap(io_base);
return ret;
}
static int __devexit omap_hwspinlock_remove(struct platform_device *pdev)
{
struct hwspinlock_device *bank = platform_get_drvdata(pdev);
void __iomem *io_base = bank->lock[0].priv - LOCK_BASE_OFFSET;
int ret;
ret = hwspin_lock_unregister(bank);
if (ret) {
dev_err(&pdev->dev, "%s failed: %d\n", __func__, ret);
return ret;
}
pm_runtime_disable(&pdev->dev);
iounmap(io_base);
kfree(bank);
return 0;
}
static int __init omap_hwspinlock_init(void)
{
return platform_driver_register(&omap_hwspinlock_driver);
}
static void __exit omap_hwspinlock_exit(void)
{
platform_driver_unregister(&omap_hwspinlock_driver);
}
