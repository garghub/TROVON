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
ret = hwlock->ops->trylock(hwlock);
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
if (hwlock->ops->relax)
hwlock->ops->relax(hwlock);
}
return ret;
}
void __hwspin_unlock(struct hwspinlock *hwlock, int mode, unsigned long *flags)
{
BUG_ON(!hwlock);
BUG_ON(!flags && mode == HWLOCK_IRQSTATE);
mb();
hwlock->ops->unlock(hwlock);
if (mode == HWLOCK_IRQSTATE)
spin_unlock_irqrestore(&hwlock->lock, *flags);
else if (mode == HWLOCK_IRQ)
spin_unlock_irq(&hwlock->lock);
else
spin_unlock(&hwlock->lock);
}
int hwspin_lock_register(struct hwspinlock *hwlock)
{
struct hwspinlock *tmp;
int ret;
if (!hwlock || !hwlock->ops ||
!hwlock->ops->trylock || !hwlock->ops->unlock) {
pr_err("invalid parameters\n");
return -EINVAL;
}
spin_lock_init(&hwlock->lock);
spin_lock(&hwspinlock_tree_lock);
ret = radix_tree_insert(&hwspinlock_tree, hwlock->id, hwlock);
if (ret)
goto out;
tmp = radix_tree_tag_set(&hwspinlock_tree, hwlock->id,
HWSPINLOCK_UNUSED);
WARN_ON(tmp != hwlock);
out:
spin_unlock(&hwspinlock_tree_lock);
return ret;
}
struct hwspinlock *hwspin_lock_unregister(unsigned int id)
{
struct hwspinlock *hwlock = NULL;
int ret;
spin_lock(&hwspinlock_tree_lock);
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
spin_unlock(&hwspinlock_tree_lock);
return hwlock;
}
static int __hwspin_lock_request(struct hwspinlock *hwlock)
{
struct hwspinlock *tmp;
int ret;
if (!try_module_get(hwlock->owner)) {
dev_err(hwlock->dev, "%s: can't get owner\n", __func__);
return -EINVAL;
}
ret = pm_runtime_get_sync(hwlock->dev);
if (ret < 0) {
dev_err(hwlock->dev, "%s: can't power on device\n", __func__);
return ret;
}
tmp = radix_tree_tag_clear(&hwspinlock_tree, hwlock->id,
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
return hwlock->id;
}
struct hwspinlock *hwspin_lock_request(void)
{
struct hwspinlock *hwlock;
int ret;
spin_lock(&hwspinlock_tree_lock);
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
spin_unlock(&hwspinlock_tree_lock);
return hwlock;
}
struct hwspinlock *hwspin_lock_request_specific(unsigned int id)
{
struct hwspinlock *hwlock;
int ret;
spin_lock(&hwspinlock_tree_lock);
hwlock = radix_tree_lookup(&hwspinlock_tree, id);
if (!hwlock) {
pr_warn("hwspinlock %u does not exist\n", id);
goto out;
}
WARN_ON(hwlock->id != id);
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
spin_unlock(&hwspinlock_tree_lock);
return hwlock;
}
int hwspin_lock_free(struct hwspinlock *hwlock)
{
struct hwspinlock *tmp;
int ret;
if (!hwlock) {
pr_err("invalid hwlock\n");
return -EINVAL;
}
spin_lock(&hwspinlock_tree_lock);
ret = radix_tree_tag_get(&hwspinlock_tree, hwlock->id,
HWSPINLOCK_UNUSED);
if (ret == 1) {
dev_err(hwlock->dev, "%s: hwlock is already free\n", __func__);
dump_stack();
ret = -EINVAL;
goto out;
}
ret = pm_runtime_put(hwlock->dev);
if (ret < 0)
goto out;
tmp = radix_tree_tag_set(&hwspinlock_tree, hwlock->id,
HWSPINLOCK_UNUSED);
WARN_ON(tmp != hwlock);
module_put(hwlock->owner);
out:
spin_unlock(&hwspinlock_tree_lock);
return ret;
}
