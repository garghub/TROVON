static inline struct alua_dh_data *get_alua_data(struct scsi_device *sdev)
{
struct scsi_dh_data *scsi_dh_data = sdev->scsi_dh_data;
BUG_ON(scsi_dh_data == NULL);
return ((struct alua_dh_data *) scsi_dh_data->buf);
}
static int realloc_buffer(struct alua_dh_data *h, unsigned len)
{
if (h->buff && h->buff != h->inq)
kfree(h->buff);
h->buff = kmalloc(len, GFP_NOIO);
if (!h->buff) {
h->buff = h->inq;
h->bufflen = ALUA_INQUIRY_SIZE;
return 1;
}
h->bufflen = len;
return 0;
}
static struct request *get_alua_req(struct scsi_device *sdev,
void *buffer, unsigned buflen, int rw)
{
struct request *rq;
struct request_queue *q = sdev->request_queue;
rq = blk_get_request(q, rw, GFP_NOIO);
if (!rq) {
sdev_printk(KERN_INFO, sdev,
"%s: blk_get_request failed\n", __func__);
return NULL;
}
if (buflen && blk_rq_map_kern(q, rq, buffer, buflen, GFP_NOIO)) {
blk_put_request(rq);
sdev_printk(KERN_INFO, sdev,
"%s: blk_rq_map_kern failed\n", __func__);
return NULL;
}
rq->cmd_type = REQ_TYPE_BLOCK_PC;
rq->cmd_flags |= REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
rq->retries = ALUA_FAILOVER_RETRIES;
rq->timeout = ALUA_FAILOVER_TIMEOUT * HZ;
return rq;
}
static int submit_vpd_inquiry(struct scsi_device *sdev, struct alua_dh_data *h)
{
struct request *rq;
int err = SCSI_DH_RES_TEMP_UNAVAIL;
rq = get_alua_req(sdev, h->buff, h->bufflen, READ);
if (!rq)
goto done;
rq->cmd[0] = INQUIRY;
rq->cmd[1] = 1;
rq->cmd[2] = 0x83;
rq->cmd[4] = h->bufflen;
rq->cmd_len = COMMAND_SIZE(INQUIRY);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = h->senselen = 0;
err = blk_execute_rq(rq->q, NULL, rq, 1);
if (err == -EIO) {
sdev_printk(KERN_INFO, sdev,
"%s: evpd inquiry failed with %x\n",
ALUA_DH_NAME, rq->errors);
h->senselen = rq->sense_len;
err = SCSI_DH_IO;
}
blk_put_request(rq);
done:
return err;
}
static unsigned submit_rtpg(struct scsi_device *sdev, struct alua_dh_data *h,
bool rtpg_ext_hdr_req)
{
struct request *rq;
int err = SCSI_DH_RES_TEMP_UNAVAIL;
rq = get_alua_req(sdev, h->buff, h->bufflen, READ);
if (!rq)
goto done;
rq->cmd[0] = MAINTENANCE_IN;
if (rtpg_ext_hdr_req)
rq->cmd[1] = MI_REPORT_TARGET_PGS | MI_EXT_HDR_PARAM_FMT;
else
rq->cmd[1] = MI_REPORT_TARGET_PGS;
rq->cmd[6] = (h->bufflen >> 24) & 0xff;
rq->cmd[7] = (h->bufflen >> 16) & 0xff;
rq->cmd[8] = (h->bufflen >> 8) & 0xff;
rq->cmd[9] = h->bufflen & 0xff;
rq->cmd_len = COMMAND_SIZE(MAINTENANCE_IN);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = h->senselen = 0;
err = blk_execute_rq(rq->q, NULL, rq, 1);
if (err == -EIO) {
sdev_printk(KERN_INFO, sdev,
"%s: rtpg failed with %x\n",
ALUA_DH_NAME, rq->errors);
h->senselen = rq->sense_len;
err = SCSI_DH_IO;
}
blk_put_request(rq);
done:
return err;
}
static void stpg_endio(struct request *req, int error)
{
struct alua_dh_data *h = req->end_io_data;
struct scsi_sense_hdr sense_hdr;
unsigned err = SCSI_DH_OK;
if (error || host_byte(req->errors) != DID_OK ||
msg_byte(req->errors) != COMMAND_COMPLETE) {
err = SCSI_DH_IO;
goto done;
}
if (h->senselen > 0) {
err = scsi_normalize_sense(h->sense, SCSI_SENSE_BUFFERSIZE,
&sense_hdr);
if (!err) {
err = SCSI_DH_IO;
goto done;
}
err = alua_check_sense(h->sdev, &sense_hdr);
if (err == ADD_TO_MLQUEUE) {
err = SCSI_DH_RETRY;
goto done;
}
sdev_printk(KERN_INFO, h->sdev,
"%s: stpg sense code: %02x/%02x/%02x\n",
ALUA_DH_NAME, sense_hdr.sense_key,
sense_hdr.asc, sense_hdr.ascq);
err = SCSI_DH_IO;
}
if (err == SCSI_DH_OK) {
h->state = TPGS_STATE_OPTIMIZED;
sdev_printk(KERN_INFO, h->sdev,
"%s: port group %02x switched to state %c\n",
ALUA_DH_NAME, h->group_id,
print_alua_state(h->state));
}
done:
req->end_io_data = NULL;
__blk_put_request(req->q, req);
if (h->callback_fn) {
h->callback_fn(h->callback_data, err);
h->callback_fn = h->callback_data = NULL;
}
return;
}
static unsigned submit_stpg(struct alua_dh_data *h)
{
struct request *rq;
int stpg_len = 8;
struct scsi_device *sdev = h->sdev;
memset(h->buff, 0, stpg_len);
h->buff[4] = TPGS_STATE_OPTIMIZED & 0x0f;
h->buff[6] = (h->group_id >> 8) & 0xff;
h->buff[7] = h->group_id & 0xff;
rq = get_alua_req(sdev, h->buff, stpg_len, WRITE);
if (!rq)
return SCSI_DH_RES_TEMP_UNAVAIL;
rq->cmd[0] = MAINTENANCE_OUT;
rq->cmd[1] = MO_SET_TARGET_PGS;
rq->cmd[6] = (stpg_len >> 24) & 0xff;
rq->cmd[7] = (stpg_len >> 16) & 0xff;
rq->cmd[8] = (stpg_len >> 8) & 0xff;
rq->cmd[9] = stpg_len & 0xff;
rq->cmd_len = COMMAND_SIZE(MAINTENANCE_OUT);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = h->senselen = 0;
rq->end_io_data = h;
blk_execute_rq_nowait(rq->q, NULL, rq, 1, stpg_endio);
return SCSI_DH_OK;
}
static int alua_check_tpgs(struct scsi_device *sdev, struct alua_dh_data *h)
{
int err = SCSI_DH_OK;
h->tpgs = scsi_device_tpgs(sdev);
switch (h->tpgs) {
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
default:
h->tpgs = TPGS_MODE_NONE;
sdev_printk(KERN_INFO, sdev, "%s: not supported\n",
ALUA_DH_NAME);
err = SCSI_DH_DEV_UNSUPP;
break;
}
return err;
}
static int alua_vpd_inquiry(struct scsi_device *sdev, struct alua_dh_data *h)
{
int len;
unsigned err;
unsigned char *d;
retry:
err = submit_vpd_inquiry(sdev, h);
if (err != SCSI_DH_OK)
return err;
len = (h->buff[2] << 8) + h->buff[3] + 4;
if (len > h->bufflen) {
if (realloc_buffer(h, len)) {
sdev_printk(KERN_WARNING, sdev,
"%s: kmalloc buffer failed\n",
ALUA_DH_NAME);
return SCSI_DH_DEV_TEMP_BUSY;
}
goto retry;
}
d = h->buff + 4;
while (d < h->buff + len) {
switch (d[1] & 0xf) {
case 0x4:
h->rel_port = (d[6] << 8) + d[7];
break;
case 0x5:
h->group_id = (d[6] << 8) + d[7];
break;
default:
break;
}
d += d[3] + 4;
}
if (h->group_id == -1) {
sdev_printk(KERN_INFO, sdev,
"%s: No target port descriptors found\n",
ALUA_DH_NAME);
h->state = TPGS_STATE_OPTIMIZED;
h->tpgs = TPGS_MODE_NONE;
err = SCSI_DH_DEV_UNSUPP;
} else {
sdev_printk(KERN_INFO, sdev,
"%s: port group %02x rel port %02x\n",
ALUA_DH_NAME, h->group_id, h->rel_port);
}
return err;
}
static char print_alua_state(int state)
{
switch (state) {
case TPGS_STATE_OPTIMIZED:
return 'A';
case TPGS_STATE_NONOPTIMIZED:
return 'N';
case TPGS_STATE_STANDBY:
return 'S';
case TPGS_STATE_UNAVAILABLE:
return 'U';
case TPGS_STATE_LBA_DEPENDENT:
return 'L';
case TPGS_STATE_OFFLINE:
return 'O';
case TPGS_STATE_TRANSITIONING:
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
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x0a)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x0b)
return SUCCESS;
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x0c)
return SUCCESS;
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x12)
return SUCCESS;
break;
case UNIT_ATTENTION:
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x00)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x2a && sense_hdr->ascq == 0x01)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x2a && sense_hdr->ascq == 0x06)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x2a && sense_hdr->ascq == 0x07)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x3f && sense_hdr->ascq == 0x03)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x3f && sense_hdr->ascq == 0x0e)
return ADD_TO_MLQUEUE;
break;
}
return SCSI_RETURN_NOT_HANDLED;
}
static int alua_rtpg(struct scsi_device *sdev, struct alua_dh_data *h)
{
struct scsi_sense_hdr sense_hdr;
int len, k, off, valid_states = 0;
unsigned char *ucp;
unsigned err;
bool rtpg_ext_hdr_req = 1;
unsigned long expiry, interval = 0;
unsigned int tpg_desc_tbl_off;
unsigned char orig_transition_tmo;
if (!h->transition_tmo)
expiry = round_jiffies_up(jiffies + ALUA_FAILOVER_TIMEOUT * HZ);
else
expiry = round_jiffies_up(jiffies + h->transition_tmo * HZ);
retry:
err = submit_rtpg(sdev, h, rtpg_ext_hdr_req);
if (err == SCSI_DH_IO && h->senselen > 0) {
err = scsi_normalize_sense(h->sense, SCSI_SENSE_BUFFERSIZE,
&sense_hdr);
if (!err)
return SCSI_DH_IO;
if (rtpg_ext_hdr_req == 1 &&
sense_hdr.sense_key == ILLEGAL_REQUEST &&
sense_hdr.asc == 0x24 && sense_hdr.ascq == 0) {
rtpg_ext_hdr_req = 0;
goto retry;
}
err = alua_check_sense(sdev, &sense_hdr);
if (err == ADD_TO_MLQUEUE && time_before(jiffies, expiry))
goto retry;
sdev_printk(KERN_INFO, sdev,
"%s: rtpg sense code %02x/%02x/%02x\n",
ALUA_DH_NAME, sense_hdr.sense_key,
sense_hdr.asc, sense_hdr.ascq);
err = SCSI_DH_IO;
}
if (err != SCSI_DH_OK)
return err;
len = (h->buff[0] << 24) + (h->buff[1] << 16) +
(h->buff[2] << 8) + h->buff[3] + 4;
if (len > h->bufflen) {
if (realloc_buffer(h, len)) {
sdev_printk(KERN_WARNING, sdev,
"%s: kmalloc buffer failed\n",__func__);
return SCSI_DH_DEV_TEMP_BUSY;
}
goto retry;
}
orig_transition_tmo = h->transition_tmo;
if ((h->buff[4] & RTPG_FMT_MASK) == RTPG_FMT_EXT_HDR && h->buff[5] != 0)
h->transition_tmo = h->buff[5];
else
h->transition_tmo = ALUA_FAILOVER_TIMEOUT;
if (orig_transition_tmo != h->transition_tmo) {
sdev_printk(KERN_INFO, sdev,
"%s: transition timeout set to %d seconds\n",
ALUA_DH_NAME, h->transition_tmo);
expiry = jiffies + h->transition_tmo * HZ;
}
if ((h->buff[4] & RTPG_FMT_MASK) == RTPG_FMT_EXT_HDR)
tpg_desc_tbl_off = 8;
else
tpg_desc_tbl_off = 4;
for (k = tpg_desc_tbl_off, ucp = h->buff + tpg_desc_tbl_off;
k < len;
k += off, ucp += off) {
if (h->group_id == (ucp[2] << 8) + ucp[3]) {
h->state = ucp[0] & 0x0f;
h->pref = ucp[0] >> 7;
valid_states = ucp[1];
}
off = 8 + (ucp[7] * 4);
}
sdev_printk(KERN_INFO, sdev,
"%s: port group %02x state %c %s supports %c%c%c%c%c%c%c\n",
ALUA_DH_NAME, h->group_id, print_alua_state(h->state),
h->pref ? "preferred" : "non-preferred",
valid_states&TPGS_SUPPORT_TRANSITION?'T':'t',
valid_states&TPGS_SUPPORT_OFFLINE?'O':'o',
valid_states&TPGS_SUPPORT_LBA_DEPENDENT?'L':'l',
valid_states&TPGS_SUPPORT_UNAVAILABLE?'U':'u',
valid_states&TPGS_SUPPORT_STANDBY?'S':'s',
valid_states&TPGS_SUPPORT_NONOPTIMIZED?'N':'n',
valid_states&TPGS_SUPPORT_OPTIMIZED?'A':'a');
switch (h->state) {
case TPGS_STATE_TRANSITIONING:
if (time_before(jiffies, expiry)) {
interval += 2000;
msleep(interval);
goto retry;
}
err = SCSI_DH_RETRY;
h->state = TPGS_STATE_STANDBY;
break;
case TPGS_STATE_OFFLINE:
err = SCSI_DH_DEV_OFFLINED;
break;
default:
err = SCSI_DH_OK;
break;
}
return err;
}
static int alua_initialize(struct scsi_device *sdev, struct alua_dh_data *h)
{
int err;
err = alua_check_tpgs(sdev, h);
if (err != SCSI_DH_OK)
goto out;
err = alua_vpd_inquiry(sdev, h);
if (err != SCSI_DH_OK)
goto out;
err = alua_rtpg(sdev, h);
if (err != SCSI_DH_OK)
goto out;
out:
return err;
}
static int alua_set_params(struct scsi_device *sdev, const char *params)
{
struct alua_dh_data *h = get_alua_data(sdev);
unsigned int optimize = 0, argc;
const char *p = params;
int result = SCSI_DH_OK;
if ((sscanf(params, "%u", &argc) != 1) || (argc != 1))
return -EINVAL;
while (*p++)
;
if ((sscanf(p, "%u", &optimize) != 1) || (optimize > 1))
return -EINVAL;
if (optimize)
h->flags |= ALUA_OPTIMIZE_STPG;
else
h->flags &= ~ALUA_OPTIMIZE_STPG;
return result;
}
static int alua_activate(struct scsi_device *sdev,
activate_complete fn, void *data)
{
struct alua_dh_data *h = get_alua_data(sdev);
int err = SCSI_DH_OK;
int stpg = 0;
err = alua_rtpg(sdev, h);
if (err != SCSI_DH_OK)
goto out;
if (h->tpgs & TPGS_MODE_EXPLICIT) {
switch (h->state) {
case TPGS_STATE_NONOPTIMIZED:
stpg = 1;
if ((h->flags & ALUA_OPTIMIZE_STPG) &&
(!h->pref) &&
(h->tpgs & TPGS_MODE_IMPLICIT))
stpg = 0;
break;
case TPGS_STATE_STANDBY:
case TPGS_STATE_UNAVAILABLE:
stpg = 1;
break;
case TPGS_STATE_OFFLINE:
err = SCSI_DH_IO;
break;
case TPGS_STATE_TRANSITIONING:
err = SCSI_DH_RETRY;
break;
default:
break;
}
}
if (stpg) {
h->callback_fn = fn;
h->callback_data = data;
err = submit_stpg(h);
if (err == SCSI_DH_OK)
return 0;
h->callback_fn = h->callback_data = NULL;
}
out:
if (fn)
fn(data, err);
return 0;
}
static int alua_prep_fn(struct scsi_device *sdev, struct request *req)
{
struct alua_dh_data *h = get_alua_data(sdev);
int ret = BLKPREP_OK;
if (h->state == TPGS_STATE_TRANSITIONING)
ret = BLKPREP_DEFER;
else if (h->state != TPGS_STATE_OPTIMIZED &&
h->state != TPGS_STATE_NONOPTIMIZED &&
h->state != TPGS_STATE_LBA_DEPENDENT) {
ret = BLKPREP_KILL;
req->cmd_flags |= REQ_QUIET;
}
return ret;
}
static bool alua_match(struct scsi_device *sdev)
{
return (scsi_device_tpgs(sdev) != 0);
}
static int alua_bus_attach(struct scsi_device *sdev)
{
struct scsi_dh_data *scsi_dh_data;
struct alua_dh_data *h;
unsigned long flags;
int err = SCSI_DH_OK;
scsi_dh_data = kzalloc(sizeof(*scsi_dh_data)
+ sizeof(*h) , GFP_KERNEL);
if (!scsi_dh_data) {
sdev_printk(KERN_ERR, sdev, "%s: Attach failed\n",
ALUA_DH_NAME);
return -ENOMEM;
}
scsi_dh_data->scsi_dh = &alua_dh;
h = (struct alua_dh_data *) scsi_dh_data->buf;
h->tpgs = TPGS_MODE_UNINITIALIZED;
h->state = TPGS_STATE_OPTIMIZED;
h->group_id = -1;
h->rel_port = -1;
h->buff = h->inq;
h->bufflen = ALUA_INQUIRY_SIZE;
h->sdev = sdev;
err = alua_initialize(sdev, h);
if ((err != SCSI_DH_OK) && (err != SCSI_DH_DEV_OFFLINED))
goto failed;
if (!try_module_get(THIS_MODULE))
goto failed;
spin_lock_irqsave(sdev->request_queue->queue_lock, flags);
sdev->scsi_dh_data = scsi_dh_data;
spin_unlock_irqrestore(sdev->request_queue->queue_lock, flags);
sdev_printk(KERN_NOTICE, sdev, "%s: Attached\n", ALUA_DH_NAME);
return 0;
failed:
kfree(scsi_dh_data);
sdev_printk(KERN_ERR, sdev, "%s: not attached\n", ALUA_DH_NAME);
return -EINVAL;
}
static void alua_bus_detach(struct scsi_device *sdev)
{
struct scsi_dh_data *scsi_dh_data;
struct alua_dh_data *h;
unsigned long flags;
spin_lock_irqsave(sdev->request_queue->queue_lock, flags);
scsi_dh_data = sdev->scsi_dh_data;
sdev->scsi_dh_data = NULL;
spin_unlock_irqrestore(sdev->request_queue->queue_lock, flags);
h = (struct alua_dh_data *) scsi_dh_data->buf;
if (h->buff && h->inq != h->buff)
kfree(h->buff);
kfree(scsi_dh_data);
module_put(THIS_MODULE);
sdev_printk(KERN_NOTICE, sdev, "%s: Detached\n", ALUA_DH_NAME);
}
static int __init alua_init(void)
{
int r;
r = scsi_register_device_handler(&alua_dh);
if (r != 0)
printk(KERN_ERR "%s: Failed to register scsi device handler",
ALUA_DH_NAME);
return r;
}
static void __exit alua_exit(void)
{
scsi_unregister_device_handler(&alua_dh);
}
