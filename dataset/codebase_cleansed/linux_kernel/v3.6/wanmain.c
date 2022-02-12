static int __init wanrouter_init(void)
{
int err;
printk(KERN_INFO "%s v%u.%u %s\n",
wanrouter_fullname, ROUTER_VERSION, ROUTER_RELEASE,
wanrouter_copyright);
err = wanrouter_proc_init();
if (err)
printk(KERN_INFO "%s: can't create entry in proc filesystem!\n",
wanrouter_modname);
return err;
}
static void __exit wanrouter_cleanup (void)
{
wanrouter_proc_cleanup();
}
int register_wan_device(struct wan_device *wandev)
{
int err, namelen;
if ((wandev == NULL) || (wandev->magic != ROUTER_MAGIC) ||
(wandev->name == NULL))
return -EINVAL;
namelen = strlen(wandev->name);
if (!namelen || (namelen > WAN_DRVNAME_SZ))
return -EINVAL;
if (wanrouter_find_device(wandev->name))
return -EEXIST;
#ifdef WANDEBUG
printk(KERN_INFO "%s: registering WAN device %s\n",
wanrouter_modname, wandev->name);
#endif
err = wanrouter_proc_add(wandev);
if (err) {
printk(KERN_INFO
"%s: can't create /proc/net/router/%s entry!\n",
wanrouter_modname, wandev->name);
return err;
}
wandev->ndev = 0;
wandev->dev = NULL;
wandev->next = wanrouter_router_devlist;
wanrouter_router_devlist = wandev;
return 0;
}
int unregister_wan_device(char *name)
{
struct wan_device *wandev, *prev;
if (name == NULL)
return -EINVAL;
for (wandev = wanrouter_router_devlist, prev = NULL;
wandev && strcmp(wandev->name, name);
prev = wandev, wandev = wandev->next)
;
if (wandev == NULL)
return -ENODEV;
#ifdef WANDEBUG
printk(KERN_INFO "%s: unregistering WAN device %s\n",
wanrouter_modname, name);
#endif
if (wandev->state != WAN_UNCONFIGURED)
wanrouter_device_shutdown(wandev);
if (prev)
prev->next = wandev->next;
else
wanrouter_router_devlist = wandev->next;
wanrouter_proc_delete(wandev);
return 0;
}
long wanrouter_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct inode *inode = file->f_path.dentry->d_inode;
int err = 0;
struct proc_dir_entry *dent;
struct wan_device *wandev;
void __user *data = (void __user *)arg;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if ((cmd >> 8) != ROUTER_IOCTL)
return -EINVAL;
dent = PDE(inode);
if ((dent == NULL) || (dent->data == NULL))
return -EINVAL;
wandev = dent->data;
if (wandev->magic != ROUTER_MAGIC)
return -EINVAL;
mutex_lock(&wanrouter_mutex);
switch (cmd) {
case ROUTER_SETUP:
err = wanrouter_device_setup(wandev, data);
break;
case ROUTER_DOWN:
err = wanrouter_device_shutdown(wandev);
break;
case ROUTER_STAT:
err = wanrouter_device_stat(wandev, data);
break;
case ROUTER_IFNEW:
err = wanrouter_device_new_if(wandev, data);
break;
case ROUTER_IFDEL:
err = wanrouter_device_del_if(wandev, data);
break;
case ROUTER_IFSTAT:
break;
default:
if ((cmd >= ROUTER_USER) &&
(cmd <= ROUTER_USER_MAX) &&
wandev->ioctl)
err = wandev->ioctl(wandev, cmd, arg);
else err = -EINVAL;
}
mutex_unlock(&wanrouter_mutex);
return err;
}
static int wanrouter_device_setup(struct wan_device *wandev,
wandev_conf_t __user *u_conf)
{
void *data = NULL;
wandev_conf_t *conf;
int err = -EINVAL;
if (wandev->setup == NULL) {
printk(KERN_INFO "%s: ERROR, No setup script: wandev->setup()\n",
wandev->name);
return 0;
}
conf = kmalloc(sizeof(wandev_conf_t), GFP_KERNEL);
if (conf == NULL){
printk(KERN_INFO "%s: ERROR, Failed to allocate kernel memory !\n",
wandev->name);
return -ENOBUFS;
}
if (copy_from_user(conf, u_conf, sizeof(wandev_conf_t))) {
printk(KERN_INFO "%s: Failed to copy user config data to kernel space!\n",
wandev->name);
kfree(conf);
return -EFAULT;
}
if (conf->magic != ROUTER_MAGIC) {
kfree(conf);
printk(KERN_INFO "%s: ERROR, Invalid MAGIC Number\n",
wandev->name);
return -EINVAL;
}
if (conf->data_size && conf->data) {
if (conf->data_size > 128000) {
printk(KERN_INFO
"%s: ERROR, Invalid firmware data size %i !\n",
wandev->name, conf->data_size);
kfree(conf);
return -EINVAL;
}
data = vmalloc(conf->data_size);
if (!data) {
printk(KERN_INFO
"%s: ERROR, Failed allocate kernel memory !\n",
wandev->name);
kfree(conf);
return -ENOBUFS;
}
if (!copy_from_user(data, conf->data, conf->data_size)) {
conf->data = data;
err = wandev->setup(wandev, conf);
} else {
printk(KERN_INFO
"%s: ERROR, Failed to copy from user data !\n",
wandev->name);
err = -EFAULT;
}
vfree(data);
} else {
printk(KERN_INFO
"%s: ERROR, No firmware found ! Firmware size = %i !\n",
wandev->name, conf->data_size);
}
kfree(conf);
return err;
}
static int wanrouter_device_shutdown(struct wan_device *wandev)
{
struct net_device *dev;
int err=0;
if (wandev->state == WAN_UNCONFIGURED)
return 0;
printk(KERN_INFO "\n%s: Shutting Down!\n",wandev->name);
for (dev = wandev->dev; dev;) {
err = wanrouter_delete_interface(wandev, dev->name);
if (err)
return err;
dev = wandev->dev;
}
if (wandev->ndev)
return -EBUSY;
if (wandev->shutdown)
err=wandev->shutdown(wandev);
return err;
}
static int wanrouter_device_stat(struct wan_device *wandev,
wandev_stat_t __user *u_stat)
{
wandev_stat_t stat;
memset(&stat, 0, sizeof(stat));
if ((wandev->state != WAN_UNCONFIGURED) && wandev->update)
wandev->update(wandev);
stat.ndev = wandev->ndev;
stat.state = wandev->state;
if (copy_to_user(u_stat, &stat, sizeof(stat)))
return -EFAULT;
return 0;
}
static int wanrouter_device_new_if(struct wan_device *wandev,
wanif_conf_t __user *u_conf)
{
wanif_conf_t *cnf;
struct net_device *dev = NULL;
int err;
if ((wandev->state == WAN_UNCONFIGURED) || (wandev->new_if == NULL))
return -ENODEV;
cnf = kmalloc(sizeof(wanif_conf_t), GFP_KERNEL);
if (!cnf)
return -ENOBUFS;
err = -EFAULT;
if (copy_from_user(cnf, u_conf, sizeof(wanif_conf_t)))
goto out;
err = -EINVAL;
if (cnf->magic != ROUTER_MAGIC)
goto out;
if (cnf->config_id == WANCONFIG_MPPP) {
printk(KERN_INFO "%s: Wanpipe Mulit-Port PPP support has not been compiled in!\n",
wandev->name);
err = -EPROTONOSUPPORT;
goto out;
} else {
err = wandev->new_if(wandev, dev, cnf);
}
if (!err) {
#ifdef WANDEBUG
printk(KERN_INFO "%s: registering interface %s...\n",
wanrouter_modname, dev->name);
#endif
err = register_netdev(dev);
if (!err) {
struct net_device *slave = NULL;
unsigned long smp_flags=0;
lock_adapter_irq(&wandev->lock, &smp_flags);
if (wandev->dev == NULL) {
wandev->dev = dev;
} else {
for (slave=wandev->dev;
DEV_TO_SLAVE(slave);
slave = DEV_TO_SLAVE(slave))
DEV_TO_SLAVE(slave) = dev;
}
++wandev->ndev;
unlock_adapter_irq(&wandev->lock, &smp_flags);
err = 0;
goto out;
}
if (wandev->del_if)
wandev->del_if(wandev, dev);
free_netdev(dev);
}
out:
kfree(cnf);
return err;
}
static int wanrouter_device_del_if(struct wan_device *wandev, char __user *u_name)
{
char name[WAN_IFNAME_SZ + 1];
int err = 0;
if (wandev->state == WAN_UNCONFIGURED)
return -ENODEV;
memset(name, 0, sizeof(name));
if (copy_from_user(name, u_name, WAN_IFNAME_SZ))
return -EFAULT;
err = wanrouter_delete_interface(wandev, name);
if (err)
return err;
if (!wandev->ndev && wandev->shutdown)
err = wandev->shutdown(wandev);
return err;
}
static struct wan_device *wanrouter_find_device(char *name)
{
struct wan_device *wandev;
for (wandev = wanrouter_router_devlist;
wandev && strcmp(wandev->name, name);
wandev = wandev->next);
return wandev;
}
static int wanrouter_delete_interface(struct wan_device *wandev, char *name)
{
struct net_device *dev = NULL, *prev = NULL;
unsigned long smp_flags=0;
lock_adapter_irq(&wandev->lock, &smp_flags);
dev = wandev->dev;
prev = NULL;
while (dev && strcmp(name, dev->name)) {
struct net_device **slave = netdev_priv(dev);
prev = dev;
dev = *slave;
}
unlock_adapter_irq(&wandev->lock, &smp_flags);
if (dev == NULL)
return -ENODEV;
if (netif_running(dev))
return -EBUSY;
if (wandev->del_if)
wandev->del_if(wandev, dev);
lock_adapter_irq(&wandev->lock, &smp_flags);
if (prev) {
struct net_device **prev_slave = netdev_priv(prev);
struct net_device **slave = netdev_priv(dev);
*prev_slave = *slave;
} else {
struct net_device **slave = netdev_priv(dev);
wandev->dev = *slave;
}
--wandev->ndev;
unlock_adapter_irq(&wandev->lock, &smp_flags);
printk(KERN_INFO "%s: unregistering '%s'\n", wandev->name, dev->name);
unregister_netdev(dev);
free_netdev(dev);
return 0;
}
static void lock_adapter_irq(spinlock_t *lock, unsigned long *smp_flags)
__acquires(lock)
{
spin_lock_irqsave(lock, *smp_flags);
}
static void unlock_adapter_irq(spinlock_t *lock, unsigned long *smp_flags)
__releases(lock)
{
spin_unlock_irqrestore(lock, *smp_flags);
}
