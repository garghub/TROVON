static ssize_t mlog_mask_show(u64 mask, char *buf)
{
char *state;
if (__mlog_test_u64(mask, r2_mlog_and_bits))
state = "allow";
else if (__mlog_test_u64(mask, r2_mlog_not_bits))
state = "deny";
else
state = "off";
return snprintf(buf, PAGE_SIZE, "%s\n", state);
}
static ssize_t mlog_mask_store(u64 mask, const char *buf, size_t count)
{
if (!strnicmp(buf, "allow", 5)) {
__mlog_set_u64(mask, r2_mlog_and_bits);
__mlog_clear_u64(mask, r2_mlog_not_bits);
} else if (!strnicmp(buf, "deny", 4)) {
__mlog_set_u64(mask, r2_mlog_not_bits);
__mlog_clear_u64(mask, r2_mlog_and_bits);
} else if (!strnicmp(buf, "off", 3)) {
__mlog_clear_u64(mask, r2_mlog_not_bits);
__mlog_clear_u64(mask, r2_mlog_and_bits);
} else
return -EINVAL;
return count;
}
static ssize_t mlog_show(struct kobject *obj, struct attribute *attr,
char *buf)
{
struct mlog_attribute *mlog_attr = to_mlog_attr(attr);
return mlog_mask_show(mlog_attr->mask, buf);
}
static ssize_t mlog_store(struct kobject *obj, struct attribute *attr,
const char *buf, size_t count)
{
struct mlog_attribute *mlog_attr = to_mlog_attr(attr);
return mlog_mask_store(mlog_attr->mask, buf, count);
}
int r2_mlog_sys_init(struct kset *r2cb_kset)
{
int i = 0;
while (mlog_attrs[i].attr.mode) {
mlog_attr_ptrs[i] = &mlog_attrs[i].attr;
i++;
}
mlog_attr_ptrs[i] = NULL;
kobject_set_name(&mlog_kset.kobj, "logmask");
mlog_kset.kobj.kset = r2cb_kset;
return kset_register(&mlog_kset);
}
void r2_mlog_sys_shutdown(void)
{
kset_unregister(&mlog_kset);
}
