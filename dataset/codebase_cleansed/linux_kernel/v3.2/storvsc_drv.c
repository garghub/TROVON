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
static int storvsc_channel_init(struct hv_device *device)
{
struct storvsc_device *stor_device;
struct hv_storvsc_request *request;
struct vstor_packet *vstor_packet;
int ret, t;
stor_device = get_out_stor_device(device);
if (!stor_device)
return -ENODEV;
request = &stor_device->init_request;
vstor_packet = &request->vstor_packet;
memset(request, 0, sizeof(struct hv_storvsc_request));
init_completion(&request->wait_event);
vstor_packet->operation = VSTOR_OPERATION_BEGIN_INITIALIZATION;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
ret = vmbus_sendpacket(device->channel, vstor_packet,
sizeof(struct vstor_packet),
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
vstor_packet->version.major_minor = VMSTOR_PROTOCOL_VERSION_CURRENT;
FILL_VMSTOR_REVISION(vstor_packet->version.revision);
ret = vmbus_sendpacket(device->channel, vstor_packet,
sizeof(struct vstor_packet),
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
vstor_packet->storage_channel_properties.port_number =
stor_device->port_number;
ret = vmbus_sendpacket(device->channel, vstor_packet,
sizeof(struct vstor_packet),
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
stor_device->path_id = vstor_packet->storage_channel_properties.path_id;
stor_device->target_id
= vstor_packet->storage_channel_properties.target_id;
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_END_INITIALIZATION;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
ret = vmbus_sendpacket(device->channel, vstor_packet,
sizeof(struct vstor_packet),
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
cleanup:
return ret;
}
static void storvsc_on_io_completion(struct hv_device *device,
struct vstor_packet *vstor_packet,
struct hv_storvsc_request *request)
{
struct storvsc_device *stor_device;
struct vstor_packet *stor_pkt;
stor_device = hv_get_drvdata(device);
stor_pkt = &request->vstor_packet;
if ((stor_pkt->vm_srb.cdb[0] == INQUIRY) ||
(stor_pkt->vm_srb.cdb[0] == MODE_SENSE)) {
vstor_packet->vm_srb.scsi_status = 0;
vstor_packet->vm_srb.srb_status = 0x1;
}
stor_pkt->vm_srb.scsi_status = vstor_packet->vm_srb.scsi_status;
stor_pkt->vm_srb.srb_status = vstor_packet->vm_srb.srb_status;
stor_pkt->vm_srb.sense_info_length =
vstor_packet->vm_srb.sense_info_length;
if (vstor_packet->vm_srb.scsi_status != 0 ||
vstor_packet->vm_srb.srb_status != 1){
dev_warn(&device->device,
"cmd 0x%x scsi status 0x%x srb status 0x%x\n",
stor_pkt->vm_srb.cdb[0],
vstor_packet->vm_srb.scsi_status,
vstor_packet->vm_srb.srb_status);
}
if ((vstor_packet->vm_srb.scsi_status & 0xFF) == 0x02) {
if (vstor_packet->vm_srb.srb_status & 0x80) {
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
request->on_io_completion(request);
if (atomic_dec_and_test(&stor_device->num_outstanding_req) &&
stor_device->drain_notify)
wake_up(&stor_device->waiting_to_drain);
}
static void storvsc_on_receive(struct hv_device *device,
struct vstor_packet *vstor_packet,
struct hv_storvsc_request *request)
{
switch (vstor_packet->operation) {
case VSTOR_OPERATION_COMPLETE_IO:
storvsc_on_io_completion(device, vstor_packet, request);
break;
case VSTOR_OPERATION_REMOVE_DEVICE:
default:
break;
}
}
static void storvsc_on_channel_callback(void *context)
{
struct hv_device *device = (struct hv_device *)context;
struct storvsc_device *stor_device;
u32 bytes_recvd;
u64 request_id;
unsigned char packet[ALIGN(sizeof(struct vstor_packet), 8)];
struct hv_storvsc_request *request;
int ret;
stor_device = get_in_stor_device(device);
if (!stor_device)
return;
do {
ret = vmbus_recvpacket(device->channel, packet,
ALIGN(sizeof(struct vstor_packet), 8),
&bytes_recvd, &request_id);
if (ret == 0 && bytes_recvd > 0) {
request = (struct hv_storvsc_request *)
(unsigned long)request_id;
if ((request == &stor_device->init_request) ||
(request == &stor_device->reset_request)) {
memcpy(&request->vstor_packet, packet,
sizeof(struct vstor_packet));
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
storvsc_on_channel_callback, device);
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
struct hv_storvsc_request *request)
{
struct storvsc_device *stor_device;
struct vstor_packet *vstor_packet;
int ret = 0;
vstor_packet = &request->vstor_packet;
stor_device = get_out_stor_device(device);
if (!stor_device)
return -ENODEV;
request->device = device;
vstor_packet->flags |= REQUEST_COMPLETION_FLAG;
vstor_packet->vm_srb.length = sizeof(struct vmscsi_request);
vstor_packet->vm_srb.sense_info_length = SENSE_BUFFER_SIZE;
vstor_packet->vm_srb.data_transfer_length =
request->data_buffer.len;
vstor_packet->operation = VSTOR_OPERATION_EXECUTE_SRB;
if (request->data_buffer.len) {
ret = vmbus_sendpacket_multipagebuffer(device->channel,
&request->data_buffer,
vstor_packet,
sizeof(struct vstor_packet),
(unsigned long)request);
} else {
ret = vmbus_sendpacket(device->channel, vstor_packet,
sizeof(struct vstor_packet),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
}
if (ret != 0)
return ret;
atomic_inc(&stor_device->num_outstanding_req);
return ret;
}
static void storvsc_get_ide_info(struct hv_device *dev, int *target, int *path)
{
*target =
dev->dev_instance.b[5] << 8 | dev->dev_instance.b[4];
*path =
dev->dev_instance.b[3] << 24 |
dev->dev_instance.b[2] << 16 |
dev->dev_instance.b[1] << 8 | dev->dev_instance.b[0];
}
static int storvsc_device_alloc(struct scsi_device *sdevice)
{
sdevice->sdev_bflags |= BLIST_SPARSELUN | BLIST_LARGELUN;
return 0;
}
static int storvsc_merge_bvec(struct request_queue *q,
struct bvec_merge_data *bmd, struct bio_vec *bvec)
{
return bvec->bv_len;
}
static int storvsc_device_configure(struct scsi_device *sdevice)
{
scsi_adjust_queue_depth(sdevice, MSG_SIMPLE_TAG,
STORVSC_MAX_IO_REQUESTS);
blk_queue_max_segment_size(sdevice->request_queue, PAGE_SIZE);
blk_queue_merge_bvec(sdevice->request_queue, storvsc_merge_bvec);
blk_queue_bounce_limit(sdevice->request_queue, BLK_BOUNCE_ANY);
return 0;
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
unsigned int len)
{
int i;
int num_pages;
struct scatterlist *bounce_sgl;
struct page *page_buf;
num_pages = ALIGN(len, PAGE_SIZE) >> PAGE_SHIFT;
bounce_sgl = kcalloc(num_pages, sizeof(struct scatterlist), GFP_ATOMIC);
if (!bounce_sgl)
return NULL;
for (i = 0; i < num_pages; i++) {
page_buf = alloc_page(GFP_ATOMIC);
if (!page_buf)
goto cleanup;
sg_set_page(&bounce_sgl[i], page_buf, 0, 0);
}
return bounce_sgl;
cleanup:
destroy_bounce_buffer(bounce_sgl, num_pages);
return NULL;
}
static unsigned int copy_from_bounce_buffer(struct scatterlist *orig_sgl,
struct scatterlist *bounce_sgl,
unsigned int orig_sgl_count)
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
dest_addr = (unsigned long)kmap_atomic(sg_page((&orig_sgl[i])),
KM_IRQ0) + orig_sgl[i].offset;
dest = dest_addr;
destlen = orig_sgl[i].length;
if (bounce_addr == 0)
bounce_addr =
(unsigned long)kmap_atomic(sg_page((&bounce_sgl[j])),
KM_IRQ0);
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
kunmap_atomic((void *)bounce_addr, KM_IRQ0);
j++;
if (destlen || i != orig_sgl_count - 1)
bounce_addr =
(unsigned long)kmap_atomic(
sg_page((&bounce_sgl[j])), KM_IRQ0);
} else if (destlen == 0 && i == orig_sgl_count - 1) {
kunmap_atomic((void *)bounce_addr, KM_IRQ0);
}
}
kunmap_atomic((void *)(dest_addr - orig_sgl[i].offset),
KM_IRQ0);
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
src_addr = (unsigned long)kmap_atomic(sg_page((&orig_sgl[i])),
KM_IRQ0) + orig_sgl[i].offset;
src = src_addr;
srclen = orig_sgl[i].length;
if (bounce_addr == 0)
bounce_addr =
(unsigned long)kmap_atomic(sg_page((&bounce_sgl[j])),
KM_IRQ0);
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
kunmap_atomic((void *)bounce_addr, KM_IRQ0);
j++;
if (srclen || i != orig_sgl_count - 1)
bounce_addr =
(unsigned long)kmap_atomic(
sg_page((&bounce_sgl[j])), KM_IRQ0);
} else if (srclen == 0 && i == orig_sgl_count - 1) {
kunmap_atomic((void *)bounce_addr, KM_IRQ0);
}
}
kunmap_atomic((void *)(src_addr - orig_sgl[i].offset), KM_IRQ0);
}
local_irq_restore(flags);
return total_copied;
}
static int storvsc_remove(struct hv_device *dev)
{
struct storvsc_device *stor_device = hv_get_drvdata(dev);
struct Scsi_Host *host = stor_device->host;
struct hv_host_device *host_dev =
(struct hv_host_device *)host->hostdata;
scsi_remove_host(host);
scsi_host_put(host);
storvsc_dev_remove(dev);
if (host_dev->request_pool) {
kmem_cache_destroy(host_dev->request_pool);
host_dev->request_pool = NULL;
}
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
static int storvsc_host_reset(struct hv_device *device)
{
struct storvsc_device *stor_device;
struct hv_storvsc_request *request;
struct vstor_packet *vstor_packet;
int ret, t;
stor_device = get_out_stor_device(device);
if (!stor_device)
return -ENODEV;
request = &stor_device->reset_request;
vstor_packet = &request->vstor_packet;
init_completion(&request->wait_event);
vstor_packet->operation = VSTOR_OPERATION_RESET_BUS;
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
vstor_packet->vm_srb.path_id = stor_device->path_id;
ret = vmbus_sendpacket(device->channel, vstor_packet,
sizeof(struct vstor_packet),
(unsigned long)&stor_device->reset_request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
goto cleanup;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
cleanup:
return ret;
}
static int storvsc_host_reset_handler(struct scsi_cmnd *scmnd)
{
int ret;
struct hv_host_device *host_dev =
(struct hv_host_device *)scmnd->device->host->hostdata;
struct hv_device *dev = host_dev->dev;
ret = storvsc_host_reset(dev);
if (ret != 0)
return ret;
return ret;
}
static void storvsc_command_completion(struct hv_storvsc_request *request)
{
struct storvsc_cmd_request *cmd_request =
(struct storvsc_cmd_request *)request->context;
struct scsi_cmnd *scmnd = cmd_request->cmd;
struct hv_host_device *host_dev =
(struct hv_host_device *)scmnd->device->host->hostdata;
void (*scsi_done_fn)(struct scsi_cmnd *);
struct scsi_sense_hdr sense_hdr;
struct vmscsi_request *vm_srb;
vm_srb = &request->vstor_packet.vm_srb;
if (cmd_request->bounce_sgl_count) {
if (vm_srb->data_in == READ_TYPE) {
copy_from_bounce_buffer(scsi_sglist(scmnd),
cmd_request->bounce_sgl,
scsi_sg_count(scmnd));
destroy_bounce_buffer(cmd_request->bounce_sgl,
cmd_request->bounce_sgl_count);
}
}
if (vm_srb->srb_status == 0x4)
scmnd->result = DID_TARGET_FAILURE << 16;
else
scmnd->result = vm_srb->scsi_status;
if (scmnd->result) {
if (scsi_normalize_sense(scmnd->sense_buffer,
SCSI_SENSE_BUFFERSIZE, &sense_hdr))
scsi_print_sense_hdr("storvsc", &sense_hdr);
}
scsi_set_resid(scmnd,
request->data_buffer.len -
vm_srb->data_transfer_length);
scsi_done_fn = scmnd->scsi_done;
scmnd->host_scribble = NULL;
scmnd->scsi_done = NULL;
scsi_done_fn(scmnd);
kmem_cache_free(host_dev->request_pool, cmd_request);
}
static bool storvsc_check_scsi_cmd(struct scsi_cmnd *scmnd)
{
bool allowed = true;
u8 scsi_op = scmnd->cmnd[0];
switch (scsi_op) {
case SET_WINDOW:
scmnd->result = DID_ERROR << 16;
allowed = false;
break;
default:
break;
}
return allowed;
}
static int storvsc_queuecommand_lck(struct scsi_cmnd *scmnd,
void (*done)(struct scsi_cmnd *))
{
int ret;
struct hv_host_device *host_dev =
(struct hv_host_device *)scmnd->device->host->hostdata;
struct hv_device *dev = host_dev->dev;
struct hv_storvsc_request *request;
struct storvsc_cmd_request *cmd_request;
unsigned int request_size = 0;
int i;
struct scatterlist *sgl;
unsigned int sg_count = 0;
struct vmscsi_request *vm_srb;
if (storvsc_check_scsi_cmd(scmnd) == false) {
done(scmnd);
return 0;
}
if (scmnd->host_scribble) {
cmd_request =
(struct storvsc_cmd_request *)scmnd->host_scribble;
goto retry_request;
}
scmnd->scsi_done = done;
request_size = sizeof(struct storvsc_cmd_request);
cmd_request = kmem_cache_zalloc(host_dev->request_pool,
GFP_ATOMIC);
if (!cmd_request) {
scmnd->scsi_done = NULL;
return SCSI_MLQUEUE_DEVICE_BUSY;
}
cmd_request->bounce_sgl_count = 0;
cmd_request->bounce_sgl = NULL;
cmd_request->cmd = scmnd;
scmnd->host_scribble = (unsigned char *)cmd_request;
request = &cmd_request->request;
vm_srb = &request->vstor_packet.vm_srb;
switch (scmnd->sc_data_direction) {
case DMA_TO_DEVICE:
vm_srb->data_in = WRITE_TYPE;
break;
case DMA_FROM_DEVICE:
vm_srb->data_in = READ_TYPE;
break;
default:
vm_srb->data_in = UNKNOWN_TYPE;
break;
}
request->on_io_completion = storvsc_command_completion;
request->context = cmd_request;
vm_srb->port_number = host_dev->port;
vm_srb->path_id = scmnd->device->channel;
vm_srb->target_id = scmnd->device->id;
vm_srb->lun = scmnd->device->lun;
vm_srb->cdb_length = scmnd->cmd_len;
memcpy(vm_srb->cdb, scmnd->cmnd, vm_srb->cdb_length);
request->sense_buffer = scmnd->sense_buffer;
request->data_buffer.len = scsi_bufflen(scmnd);
if (scsi_sg_count(scmnd)) {
sgl = (struct scatterlist *)scsi_sglist(scmnd);
sg_count = scsi_sg_count(scmnd);
if (do_bounce_buffer(sgl, scsi_sg_count(scmnd)) != -1) {
cmd_request->bounce_sgl =
create_bounce_buffer(sgl, scsi_sg_count(scmnd),
scsi_bufflen(scmnd));
if (!cmd_request->bounce_sgl) {
scmnd->scsi_done = NULL;
scmnd->host_scribble = NULL;
kmem_cache_free(host_dev->request_pool,
cmd_request);
return SCSI_MLQUEUE_HOST_BUSY;
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
request->data_buffer.offset = sgl[0].offset;
for (i = 0; i < sg_count; i++)
request->data_buffer.pfn_array[i] =
page_to_pfn(sg_page((&sgl[i])));
} else if (scsi_sglist(scmnd)) {
request->data_buffer.offset =
virt_to_phys(scsi_sglist(scmnd)) & (PAGE_SIZE-1);
request->data_buffer.pfn_array[0] =
virt_to_phys(scsi_sglist(scmnd)) >> PAGE_SHIFT;
}
retry_request:
ret = storvsc_do_io(dev, &cmd_request->request);
if (ret == -EAGAIN) {
if (cmd_request->bounce_sgl_count)
destroy_bounce_buffer(cmd_request->bounce_sgl,
cmd_request->bounce_sgl_count);
kmem_cache_free(host_dev->request_pool, cmd_request);
scmnd->scsi_done = NULL;
scmnd->host_scribble = NULL;
ret = SCSI_MLQUEUE_DEVICE_BUSY;
}
return ret;
}
static int storvsc_probe(struct hv_device *device,
const struct hv_vmbus_device_id *dev_id)
{
int ret;
struct Scsi_Host *host;
struct hv_host_device *host_dev;
bool dev_is_ide = ((dev_id->driver_data == IDE_GUID) ? true : false);
int path = 0;
int target = 0;
struct storvsc_device *stor_device;
host = scsi_host_alloc(&scsi_driver,
sizeof(struct hv_host_device));
if (!host)
return -ENOMEM;
host_dev = (struct hv_host_device *)host->hostdata;
memset(host_dev, 0, sizeof(struct hv_host_device));
host_dev->port = host->host_no;
host_dev->dev = device;
host_dev->request_pool =
kmem_cache_create(dev_name(&device->device),
sizeof(struct storvsc_cmd_request), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!host_dev->request_pool) {
scsi_host_put(host);
return -ENOMEM;
}
stor_device = kzalloc(sizeof(struct storvsc_device), GFP_KERNEL);
if (!stor_device) {
kmem_cache_destroy(host_dev->request_pool);
scsi_host_put(host);
return -ENOMEM;
}
stor_device->destroy = false;
init_waitqueue_head(&stor_device->waiting_to_drain);
stor_device->device = device;
stor_device->host = host;
hv_set_drvdata(device, stor_device);
stor_device->port_number = host->host_no;
ret = storvsc_connect_to_vsp(device, storvsc_ringbuffer_size);
if (ret) {
kmem_cache_destroy(host_dev->request_pool);
scsi_host_put(host);
kfree(stor_device);
return ret;
}
if (dev_is_ide)
storvsc_get_ide_info(device, &target, &path);
host_dev->path = stor_device->path_id;
host_dev->target = stor_device->target_id;
host->max_lun = STORVSC_MAX_LUNS_PER_TARGET;
host->max_id = STORVSC_MAX_TARGETS;
host->max_channel = STORVSC_MAX_CHANNELS - 1;
host->max_cmd_len = STORVSC_MAX_CMD_LEN;
ret = scsi_add_host(host, &device->device);
if (ret != 0)
goto err_out;
if (!dev_is_ide) {
scsi_scan_host(host);
return 0;
}
ret = scsi_add_device(host, 0, target, 0);
if (ret) {
scsi_remove_host(host);
goto err_out;
}
return 0;
err_out:
storvsc_dev_remove(device);
kmem_cache_destroy(host_dev->request_pool);
scsi_host_put(host);
return -ENODEV;
}
static int __init storvsc_drv_init(void)
{
u32 max_outstanding_req_per_channel;
max_outstanding_req_per_channel =
((storvsc_ringbuffer_size - PAGE_SIZE) /
ALIGN(MAX_MULTIPAGE_BUFFER_PACKET +
sizeof(struct vstor_packet) + sizeof(u64),
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
