static struct llun_info *create_local(struct scsi_device *sdev, u8 *wwid)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = NULL;
lli = kzalloc(sizeof(*lli), GFP_KERNEL);
if (unlikely(!lli)) {
dev_err(dev, "%s: could not allocate lli\n", __func__);
goto out;
}
lli->sdev = sdev;
lli->host_no = sdev->host->host_no;
lli->in_table = false;
memcpy(lli->wwid, wwid, DK_CXLFLASH_MANAGE_LUN_WWID_LEN);
out:
return lli;
}
static struct glun_info *create_global(struct scsi_device *sdev, u8 *wwid)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct glun_info *gli = NULL;
gli = kzalloc(sizeof(*gli), GFP_KERNEL);
if (unlikely(!gli)) {
dev_err(dev, "%s: could not allocate gli\n", __func__);
goto out;
}
mutex_init(&gli->mutex);
memcpy(gli->wwid, wwid, DK_CXLFLASH_MANAGE_LUN_WWID_LEN);
out:
return gli;
}
static struct llun_info *lookup_local(struct cxlflash_cfg *cfg, u8 *wwid)
{
struct llun_info *lli, *temp;
list_for_each_entry_safe(lli, temp, &cfg->lluns, list)
if (!memcmp(lli->wwid, wwid, DK_CXLFLASH_MANAGE_LUN_WWID_LEN))
return lli;
return NULL;
}
static struct glun_info *lookup_global(u8 *wwid)
{
struct glun_info *gli, *temp;
list_for_each_entry_safe(gli, temp, &global.gluns, list)
if (!memcmp(gli->wwid, wwid, DK_CXLFLASH_MANAGE_LUN_WWID_LEN))
return gli;
return NULL;
}
static struct llun_info *find_and_create_lun(struct scsi_device *sdev, u8 *wwid)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = NULL;
struct glun_info *gli = NULL;
if (unlikely(!wwid))
goto out;
lli = lookup_local(cfg, wwid);
if (lli)
goto out;
lli = create_local(sdev, wwid);
if (unlikely(!lli))
goto out;
gli = lookup_global(wwid);
if (gli) {
lli->parent = gli;
list_add(&lli->list, &cfg->lluns);
goto out;
}
gli = create_global(sdev, wwid);
if (unlikely(!gli)) {
kfree(lli);
lli = NULL;
goto out;
}
lli->parent = gli;
list_add(&lli->list, &cfg->lluns);
list_add(&gli->list, &global.gluns);
out:
dev_dbg(dev, "%s: returning lli=%p, gli=%p\n", __func__, lli, gli);
return lli;
}
void cxlflash_term_local_luns(struct cxlflash_cfg *cfg)
{
struct llun_info *lli, *temp;
mutex_lock(&global.mutex);
list_for_each_entry_safe(lli, temp, &cfg->lluns, list) {
list_del(&lli->list);
kfree(lli);
}
mutex_unlock(&global.mutex);
}
void cxlflash_list_init(void)
{
INIT_LIST_HEAD(&global.gluns);
mutex_init(&global.mutex);
global.err_page = NULL;
}
void cxlflash_term_global_luns(void)
{
struct glun_info *gli, *temp;
mutex_lock(&global.mutex);
list_for_each_entry_safe(gli, temp, &global.gluns, list) {
list_del(&gli->list);
cxlflash_ba_terminate(&gli->blka.ba_lun);
kfree(gli);
}
mutex_unlock(&global.mutex);
}
int cxlflash_manage_lun(struct scsi_device *sdev,
struct dk_cxlflash_manage_lun *manage)
{
struct cxlflash_cfg *cfg = shost_priv(sdev->host);
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = NULL;
int rc = 0;
u64 flags = manage->hdr.flags;
u32 chan = sdev->channel;
mutex_lock(&global.mutex);
lli = find_and_create_lun(sdev, manage->wwid);
dev_dbg(dev, "%s: WWID=%016llx%016llx, flags=%016llx lli=%p\n",
__func__, get_unaligned_be64(&manage->wwid[0]),
get_unaligned_be64(&manage->wwid[8]), manage->hdr.flags, lli);
if (unlikely(!lli)) {
rc = -ENOMEM;
goto out;
}
if (flags & DK_CXLFLASH_MANAGE_LUN_ENABLE_SUPERPIPE) {
lli->port_sel |= CHAN2PORTMASK(chan);
lli->lun_id[chan] = lun_to_lunid(sdev->lun);
sdev->hostdata = lli;
} else if (flags & DK_CXLFLASH_MANAGE_LUN_DISABLE_SUPERPIPE) {
if (lli->parent->mode != MODE_NONE)
rc = -EBUSY;
else {
sdev->hostdata = NULL;
lli->port_sel &= ~CHAN2PORTMASK(chan);
if (lli->port_sel == 0U)
lli->in_table = false;
}
}
dev_dbg(dev, "%s: port_sel=%08x chan=%u lun_id=%016llx\n",
__func__, lli->port_sel, chan, lli->lun_id[chan]);
out:
mutex_unlock(&global.mutex);
dev_dbg(dev, "%s: returning rc=%d\n", __func__, rc);
return rc;
}
