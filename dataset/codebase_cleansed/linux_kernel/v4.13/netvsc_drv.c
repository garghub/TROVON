static void netvsc_set_multicast_list(struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct netvsc_device *nvdev = rtnl_dereference(net_device_ctx->nvdev);
rndis_filter_update(nvdev);
}
static int netvsc_open(struct net_device *net)
{
struct net_device_context *ndev_ctx = netdev_priv(net);
struct netvsc_device *nvdev = ndev_ctx->nvdev;
struct rndis_device *rdev;
int ret = 0;
netif_carrier_off(net);
ret = rndis_filter_open(nvdev);
if (ret != 0) {
netdev_err(net, "unable to open device (ret %d).\n", ret);
return ret;
}
netif_tx_wake_all_queues(net);
rdev = nvdev->extension;
if (!rdev->link_state && !ndev_ctx->datapath)
netif_carrier_on(net);
return ret;
}
static int netvsc_close(struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct netvsc_device *nvdev = rtnl_dereference(net_device_ctx->nvdev);
int ret;
u32 aread, i, msec = 10, retry = 0, retry_max = 20;
struct vmbus_channel *chn;
netif_tx_disable(net);
ret = rndis_filter_close(nvdev);
if (ret != 0) {
netdev_err(net, "unable to close device (ret %d).\n", ret);
return ret;
}
while (true) {
aread = 0;
for (i = 0; i < nvdev->num_chn; i++) {
chn = nvdev->chan_table[i].channel;
if (!chn)
continue;
aread = hv_get_bytes_to_read(&chn->inbound);
if (aread)
break;
aread = hv_get_bytes_to_read(&chn->outbound);
if (aread)
break;
}
retry++;
if (retry > retry_max || aread == 0)
break;
msleep(msec);
if (msec < 1000)
msec *= 2;
}
if (aread) {
netdev_err(net, "Ring buffer not empty after closing rndis\n");
ret = -ETIMEDOUT;
}
return ret;
}
static void *init_ppi_data(struct rndis_message *msg, u32 ppi_size,
int pkt_type)
{
struct rndis_packet *rndis_pkt;
struct rndis_per_packet_info *ppi;
rndis_pkt = &msg->msg.pkt;
rndis_pkt->data_offset += ppi_size;
ppi = (struct rndis_per_packet_info *)((void *)rndis_pkt +
rndis_pkt->per_pkt_info_offset + rndis_pkt->per_pkt_info_len);
ppi->size = ppi_size;
ppi->type = pkt_type;
ppi->ppi_offset = sizeof(struct rndis_per_packet_info);
rndis_pkt->per_pkt_info_len += ppi_size;
return ppi;
}
static inline u32 netvsc_get_hash(struct sk_buff *skb, struct sock *sk)
{
struct flow_keys flow;
u32 hash;
static u32 hashrnd __read_mostly;
net_get_random_once(&hashrnd, sizeof(hashrnd));
if (!skb_flow_dissect_flow_keys(skb, &flow, 0))
return 0;
if (flow.basic.ip_proto == IPPROTO_TCP) {
return skb_get_hash(skb);
} else {
if (flow.basic.n_proto == htons(ETH_P_IP))
hash = jhash2((u32 *)&flow.addrs.v4addrs, 2, hashrnd);
else if (flow.basic.n_proto == htons(ETH_P_IPV6))
hash = jhash2((u32 *)&flow.addrs.v6addrs, 8, hashrnd);
else
hash = 0;
skb_set_hash(skb, hash, PKT_HASH_TYPE_L3);
}
return hash;
}
static inline int netvsc_get_tx_queue(struct net_device *ndev,
struct sk_buff *skb, int old_idx)
{
const struct net_device_context *ndc = netdev_priv(ndev);
struct sock *sk = skb->sk;
int q_idx;
q_idx = ndc->tx_send_table[netvsc_get_hash(skb, sk) &
(VRSS_SEND_TAB_SIZE - 1)];
if (q_idx != old_idx &&
sk && sk_fullsock(sk) && rcu_access_pointer(sk->sk_dst_cache))
sk_tx_queue_set(sk, q_idx);
return q_idx;
}
static u16 netvsc_select_queue(struct net_device *ndev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
unsigned int num_tx_queues = ndev->real_num_tx_queues;
int q_idx = sk_tx_queue_get(skb->sk);
if (q_idx < 0 || skb->ooo_okay) {
if (skb_rx_queue_recorded(skb))
q_idx = skb_get_rx_queue(skb);
else
q_idx = netvsc_get_tx_queue(ndev, skb, q_idx);
}
while (unlikely(q_idx >= num_tx_queues))
q_idx -= num_tx_queues;
return q_idx;
}
static u32 fill_pg_buf(struct page *page, u32 offset, u32 len,
struct hv_page_buffer *pb)
{
int j = 0;
page += (offset >> PAGE_SHIFT);
offset &= ~PAGE_MASK;
while (len > 0) {
unsigned long bytes;
bytes = PAGE_SIZE - offset;
if (bytes > len)
bytes = len;
pb[j].pfn = page_to_pfn(page);
pb[j].offset = offset;
pb[j].len = bytes;
offset += bytes;
len -= bytes;
if (offset == PAGE_SIZE && len) {
page++;
offset = 0;
j++;
}
}
return j + 1;
}
static u32 init_page_array(void *hdr, u32 len, struct sk_buff *skb,
struct hv_netvsc_packet *packet,
struct hv_page_buffer **page_buf)
{
struct hv_page_buffer *pb = *page_buf;
u32 slots_used = 0;
char *data = skb->data;
int frags = skb_shinfo(skb)->nr_frags;
int i;
if (hdr != NULL)
slots_used += fill_pg_buf(virt_to_page(hdr),
offset_in_page(hdr),
len, &pb[slots_used]);
packet->rmsg_size = len;
packet->rmsg_pgcnt = slots_used;
slots_used += fill_pg_buf(virt_to_page(data),
offset_in_page(data),
skb_headlen(skb), &pb[slots_used]);
for (i = 0; i < frags; i++) {
skb_frag_t *frag = skb_shinfo(skb)->frags + i;
slots_used += fill_pg_buf(skb_frag_page(frag),
frag->page_offset,
skb_frag_size(frag), &pb[slots_used]);
}
return slots_used;
}
static int count_skb_frag_slots(struct sk_buff *skb)
{
int i, frags = skb_shinfo(skb)->nr_frags;
int pages = 0;
for (i = 0; i < frags; i++) {
skb_frag_t *frag = skb_shinfo(skb)->frags + i;
unsigned long size = skb_frag_size(frag);
unsigned long offset = frag->page_offset;
offset &= ~PAGE_MASK;
pages += PFN_UP(offset + size);
}
return pages;
}
static int netvsc_get_slots(struct sk_buff *skb)
{
char *data = skb->data;
unsigned int offset = offset_in_page(data);
unsigned int len = skb_headlen(skb);
int slots;
int frag_slots;
slots = DIV_ROUND_UP(offset + len, PAGE_SIZE);
frag_slots = count_skb_frag_slots(skb);
return slots + frag_slots;
}
static u32 net_checksum_info(struct sk_buff *skb)
{
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *ip = ip_hdr(skb);
if (ip->protocol == IPPROTO_TCP)
return TRANSPORT_INFO_IPV4_TCP;
else if (ip->protocol == IPPROTO_UDP)
return TRANSPORT_INFO_IPV4_UDP;
} else {
struct ipv6hdr *ip6 = ipv6_hdr(skb);
if (ip6->nexthdr == IPPROTO_TCP)
return TRANSPORT_INFO_IPV6_TCP;
else if (ipv6_hdr(skb)->nexthdr == IPPROTO_UDP)
return TRANSPORT_INFO_IPV6_UDP;
}
return TRANSPORT_INFO_NOT_IP;
}
static int netvsc_start_xmit(struct sk_buff *skb, struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct hv_netvsc_packet *packet = NULL;
int ret;
unsigned int num_data_pgs;
struct rndis_message *rndis_msg;
struct rndis_packet *rndis_pkt;
u32 rndis_msg_size;
struct rndis_per_packet_info *ppi;
u32 hash;
struct hv_page_buffer page_buf[MAX_PAGE_BUFFER_COUNT];
struct hv_page_buffer *pb = page_buf;
num_data_pgs = netvsc_get_slots(skb) + 2;
if (unlikely(num_data_pgs > MAX_PAGE_BUFFER_COUNT)) {
++net_device_ctx->eth_stats.tx_scattered;
if (skb_linearize(skb))
goto no_memory;
num_data_pgs = netvsc_get_slots(skb) + 2;
if (num_data_pgs > MAX_PAGE_BUFFER_COUNT) {
++net_device_ctx->eth_stats.tx_too_big;
goto drop;
}
}
ret = skb_cow_head(skb, RNDIS_AND_PPI_SIZE);
if (ret)
goto no_memory;
BUILD_BUG_ON(sizeof(struct hv_netvsc_packet) >
FIELD_SIZEOF(struct sk_buff, cb));
packet = (struct hv_netvsc_packet *)skb->cb;
packet->q_idx = skb_get_queue_mapping(skb);
packet->total_data_buflen = skb->len;
packet->total_bytes = skb->len;
packet->total_packets = 1;
rndis_msg = (struct rndis_message *)skb->head;
memset(rndis_msg, 0, RNDIS_AND_PPI_SIZE);
rndis_msg->ndis_msg_type = RNDIS_MSG_PACKET;
rndis_msg->msg_len = packet->total_data_buflen;
rndis_pkt = &rndis_msg->msg.pkt;
rndis_pkt->data_offset = sizeof(struct rndis_packet);
rndis_pkt->data_len = packet->total_data_buflen;
rndis_pkt->per_pkt_info_offset = sizeof(struct rndis_packet);
rndis_msg_size = RNDIS_MESSAGE_SIZE(struct rndis_packet);
hash = skb_get_hash_raw(skb);
if (hash != 0 && net->real_num_tx_queues > 1) {
rndis_msg_size += NDIS_HASH_PPI_SIZE;
ppi = init_ppi_data(rndis_msg, NDIS_HASH_PPI_SIZE,
NBL_HASH_VALUE);
*(u32 *)((void *)ppi + ppi->ppi_offset) = hash;
}
if (skb_vlan_tag_present(skb)) {
struct ndis_pkt_8021q_info *vlan;
rndis_msg_size += NDIS_VLAN_PPI_SIZE;
ppi = init_ppi_data(rndis_msg, NDIS_VLAN_PPI_SIZE,
IEEE_8021Q_INFO);
vlan = (struct ndis_pkt_8021q_info *)((void *)ppi +
ppi->ppi_offset);
vlan->vlanid = skb->vlan_tci & VLAN_VID_MASK;
vlan->pri = (skb->vlan_tci & VLAN_PRIO_MASK) >>
VLAN_PRIO_SHIFT;
}
if (skb_is_gso(skb)) {
struct ndis_tcp_lso_info *lso_info;
rndis_msg_size += NDIS_LSO_PPI_SIZE;
ppi = init_ppi_data(rndis_msg, NDIS_LSO_PPI_SIZE,
TCP_LARGESEND_PKTINFO);
lso_info = (struct ndis_tcp_lso_info *)((void *)ppi +
ppi->ppi_offset);
lso_info->lso_v2_transmit.type = NDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE;
if (skb->protocol == htons(ETH_P_IP)) {
lso_info->lso_v2_transmit.ip_version =
NDIS_TCP_LARGE_SEND_OFFLOAD_IPV4;
ip_hdr(skb)->tot_len = 0;
ip_hdr(skb)->check = 0;
tcp_hdr(skb)->check =
~csum_tcpudp_magic(ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr, 0, IPPROTO_TCP, 0);
} else {
lso_info->lso_v2_transmit.ip_version =
NDIS_TCP_LARGE_SEND_OFFLOAD_IPV6;
ipv6_hdr(skb)->payload_len = 0;
tcp_hdr(skb)->check =
~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr, 0, IPPROTO_TCP, 0);
}
lso_info->lso_v2_transmit.tcp_header_offset = skb_transport_offset(skb);
lso_info->lso_v2_transmit.mss = skb_shinfo(skb)->gso_size;
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
if (net_checksum_info(skb) & net_device_ctx->tx_checksum_mask) {
struct ndis_tcp_ip_checksum_info *csum_info;
rndis_msg_size += NDIS_CSUM_PPI_SIZE;
ppi = init_ppi_data(rndis_msg, NDIS_CSUM_PPI_SIZE,
TCPIP_CHKSUM_PKTINFO);
csum_info = (struct ndis_tcp_ip_checksum_info *)((void *)ppi +
ppi->ppi_offset);
csum_info->transmit.tcp_header_offset = skb_transport_offset(skb);
if (skb->protocol == htons(ETH_P_IP)) {
csum_info->transmit.is_ipv4 = 1;
if (ip_hdr(skb)->protocol == IPPROTO_TCP)
csum_info->transmit.tcp_checksum = 1;
else
csum_info->transmit.udp_checksum = 1;
} else {
csum_info->transmit.is_ipv6 = 1;
if (ipv6_hdr(skb)->nexthdr == IPPROTO_TCP)
csum_info->transmit.tcp_checksum = 1;
else
csum_info->transmit.udp_checksum = 1;
}
} else {
if (skb_checksum_help(skb))
goto drop;
}
}
rndis_msg->msg_len += rndis_msg_size;
packet->total_data_buflen = rndis_msg->msg_len;
packet->page_buf_cnt = init_page_array(rndis_msg, rndis_msg_size,
skb, packet, &pb);
skb_tx_timestamp(skb);
ret = netvsc_send(net_device_ctx->device_ctx, packet,
rndis_msg, &pb, skb);
if (likely(ret == 0))
return NETDEV_TX_OK;
if (ret == -EAGAIN) {
++net_device_ctx->eth_stats.tx_busy;
return NETDEV_TX_BUSY;
}
if (ret == -ENOSPC)
++net_device_ctx->eth_stats.tx_no_space;
drop:
dev_kfree_skb_any(skb);
net->stats.tx_dropped++;
return NETDEV_TX_OK;
no_memory:
++net_device_ctx->eth_stats.tx_no_memory;
goto drop;
}
void netvsc_linkstatus_callback(struct hv_device *device_obj,
struct rndis_message *resp)
{
struct rndis_indicate_status *indicate = &resp->msg.indicate_status;
struct net_device *net;
struct net_device_context *ndev_ctx;
struct netvsc_reconfig *event;
unsigned long flags;
net = hv_get_drvdata(device_obj);
if (!net)
return;
ndev_ctx = netdev_priv(net);
if (indicate->status == RNDIS_STATUS_LINK_SPEED_CHANGE) {
u32 speed;
speed = *(u32 *)((void *)indicate + indicate->
status_buf_offset) / 10000;
ndev_ctx->speed = speed;
return;
}
if (indicate->status != RNDIS_STATUS_NETWORK_CHANGE &&
indicate->status != RNDIS_STATUS_MEDIA_CONNECT &&
indicate->status != RNDIS_STATUS_MEDIA_DISCONNECT)
return;
if (net->reg_state != NETREG_REGISTERED)
return;
event = kzalloc(sizeof(*event), GFP_ATOMIC);
if (!event)
return;
event->event = indicate->status;
spin_lock_irqsave(&ndev_ctx->lock, flags);
list_add_tail(&event->list, &ndev_ctx->reconfig_events);
spin_unlock_irqrestore(&ndev_ctx->lock, flags);
schedule_delayed_work(&ndev_ctx->dwork, 0);
}
static struct sk_buff *netvsc_alloc_recv_skb(struct net_device *net,
struct napi_struct *napi,
const struct ndis_tcp_ip_checksum_info *csum_info,
const struct ndis_pkt_8021q_info *vlan,
void *data, u32 buflen)
{
struct sk_buff *skb;
skb = napi_alloc_skb(napi, buflen);
if (!skb)
return skb;
skb_put_data(skb, data, buflen);
skb->protocol = eth_type_trans(skb, net);
skb_checksum_none_assert(skb);
if (csum_info && (net->features & NETIF_F_RXCSUM)) {
if (csum_info->receive.tcp_checksum_succeeded ||
csum_info->receive.udp_checksum_succeeded)
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
if (vlan) {
u16 vlan_tci = vlan->vlanid | (vlan->pri << VLAN_PRIO_SHIFT);
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
vlan_tci);
}
return skb;
}
int netvsc_recv_callback(struct net_device *net,
struct vmbus_channel *channel,
void *data, u32 len,
const struct ndis_tcp_ip_checksum_info *csum_info,
const struct ndis_pkt_8021q_info *vlan)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct netvsc_device *net_device;
u16 q_idx = channel->offermsg.offer.sub_channel_index;
struct netvsc_channel *nvchan;
struct net_device *vf_netdev;
struct sk_buff *skb;
struct netvsc_stats *rx_stats;
if (net->reg_state != NETREG_REGISTERED)
return NVSP_STAT_FAIL;
rcu_read_lock();
net_device = rcu_dereference(net_device_ctx->nvdev);
if (unlikely(!net_device))
goto drop;
nvchan = &net_device->chan_table[q_idx];
vf_netdev = rcu_dereference(net_device_ctx->vf_netdev);
if (vf_netdev && (vf_netdev->flags & IFF_UP))
net = vf_netdev;
skb = netvsc_alloc_recv_skb(net, &nvchan->napi,
csum_info, vlan, data, len);
if (unlikely(!skb)) {
drop:
++net->stats.rx_dropped;
rcu_read_unlock();
return NVSP_STAT_FAIL;
}
if (net != vf_netdev)
skb_record_rx_queue(skb, q_idx);
rx_stats = &nvchan->rx_stats;
u64_stats_update_begin(&rx_stats->syncp);
rx_stats->packets++;
rx_stats->bytes += len;
if (skb->pkt_type == PACKET_BROADCAST)
++rx_stats->broadcast;
else if (skb->pkt_type == PACKET_MULTICAST)
++rx_stats->multicast;
u64_stats_update_end(&rx_stats->syncp);
napi_gro_receive(&nvchan->napi, skb);
rcu_read_unlock();
return 0;
}
static void netvsc_get_drvinfo(struct net_device *net,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
}
static void netvsc_get_channels(struct net_device *net,
struct ethtool_channels *channel)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct netvsc_device *nvdev = rtnl_dereference(net_device_ctx->nvdev);
if (nvdev) {
channel->max_combined = nvdev->max_chn;
channel->combined_count = nvdev->num_chn;
}
}
static int netvsc_set_queues(struct net_device *net, struct hv_device *dev,
u32 num_chn)
{
struct netvsc_device_info device_info;
int ret;
memset(&device_info, 0, sizeof(device_info));
device_info.num_chn = num_chn;
device_info.ring_size = ring_size;
device_info.max_num_vrss_chns = num_chn;
ret = rndis_filter_device_add(dev, &device_info);
if (ret)
return ret;
ret = netif_set_real_num_tx_queues(net, num_chn);
if (ret)
return ret;
ret = netif_set_real_num_rx_queues(net, num_chn);
return ret;
}
static int netvsc_set_channels(struct net_device *net,
struct ethtool_channels *channels)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct hv_device *dev = net_device_ctx->device_ctx;
struct netvsc_device *nvdev = rtnl_dereference(net_device_ctx->nvdev);
unsigned int count = channels->combined_count;
bool was_running;
int ret;
if (count == 0 ||
channels->rx_count || channels->tx_count || channels->other_count)
return -EINVAL;
if (count > net->num_tx_queues || count > VRSS_CHANNEL_MAX)
return -EINVAL;
if (!nvdev || nvdev->destroy)
return -ENODEV;
if (nvdev->nvsp_version < NVSP_PROTOCOL_VERSION_5)
return -EINVAL;
if (count > nvdev->max_chn)
return -EINVAL;
was_running = netif_running(net);
if (was_running) {
ret = netvsc_close(net);
if (ret)
return ret;
}
rndis_filter_device_remove(dev, nvdev);
ret = netvsc_set_queues(net, dev, count);
if (ret == 0)
nvdev->num_chn = count;
else
netvsc_set_queues(net, dev, nvdev->num_chn);
if (was_running)
ret = netvsc_open(net);
schedule_delayed_work(&net_device_ctx->dwork, 0);
return ret;
}
static bool
netvsc_validate_ethtool_ss_cmd(const struct ethtool_link_ksettings *cmd)
{
struct ethtool_link_ksettings diff1 = *cmd;
struct ethtool_link_ksettings diff2 = {};
diff1.base.speed = 0;
diff1.base.duplex = 0;
ethtool_link_ksettings_zero_link_mode(&diff1, advertising);
diff1.base.cmd = 0;
diff2.base.port = PORT_OTHER;
return !memcmp(&diff1, &diff2, sizeof(diff1));
}
static void netvsc_init_settings(struct net_device *dev)
{
struct net_device_context *ndc = netdev_priv(dev);
ndc->speed = SPEED_UNKNOWN;
ndc->duplex = DUPLEX_FULL;
}
static int netvsc_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
struct net_device_context *ndc = netdev_priv(dev);
cmd->base.speed = ndc->speed;
cmd->base.duplex = ndc->duplex;
cmd->base.port = PORT_OTHER;
return 0;
}
static int netvsc_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *cmd)
{
struct net_device_context *ndc = netdev_priv(dev);
u32 speed;
speed = cmd->base.speed;
if (!ethtool_validate_speed(speed) ||
!ethtool_validate_duplex(cmd->base.duplex) ||
!netvsc_validate_ethtool_ss_cmd(cmd))
return -EINVAL;
ndc->speed = speed;
ndc->duplex = cmd->base.duplex;
return 0;
}
static int netvsc_change_mtu(struct net_device *ndev, int mtu)
{
struct net_device_context *ndevctx = netdev_priv(ndev);
struct netvsc_device *nvdev = rtnl_dereference(ndevctx->nvdev);
struct hv_device *hdev = ndevctx->device_ctx;
struct netvsc_device_info device_info;
bool was_running;
int ret = 0;
if (!nvdev || nvdev->destroy)
return -ENODEV;
was_running = netif_running(ndev);
if (was_running) {
ret = netvsc_close(ndev);
if (ret)
return ret;
}
memset(&device_info, 0, sizeof(device_info));
device_info.ring_size = ring_size;
device_info.num_chn = nvdev->num_chn;
device_info.max_num_vrss_chns = nvdev->num_chn;
rndis_filter_device_remove(hdev, nvdev);
ndev->mtu = mtu;
rndis_filter_device_add(hdev, &device_info);
if (was_running)
ret = netvsc_open(ndev);
schedule_delayed_work(&ndevctx->dwork, 0);
return ret;
}
static void netvsc_get_stats64(struct net_device *net,
struct rtnl_link_stats64 *t)
{
struct net_device_context *ndev_ctx = netdev_priv(net);
struct netvsc_device *nvdev = rcu_dereference_rtnl(ndev_ctx->nvdev);
int i;
if (!nvdev)
return;
for (i = 0; i < nvdev->num_chn; i++) {
const struct netvsc_channel *nvchan = &nvdev->chan_table[i];
const struct netvsc_stats *stats;
u64 packets, bytes, multicast;
unsigned int start;
stats = &nvchan->tx_stats;
do {
start = u64_stats_fetch_begin_irq(&stats->syncp);
packets = stats->packets;
bytes = stats->bytes;
} while (u64_stats_fetch_retry_irq(&stats->syncp, start));
t->tx_bytes += bytes;
t->tx_packets += packets;
stats = &nvchan->rx_stats;
do {
start = u64_stats_fetch_begin_irq(&stats->syncp);
packets = stats->packets;
bytes = stats->bytes;
multicast = stats->multicast + stats->broadcast;
} while (u64_stats_fetch_retry_irq(&stats->syncp, start));
t->rx_bytes += bytes;
t->rx_packets += packets;
t->multicast += multicast;
}
t->tx_dropped = net->stats.tx_dropped;
t->tx_errors = net->stats.tx_errors;
t->rx_dropped = net->stats.rx_dropped;
t->rx_errors = net->stats.rx_errors;
}
static int netvsc_set_mac_addr(struct net_device *ndev, void *p)
{
struct sockaddr *addr = p;
char save_adr[ETH_ALEN];
unsigned char save_aatype;
int err;
memcpy(save_adr, ndev->dev_addr, ETH_ALEN);
save_aatype = ndev->addr_assign_type;
err = eth_mac_addr(ndev, p);
if (err != 0)
return err;
err = rndis_filter_set_device_mac(ndev, addr->sa_data);
if (err != 0) {
memcpy(ndev->dev_addr, save_adr, ETH_ALEN);
ndev->addr_assign_type = save_aatype;
}
return err;
}
static int netvsc_get_sset_count(struct net_device *dev, int string_set)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *nvdev = rtnl_dereference(ndc->nvdev);
if (!nvdev)
return -ENODEV;
switch (string_set) {
case ETH_SS_STATS:
return NETVSC_GLOBAL_STATS_LEN + NETVSC_QUEUE_STATS_LEN(nvdev);
default:
return -EINVAL;
}
}
static void netvsc_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *nvdev = rcu_dereference(ndc->nvdev);
const void *nds = &ndc->eth_stats;
const struct netvsc_stats *qstats;
unsigned int start;
u64 packets, bytes;
int i, j;
if (!nvdev)
return;
for (i = 0; i < NETVSC_GLOBAL_STATS_LEN; i++)
data[i] = *(unsigned long *)(nds + netvsc_stats[i].offset);
for (j = 0; j < nvdev->num_chn; j++) {
qstats = &nvdev->chan_table[j].tx_stats;
do {
start = u64_stats_fetch_begin_irq(&qstats->syncp);
packets = qstats->packets;
bytes = qstats->bytes;
} while (u64_stats_fetch_retry_irq(&qstats->syncp, start));
data[i++] = packets;
data[i++] = bytes;
qstats = &nvdev->chan_table[j].rx_stats;
do {
start = u64_stats_fetch_begin_irq(&qstats->syncp);
packets = qstats->packets;
bytes = qstats->bytes;
} while (u64_stats_fetch_retry_irq(&qstats->syncp, start));
data[i++] = packets;
data[i++] = bytes;
}
}
static void netvsc_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *nvdev = rcu_dereference(ndc->nvdev);
u8 *p = data;
int i;
if (!nvdev)
return;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < ARRAY_SIZE(netvsc_stats); i++)
memcpy(p + i * ETH_GSTRING_LEN,
netvsc_stats[i].name, ETH_GSTRING_LEN);
p += i * ETH_GSTRING_LEN;
for (i = 0; i < nvdev->num_chn; i++) {
sprintf(p, "tx_queue_%u_packets", i);
p += ETH_GSTRING_LEN;
sprintf(p, "tx_queue_%u_bytes", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rx_queue_%u_packets", i);
p += ETH_GSTRING_LEN;
sprintf(p, "rx_queue_%u_bytes", i);
p += ETH_GSTRING_LEN;
}
break;
}
}
static int
netvsc_get_rss_hash_opts(struct netvsc_device *nvdev,
struct ethtool_rxnfc *info)
{
info->data = RXH_IP_SRC | RXH_IP_DST;
switch (info->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case UDP_V4_FLOW:
case UDP_V6_FLOW:
case IPV4_FLOW:
case IPV6_FLOW:
break;
default:
info->data = 0;
break;
}
return 0;
}
static int
netvsc_get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *info,
u32 *rules)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *nvdev = rcu_dereference(ndc->nvdev);
if (!nvdev)
return -ENODEV;
switch (info->cmd) {
case ETHTOOL_GRXRINGS:
info->data = nvdev->num_chn;
return 0;
case ETHTOOL_GRXFH:
return netvsc_get_rss_hash_opts(nvdev, info);
}
return -EOPNOTSUPP;
}
static void netvsc_poll_controller(struct net_device *dev)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *ndev;
int i;
rcu_read_lock();
ndev = rcu_dereference(ndc->nvdev);
if (ndev) {
for (i = 0; i < ndev->num_chn; i++) {
struct netvsc_channel *nvchan = &ndev->chan_table[i];
napi_schedule(&nvchan->napi);
}
}
rcu_read_unlock();
}
static u32 netvsc_get_rxfh_key_size(struct net_device *dev)
{
return NETVSC_HASH_KEYLEN;
}
static u32 netvsc_rss_indir_size(struct net_device *dev)
{
return ITAB_NUM;
}
static int netvsc_get_rxfh(struct net_device *dev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *ndev = rcu_dereference(ndc->nvdev);
struct rndis_device *rndis_dev;
int i;
if (!ndev)
return -ENODEV;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
rndis_dev = ndev->extension;
if (indir) {
for (i = 0; i < ITAB_NUM; i++)
indir[i] = rndis_dev->ind_table[i];
}
if (key)
memcpy(key, rndis_dev->rss_key, NETVSC_HASH_KEYLEN);
return 0;
}
static int netvsc_set_rxfh(struct net_device *dev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct net_device_context *ndc = netdev_priv(dev);
struct netvsc_device *ndev = rtnl_dereference(ndc->nvdev);
struct rndis_device *rndis_dev;
int i;
if (!ndev)
return -ENODEV;
if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
return -EOPNOTSUPP;
rndis_dev = ndev->extension;
if (indir) {
for (i = 0; i < ITAB_NUM; i++)
if (indir[i] >= VRSS_CHANNEL_MAX)
return -EINVAL;
for (i = 0; i < ITAB_NUM; i++)
rndis_dev->ind_table[i] = indir[i];
}
if (!key) {
if (!indir)
return 0;
key = rndis_dev->rss_key;
}
return rndis_filter_set_rss_param(rndis_dev, key, ndev->num_chn);
}
static void netvsc_link_change(struct work_struct *w)
{
struct net_device_context *ndev_ctx =
container_of(w, struct net_device_context, dwork.work);
struct hv_device *device_obj = ndev_ctx->device_ctx;
struct net_device *net = hv_get_drvdata(device_obj);
struct netvsc_device *net_device;
struct rndis_device *rdev;
struct netvsc_reconfig *event = NULL;
bool notify = false, reschedule = false;
unsigned long flags, next_reconfig, delay;
if (!rtnl_trylock()) {
schedule_delayed_work(&ndev_ctx->dwork, LINKCHANGE_INT);
return;
}
net_device = rtnl_dereference(ndev_ctx->nvdev);
if (!net_device)
goto out_unlock;
rdev = net_device->extension;
next_reconfig = ndev_ctx->last_reconfig + LINKCHANGE_INT;
if (time_is_after_jiffies(next_reconfig)) {
delay = next_reconfig - jiffies;
delay = delay < LINKCHANGE_INT ? delay : LINKCHANGE_INT;
schedule_delayed_work(&ndev_ctx->dwork, delay);
goto out_unlock;
}
ndev_ctx->last_reconfig = jiffies;
spin_lock_irqsave(&ndev_ctx->lock, flags);
if (!list_empty(&ndev_ctx->reconfig_events)) {
event = list_first_entry(&ndev_ctx->reconfig_events,
struct netvsc_reconfig, list);
list_del(&event->list);
reschedule = !list_empty(&ndev_ctx->reconfig_events);
}
spin_unlock_irqrestore(&ndev_ctx->lock, flags);
if (!event)
goto out_unlock;
switch (event->event) {
case RNDIS_STATUS_MEDIA_CONNECT:
if (rdev->link_state) {
rdev->link_state = false;
if (!ndev_ctx->datapath)
netif_carrier_on(net);
netif_tx_wake_all_queues(net);
} else {
notify = true;
}
kfree(event);
break;
case RNDIS_STATUS_MEDIA_DISCONNECT:
if (!rdev->link_state) {
rdev->link_state = true;
netif_carrier_off(net);
netif_tx_stop_all_queues(net);
}
kfree(event);
break;
case RNDIS_STATUS_NETWORK_CHANGE:
if (!rdev->link_state) {
rdev->link_state = true;
netif_carrier_off(net);
netif_tx_stop_all_queues(net);
event->event = RNDIS_STATUS_MEDIA_CONNECT;
spin_lock_irqsave(&ndev_ctx->lock, flags);
list_add(&event->list, &ndev_ctx->reconfig_events);
spin_unlock_irqrestore(&ndev_ctx->lock, flags);
reschedule = true;
}
break;
}
rtnl_unlock();
if (notify)
netdev_notify_peers(net);
if (reschedule)
schedule_delayed_work(&ndev_ctx->dwork, LINKCHANGE_INT);
return;
out_unlock:
rtnl_unlock();
}
static struct net_device *get_netvsc_bymac(const u8 *mac)
{
struct net_device *dev;
ASSERT_RTNL();
for_each_netdev(&init_net, dev) {
if (dev->netdev_ops != &device_ops)
continue;
if (ether_addr_equal(mac, dev->perm_addr))
return dev;
}
return NULL;
}
static struct net_device *get_netvsc_byref(struct net_device *vf_netdev)
{
struct net_device *dev;
ASSERT_RTNL();
for_each_netdev(&init_net, dev) {
struct net_device_context *net_device_ctx;
if (dev->netdev_ops != &device_ops)
continue;
net_device_ctx = netdev_priv(dev);
if (net_device_ctx->nvdev == NULL)
continue;
if (rtnl_dereference(net_device_ctx->vf_netdev) == vf_netdev)
return dev;
}
return NULL;
}
static int netvsc_register_vf(struct net_device *vf_netdev)
{
struct net_device *ndev;
struct net_device_context *net_device_ctx;
struct netvsc_device *netvsc_dev;
if (vf_netdev->addr_len != ETH_ALEN)
return NOTIFY_DONE;
ndev = get_netvsc_bymac(vf_netdev->perm_addr);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = rtnl_dereference(net_device_ctx->nvdev);
if (!netvsc_dev || rtnl_dereference(net_device_ctx->vf_netdev))
return NOTIFY_DONE;
netdev_info(ndev, "VF registering: %s\n", vf_netdev->name);
try_module_get(THIS_MODULE);
dev_hold(vf_netdev);
rcu_assign_pointer(net_device_ctx->vf_netdev, vf_netdev);
return NOTIFY_OK;
}
static int netvsc_vf_up(struct net_device *vf_netdev)
{
struct net_device *ndev;
struct netvsc_device *netvsc_dev;
struct net_device_context *net_device_ctx;
ndev = get_netvsc_byref(vf_netdev);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = rtnl_dereference(net_device_ctx->nvdev);
netdev_info(ndev, "VF up: %s\n", vf_netdev->name);
rndis_filter_open(netvsc_dev);
netvsc_switch_datapath(ndev, true);
netdev_info(ndev, "Data path switched to VF: %s\n", vf_netdev->name);
netif_carrier_off(ndev);
call_netdevice_notifiers(NETDEV_NOTIFY_PEERS, vf_netdev);
return NOTIFY_OK;
}
static int netvsc_vf_down(struct net_device *vf_netdev)
{
struct net_device *ndev;
struct netvsc_device *netvsc_dev;
struct net_device_context *net_device_ctx;
ndev = get_netvsc_byref(vf_netdev);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = rtnl_dereference(net_device_ctx->nvdev);
netdev_info(ndev, "VF down: %s\n", vf_netdev->name);
netvsc_switch_datapath(ndev, false);
netdev_info(ndev, "Data path switched from VF: %s\n", vf_netdev->name);
rndis_filter_close(netvsc_dev);
netif_carrier_on(ndev);
call_netdevice_notifiers(NETDEV_NOTIFY_PEERS, ndev);
return NOTIFY_OK;
}
static int netvsc_unregister_vf(struct net_device *vf_netdev)
{
struct net_device *ndev;
struct net_device_context *net_device_ctx;
ndev = get_netvsc_byref(vf_netdev);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netdev_info(ndev, "VF unregistering: %s\n", vf_netdev->name);
RCU_INIT_POINTER(net_device_ctx->vf_netdev, NULL);
dev_put(vf_netdev);
module_put(THIS_MODULE);
return NOTIFY_OK;
}
static int netvsc_probe(struct hv_device *dev,
const struct hv_vmbus_device_id *dev_id)
{
struct net_device *net = NULL;
struct net_device_context *net_device_ctx;
struct netvsc_device_info device_info;
struct netvsc_device *nvdev;
int ret;
net = alloc_etherdev_mq(sizeof(struct net_device_context),
VRSS_CHANNEL_MAX);
if (!net)
return -ENOMEM;
netif_carrier_off(net);
netvsc_init_settings(net);
net_device_ctx = netdev_priv(net);
net_device_ctx->device_ctx = dev;
net_device_ctx->msg_enable = netif_msg_init(debug, default_msg);
if (netif_msg_probe(net_device_ctx))
netdev_dbg(net, "netvsc msg_enable: %d\n",
net_device_ctx->msg_enable);
hv_set_drvdata(dev, net);
INIT_DELAYED_WORK(&net_device_ctx->dwork, netvsc_link_change);
spin_lock_init(&net_device_ctx->lock);
INIT_LIST_HEAD(&net_device_ctx->reconfig_events);
net->netdev_ops = &device_ops;
net->ethtool_ops = &ethtool_ops;
SET_NETDEV_DEV(net, &dev->device);
net->needed_headroom = RNDIS_AND_PPI_SIZE;
memset(&device_info, 0, sizeof(device_info));
device_info.ring_size = ring_size;
device_info.num_chn = VRSS_CHANNEL_DEFAULT;
ret = rndis_filter_device_add(dev, &device_info);
if (ret != 0) {
netdev_err(net, "unable to add netvsc device (ret %d)\n", ret);
free_netdev(net);
hv_set_drvdata(dev, NULL);
return ret;
}
memcpy(net->dev_addr, device_info.mac_adr, ETH_ALEN);
net->features = net->hw_features |
NETIF_F_HIGHDMA | NETIF_F_SG |
NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;
net->vlan_features = net->features;
nvdev = net_device_ctx->nvdev;
netif_set_real_num_tx_queues(net, nvdev->num_chn);
netif_set_real_num_rx_queues(net, nvdev->num_chn);
net->min_mtu = NETVSC_MTU_MIN;
if (nvdev->nvsp_version >= NVSP_PROTOCOL_VERSION_2)
net->max_mtu = NETVSC_MTU - ETH_HLEN;
else
net->max_mtu = ETH_DATA_LEN;
ret = register_netdev(net);
if (ret != 0) {
pr_err("Unable to register netdev.\n");
rndis_filter_device_remove(dev, nvdev);
free_netdev(net);
}
return ret;
}
static int netvsc_remove(struct hv_device *dev)
{
struct net_device *net;
struct net_device_context *ndev_ctx;
net = hv_get_drvdata(dev);
if (net == NULL) {
dev_err(&dev->device, "No net device to remove\n");
return 0;
}
ndev_ctx = netdev_priv(net);
netif_device_detach(net);
cancel_delayed_work_sync(&ndev_ctx->dwork);
rtnl_lock();
rndis_filter_device_remove(dev, ndev_ctx->nvdev);
rtnl_unlock();
unregister_netdev(net);
hv_set_drvdata(dev, NULL);
free_netdev(net);
return 0;
}
static int netvsc_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *event_dev = netdev_notifier_info_to_dev(ptr);
if (event_dev->netdev_ops == &device_ops)
return NOTIFY_DONE;
if (event_dev->type != ARPHRD_ETHER)
return NOTIFY_DONE;
if (is_vlan_dev(event_dev))
return NOTIFY_DONE;
if ((event_dev->priv_flags & IFF_BONDING) &&
(event_dev->flags & IFF_MASTER))
return NOTIFY_DONE;
switch (event) {
case NETDEV_REGISTER:
return netvsc_register_vf(event_dev);
case NETDEV_UNREGISTER:
return netvsc_unregister_vf(event_dev);
case NETDEV_UP:
return netvsc_vf_up(event_dev);
case NETDEV_DOWN:
return netvsc_vf_down(event_dev);
default:
return NOTIFY_DONE;
}
}
static void __exit netvsc_drv_exit(void)
{
unregister_netdevice_notifier(&netvsc_netdev_notifier);
vmbus_driver_unregister(&netvsc_drv);
}
static int __init netvsc_drv_init(void)
{
int ret;
if (ring_size < RING_SIZE_MIN) {
ring_size = RING_SIZE_MIN;
pr_info("Increased ring_size to %d (min allowed)\n",
ring_size);
}
ret = vmbus_driver_register(&netvsc_drv);
if (ret)
return ret;
register_netdevice_notifier(&netvsc_netdev_notifier);
return 0;
}
