static evtchn_port_t *evtchn_alloc_ring(unsigned int size)
{
evtchn_port_t *ring;
size_t s = size * sizeof(*ring);
ring = kmalloc(s, GFP_KERNEL);
if (!ring)
ring = vmalloc(s);
return ring;
}
static void evtchn_free_ring(evtchn_port_t *ring)
{
kvfree(ring);
}
static unsigned int evtchn_ring_offset(struct per_user_data *u,
unsigned int idx)
{
return idx & (u->ring_size - 1);
}
static evtchn_port_t *evtchn_ring_entry(struct per_user_data *u,
unsigned int idx)
{
return u->ring + evtchn_ring_offset(u, idx);
}
static int add_evtchn(struct per_user_data *u, struct user_evtchn *evtchn)
{
struct rb_node **new = &(u->evtchns.rb_node), *parent = NULL;
u->nr_evtchns++;
while (*new) {
struct user_evtchn *this;
this = container_of(*new, struct user_evtchn, node);
parent = *new;
if (this->port < evtchn->port)
new = &((*new)->rb_left);
else if (this->port > evtchn->port)
new = &((*new)->rb_right);
else
return -EEXIST;
}
rb_link_node(&evtchn->node, parent, new);
rb_insert_color(&evtchn->node, &u->evtchns);
return 0;
}
static void del_evtchn(struct per_user_data *u, struct user_evtchn *evtchn)
{
u->nr_evtchns--;
rb_erase(&evtchn->node, &u->evtchns);
kfree(evtchn);
}
static struct user_evtchn *find_evtchn(struct per_user_data *u, unsigned port)
{
struct rb_node *node = u->evtchns.rb_node;
while (node) {
struct user_evtchn *evtchn;
evtchn = container_of(node, struct user_evtchn, node);
if (evtchn->port < port)
node = node->rb_left;
else if (evtchn->port > port)
node = node->rb_right;
else
return evtchn;
}
return NULL;
}
static irqreturn_t evtchn_interrupt(int irq, void *data)
{
struct user_evtchn *evtchn = data;
struct per_user_data *u = evtchn->user;
WARN(!evtchn->enabled,
"Interrupt for port %d, but apparently not enabled; per-user %p\n",
evtchn->port, u);
disable_irq_nosync(irq);
evtchn->enabled = false;
spin_lock(&u->ring_prod_lock);
if ((u->ring_prod - u->ring_cons) < u->ring_size) {
*evtchn_ring_entry(u, u->ring_prod) = evtchn->port;
wmb();
if (u->ring_cons == u->ring_prod++) {
wake_up_interruptible(&u->evtchn_wait);
kill_fasync(&u->evtchn_async_queue,
SIGIO, POLL_IN);
}
} else
u->ring_overflow = 1;
spin_unlock(&u->ring_prod_lock);
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
if (((c ^ p) & u->ring_size) != 0) {
bytes1 = (u->ring_size - evtchn_ring_offset(u, c)) *
sizeof(evtchn_port_t);
bytes2 = evtchn_ring_offset(u, p) * sizeof(evtchn_port_t);
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
if (copy_to_user(buf, evtchn_ring_entry(u, c), bytes1) ||
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
mutex_lock(&u->bind_mutex);
for (i = 0; i < (count/sizeof(evtchn_port_t)); i++) {
unsigned port = kbuf[i];
struct user_evtchn *evtchn;
evtchn = find_evtchn(u, port);
if (evtchn && !evtchn->enabled) {
evtchn->enabled = true;
enable_irq(irq_from_evtchn(port));
}
}
mutex_unlock(&u->bind_mutex);
rc = count;
out:
free_page((unsigned long)kbuf);
return rc;
}
static int evtchn_resize_ring(struct per_user_data *u)
{
unsigned int new_size;
evtchn_port_t *new_ring, *old_ring;
if (u->nr_evtchns <= u->ring_size)
return 0;
if (u->ring_size == 0)
new_size = 64;
else
new_size = 2 * u->ring_size;
new_ring = evtchn_alloc_ring(new_size);
if (!new_ring)
return -ENOMEM;
old_ring = u->ring;
mutex_lock(&u->ring_cons_mutex);
spin_lock_irq(&u->ring_prod_lock);
memcpy(new_ring, old_ring, u->ring_size * sizeof(*u->ring));
memcpy(new_ring + u->ring_size, old_ring,
u->ring_size * sizeof(*u->ring));
u->ring = new_ring;
u->ring_size = new_size;
spin_unlock_irq(&u->ring_prod_lock);
mutex_unlock(&u->ring_cons_mutex);
evtchn_free_ring(old_ring);
return 0;
}
static int evtchn_bind_to_user(struct per_user_data *u, int port)
{
struct user_evtchn *evtchn;
struct evtchn_close close;
int rc = 0;
evtchn = kzalloc(sizeof(*evtchn), GFP_KERNEL);
if (!evtchn)
return -ENOMEM;
evtchn->user = u;
evtchn->port = port;
evtchn->enabled = true;
rc = add_evtchn(u, evtchn);
if (rc < 0)
goto err;
rc = evtchn_resize_ring(u);
if (rc < 0)
goto err;
rc = bind_evtchn_to_irqhandler(port, evtchn_interrupt, 0,
u->name, evtchn);
if (rc < 0)
goto err;
rc = evtchn_make_refcounted(port);
return rc;
err:
close.port = port;
if (HYPERVISOR_event_channel_op(EVTCHNOP_close, &close) != 0)
BUG();
del_evtchn(u, evtchn);
return rc;
}
static void evtchn_unbind_from_user(struct per_user_data *u,
struct user_evtchn *evtchn)
{
int irq = irq_from_evtchn(evtchn->port);
BUG_ON(irq < 0);
unbind_from_irqhandler(irq, evtchn);
del_evtchn(u, evtchn);
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
struct user_evtchn *evtchn;
rc = -EFAULT;
if (copy_from_user(&unbind, uarg, sizeof(unbind)))
break;
rc = -EINVAL;
if (unbind.port >= xen_evtchn_nr_channels())
break;
rc = -ENOTCONN;
evtchn = find_evtchn(u, unbind.port);
if (!evtchn)
break;
disable_irq(irq_from_evtchn(unbind.port));
evtchn_unbind_from_user(u, evtchn);
rc = 0;
break;
}
case IOCTL_EVTCHN_NOTIFY: {
struct ioctl_evtchn_notify notify;
struct user_evtchn *evtchn;
rc = -EFAULT;
if (copy_from_user(&notify, uarg, sizeof(notify)))
break;
rc = -ENOTCONN;
evtchn = find_evtchn(u, notify.port);
if (evtchn) {
notify_remote_via_evtchn(notify.port);
rc = 0;
}
break;
}
case IOCTL_EVTCHN_RESET: {
mutex_lock(&u->ring_cons_mutex);
spin_lock_irq(&u->ring_prod_lock);
u->ring_cons = u->ring_prod = u->ring_overflow = 0;
spin_unlock_irq(&u->ring_prod_lock);
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
mutex_init(&u->bind_mutex);
mutex_init(&u->ring_cons_mutex);
spin_lock_init(&u->ring_prod_lock);
filp->private_data = u;
return nonseekable_open(inode, filp);
}
static int evtchn_release(struct inode *inode, struct file *filp)
{
struct per_user_data *u = filp->private_data;
struct rb_node *node;
while ((node = u->evtchns.rb_node)) {
struct user_evtchn *evtchn;
evtchn = rb_entry(node, struct user_evtchn, node);
disable_irq(irq_from_evtchn(evtchn->port));
evtchn_unbind_from_user(u, evtchn);
}
evtchn_free_ring(u->ring);
kfree(u->name);
kfree(u);
return 0;
}
static int __init evtchn_init(void)
{
int err;
if (!xen_domain())
return -ENODEV;
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
misc_deregister(&evtchn_miscdev);
}
