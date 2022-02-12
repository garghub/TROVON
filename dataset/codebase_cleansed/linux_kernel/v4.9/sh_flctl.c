static int flctl_4secc_ooblayout_sp_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section)
return -ERANGE;
oobregion->offset = 0;
oobregion->length = chip->ecc.bytes;
return 0;
}
static int flctl_4secc_ooblayout_sp_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section)
return -ERANGE;
oobregion->offset = 12;
oobregion->length = 4;
return 0;
}
static int flctl_4secc_ooblayout_lp_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->offset = (section * 16) + 6;
oobregion->length = chip->ecc.bytes;
return 0;
}
static int flctl_4secc_ooblayout_lp_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->offset = section * 16;
oobregion->length = 6;
if (!section) {
oobregion->offset += 2;
oobregion->length -= 2;
}
return 0;
}
static void empty_fifo(struct sh_flctl *flctl)
{
writel(flctl->flintdmacr_base | AC1CLR | AC0CLR, FLINTDMACR(flctl));
writel(flctl->flintdmacr_base, FLINTDMACR(flctl));
}
static void start_translation(struct sh_flctl *flctl)
{
writeb(TRSTRT, FLTRCR(flctl));
}
static void timeout_error(struct sh_flctl *flctl, const char *str)
{
dev_err(&flctl->pdev->dev, "Timeout occurred in %s\n", str);
}
static void wait_completion(struct sh_flctl *flctl)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
while (timeout--) {
if (readb(FLTRCR(flctl)) & TREND) {
writeb(0x0, FLTRCR(flctl));
return;
}
udelay(1);
}
timeout_error(flctl, __func__);
writeb(0x0, FLTRCR(flctl));
}
static void flctl_dma_complete(void *param)
{
struct sh_flctl *flctl = param;
complete(&flctl->dma_complete);
}
static void flctl_release_dma(struct sh_flctl *flctl)
{
if (flctl->chan_fifo0_rx) {
dma_release_channel(flctl->chan_fifo0_rx);
flctl->chan_fifo0_rx = NULL;
}
if (flctl->chan_fifo0_tx) {
dma_release_channel(flctl->chan_fifo0_tx);
flctl->chan_fifo0_tx = NULL;
}
}
static void flctl_setup_dma(struct sh_flctl *flctl)
{
dma_cap_mask_t mask;
struct dma_slave_config cfg;
struct platform_device *pdev = flctl->pdev;
struct sh_flctl_platform_data *pdata = dev_get_platdata(&pdev->dev);
int ret;
if (!pdata)
return;
if (pdata->slave_id_fifo0_tx <= 0 || pdata->slave_id_fifo0_rx <= 0)
return;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
flctl->chan_fifo0_tx = dma_request_channel(mask, shdma_chan_filter,
(void *)(uintptr_t)pdata->slave_id_fifo0_tx);
dev_dbg(&pdev->dev, "%s: TX: got channel %p\n", __func__,
flctl->chan_fifo0_tx);
if (!flctl->chan_fifo0_tx)
return;
memset(&cfg, 0, sizeof(cfg));
cfg.direction = DMA_MEM_TO_DEV;
cfg.dst_addr = flctl->fifo;
cfg.src_addr = 0;
ret = dmaengine_slave_config(flctl->chan_fifo0_tx, &cfg);
if (ret < 0)
goto err;
flctl->chan_fifo0_rx = dma_request_channel(mask, shdma_chan_filter,
(void *)(uintptr_t)pdata->slave_id_fifo0_rx);
dev_dbg(&pdev->dev, "%s: RX: got channel %p\n", __func__,
flctl->chan_fifo0_rx);
if (!flctl->chan_fifo0_rx)
goto err;
cfg.direction = DMA_DEV_TO_MEM;
cfg.dst_addr = 0;
cfg.src_addr = flctl->fifo;
ret = dmaengine_slave_config(flctl->chan_fifo0_rx, &cfg);
if (ret < 0)
goto err;
init_completion(&flctl->dma_complete);
return;
err:
flctl_release_dma(flctl);
}
static void set_addr(struct mtd_info *mtd, int column, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint32_t addr = 0;
if (column == -1) {
addr = page_addr;
} else if (page_addr != -1) {
if (flctl->chip.options & NAND_BUSWIDTH_16)
column >>= 1;
if (flctl->page_size) {
addr = column & 0x0FFF;
addr |= (page_addr & 0xff) << 16;
addr |= ((page_addr >> 8) & 0xff) << 24;
if (flctl->rw_ADRCNT == ADRCNT2_E) {
uint32_t addr2;
addr2 = (page_addr >> 16) & 0xff;
writel(addr2, FLADR2(flctl));
}
} else {
addr = column;
addr |= (page_addr & 0xff) << 8;
addr |= ((page_addr >> 8) & 0xff) << 16;
addr |= ((page_addr >> 16) & 0xff) << 24;
}
}
writel(addr, FLADR(flctl));
}
static void wait_rfifo_ready(struct sh_flctl *flctl)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
while (timeout--) {
uint32_t val;
val = readl(FLDTCNTR(flctl)) >> 16;
if (val & 0xFF)
return;
udelay(1);
}
timeout_error(flctl, __func__);
}
static void wait_wfifo_ready(struct sh_flctl *flctl)
{
uint32_t len, timeout = LOOP_TIMEOUT_MAX;
while (timeout--) {
len = (readl(FLDTCNTR(flctl)) >> 16) & 0xFF;
if (len >= 4)
return;
udelay(1);
}
timeout_error(flctl, __func__);
}
static enum flctl_ecc_res_t wait_recfifo_ready
(struct sh_flctl *flctl, int sector_number)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
void __iomem *ecc_reg[4];
int i;
int state = FL_SUCCESS;
uint32_t data, size;
while (timeout--) {
size = readl(FLDTCNTR(flctl)) >> 24;
if ((size & 0xFF) == 4)
return state;
if (!(readl(FL4ECCCR(flctl)) & _4ECCEND)) {
udelay(1);
continue;
}
if (readl(FL4ECCCR(flctl)) & _4ECCFA) {
for (i = 0; i < 512; i++) {
if (flctl->done_buff[i] != 0xff) {
state = FL_ERROR;
break;
}
}
if (state == FL_SUCCESS)
dev_dbg(&flctl->pdev->dev,
"reading empty sector %d, ecc error ignored\n",
sector_number);
writel(0, FL4ECCCR(flctl));
continue;
}
ecc_reg[0] = FL4ECCRESULT0(flctl);
ecc_reg[1] = FL4ECCRESULT1(flctl);
ecc_reg[2] = FL4ECCRESULT2(flctl);
ecc_reg[3] = FL4ECCRESULT3(flctl);
for (i = 0; i < 3; i++) {
uint8_t org;
unsigned int index;
data = readl(ecc_reg[i]);
if (flctl->page_size)
index = (512 * sector_number) +
(data >> 16);
else
index = data >> 16;
org = flctl->done_buff[index];
flctl->done_buff[index] = org ^ (data & 0xFF);
}
state = FL_REPAIRABLE;
writel(0, FL4ECCCR(flctl));
}
timeout_error(flctl, __func__);
return FL_TIMEOUT;
}
static void wait_wecfifo_ready(struct sh_flctl *flctl)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
uint32_t len;
while (timeout--) {
len = (readl(FLDTCNTR(flctl)) >> 24) & 0xFF;
if (len >= 4)
return;
udelay(1);
}
timeout_error(flctl, __func__);
}
static int flctl_dma_fifo0_transfer(struct sh_flctl *flctl, unsigned long *buf,
int len, enum dma_data_direction dir)
{
struct dma_async_tx_descriptor *desc = NULL;
struct dma_chan *chan;
enum dma_transfer_direction tr_dir;
dma_addr_t dma_addr;
dma_cookie_t cookie;
uint32_t reg;
int ret;
if (dir == DMA_FROM_DEVICE) {
chan = flctl->chan_fifo0_rx;
tr_dir = DMA_DEV_TO_MEM;
} else {
chan = flctl->chan_fifo0_tx;
tr_dir = DMA_MEM_TO_DEV;
}
dma_addr = dma_map_single(chan->device->dev, buf, len, dir);
if (dma_addr)
desc = dmaengine_prep_slave_single(chan, dma_addr, len,
tr_dir, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (desc) {
reg = readl(FLINTDMACR(flctl));
reg |= DREQ0EN;
writel(reg, FLINTDMACR(flctl));
desc->callback = flctl_dma_complete;
desc->callback_param = flctl;
cookie = dmaengine_submit(desc);
if (dma_submit_error(cookie)) {
ret = dma_submit_error(cookie);
dev_warn(&flctl->pdev->dev,
"DMA submit failed, falling back to PIO\n");
goto out;
}
dma_async_issue_pending(chan);
} else {
flctl_release_dma(flctl);
dev_warn(&flctl->pdev->dev,
"DMA failed, falling back to PIO\n");
ret = -EIO;
goto out;
}
ret =
wait_for_completion_timeout(&flctl->dma_complete,
msecs_to_jiffies(3000));
if (ret <= 0) {
dmaengine_terminate_all(chan);
dev_err(&flctl->pdev->dev, "wait_for_completion_timeout\n");
}
out:
reg = readl(FLINTDMACR(flctl));
reg &= ~DREQ0EN;
writel(reg, FLINTDMACR(flctl));
dma_unmap_single(chan->device->dev, dma_addr, len, dir);
return ret;
}
static void read_datareg(struct sh_flctl *flctl, int offset)
{
unsigned long data;
unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];
wait_completion(flctl);
data = readl(FLDATAR(flctl));
*buf = le32_to_cpu(data);
}
static void read_fiforeg(struct sh_flctl *flctl, int rlen, int offset)
{
int i, len_4align;
unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];
len_4align = (rlen + 3) / 4;
if (flctl->chan_fifo0_rx && rlen >= 32 &&
flctl_dma_fifo0_transfer(flctl, buf, rlen, DMA_DEV_TO_MEM) > 0)
goto convert;
for (i = 0; i < len_4align; i++) {
wait_rfifo_ready(flctl);
buf[i] = readl(FLDTFIFO(flctl));
}
convert:
for (i = 0; i < len_4align; i++)
buf[i] = be32_to_cpu(buf[i]);
}
static enum flctl_ecc_res_t read_ecfiforeg
(struct sh_flctl *flctl, uint8_t *buff, int sector)
{
int i;
enum flctl_ecc_res_t res;
unsigned long *ecc_buf = (unsigned long *)buff;
res = wait_recfifo_ready(flctl , sector);
if (res != FL_ERROR) {
for (i = 0; i < 4; i++) {
ecc_buf[i] = readl(FLECFIFO(flctl));
ecc_buf[i] = be32_to_cpu(ecc_buf[i]);
}
}
return res;
}
static void write_fiforeg(struct sh_flctl *flctl, int rlen,
unsigned int offset)
{
int i, len_4align;
unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];
len_4align = (rlen + 3) / 4;
for (i = 0; i < len_4align; i++) {
wait_wfifo_ready(flctl);
writel(cpu_to_be32(buf[i]), FLDTFIFO(flctl));
}
}
static void write_ec_fiforeg(struct sh_flctl *flctl, int rlen,
unsigned int offset)
{
int i, len_4align;
unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];
len_4align = (rlen + 3) / 4;
for (i = 0; i < len_4align; i++)
buf[i] = cpu_to_be32(buf[i]);
if (flctl->chan_fifo0_tx && rlen >= 32 &&
flctl_dma_fifo0_transfer(flctl, buf, rlen, DMA_MEM_TO_DEV) > 0)
return;
for (i = 0; i < len_4align; i++) {
wait_wecfifo_ready(flctl);
writel(buf[i], FLECFIFO(flctl));
}
}
static void set_cmd_regs(struct mtd_info *mtd, uint32_t cmd, uint32_t flcmcdr_val)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint32_t flcmncr_val = flctl->flcmncr_base & ~SEL_16BIT;
uint32_t flcmdcr_val, addr_len_bytes = 0;
if (flctl->page_size)
flcmncr_val |= SNAND_E;
else
flcmncr_val &= ~SNAND_E;
flcmdcr_val = DOCMD1_E | DOADR_E;
switch (cmd) {
case NAND_CMD_ERASE1:
addr_len_bytes = flctl->erase_ADRCNT;
flcmdcr_val |= DOCMD2_E;
break;
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
case NAND_CMD_RNDOUT:
addr_len_bytes = flctl->rw_ADRCNT;
flcmdcr_val |= CDSRC_E;
if (flctl->chip.options & NAND_BUSWIDTH_16)
flcmncr_val |= SEL_16BIT;
break;
case NAND_CMD_SEQIN:
flcmdcr_val &= ~DOADR_E;
break;
case NAND_CMD_PAGEPROG:
addr_len_bytes = flctl->rw_ADRCNT;
flcmdcr_val |= DOCMD2_E | CDSRC_E | SELRW;
if (flctl->chip.options & NAND_BUSWIDTH_16)
flcmncr_val |= SEL_16BIT;
break;
case NAND_CMD_READID:
flcmncr_val &= ~SNAND_E;
flcmdcr_val |= CDSRC_E;
addr_len_bytes = ADRCNT_1;
break;
case NAND_CMD_STATUS:
case NAND_CMD_RESET:
flcmncr_val &= ~SNAND_E;
flcmdcr_val &= ~(DOADR_E | DOSR_E);
break;
default:
break;
}
flcmdcr_val |= addr_len_bytes;
writel(flcmncr_val, FLCMNCR(flctl));
writel(flcmdcr_val, FLCMDCR(flctl));
writel(flcmcdr_val, FLCMCDR(flctl));
}
static int flctl_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
chip->read_buf(mtd, buf, mtd->writesize);
if (oob_required)
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int flctl_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
chip->write_buf(mtd, buf, mtd->writesize);
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static void execmd_read_page_sector(struct mtd_info *mtd, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int sector, page_sectors;
enum flctl_ecc_res_t ecc_result;
page_sectors = flctl->page_size ? 4 : 1;
set_cmd_regs(mtd, NAND_CMD_READ0,
(NAND_CMD_READSTART << 8) | NAND_CMD_READ0);
writel(readl(FLCMNCR(flctl)) | ACM_SACCES_MODE | _4ECCCORRECT,
FLCMNCR(flctl));
writel(readl(FLCMDCR(flctl)) | page_sectors, FLCMDCR(flctl));
writel(page_addr << 2, FLADR(flctl));
empty_fifo(flctl);
start_translation(flctl);
for (sector = 0; sector < page_sectors; sector++) {
read_fiforeg(flctl, 512, 512 * sector);
ecc_result = read_ecfiforeg(flctl,
&flctl->done_buff[mtd->writesize + 16 * sector],
sector);
switch (ecc_result) {
case FL_REPAIRABLE:
dev_info(&flctl->pdev->dev,
"applied ecc on page 0x%x", page_addr);
mtd->ecc_stats.corrected++;
break;
case FL_ERROR:
dev_warn(&flctl->pdev->dev,
"page 0x%x contains corrupted data\n",
page_addr);
mtd->ecc_stats.failed++;
break;
default:
;
}
}
wait_completion(flctl);
writel(readl(FLCMNCR(flctl)) & ~(ACM_SACCES_MODE | _4ECCCORRECT),
FLCMNCR(flctl));
}
static void execmd_read_oob(struct mtd_info *mtd, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int page_sectors = flctl->page_size ? 4 : 1;
int i;
set_cmd_regs(mtd, NAND_CMD_READ0,
(NAND_CMD_READSTART << 8) | NAND_CMD_READ0);
empty_fifo(flctl);
for (i = 0; i < page_sectors; i++) {
set_addr(mtd, (512 + 16) * i + 512 , page_addr);
writel(16, FLDTCNTR(flctl));
start_translation(flctl);
read_fiforeg(flctl, 16, 16 * i);
wait_completion(flctl);
}
}
static void execmd_write_page_sector(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int page_addr = flctl->seqin_page_addr;
int sector, page_sectors;
page_sectors = flctl->page_size ? 4 : 1;
set_cmd_regs(mtd, NAND_CMD_PAGEPROG,
(NAND_CMD_PAGEPROG << 8) | NAND_CMD_SEQIN);
empty_fifo(flctl);
writel(readl(FLCMNCR(flctl)) | ACM_SACCES_MODE, FLCMNCR(flctl));
writel(readl(FLCMDCR(flctl)) | page_sectors, FLCMDCR(flctl));
writel(page_addr << 2, FLADR(flctl));
start_translation(flctl);
for (sector = 0; sector < page_sectors; sector++) {
write_fiforeg(flctl, 512, 512 * sector);
write_ec_fiforeg(flctl, 16, mtd->writesize + 16 * sector);
}
wait_completion(flctl);
writel(readl(FLCMNCR(flctl)) & ~ACM_SACCES_MODE, FLCMNCR(flctl));
}
static void execmd_write_oob(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int page_addr = flctl->seqin_page_addr;
int sector, page_sectors;
page_sectors = flctl->page_size ? 4 : 1;
set_cmd_regs(mtd, NAND_CMD_PAGEPROG,
(NAND_CMD_PAGEPROG << 8) | NAND_CMD_SEQIN);
for (sector = 0; sector < page_sectors; sector++) {
empty_fifo(flctl);
set_addr(mtd, sector * 528 + 512, page_addr);
writel(16, FLDTCNTR(flctl));
start_translation(flctl);
write_fiforeg(flctl, 16, 16 * sector);
wait_completion(flctl);
}
}
static void flctl_cmdfunc(struct mtd_info *mtd, unsigned int command,
int column, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint32_t read_cmd = 0;
pm_runtime_get_sync(&flctl->pdev->dev);
flctl->read_bytes = 0;
if (command != NAND_CMD_PAGEPROG)
flctl->index = 0;
switch (command) {
case NAND_CMD_READ1:
case NAND_CMD_READ0:
if (flctl->hwecc) {
execmd_read_page_sector(mtd, page_addr);
break;
}
if (flctl->page_size)
set_cmd_regs(mtd, command, (NAND_CMD_READSTART << 8)
| command);
else
set_cmd_regs(mtd, command, command);
set_addr(mtd, 0, page_addr);
flctl->read_bytes = mtd->writesize + mtd->oobsize;
if (flctl->chip.options & NAND_BUSWIDTH_16)
column >>= 1;
flctl->index += column;
goto read_normal_exit;
case NAND_CMD_READOOB:
if (flctl->hwecc) {
execmd_read_oob(mtd, page_addr);
break;
}
if (flctl->page_size) {
set_cmd_regs(mtd, command, (NAND_CMD_READSTART << 8)
| NAND_CMD_READ0);
set_addr(mtd, mtd->writesize, page_addr);
} else {
set_cmd_regs(mtd, command, command);
set_addr(mtd, 0, page_addr);
}
flctl->read_bytes = mtd->oobsize;
goto read_normal_exit;
case NAND_CMD_RNDOUT:
if (flctl->hwecc)
break;
if (flctl->page_size)
set_cmd_regs(mtd, command, (NAND_CMD_RNDOUTSTART << 8)
| command);
else
set_cmd_regs(mtd, command, command);
set_addr(mtd, column, 0);
flctl->read_bytes = mtd->writesize + mtd->oobsize - column;
goto read_normal_exit;
case NAND_CMD_READID:
set_cmd_regs(mtd, command, command);
if (flctl->chip.options & NAND_BUSWIDTH_16)
column <<= 1;
set_addr(mtd, column, 0);
flctl->read_bytes = 8;
writel(flctl->read_bytes, FLDTCNTR(flctl));
empty_fifo(flctl);
start_translation(flctl);
read_fiforeg(flctl, flctl->read_bytes, 0);
wait_completion(flctl);
break;
case NAND_CMD_ERASE1:
flctl->erase1_page_addr = page_addr;
break;
case NAND_CMD_ERASE2:
set_cmd_regs(mtd, NAND_CMD_ERASE1,
(command << 8) | NAND_CMD_ERASE1);
set_addr(mtd, -1, flctl->erase1_page_addr);
start_translation(flctl);
wait_completion(flctl);
break;
case NAND_CMD_SEQIN:
if (!flctl->page_size) {
if (column >= mtd->writesize) {
column -= mtd->writesize;
read_cmd = NAND_CMD_READOOB;
} else if (column < 256) {
read_cmd = NAND_CMD_READ0;
} else {
column -= 256;
read_cmd = NAND_CMD_READ1;
}
}
flctl->seqin_column = column;
flctl->seqin_page_addr = page_addr;
flctl->seqin_read_cmd = read_cmd;
break;
case NAND_CMD_PAGEPROG:
empty_fifo(flctl);
if (!flctl->page_size) {
set_cmd_regs(mtd, NAND_CMD_SEQIN,
flctl->seqin_read_cmd);
set_addr(mtd, -1, -1);
writel(0, FLDTCNTR(flctl));
start_translation(flctl);
wait_completion(flctl);
}
if (flctl->hwecc) {
if (flctl->seqin_column == mtd->writesize)
execmd_write_oob(mtd);
else if (!flctl->seqin_column)
execmd_write_page_sector(mtd);
else
printk(KERN_ERR "Invalid address !?\n");
break;
}
set_cmd_regs(mtd, command, (command << 8) | NAND_CMD_SEQIN);
set_addr(mtd, flctl->seqin_column, flctl->seqin_page_addr);
writel(flctl->index, FLDTCNTR(flctl));
start_translation(flctl);
write_fiforeg(flctl, flctl->index, 0);
wait_completion(flctl);
break;
case NAND_CMD_STATUS:
set_cmd_regs(mtd, command, command);
set_addr(mtd, -1, -1);
flctl->read_bytes = 1;
writel(flctl->read_bytes, FLDTCNTR(flctl));
start_translation(flctl);
read_datareg(flctl, 0);
break;
case NAND_CMD_RESET:
set_cmd_regs(mtd, command, command);
set_addr(mtd, -1, -1);
writel(0, FLDTCNTR(flctl));
start_translation(flctl);
wait_completion(flctl);
break;
default:
break;
}
goto runtime_exit;
read_normal_exit:
writel(flctl->read_bytes, FLDTCNTR(flctl));
empty_fifo(flctl);
start_translation(flctl);
read_fiforeg(flctl, flctl->read_bytes, 0);
wait_completion(flctl);
runtime_exit:
pm_runtime_put_sync(&flctl->pdev->dev);
return;
}
static void flctl_select_chip(struct mtd_info *mtd, int chipnr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int ret;
switch (chipnr) {
case -1:
flctl->flcmncr_base &= ~CE0_ENABLE;
pm_runtime_get_sync(&flctl->pdev->dev);
writel(flctl->flcmncr_base, FLCMNCR(flctl));
if (flctl->qos_request) {
dev_pm_qos_remove_request(&flctl->pm_qos);
flctl->qos_request = 0;
}
pm_runtime_put_sync(&flctl->pdev->dev);
break;
case 0:
flctl->flcmncr_base |= CE0_ENABLE;
if (!flctl->qos_request) {
ret = dev_pm_qos_add_request(&flctl->pdev->dev,
&flctl->pm_qos,
DEV_PM_QOS_RESUME_LATENCY,
100);
if (ret < 0)
dev_err(&flctl->pdev->dev,
"PM QoS request failed: %d\n", ret);
flctl->qos_request = 1;
}
if (flctl->holden) {
pm_runtime_get_sync(&flctl->pdev->dev);
writel(HOLDEN, FLHOLDCR(flctl));
pm_runtime_put_sync(&flctl->pdev->dev);
}
break;
default:
BUG();
}
}
static void flctl_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
memcpy(&flctl->done_buff[flctl->index], buf, len);
flctl->index += len;
}
static uint8_t flctl_read_byte(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint8_t data;
data = flctl->done_buff[flctl->index];
flctl->index++;
return data;
}
static uint16_t flctl_read_word(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint16_t *buf = (uint16_t *)&flctl->done_buff[flctl->index];
flctl->index += 2;
return *buf;
}
static void flctl_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
memcpy(buf, &flctl->done_buff[flctl->index], len);
flctl->index += len;
}
static int flctl_chip_init_tail(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
struct nand_chip *chip = &flctl->chip;
if (mtd->writesize == 512) {
flctl->page_size = 0;
if (chip->chipsize > (32 << 20)) {
flctl->rw_ADRCNT = ADRCNT_4;
flctl->erase_ADRCNT = ADRCNT_3;
} else if (chip->chipsize > (2 << 16)) {
flctl->rw_ADRCNT = ADRCNT_3;
flctl->erase_ADRCNT = ADRCNT_2;
} else {
flctl->rw_ADRCNT = ADRCNT_2;
flctl->erase_ADRCNT = ADRCNT_1;
}
} else {
flctl->page_size = 1;
if (chip->chipsize > (128 << 20)) {
flctl->rw_ADRCNT = ADRCNT2_E;
flctl->erase_ADRCNT = ADRCNT_3;
} else if (chip->chipsize > (8 << 16)) {
flctl->rw_ADRCNT = ADRCNT_4;
flctl->erase_ADRCNT = ADRCNT_2;
} else {
flctl->rw_ADRCNT = ADRCNT_3;
flctl->erase_ADRCNT = ADRCNT_1;
}
}
if (flctl->hwecc) {
if (mtd->writesize == 512) {
mtd_set_ooblayout(mtd, &flctl_4secc_oob_smallpage_ops);
chip->badblock_pattern = &flctl_4secc_smallpage;
} else {
mtd_set_ooblayout(mtd, &flctl_4secc_oob_largepage_ops);
chip->badblock_pattern = &flctl_4secc_largepage;
}
chip->ecc.size = 512;
chip->ecc.bytes = 10;
chip->ecc.strength = 4;
chip->ecc.read_page = flctl_read_page_hwecc;
chip->ecc.write_page = flctl_write_page_hwecc;
chip->ecc.mode = NAND_ECC_HW;
flctl->flcmncr_base |= _4ECCEN;
} else {
chip->ecc.mode = NAND_ECC_SOFT;
chip->ecc.algo = NAND_ECC_HAMMING;
}
return 0;
}
static irqreturn_t flctl_handle_flste(int irq, void *dev_id)
{
struct sh_flctl *flctl = dev_id;
dev_err(&flctl->pdev->dev, "flste irq: %x\n", readl(FLINTDMACR(flctl)));
writel(flctl->flintdmacr_base, FLINTDMACR(flctl));
return IRQ_HANDLED;
}
static struct sh_flctl_platform_data *flctl_parse_dt(struct device *dev)
{
const struct of_device_id *match;
struct flctl_soc_config *config;
struct sh_flctl_platform_data *pdata;
match = of_match_device(of_flctl_match, dev);
if (match)
config = (struct flctl_soc_config *)match->data;
else {
dev_err(dev, "%s: no OF configuration attached\n", __func__);
return NULL;
}
pdata = devm_kzalloc(dev, sizeof(struct sh_flctl_platform_data),
GFP_KERNEL);
if (!pdata)
return NULL;
pdata->flcmncr_val = config->flcmncr_val;
pdata->has_hwecc = config->has_hwecc;
pdata->use_holden = config->use_holden;
return pdata;
}
static int flctl_probe(struct platform_device *pdev)
{
struct resource *res;
struct sh_flctl *flctl;
struct mtd_info *flctl_mtd;
struct nand_chip *nand;
struct sh_flctl_platform_data *pdata;
int ret;
int irq;
flctl = devm_kzalloc(&pdev->dev, sizeof(struct sh_flctl), GFP_KERNEL);
if (!flctl)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
flctl->reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(flctl->reg))
return PTR_ERR(flctl->reg);
flctl->fifo = res->start + 0x24;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get flste irq data\n");
return -ENXIO;
}
ret = devm_request_irq(&pdev->dev, irq, flctl_handle_flste, IRQF_SHARED,
"flste", flctl);
if (ret) {
dev_err(&pdev->dev, "request interrupt failed.\n");
return ret;
}
if (pdev->dev.of_node)
pdata = flctl_parse_dt(&pdev->dev);
else
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "no setup data defined\n");
return -EINVAL;
}
platform_set_drvdata(pdev, flctl);
nand = &flctl->chip;
flctl_mtd = nand_to_mtd(nand);
nand_set_flash_node(nand, pdev->dev.of_node);
flctl_mtd->dev.parent = &pdev->dev;
flctl->pdev = pdev;
flctl->hwecc = pdata->has_hwecc;
flctl->holden = pdata->use_holden;
flctl->flcmncr_base = pdata->flcmncr_val;
flctl->flintdmacr_base = flctl->hwecc ? (STERINTE | ECERB) : STERINTE;
nand->chip_delay = 20;
nand->read_byte = flctl_read_byte;
nand->read_word = flctl_read_word;
nand->write_buf = flctl_write_buf;
nand->read_buf = flctl_read_buf;
nand->select_chip = flctl_select_chip;
nand->cmdfunc = flctl_cmdfunc;
if (pdata->flcmncr_val & SEL_16BIT)
nand->options |= NAND_BUSWIDTH_16;
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
flctl_setup_dma(flctl);
ret = nand_scan_ident(flctl_mtd, 1, NULL);
if (ret)
goto err_chip;
if (nand->options & NAND_BUSWIDTH_16) {
pdata->flcmncr_val |= SEL_16BIT;
flctl->flcmncr_base = pdata->flcmncr_val;
}
ret = flctl_chip_init_tail(flctl_mtd);
if (ret)
goto err_chip;
ret = nand_scan_tail(flctl_mtd);
if (ret)
goto err_chip;
ret = mtd_device_register(flctl_mtd, pdata->parts, pdata->nr_parts);
return 0;
err_chip:
flctl_release_dma(flctl);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int flctl_remove(struct platform_device *pdev)
{
struct sh_flctl *flctl = platform_get_drvdata(pdev);
flctl_release_dma(flctl);
nand_release(nand_to_mtd(&flctl->chip));
pm_runtime_disable(&pdev->dev);
return 0;
}
