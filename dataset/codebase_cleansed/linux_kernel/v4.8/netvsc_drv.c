static void do_set_multicast(struct work_struct *w)
{
struct net_device_context *ndevctx =
container_of(w, struct net_device_context, work);
struct hv_device *device_obj = ndevctx->device_ctx;
struct net_device *ndev = hv_get_drvdata(device_obj);
struct netvsc_device *nvdev = ndevctx->nvdev;
struct rndis_device *rdev;
if (!nvdev)
return;
rdev = nvdev->extension;
if (rdev == NULL)
return;
if (ndev->flags & IFF_PROMISC)
rndis_filter_set_packet_filter(rdev,
NDIS_PACKET_TYPE_PROMISCUOUS);
else
rndis_filter_set_packet_filter(rdev,
NDIS_PACKET_TYPE_BROADCAST |
NDIS_PACKET_TYPE_ALL_MULTICAST |
NDIS_PACKET_TYPE_DIRECTED);
}
static void netvsc_set_multicast_list(struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
schedule_work(&net_device_ctx->work);
}
static int netvsc_open(struct net_device *net)
{
struct netvsc_device *nvdev = net_device_to_netvsc_device(net);
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
if (!rdev->link_state)
netif_carrier_on(net);
return ret;
}
static int netvsc_close(struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct netvsc_device *nvdev = net_device_ctx->nvdev;
int ret;
u32 aread, awrite, i, msec = 10, retry = 0, retry_max = 20;
struct vmbus_channel *chn;
netif_tx_disable(net);
cancel_work_sync(&net_device_ctx->work);
ret = rndis_filter_close(nvdev);
if (ret != 0) {
netdev_err(net, "unable to close device (ret %d).\n", ret);
return ret;
}
while (true) {
aread = 0;
for (i = 0; i < nvdev->num_chn; i++) {
chn = nvdev->chn_table[i];
if (!chn)
continue;
hv_get_ringbuffer_availbytes(&chn->inbound, &aread,
&awrite);
if (aread)
break;
hv_get_ringbuffer_availbytes(&chn->outbound, &aread,
&awrite);
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
static u16 netvsc_select_queue(struct net_device *ndev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
struct net_device_context *net_device_ctx = netdev_priv(ndev);
struct netvsc_device *nvsc_dev = net_device_ctx->nvdev;
u32 hash;
u16 q_idx = 0;
if (nvsc_dev == NULL || ndev->real_num_tx_queues <= 1)
return 0;
hash = skb_get_hash(skb);
q_idx = nvsc_dev->send_table[hash % VRSS_SEND_TAB_SIZE] %
ndev->real_num_tx_queues;
if (!nvsc_dev->chn_table[q_idx])
q_idx = 0;
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
static u32 get_net_transport_info(struct sk_buff *skb, u32 *trans_off)
{
u32 ret_val = TRANSPORT_INFO_NOT_IP;
if ((eth_hdr(skb)->h_proto != htons(ETH_P_IP)) &&
(eth_hdr(skb)->h_proto != htons(ETH_P_IPV6))) {
goto not_ip;
}
*trans_off = skb_transport_offset(skb);
if ((eth_hdr(skb)->h_proto == htons(ETH_P_IP))) {
struct iphdr *iphdr = ip_hdr(skb);
if (iphdr->protocol == IPPROTO_TCP)
ret_val = TRANSPORT_INFO_IPV4_TCP;
else if (iphdr->protocol == IPPROTO_UDP)
ret_val = TRANSPORT_INFO_IPV4_UDP;
} else {
if (ipv6_hdr(skb)->nexthdr == IPPROTO_TCP)
ret_val = TRANSPORT_INFO_IPV6_TCP;
else if (ipv6_hdr(skb)->nexthdr == IPPROTO_UDP)
ret_val = TRANSPORT_INFO_IPV6_UDP;
}
not_ip:
return ret_val;
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
bool isvlan;
bool linear = false;
struct rndis_per_packet_info *ppi;
struct ndis_tcp_ip_checksum_info *csum_info;
struct ndis_tcp_lso_info *lso_info;
int hdr_offset;
u32 net_trans_info;
u32 hash;
u32 skb_length;
struct hv_page_buffer page_buf[MAX_PAGE_BUFFER_COUNT];
struct hv_page_buffer *pb = page_buf;
struct netvsc_stats *tx_stats = this_cpu_ptr(net_device_ctx->tx_stats);
check_size:
skb_length = skb->len;
num_data_pgs = netvsc_get_slots(skb) + 2;
if (num_data_pgs > MAX_PAGE_BUFFER_COUNT && linear) {
net_alert_ratelimited("packet too big: %u pages (%u bytes)\n",
num_data_pgs, skb->len);
ret = -EFAULT;
goto drop;
} else if (num_data_pgs > MAX_PAGE_BUFFER_COUNT) {
if (skb_linearize(skb)) {
net_alert_ratelimited("failed to linearize skb\n");
ret = -ENOMEM;
goto drop;
}
linear = true;
goto check_size;
}
ret = skb_cow_head(skb, RNDIS_AND_PPI_SIZE);
if (ret) {
netdev_err(net, "unable to alloc hv_netvsc_packet\n");
ret = -ENOMEM;
goto drop;
}
BUILD_BUG_ON(sizeof(struct hv_netvsc_packet) >
FIELD_SIZEOF(struct sk_buff, cb));
packet = (struct hv_netvsc_packet *)skb->cb;
packet->q_idx = skb_get_queue_mapping(skb);
packet->total_data_buflen = skb->len;
rndis_msg = (struct rndis_message *)skb->head;
memset(rndis_msg, 0, RNDIS_AND_PPI_SIZE);
isvlan = skb->vlan_tci & VLAN_TAG_PRESENT;
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
if (isvlan) {
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
net_trans_info = get_net_transport_info(skb, &hdr_offset);
if (net_trans_info == TRANSPORT_INFO_NOT_IP)
goto do_send;
if (skb_is_gso(skb))
goto do_lso;
if ((skb->ip_summed == CHECKSUM_NONE) ||
(skb->ip_summed == CHECKSUM_UNNECESSARY))
goto do_send;
rndis_msg_size += NDIS_CSUM_PPI_SIZE;
ppi = init_ppi_data(rndis_msg, NDIS_CSUM_PPI_SIZE,
TCPIP_CHKSUM_PKTINFO);
csum_info = (struct ndis_tcp_ip_checksum_info *)((void *)ppi +
ppi->ppi_offset);
if (net_trans_info & (INFO_IPV4 << 16))
csum_info->transmit.is_ipv4 = 1;
else
csum_info->transmit.is_ipv6 = 1;
if (net_trans_info & INFO_TCP) {
csum_info->transmit.tcp_checksum = 1;
csum_info->transmit.tcp_header_offset = hdr_offset;
} else if (net_trans_info & INFO_UDP) {
struct udphdr *uh;
u16 udp_len;
ret = skb_cow_head(skb, 0);
if (ret)
goto drop;
uh = udp_hdr(skb);
udp_len = ntohs(uh->len);
uh->check = 0;
uh->check = csum_tcpudp_magic(ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr,
udp_len, IPPROTO_UDP,
csum_partial(uh, udp_len, 0));
if (uh->check == 0)
uh->check = CSUM_MANGLED_0;
csum_info->transmit.udp_checksum = 0;
}
goto do_send;
do_lso:
rndis_msg_size += NDIS_LSO_PPI_SIZE;
ppi = init_ppi_data(rndis_msg, NDIS_LSO_PPI_SIZE,
TCP_LARGESEND_PKTINFO);
lso_info = (struct ndis_tcp_lso_info *)((void *)ppi +
ppi->ppi_offset);
lso_info->lso_v2_transmit.type = NDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE;
if (net_trans_info & (INFO_IPV4 << 16)) {
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
lso_info->lso_v2_transmit.tcp_header_offset = hdr_offset;
lso_info->lso_v2_transmit.mss = skb_shinfo(skb)->gso_size;
do_send:
rndis_msg->msg_len += rndis_msg_size;
packet->total_data_buflen = rndis_msg->msg_len;
packet->page_buf_cnt = init_page_array(rndis_msg, rndis_msg_size,
skb, packet, &pb);
skb_tx_timestamp(skb);
ret = netvsc_send(net_device_ctx->device_ctx, packet,
rndis_msg, &pb, skb);
drop:
if (ret == 0) {
u64_stats_update_begin(&tx_stats->syncp);
tx_stats->packets++;
tx_stats->bytes += skb_length;
u64_stats_update_end(&tx_stats->syncp);
} else {
if (ret != -EAGAIN) {
dev_kfree_skb_any(skb);
net->stats.tx_dropped++;
}
}
return (ret == -EAGAIN) ? NETDEV_TX_BUSY : NETDEV_TX_OK;
}
void netvsc_linkstatus_callback(struct hv_device *device_obj,
struct rndis_message *resp)
{
struct rndis_indicate_status *indicate = &resp->msg.indicate_status;
struct net_device *net;
struct net_device_context *ndev_ctx;
struct netvsc_reconfig *event;
unsigned long flags;
if (indicate->status != RNDIS_STATUS_NETWORK_CHANGE &&
indicate->status != RNDIS_STATUS_MEDIA_CONNECT &&
indicate->status != RNDIS_STATUS_MEDIA_DISCONNECT)
return;
net = hv_get_drvdata(device_obj);
if (!net || net->reg_state != NETREG_REGISTERED)
return;
ndev_ctx = netdev_priv(net);
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
struct hv_netvsc_packet *packet,
struct ndis_tcp_ip_checksum_info *csum_info,
void *data, u16 vlan_tci)
{
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(net, packet->total_data_buflen);
if (!skb)
return skb;
memcpy(skb_put(skb, packet->total_data_buflen), data,
packet->total_data_buflen);
skb->protocol = eth_type_trans(skb, net);
if (csum_info) {
if (csum_info->receive.ip_checksum_succeeded)
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
skb->ip_summed = CHECKSUM_NONE;
}
if (vlan_tci & VLAN_TAG_PRESENT)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
vlan_tci);
return skb;
}
int netvsc_recv_callback(struct hv_device *device_obj,
struct hv_netvsc_packet *packet,
void **data,
struct ndis_tcp_ip_checksum_info *csum_info,
struct vmbus_channel *channel,
u16 vlan_tci)
{
struct net_device *net = hv_get_drvdata(device_obj);
struct net_device_context *net_device_ctx = netdev_priv(net);
struct sk_buff *skb;
struct sk_buff *vf_skb;
struct netvsc_stats *rx_stats;
u32 bytes_recvd = packet->total_data_buflen;
int ret = 0;
if (!net || net->reg_state != NETREG_REGISTERED)
return NVSP_STAT_FAIL;
if (READ_ONCE(net_device_ctx->vf_inject)) {
atomic_inc(&net_device_ctx->vf_use_cnt);
if (!READ_ONCE(net_device_ctx->vf_inject)) {
atomic_dec(&net_device_ctx->vf_use_cnt);
goto vf_injection_done;
}
vf_skb = netvsc_alloc_recv_skb(net_device_ctx->vf_netdev,
packet, csum_info, *data,
vlan_tci);
if (vf_skb != NULL) {
++net_device_ctx->vf_netdev->stats.rx_packets;
net_device_ctx->vf_netdev->stats.rx_bytes +=
bytes_recvd;
netif_receive_skb(vf_skb);
} else {
++net->stats.rx_dropped;
ret = NVSP_STAT_FAIL;
}
atomic_dec(&net_device_ctx->vf_use_cnt);
return ret;
}
vf_injection_done:
rx_stats = this_cpu_ptr(net_device_ctx->rx_stats);
skb = netvsc_alloc_recv_skb(net, packet, csum_info, *data, vlan_tci);
if (unlikely(!skb)) {
++net->stats.rx_dropped;
return NVSP_STAT_FAIL;
}
skb_record_rx_queue(skb, channel->
offermsg.offer.sub_channel_index);
u64_stats_update_begin(&rx_stats->syncp);
rx_stats->packets++;
rx_stats->bytes += packet->total_data_buflen;
u64_stats_update_end(&rx_stats->syncp);
netif_rx(skb);
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
struct netvsc_device *nvdev = net_device_ctx->nvdev;
if (nvdev) {
channel->max_combined = nvdev->max_chn;
channel->combined_count = nvdev->num_chn;
}
}
static int netvsc_set_channels(struct net_device *net,
struct ethtool_channels *channels)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct hv_device *dev = net_device_ctx->device_ctx;
struct netvsc_device *nvdev = net_device_ctx->nvdev;
struct netvsc_device_info device_info;
u32 num_chn;
u32 max_chn;
int ret = 0;
bool recovering = false;
if (net_device_ctx->start_remove || !nvdev || nvdev->destroy)
return -ENODEV;
num_chn = nvdev->num_chn;
max_chn = min_t(u32, nvdev->max_chn, num_online_cpus());
if (nvdev->nvsp_version < NVSP_PROTOCOL_VERSION_5) {
pr_info("vRSS unsupported before NVSP Version 5\n");
return -EINVAL;
}
if (!channels ||
channels->rx_count ||
channels->tx_count ||
channels->other_count ||
(channels->combined_count < 1))
return -EINVAL;
if (channels->combined_count > max_chn) {
pr_info("combined channels too high, using %d\n", max_chn);
channels->combined_count = max_chn;
}
ret = netvsc_close(net);
if (ret)
goto out;
do_set:
net_device_ctx->start_remove = true;
rndis_filter_device_remove(dev);
nvdev->num_chn = channels->combined_count;
memset(&device_info, 0, sizeof(device_info));
device_info.num_chn = nvdev->num_chn;
device_info.ring_size = ring_size;
device_info.max_num_vrss_chns = max_num_vrss_chns;
ret = rndis_filter_device_add(dev, &device_info);
if (ret) {
if (recovering) {
netdev_err(net, "unable to add netvsc device (ret %d)\n", ret);
return ret;
}
goto recover;
}
nvdev = net_device_ctx->nvdev;
ret = netif_set_real_num_tx_queues(net, nvdev->num_chn);
if (ret) {
if (recovering) {
netdev_err(net, "could not set tx queue count (ret %d)\n", ret);
return ret;
}
goto recover;
}
ret = netif_set_real_num_rx_queues(net, nvdev->num_chn);
if (ret) {
if (recovering) {
netdev_err(net, "could not set rx queue count (ret %d)\n", ret);
return ret;
}
goto recover;
}
out:
netvsc_open(net);
net_device_ctx->start_remove = false;
schedule_delayed_work(&net_device_ctx->dwork, 0);
return ret;
recover:
netdev_err(net, "could not set channels, recovering\n");
recovering = true;
channels->combined_count = num_chn;
goto do_set;
}
static bool netvsc_validate_ethtool_ss_cmd(const struct ethtool_cmd *cmd)
{
struct ethtool_cmd diff1 = *cmd;
struct ethtool_cmd diff2 = {};
ethtool_cmd_speed_set(&diff1, 0);
diff1.duplex = 0;
diff1.advertising = 0;
diff1.cmd = 0;
diff2.port = PORT_OTHER;
return !memcmp(&diff1, &diff2, sizeof(diff1));
}
static void netvsc_init_settings(struct net_device *dev)
{
struct net_device_context *ndc = netdev_priv(dev);
ndc->speed = SPEED_UNKNOWN;
ndc->duplex = DUPLEX_UNKNOWN;
}
static int netvsc_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct net_device_context *ndc = netdev_priv(dev);
ethtool_cmd_speed_set(cmd, ndc->speed);
cmd->duplex = ndc->duplex;
cmd->port = PORT_OTHER;
return 0;
}
static int netvsc_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct net_device_context *ndc = netdev_priv(dev);
u32 speed;
speed = ethtool_cmd_speed(cmd);
if (!ethtool_validate_speed(speed) ||
!ethtool_validate_duplex(cmd->duplex) ||
!netvsc_validate_ethtool_ss_cmd(cmd))
return -EINVAL;
ndc->speed = speed;
ndc->duplex = cmd->duplex;
return 0;
}
static int netvsc_change_mtu(struct net_device *ndev, int mtu)
{
struct net_device_context *ndevctx = netdev_priv(ndev);
struct netvsc_device *nvdev = ndevctx->nvdev;
struct hv_device *hdev = ndevctx->device_ctx;
struct netvsc_device_info device_info;
int limit = ETH_DATA_LEN;
u32 num_chn;
int ret = 0;
if (ndevctx->start_remove || !nvdev || nvdev->destroy)
return -ENODEV;
if (nvdev->nvsp_version >= NVSP_PROTOCOL_VERSION_2)
limit = NETVSC_MTU - ETH_HLEN;
if (mtu < NETVSC_MTU_MIN || mtu > limit)
return -EINVAL;
ret = netvsc_close(ndev);
if (ret)
goto out;
num_chn = nvdev->num_chn;
ndevctx->start_remove = true;
rndis_filter_device_remove(hdev);
ndev->mtu = mtu;
memset(&device_info, 0, sizeof(device_info));
device_info.ring_size = ring_size;
device_info.num_chn = num_chn;
device_info.max_num_vrss_chns = max_num_vrss_chns;
rndis_filter_device_add(hdev, &device_info);
out:
netvsc_open(ndev);
ndevctx->start_remove = false;
schedule_delayed_work(&ndevctx->dwork, 0);
return ret;
}
static struct rtnl_link_stats64 *netvsc_get_stats64(struct net_device *net,
struct rtnl_link_stats64 *t)
{
struct net_device_context *ndev_ctx = netdev_priv(net);
int cpu;
for_each_possible_cpu(cpu) {
struct netvsc_stats *tx_stats = per_cpu_ptr(ndev_ctx->tx_stats,
cpu);
struct netvsc_stats *rx_stats = per_cpu_ptr(ndev_ctx->rx_stats,
cpu);
u64 tx_packets, tx_bytes, rx_packets, rx_bytes;
unsigned int start;
do {
start = u64_stats_fetch_begin_irq(&tx_stats->syncp);
tx_packets = tx_stats->packets;
tx_bytes = tx_stats->bytes;
} while (u64_stats_fetch_retry_irq(&tx_stats->syncp, start));
do {
start = u64_stats_fetch_begin_irq(&rx_stats->syncp);
rx_packets = rx_stats->packets;
rx_bytes = rx_stats->bytes;
} while (u64_stats_fetch_retry_irq(&rx_stats->syncp, start));
t->tx_bytes += tx_bytes;
t->tx_packets += tx_packets;
t->rx_bytes += rx_bytes;
t->rx_packets += rx_packets;
}
t->tx_dropped = net->stats.tx_dropped;
t->tx_errors = net->stats.tx_dropped;
t->rx_dropped = net->stats.rx_dropped;
t->rx_errors = net->stats.rx_errors;
return t;
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
static void netvsc_poll_controller(struct net_device *net)
{
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
rtnl_lock();
if (ndev_ctx->start_remove)
goto out_unlock;
net_device = ndev_ctx->nvdev;
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
static void netvsc_free_netdev(struct net_device *netdev)
{
struct net_device_context *net_device_ctx = netdev_priv(netdev);
free_percpu(net_device_ctx->tx_stats);
free_percpu(net_device_ctx->rx_stats);
free_netdev(netdev);
}
static struct net_device *get_netvsc_net_device(char *mac)
{
struct net_device *dev, *found = NULL;
int rtnl_locked;
rtnl_locked = rtnl_trylock();
for_each_netdev(&init_net, dev) {
if (memcmp(dev->dev_addr, mac, ETH_ALEN) == 0) {
if (dev->netdev_ops != &device_ops)
continue;
found = dev;
break;
}
}
if (rtnl_locked)
rtnl_unlock();
return found;
}
static int netvsc_register_vf(struct net_device *vf_netdev)
{
struct net_device *ndev;
struct net_device_context *net_device_ctx;
struct netvsc_device *netvsc_dev;
const struct ethtool_ops *eth_ops = vf_netdev->ethtool_ops;
if (eth_ops == NULL || eth_ops == &ethtool_ops)
return NOTIFY_DONE;
ndev = get_netvsc_net_device(vf_netdev->dev_addr);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = net_device_ctx->nvdev;
if (!netvsc_dev || net_device_ctx->vf_netdev)
return NOTIFY_DONE;
netdev_info(ndev, "VF registering: %s\n", vf_netdev->name);
try_module_get(THIS_MODULE);
net_device_ctx->vf_netdev = vf_netdev;
return NOTIFY_OK;
}
static void netvsc_inject_enable(struct net_device_context *net_device_ctx)
{
net_device_ctx->vf_inject = true;
}
static void netvsc_inject_disable(struct net_device_context *net_device_ctx)
{
net_device_ctx->vf_inject = false;
while (atomic_read(&net_device_ctx->vf_use_cnt) != 0)
udelay(50);
}
static int netvsc_vf_up(struct net_device *vf_netdev)
{
struct net_device *ndev;
struct netvsc_device *netvsc_dev;
const struct ethtool_ops *eth_ops = vf_netdev->ethtool_ops;
struct net_device_context *net_device_ctx;
if (eth_ops == &ethtool_ops)
return NOTIFY_DONE;
ndev = get_netvsc_net_device(vf_netdev->dev_addr);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = net_device_ctx->nvdev;
if (!netvsc_dev || !net_device_ctx->vf_netdev)
return NOTIFY_DONE;
netdev_info(ndev, "VF up: %s\n", vf_netdev->name);
netvsc_inject_enable(net_device_ctx);
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
const struct ethtool_ops *eth_ops = vf_netdev->ethtool_ops;
if (eth_ops == &ethtool_ops)
return NOTIFY_DONE;
ndev = get_netvsc_net_device(vf_netdev->dev_addr);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = net_device_ctx->nvdev;
if (!netvsc_dev || !net_device_ctx->vf_netdev)
return NOTIFY_DONE;
netdev_info(ndev, "VF down: %s\n", vf_netdev->name);
netvsc_inject_disable(net_device_ctx);
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
struct netvsc_device *netvsc_dev;
const struct ethtool_ops *eth_ops = vf_netdev->ethtool_ops;
struct net_device_context *net_device_ctx;
if (eth_ops == &ethtool_ops)
return NOTIFY_DONE;
ndev = get_netvsc_net_device(vf_netdev->dev_addr);
if (!ndev)
return NOTIFY_DONE;
net_device_ctx = netdev_priv(ndev);
netvsc_dev = net_device_ctx->nvdev;
if (!netvsc_dev || !net_device_ctx->vf_netdev)
return NOTIFY_DONE;
netdev_info(ndev, "VF unregistering: %s\n", vf_netdev->name);
netvsc_inject_disable(net_device_ctx);
net_device_ctx->vf_netdev = NULL;
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
num_online_cpus());
if (!net)
return -ENOMEM;
netif_carrier_off(net);
net_device_ctx = netdev_priv(net);
net_device_ctx->device_ctx = dev;
net_device_ctx->msg_enable = netif_msg_init(debug, default_msg);
if (netif_msg_probe(net_device_ctx))
netdev_dbg(net, "netvsc msg_enable: %d\n",
net_device_ctx->msg_enable);
net_device_ctx->tx_stats = netdev_alloc_pcpu_stats(struct netvsc_stats);
if (!net_device_ctx->tx_stats) {
free_netdev(net);
return -ENOMEM;
}
net_device_ctx->rx_stats = netdev_alloc_pcpu_stats(struct netvsc_stats);
if (!net_device_ctx->rx_stats) {
free_percpu(net_device_ctx->tx_stats);
free_netdev(net);
return -ENOMEM;
}
hv_set_drvdata(dev, net);
net_device_ctx->start_remove = false;
INIT_DELAYED_WORK(&net_device_ctx->dwork, netvsc_link_change);
INIT_WORK(&net_device_ctx->work, do_set_multicast);
spin_lock_init(&net_device_ctx->lock);
INIT_LIST_HEAD(&net_device_ctx->reconfig_events);
atomic_set(&net_device_ctx->vf_use_cnt, 0);
net_device_ctx->vf_netdev = NULL;
net_device_ctx->vf_inject = false;
net->netdev_ops = &device_ops;
net->hw_features = NETVSC_HW_FEATURES;
net->features = NETVSC_HW_FEATURES | NETIF_F_HW_VLAN_CTAG_TX;
net->ethtool_ops = &ethtool_ops;
SET_NETDEV_DEV(net, &dev->device);
net->needed_headroom = RNDIS_AND_PPI_SIZE;
memset(&device_info, 0, sizeof(device_info));
device_info.ring_size = ring_size;
device_info.max_num_vrss_chns = max_num_vrss_chns;
ret = rndis_filter_device_add(dev, &device_info);
if (ret != 0) {
netdev_err(net, "unable to add netvsc device (ret %d)\n", ret);
netvsc_free_netdev(net);
hv_set_drvdata(dev, NULL);
return ret;
}
memcpy(net->dev_addr, device_info.mac_adr, ETH_ALEN);
nvdev = net_device_ctx->nvdev;
netif_set_real_num_tx_queues(net, nvdev->num_chn);
netif_set_real_num_rx_queues(net, nvdev->num_chn);
netvsc_init_settings(net);
ret = register_netdev(net);
if (ret != 0) {
pr_err("Unable to register netdev.\n");
rndis_filter_device_remove(dev);
netvsc_free_netdev(net);
}
return ret;
}
static int netvsc_remove(struct hv_device *dev)
{
struct net_device *net;
struct net_device_context *ndev_ctx;
struct netvsc_device *net_device;
net = hv_get_drvdata(dev);
if (net == NULL) {
dev_err(&dev->device, "No net device to remove\n");
return 0;
}
ndev_ctx = netdev_priv(net);
net_device = ndev_ctx->nvdev;
rtnl_lock();
ndev_ctx->start_remove = true;
rtnl_unlock();
cancel_delayed_work_sync(&ndev_ctx->dwork);
cancel_work_sync(&ndev_ctx->work);
netif_tx_disable(net);
unregister_netdev(net);
rndis_filter_device_remove(dev);
hv_set_drvdata(dev, NULL);
netvsc_free_netdev(net);
return 0;
}
static int netvsc_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *event_dev = netdev_notifier_info_to_dev(ptr);
if (event_dev->priv_flags & IFF_802_1Q_VLAN)
return NOTIFY_DONE;
if (event_dev->priv_flags & IFF_BONDING &&
event_dev->flags & IFF_MASTER)
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
