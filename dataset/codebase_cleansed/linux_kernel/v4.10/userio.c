static int userio_device_write(struct serio *id, unsigned char val)
{
struct userio_device *userio = id->port_data;
unsigned long flags;
spin_lock_irqsave(&userio->buf_lock, flags);
userio->buf[userio->head] = val;
userio->head = (userio->head + 1) % USERIO_BUFSIZE;
if (userio->head == userio->tail)
dev_warn(userio_misc.this_device,
"Buffer overflowed, userio client isn't keeping up");
spin_unlock_irqrestore(&userio->buf_lock, flags);
wake_up_interruptible(&userio->waitq);
return 0;
}
static int userio_char_open(struct inode *inode, struct file *file)
{
struct userio_device *userio;
userio = kzalloc(sizeof(struct userio_device), GFP_KERNEL);
if (!userio)
return -ENOMEM;
mutex_init(&userio->mutex);
spin_lock_init(&userio->buf_lock);
init_waitqueue_head(&userio->waitq);
userio->serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!userio->serio) {
kfree(userio);
return -ENOMEM;
}
userio->serio->write = userio_device_write;
userio->serio->port_data = userio;
file->private_data = userio;
return 0;
}
static int userio_char_release(struct inode *inode, struct file *file)
{
struct userio_device *userio = file->private_data;
if (userio->running) {
serio_unregister_port(userio->serio);
} else {
kfree(userio->serio);
}
kfree(userio);
return 0;
}
static ssize_t userio_char_read(struct file *file, char __user *user_buffer,
size_t count, loff_t *ppos)
{
struct userio_device *userio = file->private_data;
int error;
size_t nonwrap_len, copylen;
unsigned char buf[USERIO_BUFSIZE];
unsigned long flags;
for (;;) {
spin_lock_irqsave(&userio->buf_lock, flags);
nonwrap_len = CIRC_CNT_TO_END(userio->head,
userio->tail,
USERIO_BUFSIZE);
copylen = min(nonwrap_len, count);
if (copylen) {
memcpy(buf, &userio->buf[userio->tail], copylen);
userio->tail = (userio->tail + copylen) %
USERIO_BUFSIZE;
}
spin_unlock_irqrestore(&userio->buf_lock, flags);
if (nonwrap_len)
break;
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
if (count == 0)
return 0;
error = wait_event_interruptible(userio->waitq,
userio->head != userio->tail);
if (error)
return error;
}
if (copylen)
if (copy_to_user(user_buffer, buf, copylen))
return -EFAULT;
return copylen;
}
static ssize_t userio_char_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct userio_device *userio = file->private_data;
struct userio_cmd cmd;
int error;
if (count != sizeof(cmd)) {
dev_warn(userio_misc.this_device, "Invalid payload size\n");
return -EINVAL;
}
if (copy_from_user(&cmd, buffer, sizeof(cmd)))
return -EFAULT;
error = mutex_lock_interruptible(&userio->mutex);
if (error)
return error;
switch (cmd.type) {
case USERIO_CMD_REGISTER:
if (!userio->serio->id.type) {
dev_warn(userio_misc.this_device,
"No port type given on /dev/userio\n");
error = -EINVAL;
goto out;
}
if (userio->running) {
dev_warn(userio_misc.this_device,
"Begin command sent, but we're already running\n");
error = -EBUSY;
goto out;
}
userio->running = true;
serio_register_port(userio->serio);
break;
case USERIO_CMD_SET_PORT_TYPE:
if (userio->running) {
dev_warn(userio_misc.this_device,
"Can't change port type on an already running userio instance\n");
error = -EBUSY;
goto out;
}
userio->serio->id.type = cmd.data;
break;
case USERIO_CMD_SEND_INTERRUPT:
if (!userio->running) {
dev_warn(userio_misc.this_device,
"The device must be registered before sending interrupts\n");
error = -ENODEV;
goto out;
}
serio_interrupt(userio->serio, cmd.data, 0);
break;
default:
error = -EOPNOTSUPP;
goto out;
}
out:
mutex_unlock(&userio->mutex);
return error ?: count;
}
static unsigned int userio_char_poll(struct file *file, poll_table *wait)
{
struct userio_device *userio = file->private_data;
poll_wait(file, &userio->waitq, wait);
if (userio->head != userio->tail)
return POLLIN | POLLRDNORM;
return 0;
}
