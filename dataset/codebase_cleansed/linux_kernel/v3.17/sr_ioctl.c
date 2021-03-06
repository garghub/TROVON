static int sr_read_tochdr(struct cdrom_device_info *cdi,
struct cdrom_tochdr *tochdr)
{
struct scsi_cd *cd = cdi->handle;
struct packet_command cgc;
int result;
unsigned char *buffer;
buffer = kmalloc(32, GFP_KERNEL | SR_GFP_DMA(cd));
if (!buffer)
return -ENOMEM;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.timeout = IOCTL_TIMEOUT;
cgc.cmd[0] = GPCMD_READ_TOC_PMA_ATIP;
cgc.cmd[8] = 12;
cgc.buffer = buffer;
cgc.buflen = 12;
cgc.quiet = 1;
cgc.data_direction = DMA_FROM_DEVICE;
result = sr_do_ioctl(cd, &cgc);
tochdr->cdth_trk0 = buffer[2];
tochdr->cdth_trk1 = buffer[3];
kfree(buffer);
return result;
}
static int sr_read_tocentry(struct cdrom_device_info *cdi,
struct cdrom_tocentry *tocentry)
{
struct scsi_cd *cd = cdi->handle;
struct packet_command cgc;
int result;
unsigned char *buffer;
buffer = kmalloc(32, GFP_KERNEL | SR_GFP_DMA(cd));
if (!buffer)
return -ENOMEM;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.timeout = IOCTL_TIMEOUT;
cgc.cmd[0] = GPCMD_READ_TOC_PMA_ATIP;
cgc.cmd[1] |= (tocentry->cdte_format == CDROM_MSF) ? 0x02 : 0;
cgc.cmd[6] = tocentry->cdte_track;
cgc.cmd[8] = 12;
cgc.buffer = buffer;
cgc.buflen = 12;
cgc.data_direction = DMA_FROM_DEVICE;
result = sr_do_ioctl(cd, &cgc);
tocentry->cdte_ctrl = buffer[5] & 0xf;
tocentry->cdte_adr = buffer[5] >> 4;
tocentry->cdte_datamode = (tocentry->cdte_ctrl & 0x04) ? 1 : 0;
if (tocentry->cdte_format == CDROM_MSF) {
tocentry->cdte_addr.msf.minute = buffer[9];
tocentry->cdte_addr.msf.second = buffer[10];
tocentry->cdte_addr.msf.frame = buffer[11];
} else
tocentry->cdte_addr.lba = (((((buffer[8] << 8) + buffer[9]) << 8)
+ buffer[10]) << 8) + buffer[11];
kfree(buffer);
return result;
}
static int sr_fake_playtrkind(struct cdrom_device_info *cdi, struct cdrom_ti *ti)
{
struct cdrom_tocentry trk0_te, trk1_te;
struct cdrom_tochdr tochdr;
struct packet_command cgc;
int ntracks, ret;
ret = sr_read_tochdr(cdi, &tochdr);
if (ret)
return ret;
ntracks = tochdr.cdth_trk1 - tochdr.cdth_trk0 + 1;
if (ti->cdti_trk1 == ntracks)
ti->cdti_trk1 = CDROM_LEADOUT;
else if (ti->cdti_trk1 != CDROM_LEADOUT)
ti->cdti_trk1 ++;
trk0_te.cdte_track = ti->cdti_trk0;
trk0_te.cdte_format = CDROM_MSF;
trk1_te.cdte_track = ti->cdti_trk1;
trk1_te.cdte_format = CDROM_MSF;
ret = sr_read_tocentry(cdi, &trk0_te);
if (ret)
return ret;
ret = sr_read_tocentry(cdi, &trk1_te);
if (ret)
return ret;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.cmd[0] = GPCMD_PLAY_AUDIO_MSF;
cgc.cmd[3] = trk0_te.cdte_addr.msf.minute;
cgc.cmd[4] = trk0_te.cdte_addr.msf.second;
cgc.cmd[5] = trk0_te.cdte_addr.msf.frame;
cgc.cmd[6] = trk1_te.cdte_addr.msf.minute;
cgc.cmd[7] = trk1_te.cdte_addr.msf.second;
cgc.cmd[8] = trk1_te.cdte_addr.msf.frame;
cgc.data_direction = DMA_NONE;
cgc.timeout = IOCTL_TIMEOUT;
return sr_do_ioctl(cdi->handle, &cgc);
}
static int sr_play_trkind(struct cdrom_device_info *cdi,
struct cdrom_ti *ti)
{
struct scsi_cd *cd = cdi->handle;
struct packet_command cgc;
int result;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.timeout = IOCTL_TIMEOUT;
cgc.cmd[0] = GPCMD_PLAYAUDIO_TI;
cgc.cmd[4] = ti->cdti_trk0;
cgc.cmd[5] = ti->cdti_ind0;
cgc.cmd[7] = ti->cdti_trk1;
cgc.cmd[8] = ti->cdti_ind1;
cgc.data_direction = DMA_NONE;
result = sr_do_ioctl(cd, &cgc);
if (result == -EDRIVE_CANT_DO_THIS)
result = sr_fake_playtrkind(cdi, ti);
return result;
}
int sr_do_ioctl(Scsi_CD *cd, struct packet_command *cgc)
{
struct scsi_device *SDev;
struct scsi_sense_hdr sshdr;
int result, err = 0, retries = 0;
struct request_sense *sense = cgc->sense;
SDev = cd->device;
if (!sense) {
sense = kmalloc(SCSI_SENSE_BUFFERSIZE, GFP_KERNEL);
if (!sense) {
err = -ENOMEM;
goto out;
}
}
retry:
if (!scsi_block_when_processing_errors(SDev)) {
err = -ENODEV;
goto out;
}
memset(sense, 0, sizeof(*sense));
result = scsi_execute(SDev, cgc->cmd, cgc->data_direction,
cgc->buffer, cgc->buflen, (char *)sense,
cgc->timeout, IOCTL_RETRIES, 0, NULL);
scsi_normalize_sense((char *)sense, sizeof(*sense), &sshdr);
if (driver_byte(result) != 0) {
switch (sshdr.sense_key) {
case UNIT_ATTENTION:
SDev->changed = 1;
if (!cgc->quiet)
sr_printk(KERN_INFO, cd,
"disc change detected.\n");
if (retries++ < 10)
goto retry;
err = -ENOMEDIUM;
break;
case NOT_READY:
if (sshdr.asc == 0x04 &&
sshdr.ascq == 0x01) {
if (!cgc->quiet)
sr_printk(KERN_INFO, cd,
"CDROM not ready yet.\n");
if (retries++ < 10) {
ssleep(2);
goto retry;
} else {
err = -ENOMEDIUM;
break;
}
}
if (!cgc->quiet)
sr_printk(KERN_INFO, cd,
"CDROM not ready. Make sure there "
"is a disc in the drive.\n");
#ifdef DEBUG
scsi_print_sense_hdr("sr", &sshdr);
#endif
err = -ENOMEDIUM;
break;
case ILLEGAL_REQUEST:
err = -EIO;
if (sshdr.asc == 0x20 &&
sshdr.ascq == 0x00)
err = -EDRIVE_CANT_DO_THIS;
#ifdef DEBUG
__scsi_print_command(cgc->cmd);
scsi_print_sense_hdr("sr", &sshdr);
#endif
break;
default:
sr_printk(KERN_ERR, cd,
"CDROM (ioctl) error, command: ");
__scsi_print_command(cgc->cmd);
scsi_print_sense_hdr("sr", &sshdr);
err = -EIO;
}
}
out:
if (!cgc->sense)
kfree(sense);
cgc->stat = err;
return err;
}
int sr_tray_move(struct cdrom_device_info *cdi, int pos)
{
Scsi_CD *cd = cdi->handle;
struct packet_command cgc;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.cmd[0] = GPCMD_START_STOP_UNIT;
cgc.cmd[4] = (pos == 0) ? 0x03 : 0x02 ;
cgc.data_direction = DMA_NONE;
cgc.timeout = IOCTL_TIMEOUT;
return sr_do_ioctl(cd, &cgc);
}
int sr_lock_door(struct cdrom_device_info *cdi, int lock)
{
Scsi_CD *cd = cdi->handle;
return scsi_set_medium_removal(cd->device, lock ?
SCSI_REMOVAL_PREVENT : SCSI_REMOVAL_ALLOW);
}
int sr_drive_status(struct cdrom_device_info *cdi, int slot)
{
struct scsi_cd *cd = cdi->handle;
struct scsi_sense_hdr sshdr;
struct media_event_desc med;
if (CDSL_CURRENT != slot) {
return -EINVAL;
}
if (!scsi_test_unit_ready(cd->device, SR_TIMEOUT, MAX_RETRIES, &sshdr))
return CDS_DISC_OK;
if (scsi_sense_valid(&sshdr) && sshdr.sense_key == NOT_READY
&& sshdr.asc == 0x04 && sshdr.ascq == 0x01)
return CDS_DRIVE_NOT_READY;
if (!cdrom_get_media_event(cdi, &med)) {
if (med.media_present)
return CDS_DISC_OK;
else if (med.door_open)
return CDS_TRAY_OPEN;
else
return CDS_NO_DISC;
}
if (scsi_sense_valid(&sshdr) && sshdr.sense_key == NOT_READY
&& sshdr.asc == 0x04 && sshdr.ascq == 0x02)
return CDS_TRAY_OPEN;
if (sshdr.sense_key == NOT_READY && sshdr.asc == 0x04)
return CDS_DISC_OK;
if (scsi_sense_valid(&sshdr) &&
sshdr.asc == 0x3a)
return CDS_NO_DISC;
else
return CDS_TRAY_OPEN;
return CDS_DRIVE_NOT_READY;
}
int sr_disk_status(struct cdrom_device_info *cdi)
{
Scsi_CD *cd = cdi->handle;
struct cdrom_tochdr toc_h;
struct cdrom_tocentry toc_e;
int i, rc, have_datatracks = 0;
rc = sr_read_tochdr(cdi, &toc_h);
if (rc)
return (rc == -ENOMEDIUM) ? CDS_NO_DISC : CDS_NO_INFO;
for (i = toc_h.cdth_trk0; i <= toc_h.cdth_trk1; i++) {
toc_e.cdte_track = i;
toc_e.cdte_format = CDROM_LBA;
if (sr_read_tocentry(cdi, &toc_e))
return CDS_NO_INFO;
if (toc_e.cdte_ctrl & CDROM_DATA_TRACK) {
have_datatracks = 1;
break;
}
}
if (!have_datatracks)
return CDS_AUDIO;
if (cd->xa_flag)
return CDS_XA_2_1;
else
return CDS_DATA_1;
}
int sr_get_last_session(struct cdrom_device_info *cdi,
struct cdrom_multisession *ms_info)
{
Scsi_CD *cd = cdi->handle;
ms_info->addr.lba = cd->ms_offset;
ms_info->xa_flag = cd->xa_flag || cd->ms_offset > 0;
return 0;
}
int sr_get_mcn(struct cdrom_device_info *cdi, struct cdrom_mcn *mcn)
{
Scsi_CD *cd = cdi->handle;
struct packet_command cgc;
char *buffer = kmalloc(32, GFP_KERNEL | SR_GFP_DMA(cd));
int result;
if (!buffer)
return -ENOMEM;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.cmd[0] = GPCMD_READ_SUBCHANNEL;
cgc.cmd[2] = 0x40;
cgc.cmd[3] = 0x02;
cgc.cmd[8] = 24;
cgc.buffer = buffer;
cgc.buflen = 24;
cgc.data_direction = DMA_FROM_DEVICE;
cgc.timeout = IOCTL_TIMEOUT;
result = sr_do_ioctl(cd, &cgc);
memcpy(mcn->medium_catalog_number, buffer + 9, 13);
mcn->medium_catalog_number[13] = 0;
kfree(buffer);
return result;
}
int sr_reset(struct cdrom_device_info *cdi)
{
return 0;
}
int sr_select_speed(struct cdrom_device_info *cdi, int speed)
{
Scsi_CD *cd = cdi->handle;
struct packet_command cgc;
if (speed == 0)
speed = 0xffff;
else
speed *= 177;
memset(&cgc, 0, sizeof(struct packet_command));
cgc.cmd[0] = GPCMD_SET_SPEED;
cgc.cmd[2] = (speed >> 8) & 0xff;
cgc.cmd[3] = speed & 0xff;
cgc.data_direction = DMA_NONE;
cgc.timeout = IOCTL_TIMEOUT;
if (sr_do_ioctl(cd, &cgc))
return -EIO;
return 0;
}
int sr_audio_ioctl(struct cdrom_device_info *cdi, unsigned int cmd, void *arg)
{
switch (cmd) {
case CDROMREADTOCHDR:
return sr_read_tochdr(cdi, arg);
case CDROMREADTOCENTRY:
return sr_read_tocentry(cdi, arg);
case CDROMPLAYTRKIND:
return sr_play_trkind(cdi, arg);
default:
return -EINVAL;
}
}
static int sr_read_cd(Scsi_CD *cd, unsigned char *dest, int lba, int format, int blksize)
{
struct packet_command cgc;
#ifdef DEBUG
sr_printk(KERN_INFO, cd, "sr_read_cd lba=%d format=%d blksize=%d\n",
lba, format, blksize);
#endif
memset(&cgc, 0, sizeof(struct packet_command));
cgc.cmd[0] = GPCMD_READ_CD;
cgc.cmd[1] = ((format & 7) << 2);
cgc.cmd[2] = (unsigned char) (lba >> 24) & 0xff;
cgc.cmd[3] = (unsigned char) (lba >> 16) & 0xff;
cgc.cmd[4] = (unsigned char) (lba >> 8) & 0xff;
cgc.cmd[5] = (unsigned char) lba & 0xff;
cgc.cmd[8] = 1;
switch (blksize) {
case 2336:
cgc.cmd[9] = 0x58;
break;
case 2340:
cgc.cmd[9] = 0x78;
break;
case 2352:
cgc.cmd[9] = 0xf8;
break;
default:
cgc.cmd[9] = 0x10;
break;
}
cgc.buffer = dest;
cgc.buflen = blksize;
cgc.data_direction = DMA_FROM_DEVICE;
cgc.timeout = IOCTL_TIMEOUT;
return sr_do_ioctl(cd, &cgc);
}
static int sr_read_sector(Scsi_CD *cd, int lba, int blksize, unsigned char *dest)
{
struct packet_command cgc;
int rc;
if (cd->readcd_known) {
rc = sr_read_cd(cd, dest, lba, 0, blksize);
if (-EDRIVE_CANT_DO_THIS != rc)
return rc;
cd->readcd_known = 0;
sr_printk(KERN_INFO, cd,
"CDROM does'nt support READ CD (0xbe) command\n");
}
if (blksize != cd->device->sector_size) {
if (0 != (rc = sr_set_blocklength(cd, blksize)))
return rc;
}
#ifdef DEBUG
sr_printk(KERN_INFO, cd, "sr_read_sector lba=%d blksize=%d\n",
lba, blksize);
#endif
memset(&cgc, 0, sizeof(struct packet_command));
cgc.cmd[0] = GPCMD_READ_10;
cgc.cmd[2] = (unsigned char) (lba >> 24) & 0xff;
cgc.cmd[3] = (unsigned char) (lba >> 16) & 0xff;
cgc.cmd[4] = (unsigned char) (lba >> 8) & 0xff;
cgc.cmd[5] = (unsigned char) lba & 0xff;
cgc.cmd[8] = 1;
cgc.buffer = dest;
cgc.buflen = blksize;
cgc.data_direction = DMA_FROM_DEVICE;
cgc.timeout = IOCTL_TIMEOUT;
rc = sr_do_ioctl(cd, &cgc);
return rc;
}
int sr_is_xa(Scsi_CD *cd)
{
unsigned char *raw_sector;
int is_xa;
if (!xa_test)
return 0;
raw_sector = kmalloc(2048, GFP_KERNEL | SR_GFP_DMA(cd));
if (!raw_sector)
return -ENOMEM;
if (0 == sr_read_sector(cd, cd->ms_offset + 16,
CD_FRAMESIZE_RAW1, raw_sector)) {
is_xa = (raw_sector[3] == 0x02) ? 1 : 0;
} else {
is_xa = -1;
}
kfree(raw_sector);
#ifdef DEBUG
sr_printk(KERN_INFO, cd, "sr_is_xa: %d\n", is_xa);
#endif
return is_xa;
}
