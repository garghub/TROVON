static bool gdrom_is_busy(void)
{
return (__raw_readb(GDROM_ALTSTATUS_REG) & 0x80) != 0;
}
static bool gdrom_data_request(void)
{
return (__raw_readb(GDROM_ALTSTATUS_REG) & 0x88) == 8;
}
static bool gdrom_wait_clrbusy(void)
{
unsigned long timeout = jiffies + GDROM_DEFAULT_TIMEOUT;
while ((__raw_readb(GDROM_ALTSTATUS_REG) & 0x80) &&
(time_before(jiffies, timeout)))
cpu_relax();
return time_before(jiffies, timeout + 1);
}
static bool gdrom_wait_busy_sleeps(void)
{
unsigned long timeout;
timeout = jiffies + GDROM_DEFAULT_TIMEOUT;
while (!gdrom_is_busy() && time_before(jiffies, timeout))
cpu_relax();
return gdrom_wait_clrbusy();
}
static void gdrom_identifydevice(void *buf)
{
int c;
short *data = buf;
if (!gdrom_wait_clrbusy()) {
gdrom_getsense(NULL);
return;
}
__raw_writeb(GDROM_COM_IDDEV, GDROM_STATUSCOMMAND_REG);
if (!gdrom_wait_busy_sleeps()) {
gdrom_getsense(NULL);
return;
}
for (c = 0; c < 40; c++)
data[c] = __raw_readw(GDROM_DATA_REG);
}
static void gdrom_spicommand(void *spi_string, int buflen)
{
short *cmd = spi_string;
unsigned long timeout;
__raw_writeb(0x08, GDROM_ALTSTATUS_REG);
__raw_writeb(buflen & 0xFF, GDROM_BCL_REG);
__raw_writeb((buflen >> 8) & 0xFF, GDROM_BCH_REG);
__raw_writeb(0, GDROM_INTSEC_REG);
__raw_writeb(0, GDROM_SECNUM_REG);
__raw_writeb(0, GDROM_ERROR_REG);
if (!gdrom_wait_clrbusy()) {
gdrom_getsense(NULL);
return;
}
timeout = jiffies + GDROM_DEFAULT_TIMEOUT;
__raw_writeb(GDROM_COM_PACKET, GDROM_STATUSCOMMAND_REG);
while (!gdrom_data_request() && time_before(jiffies, timeout))
cpu_relax();
if (!time_before(jiffies, timeout + 1)) {
gdrom_getsense(NULL);
return;
}
outsw(GDROM_DATA_REG, cmd, 6);
}
static char gdrom_execute_diagnostic(void)
{
gdrom_hardreset(gd.cd_info);
if (!gdrom_wait_clrbusy())
return 0;
__raw_writeb(GDROM_COM_EXECDIAG, GDROM_STATUSCOMMAND_REG);
if (!gdrom_wait_busy_sleeps())
return 0;
return __raw_readb(GDROM_ERROR_REG);
}
static int gdrom_preparedisk_cmd(void)
{
struct packet_command *spin_command;
spin_command = kzalloc(sizeof(struct packet_command), GFP_KERNEL);
if (!spin_command)
return -ENOMEM;
spin_command->cmd[0] = 0x70;
spin_command->cmd[2] = 0x1f;
spin_command->buflen = 0;
gd.pending = 1;
gdrom_packetcommand(gd.cd_info, spin_command);
wait_event_interruptible_timeout(command_queue, gd.pending == 0,
GDROM_DEFAULT_TIMEOUT);
gd.pending = 0;
kfree(spin_command);
if (gd.status & 0x01) {
gdrom_getsense(NULL);
return -EIO;
}
return 0;
}
static int gdrom_readtoc_cmd(struct gdromtoc *toc, int session)
{
int tocsize;
struct packet_command *toc_command;
int err = 0;
toc_command = kzalloc(sizeof(struct packet_command), GFP_KERNEL);
if (!toc_command)
return -ENOMEM;
tocsize = sizeof(struct gdromtoc);
toc_command->cmd[0] = 0x14;
toc_command->cmd[1] = session;
toc_command->cmd[3] = tocsize >> 8;
toc_command->cmd[4] = tocsize & 0xff;
toc_command->buflen = tocsize;
if (gd.pending) {
err = -EBUSY;
goto cleanup_readtoc_final;
}
gd.pending = 1;
gdrom_packetcommand(gd.cd_info, toc_command);
wait_event_interruptible_timeout(command_queue, gd.pending == 0,
GDROM_DEFAULT_TIMEOUT);
if (gd.pending) {
err = -EINVAL;
goto cleanup_readtoc;
}
insw(GDROM_DATA_REG, toc, tocsize/2);
if (gd.status & 0x01)
err = -EINVAL;
cleanup_readtoc:
gd.pending = 0;
cleanup_readtoc_final:
kfree(toc_command);
return err;
}
static int get_entry_lba(int track)
{
return (cpu_to_be32(track & 0xffffff00) - GD_SESSION_OFFSET);
}
static int get_entry_q_ctrl(int track)
{
return (track & 0x000000f0) >> 4;
}
static int get_entry_track(int track)
{
return (track & 0x0000ff00) >> 8;
}
static int gdrom_get_last_session(struct cdrom_device_info *cd_info,
struct cdrom_multisession *ms_info)
{
int fentry, lentry, track, data, tocuse, err;
if (!gd.toc)
return -ENOMEM;
tocuse = 1;
err = gdrom_readtoc_cmd(gd.toc, 1);
if (err) {
tocuse = 0;
err = gdrom_readtoc_cmd(gd.toc, 0);
if (err) {
pr_info("Could not get CD table of contents\n");
return -ENXIO;
}
}
fentry = get_entry_track(gd.toc->first);
lentry = get_entry_track(gd.toc->last);
track = get_entry_track(gd.toc->last);
do {
data = gd.toc->entry[track - 1];
if (get_entry_q_ctrl(data))
break;
track--;
} while (track >= fentry);
if ((track > 100) || (track < get_entry_track(gd.toc->first))) {
pr_info("No data on the last session of the CD\n");
gdrom_getsense(NULL);
return -ENXIO;
}
ms_info->addr_format = CDROM_LBA;
ms_info->addr.lba = get_entry_lba(data);
ms_info->xa_flag = 1;
return 0;
}
static int gdrom_open(struct cdrom_device_info *cd_info, int purpose)
{
return gdrom_preparedisk_cmd();
}
static void gdrom_release(struct cdrom_device_info *cd_info)
{
}
static int gdrom_drivestatus(struct cdrom_device_info *cd_info, int ignore)
{
char sense = __raw_readb(GDROM_ERROR_REG);
sense &= 0xF0;
if (sense == 0)
return CDS_DISC_OK;
if (sense == 0x20)
return CDS_DRIVE_NOT_READY;
return CDS_NO_INFO;
}
static unsigned int gdrom_check_events(struct cdrom_device_info *cd_info,
unsigned int clearing, int ignore)
{
return (__raw_readb(GDROM_ERROR_REG) & 0xF0) == 0x60 ?
DISK_EVENT_MEDIA_CHANGE : 0;
}
static int gdrom_hardreset(struct cdrom_device_info *cd_info)
{
int count;
__raw_writel(0x1fffff, GDROM_RESET_REG);
for (count = 0xa0000000; count < 0xa0200000; count += 4)
__raw_readl(count);
return 0;
}
static int gdrom_packetcommand(struct cdrom_device_info *cd_info,
struct packet_command *command)
{
gdrom_spicommand(&command->cmd, command->buflen);
return 0;
}
static int gdrom_getsense(short *bufstring)
{
struct packet_command *sense_command;
short sense[5];
int sense_key;
int err = -EIO;
sense_command = kzalloc(sizeof(struct packet_command), GFP_KERNEL);
if (!sense_command)
return -ENOMEM;
sense_command->cmd[0] = 0x13;
sense_command->cmd[4] = 10;
sense_command->buflen = 10;
if (gd.pending && !gdrom_wait_clrbusy()) {
err = -EBUSY;
goto cleanup_sense_final;
}
gd.pending = 1;
gdrom_packetcommand(gd.cd_info, sense_command);
wait_event_interruptible_timeout(command_queue, gd.pending == 0,
GDROM_DEFAULT_TIMEOUT);
if (gd.pending)
goto cleanup_sense;
insw(GDROM_DATA_REG, &sense, sense_command->buflen/2);
if (sense[1] & 40) {
pr_info("Drive not ready - command aborted\n");
goto cleanup_sense;
}
sense_key = sense[1] & 0x0F;
if (sense_key < ARRAY_SIZE(sense_texts))
pr_info("%s\n", sense_texts[sense_key].text);
else
pr_err("Unknown sense key: %d\n", sense_key);
if (bufstring)
memcpy(bufstring, &sense[4], 2);
if (sense_key < 2)
err = 0;
cleanup_sense:
gd.pending = 0;
cleanup_sense_final:
kfree(sense_command);
return err;
}
static int gdrom_audio_ioctl(struct cdrom_device_info *cdi, unsigned int cmd,
void *arg)
{
return -EINVAL;
}
static int gdrom_bdops_open(struct block_device *bdev, fmode_t mode)
{
int ret;
mutex_lock(&gdrom_mutex);
ret = cdrom_open(gd.cd_info, bdev, mode);
mutex_unlock(&gdrom_mutex);
return ret;
}
static int gdrom_bdops_release(struct gendisk *disk, fmode_t mode)
{
mutex_lock(&gdrom_mutex);
cdrom_release(gd.cd_info, mode);
mutex_unlock(&gdrom_mutex);
return 0;
}
static unsigned int gdrom_bdops_check_events(struct gendisk *disk,
unsigned int clearing)
{
return cdrom_check_events(gd.cd_info, clearing);
}
static int gdrom_bdops_ioctl(struct block_device *bdev, fmode_t mode,
unsigned cmd, unsigned long arg)
{
int ret;
mutex_lock(&gdrom_mutex);
ret = cdrom_ioctl(gd.cd_info, bdev, mode, cmd, arg);
mutex_unlock(&gdrom_mutex);
return ret;
}
static irqreturn_t gdrom_command_interrupt(int irq, void *dev_id)
{
gd.status = __raw_readb(GDROM_STATUSCOMMAND_REG);
if (gd.pending != 1)
return IRQ_HANDLED;
gd.pending = 0;
wake_up_interruptible(&command_queue);
return IRQ_HANDLED;
}
static irqreturn_t gdrom_dma_interrupt(int irq, void *dev_id)
{
gd.status = __raw_readb(GDROM_STATUSCOMMAND_REG);
if (gd.transfer != 1)
return IRQ_HANDLED;
gd.transfer = 0;
wake_up_interruptible(&request_queue);
return IRQ_HANDLED;
}
static int __devinit gdrom_set_interrupt_handlers(void)
{
int err;
err = request_irq(HW_EVENT_GDROM_CMD, gdrom_command_interrupt,
IRQF_DISABLED, "gdrom_command", &gd);
if (err)
return err;
err = request_irq(HW_EVENT_GDROM_DMA, gdrom_dma_interrupt,
IRQF_DISABLED, "gdrom_dma", &gd);
if (err)
free_irq(HW_EVENT_GDROM_CMD, &gd);
return err;
}
static void gdrom_readdisk_dma(struct work_struct *work)
{
int err, block, block_cnt;
struct packet_command *read_command;
struct list_head *elem, *next;
struct request *req;
unsigned long timeout;
if (list_empty(&gdrom_deferred))
return;
read_command = kzalloc(sizeof(struct packet_command), GFP_KERNEL);
if (!read_command)
return;
read_command->cmd[0] = 0x30;
read_command->cmd[1] = 0x20;
spin_lock(&gdrom_lock);
list_for_each_safe(elem, next, &gdrom_deferred) {
req = list_entry(elem, struct request, queuelist);
spin_unlock(&gdrom_lock);
block = blk_rq_pos(req)/GD_TO_BLK + GD_SESSION_OFFSET;
block_cnt = blk_rq_sectors(req)/GD_TO_BLK;
__raw_writel(virt_to_phys(req->buffer), GDROM_DMA_STARTADDR_REG);
__raw_writel(block_cnt * GDROM_HARD_SECTOR, GDROM_DMA_LENGTH_REG);
__raw_writel(1, GDROM_DMA_DIRECTION_REG);
__raw_writel(1, GDROM_DMA_ENABLE_REG);
read_command->cmd[2] = (block >> 16) & 0xFF;
read_command->cmd[3] = (block >> 8) & 0xFF;
read_command->cmd[4] = block & 0xFF;
read_command->cmd[8] = (block_cnt >> 16) & 0xFF;
read_command->cmd[9] = (block_cnt >> 8) & 0xFF;
read_command->cmd[10] = block_cnt & 0xFF;
__raw_writeb(1, GDROM_ERROR_REG);
__raw_writeb(0, GDROM_SECNUM_REG);
__raw_writeb(0, GDROM_BCL_REG);
__raw_writeb(0, GDROM_BCH_REG);
__raw_writeb(0, GDROM_DSEL_REG);
__raw_writeb(0, GDROM_INTSEC_REG);
timeout = jiffies + HZ / 2;
while (gdrom_is_busy() && time_before(jiffies, timeout))
cpu_relax();
__raw_writeb(GDROM_COM_PACKET, GDROM_STATUSCOMMAND_REG);
timeout = jiffies + HZ / 2;
while (gdrom_is_busy() && time_before(jiffies, timeout))
cpu_relax();
gd.pending = 1;
gd.transfer = 1;
outsw(GDROM_DATA_REG, &read_command->cmd, 6);
timeout = jiffies + HZ / 2;
while (__raw_readb(GDROM_DMA_STATUS_REG) &&
time_before(jiffies, timeout))
cpu_relax();
__raw_writeb(1, GDROM_DMA_STATUS_REG);
wait_event_interruptible_timeout(request_queue,
gd.transfer == 0, GDROM_DEFAULT_TIMEOUT);
err = gd.transfer ? -EIO : 0;
gd.transfer = 0;
gd.pending = 0;
spin_lock(&gdrom_lock);
list_del_init(&req->queuelist);
__blk_end_request_all(req, err);
}
spin_unlock(&gdrom_lock);
kfree(read_command);
}
static void gdrom_request(struct request_queue *rq)
{
struct request *req;
while ((req = blk_fetch_request(rq)) != NULL) {
if (req->cmd_type != REQ_TYPE_FS) {
printk(KERN_DEBUG "gdrom: Non-fs request ignored\n");
__blk_end_request_all(req, -EIO);
continue;
}
if (rq_data_dir(req) != READ) {
pr_notice("Read only device - write request ignored\n");
__blk_end_request_all(req, -EIO);
continue;
}
list_add_tail(&req->queuelist, &gdrom_deferred);
schedule_work(&work);
}
}
static int __devinit gdrom_outputversion(void)
{
struct gdrom_id *id;
char *model_name, *manuf_name, *firmw_ver;
int err = -ENOMEM;
id = kzalloc(sizeof(struct gdrom_id), GFP_KERNEL);
if (!id)
return err;
gdrom_identifydevice(id);
model_name = kstrndup(id->modname, 16, GFP_KERNEL);
if (!model_name)
goto free_id;
manuf_name = kstrndup(id->mname, 16, GFP_KERNEL);
if (!manuf_name)
goto free_model_name;
firmw_ver = kstrndup(id->firmver, 16, GFP_KERNEL);
if (!firmw_ver)
goto free_manuf_name;
pr_info("%s from %s with firmware %s\n",
model_name, manuf_name, firmw_ver);
err = 0;
kfree(firmw_ver);
free_manuf_name:
kfree(manuf_name);
free_model_name:
kfree(model_name);
free_id:
kfree(id);
return err;
}
static int __devinit gdrom_init_dma_mode(void)
{
__raw_writeb(0x13, GDROM_ERROR_REG);
__raw_writeb(0x22, GDROM_INTSEC_REG);
if (!gdrom_wait_clrbusy())
return -EBUSY;
__raw_writeb(0xEF, GDROM_STATUSCOMMAND_REG);
if (!gdrom_wait_busy_sleeps())
return -EBUSY;
__raw_writel(0x8843407F, GDROM_DMA_ACCESS_CTRL_REG);
__raw_writel(9, GDROM_DMA_WAIT_REG);
return 0;
}
static void __devinit probe_gdrom_setupcd(void)
{
gd.cd_info->ops = &gdrom_ops;
gd.cd_info->capacity = 1;
strcpy(gd.cd_info->name, GDROM_DEV_NAME);
gd.cd_info->mask = CDC_CLOSE_TRAY|CDC_OPEN_TRAY|CDC_LOCK|
CDC_SELECT_DISC;
}
static void __devinit probe_gdrom_setupdisk(void)
{
gd.disk->major = gdrom_major;
gd.disk->first_minor = 1;
gd.disk->minors = 1;
strcpy(gd.disk->disk_name, GDROM_DEV_NAME);
}
static int __devinit probe_gdrom_setupqueue(void)
{
blk_queue_logical_block_size(gd.gdrom_rq, GDROM_HARD_SECTOR);
blk_queue_max_segments(gd.gdrom_rq, 1);
blk_queue_max_segment_size(gd.gdrom_rq, 0x40000);
gd.disk->queue = gd.gdrom_rq;
return gdrom_init_dma_mode();
}
static int __devinit probe_gdrom(struct platform_device *devptr)
{
int err;
if (gdrom_execute_diagnostic() != 1) {
pr_warning("ATA Probe for GDROM failed\n");
return -ENODEV;
}
if (gdrom_outputversion())
return -ENOMEM;
gdrom_major = register_blkdev(0, GDROM_DEV_NAME);
if (gdrom_major <= 0)
return gdrom_major;
pr_info("Registered with major number %d\n",
gdrom_major);
gd.cd_info = kzalloc(sizeof(struct cdrom_device_info), GFP_KERNEL);
if (!gd.cd_info) {
err = -ENOMEM;
goto probe_fail_no_mem;
}
probe_gdrom_setupcd();
gd.disk = alloc_disk(1);
if (!gd.disk) {
err = -ENODEV;
goto probe_fail_no_disk;
}
probe_gdrom_setupdisk();
if (register_cdrom(gd.cd_info)) {
err = -ENODEV;
goto probe_fail_cdrom_register;
}
gd.disk->fops = &gdrom_bdops;
err = gdrom_set_interrupt_handlers();
if (err)
goto probe_fail_cmdirq_register;
gd.gdrom_rq = blk_init_queue(gdrom_request, &gdrom_lock);
if (!gd.gdrom_rq)
goto probe_fail_requestq;
err = probe_gdrom_setupqueue();
if (err)
goto probe_fail_toc;
gd.toc = kzalloc(sizeof(struct gdromtoc), GFP_KERNEL);
if (!gd.toc)
goto probe_fail_toc;
add_disk(gd.disk);
return 0;
probe_fail_toc:
blk_cleanup_queue(gd.gdrom_rq);
probe_fail_requestq:
free_irq(HW_EVENT_GDROM_DMA, &gd);
free_irq(HW_EVENT_GDROM_CMD, &gd);
probe_fail_cmdirq_register:
probe_fail_cdrom_register:
del_gendisk(gd.disk);
probe_fail_no_disk:
kfree(gd.cd_info);
unregister_blkdev(gdrom_major, GDROM_DEV_NAME);
gdrom_major = 0;
probe_fail_no_mem:
pr_warning("Probe failed - error is 0x%X\n", err);
return err;
}
static int __devexit remove_gdrom(struct platform_device *devptr)
{
flush_work(&work);
blk_cleanup_queue(gd.gdrom_rq);
free_irq(HW_EVENT_GDROM_CMD, &gd);
free_irq(HW_EVENT_GDROM_DMA, &gd);
del_gendisk(gd.disk);
if (gdrom_major)
unregister_blkdev(gdrom_major, GDROM_DEV_NAME);
unregister_cdrom(gd.cd_info);
return 0;
}
static int __init init_gdrom(void)
{
int rc;
gd.toc = NULL;
rc = platform_driver_register(&gdrom_driver);
if (rc)
return rc;
pd = platform_device_register_simple(GDROM_DEV_NAME, -1, NULL, 0);
if (IS_ERR(pd)) {
platform_driver_unregister(&gdrom_driver);
return PTR_ERR(pd);
}
return 0;
}
static void __exit exit_gdrom(void)
{
platform_device_unregister(pd);
platform_driver_unregister(&gdrom_driver);
kfree(gd.toc);
}
