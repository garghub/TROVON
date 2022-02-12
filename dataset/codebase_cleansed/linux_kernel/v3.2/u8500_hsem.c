static int u8500_hsem_trylock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
writel(HSEM_MASTER_ID, lock_addr);
return (HSEM_MASTER_ID == (0x0F & readl(lock_addr)));
}
static void u8500_hsem_unlock(struct hwspinlock *lock)
{
void __iomem *lock_addr = lock->priv;
writel(RESET_SEMAPHORE, lock_addr);
}
static void u8500_hsem_relax(struct hwspinlock *lock)
{
ndelay(50);
}
static int __devinit u8500_hsem_probe(struct platform_device *pdev)
{
struct hwspinlock_pdata *pdata = pdev->dev.platform_data;
struct hwspinlock_device *bank;
struct hwspinlock *hwlock;
struct resource *res;
void __iomem *io_base;
int i, ret, num_locks = U8500_MAX_SEMAPHORE;
ulong val;
if (!pdata)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
io_base = ioremap(res->start, resource_size(res));
if (!io_base)
return -ENOMEM;
val = readl(io_base + HSEM_CTRL_REG);
writel((val & ~HSEM_PROTOCOL_1), io_base + HSEM_CTRL_REG);
writel(0xFFFF, io_base + HSEM_ICRALL);
bank = kzalloc(sizeof(*bank) + num_locks * sizeof(*hwlock), GFP_KERNEL);
if (!bank) {
ret = -ENOMEM;
goto iounmap_base;
}
platform_set_drvdata(pdev, bank);
for (i = 0, hwlock = &bank->lock[0]; i < num_locks; i++, hwlock++)
hwlock->priv = io_base + HSEM_REGISTER_OFFSET + sizeof(u32) * i;
pm_runtime_enable(&pdev->dev);
ret = hwspin_lock_register(bank, &pdev->dev, &u8500_hwspinlock_ops,
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
static int __devexit u8500_hsem_remove(struct platform_device *pdev)
{
struct hwspinlock_device *bank = platform_get_drvdata(pdev);
void __iomem *io_base = bank->lock[0].priv - HSEM_REGISTER_OFFSET;
int ret;
writel(0xFFFF, io_base + HSEM_ICRALL);
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
static int __init u8500_hsem_init(void)
{
return platform_driver_register(&u8500_hsem_driver);
}
static void __exit u8500_hsem_exit(void)
{
platform_driver_unregister(&u8500_hsem_driver);
}
