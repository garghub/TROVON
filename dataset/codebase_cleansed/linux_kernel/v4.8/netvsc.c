void netvsc_switch_datapath(struct net_device *ndev, bool vf)
{
struct net_device_context *net_device_ctx = netdev_priv(ndev);
struct hv_device *dev = net_device_ctx->device_ctx;
struct netvsc_device *nv_dev = net_device_ctx->nvdev;
struct nvsp_message *init_pkt = &nv_dev->channel_init_pkt;
memset(init_pkt, 0, sizeof(struct nvsp_message));
init_pkt->hdr.msg_type = NVSP_MSG4_TYPE_SWITCH_DATA_PATH;
if (vf)
init_pkt->msg.v4_msg.active_dp.active_datapath =
NVSP_DATAPATH_VF;
else
init_pkt->msg.v4_msg.active_dp.active_datapath =
NVSP_DATAPATH_SYNTHETIC;
vmbus_sendpacket(dev->channel, init_pkt,
sizeof(struct nvsp_message),
(unsigned long)init_pkt,
VM_PKT_DATA_INBAND, 0);
}
static struct netvsc_device *alloc_net_device(void)
{
struct netvsc_device *net_device;
net_device = kzalloc(sizeof(struct netvsc_device), GFP_KERNEL);
if (!net_device)
return NULL;
net_device->cb_buffer = kzalloc(NETVSC_PACKET_SIZE, GFP_KERNEL);
if (!net_device->cb_buffer) {
kfree(net_device);
return NULL;
}
init_waitqueue_head(&net_device->wait_drain);
net_device->destroy = false;
atomic_set(&net_device->open_cnt, 0);
net_device->max_pkt = RNDIS_MAX_PKT_DEFAULT;
net_device->pkt_align = RNDIS_PKT_ALIGN_DEFAULT;
return net_device;
}
static void free_netvsc_device(struct netvsc_device *nvdev)
{
kfree(nvdev->cb_buffer);
kfree(nvdev);
}
static struct netvsc_device *get_outbound_net_device(struct hv_device *device)
{
struct netvsc_device *net_device = hv_device_to_netvsc_device(device);
if (net_device && net_device->destroy)
net_device = NULL;
return net_device;
}
static struct netvsc_device *get_inbound_net_device(struct hv_device *device)
{
struct netvsc_device *net_device = hv_device_to_netvsc_device(device);
if (!net_device)
goto get_in_err;
if (net_device->destroy &&
atomic_read(&net_device->num_outstanding_sends) == 0)
net_device = NULL;
get_in_err:
return net_device;
}
static int netvsc_destroy_buf(struct hv_device *device)
{
struct nvsp_message *revoke_packet;
int ret = 0;
struct net_device *ndev = hv_get_drvdata(device);
struct netvsc_device *net_device = net_device_to_netvsc_device(ndev);
if (net_device->recv_section_cnt) {
revoke_packet = &net_device->revoke_packet;
memset(revoke_packet, 0, sizeof(struct nvsp_message));
revoke_packet->hdr.msg_type =
NVSP_MSG1_TYPE_REVOKE_RECV_BUF;
revoke_packet->msg.v1_msg.
revoke_recv_buf.id = NETVSC_RECEIVE_BUFFER_ID;
ret = vmbus_sendpacket(device->channel,
revoke_packet,
sizeof(struct nvsp_message),
(unsigned long)revoke_packet,
VM_PKT_DATA_INBAND, 0);
if (ret != 0) {
netdev_err(ndev, "unable to send "
"revoke receive buffer to netvsp\n");
return ret;
}
}
if (net_device->recv_buf_gpadl_handle) {
ret = vmbus_teardown_gpadl(device->channel,
net_device->recv_buf_gpadl_handle);
if (ret != 0) {
netdev_err(ndev,
"unable to teardown receive buffer's gpadl\n");
return ret;
}
net_device->recv_buf_gpadl_handle = 0;
}
if (net_device->recv_buf) {
vfree(net_device->recv_buf);
net_device->recv_buf = NULL;
}
if (net_device->recv_section) {
net_device->recv_section_cnt = 0;
kfree(net_device->recv_section);
net_device->recv_section = NULL;
}
if (net_device->send_section_size) {
revoke_packet = &net_device->revoke_packet;
memset(revoke_packet, 0, sizeof(struct nvsp_message));
revoke_packet->hdr.msg_type =
NVSP_MSG1_TYPE_REVOKE_SEND_BUF;
revoke_packet->msg.v1_msg.revoke_send_buf.id =
NETVSC_SEND_BUFFER_ID;
ret = vmbus_sendpacket(device->channel,
revoke_packet,
sizeof(struct nvsp_message),
(unsigned long)revoke_packet,
VM_PKT_DATA_INBAND, 0);
if (ret != 0) {
netdev_err(ndev, "unable to send "
"revoke send buffer to netvsp\n");
return ret;
}
}
if (net_device->send_buf_gpadl_handle) {
ret = vmbus_teardown_gpadl(device->channel,
net_device->send_buf_gpadl_handle);
if (ret != 0) {
netdev_err(ndev,
"unable to teardown send buffer's gpadl\n");
return ret;
}
net_device->send_buf_gpadl_handle = 0;
}
if (net_device->send_buf) {
vfree(net_device->send_buf);
net_device->send_buf = NULL;
}
kfree(net_device->send_section_map);
return ret;
}
static int netvsc_init_buf(struct hv_device *device)
{
int ret = 0;
struct netvsc_device *net_device;
struct nvsp_message *init_packet;
struct net_device *ndev;
int node;
net_device = get_outbound_net_device(device);
if (!net_device)
return -ENODEV;
ndev = hv_get_drvdata(device);
node = cpu_to_node(device->channel->target_cpu);
net_device->recv_buf = vzalloc_node(net_device->recv_buf_size, node);
if (!net_device->recv_buf)
net_device->recv_buf = vzalloc(net_device->recv_buf_size);
if (!net_device->recv_buf) {
netdev_err(ndev, "unable to allocate receive "
"buffer of size %d\n", net_device->recv_buf_size);
ret = -ENOMEM;
goto cleanup;
}
ret = vmbus_establish_gpadl(device->channel, net_device->recv_buf,
net_device->recv_buf_size,
&net_device->recv_buf_gpadl_handle);
if (ret != 0) {
netdev_err(ndev,
"unable to establish receive buffer's gpadl\n");
goto cleanup;
}
init_packet = &net_device->channel_init_pkt;
memset(init_packet, 0, sizeof(struct nvsp_message));
init_packet->hdr.msg_type = NVSP_MSG1_TYPE_SEND_RECV_BUF;
init_packet->msg.v1_msg.send_recv_buf.
gpadl_handle = net_device->recv_buf_gpadl_handle;
init_packet->msg.v1_msg.
send_recv_buf.id = NETVSC_RECEIVE_BUFFER_ID;
ret = vmbus_sendpacket(device->channel, init_packet,
sizeof(struct nvsp_message),
(unsigned long)init_packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0) {
netdev_err(ndev,
"unable to send receive buffer's gpadl to netvsp\n");
goto cleanup;
}
wait_for_completion(&net_device->channel_init_wait);
if (init_packet->msg.v1_msg.
send_recv_buf_complete.status != NVSP_STAT_SUCCESS) {
netdev_err(ndev, "Unable to complete receive buffer "
"initialization with NetVsp - status %d\n",
init_packet->msg.v1_msg.
send_recv_buf_complete.status);
ret = -EINVAL;
goto cleanup;
}
net_device->recv_section_cnt = init_packet->msg.
v1_msg.send_recv_buf_complete.num_sections;
net_device->recv_section = kmemdup(
init_packet->msg.v1_msg.send_recv_buf_complete.sections,
net_device->recv_section_cnt *
sizeof(struct nvsp_1_receive_buffer_section),
GFP_KERNEL);
if (net_device->recv_section == NULL) {
ret = -EINVAL;
goto cleanup;
}
if (net_device->recv_section_cnt != 1 ||
net_device->recv_section->offset != 0) {
ret = -EINVAL;
goto cleanup;
}
net_device->send_buf = vzalloc_node(net_device->send_buf_size, node);
if (!net_device->send_buf)
net_device->send_buf = vzalloc(net_device->send_buf_size);
if (!net_device->send_buf) {
netdev_err(ndev, "unable to allocate send "
"buffer of size %d\n", net_device->send_buf_size);
ret = -ENOMEM;
goto cleanup;
}
ret = vmbus_establish_gpadl(device->channel, net_device->send_buf,
net_device->send_buf_size,
&net_device->send_buf_gpadl_handle);
if (ret != 0) {
netdev_err(ndev,
"unable to establish send buffer's gpadl\n");
goto cleanup;
}
init_packet = &net_device->channel_init_pkt;
memset(init_packet, 0, sizeof(struct nvsp_message));
init_packet->hdr.msg_type = NVSP_MSG1_TYPE_SEND_SEND_BUF;
init_packet->msg.v1_msg.send_send_buf.gpadl_handle =
net_device->send_buf_gpadl_handle;
init_packet->msg.v1_msg.send_send_buf.id = NETVSC_SEND_BUFFER_ID;
ret = vmbus_sendpacket(device->channel, init_packet,
sizeof(struct nvsp_message),
(unsigned long)init_packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0) {
netdev_err(ndev,
"unable to send send buffer's gpadl to netvsp\n");
goto cleanup;
}
wait_for_completion(&net_device->channel_init_wait);
if (init_packet->msg.v1_msg.
send_send_buf_complete.status != NVSP_STAT_SUCCESS) {
netdev_err(ndev, "Unable to complete send buffer "
"initialization with NetVsp - status %d\n",
init_packet->msg.v1_msg.
send_send_buf_complete.status);
ret = -EINVAL;
goto cleanup;
}
net_device->send_section_size = init_packet->msg.
v1_msg.send_send_buf_complete.section_size;
net_device->send_section_cnt =
net_device->send_buf_size/net_device->send_section_size;
dev_info(&device->device, "Send section size: %d, Section count:%d\n",
net_device->send_section_size, net_device->send_section_cnt);
net_device->map_words = DIV_ROUND_UP(net_device->send_section_cnt,
BITS_PER_LONG);
net_device->send_section_map =
kzalloc(net_device->map_words * sizeof(ulong), GFP_KERNEL);
if (net_device->send_section_map == NULL) {
ret = -ENOMEM;
goto cleanup;
}
goto exit;
cleanup:
netvsc_destroy_buf(device);
exit:
return ret;
}
static int negotiate_nvsp_ver(struct hv_device *device,
struct netvsc_device *net_device,
struct nvsp_message *init_packet,
u32 nvsp_ver)
{
struct net_device *ndev = hv_get_drvdata(device);
int ret;
memset(init_packet, 0, sizeof(struct nvsp_message));
init_packet->hdr.msg_type = NVSP_MSG_TYPE_INIT;
init_packet->msg.init_msg.init.min_protocol_ver = nvsp_ver;
init_packet->msg.init_msg.init.max_protocol_ver = nvsp_ver;
ret = vmbus_sendpacket(device->channel, init_packet,
sizeof(struct nvsp_message),
(unsigned long)init_packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
return ret;
wait_for_completion(&net_device->channel_init_wait);
if (init_packet->msg.init_msg.init_complete.status !=
NVSP_STAT_SUCCESS)
return -EINVAL;
if (nvsp_ver == NVSP_PROTOCOL_VERSION_1)
return 0;
memset(init_packet, 0, sizeof(struct nvsp_message));
init_packet->hdr.msg_type = NVSP_MSG2_TYPE_SEND_NDIS_CONFIG;
init_packet->msg.v2_msg.send_ndis_config.mtu = ndev->mtu + ETH_HLEN;
init_packet->msg.v2_msg.send_ndis_config.capability.ieee8021q = 1;
if (nvsp_ver >= NVSP_PROTOCOL_VERSION_5)
init_packet->msg.v2_msg.send_ndis_config.capability.sriov = 1;
ret = vmbus_sendpacket(device->channel, init_packet,
sizeof(struct nvsp_message),
(unsigned long)init_packet,
VM_PKT_DATA_INBAND, 0);
return ret;
}
static int netvsc_connect_vsp(struct hv_device *device)
{
int ret;
struct netvsc_device *net_device;
struct nvsp_message *init_packet;
int ndis_version;
u32 ver_list[] = { NVSP_PROTOCOL_VERSION_1, NVSP_PROTOCOL_VERSION_2,
NVSP_PROTOCOL_VERSION_4, NVSP_PROTOCOL_VERSION_5 };
int i, num_ver = 4;
net_device = get_outbound_net_device(device);
if (!net_device)
return -ENODEV;
init_packet = &net_device->channel_init_pkt;
for (i = num_ver - 1; i >= 0; i--)
if (negotiate_nvsp_ver(device, net_device, init_packet,
ver_list[i]) == 0) {
net_device->nvsp_version = ver_list[i];
break;
}
if (i < 0) {
ret = -EPROTO;
goto cleanup;
}
pr_debug("Negotiated NVSP version:%x\n", net_device->nvsp_version);
memset(init_packet, 0, sizeof(struct nvsp_message));
if (net_device->nvsp_version <= NVSP_PROTOCOL_VERSION_4)
ndis_version = 0x00060001;
else
ndis_version = 0x0006001e;
init_packet->hdr.msg_type = NVSP_MSG1_TYPE_SEND_NDIS_VER;
init_packet->msg.v1_msg.
send_ndis_ver.ndis_major_ver =
(ndis_version & 0xFFFF0000) >> 16;
init_packet->msg.v1_msg.
send_ndis_ver.ndis_minor_ver =
ndis_version & 0xFFFF;
ret = vmbus_sendpacket(device->channel, init_packet,
sizeof(struct nvsp_message),
(unsigned long)init_packet,
VM_PKT_DATA_INBAND, 0);
if (ret != 0)
goto cleanup;
if (net_device->nvsp_version <= NVSP_PROTOCOL_VERSION_2)
net_device->recv_buf_size = NETVSC_RECEIVE_BUFFER_SIZE_LEGACY;
else
net_device->recv_buf_size = NETVSC_RECEIVE_BUFFER_SIZE;
net_device->send_buf_size = NETVSC_SEND_BUFFER_SIZE;
ret = netvsc_init_buf(device);
cleanup:
return ret;
}
static void netvsc_disconnect_vsp(struct hv_device *device)
{
netvsc_destroy_buf(device);
}
int netvsc_device_remove(struct hv_device *device)
{
struct net_device *ndev = hv_get_drvdata(device);
struct net_device_context *net_device_ctx = netdev_priv(ndev);
struct netvsc_device *net_device = net_device_ctx->nvdev;
netvsc_disconnect_vsp(device);
net_device_ctx->nvdev = NULL;
dev_notice(&device->device, "net device safe to remove\n");
vmbus_close(device->channel);
vfree(net_device->sub_cb_buf);
free_netvsc_device(net_device);
return 0;
}
static inline u32 hv_ringbuf_avail_percent(
struct hv_ring_buffer_info *ring_info)
{
u32 avail_read, avail_write;
hv_get_ringbuffer_availbytes(ring_info, &avail_read, &avail_write);
return avail_write * 100 / ring_info->ring_datasize;
}
static inline void netvsc_free_send_slot(struct netvsc_device *net_device,
u32 index)
{
sync_change_bit(index, net_device->send_section_map);
}
static void netvsc_send_completion(struct netvsc_device *net_device,
struct vmbus_channel *incoming_channel,
struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct nvsp_message *nvsp_packet;
struct hv_netvsc_packet *nvsc_packet;
struct net_device *ndev = hv_get_drvdata(device);
struct net_device_context *net_device_ctx = netdev_priv(ndev);
u32 send_index;
struct sk_buff *skb;
nvsp_packet = (struct nvsp_message *)((unsigned long)packet +
(packet->offset8 << 3));
if ((nvsp_packet->hdr.msg_type == NVSP_MSG_TYPE_INIT_COMPLETE) ||
(nvsp_packet->hdr.msg_type ==
NVSP_MSG1_TYPE_SEND_RECV_BUF_COMPLETE) ||
(nvsp_packet->hdr.msg_type ==
NVSP_MSG1_TYPE_SEND_SEND_BUF_COMPLETE) ||
(nvsp_packet->hdr.msg_type ==
NVSP_MSG5_TYPE_SUBCHANNEL)) {
memcpy(&net_device->channel_init_pkt, nvsp_packet,
sizeof(struct nvsp_message));
complete(&net_device->channel_init_wait);
} else if (nvsp_packet->hdr.msg_type ==
NVSP_MSG1_TYPE_SEND_RNDIS_PKT_COMPLETE) {
int num_outstanding_sends;
u16 q_idx = 0;
struct vmbus_channel *channel = device->channel;
int queue_sends;
skb = (struct sk_buff *)(unsigned long)packet->trans_id;
if (skb) {
nvsc_packet = (struct hv_netvsc_packet *) skb->cb;
send_index = nvsc_packet->send_buf_index;
if (send_index != NETVSC_INVALID_INDEX)
netvsc_free_send_slot(net_device, send_index);
q_idx = nvsc_packet->q_idx;
channel = incoming_channel;
dev_kfree_skb_any(skb);
}
num_outstanding_sends =
atomic_dec_return(&net_device->num_outstanding_sends);
queue_sends = atomic_dec_return(&net_device->
queue_sends[q_idx]);
if (net_device->destroy && num_outstanding_sends == 0)
wake_up(&net_device->wait_drain);
if (netif_tx_queue_stopped(netdev_get_tx_queue(ndev, q_idx)) &&
!net_device_ctx->start_remove &&
(hv_ringbuf_avail_percent(&channel->outbound) >
RING_AVAIL_PERCENT_HIWATER || queue_sends < 1))
netif_tx_wake_queue(netdev_get_tx_queue(
ndev, q_idx));
} else {
netdev_err(ndev, "Unknown send completion packet type- "
"%d received!!\n", nvsp_packet->hdr.msg_type);
}
}
static u32 netvsc_get_next_send_section(struct netvsc_device *net_device)
{
unsigned long index;
u32 max_words = net_device->map_words;
unsigned long *map_addr = (unsigned long *)net_device->send_section_map;
u32 section_cnt = net_device->send_section_cnt;
int ret_val = NETVSC_INVALID_INDEX;
int i;
int prev_val;
for (i = 0; i < max_words; i++) {
if (!~(map_addr[i]))
continue;
index = ffz(map_addr[i]);
prev_val = sync_test_and_set_bit(index, &map_addr[i]);
if (prev_val)
continue;
if ((index + (i * BITS_PER_LONG)) >= section_cnt)
break;
ret_val = (index + (i * BITS_PER_LONG));
break;
}
return ret_val;
}
static u32 netvsc_copy_to_send_buf(struct netvsc_device *net_device,
unsigned int section_index,
u32 pend_size,
struct hv_netvsc_packet *packet,
struct rndis_message *rndis_msg,
struct hv_page_buffer **pb,
struct sk_buff *skb)
{
char *start = net_device->send_buf;
char *dest = start + (section_index * net_device->send_section_size)
+ pend_size;
int i;
bool is_data_pkt = (skb != NULL) ? true : false;
bool xmit_more = (skb != NULL) ? skb->xmit_more : false;
u32 msg_size = 0;
u32 padding = 0;
u32 remain = packet->total_data_buflen % net_device->pkt_align;
u32 page_count = packet->cp_partial ? packet->rmsg_pgcnt :
packet->page_buf_cnt;
if (is_data_pkt && xmit_more && remain &&
!packet->cp_partial) {
padding = net_device->pkt_align - remain;
rndis_msg->msg_len += padding;
packet->total_data_buflen += padding;
}
for (i = 0; i < page_count; i++) {
char *src = phys_to_virt((*pb)[i].pfn << PAGE_SHIFT);
u32 offset = (*pb)[i].offset;
u32 len = (*pb)[i].len;
memcpy(dest, (src + offset), len);
msg_size += len;
dest += len;
}
if (padding) {
memset(dest, 0, padding);
msg_size += padding;
}
return msg_size;
}
static inline int netvsc_send_pkt(
struct hv_device *device,
struct hv_netvsc_packet *packet,
struct netvsc_device *net_device,
struct hv_page_buffer **pb,
struct sk_buff *skb)
{
struct nvsp_message nvmsg;
u16 q_idx = packet->q_idx;
struct vmbus_channel *out_channel = net_device->chn_table[q_idx];
struct net_device *ndev = hv_get_drvdata(device);
u64 req_id;
int ret;
struct hv_page_buffer *pgbuf;
u32 ring_avail = hv_ringbuf_avail_percent(&out_channel->outbound);
bool xmit_more = (skb != NULL) ? skb->xmit_more : false;
nvmsg.hdr.msg_type = NVSP_MSG1_TYPE_SEND_RNDIS_PKT;
if (skb != NULL) {
nvmsg.msg.v1_msg.send_rndis_pkt.channel_type = 0;
} else {
nvmsg.msg.v1_msg.send_rndis_pkt.channel_type = 1;
}
nvmsg.msg.v1_msg.send_rndis_pkt.send_buf_section_index =
packet->send_buf_index;
if (packet->send_buf_index == NETVSC_INVALID_INDEX)
nvmsg.msg.v1_msg.send_rndis_pkt.send_buf_section_size = 0;
else
nvmsg.msg.v1_msg.send_rndis_pkt.send_buf_section_size =
packet->total_data_buflen;
req_id = (ulong)skb;
if (out_channel->rescind)
return -ENODEV;
if (ring_avail < (RING_AVAIL_PERCENT_LOWATER + 1))
xmit_more = false;
if (packet->page_buf_cnt) {
pgbuf = packet->cp_partial ? (*pb) +
packet->rmsg_pgcnt : (*pb);
ret = vmbus_sendpacket_pagebuffer_ctl(out_channel,
pgbuf,
packet->page_buf_cnt,
&nvmsg,
sizeof(struct nvsp_message),
req_id,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED,
!xmit_more);
} else {
ret = vmbus_sendpacket_ctl(out_channel, &nvmsg,
sizeof(struct nvsp_message),
req_id,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED,
!xmit_more);
}
if (ret == 0) {
atomic_inc(&net_device->num_outstanding_sends);
atomic_inc(&net_device->queue_sends[q_idx]);
if (ring_avail < RING_AVAIL_PERCENT_LOWATER) {
netif_tx_stop_queue(netdev_get_tx_queue(ndev, q_idx));
if (atomic_read(&net_device->
queue_sends[q_idx]) < 1)
netif_tx_wake_queue(netdev_get_tx_queue(
ndev, q_idx));
}
} else if (ret == -EAGAIN) {
netif_tx_stop_queue(netdev_get_tx_queue(
ndev, q_idx));
if (atomic_read(&net_device->queue_sends[q_idx]) < 1) {
netif_tx_wake_queue(netdev_get_tx_queue(
ndev, q_idx));
ret = -ENOSPC;
}
} else {
netdev_err(ndev, "Unable to send packet %p ret %d\n",
packet, ret);
}
return ret;
}
static inline void move_pkt_msd(struct hv_netvsc_packet **msd_send,
struct sk_buff **msd_skb,
struct multi_send_data *msdp)
{
*msd_skb = msdp->skb;
*msd_send = msdp->pkt;
msdp->skb = NULL;
msdp->pkt = NULL;
msdp->count = 0;
}
int netvsc_send(struct hv_device *device,
struct hv_netvsc_packet *packet,
struct rndis_message *rndis_msg,
struct hv_page_buffer **pb,
struct sk_buff *skb)
{
struct netvsc_device *net_device;
int ret = 0, m_ret = 0;
struct vmbus_channel *out_channel;
u16 q_idx = packet->q_idx;
u32 pktlen = packet->total_data_buflen, msd_len = 0;
unsigned int section_index = NETVSC_INVALID_INDEX;
struct multi_send_data *msdp;
struct hv_netvsc_packet *msd_send = NULL, *cur_send = NULL;
struct sk_buff *msd_skb = NULL;
bool try_batch;
bool xmit_more = (skb != NULL) ? skb->xmit_more : false;
net_device = get_outbound_net_device(device);
if (!net_device)
return -ENODEV;
out_channel = net_device->chn_table[q_idx];
packet->send_buf_index = NETVSC_INVALID_INDEX;
packet->cp_partial = false;
if (!skb) {
cur_send = packet;
goto send_now;
}
msdp = &net_device->msd[q_idx];
if (msdp->pkt)
msd_len = msdp->pkt->total_data_buflen;
try_batch = (skb != NULL) && msd_len > 0 && msdp->count <
net_device->max_pkt;
if (try_batch && msd_len + pktlen + net_device->pkt_align <
net_device->send_section_size) {
section_index = msdp->pkt->send_buf_index;
} else if (try_batch && msd_len + packet->rmsg_size <
net_device->send_section_size) {
section_index = msdp->pkt->send_buf_index;
packet->cp_partial = true;
} else if ((skb != NULL) && pktlen + net_device->pkt_align <
net_device->send_section_size) {
section_index = netvsc_get_next_send_section(net_device);
if (section_index != NETVSC_INVALID_INDEX) {
move_pkt_msd(&msd_send, &msd_skb, msdp);
msd_len = 0;
}
}
if (section_index != NETVSC_INVALID_INDEX) {
netvsc_copy_to_send_buf(net_device,
section_index, msd_len,
packet, rndis_msg, pb, skb);
packet->send_buf_index = section_index;
if (packet->cp_partial) {
packet->page_buf_cnt -= packet->rmsg_pgcnt;
packet->total_data_buflen = msd_len + packet->rmsg_size;
} else {
packet->page_buf_cnt = 0;
packet->total_data_buflen += msd_len;
}
if (msdp->skb)
dev_kfree_skb_any(msdp->skb);
if (xmit_more && !packet->cp_partial) {
msdp->skb = skb;
msdp->pkt = packet;
msdp->count++;
} else {
cur_send = packet;
msdp->skb = NULL;
msdp->pkt = NULL;
msdp->count = 0;
}
} else {
move_pkt_msd(&msd_send, &msd_skb, msdp);
cur_send = packet;
}
if (msd_send) {
m_ret = netvsc_send_pkt(device, msd_send, net_device,
NULL, msd_skb);
if (m_ret != 0) {
netvsc_free_send_slot(net_device,
msd_send->send_buf_index);
dev_kfree_skb_any(msd_skb);
}
}
send_now:
if (cur_send)
ret = netvsc_send_pkt(device, cur_send, net_device, pb, skb);
if (ret != 0 && section_index != NETVSC_INVALID_INDEX)
netvsc_free_send_slot(net_device, section_index);
return ret;
}
static void netvsc_send_recv_completion(struct hv_device *device,
struct vmbus_channel *channel,
struct netvsc_device *net_device,
u64 transaction_id, u32 status)
{
struct nvsp_message recvcompMessage;
int retries = 0;
int ret;
struct net_device *ndev = hv_get_drvdata(device);
recvcompMessage.hdr.msg_type =
NVSP_MSG1_TYPE_SEND_RNDIS_PKT_COMPLETE;
recvcompMessage.msg.v1_msg.send_rndis_pkt_complete.status = status;
retry_send_cmplt:
ret = vmbus_sendpacket(channel, &recvcompMessage,
sizeof(struct nvsp_message), transaction_id,
VM_PKT_COMP, 0);
if (ret == 0) {
} else if (ret == -EAGAIN) {
retries++;
netdev_err(ndev, "unable to send receive completion pkt"
" (tid %llx)...retrying %d\n", transaction_id, retries);
if (retries < 4) {
udelay(100);
goto retry_send_cmplt;
} else {
netdev_err(ndev, "unable to send receive "
"completion pkt (tid %llx)...give up retrying\n",
transaction_id);
}
} else {
netdev_err(ndev, "unable to send receive "
"completion pkt - %llx\n", transaction_id);
}
}
static void netvsc_receive(struct netvsc_device *net_device,
struct vmbus_channel *channel,
struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct vmtransfer_page_packet_header *vmxferpage_packet;
struct nvsp_message *nvsp_packet;
struct hv_netvsc_packet nv_pkt;
struct hv_netvsc_packet *netvsc_packet = &nv_pkt;
u32 status = NVSP_STAT_SUCCESS;
int i;
int count = 0;
struct net_device *ndev = hv_get_drvdata(device);
void *data;
if (packet->type != VM_PKT_DATA_USING_XFER_PAGES) {
netdev_err(ndev, "Unknown packet type received - %d\n",
packet->type);
return;
}
nvsp_packet = (struct nvsp_message *)((unsigned long)packet +
(packet->offset8 << 3));
if (nvsp_packet->hdr.msg_type !=
NVSP_MSG1_TYPE_SEND_RNDIS_PKT) {
netdev_err(ndev, "Unknown nvsp packet type received-"
" %d\n", nvsp_packet->hdr.msg_type);
return;
}
vmxferpage_packet = (struct vmtransfer_page_packet_header *)packet;
if (vmxferpage_packet->xfer_pageset_id != NETVSC_RECEIVE_BUFFER_ID) {
netdev_err(ndev, "Invalid xfer page set id - "
"expecting %x got %x\n", NETVSC_RECEIVE_BUFFER_ID,
vmxferpage_packet->xfer_pageset_id);
return;
}
count = vmxferpage_packet->range_cnt;
for (i = 0; i < count; i++) {
data = (void *)((unsigned long)net_device->
recv_buf + vmxferpage_packet->ranges[i].byte_offset);
netvsc_packet->total_data_buflen =
vmxferpage_packet->ranges[i].byte_count;
status = rndis_filter_receive(device, netvsc_packet, &data,
channel);
}
netvsc_send_recv_completion(device, channel, net_device,
vmxferpage_packet->d.trans_id, status);
}
static void netvsc_send_table(struct hv_device *hdev,
struct nvsp_message *nvmsg)
{
struct netvsc_device *nvscdev;
struct net_device *ndev = hv_get_drvdata(hdev);
int i;
u32 count, *tab;
nvscdev = get_outbound_net_device(hdev);
if (!nvscdev)
return;
count = nvmsg->msg.v5_msg.send_table.count;
if (count != VRSS_SEND_TAB_SIZE) {
netdev_err(ndev, "Received wrong send-table size:%u\n", count);
return;
}
tab = (u32 *)((unsigned long)&nvmsg->msg.v5_msg.send_table +
nvmsg->msg.v5_msg.send_table.offset);
for (i = 0; i < count; i++)
nvscdev->send_table[i] = tab[i];
}
static void netvsc_send_vf(struct net_device_context *net_device_ctx,
struct nvsp_message *nvmsg)
{
net_device_ctx->vf_alloc = nvmsg->msg.v4_msg.vf_assoc.allocated;
net_device_ctx->vf_serial = nvmsg->msg.v4_msg.vf_assoc.serial;
}
static inline void netvsc_receive_inband(struct hv_device *hdev,
struct net_device_context *net_device_ctx,
struct nvsp_message *nvmsg)
{
switch (nvmsg->hdr.msg_type) {
case NVSP_MSG5_TYPE_SEND_INDIRECTION_TABLE:
netvsc_send_table(hdev, nvmsg);
break;
case NVSP_MSG4_TYPE_SEND_VF_ASSOCIATION:
netvsc_send_vf(net_device_ctx, nvmsg);
break;
}
}
static void netvsc_process_raw_pkt(struct hv_device *device,
struct vmbus_channel *channel,
struct netvsc_device *net_device,
struct net_device *ndev,
u64 request_id,
struct vmpacket_descriptor *desc)
{
struct nvsp_message *nvmsg;
struct net_device_context *net_device_ctx = netdev_priv(ndev);
nvmsg = (struct nvsp_message *)((unsigned long)
desc + (desc->offset8 << 3));
switch (desc->type) {
case VM_PKT_COMP:
netvsc_send_completion(net_device, channel, device, desc);
break;
case VM_PKT_DATA_USING_XFER_PAGES:
netvsc_receive(net_device, channel, device, desc);
break;
case VM_PKT_DATA_INBAND:
netvsc_receive_inband(device, net_device_ctx, nvmsg);
break;
default:
netdev_err(ndev, "unhandled packet type %d, tid %llx\n",
desc->type, request_id);
break;
}
}
void netvsc_channel_cb(void *context)
{
int ret;
struct vmbus_channel *channel = (struct vmbus_channel *)context;
struct hv_device *device;
struct netvsc_device *net_device;
u32 bytes_recvd;
u64 request_id;
struct vmpacket_descriptor *desc;
unsigned char *buffer;
int bufferlen = NETVSC_PACKET_SIZE;
struct net_device *ndev;
bool need_to_commit = false;
if (channel->primary_channel != NULL)
device = channel->primary_channel->device_obj;
else
device = channel->device_obj;
net_device = get_inbound_net_device(device);
if (!net_device)
return;
ndev = hv_get_drvdata(device);
buffer = get_per_channel_state(channel);
do {
desc = get_next_pkt_raw(channel);
if (desc != NULL) {
netvsc_process_raw_pkt(device,
channel,
net_device,
ndev,
desc->trans_id,
desc);
put_pkt_raw(channel, desc);
need_to_commit = true;
continue;
}
if (need_to_commit) {
need_to_commit = false;
commit_rd_index(channel);
}
ret = vmbus_recvpacket_raw(channel, buffer, bufferlen,
&bytes_recvd, &request_id);
if (ret == 0) {
if (bytes_recvd > 0) {
desc = (struct vmpacket_descriptor *)buffer;
netvsc_process_raw_pkt(device,
channel,
net_device,
ndev,
request_id,
desc);
} else {
break;
}
} else if (ret == -ENOBUFS) {
if (bufferlen > NETVSC_PACKET_SIZE)
kfree(buffer);
buffer = kmalloc(bytes_recvd, GFP_ATOMIC);
if (buffer == NULL) {
netdev_err(ndev,
"unable to allocate buffer of size "
"(%d)!!\n", bytes_recvd);
break;
}
bufferlen = bytes_recvd;
}
} while (1);
if (bufferlen > NETVSC_PACKET_SIZE)
kfree(buffer);
return;
}
int netvsc_device_add(struct hv_device *device, void *additional_info)
{
int i, ret = 0;
int ring_size =
((struct netvsc_device_info *)additional_info)->ring_size;
struct netvsc_device *net_device;
struct net_device *ndev = hv_get_drvdata(device);
struct net_device_context *net_device_ctx = netdev_priv(ndev);
net_device = alloc_net_device();
if (!net_device)
return -ENOMEM;
net_device->ring_size = ring_size;
init_completion(&net_device->channel_init_wait);
set_per_channel_state(device->channel, net_device->cb_buffer);
ret = vmbus_open(device->channel, ring_size * PAGE_SIZE,
ring_size * PAGE_SIZE, NULL, 0,
netvsc_channel_cb, device->channel);
if (ret != 0) {
netdev_err(ndev, "unable to open channel: %d\n", ret);
goto cleanup;
}
pr_info("hv_netvsc channel opened successfully\n");
for (i = 0; i < VRSS_CHANNEL_MAX; i++)
net_device->chn_table[i] = device->channel;
wmb();
net_device_ctx->nvdev = net_device;
ret = netvsc_connect_vsp(device);
if (ret != 0) {
netdev_err(ndev,
"unable to connect to NetVSP - %d\n", ret);
goto close;
}
return ret;
close:
vmbus_close(device->channel);
cleanup:
free_netvsc_device(net_device);
return ret;
}
