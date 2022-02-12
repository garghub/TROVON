static int hv_memory_notifier(struct notifier_block *nb, unsigned long val,
void *v)
{
struct memory_notify *mem = (struct memory_notify *)v;
unsigned long flags;
switch (val) {
case MEM_ONLINE:
spin_lock_irqsave(&dm_device.ha_lock, flags);
dm_device.num_pages_onlined += mem->nr_pages;
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
case MEM_CANCEL_ONLINE:
if (dm_device.ha_waiting) {
dm_device.ha_waiting = false;
complete(&dm_device.ol_waitevent);
}
break;
case MEM_OFFLINE:
spin_lock_irqsave(&dm_device.ha_lock, flags);
dm_device.num_pages_onlined -= mem->nr_pages;
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
break;
case MEM_GOING_ONLINE:
case MEM_GOING_OFFLINE:
case MEM_CANCEL_OFFLINE:
break;
}
return NOTIFY_OK;
}
static void hv_page_online_one(struct hv_hotadd_state *has, struct page *pg)
{
unsigned long cur_start_pgp;
unsigned long cur_end_pgp;
struct hv_hotadd_gap *gap;
cur_start_pgp = (unsigned long)pfn_to_page(has->covered_start_pfn);
cur_end_pgp = (unsigned long)pfn_to_page(has->covered_end_pfn);
if (((unsigned long)pg < cur_start_pgp) ||
((unsigned long)pg >= cur_end_pgp))
return;
list_for_each_entry(gap, &has->gap_list, list) {
cur_start_pgp = (unsigned long)
pfn_to_page(gap->start_pfn);
cur_end_pgp = (unsigned long)
pfn_to_page(gap->end_pfn);
if (((unsigned long)pg >= cur_start_pgp) &&
((unsigned long)pg < cur_end_pgp)) {
return;
}
}
__online_page_set_limits(pg);
__online_page_increment_counters(pg);
__online_page_free(pg);
}
static void hv_bring_pgs_online(struct hv_hotadd_state *has,
unsigned long start_pfn, unsigned long size)
{
int i;
pr_debug("Online %lu pages starting at pfn 0x%lx\n", size, start_pfn);
for (i = 0; i < size; i++)
hv_page_online_one(has, pfn_to_page(start_pfn + i));
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
unsigned long flags;
for (i = 0; i < (size/HA_CHUNK); i++) {
start_pfn = start + (i * HA_CHUNK);
spin_lock_irqsave(&dm_device.ha_lock, flags);
has->ha_end_pfn += HA_CHUNK;
if (total_pfn > HA_CHUNK) {
processed_pfn = HA_CHUNK;
total_pfn -= HA_CHUNK;
} else {
processed_pfn = total_pfn;
total_pfn = 0;
}
has->covered_end_pfn += processed_pfn;
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
init_completion(&dm_device.ol_waitevent);
dm_device.ha_waiting = !memhp_auto_online;
nid = memory_add_physaddr_to_nid(PFN_PHYS(start_pfn));
ret = add_memory(nid, PFN_PHYS((start_pfn)),
(HA_CHUNK << PAGE_SHIFT));
if (ret) {
pr_warn("hot_add memory failed error is %d\n", ret);
if (ret == -EEXIST) {
do_hot_add = false;
}
spin_lock_irqsave(&dm_device.ha_lock, flags);
has->ha_end_pfn -= HA_CHUNK;
has->covered_end_pfn -= processed_pfn;
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
break;
}
if (dm_device.ha_waiting)
wait_for_completion_timeout(&dm_device.ol_waitevent,
5*HZ);
post_status(&dm_device);
}
}
static void hv_online_page(struct page *pg)
{
struct hv_hotadd_state *has;
unsigned long cur_start_pgp;
unsigned long cur_end_pgp;
unsigned long flags;
spin_lock_irqsave(&dm_device.ha_lock, flags);
list_for_each_entry(has, &dm_device.ha_region_list, list) {
cur_start_pgp = (unsigned long)
pfn_to_page(has->start_pfn);
cur_end_pgp = (unsigned long)pfn_to_page(has->end_pfn);
if (((unsigned long)pg < cur_start_pgp) ||
((unsigned long)pg >= cur_end_pgp))
continue;
hv_page_online_one(has, pg);
break;
}
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
}
static int pfn_covered(unsigned long start_pfn, unsigned long pfn_cnt)
{
struct hv_hotadd_state *has;
struct hv_hotadd_gap *gap;
unsigned long residual, new_inc;
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&dm_device.ha_lock, flags);
list_for_each_entry(has, &dm_device.ha_region_list, list) {
if (start_pfn < has->start_pfn || start_pfn >= has->end_pfn)
continue;
if (has->covered_end_pfn != start_pfn) {
gap = kzalloc(sizeof(struct hv_hotadd_gap), GFP_ATOMIC);
if (!gap) {
ret = -ENOMEM;
break;
}
INIT_LIST_HEAD(&gap->list);
gap->start_pfn = has->covered_end_pfn;
gap->end_pfn = start_pfn;
list_add_tail(&gap->list, &has->gap_list);
has->covered_end_pfn = start_pfn;
}
if ((start_pfn + pfn_cnt) > has->end_pfn) {
residual = (start_pfn + pfn_cnt - has->end_pfn);
new_inc = (residual / HA_CHUNK) * HA_CHUNK;
if (residual % HA_CHUNK)
new_inc += HA_CHUNK;
has->end_pfn += new_inc;
}
ret = 1;
break;
}
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
return ret;
}
static unsigned long handle_pg_range(unsigned long pg_start,
unsigned long pg_count)
{
unsigned long start_pfn = pg_start;
unsigned long pfn_cnt = pg_count;
unsigned long size;
struct hv_hotadd_state *has;
unsigned long pgs_ol = 0;
unsigned long old_covered_state;
unsigned long res = 0, flags;
pr_debug("Hot adding %lu pages starting at pfn 0x%lx.\n", pg_count,
pg_start);
spin_lock_irqsave(&dm_device.ha_lock, flags);
list_for_each_entry(has, &dm_device.ha_region_list, list) {
if (start_pfn < has->start_pfn || start_pfn >= has->end_pfn)
continue;
old_covered_state = has->covered_end_pfn;
if (start_pfn < has->ha_end_pfn) {
pgs_ol = has->ha_end_pfn - start_pfn;
if (pgs_ol > pfn_cnt)
pgs_ol = pfn_cnt;
has->covered_end_pfn += pgs_ol;
pfn_cnt -= pgs_ol;
if (start_pfn > has->start_pfn &&
!PageReserved(pfn_to_page(start_pfn - 1)))
hv_bring_pgs_online(has, start_pfn, pgs_ol);
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
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
hv_mem_hot_add(has->ha_end_pfn, size, pfn_cnt, has);
spin_lock_irqsave(&dm_device.ha_lock, flags);
}
res = has->covered_end_pfn - old_covered_state;
break;
}
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
return res;
}
static unsigned long process_hot_add(unsigned long pg_start,
unsigned long pfn_cnt,
unsigned long rg_start,
unsigned long rg_size)
{
struct hv_hotadd_state *ha_region = NULL;
int covered;
unsigned long flags;
if (pfn_cnt == 0)
return 0;
if (!dm_device.host_specified_ha_region) {
covered = pfn_covered(pg_start, pfn_cnt);
if (covered < 0)
return 0;
if (covered)
goto do_pg_range;
}
if (rg_size != 0) {
ha_region = kzalloc(sizeof(struct hv_hotadd_state), GFP_KERNEL);
if (!ha_region)
return 0;
INIT_LIST_HEAD(&ha_region->list);
INIT_LIST_HEAD(&ha_region->gap_list);
ha_region->start_pfn = rg_start;
ha_region->ha_end_pfn = rg_start;
ha_region->covered_start_pfn = pg_start;
ha_region->covered_end_pfn = pg_start;
ha_region->end_pfn = rg_start + rg_size;
spin_lock_irqsave(&dm_device.ha_lock, flags);
list_add_tail(&ha_region->list, &dm_device.ha_region_list);
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
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
dm->num_pages_added += resp.page_count;
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
if (info_hdr->data_size == sizeof(__u64)) {
__u64 *max_page_count = (__u64 *)&info_hdr[1];
pr_info("INFO_TYPE_MAX_PAGE_CNT = %llu\n",
*max_page_count);
}
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
else if (totalram_pages < MB2PAGES(8192))
min_pages = MB2PAGES(232) + (totalram_pages >> 4);
else
min_pages = MB2PAGES(488) + (totalram_pages >> 5);
#undef MB2PAGES
return min_pages;
}
static void post_status(struct hv_dynmem_device *dm)
{
struct dm_status status;
unsigned long now = jiffies;
unsigned long last_post = last_post_time;
if (pressure_report_delay > 0) {
--pressure_report_delay;
return;
}
if (!time_after(now, (last_post_time + HZ)))
return;
memset(&status, 0, sizeof(struct dm_status));
status.hdr.type = DM_STATUS_REPORT;
status.hdr.size = sizeof(struct dm_status);
status.hdr.trans_id = atomic_inc_return(&trans_id);
status.num_avail = si_mem_available();
status.num_committed = vm_memory_committed() +
dm->num_pages_ballooned +
(dm->num_pages_added > dm->num_pages_onlined ?
dm->num_pages_added - dm->num_pages_onlined : 0) +
compute_balloon_floor();
if (status.hdr.trans_id != atomic_read(&trans_id))
return;
if (last_post != last_post_time)
return;
last_post_time = jiffies;
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
static unsigned int alloc_balloon_pages(struct hv_dynmem_device *dm,
unsigned int num_pages,
struct dm_balloon_response *bl_resp,
int alloc_unit)
{
unsigned int i = 0;
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
if (!pg)
return i * alloc_unit;
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
unsigned int num_pages = dm_device.balloon_wrk.num_pages;
unsigned int num_ballooned = 0;
struct dm_balloon_response *bl_resp;
int alloc_unit;
int ret;
bool done = false;
int i;
long avail_pages;
unsigned long floor;
WARN_ON_ONCE(num_pages % PAGES_IN_2M != 0);
alloc_unit = 512;
avail_pages = si_mem_available();
floor = compute_balloon_floor();
if (avail_pages < num_pages || avail_pages - num_pages < floor) {
pr_warn("Balloon request will be partially fulfilled. %s\n",
avail_pages < num_pages ? "Not enough memory." :
"Balloon floor reached.");
num_pages = avail_pages > floor ? (avail_pages - floor) : 0;
num_pages -= num_pages % PAGES_IN_2M;
}
while (!done) {
bl_resp = (struct dm_balloon_response *)send_buffer;
memset(send_buffer, 0, PAGE_SIZE);
bl_resp->hdr.type = DM_BALLOON_RESPONSE;
bl_resp->hdr.size = sizeof(struct dm_balloon_response);
bl_resp->more_pages = 1;
num_pages -= num_ballooned;
num_ballooned = alloc_balloon_pages(&dm_device, num_pages,
bl_resp, alloc_unit);
if (alloc_unit != 1 && num_ballooned == 0) {
alloc_unit = 1;
continue;
}
if (num_ballooned == 0 || num_ballooned == num_pages) {
pr_debug("Ballooned %u out of %u requested pages.\n",
num_pages, dm_device.balloon_wrk.num_pages);
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
post_status(&dm_device);
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
unsigned int prev_pages_ballooned = dm->num_pages_ballooned;
for (i = 0; i < range_count; i++) {
free_balloon_pages(dm, &range_array[i]);
complete(&dm_device.config_event);
}
pr_debug("Freed %u ballooned pages.\n",
prev_pages_ballooned - dm->num_pages_ballooned);
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
while (!kthread_should_stop()) {
wait_for_completion_interruptible_timeout(
&dm_device.config_event, 1*HZ);
reinit_completion(&dm_device.config_event);
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
memset(&version_req, 0, sizeof(struct dm_version_request));
version_req.hdr.type = DM_VERSION_REQUEST;
version_req.hdr.size = sizeof(struct dm_version_request);
version_req.hdr.trans_id = atomic_inc_return(&trans_id);
version_req.version.version = dm->next_version;
dm->version = version_req.version.version;
switch (version_req.version.version) {
case DYNMEM_PROTOCOL_VERSION_WIN8:
dm->next_version = DYNMEM_PROTOCOL_VERSION_WIN7;
version_req.is_last_attempt = 0;
break;
default:
dm->next_version = 0;
version_req.is_last_attempt = 1;
}
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
dm->host_specified_ha_region = false;
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
int ret;
unsigned long t;
struct dm_version_request version_req;
struct dm_capabilities cap_msg;
#ifdef CONFIG_MEMORY_HOTPLUG
do_hot_add = hot_add;
#else
do_hot_add = false;
#endif
send_buffer = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!send_buffer)
return -ENOMEM;
ret = vmbus_open(dev->channel, dm_ring_size, dm_ring_size, NULL, 0,
balloon_onchannelcallback, dev);
if (ret)
goto probe_error0;
dm_device.dev = dev;
dm_device.state = DM_INITIALIZING;
dm_device.next_version = DYNMEM_PROTOCOL_VERSION_WIN8;
init_completion(&dm_device.host_event);
init_completion(&dm_device.config_event);
INIT_LIST_HEAD(&dm_device.ha_region_list);
spin_lock_init(&dm_device.ha_lock);
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
register_memory_notifier(&hv_memory_nb);
#endif
hv_set_drvdata(dev, &dm_device);
memset(&version_req, 0, sizeof(struct dm_version_request));
version_req.hdr.type = DM_VERSION_REQUEST;
version_req.hdr.size = sizeof(struct dm_version_request);
version_req.hdr.trans_id = atomic_inc_return(&trans_id);
version_req.version.version = DYNMEM_PROTOCOL_VERSION_WIN10;
version_req.is_last_attempt = 0;
dm_device.version = version_req.version.version;
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
pr_info("Using Dynamic Memory protocol version %u.%u\n",
DYNMEM_MAJOR_VERSION(dm_device.version),
DYNMEM_MINOR_VERSION(dm_device.version));
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
struct hv_hotadd_state *has, *tmp;
struct hv_hotadd_gap *gap, *tmp_gap;
unsigned long flags;
if (dm->num_pages_ballooned != 0)
pr_warn("Ballooned pages: %d\n", dm->num_pages_ballooned);
cancel_work_sync(&dm->balloon_wrk.wrk);
cancel_work_sync(&dm->ha_wrk.wrk);
vmbus_close(dev->channel);
kthread_stop(dm->thread);
kfree(send_buffer);
#ifdef CONFIG_MEMORY_HOTPLUG
restore_online_page_callback(&hv_online_page);
unregister_memory_notifier(&hv_memory_nb);
#endif
spin_lock_irqsave(&dm_device.ha_lock, flags);
list_for_each_entry_safe(has, tmp, &dm->ha_region_list, list) {
list_for_each_entry_safe(gap, tmp_gap, &has->gap_list, list) {
list_del(&gap->list);
kfree(gap);
}
list_del(&has->list);
kfree(has);
}
spin_unlock_irqrestore(&dm_device.ha_lock, flags);
return 0;
}
static int __init init_balloon_drv(void)
{
return vmbus_driver_register(&balloon_drv);
}
