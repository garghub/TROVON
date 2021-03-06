static int eata_pio_show_info(struct seq_file *m, struct Scsi_Host *shost)
{
seq_printf(m, "EATA (Extended Attachment) PIO driver version: "
"%d.%d%s\n",VER_MAJOR, VER_MINOR, VER_SUB);
seq_printf(m, "queued commands: %10ld\n"
"processed interrupts:%10ld\n", queue_counter, int_counter);
seq_printf(m, "\nscsi%-2d: HBA %.10s\n",
shost->host_no, SD(shost)->name);
seq_printf(m, "Firmware revision: v%s\n",
SD(shost)->revision);
seq_puts(m, "IO: PIO\n");
seq_printf(m, "Base IO : %#.4x\n", (u32) shost->base);
seq_printf(m, "Host Bus: %s\n",
(SD(shost)->bustype == 'P')?"PCI ":
(SD(shost)->bustype == 'E')?"EISA":"ISA ");
return 0;
}
static int eata_pio_release(struct Scsi_Host *sh)
{
hostdata *hd = SD(sh);
if (sh->irq && reg_IRQ[sh->irq] == 1)
free_irq(sh->irq, NULL);
else
reg_IRQ[sh->irq]--;
if (SD(sh)->channel == 0) {
if (sh->io_port && sh->n_io_port)
release_region(sh->io_port, sh->n_io_port);
}
if (hd->pdev)
pci_dev_put(hd->pdev);
return 1;
}
static void IncStat(struct scsi_pointer *SCp, unsigned int Increment)
{
SCp->ptr += Increment;
if ((SCp->this_residual -= Increment) == 0) {
if ((--SCp->buffers_residual) == 0)
SCp->Status = 0;
else {
SCp->buffer++;
SCp->ptr = sg_virt(SCp->buffer);
SCp->this_residual = SCp->buffer->length;
}
}
}
static irqreturn_t do_eata_pio_int_handler(int irq, void *dev_id)
{
unsigned long flags;
struct Scsi_Host *dev = dev_id;
irqreturn_t ret;
spin_lock_irqsave(dev->host_lock, flags);
ret = eata_pio_int_handler(irq, dev_id);
spin_unlock_irqrestore(dev->host_lock, flags);
return ret;
}
static irqreturn_t eata_pio_int_handler(int irq, void *dev_id)
{
unsigned int eata_stat = 0xfffff;
struct scsi_cmnd *cmd;
hostdata *hd;
struct eata_ccb *cp;
unsigned long base;
unsigned int x, z;
struct Scsi_Host *sh;
unsigned short zwickel = 0;
unsigned char stat, odd;
irqreturn_t ret = IRQ_NONE;
for (x = 1, sh = first_HBA; x <= registered_HBAs; x++, sh = SD(sh)->prev)
{
if (sh->irq != irq)
continue;
if (inb(sh->base + HA_RSTATUS) & HA_SBUSY)
continue;
int_counter++;
ret = IRQ_HANDLED;
hd = SD(sh);
cp = &hd->ccb[0];
cmd = cp->cmd;
base = cmd->device->host->base;
do {
stat = inb(base + HA_RSTATUS);
if (stat & HA_SDRQ) {
if (cp->DataIn) {
z = 256;
odd = 0;
while ((cmd->SCp.Status) && ((z > 0) || (odd))) {
if (odd) {
*(cmd->SCp.ptr) = zwickel >> 8;
IncStat(&cmd->SCp, 1);
odd = 0;
}
x = min_t(unsigned int, z, cmd->SCp.this_residual / 2);
insw(base + HA_RDATA, cmd->SCp.ptr, x);
z -= x;
IncStat(&cmd->SCp, 2 * x);
if ((z > 0) && (cmd->SCp.this_residual == 1)) {
zwickel = inw(base + HA_RDATA);
*(cmd->SCp.ptr) = zwickel & 0xff;
IncStat(&cmd->SCp, 1);
z--;
odd = 1;
}
}
while (z > 0) {
zwickel = inw(base + HA_RDATA);
z--;
}
} else {
odd = 0;
z = 256;
while ((cmd->SCp.Status) && ((z > 0) || (odd))) {
if (odd) {
zwickel += *(cmd->SCp.ptr) << 8;
IncStat(&cmd->SCp, 1);
outw(zwickel, base + HA_RDATA);
z--;
odd = 0;
}
x = min_t(unsigned int, z, cmd->SCp.this_residual / 2);
outsw(base + HA_RDATA, cmd->SCp.ptr, x);
z -= x;
IncStat(&cmd->SCp, 2 * x);
if ((z > 0) && (cmd->SCp.this_residual == 1)) {
zwickel = *(cmd->SCp.ptr);
zwickel &= 0xff;
IncStat(&cmd->SCp, 1);
odd = 1;
}
}
while (z > 0 || odd) {
outw(zwickel, base + HA_RDATA);
z--;
odd = 0;
}
}
}
}
while ((stat & HA_SDRQ) || ((stat & HA_SMORE) && hd->moresupport));
if (stat & HA_SBUSY)
break;
if (!(inb(base + HA_RSTATUS) & HA_SERROR)) {
cmd->result = (DID_OK << 16);
hd->devflags |= (1 << cp->cp_id);
} else if (hd->devflags & (1 << cp->cp_id))
cmd->result = (DID_OK << 16) + 0x02;
else
cmd->result = (DID_NO_CONNECT << 16);
if (cp->status == LOCKED) {
cp->status = FREE;
eata_stat = inb(base + HA_RSTATUS);
printk(KERN_CRIT "eata_pio: int_handler, freeing locked " "queueslot\n");
return ret;
}
#if DBG_INTR2
if (stat != 0x50)
printk(KERN_DEBUG "stat: %#.2x, result: %#.8x\n", stat, cmd->result);
#endif
cp->status = FREE;
cmd->scsi_done(cmd);
}
return ret;
}
static inline unsigned int eata_pio_send_command(unsigned long base, unsigned char command)
{
unsigned int loop = 50;
while (inb(base + HA_RSTATUS) & HA_SBUSY)
if (--loop == 0)
return 1;
outb(HA_CTRL_8HEADS, base + HA_CTRLREG);
outb(command, base + HA_WCOMMAND);
return 0;
}
static int eata_pio_queue_lck(struct scsi_cmnd *cmd,
void (*done)(struct scsi_cmnd *))
{
unsigned int x, y;
unsigned long base;
hostdata *hd;
struct Scsi_Host *sh;
struct eata_ccb *cp;
queue_counter++;
hd = HD(cmd);
sh = cmd->device->host;
base = sh->base;
y = x = 0;
if (hd->ccb[y].status != FREE) {
DBG(DBG_QUEUE, printk(KERN_EMERG "can_queue %d, x %d, y %d\n", sh->can_queue, x, y));
#if DEBUG_EATA
panic(KERN_EMERG "eata_pio: run out of queue slots cmdno:%ld " "intrno: %ld\n", queue_counter, int_counter);
#else
panic(KERN_EMERG "eata_pio: run out of queue slots....\n");
#endif
}
cp = &hd->ccb[y];
memset(cp, 0, sizeof(struct eata_ccb));
cp->status = USED;
DBG(DBG_QUEUE, scmd_printk(KERN_DEBUG, cmd,
"eata_pio_queue 0x%p, y %d\n", cmd, y));
cmd->scsi_done = (void *) done;
if (cmd->sc_data_direction == DMA_TO_DEVICE)
cp->DataOut = 1;
else
cp->DataIn = 0;
cp->Interpret = (cmd->device->id == hd->hostid);
cp->cp_datalen = cpu_to_be32(scsi_bufflen(cmd));
cp->Auto_Req_Sen = 0;
cp->cp_reqDMA = 0;
cp->reqlen = 0;
cp->cp_id = cmd->device->id;
cp->cp_lun = cmd->device->lun;
cp->cp_dispri = 0;
cp->cp_identify = 1;
memcpy(cp->cp_cdb, cmd->cmnd, COMMAND_SIZE(*cmd->cmnd));
cp->cp_statDMA = 0;
cp->cp_viraddr = cp;
cp->cmd = cmd;
cmd->host_scribble = (char *) &hd->ccb[y];
if (!scsi_bufflen(cmd)) {
cmd->SCp.buffers_residual = 1;
cmd->SCp.ptr = NULL;
cmd->SCp.this_residual = 0;
cmd->SCp.buffer = NULL;
} else {
cmd->SCp.buffer = scsi_sglist(cmd);
cmd->SCp.buffers_residual = scsi_sg_count(cmd);
cmd->SCp.ptr = sg_virt(cmd->SCp.buffer);
cmd->SCp.this_residual = cmd->SCp.buffer->length;
}
cmd->SCp.Status = (cmd->SCp.this_residual != 0);
if (eata_pio_send_command(base, EATA_CMD_PIO_SEND_CP)) {
cmd->result = DID_BUS_BUSY << 16;
scmd_printk(KERN_NOTICE, cmd,
"eata_pio_queue pid 0x%p, HBA busy, "
"returning DID_BUS_BUSY, done.\n", cmd);
done(cmd);
cp->status = FREE;
return 0;
}
while (!(inb(base + HA_RSTATUS) & HA_SDRQ))
cpu_relax();
outsw(base + HA_RDATA, cp, hd->cplen);
outb(EATA_CMD_PIO_TRUNC, base + HA_WCOMMAND);
for (x = 0; x < hd->cppadlen; x++)
outw(0, base + HA_RDATA);
DBG(DBG_QUEUE, scmd_printk(KERN_DEBUG, cmd,
"Queued base %#.4lx cmd: 0x%p "
"slot %d irq %d\n", sh->base, cmd, y, sh->irq));
return 0;
}
int eata_pio_host_reset(struct scsi_cmnd *cmd)
{
unsigned int x, limit = 0;
unsigned char success = 0;
struct scsi_cmnd *sp;
struct Scsi_Host *host = cmd->device->host;
DBG(DBG_ABNORM, scmd_printk(KERN_WARNING, cmd,
"eata_pio_reset called\n"));
spin_lock_irq(host->host_lock);
if (HD(cmd)->state == RESET) {
printk(KERN_WARNING "eata_pio_reset: exit, already in reset.\n");
spin_unlock_irq(host->host_lock);
return FAILED;
}
for (x = 0; x < cmd->device->host->can_queue; x++) {
if (HD(cmd)->ccb[x].status == FREE)
continue;
sp = HD(cmd)->ccb[x].cmd;
HD(cmd)->ccb[x].status = RESET;
printk(KERN_WARNING "eata_pio_reset: slot %d in reset.\n", x);
if (sp == NULL)
panic("eata_pio_reset: slot %d, sp==NULL.\n", x);
}
outb(EATA_CMD_RESET, cmd->device->host->base + HA_WCOMMAND);
DBG(DBG_ABNORM, printk(KERN_WARNING "eata_pio_reset: board reset done.\n"));
HD(cmd)->state = RESET;
spin_unlock_irq(host->host_lock);
msleep(3000);
spin_lock_irq(host->host_lock);
DBG(DBG_ABNORM, printk(KERN_WARNING "eata_pio_reset: interrupts disabled, " "loops %d.\n", limit));
for (x = 0; x < cmd->device->host->can_queue; x++) {
if (HD(cmd)->ccb[x].status != RESET)
continue;
sp = HD(cmd)->ccb[x].cmd;
sp->result = DID_RESET << 16;
printk(KERN_WARNING "eata_pio_reset: reset ccb %d.\n", x);
HD(cmd)->ccb[x].status = FREE;
sp->scsi_done(sp);
}
HD(cmd)->state = 0;
spin_unlock_irq(host->host_lock);
if (success) {
DBG(DBG_ABNORM, printk(KERN_WARNING "eata_pio_reset: exit, success.\n"));
return SUCCESS;
} else {
DBG(DBG_ABNORM, printk(KERN_WARNING "eata_pio_reset: exit, wakeup.\n"));
return FAILED;
}
}
static char *get_pio_board_data(unsigned long base, unsigned int irq, unsigned int id, unsigned long cplen, unsigned short cppadlen)
{
struct eata_ccb cp;
static char buff[256];
int z;
memset(&cp, 0, sizeof(struct eata_ccb));
memset(buff, 0, sizeof(buff));
cp.DataIn = 1;
cp.Interpret = 1;
cp.cp_datalen = cpu_to_be32(254);
cp.cp_dataDMA = cpu_to_be32(0);
cp.cp_id = id;
cp.cp_lun = 0;
cp.cp_cdb[0] = INQUIRY;
cp.cp_cdb[1] = 0;
cp.cp_cdb[2] = 0;
cp.cp_cdb[3] = 0;
cp.cp_cdb[4] = 254;
cp.cp_cdb[5] = 0;
if (eata_pio_send_command(base, EATA_CMD_PIO_SEND_CP))
return NULL;
while (!(inb(base + HA_RSTATUS) & HA_SDRQ))
cpu_relax();
outsw(base + HA_RDATA, &cp, cplen);
outb(EATA_CMD_PIO_TRUNC, base + HA_WCOMMAND);
for (z = 0; z < cppadlen; z++)
outw(0, base + HA_RDATA);
while (inb(base + HA_RSTATUS) & HA_SBUSY)
cpu_relax();
if (inb(base + HA_RSTATUS) & HA_SERROR)
return NULL;
else if (!(inb(base + HA_RSTATUS) & HA_SDRQ))
return NULL;
else {
insw(base + HA_RDATA, &buff, 127);
while (inb(base + HA_RSTATUS) & HA_SDRQ)
inw(base + HA_RDATA);
return buff;
}
}
static int get_pio_conf_PIO(unsigned long base, struct get_conf *buf)
{
unsigned long loop = HZ / 2;
int z;
unsigned short *p;
if (!request_region(base, 9, "eata_pio"))
return 0;
memset(buf, 0, sizeof(struct get_conf));
while (inb(base + HA_RSTATUS) & HA_SBUSY)
if (--loop == 0)
goto fail;
DBG(DBG_PIO && DBG_PROBE, printk(KERN_DEBUG "Issuing PIO READ CONFIG to HBA at %#lx\n", base));
eata_pio_send_command(base, EATA_CMD_PIO_READ_CONFIG);
loop = 50;
for (p = (unsigned short *) buf; (long) p <= ((long) buf + (sizeof(struct get_conf) / 2)); p++) {
while (!(inb(base + HA_RSTATUS) & HA_SDRQ))
if (--loop == 0)
goto fail;
loop = 50;
*p = inw(base + HA_RDATA);
}
if (inb(base + HA_RSTATUS) & HA_SERROR) {
DBG(DBG_PROBE, printk("eata_dma: get_conf_PIO, error during "
"transfer for HBA at %lx\n", base));
goto fail;
}
if (cpu_to_be32(EATA_SIGNATURE) != buf->signature)
goto fail;
DBG(DBG_PIO && DBG_PROBE, printk(KERN_NOTICE "EATA Controller found "
"at %#4lx EATA Level: %x\n",
base, (unsigned int) (buf->version)));
while (inb(base + HA_RSTATUS) & HA_SDRQ)
inw(base + HA_RDATA);
if (!ALLOW_DMA_BOARDS) {
for (z = 0; z < MAXISA; z++)
if (base == ISAbases[z]) {
buf->IRQ = ISAirqs[z];
break;
}
}
return 1;
fail:
release_region(base, 9);
return 0;
}
static void print_pio_config(struct get_conf *gc)
{
printk("Please check values: (read config data)\n");
printk("LEN: %d ver:%d OCS:%d TAR:%d TRNXFR:%d MORES:%d\n", be32_to_cpu(gc->len), gc->version, gc->OCS_enabled, gc->TAR_support, gc->TRNXFR, gc->MORE_support);
printk("HAAV:%d SCSIID0:%d ID1:%d ID2:%d QUEUE:%d SG:%d SEC:%d\n", gc->HAA_valid, gc->scsi_id[3], gc->scsi_id[2], gc->scsi_id[1], be16_to_cpu(gc->queuesiz), be16_to_cpu(gc->SGsiz), gc->SECOND);
printk("IRQ:%d IRQT:%d FORCADR:%d MCH:%d RIDQ:%d\n", gc->IRQ, gc->IRQ_TR, gc->FORCADR, gc->MAX_CHAN, gc->ID_qest);
}
static unsigned int print_selftest(unsigned int base)
{
unsigned char buffer[512];
#ifdef VERBOSE_SETUP
int z;
#endif
printk("eata_pio: executing controller self test & setup...\n");
while (inb(base + HA_RSTATUS) & HA_SBUSY);
outb(EATA_CMD_PIO_SETUPTEST, base + HA_WCOMMAND);
do {
while (inb(base + HA_RSTATUS) & HA_SBUSY)
;
if (inb(base + HA_RSTATUS) & HA_SDRQ) {
insw(base + HA_RDATA, &buffer, 256);
#ifdef VERBOSE_SETUP
for (z = 0; z < 511 && buffer[z]; z++)
if (buffer[z] != 7)
printk("%c", buffer[z]);
#endif
}
} while (inb(base + HA_RSTATUS) & (HA_SBUSY | HA_SDRQ));
return (!(inb(base + HA_RSTATUS) & HA_SERROR));
}
static int register_pio_HBA(long base, struct get_conf *gc, struct pci_dev *pdev)
{
unsigned long size = 0;
char *buff;
unsigned long cplen;
unsigned short cppadlen;
struct Scsi_Host *sh;
hostdata *hd;
DBG(DBG_REGISTER, print_pio_config(gc));
if (gc->DMA_support) {
printk("HBA at %#.4lx supports DMA. Please use EATA-DMA driver.\n", base);
if (!ALLOW_DMA_BOARDS)
return 0;
}
if ((buff = get_pio_board_data(base, gc->IRQ, gc->scsi_id[3], cplen = (cpu_to_be32(gc->cplen) + 1) / 2, cppadlen = (cpu_to_be16(gc->cppadlen) + 1) / 2)) == NULL) {
printk("HBA at %#lx didn't react on INQUIRY. Sorry.\n", base);
return 0;
}
if (!print_selftest(base) && !ALLOW_DMA_BOARDS) {
printk("HBA at %#lx failed while performing self test & setup.\n", base);
return 0;
}
size = sizeof(hostdata) + (sizeof(struct eata_ccb) * be16_to_cpu(gc->queuesiz));
sh = scsi_register(&driver_template, size);
if (sh == NULL)
return 0;
if (!reg_IRQ[gc->IRQ]) {
if (!request_irq(gc->IRQ, do_eata_pio_int_handler, 0, "EATA-PIO", sh)) {
reg_IRQ[gc->IRQ]++;
if (!gc->IRQ_TR)
reg_IRQL[gc->IRQ] = 1;
} else {
printk("Couldn't allocate IRQ %d, Sorry.\n", gc->IRQ);
return 0;
}
} else {
if (reg_IRQL[gc->IRQ]) {
printk("Can't support more than one HBA on this IRQ,\n" " if the IRQ is edge triggered. Sorry.\n");
return 0;
} else
reg_IRQ[gc->IRQ]++;
}
hd = SD(sh);
memset(hd->ccb, 0, (sizeof(struct eata_ccb) * be16_to_cpu(gc->queuesiz)));
memset(hd->reads, 0, sizeof(hd->reads));
strlcpy(SD(sh)->vendor, &buff[8], sizeof(SD(sh)->vendor));
strlcpy(SD(sh)->name, &buff[16], sizeof(SD(sh)->name));
SD(sh)->revision[0] = buff[32];
SD(sh)->revision[1] = buff[33];
SD(sh)->revision[2] = buff[34];
SD(sh)->revision[3] = '.';
SD(sh)->revision[4] = buff[35];
SD(sh)->revision[5] = 0;
switch (be32_to_cpu(gc->len)) {
case 0x1c:
SD(sh)->EATA_revision = 'a';
break;
case 0x1e:
SD(sh)->EATA_revision = 'b';
break;
case 0x22:
SD(sh)->EATA_revision = 'c';
break;
case 0x24:
SD(sh)->EATA_revision = 'z';
default:
SD(sh)->EATA_revision = '?';
}
if (be32_to_cpu(gc->len) >= 0x22) {
if (gc->is_PCI)
hd->bustype = IS_PCI;
else if (gc->is_EISA)
hd->bustype = IS_EISA;
else
hd->bustype = IS_ISA;
} else {
if (buff[21] == '4')
hd->bustype = IS_PCI;
else if (buff[21] == '2')
hd->bustype = IS_EISA;
else
hd->bustype = IS_ISA;
}
SD(sh)->cplen = cplen;
SD(sh)->cppadlen = cppadlen;
SD(sh)->hostid = gc->scsi_id[3];
SD(sh)->devflags = 1 << gc->scsi_id[3];
SD(sh)->moresupport = gc->MORE_support;
sh->unique_id = base;
sh->base = base;
sh->io_port = base;
sh->n_io_port = 9;
sh->irq = gc->IRQ;
sh->dma_channel = PIO;
sh->this_id = gc->scsi_id[3];
sh->can_queue = 1;
sh->cmd_per_lun = 1;
sh->sg_tablesize = SG_ALL;
hd->channel = 0;
hd->pdev = pci_dev_get(pdev);
sh->max_id = 8;
sh->max_lun = 8;
if (gc->SECOND)
hd->primary = 0;
else
hd->primary = 1;
hd->next = NULL;
hd->prev = last_HBA;
if (hd->prev != NULL)
SD(hd->prev)->next = sh;
last_HBA = sh;
if (first_HBA == NULL)
first_HBA = sh;
registered_HBAs++;
return (1);
}
static void find_pio_ISA(struct get_conf *buf)
{
int i;
for (i = 0; i < MAXISA; i++) {
if (!ISAbases[i])
continue;
if (!get_pio_conf_PIO(ISAbases[i], buf))
continue;
if (!register_pio_HBA(ISAbases[i], buf, NULL))
release_region(ISAbases[i], 9);
else
ISAbases[i] = 0;
}
return;
}
static void find_pio_EISA(struct get_conf *buf)
{
u32 base;
int i;
#ifdef CHECKPAL
u8 pal1, pal2, pal3;
#endif
for (i = 0; i < MAXEISA; i++) {
if (EISAbases[i]) {
base = 0x1c88 + (i * 0x1000);
#ifdef CHECKPAL
pal1 = inb((u16) base - 8);
pal2 = inb((u16) base - 7);
pal3 = inb((u16) base - 6);
if (((pal1 == 0x12) && (pal2 == 0x14)) || ((pal1 == 0x38) && (pal2 == 0xa3) && (pal3 == 0x82)) || ((pal1 == 0x06) && (pal2 == 0x94) && (pal3 == 0x24))) {
DBG(DBG_PROBE, printk(KERN_NOTICE "EISA EATA id tags found: " "%x %x %x \n", (int) pal1, (int) pal2, (int) pal3));
#endif
if (get_pio_conf_PIO(base, buf)) {
DBG(DBG_PROBE && DBG_EISA, print_pio_config(buf));
if (buf->IRQ) {
if (!register_pio_HBA(base, buf, NULL))
release_region(base, 9);
} else {
printk(KERN_NOTICE "eata_dma: No valid IRQ. HBA " "removed from list\n");
release_region(base, 9);
}
}
EISAbases[i] = 0;
#ifdef CHECKPAL
}
#endif
}
}
return;
}
static void find_pio_PCI(struct get_conf *buf)
{
#ifndef CONFIG_PCI
printk("eata_dma: kernel PCI support not enabled. Skipping scan for PCI HBAs.\n");
#else
struct pci_dev *dev = NULL;
unsigned long base, x;
while ((dev = pci_get_device(PCI_VENDOR_ID_DPT, PCI_DEVICE_ID_DPT, dev)) != NULL) {
DBG(DBG_PROBE && DBG_PCI, printk("eata_pio: find_PCI, HBA at %s\n", pci_name(dev)));
if (pci_enable_device(dev))
continue;
pci_set_master(dev);
base = pci_resource_flags(dev, 0);
if (base & IORESOURCE_MEM) {
printk("eata_pio: invalid base address of device %s\n", pci_name(dev));
continue;
}
base = pci_resource_start(dev, 0);
if ((inb(base) == 0x12) && (inb(base + 1) == 0x14))
continue;
base += 0x10;
if (base != 0x1f8) {
if (get_pio_conf_PIO(base, buf)) {
if (buf->FORCADR) {
release_region(base, 9);
continue;
}
if (!register_pio_HBA(base, buf, dev)) {
release_region(base, 9);
continue;
}
if (base < 0x1000) {
for (x = 0; x < MAXISA; ++x) {
if (ISAbases[x] == base) {
ISAbases[x] = 0;
break;
}
}
} else if ((base & 0x0fff) == 0x0c88) {
x = (base >> 12) & 0x0f;
EISAbases[x] = 0;
}
}
#ifdef CHECK_BLINK
else if (check_blink_state(base)) {
printk("eata_pio: HBA is in BLINK state.\n" "Consult your HBAs manual to correct this.\n");
}
#endif
}
}
#endif
}
static int eata_pio_detect(struct scsi_host_template *tpnt)
{
struct Scsi_Host *HBA_ptr;
struct get_conf gc;
int i;
find_pio_PCI(&gc);
find_pio_EISA(&gc);
find_pio_ISA(&gc);
for (i = 0; i < MAXIRQ; i++)
if (reg_IRQ[i])
request_irq(i, do_eata_pio_int_handler, 0, "EATA-PIO", NULL);
HBA_ptr = first_HBA;
if (registered_HBAs != 0) {
printk("EATA (Extended Attachment) PIO driver version: %d.%d%s\n"
"(c) 1993-95 Michael Neuffer, neuffer@goofy.zdv.uni-mainz.de\n" " Alfred Arnold, a.arnold@kfa-juelich.de\n" "This release only supports DASD devices (harddisks)\n", VER_MAJOR, VER_MINOR, VER_SUB);
printk("Registered HBAs:\n");
printk("HBA no. Boardtype: Revis: EATA: Bus: BaseIO: IRQ: Ch: ID: Pr:" " QS: SG: CPL:\n");
for (i = 1; i <= registered_HBAs; i++) {
printk("scsi%-2d: %.10s v%s 2.0%c %s %#.4lx %2d %d %d %c"
" %2d %2d %2d\n",
HBA_ptr->host_no, SD(HBA_ptr)->name, SD(HBA_ptr)->revision,
SD(HBA_ptr)->EATA_revision, (SD(HBA_ptr)->bustype == 'P') ?
"PCI " : (SD(HBA_ptr)->bustype == 'E') ? "EISA" : "ISA ",
HBA_ptr->base, HBA_ptr->irq, SD(HBA_ptr)->channel, HBA_ptr->this_id,
SD(HBA_ptr)->primary ? 'Y' : 'N', HBA_ptr->can_queue,
HBA_ptr->sg_tablesize, HBA_ptr->cmd_per_lun);
HBA_ptr = SD(HBA_ptr)->next;
}
}
return (registered_HBAs);
}
