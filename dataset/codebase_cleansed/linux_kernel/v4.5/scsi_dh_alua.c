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
if (IS_ERR(rq)) {
sdev_printk(KERN_INFO, sdev,
"%s: blk_get_request failed\n", __func__);
return NULL;
}
blk_rq_set_block_pc(rq);
if (buflen && blk_rq_map_kern(q, rq, buffer, buflen, GFP_NOIO)) {
blk_put_request(rq);
sdev_printk(KERN_INFO, sdev,
"%s: blk_rq_map_kern failed\n", __func__);
return NULL;
}
rq->cmd_flags |= REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
rq->retries = ALUA_FAILOVER_RETRIES;
rq->timeout = ALUA_FAILOVER_TIMEOUT * HZ;
return rq;
}
static unsigned submit_rtpg(struct scsi_device *sdev, struct alua_dh_data *h)
{
struct request *rq;
int err = 0;
rq = get_alua_req(sdev, h->buff, h->bufflen, READ);
if (!rq) {
err = DRIVER_BUSY << 24;
goto done;
}
rq->cmd[0] = MAINTENANCE_IN;
if (!(h->flags & ALUA_RTPG_EXT_HDR_UNSUPP))
rq->cmd[1] = MI_REPORT_TARGET_PGS | MI_EXT_HDR_PARAM_FMT;
else
rq->cmd[1] = MI_REPORT_TARGET_PGS;
put_unaligned_be32(h->bufflen, &rq->cmd[6]);
rq->cmd_len = COMMAND_SIZE(MAINTENANCE_IN);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = 0;
blk_execute_rq(rq->q, NULL, rq, 1);
if (rq->errors)
err = rq->errors;
blk_put_request(rq);
done:
return err;
}
static void stpg_endio(struct request *req, int error)
{
struct alua_dh_data *h = req->end_io_data;
struct scsi_sense_hdr sense_hdr;
unsigned err = SCSI_DH_OK;
if (host_byte(req->errors) != DID_OK ||
msg_byte(req->errors) != COMMAND_COMPLETE) {
err = SCSI_DH_IO;
goto done;
}
if (scsi_normalize_sense(h->sense, SCSI_SENSE_BUFFERSIZE,
&sense_hdr)) {
if (sense_hdr.sense_key == NOT_READY &&
sense_hdr.asc == 0x04 && sense_hdr.ascq == 0x0a) {
err = SCSI_DH_OK;
goto done;
}
if (sense_hdr.sense_key == UNIT_ATTENTION) {
err = SCSI_DH_RETRY;
goto done;
}
sdev_printk(KERN_INFO, h->sdev, "%s: stpg failed\n",
ALUA_DH_NAME);
scsi_print_sense_hdr(h->sdev, ALUA_DH_NAME, &sense_hdr);
err = SCSI_DH_IO;
} else if (error)
err = SCSI_DH_IO;
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
put_unaligned_be16(h->group_id, &h->buff[6]);
rq = get_alua_req(sdev, h->buff, stpg_len, WRITE);
if (!rq)
return SCSI_DH_RES_TEMP_UNAVAIL;
rq->cmd[0] = MAINTENANCE_OUT;
rq->cmd[1] = MO_SET_TARGET_PGS;
put_unaligned_be32(stpg_len, &rq->cmd[6]);
rq->cmd_len = COMMAND_SIZE(MAINTENANCE_OUT);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = 0;
rq->end_io_data = h;
blk_execute_rq_nowait(rq->q, NULL, rq, 1, stpg_endio);
return SCSI_DH_OK;
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
static int alua_check_vpd(struct scsi_device *sdev, struct alua_dh_data *h)
{
int rel_port = -1, group_id;
group_id = scsi_vpd_tpg_id(sdev, &rel_port);
if (group_id < 0) {
sdev_printk(KERN_INFO, sdev,
"%s: No target port descriptors found\n",
ALUA_DH_NAME);
return SCSI_DH_DEV_UNSUPP;
}
h->state = TPGS_STATE_OPTIMIZED;
h->group_id = group_id;
sdev_printk(KERN_INFO, sdev,
"%s: port group %02x rel port %02x\n",
ALUA_DH_NAME, h->group_id, h->rel_port);
return 0;
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
break;
case UNIT_ATTENTION:
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x00)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x04)
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
static int alua_rtpg(struct scsi_device *sdev, struct alua_dh_data *h, int wait_for_transition)
{
struct scsi_sense_hdr sense_hdr;
int len, k, off, valid_states = 0;
unsigned char *ucp;
unsigned err, retval;
unsigned long expiry, interval = 0;
unsigned int tpg_desc_tbl_off;
unsigned char orig_transition_tmo;
if (!h->transition_tmo)
expiry = round_jiffies_up(jiffies + ALUA_FAILOVER_TIMEOUT * HZ);
else
expiry = round_jiffies_up(jiffies + h->transition_tmo * HZ);
retry:
retval = submit_rtpg(sdev, h);
if (retval) {
if (!scsi_normalize_sense(h->sense, SCSI_SENSE_BUFFERSIZE,
&sense_hdr)) {
sdev_printk(KERN_INFO, sdev,
"%s: rtpg failed, result %d\n",
ALUA_DH_NAME, retval);
if (driver_byte(retval) == DRIVER_BUSY)
return SCSI_DH_DEV_TEMP_BUSY;
return SCSI_DH_IO;
}
if (!(h->flags & ALUA_RTPG_EXT_HDR_UNSUPP) &&
sense_hdr.sense_key == ILLEGAL_REQUEST &&
sense_hdr.asc == 0x24 && sense_hdr.ascq == 0) {
h->flags |= ALUA_RTPG_EXT_HDR_UNSUPP;
goto retry;
}
if (sense_hdr.sense_key == NOT_READY &&
sense_hdr.asc == 0x04 && sense_hdr.ascq == 0x0a)
err = SCSI_DH_RETRY;
else if (sense_hdr.sense_key == UNIT_ATTENTION)
err = SCSI_DH_RETRY;
if (err == SCSI_DH_RETRY && time_before(jiffies, expiry)) {
sdev_printk(KERN_ERR, sdev, "%s: rtpg retry\n",
ALUA_DH_NAME);
scsi_print_sense_hdr(sdev, ALUA_DH_NAME, &sense_hdr);
goto retry;
}
sdev_printk(KERN_ERR, sdev, "%s: rtpg failed\n",
ALUA_DH_NAME);
scsi_print_sense_hdr(sdev, ALUA_DH_NAME, &sense_hdr);
return SCSI_DH_IO;
}
len = get_unaligned_be32(&h->buff[0]) + 4;
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
if (wait_for_transition && (orig_transition_tmo != h->transition_tmo)) {
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
if (h->group_id == get_unaligned_be16(&ucp[2])) {
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
if (wait_for_transition) {
if (time_before(jiffies, expiry)) {
interval += 2000;
msleep(interval);
goto retry;
}
err = SCSI_DH_RETRY;
} else {
err = SCSI_DH_OK;
}
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
int err = SCSI_DH_DEV_UNSUPP;
h->tpgs = alua_check_tpgs(sdev);
if (h->tpgs == TPGS_MODE_NONE)
goto out;
err = alua_check_vpd(sdev, h);
if (err != SCSI_DH_OK)
goto out;
err = alua_rtpg(sdev, h, 0);
if (err != SCSI_DH_OK)
goto out;
out:
return err;
}
static int alua_set_params(struct scsi_device *sdev, const char *params)
{
struct alua_dh_data *h = sdev->handler_data;
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
struct alua_dh_data *h = sdev->handler_data;
int err = SCSI_DH_OK;
int stpg = 0;
err = alua_rtpg(sdev, h, 1);
if (err != SCSI_DH_OK)
goto out;
if (optimize_stpg)
h->flags |= ALUA_OPTIMIZE_STPG;
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
struct alua_dh_data *h = sdev->handler_data;
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
static int alua_bus_attach(struct scsi_device *sdev)
{
struct alua_dh_data *h;
int err;
h = kzalloc(sizeof(*h) , GFP_KERNEL);
if (!h)
return -ENOMEM;
h->tpgs = TPGS_MODE_UNINITIALIZED;
h->state = TPGS_STATE_OPTIMIZED;
h->group_id = -1;
h->rel_port = -1;
h->buff = h->inq;
h->bufflen = ALUA_INQUIRY_SIZE;
h->sdev = sdev;
err = alua_initialize(sdev, h);
if (err != SCSI_DH_OK && err != SCSI_DH_DEV_OFFLINED)
goto failed;
sdev->handler_data = h;
return 0;
failed:
kfree(h);
return -EINVAL;
}
static void alua_bus_detach(struct scsi_device *sdev)
{
struct alua_dh_data *h = sdev->handler_data;
if (h->buff && h->inq != h->buff)
kfree(h->buff);
sdev->handler_data = NULL;
kfree(h);
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
