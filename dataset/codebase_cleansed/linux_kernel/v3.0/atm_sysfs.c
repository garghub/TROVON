static ssize_t show_type(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct atm_dev *adev = to_atm_dev(cdev);
return sprintf(buf, "%s\n", adev->type);
}
static ssize_t show_address(struct device *cdev,
struct device_attribute *attr, char *buf)
{
char *pos = buf;
struct atm_dev *adev = to_atm_dev(cdev);
int i;
for (i = 0; i < (ESI_LEN - 1); i++)
pos += sprintf(pos, "%02x:", adev->esi[i]);
pos += sprintf(pos, "%02x\n", adev->esi[i]);
return pos - buf;
}
static ssize_t show_atmaddress(struct device *cdev,
struct device_attribute *attr, char *buf)
{
unsigned long flags;
char *pos = buf;
struct atm_dev *adev = to_atm_dev(cdev);
struct atm_dev_addr *aaddr;
int bin[] = { 1, 2, 10, 6, 1 }, *fmt = bin;
int i, j;
spin_lock_irqsave(&adev->lock, flags);
list_for_each_entry(aaddr, &adev->local, entry) {
for (i = 0, j = 0; i < ATM_ESA_LEN; ++i, ++j) {
if (j == *fmt) {
pos += sprintf(pos, ".");
++fmt;
j = 0;
}
pos += sprintf(pos, "%02x",
aaddr->addr.sas_addr.prv[i]);
}
pos += sprintf(pos, "\n");
}
spin_unlock_irqrestore(&adev->lock, flags);
return pos - buf;
}
static ssize_t show_atmindex(struct device *cdev,
struct device_attribute *attr, char *buf)
{
struct atm_dev *adev = to_atm_dev(cdev);
return sprintf(buf, "%d\n", adev->number);
}
static ssize_t show_carrier(struct device *cdev,
struct device_attribute *attr, char *buf)
{
char *pos = buf;
struct atm_dev *adev = to_atm_dev(cdev);
pos += sprintf(pos, "%d\n",
adev->signal == ATM_PHY_SIG_LOST ? 0 : 1);
return pos - buf;
}
static ssize_t show_link_rate(struct device *cdev,
struct device_attribute *attr, char *buf)
{
char *pos = buf;
struct atm_dev *adev = to_atm_dev(cdev);
int link_rate;
switch (adev->link_rate) {
case ATM_OC3_PCR:
link_rate = 155520000;
break;
case ATM_OC12_PCR:
link_rate = 622080000;
break;
case ATM_25_PCR:
link_rate = 25600000;
break;
default:
link_rate = adev->link_rate * 8 * 53;
}
pos += sprintf(pos, "%d\n", link_rate);
return pos - buf;
}
static int atm_uevent(struct device *cdev, struct kobj_uevent_env *env)
{
struct atm_dev *adev;
if (!cdev)
return -ENODEV;
adev = to_atm_dev(cdev);
if (!adev)
return -ENODEV;
if (add_uevent_var(env, "NAME=%s%d", adev->type, adev->number))
return -ENOMEM;
return 0;
}
static void atm_release(struct device *cdev)
{
struct atm_dev *adev = to_atm_dev(cdev);
kfree(adev);
}
int atm_register_sysfs(struct atm_dev *adev, struct device *parent)
{
struct device *cdev = &adev->class_dev;
int i, j, err;
cdev->class = &atm_class;
cdev->parent = parent;
dev_set_drvdata(cdev, adev);
dev_set_name(cdev, "%s%d", adev->type, adev->number);
err = device_register(cdev);
if (err < 0)
return err;
for (i = 0; atm_attrs[i]; i++) {
err = device_create_file(cdev, atm_attrs[i]);
if (err)
goto err_out;
}
return 0;
err_out:
for (j = 0; j < i; j++)
device_remove_file(cdev, atm_attrs[j]);
device_del(cdev);
return err;
}
void atm_unregister_sysfs(struct atm_dev *adev)
{
struct device *cdev = &adev->class_dev;
device_del(cdev);
}
int __init atm_sysfs_init(void)
{
return class_register(&atm_class);
}
void __exit atm_sysfs_exit(void)
{
class_unregister(&atm_class);
}
