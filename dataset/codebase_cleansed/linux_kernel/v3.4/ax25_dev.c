ax25_dev *ax25_addr_ax25dev(ax25_address *addr)
{
ax25_dev *ax25_dev, *res = NULL;
spin_lock_bh(&ax25_dev_lock);
for (ax25_dev = ax25_dev_list; ax25_dev != NULL; ax25_dev = ax25_dev->next)
if (ax25cmp(addr, (ax25_address *)ax25_dev->dev->dev_addr) == 0) {
res = ax25_dev;
}
spin_unlock_bh(&ax25_dev_lock);
return res;
}
void ax25_dev_device_up(struct net_device *dev)
{
ax25_dev *ax25_dev;
if ((ax25_dev = kzalloc(sizeof(*ax25_dev), GFP_ATOMIC)) == NULL) {
printk(KERN_ERR "AX.25: ax25_dev_device_up - out of memory\n");
return;
}
ax25_unregister_sysctl();
dev->ax25_ptr = ax25_dev;
ax25_dev->dev = dev;
dev_hold(dev);
ax25_dev->forward = NULL;
ax25_dev->values[AX25_VALUES_IPDEFMODE] = AX25_DEF_IPDEFMODE;
ax25_dev->values[AX25_VALUES_AXDEFMODE] = AX25_DEF_AXDEFMODE;
ax25_dev->values[AX25_VALUES_BACKOFF] = AX25_DEF_BACKOFF;
ax25_dev->values[AX25_VALUES_CONMODE] = AX25_DEF_CONMODE;
ax25_dev->values[AX25_VALUES_WINDOW] = AX25_DEF_WINDOW;
ax25_dev->values[AX25_VALUES_EWINDOW] = AX25_DEF_EWINDOW;
ax25_dev->values[AX25_VALUES_T1] = AX25_DEF_T1;
ax25_dev->values[AX25_VALUES_T2] = AX25_DEF_T2;
ax25_dev->values[AX25_VALUES_T3] = AX25_DEF_T3;
ax25_dev->values[AX25_VALUES_IDLE] = AX25_DEF_IDLE;
ax25_dev->values[AX25_VALUES_N2] = AX25_DEF_N2;
ax25_dev->values[AX25_VALUES_PACLEN] = AX25_DEF_PACLEN;
ax25_dev->values[AX25_VALUES_PROTOCOL] = AX25_DEF_PROTOCOL;
ax25_dev->values[AX25_VALUES_DS_TIMEOUT]= AX25_DEF_DS_TIMEOUT;
#if defined(CONFIG_AX25_DAMA_SLAVE) || defined(CONFIG_AX25_DAMA_MASTER)
ax25_ds_setup_timer(ax25_dev);
#endif
spin_lock_bh(&ax25_dev_lock);
ax25_dev->next = ax25_dev_list;
ax25_dev_list = ax25_dev;
spin_unlock_bh(&ax25_dev_lock);
ax25_register_sysctl();
}
void ax25_dev_device_down(struct net_device *dev)
{
ax25_dev *s, *ax25_dev;
if ((ax25_dev = ax25_dev_ax25dev(dev)) == NULL)
return;
ax25_unregister_sysctl();
spin_lock_bh(&ax25_dev_lock);
#ifdef CONFIG_AX25_DAMA_SLAVE
ax25_ds_del_timer(ax25_dev);
#endif
for (s = ax25_dev_list; s != NULL; s = s->next)
if (s->forward == dev)
s->forward = NULL;
if ((s = ax25_dev_list) == ax25_dev) {
ax25_dev_list = s->next;
spin_unlock_bh(&ax25_dev_lock);
dev_put(dev);
kfree(ax25_dev);
ax25_register_sysctl();
return;
}
while (s != NULL && s->next != NULL) {
if (s->next == ax25_dev) {
s->next = ax25_dev->next;
spin_unlock_bh(&ax25_dev_lock);
dev_put(dev);
kfree(ax25_dev);
ax25_register_sysctl();
return;
}
s = s->next;
}
spin_unlock_bh(&ax25_dev_lock);
dev->ax25_ptr = NULL;
ax25_register_sysctl();
}
int ax25_fwd_ioctl(unsigned int cmd, struct ax25_fwd_struct *fwd)
{
ax25_dev *ax25_dev, *fwd_dev;
if ((ax25_dev = ax25_addr_ax25dev(&fwd->port_from)) == NULL)
return -EINVAL;
switch (cmd) {
case SIOCAX25ADDFWD:
if ((fwd_dev = ax25_addr_ax25dev(&fwd->port_to)) == NULL)
return -EINVAL;
if (ax25_dev->forward != NULL)
return -EINVAL;
ax25_dev->forward = fwd_dev->dev;
break;
case SIOCAX25DELFWD:
if (ax25_dev->forward == NULL)
return -EINVAL;
ax25_dev->forward = NULL;
break;
default:
return -EINVAL;
}
return 0;
}
struct net_device *ax25_fwd_dev(struct net_device *dev)
{
ax25_dev *ax25_dev;
if ((ax25_dev = ax25_dev_ax25dev(dev)) == NULL)
return dev;
if (ax25_dev->forward == NULL)
return dev;
return ax25_dev->forward;
}
void __exit ax25_dev_free(void)
{
ax25_dev *s, *ax25_dev;
spin_lock_bh(&ax25_dev_lock);
ax25_dev = ax25_dev_list;
while (ax25_dev != NULL) {
s = ax25_dev;
dev_put(ax25_dev->dev);
ax25_dev = ax25_dev->next;
kfree(s);
}
ax25_dev_list = NULL;
spin_unlock_bh(&ax25_dev_lock);
}
