static ssize_t uevent_seqnum_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%llu\n", (unsigned long long)uevent_seqnum);
}
static ssize_t uevent_helper_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", uevent_helper);
}
static ssize_t uevent_helper_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
if (count+1 > UEVENT_HELPER_PATH_LEN)
return -ENOENT;
memcpy(uevent_helper, buf, count);
uevent_helper[count] = '\0';
if (count && uevent_helper[count-1] == '\n')
uevent_helper[count-1] = '\0';
return count;
}
static ssize_t profiling_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", prof_on);
}
static ssize_t profiling_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int ret;
if (prof_on)
return -EEXIST;
profile_setup((char *)buf);
ret = profile_init();
if (ret)
return ret;
ret = create_proc_profile();
if (ret)
return ret;
return count;
}
static ssize_t kexec_loaded_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", !!kexec_image);
}
static ssize_t kexec_crash_loaded_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", !!kexec_crash_image);
}
static ssize_t kexec_crash_size_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%zu\n", crash_get_memory_size());
}
static ssize_t kexec_crash_size_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
unsigned long cnt;
int ret;
if (kstrtoul(buf, 0, &cnt))
return -EINVAL;
ret = crash_shrink_memory(cnt);
return ret < 0 ? ret : count;
}
static ssize_t vmcoreinfo_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lx %x\n",
paddr_vmcoreinfo_note(),
(unsigned int)vmcoreinfo_max_size);
}
static ssize_t fscaps_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", file_caps_enabled);
}
static ssize_t rcu_expedited_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", rcu_expedited);
}
static ssize_t rcu_expedited_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
if (kstrtoint(buf, 0, &rcu_expedited))
return -EINVAL;
return count;
}
static ssize_t notes_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
memcpy(buf, &__start_notes + off, count);
return count;
}
static int __init ksysfs_init(void)
{
int error;
kernel_kobj = kobject_create_and_add("kernel", NULL);
if (!kernel_kobj) {
error = -ENOMEM;
goto exit;
}
error = sysfs_create_group(kernel_kobj, &kernel_attr_group);
if (error)
goto kset_exit;
if (notes_size > 0) {
notes_attr.size = notes_size;
error = sysfs_create_bin_file(kernel_kobj, &notes_attr);
if (error)
goto group_exit;
}
return 0;
group_exit:
sysfs_remove_group(kernel_kobj, &kernel_attr_group);
kset_exit:
kobject_put(kernel_kobj);
exit:
return error;
}
