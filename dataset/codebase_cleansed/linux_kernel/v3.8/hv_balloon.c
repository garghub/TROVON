static void hot_add_req(struct hv_dynmem_device *dm, struct dm_hot_add *msg)
{
struct dm_hot_add_response resp;
if (do_hot_add) {
pr_info("Memory hot add not supported\n");
}
memset(&resp, 0, sizeof(struct dm_hot_add_response));
resp.hdr.type = DM_MEM_HOT_ADD_RESPONSE;
resp.hdr.size = sizeof(struct dm_hot_add_response);
resp.hdr.trans_id = atomic_inc_return(&trans_id);
resp.page_count = 0;
resp.result = 0;
dm->state = DM_INITIALIZED;
vmbus_sendpacket(dm->dev->channel, &resp,
sizeof(struct dm_hot_add_response),
(unsigned long)NULL,
VM_PKT_DATA_INBAND, 0);
}
static void process_info(struct hv_dynmem_device *dm, struct dm_info_msg *msg)
{
struct dm_info_header *info_hdr;
info_hdr = (struct dm_info_header *)msg->info;
switch (info_hdr->type) {
case INFO_TYPE_MAX_PAGE_CNT:
pr_info("Received INFO_TYPE_MAX_PAGE_CNT\n");
pr_info("Data Size is %d\n", info_hdr->data_size);
break;
default:
pr_info("Received Unknown type: %d\n", info_hdr->type);
}
}
static void post_status(struct hv_dynmem_device *dm)
{
struct dm_status status;
memset(&status, 0, sizeof(struct dm_status));
status.hdr.type = DM_STATUS_REPORT;
status.hdr.size = sizeof(struct dm_status);
status.hdr.trans_id = atomic_inc_return(&trans_id);
status.num_committed = vm_memory_committed();
vmbus_sendpacket(dm->dev->channel, &status,
sizeof(struct dm_status),
(unsigned long)NULL,
VM_PKT_DATA_INBAND, 0);
}
static void free_balloon_pages(struct hv_dynmem_device *dm,
union dm_mem_page_range *range_array)
{
int num_pages = range_array->finfo.page_cnt;
__u64 start_frame = range_array->finfo.start_page;
struct page *pg;
int i;
for (i = 0; i < num_pages; i++) {
pg = pfn_to_page(i + start_frame);
__free_page(pg);
dm->num_pages_ballooned--;
}
}
static int alloc_balloon_pages(struct hv_dynmem_device *dm, int num_pages,
struct dm_balloon_response *bl_resp, int alloc_unit,
bool *alloc_error)
{
int i = 0;
struct page *pg;
if (num_pages < alloc_unit)
return 0;
for (i = 0; (i * alloc_unit) < num_pages; i++) {
if (bl_resp->hdr.size + sizeof(union dm_mem_page_range) >
PAGE_SIZE)
return i * alloc_unit;
pg = alloc_pages(GFP_HIGHUSER | __GFP_NORETRY |
__GFP_NOMEMALLOC | __GFP_NOWARN,
get_order(alloc_unit << PAGE_SHIFT));
if (!pg) {
*alloc_error = true;
return i * alloc_unit;
}
dm->num_pages_ballooned += alloc_unit;
bl_resp->range_count++;
bl_resp->range_array[i].finfo.start_page =
page_to_pfn(pg);
bl_resp->range_array[i].finfo.page_cnt = alloc_unit;
bl_resp->hdr.size += sizeof(union dm_mem_page_range);
}
return num_pages;
}
static void balloon_up(struct hv_dynmem_device *dm, struct dm_balloon *req)
{
int num_pages = req->num_pages;
int num_ballooned = 0;
struct dm_balloon_response *bl_resp;
int alloc_unit;
int ret;
bool alloc_error = false;
bool done = false;
int i;
alloc_unit = 1;
while (!done) {
bl_resp = (struct dm_balloon_response *)send_buffer;
memset(send_buffer, 0, PAGE_SIZE);
bl_resp->hdr.type = DM_BALLOON_RESPONSE;
bl_resp->hdr.trans_id = atomic_inc_return(&trans_id);
bl_resp->hdr.size = sizeof(struct dm_balloon_response);
bl_resp->more_pages = 1;
num_pages -= num_ballooned;
num_ballooned = alloc_balloon_pages(dm, num_pages,
bl_resp, alloc_unit,
&alloc_error);
if ((alloc_error) || (num_ballooned == num_pages)) {
bl_resp->more_pages = 0;
done = true;
dm->state = DM_INITIALIZED;
}
do {
ret = vmbus_sendpacket(dm_device.dev->channel,
bl_resp,
bl_resp->hdr.size,
(unsigned long)NULL,
VM_PKT_DATA_INBAND, 0);
if (ret == -EAGAIN)
msleep(20);
} while (ret == -EAGAIN);
if (ret) {
pr_info("Balloon response failed\n");
for (i = 0; i < bl_resp->range_count; i++)
free_balloon_pages(dm,
&bl_resp->range_array[i]);
done = true;
}
}
}
static void balloon_down(struct hv_dynmem_device *dm,
struct dm_unballoon_request *req)
{
union dm_mem_page_range *range_array = req->range_array;
int range_count = req->range_count;
struct dm_unballoon_response resp;
int i;
for (i = 0; i < range_count; i++)
free_balloon_pages(dm, &range_array[i]);
if (req->more_pages == 1)
return;
memset(&resp, 0, sizeof(struct dm_unballoon_response));
resp.hdr.type = DM_UNBALLOON_RESPONSE;
resp.hdr.trans_id = atomic_inc_return(&trans_id);
resp.hdr.size = sizeof(struct dm_unballoon_response);
vmbus_sendpacket(dm_device.dev->channel, &resp,
sizeof(struct dm_unballoon_response),
(unsigned long)NULL,
VM_PKT_DATA_INBAND, 0);
dm->state = DM_INITIALIZED;
}
static int dm_thread_func(void *dm_dev)
{
struct hv_dynmem_device *dm = dm_dev;
int t;
unsigned long scan_start;
while (!kthread_should_stop()) {
t = wait_for_completion_timeout(&dm_device.config_event, 1*HZ);
if (t == 0)
post_status(dm);
scan_start = jiffies;
switch (dm->state) {
case DM_BALLOON_UP:
balloon_up(dm, (struct dm_balloon *)recv_buffer);
break;
case DM_HOT_ADD:
hot_add_req(dm, (struct dm_hot_add *)recv_buffer);
break;
default:
break;
}
if (!time_in_range(jiffies, scan_start, scan_start + HZ))
post_status(dm);
}
return 0;
}
static void version_resp(struct hv_dynmem_device *dm,
struct dm_version_response *vresp)
{
struct dm_version_request version_req;
int ret;
if (vresp->is_accepted) {
complete(&dm->host_event);
return;
}
if (dm->next_version == 0)
goto version_error;
dm->next_version = 0;
memset(&version_req, 0, sizeof(struct dm_version_request));
version_req.hdr.type = DM_VERSION_REQUEST;
version_req.hdr.size = sizeof(struct dm_version_request);
version_req.hdr.trans_id = atomic_inc_return(&trans_id);
version_req.version.version = DYNMEM_PROTOCOL_VERSION_WIN7;
version_req.is_last_attempt = 1;
ret = vmbus_sendpacket(dm->dev->channel, &version_req,
sizeof(struct dm_version_request),
(unsigned long)NULL,
VM_PKT_DATA_INBAND, 0);
if (ret)
goto version_error;
return;
version_error:
dm->state = DM_INIT_ERROR;
complete(&dm->host_event);
}
static void cap_resp(struct hv_dynmem_device *dm,
struct dm_capabilities_resp_msg *cap_resp)
{
if (!cap_resp->is_accepted) {
pr_info("Capabilities not accepted by host\n");
dm->state = DM_INIT_ERROR;
}
complete(&dm->host_event);
}
static void balloon_onchannelcallback(void *context)
{
struct hv_device *dev = context;
u32 recvlen;
u64 requestid;
struct dm_message *dm_msg;
struct dm_header *dm_hdr;
struct hv_dynmem_device *dm = hv_get_drvdata(dev);
memset(recv_buffer, 0, sizeof(recv_buffer));
vmbus_recvpacket(dev->channel, recv_buffer,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
dm_msg = (struct dm_message *)recv_buffer;
dm_hdr = &dm_msg->hdr;
switch (dm_hdr->type) {
case DM_VERSION_RESPONSE:
version_resp(dm,
(struct dm_version_response *)dm_msg);
break;
case DM_CAPABILITIES_RESPONSE:
cap_resp(dm,
(struct dm_capabilities_resp_msg *)dm_msg);
break;
case DM_BALLOON_REQUEST:
dm->state = DM_BALLOON_UP;
complete(&dm->config_event);
break;
case DM_UNBALLOON_REQUEST:
dm->state = DM_BALLOON_DOWN;
balloon_down(dm,
(struct dm_unballoon_request *)recv_buffer);
break;
case DM_MEM_HOT_ADD_REQUEST:
dm->state = DM_HOT_ADD;
complete(&dm->config_event);
break;
case DM_INFO_MESSAGE:
process_info(dm, (struct dm_info_msg *)dm_msg);
break;
default:
pr_err("Unhandled message: type: %d\n", dm_hdr->type);
}
}
}
static int balloon_probe(struct hv_device *dev,
const struct hv_vmbus_device_id *dev_id)
{
int ret, t;
struct dm_version_request version_req;
struct dm_capabilities cap_msg;
do_hot_add = hot_add;
send_buffer = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!send_buffer)
return -ENOMEM;
ret = vmbus_open(dev->channel, dm_ring_size, dm_ring_size, NULL, 0,
balloon_onchannelcallback, dev);
if (ret)
goto probe_error0;
dm_device.dev = dev;
dm_device.state = DM_INITIALIZING;
dm_device.next_version = DYNMEM_PROTOCOL_VERSION_WIN7;
init_completion(&dm_device.host_event);
init_completion(&dm_device.config_event);
dm_device.thread =
kthread_run(dm_thread_func, &dm_device, "hv_balloon");
if (IS_ERR(dm_device.thread)) {
ret = PTR_ERR(dm_device.thread);
goto probe_error1;
}
hv_set_drvdata(dev, &dm_device);
memset(&version_req, 0, sizeof(struct dm_version_request));
version_req.hdr.type = DM_VERSION_REQUEST;
version_req.hdr.size = sizeof(struct dm_version_request);
version_req.hdr.trans_id = atomic_inc_return(&trans_id);
version_req.version.version = DYNMEM_PROTOCOL_VERSION_WIN8;
version_req.is_last_attempt = 0;
ret = vmbus_sendpacket(dev->channel, &version_req,
sizeof(struct dm_version_request),
(unsigned long)NULL,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret)
goto probe_error2;
t = wait_for_completion_timeout(&dm_device.host_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto probe_error2;
}
if (dm_device.state == DM_INIT_ERROR) {
ret = -ETIMEDOUT;
goto probe_error2;
}
memset(&cap_msg, 0, sizeof(struct dm_capabilities));
cap_msg.hdr.type = DM_CAPABILITIES_REPORT;
cap_msg.hdr.size = sizeof(struct dm_capabilities);
cap_msg.hdr.trans_id = atomic_inc_return(&trans_id);
cap_msg.caps.cap_bits.balloon = 1;
cap_msg.caps.cap_bits.hot_add = 1;
cap_msg.min_page_cnt = 0;
cap_msg.max_page_number = -1;
ret = vmbus_sendpacket(dev->channel, &cap_msg,
sizeof(struct dm_capabilities),
(unsigned long)NULL,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret)
goto probe_error2;
t = wait_for_completion_timeout(&dm_device.host_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto probe_error2;
}
if (dm_device.state == DM_INIT_ERROR) {
ret = -ETIMEDOUT;
goto probe_error2;
}
dm_device.state = DM_INITIALIZED;
return 0;
probe_error2:
kthread_stop(dm_device.thread);
probe_error1:
vmbus_close(dev->channel);
probe_error0:
kfree(send_buffer);
return ret;
}
static int balloon_remove(struct hv_device *dev)
{
struct hv_dynmem_device *dm = hv_get_drvdata(dev);
if (dm->num_pages_ballooned != 0)
pr_warn("Ballooned pages: %d\n", dm->num_pages_ballooned);
vmbus_close(dev->channel);
kthread_stop(dm->thread);
kfree(send_buffer);
return 0;
}
static int __init init_balloon_drv(void)
{
return vmbus_driver_register(&balloon_drv);
}
static void exit_balloon_drv(void)
{
vmbus_driver_unregister(&balloon_drv);
}
