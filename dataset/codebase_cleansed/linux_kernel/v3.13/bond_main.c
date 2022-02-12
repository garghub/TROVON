const char *bond_mode_name(int mode)
{
static const char *names[] = {
[BOND_MODE_ROUNDROBIN] = "load balancing (round-robin)",
[BOND_MODE_ACTIVEBACKUP] = "fault-tolerance (active-backup)",
[BOND_MODE_XOR] = "load balancing (xor)",
[BOND_MODE_BROADCAST] = "fault-tolerance (broadcast)",
[BOND_MODE_8023AD] = "IEEE 802.3ad Dynamic link aggregation",
[BOND_MODE_TLB] = "transmit load balancing",
[BOND_MODE_ALB] = "adaptive load balancing",
};
if (mode < BOND_MODE_ROUNDROBIN || mode > BOND_MODE_ALB)
return "unknown";
return names[mode];
}
int bond_dev_queue_xmit(struct bonding *bond, struct sk_buff *skb,
struct net_device *slave_dev)
{
skb->dev = slave_dev;
BUILD_BUG_ON(sizeof(skb->queue_mapping) !=
sizeof(qdisc_skb_cb(skb)->slave_dev_queue_mapping));
skb->queue_mapping = qdisc_skb_cb(skb)->slave_dev_queue_mapping;
if (unlikely(netpoll_tx_running(bond->dev)))
bond_netpoll_send_skb(bond_get_slave_by_dev(bond, slave_dev), skb);
else
dev_queue_xmit(skb);
return 0;
}
static int bond_vlan_rx_add_vid(struct net_device *bond_dev,
__be16 proto, u16 vid)
{
struct bonding *bond = netdev_priv(bond_dev);
struct slave *slave, *rollback_slave;
struct list_head *iter;
int res;
bond_for_each_slave(bond, slave, iter) {
res = vlan_vid_add(slave->dev, proto, vid);
if (res)
goto unwind;
}
return 0;
unwind:
bond_for_each_slave(bond, rollback_slave, iter) {
if (rollback_slave == slave)
break;
vlan_vid_del(rollback_slave->dev, proto, vid);
}
return res;
}
static int bond_vlan_rx_kill_vid(struct net_device *bond_dev,
__be16 proto, u16 vid)
{
struct bonding *bond = netdev_priv(bond_dev);
struct list_head *iter;
struct slave *slave;
bond_for_each_slave(bond, slave, iter)
vlan_vid_del(slave->dev, proto, vid);
if (bond_is_lb(bond))
bond_alb_clear_vlan(bond, vid);
return 0;
}
static int bond_set_carrier(struct bonding *bond)
{
struct list_head *iter;
struct slave *slave;
if (!bond_has_slaves(bond))
goto down;
if (bond->params.mode == BOND_MODE_8023AD)
return bond_3ad_set_carrier(bond);
bond_for_each_slave(bond, slave, iter) {
if (slave->link == BOND_LINK_UP) {
if (!netif_carrier_ok(bond->dev)) {
netif_carrier_on(bond->dev);
return 1;
}
return 0;
}
}
down:
if (netif_carrier_ok(bond->dev)) {
netif_carrier_off(bond->dev);
return 1;
}
return 0;
}
static void bond_update_speed_duplex(struct slave *slave)
{
struct net_device *slave_dev = slave->dev;
struct ethtool_cmd ecmd;
u32 slave_speed;
int res;
slave->speed = SPEED_UNKNOWN;
slave->duplex = DUPLEX_UNKNOWN;
res = __ethtool_get_settings(slave_dev, &ecmd);
if (res < 0)
return;
slave_speed = ethtool_cmd_speed(&ecmd);
if (slave_speed == 0 || slave_speed == ((__u32) -1))
return;
switch (ecmd.duplex) {
case DUPLEX_FULL:
case DUPLEX_HALF:
break;
default:
return;
}
slave->speed = slave_speed;
slave->duplex = ecmd.duplex;
return;
}
static int bond_check_dev_link(struct bonding *bond,
struct net_device *slave_dev, int reporting)
{
const struct net_device_ops *slave_ops = slave_dev->netdev_ops;
int (*ioctl)(struct net_device *, struct ifreq *, int);
struct ifreq ifr;
struct mii_ioctl_data *mii;
if (!reporting && !netif_running(slave_dev))
return 0;
if (bond->params.use_carrier)
return netif_carrier_ok(slave_dev) ? BMSR_LSTATUS : 0;
if (slave_dev->ethtool_ops->get_link)
return slave_dev->ethtool_ops->get_link(slave_dev) ?
BMSR_LSTATUS : 0;
ioctl = slave_ops->ndo_do_ioctl;
if (ioctl) {
strncpy(ifr.ifr_name, slave_dev->name, IFNAMSIZ);
mii = if_mii(&ifr);
if (IOCTL(slave_dev, &ifr, SIOCGMIIPHY) == 0) {
mii->reg_num = MII_BMSR;
if (IOCTL(slave_dev, &ifr, SIOCGMIIREG) == 0)
return mii->val_out & BMSR_LSTATUS;
}
}
return reporting ? -1 : BMSR_LSTATUS;
}
static int bond_set_promiscuity(struct bonding *bond, int inc)
{
struct list_head *iter;
int err = 0;
if (USES_PRIMARY(bond->params.mode)) {
if (bond->curr_active_slave) {
err = dev_set_promiscuity(bond->curr_active_slave->dev,
inc);
}
} else {
struct slave *slave;
bond_for_each_slave(bond, slave, iter) {
err = dev_set_promiscuity(slave->dev, inc);
if (err)
return err;
}
}
return err;
}
static int bond_set_allmulti(struct bonding *bond, int inc)
{
struct list_head *iter;
int err = 0;
if (USES_PRIMARY(bond->params.mode)) {
if (bond->curr_active_slave) {
err = dev_set_allmulti(bond->curr_active_slave->dev,
inc);
}
} else {
struct slave *slave;
bond_for_each_slave(bond, slave, iter) {
err = dev_set_allmulti(slave->dev, inc);
if (err)
return err;
}
}
return err;
}
static void bond_resend_igmp_join_requests(struct bonding *bond)
{
if (!rtnl_trylock()) {
queue_delayed_work(bond->wq, &bond->mcast_work, 1);
return;
}
call_netdevice_notifiers(NETDEV_RESEND_IGMP, bond->dev);
rtnl_unlock();
write_lock_bh(&bond->curr_slave_lock);
if (bond->igmp_retrans > 1) {
bond->igmp_retrans--;
queue_delayed_work(bond->wq, &bond->mcast_work, HZ/5);
}
write_unlock_bh(&bond->curr_slave_lock);
}
static void bond_resend_igmp_join_requests_delayed(struct work_struct *work)
{
struct bonding *bond = container_of(work, struct bonding,
mcast_work.work);
bond_resend_igmp_join_requests(bond);
}
static void bond_hw_addr_flush(struct net_device *bond_dev,
struct net_device *slave_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
dev_uc_unsync(slave_dev, bond_dev);
dev_mc_unsync(slave_dev, bond_dev);
if (bond->params.mode == BOND_MODE_8023AD) {
u8 lacpdu_multicast[ETH_ALEN] = MULTICAST_LACPDU_ADDR;
dev_mc_del(slave_dev, lacpdu_multicast);
}
}
static void bond_hw_addr_swap(struct bonding *bond, struct slave *new_active,
struct slave *old_active)
{
ASSERT_RTNL();
if (old_active) {
if (bond->dev->flags & IFF_PROMISC)
dev_set_promiscuity(old_active->dev, -1);
if (bond->dev->flags & IFF_ALLMULTI)
dev_set_allmulti(old_active->dev, -1);
bond_hw_addr_flush(bond->dev, old_active->dev);
}
if (new_active) {
if (bond->dev->flags & IFF_PROMISC)
dev_set_promiscuity(new_active->dev, 1);
if (bond->dev->flags & IFF_ALLMULTI)
dev_set_allmulti(new_active->dev, 1);
netif_addr_lock_bh(bond->dev);
dev_uc_sync(new_active->dev, bond->dev);
dev_mc_sync(new_active->dev, bond->dev);
netif_addr_unlock_bh(bond->dev);
}
}
static void bond_set_dev_addr(struct net_device *bond_dev,
struct net_device *slave_dev)
{
pr_debug("bond_dev=%p slave_dev=%p slave_dev->addr_len=%d\n",
bond_dev, slave_dev, slave_dev->addr_len);
memcpy(bond_dev->dev_addr, slave_dev->dev_addr, slave_dev->addr_len);
bond_dev->addr_assign_type = NET_ADDR_STOLEN;
call_netdevice_notifiers(NETDEV_CHANGEADDR, bond_dev);
}
static void bond_do_fail_over_mac(struct bonding *bond,
struct slave *new_active,
struct slave *old_active)
__releases(&bond->curr_slave_lock
static bool bond_should_change_active(struct bonding *bond)
{
struct slave *prim = bond->primary_slave;
struct slave *curr = bond->curr_active_slave;
if (!prim || !curr || curr->link != BOND_LINK_UP)
return true;
if (bond->force_primary) {
bond->force_primary = false;
return true;
}
if (bond->params.primary_reselect == BOND_PRI_RESELECT_BETTER &&
(prim->speed < curr->speed ||
(prim->speed == curr->speed && prim->duplex <= curr->duplex)))
return false;
if (bond->params.primary_reselect == BOND_PRI_RESELECT_FAILURE)
return false;
return true;
}
static struct slave *bond_find_best_slave(struct bonding *bond)
{
struct slave *slave, *bestslave = NULL;
struct list_head *iter;
int mintime = bond->params.updelay;
if (bond->primary_slave && bond->primary_slave->link == BOND_LINK_UP &&
bond_should_change_active(bond))
return bond->primary_slave;
bond_for_each_slave(bond, slave, iter) {
if (slave->link == BOND_LINK_UP)
return slave;
if (slave->link == BOND_LINK_BACK && IS_UP(slave->dev) &&
slave->delay < mintime) {
mintime = slave->delay;
bestslave = slave;
}
}
return bestslave;
}
static bool bond_should_notify_peers(struct bonding *bond)
{
struct slave *slave = bond->curr_active_slave;
pr_debug("bond_should_notify_peers: bond %s slave %s\n",
bond->dev->name, slave ? slave->dev->name : "NULL");
if (!slave || !bond->send_peer_notif ||
test_bit(__LINK_STATE_LINKWATCH_PENDING, &slave->dev->state))
return false;
return true;
}
void bond_change_active_slave(struct bonding *bond, struct slave *new_active)
{
struct slave *old_active = bond->curr_active_slave;
if (old_active == new_active)
return;
if (new_active) {
new_active->jiffies = jiffies;
if (new_active->link == BOND_LINK_BACK) {
if (USES_PRIMARY(bond->params.mode)) {
pr_info("%s: making interface %s the new active one %d ms earlier.\n",
bond->dev->name, new_active->dev->name,
(bond->params.updelay - new_active->delay) * bond->params.miimon);
}
new_active->delay = 0;
new_active->link = BOND_LINK_UP;
if (bond->params.mode == BOND_MODE_8023AD)
bond_3ad_handle_link_change(new_active, BOND_LINK_UP);
if (bond_is_lb(bond))
bond_alb_handle_link_change(bond, new_active, BOND_LINK_UP);
} else {
if (USES_PRIMARY(bond->params.mode)) {
pr_info("%s: making interface %s the new active one.\n",
bond->dev->name, new_active->dev->name);
}
}
}
if (USES_PRIMARY(bond->params.mode))
bond_hw_addr_swap(bond, new_active, old_active);
if (bond_is_lb(bond)) {
bond_alb_handle_active_change(bond, new_active);
if (old_active)
bond_set_slave_inactive_flags(old_active);
if (new_active)
bond_set_slave_active_flags(new_active);
} else {
rcu_assign_pointer(bond->curr_active_slave, new_active);
}
if (bond->params.mode == BOND_MODE_ACTIVEBACKUP) {
if (old_active)
bond_set_slave_inactive_flags(old_active);
if (new_active) {
bool should_notify_peers = false;
bond_set_slave_active_flags(new_active);
if (bond->params.fail_over_mac)
bond_do_fail_over_mac(bond, new_active,
old_active);
if (netif_running(bond->dev)) {
bond->send_peer_notif =
bond->params.num_peer_notif;
should_notify_peers =
bond_should_notify_peers(bond);
}
write_unlock_bh(&bond->curr_slave_lock);
read_unlock(&bond->lock);
call_netdevice_notifiers(NETDEV_BONDING_FAILOVER, bond->dev);
if (should_notify_peers)
call_netdevice_notifiers(NETDEV_NOTIFY_PEERS,
bond->dev);
read_lock(&bond->lock);
write_lock_bh(&bond->curr_slave_lock);
}
}
if (netif_running(bond->dev) && (bond->params.resend_igmp > 0) &&
((USES_PRIMARY(bond->params.mode) && new_active) ||
bond->params.mode == BOND_MODE_ROUNDROBIN)) {
bond->igmp_retrans = bond->params.resend_igmp;
queue_delayed_work(bond->wq, &bond->mcast_work, 1);
}
}
void bond_select_active_slave(struct bonding *bond)
{
struct slave *best_slave;
int rv;
best_slave = bond_find_best_slave(bond);
if (best_slave != bond->curr_active_slave) {
bond_change_active_slave(bond, best_slave);
rv = bond_set_carrier(bond);
if (!rv)
return;
if (netif_carrier_ok(bond->dev)) {
pr_info("%s: first active interface up!\n",
bond->dev->name);
} else {
pr_info("%s: now running without any active interface !\n",
bond->dev->name);
}
}
}
static inline int slave_enable_netpoll(struct slave *slave)
{
struct netpoll *np;
int err = 0;
np = kzalloc(sizeof(*np), GFP_ATOMIC);
err = -ENOMEM;
if (!np)
goto out;
err = __netpoll_setup(np, slave->dev, GFP_ATOMIC);
if (err) {
kfree(np);
goto out;
}
slave->np = np;
out:
return err;
}
static inline void slave_disable_netpoll(struct slave *slave)
{
struct netpoll *np = slave->np;
if (!np)
return;
slave->np = NULL;
__netpoll_free_async(np);
}
static inline bool slave_dev_support_netpoll(struct net_device *slave_dev)
{
if (slave_dev->priv_flags & IFF_DISABLE_NETPOLL)
return false;
if (!slave_dev->netdev_ops->ndo_poll_controller)
return false;
return true;
}
static void bond_poll_controller(struct net_device *bond_dev)
{
}
static void bond_netpoll_cleanup(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct list_head *iter;
struct slave *slave;
bond_for_each_slave(bond, slave, iter)
if (IS_UP(slave->dev))
slave_disable_netpoll(slave);
}
static int bond_netpoll_setup(struct net_device *dev, struct netpoll_info *ni, gfp_t gfp)
{
struct bonding *bond = netdev_priv(dev);
struct list_head *iter;
struct slave *slave;
int err = 0;
bond_for_each_slave(bond, slave, iter) {
err = slave_enable_netpoll(slave);
if (err) {
bond_netpoll_cleanup(dev);
break;
}
}
return err;
}
static inline int slave_enable_netpoll(struct slave *slave)
{
return 0;
}
static inline void slave_disable_netpoll(struct slave *slave)
{
}
static void bond_netpoll_cleanup(struct net_device *bond_dev)
{
}
static netdev_features_t bond_fix_features(struct net_device *dev,
netdev_features_t features)
{
struct bonding *bond = netdev_priv(dev);
struct list_head *iter;
netdev_features_t mask;
struct slave *slave;
if (!bond_has_slaves(bond)) {
features |= NETIF_F_VLAN_CHALLENGED;
return features;
}
mask = features;
features &= ~NETIF_F_ONE_FOR_ALL;
features |= NETIF_F_ALL_FOR_ALL;
bond_for_each_slave(bond, slave, iter) {
features = netdev_increment_features(features,
slave->dev->features,
mask);
}
features = netdev_add_tso_features(features, mask);
return features;
}
static void bond_compute_features(struct bonding *bond)
{
unsigned int flags, dst_release_flag = IFF_XMIT_DST_RELEASE;
netdev_features_t vlan_features = BOND_VLAN_FEATURES;
struct net_device *bond_dev = bond->dev;
struct list_head *iter;
struct slave *slave;
unsigned short max_hard_header_len = ETH_HLEN;
unsigned int gso_max_size = GSO_MAX_SIZE;
u16 gso_max_segs = GSO_MAX_SEGS;
if (!bond_has_slaves(bond))
goto done;
bond_for_each_slave(bond, slave, iter) {
vlan_features = netdev_increment_features(vlan_features,
slave->dev->vlan_features, BOND_VLAN_FEATURES);
dst_release_flag &= slave->dev->priv_flags;
if (slave->dev->hard_header_len > max_hard_header_len)
max_hard_header_len = slave->dev->hard_header_len;
gso_max_size = min(gso_max_size, slave->dev->gso_max_size);
gso_max_segs = min(gso_max_segs, slave->dev->gso_max_segs);
}
done:
bond_dev->vlan_features = vlan_features;
bond_dev->hard_header_len = max_hard_header_len;
bond_dev->gso_max_segs = gso_max_segs;
netif_set_gso_max_size(bond_dev, gso_max_size);
flags = bond_dev->priv_flags & ~IFF_XMIT_DST_RELEASE;
bond_dev->priv_flags = flags | dst_release_flag;
netdev_change_features(bond_dev);
}
static void bond_setup_by_slave(struct net_device *bond_dev,
struct net_device *slave_dev)
{
bond_dev->header_ops = slave_dev->header_ops;
bond_dev->type = slave_dev->type;
bond_dev->hard_header_len = slave_dev->hard_header_len;
bond_dev->addr_len = slave_dev->addr_len;
memcpy(bond_dev->broadcast, slave_dev->broadcast,
slave_dev->addr_len);
}
static bool bond_should_deliver_exact_match(struct sk_buff *skb,
struct slave *slave,
struct bonding *bond)
{
if (bond_is_slave_inactive(slave)) {
if (bond->params.mode == BOND_MODE_ALB &&
skb->pkt_type != PACKET_BROADCAST &&
skb->pkt_type != PACKET_MULTICAST)
return false;
return true;
}
return false;
}
static rx_handler_result_t bond_handle_frame(struct sk_buff **pskb)
{
struct sk_buff *skb = *pskb;
struct slave *slave;
struct bonding *bond;
int (*recv_probe)(const struct sk_buff *, struct bonding *,
struct slave *);
int ret = RX_HANDLER_ANOTHER;
skb = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(!skb))
return RX_HANDLER_CONSUMED;
*pskb = skb;
slave = bond_slave_get_rcu(skb->dev);
bond = slave->bond;
if (bond->params.arp_interval)
slave->dev->last_rx = jiffies;
recv_probe = ACCESS_ONCE(bond->recv_probe);
if (recv_probe) {
ret = recv_probe(skb, bond, slave);
if (ret == RX_HANDLER_CONSUMED) {
consume_skb(skb);
return ret;
}
}
if (bond_should_deliver_exact_match(skb, slave, bond)) {
return RX_HANDLER_EXACT;
}
skb->dev = bond->dev;
if (bond->params.mode == BOND_MODE_ALB &&
bond->dev->priv_flags & IFF_BRIDGE_PORT &&
skb->pkt_type == PACKET_HOST) {
if (unlikely(skb_cow_head(skb,
skb->data - skb_mac_header(skb)))) {
kfree_skb(skb);
return RX_HANDLER_CONSUMED;
}
memcpy(eth_hdr(skb)->h_dest, bond->dev->dev_addr, ETH_ALEN);
}
return ret;
}
static int bond_master_upper_dev_link(struct net_device *bond_dev,
struct net_device *slave_dev,
struct slave *slave)
{
int err;
err = netdev_master_upper_dev_link_private(slave_dev, bond_dev, slave);
if (err)
return err;
slave_dev->flags |= IFF_SLAVE;
rtmsg_ifinfo(RTM_NEWLINK, slave_dev, IFF_SLAVE, GFP_KERNEL);
return 0;
}
static void bond_upper_dev_unlink(struct net_device *bond_dev,
struct net_device *slave_dev)
{
netdev_upper_dev_unlink(slave_dev, bond_dev);
slave_dev->flags &= ~IFF_SLAVE;
rtmsg_ifinfo(RTM_NEWLINK, slave_dev, IFF_SLAVE, GFP_KERNEL);
}
int bond_enslave(struct net_device *bond_dev, struct net_device *slave_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
const struct net_device_ops *slave_ops = slave_dev->netdev_ops;
struct slave *new_slave = NULL, *prev_slave;
struct sockaddr addr;
int link_reporting;
int res = 0, i;
if (!bond->params.use_carrier &&
slave_dev->ethtool_ops->get_link == NULL &&
slave_ops->ndo_do_ioctl == NULL) {
pr_warning("%s: Warning: no link monitoring support for %s\n",
bond_dev->name, slave_dev->name);
}
if (slave_dev->flags & IFF_SLAVE) {
pr_debug("Error, Device was already enslaved\n");
return -EBUSY;
}
if (slave_dev->features & NETIF_F_VLAN_CHALLENGED) {
pr_debug("%s: NETIF_F_VLAN_CHALLENGED\n", slave_dev->name);
if (vlan_uses_dev(bond_dev)) {
pr_err("%s: Error: cannot enslave VLAN challenged slave %s on VLAN enabled bond %s\n",
bond_dev->name, slave_dev->name, bond_dev->name);
return -EPERM;
} else {
pr_warning("%s: Warning: enslaved VLAN challenged slave %s. Adding VLANs will be blocked as long as %s is part of bond %s\n",
bond_dev->name, slave_dev->name,
slave_dev->name, bond_dev->name);
}
} else {
pr_debug("%s: ! NETIF_F_VLAN_CHALLENGED\n", slave_dev->name);
}
if ((slave_dev->flags & IFF_UP)) {
pr_err("%s is up. This may be due to an out of date ifenslave.\n",
slave_dev->name);
res = -EPERM;
goto err_undo_flags;
}
if (!bond_has_slaves(bond)) {
if (bond_dev->type != slave_dev->type) {
pr_debug("%s: change device type from %d to %d\n",
bond_dev->name,
bond_dev->type, slave_dev->type);
res = call_netdevice_notifiers(NETDEV_PRE_TYPE_CHANGE,
bond_dev);
res = notifier_to_errno(res);
if (res) {
pr_err("%s: refused to change device type\n",
bond_dev->name);
res = -EBUSY;
goto err_undo_flags;
}
dev_uc_flush(bond_dev);
dev_mc_flush(bond_dev);
if (slave_dev->type != ARPHRD_ETHER)
bond_setup_by_slave(bond_dev, slave_dev);
else {
ether_setup(bond_dev);
bond_dev->priv_flags &= ~IFF_TX_SKB_SHARING;
}
call_netdevice_notifiers(NETDEV_POST_TYPE_CHANGE,
bond_dev);
}
} else if (bond_dev->type != slave_dev->type) {
pr_err("%s ether type (%d) is different from other slaves (%d), can not enslave it.\n",
slave_dev->name,
slave_dev->type, bond_dev->type);
res = -EINVAL;
goto err_undo_flags;
}
if (slave_ops->ndo_set_mac_address == NULL) {
if (!bond_has_slaves(bond)) {
pr_warning("%s: Warning: The first slave device specified does not support setting the MAC address. Setting fail_over_mac to active.",
bond_dev->name);
bond->params.fail_over_mac = BOND_FOM_ACTIVE;
} else if (bond->params.fail_over_mac != BOND_FOM_ACTIVE) {
pr_err("%s: Error: The slave device specified does not support setting the MAC address, but fail_over_mac is not set to active.\n",
bond_dev->name);
res = -EOPNOTSUPP;
goto err_undo_flags;
}
}
call_netdevice_notifiers(NETDEV_JOIN, slave_dev);
if (!bond_has_slaves(bond) &&
bond->dev->addr_assign_type == NET_ADDR_RANDOM)
bond_set_dev_addr(bond->dev, slave_dev);
new_slave = kzalloc(sizeof(struct slave), GFP_KERNEL);
if (!new_slave) {
res = -ENOMEM;
goto err_undo_flags;
}
new_slave->queue_id = 0;
new_slave->original_mtu = slave_dev->mtu;
res = dev_set_mtu(slave_dev, bond->dev->mtu);
if (res) {
pr_debug("Error %d calling dev_set_mtu\n", res);
goto err_free;
}
memcpy(new_slave->perm_hwaddr, slave_dev->dev_addr, ETH_ALEN);
if (!bond->params.fail_over_mac) {
memcpy(addr.sa_data, bond_dev->dev_addr, bond_dev->addr_len);
addr.sa_family = slave_dev->type;
res = dev_set_mac_address(slave_dev, &addr);
if (res) {
pr_debug("Error %d calling set_mac_address\n", res);
goto err_restore_mtu;
}
}
res = dev_open(slave_dev);
if (res) {
pr_debug("Opening slave %s failed\n", slave_dev->name);
goto err_restore_mac;
}
new_slave->bond = bond;
new_slave->dev = slave_dev;
slave_dev->priv_flags |= IFF_BONDING;
if (bond_is_lb(bond)) {
res = bond_alb_init_slave(bond, new_slave);
if (res)
goto err_close;
}
if (!USES_PRIMARY(bond->params.mode)) {
if (bond_dev->flags & IFF_PROMISC) {
res = dev_set_promiscuity(slave_dev, 1);
if (res)
goto err_close;
}
if (bond_dev->flags & IFF_ALLMULTI) {
res = dev_set_allmulti(slave_dev, 1);
if (res)
goto err_close;
}
netif_addr_lock_bh(bond_dev);
dev_mc_sync_multiple(slave_dev, bond_dev);
dev_uc_sync_multiple(slave_dev, bond_dev);
netif_addr_unlock_bh(bond_dev);
}
if (bond->params.mode == BOND_MODE_8023AD) {
u8 lacpdu_multicast[ETH_ALEN] = MULTICAST_LACPDU_ADDR;
dev_mc_add(slave_dev, lacpdu_multicast);
}
res = vlan_vids_add_by_dev(slave_dev, bond_dev);
if (res) {
pr_err("%s: Error: Couldn't add bond vlan ids to %s\n",
bond_dev->name, slave_dev->name);
goto err_close;
}
prev_slave = bond_last_slave(bond);
new_slave->delay = 0;
new_slave->link_failure_count = 0;
bond_update_speed_duplex(new_slave);
new_slave->last_arp_rx = jiffies -
(msecs_to_jiffies(bond->params.arp_interval) + 1);
for (i = 0; i < BOND_MAX_ARP_TARGETS; i++)
new_slave->target_last_arp_rx[i] = new_slave->last_arp_rx;
if (bond->params.miimon && !bond->params.use_carrier) {
link_reporting = bond_check_dev_link(bond, slave_dev, 1);
if ((link_reporting == -1) && !bond->params.arp_interval) {
pr_warning("%s: Warning: MII and ETHTOOL support not available for interface %s, and arp_interval/arp_ip_target module parameters not specified, thus bonding will not detect link failures! see bonding.txt for details.\n",
bond_dev->name, slave_dev->name);
} else if (link_reporting == -1) {
pr_warning("%s: Warning: can't get link status from interface %s; the network driver associated with this interface does not support MII or ETHTOOL link status reporting, thus miimon has no effect on this interface.\n",
bond_dev->name, slave_dev->name);
}
}
if (bond->params.miimon) {
if (bond_check_dev_link(bond, slave_dev, 0) == BMSR_LSTATUS) {
if (bond->params.updelay) {
new_slave->link = BOND_LINK_BACK;
new_slave->delay = bond->params.updelay;
} else {
new_slave->link = BOND_LINK_UP;
}
} else {
new_slave->link = BOND_LINK_DOWN;
}
} else if (bond->params.arp_interval) {
new_slave->link = (netif_carrier_ok(slave_dev) ?
BOND_LINK_UP : BOND_LINK_DOWN);
} else {
new_slave->link = BOND_LINK_UP;
}
if (new_slave->link != BOND_LINK_DOWN)
new_slave->jiffies = jiffies;
pr_debug("Initial state of slave_dev is BOND_LINK_%s\n",
new_slave->link == BOND_LINK_DOWN ? "DOWN" :
(new_slave->link == BOND_LINK_UP ? "UP" : "BACK"));
if (USES_PRIMARY(bond->params.mode) && bond->params.primary[0]) {
if (strcmp(bond->params.primary, new_slave->dev->name) == 0) {
bond->primary_slave = new_slave;
bond->force_primary = true;
}
}
switch (bond->params.mode) {
case BOND_MODE_ACTIVEBACKUP:
bond_set_slave_inactive_flags(new_slave);
break;
case BOND_MODE_8023AD:
bond_set_slave_inactive_flags(new_slave);
if (!prev_slave) {
SLAVE_AD_INFO(new_slave).id = 1;
bond_3ad_initialize(bond, 1000/AD_TIMER_INTERVAL);
} else {
SLAVE_AD_INFO(new_slave).id =
SLAVE_AD_INFO(prev_slave).id + 1;
}
bond_3ad_bind_slave(new_slave);
break;
case BOND_MODE_TLB:
case BOND_MODE_ALB:
bond_set_active_slave(new_slave);
bond_set_slave_inactive_flags(new_slave);
break;
default:
pr_debug("This slave is always active in trunk mode\n");
bond_set_active_slave(new_slave);
if (!bond->curr_active_slave && new_slave->link == BOND_LINK_UP)
rcu_assign_pointer(bond->curr_active_slave, new_slave);
break;
}
#ifdef CONFIG_NET_POLL_CONTROLLER
slave_dev->npinfo = bond->dev->npinfo;
if (slave_dev->npinfo) {
if (slave_enable_netpoll(new_slave)) {
read_unlock(&bond->lock);
pr_info("Error, %s: master_dev is using netpoll, "
"but new slave device does not support netpoll.\n",
bond_dev->name);
res = -EBUSY;
goto err_detach;
}
}
#endif
res = netdev_rx_handler_register(slave_dev, bond_handle_frame,
new_slave);
if (res) {
pr_debug("Error %d calling netdev_rx_handler_register\n", res);
goto err_detach;
}
res = bond_master_upper_dev_link(bond_dev, slave_dev, new_slave);
if (res) {
pr_debug("Error %d calling bond_master_upper_dev_link\n", res);
goto err_unregister;
}
bond->slave_cnt++;
bond_compute_features(bond);
bond_set_carrier(bond);
if (USES_PRIMARY(bond->params.mode)) {
read_lock(&bond->lock);
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
read_unlock(&bond->lock);
}
pr_info("%s: enslaving %s as a%s interface with a%s link.\n",
bond_dev->name, slave_dev->name,
bond_is_active_slave(new_slave) ? "n active" : " backup",
new_slave->link != BOND_LINK_DOWN ? "n up" : " down");
return 0;
err_unregister:
netdev_rx_handler_unregister(slave_dev);
err_detach:
if (!USES_PRIMARY(bond->params.mode))
bond_hw_addr_flush(bond_dev, slave_dev);
vlan_vids_del_by_dev(slave_dev, bond_dev);
write_lock_bh(&bond->lock);
if (bond->primary_slave == new_slave)
bond->primary_slave = NULL;
if (bond->curr_active_slave == new_slave) {
bond_change_active_slave(bond, NULL);
write_unlock_bh(&bond->lock);
read_lock(&bond->lock);
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
read_unlock(&bond->lock);
} else {
write_unlock_bh(&bond->lock);
}
slave_disable_netpoll(new_slave);
err_close:
slave_dev->priv_flags &= ~IFF_BONDING;
dev_close(slave_dev);
err_restore_mac:
if (!bond->params.fail_over_mac) {
memcpy(addr.sa_data, new_slave->perm_hwaddr, ETH_ALEN);
addr.sa_family = slave_dev->type;
dev_set_mac_address(slave_dev, &addr);
}
err_restore_mtu:
dev_set_mtu(slave_dev, new_slave->original_mtu);
err_free:
kfree(new_slave);
err_undo_flags:
if (!bond_has_slaves(bond) &&
ether_addr_equal(bond_dev->dev_addr, slave_dev->dev_addr))
eth_hw_addr_random(bond_dev);
return res;
}
static int __bond_release_one(struct net_device *bond_dev,
struct net_device *slave_dev,
bool all)
{
struct bonding *bond = netdev_priv(bond_dev);
struct slave *slave, *oldcurrent;
struct sockaddr addr;
int old_flags = bond_dev->flags;
netdev_features_t old_features = bond_dev->features;
if (!(slave_dev->flags & IFF_SLAVE) ||
!netdev_has_upper_dev(slave_dev, bond_dev)) {
pr_err("%s: Error: cannot release %s.\n",
bond_dev->name, slave_dev->name);
return -EINVAL;
}
block_netpoll_tx();
write_lock_bh(&bond->lock);
slave = bond_get_slave_by_dev(bond, slave_dev);
if (!slave) {
pr_info("%s: %s not enslaved\n",
bond_dev->name, slave_dev->name);
write_unlock_bh(&bond->lock);
unblock_netpoll_tx();
return -EINVAL;
}
write_unlock_bh(&bond->lock);
bond->slave_cnt--;
bond_upper_dev_unlink(bond_dev, slave_dev);
netdev_rx_handler_unregister(slave_dev);
write_lock_bh(&bond->lock);
if (bond->params.mode == BOND_MODE_8023AD) {
bond_3ad_unbind_slave(slave);
}
pr_info("%s: releasing %s interface %s\n",
bond_dev->name,
bond_is_active_slave(slave) ? "active" : "backup",
slave_dev->name);
oldcurrent = bond->curr_active_slave;
bond->current_arp_slave = NULL;
if (!all && !bond->params.fail_over_mac) {
if (ether_addr_equal(bond_dev->dev_addr, slave->perm_hwaddr) &&
bond_has_slaves(bond))
pr_warn("%s: Warning: the permanent HWaddr of %s - %pM - is still in use by %s. Set the HWaddr of %s to a different address to avoid conflicts.\n",
bond_dev->name, slave_dev->name,
slave->perm_hwaddr,
bond_dev->name, slave_dev->name);
}
if (bond->primary_slave == slave)
bond->primary_slave = NULL;
if (oldcurrent == slave)
bond_change_active_slave(bond, NULL);
if (bond_is_lb(bond)) {
write_unlock_bh(&bond->lock);
bond_alb_deinit_slave(bond, slave);
write_lock_bh(&bond->lock);
}
if (all) {
rcu_assign_pointer(bond->curr_active_slave, NULL);
} else if (oldcurrent == slave) {
write_unlock_bh(&bond->lock);
read_lock(&bond->lock);
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
read_unlock(&bond->lock);
write_lock_bh(&bond->lock);
}
if (!bond_has_slaves(bond)) {
bond_set_carrier(bond);
eth_hw_addr_random(bond_dev);
if (vlan_uses_dev(bond_dev)) {
pr_warning("%s: Warning: clearing HW address of %s while it still has VLANs.\n",
bond_dev->name, bond_dev->name);
pr_warning("%s: When re-adding slaves, make sure the bond's HW address matches its VLANs'.\n",
bond_dev->name);
}
}
write_unlock_bh(&bond->lock);
unblock_netpoll_tx();
synchronize_rcu();
if (!bond_has_slaves(bond)) {
call_netdevice_notifiers(NETDEV_CHANGEADDR, bond->dev);
call_netdevice_notifiers(NETDEV_RELEASE, bond->dev);
}
bond_compute_features(bond);
if (!(bond_dev->features & NETIF_F_VLAN_CHALLENGED) &&
(old_features & NETIF_F_VLAN_CHALLENGED))
pr_info("%s: last VLAN challenged slave %s left bond %s. VLAN blocking is removed\n",
bond_dev->name, slave_dev->name, bond_dev->name);
vlan_vids_del_by_dev(slave_dev, bond_dev);
if (!USES_PRIMARY(bond->params.mode)) {
if (old_flags & IFF_PROMISC)
dev_set_promiscuity(slave_dev, -1);
if (old_flags & IFF_ALLMULTI)
dev_set_allmulti(slave_dev, -1);
bond_hw_addr_flush(bond_dev, slave_dev);
}
slave_disable_netpoll(slave);
dev_close(slave_dev);
if (bond->params.fail_over_mac != BOND_FOM_ACTIVE) {
memcpy(addr.sa_data, slave->perm_hwaddr, ETH_ALEN);
addr.sa_family = slave_dev->type;
dev_set_mac_address(slave_dev, &addr);
}
dev_set_mtu(slave_dev, slave->original_mtu);
slave_dev->priv_flags &= ~IFF_BONDING;
kfree(slave);
return 0;
}
int bond_release(struct net_device *bond_dev, struct net_device *slave_dev)
{
return __bond_release_one(bond_dev, slave_dev, false);
}
static int bond_release_and_destroy(struct net_device *bond_dev,
struct net_device *slave_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
int ret;
ret = bond_release(bond_dev, slave_dev);
if (ret == 0 && !bond_has_slaves(bond)) {
bond_dev->priv_flags |= IFF_DISABLE_NETPOLL;
pr_info("%s: destroying bond %s.\n",
bond_dev->name, bond_dev->name);
unregister_netdevice(bond_dev);
}
return ret;
}
static int bond_info_query(struct net_device *bond_dev, struct ifbond *info)
{
struct bonding *bond = netdev_priv(bond_dev);
info->bond_mode = bond->params.mode;
info->miimon = bond->params.miimon;
read_lock(&bond->lock);
info->num_slaves = bond->slave_cnt;
read_unlock(&bond->lock);
return 0;
}
static int bond_slave_info_query(struct net_device *bond_dev, struct ifslave *info)
{
struct bonding *bond = netdev_priv(bond_dev);
struct list_head *iter;
int i = 0, res = -ENODEV;
struct slave *slave;
read_lock(&bond->lock);
bond_for_each_slave(bond, slave, iter) {
if (i++ == (int)info->slave_id) {
res = 0;
strcpy(info->slave_name, slave->dev->name);
info->link = slave->link;
info->state = bond_slave_state(slave);
info->link_failure_count = slave->link_failure_count;
break;
}
}
read_unlock(&bond->lock);
return res;
}
static int bond_miimon_inspect(struct bonding *bond)
{
int link_state, commit = 0;
struct list_head *iter;
struct slave *slave;
bool ignore_updelay;
ignore_updelay = !bond->curr_active_slave ? true : false;
bond_for_each_slave(bond, slave, iter) {
slave->new_link = BOND_LINK_NOCHANGE;
link_state = bond_check_dev_link(bond, slave->dev, 0);
switch (slave->link) {
case BOND_LINK_UP:
if (link_state)
continue;
slave->link = BOND_LINK_FAIL;
slave->delay = bond->params.downdelay;
if (slave->delay) {
pr_info("%s: link status down for %sinterface %s, disabling it in %d ms.\n",
bond->dev->name,
(bond->params.mode ==
BOND_MODE_ACTIVEBACKUP) ?
(bond_is_active_slave(slave) ?
"active " : "backup ") : "",
slave->dev->name,
bond->params.downdelay * bond->params.miimon);
}
case BOND_LINK_FAIL:
if (link_state) {
slave->link = BOND_LINK_UP;
slave->jiffies = jiffies;
pr_info("%s: link status up again after %d ms for interface %s.\n",
bond->dev->name,
(bond->params.downdelay - slave->delay) *
bond->params.miimon,
slave->dev->name);
continue;
}
if (slave->delay <= 0) {
slave->new_link = BOND_LINK_DOWN;
commit++;
continue;
}
slave->delay--;
break;
case BOND_LINK_DOWN:
if (!link_state)
continue;
slave->link = BOND_LINK_BACK;
slave->delay = bond->params.updelay;
if (slave->delay) {
pr_info("%s: link status up for interface %s, enabling it in %d ms.\n",
bond->dev->name, slave->dev->name,
ignore_updelay ? 0 :
bond->params.updelay *
bond->params.miimon);
}
case BOND_LINK_BACK:
if (!link_state) {
slave->link = BOND_LINK_DOWN;
pr_info("%s: link status down again after %d ms for interface %s.\n",
bond->dev->name,
(bond->params.updelay - slave->delay) *
bond->params.miimon,
slave->dev->name);
continue;
}
if (ignore_updelay)
slave->delay = 0;
if (slave->delay <= 0) {
slave->new_link = BOND_LINK_UP;
commit++;
ignore_updelay = false;
continue;
}
slave->delay--;
break;
}
}
return commit;
}
static void bond_miimon_commit(struct bonding *bond)
{
struct list_head *iter;
struct slave *slave;
bond_for_each_slave(bond, slave, iter) {
switch (slave->new_link) {
case BOND_LINK_NOCHANGE:
continue;
case BOND_LINK_UP:
slave->link = BOND_LINK_UP;
slave->jiffies = jiffies;
if (bond->params.mode == BOND_MODE_8023AD) {
bond_set_backup_slave(slave);
} else if (bond->params.mode != BOND_MODE_ACTIVEBACKUP) {
bond_set_active_slave(slave);
} else if (slave != bond->primary_slave) {
bond_set_backup_slave(slave);
}
pr_info("%s: link status definitely up for interface %s, %u Mbps %s duplex.\n",
bond->dev->name, slave->dev->name,
slave->speed == SPEED_UNKNOWN ? 0 : slave->speed,
slave->duplex ? "full" : "half");
if (bond->params.mode == BOND_MODE_8023AD)
bond_3ad_handle_link_change(slave, BOND_LINK_UP);
if (bond_is_lb(bond))
bond_alb_handle_link_change(bond, slave,
BOND_LINK_UP);
if (!bond->curr_active_slave ||
(slave == bond->primary_slave))
goto do_failover;
continue;
case BOND_LINK_DOWN:
if (slave->link_failure_count < UINT_MAX)
slave->link_failure_count++;
slave->link = BOND_LINK_DOWN;
if (bond->params.mode == BOND_MODE_ACTIVEBACKUP ||
bond->params.mode == BOND_MODE_8023AD)
bond_set_slave_inactive_flags(slave);
pr_info("%s: link status definitely down for interface %s, disabling it\n",
bond->dev->name, slave->dev->name);
if (bond->params.mode == BOND_MODE_8023AD)
bond_3ad_handle_link_change(slave,
BOND_LINK_DOWN);
if (bond_is_lb(bond))
bond_alb_handle_link_change(bond, slave,
BOND_LINK_DOWN);
if (slave == bond->curr_active_slave)
goto do_failover;
continue;
default:
pr_err("%s: invalid new link %d on slave %s\n",
bond->dev->name, slave->new_link,
slave->dev->name);
slave->new_link = BOND_LINK_NOCHANGE;
continue;
}
do_failover:
ASSERT_RTNL();
block_netpoll_tx();
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
unblock_netpoll_tx();
}
bond_set_carrier(bond);
}
void bond_mii_monitor(struct work_struct *work)
{
struct bonding *bond = container_of(work, struct bonding,
mii_work.work);
bool should_notify_peers = false;
unsigned long delay;
read_lock(&bond->lock);
delay = msecs_to_jiffies(bond->params.miimon);
if (!bond_has_slaves(bond))
goto re_arm;
should_notify_peers = bond_should_notify_peers(bond);
if (bond_miimon_inspect(bond)) {
read_unlock(&bond->lock);
if (!rtnl_trylock()) {
read_lock(&bond->lock);
delay = 1;
should_notify_peers = false;
goto re_arm;
}
read_lock(&bond->lock);
bond_miimon_commit(bond);
read_unlock(&bond->lock);
rtnl_unlock();
read_lock(&bond->lock);
}
re_arm:
if (bond->params.miimon)
queue_delayed_work(bond->wq, &bond->mii_work, delay);
read_unlock(&bond->lock);
if (should_notify_peers) {
if (!rtnl_trylock())
return;
call_netdevice_notifiers(NETDEV_NOTIFY_PEERS, bond->dev);
rtnl_unlock();
}
}
static bool bond_has_this_ip(struct bonding *bond, __be32 ip)
{
struct net_device *upper;
struct list_head *iter;
bool ret = false;
if (ip == bond_confirm_addr(bond->dev, 0, ip))
return true;
rcu_read_lock();
netdev_for_each_all_upper_dev_rcu(bond->dev, upper, iter) {
if (ip == bond_confirm_addr(upper, 0, ip)) {
ret = true;
break;
}
}
rcu_read_unlock();
return ret;
}
static void bond_arp_send(struct net_device *slave_dev, int arp_op, __be32 dest_ip, __be32 src_ip, unsigned short vlan_id)
{
struct sk_buff *skb;
pr_debug("arp %d on slave %s: dst %pI4 src %pI4 vid %d\n", arp_op,
slave_dev->name, &dest_ip, &src_ip, vlan_id);
skb = arp_create(arp_op, ETH_P_ARP, dest_ip, slave_dev, src_ip,
NULL, slave_dev->dev_addr, NULL);
if (!skb) {
pr_err("ARP packet allocation failed\n");
return;
}
if (vlan_id) {
skb = vlan_put_tag(skb, htons(ETH_P_8021Q), vlan_id);
if (!skb) {
pr_err("failed to insert VLAN tag\n");
return;
}
}
arp_xmit(skb);
}
static void bond_arp_send_all(struct bonding *bond, struct slave *slave)
{
struct net_device *upper, *vlan_upper;
struct list_head *iter, *vlan_iter;
struct rtable *rt;
__be32 *targets = bond->params.arp_targets, addr;
int i, vlan_id;
for (i = 0; i < BOND_MAX_ARP_TARGETS && targets[i]; i++) {
pr_debug("basa: target %pI4\n", &targets[i]);
rt = ip_route_output(dev_net(bond->dev), targets[i], 0,
RTO_ONLINK, 0);
if (IS_ERR(rt)) {
pr_debug("%s: no route to arp_ip_target %pI4\n",
bond->dev->name, &targets[i]);
continue;
}
vlan_id = 0;
if (rt->dst.dev == bond->dev)
goto found;
rcu_read_lock();
netdev_for_each_all_upper_dev_rcu(bond->dev, vlan_upper,
vlan_iter) {
if (!is_vlan_dev(vlan_upper))
continue;
netdev_for_each_all_upper_dev_rcu(vlan_upper, upper,
iter) {
if (upper == rt->dst.dev) {
vlan_id = vlan_dev_vlan_id(vlan_upper);
rcu_read_unlock();
goto found;
}
}
}
netdev_for_each_all_upper_dev_rcu(bond->dev, upper, iter) {
if (upper == rt->dst.dev) {
if (is_vlan_dev(upper))
vlan_id = vlan_dev_vlan_id(upper);
rcu_read_unlock();
goto found;
}
}
rcu_read_unlock();
pr_debug("%s: no path to arp_ip_target %pI4 via rt.dev %s\n",
bond->dev->name, &targets[i],
rt->dst.dev ? rt->dst.dev->name : "NULL");
ip_rt_put(rt);
continue;
found:
addr = bond_confirm_addr(rt->dst.dev, targets[i], 0);
ip_rt_put(rt);
bond_arp_send(slave->dev, ARPOP_REQUEST, targets[i],
addr, vlan_id);
}
}
static void bond_validate_arp(struct bonding *bond, struct slave *slave, __be32 sip, __be32 tip)
{
int i;
if (!sip || !bond_has_this_ip(bond, tip)) {
pr_debug("bva: sip %pI4 tip %pI4 not found\n", &sip, &tip);
return;
}
i = bond_get_targets_ip(bond->params.arp_targets, sip);
if (i == -1) {
pr_debug("bva: sip %pI4 not found in targets\n", &sip);
return;
}
slave->last_arp_rx = jiffies;
slave->target_last_arp_rx[i] = jiffies;
}
int bond_arp_rcv(const struct sk_buff *skb, struct bonding *bond,
struct slave *slave)
{
struct arphdr *arp = (struct arphdr *)skb->data;
unsigned char *arp_ptr;
__be32 sip, tip;
int alen;
if (skb->protocol != __cpu_to_be16(ETH_P_ARP))
return RX_HANDLER_ANOTHER;
read_lock(&bond->lock);
if (!slave_do_arp_validate(bond, slave))
goto out_unlock;
alen = arp_hdr_len(bond->dev);
pr_debug("bond_arp_rcv: bond %s skb->dev %s\n",
bond->dev->name, skb->dev->name);
if (alen > skb_headlen(skb)) {
arp = kmalloc(alen, GFP_ATOMIC);
if (!arp)
goto out_unlock;
if (skb_copy_bits(skb, 0, arp, alen) < 0)
goto out_unlock;
}
if (arp->ar_hln != bond->dev->addr_len ||
skb->pkt_type == PACKET_OTHERHOST ||
skb->pkt_type == PACKET_LOOPBACK ||
arp->ar_hrd != htons(ARPHRD_ETHER) ||
arp->ar_pro != htons(ETH_P_IP) ||
arp->ar_pln != 4)
goto out_unlock;
arp_ptr = (unsigned char *)(arp + 1);
arp_ptr += bond->dev->addr_len;
memcpy(&sip, arp_ptr, 4);
arp_ptr += 4 + bond->dev->addr_len;
memcpy(&tip, arp_ptr, 4);
pr_debug("bond_arp_rcv: %s %s/%d av %d sv %d sip %pI4 tip %pI4\n",
bond->dev->name, slave->dev->name, bond_slave_state(slave),
bond->params.arp_validate, slave_do_arp_validate(bond, slave),
&sip, &tip);
if (bond_is_active_slave(slave))
bond_validate_arp(bond, slave, sip, tip);
else if (bond->curr_active_slave &&
time_after(slave_last_rx(bond, bond->curr_active_slave),
bond->curr_active_slave->jiffies))
bond_validate_arp(bond, slave, tip, sip);
out_unlock:
read_unlock(&bond->lock);
if (arp != (struct arphdr *)skb->data)
kfree(arp);
return RX_HANDLER_ANOTHER;
}
static bool bond_time_in_interval(struct bonding *bond, unsigned long last_act,
int mod)
{
int delta_in_ticks = msecs_to_jiffies(bond->params.arp_interval);
return time_in_range(jiffies,
last_act - delta_in_ticks,
last_act + mod * delta_in_ticks + delta_in_ticks/2);
}
void bond_loadbalance_arp_mon(struct work_struct *work)
{
struct bonding *bond = container_of(work, struct bonding,
arp_work.work);
struct slave *slave, *oldcurrent;
struct list_head *iter;
int do_failover = 0;
read_lock(&bond->lock);
if (!bond_has_slaves(bond))
goto re_arm;
oldcurrent = bond->curr_active_slave;
bond_for_each_slave(bond, slave, iter) {
unsigned long trans_start = dev_trans_start(slave->dev);
if (slave->link != BOND_LINK_UP) {
if (bond_time_in_interval(bond, trans_start, 1) &&
bond_time_in_interval(bond, slave->dev->last_rx, 1)) {
slave->link = BOND_LINK_UP;
bond_set_active_slave(slave);
if (!oldcurrent) {
pr_info("%s: link status definitely up for interface %s, ",
bond->dev->name,
slave->dev->name);
do_failover = 1;
} else {
pr_info("%s: interface %s is now up\n",
bond->dev->name,
slave->dev->name);
}
}
} else {
if (!bond_time_in_interval(bond, trans_start, 2) ||
!bond_time_in_interval(bond, slave->dev->last_rx, 2)) {
slave->link = BOND_LINK_DOWN;
bond_set_backup_slave(slave);
if (slave->link_failure_count < UINT_MAX)
slave->link_failure_count++;
pr_info("%s: interface %s is now down.\n",
bond->dev->name,
slave->dev->name);
if (slave == oldcurrent)
do_failover = 1;
}
}
if (IS_UP(slave->dev))
bond_arp_send_all(bond, slave);
}
if (do_failover) {
block_netpoll_tx();
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
unblock_netpoll_tx();
}
re_arm:
if (bond->params.arp_interval)
queue_delayed_work(bond->wq, &bond->arp_work,
msecs_to_jiffies(bond->params.arp_interval));
read_unlock(&bond->lock);
}
static int bond_ab_arp_inspect(struct bonding *bond)
{
unsigned long trans_start, last_rx;
struct list_head *iter;
struct slave *slave;
int commit = 0;
bond_for_each_slave(bond, slave, iter) {
slave->new_link = BOND_LINK_NOCHANGE;
last_rx = slave_last_rx(bond, slave);
if (slave->link != BOND_LINK_UP) {
if (bond_time_in_interval(bond, last_rx, 1)) {
slave->new_link = BOND_LINK_UP;
commit++;
}
continue;
}
if (bond_time_in_interval(bond, slave->jiffies, 2))
continue;
if (!bond_is_active_slave(slave) &&
!bond->current_arp_slave &&
!bond_time_in_interval(bond, last_rx, 3)) {
slave->new_link = BOND_LINK_DOWN;
commit++;
}
trans_start = dev_trans_start(slave->dev);
if (bond_is_active_slave(slave) &&
(!bond_time_in_interval(bond, trans_start, 2) ||
!bond_time_in_interval(bond, last_rx, 2))) {
slave->new_link = BOND_LINK_DOWN;
commit++;
}
}
return commit;
}
static void bond_ab_arp_commit(struct bonding *bond)
{
unsigned long trans_start;
struct list_head *iter;
struct slave *slave;
bond_for_each_slave(bond, slave, iter) {
switch (slave->new_link) {
case BOND_LINK_NOCHANGE:
continue;
case BOND_LINK_UP:
trans_start = dev_trans_start(slave->dev);
if (bond->curr_active_slave != slave ||
(!bond->curr_active_slave &&
bond_time_in_interval(bond, trans_start, 1))) {
slave->link = BOND_LINK_UP;
if (bond->current_arp_slave) {
bond_set_slave_inactive_flags(
bond->current_arp_slave);
bond->current_arp_slave = NULL;
}
pr_info("%s: link status definitely up for interface %s.\n",
bond->dev->name, slave->dev->name);
if (!bond->curr_active_slave ||
(slave == bond->primary_slave))
goto do_failover;
}
continue;
case BOND_LINK_DOWN:
if (slave->link_failure_count < UINT_MAX)
slave->link_failure_count++;
slave->link = BOND_LINK_DOWN;
bond_set_slave_inactive_flags(slave);
pr_info("%s: link status definitely down for interface %s, disabling it\n",
bond->dev->name, slave->dev->name);
if (slave == bond->curr_active_slave) {
bond->current_arp_slave = NULL;
goto do_failover;
}
continue;
default:
pr_err("%s: impossible: new_link %d on slave %s\n",
bond->dev->name, slave->new_link,
slave->dev->name);
continue;
}
do_failover:
ASSERT_RTNL();
block_netpoll_tx();
write_lock_bh(&bond->curr_slave_lock);
bond_select_active_slave(bond);
write_unlock_bh(&bond->curr_slave_lock);
unblock_netpoll_tx();
}
bond_set_carrier(bond);
}
static void bond_ab_arp_probe(struct bonding *bond)
{
struct slave *slave, *before = NULL, *new_slave = NULL;
struct list_head *iter;
bool found = false;
read_lock(&bond->curr_slave_lock);
if (bond->current_arp_slave && bond->curr_active_slave)
pr_info("PROBE: c_arp %s && cas %s BAD\n",
bond->current_arp_slave->dev->name,
bond->curr_active_slave->dev->name);
if (bond->curr_active_slave) {
bond_arp_send_all(bond, bond->curr_active_slave);
read_unlock(&bond->curr_slave_lock);
return;
}
read_unlock(&bond->curr_slave_lock);
if (!bond->current_arp_slave) {
bond->current_arp_slave = bond_first_slave(bond);
if (!bond->current_arp_slave)
return;
}
bond_set_slave_inactive_flags(bond->current_arp_slave);
bond_for_each_slave(bond, slave, iter) {
if (!found && !before && IS_UP(slave->dev))
before = slave;
if (found && !new_slave && IS_UP(slave->dev))
new_slave = slave;
if (!IS_UP(slave->dev) && slave->link == BOND_LINK_UP) {
slave->link = BOND_LINK_DOWN;
if (slave->link_failure_count < UINT_MAX)
slave->link_failure_count++;
bond_set_slave_inactive_flags(slave);
pr_info("%s: backup interface %s is now down.\n",
bond->dev->name, slave->dev->name);
}
if (slave == bond->current_arp_slave)
found = true;
}
if (!new_slave && before)
new_slave = before;
if (!new_slave)
return;
new_slave->link = BOND_LINK_BACK;
bond_set_slave_active_flags(new_slave);
bond_arp_send_all(bond, new_slave);
new_slave->jiffies = jiffies;
bond->current_arp_slave = new_slave;
}
void bond_activebackup_arp_mon(struct work_struct *work)
{
struct bonding *bond = container_of(work, struct bonding,
arp_work.work);
bool should_notify_peers = false;
int delta_in_ticks;
read_lock(&bond->lock);
delta_in_ticks = msecs_to_jiffies(bond->params.arp_interval);
if (!bond_has_slaves(bond))
goto re_arm;
should_notify_peers = bond_should_notify_peers(bond);
if (bond_ab_arp_inspect(bond)) {
read_unlock(&bond->lock);
if (!rtnl_trylock()) {
read_lock(&bond->lock);
delta_in_ticks = 1;
should_notify_peers = false;
goto re_arm;
}
read_lock(&bond->lock);
bond_ab_arp_commit(bond);
read_unlock(&bond->lock);
rtnl_unlock();
read_lock(&bond->lock);
}
bond_ab_arp_probe(bond);
re_arm:
if (bond->params.arp_interval)
queue_delayed_work(bond->wq, &bond->arp_work, delta_in_ticks);
read_unlock(&bond->lock);
if (should_notify_peers) {
if (!rtnl_trylock())
return;
call_netdevice_notifiers(NETDEV_NOTIFY_PEERS, bond->dev);
rtnl_unlock();
}
}
static int bond_event_changename(struct bonding *bond)
{
bond_remove_proc_entry(bond);
bond_create_proc_entry(bond);
bond_debug_reregister(bond);
return NOTIFY_DONE;
}
static int bond_master_netdev_event(unsigned long event,
struct net_device *bond_dev)
{
struct bonding *event_bond = netdev_priv(bond_dev);
switch (event) {
case NETDEV_CHANGENAME:
return bond_event_changename(event_bond);
case NETDEV_UNREGISTER:
bond_remove_proc_entry(event_bond);
break;
case NETDEV_REGISTER:
bond_create_proc_entry(event_bond);
break;
case NETDEV_NOTIFY_PEERS:
if (event_bond->send_peer_notif)
event_bond->send_peer_notif--;
break;
default:
break;
}
return NOTIFY_DONE;
}
static int bond_slave_netdev_event(unsigned long event,
struct net_device *slave_dev)
{
struct slave *slave = bond_slave_get_rtnl(slave_dev);
struct bonding *bond;
struct net_device *bond_dev;
u32 old_speed;
u8 old_duplex;
if (!slave)
return NOTIFY_DONE;
bond_dev = slave->bond->dev;
bond = slave->bond;
switch (event) {
case NETDEV_UNREGISTER:
if (bond_dev->type != ARPHRD_ETHER)
bond_release_and_destroy(bond_dev, slave_dev);
else
bond_release(bond_dev, slave_dev);
break;
case NETDEV_UP:
case NETDEV_CHANGE:
old_speed = slave->speed;
old_duplex = slave->duplex;
bond_update_speed_duplex(slave);
if (bond->params.mode == BOND_MODE_8023AD) {
if (old_speed != slave->speed)
bond_3ad_adapter_speed_changed(slave);
if (old_duplex != slave->duplex)
bond_3ad_adapter_duplex_changed(slave);
}
break;
case NETDEV_DOWN:
break;
case NETDEV_CHANGEMTU:
break;
case NETDEV_CHANGENAME:
break;
case NETDEV_FEAT_CHANGE:
bond_compute_features(bond);
break;
case NETDEV_RESEND_IGMP:
call_netdevice_notifiers(event, slave->bond->dev);
break;
default:
break;
}
return NOTIFY_DONE;
}
static int bond_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *event_dev = netdev_notifier_info_to_dev(ptr);
pr_debug("event_dev: %s, event: %lx\n",
event_dev ? event_dev->name : "None",
event);
if (!(event_dev->priv_flags & IFF_BONDING))
return NOTIFY_DONE;
if (event_dev->flags & IFF_MASTER) {
pr_debug("IFF_MASTER\n");
return bond_master_netdev_event(event, event_dev);
}
if (event_dev->flags & IFF_SLAVE) {
pr_debug("IFF_SLAVE\n");
return bond_slave_netdev_event(event, event_dev);
}
return NOTIFY_DONE;
}
static inline u32 bond_eth_hash(struct sk_buff *skb)
{
struct ethhdr *data = (struct ethhdr *)skb->data;
if (skb_headlen(skb) >= offsetof(struct ethhdr, h_proto))
return data->h_dest[5] ^ data->h_source[5];
return 0;
}
static bool bond_flow_dissect(struct bonding *bond, struct sk_buff *skb,
struct flow_keys *fk)
{
const struct ipv6hdr *iph6;
const struct iphdr *iph;
int noff, proto = -1;
if (bond->params.xmit_policy > BOND_XMIT_POLICY_LAYER23)
return skb_flow_dissect(skb, fk);
fk->ports = 0;
noff = skb_network_offset(skb);
if (skb->protocol == htons(ETH_P_IP)) {
if (!pskb_may_pull(skb, noff + sizeof(*iph)))
return false;
iph = ip_hdr(skb);
fk->src = iph->saddr;
fk->dst = iph->daddr;
noff += iph->ihl << 2;
if (!ip_is_fragment(iph))
proto = iph->protocol;
} else if (skb->protocol == htons(ETH_P_IPV6)) {
if (!pskb_may_pull(skb, noff + sizeof(*iph6)))
return false;
iph6 = ipv6_hdr(skb);
fk->src = (__force __be32)ipv6_addr_hash(&iph6->saddr);
fk->dst = (__force __be32)ipv6_addr_hash(&iph6->daddr);
noff += sizeof(*iph6);
proto = iph6->nexthdr;
} else {
return false;
}
if (bond->params.xmit_policy == BOND_XMIT_POLICY_LAYER34 && proto >= 0)
fk->ports = skb_flow_get_ports(skb, noff, proto);
return true;
}
int bond_xmit_hash(struct bonding *bond, struct sk_buff *skb, int count)
{
struct flow_keys flow;
u32 hash;
if (bond->params.xmit_policy == BOND_XMIT_POLICY_LAYER2 ||
!bond_flow_dissect(bond, skb, &flow))
return bond_eth_hash(skb) % count;
if (bond->params.xmit_policy == BOND_XMIT_POLICY_LAYER23 ||
bond->params.xmit_policy == BOND_XMIT_POLICY_ENCAP23)
hash = bond_eth_hash(skb);
else
hash = (__force u32)flow.ports;
hash ^= (__force u32)flow.dst ^ (__force u32)flow.src;
hash ^= (hash >> 16);
hash ^= (hash >> 8);
return hash % count;
}
static void bond_work_init_all(struct bonding *bond)
{
INIT_DELAYED_WORK(&bond->mcast_work,
bond_resend_igmp_join_requests_delayed);
INIT_DELAYED_WORK(&bond->alb_work, bond_alb_monitor);
INIT_DELAYED_WORK(&bond->mii_work, bond_mii_monitor);
if (bond->params.mode == BOND_MODE_ACTIVEBACKUP)
INIT_DELAYED_WORK(&bond->arp_work, bond_activebackup_arp_mon);
else
INIT_DELAYED_WORK(&bond->arp_work, bond_loadbalance_arp_mon);
INIT_DELAYED_WORK(&bond->ad_work, bond_3ad_state_machine_handler);
}
static void bond_work_cancel_all(struct bonding *bond)
{
cancel_delayed_work_sync(&bond->mii_work);
cancel_delayed_work_sync(&bond->arp_work);
cancel_delayed_work_sync(&bond->alb_work);
cancel_delayed_work_sync(&bond->ad_work);
cancel_delayed_work_sync(&bond->mcast_work);
}
static int bond_open(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct list_head *iter;
struct slave *slave;
read_lock(&bond->lock);
if (bond_has_slaves(bond)) {
read_lock(&bond->curr_slave_lock);
bond_for_each_slave(bond, slave, iter) {
if ((bond->params.mode == BOND_MODE_ACTIVEBACKUP)
&& (slave != bond->curr_active_slave)) {
bond_set_slave_inactive_flags(slave);
} else {
bond_set_slave_active_flags(slave);
}
}
read_unlock(&bond->curr_slave_lock);
}
read_unlock(&bond->lock);
bond_work_init_all(bond);
if (bond_is_lb(bond)) {
if (bond_alb_initialize(bond, (bond->params.mode == BOND_MODE_ALB)))
return -ENOMEM;
queue_delayed_work(bond->wq, &bond->alb_work, 0);
}
if (bond->params.miimon)
queue_delayed_work(bond->wq, &bond->mii_work, 0);
if (bond->params.arp_interval) {
queue_delayed_work(bond->wq, &bond->arp_work, 0);
if (bond->params.arp_validate)
bond->recv_probe = bond_arp_rcv;
}
if (bond->params.mode == BOND_MODE_8023AD) {
queue_delayed_work(bond->wq, &bond->ad_work, 0);
bond->recv_probe = bond_3ad_lacpdu_recv;
bond_3ad_initiate_agg_selection(bond, 1);
}
return 0;
}
static int bond_close(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
bond_work_cancel_all(bond);
bond->send_peer_notif = 0;
if (bond_is_lb(bond))
bond_alb_deinitialize(bond);
bond->recv_probe = NULL;
return 0;
}
static struct rtnl_link_stats64 *bond_get_stats(struct net_device *bond_dev,
struct rtnl_link_stats64 *stats)
{
struct bonding *bond = netdev_priv(bond_dev);
struct rtnl_link_stats64 temp;
struct list_head *iter;
struct slave *slave;
memset(stats, 0, sizeof(*stats));
read_lock_bh(&bond->lock);
bond_for_each_slave(bond, slave, iter) {
const struct rtnl_link_stats64 *sstats =
dev_get_stats(slave->dev, &temp);
stats->rx_packets += sstats->rx_packets;
stats->rx_bytes += sstats->rx_bytes;
stats->rx_errors += sstats->rx_errors;
stats->rx_dropped += sstats->rx_dropped;
stats->tx_packets += sstats->tx_packets;
stats->tx_bytes += sstats->tx_bytes;
stats->tx_errors += sstats->tx_errors;
stats->tx_dropped += sstats->tx_dropped;
stats->multicast += sstats->multicast;
stats->collisions += sstats->collisions;
stats->rx_length_errors += sstats->rx_length_errors;
stats->rx_over_errors += sstats->rx_over_errors;
stats->rx_crc_errors += sstats->rx_crc_errors;
stats->rx_frame_errors += sstats->rx_frame_errors;
stats->rx_fifo_errors += sstats->rx_fifo_errors;
stats->rx_missed_errors += sstats->rx_missed_errors;
stats->tx_aborted_errors += sstats->tx_aborted_errors;
stats->tx_carrier_errors += sstats->tx_carrier_errors;
stats->tx_fifo_errors += sstats->tx_fifo_errors;
stats->tx_heartbeat_errors += sstats->tx_heartbeat_errors;
stats->tx_window_errors += sstats->tx_window_errors;
}
read_unlock_bh(&bond->lock);
return stats;
}
static int bond_do_ioctl(struct net_device *bond_dev, struct ifreq *ifr, int cmd)
{
struct bonding *bond = netdev_priv(bond_dev);
struct net_device *slave_dev = NULL;
struct ifbond k_binfo;
struct ifbond __user *u_binfo = NULL;
struct ifslave k_sinfo;
struct ifslave __user *u_sinfo = NULL;
struct mii_ioctl_data *mii = NULL;
struct net *net;
int res = 0;
pr_debug("bond_ioctl: master=%s, cmd=%d\n", bond_dev->name, cmd);
switch (cmd) {
case SIOCGMIIPHY:
mii = if_mii(ifr);
if (!mii)
return -EINVAL;
mii->phy_id = 0;
case SIOCGMIIREG:
mii = if_mii(ifr);
if (!mii)
return -EINVAL;
if (mii->reg_num == 1) {
mii->val_out = 0;
read_lock(&bond->lock);
read_lock(&bond->curr_slave_lock);
if (netif_carrier_ok(bond->dev))
mii->val_out = BMSR_LSTATUS;
read_unlock(&bond->curr_slave_lock);
read_unlock(&bond->lock);
}
return 0;
case BOND_INFO_QUERY_OLD:
case SIOCBONDINFOQUERY:
u_binfo = (struct ifbond __user *)ifr->ifr_data;
if (copy_from_user(&k_binfo, u_binfo, sizeof(ifbond)))
return -EFAULT;
res = bond_info_query(bond_dev, &k_binfo);
if (res == 0 &&
copy_to_user(u_binfo, &k_binfo, sizeof(ifbond)))
return -EFAULT;
return res;
case BOND_SLAVE_INFO_QUERY_OLD:
case SIOCBONDSLAVEINFOQUERY:
u_sinfo = (struct ifslave __user *)ifr->ifr_data;
if (copy_from_user(&k_sinfo, u_sinfo, sizeof(ifslave)))
return -EFAULT;
res = bond_slave_info_query(bond_dev, &k_sinfo);
if (res == 0 &&
copy_to_user(u_sinfo, &k_sinfo, sizeof(ifslave)))
return -EFAULT;
return res;
default:
break;
}
net = dev_net(bond_dev);
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
slave_dev = dev_get_by_name(net, ifr->ifr_slave);
pr_debug("slave_dev=%p:\n", slave_dev);
if (!slave_dev)
res = -ENODEV;
else {
pr_debug("slave_dev->name=%s:\n", slave_dev->name);
switch (cmd) {
case BOND_ENSLAVE_OLD:
case SIOCBONDENSLAVE:
res = bond_enslave(bond_dev, slave_dev);
break;
case BOND_RELEASE_OLD:
case SIOCBONDRELEASE:
res = bond_release(bond_dev, slave_dev);
break;
case BOND_SETHWADDR_OLD:
case SIOCBONDSETHWADDR:
bond_set_dev_addr(bond_dev, slave_dev);
res = 0;
break;
case BOND_CHANGE_ACTIVE_OLD:
case SIOCBONDCHANGEACTIVE:
res = bond_option_active_slave_set(bond, slave_dev);
break;
default:
res = -EOPNOTSUPP;
}
dev_put(slave_dev);
}
return res;
}
static void bond_change_rx_flags(struct net_device *bond_dev, int change)
{
struct bonding *bond = netdev_priv(bond_dev);
if (change & IFF_PROMISC)
bond_set_promiscuity(bond,
bond_dev->flags & IFF_PROMISC ? 1 : -1);
if (change & IFF_ALLMULTI)
bond_set_allmulti(bond,
bond_dev->flags & IFF_ALLMULTI ? 1 : -1);
}
static void bond_set_rx_mode(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct list_head *iter;
struct slave *slave;
rcu_read_lock();
if (USES_PRIMARY(bond->params.mode)) {
slave = rcu_dereference(bond->curr_active_slave);
if (slave) {
dev_uc_sync(slave->dev, bond_dev);
dev_mc_sync(slave->dev, bond_dev);
}
} else {
bond_for_each_slave_rcu(bond, slave, iter) {
dev_uc_sync_multiple(slave->dev, bond_dev);
dev_mc_sync_multiple(slave->dev, bond_dev);
}
}
rcu_read_unlock();
}
static int bond_neigh_init(struct neighbour *n)
{
struct bonding *bond = netdev_priv(n->dev);
const struct net_device_ops *slave_ops;
struct neigh_parms parms;
struct slave *slave;
int ret;
slave = bond_first_slave(bond);
if (!slave)
return 0;
slave_ops = slave->dev->netdev_ops;
if (!slave_ops->ndo_neigh_setup)
return 0;
parms.neigh_setup = NULL;
parms.neigh_cleanup = NULL;
ret = slave_ops->ndo_neigh_setup(slave->dev, &parms);
if (ret)
return ret;
n->parms->neigh_cleanup = parms.neigh_cleanup;
if (!parms.neigh_setup)
return 0;
return parms.neigh_setup(n);
}
static int bond_neigh_setup(struct net_device *dev,
struct neigh_parms *parms)
{
if (parms->dev == dev)
parms->neigh_setup = bond_neigh_init;
return 0;
}
static int bond_change_mtu(struct net_device *bond_dev, int new_mtu)
{
struct bonding *bond = netdev_priv(bond_dev);
struct slave *slave, *rollback_slave;
struct list_head *iter;
int res = 0;
pr_debug("bond=%p, name=%s, new_mtu=%d\n", bond,
(bond_dev ? bond_dev->name : "None"), new_mtu);
bond_for_each_slave(bond, slave, iter) {
pr_debug("s %p c_m %p\n",
slave,
slave->dev->netdev_ops->ndo_change_mtu);
res = dev_set_mtu(slave->dev, new_mtu);
if (res) {
pr_debug("err %d %s\n", res, slave->dev->name);
goto unwind;
}
}
bond_dev->mtu = new_mtu;
return 0;
unwind:
bond_for_each_slave(bond, rollback_slave, iter) {
int tmp_res;
if (rollback_slave == slave)
break;
tmp_res = dev_set_mtu(rollback_slave->dev, bond_dev->mtu);
if (tmp_res) {
pr_debug("unwind err %d dev %s\n",
tmp_res, rollback_slave->dev->name);
}
}
return res;
}
static int bond_set_mac_address(struct net_device *bond_dev, void *addr)
{
struct bonding *bond = netdev_priv(bond_dev);
struct slave *slave, *rollback_slave;
struct sockaddr *sa = addr, tmp_sa;
struct list_head *iter;
int res = 0;
if (bond->params.mode == BOND_MODE_ALB)
return bond_alb_set_mac_address(bond_dev, addr);
pr_debug("bond=%p, name=%s\n",
bond, bond_dev ? bond_dev->name : "None");
if (bond->params.fail_over_mac)
return 0;
if (!is_valid_ether_addr(sa->sa_data))
return -EADDRNOTAVAIL;
bond_for_each_slave(bond, slave, iter) {
const struct net_device_ops *slave_ops = slave->dev->netdev_ops;
pr_debug("slave %p %s\n", slave, slave->dev->name);
if (slave_ops->ndo_set_mac_address == NULL) {
res = -EOPNOTSUPP;
pr_debug("EOPNOTSUPP %s\n", slave->dev->name);
goto unwind;
}
res = dev_set_mac_address(slave->dev, addr);
if (res) {
pr_debug("err %d %s\n", res, slave->dev->name);
goto unwind;
}
}
memcpy(bond_dev->dev_addr, sa->sa_data, bond_dev->addr_len);
return 0;
unwind:
memcpy(tmp_sa.sa_data, bond_dev->dev_addr, bond_dev->addr_len);
tmp_sa.sa_family = bond_dev->type;
bond_for_each_slave(bond, rollback_slave, iter) {
int tmp_res;
if (rollback_slave == slave)
break;
tmp_res = dev_set_mac_address(rollback_slave->dev, &tmp_sa);
if (tmp_res) {
pr_debug("unwind err %d dev %s\n",
tmp_res, rollback_slave->dev->name);
}
}
return res;
}
void bond_xmit_slave_id(struct bonding *bond, struct sk_buff *skb, int slave_id)
{
struct list_head *iter;
struct slave *slave;
int i = slave_id;
bond_for_each_slave_rcu(bond, slave, iter) {
if (--i < 0) {
if (slave_can_tx(slave)) {
bond_dev_queue_xmit(bond, skb, slave->dev);
return;
}
}
}
i = slave_id;
bond_for_each_slave_rcu(bond, slave, iter) {
if (--i < 0)
break;
if (slave_can_tx(slave)) {
bond_dev_queue_xmit(bond, skb, slave->dev);
return;
}
}
kfree_skb(skb);
}
static u32 bond_rr_gen_slave_id(struct bonding *bond)
{
int packets_per_slave = bond->params.packets_per_slave;
u32 slave_id;
switch (packets_per_slave) {
case 0:
slave_id = prandom_u32();
break;
case 1:
slave_id = bond->rr_tx_counter;
break;
default:
slave_id = reciprocal_divide(bond->rr_tx_counter,
packets_per_slave);
break;
}
bond->rr_tx_counter++;
return slave_id;
}
static int bond_xmit_roundrobin(struct sk_buff *skb, struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct iphdr *iph = ip_hdr(skb);
struct slave *slave;
u32 slave_id;
if (iph->protocol == IPPROTO_IGMP && skb->protocol == htons(ETH_P_IP)) {
slave = rcu_dereference(bond->curr_active_slave);
if (slave && slave_can_tx(slave))
bond_dev_queue_xmit(bond, skb, slave->dev);
else
bond_xmit_slave_id(bond, skb, 0);
} else {
slave_id = bond_rr_gen_slave_id(bond);
bond_xmit_slave_id(bond, skb, slave_id % bond->slave_cnt);
}
return NETDEV_TX_OK;
}
static int bond_xmit_activebackup(struct sk_buff *skb, struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct slave *slave;
slave = rcu_dereference(bond->curr_active_slave);
if (slave)
bond_dev_queue_xmit(bond, skb, slave->dev);
else
kfree_skb(skb);
return NETDEV_TX_OK;
}
static int bond_xmit_xor(struct sk_buff *skb, struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
bond_xmit_slave_id(bond, skb, bond_xmit_hash(bond, skb, bond->slave_cnt));
return NETDEV_TX_OK;
}
static int bond_xmit_broadcast(struct sk_buff *skb, struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct slave *slave = NULL;
struct list_head *iter;
bond_for_each_slave_rcu(bond, slave, iter) {
if (bond_is_last_slave(bond, slave))
break;
if (IS_UP(slave->dev) && slave->link == BOND_LINK_UP) {
struct sk_buff *skb2 = skb_clone(skb, GFP_ATOMIC);
if (!skb2) {
pr_err("%s: Error: bond_xmit_broadcast(): skb_clone() failed\n",
bond_dev->name);
continue;
}
bond_dev_queue_xmit(bond, skb2, slave->dev);
}
}
if (slave && IS_UP(slave->dev) && slave->link == BOND_LINK_UP)
bond_dev_queue_xmit(bond, skb, slave->dev);
else
kfree_skb(skb);
return NETDEV_TX_OK;
}
static inline int bond_slave_override(struct bonding *bond,
struct sk_buff *skb)
{
struct slave *slave = NULL;
struct slave *check_slave;
struct list_head *iter;
int res = 1;
if (!skb->queue_mapping)
return 1;
bond_for_each_slave_rcu(bond, check_slave, iter) {
if (check_slave->queue_id == skb->queue_mapping) {
slave = check_slave;
break;
}
}
if (slave && slave->queue_id && IS_UP(slave->dev) &&
(slave->link == BOND_LINK_UP)) {
res = bond_dev_queue_xmit(bond, skb, slave->dev);
}
return res;
}
static u16 bond_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv)
{
u16 txq = skb_rx_queue_recorded(skb) ? skb_get_rx_queue(skb) : 0;
qdisc_skb_cb(skb)->slave_dev_queue_mapping = skb->queue_mapping;
if (unlikely(txq >= dev->real_num_tx_queues)) {
do {
txq -= dev->real_num_tx_queues;
} while (txq >= dev->real_num_tx_queues);
}
return txq;
}
static netdev_tx_t __bond_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bonding *bond = netdev_priv(dev);
if (TX_QUEUE_OVERRIDE(bond->params.mode)) {
if (!bond_slave_override(bond, skb))
return NETDEV_TX_OK;
}
switch (bond->params.mode) {
case BOND_MODE_ROUNDROBIN:
return bond_xmit_roundrobin(skb, dev);
case BOND_MODE_ACTIVEBACKUP:
return bond_xmit_activebackup(skb, dev);
case BOND_MODE_XOR:
return bond_xmit_xor(skb, dev);
case BOND_MODE_BROADCAST:
return bond_xmit_broadcast(skb, dev);
case BOND_MODE_8023AD:
return bond_3ad_xmit_xor(skb, dev);
case BOND_MODE_ALB:
case BOND_MODE_TLB:
return bond_alb_xmit(skb, dev);
default:
pr_err("%s: Error: Unknown bonding mode %d\n",
dev->name, bond->params.mode);
WARN_ON_ONCE(1);
kfree_skb(skb);
return NETDEV_TX_OK;
}
}
static netdev_tx_t bond_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bonding *bond = netdev_priv(dev);
netdev_tx_t ret = NETDEV_TX_OK;
if (is_netpoll_tx_blocked(dev))
return NETDEV_TX_BUSY;
rcu_read_lock();
if (bond_has_slaves(bond))
ret = __bond_start_xmit(skb, dev);
else
kfree_skb(skb);
rcu_read_unlock();
return ret;
}
static int bond_ethtool_get_settings(struct net_device *bond_dev,
struct ethtool_cmd *ecmd)
{
struct bonding *bond = netdev_priv(bond_dev);
unsigned long speed = 0;
struct list_head *iter;
struct slave *slave;
ecmd->duplex = DUPLEX_UNKNOWN;
ecmd->port = PORT_OTHER;
read_lock(&bond->lock);
bond_for_each_slave(bond, slave, iter) {
if (SLAVE_IS_OK(slave)) {
if (slave->speed != SPEED_UNKNOWN)
speed += slave->speed;
if (ecmd->duplex == DUPLEX_UNKNOWN &&
slave->duplex != DUPLEX_UNKNOWN)
ecmd->duplex = slave->duplex;
}
}
ethtool_cmd_speed_set(ecmd, speed ? : SPEED_UNKNOWN);
read_unlock(&bond->lock);
return 0;
}
static void bond_ethtool_get_drvinfo(struct net_device *bond_dev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, DRV_VERSION, sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version), "%d",
BOND_ABI_VERSION);
}
static void bond_destructor(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
if (bond->wq)
destroy_workqueue(bond->wq);
free_netdev(bond_dev);
}
void bond_setup(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
rwlock_init(&bond->lock);
rwlock_init(&bond->curr_slave_lock);
bond->params = bonding_defaults;
bond->dev = bond_dev;
ether_setup(bond_dev);
bond_dev->netdev_ops = &bond_netdev_ops;
bond_dev->ethtool_ops = &bond_ethtool_ops;
bond_dev->destructor = bond_destructor;
SET_NETDEV_DEVTYPE(bond_dev, &bond_type);
bond_dev->tx_queue_len = 0;
bond_dev->flags |= IFF_MASTER|IFF_MULTICAST;
bond_dev->priv_flags |= IFF_BONDING;
bond_dev->priv_flags &= ~(IFF_XMIT_DST_RELEASE | IFF_TX_SKB_SHARING);
bond_dev->features |= NETIF_F_VLAN_CHALLENGED;
bond_dev->features |= NETIF_F_LLTX;
bond_dev->hw_features = BOND_VLAN_FEATURES |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER;
bond_dev->hw_features &= ~(NETIF_F_ALL_CSUM & ~NETIF_F_HW_CSUM);
bond_dev->features |= bond_dev->hw_features;
}
static void bond_uninit(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct list_head *iter;
struct slave *slave;
bond_netpoll_cleanup(bond_dev);
bond_for_each_slave(bond, slave, iter)
__bond_release_one(bond_dev, slave->dev, true);
pr_info("%s: released all slaves\n", bond_dev->name);
list_del(&bond->bond_list);
bond_debug_unregister(bond);
}
int bond_parse_parm(const char *buf, const struct bond_parm_tbl *tbl)
{
int modeint = -1, i, rv;
char *p, modestr[BOND_MAX_MODENAME_LEN + 1] = { 0, };
for (p = (char *)buf; *p; p++)
if (!(isdigit(*p) || isspace(*p)))
break;
if (*p)
rv = sscanf(buf, "%20s", modestr);
else
rv = sscanf(buf, "%d", &modeint);
if (!rv)
return -1;
for (i = 0; tbl[i].modename; i++) {
if (modeint == tbl[i].mode)
return tbl[i].mode;
if (strcmp(modestr, tbl[i].modename) == 0)
return tbl[i].mode;
}
return -1;
}
static int bond_check_params(struct bond_params *params)
{
int arp_validate_value, fail_over_mac_value, primary_reselect_value, i;
int arp_all_targets_value;
if (mode) {
bond_mode = bond_parse_parm(mode, bond_mode_tbl);
if (bond_mode == -1) {
pr_err("Error: Invalid bonding mode \"%s\"\n",
mode == NULL ? "NULL" : mode);
return -EINVAL;
}
}
if (xmit_hash_policy) {
if ((bond_mode != BOND_MODE_XOR) &&
(bond_mode != BOND_MODE_8023AD)) {
pr_info("xmit_hash_policy param is irrelevant in mode %s\n",
bond_mode_name(bond_mode));
} else {
xmit_hashtype = bond_parse_parm(xmit_hash_policy,
xmit_hashtype_tbl);
if (xmit_hashtype == -1) {
pr_err("Error: Invalid xmit_hash_policy \"%s\"\n",
xmit_hash_policy == NULL ? "NULL" :
xmit_hash_policy);
return -EINVAL;
}
}
}
if (lacp_rate) {
if (bond_mode != BOND_MODE_8023AD) {
pr_info("lacp_rate param is irrelevant in mode %s\n",
bond_mode_name(bond_mode));
} else {
lacp_fast = bond_parse_parm(lacp_rate, bond_lacp_tbl);
if (lacp_fast == -1) {
pr_err("Error: Invalid lacp rate \"%s\"\n",
lacp_rate == NULL ? "NULL" : lacp_rate);
return -EINVAL;
}
}
}
if (ad_select) {
params->ad_select = bond_parse_parm(ad_select, ad_select_tbl);
if (params->ad_select == -1) {
pr_err("Error: Invalid ad_select \"%s\"\n",
ad_select == NULL ? "NULL" : ad_select);
return -EINVAL;
}
if (bond_mode != BOND_MODE_8023AD) {
pr_warning("ad_select param only affects 802.3ad mode\n");
}
} else {
params->ad_select = BOND_AD_STABLE;
}
if (max_bonds < 0) {
pr_warning("Warning: max_bonds (%d) not in range %d-%d, so it was reset to BOND_DEFAULT_MAX_BONDS (%d)\n",
max_bonds, 0, INT_MAX, BOND_DEFAULT_MAX_BONDS);
max_bonds = BOND_DEFAULT_MAX_BONDS;
}
if (miimon < 0) {
pr_warning("Warning: miimon module parameter (%d), not in range 0-%d, so it was reset to %d\n",
miimon, INT_MAX, BOND_LINK_MON_INTERV);
miimon = BOND_LINK_MON_INTERV;
}
if (updelay < 0) {
pr_warning("Warning: updelay module parameter (%d), not in range 0-%d, so it was reset to 0\n",
updelay, INT_MAX);
updelay = 0;
}
if (downdelay < 0) {
pr_warning("Warning: downdelay module parameter (%d), not in range 0-%d, so it was reset to 0\n",
downdelay, INT_MAX);
downdelay = 0;
}
if ((use_carrier != 0) && (use_carrier != 1)) {
pr_warning("Warning: use_carrier module parameter (%d), not of valid value (0/1), so it was set to 1\n",
use_carrier);
use_carrier = 1;
}
if (num_peer_notif < 0 || num_peer_notif > 255) {
pr_warning("Warning: num_grat_arp/num_unsol_na (%d) not in range 0-255 so it was reset to 1\n",
num_peer_notif);
num_peer_notif = 1;
}
if (bond_mode == BOND_MODE_8023AD) {
if (!miimon) {
pr_warning("Warning: miimon must be specified, otherwise bonding will not detect link failure, speed and duplex which are essential for 802.3ad operation\n");
pr_warning("Forcing miimon to 100msec\n");
miimon = BOND_DEFAULT_MIIMON;
}
}
if (tx_queues < 1 || tx_queues > 255) {
pr_warning("Warning: tx_queues (%d) should be between "
"1 and 255, resetting to %d\n",
tx_queues, BOND_DEFAULT_TX_QUEUES);
tx_queues = BOND_DEFAULT_TX_QUEUES;
}
if ((all_slaves_active != 0) && (all_slaves_active != 1)) {
pr_warning("Warning: all_slaves_active module parameter (%d), "
"not of valid value (0/1), so it was set to "
"0\n", all_slaves_active);
all_slaves_active = 0;
}
if (resend_igmp < 0 || resend_igmp > 255) {
pr_warning("Warning: resend_igmp (%d) should be between "
"0 and 255, resetting to %d\n",
resend_igmp, BOND_DEFAULT_RESEND_IGMP);
resend_igmp = BOND_DEFAULT_RESEND_IGMP;
}
if (packets_per_slave < 0 || packets_per_slave > USHRT_MAX) {
pr_warn("Warning: packets_per_slave (%d) should be between 0 and %u resetting to 1\n",
packets_per_slave, USHRT_MAX);
packets_per_slave = 1;
}
if ((bond_mode == BOND_MODE_TLB) ||
(bond_mode == BOND_MODE_ALB)) {
if (!miimon) {
pr_warning("Warning: miimon must be specified, otherwise bonding will not detect link failure and link speed which are essential for TLB/ALB load balancing\n");
pr_warning("Forcing miimon to 100msec\n");
miimon = BOND_DEFAULT_MIIMON;
}
}
if (bond_mode == BOND_MODE_ALB) {
pr_notice("In ALB mode you might experience client disconnections upon reconnection of a link if the bonding module updelay parameter (%d msec) is incompatible with the forwarding delay time of the switch\n",
updelay);
}
if (!miimon) {
if (updelay || downdelay) {
pr_warning("Warning: miimon module parameter not set and updelay (%d) or downdelay (%d) module parameter is set; updelay and downdelay have no effect unless miimon is set\n",
updelay, downdelay);
}
} else {
if (arp_interval) {
pr_warning("Warning: miimon (%d) and arp_interval (%d) can't be used simultaneously, disabling ARP monitoring\n",
miimon, arp_interval);
arp_interval = 0;
}
if ((updelay % miimon) != 0) {
pr_warning("Warning: updelay (%d) is not a multiple of miimon (%d), updelay rounded to %d ms\n",
updelay, miimon,
(updelay / miimon) * miimon);
}
updelay /= miimon;
if ((downdelay % miimon) != 0) {
pr_warning("Warning: downdelay (%d) is not a multiple of miimon (%d), downdelay rounded to %d ms\n",
downdelay, miimon,
(downdelay / miimon) * miimon);
}
downdelay /= miimon;
}
if (arp_interval < 0) {
pr_warning("Warning: arp_interval module parameter (%d) , not in range 0-%d, so it was reset to %d\n",
arp_interval, INT_MAX, BOND_LINK_ARP_INTERV);
arp_interval = BOND_LINK_ARP_INTERV;
}
for (arp_ip_count = 0, i = 0;
(arp_ip_count < BOND_MAX_ARP_TARGETS) && arp_ip_target[i]; i++) {
__be32 ip;
if (!in4_pton(arp_ip_target[i], -1, (u8 *)&ip, -1, NULL) ||
IS_IP_TARGET_UNUSABLE_ADDRESS(ip)) {
pr_warning("Warning: bad arp_ip_target module parameter (%s), ARP monitoring will not be performed\n",
arp_ip_target[i]);
arp_interval = 0;
} else {
if (bond_get_targets_ip(arp_target, ip) == -1)
arp_target[arp_ip_count++] = ip;
else
pr_warning("Warning: duplicate address %pI4 in arp_ip_target, skipping\n",
&ip);
}
}
if (arp_interval && !arp_ip_count) {
pr_warning("Warning: arp_interval module parameter (%d) specified without providing an arp_ip_target parameter, arp_interval was reset to 0\n",
arp_interval);
arp_interval = 0;
}
if (arp_validate) {
if (bond_mode != BOND_MODE_ACTIVEBACKUP) {
pr_err("arp_validate only supported in active-backup mode\n");
return -EINVAL;
}
if (!arp_interval) {
pr_err("arp_validate requires arp_interval\n");
return -EINVAL;
}
arp_validate_value = bond_parse_parm(arp_validate,
arp_validate_tbl);
if (arp_validate_value == -1) {
pr_err("Error: invalid arp_validate \"%s\"\n",
arp_validate == NULL ? "NULL" : arp_validate);
return -EINVAL;
}
} else
arp_validate_value = 0;
arp_all_targets_value = 0;
if (arp_all_targets) {
arp_all_targets_value = bond_parse_parm(arp_all_targets,
arp_all_targets_tbl);
if (arp_all_targets_value == -1) {
pr_err("Error: invalid arp_all_targets_value \"%s\"\n",
arp_all_targets);
arp_all_targets_value = 0;
}
}
if (miimon) {
pr_info("MII link monitoring set to %d ms\n", miimon);
} else if (arp_interval) {
pr_info("ARP monitoring set to %d ms, validate %s, with %d target(s):",
arp_interval,
arp_validate_tbl[arp_validate_value].modename,
arp_ip_count);
for (i = 0; i < arp_ip_count; i++)
pr_info(" %s", arp_ip_target[i]);
pr_info("\n");
} else if (max_bonds) {
pr_debug("Warning: either miimon or arp_interval and arp_ip_target module parameters must be specified, otherwise bonding will not detect link failures! see bonding.txt for details.\n");
}
if (primary && !USES_PRIMARY(bond_mode)) {
pr_warning("Warning: %s primary device specified but has no effect in %s mode\n",
primary, bond_mode_name(bond_mode));
primary = NULL;
}
if (primary && primary_reselect) {
primary_reselect_value = bond_parse_parm(primary_reselect,
pri_reselect_tbl);
if (primary_reselect_value == -1) {
pr_err("Error: Invalid primary_reselect \"%s\"\n",
primary_reselect ==
NULL ? "NULL" : primary_reselect);
return -EINVAL;
}
} else {
primary_reselect_value = BOND_PRI_RESELECT_ALWAYS;
}
if (fail_over_mac) {
fail_over_mac_value = bond_parse_parm(fail_over_mac,
fail_over_mac_tbl);
if (fail_over_mac_value == -1) {
pr_err("Error: invalid fail_over_mac \"%s\"\n",
arp_validate == NULL ? "NULL" : arp_validate);
return -EINVAL;
}
if (bond_mode != BOND_MODE_ACTIVEBACKUP)
pr_warning("Warning: fail_over_mac only affects active-backup mode.\n");
} else {
fail_over_mac_value = BOND_FOM_NONE;
}
params->mode = bond_mode;
params->xmit_policy = xmit_hashtype;
params->miimon = miimon;
params->num_peer_notif = num_peer_notif;
params->arp_interval = arp_interval;
params->arp_validate = arp_validate_value;
params->arp_all_targets = arp_all_targets_value;
params->updelay = updelay;
params->downdelay = downdelay;
params->use_carrier = use_carrier;
params->lacp_fast = lacp_fast;
params->primary[0] = 0;
params->primary_reselect = primary_reselect_value;
params->fail_over_mac = fail_over_mac_value;
params->tx_queues = tx_queues;
params->all_slaves_active = all_slaves_active;
params->resend_igmp = resend_igmp;
params->min_links = min_links;
params->lp_interval = BOND_ALB_DEFAULT_LP_INTERVAL;
if (packets_per_slave > 1)
params->packets_per_slave = reciprocal_value(packets_per_slave);
else
params->packets_per_slave = packets_per_slave;
if (primary) {
strncpy(params->primary, primary, IFNAMSIZ);
params->primary[IFNAMSIZ - 1] = 0;
}
memcpy(params->arp_targets, arp_target, sizeof(arp_target));
return 0;
}
static void bond_set_lockdep_class_one(struct net_device *dev,
struct netdev_queue *txq,
void *_unused)
{
lockdep_set_class(&txq->_xmit_lock,
&bonding_netdev_xmit_lock_key);
}
static void bond_set_lockdep_class(struct net_device *dev)
{
lockdep_set_class(&dev->addr_list_lock,
&bonding_netdev_addr_lock_key);
netdev_for_each_tx_queue(dev, bond_set_lockdep_class_one, NULL);
dev->qdisc_tx_busylock = &bonding_tx_busylock_key;
}
static int bond_init(struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct bond_net *bn = net_generic(dev_net(bond_dev), bond_net_id);
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
pr_debug("Begin bond_init for %s\n", bond_dev->name);
spin_lock_init(&(bond_info->tx_hashtbl_lock));
spin_lock_init(&(bond_info->rx_hashtbl_lock));
bond->wq = create_singlethread_workqueue(bond_dev->name);
if (!bond->wq)
return -ENOMEM;
bond_set_lockdep_class(bond_dev);
list_add_tail(&bond->bond_list, &bn->dev_list);
bond_prepare_sysfs_group(bond);
bond_debug_register(bond);
if (is_zero_ether_addr(bond_dev->dev_addr) &&
bond_dev->addr_assign_type == NET_ADDR_PERM)
eth_hw_addr_random(bond_dev);
return 0;
}
unsigned int bond_get_num_tx_queues(void)
{
return tx_queues;
}
int bond_create(struct net *net, const char *name)
{
struct net_device *bond_dev;
int res;
rtnl_lock();
bond_dev = alloc_netdev_mq(sizeof(struct bonding),
name ? name : "bond%d",
bond_setup, tx_queues);
if (!bond_dev) {
pr_err("%s: eek! can't alloc netdev!\n", name);
rtnl_unlock();
return -ENOMEM;
}
dev_net_set(bond_dev, net);
bond_dev->rtnl_link_ops = &bond_link_ops;
res = register_netdevice(bond_dev);
netif_carrier_off(bond_dev);
rtnl_unlock();
if (res < 0)
bond_destructor(bond_dev);
return res;
}
static int __net_init bond_net_init(struct net *net)
{
struct bond_net *bn = net_generic(net, bond_net_id);
bn->net = net;
INIT_LIST_HEAD(&bn->dev_list);
bond_create_proc_dir(bn);
bond_create_sysfs(bn);
return 0;
}
static void __net_exit bond_net_exit(struct net *net)
{
struct bond_net *bn = net_generic(net, bond_net_id);
struct bonding *bond, *tmp_bond;
LIST_HEAD(list);
bond_destroy_sysfs(bn);
bond_destroy_proc_dir(bn);
rtnl_lock();
list_for_each_entry_safe(bond, tmp_bond, &bn->dev_list, bond_list)
unregister_netdevice_queue(bond->dev, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int __init bonding_init(void)
{
int i;
int res;
pr_info("%s", bond_version);
res = bond_check_params(&bonding_defaults);
if (res)
goto out;
res = register_pernet_subsys(&bond_net_ops);
if (res)
goto out;
res = bond_netlink_init();
if (res)
goto err_link;
bond_create_debugfs();
for (i = 0; i < max_bonds; i++) {
res = bond_create(&init_net, NULL);
if (res)
goto err;
}
register_netdevice_notifier(&bond_netdev_notifier);
out:
return res;
err:
bond_netlink_fini();
err_link:
unregister_pernet_subsys(&bond_net_ops);
goto out;
}
static void __exit bonding_exit(void)
{
unregister_netdevice_notifier(&bond_netdev_notifier);
bond_destroy_debugfs();
bond_netlink_fini();
unregister_pernet_subsys(&bond_net_ops);
#ifdef CONFIG_NET_POLL_CONTROLLER
WARN_ON(atomic_read(&netpoll_block_tx));
#endif
}
