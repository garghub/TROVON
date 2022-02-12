static
struct idletimer_tg *__idletimer_tg_find_by_label(const char *label)
{
struct idletimer_tg *entry;
BUG_ON(!label);
list_for_each_entry(entry, &idletimer_tg_list, entry) {
if (!strcmp(label, entry->attr.attr.name))
return entry;
}
return NULL;
}
static ssize_t idletimer_tg_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct idletimer_tg *timer;
unsigned long expires = 0;
mutex_lock(&list_mutex);
timer = __idletimer_tg_find_by_label(attr->name);
if (timer)
expires = timer->timer.expires;
mutex_unlock(&list_mutex);
if (time_after(expires, jiffies))
return sprintf(buf, "%u\n",
jiffies_to_msecs(expires - jiffies) / 1000);
return sprintf(buf, "0\n");
}
static void idletimer_tg_work(struct work_struct *work)
{
struct idletimer_tg *timer = container_of(work, struct idletimer_tg,
work);
sysfs_notify(idletimer_tg_kobj, NULL, timer->attr.attr.name);
}
static void idletimer_tg_expired(unsigned long data)
{
struct idletimer_tg *timer = (struct idletimer_tg *) data;
pr_debug("timer %s expired\n", timer->attr.attr.name);
schedule_work(&timer->work);
}
static int idletimer_tg_create(struct idletimer_tg_info *info)
{
int ret;
info->timer = kmalloc(sizeof(*info->timer), GFP_KERNEL);
if (!info->timer) {
ret = -ENOMEM;
goto out;
}
sysfs_attr_init(&info->timer->attr.attr);
info->timer->attr.attr.name = kstrdup(info->label, GFP_KERNEL);
if (!info->timer->attr.attr.name) {
ret = -ENOMEM;
goto out_free_timer;
}
info->timer->attr.attr.mode = S_IRUGO;
info->timer->attr.show = idletimer_tg_show;
ret = sysfs_create_file(idletimer_tg_kobj, &info->timer->attr.attr);
if (ret < 0) {
pr_debug("couldn't add file to sysfs");
goto out_free_attr;
}
list_add(&info->timer->entry, &idletimer_tg_list);
setup_timer(&info->timer->timer, idletimer_tg_expired,
(unsigned long) info->timer);
info->timer->refcnt = 1;
mod_timer(&info->timer->timer,
msecs_to_jiffies(info->timeout * 1000) + jiffies);
INIT_WORK(&info->timer->work, idletimer_tg_work);
return 0;
out_free_attr:
kfree(info->timer->attr.attr.name);
out_free_timer:
kfree(info->timer);
out:
return ret;
}
static unsigned int idletimer_tg_target(struct sk_buff *skb,
const struct xt_action_param *par)
{
const struct idletimer_tg_info *info = par->targinfo;
pr_debug("resetting timer %s, timeout period %u\n",
info->label, info->timeout);
BUG_ON(!info->timer);
mod_timer(&info->timer->timer,
msecs_to_jiffies(info->timeout * 1000) + jiffies);
return XT_CONTINUE;
}
static int idletimer_tg_checkentry(const struct xt_tgchk_param *par)
{
struct idletimer_tg_info *info = par->targinfo;
int ret;
pr_debug("checkentry targinfo%s\n", info->label);
if (info->timeout == 0) {
pr_debug("timeout value is zero\n");
return -EINVAL;
}
if (info->label[0] == '\0' ||
strnlen(info->label,
MAX_IDLETIMER_LABEL_SIZE) == MAX_IDLETIMER_LABEL_SIZE) {
pr_debug("label is empty or not nul-terminated\n");
return -EINVAL;
}
mutex_lock(&list_mutex);
info->timer = __idletimer_tg_find_by_label(info->label);
if (info->timer) {
info->timer->refcnt++;
mod_timer(&info->timer->timer,
msecs_to_jiffies(info->timeout * 1000) + jiffies);
pr_debug("increased refcnt of timer %s to %u\n",
info->label, info->timer->refcnt);
} else {
ret = idletimer_tg_create(info);
if (ret < 0) {
pr_debug("failed to create timer\n");
mutex_unlock(&list_mutex);
return ret;
}
}
mutex_unlock(&list_mutex);
return 0;
}
static void idletimer_tg_destroy(const struct xt_tgdtor_param *par)
{
const struct idletimer_tg_info *info = par->targinfo;
pr_debug("destroy targinfo %s\n", info->label);
mutex_lock(&list_mutex);
if (--info->timer->refcnt == 0) {
pr_debug("deleting timer %s\n", info->label);
list_del(&info->timer->entry);
del_timer_sync(&info->timer->timer);
sysfs_remove_file(idletimer_tg_kobj, &info->timer->attr.attr);
kfree(info->timer->attr.attr.name);
kfree(info->timer);
} else {
pr_debug("decreased refcnt of timer %s to %u\n",
info->label, info->timer->refcnt);
}
mutex_unlock(&list_mutex);
}
static int __init idletimer_tg_init(void)
{
int err;
idletimer_tg_class = class_create(THIS_MODULE, "xt_idletimer");
err = PTR_ERR(idletimer_tg_class);
if (IS_ERR(idletimer_tg_class)) {
pr_debug("couldn't register device class\n");
goto out;
}
idletimer_tg_device = device_create(idletimer_tg_class, NULL,
MKDEV(0, 0), NULL, "timers");
err = PTR_ERR(idletimer_tg_device);
if (IS_ERR(idletimer_tg_device)) {
pr_debug("couldn't register system device\n");
goto out_class;
}
idletimer_tg_kobj = &idletimer_tg_device->kobj;
err = xt_register_target(&idletimer_tg);
if (err < 0) {
pr_debug("couldn't register xt target\n");
goto out_dev;
}
return 0;
out_dev:
device_destroy(idletimer_tg_class, MKDEV(0, 0));
out_class:
class_destroy(idletimer_tg_class);
out:
return err;
}
static void __exit idletimer_tg_exit(void)
{
xt_unregister_target(&idletimer_tg);
device_destroy(idletimer_tg_class, MKDEV(0, 0));
class_destroy(idletimer_tg_class);
}
