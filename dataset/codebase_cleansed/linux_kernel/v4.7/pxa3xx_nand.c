static int pxa3xx_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
struct pxa3xx_nand_info *info = host->info_data;
int nchunks = mtd->writesize / info->chunk_size;
if (section >= nchunks)
return -ERANGE;
oobregion->offset = ((info->ecc_size + info->spare_size) * section) +
info->spare_size;
oobregion->length = info->ecc_size;
return 0;
}
static int pxa3xx_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
struct pxa3xx_nand_info *info = host->info_data;
int nchunks = mtd->writesize / info->chunk_size;
if (section >= nchunks)
return -ERANGE;
if (!info->spare_size)
return 0;
oobregion->offset = section * (info->ecc_size + info->spare_size);
oobregion->length = info->spare_size;
if (!section) {
if (mtd->writesize == 4096 && info->chunk_size == 2048) {
oobregion->offset += 6;
oobregion->length -= 6;
} else {
oobregion->offset += 2;
oobregion->length -= 2;
}
}
return 0;
}
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
static void pxa3xx_nand_set_sdr_timing(struct pxa3xx_nand_host *host,
const struct nand_sdr_timings *t)
{
struct pxa3xx_nand_info *info = host->info_data;
struct nand_chip *chip = &host->chip;
unsigned long nand_clk = clk_get_rate(info->clk);
uint32_t ndtr0, ndtr1;
u32 tCH_min = DIV_ROUND_UP(t->tCH_min, 1000);
u32 tCS_min = DIV_ROUND_UP(t->tCS_min, 1000);
u32 tWH_min = DIV_ROUND_UP(t->tWH_min, 1000);
u32 tWP_min = DIV_ROUND_UP(t->tWC_min - t->tWH_min, 1000);
u32 tREH_min = DIV_ROUND_UP(t->tREH_min, 1000);
u32 tRP_min = DIV_ROUND_UP(t->tRC_min - t->tREH_min, 1000);
u32 tR = chip->chip_delay * 1000;
u32 tWHR_min = DIV_ROUND_UP(t->tWHR_min, 1000);
u32 tAR_min = DIV_ROUND_UP(t->tAR_min, 1000);
if (!tR)
tR = 20000;
ndtr0 = NDTR0_tCH(ns2cycle(tCH_min, nand_clk)) |
NDTR0_tCS(ns2cycle(tCS_min, nand_clk)) |
NDTR0_tWH(ns2cycle(tWH_min, nand_clk)) |
NDTR0_tWP(ns2cycle(tWP_min, nand_clk)) |
NDTR0_tRH(ns2cycle(tREH_min, nand_clk)) |
NDTR0_tRP(ns2cycle(tRP_min, nand_clk));
ndtr1 = NDTR1_tR(ns2cycle(tR, nand_clk)) |
NDTR1_tWHR(ns2cycle(tWHR_min, nand_clk)) |
NDTR1_tAR(ns2cycle(tAR_min, nand_clk));
info->ndtr0cs0 = ndtr0;
info->ndtr1cs0 = ndtr1;
nand_writel(info, NDTR0CS0, ndtr0);
nand_writel(info, NDTR1CS0, ndtr1);
}
static int pxa3xx_nand_init_timings_compat(struct pxa3xx_nand_host *host,
unsigned int *flash_width,
unsigned int *dfc_width)
{
struct nand_chip *chip = &host->chip;
struct pxa3xx_nand_info *info = host->info_data;
const struct pxa3xx_nand_flash *f = NULL;
struct mtd_info *mtd = nand_to_mtd(&host->chip);
int i, id, ntypes;
ntypes = ARRAY_SIZE(builtin_flash_types);
chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
id = chip->read_byte(mtd);
id |= chip->read_byte(mtd) << 0x8;
for (i = 0; i < ntypes; i++) {
f = &builtin_flash_types[i];
if (f->chip_id == id)
break;
}
if (i == ntypes) {
dev_err(&info->pdev->dev, "Error: timings not found\n");
return -EINVAL;
}
pxa3xx_nand_set_timing(host, f->timing);
*flash_width = f->flash_width;
*dfc_width = f->dfc_width;
return 0;
}
static int pxa3xx_nand_init_timings_onfi(struct pxa3xx_nand_host *host,
int mode)
{
const struct nand_sdr_timings *timings;
mode = fls(mode) - 1;
if (mode < 0)
mode = 0;
timings = onfi_async_timing_mode_to_sdr_timings(mode);
if (IS_ERR(timings))
return PTR_ERR(timings);
pxa3xx_nand_set_sdr_timing(host, timings);
return 0;
}
static int pxa3xx_nand_init(struct pxa3xx_nand_host *host)
{
struct nand_chip *chip = &host->chip;
struct pxa3xx_nand_info *info = host->info_data;
unsigned int flash_width = 0, dfc_width = 0;
int mode, err;
mode = onfi_get_async_timing_mode(chip);
if (mode == ONFI_TIMING_MODE_UNKNOWN) {
err = pxa3xx_nand_init_timings_compat(host, &flash_width,
&dfc_width);
if (err)
return err;
if (flash_width == 16) {
info->reg_ndcr |= NDCR_DWIDTH_M;
chip->options |= NAND_BUSWIDTH_16;
}
info->reg_ndcr |= (dfc_width == 16) ? NDCR_DWIDTH_C : 0;
} else {
err = pxa3xx_nand_init_timings_onfi(host, mode);
if (err)
return err;
}
return 0;
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
nand_writel(info, NDSR, NDSR_MASK);
nand_writel(info, NDCR, 0);
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
if (info->dma_chan)
dmaengine_terminate_all(info->dma_chan);
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
u32 val;
int ret;
while (len > 8) {
ioread32_rep(info->mmio_base + NDDB, data, 8);
ret = readl_relaxed_poll_timeout(info->mmio_base + NDSR, val,
val & NDSR_RDDREQ, 1000, 5000);
if (ret) {
dev_err(&info->pdev->dev,
"Timeout on RDDREQ while draining the FIFO\n");
return;
}
data += 32;
len -= 8;
}
}
ioread32_rep(info->mmio_base + NDDB, data, len);
}
static void handle_data_pio(struct pxa3xx_nand_info *info)
{
switch (info->state) {
case STATE_PIO_WRITING:
if (info->step_chunk_size)
writesl(info->mmio_base + NDDB,
info->data_buff + info->data_buff_pos,
DIV_ROUND_UP(info->step_chunk_size, 4));
if (info->step_spare_size)
writesl(info->mmio_base + NDDB,
info->oob_buff + info->oob_buff_pos,
DIV_ROUND_UP(info->step_spare_size, 4));
break;
case STATE_PIO_READING:
if (info->step_chunk_size)
drain_fifo(info,
info->data_buff + info->data_buff_pos,
DIV_ROUND_UP(info->step_chunk_size, 4));
if (info->step_spare_size)
drain_fifo(info,
info->oob_buff + info->oob_buff_pos,
DIV_ROUND_UP(info->step_spare_size, 4));
break;
default:
dev_err(&info->pdev->dev, "%s: invalid state %d\n", __func__,
info->state);
BUG();
}
info->data_buff_pos += info->step_chunk_size;
info->oob_buff_pos += info->step_spare_size;
}
static void pxa3xx_nand_data_dma_irq(void *data)
{
struct pxa3xx_nand_info *info = data;
struct dma_tx_state state;
enum dma_status status;
status = dmaengine_tx_status(info->dma_chan, info->dma_cookie, &state);
if (likely(status == DMA_COMPLETE)) {
info->state = STATE_DMA_DONE;
} else {
dev_err(&info->pdev->dev, "DMA error on data channel\n");
info->retcode = ERR_DMABUSERR;
}
dma_unmap_sg(info->dma_chan->device->dev, &info->sg, 1, info->dma_dir);
nand_writel(info, NDSR, NDSR_WRDREQ | NDSR_RDDREQ);
enable_int(info, NDCR_INT_MASK);
}
static void start_data_dma(struct pxa3xx_nand_info *info)
{
enum dma_transfer_direction direction;
struct dma_async_tx_descriptor *tx;
switch (info->state) {
case STATE_DMA_WRITING:
info->dma_dir = DMA_TO_DEVICE;
direction = DMA_MEM_TO_DEV;
break;
case STATE_DMA_READING:
info->dma_dir = DMA_FROM_DEVICE;
direction = DMA_DEV_TO_MEM;
break;
default:
dev_err(&info->pdev->dev, "%s: invalid state %d\n", __func__,
info->state);
BUG();
}
info->sg.length = info->chunk_size;
if (info->use_spare)
info->sg.length += info->spare_size + info->ecc_size;
dma_map_sg(info->dma_chan->device->dev, &info->sg, 1, info->dma_dir);
tx = dmaengine_prep_slave_sg(info->dma_chan, &info->sg, 1, direction,
DMA_PREP_INTERRUPT);
if (!tx) {
dev_err(&info->pdev->dev, "prep_slave_sg() failed\n");
return;
}
tx->callback = pxa3xx_nand_data_dma_irq;
tx->callback_param = info;
info->dma_cookie = dmaengine_submit(tx);
dma_async_issue_pending(info->dma_chan);
dev_dbg(&info->pdev->dev, "%s(dir=%d cookie=%x size=%u)\n",
__func__, direction, info->dma_cookie, info->sg.length);
}
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
nand_writel(info, NDSR, status);
if (status & NDSR_WRCMDREQ) {
status &= ~NDSR_WRCMDREQ;
info->state = STATE_CMD_HANDLE;
nand_writel(info, NDCB0, info->ndcb0);
nand_writel(info, NDCB0, info->ndcb1);
nand_writel(info, NDCB0, info->ndcb2);
if (info->variant == PXA3XX_NAND_VARIANT_ARMADA370)
nand_writel(info, NDCB0, info->ndcb3);
}
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
struct mtd_info *mtd = nand_to_mtd(&host->chip);
info->buf_start = 0;
info->buf_count = 0;
info->data_buff_pos = 0;
info->oob_buff_pos = 0;
info->step_chunk_size = 0;
info->step_spare_size = 0;
info->cur_chunk = 0;
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
mtd = nand_to_mtd(&host->chip);
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
if (info->cur_chunk < info->nfullchunks) {
info->step_chunk_size = info->chunk_size;
info->step_spare_size = info->spare_size;
} else {
info->step_chunk_size = info->last_chunk_size;
info->step_spare_size = info->last_spare_size;
}
if (mtd->writesize == PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_DBC | (NAND_CMD_READSTART << 8);
} else if (mtd->writesize > PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_DBC | (NAND_CMD_READSTART << 8)
| NDCB0_LEN_OVRD
| NDCB0_EXT_CMD_TYPE(ext_cmd_type);
info->ndcb3 = info->step_chunk_size +
info->step_spare_size;
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
exec_cmd = 1;
}
break;
case NAND_CMD_PAGEPROG:
if (is_buf_blank(info->data_buff,
(mtd->writesize + mtd->oobsize))) {
exec_cmd = 0;
break;
}
if (info->cur_chunk < info->nfullchunks) {
info->step_chunk_size = info->chunk_size;
info->step_spare_size = info->spare_size;
} else {
info->step_chunk_size = info->last_chunk_size;
info->step_spare_size = info->last_spare_size;
}
if (mtd->writesize > PAGE_CHUNK_SIZE) {
info->ndcb0 |= NDCB0_CMD_TYPE(0x1)
| NDCB0_LEN_OVRD
| NDCB0_EXT_CMD_TYPE(ext_cmd_type);
info->ndcb3 = info->step_chunk_size +
info->step_spare_size;
if (info->cur_chunk == info->ntotalchunks) {
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
info->buf_count = INIT_BUFFER_SIZE;
info->ndcb0 |= NDCB0_CMD_TYPE(0)
| NDCB0_ADDR_CYC(1)
| NDCB0_LEN_OVRD
| command;
info->ndcb1 = (column & 0xFF);
info->ndcb3 = INIT_BUFFER_SIZE;
info->step_chunk_size = INIT_BUFFER_SIZE;
break;
case NAND_CMD_READID:
info->buf_count = READ_ID_BYTES;
info->ndcb0 |= NDCB0_CMD_TYPE(3)
| NDCB0_ADDR_CYC(1)
| command;
info->ndcb1 = (column & 0xFF);
info->step_chunk_size = 8;
break;
case NAND_CMD_STATUS:
info->buf_count = 1;
info->ndcb0 |= NDCB0_CMD_TYPE(4)
| NDCB0_ADDR_CYC(1)
| command;
info->step_chunk_size = 8;
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
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
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
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
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
if (command != NAND_CMD_PAGEPROG &&
command != NAND_CMD_READ0 &&
command != NAND_CMD_READOOB)
break;
info->cur_chunk++;
if (info->cur_chunk == info->ntotalchunks && command != NAND_CMD_PAGEPROG)
break;
if (info->cur_chunk == (info->ntotalchunks + 1) &&
command == NAND_CMD_PAGEPROG &&
ext_cmd_type == EXT_CMD_TYPE_DISPATCH)
break;
if (command == NAND_CMD_READ0 || command == NAND_CMD_READOOB) {
if (info->cur_chunk == info->ntotalchunks - 1)
ext_cmd_type = EXT_CMD_TYPE_LAST_RW;
else
ext_cmd_type = EXT_CMD_TYPE_NAKED_RW;
} else if (command == NAND_CMD_PAGEPROG &&
info->cur_chunk == info->ntotalchunks) {
ext_cmd_type = EXT_CMD_TYPE_DISPATCH;
}
} while (1);
info->state = STATE_IDLE;
}
static int pxa3xx_nand_write_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf, int oob_required,
int page)
{
chip->write_buf(mtd, buf, mtd->writesize);
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int pxa3xx_nand_read_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf, int oob_required,
int page)
{
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
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
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
struct pxa3xx_nand_info *info = host->info_data;
char retval = 0xFF;
if (info->buf_start < info->buf_count)
retval = info->data_buff[info->buf_start++];
return retval;
}
static u16 pxa3xx_nand_read_word(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
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
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
struct pxa3xx_nand_info *info = host->info_data;
int real_len = min_t(size_t, len, info->buf_count - info->buf_start);
memcpy(buf, info->data_buff + info->buf_start, real_len);
info->buf_start += real_len;
}
static void pxa3xx_nand_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
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
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
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
static int pxa3xx_nand_config_ident(struct pxa3xx_nand_info *info)
{
struct pxa3xx_nand_host *host = info->host[info->cs];
struct platform_device *pdev = info->pdev;
struct pxa3xx_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
const struct nand_sdr_timings *timings;
info->chunk_size = PAGE_CHUNK_SIZE;
info->reg_ndcr = 0x0;
info->reg_ndcr |= (pdata->enable_arbiter) ? NDCR_ND_ARB_EN : 0;
info->reg_ndcr |= NDCR_RD_ID_CNT(READ_ID_BYTES);
info->reg_ndcr |= NDCR_SPARE_EN;
timings = onfi_async_timing_mode_to_sdr_timings(0);
if (IS_ERR(timings))
return PTR_ERR(timings);
pxa3xx_nand_set_sdr_timing(host, timings);
return 0;
}
static void pxa3xx_nand_config_tail(struct pxa3xx_nand_info *info)
{
struct pxa3xx_nand_host *host = info->host[info->cs];
struct nand_chip *chip = &host->chip;
struct mtd_info *mtd = nand_to_mtd(chip);
info->reg_ndcr |= (host->col_addr_cycles == 2) ? NDCR_RA_START : 0;
info->reg_ndcr |= (chip->page_shift == 6) ? NDCR_PG_PER_BLK : 0;
info->reg_ndcr |= (mtd->writesize == 2048) ? NDCR_PAGE_SZ : 0;
}
static void pxa3xx_nand_detect_config(struct pxa3xx_nand_info *info)
{
struct platform_device *pdev = info->pdev;
struct pxa3xx_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
uint32_t ndcr = nand_readl(info, NDCR);
info->chunk_size = ndcr & NDCR_PAGE_SZ ? 2048 : 512;
info->reg_ndcr = ndcr &
~(NDCR_INT_MASK | NDCR_ND_ARB_EN | NFCV1_NDCR_ARB_CNTL);
info->reg_ndcr |= (pdata->enable_arbiter) ? NDCR_ND_ARB_EN : 0;
info->ndtr0cs0 = nand_readl(info, NDTR0CS0);
info->ndtr1cs0 = nand_readl(info, NDTR1CS0);
}
static int pxa3xx_nand_init_buff(struct pxa3xx_nand_info *info)
{
struct platform_device *pdev = info->pdev;
struct dma_slave_config config;
dma_cap_mask_t mask;
struct pxad_param param;
int ret;
info->data_buff = kmalloc(info->buf_size, GFP_KERNEL);
if (info->data_buff == NULL)
return -ENOMEM;
if (use_dma == 0)
return 0;
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
sg_init_one(&info->sg, info->data_buff, info->buf_size);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
param.prio = PXAD_PRIO_LOWEST;
param.drcmr = info->drcmr_dat;
info->dma_chan = dma_request_slave_channel_compat(mask, pxad_filter_fn,
&param, &pdev->dev,
"data");
if (!info->dma_chan) {
dev_err(&pdev->dev, "unable to request data dma channel\n");
return -ENODEV;
}
memset(&config, 0, sizeof(config));
config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
config.src_addr = info->mmio_phys + NDDB;
config.dst_addr = info->mmio_phys + NDDB;
config.src_maxburst = 32;
config.dst_maxburst = 32;
ret = dmaengine_slave_config(info->dma_chan, &config);
if (ret < 0) {
dev_err(&info->pdev->dev,
"dma channel configuration failed: %d\n",
ret);
return ret;
}
info->use_dma = 1;
return 0;
}
static void pxa3xx_nand_free_buff(struct pxa3xx_nand_info *info)
{
if (info->use_dma) {
dmaengine_terminate_all(info->dma_chan);
dma_release_channel(info->dma_chan);
}
kfree(info->data_buff);
}
static int pxa_ecc_init(struct pxa3xx_nand_info *info,
struct mtd_info *mtd,
int strength, int ecc_stepsize, int page_size)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (strength == 1 && ecc_stepsize == 512 && page_size == 2048) {
info->nfullchunks = 1;
info->ntotalchunks = 1;
info->chunk_size = 2048;
info->spare_size = 40;
info->ecc_size = 24;
ecc->mode = NAND_ECC_HW;
ecc->size = 512;
ecc->strength = 1;
} else if (strength == 1 && ecc_stepsize == 512 && page_size == 512) {
info->nfullchunks = 1;
info->ntotalchunks = 1;
info->chunk_size = 512;
info->spare_size = 8;
info->ecc_size = 8;
ecc->mode = NAND_ECC_HW;
ecc->size = 512;
ecc->strength = 1;
} else if (strength == 4 && ecc_stepsize == 512 && page_size == 2048) {
info->ecc_bch = 1;
info->nfullchunks = 1;
info->ntotalchunks = 1;
info->chunk_size = 2048;
info->spare_size = 32;
info->ecc_size = 32;
ecc->mode = NAND_ECC_HW;
ecc->size = info->chunk_size;
mtd_set_ooblayout(mtd, &pxa3xx_ooblayout_ops);
ecc->strength = 16;
} else if (strength == 4 && ecc_stepsize == 512 && page_size == 4096) {
info->ecc_bch = 1;
info->nfullchunks = 2;
info->ntotalchunks = 2;
info->chunk_size = 2048;
info->spare_size = 32;
info->ecc_size = 32;
ecc->mode = NAND_ECC_HW;
ecc->size = info->chunk_size;
mtd_set_ooblayout(mtd, &pxa3xx_ooblayout_ops);
ecc->strength = 16;
} else if (strength == 8 && ecc_stepsize == 512 && page_size == 4096) {
info->ecc_bch = 1;
info->nfullchunks = 4;
info->ntotalchunks = 5;
info->chunk_size = 1024;
info->spare_size = 0;
info->last_chunk_size = 0;
info->last_spare_size = 64;
info->ecc_size = 32;
ecc->mode = NAND_ECC_HW;
ecc->size = info->chunk_size;
mtd_set_ooblayout(mtd, &pxa3xx_ooblayout_ops);
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
struct nand_chip *chip = mtd_to_nand(mtd);
struct pxa3xx_nand_host *host = nand_get_controller_data(chip);
struct pxa3xx_nand_info *info = host->info_data;
struct platform_device *pdev = info->pdev;
struct pxa3xx_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
int ret;
uint16_t ecc_strength, ecc_step;
if (pdata->keep_config) {
pxa3xx_nand_detect_config(info);
} else {
ret = pxa3xx_nand_config_ident(info);
if (ret)
return ret;
}
if (info->reg_ndcr & NDCR_DWIDTH_M)
chip->options |= NAND_BUSWIDTH_16;
if (info->variant == PXA3XX_NAND_VARIANT_ARMADA370)
nand_writel(info, NDECCCTRL, 0x0);
if (pdata->flash_bbt)
chip->bbt_options |= NAND_BBT_USE_FLASH;
chip->ecc.strength = pdata->ecc_strength;
chip->ecc.size = pdata->ecc_step_size;
if (nand_scan_ident(mtd, 1, NULL))
return -ENODEV;
if (!pdata->keep_config) {
ret = pxa3xx_nand_init(host);
if (ret) {
dev_err(&info->pdev->dev, "Failed to init nand: %d\n",
ret);
return ret;
}
}
if (chip->bbt_options & NAND_BBT_USE_FLASH) {
chip->bbt_options |= NAND_BBT_NO_OOB_BBM;
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
ecc_strength = chip->ecc.strength;
ecc_step = chip->ecc.size;
if (!ecc_strength || !ecc_step) {
ecc_strength = chip->ecc_strength_ds;
ecc_step = chip->ecc_step_ds;
}
if (ecc_strength < 1 && ecc_step < 1) {
ecc_strength = 1;
ecc_step = 512;
}
ret = pxa_ecc_init(info, mtd, ecc_strength,
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
if (!pdata->keep_config)
pxa3xx_nand_config_tail(info);
return nand_scan_tail(mtd);
}
static int alloc_nand_resource(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
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
info = devm_kzalloc(&pdev->dev,
sizeof(*info) + sizeof(*host) * pdata->num_cs,
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->pdev = pdev;
info->variant = pxa3xx_nand_get_variant(pdev);
for (cs = 0; cs < pdata->num_cs; cs++) {
host = (void *)&info[1] + sizeof(*host) * cs;
chip = &host->chip;
nand_set_controller_data(chip, host);
mtd = nand_to_mtd(chip);
info->host[cs] = host;
host->cs = cs;
host->info_data = info;
mtd->dev.parent = &pdev->dev;
nand_set_flash_node(chip, np);
nand_set_controller_data(chip, host);
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
if (!np && use_dma) {
r = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (r == NULL) {
dev_err(&pdev->dev,
"no resource defined for data DMA\n");
ret = -ENXIO;
goto fail_disable_clk;
}
info->drcmr_dat = r->start;
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
nand_writel(info, NDCR,
(nand_readl(info, NDCR) & ~NDCR_ND_ARB_EN) |
NFCV1_NDCR_ARB_CNTL);
clk_disable_unprepare(info->clk);
for (cs = 0; cs < pdata->num_cs; cs++)
nand_release(nand_to_mtd(&info->host[cs]->chip));
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
pdev->dev.platform_data = pdata;
return 0;
}
static int pxa3xx_nand_probe(struct platform_device *pdev)
{
struct pxa3xx_nand_platform_data *pdata;
struct pxa3xx_nand_info *info;
int ret, cs, probe_success, dma_available;
dma_available = IS_ENABLED(CONFIG_ARM) &&
(IS_ENABLED(CONFIG_ARCH_PXA) || IS_ENABLED(CONFIG_ARCH_MMP));
if (use_dma && !dma_available) {
use_dma = 0;
dev_warn(&pdev->dev,
"This platform can't do DMA on this device\n");
}
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
struct mtd_info *mtd = nand_to_mtd(&info->host[cs]->chip);
mtd->name = "pxa3xx_nand-0";
info->cs = cs;
ret = pxa3xx_nand_scan(mtd);
if (ret) {
dev_warn(&pdev->dev, "failed to scan nand at cs %d\n",
cs);
continue;
}
ret = mtd_device_register(mtd, pdata->parts[cs],
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
static int pxa3xx_nand_suspend(struct device *dev)
{
struct pxa3xx_nand_info *info = dev_get_drvdata(dev);
if (info->state) {
dev_err(dev, "driver busy, state = %d\n", info->state);
return -EAGAIN;
}
clk_disable(info->clk);
return 0;
}
static int pxa3xx_nand_resume(struct device *dev)
{
struct pxa3xx_nand_info *info = dev_get_drvdata(dev);
int ret;
ret = clk_enable(info->clk);
if (ret < 0)
return ret;
disable_int(info, NDCR_INT_MASK);
info->cs = 0xff;
nand_writel(info, NDSR, NDSR_MASK);
return 0;
}
