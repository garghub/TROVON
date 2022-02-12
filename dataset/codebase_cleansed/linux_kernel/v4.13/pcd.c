static int pcd_block_open(struct block_device *bdev, fmode_t mode)
{
struct pcd_unit *cd = bdev->bd_disk->private_data;
int ret;
mutex_lock(&pcd_mutex);
ret = cdrom_open(&cd->info, bdev, mode);
mutex_unlock(&pcd_mutex);
return ret;
}
static void pcd_block_release(struct gendisk *disk, fmode_t mode)
{
struct pcd_unit *cd = disk->private_data;
mutex_lock(&pcd_mutex);
cdrom_release(&cd->info, mode);
mutex_unlock(&pcd_mutex);
}
static int pcd_block_ioctl(struct block_device *bdev, fmode_t mode,
unsigned cmd, unsigned long arg)
{
struct pcd_unit *cd = bdev->bd_disk->private_data;
int ret;
mutex_lock(&pcd_mutex);
ret = cdrom_ioctl(&cd->info, bdev, mode, cmd, arg);
mutex_unlock(&pcd_mutex);
return ret;
}
static unsigned int pcd_block_check_events(struct gendisk *disk,
unsigned int clearing)
{
struct pcd_unit *cd = disk->private_data;
return cdrom_check_events(&cd->info, clearing);
}
static void pcd_init_units(void)
{
struct pcd_unit *cd;
int unit;
pcd_drive_count = 0;
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++) {
struct gendisk *disk = alloc_disk(1);
if (!disk)
continue;
disk->queue = blk_init_queue(do_pcd_request, &pcd_lock);
if (!disk->queue) {
put_disk(disk);
continue;
}
blk_queue_bounce_limit(disk->queue, BLK_BOUNCE_HIGH);
cd->disk = disk;
cd->pi = &cd->pia;
cd->present = 0;
cd->last_sense = 0;
cd->changed = 1;
cd->drive = (*drives[unit])[D_SLV];
if ((*drives[unit])[D_PRT])
pcd_drive_count++;
cd->name = &cd->info.name[0];
snprintf(cd->name, sizeof(cd->info.name), "%s%d", name, unit);
cd->info.ops = &pcd_dops;
cd->info.handle = cd;
cd->info.speed = 0;
cd->info.capacity = 1;
cd->info.mask = 0;
disk->major = major;
disk->first_minor = unit;
strcpy(disk->disk_name, cd->name);
disk->fops = &pcd_bdops;
disk->flags = GENHD_FL_BLOCK_EVENTS_ON_EXCL_WRITE;
}
}
static int pcd_open(struct cdrom_device_info *cdi, int purpose)
{
struct pcd_unit *cd = cdi->handle;
if (!cd->present)
return -ENODEV;
return 0;
}
static void pcd_release(struct cdrom_device_info *cdi)
{
}
static inline int status_reg(struct pcd_unit *cd)
{
return pi_read_regr(cd->pi, 1, 6);
}
static inline int read_reg(struct pcd_unit *cd, int reg)
{
return pi_read_regr(cd->pi, 0, reg);
}
static inline void write_reg(struct pcd_unit *cd, int reg, int val)
{
pi_write_regr(cd->pi, 0, reg, val);
}
static int pcd_wait(struct pcd_unit *cd, int go, int stop, char *fun, char *msg)
{
int j, r, e, s, p;
j = 0;
while ((((r = status_reg(cd)) & go) || (stop && (!(r & stop))))
&& (j++ < PCD_SPIN))
udelay(PCD_DELAY);
if ((r & (IDE_ERR & stop)) || (j > PCD_SPIN)) {
s = read_reg(cd, 7);
e = read_reg(cd, 1);
p = read_reg(cd, 2);
if (j > PCD_SPIN)
e |= 0x100;
if (fun)
printk("%s: %s %s: alt=0x%x stat=0x%x err=0x%x"
" loop=%d phase=%d\n",
cd->name, fun, msg, r, s, e, j, p);
return (s << 8) + r;
}
return 0;
}
static int pcd_command(struct pcd_unit *cd, char *cmd, int dlen, char *fun)
{
pi_connect(cd->pi);
write_reg(cd, 6, 0xa0 + 0x10 * cd->drive);
if (pcd_wait(cd, IDE_BUSY | IDE_DRQ, 0, fun, "before command")) {
pi_disconnect(cd->pi);
return -1;
}
write_reg(cd, 4, dlen % 256);
write_reg(cd, 5, dlen / 256);
write_reg(cd, 7, 0xa0);
if (pcd_wait(cd, IDE_BUSY, IDE_DRQ, fun, "command DRQ")) {
pi_disconnect(cd->pi);
return -1;
}
if (read_reg(cd, 2) != 1) {
printk("%s: %s: command phase error\n", cd->name, fun);
pi_disconnect(cd->pi);
return -1;
}
pi_write_block(cd->pi, cmd, 12);
return 0;
}
static int pcd_completion(struct pcd_unit *cd, char *buf, char *fun)
{
int r, d, p, n, k, j;
r = -1;
k = 0;
j = 0;
if (!pcd_wait(cd, IDE_BUSY, IDE_DRQ | IDE_READY | IDE_ERR,
fun, "completion")) {
r = 0;
while (read_reg(cd, 7) & IDE_DRQ) {
d = read_reg(cd, 4) + 256 * read_reg(cd, 5);
n = (d + 3) & 0xfffc;
p = read_reg(cd, 2) & 3;
if ((p == 2) && (n > 0) && (j == 0)) {
pi_read_block(cd->pi, buf, n);
if (verbose > 1)
printk("%s: %s: Read %d bytes\n",
cd->name, fun, n);
r = 0;
j++;
} else {
if (verbose > 1)
printk
("%s: %s: Unexpected phase %d, d=%d, k=%d\n",
cd->name, fun, p, d, k);
if (verbose < 2)
printk_once(
"%s: WARNING: ATAPI phase errors\n",
cd->name);
mdelay(1);
}
if (k++ > PCD_TMO) {
printk("%s: Stuck DRQ\n", cd->name);
break;
}
if (pcd_wait
(cd, IDE_BUSY, IDE_DRQ | IDE_READY | IDE_ERR, fun,
"completion")) {
r = -1;
break;
}
}
}
pi_disconnect(cd->pi);
return r;
}
static void pcd_req_sense(struct pcd_unit *cd, char *fun)
{
char rs_cmd[12] = { 0x03, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0 };
char buf[16];
int r, c;
r = pcd_command(cd, rs_cmd, 16, "Request sense");
mdelay(1);
if (!r)
pcd_completion(cd, buf, "Request sense");
cd->last_sense = -1;
c = 2;
if (!r) {
if (fun)
printk("%s: %s: Sense key: %x, ASC: %x, ASQ: %x\n",
cd->name, fun, buf[2] & 0xf, buf[12], buf[13]);
c = buf[2] & 0xf;
cd->last_sense =
c | ((buf[12] & 0xff) << 8) | ((buf[13] & 0xff) << 16);
}
if ((c == 2) || (c == 6))
cd->changed = 1;
}
static int pcd_atapi(struct pcd_unit *cd, char *cmd, int dlen, char *buf, char *fun)
{
int r;
r = pcd_command(cd, cmd, dlen, fun);
mdelay(1);
if (!r)
r = pcd_completion(cd, buf, fun);
if (r)
pcd_req_sense(cd, fun);
return r;
}
static int pcd_packet(struct cdrom_device_info *cdi, struct packet_command *cgc)
{
return pcd_atapi(cdi->handle, cgc->cmd, cgc->buflen, cgc->buffer,
"generic packet");
}
static unsigned int pcd_check_events(struct cdrom_device_info *cdi,
unsigned int clearing, int slot_nr)
{
struct pcd_unit *cd = cdi->handle;
int res = cd->changed;
if (res)
cd->changed = 0;
return res ? DISK_EVENT_MEDIA_CHANGE : 0;
}
static int pcd_lock_door(struct cdrom_device_info *cdi, int lock)
{
char un_cmd[12] = { 0x1e, 0, 0, 0, lock, 0, 0, 0, 0, 0, 0, 0 };
return pcd_atapi(cdi->handle, un_cmd, 0, pcd_scratch,
lock ? "lock door" : "unlock door");
}
static int pcd_tray_move(struct cdrom_device_info *cdi, int position)
{
char ej_cmd[12] = { 0x1b, 0, 0, 0, 3 - position, 0, 0, 0, 0, 0, 0, 0 };
return pcd_atapi(cdi->handle, ej_cmd, 0, pcd_scratch,
position ? "eject" : "close tray");
}
static void pcd_sleep(int cs)
{
schedule_timeout_interruptible(cs);
}
static int pcd_reset(struct pcd_unit *cd)
{
int i, k, flg;
int expect[5] = { 1, 1, 1, 0x14, 0xeb };
pi_connect(cd->pi);
write_reg(cd, 6, 0xa0 + 0x10 * cd->drive);
write_reg(cd, 7, 8);
pcd_sleep(20 * HZ / 1000);
k = 0;
while ((k++ < PCD_RESET_TMO) && (status_reg(cd) & IDE_BUSY))
pcd_sleep(HZ / 10);
flg = 1;
for (i = 0; i < 5; i++)
flg &= (read_reg(cd, i + 1) == expect[i]);
if (verbose) {
printk("%s: Reset (%d) signature = ", cd->name, k);
for (i = 0; i < 5; i++)
printk("%3x", read_reg(cd, i + 1));
if (!flg)
printk(" (incorrect)");
printk("\n");
}
pi_disconnect(cd->pi);
return flg - 1;
}
static int pcd_drive_reset(struct cdrom_device_info *cdi)
{
return pcd_reset(cdi->handle);
}
static int pcd_ready_wait(struct pcd_unit *cd, int tmo)
{
char tr_cmd[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int k, p;
k = 0;
while (k < tmo) {
cd->last_sense = 0;
pcd_atapi(cd, tr_cmd, 0, NULL, DBMSG("test unit ready"));
p = cd->last_sense;
if (!p)
return 0;
if (!(((p & 0xffff) == 0x0402) || ((p & 0xff) == 6)))
return p;
k++;
pcd_sleep(HZ);
}
return 0x000020;
}
static int pcd_drive_status(struct cdrom_device_info *cdi, int slot_nr)
{
char rc_cmd[12] = { 0x25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
struct pcd_unit *cd = cdi->handle;
if (pcd_ready_wait(cd, PCD_READY_TMO))
return CDS_DRIVE_NOT_READY;
if (pcd_atapi(cd, rc_cmd, 8, pcd_scratch, DBMSG("check media")))
return CDS_NO_DISC;
return CDS_DISC_OK;
}
static int pcd_identify(struct pcd_unit *cd, char *id)
{
int k, s;
char id_cmd[12] = { 0x12, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0 };
pcd_bufblk = -1;
s = pcd_atapi(cd, id_cmd, 36, pcd_buffer, "identify");
if (s)
return -1;
if ((pcd_buffer[0] & 0x1f) != 5) {
if (verbose)
printk("%s: %s is not a CD-ROM\n",
cd->name, cd->drive ? "Slave" : "Master");
return -1;
}
memcpy(id, pcd_buffer + 16, 16);
id[16] = 0;
k = 16;
while ((k >= 0) && (id[k] <= 0x20)) {
id[k] = 0;
k--;
}
printk("%s: %s: %s\n", cd->name, cd->drive ? "Slave" : "Master", id);
return 0;
}
static int pcd_probe(struct pcd_unit *cd, int ms, char *id)
{
if (ms == -1) {
for (cd->drive = 0; cd->drive <= 1; cd->drive++)
if (!pcd_reset(cd) && !pcd_identify(cd, id))
return 0;
} else {
cd->drive = ms;
if (!pcd_reset(cd) && !pcd_identify(cd, id))
return 0;
}
return -1;
}
static void pcd_probe_capabilities(void)
{
int unit, r;
char buffer[32];
char cmd[12] = { 0x5a, 1 << 3, 0x2a, 0, 0, 0, 0, 18, 0, 0, 0, 0 };
struct pcd_unit *cd;
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++) {
if (!cd->present)
continue;
r = pcd_atapi(cd, cmd, 18, buffer, "mode sense capabilities");
if (r)
continue;
if ((buffer[11] & 1) == 0)
cd->info.mask |= CDC_CD_R;
if ((buffer[11] & 2) == 0)
cd->info.mask |= CDC_CD_RW;
if ((buffer[12] & 1) == 0)
cd->info.mask |= CDC_PLAY_AUDIO;
if ((buffer[14] & 1) == 0)
cd->info.mask |= CDC_LOCK;
if ((buffer[14] & 8) == 0)
cd->info.mask |= CDC_OPEN_TRAY;
if ((buffer[14] >> 6) == 0)
cd->info.mask |= CDC_CLOSE_TRAY;
}
}
static int pcd_detect(void)
{
char id[18];
int k, unit;
struct pcd_unit *cd;
printk("%s: %s version %s, major %d, nice %d\n",
name, name, PCD_VERSION, major, nice);
par_drv = pi_register_driver(name);
if (!par_drv) {
pr_err("failed to register %s driver\n", name);
return -1;
}
k = 0;
if (pcd_drive_count == 0) {
cd = pcd;
if (pi_init(cd->pi, 1, -1, -1, -1, -1, -1, pcd_buffer,
PI_PCD, verbose, cd->name)) {
if (!pcd_probe(cd, -1, id) && cd->disk) {
cd->present = 1;
k++;
} else
pi_release(cd->pi);
}
} else {
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++) {
int *conf = *drives[unit];
if (!conf[D_PRT])
continue;
if (!pi_init(cd->pi, 0, conf[D_PRT], conf[D_MOD],
conf[D_UNI], conf[D_PRO], conf[D_DLY],
pcd_buffer, PI_PCD, verbose, cd->name))
continue;
if (!pcd_probe(cd, conf[D_SLV], id) && cd->disk) {
cd->present = 1;
k++;
} else
pi_release(cd->pi);
}
}
if (k)
return 0;
printk("%s: No CD-ROM drive found\n", name);
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++)
put_disk(cd->disk);
pi_unregister_driver(par_drv);
return -1;
}
static int set_next_request(void)
{
struct pcd_unit *cd;
struct request_queue *q;
int old_pos = pcd_queue;
do {
cd = &pcd[pcd_queue];
q = cd->present ? cd->disk->queue : NULL;
if (++pcd_queue == PCD_UNITS)
pcd_queue = 0;
if (q) {
pcd_req = blk_fetch_request(q);
if (pcd_req)
break;
}
} while (pcd_queue != old_pos);
return pcd_req != NULL;
}
static void pcd_request(void)
{
if (pcd_busy)
return;
while (1) {
if (!pcd_req && !set_next_request())
return;
if (rq_data_dir(pcd_req) == READ) {
struct pcd_unit *cd = pcd_req->rq_disk->private_data;
if (cd != pcd_current)
pcd_bufblk = -1;
pcd_current = cd;
pcd_sector = blk_rq_pos(pcd_req);
pcd_count = blk_rq_cur_sectors(pcd_req);
pcd_buf = bio_data(pcd_req->bio);
pcd_busy = 1;
ps_set_intr(do_pcd_read, NULL, 0, nice);
return;
} else {
__blk_end_request_all(pcd_req, BLK_STS_IOERR);
pcd_req = NULL;
}
}
}
static void do_pcd_request(struct request_queue *q)
{
pcd_request();
}
static inline void next_request(blk_status_t err)
{
unsigned long saved_flags;
spin_lock_irqsave(&pcd_lock, saved_flags);
if (!__blk_end_request_cur(pcd_req, err))
pcd_req = NULL;
pcd_busy = 0;
pcd_request();
spin_unlock_irqrestore(&pcd_lock, saved_flags);
}
static int pcd_ready(void)
{
return (((status_reg(pcd_current) & (IDE_BUSY | IDE_DRQ)) == IDE_DRQ));
}
static void pcd_transfer(void)
{
while (pcd_count && (pcd_sector / 4 == pcd_bufblk)) {
int o = (pcd_sector % 4) * 512;
memcpy(pcd_buf, pcd_buffer + o, 512);
pcd_count--;
pcd_buf += 512;
pcd_sector++;
}
}
static void pcd_start(void)
{
int b, i;
char rd_cmd[12] = { 0xa8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
pcd_bufblk = pcd_sector / 4;
b = pcd_bufblk;
for (i = 0; i < 4; i++) {
rd_cmd[5 - i] = b & 0xff;
b = b >> 8;
}
if (pcd_command(pcd_current, rd_cmd, 2048, "read block")) {
pcd_bufblk = -1;
next_request(BLK_STS_IOERR);
return;
}
mdelay(1);
ps_set_intr(do_pcd_read_drq, pcd_ready, PCD_TMO, nice);
}
static void do_pcd_read(void)
{
pcd_busy = 1;
pcd_retries = 0;
pcd_transfer();
if (!pcd_count) {
next_request(0);
return;
}
pi_do_claimed(pcd_current->pi, pcd_start);
}
static void do_pcd_read_drq(void)
{
unsigned long saved_flags;
if (pcd_completion(pcd_current, pcd_buffer, "read block")) {
if (pcd_retries < PCD_RETRIES) {
mdelay(1);
pcd_retries++;
pi_do_claimed(pcd_current->pi, pcd_start);
return;
}
pcd_bufblk = -1;
next_request(BLK_STS_IOERR);
return;
}
do_pcd_read();
spin_lock_irqsave(&pcd_lock, saved_flags);
pcd_request();
spin_unlock_irqrestore(&pcd_lock, saved_flags);
}
static int pcd_audio_ioctl(struct cdrom_device_info *cdi, unsigned int cmd, void *arg)
{
struct pcd_unit *cd = cdi->handle;
switch (cmd) {
case CDROMREADTOCHDR:
{
char cmd[12] =
{ GPCMD_READ_TOC_PMA_ATIP, 0, 0, 0, 0, 0, 0, 0, 12,
0, 0, 0 };
struct cdrom_tochdr *tochdr =
(struct cdrom_tochdr *) arg;
char buffer[32];
int r;
r = pcd_atapi(cd, cmd, 12, buffer, "read toc header");
tochdr->cdth_trk0 = buffer[2];
tochdr->cdth_trk1 = buffer[3];
return r ? -EIO : 0;
}
case CDROMREADTOCENTRY:
{
char cmd[12] =
{ GPCMD_READ_TOC_PMA_ATIP, 0, 0, 0, 0, 0, 0, 0, 12,
0, 0, 0 };
struct cdrom_tocentry *tocentry =
(struct cdrom_tocentry *) arg;
unsigned char buffer[32];
int r;
cmd[1] =
(tocentry->cdte_format == CDROM_MSF ? 0x02 : 0);
cmd[6] = tocentry->cdte_track;
r = pcd_atapi(cd, cmd, 12, buffer, "read toc entry");
tocentry->cdte_ctrl = buffer[5] & 0xf;
tocentry->cdte_adr = buffer[5] >> 4;
tocentry->cdte_datamode =
(tocentry->cdte_ctrl & 0x04) ? 1 : 0;
if (tocentry->cdte_format == CDROM_MSF) {
tocentry->cdte_addr.msf.minute = buffer[9];
tocentry->cdte_addr.msf.second = buffer[10];
tocentry->cdte_addr.msf.frame = buffer[11];
} else
tocentry->cdte_addr.lba =
(((((buffer[8] << 8) + buffer[9]) << 8)
+ buffer[10]) << 8) + buffer[11];
return r ? -EIO : 0;
}
default:
return -ENOSYS;
}
}
static int pcd_get_mcn(struct cdrom_device_info *cdi, struct cdrom_mcn *mcn)
{
char cmd[12] =
{ GPCMD_READ_SUBCHANNEL, 0, 0x40, 2, 0, 0, 0, 0, 24, 0, 0, 0 };
char buffer[32];
if (pcd_atapi(cdi->handle, cmd, 24, buffer, "get mcn"))
return -EIO;
memcpy(mcn->medium_catalog_number, buffer + 9, 13);
mcn->medium_catalog_number[13] = 0;
return 0;
}
static int __init pcd_init(void)
{
struct pcd_unit *cd;
int unit;
if (disable)
return -EINVAL;
pcd_init_units();
if (pcd_detect())
return -ENODEV;
pcd_probe_capabilities();
if (register_blkdev(major, name)) {
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++)
put_disk(cd->disk);
return -EBUSY;
}
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++) {
if (cd->present) {
register_cdrom(&cd->info);
cd->disk->private_data = cd;
add_disk(cd->disk);
}
}
return 0;
}
static void __exit pcd_exit(void)
{
struct pcd_unit *cd;
int unit;
for (unit = 0, cd = pcd; unit < PCD_UNITS; unit++, cd++) {
if (cd->present) {
del_gendisk(cd->disk);
pi_release(cd->pi);
unregister_cdrom(&cd->info);
}
blk_cleanup_queue(cd->disk->queue);
put_disk(cd->disk);
}
unregister_blkdev(major, name);
pi_unregister_driver(par_drv);
}
