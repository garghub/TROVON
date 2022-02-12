static void storvsc_device_scan(struct work_struct *work)
{
struct storvsc_scan_work *wrk;
uint lun;
struct scsi_device *sdev;
wrk = container_of(work, struct storvsc_scan_work, work);
lun = wrk->lun;
sdev = scsi_device_lookup(wrk->host, 0, 0, lun);
if (!sdev)
goto done;
scsi_rescan_device(&sdev->sdev_gendev);
scsi_device_put(sdev);
done:
kfree(wrk);
}
static void storvsc_bus_scan(struct work_struct *work)
{
struct storvsc_scan_work *wrk;
int id, order_id;
wrk = container_of(work, struct storvsc_scan_work, work);
for (id = 0; id < wrk->host->max_id; ++id) {
if (wrk->host->reverse_ordering)
order_id = wrk->host->max_id - id - 1;
else
order_id = id;
scsi_scan_target(&wrk->host->shost_gendev, 0,
order_id, SCAN_WILD_CARD, 1);
}
kfree(wrk);
}
static void storvsc_remove_lun(struct work_struct *work)
{
struct storvsc_scan_work *wrk;
struct scsi_device *sdev;
wrk = container_of(work, struct storvsc_scan_work, work);
if (!scsi_host_get(wrk->host))
goto done;
sdev = scsi_device_lookup(wrk->host, 0, 0, wrk->lun);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
}
scsi_host_put(wrk->host);
done:
kfree(wrk);
}
static inline u16 storvsc_get_version(u8 major, u8 minor)
{
u16 version;
version = ((major << 8) | minor);
return version;
}
static inline struct storvsc_device *get_out_stor_device(
struct hv_device *device)
{
struct storvsc_device *stor_device;
stor_device = hv_get_drvdata(device);
if (stor_device && stor_device->destroy)
stor_device = NULL;
return stor_device;
}
static inline void storvsc_wait_to_drain(struct storvsc_device *dev)
{
dev->drain_notify = true;
wait_event(dev->waiting_to_drain,
atomic_read(&dev->num_outstanding_req) == 0);
dev->drain_notify = false;
}
static inline struct storvsc_device *get_in_stor_device(
struct hv_device *device)
{
struct storvsc_device *stor_device;
stor_device = hv_get_drvdata(device);
if (!stor_device)
goto get_in_err;
if (stor_device->destroy &&
(atomic_read(&stor_device->num_outstanding_req) == 0))
stor_device = NULL;
get_in_err:
return stor_device;
}
static void destroy_bounce_buffer(struct scatterlist *sgl,
unsigned int sg_count)
{
int i;
struct page *page_buf;
for (i = 0; i < sg_count; i++) {
page_buf = sg_page((&sgl[i]));
if (page_buf != NULL)
__free_page(page_buf);
}
kfree(sgl);
}
static int do_bounce_buffer(struct scatterlist *sgl, unsigned int sg_count)
{
int i;
if (sg_count < 2)
return -1;
for (i = 0; i < sg_count; i++) {
if (i == 0) {
if (sgl[i].offset + sgl[i].length != PAGE_SIZE)
return i;
} else if (i == sg_count - 1) {
if (sgl[i].offset != 0)
return i;
} else {
if (sgl[i].length != PAGE_SIZE || sgl[i].offset != 0)
return i;
}
}
return -1;
}
static struct scatterlist *create_bounce_buffer(struct scatterlist *sgl,
unsigned int sg_count,
unsigned int len,
int write)
{
int i;
int num_pages;
struct scatterlist *bounce_sgl;
struct page *page_buf;
unsigned int buf_len = ((write == WRITE_TYPE) ? 0 : PAGE_SIZE);
num_pages = ALIGN(len, PAGE_SIZE) >> PAGE_SHIFT;
bounce_sgl = kcalloc(num_pages, sizeof(struct scatterlist), GFP_ATOMIC);
if (!bounce_sgl)
return NULL;
sg_init_table(bounce_sgl, num_pages);
for (i = 0; i < num_pages; i++) {
page_buf = alloc_page(GFP_ATOMIC);
if (!page_buf)
goto cleanup;
sg_set_page(&bounce_sgl[i], page_buf, buf_len, 0);
}
return bounce_sgl;
cleanup:
destroy_bounce_buffer(bounce_sgl, num_pages);
return NULL;
}
static inline unsigned long sg_kmap_atomic(struct scatterlist *sgl, int idx)
{
void *addr = kmap_atomic(sg_page(sgl + idx));
return (unsigned long)addr;
}
static inline void sg_kunmap_atomic(unsigned long addr)
{
kunmap_atomic((void *)addr);
}
static unsigned int copy_from_bounce_buffer(struct scatterlist *orig_sgl,
struct scatterlist *bounce_sgl,
unsigned int orig_sgl_count,
unsigned int bounce_sgl_count)
{
int i;
int j = 0;
unsigned long src, dest;
unsigned int srclen, destlen, copylen;
unsigned int total_copied = 0;
unsigned long bounce_addr = 0;
unsigned long dest_addr = 0;
unsigned long flags;
local_irq_save(flags);
for (i = 0; i < orig_sgl_count; i++) {
dest_addr = sg_kmap_atomic(orig_sgl,i) + orig_sgl[i].offset;
dest = dest_addr;
destlen = orig_sgl[i].length;
if (bounce_addr == 0)
bounce_addr = sg_kmap_atomic(bounce_sgl,j);
while (destlen) {
src = bounce_addr + bounce_sgl[j].offset;
srclen = bounce_sgl[j].length - bounce_sgl[j].offset;
copylen = min(srclen, destlen);
memcpy((void *)dest, (void *)src, copylen);
total_copied += copylen;
bounce_sgl[j].offset += copylen;
destlen -= copylen;
dest += copylen;
if (bounce_sgl[j].offset == bounce_sgl[j].length) {
sg_kunmap_atomic(bounce_addr);
j++;
if (j == bounce_sgl_count) {
sg_kunmap_atomic(dest_addr - orig_sgl[i].offset);
local_irq_restore(flags);
return total_copied;
}
if (destlen || i != orig_sgl_count - 1)
bounce_addr = sg_kmap_atomic(bounce_sgl,j);
} else if (destlen == 0 && i == orig_sgl_count - 1) {
sg_kunmap_atomic(bounce_addr);
}
}
sg_kunmap_atomic(dest_addr - orig_sgl[i].offset);
}
local_irq_restore(flags);
return total_copied;
}
static unsigned int copy_to_bounce_buffer(struct scatterlist *orig_sgl,
struct scatterlist *bounce_sgl,
unsigned int orig_sgl_count)
{
int i;
int j = 0;
unsigned long src, dest;
unsigned int srclen, destlen, copylen;
unsigned int total_copied = 0;
unsigned long bounce_addr = 0;
unsigned long src_addr = 0;
unsigned long flags;
local_irq_save(flags);
for (i = 0; i < orig_sgl_count; i++) {
src_addr = sg_kmap_atomic(orig_sgl,i) + orig_sgl[i].offset;
src = src_addr;
srclen = orig_sgl[i].length;
if (bounce_addr == 0)
bounce_addr = sg_kmap_atomic(bounce_sgl,j);
while (srclen) {
dest = bounce_addr + bounce_sgl[j].length;
destlen = PAGE_SIZE - bounce_sgl[j].length;
copylen = min(srclen, destlen);
memcpy((void *)dest, (void *)src, copylen);
total_copied += copylen;
bounce_sgl[j].length += copylen;
srclen -= copylen;
src += copylen;
if (bounce_sgl[j].length == PAGE_SIZE) {
sg_kunmap_atomic(bounce_addr);
j++;
if (srclen || i != orig_sgl_count - 1)
bounce_addr = sg_kmap_atomic(bounce_sgl,j);
} else if (srclen == 0 && i == orig_sgl_count - 1) {
sg_kunmap_atomic(bounce_addr);
}
}
sg_kunmap_atomic(src_addr - orig_sgl[i].offset);
}
local_irq_restore(flags);
return total_copied;
}
static void handle_sc_creation(struct vmbus_channel *new_sc)
{
struct hv_device *device = new_sc->primary_channel->device_obj;
struct storvsc_device *stor_device;
struct vmstorage_channel_properties props;
stor_device = get_out_stor_device(device);
if (!stor_device)
return;
if (stor_device->open_sub_channel == false)
return;
memset(&props, 0, sizeof(struct vmstorage_channel_properties));
vmbus_open(new_sc,
storvsc_ringbuffer_size,
storvsc_ringbuffer_size,
(void *)&props,
sizeof(struct vmstorage_channel_properties),
storvsc_on_channel_callback, new_sc);
}
static void handle_multichannel_storage(struct hv_device *device, int max_chns)
{
struct storvsc_device *stor_device;
int num_cpus = num_online_cpus();
int num_sc;
struct storvsc_cmd_request *request;
struct vstor_packet *vstor_packet;
int ret, t;
num_sc = ((max_chns > num_cpus) ? num_cpus : max_chns);
stor_device = get_out_stor_device(device);
if (!stor_device)
return;
request = &stor_device->init_request;
vstor_packet = &request->vstor_packet;
stor_device->open_sub_channel = true;
vmbus_set_sc_create_callback(device->channel, handle_sc_creation);
if (vmbus_are_subchannels_present(device->channel))
return;
stor_device->open_sub_channel = false;
memset(request, 0, sizeof(struct storvsc_cmd_request));
init_completion(&request->wait_event);
vstor_packet->operation = VSTOR_OPERATION_CREATE_SUB_CHANNELS;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
vstor_packet->sub_channel_count = num_sc;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
return;
t = wait_for_completion_timeout(&request->wait_event, 10*HZ);
if (t == 0)
return;
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO ||
vstor_packet->status != 0)
return;
stor_device->open_sub_channel = true;
vmbus_are_subchannels_present(device->channel);
}
static int storvsc_channel_init(struct hv_device *device)
{
struct storvsc_device *stor_device;
struct storvsc_cmd_request *request;
struct vstor_packet *vstor_packet;
int ret, t;
int max_chns;
bool process_sub_channels = false;
stor_device = get_out_stor_device(device);
if (!stor_device)
return -ENODEV;
request = &stor_device->init_request;
vstor_packet = &request->vstor_packet;
memset(request, 0, sizeof(struct storvsc_cmd_request));
init_completion(&request->wait_event);
vstor_packet->operation = VSTOR_OPERATION_BEGIN_INITIALIZATION;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
goto cleanup;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO ||
vstor_packet->status != 0)
goto cleanup;
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_QUERY_PROTOCOL_VERSION;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
vstor_packet->version.major_minor =
storvsc_get_version(vmstor_current_major, vmstor_current_minor);
vstor_packet->version.revision = 0;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
goto cleanup;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO ||
vstor_packet->status != 0)
goto cleanup;
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_QUERY_PROPERTIES;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
goto cleanup;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO ||
vstor_packet->status != 0)
goto cleanup;
max_chns = vstor_packet->storage_channel_properties.max_channel_cnt;
if ((vmbus_proto_version != VERSION_WIN7) &&
(vmbus_proto_version != VERSION_WS2008)) {
if (vstor_packet->storage_channel_properties.flags &
STORAGE_CHANNEL_SUPPORTS_MULTI_CHANNEL)
process_sub_channels = true;
}
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_END_INITIALIZATION;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
goto cleanup;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO ||
vstor_packet->status != 0)
goto cleanup;
if (process_sub_channels)
handle_multichannel_storage(device, max_chns);
cleanup:
return ret;
}
static void storvsc_handle_error(struct vmscsi_request *vm_srb,
struct scsi_cmnd *scmnd,
struct Scsi_Host *host,
u8 asc, u8 ascq)
{
struct storvsc_scan_work *wrk;
void (*process_err_fn)(struct work_struct *work);
bool do_work = false;
switch (vm_srb->srb_status) {
case SRB_STATUS_ERROR:
switch (scmnd->cmnd[0]) {
case ATA_16:
case ATA_12:
set_host_byte(scmnd, DID_PASSTHROUGH);
break;
default:
set_host_byte(scmnd, DID_TARGET_FAILURE);
}
break;
case SRB_STATUS_INVALID_LUN:
do_work = true;
process_err_fn = storvsc_remove_lun;
break;
case (SRB_STATUS_ABORTED | SRB_STATUS_AUTOSENSE_VALID):
if ((asc == 0x2a) && (ascq == 0x9)) {
do_work = true;
process_err_fn = storvsc_device_scan;
set_host_byte(scmnd, DID_REQUEUE);
}
break;
}
if (!do_work)
return;
wrk = kmalloc(sizeof(struct storvsc_scan_work), GFP_ATOMIC);
if (!wrk) {
set_host_byte(scmnd, DID_TARGET_FAILURE);
return;
}
wrk->host = host;
wrk->lun = vm_srb->lun;
INIT_WORK(&wrk->work, process_err_fn);
schedule_work(&wrk->work);
}
static void storvsc_command_completion(struct storvsc_cmd_request *cmd_request)
{
struct scsi_cmnd *scmnd = cmd_request->cmd;
struct hv_host_device *host_dev = shost_priv(scmnd->device->host);
void (*scsi_done_fn)(struct scsi_cmnd *);
struct scsi_sense_hdr sense_hdr;
struct vmscsi_request *vm_srb;
struct stor_mem_pools *memp = scmnd->device->hostdata;
struct Scsi_Host *host;
struct storvsc_device *stor_dev;
struct hv_device *dev = host_dev->dev;
stor_dev = get_in_stor_device(dev);
host = stor_dev->host;
vm_srb = &cmd_request->vstor_packet.vm_srb;
if (cmd_request->bounce_sgl_count) {
if (vm_srb->data_in == READ_TYPE)
copy_from_bounce_buffer(scsi_sglist(scmnd),
cmd_request->bounce_sgl,
scsi_sg_count(scmnd),
cmd_request->bounce_sgl_count);
destroy_bounce_buffer(cmd_request->bounce_sgl,
cmd_request->bounce_sgl_count);
}
scmnd->result = vm_srb->scsi_status;
if (scmnd->result) {
if (scsi_normalize_sense(scmnd->sense_buffer,
SCSI_SENSE_BUFFERSIZE, &sense_hdr))
scsi_print_sense_hdr("storvsc", &sense_hdr);
}
if (vm_srb->srb_status != SRB_STATUS_SUCCESS)
storvsc_handle_error(vm_srb, scmnd, host, sense_hdr.asc,
sense_hdr.ascq);
scsi_set_resid(scmnd,
cmd_request->data_buffer.len -
vm_srb->data_transfer_length);
scsi_done_fn = scmnd->scsi_done;
scmnd->host_scribble = NULL;
scmnd->scsi_done = NULL;
scsi_done_fn(scmnd);
mempool_free(cmd_request, memp->request_mempool);
}
static void storvsc_on_io_completion(struct hv_device *device,
struct vstor_packet *vstor_packet,
struct storvsc_cmd_request *request)
{
struct storvsc_device *stor_device;
struct vstor_packet *stor_pkt;
stor_device = hv_get_drvdata(device);
stor_pkt = &request->vstor_packet;
if ((stor_pkt->vm_srb.cdb[0] == INQUIRY) ||
(stor_pkt->vm_srb.cdb[0] == MODE_SENSE)) {
vstor_packet->vm_srb.scsi_status = 0;
vstor_packet->vm_srb.srb_status = SRB_STATUS_SUCCESS;
}
stor_pkt->vm_srb.scsi_status = vstor_packet->vm_srb.scsi_status;
stor_pkt->vm_srb.srb_status = vstor_packet->vm_srb.srb_status;
stor_pkt->vm_srb.sense_info_length =
vstor_packet->vm_srb.sense_info_length;
if (vstor_packet->vm_srb.scsi_status != 0 ||
vstor_packet->vm_srb.srb_status != SRB_STATUS_SUCCESS){
dev_warn(&device->device,
"cmd 0x%x scsi status 0x%x srb status 0x%x\n",
stor_pkt->vm_srb.cdb[0],
vstor_packet->vm_srb.scsi_status,
vstor_packet->vm_srb.srb_status);
}
if ((vstor_packet->vm_srb.scsi_status & 0xFF) == 0x02) {
if (vstor_packet->vm_srb.srb_status &
SRB_STATUS_AUTOSENSE_VALID) {
dev_warn(&device->device,
"stor pkt %p autosense data valid - len %d\n",
request,
vstor_packet->vm_srb.sense_info_length);
memcpy(request->sense_buffer,
vstor_packet->vm_srb.sense_data,
vstor_packet->vm_srb.sense_info_length);
}
}
stor_pkt->vm_srb.data_transfer_length =
vstor_packet->vm_srb.data_transfer_length;
storvsc_command_completion(request);
if (atomic_dec_and_test(&stor_device->num_outstanding_req) &&
stor_device->drain_notify)
wake_up(&stor_device->waiting_to_drain);
}
static void storvsc_on_receive(struct hv_device *device,
struct vstor_packet *vstor_packet,
struct storvsc_cmd_request *request)
{
struct storvsc_scan_work *work;
struct storvsc_device *stor_device;
switch (vstor_packet->operation) {
case VSTOR_OPERATION_COMPLETE_IO:
storvsc_on_io_completion(device, vstor_packet, request);
break;
case VSTOR_OPERATION_REMOVE_DEVICE:
case VSTOR_OPERATION_ENUMERATE_BUS:
stor_device = get_in_stor_device(device);
work = kmalloc(sizeof(struct storvsc_scan_work), GFP_ATOMIC);
if (!work)
return;
INIT_WORK(&work->work, storvsc_bus_scan);
work->host = stor_device->host;
schedule_work(&work->work);
break;
default:
break;
}
}
static void storvsc_on_channel_callback(void *context)
{
struct vmbus_channel *channel = (struct vmbus_channel *)context;
struct hv_device *device;
struct storvsc_device *stor_device;
u32 bytes_recvd;
u64 request_id;
unsigned char packet[ALIGN(sizeof(struct vstor_packet), 8)];
struct storvsc_cmd_request *request;
int ret;
if (channel->primary_channel != NULL)
device = channel->primary_channel->device_obj;
else
device = channel->device_obj;
stor_device = get_in_stor_device(device);
if (!stor_device)
return;
do {
ret = vmbus_recvpacket(channel, packet,
ALIGN((sizeof(struct vstor_packet) -
vmscsi_size_delta), 8),
&bytes_recvd, &request_id);
if (ret == 0 && bytes_recvd > 0) {
request = (struct storvsc_cmd_request *)
(unsigned long)request_id;
if ((request == &stor_device->init_request) ||
(request == &stor_device->reset_request)) {
memcpy(&request->vstor_packet, packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta));
complete(&request->wait_event);
} else {
storvsc_on_receive(device,
(struct vstor_packet *)packet,
request);
}
} else {
break;
}
} while (1);
return;
}
static int storvsc_connect_to_vsp(struct hv_device *device, u32 ring_size)
{
struct vmstorage_channel_properties props;
int ret;
memset(&props, 0, sizeof(struct vmstorage_channel_properties));
ret = vmbus_open(device->channel,
ring_size,
ring_size,
(void *)&props,
sizeof(struct vmstorage_channel_properties),
storvsc_on_channel_callback, device->channel);
if (ret != 0)
return ret;
ret = storvsc_channel_init(device);
return ret;
}
static int storvsc_dev_remove(struct hv_device *device)
{
struct storvsc_device *stor_device;
unsigned long flags;
stor_device = hv_get_drvdata(device);
spin_lock_irqsave(&device->channel->inbound_lock, flags);
stor_device->destroy = true;
spin_unlock_irqrestore(&device->channel->inbound_lock, flags);
storvsc_wait_to_drain(stor_device);
spin_lock_irqsave(&device->channel->inbound_lock, flags);
hv_set_drvdata(device, NULL);
spin_unlock_irqrestore(&device->channel->inbound_lock, flags);
vmbus_close(device->channel);
kfree(stor_device);
return 0;
}
static int storvsc_do_io(struct hv_device *device,
struct storvsc_cmd_request *request)
{
struct storvsc_device *stor_device;
struct vstor_packet *vstor_packet;
struct vmbus_channel *outgoing_channel;
int ret = 0;
vstor_packet = &request->vstor_packet;
stor_device = get_out_stor_device(device);
if (!stor_device)
return -ENODEV;
request->device = device;
outgoing_channel = vmbus_get_outgoing_channel(device->channel);
vstor_packet->flags |= REQUEST_COMPLETION_FLAG;
vstor_packet->vm_srb.length = (sizeof(struct vmscsi_request) -
vmscsi_size_delta);
vstor_packet->vm_srb.sense_info_length = sense_buffer_size;
vstor_packet->vm_srb.data_transfer_length =
request->data_buffer.len;
vstor_packet->operation = VSTOR_OPERATION_EXECUTE_SRB;
if (request->data_buffer.len) {
ret = vmbus_sendpacket_multipagebuffer(outgoing_channel,
&request->data_buffer,
vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request);
} else {
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
}
if (ret != 0)
return ret;
atomic_inc(&stor_device->num_outstanding_req);
return ret;
}
static int storvsc_device_alloc(struct scsi_device *sdevice)
{
struct stor_mem_pools *memp;
int number = STORVSC_MIN_BUF_NR;
memp = kzalloc(sizeof(struct stor_mem_pools), GFP_KERNEL);
if (!memp)
return -ENOMEM;
memp->request_pool =
kmem_cache_create(dev_name(&sdevice->sdev_dev),
sizeof(struct storvsc_cmd_request), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!memp->request_pool)
goto err0;
memp->request_mempool = mempool_create(number, mempool_alloc_slab,
mempool_free_slab,
memp->request_pool);
if (!memp->request_mempool)
goto err1;
sdevice->hostdata = memp;
return 0;
err1:
kmem_cache_destroy(memp->request_pool);
err0:
kfree(memp);
return -ENOMEM;
}
static void storvsc_device_destroy(struct scsi_device *sdevice)
{
struct stor_mem_pools *memp = sdevice->hostdata;
if (!memp)
return;
mempool_destroy(memp->request_mempool);
kmem_cache_destroy(memp->request_pool);
kfree(memp);
sdevice->hostdata = NULL;
}
static int storvsc_device_configure(struct scsi_device *sdevice)
{
scsi_adjust_queue_depth(sdevice, MSG_SIMPLE_TAG,
STORVSC_MAX_IO_REQUESTS);
blk_queue_max_segment_size(sdevice->request_queue, PAGE_SIZE);
blk_queue_bounce_limit(sdevice->request_queue, BLK_BOUNCE_ANY);
blk_queue_rq_timeout(sdevice->request_queue, (storvsc_timeout * HZ));
sdevice->no_write_same = 1;
return 0;
}
static int storvsc_get_chs(struct scsi_device *sdev, struct block_device * bdev,
sector_t capacity, int *info)
{
sector_t nsect = capacity;
sector_t cylinders = nsect;
int heads, sectors_pt;
heads = 0xff;
sectors_pt = 0x3f;
sector_div(cylinders, heads * sectors_pt);
if ((sector_t)(cylinders + 1) * heads * sectors_pt < nsect)
cylinders = 0xffff;
info[0] = heads;
info[1] = sectors_pt;
info[2] = (int)cylinders;
return 0;
}
static int storvsc_host_reset_handler(struct scsi_cmnd *scmnd)
{
struct hv_host_device *host_dev = shost_priv(scmnd->device->host);
struct hv_device *device = host_dev->dev;
struct storvsc_device *stor_device;
struct storvsc_cmd_request *request;
struct vstor_packet *vstor_packet;
int ret, t;
stor_device = get_out_stor_device(device);
if (!stor_device)
return FAILED;
request = &stor_device->reset_request;
vstor_packet = &request->vstor_packet;
init_completion(&request->wait_event);
vstor_packet->operation = VSTOR_OPERATION_RESET_BUS;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
vstor_packet->vm_srb.path_id = stor_device->path_id;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)&stor_device->reset_request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
return FAILED;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0)
return TIMEOUT_ERROR;
storvsc_wait_to_drain(stor_device);
return SUCCESS;
}
static bool storvsc_scsi_cmd_ok(struct scsi_cmnd *scmnd)
{
bool allowed = true;
u8 scsi_op = scmnd->cmnd[0];
switch (scsi_op) {
case WRITE_SAME:
case SET_WINDOW:
scmnd->result = ILLEGAL_REQUEST << 16;
allowed = false;
break;
default:
break;
}
return allowed;
}
static int storvsc_queuecommand(struct Scsi_Host *host, struct scsi_cmnd *scmnd)
{
int ret;
struct hv_host_device *host_dev = shost_priv(host);
struct hv_device *dev = host_dev->dev;
struct storvsc_cmd_request *cmd_request;
unsigned int request_size = 0;
int i;
struct scatterlist *sgl;
unsigned int sg_count = 0;
struct vmscsi_request *vm_srb;
struct stor_mem_pools *memp = scmnd->device->hostdata;
if (!storvsc_scsi_cmd_ok(scmnd)) {
scmnd->scsi_done(scmnd);
return 0;
}
request_size = sizeof(struct storvsc_cmd_request);
cmd_request = mempool_alloc(memp->request_mempool,
GFP_ATOMIC);
if (!cmd_request)
return SCSI_MLQUEUE_DEVICE_BUSY;
memset(cmd_request, 0, sizeof(struct storvsc_cmd_request));
cmd_request->cmd = scmnd;
scmnd->host_scribble = (unsigned char *)cmd_request;
vm_srb = &cmd_request->vstor_packet.vm_srb;
vm_srb->win8_extension.time_out_value = 60;
switch (scmnd->sc_data_direction) {
case DMA_TO_DEVICE:
vm_srb->data_in = WRITE_TYPE;
vm_srb->win8_extension.srb_flags |= SRB_FLAGS_DATA_OUT;
vm_srb->win8_extension.srb_flags |=
(SRB_FLAGS_QUEUE_ACTION_ENABLE |
SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
break;
case DMA_FROM_DEVICE:
vm_srb->data_in = READ_TYPE;
vm_srb->win8_extension.srb_flags |= SRB_FLAGS_DATA_IN;
vm_srb->win8_extension.srb_flags |=
(SRB_FLAGS_QUEUE_ACTION_ENABLE |
SRB_FLAGS_DISABLE_SYNCH_TRANSFER);
break;
default:
vm_srb->data_in = UNKNOWN_TYPE;
vm_srb->win8_extension.srb_flags = 0;
break;
}
vm_srb->port_number = host_dev->port;
vm_srb->path_id = scmnd->device->channel;
vm_srb->target_id = scmnd->device->id;
vm_srb->lun = scmnd->device->lun;
vm_srb->cdb_length = scmnd->cmd_len;
memcpy(vm_srb->cdb, scmnd->cmnd, vm_srb->cdb_length);
cmd_request->sense_buffer = scmnd->sense_buffer;
cmd_request->data_buffer.len = scsi_bufflen(scmnd);
if (scsi_sg_count(scmnd)) {
sgl = (struct scatterlist *)scsi_sglist(scmnd);
sg_count = scsi_sg_count(scmnd);
if (do_bounce_buffer(sgl, scsi_sg_count(scmnd)) != -1) {
cmd_request->bounce_sgl =
create_bounce_buffer(sgl, scsi_sg_count(scmnd),
scsi_bufflen(scmnd),
vm_srb->data_in);
if (!cmd_request->bounce_sgl) {
ret = SCSI_MLQUEUE_HOST_BUSY;
goto queue_error;
}
cmd_request->bounce_sgl_count =
ALIGN(scsi_bufflen(scmnd), PAGE_SIZE) >>
PAGE_SHIFT;
if (vm_srb->data_in == WRITE_TYPE)
copy_to_bounce_buffer(sgl,
cmd_request->bounce_sgl,
scsi_sg_count(scmnd));
sgl = cmd_request->bounce_sgl;
sg_count = cmd_request->bounce_sgl_count;
}
cmd_request->data_buffer.offset = sgl[0].offset;
for (i = 0; i < sg_count; i++)
cmd_request->data_buffer.pfn_array[i] =
page_to_pfn(sg_page((&sgl[i])));
} else if (scsi_sglist(scmnd)) {
cmd_request->data_buffer.offset =
virt_to_phys(scsi_sglist(scmnd)) & (PAGE_SIZE-1);
cmd_request->data_buffer.pfn_array[0] =
virt_to_phys(scsi_sglist(scmnd)) >> PAGE_SHIFT;
}
ret = storvsc_do_io(dev, cmd_request);
if (ret == -EAGAIN) {
if (cmd_request->bounce_sgl_count) {
destroy_bounce_buffer(cmd_request->bounce_sgl,
cmd_request->bounce_sgl_count);
ret = SCSI_MLQUEUE_DEVICE_BUSY;
goto queue_error;
}
}
return 0;
queue_error:
mempool_free(cmd_request, memp->request_mempool);
scmnd->host_scribble = NULL;
return ret;
}
static int storvsc_probe(struct hv_device *device,
const struct hv_vmbus_device_id *dev_id)
{
int ret;
struct Scsi_Host *host;
struct hv_host_device *host_dev;
bool dev_is_ide = ((dev_id->driver_data == IDE_GUID) ? true : false);
int target = 0;
struct storvsc_device *stor_device;
if (vmbus_proto_version == VERSION_WIN8) {
sense_buffer_size = POST_WIN7_STORVSC_SENSE_BUFFER_SIZE;
vmscsi_size_delta = 0;
vmstor_current_major = VMSTOR_WIN8_MAJOR;
vmstor_current_minor = VMSTOR_WIN8_MINOR;
} else {
sense_buffer_size = PRE_WIN8_STORVSC_SENSE_BUFFER_SIZE;
vmscsi_size_delta = sizeof(struct vmscsi_win8_extension);
vmstor_current_major = VMSTOR_WIN7_MAJOR;
vmstor_current_minor = VMSTOR_WIN7_MINOR;
}
host = scsi_host_alloc(&scsi_driver,
sizeof(struct hv_host_device));
if (!host)
return -ENOMEM;
host_dev = shost_priv(host);
memset(host_dev, 0, sizeof(struct hv_host_device));
host_dev->port = host->host_no;
host_dev->dev = device;
stor_device = kzalloc(sizeof(struct storvsc_device), GFP_KERNEL);
if (!stor_device) {
ret = -ENOMEM;
goto err_out0;
}
stor_device->destroy = false;
stor_device->open_sub_channel = false;
init_waitqueue_head(&stor_device->waiting_to_drain);
stor_device->device = device;
stor_device->host = host;
hv_set_drvdata(device, stor_device);
stor_device->port_number = host->host_no;
ret = storvsc_connect_to_vsp(device, storvsc_ringbuffer_size);
if (ret)
goto err_out1;
host_dev->path = stor_device->path_id;
host_dev->target = stor_device->target_id;
host->max_lun = STORVSC_MAX_LUNS_PER_TARGET;
host->max_id = STORVSC_MAX_TARGETS;
host->max_channel = STORVSC_MAX_CHANNELS - 1;
host->max_cmd_len = STORVSC_MAX_CMD_LEN;
ret = scsi_add_host(host, &device->device);
if (ret != 0)
goto err_out2;
if (!dev_is_ide) {
scsi_scan_host(host);
} else {
target = (device->dev_instance.b[5] << 8 |
device->dev_instance.b[4]);
ret = scsi_add_device(host, 0, target, 0);
if (ret) {
scsi_remove_host(host);
goto err_out2;
}
}
return 0;
err_out2:
storvsc_dev_remove(device);
goto err_out0;
err_out1:
kfree(stor_device);
err_out0:
scsi_host_put(host);
return ret;
}
static int storvsc_remove(struct hv_device *dev)
{
struct storvsc_device *stor_device = hv_get_drvdata(dev);
struct Scsi_Host *host = stor_device->host;
scsi_remove_host(host);
storvsc_dev_remove(dev);
scsi_host_put(host);
return 0;
}
static int __init storvsc_drv_init(void)
{
u32 max_outstanding_req_per_channel;
max_outstanding_req_per_channel =
((storvsc_ringbuffer_size - PAGE_SIZE) /
ALIGN(MAX_MULTIPAGE_BUFFER_PACKET +
sizeof(struct vstor_packet) + sizeof(u64) -
vmscsi_size_delta,
sizeof(u64)));
if (max_outstanding_req_per_channel <
STORVSC_MAX_IO_REQUESTS)
return -EINVAL;
return vmbus_driver_register(&storvsc_drv);
}
static void __exit storvsc_drv_exit(void)
{
vmbus_driver_unregister(&storvsc_drv);
}
