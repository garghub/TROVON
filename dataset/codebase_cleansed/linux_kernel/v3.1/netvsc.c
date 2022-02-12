static struct netvsc_device *alloc_net_device(struct hv_device *device)
{
struct netvsc_device *net_device;
net_device = kzalloc(sizeof(struct netvsc_device), GFP_KERNEL);
if (!net_device)
return NULL;
atomic_cmpxchg(&net_device->refcnt, 0, 2);
net_device->dev = device;
device->ext = net_device;
return net_device;
}
static void free_net_device(struct netvsc_device *device)
{
WARN_ON(atomic_read(&device->refcnt) != 0);
device->dev->ext = NULL;
kfree(device);
}
static struct netvsc_device *get_outbound_net_device(struct hv_device *device)
{
struct netvsc_device *net_device;
net_device = device->ext;
if (net_device && atomic_read(&net_device->refcnt) > 1)
atomic_inc(&net_device->refcnt);
else
net_device = NULL;
return net_device;
}
static struct netvsc_device *get_inbound_net_device(struct hv_device *device)
{
struct netvsc_device *net_device;
net_device = device->ext;
if (net_device && atomic_read(&net_device->refcnt))
atomic_inc(&net_device->refcnt);
else
net_device = NULL;
return net_device;
}
static void put_net_device(struct hv_device *device)
{
struct netvsc_device *net_device;
net_device = device->ext;
atomic_dec(&net_device->refcnt);
}
static struct netvsc_device *release_outbound_net_device(
struct hv_device *device)
{
struct netvsc_device *net_device;
net_device = device->ext;
if (net_device == NULL)
return NULL;
while (atomic_cmpxchg(&net_device->refcnt, 2, 1) != 2)
udelay(100);
return net_device;
}
static struct netvsc_device *release_inbound_net_device(
struct hv_device *device)
{
struct netvsc_device *net_device;
net_device = device->ext;
if (net_device == NULL)
return NULL;
while (atomic_cmpxchg(&net_device->refcnt, 1, 0) != 1)
udelay(100);
device->ext = NULL;
return net_device;
}
static int netvsc_destroy_recv_buf(struct netvsc_device *net_device)
{
struct nvsp_message *revoke_packet;
int ret = 0;
if (net_device->recv_section_cnt) {
revoke_packet = &net_device->revoke_packet;
memset(revoke_packet, 0, sizeof(struct nvsp_message));
revoke_packet->hdr.msg_type =
NVSP_MSG1_TYPE_REVOKE_RECV_BUF;
revoke_packet->msg.v1_msg.
revoke_recv_buf.id = NETVSC_RECEIVE_BUFFER_ID;
ret = vmbus_sendpacket(net_device->dev->channel,
revoke_packet,
sizeof(struct nvsp_message),
(unsigned long)revoke_packet,
VM_PKT_DATA_INBAND, 0);
if (ret != 0) {
dev_err(&net_device->dev->device, "unable to send "
"revoke receive buffer to netvsp");
return -1;
}
}
if (net_device->recv_buf_gpadl_handle) {
ret = vmbus_teardown_gpadl(net_device->dev->channel,
net_device->recv_buf_gpadl_handle);
if (ret != 0) {
dev_err(&net_device->dev->device,
"unable to teardown receive buffer's gpadl");
return -1;
}
net_device->recv_buf_gpadl_handle = 0;
}
if (net_device->recv_buf) {
free_pages((unsigned long)net_device->recv_buf,
get_order(net_device->recv_buf_size));
net_device->recv_buf = NULL;
}
if (net_device->recv_section) {
net_device->recv_section_cnt = 0;
kfree(net_device->recv_section);
net_device->recv_section = NULL;
}
return ret;
}
static int netvsc_init_recv_buf(struct hv_device *device)
{
int ret = 0;
int t;
struct netvsc_device *net_device;
struct nvsp_message *init_packet;
net_device = get_outbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "unable to get net device..."
"device being destroyed?");
return -1;
}
net_device->recv_buf =
(void *)__get_free_pages(GFP_KERNEL|__GFP_ZERO,
get_order(net_device->recv_buf_size));
if (!net_device->recv_buf) {
dev_err(&device->device, "unable to allocate receive "
"buffer of size %d", net_device->recv_buf_size);
ret = -1;
goto cleanup;
}
ret = vmbus_establish_gpadl(device->channel, net_device->recv_buf,
net_device->recv_buf_size,
&net_device->recv_buf_gpadl_handle);
if (ret != 0) {
dev_err(&device->device,
"unable to establish receive buffer's gpadl");
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
dev_err(&device->device,
"unable to send receive buffer's gpadl to netvsp");
goto cleanup;
}
t = wait_for_completion_timeout(&net_device->channel_init_wait, 5*HZ);
BUG_ON(t == 0);
if (init_packet->msg.v1_msg.
send_recv_buf_complete.status != NVSP_STAT_SUCCESS) {
dev_err(&device->device, "Unable to complete receive buffer "
"initialzation with NetVsp - status %d",
init_packet->msg.v1_msg.
send_recv_buf_complete.status);
ret = -1;
goto cleanup;
}
net_device->recv_section_cnt = init_packet->msg.
v1_msg.send_recv_buf_complete.num_sections;
net_device->recv_section = kmalloc(net_device->recv_section_cnt
* sizeof(struct nvsp_1_receive_buffer_section), GFP_KERNEL);
if (net_device->recv_section == NULL) {
ret = -1;
goto cleanup;
}
memcpy(net_device->recv_section,
init_packet->msg.v1_msg.
send_recv_buf_complete.sections,
net_device->recv_section_cnt *
sizeof(struct nvsp_1_receive_buffer_section));
if (net_device->recv_section_cnt != 1 ||
net_device->recv_section->offset != 0) {
ret = -1;
goto cleanup;
}
goto exit;
cleanup:
netvsc_destroy_recv_buf(net_device);
exit:
put_net_device(device);
return ret;
}
static int netvsc_connect_vsp(struct hv_device *device)
{
int ret, t;
struct netvsc_device *net_device;
struct nvsp_message *init_packet;
int ndis_version;
net_device = get_outbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "unable to get net device..."
"device being destroyed?");
return -1;
}
init_packet = &net_device->channel_init_pkt;
memset(init_packet, 0, sizeof(struct nvsp_message));
init_packet->hdr.msg_type = NVSP_MSG_TYPE_INIT;
init_packet->msg.init_msg.init.min_protocol_ver =
NVSP_MIN_PROTOCOL_VERSION;
init_packet->msg.init_msg.init.max_protocol_ver =
NVSP_MAX_PROTOCOL_VERSION;
ret = vmbus_sendpacket(device->channel, init_packet,
sizeof(struct nvsp_message),
(unsigned long)init_packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
goto cleanup;
t = wait_for_completion_timeout(&net_device->channel_init_wait, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
if (init_packet->msg.init_msg.init_complete.status !=
NVSP_STAT_SUCCESS) {
ret = -1;
goto cleanup;
}
if (init_packet->msg.init_msg.init_complete.
negotiated_protocol_ver != NVSP_PROTOCOL_VERSION_1) {
ret = -1;
goto cleanup;
}
memset(init_packet, 0, sizeof(struct nvsp_message));
ndis_version = 0x00050000;
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
if (ret != 0) {
ret = -1;
goto cleanup;
}
ret = netvsc_init_recv_buf(device);
cleanup:
put_net_device(device);
return ret;
}
static void netvsc_disconnect_vsp(struct netvsc_device *net_device)
{
netvsc_destroy_recv_buf(net_device);
}
int netvsc_device_remove(struct hv_device *device)
{
struct netvsc_device *net_device;
struct hv_netvsc_packet *netvsc_packet, *pos;
net_device = release_outbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "No net device present!!");
return -1;
}
while (atomic_read(&net_device->num_outstanding_sends)) {
dev_err(&device->device,
"waiting for %d requests to complete...",
atomic_read(&net_device->num_outstanding_sends));
udelay(100);
}
netvsc_disconnect_vsp(net_device);
net_device = release_inbound_net_device(device);
dev_notice(&device->device, "net device safe to remove");
vmbus_close(device->channel);
list_for_each_entry_safe(netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
list_del(&netvsc_packet->list_ent);
kfree(netvsc_packet);
}
free_net_device(net_device);
return 0;
}
static void netvsc_send_completion(struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct netvsc_device *net_device;
struct nvsp_message *nvsp_packet;
struct hv_netvsc_packet *nvsc_packet;
net_device = get_inbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "unable to get net device..."
"device being destroyed?");
return;
}
nvsp_packet = (struct nvsp_message *)((unsigned long)packet +
(packet->offset8 << 3));
if ((nvsp_packet->hdr.msg_type == NVSP_MSG_TYPE_INIT_COMPLETE) ||
(nvsp_packet->hdr.msg_type ==
NVSP_MSG1_TYPE_SEND_RECV_BUF_COMPLETE) ||
(nvsp_packet->hdr.msg_type ==
NVSP_MSG1_TYPE_SEND_SEND_BUF_COMPLETE)) {
memcpy(&net_device->channel_init_pkt, nvsp_packet,
sizeof(struct nvsp_message));
complete(&net_device->channel_init_wait);
} else if (nvsp_packet->hdr.msg_type ==
NVSP_MSG1_TYPE_SEND_RNDIS_PKT_COMPLETE) {
nvsc_packet = (struct hv_netvsc_packet *)(unsigned long)
packet->trans_id;
nvsc_packet->completion.send.send_completion(
nvsc_packet->completion.send.send_completion_ctx);
atomic_dec(&net_device->num_outstanding_sends);
} else {
dev_err(&device->device, "Unknown send completion packet type- "
"%d received!!", nvsp_packet->hdr.msg_type);
}
put_net_device(device);
}
int netvsc_send(struct hv_device *device,
struct hv_netvsc_packet *packet)
{
struct netvsc_device *net_device;
int ret = 0;
struct nvsp_message sendMessage;
net_device = get_outbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "net device (%p) shutting down..."
"ignoring outbound packets", net_device);
return -2;
}
sendMessage.hdr.msg_type = NVSP_MSG1_TYPE_SEND_RNDIS_PKT;
if (packet->is_data_pkt) {
sendMessage.msg.v1_msg.send_rndis_pkt.channel_type = 0;
} else {
sendMessage.msg.v1_msg.send_rndis_pkt.channel_type = 1;
}
sendMessage.msg.v1_msg.send_rndis_pkt.send_buf_section_index =
0xFFFFFFFF;
sendMessage.msg.v1_msg.send_rndis_pkt.send_buf_section_size = 0;
if (packet->page_buf_cnt) {
ret = vmbus_sendpacket_pagebuffer(device->channel,
packet->page_buf,
packet->page_buf_cnt,
&sendMessage,
sizeof(struct nvsp_message),
(unsigned long)packet);
} else {
ret = vmbus_sendpacket(device->channel, &sendMessage,
sizeof(struct nvsp_message),
(unsigned long)packet,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
}
if (ret != 0)
dev_err(&device->device, "Unable to send packet %p ret %d",
packet, ret);
atomic_inc(&net_device->num_outstanding_sends);
put_net_device(device);
return ret;
}
static void netvsc_send_recv_completion(struct hv_device *device,
u64 transaction_id)
{
struct nvsp_message recvcompMessage;
int retries = 0;
int ret;
recvcompMessage.hdr.msg_type =
NVSP_MSG1_TYPE_SEND_RNDIS_PKT_COMPLETE;
recvcompMessage.msg.v1_msg.send_rndis_pkt_complete.status =
NVSP_STAT_SUCCESS;
retry_send_cmplt:
ret = vmbus_sendpacket(device->channel, &recvcompMessage,
sizeof(struct nvsp_message), transaction_id,
VM_PKT_COMP, 0);
if (ret == 0) {
} else if (ret == -1) {
retries++;
dev_err(&device->device, "unable to send receive completion pkt"
" (tid %llx)...retrying %d", transaction_id, retries);
if (retries < 4) {
udelay(100);
goto retry_send_cmplt;
} else {
dev_err(&device->device, "unable to send receive "
"completion pkt (tid %llx)...give up retrying",
transaction_id);
}
} else {
dev_err(&device->device, "unable to send receive "
"completion pkt - %llx", transaction_id);
}
}
static void netvsc_receive_completion(void *context)
{
struct hv_netvsc_packet *packet = context;
struct hv_device *device = (struct hv_device *)packet->device;
struct netvsc_device *net_device;
u64 transaction_id = 0;
bool fsend_receive_comp = false;
unsigned long flags;
net_device = get_inbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "unable to get net device..."
"device being destroyed?");
return;
}
spin_lock_irqsave(&net_device->recv_pkt_list_lock, flags);
packet->xfer_page_pkt->count--;
if (packet->xfer_page_pkt->count == 0) {
fsend_receive_comp = true;
transaction_id = packet->completion.recv.recv_completion_tid;
list_add_tail(&packet->xfer_page_pkt->list_ent,
&net_device->recv_pkt_list);
}
list_add_tail(&packet->list_ent, &net_device->recv_pkt_list);
spin_unlock_irqrestore(&net_device->recv_pkt_list_lock, flags);
if (fsend_receive_comp)
netvsc_send_recv_completion(device, transaction_id);
put_net_device(device);
}
static void netvsc_receive(struct hv_device *device,
struct vmpacket_descriptor *packet)
{
struct netvsc_device *net_device;
struct vmtransfer_page_packet_header *vmxferpage_packet;
struct nvsp_message *nvsp_packet;
struct hv_netvsc_packet *netvsc_packet = NULL;
unsigned long start;
unsigned long end, end_virtual;
struct xferpage_packet *xferpage_packet = NULL;
int i, j;
int count = 0, bytes_remain = 0;
unsigned long flags;
LIST_HEAD(listHead);
net_device = get_inbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "unable to get net device..."
"device being destroyed?");
return;
}
if (packet->type != VM_PKT_DATA_USING_XFER_PAGES) {
dev_err(&device->device, "Unknown packet type received - %d",
packet->type);
put_net_device(device);
return;
}
nvsp_packet = (struct nvsp_message *)((unsigned long)packet +
(packet->offset8 << 3));
if (nvsp_packet->hdr.msg_type !=
NVSP_MSG1_TYPE_SEND_RNDIS_PKT) {
dev_err(&device->device, "Unknown nvsp packet type received-"
" %d", nvsp_packet->hdr.msg_type);
put_net_device(device);
return;
}
vmxferpage_packet = (struct vmtransfer_page_packet_header *)packet;
if (vmxferpage_packet->xfer_pageset_id != NETVSC_RECEIVE_BUFFER_ID) {
dev_err(&device->device, "Invalid xfer page set id - "
"expecting %x got %x", NETVSC_RECEIVE_BUFFER_ID,
vmxferpage_packet->xfer_pageset_id);
put_net_device(device);
return;
}
spin_lock_irqsave(&net_device->recv_pkt_list_lock, flags);
while (!list_empty(&net_device->recv_pkt_list)) {
list_move_tail(net_device->recv_pkt_list.next, &listHead);
if (++count == vmxferpage_packet->range_cnt + 1)
break;
}
spin_unlock_irqrestore(&net_device->recv_pkt_list_lock, flags);
if (count < 2) {
dev_err(&device->device, "Got only %d netvsc pkt...needed "
"%d pkts. Dropping this xfer page packet completely!",
count, vmxferpage_packet->range_cnt + 1);
spin_lock_irqsave(&net_device->recv_pkt_list_lock, flags);
for (i = count; i != 0; i--) {
list_move_tail(listHead.next,
&net_device->recv_pkt_list);
}
spin_unlock_irqrestore(&net_device->recv_pkt_list_lock,
flags);
netvsc_send_recv_completion(device,
vmxferpage_packet->d.trans_id);
put_net_device(device);
return;
}
xferpage_packet = (struct xferpage_packet *)listHead.next;
list_del(&xferpage_packet->list_ent);
xferpage_packet->count = count - 1;
if (xferpage_packet->count != vmxferpage_packet->range_cnt) {
dev_err(&device->device, "Needed %d netvsc pkts to satisy "
"this xfer page...got %d",
vmxferpage_packet->range_cnt, xferpage_packet->count);
}
for (i = 0; i < (count - 1); i++) {
netvsc_packet = (struct hv_netvsc_packet *)listHead.next;
list_del(&netvsc_packet->list_ent);
netvsc_packet->xfer_page_pkt = xferpage_packet;
netvsc_packet->completion.recv.recv_completion =
netvsc_receive_completion;
netvsc_packet->completion.recv.recv_completion_ctx =
netvsc_packet;
netvsc_packet->device = device;
netvsc_packet->completion.recv.recv_completion_tid =
vmxferpage_packet->d.trans_id;
netvsc_packet->total_data_buflen =
vmxferpage_packet->ranges[i].byte_count;
netvsc_packet->page_buf_cnt = 1;
netvsc_packet->page_buf[0].len =
vmxferpage_packet->ranges[i].byte_count;
start = virt_to_phys((void *)((unsigned long)net_device->
recv_buf + vmxferpage_packet->ranges[i].byte_offset));
netvsc_packet->page_buf[0].pfn = start >> PAGE_SHIFT;
end_virtual = (unsigned long)net_device->recv_buf
+ vmxferpage_packet->ranges[i].byte_offset
+ vmxferpage_packet->ranges[i].byte_count - 1;
end = virt_to_phys((void *)end_virtual);
netvsc_packet->page_buf[0].offset =
vmxferpage_packet->ranges[i].byte_offset &
(PAGE_SIZE - 1);
if ((end >> PAGE_SHIFT) != (start >> PAGE_SHIFT)) {
netvsc_packet->page_buf[0].len =
(netvsc_packet->page_buf[0].pfn <<
PAGE_SHIFT)
+ PAGE_SIZE - start;
bytes_remain = netvsc_packet->total_data_buflen -
netvsc_packet->page_buf[0].len;
for (j = 1; j < NETVSC_PACKET_MAXPAGE; j++) {
netvsc_packet->page_buf[j].offset = 0;
if (bytes_remain <= PAGE_SIZE) {
netvsc_packet->page_buf[j].len =
bytes_remain;
bytes_remain = 0;
} else {
netvsc_packet->page_buf[j].len =
PAGE_SIZE;
bytes_remain -= PAGE_SIZE;
}
netvsc_packet->page_buf[j].pfn =
virt_to_phys((void *)(end_virtual -
bytes_remain)) >> PAGE_SHIFT;
netvsc_packet->page_buf_cnt++;
if (bytes_remain == 0)
break;
}
}
rndis_filter_receive(device, netvsc_packet);
netvsc_receive_completion(netvsc_packet->
completion.recv.recv_completion_ctx);
}
put_net_device(device);
}
static void netvsc_channel_cb(void *context)
{
int ret;
struct hv_device *device = context;
struct netvsc_device *net_device;
u32 bytes_recvd;
u64 request_id;
unsigned char *packet;
struct vmpacket_descriptor *desc;
unsigned char *buffer;
int bufferlen = NETVSC_PACKET_SIZE;
packet = kzalloc(NETVSC_PACKET_SIZE * sizeof(unsigned char),
GFP_ATOMIC);
if (!packet)
return;
buffer = packet;
net_device = get_inbound_net_device(device);
if (!net_device) {
dev_err(&device->device, "net device (%p) shutting down..."
"ignoring inbound packets", net_device);
goto out;
}
do {
ret = vmbus_recvpacket_raw(device->channel, buffer, bufferlen,
&bytes_recvd, &request_id);
if (ret == 0) {
if (bytes_recvd > 0) {
desc = (struct vmpacket_descriptor *)buffer;
switch (desc->type) {
case VM_PKT_COMP:
netvsc_send_completion(device, desc);
break;
case VM_PKT_DATA_USING_XFER_PAGES:
netvsc_receive(device, desc);
break;
default:
dev_err(&device->device,
"unhandled packet type %d, "
"tid %llx len %d\n",
desc->type, request_id,
bytes_recvd);
break;
}
if (bufferlen > NETVSC_PACKET_SIZE) {
kfree(buffer);
buffer = packet;
bufferlen = NETVSC_PACKET_SIZE;
}
} else {
if (bufferlen > NETVSC_PACKET_SIZE) {
kfree(buffer);
buffer = packet;
bufferlen = NETVSC_PACKET_SIZE;
}
break;
}
} else if (ret == -2) {
buffer = kmalloc(bytes_recvd, GFP_ATOMIC);
if (buffer == NULL) {
dev_err(&device->device,
"unable to allocate buffer of size "
"(%d)!!", bytes_recvd);
break;
}
bufferlen = bytes_recvd;
}
} while (1);
put_net_device(device);
out:
kfree(buffer);
return;
}
int netvsc_device_add(struct hv_device *device, void *additional_info)
{
int ret = 0;
int i;
int ring_size =
((struct netvsc_device_info *)additional_info)->ring_size;
struct netvsc_device *net_device;
struct hv_netvsc_packet *packet, *pos;
net_device = alloc_net_device(device);
if (!net_device) {
ret = -1;
goto cleanup;
}
net_device->recv_buf_size = NETVSC_RECEIVE_BUFFER_SIZE;
spin_lock_init(&net_device->recv_pkt_list_lock);
INIT_LIST_HEAD(&net_device->recv_pkt_list);
for (i = 0; i < NETVSC_RECEIVE_PACKETLIST_COUNT; i++) {
packet = kzalloc(sizeof(struct hv_netvsc_packet) +
(NETVSC_RECEIVE_SG_COUNT *
sizeof(struct hv_page_buffer)), GFP_KERNEL);
if (!packet)
break;
list_add_tail(&packet->list_ent,
&net_device->recv_pkt_list);
}
init_completion(&net_device->channel_init_wait);
ret = vmbus_open(device->channel, ring_size * PAGE_SIZE,
ring_size * PAGE_SIZE, NULL, 0,
netvsc_channel_cb, device);
if (ret != 0) {
dev_err(&device->device, "unable to open channel: %d", ret);
ret = -1;
goto cleanup;
}
pr_info("hv_netvsc channel opened successfully");
ret = netvsc_connect_vsp(device);
if (ret != 0) {
dev_err(&device->device,
"unable to connect to NetVSP - %d", ret);
ret = -1;
goto close;
}
return ret;
close:
vmbus_close(device->channel);
cleanup:
if (net_device) {
list_for_each_entry_safe(packet, pos,
&net_device->recv_pkt_list,
list_ent) {
list_del(&packet->list_ent);
kfree(packet);
}
release_outbound_net_device(device);
release_inbound_net_device(device);
free_net_device(net_device);
}
return ret;
}
int netvsc_initialize(struct hv_driver *drv)
{
drv->name = driver_name;
memcpy(&drv->dev_type, &netvsc_device_type, sizeof(struct hv_guid));
return 0;
}
