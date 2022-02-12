static void memcpy32_fromio(void *trg, const void __iomem *src, size_t size)
{
int i;
u32 *t = trg;
const __iomem u32 *s = src;
for (i = 0; i < (size >> 2); i++)
*t++ = __raw_readl(s++);
}
static void memcpy16_fromio(void *trg, const void __iomem *src, size_t size)
{
int i;
u16 *t = trg;
const __iomem u16 *s = src;
if (PTR_ALIGN(trg, 4) == trg && IS_ALIGNED(size, 4)) {
memcpy32_fromio(trg, src, size);
return;
}
for (i = 0; i < (size >> 1); i++)
*t++ = __raw_readw(s++);
}
static inline void memcpy32_toio(void __iomem *trg, const void *src, int size)
{
__iowrite32_copy(trg, src, size / 4);
}
static void memcpy16_toio(void __iomem *trg, const void *src, int size)
{
int i;
__iomem u16 *t = trg;
const u16 *s = src;
if (PTR_ALIGN(src, 4) == src && IS_ALIGNED(size, 4)) {
memcpy32_toio(trg, src, size);
return;
}
for (i = 0; i < (size >> 1); i++)
__raw_writew(*s++, t++);
}
static int check_int_v3(struct mxc_nand_host *host)
{
uint32_t tmp;
tmp = readl(NFC_V3_IPC);
if (!(tmp & NFC_V3_IPC_INT))
return 0;
tmp &= ~NFC_V3_IPC_INT;
writel(tmp, NFC_V3_IPC);
return 1;
}
static int check_int_v1_v2(struct mxc_nand_host *host)
{
uint32_t tmp;
tmp = readw(NFC_V1_V2_CONFIG2);
if (!(tmp & NFC_V1_V2_CONFIG2_INT))
return 0;
if (!host->devtype_data->irqpending_quirk)
writew(tmp & ~NFC_V1_V2_CONFIG2_INT, NFC_V1_V2_CONFIG2);
return 1;
}
static void irq_control_v1_v2(struct mxc_nand_host *host, int activate)
{
uint16_t tmp;
tmp = readw(NFC_V1_V2_CONFIG1);
if (activate)
tmp &= ~NFC_V1_V2_CONFIG1_INT_MSK;
else
tmp |= NFC_V1_V2_CONFIG1_INT_MSK;
writew(tmp, NFC_V1_V2_CONFIG1);
}
static void irq_control_v3(struct mxc_nand_host *host, int activate)
{
uint32_t tmp;
tmp = readl(NFC_V3_CONFIG2);
if (activate)
tmp &= ~NFC_V3_CONFIG2_INT_MSK;
else
tmp |= NFC_V3_CONFIG2_INT_MSK;
writel(tmp, NFC_V3_CONFIG2);
}
static void irq_control(struct mxc_nand_host *host, int activate)
{
if (host->devtype_data->irqpending_quirk) {
if (activate)
enable_irq(host->irq);
else
disable_irq_nosync(host->irq);
} else {
host->devtype_data->irq_control(host, activate);
}
}
static u32 get_ecc_status_v1(struct mxc_nand_host *host)
{
return readw(NFC_V1_V2_ECC_STATUS_RESULT);
}
static u32 get_ecc_status_v2(struct mxc_nand_host *host)
{
return readl(NFC_V1_V2_ECC_STATUS_RESULT);
}
static u32 get_ecc_status_v3(struct mxc_nand_host *host)
{
return readl(NFC_V3_ECC_STATUS_RESULT);
}
static irqreturn_t mxc_nfc_irq(int irq, void *dev_id)
{
struct mxc_nand_host *host = dev_id;
if (!host->devtype_data->check_int(host))
return IRQ_NONE;
irq_control(host, 0);
complete(&host->op_completion);
return IRQ_HANDLED;
}
static int wait_op_done(struct mxc_nand_host *host, int useirq)
{
int ret = 0;
if (host->devtype_data->check_int(host))
return 0;
if (useirq) {
unsigned long timeout;
reinit_completion(&host->op_completion);
irq_control(host, 1);
timeout = wait_for_completion_timeout(&host->op_completion, HZ);
if (!timeout && !host->devtype_data->check_int(host)) {
dev_dbg(host->dev, "timeout waiting for irq\n");
ret = -ETIMEDOUT;
}
} else {
int max_retries = 8000;
int done;
do {
udelay(1);
done = host->devtype_data->check_int(host);
if (done)
break;
} while (--max_retries);
if (!done) {
dev_dbg(host->dev, "timeout polling for completion\n");
ret = -ETIMEDOUT;
}
}
WARN_ONCE(ret < 0, "timeout! useirq=%d\n", useirq);
return ret;
}
static void send_cmd_v3(struct mxc_nand_host *host, uint16_t cmd, int useirq)
{
writel(cmd, NFC_V3_FLASH_CMD);
writel(NFC_CMD, NFC_V3_LAUNCH);
wait_op_done(host, useirq);
}
static void send_cmd_v1_v2(struct mxc_nand_host *host, uint16_t cmd, int useirq)
{
pr_debug("send_cmd(host, 0x%x, %d)\n", cmd, useirq);
writew(cmd, NFC_V1_V2_FLASH_CMD);
writew(NFC_CMD, NFC_V1_V2_CONFIG2);
if (host->devtype_data->irqpending_quirk && (cmd == NAND_CMD_RESET)) {
int max_retries = 100;
while (max_retries-- > 0) {
if (readw(NFC_V1_V2_CONFIG2) == 0) {
break;
}
udelay(1);
}
if (max_retries < 0)
pr_debug("%s: RESET failed\n", __func__);
} else {
wait_op_done(host, useirq);
}
}
static void send_addr_v3(struct mxc_nand_host *host, uint16_t addr, int islast)
{
writel(addr, NFC_V3_FLASH_ADDR0);
writel(NFC_ADDR, NFC_V3_LAUNCH);
wait_op_done(host, 0);
}
static void send_addr_v1_v2(struct mxc_nand_host *host, uint16_t addr, int islast)
{
pr_debug("send_addr(host, 0x%x %d)\n", addr, islast);
writew(addr, NFC_V1_V2_FLASH_ADDR);
writew(NFC_ADDR, NFC_V1_V2_CONFIG2);
wait_op_done(host, islast);
}
static void send_page_v3(struct mtd_info *mtd, unsigned int ops)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint32_t tmp;
tmp = readl(NFC_V3_CONFIG1);
tmp &= ~(7 << 4);
writel(tmp, NFC_V3_CONFIG1);
writel(ops, NFC_V3_LAUNCH);
wait_op_done(host, false);
}
static void send_page_v2(struct mtd_info *mtd, unsigned int ops)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
writew(ops, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
}
static void send_page_v1(struct mtd_info *mtd, unsigned int ops)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
int bufs, i;
if (mtd->writesize > 512)
bufs = 4;
else
bufs = 1;
for (i = 0; i < bufs; i++) {
writew((host->active_cs << 4) | i, NFC_V1_V2_BUF_ADDR);
writew(ops, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
}
}
static void send_read_id_v3(struct mxc_nand_host *host)
{
writel(NFC_ID, NFC_V3_LAUNCH);
wait_op_done(host, true);
memcpy32_fromio(host->data_buf, host->main_area0, 16);
}
static void send_read_id_v1_v2(struct mxc_nand_host *host)
{
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
writew(NFC_ID, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
memcpy32_fromio(host->data_buf, host->main_area0, 16);
}
static uint16_t get_dev_status_v3(struct mxc_nand_host *host)
{
writew(NFC_STATUS, NFC_V3_LAUNCH);
wait_op_done(host, true);
return readl(NFC_V3_CONFIG1) >> 16;
}
static uint16_t get_dev_status_v1_v2(struct mxc_nand_host *host)
{
void __iomem *main_buf = host->main_area0;
uint32_t store;
uint16_t ret;
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
store = readl(main_buf);
writew(NFC_STATUS, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
ret = readw(main_buf);
writel(store, main_buf);
return ret;
}
static int mxc_nand_dev_ready(struct mtd_info *mtd)
{
return 1;
}
static void mxc_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
}
static int mxc_nand_correct_data_v1(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t ecc_status = get_ecc_status_v1(host);
if (((ecc_status & 0x3) == 2) || ((ecc_status >> 2) == 2)) {
pr_debug("MXC_NAND: HWECC uncorrectable 2-bit ECC error\n");
return -1;
}
return 0;
}
static int mxc_nand_correct_data_v2_v3(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
u32 ecc_stat, err;
int no_subpages = 1;
int ret = 0;
u8 ecc_bit_mask, err_limit;
ecc_bit_mask = (host->eccsize == 4) ? 0x7 : 0xf;
err_limit = (host->eccsize == 4) ? 0x4 : 0x8;
no_subpages = mtd->writesize >> 9;
ecc_stat = host->devtype_data->get_ecc_status(host);
do {
err = ecc_stat & ecc_bit_mask;
if (err > err_limit) {
printk(KERN_WARNING "UnCorrectable RS-ECC Error\n");
return -1;
} else {
ret += err;
}
ecc_stat >>= 4;
} while (--no_subpages);
pr_debug("%d Symbol Correctable RS-ECC Error\n", ret);
return ret;
}
static int mxc_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
return 0;
}
static u_char mxc_nand_read_byte(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint8_t ret;
if (host->status_request)
return host->devtype_data->get_dev_status(host) & 0xFF;
if (nand_chip->options & NAND_BUSWIDTH_16) {
ret = *(uint16_t *)(host->data_buf + host->buf_start);
host->buf_start += 2;
} else {
ret = *(uint8_t *)(host->data_buf + host->buf_start);
host->buf_start++;
}
pr_debug("%s: ret=0x%hhx (start=%u)\n", __func__, ret, host->buf_start);
return ret;
}
static uint16_t mxc_nand_read_word(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t ret;
ret = *(uint16_t *)(host->data_buf + host->buf_start);
host->buf_start += 2;
return ret;
}
static void mxc_nand_write_buf(struct mtd_info *mtd,
const u_char *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
u16 col = host->buf_start;
int n = mtd->oobsize + mtd->writesize - col;
n = min(n, len);
memcpy(host->data_buf + col, buf, n);
host->buf_start += n;
}
static void mxc_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
u16 col = host->buf_start;
int n = mtd->oobsize + mtd->writesize - col;
n = min(n, len);
memcpy(buf, host->data_buf + col, n);
host->buf_start += n;
}
static void mxc_nand_select_chip_v1_v3(struct mtd_info *mtd, int chip)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
if (chip == -1) {
if (host->clk_act) {
clk_disable_unprepare(host->clk);
host->clk_act = 0;
}
return;
}
if (!host->clk_act) {
clk_prepare_enable(host->clk);
host->clk_act = 1;
}
}
static void mxc_nand_select_chip_v2(struct mtd_info *mtd, int chip)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
if (chip == -1) {
if (host->clk_act) {
clk_disable_unprepare(host->clk);
host->clk_act = 0;
}
return;
}
if (!host->clk_act) {
clk_prepare_enable(host->clk);
host->clk_act = 1;
}
host->active_cs = chip;
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
}
static void copy_spare(struct mtd_info *mtd, bool bfrom)
{
struct nand_chip *this = mtd->priv;
struct mxc_nand_host *host = this->priv;
u16 i, oob_chunk_size;
u16 num_chunks = mtd->writesize / 512;
u8 *d = host->data_buf + mtd->writesize;
u8 __iomem *s = host->spare0;
u16 sparebuf_size = host->devtype_data->spare_len;
oob_chunk_size = (host->used_oobsize / num_chunks) & ~1;
if (bfrom) {
for (i = 0; i < num_chunks - 1; i++)
memcpy16_fromio(d + i * oob_chunk_size,
s + i * sparebuf_size,
oob_chunk_size);
memcpy16_fromio(d + i * oob_chunk_size,
s + i * sparebuf_size,
host->used_oobsize - i * oob_chunk_size);
} else {
for (i = 0; i < num_chunks - 1; i++)
memcpy16_toio(&s[i * sparebuf_size],
&d[i * oob_chunk_size],
oob_chunk_size);
memcpy16_toio(&s[oob_chunk_size * sparebuf_size],
&d[i * oob_chunk_size],
host->used_oobsize - i * oob_chunk_size);
}
}
static void mxc_do_addr_cycle(struct mtd_info *mtd, int column, int page_addr)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
if (column != -1) {
host->devtype_data->send_addr(host, column & 0xff,
page_addr == -1);
if (mtd->writesize > 512)
host->devtype_data->send_addr(host,
(column >> 8) & 0xff,
false);
}
if (page_addr != -1) {
host->devtype_data->send_addr(host, (page_addr & 0xff), false);
if (mtd->writesize > 512) {
if (mtd->size >= 0x10000000) {
host->devtype_data->send_addr(host,
(page_addr >> 8) & 0xff,
false);
host->devtype_data->send_addr(host,
(page_addr >> 16) & 0xff,
true);
} else
host->devtype_data->send_addr(host,
(page_addr >> 8) & 0xff, true);
} else {
if (mtd->size >= 0x4000000) {
host->devtype_data->send_addr(host,
(page_addr >> 8) & 0xff,
false);
host->devtype_data->send_addr(host,
(page_addr >> 16) & 0xff,
true);
} else
host->devtype_data->send_addr(host,
(page_addr >> 8) & 0xff, true);
}
}
}
static int get_eccsize(struct mtd_info *mtd)
{
int oobbytes_per_512 = 0;
oobbytes_per_512 = mtd->oobsize * 512 / mtd->writesize;
if (oobbytes_per_512 < 26)
return 4;
else
return 8;
}
static void ecc_8bit_layout_4k(struct nand_ecclayout *layout)
{
int i, j;
layout->eccbytes = 8*18;
for (i = 0; i < 8; i++)
for (j = 0; j < 18; j++)
layout->eccpos[i*18 + j] = i*26 + j + 7;
layout->oobfree[0].offset = 2;
layout->oobfree[0].length = 4;
for (i = 1; i < 8; i++) {
layout->oobfree[i].offset = i*26;
layout->oobfree[i].length = 7;
}
}
static void preset_v1(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t config1 = 0;
if (nand_chip->ecc.mode == NAND_ECC_HW && mtd->writesize)
config1 |= NFC_V1_V2_CONFIG1_ECC_EN;
if (!host->devtype_data->irqpending_quirk)
config1 |= NFC_V1_V2_CONFIG1_INT_MSK;
host->eccsize = 1;
writew(config1, NFC_V1_V2_CONFIG1);
writew(0x2, NFC_V1_V2_CONFIG);
writew(0x0, NFC_V1_UNLOCKSTART_BLKADDR);
writew(0xffff, NFC_V1_UNLOCKEND_BLKADDR);
writew(0x4, NFC_V1_V2_WRPROT);
}
static void preset_v2(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t config1 = 0;
config1 |= NFC_V2_CONFIG1_FP_INT;
if (!host->devtype_data->irqpending_quirk)
config1 |= NFC_V1_V2_CONFIG1_INT_MSK;
if (mtd->writesize) {
uint16_t pages_per_block = mtd->erasesize / mtd->writesize;
if (nand_chip->ecc.mode == NAND_ECC_HW)
config1 |= NFC_V1_V2_CONFIG1_ECC_EN;
host->eccsize = get_eccsize(mtd);
if (host->eccsize == 4)
config1 |= NFC_V2_CONFIG1_ECC_MODE_4;
config1 |= NFC_V2_CONFIG1_PPB(ffs(pages_per_block) - 6);
} else {
host->eccsize = 1;
}
writew(config1, NFC_V1_V2_CONFIG1);
writew(0x2, NFC_V1_V2_CONFIG);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR0);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR1);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR2);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR3);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR0);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR1);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR2);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR3);
writew(0x4, NFC_V1_V2_WRPROT);
}
static void preset_v3(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct mxc_nand_host *host = chip->priv;
uint32_t config2, config3;
int i, addr_phases;
writel(NFC_V3_CONFIG1_RBA(0), NFC_V3_CONFIG1);
writel(NFC_V3_IPC_CREQ, NFC_V3_IPC);
writel(NFC_V3_WRPROT_BLS_UNLOCK | NFC_V3_WRPROT_UNLOCK,
NFC_V3_WRPROT);
for (i = 0; i < NAND_MAX_CHIPS; i++)
writel(0x0 | (0xffff << 16),
NFC_V3_WRPROT_UNLOCK_BLK_ADD0 + (i << 2));
writel(0, NFC_V3_IPC);
config2 = NFC_V3_CONFIG2_ONE_CYCLE |
NFC_V3_CONFIG2_2CMD_PHASES |
NFC_V3_CONFIG2_SPAS(mtd->oobsize >> 1) |
NFC_V3_CONFIG2_ST_CMD(0x70) |
NFC_V3_CONFIG2_INT_MSK |
NFC_V3_CONFIG2_NUM_ADDR_PHASE0;
addr_phases = fls(chip->pagemask) >> 3;
if (mtd->writesize == 2048) {
config2 |= NFC_V3_CONFIG2_PS_2048;
config2 |= NFC_V3_CONFIG2_NUM_ADDR_PHASE1(addr_phases);
} else if (mtd->writesize == 4096) {
config2 |= NFC_V3_CONFIG2_PS_4096;
config2 |= NFC_V3_CONFIG2_NUM_ADDR_PHASE1(addr_phases);
} else {
config2 |= NFC_V3_CONFIG2_PS_512;
config2 |= NFC_V3_CONFIG2_NUM_ADDR_PHASE1(addr_phases - 1);
}
if (mtd->writesize) {
if (chip->ecc.mode == NAND_ECC_HW)
config2 |= NFC_V3_CONFIG2_ECC_EN;
config2 |= NFC_V3_CONFIG2_PPB(
ffs(mtd->erasesize / mtd->writesize) - 6,
host->devtype_data->ppb_shift);
host->eccsize = get_eccsize(mtd);
if (host->eccsize == 8)
config2 |= NFC_V3_CONFIG2_ECC_MODE_8;
}
writel(config2, NFC_V3_CONFIG2);
config3 = NFC_V3_CONFIG3_NUM_OF_DEVICES(0) |
NFC_V3_CONFIG3_NO_SDMA |
NFC_V3_CONFIG3_RBB_MODE |
NFC_V3_CONFIG3_SBB(6) |
NFC_V3_CONFIG3_ADD_OP(0);
if (!(chip->options & NAND_BUSWIDTH_16))
config3 |= NFC_V3_CONFIG3_FW8;
writel(config3, NFC_V3_CONFIG3);
writel(0, NFC_V3_DELAY_LINE);
}
static void mxc_nand_command(struct mtd_info *mtd, unsigned command,
int column, int page_addr)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
pr_debug("mxc_nand_command (cmd = 0x%x, col = 0x%x, page = 0x%x)\n",
command, column, page_addr);
host->status_request = false;
switch (command) {
case NAND_CMD_RESET:
host->devtype_data->preset(mtd);
host->devtype_data->send_cmd(host, command, false);
break;
case NAND_CMD_STATUS:
host->buf_start = 0;
host->status_request = true;
host->devtype_data->send_cmd(host, command, true);
WARN_ONCE(column != -1 || page_addr != -1,
"Unexpected column/row value (cmd=%u, col=%d, row=%d)\n",
command, column, page_addr);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
if (command == NAND_CMD_READ0)
host->buf_start = column;
else
host->buf_start = column + mtd->writesize;
command = NAND_CMD_READ0;
host->devtype_data->send_cmd(host, command, false);
WARN_ONCE(column < 0,
"Unexpected column/row value (cmd=%u, col=%d, row=%d)\n",
command, column, page_addr);
mxc_do_addr_cycle(mtd, 0, page_addr);
if (mtd->writesize > 512)
host->devtype_data->send_cmd(host,
NAND_CMD_READSTART, true);
host->devtype_data->send_page(mtd, NFC_OUTPUT);
memcpy32_fromio(host->data_buf, host->main_area0,
mtd->writesize);
copy_spare(mtd, true);
break;
case NAND_CMD_SEQIN:
if (column >= mtd->writesize)
mxc_nand_command(mtd, NAND_CMD_READ0, 0, page_addr);
host->buf_start = column;
host->devtype_data->send_cmd(host, command, false);
WARN_ONCE(column < -1,
"Unexpected column/row value (cmd=%u, col=%d, row=%d)\n",
command, column, page_addr);
mxc_do_addr_cycle(mtd, 0, page_addr);
break;
case NAND_CMD_PAGEPROG:
memcpy32_toio(host->main_area0, host->data_buf, mtd->writesize);
copy_spare(mtd, false);
host->devtype_data->send_page(mtd, NFC_INPUT);
host->devtype_data->send_cmd(host, command, true);
WARN_ONCE(column != -1 || page_addr != -1,
"Unexpected column/row value (cmd=%u, col=%d, row=%d)\n",
command, column, page_addr);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
case NAND_CMD_READID:
host->devtype_data->send_cmd(host, command, true);
mxc_do_addr_cycle(mtd, column, page_addr);
host->devtype_data->send_read_id(host);
host->buf_start = 0;
break;
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
host->devtype_data->send_cmd(host, command, false);
WARN_ONCE(column != -1,
"Unexpected column value (cmd=%u, col=%d)\n",
command, column);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
case NAND_CMD_PARAM:
host->devtype_data->send_cmd(host, command, false);
mxc_do_addr_cycle(mtd, column, page_addr);
host->devtype_data->send_page(mtd, NFC_OUTPUT);
memcpy32_fromio(host->data_buf, host->main_area0, 512);
host->buf_start = 0;
break;
default:
WARN_ONCE(1, "Unimplemented command (cmd=%u)\n",
command);
break;
}
}
static inline int is_imx21_nfc(struct mxc_nand_host *host)
{
return host->devtype_data == &imx21_nand_devtype_data;
}
static inline int is_imx27_nfc(struct mxc_nand_host *host)
{
return host->devtype_data == &imx27_nand_devtype_data;
}
static inline int is_imx25_nfc(struct mxc_nand_host *host)
{
return host->devtype_data == &imx25_nand_devtype_data;
}
static inline int is_imx51_nfc(struct mxc_nand_host *host)
{
return host->devtype_data == &imx51_nand_devtype_data;
}
static inline int is_imx53_nfc(struct mxc_nand_host *host)
{
return host->devtype_data == &imx53_nand_devtype_data;
}
static int __init mxcnd_probe_dt(struct mxc_nand_host *host)
{
struct device_node *np = host->dev->of_node;
struct mxc_nand_platform_data *pdata = &host->pdata;
const struct of_device_id *of_id =
of_match_device(mxcnd_dt_ids, host->dev);
int buswidth;
if (!np)
return 1;
if (of_get_nand_ecc_mode(np) >= 0)
pdata->hw_ecc = 1;
pdata->flash_bbt = of_get_nand_on_flash_bbt(np);
buswidth = of_get_nand_bus_width(np);
if (buswidth < 0)
return buswidth;
pdata->width = buswidth / 8;
host->devtype_data = of_id->data;
return 0;
}
static int __init mxcnd_probe_dt(struct mxc_nand_host *host)
{
return 1;
}
static int mxcnd_probe(struct platform_device *pdev)
{
struct nand_chip *this;
struct mtd_info *mtd;
struct mxc_nand_host *host;
struct resource *res;
int err = 0;
host = devm_kzalloc(&pdev->dev, sizeof(struct mxc_nand_host),
GFP_KERNEL);
if (!host)
return -ENOMEM;
host->data_buf = devm_kzalloc(&pdev->dev, PAGE_SIZE, GFP_KERNEL);
if (!host->data_buf)
return -ENOMEM;
host->dev = &pdev->dev;
this = &host->nand;
mtd = &host->mtd;
mtd->priv = this;
mtd->owner = THIS_MODULE;
mtd->dev.parent = &pdev->dev;
mtd->name = DRIVER_NAME;
this->chip_delay = 5;
this->priv = host;
this->dev_ready = mxc_nand_dev_ready;
this->cmdfunc = mxc_nand_command;
this->read_byte = mxc_nand_read_byte;
this->read_word = mxc_nand_read_word;
this->write_buf = mxc_nand_write_buf;
this->read_buf = mxc_nand_read_buf;
host->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(host->clk))
return PTR_ERR(host->clk);
err = mxcnd_probe_dt(host);
if (err > 0) {
struct mxc_nand_platform_data *pdata =
dev_get_platdata(&pdev->dev);
if (pdata) {
host->pdata = *pdata;
host->devtype_data = (struct mxc_nand_devtype_data *)
pdev->id_entry->driver_data;
} else {
err = -ENODEV;
}
}
if (err < 0)
return err;
if (host->devtype_data->needs_ip) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->regs_ip = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->regs_ip))
return PTR_ERR(host->regs_ip);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
} else {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
}
host->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->base))
return PTR_ERR(host->base);
host->main_area0 = host->base;
if (host->devtype_data->regs_offset)
host->regs = host->base + host->devtype_data->regs_offset;
host->spare0 = host->base + host->devtype_data->spare0_offset;
if (host->devtype_data->axi_offset)
host->regs_axi = host->base + host->devtype_data->axi_offset;
this->ecc.bytes = host->devtype_data->eccbytes;
host->eccsize = host->devtype_data->eccsize;
this->select_chip = host->devtype_data->select_chip;
this->ecc.size = 512;
this->ecc.layout = host->devtype_data->ecclayout_512;
if (host->pdata.hw_ecc) {
this->ecc.calculate = mxc_nand_calculate_ecc;
this->ecc.hwctl = mxc_nand_enable_hwecc;
this->ecc.correct = host->devtype_data->correct_data;
this->ecc.mode = NAND_ECC_HW;
} else {
this->ecc.mode = NAND_ECC_SOFT;
}
if (host->pdata.width == 2)
this->options |= NAND_BUSWIDTH_16;
if (host->pdata.flash_bbt) {
this->bbt_td = &bbt_main_descr;
this->bbt_md = &bbt_mirror_descr;
this->bbt_options |= NAND_BBT_USE_FLASH;
}
init_completion(&host->op_completion);
host->irq = platform_get_irq(pdev, 0);
if (host->irq < 0)
return host->irq;
host->devtype_data->irq_control(host, 0);
err = devm_request_irq(&pdev->dev, host->irq, mxc_nfc_irq,
0, DRIVER_NAME, host);
if (err)
return err;
err = clk_prepare_enable(host->clk);
if (err)
return err;
host->clk_act = 1;
if (host->devtype_data->irqpending_quirk) {
disable_irq_nosync(host->irq);
host->devtype_data->irq_control(host, 1);
}
if (nand_scan_ident(mtd, is_imx25_nfc(host) ? 4 : 1, NULL)) {
err = -ENXIO;
goto escan;
}
devm_kfree(&pdev->dev, (void *)host->data_buf);
host->data_buf = devm_kzalloc(&pdev->dev, mtd->writesize + mtd->oobsize,
GFP_KERNEL);
if (!host->data_buf) {
err = -ENOMEM;
goto escan;
}
host->devtype_data->preset(mtd);
if (mtd->writesize == 2048)
this->ecc.layout = host->devtype_data->ecclayout_2k;
else if (mtd->writesize == 4096) {
this->ecc.layout = host->devtype_data->ecclayout_4k;
if (get_eccsize(mtd) == 8)
ecc_8bit_layout_4k(this->ecc.layout);
}
host->used_oobsize = min(mtd->oobsize, 218U);
if (this->ecc.mode == NAND_ECC_HW) {
if (is_imx21_nfc(host) || is_imx27_nfc(host))
this->ecc.strength = 1;
else
this->ecc.strength = (host->eccsize == 4) ? 4 : 8;
}
if (nand_scan_tail(mtd)) {
err = -ENXIO;
goto escan;
}
mtd_device_parse_register(mtd, part_probes,
&(struct mtd_part_parser_data){
.of_node = pdev->dev.of_node,
},
host->pdata.parts,
host->pdata.nr_parts);
platform_set_drvdata(pdev, host);
return 0;
escan:
if (host->clk_act)
clk_disable_unprepare(host->clk);
return err;
}
static int mxcnd_remove(struct platform_device *pdev)
{
struct mxc_nand_host *host = platform_get_drvdata(pdev);
nand_release(&host->mtd);
if (host->clk_act)
clk_disable_unprepare(host->clk);
return 0;
}
