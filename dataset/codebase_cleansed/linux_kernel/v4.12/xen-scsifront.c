static void scsifront_wake_up(struct vscsifrnt_info *info)
{
info->wait_ring_available = 0;
wake_up(&info->wq_sync);
}
static int scsifront_get_rqid(struct vscsifrnt_info *info)
{
unsigned long flags;
int free;
spin_lock_irqsave(&info->shadow_lock, flags);
free = find_first_bit(info->shadow_free_bitmap, VSCSIIF_MAX_REQS);
__clear_bit(free, info->shadow_free_bitmap);
spin_unlock_irqrestore(&info->shadow_lock, flags);
return free;
}
static int _scsifront_put_rqid(struct vscsifrnt_info *info, uint32_t id)
{
int empty = bitmap_empty(info->shadow_free_bitmap, VSCSIIF_MAX_REQS);
__set_bit(id, info->shadow_free_bitmap);
info->shadow[id] = NULL;
return empty || info->wait_ring_available;
}
static void scsifront_put_rqid(struct vscsifrnt_info *info, uint32_t id)
{
unsigned long flags;
int kick;
spin_lock_irqsave(&info->shadow_lock, flags);
kick = _scsifront_put_rqid(info, id);
spin_unlock_irqrestore(&info->shadow_lock, flags);
if (kick)
scsifront_wake_up(info);
}
static int scsifront_do_request(struct vscsifrnt_info *info,
struct vscsifrnt_shadow *shadow)
{
struct vscsiif_front_ring *ring = &(info->ring);
struct vscsiif_request *ring_req;
struct scsi_cmnd *sc = shadow->sc;
uint32_t id;
int i, notify;
if (RING_FULL(&info->ring))
return -EBUSY;
id = scsifront_get_rqid(info);
if (id >= VSCSIIF_MAX_REQS)
return -EBUSY;
info->shadow[id] = shadow;
shadow->rqid = id;
ring_req = RING_GET_REQUEST(&(info->ring), ring->req_prod_pvt);
ring->req_prod_pvt++;
ring_req->rqid = id;
ring_req->act = shadow->act;
ring_req->ref_rqid = shadow->ref_rqid;
ring_req->nr_segments = shadow->nr_segments;
ring_req->id = sc->device->id;
ring_req->lun = sc->device->lun;
ring_req->channel = sc->device->channel;
ring_req->cmd_len = sc->cmd_len;
BUG_ON(sc->cmd_len > VSCSIIF_MAX_COMMAND_SIZE);
memcpy(ring_req->cmnd, sc->cmnd, sc->cmd_len);
ring_req->sc_data_direction = (uint8_t)sc->sc_data_direction;
ring_req->timeout_per_command = sc->request->timeout / HZ;
for (i = 0; i < (shadow->nr_segments & ~VSCSIIF_SG_GRANT); i++)
ring_req->seg[i] = shadow->seg[i];
RING_PUSH_REQUESTS_AND_CHECK_NOTIFY(ring, notify);
if (notify)
notify_remote_via_irq(info->irq);
return 0;
}
static void scsifront_gnttab_done(struct vscsifrnt_info *info,
struct vscsifrnt_shadow *shadow)
{
int i;
if (shadow->sc->sc_data_direction == DMA_NONE)
return;
for (i = 0; i < shadow->nr_grants; i++) {
if (unlikely(gnttab_query_foreign_access(shadow->gref[i]))) {
shost_printk(KERN_ALERT, info->host, KBUILD_MODNAME
"grant still in use by backend\n");
BUG();
}
gnttab_end_foreign_access(shadow->gref[i], 0, 0UL);
}
kfree(shadow->sg);
}
static void scsifront_cdb_cmd_done(struct vscsifrnt_info *info,
struct vscsiif_response *ring_rsp)
{
struct vscsifrnt_shadow *shadow;
struct scsi_cmnd *sc;
uint32_t id;
uint8_t sense_len;
id = ring_rsp->rqid;
shadow = info->shadow[id];
sc = shadow->sc;
BUG_ON(sc == NULL);
scsifront_gnttab_done(info, shadow);
scsifront_put_rqid(info, id);
sc->result = ring_rsp->rslt;
scsi_set_resid(sc, ring_rsp->residual_len);
sense_len = min_t(uint8_t, VSCSIIF_SENSE_BUFFERSIZE,
ring_rsp->sense_len);
if (sense_len)
memcpy(sc->sense_buffer, ring_rsp->sense_buffer, sense_len);
sc->scsi_done(sc);
}
static void scsifront_sync_cmd_done(struct vscsifrnt_info *info,
struct vscsiif_response *ring_rsp)
{
uint16_t id = ring_rsp->rqid;
unsigned long flags;
struct vscsifrnt_shadow *shadow = info->shadow[id];
int kick;
spin_lock_irqsave(&info->shadow_lock, flags);
shadow->wait_reset = 1;
switch (shadow->rslt_reset) {
case RSLT_RESET_WAITING:
shadow->rslt_reset = ring_rsp->rslt;
break;
case RSLT_RESET_ERR:
kick = _scsifront_put_rqid(info, id);
spin_unlock_irqrestore(&info->shadow_lock, flags);
kfree(shadow);
if (kick)
scsifront_wake_up(info);
return;
default:
shost_printk(KERN_ERR, info->host, KBUILD_MODNAME
"bad reset state %d, possibly leaking %u\n",
shadow->rslt_reset, id);
break;
}
spin_unlock_irqrestore(&info->shadow_lock, flags);
wake_up(&shadow->wq_reset);
}
static void scsifront_do_response(struct vscsifrnt_info *info,
struct vscsiif_response *ring_rsp)
{
if (WARN(ring_rsp->rqid >= VSCSIIF_MAX_REQS ||
test_bit(ring_rsp->rqid, info->shadow_free_bitmap),
"illegal rqid %u returned by backend!\n", ring_rsp->rqid))
return;
if (info->shadow[ring_rsp->rqid]->act == VSCSIIF_ACT_SCSI_CDB)
scsifront_cdb_cmd_done(info, ring_rsp);
else
scsifront_sync_cmd_done(info, ring_rsp);
}
static int scsifront_ring_drain(struct vscsifrnt_info *info)
{
struct vscsiif_response *ring_rsp;
RING_IDX i, rp;
int more_to_do = 0;
rp = info->ring.sring->rsp_prod;
rmb();
for (i = info->ring.rsp_cons; i != rp; i++) {
ring_rsp = RING_GET_RESPONSE(&info->ring, i);
scsifront_do_response(info, ring_rsp);
}
info->ring.rsp_cons = i;
if (i != info->ring.req_prod_pvt)
RING_FINAL_CHECK_FOR_RESPONSES(&info->ring, more_to_do);
else
info->ring.sring->rsp_event = i + 1;
return more_to_do;
}
static int scsifront_cmd_done(struct vscsifrnt_info *info)
{
int more_to_do;
unsigned long flags;
spin_lock_irqsave(info->host->host_lock, flags);
more_to_do = scsifront_ring_drain(info);
info->wait_ring_available = 0;
spin_unlock_irqrestore(info->host->host_lock, flags);
wake_up(&info->wq_sync);
return more_to_do;
}
static irqreturn_t scsifront_irq_fn(int irq, void *dev_id)
{
struct vscsifrnt_info *info = dev_id;
while (scsifront_cmd_done(info))
cond_resched();
return IRQ_HANDLED;
}
static void scsifront_finish_all(struct vscsifrnt_info *info)
{
unsigned i;
struct vscsiif_response resp;
scsifront_ring_drain(info);
for (i = 0; i < VSCSIIF_MAX_REQS; i++) {
if (test_bit(i, info->shadow_free_bitmap))
continue;
resp.rqid = i;
resp.sense_len = 0;
resp.rslt = DID_RESET << 16;
resp.residual_len = 0;
scsifront_do_response(info, &resp);
}
}
static int map_data_for_request(struct vscsifrnt_info *info,
struct scsi_cmnd *sc,
struct vscsifrnt_shadow *shadow)
{
grant_ref_t gref_head;
struct page *page;
int err, ref, ref_cnt = 0;
int grant_ro = (sc->sc_data_direction == DMA_TO_DEVICE);
unsigned int i, off, len, bytes;
unsigned int data_len = scsi_bufflen(sc);
unsigned int data_grants = 0, seg_grants = 0;
struct scatterlist *sg;
struct scsiif_request_segment *seg;
if (sc->sc_data_direction == DMA_NONE || !data_len)
return 0;
scsi_for_each_sg(sc, sg, scsi_sg_count(sc), i)
data_grants += PFN_UP(sg->offset + sg->length);
if (data_grants > VSCSIIF_SG_TABLESIZE) {
if (data_grants > info->host->sg_tablesize) {
shost_printk(KERN_ERR, info->host, KBUILD_MODNAME
"Unable to map request_buffer for command!\n");
return -E2BIG;
}
seg_grants = vscsiif_grants_sg(data_grants);
shadow->sg = kcalloc(data_grants,
sizeof(struct scsiif_request_segment), GFP_ATOMIC);
if (!shadow->sg)
return -ENOMEM;
}
seg = shadow->sg ? : shadow->seg;
err = gnttab_alloc_grant_references(seg_grants + data_grants,
&gref_head);
if (err) {
kfree(shadow->sg);
shost_printk(KERN_ERR, info->host, KBUILD_MODNAME
"gnttab_alloc_grant_references() error\n");
return -ENOMEM;
}
if (seg_grants) {
page = virt_to_page(seg);
off = offset_in_page(seg);
len = sizeof(struct scsiif_request_segment) * data_grants;
while (len > 0) {
bytes = min_t(unsigned int, len, PAGE_SIZE - off);
ref = gnttab_claim_grant_reference(&gref_head);
BUG_ON(ref == -ENOSPC);
gnttab_grant_foreign_access_ref(ref,
info->dev->otherend_id,
xen_page_to_gfn(page), 1);
shadow->gref[ref_cnt] = ref;
shadow->seg[ref_cnt].gref = ref;
shadow->seg[ref_cnt].offset = (uint16_t)off;
shadow->seg[ref_cnt].length = (uint16_t)bytes;
page++;
len -= bytes;
off = 0;
ref_cnt++;
}
BUG_ON(seg_grants < ref_cnt);
seg_grants = ref_cnt;
}
scsi_for_each_sg(sc, sg, scsi_sg_count(sc), i) {
page = sg_page(sg);
off = sg->offset;
len = sg->length;
while (len > 0 && data_len > 0) {
bytes = min_t(unsigned int, len, PAGE_SIZE - off);
bytes = min(bytes, data_len);
ref = gnttab_claim_grant_reference(&gref_head);
BUG_ON(ref == -ENOSPC);
gnttab_grant_foreign_access_ref(ref,
info->dev->otherend_id,
xen_page_to_gfn(page),
grant_ro);
shadow->gref[ref_cnt] = ref;
seg->gref = ref;
seg->offset = (uint16_t)off;
seg->length = (uint16_t)bytes;
page++;
seg++;
len -= bytes;
data_len -= bytes;
off = 0;
ref_cnt++;
}
}
if (seg_grants)
shadow->nr_segments = VSCSIIF_SG_GRANT | seg_grants;
else
shadow->nr_segments = (uint8_t)ref_cnt;
shadow->nr_grants = ref_cnt;
return 0;
}
static int scsifront_enter(struct vscsifrnt_info *info)
{
if (info->pause)
return 1;
info->callers++;
return 0;
}
static void scsifront_return(struct vscsifrnt_info *info)
{
info->callers--;
if (info->callers)
return;
if (!info->waiting_pause)
return;
info->waiting_pause = 0;
wake_up(&info->wq_pause);
}
static int scsifront_queuecommand(struct Scsi_Host *shost,
struct scsi_cmnd *sc)
{
struct vscsifrnt_info *info = shost_priv(shost);
struct vscsifrnt_shadow *shadow = scsi_cmd_priv(sc);
unsigned long flags;
int err;
sc->result = 0;
memset(shadow, 0, sizeof(*shadow));
shadow->sc = sc;
shadow->act = VSCSIIF_ACT_SCSI_CDB;
spin_lock_irqsave(shost->host_lock, flags);
if (scsifront_enter(info)) {
spin_unlock_irqrestore(shost->host_lock, flags);
return SCSI_MLQUEUE_HOST_BUSY;
}
err = map_data_for_request(info, sc, shadow);
if (err < 0) {
pr_debug("%s: err %d\n", __func__, err);
scsifront_return(info);
spin_unlock_irqrestore(shost->host_lock, flags);
if (err == -ENOMEM)
return SCSI_MLQUEUE_HOST_BUSY;
sc->result = DID_ERROR << 16;
sc->scsi_done(sc);
return 0;
}
if (scsifront_do_request(info, shadow)) {
scsifront_gnttab_done(info, shadow);
goto busy;
}
scsifront_return(info);
spin_unlock_irqrestore(shost->host_lock, flags);
return 0;
busy:
scsifront_return(info);
spin_unlock_irqrestore(shost->host_lock, flags);
pr_debug("%s: busy\n", __func__);
return SCSI_MLQUEUE_HOST_BUSY;
}
static int scsifront_action_handler(struct scsi_cmnd *sc, uint8_t act)
{
struct Scsi_Host *host = sc->device->host;
struct vscsifrnt_info *info = shost_priv(host);
struct vscsifrnt_shadow *shadow, *s = scsi_cmd_priv(sc);
int err = 0;
shadow = kzalloc(sizeof(*shadow), GFP_NOIO);
if (!shadow)
return FAILED;
shadow->act = act;
shadow->rslt_reset = RSLT_RESET_WAITING;
shadow->sc = sc;
shadow->ref_rqid = s->rqid;
init_waitqueue_head(&shadow->wq_reset);
spin_lock_irq(host->host_lock);
for (;;) {
if (scsifront_enter(info))
goto fail;
if (!scsifront_do_request(info, shadow))
break;
scsifront_return(info);
if (err)
goto fail;
info->wait_ring_available = 1;
spin_unlock_irq(host->host_lock);
err = wait_event_interruptible(info->wq_sync,
!info->wait_ring_available);
spin_lock_irq(host->host_lock);
}
spin_unlock_irq(host->host_lock);
err = wait_event_interruptible(shadow->wq_reset, shadow->wait_reset);
spin_lock_irq(host->host_lock);
if (!err) {
err = shadow->rslt_reset;
scsifront_put_rqid(info, shadow->rqid);
kfree(shadow);
} else {
spin_lock(&info->shadow_lock);
shadow->rslt_reset = RSLT_RESET_ERR;
spin_unlock(&info->shadow_lock);
err = FAILED;
}
scsifront_return(info);
spin_unlock_irq(host->host_lock);
return err;
fail:
spin_unlock_irq(host->host_lock);
kfree(shadow);
return FAILED;
}
static int scsifront_eh_abort_handler(struct scsi_cmnd *sc)
{
pr_debug("%s\n", __func__);
return scsifront_action_handler(sc, VSCSIIF_ACT_SCSI_ABORT);
}
static int scsifront_dev_reset_handler(struct scsi_cmnd *sc)
{
pr_debug("%s\n", __func__);
return scsifront_action_handler(sc, VSCSIIF_ACT_SCSI_RESET);
}
static int scsifront_sdev_configure(struct scsi_device *sdev)
{
struct vscsifrnt_info *info = shost_priv(sdev->host);
if (info && current == info->curr)
xenbus_printf(XBT_NIL, info->dev->nodename,
info->dev_state_path, "%d", XenbusStateConnected);
return 0;
}
static void scsifront_sdev_destroy(struct scsi_device *sdev)
{
struct vscsifrnt_info *info = shost_priv(sdev->host);
if (info && current == info->curr)
xenbus_printf(XBT_NIL, info->dev->nodename,
info->dev_state_path, "%d", XenbusStateClosed);
}
static int scsifront_alloc_ring(struct vscsifrnt_info *info)
{
struct xenbus_device *dev = info->dev;
struct vscsiif_sring *sring;
grant_ref_t gref;
int err = -ENOMEM;
sring = (struct vscsiif_sring *)__get_free_page(GFP_KERNEL);
if (!sring) {
xenbus_dev_fatal(dev, err,
"fail to allocate shared ring (Front to Back)");
return err;
}
SHARED_RING_INIT(sring);
FRONT_RING_INIT(&info->ring, sring, PAGE_SIZE);
err = xenbus_grant_ring(dev, sring, 1, &gref);
if (err < 0) {
free_page((unsigned long)sring);
xenbus_dev_fatal(dev, err,
"fail to grant shared ring (Front to Back)");
return err;
}
info->ring_ref = gref;
err = xenbus_alloc_evtchn(dev, &info->evtchn);
if (err) {
xenbus_dev_fatal(dev, err, "xenbus_alloc_evtchn");
goto free_gnttab;
}
err = bind_evtchn_to_irq(info->evtchn);
if (err <= 0) {
xenbus_dev_fatal(dev, err, "bind_evtchn_to_irq");
goto free_gnttab;
}
info->irq = err;
err = request_threaded_irq(info->irq, NULL, scsifront_irq_fn,
IRQF_ONESHOT, "scsifront", info);
if (err) {
xenbus_dev_fatal(dev, err, "request_threaded_irq");
goto free_irq;
}
return 0;
free_irq:
unbind_from_irqhandler(info->irq, info);
free_gnttab:
gnttab_end_foreign_access(info->ring_ref, 0,
(unsigned long)info->ring.sring);
return err;
}
static void scsifront_free_ring(struct vscsifrnt_info *info)
{
unbind_from_irqhandler(info->irq, info);
gnttab_end_foreign_access(info->ring_ref, 0,
(unsigned long)info->ring.sring);
}
static int scsifront_init_ring(struct vscsifrnt_info *info)
{
struct xenbus_device *dev = info->dev;
struct xenbus_transaction xbt;
int err;
pr_debug("%s\n", __func__);
err = scsifront_alloc_ring(info);
if (err)
return err;
pr_debug("%s: %u %u\n", __func__, info->ring_ref, info->evtchn);
again:
err = xenbus_transaction_start(&xbt);
if (err)
xenbus_dev_fatal(dev, err, "starting transaction");
err = xenbus_printf(xbt, dev->nodename, "ring-ref", "%u",
info->ring_ref);
if (err) {
xenbus_dev_fatal(dev, err, "%s", "writing ring-ref");
goto fail;
}
err = xenbus_printf(xbt, dev->nodename, "event-channel", "%u",
info->evtchn);
if (err) {
xenbus_dev_fatal(dev, err, "%s", "writing event-channel");
goto fail;
}
err = xenbus_transaction_end(xbt, 0);
if (err) {
if (err == -EAGAIN)
goto again;
xenbus_dev_fatal(dev, err, "completing transaction");
goto free_sring;
}
return 0;
fail:
xenbus_transaction_end(xbt, 1);
free_sring:
scsifront_free_ring(info);
return err;
}
static int scsifront_probe(struct xenbus_device *dev,
const struct xenbus_device_id *id)
{
struct vscsifrnt_info *info;
struct Scsi_Host *host;
int err = -ENOMEM;
char name[TASK_COMM_LEN];
host = scsi_host_alloc(&scsifront_sht, sizeof(*info));
if (!host) {
xenbus_dev_fatal(dev, err, "fail to allocate scsi host");
return err;
}
info = (struct vscsifrnt_info *)host->hostdata;
dev_set_drvdata(&dev->dev, info);
info->dev = dev;
bitmap_fill(info->shadow_free_bitmap, VSCSIIF_MAX_REQS);
err = scsifront_init_ring(info);
if (err) {
scsi_host_put(host);
return err;
}
init_waitqueue_head(&info->wq_sync);
init_waitqueue_head(&info->wq_pause);
spin_lock_init(&info->shadow_lock);
snprintf(name, TASK_COMM_LEN, "vscsiif.%d", host->host_no);
host->max_id = VSCSIIF_MAX_TARGET;
host->max_channel = 0;
host->max_lun = VSCSIIF_MAX_LUN;
host->max_sectors = (host->sg_tablesize - 1) * PAGE_SIZE / 512;
host->max_cmd_len = VSCSIIF_MAX_COMMAND_SIZE;
err = scsi_add_host(host, &dev->dev);
if (err) {
dev_err(&dev->dev, "fail to add scsi host %d\n", err);
goto free_sring;
}
info->host = host;
info->host_active = 1;
xenbus_switch_state(dev, XenbusStateInitialised);
return 0;
free_sring:
scsifront_free_ring(info);
scsi_host_put(host);
return err;
}
static int scsifront_resume(struct xenbus_device *dev)
{
struct vscsifrnt_info *info = dev_get_drvdata(&dev->dev);
struct Scsi_Host *host = info->host;
int err;
spin_lock_irq(host->host_lock);
scsifront_finish_all(info);
spin_unlock_irq(host->host_lock);
scsifront_free_ring(info);
err = scsifront_init_ring(info);
if (err) {
dev_err(&dev->dev, "fail to resume %d\n", err);
scsi_host_put(host);
return err;
}
xenbus_switch_state(dev, XenbusStateInitialised);
return 0;
}
static int scsifront_suspend(struct xenbus_device *dev)
{
struct vscsifrnt_info *info = dev_get_drvdata(&dev->dev);
struct Scsi_Host *host = info->host;
int err = 0;
spin_lock_irq(host->host_lock);
info->pause = 1;
while (info->callers && !err) {
info->waiting_pause = 1;
info->wait_ring_available = 0;
spin_unlock_irq(host->host_lock);
wake_up(&info->wq_sync);
err = wait_event_interruptible(info->wq_pause,
!info->waiting_pause);
spin_lock_irq(host->host_lock);
}
spin_unlock_irq(host->host_lock);
return err;
}
static int scsifront_remove(struct xenbus_device *dev)
{
struct vscsifrnt_info *info = dev_get_drvdata(&dev->dev);
pr_debug("%s: %s removed\n", __func__, dev->nodename);
mutex_lock(&scsifront_mutex);
if (info->host_active) {
scsi_remove_host(info->host);
info->host_active = 0;
}
mutex_unlock(&scsifront_mutex);
scsifront_free_ring(info);
scsi_host_put(info->host);
return 0;
}
static void scsifront_disconnect(struct vscsifrnt_info *info)
{
struct xenbus_device *dev = info->dev;
struct Scsi_Host *host = info->host;
pr_debug("%s: %s disconnect\n", __func__, dev->nodename);
mutex_lock(&scsifront_mutex);
if (info->host_active) {
scsi_remove_host(host);
info->host_active = 0;
}
mutex_unlock(&scsifront_mutex);
xenbus_frontend_closed(dev);
}
static void scsifront_do_lun_hotplug(struct vscsifrnt_info *info, int op)
{
struct xenbus_device *dev = info->dev;
int i, err = 0;
char str[64];
char **dir;
unsigned int dir_n = 0;
unsigned int device_state;
unsigned int hst, chn, tgt, lun;
struct scsi_device *sdev;
dir = xenbus_directory(XBT_NIL, dev->otherend, "vscsi-devs", &dir_n);
if (IS_ERR(dir))
return;
BUG_ON(info->curr);
info->curr = current;
for (i = 0; i < dir_n; i++) {
snprintf(str, sizeof(str), "vscsi-devs/%s/state", dir[i]);
err = xenbus_scanf(XBT_NIL, dev->otherend, str, "%u",
&device_state);
if (XENBUS_EXIST_ERR(err))
continue;
snprintf(str, sizeof(str), "vscsi-devs/%s/v-dev", dir[i]);
err = xenbus_scanf(XBT_NIL, dev->otherend, str,
"%u:%u:%u:%u", &hst, &chn, &tgt, &lun);
if (XENBUS_EXIST_ERR(err))
continue;
snprintf(info->dev_state_path, sizeof(info->dev_state_path),
"vscsi-devs/%s/state", dir[i]);
switch (op) {
case VSCSIFRONT_OP_ADD_LUN:
if (device_state != XenbusStateInitialised)
break;
if (scsi_add_device(info->host, chn, tgt, lun)) {
dev_err(&dev->dev, "scsi_add_device\n");
xenbus_printf(XBT_NIL, dev->nodename,
info->dev_state_path,
"%d", XenbusStateClosed);
}
break;
case VSCSIFRONT_OP_DEL_LUN:
if (device_state != XenbusStateClosing)
break;
sdev = scsi_device_lookup(info->host, chn, tgt, lun);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
}
break;
case VSCSIFRONT_OP_READD_LUN:
if (device_state == XenbusStateConnected)
xenbus_printf(XBT_NIL, dev->nodename,
info->dev_state_path,
"%d", XenbusStateConnected);
break;
default:
break;
}
}
info->curr = NULL;
kfree(dir);
}
static void scsifront_read_backend_params(struct xenbus_device *dev,
struct vscsifrnt_info *info)
{
unsigned int sg_grant, nr_segs;
struct Scsi_Host *host = info->host;
sg_grant = xenbus_read_unsigned(dev->otherend, "feature-sg-grant", 0);
nr_segs = min_t(unsigned int, sg_grant, SG_ALL);
nr_segs = max_t(unsigned int, nr_segs, VSCSIIF_SG_TABLESIZE);
nr_segs = min_t(unsigned int, nr_segs,
VSCSIIF_SG_TABLESIZE * PAGE_SIZE /
sizeof(struct scsiif_request_segment));
if (!info->pause && sg_grant)
dev_info(&dev->dev, "using up to %d SG entries\n", nr_segs);
else if (info->pause && nr_segs < host->sg_tablesize)
dev_warn(&dev->dev,
"SG entries decreased from %d to %u - device may not work properly anymore\n",
host->sg_tablesize, nr_segs);
host->sg_tablesize = nr_segs;
host->max_sectors = (nr_segs - 1) * PAGE_SIZE / 512;
}
static void scsifront_backend_changed(struct xenbus_device *dev,
enum xenbus_state backend_state)
{
struct vscsifrnt_info *info = dev_get_drvdata(&dev->dev);
pr_debug("%s: %p %u %u\n", __func__, dev, dev->state, backend_state);
switch (backend_state) {
case XenbusStateUnknown:
case XenbusStateInitialising:
case XenbusStateInitWait:
case XenbusStateInitialised:
break;
case XenbusStateConnected:
scsifront_read_backend_params(dev, info);
if (info->pause) {
scsifront_do_lun_hotplug(info, VSCSIFRONT_OP_READD_LUN);
xenbus_switch_state(dev, XenbusStateConnected);
info->pause = 0;
return;
}
if (xenbus_read_driver_state(dev->nodename) ==
XenbusStateInitialised)
scsifront_do_lun_hotplug(info, VSCSIFRONT_OP_ADD_LUN);
if (dev->state != XenbusStateConnected)
xenbus_switch_state(dev, XenbusStateConnected);
break;
case XenbusStateClosed:
if (dev->state == XenbusStateClosed)
break;
case XenbusStateClosing:
scsifront_disconnect(info);
break;
case XenbusStateReconfiguring:
scsifront_do_lun_hotplug(info, VSCSIFRONT_OP_DEL_LUN);
xenbus_switch_state(dev, XenbusStateReconfiguring);
break;
case XenbusStateReconfigured:
scsifront_do_lun_hotplug(info, VSCSIFRONT_OP_ADD_LUN);
xenbus_switch_state(dev, XenbusStateConnected);
break;
}
}
static int __init scsifront_init(void)
{
if (!xen_domain())
return -ENODEV;
return xenbus_register_frontend(&scsifront_driver);
}
static void __exit scsifront_exit(void)
{
xenbus_unregister_driver(&scsifront_driver);
}
