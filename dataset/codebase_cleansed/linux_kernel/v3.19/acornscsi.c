static inline void sbic_arm_write(AS_Host *host, unsigned int reg, unsigned int value)
{
writeb(reg, host->base + SBIC_REGIDX);
writeb(value, host->base + SBIC_REGVAL);
}
static inline int sbic_arm_read(AS_Host *host, unsigned int reg)
{
if(reg == SBIC_ASR)
return readl(host->base + SBIC_REGIDX) & 255;
writeb(reg, host->base + SBIC_REGIDX);
return readl(host->base + SBIC_REGVAL) & 255;
}
static inline unsigned int dmac_address(AS_Host *host)
{
return dmac_read(host, DMAC_TXADRHI) << 16 |
dmac_read(host, DMAC_TXADRMD) << 8 |
dmac_read(host, DMAC_TXADRLO);
}
static
void acornscsi_dumpdma(AS_Host *host, char *where)
{
unsigned int mode, addr, len;
mode = dmac_read(host, DMAC_MODECON);
addr = dmac_address(host);
len = dmac_read(host, DMAC_TXCNTHI) << 8 |
dmac_read(host, DMAC_TXCNTLO);
printk("scsi%d: %s: DMAC %02x @%06x+%04x msk %02x, ",
host->host->host_no, where,
mode, addr, (len + 1) & 0xffff,
dmac_read(host, DMAC_MASKREG));
printk("DMA @%06x, ", host->dma.start_addr);
printk("BH @%p +%04x, ", host->scsi.SCp.ptr,
host->scsi.SCp.this_residual);
printk("DT @+%04x ST @+%04x", host->dma.transferred,
host->scsi.SCp.scsi_xferred);
printk("\n");
}
static
unsigned long acornscsi_sbic_xfcount(AS_Host *host)
{
unsigned long length;
length = sbic_arm_read(host, SBIC_TRANSCNTH) << 16;
length |= sbic_arm_readnext(host) << 8;
length |= sbic_arm_readnext(host);
return length;
}
static int
acornscsi_sbic_wait(AS_Host *host, int stat_mask, int stat, int timeout, char *msg)
{
int asr;
do {
asr = sbic_arm_read(host, SBIC_ASR);
if ((asr & stat_mask) == stat)
return 0;
udelay(1);
} while (--timeout);
printk("scsi%d: timeout while %s\n", host->host->host_no, msg);
return -1;
}
static
int acornscsi_sbic_issuecmd(AS_Host *host, int command)
{
if (acornscsi_sbic_wait(host, ASR_CIP, 0, 1000, "issuing command"))
return -1;
sbic_arm_write(host, SBIC_CMND, command);
return 0;
}
static void
acornscsi_csdelay(unsigned int cs)
{
unsigned long target_jiffies, flags;
target_jiffies = jiffies + 1 + cs * HZ / 100;
local_save_flags(flags);
local_irq_enable();
while (time_before(jiffies, target_jiffies)) barrier();
local_irq_restore(flags);
}
static
void acornscsi_resetcard(AS_Host *host)
{
unsigned int i, timeout;
host->card.page_reg = 0x80;
writeb(host->card.page_reg, host->fast + PAGE_REG);
acornscsi_csdelay(3);
host->card.page_reg = 0;
writeb(host->card.page_reg, host->fast + PAGE_REG);
timeout = 1000;
do {
if (readb(host->fast + INT_REG) & 8)
break;
udelay(1);
} while (--timeout);
if (timeout == 0)
printk("scsi%d: timeout while resetting card\n",
host->host->host_no);
sbic_arm_read(host, SBIC_ASR);
sbic_arm_read(host, SBIC_SSR);
sbic_arm_write(host, SBIC_OWNID, OWNID_EAF | host->host->this_id);
sbic_arm_write(host, SBIC_CMND, CMND_RESET);
timeout = 1000;
do {
if (readb(host->fast + INT_REG) & 8)
break;
udelay(1);
} while (--timeout);
if (timeout == 0)
printk("scsi%d: timeout while resetting card\n",
host->host->host_no);
sbic_arm_read(host, SBIC_ASR);
if (sbic_arm_read(host, SBIC_SSR) != 0x01)
printk(KERN_CRIT "scsi%d: WD33C93A didn't give enhanced reset interrupt\n",
host->host->host_no);
sbic_arm_write(host, SBIC_CTRL, INIT_SBICDMA | CTRL_IDI);
sbic_arm_write(host, SBIC_TIMEOUT, TIMEOUT_TIME);
sbic_arm_write(host, SBIC_SYNCHTRANSFER, SYNCHTRANSFER_2DBA);
sbic_arm_write(host, SBIC_SOURCEID, SOURCEID_ER | SOURCEID_DSP);
host->card.page_reg = 0x40;
writeb(host->card.page_reg, host->fast + PAGE_REG);
dmac_write(host, DMAC_INIT, 0);
#ifdef USE_DMAC
dmac_write(host, DMAC_INIT, INIT_8BIT);
dmac_write(host, DMAC_CHANNEL, CHANNEL_0);
dmac_write(host, DMAC_DEVCON0, INIT_DEVCON0);
dmac_write(host, DMAC_DEVCON1, INIT_DEVCON1);
#endif
host->SCpnt = NULL;
host->scsi.phase = PHASE_IDLE;
host->scsi.disconnectable = 0;
memset(host->busyluns, 0, sizeof(host->busyluns));
for (i = 0; i < 8; i++) {
host->device[i].sync_state = SYNC_NEGOCIATE;
host->device[i].disconnect_ok = 1;
}
acornscsi_csdelay(25);
}
static
void print_scsi_status(unsigned int ssr)
{
if (acornscsi_map[ssr] != -1)
printk("%s:%s",
acornscsi_interrupttype[(ssr >> 4)],
acornscsi_interruptcode[acornscsi_map[ssr]]);
else
printk("%X:%X", ssr >> 4, ssr & 0x0f);
}
static
void print_sbic_status(int asr, int ssr, int cmdphase)
{
#ifdef CONFIG_ACORNSCSI_CONSTANTS
printk("sbic: %c%c%c%c%c%c ",
asr & ASR_INT ? 'I' : 'i',
asr & ASR_LCI ? 'L' : 'l',
asr & ASR_BSY ? 'B' : 'b',
asr & ASR_CIP ? 'C' : 'c',
asr & ASR_PE ? 'P' : 'p',
asr & ASR_DBR ? 'D' : 'd');
printk("scsi: ");
print_scsi_status(ssr);
printk(" ph %02X\n", cmdphase);
#else
printk("sbic: %02X scsi: %X:%X ph: %02X\n",
asr, (ssr & 0xf0)>>4, ssr & 0x0f, cmdphase);
#endif
}
static void
acornscsi_dumplogline(AS_Host *host, int target, int line)
{
unsigned long prev;
signed int ptr;
ptr = host->status_ptr[target] - STATUS_BUFFER_TO_PRINT;
if (ptr < 0)
ptr += STATUS_BUFFER_SIZE;
printk("%c: %3s:", target == 8 ? 'H' : '0' + target,
line == 0 ? "ph" : line == 1 ? "ssr" : "int");
prev = host->status[target][ptr].when;
for (; ptr != host->status_ptr[target]; ptr = (ptr + 1) & (STATUS_BUFFER_SIZE - 1)) {
unsigned long time_diff;
if (!host->status[target][ptr].when)
continue;
switch (line) {
case 0:
printk("%c%02X", host->status[target][ptr].irq ? '-' : ' ',
host->status[target][ptr].ph);
break;
case 1:
printk(" %02X", host->status[target][ptr].ssr);
break;
case 2:
time_diff = host->status[target][ptr].when - prev;
prev = host->status[target][ptr].when;
if (time_diff == 0)
printk("==^");
else if (time_diff >= 100)
printk(" ");
else
printk(" %02ld", time_diff);
break;
}
}
printk("\n");
}
static
void acornscsi_dumplog(AS_Host *host, int target)
{
do {
acornscsi_dumplogline(host, target, 0);
acornscsi_dumplogline(host, target, 1);
acornscsi_dumplogline(host, target, 2);
if (target == 8)
break;
target = 8;
} while (1);
}
static
char acornscsi_target(AS_Host *host)
{
if (host->SCpnt)
return '0' + host->SCpnt->device->id;
return 'H';
}
static inline
cmdtype_t acornscsi_cmdtype(int command)
{
switch (command) {
case WRITE_6: case WRITE_10: case WRITE_12:
return CMD_WRITE;
case READ_6: case READ_10: case READ_12:
return CMD_READ;
default:
return CMD_MISC;
}
}
static
datadir_t acornscsi_datadirection(int command)
{
switch (command) {
case CHANGE_DEFINITION: case COMPARE: case COPY:
case COPY_VERIFY: case LOG_SELECT: case MODE_SELECT:
case MODE_SELECT_10: case SEND_DIAGNOSTIC: case WRITE_BUFFER:
case FORMAT_UNIT: case REASSIGN_BLOCKS: case RESERVE:
case SEARCH_EQUAL: case SEARCH_HIGH: case SEARCH_LOW:
case WRITE_6: case WRITE_10: case WRITE_VERIFY:
case UPDATE_BLOCK: case WRITE_LONG: case WRITE_SAME:
case SEARCH_HIGH_12: case SEARCH_EQUAL_12: case SEARCH_LOW_12:
case WRITE_12: case WRITE_VERIFY_12: case SET_WINDOW:
case MEDIUM_SCAN: case SEND_VOLUME_TAG: case 0xea:
return DATADIR_OUT;
default:
return DATADIR_IN;
}
}
static
int acornscsi_getperiod(unsigned char syncxfer)
{
int i;
syncxfer &= 0xf0;
if (syncxfer == 0x10)
syncxfer = 0;
for (i = 1; sync_xfer_table[i].period_ns; i++)
if (syncxfer == sync_xfer_table[i].reg_value)
return sync_xfer_table[i].period_ns;
return 0;
}
static inline
int round_period(unsigned int period)
{
int i;
for (i = 1; sync_xfer_table[i].period_ns; i++) {
if ((period <= sync_xfer_table[i].period_ns) &&
(period > sync_xfer_table[i - 1].period_ns))
return i;
}
return 7;
}
static
unsigned char calc_sync_xfer(unsigned int period, unsigned int offset)
{
return sync_xfer_table[round_period(period)].reg_value |
((offset < SDTR_SIZE) ? offset : SDTR_SIZE);
}
static
intr_ret_t acornscsi_kick(AS_Host *host)
{
int from_queue = 0;
struct scsi_cmnd *SCpnt;
SCpnt = host->origSCpnt;
host->origSCpnt = NULL;
if (!SCpnt) {
SCpnt = queue_remove_exclude(&host->queues.issue, host->busyluns);
if (!SCpnt)
return INTR_IDLE;
from_queue = 1;
}
if (host->scsi.disconnectable && host->SCpnt) {
queue_add_cmd_tail(&host->queues.disconnected, host->SCpnt);
host->scsi.disconnectable = 0;
#if (DEBUG & (DEBUG_QUEUES|DEBUG_DISCON))
DBG(host->SCpnt, printk("scsi%d.%c: moved command to disconnected queue\n",
host->host->host_no, acornscsi_target(host)));
#endif
host->SCpnt = NULL;
}
if (!(sbic_arm_read(host, SBIC_ASR) & (ASR_INT|ASR_BSY|ASR_CIP))) {
sbic_arm_write(host, SBIC_DESTID, SCpnt->device->id);
sbic_arm_write(host, SBIC_CMND, CMND_SELWITHATN);
}
host->scsi.phase = PHASE_CONNECTING;
host->SCpnt = SCpnt;
host->scsi.SCp = SCpnt->SCp;
host->dma.xfer_setup = 0;
host->dma.xfer_required = 0;
host->dma.xfer_done = 0;
#if (DEBUG & (DEBUG_ABORT|DEBUG_CONNECT))
DBG(SCpnt,printk("scsi%d.%c: starting cmd %02X\n",
host->host->host_no, '0' + SCpnt->device->id,
SCpnt->cmnd[0]));
#endif
if (from_queue) {
#ifdef CONFIG_SCSI_ACORNSCSI_TAGGED_QUEUE
if (SCpnt->device->simple_tags) {
SCpnt->device->current_tag += 1;
if (SCpnt->device->current_tag == 0)
SCpnt->device->current_tag = 1;
SCpnt->tag = SCpnt->device->current_tag;
} else
#endif
set_bit(SCpnt->device->id * 8 +
(u8)(SCpnt->device->lun & 0x07), host->busyluns);
host->stats.removes += 1;
switch (acornscsi_cmdtype(SCpnt->cmnd[0])) {
case CMD_WRITE:
host->stats.writes += 1;
break;
case CMD_READ:
host->stats.reads += 1;
break;
case CMD_MISC:
host->stats.miscs += 1;
break;
}
}
return INTR_PROCESSING;
}
static void acornscsi_done(AS_Host *host, struct scsi_cmnd **SCpntp,
unsigned int result)
{
struct scsi_cmnd *SCpnt = *SCpntp;
sbic_arm_write(host, SBIC_SOURCEID, SOURCEID_ER | SOURCEID_DSP);
host->stats.fins += 1;
if (SCpnt) {
*SCpntp = NULL;
acornscsi_dma_cleanup(host);
SCpnt->result = result << 16 | host->scsi.SCp.Message << 8 | host->scsi.SCp.Status;
if (result == DID_OK) {
int xfer_warn = 0;
if (SCpnt->underflow == 0) {
if (host->scsi.SCp.ptr &&
acornscsi_cmdtype(SCpnt->cmnd[0]) != CMD_MISC)
xfer_warn = 1;
} else {
if (host->scsi.SCp.scsi_xferred < SCpnt->underflow ||
host->scsi.SCp.scsi_xferred != host->dma.transferred)
xfer_warn = 1;
}
if (host->dma.xfer_done)
xfer_warn = 0;
if (xfer_warn) {
switch (status_byte(SCpnt->result)) {
case CHECK_CONDITION:
case COMMAND_TERMINATED:
case BUSY:
case QUEUE_FULL:
case RESERVATION_CONFLICT:
break;
default:
scmd_printk(KERN_ERR, SCpnt,
"incomplete data transfer detected: "
"result=%08X", SCpnt->result);
scsi_print_command(SCpnt);
acornscsi_dumpdma(host, "done");
acornscsi_dumplog(host, SCpnt->device->id);
set_host_byte(SCpnt, DID_ERROR);
}
}
}
if (!SCpnt->scsi_done)
panic("scsi%d.H: null scsi_done function in acornscsi_done", host->host->host_no);
clear_bit(SCpnt->device->id * 8 +
(u8)(SCpnt->device->lun & 0x7), host->busyluns);
SCpnt->scsi_done(SCpnt);
} else
printk("scsi%d: null command in acornscsi_done", host->host->host_no);
host->scsi.phase = PHASE_IDLE;
}
static
void acornscsi_data_updateptr(AS_Host *host, struct scsi_pointer *SCp, unsigned int length)
{
SCp->ptr += length;
SCp->this_residual -= length;
if (SCp->this_residual == 0 && next_SCp(SCp) == 0)
host->dma.xfer_done = 1;
}
static
void acornscsi_data_read(AS_Host *host, char *ptr,
unsigned int start_addr, unsigned int length)
{
extern void __acornscsi_in(void __iomem *, char *buf, int len);
unsigned int page, offset, len = length;
page = (start_addr >> 12);
offset = start_addr & ((1 << 12) - 1);
writeb((page & 0x3f) | host->card.page_reg, host->fast + PAGE_REG);
while (len > 0) {
unsigned int this_len;
if (len + offset > (1 << 12))
this_len = (1 << 12) - offset;
else
this_len = len;
__acornscsi_in(host->base + (offset << 1), ptr, this_len);
offset += this_len;
ptr += this_len;
len -= this_len;
if (offset == (1 << 12)) {
offset = 0;
page ++;
writeb((page & 0x3f) | host->card.page_reg, host->fast + PAGE_REG);
}
}
writeb(host->card.page_reg, host->fast + PAGE_REG);
}
static
void acornscsi_data_write(AS_Host *host, char *ptr,
unsigned int start_addr, unsigned int length)
{
extern void __acornscsi_out(void __iomem *, char *buf, int len);
unsigned int page, offset, len = length;
page = (start_addr >> 12);
offset = start_addr & ((1 << 12) - 1);
writeb((page & 0x3f) | host->card.page_reg, host->fast + PAGE_REG);
while (len > 0) {
unsigned int this_len;
if (len + offset > (1 << 12))
this_len = (1 << 12) - offset;
else
this_len = len;
__acornscsi_out(host->base + (offset << 1), ptr, this_len);
offset += this_len;
ptr += this_len;
len -= this_len;
if (offset == (1 << 12)) {
offset = 0;
page ++;
writeb((page & 0x3f) | host->card.page_reg, host->fast + PAGE_REG);
}
}
writeb(host->card.page_reg, host->fast + PAGE_REG);
}
static inline
void acornscsi_dma_stop(AS_Host *host)
{
dmac_write(host, DMAC_MASKREG, MASK_ON);
dmac_clearintr(host);
#if (DEBUG & DEBUG_DMA)
DBG(host->SCpnt, acornscsi_dumpdma(host, "stop"));
#endif
}
static
void acornscsi_dma_setup(AS_Host *host, dmadir_t direction)
{
unsigned int address, length, mode;
host->dma.direction = direction;
dmac_write(host, DMAC_MASKREG, MASK_ON);
if (direction == DMA_OUT) {
#if (DEBUG & DEBUG_NO_WRITE)
if (NO_WRITE & (1 << host->SCpnt->device->id)) {
printk(KERN_CRIT "scsi%d.%c: I can't handle DMA_OUT!\n",
host->host->host_no, acornscsi_target(host));
return;
}
#endif
mode = DMAC_WRITE;
} else
mode = DMAC_READ;
length = min_t(unsigned int, host->scsi.SCp.this_residual, DMAC_BUFFER_SIZE / 2);
if (length) {
host->dma.start_addr = address = host->dma.free_addr;
host->dma.free_addr = (host->dma.free_addr + length) &
(DMAC_BUFFER_SIZE - 1);
if (direction == DMA_OUT)
acornscsi_data_write(host, host->scsi.SCp.ptr, host->dma.start_addr,
length);
length -= 1;
dmac_write(host, DMAC_TXCNTLO, length);
dmac_write(host, DMAC_TXCNTHI, length >> 8);
dmac_write(host, DMAC_TXADRLO, address);
dmac_write(host, DMAC_TXADRMD, address >> 8);
dmac_write(host, DMAC_TXADRHI, 0);
dmac_write(host, DMAC_MODECON, mode);
dmac_write(host, DMAC_MASKREG, MASK_OFF);
#if (DEBUG & DEBUG_DMA)
DBG(host->SCpnt, acornscsi_dumpdma(host, "strt"));
#endif
host->dma.xfer_setup = 1;
}
}
static
void acornscsi_dma_cleanup(AS_Host *host)
{
dmac_write(host, DMAC_MASKREG, MASK_ON);
dmac_clearintr(host);
if (host->dma.xfer_required) {
host->dma.xfer_required = 0;
if (host->dma.direction == DMA_IN)
acornscsi_data_read(host, host->dma.xfer_ptr,
host->dma.xfer_start, host->dma.xfer_length);
}
if (host->dma.xfer_setup) {
unsigned int transferred;
host->dma.xfer_setup = 0;
#if (DEBUG & DEBUG_DMA)
DBG(host->SCpnt, acornscsi_dumpdma(host, "cupi"));
#endif
transferred = dmac_address(host) - host->dma.start_addr;
host->dma.transferred += transferred;
if (host->dma.direction == DMA_IN)
acornscsi_data_read(host, host->scsi.SCp.ptr,
host->dma.start_addr, transferred);
acornscsi_data_updateptr(host, &host->scsi.SCp, transferred);
#if (DEBUG & DEBUG_DMA)
DBG(host->SCpnt, acornscsi_dumpdma(host, "cupo"));
#endif
}
}
static
void acornscsi_dma_intr(AS_Host *host)
{
unsigned int address, length, transferred;
#if (DEBUG & DEBUG_DMA)
DBG(host->SCpnt, acornscsi_dumpdma(host, "inti"));
#endif
dmac_write(host, DMAC_MASKREG, MASK_ON);
dmac_clearintr(host);
transferred = dmac_address(host) - host->dma.start_addr;
host->dma.transferred += transferred;
if (host->dma.direction == DMA_IN) {
host->dma.xfer_start = host->dma.start_addr;
host->dma.xfer_length = transferred;
host->dma.xfer_ptr = host->scsi.SCp.ptr;
host->dma.xfer_required = 1;
}
acornscsi_data_updateptr(host, &host->scsi.SCp, transferred);
length = min_t(unsigned int, host->scsi.SCp.this_residual, DMAC_BUFFER_SIZE / 2);
if (length) {
host->dma.start_addr = address = host->dma.free_addr;
host->dma.free_addr = (host->dma.free_addr + length) &
(DMAC_BUFFER_SIZE - 1);
if (host->dma.direction == DMA_OUT)
acornscsi_data_write(host, host->scsi.SCp.ptr, host->dma.start_addr,
length);
length -= 1;
dmac_write(host, DMAC_TXCNTLO, length);
dmac_write(host, DMAC_TXCNTHI, length >> 8);
dmac_write(host, DMAC_TXADRLO, address);
dmac_write(host, DMAC_TXADRMD, address >> 8);
dmac_write(host, DMAC_TXADRHI, 0);
dmac_write(host, DMAC_MASKREG, MASK_OFF);
#if (DEBUG & DEBUG_DMA)
DBG(host->SCpnt, acornscsi_dumpdma(host, "into"));
#endif
} else {
host->dma.xfer_setup = 0;
#if 0
if (dmac_read(host, DMAC_STATUS) & STATUS_RQ0) {
acornscsi_abortcmd(host, host->SCpnt->tag);
dmac_write(host, DMAC_TXCNTLO, 0);
dmac_write(host, DMAC_TXCNTHI, 0);
dmac_write(host, DMAC_TXADRLO, 0);
dmac_write(host, DMAC_TXADRMD, 0);
dmac_write(host, DMAC_TXADRHI, 0);
dmac_write(host, DMAC_MASKREG, MASK_OFF);
}
#endif
}
}
static
void acornscsi_dma_xfer(AS_Host *host)
{
host->dma.xfer_required = 0;
if (host->dma.direction == DMA_IN)
acornscsi_data_read(host, host->dma.xfer_ptr,
host->dma.xfer_start, host->dma.xfer_length);
}
static
void acornscsi_dma_adjust(AS_Host *host)
{
if (host->dma.xfer_setup) {
signed long transferred;
#if (DEBUG & (DEBUG_DMA|DEBUG_WRITE))
DBG(host->SCpnt, acornscsi_dumpdma(host, "adji"));
#endif
transferred = host->scsi.SCp.scsi_xferred - host->dma.transferred;
if (transferred < 0)
printk("scsi%d.%c: Ack! DMA write correction %ld < 0!\n",
host->host->host_no, acornscsi_target(host), transferred);
else if (transferred == 0)
host->dma.xfer_setup = 0;
else {
transferred += host->dma.start_addr;
dmac_write(host, DMAC_TXADRLO, transferred);
dmac_write(host, DMAC_TXADRMD, transferred >> 8);
dmac_write(host, DMAC_TXADRHI, transferred >> 16);
#if (DEBUG & (DEBUG_DMA|DEBUG_WRITE))
DBG(host->SCpnt, acornscsi_dumpdma(host, "adjo"));
#endif
}
}
}
static int
acornscsi_write_pio(AS_Host *host, char *bytes, int *ptr, int len, unsigned int max_timeout)
{
unsigned int asr, timeout = max_timeout;
int my_ptr = *ptr;
while (my_ptr < len) {
asr = sbic_arm_read(host, SBIC_ASR);
if (asr & ASR_DBR) {
timeout = max_timeout;
sbic_arm_write(host, SBIC_DATA, bytes[my_ptr++]);
} else if (asr & ASR_INT)
break;
else if (--timeout == 0)
break;
udelay(1);
}
*ptr = my_ptr;
return (timeout == 0) ? -1 : 0;
}
static void
acornscsi_sendcommand(AS_Host *host)
{
struct scsi_cmnd *SCpnt = host->SCpnt;
sbic_arm_write(host, SBIC_TRANSCNTH, 0);
sbic_arm_writenext(host, 0);
sbic_arm_writenext(host, SCpnt->cmd_len - host->scsi.SCp.sent_command);
acornscsi_sbic_issuecmd(host, CMND_XFERINFO);
if (acornscsi_write_pio(host, SCpnt->cmnd,
(int *)&host->scsi.SCp.sent_command, SCpnt->cmd_len, 1000000))
printk("scsi%d: timeout while sending command\n", host->host->host_no);
host->scsi.phase = PHASE_COMMAND;
}
static
void acornscsi_sendmessage(AS_Host *host)
{
unsigned int message_length = msgqueue_msglength(&host->scsi.msgs);
unsigned int msgnr;
struct message *msg;
#if (DEBUG & DEBUG_MESSAGES)
printk("scsi%d.%c: sending message ",
host->host->host_no, acornscsi_target(host));
#endif
switch (message_length) {
case 0:
acornscsi_sbic_issuecmd(host, CMND_XFERINFO | CMND_SBT);
acornscsi_sbic_wait(host, ASR_DBR, ASR_DBR, 1000, "sending message 1");
sbic_arm_write(host, SBIC_DATA, NOP);
host->scsi.last_message = NOP;
#if (DEBUG & DEBUG_MESSAGES)
printk("NOP");
#endif
break;
case 1:
acornscsi_sbic_issuecmd(host, CMND_XFERINFO | CMND_SBT);
msg = msgqueue_getmsg(&host->scsi.msgs, 0);
acornscsi_sbic_wait(host, ASR_DBR, ASR_DBR, 1000, "sending message 2");
sbic_arm_write(host, SBIC_DATA, msg->msg[0]);
host->scsi.last_message = msg->msg[0];
#if (DEBUG & DEBUG_MESSAGES)
spi_print_msg(msg->msg);
#endif
break;
default:
sbic_arm_write(host, SBIC_TRANSCNTH, 0);
sbic_arm_writenext(host, 0);
sbic_arm_writenext(host, message_length);
acornscsi_sbic_issuecmd(host, CMND_XFERINFO);
msgnr = 0;
while ((msg = msgqueue_getmsg(&host->scsi.msgs, msgnr++)) != NULL) {
unsigned int i;
#if (DEBUG & DEBUG_MESSAGES)
spi_print_msg(msg);
#endif
i = 0;
if (acornscsi_write_pio(host, msg->msg, &i, msg->length, 1000000))
printk("scsi%d: timeout while sending message\n", host->host->host_no);
host->scsi.last_message = msg->msg[0];
if (msg->msg[0] == EXTENDED_MESSAGE)
host->scsi.last_message |= msg->msg[2] << 8;
if (i != msg->length)
break;
}
break;
}
#if (DEBUG & DEBUG_MESSAGES)
printk("\n");
#endif
}
static
void acornscsi_readstatusbyte(AS_Host *host)
{
acornscsi_sbic_issuecmd(host, CMND_XFERINFO|CMND_SBT);
acornscsi_sbic_wait(host, ASR_DBR, ASR_DBR, 1000, "reading status byte");
host->scsi.SCp.Status = sbic_arm_read(host, SBIC_DATA);
}
static
unsigned char acornscsi_readmessagebyte(AS_Host *host)
{
unsigned char message;
acornscsi_sbic_issuecmd(host, CMND_XFERINFO | CMND_SBT);
acornscsi_sbic_wait(host, ASR_DBR, ASR_DBR, 1000, "for message byte");
message = sbic_arm_read(host, SBIC_DATA);
acornscsi_sbic_wait(host, ASR_INT, ASR_INT, 1000, "for interrupt after message byte");
sbic_arm_read(host, SBIC_SSR);
return message;
}
static
void acornscsi_message(AS_Host *host)
{
unsigned char message[16];
unsigned int msgidx = 0, msglen = 1;
do {
message[msgidx] = acornscsi_readmessagebyte(host);
switch (msgidx) {
case 0:
if (message[0] == EXTENDED_MESSAGE ||
(message[0] >= 0x20 && message[0] <= 0x2f))
msglen = 2;
break;
case 1:
if (message[0] == EXTENDED_MESSAGE)
msglen += message[msgidx];
break;
}
msgidx += 1;
if (msgidx < msglen) {
acornscsi_sbic_issuecmd(host, CMND_NEGATEACK);
acornscsi_sbic_wait(host, ASR_INT, ASR_INT, 1000, "for interrupt after negate ack");
sbic_arm_read(host, SBIC_SSR);
}
} while (msgidx < msglen);
#if (DEBUG & DEBUG_MESSAGES)
printk("scsi%d.%c: message in: ",
host->host->host_no, acornscsi_target(host));
spi_print_msg(message);
printk("\n");
#endif
if (host->scsi.phase == PHASE_RECONNECTED) {
if (message[0] == SIMPLE_QUEUE_TAG)
host->scsi.reconnected.tag = message[1];
if (acornscsi_reconnect_finish(host))
host->scsi.phase = PHASE_MSGIN;
}
switch (message[0]) {
case ABORT:
case ABORT_TAG:
case COMMAND_COMPLETE:
if (host->scsi.phase != PHASE_STATUSIN) {
printk(KERN_ERR "scsi%d.%c: command complete following non-status in phase?\n",
host->host->host_no, acornscsi_target(host));
acornscsi_dumplog(host, host->SCpnt->device->id);
}
host->scsi.phase = PHASE_DONE;
host->scsi.SCp.Message = message[0];
break;
case SAVE_POINTERS:
acornscsi_dma_cleanup(host);
host->SCpnt->SCp = host->scsi.SCp;
host->SCpnt->SCp.sent_command = 0;
host->scsi.phase = PHASE_MSGIN;
break;
case RESTORE_POINTERS:
acornscsi_dma_cleanup(host);
host->scsi.SCp = host->SCpnt->SCp;
host->scsi.phase = PHASE_MSGIN;
break;
case DISCONNECT:
acornscsi_dma_cleanup(host);
host->scsi.phase = PHASE_DISCONNECT;
break;
case MESSAGE_REJECT:
#if 0
if (host->device[host->SCpnt->device->id].sync_state == SYNC_SENT_REQUEST)
host->device[host->SCpnt->device->id].sync_state = SYNC_NEGOCIATE;
#endif
if (msgqueue_msglength(&host->scsi.msgs))
acornscsi_sbic_issuecmd(host, CMND_ASSERTATN);
switch (host->scsi.last_message) {
#ifdef CONFIG_SCSI_ACORNSCSI_TAGGED_QUEUE
case HEAD_OF_QUEUE_TAG:
case ORDERED_QUEUE_TAG:
case SIMPLE_QUEUE_TAG:
printk(KERN_NOTICE "scsi%d.%c: disabling tagged queueing\n",
host->host->host_no, acornscsi_target(host));
host->SCpnt->device->simple_tags = 0;
set_bit(host->SCpnt->device->id * 8 +
(u8)(host->SCpnt->device->lun & 0x7), host->busyluns);
break;
#endif
case EXTENDED_MESSAGE | (EXTENDED_SDTR << 8):
printk(KERN_NOTICE "scsi%d.%c: Using asynchronous transfer\n",
host->host->host_no, acornscsi_target(host));
host->device[host->SCpnt->device->id].sync_xfer = SYNCHTRANSFER_2DBA;
host->device[host->SCpnt->device->id].sync_state = SYNC_ASYNCHRONOUS;
sbic_arm_write(host, SBIC_SYNCHTRANSFER, host->device[host->SCpnt->device->id].sync_xfer);
break;
default:
break;
}
break;
case QUEUE_FULL:
break;
case SIMPLE_QUEUE_TAG:
printk("scsi%d.%c: reconnect queue tag %02X\n",
host->host->host_no, acornscsi_target(host),
message[1]);
break;
case EXTENDED_MESSAGE:
switch (message[2]) {
#ifdef CONFIG_SCSI_ACORNSCSI_SYNC
case EXTENDED_SDTR:
if (host->device[host->SCpnt->device->id].sync_state == SYNC_SENT_REQUEST) {
host->device[host->SCpnt->device->id].sync_state = SYNC_COMPLETED;
printk(KERN_NOTICE "scsi%d.%c: Using synchronous transfer, offset %d, %d ns\n",
host->host->host_no, acornscsi_target(host),
message[4], message[3] * 4);
host->device[host->SCpnt->device->id].sync_xfer =
calc_sync_xfer(message[3] * 4, message[4]);
} else {
unsigned char period, length;
acornscsi_sbic_issuecmd(host, CMND_ASSERTATN);
period = max_t(unsigned int, message[3], sdtr_period / 4);
length = min_t(unsigned int, message[4], sdtr_size);
msgqueue_addmsg(&host->scsi.msgs, 5, EXTENDED_MESSAGE, 3,
EXTENDED_SDTR, period, length);
host->device[host->SCpnt->device->id].sync_xfer =
calc_sync_xfer(period * 4, length);
}
sbic_arm_write(host, SBIC_SYNCHTRANSFER, host->device[host->SCpnt->device->id].sync_xfer);
break;
#else
#endif
case EXTENDED_WDTR:
default:
acornscsi_sbic_issuecmd(host, CMND_ASSERTATN);
msgqueue_flush(&host->scsi.msgs);
msgqueue_addmsg(&host->scsi.msgs, 1, MESSAGE_REJECT);
break;
}
break;
default:
printk(KERN_ERR "scsi%d.%c: unrecognised message %02X, rejecting\n",
host->host->host_no, acornscsi_target(host),
message[0]);
acornscsi_sbic_issuecmd(host, CMND_ASSERTATN);
msgqueue_flush(&host->scsi.msgs);
msgqueue_addmsg(&host->scsi.msgs, 1, MESSAGE_REJECT);
host->scsi.phase = PHASE_MSGIN;
break;
}
acornscsi_sbic_issuecmd(host, CMND_NEGATEACK);
}
static
void acornscsi_buildmessages(AS_Host *host)
{
#if 0
if (cmd_reset) {
msgqueue_addmsg(&host->scsi.msgs, 1, BUS_DEVICE_RESET);
return;
}
#endif
msgqueue_addmsg(&host->scsi.msgs, 1,
IDENTIFY(host->device[host->SCpnt->device->id].disconnect_ok,
host->SCpnt->device->lun));
#if 0
if (cmd_aborted) {
acornscsi_abortcmd(host->SCpnt->tag);
return;
}
#endif
#ifdef CONFIG_SCSI_ACORNSCSI_TAGGED_QUEUE
if (host->SCpnt->tag) {
unsigned int tag_type;
if (host->SCpnt->cmnd[0] == REQUEST_SENSE ||
host->SCpnt->cmnd[0] == TEST_UNIT_READY ||
host->SCpnt->cmnd[0] == INQUIRY)
tag_type = HEAD_OF_QUEUE_TAG;
else
tag_type = SIMPLE_QUEUE_TAG;
msgqueue_addmsg(&host->scsi.msgs, 2, tag_type, host->SCpnt->tag);
}
#endif
#ifdef CONFIG_SCSI_ACORNSCSI_SYNC
if (host->device[host->SCpnt->device->id].sync_state == SYNC_NEGOCIATE) {
host->device[host->SCpnt->device->id].sync_state = SYNC_SENT_REQUEST;
msgqueue_addmsg(&host->scsi.msgs, 5,
EXTENDED_MESSAGE, 3, EXTENDED_SDTR,
sdtr_period / 4, sdtr_size);
}
#endif
}
static
int acornscsi_starttransfer(AS_Host *host)
{
int residual;
if (!host->scsi.SCp.ptr ) {
printk(KERN_ERR "scsi%d.%c: null buffer passed to acornscsi_starttransfer\n",
host->host->host_no, acornscsi_target(host));
return 0;
}
residual = scsi_bufflen(host->SCpnt) - host->scsi.SCp.scsi_xferred;
sbic_arm_write(host, SBIC_SYNCHTRANSFER, host->device[host->SCpnt->device->id].sync_xfer);
sbic_arm_writenext(host, residual >> 16);
sbic_arm_writenext(host, residual >> 8);
sbic_arm_writenext(host, residual);
acornscsi_sbic_issuecmd(host, CMND_XFERINFO);
return 1;
}
static
int acornscsi_reconnect(AS_Host *host)
{
unsigned int target, lun, ok = 0;
target = sbic_arm_read(host, SBIC_SOURCEID);
if (!(target & 8))
printk(KERN_ERR "scsi%d: invalid source id after reselection "
"- device fault?\n",
host->host->host_no);
target &= 7;
if (host->SCpnt && !host->scsi.disconnectable) {
printk(KERN_ERR "scsi%d.%d: reconnected while command in "
"progress to target %d?\n",
host->host->host_no, target, host->SCpnt->device->id);
host->SCpnt = NULL;
}
lun = sbic_arm_read(host, SBIC_DATA) & 7;
host->scsi.reconnected.target = target;
host->scsi.reconnected.lun = lun;
host->scsi.reconnected.tag = 0;
if (host->scsi.disconnectable && host->SCpnt &&
host->SCpnt->device->id == target && host->SCpnt->device->lun == lun)
ok = 1;
if (!ok && queue_probetgtlun(&host->queues.disconnected, target, lun))
ok = 1;
ADD_STATUS(target, 0x81, host->scsi.phase, 0);
if (ok) {
host->scsi.phase = PHASE_RECONNECTED;
} else {
printk(KERN_ERR "scsi%d.%c: reselected with no command "
"to reconnect with\n",
host->host->host_no, '0' + target);
acornscsi_dumplog(host, target);
acornscsi_abortcmd(host, 0);
if (host->SCpnt) {
queue_add_cmd_tail(&host->queues.disconnected, host->SCpnt);
host->SCpnt = NULL;
}
}
acornscsi_sbic_issuecmd(host, CMND_NEGATEACK);
return !ok;
}
static
int acornscsi_reconnect_finish(AS_Host *host)
{
if (host->scsi.disconnectable && host->SCpnt) {
host->scsi.disconnectable = 0;
if (host->SCpnt->device->id == host->scsi.reconnected.target &&
host->SCpnt->device->lun == host->scsi.reconnected.lun &&
host->SCpnt->tag == host->scsi.reconnected.tag) {
#if (DEBUG & (DEBUG_QUEUES|DEBUG_DISCON))
DBG(host->SCpnt, printk("scsi%d.%c: reconnected",
host->host->host_no, acornscsi_target(host)));
#endif
} else {
queue_add_cmd_tail(&host->queues.disconnected, host->SCpnt);
#if (DEBUG & (DEBUG_QUEUES|DEBUG_DISCON))
DBG(host->SCpnt, printk("scsi%d.%c: had to move command "
"to disconnected queue\n",
host->host->host_no, acornscsi_target(host)));
#endif
host->SCpnt = NULL;
}
}
if (!host->SCpnt) {
host->SCpnt = queue_remove_tgtluntag(&host->queues.disconnected,
host->scsi.reconnected.target,
host->scsi.reconnected.lun,
host->scsi.reconnected.tag);
#if (DEBUG & (DEBUG_QUEUES|DEBUG_DISCON))
DBG(host->SCpnt, printk("scsi%d.%c: had to get command",
host->host->host_no, acornscsi_target(host)));
#endif
}
if (!host->SCpnt)
acornscsi_abortcmd(host, host->scsi.reconnected.tag);
else {
host->scsi.SCp = host->SCpnt->SCp;
#if (DEBUG & (DEBUG_QUEUES|DEBUG_DISCON))
printk(", data pointers: [%p, %X]",
host->scsi.SCp.ptr, host->scsi.SCp.this_residual);
#endif
}
#if (DEBUG & (DEBUG_QUEUES|DEBUG_DISCON))
printk("\n");
#endif
host->dma.transferred = host->scsi.SCp.scsi_xferred;
return host->SCpnt != NULL;
}
static
void acornscsi_disconnect_unexpected(AS_Host *host)
{
printk(KERN_ERR "scsi%d.%c: unexpected disconnect\n",
host->host->host_no, acornscsi_target(host));
#if (DEBUG & DEBUG_ABORT)
acornscsi_dumplog(host, 8);
#endif
acornscsi_done(host, &host->SCpnt, DID_ERROR);
}
static
void acornscsi_abortcmd(AS_Host *host, unsigned char tag)
{
host->scsi.phase = PHASE_ABORTED;
sbic_arm_write(host, SBIC_CMND, CMND_ASSERTATN);
msgqueue_flush(&host->scsi.msgs);
#ifdef CONFIG_SCSI_ACORNSCSI_TAGGED_QUEUE
if (tag)
msgqueue_addmsg(&host->scsi.msgs, 2, ABORT_TAG, tag);
else
#endif
msgqueue_addmsg(&host->scsi.msgs, 1, ABORT);
}
static
intr_ret_t acornscsi_sbicintr(AS_Host *host, int in_irq)
{
unsigned int asr, ssr;
asr = sbic_arm_read(host, SBIC_ASR);
if (!(asr & ASR_INT))
return INTR_IDLE;
ssr = sbic_arm_read(host, SBIC_SSR);
#if (DEBUG & DEBUG_PHASES)
print_sbic_status(asr, ssr, host->scsi.phase);
#endif
ADD_STATUS(8, ssr, host->scsi.phase, in_irq);
if (host->SCpnt && !host->scsi.disconnectable)
ADD_STATUS(host->SCpnt->device->id, ssr, host->scsi.phase, in_irq);
switch (ssr) {
case 0x00:
printk(KERN_ERR "scsi%d: reset in standard mode but wanted advanced mode.\n",
host->host->host_no);
sbic_arm_write(host, SBIC_OWNID, OWNID_EAF | host->host->this_id);
sbic_arm_write(host, SBIC_CMND, CMND_RESET);
return INTR_IDLE;
case 0x01:
sbic_arm_write(host, SBIC_CTRL, INIT_SBICDMA | CTRL_IDI);
sbic_arm_write(host, SBIC_TIMEOUT, TIMEOUT_TIME);
sbic_arm_write(host, SBIC_SYNCHTRANSFER, SYNCHTRANSFER_2DBA);
sbic_arm_write(host, SBIC_SOURCEID, SOURCEID_ER | SOURCEID_DSP);
msgqueue_flush(&host->scsi.msgs);
return INTR_IDLE;
case 0x41:
acornscsi_disconnect_unexpected(host);
return INTR_NEXT_COMMAND;
}
switch (host->scsi.phase) {
case PHASE_CONNECTING:
switch (ssr) {
case 0x11:
host->scsi.phase = PHASE_CONNECTED;
msgqueue_flush(&host->scsi.msgs);
host->dma.transferred = host->scsi.SCp.scsi_xferred;
asr = sbic_arm_read(host, SBIC_ASR);
if (!(asr & ASR_INT))
break;
ssr = sbic_arm_read(host, SBIC_SSR);
ADD_STATUS(8, ssr, host->scsi.phase, 1);
ADD_STATUS(host->SCpnt->device->id, ssr, host->scsi.phase, 1);
goto connected;
case 0x42:
acornscsi_done(host, &host->SCpnt, DID_NO_CONNECT);
return INTR_NEXT_COMMAND;
case 0x81:
host->origSCpnt = host->SCpnt;
host->SCpnt = NULL;
msgqueue_flush(&host->scsi.msgs);
acornscsi_reconnect(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_CONNECTING, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
acornscsi_abortcmd(host, host->SCpnt->tag);
}
return INTR_PROCESSING;
connected:
case PHASE_CONNECTED:
switch (ssr) {
#ifdef NONSTANDARD
case 0x8a:
acornscsi_sendcommand(host);
break;
case 0x8b:
acornscsi_readstatusbyte(host);
host->scsi.phase = PHASE_STATUSIN;
break;
#endif
case 0x8e:
host->scsi.phase = PHASE_MSGOUT;
acornscsi_buildmessages(host);
acornscsi_sendmessage(host);
break;
case 0x85:
acornscsi_done(host, &host->SCpnt, DID_ERROR);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_CONNECTED, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
acornscsi_abortcmd(host, host->SCpnt->tag);
}
return INTR_PROCESSING;
case PHASE_MSGOUT:
switch (ssr) {
case 0x8a:
case 0x1a:
acornscsi_sendcommand(host);
break;
case 0x8b:
case 0x1b:
acornscsi_readstatusbyte(host);
host->scsi.phase = PHASE_STATUSIN;
break;
case 0x8e:
acornscsi_sendmessage(host);
break;
case 0x4f:
case 0x1f:
acornscsi_message(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_MSGOUT, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_COMMAND:
switch (ssr) {
case 0x18:
if (host->scsi.SCp.sent_command != host->SCpnt->cmd_len)
acornscsi_abortcmd(host, host->SCpnt->tag);
acornscsi_dma_setup(host, DMA_OUT);
if (!acornscsi_starttransfer(host))
acornscsi_abortcmd(host, host->SCpnt->tag);
host->scsi.phase = PHASE_DATAOUT;
return INTR_IDLE;
case 0x19:
if (host->scsi.SCp.sent_command != host->SCpnt->cmd_len)
acornscsi_abortcmd(host, host->SCpnt->tag);
acornscsi_dma_setup(host, DMA_IN);
if (!acornscsi_starttransfer(host))
acornscsi_abortcmd(host, host->SCpnt->tag);
host->scsi.phase = PHASE_DATAIN;
return INTR_IDLE;
case 0x1b:
acornscsi_readstatusbyte(host);
host->scsi.phase = PHASE_STATUSIN;
break;
case 0x1e:
acornscsi_sendmessage(host);
break;
case 0x1f:
acornscsi_message(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_COMMAND, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_DISCONNECT:
if (ssr == 0x85) {
host->scsi.disconnectable = 1;
host->scsi.reconnected.tag = 0;
host->scsi.phase = PHASE_IDLE;
host->stats.disconnects += 1;
} else {
printk(KERN_ERR "scsi%d.%c: PHASE_DISCONNECT, SSR %02X instead of disconnect?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_NEXT_COMMAND;
case PHASE_IDLE:
if (ssr == 0x81)
acornscsi_reconnect(host);
else {
printk(KERN_ERR "scsi%d.%c: PHASE_IDLE, SSR %02X while idle?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_RECONNECTED:
if (ssr != 0x8f && !acornscsi_reconnect_finish(host))
return INTR_IDLE;
ADD_STATUS(host->SCpnt->device->id, ssr, host->scsi.phase, in_irq);
switch (ssr) {
case 0x88:
acornscsi_dma_setup(host, DMA_OUT);
if (!acornscsi_starttransfer(host))
acornscsi_abortcmd(host, host->SCpnt->tag);
host->scsi.phase = PHASE_DATAOUT;
return INTR_IDLE;
case 0x89:
acornscsi_dma_setup(host, DMA_IN);
if (!acornscsi_starttransfer(host))
acornscsi_abortcmd(host, host->SCpnt->tag);
host->scsi.phase = PHASE_DATAIN;
return INTR_IDLE;
case 0x8a:
acornscsi_sendcommand(host);
break;
case 0x8b:
acornscsi_readstatusbyte(host);
host->scsi.phase = PHASE_STATUSIN;
break;
case 0x8e:
acornscsi_sendmessage(host);
break;
case 0x8f:
acornscsi_message(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_RECONNECTED, SSR %02X after reconnect?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_DATAIN:
switch (ssr) {
case 0x19:
case 0x89:
acornscsi_abortcmd(host, host->SCpnt->tag);
return INTR_IDLE;
case 0x1b:
case 0x4b:
case 0x8b:
host->scsi.SCp.scsi_xferred = scsi_bufflen(host->SCpnt) -
acornscsi_sbic_xfcount(host);
acornscsi_dma_stop(host);
acornscsi_readstatusbyte(host);
host->scsi.phase = PHASE_STATUSIN;
break;
case 0x1e:
case 0x4e:
case 0x8e:
host->scsi.SCp.scsi_xferred = scsi_bufflen(host->SCpnt) -
acornscsi_sbic_xfcount(host);
acornscsi_dma_stop(host);
acornscsi_sendmessage(host);
break;
case 0x1f:
case 0x4f:
case 0x8f:
host->scsi.SCp.scsi_xferred = scsi_bufflen(host->SCpnt) -
acornscsi_sbic_xfcount(host);
acornscsi_dma_stop(host);
acornscsi_message(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_DATAIN, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_DATAOUT:
switch (ssr) {
case 0x18:
case 0x88:
acornscsi_abortcmd(host, host->SCpnt->tag);
return INTR_IDLE;
case 0x1b:
case 0x4b:
case 0x8b:
host->scsi.SCp.scsi_xferred = scsi_bufflen(host->SCpnt) -
acornscsi_sbic_xfcount(host);
acornscsi_dma_stop(host);
acornscsi_dma_adjust(host);
acornscsi_readstatusbyte(host);
host->scsi.phase = PHASE_STATUSIN;
break;
case 0x1e:
case 0x4e:
case 0x8e:
host->scsi.SCp.scsi_xferred = scsi_bufflen(host->SCpnt) -
acornscsi_sbic_xfcount(host);
acornscsi_dma_stop(host);
acornscsi_dma_adjust(host);
acornscsi_sendmessage(host);
break;
case 0x1f:
case 0x4f:
case 0x8f:
host->scsi.SCp.scsi_xferred = scsi_bufflen(host->SCpnt) -
acornscsi_sbic_xfcount(host);
acornscsi_dma_stop(host);
acornscsi_dma_adjust(host);
acornscsi_message(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_DATAOUT, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_STATUSIN:
switch (ssr) {
case 0x1f:
case 0x8f:
acornscsi_message(host);
break;
case 0x1e:
case 0x8e:
acornscsi_sendmessage(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_STATUSIN, SSR %02X instead of MESSAGE_IN?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_MSGIN:
switch (ssr) {
case 0x1e:
case 0x4e:
case 0x8e:
acornscsi_sendmessage(host);
break;
case 0x1f:
case 0x2f:
case 0x4f:
case 0x8f:
acornscsi_message(host);
break;
case 0x85:
printk("scsi%d.%c: strange message in disconnection\n",
host->host->host_no, acornscsi_target(host));
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
acornscsi_done(host, &host->SCpnt, DID_ERROR);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_MSGIN, SSR %02X after message in?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_DONE:
switch (ssr) {
case 0x85:
acornscsi_done(host, &host->SCpnt, DID_OK);
return INTR_NEXT_COMMAND;
case 0x1e:
case 0x8e:
acornscsi_sendmessage(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_DONE, SSR %02X instead of disconnect?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
case PHASE_ABORTED:
switch (ssr) {
case 0x85:
if (host->SCpnt)
acornscsi_done(host, &host->SCpnt, DID_ABORT);
else {
clear_bit(host->scsi.reconnected.target * 8 + host->scsi.reconnected.lun,
host->busyluns);
host->scsi.phase = PHASE_IDLE;
}
return INTR_NEXT_COMMAND;
case 0x1e:
case 0x2e:
case 0x4e:
case 0x8e:
acornscsi_sendmessage(host);
break;
default:
printk(KERN_ERR "scsi%d.%c: PHASE_ABORTED, SSR %02X?\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
default:
printk(KERN_ERR "scsi%d.%c: unknown driver phase %d\n",
host->host->host_no, acornscsi_target(host), ssr);
acornscsi_dumplog(host, host->SCpnt ? host->SCpnt->device->id : 8);
}
return INTR_PROCESSING;
}
static irqreturn_t
acornscsi_intr(int irq, void *dev_id)
{
AS_Host *host = (AS_Host *)dev_id;
intr_ret_t ret;
int iostatus;
int in_irq = 0;
do {
ret = INTR_IDLE;
iostatus = readb(host->fast + INT_REG);
if (iostatus & 2) {
acornscsi_dma_intr(host);
iostatus = readb(host->fast + INT_REG);
}
if (iostatus & 8)
ret = acornscsi_sbicintr(host, in_irq);
if (host->dma.xfer_required)
acornscsi_dma_xfer(host);
if (ret == INTR_NEXT_COMMAND)
ret = acornscsi_kick(host);
in_irq = 1;
} while (ret != INTR_IDLE);
return IRQ_HANDLED;
}
static int acornscsi_queuecmd_lck(struct scsi_cmnd *SCpnt,
void (*done)(struct scsi_cmnd *))
{
AS_Host *host = (AS_Host *)SCpnt->device->host->hostdata;
if (!done) {
panic("scsi%d: queuecommand called with NULL done function [cmd=%p]",
host->host->host_no, SCpnt);
return -EINVAL;
}
#if (DEBUG & DEBUG_NO_WRITE)
if (acornscsi_cmdtype(SCpnt->cmnd[0]) == CMD_WRITE && (NO_WRITE & (1 << SCpnt->device->id))) {
printk(KERN_CRIT "scsi%d.%c: WRITE attempted with NO_WRITE flag set\n",
host->host->host_no, '0' + SCpnt->device->id);
SCpnt->result = DID_NO_CONNECT << 16;
done(SCpnt);
return 0;
}
#endif
SCpnt->scsi_done = done;
SCpnt->host_scribble = NULL;
SCpnt->result = 0;
SCpnt->tag = 0;
SCpnt->SCp.phase = (int)acornscsi_datadirection(SCpnt->cmnd[0]);
SCpnt->SCp.sent_command = 0;
SCpnt->SCp.scsi_xferred = 0;
init_SCp(SCpnt);
host->stats.queues += 1;
{
unsigned long flags;
if (!queue_add_cmd_ordered(&host->queues.issue, SCpnt)) {
SCpnt->result = DID_ERROR << 16;
done(SCpnt);
return 0;
}
local_irq_save(flags);
if (host->scsi.phase == PHASE_IDLE)
acornscsi_kick(host);
local_irq_restore(flags);
}
return 0;
}
static inline void acornscsi_reportstatus(struct scsi_cmnd **SCpntp1,
struct scsi_cmnd **SCpntp2,
int result)
{
struct scsi_cmnd *SCpnt = *SCpntp1;
if (SCpnt) {
*SCpntp1 = NULL;
SCpnt->result = result;
SCpnt->scsi_done(SCpnt);
}
if (SCpnt == *SCpntp2)
*SCpntp2 = NULL;
}
static enum res_abort acornscsi_do_abort(AS_Host *host, struct scsi_cmnd *SCpnt)
{
enum res_abort res = res_not_running;
if (queue_remove_cmd(&host->queues.issue, SCpnt)) {
printk("on issue queue ");
res = res_success;
} else if (queue_remove_cmd(&host->queues.disconnected, SCpnt)) {
printk("on disconnected queue ");
res = res_success;
} else if (host->SCpnt == SCpnt) {
unsigned long flags;
printk("executing ");
local_irq_save(flags);
switch (host->scsi.phase) {
case PHASE_IDLE:
if (host->scsi.disconnectable) {
host->scsi.disconnectable = 0;
host->SCpnt = NULL;
res = res_success;
}
break;
case PHASE_CONNECTED:
sbic_arm_write(host, SBIC_CMND, CMND_DISCONNECT);
host->SCpnt = NULL;
res = res_success_clear;
break;
default:
acornscsi_abortcmd(host, host->SCpnt->tag);
res = res_snooze;
}
local_irq_restore(flags);
} else if (host->origSCpnt == SCpnt) {
host->origSCpnt = NULL;
printk("waiting for execution ");
res = res_success_clear;
} else
printk("unknown ");
return res;
}
int acornscsi_abort(struct scsi_cmnd *SCpnt)
{
AS_Host *host = (AS_Host *) SCpnt->device->host->hostdata;
int result;
host->stats.aborts += 1;
#if (DEBUG & DEBUG_ABORT)
{
int asr, ssr;
asr = sbic_arm_read(host, SBIC_ASR);
ssr = sbic_arm_read(host, SBIC_SSR);
printk(KERN_WARNING "acornscsi_abort: ");
print_sbic_status(asr, ssr, host->scsi.phase);
acornscsi_dumplog(host, SCpnt->device->id);
}
#endif
printk("scsi%d: ", host->host->host_no);
switch (acornscsi_do_abort(host, SCpnt)) {
case res_success_clear:
printk("clear ");
clear_bit(SCpnt->device->id * 8 +
(u8)(SCpnt->device->lun & 0x7), host->busyluns);
case res_success:
printk("success\n");
result = SUCCESS;
break;
case res_snooze:
printk("snooze\n");
result = FAILED;
break;
default:
case res_not_running:
acornscsi_dumplog(host, SCpnt->device->id);
result = FAILED;
printk("not running\n");
break;
}
return result;
}
int acornscsi_bus_reset(struct scsi_cmnd *SCpnt)
{
AS_Host *host = (AS_Host *)SCpnt->device->host->hostdata;
struct scsi_cmnd *SCptr;
host->stats.resets += 1;
#if (DEBUG & DEBUG_RESET)
{
int asr, ssr;
asr = sbic_arm_read(host, SBIC_ASR);
ssr = sbic_arm_read(host, SBIC_SSR);
printk(KERN_WARNING "acornscsi_reset: ");
print_sbic_status(asr, ssr, host->scsi.phase);
acornscsi_dumplog(host, SCpnt->device->id);
}
#endif
acornscsi_dma_stop(host);
acornscsi_resetcard(host);
while ((SCptr = queue_remove(&host->queues.disconnected)) != NULL)
;
return SUCCESS;
}
const
char *acornscsi_info(struct Scsi_Host *host)
{
static char string[100], *p;
p = string;
p += sprintf(string, "%s at port %08lX irq %d v%d.%d.%d"
#ifdef CONFIG_SCSI_ACORNSCSI_SYNC
" SYNC"
#endif
#ifdef CONFIG_SCSI_ACORNSCSI_TAGGED_QUEUE
" TAG"
#endif
#if (DEBUG & DEBUG_NO_WRITE)
" NOWRITE (" __stringify(NO_WRITE) ")"
#endif
, host->hostt->name, host->io_port, host->irq,
VER_MAJOR, VER_MINOR, VER_PATCH);
return string;
}
static int acornscsi_show_info(struct seq_file *m, struct Scsi_Host *instance)
{
int devidx;
struct scsi_device *scd;
AS_Host *host;
host = (AS_Host *)instance->hostdata;
seq_printf(m, "AcornSCSI driver v%d.%d.%d"
#ifdef CONFIG_SCSI_ACORNSCSI_SYNC
" SYNC"
#endif
#ifdef CONFIG_SCSI_ACORNSCSI_TAGGED_QUEUE
" TAG"
#endif
#if (DEBUG & DEBUG_NO_WRITE)
" NOWRITE (" __stringify(NO_WRITE) ")"
#endif
"\n\n", VER_MAJOR, VER_MINOR, VER_PATCH);
seq_printf(m, "SBIC: WD33C93A Address: %p IRQ : %d\n",
host->base + SBIC_REGIDX, host->scsi.irq);
#ifdef USE_DMAC
seq_printf(m, "DMAC: uPC71071 Address: %p IRQ : %d\n\n",
host->base + DMAC_OFFSET, host->scsi.irq);
#endif
seq_printf(m, "Statistics:\n"
"Queued commands: %-10u Issued commands: %-10u\n"
"Done commands : %-10u Reads : %-10u\n"
"Writes : %-10u Others : %-10u\n"
"Disconnects : %-10u Aborts : %-10u\n"
"Resets : %-10u\n\nLast phases:",
host->stats.queues, host->stats.removes,
host->stats.fins, host->stats.reads,
host->stats.writes, host->stats.miscs,
host->stats.disconnects, host->stats.aborts,
host->stats.resets);
for (devidx = 0; devidx < 9; devidx ++) {
unsigned int statptr, prev;
seq_printf(m, "\n%c:", devidx == 8 ? 'H' : ('0' + devidx));
statptr = host->status_ptr[devidx] - 10;
if ((signed int)statptr < 0)
statptr += STATUS_BUFFER_SIZE;
prev = host->status[devidx][statptr].when;
for (; statptr != host->status_ptr[devidx]; statptr = (statptr + 1) & (STATUS_BUFFER_SIZE - 1)) {
if (host->status[devidx][statptr].when) {
seq_printf(m, "%c%02X:%02X+%2ld",
host->status[devidx][statptr].irq ? '-' : ' ',
host->status[devidx][statptr].ph,
host->status[devidx][statptr].ssr,
(host->status[devidx][statptr].when - prev) < 100 ?
(host->status[devidx][statptr].when - prev) : 99);
prev = host->status[devidx][statptr].when;
}
}
}
seq_printf(m, "\nAttached devices:\n");
shost_for_each_device(scd, instance) {
seq_printf(m, "Device/Lun TaggedQ Sync\n");
seq_printf(m, " %d/%llu ", scd->id, scd->lun);
if (scd->tagged_supported)
seq_printf(m, "%3sabled(%3d) ",
scd->simple_tags ? "en" : "dis",
scd->current_tag);
else
seq_printf(m, "unsupported ");
if (host->device[scd->id].sync_xfer & 15)
seq_printf(m, "offset %d, %d ns\n",
host->device[scd->id].sync_xfer & 15,
acornscsi_getperiod(host->device[scd->id].sync_xfer));
else
seq_printf(m, "async\n");
}
return 0;
}
static int acornscsi_probe(struct expansion_card *ec, const struct ecard_id *id)
{
struct Scsi_Host *host;
AS_Host *ashost;
int ret;
ret = ecard_request_resources(ec);
if (ret)
goto out;
host = scsi_host_alloc(&acornscsi_template, sizeof(AS_Host));
if (!host) {
ret = -ENOMEM;
goto out_release;
}
ashost = (AS_Host *)host->hostdata;
ashost->base = ecardm_iomap(ec, ECARD_RES_MEMC, 0, 0);
ashost->fast = ecardm_iomap(ec, ECARD_RES_IOCFAST, 0, 0);
if (!ashost->base || !ashost->fast)
goto out_put;
host->irq = ec->irq;
ashost->host = host;
ashost->scsi.irq = host->irq;
ec->irqaddr = ashost->fast + INT_REG;
ec->irqmask = 0x0a;
ret = request_irq(host->irq, acornscsi_intr, 0, "acornscsi", ashost);
if (ret) {
printk(KERN_CRIT "scsi%d: IRQ%d not free: %d\n",
host->host_no, ashost->scsi.irq, ret);
goto out_put;
}
memset(&ashost->stats, 0, sizeof (ashost->stats));
queue_initialise(&ashost->queues.issue);
queue_initialise(&ashost->queues.disconnected);
msgqueue_initialise(&ashost->scsi.msgs);
acornscsi_resetcard(ashost);
ret = scsi_add_host(host, &ec->dev);
if (ret)
goto out_irq;
scsi_scan_host(host);
goto out;
out_irq:
free_irq(host->irq, ashost);
msgqueue_free(&ashost->scsi.msgs);
queue_free(&ashost->queues.disconnected);
queue_free(&ashost->queues.issue);
out_put:
ecardm_iounmap(ec, ashost->fast);
ecardm_iounmap(ec, ashost->base);
scsi_host_put(host);
out_release:
ecard_release_resources(ec);
out:
return ret;
}
static void acornscsi_remove(struct expansion_card *ec)
{
struct Scsi_Host *host = ecard_get_drvdata(ec);
AS_Host *ashost = (AS_Host *)host->hostdata;
ecard_set_drvdata(ec, NULL);
scsi_remove_host(host);
writeb(0x80, ashost->fast + PAGE_REG);
free_irq(host->irq, ashost);
msgqueue_free(&ashost->scsi.msgs);
queue_free(&ashost->queues.disconnected);
queue_free(&ashost->queues.issue);
ecardm_iounmap(ec, ashost->fast);
ecardm_iounmap(ec, ashost->base);
scsi_host_put(host);
ecard_release_resources(ec);
}
static int __init acornscsi_init(void)
{
return ecard_register_driver(&acornscsi_driver);
}
static void __exit acornscsi_exit(void)
{
ecard_remove_driver(&acornscsi_driver);
}
