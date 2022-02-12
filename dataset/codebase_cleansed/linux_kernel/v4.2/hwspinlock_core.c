int __hwspin_trylock(struct hwspinlock *hwlock, int mode, unsigned long *flags)
{
int ret;
BUG_ON(!hwlock);
BUG_ON(!flags && mode == HWLOCK_IRQSTATE);
if (mode == HWLOCK_IRQSTATE)
ret = spin_trylock_irqsave(&hwlock->lock, *flags);
else if (mode == HWLOCK_IRQ)
ret = spin_trylock_irq(&hwlock->lock);
else
ret = spin_trylock(&hwlock->lock);
if (!ret)
return -EBUSY;
ret = hwlock->bank->ops->trylock(hwlock);
if (!ret) {
if (mode == HWLOCK_IRQSTATE)
spin_unlock_irqrestore(&hwlock->lock, *flags);
else if (mode == HWLOCK_IRQ)
spin_unlock_irq(&hwlock->lock);
else
spin_unlock(&hwlock->lock);
return -EBUSY;
}
mb();
return 0;
}
int __hwspin_lock_timeout(struct hwspinlock *hwlock, unsigned int to,
int mode, unsigned long *flags)
{
int ret;
unsigned long expire;
expire = msecs_to_jiffies(to) + jiffies;
for (;;) {
ret = __hwspin_trylock(hwlock, mode, flags);
if (ret != -EBUSY)
break;
if (time_is_before_eq_jiffies(expire))
return -ETIMEDOUT;
if (hwlock->bank->ops->relax)
hwlock->bank->ops->relax(hwlock);
}
return ret;
}
void __hwspin_unlock(struct hwspinlock *hwlock, int mode, unsigned long *flags)
{
BUG_ON(!hwlock);
BUG_ON(!flags && mode == HWLOCK_IRQSTATE);
mb();
hwlock->bank->ops->unlock(hwlock);
if (mode == HWLOCK_IRQSTATE)
spin_unlock_irqrestore(&hwlock->lock, *flags);
else if (mode == HWLOCK_IRQ)
spin_unlock_irq(&hwlock->lock);
else
spin_unlock(&hwlock->lock);
}
static inline int
of_hwspin_lock_simple_xlate(const struct of_phandle_args *hwlock_spec)
{
if (WARN_ON(hwlock_spec->args_count != 1))
return -EINVAL;
return hwlock_spec->args[0];
}
int of_hwspin_lock_get_id(struct device_node *np, int index)
{
struct of_phandle_args args;
struct hwspinlock *hwlock;
struct radix_tree_iter iter;
void **slot;
int id;
int ret;
ret = of_parse_phandle_with_args(np, "hwlocks", "#hwlock-cells", index,
&args);
if (ret)
return ret;
ret = -EPROBE_DEFER;
rcu_read_lock();
radix_tree_for_each_slot(slot, &hwspinlock_tree, &iter, 0) {
hwlock = radix_tree_deref_slot(slot);
if (unlikely(!hwlock))
continue;
if (hwlock->bank->dev->of_node == args.np) {
ret = 0;
break;
}
}
rcu_read_unlock();
if (ret < 0)
goto out;
id = of_hwspin_lock_simple_xlate(&args);
if (id < 0 || id >= hwlock->bank->num_locks) {
ret = -EINVAL;
goto out;
}
id += hwlock->bank->base_id;
out:
of_node_put(args.np);
return ret ? ret : id;
}
static int hwspin_lock_register_single(struct hwspinlock *hwlock, int id)
{
struct hwspinlock *tmp;
int ret;
mutex_lock(&hwspinlock_tree_lock);
ret = radix_tree_insert(&hwspinlock_tree, id, hwlock);
if (ret) {
if (ret == -EEXIST)
pr_err("hwspinlock id %d already exists!\n", id);
goto out;
}
tmp = radix_tree_tag_set(&hwspinlock_tree, id, HWSPINLOCK_UNUSED);
WARN_ON(tmp != hwlock);
out:
mutex_unlock(&hwspinlock_tree_lock);
return 0;
}
static struct hwspinlock *hwspin_lock_unregister_single(unsigned int id)
{
struct hwspinlock *hwlock = NULL;
int ret;
mutex_lock(&hwspinlock_tree_lock);
ret = radix_tree_tag_get(&hwspinlock_tree, id, HWSPINLOCK_UNUSED);
if (ret == 0) {
pr_err("hwspinlock %d still in use (or not present)\n", id);
goto out;
}
hwlock = radix_tree_delete(&hwspinlock_tree, id);
if (!hwlock) {
pr_err("failed to delete hwspinlock %d\n", id);
goto out;
}
out:
mutex_unlock(&hwspinlock_tree_lock);
return hwlock;
}
int hwspin_lock_register(struct hwspinlock_device *bank, struct device *dev,
const struct hwspinlock_ops *ops, int base_id, int num_locks)
{
struct hwspinlock *hwlock;
int ret = 0, i;
if (!bank || !ops || !dev || !num_locks || !ops->trylock ||
!ops->unlock) {
pr_err("invalid parameters\n");
return -EINVAL;
}
bank->dev = dev;
bank->ops = ops;
bank->base_id = base_id;
bank->num_locks = num_locks;
for (i = 0; i < num_locks; i++) {
hwlock = &bank->lock[i];
spin_lock_init(&hwlock->lock);
hwlock->bank = bank;
ret = hwspin_lock_register_single(hwlock, base_id + i);
if (ret)
goto reg_failed;
}
return 0;
reg_failed:
while (--i >= 0)
hwspin_lock_unregister_single(base_id + i);
return ret;
}
int hwspin_lock_unregister(struct hwspinlock_device *bank)
{
struct hwspinlock *hwlock, *tmp;
int i;
for (i = 0; i < bank->num_locks; i++) {
hwlock = &bank->lock[i];
tmp = hwspin_lock_unregister_single(bank->base_id + i);
if (!tmp)
return -EBUSY;
WARN_ON(tmp != hwlock);
}
return 0;
}
static int __hwspin_lock_request(struct hwspinlock *hwlock)
{
struct device *dev = hwlock->bank->dev;
struct hwspinlock *tmp;
int ret;
if (!try_module_get(dev->driver->owner)) {
dev_err(dev, "%s: can't get owner\n", __func__);
return -EINVAL;
}
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "%s: can't power on device\n", __func__);
pm_runtime_put_noidle(dev);
module_put(dev->driver->owner);
return ret;
}
tmp = radix_tree_tag_clear(&hwspinlock_tree, hwlock_to_id(hwlock),
HWSPINLOCK_UNUSED);
WARN_ON(tmp != hwlock);
return ret;
}
int hwspin_lock_get_id(struct hwspinlock *hwlock)
{
if (!hwlock) {
pr_err("invalid hwlock\n");
return -EINVAL;
}
return hwlock_to_id(hwlock);
}
struct hwspinlock *hwspin_lock_request(void)
{
struct hwspinlock *hwlock;
int ret;
mutex_lock(&hwspinlock_tree_lock);
ret = radix_tree_gang_lookup_tag(&hwspinlock_tree, (void **)&hwlock,
0, 1, HWSPINLOCK_UNUSED);
if (ret == 0) {
pr_warn("a free hwspinlock is not available\n");
hwlock = NULL;
goto out;
}
WARN_ON(ret > 1);
ret = __hwspin_lock_request(hwlock);
if (ret < 0)
hwlock = NULL;
out:
mutex_unlock(&hwspinlock_tree_lock);
return hwlock;
}
struct hwspinlock *hwspin_lock_request_specific(unsigned int id)
{
struct hwspinlock *hwlock;
int ret;
mutex_lock(&hwspinlock_tree_lock);
hwlock = radix_tree_lookup(&hwspinlock_tree, id);
if (!hwlock) {
pr_warn("hwspinlock %u does not exist\n", id);
goto out;
}
WARN_ON(hwlock_to_id(hwlock) != id);
ret = radix_tree_tag_get(&hwspinlock_tree, id, HWSPINLOCK_UNUSED);
if (ret == 0) {
pr_warn("hwspinlock %u is already in use\n", id);
hwlock = NULL;
goto out;
}
ret = __hwspin_lock_request(hwlock);
if (ret < 0)
hwlock = NULL;
out:
mutex_unlock(&hwspinlock_tree_lock);
return hwlock;
}
int hwspin_lock_free(struct hwspinlock *hwlock)
{
struct device *dev;
struct hwspinlock *tmp;
int ret;
if (!hwlock) {
pr_err("invalid hwlock\n");
return -EINVAL;
}
dev = hwlock->bank->dev;
mutex_lock(&hwspinlock_tree_lock);
ret = radix_tree_tag_get(&hwspinlock_tree, hwlock_to_id(hwlock),
HWSPINLOCK_UNUSED);
if (ret == 1) {
dev_err(dev, "%s: hwlock is already free\n", __func__);
dump_stack();
ret = -EINVAL;
goto out;
}
ret = pm_runtime_put(dev);
if (ret < 0)
goto out;
tmp = radix_tree_tag_set(&hwspinlock_tree, hwlock_to_id(hwlock),
HWSPINLOCK_UNUSED);
WARN_ON(tmp != hwlock);
module_put(dev->driver->owner);
out:
mutex_unlock(&hwspinlock_tree_lock);
return ret;
}
