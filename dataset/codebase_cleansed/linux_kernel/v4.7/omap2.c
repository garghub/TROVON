static inline struct omap_nand_info *mtd_to_omap(struct mtd_info *mtd)
{
return container_of(mtd_to_nand(mtd), struct omap_nand_info, nand);
}
static int omap_prefetch_enable(int cs, int fifo_th, int dma_mode,
unsigned int u32_count, int is_write, struct omap_nand_info *info)
{
u32 val;
if (fifo_th > PREFETCH_FIFOTHRESHOLD_MAX)
return -1;
if (readl(info->reg.gpmc_prefetch_control))
return -EBUSY;
writel(u32_count, info->reg.gpmc_prefetch_config2);
val = ((cs << PREFETCH_CONFIG1_CS_SHIFT) |
PREFETCH_FIFOTHRESHOLD(fifo_th) | ENABLE_PREFETCH |
(dma_mode << DMA_MPU_MODE_SHIFT) | (is_write & 0x1));
writel(val, info->reg.gpmc_prefetch_config1);
writel(0x1, info->reg.gpmc_prefetch_control);
return 0;
}
static int omap_prefetch_reset(int cs, struct omap_nand_info *info)
{
u32 config1;
config1 = readl(info->reg.gpmc_prefetch_config1);
if (((config1 >> PREFETCH_CONFIG1_CS_SHIFT) & CS_MASK) != cs)
return -EINVAL;
writel(0x0, info->reg.gpmc_prefetch_control);
writel(0x0, info->reg.gpmc_prefetch_config1);
return 0;
}
static void omap_hwcontrol(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
if (cmd != NAND_CMD_NONE) {
if (ctrl & NAND_CLE)
writeb(cmd, info->reg.gpmc_nand_command);
else if (ctrl & NAND_ALE)
writeb(cmd, info->reg.gpmc_nand_address);
else
writeb(cmd, info->reg.gpmc_nand_data);
}
}
static void omap_read_buf8(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *nand = mtd_to_nand(mtd);
ioread8_rep(nand->IO_ADDR_R, buf, len);
}
static void omap_write_buf8(struct mtd_info *mtd, const u_char *buf, int len)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
u_char *p = (u_char *)buf;
bool status;
while (len--) {
iowrite8(*p++, info->nand.IO_ADDR_W);
do {
status = info->ops->nand_writebuffer_empty();
} while (!status);
}
}
static void omap_read_buf16(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *nand = mtd_to_nand(mtd);
ioread16_rep(nand->IO_ADDR_R, buf, len / 2);
}
static void omap_write_buf16(struct mtd_info *mtd, const u_char * buf, int len)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
u16 *p = (u16 *) buf;
bool status;
len >>= 1;
while (len--) {
iowrite16(*p++, info->nand.IO_ADDR_W);
do {
status = info->ops->nand_writebuffer_empty();
} while (!status);
}
}
static void omap_read_buf_pref(struct mtd_info *mtd, u_char *buf, int len)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
uint32_t r_count = 0;
int ret = 0;
u32 *p = (u32 *)buf;
if (len % 4) {
if (info->nand.options & NAND_BUSWIDTH_16)
omap_read_buf16(mtd, buf, len % 4);
else
omap_read_buf8(mtd, buf, len % 4);
p = (u32 *) (buf + len % 4);
len -= len % 4;
}
ret = omap_prefetch_enable(info->gpmc_cs,
PREFETCH_FIFOTHRESHOLD_MAX, 0x0, len, 0x0, info);
if (ret) {
if (info->nand.options & NAND_BUSWIDTH_16)
omap_read_buf16(mtd, (u_char *)p, len);
else
omap_read_buf8(mtd, (u_char *)p, len);
} else {
do {
r_count = readl(info->reg.gpmc_prefetch_status);
r_count = PREFETCH_STATUS_FIFO_CNT(r_count);
r_count = r_count >> 2;
ioread32_rep(info->nand.IO_ADDR_R, p, r_count);
p += r_count;
len -= r_count << 2;
} while (len);
omap_prefetch_reset(info->gpmc_cs, info);
}
}
static void omap_write_buf_pref(struct mtd_info *mtd,
const u_char *buf, int len)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
uint32_t w_count = 0;
int i = 0, ret = 0;
u16 *p = (u16 *)buf;
unsigned long tim, limit;
u32 val;
if (len % 2 != 0) {
writeb(*buf, info->nand.IO_ADDR_W);
p = (u16 *)(buf + 1);
len--;
}
ret = omap_prefetch_enable(info->gpmc_cs,
PREFETCH_FIFOTHRESHOLD_MAX, 0x0, len, 0x1, info);
if (ret) {
if (info->nand.options & NAND_BUSWIDTH_16)
omap_write_buf16(mtd, (u_char *)p, len);
else
omap_write_buf8(mtd, (u_char *)p, len);
} else {
while (len) {
w_count = readl(info->reg.gpmc_prefetch_status);
w_count = PREFETCH_STATUS_FIFO_CNT(w_count);
w_count = w_count >> 1;
for (i = 0; (i < w_count) && len; i++, len -= 2)
iowrite16(*p++, info->nand.IO_ADDR_W);
}
tim = 0;
limit = (loops_per_jiffy *
msecs_to_jiffies(OMAP_NAND_TIMEOUT_MS));
do {
cpu_relax();
val = readl(info->reg.gpmc_prefetch_status);
val = PREFETCH_STATUS_COUNT(val);
} while (val && (tim++ < limit));
omap_prefetch_reset(info->gpmc_cs, info);
}
}
static void omap_nand_dma_callback(void *data)
{
complete((struct completion *) data);
}
static inline int omap_nand_dma_transfer(struct mtd_info *mtd, void *addr,
unsigned int len, int is_write)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
struct dma_async_tx_descriptor *tx;
enum dma_data_direction dir = is_write ? DMA_TO_DEVICE :
DMA_FROM_DEVICE;
struct scatterlist sg;
unsigned long tim, limit;
unsigned n;
int ret;
u32 val;
if (!virt_addr_valid(addr))
goto out_copy;
sg_init_one(&sg, addr, len);
n = dma_map_sg(info->dma->device->dev, &sg, 1, dir);
if (n == 0) {
dev_err(&info->pdev->dev,
"Couldn't DMA map a %d byte buffer\n", len);
goto out_copy;
}
tx = dmaengine_prep_slave_sg(info->dma, &sg, n,
is_write ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!tx)
goto out_copy_unmap;
tx->callback = omap_nand_dma_callback;
tx->callback_param = &info->comp;
dmaengine_submit(tx);
init_completion(&info->comp);
dma_async_issue_pending(info->dma);
ret = omap_prefetch_enable(info->gpmc_cs,
PREFETCH_FIFOTHRESHOLD_MAX, 0x1, len, is_write, info);
if (ret)
goto out_copy_unmap;
wait_for_completion(&info->comp);
tim = 0;
limit = (loops_per_jiffy * msecs_to_jiffies(OMAP_NAND_TIMEOUT_MS));
do {
cpu_relax();
val = readl(info->reg.gpmc_prefetch_status);
val = PREFETCH_STATUS_COUNT(val);
} while (val && (tim++ < limit));
omap_prefetch_reset(info->gpmc_cs, info);
dma_unmap_sg(info->dma->device->dev, &sg, 1, dir);
return 0;
out_copy_unmap:
dma_unmap_sg(info->dma->device->dev, &sg, 1, dir);
out_copy:
if (info->nand.options & NAND_BUSWIDTH_16)
is_write == 0 ? omap_read_buf16(mtd, (u_char *) addr, len)
: omap_write_buf16(mtd, (u_char *) addr, len);
else
is_write == 0 ? omap_read_buf8(mtd, (u_char *) addr, len)
: omap_write_buf8(mtd, (u_char *) addr, len);
return 0;
}
static void omap_read_buf_dma_pref(struct mtd_info *mtd, u_char *buf, int len)
{
if (len <= mtd->oobsize)
omap_read_buf_pref(mtd, buf, len);
else
omap_nand_dma_transfer(mtd, buf, len, 0x0);
}
static void omap_write_buf_dma_pref(struct mtd_info *mtd,
const u_char *buf, int len)
{
if (len <= mtd->oobsize)
omap_write_buf_pref(mtd, buf, len);
else
omap_nand_dma_transfer(mtd, (u_char *) buf, len, 0x1);
}
static irqreturn_t omap_nand_irq(int this_irq, void *dev)
{
struct omap_nand_info *info = (struct omap_nand_info *) dev;
u32 bytes;
bytes = readl(info->reg.gpmc_prefetch_status);
bytes = PREFETCH_STATUS_FIFO_CNT(bytes);
bytes = bytes & 0xFFFC;
if (info->iomode == OMAP_NAND_IO_WRITE) {
if (this_irq == info->gpmc_irq_count)
goto done;
if (info->buf_len && (info->buf_len < bytes))
bytes = info->buf_len;
else if (!info->buf_len)
bytes = 0;
iowrite32_rep(info->nand.IO_ADDR_W,
(u32 *)info->buf, bytes >> 2);
info->buf = info->buf + bytes;
info->buf_len -= bytes;
} else {
ioread32_rep(info->nand.IO_ADDR_R,
(u32 *)info->buf, bytes >> 2);
info->buf = info->buf + bytes;
if (this_irq == info->gpmc_irq_count)
goto done;
}
return IRQ_HANDLED;
done:
complete(&info->comp);
disable_irq_nosync(info->gpmc_irq_fifo);
disable_irq_nosync(info->gpmc_irq_count);
return IRQ_HANDLED;
}
static void omap_read_buf_irq_pref(struct mtd_info *mtd, u_char *buf, int len)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
int ret = 0;
if (len <= mtd->oobsize) {
omap_read_buf_pref(mtd, buf, len);
return;
}
info->iomode = OMAP_NAND_IO_READ;
info->buf = buf;
init_completion(&info->comp);
ret = omap_prefetch_enable(info->gpmc_cs,
PREFETCH_FIFOTHRESHOLD_MAX/2, 0x0, len, 0x0, info);
if (ret)
goto out_copy;
info->buf_len = len;
enable_irq(info->gpmc_irq_count);
enable_irq(info->gpmc_irq_fifo);
wait_for_completion(&info->comp);
omap_prefetch_reset(info->gpmc_cs, info);
return;
out_copy:
if (info->nand.options & NAND_BUSWIDTH_16)
omap_read_buf16(mtd, buf, len);
else
omap_read_buf8(mtd, buf, len);
}
static void omap_write_buf_irq_pref(struct mtd_info *mtd,
const u_char *buf, int len)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
int ret = 0;
unsigned long tim, limit;
u32 val;
if (len <= mtd->oobsize) {
omap_write_buf_pref(mtd, buf, len);
return;
}
info->iomode = OMAP_NAND_IO_WRITE;
info->buf = (u_char *) buf;
init_completion(&info->comp);
ret = omap_prefetch_enable(info->gpmc_cs,
(PREFETCH_FIFOTHRESHOLD_MAX * 3) / 8, 0x0, len, 0x1, info);
if (ret)
goto out_copy;
info->buf_len = len;
enable_irq(info->gpmc_irq_count);
enable_irq(info->gpmc_irq_fifo);
wait_for_completion(&info->comp);
tim = 0;
limit = (loops_per_jiffy * msecs_to_jiffies(OMAP_NAND_TIMEOUT_MS));
do {
val = readl(info->reg.gpmc_prefetch_status);
val = PREFETCH_STATUS_COUNT(val);
cpu_relax();
} while (val && (tim++ < limit));
omap_prefetch_reset(info->gpmc_cs, info);
return;
out_copy:
if (info->nand.options & NAND_BUSWIDTH_16)
omap_write_buf16(mtd, buf, len);
else
omap_write_buf8(mtd, buf, len);
}
static void gen_true_ecc(u8 *ecc_buf)
{
u32 tmp = ecc_buf[0] | (ecc_buf[1] << 16) |
((ecc_buf[2] & 0xF0) << 20) | ((ecc_buf[2] & 0x0F) << 8);
ecc_buf[0] = ~(P64o(tmp) | P64e(tmp) | P32o(tmp) | P32e(tmp) |
P16o(tmp) | P16e(tmp) | P8o(tmp) | P8e(tmp));
ecc_buf[1] = ~(P1024o(tmp) | P1024e(tmp) | P512o(tmp) | P512e(tmp) |
P256o(tmp) | P256e(tmp) | P128o(tmp) | P128e(tmp));
ecc_buf[2] = ~(P4o(tmp) | P4e(tmp) | P2o(tmp) | P2e(tmp) | P1o(tmp) |
P1e(tmp) | P2048o(tmp) | P2048e(tmp));
}
static int omap_compare_ecc(u8 *ecc_data1,
u8 *ecc_data2,
u8 *page_data)
{
uint i;
u8 tmp0_bit[8], tmp1_bit[8], tmp2_bit[8];
u8 comp0_bit[8], comp1_bit[8], comp2_bit[8];
u8 ecc_bit[24];
u8 ecc_sum = 0;
u8 find_bit = 0;
uint find_byte = 0;
int isEccFF;
isEccFF = ((*(u32 *)ecc_data1 & 0xFFFFFF) == 0xFFFFFF);
gen_true_ecc(ecc_data1);
gen_true_ecc(ecc_data2);
for (i = 0; i <= 2; i++) {
*(ecc_data1 + i) = ~(*(ecc_data1 + i));
*(ecc_data2 + i) = ~(*(ecc_data2 + i));
}
for (i = 0; i < 8; i++) {
tmp0_bit[i] = *ecc_data1 % 2;
*ecc_data1 = *ecc_data1 / 2;
}
for (i = 0; i < 8; i++) {
tmp1_bit[i] = *(ecc_data1 + 1) % 2;
*(ecc_data1 + 1) = *(ecc_data1 + 1) / 2;
}
for (i = 0; i < 8; i++) {
tmp2_bit[i] = *(ecc_data1 + 2) % 2;
*(ecc_data1 + 2) = *(ecc_data1 + 2) / 2;
}
for (i = 0; i < 8; i++) {
comp0_bit[i] = *ecc_data2 % 2;
*ecc_data2 = *ecc_data2 / 2;
}
for (i = 0; i < 8; i++) {
comp1_bit[i] = *(ecc_data2 + 1) % 2;
*(ecc_data2 + 1) = *(ecc_data2 + 1) / 2;
}
for (i = 0; i < 8; i++) {
comp2_bit[i] = *(ecc_data2 + 2) % 2;
*(ecc_data2 + 2) = *(ecc_data2 + 2) / 2;
}
for (i = 0; i < 6; i++)
ecc_bit[i] = tmp2_bit[i + 2] ^ comp2_bit[i + 2];
for (i = 0; i < 8; i++)
ecc_bit[i + 6] = tmp0_bit[i] ^ comp0_bit[i];
for (i = 0; i < 8; i++)
ecc_bit[i + 14] = tmp1_bit[i] ^ comp1_bit[i];
ecc_bit[22] = tmp2_bit[0] ^ comp2_bit[0];
ecc_bit[23] = tmp2_bit[1] ^ comp2_bit[1];
for (i = 0; i < 24; i++)
ecc_sum += ecc_bit[i];
switch (ecc_sum) {
case 0:
return 0;
case 1:
pr_debug("ECC UNCORRECTED_ERROR 1\n");
return -EBADMSG;
case 11:
pr_debug("ECC UNCORRECTED_ERROR B\n");
return -EBADMSG;
case 12:
find_byte = (ecc_bit[23] << 8) +
(ecc_bit[21] << 7) +
(ecc_bit[19] << 6) +
(ecc_bit[17] << 5) +
(ecc_bit[15] << 4) +
(ecc_bit[13] << 3) +
(ecc_bit[11] << 2) +
(ecc_bit[9] << 1) +
ecc_bit[7];
find_bit = (ecc_bit[5] << 2) + (ecc_bit[3] << 1) + ecc_bit[1];
pr_debug("Correcting single bit ECC error at offset: "
"%d, bit: %d\n", find_byte, find_bit);
page_data[find_byte] ^= (1 << find_bit);
return 1;
default:
if (isEccFF) {
if (ecc_data2[0] == 0 &&
ecc_data2[1] == 0 &&
ecc_data2[2] == 0)
return 0;
}
pr_debug("UNCORRECTED_ERROR default\n");
return -EBADMSG;
}
}
static int omap_correct_data(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
int blockCnt = 0, i = 0, ret = 0;
int stat = 0;
if ((info->nand.ecc.mode == NAND_ECC_HW) &&
(info->nand.ecc.size == 2048))
blockCnt = 4;
else
blockCnt = 1;
for (i = 0; i < blockCnt; i++) {
if (memcmp(read_ecc, calc_ecc, 3) != 0) {
ret = omap_compare_ecc(read_ecc, calc_ecc, dat);
if (ret < 0)
return ret;
stat += ret;
}
read_ecc += 3;
calc_ecc += 3;
dat += 512;
}
return stat;
}
static int omap_calculate_ecc(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
u32 val;
val = readl(info->reg.gpmc_ecc_config);
if (((val >> ECC_CONFIG_CS_SHIFT) & CS_MASK) != info->gpmc_cs)
return -EINVAL;
val = readl(info->reg.gpmc_ecc1_result);
*ecc_code++ = val;
*ecc_code++ = val >> 16;
*ecc_code++ = ((val >> 8) & 0x0f) | ((val >> 20) & 0xf0);
return 0;
}
static void omap_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
struct nand_chip *chip = mtd_to_nand(mtd);
unsigned int dev_width = (chip->options & NAND_BUSWIDTH_16) ? 1 : 0;
u32 val;
val = ECCCLEAR | ECC1;
writel(val, info->reg.gpmc_ecc_control);
val = ((((info->nand.ecc.size >> 1) - 1) << ECCSIZE1_SHIFT) |
ECC1RESULTSIZE);
writel(val, info->reg.gpmc_ecc_size_config);
switch (mode) {
case NAND_ECC_READ:
case NAND_ECC_WRITE:
writel(ECCCLEAR | ECC1, info->reg.gpmc_ecc_control);
break;
case NAND_ECC_READSYN:
writel(ECCCLEAR, info->reg.gpmc_ecc_control);
break;
default:
dev_info(&info->pdev->dev,
"error: unrecognized Mode[%d]!\n", mode);
break;
}
val = (dev_width << 7) | (info->gpmc_cs << 1) | (0x1);
writel(val, info->reg.gpmc_ecc_config);
}
static int omap_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
struct nand_chip *this = mtd_to_nand(mtd);
struct omap_nand_info *info = mtd_to_omap(mtd);
unsigned long timeo = jiffies;
int status, state = this->state;
if (state == FL_ERASING)
timeo += msecs_to_jiffies(400);
else
timeo += msecs_to_jiffies(20);
writeb(NAND_CMD_STATUS & 0xFF, info->reg.gpmc_nand_command);
while (time_before(jiffies, timeo)) {
status = readb(info->reg.gpmc_nand_data);
if (status & NAND_STATUS_READY)
break;
cond_resched();
}
status = readb(info->reg.gpmc_nand_data);
return status;
}
static int omap_dev_ready(struct mtd_info *mtd)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
return gpiod_get_value(info->ready_gpiod);
}
static void __maybe_unused omap_enable_hwecc_bch(struct mtd_info *mtd, int mode)
{
unsigned int bch_type;
unsigned int dev_width, nsectors;
struct omap_nand_info *info = mtd_to_omap(mtd);
enum omap_ecc ecc_opt = info->ecc_opt;
struct nand_chip *chip = mtd_to_nand(mtd);
u32 val, wr_mode;
unsigned int ecc_size1, ecc_size0;
switch (ecc_opt) {
case OMAP_ECC_BCH4_CODE_HW_DETECTION_SW:
bch_type = 0;
nsectors = 1;
wr_mode = BCH_WRAPMODE_6;
ecc_size0 = BCH_ECC_SIZE0;
ecc_size1 = BCH_ECC_SIZE1;
break;
case OMAP_ECC_BCH4_CODE_HW:
bch_type = 0;
nsectors = chip->ecc.steps;
if (mode == NAND_ECC_READ) {
wr_mode = BCH_WRAPMODE_1;
ecc_size0 = BCH4R_ECC_SIZE0;
ecc_size1 = BCH4R_ECC_SIZE1;
} else {
wr_mode = BCH_WRAPMODE_6;
ecc_size0 = BCH_ECC_SIZE0;
ecc_size1 = BCH_ECC_SIZE1;
}
break;
case OMAP_ECC_BCH8_CODE_HW_DETECTION_SW:
bch_type = 1;
nsectors = 1;
wr_mode = BCH_WRAPMODE_6;
ecc_size0 = BCH_ECC_SIZE0;
ecc_size1 = BCH_ECC_SIZE1;
break;
case OMAP_ECC_BCH8_CODE_HW:
bch_type = 1;
nsectors = chip->ecc.steps;
if (mode == NAND_ECC_READ) {
wr_mode = BCH_WRAPMODE_1;
ecc_size0 = BCH8R_ECC_SIZE0;
ecc_size1 = BCH8R_ECC_SIZE1;
} else {
wr_mode = BCH_WRAPMODE_6;
ecc_size0 = BCH_ECC_SIZE0;
ecc_size1 = BCH_ECC_SIZE1;
}
break;
case OMAP_ECC_BCH16_CODE_HW:
bch_type = 0x2;
nsectors = chip->ecc.steps;
if (mode == NAND_ECC_READ) {
wr_mode = 0x01;
ecc_size0 = 52;
ecc_size1 = 0;
} else {
wr_mode = 0x01;
ecc_size0 = 0;
ecc_size1 = 52;
}
break;
default:
return;
}
writel(ECC1, info->reg.gpmc_ecc_control);
val = (ecc_size1 << ECCSIZE1_SHIFT) | (ecc_size0 << ECCSIZE0_SHIFT);
writel(val, info->reg.gpmc_ecc_size_config);
dev_width = (chip->options & NAND_BUSWIDTH_16) ? 1 : 0;
val = ((1 << 16) |
(bch_type << 12) |
(wr_mode << 8) |
(dev_width << 7) |
(((nsectors-1) & 0x7) << 4) |
(info->gpmc_cs << 1) |
(0x1));
writel(val, info->reg.gpmc_ecc_config);
writel(ECCCLEAR | ECC1, info->reg.gpmc_ecc_control);
}
static int __maybe_unused omap_calculate_ecc_bch(struct mtd_info *mtd,
const u_char *dat, u_char *ecc_calc)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
int eccbytes = info->nand.ecc.bytes;
struct gpmc_nand_regs *gpmc_regs = &info->reg;
u8 *ecc_code;
unsigned long nsectors, bch_val1, bch_val2, bch_val3, bch_val4;
u32 val;
int i, j;
nsectors = ((readl(info->reg.gpmc_ecc_config) >> 4) & 0x7) + 1;
for (i = 0; i < nsectors; i++) {
ecc_code = ecc_calc;
switch (info->ecc_opt) {
case OMAP_ECC_BCH8_CODE_HW_DETECTION_SW:
case OMAP_ECC_BCH8_CODE_HW:
bch_val1 = readl(gpmc_regs->gpmc_bch_result0[i]);
bch_val2 = readl(gpmc_regs->gpmc_bch_result1[i]);
bch_val3 = readl(gpmc_regs->gpmc_bch_result2[i]);
bch_val4 = readl(gpmc_regs->gpmc_bch_result3[i]);
*ecc_code++ = (bch_val4 & 0xFF);
*ecc_code++ = ((bch_val3 >> 24) & 0xFF);
*ecc_code++ = ((bch_val3 >> 16) & 0xFF);
*ecc_code++ = ((bch_val3 >> 8) & 0xFF);
*ecc_code++ = (bch_val3 & 0xFF);
*ecc_code++ = ((bch_val2 >> 24) & 0xFF);
*ecc_code++ = ((bch_val2 >> 16) & 0xFF);
*ecc_code++ = ((bch_val2 >> 8) & 0xFF);
*ecc_code++ = (bch_val2 & 0xFF);
*ecc_code++ = ((bch_val1 >> 24) & 0xFF);
*ecc_code++ = ((bch_val1 >> 16) & 0xFF);
*ecc_code++ = ((bch_val1 >> 8) & 0xFF);
*ecc_code++ = (bch_val1 & 0xFF);
break;
case OMAP_ECC_BCH4_CODE_HW_DETECTION_SW:
case OMAP_ECC_BCH4_CODE_HW:
bch_val1 = readl(gpmc_regs->gpmc_bch_result0[i]);
bch_val2 = readl(gpmc_regs->gpmc_bch_result1[i]);
*ecc_code++ = ((bch_val2 >> 12) & 0xFF);
*ecc_code++ = ((bch_val2 >> 4) & 0xFF);
*ecc_code++ = ((bch_val2 & 0xF) << 4) |
((bch_val1 >> 28) & 0xF);
*ecc_code++ = ((bch_val1 >> 20) & 0xFF);
*ecc_code++ = ((bch_val1 >> 12) & 0xFF);
*ecc_code++ = ((bch_val1 >> 4) & 0xFF);
*ecc_code++ = ((bch_val1 & 0xF) << 4);
break;
case OMAP_ECC_BCH16_CODE_HW:
val = readl(gpmc_regs->gpmc_bch_result6[i]);
ecc_code[0] = ((val >> 8) & 0xFF);
ecc_code[1] = ((val >> 0) & 0xFF);
val = readl(gpmc_regs->gpmc_bch_result5[i]);
ecc_code[2] = ((val >> 24) & 0xFF);
ecc_code[3] = ((val >> 16) & 0xFF);
ecc_code[4] = ((val >> 8) & 0xFF);
ecc_code[5] = ((val >> 0) & 0xFF);
val = readl(gpmc_regs->gpmc_bch_result4[i]);
ecc_code[6] = ((val >> 24) & 0xFF);
ecc_code[7] = ((val >> 16) & 0xFF);
ecc_code[8] = ((val >> 8) & 0xFF);
ecc_code[9] = ((val >> 0) & 0xFF);
val = readl(gpmc_regs->gpmc_bch_result3[i]);
ecc_code[10] = ((val >> 24) & 0xFF);
ecc_code[11] = ((val >> 16) & 0xFF);
ecc_code[12] = ((val >> 8) & 0xFF);
ecc_code[13] = ((val >> 0) & 0xFF);
val = readl(gpmc_regs->gpmc_bch_result2[i]);
ecc_code[14] = ((val >> 24) & 0xFF);
ecc_code[15] = ((val >> 16) & 0xFF);
ecc_code[16] = ((val >> 8) & 0xFF);
ecc_code[17] = ((val >> 0) & 0xFF);
val = readl(gpmc_regs->gpmc_bch_result1[i]);
ecc_code[18] = ((val >> 24) & 0xFF);
ecc_code[19] = ((val >> 16) & 0xFF);
ecc_code[20] = ((val >> 8) & 0xFF);
ecc_code[21] = ((val >> 0) & 0xFF);
val = readl(gpmc_regs->gpmc_bch_result0[i]);
ecc_code[22] = ((val >> 24) & 0xFF);
ecc_code[23] = ((val >> 16) & 0xFF);
ecc_code[24] = ((val >> 8) & 0xFF);
ecc_code[25] = ((val >> 0) & 0xFF);
break;
default:
return -EINVAL;
}
switch (info->ecc_opt) {
case OMAP_ECC_BCH4_CODE_HW_DETECTION_SW:
for (j = 0; j < eccbytes; j++)
ecc_calc[j] ^= bch4_polynomial[j];
break;
case OMAP_ECC_BCH4_CODE_HW:
ecc_calc[eccbytes - 1] = 0x0;
break;
case OMAP_ECC_BCH8_CODE_HW_DETECTION_SW:
for (j = 0; j < eccbytes; j++)
ecc_calc[j] ^= bch8_polynomial[j];
break;
case OMAP_ECC_BCH8_CODE_HW:
ecc_calc[eccbytes - 1] = 0x0;
break;
case OMAP_ECC_BCH16_CODE_HW:
break;
default:
return -EINVAL;
}
ecc_calc += eccbytes;
}
return 0;
}
static int erased_sector_bitflips(u_char *data, u_char *oob,
struct omap_nand_info *info)
{
int flip_bits = 0, i;
for (i = 0; i < info->nand.ecc.size; i++) {
flip_bits += hweight8(~data[i]);
if (flip_bits > info->nand.ecc.strength)
return 0;
}
for (i = 0; i < info->nand.ecc.bytes - 1; i++) {
flip_bits += hweight8(~oob[i]);
if (flip_bits > info->nand.ecc.strength)
return 0;
}
if (flip_bits) {
memset(data, 0xFF, info->nand.ecc.size);
memset(oob, 0xFF, info->nand.ecc.bytes);
}
return flip_bits;
}
static int omap_elm_correct_data(struct mtd_info *mtd, u_char *data,
u_char *read_ecc, u_char *calc_ecc)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
struct nand_ecc_ctrl *ecc = &info->nand.ecc;
int eccsteps = info->nand.ecc.steps;
int i , j, stat = 0;
int eccflag, actual_eccbytes;
struct elm_errorvec err_vec[ERROR_VECTOR_MAX];
u_char *ecc_vec = calc_ecc;
u_char *spare_ecc = read_ecc;
u_char *erased_ecc_vec;
u_char *buf;
int bitflip_count;
bool is_error_reported = false;
u32 bit_pos, byte_pos, error_max, pos;
int err;
switch (info->ecc_opt) {
case OMAP_ECC_BCH4_CODE_HW:
actual_eccbytes = ecc->bytes - 1;
erased_ecc_vec = bch4_vector;
break;
case OMAP_ECC_BCH8_CODE_HW:
actual_eccbytes = ecc->bytes - 1;
erased_ecc_vec = bch8_vector;
break;
case OMAP_ECC_BCH16_CODE_HW:
actual_eccbytes = ecc->bytes;
erased_ecc_vec = bch16_vector;
break;
default:
dev_err(&info->pdev->dev, "invalid driver configuration\n");
return -EINVAL;
}
memset(err_vec, 0, sizeof(err_vec));
for (i = 0; i < eccsteps ; i++) {
eccflag = 0;
for (j = 0; j < actual_eccbytes; j++) {
if (calc_ecc[j] != 0) {
eccflag = 1;
break;
}
}
if (eccflag == 1) {
if (memcmp(calc_ecc, erased_ecc_vec,
actual_eccbytes) == 0) {
} else {
buf = &data[info->nand.ecc.size * i];
bitflip_count = erased_sector_bitflips(
buf, read_ecc, info);
if (bitflip_count) {
stat += bitflip_count;
} else {
err_vec[i].error_reported = true;
is_error_reported = true;
}
}
}
calc_ecc += ecc->bytes;
read_ecc += ecc->bytes;
}
if (!is_error_reported)
return stat;
elm_decode_bch_error_page(info->elm_dev, ecc_vec, err_vec);
err = 0;
for (i = 0; i < eccsteps; i++) {
if (err_vec[i].error_uncorrectable) {
dev_err(&info->pdev->dev,
"uncorrectable bit-flips found\n");
err = -EBADMSG;
} else if (err_vec[i].error_reported) {
for (j = 0; j < err_vec[i].error_count; j++) {
switch (info->ecc_opt) {
case OMAP_ECC_BCH4_CODE_HW:
pos = err_vec[i].error_loc[j] +
BCH4_BIT_PAD;
break;
case OMAP_ECC_BCH8_CODE_HW:
case OMAP_ECC_BCH16_CODE_HW:
pos = err_vec[i].error_loc[j];
break;
default:
return -EINVAL;
}
error_max = (ecc->size + actual_eccbytes) * 8;
bit_pos = pos % 8;
byte_pos = (error_max - pos - 1) / 8;
if (pos < error_max) {
if (byte_pos < 512) {
pr_debug("bitflip@dat[%d]=%x\n",
byte_pos, data[byte_pos]);
data[byte_pos] ^= 1 << bit_pos;
} else {
pr_debug("bitflip@oob[%d]=%x\n",
(byte_pos - 512),
spare_ecc[byte_pos - 512]);
spare_ecc[byte_pos - 512] ^=
1 << bit_pos;
}
} else {
dev_err(&info->pdev->dev,
"invalid bit-flip @ %d:%d\n",
byte_pos, bit_pos);
err = -EBADMSG;
}
}
}
stat += err_vec[i].error_count;
data += ecc->size;
spare_ecc += ecc->bytes;
}
return (err) ? err : stat;
}
static int omap_write_page_bch(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required, int page)
{
int ret;
uint8_t *ecc_calc = chip->buffers->ecccalc;
chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
chip->write_buf(mtd, buf, mtd->writesize);
chip->ecc.calculate(mtd, buf, &ecc_calc[0]);
ret = mtd_ooblayout_set_eccbytes(mtd, ecc_calc, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int omap_read_page_bch(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
uint8_t *ecc_calc = chip->buffers->ecccalc;
uint8_t *ecc_code = chip->buffers->ecccode;
int stat, ret;
unsigned int max_bitflips = 0;
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, buf, mtd->writesize);
chip->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + BADBLOCK_MARKER_LENGTH, -1);
chip->read_buf(mtd, chip->oob_poi + BADBLOCK_MARKER_LENGTH,
chip->ecc.total);
chip->ecc.calculate(mtd, buf, ecc_calc);
ret = mtd_ooblayout_get_eccbytes(mtd, ecc_code, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
stat = chip->ecc.correct(mtd, buf, ecc_code, ecc_calc);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
return max_bitflips;
}
static bool is_elm_present(struct omap_nand_info *info,
struct device_node *elm_node)
{
struct platform_device *pdev;
if (!elm_node) {
dev_err(&info->pdev->dev, "ELM devicetree node not found\n");
return false;
}
pdev = of_find_device_by_node(elm_node);
if (!pdev) {
dev_err(&info->pdev->dev, "ELM device not found\n");
return false;
}
info->elm_dev = &pdev->dev;
return true;
}
static bool omap2_nand_ecc_check(struct omap_nand_info *info,
struct omap_nand_platform_data *pdata)
{
bool ecc_needs_bch, ecc_needs_omap_bch, ecc_needs_elm;
switch (info->ecc_opt) {
case OMAP_ECC_BCH4_CODE_HW_DETECTION_SW:
case OMAP_ECC_BCH8_CODE_HW_DETECTION_SW:
ecc_needs_omap_bch = false;
ecc_needs_bch = true;
ecc_needs_elm = false;
break;
case OMAP_ECC_BCH4_CODE_HW:
case OMAP_ECC_BCH8_CODE_HW:
case OMAP_ECC_BCH16_CODE_HW:
ecc_needs_omap_bch = true;
ecc_needs_bch = false;
ecc_needs_elm = true;
break;
default:
ecc_needs_omap_bch = false;
ecc_needs_bch = false;
ecc_needs_elm = false;
break;
}
if (ecc_needs_bch && !IS_ENABLED(CONFIG_MTD_NAND_ECC_BCH)) {
dev_err(&info->pdev->dev,
"CONFIG_MTD_NAND_ECC_BCH not enabled\n");
return false;
}
if (ecc_needs_omap_bch && !IS_ENABLED(CONFIG_MTD_NAND_OMAP_BCH)) {
dev_err(&info->pdev->dev,
"CONFIG_MTD_NAND_OMAP_BCH not enabled\n");
return false;
}
if (ecc_needs_elm && !is_elm_present(info, info->elm_of_node)) {
dev_err(&info->pdev->dev, "ELM not available\n");
return false;
}
return true;
}
static int omap_get_dt_info(struct device *dev, struct omap_nand_info *info)
{
struct device_node *child = dev->of_node;
int i;
const char *s;
u32 cs;
if (of_property_read_u32(child, "reg", &cs) < 0) {
dev_err(dev, "reg not found in DT\n");
return -EINVAL;
}
info->gpmc_cs = cs;
info->elm_of_node = of_parse_phandle(child, "ti,elm-id", 0);
if (!info->elm_of_node) {
info->elm_of_node = of_parse_phandle(child, "elm_id", 0);
if (!info->elm_of_node)
dev_dbg(dev, "ti,elm-id not in DT\n");
}
if (of_property_read_string(child, "ti,nand-ecc-opt", &s)) {
dev_err(dev, "ti,nand-ecc-opt not found\n");
return -EINVAL;
}
if (!strcmp(s, "sw")) {
info->ecc_opt = OMAP_ECC_HAM1_CODE_SW;
} else if (!strcmp(s, "ham1") ||
!strcmp(s, "hw") || !strcmp(s, "hw-romcode")) {
info->ecc_opt = OMAP_ECC_HAM1_CODE_HW;
} else if (!strcmp(s, "bch4")) {
if (info->elm_of_node)
info->ecc_opt = OMAP_ECC_BCH4_CODE_HW;
else
info->ecc_opt = OMAP_ECC_BCH4_CODE_HW_DETECTION_SW;
} else if (!strcmp(s, "bch8")) {
if (info->elm_of_node)
info->ecc_opt = OMAP_ECC_BCH8_CODE_HW;
else
info->ecc_opt = OMAP_ECC_BCH8_CODE_HW_DETECTION_SW;
} else if (!strcmp(s, "bch16")) {
info->ecc_opt = OMAP_ECC_BCH16_CODE_HW;
} else {
dev_err(dev, "unrecognized value for ti,nand-ecc-opt\n");
return -EINVAL;
}
if (!of_property_read_string(child, "ti,nand-xfer-type", &s)) {
for (i = 0; i < ARRAY_SIZE(nand_xfer_types); i++) {
if (!strcasecmp(s, nand_xfer_types[i])) {
info->xfer_type = i;
return 0;
}
}
dev_err(dev, "unrecognized value for ti,nand-xfer-type\n");
return -EINVAL;
}
return 0;
}
static int omap_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
struct nand_chip *chip = &info->nand;
int off = BADBLOCK_MARKER_LENGTH;
if (info->ecc_opt == OMAP_ECC_HAM1_CODE_HW &&
!(chip->options & NAND_BUSWIDTH_16))
off = 1;
if (section)
return -ERANGE;
oobregion->offset = off;
oobregion->length = chip->ecc.total;
return 0;
}
static int omap_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct omap_nand_info *info = mtd_to_omap(mtd);
struct nand_chip *chip = &info->nand;
int off = BADBLOCK_MARKER_LENGTH;
if (info->ecc_opt == OMAP_ECC_HAM1_CODE_HW &&
!(chip->options & NAND_BUSWIDTH_16))
off = 1;
if (section)
return -ERANGE;
off += chip->ecc.total;
if (off >= mtd->oobsize)
return -ERANGE;
oobregion->offset = off;
oobregion->length = mtd->oobsize - off;
return 0;
}
static int omap_sw_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int off = BADBLOCK_MARKER_LENGTH;
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->offset = off + (section * (chip->ecc.bytes + 1));
oobregion->length = chip->ecc.bytes;
return 0;
}
static int omap_sw_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int off = BADBLOCK_MARKER_LENGTH;
if (section)
return -ERANGE;
off += ((chip->ecc.bytes + 1) * chip->ecc.steps);
if (off >= mtd->oobsize)
return -ERANGE;
oobregion->offset = off;
oobregion->length = mtd->oobsize - off;
return 0;
}
static int omap_nand_probe(struct platform_device *pdev)
{
struct omap_nand_info *info;
struct omap_nand_platform_data *pdata = NULL;
struct mtd_info *mtd;
struct nand_chip *nand_chip;
int err;
dma_cap_mask_t mask;
unsigned sig;
struct resource *res;
struct device *dev = &pdev->dev;
int min_oobbytes = BADBLOCK_MARKER_LENGTH;
int oobbytes_per_step;
info = devm_kzalloc(&pdev->dev, sizeof(struct omap_nand_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->pdev = pdev;
if (dev->of_node) {
if (omap_get_dt_info(dev, info))
return -EINVAL;
} else {
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "platform data missing\n");
return -EINVAL;
}
info->gpmc_cs = pdata->cs;
info->reg = pdata->reg;
info->ecc_opt = pdata->ecc_opt;
if (pdata->dev_ready)
dev_info(&pdev->dev, "pdata->dev_ready is deprecated\n");
info->xfer_type = pdata->xfer_type;
info->devsize = pdata->devsize;
info->elm_of_node = pdata->elm_of_node;
info->flash_bbt = pdata->flash_bbt;
}
platform_set_drvdata(pdev, info);
info->ops = gpmc_omap_get_nand_ops(&info->reg, info->gpmc_cs);
if (!info->ops) {
dev_err(&pdev->dev, "Failed to get GPMC->NAND interface\n");
return -ENODEV;
}
nand_chip = &info->nand;
mtd = nand_to_mtd(nand_chip);
mtd->dev.parent = &pdev->dev;
nand_chip->ecc.priv = NULL;
nand_set_flash_node(nand_chip, dev->of_node);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nand_chip->IO_ADDR_R = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(nand_chip->IO_ADDR_R))
return PTR_ERR(nand_chip->IO_ADDR_R);
info->phys_base = res->start;
nand_chip->controller = &omap_gpmc_controller;
nand_chip->IO_ADDR_W = nand_chip->IO_ADDR_R;
nand_chip->cmd_ctrl = omap_hwcontrol;
info->ready_gpiod = devm_gpiod_get_optional(&pdev->dev, "rb",
GPIOD_IN);
if (IS_ERR(info->ready_gpiod)) {
dev_err(dev, "failed to get ready gpio\n");
return PTR_ERR(info->ready_gpiod);
}
if (info->ready_gpiod) {
nand_chip->dev_ready = omap_dev_ready;
nand_chip->chip_delay = 0;
} else {
nand_chip->waitfunc = omap_wait;
nand_chip->chip_delay = 50;
}
if (info->flash_bbt)
nand_chip->bbt_options |= NAND_BBT_USE_FLASH;
nand_chip->options |= info->devsize & NAND_BUSWIDTH_16;
if (nand_scan_ident(mtd, 1, NULL)) {
dev_err(&info->pdev->dev,
"scan failed, may be bus-width mismatch\n");
err = -ENXIO;
goto return_error;
}
if (nand_chip->bbt_options & NAND_BBT_USE_FLASH)
nand_chip->bbt_options |= NAND_BBT_NO_OOB;
else
nand_chip->options |= NAND_SKIP_BBTSCAN;
switch (info->xfer_type) {
case NAND_OMAP_PREFETCH_POLLED:
nand_chip->read_buf = omap_read_buf_pref;
nand_chip->write_buf = omap_write_buf_pref;
break;
case NAND_OMAP_POLLED:
break;
case NAND_OMAP_PREFETCH_DMA:
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
sig = OMAP24XX_DMA_GPMC;
info->dma = dma_request_channel(mask, omap_dma_filter_fn, &sig);
if (!info->dma) {
dev_err(&pdev->dev, "DMA engine request failed\n");
err = -ENXIO;
goto return_error;
} else {
struct dma_slave_config cfg;
memset(&cfg, 0, sizeof(cfg));
cfg.src_addr = info->phys_base;
cfg.dst_addr = info->phys_base;
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
cfg.src_maxburst = 16;
cfg.dst_maxburst = 16;
err = dmaengine_slave_config(info->dma, &cfg);
if (err) {
dev_err(&pdev->dev, "DMA engine slave config failed: %d\n",
err);
goto return_error;
}
nand_chip->read_buf = omap_read_buf_dma_pref;
nand_chip->write_buf = omap_write_buf_dma_pref;
}
break;
case NAND_OMAP_PREFETCH_IRQ:
info->gpmc_irq_fifo = platform_get_irq(pdev, 0);
if (info->gpmc_irq_fifo <= 0) {
dev_err(&pdev->dev, "error getting fifo irq\n");
err = -ENODEV;
goto return_error;
}
err = devm_request_irq(&pdev->dev, info->gpmc_irq_fifo,
omap_nand_irq, IRQF_SHARED,
"gpmc-nand-fifo", info);
if (err) {
dev_err(&pdev->dev, "requesting irq(%d) error:%d",
info->gpmc_irq_fifo, err);
info->gpmc_irq_fifo = 0;
goto return_error;
}
info->gpmc_irq_count = platform_get_irq(pdev, 1);
if (info->gpmc_irq_count <= 0) {
dev_err(&pdev->dev, "error getting count irq\n");
err = -ENODEV;
goto return_error;
}
err = devm_request_irq(&pdev->dev, info->gpmc_irq_count,
omap_nand_irq, IRQF_SHARED,
"gpmc-nand-count", info);
if (err) {
dev_err(&pdev->dev, "requesting irq(%d) error:%d",
info->gpmc_irq_count, err);
info->gpmc_irq_count = 0;
goto return_error;
}
nand_chip->read_buf = omap_read_buf_irq_pref;
nand_chip->write_buf = omap_write_buf_irq_pref;
break;
default:
dev_err(&pdev->dev,
"xfer_type(%d) not supported!\n", info->xfer_type);
err = -EINVAL;
goto return_error;
}
if (!omap2_nand_ecc_check(info, pdata)) {
err = -EINVAL;
goto return_error;
}
if (info->ecc_opt == OMAP_ECC_HAM1_CODE_SW) {
nand_chip->ecc.mode = NAND_ECC_SOFT;
nand_chip->ecc.algo = NAND_ECC_HAMMING;
goto scan_tail;
}
switch (info->ecc_opt) {
case OMAP_ECC_HAM1_CODE_HW:
pr_info("nand: using OMAP_ECC_HAM1_CODE_HW\n");
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.bytes = 3;
nand_chip->ecc.size = 512;
nand_chip->ecc.strength = 1;
nand_chip->ecc.calculate = omap_calculate_ecc;
nand_chip->ecc.hwctl = omap_enable_hwecc;
nand_chip->ecc.correct = omap_correct_data;
mtd_set_ooblayout(mtd, &omap_ooblayout_ops);
oobbytes_per_step = nand_chip->ecc.bytes;
if (!(nand_chip->options & NAND_BUSWIDTH_16))
min_oobbytes = 1;
break;
case OMAP_ECC_BCH4_CODE_HW_DETECTION_SW:
pr_info("nand: using OMAP_ECC_BCH4_CODE_HW_DETECTION_SW\n");
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.size = 512;
nand_chip->ecc.bytes = 7;
nand_chip->ecc.strength = 4;
nand_chip->ecc.hwctl = omap_enable_hwecc_bch;
nand_chip->ecc.correct = nand_bch_correct_data;
nand_chip->ecc.calculate = omap_calculate_ecc_bch;
mtd_set_ooblayout(mtd, &omap_sw_ooblayout_ops);
oobbytes_per_step = nand_chip->ecc.bytes + 1;
nand_chip->ecc.priv = nand_bch_init(mtd);
if (!nand_chip->ecc.priv) {
dev_err(&info->pdev->dev, "unable to use BCH library\n");
err = -EINVAL;
goto return_error;
}
break;
case OMAP_ECC_BCH4_CODE_HW:
pr_info("nand: using OMAP_ECC_BCH4_CODE_HW ECC scheme\n");
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.size = 512;
nand_chip->ecc.bytes = 7 + 1;
nand_chip->ecc.strength = 4;
nand_chip->ecc.hwctl = omap_enable_hwecc_bch;
nand_chip->ecc.correct = omap_elm_correct_data;
nand_chip->ecc.calculate = omap_calculate_ecc_bch;
nand_chip->ecc.read_page = omap_read_page_bch;
nand_chip->ecc.write_page = omap_write_page_bch;
mtd_set_ooblayout(mtd, &omap_ooblayout_ops);
oobbytes_per_step = nand_chip->ecc.bytes;
err = elm_config(info->elm_dev, BCH4_ECC,
mtd->writesize / nand_chip->ecc.size,
nand_chip->ecc.size, nand_chip->ecc.bytes);
if (err < 0)
goto return_error;
break;
case OMAP_ECC_BCH8_CODE_HW_DETECTION_SW:
pr_info("nand: using OMAP_ECC_BCH8_CODE_HW_DETECTION_SW\n");
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.size = 512;
nand_chip->ecc.bytes = 13;
nand_chip->ecc.strength = 8;
nand_chip->ecc.hwctl = omap_enable_hwecc_bch;
nand_chip->ecc.correct = nand_bch_correct_data;
nand_chip->ecc.calculate = omap_calculate_ecc_bch;
mtd_set_ooblayout(mtd, &omap_sw_ooblayout_ops);
oobbytes_per_step = nand_chip->ecc.bytes + 1;
nand_chip->ecc.priv = nand_bch_init(mtd);
if (!nand_chip->ecc.priv) {
dev_err(&info->pdev->dev, "unable to use BCH library\n");
err = -EINVAL;
goto return_error;
}
break;
case OMAP_ECC_BCH8_CODE_HW:
pr_info("nand: using OMAP_ECC_BCH8_CODE_HW ECC scheme\n");
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.size = 512;
nand_chip->ecc.bytes = 13 + 1;
nand_chip->ecc.strength = 8;
nand_chip->ecc.hwctl = omap_enable_hwecc_bch;
nand_chip->ecc.correct = omap_elm_correct_data;
nand_chip->ecc.calculate = omap_calculate_ecc_bch;
nand_chip->ecc.read_page = omap_read_page_bch;
nand_chip->ecc.write_page = omap_write_page_bch;
mtd_set_ooblayout(mtd, &omap_ooblayout_ops);
oobbytes_per_step = nand_chip->ecc.bytes;
err = elm_config(info->elm_dev, BCH8_ECC,
mtd->writesize / nand_chip->ecc.size,
nand_chip->ecc.size, nand_chip->ecc.bytes);
if (err < 0)
goto return_error;
break;
case OMAP_ECC_BCH16_CODE_HW:
pr_info("using OMAP_ECC_BCH16_CODE_HW ECC scheme\n");
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.size = 512;
nand_chip->ecc.bytes = 26;
nand_chip->ecc.strength = 16;
nand_chip->ecc.hwctl = omap_enable_hwecc_bch;
nand_chip->ecc.correct = omap_elm_correct_data;
nand_chip->ecc.calculate = omap_calculate_ecc_bch;
nand_chip->ecc.read_page = omap_read_page_bch;
nand_chip->ecc.write_page = omap_write_page_bch;
mtd_set_ooblayout(mtd, &omap_ooblayout_ops);
oobbytes_per_step = nand_chip->ecc.bytes;
err = elm_config(info->elm_dev, BCH16_ECC,
mtd->writesize / nand_chip->ecc.size,
nand_chip->ecc.size, nand_chip->ecc.bytes);
if (err < 0)
goto return_error;
break;
default:
dev_err(&info->pdev->dev, "invalid or unsupported ECC scheme\n");
err = -EINVAL;
goto return_error;
}
min_oobbytes += (oobbytes_per_step *
(mtd->writesize / nand_chip->ecc.size));
if (mtd->oobsize < min_oobbytes) {
dev_err(&info->pdev->dev,
"not enough OOB bytes required = %d, available=%d\n",
min_oobbytes, mtd->oobsize);
err = -EINVAL;
goto return_error;
}
scan_tail:
if (nand_scan_tail(mtd)) {
err = -ENXIO;
goto return_error;
}
if (dev->of_node)
mtd_device_register(mtd, NULL, 0);
else
mtd_device_register(mtd, pdata->parts, pdata->nr_parts);
platform_set_drvdata(pdev, mtd);
return 0;
return_error:
if (info->dma)
dma_release_channel(info->dma);
if (nand_chip->ecc.priv) {
nand_bch_free(nand_chip->ecc.priv);
nand_chip->ecc.priv = NULL;
}
return err;
}
static int omap_nand_remove(struct platform_device *pdev)
{
struct mtd_info *mtd = platform_get_drvdata(pdev);
struct nand_chip *nand_chip = mtd_to_nand(mtd);
struct omap_nand_info *info = mtd_to_omap(mtd);
if (nand_chip->ecc.priv) {
nand_bch_free(nand_chip->ecc.priv);
nand_chip->ecc.priv = NULL;
}
if (info->dma)
dma_release_channel(info->dma);
nand_release(mtd);
return 0;
}
