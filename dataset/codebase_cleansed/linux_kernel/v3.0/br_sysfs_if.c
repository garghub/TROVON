static ssize_t show_path_cost(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->path_cost);
}
static ssize_t show_priority(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->priority);
}
static ssize_t show_designated_root(struct net_bridge_port *p, char *buf)
{
return br_show_bridge_id(buf, &p->designated_root);
}
static ssize_t show_designated_bridge(struct net_bridge_port *p, char *buf)
{
return br_show_bridge_id(buf, &p->designated_bridge);
}
static ssize_t show_designated_port(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->designated_port);
}
static ssize_t show_designated_cost(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->designated_cost);
}
static ssize_t show_port_id(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "0x%x\n", p->port_id);
}
static ssize_t show_port_no(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "0x%x\n", p->port_no);
}
static ssize_t show_change_ack(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->topology_change_ack);
}
static ssize_t show_config_pending(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->config_pending);
}
static ssize_t show_port_state(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->state);
}
static ssize_t show_message_age_timer(struct net_bridge_port *p,
char *buf)
{
return sprintf(buf, "%ld\n", br_timer_value(&p->message_age_timer));
}
static ssize_t show_forward_delay_timer(struct net_bridge_port *p,
char *buf)
{
return sprintf(buf, "%ld\n", br_timer_value(&p->forward_delay_timer));
}
static ssize_t show_hold_timer(struct net_bridge_port *p,
char *buf)
{
return sprintf(buf, "%ld\n", br_timer_value(&p->hold_timer));
}
static int store_flush(struct net_bridge_port *p, unsigned long v)
{
br_fdb_delete_by_port(p->br, p, 0);
return 0;
}
static ssize_t show_hairpin_mode(struct net_bridge_port *p, char *buf)
{
int hairpin_mode = (p->flags & BR_HAIRPIN_MODE) ? 1 : 0;
return sprintf(buf, "%d\n", hairpin_mode);
}
static int store_hairpin_mode(struct net_bridge_port *p, unsigned long v)
{
if (v)
p->flags |= BR_HAIRPIN_MODE;
else
p->flags &= ~BR_HAIRPIN_MODE;
return 0;
}
static ssize_t show_multicast_router(struct net_bridge_port *p, char *buf)
{
return sprintf(buf, "%d\n", p->multicast_router);
}
static int store_multicast_router(struct net_bridge_port *p,
unsigned long v)
{
return br_multicast_set_port_router(p, v);
}
static ssize_t brport_show(struct kobject * kobj,
struct attribute * attr, char * buf)
{
struct brport_attribute * brport_attr = to_brport_attr(attr);
struct net_bridge_port * p = to_brport(kobj);
return brport_attr->show(p, buf);
}
static ssize_t brport_store(struct kobject * kobj,
struct attribute * attr,
const char * buf, size_t count)
{
struct brport_attribute * brport_attr = to_brport_attr(attr);
struct net_bridge_port * p = to_brport(kobj);
ssize_t ret = -EINVAL;
char *endp;
unsigned long val;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
val = simple_strtoul(buf, &endp, 0);
if (endp != buf) {
if (!rtnl_trylock())
return restart_syscall();
if (p->dev && p->br && brport_attr->store) {
spin_lock_bh(&p->br->lock);
ret = brport_attr->store(p, val);
spin_unlock_bh(&p->br->lock);
if (ret == 0)
ret = count;
}
rtnl_unlock();
}
return ret;
}
int br_sysfs_addif(struct net_bridge_port *p)
{
struct net_bridge *br = p->br;
struct brport_attribute **a;
int err;
err = sysfs_create_link(&p->kobj, &br->dev->dev.kobj,
SYSFS_BRIDGE_PORT_LINK);
if (err)
return err;
for (a = brport_attrs; *a; ++a) {
err = sysfs_create_file(&p->kobj, &((*a)->attr));
if (err)
return err;
}
strlcpy(p->sysfs_name, p->dev->name, IFNAMSIZ);
return sysfs_create_link(br->ifobj, &p->kobj, p->sysfs_name);
}
int br_sysfs_renameif(struct net_bridge_port *p)
{
struct net_bridge *br = p->br;
int err;
if (!strncmp(p->sysfs_name, p->dev->name, IFNAMSIZ))
return 0;
err = sysfs_rename_link(br->ifobj, &p->kobj,
p->sysfs_name, p->dev->name);
if (err)
netdev_notice(br->dev, "unable to rename link %s to %s",
p->sysfs_name, p->dev->name);
else
strlcpy(p->sysfs_name, p->dev->name, IFNAMSIZ);
return err;
}
