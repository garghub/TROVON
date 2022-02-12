static inline struct sunxi_nand_chip *to_sunxi_nand(struct nand_chip *nand)
{
return container_of(nand, struct sunxi_nand_chip, nand);
}
static inline struct sunxi_nfc *to_sunxi_nfc(struct nand_hw_control *ctrl)
{
return container_of(ctrl, struct sunxi_nfc, controller);
}
static irqreturn_t sunxi_nfc_interrupt(int irq, void *dev_id)
{
struct sunxi_nfc *nfc = dev_id;
u32 st = readl(nfc->regs + NFC_REG_ST);
u32 ien = readl(nfc->regs + NFC_REG_INT);
if (!(ien & st))
return IRQ_NONE;
if ((ien & st) == ien)
complete(&nfc->complete);
writel(st & NFC_INT_MASK, nfc->regs + NFC_REG_ST);
writel(~st & ien & NFC_INT_MASK, nfc->regs + NFC_REG_INT);
return IRQ_HANDLED;
}
static int sunxi_nfc_wait_events(struct sunxi_nfc *nfc, u32 events,
bool use_polling, unsigned int timeout_ms)
{
int ret;
if (events & ~NFC_INT_MASK)
return -EINVAL;
if (!timeout_ms)
timeout_ms = NFC_DEFAULT_TIMEOUT_MS;
if (!use_polling) {
init_completion(&nfc->complete);
writel(events, nfc->regs + NFC_REG_INT);
ret = wait_for_completion_timeout(&nfc->complete,
msecs_to_jiffies(timeout_ms));
writel(0, nfc->regs + NFC_REG_INT);
} else {
u32 status;
ret = readl_poll_timeout(nfc->regs + NFC_REG_ST, status,
(status & events) == events, 1,
timeout_ms * 1000);
}
writel(events & NFC_INT_MASK, nfc->regs + NFC_REG_ST);
if (ret)
dev_err(nfc->dev, "wait interrupt timedout\n");
return ret;
}
static int sunxi_nfc_wait_cmd_fifo_empty(struct sunxi_nfc *nfc)
{
u32 status;
int ret;
ret = readl_poll_timeout(nfc->regs + NFC_REG_ST, status,
!(status & NFC_CMD_FIFO_STATUS), 1,
NFC_DEFAULT_TIMEOUT_MS * 1000);
if (ret)
dev_err(nfc->dev, "wait for empty cmd FIFO timedout\n");
return ret;
}
static int sunxi_nfc_rst(struct sunxi_nfc *nfc)
{
u32 ctl;
int ret;
writel(0, nfc->regs + NFC_REG_ECC_CTL);
writel(NFC_RESET, nfc->regs + NFC_REG_CTL);
ret = readl_poll_timeout(nfc->regs + NFC_REG_CTL, ctl,
!(ctl & NFC_RESET), 1,
NFC_DEFAULT_TIMEOUT_MS * 1000);
if (ret)
dev_err(nfc->dev, "wait for NAND controller reset timedout\n");
return ret;
}
static int sunxi_nfc_dma_op_prepare(struct mtd_info *mtd, const void *buf,
int chunksize, int nchunks,
enum dma_data_direction ddir,
struct scatterlist *sg)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct dma_async_tx_descriptor *dmad;
enum dma_transfer_direction tdir;
dma_cookie_t dmat;
int ret;
if (ddir == DMA_FROM_DEVICE)
tdir = DMA_DEV_TO_MEM;
else
tdir = DMA_MEM_TO_DEV;
sg_init_one(sg, buf, nchunks * chunksize);
ret = dma_map_sg(nfc->dev, sg, 1, ddir);
if (!ret)
return -ENOMEM;
dmad = dmaengine_prep_slave_sg(nfc->dmac, sg, 1, tdir, DMA_CTRL_ACK);
if (!dmad) {
ret = -EINVAL;
goto err_unmap_buf;
}
writel(readl(nfc->regs + NFC_REG_CTL) | NFC_RAM_METHOD,
nfc->regs + NFC_REG_CTL);
writel(nchunks, nfc->regs + NFC_REG_SECTOR_NUM);
writel(chunksize, nfc->regs + NFC_REG_CNT);
dmat = dmaengine_submit(dmad);
ret = dma_submit_error(dmat);
if (ret)
goto err_clr_dma_flag;
return 0;
err_clr_dma_flag:
writel(readl(nfc->regs + NFC_REG_CTL) & ~NFC_RAM_METHOD,
nfc->regs + NFC_REG_CTL);
err_unmap_buf:
dma_unmap_sg(nfc->dev, sg, 1, ddir);
return ret;
}
static void sunxi_nfc_dma_op_cleanup(struct mtd_info *mtd,
enum dma_data_direction ddir,
struct scatterlist *sg)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
dma_unmap_sg(nfc->dev, sg, 1, ddir);
writel(readl(nfc->regs + NFC_REG_CTL) & ~NFC_RAM_METHOD,
nfc->regs + NFC_REG_CTL);
}
static int sunxi_nfc_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
struct sunxi_nand_rb *rb;
int ret;
if (sunxi_nand->selected < 0)
return 0;
rb = &sunxi_nand->sels[sunxi_nand->selected].rb;
switch (rb->type) {
case RB_NATIVE:
ret = !!(readl(nfc->regs + NFC_REG_ST) &
NFC_RB_STATE(rb->info.nativeid));
break;
case RB_GPIO:
ret = gpio_get_value(rb->info.gpio);
break;
case RB_NONE:
default:
ret = 0;
dev_err(nfc->dev, "cannot check R/B NAND status!\n");
break;
}
return ret;
}
static void sunxi_nfc_select_chip(struct mtd_info *mtd, int chip)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
struct sunxi_nand_chip_sel *sel;
u32 ctl;
if (chip > 0 && chip >= sunxi_nand->nsels)
return;
if (chip == sunxi_nand->selected)
return;
ctl = readl(nfc->regs + NFC_REG_CTL) &
~(NFC_PAGE_SHIFT_MSK | NFC_CE_SEL_MSK | NFC_RB_SEL_MSK | NFC_EN);
if (chip >= 0) {
sel = &sunxi_nand->sels[chip];
ctl |= NFC_CE_SEL(sel->cs) | NFC_EN |
NFC_PAGE_SHIFT(nand->page_shift);
if (sel->rb.type == RB_NONE) {
nand->dev_ready = NULL;
} else {
nand->dev_ready = sunxi_nfc_dev_ready;
if (sel->rb.type == RB_NATIVE)
ctl |= NFC_RB_SEL(sel->rb.info.nativeid);
}
writel(mtd->writesize, nfc->regs + NFC_REG_SPARE_AREA);
if (nfc->clk_rate != sunxi_nand->clk_rate) {
clk_set_rate(nfc->mod_clk, sunxi_nand->clk_rate);
nfc->clk_rate = sunxi_nand->clk_rate;
}
}
writel(sunxi_nand->timing_ctl, nfc->regs + NFC_REG_TIMING_CTL);
writel(sunxi_nand->timing_cfg, nfc->regs + NFC_REG_TIMING_CFG);
writel(ctl, nfc->regs + NFC_REG_CTL);
sunxi_nand->selected = chip;
}
static void sunxi_nfc_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
int ret;
int cnt;
int offs = 0;
u32 tmp;
while (len > offs) {
cnt = min(len - offs, NFC_SRAM_SIZE);
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
break;
writel(cnt, nfc->regs + NFC_REG_CNT);
tmp = NFC_DATA_TRANS | NFC_DATA_SWAP_METHOD;
writel(tmp, nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
if (ret)
break;
if (buf)
memcpy_fromio(buf + offs, nfc->regs + NFC_RAM0_BASE,
cnt);
offs += cnt;
}
}
static void sunxi_nfc_write_buf(struct mtd_info *mtd, const uint8_t *buf,
int len)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
int ret;
int cnt;
int offs = 0;
u32 tmp;
while (len > offs) {
cnt = min(len - offs, NFC_SRAM_SIZE);
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
break;
writel(cnt, nfc->regs + NFC_REG_CNT);
memcpy_toio(nfc->regs + NFC_RAM0_BASE, buf + offs, cnt);
tmp = NFC_DATA_TRANS | NFC_DATA_SWAP_METHOD |
NFC_ACCESS_DIR;
writel(tmp, nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
if (ret)
break;
offs += cnt;
}
}
static uint8_t sunxi_nfc_read_byte(struct mtd_info *mtd)
{
uint8_t ret;
sunxi_nfc_read_buf(mtd, &ret, 1);
return ret;
}
static void sunxi_nfc_cmd_ctrl(struct mtd_info *mtd, int dat,
unsigned int ctrl)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
int ret;
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return;
if (dat == NAND_CMD_NONE && (ctrl & NAND_NCE) &&
!(ctrl & (NAND_CLE | NAND_ALE))) {
u32 cmd = 0;
if (!sunxi_nand->addr_cycles && !sunxi_nand->cmd_cycles)
return;
if (sunxi_nand->cmd_cycles--)
cmd |= NFC_SEND_CMD1 | sunxi_nand->cmd[0];
if (sunxi_nand->cmd_cycles--) {
cmd |= NFC_SEND_CMD2;
writel(sunxi_nand->cmd[1],
nfc->regs + NFC_REG_RCMD_SET);
}
sunxi_nand->cmd_cycles = 0;
if (sunxi_nand->addr_cycles) {
cmd |= NFC_SEND_ADR |
NFC_ADR_NUM(sunxi_nand->addr_cycles);
writel(sunxi_nand->addr[0],
nfc->regs + NFC_REG_ADDR_LOW);
}
if (sunxi_nand->addr_cycles > 4)
writel(sunxi_nand->addr[1],
nfc->regs + NFC_REG_ADDR_HIGH);
writel(cmd, nfc->regs + NFC_REG_CMD);
sunxi_nand->addr[0] = 0;
sunxi_nand->addr[1] = 0;
sunxi_nand->addr_cycles = 0;
sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
}
if (ctrl & NAND_CLE) {
sunxi_nand->cmd[sunxi_nand->cmd_cycles++] = dat;
} else if (ctrl & NAND_ALE) {
sunxi_nand->addr[sunxi_nand->addr_cycles / 4] |=
dat << ((sunxi_nand->addr_cycles % 4) * 8);
sunxi_nand->addr_cycles++;
}
}
static u16 sunxi_nfc_randomizer_step(u16 state, int count)
{
state &= 0x7fff;
while (count--)
state = ((state >> 1) |
(((state ^ (state >> 1)) & 1) << 14)) & 0x7fff;
return state;
}
static u16 sunxi_nfc_randomizer_state(struct mtd_info *mtd, int page, bool ecc)
{
const u16 *seeds = sunxi_nfc_randomizer_page_seeds;
int mod = mtd_div_by_ws(mtd->erasesize, mtd);
if (mod > ARRAY_SIZE(sunxi_nfc_randomizer_page_seeds))
mod = ARRAY_SIZE(sunxi_nfc_randomizer_page_seeds);
if (ecc) {
if (mtd->ecc_step_size == 512)
seeds = sunxi_nfc_randomizer_ecc512_seeds;
else
seeds = sunxi_nfc_randomizer_ecc1024_seeds;
}
return seeds[page % mod];
}
static void sunxi_nfc_randomizer_config(struct mtd_info *mtd,
int page, bool ecc)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
u32 ecc_ctl = readl(nfc->regs + NFC_REG_ECC_CTL);
u16 state;
if (!(nand->options & NAND_NEED_SCRAMBLING))
return;
ecc_ctl = readl(nfc->regs + NFC_REG_ECC_CTL);
state = sunxi_nfc_randomizer_state(mtd, page, ecc);
ecc_ctl = readl(nfc->regs + NFC_REG_ECC_CTL) & ~NFC_RANDOM_SEED_MSK;
writel(ecc_ctl | NFC_RANDOM_SEED(state), nfc->regs + NFC_REG_ECC_CTL);
}
static void sunxi_nfc_randomizer_enable(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
if (!(nand->options & NAND_NEED_SCRAMBLING))
return;
writel(readl(nfc->regs + NFC_REG_ECC_CTL) | NFC_RANDOM_EN,
nfc->regs + NFC_REG_ECC_CTL);
}
static void sunxi_nfc_randomizer_disable(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
if (!(nand->options & NAND_NEED_SCRAMBLING))
return;
writel(readl(nfc->regs + NFC_REG_ECC_CTL) & ~NFC_RANDOM_EN,
nfc->regs + NFC_REG_ECC_CTL);
}
static void sunxi_nfc_randomize_bbm(struct mtd_info *mtd, int page, u8 *bbm)
{
u16 state = sunxi_nfc_randomizer_state(mtd, page, true);
bbm[0] ^= state;
bbm[1] ^= sunxi_nfc_randomizer_step(state, 8);
}
static void sunxi_nfc_randomizer_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len,
bool ecc, int page)
{
sunxi_nfc_randomizer_config(mtd, page, ecc);
sunxi_nfc_randomizer_enable(mtd);
sunxi_nfc_write_buf(mtd, buf, len);
sunxi_nfc_randomizer_disable(mtd);
}
static void sunxi_nfc_randomizer_read_buf(struct mtd_info *mtd, uint8_t *buf,
int len, bool ecc, int page)
{
sunxi_nfc_randomizer_config(mtd, page, ecc);
sunxi_nfc_randomizer_enable(mtd);
sunxi_nfc_read_buf(mtd, buf, len);
sunxi_nfc_randomizer_disable(mtd);
}
static void sunxi_nfc_hw_ecc_enable(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct sunxi_nand_hw_ecc *data = nand->ecc.priv;
u32 ecc_ctl;
ecc_ctl = readl(nfc->regs + NFC_REG_ECC_CTL);
ecc_ctl &= ~(NFC_ECC_MODE_MSK | NFC_ECC_PIPELINE |
NFC_ECC_BLOCK_SIZE_MSK);
ecc_ctl |= NFC_ECC_EN | NFC_ECC_MODE(data->mode) | NFC_ECC_EXCEPTION |
NFC_ECC_PIPELINE;
writel(ecc_ctl, nfc->regs + NFC_REG_ECC_CTL);
}
static void sunxi_nfc_hw_ecc_disable(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
writel(readl(nfc->regs + NFC_REG_ECC_CTL) & ~NFC_ECC_EN,
nfc->regs + NFC_REG_ECC_CTL);
}
static inline void sunxi_nfc_user_data_to_buf(u32 user_data, u8 *buf)
{
buf[0] = user_data;
buf[1] = user_data >> 8;
buf[2] = user_data >> 16;
buf[3] = user_data >> 24;
}
static inline u32 sunxi_nfc_buf_to_user_data(const u8 *buf)
{
return buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
}
static void sunxi_nfc_hw_ecc_get_prot_oob_bytes(struct mtd_info *mtd, u8 *oob,
int step, bool bbm, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
sunxi_nfc_user_data_to_buf(readl(nfc->regs + NFC_REG_USER_DATA(step)),
oob);
if (bbm && (nand->options & NAND_NEED_SCRAMBLING))
sunxi_nfc_randomize_bbm(mtd, page, oob);
}
static void sunxi_nfc_hw_ecc_set_prot_oob_bytes(struct mtd_info *mtd,
const u8 *oob, int step,
bool bbm, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
u8 user_data[4];
if (bbm && (nand->options & NAND_NEED_SCRAMBLING)) {
memcpy(user_data, oob, sizeof(user_data));
sunxi_nfc_randomize_bbm(mtd, page, user_data);
oob = user_data;
}
writel(sunxi_nfc_buf_to_user_data(oob),
nfc->regs + NFC_REG_USER_DATA(step));
}
static void sunxi_nfc_hw_ecc_update_stats(struct mtd_info *mtd,
unsigned int *max_bitflips, int ret)
{
if (ret < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += ret;
*max_bitflips = max_t(unsigned int, *max_bitflips, ret);
}
}
static int sunxi_nfc_hw_ecc_correct(struct mtd_info *mtd, u8 *data, u8 *oob,
int step, u32 status, bool *erased)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct nand_ecc_ctrl *ecc = &nand->ecc;
u32 tmp;
*erased = false;
if (status & NFC_ECC_ERR(step))
return -EBADMSG;
if (status & NFC_ECC_PAT_FOUND(step)) {
u8 pattern;
if (unlikely(!(readl(nfc->regs + NFC_REG_PAT_ID) & 0x1))) {
pattern = 0x0;
} else {
pattern = 0xff;
*erased = true;
}
if (data)
memset(data, pattern, ecc->size);
if (oob)
memset(oob, pattern, ecc->bytes + 4);
return 0;
}
tmp = readl(nfc->regs + NFC_REG_ECC_ERR_CNT(step));
return NFC_ECC_ERR_CNT(step, tmp);
}
static int sunxi_nfc_hw_ecc_read_chunk(struct mtd_info *mtd,
u8 *data, int data_off,
u8 *oob, int oob_off,
int *cur_off,
unsigned int *max_bitflips,
bool bbm, bool oob_required, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct nand_ecc_ctrl *ecc = &nand->ecc;
int raw_mode = 0;
bool erased;
int ret;
if (*cur_off != data_off)
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, data_off, -1);
sunxi_nfc_randomizer_read_buf(mtd, NULL, ecc->size, false, page);
if (data_off + ecc->size != oob_off)
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, oob_off, -1);
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return ret;
sunxi_nfc_randomizer_enable(mtd);
writel(NFC_DATA_TRANS | NFC_DATA_SWAP_METHOD | NFC_ECC_OP,
nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
sunxi_nfc_randomizer_disable(mtd);
if (ret)
return ret;
*cur_off = oob_off + ecc->bytes + 4;
ret = sunxi_nfc_hw_ecc_correct(mtd, data, oob_required ? oob : NULL, 0,
readl(nfc->regs + NFC_REG_ECC_ST),
&erased);
if (erased)
return 1;
if (ret < 0) {
if (nand->options & NAND_NEED_SCRAMBLING) {
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, data_off, -1);
nand->read_buf(mtd, data, ecc->size);
} else {
memcpy_fromio(data, nfc->regs + NFC_RAM0_BASE,
ecc->size);
}
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, oob_off, -1);
nand->read_buf(mtd, oob, ecc->bytes + 4);
ret = nand_check_erased_ecc_chunk(data, ecc->size,
oob, ecc->bytes + 4,
NULL, 0, ecc->strength);
if (ret >= 0)
raw_mode = 1;
} else {
memcpy_fromio(data, nfc->regs + NFC_RAM0_BASE, ecc->size);
if (oob_required) {
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, oob_off, -1);
sunxi_nfc_randomizer_read_buf(mtd, oob, ecc->bytes + 4,
true, page);
sunxi_nfc_hw_ecc_get_prot_oob_bytes(mtd, oob, 0,
bbm, page);
}
}
sunxi_nfc_hw_ecc_update_stats(mtd, max_bitflips, ret);
return raw_mode;
}
static void sunxi_nfc_hw_ecc_read_extra_oob(struct mtd_info *mtd,
u8 *oob, int *cur_off,
bool randomize, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &nand->ecc;
int offset = ((ecc->bytes + 4) * ecc->steps);
int len = mtd->oobsize - offset;
if (len <= 0)
return;
if (!cur_off || *cur_off != offset)
nand->cmdfunc(mtd, NAND_CMD_RNDOUT,
offset + mtd->writesize, -1);
if (!randomize)
sunxi_nfc_read_buf(mtd, oob + offset, len);
else
sunxi_nfc_randomizer_read_buf(mtd, oob + offset, len,
false, page);
if (cur_off)
*cur_off = mtd->oobsize + mtd->writesize;
}
static int sunxi_nfc_hw_ecc_read_chunks_dma(struct mtd_info *mtd, uint8_t *buf,
int oob_required, int page,
int nchunks)
{
struct nand_chip *nand = mtd_to_nand(mtd);
bool randomized = nand->options & NAND_NEED_SCRAMBLING;
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct nand_ecc_ctrl *ecc = &nand->ecc;
unsigned int max_bitflips = 0;
int ret, i, raw_mode = 0;
struct scatterlist sg;
u32 status;
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return ret;
ret = sunxi_nfc_dma_op_prepare(mtd, buf, ecc->size, nchunks,
DMA_FROM_DEVICE, &sg);
if (ret)
return ret;
sunxi_nfc_hw_ecc_enable(mtd);
sunxi_nfc_randomizer_config(mtd, page, false);
sunxi_nfc_randomizer_enable(mtd);
writel((NAND_CMD_RNDOUTSTART << 16) | (NAND_CMD_RNDOUT << 8) |
NAND_CMD_READSTART, nfc->regs + NFC_REG_RCMD_SET);
dma_async_issue_pending(nfc->dmac);
writel(NFC_PAGE_OP | NFC_DATA_SWAP_METHOD | NFC_DATA_TRANS,
nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
if (ret)
dmaengine_terminate_all(nfc->dmac);
sunxi_nfc_randomizer_disable(mtd);
sunxi_nfc_hw_ecc_disable(mtd);
sunxi_nfc_dma_op_cleanup(mtd, DMA_FROM_DEVICE, &sg);
if (ret)
return ret;
status = readl(nfc->regs + NFC_REG_ECC_ST);
for (i = 0; i < nchunks; i++) {
int data_off = i * ecc->size;
int oob_off = i * (ecc->bytes + 4);
u8 *data = buf + data_off;
u8 *oob = nand->oob_poi + oob_off;
bool erased;
ret = sunxi_nfc_hw_ecc_correct(mtd, randomized ? data : NULL,
oob_required ? oob : NULL,
i, status, &erased);
if (ret < 0)
continue;
if (oob_required && !erased) {
nand->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + oob_off, -1);
nand->read_buf(mtd, oob, ecc->bytes + 4);
sunxi_nfc_hw_ecc_get_prot_oob_bytes(mtd, oob, i,
!i, page);
}
if (erased)
raw_mode = 1;
sunxi_nfc_hw_ecc_update_stats(mtd, &max_bitflips, ret);
}
if (status & NFC_ECC_ERR_MSK) {
for (i = 0; i < nchunks; i++) {
int data_off = i * ecc->size;
int oob_off = i * (ecc->bytes + 4);
u8 *data = buf + data_off;
u8 *oob = nand->oob_poi + oob_off;
if (!(status & NFC_ECC_ERR(i)))
continue;
if (randomized) {
nand->cmdfunc(mtd, NAND_CMD_RNDOUT,
data_off, -1);
nand->read_buf(mtd, data, ecc->size);
}
nand->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + oob_off, -1);
nand->read_buf(mtd, oob, ecc->bytes + 4);
ret = nand_check_erased_ecc_chunk(data, ecc->size,
oob, ecc->bytes + 4,
NULL, 0,
ecc->strength);
if (ret >= 0)
raw_mode = 1;
sunxi_nfc_hw_ecc_update_stats(mtd, &max_bitflips, ret);
}
}
if (oob_required)
sunxi_nfc_hw_ecc_read_extra_oob(mtd, nand->oob_poi,
NULL, !raw_mode,
page);
return max_bitflips;
}
static int sunxi_nfc_hw_ecc_write_chunk(struct mtd_info *mtd,
const u8 *data, int data_off,
const u8 *oob, int oob_off,
int *cur_off, bool bbm,
int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct nand_ecc_ctrl *ecc = &nand->ecc;
int ret;
if (data_off != *cur_off)
nand->cmdfunc(mtd, NAND_CMD_RNDIN, data_off, -1);
sunxi_nfc_randomizer_write_buf(mtd, data, ecc->size, false, page);
if (data_off + ecc->size != oob_off)
nand->cmdfunc(mtd, NAND_CMD_RNDIN, oob_off, -1);
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return ret;
sunxi_nfc_randomizer_enable(mtd);
sunxi_nfc_hw_ecc_set_prot_oob_bytes(mtd, oob, 0, bbm, page);
writel(NFC_DATA_TRANS | NFC_DATA_SWAP_METHOD |
NFC_ACCESS_DIR | NFC_ECC_OP,
nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
sunxi_nfc_randomizer_disable(mtd);
if (ret)
return ret;
*cur_off = oob_off + ecc->bytes + 4;
return 0;
}
static void sunxi_nfc_hw_ecc_write_extra_oob(struct mtd_info *mtd,
u8 *oob, int *cur_off,
int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &nand->ecc;
int offset = ((ecc->bytes + 4) * ecc->steps);
int len = mtd->oobsize - offset;
if (len <= 0)
return;
if (!cur_off || *cur_off != offset)
nand->cmdfunc(mtd, NAND_CMD_RNDIN,
offset + mtd->writesize, -1);
sunxi_nfc_randomizer_write_buf(mtd, oob + offset, len, false, page);
if (cur_off)
*cur_off = mtd->oobsize + mtd->writesize;
}
static int sunxi_nfc_hw_ecc_read_page(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf,
int oob_required, int page)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
unsigned int max_bitflips = 0;
int ret, i, cur_off = 0;
bool raw_mode = false;
sunxi_nfc_hw_ecc_enable(mtd);
for (i = 0; i < ecc->steps; i++) {
int data_off = i * ecc->size;
int oob_off = i * (ecc->bytes + 4);
u8 *data = buf + data_off;
u8 *oob = chip->oob_poi + oob_off;
ret = sunxi_nfc_hw_ecc_read_chunk(mtd, data, data_off, oob,
oob_off + mtd->writesize,
&cur_off, &max_bitflips,
!i, oob_required, page);
if (ret < 0)
return ret;
else if (ret)
raw_mode = true;
}
if (oob_required)
sunxi_nfc_hw_ecc_read_extra_oob(mtd, chip->oob_poi, &cur_off,
!raw_mode, page);
sunxi_nfc_hw_ecc_disable(mtd);
return max_bitflips;
}
static int sunxi_nfc_hw_ecc_read_page_dma(struct mtd_info *mtd,
struct nand_chip *chip, u8 *buf,
int oob_required, int page)
{
int ret;
ret = sunxi_nfc_hw_ecc_read_chunks_dma(mtd, buf, oob_required, page,
chip->ecc.steps);
if (ret >= 0)
return ret;
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, 0, -1);
return sunxi_nfc_hw_ecc_read_page(mtd, chip, buf, oob_required, page);
}
static int sunxi_nfc_hw_ecc_read_subpage(struct mtd_info *mtd,
struct nand_chip *chip,
u32 data_offs, u32 readlen,
u8 *bufpoi, int page)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
int ret, i, cur_off = 0;
unsigned int max_bitflips = 0;
sunxi_nfc_hw_ecc_enable(mtd);
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
for (i = data_offs / ecc->size;
i < DIV_ROUND_UP(data_offs + readlen, ecc->size); i++) {
int data_off = i * ecc->size;
int oob_off = i * (ecc->bytes + 4);
u8 *data = bufpoi + data_off;
u8 *oob = chip->oob_poi + oob_off;
ret = sunxi_nfc_hw_ecc_read_chunk(mtd, data, data_off,
oob,
oob_off + mtd->writesize,
&cur_off, &max_bitflips, !i,
false, page);
if (ret < 0)
return ret;
}
sunxi_nfc_hw_ecc_disable(mtd);
return max_bitflips;
}
static int sunxi_nfc_hw_ecc_read_subpage_dma(struct mtd_info *mtd,
struct nand_chip *chip,
u32 data_offs, u32 readlen,
u8 *buf, int page)
{
int nchunks = DIV_ROUND_UP(data_offs + readlen, chip->ecc.size);
int ret;
ret = sunxi_nfc_hw_ecc_read_chunks_dma(mtd, buf, false, page, nchunks);
if (ret >= 0)
return ret;
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, 0, -1);
return sunxi_nfc_hw_ecc_read_subpage(mtd, chip, data_offs, readlen,
buf, page);
}
static int sunxi_nfc_hw_ecc_write_page(struct mtd_info *mtd,
struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
int ret, i, cur_off = 0;
sunxi_nfc_hw_ecc_enable(mtd);
for (i = 0; i < ecc->steps; i++) {
int data_off = i * ecc->size;
int oob_off = i * (ecc->bytes + 4);
const u8 *data = buf + data_off;
const u8 *oob = chip->oob_poi + oob_off;
ret = sunxi_nfc_hw_ecc_write_chunk(mtd, data, data_off, oob,
oob_off + mtd->writesize,
&cur_off, !i, page);
if (ret)
return ret;
}
if (oob_required || (chip->options & NAND_NEED_SCRAMBLING))
sunxi_nfc_hw_ecc_write_extra_oob(mtd, chip->oob_poi,
&cur_off, page);
sunxi_nfc_hw_ecc_disable(mtd);
return 0;
}
static int sunxi_nfc_hw_ecc_write_subpage(struct mtd_info *mtd,
struct nand_chip *chip,
u32 data_offs, u32 data_len,
const u8 *buf, int oob_required,
int page)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
int ret, i, cur_off = 0;
sunxi_nfc_hw_ecc_enable(mtd);
for (i = data_offs / ecc->size;
i < DIV_ROUND_UP(data_offs + data_len, ecc->size); i++) {
int data_off = i * ecc->size;
int oob_off = i * (ecc->bytes + 4);
const u8 *data = buf + data_off;
const u8 *oob = chip->oob_poi + oob_off;
ret = sunxi_nfc_hw_ecc_write_chunk(mtd, data, data_off, oob,
oob_off + mtd->writesize,
&cur_off, !i, page);
if (ret)
return ret;
}
sunxi_nfc_hw_ecc_disable(mtd);
return 0;
}
static int sunxi_nfc_hw_ecc_write_page_dma(struct mtd_info *mtd,
struct nand_chip *chip,
const u8 *buf,
int oob_required,
int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct nand_ecc_ctrl *ecc = &nand->ecc;
struct scatterlist sg;
int ret, i;
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return ret;
ret = sunxi_nfc_dma_op_prepare(mtd, buf, ecc->size, ecc->steps,
DMA_TO_DEVICE, &sg);
if (ret)
goto pio_fallback;
for (i = 0; i < ecc->steps; i++) {
const u8 *oob = nand->oob_poi + (i * (ecc->bytes + 4));
sunxi_nfc_hw_ecc_set_prot_oob_bytes(mtd, oob, i, !i, page);
}
sunxi_nfc_hw_ecc_enable(mtd);
sunxi_nfc_randomizer_config(mtd, page, false);
sunxi_nfc_randomizer_enable(mtd);
writel((NAND_CMD_RNDIN << 8) | NAND_CMD_PAGEPROG,
nfc->regs + NFC_REG_RCMD_SET);
dma_async_issue_pending(nfc->dmac);
writel(NFC_PAGE_OP | NFC_DATA_SWAP_METHOD |
NFC_DATA_TRANS | NFC_ACCESS_DIR,
nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_events(nfc, NFC_CMD_INT_FLAG, true, 0);
if (ret)
dmaengine_terminate_all(nfc->dmac);
sunxi_nfc_randomizer_disable(mtd);
sunxi_nfc_hw_ecc_disable(mtd);
sunxi_nfc_dma_op_cleanup(mtd, DMA_TO_DEVICE, &sg);
if (ret)
return ret;
if (oob_required || (chip->options & NAND_NEED_SCRAMBLING))
sunxi_nfc_hw_ecc_write_extra_oob(mtd, chip->oob_poi,
NULL, page);
return 0;
pio_fallback:
return sunxi_nfc_hw_ecc_write_page(mtd, chip, buf, oob_required, page);
}
static int sunxi_nfc_hw_syndrome_ecc_read_page(struct mtd_info *mtd,
struct nand_chip *chip,
uint8_t *buf, int oob_required,
int page)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
unsigned int max_bitflips = 0;
int ret, i, cur_off = 0;
bool raw_mode = false;
sunxi_nfc_hw_ecc_enable(mtd);
for (i = 0; i < ecc->steps; i++) {
int data_off = i * (ecc->size + ecc->bytes + 4);
int oob_off = data_off + ecc->size;
u8 *data = buf + (i * ecc->size);
u8 *oob = chip->oob_poi + (i * (ecc->bytes + 4));
ret = sunxi_nfc_hw_ecc_read_chunk(mtd, data, data_off, oob,
oob_off, &cur_off,
&max_bitflips, !i,
oob_required,
page);
if (ret < 0)
return ret;
else if (ret)
raw_mode = true;
}
if (oob_required)
sunxi_nfc_hw_ecc_read_extra_oob(mtd, chip->oob_poi, &cur_off,
!raw_mode, page);
sunxi_nfc_hw_ecc_disable(mtd);
return max_bitflips;
}
static int sunxi_nfc_hw_syndrome_ecc_write_page(struct mtd_info *mtd,
struct nand_chip *chip,
const uint8_t *buf,
int oob_required, int page)
{
struct nand_ecc_ctrl *ecc = &chip->ecc;
int ret, i, cur_off = 0;
sunxi_nfc_hw_ecc_enable(mtd);
for (i = 0; i < ecc->steps; i++) {
int data_off = i * (ecc->size + ecc->bytes + 4);
int oob_off = data_off + ecc->size;
const u8 *data = buf + (i * ecc->size);
const u8 *oob = chip->oob_poi + (i * (ecc->bytes + 4));
ret = sunxi_nfc_hw_ecc_write_chunk(mtd, data, data_off,
oob, oob_off, &cur_off,
false, page);
if (ret)
return ret;
}
if (oob_required || (chip->options & NAND_NEED_SCRAMBLING))
sunxi_nfc_hw_ecc_write_extra_oob(mtd, chip->oob_poi,
&cur_off, page);
sunxi_nfc_hw_ecc_disable(mtd);
return 0;
}
static int sunxi_nfc_hw_common_ecc_read_oob(struct mtd_info *mtd,
struct nand_chip *chip,
int page)
{
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
chip->pagebuf = -1;
return chip->ecc.read_page(mtd, chip, chip->buffers->databuf, 1, page);
}
static int sunxi_nfc_hw_common_ecc_write_oob(struct mtd_info *mtd,
struct nand_chip *chip,
int page)
{
int ret, status;
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0, page);
chip->pagebuf = -1;
memset(chip->buffers->databuf, 0xff, mtd->writesize);
ret = chip->ecc.write_page(mtd, chip, chip->buffers->databuf, 1, page);
if (ret)
return ret;
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
static int _sunxi_nand_lookup_timing(const s32 *lut, int lut_size, u32 duration,
u32 clk_period)
{
u32 clk_cycles = DIV_ROUND_UP(duration, clk_period);
int i;
for (i = 0; i < lut_size; i++) {
if (clk_cycles <= lut[i])
return i;
}
return -EINVAL;
}
static int sunxi_nand_chip_set_timings(struct sunxi_nand_chip *chip,
const struct nand_sdr_timings *timings)
{
struct sunxi_nfc *nfc = to_sunxi_nfc(chip->nand.controller);
u32 min_clk_period = 0;
s32 tWB, tADL, tWHR, tRHW, tCAD;
long real_clk_rate;
if (timings->tCLS_min > min_clk_period)
min_clk_period = timings->tCLS_min;
if (timings->tCLH_min > min_clk_period)
min_clk_period = timings->tCLH_min;
if (timings->tCS_min > min_clk_period)
min_clk_period = timings->tCS_min;
if (timings->tCH_min > min_clk_period)
min_clk_period = timings->tCH_min;
if (timings->tWP_min > min_clk_period)
min_clk_period = timings->tWP_min;
if (timings->tWH_min > min_clk_period)
min_clk_period = timings->tWH_min;
if (timings->tALS_min > min_clk_period)
min_clk_period = timings->tALS_min;
if (timings->tDS_min > min_clk_period)
min_clk_period = timings->tDS_min;
if (timings->tDH_min > min_clk_period)
min_clk_period = timings->tDH_min;
if (timings->tRR_min > (min_clk_period * 3))
min_clk_period = DIV_ROUND_UP(timings->tRR_min, 3);
if (timings->tALH_min > min_clk_period)
min_clk_period = timings->tALH_min;
if (timings->tRP_min > min_clk_period)
min_clk_period = timings->tRP_min;
if (timings->tREH_min > min_clk_period)
min_clk_period = timings->tREH_min;
if (timings->tRC_min > (min_clk_period * 2))
min_clk_period = DIV_ROUND_UP(timings->tRC_min, 2);
if (timings->tWC_min > (min_clk_period * 2))
min_clk_period = DIV_ROUND_UP(timings->tWC_min, 2);
if (timings->tWB_max > (min_clk_period * 20))
min_clk_period = DIV_ROUND_UP(timings->tWB_max, 20);
if (timings->tADL_min > (min_clk_period * 32))
min_clk_period = DIV_ROUND_UP(timings->tADL_min, 32);
if (timings->tWHR_min > (min_clk_period * 32))
min_clk_period = DIV_ROUND_UP(timings->tWHR_min, 32);
if (timings->tRHW_min > (min_clk_period * 20))
min_clk_period = DIV_ROUND_UP(timings->tRHW_min, 20);
tWB = sunxi_nand_lookup_timing(tWB_lut, timings->tWB_max,
min_clk_period);
if (tWB < 0) {
dev_err(nfc->dev, "unsupported tWB\n");
return tWB;
}
tADL = DIV_ROUND_UP(timings->tADL_min, min_clk_period) >> 3;
if (tADL > 3) {
dev_err(nfc->dev, "unsupported tADL\n");
return -EINVAL;
}
tWHR = DIV_ROUND_UP(timings->tWHR_min, min_clk_period) >> 3;
if (tWHR > 3) {
dev_err(nfc->dev, "unsupported tWHR\n");
return -EINVAL;
}
tRHW = sunxi_nand_lookup_timing(tRHW_lut, timings->tRHW_min,
min_clk_period);
if (tRHW < 0) {
dev_err(nfc->dev, "unsupported tRHW\n");
return tRHW;
}
tCAD = 0x7;
chip->timing_cfg = NFC_TIMING_CFG(tWB, tADL, tWHR, tRHW, tCAD);
min_clk_period = DIV_ROUND_UP(min_clk_period, 1000);
chip->clk_rate = NSEC_PER_SEC / min_clk_period;
real_clk_rate = clk_round_rate(nfc->mod_clk, chip->clk_rate);
min_clk_period = NSEC_PER_SEC / real_clk_rate;
chip->timing_ctl = ((min_clk_period * 2) < 30) ?
NFC_TIMING_CTL_EDO : 0;
return 0;
}
static int sunxi_nand_chip_init_timings(struct sunxi_nand_chip *chip,
struct device_node *np)
{
struct mtd_info *mtd = nand_to_mtd(&chip->nand);
const struct nand_sdr_timings *timings;
int ret;
int mode;
mode = onfi_get_async_timing_mode(&chip->nand);
if (mode == ONFI_TIMING_MODE_UNKNOWN) {
mode = chip->nand.onfi_timing_mode_default;
} else {
uint8_t feature[ONFI_SUBFEATURE_PARAM_LEN] = {};
int i;
mode = fls(mode) - 1;
if (mode < 0)
mode = 0;
feature[0] = mode;
for (i = 0; i < chip->nsels; i++) {
chip->nand.select_chip(mtd, i);
ret = chip->nand.onfi_set_features(mtd, &chip->nand,
ONFI_FEATURE_ADDR_TIMING_MODE,
feature);
chip->nand.select_chip(mtd, -1);
if (ret)
return ret;
}
}
timings = onfi_async_timing_mode_to_sdr_timings(mode);
if (IS_ERR(timings))
return PTR_ERR(timings);
return sunxi_nand_chip_set_timings(chip, timings);
}
static int sunxi_nand_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &nand->ecc;
if (section >= ecc->steps)
return -ERANGE;
oobregion->offset = section * (ecc->bytes + 4) + 4;
oobregion->length = ecc->bytes;
return 0;
}
static int sunxi_nand_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &nand->ecc;
if (section > ecc->steps)
return -ERANGE;
if (!section && ecc->mode == NAND_ECC_HW) {
oobregion->offset = 2;
oobregion->length = 2;
return 0;
}
oobregion->offset = section * (ecc->bytes + 4);
if (section < ecc->steps)
oobregion->length = 4;
else
oobregion->offset = mtd->oobsize - oobregion->offset;
return 0;
}
static int sunxi_nand_hw_common_ecc_ctrl_init(struct mtd_info *mtd,
struct nand_ecc_ctrl *ecc,
struct device_node *np)
{
static const u8 strengths[] = { 16, 24, 28, 32, 40, 48, 56, 60, 64 };
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
struct sunxi_nand_hw_ecc *data;
int nsectors;
int ret;
int i;
if (ecc->size != 512 && ecc->size != 1024)
return -EINVAL;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (ecc->size == 512 && mtd->writesize > 512) {
ecc->size = 1024;
ecc->strength *= 2;
}
for (i = 0; i < ARRAY_SIZE(strengths); i++) {
if (ecc->strength <= strengths[i])
break;
}
if (i >= ARRAY_SIZE(strengths)) {
dev_err(nfc->dev, "unsupported strength\n");
ret = -ENOTSUPP;
goto err;
}
data->mode = i;
ecc->bytes = DIV_ROUND_UP(ecc->strength * fls(8 * 1024), 8);
ecc->bytes = ALIGN(ecc->bytes, 2);
nsectors = mtd->writesize / ecc->size;
if (mtd->oobsize < ((ecc->bytes + 4) * nsectors)) {
ret = -EINVAL;
goto err;
}
ecc->read_oob = sunxi_nfc_hw_common_ecc_read_oob;
ecc->write_oob = sunxi_nfc_hw_common_ecc_write_oob;
mtd_set_ooblayout(mtd, &sunxi_nand_ooblayout_ops);
ecc->priv = data;
return 0;
err:
kfree(data);
return ret;
}
static void sunxi_nand_hw_common_ecc_ctrl_cleanup(struct nand_ecc_ctrl *ecc)
{
kfree(ecc->priv);
}
static int sunxi_nand_hw_ecc_ctrl_init(struct mtd_info *mtd,
struct nand_ecc_ctrl *ecc,
struct device_node *np)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
int ret;
ret = sunxi_nand_hw_common_ecc_ctrl_init(mtd, ecc, np);
if (ret)
return ret;
if (nfc->dmac) {
ecc->read_page = sunxi_nfc_hw_ecc_read_page_dma;
ecc->read_subpage = sunxi_nfc_hw_ecc_read_subpage_dma;
ecc->write_page = sunxi_nfc_hw_ecc_write_page_dma;
nand->options |= NAND_USE_BOUNCE_BUFFER;
} else {
ecc->read_page = sunxi_nfc_hw_ecc_read_page;
ecc->read_subpage = sunxi_nfc_hw_ecc_read_subpage;
ecc->write_page = sunxi_nfc_hw_ecc_write_page;
}
ecc->write_subpage = sunxi_nfc_hw_ecc_write_subpage;
ecc->read_oob_raw = nand_read_oob_std;
ecc->write_oob_raw = nand_write_oob_std;
ecc->read_subpage = sunxi_nfc_hw_ecc_read_subpage;
return 0;
}
static int sunxi_nand_hw_syndrome_ecc_ctrl_init(struct mtd_info *mtd,
struct nand_ecc_ctrl *ecc,
struct device_node *np)
{
int ret;
ret = sunxi_nand_hw_common_ecc_ctrl_init(mtd, ecc, np);
if (ret)
return ret;
ecc->prepad = 4;
ecc->read_page = sunxi_nfc_hw_syndrome_ecc_read_page;
ecc->write_page = sunxi_nfc_hw_syndrome_ecc_write_page;
ecc->read_oob_raw = nand_read_oob_syndrome;
ecc->write_oob_raw = nand_write_oob_syndrome;
return 0;
}
static void sunxi_nand_ecc_cleanup(struct nand_ecc_ctrl *ecc)
{
switch (ecc->mode) {
case NAND_ECC_HW:
case NAND_ECC_HW_SYNDROME:
sunxi_nand_hw_common_ecc_ctrl_cleanup(ecc);
break;
case NAND_ECC_NONE:
default:
break;
}
}
static int sunxi_nand_ecc_init(struct mtd_info *mtd, struct nand_ecc_ctrl *ecc,
struct device_node *np)
{
struct nand_chip *nand = mtd_to_nand(mtd);
int ret;
if (!ecc->size) {
ecc->size = nand->ecc_step_ds;
ecc->strength = nand->ecc_strength_ds;
}
if (!ecc->size || !ecc->strength)
return -EINVAL;
switch (ecc->mode) {
case NAND_ECC_HW:
ret = sunxi_nand_hw_ecc_ctrl_init(mtd, ecc, np);
if (ret)
return ret;
break;
case NAND_ECC_HW_SYNDROME:
ret = sunxi_nand_hw_syndrome_ecc_ctrl_init(mtd, ecc, np);
if (ret)
return ret;
break;
case NAND_ECC_NONE:
case NAND_ECC_SOFT:
break;
default:
return -EINVAL;
}
return 0;
}
static int sunxi_nand_chip_init(struct device *dev, struct sunxi_nfc *nfc,
struct device_node *np)
{
const struct nand_sdr_timings *timings;
struct sunxi_nand_chip *chip;
struct mtd_info *mtd;
struct nand_chip *nand;
int nsels;
int ret;
int i;
u32 tmp;
if (!of_get_property(np, "reg", &nsels))
return -EINVAL;
nsels /= sizeof(u32);
if (!nsels) {
dev_err(dev, "invalid reg property size\n");
return -EINVAL;
}
chip = devm_kzalloc(dev,
sizeof(*chip) +
(nsels * sizeof(struct sunxi_nand_chip_sel)),
GFP_KERNEL);
if (!chip) {
dev_err(dev, "could not allocate chip\n");
return -ENOMEM;
}
chip->nsels = nsels;
chip->selected = -1;
for (i = 0; i < nsels; i++) {
ret = of_property_read_u32_index(np, "reg", i, &tmp);
if (ret) {
dev_err(dev, "could not retrieve reg property: %d\n",
ret);
return ret;
}
if (tmp > NFC_MAX_CS) {
dev_err(dev,
"invalid reg value: %u (max CS = 7)\n",
tmp);
return -EINVAL;
}
if (test_and_set_bit(tmp, &nfc->assigned_cs)) {
dev_err(dev, "CS %d already assigned\n", tmp);
return -EINVAL;
}
chip->sels[i].cs = tmp;
if (!of_property_read_u32_index(np, "allwinner,rb", i, &tmp) &&
tmp < 2) {
chip->sels[i].rb.type = RB_NATIVE;
chip->sels[i].rb.info.nativeid = tmp;
} else {
ret = of_get_named_gpio(np, "rb-gpios", i);
if (ret >= 0) {
tmp = ret;
chip->sels[i].rb.type = RB_GPIO;
chip->sels[i].rb.info.gpio = tmp;
ret = devm_gpio_request(dev, tmp, "nand-rb");
if (ret)
return ret;
ret = gpio_direction_input(tmp);
if (ret)
return ret;
} else {
chip->sels[i].rb.type = RB_NONE;
}
}
}
nand = &chip->nand;
nand->chip_delay = 200;
nand->controller = &nfc->controller;
nand->ecc.mode = NAND_ECC_HW;
nand_set_flash_node(nand, np);
nand->select_chip = sunxi_nfc_select_chip;
nand->cmd_ctrl = sunxi_nfc_cmd_ctrl;
nand->read_buf = sunxi_nfc_read_buf;
nand->write_buf = sunxi_nfc_write_buf;
nand->read_byte = sunxi_nfc_read_byte;
mtd = nand_to_mtd(nand);
mtd->dev.parent = dev;
timings = onfi_async_timing_mode_to_sdr_timings(0);
if (IS_ERR(timings)) {
ret = PTR_ERR(timings);
dev_err(dev,
"could not retrieve timings for ONFI mode 0: %d\n",
ret);
return ret;
}
ret = sunxi_nand_chip_set_timings(chip, timings);
if (ret) {
dev_err(dev, "could not configure chip timings: %d\n", ret);
return ret;
}
ret = nand_scan_ident(mtd, nsels, NULL);
if (ret)
return ret;
if (nand->bbt_options & NAND_BBT_USE_FLASH)
nand->bbt_options |= NAND_BBT_NO_OOB;
if (nand->options & NAND_NEED_SCRAMBLING)
nand->options |= NAND_NO_SUBPAGE_WRITE;
nand->options |= NAND_SUBPAGE_READ;
ret = sunxi_nand_chip_init_timings(chip, np);
if (ret) {
dev_err(dev, "could not configure chip timings: %d\n", ret);
return ret;
}
ret = sunxi_nand_ecc_init(mtd, &nand->ecc, np);
if (ret) {
dev_err(dev, "ECC init failed: %d\n", ret);
return ret;
}
ret = nand_scan_tail(mtd);
if (ret) {
dev_err(dev, "nand_scan_tail failed: %d\n", ret);
return ret;
}
ret = mtd_device_register(mtd, NULL, 0);
if (ret) {
dev_err(dev, "failed to register mtd device: %d\n", ret);
nand_release(mtd);
return ret;
}
list_add_tail(&chip->node, &nfc->chips);
return 0;
}
static int sunxi_nand_chips_init(struct device *dev, struct sunxi_nfc *nfc)
{
struct device_node *np = dev->of_node;
struct device_node *nand_np;
int nchips = of_get_child_count(np);
int ret;
if (nchips > 8) {
dev_err(dev, "too many NAND chips: %d (max = 8)\n", nchips);
return -EINVAL;
}
for_each_child_of_node(np, nand_np) {
ret = sunxi_nand_chip_init(dev, nfc, nand_np);
if (ret) {
of_node_put(nand_np);
return ret;
}
}
return 0;
}
static void sunxi_nand_chips_cleanup(struct sunxi_nfc *nfc)
{
struct sunxi_nand_chip *chip;
while (!list_empty(&nfc->chips)) {
chip = list_first_entry(&nfc->chips, struct sunxi_nand_chip,
node);
nand_release(nand_to_mtd(&chip->nand));
sunxi_nand_ecc_cleanup(&chip->nand.ecc);
list_del(&chip->node);
}
}
static int sunxi_nfc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *r;
struct sunxi_nfc *nfc;
int irq;
int ret;
nfc = devm_kzalloc(dev, sizeof(*nfc), GFP_KERNEL);
if (!nfc)
return -ENOMEM;
nfc->dev = dev;
spin_lock_init(&nfc->controller.lock);
init_waitqueue_head(&nfc->controller.wq);
INIT_LIST_HEAD(&nfc->chips);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nfc->regs = devm_ioremap_resource(dev, r);
if (IS_ERR(nfc->regs))
return PTR_ERR(nfc->regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to retrieve irq\n");
return irq;
}
nfc->ahb_clk = devm_clk_get(dev, "ahb");
if (IS_ERR(nfc->ahb_clk)) {
dev_err(dev, "failed to retrieve ahb clk\n");
return PTR_ERR(nfc->ahb_clk);
}
ret = clk_prepare_enable(nfc->ahb_clk);
if (ret)
return ret;
nfc->mod_clk = devm_clk_get(dev, "mod");
if (IS_ERR(nfc->mod_clk)) {
dev_err(dev, "failed to retrieve mod clk\n");
ret = PTR_ERR(nfc->mod_clk);
goto out_ahb_clk_unprepare;
}
ret = clk_prepare_enable(nfc->mod_clk);
if (ret)
goto out_ahb_clk_unprepare;
nfc->reset = devm_reset_control_get_optional(dev, "ahb");
if (!IS_ERR(nfc->reset)) {
ret = reset_control_deassert(nfc->reset);
if (ret) {
dev_err(dev, "reset err %d\n", ret);
goto out_mod_clk_unprepare;
}
} else if (PTR_ERR(nfc->reset) != -ENOENT) {
ret = PTR_ERR(nfc->reset);
goto out_mod_clk_unprepare;
}
ret = sunxi_nfc_rst(nfc);
if (ret)
goto out_ahb_reset_reassert;
writel(0, nfc->regs + NFC_REG_INT);
ret = devm_request_irq(dev, irq, sunxi_nfc_interrupt,
0, "sunxi-nand", nfc);
if (ret)
goto out_ahb_reset_reassert;
nfc->dmac = dma_request_slave_channel(dev, "rxtx");
if (nfc->dmac) {
struct dma_slave_config dmac_cfg = { };
dmac_cfg.src_addr = r->start + NFC_REG_IO_DATA;
dmac_cfg.dst_addr = dmac_cfg.src_addr;
dmac_cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
dmac_cfg.dst_addr_width = dmac_cfg.src_addr_width;
dmac_cfg.src_maxburst = 4;
dmac_cfg.dst_maxburst = 4;
dmaengine_slave_config(nfc->dmac, &dmac_cfg);
} else {
dev_warn(dev, "failed to request rxtx DMA channel\n");
}
platform_set_drvdata(pdev, nfc);
ret = sunxi_nand_chips_init(dev, nfc);
if (ret) {
dev_err(dev, "failed to init nand chips\n");
goto out_release_dmac;
}
return 0;
out_release_dmac:
if (nfc->dmac)
dma_release_channel(nfc->dmac);
out_ahb_reset_reassert:
if (!IS_ERR(nfc->reset))
reset_control_assert(nfc->reset);
out_mod_clk_unprepare:
clk_disable_unprepare(nfc->mod_clk);
out_ahb_clk_unprepare:
clk_disable_unprepare(nfc->ahb_clk);
return ret;
}
static int sunxi_nfc_remove(struct platform_device *pdev)
{
struct sunxi_nfc *nfc = platform_get_drvdata(pdev);
sunxi_nand_chips_cleanup(nfc);
if (!IS_ERR(nfc->reset))
reset_control_assert(nfc->reset);
if (nfc->dmac)
dma_release_channel(nfc->dmac);
clk_disable_unprepare(nfc->mod_clk);
clk_disable_unprepare(nfc->ahb_clk);
return 0;
}
