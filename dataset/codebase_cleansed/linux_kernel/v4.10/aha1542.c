static inline void aha1542_intr_reset(u16 base)
{
outb(IRST, CONTROL(base));
}
static inline bool wait_mask(u16 port, u8 mask, u8 allof, u8 noneof, int timeout)
{
bool delayed = true;
if (timeout == 0) {
timeout = 3000000;
delayed = false;
}
while (1) {
u8 bits = inb(port) & mask;
if ((bits & allof) == allof && ((bits & noneof) == 0))
break;
if (delayed)
mdelay(1);
if (--timeout == 0)
return false;
}
return true;
}
static int aha1542_outb(unsigned int base, u8 val)
{
if (!wait_mask(STATUS(base), CDF, 0, CDF, 0))
return 1;
outb(val, DATA(base));
return 0;
}
static int aha1542_out(unsigned int base, u8 *buf, int len)
{
while (len--) {
if (!wait_mask(STATUS(base), CDF, 0, CDF, 0))
return 1;
outb(*buf++, DATA(base));
}
if (!wait_mask(INTRFLAGS(base), INTRMASK, HACC, 0, 0))
return 1;
return 0;
}
static int aha1542_in(unsigned int base, u8 *buf, int len, int timeout)
{
while (len--) {
if (!wait_mask(STATUS(base), DF, DF, 0, timeout))
return 1;
*buf++ = inb(DATA(base));
}
return 0;
}
static int makecode(unsigned hosterr, unsigned scsierr)
{
switch (hosterr) {
case 0x0:
case 0xa:
case 0xb:
hosterr = 0;
break;
case 0x11:
hosterr = DID_TIME_OUT;
break;
case 0x12:
case 0x13:
case 0x15:
case 0x16:
case 0x17:
case 0x18:
case 0x19:
case 0x1a:
#ifdef DEBUG
printk("Aha1542: %x %x\n", hosterr, scsierr);
#endif
hosterr = DID_ERROR;
break;
case 0x14:
hosterr = DID_RESET;
break;
default:
printk(KERN_ERR "aha1542: makecode: unknown hoststatus %x\n", hosterr);
break;
}
return scsierr | (hosterr << 16);
}
static int aha1542_test_port(struct Scsi_Host *sh)
{
u8 inquiry_result[4];
int i;
if (inb(STATUS(sh->io_port)) == 0xff)
return 0;
aha1542_intr_reset(sh->io_port);
outb(SRST | IRST , CONTROL(sh->io_port));
mdelay(20);
if (!wait_mask(STATUS(sh->io_port), STATMASK, INIT | IDLE, STST | DIAGF | INVDCMD | DF | CDF, 0))
return 0;
if (inb(INTRFLAGS(sh->io_port)) & INTRMASK)
return 0;
aha1542_outb(sh->io_port, CMD_INQUIRY);
for (i = 0; i < 4; i++) {
if (!wait_mask(STATUS(sh->io_port), DF, DF, 0, 0))
return 0;
inquiry_result[i] = inb(DATA(sh->io_port));
}
if (inb(STATUS(sh->io_port)) & DF)
return 0;
if (!wait_mask(INTRFLAGS(sh->io_port), HACC, HACC, 0, 0))
return 0;
outb(IRST, CONTROL(sh->io_port));
return 1;
}
static irqreturn_t aha1542_interrupt(int irq, void *dev_id)
{
struct Scsi_Host *sh = dev_id;
struct aha1542_hostdata *aha1542 = shost_priv(sh);
void (*my_done)(struct scsi_cmnd *) = NULL;
int errstatus, mbi, mbo, mbistatus;
int number_serviced;
unsigned long flags;
struct scsi_cmnd *tmp_cmd;
int flag;
struct mailbox *mb = aha1542->mb;
struct ccb *ccb = aha1542->ccb;
#ifdef DEBUG
{
flag = inb(INTRFLAGS(sh->io_port));
shost_printk(KERN_DEBUG, sh, "aha1542_intr_handle: ");
if (!(flag & ANYINTR))
printk("no interrupt?");
if (flag & MBIF)
printk("MBIF ");
if (flag & MBOA)
printk("MBOF ");
if (flag & HACC)
printk("HACC ");
if (flag & SCRD)
printk("SCRD ");
printk("status %02x\n", inb(STATUS(sh->io_port)));
};
#endif
number_serviced = 0;
spin_lock_irqsave(sh->host_lock, flags);
while (1) {
flag = inb(INTRFLAGS(sh->io_port));
if (flag & ~MBIF) {
if (flag & MBOA)
printk("MBOF ");
if (flag & HACC)
printk("HACC ");
if (flag & SCRD)
printk("SCRD ");
}
aha1542_intr_reset(sh->io_port);
mbi = aha1542->aha1542_last_mbi_used + 1;
if (mbi >= 2 * AHA1542_MAILBOXES)
mbi = AHA1542_MAILBOXES;
do {
if (mb[mbi].status != 0)
break;
mbi++;
if (mbi >= 2 * AHA1542_MAILBOXES)
mbi = AHA1542_MAILBOXES;
} while (mbi != aha1542->aha1542_last_mbi_used);
if (mb[mbi].status == 0) {
spin_unlock_irqrestore(sh->host_lock, flags);
if (!number_serviced)
shost_printk(KERN_WARNING, sh, "interrupt received, but no mail.\n");
return IRQ_HANDLED;
};
mbo = (scsi2int(mb[mbi].ccbptr) - (isa_virt_to_bus(&ccb[0]))) / sizeof(struct ccb);
mbistatus = mb[mbi].status;
mb[mbi].status = 0;
aha1542->aha1542_last_mbi_used = mbi;
#ifdef DEBUG
if (ccb[mbo].tarstat | ccb[mbo].hastat)
shost_printk(KERN_DEBUG, sh, "aha1542_command: returning %x (status %d)\n",
ccb[mbo].tarstat + ((int) ccb[mbo].hastat << 16), mb[mbi].status);
#endif
if (mbistatus == 3)
continue;
#ifdef DEBUG
shost_printk(KERN_DEBUG, sh, "...done %d %d\n", mbo, mbi);
#endif
tmp_cmd = aha1542->int_cmds[mbo];
if (!tmp_cmd || !tmp_cmd->scsi_done) {
spin_unlock_irqrestore(sh->host_lock, flags);
shost_printk(KERN_WARNING, sh, "Unexpected interrupt\n");
shost_printk(KERN_WARNING, sh, "tarstat=%x, hastat=%x idlun=%x ccb#=%d\n", ccb[mbo].tarstat,
ccb[mbo].hastat, ccb[mbo].idlun, mbo);
return IRQ_HANDLED;
}
my_done = tmp_cmd->scsi_done;
kfree(tmp_cmd->host_scribble);
tmp_cmd->host_scribble = NULL;
if (ccb[mbo].tarstat == 2)
memcpy(tmp_cmd->sense_buffer, &ccb[mbo].cdb[ccb[mbo].cdblen],
SCSI_SENSE_BUFFERSIZE);
if (mbistatus != 1)
errstatus = makecode(ccb[mbo].hastat, ccb[mbo].tarstat);
else
errstatus = 0;
#ifdef DEBUG
if (errstatus)
shost_printk(KERN_DEBUG, sh, "(aha1542 error:%x %x %x) ", errstatus,
ccb[mbo].hastat, ccb[mbo].tarstat);
if (ccb[mbo].tarstat == 2)
print_hex_dump_bytes("sense: ", DUMP_PREFIX_NONE, &ccb[mbo].cdb[ccb[mbo].cdblen], 12);
if (errstatus)
printk("aha1542_intr_handle: returning %6x\n", errstatus);
#endif
tmp_cmd->result = errstatus;
aha1542->int_cmds[mbo] = NULL;
my_done(tmp_cmd);
number_serviced++;
};
}
static int aha1542_queuecommand(struct Scsi_Host *sh, struct scsi_cmnd *cmd)
{
struct aha1542_hostdata *aha1542 = shost_priv(sh);
u8 direction;
u8 target = cmd->device->id;
u8 lun = cmd->device->lun;
unsigned long flags;
int bufflen = scsi_bufflen(cmd);
int mbo, sg_count;
struct mailbox *mb = aha1542->mb;
struct ccb *ccb = aha1542->ccb;
struct chain *cptr;
if (*cmd->cmnd == REQUEST_SENSE) {
cmd->result = 0;
cmd->scsi_done(cmd);
return 0;
}
#ifdef DEBUG
{
int i = -1;
if (*cmd->cmnd == READ_10 || *cmd->cmnd == WRITE_10)
i = xscsi2int(cmd->cmnd + 2);
else if (*cmd->cmnd == READ_6 || *cmd->cmnd == WRITE_6)
i = scsi2int(cmd->cmnd + 2);
shost_printk(KERN_DEBUG, sh, "aha1542_queuecommand: dev %d cmd %02x pos %d len %d",
target, *cmd->cmnd, i, bufflen);
print_hex_dump_bytes("command: ", DUMP_PREFIX_NONE, cmd->cmnd, cmd->cmd_len);
}
#endif
if (bufflen) {
sg_count = scsi_sg_count(cmd);
cptr = kmalloc(sizeof(*cptr) * sg_count, GFP_KERNEL | GFP_DMA);
if (!cptr)
return SCSI_MLQUEUE_HOST_BUSY;
} else {
sg_count = 0;
cptr = NULL;
}
spin_lock_irqsave(sh->host_lock, flags);
mbo = aha1542->aha1542_last_mbo_used + 1;
if (mbo >= AHA1542_MAILBOXES)
mbo = 0;
do {
if (mb[mbo].status == 0 && aha1542->int_cmds[mbo] == NULL)
break;
mbo++;
if (mbo >= AHA1542_MAILBOXES)
mbo = 0;
} while (mbo != aha1542->aha1542_last_mbo_used);
if (mb[mbo].status || aha1542->int_cmds[mbo])
panic("Unable to find empty mailbox for aha1542.\n");
aha1542->int_cmds[mbo] = cmd;
aha1542->aha1542_last_mbo_used = mbo;
#ifdef DEBUG
shost_printk(KERN_DEBUG, sh, "Sending command (%d %p)...", mbo, cmd->scsi_done);
#endif
any2scsi(mb[mbo].ccbptr, isa_virt_to_bus(&ccb[mbo]));
memset(&ccb[mbo], 0, sizeof(struct ccb));
ccb[mbo].cdblen = cmd->cmd_len;
direction = 0;
if (*cmd->cmnd == READ_10 || *cmd->cmnd == READ_6)
direction = 8;
else if (*cmd->cmnd == WRITE_10 || *cmd->cmnd == WRITE_6)
direction = 16;
memcpy(ccb[mbo].cdb, cmd->cmnd, ccb[mbo].cdblen);
if (bufflen) {
struct scatterlist *sg;
int i;
ccb[mbo].op = 2;
cmd->host_scribble = (void *)cptr;
scsi_for_each_sg(cmd, sg, sg_count, i) {
any2scsi(cptr[i].dataptr, isa_page_to_bus(sg_page(sg))
+ sg->offset);
any2scsi(cptr[i].datalen, sg->length);
};
any2scsi(ccb[mbo].datalen, sg_count * sizeof(struct chain));
any2scsi(ccb[mbo].dataptr, isa_virt_to_bus(cptr));
#ifdef DEBUG
shost_printk(KERN_DEBUG, sh, "cptr %p: ", cptr);
print_hex_dump_bytes("cptr: ", DUMP_PREFIX_NONE, cptr, 18);
#endif
} else {
ccb[mbo].op = 0;
cmd->host_scribble = NULL;
any2scsi(ccb[mbo].datalen, 0);
any2scsi(ccb[mbo].dataptr, 0);
};
ccb[mbo].idlun = (target & 7) << 5 | direction | (lun & 7);
ccb[mbo].rsalen = 16;
ccb[mbo].linkptr[0] = ccb[mbo].linkptr[1] = ccb[mbo].linkptr[2] = 0;
ccb[mbo].commlinkid = 0;
#ifdef DEBUG
print_hex_dump_bytes("sending: ", DUMP_PREFIX_NONE, &ccb[mbo], sizeof(ccb[mbo]) - 10);
printk("aha1542_queuecommand: now waiting for interrupt ");
#endif
mb[mbo].status = 1;
aha1542_outb(cmd->device->host->io_port, CMD_START_SCSI);
spin_unlock_irqrestore(sh->host_lock, flags);
return 0;
}
static void setup_mailboxes(struct Scsi_Host *sh)
{
struct aha1542_hostdata *aha1542 = shost_priv(sh);
int i;
struct mailbox *mb = aha1542->mb;
struct ccb *ccb = aha1542->ccb;
u8 mb_cmd[5] = { CMD_MBINIT, AHA1542_MAILBOXES, 0, 0, 0};
for (i = 0; i < AHA1542_MAILBOXES; i++) {
mb[i].status = mb[AHA1542_MAILBOXES + i].status = 0;
any2scsi(mb[i].ccbptr, isa_virt_to_bus(&ccb[i]));
};
aha1542_intr_reset(sh->io_port);
any2scsi((mb_cmd + 2), isa_virt_to_bus(mb));
if (aha1542_out(sh->io_port, mb_cmd, 5))
shost_printk(KERN_ERR, sh, "failed setting up mailboxes\n");
aha1542_intr_reset(sh->io_port);
}
static int aha1542_getconfig(struct Scsi_Host *sh)
{
u8 inquiry_result[3];
int i;
i = inb(STATUS(sh->io_port));
if (i & DF) {
i = inb(DATA(sh->io_port));
};
aha1542_outb(sh->io_port, CMD_RETCONF);
aha1542_in(sh->io_port, inquiry_result, 3, 0);
if (!wait_mask(INTRFLAGS(sh->io_port), INTRMASK, HACC, 0, 0))
shost_printk(KERN_ERR, sh, "error querying board settings\n");
aha1542_intr_reset(sh->io_port);
switch (inquiry_result[0]) {
case 0x80:
sh->dma_channel = 7;
break;
case 0x40:
sh->dma_channel = 6;
break;
case 0x20:
sh->dma_channel = 5;
break;
case 0x01:
sh->dma_channel = 0;
break;
case 0:
sh->dma_channel = 0xFF;
break;
default:
shost_printk(KERN_ERR, sh, "Unable to determine DMA channel.\n");
return -1;
};
switch (inquiry_result[1]) {
case 0x40:
sh->irq = 15;
break;
case 0x20:
sh->irq = 14;
break;
case 0x8:
sh->irq = 12;
break;
case 0x4:
sh->irq = 11;
break;
case 0x2:
sh->irq = 10;
break;
case 0x1:
sh->irq = 9;
break;
default:
shost_printk(KERN_ERR, sh, "Unable to determine IRQ level.\n");
return -1;
};
sh->this_id = inquiry_result[2] & 7;
return 0;
}
static int aha1542_mbenable(struct Scsi_Host *sh)
{
static u8 mbenable_cmd[3];
static u8 mbenable_result[2];
int retval;
retval = BIOS_TRANSLATION_6432;
aha1542_outb(sh->io_port, CMD_EXTBIOS);
if (aha1542_in(sh->io_port, mbenable_result, 2, 100))
return retval;
if (!wait_mask(INTRFLAGS(sh->io_port), INTRMASK, HACC, 0, 100))
goto fail;
aha1542_intr_reset(sh->io_port);
if ((mbenable_result[0] & 0x08) || mbenable_result[1]) {
mbenable_cmd[0] = CMD_MBENABLE;
mbenable_cmd[1] = 0;
mbenable_cmd[2] = mbenable_result[1];
if ((mbenable_result[0] & 0x08) && (mbenable_result[1] & 0x03))
retval = BIOS_TRANSLATION_25563;
if (aha1542_out(sh->io_port, mbenable_cmd, 3))
goto fail;
};
while (0) {
fail:
shost_printk(KERN_ERR, sh, "Mailbox init failed\n");
}
aha1542_intr_reset(sh->io_port);
return retval;
}
static int aha1542_query(struct Scsi_Host *sh)
{
struct aha1542_hostdata *aha1542 = shost_priv(sh);
u8 inquiry_result[4];
int i;
i = inb(STATUS(sh->io_port));
if (i & DF) {
i = inb(DATA(sh->io_port));
};
aha1542_outb(sh->io_port, CMD_INQUIRY);
aha1542_in(sh->io_port, inquiry_result, 4, 0);
if (!wait_mask(INTRFLAGS(sh->io_port), INTRMASK, HACC, 0, 0))
shost_printk(KERN_ERR, sh, "error querying card type\n");
aha1542_intr_reset(sh->io_port);
aha1542->bios_translation = BIOS_TRANSLATION_6432;
if (inquiry_result[0] == 0x43) {
shost_printk(KERN_INFO, sh, "Emulation mode not supported for AHA-1740 hardware, use aha1740 driver instead.\n");
return 1;
};
aha1542->bios_translation = aha1542_mbenable(sh);
return 0;
}
static u8 dma_speed_hw(int dma_speed)
{
switch (dma_speed) {
case 5:
return 0x00;
case 6:
return 0x04;
case 7:
return 0x01;
case 8:
return 0x02;
case 10:
return 0x03;
}
return 0xff;
}
static void aha1542_set_bus_times(struct Scsi_Host *sh, int bus_on, int bus_off, int dma_speed)
{
if (bus_on > 0) {
u8 oncmd[] = { CMD_BUSON_TIME, clamp(bus_on, 2, 15) };
aha1542_intr_reset(sh->io_port);
if (aha1542_out(sh->io_port, oncmd, 2))
goto fail;
}
if (bus_off > 0) {
u8 offcmd[] = { CMD_BUSOFF_TIME, clamp(bus_off, 1, 64) };
aha1542_intr_reset(sh->io_port);
if (aha1542_out(sh->io_port, offcmd, 2))
goto fail;
}
if (dma_speed_hw(dma_speed) != 0xff) {
u8 dmacmd[] = { CMD_DMASPEED, dma_speed_hw(dma_speed) };
aha1542_intr_reset(sh->io_port);
if (aha1542_out(sh->io_port, dmacmd, 2))
goto fail;
}
aha1542_intr_reset(sh->io_port);
return;
fail:
shost_printk(KERN_ERR, sh, "setting bus on/off-time failed\n");
aha1542_intr_reset(sh->io_port);
}
static struct Scsi_Host *aha1542_hw_init(struct scsi_host_template *tpnt, struct device *pdev, int indx)
{
unsigned int base_io = io[indx];
struct Scsi_Host *sh;
struct aha1542_hostdata *aha1542;
char dma_info[] = "no DMA";
if (base_io == 0)
return NULL;
if (!request_region(base_io, AHA1542_REGION_SIZE, "aha1542"))
return NULL;
sh = scsi_host_alloc(tpnt, sizeof(struct aha1542_hostdata));
if (!sh)
goto release;
aha1542 = shost_priv(sh);
sh->unique_id = base_io;
sh->io_port = base_io;
sh->n_io_port = AHA1542_REGION_SIZE;
aha1542->aha1542_last_mbi_used = 2 * AHA1542_MAILBOXES - 1;
aha1542->aha1542_last_mbo_used = AHA1542_MAILBOXES - 1;
if (!aha1542_test_port(sh))
goto unregister;
aha1542_set_bus_times(sh, bus_on[indx], bus_off[indx], dma_speed[indx]);
if (aha1542_query(sh))
goto unregister;
if (aha1542_getconfig(sh) == -1)
goto unregister;
if (sh->dma_channel != 0xFF)
snprintf(dma_info, sizeof(dma_info), "DMA %d", sh->dma_channel);
shost_printk(KERN_INFO, sh, "Adaptec AHA-1542 (SCSI-ID %d) at IO 0x%x, IRQ %d, %s\n",
sh->this_id, base_io, sh->irq, dma_info);
if (aha1542->bios_translation == BIOS_TRANSLATION_25563)
shost_printk(KERN_INFO, sh, "Using extended bios translation\n");
setup_mailboxes(sh);
if (request_irq(sh->irq, aha1542_interrupt, 0, "aha1542", sh)) {
shost_printk(KERN_ERR, sh, "Unable to allocate IRQ.\n");
goto unregister;
}
if (sh->dma_channel != 0xFF) {
if (request_dma(sh->dma_channel, "aha1542")) {
shost_printk(KERN_ERR, sh, "Unable to allocate DMA channel.\n");
goto free_irq;
}
if (sh->dma_channel == 0 || sh->dma_channel >= 5) {
set_dma_mode(sh->dma_channel, DMA_MODE_CASCADE);
enable_dma(sh->dma_channel);
}
}
if (scsi_add_host(sh, pdev))
goto free_dma;
scsi_scan_host(sh);
return sh;
free_dma:
if (sh->dma_channel != 0xff)
free_dma(sh->dma_channel);
free_irq:
free_irq(sh->irq, sh);
unregister:
scsi_host_put(sh);
release:
release_region(base_io, AHA1542_REGION_SIZE);
return NULL;
}
static int aha1542_release(struct Scsi_Host *sh)
{
scsi_remove_host(sh);
if (sh->dma_channel != 0xff)
free_dma(sh->dma_channel);
if (sh->irq)
free_irq(sh->irq, sh);
if (sh->io_port && sh->n_io_port)
release_region(sh->io_port, sh->n_io_port);
scsi_host_put(sh);
return 0;
}
static int aha1542_dev_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *sh = cmd->device->host;
struct aha1542_hostdata *aha1542 = shost_priv(sh);
unsigned long flags;
struct mailbox *mb = aha1542->mb;
u8 target = cmd->device->id;
u8 lun = cmd->device->lun;
int mbo;
struct ccb *ccb = aha1542->ccb;
spin_lock_irqsave(sh->host_lock, flags);
mbo = aha1542->aha1542_last_mbo_used + 1;
if (mbo >= AHA1542_MAILBOXES)
mbo = 0;
do {
if (mb[mbo].status == 0 && aha1542->int_cmds[mbo] == NULL)
break;
mbo++;
if (mbo >= AHA1542_MAILBOXES)
mbo = 0;
} while (mbo != aha1542->aha1542_last_mbo_used);
if (mb[mbo].status || aha1542->int_cmds[mbo])
panic("Unable to find empty mailbox for aha1542.\n");
aha1542->int_cmds[mbo] = cmd;
aha1542->aha1542_last_mbo_used = mbo;
any2scsi(mb[mbo].ccbptr, isa_virt_to_bus(&ccb[mbo]));
memset(&ccb[mbo], 0, sizeof(struct ccb));
ccb[mbo].op = 0x81;
ccb[mbo].idlun = (target & 7) << 5 | (lun & 7);
ccb[mbo].linkptr[0] = ccb[mbo].linkptr[1] = ccb[mbo].linkptr[2] = 0;
ccb[mbo].commlinkid = 0;
aha1542_outb(sh->io_port, CMD_START_SCSI);
spin_unlock_irqrestore(sh->host_lock, flags);
scmd_printk(KERN_WARNING, cmd,
"Trying device reset for target\n");
return SUCCESS;
}
static int aha1542_reset(struct scsi_cmnd *cmd, u8 reset_cmd)
{
struct Scsi_Host *sh = cmd->device->host;
struct aha1542_hostdata *aha1542 = shost_priv(sh);
unsigned long flags;
int i;
spin_lock_irqsave(sh->host_lock, flags);
outb(reset_cmd, CONTROL(cmd->device->host->io_port));
if (!wait_mask(STATUS(cmd->device->host->io_port),
STATMASK, IDLE, STST | DIAGF | INVDCMD | DF | CDF, 0)) {
spin_unlock_irqrestore(sh->host_lock, flags);
return FAILED;
}
if (reset_cmd & HRST)
setup_mailboxes(cmd->device->host);
shost_printk(KERN_WARNING, cmd->device->host, "Sent BUS RESET to scsi host %d\n", cmd->device->host->host_no);
for (i = 0; i < AHA1542_MAILBOXES; i++) {
if (aha1542->int_cmds[i] != NULL) {
struct scsi_cmnd *tmp_cmd;
tmp_cmd = aha1542->int_cmds[i];
if (tmp_cmd->device->soft_reset) {
continue;
}
kfree(tmp_cmd->host_scribble);
tmp_cmd->host_scribble = NULL;
aha1542->int_cmds[i] = NULL;
aha1542->mb[i].status = 0;
}
}
spin_unlock_irqrestore(sh->host_lock, flags);
return SUCCESS;
}
static int aha1542_bus_reset(struct scsi_cmnd *cmd)
{
return aha1542_reset(cmd, SCRST);
}
static int aha1542_host_reset(struct scsi_cmnd *cmd)
{
return aha1542_reset(cmd, HRST | SCRST);
}
static int aha1542_biosparam(struct scsi_device *sdev,
struct block_device *bdev, sector_t capacity, int geom[])
{
struct aha1542_hostdata *aha1542 = shost_priv(sdev->host);
if (capacity >= 0x200000 &&
aha1542->bios_translation == BIOS_TRANSLATION_25563) {
geom[0] = 255;
geom[1] = 63;
} else {
geom[0] = 64;
geom[1] = 32;
}
geom[2] = sector_div(capacity, geom[0] * geom[1]);
return 0;
}
static int aha1542_isa_match(struct device *pdev, unsigned int ndev)
{
struct Scsi_Host *sh = aha1542_hw_init(&driver_template, pdev, ndev);
if (!sh)
return 0;
dev_set_drvdata(pdev, sh);
return 1;
}
static int aha1542_isa_remove(struct device *pdev,
unsigned int ndev)
{
aha1542_release(dev_get_drvdata(pdev));
dev_set_drvdata(pdev, NULL);
return 0;
}
static int aha1542_pnp_probe(struct pnp_dev *pdev, const struct pnp_device_id *id)
{
int indx;
struct Scsi_Host *sh;
for (indx = 0; indx < ARRAY_SIZE(io); indx++) {
if (io[indx])
continue;
if (pnp_activate_dev(pdev) < 0)
continue;
io[indx] = pnp_port_start(pdev, 0);
dev_info(&pdev->dev, "ISAPnP found an AHA1535 at I/O 0x%03X", io[indx]);
}
sh = aha1542_hw_init(&driver_template, &pdev->dev, indx);
if (!sh)
return -ENODEV;
pnp_set_drvdata(pdev, sh);
return 0;
}
static void aha1542_pnp_remove(struct pnp_dev *pdev)
{
aha1542_release(pnp_get_drvdata(pdev));
pnp_set_drvdata(pdev, NULL);
}
static int __init aha1542_init(void)
{
int ret = 0;
#ifdef CONFIG_PNP
if (isapnp) {
ret = pnp_register_driver(&aha1542_pnp_driver);
if (!ret)
pnp_registered = 1;
}
#endif
ret = isa_register_driver(&aha1542_isa_driver, MAXBOARDS);
if (!ret)
isa_registered = 1;
#ifdef CONFIG_PNP
if (pnp_registered)
ret = 0;
#endif
if (isa_registered)
ret = 0;
return ret;
}
static void __exit aha1542_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_driver(&aha1542_pnp_driver);
#endif
if (isa_registered)
isa_unregister_driver(&aha1542_isa_driver);
}
