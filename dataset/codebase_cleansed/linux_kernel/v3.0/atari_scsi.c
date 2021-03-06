static inline void SCSI_DMA_SETADR(unsigned long adr)
{
st_dma.dma_lo = (unsigned char)adr;
MFPDELAY();
adr >>= 8;
st_dma.dma_md = (unsigned char)adr;
MFPDELAY();
adr >>= 8;
st_dma.dma_hi = (unsigned char)adr;
MFPDELAY();
}
static inline unsigned long SCSI_DMA_GETADR(void)
{
unsigned long adr;
adr = st_dma.dma_lo;
MFPDELAY();
adr |= (st_dma.dma_md & 0xff) << 8;
MFPDELAY();
adr |= (st_dma.dma_hi & 0xff) << 16;
MFPDELAY();
return adr;
}
static inline void ENABLE_IRQ(void)
{
if (IS_A_TT())
atari_enable_irq(IRQ_TT_MFP_SCSI);
else
atari_enable_irq(IRQ_MFP_FSCSI);
}
static inline void DISABLE_IRQ(void)
{
if (IS_A_TT())
atari_disable_irq(IRQ_TT_MFP_SCSI);
else
atari_disable_irq(IRQ_MFP_FSCSI);
}
static int scsi_dma_is_ignored_buserr(unsigned char dma_stat)
{
int i;
unsigned long addr = SCSI_DMA_READ_P(dma_addr), end_addr;
if (dma_stat & 0x01) {
for (i = 0; i < m68k_num_memory; ++i) {
end_addr = m68k_memory[i].addr + m68k_memory[i].size;
if (end_addr <= addr && addr <= end_addr + 4)
return 1;
}
}
return 0;
}
static irqreturn_t scsi_tt_intr(int irq, void *dummy)
{
#ifdef REAL_DMA
int dma_stat;
dma_stat = tt_scsi_dma.dma_ctrl;
INT_PRINTK("scsi%d: NCR5380 interrupt, DMA status = %02x\n",
atari_scsi_host->host_no, dma_stat & 0xff);
if (dma_stat & 0x80) {
if (!scsi_dma_is_ignored_buserr(dma_stat)) {
printk(KERN_ERR "SCSI DMA caused bus error near 0x%08lx\n",
SCSI_DMA_READ_P(dma_addr));
printk(KERN_CRIT "SCSI DMA bus error -- bad DMA programming!");
}
}
if ((dma_stat & 0x02) && !(dma_stat & 0x40)) {
atari_dma_residual = HOSTDATA_DMALEN - (SCSI_DMA_READ_P(dma_addr) - atari_dma_startaddr);
DMA_PRINTK("SCSI DMA: There are %ld residual bytes.\n",
atari_dma_residual);
if ((signed int)atari_dma_residual < 0)
atari_dma_residual = 0;
if ((dma_stat & 1) == 0) {
atari_scsi_fetch_restbytes();
} else {
if (atari_dma_residual & 0x1ff) {
DMA_PRINTK("SCSI DMA: DMA bug corrected, "
"difference %ld bytes\n",
512 - (atari_dma_residual & 0x1ff));
atari_dma_residual = (atari_dma_residual + 511) & ~0x1ff;
}
}
tt_scsi_dma.dma_ctrl = 0;
}
if (dma_stat & 0x40) {
atari_dma_residual = 0;
if ((dma_stat & 1) == 0)
atari_scsi_fetch_restbytes();
tt_scsi_dma.dma_ctrl = 0;
}
#endif
NCR5380_intr(irq, dummy);
#if 0
atari_enable_irq(IRQ_TT_MFP_SCSI);
#endif
return IRQ_HANDLED;
}
static irqreturn_t scsi_falcon_intr(int irq, void *dummy)
{
#ifdef REAL_DMA
int dma_stat;
st_dma.dma_mode_status = 0x90;
dma_stat = st_dma.dma_mode_status;
if (!(dma_stat & 0x01)) {
printk(KERN_CRIT "SCSI DMA error near 0x%08lx!\n", SCSI_DMA_GETADR());
}
if (atari_dma_active && (dma_stat & 0x02)) {
unsigned long transferred;
transferred = SCSI_DMA_GETADR() - atari_dma_startaddr;
if (transferred & 15)
printk(KERN_ERR "SCSI DMA error: %ld bytes lost in "
"ST-DMA fifo\n", transferred & 15);
atari_dma_residual = HOSTDATA_DMALEN - transferred;
DMA_PRINTK("SCSI DMA: There are %ld residual bytes.\n",
atari_dma_residual);
} else
atari_dma_residual = 0;
atari_dma_active = 0;
if (atari_dma_orig_addr) {
memcpy(atari_dma_orig_addr, phys_to_virt(atari_dma_startaddr),
HOSTDATA_DMALEN - atari_dma_residual);
atari_dma_orig_addr = NULL;
}
#endif
NCR5380_intr(irq, dummy);
return IRQ_HANDLED;
}
static void atari_scsi_fetch_restbytes(void)
{
int nr;
char *src, *dst;
unsigned long phys_dst;
phys_dst = SCSI_DMA_READ_P(dma_addr);
nr = phys_dst & 3;
if (nr) {
phys_dst ^= nr;
DMA_PRINTK("SCSI DMA: there are %d rest bytes for phys addr 0x%08lx",
nr, phys_dst);
dst = phys_to_virt(phys_dst);
DMA_PRINTK(" = virt addr %p\n", dst);
for (src = (char *)&tt_scsi_dma.dma_restdata; nr != 0; --nr)
*dst++ = *src++;
}
}
static void falcon_release_lock_if_possible(struct NCR5380_hostdata *hostdata)
{
unsigned long flags;
if (IS_A_TT())
return;
local_irq_save(flags);
if (falcon_got_lock && !hostdata->disconnected_queue &&
!hostdata->issue_queue && !hostdata->connected) {
if (falcon_dont_release) {
#if 0
printk("WARNING: Lock release not allowed. Ignored\n");
#endif
local_irq_restore(flags);
return;
}
falcon_got_lock = 0;
stdma_release();
wake_up(&falcon_fairness_wait);
}
local_irq_restore(flags);
}
static void falcon_get_lock(void)
{
unsigned long flags;
if (IS_A_TT())
return;
local_irq_save(flags);
while (!in_irq() && falcon_got_lock && stdma_others_waiting())
sleep_on(&falcon_fairness_wait);
while (!falcon_got_lock) {
if (in_irq())
panic("Falcon SCSI hasn't ST-DMA lock in interrupt");
if (!falcon_trying_lock) {
falcon_trying_lock = 1;
stdma_lock(scsi_falcon_intr, NULL);
falcon_got_lock = 1;
falcon_trying_lock = 0;
wake_up(&falcon_try_wait);
} else {
sleep_on(&falcon_try_wait);
}
}
local_irq_restore(flags);
if (!falcon_got_lock)
panic("Falcon SCSI: someone stole the lock :-(\n");
}
int __init atari_scsi_detect(struct scsi_host_template *host)
{
static int called = 0;
struct Scsi_Host *instance;
if (!MACH_IS_ATARI ||
(!ATARIHW_PRESENT(ST_SCSI) && !ATARIHW_PRESENT(TT_SCSI)) ||
called)
return 0;
host->proc_name = "Atari";
atari_scsi_reg_read = IS_A_TT() ? atari_scsi_tt_reg_read :
atari_scsi_falcon_reg_read;
atari_scsi_reg_write = IS_A_TT() ? atari_scsi_tt_reg_write :
atari_scsi_falcon_reg_write;
host->can_queue =
(setup_can_queue > 0) ? setup_can_queue :
IS_A_TT() ? ATARI_TT_CAN_QUEUE : ATARI_FALCON_CAN_QUEUE;
host->cmd_per_lun =
(setup_cmd_per_lun > 0) ? setup_cmd_per_lun :
IS_A_TT() ? ATARI_TT_CMD_PER_LUN : ATARI_FALCON_CMD_PER_LUN;
host->sg_tablesize =
!IS_A_TT() ? ATARI_FALCON_SG_TABLESIZE :
(setup_sg_tablesize >= 0) ? setup_sg_tablesize : ATARI_TT_SG_TABLESIZE;
if (setup_hostid >= 0)
host->this_id = setup_hostid;
else {
host->this_id = 7;
if (ATARIHW_PRESENT(TT_CLK) && nvram_check_checksum()) {
unsigned char b = nvram_read_byte( 14 );
if (b & 0x80)
host->this_id = b & 7;
}
}
#ifdef SUPPORT_TAGS
if (setup_use_tagged_queuing < 0)
setup_use_tagged_queuing = DEFAULT_USE_TAGGED_QUEUING;
#endif
#ifdef REAL_DMA
if (MACH_IS_ATARI && ATARIHW_PRESENT(ST_SCSI) &&
!ATARIHW_PRESENT(EXTD_DMA) && m68k_num_memory > 1) {
atari_dma_buffer = atari_stram_alloc(STRAM_BUFFER_SIZE, "SCSI");
if (!atari_dma_buffer) {
printk(KERN_ERR "atari_scsi_detect: can't allocate ST-RAM "
"double buffer\n");
return 0;
}
atari_dma_phys_buffer = virt_to_phys(atari_dma_buffer);
atari_dma_orig_addr = 0;
}
#endif
instance = scsi_register(host, sizeof(struct NCR5380_hostdata));
if (instance == NULL) {
atari_stram_free(atari_dma_buffer);
atari_dma_buffer = 0;
return 0;
}
atari_scsi_host = instance;
instance->irq = 0;
#ifdef CONFIG_ATARI_SCSI_RESET_BOOT
atari_scsi_reset_boot();
#endif
NCR5380_init(instance, 0);
if (IS_A_TT()) {
if (request_irq(IRQ_TT_MFP_SCSI, scsi_tt_intr, IRQ_TYPE_SLOW,
"SCSI NCR5380", instance)) {
printk(KERN_ERR "atari_scsi_detect: cannot allocate irq %d, aborting",IRQ_TT_MFP_SCSI);
scsi_unregister(atari_scsi_host);
atari_stram_free(atari_dma_buffer);
atari_dma_buffer = 0;
return 0;
}
tt_mfp.active_edge |= 0x80;
#ifdef REAL_DMA
tt_scsi_dma.dma_ctrl = 0;
atari_dma_residual = 0;
if (MACH_IS_MEDUSA) {
atari_read_overruns = 4;
}
#endif
} else {
#ifdef REAL_DMA
atari_dma_residual = 0;
atari_dma_active = 0;
atari_dma_stram_mask = (ATARIHW_PRESENT(EXTD_DMA) ? 0x00000000
: 0xff000000);
#endif
}
printk(KERN_INFO "scsi%d: options CAN_QUEUE=%d CMD_PER_LUN=%d SCAT-GAT=%d "
#ifdef SUPPORT_TAGS
"TAGGED-QUEUING=%s "
#endif
"HOSTID=%d",
instance->host_no, instance->hostt->can_queue,
instance->hostt->cmd_per_lun,
instance->hostt->sg_tablesize,
#ifdef SUPPORT_TAGS
setup_use_tagged_queuing ? "yes" : "no",
#endif
instance->hostt->this_id );
NCR5380_print_options(instance);
printk("\n");
called = 1;
return 1;
}
int atari_scsi_release(struct Scsi_Host *sh)
{
if (IS_A_TT())
free_irq(IRQ_TT_MFP_SCSI, sh);
if (atari_dma_buffer)
atari_stram_free(atari_dma_buffer);
return 1;
}
void __init atari_scsi_setup(char *str, int *ints)
{
if (ints[0] < 1) {
printk("atari_scsi_setup: no arguments!\n");
return;
}
if (ints[0] >= 1) {
if (ints[1] > 0)
setup_can_queue = ints[1];
}
if (ints[0] >= 2) {
if (ints[2] > 0)
setup_cmd_per_lun = ints[2];
}
if (ints[0] >= 3) {
if (ints[3] >= 0) {
setup_sg_tablesize = ints[3];
if (setup_sg_tablesize > SG_ALL)
setup_sg_tablesize = SG_ALL;
}
}
if (ints[0] >= 4) {
if (ints[4] >= 0 && ints[4] <= 7)
setup_hostid = ints[4];
else if (ints[4] > 7)
printk("atari_scsi_setup: invalid host ID %d !\n", ints[4]);
}
#ifdef SUPPORT_TAGS
if (ints[0] >= 5) {
if (ints[5] >= 0)
setup_use_tagged_queuing = !!ints[5];
}
#endif
}
int atari_scsi_bus_reset(Scsi_Cmnd *cmd)
{
int rv;
struct NCR5380_hostdata *hostdata =
(struct NCR5380_hostdata *)cmd->device->host->hostdata;
if (IS_A_TT()) {
atari_turnoff_irq(IRQ_TT_MFP_SCSI);
#ifdef REAL_DMA
tt_scsi_dma.dma_ctrl = 0;
#endif
} else {
atari_turnoff_irq(IRQ_MFP_FSCSI);
#ifdef REAL_DMA
st_dma.dma_mode_status = 0x90;
atari_dma_active = 0;
atari_dma_orig_addr = NULL;
#endif
}
rv = NCR5380_bus_reset(cmd);
if (IS_A_TT()) {
atari_turnon_irq(IRQ_TT_MFP_SCSI);
} else {
atari_turnon_irq(IRQ_MFP_FSCSI);
}
if ((rv & SCSI_RESET_ACTION) == SCSI_RESET_SUCCESS)
falcon_release_lock_if_possible(hostdata);
return rv;
}
static void __init atari_scsi_reset_boot(void)
{
unsigned long end;
printk("Atari SCSI: resetting the SCSI bus...");
NCR5380_write(TARGET_COMMAND_REG,
PHASE_SR_TO_TCR(NCR5380_read(STATUS_REG)));
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_RST);
udelay(50);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
end = jiffies + AFTER_RESET_DELAY;
while (time_before(jiffies, end))
barrier();
printk(" done\n");
}
const char *atari_scsi_info(struct Scsi_Host *host)
{
static const char string[] = "Atari native SCSI";
return string;
}
unsigned long atari_scsi_dma_setup(struct Scsi_Host *instance, void *data,
unsigned long count, int dir)
{
unsigned long addr = virt_to_phys(data);
DMA_PRINTK("scsi%d: setting up dma, data = %p, phys = %lx, count = %ld, "
"dir = %d\n", instance->host_no, data, addr, count, dir);
if (!IS_A_TT() && !STRAM_ADDR(addr)) {
if (dir)
memcpy(atari_dma_buffer, data, count);
else
atari_dma_orig_addr = data;
addr = atari_dma_phys_buffer;
}
atari_dma_startaddr = addr;
dma_cache_maintenance(addr, count, dir);
if (count == 0)
printk(KERN_NOTICE "SCSI warning: DMA programmed for 0 bytes !\n");
if (IS_A_TT()) {
tt_scsi_dma.dma_ctrl = dir;
SCSI_DMA_WRITE_P(dma_addr, addr);
SCSI_DMA_WRITE_P(dma_cnt, count);
tt_scsi_dma.dma_ctrl = dir | 2;
} else {
SCSI_DMA_SETADR(addr);
dir <<= 8;
st_dma.dma_mode_status = 0x90 | dir;
st_dma.dma_mode_status = 0x90 | (dir ^ 0x100);
st_dma.dma_mode_status = 0x90 | dir;
udelay(40);
st_dma.fdc_acces_seccount = (count + (dir ? 511 : 0)) >> 9;
udelay(40);
st_dma.dma_mode_status = 0x10 | dir;
udelay(40);
atari_dma_active = 1;
}
return count;
}
static long atari_scsi_dma_residual(struct Scsi_Host *instance)
{
return atari_dma_residual;
}
static int falcon_classify_cmd(Scsi_Cmnd *cmd)
{
unsigned char opcode = cmd->cmnd[0];
if (opcode == READ_DEFECT_DATA || opcode == READ_LONG ||
opcode == READ_BUFFER)
return CMD_SURELY_BYTE_MODE;
else if (opcode == READ_6 || opcode == READ_10 ||
opcode == 0xa8 || opcode == READ_REVERSE ||
opcode == RECOVER_BUFFERED_DATA) {
if (cmd->device->type == TYPE_TAPE && !(cmd->cmnd[1] & 1))
return CMD_SURELY_BYTE_MODE;
else
return CMD_SURELY_BLOCK_MODE;
} else
return CMD_MODE_UNKNOWN;
}
static unsigned long atari_dma_xfer_len(unsigned long wanted_len,
Scsi_Cmnd *cmd, int write_flag)
{
unsigned long possible_len, limit;
if (IS_A_TT())
return wanted_len;
if (write_flag) {
possible_len = wanted_len;
} else {
if (wanted_len & 0x1ff)
possible_len = 0;
else {
switch (falcon_classify_cmd(cmd)) {
case CMD_SURELY_BLOCK_MODE:
possible_len = wanted_len;
break;
case CMD_SURELY_BYTE_MODE:
possible_len = 0;
break;
case CMD_MODE_UNKNOWN:
default:
possible_len = (wanted_len < 1024) ? 0 : wanted_len;
break;
}
}
}
limit = (atari_dma_buffer && !STRAM_ADDR(virt_to_phys(cmd->SCp.ptr))) ?
STRAM_BUFFER_SIZE : 255*512;
if (possible_len > limit)
possible_len = limit;
if (possible_len != wanted_len)
DMA_PRINTK("Sorry, must cut DMA transfer size to %ld bytes "
"instead of %ld\n", possible_len, wanted_len);
return possible_len;
}
static unsigned char atari_scsi_tt_reg_read(unsigned char reg)
{
return tt_scsi_regp[reg * 2];
}
static void atari_scsi_tt_reg_write(unsigned char reg, unsigned char value)
{
tt_scsi_regp[reg * 2] = value;
}
static unsigned char atari_scsi_falcon_reg_read(unsigned char reg)
{
dma_wd.dma_mode_status= (u_short)(0x88 + reg);
return (u_char)dma_wd.fdc_acces_seccount;
}
static void atari_scsi_falcon_reg_write(unsigned char reg, unsigned char value)
{
dma_wd.dma_mode_status = (u_short)(0x88 + reg);
dma_wd.fdc_acces_seccount = (u_short)value;
}
