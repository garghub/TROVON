static ssize_t firmware_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct rproc *rproc = to_rproc(dev);
return sprintf(buf, "%s\n", rproc->firmware);
}
static ssize_t firmware_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct rproc *rproc = to_rproc(dev);
char *p;
int err, len = count;
err = mutex_lock_interruptible(&rproc->lock);
if (err) {
dev_err(dev, "can't lock rproc %s: %d\n", rproc->name, err);
return -EINVAL;
}
if (rproc->state != RPROC_OFFLINE) {
dev_err(dev, "can't change firmware while running\n");
err = -EBUSY;
goto out;
}
len = strcspn(buf, "\n");
p = kstrndup(buf, len, GFP_KERNEL);
if (!p) {
err = -ENOMEM;
goto out;
}
kfree(rproc->firmware);
rproc->firmware = p;
out:
mutex_unlock(&rproc->lock);
return err ? err : count;
}
static ssize_t state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct rproc *rproc = to_rproc(dev);
unsigned int state;
state = rproc->state > RPROC_LAST ? RPROC_LAST : rproc->state;
return sprintf(buf, "%s\n", rproc_state_string[state]);
}
static ssize_t state_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct rproc *rproc = to_rproc(dev);
int ret = 0;
if (sysfs_streq(buf, "start")) {
if (rproc->state == RPROC_RUNNING)
return -EBUSY;
ret = rproc_boot(rproc);
if (ret)
dev_err(&rproc->dev, "Boot failed: %d\n", ret);
} else if (sysfs_streq(buf, "stop")) {
if (rproc->state != RPROC_RUNNING)
return -EINVAL;
rproc_shutdown(rproc);
} else {
dev_err(&rproc->dev, "Unrecognised option: %s\n", buf);
ret = -EINVAL;
}
return ret ? ret : count;
}
int __init rproc_init_sysfs(void)
{
int err = class_register(&rproc_class);
if (err)
pr_err("remoteproc: unable to register class\n");
return err;
}
void __exit rproc_exit_sysfs(void)
{
class_unregister(&rproc_class);
}
