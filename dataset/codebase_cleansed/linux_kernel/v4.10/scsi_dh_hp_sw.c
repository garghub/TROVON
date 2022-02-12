static int tur_done(struct scsi_device *sdev, unsigned char *sense)
{
struct scsi_sense_hdr sshdr;
int ret;
ret = scsi_normalize_sense(sense, SCSI_SENSE_BUFFERSIZE, &sshdr);
if (!ret) {
sdev_printk(KERN_WARNING, sdev,
"%s: sending tur failed, no sense available\n",
HP_SW_NAME);
ret = SCSI_DH_IO;
goto done;
}
switch (sshdr.sense_key) {
case UNIT_ATTENTION:
ret = SCSI_DH_IMM_RETRY;
break;
case NOT_READY:
if ((sshdr.asc == 0x04) && (sshdr.ascq == 2)) {
ret = SCSI_DH_DEV_OFFLINED;
break;
}
default:
sdev_printk(KERN_WARNING, sdev,
"%s: sending tur failed, sense %x/%x/%x\n",
HP_SW_NAME, sshdr.sense_key, sshdr.asc,
sshdr.ascq);
break;
}
done:
return ret;
}
static int hp_sw_tur(struct scsi_device *sdev, struct hp_sw_dh_data *h)
{
struct request *req;
int ret;
retry:
req = blk_get_request(sdev->request_queue, WRITE, GFP_NOIO);
if (IS_ERR(req))
return SCSI_DH_RES_TEMP_UNAVAIL;
blk_rq_set_block_pc(req);
req->cmd_flags |= REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
req->cmd_len = COMMAND_SIZE(TEST_UNIT_READY);
req->cmd[0] = TEST_UNIT_READY;
req->timeout = HP_SW_TIMEOUT;
req->sense = h->sense;
memset(req->sense, 0, SCSI_SENSE_BUFFERSIZE);
req->sense_len = 0;
ret = blk_execute_rq(req->q, NULL, req, 1);
if (ret == -EIO) {
if (req->sense_len > 0) {
ret = tur_done(sdev, h->sense);
} else {
sdev_printk(KERN_WARNING, sdev,
"%s: sending tur failed with %x\n",
HP_SW_NAME, req->errors);
ret = SCSI_DH_IO;
}
} else {
h->path_state = HP_SW_PATH_ACTIVE;
ret = SCSI_DH_OK;
}
if (ret == SCSI_DH_IMM_RETRY) {
blk_put_request(req);
goto retry;
}
if (ret == SCSI_DH_DEV_OFFLINED) {
h->path_state = HP_SW_PATH_PASSIVE;
ret = SCSI_DH_OK;
}
blk_put_request(req);
return ret;
}
static int start_done(struct scsi_device *sdev, unsigned char *sense)
{
struct scsi_sense_hdr sshdr;
int rc;
rc = scsi_normalize_sense(sense, SCSI_SENSE_BUFFERSIZE, &sshdr);
if (!rc) {
sdev_printk(KERN_WARNING, sdev,
"%s: sending start_stop_unit failed, "
"no sense available\n",
HP_SW_NAME);
return SCSI_DH_IO;
}
switch (sshdr.sense_key) {
case NOT_READY:
if ((sshdr.asc == 0x04) && (sshdr.ascq == 3)) {
rc = SCSI_DH_RETRY;
break;
}
default:
sdev_printk(KERN_WARNING, sdev,
"%s: sending start_stop_unit failed, sense %x/%x/%x\n",
HP_SW_NAME, sshdr.sense_key, sshdr.asc,
sshdr.ascq);
rc = SCSI_DH_IO;
}
return rc;
}
static void start_stop_endio(struct request *req, int error)
{
struct hp_sw_dh_data *h = req->end_io_data;
unsigned err = SCSI_DH_OK;
if (error || host_byte(req->errors) != DID_OK ||
msg_byte(req->errors) != COMMAND_COMPLETE) {
sdev_printk(KERN_WARNING, h->sdev,
"%s: sending start_stop_unit failed with %x\n",
HP_SW_NAME, req->errors);
err = SCSI_DH_IO;
goto done;
}
if (req->sense_len > 0) {
err = start_done(h->sdev, h->sense);
if (err == SCSI_DH_RETRY) {
err = SCSI_DH_IO;
if (--h->retry_cnt) {
blk_put_request(req);
err = hp_sw_start_stop(h);
if (err == SCSI_DH_OK)
return;
}
}
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
static int hp_sw_start_stop(struct hp_sw_dh_data *h)
{
struct request *req;
req = blk_get_request(h->sdev->request_queue, WRITE, GFP_ATOMIC);
if (IS_ERR(req))
return SCSI_DH_RES_TEMP_UNAVAIL;
blk_rq_set_block_pc(req);
req->cmd_flags |= REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
req->cmd_len = COMMAND_SIZE(START_STOP);
req->cmd[0] = START_STOP;
req->cmd[4] = 1;
req->timeout = HP_SW_TIMEOUT;
req->sense = h->sense;
memset(req->sense, 0, SCSI_SENSE_BUFFERSIZE);
req->sense_len = 0;
req->end_io_data = h;
blk_execute_rq_nowait(req->q, NULL, req, 1, start_stop_endio);
return SCSI_DH_OK;
}
static int hp_sw_prep_fn(struct scsi_device *sdev, struct request *req)
{
struct hp_sw_dh_data *h = sdev->handler_data;
int ret = BLKPREP_OK;
if (h->path_state != HP_SW_PATH_ACTIVE) {
ret = BLKPREP_KILL;
req->rq_flags |= RQF_QUIET;
}
return ret;
}
static int hp_sw_activate(struct scsi_device *sdev,
activate_complete fn, void *data)
{
int ret = SCSI_DH_OK;
struct hp_sw_dh_data *h = sdev->handler_data;
ret = hp_sw_tur(sdev, h);
if (ret == SCSI_DH_OK && h->path_state == HP_SW_PATH_PASSIVE) {
h->retry_cnt = h->retries;
h->callback_fn = fn;
h->callback_data = data;
ret = hp_sw_start_stop(h);
if (ret == SCSI_DH_OK)
return 0;
h->callback_fn = h->callback_data = NULL;
}
if (fn)
fn(data, ret);
return 0;
}
static int hp_sw_bus_attach(struct scsi_device *sdev)
{
struct hp_sw_dh_data *h;
int ret;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return -ENOMEM;
h->path_state = HP_SW_PATH_UNINITIALIZED;
h->retries = HP_SW_RETRIES;
h->sdev = sdev;
ret = hp_sw_tur(sdev, h);
if (ret != SCSI_DH_OK || h->path_state == HP_SW_PATH_UNINITIALIZED)
goto failed;
sdev_printk(KERN_INFO, sdev, "%s: attached to %s path\n",
HP_SW_NAME, h->path_state == HP_SW_PATH_ACTIVE?
"active":"passive");
sdev->handler_data = h;
return 0;
failed:
kfree(h);
return -EINVAL;
}
static void hp_sw_bus_detach( struct scsi_device *sdev )
{
kfree(sdev->handler_data);
sdev->handler_data = NULL;
}
static int __init hp_sw_init(void)
{
return scsi_register_device_handler(&hp_sw_dh);
}
static void __exit hp_sw_exit(void)
{
scsi_unregister_device_handler(&hp_sw_dh);
}
