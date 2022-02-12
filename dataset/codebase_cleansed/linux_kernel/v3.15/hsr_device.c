static bool is_admin_up(struct net_device *dev)
{
return dev && (dev->flags & IFF_UP);
}
static bool is_slave_up(struct net_device *dev)
{
return dev && is_admin_up(dev) && netif_oper_up(dev);
}
static void __hsr_set_operstate(struct net_device *dev, int transition)
{
write_lock_bh(&dev_base_lock);
if (dev->operstate != transition) {
dev->operstate = transition;
write_unlock_bh(&dev_base_lock);
netdev_state_change(dev);
} else {
write_unlock_bh(&dev_base_lock);
}
}
void hsr_set_operstate(struct net_device *hsr_dev, struct net_device *slave1,
struct net_device *slave2)
{
if (!is_admin_up(hsr_dev)) {
__hsr_set_operstate(hsr_dev, IF_OPER_DOWN);
return;
}
if (is_slave_up(slave1) || is_slave_up(slave2))
__hsr_set_operstate(hsr_dev, IF_OPER_UP);
else
__hsr_set_operstate(hsr_dev, IF_OPER_LOWERLAYERDOWN);
}
void hsr_set_carrier(struct net_device *hsr_dev, struct net_device *slave1,
struct net_device *slave2)
{
if (is_slave_up(slave1) || is_slave_up(slave2))
netif_carrier_on(hsr_dev);
else
netif_carrier_off(hsr_dev);
}
void hsr_check_announce(struct net_device *hsr_dev, int old_operstate)
{
struct hsr_priv *hsr_priv;
hsr_priv = netdev_priv(hsr_dev);
if ((hsr_dev->operstate == IF_OPER_UP) && (old_operstate != IF_OPER_UP)) {
hsr_priv->announce_count = 0;
hsr_priv->announce_timer.expires = jiffies +
msecs_to_jiffies(HSR_ANNOUNCE_INTERVAL);
add_timer(&hsr_priv->announce_timer);
}
if ((hsr_dev->operstate != IF_OPER_UP) && (old_operstate == IF_OPER_UP))
del_timer(&hsr_priv->announce_timer);
}
int hsr_get_max_mtu(struct hsr_priv *hsr_priv)
{
int mtu_max;
if (hsr_priv->slave[0] && hsr_priv->slave[1])
mtu_max = min(hsr_priv->slave[0]->mtu, hsr_priv->slave[1]->mtu);
else if (hsr_priv->slave[0])
mtu_max = hsr_priv->slave[0]->mtu;
else if (hsr_priv->slave[1])
mtu_max = hsr_priv->slave[1]->mtu;
else
mtu_max = HSR_TAGLEN;
return mtu_max - HSR_TAGLEN;
}
static int hsr_dev_change_mtu(struct net_device *dev, int new_mtu)
{
struct hsr_priv *hsr_priv;
hsr_priv = netdev_priv(dev);
if (new_mtu > hsr_get_max_mtu(hsr_priv)) {
netdev_info(hsr_priv->dev, "A HSR master's MTU cannot be greater than the smallest MTU of its slaves minus the HSR Tag length (%d octets).\n",
HSR_TAGLEN);
return -EINVAL;
}
dev->mtu = new_mtu;
return 0;
}
static int hsr_dev_open(struct net_device *dev)
{
struct hsr_priv *hsr_priv;
int i;
char *slave_name;
hsr_priv = netdev_priv(dev);
for (i = 0; i < HSR_MAX_SLAVE; i++) {
if (hsr_priv->slave[i])
slave_name = hsr_priv->slave[i]->name;
else
slave_name = "null";
if (!is_slave_up(hsr_priv->slave[i]))
netdev_warn(dev, "Slave %c (%s) is not up; please bring it up to get a working HSR network\n",
'A' + i, slave_name);
}
return 0;
}
static int hsr_dev_close(struct net_device *dev)
{
return 0;
}
static void hsr_fill_tag(struct hsr_ethhdr *hsr_ethhdr, struct hsr_priv *hsr_priv)
{
unsigned long irqflags;
set_hsr_tag_path(&hsr_ethhdr->hsr_tag, 0x1);
set_hsr_tag_LSDU_size(&hsr_ethhdr->hsr_tag, 0);
spin_lock_irqsave(&hsr_priv->seqnr_lock, irqflags);
hsr_ethhdr->hsr_tag.sequence_nr = htons(hsr_priv->sequence_nr);
hsr_priv->sequence_nr++;
spin_unlock_irqrestore(&hsr_priv->seqnr_lock, irqflags);
hsr_ethhdr->hsr_tag.encap_proto = hsr_ethhdr->ethhdr.h_proto;
hsr_ethhdr->ethhdr.h_proto = htons(ETH_P_PRP);
}
static int slave_xmit(struct sk_buff *skb, struct hsr_priv *hsr_priv,
enum hsr_dev_idx dev_idx)
{
struct hsr_ethhdr *hsr_ethhdr;
hsr_ethhdr = (struct hsr_ethhdr *) skb->data;
skb->dev = hsr_priv->slave[dev_idx];
hsr_addr_subst_dest(hsr_priv, &hsr_ethhdr->ethhdr, dev_idx);
ether_addr_copy(hsr_ethhdr->ethhdr.h_source, skb->dev->dev_addr);
return dev_queue_xmit(skb);
}
static int hsr_dev_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct hsr_priv *hsr_priv;
struct hsr_ethhdr *hsr_ethhdr;
struct sk_buff *skb2;
int res1, res2;
hsr_priv = netdev_priv(dev);
hsr_ethhdr = (struct hsr_ethhdr *) skb->data;
if ((skb->protocol != htons(ETH_P_PRP)) ||
(hsr_ethhdr->ethhdr.h_proto != htons(ETH_P_PRP))) {
hsr_fill_tag(hsr_ethhdr, hsr_priv);
skb->protocol = htons(ETH_P_PRP);
}
skb2 = pskb_copy(skb, GFP_ATOMIC);
res1 = NET_XMIT_DROP;
if (likely(hsr_priv->slave[HSR_DEV_SLAVE_A]))
res1 = slave_xmit(skb, hsr_priv, HSR_DEV_SLAVE_A);
res2 = NET_XMIT_DROP;
if (likely(skb2 && hsr_priv->slave[HSR_DEV_SLAVE_B]))
res2 = slave_xmit(skb2, hsr_priv, HSR_DEV_SLAVE_B);
if (likely(res1 == NET_XMIT_SUCCESS || res1 == NET_XMIT_CN ||
res2 == NET_XMIT_SUCCESS || res2 == NET_XMIT_CN)) {
hsr_priv->dev->stats.tx_packets++;
hsr_priv->dev->stats.tx_bytes += skb->len;
} else {
hsr_priv->dev->stats.tx_dropped++;
}
return NETDEV_TX_OK;
}
static int hsr_header_create(struct sk_buff *skb, struct net_device *dev,
unsigned short type, const void *daddr,
const void *saddr, unsigned int len)
{
int res;
if (skb_headroom(skb) < HSR_TAGLEN + ETH_HLEN)
return -ENOBUFS;
skb_push(skb, HSR_TAGLEN);
res = eth_header(skb, dev, type, daddr, saddr, len + HSR_TAGLEN);
if (res <= 0)
return res;
skb_reset_mac_header(skb);
return res + HSR_TAGLEN;
}
static int hsr_pad(int size)
{
const int min_size = ETH_ZLEN - HSR_TAGLEN - ETH_HLEN;
if (size >= min_size)
return size;
return min_size;
}
static void send_hsr_supervision_frame(struct net_device *hsr_dev, u8 type)
{
struct hsr_priv *hsr_priv;
struct sk_buff *skb;
int hlen, tlen;
struct hsr_sup_tag *hsr_stag;
struct hsr_sup_payload *hsr_sp;
unsigned long irqflags;
hlen = LL_RESERVED_SPACE(hsr_dev);
tlen = hsr_dev->needed_tailroom;
skb = alloc_skb(hsr_pad(sizeof(struct hsr_sup_payload)) + hlen + tlen,
GFP_ATOMIC);
if (skb == NULL)
return;
hsr_priv = netdev_priv(hsr_dev);
skb_reserve(skb, hlen);
skb->dev = hsr_dev;
skb->protocol = htons(ETH_P_PRP);
skb->priority = TC_PRIO_CONTROL;
if (dev_hard_header(skb, skb->dev, ETH_P_PRP,
hsr_priv->sup_multicast_addr,
skb->dev->dev_addr, skb->len) < 0)
goto out;
skb_pull(skb, sizeof(struct ethhdr));
hsr_stag = (typeof(hsr_stag)) skb->data;
set_hsr_stag_path(hsr_stag, 0xf);
set_hsr_stag_HSR_Ver(hsr_stag, 0);
spin_lock_irqsave(&hsr_priv->seqnr_lock, irqflags);
hsr_stag->sequence_nr = htons(hsr_priv->sequence_nr);
hsr_priv->sequence_nr++;
spin_unlock_irqrestore(&hsr_priv->seqnr_lock, irqflags);
hsr_stag->HSR_TLV_Type = type;
hsr_stag->HSR_TLV_Length = 12;
skb_push(skb, sizeof(struct ethhdr));
hsr_sp = (typeof(hsr_sp)) skb_put(skb, sizeof(*hsr_sp));
ether_addr_copy(hsr_sp->MacAddressA, hsr_dev->dev_addr);
dev_queue_xmit(skb);
return;
out:
kfree_skb(skb);
}
static void hsr_announce(unsigned long data)
{
struct hsr_priv *hsr_priv;
hsr_priv = (struct hsr_priv *) data;
if (hsr_priv->announce_count < 3) {
send_hsr_supervision_frame(hsr_priv->dev, HSR_TLV_ANNOUNCE);
hsr_priv->announce_count++;
} else {
send_hsr_supervision_frame(hsr_priv->dev, HSR_TLV_LIFE_CHECK);
}
if (hsr_priv->announce_count < 3)
hsr_priv->announce_timer.expires = jiffies +
msecs_to_jiffies(HSR_ANNOUNCE_INTERVAL);
else
hsr_priv->announce_timer.expires = jiffies +
msecs_to_jiffies(HSR_LIFE_CHECK_INTERVAL);
if (is_admin_up(hsr_priv->dev))
add_timer(&hsr_priv->announce_timer);
}
static void restore_slaves(struct net_device *hsr_dev)
{
struct hsr_priv *hsr_priv;
int i;
int res;
hsr_priv = netdev_priv(hsr_dev);
rtnl_lock();
for (i = 0; i < HSR_MAX_SLAVE; i++) {
if (!hsr_priv->slave[i])
continue;
res = dev_set_promiscuity(hsr_priv->slave[i], -1);
if (res)
netdev_info(hsr_dev,
"Cannot restore slave promiscuity (%s, %d)\n",
hsr_priv->slave[i]->name, res);
}
rtnl_unlock();
}
static void reclaim_hsr_dev(struct rcu_head *rh)
{
struct hsr_priv *hsr_priv;
hsr_priv = container_of(rh, struct hsr_priv, rcu_head);
free_netdev(hsr_priv->dev);
}
static void hsr_dev_destroy(struct net_device *hsr_dev)
{
struct hsr_priv *hsr_priv;
hsr_priv = netdev_priv(hsr_dev);
del_timer(&hsr_priv->announce_timer);
unregister_hsr_master(hsr_priv);
restore_slaves(hsr_dev);
call_rcu(&hsr_priv->rcu_head, reclaim_hsr_dev);
}
void hsr_dev_setup(struct net_device *dev)
{
random_ether_addr(dev->dev_addr);
ether_setup(dev);
dev->header_ops = &hsr_header_ops;
dev->netdev_ops = &hsr_device_ops;
dev->tx_queue_len = 0;
dev->destructor = hsr_dev_destroy;
}
bool is_hsr_master(struct net_device *dev)
{
return (dev->netdev_ops->ndo_start_xmit == hsr_dev_xmit);
}
static int check_slave_ok(struct net_device *dev)
{
if ((dev->flags & IFF_LOOPBACK) || (dev->type != ARPHRD_ETHER) ||
(dev->addr_len != ETH_ALEN)) {
netdev_info(dev, "Cannot use loopback or non-ethernet device as HSR slave.\n");
return -EINVAL;
}
if (is_hsr_master(dev)) {
netdev_info(dev, "Cannot create trees of HSR devices.\n");
return -EINVAL;
}
if (is_hsr_slave(dev)) {
netdev_info(dev, "This device is already a HSR slave.\n");
return -EINVAL;
}
if (dev->priv_flags & IFF_802_1Q_VLAN) {
netdev_info(dev, "HSR on top of VLAN is not yet supported in this driver.\n");
return -EINVAL;
}
return 0;
}
int hsr_dev_finalize(struct net_device *hsr_dev, struct net_device *slave[2],
unsigned char multicast_spec)
{
struct hsr_priv *hsr_priv;
int i;
int res;
hsr_priv = netdev_priv(hsr_dev);
hsr_priv->dev = hsr_dev;
INIT_LIST_HEAD(&hsr_priv->node_db);
INIT_LIST_HEAD(&hsr_priv->self_node_db);
for (i = 0; i < HSR_MAX_SLAVE; i++)
hsr_priv->slave[i] = slave[i];
spin_lock_init(&hsr_priv->seqnr_lock);
hsr_priv->sequence_nr = USHRT_MAX - 1024;
init_timer(&hsr_priv->announce_timer);
hsr_priv->announce_timer.function = hsr_announce;
hsr_priv->announce_timer.data = (unsigned long) hsr_priv;
ether_addr_copy(hsr_priv->sup_multicast_addr, def_multicast_addr);
hsr_priv->sup_multicast_addr[ETH_ALEN - 1] = multicast_spec;
for (i = 0; i < HSR_MAX_SLAVE; i++) {
res = check_slave_ok(slave[i]);
if (res)
return res;
}
hsr_dev->features = slave[0]->features & slave[1]->features;
hsr_dev->features |= NETIF_F_LLTX;
hsr_dev->features |= NETIF_F_VLAN_CHALLENGED;
ether_addr_copy(hsr_dev->dev_addr, hsr_priv->slave[0]->dev_addr);
for (i = 0; i < HSR_MAX_SLAVE; i++) {
if (slave[i]->hard_header_len + HSR_TAGLEN >
hsr_dev->hard_header_len)
hsr_dev->hard_header_len =
slave[i]->hard_header_len + HSR_TAGLEN;
}
for (i = 0; i < HSR_MAX_SLAVE; i++)
if (slave[i]->mtu - HSR_TAGLEN < hsr_dev->mtu)
hsr_dev->mtu = slave[i]->mtu - HSR_TAGLEN;
netif_carrier_off(hsr_dev);
for (i = 0; i < HSR_MAX_SLAVE; i++) {
res = dev_set_promiscuity(slave[i], 1);
if (res) {
netdev_info(hsr_dev, "Cannot set slave promiscuity (%s, %d)\n",
slave[i]->name, res);
goto fail;
}
}
res = hsr_create_self_node(&hsr_priv->self_node_db,
hsr_dev->dev_addr,
hsr_priv->slave[1]->dev_addr);
if (res < 0)
goto fail;
res = register_netdevice(hsr_dev);
if (res)
goto fail;
register_hsr_master(hsr_priv);
return 0;
fail:
restore_slaves(hsr_dev);
return res;
}
