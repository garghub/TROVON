static void fsl_free_resource(struct work_struct *ws)
{
struct fsl_mpic_timer_wakeup *wakeup =
container_of(ws, struct fsl_mpic_timer_wakeup, free_work);
mutex_lock(&sysfs_lock);
if (wakeup->timer) {
disable_irq_wake(wakeup->timer->irq);
mpic_free_timer(wakeup->timer);
}
wakeup->timer = NULL;
mutex_unlock(&sysfs_lock);
}
static irqreturn_t fsl_mpic_timer_irq(int irq, void *dev_id)
{
struct fsl_mpic_timer_wakeup *wakeup = dev_id;
schedule_work(&wakeup->free_work);
return wakeup->timer ? IRQ_HANDLED : IRQ_NONE;
}
static ssize_t fsl_timer_wakeup_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct timeval interval;
int val = 0;
mutex_lock(&sysfs_lock);
if (fsl_wakeup->timer) {
mpic_get_remain_time(fsl_wakeup->timer, &interval);
val = interval.tv_sec + 1;
}
mutex_unlock(&sysfs_lock);
return sprintf(buf, "%d\n", val);
}
static ssize_t fsl_timer_wakeup_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct timeval interval;
int ret;
interval.tv_usec = 0;
if (kstrtol(buf, 0, &interval.tv_sec))
return -EINVAL;
mutex_lock(&sysfs_lock);
if (fsl_wakeup->timer) {
disable_irq_wake(fsl_wakeup->timer->irq);
mpic_free_timer(fsl_wakeup->timer);
fsl_wakeup->timer = NULL;
}
if (!interval.tv_sec) {
mutex_unlock(&sysfs_lock);
return count;
}
fsl_wakeup->timer = mpic_request_timer(fsl_mpic_timer_irq,
fsl_wakeup, &interval);
if (!fsl_wakeup->timer) {
mutex_unlock(&sysfs_lock);
return -EINVAL;
}
ret = enable_irq_wake(fsl_wakeup->timer->irq);
if (ret) {
mpic_free_timer(fsl_wakeup->timer);
fsl_wakeup->timer = NULL;
mutex_unlock(&sysfs_lock);
return ret;
}
mpic_start_timer(fsl_wakeup->timer);
mutex_unlock(&sysfs_lock);
return count;
}
static int __init fsl_wakeup_sys_init(void)
{
int ret;
fsl_wakeup = kzalloc(sizeof(struct fsl_mpic_timer_wakeup), GFP_KERNEL);
if (!fsl_wakeup)
return -ENOMEM;
INIT_WORK(&fsl_wakeup->free_work, fsl_free_resource);
ret = device_create_file(mpic_subsys.dev_root, &mpic_attributes);
if (ret)
kfree(fsl_wakeup);
return ret;
}
static void __exit fsl_wakeup_sys_exit(void)
{
device_remove_file(mpic_subsys.dev_root, &mpic_attributes);
mutex_lock(&sysfs_lock);
if (fsl_wakeup->timer) {
disable_irq_wake(fsl_wakeup->timer->irq);
mpic_free_timer(fsl_wakeup->timer);
}
kfree(fsl_wakeup);
mutex_unlock(&sysfs_lock);
}
