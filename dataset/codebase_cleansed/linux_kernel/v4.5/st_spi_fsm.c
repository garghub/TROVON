static int stfsm_mx25_en_32bit_addr_seq(struct stfsm_seq *seq)
{
seq->seq_opc[0] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_EN4B) |
SEQ_OPC_CSDEASSERT);
seq->seq[0] = STFSM_INST_CMD1;
seq->seq[1] = STFSM_INST_WAIT;
seq->seq[2] = STFSM_INST_STOP;
seq->seq_cfg = (SEQ_CFG_PADS_1 |
SEQ_CFG_ERASE |
SEQ_CFG_READNOTWRITE |
SEQ_CFG_CSDEASSERT |
SEQ_CFG_STARTSEQ);
return 0;
}
static int stfsm_n25q_en_32bit_addr_seq(struct stfsm_seq *seq)
{
seq->seq_opc[0] = (SEQ_OPC_PADS_1 | SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_EN4B));
seq->seq_opc[1] = (SEQ_OPC_PADS_1 | SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_WREN) |
SEQ_OPC_CSDEASSERT);
seq->seq[0] = STFSM_INST_CMD2;
seq->seq[1] = STFSM_INST_CMD1;
seq->seq[2] = STFSM_INST_WAIT;
seq->seq[3] = STFSM_INST_STOP;
seq->seq_cfg = (SEQ_CFG_PADS_1 |
SEQ_CFG_ERASE |
SEQ_CFG_READNOTWRITE |
SEQ_CFG_CSDEASSERT |
SEQ_CFG_STARTSEQ);
return 0;
}
static inline int stfsm_is_idle(struct stfsm *fsm)
{
return readl(fsm->base + SPI_FAST_SEQ_STA) & 0x10;
}
static inline uint32_t stfsm_fifo_available(struct stfsm *fsm)
{
return (readl(fsm->base + SPI_FAST_SEQ_STA) >> 5) & 0x7f;
}
static inline void stfsm_load_seq(struct stfsm *fsm,
const struct stfsm_seq *seq)
{
void __iomem *dst = fsm->base + SPI_FAST_SEQ_TRANSFER_SIZE;
const uint32_t *src = (const uint32_t *)seq;
int words = sizeof(*seq) / sizeof(*src);
BUG_ON(!stfsm_is_idle(fsm));
while (words--) {
writel(*src, dst);
src++;
dst += 4;
}
}
static void stfsm_wait_seq(struct stfsm *fsm)
{
unsigned long deadline;
int timeout = 0;
deadline = jiffies + msecs_to_jiffies(STFSM_MAX_WAIT_SEQ_MS);
while (!timeout) {
if (time_after_eq(jiffies, deadline))
timeout = 1;
if (stfsm_is_idle(fsm))
return;
cond_resched();
}
dev_err(fsm->dev, "timeout on sequence completion\n");
}
static void stfsm_read_fifo(struct stfsm *fsm, uint32_t *buf, uint32_t size)
{
uint32_t remaining = size >> 2;
uint32_t avail;
uint32_t words;
dev_dbg(fsm->dev, "Reading %d bytes from FIFO\n", size);
BUG_ON((((uintptr_t)buf) & 0x3) || (size & 0x3));
while (remaining) {
for (;;) {
avail = stfsm_fifo_available(fsm);
if (avail)
break;
udelay(1);
}
words = min(avail, remaining);
remaining -= words;
readsl(fsm->base + SPI_FAST_SEQ_DATA_REG, buf, words);
buf += words;
}
}
static void stfsm_clear_fifo(struct stfsm *fsm)
{
const struct stfsm_seq *seq = &stfsm_seq_load_fifo_byte;
uint32_t words, i;
words = stfsm_fifo_available(fsm);
if (words) {
for (i = 0; i < words; i++)
readl(fsm->base + SPI_FAST_SEQ_DATA_REG);
dev_dbg(fsm->dev, "cleared %d words from FIFO\n", words);
}
for (i = 0, words = 0; i < 4 && !words; i++) {
stfsm_load_seq(fsm, seq);
stfsm_wait_seq(fsm);
words = stfsm_fifo_available(fsm);
}
if (words != 1) {
dev_err(fsm->dev, "failed to clear bytes from the data FIFO\n");
return;
}
readl(fsm->base + SPI_FAST_SEQ_DATA_REG);
dev_dbg(fsm->dev, "cleared %d byte(s) from the data FIFO\n", 4 - i);
}
static int stfsm_write_fifo(struct stfsm *fsm, const uint32_t *buf,
uint32_t size)
{
uint32_t words = size >> 2;
dev_dbg(fsm->dev, "writing %d bytes to FIFO\n", size);
BUG_ON((((uintptr_t)buf) & 0x3) || (size & 0x3));
writesl(fsm->base + SPI_FAST_SEQ_DATA_REG, buf, words);
return size;
}
static int stfsm_enter_32bit_addr(struct stfsm *fsm, int enter)
{
struct stfsm_seq *seq = &fsm->stfsm_seq_en_32bit_addr;
uint32_t cmd = enter ? SPINOR_OP_EN4B : SPINOR_OP_EX4B;
seq->seq_opc[0] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(cmd) |
SEQ_OPC_CSDEASSERT);
stfsm_load_seq(fsm, seq);
stfsm_wait_seq(fsm);
return 0;
}
static uint8_t stfsm_wait_busy(struct stfsm *fsm)
{
struct stfsm_seq *seq = &stfsm_seq_read_status_fifo;
unsigned long deadline;
uint32_t status;
int timeout = 0;
seq->seq_opc[0] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_RDSR));
stfsm_load_seq(fsm, seq);
deadline = jiffies + FLASH_MAX_BUSY_WAIT;
while (!timeout) {
if (time_after_eq(jiffies, deadline))
timeout = 1;
stfsm_wait_seq(fsm);
stfsm_read_fifo(fsm, &status, 4);
if ((status & FLASH_STATUS_BUSY) == 0)
return 0;
if ((fsm->configuration & CFG_S25FL_CHECK_ERROR_FLAGS) &&
((status & S25FL_STATUS_P_ERR) ||
(status & S25FL_STATUS_E_ERR)))
return (uint8_t)(status & 0xff);
if (!timeout)
writel(seq->seq_cfg, fsm->base + SPI_FAST_SEQ_CFG);
cond_resched();
}
dev_err(fsm->dev, "timeout on wait_busy\n");
return FLASH_STATUS_TIMEOUT;
}
static int stfsm_read_status(struct stfsm *fsm, uint8_t cmd,
uint8_t *data, int bytes)
{
struct stfsm_seq *seq = &stfsm_seq_read_status_fifo;
uint32_t tmp;
uint8_t *t = (uint8_t *)&tmp;
int i;
dev_dbg(fsm->dev, "read 'status' register [0x%02x], %d byte(s)\n",
cmd, bytes);
BUG_ON(bytes != 1 && bytes != 2);
seq->seq_opc[0] = (SEQ_OPC_PADS_1 | SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(cmd)),
stfsm_load_seq(fsm, seq);
stfsm_read_fifo(fsm, &tmp, 4);
for (i = 0; i < bytes; i++)
data[i] = t[i];
stfsm_wait_seq(fsm);
return 0;
}
static int stfsm_write_status(struct stfsm *fsm, uint8_t cmd,
uint16_t data, int bytes, int wait_busy)
{
struct stfsm_seq *seq = &stfsm_seq_write_status;
dev_dbg(fsm->dev,
"write 'status' register [0x%02x], %d byte(s), 0x%04x\n"
" %s wait-busy\n", cmd, bytes, data, wait_busy ? "with" : "no");
BUG_ON(bytes != 1 && bytes != 2);
seq->seq_opc[1] = (SEQ_OPC_PADS_1 | SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(cmd));
seq->status = (uint32_t)data | STA_PADS_1 | STA_CSDEASSERT;
seq->seq[2] = (bytes == 1) ? STFSM_INST_STA_WR1 : STFSM_INST_STA_WR1_2;
stfsm_load_seq(fsm, seq);
stfsm_wait_seq(fsm);
if (wait_busy)
stfsm_wait_busy(fsm);
return 0;
}
static bool stfsm_can_handle_soc_reset(struct stfsm *fsm)
{
if (fsm->reset_signal && fsm->info->flags & FLASH_FLAG_RESET)
return true;
if (fsm->reset_por)
return true;
return false;
}
static void stfsm_prepare_erasesec_seq(struct stfsm *fsm,
struct stfsm_seq *seq)
{
int addr1_cycles = fsm->info->flags & FLASH_FLAG_32BIT_ADDR ? 16 : 8;
seq->addr_cfg = (ADR_CFG_CYCLES_ADD1(addr1_cycles) |
ADR_CFG_PADS_1_ADD1 |
ADR_CFG_CYCLES_ADD2(16) |
ADR_CFG_PADS_1_ADD2 |
ADR_CFG_CSDEASSERT_ADD2);
}
static struct seq_rw_config *
stfsm_search_seq_rw_configs(struct stfsm *fsm,
struct seq_rw_config cfgs[])
{
struct seq_rw_config *config;
int flags = fsm->info->flags;
for (config = cfgs; config->cmd != 0; config++)
if ((config->flags & flags) == config->flags)
return config;
return NULL;
}
static void stfsm_prepare_rw_seq(struct stfsm *fsm,
struct stfsm_seq *seq,
struct seq_rw_config *cfg)
{
int addr1_cycles, addr2_cycles;
int i = 0;
memset(seq, 0, sizeof(*seq));
seq->seq_opc[i++] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(cfg->cmd));
if (cfg->write)
seq->seq_opc[i++] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_WREN) |
SEQ_OPC_CSDEASSERT);
addr1_cycles = (fsm->info->flags & FLASH_FLAG_32BIT_ADDR) ? 16 : 8;
addr1_cycles /= cfg->addr_pads;
addr2_cycles = 16 / cfg->addr_pads;
seq->addr_cfg = ((addr1_cycles & 0x3f) << 0 |
(cfg->addr_pads - 1) << 6 |
(addr2_cycles & 0x3f) << 16 |
((cfg->addr_pads - 1) << 22));
seq->seq_cfg = ((cfg->data_pads - 1) << 16 |
SEQ_CFG_STARTSEQ |
SEQ_CFG_CSDEASSERT);
if (!cfg->write)
seq->seq_cfg |= SEQ_CFG_READNOTWRITE;
seq->mode = ((cfg->mode_data & 0xff) << 0 |
(cfg->mode_cycles & 0x3f) << 16 |
(cfg->addr_pads - 1) << 22);
seq->dummy = ((cfg->dummy_cycles & 0x3f) << 16 |
(cfg->addr_pads - 1) << 22);
i = 0;
if (cfg->write)
seq->seq[i++] = STFSM_INST_CMD2;
seq->seq[i++] = STFSM_INST_CMD1;
seq->seq[i++] = STFSM_INST_ADD1;
seq->seq[i++] = STFSM_INST_ADD2;
if (cfg->mode_cycles)
seq->seq[i++] = STFSM_INST_MODE;
if (cfg->dummy_cycles)
seq->seq[i++] = STFSM_INST_DUMMY;
seq->seq[i++] =
cfg->write ? STFSM_INST_DATA_WRITE : STFSM_INST_DATA_READ;
seq->seq[i++] = STFSM_INST_STOP;
}
static int stfsm_search_prepare_rw_seq(struct stfsm *fsm,
struct stfsm_seq *seq,
struct seq_rw_config *cfgs)
{
struct seq_rw_config *config;
config = stfsm_search_seq_rw_configs(fsm, cfgs);
if (!config) {
dev_err(fsm->dev, "failed to find suitable config\n");
return -EINVAL;
}
stfsm_prepare_rw_seq(fsm, seq, config);
return 0;
}
static int stfsm_prepare_rwe_seqs_default(struct stfsm *fsm)
{
uint32_t flags = fsm->info->flags;
int ret;
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_read,
default_read_configs);
if (ret) {
dev_err(fsm->dev,
"failed to prep READ sequence with flags [0x%08x]\n",
flags);
return ret;
}
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_write,
default_write_configs);
if (ret) {
dev_err(fsm->dev,
"failed to prep WRITE sequence with flags [0x%08x]\n",
flags);
return ret;
}
stfsm_prepare_erasesec_seq(fsm, &stfsm_seq_erase_sector);
return 0;
}
static int stfsm_mx25_config(struct stfsm *fsm)
{
uint32_t flags = fsm->info->flags;
uint32_t data_pads;
uint8_t sta;
int ret;
bool soc_reset;
ret = stfsm_prepare_rwe_seqs_default(fsm);
if (ret)
return ret;
if (flags & FLASH_FLAG_32BIT_ADDR) {
stfsm_mx25_en_32bit_addr_seq(&fsm->stfsm_seq_en_32bit_addr);
soc_reset = stfsm_can_handle_soc_reset(fsm);
if (soc_reset || !fsm->booted_from_spi)
stfsm_enter_32bit_addr(fsm, 1);
else
fsm->configuration = (CFG_READ_TOGGLE_32BIT_ADDR |
CFG_WRITE_TOGGLE_32BIT_ADDR |
CFG_ERASESEC_TOGGLE_32BIT_ADDR);
}
stfsm_read_status(fsm, SPINOR_OP_RDSR, &sta, 1);
data_pads = ((fsm->stfsm_seq_read.seq_cfg >> 16) & 0x3) + 1;
if (data_pads == 4) {
if (!(sta & MX25_STATUS_QE)) {
sta |= MX25_STATUS_QE;
stfsm_write_status(fsm, SPINOR_OP_WRSR, sta, 1, 1);
}
} else {
if (sta & MX25_STATUS_QE) {
sta &= ~MX25_STATUS_QE;
stfsm_write_status(fsm, SPINOR_OP_WRSR, sta, 1, 1);
}
}
return 0;
}
static int stfsm_n25q_config(struct stfsm *fsm)
{
uint32_t flags = fsm->info->flags;
uint8_t vcr;
int ret = 0;
bool soc_reset;
if (flags & FLASH_FLAG_32BIT_ADDR)
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_read,
n25q_read4_configs);
else
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_read,
n25q_read3_configs);
if (ret) {
dev_err(fsm->dev,
"failed to prepare READ sequence with flags [0x%08x]\n",
flags);
return ret;
}
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_write,
default_write_configs);
if (ret) {
dev_err(fsm->dev,
"preparing WRITE sequence using flags [0x%08x] failed\n",
flags);
return ret;
}
stfsm_prepare_erasesec_seq(fsm, &stfsm_seq_erase_sector);
if (flags & FLASH_FLAG_32BIT_ADDR) {
stfsm_n25q_en_32bit_addr_seq(&fsm->stfsm_seq_en_32bit_addr);
soc_reset = stfsm_can_handle_soc_reset(fsm);
if (soc_reset || !fsm->booted_from_spi) {
stfsm_enter_32bit_addr(fsm, 1);
} else {
fsm->configuration = (CFG_WRITE_TOGGLE_32BIT_ADDR |
CFG_ERASESEC_TOGGLE_32BIT_ADDR);
}
}
vcr = (N25Q_VCR_DUMMY_CYCLES(8) | N25Q_VCR_XIP_DISABLED |
N25Q_VCR_WRAP_CONT);
stfsm_write_status(fsm, N25Q_CMD_WRVCR, vcr, 1, 0);
return 0;
}
static void stfsm_s25fl_prepare_erasesec_seq_32(struct stfsm_seq *seq)
{
seq->seq_opc[1] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(S25FL_CMD_SE4));
seq->addr_cfg = (ADR_CFG_CYCLES_ADD1(16) |
ADR_CFG_PADS_1_ADD1 |
ADR_CFG_CYCLES_ADD2(16) |
ADR_CFG_PADS_1_ADD2 |
ADR_CFG_CSDEASSERT_ADD2);
}
static void stfsm_s25fl_read_dyb(struct stfsm *fsm, uint32_t offs, uint8_t *dby)
{
uint32_t tmp;
struct stfsm_seq seq = {
.data_size = TRANSFER_SIZE(4),
.seq_opc[0] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(S25FL_CMD_DYBRD)),
.addr_cfg = (ADR_CFG_CYCLES_ADD1(16) |
ADR_CFG_PADS_1_ADD1 |
ADR_CFG_CYCLES_ADD2(16) |
ADR_CFG_PADS_1_ADD2),
.addr1 = (offs >> 16) & 0xffff,
.addr2 = offs & 0xffff,
.seq = {
STFSM_INST_CMD1,
STFSM_INST_ADD1,
STFSM_INST_ADD2,
STFSM_INST_DATA_READ,
STFSM_INST_STOP,
},
.seq_cfg = (SEQ_CFG_PADS_1 |
SEQ_CFG_READNOTWRITE |
SEQ_CFG_CSDEASSERT |
SEQ_CFG_STARTSEQ),
};
stfsm_load_seq(fsm, &seq);
stfsm_read_fifo(fsm, &tmp, 4);
*dby = (uint8_t)(tmp >> 24);
stfsm_wait_seq(fsm);
}
static void stfsm_s25fl_write_dyb(struct stfsm *fsm, uint32_t offs, uint8_t dby)
{
struct stfsm_seq seq = {
.seq_opc[0] = (SEQ_OPC_PADS_1 | SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_WREN) |
SEQ_OPC_CSDEASSERT),
.seq_opc[1] = (SEQ_OPC_PADS_1 | SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(S25FL_CMD_DYBWR)),
.addr_cfg = (ADR_CFG_CYCLES_ADD1(16) |
ADR_CFG_PADS_1_ADD1 |
ADR_CFG_CYCLES_ADD2(16) |
ADR_CFG_PADS_1_ADD2),
.status = (uint32_t)dby | STA_PADS_1 | STA_CSDEASSERT,
.addr1 = (offs >> 16) & 0xffff,
.addr2 = offs & 0xffff,
.seq = {
STFSM_INST_CMD1,
STFSM_INST_CMD2,
STFSM_INST_ADD1,
STFSM_INST_ADD2,
STFSM_INST_STA_WR1,
STFSM_INST_STOP,
},
.seq_cfg = (SEQ_CFG_PADS_1 |
SEQ_CFG_READNOTWRITE |
SEQ_CFG_CSDEASSERT |
SEQ_CFG_STARTSEQ),
};
stfsm_load_seq(fsm, &seq);
stfsm_wait_seq(fsm);
stfsm_wait_busy(fsm);
}
static int stfsm_s25fl_clear_status_reg(struct stfsm *fsm)
{
struct stfsm_seq seq = {
.seq_opc[0] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(S25FL_CMD_CLSR) |
SEQ_OPC_CSDEASSERT),
.seq_opc[1] = (SEQ_OPC_PADS_1 |
SEQ_OPC_CYCLES(8) |
SEQ_OPC_OPCODE(SPINOR_OP_WRDI) |
SEQ_OPC_CSDEASSERT),
.seq = {
STFSM_INST_CMD1,
STFSM_INST_CMD2,
STFSM_INST_WAIT,
STFSM_INST_STOP,
},
.seq_cfg = (SEQ_CFG_PADS_1 |
SEQ_CFG_ERASE |
SEQ_CFG_READNOTWRITE |
SEQ_CFG_CSDEASSERT |
SEQ_CFG_STARTSEQ),
};
stfsm_load_seq(fsm, &seq);
stfsm_wait_seq(fsm);
return 0;
}
static int stfsm_s25fl_config(struct stfsm *fsm)
{
struct flash_info *info = fsm->info;
uint32_t flags = info->flags;
uint32_t data_pads;
uint32_t offs;
uint16_t sta_wr;
uint8_t sr1, cr1, dyb;
int update_sr = 0;
int ret;
if (flags & FLASH_FLAG_32BIT_ADDR) {
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_read,
stfsm_s25fl_read4_configs);
if (ret)
return ret;
ret = stfsm_search_prepare_rw_seq(fsm, &fsm->stfsm_seq_write,
stfsm_s25fl_write4_configs);
if (ret)
return ret;
stfsm_s25fl_prepare_erasesec_seq_32(&stfsm_seq_erase_sector);
} else {
ret = stfsm_prepare_rwe_seqs_default(fsm);
if (ret)
return ret;
}
if (flags & FLASH_FLAG_DYB_LOCKING) {
offs = 0;
for (offs = 0; offs < info->sector_size * info->n_sectors;) {
stfsm_s25fl_read_dyb(fsm, offs, &dyb);
if (dyb == 0x00)
stfsm_s25fl_write_dyb(fsm, offs, 0xff);
if ((offs < info->sector_size * 2) ||
(offs >= (info->sector_size - info->n_sectors * 4)))
offs += 0x1000;
else
offs += 0x10000;
}
}
stfsm_read_status(fsm, SPINOR_OP_RDSR2, &cr1, 1);
data_pads = ((fsm->stfsm_seq_read.seq_cfg >> 16) & 0x3) + 1;
if (data_pads == 4) {
if (!(cr1 & STFSM_S25FL_CONFIG_QE)) {
cr1 |= STFSM_S25FL_CONFIG_QE;
update_sr = 1;
}
} else {
if (cr1 & STFSM_S25FL_CONFIG_QE) {
cr1 &= ~STFSM_S25FL_CONFIG_QE;
update_sr = 1;
}
}
if (update_sr) {
stfsm_read_status(fsm, SPINOR_OP_RDSR, &sr1, 1);
sta_wr = ((uint16_t)cr1 << 8) | sr1;
stfsm_write_status(fsm, SPINOR_OP_WRSR, sta_wr, 2, 1);
}
fsm->configuration |= CFG_S25FL_CHECK_ERROR_FLAGS;
return 0;
}
static int stfsm_w25q_config(struct stfsm *fsm)
{
uint32_t data_pads;
uint8_t sr1, sr2;
uint16_t sr_wr;
int update_sr = 0;
int ret;
ret = stfsm_prepare_rwe_seqs_default(fsm);
if (ret)
return ret;
stfsm_read_status(fsm, SPINOR_OP_RDSR2, &sr2, 1);
data_pads = ((fsm->stfsm_seq_read.seq_cfg >> 16) & 0x3) + 1;
if (data_pads == 4) {
if (!(sr2 & W25Q_STATUS_QE)) {
sr2 |= W25Q_STATUS_QE;
update_sr = 1;
}
} else {
if (sr2 & W25Q_STATUS_QE) {
sr2 &= ~W25Q_STATUS_QE;
update_sr = 1;
}
}
if (update_sr) {
stfsm_read_status(fsm, SPINOR_OP_RDSR, &sr1, 1);
sr_wr = ((uint16_t)sr2 << 8) | sr1;
stfsm_write_status(fsm, SPINOR_OP_WRSR, sr_wr, 2, 1);
}
return 0;
}
static int stfsm_read(struct stfsm *fsm, uint8_t *buf, uint32_t size,
uint32_t offset)
{
struct stfsm_seq *seq = &fsm->stfsm_seq_read;
uint32_t data_pads;
uint32_t read_mask;
uint32_t size_ub;
uint32_t size_lb;
uint32_t size_mop;
uint32_t tmp[4];
uint32_t page_buf[FLASH_PAGESIZE_32];
uint8_t *p;
dev_dbg(fsm->dev, "reading %d bytes from 0x%08x\n", size, offset);
if (fsm->configuration & CFG_READ_TOGGLE_32BIT_ADDR)
stfsm_enter_32bit_addr(fsm, 1);
data_pads = ((seq->seq_cfg >> 16) & 0x3) + 1;
read_mask = (data_pads << 2) - 1;
p = ((uintptr_t)buf & 0x3) ? (uint8_t *)page_buf : buf;
size_ub = (size + read_mask) & ~read_mask;
size_lb = size & ~read_mask;
size_mop = size & read_mask;
seq->data_size = TRANSFER_SIZE(size_ub);
seq->addr1 = (offset >> 16) & 0xffff;
seq->addr2 = offset & 0xffff;
stfsm_load_seq(fsm, seq);
if (size_lb)
stfsm_read_fifo(fsm, (uint32_t *)p, size_lb);
if (size_mop) {
stfsm_read_fifo(fsm, tmp, read_mask + 1);
memcpy(p + size_lb, &tmp, size_mop);
}
if ((uintptr_t)buf & 0x3)
memcpy(buf, page_buf, size);
stfsm_wait_seq(fsm);
stfsm_clear_fifo(fsm);
if (fsm->configuration & CFG_READ_TOGGLE_32BIT_ADDR)
stfsm_enter_32bit_addr(fsm, 0);
return 0;
}
static int stfsm_write(struct stfsm *fsm, const uint8_t *buf,
uint32_t size, uint32_t offset)
{
struct stfsm_seq *seq = &fsm->stfsm_seq_write;
uint32_t data_pads;
uint32_t write_mask;
uint32_t size_ub;
uint32_t size_lb;
uint32_t size_mop;
uint32_t tmp[4];
uint32_t i;
uint32_t page_buf[FLASH_PAGESIZE_32];
uint8_t *t = (uint8_t *)&tmp;
const uint8_t *p;
int ret;
dev_dbg(fsm->dev, "writing %d bytes to 0x%08x\n", size, offset);
if (fsm->configuration & CFG_WRITE_TOGGLE_32BIT_ADDR)
stfsm_enter_32bit_addr(fsm, 1);
data_pads = ((seq->seq_cfg >> 16) & 0x3) + 1;
write_mask = (data_pads << 2) - 1;
if ((uintptr_t)buf & 0x3) {
memcpy(page_buf, buf, size);
p = (uint8_t *)page_buf;
} else {
p = buf;
}
size_ub = (size + write_mask) & ~write_mask;
size_lb = size & ~write_mask;
size_mop = size & write_mask;
seq->data_size = TRANSFER_SIZE(size_ub);
seq->addr1 = (offset >> 16) & 0xffff;
seq->addr2 = offset & 0xffff;
writel(0x00040000, fsm->base + SPI_FAST_SEQ_CFG);
if (fsm->fifo_dir_delay == 0)
readl(fsm->base + SPI_FAST_SEQ_CFG);
else
udelay(fsm->fifo_dir_delay);
if (size_lb) {
stfsm_write_fifo(fsm, (uint32_t *)p, size_lb);
p += size_lb;
}
if (size_mop) {
memset(t, 0xff, write_mask + 1);
for (i = 0; i < size_mop; i++)
t[i] = *p++;
stfsm_write_fifo(fsm, tmp, write_mask + 1);
}
stfsm_load_seq(fsm, seq);
stfsm_wait_seq(fsm);
ret = stfsm_wait_busy(fsm);
if (ret && fsm->configuration & CFG_S25FL_CHECK_ERROR_FLAGS)
stfsm_s25fl_clear_status_reg(fsm);
if (fsm->configuration & CFG_WRITE_TOGGLE_32BIT_ADDR)
stfsm_enter_32bit_addr(fsm, 0);
return 0;
}
static int stfsm_mtd_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct stfsm *fsm = dev_get_drvdata(mtd->dev.parent);
uint32_t bytes;
dev_dbg(fsm->dev, "%s from 0x%08x, len %zd\n",
__func__, (u32)from, len);
mutex_lock(&fsm->lock);
while (len > 0) {
bytes = min_t(size_t, len, FLASH_PAGESIZE);
stfsm_read(fsm, buf, bytes, from);
buf += bytes;
from += bytes;
len -= bytes;
*retlen += bytes;
}
mutex_unlock(&fsm->lock);
return 0;
}
static int stfsm_erase_sector(struct stfsm *fsm, uint32_t offset)
{
struct stfsm_seq *seq = &stfsm_seq_erase_sector;
int ret;
dev_dbg(fsm->dev, "erasing sector at 0x%08x\n", offset);
if (fsm->configuration & CFG_ERASESEC_TOGGLE_32BIT_ADDR)
stfsm_enter_32bit_addr(fsm, 1);
seq->addr1 = (offset >> 16) & 0xffff;
seq->addr2 = offset & 0xffff;
stfsm_load_seq(fsm, seq);
stfsm_wait_seq(fsm);
ret = stfsm_wait_busy(fsm);
if (ret && fsm->configuration & CFG_S25FL_CHECK_ERROR_FLAGS)
stfsm_s25fl_clear_status_reg(fsm);
if (fsm->configuration & CFG_ERASESEC_TOGGLE_32BIT_ADDR)
stfsm_enter_32bit_addr(fsm, 0);
return ret;
}
static int stfsm_erase_chip(struct stfsm *fsm)
{
const struct stfsm_seq *seq = &stfsm_seq_erase_chip;
dev_dbg(fsm->dev, "erasing chip\n");
stfsm_load_seq(fsm, seq);
stfsm_wait_seq(fsm);
return stfsm_wait_busy(fsm);
}
static int stfsm_mtd_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct stfsm *fsm = dev_get_drvdata(mtd->dev.parent);
u32 page_offs;
u32 bytes;
uint8_t *b = (uint8_t *)buf;
int ret = 0;
dev_dbg(fsm->dev, "%s to 0x%08x, len %zd\n", __func__, (u32)to, len);
page_offs = to % FLASH_PAGESIZE;
mutex_lock(&fsm->lock);
while (len) {
bytes = min_t(size_t, FLASH_PAGESIZE - page_offs, len);
ret = stfsm_write(fsm, b, bytes, to);
if (ret)
goto out1;
b += bytes;
len -= bytes;
to += bytes;
page_offs = 0;
*retlen += bytes;
}
out1:
mutex_unlock(&fsm->lock);
return ret;
}
static int stfsm_mtd_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct stfsm *fsm = dev_get_drvdata(mtd->dev.parent);
u32 addr, len;
int ret;
dev_dbg(fsm->dev, "%s at 0x%llx, len %lld\n", __func__,
(long long)instr->addr, (long long)instr->len);
addr = instr->addr;
len = instr->len;
mutex_lock(&fsm->lock);
if (len == mtd->size) {
ret = stfsm_erase_chip(fsm);
if (ret)
goto out1;
} else {
while (len) {
ret = stfsm_erase_sector(fsm, addr);
if (ret)
goto out1;
addr += mtd->erasesize;
len -= mtd->erasesize;
}
}
mutex_unlock(&fsm->lock);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return 0;
out1:
instr->state = MTD_ERASE_FAILED;
mutex_unlock(&fsm->lock);
return ret;
}
static void stfsm_read_jedec(struct stfsm *fsm, uint8_t *jedec)
{
const struct stfsm_seq *seq = &stfsm_seq_read_jedec;
uint32_t tmp[2];
stfsm_load_seq(fsm, seq);
stfsm_read_fifo(fsm, tmp, 8);
memcpy(jedec, tmp, 5);
stfsm_wait_seq(fsm);
}
static struct flash_info *stfsm_jedec_probe(struct stfsm *fsm)
{
struct flash_info *info;
u16 ext_jedec;
u32 jedec;
u8 id[5];
stfsm_read_jedec(fsm, id);
jedec = id[0] << 16 | id[1] << 8 | id[2];
ext_jedec = id[3] << 8 | id[4];
dev_dbg(fsm->dev, "JEDEC = 0x%08x [%02x %02x %02x %02x %02x]\n",
jedec, id[0], id[1], id[2], id[3], id[4]);
for (info = flash_types; info->name; info++) {
if (info->jedec_id == jedec) {
if (info->ext_id && info->ext_id != ext_jedec)
continue;
return info;
}
}
dev_err(fsm->dev, "Unrecognized JEDEC id %06x\n", jedec);
return NULL;
}
static int stfsm_set_mode(struct stfsm *fsm, uint32_t mode)
{
int ret, timeout = 10;
while (--timeout) {
ret = readl(fsm->base + SPI_STA_MODE_CHANGE);
if (ret & 0x1)
break;
udelay(1);
}
if (!timeout)
return -EBUSY;
writel(mode, fsm->base + SPI_MODESELECT);
return 0;
}
static void stfsm_set_freq(struct stfsm *fsm, uint32_t spi_freq)
{
uint32_t emi_freq;
uint32_t clk_div;
emi_freq = clk_get_rate(fsm->clk);
clk_div = 2 * DIV_ROUND_UP(emi_freq, 2 * spi_freq);
if (clk_div < 2)
clk_div = 2;
else if (clk_div > 128)
clk_div = 128;
if (clk_div <= 4)
fsm->fifo_dir_delay = 0;
else if (clk_div <= 10)
fsm->fifo_dir_delay = 1;
else
fsm->fifo_dir_delay = DIV_ROUND_UP(clk_div, 10);
dev_dbg(fsm->dev, "emi_clk = %uHZ, spi_freq = %uHZ, clk_div = %u\n",
emi_freq, spi_freq, clk_div);
writel(clk_div, fsm->base + SPI_CLOCKDIV);
}
static int stfsm_init(struct stfsm *fsm)
{
int ret;
writel(SEQ_CFG_SWRESET, fsm->base + SPI_FAST_SEQ_CFG);
udelay(1);
writel(0, fsm->base + SPI_FAST_SEQ_CFG);
stfsm_set_freq(fsm, STFSM_FLASH_SAFE_FREQ);
ret = stfsm_set_mode(fsm, SPI_MODESELECT_FSM);
if (ret)
return ret;
writel(SPI_CFG_DEVICE_ST |
SPI_CFG_DEFAULT_MIN_CS_HIGH |
SPI_CFG_DEFAULT_CS_SETUPHOLD |
SPI_CFG_DEFAULT_DATA_HOLD,
fsm->base + SPI_CONFIGDATA);
writel(STFSM_DEFAULT_WR_TIME, fsm->base + SPI_STATUS_WR_TIME_REG);
writel(0x00000001, fsm->base + SPI_PROGRAM_ERASE_TIME);
stfsm_clear_fifo(fsm);
return 0;
}
static void stfsm_fetch_platform_configs(struct platform_device *pdev)
{
struct stfsm *fsm = platform_get_drvdata(pdev);
struct device_node *np = pdev->dev.of_node;
struct regmap *regmap;
uint32_t boot_device_reg;
uint32_t boot_device_spi;
uint32_t boot_device;
int ret;
fsm->booted_from_spi = true;
regmap = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(regmap))
goto boot_device_fail;
fsm->reset_signal = of_property_read_bool(np, "st,reset-signal");
fsm->reset_por = of_property_read_bool(np, "st,reset-por");
ret = of_property_read_u32(np, "st,boot-device-reg", &boot_device_reg);
if (ret)
goto boot_device_fail;
ret = of_property_read_u32(np, "st,boot-device-spi", &boot_device_spi);
if (ret)
goto boot_device_fail;
ret = regmap_read(regmap, boot_device_reg, &boot_device);
if (ret)
goto boot_device_fail;
if (boot_device != boot_device_spi)
fsm->booted_from_spi = false;
return;
boot_device_fail:
dev_warn(&pdev->dev,
"failed to fetch boot device, assuming boot from SPI\n");
}
static int stfsm_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct flash_info *info;
struct resource *res;
struct stfsm *fsm;
int ret;
if (!np) {
dev_err(&pdev->dev, "No DT found\n");
return -EINVAL;
}
fsm = devm_kzalloc(&pdev->dev, sizeof(*fsm), GFP_KERNEL);
if (!fsm)
return -ENOMEM;
fsm->dev = &pdev->dev;
platform_set_drvdata(pdev, fsm);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Resource not found\n");
return -ENODEV;
}
fsm->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fsm->base)) {
dev_err(&pdev->dev,
"Failed to reserve memory region %pR\n", res);
return PTR_ERR(fsm->base);
}
fsm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(fsm->clk)) {
dev_err(fsm->dev, "Couldn't find EMI clock.\n");
return PTR_ERR(fsm->clk);
}
ret = clk_prepare_enable(fsm->clk);
if (ret) {
dev_err(fsm->dev, "Failed to enable EMI clock.\n");
return ret;
}
mutex_init(&fsm->lock);
ret = stfsm_init(fsm);
if (ret) {
dev_err(&pdev->dev, "Failed to initialise FSM Controller\n");
return ret;
}
stfsm_fetch_platform_configs(pdev);
info = stfsm_jedec_probe(fsm);
if (!info)
return -ENODEV;
fsm->info = info;
if (info->sector_size * info->n_sectors > 0x1000000)
info->flags |= FLASH_FLAG_32BIT_ADDR;
if (info->config) {
ret = info->config(fsm);
if (ret)
return ret;
} else {
ret = stfsm_prepare_rwe_seqs_default(fsm);
if (ret)
return ret;
}
fsm->mtd.name = info->name;
fsm->mtd.dev.parent = &pdev->dev;
mtd_set_of_node(&fsm->mtd, np);
fsm->mtd.type = MTD_NORFLASH;
fsm->mtd.writesize = 4;
fsm->mtd.writebufsize = fsm->mtd.writesize;
fsm->mtd.flags = MTD_CAP_NORFLASH;
fsm->mtd.size = info->sector_size * info->n_sectors;
fsm->mtd.erasesize = info->sector_size;
fsm->mtd._read = stfsm_mtd_read;
fsm->mtd._write = stfsm_mtd_write;
fsm->mtd._erase = stfsm_mtd_erase;
dev_info(&pdev->dev,
"Found serial flash device: %s\n"
" size = %llx (%lldMiB) erasesize = 0x%08x (%uKiB)\n",
info->name,
(long long)fsm->mtd.size, (long long)(fsm->mtd.size >> 20),
fsm->mtd.erasesize, (fsm->mtd.erasesize >> 10));
return mtd_device_register(&fsm->mtd, NULL, 0);
}
static int stfsm_remove(struct platform_device *pdev)
{
struct stfsm *fsm = platform_get_drvdata(pdev);
return mtd_device_unregister(&fsm->mtd);
}
static int stfsmfsm_suspend(struct device *dev)
{
struct stfsm *fsm = dev_get_drvdata(dev);
clk_disable_unprepare(fsm->clk);
return 0;
}
static int stfsmfsm_resume(struct device *dev)
{
struct stfsm *fsm = dev_get_drvdata(dev);
clk_prepare_enable(fsm->clk);
return 0;
}
