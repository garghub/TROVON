static ssize_t timeout_read(struct file *file, char __user *buf,
size_t count, loff_t *offset)
{
return oprofilefs_ulong_to_user(jiffies_to_msecs(oprofile_time_slice),
buf, count, offset);
}
static ssize_t timeout_write(struct file *file, char const __user *buf,
size_t count, loff_t *offset)
{
unsigned long val;
int retval;
if (*offset)
return -EINVAL;
retval = oprofilefs_ulong_from_user(&val, buf, count);
if (retval <= 0)
return retval;
retval = oprofile_set_timeout(val);
if (retval)
return retval;
return count;
}
static ssize_t depth_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
return oprofilefs_ulong_to_user(oprofile_backtrace_depth, buf, count,
offset);
}
static ssize_t depth_write(struct file *file, char const __user *buf, size_t count, loff_t *offset)
{
unsigned long val;
int retval;
if (*offset)
return -EINVAL;
if (!oprofile_ops.backtrace)
return -EINVAL;
retval = oprofilefs_ulong_from_user(&val, buf, count);
if (retval <= 0)
return retval;
retval = oprofile_set_ulong(&oprofile_backtrace_depth, val);
if (retval)
return retval;
return count;
}
static ssize_t pointer_size_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
return oprofilefs_ulong_to_user(sizeof(void *), buf, count, offset);
}
static ssize_t cpu_type_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
return oprofilefs_str_to_user(oprofile_ops.cpu_type, buf, count, offset);
}
static ssize_t enable_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
return oprofilefs_ulong_to_user(oprofile_started, buf, count, offset);
}
static ssize_t enable_write(struct file *file, char const __user *buf, size_t count, loff_t *offset)
{
unsigned long val;
int retval;
if (*offset)
return -EINVAL;
retval = oprofilefs_ulong_from_user(&val, buf, count);
if (retval <= 0)
return retval;
retval = 0;
if (val)
retval = oprofile_start();
else
oprofile_stop();
if (retval)
return retval;
return count;
}
static ssize_t dump_write(struct file *file, char const __user *buf, size_t count, loff_t *offset)
{
wake_up_buffer_waiter();
return count;
}
void oprofile_create_files(struct dentry *root)
{
oprofile_buffer_size = BUFFER_SIZE_DEFAULT;
oprofile_cpu_buffer_size = CPU_BUFFER_SIZE_DEFAULT;
oprofile_buffer_watershed = BUFFER_WATERSHED_DEFAULT;
oprofile_time_slice = msecs_to_jiffies(TIME_SLICE_DEFAULT);
oprofilefs_create_file(root, "enable", &enable_fops);
oprofilefs_create_file_perm(root, "dump", &dump_fops, 0666);
oprofilefs_create_file(root, "buffer", &event_buffer_fops);
oprofilefs_create_ulong(root, "buffer_size", &oprofile_buffer_size);
oprofilefs_create_ulong(root, "buffer_watershed", &oprofile_buffer_watershed);
oprofilefs_create_ulong(root, "cpu_buffer_size", &oprofile_cpu_buffer_size);
oprofilefs_create_file(root, "cpu_type", &cpu_type_fops);
oprofilefs_create_file(root, "backtrace_depth", &depth_fops);
oprofilefs_create_file(root, "pointer_size", &pointer_size_fops);
#ifdef CONFIG_OPROFILE_EVENT_MULTIPLEX
oprofilefs_create_file(root, "time_slice", &timeout_fops);
#endif
oprofile_create_stats_files(root);
if (oprofile_ops.create_files)
oprofile_ops.create_files(root);
}
