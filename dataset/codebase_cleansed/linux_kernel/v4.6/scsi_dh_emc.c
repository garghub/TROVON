static int trespass_endio(struct scsi_device *sdev, char *sense)
{
int err = SCSI_DH_IO;
struct scsi_sense_hdr sshdr;
if (!scsi_normalize_sense(sense, SCSI_SENSE_BUFFERSIZE, &sshdr)) {
sdev_printk(KERN_ERR, sdev, "%s: Found valid sense data 0x%2x, "
"0x%2x, 0x%2x while sending CLARiiON trespass "
"command.\n", CLARIION_NAME, sshdr.sense_key,
sshdr.asc, sshdr.ascq);
if ((sshdr.sense_key == 0x05) && (sshdr.asc == 0x04) &&
(sshdr.ascq == 0x00)) {
sdev_printk(KERN_INFO, sdev, "%s: Array Based Copy in "
"progress while sending CLARiiON trespass "
"command.\n", CLARIION_NAME);
err = SCSI_DH_DEV_TEMP_BUSY;
} else if ((sshdr.sense_key == 0x02) && (sshdr.asc == 0x04) &&
(sshdr.ascq == 0x03)) {
sdev_printk(KERN_INFO, sdev, "%s: Detected in-progress "
"ucode upgrade NDU operation while sending "
"CLARiiON trespass command.\n", CLARIION_NAME);
err = SCSI_DH_DEV_TEMP_BUSY;
} else
err = SCSI_DH_DEV_FAILED;
} else {
sdev_printk(KERN_INFO, sdev,
"%s: failed to send MODE SELECT, no sense available\n",
CLARIION_NAME);
}
return err;
}
static int parse_sp_info_reply(struct scsi_device *sdev,
struct clariion_dh_data *csdev)
{
int err = SCSI_DH_OK;
if (csdev->buffer[48] != 0) {
sdev_printk(KERN_NOTICE, sdev, "%s: Detected in-progress "
"ucode upgrade NDU operation while finding "
"current active SP.", CLARIION_NAME);
err = SCSI_DH_DEV_TEMP_BUSY;
goto out;
}
if (csdev->buffer[4] > 2) {
sdev_printk(KERN_NOTICE, sdev,
"%s: invalid VPD page 0xC0 format\n",
CLARIION_NAME);
err = SCSI_DH_NOSYS;
goto out;
}
switch (csdev->buffer[28] & 0x0f) {
case 6:
sdev_printk(KERN_NOTICE, sdev,
"%s: ALUA failover mode detected\n",
CLARIION_NAME);
break;
case 4:
break;
default:
sdev_printk(KERN_WARNING, sdev,
"%s: Invalid failover mode %d\n",
CLARIION_NAME, csdev->buffer[28] & 0x0f);
err = SCSI_DH_NOSYS;
goto out;
}
csdev->default_sp = csdev->buffer[5];
csdev->lun_state = csdev->buffer[4];
csdev->current_sp = csdev->buffer[8];
csdev->port = csdev->buffer[7];
if (csdev->lun_state == CLARIION_LUN_OWNED)
sdev->access_state = SCSI_ACCESS_STATE_OPTIMAL;
else
sdev->access_state = SCSI_ACCESS_STATE_STANDBY;
if (csdev->default_sp == csdev->current_sp)
sdev->access_state |= SCSI_ACCESS_STATE_PREFERRED;
out:
return err;
}
static char * parse_sp_model(struct scsi_device *sdev, unsigned char *buffer)
{
unsigned char len = buffer[4] + 5;
char *sp_model = NULL;
unsigned char sp_len, serial_len;
if (len < 160) {
sdev_printk(KERN_WARNING, sdev,
"%s: Invalid information section length %d\n",
CLARIION_NAME, len);
if (!strncmp(buffer + 8, "DGC", 3)) {
sp_model = emc_default_str;
}
goto out;
}
serial_len = buffer[160];
if (serial_len == 0 || serial_len + 161 > len) {
sdev_printk(KERN_WARNING, sdev,
"%s: Invalid array serial number length %d\n",
CLARIION_NAME, serial_len);
goto out;
}
sp_len = buffer[99];
if (sp_len == 0 || serial_len + sp_len + 161 > len) {
sdev_printk(KERN_WARNING, sdev,
"%s: Invalid model number length %d\n",
CLARIION_NAME, sp_len);
goto out;
}
sp_model = &buffer[serial_len + 161];
while (sp_len > 1 && sp_model[sp_len - 1] == ' ')
sp_len--;
sp_model[sp_len] = '\0';
out:
return sp_model;
}
static struct request *get_req(struct scsi_device *sdev, int cmd,
unsigned char *buffer)
{
struct request *rq;
int len = 0;
rq = blk_get_request(sdev->request_queue,
(cmd != INQUIRY) ? WRITE : READ, GFP_NOIO);
if (IS_ERR(rq)) {
sdev_printk(KERN_INFO, sdev, "get_req: blk_get_request failed");
return NULL;
}
blk_rq_set_block_pc(rq);
rq->cmd_len = COMMAND_SIZE(cmd);
rq->cmd[0] = cmd;
switch (cmd) {
case MODE_SELECT:
len = sizeof(short_trespass);
rq->cmd[1] = 0x10;
rq->cmd[4] = len;
break;
case MODE_SELECT_10:
len = sizeof(long_trespass);
rq->cmd[1] = 0x10;
rq->cmd[8] = len;
break;
case INQUIRY:
len = CLARIION_BUFFER_SIZE;
rq->cmd[4] = len;
memset(buffer, 0, len);
break;
default:
BUG_ON(1);
break;
}
rq->cmd_flags |= REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
rq->timeout = CLARIION_TIMEOUT;
rq->retries = CLARIION_RETRIES;
if (blk_rq_map_kern(rq->q, rq, buffer, len, GFP_NOIO)) {
blk_put_request(rq);
return NULL;
}
return rq;
}
static int send_inquiry_cmd(struct scsi_device *sdev, int page,
struct clariion_dh_data *csdev)
{
struct request *rq = get_req(sdev, INQUIRY, csdev->buffer);
int err;
if (!rq)
return SCSI_DH_RES_TEMP_UNAVAIL;
rq->sense = csdev->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = csdev->senselen = 0;
rq->cmd[0] = INQUIRY;
if (page != 0) {
rq->cmd[1] = 1;
rq->cmd[2] = page;
}
err = blk_execute_rq(sdev->request_queue, NULL, rq, 1);
if (err == -EIO) {
sdev_printk(KERN_INFO, sdev,
"%s: failed to send %s INQUIRY: %x\n",
CLARIION_NAME, page?"EVPD":"standard",
rq->errors);
csdev->senselen = rq->sense_len;
err = SCSI_DH_IO;
}
blk_put_request(rq);
return err;
}
static int send_trespass_cmd(struct scsi_device *sdev,
struct clariion_dh_data *csdev)
{
struct request *rq;
unsigned char *page22;
int err, len, cmd;
if (csdev->flags & CLARIION_SHORT_TRESPASS) {
page22 = short_trespass;
if (!(csdev->flags & CLARIION_HONOR_RESERVATIONS))
page22[6] |= 0x80;
len = sizeof(short_trespass);
cmd = MODE_SELECT;
} else {
page22 = long_trespass;
if (!(csdev->flags & CLARIION_HONOR_RESERVATIONS))
page22[10] |= 0x80;
len = sizeof(long_trespass);
cmd = MODE_SELECT_10;
}
BUG_ON((len > CLARIION_BUFFER_SIZE));
memcpy(csdev->buffer, page22, len);
rq = get_req(sdev, cmd, csdev->buffer);
if (!rq)
return SCSI_DH_RES_TEMP_UNAVAIL;
rq->sense = csdev->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = csdev->senselen = 0;
err = blk_execute_rq(sdev->request_queue, NULL, rq, 1);
if (err == -EIO) {
if (rq->sense_len) {
err = trespass_endio(sdev, csdev->sense);
} else {
sdev_printk(KERN_INFO, sdev,
"%s: failed to send MODE SELECT: %x\n",
CLARIION_NAME, rq->errors);
}
}
blk_put_request(rq);
return err;
}
static int clariion_check_sense(struct scsi_device *sdev,
struct scsi_sense_hdr *sense_hdr)
{
switch (sense_hdr->sense_key) {
case NOT_READY:
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x03)
return SUCCESS;
break;
case ILLEGAL_REQUEST:
if (sense_hdr->asc == 0x25 && sense_hdr->ascq == 0x01)
return SUCCESS;
break;
case UNIT_ATTENTION:
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x00)
return ADD_TO_MLQUEUE;
break;
}
return SCSI_RETURN_NOT_HANDLED;
}
static int clariion_prep_fn(struct scsi_device *sdev, struct request *req)
{
struct clariion_dh_data *h = sdev->handler_data;
int ret = BLKPREP_OK;
if (h->lun_state != CLARIION_LUN_OWNED) {
ret = BLKPREP_KILL;
req->cmd_flags |= REQ_QUIET;
}
return ret;
}
static int clariion_std_inquiry(struct scsi_device *sdev,
struct clariion_dh_data *csdev)
{
int err;
char *sp_model;
err = send_inquiry_cmd(sdev, 0, csdev);
if (err != SCSI_DH_OK && csdev->senselen) {
struct scsi_sense_hdr sshdr;
if (scsi_normalize_sense(csdev->sense, SCSI_SENSE_BUFFERSIZE,
&sshdr)) {
sdev_printk(KERN_ERR, sdev, "%s: INQUIRY sense code "
"%02x/%02x/%02x\n", CLARIION_NAME,
sshdr.sense_key, sshdr.asc, sshdr.ascq);
}
err = SCSI_DH_IO;
goto out;
}
sp_model = parse_sp_model(sdev, csdev->buffer);
if (!sp_model) {
err = SCSI_DH_DEV_UNSUPP;
goto out;
}
if (!strlen(sp_model) || !strncmp(sp_model, "FC",2))
csdev->flags |= CLARIION_SHORT_TRESPASS;
sdev_printk(KERN_INFO, sdev,
"%s: detected Clariion %s, flags %x\n",
CLARIION_NAME, sp_model, csdev->flags);
out:
return err;
}
static int clariion_send_inquiry(struct scsi_device *sdev,
struct clariion_dh_data *csdev)
{
int err, retry = CLARIION_RETRIES;
retry:
err = send_inquiry_cmd(sdev, 0xC0, csdev);
if (err != SCSI_DH_OK && csdev->senselen) {
struct scsi_sense_hdr sshdr;
err = scsi_normalize_sense(csdev->sense, SCSI_SENSE_BUFFERSIZE,
&sshdr);
if (!err)
return SCSI_DH_IO;
err = clariion_check_sense(sdev, &sshdr);
if (retry > 0 && err == ADD_TO_MLQUEUE) {
retry--;
goto retry;
}
sdev_printk(KERN_ERR, sdev, "%s: INQUIRY sense code "
"%02x/%02x/%02x\n", CLARIION_NAME,
sshdr.sense_key, sshdr.asc, sshdr.ascq);
err = SCSI_DH_IO;
} else {
err = parse_sp_info_reply(sdev, csdev);
}
return err;
}
static int clariion_activate(struct scsi_device *sdev,
activate_complete fn, void *data)
{
struct clariion_dh_data *csdev = sdev->handler_data;
int result;
result = clariion_send_inquiry(sdev, csdev);
if (result != SCSI_DH_OK)
goto done;
if (csdev->lun_state == CLARIION_LUN_OWNED)
goto done;
result = send_trespass_cmd(sdev, csdev);
if (result != SCSI_DH_OK)
goto done;
sdev_printk(KERN_INFO, sdev,"%s: %s trespass command sent\n",
CLARIION_NAME,
csdev->flags&CLARIION_SHORT_TRESPASS?"short":"long" );
result = clariion_send_inquiry(sdev, csdev);
if (result != SCSI_DH_OK)
goto done;
done:
sdev_printk(KERN_INFO, sdev,
"%s: at SP %c Port %d (%s, default SP %c)\n",
CLARIION_NAME, csdev->current_sp + 'A',
csdev->port, lun_state[csdev->lun_state],
csdev->default_sp + 'A');
if (fn)
fn(data, result);
return 0;
}
static int clariion_set_params(struct scsi_device *sdev, const char *params)
{
struct clariion_dh_data *csdev = sdev->handler_data;
unsigned int hr = 0, st = 0, argc;
const char *p = params;
int result = SCSI_DH_OK;
if ((sscanf(params, "%u", &argc) != 1) || (argc != 2))
return -EINVAL;
while (*p++)
;
if ((sscanf(p, "%u", &st) != 1) || (st > 1))
return -EINVAL;
while (*p++)
;
if ((sscanf(p, "%u", &hr) != 1) || (hr > 1))
return -EINVAL;
if (st)
csdev->flags |= CLARIION_SHORT_TRESPASS;
else
csdev->flags &= ~CLARIION_SHORT_TRESPASS;
if (hr)
csdev->flags |= CLARIION_HONOR_RESERVATIONS;
else
csdev->flags &= ~CLARIION_HONOR_RESERVATIONS;
if (csdev->lun_state != CLARIION_LUN_OWNED)
goto done;
csdev->lun_state = CLARIION_LUN_UNINITIALIZED;
result = send_trespass_cmd(sdev, csdev);
if (result != SCSI_DH_OK)
goto done;
result = clariion_send_inquiry(sdev, csdev);
done:
return result;
}
static int clariion_bus_attach(struct scsi_device *sdev)
{
struct clariion_dh_data *h;
int err;
h = kzalloc(sizeof(*h) , GFP_KERNEL);
if (!h)
return -ENOMEM;
h->lun_state = CLARIION_LUN_UNINITIALIZED;
h->default_sp = CLARIION_UNBOUND_LU;
h->current_sp = CLARIION_UNBOUND_LU;
err = clariion_std_inquiry(sdev, h);
if (err != SCSI_DH_OK)
goto failed;
err = clariion_send_inquiry(sdev, h);
if (err != SCSI_DH_OK)
goto failed;
sdev_printk(KERN_INFO, sdev,
"%s: connected to SP %c Port %d (%s, default SP %c)\n",
CLARIION_NAME, h->current_sp + 'A',
h->port, lun_state[h->lun_state],
h->default_sp + 'A');
sdev->handler_data = h;
return 0;
failed:
kfree(h);
return -EINVAL;
}
static void clariion_bus_detach(struct scsi_device *sdev)
{
kfree(sdev->handler_data);
sdev->handler_data = NULL;
}
static int __init clariion_init(void)
{
int r;
r = scsi_register_device_handler(&clariion_dh);
if (r != 0)
printk(KERN_ERR "%s: Failed to register scsi device handler.",
CLARIION_NAME);
return r;
}
static void __exit clariion_exit(void)
{
scsi_unregister_device_handler(&clariion_dh);
}
