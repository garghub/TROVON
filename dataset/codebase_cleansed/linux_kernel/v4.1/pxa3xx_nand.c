static enum pxa3xx_nand_variant
pxa3xx_nand_get_variant(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(pxa3xx_nand_dt_ids, &pdev->dev);
if (!of_id)
return PXA3XX_NAND_VARIANT_PXA;
return (enum pxa3xx_nand_variant)of_id->data;
}
static void pxa3xx_nand_set_timing(struct pxa3xx_nand_host *host,
const struct pxa3xx_nand_timing *t)
{
struct pxa3xx_nand_info *info = host->info_data;
unsigned long nand_clk = clk_get_rate(info->clk);
uint32_t ndtr0, ndtr1;
ndtr0 = NDTR0_tCH(ns2cycle(t->tCH, nand_clk)) |
NDTR0_tCS(ns2cycle(t->tCS, nand_clk)) |
NDTR0_tWH(ns2cycle(t->tWH, nand_clk)) |
NDTR0_tWP(ns2cycle(t->tWP, nand_clk)) |
NDTR0_tRH(ns2cycle(t->tRH, nand_clk)) |
NDTR0_tRP(ns2cycle(t->tRP, nand_clk));
ndtr1 = NDTR1_tR(ns2cycle(t->tR, nand_clk)) |
NDTR1_tWHR(ns2cycle(t->tWHR, nand_clk)) |
NDTR1_tAR(ns2cycle(t->tAR, nand_clk));
info->ndtr0cs0 = ndtr0;
info->ndtr1cs0 = ndtr1;
nand_writel(info, NDTR0CS0, ndtr0);
nand_writel(info, NDTR1CS0, ndtr1);
}
static void pxa3xx_set_datasize(struct pxa3xx_nand_info *info,
struct mtd_info *mtd)
{
int oob_enable = info->reg_ndcr & NDCR_SPARE_EN;
info->data_size = mtd->writesize;
if (!oob_enable)
return;
info->oob_size = info->spare_size;
if (!info->use_ecc)
info->oob_size += info->ecc_size;
}
static void pxa3xx_nand_start(struct pxa3xx_nand_info *info)
{
uint32_t ndcr;
ndcr = info->reg_ndcr;
if (info->use_ecc) {
ndcr |= NDCR_ECC_EN;
if (info->ecc_bch)
nand_writel(info, NDECCCTRL, 0x1);
} else {
ndcr &= ~NDCR_ECC_EN;
if (info->ecc_bch)
nand_writel(info, NDECCCTRL, 0x0);
}
if (info->use_dma)
ndcr |= NDCR_DMA_EN;
else
ndcr &= ~NDCR_DMA_EN;
if (info->use_spare)
ndcr |= NDCR_SPARE_EN;
else
ndcr &= ~NDCR_SPARE_EN;
ndcr |= NDCR_ND_RUN;
nand_writel(info, NDCR, 0);
nand_writel(info, NDSR, NDSR_MASK);
nand_writel(info, NDCR, ndcr);
}
static void pxa3xx_nand_stop(struct pxa3xx_nand_info *info)
{
uint32_t ndcr;
int timeout = NAND_STOP_DELAY;
ndcr = nand_readl(info, NDCR);
while ((ndcr & NDCR_ND_RUN) && (timeout-- > 0)) {
ndcr = nand_readl(info, NDCR);
udelay(1);
}
if (timeout <= 0) {
ndcr &= ~NDCR_ND_RUN;
nand_writel(info, NDCR, ndcr);
}
nand_writel(info, NDSR, NDSR_MASK);
}
static void __maybe_unused
enable_int(struct pxa3xx_nand_info *info, uint32_t int_mask)
{
uint32_t ndcr;
ndcr = nand_readl(info, NDCR);
nand_writel(info, NDCR, ndcr & ~int_mask);
}
static void disable_int(struct pxa3xx_nand_info *info, uint32_t int_mask)
{
uint32_t ndcr;
ndcr = nand_readl(info, NDCR);
nand_writel(info, NDCR, ndcr | int_mask);
}
static void drain_fifo(struct pxa3xx_nand_info *info, void *data, int len)
{
if (info->ecc_bch) {
int timeout;
while (len > 8) {
__raw_readsl(info->mmio_base + NDDB, data, 8);
for (timeout = 0;
!(nand_readl(info, NDSR) & NDSR_RDDREQ);
timeout++) {
if (timeout >= 5) {
dev_err(&info->pdev->dev,
"Timeout on RDDREQ while draining the FIFO\n");
return;
}
mdelay(1);
}
data += 32;
len -= 8;
}
}
__raw_readsl(info->mmio_base + NDDB, data, len);
}
static void handle_data_pio(struct pxa3xx_nand_info *info)
{
unsigned int do_bytes = min(info->data_size, info->chunk_size);
switch (info->state) {
case STATE_PIO_WRITING:
__raw_writesl(info->mmio_base + NDDB,
info->data_buff + info->data_buff_pos,
DIV_ROUND_UP(do_bytes, 4));
if (info->oob_size > 0)
__raw_writesl(info->mmio_base + NDDB,
info->oob_buff + info->oob_buff_pos,
DIV_ROUND_UP(info->oob_size, 4));
break;
case STATE_PIO_READING:
drain_fifo(info,
info->data_buff + info->data_buff_pos,
DIV_ROUND_UP(do_bytes, 4));
if (info->oob_size > 0)
drain_fifo(info,
info->oob_buff + info->oob_buff_pos,
DIV_ROUND_UP(info->oob_size, 4));
break;
default:
dev_err(&info->pdev->dev, "%s: invalid state %d\n", __func__,
info->state);
BUG();
}
info->data_buff_pos += do_bytes;
info->oob_buff_pos += info->oob_size;
info->data_size -= do_bytes;
}
static void start_data_dma(struct pxa3xx_nand_info *info)
{
struct pxa_dma_desc *desc = info->data_desc;
int dma_len = ALIGN(info->data_size + info->oob_size, 32);
desc->ddadr = DDADR_STOP;
desc->dcmd = DCMD_ENDIRQEN | DCMD_WIDTH4 | DCMD_BURST32 | dma_len;
switch (info->state) {
case STATE_DMA_WRITING:
desc->dsadr = info->data_buff_phys;
desc->dtadr = info->mmio_phys + NDDB;
desc->dcmd |= DCMD_INCSRCADDR | DCMD_FLOWTRG;
break;
case STATE_DMA_READING:
desc->dtadr = info->data_buff_phys;
desc->dsadr = info->mmio_phys + NDDB;
desc->dcmd |= DCMD_INCTRGADDR | DCMD_FLOWSRC;
break;
default:
dev_err(&info->pdev->dev, "%s: invalid state %d\n", __func__,
info->state);
BUG();
}
DRCMR(info->drcmr_dat) = DRCMR_MAPVLD | info->data_dma_ch;
DDADR(info->data_dma_ch) = info->data_desc_addr;
DCSR(info->data_dma_ch) |= DCSR_RUN;
}
static void pxa3xx_nand_data_dma_irq(int channel, void *data)
{
struct pxa3xx_nand_info *info = data;
uint32_t dcsr;
dcsr = DCSR(channel);
DCSR(channel) = dcsr;
if (dcsr & DCSR_BUSERR) {
info->retcode = ERR_DMABUSERR;
}
info->state = STATE_DMA_DONE;
enable_int(info, NDCR_INT_MASK);
nand_writel(info, NDSR, NDSR_WRDREQ | NDSR_RDDREQ);
}
static void start_data_dma(struct pxa3xx_nand_info *info)
{}
static irqreturn_t pxa3xx_nand_irq_thread(int irq, void *data)
{
struct pxa3xx_nand_info *info = data;
handle_data_pio(info);
info->state = STATE_CMD_DONE;
nand_writel(info, NDSR, NDSR_WRDREQ | NDSR_RDDREQ);
return IRQ_HANDLED;
}
static irqreturn_t pxa3xx_nand_irq(int irq, void *devid)
{
struct pxa3xx_nand_info *info = devid;
unsigned int status, is_completed = 0, is_ready = 0;
unsigned int ready, cmd_done;
irqreturn_t ret = IRQ_HANDLED;
if (info->cs == 0) {
ready = NDSR_FLASH_RDY;
cmd_done = NDSR_CS0_CMDD;
} else {
ready = NDSR_RDY;
cmd_done = NDSR_CS1_CMDD;
}
status = nand_readl(info, NDSR);
if (status & NDSR_UNCORERR)
info->retcode = ERR_UNCORERR;
if (status & NDSR_CORERR) {
info->retcode = ERR_CORERR;
if (info->variant == PXA3XX_NAND_VARIANT_ARMADA370 &&
info->ecc_bch)
info->ecc_err_cnt = NDSR_ERR_CNT(status);
else
info->ecc_err_cnt = 1;
info->max_bitflips = max_t(unsigned int,
info->max_bitflips,
info->ecc_err_cnt);
}
if (status & (NDSR_RDDREQ | NDSR_WRDREQ)) {
if (info->use_dma) {
disable_int(info, NDCR_INT_MASK);
info->state = (status & NDSR_RDDREQ) ?
STATE_DMA_READING : STATE_DMA_WRITING;
start_data_dma(info);
goto NORMAL_IRQ_EXIT;
} else {
info->state = (status & NDSR_RDDREQ) ?
STATE_PIO_READING : STATE_PIO_WRITING;
ret = IRQ_WAKE_THREAD;
goto NORMAL_IRQ_EXIT;
}
}
if (status & cmd_done) {
info->state = STATE_CMD_DONE;
is_completed = 1;
}
if (status & ready) {
info->state = STATE_READY;
is_ready = 1;
}
if (status & NDSR_WRCMDREQ) {
nand_writel(info, NDSR, NDSR_WRCMDREQ);
status &= ~NDSR_WRCMDREQ;
info->state = STATE_CMD_HANDLE;
nand_writel(info, NDCB0, info->ndcb0);
nand_writel(info, NDCB0, info->ndcb1);
nand_writel(info, NDCB0, info->ndcb2);
if (info->variant == PXA3XX_NAND_VARIANT_ARMADA370)
nand_writel(info, NDCB0, info->ndcb3);
}
nand_writel(info, NDSR, status);
if (is_completed)
complete(&info->cmd_complete);
if (is_ready)
complete(&info->dev_ready);
NORMAL_IRQ_EXIT:
return ret;
}
static inline int is_buf_blank(uint8_t *buf, size_t len)
{
for (; len > 0; len--)
if (*buf++ != 0xff)
return 0;
return 1;
}
static void set_command_address(struct pxa3xx_nand_info *info,
unsigned int page_size, uint16_t column, int page_addr)
{
if (page_size < PAGE_CHUNK_SIZE) {
info->ndcb1 = ((page_addr & 0xFFFFFF) << 8)
| (column & 0xFF);
info->ndcb2 = 0;
} else {
info->ndcb1 = ((page_addr & 0xFFFF) << 16)
| (column & 0xFFFF);
if (page_addr & 0xFF0000)
info->ndcb2 = (page_addr & 0xFF0000) >> 16;
else
info->ndcb2 = 0;
}
}
static void prepare_start_command(struct pxa3xx_nand_info *info, int command)
{
struct pxa3xx_nand_host *host = info->host[info->cs];
struct mtd_info *mtd = host->mtd;
info->buf_start = 0;
info->buf_count = 0;
info->oob_size = 0;
info->data_buff_pos = 0;
info->oob_buff_pos = 0;
info->use_ecc = 0;
info->use_spare = 1;
info->retcode = ERR_NONE;
info->ecc_err_cnt = 0;
info->ndcb3 = 0;
info->need_wait = 0;
switch (command) {
case NAND_CMD_READ0:
case NAND_CMD_PAGEPROG:
info->use_ecc = 1;
case NAND_CMD_READOOB:
pxa3xx_set_datasize(info, mtd);
break;
case NAND_CMD_PARAM:
info->use_spare = 0;
break;
default:
info->ndcb1 = 0;
info->ndcb2 = 0;
break;
}
if (command == NAND_CMD_READ0 ||
command == NAND_CMD_READOOB ||
command == NAND_CMD_SEQIN) {
info->buf_count = mtd->writesize + mtd->oobsize;
memset(info->data_buff, 0xFF, info->buf_count);
}
}
static int prepare_set_command(struct pxa3xx_nand_info *info, int command,
int ext_cmd_type, uint16_t column, int page_addr)
{
int addr_cycle, exec_cmd;
struct pxa3xx_nand_host *host;
struct mtd_info *mtd;
host = info->host[info->cs];
mtd = host->mtd;
addr_cycle = 0;
exec_cmd = 1;
if (info->cs != 0)
info->ndcb0 = NDCB0_CSEL;
else
info->ndcb0 = 0;
if (command == NAND_CMD_SEQIN)
exec_cmd = 0;
addr_cycle = NDCB0_ADDR_CYC(host->row_addr_cycles
+ host->col_addr_cycles);
switch (command) {
case NAND_CMD_READOOB:
case NAND_CMD_READ0:
info->buf_start = column;
info->ndcb0 |= NDCB0_CMD_TYPE(0)
| addr_cycle
| NAND_CMD_READ0;
if (command == NAND_CMD_READOOB)
info->buf_start += mtd->writesize;
if (mtd->writesize == PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_DBC | (NAND_CMD_READSTART << 8);
} else if (mtd->writesize > PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_DBC | (NAND_CMD_READSTART << 8)
| NDCB0_LEN_OVRD
| NDCB0_EXT_CMD_TYPE(ext_cmd_type);
info->ndcb3 = info->chunk_size +
info->oob_size;
}
set_command_address(info, mtd->writesize, column, page_addr);
break;
case NAND_CMD_SEQIN:
info->buf_start = column;
set_command_address(info, mtd->writesize, 0, page_addr);
if (mtd->writesize > PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_CMD_TYPE(0x1)
| NDCB0_EXT_CMD_TYPE(ext_cmd_type)
| addr_cycle
| command;
info->data_size = 0;
exec_cmd = 1;
}
break;
case NAND_CMD_PAGEPROG:
if (is_buf_blank(info->data_buff,
(mtd->writesize + mtd->oobsize))) {
exec_cmd = 0;
break;
}
if (mtd->writesize > PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_CMD_TYPE(0x1)
| NDCB0_LEN_OVRD
| NDCB0_EXT_CMD_TYPE(ext_cmd_type);
info->ndcb3 = info->chunk_size +
info->oob_size;
if (info->data_size == 0) {
info->ndcb0 = NDCB0_CMD_TYPE(0x1)
| NDCB0_EXT_CMD_TYPE(ext_cmd_type)
| command;
info->ndcb1 = 0;
info->ndcb2 = 0;
info->ndcb3 = 0;
}
} else {
info->ndcb0 |= NDCB0_CMD_TYPE(0x1)
| NDCB0_AUTO_RS
| NDCB0_ST_ROW_EN
| NDCB0_DBC
| (NAND_CMD_PAGEPROG << 8)
| NAND_CMD_SEQIN
| addr_cycle;
}
break;
case NAND_CMD_PARAM:
info->buf_count = 256;
info->ndcb0 |= NDCB0_CMD_TYPE(0)
| NDCB0_ADDR_CYC(1)
| NDCB0_LEN_OVRD
| command;
info->ndcb1 = (column & 0xFF);
info->ndcb3 = 256;
info->data_size = 256;
break;
case NAND_CMD_READID:
info->buf_count = host->read_id_bytes;
info->ndcb0 |= NDCB0_CMD_TYPE(3)
| NDCB0_ADDR_CYC(1)
| command;
info->ndcb1 = (column & 0xFF);
info->data_size = 8;
break;
case NAND_CMD_STATUS:
info->buf_count = 1;
info->ndcb0 |= NDCB0_CMD_TYPE(4)
| NDCB0_ADDR_CYC(1)
| command;
info->data_size = 8;
break;
case NAND_CMD_ERASE1:
info->ndcb0 |= NDCB0_CMD_TYPE(2)
| NDCB0_AUTO_RS
| NDCB0_ADDR_CYC(3)
| NDCB0_DBC
| (NAND_CMD_ERASE2 << 8)
| NAND_CMD_ERASE1;
info->ndcb1 = page_addr;
info->ndcb2 = 0;
break;
case NAND_CMD_RESET:
info->ndcb0 |= NDCB0_CMD_TYPE(5)
| command;
break;
case NAND_CMD_ERASE2:
exec_cmd = 0;
break;
default:
exec_cmd = 0;
dev_err(&info->pdev->dev, "non-supported command %x\n",
command);
break;
}
return exec_cmd;
}
static void nand_cmdfunc(struct mtd_info *mtd, unsigned command,
int column, int page_addr)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
int exec_cmd;
if (info->reg_ndcr & NDCR_DWIDTH_M)
column /= 2;
if (info->cs != host->cs) {
info->cs = host->cs;
nand_writel(info, NDTR0CS0, info->ndtr0cs0);
nand_writel(info, NDTR1CS0, info->ndtr1cs0);
}
prepare_start_command(info, command);
info->state = STATE_PREPARED;
exec_cmd = prepare_set_command(info, command, 0, column, page_addr);
if (exec_cmd) {
init_completion(&info->cmd_complete);
init_completion(&info->dev_ready);
info->need_wait = 1;
pxa3xx_nand_start(info);
if (!wait_for_completion_timeout(&info->cmd_complete,
CHIP_DELAY_TIMEOUT)) {
dev_err(&info->pdev->dev, "Wait time out!!!\n");
pxa3xx_nand_stop(info);
}
}
info->state = STATE_IDLE;
}
static void nand_cmdfunc_extended(struct mtd_info *mtd,
const unsigned command,
int column, int page_addr)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
int exec_cmd, ext_cmd_type;
if (info->reg_ndcr & NDCR_DWIDTH_M)
column /= 2;
if (info->cs != host->cs) {
info->cs = host->cs;
nand_writel(info, NDTR0CS0, info->ndtr0cs0);
nand_writel(info, NDTR1CS0, info->ndtr1cs0);
}
switch (command) {
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
ext_cmd_type = EXT_CMD_TYPE_MONO;
break;
case NAND_CMD_SEQIN:
ext_cmd_type = EXT_CMD_TYPE_DISPATCH;
break;
case NAND_CMD_PAGEPROG:
ext_cmd_type = EXT_CMD_TYPE_NAKED_RW;
break;
default:
ext_cmd_type = 0;
break;
}
prepare_start_command(info, command);
info->need_wait = 1;
init_completion(&info->dev_ready);
do {
info->state = STATE_PREPARED;
exec_cmd = prepare_set_command(info, command, ext_cmd_type,
column, page_addr);
if (!exec_cmd) {
info->need_wait = 0;
complete(&info->dev_ready);
break;
}
init_completion(&info->cmd_complete);
pxa3xx_nand_start(info);
if (!wait_for_completion_timeout(&info->cmd_complete,
CHIP_DELAY_TIMEOUT)) {
dev_err(&info->pdev->dev, "Wait time out!!!\n");
pxa3xx_nand_stop(info);
break;
}
if (info->data_size == 0 && command != NAND_CMD_PAGEPROG)
break;
if (info->data_size == 0 &&
command == NAND_CMD_PAGEPROG &&
ext_cmd_type == EXT_CMD_TYPE_DISPATCH)
break;
if (command == NAND_CMD_READ0 || command == NAND_CMD_READOOB) {
if (info->data_size == info->chunk_size)
ext_cmd_type = EXT_CMD_TYPE_LAST_RW;
else
ext_cmd_type = EXT_CMD_TYPE_NAKED_RW;
} else if (command == NAND_CMD_PAGEPROG &&
info->data_size == 0) {
ext_cmd_type = EXT_CMD_TYPE_DISPATCH;
}
} while (1);
info->state = STATE_IDLE;
}
static int pxa3xx_nand_write_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf, int oob_required)
{
chip->write_buf(mtd, buf, mtd->writesize);
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int pxa3xx_nand_read_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf, int oob_required,
int page)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
chip->read_buf(mtd, buf, mtd->writesize);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
if (info->retcode == ERR_CORERR && info->use_ecc) {
mtd->ecc_stats.corrected += info->ecc_err_cnt;
} else if (info->retcode == ERR_UNCORERR) {
if (is_buf_blank(buf, mtd->writesize))
info->retcode = ERR_NONE;
else
mtd->ecc_stats.failed++;
}
return info->max_bitflips;
}
static uint8_t pxa3xx_nand_read_byte(struct mtd_info *mtd)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
char retval = 0xFF;
if (info->buf_start < info->buf_count)
retval = info->data_buff[info->buf_start++];
return retval;
}
static u16 pxa3xx_nand_read_word(struct mtd_info *mtd)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
u16 retval = 0xFFFF;
if (!(info->buf_start & 0x01) && info->buf_start < info->buf_count) {
retval = *((u16 *)(info->data_buff+info->buf_start));
info->buf_start += 2;
}
return retval;
}
static void pxa3xx_nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
int real_len = min_t(size_t, len, info->buf_count - info->buf_start);
memcpy(buf, info->data_buff + info->buf_start, real_len);
info->buf_start += real_len;
}
static void pxa3xx_nand_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
int real_len = min_t(size_t, len, info->buf_count - info->buf_start);
memcpy(info->data_buff + info->buf_start, buf, real_len);
info->buf_start += real_len;
}
static void pxa3xx_nand_select_chip(struct mtd_info *mtd, int chip)
{
return;
}
static int pxa3xx_nand_waitfunc(struct mtd_info *mtd, struct nand_chip *this)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
if (info->need_wait) {
info->need_wait = 0;
if (!wait_for_completion_timeout(&info->dev_ready,
CHIP_DELAY_TIMEOUT)) {
dev_err(&info->pdev->dev, "Ready time out!!!\n");
return NAND_STATUS_FAIL;
}
}
if (this->state == FL_WRITING || this->state == FL_ERASING) {
if (info->retcode == ERR_NONE)
return 0;
else
return NAND_STATUS_FAIL;
}
return NAND_STATUS_READY;
}
static int pxa3xx_nand_config_flash(struct pxa3xx_nand_info *info,
const struct pxa3xx_nand_flash *f)
{
struct platform_device *pdev = info->pdev;
struct pxa3xx_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct pxa3xx_nand_host *host = info->host[info->cs];
uint32_t ndcr = 0x0;
if (f->page_size != 2048 && f->page_size != 512) {
dev_err(&pdev->dev, "Current only support 2048 and 512 size\n");
return -EINVAL;
}
if (f->flash_width != 16 && f->flash_width != 8) {
dev_err(&pdev->dev, "Only support 8bit and 16 bit!\n");
return -EINVAL;
}
host->read_id_bytes = (f->page_size == 2048) ? 4 : 2;
host->col_addr_cycles = (f->page_size == 2048) ? 2 : 1;
if (f->num_blocks * f->page_per_block > 65536)
host->row_addr_cycles = 3;
else
host->row_addr_cycles = 2;
ndcr |= (pdata->enable_arbiter) ? NDCR_ND_ARB_EN : 0;
ndcr |= (host->col_addr_cycles == 2) ? NDCR_RA_START : 0;
ndcr |= (f->page_per_block == 64) ? NDCR_PG_PER_BLK : 0;
ndcr |= (f->page_size == 2048) ? NDCR_PAGE_SZ : 0;
ndcr |= (f->flash_width == 16) ? NDCR_DWIDTH_M : 0;
ndcr |= (f->dfc_width == 16) ? NDCR_DWIDTH_C : 0;
ndcr |= NDCR_RD_ID_CNT(host->read_id_bytes);
ndcr |= NDCR_SPARE_EN;
info->reg_ndcr = ndcr;
pxa3xx_nand_set_timing(host, f->timing);
return 0;
}
static int pxa3xx_nand_detect_config(struct pxa3xx_nand_info *info)
{
struct pxa3xx_nand_host *host = info->host[0];
uint32_t ndcr = nand_readl(info, NDCR);
if (ndcr & NDCR_PAGE_SZ) {
info->chunk_size = 2048;
host->read_id_bytes = 4;
} else {
info->chunk_size = 512;
host->read_id_bytes = 2;
}
info->reg_ndcr = ndcr & ~NDCR_INT_MASK;
info->ndtr0cs0 = nand_readl(info, NDTR0CS0);
info->ndtr1cs0 = nand_readl(info, NDTR1CS0);
return 0;
}
static int pxa3xx_nand_init_buff(struct pxa3xx_nand_info *info)
{
struct platform_device *pdev = info->pdev;
int data_desc_offset = info->buf_size - sizeof(struct pxa_dma_desc);
if (use_dma == 0) {
info->data_buff = kmalloc(info->buf_size, GFP_KERNEL);
if (info->data_buff == NULL)
return -ENOMEM;
return 0;
}
info->data_buff = dma_alloc_coherent(&pdev->dev, info->buf_size,
&info->data_buff_phys, GFP_KERNEL);
if (info->data_buff == NULL) {
dev_err(&pdev->dev, "failed to allocate dma buffer\n");
return -ENOMEM;
}
info->data_desc = (void *)info->data_buff + data_desc_offset;
info->data_desc_addr = info->data_buff_phys + data_desc_offset;
info->data_dma_ch = pxa_request_dma("nand-data", DMA_PRIO_LOW,
pxa3xx_nand_data_dma_irq, info);
if (info->data_dma_ch < 0) {
dev_err(&pdev->dev, "failed to request data dma\n");
dma_free_coherent(&pdev->dev, info->buf_size,
info->data_buff, info->data_buff_phys);
return info->data_dma_ch;
}
info->use_dma = 1;
return 0;
}
static void pxa3xx_nand_free_buff(struct pxa3xx_nand_info *info)
{
struct platform_device *pdev = info->pdev;
if (info->use_dma) {
pxa_free_dma(info->data_dma_ch);
dma_free_coherent(&pdev->dev, info->buf_size,
info->data_buff, info->data_buff_phys);
} else {
kfree(info->data_buff);
}
}
static int pxa3xx_nand_init_buff(struct pxa3xx_nand_info *info)
{
info->data_buff = kmalloc(info->buf_size, GFP_KERNEL);
if (info->data_buff == NULL)
return -ENOMEM;
return 0;
}
static void pxa3xx_nand_free_buff(struct pxa3xx_nand_info *info)
{
kfree(info->data_buff);
}
static int pxa3xx_nand_sensing(struct pxa3xx_nand_info *info)
{
struct mtd_info *mtd;
struct nand_chip *chip;
int ret;
mtd = info->host[info->cs]->mtd;
chip = mtd->priv;
ret = pxa3xx_nand_config_flash(info, &builtin_flash_types[0]);
if (ret)
return ret;
chip->cmdfunc(mtd, NAND_CMD_RESET, 0, 0);
ret = chip->waitfunc(mtd, chip);
if (ret & NAND_STATUS_FAIL)
return -ENODEV;
return 0;
}
static int pxa_ecc_init(struct pxa3xx_nand_info *info,
struct nand_ecc_ctrl *ecc,
int strength, int ecc_stepsize, int page_size)
{
if (strength == 1 && ecc_stepsize == 512 && page_size == 2048) {
info->chunk_size = 2048;
info->spare_size = 40;
info->ecc_size = 24;
ecc->mode = NAND_ECC_HW;
ecc->size = 512;
ecc->strength = 1;
} else if (strength == 1 && ecc_stepsize == 512 && page_size == 512) {
info->chunk_size = 512;
info->spare_size = 8;
info->ecc_size = 8;
ecc->mode = NAND_ECC_HW;
ecc->size = 512;
ecc->strength = 1;
} else if (strength == 4 && ecc_stepsize == 512 && page_size == 2048) {
info->ecc_bch = 1;
info->chunk_size = 2048;
info->spare_size = 32;
info->ecc_size = 32;
ecc->mode = NAND_ECC_HW;
ecc->size = info->chunk_size;
ecc->layout = &ecc_layout_2KB_bch4bit;
ecc->strength = 16;
} else if (strength == 4 && ecc_stepsize == 512 && page_size == 4096) {
info->ecc_bch = 1;
info->chunk_size = 2048;
info->spare_size = 32;
info->ecc_size = 32;
ecc->mode = NAND_ECC_HW;
ecc->size = info->chunk_size;
ecc->layout = &ecc_layout_4KB_bch4bit;
ecc->strength = 16;
} else if (strength == 8 && ecc_stepsize == 512 && page_size == 4096) {
info->ecc_bch = 1;
info->chunk_size = 1024;
info->spare_size = 0;
info->ecc_size = 32;
ecc->mode = NAND_ECC_HW;
ecc->size = info->chunk_size;
ecc->layout = &ecc_layout_4KB_bch8bit;
ecc->strength = 16;
} else {
dev_err(&info->pdev->dev,
"ECC strength %d at page size %d is not supported\n",
strength, page_size);
return -ENODEV;
}
dev_info(&info->pdev->dev, "ECC strength %d, ECC step size %d\n",
ecc->strength, ecc->size);
return 0;
}
static int pxa3xx_nand_scan(struct mtd_info *mtd)
{
struct pxa3xx_nand_host *host = mtd->priv;
struct pxa3xx_nand_info *info = host->info_data;
struct platform_device *pdev = info->pdev;
struct pxa3xx_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct nand_flash_dev pxa3xx_flash_ids[2], *def = NULL;
const struct pxa3xx_nand_flash *f = NULL;
struct nand_chip *chip = mtd->priv;
uint32_t id = -1;
uint64_t chipsize;
int i, ret, num;
uint16_t ecc_strength, ecc_step;
if (pdata->keep_config && !pxa3xx_nand_detect_config(info))
goto KEEP_CONFIG;
ret = pxa3xx_nand_sensing(info);
if (ret) {
dev_info(&info->pdev->dev, "There is no chip on cs %d!\n",
info->cs);
return ret;
}
chip->cmdfunc(mtd, NAND_CMD_READID, 0, 0);
id = *((uint16_t *)(info->data_buff));
if (id != 0)
dev_info(&info->pdev->dev, "Detect a flash id %x\n", id);
else {
dev_warn(&info->pdev->dev,
"Read out ID 0, potential timing set wrong!!\n");
return -EINVAL;
}
num = ARRAY_SIZE(builtin_flash_types) + pdata->num_flash - 1;
for (i = 0; i < num; i++) {
if (i < pdata->num_flash)
f = pdata->flash + i;
else
f = &builtin_flash_types[i - pdata->num_flash + 1];
if (f->chip_id == id)
break;
}
if (i >= (ARRAY_SIZE(builtin_flash_types) + pdata->num_flash - 1)) {
dev_err(&info->pdev->dev, "ERROR!! flash not defined!!!\n");
return -EINVAL;
}
ret = pxa3xx_nand_config_flash(info, f);
if (ret) {
dev_err(&info->pdev->dev, "ERROR! Configure failed\n");
return ret;
}
memset(pxa3xx_flash_ids, 0, sizeof(pxa3xx_flash_ids));
pxa3xx_flash_ids[0].name = f->name;
pxa3xx_flash_ids[0].dev_id = (f->chip_id >> 8) & 0xffff;
pxa3xx_flash_ids[0].pagesize = f->page_size;
chipsize = (uint64_t)f->num_blocks * f->page_per_block * f->page_size;
pxa3xx_flash_ids[0].chipsize = chipsize >> 20;
pxa3xx_flash_ids[0].erasesize = f->page_size * f->page_per_block;
if (f->flash_width == 16)
pxa3xx_flash_ids[0].options = NAND_BUSWIDTH_16;
pxa3xx_flash_ids[1].name = NULL;
def = pxa3xx_flash_ids;
KEEP_CONFIG:
if (info->reg_ndcr & NDCR_DWIDTH_M)
chip->options |= NAND_BUSWIDTH_16;
if (info->variant == PXA3XX_NAND_VARIANT_ARMADA370)
nand_writel(info, NDECCCTRL, 0x0);
if (nand_scan_ident(mtd, 1, def))
return -ENODEV;
if (pdata->flash_bbt) {
chip->bbt_options |= NAND_BBT_USE_FLASH |
NAND_BBT_NO_OOB_BBM;
chip->bbt_td = &bbt_main_descr;
chip->bbt_md = &bbt_mirror_descr;
}
if (mtd->writesize > PAGE_CHUNK_SIZE) {
if (info->variant == PXA3XX_NAND_VARIANT_ARMADA370) {
chip->cmdfunc = nand_cmdfunc_extended;
} else {
dev_err(&info->pdev->dev,
"unsupported page size on this variant\n");
return -ENODEV;
}
}
if (pdata->ecc_strength && pdata->ecc_step_size) {
ecc_strength = pdata->ecc_strength;
ecc_step = pdata->ecc_step_size;
} else {
ecc_strength = chip->ecc_strength_ds;
ecc_step = chip->ecc_step_ds;
}
if (ecc_strength < 1 && ecc_step < 1) {
ecc_strength = 1;
ecc_step = 512;
}
ret = pxa_ecc_init(info, &chip->ecc, ecc_strength,
ecc_step, mtd->writesize);
if (ret)
return ret;
if (mtd->writesize >= 2048)
host->col_addr_cycles = 2;
else
host->col_addr_cycles = 1;
kfree(info->data_buff);
info->buf_size = mtd->writesize + mtd->oobsize;
ret = pxa3xx_nand_init_buff(info);
if (ret)
return ret;
info->oob_buff = info->data_buff + mtd->writesize;
if ((mtd->size >> chip->page_shift) > 65536)
host->row_addr_cycles = 3;
else
host->row_addr_cycles = 2;
return nand_scan_tail(mtd);
}
static int alloc_nand_resource(struct platform_device *pdev)
{
struct pxa3xx_nand_platform_data *pdata;
struct pxa3xx_nand_info *info;
struct pxa3xx_nand_host *host;
struct nand_chip *chip = NULL;
struct mtd_info *mtd;
struct resource *r;
int ret, irq, cs;
pdata = dev_get_platdata(&pdev->dev);
if (pdata->num_cs <= 0)
return -ENODEV;
info = devm_kzalloc(&pdev->dev, sizeof(*info) + (sizeof(*mtd) +
sizeof(*host)) * pdata->num_cs, GFP_KERNEL);
if (!info)
return -ENOMEM;
info->pdev = pdev;
info->variant = pxa3xx_nand_get_variant(pdev);
for (cs = 0; cs < pdata->num_cs; cs++) {
mtd = (struct mtd_info *)((unsigned int)&info[1] +
(sizeof(*mtd) + sizeof(*host)) * cs);
chip = (struct nand_chip *)(&mtd[1]);
host = (struct pxa3xx_nand_host *)chip;
info->host[cs] = host;
host->mtd = mtd;
host->cs = cs;
host->info_data = info;
mtd->priv = host;
mtd->owner = THIS_MODULE;
chip->ecc.read_page = pxa3xx_nand_read_page_hwecc;
chip->ecc.write_page = pxa3xx_nand_write_page_hwecc;
chip->controller = &info->controller;
chip->waitfunc = pxa3xx_nand_waitfunc;
chip->select_chip = pxa3xx_nand_select_chip;
chip->read_word = pxa3xx_nand_read_word;
chip->read_byte = pxa3xx_nand_read_byte;
chip->read_buf = pxa3xx_nand_read_buf;
chip->write_buf = pxa3xx_nand_write_buf;
chip->options |= NAND_NO_SUBPAGE_WRITE;
chip->cmdfunc = nand_cmdfunc;
}
spin_lock_init(&chip->controller->lock);
init_waitqueue_head(&chip->controller->wq);
info->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed to get nand clock\n");
return PTR_ERR(info->clk);
}
ret = clk_prepare_enable(info->clk);
if (ret < 0)
return ret;
if (use_dma) {
if (pdev->dev.of_node &&
of_machine_is_compatible("marvell,pxa3xx")) {
info->drcmr_dat = 97;
info->drcmr_cmd = 99;
} else {
r = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (r == NULL) {
dev_err(&pdev->dev,
"no resource defined for data DMA\n");
ret = -ENXIO;
goto fail_disable_clk;
}
info->drcmr_dat = r->start;
r = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (r == NULL) {
dev_err(&pdev->dev,
"no resource defined for cmd DMA\n");
ret = -ENXIO;
goto fail_disable_clk;
}
info->drcmr_cmd = r->start;
}
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no IRQ resource defined\n");
ret = -ENXIO;
goto fail_disable_clk;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(info->mmio_base)) {
ret = PTR_ERR(info->mmio_base);
goto fail_disable_clk;
}
info->mmio_phys = r->start;
info->buf_size = INIT_BUFFER_SIZE;
info->data_buff = kmalloc(info->buf_size, GFP_KERNEL);
if (info->data_buff == NULL) {
ret = -ENOMEM;
goto fail_disable_clk;
}
disable_int(info, NDSR_MASK);
ret = request_threaded_irq(irq, pxa3xx_nand_irq,
pxa3xx_nand_irq_thread, IRQF_ONESHOT,
pdev->name, info);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request IRQ\n");
goto fail_free_buf;
}
platform_set_drvdata(pdev, info);
return 0;
fail_free_buf:
free_irq(irq, info);
kfree(info->data_buff);
fail_disable_clk:
clk_disable_unprepare(info->clk);
return ret;
}
static int pxa3xx_nand_remove(struct platform_device *pdev)
{
struct pxa3xx_nand_info *info = platform_get_drvdata(pdev);
struct pxa3xx_nand_platform_data *pdata;
int irq, cs;
if (!info)
return 0;
pdata = dev_get_platdata(&pdev->dev);
irq = platform_get_irq(pdev, 0);
if (irq >= 0)
free_irq(irq, info);
pxa3xx_nand_free_buff(info);
clk_disable_unprepare(info->clk);
for (cs = 0; cs < pdata->num_cs; cs++)
nand_release(info->host[cs]->mtd);
return 0;
}
static int pxa3xx_nand_probe_dt(struct platform_device *pdev)
{
struct pxa3xx_nand_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(pxa3xx_nand_dt_ids, &pdev->dev);
if (!of_id)
return 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (of_get_property(np, "marvell,nand-enable-arbiter", NULL))
pdata->enable_arbiter = 1;
if (of_get_property(np, "marvell,nand-keep-config", NULL))
pdata->keep_config = 1;
of_property_read_u32(np, "num-cs", &pdata->num_cs);
pdata->flash_bbt = of_get_nand_on_flash_bbt(np);
pdata->ecc_strength = of_get_nand_ecc_strength(np);
if (pdata->ecc_strength < 0)
pdata->ecc_strength = 0;
pdata->ecc_step_size = of_get_nand_ecc_step_size(np);
if (pdata->ecc_step_size < 0)
pdata->ecc_step_size = 0;
pdev->dev.platform_data = pdata;
return 0;
}
static int pxa3xx_nand_probe(struct platform_device *pdev)
{
struct pxa3xx_nand_platform_data *pdata;
struct mtd_part_parser_data ppdata = {};
struct pxa3xx_nand_info *info;
int ret, cs, probe_success;
#ifndef ARCH_HAS_DMA
if (use_dma) {
use_dma = 0;
dev_warn(&pdev->dev,
"This platform can't do DMA on this device\n");
}
#endif
ret = pxa3xx_nand_probe_dt(pdev);
if (ret)
return ret;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "no platform data defined\n");
return -ENODEV;
}
ret = alloc_nand_resource(pdev);
if (ret) {
dev_err(&pdev->dev, "alloc nand resource failed\n");
return ret;
}
info = platform_get_drvdata(pdev);
probe_success = 0;
for (cs = 0; cs < pdata->num_cs; cs++) {
struct mtd_info *mtd = info->host[cs]->mtd;
mtd->name = "pxa3xx_nand-0";
info->cs = cs;
ret = pxa3xx_nand_scan(mtd);
if (ret) {
dev_warn(&pdev->dev, "failed to scan nand at cs %d\n",
cs);
continue;
}
ppdata.of_node = pdev->dev.of_node;
ret = mtd_device_parse_register(mtd, NULL,
&ppdata, pdata->parts[cs],
pdata->nr_parts[cs]);
if (!ret)
probe_success = 1;
}
if (!probe_success) {
pxa3xx_nand_remove(pdev);
return -ENODEV;
}
return 0;
}
static int pxa3xx_nand_suspend(struct platform_device *pdev, pm_message_t state)
{
struct pxa3xx_nand_info *info = platform_get_drvdata(pdev);
struct pxa3xx_nand_platform_data *pdata;
struct mtd_info *mtd;
int cs;
pdata = dev_get_platdata(&pdev->dev);
if (info->state) {
dev_err(&pdev->dev, "driver busy, state = %d\n", info->state);
return -EAGAIN;
}
for (cs = 0; cs < pdata->num_cs; cs++) {
mtd = info->host[cs]->mtd;
mtd_suspend(mtd);
}
return 0;
}
static int pxa3xx_nand_resume(struct platform_device *pdev)
{
struct pxa3xx_nand_info *info = platform_get_drvdata(pdev);
struct pxa3xx_nand_platform_data *pdata;
struct mtd_info *mtd;
int cs;
pdata = dev_get_platdata(&pdev->dev);
disable_int(info, NDCR_INT_MASK);
info->cs = 0xff;
nand_writel(info, NDSR, NDSR_MASK);
for (cs = 0; cs < pdata->num_cs; cs++) {
mtd = info->host[cs]->mtd;
mtd_resume(mtd);
}
return 0;
}
