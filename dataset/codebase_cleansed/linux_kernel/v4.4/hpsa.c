static inline struct ctlr_info *sdev_to_hba(struct scsi_device *sdev)
{
unsigned long *priv = shost_priv(sdev->host);
return (struct ctlr_info *) *priv;
}
static inline struct ctlr_info *shost_to_hba(struct Scsi_Host *sh)
{
unsigned long *priv = shost_priv(sh);
return (struct ctlr_info *) *priv;
}
static inline bool hpsa_is_cmd_idle(struct CommandList *c)
{
return c->scsi_cmd == SCSI_CMD_IDLE;
}
static inline bool hpsa_is_pending_event(struct CommandList *c)
{
return c->abort_pending || c->reset_pending;
}
static void decode_sense_data(const u8 *sense_data, int sense_data_len,
u8 *sense_key, u8 *asc, u8 *ascq)
{
struct scsi_sense_hdr sshdr;
bool rc;
*sense_key = -1;
*asc = -1;
*ascq = -1;
if (sense_data_len < 1)
return;
rc = scsi_normalize_sense(sense_data, sense_data_len, &sshdr);
if (rc) {
*sense_key = sshdr.sense_key;
*asc = sshdr.asc;
*ascq = sshdr.ascq;
}
}
static int check_for_unit_attention(struct ctlr_info *h,
struct CommandList *c)
{
u8 sense_key, asc, ascq;
int sense_len;
if (c->err_info->SenseLen > sizeof(c->err_info->SenseInfo))
sense_len = sizeof(c->err_info->SenseInfo);
else
sense_len = c->err_info->SenseLen;
decode_sense_data(c->err_info->SenseInfo, sense_len,
&sense_key, &asc, &ascq);
if (sense_key != UNIT_ATTENTION || asc == 0xff)
return 0;
switch (asc) {
case STATE_CHANGED:
dev_warn(&h->pdev->dev,
"%s: a state change detected, command retried\n",
h->devname);
break;
case LUN_FAILED:
dev_warn(&h->pdev->dev,
"%s: LUN failure detected\n", h->devname);
break;
case REPORT_LUNS_CHANGED:
dev_warn(&h->pdev->dev,
"%s: report LUN data changed\n", h->devname);
break;
case POWER_OR_RESET:
dev_warn(&h->pdev->dev,
"%s: a power on or device reset detected\n",
h->devname);
break;
case UNIT_ATTENTION_CLEARED:
dev_warn(&h->pdev->dev,
"%s: unit attention cleared by another initiator\n",
h->devname);
break;
default:
dev_warn(&h->pdev->dev,
"%s: unknown unit attention detected\n",
h->devname);
break;
}
return 1;
}
static int check_for_busy(struct ctlr_info *h, struct CommandList *c)
{
if (c->err_info->CommandStatus != CMD_TARGET_STATUS ||
(c->err_info->ScsiStatus != SAM_STAT_BUSY &&
c->err_info->ScsiStatus != SAM_STAT_TASK_SET_FULL))
return 0;
dev_warn(&h->pdev->dev, HPSA "device busy");
return 1;
}
static ssize_t host_show_lockup_detected(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ld;
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
h = shost_to_hba(shost);
ld = lockup_detected(h);
return sprintf(buf, "ld=%d\n", ld);
}
static ssize_t host_store_hp_ssd_smart_path_status(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int status, len;
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
char tmpbuf[10];
if (!capable(CAP_SYS_ADMIN) || !capable(CAP_SYS_RAWIO))
return -EACCES;
len = count > sizeof(tmpbuf) - 1 ? sizeof(tmpbuf) - 1 : count;
strncpy(tmpbuf, buf, len);
tmpbuf[len] = '\0';
if (sscanf(tmpbuf, "%d", &status) != 1)
return -EINVAL;
h = shost_to_hba(shost);
h->acciopath_status = !!status;
dev_warn(&h->pdev->dev,
"hpsa: HP SSD Smart Path %s via sysfs update.\n",
h->acciopath_status ? "enabled" : "disabled");
return count;
}
static ssize_t host_store_raid_offload_debug(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int debug_level, len;
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
char tmpbuf[10];
if (!capable(CAP_SYS_ADMIN) || !capable(CAP_SYS_RAWIO))
return -EACCES;
len = count > sizeof(tmpbuf) - 1 ? sizeof(tmpbuf) - 1 : count;
strncpy(tmpbuf, buf, len);
tmpbuf[len] = '\0';
if (sscanf(tmpbuf, "%d", &debug_level) != 1)
return -EINVAL;
if (debug_level < 0)
debug_level = 0;
h = shost_to_hba(shost);
h->raid_offload_debug = debug_level;
dev_warn(&h->pdev->dev, "hpsa: Set raid_offload_debug level = %d\n",
h->raid_offload_debug);
return count;
}
static ssize_t host_store_rescan(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
h = shost_to_hba(shost);
hpsa_scan_start(h->scsi_host);
return count;
}
static ssize_t host_show_firmware_revision(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
unsigned char *fwrev;
h = shost_to_hba(shost);
if (!h->hba_inquiry_data)
return 0;
fwrev = &h->hba_inquiry_data[32];
return snprintf(buf, 20, "%c%c%c%c\n",
fwrev[0], fwrev[1], fwrev[2], fwrev[3]);
}
static ssize_t host_show_commands_outstanding(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct ctlr_info *h = shost_to_hba(shost);
return snprintf(buf, 20, "%d\n",
atomic_read(&h->commands_outstanding));
}
static ssize_t host_show_transport_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
h = shost_to_hba(shost);
return snprintf(buf, 20, "%s\n",
h->transMethod & CFGTBL_Trans_Performant ?
"performant" : "simple");
}
static ssize_t host_show_hp_ssd_smart_path_status(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
h = shost_to_hba(shost);
return snprintf(buf, 30, "HP SSD Smart Path %s\n",
(h->acciopath_status == 1) ? "enabled" : "disabled");
}
static int board_id_in_array(u32 a[], int nelems, u32 board_id)
{
int i;
for (i = 0; i < nelems; i++)
if (a[i] == board_id)
return 1;
return 0;
}
static int ctlr_is_hard_resettable(u32 board_id)
{
return !board_id_in_array(unresettable_controller,
ARRAY_SIZE(unresettable_controller), board_id);
}
static int ctlr_is_soft_resettable(u32 board_id)
{
return !board_id_in_array(soft_unresettable_controller,
ARRAY_SIZE(soft_unresettable_controller), board_id);
}
static int ctlr_is_resettable(u32 board_id)
{
return ctlr_is_hard_resettable(board_id) ||
ctlr_is_soft_resettable(board_id);
}
static int ctlr_needs_abort_tags_swizzled(u32 board_id)
{
return board_id_in_array(needs_abort_tags_swizzled,
ARRAY_SIZE(needs_abort_tags_swizzled), board_id);
}
static ssize_t host_show_resettable(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct Scsi_Host *shost = class_to_shost(dev);
h = shost_to_hba(shost);
return snprintf(buf, 20, "%d\n", ctlr_is_resettable(h->board_id));
}
static inline int is_logical_dev_addr_mode(unsigned char scsi3addr[])
{
return (scsi3addr[3] & 0xC0) == 0x40;
}
static inline bool is_logical_device(struct hpsa_scsi_dev_t *device)
{
return !device->physical_device;
}
static ssize_t raid_level_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
ssize_t l = 0;
unsigned char rlevel;
struct ctlr_info *h;
struct scsi_device *sdev;
struct hpsa_scsi_dev_t *hdev;
unsigned long flags;
sdev = to_scsi_device(dev);
h = sdev_to_hba(sdev);
spin_lock_irqsave(&h->lock, flags);
hdev = sdev->hostdata;
if (!hdev) {
spin_unlock_irqrestore(&h->lock, flags);
return -ENODEV;
}
if (!is_logical_device(hdev)) {
spin_unlock_irqrestore(&h->lock, flags);
l = snprintf(buf, PAGE_SIZE, "N/A\n");
return l;
}
rlevel = hdev->raid_level;
spin_unlock_irqrestore(&h->lock, flags);
if (rlevel > RAID_UNKNOWN)
rlevel = RAID_UNKNOWN;
l = snprintf(buf, PAGE_SIZE, "RAID %s\n", raid_label[rlevel]);
return l;
}
static ssize_t lunid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct scsi_device *sdev;
struct hpsa_scsi_dev_t *hdev;
unsigned long flags;
unsigned char lunid[8];
sdev = to_scsi_device(dev);
h = sdev_to_hba(sdev);
spin_lock_irqsave(&h->lock, flags);
hdev = sdev->hostdata;
if (!hdev) {
spin_unlock_irqrestore(&h->lock, flags);
return -ENODEV;
}
memcpy(lunid, hdev->scsi3addr, sizeof(lunid));
spin_unlock_irqrestore(&h->lock, flags);
return snprintf(buf, 20, "0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
lunid[0], lunid[1], lunid[2], lunid[3],
lunid[4], lunid[5], lunid[6], lunid[7]);
}
static ssize_t unique_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct scsi_device *sdev;
struct hpsa_scsi_dev_t *hdev;
unsigned long flags;
unsigned char sn[16];
sdev = to_scsi_device(dev);
h = sdev_to_hba(sdev);
spin_lock_irqsave(&h->lock, flags);
hdev = sdev->hostdata;
if (!hdev) {
spin_unlock_irqrestore(&h->lock, flags);
return -ENODEV;
}
memcpy(sn, hdev->device_id, sizeof(sn));
spin_unlock_irqrestore(&h->lock, flags);
return snprintf(buf, 16 * 2 + 2,
"%02X%02X%02X%02X%02X%02X%02X%02X"
"%02X%02X%02X%02X%02X%02X%02X%02X\n",
sn[0], sn[1], sn[2], sn[3],
sn[4], sn[5], sn[6], sn[7],
sn[8], sn[9], sn[10], sn[11],
sn[12], sn[13], sn[14], sn[15]);
}
static ssize_t host_show_hp_ssd_smart_path_enabled(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct scsi_device *sdev;
struct hpsa_scsi_dev_t *hdev;
unsigned long flags;
int offload_enabled;
sdev = to_scsi_device(dev);
h = sdev_to_hba(sdev);
spin_lock_irqsave(&h->lock, flags);
hdev = sdev->hostdata;
if (!hdev) {
spin_unlock_irqrestore(&h->lock, flags);
return -ENODEV;
}
offload_enabled = hdev->offload_enabled;
spin_unlock_irqrestore(&h->lock, flags);
return snprintf(buf, 20, "%d\n", offload_enabled);
}
static ssize_t path_info_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ctlr_info *h;
struct scsi_device *sdev;
struct hpsa_scsi_dev_t *hdev;
unsigned long flags;
int i;
int output_len = 0;
u8 box;
u8 bay;
u8 path_map_index = 0;
char *active;
unsigned char phys_connector[2];
sdev = to_scsi_device(dev);
h = sdev_to_hba(sdev);
spin_lock_irqsave(&h->devlock, flags);
hdev = sdev->hostdata;
if (!hdev) {
spin_unlock_irqrestore(&h->devlock, flags);
return -ENODEV;
}
bay = hdev->bay;
for (i = 0; i < MAX_PATHS; i++) {
path_map_index = 1<<i;
if (i == hdev->active_path_index)
active = "Active";
else if (hdev->path_map & path_map_index)
active = "Inactive";
else
continue;
output_len += scnprintf(buf + output_len,
PAGE_SIZE - output_len,
"[%d:%d:%d:%d] %20.20s ",
h->scsi_host->host_no,
hdev->bus, hdev->target, hdev->lun,
scsi_device_type(hdev->devtype));
if (hdev->external ||
hdev->devtype == TYPE_RAID ||
is_logical_device(hdev)) {
output_len += snprintf(buf + output_len,
PAGE_SIZE - output_len,
"%s\n", active);
continue;
}
box = hdev->box[i];
memcpy(&phys_connector, &hdev->phys_connector[i],
sizeof(phys_connector));
if (phys_connector[0] < '0')
phys_connector[0] = '0';
if (phys_connector[1] < '0')
phys_connector[1] = '0';
if (hdev->phys_connector[i] > 0)
output_len += snprintf(buf + output_len,
PAGE_SIZE - output_len,
"PORT: %.2s ",
phys_connector);
if (hdev->devtype == TYPE_DISK && hdev->expose_device) {
if (box == 0 || box == 0xFF) {
output_len += snprintf(buf + output_len,
PAGE_SIZE - output_len,
"BAY: %hhu %s\n",
bay, active);
} else {
output_len += snprintf(buf + output_len,
PAGE_SIZE - output_len,
"BOX: %hhu BAY: %hhu %s\n",
box, bay, active);
}
} else if (box != 0 && box != 0xFF) {
output_len += snprintf(buf + output_len,
PAGE_SIZE - output_len, "BOX: %hhu %s\n",
box, active);
} else
output_len += snprintf(buf + output_len,
PAGE_SIZE - output_len, "%s\n", active);
}
spin_unlock_irqrestore(&h->devlock, flags);
return output_len;
}
static inline u32 next_command(struct ctlr_info *h, u8 q)
{
u32 a;
struct reply_queue_buffer *rq = &h->reply_queue[q];
if (h->transMethod & CFGTBL_Trans_io_accel1)
return h->access.command_completed(h, q);
if (unlikely(!(h->transMethod & CFGTBL_Trans_Performant)))
return h->access.command_completed(h, q);
if ((rq->head[rq->current_entry] & 1) == rq->wraparound) {
a = rq->head[rq->current_entry];
rq->current_entry++;
atomic_dec(&h->commands_outstanding);
} else {
a = FIFO_EMPTY;
}
if (rq->current_entry == h->max_commands) {
rq->current_entry = 0;
rq->wraparound ^= 1;
}
return a;
}
static void set_performant_mode(struct ctlr_info *h, struct CommandList *c,
int reply_queue)
{
if (likely(h->transMethod & CFGTBL_Trans_Performant)) {
c->busaddr |= 1 | (h->blockFetchTable[c->Header.SGList] << 1);
if (unlikely(!h->msix_vector))
return;
if (likely(reply_queue == DEFAULT_REPLY_QUEUE))
c->Header.ReplyQueue =
raw_smp_processor_id() % h->nreply_queues;
else
c->Header.ReplyQueue = reply_queue % h->nreply_queues;
}
}
static void set_ioaccel1_performant_mode(struct ctlr_info *h,
struct CommandList *c,
int reply_queue)
{
struct io_accel1_cmd *cp = &h->ioaccel_cmd_pool[c->cmdindex];
if (likely(reply_queue == DEFAULT_REPLY_QUEUE))
cp->ReplyQueue = smp_processor_id() % h->nreply_queues;
else
cp->ReplyQueue = reply_queue % h->nreply_queues;
c->busaddr |= 1 | (h->ioaccel1_blockFetchTable[c->Header.SGList] << 1) |
IOACCEL1_BUSADDR_CMDTYPE;
}
static void set_ioaccel2_tmf_performant_mode(struct ctlr_info *h,
struct CommandList *c,
int reply_queue)
{
struct hpsa_tmf_struct *cp = (struct hpsa_tmf_struct *)
&h->ioaccel2_cmd_pool[c->cmdindex];
if (likely(reply_queue == DEFAULT_REPLY_QUEUE))
cp->reply_queue = smp_processor_id() % h->nreply_queues;
else
cp->reply_queue = reply_queue % h->nreply_queues;
c->busaddr |= h->ioaccel2_blockFetchTable[0];
}
static void set_ioaccel2_performant_mode(struct ctlr_info *h,
struct CommandList *c,
int reply_queue)
{
struct io_accel2_cmd *cp = &h->ioaccel2_cmd_pool[c->cmdindex];
if (likely(reply_queue == DEFAULT_REPLY_QUEUE))
cp->reply_queue = smp_processor_id() % h->nreply_queues;
else
cp->reply_queue = reply_queue % h->nreply_queues;
c->busaddr |= (h->ioaccel2_blockFetchTable[cp->sg_count]);
}
static int is_firmware_flash_cmd(u8 *cdb)
{
return cdb[0] == BMIC_WRITE && cdb[6] == BMIC_FLASH_FIRMWARE;
}
static void dial_down_lockup_detection_during_fw_flash(struct ctlr_info *h,
struct CommandList *c)
{
if (!is_firmware_flash_cmd(c->Request.CDB))
return;
atomic_inc(&h->firmware_flash_in_progress);
h->heartbeat_sample_interval = HEARTBEAT_SAMPLE_INTERVAL_DURING_FLASH;
}
static void dial_up_lockup_detection_on_fw_flash_complete(struct ctlr_info *h,
struct CommandList *c)
{
if (is_firmware_flash_cmd(c->Request.CDB) &&
atomic_dec_and_test(&h->firmware_flash_in_progress))
h->heartbeat_sample_interval = HEARTBEAT_SAMPLE_INTERVAL;
}
static void __enqueue_cmd_and_start_io(struct ctlr_info *h,
struct CommandList *c, int reply_queue)
{
dial_down_lockup_detection_during_fw_flash(h, c);
atomic_inc(&h->commands_outstanding);
switch (c->cmd_type) {
case CMD_IOACCEL1:
set_ioaccel1_performant_mode(h, c, reply_queue);
writel(c->busaddr, h->vaddr + SA5_REQUEST_PORT_OFFSET);
break;
case CMD_IOACCEL2:
set_ioaccel2_performant_mode(h, c, reply_queue);
writel(c->busaddr, h->vaddr + IOACCEL2_INBOUND_POSTQ_32);
break;
case IOACCEL2_TMF:
set_ioaccel2_tmf_performant_mode(h, c, reply_queue);
writel(c->busaddr, h->vaddr + IOACCEL2_INBOUND_POSTQ_32);
break;
default:
set_performant_mode(h, c, reply_queue);
h->access.submit_command(h, c);
}
}
static void enqueue_cmd_and_start_io(struct ctlr_info *h, struct CommandList *c)
{
if (unlikely(hpsa_is_pending_event(c)))
return finish_cmd(c);
__enqueue_cmd_and_start_io(h, c, DEFAULT_REPLY_QUEUE);
}
static inline int is_hba_lunid(unsigned char scsi3addr[])
{
return memcmp(scsi3addr, RAID_CTLR_LUNID, 8) == 0;
}
static inline int is_scsi_rev_5(struct ctlr_info *h)
{
if (!h->hba_inquiry_data)
return 0;
if ((h->hba_inquiry_data[2] & 0x07) == 5)
return 1;
return 0;
}
static int hpsa_find_target_lun(struct ctlr_info *h,
unsigned char scsi3addr[], int bus, int *target, int *lun)
{
int i, found = 0;
DECLARE_BITMAP(lun_taken, HPSA_MAX_DEVICES);
bitmap_zero(lun_taken, HPSA_MAX_DEVICES);
for (i = 0; i < h->ndevices; i++) {
if (h->dev[i]->bus == bus && h->dev[i]->target != -1)
__set_bit(h->dev[i]->target, lun_taken);
}
i = find_first_zero_bit(lun_taken, HPSA_MAX_DEVICES);
if (i < HPSA_MAX_DEVICES) {
*target = i;
*lun = 0;
found = 1;
}
return !found;
}
static void hpsa_show_dev_msg(const char *level, struct ctlr_info *h,
struct hpsa_scsi_dev_t *dev, char *description)
{
#define LABEL_SIZE 25
char label[LABEL_SIZE];
if (h == NULL || h->pdev == NULL || h->scsi_host == NULL)
return;
switch (dev->devtype) {
case TYPE_RAID:
snprintf(label, LABEL_SIZE, "controller");
break;
case TYPE_ENCLOSURE:
snprintf(label, LABEL_SIZE, "enclosure");
break;
case TYPE_DISK:
if (dev->external)
snprintf(label, LABEL_SIZE, "external");
else if (!is_logical_dev_addr_mode(dev->scsi3addr))
snprintf(label, LABEL_SIZE, "%s",
raid_label[PHYSICAL_DRIVE]);
else
snprintf(label, LABEL_SIZE, "RAID-%s",
dev->raid_level > RAID_UNKNOWN ? "?" :
raid_label[dev->raid_level]);
break;
case TYPE_ROM:
snprintf(label, LABEL_SIZE, "rom");
break;
case TYPE_TAPE:
snprintf(label, LABEL_SIZE, "tape");
break;
case TYPE_MEDIUM_CHANGER:
snprintf(label, LABEL_SIZE, "changer");
break;
default:
snprintf(label, LABEL_SIZE, "UNKNOWN");
break;
}
dev_printk(level, &h->pdev->dev,
"scsi %d:%d:%d:%d: %s %s %.8s %.16s %s SSDSmartPathCap%c En%c Exp=%d\n",
h->scsi_host->host_no, dev->bus, dev->target, dev->lun,
description,
scsi_device_type(dev->devtype),
dev->vendor,
dev->model,
label,
dev->offload_config ? '+' : '-',
dev->offload_enabled ? '+' : '-',
dev->expose_device);
}
static int hpsa_scsi_add_entry(struct ctlr_info *h,
struct hpsa_scsi_dev_t *device,
struct hpsa_scsi_dev_t *added[], int *nadded)
{
int n = h->ndevices;
int i;
unsigned char addr1[8], addr2[8];
struct hpsa_scsi_dev_t *sd;
if (n >= HPSA_MAX_DEVICES) {
dev_err(&h->pdev->dev, "too many devices, some will be "
"inaccessible.\n");
return -1;
}
if (device->lun != -1)
goto lun_assigned;
if (device->scsi3addr[4] == 0) {
if (hpsa_find_target_lun(h, device->scsi3addr,
device->bus, &device->target, &device->lun) != 0)
return -1;
goto lun_assigned;
}
memcpy(addr1, device->scsi3addr, 8);
addr1[4] = 0;
addr1[5] = 0;
for (i = 0; i < n; i++) {
sd = h->dev[i];
memcpy(addr2, sd->scsi3addr, 8);
addr2[4] = 0;
addr2[5] = 0;
if (memcmp(addr1, addr2, 8) == 0) {
device->bus = sd->bus;
device->target = sd->target;
device->lun = device->scsi3addr[4];
break;
}
}
if (device->lun == -1) {
dev_warn(&h->pdev->dev, "physical device with no LUN=0,"
" suspect firmware bug or unsupported hardware "
"configuration.\n");
return -1;
}
lun_assigned:
h->dev[n] = device;
h->ndevices++;
added[*nadded] = device;
(*nadded)++;
hpsa_show_dev_msg(KERN_INFO, h, device,
device->expose_device ? "added" : "masked");
device->offload_to_be_enabled = device->offload_enabled;
device->offload_enabled = 0;
return 0;
}
static void hpsa_scsi_update_entry(struct ctlr_info *h,
int entry, struct hpsa_scsi_dev_t *new_entry)
{
int offload_enabled;
BUG_ON(entry < 0 || entry >= HPSA_MAX_DEVICES);
h->dev[entry]->raid_level = new_entry->raid_level;
if (new_entry->offload_config && new_entry->offload_enabled) {
h->dev[entry]->raid_map = new_entry->raid_map;
h->dev[entry]->ioaccel_handle = new_entry->ioaccel_handle;
}
if (new_entry->hba_ioaccel_enabled) {
h->dev[entry]->ioaccel_handle = new_entry->ioaccel_handle;
wmb();
}
h->dev[entry]->hba_ioaccel_enabled = new_entry->hba_ioaccel_enabled;
h->dev[entry]->offload_config = new_entry->offload_config;
h->dev[entry]->offload_to_mirror = new_entry->offload_to_mirror;
h->dev[entry]->queue_depth = new_entry->queue_depth;
h->dev[entry]->offload_to_be_enabled = new_entry->offload_enabled;
if (!new_entry->offload_enabled)
h->dev[entry]->offload_enabled = 0;
offload_enabled = h->dev[entry]->offload_enabled;
h->dev[entry]->offload_enabled = h->dev[entry]->offload_to_be_enabled;
hpsa_show_dev_msg(KERN_INFO, h, h->dev[entry], "updated");
h->dev[entry]->offload_enabled = offload_enabled;
}
static void hpsa_scsi_replace_entry(struct ctlr_info *h,
int entry, struct hpsa_scsi_dev_t *new_entry,
struct hpsa_scsi_dev_t *added[], int *nadded,
struct hpsa_scsi_dev_t *removed[], int *nremoved)
{
BUG_ON(entry < 0 || entry >= HPSA_MAX_DEVICES);
removed[*nremoved] = h->dev[entry];
(*nremoved)++;
if (new_entry->target == -1) {
new_entry->target = h->dev[entry]->target;
new_entry->lun = h->dev[entry]->lun;
}
h->dev[entry] = new_entry;
added[*nadded] = new_entry;
(*nadded)++;
hpsa_show_dev_msg(KERN_INFO, h, new_entry, "replaced");
new_entry->offload_to_be_enabled = new_entry->offload_enabled;
new_entry->offload_enabled = 0;
}
static void hpsa_scsi_remove_entry(struct ctlr_info *h, int entry,
struct hpsa_scsi_dev_t *removed[], int *nremoved)
{
int i;
struct hpsa_scsi_dev_t *sd;
BUG_ON(entry < 0 || entry >= HPSA_MAX_DEVICES);
sd = h->dev[entry];
removed[*nremoved] = h->dev[entry];
(*nremoved)++;
for (i = entry; i < h->ndevices-1; i++)
h->dev[i] = h->dev[i+1];
h->ndevices--;
hpsa_show_dev_msg(KERN_INFO, h, sd, "removed");
}
static void fixup_botched_add(struct ctlr_info *h,
struct hpsa_scsi_dev_t *added)
{
unsigned long flags;
int i, j;
spin_lock_irqsave(&h->lock, flags);
for (i = 0; i < h->ndevices; i++) {
if (h->dev[i] == added) {
for (j = i; j < h->ndevices-1; j++)
h->dev[j] = h->dev[j+1];
h->ndevices--;
break;
}
}
spin_unlock_irqrestore(&h->lock, flags);
kfree(added);
}
static inline int device_is_the_same(struct hpsa_scsi_dev_t *dev1,
struct hpsa_scsi_dev_t *dev2)
{
if (memcmp(dev1->scsi3addr, dev2->scsi3addr,
sizeof(dev1->scsi3addr)) != 0)
return 0;
if (memcmp(dev1->device_id, dev2->device_id,
sizeof(dev1->device_id)) != 0)
return 0;
if (memcmp(dev1->model, dev2->model, sizeof(dev1->model)) != 0)
return 0;
if (memcmp(dev1->vendor, dev2->vendor, sizeof(dev1->vendor)) != 0)
return 0;
if (dev1->devtype != dev2->devtype)
return 0;
if (dev1->bus != dev2->bus)
return 0;
return 1;
}
static inline int device_updated(struct hpsa_scsi_dev_t *dev1,
struct hpsa_scsi_dev_t *dev2)
{
if (dev1->raid_level != dev2->raid_level)
return 1;
if (dev1->offload_config != dev2->offload_config)
return 1;
if (dev1->offload_enabled != dev2->offload_enabled)
return 1;
if (!is_logical_dev_addr_mode(dev1->scsi3addr))
if (dev1->queue_depth != dev2->queue_depth)
return 1;
return 0;
}
static int hpsa_scsi_find_entry(struct hpsa_scsi_dev_t *needle,
struct hpsa_scsi_dev_t *haystack[], int haystack_size,
int *index)
{
int i;
#define DEVICE_NOT_FOUND 0
#define DEVICE_CHANGED 1
#define DEVICE_SAME 2
#define DEVICE_UPDATED 3
if (needle == NULL)
return DEVICE_NOT_FOUND;
for (i = 0; i < haystack_size; i++) {
if (haystack[i] == NULL)
continue;
if (SCSI3ADDR_EQ(needle->scsi3addr, haystack[i]->scsi3addr)) {
*index = i;
if (device_is_the_same(needle, haystack[i])) {
if (device_updated(needle, haystack[i]))
return DEVICE_UPDATED;
return DEVICE_SAME;
} else {
if (needle->volume_offline)
return DEVICE_NOT_FOUND;
return DEVICE_CHANGED;
}
}
}
*index = -1;
return DEVICE_NOT_FOUND;
}
static void hpsa_monitor_offline_device(struct ctlr_info *h,
unsigned char scsi3addr[])
{
struct offline_device_entry *device;
unsigned long flags;
spin_lock_irqsave(&h->offline_device_lock, flags);
list_for_each_entry(device, &h->offline_device_list, offline_list) {
if (memcmp(device->scsi3addr, scsi3addr,
sizeof(device->scsi3addr)) == 0) {
spin_unlock_irqrestore(&h->offline_device_lock, flags);
return;
}
}
spin_unlock_irqrestore(&h->offline_device_lock, flags);
device = kmalloc(sizeof(*device), GFP_KERNEL);
if (!device) {
dev_warn(&h->pdev->dev, "out of memory in %s\n", __func__);
return;
}
memcpy(device->scsi3addr, scsi3addr, sizeof(device->scsi3addr));
spin_lock_irqsave(&h->offline_device_lock, flags);
list_add_tail(&device->offline_list, &h->offline_device_list);
spin_unlock_irqrestore(&h->offline_device_lock, flags);
}
static void hpsa_show_volume_status(struct ctlr_info *h,
struct hpsa_scsi_dev_t *sd)
{
if (sd->volume_offline == HPSA_VPD_LV_STATUS_UNSUPPORTED)
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume status is not available through vital product data pages.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
switch (sd->volume_offline) {
case HPSA_LV_OK:
break;
case HPSA_LV_UNDERGOING_ERASE:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is undergoing background erase process.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_NOT_AVAILABLE:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is waiting for transforming volume.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_UNDERGOING_RPI:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is undergoing rapid parity init.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_PENDING_RPI:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is queued for rapid parity initialization process.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_ENCRYPTED_NO_KEY:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is encrypted and cannot be accessed because key is not present.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_PLAINTEXT_IN_ENCRYPT_ONLY_CONTROLLER:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is not encrypted and cannot be accessed because controller is in encryption-only mode.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_UNDERGOING_ENCRYPTION:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is undergoing encryption process.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_UNDERGOING_ENCRYPTION_REKEYING:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is undergoing encryption re-keying process.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_ENCRYPTED_IN_NON_ENCRYPTED_CONTROLLER:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is encrypted and cannot be accessed because controller does not have encryption enabled.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_PENDING_ENCRYPTION:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is pending migration to encrypted state, but process has not started.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
case HPSA_LV_PENDING_ENCRYPTION_REKEYING:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is encrypted and is pending encryption rekeying.\n",
h->scsi_host->host_no,
sd->bus, sd->target, sd->lun);
break;
}
}
static void hpsa_figure_phys_disk_ptrs(struct ctlr_info *h,
struct hpsa_scsi_dev_t *dev[], int ndevices,
struct hpsa_scsi_dev_t *logical_drive)
{
struct raid_map_data *map = &logical_drive->raid_map;
struct raid_map_disk_data *dd = &map->data[0];
int i, j;
int total_disks_per_row = le16_to_cpu(map->data_disks_per_row) +
le16_to_cpu(map->metadata_disks_per_row);
int nraid_map_entries = le16_to_cpu(map->row_cnt) *
le16_to_cpu(map->layout_map_count) *
total_disks_per_row;
int nphys_disk = le16_to_cpu(map->layout_map_count) *
total_disks_per_row;
int qdepth;
if (nraid_map_entries > RAID_MAP_MAX_ENTRIES)
nraid_map_entries = RAID_MAP_MAX_ENTRIES;
logical_drive->nphysical_disks = nraid_map_entries;
qdepth = 0;
for (i = 0; i < nraid_map_entries; i++) {
logical_drive->phys_disk[i] = NULL;
if (!logical_drive->offload_config)
continue;
for (j = 0; j < ndevices; j++) {
if (dev[j] == NULL)
continue;
if (dev[j]->devtype != TYPE_DISK)
continue;
if (is_logical_device(dev[j]))
continue;
if (dev[j]->ioaccel_handle != dd[i].ioaccel_handle)
continue;
logical_drive->phys_disk[i] = dev[j];
if (i < nphys_disk)
qdepth = min(h->nr_cmds, qdepth +
logical_drive->phys_disk[i]->queue_depth);
break;
}
if (!logical_drive->phys_disk[i]) {
logical_drive->offload_enabled = 0;
logical_drive->offload_to_be_enabled = 0;
logical_drive->queue_depth = 8;
}
}
if (nraid_map_entries)
logical_drive->queue_depth = qdepth;
else
logical_drive->queue_depth = h->nr_cmds;
}
static void hpsa_update_log_drive_phys_drive_ptrs(struct ctlr_info *h,
struct hpsa_scsi_dev_t *dev[], int ndevices)
{
int i;
for (i = 0; i < ndevices; i++) {
if (dev[i] == NULL)
continue;
if (dev[i]->devtype != TYPE_DISK)
continue;
if (!is_logical_device(dev[i]))
continue;
if (dev[i]->offload_enabled)
continue;
hpsa_figure_phys_disk_ptrs(h, dev, ndevices, dev[i]);
}
}
static int hpsa_add_device(struct ctlr_info *h, struct hpsa_scsi_dev_t *device)
{
int rc = 0;
if (!h->scsi_host)
return 1;
if (is_logical_device(device))
rc = scsi_add_device(h->scsi_host, device->bus,
device->target, device->lun);
else
rc = hpsa_add_sas_device(h->sas_host, device);
return rc;
}
static void hpsa_remove_device(struct ctlr_info *h,
struct hpsa_scsi_dev_t *device)
{
struct scsi_device *sdev = NULL;
if (!h->scsi_host)
return;
if (is_logical_device(device)) {
sdev = scsi_device_lookup(h->scsi_host, device->bus,
device->target, device->lun);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
} else {
hpsa_show_dev_msg(KERN_WARNING, h, device,
"didn't find device for removal.");
}
} else
hpsa_remove_sas_device(device);
}
static void adjust_hpsa_scsi_table(struct ctlr_info *h,
struct hpsa_scsi_dev_t *sd[], int nsds)
{
int i, entry, device_change, changes = 0;
struct hpsa_scsi_dev_t *csd;
unsigned long flags;
struct hpsa_scsi_dev_t **added, **removed;
int nadded, nremoved;
if (h->reset_in_progress) {
h->drv_req_rescan = 1;
return;
}
added = kzalloc(sizeof(*added) * HPSA_MAX_DEVICES, GFP_KERNEL);
removed = kzalloc(sizeof(*removed) * HPSA_MAX_DEVICES, GFP_KERNEL);
if (!added || !removed) {
dev_warn(&h->pdev->dev, "out of memory in "
"adjust_hpsa_scsi_table\n");
goto free_and_out;
}
spin_lock_irqsave(&h->devlock, flags);
i = 0;
nremoved = 0;
nadded = 0;
while (i < h->ndevices) {
csd = h->dev[i];
device_change = hpsa_scsi_find_entry(csd, sd, nsds, &entry);
if (device_change == DEVICE_NOT_FOUND) {
changes++;
hpsa_scsi_remove_entry(h, i, removed, &nremoved);
continue;
} else if (device_change == DEVICE_CHANGED) {
changes++;
hpsa_scsi_replace_entry(h, i, sd[entry],
added, &nadded, removed, &nremoved);
sd[entry] = NULL;
} else if (device_change == DEVICE_UPDATED) {
hpsa_scsi_update_entry(h, i, sd[entry]);
}
i++;
}
for (i = 0; i < nsds; i++) {
if (!sd[i])
continue;
if (sd[i]->volume_offline) {
hpsa_show_volume_status(h, sd[i]);
hpsa_show_dev_msg(KERN_INFO, h, sd[i], "offline");
continue;
}
device_change = hpsa_scsi_find_entry(sd[i], h->dev,
h->ndevices, &entry);
if (device_change == DEVICE_NOT_FOUND) {
changes++;
if (hpsa_scsi_add_entry(h, sd[i], added, &nadded) != 0)
break;
sd[i] = NULL;
} else if (device_change == DEVICE_CHANGED) {
changes++;
dev_warn(&h->pdev->dev,
"device unexpectedly changed.\n");
}
}
hpsa_update_log_drive_phys_drive_ptrs(h, h->dev, h->ndevices);
for (i = 0; i < h->ndevices; i++) {
if (h->dev[i] == NULL)
continue;
h->dev[i]->offload_enabled = h->dev[i]->offload_to_be_enabled;
}
spin_unlock_irqrestore(&h->devlock, flags);
for (i = 0; i < nsds; i++) {
if (!sd[i])
continue;
if (sd[i]->volume_offline)
hpsa_monitor_offline_device(h, sd[i]->scsi3addr);
}
if (!changes)
goto free_and_out;
for (i = 0; i < nremoved; i++) {
if (removed[i] == NULL)
continue;
if (removed[i]->expose_device)
hpsa_remove_device(h, removed[i]);
kfree(removed[i]);
removed[i] = NULL;
}
for (i = 0; i < nadded; i++) {
int rc = 0;
if (added[i] == NULL)
continue;
if (!(added[i]->expose_device))
continue;
rc = hpsa_add_device(h, added[i]);
if (!rc)
continue;
dev_warn(&h->pdev->dev,
"addition failed %d, device not added.", rc);
fixup_botched_add(h, added[i]);
h->drv_req_rescan = 1;
}
free_and_out:
kfree(added);
kfree(removed);
}
static struct hpsa_scsi_dev_t *lookup_hpsa_scsi_dev(struct ctlr_info *h,
int bus, int target, int lun)
{
int i;
struct hpsa_scsi_dev_t *sd;
for (i = 0; i < h->ndevices; i++) {
sd = h->dev[i];
if (sd->bus == bus && sd->target == target && sd->lun == lun)
return sd;
}
return NULL;
}
static int hpsa_slave_alloc(struct scsi_device *sdev)
{
struct hpsa_scsi_dev_t *sd;
unsigned long flags;
struct ctlr_info *h;
h = sdev_to_hba(sdev);
spin_lock_irqsave(&h->devlock, flags);
if (sdev_channel(sdev) == HPSA_PHYSICAL_DEVICE_BUS) {
struct scsi_target *starget;
struct sas_rphy *rphy;
starget = scsi_target(sdev);
rphy = target_to_rphy(starget);
sd = hpsa_find_device_by_sas_rphy(h, rphy);
if (sd) {
sd->target = sdev_id(sdev);
sd->lun = sdev->lun;
}
} else
sd = lookup_hpsa_scsi_dev(h, sdev_channel(sdev),
sdev_id(sdev), sdev->lun);
if (sd && sd->expose_device) {
atomic_set(&sd->ioaccel_cmds_out, 0);
sdev->hostdata = sd;
} else
sdev->hostdata = NULL;
spin_unlock_irqrestore(&h->devlock, flags);
return 0;
}
static int hpsa_slave_configure(struct scsi_device *sdev)
{
struct hpsa_scsi_dev_t *sd;
int queue_depth;
sd = sdev->hostdata;
sdev->no_uld_attach = !sd || !sd->expose_device;
if (sd)
queue_depth = sd->queue_depth != 0 ?
sd->queue_depth : sdev->host->can_queue;
else
queue_depth = sdev->host->can_queue;
scsi_change_queue_depth(sdev, queue_depth);
return 0;
}
static void hpsa_slave_destroy(struct scsi_device *sdev)
{
}
static void hpsa_free_ioaccel2_sg_chain_blocks(struct ctlr_info *h)
{
int i;
if (!h->ioaccel2_cmd_sg_list)
return;
for (i = 0; i < h->nr_cmds; i++) {
kfree(h->ioaccel2_cmd_sg_list[i]);
h->ioaccel2_cmd_sg_list[i] = NULL;
}
kfree(h->ioaccel2_cmd_sg_list);
h->ioaccel2_cmd_sg_list = NULL;
}
static int hpsa_allocate_ioaccel2_sg_chain_blocks(struct ctlr_info *h)
{
int i;
if (h->chainsize <= 0)
return 0;
h->ioaccel2_cmd_sg_list =
kzalloc(sizeof(*h->ioaccel2_cmd_sg_list) * h->nr_cmds,
GFP_KERNEL);
if (!h->ioaccel2_cmd_sg_list)
return -ENOMEM;
for (i = 0; i < h->nr_cmds; i++) {
h->ioaccel2_cmd_sg_list[i] =
kmalloc(sizeof(*h->ioaccel2_cmd_sg_list[i]) *
h->maxsgentries, GFP_KERNEL);
if (!h->ioaccel2_cmd_sg_list[i])
goto clean;
}
return 0;
clean:
hpsa_free_ioaccel2_sg_chain_blocks(h);
return -ENOMEM;
}
static void hpsa_free_sg_chain_blocks(struct ctlr_info *h)
{
int i;
if (!h->cmd_sg_list)
return;
for (i = 0; i < h->nr_cmds; i++) {
kfree(h->cmd_sg_list[i]);
h->cmd_sg_list[i] = NULL;
}
kfree(h->cmd_sg_list);
h->cmd_sg_list = NULL;
}
static int hpsa_alloc_sg_chain_blocks(struct ctlr_info *h)
{
int i;
if (h->chainsize <= 0)
return 0;
h->cmd_sg_list = kzalloc(sizeof(*h->cmd_sg_list) * h->nr_cmds,
GFP_KERNEL);
if (!h->cmd_sg_list) {
dev_err(&h->pdev->dev, "Failed to allocate SG list\n");
return -ENOMEM;
}
for (i = 0; i < h->nr_cmds; i++) {
h->cmd_sg_list[i] = kmalloc(sizeof(*h->cmd_sg_list[i]) *
h->chainsize, GFP_KERNEL);
if (!h->cmd_sg_list[i]) {
dev_err(&h->pdev->dev, "Failed to allocate cmd SG\n");
goto clean;
}
}
return 0;
clean:
hpsa_free_sg_chain_blocks(h);
return -ENOMEM;
}
static int hpsa_map_ioaccel2_sg_chain_block(struct ctlr_info *h,
struct io_accel2_cmd *cp, struct CommandList *c)
{
struct ioaccel2_sg_element *chain_block;
u64 temp64;
u32 chain_size;
chain_block = h->ioaccel2_cmd_sg_list[c->cmdindex];
chain_size = le32_to_cpu(cp->sg[0].length);
temp64 = pci_map_single(h->pdev, chain_block, chain_size,
PCI_DMA_TODEVICE);
if (dma_mapping_error(&h->pdev->dev, temp64)) {
cp->sg->address = 0;
return -1;
}
cp->sg->address = cpu_to_le64(temp64);
return 0;
}
static void hpsa_unmap_ioaccel2_sg_chain_block(struct ctlr_info *h,
struct io_accel2_cmd *cp)
{
struct ioaccel2_sg_element *chain_sg;
u64 temp64;
u32 chain_size;
chain_sg = cp->sg;
temp64 = le64_to_cpu(chain_sg->address);
chain_size = le32_to_cpu(cp->sg[0].length);
pci_unmap_single(h->pdev, temp64, chain_size, PCI_DMA_TODEVICE);
}
static int hpsa_map_sg_chain_block(struct ctlr_info *h,
struct CommandList *c)
{
struct SGDescriptor *chain_sg, *chain_block;
u64 temp64;
u32 chain_len;
chain_sg = &c->SG[h->max_cmd_sg_entries - 1];
chain_block = h->cmd_sg_list[c->cmdindex];
chain_sg->Ext = cpu_to_le32(HPSA_SG_CHAIN);
chain_len = sizeof(*chain_sg) *
(le16_to_cpu(c->Header.SGTotal) - h->max_cmd_sg_entries);
chain_sg->Len = cpu_to_le32(chain_len);
temp64 = pci_map_single(h->pdev, chain_block, chain_len,
PCI_DMA_TODEVICE);
if (dma_mapping_error(&h->pdev->dev, temp64)) {
chain_sg->Addr = cpu_to_le64(0);
return -1;
}
chain_sg->Addr = cpu_to_le64(temp64);
return 0;
}
static void hpsa_unmap_sg_chain_block(struct ctlr_info *h,
struct CommandList *c)
{
struct SGDescriptor *chain_sg;
if (le16_to_cpu(c->Header.SGTotal) <= h->max_cmd_sg_entries)
return;
chain_sg = &c->SG[h->max_cmd_sg_entries - 1];
pci_unmap_single(h->pdev, le64_to_cpu(chain_sg->Addr),
le32_to_cpu(chain_sg->Len), PCI_DMA_TODEVICE);
}
static int handle_ioaccel_mode2_error(struct ctlr_info *h,
struct CommandList *c,
struct scsi_cmnd *cmd,
struct io_accel2_cmd *c2)
{
int data_len;
int retry = 0;
u32 ioaccel2_resid = 0;
switch (c2->error_data.serv_response) {
case IOACCEL2_SERV_RESPONSE_COMPLETE:
switch (c2->error_data.status) {
case IOACCEL2_STATUS_SR_TASK_COMP_GOOD:
break;
case IOACCEL2_STATUS_SR_TASK_COMP_CHK_COND:
cmd->result |= SAM_STAT_CHECK_CONDITION;
if (c2->error_data.data_present !=
IOACCEL2_SENSE_DATA_PRESENT) {
memset(cmd->sense_buffer, 0,
SCSI_SENSE_BUFFERSIZE);
break;
}
data_len = c2->error_data.sense_data_len;
if (data_len > SCSI_SENSE_BUFFERSIZE)
data_len = SCSI_SENSE_BUFFERSIZE;
if (data_len > sizeof(c2->error_data.sense_data_buff))
data_len =
sizeof(c2->error_data.sense_data_buff);
memcpy(cmd->sense_buffer,
c2->error_data.sense_data_buff, data_len);
retry = 1;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_BUSY:
retry = 1;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_RES_CON:
retry = 1;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_SET_FULL:
retry = 1;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_ABORTED:
retry = 1;
break;
default:
retry = 1;
break;
}
break;
case IOACCEL2_SERV_RESPONSE_FAILURE:
switch (c2->error_data.status) {
case IOACCEL2_STATUS_SR_IO_ERROR:
case IOACCEL2_STATUS_SR_IO_ABORTED:
case IOACCEL2_STATUS_SR_OVERRUN:
retry = 1;
break;
case IOACCEL2_STATUS_SR_UNDERRUN:
cmd->result = (DID_OK << 16);
cmd->result |= (COMMAND_COMPLETE << 8);
ioaccel2_resid = get_unaligned_le32(
&c2->error_data.resid_cnt[0]);
scsi_set_resid(cmd, ioaccel2_resid);
break;
case IOACCEL2_STATUS_SR_NO_PATH_TO_DEVICE:
case IOACCEL2_STATUS_SR_INVALID_DEVICE:
case IOACCEL2_STATUS_SR_IOACCEL_DISABLED:
retry = 1;
break;
default:
retry = 1;
}
break;
case IOACCEL2_SERV_RESPONSE_TMF_COMPLETE:
break;
case IOACCEL2_SERV_RESPONSE_TMF_SUCCESS:
break;
case IOACCEL2_SERV_RESPONSE_TMF_REJECTED:
retry = 1;
break;
case IOACCEL2_SERV_RESPONSE_TMF_WRONG_LUN:
break;
default:
retry = 1;
break;
}
return retry;
}
static void hpsa_cmd_resolve_events(struct ctlr_info *h,
struct CommandList *c)
{
bool do_wake = false;
c->scsi_cmd = SCSI_CMD_IDLE;
mb();
if (c->abort_pending) {
do_wake = true;
c->abort_pending = false;
}
if (c->reset_pending) {
unsigned long flags;
struct hpsa_scsi_dev_t *dev;
spin_lock_irqsave(&h->lock, flags);
dev = c->reset_pending;
if (dev && atomic_dec_and_test(&dev->reset_cmds_out))
do_wake = true;
c->reset_pending = NULL;
spin_unlock_irqrestore(&h->lock, flags);
}
if (do_wake)
wake_up_all(&h->event_sync_wait_queue);
}
static void hpsa_cmd_resolve_and_free(struct ctlr_info *h,
struct CommandList *c)
{
hpsa_cmd_resolve_events(h, c);
cmd_tagged_free(h, c);
}
static void hpsa_cmd_free_and_done(struct ctlr_info *h,
struct CommandList *c, struct scsi_cmnd *cmd)
{
hpsa_cmd_resolve_and_free(h, c);
cmd->scsi_done(cmd);
}
static void hpsa_retry_cmd(struct ctlr_info *h, struct CommandList *c)
{
INIT_WORK(&c->work, hpsa_command_resubmit_worker);
queue_work_on(raw_smp_processor_id(), h->resubmit_wq, &c->work);
}
static void hpsa_set_scsi_cmd_aborted(struct scsi_cmnd *cmd)
{
cmd->result = DID_ABORT << 16;
}
static void hpsa_cmd_abort_and_free(struct ctlr_info *h, struct CommandList *c,
struct scsi_cmnd *cmd)
{
hpsa_set_scsi_cmd_aborted(cmd);
dev_warn(&h->pdev->dev, "CDB %16phN was aborted with status 0x%x\n",
c->Request.CDB, c->err_info->ScsiStatus);
hpsa_cmd_resolve_and_free(h, c);
}
static void process_ioaccel2_completion(struct ctlr_info *h,
struct CommandList *c, struct scsi_cmnd *cmd,
struct hpsa_scsi_dev_t *dev)
{
struct io_accel2_cmd *c2 = &h->ioaccel2_cmd_pool[c->cmdindex];
if (likely(c2->error_data.serv_response == 0 &&
c2->error_data.status == 0))
return hpsa_cmd_free_and_done(h, c, cmd);
if (is_logical_device(dev) &&
c2->error_data.serv_response ==
IOACCEL2_SERV_RESPONSE_FAILURE) {
if (c2->error_data.status ==
IOACCEL2_STATUS_SR_IOACCEL_DISABLED)
dev->offload_enabled = 0;
return hpsa_retry_cmd(h, c);
}
if (handle_ioaccel_mode2_error(h, c, cmd, c2))
return hpsa_retry_cmd(h, c);
return hpsa_cmd_free_and_done(h, c, cmd);
}
static int hpsa_evaluate_tmf_status(struct ctlr_info *h,
struct CommandList *cp)
{
u8 tmf_status = cp->err_info->ScsiStatus;
switch (tmf_status) {
case CISS_TMF_COMPLETE:
case CISS_TMF_SUCCESS:
return 0;
case CISS_TMF_INVALID_FRAME:
case CISS_TMF_NOT_SUPPORTED:
case CISS_TMF_FAILED:
case CISS_TMF_WRONG_LUN:
case CISS_TMF_OVERLAPPED_TAG:
break;
default:
dev_warn(&h->pdev->dev, "Unknown TMF status: 0x%02x\n",
tmf_status);
break;
}
return -tmf_status;
}
static void complete_scsi_command(struct CommandList *cp)
{
struct scsi_cmnd *cmd;
struct ctlr_info *h;
struct ErrorInfo *ei;
struct hpsa_scsi_dev_t *dev;
struct io_accel2_cmd *c2;
u8 sense_key;
u8 asc;
u8 ascq;
unsigned long sense_data_size;
ei = cp->err_info;
cmd = cp->scsi_cmd;
h = cp->h;
dev = cmd->device->hostdata;
c2 = &h->ioaccel2_cmd_pool[cp->cmdindex];
scsi_dma_unmap(cmd);
if ((cp->cmd_type == CMD_SCSI) &&
(le16_to_cpu(cp->Header.SGTotal) > h->max_cmd_sg_entries))
hpsa_unmap_sg_chain_block(h, cp);
if ((cp->cmd_type == CMD_IOACCEL2) &&
(c2->sg[0].chain_indicator == IOACCEL2_CHAIN))
hpsa_unmap_ioaccel2_sg_chain_block(h, c2);
cmd->result = (DID_OK << 16);
cmd->result |= (COMMAND_COMPLETE << 8);
if (cp->cmd_type == CMD_IOACCEL2 || cp->cmd_type == CMD_IOACCEL1)
atomic_dec(&cp->phys_disk->ioaccel_cmds_out);
if (unlikely(ei->CommandStatus == CMD_CTLR_LOCKUP)) {
cmd->result = DID_NO_CONNECT << 16;
return hpsa_cmd_free_and_done(h, cp, cmd);
}
if ((unlikely(hpsa_is_pending_event(cp)))) {
if (cp->reset_pending)
return hpsa_cmd_resolve_and_free(h, cp);
if (cp->abort_pending)
return hpsa_cmd_abort_and_free(h, cp, cmd);
}
if (cp->cmd_type == CMD_IOACCEL2)
return process_ioaccel2_completion(h, cp, cmd, dev);
scsi_set_resid(cmd, ei->ResidualCnt);
if (ei->CommandStatus == 0)
return hpsa_cmd_free_and_done(h, cp, cmd);
if (cp->cmd_type == CMD_IOACCEL1) {
struct io_accel1_cmd *c = &h->ioaccel_cmd_pool[cp->cmdindex];
cp->Header.SGList = scsi_sg_count(cmd);
cp->Header.SGTotal = cpu_to_le16(cp->Header.SGList);
cp->Request.CDBLen = le16_to_cpu(c->io_flags) &
IOACCEL1_IOFLAGS_CDBLEN_MASK;
cp->Header.tag = c->tag;
memcpy(cp->Header.LUN.LunAddrBytes, c->CISS_LUN, 8);
memcpy(cp->Request.CDB, c->CDB, cp->Request.CDBLen);
if (is_logical_device(dev)) {
if (ei->CommandStatus == CMD_IOACCEL_DISABLED)
dev->offload_enabled = 0;
return hpsa_retry_cmd(h, cp);
}
}
switch (ei->CommandStatus) {
case CMD_TARGET_STATUS:
cmd->result |= ei->ScsiStatus;
if (SCSI_SENSE_BUFFERSIZE < sizeof(ei->SenseInfo))
sense_data_size = SCSI_SENSE_BUFFERSIZE;
else
sense_data_size = sizeof(ei->SenseInfo);
if (ei->SenseLen < sense_data_size)
sense_data_size = ei->SenseLen;
memcpy(cmd->sense_buffer, ei->SenseInfo, sense_data_size);
if (ei->ScsiStatus)
decode_sense_data(ei->SenseInfo, sense_data_size,
&sense_key, &asc, &ascq);
if (ei->ScsiStatus == SAM_STAT_CHECK_CONDITION) {
if (sense_key == ABORTED_COMMAND) {
cmd->result |= DID_SOFT_ERROR << 16;
break;
}
break;
}
if (ei->ScsiStatus) {
dev_warn(&h->pdev->dev, "cp %p has status 0x%x "
"Sense: 0x%x, ASC: 0x%x, ASCQ: 0x%x, "
"Returning result: 0x%x\n",
cp, ei->ScsiStatus,
sense_key, asc, ascq,
cmd->result);
} else {
dev_warn(&h->pdev->dev, "cp %p SCSI status was 0. "
"Returning no connection.\n", cp),
cmd->result = DID_NO_CONNECT << 16;
}
break;
case CMD_DATA_UNDERRUN:
break;
case CMD_DATA_OVERRUN:
dev_warn(&h->pdev->dev,
"CDB %16phN data overrun\n", cp->Request.CDB);
break;
case CMD_INVALID: {
cmd->result = DID_NO_CONNECT << 16;
}
break;
case CMD_PROTOCOL_ERR:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "CDB %16phN : protocol error\n",
cp->Request.CDB);
break;
case CMD_HARDWARE_ERR:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "CDB %16phN : hardware error\n",
cp->Request.CDB);
break;
case CMD_CONNECTION_LOST:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "CDB %16phN : connection lost\n",
cp->Request.CDB);
break;
case CMD_ABORTED:
return hpsa_cmd_abort_and_free(h, cp, cmd);
case CMD_ABORT_FAILED:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "CDB %16phN : abort failed\n",
cp->Request.CDB);
break;
case CMD_UNSOLICITED_ABORT:
cmd->result = DID_SOFT_ERROR << 16;
dev_warn(&h->pdev->dev, "CDB %16phN : unsolicited abort\n",
cp->Request.CDB);
break;
case CMD_TIMEOUT:
cmd->result = DID_TIME_OUT << 16;
dev_warn(&h->pdev->dev, "CDB %16phN timed out\n",
cp->Request.CDB);
break;
case CMD_UNABORTABLE:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "Command unabortable\n");
break;
case CMD_TMF_STATUS:
if (hpsa_evaluate_tmf_status(h, cp))
cmd->result = DID_ERROR << 16;
break;
case CMD_IOACCEL_DISABLED:
cmd->result = DID_SOFT_ERROR << 16;
dev_warn(&h->pdev->dev,
"cp %p had HP SSD Smart Path error\n", cp);
break;
default:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "cp %p returned unknown status %x\n",
cp, ei->CommandStatus);
}
return hpsa_cmd_free_and_done(h, cp, cmd);
}
static void hpsa_pci_unmap(struct pci_dev *pdev,
struct CommandList *c, int sg_used, int data_direction)
{
int i;
for (i = 0; i < sg_used; i++)
pci_unmap_single(pdev, (dma_addr_t) le64_to_cpu(c->SG[i].Addr),
le32_to_cpu(c->SG[i].Len),
data_direction);
}
static int hpsa_map_one(struct pci_dev *pdev,
struct CommandList *cp,
unsigned char *buf,
size_t buflen,
int data_direction)
{
u64 addr64;
if (buflen == 0 || data_direction == PCI_DMA_NONE) {
cp->Header.SGList = 0;
cp->Header.SGTotal = cpu_to_le16(0);
return 0;
}
addr64 = pci_map_single(pdev, buf, buflen, data_direction);
if (dma_mapping_error(&pdev->dev, addr64)) {
cp->Header.SGList = 0;
cp->Header.SGTotal = cpu_to_le16(0);
return -1;
}
cp->SG[0].Addr = cpu_to_le64(addr64);
cp->SG[0].Len = cpu_to_le32(buflen);
cp->SG[0].Ext = cpu_to_le32(HPSA_SG_LAST);
cp->Header.SGList = 1;
cp->Header.SGTotal = cpu_to_le16(1);
return 0;
}
static int hpsa_scsi_do_simple_cmd_core(struct ctlr_info *h,
struct CommandList *c, int reply_queue, unsigned long timeout_msecs)
{
DECLARE_COMPLETION_ONSTACK(wait);
c->waiting = &wait;
__enqueue_cmd_and_start_io(h, c, reply_queue);
if (timeout_msecs == NO_TIMEOUT) {
wait_for_completion_io(&wait);
return IO_OK;
}
if (!wait_for_completion_io_timeout(&wait,
msecs_to_jiffies(timeout_msecs))) {
dev_warn(&h->pdev->dev, "Command timed out.\n");
return -ETIMEDOUT;
}
return IO_OK;
}
static int hpsa_scsi_do_simple_cmd(struct ctlr_info *h, struct CommandList *c,
int reply_queue, unsigned long timeout_msecs)
{
if (unlikely(lockup_detected(h))) {
c->err_info->CommandStatus = CMD_CTLR_LOCKUP;
return IO_OK;
}
return hpsa_scsi_do_simple_cmd_core(h, c, reply_queue, timeout_msecs);
}
static u32 lockup_detected(struct ctlr_info *h)
{
int cpu;
u32 rc, *lockup_detected;
cpu = get_cpu();
lockup_detected = per_cpu_ptr(h->lockup_detected, cpu);
rc = *lockup_detected;
put_cpu();
return rc;
}
static int hpsa_scsi_do_simple_cmd_with_retry(struct ctlr_info *h,
struct CommandList *c, int data_direction, unsigned long timeout_msecs)
{
int backoff_time = 10, retry_count = 0;
int rc;
do {
memset(c->err_info, 0, sizeof(*c->err_info));
rc = hpsa_scsi_do_simple_cmd(h, c, DEFAULT_REPLY_QUEUE,
timeout_msecs);
if (rc)
break;
retry_count++;
if (retry_count > 3) {
msleep(backoff_time);
if (backoff_time < 1000)
backoff_time *= 2;
}
} while ((check_for_unit_attention(h, c) ||
check_for_busy(h, c)) &&
retry_count <= MAX_DRIVER_CMD_RETRIES);
hpsa_pci_unmap(h->pdev, c, 1, data_direction);
if (retry_count > MAX_DRIVER_CMD_RETRIES)
rc = -EIO;
return rc;
}
static void hpsa_print_cmd(struct ctlr_info *h, char *txt,
struct CommandList *c)
{
const u8 *cdb = c->Request.CDB;
const u8 *lun = c->Header.LUN.LunAddrBytes;
dev_warn(&h->pdev->dev, "%s: LUN:%02x%02x%02x%02x%02x%02x%02x%02x"
" CDB:%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n",
txt, lun[0], lun[1], lun[2], lun[3],
lun[4], lun[5], lun[6], lun[7],
cdb[0], cdb[1], cdb[2], cdb[3],
cdb[4], cdb[5], cdb[6], cdb[7],
cdb[8], cdb[9], cdb[10], cdb[11],
cdb[12], cdb[13], cdb[14], cdb[15]);
}
static void hpsa_scsi_interpret_error(struct ctlr_info *h,
struct CommandList *cp)
{
const struct ErrorInfo *ei = cp->err_info;
struct device *d = &cp->h->pdev->dev;
u8 sense_key, asc, ascq;
int sense_len;
switch (ei->CommandStatus) {
case CMD_TARGET_STATUS:
if (ei->SenseLen > sizeof(ei->SenseInfo))
sense_len = sizeof(ei->SenseInfo);
else
sense_len = ei->SenseLen;
decode_sense_data(ei->SenseInfo, sense_len,
&sense_key, &asc, &ascq);
hpsa_print_cmd(h, "SCSI status", cp);
if (ei->ScsiStatus == SAM_STAT_CHECK_CONDITION)
dev_warn(d, "SCSI Status = 02, Sense key = 0x%02x, ASC = 0x%02x, ASCQ = 0x%02x\n",
sense_key, asc, ascq);
else
dev_warn(d, "SCSI Status = 0x%02x\n", ei->ScsiStatus);
if (ei->ScsiStatus == 0)
dev_warn(d, "SCSI status is abnormally zero. "
"(probably indicates selection timeout "
"reported incorrectly due to a known "
"firmware bug, circa July, 2001.)\n");
break;
case CMD_DATA_UNDERRUN:
break;
case CMD_DATA_OVERRUN:
hpsa_print_cmd(h, "overrun condition", cp);
break;
case CMD_INVALID: {
hpsa_print_cmd(h, "invalid command", cp);
dev_warn(d, "probably means device no longer present\n");
}
break;
case CMD_PROTOCOL_ERR:
hpsa_print_cmd(h, "protocol error", cp);
break;
case CMD_HARDWARE_ERR:
hpsa_print_cmd(h, "hardware error", cp);
break;
case CMD_CONNECTION_LOST:
hpsa_print_cmd(h, "connection lost", cp);
break;
case CMD_ABORTED:
hpsa_print_cmd(h, "aborted", cp);
break;
case CMD_ABORT_FAILED:
hpsa_print_cmd(h, "abort failed", cp);
break;
case CMD_UNSOLICITED_ABORT:
hpsa_print_cmd(h, "unsolicited abort", cp);
break;
case CMD_TIMEOUT:
hpsa_print_cmd(h, "timed out", cp);
break;
case CMD_UNABORTABLE:
hpsa_print_cmd(h, "unabortable", cp);
break;
case CMD_CTLR_LOCKUP:
hpsa_print_cmd(h, "controller lockup detected", cp);
break;
default:
hpsa_print_cmd(h, "unknown status", cp);
dev_warn(d, "Unknown command status %x\n",
ei->CommandStatus);
}
}
static int hpsa_scsi_do_inquiry(struct ctlr_info *h, unsigned char *scsi3addr,
u16 page, unsigned char *buf,
unsigned char bufsize)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_alloc(h);
if (fill_cmd(c, HPSA_INQUIRY, h, buf, bufsize,
page, scsi3addr, TYPE_CMD)) {
rc = -1;
goto out;
}
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if (rc)
goto out;
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_free(h, c);
return rc;
}
static int hpsa_send_reset(struct ctlr_info *h, unsigned char *scsi3addr,
u8 reset_type, int reply_queue)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_alloc(h);
(void) fill_cmd(c, reset_type, h, NULL, 0, 0,
scsi3addr, TYPE_MSG);
rc = hpsa_scsi_do_simple_cmd(h, c, reply_queue, NO_TIMEOUT);
if (rc) {
dev_warn(&h->pdev->dev, "Failed to send reset command\n");
goto out;
}
ei = c->err_info;
if (ei->CommandStatus != 0) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_free(h, c);
return rc;
}
static bool hpsa_cmd_dev_match(struct ctlr_info *h, struct CommandList *c,
struct hpsa_scsi_dev_t *dev,
unsigned char *scsi3addr)
{
int i;
bool match = false;
struct io_accel2_cmd *c2 = &h->ioaccel2_cmd_pool[c->cmdindex];
struct hpsa_tmf_struct *ac = (struct hpsa_tmf_struct *) c2;
if (hpsa_is_cmd_idle(c))
return false;
switch (c->cmd_type) {
case CMD_SCSI:
case CMD_IOCTL_PEND:
match = !memcmp(scsi3addr, &c->Header.LUN.LunAddrBytes,
sizeof(c->Header.LUN.LunAddrBytes));
break;
case CMD_IOACCEL1:
case CMD_IOACCEL2:
if (c->phys_disk == dev) {
match = true;
} else {
for (i = 0; i < dev->nphysical_disks && !match; i++) {
match = dev->phys_disk[i] == c->phys_disk;
}
}
break;
case IOACCEL2_TMF:
for (i = 0; i < dev->nphysical_disks && !match; i++) {
match = dev->phys_disk[i]->ioaccel_handle ==
le32_to_cpu(ac->it_nexus);
}
break;
case 0:
match = false;
break;
default:
dev_err(&h->pdev->dev, "unexpected cmd_type: %d\n",
c->cmd_type);
BUG();
}
return match;
}
static int hpsa_do_reset(struct ctlr_info *h, struct hpsa_scsi_dev_t *dev,
unsigned char *scsi3addr, u8 reset_type, int reply_queue)
{
int i;
int rc = 0;
if (mutex_lock_interruptible(&h->reset_mutex) == -EINTR) {
dev_warn(&h->pdev->dev, "concurrent reset wait interrupted.\n");
return -EINTR;
}
BUG_ON(atomic_read(&dev->reset_cmds_out) != 0);
for (i = 0; i < h->nr_cmds; i++) {
struct CommandList *c = h->cmd_pool + i;
int refcount = atomic_inc_return(&c->refcount);
if (refcount > 1 && hpsa_cmd_dev_match(h, c, dev, scsi3addr)) {
unsigned long flags;
c->reset_pending = dev;
spin_lock_irqsave(&h->lock, flags);
if (!hpsa_is_cmd_idle(c))
atomic_inc(&dev->reset_cmds_out);
else
c->reset_pending = NULL;
spin_unlock_irqrestore(&h->lock, flags);
}
cmd_free(h, c);
}
rc = hpsa_send_reset(h, scsi3addr, reset_type, reply_queue);
if (!rc)
wait_event(h->event_sync_wait_queue,
atomic_read(&dev->reset_cmds_out) == 0 ||
lockup_detected(h));
if (unlikely(lockup_detected(h))) {
dev_warn(&h->pdev->dev,
"Controller lockup detected during reset wait\n");
rc = -ENODEV;
}
if (unlikely(rc))
atomic_set(&dev->reset_cmds_out, 0);
mutex_unlock(&h->reset_mutex);
return rc;
}
static void hpsa_get_raid_level(struct ctlr_info *h,
unsigned char *scsi3addr, unsigned char *raid_level)
{
int rc;
unsigned char *buf;
*raid_level = RAID_UNKNOWN;
buf = kzalloc(64, GFP_KERNEL);
if (!buf)
return;
rc = hpsa_scsi_do_inquiry(h, scsi3addr, VPD_PAGE | 0xC1, buf, 64);
if (rc == 0)
*raid_level = buf[8];
if (*raid_level > RAID_UNKNOWN)
*raid_level = RAID_UNKNOWN;
kfree(buf);
return;
}
static void hpsa_debug_map_buff(struct ctlr_info *h, int rc,
struct raid_map_data *map_buff)
{
struct raid_map_disk_data *dd = &map_buff->data[0];
int map, row, col;
u16 map_cnt, row_cnt, disks_per_row;
if (rc != 0)
return;
if (h->raid_offload_debug < 2)
return;
dev_info(&h->pdev->dev, "structure_size = %u\n",
le32_to_cpu(map_buff->structure_size));
dev_info(&h->pdev->dev, "volume_blk_size = %u\n",
le32_to_cpu(map_buff->volume_blk_size));
dev_info(&h->pdev->dev, "volume_blk_cnt = 0x%llx\n",
le64_to_cpu(map_buff->volume_blk_cnt));
dev_info(&h->pdev->dev, "physicalBlockShift = %u\n",
map_buff->phys_blk_shift);
dev_info(&h->pdev->dev, "parity_rotation_shift = %u\n",
map_buff->parity_rotation_shift);
dev_info(&h->pdev->dev, "strip_size = %u\n",
le16_to_cpu(map_buff->strip_size));
dev_info(&h->pdev->dev, "disk_starting_blk = 0x%llx\n",
le64_to_cpu(map_buff->disk_starting_blk));
dev_info(&h->pdev->dev, "disk_blk_cnt = 0x%llx\n",
le64_to_cpu(map_buff->disk_blk_cnt));
dev_info(&h->pdev->dev, "data_disks_per_row = %u\n",
le16_to_cpu(map_buff->data_disks_per_row));
dev_info(&h->pdev->dev, "metadata_disks_per_row = %u\n",
le16_to_cpu(map_buff->metadata_disks_per_row));
dev_info(&h->pdev->dev, "row_cnt = %u\n",
le16_to_cpu(map_buff->row_cnt));
dev_info(&h->pdev->dev, "layout_map_count = %u\n",
le16_to_cpu(map_buff->layout_map_count));
dev_info(&h->pdev->dev, "flags = 0x%x\n",
le16_to_cpu(map_buff->flags));
dev_info(&h->pdev->dev, "encrypytion = %s\n",
le16_to_cpu(map_buff->flags) &
RAID_MAP_FLAG_ENCRYPT_ON ? "ON" : "OFF");
dev_info(&h->pdev->dev, "dekindex = %u\n",
le16_to_cpu(map_buff->dekindex));
map_cnt = le16_to_cpu(map_buff->layout_map_count);
for (map = 0; map < map_cnt; map++) {
dev_info(&h->pdev->dev, "Map%u:\n", map);
row_cnt = le16_to_cpu(map_buff->row_cnt);
for (row = 0; row < row_cnt; row++) {
dev_info(&h->pdev->dev, " Row%u:\n", row);
disks_per_row =
le16_to_cpu(map_buff->data_disks_per_row);
for (col = 0; col < disks_per_row; col++, dd++)
dev_info(&h->pdev->dev,
" D%02u: h=0x%04x xor=%u,%u\n",
col, dd->ioaccel_handle,
dd->xor_mult[0], dd->xor_mult[1]);
disks_per_row =
le16_to_cpu(map_buff->metadata_disks_per_row);
for (col = 0; col < disks_per_row; col++, dd++)
dev_info(&h->pdev->dev,
" M%02u: h=0x%04x xor=%u,%u\n",
col, dd->ioaccel_handle,
dd->xor_mult[0], dd->xor_mult[1]);
}
}
}
static int hpsa_get_raid_map(struct ctlr_info *h,
unsigned char *scsi3addr, struct hpsa_scsi_dev_t *this_device)
{
int rc = 0;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_alloc(h);
if (fill_cmd(c, HPSA_GET_RAID_MAP, h, &this_device->raid_map,
sizeof(this_device->raid_map), 0,
scsi3addr, TYPE_CMD)) {
dev_warn(&h->pdev->dev, "hpsa_get_raid_map fill_cmd failed\n");
cmd_free(h, c);
return -1;
}
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if (rc)
goto out;
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
goto out;
}
cmd_free(h, c);
if (le32_to_cpu(this_device->raid_map.structure_size) >
sizeof(this_device->raid_map)) {
dev_warn(&h->pdev->dev, "RAID map size is too large!\n");
rc = -1;
}
hpsa_debug_map_buff(h, rc, &this_device->raid_map);
return rc;
out:
cmd_free(h, c);
return rc;
}
static int hpsa_bmic_sense_subsystem_information(struct ctlr_info *h,
unsigned char scsi3addr[], u16 bmic_device_index,
struct bmic_sense_subsystem_info *buf, size_t bufsize)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_alloc(h);
rc = fill_cmd(c, BMIC_SENSE_SUBSYSTEM_INFORMATION, h, buf, bufsize,
0, RAID_CTLR_LUNID, TYPE_CMD);
if (rc)
goto out;
c->Request.CDB[2] = bmic_device_index & 0xff;
c->Request.CDB[9] = (bmic_device_index >> 8) & 0xff;
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if (rc)
goto out;
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_free(h, c);
return rc;
}
static int hpsa_bmic_id_controller(struct ctlr_info *h,
struct bmic_identify_controller *buf, size_t bufsize)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_alloc(h);
rc = fill_cmd(c, BMIC_IDENTIFY_CONTROLLER, h, buf, bufsize,
0, RAID_CTLR_LUNID, TYPE_CMD);
if (rc)
goto out;
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if (rc)
goto out;
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_free(h, c);
return rc;
}
static int hpsa_bmic_id_physical_device(struct ctlr_info *h,
unsigned char scsi3addr[], u16 bmic_device_index,
struct bmic_identify_physical_device *buf, size_t bufsize)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_alloc(h);
rc = fill_cmd(c, BMIC_IDENTIFY_PHYSICAL_DEVICE, h, buf, bufsize,
0, RAID_CTLR_LUNID, TYPE_CMD);
if (rc)
goto out;
c->Request.CDB[2] = bmic_device_index & 0xff;
c->Request.CDB[9] = (bmic_device_index >> 8) & 0xff;
hpsa_scsi_do_simple_cmd_with_retry(h, c, PCI_DMA_FROMDEVICE,
NO_TIMEOUT);
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_free(h, c);
return rc;
}
static u64 hpsa_get_sas_address_from_report_physical(struct ctlr_info *h,
unsigned char *scsi3addr)
{
struct ReportExtendedLUNdata *physdev;
u32 nphysicals;
u64 sa = 0;
int i;
physdev = kzalloc(sizeof(*physdev), GFP_KERNEL);
if (!physdev)
return 0;
if (hpsa_scsi_do_report_phys_luns(h, physdev, sizeof(*physdev))) {
dev_err(&h->pdev->dev, "report physical LUNs failed.\n");
kfree(physdev);
return 0;
}
nphysicals = get_unaligned_be32(physdev->LUNListLength) / 24;
for (i = 0; i < nphysicals; i++)
if (!memcmp(&physdev->LUN[i].lunid[0], scsi3addr, 8)) {
sa = get_unaligned_be64(&physdev->LUN[i].wwid[0]);
break;
}
kfree(physdev);
return sa;
}
static void hpsa_get_sas_address(struct ctlr_info *h, unsigned char *scsi3addr,
struct hpsa_scsi_dev_t *dev)
{
int rc;
u64 sa = 0;
if (is_hba_lunid(scsi3addr)) {
struct bmic_sense_subsystem_info *ssi;
ssi = kzalloc(sizeof(*ssi), GFP_KERNEL);
if (ssi == NULL) {
dev_warn(&h->pdev->dev,
"%s: out of memory\n", __func__);
return;
}
rc = hpsa_bmic_sense_subsystem_information(h,
scsi3addr, 0, ssi, sizeof(*ssi));
if (rc == 0) {
sa = get_unaligned_be64(ssi->primary_world_wide_id);
h->sas_address = sa;
}
kfree(ssi);
} else
sa = hpsa_get_sas_address_from_report_physical(h, scsi3addr);
dev->sas_address = sa;
}
static int hpsa_vpd_page_supported(struct ctlr_info *h,
unsigned char scsi3addr[], u8 page)
{
int rc;
int i;
int pages;
unsigned char *buf, bufsize;
buf = kzalloc(256, GFP_KERNEL);
if (!buf)
return 0;
rc = hpsa_scsi_do_inquiry(h, scsi3addr,
VPD_PAGE | HPSA_VPD_SUPPORTED_PAGES,
buf, HPSA_VPD_HEADER_SZ);
if (rc != 0)
goto exit_unsupported;
pages = buf[3];
if ((pages + HPSA_VPD_HEADER_SZ) <= 255)
bufsize = pages + HPSA_VPD_HEADER_SZ;
else
bufsize = 255;
rc = hpsa_scsi_do_inquiry(h, scsi3addr,
VPD_PAGE | HPSA_VPD_SUPPORTED_PAGES,
buf, bufsize);
if (rc != 0)
goto exit_unsupported;
pages = buf[3];
for (i = 1; i <= pages; i++)
if (buf[3 + i] == page)
goto exit_supported;
exit_unsupported:
kfree(buf);
return 0;
exit_supported:
kfree(buf);
return 1;
}
static void hpsa_get_ioaccel_status(struct ctlr_info *h,
unsigned char *scsi3addr, struct hpsa_scsi_dev_t *this_device)
{
int rc;
unsigned char *buf;
u8 ioaccel_status;
this_device->offload_config = 0;
this_device->offload_enabled = 0;
this_device->offload_to_be_enabled = 0;
buf = kzalloc(64, GFP_KERNEL);
if (!buf)
return;
if (!hpsa_vpd_page_supported(h, scsi3addr, HPSA_VPD_LV_IOACCEL_STATUS))
goto out;
rc = hpsa_scsi_do_inquiry(h, scsi3addr,
VPD_PAGE | HPSA_VPD_LV_IOACCEL_STATUS, buf, 64);
if (rc != 0)
goto out;
#define IOACCEL_STATUS_BYTE 4
#define OFFLOAD_CONFIGURED_BIT 0x01
#define OFFLOAD_ENABLED_BIT 0x02
ioaccel_status = buf[IOACCEL_STATUS_BYTE];
this_device->offload_config =
!!(ioaccel_status & OFFLOAD_CONFIGURED_BIT);
if (this_device->offload_config) {
this_device->offload_enabled =
!!(ioaccel_status & OFFLOAD_ENABLED_BIT);
if (hpsa_get_raid_map(h, scsi3addr, this_device))
this_device->offload_enabled = 0;
}
this_device->offload_to_be_enabled = this_device->offload_enabled;
out:
kfree(buf);
return;
}
static int hpsa_get_device_id(struct ctlr_info *h, unsigned char *scsi3addr,
unsigned char *device_id, int index, int buflen)
{
int rc;
unsigned char *buf;
if (buflen > 16)
buflen = 16;
buf = kzalloc(64, GFP_KERNEL);
if (!buf)
return -ENOMEM;
rc = hpsa_scsi_do_inquiry(h, scsi3addr, VPD_PAGE | 0x83, buf, 64);
if (rc == 0)
memcpy(device_id, &buf[index], buflen);
kfree(buf);
return rc != 0;
}
static int hpsa_scsi_do_report_luns(struct ctlr_info *h, int logical,
void *buf, int bufsize,
int extended_response)
{
int rc = IO_OK;
struct CommandList *c;
unsigned char scsi3addr[8];
struct ErrorInfo *ei;
c = cmd_alloc(h);
memset(scsi3addr, 0, sizeof(scsi3addr));
if (fill_cmd(c, logical ? HPSA_REPORT_LOG : HPSA_REPORT_PHYS, h,
buf, bufsize, 0, scsi3addr, TYPE_CMD)) {
rc = -1;
goto out;
}
if (extended_response)
c->Request.CDB[1] = extended_response;
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if (rc)
goto out;
ei = c->err_info;
if (ei->CommandStatus != 0 &&
ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
} else {
struct ReportLUNdata *rld = buf;
if (rld->extended_response_flag != extended_response) {
dev_err(&h->pdev->dev,
"report luns requested format %u, got %u\n",
extended_response,
rld->extended_response_flag);
rc = -1;
}
}
out:
cmd_free(h, c);
return rc;
}
static inline int hpsa_scsi_do_report_phys_luns(struct ctlr_info *h,
struct ReportExtendedLUNdata *buf, int bufsize)
{
return hpsa_scsi_do_report_luns(h, 0, buf, bufsize,
HPSA_REPORT_PHYS_EXTENDED);
}
static inline int hpsa_scsi_do_report_log_luns(struct ctlr_info *h,
struct ReportLUNdata *buf, int bufsize)
{
return hpsa_scsi_do_report_luns(h, 1, buf, bufsize, 0);
}
static inline void hpsa_set_bus_target_lun(struct hpsa_scsi_dev_t *device,
int bus, int target, int lun)
{
device->bus = bus;
device->target = target;
device->lun = lun;
}
static int hpsa_get_volume_status(struct ctlr_info *h,
unsigned char scsi3addr[])
{
int rc;
int status;
int size;
unsigned char *buf;
buf = kzalloc(64, GFP_KERNEL);
if (!buf)
return HPSA_VPD_LV_STATUS_UNSUPPORTED;
if (!hpsa_vpd_page_supported(h, scsi3addr, HPSA_VPD_LV_STATUS))
goto exit_failed;
rc = hpsa_scsi_do_inquiry(h, scsi3addr, VPD_PAGE | HPSA_VPD_LV_STATUS,
buf, HPSA_VPD_HEADER_SZ);
if (rc != 0)
goto exit_failed;
size = buf[3];
rc = hpsa_scsi_do_inquiry(h, scsi3addr, VPD_PAGE | HPSA_VPD_LV_STATUS,
buf, size + HPSA_VPD_HEADER_SZ);
if (rc != 0)
goto exit_failed;
status = buf[4];
kfree(buf);
return status;
exit_failed:
kfree(buf);
return HPSA_VPD_LV_STATUS_UNSUPPORTED;
}
static int hpsa_volume_offline(struct ctlr_info *h,
unsigned char scsi3addr[])
{
struct CommandList *c;
unsigned char *sense;
u8 sense_key, asc, ascq;
int sense_len;
int rc, ldstat = 0;
u16 cmd_status;
u8 scsi_status;
#define ASC_LUN_NOT_READY 0x04
#define ASCQ_LUN_NOT_READY_FORMAT_IN_PROGRESS 0x04
#define ASCQ_LUN_NOT_READY_INITIALIZING_CMD_REQ 0x02
c = cmd_alloc(h);
(void) fill_cmd(c, TEST_UNIT_READY, h, NULL, 0, 0, scsi3addr, TYPE_CMD);
rc = hpsa_scsi_do_simple_cmd(h, c, DEFAULT_REPLY_QUEUE, NO_TIMEOUT);
if (rc) {
cmd_free(h, c);
return 0;
}
sense = c->err_info->SenseInfo;
if (c->err_info->SenseLen > sizeof(c->err_info->SenseInfo))
sense_len = sizeof(c->err_info->SenseInfo);
else
sense_len = c->err_info->SenseLen;
decode_sense_data(sense, sense_len, &sense_key, &asc, &ascq);
cmd_status = c->err_info->CommandStatus;
scsi_status = c->err_info->ScsiStatus;
cmd_free(h, c);
if (cmd_status != CMD_TARGET_STATUS ||
scsi_status != SAM_STAT_CHECK_CONDITION ||
sense_key != NOT_READY ||
asc != ASC_LUN_NOT_READY) {
return 0;
}
ldstat = hpsa_get_volume_status(h, scsi3addr);
switch (ldstat) {
case HPSA_LV_UNDERGOING_ERASE:
case HPSA_LV_NOT_AVAILABLE:
case HPSA_LV_UNDERGOING_RPI:
case HPSA_LV_PENDING_RPI:
case HPSA_LV_ENCRYPTED_NO_KEY:
case HPSA_LV_PLAINTEXT_IN_ENCRYPT_ONLY_CONTROLLER:
case HPSA_LV_UNDERGOING_ENCRYPTION:
case HPSA_LV_UNDERGOING_ENCRYPTION_REKEYING:
case HPSA_LV_ENCRYPTED_IN_NON_ENCRYPTED_CONTROLLER:
return ldstat;
case HPSA_VPD_LV_STATUS_UNSUPPORTED:
if ((ascq == ASCQ_LUN_NOT_READY_FORMAT_IN_PROGRESS) ||
(ascq == ASCQ_LUN_NOT_READY_INITIALIZING_CMD_REQ))
return ldstat;
break;
default:
break;
}
return 0;
}
static int hpsa_device_supports_aborts(struct ctlr_info *h,
unsigned char *scsi3addr)
{
struct CommandList *c;
struct ErrorInfo *ei;
int rc = 0;
u64 tag = (u64) -1;
if (!is_logical_dev_addr_mode(scsi3addr))
return 1;
c = cmd_alloc(h);
(void) fill_cmd(c, HPSA_ABORT_MSG, h, &tag, 0, 0, scsi3addr, TYPE_MSG);
(void) hpsa_scsi_do_simple_cmd(h, c, DEFAULT_REPLY_QUEUE, NO_TIMEOUT);
ei = c->err_info;
switch (ei->CommandStatus) {
case CMD_INVALID:
rc = 0;
break;
case CMD_UNABORTABLE:
case CMD_ABORT_FAILED:
rc = 1;
break;
case CMD_TMF_STATUS:
rc = hpsa_evaluate_tmf_status(h, c);
break;
default:
rc = 0;
break;
}
cmd_free(h, c);
return rc;
}
static void sanitize_inquiry_string(unsigned char *s, int len)
{
bool terminated = false;
for (; len > 0; (--len, ++s)) {
if (*s == 0)
terminated = true;
if (terminated || *s < 0x20 || *s > 0x7e)
*s = ' ';
}
}
static int hpsa_update_device_info(struct ctlr_info *h,
unsigned char scsi3addr[], struct hpsa_scsi_dev_t *this_device,
unsigned char *is_OBDR_device)
{
#define OBDR_SIG_OFFSET 43
#define OBDR_TAPE_SIG "$DR-10"
#define OBDR_SIG_LEN (sizeof(OBDR_TAPE_SIG) - 1)
#define OBDR_TAPE_INQ_SIZE (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char *inq_buff;
unsigned char *obdr_sig;
int rc = 0;
inq_buff = kzalloc(OBDR_TAPE_INQ_SIZE, GFP_KERNEL);
if (!inq_buff) {
rc = -ENOMEM;
goto bail_out;
}
if (hpsa_scsi_do_inquiry(h, scsi3addr, 0, inq_buff,
(unsigned char) OBDR_TAPE_INQ_SIZE) != 0) {
dev_err(&h->pdev->dev,
"hpsa_update_device_info: inquiry failed\n");
rc = -EIO;
goto bail_out;
}
sanitize_inquiry_string(&inq_buff[8], 8);
sanitize_inquiry_string(&inq_buff[16], 16);
this_device->devtype = (inq_buff[0] & 0x1f);
memcpy(this_device->scsi3addr, scsi3addr, 8);
memcpy(this_device->vendor, &inq_buff[8],
sizeof(this_device->vendor));
memcpy(this_device->model, &inq_buff[16],
sizeof(this_device->model));
memset(this_device->device_id, 0,
sizeof(this_device->device_id));
hpsa_get_device_id(h, scsi3addr, this_device->device_id, 8,
sizeof(this_device->device_id));
if (this_device->devtype == TYPE_DISK &&
is_logical_dev_addr_mode(scsi3addr)) {
int volume_offline;
hpsa_get_raid_level(h, scsi3addr, &this_device->raid_level);
if (h->fw_support & MISC_FW_RAID_OFFLOAD_BASIC)
hpsa_get_ioaccel_status(h, scsi3addr, this_device);
volume_offline = hpsa_volume_offline(h, scsi3addr);
if (volume_offline < 0 || volume_offline > 0xff)
volume_offline = HPSA_VPD_LV_STATUS_UNSUPPORTED;
this_device->volume_offline = volume_offline & 0xff;
} else {
this_device->raid_level = RAID_UNKNOWN;
this_device->offload_config = 0;
this_device->offload_enabled = 0;
this_device->offload_to_be_enabled = 0;
this_device->hba_ioaccel_enabled = 0;
this_device->volume_offline = 0;
this_device->queue_depth = h->nr_cmds;
}
if (is_OBDR_device) {
obdr_sig = &inq_buff[OBDR_SIG_OFFSET];
*is_OBDR_device = (this_device->devtype == TYPE_ROM &&
strncmp(obdr_sig, OBDR_TAPE_SIG,
OBDR_SIG_LEN) == 0);
}
kfree(inq_buff);
return 0;
bail_out:
kfree(inq_buff);
return rc;
}
static void hpsa_update_device_supports_aborts(struct ctlr_info *h,
struct hpsa_scsi_dev_t *dev, u8 *scsi3addr)
{
unsigned long flags;
int rc, entry;
spin_lock_irqsave(&h->devlock, flags);
rc = hpsa_scsi_find_entry(dev, h->dev, h->ndevices, &entry);
if ((rc == DEVICE_SAME || rc == DEVICE_UPDATED) &&
entry >= 0 && entry < h->ndevices) {
dev->supports_aborts = h->dev[entry]->supports_aborts;
spin_unlock_irqrestore(&h->devlock, flags);
} else {
spin_unlock_irqrestore(&h->devlock, flags);
dev->supports_aborts =
hpsa_device_supports_aborts(h, scsi3addr);
if (dev->supports_aborts < 0)
dev->supports_aborts = 0;
}
}
static void figure_bus_target_lun(struct ctlr_info *h,
u8 *lunaddrbytes, struct hpsa_scsi_dev_t *device)
{
u32 lunid = get_unaligned_le32(lunaddrbytes);
if (!is_logical_dev_addr_mode(lunaddrbytes)) {
if (is_hba_lunid(lunaddrbytes))
hpsa_set_bus_target_lun(device,
HPSA_HBA_BUS, 0, lunid & 0x3fff);
else
hpsa_set_bus_target_lun(device,
HPSA_PHYSICAL_DEVICE_BUS, -1, -1);
return;
}
if (device->external) {
hpsa_set_bus_target_lun(device,
HPSA_EXTERNAL_RAID_VOLUME_BUS, (lunid >> 16) & 0x3fff,
lunid & 0x00ff);
return;
}
hpsa_set_bus_target_lun(device, HPSA_RAID_VOLUME_BUS,
0, lunid & 0x3fff);
}
static int hpsa_get_pdisk_of_ioaccel2(struct ctlr_info *h,
struct CommandList *ioaccel2_cmd_to_abort, unsigned char *scsi3addr)
{
struct io_accel2_cmd *c2 =
&h->ioaccel2_cmd_pool[ioaccel2_cmd_to_abort->cmdindex];
unsigned long flags;
int i;
spin_lock_irqsave(&h->devlock, flags);
for (i = 0; i < h->ndevices; i++)
if (h->dev[i]->ioaccel_handle == le32_to_cpu(c2->scsi_nexus)) {
memcpy(scsi3addr, h->dev[i]->scsi3addr,
sizeof(h->dev[i]->scsi3addr));
spin_unlock_irqrestore(&h->devlock, flags);
return 1;
}
spin_unlock_irqrestore(&h->devlock, flags);
return 0;
}
static int figure_external_status(struct ctlr_info *h, int raid_ctlr_position,
int i, int nphysicals, int nlocal_logicals)
{
int logicals_start = nphysicals + (raid_ctlr_position == 0);
if (i == raid_ctlr_position)
return 0;
if (i < logicals_start)
return 0;
if ((i - nphysicals - (raid_ctlr_position == 0)) < nlocal_logicals)
return 0;
return 1;
}
static int hpsa_gather_lun_info(struct ctlr_info *h,
struct ReportExtendedLUNdata *physdev, u32 *nphysicals,
struct ReportLUNdata *logdev, u32 *nlogicals)
{
if (hpsa_scsi_do_report_phys_luns(h, physdev, sizeof(*physdev))) {
dev_err(&h->pdev->dev, "report physical LUNs failed.\n");
return -1;
}
*nphysicals = be32_to_cpu(*((__be32 *)physdev->LUNListLength)) / 24;
if (*nphysicals > HPSA_MAX_PHYS_LUN) {
dev_warn(&h->pdev->dev, "maximum physical LUNs (%d) exceeded. %d LUNs ignored.\n",
HPSA_MAX_PHYS_LUN, *nphysicals - HPSA_MAX_PHYS_LUN);
*nphysicals = HPSA_MAX_PHYS_LUN;
}
if (hpsa_scsi_do_report_log_luns(h, logdev, sizeof(*logdev))) {
dev_err(&h->pdev->dev, "report logical LUNs failed.\n");
return -1;
}
*nlogicals = be32_to_cpu(*((__be32 *) logdev->LUNListLength)) / 8;
if (*nlogicals > HPSA_MAX_LUN) {
dev_warn(&h->pdev->dev,
"maximum logical LUNs (%d) exceeded. "
"%d LUNs ignored.\n", HPSA_MAX_LUN,
*nlogicals - HPSA_MAX_LUN);
*nlogicals = HPSA_MAX_LUN;
}
if (*nlogicals + *nphysicals > HPSA_MAX_PHYS_LUN) {
dev_warn(&h->pdev->dev,
"maximum logical + physical LUNs (%d) exceeded. "
"%d LUNs ignored.\n", HPSA_MAX_PHYS_LUN,
*nphysicals + *nlogicals - HPSA_MAX_PHYS_LUN);
*nlogicals = HPSA_MAX_PHYS_LUN - *nphysicals;
}
return 0;
}
static u8 *figure_lunaddrbytes(struct ctlr_info *h, int raid_ctlr_position,
int i, int nphysicals, int nlogicals,
struct ReportExtendedLUNdata *physdev_list,
struct ReportLUNdata *logdev_list)
{
int logicals_start = nphysicals + (raid_ctlr_position == 0);
int last_device = nphysicals + nlogicals + (raid_ctlr_position == 0);
if (i == raid_ctlr_position)
return RAID_CTLR_LUNID;
if (i < logicals_start)
return &physdev_list->LUN[i -
(raid_ctlr_position == 0)].lunid[0];
if (i < last_device)
return &logdev_list->LUN[i - nphysicals -
(raid_ctlr_position == 0)][0];
BUG();
return NULL;
}
static void hpsa_get_ioaccel_drive_info(struct ctlr_info *h,
struct hpsa_scsi_dev_t *dev,
struct ReportExtendedLUNdata *rlep, int rle_index,
struct bmic_identify_physical_device *id_phys)
{
int rc;
struct ext_report_lun_entry *rle = &rlep->LUN[rle_index];
dev->ioaccel_handle = rle->ioaccel_handle;
if ((rle->device_flags & 0x08) && dev->ioaccel_handle)
dev->hba_ioaccel_enabled = 1;
memset(id_phys, 0, sizeof(*id_phys));
rc = hpsa_bmic_id_physical_device(h, &rle->lunid[0],
GET_BMIC_DRIVE_NUMBER(&rle->lunid[0]), id_phys,
sizeof(*id_phys));
if (!rc)
#define DRIVE_CMDS_RESERVED_FOR_FW 2
#define DRIVE_QUEUE_DEPTH 7
dev->queue_depth =
le16_to_cpu(id_phys->current_queue_depth_limit) -
DRIVE_CMDS_RESERVED_FOR_FW;
else
dev->queue_depth = DRIVE_QUEUE_DEPTH;
}
static void hpsa_get_path_info(struct hpsa_scsi_dev_t *this_device,
struct ReportExtendedLUNdata *rlep, int rle_index,
struct bmic_identify_physical_device *id_phys)
{
struct ext_report_lun_entry *rle = &rlep->LUN[rle_index];
if ((rle->device_flags & 0x08) && this_device->ioaccel_handle)
this_device->hba_ioaccel_enabled = 1;
memcpy(&this_device->active_path_index,
&id_phys->active_path_number,
sizeof(this_device->active_path_index));
memcpy(&this_device->path_map,
&id_phys->redundant_path_present_map,
sizeof(this_device->path_map));
memcpy(&this_device->box,
&id_phys->alternate_paths_phys_box_on_port,
sizeof(this_device->box));
memcpy(&this_device->phys_connector,
&id_phys->alternate_paths_phys_connector,
sizeof(this_device->phys_connector));
memcpy(&this_device->bay,
&id_phys->phys_bay_in_box,
sizeof(this_device->bay));
}
static int hpsa_set_local_logical_count(struct ctlr_info *h,
struct bmic_identify_controller *id_ctlr,
u32 *nlocals)
{
int rc;
if (!id_ctlr) {
dev_warn(&h->pdev->dev, "%s: id_ctlr buffer is NULL.\n",
__func__);
return -ENOMEM;
}
memset(id_ctlr, 0, sizeof(*id_ctlr));
rc = hpsa_bmic_id_controller(h, id_ctlr, sizeof(*id_ctlr));
if (!rc)
if (id_ctlr->configured_logical_drive_count < 256)
*nlocals = id_ctlr->configured_logical_drive_count;
else
*nlocals = le16_to_cpu(
id_ctlr->extended_logical_unit_count);
else
*nlocals = -1;
return rc;
}
static void hpsa_update_scsi_devices(struct ctlr_info *h)
{
struct ReportExtendedLUNdata *physdev_list = NULL;
struct ReportLUNdata *logdev_list = NULL;
struct bmic_identify_physical_device *id_phys = NULL;
struct bmic_identify_controller *id_ctlr = NULL;
u32 nphysicals = 0;
u32 nlogicals = 0;
u32 nlocal_logicals = 0;
u32 ndev_allocated = 0;
struct hpsa_scsi_dev_t **currentsd, *this_device, *tmpdevice;
int ncurrent = 0;
int i, n_ext_target_devs, ndevs_to_allocate;
int raid_ctlr_position;
bool physical_device;
DECLARE_BITMAP(lunzerobits, MAX_EXT_TARGETS);
currentsd = kzalloc(sizeof(*currentsd) * HPSA_MAX_DEVICES, GFP_KERNEL);
physdev_list = kzalloc(sizeof(*physdev_list), GFP_KERNEL);
logdev_list = kzalloc(sizeof(*logdev_list), GFP_KERNEL);
tmpdevice = kzalloc(sizeof(*tmpdevice), GFP_KERNEL);
id_phys = kzalloc(sizeof(*id_phys), GFP_KERNEL);
id_ctlr = kzalloc(sizeof(*id_ctlr), GFP_KERNEL);
if (!currentsd || !physdev_list || !logdev_list ||
!tmpdevice || !id_phys || !id_ctlr) {
dev_err(&h->pdev->dev, "out of memory\n");
goto out;
}
memset(lunzerobits, 0, sizeof(lunzerobits));
h->drv_req_rescan = 0;
if (hpsa_gather_lun_info(h, physdev_list, &nphysicals,
logdev_list, &nlogicals)) {
h->drv_req_rescan = 1;
goto out;
}
if (hpsa_set_local_logical_count(h, id_ctlr, &nlocal_logicals)) {
dev_warn(&h->pdev->dev,
"%s: Can't determine number of local logical devices.\n",
__func__);
}
ndevs_to_allocate = nphysicals + nlogicals + MAX_EXT_TARGETS + 1;
for (i = 0; i < ndevs_to_allocate; i++) {
if (i >= HPSA_MAX_DEVICES) {
dev_warn(&h->pdev->dev, "maximum devices (%d) exceeded."
" %d devices ignored.\n", HPSA_MAX_DEVICES,
ndevs_to_allocate - HPSA_MAX_DEVICES);
break;
}
currentsd[i] = kzalloc(sizeof(*currentsd[i]), GFP_KERNEL);
if (!currentsd[i]) {
dev_warn(&h->pdev->dev, "out of memory at %s:%d\n",
__FILE__, __LINE__);
h->drv_req_rescan = 1;
goto out;
}
ndev_allocated++;
}
if (is_scsi_rev_5(h))
raid_ctlr_position = 0;
else
raid_ctlr_position = nphysicals + nlogicals;
n_ext_target_devs = 0;
for (i = 0; i < nphysicals + nlogicals + 1; i++) {
u8 *lunaddrbytes, is_OBDR = 0;
int rc = 0;
int phys_dev_index = i - (raid_ctlr_position == 0);
physical_device = i < nphysicals + (raid_ctlr_position == 0);
lunaddrbytes = figure_lunaddrbytes(h, raid_ctlr_position,
i, nphysicals, nlogicals, physdev_list, logdev_list);
if (MASKED_DEVICE(lunaddrbytes) && physical_device &&
(physdev_list->LUN[phys_dev_index].device_flags & 0x01))
continue;
rc = hpsa_update_device_info(h, lunaddrbytes, tmpdevice,
&is_OBDR);
if (rc == -ENOMEM) {
dev_warn(&h->pdev->dev,
"Out of memory, rescan deferred.\n");
h->drv_req_rescan = 1;
goto out;
}
if (rc) {
dev_warn(&h->pdev->dev,
"Inquiry failed, skipping device.\n");
continue;
}
tmpdevice->external =
figure_external_status(h, raid_ctlr_position, i,
nphysicals, nlocal_logicals);
figure_bus_target_lun(h, lunaddrbytes, tmpdevice);
hpsa_update_device_supports_aborts(h, tmpdevice, lunaddrbytes);
this_device = currentsd[ncurrent];
if (!h->discovery_polling) {
if (tmpdevice->external) {
h->discovery_polling = 1;
dev_info(&h->pdev->dev,
"External target, activate discovery polling.\n");
}
}
*this_device = *tmpdevice;
this_device->physical_device = physical_device;
if (MASKED_DEVICE(lunaddrbytes) && this_device->physical_device)
this_device->expose_device = 0;
else
this_device->expose_device = 1;
if (this_device->physical_device && this_device->expose_device)
hpsa_get_sas_address(h, lunaddrbytes, this_device);
switch (this_device->devtype) {
case TYPE_ROM:
if (is_OBDR)
ncurrent++;
break;
case TYPE_DISK:
if (this_device->physical_device) {
this_device->offload_enabled = 0;
hpsa_get_ioaccel_drive_info(h, this_device,
physdev_list, phys_dev_index, id_phys);
hpsa_get_path_info(this_device,
physdev_list, phys_dev_index, id_phys);
}
ncurrent++;
break;
case TYPE_TAPE:
case TYPE_MEDIUM_CHANGER:
case TYPE_ENCLOSURE:
ncurrent++;
break;
case TYPE_RAID:
if (!is_hba_lunid(lunaddrbytes))
break;
ncurrent++;
break;
default:
break;
}
if (ncurrent >= HPSA_MAX_DEVICES)
break;
}
if (h->sas_host == NULL) {
int rc = 0;
rc = hpsa_add_sas_host(h);
if (rc) {
dev_warn(&h->pdev->dev,
"Could not add sas host %d\n", rc);
goto out;
}
}
adjust_hpsa_scsi_table(h, currentsd, ncurrent);
out:
kfree(tmpdevice);
for (i = 0; i < ndev_allocated; i++)
kfree(currentsd[i]);
kfree(currentsd);
kfree(physdev_list);
kfree(logdev_list);
kfree(id_ctlr);
kfree(id_phys);
}
static void hpsa_set_sg_descriptor(struct SGDescriptor *desc,
struct scatterlist *sg)
{
u64 addr64 = (u64) sg_dma_address(sg);
unsigned int len = sg_dma_len(sg);
desc->Addr = cpu_to_le64(addr64);
desc->Len = cpu_to_le32(len);
desc->Ext = 0;
}
static int hpsa_scatter_gather(struct ctlr_info *h,
struct CommandList *cp,
struct scsi_cmnd *cmd)
{
struct scatterlist *sg;
int use_sg, i, sg_limit, chained, last_sg;
struct SGDescriptor *curr_sg;
BUG_ON(scsi_sg_count(cmd) > h->maxsgentries);
use_sg = scsi_dma_map(cmd);
if (use_sg < 0)
return use_sg;
if (!use_sg)
goto sglist_finished;
curr_sg = cp->SG;
chained = use_sg > h->max_cmd_sg_entries;
sg_limit = chained ? h->max_cmd_sg_entries - 1 : use_sg;
last_sg = scsi_sg_count(cmd) - 1;
scsi_for_each_sg(cmd, sg, sg_limit, i) {
hpsa_set_sg_descriptor(curr_sg, sg);
curr_sg++;
}
if (chained) {
curr_sg = h->cmd_sg_list[cp->cmdindex];
sg_limit = use_sg - sg_limit;
for_each_sg(sg, sg, sg_limit, i) {
hpsa_set_sg_descriptor(curr_sg, sg);
curr_sg++;
}
}
(curr_sg - 1)->Ext = cpu_to_le32(HPSA_SG_LAST);
if (use_sg + chained > h->maxSG)
h->maxSG = use_sg + chained;
if (chained) {
cp->Header.SGList = h->max_cmd_sg_entries;
cp->Header.SGTotal = cpu_to_le16(use_sg + 1);
if (hpsa_map_sg_chain_block(h, cp)) {
scsi_dma_unmap(cmd);
return -1;
}
return 0;
}
sglist_finished:
cp->Header.SGList = (u8) use_sg;
cp->Header.SGTotal = cpu_to_le16(use_sg);
return 0;
}
static int fixup_ioaccel_cdb(u8 *cdb, int *cdb_len)
{
int is_write = 0;
u32 block;
u32 block_cnt;
switch (cdb[0]) {
case WRITE_6:
case WRITE_12:
is_write = 1;
case READ_6:
case READ_12:
if (*cdb_len == 6) {
block = get_unaligned_be16(&cdb[2]);
block_cnt = cdb[4];
if (block_cnt == 0)
block_cnt = 256;
} else {
BUG_ON(*cdb_len != 12);
block = get_unaligned_be32(&cdb[2]);
block_cnt = get_unaligned_be32(&cdb[6]);
}
if (block_cnt > 0xffff)
return IO_ACCEL_INELIGIBLE;
cdb[0] = is_write ? WRITE_10 : READ_10;
cdb[1] = 0;
cdb[2] = (u8) (block >> 24);
cdb[3] = (u8) (block >> 16);
cdb[4] = (u8) (block >> 8);
cdb[5] = (u8) (block);
cdb[6] = 0;
cdb[7] = (u8) (block_cnt >> 8);
cdb[8] = (u8) (block_cnt);
cdb[9] = 0;
*cdb_len = 10;
break;
}
return 0;
}
static int hpsa_scsi_ioaccel1_queue_command(struct ctlr_info *h,
struct CommandList *c, u32 ioaccel_handle, u8 *cdb, int cdb_len,
u8 *scsi3addr, struct hpsa_scsi_dev_t *phys_disk)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct io_accel1_cmd *cp = &h->ioaccel_cmd_pool[c->cmdindex];
unsigned int len;
unsigned int total_len = 0;
struct scatterlist *sg;
u64 addr64;
int use_sg, i;
struct SGDescriptor *curr_sg;
u32 control = IOACCEL1_CONTROL_SIMPLEQUEUE;
if (scsi_sg_count(cmd) > h->ioaccel_maxsg) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
return IO_ACCEL_INELIGIBLE;
}
BUG_ON(cmd->cmd_len > IOACCEL1_IOFLAGS_CDBLEN_MAX);
if (fixup_ioaccel_cdb(cdb, &cdb_len)) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
return IO_ACCEL_INELIGIBLE;
}
c->cmd_type = CMD_IOACCEL1;
c->busaddr = (u32) h->ioaccel_cmd_pool_dhandle +
(c->cmdindex * sizeof(*cp));
BUG_ON(c->busaddr & 0x0000007F);
use_sg = scsi_dma_map(cmd);
if (use_sg < 0) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
return use_sg;
}
if (use_sg) {
curr_sg = cp->SG;
scsi_for_each_sg(cmd, sg, use_sg, i) {
addr64 = (u64) sg_dma_address(sg);
len = sg_dma_len(sg);
total_len += len;
curr_sg->Addr = cpu_to_le64(addr64);
curr_sg->Len = cpu_to_le32(len);
curr_sg->Ext = cpu_to_le32(0);
curr_sg++;
}
(--curr_sg)->Ext = cpu_to_le32(HPSA_SG_LAST);
switch (cmd->sc_data_direction) {
case DMA_TO_DEVICE:
control |= IOACCEL1_CONTROL_DATA_OUT;
break;
case DMA_FROM_DEVICE:
control |= IOACCEL1_CONTROL_DATA_IN;
break;
case DMA_NONE:
control |= IOACCEL1_CONTROL_NODATAXFER;
break;
default:
dev_err(&h->pdev->dev, "unknown data direction: %d\n",
cmd->sc_data_direction);
BUG();
break;
}
} else {
control |= IOACCEL1_CONTROL_NODATAXFER;
}
c->Header.SGList = use_sg;
cp->dev_handle = cpu_to_le16(ioaccel_handle & 0xFFFF);
cp->transfer_len = cpu_to_le32(total_len);
cp->io_flags = cpu_to_le16(IOACCEL1_IOFLAGS_IO_REQ |
(cdb_len & IOACCEL1_IOFLAGS_CDBLEN_MASK));
cp->control = cpu_to_le32(control);
memcpy(cp->CDB, cdb, cdb_len);
memcpy(cp->CISS_LUN, scsi3addr, 8);
enqueue_cmd_and_start_io(h, c);
return 0;
}
static int hpsa_scsi_ioaccel_direct_map(struct ctlr_info *h,
struct CommandList *c)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct hpsa_scsi_dev_t *dev = cmd->device->hostdata;
c->phys_disk = dev;
return hpsa_scsi_ioaccel_queue_command(h, c, dev->ioaccel_handle,
cmd->cmnd, cmd->cmd_len, dev->scsi3addr, dev);
}
static void set_encrypt_ioaccel2(struct ctlr_info *h,
struct CommandList *c, struct io_accel2_cmd *cp)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct hpsa_scsi_dev_t *dev = cmd->device->hostdata;
struct raid_map_data *map = &dev->raid_map;
u64 first_block;
if (!(le16_to_cpu(map->flags) & RAID_MAP_FLAG_ENCRYPT_ON))
return;
cp->dekindex = map->dekindex;
cp->direction |= IOACCEL2_DIRECTION_ENCRYPT_MASK;
switch (cmd->cmnd[0]) {
case WRITE_6:
case READ_6:
first_block = get_unaligned_be16(&cmd->cmnd[2]);
break;
case WRITE_10:
case READ_10:
case WRITE_12:
case READ_12:
first_block = get_unaligned_be32(&cmd->cmnd[2]);
break;
case WRITE_16:
case READ_16:
first_block = get_unaligned_be64(&cmd->cmnd[2]);
break;
default:
dev_err(&h->pdev->dev,
"ERROR: %s: size (0x%x) not supported for encryption\n",
__func__, cmd->cmnd[0]);
BUG();
break;
}
if (le32_to_cpu(map->volume_blk_size) != 512)
first_block = first_block *
le32_to_cpu(map->volume_blk_size)/512;
cp->tweak_lower = cpu_to_le32(first_block);
cp->tweak_upper = cpu_to_le32(first_block >> 32);
}
static int hpsa_scsi_ioaccel2_queue_command(struct ctlr_info *h,
struct CommandList *c, u32 ioaccel_handle, u8 *cdb, int cdb_len,
u8 *scsi3addr, struct hpsa_scsi_dev_t *phys_disk)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct io_accel2_cmd *cp = &h->ioaccel2_cmd_pool[c->cmdindex];
struct ioaccel2_sg_element *curr_sg;
int use_sg, i;
struct scatterlist *sg;
u64 addr64;
u32 len;
u32 total_len = 0;
BUG_ON(scsi_sg_count(cmd) > h->maxsgentries);
if (fixup_ioaccel_cdb(cdb, &cdb_len)) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
return IO_ACCEL_INELIGIBLE;
}
c->cmd_type = CMD_IOACCEL2;
c->busaddr = (u32) h->ioaccel2_cmd_pool_dhandle +
(c->cmdindex * sizeof(*cp));
BUG_ON(c->busaddr & 0x0000007F);
memset(cp, 0, sizeof(*cp));
cp->IU_type = IOACCEL2_IU_TYPE;
use_sg = scsi_dma_map(cmd);
if (use_sg < 0) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
return use_sg;
}
if (use_sg) {
curr_sg = cp->sg;
if (use_sg > h->ioaccel_maxsg) {
addr64 = le64_to_cpu(
h->ioaccel2_cmd_sg_list[c->cmdindex]->address);
curr_sg->address = cpu_to_le64(addr64);
curr_sg->length = 0;
curr_sg->reserved[0] = 0;
curr_sg->reserved[1] = 0;
curr_sg->reserved[2] = 0;
curr_sg->chain_indicator = 0x80;
curr_sg = h->ioaccel2_cmd_sg_list[c->cmdindex];
}
scsi_for_each_sg(cmd, sg, use_sg, i) {
addr64 = (u64) sg_dma_address(sg);
len = sg_dma_len(sg);
total_len += len;
curr_sg->address = cpu_to_le64(addr64);
curr_sg->length = cpu_to_le32(len);
curr_sg->reserved[0] = 0;
curr_sg->reserved[1] = 0;
curr_sg->reserved[2] = 0;
curr_sg->chain_indicator = 0;
curr_sg++;
}
switch (cmd->sc_data_direction) {
case DMA_TO_DEVICE:
cp->direction &= ~IOACCEL2_DIRECTION_MASK;
cp->direction |= IOACCEL2_DIR_DATA_OUT;
break;
case DMA_FROM_DEVICE:
cp->direction &= ~IOACCEL2_DIRECTION_MASK;
cp->direction |= IOACCEL2_DIR_DATA_IN;
break;
case DMA_NONE:
cp->direction &= ~IOACCEL2_DIRECTION_MASK;
cp->direction |= IOACCEL2_DIR_NO_DATA;
break;
default:
dev_err(&h->pdev->dev, "unknown data direction: %d\n",
cmd->sc_data_direction);
BUG();
break;
}
} else {
cp->direction &= ~IOACCEL2_DIRECTION_MASK;
cp->direction |= IOACCEL2_DIR_NO_DATA;
}
set_encrypt_ioaccel2(h, c, cp);
cp->scsi_nexus = cpu_to_le32(ioaccel_handle);
cp->Tag = cpu_to_le32(c->cmdindex << DIRECT_LOOKUP_SHIFT);
memcpy(cp->cdb, cdb, sizeof(cp->cdb));
cp->data_len = cpu_to_le32(total_len);
cp->err_ptr = cpu_to_le64(c->busaddr +
offsetof(struct io_accel2_cmd, error_data));
cp->err_len = cpu_to_le32(sizeof(cp->error_data));
if (use_sg > h->ioaccel_maxsg) {
cp->sg_count = 1;
cp->sg[0].length = cpu_to_le32(use_sg * sizeof(cp->sg[0]));
if (hpsa_map_ioaccel2_sg_chain_block(h, cp, c)) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
scsi_dma_unmap(cmd);
return -1;
}
} else
cp->sg_count = (u8) use_sg;
enqueue_cmd_and_start_io(h, c);
return 0;
}
static int hpsa_scsi_ioaccel_queue_command(struct ctlr_info *h,
struct CommandList *c, u32 ioaccel_handle, u8 *cdb, int cdb_len,
u8 *scsi3addr, struct hpsa_scsi_dev_t *phys_disk)
{
if (atomic_inc_return(&phys_disk->ioaccel_cmds_out) >
phys_disk->queue_depth) {
atomic_dec(&phys_disk->ioaccel_cmds_out);
return IO_ACCEL_INELIGIBLE;
}
if (h->transMethod & CFGTBL_Trans_io_accel1)
return hpsa_scsi_ioaccel1_queue_command(h, c, ioaccel_handle,
cdb, cdb_len, scsi3addr,
phys_disk);
else
return hpsa_scsi_ioaccel2_queue_command(h, c, ioaccel_handle,
cdb, cdb_len, scsi3addr,
phys_disk);
}
static void raid_map_helper(struct raid_map_data *map,
int offload_to_mirror, u32 *map_index, u32 *current_group)
{
if (offload_to_mirror == 0) {
*map_index %= le16_to_cpu(map->data_disks_per_row);
return;
}
do {
*current_group = *map_index /
le16_to_cpu(map->data_disks_per_row);
if (offload_to_mirror == *current_group)
continue;
if (*current_group < le16_to_cpu(map->layout_map_count) - 1) {
*map_index += le16_to_cpu(map->data_disks_per_row);
(*current_group)++;
} else {
*map_index %= le16_to_cpu(map->data_disks_per_row);
*current_group = 0;
}
} while (offload_to_mirror != *current_group);
}
static int hpsa_scsi_ioaccel_raid_map(struct ctlr_info *h,
struct CommandList *c)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct hpsa_scsi_dev_t *dev = cmd->device->hostdata;
struct raid_map_data *map = &dev->raid_map;
struct raid_map_disk_data *dd = &map->data[0];
int is_write = 0;
u32 map_index;
u64 first_block, last_block;
u32 block_cnt;
u32 blocks_per_row;
u64 first_row, last_row;
u32 first_row_offset, last_row_offset;
u32 first_column, last_column;
u64 r0_first_row, r0_last_row;
u32 r5or6_blocks_per_row;
u64 r5or6_first_row, r5or6_last_row;
u32 r5or6_first_row_offset, r5or6_last_row_offset;
u32 r5or6_first_column, r5or6_last_column;
u32 total_disks_per_row;
u32 stripesize;
u32 first_group, last_group, current_group;
u32 map_row;
u32 disk_handle;
u64 disk_block;
u32 disk_block_cnt;
u8 cdb[16];
u8 cdb_len;
u16 strip_size;
#if BITS_PER_LONG == 32
u64 tmpdiv;
#endif
int offload_to_mirror;
switch (cmd->cmnd[0]) {
case WRITE_6:
is_write = 1;
case READ_6:
first_block = get_unaligned_be16(&cmd->cmnd[2]);
block_cnt = cmd->cmnd[4];
if (block_cnt == 0)
block_cnt = 256;
break;
case WRITE_10:
is_write = 1;
case READ_10:
first_block =
(((u64) cmd->cmnd[2]) << 24) |
(((u64) cmd->cmnd[3]) << 16) |
(((u64) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
block_cnt =
(((u32) cmd->cmnd[7]) << 8) |
cmd->cmnd[8];
break;
case WRITE_12:
is_write = 1;
case READ_12:
first_block =
(((u64) cmd->cmnd[2]) << 24) |
(((u64) cmd->cmnd[3]) << 16) |
(((u64) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
block_cnt =
(((u32) cmd->cmnd[6]) << 24) |
(((u32) cmd->cmnd[7]) << 16) |
(((u32) cmd->cmnd[8]) << 8) |
cmd->cmnd[9];
break;
case WRITE_16:
is_write = 1;
case READ_16:
first_block =
(((u64) cmd->cmnd[2]) << 56) |
(((u64) cmd->cmnd[3]) << 48) |
(((u64) cmd->cmnd[4]) << 40) |
(((u64) cmd->cmnd[5]) << 32) |
(((u64) cmd->cmnd[6]) << 24) |
(((u64) cmd->cmnd[7]) << 16) |
(((u64) cmd->cmnd[8]) << 8) |
cmd->cmnd[9];
block_cnt =
(((u32) cmd->cmnd[10]) << 24) |
(((u32) cmd->cmnd[11]) << 16) |
(((u32) cmd->cmnd[12]) << 8) |
cmd->cmnd[13];
break;
default:
return IO_ACCEL_INELIGIBLE;
}
last_block = first_block + block_cnt - 1;
if (is_write && dev->raid_level != 0)
return IO_ACCEL_INELIGIBLE;
if (last_block >= le64_to_cpu(map->volume_blk_cnt) ||
last_block < first_block)
return IO_ACCEL_INELIGIBLE;
blocks_per_row = le16_to_cpu(map->data_disks_per_row) *
le16_to_cpu(map->strip_size);
strip_size = le16_to_cpu(map->strip_size);
#if BITS_PER_LONG == 32
tmpdiv = first_block;
(void) do_div(tmpdiv, blocks_per_row);
first_row = tmpdiv;
tmpdiv = last_block;
(void) do_div(tmpdiv, blocks_per_row);
last_row = tmpdiv;
first_row_offset = (u32) (first_block - (first_row * blocks_per_row));
last_row_offset = (u32) (last_block - (last_row * blocks_per_row));
tmpdiv = first_row_offset;
(void) do_div(tmpdiv, strip_size);
first_column = tmpdiv;
tmpdiv = last_row_offset;
(void) do_div(tmpdiv, strip_size);
last_column = tmpdiv;
#else
first_row = first_block / blocks_per_row;
last_row = last_block / blocks_per_row;
first_row_offset = (u32) (first_block - (first_row * blocks_per_row));
last_row_offset = (u32) (last_block - (last_row * blocks_per_row));
first_column = first_row_offset / strip_size;
last_column = last_row_offset / strip_size;
#endif
if ((first_row != last_row) || (first_column != last_column))
return IO_ACCEL_INELIGIBLE;
total_disks_per_row = le16_to_cpu(map->data_disks_per_row) +
le16_to_cpu(map->metadata_disks_per_row);
map_row = ((u32)(first_row >> map->parity_rotation_shift)) %
le16_to_cpu(map->row_cnt);
map_index = (map_row * total_disks_per_row) + first_column;
switch (dev->raid_level) {
case HPSA_RAID_0:
break;
case HPSA_RAID_1:
BUG_ON(le16_to_cpu(map->layout_map_count) != 2);
if (dev->offload_to_mirror)
map_index += le16_to_cpu(map->data_disks_per_row);
dev->offload_to_mirror = !dev->offload_to_mirror;
break;
case HPSA_RAID_ADM:
BUG_ON(le16_to_cpu(map->layout_map_count) != 3);
offload_to_mirror = dev->offload_to_mirror;
raid_map_helper(map, offload_to_mirror,
&map_index, &current_group);
offload_to_mirror =
(offload_to_mirror >=
le16_to_cpu(map->layout_map_count) - 1)
? 0 : offload_to_mirror + 1;
dev->offload_to_mirror = offload_to_mirror;
break;
case HPSA_RAID_5:
case HPSA_RAID_6:
if (le16_to_cpu(map->layout_map_count) <= 1)
break;
r5or6_blocks_per_row =
le16_to_cpu(map->strip_size) *
le16_to_cpu(map->data_disks_per_row);
BUG_ON(r5or6_blocks_per_row == 0);
stripesize = r5or6_blocks_per_row *
le16_to_cpu(map->layout_map_count);
#if BITS_PER_LONG == 32
tmpdiv = first_block;
first_group = do_div(tmpdiv, stripesize);
tmpdiv = first_group;
(void) do_div(tmpdiv, r5or6_blocks_per_row);
first_group = tmpdiv;
tmpdiv = last_block;
last_group = do_div(tmpdiv, stripesize);
tmpdiv = last_group;
(void) do_div(tmpdiv, r5or6_blocks_per_row);
last_group = tmpdiv;
#else
first_group = (first_block % stripesize) / r5or6_blocks_per_row;
last_group = (last_block % stripesize) / r5or6_blocks_per_row;
#endif
if (first_group != last_group)
return IO_ACCEL_INELIGIBLE;
#if BITS_PER_LONG == 32
tmpdiv = first_block;
(void) do_div(tmpdiv, stripesize);
first_row = r5or6_first_row = r0_first_row = tmpdiv;
tmpdiv = last_block;
(void) do_div(tmpdiv, stripesize);
r5or6_last_row = r0_last_row = tmpdiv;
#else
first_row = r5or6_first_row = r0_first_row =
first_block / stripesize;
r5or6_last_row = r0_last_row = last_block / stripesize;
#endif
if (r5or6_first_row != r5or6_last_row)
return IO_ACCEL_INELIGIBLE;
#if BITS_PER_LONG == 32
tmpdiv = first_block;
first_row_offset = do_div(tmpdiv, stripesize);
tmpdiv = first_row_offset;
first_row_offset = (u32) do_div(tmpdiv, r5or6_blocks_per_row);
r5or6_first_row_offset = first_row_offset;
tmpdiv = last_block;
r5or6_last_row_offset = do_div(tmpdiv, stripesize);
tmpdiv = r5or6_last_row_offset;
r5or6_last_row_offset = do_div(tmpdiv, r5or6_blocks_per_row);
tmpdiv = r5or6_first_row_offset;
(void) do_div(tmpdiv, map->strip_size);
first_column = r5or6_first_column = tmpdiv;
tmpdiv = r5or6_last_row_offset;
(void) do_div(tmpdiv, map->strip_size);
r5or6_last_column = tmpdiv;
#else
first_row_offset = r5or6_first_row_offset =
(u32)((first_block % stripesize) %
r5or6_blocks_per_row);
r5or6_last_row_offset =
(u32)((last_block % stripesize) %
r5or6_blocks_per_row);
first_column = r5or6_first_column =
r5or6_first_row_offset / le16_to_cpu(map->strip_size);
r5or6_last_column =
r5or6_last_row_offset / le16_to_cpu(map->strip_size);
#endif
if (r5or6_first_column != r5or6_last_column)
return IO_ACCEL_INELIGIBLE;
map_row = ((u32)(first_row >> map->parity_rotation_shift)) %
le16_to_cpu(map->row_cnt);
map_index = (first_group *
(le16_to_cpu(map->row_cnt) * total_disks_per_row)) +
(map_row * total_disks_per_row) + first_column;
break;
default:
return IO_ACCEL_INELIGIBLE;
}
if (unlikely(map_index >= RAID_MAP_MAX_ENTRIES))
return IO_ACCEL_INELIGIBLE;
c->phys_disk = dev->phys_disk[map_index];
disk_handle = dd[map_index].ioaccel_handle;
disk_block = le64_to_cpu(map->disk_starting_blk) +
first_row * le16_to_cpu(map->strip_size) +
(first_row_offset - first_column *
le16_to_cpu(map->strip_size));
disk_block_cnt = block_cnt;
if (map->phys_blk_shift) {
disk_block <<= map->phys_blk_shift;
disk_block_cnt <<= map->phys_blk_shift;
}
BUG_ON(disk_block_cnt > 0xffff);
if (disk_block > 0xffffffff) {
cdb[0] = is_write ? WRITE_16 : READ_16;
cdb[1] = 0;
cdb[2] = (u8) (disk_block >> 56);
cdb[3] = (u8) (disk_block >> 48);
cdb[4] = (u8) (disk_block >> 40);
cdb[5] = (u8) (disk_block >> 32);
cdb[6] = (u8) (disk_block >> 24);
cdb[7] = (u8) (disk_block >> 16);
cdb[8] = (u8) (disk_block >> 8);
cdb[9] = (u8) (disk_block);
cdb[10] = (u8) (disk_block_cnt >> 24);
cdb[11] = (u8) (disk_block_cnt >> 16);
cdb[12] = (u8) (disk_block_cnt >> 8);
cdb[13] = (u8) (disk_block_cnt);
cdb[14] = 0;
cdb[15] = 0;
cdb_len = 16;
} else {
cdb[0] = is_write ? WRITE_10 : READ_10;
cdb[1] = 0;
cdb[2] = (u8) (disk_block >> 24);
cdb[3] = (u8) (disk_block >> 16);
cdb[4] = (u8) (disk_block >> 8);
cdb[5] = (u8) (disk_block);
cdb[6] = 0;
cdb[7] = (u8) (disk_block_cnt >> 8);
cdb[8] = (u8) (disk_block_cnt);
cdb[9] = 0;
cdb_len = 10;
}
return hpsa_scsi_ioaccel_queue_command(h, c, disk_handle, cdb, cdb_len,
dev->scsi3addr,
dev->phys_disk[map_index]);
}
static int hpsa_ciss_submit(struct ctlr_info *h,
struct CommandList *c, struct scsi_cmnd *cmd,
unsigned char scsi3addr[])
{
cmd->host_scribble = (unsigned char *) c;
c->cmd_type = CMD_SCSI;
c->scsi_cmd = cmd;
c->Header.ReplyQueue = 0;
memcpy(&c->Header.LUN.LunAddrBytes[0], &scsi3addr[0], 8);
c->Header.tag = cpu_to_le64((c->cmdindex << DIRECT_LOOKUP_SHIFT));
c->Request.Timeout = 0;
BUG_ON(cmd->cmd_len > sizeof(c->Request.CDB));
c->Request.CDBLen = cmd->cmd_len;
memcpy(c->Request.CDB, cmd->cmnd, cmd->cmd_len);
switch (cmd->sc_data_direction) {
case DMA_TO_DEVICE:
c->Request.type_attr_dir =
TYPE_ATTR_DIR(TYPE_CMD, ATTR_SIMPLE, XFER_WRITE);
break;
case DMA_FROM_DEVICE:
c->Request.type_attr_dir =
TYPE_ATTR_DIR(TYPE_CMD, ATTR_SIMPLE, XFER_READ);
break;
case DMA_NONE:
c->Request.type_attr_dir =
TYPE_ATTR_DIR(TYPE_CMD, ATTR_SIMPLE, XFER_NONE);
break;
case DMA_BIDIRECTIONAL:
c->Request.type_attr_dir =
TYPE_ATTR_DIR(TYPE_CMD, ATTR_SIMPLE, XFER_RSVD);
break;
default:
dev_err(&h->pdev->dev, "unknown data direction: %d\n",
cmd->sc_data_direction);
BUG();
break;
}
if (hpsa_scatter_gather(h, c, cmd) < 0) {
hpsa_cmd_resolve_and_free(h, c);
return SCSI_MLQUEUE_HOST_BUSY;
}
enqueue_cmd_and_start_io(h, c);
return 0;
}
static void hpsa_cmd_init(struct ctlr_info *h, int index,
struct CommandList *c)
{
dma_addr_t cmd_dma_handle, err_dma_handle;
memset(c, 0, offsetof(struct CommandList, refcount));
c->Header.tag = cpu_to_le64((u64) (index << DIRECT_LOOKUP_SHIFT));
cmd_dma_handle = h->cmd_pool_dhandle + index * sizeof(*c);
c->err_info = h->errinfo_pool + index;
memset(c->err_info, 0, sizeof(*c->err_info));
err_dma_handle = h->errinfo_pool_dhandle
+ index * sizeof(*c->err_info);
c->cmdindex = index;
c->busaddr = (u32) cmd_dma_handle;
c->ErrDesc.Addr = cpu_to_le64((u64) err_dma_handle);
c->ErrDesc.Len = cpu_to_le32((u32) sizeof(*c->err_info));
c->h = h;
c->scsi_cmd = SCSI_CMD_IDLE;
}
static void hpsa_preinitialize_commands(struct ctlr_info *h)
{
int i;
for (i = 0; i < h->nr_cmds; i++) {
struct CommandList *c = h->cmd_pool + i;
hpsa_cmd_init(h, i, c);
atomic_set(&c->refcount, 0);
}
}
static inline void hpsa_cmd_partial_init(struct ctlr_info *h, int index,
struct CommandList *c)
{
dma_addr_t cmd_dma_handle = h->cmd_pool_dhandle + index * sizeof(*c);
BUG_ON(c->cmdindex != index);
memset(c->Request.CDB, 0, sizeof(c->Request.CDB));
memset(c->err_info, 0, sizeof(*c->err_info));
c->busaddr = (u32) cmd_dma_handle;
}
static int hpsa_ioaccel_submit(struct ctlr_info *h,
struct CommandList *c, struct scsi_cmnd *cmd,
unsigned char *scsi3addr)
{
struct hpsa_scsi_dev_t *dev = cmd->device->hostdata;
int rc = IO_ACCEL_INELIGIBLE;
cmd->host_scribble = (unsigned char *) c;
if (dev->offload_enabled) {
hpsa_cmd_init(h, c->cmdindex, c);
c->cmd_type = CMD_SCSI;
c->scsi_cmd = cmd;
rc = hpsa_scsi_ioaccel_raid_map(h, c);
if (rc < 0)
rc = SCSI_MLQUEUE_HOST_BUSY;
} else if (dev->hba_ioaccel_enabled) {
hpsa_cmd_init(h, c->cmdindex, c);
c->cmd_type = CMD_SCSI;
c->scsi_cmd = cmd;
rc = hpsa_scsi_ioaccel_direct_map(h, c);
if (rc < 0)
rc = SCSI_MLQUEUE_HOST_BUSY;
}
return rc;
}
static void hpsa_command_resubmit_worker(struct work_struct *work)
{
struct scsi_cmnd *cmd;
struct hpsa_scsi_dev_t *dev;
struct CommandList *c = container_of(work, struct CommandList, work);
cmd = c->scsi_cmd;
dev = cmd->device->hostdata;
if (!dev) {
cmd->result = DID_NO_CONNECT << 16;
return hpsa_cmd_free_and_done(c->h, c, cmd);
}
if (c->reset_pending)
return hpsa_cmd_resolve_and_free(c->h, c);
if (c->abort_pending)
return hpsa_cmd_abort_and_free(c->h, c, cmd);
if (c->cmd_type == CMD_IOACCEL2) {
struct ctlr_info *h = c->h;
struct io_accel2_cmd *c2 = &h->ioaccel2_cmd_pool[c->cmdindex];
int rc;
if (c2->error_data.serv_response ==
IOACCEL2_STATUS_SR_TASK_COMP_SET_FULL) {
rc = hpsa_ioaccel_submit(h, c, cmd, dev->scsi3addr);
if (rc == 0)
return;
if (rc == SCSI_MLQUEUE_HOST_BUSY) {
cmd->result = DID_IMM_RETRY << 16;
return hpsa_cmd_free_and_done(h, c, cmd);
}
}
}
hpsa_cmd_partial_init(c->h, c->cmdindex, c);
if (hpsa_ciss_submit(c->h, c, cmd, dev->scsi3addr)) {
cmd->result = DID_IMM_RETRY << 16;
cmd->scsi_done(cmd);
}
}
static int hpsa_scsi_queue_command(struct Scsi_Host *sh, struct scsi_cmnd *cmd)
{
struct ctlr_info *h;
struct hpsa_scsi_dev_t *dev;
unsigned char scsi3addr[8];
struct CommandList *c;
int rc = 0;
h = sdev_to_hba(cmd->device);
BUG_ON(cmd->request->tag < 0);
dev = cmd->device->hostdata;
if (!dev) {
cmd->result = DID_NO_CONNECT << 16;
cmd->scsi_done(cmd);
return 0;
}
memcpy(scsi3addr, dev->scsi3addr, sizeof(scsi3addr));
if (unlikely(lockup_detected(h))) {
cmd->result = DID_NO_CONNECT << 16;
cmd->scsi_done(cmd);
return 0;
}
c = cmd_tagged_alloc(h, cmd);
if (likely(cmd->retries == 0 &&
cmd->request->cmd_type == REQ_TYPE_FS &&
h->acciopath_status)) {
rc = hpsa_ioaccel_submit(h, c, cmd, scsi3addr);
if (rc == 0)
return 0;
if (rc == SCSI_MLQUEUE_HOST_BUSY) {
hpsa_cmd_resolve_and_free(h, c);
return SCSI_MLQUEUE_HOST_BUSY;
}
}
return hpsa_ciss_submit(h, c, cmd, scsi3addr);
}
static void hpsa_scan_complete(struct ctlr_info *h)
{
unsigned long flags;
spin_lock_irqsave(&h->scan_lock, flags);
h->scan_finished = 1;
wake_up_all(&h->scan_wait_queue);
spin_unlock_irqrestore(&h->scan_lock, flags);
}
static void hpsa_scan_start(struct Scsi_Host *sh)
{
struct ctlr_info *h = shost_to_hba(sh);
unsigned long flags;
if (unlikely(lockup_detected(h)))
return hpsa_scan_complete(h);
while (1) {
spin_lock_irqsave(&h->scan_lock, flags);
if (h->scan_finished)
break;
spin_unlock_irqrestore(&h->scan_lock, flags);
wait_event(h->scan_wait_queue, h->scan_finished);
}
h->scan_finished = 0;
spin_unlock_irqrestore(&h->scan_lock, flags);
if (unlikely(lockup_detected(h)))
return hpsa_scan_complete(h);
hpsa_update_scsi_devices(h);
hpsa_scan_complete(h);
}
static int hpsa_change_queue_depth(struct scsi_device *sdev, int qdepth)
{
struct hpsa_scsi_dev_t *logical_drive = sdev->hostdata;
if (!logical_drive)
return -ENODEV;
if (qdepth < 1)
qdepth = 1;
else if (qdepth > logical_drive->queue_depth)
qdepth = logical_drive->queue_depth;
return scsi_change_queue_depth(sdev, qdepth);
}
static int hpsa_scan_finished(struct Scsi_Host *sh,
unsigned long elapsed_time)
{
struct ctlr_info *h = shost_to_hba(sh);
unsigned long flags;
int finished;
spin_lock_irqsave(&h->scan_lock, flags);
finished = h->scan_finished;
spin_unlock_irqrestore(&h->scan_lock, flags);
return finished;
}
static int hpsa_scsi_host_alloc(struct ctlr_info *h)
{
struct Scsi_Host *sh;
sh = scsi_host_alloc(&hpsa_driver_template, sizeof(h));
if (sh == NULL) {
dev_err(&h->pdev->dev, "scsi_host_alloc failed\n");
return -ENOMEM;
}
sh->io_port = 0;
sh->n_io_port = 0;
sh->this_id = -1;
sh->max_channel = 3;
sh->max_cmd_len = MAX_COMMAND_SIZE;
sh->max_lun = HPSA_MAX_LUN;
sh->max_id = HPSA_MAX_LUN;
sh->can_queue = h->nr_cmds - HPSA_NRESERVED_CMDS;
sh->cmd_per_lun = sh->can_queue;
sh->sg_tablesize = h->maxsgentries;
sh->transportt = hpsa_sas_transport_template;
sh->hostdata[0] = (unsigned long) h;
sh->irq = h->intr[h->intr_mode];
sh->unique_id = sh->irq;
h->scsi_host = sh;
return 0;
}
static int hpsa_scsi_add_host(struct ctlr_info *h)
{
int rv;
rv = scsi_add_host(h->scsi_host, &h->pdev->dev);
if (rv) {
dev_err(&h->pdev->dev, "scsi_add_host failed\n");
return rv;
}
scsi_scan_host(h->scsi_host);
return 0;
}
static int hpsa_get_cmd_index(struct scsi_cmnd *scmd)
{
int idx = scmd->request->tag;
if (idx < 0)
return idx;
return idx += HPSA_NRESERVED_CMDS;
}
static int hpsa_send_test_unit_ready(struct ctlr_info *h,
struct CommandList *c, unsigned char lunaddr[],
int reply_queue)
{
int rc;
(void) fill_cmd(c, TEST_UNIT_READY, h,
NULL, 0, 0, lunaddr, TYPE_CMD);
rc = hpsa_scsi_do_simple_cmd(h, c, reply_queue, NO_TIMEOUT);
if (rc)
return rc;
if (c->err_info->CommandStatus == CMD_SUCCESS)
return 0;
if (c->err_info->CommandStatus == CMD_TARGET_STATUS &&
c->err_info->ScsiStatus == SAM_STAT_CHECK_CONDITION &&
(c->err_info->SenseInfo[2] == NO_SENSE ||
c->err_info->SenseInfo[2] == UNIT_ATTENTION))
return 0;
return 1;
}
static int hpsa_wait_for_test_unit_ready(struct ctlr_info *h,
struct CommandList *c,
unsigned char lunaddr[], int reply_queue)
{
int rc;
int count = 0;
int waittime = 1;
for (count = 0; count < HPSA_TUR_RETRY_LIMIT; count++) {
msleep(1000 * waittime);
rc = hpsa_send_test_unit_ready(h, c, lunaddr, reply_queue);
if (!rc)
break;
if (waittime < HPSA_MAX_WAIT_INTERVAL_SECS)
waittime *= 2;
dev_warn(&h->pdev->dev,
"waiting %d secs for device to become ready.\n",
waittime);
}
return rc;
}
static int wait_for_device_to_become_ready(struct ctlr_info *h,
unsigned char lunaddr[],
int reply_queue)
{
int first_queue;
int last_queue;
int rq;
int rc = 0;
struct CommandList *c;
c = cmd_alloc(h);
if (reply_queue == DEFAULT_REPLY_QUEUE) {
first_queue = 0;
last_queue = h->nreply_queues - 1;
} else {
first_queue = reply_queue;
last_queue = reply_queue;
}
for (rq = first_queue; rq <= last_queue; rq++) {
rc = hpsa_wait_for_test_unit_ready(h, c, lunaddr, rq);
if (rc)
break;
}
if (rc)
dev_warn(&h->pdev->dev, "giving up on device.\n");
else
dev_warn(&h->pdev->dev, "device is ready.\n");
cmd_free(h, c);
return rc;
}
static int hpsa_eh_device_reset_handler(struct scsi_cmnd *scsicmd)
{
int rc;
struct ctlr_info *h;
struct hpsa_scsi_dev_t *dev;
u8 reset_type;
char msg[48];
h = sdev_to_hba(scsicmd->device);
if (h == NULL)
return FAILED;
if (lockup_detected(h))
return FAILED;
dev = scsicmd->device->hostdata;
if (!dev) {
dev_err(&h->pdev->dev, "%s: device lookup failed\n", __func__);
return FAILED;
}
if (lockup_detected(h)) {
snprintf(msg, sizeof(msg),
"cmd %d RESET FAILED, lockup detected",
hpsa_get_cmd_index(scsicmd));
hpsa_show_dev_msg(KERN_WARNING, h, dev, msg);
return FAILED;
}
if (detect_controller_lockup(h)) {
snprintf(msg, sizeof(msg),
"cmd %d RESET FAILED, new lockup detected",
hpsa_get_cmd_index(scsicmd));
hpsa_show_dev_msg(KERN_WARNING, h, dev, msg);
return FAILED;
}
if (is_hba_lunid(dev->scsi3addr))
return SUCCESS;
if (is_logical_dev_addr_mode(dev->scsi3addr))
reset_type = HPSA_DEVICE_RESET_MSG;
else
reset_type = HPSA_PHYS_TARGET_RESET;
sprintf(msg, "resetting %s",
reset_type == HPSA_DEVICE_RESET_MSG ? "logical " : "physical ");
hpsa_show_dev_msg(KERN_WARNING, h, dev, msg);
h->reset_in_progress = 1;
rc = hpsa_do_reset(h, dev, dev->scsi3addr, reset_type,
DEFAULT_REPLY_QUEUE);
sprintf(msg, "reset %s %s",
reset_type == HPSA_DEVICE_RESET_MSG ? "logical " : "physical ",
rc == 0 ? "completed successfully" : "failed");
hpsa_show_dev_msg(KERN_WARNING, h, dev, msg);
h->reset_in_progress = 0;
return rc == 0 ? SUCCESS : FAILED;
}
static void swizzle_abort_tag(u8 *tag)
{
u8 original_tag[8];
memcpy(original_tag, tag, 8);
tag[0] = original_tag[3];
tag[1] = original_tag[2];
tag[2] = original_tag[1];
tag[3] = original_tag[0];
tag[4] = original_tag[7];
tag[5] = original_tag[6];
tag[6] = original_tag[5];
tag[7] = original_tag[4];
}
static void hpsa_get_tag(struct ctlr_info *h,
struct CommandList *c, __le32 *taglower, __le32 *tagupper)
{
u64 tag;
if (c->cmd_type == CMD_IOACCEL1) {
struct io_accel1_cmd *cm1 = (struct io_accel1_cmd *)
&h->ioaccel_cmd_pool[c->cmdindex];
tag = le64_to_cpu(cm1->tag);
*tagupper = cpu_to_le32(tag >> 32);
*taglower = cpu_to_le32(tag);
return;
}
if (c->cmd_type == CMD_IOACCEL2) {
struct io_accel2_cmd *cm2 = (struct io_accel2_cmd *)
&h->ioaccel2_cmd_pool[c->cmdindex];
memset(tagupper, 0, sizeof(*tagupper));
*taglower = cm2->Tag;
return;
}
tag = le64_to_cpu(c->Header.tag);
*tagupper = cpu_to_le32(tag >> 32);
*taglower = cpu_to_le32(tag);
}
static int hpsa_send_abort(struct ctlr_info *h, unsigned char *scsi3addr,
struct CommandList *abort, int reply_queue)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
__le32 tagupper, taglower;
c = cmd_alloc(h);
(void) fill_cmd(c, HPSA_ABORT_MSG, h, &abort->Header.tag,
0, 0, scsi3addr, TYPE_MSG);
if (h->needs_abort_tags_swizzled)
swizzle_abort_tag(&c->Request.CDB[4]);
(void) hpsa_scsi_do_simple_cmd(h, c, reply_queue, NO_TIMEOUT);
hpsa_get_tag(h, abort, &taglower, &tagupper);
dev_dbg(&h->pdev->dev, "%s: Tag:0x%08x:%08x: do_simple_cmd(abort) completed.\n",
__func__, tagupper, taglower);
ei = c->err_info;
switch (ei->CommandStatus) {
case CMD_SUCCESS:
break;
case CMD_TMF_STATUS:
rc = hpsa_evaluate_tmf_status(h, c);
break;
case CMD_UNABORTABLE:
rc = -1;
break;
default:
dev_dbg(&h->pdev->dev, "%s: Tag:0x%08x:%08x: interpreting error.\n",
__func__, tagupper, taglower);
hpsa_scsi_interpret_error(h, c);
rc = -1;
break;
}
cmd_free(h, c);
dev_dbg(&h->pdev->dev, "%s: Tag:0x%08x:%08x: Finished.\n",
__func__, tagupper, taglower);
return rc;
}
static void setup_ioaccel2_abort_cmd(struct CommandList *c, struct ctlr_info *h,
struct CommandList *command_to_abort, int reply_queue)
{
struct io_accel2_cmd *c2 = &h->ioaccel2_cmd_pool[c->cmdindex];
struct hpsa_tmf_struct *ac = (struct hpsa_tmf_struct *) c2;
struct io_accel2_cmd *c2a =
&h->ioaccel2_cmd_pool[command_to_abort->cmdindex];
struct scsi_cmnd *scmd = command_to_abort->scsi_cmd;
struct hpsa_scsi_dev_t *dev = scmd->device->hostdata;
BUILD_BUG_ON(sizeof(struct hpsa_tmf_struct) >
sizeof(struct io_accel2_cmd));
BUG_ON(offsetof(struct io_accel2_cmd, error_data) <
offsetof(struct hpsa_tmf_struct, error_len) +
sizeof(ac->error_len));
c->cmd_type = IOACCEL2_TMF;
c->scsi_cmd = SCSI_CMD_BUSY;
c->busaddr = (u32) h->ioaccel2_cmd_pool_dhandle +
(c->cmdindex * sizeof(struct io_accel2_cmd));
BUG_ON(c->busaddr & 0x0000007F);
memset(ac, 0, sizeof(*c2));
ac->iu_type = IOACCEL2_IU_TMF_TYPE;
ac->reply_queue = reply_queue;
ac->tmf = IOACCEL2_TMF_ABORT;
ac->it_nexus = cpu_to_le32(dev->ioaccel_handle);
memset(ac->lun_id, 0, sizeof(ac->lun_id));
ac->tag = cpu_to_le64(c->cmdindex << DIRECT_LOOKUP_SHIFT);
ac->abort_tag = cpu_to_le64(le32_to_cpu(c2a->Tag));
ac->error_ptr = cpu_to_le64(c->busaddr +
offsetof(struct io_accel2_cmd, error_data));
ac->error_len = cpu_to_le32(sizeof(c2->error_data));
}
static int hpsa_send_reset_as_abort_ioaccel2(struct ctlr_info *h,
unsigned char *scsi3addr, struct CommandList *abort, int reply_queue)
{
int rc = IO_OK;
struct scsi_cmnd *scmd;
struct hpsa_scsi_dev_t *dev;
unsigned char phys_scsi3addr[8];
unsigned char *psa = &phys_scsi3addr[0];
scmd = abort->scsi_cmd;
dev = (struct hpsa_scsi_dev_t *)(scmd->device->hostdata);
if (dev == NULL) {
dev_warn(&h->pdev->dev,
"Cannot abort: no device pointer for command.\n");
return -1;
}
if (h->raid_offload_debug > 0)
dev_info(&h->pdev->dev,
"scsi %d:%d:%d:%d %s scsi3addr 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
h->scsi_host->host_no, dev->bus, dev->target, dev->lun,
"Reset as abort",
scsi3addr[0], scsi3addr[1], scsi3addr[2], scsi3addr[3],
scsi3addr[4], scsi3addr[5], scsi3addr[6], scsi3addr[7]);
if (!dev->offload_enabled) {
dev_warn(&h->pdev->dev,
"Can't abort: device is not operating in HP SSD Smart Path mode.\n");
return -1;
}
if (!hpsa_get_pdisk_of_ioaccel2(h, abort, psa)) {
dev_warn(&h->pdev->dev, "Can't abort: Failed lookup of physical address.\n");
return -1;
}
if (h->raid_offload_debug > 0)
dev_info(&h->pdev->dev,
"Reset as abort: Resetting physical device at scsi3addr 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
psa[0], psa[1], psa[2], psa[3],
psa[4], psa[5], psa[6], psa[7]);
rc = hpsa_do_reset(h, dev, psa, HPSA_RESET_TYPE_TARGET, reply_queue);
if (rc != 0) {
dev_warn(&h->pdev->dev,
"Reset as abort: Failed on physical device at scsi3addr 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
psa[0], psa[1], psa[2], psa[3],
psa[4], psa[5], psa[6], psa[7]);
return rc;
}
if (wait_for_device_to_become_ready(h, psa, reply_queue) != 0) {
dev_warn(&h->pdev->dev,
"Reset as abort: Failed: Device never recovered from reset: 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
psa[0], psa[1], psa[2], psa[3],
psa[4], psa[5], psa[6], psa[7]);
return -1;
}
dev_info(&h->pdev->dev,
"Reset as abort: Device recovered from reset: scsi3addr 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
psa[0], psa[1], psa[2], psa[3],
psa[4], psa[5], psa[6], psa[7]);
return rc;
}
static int hpsa_send_abort_ioaccel2(struct ctlr_info *h,
struct CommandList *abort, int reply_queue)
{
int rc = IO_OK;
struct CommandList *c;
__le32 taglower, tagupper;
struct hpsa_scsi_dev_t *dev;
struct io_accel2_cmd *c2;
dev = abort->scsi_cmd->device->hostdata;
if (!dev->offload_enabled && !dev->hba_ioaccel_enabled)
return -1;
c = cmd_alloc(h);
setup_ioaccel2_abort_cmd(c, h, abort, reply_queue);
c2 = &h->ioaccel2_cmd_pool[c->cmdindex];
(void) hpsa_scsi_do_simple_cmd(h, c, reply_queue, NO_TIMEOUT);
hpsa_get_tag(h, abort, &taglower, &tagupper);
dev_dbg(&h->pdev->dev,
"%s: Tag:0x%08x:%08x: do_simple_cmd(ioaccel2 abort) completed.\n",
__func__, tagupper, taglower);
dev_dbg(&h->pdev->dev,
"%s: Tag:0x%08x:%08x: abort service response = 0x%02x.\n",
__func__, tagupper, taglower, c2->error_data.serv_response);
switch (c2->error_data.serv_response) {
case IOACCEL2_SERV_RESPONSE_TMF_COMPLETE:
case IOACCEL2_SERV_RESPONSE_TMF_SUCCESS:
rc = 0;
break;
case IOACCEL2_SERV_RESPONSE_TMF_REJECTED:
case IOACCEL2_SERV_RESPONSE_FAILURE:
case IOACCEL2_SERV_RESPONSE_TMF_WRONG_LUN:
rc = -1;
break;
default:
dev_warn(&h->pdev->dev,
"%s: Tag:0x%08x:%08x: unknown abort service response 0x%02x\n",
__func__, tagupper, taglower,
c2->error_data.serv_response);
rc = -1;
}
cmd_free(h, c);
dev_dbg(&h->pdev->dev, "%s: Tag:0x%08x:%08x: Finished.\n", __func__,
tagupper, taglower);
return rc;
}
static int hpsa_send_abort_both_ways(struct ctlr_info *h,
unsigned char *scsi3addr, struct CommandList *abort, int reply_queue)
{
if (abort->cmd_type == CMD_IOACCEL2) {
if (HPSATMF_IOACCEL_ENABLED & h->TMFSupportFlags)
return hpsa_send_abort_ioaccel2(h, abort,
reply_queue);
else
return hpsa_send_reset_as_abort_ioaccel2(h, scsi3addr,
abort, reply_queue);
}
return hpsa_send_abort(h, scsi3addr, abort, reply_queue);
}
static int hpsa_extract_reply_queue(struct ctlr_info *h,
struct CommandList *c)
{
if (c->cmd_type == CMD_IOACCEL2)
return h->ioaccel2_cmd_pool[c->cmdindex].reply_queue;
return c->Header.ReplyQueue;
}
static inline int wait_for_available_abort_cmd(struct ctlr_info *h)
{
#define ABORT_CMD_WAIT_MSECS 5000
return !wait_event_timeout(h->abort_cmd_wait_queue,
atomic_dec_if_positive(&h->abort_cmds_available) >= 0,
msecs_to_jiffies(ABORT_CMD_WAIT_MSECS));
}
static int hpsa_eh_abort_handler(struct scsi_cmnd *sc)
{
int rc;
struct ctlr_info *h;
struct hpsa_scsi_dev_t *dev;
struct CommandList *abort;
struct scsi_cmnd *as;
char msg[256];
int ml = 0;
__le32 tagupper, taglower;
int refcount, reply_queue;
if (sc == NULL)
return FAILED;
if (sc->device == NULL)
return FAILED;
h = sdev_to_hba(sc->device);
if (h == NULL)
return FAILED;
dev = sc->device->hostdata;
if (!dev) {
dev_err(&h->pdev->dev, "%s FAILED, Device lookup failed.\n",
msg);
return FAILED;
}
if (lockup_detected(h)) {
hpsa_show_dev_msg(KERN_WARNING, h, dev,
"ABORT FAILED, lockup detected");
return FAILED;
}
if (detect_controller_lockup(h)) {
hpsa_show_dev_msg(KERN_WARNING, h, dev,
"ABORT FAILED, new lockup detected");
return FAILED;
}
if (!(HPSATMF_PHYS_TASK_ABORT & h->TMFSupportFlags) &&
!(HPSATMF_LOG_TASK_ABORT & h->TMFSupportFlags))
return FAILED;
memset(msg, 0, sizeof(msg));
ml += sprintf(msg+ml, "scsi %d:%d:%d:%llu %s %p",
h->scsi_host->host_no, sc->device->channel,
sc->device->id, sc->device->lun,
"Aborting command", sc);
abort = (struct CommandList *) sc->host_scribble;
if (abort == NULL) {
return SUCCESS;
}
refcount = atomic_inc_return(&abort->refcount);
if (refcount == 1) {
cmd_free(h, abort);
return SUCCESS;
}
if (abort->cmd_type != CMD_IOACCEL2 &&
abort->cmd_type != CMD_IOACCEL1 && !dev->supports_aborts) {
cmd_free(h, abort);
return FAILED;
}
if (abort->scsi_cmd != sc) {
cmd_free(h, abort);
return SUCCESS;
}
abort->abort_pending = true;
hpsa_get_tag(h, abort, &taglower, &tagupper);
reply_queue = hpsa_extract_reply_queue(h, abort);
ml += sprintf(msg+ml, "Tag:0x%08x:%08x ", tagupper, taglower);
as = abort->scsi_cmd;
if (as != NULL)
ml += sprintf(msg+ml,
"CDBLen: %d CDB: 0x%02x%02x... SN: 0x%lx ",
as->cmd_len, as->cmnd[0], as->cmnd[1],
as->serial_number);
dev_warn(&h->pdev->dev, "%s BEING SENT\n", msg);
hpsa_show_dev_msg(KERN_WARNING, h, dev, "Aborting command");
if (wait_for_available_abort_cmd(h)) {
dev_warn(&h->pdev->dev,
"%s FAILED, timeout waiting for an abort command to become available.\n",
msg);
cmd_free(h, abort);
return FAILED;
}
rc = hpsa_send_abort_both_ways(h, dev->scsi3addr, abort, reply_queue);
atomic_inc(&h->abort_cmds_available);
wake_up_all(&h->abort_cmd_wait_queue);
if (rc != 0) {
dev_warn(&h->pdev->dev, "%s SENT, FAILED\n", msg);
hpsa_show_dev_msg(KERN_WARNING, h, dev,
"FAILED to abort command");
cmd_free(h, abort);
return FAILED;
}
dev_info(&h->pdev->dev, "%s SENT, SUCCESS\n", msg);
wait_event(h->event_sync_wait_queue,
abort->scsi_cmd != sc || lockup_detected(h));
cmd_free(h, abort);
return !lockup_detected(h) ? SUCCESS : FAILED;
}
static struct CommandList *cmd_tagged_alloc(struct ctlr_info *h,
struct scsi_cmnd *scmd)
{
int idx = hpsa_get_cmd_index(scmd);
struct CommandList *c = h->cmd_pool + idx;
if (idx < HPSA_NRESERVED_CMDS || idx >= h->nr_cmds) {
dev_err(&h->pdev->dev, "Bad block tag: %d not in [%d..%d]\n",
idx, HPSA_NRESERVED_CMDS, h->nr_cmds - 1);
BUG();
}
atomic_inc(&c->refcount);
if (unlikely(!hpsa_is_cmd_idle(c))) {
dev_err(&h->pdev->dev,
"tag collision (tag=%d) in cmd_tagged_alloc().\n",
idx);
if (c->scsi_cmd != NULL)
scsi_print_command(c->scsi_cmd);
scsi_print_command(scmd);
}
hpsa_cmd_partial_init(h, idx, c);
return c;
}
static void cmd_tagged_free(struct ctlr_info *h, struct CommandList *c)
{
(void)atomic_dec(&c->refcount);
}
static struct CommandList *cmd_alloc(struct ctlr_info *h)
{
struct CommandList *c;
int refcount, i;
int offset = 0;
for (;;) {
i = find_next_zero_bit(h->cmd_pool_bits,
HPSA_NRESERVED_CMDS,
offset);
if (unlikely(i >= HPSA_NRESERVED_CMDS)) {
offset = 0;
continue;
}
c = h->cmd_pool + i;
refcount = atomic_inc_return(&c->refcount);
if (unlikely(refcount > 1)) {
cmd_free(h, c);
offset = (i + 1) % HPSA_NRESERVED_CMDS;
continue;
}
set_bit(i & (BITS_PER_LONG - 1),
h->cmd_pool_bits + (i / BITS_PER_LONG));
break;
}
hpsa_cmd_partial_init(h, i, c);
return c;
}
static void cmd_free(struct ctlr_info *h, struct CommandList *c)
{
if (atomic_dec_and_test(&c->refcount)) {
int i;
i = c - h->cmd_pool;
clear_bit(i & (BITS_PER_LONG - 1),
h->cmd_pool_bits + (i / BITS_PER_LONG));
}
}
static int hpsa_ioctl32_passthru(struct scsi_device *dev, int cmd,
void __user *arg)
{
IOCTL32_Command_struct __user *arg32 =
(IOCTL32_Command_struct __user *) arg;
IOCTL_Command_struct arg64;
IOCTL_Command_struct __user *p = compat_alloc_user_space(sizeof(arg64));
int err;
u32 cp;
memset(&arg64, 0, sizeof(arg64));
err = 0;
err |= copy_from_user(&arg64.LUN_info, &arg32->LUN_info,
sizeof(arg64.LUN_info));
err |= copy_from_user(&arg64.Request, &arg32->Request,
sizeof(arg64.Request));
err |= copy_from_user(&arg64.error_info, &arg32->error_info,
sizeof(arg64.error_info));
err |= get_user(arg64.buf_size, &arg32->buf_size);
err |= get_user(cp, &arg32->buf);
arg64.buf = compat_ptr(cp);
err |= copy_to_user(p, &arg64, sizeof(arg64));
if (err)
return -EFAULT;
err = hpsa_ioctl(dev, CCISS_PASSTHRU, p);
if (err)
return err;
err |= copy_in_user(&arg32->error_info, &p->error_info,
sizeof(arg32->error_info));
if (err)
return -EFAULT;
return err;
}
static int hpsa_ioctl32_big_passthru(struct scsi_device *dev,
int cmd, void __user *arg)
{
BIG_IOCTL32_Command_struct __user *arg32 =
(BIG_IOCTL32_Command_struct __user *) arg;
BIG_IOCTL_Command_struct arg64;
BIG_IOCTL_Command_struct __user *p =
compat_alloc_user_space(sizeof(arg64));
int err;
u32 cp;
memset(&arg64, 0, sizeof(arg64));
err = 0;
err |= copy_from_user(&arg64.LUN_info, &arg32->LUN_info,
sizeof(arg64.LUN_info));
err |= copy_from_user(&arg64.Request, &arg32->Request,
sizeof(arg64.Request));
err |= copy_from_user(&arg64.error_info, &arg32->error_info,
sizeof(arg64.error_info));
err |= get_user(arg64.buf_size, &arg32->buf_size);
err |= get_user(arg64.malloc_size, &arg32->malloc_size);
err |= get_user(cp, &arg32->buf);
arg64.buf = compat_ptr(cp);
err |= copy_to_user(p, &arg64, sizeof(arg64));
if (err)
return -EFAULT;
err = hpsa_ioctl(dev, CCISS_BIG_PASSTHRU, p);
if (err)
return err;
err |= copy_in_user(&arg32->error_info, &p->error_info,
sizeof(arg32->error_info));
if (err)
return -EFAULT;
return err;
}
static int hpsa_compat_ioctl(struct scsi_device *dev, int cmd, void __user *arg)
{
switch (cmd) {
case CCISS_GETPCIINFO:
case CCISS_GETINTINFO:
case CCISS_SETINTINFO:
case CCISS_GETNODENAME:
case CCISS_SETNODENAME:
case CCISS_GETHEARTBEAT:
case CCISS_GETBUSTYPES:
case CCISS_GETFIRMVER:
case CCISS_GETDRIVVER:
case CCISS_REVALIDVOLS:
case CCISS_DEREGDISK:
case CCISS_REGNEWDISK:
case CCISS_REGNEWD:
case CCISS_RESCANDISK:
case CCISS_GETLUNINFO:
return hpsa_ioctl(dev, cmd, arg);
case CCISS_PASSTHRU32:
return hpsa_ioctl32_passthru(dev, cmd, arg);
case CCISS_BIG_PASSTHRU32:
return hpsa_ioctl32_big_passthru(dev, cmd, arg);
default:
return -ENOIOCTLCMD;
}
}
static int hpsa_getpciinfo_ioctl(struct ctlr_info *h, void __user *argp)
{
struct hpsa_pci_info pciinfo;
if (!argp)
return -EINVAL;
pciinfo.domain = pci_domain_nr(h->pdev->bus);
pciinfo.bus = h->pdev->bus->number;
pciinfo.dev_fn = h->pdev->devfn;
pciinfo.board_id = h->board_id;
if (copy_to_user(argp, &pciinfo, sizeof(pciinfo)))
return -EFAULT;
return 0;
}
static int hpsa_getdrivver_ioctl(struct ctlr_info *h, void __user *argp)
{
DriverVer_type DriverVer;
unsigned char vmaj, vmin, vsubmin;
int rc;
rc = sscanf(HPSA_DRIVER_VERSION, "%hhu.%hhu.%hhu",
&vmaj, &vmin, &vsubmin);
if (rc != 3) {
dev_info(&h->pdev->dev, "driver version string '%s' "
"unrecognized.", HPSA_DRIVER_VERSION);
vmaj = 0;
vmin = 0;
vsubmin = 0;
}
DriverVer = (vmaj << 16) | (vmin << 8) | vsubmin;
if (!argp)
return -EINVAL;
if (copy_to_user(argp, &DriverVer, sizeof(DriverVer_type)))
return -EFAULT;
return 0;
}
static int hpsa_passthru_ioctl(struct ctlr_info *h, void __user *argp)
{
IOCTL_Command_struct iocommand;
struct CommandList *c;
char *buff = NULL;
u64 temp64;
int rc = 0;
if (!argp)
return -EINVAL;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (copy_from_user(&iocommand, argp, sizeof(iocommand)))
return -EFAULT;
if ((iocommand.buf_size < 1) &&
(iocommand.Request.Type.Direction != XFER_NONE)) {
return -EINVAL;
}
if (iocommand.buf_size > 0) {
buff = kmalloc(iocommand.buf_size, GFP_KERNEL);
if (buff == NULL)
return -ENOMEM;
if (iocommand.Request.Type.Direction & XFER_WRITE) {
if (copy_from_user(buff, iocommand.buf,
iocommand.buf_size)) {
rc = -EFAULT;
goto out_kfree;
}
} else {
memset(buff, 0, iocommand.buf_size);
}
}
c = cmd_alloc(h);
c->cmd_type = CMD_IOCTL_PEND;
c->scsi_cmd = SCSI_CMD_BUSY;
c->Header.ReplyQueue = 0;
if (iocommand.buf_size > 0) {
c->Header.SGList = 1;
c->Header.SGTotal = cpu_to_le16(1);
} else {
c->Header.SGList = 0;
c->Header.SGTotal = cpu_to_le16(0);
}
memcpy(&c->Header.LUN, &iocommand.LUN_info, sizeof(c->Header.LUN));
memcpy(&c->Request, &iocommand.Request,
sizeof(c->Request));
if (iocommand.buf_size > 0) {
temp64 = pci_map_single(h->pdev, buff,
iocommand.buf_size, PCI_DMA_BIDIRECTIONAL);
if (dma_mapping_error(&h->pdev->dev, (dma_addr_t) temp64)) {
c->SG[0].Addr = cpu_to_le64(0);
c->SG[0].Len = cpu_to_le32(0);
rc = -ENOMEM;
goto out;
}
c->SG[0].Addr = cpu_to_le64(temp64);
c->SG[0].Len = cpu_to_le32(iocommand.buf_size);
c->SG[0].Ext = cpu_to_le32(HPSA_SG_LAST);
}
rc = hpsa_scsi_do_simple_cmd(h, c, DEFAULT_REPLY_QUEUE, NO_TIMEOUT);
if (iocommand.buf_size > 0)
hpsa_pci_unmap(h->pdev, c, 1, PCI_DMA_BIDIRECTIONAL);
check_ioctl_unit_attention(h, c);
if (rc) {
rc = -EIO;
goto out;
}
memcpy(&iocommand.error_info, c->err_info,
sizeof(iocommand.error_info));
if (copy_to_user(argp, &iocommand, sizeof(iocommand))) {
rc = -EFAULT;
goto out;
}
if ((iocommand.Request.Type.Direction & XFER_READ) &&
iocommand.buf_size > 0) {
if (copy_to_user(iocommand.buf, buff, iocommand.buf_size)) {
rc = -EFAULT;
goto out;
}
}
out:
cmd_free(h, c);
out_kfree:
kfree(buff);
return rc;
}
static int hpsa_big_passthru_ioctl(struct ctlr_info *h, void __user *argp)
{
BIG_IOCTL_Command_struct *ioc;
struct CommandList *c;
unsigned char **buff = NULL;
int *buff_size = NULL;
u64 temp64;
BYTE sg_used = 0;
int status = 0;
u32 left;
u32 sz;
BYTE __user *data_ptr;
if (!argp)
return -EINVAL;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
ioc = (BIG_IOCTL_Command_struct *)
kmalloc(sizeof(*ioc), GFP_KERNEL);
if (!ioc) {
status = -ENOMEM;
goto cleanup1;
}
if (copy_from_user(ioc, argp, sizeof(*ioc))) {
status = -EFAULT;
goto cleanup1;
}
if ((ioc->buf_size < 1) &&
(ioc->Request.Type.Direction != XFER_NONE)) {
status = -EINVAL;
goto cleanup1;
}
if (ioc->malloc_size > MAX_KMALLOC_SIZE) {
status = -EINVAL;
goto cleanup1;
}
if (ioc->buf_size > ioc->malloc_size * SG_ENTRIES_IN_CMD) {
status = -EINVAL;
goto cleanup1;
}
buff = kzalloc(SG_ENTRIES_IN_CMD * sizeof(char *), GFP_KERNEL);
if (!buff) {
status = -ENOMEM;
goto cleanup1;
}
buff_size = kmalloc(SG_ENTRIES_IN_CMD * sizeof(int), GFP_KERNEL);
if (!buff_size) {
status = -ENOMEM;
goto cleanup1;
}
left = ioc->buf_size;
data_ptr = ioc->buf;
while (left) {
sz = (left > ioc->malloc_size) ? ioc->malloc_size : left;
buff_size[sg_used] = sz;
buff[sg_used] = kmalloc(sz, GFP_KERNEL);
if (buff[sg_used] == NULL) {
status = -ENOMEM;
goto cleanup1;
}
if (ioc->Request.Type.Direction & XFER_WRITE) {
if (copy_from_user(buff[sg_used], data_ptr, sz)) {
status = -EFAULT;
goto cleanup1;
}
} else
memset(buff[sg_used], 0, sz);
left -= sz;
data_ptr += sz;
sg_used++;
}
c = cmd_alloc(h);
c->cmd_type = CMD_IOCTL_PEND;
c->scsi_cmd = SCSI_CMD_BUSY;
c->Header.ReplyQueue = 0;
c->Header.SGList = (u8) sg_used;
c->Header.SGTotal = cpu_to_le16(sg_used);
memcpy(&c->Header.LUN, &ioc->LUN_info, sizeof(c->Header.LUN));
memcpy(&c->Request, &ioc->Request, sizeof(c->Request));
if (ioc->buf_size > 0) {
int i;
for (i = 0; i < sg_used; i++) {
temp64 = pci_map_single(h->pdev, buff[i],
buff_size[i], PCI_DMA_BIDIRECTIONAL);
if (dma_mapping_error(&h->pdev->dev,
(dma_addr_t) temp64)) {
c->SG[i].Addr = cpu_to_le64(0);
c->SG[i].Len = cpu_to_le32(0);
hpsa_pci_unmap(h->pdev, c, i,
PCI_DMA_BIDIRECTIONAL);
status = -ENOMEM;
goto cleanup0;
}
c->SG[i].Addr = cpu_to_le64(temp64);
c->SG[i].Len = cpu_to_le32(buff_size[i]);
c->SG[i].Ext = cpu_to_le32(0);
}
c->SG[--i].Ext = cpu_to_le32(HPSA_SG_LAST);
}
status = hpsa_scsi_do_simple_cmd(h, c, DEFAULT_REPLY_QUEUE, NO_TIMEOUT);
if (sg_used)
hpsa_pci_unmap(h->pdev, c, sg_used, PCI_DMA_BIDIRECTIONAL);
check_ioctl_unit_attention(h, c);
if (status) {
status = -EIO;
goto cleanup0;
}
memcpy(&ioc->error_info, c->err_info, sizeof(ioc->error_info));
if (copy_to_user(argp, ioc, sizeof(*ioc))) {
status = -EFAULT;
goto cleanup0;
}
if ((ioc->Request.Type.Direction & XFER_READ) && ioc->buf_size > 0) {
int i;
BYTE __user *ptr = ioc->buf;
for (i = 0; i < sg_used; i++) {
if (copy_to_user(ptr, buff[i], buff_size[i])) {
status = -EFAULT;
goto cleanup0;
}
ptr += buff_size[i];
}
}
status = 0;
cleanup0:
cmd_free(h, c);
cleanup1:
if (buff) {
int i;
for (i = 0; i < sg_used; i++)
kfree(buff[i]);
kfree(buff);
}
kfree(buff_size);
kfree(ioc);
return status;
}
static void check_ioctl_unit_attention(struct ctlr_info *h,
struct CommandList *c)
{
if (c->err_info->CommandStatus == CMD_TARGET_STATUS &&
c->err_info->ScsiStatus != SAM_STAT_CHECK_CONDITION)
(void) check_for_unit_attention(h, c);
}
static int hpsa_ioctl(struct scsi_device *dev, int cmd, void __user *arg)
{
struct ctlr_info *h;
void __user *argp = (void __user *)arg;
int rc;
h = sdev_to_hba(dev);
switch (cmd) {
case CCISS_DEREGDISK:
case CCISS_REGNEWDISK:
case CCISS_REGNEWD:
hpsa_scan_start(h->scsi_host);
return 0;
case CCISS_GETPCIINFO:
return hpsa_getpciinfo_ioctl(h, argp);
case CCISS_GETDRIVVER:
return hpsa_getdrivver_ioctl(h, argp);
case CCISS_PASSTHRU:
if (atomic_dec_if_positive(&h->passthru_cmds_avail) < 0)
return -EAGAIN;
rc = hpsa_passthru_ioctl(h, argp);
atomic_inc(&h->passthru_cmds_avail);
return rc;
case CCISS_BIG_PASSTHRU:
if (atomic_dec_if_positive(&h->passthru_cmds_avail) < 0)
return -EAGAIN;
rc = hpsa_big_passthru_ioctl(h, argp);
atomic_inc(&h->passthru_cmds_avail);
return rc;
default:
return -ENOTTY;
}
}
static void hpsa_send_host_reset(struct ctlr_info *h, unsigned char *scsi3addr,
u8 reset_type)
{
struct CommandList *c;
c = cmd_alloc(h);
(void) fill_cmd(c, HPSA_DEVICE_RESET_MSG, h, NULL, 0, 0,
RAID_CTLR_LUNID, TYPE_MSG);
c->Request.CDB[1] = reset_type;
c->waiting = NULL;
enqueue_cmd_and_start_io(h, c);
return;
}
static int fill_cmd(struct CommandList *c, u8 cmd, struct ctlr_info *h,
void *buff, size_t size, u16 page_code, unsigned char *scsi3addr,
int cmd_type)
{
int pci_dir = XFER_NONE;
u64 tag;
c->cmd_type = CMD_IOCTL_PEND;
c->scsi_cmd = SCSI_CMD_BUSY;
c->Header.ReplyQueue = 0;
if (buff != NULL && size > 0) {
c->Header.SGList = 1;
c->Header.SGTotal = cpu_to_le16(1);
} else {
c->Header.SGList = 0;
c->Header.SGTotal = cpu_to_le16(0);
}
memcpy(c->Header.LUN.LunAddrBytes, scsi3addr, 8);
if (cmd_type == TYPE_CMD) {
switch (cmd) {
case HPSA_INQUIRY:
if (page_code & VPD_PAGE) {
c->Request.CDB[1] = 0x01;
c->Request.CDB[2] = (page_code & 0xff);
}
c->Request.CDBLen = 6;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = HPSA_INQUIRY;
c->Request.CDB[4] = size & 0xFF;
break;
case HPSA_REPORT_LOG:
case HPSA_REPORT_PHYS:
c->Request.CDBLen = 12;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
c->Request.CDB[6] = (size >> 24) & 0xFF;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0xFF;
c->Request.CDB[9] = size & 0xFF;
break;
case BMIC_SENSE_DIAG_OPTIONS:
c->Request.CDBLen = 16;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_READ;
c->Request.CDB[6] = BMIC_SENSE_DIAG_OPTIONS;
break;
case BMIC_SET_DIAG_OPTIONS:
c->Request.CDBLen = 16;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type,
ATTR_SIMPLE, XFER_WRITE);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_WRITE;
c->Request.CDB[6] = BMIC_SET_DIAG_OPTIONS;
break;
case HPSA_CACHE_FLUSH:
c->Request.CDBLen = 12;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type,
ATTR_SIMPLE, XFER_WRITE);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_WRITE;
c->Request.CDB[6] = BMIC_CACHE_FLUSH;
c->Request.CDB[7] = (size >> 8) & 0xFF;
c->Request.CDB[8] = size & 0xFF;
break;
case TEST_UNIT_READY:
c->Request.CDBLen = 6;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_NONE);
c->Request.Timeout = 0;
break;
case HPSA_GET_RAID_MAP:
c->Request.CDBLen = 12;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = HPSA_CISS_READ;
c->Request.CDB[1] = cmd;
c->Request.CDB[6] = (size >> 24) & 0xFF;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0xFF;
c->Request.CDB[9] = size & 0xFF;
break;
case BMIC_SENSE_CONTROLLER_PARAMETERS:
c->Request.CDBLen = 10;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_READ;
c->Request.CDB[6] = BMIC_SENSE_CONTROLLER_PARAMETERS;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0xFF;
break;
case BMIC_IDENTIFY_PHYSICAL_DEVICE:
c->Request.CDBLen = 10;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_READ;
c->Request.CDB[6] = BMIC_IDENTIFY_PHYSICAL_DEVICE;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0XFF;
break;
case BMIC_SENSE_SUBSYSTEM_INFORMATION:
c->Request.CDBLen = 10;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_READ;
c->Request.CDB[6] = BMIC_SENSE_SUBSYSTEM_INFORMATION;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0XFF;
break;
case BMIC_IDENTIFY_CONTROLLER:
c->Request.CDBLen = 10;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_READ);
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_READ;
c->Request.CDB[1] = 0;
c->Request.CDB[2] = 0;
c->Request.CDB[3] = 0;
c->Request.CDB[4] = 0;
c->Request.CDB[5] = 0;
c->Request.CDB[6] = BMIC_IDENTIFY_CONTROLLER;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0XFF;
c->Request.CDB[9] = 0;
break;
default:
dev_warn(&h->pdev->dev, "unknown command 0x%c\n", cmd);
BUG();
return -1;
}
} else if (cmd_type == TYPE_MSG) {
switch (cmd) {
case HPSA_PHYS_TARGET_RESET:
c->Request.CDBLen = 16;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_NONE);
c->Request.Timeout = 0;
memset(&c->Request.CDB[0], 0, sizeof(c->Request.CDB));
c->Request.CDB[0] = HPSA_RESET;
c->Request.CDB[1] = HPSA_TARGET_RESET_TYPE;
c->Request.CDB[4] = 0x00;
c->Request.CDB[5] = 0x00;
c->Request.CDB[6] = 0x00;
c->Request.CDB[7] = 0x00;
break;
case HPSA_DEVICE_RESET_MSG:
c->Request.CDBLen = 16;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type, ATTR_SIMPLE, XFER_NONE);
c->Request.Timeout = 0;
memset(&c->Request.CDB[0], 0, sizeof(c->Request.CDB));
c->Request.CDB[0] = cmd;
c->Request.CDB[1] = HPSA_RESET_TYPE_LUN;
c->Request.CDB[4] = 0x00;
c->Request.CDB[5] = 0x00;
c->Request.CDB[6] = 0x00;
c->Request.CDB[7] = 0x00;
break;
case HPSA_ABORT_MSG:
memcpy(&tag, buff, sizeof(tag));
dev_dbg(&h->pdev->dev,
"Abort Tag:0x%016llx using rqst Tag:0x%016llx",
tag, c->Header.tag);
c->Request.CDBLen = 16;
c->Request.type_attr_dir =
TYPE_ATTR_DIR(cmd_type,
ATTR_SIMPLE, XFER_WRITE);
c->Request.Timeout = 0;
c->Request.CDB[0] = HPSA_TASK_MANAGEMENT;
c->Request.CDB[1] = HPSA_TMF_ABORT_TASK;
c->Request.CDB[2] = 0x00;
c->Request.CDB[3] = 0x00;
memcpy(&c->Request.CDB[4], &tag, sizeof(tag));
c->Request.CDB[12] = 0x00;
c->Request.CDB[13] = 0x00;
c->Request.CDB[14] = 0x00;
c->Request.CDB[15] = 0x00;
break;
default:
dev_warn(&h->pdev->dev, "unknown message type %d\n",
cmd);
BUG();
}
} else {
dev_warn(&h->pdev->dev, "unknown command type %d\n", cmd_type);
BUG();
}
switch (GET_DIR(c->Request.type_attr_dir)) {
case XFER_READ:
pci_dir = PCI_DMA_FROMDEVICE;
break;
case XFER_WRITE:
pci_dir = PCI_DMA_TODEVICE;
break;
case XFER_NONE:
pci_dir = PCI_DMA_NONE;
break;
default:
pci_dir = PCI_DMA_BIDIRECTIONAL;
}
if (hpsa_map_one(h->pdev, c, buff, size, pci_dir))
return -1;
return 0;
}
static void __iomem *remap_pci_mem(ulong base, ulong size)
{
ulong page_base = ((ulong) base) & PAGE_MASK;
ulong page_offs = ((ulong) base) - page_base;
void __iomem *page_remapped = ioremap_nocache(page_base,
page_offs + size);
return page_remapped ? (page_remapped + page_offs) : NULL;
}
static inline unsigned long get_next_completion(struct ctlr_info *h, u8 q)
{
return h->access.command_completed(h, q);
}
static inline bool interrupt_pending(struct ctlr_info *h)
{
return h->access.intr_pending(h);
}
static inline long interrupt_not_for_us(struct ctlr_info *h)
{
return (h->access.intr_pending(h) == 0) ||
(h->interrupts_enabled == 0);
}
static inline int bad_tag(struct ctlr_info *h, u32 tag_index,
u32 raw_tag)
{
if (unlikely(tag_index >= h->nr_cmds)) {
dev_warn(&h->pdev->dev, "bad tag 0x%08x ignored.\n", raw_tag);
return 1;
}
return 0;
}
static inline void finish_cmd(struct CommandList *c)
{
dial_up_lockup_detection_on_fw_flash_complete(c->h, c);
if (likely(c->cmd_type == CMD_IOACCEL1 || c->cmd_type == CMD_SCSI
|| c->cmd_type == CMD_IOACCEL2))
complete_scsi_command(c);
else if (c->cmd_type == CMD_IOCTL_PEND || c->cmd_type == IOACCEL2_TMF)
complete(c->waiting);
}
static inline void process_indexed_cmd(struct ctlr_info *h,
u32 raw_tag)
{
u32 tag_index;
struct CommandList *c;
tag_index = raw_tag >> DIRECT_LOOKUP_SHIFT;
if (!bad_tag(h, tag_index, raw_tag)) {
c = h->cmd_pool + tag_index;
finish_cmd(c);
}
}
static int ignore_bogus_interrupt(struct ctlr_info *h)
{
if (likely(!reset_devices))
return 0;
if (likely(h->interrupts_enabled))
return 0;
dev_info(&h->pdev->dev, "Received interrupt while interrupts disabled "
"(known firmware bug.) Ignoring.\n");
return 1;
}
static struct ctlr_info *queue_to_hba(u8 *queue)
{
return container_of((queue - *queue), struct ctlr_info, q[0]);
}
static irqreturn_t hpsa_intx_discard_completions(int irq, void *queue)
{
struct ctlr_info *h = queue_to_hba(queue);
u8 q = *(u8 *) queue;
u32 raw_tag;
if (ignore_bogus_interrupt(h))
return IRQ_NONE;
if (interrupt_not_for_us(h))
return IRQ_NONE;
h->last_intr_timestamp = get_jiffies_64();
while (interrupt_pending(h)) {
raw_tag = get_next_completion(h, q);
while (raw_tag != FIFO_EMPTY)
raw_tag = next_command(h, q);
}
return IRQ_HANDLED;
}
static irqreturn_t hpsa_msix_discard_completions(int irq, void *queue)
{
struct ctlr_info *h = queue_to_hba(queue);
u32 raw_tag;
u8 q = *(u8 *) queue;
if (ignore_bogus_interrupt(h))
return IRQ_NONE;
h->last_intr_timestamp = get_jiffies_64();
raw_tag = get_next_completion(h, q);
while (raw_tag != FIFO_EMPTY)
raw_tag = next_command(h, q);
return IRQ_HANDLED;
}
static irqreturn_t do_hpsa_intr_intx(int irq, void *queue)
{
struct ctlr_info *h = queue_to_hba((u8 *) queue);
u32 raw_tag;
u8 q = *(u8 *) queue;
if (interrupt_not_for_us(h))
return IRQ_NONE;
h->last_intr_timestamp = get_jiffies_64();
while (interrupt_pending(h)) {
raw_tag = get_next_completion(h, q);
while (raw_tag != FIFO_EMPTY) {
process_indexed_cmd(h, raw_tag);
raw_tag = next_command(h, q);
}
}
return IRQ_HANDLED;
}
static irqreturn_t do_hpsa_intr_msi(int irq, void *queue)
{
struct ctlr_info *h = queue_to_hba(queue);
u32 raw_tag;
u8 q = *(u8 *) queue;
h->last_intr_timestamp = get_jiffies_64();
raw_tag = get_next_completion(h, q);
while (raw_tag != FIFO_EMPTY) {
process_indexed_cmd(h, raw_tag);
raw_tag = next_command(h, q);
}
return IRQ_HANDLED;
}
static int hpsa_message(struct pci_dev *pdev, unsigned char opcode,
unsigned char type)
{
struct Command {
struct CommandListHeader CommandHeader;
struct RequestBlock Request;
struct ErrDescriptor ErrorDescriptor;
};
struct Command *cmd;
static const size_t cmd_sz = sizeof(*cmd) +
sizeof(cmd->ErrorDescriptor);
dma_addr_t paddr64;
__le32 paddr32;
u32 tag;
void __iomem *vaddr;
int i, err;
vaddr = pci_ioremap_bar(pdev, 0);
if (vaddr == NULL)
return -ENOMEM;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
iounmap(vaddr);
return err;
}
cmd = pci_alloc_consistent(pdev, cmd_sz, &paddr64);
if (cmd == NULL) {
iounmap(vaddr);
return -ENOMEM;
}
paddr32 = cpu_to_le32(paddr64);
cmd->CommandHeader.ReplyQueue = 0;
cmd->CommandHeader.SGList = 0;
cmd->CommandHeader.SGTotal = cpu_to_le16(0);
cmd->CommandHeader.tag = cpu_to_le64(paddr64);
memset(&cmd->CommandHeader.LUN.LunAddrBytes, 0, 8);
cmd->Request.CDBLen = 16;
cmd->Request.type_attr_dir =
TYPE_ATTR_DIR(TYPE_MSG, ATTR_HEADOFQUEUE, XFER_NONE);
cmd->Request.Timeout = 0;
cmd->Request.CDB[0] = opcode;
cmd->Request.CDB[1] = type;
memset(&cmd->Request.CDB[2], 0, 14);
cmd->ErrorDescriptor.Addr =
cpu_to_le64((le32_to_cpu(paddr32) + sizeof(*cmd)));
cmd->ErrorDescriptor.Len = cpu_to_le32(sizeof(struct ErrorInfo));
writel(le32_to_cpu(paddr32), vaddr + SA5_REQUEST_PORT_OFFSET);
for (i = 0; i < HPSA_MSG_SEND_RETRY_LIMIT; i++) {
tag = readl(vaddr + SA5_REPLY_PORT_OFFSET);
if ((tag & ~HPSA_SIMPLE_ERROR_BITS) == paddr64)
break;
msleep(HPSA_MSG_SEND_RETRY_INTERVAL_MSECS);
}
iounmap(vaddr);
if (i == HPSA_MSG_SEND_RETRY_LIMIT) {
dev_err(&pdev->dev, "controller message %02x:%02x timed out\n",
opcode, type);
return -ETIMEDOUT;
}
pci_free_consistent(pdev, cmd_sz, cmd, paddr64);
if (tag & HPSA_ERROR_BIT) {
dev_err(&pdev->dev, "controller message %02x:%02x failed\n",
opcode, type);
return -EIO;
}
dev_info(&pdev->dev, "controller message %02x:%02x succeeded\n",
opcode, type);
return 0;
}
static int hpsa_controller_hard_reset(struct pci_dev *pdev,
void __iomem *vaddr, u32 use_doorbell)
{
if (use_doorbell) {
dev_info(&pdev->dev, "using doorbell to reset controller\n");
writel(use_doorbell, vaddr + SA5_DOORBELL);
msleep(10000);
} else {
int rc = 0;
dev_info(&pdev->dev, "using PCI PM to reset controller\n");
rc = pci_set_power_state(pdev, PCI_D3hot);
if (rc)
return rc;
msleep(500);
rc = pci_set_power_state(pdev, PCI_D0);
if (rc)
return rc;
msleep(500);
}
return 0;
}
static void init_driver_version(char *driver_version, int len)
{
memset(driver_version, 0, len);
strncpy(driver_version, HPSA " " HPSA_DRIVER_VERSION, len - 1);
}
static int write_driver_ver_to_cfgtable(struct CfgTable __iomem *cfgtable)
{
char *driver_version;
int i, size = sizeof(cfgtable->driver_version);
driver_version = kmalloc(size, GFP_KERNEL);
if (!driver_version)
return -ENOMEM;
init_driver_version(driver_version, size);
for (i = 0; i < size; i++)
writeb(driver_version[i], &cfgtable->driver_version[i]);
kfree(driver_version);
return 0;
}
static void read_driver_ver_from_cfgtable(struct CfgTable __iomem *cfgtable,
unsigned char *driver_ver)
{
int i;
for (i = 0; i < sizeof(cfgtable->driver_version); i++)
driver_ver[i] = readb(&cfgtable->driver_version[i]);
}
static int controller_reset_failed(struct CfgTable __iomem *cfgtable)
{
char *driver_ver, *old_driver_ver;
int rc, size = sizeof(cfgtable->driver_version);
old_driver_ver = kmalloc(2 * size, GFP_KERNEL);
if (!old_driver_ver)
return -ENOMEM;
driver_ver = old_driver_ver + size;
init_driver_version(old_driver_ver, size);
read_driver_ver_from_cfgtable(cfgtable, driver_ver);
rc = !memcmp(driver_ver, old_driver_ver, size);
kfree(old_driver_ver);
return rc;
}
static int hpsa_kdump_hard_reset_controller(struct pci_dev *pdev, u32 board_id)
{
u64 cfg_offset;
u32 cfg_base_addr;
u64 cfg_base_addr_index;
void __iomem *vaddr;
unsigned long paddr;
u32 misc_fw_support;
int rc;
struct CfgTable __iomem *cfgtable;
u32 use_doorbell;
u16 command_register;
if (!ctlr_is_resettable(board_id)) {
dev_warn(&pdev->dev, "Controller not resettable\n");
return -ENODEV;
}
if (!ctlr_is_hard_resettable(board_id))
return -ENOTSUPP;
pci_read_config_word(pdev, 4, &command_register);
pci_save_state(pdev);
rc = hpsa_pci_find_memory_BAR(pdev, &paddr);
if (rc)
return rc;
vaddr = remap_pci_mem(paddr, 0x250);
if (!vaddr)
return -ENOMEM;
rc = hpsa_find_cfg_addrs(pdev, vaddr, &cfg_base_addr,
&cfg_base_addr_index, &cfg_offset);
if (rc)
goto unmap_vaddr;
cfgtable = remap_pci_mem(pci_resource_start(pdev,
cfg_base_addr_index) + cfg_offset, sizeof(*cfgtable));
if (!cfgtable) {
rc = -ENOMEM;
goto unmap_vaddr;
}
rc = write_driver_ver_to_cfgtable(cfgtable);
if (rc)
goto unmap_cfgtable;
misc_fw_support = readl(&cfgtable->misc_fw_support);
use_doorbell = misc_fw_support & MISC_FW_DOORBELL_RESET2;
if (use_doorbell) {
use_doorbell = DOORBELL_CTLR_RESET2;
} else {
use_doorbell = misc_fw_support & MISC_FW_DOORBELL_RESET;
if (use_doorbell) {
dev_warn(&pdev->dev,
"Soft reset not supported. Firmware update is required.\n");
rc = -ENOTSUPP;
goto unmap_cfgtable;
}
}
rc = hpsa_controller_hard_reset(pdev, vaddr, use_doorbell);
if (rc)
goto unmap_cfgtable;
pci_restore_state(pdev);
pci_write_config_word(pdev, 4, command_register);
msleep(HPSA_POST_RESET_PAUSE_MSECS);
rc = hpsa_wait_for_board_state(pdev, vaddr, BOARD_READY);
if (rc) {
dev_warn(&pdev->dev,
"Failed waiting for board to become ready after hard reset\n");
goto unmap_cfgtable;
}
rc = controller_reset_failed(vaddr);
if (rc < 0)
goto unmap_cfgtable;
if (rc) {
dev_warn(&pdev->dev, "Unable to successfully reset "
"controller. Will try soft reset.\n");
rc = -ENOTSUPP;
} else {
dev_info(&pdev->dev, "board ready after hard reset.\n");
}
unmap_cfgtable:
iounmap(cfgtable);
unmap_vaddr:
iounmap(vaddr);
return rc;
}
static void print_cfg_table(struct device *dev, struct CfgTable __iomem *tb)
{
#ifdef HPSA_DEBUG
int i;
char temp_name[17];
dev_info(dev, "Controller Configuration information\n");
dev_info(dev, "------------------------------------\n");
for (i = 0; i < 4; i++)
temp_name[i] = readb(&(tb->Signature[i]));
temp_name[4] = '\0';
dev_info(dev, " Signature = %s\n", temp_name);
dev_info(dev, " Spec Number = %d\n", readl(&(tb->SpecValence)));
dev_info(dev, " Transport methods supported = 0x%x\n",
readl(&(tb->TransportSupport)));
dev_info(dev, " Transport methods active = 0x%x\n",
readl(&(tb->TransportActive)));
dev_info(dev, " Requested transport Method = 0x%x\n",
readl(&(tb->HostWrite.TransportRequest)));
dev_info(dev, " Coalesce Interrupt Delay = 0x%x\n",
readl(&(tb->HostWrite.CoalIntDelay)));
dev_info(dev, " Coalesce Interrupt Count = 0x%x\n",
readl(&(tb->HostWrite.CoalIntCount)));
dev_info(dev, " Max outstanding commands = %d\n",
readl(&(tb->CmdsOutMax)));
dev_info(dev, " Bus Types = 0x%x\n", readl(&(tb->BusTypes)));
for (i = 0; i < 16; i++)
temp_name[i] = readb(&(tb->ServerName[i]));
temp_name[16] = '\0';
dev_info(dev, " Server Name = %s\n", temp_name);
dev_info(dev, " Heartbeat Counter = 0x%x\n\n\n",
readl(&(tb->HeartBeat)));
#endif
}
static int find_PCI_BAR_index(struct pci_dev *pdev, unsigned long pci_bar_addr)
{
int i, offset, mem_type, bar_type;
if (pci_bar_addr == PCI_BASE_ADDRESS_0)
return 0;
offset = 0;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
bar_type = pci_resource_flags(pdev, i) & PCI_BASE_ADDRESS_SPACE;
if (bar_type == PCI_BASE_ADDRESS_SPACE_IO)
offset += 4;
else {
mem_type = pci_resource_flags(pdev, i) &
PCI_BASE_ADDRESS_MEM_TYPE_MASK;
switch (mem_type) {
case PCI_BASE_ADDRESS_MEM_TYPE_32:
case PCI_BASE_ADDRESS_MEM_TYPE_1M:
offset += 4;
break;
case PCI_BASE_ADDRESS_MEM_TYPE_64:
offset += 8;
break;
default:
dev_warn(&pdev->dev,
"base address is invalid\n");
return -1;
break;
}
}
if (offset == pci_bar_addr - PCI_BASE_ADDRESS_0)
return i + 1;
}
return -1;
}
static void hpsa_disable_interrupt_mode(struct ctlr_info *h)
{
if (h->msix_vector) {
if (h->pdev->msix_enabled)
pci_disable_msix(h->pdev);
h->msix_vector = 0;
} else if (h->msi_vector) {
if (h->pdev->msi_enabled)
pci_disable_msi(h->pdev);
h->msi_vector = 0;
}
}
static void hpsa_interrupt_mode(struct ctlr_info *h)
{
#ifdef CONFIG_PCI_MSI
int err, i;
struct msix_entry hpsa_msix_entries[MAX_REPLY_QUEUES];
for (i = 0; i < MAX_REPLY_QUEUES; i++) {
hpsa_msix_entries[i].vector = 0;
hpsa_msix_entries[i].entry = i;
}
if ((h->board_id == 0x40700E11) || (h->board_id == 0x40800E11) ||
(h->board_id == 0x40820E11) || (h->board_id == 0x40830E11))
goto default_int_mode;
if (pci_find_capability(h->pdev, PCI_CAP_ID_MSIX)) {
dev_info(&h->pdev->dev, "MSI-X capable controller\n");
h->msix_vector = MAX_REPLY_QUEUES;
if (h->msix_vector > num_online_cpus())
h->msix_vector = num_online_cpus();
err = pci_enable_msix_range(h->pdev, hpsa_msix_entries,
1, h->msix_vector);
if (err < 0) {
dev_warn(&h->pdev->dev, "MSI-X init failed %d\n", err);
h->msix_vector = 0;
goto single_msi_mode;
} else if (err < h->msix_vector) {
dev_warn(&h->pdev->dev, "only %d MSI-X vectors "
"available\n", err);
}
h->msix_vector = err;
for (i = 0; i < h->msix_vector; i++)
h->intr[i] = hpsa_msix_entries[i].vector;
return;
}
single_msi_mode:
if (pci_find_capability(h->pdev, PCI_CAP_ID_MSI)) {
dev_info(&h->pdev->dev, "MSI capable controller\n");
if (!pci_enable_msi(h->pdev))
h->msi_vector = 1;
else
dev_warn(&h->pdev->dev, "MSI init failed\n");
}
default_int_mode:
#endif
h->intr[h->intr_mode] = h->pdev->irq;
}
static int hpsa_lookup_board_id(struct pci_dev *pdev, u32 *board_id)
{
int i;
u32 subsystem_vendor_id, subsystem_device_id;
subsystem_vendor_id = pdev->subsystem_vendor;
subsystem_device_id = pdev->subsystem_device;
*board_id = ((subsystem_device_id << 16) & 0xffff0000) |
subsystem_vendor_id;
for (i = 0; i < ARRAY_SIZE(products); i++)
if (*board_id == products[i].board_id)
return i;
if ((subsystem_vendor_id != PCI_VENDOR_ID_HP &&
subsystem_vendor_id != PCI_VENDOR_ID_COMPAQ) ||
!hpsa_allow_any) {
dev_warn(&pdev->dev, "unrecognized board ID: "
"0x%08x, ignoring.\n", *board_id);
return -ENODEV;
}
return ARRAY_SIZE(products) - 1;
}
static int hpsa_pci_find_memory_BAR(struct pci_dev *pdev,
unsigned long *memory_bar)
{
int i;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++)
if (pci_resource_flags(pdev, i) & IORESOURCE_MEM) {
*memory_bar = pci_resource_start(pdev, i);
dev_dbg(&pdev->dev, "memory BAR = %lx\n",
*memory_bar);
return 0;
}
dev_warn(&pdev->dev, "no memory BAR found\n");
return -ENODEV;
}
static int hpsa_wait_for_board_state(struct pci_dev *pdev, void __iomem *vaddr,
int wait_for_ready)
{
int i, iterations;
u32 scratchpad;
if (wait_for_ready)
iterations = HPSA_BOARD_READY_ITERATIONS;
else
iterations = HPSA_BOARD_NOT_READY_ITERATIONS;
for (i = 0; i < iterations; i++) {
scratchpad = readl(vaddr + SA5_SCRATCHPAD_OFFSET);
if (wait_for_ready) {
if (scratchpad == HPSA_FIRMWARE_READY)
return 0;
} else {
if (scratchpad != HPSA_FIRMWARE_READY)
return 0;
}
msleep(HPSA_BOARD_READY_POLL_INTERVAL_MSECS);
}
dev_warn(&pdev->dev, "board not ready, timed out.\n");
return -ENODEV;
}
static int hpsa_find_cfg_addrs(struct pci_dev *pdev, void __iomem *vaddr,
u32 *cfg_base_addr, u64 *cfg_base_addr_index,
u64 *cfg_offset)
{
*cfg_base_addr = readl(vaddr + SA5_CTCFG_OFFSET);
*cfg_offset = readl(vaddr + SA5_CTMEM_OFFSET);
*cfg_base_addr &= (u32) 0x0000ffff;
*cfg_base_addr_index = find_PCI_BAR_index(pdev, *cfg_base_addr);
if (*cfg_base_addr_index == -1) {
dev_warn(&pdev->dev, "cannot find cfg_base_addr_index\n");
return -ENODEV;
}
return 0;
}
static void hpsa_free_cfgtables(struct ctlr_info *h)
{
if (h->transtable) {
iounmap(h->transtable);
h->transtable = NULL;
}
if (h->cfgtable) {
iounmap(h->cfgtable);
h->cfgtable = NULL;
}
}
static int hpsa_find_cfgtables(struct ctlr_info *h)
{
u64 cfg_offset;
u32 cfg_base_addr;
u64 cfg_base_addr_index;
u32 trans_offset;
int rc;
rc = hpsa_find_cfg_addrs(h->pdev, h->vaddr, &cfg_base_addr,
&cfg_base_addr_index, &cfg_offset);
if (rc)
return rc;
h->cfgtable = remap_pci_mem(pci_resource_start(h->pdev,
cfg_base_addr_index) + cfg_offset, sizeof(*h->cfgtable));
if (!h->cfgtable) {
dev_err(&h->pdev->dev, "Failed mapping cfgtable\n");
return -ENOMEM;
}
rc = write_driver_ver_to_cfgtable(h->cfgtable);
if (rc)
return rc;
trans_offset = readl(&h->cfgtable->TransMethodOffset);
h->transtable = remap_pci_mem(pci_resource_start(h->pdev,
cfg_base_addr_index)+cfg_offset+trans_offset,
sizeof(*h->transtable));
if (!h->transtable) {
dev_err(&h->pdev->dev, "Failed mapping transfer table\n");
hpsa_free_cfgtables(h);
return -ENOMEM;
}
return 0;
}
static void hpsa_get_max_perf_mode_cmds(struct ctlr_info *h)
{
#define MIN_MAX_COMMANDS 16
BUILD_BUG_ON(MIN_MAX_COMMANDS <= HPSA_NRESERVED_CMDS);
h->max_commands = readl(&h->cfgtable->MaxPerformantModeCommands);
if (reset_devices && h->max_commands > 32)
h->max_commands = 32;
if (h->max_commands < MIN_MAX_COMMANDS) {
dev_warn(&h->pdev->dev,
"Controller reports max supported commands of %d Using %d instead. Ensure that firmware is up to date.\n",
h->max_commands,
MIN_MAX_COMMANDS);
h->max_commands = MIN_MAX_COMMANDS;
}
}
static int hpsa_supports_chained_sg_blocks(struct ctlr_info *h)
{
return h->maxsgentries > 512;
}
static void hpsa_find_board_params(struct ctlr_info *h)
{
hpsa_get_max_perf_mode_cmds(h);
h->nr_cmds = h->max_commands;
h->maxsgentries = readl(&(h->cfgtable->MaxScatterGatherElements));
h->fw_support = readl(&(h->cfgtable->misc_fw_support));
if (hpsa_supports_chained_sg_blocks(h)) {
h->max_cmd_sg_entries = 32;
h->chainsize = h->maxsgentries - h->max_cmd_sg_entries;
h->maxsgentries--;
} else {
h->max_cmd_sg_entries = 31;
h->maxsgentries = 31;
h->chainsize = 0;
}
h->TMFSupportFlags = readl(&(h->cfgtable->TMFSupportFlags));
if (!(HPSATMF_PHYS_TASK_ABORT & h->TMFSupportFlags))
dev_warn(&h->pdev->dev, "Physical aborts not supported\n");
if (!(HPSATMF_LOG_TASK_ABORT & h->TMFSupportFlags))
dev_warn(&h->pdev->dev, "Logical aborts not supported\n");
if (!(HPSATMF_IOACCEL_ENABLED & h->TMFSupportFlags))
dev_warn(&h->pdev->dev, "HP SSD Smart Path aborts not supported\n");
}
static inline bool hpsa_CISS_signature_present(struct ctlr_info *h)
{
if (!check_signature(h->cfgtable->Signature, "CISS", 4)) {
dev_err(&h->pdev->dev, "not a valid CISS config table\n");
return false;
}
return true;
}
static inline void hpsa_set_driver_support_bits(struct ctlr_info *h)
{
u32 driver_support;
driver_support = readl(&(h->cfgtable->driver_support));
#ifdef CONFIG_X86
driver_support |= ENABLE_SCSI_PREFETCH;
#endif
driver_support |= ENABLE_UNIT_ATTN;
writel(driver_support, &(h->cfgtable->driver_support));
}
static inline void hpsa_p600_dma_prefetch_quirk(struct ctlr_info *h)
{
u32 dma_prefetch;
if (h->board_id != 0x3225103C)
return;
dma_prefetch = readl(h->vaddr + I2O_DMA1_CFG);
dma_prefetch |= 0x8000;
writel(dma_prefetch, h->vaddr + I2O_DMA1_CFG);
}
static int hpsa_wait_for_clear_event_notify_ack(struct ctlr_info *h)
{
int i;
u32 doorbell_value;
unsigned long flags;
for (i = 0; i < MAX_CLEAR_EVENT_WAIT; i++) {
spin_lock_irqsave(&h->lock, flags);
doorbell_value = readl(h->vaddr + SA5_DOORBELL);
spin_unlock_irqrestore(&h->lock, flags);
if (!(doorbell_value & DOORBELL_CLEAR_EVENTS))
goto done;
msleep(CLEAR_EVENT_WAIT_INTERVAL);
}
return -ENODEV;
done:
return 0;
}
static int hpsa_wait_for_mode_change_ack(struct ctlr_info *h)
{
int i;
u32 doorbell_value;
unsigned long flags;
for (i = 0; i < MAX_MODE_CHANGE_WAIT; i++) {
if (h->remove_in_progress)
goto done;
spin_lock_irqsave(&h->lock, flags);
doorbell_value = readl(h->vaddr + SA5_DOORBELL);
spin_unlock_irqrestore(&h->lock, flags);
if (!(doorbell_value & CFGTBL_ChangeReq))
goto done;
msleep(MODE_CHANGE_WAIT_INTERVAL);
}
return -ENODEV;
done:
return 0;
}
static int hpsa_enter_simple_mode(struct ctlr_info *h)
{
u32 trans_support;
trans_support = readl(&(h->cfgtable->TransportSupport));
if (!(trans_support & SIMPLE_MODE))
return -ENOTSUPP;
h->max_commands = readl(&(h->cfgtable->CmdsOutMax));
writel(CFGTBL_Trans_Simple, &(h->cfgtable->HostWrite.TransportRequest));
writel(0, &h->cfgtable->HostWrite.command_pool_addr_hi);
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
if (hpsa_wait_for_mode_change_ack(h))
goto error;
print_cfg_table(&h->pdev->dev, h->cfgtable);
if (!(readl(&(h->cfgtable->TransportActive)) & CFGTBL_Trans_Simple))
goto error;
h->transMethod = CFGTBL_Trans_Simple;
return 0;
error:
dev_err(&h->pdev->dev, "failed to enter simple mode\n");
return -ENODEV;
}
static void hpsa_free_pci_init(struct ctlr_info *h)
{
hpsa_free_cfgtables(h);
iounmap(h->vaddr);
h->vaddr = NULL;
hpsa_disable_interrupt_mode(h);
pci_disable_device(h->pdev);
pci_release_regions(h->pdev);
}
static int hpsa_pci_init(struct ctlr_info *h)
{
int prod_index, err;
prod_index = hpsa_lookup_board_id(h->pdev, &h->board_id);
if (prod_index < 0)
return prod_index;
h->product_name = products[prod_index].product_name;
h->access = *(products[prod_index].access);
h->needs_abort_tags_swizzled =
ctlr_needs_abort_tags_swizzled(h->board_id);
pci_disable_link_state(h->pdev, PCIE_LINK_STATE_L0S |
PCIE_LINK_STATE_L1 | PCIE_LINK_STATE_CLKPM);
err = pci_enable_device(h->pdev);
if (err) {
dev_err(&h->pdev->dev, "failed to enable PCI device\n");
pci_disable_device(h->pdev);
return err;
}
err = pci_request_regions(h->pdev, HPSA);
if (err) {
dev_err(&h->pdev->dev,
"failed to obtain PCI resources\n");
pci_disable_device(h->pdev);
return err;
}
pci_set_master(h->pdev);
hpsa_interrupt_mode(h);
err = hpsa_pci_find_memory_BAR(h->pdev, &h->paddr);
if (err)
goto clean2;
h->vaddr = remap_pci_mem(h->paddr, 0x250);
if (!h->vaddr) {
dev_err(&h->pdev->dev, "failed to remap PCI mem\n");
err = -ENOMEM;
goto clean2;
}
err = hpsa_wait_for_board_state(h->pdev, h->vaddr, BOARD_READY);
if (err)
goto clean3;
err = hpsa_find_cfgtables(h);
if (err)
goto clean3;
hpsa_find_board_params(h);
if (!hpsa_CISS_signature_present(h)) {
err = -ENODEV;
goto clean4;
}
hpsa_set_driver_support_bits(h);
hpsa_p600_dma_prefetch_quirk(h);
err = hpsa_enter_simple_mode(h);
if (err)
goto clean4;
return 0;
clean4:
hpsa_free_cfgtables(h);
clean3:
iounmap(h->vaddr);
h->vaddr = NULL;
clean2:
hpsa_disable_interrupt_mode(h);
pci_disable_device(h->pdev);
pci_release_regions(h->pdev);
return err;
}
static void hpsa_hba_inquiry(struct ctlr_info *h)
{
int rc;
#define HBA_INQUIRY_BYTE_COUNT 64
h->hba_inquiry_data = kmalloc(HBA_INQUIRY_BYTE_COUNT, GFP_KERNEL);
if (!h->hba_inquiry_data)
return;
rc = hpsa_scsi_do_inquiry(h, RAID_CTLR_LUNID, 0,
h->hba_inquiry_data, HBA_INQUIRY_BYTE_COUNT);
if (rc != 0) {
kfree(h->hba_inquiry_data);
h->hba_inquiry_data = NULL;
}
}
static int hpsa_init_reset_devices(struct pci_dev *pdev, u32 board_id)
{
int rc, i;
void __iomem *vaddr;
if (!reset_devices)
return 0;
rc = pci_enable_device(pdev);
if (rc) {
dev_warn(&pdev->dev, "Failed to enable PCI device\n");
return -ENODEV;
}
pci_disable_device(pdev);
msleep(260);
rc = pci_enable_device(pdev);
if (rc) {
dev_warn(&pdev->dev, "failed to enable device.\n");
return -ENODEV;
}
pci_set_master(pdev);
vaddr = pci_ioremap_bar(pdev, 0);
if (vaddr == NULL) {
rc = -ENOMEM;
goto out_disable;
}
writel(SA5_INTR_OFF, vaddr + SA5_REPLY_INTR_MASK_OFFSET);
iounmap(vaddr);
rc = hpsa_kdump_hard_reset_controller(pdev, board_id);
if (rc)
goto out_disable;
dev_info(&pdev->dev, "Waiting for controller to respond to no-op\n");
for (i = 0; i < HPSA_POST_RESET_NOOP_RETRIES; i++) {
if (hpsa_noop(pdev) == 0)
break;
else
dev_warn(&pdev->dev, "no-op failed%s\n",
(i < 11 ? "; re-trying" : ""));
}
out_disable:
pci_disable_device(pdev);
return rc;
}
static void hpsa_free_cmd_pool(struct ctlr_info *h)
{
kfree(h->cmd_pool_bits);
h->cmd_pool_bits = NULL;
if (h->cmd_pool) {
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct CommandList),
h->cmd_pool,
h->cmd_pool_dhandle);
h->cmd_pool = NULL;
h->cmd_pool_dhandle = 0;
}
if (h->errinfo_pool) {
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct ErrorInfo),
h->errinfo_pool,
h->errinfo_pool_dhandle);
h->errinfo_pool = NULL;
h->errinfo_pool_dhandle = 0;
}
}
static int hpsa_alloc_cmd_pool(struct ctlr_info *h)
{
h->cmd_pool_bits = kzalloc(
DIV_ROUND_UP(h->nr_cmds, BITS_PER_LONG) *
sizeof(unsigned long), GFP_KERNEL);
h->cmd_pool = pci_alloc_consistent(h->pdev,
h->nr_cmds * sizeof(*h->cmd_pool),
&(h->cmd_pool_dhandle));
h->errinfo_pool = pci_alloc_consistent(h->pdev,
h->nr_cmds * sizeof(*h->errinfo_pool),
&(h->errinfo_pool_dhandle));
if ((h->cmd_pool_bits == NULL)
|| (h->cmd_pool == NULL)
|| (h->errinfo_pool == NULL)) {
dev_err(&h->pdev->dev, "out of memory in %s", __func__);
goto clean_up;
}
hpsa_preinitialize_commands(h);
return 0;
clean_up:
hpsa_free_cmd_pool(h);
return -ENOMEM;
}
static void hpsa_irq_affinity_hints(struct ctlr_info *h)
{
int i, cpu;
cpu = cpumask_first(cpu_online_mask);
for (i = 0; i < h->msix_vector; i++) {
irq_set_affinity_hint(h->intr[i], get_cpu_mask(cpu));
cpu = cpumask_next(cpu, cpu_online_mask);
}
}
static void hpsa_free_irqs(struct ctlr_info *h)
{
int i;
if (!h->msix_vector || h->intr_mode != PERF_MODE_INT) {
i = h->intr_mode;
irq_set_affinity_hint(h->intr[i], NULL);
free_irq(h->intr[i], &h->q[i]);
h->q[i] = 0;
return;
}
for (i = 0; i < h->msix_vector; i++) {
irq_set_affinity_hint(h->intr[i], NULL);
free_irq(h->intr[i], &h->q[i]);
h->q[i] = 0;
}
for (; i < MAX_REPLY_QUEUES; i++)
h->q[i] = 0;
}
static int hpsa_request_irqs(struct ctlr_info *h,
irqreturn_t (*msixhandler)(int, void *),
irqreturn_t (*intxhandler)(int, void *))
{
int rc, i;
for (i = 0; i < MAX_REPLY_QUEUES; i++)
h->q[i] = (u8) i;
if (h->intr_mode == PERF_MODE_INT && h->msix_vector > 0) {
for (i = 0; i < h->msix_vector; i++) {
sprintf(h->intrname[i], "%s-msix%d", h->devname, i);
rc = request_irq(h->intr[i], msixhandler,
0, h->intrname[i],
&h->q[i]);
if (rc) {
int j;
dev_err(&h->pdev->dev,
"failed to get irq %d for %s\n",
h->intr[i], h->devname);
for (j = 0; j < i; j++) {
free_irq(h->intr[j], &h->q[j]);
h->q[j] = 0;
}
for (; j < MAX_REPLY_QUEUES; j++)
h->q[j] = 0;
return rc;
}
}
hpsa_irq_affinity_hints(h);
} else {
if (h->msix_vector > 0 || h->msi_vector) {
if (h->msix_vector)
sprintf(h->intrname[h->intr_mode],
"%s-msix", h->devname);
else
sprintf(h->intrname[h->intr_mode],
"%s-msi", h->devname);
rc = request_irq(h->intr[h->intr_mode],
msixhandler, 0,
h->intrname[h->intr_mode],
&h->q[h->intr_mode]);
} else {
sprintf(h->intrname[h->intr_mode],
"%s-intx", h->devname);
rc = request_irq(h->intr[h->intr_mode],
intxhandler, IRQF_SHARED,
h->intrname[h->intr_mode],
&h->q[h->intr_mode]);
}
irq_set_affinity_hint(h->intr[h->intr_mode], NULL);
}
if (rc) {
dev_err(&h->pdev->dev, "failed to get irq %d for %s\n",
h->intr[h->intr_mode], h->devname);
hpsa_free_irqs(h);
return -ENODEV;
}
return 0;
}
static int hpsa_kdump_soft_reset(struct ctlr_info *h)
{
int rc;
hpsa_send_host_reset(h, RAID_CTLR_LUNID, HPSA_RESET_TYPE_CONTROLLER);
dev_info(&h->pdev->dev, "Waiting for board to soft reset.\n");
rc = hpsa_wait_for_board_state(h->pdev, h->vaddr, BOARD_NOT_READY);
if (rc) {
dev_warn(&h->pdev->dev, "Soft reset had no effect.\n");
return rc;
}
dev_info(&h->pdev->dev, "Board reset, awaiting READY status.\n");
rc = hpsa_wait_for_board_state(h->pdev, h->vaddr, BOARD_READY);
if (rc) {
dev_warn(&h->pdev->dev, "Board failed to become ready "
"after soft reset.\n");
return rc;
}
return 0;
}
static void hpsa_free_reply_queues(struct ctlr_info *h)
{
int i;
for (i = 0; i < h->nreply_queues; i++) {
if (!h->reply_queue[i].head)
continue;
pci_free_consistent(h->pdev,
h->reply_queue_size,
h->reply_queue[i].head,
h->reply_queue[i].busaddr);
h->reply_queue[i].head = NULL;
h->reply_queue[i].busaddr = 0;
}
h->reply_queue_size = 0;
}
static void hpsa_undo_allocations_after_kdump_soft_reset(struct ctlr_info *h)
{
hpsa_free_performant_mode(h);
hpsa_free_sg_chain_blocks(h);
hpsa_free_cmd_pool(h);
hpsa_free_irqs(h);
scsi_host_put(h->scsi_host);
h->scsi_host = NULL;
hpsa_free_pci_init(h);
free_percpu(h->lockup_detected);
h->lockup_detected = NULL;
if (h->resubmit_wq) {
destroy_workqueue(h->resubmit_wq);
h->resubmit_wq = NULL;
}
if (h->rescan_ctlr_wq) {
destroy_workqueue(h->rescan_ctlr_wq);
h->rescan_ctlr_wq = NULL;
}
kfree(h);
}
static void fail_all_outstanding_cmds(struct ctlr_info *h)
{
int i, refcount;
struct CommandList *c;
int failcount = 0;
flush_workqueue(h->resubmit_wq);
for (i = 0; i < h->nr_cmds; i++) {
c = h->cmd_pool + i;
refcount = atomic_inc_return(&c->refcount);
if (refcount > 1) {
c->err_info->CommandStatus = CMD_CTLR_LOCKUP;
finish_cmd(c);
atomic_dec(&h->commands_outstanding);
failcount++;
}
cmd_free(h, c);
}
dev_warn(&h->pdev->dev,
"failed %d commands in fail_all\n", failcount);
}
static void set_lockup_detected_for_all_cpus(struct ctlr_info *h, u32 value)
{
int cpu;
for_each_online_cpu(cpu) {
u32 *lockup_detected;
lockup_detected = per_cpu_ptr(h->lockup_detected, cpu);
*lockup_detected = value;
}
wmb();
}
static void controller_lockup_detected(struct ctlr_info *h)
{
unsigned long flags;
u32 lockup_detected;
h->access.set_intr_mask(h, HPSA_INTR_OFF);
spin_lock_irqsave(&h->lock, flags);
lockup_detected = readl(h->vaddr + SA5_SCRATCHPAD_OFFSET);
if (!lockup_detected) {
dev_warn(&h->pdev->dev,
"lockup detected after %d but scratchpad register is zero\n",
h->heartbeat_sample_interval / HZ);
lockup_detected = 0xffffffff;
}
set_lockup_detected_for_all_cpus(h, lockup_detected);
spin_unlock_irqrestore(&h->lock, flags);
dev_warn(&h->pdev->dev, "Controller lockup detected: 0x%08x after %d\n",
lockup_detected, h->heartbeat_sample_interval / HZ);
pci_disable_device(h->pdev);
fail_all_outstanding_cmds(h);
}
static int detect_controller_lockup(struct ctlr_info *h)
{
u64 now;
u32 heartbeat;
unsigned long flags;
now = get_jiffies_64();
if (time_after64(h->last_intr_timestamp +
(h->heartbeat_sample_interval), now))
return false;
if (time_after64(h->last_heartbeat_timestamp +
(h->heartbeat_sample_interval), now))
return false;
spin_lock_irqsave(&h->lock, flags);
heartbeat = readl(&h->cfgtable->HeartBeat);
spin_unlock_irqrestore(&h->lock, flags);
if (h->last_heartbeat == heartbeat) {
controller_lockup_detected(h);
return true;
}
h->last_heartbeat = heartbeat;
h->last_heartbeat_timestamp = now;
return false;
}
static void hpsa_ack_ctlr_events(struct ctlr_info *h)
{
int i;
char *event_type;
if (!(h->fw_support & MISC_FW_EVENT_NOTIFY))
return;
if ((h->transMethod & (CFGTBL_Trans_io_accel1
| CFGTBL_Trans_io_accel2)) &&
(h->events & HPSA_EVENT_NOTIFY_ACCEL_IO_PATH_STATE_CHANGE ||
h->events & HPSA_EVENT_NOTIFY_ACCEL_IO_PATH_CONFIG_CHANGE)) {
if (h->events & HPSA_EVENT_NOTIFY_ACCEL_IO_PATH_STATE_CHANGE)
event_type = "state change";
if (h->events & HPSA_EVENT_NOTIFY_ACCEL_IO_PATH_CONFIG_CHANGE)
event_type = "configuration change";
scsi_block_requests(h->scsi_host);
for (i = 0; i < h->ndevices; i++)
h->dev[i]->offload_enabled = 0;
hpsa_drain_accel_commands(h);
dev_warn(&h->pdev->dev,
"Acknowledging event: 0x%08x (HP SSD Smart Path %s)\n",
h->events, event_type);
writel(h->events, &(h->cfgtable->clear_event_notify));
writel(DOORBELL_CLEAR_EVENTS, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_clear_event_notify_ack(h);
scsi_unblock_requests(h->scsi_host);
} else {
writel(h->events, &(h->cfgtable->clear_event_notify));
writel(DOORBELL_CLEAR_EVENTS, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_clear_event_notify_ack(h);
#if 0
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
hpsa_wait_for_mode_change_ack(h);
#endif
}
return;
}
static int hpsa_ctlr_needs_rescan(struct ctlr_info *h)
{
if (h->drv_req_rescan) {
h->drv_req_rescan = 0;
return 1;
}
if (!(h->fw_support & MISC_FW_EVENT_NOTIFY))
return 0;
h->events = readl(&(h->cfgtable->event_notify));
return h->events & RESCAN_REQUIRED_EVENT_BITS;
}
static int hpsa_offline_devices_ready(struct ctlr_info *h)
{
unsigned long flags;
struct offline_device_entry *d;
struct list_head *this, *tmp;
spin_lock_irqsave(&h->offline_device_lock, flags);
list_for_each_safe(this, tmp, &h->offline_device_list) {
d = list_entry(this, struct offline_device_entry,
offline_list);
spin_unlock_irqrestore(&h->offline_device_lock, flags);
if (!hpsa_volume_offline(h, d->scsi3addr)) {
spin_lock_irqsave(&h->offline_device_lock, flags);
list_del(&d->offline_list);
spin_unlock_irqrestore(&h->offline_device_lock, flags);
return 1;
}
spin_lock_irqsave(&h->offline_device_lock, flags);
}
spin_unlock_irqrestore(&h->offline_device_lock, flags);
return 0;
}
static int hpsa_luns_changed(struct ctlr_info *h)
{
int rc = 1;
struct ReportLUNdata *logdev = NULL;
if (!h->lastlogicals)
goto out;
logdev = kzalloc(sizeof(*logdev), GFP_KERNEL);
if (!logdev) {
dev_warn(&h->pdev->dev,
"Out of memory, can't track lun changes.\n");
goto out;
}
if (hpsa_scsi_do_report_luns(h, 1, logdev, sizeof(*logdev), 0)) {
dev_warn(&h->pdev->dev,
"report luns failed, can't track lun changes.\n");
goto out;
}
if (memcmp(logdev, h->lastlogicals, sizeof(*logdev))) {
dev_info(&h->pdev->dev,
"Lun changes detected.\n");
memcpy(h->lastlogicals, logdev, sizeof(*logdev));
goto out;
} else
rc = 0;
out:
kfree(logdev);
return rc;
}
static void hpsa_rescan_ctlr_worker(struct work_struct *work)
{
unsigned long flags;
struct ctlr_info *h = container_of(to_delayed_work(work),
struct ctlr_info, rescan_ctlr_work);
if (h->remove_in_progress)
return;
if (hpsa_ctlr_needs_rescan(h) || hpsa_offline_devices_ready(h)) {
scsi_host_get(h->scsi_host);
hpsa_ack_ctlr_events(h);
hpsa_scan_start(h->scsi_host);
scsi_host_put(h->scsi_host);
} else if (h->discovery_polling) {
hpsa_disable_rld_caching(h);
if (hpsa_luns_changed(h)) {
struct Scsi_Host *sh = NULL;
dev_info(&h->pdev->dev,
"driver discovery polling rescan.\n");
sh = scsi_host_get(h->scsi_host);
if (sh != NULL) {
hpsa_scan_start(sh);
scsi_host_put(sh);
}
}
}
spin_lock_irqsave(&h->lock, flags);
if (!h->remove_in_progress)
queue_delayed_work(h->rescan_ctlr_wq, &h->rescan_ctlr_work,
h->heartbeat_sample_interval);
spin_unlock_irqrestore(&h->lock, flags);
}
static void hpsa_monitor_ctlr_worker(struct work_struct *work)
{
unsigned long flags;
struct ctlr_info *h = container_of(to_delayed_work(work),
struct ctlr_info, monitor_ctlr_work);
detect_controller_lockup(h);
if (lockup_detected(h))
return;
spin_lock_irqsave(&h->lock, flags);
if (!h->remove_in_progress)
schedule_delayed_work(&h->monitor_ctlr_work,
h->heartbeat_sample_interval);
spin_unlock_irqrestore(&h->lock, flags);
}
static struct workqueue_struct *hpsa_create_controller_wq(struct ctlr_info *h,
char *name)
{
struct workqueue_struct *wq = NULL;
wq = alloc_ordered_workqueue("%s_%d_hpsa", 0, name, h->ctlr);
if (!wq)
dev_err(&h->pdev->dev, "failed to create %s workqueue\n", name);
return wq;
}
static int hpsa_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int dac, rc;
struct ctlr_info *h;
int try_soft_reset = 0;
unsigned long flags;
u32 board_id;
if (number_of_controllers == 0)
printk(KERN_INFO DRIVER_NAME "\n");
rc = hpsa_lookup_board_id(pdev, &board_id);
if (rc < 0) {
dev_warn(&pdev->dev, "Board ID not found\n");
return rc;
}
rc = hpsa_init_reset_devices(pdev, board_id);
if (rc) {
if (rc != -ENOTSUPP)
return rc;
try_soft_reset = 1;
rc = 0;
}
reinit_after_soft_reset:
BUILD_BUG_ON(sizeof(struct CommandList) % COMMANDLIST_ALIGNMENT);
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h) {
dev_err(&pdev->dev, "Failed to allocate controller head\n");
return -ENOMEM;
}
h->pdev = pdev;
h->intr_mode = hpsa_simple_mode ? SIMPLE_MODE_INT : PERF_MODE_INT;
INIT_LIST_HEAD(&h->offline_device_list);
spin_lock_init(&h->lock);
spin_lock_init(&h->offline_device_lock);
spin_lock_init(&h->scan_lock);
atomic_set(&h->passthru_cmds_avail, HPSA_MAX_CONCURRENT_PASSTHRUS);
atomic_set(&h->abort_cmds_available, HPSA_CMDS_RESERVED_FOR_ABORTS);
h->lockup_detected = alloc_percpu(u32);
if (!h->lockup_detected) {
dev_err(&h->pdev->dev, "Failed to allocate lockup detector\n");
rc = -ENOMEM;
goto clean1;
}
set_lockup_detected_for_all_cpus(h, 0);
rc = hpsa_pci_init(h);
if (rc)
goto clean2;
rc = hpsa_scsi_host_alloc(h);
if (rc)
goto clean2_5;
sprintf(h->devname, HPSA "%d", h->scsi_host->host_no);
h->ctlr = number_of_controllers;
number_of_controllers++;
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc == 0) {
dac = 1;
} else {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc == 0) {
dac = 0;
} else {
dev_err(&pdev->dev, "no suitable DMA available\n");
goto clean3;
}
}
h->access.set_intr_mask(h, HPSA_INTR_OFF);
rc = hpsa_request_irqs(h, do_hpsa_intr_msi, do_hpsa_intr_intx);
if (rc)
goto clean3;
rc = hpsa_alloc_cmd_pool(h);
if (rc)
goto clean4;
rc = hpsa_alloc_sg_chain_blocks(h);
if (rc)
goto clean5;
init_waitqueue_head(&h->scan_wait_queue);
init_waitqueue_head(&h->abort_cmd_wait_queue);
init_waitqueue_head(&h->event_sync_wait_queue);
mutex_init(&h->reset_mutex);
h->scan_finished = 1;
pci_set_drvdata(pdev, h);
h->ndevices = 0;
spin_lock_init(&h->devlock);
rc = hpsa_put_ctlr_into_performant_mode(h);
if (rc)
goto clean6;
rc = hpsa_scsi_add_host(h);
if (rc)
goto clean7;
h->rescan_ctlr_wq = hpsa_create_controller_wq(h, "rescan");
if (!h->rescan_ctlr_wq) {
rc = -ENOMEM;
goto clean7;
}
h->resubmit_wq = hpsa_create_controller_wq(h, "resubmit");
if (!h->resubmit_wq) {
rc = -ENOMEM;
goto clean7;
}
if (try_soft_reset) {
spin_lock_irqsave(&h->lock, flags);
h->access.set_intr_mask(h, HPSA_INTR_OFF);
spin_unlock_irqrestore(&h->lock, flags);
hpsa_free_irqs(h);
rc = hpsa_request_irqs(h, hpsa_msix_discard_completions,
hpsa_intx_discard_completions);
if (rc) {
dev_warn(&h->pdev->dev,
"Failed to request_irq after soft reset.\n");
hpsa_free_performant_mode(h);
hpsa_free_sg_chain_blocks(h);
hpsa_free_cmd_pool(h);
goto clean3;
}
rc = hpsa_kdump_soft_reset(h);
if (rc)
goto clean7;
dev_info(&h->pdev->dev, "Board READY.\n");
dev_info(&h->pdev->dev,
"Waiting for stale completions to drain.\n");
h->access.set_intr_mask(h, HPSA_INTR_ON);
msleep(10000);
h->access.set_intr_mask(h, HPSA_INTR_OFF);
rc = controller_reset_failed(h->cfgtable);
if (rc)
dev_info(&h->pdev->dev,
"Soft reset appears to have failed.\n");
hpsa_undo_allocations_after_kdump_soft_reset(h);
try_soft_reset = 0;
if (rc)
return -ENODEV;
goto reinit_after_soft_reset;
}
h->acciopath_status = 1;
h->discovery_polling = 0;
h->access.set_intr_mask(h, HPSA_INTR_ON);
hpsa_hba_inquiry(h);
h->lastlogicals = kzalloc(sizeof(*(h->lastlogicals)), GFP_KERNEL);
if (!h->lastlogicals)
dev_info(&h->pdev->dev,
"Can't track change to report lun data\n");
h->heartbeat_sample_interval = HEARTBEAT_SAMPLE_INTERVAL;
INIT_DELAYED_WORK(&h->monitor_ctlr_work, hpsa_monitor_ctlr_worker);
schedule_delayed_work(&h->monitor_ctlr_work,
h->heartbeat_sample_interval);
INIT_DELAYED_WORK(&h->rescan_ctlr_work, hpsa_rescan_ctlr_worker);
queue_delayed_work(h->rescan_ctlr_wq, &h->rescan_ctlr_work,
h->heartbeat_sample_interval);
return 0;
clean7:
hpsa_free_performant_mode(h);
h->access.set_intr_mask(h, HPSA_INTR_OFF);
clean6:
hpsa_free_sg_chain_blocks(h);
clean5:
hpsa_free_cmd_pool(h);
clean4:
hpsa_free_irqs(h);
clean3:
scsi_host_put(h->scsi_host);
h->scsi_host = NULL;
clean2_5:
hpsa_free_pci_init(h);
clean2:
if (h->lockup_detected) {
free_percpu(h->lockup_detected);
h->lockup_detected = NULL;
}
clean1:
if (h->resubmit_wq) {
destroy_workqueue(h->resubmit_wq);
h->resubmit_wq = NULL;
}
if (h->rescan_ctlr_wq) {
destroy_workqueue(h->rescan_ctlr_wq);
h->rescan_ctlr_wq = NULL;
}
kfree(h);
return rc;
}
static void hpsa_flush_cache(struct ctlr_info *h)
{
char *flush_buf;
struct CommandList *c;
int rc;
if (unlikely(lockup_detected(h)))
return;
flush_buf = kzalloc(4, GFP_KERNEL);
if (!flush_buf)
return;
c = cmd_alloc(h);
if (fill_cmd(c, HPSA_CACHE_FLUSH, h, flush_buf, 4, 0,
RAID_CTLR_LUNID, TYPE_CMD)) {
goto out;
}
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_TODEVICE, NO_TIMEOUT);
if (rc)
goto out;
if (c->err_info->CommandStatus != 0)
out:
dev_warn(&h->pdev->dev,
"error flushing cache on controller\n");
cmd_free(h, c);
kfree(flush_buf);
}
static void hpsa_disable_rld_caching(struct ctlr_info *h)
{
u32 *options;
struct CommandList *c;
int rc;
if (unlikely(h->lockup_detected))
return;
options = kzalloc(sizeof(*options), GFP_KERNEL);
if (!options) {
dev_err(&h->pdev->dev,
"Error: failed to disable rld caching, during alloc.\n");
return;
}
c = cmd_alloc(h);
if (fill_cmd(c, BMIC_SENSE_DIAG_OPTIONS, h, options, 4, 0,
RAID_CTLR_LUNID, TYPE_CMD))
goto errout;
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if ((rc != 0) || (c->err_info->CommandStatus != 0))
goto errout;
*options |= HPSA_DIAG_OPTS_DISABLE_RLD_CACHING;
if (fill_cmd(c, BMIC_SET_DIAG_OPTIONS, h, options, 4, 0,
RAID_CTLR_LUNID, TYPE_CMD))
goto errout;
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_TODEVICE, NO_TIMEOUT);
if ((rc != 0) || (c->err_info->CommandStatus != 0))
goto errout;
if (fill_cmd(c, BMIC_SENSE_DIAG_OPTIONS, h, options, 4, 0,
RAID_CTLR_LUNID, TYPE_CMD))
goto errout;
rc = hpsa_scsi_do_simple_cmd_with_retry(h, c,
PCI_DMA_FROMDEVICE, NO_TIMEOUT);
if ((rc != 0) || (c->err_info->CommandStatus != 0))
goto errout;
if (*options & HPSA_DIAG_OPTS_DISABLE_RLD_CACHING)
goto out;
errout:
dev_err(&h->pdev->dev,
"Error: failed to disable report lun data caching.\n");
out:
cmd_free(h, c);
kfree(options);
}
static void hpsa_shutdown(struct pci_dev *pdev)
{
struct ctlr_info *h;
h = pci_get_drvdata(pdev);
hpsa_flush_cache(h);
h->access.set_intr_mask(h, HPSA_INTR_OFF);
hpsa_free_irqs(h);
hpsa_disable_interrupt_mode(h);
}
static void hpsa_free_device_info(struct ctlr_info *h)
{
int i;
for (i = 0; i < h->ndevices; i++) {
kfree(h->dev[i]);
h->dev[i] = NULL;
}
}
static void hpsa_remove_one(struct pci_dev *pdev)
{
struct ctlr_info *h;
unsigned long flags;
if (pci_get_drvdata(pdev) == NULL) {
dev_err(&pdev->dev, "unable to remove device\n");
return;
}
h = pci_get_drvdata(pdev);
spin_lock_irqsave(&h->lock, flags);
h->remove_in_progress = 1;
spin_unlock_irqrestore(&h->lock, flags);
cancel_delayed_work_sync(&h->monitor_ctlr_work);
cancel_delayed_work_sync(&h->rescan_ctlr_work);
destroy_workqueue(h->rescan_ctlr_wq);
destroy_workqueue(h->resubmit_wq);
if (h->scsi_host)
scsi_remove_host(h->scsi_host);
hpsa_shutdown(pdev);
hpsa_free_device_info(h);
kfree(h->hba_inquiry_data);
h->hba_inquiry_data = NULL;
hpsa_free_ioaccel2_sg_chain_blocks(h);
hpsa_free_performant_mode(h);
hpsa_free_sg_chain_blocks(h);
hpsa_free_cmd_pool(h);
kfree(h->lastlogicals);
scsi_host_put(h->scsi_host);
h->scsi_host = NULL;
hpsa_free_pci_init(h);
free_percpu(h->lockup_detected);
h->lockup_detected = NULL;
hpsa_delete_sas_host(h);
kfree(h);
}
static void calc_bucket_map(int bucket[], int num_buckets,
int nsgs, int min_blocks, u32 *bucket_map)
{
int i, j, b, size;
for (i = 0; i <= nsgs; i++) {
size = i + min_blocks;
b = num_buckets;
for (j = 0; j < num_buckets; j++) {
if (bucket[j] >= size) {
b = j;
break;
}
}
bucket_map[i] = b;
}
}
static int hpsa_enter_performant_mode(struct ctlr_info *h, u32 trans_support)
{
int i;
unsigned long register_value;
unsigned long transMethod = CFGTBL_Trans_Performant |
(trans_support & CFGTBL_Trans_use_short_tags) |
CFGTBL_Trans_enable_directed_msix |
(trans_support & (CFGTBL_Trans_io_accel1 |
CFGTBL_Trans_io_accel2));
struct access_method access = SA5_performant_access;
int bft[8] = {5, 6, 8, 10, 12, 20, 28, SG_ENTRIES_IN_CMD + 4};
#define MIN_IOACCEL2_BFT_ENTRY 5
#define HPSA_IOACCEL2_HEADER_SZ 4
int bft2[16] = {MIN_IOACCEL2_BFT_ENTRY, 6, 7, 8, 9, 10, 11, 12,
13, 14, 15, 16, 17, 18, 19,
HPSA_IOACCEL2_HEADER_SZ + IOACCEL2_MAXSGENTRIES};
BUILD_BUG_ON(ARRAY_SIZE(bft2) != 16);
BUILD_BUG_ON(ARRAY_SIZE(bft) != 8);
BUILD_BUG_ON(offsetof(struct io_accel2_cmd, sg) >
16 * MIN_IOACCEL2_BFT_ENTRY);
BUILD_BUG_ON(sizeof(struct ioaccel2_sg_element) != 16);
BUILD_BUG_ON(28 > SG_ENTRIES_IN_CMD + 4);
if (trans_support & (CFGTBL_Trans_io_accel1 | CFGTBL_Trans_io_accel2))
access = SA5_performant_access_no_read;
for (i = 0; i < h->nreply_queues; i++)
memset(h->reply_queue[i].head, 0, h->reply_queue_size);
bft[7] = SG_ENTRIES_IN_CMD + 4;
calc_bucket_map(bft, ARRAY_SIZE(bft),
SG_ENTRIES_IN_CMD, 4, h->blockFetchTable);
for (i = 0; i < 8; i++)
writel(bft[i], &h->transtable->BlockFetch[i]);
writel(h->max_commands, &h->transtable->RepQSize);
writel(h->nreply_queues, &h->transtable->RepQCount);
writel(0, &h->transtable->RepQCtrAddrLow32);
writel(0, &h->transtable->RepQCtrAddrHigh32);
for (i = 0; i < h->nreply_queues; i++) {
writel(0, &h->transtable->RepQAddr[i].upper);
writel(h->reply_queue[i].busaddr,
&h->transtable->RepQAddr[i].lower);
}
writel(0, &h->cfgtable->HostWrite.command_pool_addr_hi);
writel(transMethod, &(h->cfgtable->HostWrite.TransportRequest));
if (trans_support & CFGTBL_Trans_io_accel1) {
access = SA5_ioaccel_mode1_access;
writel(10, &h->cfgtable->HostWrite.CoalIntDelay);
writel(4, &h->cfgtable->HostWrite.CoalIntCount);
} else {
if (trans_support & CFGTBL_Trans_io_accel2) {
access = SA5_ioaccel_mode2_access;
writel(10, &h->cfgtable->HostWrite.CoalIntDelay);
writel(4, &h->cfgtable->HostWrite.CoalIntCount);
}
}
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
if (hpsa_wait_for_mode_change_ack(h)) {
dev_err(&h->pdev->dev,
"performant mode problem - doorbell timeout\n");
return -ENODEV;
}
register_value = readl(&(h->cfgtable->TransportActive));
if (!(register_value & CFGTBL_Trans_Performant)) {
dev_err(&h->pdev->dev,
"performant mode problem - transport not active\n");
return -ENODEV;
}
h->access = access;
h->transMethod = transMethod;
if (!((trans_support & CFGTBL_Trans_io_accel1) ||
(trans_support & CFGTBL_Trans_io_accel2)))
return 0;
if (trans_support & CFGTBL_Trans_io_accel1) {
for (i = 0; i < h->nreply_queues; i++) {
writel(i, h->vaddr + IOACCEL_MODE1_REPLY_QUEUE_INDEX);
h->reply_queue[i].current_entry =
readl(h->vaddr + IOACCEL_MODE1_PRODUCER_INDEX);
}
bft[7] = h->ioaccel_maxsg + 8;
calc_bucket_map(bft, ARRAY_SIZE(bft), h->ioaccel_maxsg, 8,
h->ioaccel1_blockFetchTable);
for (i = 0; i < h->nreply_queues; i++)
memset(h->reply_queue[i].head,
(u8) IOACCEL_MODE1_REPLY_UNUSED,
h->reply_queue_size);
for (i = 0; i < h->nr_cmds; i++) {
struct io_accel1_cmd *cp = &h->ioaccel_cmd_pool[i];
cp->function = IOACCEL1_FUNCTION_SCSIIO;
cp->err_info = (u32) (h->errinfo_pool_dhandle +
(i * sizeof(struct ErrorInfo)));
cp->err_info_len = sizeof(struct ErrorInfo);
cp->sgl_offset = IOACCEL1_SGLOFFSET;
cp->host_context_flags =
cpu_to_le16(IOACCEL1_HCFLAGS_CISS_FORMAT);
cp->timeout_sec = 0;
cp->ReplyQueue = 0;
cp->tag =
cpu_to_le64((i << DIRECT_LOOKUP_SHIFT));
cp->host_addr =
cpu_to_le64(h->ioaccel_cmd_pool_dhandle +
(i * sizeof(struct io_accel1_cmd)));
}
} else if (trans_support & CFGTBL_Trans_io_accel2) {
u64 cfg_offset, cfg_base_addr_index;
u32 bft2_offset, cfg_base_addr;
int rc;
rc = hpsa_find_cfg_addrs(h->pdev, h->vaddr, &cfg_base_addr,
&cfg_base_addr_index, &cfg_offset);
BUILD_BUG_ON(offsetof(struct io_accel2_cmd, sg) != 64);
bft2[15] = h->ioaccel_maxsg + HPSA_IOACCEL2_HEADER_SZ;
calc_bucket_map(bft2, ARRAY_SIZE(bft2), h->ioaccel_maxsg,
4, h->ioaccel2_blockFetchTable);
bft2_offset = readl(&h->cfgtable->io_accel_request_size_offset);
BUILD_BUG_ON(offsetof(struct CfgTable,
io_accel_request_size_offset) != 0xb8);
h->ioaccel2_bft2_regs =
remap_pci_mem(pci_resource_start(h->pdev,
cfg_base_addr_index) +
cfg_offset + bft2_offset,
ARRAY_SIZE(bft2) *
sizeof(*h->ioaccel2_bft2_regs));
for (i = 0; i < ARRAY_SIZE(bft2); i++)
writel(bft2[i], &h->ioaccel2_bft2_regs[i]);
}
writel(CFGTBL_ChangeReq, h->vaddr + SA5_DOORBELL);
if (hpsa_wait_for_mode_change_ack(h)) {
dev_err(&h->pdev->dev,
"performant mode problem - enabling ioaccel mode\n");
return -ENODEV;
}
return 0;
}
static void hpsa_free_ioaccel1_cmd_and_bft(struct ctlr_info *h)
{
if (h->ioaccel_cmd_pool) {
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel_cmd_pool),
h->ioaccel_cmd_pool,
h->ioaccel_cmd_pool_dhandle);
h->ioaccel_cmd_pool = NULL;
h->ioaccel_cmd_pool_dhandle = 0;
}
kfree(h->ioaccel1_blockFetchTable);
h->ioaccel1_blockFetchTable = NULL;
}
static int hpsa_alloc_ioaccel1_cmd_and_bft(struct ctlr_info *h)
{
h->ioaccel_maxsg =
readl(&(h->cfgtable->io_accel_max_embedded_sg_count));
if (h->ioaccel_maxsg > IOACCEL1_MAXSGENTRIES)
h->ioaccel_maxsg = IOACCEL1_MAXSGENTRIES;
BUILD_BUG_ON(sizeof(struct io_accel1_cmd) %
IOACCEL1_COMMANDLIST_ALIGNMENT);
h->ioaccel_cmd_pool =
pci_alloc_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel_cmd_pool),
&(h->ioaccel_cmd_pool_dhandle));
h->ioaccel1_blockFetchTable =
kmalloc(((h->ioaccel_maxsg + 1) *
sizeof(u32)), GFP_KERNEL);
if ((h->ioaccel_cmd_pool == NULL) ||
(h->ioaccel1_blockFetchTable == NULL))
goto clean_up;
memset(h->ioaccel_cmd_pool, 0,
h->nr_cmds * sizeof(*h->ioaccel_cmd_pool));
return 0;
clean_up:
hpsa_free_ioaccel1_cmd_and_bft(h);
return -ENOMEM;
}
static void hpsa_free_ioaccel2_cmd_and_bft(struct ctlr_info *h)
{
hpsa_free_ioaccel2_sg_chain_blocks(h);
if (h->ioaccel2_cmd_pool) {
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel2_cmd_pool),
h->ioaccel2_cmd_pool,
h->ioaccel2_cmd_pool_dhandle);
h->ioaccel2_cmd_pool = NULL;
h->ioaccel2_cmd_pool_dhandle = 0;
}
kfree(h->ioaccel2_blockFetchTable);
h->ioaccel2_blockFetchTable = NULL;
}
static int hpsa_alloc_ioaccel2_cmd_and_bft(struct ctlr_info *h)
{
int rc;
h->ioaccel_maxsg =
readl(&(h->cfgtable->io_accel_max_embedded_sg_count));
if (h->ioaccel_maxsg > IOACCEL2_MAXSGENTRIES)
h->ioaccel_maxsg = IOACCEL2_MAXSGENTRIES;
BUILD_BUG_ON(sizeof(struct io_accel2_cmd) %
IOACCEL2_COMMANDLIST_ALIGNMENT);
h->ioaccel2_cmd_pool =
pci_alloc_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel2_cmd_pool),
&(h->ioaccel2_cmd_pool_dhandle));
h->ioaccel2_blockFetchTable =
kmalloc(((h->ioaccel_maxsg + 1) *
sizeof(u32)), GFP_KERNEL);
if ((h->ioaccel2_cmd_pool == NULL) ||
(h->ioaccel2_blockFetchTable == NULL)) {
rc = -ENOMEM;
goto clean_up;
}
rc = hpsa_allocate_ioaccel2_sg_chain_blocks(h);
if (rc)
goto clean_up;
memset(h->ioaccel2_cmd_pool, 0,
h->nr_cmds * sizeof(*h->ioaccel2_cmd_pool));
return 0;
clean_up:
hpsa_free_ioaccel2_cmd_and_bft(h);
return rc;
}
static void hpsa_free_performant_mode(struct ctlr_info *h)
{
kfree(h->blockFetchTable);
h->blockFetchTable = NULL;
hpsa_free_reply_queues(h);
hpsa_free_ioaccel1_cmd_and_bft(h);
hpsa_free_ioaccel2_cmd_and_bft(h);
}
static int hpsa_put_ctlr_into_performant_mode(struct ctlr_info *h)
{
u32 trans_support;
unsigned long transMethod = CFGTBL_Trans_Performant |
CFGTBL_Trans_use_short_tags;
int i, rc;
if (hpsa_simple_mode)
return 0;
trans_support = readl(&(h->cfgtable->TransportSupport));
if (!(trans_support & PERFORMANT_MODE))
return 0;
if (trans_support & CFGTBL_Trans_io_accel1) {
transMethod |= CFGTBL_Trans_io_accel1 |
CFGTBL_Trans_enable_directed_msix;
rc = hpsa_alloc_ioaccel1_cmd_and_bft(h);
if (rc)
return rc;
} else if (trans_support & CFGTBL_Trans_io_accel2) {
transMethod |= CFGTBL_Trans_io_accel2 |
CFGTBL_Trans_enable_directed_msix;
rc = hpsa_alloc_ioaccel2_cmd_and_bft(h);
if (rc)
return rc;
}
h->nreply_queues = h->msix_vector > 0 ? h->msix_vector : 1;
hpsa_get_max_perf_mode_cmds(h);
h->reply_queue_size = h->max_commands * sizeof(u64);
for (i = 0; i < h->nreply_queues; i++) {
h->reply_queue[i].head = pci_alloc_consistent(h->pdev,
h->reply_queue_size,
&(h->reply_queue[i].busaddr));
if (!h->reply_queue[i].head) {
rc = -ENOMEM;
goto clean1;
}
h->reply_queue[i].size = h->max_commands;
h->reply_queue[i].wraparound = 1;
h->reply_queue[i].current_entry = 0;
}
h->blockFetchTable = kmalloc(((SG_ENTRIES_IN_CMD + 1) *
sizeof(u32)), GFP_KERNEL);
if (!h->blockFetchTable) {
rc = -ENOMEM;
goto clean1;
}
rc = hpsa_enter_performant_mode(h, trans_support);
if (rc)
goto clean2;
return 0;
clean2:
kfree(h->blockFetchTable);
h->blockFetchTable = NULL;
clean1:
hpsa_free_reply_queues(h);
hpsa_free_ioaccel1_cmd_and_bft(h);
hpsa_free_ioaccel2_cmd_and_bft(h);
return rc;
}
static int is_accelerated_cmd(struct CommandList *c)
{
return c->cmd_type == CMD_IOACCEL1 || c->cmd_type == CMD_IOACCEL2;
}
static void hpsa_drain_accel_commands(struct ctlr_info *h)
{
struct CommandList *c = NULL;
int i, accel_cmds_out;
int refcount;
do {
accel_cmds_out = 0;
for (i = 0; i < h->nr_cmds; i++) {
c = h->cmd_pool + i;
refcount = atomic_inc_return(&c->refcount);
if (refcount > 1)
accel_cmds_out += is_accelerated_cmd(c);
cmd_free(h, c);
}
if (accel_cmds_out <= 0)
break;
msleep(100);
} while (1);
}
static struct hpsa_sas_phy *hpsa_alloc_sas_phy(
struct hpsa_sas_port *hpsa_sas_port)
{
struct hpsa_sas_phy *hpsa_sas_phy;
struct sas_phy *phy;
hpsa_sas_phy = kzalloc(sizeof(*hpsa_sas_phy), GFP_KERNEL);
if (!hpsa_sas_phy)
return NULL;
phy = sas_phy_alloc(hpsa_sas_port->parent_node->parent_dev,
hpsa_sas_port->next_phy_index);
if (!phy) {
kfree(hpsa_sas_phy);
return NULL;
}
hpsa_sas_port->next_phy_index++;
hpsa_sas_phy->phy = phy;
hpsa_sas_phy->parent_port = hpsa_sas_port;
return hpsa_sas_phy;
}
static void hpsa_free_sas_phy(struct hpsa_sas_phy *hpsa_sas_phy)
{
struct sas_phy *phy = hpsa_sas_phy->phy;
sas_port_delete_phy(hpsa_sas_phy->parent_port->port, phy);
sas_phy_free(phy);
if (hpsa_sas_phy->added_to_port)
list_del(&hpsa_sas_phy->phy_list_entry);
kfree(hpsa_sas_phy);
}
static int hpsa_sas_port_add_phy(struct hpsa_sas_phy *hpsa_sas_phy)
{
int rc;
struct hpsa_sas_port *hpsa_sas_port;
struct sas_phy *phy;
struct sas_identify *identify;
hpsa_sas_port = hpsa_sas_phy->parent_port;
phy = hpsa_sas_phy->phy;
identify = &phy->identify;
memset(identify, 0, sizeof(*identify));
identify->sas_address = hpsa_sas_port->sas_address;
identify->device_type = SAS_END_DEVICE;
identify->initiator_port_protocols = SAS_PROTOCOL_STP;
identify->target_port_protocols = SAS_PROTOCOL_STP;
phy->minimum_linkrate_hw = SAS_LINK_RATE_UNKNOWN;
phy->maximum_linkrate_hw = SAS_LINK_RATE_UNKNOWN;
phy->minimum_linkrate = SAS_LINK_RATE_UNKNOWN;
phy->maximum_linkrate = SAS_LINK_RATE_UNKNOWN;
phy->negotiated_linkrate = SAS_LINK_RATE_UNKNOWN;
rc = sas_phy_add(hpsa_sas_phy->phy);
if (rc)
return rc;
sas_port_add_phy(hpsa_sas_port->port, hpsa_sas_phy->phy);
list_add_tail(&hpsa_sas_phy->phy_list_entry,
&hpsa_sas_port->phy_list_head);
hpsa_sas_phy->added_to_port = true;
return 0;
}
static int
hpsa_sas_port_add_rphy(struct hpsa_sas_port *hpsa_sas_port,
struct sas_rphy *rphy)
{
struct sas_identify *identify;
identify = &rphy->identify;
identify->sas_address = hpsa_sas_port->sas_address;
identify->initiator_port_protocols = SAS_PROTOCOL_STP;
identify->target_port_protocols = SAS_PROTOCOL_STP;
return sas_rphy_add(rphy);
}
static struct hpsa_sas_port
*hpsa_alloc_sas_port(struct hpsa_sas_node *hpsa_sas_node,
u64 sas_address)
{
int rc;
struct hpsa_sas_port *hpsa_sas_port;
struct sas_port *port;
hpsa_sas_port = kzalloc(sizeof(*hpsa_sas_port), GFP_KERNEL);
if (!hpsa_sas_port)
return NULL;
INIT_LIST_HEAD(&hpsa_sas_port->phy_list_head);
hpsa_sas_port->parent_node = hpsa_sas_node;
port = sas_port_alloc_num(hpsa_sas_node->parent_dev);
if (!port)
goto free_hpsa_port;
rc = sas_port_add(port);
if (rc)
goto free_sas_port;
hpsa_sas_port->port = port;
hpsa_sas_port->sas_address = sas_address;
list_add_tail(&hpsa_sas_port->port_list_entry,
&hpsa_sas_node->port_list_head);
return hpsa_sas_port;
free_sas_port:
sas_port_free(port);
free_hpsa_port:
kfree(hpsa_sas_port);
return NULL;
}
static void hpsa_free_sas_port(struct hpsa_sas_port *hpsa_sas_port)
{
struct hpsa_sas_phy *hpsa_sas_phy;
struct hpsa_sas_phy *next;
list_for_each_entry_safe(hpsa_sas_phy, next,
&hpsa_sas_port->phy_list_head, phy_list_entry)
hpsa_free_sas_phy(hpsa_sas_phy);
sas_port_delete(hpsa_sas_port->port);
list_del(&hpsa_sas_port->port_list_entry);
kfree(hpsa_sas_port);
}
static struct hpsa_sas_node *hpsa_alloc_sas_node(struct device *parent_dev)
{
struct hpsa_sas_node *hpsa_sas_node;
hpsa_sas_node = kzalloc(sizeof(*hpsa_sas_node), GFP_KERNEL);
if (hpsa_sas_node) {
hpsa_sas_node->parent_dev = parent_dev;
INIT_LIST_HEAD(&hpsa_sas_node->port_list_head);
}
return hpsa_sas_node;
}
static void hpsa_free_sas_node(struct hpsa_sas_node *hpsa_sas_node)
{
struct hpsa_sas_port *hpsa_sas_port;
struct hpsa_sas_port *next;
if (!hpsa_sas_node)
return;
list_for_each_entry_safe(hpsa_sas_port, next,
&hpsa_sas_node->port_list_head, port_list_entry)
hpsa_free_sas_port(hpsa_sas_port);
kfree(hpsa_sas_node);
}
static struct hpsa_scsi_dev_t
*hpsa_find_device_by_sas_rphy(struct ctlr_info *h,
struct sas_rphy *rphy)
{
int i;
struct hpsa_scsi_dev_t *device;
for (i = 0; i < h->ndevices; i++) {
device = h->dev[i];
if (!device->sas_port)
continue;
if (device->sas_port->rphy == rphy)
return device;
}
return NULL;
}
static int hpsa_add_sas_host(struct ctlr_info *h)
{
int rc;
struct device *parent_dev;
struct hpsa_sas_node *hpsa_sas_node;
struct hpsa_sas_port *hpsa_sas_port;
struct hpsa_sas_phy *hpsa_sas_phy;
parent_dev = &h->scsi_host->shost_gendev;
hpsa_sas_node = hpsa_alloc_sas_node(parent_dev);
if (!hpsa_sas_node)
return -ENOMEM;
hpsa_sas_port = hpsa_alloc_sas_port(hpsa_sas_node, h->sas_address);
if (!hpsa_sas_port) {
rc = -ENODEV;
goto free_sas_node;
}
hpsa_sas_phy = hpsa_alloc_sas_phy(hpsa_sas_port);
if (!hpsa_sas_phy) {
rc = -ENODEV;
goto free_sas_port;
}
rc = hpsa_sas_port_add_phy(hpsa_sas_phy);
if (rc)
goto free_sas_phy;
h->sas_host = hpsa_sas_node;
return 0;
free_sas_phy:
hpsa_free_sas_phy(hpsa_sas_phy);
free_sas_port:
hpsa_free_sas_port(hpsa_sas_port);
free_sas_node:
hpsa_free_sas_node(hpsa_sas_node);
return rc;
}
static void hpsa_delete_sas_host(struct ctlr_info *h)
{
hpsa_free_sas_node(h->sas_host);
}
static int hpsa_add_sas_device(struct hpsa_sas_node *hpsa_sas_node,
struct hpsa_scsi_dev_t *device)
{
int rc;
struct hpsa_sas_port *hpsa_sas_port;
struct sas_rphy *rphy;
hpsa_sas_port = hpsa_alloc_sas_port(hpsa_sas_node, device->sas_address);
if (!hpsa_sas_port)
return -ENOMEM;
rphy = sas_end_device_alloc(hpsa_sas_port->port);
if (!rphy) {
rc = -ENODEV;
goto free_sas_port;
}
hpsa_sas_port->rphy = rphy;
device->sas_port = hpsa_sas_port;
rc = hpsa_sas_port_add_rphy(hpsa_sas_port, rphy);
if (rc)
goto free_sas_port;
return 0;
free_sas_port:
hpsa_free_sas_port(hpsa_sas_port);
device->sas_port = NULL;
return rc;
}
static void hpsa_remove_sas_device(struct hpsa_scsi_dev_t *device)
{
if (device->sas_port) {
hpsa_free_sas_port(device->sas_port);
device->sas_port = NULL;
}
}
static int
hpsa_sas_get_linkerrors(struct sas_phy *phy)
{
return 0;
}
static int
hpsa_sas_get_enclosure_identifier(struct sas_rphy *rphy, u64 *identifier)
{
return 0;
}
static int
hpsa_sas_get_bay_identifier(struct sas_rphy *rphy)
{
return -ENXIO;
}
static int
hpsa_sas_phy_reset(struct sas_phy *phy, int hard_reset)
{
return 0;
}
static int
hpsa_sas_phy_enable(struct sas_phy *phy, int enable)
{
return 0;
}
static int
hpsa_sas_phy_setup(struct sas_phy *phy)
{
return 0;
}
static void
hpsa_sas_phy_release(struct sas_phy *phy)
{
}
static int
hpsa_sas_phy_speed(struct sas_phy *phy, struct sas_phy_linkrates *rates)
{
return -EINVAL;
}
static int
hpsa_sas_smp_handler(struct Scsi_Host *shost, struct sas_rphy *rphy,
struct request *req)
{
return -EINVAL;
}
static int __init hpsa_init(void)
{
int rc;
hpsa_sas_transport_template =
sas_attach_transport(&hpsa_sas_transport_functions);
if (!hpsa_sas_transport_template)
return -ENODEV;
rc = pci_register_driver(&hpsa_pci_driver);
if (rc)
sas_release_transport(hpsa_sas_transport_template);
return rc;
}
static void __exit hpsa_cleanup(void)
{
pci_unregister_driver(&hpsa_pci_driver);
sas_release_transport(hpsa_sas_transport_template);
}
