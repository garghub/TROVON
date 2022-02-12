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
static int check_for_unit_attention(struct ctlr_info *h,
struct CommandList *c)
{
if (c->err_info->SenseInfo[2] != UNIT_ATTENTION)
return 0;
switch (c->err_info->SenseInfo[12]) {
case STATE_CHANGED:
dev_warn(&h->pdev->dev, HPSA "%d: a state change "
"detected, command retried\n", h->ctlr);
break;
case LUN_FAILED:
dev_warn(&h->pdev->dev, HPSA "%d: LUN failure "
"detected, action required\n", h->ctlr);
break;
case REPORT_LUNS_CHANGED:
dev_warn(&h->pdev->dev, HPSA "%d: report LUN data "
"changed, action required\n", h->ctlr);
break;
case POWER_OR_RESET:
dev_warn(&h->pdev->dev, HPSA "%d: a power on "
"or device reset detected\n", h->ctlr);
break;
case UNIT_ATTENTION_CLEARED:
dev_warn(&h->pdev->dev, HPSA "%d: unit attention "
"cleared by another initiator\n", h->ctlr);
break;
default:
dev_warn(&h->pdev->dev, HPSA "%d: unknown "
"unit attention detected\n", h->ctlr);
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
return snprintf(buf, 20, "%d\n", h->commands_outstanding);
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
static int ctlr_is_hard_resettable(u32 board_id)
{
int i;
for (i = 0; i < ARRAY_SIZE(unresettable_controller); i++)
if (unresettable_controller[i] == board_id)
return 0;
return 1;
}
static int ctlr_is_soft_resettable(u32 board_id)
{
int i;
for (i = 0; i < ARRAY_SIZE(soft_unresettable_controller); i++)
if (soft_unresettable_controller[i] == board_id)
return 0;
return 1;
}
static int ctlr_is_resettable(u32 board_id)
{
return ctlr_is_hard_resettable(board_id) ||
ctlr_is_soft_resettable(board_id);
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
if (!is_logical_dev_addr_mode(hdev->scsi3addr)) {
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
static inline void addQ(struct list_head *list, struct CommandList *c)
{
list_add_tail(&c->list, list);
}
static inline u32 next_command(struct ctlr_info *h, u8 q)
{
u32 a;
struct reply_queue_buffer *rq = &h->reply_queue[q];
unsigned long flags;
if (h->transMethod & CFGTBL_Trans_io_accel1)
return h->access.command_completed(h, q);
if (unlikely(!(h->transMethod & CFGTBL_Trans_Performant)))
return h->access.command_completed(h, q);
if ((rq->head[rq->current_entry] & 1) == rq->wraparound) {
a = rq->head[rq->current_entry];
rq->current_entry++;
spin_lock_irqsave(&h->lock, flags);
h->commands_outstanding--;
spin_unlock_irqrestore(&h->lock, flags);
} else {
a = FIFO_EMPTY;
}
if (rq->current_entry == h->max_commands) {
rq->current_entry = 0;
rq->wraparound ^= 1;
}
return a;
}
static void set_performant_mode(struct ctlr_info *h, struct CommandList *c)
{
if (likely(h->transMethod & CFGTBL_Trans_Performant)) {
c->busaddr |= 1 | (h->blockFetchTable[c->Header.SGList] << 1);
if (likely(h->msix_vector > 0))
c->Header.ReplyQueue =
raw_smp_processor_id() % h->nreply_queues;
}
}
static void set_ioaccel1_performant_mode(struct ctlr_info *h,
struct CommandList *c)
{
struct io_accel1_cmd *cp = &h->ioaccel_cmd_pool[c->cmdindex];
cp->ReplyQueue = smp_processor_id() % h->nreply_queues;
c->busaddr |= 1 | (h->ioaccel1_blockFetchTable[c->Header.SGList] << 1) |
IOACCEL1_BUSADDR_CMDTYPE;
}
static void set_ioaccel2_performant_mode(struct ctlr_info *h,
struct CommandList *c)
{
struct io_accel2_cmd *cp = &h->ioaccel2_cmd_pool[c->cmdindex];
cp->reply_queue = smp_processor_id() % h->nreply_queues;
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
static void enqueue_cmd_and_start_io(struct ctlr_info *h,
struct CommandList *c)
{
unsigned long flags;
switch (c->cmd_type) {
case CMD_IOACCEL1:
set_ioaccel1_performant_mode(h, c);
break;
case CMD_IOACCEL2:
set_ioaccel2_performant_mode(h, c);
break;
default:
set_performant_mode(h, c);
}
dial_down_lockup_detection_during_fw_flash(h, c);
spin_lock_irqsave(&h->lock, flags);
addQ(&h->reqQ, c);
h->Qdepth++;
start_io(h, &flags);
spin_unlock_irqrestore(&h->lock, flags);
}
static inline void removeQ(struct CommandList *c)
{
if (WARN_ON(list_empty(&c->list)))
return;
list_del_init(&c->list);
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
static int hpsa_scsi_add_entry(struct ctlr_info *h, int hostno,
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
for (i = 0; i < n; i++) {
sd = h->dev[i];
memcpy(addr2, sd->scsi3addr, 8);
addr2[4] = 0;
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
dev_info(&h->pdev->dev, "%s device c%db%dt%dl%d added.\n",
scsi_device_type(device->devtype), hostno,
device->bus, device->target, device->lun);
return 0;
}
static void hpsa_scsi_update_entry(struct ctlr_info *h, int hostno,
int entry, struct hpsa_scsi_dev_t *new_entry)
{
BUG_ON(entry < 0 || entry >= HPSA_MAX_DEVICES);
h->dev[entry]->raid_level = new_entry->raid_level;
h->dev[entry]->offload_config = new_entry->offload_config;
h->dev[entry]->offload_enabled = new_entry->offload_enabled;
h->dev[entry]->ioaccel_handle = new_entry->ioaccel_handle;
h->dev[entry]->offload_to_mirror = new_entry->offload_to_mirror;
h->dev[entry]->raid_map = new_entry->raid_map;
dev_info(&h->pdev->dev, "%s device c%db%dt%dl%d updated.\n",
scsi_device_type(new_entry->devtype), hostno, new_entry->bus,
new_entry->target, new_entry->lun);
}
static void hpsa_scsi_replace_entry(struct ctlr_info *h, int hostno,
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
dev_info(&h->pdev->dev, "%s device c%db%dt%dl%d changed.\n",
scsi_device_type(new_entry->devtype), hostno, new_entry->bus,
new_entry->target, new_entry->lun);
}
static void hpsa_scsi_remove_entry(struct ctlr_info *h, int hostno, int entry,
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
dev_info(&h->pdev->dev, "%s device c%db%dt%dl%d removed.\n",
scsi_device_type(sd->devtype), hostno, sd->bus, sd->target,
sd->lun);
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
case HPSA_LV_UNDERGOING_RPI:
dev_info(&h->pdev->dev,
"C%d:B%d:T%d:L%d Volume is undergoing rapid parity initialization process.\n",
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
static void adjust_hpsa_scsi_table(struct ctlr_info *h, int hostno,
struct hpsa_scsi_dev_t *sd[], int nsds)
{
int i, entry, device_change, changes = 0;
struct hpsa_scsi_dev_t *csd;
unsigned long flags;
struct hpsa_scsi_dev_t **added, **removed;
int nadded, nremoved;
struct Scsi_Host *sh = NULL;
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
hpsa_scsi_remove_entry(h, hostno, i,
removed, &nremoved);
continue;
} else if (device_change == DEVICE_CHANGED) {
changes++;
hpsa_scsi_replace_entry(h, hostno, i, sd[entry],
added, &nadded, removed, &nremoved);
sd[entry] = NULL;
} else if (device_change == DEVICE_UPDATED) {
hpsa_scsi_update_entry(h, hostno, i, sd[entry]);
}
i++;
}
for (i = 0; i < nsds; i++) {
if (!sd[i])
continue;
if (sd[i]->volume_offline) {
hpsa_show_volume_status(h, sd[i]);
dev_info(&h->pdev->dev, "c%db%dt%dl%d: temporarily offline\n",
h->scsi_host->host_no,
sd[i]->bus, sd[i]->target, sd[i]->lun);
continue;
}
device_change = hpsa_scsi_find_entry(sd[i], h->dev,
h->ndevices, &entry);
if (device_change == DEVICE_NOT_FOUND) {
changes++;
if (hpsa_scsi_add_entry(h, hostno, sd[i],
added, &nadded) != 0)
break;
sd[i] = NULL;
} else if (device_change == DEVICE_CHANGED) {
changes++;
dev_warn(&h->pdev->dev,
"device unexpectedly changed.\n");
}
}
spin_unlock_irqrestore(&h->devlock, flags);
for (i = 0; i < nsds; i++) {
if (!sd[i])
continue;
if (sd[i]->volume_offline)
hpsa_monitor_offline_device(h, sd[i]->scsi3addr);
}
if (hostno == -1 || !changes)
goto free_and_out;
sh = h->scsi_host;
for (i = 0; i < nremoved; i++) {
struct scsi_device *sdev =
scsi_device_lookup(sh, removed[i]->bus,
removed[i]->target, removed[i]->lun);
if (sdev != NULL) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
} else {
dev_warn(&h->pdev->dev, "didn't find c%db%dt%dl%d "
" for removal.", hostno, removed[i]->bus,
removed[i]->target, removed[i]->lun);
}
kfree(removed[i]);
removed[i] = NULL;
}
for (i = 0; i < nadded; i++) {
if (scsi_add_device(sh, added[i]->bus,
added[i]->target, added[i]->lun) == 0)
continue;
dev_warn(&h->pdev->dev, "scsi_add_device c%db%dt%dl%d failed, "
"device not added.\n", hostno, added[i]->bus,
added[i]->target, added[i]->lun);
fixup_botched_add(h, added[i]);
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
sd = lookup_hpsa_scsi_dev(h, sdev_channel(sdev),
sdev_id(sdev), sdev->lun);
if (sd != NULL)
sdev->hostdata = sd;
spin_unlock_irqrestore(&h->devlock, flags);
return 0;
}
static void hpsa_slave_destroy(struct scsi_device *sdev)
{
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
static int hpsa_allocate_sg_chain_blocks(struct ctlr_info *h)
{
int i;
if (h->chainsize <= 0)
return 0;
h->cmd_sg_list = kzalloc(sizeof(*h->cmd_sg_list) * h->nr_cmds,
GFP_KERNEL);
if (!h->cmd_sg_list)
return -ENOMEM;
for (i = 0; i < h->nr_cmds; i++) {
h->cmd_sg_list[i] = kmalloc(sizeof(*h->cmd_sg_list[i]) *
h->chainsize, GFP_KERNEL);
if (!h->cmd_sg_list[i])
goto clean;
}
return 0;
clean:
hpsa_free_sg_chain_blocks(h);
return -ENOMEM;
}
static int hpsa_map_sg_chain_block(struct ctlr_info *h,
struct CommandList *c)
{
struct SGDescriptor *chain_sg, *chain_block;
u64 temp64;
chain_sg = &c->SG[h->max_cmd_sg_entries - 1];
chain_block = h->cmd_sg_list[c->cmdindex];
chain_sg->Ext = HPSA_SG_CHAIN;
chain_sg->Len = sizeof(*chain_sg) *
(c->Header.SGTotal - h->max_cmd_sg_entries);
temp64 = pci_map_single(h->pdev, chain_block, chain_sg->Len,
PCI_DMA_TODEVICE);
if (dma_mapping_error(&h->pdev->dev, temp64)) {
chain_sg->Addr.lower = 0;
chain_sg->Addr.upper = 0;
return -1;
}
chain_sg->Addr.lower = (u32) (temp64 & 0x0FFFFFFFFULL);
chain_sg->Addr.upper = (u32) ((temp64 >> 32) & 0x0FFFFFFFFULL);
return 0;
}
static void hpsa_unmap_sg_chain_block(struct ctlr_info *h,
struct CommandList *c)
{
struct SGDescriptor *chain_sg;
union u64bit temp64;
if (c->Header.SGTotal <= h->max_cmd_sg_entries)
return;
chain_sg = &c->SG[h->max_cmd_sg_entries - 1];
temp64.val32.lower = chain_sg->Addr.lower;
temp64.val32.upper = chain_sg->Addr.upper;
pci_unmap_single(h->pdev, temp64.val, chain_sg->Len, PCI_DMA_TODEVICE);
}
static int handle_ioaccel_mode2_error(struct ctlr_info *h,
struct CommandList *c,
struct scsi_cmnd *cmd,
struct io_accel2_cmd *c2)
{
int data_len;
int retry = 0;
switch (c2->error_data.serv_response) {
case IOACCEL2_SERV_RESPONSE_COMPLETE:
switch (c2->error_data.status) {
case IOACCEL2_STATUS_SR_TASK_COMP_GOOD:
break;
case IOACCEL2_STATUS_SR_TASK_COMP_CHK_COND:
dev_warn(&h->pdev->dev,
"%s: task complete with check condition.\n",
"HP SSD Smart Path");
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
dev_warn(&h->pdev->dev,
"%s: task complete with BUSY status.\n",
"HP SSD Smart Path");
retry = 1;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_RES_CON:
dev_warn(&h->pdev->dev,
"%s: task complete with reservation conflict.\n",
"HP SSD Smart Path");
retry = 1;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_SET_FULL:
cmd->result = DID_IMM_RETRY << 16;
break;
case IOACCEL2_STATUS_SR_TASK_COMP_ABORTED:
dev_warn(&h->pdev->dev,
"%s: task complete with aborted status.\n",
"HP SSD Smart Path");
retry = 1;
break;
default:
dev_warn(&h->pdev->dev,
"%s: task complete with unrecognized status: 0x%02x\n",
"HP SSD Smart Path", c2->error_data.status);
retry = 1;
break;
}
break;
case IOACCEL2_SERV_RESPONSE_FAILURE:
dev_warn(&h->pdev->dev,
"unexpected delivery or target failure, status = 0x%02x\n",
c2->error_data.status);
retry = 1;
break;
case IOACCEL2_SERV_RESPONSE_TMF_COMPLETE:
break;
case IOACCEL2_SERV_RESPONSE_TMF_SUCCESS:
break;
case IOACCEL2_SERV_RESPONSE_TMF_REJECTED:
dev_warn(&h->pdev->dev, "task management function rejected.\n");
retry = 1;
break;
case IOACCEL2_SERV_RESPONSE_TMF_WRONG_LUN:
dev_warn(&h->pdev->dev, "task management function invalid LUN\n");
break;
default:
dev_warn(&h->pdev->dev,
"%s: Unrecognized server response: 0x%02x\n",
"HP SSD Smart Path",
c2->error_data.serv_response);
retry = 1;
break;
}
return retry;
}
static void process_ioaccel2_completion(struct ctlr_info *h,
struct CommandList *c, struct scsi_cmnd *cmd,
struct hpsa_scsi_dev_t *dev)
{
struct io_accel2_cmd *c2 = &h->ioaccel2_cmd_pool[c->cmdindex];
int raid_retry = 0;
if (likely(c2->error_data.serv_response == 0 &&
c2->error_data.status == 0)) {
cmd_free(h, c);
cmd->scsi_done(cmd);
return;
}
if (is_logical_dev_addr_mode(dev->scsi3addr) &&
c2->error_data.serv_response ==
IOACCEL2_SERV_RESPONSE_FAILURE) {
dev->offload_enabled = 0;
h->drv_req_rescan = 1;
cmd->result = DID_SOFT_ERROR << 16;
cmd_free(h, c);
cmd->scsi_done(cmd);
return;
}
raid_retry = handle_ioaccel_mode2_error(h, c, cmd, c2);
if (raid_retry) {
dev_warn(&h->pdev->dev, "%s: Retrying on standard path.\n",
"HP SSD Smart Path");
dev->offload_enabled = 0;
h->drv_req_rescan = 1;
cmd->result = DID_SOFT_ERROR << 16;
}
cmd_free(h, c);
cmd->scsi_done(cmd);
}
static void complete_scsi_command(struct CommandList *cp)
{
struct scsi_cmnd *cmd;
struct ctlr_info *h;
struct ErrorInfo *ei;
struct hpsa_scsi_dev_t *dev;
unsigned char sense_key;
unsigned char asc;
unsigned char ascq;
unsigned long sense_data_size;
ei = cp->err_info;
cmd = (struct scsi_cmnd *) cp->scsi_cmd;
h = cp->h;
dev = cmd->device->hostdata;
scsi_dma_unmap(cmd);
if ((cp->cmd_type == CMD_SCSI) &&
(cp->Header.SGTotal > h->max_cmd_sg_entries))
hpsa_unmap_sg_chain_block(h, cp);
cmd->result = (DID_OK << 16);
cmd->result |= (COMMAND_COMPLETE << 8);
if (cp->cmd_type == CMD_IOACCEL2)
return process_ioaccel2_completion(h, cp, cmd, dev);
cmd->result |= ei->ScsiStatus;
scsi_set_resid(cmd, ei->ResidualCnt);
if (ei->CommandStatus == 0) {
cmd_free(h, cp);
cmd->scsi_done(cmd);
return;
}
if (SCSI_SENSE_BUFFERSIZE < sizeof(ei->SenseInfo))
sense_data_size = SCSI_SENSE_BUFFERSIZE;
else
sense_data_size = sizeof(ei->SenseInfo);
if (ei->SenseLen < sense_data_size)
sense_data_size = ei->SenseLen;
memcpy(cmd->sense_buffer, ei->SenseInfo, sense_data_size);
if (cp->cmd_type == CMD_IOACCEL1) {
struct io_accel1_cmd *c = &h->ioaccel_cmd_pool[cp->cmdindex];
cp->Header.SGList = cp->Header.SGTotal = scsi_sg_count(cmd);
cp->Request.CDBLen = c->io_flags & IOACCEL1_IOFLAGS_CDBLEN_MASK;
cp->Header.Tag.lower = c->Tag.lower;
cp->Header.Tag.upper = c->Tag.upper;
memcpy(cp->Header.LUN.LunAddrBytes, c->CISS_LUN, 8);
memcpy(cp->Request.CDB, c->CDB, cp->Request.CDBLen);
if (is_logical_dev_addr_mode(dev->scsi3addr)) {
if (ei->CommandStatus == CMD_IOACCEL_DISABLED)
dev->offload_enabled = 0;
cmd->result = DID_SOFT_ERROR << 16;
cmd_free(h, cp);
cmd->scsi_done(cmd);
return;
}
}
switch (ei->CommandStatus) {
case CMD_TARGET_STATUS:
if (ei->ScsiStatus) {
sense_key = 0xf & ei->SenseInfo[2];
asc = ei->SenseInfo[12];
ascq = ei->SenseInfo[13];
}
if (ei->ScsiStatus == SAM_STAT_CHECK_CONDITION) {
if (check_for_unit_attention(h, cp))
break;
if (sense_key == ILLEGAL_REQUEST) {
if (cp->Request.CDB[0] == REPORT_LUNS)
break;
if ((asc == 0x25) && (ascq == 0x0)) {
dev_warn(&h->pdev->dev, "cp %p "
"has check condition\n", cp);
break;
}
}
if (sense_key == NOT_READY) {
if ((asc == 0x04) && (ascq == 0x03)) {
dev_warn(&h->pdev->dev, "cp %p "
"has check condition: unit "
"not ready, manual "
"intervention required\n", cp);
break;
}
}
if (sense_key == ABORTED_COMMAND) {
dev_warn(&h->pdev->dev, "cp %p "
"has check condition: aborted command: "
"ASC: 0x%x, ASCQ: 0x%x\n",
cp, asc, ascq);
cmd->result |= DID_SOFT_ERROR << 16;
break;
}
dev_dbg(&h->pdev->dev, "cp %p has check condition: "
"unknown type: "
"Sense: 0x%x, ASC: 0x%x, ASCQ: 0x%x, "
"Returning result: 0x%x, "
"cmd=[%02x %02x %02x %02x %02x "
"%02x %02x %02x %02x %02x %02x "
"%02x %02x %02x %02x %02x]\n",
cp, sense_key, asc, ascq,
cmd->result,
cmd->cmnd[0], cmd->cmnd[1],
cmd->cmnd[2], cmd->cmnd[3],
cmd->cmnd[4], cmd->cmnd[5],
cmd->cmnd[6], cmd->cmnd[7],
cmd->cmnd[8], cmd->cmnd[9],
cmd->cmnd[10], cmd->cmnd[11],
cmd->cmnd[12], cmd->cmnd[13],
cmd->cmnd[14], cmd->cmnd[15]);
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
dev_warn(&h->pdev->dev, "cp %p has"
" completed with data overrun "
"reported\n", cp);
break;
case CMD_INVALID: {
cmd->result = DID_NO_CONNECT << 16;
}
break;
case CMD_PROTOCOL_ERR:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "cp %p has "
"protocol error\n", cp);
break;
case CMD_HARDWARE_ERR:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "cp %p had hardware error\n", cp);
break;
case CMD_CONNECTION_LOST:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "cp %p had connection lost\n", cp);
break;
case CMD_ABORTED:
cmd->result = DID_ABORT << 16;
dev_warn(&h->pdev->dev, "cp %p was aborted with status 0x%x\n",
cp, ei->ScsiStatus);
break;
case CMD_ABORT_FAILED:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "cp %p reports abort failed\n", cp);
break;
case CMD_UNSOLICITED_ABORT:
cmd->result = DID_SOFT_ERROR << 16;
dev_warn(&h->pdev->dev, "cp %p aborted due to an unsolicited "
"abort\n", cp);
break;
case CMD_TIMEOUT:
cmd->result = DID_TIME_OUT << 16;
dev_warn(&h->pdev->dev, "cp %p timedout\n", cp);
break;
case CMD_UNABORTABLE:
cmd->result = DID_ERROR << 16;
dev_warn(&h->pdev->dev, "Command unabortable\n");
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
cmd_free(h, cp);
cmd->scsi_done(cmd);
}
static void hpsa_pci_unmap(struct pci_dev *pdev,
struct CommandList *c, int sg_used, int data_direction)
{
int i;
union u64bit addr64;
for (i = 0; i < sg_used; i++) {
addr64.val32.lower = c->SG[i].Addr.lower;
addr64.val32.upper = c->SG[i].Addr.upper;
pci_unmap_single(pdev, (dma_addr_t) addr64.val, c->SG[i].Len,
data_direction);
}
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
cp->Header.SGTotal = 0;
return 0;
}
addr64 = (u64) pci_map_single(pdev, buf, buflen, data_direction);
if (dma_mapping_error(&pdev->dev, addr64)) {
cp->Header.SGList = 0;
cp->Header.SGTotal = 0;
return -1;
}
cp->SG[0].Addr.lower =
(u32) (addr64 & (u64) 0x00000000FFFFFFFF);
cp->SG[0].Addr.upper =
(u32) ((addr64 >> 32) & (u64) 0x00000000FFFFFFFF);
cp->SG[0].Len = buflen;
cp->SG[0].Ext = HPSA_SG_LAST;
cp->Header.SGList = (u8) 1;
cp->Header.SGTotal = (u16) 1;
return 0;
}
static inline void hpsa_scsi_do_simple_cmd_core(struct ctlr_info *h,
struct CommandList *c)
{
DECLARE_COMPLETION_ONSTACK(wait);
c->waiting = &wait;
enqueue_cmd_and_start_io(h, c);
wait_for_completion(&wait);
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
static void hpsa_scsi_do_simple_cmd_core_if_no_lockup(struct ctlr_info *h,
struct CommandList *c)
{
if (unlikely(lockup_detected(h)))
c->err_info->CommandStatus = CMD_HARDWARE_ERR;
else
hpsa_scsi_do_simple_cmd_core(h, c);
}
static void hpsa_scsi_do_simple_cmd_with_retry(struct ctlr_info *h,
struct CommandList *c, int data_direction)
{
int backoff_time = 10, retry_count = 0;
do {
memset(c->err_info, 0, sizeof(*c->err_info));
hpsa_scsi_do_simple_cmd_core(h, c);
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
const u8 *sd = ei->SenseInfo;
switch (ei->CommandStatus) {
case CMD_TARGET_STATUS:
hpsa_print_cmd(h, "SCSI status", cp);
if (ei->ScsiStatus == SAM_STAT_CHECK_CONDITION)
dev_warn(d, "SCSI Status = 02, Sense key = %02x, ASC = %02x, ASCQ = %02x\n",
sd[2] & 0x0f, sd[12], sd[13]);
else
dev_warn(d, "SCSI Status = %02x\n", ei->ScsiStatus);
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
c = cmd_special_alloc(h);
if (c == NULL) {
dev_warn(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
return -ENOMEM;
}
if (fill_cmd(c, HPSA_INQUIRY, h, buf, bufsize,
page, scsi3addr, TYPE_CMD)) {
rc = -1;
goto out;
}
hpsa_scsi_do_simple_cmd_with_retry(h, c, PCI_DMA_FROMDEVICE);
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_special_free(h, c);
return rc;
}
static int hpsa_bmic_ctrl_mode_sense(struct ctlr_info *h,
unsigned char *scsi3addr, unsigned char page,
struct bmic_controller_parameters *buf, size_t bufsize)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_special_alloc(h);
if (c == NULL) {
dev_warn(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
return -ENOMEM;
}
if (fill_cmd(c, BMIC_SENSE_CONTROLLER_PARAMETERS, h, buf, bufsize,
page, scsi3addr, TYPE_CMD)) {
rc = -1;
goto out;
}
hpsa_scsi_do_simple_cmd_with_retry(h, c, PCI_DMA_FROMDEVICE);
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
out:
cmd_special_free(h, c);
return rc;
}
static int hpsa_send_reset(struct ctlr_info *h, unsigned char *scsi3addr,
u8 reset_type)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
c = cmd_special_alloc(h);
if (c == NULL) {
dev_warn(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
return -ENOMEM;
}
(void) fill_cmd(c, HPSA_DEVICE_RESET_MSG, h, NULL, 0, 0,
scsi3addr, TYPE_MSG);
c->Request.CDB[1] = reset_type;
hpsa_scsi_do_simple_cmd_core(h, c);
ei = c->err_info;
if (ei->CommandStatus != 0) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
}
cmd_special_free(h, c);
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
dev_info(&h->pdev->dev, "flags = %u\n",
le16_to_cpu(map_buff->flags));
if (map_buff->flags & RAID_MAP_FLAG_ENCRYPT_ON)
dev_info(&h->pdev->dev, "encrypytion = ON\n");
else
dev_info(&h->pdev->dev, "encrypytion = OFF\n");
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
c = cmd_special_alloc(h);
if (c == NULL) {
dev_warn(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
return -ENOMEM;
}
if (fill_cmd(c, HPSA_GET_RAID_MAP, h, &this_device->raid_map,
sizeof(this_device->raid_map), 0,
scsi3addr, TYPE_CMD)) {
dev_warn(&h->pdev->dev, "Out of memory in hpsa_get_raid_map()\n");
cmd_special_free(h, c);
return -ENOMEM;
}
hpsa_scsi_do_simple_cmd_with_retry(h, c, PCI_DMA_FROMDEVICE);
ei = c->err_info;
if (ei->CommandStatus != 0 && ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
cmd_special_free(h, c);
return -1;
}
cmd_special_free(h, c);
if (le32_to_cpu(this_device->raid_map.structure_size) >
sizeof(this_device->raid_map)) {
dev_warn(&h->pdev->dev, "RAID map size is too large!\n");
rc = -1;
}
hpsa_debug_map_buff(h, rc, &this_device->raid_map);
return rc;
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
out:
kfree(buf);
return;
}
static int hpsa_get_device_id(struct ctlr_info *h, unsigned char *scsi3addr,
unsigned char *device_id, int buflen)
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
memcpy(device_id, &buf[8], buflen);
kfree(buf);
return rc != 0;
}
static int hpsa_scsi_do_report_luns(struct ctlr_info *h, int logical,
struct ReportLUNdata *buf, int bufsize,
int extended_response)
{
int rc = IO_OK;
struct CommandList *c;
unsigned char scsi3addr[8];
struct ErrorInfo *ei;
c = cmd_special_alloc(h);
if (c == NULL) {
dev_err(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
return -1;
}
memset(scsi3addr, 0, sizeof(scsi3addr));
if (fill_cmd(c, logical ? HPSA_REPORT_LOG : HPSA_REPORT_PHYS, h,
buf, bufsize, 0, scsi3addr, TYPE_CMD)) {
rc = -1;
goto out;
}
if (extended_response)
c->Request.CDB[1] = extended_response;
hpsa_scsi_do_simple_cmd_with_retry(h, c, PCI_DMA_FROMDEVICE);
ei = c->err_info;
if (ei->CommandStatus != 0 &&
ei->CommandStatus != CMD_DATA_UNDERRUN) {
hpsa_scsi_interpret_error(h, c);
rc = -1;
} else {
if (buf->extended_response_flag != extended_response) {
dev_err(&h->pdev->dev,
"report luns requested format %u, got %u\n",
extended_response,
buf->extended_response_flag);
rc = -1;
}
}
out:
cmd_special_free(h, c);
return rc;
}
static inline int hpsa_scsi_do_report_phys_luns(struct ctlr_info *h,
struct ReportLUNdata *buf,
int bufsize, int extended_response)
{
return hpsa_scsi_do_report_luns(h, 0, buf, bufsize, extended_response);
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
unsigned char *sense, sense_key, asc, ascq;
int ldstat = 0;
u16 cmd_status;
u8 scsi_status;
#define ASC_LUN_NOT_READY 0x04
#define ASCQ_LUN_NOT_READY_FORMAT_IN_PROGRESS 0x04
#define ASCQ_LUN_NOT_READY_INITIALIZING_CMD_REQ 0x02
c = cmd_alloc(h);
if (!c)
return 0;
(void) fill_cmd(c, TEST_UNIT_READY, h, NULL, 0, 0, scsi3addr, TYPE_CMD);
hpsa_scsi_do_simple_cmd_core(h, c);
sense = c->err_info->SenseInfo;
sense_key = sense[2];
asc = sense[12];
ascq = sense[13];
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
inq_buff = kzalloc(OBDR_TAPE_INQ_SIZE, GFP_KERNEL);
if (!inq_buff)
goto bail_out;
if (hpsa_scsi_do_inquiry(h, scsi3addr, 0, inq_buff,
(unsigned char) OBDR_TAPE_INQ_SIZE) != 0) {
dev_err(&h->pdev->dev,
"hpsa_update_device_info: inquiry failed\n");
goto bail_out;
}
this_device->devtype = (inq_buff[0] & 0x1f);
memcpy(this_device->scsi3addr, scsi3addr, 8);
memcpy(this_device->vendor, &inq_buff[8],
sizeof(this_device->vendor));
memcpy(this_device->model, &inq_buff[16],
sizeof(this_device->model));
memset(this_device->device_id, 0,
sizeof(this_device->device_id));
hpsa_get_device_id(h, scsi3addr, this_device->device_id,
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
this_device->volume_offline = 0;
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
return 1;
}
static int is_ext_target(struct ctlr_info *h, struct hpsa_scsi_dev_t *device)
{
int i;
for (i = 0; ext_target_model[i]; i++)
if (strncmp(device->model, ext_target_model[i],
strlen(ext_target_model[i])) == 0)
return 1;
return 0;
}
static void figure_bus_target_lun(struct ctlr_info *h,
u8 *lunaddrbytes, struct hpsa_scsi_dev_t *device)
{
u32 lunid = le32_to_cpu(*((__le32 *) lunaddrbytes));
if (!is_logical_dev_addr_mode(lunaddrbytes)) {
if (is_hba_lunid(lunaddrbytes))
hpsa_set_bus_target_lun(device, 3, 0, lunid & 0x3fff);
else
hpsa_set_bus_target_lun(device, 2, -1, -1);
return;
}
if (is_ext_target(h, device)) {
hpsa_set_bus_target_lun(device,
1, (lunid >> 16) & 0x3fff, lunid & 0x00ff);
return;
}
hpsa_set_bus_target_lun(device, 0, 0, lunid & 0x3fff);
}
static int add_ext_target_dev(struct ctlr_info *h,
struct hpsa_scsi_dev_t *tmpdevice,
struct hpsa_scsi_dev_t *this_device, u8 *lunaddrbytes,
unsigned long lunzerobits[], int *n_ext_target_devs)
{
unsigned char scsi3addr[8];
if (test_bit(tmpdevice->target, lunzerobits))
return 0;
if (!is_logical_dev_addr_mode(lunaddrbytes))
return 0;
if (!is_ext_target(h, tmpdevice))
return 0;
if (tmpdevice->lun == 0)
return 0;
memset(scsi3addr, 0, 8);
scsi3addr[3] = tmpdevice->target;
if (is_hba_lunid(scsi3addr))
return 0;
if (is_scsi_rev_5(h))
return 0;
if (*n_ext_target_devs >= MAX_EXT_TARGETS) {
dev_warn(&h->pdev->dev, "Maximum number of external "
"target devices exceeded. Check your hardware "
"configuration.");
return 0;
}
if (hpsa_update_device_info(h, scsi3addr, this_device, NULL))
return 0;
(*n_ext_target_devs)++;
hpsa_set_bus_target_lun(this_device,
tmpdevice->bus, tmpdevice->target, 0);
set_bit(tmpdevice->target, lunzerobits);
return 1;
}
static int hpsa_get_pdisk_of_ioaccel2(struct ctlr_info *h,
struct CommandList *ioaccel2_cmd_to_abort, unsigned char *scsi3addr)
{
struct ReportExtendedLUNdata *physicals = NULL;
int responsesize = 24;
int extended = 2;
int reportsize = sizeof(*physicals) + HPSA_MAX_PHYS_LUN * responsesize;
u32 nphysicals = 0;
int found = 0;
u32 find;
int i;
struct scsi_cmnd *scmd;
struct hpsa_scsi_dev_t *d;
struct io_accel2_cmd *c2a;
u32 it_nexus;
u32 scsi_nexus;
if (ioaccel2_cmd_to_abort->cmd_type != CMD_IOACCEL2)
return 0;
c2a = &h->ioaccel2_cmd_pool[ioaccel2_cmd_to_abort->cmdindex];
if (c2a == NULL)
return 0;
scmd = (struct scsi_cmnd *) ioaccel2_cmd_to_abort->scsi_cmd;
if (scmd == NULL)
return 0;
d = scmd->device->hostdata;
if (d == NULL)
return 0;
it_nexus = cpu_to_le32((u32) d->ioaccel_handle);
scsi_nexus = cpu_to_le32((u32) c2a->scsi_nexus);
find = c2a->scsi_nexus;
if (h->raid_offload_debug > 0)
dev_info(&h->pdev->dev,
"%s: scsi_nexus:0x%08x device id: 0x%02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x\n",
__func__, scsi_nexus,
d->device_id[0], d->device_id[1], d->device_id[2],
d->device_id[3], d->device_id[4], d->device_id[5],
d->device_id[6], d->device_id[7], d->device_id[8],
d->device_id[9], d->device_id[10], d->device_id[11],
d->device_id[12], d->device_id[13], d->device_id[14],
d->device_id[15]);
physicals = kzalloc(reportsize, GFP_KERNEL);
if (physicals == NULL)
return 0;
if (hpsa_scsi_do_report_phys_luns(h, (struct ReportLUNdata *) physicals,
reportsize, extended)) {
dev_err(&h->pdev->dev,
"Can't lookup %s device handle: report physical LUNs failed.\n",
"HP SSD Smart Path");
kfree(physicals);
return 0;
}
nphysicals = be32_to_cpu(*((__be32 *)physicals->LUNListLength)) /
responsesize;
for (i = 0; i < nphysicals; i++) {
struct ext_report_lun_entry *entry = &physicals->LUN[i];
if (entry->ioaccel_handle != find)
continue;
found = 1;
memcpy(scsi3addr, entry->lunid, 8);
if (h->raid_offload_debug > 0)
dev_info(&h->pdev->dev,
"%s: Searched h=0x%08x, Found h=0x%08x, scsiaddr 0x%8phN\n",
__func__, find,
entry->ioaccel_handle, scsi3addr);
break;
}
kfree(physicals);
if (found)
return 1;
else
return 0;
}
static int hpsa_gather_lun_info(struct ctlr_info *h,
int reportlunsize,
struct ReportLUNdata *physdev, u32 *nphysicals, int *physical_mode,
struct ReportLUNdata *logdev, u32 *nlogicals)
{
int physical_entry_size = 8;
*physical_mode = 0;
if (h->transMethod & CFGTBL_Trans_io_accel1 ||
h->transMethod & CFGTBL_Trans_io_accel2) {
*physical_mode = HPSA_REPORT_PHYS_EXTENDED;
physical_entry_size = 24;
}
if (hpsa_scsi_do_report_phys_luns(h, physdev, reportlunsize,
*physical_mode)) {
dev_err(&h->pdev->dev, "report physical LUNs failed.\n");
return -1;
}
*nphysicals = be32_to_cpu(*((__be32 *)physdev->LUNListLength)) /
physical_entry_size;
if (*nphysicals > HPSA_MAX_PHYS_LUN) {
dev_warn(&h->pdev->dev, "maximum physical LUNs (%d) exceeded."
" %d LUNs ignored.\n", HPSA_MAX_PHYS_LUN,
*nphysicals - HPSA_MAX_PHYS_LUN);
*nphysicals = HPSA_MAX_PHYS_LUN;
}
if (hpsa_scsi_do_report_log_luns(h, logdev, reportlunsize)) {
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
u8 *figure_lunaddrbytes(struct ctlr_info *h, int raid_ctlr_position, int i,
int nphysicals, int nlogicals,
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
static int hpsa_hba_mode_enabled(struct ctlr_info *h)
{
int rc;
int hba_mode_enabled;
struct bmic_controller_parameters *ctlr_params;
ctlr_params = kzalloc(sizeof(struct bmic_controller_parameters),
GFP_KERNEL);
if (!ctlr_params)
return -ENOMEM;
rc = hpsa_bmic_ctrl_mode_sense(h, RAID_CTLR_LUNID, 0, ctlr_params,
sizeof(struct bmic_controller_parameters));
if (rc) {
kfree(ctlr_params);
return rc;
}
hba_mode_enabled =
((ctlr_params->nvram_flags & HBA_MODE_ENABLED_FLAG) != 0);
kfree(ctlr_params);
return hba_mode_enabled;
}
static void hpsa_update_scsi_devices(struct ctlr_info *h, int hostno)
{
struct ReportExtendedLUNdata *physdev_list = NULL;
struct ReportLUNdata *logdev_list = NULL;
u32 nphysicals = 0;
u32 nlogicals = 0;
int physical_mode = 0;
u32 ndev_allocated = 0;
struct hpsa_scsi_dev_t **currentsd, *this_device, *tmpdevice;
int ncurrent = 0;
int reportlunsize = sizeof(*physdev_list) + HPSA_MAX_PHYS_LUN * 24;
int i, n_ext_target_devs, ndevs_to_allocate;
int raid_ctlr_position;
int rescan_hba_mode;
DECLARE_BITMAP(lunzerobits, MAX_EXT_TARGETS);
currentsd = kzalloc(sizeof(*currentsd) * HPSA_MAX_DEVICES, GFP_KERNEL);
physdev_list = kzalloc(reportlunsize, GFP_KERNEL);
logdev_list = kzalloc(reportlunsize, GFP_KERNEL);
tmpdevice = kzalloc(sizeof(*tmpdevice), GFP_KERNEL);
if (!currentsd || !physdev_list || !logdev_list || !tmpdevice) {
dev_err(&h->pdev->dev, "out of memory\n");
goto out;
}
memset(lunzerobits, 0, sizeof(lunzerobits));
rescan_hba_mode = hpsa_hba_mode_enabled(h);
if (rescan_hba_mode < 0)
goto out;
if (!h->hba_mode_enabled && rescan_hba_mode)
dev_warn(&h->pdev->dev, "HBA mode enabled\n");
else if (h->hba_mode_enabled && !rescan_hba_mode)
dev_warn(&h->pdev->dev, "HBA mode disabled\n");
h->hba_mode_enabled = rescan_hba_mode;
if (hpsa_gather_lun_info(h, reportlunsize,
(struct ReportLUNdata *) physdev_list, &nphysicals,
&physical_mode, logdev_list, &nlogicals))
goto out;
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
lunaddrbytes = figure_lunaddrbytes(h, raid_ctlr_position,
i, nphysicals, nlogicals, physdev_list, logdev_list);
if (lunaddrbytes[3] & 0xC0 &&
i < nphysicals + (raid_ctlr_position == 0))
continue;
if (hpsa_update_device_info(h, lunaddrbytes, tmpdevice,
&is_OBDR))
continue;
figure_bus_target_lun(h, lunaddrbytes, tmpdevice);
this_device = currentsd[ncurrent];
if (add_ext_target_dev(h, tmpdevice, this_device,
lunaddrbytes, lunzerobits,
&n_ext_target_devs)) {
ncurrent++;
this_device = currentsd[ncurrent];
}
*this_device = *tmpdevice;
switch (this_device->devtype) {
case TYPE_ROM:
if (is_OBDR)
ncurrent++;
break;
case TYPE_DISK:
if (h->hba_mode_enabled) {
this_device->offload_enabled = 0;
ncurrent++;
break;
} else if (h->acciopath_status) {
if (i >= nphysicals) {
ncurrent++;
break;
}
} else {
if (i < nphysicals)
break;
ncurrent++;
break;
}
if (physical_mode == HPSA_REPORT_PHYS_EXTENDED) {
memcpy(&this_device->ioaccel_handle,
&lunaddrbytes[20],
sizeof(this_device->ioaccel_handle));
ncurrent++;
}
break;
case TYPE_TAPE:
case TYPE_MEDIUM_CHANGER:
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
adjust_hpsa_scsi_table(h, hostno, currentsd, ncurrent);
out:
kfree(tmpdevice);
for (i = 0; i < ndev_allocated; i++)
kfree(currentsd[i]);
kfree(currentsd);
kfree(physdev_list);
kfree(logdev_list);
}
static int hpsa_scatter_gather(struct ctlr_info *h,
struct CommandList *cp,
struct scsi_cmnd *cmd)
{
unsigned int len;
struct scatterlist *sg;
u64 addr64;
int use_sg, i, sg_index, chained;
struct SGDescriptor *curr_sg;
BUG_ON(scsi_sg_count(cmd) > h->maxsgentries);
use_sg = scsi_dma_map(cmd);
if (use_sg < 0)
return use_sg;
if (!use_sg)
goto sglist_finished;
curr_sg = cp->SG;
chained = 0;
sg_index = 0;
scsi_for_each_sg(cmd, sg, use_sg, i) {
if (i == h->max_cmd_sg_entries - 1 &&
use_sg > h->max_cmd_sg_entries) {
chained = 1;
curr_sg = h->cmd_sg_list[cp->cmdindex];
sg_index = 0;
}
addr64 = (u64) sg_dma_address(sg);
len = sg_dma_len(sg);
curr_sg->Addr.lower = (u32) (addr64 & 0x0FFFFFFFFULL);
curr_sg->Addr.upper = (u32) ((addr64 >> 32) & 0x0FFFFFFFFULL);
curr_sg->Len = len;
curr_sg->Ext = (i < scsi_sg_count(cmd) - 1) ? 0 : HPSA_SG_LAST;
curr_sg++;
}
if (use_sg + chained > h->maxSG)
h->maxSG = use_sg + chained;
if (chained) {
cp->Header.SGList = h->max_cmd_sg_entries;
cp->Header.SGTotal = (u16) (use_sg + 1);
if (hpsa_map_sg_chain_block(h, cp)) {
scsi_dma_unmap(cmd);
return -1;
}
return 0;
}
sglist_finished:
cp->Header.SGList = (u8) use_sg;
cp->Header.SGTotal = (u16) use_sg;
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
block = (((u32) cdb[2]) << 8) | cdb[3];
block_cnt = cdb[4];
} else {
BUG_ON(*cdb_len != 12);
block = (((u32) cdb[2]) << 24) |
(((u32) cdb[3]) << 16) |
(((u32) cdb[4]) << 8) |
cdb[5];
block_cnt =
(((u32) cdb[6]) << 24) |
(((u32) cdb[7]) << 16) |
(((u32) cdb[8]) << 8) |
cdb[9];
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
u8 *scsi3addr)
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
if (scsi_sg_count(cmd) > h->ioaccel_maxsg)
return IO_ACCEL_INELIGIBLE;
BUG_ON(cmd->cmd_len > IOACCEL1_IOFLAGS_CDBLEN_MAX);
if (fixup_ioaccel_cdb(cdb, &cdb_len))
return IO_ACCEL_INELIGIBLE;
c->cmd_type = CMD_IOACCEL1;
c->busaddr = (u32) h->ioaccel_cmd_pool_dhandle +
(c->cmdindex * sizeof(*cp));
BUG_ON(c->busaddr & 0x0000007F);
use_sg = scsi_dma_map(cmd);
if (use_sg < 0)
return use_sg;
if (use_sg) {
curr_sg = cp->SG;
scsi_for_each_sg(cmd, sg, use_sg, i) {
addr64 = (u64) sg_dma_address(sg);
len = sg_dma_len(sg);
total_len += len;
curr_sg->Addr.lower = (u32) (addr64 & 0x0FFFFFFFFULL);
curr_sg->Addr.upper =
(u32) ((addr64 >> 32) & 0x0FFFFFFFFULL);
curr_sg->Len = len;
if (i == (scsi_sg_count(cmd) - 1))
curr_sg->Ext = HPSA_SG_LAST;
else
curr_sg->Ext = 0;
curr_sg++;
}
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
cp->dev_handle = ioaccel_handle & 0xFFFF;
cp->transfer_len = total_len;
cp->io_flags = IOACCEL1_IOFLAGS_IO_REQ |
(cdb_len & IOACCEL1_IOFLAGS_CDBLEN_MASK);
cp->control = control;
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
return hpsa_scsi_ioaccel_queue_command(h, c, dev->ioaccel_handle,
cmd->cmnd, cmd->cmd_len, dev->scsi3addr);
}
static void set_encrypt_ioaccel2(struct ctlr_info *h,
struct CommandList *c, struct io_accel2_cmd *cp)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct hpsa_scsi_dev_t *dev = cmd->device->hostdata;
struct raid_map_data *map = &dev->raid_map;
u64 first_block;
BUG_ON(!(dev->offload_config && dev->offload_enabled));
if (!(map->flags & RAID_MAP_FLAG_ENCRYPT_ON))
return;
cp->dekindex = map->dekindex;
cp->direction |= IOACCEL2_DIRECTION_ENCRYPT_MASK;
switch (cmd->cmnd[0]) {
case WRITE_6:
case READ_6:
if (map->volume_blk_size == 512) {
cp->tweak_lower =
(((u32) cmd->cmnd[2]) << 8) |
cmd->cmnd[3];
cp->tweak_upper = 0;
} else {
first_block =
(((u64) cmd->cmnd[2]) << 8) |
cmd->cmnd[3];
first_block = (first_block * map->volume_blk_size)/512;
cp->tweak_lower = (u32)first_block;
cp->tweak_upper = (u32)(first_block >> 32);
}
break;
case WRITE_10:
case READ_10:
if (map->volume_blk_size == 512) {
cp->tweak_lower =
(((u32) cmd->cmnd[2]) << 24) |
(((u32) cmd->cmnd[3]) << 16) |
(((u32) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
cp->tweak_upper = 0;
} else {
first_block =
(((u64) cmd->cmnd[2]) << 24) |
(((u64) cmd->cmnd[3]) << 16) |
(((u64) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
first_block = (first_block * map->volume_blk_size)/512;
cp->tweak_lower = (u32)first_block;
cp->tweak_upper = (u32)(first_block >> 32);
}
break;
case WRITE_12:
case READ_12:
if (map->volume_blk_size == 512) {
cp->tweak_lower =
(((u32) cmd->cmnd[2]) << 24) |
(((u32) cmd->cmnd[3]) << 16) |
(((u32) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
cp->tweak_upper = 0;
} else {
first_block =
(((u64) cmd->cmnd[2]) << 24) |
(((u64) cmd->cmnd[3]) << 16) |
(((u64) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
first_block = (first_block * map->volume_blk_size)/512;
cp->tweak_lower = (u32)first_block;
cp->tweak_upper = (u32)(first_block >> 32);
}
break;
case WRITE_16:
case READ_16:
if (map->volume_blk_size == 512) {
cp->tweak_lower =
(((u32) cmd->cmnd[6]) << 24) |
(((u32) cmd->cmnd[7]) << 16) |
(((u32) cmd->cmnd[8]) << 8) |
cmd->cmnd[9];
cp->tweak_upper =
(((u32) cmd->cmnd[2]) << 24) |
(((u32) cmd->cmnd[3]) << 16) |
(((u32) cmd->cmnd[4]) << 8) |
cmd->cmnd[5];
} else {
first_block =
(((u64) cmd->cmnd[2]) << 56) |
(((u64) cmd->cmnd[3]) << 48) |
(((u64) cmd->cmnd[4]) << 40) |
(((u64) cmd->cmnd[5]) << 32) |
(((u64) cmd->cmnd[6]) << 24) |
(((u64) cmd->cmnd[7]) << 16) |
(((u64) cmd->cmnd[8]) << 8) |
cmd->cmnd[9];
first_block = (first_block * map->volume_blk_size)/512;
cp->tweak_lower = (u32)first_block;
cp->tweak_upper = (u32)(first_block >> 32);
}
break;
default:
dev_err(&h->pdev->dev,
"ERROR: %s: IOACCEL request CDB size not supported for encryption\n",
__func__);
BUG();
break;
}
}
static int hpsa_scsi_ioaccel2_queue_command(struct ctlr_info *h,
struct CommandList *c, u32 ioaccel_handle, u8 *cdb, int cdb_len,
u8 *scsi3addr)
{
struct scsi_cmnd *cmd = c->scsi_cmd;
struct io_accel2_cmd *cp = &h->ioaccel2_cmd_pool[c->cmdindex];
struct ioaccel2_sg_element *curr_sg;
int use_sg, i;
struct scatterlist *sg;
u64 addr64;
u32 len;
u32 total_len = 0;
if (scsi_sg_count(cmd) > h->ioaccel_maxsg)
return IO_ACCEL_INELIGIBLE;
if (fixup_ioaccel_cdb(cdb, &cdb_len))
return IO_ACCEL_INELIGIBLE;
c->cmd_type = CMD_IOACCEL2;
c->busaddr = (u32) h->ioaccel2_cmd_pool_dhandle +
(c->cmdindex * sizeof(*cp));
BUG_ON(c->busaddr & 0x0000007F);
memset(cp, 0, sizeof(*cp));
cp->IU_type = IOACCEL2_IU_TYPE;
use_sg = scsi_dma_map(cmd);
if (use_sg < 0)
return use_sg;
if (use_sg) {
BUG_ON(use_sg > IOACCEL2_MAXSGENTRIES);
curr_sg = cp->sg;
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
cp->scsi_nexus = ioaccel_handle;
cp->Tag = (c->cmdindex << DIRECT_LOOKUP_SHIFT) |
DIRECT_LOOKUP_BIT;
memcpy(cp->cdb, cdb, sizeof(cp->cdb));
cp->sg_count = (u8) use_sg;
cp->data_len = cpu_to_le32(total_len);
cp->err_ptr = cpu_to_le64(c->busaddr +
offsetof(struct io_accel2_cmd, error_data));
cp->err_len = cpu_to_le32((u32) sizeof(cp->error_data));
enqueue_cmd_and_start_io(h, c);
return 0;
}
static int hpsa_scsi_ioaccel_queue_command(struct ctlr_info *h,
struct CommandList *c, u32 ioaccel_handle, u8 *cdb, int cdb_len,
u8 *scsi3addr)
{
if (h->transMethod & CFGTBL_Trans_io_accel1)
return hpsa_scsi_ioaccel1_queue_command(h, c, ioaccel_handle,
cdb, cdb_len, scsi3addr);
else
return hpsa_scsi_ioaccel2_queue_command(h, c, ioaccel_handle,
cdb, cdb_len, scsi3addr);
}
static void raid_map_helper(struct raid_map_data *map,
int offload_to_mirror, u32 *map_index, u32 *current_group)
{
if (offload_to_mirror == 0) {
*map_index %= map->data_disks_per_row;
return;
}
do {
*current_group = *map_index / map->data_disks_per_row;
if (offload_to_mirror == *current_group)
continue;
if (*current_group < (map->layout_map_count - 1)) {
*map_index += map->data_disks_per_row;
(*current_group)++;
} else {
*map_index %= map->data_disks_per_row;
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
#if BITS_PER_LONG == 32
u64 tmpdiv;
#endif
int offload_to_mirror;
BUG_ON(!(dev->offload_config && dev->offload_enabled));
switch (cmd->cmnd[0]) {
case WRITE_6:
is_write = 1;
case READ_6:
first_block =
(((u64) cmd->cmnd[2]) << 8) |
cmd->cmnd[3];
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
if (last_block >= map->volume_blk_cnt || last_block < first_block)
return IO_ACCEL_INELIGIBLE;
blocks_per_row = map->data_disks_per_row * map->strip_size;
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
(void) do_div(tmpdiv, map->strip_size);
first_column = tmpdiv;
tmpdiv = last_row_offset;
(void) do_div(tmpdiv, map->strip_size);
last_column = tmpdiv;
#else
first_row = first_block / blocks_per_row;
last_row = last_block / blocks_per_row;
first_row_offset = (u32) (first_block - (first_row * blocks_per_row));
last_row_offset = (u32) (last_block - (last_row * blocks_per_row));
first_column = first_row_offset / map->strip_size;
last_column = last_row_offset / map->strip_size;
#endif
if ((first_row != last_row) || (first_column != last_column))
return IO_ACCEL_INELIGIBLE;
total_disks_per_row = map->data_disks_per_row +
map->metadata_disks_per_row;
map_row = ((u32)(first_row >> map->parity_rotation_shift)) %
map->row_cnt;
map_index = (map_row * total_disks_per_row) + first_column;
switch (dev->raid_level) {
case HPSA_RAID_0:
break;
case HPSA_RAID_1:
BUG_ON(map->layout_map_count != 2);
if (dev->offload_to_mirror)
map_index += map->data_disks_per_row;
dev->offload_to_mirror = !dev->offload_to_mirror;
break;
case HPSA_RAID_ADM:
BUG_ON(map->layout_map_count != 3);
offload_to_mirror = dev->offload_to_mirror;
raid_map_helper(map, offload_to_mirror,
&map_index, &current_group);
offload_to_mirror =
(offload_to_mirror >= map->layout_map_count - 1)
? 0 : offload_to_mirror + 1;
BUG_ON(offload_to_mirror >= map->layout_map_count);
dev_warn(&h->pdev->dev,
"DEBUG: Using physical disk map index %d from mirror group %d\n",
map_index, offload_to_mirror);
dev->offload_to_mirror = offload_to_mirror;
break;
case HPSA_RAID_5:
case HPSA_RAID_6:
if (map->layout_map_count <= 1)
break;
r5or6_blocks_per_row =
map->strip_size * map->data_disks_per_row;
BUG_ON(r5or6_blocks_per_row == 0);
stripesize = r5or6_blocks_per_row * map->layout_map_count;
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
r5or6_first_row_offset / map->strip_size;
r5or6_last_column =
r5or6_last_row_offset / map->strip_size;
#endif
if (r5or6_first_column != r5or6_last_column)
return IO_ACCEL_INELIGIBLE;
map_row = ((u32)(first_row >> map->parity_rotation_shift)) %
map->row_cnt;
map_index = (first_group *
(map->row_cnt * total_disks_per_row)) +
(map_row * total_disks_per_row) + first_column;
break;
default:
return IO_ACCEL_INELIGIBLE;
}
disk_handle = dd[map_index].ioaccel_handle;
disk_block = map->disk_starting_blk + (first_row * map->strip_size) +
(first_row_offset - (first_column * map->strip_size));
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
dev->scsi3addr);
}
static int hpsa_scsi_queue_command_lck(struct scsi_cmnd *cmd,
void (*done)(struct scsi_cmnd *))
{
struct ctlr_info *h;
struct hpsa_scsi_dev_t *dev;
unsigned char scsi3addr[8];
struct CommandList *c;
int rc = 0;
h = sdev_to_hba(cmd->device);
dev = cmd->device->hostdata;
if (!dev) {
cmd->result = DID_NO_CONNECT << 16;
done(cmd);
return 0;
}
memcpy(scsi3addr, dev->scsi3addr, sizeof(scsi3addr));
if (unlikely(lockup_detected(h))) {
cmd->result = DID_ERROR << 16;
done(cmd);
return 0;
}
c = cmd_alloc(h);
if (c == NULL) {
dev_err(&h->pdev->dev, "cmd_alloc returned NULL!\n");
return SCSI_MLQUEUE_HOST_BUSY;
}
cmd->scsi_done = done;
cmd->host_scribble = (unsigned char *) c;
c->cmd_type = CMD_SCSI;
c->scsi_cmd = cmd;
if (likely(cmd->retries == 0 &&
cmd->request->cmd_type == REQ_TYPE_FS &&
h->acciopath_status)) {
if (dev->offload_enabled) {
rc = hpsa_scsi_ioaccel_raid_map(h, c);
if (rc == 0)
return 0;
if (rc < 0) {
cmd_free(h, c);
return SCSI_MLQUEUE_HOST_BUSY;
}
} else if (dev->ioaccel_handle) {
rc = hpsa_scsi_ioaccel_direct_map(h, c);
if (rc == 0)
return 0;
if (rc < 0) {
cmd_free(h, c);
return SCSI_MLQUEUE_HOST_BUSY;
}
}
}
c->Header.ReplyQueue = 0;
memcpy(&c->Header.LUN.LunAddrBytes[0], &scsi3addr[0], 8);
c->Header.Tag.lower = (c->cmdindex << DIRECT_LOOKUP_SHIFT);
c->Header.Tag.lower |= DIRECT_LOOKUP_BIT;
c->Request.Timeout = 0;
memset(c->Request.CDB, 0, sizeof(c->Request.CDB));
BUG_ON(cmd->cmd_len > sizeof(c->Request.CDB));
c->Request.CDBLen = cmd->cmd_len;
memcpy(c->Request.CDB, cmd->cmnd, cmd->cmd_len);
c->Request.Type.Type = TYPE_CMD;
c->Request.Type.Attribute = ATTR_SIMPLE;
switch (cmd->sc_data_direction) {
case DMA_TO_DEVICE:
c->Request.Type.Direction = XFER_WRITE;
break;
case DMA_FROM_DEVICE:
c->Request.Type.Direction = XFER_READ;
break;
case DMA_NONE:
c->Request.Type.Direction = XFER_NONE;
break;
case DMA_BIDIRECTIONAL:
c->Request.Type.Direction = XFER_RSVD;
break;
default:
dev_err(&h->pdev->dev, "unknown data direction: %d\n",
cmd->sc_data_direction);
BUG();
break;
}
if (hpsa_scatter_gather(h, c, cmd) < 0) {
cmd_free(h, c);
return SCSI_MLQUEUE_HOST_BUSY;
}
enqueue_cmd_and_start_io(h, c);
return 0;
}
void hpsa_scan_start(struct Scsi_Host *sh)
{
struct ctlr_info *h = shost_to_hba(sh);
unsigned long flags;
if (do_not_scan_if_controller_locked_up(h))
return;
while (1) {
spin_lock_irqsave(&h->scan_lock, flags);
if (h->scan_finished)
break;
spin_unlock_irqrestore(&h->scan_lock, flags);
wait_event(h->scan_wait_queue, h->scan_finished);
}
h->scan_finished = 0;
spin_unlock_irqrestore(&h->scan_lock, flags);
if (do_not_scan_if_controller_locked_up(h))
return;
hpsa_update_scsi_devices(h, h->scsi_host->host_no);
spin_lock_irqsave(&h->scan_lock, flags);
h->scan_finished = 1;
wake_up_all(&h->scan_wait_queue);
spin_unlock_irqrestore(&h->scan_lock, flags);
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
static int hpsa_change_queue_depth(struct scsi_device *sdev,
int qdepth, int reason)
{
struct ctlr_info *h = sdev_to_hba(sdev);
if (reason != SCSI_QDEPTH_DEFAULT)
return -ENOTSUPP;
if (qdepth < 1)
qdepth = 1;
else
if (qdepth > h->nr_cmds)
qdepth = h->nr_cmds;
scsi_adjust_queue_depth(sdev, scsi_get_tag_type(sdev), qdepth);
return sdev->queue_depth;
}
static void hpsa_unregister_scsi(struct ctlr_info *h)
{
scsi_remove_host(h->scsi_host);
scsi_host_put(h->scsi_host);
h->scsi_host = NULL;
}
static int hpsa_register_scsi(struct ctlr_info *h)
{
struct Scsi_Host *sh;
int error;
sh = scsi_host_alloc(&hpsa_driver_template, sizeof(h));
if (sh == NULL)
goto fail;
sh->io_port = 0;
sh->n_io_port = 0;
sh->this_id = -1;
sh->max_channel = 3;
sh->max_cmd_len = MAX_COMMAND_SIZE;
sh->max_lun = HPSA_MAX_LUN;
sh->max_id = HPSA_MAX_LUN;
sh->can_queue = h->nr_cmds;
if (h->hba_mode_enabled)
sh->cmd_per_lun = 7;
else
sh->cmd_per_lun = h->nr_cmds;
sh->sg_tablesize = h->maxsgentries;
h->scsi_host = sh;
sh->hostdata[0] = (unsigned long) h;
sh->irq = h->intr[h->intr_mode];
sh->unique_id = sh->irq;
error = scsi_add_host(sh, &h->pdev->dev);
if (error)
goto fail_host_put;
scsi_scan_host(sh);
return 0;
fail_host_put:
dev_err(&h->pdev->dev, "%s: scsi_add_host"
" failed for controller %d\n", __func__, h->ctlr);
scsi_host_put(sh);
return error;
fail:
dev_err(&h->pdev->dev, "%s: scsi_host_alloc"
" failed for controller %d\n", __func__, h->ctlr);
return -ENOMEM;
}
static int wait_for_device_to_become_ready(struct ctlr_info *h,
unsigned char lunaddr[])
{
int rc;
int count = 0;
int waittime = 1;
struct CommandList *c;
c = cmd_special_alloc(h);
if (!c) {
dev_warn(&h->pdev->dev, "out of memory in "
"wait_for_device_to_become_ready.\n");
return IO_ERROR;
}
while (count < HPSA_TUR_RETRY_LIMIT) {
msleep(1000 * waittime);
count++;
rc = 0;
if (waittime < HPSA_MAX_WAIT_INTERVAL_SECS)
waittime = waittime * 2;
(void) fill_cmd(c, TEST_UNIT_READY, h,
NULL, 0, 0, lunaddr, TYPE_CMD);
hpsa_scsi_do_simple_cmd_core(h, c);
if (c->err_info->CommandStatus == CMD_SUCCESS)
break;
if (c->err_info->CommandStatus == CMD_TARGET_STATUS &&
c->err_info->ScsiStatus == SAM_STAT_CHECK_CONDITION &&
(c->err_info->SenseInfo[2] == NO_SENSE ||
c->err_info->SenseInfo[2] == UNIT_ATTENTION))
break;
dev_warn(&h->pdev->dev, "waiting %d secs "
"for device to become ready.\n", waittime);
rc = 1;
}
if (rc)
dev_warn(&h->pdev->dev, "giving up on device.\n");
else
dev_warn(&h->pdev->dev, "device is ready.\n");
cmd_special_free(h, c);
return rc;
}
static int hpsa_eh_device_reset_handler(struct scsi_cmnd *scsicmd)
{
int rc;
struct ctlr_info *h;
struct hpsa_scsi_dev_t *dev;
h = sdev_to_hba(scsicmd->device);
if (h == NULL)
return FAILED;
dev = scsicmd->device->hostdata;
if (!dev) {
dev_err(&h->pdev->dev, "hpsa_eh_device_reset_handler: "
"device lookup failed.\n");
return FAILED;
}
dev_warn(&h->pdev->dev, "resetting device %d:%d:%d:%d\n",
h->scsi_host->host_no, dev->bus, dev->target, dev->lun);
rc = hpsa_send_reset(h, dev->scsi3addr, HPSA_RESET_TYPE_LUN);
if (rc == 0 && wait_for_device_to_become_ready(h, dev->scsi3addr) == 0)
return SUCCESS;
dev_warn(&h->pdev->dev, "resetting device failed.\n");
return FAILED;
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
struct CommandList *c, u32 *taglower, u32 *tagupper)
{
if (c->cmd_type == CMD_IOACCEL1) {
struct io_accel1_cmd *cm1 = (struct io_accel1_cmd *)
&h->ioaccel_cmd_pool[c->cmdindex];
*tagupper = cm1->Tag.upper;
*taglower = cm1->Tag.lower;
return;
}
if (c->cmd_type == CMD_IOACCEL2) {
struct io_accel2_cmd *cm2 = (struct io_accel2_cmd *)
&h->ioaccel2_cmd_pool[c->cmdindex];
memset(tagupper, 0, sizeof(*tagupper));
*taglower = cm2->Tag;
return;
}
*tagupper = c->Header.Tag.upper;
*taglower = c->Header.Tag.lower;
}
static int hpsa_send_abort(struct ctlr_info *h, unsigned char *scsi3addr,
struct CommandList *abort, int swizzle)
{
int rc = IO_OK;
struct CommandList *c;
struct ErrorInfo *ei;
u32 tagupper, taglower;
c = cmd_special_alloc(h);
if (c == NULL) {
dev_warn(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
return -ENOMEM;
}
(void) fill_cmd(c, HPSA_ABORT_MSG, h, abort,
0, 0, scsi3addr, TYPE_MSG);
if (swizzle)
swizzle_abort_tag(&c->Request.CDB[4]);
hpsa_scsi_do_simple_cmd_core(h, c);
hpsa_get_tag(h, abort, &taglower, &tagupper);
dev_dbg(&h->pdev->dev, "%s: Tag:0x%08x:%08x: do_simple_cmd_core completed.\n",
__func__, tagupper, taglower);
ei = c->err_info;
switch (ei->CommandStatus) {
case CMD_SUCCESS:
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
cmd_special_free(h, c);
dev_dbg(&h->pdev->dev, "%s: Tag:0x%08x:%08x: Finished.\n",
__func__, tagupper, taglower);
return rc;
}
static struct CommandList *hpsa_find_cmd_in_queue(struct ctlr_info *h,
struct scsi_cmnd *find, struct list_head *queue_head)
{
unsigned long flags;
struct CommandList *c = NULL;
if (!find)
return 0;
spin_lock_irqsave(&h->lock, flags);
list_for_each_entry(c, queue_head, list) {
if (c->scsi_cmd == NULL)
continue;
if (c->scsi_cmd == find) {
spin_unlock_irqrestore(&h->lock, flags);
return c;
}
}
spin_unlock_irqrestore(&h->lock, flags);
return NULL;
}
static struct CommandList *hpsa_find_cmd_in_queue_by_tag(struct ctlr_info *h,
u8 *tag, struct list_head *queue_head)
{
unsigned long flags;
struct CommandList *c;
spin_lock_irqsave(&h->lock, flags);
list_for_each_entry(c, queue_head, list) {
if (memcmp(&c->Header.Tag, tag, 8) != 0)
continue;
spin_unlock_irqrestore(&h->lock, flags);
return c;
}
spin_unlock_irqrestore(&h->lock, flags);
return NULL;
}
static int hpsa_send_reset_as_abort_ioaccel2(struct ctlr_info *h,
unsigned char *scsi3addr, struct CommandList *abort)
{
int rc = IO_OK;
struct scsi_cmnd *scmd;
struct hpsa_scsi_dev_t *dev;
unsigned char phys_scsi3addr[8];
unsigned char *psa = &phys_scsi3addr[0];
scmd = (struct scsi_cmnd *) abort->scsi_cmd;
dev = (struct hpsa_scsi_dev_t *)(scmd->device->hostdata);
if (dev == NULL) {
dev_warn(&h->pdev->dev,
"Cannot abort: no device pointer for command.\n");
return -1;
}
if (h->raid_offload_debug > 0)
dev_info(&h->pdev->dev,
"Reset as abort: Abort requested on C%d:B%d:T%d:L%d scsi3addr 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
h->scsi_host->host_no, dev->bus, dev->target, dev->lun,
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
rc = hpsa_send_reset(h, psa, HPSA_RESET_TYPE_TARGET);
if (rc != 0) {
dev_warn(&h->pdev->dev,
"Reset as abort: Failed on physical device at scsi3addr 0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
psa[0], psa[1], psa[2], psa[3],
psa[4], psa[5], psa[6], psa[7]);
return rc;
}
if (wait_for_device_to_become_ready(h, psa) != 0) {
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
static int hpsa_send_abort_both_ways(struct ctlr_info *h,
unsigned char *scsi3addr, struct CommandList *abort)
{
u8 swizzled_tag[8];
struct CommandList *c;
int rc = 0, rc2 = 0;
if (abort->cmd_type == CMD_IOACCEL2)
return hpsa_send_reset_as_abort_ioaccel2(h, scsi3addr, abort);
memcpy(swizzled_tag, &abort->Request.CDB[4], 8);
swizzle_abort_tag(swizzled_tag);
c = hpsa_find_cmd_in_queue_by_tag(h, swizzled_tag, &h->cmpQ);
if (c != NULL) {
dev_warn(&h->pdev->dev, "Unexpectedly found byte-swapped tag in completion queue.\n");
return hpsa_send_abort(h, scsi3addr, abort, 0);
}
rc = hpsa_send_abort(h, scsi3addr, abort, 0);
c = hpsa_find_cmd_in_queue(h, abort->scsi_cmd, &h->cmpQ);
if (c)
rc2 = hpsa_send_abort(h, scsi3addr, abort, 1);
return rc && rc2;
}
static int hpsa_eh_abort_handler(struct scsi_cmnd *sc)
{
int i, rc;
struct ctlr_info *h;
struct hpsa_scsi_dev_t *dev;
struct CommandList *abort;
struct CommandList *found;
struct scsi_cmnd *as;
char msg[256];
int ml = 0;
u32 tagupper, taglower;
h = sdev_to_hba(sc->device);
if (WARN(h == NULL,
"ABORT REQUEST FAILED, Controller lookup failed.\n"))
return FAILED;
if (!(HPSATMF_PHYS_TASK_ABORT & h->TMFSupportFlags) &&
!(HPSATMF_LOG_TASK_ABORT & h->TMFSupportFlags))
return FAILED;
memset(msg, 0, sizeof(msg));
ml += sprintf(msg+ml, "ABORT REQUEST on C%d:B%d:T%d:L%llu ",
h->scsi_host->host_no, sc->device->channel,
sc->device->id, sc->device->lun);
dev = sc->device->hostdata;
if (!dev) {
dev_err(&h->pdev->dev, "%s FAILED, Device lookup failed.\n",
msg);
return FAILED;
}
abort = (struct CommandList *) sc->host_scribble;
if (abort == NULL) {
dev_err(&h->pdev->dev, "%s FAILED, Command to abort is NULL.\n",
msg);
return FAILED;
}
hpsa_get_tag(h, abort, &taglower, &tagupper);
ml += sprintf(msg+ml, "Tag:0x%08x:%08x ", tagupper, taglower);
as = (struct scsi_cmnd *) abort->scsi_cmd;
if (as != NULL)
ml += sprintf(msg+ml, "Command:0x%x SN:0x%lx ",
as->cmnd[0], as->serial_number);
dev_dbg(&h->pdev->dev, "%s\n", msg);
dev_warn(&h->pdev->dev, "Abort request on C%d:B%d:T%d:L%d\n",
h->scsi_host->host_no, dev->bus, dev->target, dev->lun);
found = hpsa_find_cmd_in_queue(h, sc, &h->reqQ);
if (found) {
found->err_info->CommandStatus = CMD_ABORTED;
finish_cmd(found);
dev_info(&h->pdev->dev, "%s Request SUCCEEDED (driver queue).\n",
msg);
return SUCCESS;
}
found = hpsa_find_cmd_in_queue(h, sc, &h->cmpQ);
if (!found) {
dev_dbg(&h->pdev->dev, "%s Request SUCCEEDED (not known to driver).\n",
msg);
return SUCCESS;
}
rc = hpsa_send_abort_both_ways(h, dev->scsi3addr, abort);
if (rc != 0) {
dev_dbg(&h->pdev->dev, "%s Request FAILED.\n", msg);
dev_warn(&h->pdev->dev, "FAILED abort on device C%d:B%d:T%d:L%d\n",
h->scsi_host->host_no,
dev->bus, dev->target, dev->lun);
return FAILED;
}
dev_info(&h->pdev->dev, "%s REQUEST SUCCEEDED.\n", msg);
#define ABORT_COMPLETE_WAIT_SECS 30
for (i = 0; i < ABORT_COMPLETE_WAIT_SECS * 10; i++) {
found = hpsa_find_cmd_in_queue(h, sc, &h->cmpQ);
if (!found)
return SUCCESS;
msleep(100);
}
dev_warn(&h->pdev->dev, "%s FAILED. Aborted command has not completed after %d seconds.\n",
msg, ABORT_COMPLETE_WAIT_SECS);
return FAILED;
}
static struct CommandList *cmd_alloc(struct ctlr_info *h)
{
struct CommandList *c;
int i;
union u64bit temp64;
dma_addr_t cmd_dma_handle, err_dma_handle;
unsigned long flags;
spin_lock_irqsave(&h->lock, flags);
do {
i = find_first_zero_bit(h->cmd_pool_bits, h->nr_cmds);
if (i == h->nr_cmds) {
spin_unlock_irqrestore(&h->lock, flags);
return NULL;
}
} while (test_and_set_bit
(i & (BITS_PER_LONG - 1),
h->cmd_pool_bits + (i / BITS_PER_LONG)) != 0);
spin_unlock_irqrestore(&h->lock, flags);
c = h->cmd_pool + i;
memset(c, 0, sizeof(*c));
cmd_dma_handle = h->cmd_pool_dhandle
+ i * sizeof(*c);
c->err_info = h->errinfo_pool + i;
memset(c->err_info, 0, sizeof(*c->err_info));
err_dma_handle = h->errinfo_pool_dhandle
+ i * sizeof(*c->err_info);
c->cmdindex = i;
INIT_LIST_HEAD(&c->list);
c->busaddr = (u32) cmd_dma_handle;
temp64.val = (u64) err_dma_handle;
c->ErrDesc.Addr.lower = temp64.val32.lower;
c->ErrDesc.Addr.upper = temp64.val32.upper;
c->ErrDesc.Len = sizeof(*c->err_info);
c->h = h;
return c;
}
static struct CommandList *cmd_special_alloc(struct ctlr_info *h)
{
struct CommandList *c;
union u64bit temp64;
dma_addr_t cmd_dma_handle, err_dma_handle;
c = pci_zalloc_consistent(h->pdev, sizeof(*c), &cmd_dma_handle);
if (c == NULL)
return NULL;
c->cmd_type = CMD_SCSI;
c->cmdindex = -1;
c->err_info = pci_zalloc_consistent(h->pdev, sizeof(*c->err_info),
&err_dma_handle);
if (c->err_info == NULL) {
pci_free_consistent(h->pdev,
sizeof(*c), c, cmd_dma_handle);
return NULL;
}
INIT_LIST_HEAD(&c->list);
c->busaddr = (u32) cmd_dma_handle;
temp64.val = (u64) err_dma_handle;
c->ErrDesc.Addr.lower = temp64.val32.lower;
c->ErrDesc.Addr.upper = temp64.val32.upper;
c->ErrDesc.Len = sizeof(*c->err_info);
c->h = h;
return c;
}
static void cmd_free(struct ctlr_info *h, struct CommandList *c)
{
int i;
unsigned long flags;
i = c - h->cmd_pool;
spin_lock_irqsave(&h->lock, flags);
clear_bit(i & (BITS_PER_LONG - 1),
h->cmd_pool_bits + (i / BITS_PER_LONG));
spin_unlock_irqrestore(&h->lock, flags);
}
static void cmd_special_free(struct ctlr_info *h, struct CommandList *c)
{
union u64bit temp64;
temp64.val32.lower = c->ErrDesc.Addr.lower;
temp64.val32.upper = c->ErrDesc.Addr.upper;
pci_free_consistent(h->pdev, sizeof(*c->err_info),
c->err_info, (dma_addr_t) temp64.val);
pci_free_consistent(h->pdev, sizeof(*c),
c, (dma_addr_t) (c->busaddr & DIRECT_LOOKUP_MASK));
}
static int hpsa_ioctl32_passthru(struct scsi_device *dev, int cmd, void *arg)
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
err = hpsa_ioctl(dev, CCISS_PASSTHRU, (void *)p);
if (err)
return err;
err |= copy_in_user(&arg32->error_info, &p->error_info,
sizeof(arg32->error_info));
if (err)
return -EFAULT;
return err;
}
static int hpsa_ioctl32_big_passthru(struct scsi_device *dev,
int cmd, void *arg)
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
err = hpsa_ioctl(dev, CCISS_BIG_PASSTHRU, (void *)p);
if (err)
return err;
err |= copy_in_user(&arg32->error_info, &p->error_info,
sizeof(arg32->error_info));
if (err)
return -EFAULT;
return err;
}
static int hpsa_compat_ioctl(struct scsi_device *dev, int cmd, void *arg)
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
union u64bit temp64;
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
return -EFAULT;
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
c = cmd_special_alloc(h);
if (c == NULL) {
rc = -ENOMEM;
goto out_kfree;
}
c->cmd_type = CMD_IOCTL_PEND;
c->Header.ReplyQueue = 0;
if (iocommand.buf_size > 0) {
c->Header.SGList = 1;
c->Header.SGTotal = 1;
} else {
c->Header.SGList = 0;
c->Header.SGTotal = 0;
}
memcpy(&c->Header.LUN, &iocommand.LUN_info, sizeof(c->Header.LUN));
c->Header.Tag.lower = c->busaddr;
memcpy(&c->Request, &iocommand.Request,
sizeof(c->Request));
if (iocommand.buf_size > 0) {
temp64.val = pci_map_single(h->pdev, buff,
iocommand.buf_size, PCI_DMA_BIDIRECTIONAL);
if (dma_mapping_error(&h->pdev->dev, temp64.val)) {
c->SG[0].Addr.lower = 0;
c->SG[0].Addr.upper = 0;
c->SG[0].Len = 0;
rc = -ENOMEM;
goto out;
}
c->SG[0].Addr.lower = temp64.val32.lower;
c->SG[0].Addr.upper = temp64.val32.upper;
c->SG[0].Len = iocommand.buf_size;
c->SG[0].Ext = HPSA_SG_LAST;
}
hpsa_scsi_do_simple_cmd_core_if_no_lockup(h, c);
if (iocommand.buf_size > 0)
hpsa_pci_unmap(h->pdev, c, 1, PCI_DMA_BIDIRECTIONAL);
check_ioctl_unit_attention(h, c);
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
cmd_special_free(h, c);
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
union u64bit temp64;
BYTE sg_used = 0;
int status = 0;
int i;
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
c = cmd_special_alloc(h);
if (c == NULL) {
status = -ENOMEM;
goto cleanup1;
}
c->cmd_type = CMD_IOCTL_PEND;
c->Header.ReplyQueue = 0;
c->Header.SGList = c->Header.SGTotal = sg_used;
memcpy(&c->Header.LUN, &ioc->LUN_info, sizeof(c->Header.LUN));
c->Header.Tag.lower = c->busaddr;
memcpy(&c->Request, &ioc->Request, sizeof(c->Request));
if (ioc->buf_size > 0) {
int i;
for (i = 0; i < sg_used; i++) {
temp64.val = pci_map_single(h->pdev, buff[i],
buff_size[i], PCI_DMA_BIDIRECTIONAL);
if (dma_mapping_error(&h->pdev->dev, temp64.val)) {
c->SG[i].Addr.lower = 0;
c->SG[i].Addr.upper = 0;
c->SG[i].Len = 0;
hpsa_pci_unmap(h->pdev, c, i,
PCI_DMA_BIDIRECTIONAL);
status = -ENOMEM;
goto cleanup0;
}
c->SG[i].Addr.lower = temp64.val32.lower;
c->SG[i].Addr.upper = temp64.val32.upper;
c->SG[i].Len = buff_size[i];
c->SG[i].Ext = i < sg_used - 1 ? 0 : HPSA_SG_LAST;
}
}
hpsa_scsi_do_simple_cmd_core_if_no_lockup(h, c);
if (sg_used)
hpsa_pci_unmap(h->pdev, c, sg_used, PCI_DMA_BIDIRECTIONAL);
check_ioctl_unit_attention(h, c);
memcpy(&ioc->error_info, c->err_info, sizeof(ioc->error_info));
if (copy_to_user(argp, ioc, sizeof(*ioc))) {
status = -EFAULT;
goto cleanup0;
}
if ((ioc->Request.Type.Direction & XFER_READ) && ioc->buf_size > 0) {
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
cmd_special_free(h, c);
cleanup1:
if (buff) {
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
static int increment_passthru_count(struct ctlr_info *h)
{
unsigned long flags;
spin_lock_irqsave(&h->passthru_count_lock, flags);
if (h->passthru_count >= HPSA_MAX_CONCURRENT_PASSTHRUS) {
spin_unlock_irqrestore(&h->passthru_count_lock, flags);
return -1;
}
h->passthru_count++;
spin_unlock_irqrestore(&h->passthru_count_lock, flags);
return 0;
}
static void decrement_passthru_count(struct ctlr_info *h)
{
unsigned long flags;
spin_lock_irqsave(&h->passthru_count_lock, flags);
if (h->passthru_count <= 0) {
spin_unlock_irqrestore(&h->passthru_count_lock, flags);
dev_warn(&h->pdev->dev, "Bug detected, passthru_count seems to be incorrect.\n");
return;
}
h->passthru_count--;
spin_unlock_irqrestore(&h->passthru_count_lock, flags);
}
static int hpsa_ioctl(struct scsi_device *dev, int cmd, void *arg)
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
if (increment_passthru_count(h))
return -EAGAIN;
rc = hpsa_passthru_ioctl(h, argp);
decrement_passthru_count(h);
return rc;
case CCISS_BIG_PASSTHRU:
if (increment_passthru_count(h))
return -EAGAIN;
rc = hpsa_big_passthru_ioctl(h, argp);
decrement_passthru_count(h);
return rc;
default:
return -ENOTTY;
}
}
static int hpsa_send_host_reset(struct ctlr_info *h, unsigned char *scsi3addr,
u8 reset_type)
{
struct CommandList *c;
c = cmd_alloc(h);
if (!c)
return -ENOMEM;
(void) fill_cmd(c, HPSA_DEVICE_RESET_MSG, h, NULL, 0, 0,
RAID_CTLR_LUNID, TYPE_MSG);
c->Request.CDB[1] = reset_type;
c->waiting = NULL;
enqueue_cmd_and_start_io(h, c);
return 0;
}
static int fill_cmd(struct CommandList *c, u8 cmd, struct ctlr_info *h,
void *buff, size_t size, u16 page_code, unsigned char *scsi3addr,
int cmd_type)
{
int pci_dir = XFER_NONE;
struct CommandList *a;
c->cmd_type = CMD_IOCTL_PEND;
c->Header.ReplyQueue = 0;
if (buff != NULL && size > 0) {
c->Header.SGList = 1;
c->Header.SGTotal = 1;
} else {
c->Header.SGList = 0;
c->Header.SGTotal = 0;
}
c->Header.Tag.lower = c->busaddr;
memcpy(c->Header.LUN.LunAddrBytes, scsi3addr, 8);
c->Request.Type.Type = cmd_type;
if (cmd_type == TYPE_CMD) {
switch (cmd) {
case HPSA_INQUIRY:
if (page_code & VPD_PAGE) {
c->Request.CDB[1] = 0x01;
c->Request.CDB[2] = (page_code & 0xff);
}
c->Request.CDBLen = 6;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = HPSA_INQUIRY;
c->Request.CDB[4] = size & 0xFF;
break;
case HPSA_REPORT_LOG:
case HPSA_REPORT_PHYS:
c->Request.CDBLen = 12;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = cmd;
c->Request.CDB[6] = (size >> 24) & 0xFF;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0xFF;
c->Request.CDB[9] = size & 0xFF;
break;
case HPSA_CACHE_FLUSH:
c->Request.CDBLen = 12;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_WRITE;
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_WRITE;
c->Request.CDB[6] = BMIC_CACHE_FLUSH;
c->Request.CDB[7] = (size >> 8) & 0xFF;
c->Request.CDB[8] = size & 0xFF;
break;
case TEST_UNIT_READY:
c->Request.CDBLen = 6;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_NONE;
c->Request.Timeout = 0;
break;
case HPSA_GET_RAID_MAP:
c->Request.CDBLen = 12;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
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
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_READ;
c->Request.Timeout = 0;
c->Request.CDB[0] = BMIC_READ;
c->Request.CDB[6] = BMIC_SENSE_CONTROLLER_PARAMETERS;
c->Request.CDB[7] = (size >> 16) & 0xFF;
c->Request.CDB[8] = (size >> 8) & 0xFF;
break;
default:
dev_warn(&h->pdev->dev, "unknown command 0x%c\n", cmd);
BUG();
return -1;
}
} else if (cmd_type == TYPE_MSG) {
switch (cmd) {
case HPSA_DEVICE_RESET_MSG:
c->Request.CDBLen = 16;
c->Request.Type.Type = 1;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_NONE;
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
a = buff;
dev_dbg(&h->pdev->dev, "Abort Tag:0x%08x:%08x using request Tag:0x%08x:%08x\n",
a->Header.Tag.upper, a->Header.Tag.lower,
c->Header.Tag.upper, c->Header.Tag.lower);
c->Request.CDBLen = 16;
c->Request.Type.Type = TYPE_MSG;
c->Request.Type.Attribute = ATTR_SIMPLE;
c->Request.Type.Direction = XFER_WRITE;
c->Request.Timeout = 0;
c->Request.CDB[0] = HPSA_TASK_MANAGEMENT;
c->Request.CDB[1] = HPSA_TMF_ABORT_TASK;
c->Request.CDB[2] = 0x00;
c->Request.CDB[3] = 0x00;
c->Request.CDB[4] = a->Header.Tag.lower & 0xFF;
c->Request.CDB[5] = (a->Header.Tag.lower >> 8) & 0xFF;
c->Request.CDB[6] = (a->Header.Tag.lower >> 16) & 0xFF;
c->Request.CDB[7] = (a->Header.Tag.lower >> 24) & 0xFF;
c->Request.CDB[8] = a->Header.Tag.upper & 0xFF;
c->Request.CDB[9] = (a->Header.Tag.upper >> 8) & 0xFF;
c->Request.CDB[10] = (a->Header.Tag.upper >> 16) & 0xFF;
c->Request.CDB[11] = (a->Header.Tag.upper >> 24) & 0xFF;
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
switch (c->Request.Type.Direction) {
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
static void start_io(struct ctlr_info *h, unsigned long *flags)
{
struct CommandList *c;
while (!list_empty(&h->reqQ)) {
c = list_entry(h->reqQ.next, struct CommandList, list);
if ((h->access.fifo_full(h))) {
h->fifo_recently_full = 1;
dev_warn(&h->pdev->dev, "fifo full\n");
break;
}
h->fifo_recently_full = 0;
removeQ(c);
h->Qdepth--;
addQ(&h->cmpQ, c);
h->commands_outstanding++;
spin_unlock_irqrestore(&h->lock, *flags);
h->access.submit_command(h, c);
spin_lock_irqsave(&h->lock, *flags);
}
}
static void lock_and_start_io(struct ctlr_info *h)
{
unsigned long flags;
spin_lock_irqsave(&h->lock, flags);
start_io(h, &flags);
spin_unlock_irqrestore(&h->lock, flags);
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
unsigned long flags;
int io_may_be_stalled = 0;
struct ctlr_info *h = c->h;
spin_lock_irqsave(&h->lock, flags);
removeQ(c);
if (unlikely(h->fifo_recently_full) &&
h->commands_outstanding < 5)
io_may_be_stalled = 1;
spin_unlock_irqrestore(&h->lock, flags);
dial_up_lockup_detection_on_fw_flash_complete(c->h, c);
if (likely(c->cmd_type == CMD_IOACCEL1 || c->cmd_type == CMD_SCSI
|| c->cmd_type == CMD_IOACCEL2))
complete_scsi_command(c);
else if (c->cmd_type == CMD_IOCTL_PEND)
complete(c->waiting);
if (unlikely(io_may_be_stalled))
lock_and_start_io(h);
}
static inline u32 hpsa_tag_contains_index(u32 tag)
{
return tag & DIRECT_LOOKUP_BIT;
}
static inline u32 hpsa_tag_to_index(u32 tag)
{
return tag >> DIRECT_LOOKUP_SHIFT;
}
static inline u32 hpsa_tag_discard_error_bits(struct ctlr_info *h, u32 tag)
{
#define HPSA_PERF_ERROR_BITS ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define HPSA_SIMPLE_ERROR_BITS 0x03
if (unlikely(!(h->transMethod & CFGTBL_Trans_Performant)))
return tag & ~HPSA_SIMPLE_ERROR_BITS;
return tag & ~HPSA_PERF_ERROR_BITS;
}
static inline void process_indexed_cmd(struct ctlr_info *h,
u32 raw_tag)
{
u32 tag_index;
struct CommandList *c;
tag_index = hpsa_tag_to_index(raw_tag);
if (!bad_tag(h, tag_index, raw_tag)) {
c = h->cmd_pool + tag_index;
finish_cmd(c);
}
}
static inline void process_nonindexed_cmd(struct ctlr_info *h,
u32 raw_tag)
{
u32 tag;
struct CommandList *c = NULL;
unsigned long flags;
tag = hpsa_tag_discard_error_bits(h, raw_tag);
spin_lock_irqsave(&h->lock, flags);
list_for_each_entry(c, &h->cmpQ, list) {
if ((c->busaddr & 0xFFFFFFE0) == (tag & 0xFFFFFFE0)) {
spin_unlock_irqrestore(&h->lock, flags);
finish_cmd(c);
return;
}
}
spin_unlock_irqrestore(&h->lock, flags);
bad_tag(h, h->nr_cmds + 1, raw_tag);
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
if (likely(hpsa_tag_contains_index(raw_tag)))
process_indexed_cmd(h, raw_tag);
else
process_nonindexed_cmd(h, raw_tag);
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
if (likely(hpsa_tag_contains_index(raw_tag)))
process_indexed_cmd(h, raw_tag);
else
process_nonindexed_cmd(h, raw_tag);
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
uint32_t paddr32, tag;
void __iomem *vaddr;
int i, err;
vaddr = pci_ioremap_bar(pdev, 0);
if (vaddr == NULL)
return -ENOMEM;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
iounmap(vaddr);
return -ENOMEM;
}
cmd = pci_alloc_consistent(pdev, cmd_sz, &paddr64);
if (cmd == NULL) {
iounmap(vaddr);
return -ENOMEM;
}
paddr32 = paddr64;
cmd->CommandHeader.ReplyQueue = 0;
cmd->CommandHeader.SGList = 0;
cmd->CommandHeader.SGTotal = 0;
cmd->CommandHeader.Tag.lower = paddr32;
cmd->CommandHeader.Tag.upper = 0;
memset(&cmd->CommandHeader.LUN.LunAddrBytes, 0, 8);
cmd->Request.CDBLen = 16;
cmd->Request.Type.Type = TYPE_MSG;
cmd->Request.Type.Attribute = ATTR_HEADOFQUEUE;
cmd->Request.Type.Direction = XFER_NONE;
cmd->Request.Timeout = 0;
cmd->Request.CDB[0] = opcode;
cmd->Request.CDB[1] = type;
memset(&cmd->Request.CDB[2], 0, 14);
cmd->ErrorDescriptor.Addr.lower = paddr32 + sizeof(*cmd);
cmd->ErrorDescriptor.Addr.upper = 0;
cmd->ErrorDescriptor.Len = sizeof(struct ErrorInfo);
writel(paddr32, vaddr + SA5_REQUEST_PORT_OFFSET);
for (i = 0; i < HPSA_MSG_SEND_RETRY_LIMIT; i++) {
tag = readl(vaddr + SA5_REPLY_PORT_OFFSET);
if ((tag & ~HPSA_SIMPLE_ERROR_BITS) == paddr32)
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
void * __iomem vaddr, u32 use_doorbell)
{
u16 pmcsr;
int pos;
if (use_doorbell) {
dev_info(&pdev->dev, "using doorbell to reset controller\n");
writel(use_doorbell, vaddr + SA5_DOORBELL);
msleep(10000);
} else {
pos = pci_find_capability(pdev, PCI_CAP_ID_PM);
if (pos == 0) {
dev_err(&pdev->dev,
"hpsa_reset_controller: "
"PCI PM not supported\n");
return -ENODEV;
}
dev_info(&pdev->dev, "using PCI PM to reset controller\n");
pci_read_config_word(pdev, pos + PCI_PM_CTRL, &pmcsr);
pmcsr &= ~PCI_PM_CTRL_STATE_MASK;
pmcsr |= PCI_D3hot;
pci_write_config_word(pdev, pos + PCI_PM_CTRL, pmcsr);
msleep(500);
pmcsr &= ~PCI_PM_CTRL_STATE_MASK;
pmcsr |= PCI_D0;
pci_write_config_word(pdev, pos + PCI_PM_CTRL, pmcsr);
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
static int hpsa_kdump_hard_reset_controller(struct pci_dev *pdev)
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
u32 board_id;
u16 command_register;
rc = hpsa_lookup_board_id(pdev, &board_id);
if (rc < 0 || !ctlr_is_resettable(board_id)) {
dev_warn(&pdev->dev, "Not resetting device.\n");
return -ENODEV;
}
if (!ctlr_is_hard_resettable(board_id))
return -ENOTSUPP;
pci_read_config_word(pdev, 4, &command_register);
pci_disable_device(pdev);
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
goto unmap_vaddr;
misc_fw_support = readl(&cfgtable->misc_fw_support);
use_doorbell = misc_fw_support & MISC_FW_DOORBELL_RESET2;
if (use_doorbell) {
use_doorbell = DOORBELL_CTLR_RESET2;
} else {
use_doorbell = misc_fw_support & MISC_FW_DOORBELL_RESET;
if (use_doorbell) {
dev_warn(&pdev->dev, "Soft reset not supported. "
"Firmware update is required.\n");
rc = -ENOTSUPP;
goto unmap_cfgtable;
}
}
rc = hpsa_controller_hard_reset(pdev, vaddr, use_doorbell);
if (rc)
goto unmap_cfgtable;
pci_restore_state(pdev);
rc = pci_enable_device(pdev);
if (rc) {
dev_warn(&pdev->dev, "failed to enable device.\n");
goto unmap_cfgtable;
}
pci_write_config_word(pdev, 4, command_register);
msleep(HPSA_POST_RESET_PAUSE_MSECS);
rc = hpsa_wait_for_board_state(pdev, vaddr, BOARD_READY);
if (rc) {
dev_warn(&pdev->dev,
"failed waiting for board to become ready "
"after hard reset\n");
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
static void print_cfg_table(struct device *dev, struct CfgTable *tb)
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
dev_info(dev, " Max outstanding commands = 0x%d\n",
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
dev_info(&h->pdev->dev, "MSIX\n");
h->msix_vector = MAX_REPLY_QUEUES;
if (h->msix_vector > num_online_cpus())
h->msix_vector = num_online_cpus();
err = pci_enable_msix(h->pdev, hpsa_msix_entries,
h->msix_vector);
if (err > 0) {
dev_warn(&h->pdev->dev, "only %d MSI-X vectors "
"available\n", err);
h->msix_vector = err;
err = pci_enable_msix(h->pdev, hpsa_msix_entries,
h->msix_vector);
}
if (!err) {
for (i = 0; i < h->msix_vector; i++)
h->intr[i] = hpsa_msix_entries[i].vector;
return;
} else {
dev_warn(&h->pdev->dev, "MSI-X init failed %d\n",
err);
h->msix_vector = 0;
goto default_int_mode;
}
}
if (pci_find_capability(h->pdev, PCI_CAP_ID_MSI)) {
dev_info(&h->pdev->dev, "MSI\n");
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
if (!h->cfgtable)
return -ENOMEM;
rc = write_driver_ver_to_cfgtable(h->cfgtable);
if (rc)
return rc;
trans_offset = readl(&h->cfgtable->TransMethodOffset);
h->transtable = remap_pci_mem(pci_resource_start(h->pdev,
cfg_base_addr_index)+cfg_offset+trans_offset,
sizeof(*h->transtable));
if (!h->transtable)
return -ENOMEM;
return 0;
}
static void hpsa_get_max_perf_mode_cmds(struct ctlr_info *h)
{
h->max_commands = readl(&(h->cfgtable->MaxPerformantModeCommands));
if (reset_devices && h->max_commands > 32)
h->max_commands = 32;
if (h->max_commands < 16) {
dev_warn(&h->pdev->dev, "Controller reports "
"max supported commands of %d, an obvious lie. "
"Using 16. Ensure that firmware is up to date.\n",
h->max_commands);
h->max_commands = 16;
}
}
static void hpsa_find_board_params(struct ctlr_info *h)
{
hpsa_get_max_perf_mode_cmds(h);
h->nr_cmds = h->max_commands - 4;
h->maxsgentries = readl(&(h->cfgtable->MaxScatterGatherElements));
h->fw_support = readl(&(h->cfgtable->misc_fw_support));
h->max_cmd_sg_entries = 31;
if (h->maxsgentries > 512) {
h->max_cmd_sg_entries = 32;
h->chainsize = h->maxsgentries - h->max_cmd_sg_entries + 1;
h->maxsgentries--;
} else {
h->maxsgentries = 31;
h->chainsize = 0;
}
h->TMFSupportFlags = readl(&(h->cfgtable->TMFSupportFlags));
if (!(HPSATMF_PHYS_TASK_ABORT & h->TMFSupportFlags))
dev_warn(&h->pdev->dev, "Physical aborts not supported\n");
if (!(HPSATMF_LOG_TASK_ABORT & h->TMFSupportFlags))
dev_warn(&h->pdev->dev, "Logical aborts not supported\n");
}
static inline bool hpsa_CISS_signature_present(struct ctlr_info *h)
{
if (!check_signature(h->cfgtable->Signature, "CISS", 4)) {
dev_warn(&h->pdev->dev, "not a valid CISS config table\n");
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
static void hpsa_wait_for_clear_event_notify_ack(struct ctlr_info *h)
{
int i;
u32 doorbell_value;
unsigned long flags;
for (i = 0; i < MAX_CONFIG_WAIT; i++) {
spin_lock_irqsave(&h->lock, flags);
doorbell_value = readl(h->vaddr + SA5_DOORBELL);
spin_unlock_irqrestore(&h->lock, flags);
if (!(doorbell_value & DOORBELL_CLEAR_EVENTS))
break;
msleep(20);
}
}
static void hpsa_wait_for_mode_change_ack(struct ctlr_info *h)
{
int i;
u32 doorbell_value;
unsigned long flags;
for (i = 0; i < MAX_CONFIG_WAIT; i++) {
spin_lock_irqsave(&h->lock, flags);
doorbell_value = readl(h->vaddr + SA5_DOORBELL);
spin_unlock_irqrestore(&h->lock, flags);
if (!(doorbell_value & CFGTBL_ChangeReq))
break;
usleep_range(10000, 20000);
}
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
hpsa_wait_for_mode_change_ack(h);
print_cfg_table(&h->pdev->dev, h->cfgtable);
if (!(readl(&(h->cfgtable->TransportActive)) & CFGTBL_Trans_Simple))
goto error;
h->transMethod = CFGTBL_Trans_Simple;
return 0;
error:
dev_warn(&h->pdev->dev, "unable to get board into simple mode\n");
return -ENODEV;
}
static int hpsa_pci_init(struct ctlr_info *h)
{
int prod_index, err;
prod_index = hpsa_lookup_board_id(h->pdev, &h->board_id);
if (prod_index < 0)
return -ENODEV;
h->product_name = products[prod_index].product_name;
h->access = *(products[prod_index].access);
pci_disable_link_state(h->pdev, PCIE_LINK_STATE_L0S |
PCIE_LINK_STATE_L1 | PCIE_LINK_STATE_CLKPM);
err = pci_enable_device(h->pdev);
if (err) {
dev_warn(&h->pdev->dev, "unable to enable PCI device\n");
return err;
}
pci_set_master(h->pdev);
err = pci_request_regions(h->pdev, HPSA);
if (err) {
dev_err(&h->pdev->dev,
"cannot obtain PCI resources, aborting\n");
return err;
}
hpsa_interrupt_mode(h);
err = hpsa_pci_find_memory_BAR(h->pdev, &h->paddr);
if (err)
goto err_out_free_res;
h->vaddr = remap_pci_mem(h->paddr, 0x250);
if (!h->vaddr) {
err = -ENOMEM;
goto err_out_free_res;
}
err = hpsa_wait_for_board_state(h->pdev, h->vaddr, BOARD_READY);
if (err)
goto err_out_free_res;
err = hpsa_find_cfgtables(h);
if (err)
goto err_out_free_res;
hpsa_find_board_params(h);
if (!hpsa_CISS_signature_present(h)) {
err = -ENODEV;
goto err_out_free_res;
}
hpsa_set_driver_support_bits(h);
hpsa_p600_dma_prefetch_quirk(h);
err = hpsa_enter_simple_mode(h);
if (err)
goto err_out_free_res;
return 0;
err_out_free_res:
if (h->transtable)
iounmap(h->transtable);
if (h->cfgtable)
iounmap(h->cfgtable);
if (h->vaddr)
iounmap(h->vaddr);
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
static int hpsa_init_reset_devices(struct pci_dev *pdev)
{
int rc, i;
if (!reset_devices)
return 0;
rc = hpsa_kdump_hard_reset_controller(pdev);
if (rc == -ENOTSUPP)
return rc;
if (rc)
return -ENODEV;
dev_warn(&pdev->dev, "Waiting for controller to respond to no-op\n");
for (i = 0; i < HPSA_POST_RESET_NOOP_RETRIES; i++) {
if (hpsa_noop(pdev) == 0)
break;
else
dev_warn(&pdev->dev, "no-op failed%s\n",
(i < 11 ? "; re-trying" : ""));
}
return 0;
}
static int hpsa_allocate_cmd_pool(struct ctlr_info *h)
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
return -ENOMEM;
}
return 0;
}
static void hpsa_free_cmd_pool(struct ctlr_info *h)
{
kfree(h->cmd_pool_bits);
if (h->cmd_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct CommandList),
h->cmd_pool, h->cmd_pool_dhandle);
if (h->ioaccel2_cmd_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel2_cmd_pool),
h->ioaccel2_cmd_pool, h->ioaccel2_cmd_pool_dhandle);
if (h->errinfo_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct ErrorInfo),
h->errinfo_pool,
h->errinfo_pool_dhandle);
if (h->ioaccel_cmd_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct io_accel1_cmd),
h->ioaccel_cmd_pool, h->ioaccel_cmd_pool_dhandle);
}
static void hpsa_irq_affinity_hints(struct ctlr_info *h)
{
int i, cpu, rc;
cpu = cpumask_first(cpu_online_mask);
for (i = 0; i < h->msix_vector; i++) {
rc = irq_set_affinity_hint(h->intr[i], get_cpu_mask(cpu));
cpu = cpumask_next(cpu, cpu_online_mask);
}
}
static int hpsa_request_irq(struct ctlr_info *h,
irqreturn_t (*msixhandler)(int, void *),
irqreturn_t (*intxhandler)(int, void *))
{
int rc, i;
for (i = 0; i < MAX_REPLY_QUEUES; i++)
h->q[i] = (u8) i;
if (h->intr_mode == PERF_MODE_INT && h->msix_vector > 0) {
for (i = 0; i < h->msix_vector; i++)
rc = request_irq(h->intr[i], msixhandler,
0, h->devname,
&h->q[i]);
hpsa_irq_affinity_hints(h);
} else {
if (h->msix_vector > 0 || h->msi_vector) {
rc = request_irq(h->intr[h->intr_mode],
msixhandler, 0, h->devname,
&h->q[h->intr_mode]);
} else {
rc = request_irq(h->intr[h->intr_mode],
intxhandler, IRQF_SHARED, h->devname,
&h->q[h->intr_mode]);
}
}
if (rc) {
dev_err(&h->pdev->dev, "unable to get irq %d for %s\n",
h->intr[h->intr_mode], h->devname);
return -ENODEV;
}
return 0;
}
static int hpsa_kdump_soft_reset(struct ctlr_info *h)
{
if (hpsa_send_host_reset(h, RAID_CTLR_LUNID,
HPSA_RESET_TYPE_CONTROLLER)) {
dev_warn(&h->pdev->dev, "Resetting array controller failed.\n");
return -EIO;
}
dev_info(&h->pdev->dev, "Waiting for board to soft reset.\n");
if (hpsa_wait_for_board_state(h->pdev, h->vaddr, BOARD_NOT_READY)) {
dev_warn(&h->pdev->dev, "Soft reset had no effect.\n");
return -1;
}
dev_info(&h->pdev->dev, "Board reset, awaiting READY status.\n");
if (hpsa_wait_for_board_state(h->pdev, h->vaddr, BOARD_READY)) {
dev_warn(&h->pdev->dev, "Board failed to become ready "
"after soft reset.\n");
return -1;
}
return 0;
}
static void free_irqs(struct ctlr_info *h)
{
int i;
if (!h->msix_vector || h->intr_mode != PERF_MODE_INT) {
i = h->intr_mode;
irq_set_affinity_hint(h->intr[i], NULL);
free_irq(h->intr[i], &h->q[i]);
return;
}
for (i = 0; i < h->msix_vector; i++) {
irq_set_affinity_hint(h->intr[i], NULL);
free_irq(h->intr[i], &h->q[i]);
}
}
static void hpsa_free_irqs_and_disable_msix(struct ctlr_info *h)
{
free_irqs(h);
#ifdef CONFIG_PCI_MSI
if (h->msix_vector) {
if (h->pdev->msix_enabled)
pci_disable_msix(h->pdev);
} else if (h->msi_vector) {
if (h->pdev->msi_enabled)
pci_disable_msi(h->pdev);
}
#endif
}
static void hpsa_free_reply_queues(struct ctlr_info *h)
{
int i;
for (i = 0; i < h->nreply_queues; i++) {
if (!h->reply_queue[i].head)
continue;
pci_free_consistent(h->pdev, h->reply_queue_size,
h->reply_queue[i].head, h->reply_queue[i].busaddr);
h->reply_queue[i].head = NULL;
h->reply_queue[i].busaddr = 0;
}
}
static void hpsa_undo_allocations_after_kdump_soft_reset(struct ctlr_info *h)
{
hpsa_free_irqs_and_disable_msix(h);
hpsa_free_sg_chain_blocks(h);
hpsa_free_cmd_pool(h);
kfree(h->ioaccel1_blockFetchTable);
kfree(h->blockFetchTable);
hpsa_free_reply_queues(h);
if (h->vaddr)
iounmap(h->vaddr);
if (h->transtable)
iounmap(h->transtable);
if (h->cfgtable)
iounmap(h->cfgtable);
pci_release_regions(h->pdev);
kfree(h);
}
static void fail_all_cmds_on_list(struct ctlr_info *h, struct list_head *list)
{
struct CommandList *c = NULL;
assert_spin_locked(&h->lock);
while (!list_empty(list)) {
c = list_entry(list->next, struct CommandList, list);
c->err_info->CommandStatus = CMD_HARDWARE_ERR;
finish_cmd(c);
}
}
static void set_lockup_detected_for_all_cpus(struct ctlr_info *h, u32 value)
{
int i, cpu;
cpu = cpumask_first(cpu_online_mask);
for (i = 0; i < num_online_cpus(); i++) {
u32 *lockup_detected;
lockup_detected = per_cpu_ptr(h->lockup_detected, cpu);
*lockup_detected = value;
cpu = cpumask_next(cpu, cpu_online_mask);
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
"lockup detected but scratchpad register is zero\n");
lockup_detected = 0xffffffff;
}
set_lockup_detected_for_all_cpus(h, lockup_detected);
spin_unlock_irqrestore(&h->lock, flags);
dev_warn(&h->pdev->dev, "Controller lockup detected: 0x%08x\n",
lockup_detected);
pci_disable_device(h->pdev);
spin_lock_irqsave(&h->lock, flags);
fail_all_cmds_on_list(h, &h->cmpQ);
fail_all_cmds_on_list(h, &h->reqQ);
spin_unlock_irqrestore(&h->lock, flags);
}
static void detect_controller_lockup(struct ctlr_info *h)
{
u64 now;
u32 heartbeat;
unsigned long flags;
now = get_jiffies_64();
if (time_after64(h->last_intr_timestamp +
(h->heartbeat_sample_interval), now))
return;
if (time_after64(h->last_heartbeat_timestamp +
(h->heartbeat_sample_interval), now))
return;
spin_lock_irqsave(&h->lock, flags);
heartbeat = readl(&h->cfgtable->HeartBeat);
spin_unlock_irqrestore(&h->lock, flags);
if (h->last_heartbeat == heartbeat) {
controller_lockup_detected(h);
return;
}
h->last_heartbeat = heartbeat;
h->last_heartbeat_timestamp = now;
}
static void hpsa_ack_ctlr_events(struct ctlr_info *h)
{
int i;
char *event_type;
h->drv_req_rescan = 0;
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
if (h->drv_req_rescan)
return 1;
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
static void hpsa_monitor_ctlr_worker(struct work_struct *work)
{
unsigned long flags;
struct ctlr_info *h = container_of(to_delayed_work(work),
struct ctlr_info, monitor_ctlr_work);
detect_controller_lockup(h);
if (lockup_detected(h))
return;
if (hpsa_ctlr_needs_rescan(h) || hpsa_offline_devices_ready(h)) {
scsi_host_get(h->scsi_host);
h->drv_req_rescan = 0;
hpsa_ack_ctlr_events(h);
hpsa_scan_start(h->scsi_host);
scsi_host_put(h->scsi_host);
}
spin_lock_irqsave(&h->lock, flags);
if (h->remove_in_progress) {
spin_unlock_irqrestore(&h->lock, flags);
return;
}
schedule_delayed_work(&h->monitor_ctlr_work,
h->heartbeat_sample_interval);
spin_unlock_irqrestore(&h->lock, flags);
}
static int hpsa_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int dac, rc;
struct ctlr_info *h;
int try_soft_reset = 0;
unsigned long flags;
if (number_of_controllers == 0)
printk(KERN_INFO DRIVER_NAME "\n");
rc = hpsa_init_reset_devices(pdev);
if (rc) {
if (rc != -ENOTSUPP)
return rc;
try_soft_reset = 1;
rc = 0;
}
reinit_after_soft_reset:
BUILD_BUG_ON(sizeof(struct CommandList) % COMMANDLIST_ALIGNMENT);
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return -ENOMEM;
h->pdev = pdev;
h->intr_mode = hpsa_simple_mode ? SIMPLE_MODE_INT : PERF_MODE_INT;
INIT_LIST_HEAD(&h->cmpQ);
INIT_LIST_HEAD(&h->reqQ);
INIT_LIST_HEAD(&h->offline_device_list);
spin_lock_init(&h->lock);
spin_lock_init(&h->offline_device_lock);
spin_lock_init(&h->scan_lock);
spin_lock_init(&h->passthru_count_lock);
h->lockup_detected = alloc_percpu(u32);
if (!h->lockup_detected) {
rc = -ENOMEM;
goto clean1;
}
set_lockup_detected_for_all_cpus(h, 0);
rc = hpsa_pci_init(h);
if (rc != 0)
goto clean1;
sprintf(h->devname, HPSA "%d", number_of_controllers);
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
goto clean1;
}
}
h->access.set_intr_mask(h, HPSA_INTR_OFF);
if (hpsa_request_irq(h, do_hpsa_intr_msi, do_hpsa_intr_intx))
goto clean2;
dev_info(&pdev->dev, "%s: <0x%x> at IRQ %d%s using DAC\n",
h->devname, pdev->device,
h->intr[h->intr_mode], dac ? "" : " not");
if (hpsa_allocate_cmd_pool(h))
goto clean4;
if (hpsa_allocate_sg_chain_blocks(h))
goto clean4;
init_waitqueue_head(&h->scan_wait_queue);
h->scan_finished = 1;
pci_set_drvdata(pdev, h);
h->ndevices = 0;
h->hba_mode_enabled = 0;
h->scsi_host = NULL;
spin_lock_init(&h->devlock);
hpsa_put_ctlr_into_performant_mode(h);
if (try_soft_reset) {
spin_lock_irqsave(&h->lock, flags);
h->access.set_intr_mask(h, HPSA_INTR_OFF);
spin_unlock_irqrestore(&h->lock, flags);
free_irqs(h);
rc = hpsa_request_irq(h, hpsa_msix_discard_completions,
hpsa_intx_discard_completions);
if (rc) {
dev_warn(&h->pdev->dev, "Failed to request_irq after "
"soft reset.\n");
goto clean4;
}
rc = hpsa_kdump_soft_reset(h);
if (rc)
goto clean4;
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
h->drv_req_rescan = 0;
h->access.set_intr_mask(h, HPSA_INTR_ON);
hpsa_hba_inquiry(h);
hpsa_register_scsi(h);
h->heartbeat_sample_interval = HEARTBEAT_SAMPLE_INTERVAL;
INIT_DELAYED_WORK(&h->monitor_ctlr_work, hpsa_monitor_ctlr_worker);
schedule_delayed_work(&h->monitor_ctlr_work,
h->heartbeat_sample_interval);
return 0;
clean4:
hpsa_free_sg_chain_blocks(h);
hpsa_free_cmd_pool(h);
free_irqs(h);
clean2:
clean1:
if (h->lockup_detected)
free_percpu(h->lockup_detected);
kfree(h);
return rc;
}
static void hpsa_flush_cache(struct ctlr_info *h)
{
char *flush_buf;
struct CommandList *c;
if (unlikely(lockup_detected(h)))
return;
flush_buf = kzalloc(4, GFP_KERNEL);
if (!flush_buf)
return;
c = cmd_special_alloc(h);
if (!c) {
dev_warn(&h->pdev->dev, "cmd_special_alloc returned NULL!\n");
goto out_of_memory;
}
if (fill_cmd(c, HPSA_CACHE_FLUSH, h, flush_buf, 4, 0,
RAID_CTLR_LUNID, TYPE_CMD)) {
goto out;
}
hpsa_scsi_do_simple_cmd_with_retry(h, c, PCI_DMA_TODEVICE);
if (c->err_info->CommandStatus != 0)
out:
dev_warn(&h->pdev->dev,
"error flushing cache on controller\n");
cmd_special_free(h, c);
out_of_memory:
kfree(flush_buf);
}
static void hpsa_shutdown(struct pci_dev *pdev)
{
struct ctlr_info *h;
h = pci_get_drvdata(pdev);
hpsa_flush_cache(h);
h->access.set_intr_mask(h, HPSA_INTR_OFF);
hpsa_free_irqs_and_disable_msix(h);
}
static void hpsa_free_device_info(struct ctlr_info *h)
{
int i;
for (i = 0; i < h->ndevices; i++)
kfree(h->dev[i]);
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
cancel_delayed_work(&h->monitor_ctlr_work);
spin_unlock_irqrestore(&h->lock, flags);
hpsa_unregister_scsi(h);
hpsa_shutdown(pdev);
iounmap(h->vaddr);
iounmap(h->transtable);
iounmap(h->cfgtable);
hpsa_free_device_info(h);
hpsa_free_sg_chain_blocks(h);
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct CommandList),
h->cmd_pool, h->cmd_pool_dhandle);
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(struct ErrorInfo),
h->errinfo_pool, h->errinfo_pool_dhandle);
hpsa_free_reply_queues(h);
kfree(h->cmd_pool_bits);
kfree(h->blockFetchTable);
kfree(h->ioaccel1_blockFetchTable);
kfree(h->ioaccel2_blockFetchTable);
kfree(h->hba_inquiry_data);
pci_disable_device(pdev);
pci_release_regions(pdev);
free_percpu(h->lockup_detected);
kfree(h);
}
static void calc_bucket_map(int bucket[], int num_buckets,
int nsgs, int min_blocks, int *bucket_map)
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
static void hpsa_enter_performant_mode(struct ctlr_info *h, u32 trans_support)
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
hpsa_wait_for_mode_change_ack(h);
register_value = readl(&(h->cfgtable->TransportActive));
if (!(register_value & CFGTBL_Trans_Performant)) {
dev_warn(&h->pdev->dev, "unable to get board into"
" performant mode\n");
return;
}
h->access = access;
h->transMethod = transMethod;
if (!((trans_support & CFGTBL_Trans_io_accel1) ||
(trans_support & CFGTBL_Trans_io_accel2)))
return;
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
cp->host_context_flags = IOACCEL1_HCFLAGS_CISS_FORMAT;
cp->timeout_sec = 0;
cp->ReplyQueue = 0;
cp->Tag.lower = (i << DIRECT_LOOKUP_SHIFT) |
DIRECT_LOOKUP_BIT;
cp->Tag.upper = 0;
cp->host_addr.lower =
(u32) (h->ioaccel_cmd_pool_dhandle +
(i * sizeof(struct io_accel1_cmd)));
cp->host_addr.upper = 0;
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
hpsa_wait_for_mode_change_ack(h);
}
static int hpsa_alloc_ioaccel_cmd_and_bft(struct ctlr_info *h)
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
if (h->ioaccel_cmd_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel_cmd_pool),
h->ioaccel_cmd_pool, h->ioaccel_cmd_pool_dhandle);
kfree(h->ioaccel1_blockFetchTable);
return 1;
}
static int ioaccel2_alloc_cmds_and_bft(struct ctlr_info *h)
{
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
(h->ioaccel2_blockFetchTable == NULL))
goto clean_up;
memset(h->ioaccel2_cmd_pool, 0,
h->nr_cmds * sizeof(*h->ioaccel2_cmd_pool));
return 0;
clean_up:
if (h->ioaccel2_cmd_pool)
pci_free_consistent(h->pdev,
h->nr_cmds * sizeof(*h->ioaccel2_cmd_pool),
h->ioaccel2_cmd_pool, h->ioaccel2_cmd_pool_dhandle);
kfree(h->ioaccel2_blockFetchTable);
return 1;
}
static void hpsa_put_ctlr_into_performant_mode(struct ctlr_info *h)
{
u32 trans_support;
unsigned long transMethod = CFGTBL_Trans_Performant |
CFGTBL_Trans_use_short_tags;
int i;
if (hpsa_simple_mode)
return;
trans_support = readl(&(h->cfgtable->TransportSupport));
if (!(trans_support & PERFORMANT_MODE))
return;
if (trans_support & CFGTBL_Trans_io_accel1) {
transMethod |= CFGTBL_Trans_io_accel1 |
CFGTBL_Trans_enable_directed_msix;
if (hpsa_alloc_ioaccel_cmd_and_bft(h))
goto clean_up;
} else {
if (trans_support & CFGTBL_Trans_io_accel2) {
transMethod |= CFGTBL_Trans_io_accel2 |
CFGTBL_Trans_enable_directed_msix;
if (ioaccel2_alloc_cmds_and_bft(h))
goto clean_up;
}
}
h->nreply_queues = h->msix_vector > 0 ? h->msix_vector : 1;
hpsa_get_max_perf_mode_cmds(h);
h->reply_queue_size = h->max_commands * sizeof(u64);
for (i = 0; i < h->nreply_queues; i++) {
h->reply_queue[i].head = pci_alloc_consistent(h->pdev,
h->reply_queue_size,
&(h->reply_queue[i].busaddr));
if (!h->reply_queue[i].head)
goto clean_up;
h->reply_queue[i].size = h->max_commands;
h->reply_queue[i].wraparound = 1;
h->reply_queue[i].current_entry = 0;
}
h->blockFetchTable = kmalloc(((SG_ENTRIES_IN_CMD + 1) *
sizeof(u32)), GFP_KERNEL);
if (!h->blockFetchTable)
goto clean_up;
hpsa_enter_performant_mode(h, trans_support);
return;
clean_up:
hpsa_free_reply_queues(h);
kfree(h->blockFetchTable);
}
static int is_accelerated_cmd(struct CommandList *c)
{
return c->cmd_type == CMD_IOACCEL1 || c->cmd_type == CMD_IOACCEL2;
}
static void hpsa_drain_accel_commands(struct ctlr_info *h)
{
struct CommandList *c = NULL;
unsigned long flags;
int accel_cmds_out;
do {
accel_cmds_out = 0;
spin_lock_irqsave(&h->lock, flags);
list_for_each_entry(c, &h->cmpQ, list)
accel_cmds_out += is_accelerated_cmd(c);
list_for_each_entry(c, &h->reqQ, list)
accel_cmds_out += is_accelerated_cmd(c);
spin_unlock_irqrestore(&h->lock, flags);
if (accel_cmds_out <= 0)
break;
msleep(100);
} while (1);
}
static int __init hpsa_init(void)
{
return pci_register_driver(&hpsa_pci_driver);
}
static void __exit hpsa_cleanup(void)
{
pci_unregister_driver(&hpsa_pci_driver);
}
