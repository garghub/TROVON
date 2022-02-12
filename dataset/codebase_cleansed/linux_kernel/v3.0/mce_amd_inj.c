static ssize_t edac_inject_bank_store(struct kobject *kobj,
struct edac_mce_attr *attr,
const char *data, size_t count)
{
int ret = 0;
unsigned long value;
ret = strict_strtoul(data, 10, &value);
if (ret < 0) {
printk(KERN_ERR "Invalid bank value!\n");
return -EINVAL;
}
if (value > 5)
if (boot_cpu_data.x86 != 0x15 || value > 6) {
printk(KERN_ERR "Non-existent MCE bank: %lu\n", value);
return -EINVAL;
}
i_mce.bank = value;
amd_decode_mce(NULL, 0, &i_mce);
return count;
}
static ssize_t edac_inject_bank_show(struct kobject *kobj,
struct edac_mce_attr *attr, char *buf)
{
return sprintf(buf, "%d\n", i_mce.bank);
}
static int __init edac_init_mce_inject(void)
{
struct sysdev_class *edac_class = NULL;
int i, err = 0;
edac_class = edac_get_sysfs_class();
if (!edac_class)
return -EINVAL;
mce_kobj = kobject_create_and_add("mce", &edac_class->kset.kobj);
if (!mce_kobj) {
printk(KERN_ERR "Error creating a mce kset.\n");
err = -ENOMEM;
goto err_mce_kobj;
}
for (i = 0; i < ARRAY_SIZE(sysfs_attrs); i++) {
err = sysfs_create_file(mce_kobj, &sysfs_attrs[i]->attr);
if (err) {
printk(KERN_ERR "Error creating %s in sysfs.\n",
sysfs_attrs[i]->attr.name);
goto err_sysfs_create;
}
}
return 0;
err_sysfs_create:
while (--i >= 0)
sysfs_remove_file(mce_kobj, &sysfs_attrs[i]->attr);
kobject_del(mce_kobj);
err_mce_kobj:
edac_put_sysfs_class();
return err;
}
static void __exit edac_exit_mce_inject(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(sysfs_attrs); i++)
sysfs_remove_file(mce_kobj, &sysfs_attrs[i]->attr);
kobject_del(mce_kobj);
edac_put_sysfs_class();
}
