static void dead_write_lines(struct parport *p, unsigned char b){}
static unsigned char dead_read_lines(struct parport *p) { return 0; }
static unsigned char dead_frob_lines(struct parport *p, unsigned char b,
unsigned char c) { return 0; }
static void dead_onearg(struct parport *p){}
static void dead_initstate(struct pardevice *d, struct parport_state *s) { }
static void dead_state(struct parport *p, struct parport_state *s) { }
static size_t dead_write(struct parport *p, const void *b, size_t l, int f)
{ return 0; }
static size_t dead_read(struct parport *p, void *b, size_t l, int f)
{ return 0; }
static int is_parport(struct device *dev)
{
return dev->type == &parport_device_type;
}
static int parport_probe(struct device *dev)
{
struct parport_driver *drv;
if (is_parport(dev))
return -ENODEV;
drv = to_parport_driver(dev->driver);
if (!drv->probe) {
struct pardevice *par_dev = to_pardevice(dev);
if (strcmp(par_dev->name, drv->name))
return -ENODEV;
return 0;
}
return drv->probe(to_pardevice(dev));
}
int parport_bus_init(void)
{
return bus_register(&parport_bus_type);
}
void parport_bus_exit(void)
{
bus_unregister(&parport_bus_type);
}
static int driver_check(struct device_driver *dev_drv, void *_port)
{
struct parport *port = _port;
struct parport_driver *drv = to_parport_driver(dev_drv);
if (drv->match_port)
drv->match_port(port);
return 0;
}
static void attach_driver_chain(struct parport *port)
{
struct parport_driver *drv;
list_for_each_entry(drv, &drivers, list)
drv->attach(port);
bus_for_each_drv(&parport_bus_type, NULL, port, driver_check);
}
static int driver_detach(struct device_driver *_drv, void *_port)
{
struct parport *port = _port;
struct parport_driver *drv = to_parport_driver(_drv);
if (drv->detach)
drv->detach(port);
return 0;
}
static void detach_driver_chain(struct parport *port)
{
struct parport_driver *drv;
list_for_each_entry(drv, &drivers, list)
drv->detach(port);
bus_for_each_drv(&parport_bus_type, NULL, port, driver_detach);
}
static void get_lowlevel_driver(void)
{
request_module("parport_lowlevel");
}
static int port_check(struct device *dev, void *dev_drv)
{
struct parport_driver *drv = dev_drv;
if (is_parport(dev))
drv->match_port(to_parport_dev(dev));
return 0;
}
int __parport_register_driver(struct parport_driver *drv, struct module *owner,
const char *mod_name)
{
if (list_empty(&portlist))
get_lowlevel_driver();
if (drv->devmodel) {
int ret;
drv->driver.name = drv->name;
drv->driver.bus = &parport_bus_type;
drv->driver.owner = owner;
drv->driver.mod_name = mod_name;
ret = driver_register(&drv->driver);
if (ret)
return ret;
mutex_lock(&registration_lock);
if (drv->match_port)
bus_for_each_dev(&parport_bus_type, NULL, drv,
port_check);
mutex_unlock(&registration_lock);
} else {
struct parport *port;
drv->devmodel = false;
mutex_lock(&registration_lock);
list_for_each_entry(port, &portlist, list)
drv->attach(port);
list_add(&drv->list, &drivers);
mutex_unlock(&registration_lock);
}
return 0;
}
static int port_detach(struct device *dev, void *_drv)
{
struct parport_driver *drv = _drv;
if (is_parport(dev) && drv->detach)
drv->detach(to_parport_dev(dev));
return 0;
}
void parport_unregister_driver(struct parport_driver *drv)
{
struct parport *port;
mutex_lock(&registration_lock);
if (drv->devmodel) {
bus_for_each_dev(&parport_bus_type, NULL, drv, port_detach);
driver_unregister(&drv->driver);
} else {
list_del_init(&drv->list);
list_for_each_entry(port, &portlist, list)
drv->detach(port);
}
mutex_unlock(&registration_lock);
}
static void free_port(struct device *dev)
{
int d;
struct parport *port = to_parport_dev(dev);
spin_lock(&full_list_lock);
list_del(&port->full_list);
spin_unlock(&full_list_lock);
for (d = 0; d < 5; d++) {
kfree(port->probe_info[d].class_name);
kfree(port->probe_info[d].mfr);
kfree(port->probe_info[d].model);
kfree(port->probe_info[d].cmdset);
kfree(port->probe_info[d].description);
}
kfree(port->name);
kfree(port);
}
struct parport *parport_get_port(struct parport *port)
{
struct device *dev = get_device(&port->bus_dev);
return to_parport_dev(dev);
}
void parport_del_port(struct parport *port)
{
device_unregister(&port->bus_dev);
}
void parport_put_port(struct parport *port)
{
put_device(&port->bus_dev);
}
struct parport *parport_register_port(unsigned long base, int irq, int dma,
struct parport_operations *ops)
{
struct list_head *l;
struct parport *tmp;
int num;
int device;
char *name;
int ret;
tmp = kzalloc(sizeof(struct parport), GFP_KERNEL);
if (!tmp)
return NULL;
tmp->base = base;
tmp->irq = irq;
tmp->dma = dma;
tmp->muxport = tmp->daisy = tmp->muxsel = -1;
tmp->modes = 0;
INIT_LIST_HEAD(&tmp->list);
tmp->devices = tmp->cad = NULL;
tmp->flags = 0;
tmp->ops = ops;
tmp->physport = tmp;
memset(tmp->probe_info, 0, 5 * sizeof(struct parport_device_info));
rwlock_init(&tmp->cad_lock);
spin_lock_init(&tmp->waitlist_lock);
spin_lock_init(&tmp->pardevice_lock);
tmp->ieee1284.mode = IEEE1284_MODE_COMPAT;
tmp->ieee1284.phase = IEEE1284_PH_FWD_IDLE;
sema_init(&tmp->ieee1284.irq, 0);
tmp->spintime = parport_default_spintime;
atomic_set(&tmp->ref_count, 1);
INIT_LIST_HEAD(&tmp->full_list);
name = kmalloc(15, GFP_KERNEL);
if (!name) {
kfree(tmp);
return NULL;
}
spin_lock(&full_list_lock);
for (l = all_ports.next, num = 0; l != &all_ports; l = l->next, num++) {
struct parport *p = list_entry(l, struct parport, full_list);
if (p->number != num)
break;
}
tmp->portnum = tmp->number = num;
list_add_tail(&tmp->full_list, l);
spin_unlock(&full_list_lock);
sprintf(name, "parport%d", tmp->portnum = tmp->number);
tmp->name = name;
tmp->bus_dev.bus = &parport_bus_type;
tmp->bus_dev.release = free_port;
dev_set_name(&tmp->bus_dev, name);
tmp->bus_dev.type = &parport_device_type;
for (device = 0; device < 5; device++)
tmp->probe_info[device].class = PARPORT_CLASS_LEGACY;
tmp->waithead = tmp->waittail = NULL;
ret = device_register(&tmp->bus_dev);
if (ret) {
put_device(&tmp->bus_dev);
return NULL;
}
return tmp;
}
void parport_announce_port(struct parport *port)
{
int i;
#ifdef CONFIG_PARPORT_1284
parport_daisy_init(port);
#endif
if (!port->dev)
printk(KERN_WARNING "%s: fix this legacy no-device port driver!\n",
port->name);
parport_proc_register(port);
mutex_lock(&registration_lock);
spin_lock_irq(&parportlist_lock);
list_add_tail(&port->list, &portlist);
for (i = 1; i < 3; i++) {
struct parport *slave = port->slaves[i-1];
if (slave)
list_add_tail(&slave->list, &portlist);
}
spin_unlock_irq(&parportlist_lock);
attach_driver_chain(port);
for (i = 1; i < 3; i++) {
struct parport *slave = port->slaves[i-1];
if (slave)
attach_driver_chain(slave);
}
mutex_unlock(&registration_lock);
}
void parport_remove_port(struct parport *port)
{
int i;
mutex_lock(&registration_lock);
detach_driver_chain(port);
#ifdef CONFIG_PARPORT_1284
parport_daisy_fini(port);
for (i = 1; i < 3; i++) {
struct parport *slave = port->slaves[i-1];
if (!slave)
continue;
detach_driver_chain(slave);
parport_daisy_fini(slave);
}
#endif
port->ops = &dead_ops;
spin_lock(&parportlist_lock);
list_del_init(&port->list);
for (i = 1; i < 3; i++) {
struct parport *slave = port->slaves[i-1];
if (slave)
list_del_init(&slave->list);
}
spin_unlock(&parportlist_lock);
mutex_unlock(&registration_lock);
parport_proc_unregister(port);
for (i = 1; i < 3; i++) {
struct parport *slave = port->slaves[i-1];
if (slave)
parport_put_port(slave);
}
}
struct pardevice *
parport_register_device(struct parport *port, const char *name,
int (*pf)(void *), void (*kf)(void *),
void (*irq_func)(void *),
int flags, void *handle)
{
struct pardevice *tmp;
if (port->physport->flags & PARPORT_FLAG_EXCL) {
printk(KERN_DEBUG "%s: no more devices allowed\n",
port->name);
return NULL;
}
if (flags & PARPORT_DEV_LURK) {
if (!pf || !kf) {
printk(KERN_INFO "%s: refused to register lurking device (%s) without callbacks\n", port->name, name);
return NULL;
}
}
if (flags & PARPORT_DEV_EXCL) {
if (port->physport->devices) {
pr_err("%s: cannot grant exclusive access for device %s\n",
port->name, name);
return NULL;
}
}
if (!try_module_get(port->ops->owner))
return NULL;
parport_get_port(port);
tmp = kmalloc(sizeof(struct pardevice), GFP_KERNEL);
if (!tmp)
goto out;
tmp->state = kmalloc(sizeof(struct parport_state), GFP_KERNEL);
if (!tmp->state)
goto out_free_pardevice;
tmp->name = name;
tmp->port = port;
tmp->daisy = -1;
tmp->preempt = pf;
tmp->wakeup = kf;
tmp->private = handle;
tmp->flags = flags;
tmp->irq_func = irq_func;
tmp->waiting = 0;
tmp->timeout = 5 * HZ;
tmp->devmodel = false;
tmp->prev = NULL;
spin_lock(&port->physport->pardevice_lock);
if (flags & PARPORT_DEV_EXCL) {
if (port->physport->devices) {
spin_unlock(&port->physport->pardevice_lock);
printk(KERN_DEBUG
"%s: cannot grant exclusive access for device %s\n",
port->name, name);
goto out_free_all;
}
port->flags |= PARPORT_FLAG_EXCL;
}
tmp->next = port->physport->devices;
wmb();
if (port->physport->devices)
port->physport->devices->prev = tmp;
port->physport->devices = tmp;
spin_unlock(&port->physport->pardevice_lock);
init_waitqueue_head(&tmp->wait_q);
tmp->timeslice = parport_default_timeslice;
tmp->waitnext = tmp->waitprev = NULL;
port->ops->init_state(tmp, tmp->state);
if (!test_and_set_bit(PARPORT_DEVPROC_REGISTERED, &port->devflags)) {
port->proc_device = tmp;
parport_device_proc_register(tmp);
}
return tmp;
out_free_all:
kfree(tmp->state);
out_free_pardevice:
kfree(tmp);
out:
parport_put_port(port);
module_put(port->ops->owner);
return NULL;
}
static void free_pardevice(struct device *dev)
{
struct pardevice *par_dev = to_pardevice(dev);
kfree(par_dev->name);
kfree(par_dev);
}
struct pardevice *
parport_register_dev_model(struct parport *port, const char *name,
const struct pardev_cb *par_dev_cb, int id)
{
struct pardevice *par_dev;
int ret;
char *devname;
if (port->physport->flags & PARPORT_FLAG_EXCL) {
pr_err("%s: no more devices allowed\n", port->name);
return NULL;
}
if (par_dev_cb->flags & PARPORT_DEV_LURK) {
if (!par_dev_cb->preempt || !par_dev_cb->wakeup) {
pr_info("%s: refused to register lurking device (%s) without callbacks\n",
port->name, name);
return NULL;
}
}
if (par_dev_cb->flags & PARPORT_DEV_EXCL) {
if (port->physport->devices) {
pr_err("%s: cannot grant exclusive access for device %s\n",
port->name, name);
return NULL;
}
}
if (!try_module_get(port->ops->owner))
return NULL;
parport_get_port(port);
par_dev = kzalloc(sizeof(*par_dev), GFP_KERNEL);
if (!par_dev)
goto err_put_port;
par_dev->state = kzalloc(sizeof(*par_dev->state), GFP_KERNEL);
if (!par_dev->state)
goto err_put_par_dev;
devname = kstrdup(name, GFP_KERNEL);
if (!devname)
goto err_free_par_dev;
par_dev->name = devname;
par_dev->port = port;
par_dev->daisy = -1;
par_dev->preempt = par_dev_cb->preempt;
par_dev->wakeup = par_dev_cb->wakeup;
par_dev->private = par_dev_cb->private;
par_dev->flags = par_dev_cb->flags;
par_dev->irq_func = par_dev_cb->irq_func;
par_dev->waiting = 0;
par_dev->timeout = 5 * HZ;
par_dev->dev.parent = &port->bus_dev;
par_dev->dev.bus = &parport_bus_type;
ret = dev_set_name(&par_dev->dev, "%s.%d", devname, id);
if (ret)
goto err_free_devname;
par_dev->dev.release = free_pardevice;
par_dev->devmodel = true;
ret = device_register(&par_dev->dev);
if (ret) {
put_device(&par_dev->dev);
goto err_put_port;
}
par_dev->prev = NULL;
spin_lock(&port->physport->pardevice_lock);
if (par_dev_cb->flags & PARPORT_DEV_EXCL) {
if (port->physport->devices) {
spin_unlock(&port->physport->pardevice_lock);
pr_debug("%s: cannot grant exclusive access for device %s\n",
port->name, name);
device_unregister(&par_dev->dev);
goto err_put_port;
}
port->flags |= PARPORT_FLAG_EXCL;
}
par_dev->next = port->physport->devices;
wmb();
if (port->physport->devices)
port->physport->devices->prev = par_dev;
port->physport->devices = par_dev;
spin_unlock(&port->physport->pardevice_lock);
init_waitqueue_head(&par_dev->wait_q);
par_dev->timeslice = parport_default_timeslice;
par_dev->waitnext = NULL;
par_dev->waitprev = NULL;
port->ops->init_state(par_dev, par_dev->state);
if (!test_and_set_bit(PARPORT_DEVPROC_REGISTERED, &port->devflags)) {
port->proc_device = par_dev;
parport_device_proc_register(par_dev);
}
return par_dev;
err_free_devname:
kfree(devname);
err_free_par_dev:
kfree(par_dev->state);
err_put_par_dev:
if (!par_dev->devmodel)
kfree(par_dev);
err_put_port:
parport_put_port(port);
module_put(port->ops->owner);
return NULL;
}
void parport_unregister_device(struct pardevice *dev)
{
struct parport *port;
#ifdef PARPORT_PARANOID
if (!dev) {
printk(KERN_ERR "parport_unregister_device: passed NULL\n");
return;
}
#endif
port = dev->port->physport;
if (port->proc_device == dev) {
port->proc_device = NULL;
clear_bit(PARPORT_DEVPROC_REGISTERED, &port->devflags);
parport_device_proc_unregister(dev);
}
if (port->cad == dev) {
printk(KERN_DEBUG "%s: %s forgot to release port\n",
port->name, dev->name);
parport_release(dev);
}
spin_lock(&port->pardevice_lock);
if (dev->next)
dev->next->prev = dev->prev;
if (dev->prev)
dev->prev->next = dev->next;
else
port->devices = dev->next;
if (dev->flags & PARPORT_DEV_EXCL)
port->flags &= ~PARPORT_FLAG_EXCL;
spin_unlock(&port->pardevice_lock);
spin_lock_irq(&port->waitlist_lock);
if (dev->waitprev || dev->waitnext || port->waithead == dev) {
if (dev->waitprev)
dev->waitprev->waitnext = dev->waitnext;
else
port->waithead = dev->waitnext;
if (dev->waitnext)
dev->waitnext->waitprev = dev->waitprev;
else
port->waittail = dev->waitprev;
}
spin_unlock_irq(&port->waitlist_lock);
kfree(dev->state);
if (dev->devmodel)
device_unregister(&dev->dev);
else
kfree(dev);
module_put(port->ops->owner);
parport_put_port(port);
}
struct parport *parport_find_number(int number)
{
struct parport *port, *result = NULL;
if (list_empty(&portlist))
get_lowlevel_driver();
spin_lock(&parportlist_lock);
list_for_each_entry(port, &portlist, list) {
if (port->number == number) {
result = parport_get_port(port);
break;
}
}
spin_unlock(&parportlist_lock);
return result;
}
struct parport *parport_find_base(unsigned long base)
{
struct parport *port, *result = NULL;
if (list_empty(&portlist))
get_lowlevel_driver();
spin_lock(&parportlist_lock);
list_for_each_entry(port, &portlist, list) {
if (port->base == base) {
result = parport_get_port(port);
break;
}
}
spin_unlock(&parportlist_lock);
return result;
}
int parport_claim(struct pardevice *dev)
{
struct pardevice *oldcad;
struct parport *port = dev->port->physport;
unsigned long flags;
if (port->cad == dev) {
printk(KERN_INFO "%s: %s already owner\n",
dev->port->name,dev->name);
return 0;
}
write_lock_irqsave(&port->cad_lock, flags);
oldcad = port->cad;
if (oldcad) {
if (oldcad->preempt) {
if (oldcad->preempt(oldcad->private))
goto blocked;
port->ops->save_state(port, dev->state);
} else
goto blocked;
if (port->cad != oldcad) {
printk(KERN_WARNING
"%s: %s released port when preempted!\n",
port->name, oldcad->name);
if (port->cad)
goto blocked;
}
}
if (dev->waiting & 1) {
dev->waiting = 0;
spin_lock_irq(&port->waitlist_lock);
if (dev->waitprev)
dev->waitprev->waitnext = dev->waitnext;
else
port->waithead = dev->waitnext;
if (dev->waitnext)
dev->waitnext->waitprev = dev->waitprev;
else
port->waittail = dev->waitprev;
spin_unlock_irq(&port->waitlist_lock);
dev->waitprev = dev->waitnext = NULL;
}
port->cad = dev;
#ifdef CONFIG_PARPORT_1284
if (dev->port->muxport >= 0) {
port->muxsel = dev->port->muxport;
}
if (dev->daisy >= 0) {
if (!parport_daisy_select(port, dev->daisy,
IEEE1284_MODE_COMPAT))
port->daisy = dev->daisy;
}
#endif
port->ops->restore_state(port, dev->state);
write_unlock_irqrestore(&port->cad_lock, flags);
dev->time = jiffies;
return 0;
blocked:
if (dev->waiting & 2 || dev->wakeup) {
spin_lock(&port->waitlist_lock);
if (test_and_set_bit(0, &dev->waiting) == 0) {
dev->waitnext = NULL;
dev->waitprev = port->waittail;
if (port->waittail) {
port->waittail->waitnext = dev;
port->waittail = dev;
} else
port->waithead = port->waittail = dev;
}
spin_unlock(&port->waitlist_lock);
}
write_unlock_irqrestore(&port->cad_lock, flags);
return -EAGAIN;
}
int parport_claim_or_block(struct pardevice *dev)
{
int r;
dev->waiting = 2;
r = parport_claim(dev);
if (r == -EAGAIN) {
#ifdef PARPORT_DEBUG_SHARING
printk(KERN_DEBUG "%s: parport_claim() returned -EAGAIN\n", dev->name);
#endif
if (dev->waiting) {
wait_event_interruptible(dev->wait_q,
!dev->waiting);
if (signal_pending(current))
return -EINTR;
r = 1;
} else {
r = 0;
#ifdef PARPORT_DEBUG_SHARING
printk(KERN_DEBUG "%s: didn't sleep in parport_claim_or_block()\n",
dev->name);
#endif
}
#ifdef PARPORT_DEBUG_SHARING
if (dev->port->physport->cad != dev)
printk(KERN_DEBUG "%s: exiting parport_claim_or_block but %s owns port!\n",
dev->name, dev->port->physport->cad ?
dev->port->physport->cad->name:"nobody");
#endif
}
dev->waiting = 0;
return r;
}
void parport_release(struct pardevice *dev)
{
struct parport *port = dev->port->physport;
struct pardevice *pd;
unsigned long flags;
write_lock_irqsave(&port->cad_lock, flags);
if (port->cad != dev) {
write_unlock_irqrestore(&port->cad_lock, flags);
printk(KERN_WARNING "%s: %s tried to release parport when not owner\n",
port->name, dev->name);
return;
}
#ifdef CONFIG_PARPORT_1284
if (dev->port->muxport >= 0) {
port->muxsel = -1;
}
if (dev->daisy >= 0) {
parport_daisy_deselect_all(port);
port->daisy = -1;
}
#endif
port->cad = NULL;
write_unlock_irqrestore(&port->cad_lock, flags);
port->ops->save_state(port, dev->state);
for (pd = port->waithead; pd; pd = pd->waitnext) {
if (pd->waiting & 2) {
parport_claim(pd);
if (waitqueue_active(&pd->wait_q))
wake_up_interruptible(&pd->wait_q);
return;
} else if (pd->wakeup) {
pd->wakeup(pd->private);
if (dev->port->cad)
return;
} else {
printk(KERN_ERR "%s: don't know how to wake %s\n", port->name, pd->name);
}
}
for (pd = port->devices; !port->cad && pd; pd = pd->next) {
if (pd->wakeup && pd != dev)
pd->wakeup(pd->private);
}
}
irqreturn_t parport_irq_handler(int irq, void *dev_id)
{
struct parport *port = dev_id;
parport_generic_irq(port);
return IRQ_HANDLED;
}
