static int omap_hwspinlock_trylock(struct hwspinlock *lock)
{
struct omap_hwspinlock *omap_lock = to_omap_hwspinlock(lock);
return (SPINLOCK_NOTTAKEN == readl(omap_lock->addr));
}
static void omap_hwspinlock_unlock(struct hwspinlock *lock)
{
struct omap_hwspinlock *omap_lock = to_omap_hwspinlock(lock);
writel(SPINLOCK_NOTTAKEN, omap_lock->addr);
}
static void omap_hwspinlock_relax(struct hwspinlock *lock)
{
ndelay(50);
}
static int __devinit omap_hwspinlock_probe(struct platform_device *pdev)
{
struct omap_hwspinlock *omap_lock;
struct omap_hwspinlock_state *state;
struct hwspinlock *lock;
struct resource *res;
void __iomem *io_base;
int i, ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
io_base = ioremap(res->start, resource_size(res));
if (!io_base) {
ret = -ENOMEM;
goto free_state;
}
i = readl(io_base + SYSSTATUS_OFFSET);
i >>= SPINLOCK_NUMLOCKS_BIT_OFFSET;
if (hweight_long(i & 0xf) != 1 || i > 8) {
ret = -EINVAL;
goto iounmap_base;
}
state->num_locks = i * 32;
state->io_base = io_base;
platform_set_drvdata(pdev, state);
pm_runtime_enable(&pdev->dev);
for (i = 0; i < state->num_locks; i++) {
omap_lock = kzalloc(sizeof(*omap_lock), GFP_KERNEL);
if (!omap_lock) {
ret = -ENOMEM;
goto free_locks;
}
omap_lock->lock.dev = &pdev->dev;
omap_lock->lock.owner = THIS_MODULE;
omap_lock->lock.id = i;
omap_lock->lock.ops = &omap_hwspinlock_ops;
omap_lock->addr = io_base + LOCK_BASE_OFFSET + sizeof(u32) * i;
ret = hwspin_lock_register(&omap_lock->lock);
if (ret) {
kfree(omap_lock);
goto free_locks;
}
}
return 0;
free_locks:
while (--i >= 0) {
lock = hwspin_lock_unregister(i);
if (!lock) {
dev_err(&pdev->dev, "%s: cleanups failed\n", __func__);
continue;
}
omap_lock = to_omap_hwspinlock(lock);
kfree(omap_lock);
}
pm_runtime_disable(&pdev->dev);
iounmap_base:
iounmap(io_base);
free_state:
kfree(state);
return ret;
}
static int omap_hwspinlock_remove(struct platform_device *pdev)
{
struct omap_hwspinlock_state *state = platform_get_drvdata(pdev);
struct hwspinlock *lock;
struct omap_hwspinlock *omap_lock;
int i;
for (i = 0; i < state->num_locks; i++) {
lock = hwspin_lock_unregister(i);
if (!lock) {
dev_err(&pdev->dev, "%s: failed on %d\n", __func__, i);
return -EBUSY;
}
omap_lock = to_omap_hwspinlock(lock);
kfree(omap_lock);
}
pm_runtime_disable(&pdev->dev);
iounmap(state->io_base);
kfree(state);
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
