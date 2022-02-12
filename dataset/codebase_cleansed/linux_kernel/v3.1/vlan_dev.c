static int vlan_dev_rebuild_header(struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
struct vlan_ethhdr *veth = (struct vlan_ethhdr *)(skb->data);
switch (veth->h_vlan_encapsulated_proto) {
#ifdef CONFIG_INET
case htons(ETH_P_IP):
return arp_find(veth->h_dest, skb);
#endif
default:
pr_debug("%s: unable to resolve type %X addresses\n",
dev->name, ntohs(veth->h_vlan_encapsulated_proto));
memcpy(veth->h_source, dev->dev_addr, ETH_ALEN);
break;
}
return 0;
}
static inline u16
vlan_dev_get_egress_qos_mask(struct net_device *dev, struct sk_buff *skb)
{
struct vlan_priority_tci_mapping *mp;
mp = vlan_dev_info(dev)->egress_priority_map[(skb->priority & 0xF)];
while (mp) {
if (mp->priority == skb->priority) {
return mp->vlan_qos;
}
mp = mp->next;
}
return 0;
}
static int vlan_dev_hard_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr,
unsigned int len)
{
struct vlan_hdr *vhdr;
unsigned int vhdrlen = 0;
u16 vlan_tci = 0;
int rc;
if (!(vlan_dev_info(dev)->flags & VLAN_FLAG_REORDER_HDR)) {
vhdr = (struct vlan_hdr *) skb_push(skb, VLAN_HLEN);
vlan_tci = vlan_dev_info(dev)->vlan_id;
vlan_tci |= vlan_dev_get_egress_qos_mask(dev, skb);
vhdr->h_vlan_TCI = htons(vlan_tci);
if (type != ETH_P_802_3 && type != ETH_P_802_2)
vhdr->h_vlan_encapsulated_proto = htons(type);
else
vhdr->h_vlan_encapsulated_proto = htons(len);
skb->protocol = htons(ETH_P_8021Q);
type = ETH_P_8021Q;
vhdrlen = VLAN_HLEN;
}
if (saddr == NULL)
saddr = dev->dev_addr;
dev = vlan_dev_info(dev)->real_dev;
rc = dev_hard_header(skb, dev, type, daddr, saddr, len + vhdrlen);
if (rc > 0)
rc += vhdrlen;
return rc;
}
static netdev_tx_t vlan_dev_hard_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct vlan_ethhdr *veth = (struct vlan_ethhdr *)(skb->data);
unsigned int len;
int ret;
if (veth->h_vlan_proto != htons(ETH_P_8021Q) ||
vlan_dev_info(dev)->flags & VLAN_FLAG_REORDER_HDR) {
u16 vlan_tci;
vlan_tci = vlan_dev_info(dev)->vlan_id;
vlan_tci |= vlan_dev_get_egress_qos_mask(dev, skb);
skb = __vlan_hwaccel_put_tag(skb, vlan_tci);
}
skb_set_dev(skb, vlan_dev_info(dev)->real_dev);
len = skb->len;
ret = dev_queue_xmit(skb);
if (likely(ret == NET_XMIT_SUCCESS || ret == NET_XMIT_CN)) {
struct vlan_pcpu_stats *stats;
stats = this_cpu_ptr(vlan_dev_info(dev)->vlan_pcpu_stats);
u64_stats_update_begin(&stats->syncp);
stats->tx_packets++;
stats->tx_bytes += len;
u64_stats_update_end(&stats->syncp);
} else {
this_cpu_inc(vlan_dev_info(dev)->vlan_pcpu_stats->tx_dropped);
}
return ret;
}
static int vlan_dev_change_mtu(struct net_device *dev, int new_mtu)
{
if (vlan_dev_info(dev)->real_dev->mtu < new_mtu)
return -ERANGE;
dev->mtu = new_mtu;
return 0;
}
void vlan_dev_set_ingress_priority(const struct net_device *dev,
u32 skb_prio, u16 vlan_prio)
{
struct vlan_dev_info *vlan = vlan_dev_info(dev);
if (vlan->ingress_priority_map[vlan_prio & 0x7] && !skb_prio)
vlan->nr_ingress_mappings--;
else if (!vlan->ingress_priority_map[vlan_prio & 0x7] && skb_prio)
vlan->nr_ingress_mappings++;
vlan->ingress_priority_map[vlan_prio & 0x7] = skb_prio;
}
int vlan_dev_set_egress_priority(const struct net_device *dev,
u32 skb_prio, u16 vlan_prio)
{
struct vlan_dev_info *vlan = vlan_dev_info(dev);
struct vlan_priority_tci_mapping *mp = NULL;
struct vlan_priority_tci_mapping *np;
u32 vlan_qos = (vlan_prio << VLAN_PRIO_SHIFT) & VLAN_PRIO_MASK;
mp = vlan->egress_priority_map[skb_prio & 0xF];
while (mp) {
if (mp->priority == skb_prio) {
if (mp->vlan_qos && !vlan_qos)
vlan->nr_egress_mappings--;
else if (!mp->vlan_qos && vlan_qos)
vlan->nr_egress_mappings++;
mp->vlan_qos = vlan_qos;
return 0;
}
mp = mp->next;
}
mp = vlan->egress_priority_map[skb_prio & 0xF];
np = kmalloc(sizeof(struct vlan_priority_tci_mapping), GFP_KERNEL);
if (!np)
return -ENOBUFS;
np->next = mp;
np->priority = skb_prio;
np->vlan_qos = vlan_qos;
vlan->egress_priority_map[skb_prio & 0xF] = np;
if (vlan_qos)
vlan->nr_egress_mappings++;
return 0;
}
int vlan_dev_change_flags(const struct net_device *dev, u32 flags, u32 mask)
{
struct vlan_dev_info *vlan = vlan_dev_info(dev);
u32 old_flags = vlan->flags;
if (mask & ~(VLAN_FLAG_REORDER_HDR | VLAN_FLAG_GVRP |
VLAN_FLAG_LOOSE_BINDING))
return -EINVAL;
vlan->flags = (old_flags & ~mask) | (flags & mask);
if (netif_running(dev) && (vlan->flags ^ old_flags) & VLAN_FLAG_GVRP) {
if (vlan->flags & VLAN_FLAG_GVRP)
vlan_gvrp_request_join(dev);
else
vlan_gvrp_request_leave(dev);
}
return 0;
}
void vlan_dev_get_realdev_name(const struct net_device *dev, char *result)
{
strncpy(result, vlan_dev_info(dev)->real_dev->name, 23);
}
static int vlan_dev_open(struct net_device *dev)
{
struct vlan_dev_info *vlan = vlan_dev_info(dev);
struct net_device *real_dev = vlan->real_dev;
int err;
if (!(real_dev->flags & IFF_UP) &&
!(vlan->flags & VLAN_FLAG_LOOSE_BINDING))
return -ENETDOWN;
if (compare_ether_addr(dev->dev_addr, real_dev->dev_addr)) {
err = dev_uc_add(real_dev, dev->dev_addr);
if (err < 0)
goto out;
}
if (dev->flags & IFF_ALLMULTI) {
err = dev_set_allmulti(real_dev, 1);
if (err < 0)
goto del_unicast;
}
if (dev->flags & IFF_PROMISC) {
err = dev_set_promiscuity(real_dev, 1);
if (err < 0)
goto clear_allmulti;
}
memcpy(vlan->real_dev_addr, real_dev->dev_addr, ETH_ALEN);
if (vlan->flags & VLAN_FLAG_GVRP)
vlan_gvrp_request_join(dev);
if (netif_carrier_ok(real_dev))
netif_carrier_on(dev);
return 0;
clear_allmulti:
if (dev->flags & IFF_ALLMULTI)
dev_set_allmulti(real_dev, -1);
del_unicast:
if (compare_ether_addr(dev->dev_addr, real_dev->dev_addr))
dev_uc_del(real_dev, dev->dev_addr);
out:
netif_carrier_off(dev);
return err;
}
static int vlan_dev_stop(struct net_device *dev)
{
struct vlan_dev_info *vlan = vlan_dev_info(dev);
struct net_device *real_dev = vlan->real_dev;
dev_mc_unsync(real_dev, dev);
dev_uc_unsync(real_dev, dev);
if (dev->flags & IFF_ALLMULTI)
dev_set_allmulti(real_dev, -1);
if (dev->flags & IFF_PROMISC)
dev_set_promiscuity(real_dev, -1);
if (compare_ether_addr(dev->dev_addr, real_dev->dev_addr))
dev_uc_del(real_dev, dev->dev_addr);
netif_carrier_off(dev);
return 0;
}
static int vlan_dev_set_mac_address(struct net_device *dev, void *p)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
struct sockaddr *addr = p;
int err;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (!(dev->flags & IFF_UP))
goto out;
if (compare_ether_addr(addr->sa_data, real_dev->dev_addr)) {
err = dev_uc_add(real_dev, addr->sa_data);
if (err < 0)
return err;
}
if (compare_ether_addr(dev->dev_addr, real_dev->dev_addr))
dev_uc_del(real_dev, dev->dev_addr);
out:
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
return 0;
}
static int vlan_dev_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
struct ifreq ifrr;
int err = -EOPNOTSUPP;
strncpy(ifrr.ifr_name, real_dev->name, IFNAMSIZ);
ifrr.ifr_ifru = ifr->ifr_ifru;
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
if (netif_device_present(real_dev) && ops->ndo_do_ioctl)
err = ops->ndo_do_ioctl(real_dev, &ifrr, cmd);
break;
}
if (!err)
ifr->ifr_ifru = ifrr.ifr_ifru;
return err;
}
static int vlan_dev_neigh_setup(struct net_device *dev, struct neigh_parms *pa)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int err = 0;
if (netif_device_present(real_dev) && ops->ndo_neigh_setup)
err = ops->ndo_neigh_setup(real_dev, pa);
return err;
}
static int vlan_dev_fcoe_ddp_setup(struct net_device *dev, u16 xid,
struct scatterlist *sgl, unsigned int sgc)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int rc = 0;
if (ops->ndo_fcoe_ddp_setup)
rc = ops->ndo_fcoe_ddp_setup(real_dev, xid, sgl, sgc);
return rc;
}
static int vlan_dev_fcoe_ddp_done(struct net_device *dev, u16 xid)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int len = 0;
if (ops->ndo_fcoe_ddp_done)
len = ops->ndo_fcoe_ddp_done(real_dev, xid);
return len;
}
static int vlan_dev_fcoe_enable(struct net_device *dev)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int rc = -EINVAL;
if (ops->ndo_fcoe_enable)
rc = ops->ndo_fcoe_enable(real_dev);
return rc;
}
static int vlan_dev_fcoe_disable(struct net_device *dev)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int rc = -EINVAL;
if (ops->ndo_fcoe_disable)
rc = ops->ndo_fcoe_disable(real_dev);
return rc;
}
static int vlan_dev_fcoe_get_wwn(struct net_device *dev, u64 *wwn, int type)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int rc = -EINVAL;
if (ops->ndo_fcoe_get_wwn)
rc = ops->ndo_fcoe_get_wwn(real_dev, wwn, type);
return rc;
}
static int vlan_dev_fcoe_ddp_target(struct net_device *dev, u16 xid,
struct scatterlist *sgl, unsigned int sgc)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
const struct net_device_ops *ops = real_dev->netdev_ops;
int rc = 0;
if (ops->ndo_fcoe_ddp_target)
rc = ops->ndo_fcoe_ddp_target(real_dev, xid, sgl, sgc);
return rc;
}
static void vlan_dev_change_rx_flags(struct net_device *dev, int change)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
if (change & IFF_ALLMULTI)
dev_set_allmulti(real_dev, dev->flags & IFF_ALLMULTI ? 1 : -1);
if (change & IFF_PROMISC)
dev_set_promiscuity(real_dev, dev->flags & IFF_PROMISC ? 1 : -1);
}
static void vlan_dev_set_rx_mode(struct net_device *vlan_dev)
{
dev_mc_sync(vlan_dev_info(vlan_dev)->real_dev, vlan_dev);
dev_uc_sync(vlan_dev_info(vlan_dev)->real_dev, vlan_dev);
}
static void vlan_dev_set_lockdep_one(struct net_device *dev,
struct netdev_queue *txq,
void *_subclass)
{
lockdep_set_class_and_subclass(&txq->_xmit_lock,
&vlan_netdev_xmit_lock_key,
*(int *)_subclass);
}
static void vlan_dev_set_lockdep_class(struct net_device *dev, int subclass)
{
lockdep_set_class_and_subclass(&dev->addr_list_lock,
&vlan_netdev_addr_lock_key,
subclass);
netdev_for_each_tx_queue(dev, vlan_dev_set_lockdep_one, &subclass);
}
static int vlan_dev_init(struct net_device *dev)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
int subclass = 0;
netif_carrier_off(dev);
dev->flags = real_dev->flags & ~(IFF_UP | IFF_PROMISC | IFF_ALLMULTI |
IFF_MASTER | IFF_SLAVE);
dev->iflink = real_dev->ifindex;
dev->state = (real_dev->state & ((1<<__LINK_STATE_NOCARRIER) |
(1<<__LINK_STATE_DORMANT))) |
(1<<__LINK_STATE_PRESENT);
dev->hw_features = NETIF_F_ALL_CSUM | NETIF_F_SG |
NETIF_F_FRAGLIST | NETIF_F_ALL_TSO |
NETIF_F_HIGHDMA | NETIF_F_SCTP_CSUM |
NETIF_F_ALL_FCOE;
dev->features |= real_dev->vlan_features | NETIF_F_LLTX;
dev->gso_max_size = real_dev->gso_max_size;
dev->dev_id = real_dev->dev_id;
if (is_zero_ether_addr(dev->dev_addr))
memcpy(dev->dev_addr, real_dev->dev_addr, dev->addr_len);
if (is_zero_ether_addr(dev->broadcast))
memcpy(dev->broadcast, real_dev->broadcast, dev->addr_len);
#if defined(CONFIG_FCOE) || defined(CONFIG_FCOE_MODULE)
dev->fcoe_ddp_xid = real_dev->fcoe_ddp_xid;
#endif
dev->needed_headroom = real_dev->needed_headroom;
if (real_dev->features & NETIF_F_HW_VLAN_TX) {
dev->header_ops = real_dev->header_ops;
dev->hard_header_len = real_dev->hard_header_len;
} else {
dev->header_ops = &vlan_header_ops;
dev->hard_header_len = real_dev->hard_header_len + VLAN_HLEN;
}
dev->netdev_ops = &vlan_netdev_ops;
if (is_vlan_dev(real_dev))
subclass = 1;
vlan_dev_set_lockdep_class(dev, subclass);
vlan_dev_info(dev)->vlan_pcpu_stats = alloc_percpu(struct vlan_pcpu_stats);
if (!vlan_dev_info(dev)->vlan_pcpu_stats)
return -ENOMEM;
return 0;
}
static void vlan_dev_uninit(struct net_device *dev)
{
struct vlan_priority_tci_mapping *pm;
struct vlan_dev_info *vlan = vlan_dev_info(dev);
int i;
free_percpu(vlan->vlan_pcpu_stats);
vlan->vlan_pcpu_stats = NULL;
for (i = 0; i < ARRAY_SIZE(vlan->egress_priority_map); i++) {
while ((pm = vlan->egress_priority_map[i]) != NULL) {
vlan->egress_priority_map[i] = pm->next;
kfree(pm);
}
}
}
static u32 vlan_dev_fix_features(struct net_device *dev, u32 features)
{
struct net_device *real_dev = vlan_dev_info(dev)->real_dev;
u32 old_features = features;
features &= real_dev->features;
features &= real_dev->vlan_features;
features |= old_features & NETIF_F_SOFT_FEATURES;
if (dev_ethtool_get_rx_csum(real_dev))
features |= NETIF_F_RXCSUM;
features |= NETIF_F_LLTX;
return features;
}
static int vlan_ethtool_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
const struct vlan_dev_info *vlan = vlan_dev_info(dev);
return dev_ethtool_get_settings(vlan->real_dev, cmd);
}
static void vlan_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strcpy(info->driver, vlan_fullname);
strcpy(info->version, vlan_version);
strcpy(info->fw_version, "N/A");
}
static struct rtnl_link_stats64 *vlan_dev_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
if (vlan_dev_info(dev)->vlan_pcpu_stats) {
struct vlan_pcpu_stats *p;
u32 rx_errors = 0, tx_dropped = 0;
int i;
for_each_possible_cpu(i) {
u64 rxpackets, rxbytes, rxmulticast, txpackets, txbytes;
unsigned int start;
p = per_cpu_ptr(vlan_dev_info(dev)->vlan_pcpu_stats, i);
do {
start = u64_stats_fetch_begin_bh(&p->syncp);
rxpackets = p->rx_packets;
rxbytes = p->rx_bytes;
rxmulticast = p->rx_multicast;
txpackets = p->tx_packets;
txbytes = p->tx_bytes;
} while (u64_stats_fetch_retry_bh(&p->syncp, start));
stats->rx_packets += rxpackets;
stats->rx_bytes += rxbytes;
stats->multicast += rxmulticast;
stats->tx_packets += txpackets;
stats->tx_bytes += txbytes;
rx_errors += p->rx_errors;
tx_dropped += p->tx_dropped;
}
stats->rx_errors = rx_errors;
stats->tx_dropped = tx_dropped;
}
return stats;
}
void vlan_setup(struct net_device *dev)
{
ether_setup(dev);
dev->priv_flags |= IFF_802_1Q_VLAN;
dev->priv_flags &= ~(IFF_XMIT_DST_RELEASE | IFF_TX_SKB_SHARING);
dev->tx_queue_len = 0;
dev->netdev_ops = &vlan_netdev_ops;
dev->destructor = free_netdev;
dev->ethtool_ops = &vlan_ethtool_ops;
memset(dev->broadcast, 0, ETH_ALEN);
}
