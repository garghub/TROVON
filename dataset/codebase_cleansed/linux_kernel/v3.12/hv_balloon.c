static void hv_bring_pgs_online(unsigned long start_pfn, unsigned long size)
{
int i;
for (i = 0; i < size; i++) {
struct page *pg;
pg = pfn_to_page(start_pfn + i);
__online_page_set_limits(pg);
__online_page_increment_counters(pg);
__online_page_free(pg);
}
}
static void hv_mem_hot_add(unsigned long start, unsigned long size,
unsigned long pfn_count,
struct hv_hotadd_state *has)
{
int ret = 0;
int i, nid;
unsigned long start_pfn;
unsigned long processed_pfn;
unsigned long total_pfn = pfn_count;
for (i = 0; i < (size/HA_CHUNK); i++) {
start_pfn = start + (i * HA_CHUNK);
has->ha_end_pfn += HA_CHUNK;
if (total_pfn > HA_CHUNK) {
processed_pfn = HA_CHUNK;
total_pfn -= HA_CHUNK;
} else {
processed_pfn = total_pfn;
total_pfn = 0;
}
has->covered_end_pfn += processed_pfn;
init_completion(&dm_device.ol_waitevent);
dm_device.ha_waiting = true;
nid = memory_add_physaddr_to_nid(PFN_PHYS(start_pfn));
ret = add_memory(nid, PFN_PHYS((start_pfn)),
(HA_CHUNK << PAGE_SHIFT));
if (ret) {
pr_info("hot_add memory failed error is %d\n", ret);
if (ret == -EEXIST) {
do_hot_add = false;
}
has->ha_end_pfn -= HA_CHUNK;
has->covered_end_pfn -= processed_pfn;
break;
}
wait_for_completion_timeout(&dm_device.ol_waitevent, 5*HZ);
}
return;
}
static void hv_online_page(struct page *pg)
{
struct list_head *cur;
struct hv_hotadd_state *has;
unsigned long cur_start_pgp;
unsigned long cur_end_pgp;
if (dm_device.ha_waiting) {
dm_device.ha_waiting = false;
complete(&dm_device.ol_waitevent);
}
list_for_each(cur, &dm_device.ha_region_list) {
has = list_entry(cur, struct hv_hotadd_state, list);
cur_start_pgp = (unsigned long)
pfn_to_page(has->covered_start_pfn);
cur_end_pgp = (unsigned long)pfn_to_page(has->covered_end_pfn);
if (((unsigned long)pg >= cur_start_pgp) &&
((unsigned long)pg < cur_end_pgp)) {
__online_page_set_limits(pg);
__online_page_increment_counters(pg);
__online_page_free(pg);
has->covered_start_pfn++;
}
}
}
static bool pfn_covered(unsigned long start_pfn, unsigned long pfn_cnt)
{
struct list_head *cur;
struct hv_hotadd_state *has;
unsigned long residual, new_inc;
if (list_empty(&dm_device.ha_region_list))
return false;
list_for_each(cur, &dm_device.ha_region_list) {
has = list_entry(cur, struct hv_hotadd_state, list);
if ((start_pfn >= has->end_pfn))
continue;
if ((start_pfn + pfn_cnt) > has->end_pfn) {
residual = (start_pfn + pfn_cnt - has->end_pfn);
new_inc = (residual / HA_CHUNK) * HA_CHUNK;
if (residual % HA_CHUNK)
new_inc += HA_CHUNK;
has->end_pfn += new_inc;
}
if (has->covered_end_pfn != start_pfn) {
has->covered_end_pfn = start_pfn;
has->covered_start_pfn = start_pfn;
}
return true;
}
return false;
}
static unsigned long handle_pg_range(unsigned long pg_start,
unsigned long pg_count)
{
unsigned long start_pfn = pg_start;
unsigned long pfn_cnt = pg_count;
unsigned long size;
struct list_head *cur;
struct hv_hotadd_state *has;
unsigned long pgs_ol = 0;
unsigned long old_covered_state;
if (list_empty(&dm_device.ha_region_list))
return 0;
list_for_each(cur, &dm_device.ha_region_list) {
has = list_entry(cur, struct hv_hotadd_state, list);
if ((start_pfn >= has->end_pfn))
continue;
old_covered_state = has->covered_end_pfn;
if (start_pfn < has->ha_end_pfn) {
pgs_ol = has->ha_end_pfn - start_pfn;
if (pgs_ol > pfn_cnt)
pgs_ol = pfn_cnt;
hv_bring_pgs_online(start_pfn, pgs_ol);
has->covered_end_pfn += pgs_ol;
has->covered_start_pfn += pgs_ol;
pfn_cnt -= pgs_ol;
}
if ((has->ha_end_pfn < has->end_pfn) && (pfn_cnt > 0)) {
size = (has->end_pfn - has->ha_end_pfn);
if (pfn_cnt <= size) {
size = ((pfn_cnt / HA_CHUNK) * HA_CHUNK);
if (pfn_cnt % HA_CHUNK)
size += HA_CHUNK;
} else {
pfn_cnt = size;
}
hv_mem_hot_add(has->ha_end_pfn, size, pfn_cnt, has);
}
return has->covered_end_pfn - old_covered_state;
}
return 0;
}
static unsigned long process_hot_add(unsigned long pg_start,
unsigned long pfn_cnt,
unsigned long rg_start,
unsigned long rg_size)
{
struct hv_hotadd_state *ha_region = NULL;
if (pfn_cnt == 0)
return 0;
if (!dm_device.host_specified_ha_region)
if (pfn_covered(pg_start, pfn_cnt))
goto do_pg_range;
if (rg_size != 0) {
ha_region = kzalloc(sizeof(struct hv_hotadd_state), GFP_KERNEL);
if (!ha_region)
return 0;
INIT_LIST_HEAD(&ha_region->list);
list_add_tail(&ha_region->list, &dm_device.ha_region_list);
ha_region->start_pfn = rg_start;
ha_region->ha_end_pfn = rg_start;
ha_region->covered_start_pfn = pg_start;
ha_region->covered_end_pfn = pg_start;
ha_region->end_pfn = rg_start + rg_size;
}
do_pg_range:
return handle_pg_range(pg_start, pfn_cnt);
}
static void hot_add_req(struct work_struct *dummy)
{
struct dm_hot_add_response resp;
#ifdef CONFIG_MEMORY_HOTPLUG
unsigned long pg_start, pfn_cnt;
unsigned long rg_start, rg_sz;
#endif
struct hv_dynmem_device *dm = &dm_device;
memset(&resp, 0, sizeof(struct dm_hot_add_response));
resp.hdr.type = DM_MEM_HOT_ADD_RESPONSE;
resp.hdr.size = sizeof(struct dm_hot_add_response);
#ifdef CONFIG_MEMORY_HOTPLUG
pg_start = dm->ha_wrk.ha_page_range.finfo.start_page;
pfn_cnt = dm->ha_wrk.ha_page_range.finfo.page_cnt;
rg_start = dm->ha_wrk.ha_region_range.finfo.start_page;
rg_sz = dm->ha_wrk.ha_region_range.finfo.page_cnt;
if ((rg_start == 0) && (!dm->host_specified_ha_region)) {
unsigned long region_size;
unsigned long region_start;
region_start = pg_start;
region_size = (pfn_cnt / HA_CHUNK) * HA_CHUNK;
if (pfn_cnt % HA_CHUNK)
region_size += HA_CHUNK;
region_start = (pg_start / HA_CHUNK) * HA_CHUNK;
rg_start = region_start;
rg_sz = region_size;
}
if (do_hot_add)
resp.page_count = process_hot_add(pg_start, pfn_cnt,
rg_start, rg_sz);
#endif
if (resp.page_count > 0)
resp.result = 1;
else if (!do_hot_add)
resp.result = 1;
else
resp.result = 0;
if (!do_hot_add || (resp.page_count == 0))
pr_info("Memory hot add failed\n");
dm->state = DM_INITIALIZED;
resp.hdr.trans_id = atomic_inc_return(&trans_id);
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
static unsigned long compute_balloon_floor(void)
{
unsigned long min_pages;
#define MB2PAGES(mb) ((mb) << (20 - PAGE_SHIFT))
if (totalram_pages < MB2PAGES(128))
min_pages = MB2PAGES(8) + (totalram_pages >> 1);
else if (totalram_pages < MB2PAGES(512))
min_pages = MB2PAGES(40) + (totalram_pages >> 2);
else if (totalram_pages < MB2PAGES(2048))
min_pages = MB2PAGES(104) + (totalram_pages >> 3);
else
min_pages = MB2PAGES(296) + (totalram_pages >> 5);
#undef MB2PAGES
return min_pages;
}
static void post_status(struct hv_dynmem_device *dm)
{
struct dm_status status;
struct sysinfo val;
if (pressure_report_delay > 0) {
--pressure_report_delay;
return;
}
si_meminfo(&val);
memset(&status, 0, sizeof(struct dm_status));
status.hdr.type = DM_STATUS_REPORT;
status.hdr.size = sizeof(struct dm_status);
status.hdr.trans_id = atomic_inc_return(&trans_id);
status.num_avail = val.freeram;
status.num_committed = vm_memory_committed() +
dm->num_pages_ballooned +
compute_balloon_floor();
if (status.hdr.trans_id != atomic_read(&trans_id))
return;
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
if (alloc_unit != 1)
split_page(pg, get_order(alloc_unit << PAGE_SHIFT));
bl_resp->range_count++;
bl_resp->range_array[i].finfo.start_page =
page_to_pfn(pg);
bl_resp->range_array[i].finfo.page_cnt = alloc_unit;
bl_resp->hdr.size += sizeof(union dm_mem_page_range);
}
return num_pages;
}
static void balloon_up(struct work_struct *dummy)
{
int num_pages = dm_device.balloon_wrk.num_pages;
int num_ballooned = 0;
struct dm_balloon_response *bl_resp;
int alloc_unit;
int ret;
bool alloc_error = false;
bool done = false;
int i;
alloc_unit = 512;
while (!done) {
bl_resp = (struct dm_balloon_response *)send_buffer;
memset(send_buffer, 0, PAGE_SIZE);
bl_resp->hdr.type = DM_BALLOON_RESPONSE;
bl_resp->hdr.size = sizeof(struct dm_balloon_response);
bl_resp->more_pages = 1;
num_pages -= num_ballooned;
num_ballooned = alloc_balloon_pages(&dm_device, num_pages,
bl_resp, alloc_unit,
&alloc_error);
if ((alloc_error) && (alloc_unit != 1)) {
alloc_unit = 1;
continue;
}
if ((alloc_error) || (num_ballooned == num_pages)) {
bl_resp->more_pages = 0;
done = true;
dm_device.state = DM_INITIALIZED;
}
do {
bl_resp->hdr.trans_id = atomic_inc_return(&trans_id);
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
free_balloon_pages(&dm_device,
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
while (!kthread_should_stop()) {
t = wait_for_completion_timeout(&dm_device.config_event, 1*HZ);
if (t == 0)
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
struct dm_balloon *bal_msg;
struct dm_hot_add *ha_msg;
union dm_mem_page_range *ha_pg_range;
union dm_mem_page_range *ha_region;
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
if (dm->state == DM_BALLOON_UP)
pr_warn("Currently ballooning\n");
bal_msg = (struct dm_balloon *)recv_buffer;
dm->state = DM_BALLOON_UP;
dm_device.balloon_wrk.num_pages = bal_msg->num_pages;
schedule_work(&dm_device.balloon_wrk.wrk);
break;
case DM_UNBALLOON_REQUEST:
dm->state = DM_BALLOON_DOWN;
balloon_down(dm,
(struct dm_unballoon_request *)recv_buffer);
break;
case DM_MEM_HOT_ADD_REQUEST:
if (dm->state == DM_HOT_ADD)
pr_warn("Currently hot-adding\n");
dm->state = DM_HOT_ADD;
ha_msg = (struct dm_hot_add *)recv_buffer;
if (ha_msg->hdr.size == sizeof(struct dm_hot_add)) {
ha_pg_range = &ha_msg->range;
dm->ha_wrk.ha_page_range = *ha_pg_range;
dm->ha_wrk.ha_region_range.page_range = 0;
} else {
dm->host_specified_ha_region = true;
ha_pg_range = &ha_msg->range;
ha_region = &ha_pg_range[1];
dm->ha_wrk.ha_page_range = *ha_pg_range;
dm->ha_wrk.ha_region_range = *ha_region;
}
schedule_work(&dm_device.ha_wrk.wrk);
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
INIT_LIST_HEAD(&dm_device.ha_region_list);
INIT_WORK(&dm_device.balloon_wrk.wrk, balloon_up);
INIT_WORK(&dm_device.ha_wrk.wrk, hot_add_req);
dm_device.host_specified_ha_region = false;
dm_device.thread =
kthread_run(dm_thread_func, &dm_device, "hv_balloon");
if (IS_ERR(dm_device.thread)) {
ret = PTR_ERR(dm_device.thread);
goto probe_error1;
}
#ifdef CONFIG_MEMORY_HOTPLUG
set_online_page_callback(&hv_online_page);
#endif
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
VM_PKT_DATA_INBAND, 0);
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
cap_msg.caps.cap_bits.hot_add_alignment = 7;
cap_msg.min_page_cnt = 0;
cap_msg.max_page_number = -1;
ret = vmbus_sendpacket(dev->channel, &cap_msg,
sizeof(struct dm_capabilities),
(unsigned long)NULL,
VM_PKT_DATA_INBAND, 0);
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
#ifdef CONFIG_MEMORY_HOTPLUG
restore_online_page_callback(&hv_online_page);
#endif
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
struct list_head *cur, *tmp;
struct hv_hotadd_state *has;
if (dm->num_pages_ballooned != 0)
pr_warn("Ballooned pages: %d\n", dm->num_pages_ballooned);
cancel_work_sync(&dm->balloon_wrk.wrk);
cancel_work_sync(&dm->ha_wrk.wrk);
vmbus_close(dev->channel);
kthread_stop(dm->thread);
kfree(send_buffer);
#ifdef CONFIG_MEMORY_HOTPLUG
restore_online_page_callback(&hv_online_page);
#endif
list_for_each_safe(cur, tmp, &dm->ha_region_list) {
has = list_entry(cur, struct hv_hotadd_state, list);
list_del(&has->list);
kfree(has);
}
return 0;
}
static int __init init_balloon_drv(void)
{
return vmbus_driver_register(&balloon_drv);
}
