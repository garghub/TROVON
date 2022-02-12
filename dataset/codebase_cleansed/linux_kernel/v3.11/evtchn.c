static inline struct per_user_data *get_port_user(unsigned port)
{
return (struct per_user_data *)(port_user[port] & ~1);
}
static inline void set_port_user(unsigned port, struct per_user_data *u)
{
port_user[port] = (unsigned long)u;
}
static inline bool get_port_enabled(unsigned port)
{
return port_user[port] & 1;
}
static inline void set_port_enabled(unsigned port, bool enabled)
{
if (enabled)
port_user[port] |= 1;
else
port_user[port] &= ~1;
}
static irqreturn_t evtchn_interrupt(int irq, void *data)
{
unsigned int port = (unsigned long)data;
struct per_user_data *u;
spin_lock(&port_user_lock);
u = get_port_user(port);
WARN(!get_port_enabled(port),
"Interrupt for port %d, but apparently not enabled; per-user %p\n",
port, u);
disable_irq_nosync(irq);
set_port_enabled(port, false);
if ((u->ring_prod - u->ring_cons) < EVTCHN_RING_SIZE) {
u->ring[EVTCHN_RING_MASK(u->ring_prod)] = port;
wmb();
if (u->ring_cons == u->ring_prod++) {
wake_up_interruptible(&u->evtchn_wait);
kill_fasync(&u->evtchn_async_queue,
SIGIO, POLL_IN);
}
} else
u->ring_overflow = 1;
spin_unlock(&port_user_lock);
return IRQ_HANDLED;
}
static ssize_t evtchn_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
int rc;
unsigned int c, p, bytes1 = 0, bytes2 = 0;
struct per_user_data *u = file->private_data;
count &= ~(sizeof(evtchn_port_t)-1);
if (count == 0)
return 0;
if (count > PAGE_SIZE)
count = PAGE_SIZE;
for (;;) {
mutex_lock(&u->ring_cons_mutex);
rc = -EFBIG;
if (u->ring_overflow)
goto unlock_out;
c = u->ring_cons;
p = u->ring_prod;
if (c != p)
break;
mutex_unlock(&u->ring_cons_mutex);
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
rc = wait_event_interruptible(u->evtchn_wait,
u->ring_cons != u->ring_prod);
if (rc)
return rc;
}
if (((c ^ p) & EVTCHN_RING_SIZE) != 0) {
bytes1 = (EVTCHN_RING_SIZE - EVTCHN_RING_MASK(c)) *
sizeof(evtchn_port_t);
bytes2 = EVTCHN_RING_MASK(p) * sizeof(evtchn_port_t);
} else {
bytes1 = (p - c) * sizeof(evtchn_port_t);
bytes2 = 0;
}
if (bytes1 > count) {
bytes1 = count;
bytes2 = 0;
} else if ((bytes1 + bytes2) > count) {
bytes2 = count - bytes1;
}
rc = -EFAULT;
rmb();
if (copy_to_user(buf, &u->ring[EVTCHN_RING_MASK(c)], bytes1) ||
((bytes2 != 0) &&
copy_to_user(&buf[bytes1], &u->ring[0], bytes2)))
goto unlock_out;
u->ring_cons += (bytes1 + bytes2) / sizeof(evtchn_port_t);
rc = bytes1 + bytes2;
unlock_out:
mutex_unlock(&u->ring_cons_mutex);
return rc;
}
static ssize_t evtchn_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
int rc, i;
evtchn_port_t *kbuf = (evtchn_port_t *)__get_free_page(GFP_KERNEL);
struct per_user_data *u = file->private_data;
if (kbuf == NULL)
return -ENOMEM;
count &= ~(sizeof(evtchn_port_t)-1);
rc = 0;
if (count == 0)
goto out;
if (count > PAGE_SIZE)
count = PAGE_SIZE;
rc = -EFAULT;
if (copy_from_user(kbuf, buf, count) != 0)
goto out;
spin_lock_irq(&port_user_lock);
for (i = 0; i < (count/sizeof(evtchn_port_t)); i++) {
unsigned port = kbuf[i];
if (port < NR_EVENT_CHANNELS &&
get_port_user(port) == u &&
!get_port_enabled(port)) {
set_port_enabled(port, true);
enable_irq(irq_from_evtchn(port));
}
}
spin_unlock_irq(&port_user_lock);
rc = count;
out:
free_page((unsigned long)kbuf);
return rc;
}
static int evtchn_bind_to_user(struct per_user_data *u, int port)
{
int rc = 0;
BUG_ON(get_port_user(port) != NULL);
set_port_user(port, u);
set_port_enabled(port, true);
rc = bind_evtchn_to_irqhandler(port, evtchn_interrupt, IRQF_DISABLED,
u->name, (void *)(unsigned long)port);
if (rc >= 0)
rc = evtchn_make_refcounted(port);
else {
struct evtchn_close close;
close.port = port;
if (HYPERVISOR_event_channel_op(EVTCHNOP_close, &close) != 0)
BUG();
set_port_user(port, NULL);
}
return rc;
}
static void evtchn_unbind_from_user(struct per_user_data *u, int port)
{
int irq = irq_from_evtchn(port);
BUG_ON(irq < 0);
unbind_from_irqhandler(irq, (void *)(unsigned long)port);
set_port_user(port, NULL);
}
static long evtchn_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int rc;
struct per_user_data *u = file->private_data;
void __user *uarg = (void __user *) arg;
mutex_lock(&u->bind_mutex);
switch (cmd) {
case IOCTL_EVTCHN_BIND_VIRQ: {
struct ioctl_evtchn_bind_virq bind;
struct evtchn_bind_virq bind_virq;
rc = -EFAULT;
if (copy_from_user(&bind, uarg, sizeof(bind)))
break;
bind_virq.virq = bind.virq;
bind_virq.vcpu = 0;
rc = HYPERVISOR_event_channel_op(EVTCHNOP_bind_virq,
&bind_virq);
if (rc != 0)
break;
rc = evtchn_bind_to_user(u, bind_virq.port);
if (rc == 0)
rc = bind_virq.port;
break;
}
case IOCTL_EVTCHN_BIND_INTERDOMAIN: {
struct ioctl_evtchn_bind_interdomain bind;
struct evtchn_bind_interdomain bind_interdomain;
rc = -EFAULT;
if (copy_from_user(&bind, uarg, sizeof(bind)))
break;
bind_interdomain.remote_dom = bind.remote_domain;
bind_interdomain.remote_port = bind.remote_port;
rc = HYPERVISOR_event_channel_op(EVTCHNOP_bind_interdomain,
&bind_interdomain);
if (rc != 0)
break;
rc = evtchn_bind_to_user(u, bind_interdomain.local_port);
if (rc == 0)
rc = bind_interdomain.local_port;
break;
}
case IOCTL_EVTCHN_BIND_UNBOUND_PORT: {
struct ioctl_evtchn_bind_unbound_port bind;
struct evtchn_alloc_unbound alloc_unbound;
rc = -EFAULT;
if (copy_from_user(&bind, uarg, sizeof(bind)))
break;
alloc_unbound.dom = DOMID_SELF;
alloc_unbound.remote_dom = bind.remote_domain;
rc = HYPERVISOR_event_channel_op(EVTCHNOP_alloc_unbound,
&alloc_unbound);
if (rc != 0)
break;
rc = evtchn_bind_to_user(u, alloc_unbound.port);
if (rc == 0)
rc = alloc_unbound.port;
break;
}
case IOCTL_EVTCHN_UNBIND: {
struct ioctl_evtchn_unbind unbind;
rc = -EFAULT;
if (copy_from_user(&unbind, uarg, sizeof(unbind)))
break;
rc = -EINVAL;
if (unbind.port >= NR_EVENT_CHANNELS)
break;
rc = -ENOTCONN;
if (get_port_user(unbind.port) != u)
break;
disable_irq(irq_from_evtchn(unbind.port));
evtchn_unbind_from_user(u, unbind.port);
rc = 0;
break;
}
case IOCTL_EVTCHN_NOTIFY: {
struct ioctl_evtchn_notify notify;
rc = -EFAULT;
if (copy_from_user(&notify, uarg, sizeof(notify)))
break;
if (notify.port >= NR_EVENT_CHANNELS) {
rc = -EINVAL;
} else if (get_port_user(notify.port) != u) {
rc = -ENOTCONN;
} else {
notify_remote_via_evtchn(notify.port);
rc = 0;
}
break;
}
case IOCTL_EVTCHN_RESET: {
mutex_lock(&u->ring_cons_mutex);
spin_lock_irq(&port_user_lock);
u->ring_cons = u->ring_prod = u->ring_overflow = 0;
spin_unlock_irq(&port_user_lock);
mutex_unlock(&u->ring_cons_mutex);
rc = 0;
break;
}
default:
rc = -ENOSYS;
break;
}
mutex_unlock(&u->bind_mutex);
return rc;
}
static unsigned int evtchn_poll(struct file *file, poll_table *wait)
{
unsigned int mask = POLLOUT | POLLWRNORM;
struct per_user_data *u = file->private_data;
poll_wait(file, &u->evtchn_wait, wait);
if (u->ring_cons != u->ring_prod)
mask |= POLLIN | POLLRDNORM;
if (u->ring_overflow)
mask = POLLERR;
return mask;
}
static int evtchn_fasync(int fd, struct file *filp, int on)
{
struct per_user_data *u = filp->private_data;
return fasync_helper(fd, filp, on, &u->evtchn_async_queue);
}
static int evtchn_open(struct inode *inode, struct file *filp)
{
struct per_user_data *u;
u = kzalloc(sizeof(*u), GFP_KERNEL);
if (u == NULL)
return -ENOMEM;
u->name = kasprintf(GFP_KERNEL, "evtchn:%s", current->comm);
if (u->name == NULL) {
kfree(u);
return -ENOMEM;
}
init_waitqueue_head(&u->evtchn_wait);
u->ring = (evtchn_port_t *)__get_free_page(GFP_KERNEL);
if (u->ring == NULL) {
kfree(u->name);
kfree(u);
return -ENOMEM;
}
mutex_init(&u->bind_mutex);
mutex_init(&u->ring_cons_mutex);
filp->private_data = u;
return nonseekable_open(inode, filp);
}
static int evtchn_release(struct inode *inode, struct file *filp)
{
int i;
struct per_user_data *u = filp->private_data;
for (i = 0; i < NR_EVENT_CHANNELS; i++) {
if (get_port_user(i) != u)
continue;
disable_irq(irq_from_evtchn(i));
evtchn_unbind_from_user(get_port_user(i), i);
}
free_page((unsigned long)u->ring);
kfree(u->name);
kfree(u);
return 0;
}
static int __init evtchn_init(void)
{
int err;
if (!xen_domain())
return -ENODEV;
port_user = kcalloc(NR_EVENT_CHANNELS, sizeof(*port_user), GFP_KERNEL);
if (port_user == NULL)
return -ENOMEM;
spin_lock_init(&port_user_lock);
err = misc_register(&evtchn_miscdev);
if (err != 0) {
pr_err("Could not register /dev/xen/evtchn\n");
return err;
}
pr_info("Event-channel device installed\n");
return 0;
}
static void __exit evtchn_cleanup(void)
{
kfree(port_user);
port_user = NULL;
misc_deregister(&evtchn_miscdev);
}
