static ssize_t
rtc_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct rtc_device *rtc = attr->private;
dev_warn_once(kobj_to_dev(kobj), nvram_warning);
return nvmem_device_read(rtc->nvmem, off, count, buf);
}
static ssize_t
rtc_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct rtc_device *rtc = attr->private;
dev_warn_once(kobj_to_dev(kobj), nvram_warning);
return nvmem_device_write(rtc->nvmem, off, count, buf);
}
static int rtc_nvram_register(struct rtc_device *rtc)
{
int err;
rtc->nvram = devm_kzalloc(rtc->dev.parent,
sizeof(struct bin_attribute),
GFP_KERNEL);
if (!rtc->nvram)
return -ENOMEM;
rtc->nvram->attr.name = "nvram";
rtc->nvram->attr.mode = 0644;
rtc->nvram->private = rtc;
sysfs_bin_attr_init(rtc->nvram);
rtc->nvram->read = rtc_nvram_read;
rtc->nvram->write = rtc_nvram_write;
rtc->nvram->size = rtc->nvmem_config->size;
err = sysfs_create_bin_file(&rtc->dev.parent->kobj,
rtc->nvram);
if (err) {
devm_kfree(rtc->dev.parent, rtc->nvram);
rtc->nvram = NULL;
}
return err;
}
static void rtc_nvram_unregister(struct rtc_device *rtc)
{
sysfs_remove_bin_file(&rtc->dev.parent->kobj, rtc->nvram);
}
void rtc_nvmem_register(struct rtc_device *rtc)
{
if (!rtc->nvmem_config)
return;
rtc->nvmem_config->dev = &rtc->dev;
rtc->nvmem_config->owner = rtc->owner;
rtc->nvmem = nvmem_register(rtc->nvmem_config);
if (IS_ERR_OR_NULL(rtc->nvmem))
return;
if (rtc->nvram_old_abi)
rtc_nvram_register(rtc);
}
void rtc_nvmem_unregister(struct rtc_device *rtc)
{
if (IS_ERR_OR_NULL(rtc->nvmem))
return;
if (rtc->nvram)
rtc_nvram_unregister(rtc);
nvmem_unregister(rtc->nvmem);
}
