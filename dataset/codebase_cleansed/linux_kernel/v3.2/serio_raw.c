static int serio_raw_fasync(int fd, struct file *file, int on)
{
struct serio_raw_client *client = file->private_data;
return fasync_helper(fd, file, on, &client->fasync);
}
static struct serio_raw *serio_raw_locate(int minor)
{
struct serio_raw *serio_raw;
list_for_each_entry(serio_raw, &serio_raw_list, node) {
if (serio_raw->dev.minor == minor)
return serio_raw;
}
return NULL;
}
static int serio_raw_open(struct inode *inode, struct file *file)
{
struct serio_raw *serio_raw;
struct serio_raw_client *client;
int retval;
retval = mutex_lock_interruptible(&serio_raw_mutex);
if (retval)
return retval;
serio_raw = serio_raw_locate(iminor(inode));
if (!serio_raw) {
retval = -ENODEV;
goto out;
}
if (serio_raw->dead) {
retval = -ENODEV;
goto out;
}
client = kzalloc(sizeof(struct serio_raw_client), GFP_KERNEL);
if (!client) {
retval = -ENOMEM;
goto out;
}
client->serio_raw = serio_raw;
file->private_data = client;
kref_get(&serio_raw->kref);
serio_pause_rx(serio_raw->serio);
list_add_tail(&client->node, &serio_raw->client_list);
serio_continue_rx(serio_raw->serio);
out:
mutex_unlock(&serio_raw_mutex);
return retval;
}
static void serio_raw_free(struct kref *kref)
{
struct serio_raw *serio_raw =
container_of(kref, struct serio_raw, kref);
put_device(&serio_raw->serio->dev);
kfree(serio_raw);
}
static int serio_raw_release(struct inode *inode, struct file *file)
{
struct serio_raw_client *client = file->private_data;
struct serio_raw *serio_raw = client->serio_raw;
serio_pause_rx(serio_raw->serio);
list_del(&client->node);
serio_continue_rx(serio_raw->serio);
kfree(client);
kref_put(&serio_raw->kref, serio_raw_free);
return 0;
}
static bool serio_raw_fetch_byte(struct serio_raw *serio_raw, char *c)
{
bool empty;
serio_pause_rx(serio_raw->serio);
empty = serio_raw->head == serio_raw->tail;
if (!empty) {
*c = serio_raw->queue[serio_raw->tail];
serio_raw->tail = (serio_raw->tail + 1) % SERIO_RAW_QUEUE_LEN;
}
serio_continue_rx(serio_raw->serio);
return !empty;
}
static ssize_t serio_raw_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
struct serio_raw_client *client = file->private_data;
struct serio_raw *serio_raw = client->serio_raw;
char uninitialized_var(c);
ssize_t retval = 0;
if (serio_raw->dead)
return -ENODEV;
if (serio_raw->head == serio_raw->tail && (file->f_flags & O_NONBLOCK))
return -EAGAIN;
retval = wait_event_interruptible(serio_raw->wait,
serio_raw->head != serio_raw->tail || serio_raw->dead);
if (retval)
return retval;
if (serio_raw->dead)
return -ENODEV;
while (retval < count && serio_raw_fetch_byte(serio_raw, &c)) {
if (put_user(c, buffer++))
return -EFAULT;
retval++;
}
return retval;
}
static ssize_t serio_raw_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct serio_raw_client *client = file->private_data;
struct serio_raw *serio_raw = client->serio_raw;
ssize_t written = 0;
int retval;
unsigned char c;
retval = mutex_lock_interruptible(&serio_raw_mutex);
if (retval)
return retval;
if (serio_raw->dead) {
retval = -ENODEV;
goto out;
}
if (count > 32)
count = 32;
while (count--) {
if (get_user(c, buffer++)) {
retval = -EFAULT;
goto out;
}
if (serio_write(serio_raw->serio, c)) {
retval = -EIO;
goto out;
}
written++;
};
out:
mutex_unlock(&serio_raw_mutex);
return written;
}
static unsigned int serio_raw_poll(struct file *file, poll_table *wait)
{
struct serio_raw_client *client = file->private_data;
struct serio_raw *serio_raw = client->serio_raw;
unsigned int mask;
poll_wait(file, &serio_raw->wait, wait);
mask = serio_raw->dead ? POLLHUP | POLLERR : POLLOUT | POLLWRNORM;
if (serio_raw->head != serio_raw->tail)
return POLLIN | POLLRDNORM;
return 0;
}
static irqreturn_t serio_raw_interrupt(struct serio *serio, unsigned char data,
unsigned int dfl)
{
struct serio_raw *serio_raw = serio_get_drvdata(serio);
struct serio_raw_client *client;
unsigned int head = serio_raw->head;
serio_raw->queue[head] = data;
head = (head + 1) % SERIO_RAW_QUEUE_LEN;
if (likely(head != serio_raw->tail)) {
serio_raw->head = head;
list_for_each_entry(client, &serio_raw->client_list, node)
kill_fasync(&client->fasync, SIGIO, POLL_IN);
wake_up_interruptible(&serio_raw->wait);
}
return IRQ_HANDLED;
}
static int serio_raw_connect(struct serio *serio, struct serio_driver *drv)
{
static atomic_t serio_raw_no = ATOMIC_INIT(0);
struct serio_raw *serio_raw;
int err;
serio_raw = kzalloc(sizeof(struct serio_raw), GFP_KERNEL);
if (!serio_raw) {
dev_dbg(&serio->dev, "can't allocate memory for a device\n");
return -ENOMEM;
}
snprintf(serio_raw->name, sizeof(serio_raw->name),
"serio_raw%ld", (long)atomic_inc_return(&serio_raw_no) - 1);
kref_init(&serio_raw->kref);
INIT_LIST_HEAD(&serio_raw->client_list);
init_waitqueue_head(&serio_raw->wait);
serio_raw->serio = serio;
get_device(&serio->dev);
serio_set_drvdata(serio, serio_raw);
err = serio_open(serio, drv);
if (err)
goto err_free;
err = mutex_lock_killable(&serio_raw_mutex);
if (err)
goto err_close;
list_add_tail(&serio_raw->node, &serio_raw_list);
mutex_unlock(&serio_raw_mutex);
serio_raw->dev.minor = PSMOUSE_MINOR;
serio_raw->dev.name = serio_raw->name;
serio_raw->dev.parent = &serio->dev;
serio_raw->dev.fops = &serio_raw_fops;
err = misc_register(&serio_raw->dev);
if (err) {
serio_raw->dev.minor = MISC_DYNAMIC_MINOR;
err = misc_register(&serio_raw->dev);
}
if (err) {
dev_err(&serio->dev,
"failed to register raw access device for %s\n",
serio->phys);
goto err_unlink;
}
dev_info(&serio->dev, "raw access enabled on %s (%s, minor %d)\n",
serio->phys, serio_raw->name, serio_raw->dev.minor);
return 0;
err_unlink:
list_del_init(&serio_raw->node);
err_close:
serio_close(serio);
err_free:
serio_set_drvdata(serio, NULL);
kref_put(&serio_raw->kref, serio_raw_free);
return err;
}
static int serio_raw_reconnect(struct serio *serio)
{
struct serio_raw *serio_raw = serio_get_drvdata(serio);
struct serio_driver *drv = serio->drv;
if (!drv || !serio_raw) {
dev_dbg(&serio->dev,
"reconnect request, but serio is disconnected, ignoring...\n");
return -1;
}
return 0;
}
static void serio_raw_hangup(struct serio_raw *serio_raw)
{
struct serio_raw_client *client;
serio_pause_rx(serio_raw->serio);
list_for_each_entry(client, &serio_raw->client_list, node)
kill_fasync(&client->fasync, SIGIO, POLL_HUP);
serio_continue_rx(serio_raw->serio);
wake_up_interruptible(&serio_raw->wait);
}
static void serio_raw_disconnect(struct serio *serio)
{
struct serio_raw *serio_raw = serio_get_drvdata(serio);
misc_deregister(&serio_raw->dev);
mutex_lock(&serio_raw_mutex);
serio_raw->dead = true;
list_del_init(&serio_raw->node);
mutex_unlock(&serio_raw_mutex);
serio_raw_hangup(serio_raw);
serio_close(serio);
kref_put(&serio_raw->kref, serio_raw_free);
serio_set_drvdata(serio, NULL);
}
static int __init serio_raw_init(void)
{
return serio_register_driver(&serio_raw_drv);
}
static void __exit serio_raw_exit(void)
{
serio_unregister_driver(&serio_raw_drv);
}
