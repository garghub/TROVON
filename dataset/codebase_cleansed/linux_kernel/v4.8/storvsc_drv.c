static inline bool do_logging(int level)
{
return logging_level >= level;
}
static void storvsc_device_scan(struct work_struct *work)
{
struct storvsc_scan_work *wrk;
struct scsi_device *sdev;
wrk = container_of(work, struct storvsc_scan_work, work);
sdev = scsi_device_lookup(wrk->host, 0, wrk->tgt_id, wrk->lun);
if (!sdev)
goto done;
scsi_rescan_device(&sdev->sdev_gendev);
scsi_device_put(sdev);
done:
kfree(wrk);
}
static void storvsc_host_scan(struct work_struct *work)
{
struct storvsc_scan_work *wrk;
struct Scsi_Host *host;
struct scsi_device *sdev;
wrk = container_of(work, struct storvsc_scan_work, work);
host = wrk->host;
mutex_lock(&host->scan_mutex);
shost_for_each_device(sdev, host)
scsi_test_unit_ready(sdev, 1, 1, NULL);
mutex_unlock(&host->scan_mutex);
scsi_scan_host(host);
kfree(wrk);
}
static void storvsc_remove_lun(struct work_struct *work)
{
struct storvsc_scan_work *wrk;
struct scsi_device *sdev;
wrk = container_of(work, struct storvsc_scan_work, work);
if (!scsi_host_get(wrk->host))
goto done;
sdev = scsi_device_lookup(wrk->host, 0, wrk->tgt_id, wrk->lun);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
}
scsi_host_put(wrk->host);
done:
kfree(wrk);
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
static void cache_wwn(struct storvsc_device *stor_device,
struct vstor_packet *vstor_packet)
{
if (vstor_packet->wwn_packet.primary_active) {
stor_device->node_name =
wwn_to_u64(vstor_packet->wwn_packet.primary_node_wwn);
stor_device->port_name =
wwn_to_u64(vstor_packet->wwn_packet.primary_port_wwn);
} else {
stor_device->node_name =
wwn_to_u64(vstor_packet->wwn_packet.secondary_node_wwn);
stor_device->port_name =
wwn_to_u64(vstor_packet->wwn_packet.secondary_port_wwn);
}
}
static int storvsc_execute_vstor_op(struct hv_device *device,
struct storvsc_cmd_request *request,
bool status_check)
{
struct vstor_packet *vstor_packet;
int ret, t;
vstor_packet = &request->vstor_packet;
init_completion(&request->wait_event);
vstor_packet->flags = REQUEST_COMPLETION_FLAG;
ret = vmbus_sendpacket(device->channel, vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request,
VM_PKT_DATA_INBAND,
VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED);
if (ret != 0)
return ret;
t = wait_for_completion_timeout(&request->wait_event, 5*HZ);
if (t == 0)
return -ETIMEDOUT;
if (!status_check)
return ret;
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO ||
vstor_packet->status != 0)
return -EINVAL;
return ret;
}
static int storvsc_channel_init(struct hv_device *device, bool is_fc)
{
struct storvsc_device *stor_device;
struct storvsc_cmd_request *request;
struct vstor_packet *vstor_packet;
int ret, i;
int max_chns;
bool process_sub_channels = false;
stor_device = get_out_stor_device(device);
if (!stor_device)
return -ENODEV;
request = &stor_device->init_request;
vstor_packet = &request->vstor_packet;
memset(request, 0, sizeof(struct storvsc_cmd_request));
vstor_packet->operation = VSTOR_OPERATION_BEGIN_INITIALIZATION;
ret = storvsc_execute_vstor_op(device, request, true);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(vmstor_protocols); i++) {
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation =
VSTOR_OPERATION_QUERY_PROTOCOL_VERSION;
vstor_packet->version.major_minor =
vmstor_protocols[i].protocol_version;
vstor_packet->version.revision = 0;
ret = storvsc_execute_vstor_op(device, request, false);
if (ret != 0)
return ret;
if (vstor_packet->operation != VSTOR_OPERATION_COMPLETE_IO)
return -EINVAL;
if (vstor_packet->status == 0) {
vmstor_proto_version =
vmstor_protocols[i].protocol_version;
sense_buffer_size =
vmstor_protocols[i].sense_buffer_size;
vmscsi_size_delta =
vmstor_protocols[i].vmscsi_size_delta;
break;
}
}
if (vstor_packet->status != 0)
return -EINVAL;
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_QUERY_PROPERTIES;
ret = storvsc_execute_vstor_op(device, request, true);
if (ret != 0)
return ret;
max_chns = vstor_packet->storage_channel_properties.max_channel_cnt;
if (vmstor_proto_version >= VMSTOR_PROTO_VERSION_WIN8) {
if (vstor_packet->storage_channel_properties.flags &
STORAGE_CHANNEL_SUPPORTS_MULTI_CHANNEL)
process_sub_channels = true;
}
stor_device->max_transfer_bytes =
vstor_packet->storage_channel_properties.max_transfer_bytes;
if (!is_fc)
goto done;
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_FCHBA_DATA;
ret = storvsc_execute_vstor_op(device, request, true);
if (ret != 0)
return ret;
cache_wwn(stor_device, vstor_packet);
done:
memset(vstor_packet, 0, sizeof(struct vstor_packet));
vstor_packet->operation = VSTOR_OPERATION_END_INITIALIZATION;
ret = storvsc_execute_vstor_op(device, request, true);
if (ret != 0)
return ret;
if (process_sub_channels)
handle_multichannel_storage(device, max_chns);
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
switch (SRB_STATUS(vm_srb->srb_status)) {
case SRB_STATUS_ERROR:
switch (scmnd->cmnd[0]) {
case ATA_16:
case ATA_12:
set_host_byte(scmnd, DID_PASSTHROUGH);
break;
case TEST_UNIT_READY:
break;
default:
set_host_byte(scmnd, DID_TARGET_FAILURE);
}
break;
case SRB_STATUS_INVALID_LUN:
do_work = true;
process_err_fn = storvsc_remove_lun;
break;
case SRB_STATUS_ABORTED:
if (vm_srb->srb_status & SRB_STATUS_AUTOSENSE_VALID &&
(asc == 0x2a) && (ascq == 0x9)) {
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
wrk->tgt_id = vm_srb->target_id;
INIT_WORK(&wrk->work, process_err_fn);
schedule_work(&wrk->work);
}
static void storvsc_command_completion(struct storvsc_cmd_request *cmd_request,
struct storvsc_device *stor_dev)
{
struct scsi_cmnd *scmnd = cmd_request->cmd;
struct scsi_sense_hdr sense_hdr;
struct vmscsi_request *vm_srb;
struct Scsi_Host *host;
u32 payload_sz = cmd_request->payload_sz;
void *payload = cmd_request->payload;
host = stor_dev->host;
vm_srb = &cmd_request->vstor_packet.vm_srb;
scmnd->result = vm_srb->scsi_status;
if (scmnd->result) {
if (scsi_normalize_sense(scmnd->sense_buffer,
SCSI_SENSE_BUFFERSIZE, &sense_hdr) &&
!(sense_hdr.sense_key == NOT_READY &&
sense_hdr.asc == 0x03A) &&
do_logging(STORVSC_LOGGING_ERROR))
scsi_print_sense_hdr(scmnd->device, "storvsc",
&sense_hdr);
}
if (vm_srb->srb_status != SRB_STATUS_SUCCESS)
storvsc_handle_error(vm_srb, scmnd, host, sense_hdr.asc,
sense_hdr.ascq);
scsi_set_resid(scmnd,
cmd_request->payload->range.len -
vm_srb->data_transfer_length);
scmnd->scsi_done(scmnd);
if (payload_sz >
sizeof(struct vmbus_channel_packet_multipage_buffer))
kfree(payload);
}
static void storvsc_on_io_completion(struct storvsc_device *stor_device,
struct vstor_packet *vstor_packet,
struct storvsc_cmd_request *request)
{
struct vstor_packet *stor_pkt;
struct hv_device *device = stor_device->device;
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
vstor_packet->vm_srb.srb_status != SRB_STATUS_SUCCESS)
storvsc_log(device, STORVSC_LOGGING_WARN,
"cmd 0x%x scsi status 0x%x srb status 0x%x\n",
stor_pkt->vm_srb.cdb[0],
vstor_packet->vm_srb.scsi_status,
vstor_packet->vm_srb.srb_status);
if ((vstor_packet->vm_srb.scsi_status & 0xFF) == 0x02) {
if (vstor_packet->vm_srb.srb_status &
SRB_STATUS_AUTOSENSE_VALID) {
storvsc_log(device, STORVSC_LOGGING_WARN,
"stor pkt %p autosense data valid - len %d\n",
request, vstor_packet->vm_srb.sense_info_length);
memcpy(request->cmd->sense_buffer,
vstor_packet->vm_srb.sense_data,
vstor_packet->vm_srb.sense_info_length);
}
}
stor_pkt->vm_srb.data_transfer_length =
vstor_packet->vm_srb.data_transfer_length;
storvsc_command_completion(request, stor_device);
if (atomic_dec_and_test(&stor_device->num_outstanding_req) &&
stor_device->drain_notify)
wake_up(&stor_device->waiting_to_drain);
}
static void storvsc_on_receive(struct storvsc_device *stor_device,
struct vstor_packet *vstor_packet,
struct storvsc_cmd_request *request)
{
struct storvsc_scan_work *work;
switch (vstor_packet->operation) {
case VSTOR_OPERATION_COMPLETE_IO:
storvsc_on_io_completion(stor_device, vstor_packet, request);
break;
case VSTOR_OPERATION_REMOVE_DEVICE:
case VSTOR_OPERATION_ENUMERATE_BUS:
work = kmalloc(sizeof(struct storvsc_scan_work), GFP_ATOMIC);
if (!work)
return;
INIT_WORK(&work->work, storvsc_host_scan);
work->host = stor_device->host;
schedule_work(&work->work);
break;
case VSTOR_OPERATION_FCHBA_DATA:
cache_wwn(stor_device, vstor_packet);
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
fc_host_node_name(stor_device->host) = stor_device->node_name;
fc_host_port_name(stor_device->host) = stor_device->port_name;
#endif
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
storvsc_on_receive(stor_device,
(struct vstor_packet *)packet,
request);
}
} else {
break;
}
} while (1);
return;
}
static int storvsc_connect_to_vsp(struct hv_device *device, u32 ring_size,
bool is_fc)
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
ret = storvsc_channel_init(device, is_fc);
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
request->payload->range.len;
vstor_packet->operation = VSTOR_OPERATION_EXECUTE_SRB;
if (request->payload->range.len) {
ret = vmbus_sendpacket_mpb_desc(outgoing_channel,
request->payload, request->payload_sz,
vstor_packet,
(sizeof(struct vstor_packet) -
vmscsi_size_delta),
(unsigned long)request);
} else {
ret = vmbus_sendpacket(outgoing_channel, vstor_packet,
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
static int storvsc_device_configure(struct scsi_device *sdevice)
{
blk_queue_max_segment_size(sdevice->request_queue, PAGE_SIZE);
blk_queue_bounce_limit(sdevice->request_queue, BLK_BOUNCE_ANY);
blk_queue_rq_timeout(sdevice->request_queue, (storvsc_timeout * HZ));
blk_queue_virt_boundary(sdevice->request_queue, PAGE_SIZE - 1);
sdevice->no_write_same = 1;
sdevice->sdev_bflags |= msft_blist_flags;
if (!strncmp(sdevice->vendor, "Msft", 4)) {
switch (vmstor_proto_version) {
case VMSTOR_PROTO_VERSION_WIN8:
case VMSTOR_PROTO_VERSION_WIN8_1:
sdevice->scsi_level = SCSI_SPC_3;
break;
}
if (vmstor_proto_version >= VMSTOR_PROTO_VERSION_WIN10)
sdevice->no_write_same = 0;
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
static enum blk_eh_timer_return storvsc_eh_timed_out(struct scsi_cmnd *scmnd)
{
return BLK_EH_RESET_TIMER;
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
struct storvsc_cmd_request *cmd_request = scsi_cmd_priv(scmnd);
int i;
struct scatterlist *sgl;
unsigned int sg_count = 0;
struct vmscsi_request *vm_srb;
struct scatterlist *cur_sgl;
struct vmbus_packet_mpb_array *payload;
u32 payload_sz;
u32 length;
if (vmstor_proto_version <= VMSTOR_PROTO_VERSION_WIN8) {
if (!storvsc_scsi_cmd_ok(scmnd)) {
scmnd->scsi_done(scmnd);
return 0;
}
}
cmd_request->cmd = scmnd;
vm_srb = &cmd_request->vstor_packet.vm_srb;
vm_srb->win8_extension.time_out_value = 60;
vm_srb->win8_extension.srb_flags |=
SRB_FLAGS_DISABLE_SYNCH_TRANSFER;
switch (scmnd->sc_data_direction) {
case DMA_TO_DEVICE:
vm_srb->data_in = WRITE_TYPE;
vm_srb->win8_extension.srb_flags |= SRB_FLAGS_DATA_OUT;
break;
case DMA_FROM_DEVICE:
vm_srb->data_in = READ_TYPE;
vm_srb->win8_extension.srb_flags |= SRB_FLAGS_DATA_IN;
break;
case DMA_NONE:
vm_srb->data_in = UNKNOWN_TYPE;
vm_srb->win8_extension.srb_flags |= SRB_FLAGS_NO_DATA_TRANSFER;
break;
default:
WARN(1, "Unexpected data direction: %d\n",
scmnd->sc_data_direction);
return -EINVAL;
}
vm_srb->port_number = host_dev->port;
vm_srb->path_id = scmnd->device->channel;
vm_srb->target_id = scmnd->device->id;
vm_srb->lun = scmnd->device->lun;
vm_srb->cdb_length = scmnd->cmd_len;
memcpy(vm_srb->cdb, scmnd->cmnd, vm_srb->cdb_length);
sgl = (struct scatterlist *)scsi_sglist(scmnd);
sg_count = scsi_sg_count(scmnd);
length = scsi_bufflen(scmnd);
payload = (struct vmbus_packet_mpb_array *)&cmd_request->mpb;
payload_sz = sizeof(cmd_request->mpb);
if (sg_count) {
if (sg_count > MAX_PAGE_BUFFER_COUNT) {
payload_sz = (sg_count * sizeof(void *) +
sizeof(struct vmbus_packet_mpb_array));
payload = kmalloc(payload_sz, GFP_ATOMIC);
if (!payload)
return SCSI_MLQUEUE_DEVICE_BUSY;
}
payload->range.len = length;
payload->range.offset = sgl[0].offset;
cur_sgl = sgl;
for (i = 0; i < sg_count; i++) {
payload->range.pfn_array[i] =
page_to_pfn(sg_page((cur_sgl)));
cur_sgl = sg_next(cur_sgl);
}
} else if (scsi_sglist(scmnd)) {
payload->range.len = length;
payload->range.offset =
virt_to_phys(scsi_sglist(scmnd)) & (PAGE_SIZE-1);
payload->range.pfn_array[0] =
virt_to_phys(scsi_sglist(scmnd)) >> PAGE_SHIFT;
}
cmd_request->payload = payload;
cmd_request->payload_sz = payload_sz;
ret = storvsc_do_io(dev, cmd_request);
if (ret == -EAGAIN) {
return SCSI_MLQUEUE_DEVICE_BUSY;
}
return 0;
}
static int storvsc_probe(struct hv_device *device,
const struct hv_vmbus_device_id *dev_id)
{
int ret;
int num_cpus = num_online_cpus();
struct Scsi_Host *host;
struct hv_host_device *host_dev;
bool dev_is_ide = ((dev_id->driver_data == IDE_GUID) ? true : false);
bool is_fc = ((dev_id->driver_data == SFC_GUID) ? true : false);
int target = 0;
struct storvsc_device *stor_device;
int max_luns_per_target;
int max_targets;
int max_channels;
int max_sub_channels = 0;
if (vmbus_proto_version < VERSION_WIN8) {
max_luns_per_target = STORVSC_IDE_MAX_LUNS_PER_TARGET;
max_targets = STORVSC_IDE_MAX_TARGETS;
max_channels = STORVSC_IDE_MAX_CHANNELS;
} else {
max_luns_per_target = STORVSC_MAX_LUNS_PER_TARGET;
max_targets = STORVSC_MAX_TARGETS;
max_channels = STORVSC_MAX_CHANNELS;
max_sub_channels = (num_cpus / storvsc_vcpus_per_sub_channel);
}
scsi_driver.can_queue = (max_outstanding_req_per_channel *
(max_sub_channels + 1));
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
ret = storvsc_connect_to_vsp(device, storvsc_ringbuffer_size, is_fc);
if (ret)
goto err_out1;
host_dev->path = stor_device->path_id;
host_dev->target = stor_device->target_id;
switch (dev_id->driver_data) {
case SFC_GUID:
host->max_lun = STORVSC_FC_MAX_LUNS_PER_TARGET;
host->max_id = STORVSC_FC_MAX_TARGETS;
host->max_channel = STORVSC_FC_MAX_CHANNELS - 1;
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
host->transportt = fc_transport_template;
#endif
break;
case SCSI_GUID:
host->max_lun = max_luns_per_target;
host->max_id = max_targets;
host->max_channel = max_channels - 1;
break;
default:
host->max_lun = STORVSC_IDE_MAX_LUNS_PER_TARGET;
host->max_id = STORVSC_IDE_MAX_TARGETS;
host->max_channel = STORVSC_IDE_MAX_CHANNELS - 1;
break;
}
host->max_cmd_len = STORVSC_MAX_CMD_LEN;
host->sg_tablesize = (stor_device->max_transfer_bytes >> PAGE_SHIFT);
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
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
if (host->transportt == fc_transport_template) {
fc_host_node_name(host) = stor_device->node_name;
fc_host_port_name(host) = stor_device->port_name;
}
#endif
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
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
if (host->transportt == fc_transport_template)
fc_remove_host(host);
#endif
scsi_remove_host(host);
storvsc_dev_remove(dev);
scsi_host_put(host);
return 0;
}
static int __init storvsc_drv_init(void)
{
int ret;
max_outstanding_req_per_channel =
((storvsc_ringbuffer_size - PAGE_SIZE) /
ALIGN(MAX_MULTIPAGE_BUFFER_PACKET +
sizeof(struct vstor_packet) + sizeof(u64) -
vmscsi_size_delta,
sizeof(u64)));
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
fc_transport_template = fc_attach_transport(&fc_transport_functions);
if (!fc_transport_template)
return -ENODEV;
fc_transport_template->eh_timed_out = storvsc_eh_timed_out;
#endif
ret = vmbus_driver_register(&storvsc_drv);
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
if (ret)
fc_release_transport(fc_transport_template);
#endif
return ret;
}
static void __exit storvsc_drv_exit(void)
{
vmbus_driver_unregister(&storvsc_drv);
#if IS_ENABLED(CONFIG_SCSI_FC_ATTRS)
fc_release_transport(fc_transport_template);
#endif
}
