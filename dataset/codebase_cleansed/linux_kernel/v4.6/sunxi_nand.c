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
static int sunxi_nfc_wait_int(struct sunxi_nfc *nfc, u32 flags,
unsigned int timeout_ms)
{
init_completion(&nfc->complete);
writel(flags, nfc->regs + NFC_REG_INT);
if (!timeout_ms)
timeout_ms = NFC_DEFAULT_TIMEOUT_MS;
if (!wait_for_completion_timeout(&nfc->complete,
msecs_to_jiffies(timeout_ms))) {
dev_err(nfc->dev, "wait interrupt timedout\n");
return -ETIMEDOUT;
}
return 0;
}
static int sunxi_nfc_wait_cmd_fifo_empty(struct sunxi_nfc *nfc)
{
unsigned long timeout = jiffies +
msecs_to_jiffies(NFC_DEFAULT_TIMEOUT_MS);
do {
if (!(readl(nfc->regs + NFC_REG_ST) & NFC_CMD_FIFO_STATUS))
return 0;
} while (time_before(jiffies, timeout));
dev_err(nfc->dev, "wait for empty cmd FIFO timedout\n");
return -ETIMEDOUT;
}
static int sunxi_nfc_rst(struct sunxi_nfc *nfc)
{
unsigned long timeout = jiffies +
msecs_to_jiffies(NFC_DEFAULT_TIMEOUT_MS);
writel(0, nfc->regs + NFC_REG_ECC_CTL);
writel(NFC_RESET, nfc->regs + NFC_REG_CTL);
do {
if (!(readl(nfc->regs + NFC_REG_CTL) & NFC_RESET))
return 0;
} while (time_before(jiffies, timeout));
dev_err(nfc->dev, "wait for NAND controller reset timedout\n");
return -ETIMEDOUT;
}
static int sunxi_nfc_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
struct sunxi_nand_rb *rb;
unsigned long timeo = (sunxi_nand->nand.state == FL_ERASING ? 400 : 20);
int ret;
if (sunxi_nand->selected < 0)
return 0;
rb = &sunxi_nand->sels[sunxi_nand->selected].rb;
switch (rb->type) {
case RB_NATIVE:
ret = !!(readl(nfc->regs + NFC_REG_ST) &
NFC_RB_STATE(rb->info.nativeid));
if (ret)
break;
sunxi_nfc_wait_int(nfc, NFC_RB_B2R, timeo);
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
NFC_PAGE_SHIFT(nand->page_shift - 10);
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
ret = sunxi_nfc_wait_int(nfc, NFC_CMD_INT_FLAG, 0);
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
ret = sunxi_nfc_wait_int(nfc, NFC_CMD_INT_FLAG, 0);
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
u32 tmp;
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return;
if (ctrl & NAND_CTRL_CHANGE) {
tmp = readl(nfc->regs + NFC_REG_CTL);
if (ctrl & NAND_NCE)
tmp |= NFC_CE_CTL;
else
tmp &= ~NFC_CE_CTL;
writel(tmp, nfc->regs + NFC_REG_CTL);
}
if (dat == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE) {
writel(NFC_SEND_CMD1 | dat, nfc->regs + NFC_REG_CMD);
} else {
writel(dat, nfc->regs + NFC_REG_ADDR_LOW);
writel(NFC_SEND_ADR, nfc->regs + NFC_REG_CMD);
}
sunxi_nfc_wait_int(nfc, NFC_CMD_INT_FLAG, 0);
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
ecc_ctl |= NFC_ECC_EN | NFC_ECC_MODE(data->mode) | NFC_ECC_EXCEPTION;
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
static int sunxi_nfc_hw_ecc_read_chunk(struct mtd_info *mtd,
u8 *data, int data_off,
u8 *oob, int oob_off,
int *cur_off,
unsigned int *max_bitflips,
bool bbm, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nfc *nfc = to_sunxi_nfc(nand->controller);
struct nand_ecc_ctrl *ecc = &nand->ecc;
int raw_mode = 0;
u32 status;
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
ret = sunxi_nfc_wait_int(nfc, NFC_CMD_INT_FLAG, 0);
sunxi_nfc_randomizer_disable(mtd);
if (ret)
return ret;
*cur_off = oob_off + ecc->bytes + 4;
status = readl(nfc->regs + NFC_REG_ECC_ST);
if (status & NFC_ECC_PAT_FOUND(0)) {
u8 pattern = 0xff;
if (unlikely(!(readl(nfc->regs + NFC_REG_PAT_ID) & 0x1)))
pattern = 0x0;
memset(data, pattern, ecc->size);
memset(oob, pattern, ecc->bytes + 4);
return 1;
}
ret = NFC_ECC_ERR_CNT(0, readl(nfc->regs + NFC_REG_ECC_ERR_CNT(0)));
memcpy_fromio(data, nfc->regs + NFC_RAM0_BASE, ecc->size);
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, oob_off, -1);
sunxi_nfc_randomizer_read_buf(mtd, oob, ecc->bytes + 4, true, page);
if (status & NFC_ECC_ERR(0)) {
if (nand->options & NAND_NEED_SCRAMBLING) {
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, data_off, -1);
nand->read_buf(mtd, data, ecc->size);
nand->cmdfunc(mtd, NAND_CMD_RNDOUT, oob_off, -1);
nand->read_buf(mtd, oob, ecc->bytes + 4);
}
ret = nand_check_erased_ecc_chunk(data, ecc->size,
oob, ecc->bytes + 4,
NULL, 0, ecc->strength);
if (ret >= 0)
raw_mode = 1;
} else {
sunxi_nfc_user_data_to_buf(readl(nfc->regs + NFC_REG_USER_DATA(0)),
oob);
if (bbm && nand->options & NAND_NEED_SCRAMBLING)
sunxi_nfc_randomize_bbm(mtd, page, oob);
}
if (ret < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += ret;
*max_bitflips = max_t(unsigned int, *max_bitflips, ret);
}
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
if (*cur_off != offset)
nand->cmdfunc(mtd, NAND_CMD_RNDOUT,
offset + mtd->writesize, -1);
if (!randomize)
sunxi_nfc_read_buf(mtd, oob + offset, len);
else
sunxi_nfc_randomizer_read_buf(mtd, oob + offset, len,
false, page);
*cur_off = mtd->oobsize + mtd->writesize;
}
static inline u32 sunxi_nfc_buf_to_user_data(const u8 *buf)
{
return buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
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
if ((nand->options & NAND_NEED_SCRAMBLING) && bbm) {
u8 user_data[4];
memcpy(user_data, oob, 4);
sunxi_nfc_randomize_bbm(mtd, page, user_data);
writel(sunxi_nfc_buf_to_user_data(user_data),
nfc->regs + NFC_REG_USER_DATA(0));
} else {
writel(sunxi_nfc_buf_to_user_data(oob),
nfc->regs + NFC_REG_USER_DATA(0));
}
if (data_off + ecc->size != oob_off)
nand->cmdfunc(mtd, NAND_CMD_RNDIN, oob_off, -1);
ret = sunxi_nfc_wait_cmd_fifo_empty(nfc);
if (ret)
return ret;
sunxi_nfc_randomizer_enable(mtd);
writel(NFC_DATA_TRANS | NFC_DATA_SWAP_METHOD |
NFC_ACCESS_DIR | NFC_ECC_OP,
nfc->regs + NFC_REG_CMD);
ret = sunxi_nfc_wait_int(nfc, NFC_CMD_INT_FLAG, 0);
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
if (*cur_off != offset)
nand->cmdfunc(mtd, NAND_CMD_RNDIN,
offset + mtd->writesize, -1);
sunxi_nfc_randomizer_write_buf(mtd, oob + offset, len, false, page);
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
!i, page);
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
&max_bitflips, !i, page);
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
chip->timing_ctl = (timings->tRC_min < 30000) ? NFC_TIMING_CTL_EDO : 0;
min_clk_period = DIV_ROUND_UP(min_clk_period, 1000);
chip->clk_rate = (2 * NSEC_PER_SEC) / min_clk_period;
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
static int sunxi_nand_hw_common_ecc_ctrl_init(struct mtd_info *mtd,
struct nand_ecc_ctrl *ecc,
struct device_node *np)
{
static const u8 strengths[] = { 16, 24, 28, 32, 40, 48, 56, 60, 64 };
struct nand_chip *nand = mtd_to_nand(mtd);
struct sunxi_nand_chip *sunxi_nand = to_sunxi_nand(nand);
struct sunxi_nfc *nfc = to_sunxi_nfc(sunxi_nand->nand.controller);
struct sunxi_nand_hw_ecc *data;
struct nand_ecclayout *layout;
int nsectors;
int ret;
int i;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
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
layout = &data->layout;
nsectors = mtd->writesize / ecc->size;
if (mtd->oobsize < ((ecc->bytes + 4) * nsectors)) {
ret = -EINVAL;
goto err;
}
layout->eccbytes = (ecc->bytes * nsectors);
ecc->layout = layout;
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
struct nand_ecclayout *layout;
int nsectors;
int i, j;
int ret;
ret = sunxi_nand_hw_common_ecc_ctrl_init(mtd, ecc, np);
if (ret)
return ret;
ecc->read_page = sunxi_nfc_hw_ecc_read_page;
ecc->write_page = sunxi_nfc_hw_ecc_write_page;
layout = ecc->layout;
nsectors = mtd->writesize / ecc->size;
for (i = 0; i < nsectors; i++) {
if (i) {
layout->oobfree[i].offset =
layout->oobfree[i - 1].offset +
layout->oobfree[i - 1].length +
ecc->bytes;
layout->oobfree[i].length = 4;
} else {
layout->oobfree[i].length = 2;
layout->oobfree[i].offset = 2;
}
for (j = 0; j < ecc->bytes; j++)
layout->eccpos[(ecc->bytes * i) + j] =
layout->oobfree[i].offset +
layout->oobfree[i].length + j;
}
if (mtd->oobsize > (ecc->bytes + 4) * nsectors) {
layout->oobfree[nsectors].offset =
layout->oobfree[nsectors - 1].offset +
layout->oobfree[nsectors - 1].length +
ecc->bytes;
layout->oobfree[nsectors].length = mtd->oobsize -
((ecc->bytes + 4) * nsectors);
}
return 0;
}
static int sunxi_nand_hw_syndrome_ecc_ctrl_init(struct mtd_info *mtd,
struct nand_ecc_ctrl *ecc,
struct device_node *np)
{
struct nand_ecclayout *layout;
int nsectors;
int i;
int ret;
ret = sunxi_nand_hw_common_ecc_ctrl_init(mtd, ecc, np);
if (ret)
return ret;
ecc->prepad = 4;
ecc->read_page = sunxi_nfc_hw_syndrome_ecc_read_page;
ecc->write_page = sunxi_nfc_hw_syndrome_ecc_write_page;
layout = ecc->layout;
nsectors = mtd->writesize / ecc->size;
for (i = 0; i < (ecc->bytes * nsectors); i++)
layout->eccpos[i] = i;
layout->oobfree[0].length = mtd->oobsize - i;
layout->oobfree[0].offset = i;
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
kfree(ecc->layout);
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
case NAND_ECC_SOFT_BCH:
break;
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
ecc->layout = kzalloc(sizeof(*ecc->layout), GFP_KERNEL);
if (!ecc->layout)
return -ENOMEM;
ecc->layout->oobfree[0].length = mtd->oobsize;
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
ret = nand_scan_ident(mtd, nsels, NULL);
if (ret)
return ret;
if (nand->bbt_options & NAND_BBT_USE_FLASH)
nand->bbt_options |= NAND_BBT_NO_OOB;
if (nand->options & NAND_NEED_SCRAMBLING)
nand->options |= NAND_NO_SUBPAGE_WRITE;
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
ret = sunxi_nfc_rst(nfc);
if (ret)
goto out_mod_clk_unprepare;
writel(0, nfc->regs + NFC_REG_INT);
ret = devm_request_irq(dev, irq, sunxi_nfc_interrupt,
0, "sunxi-nand", nfc);
if (ret)
goto out_mod_clk_unprepare;
platform_set_drvdata(pdev, nfc);
ret = sunxi_nand_chips_init(dev, nfc);
if (ret) {
dev_err(dev, "failed to init nand chips\n");
goto out_mod_clk_unprepare;
}
return 0;
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
return 0;
}
