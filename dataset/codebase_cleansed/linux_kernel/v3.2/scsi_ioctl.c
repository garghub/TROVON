static int sg_get_version(int __user *p)
{
static const int sg_version_num = 30527;
return put_user(sg_version_num, p);
}
static int scsi_get_idlun(struct request_queue *q, int __user *p)
{
return put_user(0, p);
}
static int scsi_get_bus(struct request_queue *q, int __user *p)
{
return put_user(0, p);
}
static int sg_get_timeout(struct request_queue *q)
{
return jiffies_to_clock_t(q->sg_timeout);
}
static int sg_set_timeout(struct request_queue *q, int __user *p)
{
int timeout, err = get_user(timeout, p);
if (!err)
q->sg_timeout = clock_t_to_jiffies(timeout);
return err;
}
static int sg_get_reserved_size(struct request_queue *q, int __user *p)
{
unsigned val = min(q->sg_reserved_size, queue_max_sectors(q) << 9);
return put_user(val, p);
}
static int sg_set_reserved_size(struct request_queue *q, int __user *p)
{
int size, err = get_user(size, p);
if (err)
return err;
if (size < 0)
return -EINVAL;
if (size > (queue_max_sectors(q) << 9))
size = queue_max_sectors(q) << 9;
q->sg_reserved_size = size;
return 0;
}
static int sg_emulated_host(struct request_queue *q, int __user *p)
{
return put_user(1, p);
}
static void blk_set_cmd_filter_defaults(struct blk_cmd_filter *filter)
{
__set_bit(TEST_UNIT_READY, filter->read_ok);
__set_bit(REQUEST_SENSE, filter->read_ok);
__set_bit(READ_6, filter->read_ok);
__set_bit(READ_10, filter->read_ok);
__set_bit(READ_12, filter->read_ok);
__set_bit(READ_16, filter->read_ok);
__set_bit(READ_BUFFER, filter->read_ok);
__set_bit(READ_DEFECT_DATA, filter->read_ok);
__set_bit(READ_CAPACITY, filter->read_ok);
__set_bit(READ_LONG, filter->read_ok);
__set_bit(INQUIRY, filter->read_ok);
__set_bit(MODE_SENSE, filter->read_ok);
__set_bit(MODE_SENSE_10, filter->read_ok);
__set_bit(LOG_SENSE, filter->read_ok);
__set_bit(START_STOP, filter->read_ok);
__set_bit(GPCMD_VERIFY_10, filter->read_ok);
__set_bit(VERIFY_16, filter->read_ok);
__set_bit(REPORT_LUNS, filter->read_ok);
__set_bit(SERVICE_ACTION_IN, filter->read_ok);
__set_bit(RECEIVE_DIAGNOSTIC, filter->read_ok);
__set_bit(MAINTENANCE_IN, filter->read_ok);
__set_bit(GPCMD_READ_BUFFER_CAPACITY, filter->read_ok);
__set_bit(GPCMD_PLAY_CD, filter->read_ok);
__set_bit(GPCMD_PLAY_AUDIO_10, filter->read_ok);
__set_bit(GPCMD_PLAY_AUDIO_MSF, filter->read_ok);
__set_bit(GPCMD_PLAY_AUDIO_TI, filter->read_ok);
__set_bit(GPCMD_PAUSE_RESUME, filter->read_ok);
__set_bit(GPCMD_READ_CD, filter->read_ok);
__set_bit(GPCMD_READ_CD_MSF, filter->read_ok);
__set_bit(GPCMD_READ_DISC_INFO, filter->read_ok);
__set_bit(GPCMD_READ_CDVD_CAPACITY, filter->read_ok);
__set_bit(GPCMD_READ_DVD_STRUCTURE, filter->read_ok);
__set_bit(GPCMD_READ_HEADER, filter->read_ok);
__set_bit(GPCMD_READ_TRACK_RZONE_INFO, filter->read_ok);
__set_bit(GPCMD_READ_SUBCHANNEL, filter->read_ok);
__set_bit(GPCMD_READ_TOC_PMA_ATIP, filter->read_ok);
__set_bit(GPCMD_REPORT_KEY, filter->read_ok);
__set_bit(GPCMD_SCAN, filter->read_ok);
__set_bit(GPCMD_GET_CONFIGURATION, filter->read_ok);
__set_bit(GPCMD_READ_FORMAT_CAPACITIES, filter->read_ok);
__set_bit(GPCMD_GET_EVENT_STATUS_NOTIFICATION, filter->read_ok);
__set_bit(GPCMD_GET_PERFORMANCE, filter->read_ok);
__set_bit(GPCMD_SEEK, filter->read_ok);
__set_bit(GPCMD_STOP_PLAY_SCAN, filter->read_ok);
__set_bit(WRITE_6, filter->write_ok);
__set_bit(WRITE_10, filter->write_ok);
__set_bit(WRITE_VERIFY, filter->write_ok);
__set_bit(WRITE_12, filter->write_ok);
__set_bit(WRITE_VERIFY_12, filter->write_ok);
__set_bit(WRITE_16, filter->write_ok);
__set_bit(WRITE_LONG, filter->write_ok);
__set_bit(WRITE_LONG_2, filter->write_ok);
__set_bit(ERASE, filter->write_ok);
__set_bit(GPCMD_MODE_SELECT_10, filter->write_ok);
__set_bit(MODE_SELECT, filter->write_ok);
__set_bit(LOG_SELECT, filter->write_ok);
__set_bit(GPCMD_BLANK, filter->write_ok);
__set_bit(GPCMD_CLOSE_TRACK, filter->write_ok);
__set_bit(GPCMD_FLUSH_CACHE, filter->write_ok);
__set_bit(GPCMD_FORMAT_UNIT, filter->write_ok);
__set_bit(GPCMD_REPAIR_RZONE_TRACK, filter->write_ok);
__set_bit(GPCMD_RESERVE_RZONE_TRACK, filter->write_ok);
__set_bit(GPCMD_SEND_DVD_STRUCTURE, filter->write_ok);
__set_bit(GPCMD_SEND_EVENT, filter->write_ok);
__set_bit(GPCMD_SEND_KEY, filter->write_ok);
__set_bit(GPCMD_SEND_OPC, filter->write_ok);
__set_bit(GPCMD_SEND_CUE_SHEET, filter->write_ok);
__set_bit(GPCMD_SET_SPEED, filter->write_ok);
__set_bit(GPCMD_PREVENT_ALLOW_MEDIUM_REMOVAL, filter->write_ok);
__set_bit(GPCMD_LOAD_UNLOAD, filter->write_ok);
__set_bit(GPCMD_SET_STREAMING, filter->write_ok);
__set_bit(GPCMD_SET_READ_AHEAD, filter->write_ok);
}
int blk_verify_command(unsigned char *cmd, fmode_t has_write_perm)
{
struct blk_cmd_filter *filter = &blk_default_cmd_filter;
if (capable(CAP_SYS_RAWIO))
return 0;
if (!filter)
return -EPERM;
if (test_bit(cmd[0], filter->read_ok))
return 0;
if (test_bit(cmd[0], filter->write_ok) && has_write_perm)
return 0;
return -EPERM;
}
static int blk_fill_sghdr_rq(struct request_queue *q, struct request *rq,
struct sg_io_hdr *hdr, fmode_t mode)
{
if (copy_from_user(rq->cmd, hdr->cmdp, hdr->cmd_len))
return -EFAULT;
if (blk_verify_command(rq->cmd, mode & FMODE_WRITE))
return -EPERM;
rq->cmd_len = hdr->cmd_len;
rq->cmd_type = REQ_TYPE_BLOCK_PC;
rq->timeout = msecs_to_jiffies(hdr->timeout);
if (!rq->timeout)
rq->timeout = q->sg_timeout;
if (!rq->timeout)
rq->timeout = BLK_DEFAULT_SG_TIMEOUT;
if (rq->timeout < BLK_MIN_SG_TIMEOUT)
rq->timeout = BLK_MIN_SG_TIMEOUT;
return 0;
}
static int blk_complete_sghdr_rq(struct request *rq, struct sg_io_hdr *hdr,
struct bio *bio)
{
int r, ret = 0;
hdr->status = rq->errors & 0xff;
hdr->masked_status = status_byte(rq->errors);
hdr->msg_status = msg_byte(rq->errors);
hdr->host_status = host_byte(rq->errors);
hdr->driver_status = driver_byte(rq->errors);
hdr->info = 0;
if (hdr->masked_status || hdr->host_status || hdr->driver_status)
hdr->info |= SG_INFO_CHECK;
hdr->resid = rq->resid_len;
hdr->sb_len_wr = 0;
if (rq->sense_len && hdr->sbp) {
int len = min((unsigned int) hdr->mx_sb_len, rq->sense_len);
if (!copy_to_user(hdr->sbp, rq->sense, len))
hdr->sb_len_wr = len;
else
ret = -EFAULT;
}
r = blk_rq_unmap_user(bio);
if (!ret)
ret = r;
blk_put_request(rq);
return ret;
}
static int sg_io(struct request_queue *q, struct gendisk *bd_disk,
struct sg_io_hdr *hdr, fmode_t mode)
{
unsigned long start_time;
int writing = 0, ret = 0;
struct request *rq;
char sense[SCSI_SENSE_BUFFERSIZE];
struct bio *bio;
if (hdr->interface_id != 'S')
return -EINVAL;
if (hdr->cmd_len > BLK_MAX_CDB)
return -EINVAL;
if (hdr->dxfer_len > (queue_max_hw_sectors(q) << 9))
return -EIO;
if (hdr->dxfer_len)
switch (hdr->dxfer_direction) {
default:
return -EINVAL;
case SG_DXFER_TO_DEV:
writing = 1;
break;
case SG_DXFER_TO_FROM_DEV:
case SG_DXFER_FROM_DEV:
break;
}
rq = blk_get_request(q, writing ? WRITE : READ, GFP_KERNEL);
if (!rq)
return -ENOMEM;
if (blk_fill_sghdr_rq(q, rq, hdr, mode)) {
blk_put_request(rq);
return -EFAULT;
}
if (hdr->iovec_count) {
const int size = sizeof(struct sg_iovec) * hdr->iovec_count;
size_t iov_data_len;
struct sg_iovec *sg_iov;
struct iovec *iov;
int i;
sg_iov = kmalloc(size, GFP_KERNEL);
if (!sg_iov) {
ret = -ENOMEM;
goto out;
}
if (copy_from_user(sg_iov, hdr->dxferp, size)) {
kfree(sg_iov);
ret = -EFAULT;
goto out;
}
iov = (struct iovec *) sg_iov;
iov_data_len = 0;
for (i = 0; i < hdr->iovec_count; i++) {
if (iov_data_len + iov[i].iov_len < iov_data_len) {
kfree(sg_iov);
ret = -EINVAL;
goto out;
}
iov_data_len += iov[i].iov_len;
}
if (hdr->dxfer_len < iov_data_len) {
hdr->iovec_count = iov_shorten(iov,
hdr->iovec_count,
hdr->dxfer_len);
iov_data_len = hdr->dxfer_len;
}
ret = blk_rq_map_user_iov(q, rq, NULL, sg_iov, hdr->iovec_count,
iov_data_len, GFP_KERNEL);
kfree(sg_iov);
} else if (hdr->dxfer_len)
ret = blk_rq_map_user(q, rq, NULL, hdr->dxferp, hdr->dxfer_len,
GFP_KERNEL);
if (ret)
goto out;
bio = rq->bio;
memset(sense, 0, sizeof(sense));
rq->sense = sense;
rq->sense_len = 0;
rq->retries = 0;
start_time = jiffies;
blk_execute_rq(q, bd_disk, rq, 0);
hdr->duration = jiffies_to_msecs(jiffies - start_time);
return blk_complete_sghdr_rq(rq, hdr, bio);
out:
blk_put_request(rq);
return ret;
}
int sg_scsi_ioctl(struct request_queue *q, struct gendisk *disk, fmode_t mode,
struct scsi_ioctl_command __user *sic)
{
struct request *rq;
int err;
unsigned int in_len, out_len, bytes, opcode, cmdlen;
char *buffer = NULL, sense[SCSI_SENSE_BUFFERSIZE];
if (!sic)
return -EINVAL;
if (get_user(in_len, &sic->inlen))
return -EFAULT;
if (get_user(out_len, &sic->outlen))
return -EFAULT;
if (in_len > PAGE_SIZE || out_len > PAGE_SIZE)
return -EINVAL;
if (get_user(opcode, sic->data))
return -EFAULT;
bytes = max(in_len, out_len);
if (bytes) {
buffer = kzalloc(bytes, q->bounce_gfp | GFP_USER| __GFP_NOWARN);
if (!buffer)
return -ENOMEM;
}
rq = blk_get_request(q, in_len ? WRITE : READ, __GFP_WAIT);
cmdlen = COMMAND_SIZE(opcode);
err = -EFAULT;
rq->cmd_len = cmdlen;
if (copy_from_user(rq->cmd, sic->data, cmdlen))
goto error;
if (in_len && copy_from_user(buffer, sic->data + cmdlen, in_len))
goto error;
err = blk_verify_command(rq->cmd, mode & FMODE_WRITE);
if (err)
goto error;
rq->retries = 5;
switch (opcode) {
case SEND_DIAGNOSTIC:
case FORMAT_UNIT:
rq->timeout = FORMAT_UNIT_TIMEOUT;
rq->retries = 1;
break;
case START_STOP:
rq->timeout = START_STOP_TIMEOUT;
break;
case MOVE_MEDIUM:
rq->timeout = MOVE_MEDIUM_TIMEOUT;
break;
case READ_ELEMENT_STATUS:
rq->timeout = READ_ELEMENT_STATUS_TIMEOUT;
break;
case READ_DEFECT_DATA:
rq->timeout = READ_DEFECT_DATA_TIMEOUT;
rq->retries = 1;
break;
default:
rq->timeout = BLK_DEFAULT_SG_TIMEOUT;
break;
}
if (bytes && blk_rq_map_kern(q, rq, buffer, bytes, __GFP_WAIT)) {
err = DRIVER_ERROR << 24;
goto out;
}
memset(sense, 0, sizeof(sense));
rq->sense = sense;
rq->sense_len = 0;
rq->cmd_type = REQ_TYPE_BLOCK_PC;
blk_execute_rq(q, disk, rq, 0);
out:
err = rq->errors & 0xff;
if (err) {
if (rq->sense_len && rq->sense) {
bytes = (OMAX_SB_LEN > rq->sense_len) ?
rq->sense_len : OMAX_SB_LEN;
if (copy_to_user(sic->data, rq->sense, bytes))
err = -EFAULT;
}
} else {
if (copy_to_user(sic->data, buffer, out_len))
err = -EFAULT;
}
error:
kfree(buffer);
blk_put_request(rq);
return err;
}
static int __blk_send_generic(struct request_queue *q, struct gendisk *bd_disk,
int cmd, int data)
{
struct request *rq;
int err;
rq = blk_get_request(q, WRITE, __GFP_WAIT);
rq->cmd_type = REQ_TYPE_BLOCK_PC;
rq->timeout = BLK_DEFAULT_SG_TIMEOUT;
rq->cmd[0] = cmd;
rq->cmd[4] = data;
rq->cmd_len = 6;
err = blk_execute_rq(q, bd_disk, rq, 0);
blk_put_request(rq);
return err;
}
static inline int blk_send_start_stop(struct request_queue *q,
struct gendisk *bd_disk, int data)
{
return __blk_send_generic(q, bd_disk, GPCMD_START_STOP_UNIT, data);
}
int scsi_cmd_ioctl(struct request_queue *q, struct gendisk *bd_disk, fmode_t mode,
unsigned int cmd, void __user *arg)
{
int err;
if (!q)
return -ENXIO;
switch (cmd) {
case SG_GET_VERSION_NUM:
err = sg_get_version(arg);
break;
case SCSI_IOCTL_GET_IDLUN:
err = scsi_get_idlun(q, arg);
break;
case SCSI_IOCTL_GET_BUS_NUMBER:
err = scsi_get_bus(q, arg);
break;
case SG_SET_TIMEOUT:
err = sg_set_timeout(q, arg);
break;
case SG_GET_TIMEOUT:
err = sg_get_timeout(q);
break;
case SG_GET_RESERVED_SIZE:
err = sg_get_reserved_size(q, arg);
break;
case SG_SET_RESERVED_SIZE:
err = sg_set_reserved_size(q, arg);
break;
case SG_EMULATED_HOST:
err = sg_emulated_host(q, arg);
break;
case SG_IO: {
struct sg_io_hdr hdr;
err = -EFAULT;
if (copy_from_user(&hdr, arg, sizeof(hdr)))
break;
err = sg_io(q, bd_disk, &hdr, mode);
if (err == -EFAULT)
break;
if (copy_to_user(arg, &hdr, sizeof(hdr)))
err = -EFAULT;
break;
}
case CDROM_SEND_PACKET: {
struct cdrom_generic_command cgc;
struct sg_io_hdr hdr;
err = -EFAULT;
if (copy_from_user(&cgc, arg, sizeof(cgc)))
break;
cgc.timeout = clock_t_to_jiffies(cgc.timeout);
memset(&hdr, 0, sizeof(hdr));
hdr.interface_id = 'S';
hdr.cmd_len = sizeof(cgc.cmd);
hdr.dxfer_len = cgc.buflen;
err = 0;
switch (cgc.data_direction) {
case CGC_DATA_UNKNOWN:
hdr.dxfer_direction = SG_DXFER_UNKNOWN;
break;
case CGC_DATA_WRITE:
hdr.dxfer_direction = SG_DXFER_TO_DEV;
break;
case CGC_DATA_READ:
hdr.dxfer_direction = SG_DXFER_FROM_DEV;
break;
case CGC_DATA_NONE:
hdr.dxfer_direction = SG_DXFER_NONE;
break;
default:
err = -EINVAL;
}
if (err)
break;
hdr.dxferp = cgc.buffer;
hdr.sbp = cgc.sense;
if (hdr.sbp)
hdr.mx_sb_len = sizeof(struct request_sense);
hdr.timeout = jiffies_to_msecs(cgc.timeout);
hdr.cmdp = ((struct cdrom_generic_command __user*) arg)->cmd;
hdr.cmd_len = sizeof(cgc.cmd);
err = sg_io(q, bd_disk, &hdr, mode);
if (err == -EFAULT)
break;
if (hdr.status)
err = -EIO;
cgc.stat = err;
cgc.buflen = hdr.resid;
if (copy_to_user(arg, &cgc, sizeof(cgc)))
err = -EFAULT;
break;
}
case SCSI_IOCTL_SEND_COMMAND:
printk(KERN_WARNING "program %s is using a deprecated SCSI ioctl, please convert it to SG_IO\n", current->comm);
err = -EINVAL;
if (!arg)
break;
err = sg_scsi_ioctl(q, bd_disk, mode, arg);
break;
case CDROMCLOSETRAY:
err = blk_send_start_stop(q, bd_disk, 0x03);
break;
case CDROMEJECT:
err = blk_send_start_stop(q, bd_disk, 0x02);
break;
default:
err = -ENOTTY;
}
return err;
}
static int __init blk_scsi_ioctl_init(void)
{
blk_set_cmd_filter_defaults(&blk_default_cmd_filter);
return 0;
}
