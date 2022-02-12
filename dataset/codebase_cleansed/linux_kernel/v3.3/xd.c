static int __init xd_init(void)
{
u_char i,controller;
unsigned int address;
int err;
#ifdef MODULE
{
u_char count = 0;
for (i = 4; i > 0; i--)
if (((xd[i] = xd[i-1]) >= 0) && !count)
count = i;
if ((xd[0] = count))
do_xd_setup(xd);
}
#endif
init_timer (&xd_watchdog_int); xd_watchdog_int.function = xd_watchdog;
err = -EBUSY;
if (register_blkdev(XT_DISK_MAJOR, "xd"))
goto out1;
err = -ENOMEM;
xd_queue = blk_init_queue(do_xd_request, &xd_lock);
if (!xd_queue)
goto out1a;
if (xd_detect(&controller,&address)) {
printk("Detected a%s controller (type %d) at address %06x\n",
xd_sigs[controller].name,controller,address);
if (!request_region(xd_iobase,4,"xd")) {
printk("xd: Ports at 0x%x are not available\n",
xd_iobase);
goto out2;
}
if (controller)
xd_sigs[controller].init_controller(address);
xd_drives = xd_initdrives(xd_sigs[controller].init_drive);
printk("Detected %d hard drive%s (using IRQ%d & DMA%d)\n",
xd_drives,xd_drives == 1 ? "" : "s",xd_irq,xd_dma);
}
if (!xd_dma_buffer && xd_maxsectors) {
xd_dma_buffer = (char *)xd_dma_mem_alloc(xd_maxsectors * 0x200);
if (!xd_dma_buffer) {
printk(KERN_ERR "xd: Out of memory.\n");
goto out3;
}
}
err = -ENODEV;
if (!xd_drives)
goto out3;
for (i = 0; i < xd_drives; i++) {
XD_INFO *p = &xd_info[i];
struct gendisk *disk = alloc_disk(64);
if (!disk)
goto Enomem;
p->unit = i;
disk->major = XT_DISK_MAJOR;
disk->first_minor = i<<6;
sprintf(disk->disk_name, "xd%c", i+'a');
disk->fops = &xd_fops;
disk->private_data = p;
disk->queue = xd_queue;
set_capacity(disk, p->heads * p->cylinders * p->sectors);
printk(" %s: CHS=%d/%d/%d\n", disk->disk_name,
p->cylinders, p->heads, p->sectors);
xd_gendisk[i] = disk;
}
err = -EBUSY;
if (request_irq(xd_irq,xd_interrupt_handler, 0, "XT hard disk", NULL)) {
printk("xd: unable to get IRQ%d\n",xd_irq);
goto out4;
}
if (request_dma(xd_dma,"xd")) {
printk("xd: unable to get DMA%d\n",xd_dma);
goto out5;
}
blk_queue_max_hw_sectors(xd_queue, xd_maxsectors);
for (i = 0; i < xd_drives; i++)
add_disk(xd_gendisk[i]);
return 0;
out5:
free_irq(xd_irq, NULL);
out4:
for (i = 0; i < xd_drives; i++)
put_disk(xd_gendisk[i]);
out3:
if (xd_maxsectors)
release_region(xd_iobase,4);
if (xd_dma_buffer)
xd_dma_mem_free((unsigned long)xd_dma_buffer,
xd_maxsectors * 0x200);
out2:
blk_cleanup_queue(xd_queue);
out1a:
unregister_blkdev(XT_DISK_MAJOR, "xd");
out1:
return err;
Enomem:
err = -ENOMEM;
while (i--)
put_disk(xd_gendisk[i]);
goto out3;
}
static u_char __init xd_detect (u_char *controller, unsigned int *address)
{
int i, j;
if (xd_override)
{
*controller = xd_type;
*address = 0;
return(1);
}
for (i = 0; i < ARRAY_SIZE(xd_bases); i++) {
void __iomem *p = ioremap(xd_bases[i], 0x2000);
if (!p)
continue;
for (j = 1; j < ARRAY_SIZE(xd_sigs); j++) {
const char *s = xd_sigs[j].string;
if (check_signature(p + xd_sigs[j].offset, s, strlen(s))) {
*controller = j;
xd_type = j;
*address = xd_bases[i];
iounmap(p);
return 1;
}
}
iounmap(p);
}
return 0;
}
static void do_xd_request (struct request_queue * q)
{
struct request *req;
if (xdc_busy)
return;
req = blk_fetch_request(q);
while (req) {
unsigned block = blk_rq_pos(req);
unsigned count = blk_rq_cur_sectors(req);
XD_INFO *disk = req->rq_disk->private_data;
int res = -EIO;
int retry;
if (req->cmd_type != REQ_TYPE_FS)
goto done;
if (block + count > get_capacity(req->rq_disk))
goto done;
for (retry = 0; (retry < XD_RETRIES) && !res; retry++)
res = xd_readwrite(rq_data_dir(req), disk, req->buffer,
block, count);
done:
if (!__blk_end_request_cur(req, res))
req = blk_fetch_request(q);
}
}
static int xd_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
XD_INFO *p = bdev->bd_disk->private_data;
geo->heads = p->heads;
geo->sectors = p->sectors;
geo->cylinders = p->cylinders;
return 0;
}
static int xd_locked_ioctl(struct block_device *bdev, fmode_t mode, u_int cmd, u_long arg)
{
switch (cmd) {
case HDIO_SET_DMA:
if (!capable(CAP_SYS_ADMIN)) return -EACCES;
if (xdc_busy) return -EBUSY;
nodma = !arg;
if (nodma && xd_dma_buffer) {
xd_dma_mem_free((unsigned long)xd_dma_buffer,
xd_maxsectors * 0x200);
xd_dma_buffer = NULL;
} else if (!nodma && !xd_dma_buffer) {
xd_dma_buffer = (char *)xd_dma_mem_alloc(xd_maxsectors * 0x200);
if (!xd_dma_buffer) {
nodma = XD_DONT_USE_DMA;
return -ENOMEM;
}
}
return 0;
case HDIO_GET_DMA:
return put_user(!nodma, (long __user *) arg);
case HDIO_GET_MULTCOUNT:
return put_user(xd_maxsectors, (long __user *) arg);
default:
return -EINVAL;
}
}
static int xd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long param)
{
int ret;
mutex_lock(&xd_mutex);
ret = xd_locked_ioctl(bdev, mode, cmd, param);
mutex_unlock(&xd_mutex);
return ret;
}
static int xd_readwrite (u_char operation,XD_INFO *p,char *buffer,u_int block,u_int count)
{
int drive = p->unit;
u_char cmdblk[6],sense[4];
u_short track,cylinder;
u_char head,sector,control,mode = PIO_MODE,temp;
char **real_buffer;
register int i;
#ifdef DEBUG_READWRITE
printk("xd_readwrite: operation = %s, drive = %d, buffer = 0x%X, block = %d, count = %d\n",operation == READ ? "read" : "write",drive,buffer,block,count);
#endif
spin_unlock_irq(&xd_lock);
control = p->control;
if (!xd_dma_buffer)
xd_dma_buffer = (char *)xd_dma_mem_alloc(xd_maxsectors * 0x200);
while (count) {
temp = count < xd_maxsectors ? count : xd_maxsectors;
track = block / p->sectors;
head = track % p->heads;
cylinder = track / p->heads;
sector = block % p->sectors;
#ifdef DEBUG_READWRITE
printk("xd_readwrite: drive = %d, head = %d, cylinder = %d, sector = %d, count = %d\n",drive,head,cylinder,sector,temp);
#endif
if (xd_dma_buffer) {
mode = xd_setup_dma(operation == READ ? DMA_MODE_READ : DMA_MODE_WRITE,(u_char *)(xd_dma_buffer),temp * 0x200);
real_buffer = &xd_dma_buffer;
for (i=0; i < (temp * 0x200); i++)
xd_dma_buffer[i] = buffer[i];
}
else
real_buffer = &buffer;
xd_build(cmdblk,operation == READ ? CMD_READ : CMD_WRITE,drive,head,cylinder,sector,temp & 0xFF,control);
switch (xd_command(cmdblk,mode,(u_char *)(*real_buffer),(u_char *)(*real_buffer),sense,XD_TIMEOUT)) {
case 1:
printk("xd%c: %s timeout, recalibrating drive\n",'a'+drive,(operation == READ ? "read" : "write"));
xd_recalibrate(drive);
spin_lock_irq(&xd_lock);
return -EIO;
case 2:
if (sense[0] & 0x30) {
printk("xd%c: %s - ",'a'+drive,(operation == READ ? "reading" : "writing"));
switch ((sense[0] & 0x30) >> 4) {
case 0: printk("drive error, code = 0x%X",sense[0] & 0x0F);
break;
case 1: printk("controller error, code = 0x%X",sense[0] & 0x0F);
break;
case 2: printk("command error, code = 0x%X",sense[0] & 0x0F);
break;
case 3: printk("miscellaneous error, code = 0x%X",sense[0] & 0x0F);
break;
}
}
if (sense[0] & 0x80)
printk(" - CHS = %d/%d/%d\n",((sense[2] & 0xC0) << 2) | sense[3],sense[1] & 0x1F,sense[2] & 0x3F);
else
printk(" - no valid disk address\n");
spin_lock_irq(&xd_lock);
return -EIO;
}
if (xd_dma_buffer)
for (i=0; i < (temp * 0x200); i++)
buffer[i] = xd_dma_buffer[i];
count -= temp, buffer += temp * 0x200, block += temp;
}
spin_lock_irq(&xd_lock);
return 0;
}
static void xd_recalibrate (u_char drive)
{
u_char cmdblk[6];
xd_build(cmdblk,CMD_RECALIBRATE,drive,0,0,0,0,0);
if (xd_command(cmdblk,PIO_MODE,NULL,NULL,NULL,XD_TIMEOUT * 8))
printk("xd%c: warning! error recalibrating, controller may be unstable\n", 'a'+drive);
}
static irqreturn_t xd_interrupt_handler(int irq, void *dev_id)
{
if (inb(XD_STATUS) & STAT_INTERRUPT) {
#ifdef DEBUG_OTHER
printk("xd_interrupt_handler: interrupt detected\n");
#endif
outb(0,XD_CONTROL);
wake_up(&xd_wait_int);
return IRQ_HANDLED;
}
else
printk("xd: unexpected interrupt\n");
return IRQ_NONE;
}
static u_char xd_setup_dma (u_char mode,u_char *buffer,u_int count)
{
unsigned long f;
if (nodma)
return (PIO_MODE);
if (((unsigned long) buffer & 0xFFFF0000) != (((unsigned long) buffer + count) & 0xFFFF0000)) {
#ifdef DEBUG_OTHER
printk("xd_setup_dma: using PIO, transfer overlaps 64k boundary\n");
#endif
return (PIO_MODE);
}
f=claim_dma_lock();
disable_dma(xd_dma);
clear_dma_ff(xd_dma);
set_dma_mode(xd_dma,mode);
set_dma_addr(xd_dma, (unsigned long) buffer);
set_dma_count(xd_dma,count);
release_dma_lock(f);
return (DMA_MODE);
}
static u_char *xd_build (u_char *cmdblk,u_char command,u_char drive,u_char head,u_short cylinder,u_char sector,u_char count,u_char control)
{
cmdblk[0] = command;
cmdblk[1] = ((drive & 0x07) << 5) | (head & 0x1F);
cmdblk[2] = ((cylinder & 0x300) >> 2) | (sector & 0x3F);
cmdblk[3] = cylinder & 0xFF;
cmdblk[4] = count;
cmdblk[5] = control;
return (cmdblk);
}
static void xd_watchdog (unsigned long unused)
{
xd_error = 1;
wake_up(&xd_wait_int);
}
static inline u_char xd_waitport (u_short port,u_char flags,u_char mask,u_long timeout)
{
u_long expiry = jiffies + timeout;
int success;
xdc_busy = 1;
while ((success = ((inb(port) & mask) != flags)) && time_before(jiffies, expiry))
schedule_timeout_uninterruptible(1);
xdc_busy = 0;
return (success);
}
static inline u_int xd_wait_for_IRQ (void)
{
unsigned long flags;
xd_watchdog_int.expires = jiffies + 8 * HZ;
add_timer(&xd_watchdog_int);
flags=claim_dma_lock();
enable_dma(xd_dma);
release_dma_lock(flags);
sleep_on(&xd_wait_int);
del_timer(&xd_watchdog_int);
xdc_busy = 0;
flags=claim_dma_lock();
disable_dma(xd_dma);
release_dma_lock(flags);
if (xd_error) {
printk("xd: missed IRQ - command aborted\n");
xd_error = 0;
return (1);
}
return (0);
}
static u_int xd_command (u_char *command,u_char mode,u_char *indata,u_char *outdata,u_char *sense,u_long timeout)
{
u_char cmdblk[6],csb,complete = 0;
#ifdef DEBUG_COMMAND
printk("xd_command: command = 0x%X, mode = 0x%X, indata = 0x%X, outdata = 0x%X, sense = 0x%X\n",command,mode,indata,outdata,sense);
#endif
outb(0,XD_SELECT);
outb(mode,XD_CONTROL);
if (xd_waitport(XD_STATUS,STAT_SELECT,STAT_SELECT,timeout))
return (1);
while (!complete) {
if (xd_waitport(XD_STATUS,STAT_READY,STAT_READY,timeout))
return (1);
switch (inb(XD_STATUS) & (STAT_COMMAND | STAT_INPUT)) {
case 0:
if (mode == DMA_MODE) {
if (xd_wait_for_IRQ())
return (1);
} else
outb(outdata ? *outdata++ : 0,XD_DATA);
break;
case STAT_INPUT:
if (mode == DMA_MODE) {
if (xd_wait_for_IRQ())
return (1);
} else
if (indata)
*indata++ = inb(XD_DATA);
else
inb(XD_DATA);
break;
case STAT_COMMAND:
outb(command ? *command++ : 0,XD_DATA);
break;
case STAT_COMMAND | STAT_INPUT:
complete = 1;
break;
}
}
csb = inb(XD_DATA);
if (xd_waitport(XD_STATUS,0,STAT_SELECT,timeout))
return (1);
if (csb & CSB_ERROR) {
xd_build(cmdblk,CMD_SENSE,(csb & CSB_LUN) >> 5,0,0,0,0,0);
if (xd_command(cmdblk,0,sense,NULL,NULL,XD_TIMEOUT))
printk("xd: warning! sense command failed!\n");
}
#ifdef DEBUG_COMMAND
printk("xd_command: completed with csb = 0x%X\n",csb);
#endif
return (csb & CSB_ERROR);
}
static u_char __init xd_initdrives (void (*init_drive)(u_char drive))
{
u_char cmdblk[6],i,count = 0;
for (i = 0; i < XD_MAXDRIVES; i++) {
xd_build(cmdblk,CMD_TESTREADY,i,0,0,0,0,0);
if (!xd_command(cmdblk,PIO_MODE,NULL,NULL,NULL,XD_TIMEOUT*8)) {
msleep_interruptible(XD_INIT_DISK_DELAY);
init_drive(count);
count++;
msleep_interruptible(XD_INIT_DISK_DELAY);
}
}
return (count);
}
static void __init xd_manual_geo_set (u_char drive)
{
xd_info[drive].heads = (u_char)(xd_geo[3 * drive + 1]);
xd_info[drive].cylinders = (u_short)(xd_geo[3 * drive]);
xd_info[drive].sectors = (u_char)(xd_geo[3 * drive + 2]);
}
static void __init xd_dtc_init_controller (unsigned int address)
{
switch (address) {
case 0x00000:
case 0xC8000: break;
case 0xCA000: xd_iobase = 0x324;
case 0xD0000:
case 0xD8000: break;
default: printk("xd_dtc_init_controller: unsupported BIOS address %06x\n",address);
break;
}
xd_maxsectors = 0x01;
outb(0,XD_RESET);
}
static void __init xd_dtc5150cx_init_drive (u_char drive)
{
static u_short geometry_table[][4] = {
{0x200,8,0x200,0x100},
{0x267,2,0x267,0x267},
{0x264,4,0x264,0x80},
{0x132,4,0x132,0x0},
{0x132,2,0x80, 0x132},
{0x177,8,0x177,0x0},
{0x132,8,0x84, 0x0},
{},
{0x132,6,0x80, 0x100},
{0x200,6,0x100,0x100},
{0x264,2,0x264,0x80},
{0x280,4,0x280,0x100},
{0x2B9,3,0x2B9,0x2B9},
{0x2B9,5,0x2B9,0x2B9},
{0x280,6,0x280,0x100},
{0x132,4,0x132,0x0}};
u_char n;
n = inb(XD_JUMPER);
n = (drive ? n : (n >> 2)) & 0x33;
n = (n | (n >> 2)) & 0x0F;
if (xd_geo[3*drive])
xd_manual_geo_set(drive);
else
if (n != 7) {
xd_info[drive].heads = (u_char)(geometry_table[n][1]);
xd_info[drive].cylinders = geometry_table[n][0];
xd_info[drive].sectors = 17;
#if 0
xd_info[drive].rwrite = geometry_table[n][2];
xd_info[drive].precomp = geometry_table[n][3]
xd_info[drive].ecc = 0x0B;
#endif
}
else {
printk("xd%c: undetermined drive geometry\n",'a'+drive);
return;
}
xd_info[drive].control = 5;
xd_setparam(CMD_DTCSETPARAM,drive,xd_info[drive].heads,xd_info[drive].cylinders,geometry_table[n][2],geometry_table[n][3],0x0B);
xd_recalibrate(drive);
}
static void __init xd_dtc_init_drive (u_char drive)
{
u_char cmdblk[6],buf[64];
xd_build(cmdblk,CMD_DTCGETGEOM,drive,0,0,0,0,0);
if (!xd_command(cmdblk,PIO_MODE,buf,NULL,NULL,XD_TIMEOUT * 2)) {
xd_info[drive].heads = buf[0x0A];
xd_info[drive].cylinders = ((u_short *) (buf))[0x04];
xd_info[drive].sectors = 17;
if (xd_geo[3*drive])
xd_manual_geo_set(drive);
#if 0
xd_info[drive].rwrite = ((u_short *) (buf + 1))[0x05];
xd_info[drive].precomp = ((u_short *) (buf + 1))[0x06];
xd_info[drive].ecc = buf[0x0F];
#endif
xd_info[drive].control = 0;
xd_setparam(CMD_DTCSETPARAM,drive,xd_info[drive].heads,xd_info[drive].cylinders,((u_short *) (buf + 1))[0x05],((u_short *) (buf + 1))[0x06],buf[0x0F]);
xd_build(cmdblk,CMD_DTCSETSTEP,drive,0,0,0,0,7);
if (xd_command(cmdblk,PIO_MODE,NULL,NULL,NULL,XD_TIMEOUT * 2))
printk("xd_dtc_init_drive: error setting step rate for xd%c\n", 'a'+drive);
}
else
printk("xd_dtc_init_drive: error reading geometry for xd%c\n", 'a'+drive);
}
static void __init xd_wd_init_controller (unsigned int address)
{
switch (address) {
case 0x00000:
case 0xC8000: break;
case 0xCA000: xd_iobase = 0x324; break;
case 0xCC000: xd_iobase = 0x328; break;
case 0xCE000: xd_iobase = 0x32C; break;
case 0xD0000: xd_iobase = 0x328; break;
case 0xD8000: xd_iobase = 0x32C; break;
default: printk("xd_wd_init_controller: unsupported BIOS address %06x\n",address);
break;
}
xd_maxsectors = 0x01;
outb(0,XD_RESET);
msleep(XD_INIT_DISK_DELAY);
}
static void __init xd_wd_init_drive (u_char drive)
{
static u_short geometry_table[][4] = {
{0x264,4,0x1C2,0x1C2},
{0x132,4,0x099,0x0},
{0x267,2,0x1C2,0x1C2},
{0x267,4,0x1C2,0x1C2},
{0x334,6,0x335,0x335},
{0x30E,4,0x30F,0x3DC},
{0x30E,2,0x30F,0x30F},
{0x267,4,0x268,0x268},
{0x3D5,5,0x3D6,0x3D6},
{0x3DB,7,0x3DC,0x3DC},
{0x264,4,0x265,0x265},
{0x267,4,0x268,0x268}};
u_char cmdblk[6],buf[0x200];
u_char n = 0,rll,jumper_state,use_jumper_geo;
u_char wd_1002 = (xd_sigs[xd_type].string[7] == '6');
jumper_state = ~(inb(0x322));
if (jumper_state & 0x40)
xd_irq = 9;
rll = (jumper_state & 0x30) ? (0x04 << wd_1002) : 0;
xd_build(cmdblk,CMD_READ,drive,0,0,0,1,0);
if (!xd_command(cmdblk,PIO_MODE,buf,NULL,NULL,XD_TIMEOUT * 2)) {
xd_info[drive].heads = buf[0x1AF];
xd_info[drive].cylinders = ((u_short *) (buf + 1))[0xD6];
xd_info[drive].sectors = 17;
if (xd_geo[3*drive])
xd_manual_geo_set(drive);
#if 0
xd_info[drive].rwrite = ((u_short *) (buf))[0xD8];
xd_info[drive].wprecomp = ((u_short *) (buf))[0xDA];
xd_info[drive].ecc = buf[0x1B4];
#endif
xd_info[drive].control = buf[0x1B5];
use_jumper_geo = !(xd_info[drive].heads) || !(xd_info[drive].cylinders);
if (xd_geo[3*drive]) {
xd_manual_geo_set(drive);
xd_info[drive].control = rll ? 7 : 5;
}
else if (use_jumper_geo) {
n = (((jumper_state & 0x0F) >> (drive << 1)) & 0x03) | rll;
xd_info[drive].cylinders = geometry_table[n][0];
xd_info[drive].heads = (u_char)(geometry_table[n][1]);
xd_info[drive].control = rll ? 7 : 5;
#if 0
xd_info[drive].rwrite = geometry_table[n][2];
xd_info[drive].wprecomp = geometry_table[n][3];
xd_info[drive].ecc = 0x0B;
#endif
}
if (!wd_1002) {
if (use_jumper_geo)
xd_setparam(CMD_WDSETPARAM,drive,xd_info[drive].heads,xd_info[drive].cylinders,
geometry_table[n][2],geometry_table[n][3],0x0B);
else
xd_setparam(CMD_WDSETPARAM,drive,xd_info[drive].heads,xd_info[drive].cylinders,
((u_short *) (buf))[0xD8],((u_short *) (buf))[0xDA],buf[0x1B4]);
}
if (rll & wd_1002) {
if ((xd_info[drive].cylinders *= 26,
xd_info[drive].cylinders /= 17) > 1023)
xd_info[drive].cylinders = 1023;
#if 0
xd_info[drive].rwrite *= 26;
xd_info[drive].rwrite /= 17;
xd_info[drive].wprecomp *= 26
xd_info[drive].wprecomp /= 17;
#endif
}
}
else
printk("xd_wd_init_drive: error reading geometry for xd%c\n",'a'+drive);
}
static void __init xd_seagate_init_controller (unsigned int address)
{
switch (address) {
case 0x00000:
case 0xC8000: break;
case 0xD0000: xd_iobase = 0x324; break;
case 0xD8000: xd_iobase = 0x328; break;
case 0xE0000: xd_iobase = 0x32C; break;
default: printk("xd_seagate_init_controller: unsupported BIOS address %06x\n",address);
break;
}
xd_maxsectors = 0x40;
outb(0,XD_RESET);
}
static void __init xd_seagate_init_drive (u_char drive)
{
u_char cmdblk[6],buf[0x200];
xd_build(cmdblk,CMD_ST11GETGEOM,drive,0,0,0,1,0);
if (!xd_command(cmdblk,PIO_MODE,buf,NULL,NULL,XD_TIMEOUT * 2)) {
xd_info[drive].heads = buf[0x04];
xd_info[drive].cylinders = (buf[0x02] << 8) | buf[0x03];
xd_info[drive].sectors = buf[0x05];
xd_info[drive].control = 0;
}
else
printk("xd_seagate_init_drive: error reading geometry from xd%c\n", 'a'+drive);
}
static void __init xd_omti_init_controller (unsigned int address)
{
switch (address) {
case 0x00000:
case 0xC8000: break;
case 0xD0000: xd_iobase = 0x324; break;
case 0xD8000: xd_iobase = 0x328; break;
case 0xE0000: xd_iobase = 0x32C; break;
default: printk("xd_omti_init_controller: unsupported BIOS address %06x\n",address);
break;
}
xd_maxsectors = 0x40;
outb(0,XD_RESET);
}
static void __init xd_omti_init_drive (u_char drive)
{
xd_override_init_drive(drive);
xd_info[drive].control = 2;
}
static void __init xd_xebec_init_controller (unsigned int address)
{
switch (address) {
case 0x00000:
case 0xC8000:
case 0xD0000:
case 0xD2000:
case 0xD4000:
case 0xD6000:
case 0xD8000:
case 0xDA000:
case 0xDC000:
case 0xDE000:
case 0xE0000: break;
default: printk("xd_xebec_init_controller: unsupported BIOS address %06x\n",address);
break;
}
xd_maxsectors = 0x01;
outb(0,XD_RESET);
msleep(XD_INIT_DISK_DELAY);
}
static void __init xd_xebec_init_drive (u_char drive)
{
static u_short geometry_table[][5] = {
{0x132,4,0x080,0x080,0x7},
{0x132,4,0x080,0x080,0x17},
{0x264,2,0x100,0x100,0x7},
{0x264,2,0x100,0x100,0x17},
{0x132,8,0x080,0x080,0x7},
{0x132,8,0x080,0x080,0x17},
{0x264,4,0x100,0x100,0x6},
{0x264,4,0x100,0x100,0x17},
{0x2BC,5,0x2BC,0x12C,0x6},
{0x3A5,4,0x3A5,0x3A5,0x7},
{0x26C,6,0x26C,0x26C,0x7},
{0x200,8,0x200,0x100,0x17},
{0x400,5,0x400,0x400,0x7},
{0x400,6,0x400,0x400,0x7},
{0x264,8,0x264,0x200,0x17},
{0x33E,7,0x33E,0x200,0x7}};
u_char n;
n = inb(XD_JUMPER) & 0x0F;
if (xd_geo[3*drive])
xd_manual_geo_set(drive);
else {
xd_info[drive].heads = (u_char)(geometry_table[n][1]);
xd_info[drive].cylinders = geometry_table[n][0];
xd_info[drive].sectors = 17;
#if 0
xd_info[drive].rwrite = geometry_table[n][2];
xd_info[drive].precomp = geometry_table[n][3]
xd_info[drive].ecc = 0x0B;
#endif
}
xd_info[drive].control = geometry_table[n][4];
xd_setparam(CMD_XBSETPARAM,drive,xd_info[drive].heads,xd_info[drive].cylinders,geometry_table[n][2],geometry_table[n][3],0x0B);
xd_recalibrate(drive);
}
static void __init xd_override_init_drive (u_char drive)
{
u_short min[] = { 0,0,0 },max[] = { 16,1024,64 },test[] = { 0,0,0 };
u_char cmdblk[6],i;
if (xd_geo[3*drive])
xd_manual_geo_set(drive);
else {
for (i = 0; i < 3; i++) {
while (min[i] != max[i] - 1) {
test[i] = (min[i] + max[i]) / 2;
xd_build(cmdblk,CMD_SEEK,drive,(u_char) test[0],(u_short) test[1],(u_char) test[2],0,0);
if (!xd_command(cmdblk,PIO_MODE,NULL,NULL,NULL,XD_TIMEOUT * 2))
min[i] = test[i];
else
max[i] = test[i];
}
test[i] = min[i];
}
xd_info[drive].heads = (u_char) min[0] + 1;
xd_info[drive].cylinders = (u_short) min[1] + 1;
xd_info[drive].sectors = (u_char) min[2] + 1;
}
xd_info[drive].control = 0;
}
static void __init do_xd_setup (int *integers)
{
switch (integers[0]) {
case 4: if (integers[4] < 0)
nodma = 1;
else if (integers[4] < 8)
xd_dma = integers[4];
case 3: if ((integers[3] > 0) && (integers[3] <= 0x3FC))
xd_iobase = integers[3];
case 2: if ((integers[2] > 0) && (integers[2] < 16))
xd_irq = integers[2];
case 1: xd_override = 1;
if ((integers[1] >= 0) && (integers[1] < ARRAY_SIZE(xd_sigs)))
xd_type = integers[1];
case 0: break;
default:printk("xd: too many parameters for xd\n");
}
xd_maxsectors = 0x01;
}
static void __init xd_setparam (u_char command,u_char drive,u_char heads,u_short cylinders,u_short rwrite,u_short wprecomp,u_char ecc)
{
u_char cmdblk[14];
xd_build(cmdblk,command,drive,0,0,0,0,0);
cmdblk[6] = (u_char) (cylinders >> 8) & 0x03;
cmdblk[7] = (u_char) (cylinders & 0xFF);
cmdblk[8] = heads & 0x1F;
cmdblk[9] = (u_char) (rwrite >> 8) & 0x03;
cmdblk[10] = (u_char) (rwrite & 0xFF);
cmdblk[11] = (u_char) (wprecomp >> 8) & 0x03;
cmdblk[12] = (u_char) (wprecomp & 0xFF);
cmdblk[13] = ecc;
if (xd_command(cmdblk,PIO_MODE,NULL,&cmdblk[6],NULL,XD_TIMEOUT * 2))
printk("xd: error setting characteristics for xd%c\n", 'a'+drive);
}
void cleanup_module(void)
{
int i;
unregister_blkdev(XT_DISK_MAJOR, "xd");
for (i = 0; i < xd_drives; i++) {
del_gendisk(xd_gendisk[i]);
put_disk(xd_gendisk[i]);
}
blk_cleanup_queue(xd_queue);
release_region(xd_iobase,4);
if (xd_drives) {
free_irq(xd_irq, NULL);
free_dma(xd_dma);
if (xd_dma_buffer)
xd_dma_mem_free((unsigned long)xd_dma_buffer, xd_maxsectors * 0x200);
}
}
static int __init xd_setup (char *str)
{
int ints[5];
get_options (str, ARRAY_SIZE (ints), ints);
do_xd_setup (ints);
return 1;
}
static int __init xd_manual_geo_init (char *str)
{
int i, integers[1 + 3*XD_MAXDRIVES];
get_options (str, ARRAY_SIZE (integers), integers);
if (integers[0]%3 != 0) {
printk("xd: incorrect number of parameters for xd_geo\n");
return 1;
}
for (i = 0; (i < integers[0]) && (i < 3*XD_MAXDRIVES); i++)
xd_geo[i] = integers[i+1];
return 1;
}
