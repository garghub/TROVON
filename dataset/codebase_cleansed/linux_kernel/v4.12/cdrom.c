int cdrom_dummy_generic_packet(struct cdrom_device_info *cdi,
struct packet_command *cgc)
{
if (cgc->sense) {
cgc->sense->sense_key = 0x05;
cgc->sense->asc = 0x20;
cgc->sense->ascq = 0x00;
}
cgc->stat = -EIO;
return -EIO;
}
static int cdrom_flush_cache(struct cdrom_device_info *cdi)
{
struct packet_command cgc;
init_cdrom_command(&cgc, NULL, 0, CGC_DATA_NONE);
cgc.cmd[0] = GPCMD_FLUSH_CACHE;
cgc.timeout = 5 * 60 * HZ;
return cdi->ops->generic_packet(cdi, &cgc);
}
static int cdrom_get_disc_info(struct cdrom_device_info *cdi,
disc_information *di)
{
const struct cdrom_device_ops *cdo = cdi->ops;
struct packet_command cgc;
int ret, buflen;
init_cdrom_command(&cgc, di, sizeof(*di), CGC_DATA_READ);
cgc.cmd[0] = GPCMD_READ_DISC_INFO;
cgc.cmd[8] = cgc.buflen = 2;
cgc.quiet = 1;
ret = cdo->generic_packet(cdi, &cgc);
if (ret)
return ret;
buflen = be16_to_cpu(di->disc_information_length) +
sizeof(di->disc_information_length);
if (buflen > sizeof(disc_information))
buflen = sizeof(disc_information);
cgc.cmd[8] = cgc.buflen = buflen;
ret = cdo->generic_packet(cdi, &cgc);
if (ret)
return ret;
return buflen;
}
static int cdrom_mrw_probe_pc(struct cdrom_device_info *cdi)
{
struct packet_command cgc;
char buffer[16];
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.timeout = HZ;
cgc.quiet = 1;
if (!cdrom_mode_sense(cdi, &cgc, MRW_MODE_PC, 0)) {
cdi->mrw_mode_page = MRW_MODE_PC;
return 0;
} else if (!cdrom_mode_sense(cdi, &cgc, MRW_MODE_PC_PRE1, 0)) {
cdi->mrw_mode_page = MRW_MODE_PC_PRE1;
return 0;
}
return 1;
}
static int cdrom_is_mrw(struct cdrom_device_info *cdi, int *write)
{
struct packet_command cgc;
struct mrw_feature_desc *mfd;
unsigned char buffer[16];
int ret;
*write = 0;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.cmd[0] = GPCMD_GET_CONFIGURATION;
cgc.cmd[3] = CDF_MRW;
cgc.cmd[8] = sizeof(buffer);
cgc.quiet = 1;
if ((ret = cdi->ops->generic_packet(cdi, &cgc)))
return ret;
mfd = (struct mrw_feature_desc *)&buffer[sizeof(struct feature_header)];
if (be16_to_cpu(mfd->feature_code) != CDF_MRW)
return 1;
*write = mfd->write;
if ((ret = cdrom_mrw_probe_pc(cdi))) {
*write = 0;
return ret;
}
return 0;
}
static int cdrom_mrw_bgformat(struct cdrom_device_info *cdi, int cont)
{
struct packet_command cgc;
unsigned char buffer[12];
int ret;
pr_info("%sstarting format\n", cont ? "Re" : "");
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_WRITE);
cgc.cmd[0] = GPCMD_FORMAT_UNIT;
cgc.cmd[1] = (1 << 4) | 1;
cgc.timeout = 5 * 60 * HZ;
buffer[1] = 1 << 1;
buffer[3] = 8;
buffer[4] = 0xff;
buffer[5] = 0xff;
buffer[6] = 0xff;
buffer[7] = 0xff;
buffer[8] = 0x24 << 2;
buffer[11] = cont;
ret = cdi->ops->generic_packet(cdi, &cgc);
if (ret)
pr_info("bgformat failed\n");
return ret;
}
static int cdrom_mrw_bgformat_susp(struct cdrom_device_info *cdi, int immed)
{
struct packet_command cgc;
init_cdrom_command(&cgc, NULL, 0, CGC_DATA_NONE);
cgc.cmd[0] = GPCMD_CLOSE_TRACK;
cgc.cmd[1] = !!immed;
cgc.cmd[2] = 1 << 1;
cgc.timeout = 5 * 60 * HZ;
return cdi->ops->generic_packet(cdi, &cgc);
}
static int cdrom_mrw_exit(struct cdrom_device_info *cdi)
{
disc_information di;
int ret;
ret = cdrom_get_disc_info(cdi, &di);
if (ret < 0 || ret < (int)offsetof(typeof(di),disc_type))
return 1;
ret = 0;
if (di.mrw_status == CDM_MRW_BGFORMAT_ACTIVE) {
pr_info("issuing MRW background format suspend\n");
ret = cdrom_mrw_bgformat_susp(cdi, 0);
}
if (!ret && cdi->media_written)
ret = cdrom_flush_cache(cdi);
return ret;
}
static int cdrom_mrw_set_lba_space(struct cdrom_device_info *cdi, int space)
{
struct packet_command cgc;
struct mode_page_header *mph;
char buffer[16];
int ret, offset, size;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.buffer = buffer;
cgc.buflen = sizeof(buffer);
ret = cdrom_mode_sense(cdi, &cgc, cdi->mrw_mode_page, 0);
if (ret)
return ret;
mph = (struct mode_page_header *)buffer;
offset = be16_to_cpu(mph->desc_length);
size = be16_to_cpu(mph->mode_data_length) + 2;
buffer[offset + 3] = space;
cgc.buflen = size;
ret = cdrom_mode_select(cdi, &cgc);
if (ret)
return ret;
pr_info("%s: mrw address space %s selected\n",
cdi->name, mrw_address_space[space]);
return 0;
}
int register_cdrom(struct cdrom_device_info *cdi)
{
static char banner_printed;
const struct cdrom_device_ops *cdo = cdi->ops;
int *change_capability = (int *)&cdo->capability;
cd_dbg(CD_OPEN, "entering register_cdrom\n");
if (cdo->open == NULL || cdo->release == NULL)
return -EINVAL;
if (!banner_printed) {
pr_info("Uniform CD-ROM driver " REVISION "\n");
banner_printed = 1;
cdrom_sysctl_register();
}
ENSURE(drive_status, CDC_DRIVE_STATUS);
if (cdo->check_events == NULL && cdo->media_changed == NULL)
*change_capability = ~(CDC_MEDIA_CHANGED | CDC_SELECT_DISC);
ENSURE(tray_move, CDC_CLOSE_TRAY | CDC_OPEN_TRAY);
ENSURE(lock_door, CDC_LOCK);
ENSURE(select_speed, CDC_SELECT_SPEED);
ENSURE(get_last_session, CDC_MULTI_SESSION);
ENSURE(get_mcn, CDC_MCN);
ENSURE(reset, CDC_RESET);
ENSURE(generic_packet, CDC_GENERIC_PACKET);
cdi->mc_flags = 0;
cdi->options = CDO_USE_FFLAGS;
if (autoclose == 1 && CDROM_CAN(CDC_CLOSE_TRAY))
cdi->options |= (int) CDO_AUTO_CLOSE;
if (autoeject == 1 && CDROM_CAN(CDC_OPEN_TRAY))
cdi->options |= (int) CDO_AUTO_EJECT;
if (lockdoor == 1)
cdi->options |= (int) CDO_LOCK;
if (check_media_type == 1)
cdi->options |= (int) CDO_CHECK_TYPE;
if (CDROM_CAN(CDC_MRW_W))
cdi->exit = cdrom_mrw_exit;
if (cdi->disk)
cdi->cdda_method = CDDA_BPC_FULL;
else
cdi->cdda_method = CDDA_OLD;
WARN_ON(!cdo->generic_packet);
cd_dbg(CD_REG_UNREG, "drive \"/dev/%s\" registered\n", cdi->name);
mutex_lock(&cdrom_mutex);
list_add(&cdi->list, &cdrom_list);
mutex_unlock(&cdrom_mutex);
return 0;
}
void unregister_cdrom(struct cdrom_device_info *cdi)
{
cd_dbg(CD_OPEN, "entering unregister_cdrom\n");
mutex_lock(&cdrom_mutex);
list_del(&cdi->list);
mutex_unlock(&cdrom_mutex);
if (cdi->exit)
cdi->exit(cdi);
cd_dbg(CD_REG_UNREG, "drive \"/dev/%s\" unregistered\n", cdi->name);
}
int cdrom_get_media_event(struct cdrom_device_info *cdi,
struct media_event_desc *med)
{
struct packet_command cgc;
unsigned char buffer[8];
struct event_header *eh = (struct event_header *)buffer;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.cmd[0] = GPCMD_GET_EVENT_STATUS_NOTIFICATION;
cgc.cmd[1] = 1;
cgc.cmd[4] = 1 << 4;
cgc.cmd[8] = sizeof(buffer);
cgc.quiet = 1;
if (cdi->ops->generic_packet(cdi, &cgc))
return 1;
if (be16_to_cpu(eh->data_len) < sizeof(*med))
return 1;
if (eh->nea || eh->notification_class != 0x4)
return 1;
memcpy(med, &buffer[sizeof(*eh)], sizeof(*med));
return 0;
}
static int cdrom_get_random_writable(struct cdrom_device_info *cdi,
struct rwrt_feature_desc *rfd)
{
struct packet_command cgc;
char buffer[24];
int ret;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.cmd[0] = GPCMD_GET_CONFIGURATION;
cgc.cmd[3] = CDF_RWRT;
cgc.cmd[8] = sizeof(buffer);
cgc.quiet = 1;
if ((ret = cdi->ops->generic_packet(cdi, &cgc)))
return ret;
memcpy(rfd, &buffer[sizeof(struct feature_header)], sizeof (*rfd));
return 0;
}
static int cdrom_has_defect_mgt(struct cdrom_device_info *cdi)
{
struct packet_command cgc;
char buffer[16];
__be16 *feature_code;
int ret;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.cmd[0] = GPCMD_GET_CONFIGURATION;
cgc.cmd[3] = CDF_HWDM;
cgc.cmd[8] = sizeof(buffer);
cgc.quiet = 1;
if ((ret = cdi->ops->generic_packet(cdi, &cgc)))
return ret;
feature_code = (__be16 *) &buffer[sizeof(struct feature_header)];
if (be16_to_cpu(*feature_code) == CDF_HWDM)
return 0;
return 1;
}
static int cdrom_is_random_writable(struct cdrom_device_info *cdi, int *write)
{
struct rwrt_feature_desc rfd;
int ret;
*write = 0;
if ((ret = cdrom_get_random_writable(cdi, &rfd)))
return ret;
if (CDF_RWRT == be16_to_cpu(rfd.feature_code))
*write = 1;
return 0;
}
static int cdrom_media_erasable(struct cdrom_device_info *cdi)
{
disc_information di;
int ret;
ret = cdrom_get_disc_info(cdi, &di);
if (ret < 0 || ret < offsetof(typeof(di), n_first_track))
return -1;
return di.erasable;
}
static int cdrom_dvdram_open_write(struct cdrom_device_info *cdi)
{
int ret = cdrom_media_erasable(cdi);
if (!ret)
return 1;
return 0;
}
static int cdrom_mrw_open_write(struct cdrom_device_info *cdi)
{
disc_information di;
int ret;
if (cdrom_mrw_set_lba_space(cdi, MRW_LBA_DMA)) {
pr_err("failed setting lba address space\n");
return 1;
}
ret = cdrom_get_disc_info(cdi, &di);
if (ret < 0 || ret < offsetof(typeof(di),disc_type))
return 1;
if (!di.erasable)
return 1;
ret = 0;
pr_info("open: mrw_status '%s'\n", mrw_format_status[di.mrw_status]);
if (!di.mrw_status)
ret = 1;
else if (di.mrw_status == CDM_MRW_BGFORMAT_INACTIVE &&
mrw_format_restart)
ret = cdrom_mrw_bgformat(cdi, 1);
return ret;
}
static int mo_open_write(struct cdrom_device_info *cdi)
{
struct packet_command cgc;
char buffer[255];
int ret;
init_cdrom_command(&cgc, &buffer, 4, CGC_DATA_READ);
cgc.quiet = 1;
ret = cdrom_mode_sense(cdi, &cgc, GPMODE_ALL_PAGES, 0);
if (ret)
ret = cdrom_mode_sense(cdi, &cgc, GPMODE_VENDOR_PAGE, 0);
if (ret) {
cgc.buflen = 255;
ret = cdrom_mode_sense(cdi, &cgc, GPMODE_ALL_PAGES, 0);
}
if (ret)
return 0;
return buffer[3] & 0x80;
}
static int cdrom_ram_open_write(struct cdrom_device_info *cdi)
{
struct rwrt_feature_desc rfd;
int ret;
if ((ret = cdrom_has_defect_mgt(cdi)))
return ret;
if ((ret = cdrom_get_random_writable(cdi, &rfd)))
return ret;
else if (CDF_RWRT == be16_to_cpu(rfd.feature_code))
ret = !rfd.curr;
cd_dbg(CD_OPEN, "can open for random write\n");
return ret;
}
static void cdrom_mmc3_profile(struct cdrom_device_info *cdi)
{
struct packet_command cgc;
char buffer[32];
int ret, mmc3_profile;
init_cdrom_command(&cgc, buffer, sizeof(buffer), CGC_DATA_READ);
cgc.cmd[0] = GPCMD_GET_CONFIGURATION;
cgc.cmd[1] = 0;
cgc.cmd[2] = cgc.cmd[3] = 0;
cgc.cmd[8] = sizeof(buffer);
cgc.quiet = 1;
if ((ret = cdi->ops->generic_packet(cdi, &cgc)))
mmc3_profile = 0xffff;
else
mmc3_profile = (buffer[6] << 8) | buffer[7];
cdi->mmc3_profile = mmc3_profile;
}
static int cdrom_is_dvd_rw(struct cdrom_device_info *cdi)
{
switch (cdi->mmc3_profile) {
case 0x12:
case 0x1A:
case 0x43:
return 0;
default:
return 1;
}
}
static int cdrom_open_write(struct cdrom_device_info *cdi)
{
int mrw, mrw_write, ram_write;
int ret = 1;
mrw = 0;
if (!cdrom_is_mrw(cdi, &mrw_write))
mrw = 1;
if (CDROM_CAN(CDC_MO_DRIVE))
ram_write = 1;
else
(void) cdrom_is_random_writable(cdi, &ram_write);
if (mrw)
cdi->mask &= ~CDC_MRW;
else
cdi->mask |= CDC_MRW;
if (mrw_write)
cdi->mask &= ~CDC_MRW_W;
else
cdi->mask |= CDC_MRW_W;
if (ram_write)
cdi->mask &= ~CDC_RAM;
else
cdi->mask |= CDC_RAM;
if (CDROM_CAN(CDC_MRW_W))
ret = cdrom_mrw_open_write(cdi);
else if (CDROM_CAN(CDC_DVD_RAM))
ret = cdrom_dvdram_open_write(cdi);
else if (CDROM_CAN(CDC_RAM) &&
!CDROM_CAN(CDC_CD_R|CDC_CD_RW|CDC_DVD|CDC_DVD_R|CDC_MRW|CDC_MO_DRIVE))
ret = cdrom_ram_open_write(cdi);
else if (CDROM_CAN(CDC_MO_DRIVE))
ret = mo_open_write(cdi);
else if (!cdrom_is_dvd_rw(cdi))
ret = 0;
return ret;
}
static void cdrom_dvd_rw_close_write(struct cdrom_device_info *cdi)
{
struct packet_command cgc;
if (cdi->mmc3_profile != 0x1a) {
cd_dbg(CD_CLOSE, "%s: No DVD+RW\n", cdi->name);
return;
}
if (!cdi->media_written) {
cd_dbg(CD_CLOSE, "%s: DVD+RW media clean\n", cdi->name);
return;
}
pr_info("%s: dirty DVD+RW media, \"finalizing\"\n", cdi->name);
init_cdrom_command(&cgc, NULL, 0, CGC_DATA_NONE);
cgc.cmd[0] = GPCMD_FLUSH_CACHE;
cgc.timeout = 30*HZ;
cdi->ops->generic_packet(cdi, &cgc);
init_cdrom_command(&cgc, NULL, 0, CGC_DATA_NONE);
cgc.cmd[0] = GPCMD_CLOSE_TRACK;
cgc.timeout = 3000*HZ;
cgc.quiet = 1;
cdi->ops->generic_packet(cdi, &cgc);
init_cdrom_command(&cgc, NULL, 0, CGC_DATA_NONE);
cgc.cmd[0] = GPCMD_CLOSE_TRACK;
cgc.cmd[2] = 2;
cgc.quiet = 1;
cgc.timeout = 3000*HZ;
cdi->ops->generic_packet(cdi, &cgc);
cdi->media_written = 0;
}
static int cdrom_close_write(struct cdrom_device_info *cdi)
{
#if 0
return cdrom_flush_cache(cdi);
#else
return 0;
#endif
}
static void cdrom_count_tracks(struct cdrom_device_info *cdi, tracktype *tracks)
{
struct cdrom_tochdr header;
struct cdrom_tocentry entry;
int ret, i;
tracks->data = 0;
tracks->audio = 0;
tracks->cdi = 0;
tracks->xa = 0;
tracks->error = 0;
cd_dbg(CD_COUNT_TRACKS, "entering cdrom_count_tracks\n");
ret = cdi->ops->audio_ioctl(cdi, CDROMREADTOCHDR, &header);
if (ret) {
if (ret == -ENOMEDIUM)
tracks->error = CDS_NO_DISC;
else
tracks->error = CDS_NO_INFO;
return;
}
entry.cdte_format = CDROM_MSF;
for (i = header.cdth_trk0; i <= header.cdth_trk1; i++) {
entry.cdte_track = i;
if (cdi->ops->audio_ioctl(cdi, CDROMREADTOCENTRY, &entry)) {
tracks->error = CDS_NO_INFO;
return;
}
if (entry.cdte_ctrl & CDROM_DATA_TRACK) {
if (entry.cdte_format == 0x10)
tracks->cdi++;
else if (entry.cdte_format == 0x20)
tracks->xa++;
else
tracks->data++;
} else {
tracks->audio++;
}
cd_dbg(CD_COUNT_TRACKS, "track %d: format=%d, ctrl=%d\n",
i, entry.cdte_format, entry.cdte_ctrl);
}
cd_dbg(CD_COUNT_TRACKS, "disc has %d tracks: %d=audio %d=data %d=Cd-I %d=XA\n",
header.cdth_trk1, tracks->audio, tracks->data,
tracks->cdi, tracks->xa);
}
static
int open_for_data(struct cdrom_device_info *cdi)
{
int ret;
const struct cdrom_device_ops *cdo = cdi->ops;
tracktype tracks;
cd_dbg(CD_OPEN, "entering open_for_data\n");
if (cdo->drive_status != NULL) {
ret = cdo->drive_status(cdi, CDSL_CURRENT);
cd_dbg(CD_OPEN, "drive_status=%d\n", ret);
if (ret == CDS_TRAY_OPEN) {
cd_dbg(CD_OPEN, "the tray is open...\n");
if (CDROM_CAN(CDC_CLOSE_TRAY) &&
cdi->options & CDO_AUTO_CLOSE) {
cd_dbg(CD_OPEN, "trying to close the tray\n");
ret=cdo->tray_move(cdi,0);
if (ret) {
cd_dbg(CD_OPEN, "bummer. tried to close the tray but failed.\n");
ret=-ENOMEDIUM;
goto clean_up_and_return;
}
} else {
cd_dbg(CD_OPEN, "bummer. this drive can't close the tray.\n");
ret=-ENOMEDIUM;
goto clean_up_and_return;
}
ret = cdo->drive_status(cdi, CDSL_CURRENT);
if ((ret == CDS_NO_DISC) || (ret==CDS_TRAY_OPEN)) {
cd_dbg(CD_OPEN, "bummer. the tray is still not closed.\n");
cd_dbg(CD_OPEN, "tray might not contain a medium\n");
ret=-ENOMEDIUM;
goto clean_up_and_return;
}
cd_dbg(CD_OPEN, "the tray is now closed\n");
}
ret = cdo->drive_status(cdi, CDSL_CURRENT);
if (ret!=CDS_DISC_OK) {
ret = -ENOMEDIUM;
goto clean_up_and_return;
}
}
cdrom_count_tracks(cdi, &tracks);
if (tracks.error == CDS_NO_DISC) {
cd_dbg(CD_OPEN, "bummer. no disc.\n");
ret=-ENOMEDIUM;
goto clean_up_and_return;
}
if (tracks.data==0) {
if (cdi->options & CDO_CHECK_TYPE) {
cd_dbg(CD_OPEN, "bummer. wrong media type.\n");
cd_dbg(CD_WARNING, "pid %d must open device O_NONBLOCK!\n",
(unsigned int)task_pid_nr(current));
ret=-EMEDIUMTYPE;
goto clean_up_and_return;
}
else {
cd_dbg(CD_OPEN, "wrong media type, but CDO_CHECK_TYPE not set\n");
}
}
cd_dbg(CD_OPEN, "all seems well, opening the devicen");
ret = cdo->open(cdi, 0);
cd_dbg(CD_OPEN, "opening the device gave me %d\n", ret);
if (ret) {
cd_dbg(CD_OPEN, "open device failed\n");
goto clean_up_and_return;
}
if (CDROM_CAN(CDC_LOCK) && (cdi->options & CDO_LOCK)) {
cdo->lock_door(cdi, 1);
cd_dbg(CD_OPEN, "door locked\n");
}
cd_dbg(CD_OPEN, "device opened successfully\n");
return ret;
clean_up_and_return:
cd_dbg(CD_OPEN, "open failed\n");
if (CDROM_CAN(CDC_LOCK) && cdi->options & CDO_LOCK) {
cdo->lock_door(cdi, 0);
cd_dbg(CD_OPEN, "door unlocked\n");
}
return ret;
}
int cdrom_open(struct cdrom_device_info *cdi, struct block_device *bdev,
fmode_t mode)
{
int ret;
cd_dbg(CD_OPEN, "entering cdrom_open\n");
check_disk_change(bdev);
cdi->use_count++;
if ((mode & FMODE_NDELAY) && (cdi->options & CDO_USE_FFLAGS)) {
ret = cdi->ops->open(cdi, 1);
} else {
ret = open_for_data(cdi);
if (ret)
goto err;
cdrom_mmc3_profile(cdi);
if (mode & FMODE_WRITE) {
ret = -EROFS;
if (cdrom_open_write(cdi))
goto err_release;
if (!CDROM_CAN(CDC_RAM))
goto err_release;
ret = 0;
cdi->media_written = 0;
}
}
if (ret)
goto err;
cd_dbg(CD_OPEN, "Use count for \"/dev/%s\" now %d\n",
cdi->name, cdi->use_count);
return 0;
err_release:
if (CDROM_CAN(CDC_LOCK) && cdi->options & CDO_LOCK) {
cdi->ops->lock_door(cdi, 0);
cd_dbg(CD_OPEN, "door unlocked\n");
}
cdi->ops->release(cdi);
err:
cdi->use_count--;
return ret;
}
static int check_for_audio_disc(struct cdrom_device_info *cdi,
const struct cdrom_device_ops *cdo)
{
int ret;
tracktype tracks;
cd_dbg(CD_OPEN, "entering check_for_audio_disc\n");
if (!(cdi->options & CDO_CHECK_TYPE))
return 0;
if (cdo->drive_status != NULL) {
ret = cdo->drive_status(cdi, CDSL_CURRENT);
cd_dbg(CD_OPEN, "drive_status=%d\n", ret);
if (ret == CDS_TRAY_OPEN) {
cd_dbg(CD_OPEN, "the tray is open...\n");
if (CDROM_CAN(CDC_CLOSE_TRAY) &&
cdi->options & CDO_AUTO_CLOSE) {
cd_dbg(CD_OPEN, "trying to close the tray\n");
ret=cdo->tray_move(cdi,0);
if (ret) {
cd_dbg(CD_OPEN, "bummer. tried to close tray but failed.\n");
return -ENOMEDIUM;
}
} else {
cd_dbg(CD_OPEN, "bummer. this driver can't close the tray.\n");
return -ENOMEDIUM;
}
ret = cdo->drive_status(cdi, CDSL_CURRENT);
if ((ret == CDS_NO_DISC) || (ret==CDS_TRAY_OPEN)) {
cd_dbg(CD_OPEN, "bummer. the tray is still not closed.\n");
return -ENOMEDIUM;
}
if (ret!=CDS_DISC_OK) {
cd_dbg(CD_OPEN, "bummer. disc isn't ready.\n");
return -EIO;
}
cd_dbg(CD_OPEN, "the tray is now closed\n");
}
}
cdrom_count_tracks(cdi, &tracks);
if (tracks.error)
return(tracks.error);
if (tracks.audio==0)
return -EMEDIUMTYPE;
return 0;
}
void cdrom_release(struct cdrom_device_info *cdi, fmode_t mode)
{
const struct cdrom_device_ops *cdo = cdi->ops;
int opened_for_data;
cd_dbg(CD_CLOSE, "entering cdrom_release\n");
if (cdi->use_count > 0)
cdi->use_count--;
if (cdi->use_count == 0) {
cd_dbg(CD_CLOSE, "Use count for \"/dev/%s\" now zero\n",
cdi->name);
cdrom_dvd_rw_close_write(cdi);
if ((cdo->capability & CDC_LOCK) && !cdi->keeplocked) {
cd_dbg(CD_CLOSE, "Unlocking door!\n");
cdo->lock_door(cdi, 0);
}
}
opened_for_data = !(cdi->options & CDO_USE_FFLAGS) ||
!(mode & FMODE_NDELAY);
if (CDROM_CAN(CDC_RAM) && !cdi->use_count && cdi->for_data)
cdrom_close_write(cdi);
cdo->release(cdi);
if (cdi->use_count == 0) {
if (opened_for_data &&
cdi->options & CDO_AUTO_EJECT && CDROM_CAN(CDC_OPEN_TRAY))
cdo->tray_move(cdi, 1);
}
}
static int cdrom_read_mech_status(struct cdrom_device_info *cdi,
struct cdrom_changer_info *buf)
{
struct packet_command cgc;
const struct cdrom_device_ops *cdo = cdi->ops;
int length;
if (cdi->sanyo_slot) {
buf->hdr.nslots = 3;
buf->hdr.curslot = cdi->sanyo_slot == 3 ? 0 : cdi->sanyo_slot;
for (length = 0; length < 3; length++) {
buf->slots[length].disc_present = 1;
buf->slots[length].change = 0;
}
return 0;
}
length = sizeof(struct cdrom_mechstat_header) +
cdi->capacity * sizeof(struct cdrom_slot);
init_cdrom_command(&cgc, buf, length, CGC_DATA_READ);
cgc.cmd[0] = GPCMD_MECHANISM_STATUS;
cgc.cmd[8] = (length >> 8) & 0xff;
cgc.cmd[9] = length & 0xff;
return cdo->generic_packet(cdi, &cgc);
}
static int cdrom_slot_status(struct cdrom_device_info *cdi, int slot)
{
struct cdrom_changer_info *info;
int ret;
cd_dbg(CD_CHANGER, "entering cdrom_slot_status()\n");
if (cdi->sanyo_slot)
return CDS_NO_INFO;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if ((ret = cdrom_read_mech_status(cdi, info)))
goto out_free;
if (info->slots[slot].disc_present)
ret = CDS_DISC_OK;
else
ret = CDS_NO_DISC;
out_free:
kfree(info);
return ret;
}
int cdrom_number_of_slots(struct cdrom_device_info *cdi)
{
int status;
int nslots = 1;
struct cdrom_changer_info *info;
cd_dbg(CD_CHANGER, "entering cdrom_number_of_slots()\n");
cdi->capacity = 0;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if ((status = cdrom_read_mech_status(cdi, info)) == 0)
nslots = info->hdr.nslots;
kfree(info);
return nslots;
}
static int cdrom_load_unload(struct cdrom_device_info *cdi, int slot)
{
struct packet_command cgc;
cd_dbg(CD_CHANGER, "entering cdrom_load_unload()\n");
if (cdi->sanyo_slot && slot < 0)
return 0;
init_cdrom_command(&cgc, NULL, 0, CGC_DATA_NONE);
cgc.cmd[0] = GPCMD_LOAD_UNLOAD;
cgc.cmd[4] = 2 + (slot >= 0);
cgc.cmd[8] = slot;
cgc.timeout = 60 * HZ;
if (cdi->sanyo_slot && -1 < slot) {
cgc.cmd[0] = GPCMD_TEST_UNIT_READY;
cgc.cmd[7] = slot;
cgc.cmd[4] = cgc.cmd[8] = 0;
cdi->sanyo_slot = slot ? slot : 3;
}
return cdi->ops->generic_packet(cdi, &cgc);
}
static int cdrom_select_disc(struct cdrom_device_info *cdi, int slot)
{
struct cdrom_changer_info *info;
int curslot;
int ret;
cd_dbg(CD_CHANGER, "entering cdrom_select_disc()\n");
if (!CDROM_CAN(CDC_SELECT_DISC))
return -EDRIVE_CANT_DO_THIS;
if (cdi->ops->check_events)
cdi->ops->check_events(cdi, 0, slot);
else
cdi->ops->media_changed(cdi, slot);
if (slot == CDSL_NONE) {
cdi->mc_flags = 0x3;
return cdrom_load_unload(cdi, -1);
}
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if ((ret = cdrom_read_mech_status(cdi, info))) {
kfree(info);
return ret;
}
curslot = info->hdr.curslot;
kfree(info);
if (cdi->use_count > 1 || cdi->keeplocked) {
if (slot == CDSL_CURRENT) {
return curslot;
} else {
return -EBUSY;
}
}
if (slot == CDSL_CURRENT)
slot = curslot;
cdi->mc_flags = 0x3;
if ((ret = cdrom_load_unload(cdi, slot)))
return ret;
return slot;
}
static void cdrom_update_events(struct cdrom_device_info *cdi,
unsigned int clearing)
{
unsigned int events;
events = cdi->ops->check_events(cdi, clearing, CDSL_CURRENT);
cdi->vfs_events |= events;
cdi->ioctl_events |= events;
}
unsigned int cdrom_check_events(struct cdrom_device_info *cdi,
unsigned int clearing)
{
unsigned int events;
cdrom_update_events(cdi, clearing);
events = cdi->vfs_events;
cdi->vfs_events = 0;
return events;
}
static
int media_changed(struct cdrom_device_info *cdi, int queue)
{
unsigned int mask = (1 << (queue & 1));
int ret = !!(cdi->mc_flags & mask);
bool changed;
if (!CDROM_CAN(CDC_MEDIA_CHANGED))
return ret;
if (cdi->ops->check_events) {
BUG_ON(!queue);
cdrom_update_events(cdi, DISK_EVENT_MEDIA_CHANGE);
changed = cdi->ioctl_events & DISK_EVENT_MEDIA_CHANGE;
cdi->ioctl_events = 0;
} else
changed = cdi->ops->media_changed(cdi, CDSL_CURRENT);
if (changed) {
cdi->mc_flags = 0x3;
ret |= 1;
cdi->media_written = 0;
}
cdi->mc_flags &= ~mask;
return ret;
}
int cdrom_media_changed(struct cdrom_device_info *cdi)
{
if (cdi == NULL || cdi->ops->media_changed == NULL)
return 0;
if (!CDROM_CAN(CDC_MEDIA_CHANGED))
return 0;
return media_changed(cdi, 0);
}
static
void sanitize_format(union cdrom_addr *addr,
u_char * curr, u_char requested)
{
if (*curr == requested)
return;
if (requested == CDROM_LBA) {
addr->lba = (int) addr->msf.frame +
75 * (addr->msf.second - 2 + 60 * addr->msf.minute);
} else {
int lba = addr->lba;
addr->msf.frame = lba % 75;
lba /= 75;
lba += 2;
addr->msf.second = lba % 60;
addr->msf.minute = lba / 60;
}
*curr = requested;
}
void init_cdrom_command(struct packet_command *cgc, void *buf, int len,
int type)
{
memset(cgc, 0, sizeof(struct packet_command));
if (buf)
memset(buf, 0, len);
cgc->buffer = (char *) buf;
cgc->buflen = len;
cgc->data_direction = type;
cgc->timeout = CDROM_DEF_TIMEOUT;
}
static void setup_report_key(struct packet_command *cgc, unsigned agid, unsigned type)
{
cgc->cmd[0] = GPCMD_REPORT_KEY;
cgc->cmd[10] = type | (agid << 6);
switch (type) {
case 0: case 8: case 5: {
cgc->buflen = 8;
break;
}
case 1: {
cgc->buflen = 16;
break;
}
case 2: case 4: {
cgc->buflen = 12;
break;
}
}
cgc->cmd[9] = cgc->buflen;
cgc->data_direction = CGC_DATA_READ;
}
static void setup_send_key(struct packet_command *cgc, unsigned agid, unsigned type)
{
cgc->cmd[0] = GPCMD_SEND_KEY;
cgc->cmd[10] = type | (agid << 6);
switch (type) {
case 1: {
cgc->buflen = 16;
break;
}
case 3: {
cgc->buflen = 12;
break;
}
case 6: {
cgc->buflen = 8;
break;
}
}
cgc->cmd[9] = cgc->buflen;
cgc->data_direction = CGC_DATA_WRITE;
}
static int dvd_do_auth(struct cdrom_device_info *cdi, dvd_authinfo *ai)
{
int ret;
u_char buf[20];
struct packet_command cgc;
const struct cdrom_device_ops *cdo = cdi->ops;
rpc_state_t rpc_state;
memset(buf, 0, sizeof(buf));
init_cdrom_command(&cgc, buf, 0, CGC_DATA_READ);
switch (ai->type) {
case DVD_LU_SEND_AGID:
cd_dbg(CD_DVD, "entering DVD_LU_SEND_AGID\n");
cgc.quiet = 1;
setup_report_key(&cgc, ai->lsa.agid, 0);
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
ai->lsa.agid = buf[7] >> 6;
break;
case DVD_LU_SEND_KEY1:
cd_dbg(CD_DVD, "entering DVD_LU_SEND_KEY1\n");
setup_report_key(&cgc, ai->lsk.agid, 2);
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
copy_key(ai->lsk.key, &buf[4]);
break;
case DVD_LU_SEND_CHALLENGE:
cd_dbg(CD_DVD, "entering DVD_LU_SEND_CHALLENGE\n");
setup_report_key(&cgc, ai->lsc.agid, 1);
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
copy_chal(ai->lsc.chal, &buf[4]);
break;
case DVD_LU_SEND_TITLE_KEY:
cd_dbg(CD_DVD, "entering DVD_LU_SEND_TITLE_KEY\n");
cgc.quiet = 1;
setup_report_key(&cgc, ai->lstk.agid, 4);
cgc.cmd[5] = ai->lstk.lba;
cgc.cmd[4] = ai->lstk.lba >> 8;
cgc.cmd[3] = ai->lstk.lba >> 16;
cgc.cmd[2] = ai->lstk.lba >> 24;
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
ai->lstk.cpm = (buf[4] >> 7) & 1;
ai->lstk.cp_sec = (buf[4] >> 6) & 1;
ai->lstk.cgms = (buf[4] >> 4) & 3;
copy_key(ai->lstk.title_key, &buf[5]);
break;
case DVD_LU_SEND_ASF:
cd_dbg(CD_DVD, "entering DVD_LU_SEND_ASF\n");
setup_report_key(&cgc, ai->lsasf.agid, 5);
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
ai->lsasf.asf = buf[7] & 1;
break;
case DVD_HOST_SEND_CHALLENGE:
cd_dbg(CD_DVD, "entering DVD_HOST_SEND_CHALLENGE\n");
setup_send_key(&cgc, ai->hsc.agid, 1);
buf[1] = 0xe;
copy_chal(&buf[4], ai->hsc.chal);
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
ai->type = DVD_LU_SEND_KEY1;
break;
case DVD_HOST_SEND_KEY2:
cd_dbg(CD_DVD, "entering DVD_HOST_SEND_KEY2\n");
setup_send_key(&cgc, ai->hsk.agid, 3);
buf[1] = 0xa;
copy_key(&buf[4], ai->hsk.key);
if ((ret = cdo->generic_packet(cdi, &cgc))) {
ai->type = DVD_AUTH_FAILURE;
return ret;
}
ai->type = DVD_AUTH_ESTABLISHED;
break;
case DVD_INVALIDATE_AGID:
cgc.quiet = 1;
cd_dbg(CD_DVD, "entering DVD_INVALIDATE_AGID\n");
setup_report_key(&cgc, ai->lsa.agid, 0x3f);
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
break;
case DVD_LU_SEND_RPC_STATE:
cd_dbg(CD_DVD, "entering DVD_LU_SEND_RPC_STATE\n");
setup_report_key(&cgc, 0, 8);
memset(&rpc_state, 0, sizeof(rpc_state_t));
cgc.buffer = (char *) &rpc_state;
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
ai->lrpcs.type = rpc_state.type_code;
ai->lrpcs.vra = rpc_state.vra;
ai->lrpcs.ucca = rpc_state.ucca;
ai->lrpcs.region_mask = rpc_state.region_mask;
ai->lrpcs.rpc_scheme = rpc_state.rpc_scheme;
break;
case DVD_HOST_SEND_RPC_STATE:
cd_dbg(CD_DVD, "entering DVD_HOST_SEND_RPC_STATE\n");
setup_send_key(&cgc, 0, 6);
buf[1] = 6;
buf[4] = ai->hrpcs.pdrc;
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
break;
default:
cd_dbg(CD_WARNING, "Invalid DVD key ioctl (%d)\n", ai->type);
return -ENOTTY;
}
return 0;
}
static int dvd_read_physical(struct cdrom_device_info *cdi, dvd_struct *s,
struct packet_command *cgc)
{
unsigned char buf[21], *base;
struct dvd_layer *layer;
const struct cdrom_device_ops *cdo = cdi->ops;
int ret, layer_num = s->physical.layer_num;
if (layer_num >= DVD_LAYERS)
return -EINVAL;
init_cdrom_command(cgc, buf, sizeof(buf), CGC_DATA_READ);
cgc->cmd[0] = GPCMD_READ_DVD_STRUCTURE;
cgc->cmd[6] = layer_num;
cgc->cmd[7] = s->type;
cgc->cmd[9] = cgc->buflen & 0xff;
cgc->quiet = 1;
ret = cdo->generic_packet(cdi, cgc);
if (ret)
return ret;
base = &buf[4];
layer = &s->physical.layer[layer_num];
memset(layer, 0, sizeof(*layer));
layer->book_version = base[0] & 0xf;
layer->book_type = base[0] >> 4;
layer->min_rate = base[1] & 0xf;
layer->disc_size = base[1] >> 4;
layer->layer_type = base[2] & 0xf;
layer->track_path = (base[2] >> 4) & 1;
layer->nlayers = (base[2] >> 5) & 3;
layer->track_density = base[3] & 0xf;
layer->linear_density = base[3] >> 4;
layer->start_sector = base[5] << 16 | base[6] << 8 | base[7];
layer->end_sector = base[9] << 16 | base[10] << 8 | base[11];
layer->end_sector_l0 = base[13] << 16 | base[14] << 8 | base[15];
layer->bca = base[16] >> 7;
return 0;
}
static int dvd_read_copyright(struct cdrom_device_info *cdi, dvd_struct *s,
struct packet_command *cgc)
{
int ret;
u_char buf[8];
const struct cdrom_device_ops *cdo = cdi->ops;
init_cdrom_command(cgc, buf, sizeof(buf), CGC_DATA_READ);
cgc->cmd[0] = GPCMD_READ_DVD_STRUCTURE;
cgc->cmd[6] = s->copyright.layer_num;
cgc->cmd[7] = s->type;
cgc->cmd[8] = cgc->buflen >> 8;
cgc->cmd[9] = cgc->buflen & 0xff;
ret = cdo->generic_packet(cdi, cgc);
if (ret)
return ret;
s->copyright.cpst = buf[4];
s->copyright.rmi = buf[5];
return 0;
}
static int dvd_read_disckey(struct cdrom_device_info *cdi, dvd_struct *s,
struct packet_command *cgc)
{
int ret, size;
u_char *buf;
const struct cdrom_device_ops *cdo = cdi->ops;
size = sizeof(s->disckey.value) + 4;
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
init_cdrom_command(cgc, buf, size, CGC_DATA_READ);
cgc->cmd[0] = GPCMD_READ_DVD_STRUCTURE;
cgc->cmd[7] = s->type;
cgc->cmd[8] = size >> 8;
cgc->cmd[9] = size & 0xff;
cgc->cmd[10] = s->disckey.agid << 6;
ret = cdo->generic_packet(cdi, cgc);
if (!ret)
memcpy(s->disckey.value, &buf[4], sizeof(s->disckey.value));
kfree(buf);
return ret;
}
static int dvd_read_bca(struct cdrom_device_info *cdi, dvd_struct *s,
struct packet_command *cgc)
{
int ret, size = 4 + 188;
u_char *buf;
const struct cdrom_device_ops *cdo = cdi->ops;
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
init_cdrom_command(cgc, buf, size, CGC_DATA_READ);
cgc->cmd[0] = GPCMD_READ_DVD_STRUCTURE;
cgc->cmd[7] = s->type;
cgc->cmd[9] = cgc->buflen & 0xff;
ret = cdo->generic_packet(cdi, cgc);
if (ret)
goto out;
s->bca.len = buf[0] << 8 | buf[1];
if (s->bca.len < 12 || s->bca.len > 188) {
cd_dbg(CD_WARNING, "Received invalid BCA length (%d)\n",
s->bca.len);
ret = -EIO;
goto out;
}
memcpy(s->bca.value, &buf[4], s->bca.len);
ret = 0;
out:
kfree(buf);
return ret;
}
static int dvd_read_manufact(struct cdrom_device_info *cdi, dvd_struct *s,
struct packet_command *cgc)
{
int ret = 0, size;
u_char *buf;
const struct cdrom_device_ops *cdo = cdi->ops;
size = sizeof(s->manufact.value) + 4;
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
init_cdrom_command(cgc, buf, size, CGC_DATA_READ);
cgc->cmd[0] = GPCMD_READ_DVD_STRUCTURE;
cgc->cmd[7] = s->type;
cgc->cmd[8] = size >> 8;
cgc->cmd[9] = size & 0xff;
ret = cdo->generic_packet(cdi, cgc);
if (ret)
goto out;
s->manufact.len = buf[0] << 8 | buf[1];
if (s->manufact.len < 0) {
cd_dbg(CD_WARNING, "Received invalid manufacture info length (%d)\n",
s->manufact.len);
ret = -EIO;
} else {
if (s->manufact.len > 2048) {
cd_dbg(CD_WARNING, "Received invalid manufacture info length (%d): truncating to 2048\n",
s->manufact.len);
s->manufact.len = 2048;
}
memcpy(s->manufact.value, &buf[4], s->manufact.len);
}
out:
kfree(buf);
return ret;
}
static int dvd_read_struct(struct cdrom_device_info *cdi, dvd_struct *s,
struct packet_command *cgc)
{
switch (s->type) {
case DVD_STRUCT_PHYSICAL:
return dvd_read_physical(cdi, s, cgc);
case DVD_STRUCT_COPYRIGHT:
return dvd_read_copyright(cdi, s, cgc);
case DVD_STRUCT_DISCKEY:
return dvd_read_disckey(cdi, s, cgc);
case DVD_STRUCT_BCA:
return dvd_read_bca(cdi, s, cgc);
case DVD_STRUCT_MANUFACT:
return dvd_read_manufact(cdi, s, cgc);
default:
cd_dbg(CD_WARNING, ": Invalid DVD structure read requested (%d)\n",
s->type);
return -EINVAL;
}
}
int cdrom_mode_sense(struct cdrom_device_info *cdi,
struct packet_command *cgc,
int page_code, int page_control)
{
const struct cdrom_device_ops *cdo = cdi->ops;
memset(cgc->cmd, 0, sizeof(cgc->cmd));
cgc->cmd[0] = GPCMD_MODE_SENSE_10;
cgc->cmd[2] = page_code | (page_control << 6);
cgc->cmd[7] = cgc->buflen >> 8;
cgc->cmd[8] = cgc->buflen & 0xff;
cgc->data_direction = CGC_DATA_READ;
return cdo->generic_packet(cdi, cgc);
}
int cdrom_mode_select(struct cdrom_device_info *cdi,
struct packet_command *cgc)
{
const struct cdrom_device_ops *cdo = cdi->ops;
memset(cgc->cmd, 0, sizeof(cgc->cmd));
memset(cgc->buffer, 0, 2);
cgc->cmd[0] = GPCMD_MODE_SELECT_10;
cgc->cmd[1] = 0x10;
cgc->cmd[7] = cgc->buflen >> 8;
cgc->cmd[8] = cgc->buflen & 0xff;
cgc->data_direction = CGC_DATA_WRITE;
return cdo->generic_packet(cdi, cgc);
}
static int cdrom_read_subchannel(struct cdrom_device_info *cdi,
struct cdrom_subchnl *subchnl, int mcn)
{
const struct cdrom_device_ops *cdo = cdi->ops;
struct packet_command cgc;
char buffer[32];
int ret;
init_cdrom_command(&cgc, buffer, 16, CGC_DATA_READ);
cgc.cmd[0] = GPCMD_READ_SUBCHANNEL;
cgc.cmd[1] = subchnl->cdsc_format;
cgc.cmd[2] = 0x40;
cgc.cmd[3] = mcn ? 2 : 1;
cgc.cmd[8] = 16;
if ((ret = cdo->generic_packet(cdi, &cgc)))
return ret;
subchnl->cdsc_audiostatus = cgc.buffer[1];
subchnl->cdsc_ctrl = cgc.buffer[5] & 0xf;
subchnl->cdsc_trk = cgc.buffer[6];
subchnl->cdsc_ind = cgc.buffer[7];
if (subchnl->cdsc_format == CDROM_LBA) {
subchnl->cdsc_absaddr.lba = ((cgc.buffer[8] << 24) |
(cgc.buffer[9] << 16) |
(cgc.buffer[10] << 8) |
(cgc.buffer[11]));
subchnl->cdsc_reladdr.lba = ((cgc.buffer[12] << 24) |
(cgc.buffer[13] << 16) |
(cgc.buffer[14] << 8) |
(cgc.buffer[15]));
} else {
subchnl->cdsc_reladdr.msf.minute = cgc.buffer[13];
subchnl->cdsc_reladdr.msf.second = cgc.buffer[14];
subchnl->cdsc_reladdr.msf.frame = cgc.buffer[15];
subchnl->cdsc_absaddr.msf.minute = cgc.buffer[9];
subchnl->cdsc_absaddr.msf.second = cgc.buffer[10];
subchnl->cdsc_absaddr.msf.frame = cgc.buffer[11];
}
return 0;
}
static int cdrom_read_cd(struct cdrom_device_info *cdi,
struct packet_command *cgc, int lba,
int blocksize, int nblocks)
{
const struct cdrom_device_ops *cdo = cdi->ops;
memset(&cgc->cmd, 0, sizeof(cgc->cmd));
cgc->cmd[0] = GPCMD_READ_10;
cgc->cmd[2] = (lba >> 24) & 0xff;
cgc->cmd[3] = (lba >> 16) & 0xff;
cgc->cmd[4] = (lba >> 8) & 0xff;
cgc->cmd[5] = lba & 0xff;
cgc->cmd[6] = (nblocks >> 16) & 0xff;
cgc->cmd[7] = (nblocks >> 8) & 0xff;
cgc->cmd[8] = nblocks & 0xff;
cgc->buflen = blocksize * nblocks;
return cdo->generic_packet(cdi, cgc);
}
static int cdrom_read_block(struct cdrom_device_info *cdi,
struct packet_command *cgc,
int lba, int nblocks, int format, int blksize)
{
const struct cdrom_device_ops *cdo = cdi->ops;
memset(&cgc->cmd, 0, sizeof(cgc->cmd));
cgc->cmd[0] = GPCMD_READ_CD;
cgc->cmd[1] = format << 2;
cgc->cmd[2] = (lba >> 24) & 0xff;
cgc->cmd[3] = (lba >> 16) & 0xff;
cgc->cmd[4] = (lba >> 8) & 0xff;
cgc->cmd[5] = lba & 0xff;
cgc->cmd[6] = (nblocks >> 16) & 0xff;
cgc->cmd[7] = (nblocks >> 8) & 0xff;
cgc->cmd[8] = nblocks & 0xff;
cgc->buflen = blksize * nblocks;
switch (blksize) {
case CD_FRAMESIZE_RAW0 : cgc->cmd[9] = 0x58; break;
case CD_FRAMESIZE_RAW1 : cgc->cmd[9] = 0x78; break;
case CD_FRAMESIZE_RAW : cgc->cmd[9] = 0xf8; break;
default : cgc->cmd[9] = 0x10;
}
return cdo->generic_packet(cdi, cgc);
}
static int cdrom_read_cdda_old(struct cdrom_device_info *cdi, __u8 __user *ubuf,
int lba, int nframes)
{
struct packet_command cgc;
int ret = 0;
int nr;
cdi->last_sense = 0;
memset(&cgc, 0, sizeof(cgc));
nr = nframes;
do {
cgc.buffer = kmalloc(CD_FRAMESIZE_RAW * nr, GFP_KERNEL);
if (cgc.buffer)
break;
nr >>= 1;
} while (nr);
if (!nr)
return -ENOMEM;
cgc.data_direction = CGC_DATA_READ;
while (nframes > 0) {
if (nr > nframes)
nr = nframes;
ret = cdrom_read_block(cdi, &cgc, lba, nr, 1, CD_FRAMESIZE_RAW);
if (ret)
break;
if (copy_to_user(ubuf, cgc.buffer, CD_FRAMESIZE_RAW * nr)) {
ret = -EFAULT;
break;
}
ubuf += CD_FRAMESIZE_RAW * nr;
nframes -= nr;
lba += nr;
}
kfree(cgc.buffer);
return ret;
}
static int cdrom_read_cdda_bpc(struct cdrom_device_info *cdi, __u8 __user *ubuf,
int lba, int nframes)
{
struct request_queue *q = cdi->disk->queue;
struct request *rq;
struct scsi_request *req;
struct bio *bio;
unsigned int len;
int nr, ret = 0;
if (!q)
return -ENXIO;
cdi->last_sense = 0;
while (nframes) {
nr = nframes;
if (cdi->cdda_method == CDDA_BPC_SINGLE)
nr = 1;
if (nr * CD_FRAMESIZE_RAW > (queue_max_sectors(q) << 9))
nr = (queue_max_sectors(q) << 9) / CD_FRAMESIZE_RAW;
len = nr * CD_FRAMESIZE_RAW;
rq = blk_get_request(q, REQ_OP_SCSI_IN, GFP_KERNEL);
if (IS_ERR(rq)) {
ret = PTR_ERR(rq);
break;
}
req = scsi_req(rq);
scsi_req_init(rq);
ret = blk_rq_map_user(q, rq, NULL, ubuf, len, GFP_KERNEL);
if (ret) {
blk_put_request(rq);
break;
}
req->cmd[0] = GPCMD_READ_CD;
req->cmd[1] = 1 << 2;
req->cmd[2] = (lba >> 24) & 0xff;
req->cmd[3] = (lba >> 16) & 0xff;
req->cmd[4] = (lba >> 8) & 0xff;
req->cmd[5] = lba & 0xff;
req->cmd[6] = (nr >> 16) & 0xff;
req->cmd[7] = (nr >> 8) & 0xff;
req->cmd[8] = nr & 0xff;
req->cmd[9] = 0xf8;
req->cmd_len = 12;
rq->timeout = 60 * HZ;
bio = rq->bio;
blk_execute_rq(q, cdi->disk, rq, 0);
if (scsi_req(rq)->result) {
struct request_sense *s = req->sense;
ret = -EIO;
cdi->last_sense = s->sense_key;
}
if (blk_rq_unmap_user(bio))
ret = -EFAULT;
blk_put_request(rq);
if (ret)
break;
nframes -= nr;
lba += nr;
ubuf += len;
}
return ret;
}
static int cdrom_read_cdda(struct cdrom_device_info *cdi, __u8 __user *ubuf,
int lba, int nframes)
{
int ret;
if (cdi->cdda_method == CDDA_OLD)
return cdrom_read_cdda_old(cdi, ubuf, lba, nframes);
retry:
ret = cdrom_read_cdda_bpc(cdi, ubuf, lba, nframes);
if (!ret || ret != -EIO)
return ret;
if (cdi->cdda_method == CDDA_BPC_FULL && nframes > 1) {
pr_info("dropping to single frame dma\n");
cdi->cdda_method = CDDA_BPC_SINGLE;
goto retry;
}
if (cdi->last_sense != 0x04 && cdi->last_sense != 0x0b)
return ret;
pr_info("dropping to old style cdda (sense=%x)\n", cdi->last_sense);
cdi->cdda_method = CDDA_OLD;
return cdrom_read_cdda_old(cdi, ubuf, lba, nframes);
}
static int cdrom_ioctl_multisession(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_multisession ms_info;
u8 requested_format;
int ret;
cd_dbg(CD_DO_IOCTL, "entering CDROMMULTISESSION\n");
if (!(cdi->ops->capability & CDC_MULTI_SESSION))
return -ENOSYS;
if (copy_from_user(&ms_info, argp, sizeof(ms_info)))
return -EFAULT;
requested_format = ms_info.addr_format;
if (requested_format != CDROM_MSF && requested_format != CDROM_LBA)
return -EINVAL;
ms_info.addr_format = CDROM_LBA;
ret = cdi->ops->get_last_session(cdi, &ms_info);
if (ret)
return ret;
sanitize_format(&ms_info.addr, &ms_info.addr_format, requested_format);
if (copy_to_user(argp, &ms_info, sizeof(ms_info)))
return -EFAULT;
cd_dbg(CD_DO_IOCTL, "CDROMMULTISESSION successful\n");
return 0;
}
static int cdrom_ioctl_eject(struct cdrom_device_info *cdi)
{
cd_dbg(CD_DO_IOCTL, "entering CDROMEJECT\n");
if (!CDROM_CAN(CDC_OPEN_TRAY))
return -ENOSYS;
if (cdi->use_count != 1 || cdi->keeplocked)
return -EBUSY;
if (CDROM_CAN(CDC_LOCK)) {
int ret = cdi->ops->lock_door(cdi, 0);
if (ret)
return ret;
}
return cdi->ops->tray_move(cdi, 1);
}
static int cdrom_ioctl_closetray(struct cdrom_device_info *cdi)
{
cd_dbg(CD_DO_IOCTL, "entering CDROMCLOSETRAY\n");
if (!CDROM_CAN(CDC_CLOSE_TRAY))
return -ENOSYS;
return cdi->ops->tray_move(cdi, 0);
}
static int cdrom_ioctl_eject_sw(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "entering CDROMEJECT_SW\n");
if (!CDROM_CAN(CDC_OPEN_TRAY))
return -ENOSYS;
if (cdi->keeplocked)
return -EBUSY;
cdi->options &= ~(CDO_AUTO_CLOSE | CDO_AUTO_EJECT);
if (arg)
cdi->options |= CDO_AUTO_CLOSE | CDO_AUTO_EJECT;
return 0;
}
static int cdrom_ioctl_media_changed(struct cdrom_device_info *cdi,
unsigned long arg)
{
struct cdrom_changer_info *info;
int ret;
cd_dbg(CD_DO_IOCTL, "entering CDROM_MEDIA_CHANGED\n");
if (!CDROM_CAN(CDC_MEDIA_CHANGED))
return -ENOSYS;
if (!CDROM_CAN(CDC_SELECT_DISC) || arg == CDSL_CURRENT)
return media_changed(cdi, 1);
if ((unsigned int)arg >= cdi->capacity)
return -EINVAL;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
ret = cdrom_read_mech_status(cdi, info);
if (!ret)
ret = info->slots[arg].change;
kfree(info);
return ret;
}
static int cdrom_ioctl_set_options(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_SET_OPTIONS\n");
switch (arg) {
case CDO_USE_FFLAGS:
case CDO_CHECK_TYPE:
break;
case CDO_LOCK:
if (!CDROM_CAN(CDC_LOCK))
return -ENOSYS;
break;
case 0:
return cdi->options;
default:
if (!CDROM_CAN(arg))
return -ENOSYS;
}
cdi->options |= (int) arg;
return cdi->options;
}
static int cdrom_ioctl_clear_options(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_CLEAR_OPTIONS\n");
cdi->options &= ~(int) arg;
return cdi->options;
}
static int cdrom_ioctl_select_speed(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_SELECT_SPEED\n");
if (!CDROM_CAN(CDC_SELECT_SPEED))
return -ENOSYS;
return cdi->ops->select_speed(cdi, arg);
}
static int cdrom_ioctl_select_disc(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_SELECT_DISC\n");
if (!CDROM_CAN(CDC_SELECT_DISC))
return -ENOSYS;
if (arg != CDSL_CURRENT && arg != CDSL_NONE) {
if ((int)arg >= cdi->capacity)
return -EINVAL;
}
if (cdi->ops->select_disc)
return cdi->ops->select_disc(cdi, arg);
cd_dbg(CD_CHANGER, "Using generic cdrom_select_disc()\n");
return cdrom_select_disc(cdi, arg);
}
static int cdrom_ioctl_reset(struct cdrom_device_info *cdi,
struct block_device *bdev)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_RESET\n");
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (!CDROM_CAN(CDC_RESET))
return -ENOSYS;
invalidate_bdev(bdev);
return cdi->ops->reset(cdi);
}
static int cdrom_ioctl_lock_door(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "%socking door\n", arg ? "L" : "Unl");
if (!CDROM_CAN(CDC_LOCK))
return -EDRIVE_CANT_DO_THIS;
cdi->keeplocked = arg ? 1 : 0;
if (cdi->use_count != 1 && !arg && !capable(CAP_SYS_ADMIN))
return -EBUSY;
return cdi->ops->lock_door(cdi, arg);
}
static int cdrom_ioctl_debug(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "%sabling debug\n", arg ? "En" : "Dis");
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
debug = arg ? 1 : 0;
return debug;
}
static int cdrom_ioctl_get_capability(struct cdrom_device_info *cdi)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_GET_CAPABILITY\n");
return (cdi->ops->capability & ~cdi->mask);
}
static int cdrom_ioctl_get_mcn(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_mcn mcn;
int ret;
cd_dbg(CD_DO_IOCTL, "entering CDROM_GET_MCN\n");
if (!(cdi->ops->capability & CDC_MCN))
return -ENOSYS;
ret = cdi->ops->get_mcn(cdi, &mcn);
if (ret)
return ret;
if (copy_to_user(argp, &mcn, sizeof(mcn)))
return -EFAULT;
cd_dbg(CD_DO_IOCTL, "CDROM_GET_MCN successful\n");
return 0;
}
static int cdrom_ioctl_drive_status(struct cdrom_device_info *cdi,
unsigned long arg)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_DRIVE_STATUS\n");
if (!(cdi->ops->capability & CDC_DRIVE_STATUS))
return -ENOSYS;
if (!CDROM_CAN(CDC_SELECT_DISC) ||
(arg == CDSL_CURRENT || arg == CDSL_NONE))
return cdi->ops->drive_status(cdi, CDSL_CURRENT);
if (((int)arg >= cdi->capacity))
return -EINVAL;
return cdrom_slot_status(cdi, arg);
}
static int cdrom_ioctl_disc_status(struct cdrom_device_info *cdi)
{
tracktype tracks;
cd_dbg(CD_DO_IOCTL, "entering CDROM_DISC_STATUS\n");
cdrom_count_tracks(cdi, &tracks);
if (tracks.error)
return tracks.error;
if (tracks.audio > 0) {
if (!tracks.data && !tracks.cdi && !tracks.xa)
return CDS_AUDIO;
else
return CDS_MIXED;
}
if (tracks.cdi > 0)
return CDS_XA_2_2;
if (tracks.xa > 0)
return CDS_XA_2_1;
if (tracks.data > 0)
return CDS_DATA_1;
cd_dbg(CD_WARNING, "This disc doesn't have any tracks I recognize!\n");
return CDS_NO_INFO;
}
static int cdrom_ioctl_changer_nslots(struct cdrom_device_info *cdi)
{
cd_dbg(CD_DO_IOCTL, "entering CDROM_CHANGER_NSLOTS\n");
return cdi->capacity;
}
static int cdrom_ioctl_get_subchnl(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_subchnl q;
u8 requested, back;
int ret;
if (copy_from_user(&q, argp, sizeof(q)))
return -EFAULT;
requested = q.cdsc_format;
if (requested != CDROM_MSF && requested != CDROM_LBA)
return -EINVAL;
q.cdsc_format = CDROM_MSF;
ret = cdi->ops->audio_ioctl(cdi, CDROMSUBCHNL, &q);
if (ret)
return ret;
back = q.cdsc_format;
sanitize_format(&q.cdsc_absaddr, &back, requested);
sanitize_format(&q.cdsc_reladdr, &q.cdsc_format, requested);
if (copy_to_user(argp, &q, sizeof(q)))
return -EFAULT;
return 0;
}
static int cdrom_ioctl_read_tochdr(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_tochdr header;
int ret;
if (copy_from_user(&header, argp, sizeof(header)))
return -EFAULT;
ret = cdi->ops->audio_ioctl(cdi, CDROMREADTOCHDR, &header);
if (ret)
return ret;
if (copy_to_user(argp, &header, sizeof(header)))
return -EFAULT;
return 0;
}
static int cdrom_ioctl_read_tocentry(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_tocentry entry;
u8 requested_format;
int ret;
if (copy_from_user(&entry, argp, sizeof(entry)))
return -EFAULT;
requested_format = entry.cdte_format;
if (requested_format != CDROM_MSF && requested_format != CDROM_LBA)
return -EINVAL;
entry.cdte_format = CDROM_MSF;
ret = cdi->ops->audio_ioctl(cdi, CDROMREADTOCENTRY, &entry);
if (ret)
return ret;
sanitize_format(&entry.cdte_addr, &entry.cdte_format, requested_format);
if (copy_to_user(argp, &entry, sizeof(entry)))
return -EFAULT;
return 0;
}
static int cdrom_ioctl_play_msf(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_msf msf;
cd_dbg(CD_DO_IOCTL, "entering CDROMPLAYMSF\n");
if (!CDROM_CAN(CDC_PLAY_AUDIO))
return -ENOSYS;
if (copy_from_user(&msf, argp, sizeof(msf)))
return -EFAULT;
return cdi->ops->audio_ioctl(cdi, CDROMPLAYMSF, &msf);
}
static int cdrom_ioctl_play_trkind(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_ti ti;
int ret;
cd_dbg(CD_DO_IOCTL, "entering CDROMPLAYTRKIND\n");
if (!CDROM_CAN(CDC_PLAY_AUDIO))
return -ENOSYS;
if (copy_from_user(&ti, argp, sizeof(ti)))
return -EFAULT;
ret = check_for_audio_disc(cdi, cdi->ops);
if (ret)
return ret;
return cdi->ops->audio_ioctl(cdi, CDROMPLAYTRKIND, &ti);
}
static int cdrom_ioctl_volctrl(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_volctrl volume;
cd_dbg(CD_DO_IOCTL, "entering CDROMVOLCTRL\n");
if (!CDROM_CAN(CDC_PLAY_AUDIO))
return -ENOSYS;
if (copy_from_user(&volume, argp, sizeof(volume)))
return -EFAULT;
return cdi->ops->audio_ioctl(cdi, CDROMVOLCTRL, &volume);
}
static int cdrom_ioctl_volread(struct cdrom_device_info *cdi,
void __user *argp)
{
struct cdrom_volctrl volume;
int ret;
cd_dbg(CD_DO_IOCTL, "entering CDROMVOLREAD\n");
if (!CDROM_CAN(CDC_PLAY_AUDIO))
return -ENOSYS;
ret = cdi->ops->audio_ioctl(cdi, CDROMVOLREAD, &volume);
if (ret)
return ret;
if (copy_to_user(argp, &volume, sizeof(volume)))
return -EFAULT;
return 0;
}
static int cdrom_ioctl_audioctl(struct cdrom_device_info *cdi,
unsigned int cmd)
{
int ret;
cd_dbg(CD_DO_IOCTL, "doing audio ioctl (start/stop/pause/resume)\n");
if (!CDROM_CAN(CDC_PLAY_AUDIO))
return -ENOSYS;
ret = check_for_audio_disc(cdi, cdi->ops);
if (ret)
return ret;
return cdi->ops->audio_ioctl(cdi, cmd, NULL);
}
static int cdrom_switch_blocksize(struct cdrom_device_info *cdi, int size)
{
const struct cdrom_device_ops *cdo = cdi->ops;
struct packet_command cgc;
struct modesel_head mh;
memset(&mh, 0, sizeof(mh));
mh.block_desc_length = 0x08;
mh.block_length_med = (size >> 8) & 0xff;
mh.block_length_lo = size & 0xff;
memset(&cgc, 0, sizeof(cgc));
cgc.cmd[0] = 0x15;
cgc.cmd[1] = 1 << 4;
cgc.cmd[4] = 12;
cgc.buflen = sizeof(mh);
cgc.buffer = (char *) &mh;
cgc.data_direction = CGC_DATA_WRITE;
mh.block_desc_length = 0x08;
mh.block_length_med = (size >> 8) & 0xff;
mh.block_length_lo = size & 0xff;
return cdo->generic_packet(cdi, &cgc);
}
static int cdrom_get_track_info(struct cdrom_device_info *cdi,
__u16 track, __u8 type, track_information *ti)
{
const struct cdrom_device_ops *cdo = cdi->ops;
struct packet_command cgc;
int ret, buflen;
init_cdrom_command(&cgc, ti, 8, CGC_DATA_READ);
cgc.cmd[0] = GPCMD_READ_TRACK_RZONE_INFO;
cgc.cmd[1] = type & 3;
cgc.cmd[4] = (track & 0xff00) >> 8;
cgc.cmd[5] = track & 0xff;
cgc.cmd[8] = 8;
cgc.quiet = 1;
ret = cdo->generic_packet(cdi, &cgc);
if (ret)
return ret;
buflen = be16_to_cpu(ti->track_information_length) +
sizeof(ti->track_information_length);
if (buflen > sizeof(track_information))
buflen = sizeof(track_information);
cgc.cmd[8] = cgc.buflen = buflen;
ret = cdo->generic_packet(cdi, &cgc);
if (ret)
return ret;
return buflen;
}
int cdrom_get_last_written(struct cdrom_device_info *cdi, long *last_written)
{
struct cdrom_tocentry toc;
disc_information di;
track_information ti;
__u32 last_track;
int ret = -1, ti_size;
if (!CDROM_CAN(CDC_GENERIC_PACKET))
goto use_toc;
ret = cdrom_get_disc_info(cdi, &di);
if (ret < (int)(offsetof(typeof(di), last_track_lsb)
+ sizeof(di.last_track_lsb)))
goto use_toc;
last_track = (di.last_track_msb << 8) | di.last_track_lsb;
ti_size = cdrom_get_track_info(cdi, last_track, 1, &ti);
if (ti_size < (int)offsetof(typeof(ti), track_start))
goto use_toc;
if (ti.blank) {
if (last_track == 1)
goto use_toc;
last_track--;
ti_size = cdrom_get_track_info(cdi, last_track, 1, &ti);
}
if (ti_size < (int)(offsetof(typeof(ti), track_size)
+ sizeof(ti.track_size)))
goto use_toc;
if (ti.lra_v && ti_size >= (int)(offsetof(typeof(ti), last_rec_address)
+ sizeof(ti.last_rec_address))) {
*last_written = be32_to_cpu(ti.last_rec_address);
} else {
*last_written = be32_to_cpu(ti.track_start) +
be32_to_cpu(ti.track_size);
if (ti.free_blocks)
*last_written -= (be32_to_cpu(ti.free_blocks) + 7);
}
return 0;
use_toc:
toc.cdte_format = CDROM_MSF;
toc.cdte_track = CDROM_LEADOUT;
if ((ret = cdi->ops->audio_ioctl(cdi, CDROMREADTOCENTRY, &toc)))
return ret;
sanitize_format(&toc.cdte_addr, &toc.cdte_format, CDROM_LBA);
*last_written = toc.cdte_addr.lba;
return 0;
}
static int cdrom_get_next_writable(struct cdrom_device_info *cdi,
long *next_writable)
{
disc_information di;
track_information ti;
__u16 last_track;
int ret, ti_size;
if (!CDROM_CAN(CDC_GENERIC_PACKET))
goto use_last_written;
ret = cdrom_get_disc_info(cdi, &di);
if (ret < 0 || ret < offsetof(typeof(di), last_track_lsb)
+ sizeof(di.last_track_lsb))
goto use_last_written;
last_track = (di.last_track_msb << 8) | di.last_track_lsb;
ti_size = cdrom_get_track_info(cdi, last_track, 1, &ti);
if (ti_size < 0 || ti_size < offsetof(typeof(ti), track_start))
goto use_last_written;
if (ti.blank) {
if (last_track == 1)
goto use_last_written;
last_track--;
ti_size = cdrom_get_track_info(cdi, last_track, 1, &ti);
if (ti_size < 0)
goto use_last_written;
}
if (ti.nwa_v && ti_size >= offsetof(typeof(ti), next_writable)
+ sizeof(ti.next_writable)) {
*next_writable = be32_to_cpu(ti.next_writable);
return 0;
}
use_last_written:
ret = cdrom_get_last_written(cdi, next_writable);
if (ret) {
*next_writable = 0;
return ret;
} else {
*next_writable += 7;
return 0;
}
}
static noinline int mmc_ioctl_cdrom_read_data(struct cdrom_device_info *cdi,
void __user *arg,
struct packet_command *cgc,
int cmd)
{
struct request_sense sense;
struct cdrom_msf msf;
int blocksize = 0, format = 0, lba;
int ret;
switch (cmd) {
case CDROMREADRAW:
blocksize = CD_FRAMESIZE_RAW;
break;
case CDROMREADMODE1:
blocksize = CD_FRAMESIZE;
format = 2;
break;
case CDROMREADMODE2:
blocksize = CD_FRAMESIZE_RAW0;
break;
}
if (copy_from_user(&msf, (struct cdrom_msf __user *)arg, sizeof(msf)))
return -EFAULT;
lba = msf_to_lba(msf.cdmsf_min0, msf.cdmsf_sec0, msf.cdmsf_frame0);
if (lba < 0)
return -EINVAL;
cgc->buffer = kzalloc(blocksize, GFP_KERNEL);
if (cgc->buffer == NULL)
return -ENOMEM;
memset(&sense, 0, sizeof(sense));
cgc->sense = &sense;
cgc->data_direction = CGC_DATA_READ;
ret = cdrom_read_block(cdi, cgc, lba, 1, format, blocksize);
if (ret && sense.sense_key == 0x05 &&
sense.asc == 0x20 &&
sense.ascq == 0x00) {
ret = cdrom_switch_blocksize(cdi, blocksize);
if (ret)
goto out;
cgc->sense = NULL;
ret = cdrom_read_cd(cdi, cgc, lba, blocksize, 1);
ret |= cdrom_switch_blocksize(cdi, blocksize);
}
if (!ret && copy_to_user(arg, cgc->buffer, blocksize))
ret = -EFAULT;
out:
kfree(cgc->buffer);
return ret;
}
static noinline int mmc_ioctl_cdrom_read_audio(struct cdrom_device_info *cdi,
void __user *arg)
{
struct cdrom_read_audio ra;
int lba;
if (copy_from_user(&ra, (struct cdrom_read_audio __user *)arg,
sizeof(ra)))
return -EFAULT;
if (ra.addr_format == CDROM_MSF)
lba = msf_to_lba(ra.addr.msf.minute,
ra.addr.msf.second,
ra.addr.msf.frame);
else if (ra.addr_format == CDROM_LBA)
lba = ra.addr.lba;
else
return -EINVAL;
if (lba < 0 || ra.nframes <= 0 || ra.nframes > CD_FRAMES)
return -EINVAL;
return cdrom_read_cdda(cdi, ra.buf, lba, ra.nframes);
}
static noinline int mmc_ioctl_cdrom_subchannel(struct cdrom_device_info *cdi,
void __user *arg)
{
int ret;
struct cdrom_subchnl q;
u_char requested, back;
if (copy_from_user(&q, (struct cdrom_subchnl __user *)arg, sizeof(q)))
return -EFAULT;
requested = q.cdsc_format;
if (!((requested == CDROM_MSF) ||
(requested == CDROM_LBA)))
return -EINVAL;
ret = cdrom_read_subchannel(cdi, &q, 0);
if (ret)
return ret;
back = q.cdsc_format;
sanitize_format(&q.cdsc_absaddr, &back, requested);
sanitize_format(&q.cdsc_reladdr, &q.cdsc_format, requested);
if (copy_to_user((struct cdrom_subchnl __user *)arg, &q, sizeof(q)))
return -EFAULT;
return 0;
}
static noinline int mmc_ioctl_cdrom_play_msf(struct cdrom_device_info *cdi,
void __user *arg,
struct packet_command *cgc)
{
const struct cdrom_device_ops *cdo = cdi->ops;
struct cdrom_msf msf;
cd_dbg(CD_DO_IOCTL, "entering CDROMPLAYMSF\n");
if (copy_from_user(&msf, (struct cdrom_msf __user *)arg, sizeof(msf)))
return -EFAULT;
cgc->cmd[0] = GPCMD_PLAY_AUDIO_MSF;
cgc->cmd[3] = msf.cdmsf_min0;
cgc->cmd[4] = msf.cdmsf_sec0;
cgc->cmd[5] = msf.cdmsf_frame0;
cgc->cmd[6] = msf.cdmsf_min1;
cgc->cmd[7] = msf.cdmsf_sec1;
cgc->cmd[8] = msf.cdmsf_frame1;
cgc->data_direction = CGC_DATA_NONE;
return cdo->generic_packet(cdi, cgc);
}
static noinline int mmc_ioctl_cdrom_play_blk(struct cdrom_device_info *cdi,
void __user *arg,
struct packet_command *cgc)
{
const struct cdrom_device_ops *cdo = cdi->ops;
struct cdrom_blk blk;
cd_dbg(CD_DO_IOCTL, "entering CDROMPLAYBLK\n");
if (copy_from_user(&blk, (struct cdrom_blk __user *)arg, sizeof(blk)))
return -EFAULT;
cgc->cmd[0] = GPCMD_PLAY_AUDIO_10;
cgc->cmd[2] = (blk.from >> 24) & 0xff;
cgc->cmd[3] = (blk.from >> 16) & 0xff;
cgc->cmd[4] = (blk.from >> 8) & 0xff;
cgc->cmd[5] = blk.from & 0xff;
cgc->cmd[7] = (blk.len >> 8) & 0xff;
cgc->cmd[8] = blk.len & 0xff;
cgc->data_direction = CGC_DATA_NONE;
return cdo->generic_packet(cdi, cgc);
}
static noinline int mmc_ioctl_cdrom_volume(struct cdrom_device_info *cdi,
void __user *arg,
struct packet_command *cgc,
unsigned int cmd)
{
struct cdrom_volctrl volctrl;
unsigned char buffer[32];
char mask[sizeof(buffer)];
unsigned short offset;
int ret;
cd_dbg(CD_DO_IOCTL, "entering CDROMVOLUME\n");
if (copy_from_user(&volctrl, (struct cdrom_volctrl __user *)arg,
sizeof(volctrl)))
return -EFAULT;
cgc->buffer = buffer;
cgc->buflen = 24;
ret = cdrom_mode_sense(cdi, cgc, GPMODE_AUDIO_CTL_PAGE, 0);
if (ret)
return ret;
offset = 8 + be16_to_cpu(*(__be16 *)(buffer + 6));
if (offset + 16 > sizeof(buffer))
return -E2BIG;
if (offset + 16 > cgc->buflen) {
cgc->buflen = offset + 16;
ret = cdrom_mode_sense(cdi, cgc,
GPMODE_AUDIO_CTL_PAGE, 0);
if (ret)
return ret;
}
if ((buffer[offset] & 0x3f) != GPMODE_AUDIO_CTL_PAGE ||
buffer[offset + 1] < 14)
return -EINVAL;
if (cmd == CDROMVOLREAD) {
volctrl.channel0 = buffer[offset+9];
volctrl.channel1 = buffer[offset+11];
volctrl.channel2 = buffer[offset+13];
volctrl.channel3 = buffer[offset+15];
if (copy_to_user((struct cdrom_volctrl __user *)arg, &volctrl,
sizeof(volctrl)))
return -EFAULT;
return 0;
}
cgc->buffer = mask;
ret = cdrom_mode_sense(cdi, cgc, GPMODE_AUDIO_CTL_PAGE, 1);
if (ret)
return ret;
buffer[offset + 9] = volctrl.channel0 & mask[offset + 9];
buffer[offset + 11] = volctrl.channel1 & mask[offset + 11];
buffer[offset + 13] = volctrl.channel2 & mask[offset + 13];
buffer[offset + 15] = volctrl.channel3 & mask[offset + 15];
cgc->buffer = buffer + offset - 8;
memset(cgc->buffer, 0, 8);
return cdrom_mode_select(cdi, cgc);
}
static noinline int mmc_ioctl_cdrom_start_stop(struct cdrom_device_info *cdi,
struct packet_command *cgc,
int cmd)
{
const struct cdrom_device_ops *cdo = cdi->ops;
cd_dbg(CD_DO_IOCTL, "entering CDROMSTART/CDROMSTOP\n");
cgc->cmd[0] = GPCMD_START_STOP_UNIT;
cgc->cmd[1] = 1;
cgc->cmd[4] = (cmd == CDROMSTART) ? 1 : 0;
cgc->data_direction = CGC_DATA_NONE;
return cdo->generic_packet(cdi, cgc);
}
static noinline int mmc_ioctl_cdrom_pause_resume(struct cdrom_device_info *cdi,
struct packet_command *cgc,
int cmd)
{
const struct cdrom_device_ops *cdo = cdi->ops;
cd_dbg(CD_DO_IOCTL, "entering CDROMPAUSE/CDROMRESUME\n");
cgc->cmd[0] = GPCMD_PAUSE_RESUME;
cgc->cmd[8] = (cmd == CDROMRESUME) ? 1 : 0;
cgc->data_direction = CGC_DATA_NONE;
return cdo->generic_packet(cdi, cgc);
}
static noinline int mmc_ioctl_dvd_read_struct(struct cdrom_device_info *cdi,
void __user *arg,
struct packet_command *cgc)
{
int ret;
dvd_struct *s;
int size = sizeof(dvd_struct);
if (!CDROM_CAN(CDC_DVD))
return -ENOSYS;
s = memdup_user(arg, size);
if (IS_ERR(s))
return PTR_ERR(s);
cd_dbg(CD_DO_IOCTL, "entering DVD_READ_STRUCT\n");
ret = dvd_read_struct(cdi, s, cgc);
if (ret)
goto out;
if (copy_to_user(arg, s, size))
ret = -EFAULT;
out:
kfree(s);
return ret;
}
static noinline int mmc_ioctl_dvd_auth(struct cdrom_device_info *cdi,
void __user *arg)
{
int ret;
dvd_authinfo ai;
if (!CDROM_CAN(CDC_DVD))
return -ENOSYS;
cd_dbg(CD_DO_IOCTL, "entering DVD_AUTH\n");
if (copy_from_user(&ai, (dvd_authinfo __user *)arg, sizeof(ai)))
return -EFAULT;
ret = dvd_do_auth(cdi, &ai);
if (ret)
return ret;
if (copy_to_user((dvd_authinfo __user *)arg, &ai, sizeof(ai)))
return -EFAULT;
return 0;
}
static noinline int mmc_ioctl_cdrom_next_writable(struct cdrom_device_info *cdi,
void __user *arg)
{
int ret;
long next = 0;
cd_dbg(CD_DO_IOCTL, "entering CDROM_NEXT_WRITABLE\n");
ret = cdrom_get_next_writable(cdi, &next);
if (ret)
return ret;
if (copy_to_user((long __user *)arg, &next, sizeof(next)))
return -EFAULT;
return 0;
}
static noinline int mmc_ioctl_cdrom_last_written(struct cdrom_device_info *cdi,
void __user *arg)
{
int ret;
long last = 0;
cd_dbg(CD_DO_IOCTL, "entering CDROM_LAST_WRITTEN\n");
ret = cdrom_get_last_written(cdi, &last);
if (ret)
return ret;
if (copy_to_user((long __user *)arg, &last, sizeof(last)))
return -EFAULT;
return 0;
}
static int mmc_ioctl(struct cdrom_device_info *cdi, unsigned int cmd,
unsigned long arg)
{
struct packet_command cgc;
void __user *userptr = (void __user *)arg;
memset(&cgc, 0, sizeof(cgc));
switch (cmd) {
case CDROMREADRAW:
case CDROMREADMODE1:
case CDROMREADMODE2:
return mmc_ioctl_cdrom_read_data(cdi, userptr, &cgc, cmd);
case CDROMREADAUDIO:
return mmc_ioctl_cdrom_read_audio(cdi, userptr);
case CDROMSUBCHNL:
return mmc_ioctl_cdrom_subchannel(cdi, userptr);
case CDROMPLAYMSF:
return mmc_ioctl_cdrom_play_msf(cdi, userptr, &cgc);
case CDROMPLAYBLK:
return mmc_ioctl_cdrom_play_blk(cdi, userptr, &cgc);
case CDROMVOLCTRL:
case CDROMVOLREAD:
return mmc_ioctl_cdrom_volume(cdi, userptr, &cgc, cmd);
case CDROMSTART:
case CDROMSTOP:
return mmc_ioctl_cdrom_start_stop(cdi, &cgc, cmd);
case CDROMPAUSE:
case CDROMRESUME:
return mmc_ioctl_cdrom_pause_resume(cdi, &cgc, cmd);
case DVD_READ_STRUCT:
return mmc_ioctl_dvd_read_struct(cdi, userptr, &cgc);
case DVD_AUTH:
return mmc_ioctl_dvd_auth(cdi, userptr);
case CDROM_NEXT_WRITABLE:
return mmc_ioctl_cdrom_next_writable(cdi, userptr);
case CDROM_LAST_WRITTEN:
return mmc_ioctl_cdrom_last_written(cdi, userptr);
}
return -ENOTTY;
}
int cdrom_ioctl(struct cdrom_device_info *cdi, struct block_device *bdev,
fmode_t mode, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int ret;
ret = scsi_cmd_blk_ioctl(bdev, mode, cmd, argp);
if (ret != -ENOTTY)
return ret;
switch (cmd) {
case CDROMMULTISESSION:
return cdrom_ioctl_multisession(cdi, argp);
case CDROMEJECT:
return cdrom_ioctl_eject(cdi);
case CDROMCLOSETRAY:
return cdrom_ioctl_closetray(cdi);
case CDROMEJECT_SW:
return cdrom_ioctl_eject_sw(cdi, arg);
case CDROM_MEDIA_CHANGED:
return cdrom_ioctl_media_changed(cdi, arg);
case CDROM_SET_OPTIONS:
return cdrom_ioctl_set_options(cdi, arg);
case CDROM_CLEAR_OPTIONS:
return cdrom_ioctl_clear_options(cdi, arg);
case CDROM_SELECT_SPEED:
return cdrom_ioctl_select_speed(cdi, arg);
case CDROM_SELECT_DISC:
return cdrom_ioctl_select_disc(cdi, arg);
case CDROMRESET:
return cdrom_ioctl_reset(cdi, bdev);
case CDROM_LOCKDOOR:
return cdrom_ioctl_lock_door(cdi, arg);
case CDROM_DEBUG:
return cdrom_ioctl_debug(cdi, arg);
case CDROM_GET_CAPABILITY:
return cdrom_ioctl_get_capability(cdi);
case CDROM_GET_MCN:
return cdrom_ioctl_get_mcn(cdi, argp);
case CDROM_DRIVE_STATUS:
return cdrom_ioctl_drive_status(cdi, arg);
case CDROM_DISC_STATUS:
return cdrom_ioctl_disc_status(cdi);
case CDROM_CHANGER_NSLOTS:
return cdrom_ioctl_changer_nslots(cdi);
}
if (CDROM_CAN(CDC_GENERIC_PACKET)) {
ret = mmc_ioctl(cdi, cmd, arg);
if (ret != -ENOTTY)
return ret;
}
switch (cmd) {
case CDROMSUBCHNL:
return cdrom_ioctl_get_subchnl(cdi, argp);
case CDROMREADTOCHDR:
return cdrom_ioctl_read_tochdr(cdi, argp);
case CDROMREADTOCENTRY:
return cdrom_ioctl_read_tocentry(cdi, argp);
case CDROMPLAYMSF:
return cdrom_ioctl_play_msf(cdi, argp);
case CDROMPLAYTRKIND:
return cdrom_ioctl_play_trkind(cdi, argp);
case CDROMVOLCTRL:
return cdrom_ioctl_volctrl(cdi, argp);
case CDROMVOLREAD:
return cdrom_ioctl_volread(cdi, argp);
case CDROMSTART:
case CDROMSTOP:
case CDROMPAUSE:
case CDROMRESUME:
return cdrom_ioctl_audioctl(cdi, cmd);
}
return -ENOSYS;
}
static int cdrom_print_info(const char *header, int val, char *info,
int *pos, enum cdrom_print_option option)
{
const int max_size = sizeof(cdrom_sysctl_settings.info);
struct cdrom_device_info *cdi;
int ret;
ret = scnprintf(info + *pos, max_size - *pos, header);
if (!ret)
return 1;
*pos += ret;
list_for_each_entry(cdi, &cdrom_list, list) {
switch (option) {
case CTL_NAME:
ret = scnprintf(info + *pos, max_size - *pos,
"\t%s", cdi->name);
break;
case CTL_SPEED:
ret = scnprintf(info + *pos, max_size - *pos,
"\t%d", cdi->speed);
break;
case CTL_SLOTS:
ret = scnprintf(info + *pos, max_size - *pos,
"\t%d", cdi->capacity);
break;
case CTL_CAPABILITY:
ret = scnprintf(info + *pos, max_size - *pos,
"\t%d", CDROM_CAN(val) != 0);
break;
default:
pr_info("invalid option%d\n", option);
return 1;
}
if (!ret)
return 1;
*pos += ret;
}
return 0;
}
static int cdrom_sysctl_info(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int pos;
char *info = cdrom_sysctl_settings.info;
const int max_size = sizeof(cdrom_sysctl_settings.info);
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
mutex_lock(&cdrom_mutex);
pos = sprintf(info, "CD-ROM information, " VERSION "\n");
if (cdrom_print_info("\ndrive name:\t", 0, info, &pos, CTL_NAME))
goto done;
if (cdrom_print_info("\ndrive speed:\t", 0, info, &pos, CTL_SPEED))
goto done;
if (cdrom_print_info("\ndrive # of slots:", 0, info, &pos, CTL_SLOTS))
goto done;
if (cdrom_print_info("\nCan close tray:\t",
CDC_CLOSE_TRAY, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan open tray:\t",
CDC_OPEN_TRAY, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan lock tray:\t",
CDC_LOCK, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan change speed:",
CDC_SELECT_SPEED, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan select disk:",
CDC_SELECT_DISC, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan read multisession:",
CDC_MULTI_SESSION, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan read MCN:\t",
CDC_MCN, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nReports media changed:",
CDC_MEDIA_CHANGED, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan play audio:\t",
CDC_PLAY_AUDIO, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan write CD-R:\t",
CDC_CD_R, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan write CD-RW:",
CDC_CD_RW, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan read DVD:\t",
CDC_DVD, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan write DVD-R:",
CDC_DVD_R, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan write DVD-RAM:",
CDC_DVD_RAM, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan read MRW:\t",
CDC_MRW, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan write MRW:\t",
CDC_MRW_W, info, &pos, CTL_CAPABILITY))
goto done;
if (cdrom_print_info("\nCan write RAM:\t",
CDC_RAM, info, &pos, CTL_CAPABILITY))
goto done;
if (!scnprintf(info + pos, max_size - pos, "\n\n"))
goto done;
doit:
mutex_unlock(&cdrom_mutex);
return proc_dostring(ctl, write, buffer, lenp, ppos);
done:
pr_info("info buffer too small\n");
goto doit;
}
static void cdrom_update_settings(void)
{
struct cdrom_device_info *cdi;
mutex_lock(&cdrom_mutex);
list_for_each_entry(cdi, &cdrom_list, list) {
if (autoclose && CDROM_CAN(CDC_CLOSE_TRAY))
cdi->options |= CDO_AUTO_CLOSE;
else if (!autoclose)
cdi->options &= ~CDO_AUTO_CLOSE;
if (autoeject && CDROM_CAN(CDC_OPEN_TRAY))
cdi->options |= CDO_AUTO_EJECT;
else if (!autoeject)
cdi->options &= ~CDO_AUTO_EJECT;
if (lockdoor && CDROM_CAN(CDC_LOCK))
cdi->options |= CDO_LOCK;
else if (!lockdoor)
cdi->options &= ~CDO_LOCK;
if (check_media_type)
cdi->options |= CDO_CHECK_TYPE;
else
cdi->options &= ~CDO_CHECK_TYPE;
}
mutex_unlock(&cdrom_mutex);
}
static int cdrom_sysctl_handler(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret;
ret = proc_dointvec(ctl, write, buffer, lenp, ppos);
if (write) {
autoclose = !!cdrom_sysctl_settings.autoclose;
autoeject = !!cdrom_sysctl_settings.autoeject;
debug = !!cdrom_sysctl_settings.debug;
lockdoor = !!cdrom_sysctl_settings.lock;
check_media_type = !!cdrom_sysctl_settings.check;
cdrom_update_settings();
}
return ret;
}
static void cdrom_sysctl_register(void)
{
static int initialized;
if (initialized == 1)
return;
cdrom_sysctl_header = register_sysctl_table(cdrom_root_table);
cdrom_sysctl_settings.autoclose = autoclose;
cdrom_sysctl_settings.autoeject = autoeject;
cdrom_sysctl_settings.debug = debug;
cdrom_sysctl_settings.lock = lockdoor;
cdrom_sysctl_settings.check = check_media_type;
initialized = 1;
}
static void cdrom_sysctl_unregister(void)
{
if (cdrom_sysctl_header)
unregister_sysctl_table(cdrom_sysctl_header);
}
static void cdrom_sysctl_register(void)
{
}
static void cdrom_sysctl_unregister(void)
{
}
static int __init cdrom_init(void)
{
cdrom_sysctl_register();
return 0;
}
static void __exit cdrom_exit(void)
{
pr_info("Uniform CD-ROM driver unloaded\n");
cdrom_sysctl_unregister();
}
