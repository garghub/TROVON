static void release_port_group(struct kref *kref)
{
struct alua_port_group *pg;
pg = container_of(kref, struct alua_port_group, kref);
if (pg->rtpg_sdev)
flush_delayed_work(&pg->rtpg_work);
spin_lock(&port_group_lock);
list_del(&pg->node);
spin_unlock(&port_group_lock);
kfree_rcu(pg, rcu);
}
static int submit_rtpg(struct scsi_device *sdev, unsigned char *buff,
int bufflen, struct scsi_sense_hdr *sshdr, int flags)
{
u8 cdb[COMMAND_SIZE(MAINTENANCE_IN)];
int req_flags = REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
memset(cdb, 0x0, COMMAND_SIZE(MAINTENANCE_IN));
cdb[0] = MAINTENANCE_IN;
if (!(flags & ALUA_RTPG_EXT_HDR_UNSUPP))
cdb[1] = MI_REPORT_TARGET_PGS | MI_EXT_HDR_PARAM_FMT;
else
cdb[1] = MI_REPORT_TARGET_PGS;
put_unaligned_be32(bufflen, &cdb[6]);
return scsi_execute_req_flags(sdev, cdb, DMA_FROM_DEVICE,
buff, bufflen, sshdr,
ALUA_FAILOVER_TIMEOUT * HZ,
ALUA_FAILOVER_RETRIES, NULL,
req_flags, 0);
}
static int submit_stpg(struct scsi_device *sdev, int group_id,
struct scsi_sense_hdr *sshdr)
{
u8 cdb[COMMAND_SIZE(MAINTENANCE_OUT)];
unsigned char stpg_data[8];
int stpg_len = 8;
int req_flags = REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
memset(stpg_data, 0, stpg_len);
stpg_data[4] = SCSI_ACCESS_STATE_OPTIMAL;
put_unaligned_be16(group_id, &stpg_data[6]);
memset(cdb, 0x0, COMMAND_SIZE(MAINTENANCE_OUT));
cdb[0] = MAINTENANCE_OUT;
cdb[1] = MO_SET_TARGET_PGS;
put_unaligned_be32(stpg_len, &cdb[6]);
return scsi_execute_req_flags(sdev, cdb, DMA_TO_DEVICE,
stpg_data, stpg_len,
sshdr, ALUA_FAILOVER_TIMEOUT * HZ,
ALUA_FAILOVER_RETRIES, NULL,
req_flags, 0);
}
static struct alua_port_group *alua_find_get_pg(char *id_str, size_t id_size,
int group_id)
{
struct alua_port_group *pg;
if (!id_str || !id_size || !strlen(id_str))
return NULL;
list_for_each_entry(pg, &port_group_list, node) {
if (pg->group_id != group_id)
continue;
if (!pg->device_id_len || pg->device_id_len != id_size)
continue;
if (strncmp(pg->device_id_str, id_str, id_size))
continue;
if (!kref_get_unless_zero(&pg->kref))
continue;
return pg;
}
return NULL;
}
static struct alua_port_group *alua_alloc_pg(struct scsi_device *sdev,
int group_id, int tpgs)
{
struct alua_port_group *pg, *tmp_pg;
pg = kzalloc(sizeof(struct alua_port_group), GFP_KERNEL);
if (!pg)
return ERR_PTR(-ENOMEM);
pg->device_id_len = scsi_vpd_lun_id(sdev, pg->device_id_str,
sizeof(pg->device_id_str));
if (pg->device_id_len <= 0) {
sdev_printk(KERN_INFO, sdev,
"%s: No device descriptors found\n",
ALUA_DH_NAME);
pg->device_id_str[0] = '\0';
pg->device_id_len = 0;
}
pg->group_id = group_id;
pg->tpgs = tpgs;
pg->state = SCSI_ACCESS_STATE_OPTIMAL;
if (optimize_stpg)
pg->flags |= ALUA_OPTIMIZE_STPG;
kref_init(&pg->kref);
INIT_DELAYED_WORK(&pg->rtpg_work, alua_rtpg_work);
INIT_LIST_HEAD(&pg->rtpg_list);
INIT_LIST_HEAD(&pg->node);
INIT_LIST_HEAD(&pg->dh_list);
spin_lock_init(&pg->lock);
spin_lock(&port_group_lock);
tmp_pg = alua_find_get_pg(pg->device_id_str, pg->device_id_len,
group_id);
if (tmp_pg) {
spin_unlock(&port_group_lock);
kfree(pg);
return tmp_pg;
}
list_add(&pg->node, &port_group_list);
spin_unlock(&port_group_lock);
return pg;
}
static int alua_check_tpgs(struct scsi_device *sdev)
{
int tpgs = TPGS_MODE_NONE;
if (sdev->type != TYPE_DISK) {
sdev_printk(KERN_INFO, sdev,
"%s: disable for non-disk devices\n",
ALUA_DH_NAME);
return tpgs;
}
tpgs = scsi_device_tpgs(sdev);
switch (tpgs) {
case TPGS_MODE_EXPLICIT|TPGS_MODE_IMPLICIT:
sdev_printk(KERN_INFO, sdev,
"%s: supports implicit and explicit TPGS\n",
ALUA_DH_NAME);
break;
case TPGS_MODE_EXPLICIT:
sdev_printk(KERN_INFO, sdev, "%s: supports explicit TPGS\n",
ALUA_DH_NAME);
break;
case TPGS_MODE_IMPLICIT:
sdev_printk(KERN_INFO, sdev, "%s: supports implicit TPGS\n",
ALUA_DH_NAME);
break;
case TPGS_MODE_NONE:
sdev_printk(KERN_INFO, sdev, "%s: not supported\n",
ALUA_DH_NAME);
break;
default:
sdev_printk(KERN_INFO, sdev,
"%s: unsupported TPGS setting %d\n",
ALUA_DH_NAME, tpgs);
tpgs = TPGS_MODE_NONE;
break;
}
return tpgs;
}
static int alua_check_vpd(struct scsi_device *sdev, struct alua_dh_data *h,
int tpgs)
{
int rel_port = -1, group_id;
struct alua_port_group *pg, *old_pg = NULL;
bool pg_updated = false;
unsigned long flags;
group_id = scsi_vpd_tpg_id(sdev, &rel_port);
if (group_id < 0) {
sdev_printk(KERN_INFO, sdev,
"%s: No target port descriptors found\n",
ALUA_DH_NAME);
return SCSI_DH_DEV_UNSUPP;
}
pg = alua_alloc_pg(sdev, group_id, tpgs);
if (IS_ERR(pg)) {
if (PTR_ERR(pg) == -ENOMEM)
return SCSI_DH_NOMEM;
return SCSI_DH_DEV_UNSUPP;
}
if (pg->device_id_len)
sdev_printk(KERN_INFO, sdev,
"%s: device %s port group %x rel port %x\n",
ALUA_DH_NAME, pg->device_id_str,
group_id, rel_port);
else
sdev_printk(KERN_INFO, sdev,
"%s: port group %x rel port %x\n",
ALUA_DH_NAME, group_id, rel_port);
spin_lock(&h->pg_lock);
old_pg = rcu_dereference_protected(h->pg, lockdep_is_held(&h->pg_lock));
if (old_pg != pg) {
if (h->pg) {
spin_lock_irqsave(&old_pg->lock, flags);
list_del_rcu(&h->node);
spin_unlock_irqrestore(&old_pg->lock, flags);
}
rcu_assign_pointer(h->pg, pg);
pg_updated = true;
}
spin_lock_irqsave(&pg->lock, flags);
if (sdev->synchronous_alua)
pg->flags |= ALUA_SYNC_STPG;
if (pg_updated)
list_add_rcu(&h->node, &pg->dh_list);
spin_unlock_irqrestore(&pg->lock, flags);
alua_rtpg_queue(rcu_dereference_protected(h->pg,
lockdep_is_held(&h->pg_lock)),
sdev, NULL, true);
spin_unlock(&h->pg_lock);
if (old_pg)
kref_put(&old_pg->kref, release_port_group);
return SCSI_DH_OK;
}
static char print_alua_state(unsigned char state)
{
switch (state) {
case SCSI_ACCESS_STATE_OPTIMAL:
return 'A';
case SCSI_ACCESS_STATE_ACTIVE:
return 'N';
case SCSI_ACCESS_STATE_STANDBY:
return 'S';
case SCSI_ACCESS_STATE_UNAVAILABLE:
return 'U';
case SCSI_ACCESS_STATE_LBA:
return 'L';
case SCSI_ACCESS_STATE_OFFLINE:
return 'O';
case SCSI_ACCESS_STATE_TRANSITIONING:
return 'T';
default:
return 'X';
}
}
static int alua_check_sense(struct scsi_device *sdev,
struct scsi_sense_hdr *sense_hdr)
{
switch (sense_hdr->sense_key) {
case NOT_READY:
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x0a) {
alua_check(sdev, false);
return NEEDS_RETRY;
}
break;
case UNIT_ATTENTION:
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x00) {
alua_check(sdev, true);
return ADD_TO_MLQUEUE;
}
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x04)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x2a && sense_hdr->ascq == 0x01)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x2a && sense_hdr->ascq == 0x06) {
alua_check(sdev, true);
return ADD_TO_MLQUEUE;
}
if (sense_hdr->asc == 0x2a && sense_hdr->ascq == 0x07) {
alua_check(sdev, true);
return ADD_TO_MLQUEUE;
}
if (sense_hdr->asc == 0x3f && sense_hdr->ascq == 0x03)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x3f && sense_hdr->ascq == 0x0e)
return ADD_TO_MLQUEUE;
break;
}
return SCSI_RETURN_NOT_HANDLED;
}
static int alua_tur(struct scsi_device *sdev)
{
struct scsi_sense_hdr sense_hdr;
int retval;
retval = scsi_test_unit_ready(sdev, ALUA_FAILOVER_TIMEOUT * HZ,
ALUA_FAILOVER_RETRIES, &sense_hdr);
if (sense_hdr.sense_key == NOT_READY &&
sense_hdr.asc == 0x04 && sense_hdr.ascq == 0x0a)
return SCSI_DH_RETRY;
else if (retval)
return SCSI_DH_IO;
else
return SCSI_DH_OK;
}
static int alua_rtpg(struct scsi_device *sdev, struct alua_port_group *pg)
{
struct scsi_sense_hdr sense_hdr;
struct alua_port_group *tmp_pg;
int len, k, off, valid_states = 0, bufflen = ALUA_RTPG_SIZE;
unsigned char *desc, *buff;
unsigned err, retval;
unsigned int tpg_desc_tbl_off;
unsigned char orig_transition_tmo;
unsigned long flags;
if (!pg->expiry) {
unsigned long transition_tmo = ALUA_FAILOVER_TIMEOUT * HZ;
if (pg->transition_tmo)
transition_tmo = pg->transition_tmo * HZ;
pg->expiry = round_jiffies_up(jiffies + transition_tmo);
}
buff = kzalloc(bufflen, GFP_KERNEL);
if (!buff)
return SCSI_DH_DEV_TEMP_BUSY;
retry:
err = 0;
retval = submit_rtpg(sdev, buff, bufflen, &sense_hdr, pg->flags);
if (retval) {
if (!scsi_sense_valid(&sense_hdr)) {
sdev_printk(KERN_INFO, sdev,
"%s: rtpg failed, result %d\n",
ALUA_DH_NAME, retval);
kfree(buff);
if (driver_byte(retval) == DRIVER_ERROR)
return SCSI_DH_DEV_TEMP_BUSY;
return SCSI_DH_IO;
}
if (!(pg->flags & ALUA_RTPG_EXT_HDR_UNSUPP) &&
sense_hdr.sense_key == ILLEGAL_REQUEST &&
sense_hdr.asc == 0x24 && sense_hdr.ascq == 0) {
pg->flags |= ALUA_RTPG_EXT_HDR_UNSUPP;
goto retry;
}
if (sense_hdr.sense_key == NOT_READY &&
sense_hdr.asc == 0x04 && sense_hdr.ascq == 0x0a)
err = SCSI_DH_RETRY;
else if (sense_hdr.sense_key == UNIT_ATTENTION)
err = SCSI_DH_RETRY;
if (err == SCSI_DH_RETRY &&
pg->expiry != 0 && time_before(jiffies, pg->expiry)) {
sdev_printk(KERN_ERR, sdev, "%s: rtpg retry\n",
ALUA_DH_NAME);
scsi_print_sense_hdr(sdev, ALUA_DH_NAME, &sense_hdr);
kfree(buff);
return err;
}
sdev_printk(KERN_ERR, sdev, "%s: rtpg failed\n",
ALUA_DH_NAME);
scsi_print_sense_hdr(sdev, ALUA_DH_NAME, &sense_hdr);
kfree(buff);
pg->expiry = 0;
return SCSI_DH_IO;
}
len = get_unaligned_be32(&buff[0]) + 4;
if (len > bufflen) {
kfree(buff);
bufflen = len;
buff = kmalloc(bufflen, GFP_KERNEL);
if (!buff) {
sdev_printk(KERN_WARNING, sdev,
"%s: kmalloc buffer failed\n",__func__);
pg->expiry = 0;
return SCSI_DH_DEV_TEMP_BUSY;
}
goto retry;
}
orig_transition_tmo = pg->transition_tmo;
if ((buff[4] & RTPG_FMT_MASK) == RTPG_FMT_EXT_HDR && buff[5] != 0)
pg->transition_tmo = buff[5];
else
pg->transition_tmo = ALUA_FAILOVER_TIMEOUT;
if (orig_transition_tmo != pg->transition_tmo) {
sdev_printk(KERN_INFO, sdev,
"%s: transition timeout set to %d seconds\n",
ALUA_DH_NAME, pg->transition_tmo);
pg->expiry = jiffies + pg->transition_tmo * HZ;
}
if ((buff[4] & RTPG_FMT_MASK) == RTPG_FMT_EXT_HDR)
tpg_desc_tbl_off = 8;
else
tpg_desc_tbl_off = 4;
for (k = tpg_desc_tbl_off, desc = buff + tpg_desc_tbl_off;
k < len;
k += off, desc += off) {
u16 group_id = get_unaligned_be16(&desc[2]);
spin_lock_irqsave(&port_group_lock, flags);
tmp_pg = alua_find_get_pg(pg->device_id_str, pg->device_id_len,
group_id);
spin_unlock_irqrestore(&port_group_lock, flags);
if (tmp_pg) {
if (spin_trylock_irqsave(&tmp_pg->lock, flags)) {
if ((tmp_pg == pg) ||
!(tmp_pg->flags & ALUA_PG_RUNNING)) {
struct alua_dh_data *h;
tmp_pg->state = desc[0] & 0x0f;
tmp_pg->pref = desc[0] >> 7;
rcu_read_lock();
list_for_each_entry_rcu(h,
&tmp_pg->dh_list, node) {
BUG_ON(!h->sdev);
h->sdev->access_state = desc[0];
}
rcu_read_unlock();
}
if (tmp_pg == pg)
valid_states = desc[1];
spin_unlock_irqrestore(&tmp_pg->lock, flags);
}
kref_put(&tmp_pg->kref, release_port_group);
}
off = 8 + (desc[7] * 4);
}
spin_lock_irqsave(&pg->lock, flags);
sdev_printk(KERN_INFO, sdev,
"%s: port group %02x state %c %s supports %c%c%c%c%c%c%c\n",
ALUA_DH_NAME, pg->group_id, print_alua_state(pg->state),
pg->pref ? "preferred" : "non-preferred",
valid_states&TPGS_SUPPORT_TRANSITION?'T':'t',
valid_states&TPGS_SUPPORT_OFFLINE?'O':'o',
valid_states&TPGS_SUPPORT_LBA_DEPENDENT?'L':'l',
valid_states&TPGS_SUPPORT_UNAVAILABLE?'U':'u',
valid_states&TPGS_SUPPORT_STANDBY?'S':'s',
valid_states&TPGS_SUPPORT_NONOPTIMIZED?'N':'n',
valid_states&TPGS_SUPPORT_OPTIMIZED?'A':'a');
switch (pg->state) {
case SCSI_ACCESS_STATE_TRANSITIONING:
if (time_before(jiffies, pg->expiry)) {
pg->interval = 2;
err = SCSI_DH_RETRY;
} else {
struct alua_dh_data *h;
err = SCSI_DH_IO;
pg->state = SCSI_ACCESS_STATE_STANDBY;
pg->expiry = 0;
rcu_read_lock();
list_for_each_entry_rcu(h, &pg->dh_list, node) {
BUG_ON(!h->sdev);
h->sdev->access_state =
(pg->state & SCSI_ACCESS_STATE_MASK);
if (pg->pref)
h->sdev->access_state |=
SCSI_ACCESS_STATE_PREFERRED;
}
rcu_read_unlock();
}
break;
case SCSI_ACCESS_STATE_OFFLINE:
err = SCSI_DH_DEV_OFFLINED;
pg->expiry = 0;
break;
default:
err = SCSI_DH_OK;
pg->expiry = 0;
break;
}
spin_unlock_irqrestore(&pg->lock, flags);
kfree(buff);
return err;
}
static unsigned alua_stpg(struct scsi_device *sdev, struct alua_port_group *pg)
{
int retval;
struct scsi_sense_hdr sense_hdr;
if (!(pg->tpgs & TPGS_MODE_EXPLICIT)) {
return SCSI_DH_RETRY;
}
switch (pg->state) {
case SCSI_ACCESS_STATE_OPTIMAL:
return SCSI_DH_OK;
case SCSI_ACCESS_STATE_ACTIVE:
if ((pg->flags & ALUA_OPTIMIZE_STPG) &&
!pg->pref &&
(pg->tpgs & TPGS_MODE_IMPLICIT))
return SCSI_DH_OK;
break;
case SCSI_ACCESS_STATE_STANDBY:
case SCSI_ACCESS_STATE_UNAVAILABLE:
break;
case SCSI_ACCESS_STATE_OFFLINE:
return SCSI_DH_IO;
case SCSI_ACCESS_STATE_TRANSITIONING:
break;
default:
sdev_printk(KERN_INFO, sdev,
"%s: stpg failed, unhandled TPGS state %d",
ALUA_DH_NAME, pg->state);
return SCSI_DH_NOSYS;
}
retval = submit_stpg(sdev, pg->group_id, &sense_hdr);
if (retval) {
if (!scsi_sense_valid(&sense_hdr)) {
sdev_printk(KERN_INFO, sdev,
"%s: stpg failed, result %d",
ALUA_DH_NAME, retval);
if (driver_byte(retval) == DRIVER_ERROR)
return SCSI_DH_DEV_TEMP_BUSY;
} else {
sdev_printk(KERN_INFO, sdev, "%s: stpg failed\n",
ALUA_DH_NAME);
scsi_print_sense_hdr(sdev, ALUA_DH_NAME, &sense_hdr);
}
}
return SCSI_DH_RETRY;
}
static void alua_rtpg_work(struct work_struct *work)
{
struct alua_port_group *pg =
container_of(work, struct alua_port_group, rtpg_work.work);
struct scsi_device *sdev;
LIST_HEAD(qdata_list);
int err = SCSI_DH_OK;
struct alua_queue_data *qdata, *tmp;
unsigned long flags;
struct workqueue_struct *alua_wq = kaluad_wq;
spin_lock_irqsave(&pg->lock, flags);
sdev = pg->rtpg_sdev;
if (!sdev) {
WARN_ON(pg->flags & ALUA_PG_RUN_RTPG);
WARN_ON(pg->flags & ALUA_PG_RUN_STPG);
spin_unlock_irqrestore(&pg->lock, flags);
kref_put(&pg->kref, release_port_group);
return;
}
if (pg->flags & ALUA_SYNC_STPG)
alua_wq = kaluad_sync_wq;
pg->flags |= ALUA_PG_RUNNING;
if (pg->flags & ALUA_PG_RUN_RTPG) {
int state = pg->state;
pg->flags &= ~ALUA_PG_RUN_RTPG;
spin_unlock_irqrestore(&pg->lock, flags);
if (state == SCSI_ACCESS_STATE_TRANSITIONING) {
if (alua_tur(sdev) == SCSI_DH_RETRY) {
spin_lock_irqsave(&pg->lock, flags);
pg->flags &= ~ALUA_PG_RUNNING;
pg->flags |= ALUA_PG_RUN_RTPG;
spin_unlock_irqrestore(&pg->lock, flags);
queue_delayed_work(alua_wq, &pg->rtpg_work,
pg->interval * HZ);
return;
}
}
err = alua_rtpg(sdev, pg);
spin_lock_irqsave(&pg->lock, flags);
if (err == SCSI_DH_RETRY || pg->flags & ALUA_PG_RUN_RTPG) {
pg->flags &= ~ALUA_PG_RUNNING;
pg->flags |= ALUA_PG_RUN_RTPG;
spin_unlock_irqrestore(&pg->lock, flags);
queue_delayed_work(alua_wq, &pg->rtpg_work,
pg->interval * HZ);
return;
}
if (err != SCSI_DH_OK)
pg->flags &= ~ALUA_PG_RUN_STPG;
}
if (pg->flags & ALUA_PG_RUN_STPG) {
pg->flags &= ~ALUA_PG_RUN_STPG;
spin_unlock_irqrestore(&pg->lock, flags);
err = alua_stpg(sdev, pg);
spin_lock_irqsave(&pg->lock, flags);
if (err == SCSI_DH_RETRY || pg->flags & ALUA_PG_RUN_RTPG) {
pg->flags |= ALUA_PG_RUN_RTPG;
pg->interval = 0;
pg->flags &= ~ALUA_PG_RUNNING;
spin_unlock_irqrestore(&pg->lock, flags);
queue_delayed_work(alua_wq, &pg->rtpg_work,
pg->interval * HZ);
return;
}
}
list_splice_init(&pg->rtpg_list, &qdata_list);
pg->rtpg_sdev = NULL;
spin_unlock_irqrestore(&pg->lock, flags);
list_for_each_entry_safe(qdata, tmp, &qdata_list, entry) {
list_del(&qdata->entry);
if (qdata->callback_fn)
qdata->callback_fn(qdata->callback_data, err);
kfree(qdata);
}
spin_lock_irqsave(&pg->lock, flags);
pg->flags &= ~ALUA_PG_RUNNING;
spin_unlock_irqrestore(&pg->lock, flags);
scsi_device_put(sdev);
kref_put(&pg->kref, release_port_group);
}
static void alua_rtpg_queue(struct alua_port_group *pg,
struct scsi_device *sdev,
struct alua_queue_data *qdata, bool force)
{
int start_queue = 0;
unsigned long flags;
struct workqueue_struct *alua_wq = kaluad_wq;
if (!pg)
return;
spin_lock_irqsave(&pg->lock, flags);
if (qdata) {
list_add_tail(&qdata->entry, &pg->rtpg_list);
pg->flags |= ALUA_PG_RUN_STPG;
force = true;
}
if (pg->rtpg_sdev == NULL) {
pg->interval = 0;
pg->flags |= ALUA_PG_RUN_RTPG;
kref_get(&pg->kref);
pg->rtpg_sdev = sdev;
scsi_device_get(sdev);
start_queue = 1;
} else if (!(pg->flags & ALUA_PG_RUN_RTPG) && force) {
pg->flags |= ALUA_PG_RUN_RTPG;
if (!(pg->flags & ALUA_PG_RUNNING)) {
kref_get(&pg->kref);
sdev = NULL;
start_queue = 1;
}
}
if (pg->flags & ALUA_SYNC_STPG)
alua_wq = kaluad_sync_wq;
spin_unlock_irqrestore(&pg->lock, flags);
if (start_queue &&
!queue_delayed_work(alua_wq, &pg->rtpg_work,
msecs_to_jiffies(ALUA_RTPG_DELAY_MSECS))) {
if (sdev)
scsi_device_put(sdev);
kref_put(&pg->kref, release_port_group);
}
}
static int alua_initialize(struct scsi_device *sdev, struct alua_dh_data *h)
{
int err = SCSI_DH_DEV_UNSUPP, tpgs;
mutex_lock(&h->init_mutex);
tpgs = alua_check_tpgs(sdev);
if (tpgs != TPGS_MODE_NONE)
err = alua_check_vpd(sdev, h, tpgs);
h->init_error = err;
mutex_unlock(&h->init_mutex);
return err;
}
static int alua_set_params(struct scsi_device *sdev, const char *params)
{
struct alua_dh_data *h = sdev->handler_data;
struct alua_port_group *pg = NULL;
unsigned int optimize = 0, argc;
const char *p = params;
int result = SCSI_DH_OK;
unsigned long flags;
if ((sscanf(params, "%u", &argc) != 1) || (argc != 1))
return -EINVAL;
while (*p++)
;
if ((sscanf(p, "%u", &optimize) != 1) || (optimize > 1))
return -EINVAL;
rcu_read_lock();
pg = rcu_dereference(h->pg);
if (!pg) {
rcu_read_unlock();
return -ENXIO;
}
spin_lock_irqsave(&pg->lock, flags);
if (optimize)
pg->flags |= ALUA_OPTIMIZE_STPG;
else
pg->flags &= ~ALUA_OPTIMIZE_STPG;
spin_unlock_irqrestore(&pg->lock, flags);
rcu_read_unlock();
return result;
}
static int alua_activate(struct scsi_device *sdev,
activate_complete fn, void *data)
{
struct alua_dh_data *h = sdev->handler_data;
int err = SCSI_DH_OK;
struct alua_queue_data *qdata;
struct alua_port_group *pg;
qdata = kzalloc(sizeof(*qdata), GFP_KERNEL);
if (!qdata) {
err = SCSI_DH_RES_TEMP_UNAVAIL;
goto out;
}
qdata->callback_fn = fn;
qdata->callback_data = data;
mutex_lock(&h->init_mutex);
rcu_read_lock();
pg = rcu_dereference(h->pg);
if (!pg || !kref_get_unless_zero(&pg->kref)) {
rcu_read_unlock();
kfree(qdata);
err = h->init_error;
mutex_unlock(&h->init_mutex);
goto out;
}
fn = NULL;
rcu_read_unlock();
mutex_unlock(&h->init_mutex);
alua_rtpg_queue(pg, sdev, qdata, true);
kref_put(&pg->kref, release_port_group);
out:
if (fn)
fn(data, err);
return 0;
}
static void alua_check(struct scsi_device *sdev, bool force)
{
struct alua_dh_data *h = sdev->handler_data;
struct alua_port_group *pg;
rcu_read_lock();
pg = rcu_dereference(h->pg);
if (!pg || !kref_get_unless_zero(&pg->kref)) {
rcu_read_unlock();
return;
}
rcu_read_unlock();
alua_rtpg_queue(pg, sdev, NULL, force);
kref_put(&pg->kref, release_port_group);
}
static int alua_prep_fn(struct scsi_device *sdev, struct request *req)
{
struct alua_dh_data *h = sdev->handler_data;
struct alua_port_group *pg;
unsigned char state = SCSI_ACCESS_STATE_OPTIMAL;
int ret = BLKPREP_OK;
rcu_read_lock();
pg = rcu_dereference(h->pg);
if (pg)
state = pg->state;
rcu_read_unlock();
if (state == SCSI_ACCESS_STATE_TRANSITIONING)
ret = BLKPREP_DEFER;
else if (state != SCSI_ACCESS_STATE_OPTIMAL &&
state != SCSI_ACCESS_STATE_ACTIVE &&
state != SCSI_ACCESS_STATE_LBA) {
ret = BLKPREP_KILL;
req->rq_flags |= RQF_QUIET;
}
return ret;
}
static void alua_rescan(struct scsi_device *sdev)
{
struct alua_dh_data *h = sdev->handler_data;
alua_initialize(sdev, h);
}
static int alua_bus_attach(struct scsi_device *sdev)
{
struct alua_dh_data *h;
int err, ret = -EINVAL;
h = kzalloc(sizeof(*h) , GFP_KERNEL);
if (!h)
return -ENOMEM;
spin_lock_init(&h->pg_lock);
rcu_assign_pointer(h->pg, NULL);
h->init_error = SCSI_DH_OK;
h->sdev = sdev;
INIT_LIST_HEAD(&h->node);
mutex_init(&h->init_mutex);
err = alua_initialize(sdev, h);
if (err == SCSI_DH_NOMEM)
ret = -ENOMEM;
if (err != SCSI_DH_OK && err != SCSI_DH_DEV_OFFLINED)
goto failed;
sdev->handler_data = h;
return 0;
failed:
kfree(h);
return ret;
}
static void alua_bus_detach(struct scsi_device *sdev)
{
struct alua_dh_data *h = sdev->handler_data;
struct alua_port_group *pg;
spin_lock(&h->pg_lock);
pg = rcu_dereference_protected(h->pg, lockdep_is_held(&h->pg_lock));
rcu_assign_pointer(h->pg, NULL);
h->sdev = NULL;
spin_unlock(&h->pg_lock);
if (pg) {
spin_lock_irq(&pg->lock);
list_del_rcu(&h->node);
spin_unlock_irq(&pg->lock);
kref_put(&pg->kref, release_port_group);
}
sdev->handler_data = NULL;
kfree(h);
}
static int __init alua_init(void)
{
int r;
kaluad_wq = alloc_workqueue("kaluad", WQ_MEM_RECLAIM, 0);
if (!kaluad_wq) {
return SCSI_DH_DEV_TEMP_BUSY;
}
kaluad_sync_wq = create_workqueue("kaluad_sync");
if (!kaluad_sync_wq) {
destroy_workqueue(kaluad_wq);
return SCSI_DH_DEV_TEMP_BUSY;
}
r = scsi_register_device_handler(&alua_dh);
if (r != 0) {
printk(KERN_ERR "%s: Failed to register scsi device handler",
ALUA_DH_NAME);
destroy_workqueue(kaluad_sync_wq);
destroy_workqueue(kaluad_wq);
}
return r;
}
static void __exit alua_exit(void)
{
scsi_unregister_device_handler(&alua_dh);
destroy_workqueue(kaluad_sync_wq);
destroy_workqueue(kaluad_wq);
}
