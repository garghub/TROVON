static void __init internal_setup(int board, char *str, int *ints)
{
static int commandline_current = 0;
switch (board) {
case BOARD_NCR5380:
if (ints[0] != 2 && ints[0] != 3) {
printk(KERN_ERR "generic_NCR5380_setup : usage ncr5380=" STRVAL(NCR5380_map_name) ",irq,dma\n");
return;
}
break;
case BOARD_NCR53C400:
if (ints[0] != 2) {
printk(KERN_ERR "generic_NCR53C400_setup : usage ncr53c400=" STRVAL(NCR5380_map_name) ",irq\n");
return;
}
break;
case BOARD_NCR53C400A:
if (ints[0] != 2) {
printk(KERN_ERR "generic_NCR53C400A_setup : usage ncr53c400a=" STRVAL(NCR5380_map_name) ",irq\n");
return;
}
break;
case BOARD_DTC3181E:
if (ints[0] != 2) {
printk("generic_DTC3181E_setup : usage dtc3181e=" STRVAL(NCR5380_map_name) ",irq\n");
return;
}
break;
}
if (commandline_current < NO_OVERRIDES) {
overrides[commandline_current].NCR5380_map_name = (NCR5380_map_type) ints[1];
overrides[commandline_current].irq = ints[2];
if (ints[0] == 3)
overrides[commandline_current].dma = ints[3];
else
overrides[commandline_current].dma = DMA_NONE;
overrides[commandline_current].board = board;
++commandline_current;
}
}
static int __init do_NCR5380_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_NCR5380, str, ints);
return 1;
}
static int __init do_NCR53C400_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_NCR53C400, str, ints);
return 1;
}
static int __init do_NCR53C400A_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_NCR53C400A, str, ints);
return 1;
}
static int __init do_DTC3181E_setup(char *str)
{
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
internal_setup(BOARD_DTC3181E, str, ints);
return 1;
}
int __init generic_NCR5380_detect(struct scsi_host_template * tpnt)
{
static int current_override = 0;
int count;
unsigned int *ports;
#ifndef SCSI_G_NCR5380_MEM
int i;
unsigned long region_size = 16;
#endif
static unsigned int __initdata ncr_53c400a_ports[] = {
0x280, 0x290, 0x300, 0x310, 0x330, 0x340, 0x348, 0x350, 0
};
static unsigned int __initdata dtc_3181e_ports[] = {
0x220, 0x240, 0x280, 0x2a0, 0x2c0, 0x300, 0x320, 0x340, 0
};
int flags = 0;
struct Scsi_Host *instance;
#ifdef SCSI_G_NCR5380_MEM
unsigned long base;
void __iomem *iomem;
#endif
if (ncr_irq != NCR_NOT_SET)
overrides[0].irq = ncr_irq;
if (ncr_dma != NCR_NOT_SET)
overrides[0].dma = ncr_dma;
if (ncr_addr != NCR_NOT_SET)
overrides[0].NCR5380_map_name = (NCR5380_map_type) ncr_addr;
if (ncr_5380 != NCR_NOT_SET)
overrides[0].board = BOARD_NCR5380;
else if (ncr_53c400 != NCR_NOT_SET)
overrides[0].board = BOARD_NCR53C400;
else if (ncr_53c400a != NCR_NOT_SET)
overrides[0].board = BOARD_NCR53C400A;
else if (dtc_3181e != NCR_NOT_SET)
overrides[0].board = BOARD_DTC3181E;
#ifndef SCSI_G_NCR5380_MEM
if (!current_override && isapnp_present()) {
struct pnp_dev *dev = NULL;
count = 0;
while ((dev = pnp_find_dev(NULL, ISAPNP_VENDOR('D', 'T', 'C'), ISAPNP_FUNCTION(0x436e), dev))) {
if (count >= NO_OVERRIDES)
break;
if (pnp_device_attach(dev) < 0)
continue;
if (pnp_activate_dev(dev) < 0) {
printk(KERN_ERR "dtc436e probe: activate failed\n");
pnp_device_detach(dev);
continue;
}
if (!pnp_port_valid(dev, 0)) {
printk(KERN_ERR "dtc436e probe: no valid port\n");
pnp_device_detach(dev);
continue;
}
if (pnp_irq_valid(dev, 0))
overrides[count].irq = pnp_irq(dev, 0);
else
overrides[count].irq = SCSI_IRQ_NONE;
if (pnp_dma_valid(dev, 0))
overrides[count].dma = pnp_dma(dev, 0);
else
overrides[count].dma = DMA_NONE;
overrides[count].NCR5380_map_name = (NCR5380_map_type) pnp_port_start(dev, 0);
overrides[count].board = BOARD_DTC3181E;
count++;
}
}
#endif
tpnt->proc_name = "g_NCR5380";
for (count = 0; current_override < NO_OVERRIDES; ++current_override) {
if (!(overrides[current_override].NCR5380_map_name))
continue;
ports = NULL;
switch (overrides[current_override].board) {
case BOARD_NCR5380:
flags = FLAG_NO_PSEUDO_DMA;
break;
case BOARD_NCR53C400:
flags = FLAG_NCR53C400;
break;
case BOARD_NCR53C400A:
flags = FLAG_NO_PSEUDO_DMA;
ports = ncr_53c400a_ports;
break;
case BOARD_DTC3181E:
flags = FLAG_NO_PSEUDO_DMA | FLAG_DTC3181E;
ports = dtc_3181e_ports;
break;
}
#ifndef SCSI_G_NCR5380_MEM
if (ports) {
outb(0x59, 0x779);
outb(0xb9, 0x379);
outb(0xc5, 0x379);
outb(0xae, 0x379);
outb(0xa6, 0x379);
outb(0x00, 0x379);
if (overrides[current_override].NCR5380_map_name != PORT_AUTO)
for (i = 0; ports[i]; i++) {
if (!request_region(ports[i], 16, "ncr53c80"))
continue;
if (overrides[current_override].NCR5380_map_name == ports[i])
break;
release_region(ports[i], 16);
} else
for (i = 0; ports[i]; i++) {
if (!request_region(ports[i], 16, "ncr53c80"))
continue;
if (inb(ports[i]) == 0xff)
break;
release_region(ports[i], 16);
}
if (ports[i]) {
outb(0x59, 0x779);
outb(0xb9, 0x379);
outb(0xc5, 0x379);
outb(0xae, 0x379);
outb(0xa6, 0x379);
outb(0x80 | i, 0x379);
outb(0xc0, ports[i] + 9);
if (inb(ports[i] + 9) != 0x80)
continue;
else
overrides[current_override].NCR5380_map_name = ports[i];
} else
continue;
}
else
{
if(!(request_region(overrides[current_override].NCR5380_map_name, NCR5380_region_size, "ncr5380")))
continue;
region_size = NCR5380_region_size;
}
#else
base = overrides[current_override].NCR5380_map_name;
if (!request_mem_region(base, NCR5380_region_size, "ncr5380"))
continue;
iomem = ioremap(base, NCR5380_region_size);
if (!iomem) {
release_mem_region(base, NCR5380_region_size);
continue;
}
#endif
instance = scsi_register(tpnt, sizeof(struct NCR5380_hostdata));
if (instance == NULL) {
#ifndef SCSI_G_NCR5380_MEM
release_region(overrides[current_override].NCR5380_map_name, region_size);
#else
iounmap(iomem);
release_mem_region(base, NCR5380_region_size);
#endif
continue;
}
instance->NCR5380_instance_name = overrides[current_override].NCR5380_map_name;
#ifndef SCSI_G_NCR5380_MEM
instance->n_io_port = region_size;
#else
((struct NCR5380_hostdata *)instance->hostdata)->iomem = iomem;
#endif
NCR5380_init(instance, flags);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, 0xffff);
if (instance->irq != SCSI_IRQ_NONE)
if (request_irq(instance->irq, generic_NCR5380_intr,
0, "NCR5380", instance)) {
printk(KERN_WARNING "scsi%d : IRQ%d not free, interrupts disabled\n", instance->host_no, instance->irq);
instance->irq = SCSI_IRQ_NONE;
}
if (instance->irq == SCSI_IRQ_NONE) {
printk(KERN_INFO "scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk(KERN_INFO "scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
}
printk(KERN_INFO "scsi%d : at " STRVAL(NCR5380_map_name) " 0x%x", instance->host_no, (unsigned int) instance->NCR5380_instance_name);
if (instance->irq == SCSI_IRQ_NONE)
printk(" interrupts disabled");
else
printk(" irq %d", instance->irq);
printk(" options CAN_QUEUE=%d CMD_PER_LUN=%d release=%d", CAN_QUEUE, CMD_PER_LUN, GENERIC_NCR5380_PUBLIC_RELEASE);
NCR5380_print_options(instance);
printk("\n");
++current_override;
++count;
}
return count;
}
const char *generic_NCR5380_info(struct Scsi_Host *host)
{
static const char string[] = "Generic NCR5380/53C400 Driver";
return string;
}
int generic_NCR5380_release_resources(struct Scsi_Host *instance)
{
NCR5380_local_declare();
NCR5380_setup(instance);
if (instance->irq != SCSI_IRQ_NONE)
free_irq(instance->irq, instance);
NCR5380_exit(instance);
#ifndef SCSI_G_NCR5380_MEM
release_region(instance->NCR5380_instance_name, instance->n_io_port);
#else
iounmap(((struct NCR5380_hostdata *)instance->hostdata)->iomem);
release_mem_region(instance->NCR5380_instance_name, NCR5380_region_size);
#endif
return 0;
}
static int
generic_NCR5380_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int *ip)
{
ip[0] = 64;
ip[1] = 32;
ip[2] = capacity >> 11;
return 0;
}
static inline int NCR5380_pread(struct Scsi_Host *instance, unsigned char *dst, int len)
{
int blocks = len / 128;
int start = 0;
int bl;
NCR5380_local_declare();
NCR5380_setup(instance);
NCR5380_write(C400_CONTROL_STATUS_REG, CSR_BASE | CSR_TRANS_DIR);
NCR5380_write(C400_BLOCK_COUNTER_REG, blocks);
while (1) {
if ((bl = NCR5380_read(C400_BLOCK_COUNTER_REG)) == 0) {
break;
}
if (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_GATED_53C80_IRQ) {
printk(KERN_ERR "53C400r: Got 53C80_IRQ start=%d, blocks=%d\n", start, blocks);
return -1;
}
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_HOST_BUF_NOT_RDY);
#ifndef SCSI_G_NCR5380_MEM
{
int i;
for (i = 0; i < 128; i++)
dst[start + i] = NCR5380_read(C400_HOST_BUFFER);
}
#else
memcpy_fromio(dst + start, iomem + NCR53C400_host_buffer, 128);
#endif
start += 128;
blocks--;
}
if (blocks) {
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_HOST_BUF_NOT_RDY)
{
}
#ifndef SCSI_G_NCR5380_MEM
{
int i;
for (i = 0; i < 128; i++)
dst[start + i] = NCR5380_read(C400_HOST_BUFFER);
}
#else
memcpy_fromio(dst + start, iomem + NCR53C400_host_buffer, 128);
#endif
start += 128;
blocks--;
}
if (!(NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_GATED_53C80_IRQ))
printk("53C400r: no 53C80 gated irq after transfer");
#if 0
printk("53C400r: Waiting for 53C80 registers\n");
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_53C80_REG)
;
#endif
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_END_DMA_TRANSFER))
printk(KERN_ERR "53C400r: no end dma signal\n");
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
return 0;
}
static inline int NCR5380_pwrite(struct Scsi_Host *instance, unsigned char *src, int len)
{
int blocks = len / 128;
int start = 0;
int bl;
int i;
NCR5380_local_declare();
NCR5380_setup(instance);
NCR5380_write(C400_CONTROL_STATUS_REG, CSR_BASE);
NCR5380_write(C400_BLOCK_COUNTER_REG, blocks);
while (1) {
if (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_GATED_53C80_IRQ) {
printk(KERN_ERR "53C400w: Got 53C80_IRQ start=%d, blocks=%d\n", start, blocks);
return -1;
}
if ((bl = NCR5380_read(C400_BLOCK_COUNTER_REG)) == 0) {
break;
}
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_HOST_BUF_NOT_RDY)
;
#ifndef SCSI_G_NCR5380_MEM
{
for (i = 0; i < 128; i++)
NCR5380_write(C400_HOST_BUFFER, src[start + i]);
}
#else
memcpy_toio(iomem + NCR53C400_host_buffer, src + start, 128);
#endif
start += 128;
blocks--;
}
if (blocks) {
while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_HOST_BUF_NOT_RDY)
;
#ifndef SCSI_G_NCR5380_MEM
{
for (i = 0; i < 128; i++)
NCR5380_write(C400_HOST_BUFFER, src[start + i]);
}
#else
memcpy_toio(iomem + NCR53C400_host_buffer, src + start, 128);
#endif
start += 128;
blocks--;
}
#if 0
printk("53C400w: waiting for registers to be available\n");
THEY NEVER DO ! while (NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_53C80_REG);
printk("53C400w: Got em\n");
#endif
while (!(i = NCR5380_read(C400_CONTROL_STATUS_REG) & CSR_GATED_53C80_IRQ))
;
if (i) {
if (!((i = NCR5380_read(BUS_AND_STATUS_REG)) & BASR_END_DMA_TRANSFER))
printk(KERN_ERR "53C400w: No END OF DMA bit - WHOOPS! BASR=%0x\n", i);
} else
printk(KERN_ERR "53C400w: no 53C80 gated irq after transfer (last block)\n");
#if 0
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_END_DMA_TRANSFER)) {
printk(KERN_ERR "53C400w: no end dma signal\n");
}
#endif
while (!(NCR5380_read(TARGET_COMMAND_REG) & TCR_LAST_BYTE_SENT))
;
return 0;
}
static void sprint_opcode(struct seq_file *m, int opcode)
{
PRINTP("0x%02x " ANDP opcode);
}
static void sprint_command(struct seq_file *m, unsigned char *command)
{
int i, s;
sprint_opcode(m, command[0]);
for (i = 1, s = COMMAND_SIZE(command[0]); i < s; ++i)
PRINTP("%02x " ANDP command[i]);
PRINTP("\n");
}
static void sprint_Scsi_Cmnd(struct seq_file *m, Scsi_Cmnd * cmd)
{
PRINTP("host number %d destination target %d, lun %llu\n" ANDP cmd->device->host->host_no ANDP cmd->device->id ANDP cmd->device->lun);
PRINTP(" command = ");
sprint_command(m, cmd->cmnd);
}
static int generic_NCR5380_show_info(struct seq_file *m, struct Scsi_Host *scsi_ptr)
{
NCR5380_local_declare();
unsigned long flags;
unsigned char status;
int i;
Scsi_Cmnd *ptr;
struct NCR5380_hostdata *hostdata;
#ifdef NCR5380_STATS
struct scsi_device *dev;
#endif
NCR5380_setup(scsi_ptr);
hostdata = (struct NCR5380_hostdata *) scsi_ptr->hostdata;
spin_lock_irqsave(scsi_ptr->host_lock, flags);
PRINTP("SCSI host number %d : %s\n" ANDP scsi_ptr->host_no ANDP scsi_ptr->hostt->name);
PRINTP("Generic NCR5380 driver version %d\n" ANDP GENERIC_NCR5380_PUBLIC_RELEASE);
PRINTP("NCR5380 core version %d\n" ANDP NCR5380_PUBLIC_RELEASE);
#ifdef NCR53C400
PRINTP("NCR53C400 extension version %d\n" ANDP NCR53C400_PUBLIC_RELEASE);
PRINTP("NCR53C400 card%s detected\n" ANDP(((struct NCR5380_hostdata *) scsi_ptr->hostdata)->flags & FLAG_NCR53C400) ? "" : " not");
# if NCR53C400_PSEUDO_DMA
PRINTP("NCR53C400 pseudo DMA used\n");
# endif
#else
PRINTP("NO NCR53C400 driver extensions\n");
#endif
PRINTP("Using %s mapping at %s 0x%lx, " ANDP STRVAL(NCR5380_map_config) ANDP STRVAL(NCR5380_map_name) ANDP scsi_ptr->NCR5380_instance_name);
if (scsi_ptr->irq == SCSI_IRQ_NONE)
PRINTP("no interrupt\n");
else
PRINTP("on interrupt %d\n" ANDP scsi_ptr->irq);
#ifdef NCR5380_STATS
if (hostdata->connected || hostdata->issue_queue || hostdata->disconnected_queue)
PRINTP("There are commands pending, transfer rates may be crud\n");
if (hostdata->pendingr)
PRINTP(" %d pending reads" ANDP hostdata->pendingr);
if (hostdata->pendingw)
PRINTP(" %d pending writes" ANDP hostdata->pendingw);
if (hostdata->pendingr || hostdata->pendingw)
PRINTP("\n");
shost_for_each_device(dev, scsi_ptr) {
unsigned long br = hostdata->bytes_read[dev->id];
unsigned long bw = hostdata->bytes_write[dev->id];
long tr = hostdata->time_read[dev->id] / HZ;
long tw = hostdata->time_write[dev->id] / HZ;
PRINTP(" T:%d %s " ANDP dev->id ANDP scsi_device_type(dev->type));
for (i = 0; i < 8; i++)
if (dev->vendor[i] >= 0x20)
seq_putc(m, dev->vendor[i]);
seq_putc(m, ' ');
for (i = 0; i < 16; i++)
if (dev->model[i] >= 0x20)
seq_putc(m, dev->model[i]);
seq_putc(m, ' ');
for (i = 0; i < 4; i++)
if (dev->rev[i] >= 0x20)
seq_putc(m, dev->rev[i]);
seq_putc(m, ' ');
PRINTP("\n%10ld kb read in %5ld secs" ANDP br / 1024 ANDP tr);
if (tr)
PRINTP(" @ %5ld bps" ANDP br / tr);
PRINTP("\n%10ld kb written in %5ld secs" ANDP bw / 1024 ANDP tw);
if (tw)
PRINTP(" @ %5ld bps" ANDP bw / tw);
PRINTP("\n");
}
#endif
status = NCR5380_read(STATUS_REG);
if (!(status & SR_REQ))
PRINTP("REQ not asserted, phase unknown.\n");
else {
for (i = 0; (phases[i].value != PHASE_UNKNOWN) && (phases[i].value != (status & PHASE_MASK)); ++i);
PRINTP("Phase %s\n" ANDP phases[i].name);
}
if (!hostdata->connected) {
PRINTP("No currently connected command\n");
} else {
sprint_Scsi_Cmnd(m, (Scsi_Cmnd *) hostdata->connected);
}
PRINTP("issue_queue\n");
for (ptr = (Scsi_Cmnd *) hostdata->issue_queue; ptr; ptr = (Scsi_Cmnd *) ptr->host_scribble)
sprint_Scsi_Cmnd(m, ptr);
PRINTP("disconnected_queue\n");
for (ptr = (Scsi_Cmnd *) hostdata->disconnected_queue; ptr; ptr = (Scsi_Cmnd *) ptr->host_scribble)
sprint_Scsi_Cmnd(m, ptr);
spin_unlock_irqrestore(scsi_ptr->host_lock, flags);
return 0;
}
