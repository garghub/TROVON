static inline struct pscsi_dev_virt *PSCSI_DEV(struct se_device *dev)
{
return container_of(dev, struct pscsi_dev_virt, dev);
}
static int pscsi_attach_hba(struct se_hba *hba, u32 host_id)
{
struct pscsi_hba_virt *phv;
phv = kzalloc(sizeof(struct pscsi_hba_virt), GFP_KERNEL);
if (!phv) {
pr_err("Unable to allocate struct pscsi_hba_virt\n");
return -ENOMEM;
}
phv->phv_host_id = host_id;
phv->phv_mode = PHV_VIRTUAL_HOST_ID;
hba->hba_ptr = phv;
pr_debug("CORE_HBA[%d] - TCM SCSI HBA Driver %s on"
" Generic Target Core Stack %s\n", hba->hba_id,
PSCSI_VERSION, TARGET_CORE_MOD_VERSION);
pr_debug("CORE_HBA[%d] - Attached SCSI HBA to Generic\n",
hba->hba_id);
return 0;
}
static void pscsi_detach_hba(struct se_hba *hba)
{
struct pscsi_hba_virt *phv = hba->hba_ptr;
struct Scsi_Host *scsi_host = phv->phv_lld_host;
if (scsi_host) {
scsi_host_put(scsi_host);
pr_debug("CORE_HBA[%d] - Detached SCSI HBA: %s from"
" Generic Target Core\n", hba->hba_id,
(scsi_host->hostt->name) ? (scsi_host->hostt->name) :
"Unknown");
} else
pr_debug("CORE_HBA[%d] - Detached Virtual SCSI HBA"
" from Generic Target Core\n", hba->hba_id);
kfree(phv);
hba->hba_ptr = NULL;
}
static int pscsi_pmode_enable_hba(struct se_hba *hba, unsigned long mode_flag)
{
struct pscsi_hba_virt *phv = hba->hba_ptr;
struct Scsi_Host *sh = phv->phv_lld_host;
if (!mode_flag) {
if (!sh)
return 0;
phv->phv_lld_host = NULL;
phv->phv_mode = PHV_VIRTUAL_HOST_ID;
pr_debug("CORE_HBA[%d] - Disabled pSCSI HBA Passthrough"
" %s\n", hba->hba_id, (sh->hostt->name) ?
(sh->hostt->name) : "Unknown");
scsi_host_put(sh);
return 0;
}
sh = scsi_host_lookup(phv->phv_host_id);
if (!sh) {
pr_err("pSCSI: Unable to locate SCSI Host for"
" phv_host_id: %d\n", phv->phv_host_id);
return -EINVAL;
}
phv->phv_lld_host = sh;
phv->phv_mode = PHV_LLD_SCSI_HOST_NO;
pr_debug("CORE_HBA[%d] - Enabled pSCSI HBA Passthrough %s\n",
hba->hba_id, (sh->hostt->name) ? (sh->hostt->name) : "Unknown");
return 1;
}
static void pscsi_tape_read_blocksize(struct se_device *dev,
struct scsi_device *sdev)
{
unsigned char cdb[MAX_COMMAND_SIZE], *buf;
int ret;
buf = kzalloc(12, GFP_KERNEL);
if (!buf)
return;
memset(cdb, 0, MAX_COMMAND_SIZE);
cdb[0] = MODE_SENSE;
cdb[4] = 0x0c;
ret = scsi_execute_req(sdev, cdb, DMA_FROM_DEVICE, buf, 12, NULL,
HZ, 1, NULL);
if (ret)
goto out_free;
sdev->sector_size = (buf[9] << 16) | (buf[10] << 8) | (buf[11]);
if (!sdev->sector_size)
sdev->sector_size = 1024;
out_free:
kfree(buf);
}
static void
pscsi_set_inquiry_info(struct scsi_device *sdev, struct t10_wwn *wwn)
{
unsigned char *buf;
if (sdev->inquiry_len < INQUIRY_LEN)
return;
buf = sdev->inquiry;
if (!buf)
return;
memcpy(&wwn->vendor[0], &buf[8], sizeof(wwn->vendor));
memcpy(&wwn->model[0], &buf[16], sizeof(wwn->model));
memcpy(&wwn->revision[0], &buf[32], sizeof(wwn->revision));
}
static int
pscsi_get_inquiry_vpd_serial(struct scsi_device *sdev, struct t10_wwn *wwn)
{
unsigned char cdb[MAX_COMMAND_SIZE], *buf;
int ret;
buf = kzalloc(INQUIRY_VPD_SERIAL_LEN, GFP_KERNEL);
if (!buf)
return -ENOMEM;
memset(cdb, 0, MAX_COMMAND_SIZE);
cdb[0] = INQUIRY;
cdb[1] = 0x01;
cdb[2] = 0x80;
cdb[3] = (INQUIRY_VPD_SERIAL_LEN >> 8) & 0xff;
cdb[4] = (INQUIRY_VPD_SERIAL_LEN & 0xff);
ret = scsi_execute_req(sdev, cdb, DMA_FROM_DEVICE, buf,
INQUIRY_VPD_SERIAL_LEN, NULL, HZ, 1, NULL);
if (ret)
goto out_free;
snprintf(&wwn->unit_serial[0], INQUIRY_VPD_SERIAL_LEN, "%s", &buf[4]);
wwn->t10_dev->dev_flags |= DF_FIRMWARE_VPD_UNIT_SERIAL;
kfree(buf);
return 0;
out_free:
kfree(buf);
return -EPERM;
}
static void
pscsi_get_inquiry_vpd_device_ident(struct scsi_device *sdev,
struct t10_wwn *wwn)
{
unsigned char cdb[MAX_COMMAND_SIZE], *buf, *page_83;
int ident_len, page_len, off = 4, ret;
struct t10_vpd *vpd;
buf = kzalloc(INQUIRY_VPD_SERIAL_LEN, GFP_KERNEL);
if (!buf)
return;
memset(cdb, 0, MAX_COMMAND_SIZE);
cdb[0] = INQUIRY;
cdb[1] = 0x01;
cdb[2] = 0x83;
cdb[3] = (INQUIRY_VPD_DEVICE_IDENTIFIER_LEN >> 8) & 0xff;
cdb[4] = (INQUIRY_VPD_DEVICE_IDENTIFIER_LEN & 0xff);
ret = scsi_execute_req(sdev, cdb, DMA_FROM_DEVICE, buf,
INQUIRY_VPD_DEVICE_IDENTIFIER_LEN,
NULL, HZ, 1, NULL);
if (ret)
goto out;
page_len = (buf[2] << 8) | buf[3];
while (page_len > 0) {
page_83 = &buf[off];
ident_len = page_83[3];
if (!ident_len) {
pr_err("page_83[3]: identifier"
" length zero!\n");
break;
}
pr_debug("T10 VPD Identifier Length: %d\n", ident_len);
vpd = kzalloc(sizeof(struct t10_vpd), GFP_KERNEL);
if (!vpd) {
pr_err("Unable to allocate memory for"
" struct t10_vpd\n");
goto out;
}
INIT_LIST_HEAD(&vpd->vpd_list);
transport_set_vpd_proto_id(vpd, page_83);
transport_set_vpd_assoc(vpd, page_83);
if (transport_set_vpd_ident_type(vpd, page_83) < 0) {
off += (ident_len + 4);
page_len -= (ident_len + 4);
kfree(vpd);
continue;
}
if (transport_set_vpd_ident(vpd, page_83) < 0) {
off += (ident_len + 4);
page_len -= (ident_len + 4);
kfree(vpd);
continue;
}
list_add_tail(&vpd->vpd_list, &wwn->t10_vpd_list);
off += (ident_len + 4);
page_len -= (ident_len + 4);
}
out:
kfree(buf);
}
static int pscsi_add_device_to_list(struct se_device *dev,
struct scsi_device *sd)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct request_queue *q = sd->request_queue;
pdv->pdv_sd = sd;
if (!sd->queue_depth) {
sd->queue_depth = PSCSI_DEFAULT_QUEUEDEPTH;
pr_err("Set broken SCSI Device %d:%d:%d"
" queue_depth to %d\n", sd->channel, sd->id,
sd->lun, sd->queue_depth);
}
dev->dev_attrib.hw_block_size = sd->sector_size;
dev->dev_attrib.hw_max_sectors =
min_t(int, sd->host->max_sectors, queue_max_hw_sectors(q));
dev->dev_attrib.hw_queue_depth = sd->queue_depth;
pscsi_set_inquiry_info(sd, &dev->t10_wwn);
if (!pscsi_get_inquiry_vpd_serial(sd, &dev->t10_wwn)) {
pscsi_get_inquiry_vpd_device_ident(sd, &dev->t10_wwn);
}
if (sd->type == TYPE_TAPE)
pscsi_tape_read_blocksize(dev, sd);
return 0;
}
static struct se_device *pscsi_alloc_device(struct se_hba *hba,
const char *name)
{
struct pscsi_dev_virt *pdv;
pdv = kzalloc(sizeof(struct pscsi_dev_virt), GFP_KERNEL);
if (!pdv) {
pr_err("Unable to allocate memory for struct pscsi_dev_virt\n");
return NULL;
}
pr_debug("PSCSI: Allocated pdv: %p for %s\n", pdv, name);
return &pdv->dev;
}
static int pscsi_create_type_disk(struct se_device *dev, struct scsi_device *sd)
__releases(sh->host_lock)
{
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct Scsi_Host *sh = sd->host;
struct block_device *bd;
int ret;
if (scsi_device_get(sd)) {
pr_err("scsi_device_get() failed for %d:%d:%d:%d\n",
sh->host_no, sd->channel, sd->id, sd->lun);
spin_unlock_irq(sh->host_lock);
return -EIO;
}
spin_unlock_irq(sh->host_lock);
bd = blkdev_get_by_path(dev->udev_path,
FMODE_WRITE|FMODE_READ|FMODE_EXCL, pdv);
if (IS_ERR(bd)) {
pr_err("pSCSI: blkdev_get_by_path() failed\n");
scsi_device_put(sd);
return PTR_ERR(bd);
}
pdv->pdv_bd = bd;
ret = pscsi_add_device_to_list(dev, sd);
if (ret) {
blkdev_put(pdv->pdv_bd, FMODE_WRITE|FMODE_READ|FMODE_EXCL);
scsi_device_put(sd);
return ret;
}
pr_debug("CORE_PSCSI[%d] - Added TYPE_DISK for %d:%d:%d:%d\n",
phv->phv_host_id, sh->host_no, sd->channel, sd->id, sd->lun);
return 0;
}
static int pscsi_create_type_rom(struct se_device *dev, struct scsi_device *sd)
__releases(sh->host_lock)
{
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
struct Scsi_Host *sh = sd->host;
int ret;
if (scsi_device_get(sd)) {
pr_err("scsi_device_get() failed for %d:%d:%d:%d\n",
sh->host_no, sd->channel, sd->id, sd->lun);
spin_unlock_irq(sh->host_lock);
return -EIO;
}
spin_unlock_irq(sh->host_lock);
ret = pscsi_add_device_to_list(dev, sd);
if (ret) {
scsi_device_put(sd);
return ret;
}
pr_debug("CORE_PSCSI[%d] - Added Type: %s for %d:%d:%d:%d\n",
phv->phv_host_id, scsi_device_type(sd->type), sh->host_no,
sd->channel, sd->id, sd->lun);
return 0;
}
static int pscsi_create_type_other(struct se_device *dev,
struct scsi_device *sd)
__releases(sh->host_lock)
{
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
struct Scsi_Host *sh = sd->host;
int ret;
spin_unlock_irq(sh->host_lock);
ret = pscsi_add_device_to_list(dev, sd);
if (ret)
return ret;
pr_debug("CORE_PSCSI[%d] - Added Type: %s for %d:%d:%d:%d\n",
phv->phv_host_id, scsi_device_type(sd->type), sh->host_no,
sd->channel, sd->id, sd->lun);
return 0;
}
static int pscsi_configure_device(struct se_device *dev)
{
struct se_hba *hba = dev->se_hba;
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct scsi_device *sd;
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
struct Scsi_Host *sh = phv->phv_lld_host;
int legacy_mode_enable = 0;
int ret;
if (!(pdv->pdv_flags & PDF_HAS_CHANNEL_ID) ||
!(pdv->pdv_flags & PDF_HAS_TARGET_ID) ||
!(pdv->pdv_flags & PDF_HAS_LUN_ID)) {
pr_err("Missing scsi_channel_id=, scsi_target_id= and"
" scsi_lun_id= parameters\n");
return -EINVAL;
}
if (!sh) {
if (phv->phv_mode == PHV_LLD_SCSI_HOST_NO) {
pr_err("pSCSI: Unable to locate struct"
" Scsi_Host for PHV_LLD_SCSI_HOST_NO\n");
return -ENODEV;
}
if (!(dev->dev_flags & DF_USING_UDEV_PATH)) {
pr_err("pSCSI: udev_path attribute has not"
" been set before ENABLE=1\n");
return -EINVAL;
}
if (!(pdv->pdv_flags & PDF_HAS_VIRT_HOST_ID)) {
if (hba->dev_count) {
pr_err("pSCSI: Unable to set hba_mode"
" with active devices\n");
return -EEXIST;
}
if (pscsi_pmode_enable_hba(hba, 1) != 1)
return -ENODEV;
legacy_mode_enable = 1;
hba->hba_flags |= HBA_FLAGS_PSCSI_MODE;
sh = phv->phv_lld_host;
} else {
sh = scsi_host_lookup(pdv->pdv_host_id);
if (!sh) {
pr_err("pSCSI: Unable to locate"
" pdv_host_id: %d\n", pdv->pdv_host_id);
return -EINVAL;
}
}
} else {
if (phv->phv_mode == PHV_VIRTUAL_HOST_ID) {
pr_err("pSCSI: PHV_VIRTUAL_HOST_ID set while"
" struct Scsi_Host exists\n");
return -EEXIST;
}
}
spin_lock_irq(sh->host_lock);
list_for_each_entry(sd, &sh->__devices, siblings) {
if ((pdv->pdv_channel_id != sd->channel) ||
(pdv->pdv_target_id != sd->id) ||
(pdv->pdv_lun_id != sd->lun))
continue;
switch (sd->type) {
case TYPE_DISK:
ret = pscsi_create_type_disk(dev, sd);
break;
case TYPE_ROM:
ret = pscsi_create_type_rom(dev, sd);
break;
default:
ret = pscsi_create_type_other(dev, sd);
break;
}
if (ret) {
if (phv->phv_mode == PHV_VIRTUAL_HOST_ID)
scsi_host_put(sh);
else if (legacy_mode_enable) {
pscsi_pmode_enable_hba(hba, 0);
hba->hba_flags &= ~HBA_FLAGS_PSCSI_MODE;
}
pdv->pdv_sd = NULL;
return ret;
}
return 0;
}
spin_unlock_irq(sh->host_lock);
pr_err("pSCSI: Unable to locate %d:%d:%d:%d\n", sh->host_no,
pdv->pdv_channel_id, pdv->pdv_target_id, pdv->pdv_lun_id);
if (phv->phv_mode == PHV_VIRTUAL_HOST_ID)
scsi_host_put(sh);
else if (legacy_mode_enable) {
pscsi_pmode_enable_hba(hba, 0);
hba->hba_flags &= ~HBA_FLAGS_PSCSI_MODE;
}
return -ENODEV;
}
static void pscsi_free_device(struct se_device *dev)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
struct scsi_device *sd = pdv->pdv_sd;
if (sd) {
if ((sd->type == TYPE_DISK) && pdv->pdv_bd) {
blkdev_put(pdv->pdv_bd,
FMODE_WRITE|FMODE_READ|FMODE_EXCL);
pdv->pdv_bd = NULL;
}
if ((phv->phv_mode == PHV_LLD_SCSI_HOST_NO) &&
(phv->phv_lld_host != NULL))
scsi_host_put(phv->phv_lld_host);
if ((sd->type == TYPE_DISK) || (sd->type == TYPE_ROM))
scsi_device_put(sd);
pdv->pdv_sd = NULL;
}
kfree(pdv);
}
static void pscsi_transport_complete(struct se_cmd *cmd, struct scatterlist *sg,
unsigned char *sense_buffer)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(cmd->se_dev);
struct scsi_device *sd = pdv->pdv_sd;
int result;
struct pscsi_plugin_task *pt = cmd->priv;
unsigned char *cdb;
if (!pt)
return;
cdb = &pt->pscsi_cdb[0];
result = pt->pscsi_result;
if (!cmd->se_deve || !cmd->data_length)
goto after_mode_sense;
if (((cdb[0] == MODE_SENSE) || (cdb[0] == MODE_SENSE_10)) &&
(status_byte(result) << 1) == SAM_STAT_GOOD) {
if (cmd->se_deve->lun_flags & TRANSPORT_LUNFLAGS_READ_ONLY) {
unsigned char *buf;
buf = transport_kmap_data_sg(cmd);
if (!buf)
;
if (cdb[0] == MODE_SENSE_10) {
if (!(buf[3] & 0x80))
buf[3] |= 0x80;
} else {
if (!(buf[2] & 0x80))
buf[2] |= 0x80;
}
transport_kunmap_data_sg(cmd);
}
}
after_mode_sense:
if (sd->type != TYPE_TAPE || !cmd->data_length)
goto after_mode_select;
if (((cdb[0] == MODE_SELECT) || (cdb[0] == MODE_SELECT_10)) &&
(status_byte(result) << 1) == SAM_STAT_GOOD) {
unsigned char *buf;
u16 bdl;
u32 blocksize;
buf = sg_virt(&sg[0]);
if (!buf) {
pr_err("Unable to get buf for scatterlist\n");
goto after_mode_select;
}
if (cdb[0] == MODE_SELECT)
bdl = (buf[3]);
else
bdl = (buf[6] << 8) | (buf[7]);
if (!bdl)
goto after_mode_select;
if (cdb[0] == MODE_SELECT)
blocksize = (buf[9] << 16) | (buf[10] << 8) |
(buf[11]);
else
blocksize = (buf[13] << 16) | (buf[14] << 8) |
(buf[15]);
sd->sector_size = blocksize;
}
after_mode_select:
if (sense_buffer && (status_byte(result) & CHECK_CONDITION)) {
memcpy(sense_buffer, pt->pscsi_sense, TRANSPORT_SENSE_BUFFER);
cmd->se_cmd_flags |= SCF_TRANSPORT_TASK_SENSE;
}
}
static ssize_t pscsi_set_configfs_dev_params(struct se_device *dev,
const char *page, ssize_t count)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
char *orig, *ptr, *opts;
substring_t args[MAX_OPT_ARGS];
int ret = 0, arg, token;
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",\n")) != NULL) {
if (!*ptr)
continue;
token = match_token(ptr, tokens, args);
switch (token) {
case Opt_scsi_host_id:
if (phv->phv_mode == PHV_LLD_SCSI_HOST_NO) {
pr_err("PSCSI[%d]: Unable to accept"
" scsi_host_id while phv_mode =="
" PHV_LLD_SCSI_HOST_NO\n",
phv->phv_host_id);
ret = -EINVAL;
goto out;
}
match_int(args, &arg);
pdv->pdv_host_id = arg;
pr_debug("PSCSI[%d]: Referencing SCSI Host ID:"
" %d\n", phv->phv_host_id, pdv->pdv_host_id);
pdv->pdv_flags |= PDF_HAS_VIRT_HOST_ID;
break;
case Opt_scsi_channel_id:
match_int(args, &arg);
pdv->pdv_channel_id = arg;
pr_debug("PSCSI[%d]: Referencing SCSI Channel"
" ID: %d\n", phv->phv_host_id,
pdv->pdv_channel_id);
pdv->pdv_flags |= PDF_HAS_CHANNEL_ID;
break;
case Opt_scsi_target_id:
match_int(args, &arg);
pdv->pdv_target_id = arg;
pr_debug("PSCSI[%d]: Referencing SCSI Target"
" ID: %d\n", phv->phv_host_id,
pdv->pdv_target_id);
pdv->pdv_flags |= PDF_HAS_TARGET_ID;
break;
case Opt_scsi_lun_id:
match_int(args, &arg);
pdv->pdv_lun_id = arg;
pr_debug("PSCSI[%d]: Referencing SCSI LUN ID:"
" %d\n", phv->phv_host_id, pdv->pdv_lun_id);
pdv->pdv_flags |= PDF_HAS_LUN_ID;
break;
default:
break;
}
}
out:
kfree(orig);
return (!ret) ? count : ret;
}
static ssize_t pscsi_show_configfs_dev_params(struct se_device *dev, char *b)
{
struct pscsi_hba_virt *phv = dev->se_hba->hba_ptr;
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct scsi_device *sd = pdv->pdv_sd;
unsigned char host_id[16];
ssize_t bl;
int i;
if (phv->phv_mode == PHV_VIRTUAL_HOST_ID)
snprintf(host_id, 16, "%d", pdv->pdv_host_id);
else
snprintf(host_id, 16, "PHBA Mode");
bl = sprintf(b, "SCSI Device Bus Location:"
" Channel ID: %d Target ID: %d LUN: %d Host ID: %s\n",
pdv->pdv_channel_id, pdv->pdv_target_id, pdv->pdv_lun_id,
host_id);
if (sd) {
bl += sprintf(b + bl, " ");
bl += sprintf(b + bl, "Vendor: ");
for (i = 0; i < 8; i++) {
if (ISPRINT(sd->vendor[i]))
bl += sprintf(b + bl, "%c", sd->vendor[i]);
else
bl += sprintf(b + bl, " ");
}
bl += sprintf(b + bl, " Model: ");
for (i = 0; i < 16; i++) {
if (ISPRINT(sd->model[i]))
bl += sprintf(b + bl, "%c", sd->model[i]);
else
bl += sprintf(b + bl, " ");
}
bl += sprintf(b + bl, " Rev: ");
for (i = 0; i < 4; i++) {
if (ISPRINT(sd->rev[i]))
bl += sprintf(b + bl, "%c", sd->rev[i]);
else
bl += sprintf(b + bl, " ");
}
bl += sprintf(b + bl, "\n");
}
return bl;
}
static void pscsi_bi_endio(struct bio *bio, int error)
{
bio_put(bio);
}
static inline struct bio *pscsi_get_bio(int nr_vecs)
{
struct bio *bio;
bio = bio_kmalloc(GFP_KERNEL, nr_vecs);
if (!bio) {
pr_err("PSCSI: bio_kmalloc() failed\n");
return NULL;
}
bio->bi_end_io = pscsi_bi_endio;
return bio;
}
static sense_reason_t
pscsi_map_sg(struct se_cmd *cmd, struct scatterlist *sgl, u32 sgl_nents,
enum dma_data_direction data_direction, struct bio **hbio)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(cmd->se_dev);
struct bio *bio = NULL, *tbio = NULL;
struct page *page;
struct scatterlist *sg;
u32 data_len = cmd->data_length, i, len, bytes, off;
int nr_pages = (cmd->data_length + sgl[0].offset +
PAGE_SIZE - 1) >> PAGE_SHIFT;
int nr_vecs = 0, rc;
int rw = (data_direction == DMA_TO_DEVICE);
*hbio = NULL;
pr_debug("PSCSI: nr_pages: %d\n", nr_pages);
for_each_sg(sgl, sg, sgl_nents, i) {
page = sg_page(sg);
off = sg->offset;
len = sg->length;
pr_debug("PSCSI: i: %d page: %p len: %d off: %d\n", i,
page, len, off);
if (off + len > PAGE_SIZE)
goto fail;
if (len > 0 && data_len > 0) {
bytes = min_t(unsigned int, len, PAGE_SIZE - off);
bytes = min(bytes, data_len);
if (!bio) {
nr_vecs = min_t(int, BIO_MAX_PAGES, nr_pages);
nr_pages -= nr_vecs;
bio = pscsi_get_bio(nr_vecs);
if (!bio)
goto fail;
if (rw)
bio->bi_rw |= REQ_WRITE;
pr_debug("PSCSI: Allocated bio: %p,"
" dir: %s nr_vecs: %d\n", bio,
(rw) ? "rw" : "r", nr_vecs);
if (!*hbio)
*hbio = tbio = bio;
else
tbio = tbio->bi_next = bio;
}
pr_debug("PSCSI: Calling bio_add_pc_page() i: %d"
" bio: %p page: %p len: %d off: %d\n", i, bio,
page, len, off);
rc = bio_add_pc_page(pdv->pdv_sd->request_queue,
bio, page, bytes, off);
if (rc != bytes)
goto fail;
pr_debug("PSCSI: bio->bi_vcnt: %d nr_vecs: %d\n",
bio->bi_vcnt, nr_vecs);
if (bio->bi_vcnt > nr_vecs) {
pr_debug("PSCSI: Reached bio->bi_vcnt max:"
" %d i: %d bio: %p, allocating another"
" bio\n", bio->bi_vcnt, i, bio);
bio = NULL;
}
data_len -= bytes;
}
}
return 0;
fail:
while (*hbio) {
bio = *hbio;
*hbio = (*hbio)->bi_next;
bio_endio(bio, 0);
}
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
static inline void pscsi_clear_cdb_lun(unsigned char *cdb)
{
switch (cdb[0]) {
case READ_10:
case READ_12:
case READ_16:
case SEND_DIAGNOSTIC:
case VERIFY:
case VERIFY_16:
case WRITE_VERIFY:
case WRITE_VERIFY_12:
case MAINTENANCE_IN:
break;
default:
cdb[1] &= 0x1f;
break;
}
}
static sense_reason_t
pscsi_parse_cdb(struct se_cmd *cmd)
{
unsigned char *cdb = cmd->t_task_cdb;
if (cmd->se_cmd_flags & SCF_BIDI)
return TCM_UNSUPPORTED_SCSI_OPCODE;
pscsi_clear_cdb_lun(cdb);
switch (cdb[0]) {
case REPORT_LUNS:
cmd->execute_cmd = spc_emulate_report_luns;
return 0;
case READ_6:
case READ_10:
case READ_12:
case READ_16:
case WRITE_6:
case WRITE_10:
case WRITE_12:
case WRITE_16:
case WRITE_VERIFY:
cmd->se_cmd_flags |= SCF_SCSI_DATA_CDB;
default:
cmd->execute_cmd = pscsi_execute_cmd;
return 0;
}
}
static sense_reason_t
pscsi_execute_cmd(struct se_cmd *cmd)
{
struct scatterlist *sgl = cmd->t_data_sg;
u32 sgl_nents = cmd->t_data_nents;
enum dma_data_direction data_direction = cmd->data_direction;
struct pscsi_dev_virt *pdv = PSCSI_DEV(cmd->se_dev);
struct pscsi_plugin_task *pt;
struct request *req;
struct bio *hbio;
sense_reason_t ret;
pt = kzalloc(sizeof(*pt) + scsi_command_size(cmd->t_task_cdb), GFP_KERNEL);
if (!pt) {
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
cmd->priv = pt;
memcpy(pt->pscsi_cdb, cmd->t_task_cdb,
scsi_command_size(cmd->t_task_cdb));
if (!sgl) {
req = blk_get_request(pdv->pdv_sd->request_queue,
(data_direction == DMA_TO_DEVICE),
GFP_KERNEL);
if (!req) {
pr_err("PSCSI: blk_get_request() failed\n");
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto fail;
}
} else {
BUG_ON(!cmd->data_length);
ret = pscsi_map_sg(cmd, sgl, sgl_nents, data_direction, &hbio);
if (ret)
goto fail;
req = blk_make_request(pdv->pdv_sd->request_queue, hbio,
GFP_KERNEL);
if (IS_ERR(req)) {
pr_err("pSCSI: blk_make_request() failed\n");
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
goto fail_free_bio;
}
}
req->cmd_type = REQ_TYPE_BLOCK_PC;
req->end_io = pscsi_req_done;
req->end_io_data = cmd;
req->cmd_len = scsi_command_size(pt->pscsi_cdb);
req->cmd = &pt->pscsi_cdb[0];
req->sense = &pt->pscsi_sense[0];
req->sense_len = 0;
if (pdv->pdv_sd->type == TYPE_DISK)
req->timeout = PS_TIMEOUT_DISK;
else
req->timeout = PS_TIMEOUT_OTHER;
req->retries = PS_RETRY;
blk_execute_rq_nowait(pdv->pdv_sd->request_queue, NULL, req,
(cmd->sam_task_attr == MSG_HEAD_TAG),
pscsi_req_done);
return 0;
fail_free_bio:
while (hbio) {
struct bio *bio = hbio;
hbio = hbio->bi_next;
bio_endio(bio, 0);
}
ret = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
fail:
kfree(pt);
return ret;
}
static u32 pscsi_get_device_type(struct se_device *dev)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
struct scsi_device *sd = pdv->pdv_sd;
return sd->type;
}
static sector_t pscsi_get_blocks(struct se_device *dev)
{
struct pscsi_dev_virt *pdv = PSCSI_DEV(dev);
if (pdv->pdv_bd && pdv->pdv_bd->bd_part)
return pdv->pdv_bd->bd_part->nr_sects;
dump_stack();
return 0;
}
static void pscsi_req_done(struct request *req, int uptodate)
{
struct se_cmd *cmd = req->end_io_data;
struct pscsi_plugin_task *pt = cmd->priv;
pt->pscsi_result = req->errors;
pt->pscsi_resid = req->resid_len;
cmd->scsi_status = status_byte(pt->pscsi_result) << 1;
if (cmd->scsi_status) {
pr_debug("PSCSI Status Byte exception at cmd: %p CDB:"
" 0x%02x Result: 0x%08x\n", cmd, pt->pscsi_cdb[0],
pt->pscsi_result);
}
switch (host_byte(pt->pscsi_result)) {
case DID_OK:
target_complete_cmd(cmd, cmd->scsi_status);
break;
default:
pr_debug("PSCSI Host Byte exception at cmd: %p CDB:"
" 0x%02x Result: 0x%08x\n", cmd, pt->pscsi_cdb[0],
pt->pscsi_result);
target_complete_cmd(cmd, SAM_STAT_CHECK_CONDITION);
break;
}
__blk_put_request(req->q, req);
kfree(pt);
}
static int __init pscsi_module_init(void)
{
return transport_subsystem_register(&pscsi_template);
}
static void __exit pscsi_module_exit(void)
{
transport_subsystem_release(&pscsi_template);
}
