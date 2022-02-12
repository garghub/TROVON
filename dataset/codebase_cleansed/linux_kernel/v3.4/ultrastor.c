static inline int find_and_clear_bit_16(unsigned long *field)
{
int rv;
if (*field == 0)
panic("No free mscp");
asm volatile (
"xorl %0,%0\n\t"
"0: bsfw %1,%w0\n\t"
"btr %0,%1\n\t"
"jnc 0b"
: "=&r" (rv), "+m" (*field) :);
return rv;
}
static inline unsigned char xchgb(unsigned char reg,
volatile unsigned char *mem)
{
__asm__ ("xchgb %0,%1" : "=q" (reg), "=m" (*mem) : "0" (reg));
return reg;
}
static void log_ultrastor_abort(struct ultrastor_config *config,
int command)
{
static char fmt[80] = "abort %d (%x); MSCP free pool: %x;";
int i;
for (i = 0; i < ULTRASTOR_MAX_CMDS; i++)
{
fmt[20 + i*2] = ' ';
if (! (config->mscp_free & (1 << i)))
fmt[21 + i*2] = '0' + config->mscp[i].target_id;
else
fmt[21 + i*2] = '-';
}
fmt[20 + ULTRASTOR_MAX_CMDS * 2] = '\n';
fmt[21 + ULTRASTOR_MAX_CMDS * 2] = 0;
printk(fmt, command, &config->mscp[command], config->mscp_free);
}
static int ultrastor_14f_detect(struct scsi_host_template * tpnt)
{
size_t i;
unsigned char in_byte, version_byte = 0;
struct config_1 {
unsigned char bios_segment: 3;
unsigned char removable_disks_as_fixed: 1;
unsigned char interrupt: 2;
unsigned char dma_channel: 2;
} config_1;
struct config_2 {
unsigned char ha_scsi_id: 3;
unsigned char mapping_mode: 2;
unsigned char bios_drive_number: 1;
unsigned char tfr_port: 2;
} config_2;
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: called\n");
#endif
if (config.bios_segment)
return FALSE;
#ifdef PORT_OVERRIDE
if(!request_region(PORT_OVERRIDE, 0xc, "ultrastor")) {
printk("Ultrastor I/O space already in use\n");
return FALSE;
};
config.port_address = PORT_OVERRIDE;
#else
for (i = 0; i < ARRAY_SIZE(ultrastor_ports_14f); i++) {
if(!request_region(ultrastor_ports_14f[i], 0x0c, "ultrastor")) continue;
config.port_address = ultrastor_ports_14f[i];
#endif
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: testing port address %03X\n", config.port_address);
#endif
in_byte = inb(U14F_PRODUCT_ID(config.port_address));
if (in_byte != US14F_PRODUCT_ID_0) {
#if (ULTRASTOR_DEBUG & UD_DETECT)
# ifdef PORT_OVERRIDE
printk("US14F: detect: wrong product ID 0 - %02X\n", in_byte);
# else
printk("US14F: detect: no adapter at port %03X\n", config.port_address);
# endif
#endif
#ifdef PORT_OVERRIDE
goto out_release_port;
#else
release_region(config.port_address, 0x0c);
continue;
#endif
}
in_byte = inb(U14F_PRODUCT_ID(config.port_address) + 1);
if ((in_byte & 0xF0) != US14F_PRODUCT_ID_1) {
#if (ULTRASTOR_DEBUG & UD_DETECT)
# ifdef PORT_OVERRIDE
printk("US14F: detect: wrong product ID 1 - %02X\n", in_byte);
# else
printk("US14F: detect: no adapter at port %03X\n", config.port_address);
# endif
#endif
#ifdef PORT_OVERRIDE
goto out_release_port;
#else
release_region(config.port_address, 0x0c);
continue;
#endif
}
version_byte = in_byte;
#ifndef PORT_OVERRIDE
break;
}
if (i == ARRAY_SIZE(ultrastor_ports_14f)) {
# if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: no port address found!\n");
# endif
return FALSE;
}
#endif
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: adapter found at port address %03X\n",
config.port_address);
#endif
outb(ultrastor_bus_reset ? 0xc2 : 0x82, LCL_DOORBELL_MASK(config.port_address));
*(char *)&config_1 = inb(CONFIG(config.port_address + 0));
*(char *)&config_2 = inb(CONFIG(config.port_address + 1));
config.bios_segment = bios_segment_table[config_1.bios_segment];
config.doorbell_address = config.port_address;
config.ogm_address = config.port_address + 0x8;
config.icm_address = config.port_address + 0xC;
config.interrupt = interrupt_table_14f[config_1.interrupt];
config.ha_scsi_id = config_2.ha_scsi_id;
config.heads = mapping_table[config_2.mapping_mode].heads;
config.sectors = mapping_table[config_2.mapping_mode].sectors;
config.bios_drive_number = config_2.bios_drive_number;
config.subversion = (version_byte & 0x0F);
if (config.subversion == U34F)
config.dma_channel = 0;
else
config.dma_channel = dma_channel_table_14f[config_1.dma_channel];
if (!config.bios_segment) {
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: not detected.\n");
#endif
goto out_release_port;
}
if (config.subversion != U34F)
if (!config.dma_channel || !(config_2.tfr_port & 0x2)) {
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: consistency check failed\n");
#endif
goto out_release_port;
}
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US14F: detect: detect succeeded\n"
" Port address: %03X\n"
" BIOS segment: %05X\n"
" Interrupt: %u\n"
" DMA channel: %u\n"
" H/A SCSI ID: %u\n"
" Subversion: %u\n",
config.port_address, config.bios_segment, config.interrupt,
config.dma_channel, config.ha_scsi_id, config.subversion);
#endif
tpnt->this_id = config.ha_scsi_id;
tpnt->unchecked_isa_dma = (config.subversion != U34F);
#if ULTRASTOR_MAX_CMDS > 1
config.mscp_free = ~0;
#endif
if (request_irq(config.interrupt, do_ultrastor_interrupt, 0, "Ultrastor", &config.mscp[0].SCint->device->host)) {
printk("Unable to allocate IRQ%u for UltraStor controller.\n",
config.interrupt);
goto out_release_port;
}
if (config.dma_channel && request_dma(config.dma_channel,"Ultrastor")) {
printk("Unable to allocate DMA channel %u for UltraStor controller.\n",
config.dma_channel);
free_irq(config.interrupt, NULL);
goto out_release_port;
}
tpnt->sg_tablesize = ULTRASTOR_14F_MAX_SG;
printk("UltraStor driver version" VERSION ". Using %d SG lists.\n",
ULTRASTOR_14F_MAX_SG);
return TRUE;
out_release_port:
release_region(config.port_address, 0x0c);
return FALSE;
}
static int ultrastor_24f_detect(struct scsi_host_template * tpnt)
{
int i;
struct Scsi_Host * shpnt = NULL;
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US24F: detect");
#endif
for (i = 1; i < 15; i++)
{
unsigned char config_1, config_2;
unsigned short addr = (i << 12) | ULTRASTOR_24F_PORT;
if (inb(addr) != US24F_PRODUCT_ID_0 &&
inb(addr+1) != US24F_PRODUCT_ID_1 &&
inb(addr+2) != US24F_PRODUCT_ID_2)
continue;
config.revision = inb(addr+3);
config.slot = i;
if (! (inb(addr+4) & 1))
{
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("U24F: found disabled card in slot %u\n", i);
#endif
continue;
}
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("U24F: found card in slot %u\n", i);
#endif
config_1 = inb(addr + 5);
config.bios_segment = bios_segment_table[config_1 & 7];
switch(config_1 >> 4)
{
case 1:
config.interrupt = 15;
break;
case 2:
config.interrupt = 14;
break;
case 4:
config.interrupt = 11;
break;
case 8:
config.interrupt = 10;
break;
default:
printk("U24F: invalid IRQ\n");
return FALSE;
}
config.port_address = addr;
config.doorbell_address = addr + 12;
config.ogm_address = addr + 0x17;
config.icm_address = addr + 0x1C;
config_2 = inb(addr + 7);
config.ha_scsi_id = config_2 & 7;
config.heads = mapping_table[(config_2 >> 3) & 3].heads;
config.sectors = mapping_table[(config_2 >> 3) & 3].sectors;
#if (ULTRASTOR_DEBUG & UD_DETECT)
printk("US24F: detect: detect succeeded\n"
" Port address: %03X\n"
" BIOS segment: %05X\n"
" Interrupt: %u\n"
" H/A SCSI ID: %u\n",
config.port_address, config.bios_segment,
config.interrupt, config.ha_scsi_id);
#endif
tpnt->this_id = config.ha_scsi_id;
tpnt->unchecked_isa_dma = 0;
tpnt->sg_tablesize = ULTRASTOR_24F_MAX_SG;
shpnt = scsi_register(tpnt, 0);
if (!shpnt) {
printk(KERN_WARNING "(ultrastor:) Could not register scsi device. Aborting registration.\n");
free_irq(config.interrupt, do_ultrastor_interrupt);
return FALSE;
}
if (request_irq(config.interrupt, do_ultrastor_interrupt, 0, "Ultrastor", shpnt))
{
printk("Unable to allocate IRQ%u for UltraStor controller.\n",
config.interrupt);
return FALSE;
}
shpnt->irq = config.interrupt;
shpnt->dma_channel = config.dma_channel;
shpnt->io_port = config.port_address;
#if ULTRASTOR_MAX_CMDS > 1
config.mscp_free = ~0;
#endif
outb(0, addr + 0x16);
outb(0, addr + 0x1B);
outb(ultrastor_bus_reset ? 0xc2 : 0x82, LCL_DOORBELL_MASK(addr+12));
outb(0x02, SYS_DOORBELL_MASK(addr+12));
printk("UltraStor driver version " VERSION ". Using %d SG lists.\n",
tpnt->sg_tablesize);
return TRUE;
}
return FALSE;
}
static int ultrastor_detect(struct scsi_host_template * tpnt)
{
tpnt->proc_name = "ultrastor";
return ultrastor_14f_detect(tpnt) || ultrastor_24f_detect(tpnt);
}
static int ultrastor_release(struct Scsi_Host *shost)
{
if (shost->irq)
free_irq(shost->irq, NULL);
if (shost->dma_channel != 0xff)
free_dma(shost->dma_channel);
if (shost->io_port && shost->n_io_port)
release_region(shost->io_port, shost->n_io_port);
scsi_unregister(shost);
return 0;
}
static const char *ultrastor_info(struct Scsi_Host * shpnt)
{
static char buf[64];
if (config.slot)
sprintf(buf, "UltraStor 24F SCSI @ Slot %u IRQ%u",
config.slot, config.interrupt);
else if (config.subversion)
sprintf(buf, "UltraStor 34F SCSI @ Port %03X BIOS %05X IRQ%u",
config.port_address, (int)config.bios_segment,
config.interrupt);
else
sprintf(buf, "UltraStor 14F SCSI @ Port %03X BIOS %05X IRQ%u DMA%u",
config.port_address, (int)config.bios_segment,
config.interrupt, config.dma_channel);
return buf;
}
static inline void build_sg_list(struct mscp *mscp, struct scsi_cmnd *SCpnt)
{
struct scatterlist *sg;
long transfer_length = 0;
int i, max;
max = scsi_sg_count(SCpnt);
scsi_for_each_sg(SCpnt, sg, max, i) {
mscp->sglist[i].address = isa_page_to_bus(sg_page(sg)) + sg->offset;
mscp->sglist[i].num_bytes = sg->length;
transfer_length += sg->length;
}
mscp->number_of_sg_list = max;
mscp->transfer_data = isa_virt_to_bus(mscp->sglist);
mscp->transfer_data_length = transfer_length;
}
static int ultrastor_queuecommand_lck(struct scsi_cmnd *SCpnt,
void (*done) (struct scsi_cmnd *))
{
struct mscp *my_mscp;
#if ULTRASTOR_MAX_CMDS > 1
int mscp_index;
#endif
unsigned int status;
if ((config.mscp_free & ((1U << ULTRASTOR_MAX_CMDS) - 1)) == 0)
panic("ultrastor_queuecommand: no free MSCP\n");
mscp_index = find_and_clear_bit_16(&config.mscp_free);
if (xchgb(0xff, &config.aborted[mscp_index]) != 0)
{
status = DID_ABORT << 16;
goto aborted;
}
my_mscp = &config.mscp[mscp_index];
*(unsigned char *)my_mscp = OP_SCSI | (DTD_SCSI << 3);
my_mscp->ca = SCpnt->device->type != TYPE_TAPE;
my_mscp->target_id = SCpnt->device->id;
my_mscp->ch_no = 0;
my_mscp->lun = SCpnt->device->lun;
if (scsi_sg_count(SCpnt)) {
my_mscp->sg = TRUE;
build_sg_list(my_mscp, SCpnt);
} else {
my_mscp->sg = FALSE;
my_mscp->transfer_data = isa_virt_to_bus(scsi_sglist(SCpnt));
my_mscp->transfer_data_length = scsi_bufflen(SCpnt);
}
my_mscp->command_link = 0;
my_mscp->scsi_command_link_id = 0;
my_mscp->length_of_sense_byte = SCSI_SENSE_BUFFERSIZE;
my_mscp->length_of_scsi_cdbs = SCpnt->cmd_len;
memcpy(my_mscp->scsi_cdbs, SCpnt->cmnd, my_mscp->length_of_scsi_cdbs);
my_mscp->adapter_status = 0;
my_mscp->target_status = 0;
my_mscp->sense_data = isa_virt_to_bus(&SCpnt->sense_buffer);
my_mscp->done = done;
my_mscp->SCint = SCpnt;
SCpnt->host_scribble = (unsigned char *)my_mscp;
retry:
if (config.slot)
while (inb(config.ogm_address - 1) != 0 && config.aborted[mscp_index] == 0xff)
barrier();
while ((inb(LCL_DOORBELL_INTR(config.doorbell_address)) & (config.slot ? 2 : 1)) && config.aborted[mscp_index] == 0xff)
barrier();
if (inb(LCL_DOORBELL_INTR(config.doorbell_address)) & (config.slot ? 2 : 1))
goto retry;
status = xchgb(0, &config.aborted[mscp_index]);
if (status != 0xff) {
#if ULTRASTOR_DEBUG & (UD_COMMAND | UD_ABORT)
printk("USx4F: queuecommand: aborted\n");
#if ULTRASTOR_MAX_CMDS > 1
log_ultrastor_abort(&config, mscp_index);
#endif
#endif
status <<= 16;
aborted:
set_bit(mscp_index, &config.mscp_free);
#if ULTRASTOR_MAX_CMDS > 1
SCpnt->result = status;
done(SCpnt);
return 0;
#else
return status;
#endif
}
outl(isa_virt_to_bus(my_mscp), config.ogm_address);
if (config.slot) {
outb(1, config.ogm_address - 1);
outb(0x2, LCL_DOORBELL_INTR(config.doorbell_address));
} else {
outb(0x1, LCL_DOORBELL_INTR(config.doorbell_address));
}
#if (ULTRASTOR_DEBUG & UD_COMMAND)
printk("USx4F: queuecommand: returning\n");
#endif
return 0;
}
int ultrastor_host_reset(struct scsi_cmnd * SCpnt)
{
unsigned long flags;
int i;
struct Scsi_Host *host = SCpnt->device->host;
#if (ULTRASTOR_DEBUG & UD_RESET)
printk("US14F: reset: called\n");
#endif
if(config.slot)
return FAILED;
spin_lock_irqsave(host->host_lock, flags);
outb(0xc0, LCL_DOORBELL_INTR(config.doorbell_address));
if (config.slot)
{
outb(0, config.ogm_address - 1);
outb(0, config.icm_address - 1);
}
#if ULTRASTOR_MAX_CMDS == 1
if (config.mscp_busy && config.mscp->done && config.mscp->SCint)
{
config.mscp->SCint->result = DID_RESET << 16;
config.mscp->done(config.mscp->SCint);
}
config.mscp->SCint = 0;
#else
for (i = 0; i < ULTRASTOR_MAX_CMDS; i++)
{
if (! (config.mscp_free & (1 << i)) &&
config.mscp[i].done && config.mscp[i].SCint)
{
config.mscp[i].SCint->result = DID_RESET << 16;
config.mscp[i].done(config.mscp[i].SCint);
config.mscp[i].done = NULL;
}
config.mscp[i].SCint = NULL;
}
#endif
memset((unsigned char *)config.aborted, 0, sizeof config.aborted);
#if ULTRASTOR_MAX_CMDS == 1
config.mscp_busy = 0;
#else
config.mscp_free = ~0;
#endif
spin_unlock_irqrestore(host->host_lock, flags);
return SUCCESS;
}
int ultrastor_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int * dkinfo)
{
int size = capacity;
unsigned int s = config.heads * config.sectors;
dkinfo[0] = config.heads;
dkinfo[1] = config.sectors;
dkinfo[2] = size / s;
#if 0
if (dkinfo[2] > 1024)
dkinfo[2] = 1024;
#endif
return 0;
}
static void ultrastor_interrupt(void *dev_id)
{
unsigned int status;
#if ULTRASTOR_MAX_CMDS > 1
unsigned int mscp_index;
#endif
struct mscp *mscp;
void (*done) (struct scsi_cmnd *);
struct scsi_cmnd *SCtmp;
#if ULTRASTOR_MAX_CMDS == 1
mscp = &config.mscp[0];
#else
mscp = (struct mscp *)isa_bus_to_virt(inl(config.icm_address));
mscp_index = mscp - config.mscp;
if (mscp_index >= ULTRASTOR_MAX_CMDS) {
printk("Ux4F interrupt: bad MSCP address %x\n", (unsigned int) mscp);
ultrastor_host_reset(dev_id);
return;
}
#endif
if (config.slot) {
unsigned char icm_status = inb(config.icm_address - 1);
#if ULTRASTOR_DEBUG & (UD_INTERRUPT|UD_ERROR|UD_ABORT)
if (icm_status != 1 && icm_status != 2)
printk("US24F: ICM status %x for MSCP %d (%x)\n", icm_status,
mscp_index, (unsigned int) mscp);
#endif
outb(2, SYS_DOORBELL_INTR(config.doorbell_address));
outb(0, config.icm_address - 1);
if (icm_status == 4) {
printk("UltraStor abort command failed\n");
return;
}
if (icm_status == 3) {
void (*done)(struct scsi_cmnd *) = mscp->done;
if (done) {
mscp->done = NULL;
mscp->SCint->result = DID_ABORT << 16;
done(mscp->SCint);
}
return;
}
} else {
outb(1, SYS_DOORBELL_INTR(config.doorbell_address));
}
SCtmp = mscp->SCint;
mscp->SCint = NULL;
if (!SCtmp)
{
#if ULTRASTOR_DEBUG & (UD_ABORT|UD_INTERRUPT)
printk("MSCP %d (%x): no command\n", mscp_index, (unsigned int) mscp);
#endif
#if ULTRASTOR_MAX_CMDS == 1
config.mscp_busy = FALSE;
#else
set_bit(mscp_index, &config.mscp_free);
#endif
config.aborted[mscp_index] = 0;
return;
}
done = mscp->done;
mscp->done = NULL;
switch (mscp->adapter_status)
{
case 0:
status = DID_OK << 16;
break;
case 0x01:
case 0x02:
case 0x03:
default:
status = DID_ERROR << 16;
break;
case 0x84:
status = DID_ABORT << 16;
break;
case 0x91:
status = DID_TIME_OUT << 16;
break;
}
SCtmp->result = status | mscp->target_status;
SCtmp->host_scribble = NULL;
#if ULTRASTOR_MAX_CMDS == 1
config.mscp_busy = FALSE;
#else
set_bit(mscp_index, &config.mscp_free);
#endif
#if ULTRASTOR_DEBUG & (UD_ABORT|UD_INTERRUPT)
if (config.aborted[mscp_index])
printk("Ux4 interrupt: MSCP %d (%x) aborted = %d\n",
mscp_index, (unsigned int) mscp, config.aborted[mscp_index]);
#endif
config.aborted[mscp_index] = 0;
if (done)
done(SCtmp);
else
printk("US14F: interrupt: unexpected interrupt\n");
if (config.slot ? inb(config.icm_address - 1) :
(inb(SYS_DOORBELL_INTR(config.doorbell_address)) & 1))
#if (ULTRASTOR_DEBUG & UD_MULTI_CMD)
printk("Ux4F: multiple commands completed\n");
#else
;
#endif
#if (ULTRASTOR_DEBUG & UD_INTERRUPT)
printk("USx4F: interrupt: returning\n");
#endif
}
static irqreturn_t do_ultrastor_interrupt(int irq, void *dev_id)
{
unsigned long flags;
struct Scsi_Host *dev = dev_id;
spin_lock_irqsave(dev->host_lock, flags);
ultrastor_interrupt(dev_id);
spin_unlock_irqrestore(dev->host_lock, flags);
return IRQ_HANDLED;
}
