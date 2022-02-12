static inline struct skb_vnet_hdr *skb_vnet_hdr(struct sk_buff *skb)
{
return (struct skb_vnet_hdr *)skb->cb;
}
static void give_pages(struct virtnet_info *vi, struct page *page)
{
struct page *end;
for (end = page; end->private; end = (struct page *)end->private);
end->private = (unsigned long)vi->pages;
vi->pages = page;
}
static struct page *get_a_page(struct virtnet_info *vi, gfp_t gfp_mask)
{
struct page *p = vi->pages;
if (p) {
vi->pages = (struct page *)p->private;
p->private = 0;
} else
p = alloc_page(gfp_mask);
return p;
}
static void skb_xmit_done(struct virtqueue *svq)
{
struct virtnet_info *vi = svq->vdev->priv;
virtqueue_disable_cb(svq);
netif_wake_queue(vi->dev);
}
static void set_skb_frag(struct sk_buff *skb, struct page *page,
unsigned int offset, unsigned int *len)
{
int size = min((unsigned)PAGE_SIZE - offset, *len);
int i = skb_shinfo(skb)->nr_frags;
__skb_fill_page_desc(skb, i, page, offset, size);
skb->data_len += size;
skb->len += size;
skb->truesize += PAGE_SIZE;
skb_shinfo(skb)->nr_frags++;
*len -= size;
}
static struct sk_buff *page_to_skb(struct virtnet_info *vi,
struct page *page, unsigned int len)
{
struct sk_buff *skb;
struct skb_vnet_hdr *hdr;
unsigned int copy, hdr_len, offset;
char *p;
p = page_address(page);
skb = netdev_alloc_skb_ip_align(vi->dev, GOOD_COPY_LEN);
if (unlikely(!skb))
return NULL;
hdr = skb_vnet_hdr(skb);
if (vi->mergeable_rx_bufs) {
hdr_len = sizeof hdr->mhdr;
offset = hdr_len;
} else {
hdr_len = sizeof hdr->hdr;
offset = sizeof(struct padded_vnet_hdr);
}
memcpy(hdr, p, hdr_len);
len -= hdr_len;
p += offset;
copy = len;
if (copy > skb_tailroom(skb))
copy = skb_tailroom(skb);
memcpy(skb_put(skb, copy), p, copy);
len -= copy;
offset += copy;
if (unlikely(len > MAX_SKB_FRAGS * PAGE_SIZE)) {
if (net_ratelimit())
pr_debug("%s: too much data\n", skb->dev->name);
dev_kfree_skb(skb);
return NULL;
}
while (len) {
set_skb_frag(skb, page, offset, &len);
page = (struct page *)page->private;
offset = 0;
}
if (page)
give_pages(vi, page);
return skb;
}
static int receive_mergeable(struct virtnet_info *vi, struct sk_buff *skb)
{
struct skb_vnet_hdr *hdr = skb_vnet_hdr(skb);
struct page *page;
int num_buf, i, len;
num_buf = hdr->mhdr.num_buffers;
while (--num_buf) {
i = skb_shinfo(skb)->nr_frags;
if (i >= MAX_SKB_FRAGS) {
pr_debug("%s: packet too long\n", skb->dev->name);
skb->dev->stats.rx_length_errors++;
return -EINVAL;
}
page = virtqueue_get_buf(vi->rvq, &len);
if (!page) {
pr_debug("%s: rx error: %d buffers missing\n",
skb->dev->name, hdr->mhdr.num_buffers);
skb->dev->stats.rx_length_errors++;
return -EINVAL;
}
if (len > PAGE_SIZE)
len = PAGE_SIZE;
set_skb_frag(skb, page, 0, &len);
--vi->num;
}
return 0;
}
static void receive_buf(struct net_device *dev, void *buf, unsigned int len)
{
struct virtnet_info *vi = netdev_priv(dev);
struct virtnet_stats __percpu *stats = this_cpu_ptr(vi->stats);
struct sk_buff *skb;
struct page *page;
struct skb_vnet_hdr *hdr;
if (unlikely(len < sizeof(struct virtio_net_hdr) + ETH_HLEN)) {
pr_debug("%s: short packet %i\n", dev->name, len);
dev->stats.rx_length_errors++;
if (vi->mergeable_rx_bufs || vi->big_packets)
give_pages(vi, buf);
else
dev_kfree_skb(buf);
return;
}
if (!vi->mergeable_rx_bufs && !vi->big_packets) {
skb = buf;
len -= sizeof(struct virtio_net_hdr);
skb_trim(skb, len);
} else {
page = buf;
skb = page_to_skb(vi, page, len);
if (unlikely(!skb)) {
dev->stats.rx_dropped++;
give_pages(vi, page);
return;
}
if (vi->mergeable_rx_bufs)
if (receive_mergeable(vi, skb)) {
dev_kfree_skb(skb);
return;
}
}
hdr = skb_vnet_hdr(skb);
u64_stats_update_begin(&stats->syncp);
stats->rx_bytes += skb->len;
stats->rx_packets++;
u64_stats_update_end(&stats->syncp);
if (hdr->hdr.flags & VIRTIO_NET_HDR_F_NEEDS_CSUM) {
pr_debug("Needs csum!\n");
if (!skb_partial_csum_set(skb,
hdr->hdr.csum_start,
hdr->hdr.csum_offset))
goto frame_err;
} else if (hdr->hdr.flags & VIRTIO_NET_HDR_F_DATA_VALID) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
skb->protocol = eth_type_trans(skb, dev);
pr_debug("Receiving skb proto 0x%04x len %i type %i\n",
ntohs(skb->protocol), skb->len, skb->pkt_type);
if (hdr->hdr.gso_type != VIRTIO_NET_HDR_GSO_NONE) {
pr_debug("GSO!\n");
switch (hdr->hdr.gso_type & ~VIRTIO_NET_HDR_GSO_ECN) {
case VIRTIO_NET_HDR_GSO_TCPV4:
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
break;
case VIRTIO_NET_HDR_GSO_UDP:
skb_shinfo(skb)->gso_type = SKB_GSO_UDP;
break;
case VIRTIO_NET_HDR_GSO_TCPV6:
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV6;
break;
default:
if (net_ratelimit())
printk(KERN_WARNING "%s: bad gso type %u.\n",
dev->name, hdr->hdr.gso_type);
goto frame_err;
}
if (hdr->hdr.gso_type & VIRTIO_NET_HDR_GSO_ECN)
skb_shinfo(skb)->gso_type |= SKB_GSO_TCP_ECN;
skb_shinfo(skb)->gso_size = hdr->hdr.gso_size;
if (skb_shinfo(skb)->gso_size == 0) {
if (net_ratelimit())
printk(KERN_WARNING "%s: zero gso size.\n",
dev->name);
goto frame_err;
}
skb_shinfo(skb)->gso_type |= SKB_GSO_DODGY;
skb_shinfo(skb)->gso_segs = 0;
}
netif_receive_skb(skb);
return;
frame_err:
dev->stats.rx_frame_errors++;
dev_kfree_skb(skb);
}
static int add_recvbuf_small(struct virtnet_info *vi, gfp_t gfp)
{
struct sk_buff *skb;
struct skb_vnet_hdr *hdr;
int err;
skb = netdev_alloc_skb_ip_align(vi->dev, MAX_PACKET_LEN);
if (unlikely(!skb))
return -ENOMEM;
skb_put(skb, MAX_PACKET_LEN);
hdr = skb_vnet_hdr(skb);
sg_set_buf(vi->rx_sg, &hdr->hdr, sizeof hdr->hdr);
skb_to_sgvec(skb, vi->rx_sg + 1, 0, skb->len);
err = virtqueue_add_buf_gfp(vi->rvq, vi->rx_sg, 0, 2, skb, gfp);
if (err < 0)
dev_kfree_skb(skb);
return err;
}
static int add_recvbuf_big(struct virtnet_info *vi, gfp_t gfp)
{
struct page *first, *list = NULL;
char *p;
int i, err, offset;
for (i = MAX_SKB_FRAGS + 1; i > 1; --i) {
first = get_a_page(vi, gfp);
if (!first) {
if (list)
give_pages(vi, list);
return -ENOMEM;
}
sg_set_buf(&vi->rx_sg[i], page_address(first), PAGE_SIZE);
first->private = (unsigned long)list;
list = first;
}
first = get_a_page(vi, gfp);
if (!first) {
give_pages(vi, list);
return -ENOMEM;
}
p = page_address(first);
sg_set_buf(&vi->rx_sg[0], p, sizeof(struct virtio_net_hdr));
offset = sizeof(struct padded_vnet_hdr);
sg_set_buf(&vi->rx_sg[1], p + offset, PAGE_SIZE - offset);
first->private = (unsigned long)list;
err = virtqueue_add_buf_gfp(vi->rvq, vi->rx_sg, 0, MAX_SKB_FRAGS + 2,
first, gfp);
if (err < 0)
give_pages(vi, first);
return err;
}
static int add_recvbuf_mergeable(struct virtnet_info *vi, gfp_t gfp)
{
struct page *page;
int err;
page = get_a_page(vi, gfp);
if (!page)
return -ENOMEM;
sg_init_one(vi->rx_sg, page_address(page), PAGE_SIZE);
err = virtqueue_add_buf_gfp(vi->rvq, vi->rx_sg, 0, 1, page, gfp);
if (err < 0)
give_pages(vi, page);
return err;
}
static bool try_fill_recv(struct virtnet_info *vi, gfp_t gfp)
{
int err;
bool oom;
do {
if (vi->mergeable_rx_bufs)
err = add_recvbuf_mergeable(vi, gfp);
else if (vi->big_packets)
err = add_recvbuf_big(vi, gfp);
else
err = add_recvbuf_small(vi, gfp);
oom = err == -ENOMEM;
if (err < 0)
break;
++vi->num;
} while (err > 0);
if (unlikely(vi->num > vi->max))
vi->max = vi->num;
virtqueue_kick(vi->rvq);
return !oom;
}
static void skb_recv_done(struct virtqueue *rvq)
{
struct virtnet_info *vi = rvq->vdev->priv;
if (napi_schedule_prep(&vi->napi)) {
virtqueue_disable_cb(rvq);
__napi_schedule(&vi->napi);
}
}
static void virtnet_napi_enable(struct virtnet_info *vi)
{
napi_enable(&vi->napi);
if (napi_schedule_prep(&vi->napi)) {
virtqueue_disable_cb(vi->rvq);
__napi_schedule(&vi->napi);
}
}
static void refill_work(struct work_struct *work)
{
struct virtnet_info *vi;
bool still_empty;
vi = container_of(work, struct virtnet_info, refill.work);
napi_disable(&vi->napi);
still_empty = !try_fill_recv(vi, GFP_KERNEL);
virtnet_napi_enable(vi);
if (still_empty)
schedule_delayed_work(&vi->refill, HZ/2);
}
static int virtnet_poll(struct napi_struct *napi, int budget)
{
struct virtnet_info *vi = container_of(napi, struct virtnet_info, napi);
void *buf;
unsigned int len, received = 0;
again:
while (received < budget &&
(buf = virtqueue_get_buf(vi->rvq, &len)) != NULL) {
receive_buf(vi->dev, buf, len);
--vi->num;
received++;
}
if (vi->num < vi->max / 2) {
if (!try_fill_recv(vi, GFP_ATOMIC))
schedule_delayed_work(&vi->refill, 0);
}
if (received < budget) {
napi_complete(napi);
if (unlikely(!virtqueue_enable_cb(vi->rvq)) &&
napi_schedule_prep(napi)) {
virtqueue_disable_cb(vi->rvq);
__napi_schedule(napi);
goto again;
}
}
return received;
}
static unsigned int free_old_xmit_skbs(struct virtnet_info *vi)
{
struct sk_buff *skb;
unsigned int len, tot_sgs = 0;
struct virtnet_stats __percpu *stats = this_cpu_ptr(vi->stats);
while ((skb = virtqueue_get_buf(vi->svq, &len)) != NULL) {
pr_debug("Sent skb %p\n", skb);
u64_stats_update_begin(&stats->syncp);
stats->tx_bytes += skb->len;
stats->tx_packets++;
u64_stats_update_end(&stats->syncp);
tot_sgs += skb_vnet_hdr(skb)->num_sg;
dev_kfree_skb_any(skb);
}
return tot_sgs;
}
static int xmit_skb(struct virtnet_info *vi, struct sk_buff *skb)
{
struct skb_vnet_hdr *hdr = skb_vnet_hdr(skb);
const unsigned char *dest = ((struct ethhdr *)skb->data)->h_dest;
pr_debug("%s: xmit %p %pM\n", vi->dev->name, skb, dest);
if (skb->ip_summed == CHECKSUM_PARTIAL) {
hdr->hdr.flags = VIRTIO_NET_HDR_F_NEEDS_CSUM;
hdr->hdr.csum_start = skb_checksum_start_offset(skb);
hdr->hdr.csum_offset = skb->csum_offset;
} else {
hdr->hdr.flags = 0;
hdr->hdr.csum_offset = hdr->hdr.csum_start = 0;
}
if (skb_is_gso(skb)) {
hdr->hdr.hdr_len = skb_headlen(skb);
hdr->hdr.gso_size = skb_shinfo(skb)->gso_size;
if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4)
hdr->hdr.gso_type = VIRTIO_NET_HDR_GSO_TCPV4;
else if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6)
hdr->hdr.gso_type = VIRTIO_NET_HDR_GSO_TCPV6;
else if (skb_shinfo(skb)->gso_type & SKB_GSO_UDP)
hdr->hdr.gso_type = VIRTIO_NET_HDR_GSO_UDP;
else
BUG();
if (skb_shinfo(skb)->gso_type & SKB_GSO_TCP_ECN)
hdr->hdr.gso_type |= VIRTIO_NET_HDR_GSO_ECN;
} else {
hdr->hdr.gso_type = VIRTIO_NET_HDR_GSO_NONE;
hdr->hdr.gso_size = hdr->hdr.hdr_len = 0;
}
hdr->mhdr.num_buffers = 0;
if (vi->mergeable_rx_bufs)
sg_set_buf(vi->tx_sg, &hdr->mhdr, sizeof hdr->mhdr);
else
sg_set_buf(vi->tx_sg, &hdr->hdr, sizeof hdr->hdr);
hdr->num_sg = skb_to_sgvec(skb, vi->tx_sg + 1, 0, skb->len) + 1;
return virtqueue_add_buf(vi->svq, vi->tx_sg, hdr->num_sg,
0, skb);
}
static netdev_tx_t start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct virtnet_info *vi = netdev_priv(dev);
int capacity;
free_old_xmit_skbs(vi);
capacity = xmit_skb(vi, skb);
if (unlikely(capacity < 0)) {
if (net_ratelimit()) {
if (likely(capacity == -ENOMEM)) {
dev_warn(&dev->dev,
"TX queue failure: out of memory\n");
} else {
dev->stats.tx_fifo_errors++;
dev_warn(&dev->dev,
"Unexpected TX queue failure: %d\n",
capacity);
}
}
dev->stats.tx_dropped++;
kfree_skb(skb);
return NETDEV_TX_OK;
}
virtqueue_kick(vi->svq);
skb_orphan(skb);
nf_reset(skb);
if (capacity < 2+MAX_SKB_FRAGS) {
netif_stop_queue(dev);
if (unlikely(!virtqueue_enable_cb_delayed(vi->svq))) {
capacity += free_old_xmit_skbs(vi);
if (capacity >= 2+MAX_SKB_FRAGS) {
netif_start_queue(dev);
virtqueue_disable_cb(vi->svq);
}
}
}
return NETDEV_TX_OK;
}
static int virtnet_set_mac_address(struct net_device *dev, void *p)
{
struct virtnet_info *vi = netdev_priv(dev);
struct virtio_device *vdev = vi->vdev;
int ret;
ret = eth_mac_addr(dev, p);
if (ret)
return ret;
if (virtio_has_feature(vdev, VIRTIO_NET_F_MAC))
vdev->config->set(vdev, offsetof(struct virtio_net_config, mac),
dev->dev_addr, dev->addr_len);
return 0;
}
static struct rtnl_link_stats64 *virtnet_stats(struct net_device *dev,
struct rtnl_link_stats64 *tot)
{
struct virtnet_info *vi = netdev_priv(dev);
int cpu;
unsigned int start;
for_each_possible_cpu(cpu) {
struct virtnet_stats __percpu *stats
= per_cpu_ptr(vi->stats, cpu);
u64 tpackets, tbytes, rpackets, rbytes;
do {
start = u64_stats_fetch_begin(&stats->syncp);
tpackets = stats->tx_packets;
tbytes = stats->tx_bytes;
rpackets = stats->rx_packets;
rbytes = stats->rx_bytes;
} while (u64_stats_fetch_retry(&stats->syncp, start));
tot->rx_packets += rpackets;
tot->tx_packets += tpackets;
tot->rx_bytes += rbytes;
tot->tx_bytes += tbytes;
}
tot->tx_dropped = dev->stats.tx_dropped;
tot->rx_dropped = dev->stats.rx_dropped;
tot->rx_length_errors = dev->stats.rx_length_errors;
tot->rx_frame_errors = dev->stats.rx_frame_errors;
return tot;
}
static void virtnet_netpoll(struct net_device *dev)
{
struct virtnet_info *vi = netdev_priv(dev);
napi_schedule(&vi->napi);
}
static int virtnet_open(struct net_device *dev)
{
struct virtnet_info *vi = netdev_priv(dev);
virtnet_napi_enable(vi);
return 0;
}
static bool virtnet_send_command(struct virtnet_info *vi, u8 class, u8 cmd,
struct scatterlist *data, int out, int in)
{
struct scatterlist *s, sg[VIRTNET_SEND_COMMAND_SG_MAX + 2];
struct virtio_net_ctrl_hdr ctrl;
virtio_net_ctrl_ack status = ~0;
unsigned int tmp;
int i;
BUG_ON(!virtio_has_feature(vi->vdev, VIRTIO_NET_F_CTRL_VQ) ||
(out + in > VIRTNET_SEND_COMMAND_SG_MAX));
out++;
in++;
ctrl.class = class;
ctrl.cmd = cmd;
sg_init_table(sg, out + in);
sg_set_buf(&sg[0], &ctrl, sizeof(ctrl));
for_each_sg(data, s, out + in - 2, i)
sg_set_buf(&sg[i + 1], sg_virt(s), s->length);
sg_set_buf(&sg[out + in - 1], &status, sizeof(status));
BUG_ON(virtqueue_add_buf(vi->cvq, sg, out, in, vi) < 0);
virtqueue_kick(vi->cvq);
while (!virtqueue_get_buf(vi->cvq, &tmp))
cpu_relax();
return status == VIRTIO_NET_OK;
}
static int virtnet_close(struct net_device *dev)
{
struct virtnet_info *vi = netdev_priv(dev);
napi_disable(&vi->napi);
return 0;
}
static void virtnet_set_rx_mode(struct net_device *dev)
{
struct virtnet_info *vi = netdev_priv(dev);
struct scatterlist sg[2];
u8 promisc, allmulti;
struct virtio_net_ctrl_mac *mac_data;
struct netdev_hw_addr *ha;
int uc_count;
int mc_count;
void *buf;
int i;
if (!virtio_has_feature(vi->vdev, VIRTIO_NET_F_CTRL_RX))
return;
promisc = ((dev->flags & IFF_PROMISC) != 0);
allmulti = ((dev->flags & IFF_ALLMULTI) != 0);
sg_init_one(sg, &promisc, sizeof(promisc));
if (!virtnet_send_command(vi, VIRTIO_NET_CTRL_RX,
VIRTIO_NET_CTRL_RX_PROMISC,
sg, 1, 0))
dev_warn(&dev->dev, "Failed to %sable promisc mode.\n",
promisc ? "en" : "dis");
sg_init_one(sg, &allmulti, sizeof(allmulti));
if (!virtnet_send_command(vi, VIRTIO_NET_CTRL_RX,
VIRTIO_NET_CTRL_RX_ALLMULTI,
sg, 1, 0))
dev_warn(&dev->dev, "Failed to %sable allmulti mode.\n",
allmulti ? "en" : "dis");
uc_count = netdev_uc_count(dev);
mc_count = netdev_mc_count(dev);
buf = kzalloc(((uc_count + mc_count) * ETH_ALEN) +
(2 * sizeof(mac_data->entries)), GFP_ATOMIC);
mac_data = buf;
if (!buf) {
dev_warn(&dev->dev, "No memory for MAC address buffer\n");
return;
}
sg_init_table(sg, 2);
mac_data->entries = uc_count;
i = 0;
netdev_for_each_uc_addr(ha, dev)
memcpy(&mac_data->macs[i++][0], ha->addr, ETH_ALEN);
sg_set_buf(&sg[0], mac_data,
sizeof(mac_data->entries) + (uc_count * ETH_ALEN));
mac_data = (void *)&mac_data->macs[uc_count][0];
mac_data->entries = mc_count;
i = 0;
netdev_for_each_mc_addr(ha, dev)
memcpy(&mac_data->macs[i++][0], ha->addr, ETH_ALEN);
sg_set_buf(&sg[1], mac_data,
sizeof(mac_data->entries) + (mc_count * ETH_ALEN));
if (!virtnet_send_command(vi, VIRTIO_NET_CTRL_MAC,
VIRTIO_NET_CTRL_MAC_TABLE_SET,
sg, 2, 0))
dev_warn(&dev->dev, "Failed to set MAC fitler table.\n");
kfree(buf);
}
static void virtnet_vlan_rx_add_vid(struct net_device *dev, u16 vid)
{
struct virtnet_info *vi = netdev_priv(dev);
struct scatterlist sg;
sg_init_one(&sg, &vid, sizeof(vid));
if (!virtnet_send_command(vi, VIRTIO_NET_CTRL_VLAN,
VIRTIO_NET_CTRL_VLAN_ADD, &sg, 1, 0))
dev_warn(&dev->dev, "Failed to add VLAN ID %d.\n", vid);
}
static void virtnet_vlan_rx_kill_vid(struct net_device *dev, u16 vid)
{
struct virtnet_info *vi = netdev_priv(dev);
struct scatterlist sg;
sg_init_one(&sg, &vid, sizeof(vid));
if (!virtnet_send_command(vi, VIRTIO_NET_CTRL_VLAN,
VIRTIO_NET_CTRL_VLAN_DEL, &sg, 1, 0))
dev_warn(&dev->dev, "Failed to kill VLAN ID %d.\n", vid);
}
static void virtnet_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *ring)
{
struct virtnet_info *vi = netdev_priv(dev);
ring->rx_max_pending = virtqueue_get_vring_size(vi->rvq);
ring->tx_max_pending = virtqueue_get_vring_size(vi->svq);
ring->rx_pending = ring->rx_max_pending;
ring->tx_pending = ring->tx_max_pending;
}
static int virtnet_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < MIN_MTU || new_mtu > MAX_MTU)
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static void virtnet_update_status(struct virtnet_info *vi)
{
u16 v;
if (virtio_config_val(vi->vdev, VIRTIO_NET_F_STATUS,
offsetof(struct virtio_net_config, status),
&v) < 0)
return;
v &= VIRTIO_NET_S_LINK_UP;
if (vi->status == v)
return;
vi->status = v;
if (vi->status & VIRTIO_NET_S_LINK_UP) {
netif_carrier_on(vi->dev);
netif_wake_queue(vi->dev);
} else {
netif_carrier_off(vi->dev);
netif_stop_queue(vi->dev);
}
}
static void virtnet_config_changed(struct virtio_device *vdev)
{
struct virtnet_info *vi = vdev->priv;
virtnet_update_status(vi);
}
static int virtnet_probe(struct virtio_device *vdev)
{
int err;
struct net_device *dev;
struct virtnet_info *vi;
struct virtqueue *vqs[3];
vq_callback_t *callbacks[] = { skb_recv_done, skb_xmit_done, NULL};
const char *names[] = { "input", "output", "control" };
int nvqs;
dev = alloc_etherdev(sizeof(struct virtnet_info));
if (!dev)
return -ENOMEM;
dev->priv_flags |= IFF_UNICAST_FLT;
dev->netdev_ops = &virtnet_netdev;
dev->features = NETIF_F_HIGHDMA;
SET_ETHTOOL_OPS(dev, &virtnet_ethtool_ops);
SET_NETDEV_DEV(dev, &vdev->dev);
if (virtio_has_feature(vdev, VIRTIO_NET_F_CSUM)) {
dev->hw_features |= NETIF_F_HW_CSUM|NETIF_F_SG|NETIF_F_FRAGLIST;
if (csum)
dev->features |= NETIF_F_HW_CSUM|NETIF_F_SG|NETIF_F_FRAGLIST;
if (virtio_has_feature(vdev, VIRTIO_NET_F_GSO)) {
dev->hw_features |= NETIF_F_TSO | NETIF_F_UFO
| NETIF_F_TSO_ECN | NETIF_F_TSO6;
}
if (virtio_has_feature(vdev, VIRTIO_NET_F_HOST_TSO4))
dev->hw_features |= NETIF_F_TSO;
if (virtio_has_feature(vdev, VIRTIO_NET_F_HOST_TSO6))
dev->hw_features |= NETIF_F_TSO6;
if (virtio_has_feature(vdev, VIRTIO_NET_F_HOST_ECN))
dev->hw_features |= NETIF_F_TSO_ECN;
if (virtio_has_feature(vdev, VIRTIO_NET_F_HOST_UFO))
dev->hw_features |= NETIF_F_UFO;
if (gso)
dev->features |= dev->hw_features & (NETIF_F_ALL_TSO|NETIF_F_UFO);
}
if (virtio_config_val_len(vdev, VIRTIO_NET_F_MAC,
offsetof(struct virtio_net_config, mac),
dev->dev_addr, dev->addr_len) < 0)
random_ether_addr(dev->dev_addr);
vi = netdev_priv(dev);
netif_napi_add(dev, &vi->napi, virtnet_poll, napi_weight);
vi->dev = dev;
vi->vdev = vdev;
vdev->priv = vi;
vi->pages = NULL;
vi->stats = alloc_percpu(struct virtnet_stats);
err = -ENOMEM;
if (vi->stats == NULL)
goto free;
INIT_DELAYED_WORK(&vi->refill, refill_work);
sg_init_table(vi->rx_sg, ARRAY_SIZE(vi->rx_sg));
sg_init_table(vi->tx_sg, ARRAY_SIZE(vi->tx_sg));
if (virtio_has_feature(vdev, VIRTIO_NET_F_GUEST_TSO4) ||
virtio_has_feature(vdev, VIRTIO_NET_F_GUEST_TSO6) ||
virtio_has_feature(vdev, VIRTIO_NET_F_GUEST_ECN))
vi->big_packets = true;
if (virtio_has_feature(vdev, VIRTIO_NET_F_MRG_RXBUF))
vi->mergeable_rx_bufs = true;
nvqs = virtio_has_feature(vi->vdev, VIRTIO_NET_F_CTRL_VQ) ? 3 : 2;
err = vdev->config->find_vqs(vdev, nvqs, vqs, callbacks, names);
if (err)
goto free_stats;
vi->rvq = vqs[0];
vi->svq = vqs[1];
if (virtio_has_feature(vi->vdev, VIRTIO_NET_F_CTRL_VQ)) {
vi->cvq = vqs[2];
if (virtio_has_feature(vi->vdev, VIRTIO_NET_F_CTRL_VLAN))
dev->features |= NETIF_F_HW_VLAN_FILTER;
}
err = register_netdev(dev);
if (err) {
pr_debug("virtio_net: registering device failed\n");
goto free_vqs;
}
try_fill_recv(vi, GFP_KERNEL);
if (vi->num == 0) {
err = -ENOMEM;
goto unregister;
}
if (virtio_has_feature(vi->vdev, VIRTIO_NET_F_STATUS)) {
netif_carrier_off(dev);
virtnet_update_status(vi);
} else {
vi->status = VIRTIO_NET_S_LINK_UP;
netif_carrier_on(dev);
}
pr_debug("virtnet: registered device %s\n", dev->name);
return 0;
unregister:
unregister_netdev(dev);
cancel_delayed_work_sync(&vi->refill);
free_vqs:
vdev->config->del_vqs(vdev);
free_stats:
free_percpu(vi->stats);
free:
free_netdev(dev);
return err;
}
static void free_unused_bufs(struct virtnet_info *vi)
{
void *buf;
while (1) {
buf = virtqueue_detach_unused_buf(vi->svq);
if (!buf)
break;
dev_kfree_skb(buf);
}
while (1) {
buf = virtqueue_detach_unused_buf(vi->rvq);
if (!buf)
break;
if (vi->mergeable_rx_bufs || vi->big_packets)
give_pages(vi, buf);
else
dev_kfree_skb(buf);
--vi->num;
}
BUG_ON(vi->num != 0);
}
static void __devexit virtnet_remove(struct virtio_device *vdev)
{
struct virtnet_info *vi = vdev->priv;
vdev->config->reset(vdev);
unregister_netdev(vi->dev);
cancel_delayed_work_sync(&vi->refill);
free_unused_bufs(vi);
vdev->config->del_vqs(vi->vdev);
while (vi->pages)
__free_pages(get_a_page(vi, GFP_KERNEL), 0);
free_percpu(vi->stats);
free_netdev(vi->dev);
}
static int __init init(void)
{
return register_virtio_driver(&virtio_net_driver);
}
static void __exit fini(void)
{
unregister_virtio_driver(&virtio_net_driver);
}
