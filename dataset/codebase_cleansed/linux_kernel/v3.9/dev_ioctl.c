static int dev_ifname(struct net *net, struct ifreq __user *arg)
{
struct net_device *dev;
struct ifreq ifr;
unsigned seq;
if (copy_from_user(&ifr, arg, sizeof(struct ifreq)))
return -EFAULT;
retry:
seq = read_seqcount_begin(&devnet_rename_seq);
rcu_read_lock();
dev = dev_get_by_index_rcu(net, ifr.ifr_ifindex);
if (!dev) {
rcu_read_unlock();
return -ENODEV;
}
strcpy(ifr.ifr_name, dev->name);
rcu_read_unlock();
if (read_seqcount_retry(&devnet_rename_seq, seq))
goto retry;
if (copy_to_user(arg, &ifr, sizeof(struct ifreq)))
return -EFAULT;
return 0;
}
int register_gifconf(unsigned int family, gifconf_func_t *gifconf)
{
if (family >= NPROTO)
return -EINVAL;
gifconf_list[family] = gifconf;
return 0;
}
static int dev_ifconf(struct net *net, char __user *arg)
{
struct ifconf ifc;
struct net_device *dev;
char __user *pos;
int len;
int total;
int i;
if (copy_from_user(&ifc, arg, sizeof(struct ifconf)))
return -EFAULT;
pos = ifc.ifc_buf;
len = ifc.ifc_len;
total = 0;
for_each_netdev(net, dev) {
for (i = 0; i < NPROTO; i++) {
if (gifconf_list[i]) {
int done;
if (!pos)
done = gifconf_list[i](dev, NULL, 0);
else
done = gifconf_list[i](dev, pos + total,
len - total);
if (done < 0)
return -EFAULT;
total += done;
}
}
}
ifc.ifc_len = total;
return copy_to_user(arg, &ifc, sizeof(struct ifconf)) ? -EFAULT : 0;
}
static int dev_ifsioc_locked(struct net *net, struct ifreq *ifr, unsigned int cmd)
{
int err;
struct net_device *dev = dev_get_by_name_rcu(net, ifr->ifr_name);
if (!dev)
return -ENODEV;
switch (cmd) {
case SIOCGIFFLAGS:
ifr->ifr_flags = (short) dev_get_flags(dev);
return 0;
case SIOCGIFMETRIC:
ifr->ifr_metric = 0;
return 0;
case SIOCGIFMTU:
ifr->ifr_mtu = dev->mtu;
return 0;
case SIOCGIFHWADDR:
if (!dev->addr_len)
memset(ifr->ifr_hwaddr.sa_data, 0, sizeof ifr->ifr_hwaddr.sa_data);
else
memcpy(ifr->ifr_hwaddr.sa_data, dev->dev_addr,
min(sizeof ifr->ifr_hwaddr.sa_data, (size_t) dev->addr_len));
ifr->ifr_hwaddr.sa_family = dev->type;
return 0;
case SIOCGIFSLAVE:
err = -EINVAL;
break;
case SIOCGIFMAP:
ifr->ifr_map.mem_start = dev->mem_start;
ifr->ifr_map.mem_end = dev->mem_end;
ifr->ifr_map.base_addr = dev->base_addr;
ifr->ifr_map.irq = dev->irq;
ifr->ifr_map.dma = dev->dma;
ifr->ifr_map.port = dev->if_port;
return 0;
case SIOCGIFINDEX:
ifr->ifr_ifindex = dev->ifindex;
return 0;
case SIOCGIFTXQLEN:
ifr->ifr_qlen = dev->tx_queue_len;
return 0;
default:
WARN_ON(1);
err = -ENOTTY;
break;
}
return err;
}
static int net_hwtstamp_validate(struct ifreq *ifr)
{
struct hwtstamp_config cfg;
enum hwtstamp_tx_types tx_type;
enum hwtstamp_rx_filters rx_filter;
int tx_type_valid = 0;
int rx_filter_valid = 0;
if (copy_from_user(&cfg, ifr->ifr_data, sizeof(cfg)))
return -EFAULT;
if (cfg.flags)
return -EINVAL;
tx_type = cfg.tx_type;
rx_filter = cfg.rx_filter;
switch (tx_type) {
case HWTSTAMP_TX_OFF:
case HWTSTAMP_TX_ON:
case HWTSTAMP_TX_ONESTEP_SYNC:
tx_type_valid = 1;
break;
}
switch (rx_filter) {
case HWTSTAMP_FILTER_NONE:
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_SOME:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
rx_filter_valid = 1;
break;
}
if (!tx_type_valid || !rx_filter_valid)
return -ERANGE;
return 0;
}
static int dev_ifsioc(struct net *net, struct ifreq *ifr, unsigned int cmd)
{
int err;
struct net_device *dev = __dev_get_by_name(net, ifr->ifr_name);
const struct net_device_ops *ops;
if (!dev)
return -ENODEV;
ops = dev->netdev_ops;
switch (cmd) {
case SIOCSIFFLAGS:
return dev_change_flags(dev, ifr->ifr_flags);
case SIOCSIFMETRIC:
return -EOPNOTSUPP;
case SIOCSIFMTU:
return dev_set_mtu(dev, ifr->ifr_mtu);
case SIOCSIFHWADDR:
return dev_set_mac_address(dev, &ifr->ifr_hwaddr);
case SIOCSIFHWBROADCAST:
if (ifr->ifr_hwaddr.sa_family != dev->type)
return -EINVAL;
memcpy(dev->broadcast, ifr->ifr_hwaddr.sa_data,
min(sizeof ifr->ifr_hwaddr.sa_data, (size_t) dev->addr_len));
call_netdevice_notifiers(NETDEV_CHANGEADDR, dev);
return 0;
case SIOCSIFMAP:
if (ops->ndo_set_config) {
if (!netif_device_present(dev))
return -ENODEV;
return ops->ndo_set_config(dev, &ifr->ifr_map);
}
return -EOPNOTSUPP;
case SIOCADDMULTI:
if (!ops->ndo_set_rx_mode ||
ifr->ifr_hwaddr.sa_family != AF_UNSPEC)
return -EINVAL;
if (!netif_device_present(dev))
return -ENODEV;
return dev_mc_add_global(dev, ifr->ifr_hwaddr.sa_data);
case SIOCDELMULTI:
if (!ops->ndo_set_rx_mode ||
ifr->ifr_hwaddr.sa_family != AF_UNSPEC)
return -EINVAL;
if (!netif_device_present(dev))
return -ENODEV;
return dev_mc_del_global(dev, ifr->ifr_hwaddr.sa_data);
case SIOCSIFTXQLEN:
if (ifr->ifr_qlen < 0)
return -EINVAL;
dev->tx_queue_len = ifr->ifr_qlen;
return 0;
case SIOCSIFNAME:
ifr->ifr_newname[IFNAMSIZ-1] = '\0';
return dev_change_name(dev, ifr->ifr_newname);
case SIOCSHWTSTAMP:
err = net_hwtstamp_validate(ifr);
if (err)
return err;
default:
if ((cmd >= SIOCDEVPRIVATE &&
cmd <= SIOCDEVPRIVATE + 15) ||
cmd == SIOCBONDENSLAVE ||
cmd == SIOCBONDRELEASE ||
cmd == SIOCBONDSETHWADDR ||
cmd == SIOCBONDSLAVEINFOQUERY ||
cmd == SIOCBONDINFOQUERY ||
cmd == SIOCBONDCHANGEACTIVE ||
cmd == SIOCGMIIPHY ||
cmd == SIOCGMIIREG ||
cmd == SIOCSMIIREG ||
cmd == SIOCBRADDIF ||
cmd == SIOCBRDELIF ||
cmd == SIOCSHWTSTAMP ||
cmd == SIOCWANDEV) {
err = -EOPNOTSUPP;
if (ops->ndo_do_ioctl) {
if (netif_device_present(dev))
err = ops->ndo_do_ioctl(dev, ifr, cmd);
else
err = -ENODEV;
}
} else
err = -EINVAL;
}
return err;
}
void dev_load(struct net *net, const char *name)
{
struct net_device *dev;
int no_module;
rcu_read_lock();
dev = dev_get_by_name_rcu(net, name);
rcu_read_unlock();
no_module = !dev;
if (no_module && capable(CAP_NET_ADMIN))
no_module = request_module("netdev-%s", name);
if (no_module && capable(CAP_SYS_MODULE)) {
if (!request_module("%s", name))
pr_warn("Loading kernel module for a network device with CAP_SYS_MODULE (deprecated). Use CAP_NET_ADMIN and alias netdev-%s instead.\n",
name);
}
}
int dev_ioctl(struct net *net, unsigned int cmd, void __user *arg)
{
struct ifreq ifr;
int ret;
char *colon;
if (cmd == SIOCGIFCONF) {
rtnl_lock();
ret = dev_ifconf(net, (char __user *) arg);
rtnl_unlock();
return ret;
}
if (cmd == SIOCGIFNAME)
return dev_ifname(net, (struct ifreq __user *)arg);
if (copy_from_user(&ifr, arg, sizeof(struct ifreq)))
return -EFAULT;
ifr.ifr_name[IFNAMSIZ-1] = 0;
colon = strchr(ifr.ifr_name, ':');
if (colon)
*colon = 0;
switch (cmd) {
case SIOCGIFFLAGS:
case SIOCGIFMETRIC:
case SIOCGIFMTU:
case SIOCGIFHWADDR:
case SIOCGIFSLAVE:
case SIOCGIFMAP:
case SIOCGIFINDEX:
case SIOCGIFTXQLEN:
dev_load(net, ifr.ifr_name);
rcu_read_lock();
ret = dev_ifsioc_locked(net, &ifr, cmd);
rcu_read_unlock();
if (!ret) {
if (colon)
*colon = ':';
if (copy_to_user(arg, &ifr,
sizeof(struct ifreq)))
ret = -EFAULT;
}
return ret;
case SIOCETHTOOL:
dev_load(net, ifr.ifr_name);
rtnl_lock();
ret = dev_ethtool(net, &ifr);
rtnl_unlock();
if (!ret) {
if (colon)
*colon = ':';
if (copy_to_user(arg, &ifr,
sizeof(struct ifreq)))
ret = -EFAULT;
}
return ret;
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSIFNAME:
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
dev_load(net, ifr.ifr_name);
rtnl_lock();
ret = dev_ifsioc(net, &ifr, cmd);
rtnl_unlock();
if (!ret) {
if (colon)
*colon = ':';
if (copy_to_user(arg, &ifr,
sizeof(struct ifreq)))
ret = -EFAULT;
}
return ret;
case SIOCSIFMAP:
case SIOCSIFTXQLEN:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
case SIOCSIFFLAGS:
case SIOCSIFMETRIC:
case SIOCSIFMTU:
case SIOCSIFHWADDR:
case SIOCSIFSLAVE:
case SIOCADDMULTI:
case SIOCDELMULTI:
case SIOCSIFHWBROADCAST:
case SIOCSMIIREG:
case SIOCBONDENSLAVE:
case SIOCBONDRELEASE:
case SIOCBONDSETHWADDR:
case SIOCBONDCHANGEACTIVE:
case SIOCBRADDIF:
case SIOCBRDELIF:
case SIOCSHWTSTAMP:
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
case SIOCBONDSLAVEINFOQUERY:
case SIOCBONDINFOQUERY:
dev_load(net, ifr.ifr_name);
rtnl_lock();
ret = dev_ifsioc(net, &ifr, cmd);
rtnl_unlock();
return ret;
case SIOCGIFMEM:
case SIOCSIFMEM:
case SIOCSIFLINK:
return -ENOTTY;
default:
if (cmd == SIOCWANDEV ||
(cmd >= SIOCDEVPRIVATE &&
cmd <= SIOCDEVPRIVATE + 15)) {
dev_load(net, ifr.ifr_name);
rtnl_lock();
ret = dev_ifsioc(net, &ifr, cmd);
rtnl_unlock();
if (!ret && copy_to_user(arg, &ifr,
sizeof(struct ifreq)))
ret = -EFAULT;
return ret;
}
if (cmd >= SIOCIWFIRST && cmd <= SIOCIWLAST)
return wext_handle_ioctl(net, &ifr, cmd, arg);
return -ENOTTY;
}
}
