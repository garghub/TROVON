void add_event_entry(unsigned long value)
{
if (!event_buffer) {
WARN_ON_ONCE(1);
return;
}
if (buffer_pos == buffer_size) {
atomic_inc(&oprofile_stats.event_lost_overflow);
return;
}
event_buffer[buffer_pos] = value;
if (++buffer_pos == buffer_size - buffer_watershed) {
atomic_set(&buffer_ready, 1);
wake_up(&buffer_wait);
}
}
void wake_up_buffer_waiter(void)
{
mutex_lock(&buffer_mutex);
atomic_set(&buffer_ready, 1);
wake_up(&buffer_wait);
mutex_unlock(&buffer_mutex);
}
int alloc_event_buffer(void)
{
unsigned long flags;
spin_lock_irqsave(&oprofilefs_lock, flags);
buffer_size = oprofile_buffer_size;
buffer_watershed = oprofile_buffer_watershed;
spin_unlock_irqrestore(&oprofilefs_lock, flags);
if (buffer_watershed >= buffer_size)
return -EINVAL;
buffer_pos = 0;
event_buffer = vmalloc(sizeof(unsigned long) * buffer_size);
if (!event_buffer)
return -ENOMEM;
return 0;
}
void free_event_buffer(void)
{
mutex_lock(&buffer_mutex);
vfree(event_buffer);
buffer_pos = 0;
event_buffer = NULL;
mutex_unlock(&buffer_mutex);
}
static int event_buffer_open(struct inode *inode, struct file *file)
{
int err = -EPERM;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (test_and_set_bit_lock(0, &buffer_opened))
return -EBUSY;
err = -EINVAL;
file->private_data = dcookie_register();
if (!file->private_data)
goto out;
if ((err = oprofile_setup()))
goto fail;
return nonseekable_open(inode, file);
fail:
dcookie_unregister(file->private_data);
out:
__clear_bit_unlock(0, &buffer_opened);
return err;
}
static int event_buffer_release(struct inode *inode, struct file *file)
{
oprofile_stop();
oprofile_shutdown();
dcookie_unregister(file->private_data);
buffer_pos = 0;
atomic_set(&buffer_ready, 0);
__clear_bit_unlock(0, &buffer_opened);
return 0;
}
static ssize_t event_buffer_read(struct file *file, char __user *buf,
size_t count, loff_t *offset)
{
int retval = -EINVAL;
size_t const max = buffer_size * sizeof(unsigned long);
if (count != max || *offset)
return -EINVAL;
wait_event_interruptible(buffer_wait, atomic_read(&buffer_ready));
if (signal_pending(current))
return -EINTR;
if (!atomic_read(&buffer_ready))
return -EAGAIN;
mutex_lock(&buffer_mutex);
if (!event_buffer) {
retval = -EINTR;
goto out;
}
atomic_set(&buffer_ready, 0);
retval = -EFAULT;
count = buffer_pos * sizeof(unsigned long);
if (copy_to_user(buf, event_buffer, count))
goto out;
retval = count;
buffer_pos = 0;
out:
mutex_unlock(&buffer_mutex);
return retval;
}
