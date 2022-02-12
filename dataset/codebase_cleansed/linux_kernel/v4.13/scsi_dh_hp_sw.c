static int tur_done(struct scsi_device *sdev, struct hp_sw_dh_data *h,
struct scsi_sense_hdr *sshdr)
{
int ret = SCSI_DH_IO;
switch (sshdr->sense_key) {
case UNIT_ATTENTION:
ret = SCSI_DH_IMM_RETRY;
break;
case NOT_READY:
if (sshdr->asc == 0x04 && sshdr->ascq == 2) {
h->path_state = HP_SW_PATH_PASSIVE;
ret = SCSI_DH_OK;
break;
}
default:
sdev_printk(KERN_WARNING, sdev,
"%s: sending tur failed, sense %x/%x/%x\n",
HP_SW_NAME, sshdr->sense_key, sshdr->asc,
sshdr->ascq);
break;
}
return ret;
}
static int hp_sw_tur(struct scsi_device *sdev, struct hp_sw_dh_data *h)
{
unsigned char cmd[6] = { TEST_UNIT_READY };
struct scsi_sense_hdr sshdr;
int ret = SCSI_DH_OK, res;
u64 req_flags = REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
retry:
res = scsi_execute(sdev, cmd, DMA_NONE, NULL, 0, NULL, &sshdr,
HP_SW_TIMEOUT, HP_SW_RETRIES, req_flags, 0, NULL);
if (res) {
if (scsi_sense_valid(&sshdr))
ret = tur_done(sdev, h, &sshdr);
else {
sdev_printk(KERN_WARNING, sdev,
"%s: sending tur failed with %x\n",
HP_SW_NAME, res);
ret = SCSI_DH_IO;
}
} else {
h->path_state = HP_SW_PATH_ACTIVE;
ret = SCSI_DH_OK;
}
if (ret == SCSI_DH_IMM_RETRY)
goto retry;
return ret;
}
static int hp_sw_start_stop(struct hp_sw_dh_data *h)
{
unsigned char cmd[6] = { START_STOP, 0, 0, 0, 1, 0 };
struct scsi_sense_hdr sshdr;
struct scsi_device *sdev = h->sdev;
int res, rc = SCSI_DH_OK;
int retry_cnt = HP_SW_RETRIES;
u64 req_flags = REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
retry:
res = scsi_execute(sdev, cmd, DMA_NONE, NULL, 0, NULL, &sshdr,
HP_SW_TIMEOUT, HP_SW_RETRIES, req_flags, 0, NULL);
if (res) {
if (!scsi_sense_valid(&sshdr)) {
sdev_printk(KERN_WARNING, sdev,
"%s: sending start_stop_unit failed, "
"no sense available\n", HP_SW_NAME);
return SCSI_DH_IO;
}
switch (sshdr.sense_key) {
case NOT_READY:
if (sshdr.asc == 0x04 && sshdr.ascq == 3) {
if (--retry_cnt)
goto retry;
rc = SCSI_DH_RETRY;
break;
}
default:
sdev_printk(KERN_WARNING, sdev,
"%s: sending start_stop_unit failed, "
"sense %x/%x/%x\n", HP_SW_NAME,
sshdr.sense_key, sshdr.asc, sshdr.ascq);
rc = SCSI_DH_IO;
}
}
return rc;
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
if (ret == SCSI_DH_OK && h->path_state == HP_SW_PATH_PASSIVE)
ret = hp_sw_start_stop(h);
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
