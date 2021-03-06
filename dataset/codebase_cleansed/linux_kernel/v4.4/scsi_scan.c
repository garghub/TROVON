int scsi_complete_async_scans(void)
{
struct async_scan_data *data;
do {
if (list_empty(&scanning_hosts))
return 0;
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
msleep(1);
} while (!data);
data->shost = NULL;
init_completion(&data->prev_finished);
spin_lock(&async_scan_lock);
if (list_empty(&scanning_hosts))
goto done;
list_add_tail(&data->list, &scanning_hosts);
spin_unlock(&async_scan_lock);
printk(KERN_INFO "scsi: waiting for bus probes to complete ...\n");
wait_for_completion(&data->prev_finished);
spin_lock(&async_scan_lock);
list_del(&data->list);
if (!list_empty(&scanning_hosts)) {
struct async_scan_data *next = list_entry(scanning_hosts.next,
struct async_scan_data, list);
complete(&next->prev_finished);
}
done:
spin_unlock(&async_scan_lock);
kfree(data);
return 0;
}
static void scsi_unlock_floptical(struct scsi_device *sdev,
unsigned char *result)
{
unsigned char scsi_cmd[MAX_COMMAND_SIZE];
sdev_printk(KERN_NOTICE, sdev, "unlocking floptical drive\n");
scsi_cmd[0] = MODE_SENSE;
scsi_cmd[1] = 0;
scsi_cmd[2] = 0x2e;
scsi_cmd[3] = 0;
scsi_cmd[4] = 0x2a;
scsi_cmd[5] = 0;
scsi_execute_req(sdev, scsi_cmd, DMA_FROM_DEVICE, result, 0x2a, NULL,
SCSI_TIMEOUT, 3, NULL);
}
static struct scsi_device *scsi_alloc_sdev(struct scsi_target *starget,
u64 lun, void *hostdata)
{
struct scsi_device *sdev;
int display_failure_msg = 1, ret;
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
extern void scsi_evt_thread(struct work_struct *work);
extern void scsi_requeue_run_queue(struct work_struct *work);
sdev = kzalloc(sizeof(*sdev) + shost->transportt->device_size,
GFP_ATOMIC);
if (!sdev)
goto out;
sdev->vendor = scsi_null_device_strs;
sdev->model = scsi_null_device_strs;
sdev->rev = scsi_null_device_strs;
sdev->host = shost;
sdev->queue_ramp_up_period = SCSI_DEFAULT_RAMP_UP_PERIOD;
sdev->id = starget->id;
sdev->lun = lun;
sdev->channel = starget->channel;
sdev->sdev_state = SDEV_CREATED;
INIT_LIST_HEAD(&sdev->siblings);
INIT_LIST_HEAD(&sdev->same_target_siblings);
INIT_LIST_HEAD(&sdev->cmd_list);
INIT_LIST_HEAD(&sdev->starved_entry);
INIT_LIST_HEAD(&sdev->event_list);
spin_lock_init(&sdev->list_lock);
INIT_WORK(&sdev->event_work, scsi_evt_thread);
INIT_WORK(&sdev->requeue_work, scsi_requeue_run_queue);
sdev->sdev_gendev.parent = get_device(&starget->dev);
sdev->sdev_target = starget;
sdev->hostdata = hostdata;
sdev->max_device_blocked = SCSI_DEFAULT_DEVICE_BLOCKED;
sdev->type = -1;
sdev->borken = 1;
if (shost_use_blk_mq(shost))
sdev->request_queue = scsi_mq_alloc_queue(sdev);
else
sdev->request_queue = scsi_alloc_queue(sdev);
if (!sdev->request_queue) {
put_device(&starget->dev);
kfree(sdev);
goto out;
}
WARN_ON_ONCE(!blk_get_queue(sdev->request_queue));
sdev->request_queue->queuedata = sdev;
if (!shost_use_blk_mq(sdev->host)) {
blk_queue_init_tags(sdev->request_queue,
sdev->host->cmd_per_lun, shost->bqt,
shost->hostt->tag_alloc_policy);
}
scsi_change_queue_depth(sdev, sdev->host->cmd_per_lun ?
sdev->host->cmd_per_lun : 1);
scsi_sysfs_device_initialize(sdev);
if (shost->hostt->slave_alloc) {
ret = shost->hostt->slave_alloc(sdev);
if (ret) {
if (ret == -ENXIO)
display_failure_msg = 0;
goto out_device_destroy;
}
}
return sdev;
out_device_destroy:
__scsi_remove_device(sdev);
out:
if (display_failure_msg)
printk(ALLOC_FAILURE_MSG, __func__);
return NULL;
}
static void scsi_target_destroy(struct scsi_target *starget)
{
struct device *dev = &starget->dev;
struct Scsi_Host *shost = dev_to_shost(dev->parent);
unsigned long flags;
starget->state = STARGET_DEL;
transport_destroy_device(dev);
spin_lock_irqsave(shost->host_lock, flags);
if (shost->hostt->target_destroy)
shost->hostt->target_destroy(starget);
list_del_init(&starget->siblings);
spin_unlock_irqrestore(shost->host_lock, flags);
put_device(dev);
}
static void scsi_target_dev_release(struct device *dev)
{
struct device *parent = dev->parent;
struct scsi_target *starget = to_scsi_target(dev);
kfree(starget);
put_device(parent);
}
int scsi_is_target_device(const struct device *dev)
{
return dev->type == &scsi_target_type;
}
static struct scsi_target *__scsi_find_target(struct device *parent,
int channel, uint id)
{
struct scsi_target *starget, *found_starget = NULL;
struct Scsi_Host *shost = dev_to_shost(parent);
list_for_each_entry(starget, &shost->__targets, siblings) {
if (starget->id == id &&
starget->channel == channel) {
found_starget = starget;
break;
}
}
if (found_starget)
get_device(&found_starget->dev);
return found_starget;
}
static void scsi_target_reap_ref_release(struct kref *kref)
{
struct scsi_target *starget
= container_of(kref, struct scsi_target, reap_ref);
if (starget->state != STARGET_CREATED) {
transport_remove_device(&starget->dev);
device_del(&starget->dev);
}
scsi_target_destroy(starget);
}
static void scsi_target_reap_ref_put(struct scsi_target *starget)
{
kref_put(&starget->reap_ref, scsi_target_reap_ref_release);
}
static struct scsi_target *scsi_alloc_target(struct device *parent,
int channel, uint id)
{
struct Scsi_Host *shost = dev_to_shost(parent);
struct device *dev = NULL;
unsigned long flags;
const int size = sizeof(struct scsi_target)
+ shost->transportt->target_size;
struct scsi_target *starget;
struct scsi_target *found_target;
int error, ref_got;
starget = kzalloc(size, GFP_KERNEL);
if (!starget) {
printk(KERN_ERR "%s: allocation failure\n", __func__);
return NULL;
}
dev = &starget->dev;
device_initialize(dev);
kref_init(&starget->reap_ref);
dev->parent = get_device(parent);
dev_set_name(dev, "target%d:%d:%d", shost->host_no, channel, id);
dev->bus = &scsi_bus_type;
dev->type = &scsi_target_type;
starget->id = id;
starget->channel = channel;
starget->can_queue = 0;
INIT_LIST_HEAD(&starget->siblings);
INIT_LIST_HEAD(&starget->devices);
starget->state = STARGET_CREATED;
starget->scsi_level = SCSI_2;
starget->max_target_blocked = SCSI_DEFAULT_TARGET_BLOCKED;
retry:
spin_lock_irqsave(shost->host_lock, flags);
found_target = __scsi_find_target(parent, channel, id);
if (found_target)
goto found;
list_add_tail(&starget->siblings, &shost->__targets);
spin_unlock_irqrestore(shost->host_lock, flags);
transport_setup_device(dev);
if (shost->hostt->target_alloc) {
error = shost->hostt->target_alloc(starget);
if(error) {
dev_printk(KERN_ERR, dev, "target allocation failed, error %d\n", error);
scsi_target_destroy(starget);
return NULL;
}
}
get_device(dev);
return starget;
found:
ref_got = kref_get_unless_zero(&found_target->reap_ref);
spin_unlock_irqrestore(shost->host_lock, flags);
if (ref_got) {
put_device(dev);
return found_target;
}
put_device(&found_target->dev);
msleep(1);
goto retry;
}
void scsi_target_reap(struct scsi_target *starget)
{
BUG_ON(starget->state == STARGET_DEL);
scsi_target_reap_ref_put(starget);
}
static void sanitize_inquiry_string(unsigned char *s, int len)
{
int terminated = 0;
for (; len > 0; (--len, ++s)) {
if (*s == 0)
terminated = 1;
if (terminated || *s < 0x20 || *s > 0x7e)
*s = ' ';
}
}
static int scsi_probe_lun(struct scsi_device *sdev, unsigned char *inq_result,
int result_len, int *bflags)
{
unsigned char scsi_cmd[MAX_COMMAND_SIZE];
int first_inquiry_len, try_inquiry_len, next_inquiry_len;
int response_len = 0;
int pass, count, result;
struct scsi_sense_hdr sshdr;
*bflags = 0;
first_inquiry_len = sdev->inquiry_len ? sdev->inquiry_len : 36;
try_inquiry_len = first_inquiry_len;
pass = 1;
next_pass:
SCSI_LOG_SCAN_BUS(3, sdev_printk(KERN_INFO, sdev,
"scsi scan: INQUIRY pass %d length %d\n",
pass, try_inquiry_len));
for (count = 0; count < 3; ++count) {
int resid;
memset(scsi_cmd, 0, 6);
scsi_cmd[0] = INQUIRY;
scsi_cmd[4] = (unsigned char) try_inquiry_len;
memset(inq_result, 0, try_inquiry_len);
result = scsi_execute_req(sdev, scsi_cmd, DMA_FROM_DEVICE,
inq_result, try_inquiry_len, &sshdr,
HZ / 2 + HZ * scsi_inq_timeout, 3,
&resid);
SCSI_LOG_SCAN_BUS(3, sdev_printk(KERN_INFO, sdev,
"scsi scan: INQUIRY %s with code 0x%x\n",
result ? "failed" : "successful", result));
if (result) {
if ((driver_byte(result) & DRIVER_SENSE) &&
scsi_sense_valid(&sshdr)) {
if ((sshdr.sense_key == UNIT_ATTENTION) &&
((sshdr.asc == 0x28) ||
(sshdr.asc == 0x29)) &&
(sshdr.ascq == 0))
continue;
}
} else {
if (resid == try_inquiry_len)
continue;
}
break;
}
if (result == 0) {
sanitize_inquiry_string(&inq_result[8], 8);
sanitize_inquiry_string(&inq_result[16], 16);
sanitize_inquiry_string(&inq_result[32], 4);
response_len = inq_result[4] + 5;
if (response_len > 255)
response_len = first_inquiry_len;
*bflags = scsi_get_device_flags(sdev, &inq_result[8],
&inq_result[16]);
if (pass == 1) {
if (BLIST_INQUIRY_36 & *bflags)
next_inquiry_len = 36;
else if (BLIST_INQUIRY_58 & *bflags)
next_inquiry_len = 58;
else if (sdev->inquiry_len)
next_inquiry_len = sdev->inquiry_len;
else
next_inquiry_len = response_len;
if (next_inquiry_len > try_inquiry_len) {
try_inquiry_len = next_inquiry_len;
pass = 2;
goto next_pass;
}
}
} else if (pass == 2) {
sdev_printk(KERN_INFO, sdev,
"scsi scan: %d byte inquiry failed. "
"Consider BLIST_INQUIRY_36 for this device\n",
try_inquiry_len);
try_inquiry_len = first_inquiry_len;
pass = 3;
goto next_pass;
}
if (result)
return -EIO;
sdev->inquiry_len = min(try_inquiry_len, response_len);
if (sdev->inquiry_len < 36) {
if (!sdev->host->short_inquiry) {
shost_printk(KERN_INFO, sdev->host,
"scsi scan: INQUIRY result too short (%d),"
" using 36\n", sdev->inquiry_len);
sdev->host->short_inquiry = 1;
}
sdev->inquiry_len = 36;
}
sdev->scsi_level = inq_result[2] & 0x07;
if (sdev->scsi_level >= 2 ||
(sdev->scsi_level == 1 && (inq_result[3] & 0x0f) == 1))
sdev->scsi_level++;
sdev->sdev_target->scsi_level = sdev->scsi_level;
sdev->lun_in_cdb = 0;
if (sdev->scsi_level <= SCSI_2 &&
sdev->scsi_level != SCSI_UNKNOWN &&
!sdev->host->no_scsi2_lun_in_cdb)
sdev->lun_in_cdb = 1;
return 0;
}
static int scsi_add_lun(struct scsi_device *sdev, unsigned char *inq_result,
int *bflags, int async)
{
int ret;
sdev->inquiry = kmemdup(inq_result,
max_t(size_t, sdev->inquiry_len, 36),
GFP_ATOMIC);
if (sdev->inquiry == NULL)
return SCSI_SCAN_NO_RESPONSE;
sdev->vendor = (char *) (sdev->inquiry + 8);
sdev->model = (char *) (sdev->inquiry + 16);
sdev->rev = (char *) (sdev->inquiry + 32);
if (strncmp(sdev->vendor, "ATA ", 8) == 0) {
sdev->allow_restart = 1;
}
if (*bflags & BLIST_ISROM) {
sdev->type = TYPE_ROM;
sdev->removable = 1;
} else {
sdev->type = (inq_result[0] & 0x1f);
sdev->removable = (inq_result[1] & 0x80) >> 7;
if (scsi_is_wlun(sdev->lun) && sdev->type != TYPE_WLUN) {
sdev_printk(KERN_WARNING, sdev,
"%s: correcting incorrect peripheral device type 0x%x for W-LUN 0x%16xhN\n",
__func__, sdev->type, (unsigned int)sdev->lun);
sdev->type = TYPE_WLUN;
}
}
if (sdev->type == TYPE_RBC || sdev->type == TYPE_ROM) {
if ((*bflags & BLIST_REPORTLUN2) == 0)
*bflags |= BLIST_NOREPORTLUN;
}
sdev->inq_periph_qual = (inq_result[0] >> 5) & 7;
sdev->lockable = sdev->removable;
sdev->soft_reset = (inq_result[7] & 1) && ((inq_result[3] & 7) == 2);
if (sdev->scsi_level >= SCSI_3 ||
(sdev->inquiry_len > 56 && inq_result[56] & 0x04))
sdev->ppr = 1;
if (inq_result[7] & 0x60)
sdev->wdtr = 1;
if (inq_result[7] & 0x10)
sdev->sdtr = 1;
sdev_printk(KERN_NOTICE, sdev, "%s %.8s %.16s %.4s PQ: %d "
"ANSI: %d%s\n", scsi_device_type(sdev->type),
sdev->vendor, sdev->model, sdev->rev,
sdev->inq_periph_qual, inq_result[2] & 0x07,
(inq_result[3] & 0x0f) == 1 ? " CCS" : "");
if ((sdev->scsi_level >= SCSI_2) && (inq_result[7] & 2) &&
!(*bflags & BLIST_NOTQ)) {
sdev->tagged_supported = 1;
sdev->simple_tags = 1;
}
if ((*bflags & BLIST_BORKEN) == 0)
sdev->borken = 0;
if (*bflags & BLIST_NO_ULD_ATTACH)
sdev->no_uld_attach = 1;
if (*bflags & BLIST_SELECT_NO_ATN)
sdev->select_no_atn = 1;
if (*bflags & BLIST_MAX_512)
blk_queue_max_hw_sectors(sdev->request_queue, 512);
else if (*bflags & BLIST_MAX_1024)
blk_queue_max_hw_sectors(sdev->request_queue, 1024);
if (*bflags & BLIST_NOSTARTONADD)
sdev->no_start_on_add = 1;
if (*bflags & BLIST_SINGLELUN)
scsi_target(sdev)->single_lun = 1;
sdev->use_10_for_rw = 1;
if (*bflags & BLIST_MS_SKIP_PAGE_08)
sdev->skip_ms_page_8 = 1;
if (*bflags & BLIST_MS_SKIP_PAGE_3F)
sdev->skip_ms_page_3f = 1;
if (*bflags & BLIST_USE_10_BYTE_MS)
sdev->use_10_for_ms = 1;
if (*bflags & BLIST_NO_RSOC)
sdev->no_report_opcodes = 1;
ret = scsi_device_set_state(sdev, SDEV_RUNNING);
if (ret) {
ret = scsi_device_set_state(sdev, SDEV_BLOCK);
if (ret) {
sdev_printk(KERN_ERR, sdev,
"in wrong state %s to complete scan\n",
scsi_device_state_name(sdev->sdev_state));
return SCSI_SCAN_NO_RESPONSE;
}
}
if (*bflags & BLIST_MS_192_BYTES_FOR_3F)
sdev->use_192_bytes_for_3f = 1;
if (*bflags & BLIST_NOT_LOCKABLE)
sdev->lockable = 0;
if (*bflags & BLIST_RETRY_HWERROR)
sdev->retry_hwerror = 1;
if (*bflags & BLIST_NO_DIF)
sdev->no_dif = 1;
sdev->eh_timeout = SCSI_DEFAULT_EH_TIMEOUT;
if (*bflags & BLIST_TRY_VPD_PAGES)
sdev->try_vpd_pages = 1;
else if (*bflags & BLIST_SKIP_VPD_PAGES)
sdev->skip_vpd_pages = 1;
transport_configure_device(&sdev->sdev_gendev);
if (sdev->host->hostt->slave_configure) {
ret = sdev->host->hostt->slave_configure(sdev);
if (ret) {
if (ret != -ENXIO) {
sdev_printk(KERN_ERR, sdev,
"failed to configure device\n");
}
return SCSI_SCAN_NO_RESPONSE;
}
}
if (sdev->scsi_level >= SCSI_3)
scsi_attach_vpd(sdev);
sdev->max_queue_depth = sdev->queue_depth;
if (!async && scsi_sysfs_add_sdev(sdev) != 0)
return SCSI_SCAN_NO_RESPONSE;
return SCSI_SCAN_LUN_PRESENT;
}
static unsigned char *scsi_inq_str(unsigned char *buf, unsigned char *inq,
unsigned first, unsigned end)
{
unsigned term = 0, idx;
for (idx = 0; idx + first < end && idx + first < inq[4] + 5; idx++) {
if (inq[idx+first] > ' ') {
buf[idx] = inq[idx+first];
term = idx+1;
} else {
buf[idx] = ' ';
}
}
buf[term] = 0;
return buf;
}
static int scsi_probe_and_add_lun(struct scsi_target *starget,
u64 lun, int *bflagsp,
struct scsi_device **sdevp, int rescan,
void *hostdata)
{
struct scsi_device *sdev;
unsigned char *result;
int bflags, res = SCSI_SCAN_NO_RESPONSE, result_len = 256;
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
sdev = scsi_device_lookup_by_target(starget, lun);
if (sdev) {
if (rescan || !scsi_device_created(sdev)) {
SCSI_LOG_SCAN_BUS(3, sdev_printk(KERN_INFO, sdev,
"scsi scan: device exists on %s\n",
dev_name(&sdev->sdev_gendev)));
if (sdevp)
*sdevp = sdev;
else
scsi_device_put(sdev);
if (bflagsp)
*bflagsp = scsi_get_device_flags(sdev,
sdev->vendor,
sdev->model);
return SCSI_SCAN_LUN_PRESENT;
}
scsi_device_put(sdev);
} else
sdev = scsi_alloc_sdev(starget, lun, hostdata);
if (!sdev)
goto out;
result = kmalloc(result_len, GFP_ATOMIC |
((shost->unchecked_isa_dma) ? __GFP_DMA : 0));
if (!result)
goto out_free_sdev;
if (scsi_probe_lun(sdev, result, result_len, &bflags))
goto out_free_result;
if (bflagsp)
*bflagsp = bflags;
if (((result[0] >> 5) == 3) && !(bflags & BLIST_ATTACH_PQ3)) {
SCSI_LOG_SCAN_BUS(2, sdev_printk(KERN_INFO, sdev, "scsi scan:"
" peripheral qualifier of 3, device not"
" added\n"))
if (lun == 0) {
SCSI_LOG_SCAN_BUS(1, {
unsigned char vend[9];
unsigned char mod[17];
sdev_printk(KERN_INFO, sdev,
"scsi scan: consider passing scsi_mod."
"dev_flags=%s:%s:0x240 or 0x1000240\n",
scsi_inq_str(vend, result, 8, 16),
scsi_inq_str(mod, result, 16, 32));
});
}
res = SCSI_SCAN_TARGET_PRESENT;
goto out_free_result;
}
if (((result[0] >> 5) == 1 || starget->pdt_1f_for_no_lun) &&
(result[0] & 0x1f) == 0x1f &&
!scsi_is_wlun(lun)) {
SCSI_LOG_SCAN_BUS(3, sdev_printk(KERN_INFO, sdev,
"scsi scan: peripheral device type"
" of 31, no device added\n"));
res = SCSI_SCAN_TARGET_PRESENT;
goto out_free_result;
}
res = scsi_add_lun(sdev, result, &bflags, shost->async_scan);
if (res == SCSI_SCAN_LUN_PRESENT) {
if (bflags & BLIST_KEY) {
sdev->lockable = 0;
scsi_unlock_floptical(sdev, result);
}
}
out_free_result:
kfree(result);
out_free_sdev:
if (res == SCSI_SCAN_LUN_PRESENT) {
if (sdevp) {
if (scsi_device_get(sdev) == 0) {
*sdevp = sdev;
} else {
__scsi_remove_device(sdev);
res = SCSI_SCAN_NO_RESPONSE;
}
}
} else
__scsi_remove_device(sdev);
out:
return res;
}
static void scsi_sequential_lun_scan(struct scsi_target *starget,
int bflags, int scsi_level, int rescan)
{
uint max_dev_lun;
u64 sparse_lun, lun;
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
SCSI_LOG_SCAN_BUS(3, starget_printk(KERN_INFO, starget,
"scsi scan: Sequential scan\n"));
max_dev_lun = min(max_scsi_luns, shost->max_lun);
if (bflags & BLIST_SPARSELUN) {
max_dev_lun = shost->max_lun;
sparse_lun = 1;
} else
sparse_lun = 0;
if (bflags & BLIST_FORCELUN)
max_dev_lun = shost->max_lun;
if (bflags & BLIST_MAX5LUN)
max_dev_lun = min(5U, max_dev_lun);
if (scsi_level < SCSI_3 && !(bflags & BLIST_LARGELUN))
max_dev_lun = min(8U, max_dev_lun);
if (!(bflags & BLIST_SCSI3LUN))
max_dev_lun = min(256U, max_dev_lun);
for (lun = 1; lun < max_dev_lun; ++lun)
if ((scsi_probe_and_add_lun(starget, lun, NULL, NULL, rescan,
NULL) != SCSI_SCAN_LUN_PRESENT) &&
!sparse_lun)
return;
}
static int scsi_report_lun_scan(struct scsi_target *starget, int bflags,
int rescan)
{
char devname[64];
unsigned char scsi_cmd[MAX_COMMAND_SIZE];
unsigned int length;
u64 lun;
unsigned int num_luns;
unsigned int retries;
int result;
struct scsi_lun *lunp, *lun_data;
struct scsi_sense_hdr sshdr;
struct scsi_device *sdev;
struct Scsi_Host *shost = dev_to_shost(&starget->dev);
int ret = 0;
if (bflags & BLIST_NOREPORTLUN)
return 1;
if (starget->scsi_level < SCSI_2 &&
starget->scsi_level != SCSI_UNKNOWN)
return 1;
if (starget->scsi_level < SCSI_3 &&
(!(bflags & BLIST_REPORTLUN2) || shost->max_lun <= 8))
return 1;
if (bflags & BLIST_NOLUN)
return 0;
if (starget->no_report_luns)
return 1;
if (!(sdev = scsi_device_lookup_by_target(starget, 0))) {
sdev = scsi_alloc_sdev(starget, 0, NULL);
if (!sdev)
return 0;
if (scsi_device_get(sdev)) {
__scsi_remove_device(sdev);
return 0;
}
}
sprintf(devname, "host %d channel %d id %d",
shost->host_no, sdev->channel, sdev->id);
length = (511 + 1) * sizeof(struct scsi_lun);
retry:
lun_data = kmalloc(length, GFP_KERNEL |
(sdev->host->unchecked_isa_dma ? __GFP_DMA : 0));
if (!lun_data) {
printk(ALLOC_FAILURE_MSG, __func__);
goto out;
}
scsi_cmd[0] = REPORT_LUNS;
memset(&scsi_cmd[1], 0, 5);
put_unaligned_be32(length, &scsi_cmd[6]);
scsi_cmd[10] = 0;
scsi_cmd[11] = 0;
for (retries = 0; retries < 3; retries++) {
SCSI_LOG_SCAN_BUS(3, sdev_printk (KERN_INFO, sdev,
"scsi scan: Sending REPORT LUNS to (try %d)\n",
retries));
result = scsi_execute_req(sdev, scsi_cmd, DMA_FROM_DEVICE,
lun_data, length, &sshdr,
SCSI_REPORT_LUNS_TIMEOUT, 3, NULL);
SCSI_LOG_SCAN_BUS(3, sdev_printk (KERN_INFO, sdev,
"scsi scan: REPORT LUNS"
" %s (try %d) result 0x%x\n",
result ? "failed" : "successful",
retries, result));
if (result == 0)
break;
else if (scsi_sense_valid(&sshdr)) {
if (sshdr.sense_key != UNIT_ATTENTION)
break;
}
}
if (result) {
ret = 1;
goto out_err;
}
if (get_unaligned_be32(lun_data->scsi_lun) +
sizeof(struct scsi_lun) > length) {
length = get_unaligned_be32(lun_data->scsi_lun) +
sizeof(struct scsi_lun);
kfree(lun_data);
goto retry;
}
length = get_unaligned_be32(lun_data->scsi_lun);
num_luns = (length / sizeof(struct scsi_lun));
SCSI_LOG_SCAN_BUS(3, sdev_printk (KERN_INFO, sdev,
"scsi scan: REPORT LUN scan\n"));
for (lunp = &lun_data[1]; lunp <= &lun_data[num_luns]; lunp++) {
lun = scsilun_to_int(lunp);
if (lun > sdev->host->max_lun) {
sdev_printk(KERN_WARNING, sdev,
"lun%llu has a LUN larger than"
" allowed by the host adapter\n", lun);
} else {
int res;
res = scsi_probe_and_add_lun(starget,
lun, NULL, NULL, rescan, NULL);
if (res == SCSI_SCAN_NO_RESPONSE) {
sdev_printk(KERN_ERR, sdev,
"Unexpected response"
" from lun %llu while scanning, scan"
" aborted\n", (unsigned long long)lun);
break;
}
}
}
out_err:
kfree(lun_data);
out:
scsi_device_put(sdev);
if (scsi_device_created(sdev))
__scsi_remove_device(sdev);
return ret;
}
struct scsi_device *__scsi_add_device(struct Scsi_Host *shost, uint channel,
uint id, u64 lun, void *hostdata)
{
struct scsi_device *sdev = ERR_PTR(-ENODEV);
struct device *parent = &shost->shost_gendev;
struct scsi_target *starget;
if (strncmp(scsi_scan_type, "none", 4) == 0)
return ERR_PTR(-ENODEV);
starget = scsi_alloc_target(parent, channel, id);
if (!starget)
return ERR_PTR(-ENOMEM);
scsi_autopm_get_target(starget);
mutex_lock(&shost->scan_mutex);
if (!shost->async_scan)
scsi_complete_async_scans();
if (scsi_host_scan_allowed(shost) && scsi_autopm_get_host(shost) == 0) {
scsi_probe_and_add_lun(starget, lun, NULL, &sdev, 1, hostdata);
scsi_autopm_put_host(shost);
}
mutex_unlock(&shost->scan_mutex);
scsi_autopm_put_target(starget);
scsi_target_reap(starget);
put_device(&starget->dev);
return sdev;
}
int scsi_add_device(struct Scsi_Host *host, uint channel,
uint target, u64 lun)
{
struct scsi_device *sdev =
__scsi_add_device(host, channel, target, lun, NULL);
if (IS_ERR(sdev))
return PTR_ERR(sdev);
scsi_device_put(sdev);
return 0;
}
void scsi_rescan_device(struct device *dev)
{
device_lock(dev);
if (dev->driver && try_module_get(dev->driver->owner)) {
struct scsi_driver *drv = to_scsi_driver(dev->driver);
if (drv->rescan)
drv->rescan(dev);
module_put(dev->driver->owner);
}
device_unlock(dev);
}
static void __scsi_scan_target(struct device *parent, unsigned int channel,
unsigned int id, u64 lun, int rescan)
{
struct Scsi_Host *shost = dev_to_shost(parent);
int bflags = 0;
int res;
struct scsi_target *starget;
if (shost->this_id == id)
return;
starget = scsi_alloc_target(parent, channel, id);
if (!starget)
return;
scsi_autopm_get_target(starget);
if (lun != SCAN_WILD_CARD) {
scsi_probe_and_add_lun(starget, lun, NULL, NULL, rescan, NULL);
goto out_reap;
}
res = scsi_probe_and_add_lun(starget, 0, &bflags, NULL, rescan, NULL);
if (res == SCSI_SCAN_LUN_PRESENT || res == SCSI_SCAN_TARGET_PRESENT) {
if (scsi_report_lun_scan(starget, bflags, rescan) != 0)
scsi_sequential_lun_scan(starget, bflags,
starget->scsi_level, rescan);
}
out_reap:
scsi_autopm_put_target(starget);
scsi_target_reap(starget);
put_device(&starget->dev);
}
void scsi_scan_target(struct device *parent, unsigned int channel,
unsigned int id, u64 lun, int rescan)
{
struct Scsi_Host *shost = dev_to_shost(parent);
if (strncmp(scsi_scan_type, "none", 4) == 0)
return;
mutex_lock(&shost->scan_mutex);
if (!shost->async_scan)
scsi_complete_async_scans();
if (scsi_host_scan_allowed(shost) && scsi_autopm_get_host(shost) == 0) {
__scsi_scan_target(parent, channel, id, lun, rescan);
scsi_autopm_put_host(shost);
}
mutex_unlock(&shost->scan_mutex);
}
static void scsi_scan_channel(struct Scsi_Host *shost, unsigned int channel,
unsigned int id, u64 lun, int rescan)
{
uint order_id;
if (id == SCAN_WILD_CARD)
for (id = 0; id < shost->max_id; ++id) {
if (shost->reverse_ordering)
order_id = shost->max_id - id - 1;
else
order_id = id;
__scsi_scan_target(&shost->shost_gendev, channel,
order_id, lun, rescan);
}
else
__scsi_scan_target(&shost->shost_gendev, channel,
id, lun, rescan);
}
int scsi_scan_host_selected(struct Scsi_Host *shost, unsigned int channel,
unsigned int id, u64 lun, int rescan)
{
SCSI_LOG_SCAN_BUS(3, shost_printk (KERN_INFO, shost,
"%s: <%u:%u:%llu>\n",
__func__, channel, id, lun));
if (((channel != SCAN_WILD_CARD) && (channel > shost->max_channel)) ||
((id != SCAN_WILD_CARD) && (id >= shost->max_id)) ||
((lun != SCAN_WILD_CARD) && (lun >= shost->max_lun)))
return -EINVAL;
mutex_lock(&shost->scan_mutex);
if (!shost->async_scan)
scsi_complete_async_scans();
if (scsi_host_scan_allowed(shost) && scsi_autopm_get_host(shost) == 0) {
if (channel == SCAN_WILD_CARD)
for (channel = 0; channel <= shost->max_channel;
channel++)
scsi_scan_channel(shost, channel, id, lun,
rescan);
else
scsi_scan_channel(shost, channel, id, lun, rescan);
scsi_autopm_put_host(shost);
}
mutex_unlock(&shost->scan_mutex);
return 0;
}
static void scsi_sysfs_add_devices(struct Scsi_Host *shost)
{
struct scsi_device *sdev;
shost_for_each_device(sdev, shost) {
if (sdev->sdev_state == SDEV_DEL)
continue;
if (sdev->is_visible)
continue;
if (!scsi_host_scan_allowed(shost) ||
scsi_sysfs_add_sdev(sdev) != 0)
__scsi_remove_device(sdev);
}
}
static struct async_scan_data *scsi_prep_async_scan(struct Scsi_Host *shost)
{
struct async_scan_data *data;
unsigned long flags;
if (strncmp(scsi_scan_type, "sync", 4) == 0)
return NULL;
if (shost->async_scan) {
shost_printk(KERN_DEBUG, shost, "%s called twice\n", __func__);
return NULL;
}
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
goto err;
data->shost = scsi_host_get(shost);
if (!data->shost)
goto err;
init_completion(&data->prev_finished);
mutex_lock(&shost->scan_mutex);
spin_lock_irqsave(shost->host_lock, flags);
shost->async_scan = 1;
spin_unlock_irqrestore(shost->host_lock, flags);
mutex_unlock(&shost->scan_mutex);
spin_lock(&async_scan_lock);
if (list_empty(&scanning_hosts))
complete(&data->prev_finished);
list_add_tail(&data->list, &scanning_hosts);
spin_unlock(&async_scan_lock);
return data;
err:
kfree(data);
return NULL;
}
static void scsi_finish_async_scan(struct async_scan_data *data)
{
struct Scsi_Host *shost;
unsigned long flags;
if (!data)
return;
shost = data->shost;
mutex_lock(&shost->scan_mutex);
if (!shost->async_scan) {
shost_printk(KERN_INFO, shost, "%s called twice\n", __func__);
dump_stack();
mutex_unlock(&shost->scan_mutex);
return;
}
wait_for_completion(&data->prev_finished);
scsi_sysfs_add_devices(shost);
spin_lock_irqsave(shost->host_lock, flags);
shost->async_scan = 0;
spin_unlock_irqrestore(shost->host_lock, flags);
mutex_unlock(&shost->scan_mutex);
spin_lock(&async_scan_lock);
list_del(&data->list);
if (!list_empty(&scanning_hosts)) {
struct async_scan_data *next = list_entry(scanning_hosts.next,
struct async_scan_data, list);
complete(&next->prev_finished);
}
spin_unlock(&async_scan_lock);
scsi_autopm_put_host(shost);
scsi_host_put(shost);
kfree(data);
}
static void do_scsi_scan_host(struct Scsi_Host *shost)
{
if (shost->hostt->scan_finished) {
unsigned long start = jiffies;
if (shost->hostt->scan_start)
shost->hostt->scan_start(shost);
while (!shost->hostt->scan_finished(shost, jiffies - start))
msleep(10);
} else {
scsi_scan_host_selected(shost, SCAN_WILD_CARD, SCAN_WILD_CARD,
SCAN_WILD_CARD, 0);
}
}
static void do_scan_async(void *_data, async_cookie_t c)
{
struct async_scan_data *data = _data;
struct Scsi_Host *shost = data->shost;
do_scsi_scan_host(shost);
scsi_finish_async_scan(data);
}
void scsi_scan_host(struct Scsi_Host *shost)
{
struct async_scan_data *data;
if (strncmp(scsi_scan_type, "none", 4) == 0)
return;
if (scsi_autopm_get_host(shost) < 0)
return;
data = scsi_prep_async_scan(shost);
if (!data) {
do_scsi_scan_host(shost);
scsi_autopm_put_host(shost);
return;
}
async_schedule(do_scan_async, data);
}
void scsi_forget_host(struct Scsi_Host *shost)
{
struct scsi_device *sdev;
unsigned long flags;
restart:
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry(sdev, &shost->__devices, siblings) {
if (sdev->sdev_state == SDEV_DEL)
continue;
spin_unlock_irqrestore(shost->host_lock, flags);
__scsi_remove_device(sdev);
goto restart;
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
struct scsi_device *scsi_get_host_dev(struct Scsi_Host *shost)
{
struct scsi_device *sdev = NULL;
struct scsi_target *starget;
mutex_lock(&shost->scan_mutex);
if (!scsi_host_scan_allowed(shost))
goto out;
starget = scsi_alloc_target(&shost->shost_gendev, 0, shost->this_id);
if (!starget)
goto out;
sdev = scsi_alloc_sdev(starget, 0, NULL);
if (sdev)
sdev->borken = 0;
else
scsi_target_reap(starget);
put_device(&starget->dev);
out:
mutex_unlock(&shost->scan_mutex);
return sdev;
}
void scsi_free_host_dev(struct scsi_device *sdev)
{
BUG_ON(sdev->id != sdev->host->this_id);
__scsi_remove_device(sdev);
}
