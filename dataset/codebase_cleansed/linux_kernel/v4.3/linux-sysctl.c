static ssize_t static_uintvalue_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct static_lustre_uintvalue_attr *lattr = (void *)attr;
return sprintf(buf, "%d\n", *lattr->value);
}
static ssize_t static_uintvalue_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer, size_t count)
{
struct static_lustre_uintvalue_attr *lattr = (void *)attr;
int rc;
unsigned int val;
rc = kstrtouint(buffer, 10, &val);
if (rc)
return rc;
*lattr->value = val;
return count;
}
static ssize_t max_dirty_mb_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
return sprintf(buf, "%ul\n",
obd_max_dirty_pages / (1 << (20 - PAGE_CACHE_SHIFT)));
}
static ssize_t max_dirty_mb_store(struct kobject *kobj, struct attribute *attr,
const char *buffer, size_t count)
{
int rc;
unsigned long val;
rc = kstrtoul(buffer, 10, &val);
if (rc)
return rc;
val *= 1 << (20 - PAGE_CACHE_SHIFT);
if (val > ((totalram_pages / 10) * 9)) {
return -EINVAL;
}
if (val < 4 << (20 - PAGE_CACHE_SHIFT)) {
return -EINVAL;
}
obd_max_dirty_pages = val;
return count;
}
int obd_sysctl_init(void)
{
return sysfs_create_group(lustre_kobj, &lustre_attr_group);
}
void obd_sysctl_clean(void)
{
}
