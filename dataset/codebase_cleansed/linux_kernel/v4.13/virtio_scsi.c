static inline struct Scsi_Host *virtio_scsi_host(struct virtio_device *vdev)
{
return vdev->priv;
}
static void virtscsi_compute_resid(struct scsi_cmnd *sc, u32 resid)
{
if (!resid)
return;
if (!scsi_bidi_cmnd(sc)) {
scsi_set_resid(sc, resid);
return;
}
scsi_in(sc)->resid = min(resid, scsi_in(sc)->length);
scsi_out(sc)->resid = resid - scsi_in(sc)->resid;
}
static void virtscsi_complete_cmd(struct virtio_scsi *vscsi, void *buf)
{
struct virtio_scsi_cmd *cmd = buf;
struct scsi_cmnd *sc = cmd->sc;
struct virtio_scsi_cmd_resp *resp = &cmd->resp.cmd;
struct virtio_scsi_target_state *tgt =
scsi_target(sc->device)->hostdata;
dev_dbg(&sc->device->sdev_gendev,
"cmd %p response %u status %#02x sense_len %u\n",
sc, resp->response, resp->status, resp->sense_len);
sc->result = resp->status;
virtscsi_compute_resid(sc, virtio32_to_cpu(vscsi->vdev, resp->resid));
switch (resp->response) {
case VIRTIO_SCSI_S_OK:
set_host_byte(sc, DID_OK);
break;
case VIRTIO_SCSI_S_OVERRUN:
set_host_byte(sc, DID_ERROR);
break;
case VIRTIO_SCSI_S_ABORTED:
set_host_byte(sc, DID_ABORT);
break;
case VIRTIO_SCSI_S_BAD_TARGET:
set_host_byte(sc, DID_BAD_TARGET);
break;
case VIRTIO_SCSI_S_RESET:
set_host_byte(sc, DID_RESET);
break;
case VIRTIO_SCSI_S_BUSY:
set_host_byte(sc, DID_BUS_BUSY);
break;
case VIRTIO_SCSI_S_TRANSPORT_FAILURE:
set_host_byte(sc, DID_TRANSPORT_DISRUPTED);
break;
case VIRTIO_SCSI_S_TARGET_FAILURE:
set_host_byte(sc, DID_TARGET_FAILURE);
break;
case VIRTIO_SCSI_S_NEXUS_FAILURE:
set_host_byte(sc, DID_NEXUS_FAILURE);
break;
default:
scmd_printk(KERN_WARNING, sc, "Unknown response %d",
resp->response);
case VIRTIO_SCSI_S_FAILURE:
set_host_byte(sc, DID_ERROR);
break;
}
WARN_ON(virtio32_to_cpu(vscsi->vdev, resp->sense_len) >
VIRTIO_SCSI_SENSE_SIZE);
if (sc->sense_buffer) {
memcpy(sc->sense_buffer, resp->sense,
min_t(u32,
virtio32_to_cpu(vscsi->vdev, resp->sense_len),
VIRTIO_SCSI_SENSE_SIZE));
if (resp->sense_len)
set_driver_byte(sc, DRIVER_SENSE);
}
sc->scsi_done(sc);
atomic_dec(&tgt->reqs);
}
static void virtscsi_vq_done(struct virtio_scsi *vscsi,
struct virtio_scsi_vq *virtscsi_vq,
void (*fn)(struct virtio_scsi *vscsi, void *buf))
{
void *buf;
unsigned int len;
unsigned long flags;
struct virtqueue *vq = virtscsi_vq->vq;
spin_lock_irqsave(&virtscsi_vq->vq_lock, flags);
do {
virtqueue_disable_cb(vq);
while ((buf = virtqueue_get_buf(vq, &len)) != NULL)
fn(vscsi, buf);
if (unlikely(virtqueue_is_broken(vq)))
break;
} while (!virtqueue_enable_cb(vq));
spin_unlock_irqrestore(&virtscsi_vq->vq_lock, flags);
}
static void virtscsi_req_done(struct virtqueue *vq)
{
struct Scsi_Host *sh = virtio_scsi_host(vq->vdev);
struct virtio_scsi *vscsi = shost_priv(sh);
int index = vq->index - VIRTIO_SCSI_VQ_BASE;
struct virtio_scsi_vq *req_vq = &vscsi->req_vqs[index];
virtscsi_vq_done(vscsi, req_vq, virtscsi_complete_cmd);
}
static void virtscsi_poll_requests(struct virtio_scsi *vscsi)
{
int i, num_vqs;
num_vqs = vscsi->num_queues;
for (i = 0; i < num_vqs; i++)
virtscsi_vq_done(vscsi, &vscsi->req_vqs[i],
virtscsi_complete_cmd);
}
static void virtscsi_complete_free(struct virtio_scsi *vscsi, void *buf)
{
struct virtio_scsi_cmd *cmd = buf;
if (cmd->comp)
complete(cmd->comp);
}
static void virtscsi_ctrl_done(struct virtqueue *vq)
{
struct Scsi_Host *sh = virtio_scsi_host(vq->vdev);
struct virtio_scsi *vscsi = shost_priv(sh);
virtscsi_vq_done(vscsi, &vscsi->ctrl_vq, virtscsi_complete_free);
}
static int virtscsi_kick_event(struct virtio_scsi *vscsi,
struct virtio_scsi_event_node *event_node)
{
int err;
struct scatterlist sg;
unsigned long flags;
INIT_WORK(&event_node->work, virtscsi_handle_event);
sg_init_one(&sg, &event_node->event, sizeof(struct virtio_scsi_event));
spin_lock_irqsave(&vscsi->event_vq.vq_lock, flags);
err = virtqueue_add_inbuf(vscsi->event_vq.vq, &sg, 1, event_node,
GFP_ATOMIC);
if (!err)
virtqueue_kick(vscsi->event_vq.vq);
spin_unlock_irqrestore(&vscsi->event_vq.vq_lock, flags);
return err;
}
static int virtscsi_kick_event_all(struct virtio_scsi *vscsi)
{
int i;
for (i = 0; i < VIRTIO_SCSI_EVENT_LEN; i++) {
vscsi->event_list[i].vscsi = vscsi;
virtscsi_kick_event(vscsi, &vscsi->event_list[i]);
}
return 0;
}
static void virtscsi_cancel_event_work(struct virtio_scsi *vscsi)
{
int i;
spin_lock_irq(&vscsi->event_vq.vq_lock);
vscsi->stop_events = true;
spin_unlock_irq(&vscsi->event_vq.vq_lock);
for (i = 0; i < VIRTIO_SCSI_EVENT_LEN; i++)
cancel_work_sync(&vscsi->event_list[i].work);
}
static void virtscsi_handle_transport_reset(struct virtio_scsi *vscsi,
struct virtio_scsi_event *event)
{
struct scsi_device *sdev;
struct Scsi_Host *shost = virtio_scsi_host(vscsi->vdev);
unsigned int target = event->lun[1];
unsigned int lun = (event->lun[2] << 8) | event->lun[3];
switch (virtio32_to_cpu(vscsi->vdev, event->reason)) {
case VIRTIO_SCSI_EVT_RESET_RESCAN:
scsi_add_device(shost, 0, target, lun);
break;
case VIRTIO_SCSI_EVT_RESET_REMOVED:
sdev = scsi_device_lookup(shost, 0, target, lun);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
} else {
pr_err("SCSI device %d 0 %d %d not found\n",
shost->host_no, target, lun);
}
break;
default:
pr_info("Unsupport virtio scsi event reason %x\n", event->reason);
}
}
static void virtscsi_handle_param_change(struct virtio_scsi *vscsi,
struct virtio_scsi_event *event)
{
struct scsi_device *sdev;
struct Scsi_Host *shost = virtio_scsi_host(vscsi->vdev);
unsigned int target = event->lun[1];
unsigned int lun = (event->lun[2] << 8) | event->lun[3];
u8 asc = virtio32_to_cpu(vscsi->vdev, event->reason) & 255;
u8 ascq = virtio32_to_cpu(vscsi->vdev, event->reason) >> 8;
sdev = scsi_device_lookup(shost, 0, target, lun);
if (!sdev) {
pr_err("SCSI device %d 0 %d %d not found\n",
shost->host_no, target, lun);
return;
}
if (asc == 0x2a && (ascq == 0x00 || ascq == 0x01 || ascq == 0x09))
scsi_rescan_device(&sdev->sdev_gendev);
scsi_device_put(sdev);
}
static void virtscsi_handle_event(struct work_struct *work)
{
struct virtio_scsi_event_node *event_node =
container_of(work, struct virtio_scsi_event_node, work);
struct virtio_scsi *vscsi = event_node->vscsi;
struct virtio_scsi_event *event = &event_node->event;
if (event->event &
cpu_to_virtio32(vscsi->vdev, VIRTIO_SCSI_T_EVENTS_MISSED)) {
event->event &= ~cpu_to_virtio32(vscsi->vdev,
VIRTIO_SCSI_T_EVENTS_MISSED);
scsi_scan_host(virtio_scsi_host(vscsi->vdev));
}
switch (virtio32_to_cpu(vscsi->vdev, event->event)) {
case VIRTIO_SCSI_T_NO_EVENT:
break;
case VIRTIO_SCSI_T_TRANSPORT_RESET:
virtscsi_handle_transport_reset(vscsi, event);
break;
case VIRTIO_SCSI_T_PARAM_CHANGE:
virtscsi_handle_param_change(vscsi, event);
break;
default:
pr_err("Unsupport virtio scsi event %x\n", event->event);
}
virtscsi_kick_event(vscsi, event_node);
}
static void virtscsi_complete_event(struct virtio_scsi *vscsi, void *buf)
{
struct virtio_scsi_event_node *event_node = buf;
if (!vscsi->stop_events)
queue_work(system_freezable_wq, &event_node->work);
}
static void virtscsi_event_done(struct virtqueue *vq)
{
struct Scsi_Host *sh = virtio_scsi_host(vq->vdev);
struct virtio_scsi *vscsi = shost_priv(sh);
virtscsi_vq_done(vscsi, &vscsi->event_vq, virtscsi_complete_event);
}
static int virtscsi_add_cmd(struct virtqueue *vq,
struct virtio_scsi_cmd *cmd,
size_t req_size, size_t resp_size)
{
struct scsi_cmnd *sc = cmd->sc;
struct scatterlist *sgs[6], req, resp;
struct sg_table *out, *in;
unsigned out_num = 0, in_num = 0;
out = in = NULL;
if (sc && sc->sc_data_direction != DMA_NONE) {
if (sc->sc_data_direction != DMA_FROM_DEVICE)
out = &scsi_out(sc)->table;
if (sc->sc_data_direction != DMA_TO_DEVICE)
in = &scsi_in(sc)->table;
}
sg_init_one(&req, &cmd->req, req_size);
sgs[out_num++] = &req;
if (out) {
if (scsi_prot_sg_count(sc))
sgs[out_num++] = scsi_prot_sglist(sc);
sgs[out_num++] = out->sgl;
}
sg_init_one(&resp, &cmd->resp, resp_size);
sgs[out_num + in_num++] = &resp;
if (in) {
if (scsi_prot_sg_count(sc))
sgs[out_num + in_num++] = scsi_prot_sglist(sc);
sgs[out_num + in_num++] = in->sgl;
}
return virtqueue_add_sgs(vq, sgs, out_num, in_num, cmd, GFP_ATOMIC);
}
static int virtscsi_kick_cmd(struct virtio_scsi_vq *vq,
struct virtio_scsi_cmd *cmd,
size_t req_size, size_t resp_size)
{
unsigned long flags;
int err;
bool needs_kick = false;
spin_lock_irqsave(&vq->vq_lock, flags);
err = virtscsi_add_cmd(vq->vq, cmd, req_size, resp_size);
if (!err)
needs_kick = virtqueue_kick_prepare(vq->vq);
spin_unlock_irqrestore(&vq->vq_lock, flags);
if (needs_kick)
virtqueue_notify(vq->vq);
return err;
}
static void virtio_scsi_init_hdr(struct virtio_device *vdev,
struct virtio_scsi_cmd_req *cmd,
struct scsi_cmnd *sc)
{
cmd->lun[0] = 1;
cmd->lun[1] = sc->device->id;
cmd->lun[2] = (sc->device->lun >> 8) | 0x40;
cmd->lun[3] = sc->device->lun & 0xff;
cmd->tag = cpu_to_virtio64(vdev, (unsigned long)sc);
cmd->task_attr = VIRTIO_SCSI_S_SIMPLE;
cmd->prio = 0;
cmd->crn = 0;
}
static void virtio_scsi_init_hdr_pi(struct virtio_device *vdev,
struct virtio_scsi_cmd_req_pi *cmd_pi,
struct scsi_cmnd *sc)
{
struct request *rq = sc->request;
struct blk_integrity *bi;
virtio_scsi_init_hdr(vdev, (struct virtio_scsi_cmd_req *)cmd_pi, sc);
if (!rq || !scsi_prot_sg_count(sc))
return;
bi = blk_get_integrity(rq->rq_disk);
if (sc->sc_data_direction == DMA_TO_DEVICE)
cmd_pi->pi_bytesout = cpu_to_virtio32(vdev,
blk_rq_sectors(rq) *
bi->tuple_size);
else if (sc->sc_data_direction == DMA_FROM_DEVICE)
cmd_pi->pi_bytesin = cpu_to_virtio32(vdev,
blk_rq_sectors(rq) *
bi->tuple_size);
}
static int virtscsi_queuecommand(struct virtio_scsi *vscsi,
struct virtio_scsi_vq *req_vq,
struct scsi_cmnd *sc)
{
struct Scsi_Host *shost = virtio_scsi_host(vscsi->vdev);
struct virtio_scsi_cmd *cmd = scsi_cmd_priv(sc);
unsigned long flags;
int req_size;
int ret;
BUG_ON(scsi_sg_count(sc) > shost->sg_tablesize);
BUG_ON(sc->sc_data_direction == DMA_BIDIRECTIONAL);
dev_dbg(&sc->device->sdev_gendev,
"cmd %p CDB: %#02x\n", sc, sc->cmnd[0]);
cmd->sc = sc;
BUG_ON(sc->cmd_len > VIRTIO_SCSI_CDB_SIZE);
#ifdef CONFIG_BLK_DEV_INTEGRITY
if (virtio_has_feature(vscsi->vdev, VIRTIO_SCSI_F_T10_PI)) {
virtio_scsi_init_hdr_pi(vscsi->vdev, &cmd->req.cmd_pi, sc);
memcpy(cmd->req.cmd_pi.cdb, sc->cmnd, sc->cmd_len);
req_size = sizeof(cmd->req.cmd_pi);
} else
#endif
{
virtio_scsi_init_hdr(vscsi->vdev, &cmd->req.cmd, sc);
memcpy(cmd->req.cmd.cdb, sc->cmnd, sc->cmd_len);
req_size = sizeof(cmd->req.cmd);
}
ret = virtscsi_kick_cmd(req_vq, cmd, req_size, sizeof(cmd->resp.cmd));
if (ret == -EIO) {
cmd->resp.cmd.response = VIRTIO_SCSI_S_BAD_TARGET;
spin_lock_irqsave(&req_vq->vq_lock, flags);
virtscsi_complete_cmd(vscsi, cmd);
spin_unlock_irqrestore(&req_vq->vq_lock, flags);
} else if (ret != 0) {
return SCSI_MLQUEUE_HOST_BUSY;
}
return 0;
}
static int virtscsi_queuecommand_single(struct Scsi_Host *sh,
struct scsi_cmnd *sc)
{
struct virtio_scsi *vscsi = shost_priv(sh);
struct virtio_scsi_target_state *tgt =
scsi_target(sc->device)->hostdata;
atomic_inc(&tgt->reqs);
return virtscsi_queuecommand(vscsi, &vscsi->req_vqs[0], sc);
}
static struct virtio_scsi_vq *virtscsi_pick_vq_mq(struct virtio_scsi *vscsi,
struct scsi_cmnd *sc)
{
u32 tag = blk_mq_unique_tag(sc->request);
u16 hwq = blk_mq_unique_tag_to_hwq(tag);
return &vscsi->req_vqs[hwq];
}
static struct virtio_scsi_vq *virtscsi_pick_vq(struct virtio_scsi *vscsi,
struct virtio_scsi_target_state *tgt)
{
struct virtio_scsi_vq *vq;
unsigned long flags;
u32 queue_num;
local_irq_save(flags);
if (atomic_inc_return(&tgt->reqs) > 1) {
unsigned long seq;
do {
seq = read_seqcount_begin(&tgt->tgt_seq);
vq = tgt->req_vq;
} while (read_seqcount_retry(&tgt->tgt_seq, seq));
} else {
write_seqcount_begin(&tgt->tgt_seq);
if (unlikely(atomic_read(&tgt->reqs) > 1)) {
vq = tgt->req_vq;
goto unlock;
}
queue_num = smp_processor_id();
while (unlikely(queue_num >= vscsi->num_queues))
queue_num -= vscsi->num_queues;
tgt->req_vq = vq = &vscsi->req_vqs[queue_num];
unlock:
write_seqcount_end(&tgt->tgt_seq);
}
local_irq_restore(flags);
return vq;
}
static int virtscsi_queuecommand_multi(struct Scsi_Host *sh,
struct scsi_cmnd *sc)
{
struct virtio_scsi *vscsi = shost_priv(sh);
struct virtio_scsi_target_state *tgt =
scsi_target(sc->device)->hostdata;
struct virtio_scsi_vq *req_vq;
if (shost_use_blk_mq(sh))
req_vq = virtscsi_pick_vq_mq(vscsi, sc);
else
req_vq = virtscsi_pick_vq(vscsi, tgt);
return virtscsi_queuecommand(vscsi, req_vq, sc);
}
static int virtscsi_tmf(struct virtio_scsi *vscsi, struct virtio_scsi_cmd *cmd)
{
DECLARE_COMPLETION_ONSTACK(comp);
int ret = FAILED;
cmd->comp = &comp;
if (virtscsi_kick_cmd(&vscsi->ctrl_vq, cmd,
sizeof cmd->req.tmf, sizeof cmd->resp.tmf) < 0)
goto out;
wait_for_completion(&comp);
if (cmd->resp.tmf.response == VIRTIO_SCSI_S_OK ||
cmd->resp.tmf.response == VIRTIO_SCSI_S_FUNCTION_SUCCEEDED)
ret = SUCCESS;
virtscsi_poll_requests(vscsi);
out:
mempool_free(cmd, virtscsi_cmd_pool);
return ret;
}
static int virtscsi_device_reset(struct scsi_cmnd *sc)
{
struct virtio_scsi *vscsi = shost_priv(sc->device->host);
struct virtio_scsi_cmd *cmd;
sdev_printk(KERN_INFO, sc->device, "device reset\n");
cmd = mempool_alloc(virtscsi_cmd_pool, GFP_NOIO);
if (!cmd)
return FAILED;
memset(cmd, 0, sizeof(*cmd));
cmd->sc = sc;
cmd->req.tmf = (struct virtio_scsi_ctrl_tmf_req){
.type = VIRTIO_SCSI_T_TMF,
.subtype = cpu_to_virtio32(vscsi->vdev,
VIRTIO_SCSI_T_TMF_LOGICAL_UNIT_RESET),
.lun[0] = 1,
.lun[1] = sc->device->id,
.lun[2] = (sc->device->lun >> 8) | 0x40,
.lun[3] = sc->device->lun & 0xff,
};
return virtscsi_tmf(vscsi, cmd);
}
static int virtscsi_device_alloc(struct scsi_device *sdevice)
{
sdevice->sdev_bflags = BLIST_TRY_VPD_PAGES;
return 0;
}
static int virtscsi_change_queue_depth(struct scsi_device *sdev, int qdepth)
{
struct Scsi_Host *shost = sdev->host;
int max_depth = shost->cmd_per_lun;
return scsi_change_queue_depth(sdev, min(max_depth, qdepth));
}
static int virtscsi_abort(struct scsi_cmnd *sc)
{
struct virtio_scsi *vscsi = shost_priv(sc->device->host);
struct virtio_scsi_cmd *cmd;
scmd_printk(KERN_INFO, sc, "abort\n");
cmd = mempool_alloc(virtscsi_cmd_pool, GFP_NOIO);
if (!cmd)
return FAILED;
memset(cmd, 0, sizeof(*cmd));
cmd->sc = sc;
cmd->req.tmf = (struct virtio_scsi_ctrl_tmf_req){
.type = VIRTIO_SCSI_T_TMF,
.subtype = VIRTIO_SCSI_T_TMF_ABORT_TASK,
.lun[0] = 1,
.lun[1] = sc->device->id,
.lun[2] = (sc->device->lun >> 8) | 0x40,
.lun[3] = sc->device->lun & 0xff,
.tag = cpu_to_virtio64(vscsi->vdev, (unsigned long)sc),
};
return virtscsi_tmf(vscsi, cmd);
}
static int virtscsi_target_alloc(struct scsi_target *starget)
{
struct Scsi_Host *sh = dev_to_shost(starget->dev.parent);
struct virtio_scsi *vscsi = shost_priv(sh);
struct virtio_scsi_target_state *tgt =
kmalloc(sizeof(*tgt), GFP_KERNEL);
if (!tgt)
return -ENOMEM;
seqcount_init(&tgt->tgt_seq);
atomic_set(&tgt->reqs, 0);
tgt->req_vq = &vscsi->req_vqs[0];
starget->hostdata = tgt;
return 0;
}
static void virtscsi_target_destroy(struct scsi_target *starget)
{
struct virtio_scsi_target_state *tgt = starget->hostdata;
kfree(tgt);
}
static int virtscsi_map_queues(struct Scsi_Host *shost)
{
struct virtio_scsi *vscsi = shost_priv(shost);
return blk_mq_virtio_map_queues(&shost->tag_set, vscsi->vdev, 2);
}
static enum blk_eh_timer_return virtscsi_eh_timed_out(struct scsi_cmnd *scmnd)
{
return BLK_EH_RESET_TIMER;
}
static void virtscsi_init_vq(struct virtio_scsi_vq *virtscsi_vq,
struct virtqueue *vq)
{
spin_lock_init(&virtscsi_vq->vq_lock);
virtscsi_vq->vq = vq;
}
static void virtscsi_remove_vqs(struct virtio_device *vdev)
{
vdev->config->reset(vdev);
vdev->config->del_vqs(vdev);
}
static int virtscsi_init(struct virtio_device *vdev,
struct virtio_scsi *vscsi)
{
int err;
u32 i;
u32 num_vqs;
vq_callback_t **callbacks;
const char **names;
struct virtqueue **vqs;
struct irq_affinity desc = { .pre_vectors = 2 };
num_vqs = vscsi->num_queues + VIRTIO_SCSI_VQ_BASE;
vqs = kmalloc(num_vqs * sizeof(struct virtqueue *), GFP_KERNEL);
callbacks = kmalloc(num_vqs * sizeof(vq_callback_t *), GFP_KERNEL);
names = kmalloc(num_vqs * sizeof(char *), GFP_KERNEL);
if (!callbacks || !vqs || !names) {
err = -ENOMEM;
goto out;
}
callbacks[0] = virtscsi_ctrl_done;
callbacks[1] = virtscsi_event_done;
names[0] = "control";
names[1] = "event";
for (i = VIRTIO_SCSI_VQ_BASE; i < num_vqs; i++) {
callbacks[i] = virtscsi_req_done;
names[i] = "request";
}
err = virtio_find_vqs(vdev, num_vqs, vqs, callbacks, names, &desc);
if (err)
goto out;
virtscsi_init_vq(&vscsi->ctrl_vq, vqs[0]);
virtscsi_init_vq(&vscsi->event_vq, vqs[1]);
for (i = VIRTIO_SCSI_VQ_BASE; i < num_vqs; i++)
virtscsi_init_vq(&vscsi->req_vqs[i - VIRTIO_SCSI_VQ_BASE],
vqs[i]);
virtscsi_config_set(vdev, cdb_size, VIRTIO_SCSI_CDB_SIZE);
virtscsi_config_set(vdev, sense_size, VIRTIO_SCSI_SENSE_SIZE);
err = 0;
out:
kfree(names);
kfree(callbacks);
kfree(vqs);
if (err)
virtscsi_remove_vqs(vdev);
return err;
}
static int virtscsi_probe(struct virtio_device *vdev)
{
struct Scsi_Host *shost;
struct virtio_scsi *vscsi;
int err;
u32 sg_elems, num_targets;
u32 cmd_per_lun;
u32 num_queues;
struct scsi_host_template *hostt;
if (!vdev->config->get) {
dev_err(&vdev->dev, "%s failure: config access disabled\n",
__func__);
return -EINVAL;
}
num_queues = virtscsi_config_get(vdev, num_queues) ? : 1;
num_targets = virtscsi_config_get(vdev, max_target) + 1;
if (num_queues == 1)
hostt = &virtscsi_host_template_single;
else
hostt = &virtscsi_host_template_multi;
shost = scsi_host_alloc(hostt,
sizeof(*vscsi) + sizeof(vscsi->req_vqs[0]) * num_queues);
if (!shost)
return -ENOMEM;
sg_elems = virtscsi_config_get(vdev, seg_max) ?: 1;
shost->sg_tablesize = sg_elems;
vscsi = shost_priv(shost);
vscsi->vdev = vdev;
vscsi->num_queues = num_queues;
vdev->priv = shost;
err = virtscsi_init(vdev, vscsi);
if (err)
goto virtscsi_init_failed;
cmd_per_lun = virtscsi_config_get(vdev, cmd_per_lun) ?: 1;
shost->cmd_per_lun = min_t(u32, cmd_per_lun, shost->can_queue);
shost->max_sectors = virtscsi_config_get(vdev, max_sectors) ?: 0xFFFF;
shost->max_lun = virtscsi_config_get(vdev, max_lun) + 1 + 0x4000;
shost->max_id = num_targets;
shost->max_channel = 0;
shost->max_cmd_len = VIRTIO_SCSI_CDB_SIZE;
shost->nr_hw_queues = num_queues;
#ifdef CONFIG_BLK_DEV_INTEGRITY
if (virtio_has_feature(vdev, VIRTIO_SCSI_F_T10_PI)) {
int host_prot;
host_prot = SHOST_DIF_TYPE1_PROTECTION | SHOST_DIF_TYPE2_PROTECTION |
SHOST_DIF_TYPE3_PROTECTION | SHOST_DIX_TYPE1_PROTECTION |
SHOST_DIX_TYPE2_PROTECTION | SHOST_DIX_TYPE3_PROTECTION;
scsi_host_set_prot(shost, host_prot);
scsi_host_set_guard(shost, SHOST_DIX_GUARD_CRC);
}
#endif
err = scsi_add_host(shost, &vdev->dev);
if (err)
goto scsi_add_host_failed;
virtio_device_ready(vdev);
if (virtio_has_feature(vdev, VIRTIO_SCSI_F_HOTPLUG))
virtscsi_kick_event_all(vscsi);
scsi_scan_host(shost);
return 0;
scsi_add_host_failed:
vdev->config->del_vqs(vdev);
virtscsi_init_failed:
scsi_host_put(shost);
return err;
}
static void virtscsi_remove(struct virtio_device *vdev)
{
struct Scsi_Host *shost = virtio_scsi_host(vdev);
struct virtio_scsi *vscsi = shost_priv(shost);
if (virtio_has_feature(vdev, VIRTIO_SCSI_F_HOTPLUG))
virtscsi_cancel_event_work(vscsi);
scsi_remove_host(shost);
virtscsi_remove_vqs(vdev);
scsi_host_put(shost);
}
static int virtscsi_freeze(struct virtio_device *vdev)
{
virtscsi_remove_vqs(vdev);
return 0;
}
static int virtscsi_restore(struct virtio_device *vdev)
{
struct Scsi_Host *sh = virtio_scsi_host(vdev);
struct virtio_scsi *vscsi = shost_priv(sh);
int err;
err = virtscsi_init(vdev, vscsi);
if (err)
return err;
virtio_device_ready(vdev);
if (virtio_has_feature(vdev, VIRTIO_SCSI_F_HOTPLUG))
virtscsi_kick_event_all(vscsi);
return err;
}
static int __init init(void)
{
int ret = -ENOMEM;
virtscsi_cmd_cache = KMEM_CACHE(virtio_scsi_cmd, 0);
if (!virtscsi_cmd_cache) {
pr_err("kmem_cache_create() for virtscsi_cmd_cache failed\n");
goto error;
}
virtscsi_cmd_pool =
mempool_create_slab_pool(VIRTIO_SCSI_MEMPOOL_SZ,
virtscsi_cmd_cache);
if (!virtscsi_cmd_pool) {
pr_err("mempool_create() for virtscsi_cmd_pool failed\n");
goto error;
}
ret = register_virtio_driver(&virtio_scsi_driver);
if (ret < 0)
goto error;
return 0;
error:
if (virtscsi_cmd_pool) {
mempool_destroy(virtscsi_cmd_pool);
virtscsi_cmd_pool = NULL;
}
if (virtscsi_cmd_cache) {
kmem_cache_destroy(virtscsi_cmd_cache);
virtscsi_cmd_cache = NULL;
}
return ret;
}
static void __exit fini(void)
{
unregister_virtio_driver(&virtio_scsi_driver);
mempool_destroy(virtscsi_cmd_pool);
kmem_cache_destroy(virtscsi_cmd_cache);
}
