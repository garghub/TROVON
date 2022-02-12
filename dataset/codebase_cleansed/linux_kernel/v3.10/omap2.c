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
(dma_mode << DMA_MPU_MODE_SHIFT) | (0x1 & is_write));
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
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
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
struct nand_chip *nand = mtd->priv;
ioread8_rep(nand->IO_ADDR_R, buf, len);
}
static void omap_write_buf8(struct mtd_info *mtd, const u_char *buf, int len)
{
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
u_char *p = (u_char *)buf;
u32 status = 0;
while (len--) {
iowrite8(*p++, info->nand.IO_ADDR_W);
do {
status = readl(info->reg.gpmc_status) &
STATUS_BUFF_EMPTY;
} while (!status);
}
}
static void omap_read_buf16(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *nand = mtd->priv;
ioread16_rep(nand->IO_ADDR_R, buf, len / 2);
}
static void omap_write_buf16(struct mtd_info *mtd, const u_char * buf, int len)
{
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
u16 *p = (u16 *) buf;
u32 status = 0;
len >>= 1;
while (len--) {
iowrite16(*p++, info->nand.IO_ADDR_W);
do {
status = readl(info->reg.gpmc_status) &
STATUS_BUFF_EMPTY;
} while (!status);
}
}
static void omap_read_buf_pref(struct mtd_info *mtd, u_char *buf, int len)
{
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
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
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
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
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
struct dma_async_tx_descriptor *tx;
enum dma_data_direction dir = is_write ? DMA_TO_DEVICE :
DMA_FROM_DEVICE;
struct scatterlist sg;
unsigned long tim, limit;
unsigned n;
int ret;
u32 val;
if (addr >= high_memory) {
struct page *p1;
if (((size_t)addr & PAGE_MASK) !=
((size_t)(addr + len - 1) & PAGE_MASK))
goto out_copy;
p1 = vmalloc_to_page(addr);
if (!p1)
goto out_copy;
addr = page_address(p1) + ((size_t)addr & ~PAGE_MASK);
}
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
ret = omap_prefetch_enable(info->gpmc_cs,
PREFETCH_FIFOTHRESHOLD_MAX, 0x1, len, is_write, info);
if (ret)
goto out_copy_unmap;
init_completion(&info->comp);
dma_async_issue_pending(info->dma);
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
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
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
struct omap_nand_info *info = container_of(mtd,
struct omap_nand_info, mtd);
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
return -1;
case 11:
pr_debug("ECC UNCORRECTED_ERROR B\n");
return -1;
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
return -1;
}
}
static int omap_correct_data(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
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
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
u32 val;
val = readl(info->reg.gpmc_ecc_config);
if (((val >> ECC_CONFIG_CS_SHIFT) & ~CS_MASK) != info->gpmc_cs)
return -EINVAL;
val = readl(info->reg.gpmc_ecc1_result);
*ecc_code++ = val;
*ecc_code++ = val >> 16;
*ecc_code++ = ((val >> 8) & 0x0f) | ((val >> 20) & 0xf0);
return 0;
}
static void omap_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
struct nand_chip *chip = mtd->priv;
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
struct nand_chip *this = mtd->priv;
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
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
unsigned int val = 0;
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
val = readl(info->reg.gpmc_status);
if ((val & 0x100) == 0x100) {
return 1;
} else {
return 0;
}
}
static void omap3_enable_hwecc_bch(struct mtd_info *mtd, int mode)
{
int nerrors;
unsigned int dev_width, nsectors;
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
struct nand_chip *chip = mtd->priv;
u32 val, wr_mode;
unsigned int ecc_size1, ecc_size0;
wr_mode = BCH_WRAPMODE_6;
ecc_size0 = BCH_ECC_SIZE0;
ecc_size1 = BCH_ECC_SIZE1;
nsectors = 1;
nerrors = info->nand.ecc.strength;
if (info->is_elm_used && (mtd->writesize <= 4096)) {
if (mode == NAND_ECC_READ) {
wr_mode = BCH_WRAPMODE_1;
ecc_size0 = (nerrors == 8) ?
BCH8R_ECC_SIZE0 : BCH4R_ECC_SIZE0;
ecc_size1 = (nerrors == 8) ?
BCH8R_ECC_SIZE1 : BCH4R_ECC_SIZE1;
}
nsectors = info->nand.ecc.steps;
}
writel(ECC1, info->reg.gpmc_ecc_control);
val = (ecc_size1 << ECCSIZE1_SHIFT) | (ecc_size0 << ECCSIZE0_SHIFT);
writel(val, info->reg.gpmc_ecc_size_config);
dev_width = (chip->options & NAND_BUSWIDTH_16) ? 1 : 0;
val = ((1 << 16) |
(((nerrors == 8) ? 1 : 0) << 12) |
(wr_mode << 8) |
(dev_width << 7) |
(((nsectors-1) & 0x7) << 4) |
(info->gpmc_cs << 1) |
(0x1));
writel(val, info->reg.gpmc_ecc_config);
writel(ECCCLEAR | ECC1, info->reg.gpmc_ecc_control);
}
static int omap3_calculate_ecc_bch4(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
unsigned long nsectors, val1, val2;
int i;
nsectors = ((readl(info->reg.gpmc_ecc_config) >> 4) & 0x7) + 1;
for (i = 0; i < nsectors; i++) {
val1 = readl(info->reg.gpmc_bch_result0[i]);
val2 = readl(info->reg.gpmc_bch_result1[i]);
*ecc_code++ = 0x28 ^ ((val2 >> 12) & 0xFF);
*ecc_code++ = 0x13 ^ ((val2 >> 4) & 0xFF);
*ecc_code++ = 0xcc ^ (((val2 & 0xF) << 4)|((val1 >> 28) & 0xF));
*ecc_code++ = 0x39 ^ ((val1 >> 20) & 0xFF);
*ecc_code++ = 0x96 ^ ((val1 >> 12) & 0xFF);
*ecc_code++ = 0xac ^ ((val1 >> 4) & 0xFF);
*ecc_code++ = 0x7f ^ ((val1 & 0xF) << 4);
}
return 0;
}
static int omap3_calculate_ecc_bch8(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
unsigned long nsectors, val1, val2, val3, val4;
int i;
nsectors = ((readl(info->reg.gpmc_ecc_config) >> 4) & 0x7) + 1;
for (i = 0; i < nsectors; i++) {
val1 = readl(info->reg.gpmc_bch_result0[i]);
val2 = readl(info->reg.gpmc_bch_result1[i]);
val3 = readl(info->reg.gpmc_bch_result2[i]);
val4 = readl(info->reg.gpmc_bch_result3[i]);
*ecc_code++ = 0xef ^ (val4 & 0xFF);
*ecc_code++ = 0x51 ^ ((val3 >> 24) & 0xFF);
*ecc_code++ = 0x2e ^ ((val3 >> 16) & 0xFF);
*ecc_code++ = 0x09 ^ ((val3 >> 8) & 0xFF);
*ecc_code++ = 0xed ^ (val3 & 0xFF);
*ecc_code++ = 0x93 ^ ((val2 >> 24) & 0xFF);
*ecc_code++ = 0x9a ^ ((val2 >> 16) & 0xFF);
*ecc_code++ = 0xc2 ^ ((val2 >> 8) & 0xFF);
*ecc_code++ = 0x97 ^ (val2 & 0xFF);
*ecc_code++ = 0x79 ^ ((val1 >> 24) & 0xFF);
*ecc_code++ = 0xe5 ^ ((val1 >> 16) & 0xFF);
*ecc_code++ = 0x24 ^ ((val1 >> 8) & 0xFF);
*ecc_code++ = 0xb5 ^ (val1 & 0xFF);
}
return 0;
}
static int omap3_calculate_ecc_bch(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
unsigned long nsectors, bch_val1, bch_val2, bch_val3, bch_val4;
int i, eccbchtsel;
nsectors = ((readl(info->reg.gpmc_ecc_config) >> 4) & 0x7) + 1;
eccbchtsel = ((readl(info->reg.gpmc_ecc_config) >> 12) & 0x3);
for (i = 0; i < nsectors; i++) {
bch_val1 = readl(info->reg.gpmc_bch_result0[i]);
bch_val2 = readl(info->reg.gpmc_bch_result1[i]);
if (eccbchtsel) {
bch_val3 = readl(info->reg.gpmc_bch_result2[i]);
bch_val4 = readl(info->reg.gpmc_bch_result3[i]);
}
if (eccbchtsel) {
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
*ecc_code++ = 0x0;
} else {
*ecc_code++ = ((bch_val2 >> 12) & 0xFF);
*ecc_code++ = ((bch_val2 >> 4) & 0xFF);
*ecc_code++ = ((bch_val2 & 0xF) << 4) |
((bch_val1 >> 28) & 0xF);
*ecc_code++ = ((bch_val1 >> 20) & 0xFF);
*ecc_code++ = ((bch_val1 >> 12) & 0xFF);
*ecc_code++ = ((bch_val1 >> 4) & 0xFF);
*ecc_code++ = ((bch_val1 & 0xF) << 4);
*ecc_code++ = 0x0;
}
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
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
int eccsteps = info->nand.ecc.steps;
int i , j, stat = 0;
int eccsize, eccflag, ecc_vector_size;
struct elm_errorvec err_vec[ERROR_VECTOR_MAX];
u_char *ecc_vec = calc_ecc;
u_char *spare_ecc = read_ecc;
u_char *erased_ecc_vec;
enum bch_ecc type;
bool is_error_reported = false;
memset(err_vec, 0, sizeof(err_vec));
if (info->nand.ecc.strength == BCH8_MAX_ERROR) {
type = BCH8_ECC;
erased_ecc_vec = bch8_vector;
} else {
type = BCH4_ECC;
erased_ecc_vec = bch4_vector;
}
ecc_vector_size = info->nand.ecc.bytes;
eccsize = ecc_vector_size - 1;
for (i = 0; i < eccsteps ; i++) {
eccflag = 0;
for (j = 0; (j < eccsize); j++) {
if (calc_ecc[j] != 0) {
eccflag = 1;
break;
}
}
if (eccflag == 1) {
unsigned int threshold = min_t(unsigned int, 4,
info->nand.ecc.strength / 2);
if (hweight8(~read_ecc[eccsize]) >= threshold) {
err_vec[i].error_reported = true;
is_error_reported = true;
} else {
int bitflip_count;
u_char *buf = &data[info->nand.ecc.size * i];
if (memcmp(calc_ecc, erased_ecc_vec, eccsize)) {
bitflip_count = erased_sector_bitflips(
buf, read_ecc, info);
if (bitflip_count)
stat += bitflip_count;
else
return -EINVAL;
}
}
}
calc_ecc += ecc_vector_size;
read_ecc += ecc_vector_size;
}
if (!is_error_reported)
return 0;
elm_decode_bch_error_page(info->elm_dev, ecc_vec, err_vec);
for (i = 0; i < eccsteps; i++) {
if (err_vec[i].error_reported) {
for (j = 0; j < err_vec[i].error_count; j++) {
u32 bit_pos, byte_pos, error_max, pos;
if (type == BCH8_ECC)
error_max = BCH8_ECC_MAX;
else
error_max = BCH4_ECC_MAX;
if (info->nand.ecc.strength == BCH8_MAX_ERROR)
pos = err_vec[i].error_loc[j];
else
pos = err_vec[i].error_loc[j] +
BCH4_BIT_PAD;
bit_pos = pos % 8;
byte_pos = (error_max - pos - 1) / 8;
if (pos < error_max) {
if (byte_pos < 512)
data[byte_pos] ^= 1 << bit_pos;
else
spare_ecc[byte_pos - 512] ^=
1 << bit_pos;
}
}
}
stat += err_vec[i].error_count;
data += info->nand.ecc.size;
spare_ecc += ecc_vector_size;
}
for (i = 0; i < eccsteps; i++)
if (err_vec[i].error_uncorrectable)
return -EINVAL;
return stat;
}
static int omap3_correct_data_bch(struct mtd_info *mtd, u_char *data,
u_char *read_ecc, u_char *calc_ecc)
{
int i, count;
unsigned int errloc[8];
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
count = decode_bch(info->bch, NULL, 512, read_ecc, calc_ecc, NULL,
errloc);
if (count > 0) {
for (i = 0; i < count; i++) {
if (errloc[i] < 8*512)
data[errloc[i]/8] ^= 1 << (errloc[i] & 7);
pr_debug("corrected bitflip %u\n", errloc[i]);
}
} else if (count < 0) {
pr_err("ecc unrecoverable error\n");
}
return count;
}
static int omap_write_page_bch(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required)
{
int i;
uint8_t *ecc_calc = chip->buffers->ecccalc;
uint32_t *eccpos = chip->ecc.layout->eccpos;
chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
chip->write_buf(mtd, buf, mtd->writesize);
chip->ecc.calculate(mtd, buf, &ecc_calc[0]);
for (i = 0; i < chip->ecc.total; i++)
chip->oob_poi[eccpos[i]] = ecc_calc[i];
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int omap_read_page_bch(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
uint8_t *ecc_calc = chip->buffers->ecccalc;
uint8_t *ecc_code = chip->buffers->ecccode;
uint32_t *eccpos = chip->ecc.layout->eccpos;
uint8_t *oob = &chip->oob_poi[eccpos[0]];
uint32_t oob_pos = mtd->writesize + chip->ecc.layout->eccpos[0];
int stat;
unsigned int max_bitflips = 0;
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, buf, mtd->writesize);
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, oob_pos, -1);
chip->read_buf(mtd, oob, chip->ecc.total);
chip->ecc.calculate(mtd, buf, ecc_calc);
memcpy(ecc_code, &chip->oob_poi[eccpos[0]], chip->ecc.total);
stat = chip->ecc.correct(mtd, buf, ecc_code, ecc_calc);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
return max_bitflips;
}
static void omap3_free_bch(struct mtd_info *mtd)
{
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
if (info->bch) {
free_bch(info->bch);
info->bch = NULL;
}
}
static int omap3_init_bch(struct mtd_info *mtd, int ecc_opt)
{
int max_errors;
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
#ifdef CONFIG_MTD_NAND_OMAP_BCH8
const int hw_errors = BCH8_MAX_ERROR;
#else
const int hw_errors = BCH4_MAX_ERROR;
#endif
enum bch_ecc bch_type;
const __be32 *parp;
int lenp;
struct device_node *elm_node;
info->bch = NULL;
max_errors = (ecc_opt == OMAP_ECC_BCH8_CODE_HW) ?
BCH8_MAX_ERROR : BCH4_MAX_ERROR;
if (max_errors != hw_errors) {
pr_err("cannot configure %d-bit BCH ecc, only %d-bit supported",
max_errors, hw_errors);
goto fail;
}
info->nand.ecc.size = 512;
info->nand.ecc.hwctl = omap3_enable_hwecc_bch;
info->nand.ecc.mode = NAND_ECC_HW;
info->nand.ecc.strength = max_errors;
if (hw_errors == BCH8_MAX_ERROR)
bch_type = BCH8_ECC;
else
bch_type = BCH4_ECC;
parp = of_get_property(info->of_node, "elm_id", &lenp);
if ((parp == NULL) && (lenp != (sizeof(void *) * 2))) {
pr_err("Missing elm_id property, fall back to Software BCH\n");
info->is_elm_used = false;
} else {
struct platform_device *pdev;
elm_node = of_find_node_by_phandle(be32_to_cpup(parp));
pdev = of_find_device_by_node(elm_node);
info->elm_dev = &pdev->dev;
if (elm_config(info->elm_dev, bch_type) == 0)
info->is_elm_used = true;
}
if (info->is_elm_used && (mtd->writesize <= 4096)) {
if (hw_errors == BCH8_MAX_ERROR)
info->nand.ecc.bytes = BCH8_SIZE;
else
info->nand.ecc.bytes = BCH4_SIZE;
info->nand.ecc.correct = omap_elm_correct_data;
info->nand.ecc.calculate = omap3_calculate_ecc_bch;
info->nand.ecc.read_page = omap_read_page_bch;
info->nand.ecc.write_page = omap_write_page_bch;
} else {
info->bch = init_bch(13, max_errors,
0x201b );
if (!info->bch)
goto fail;
info->nand.ecc.correct = omap3_correct_data_bch;
if (max_errors == 8) {
info->nand.ecc.bytes = 13;
info->nand.ecc.calculate = omap3_calculate_ecc_bch8;
} else {
info->nand.ecc.bytes = 7;
info->nand.ecc.calculate = omap3_calculate_ecc_bch4;
}
}
pr_info("enabling NAND BCH ecc with %d-bit correction\n", max_errors);
return 0;
fail:
omap3_free_bch(mtd);
return -1;
}
static int omap3_init_bch_tail(struct mtd_info *mtd)
{
int i, steps, offset;
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
struct nand_ecclayout *layout = &info->ecclayout;
steps = mtd->writesize/info->nand.ecc.size;
layout->eccbytes = steps*info->nand.ecc.bytes;
if (mtd->oobsize < 64) {
pr_err("BCH ecc is not supported on small page devices\n");
goto fail;
}
if (layout->eccbytes+2 > mtd->oobsize) {
pr_err("no oob layout available for oobsize %d eccbytes %u\n",
mtd->oobsize, layout->eccbytes);
goto fail;
}
if (info->is_elm_used && (info->nand.ecc.bytes == BCH8_SIZE))
offset = 2;
else
offset = mtd->oobsize - layout->eccbytes;
for (i = 0; i < layout->eccbytes; i++)
layout->eccpos[i] = offset + i;
if (info->is_elm_used && (info->nand.ecc.bytes == BCH8_SIZE))
layout->oobfree[0].offset = 2 + layout->eccbytes * steps;
else
layout->oobfree[0].offset = 2;
layout->oobfree[0].length = mtd->oobsize-2-layout->eccbytes;
info->nand.ecc.layout = layout;
if (!(info->nand.options & NAND_BUSWIDTH_16))
info->nand.badblock_pattern = &bb_descrip_flashbased;
return 0;
fail:
omap3_free_bch(mtd);
return -1;
}
static int omap3_init_bch(struct mtd_info *mtd, int ecc_opt)
{
pr_err("CONFIG_MTD_NAND_OMAP_BCH is not enabled\n");
return -1;
}
static int omap3_init_bch_tail(struct mtd_info *mtd)
{
return -1;
}
static void omap3_free_bch(struct mtd_info *mtd)
{
}
static int omap_nand_probe(struct platform_device *pdev)
{
struct omap_nand_info *info;
struct omap_nand_platform_data *pdata;
int err;
int i, offset;
dma_cap_mask_t mask;
unsigned sig;
struct resource *res;
struct mtd_part_parser_data ppdata = {};
pdata = pdev->dev.platform_data;
if (pdata == NULL) {
dev_err(&pdev->dev, "platform data missing\n");
return -ENODEV;
}
info = kzalloc(sizeof(struct omap_nand_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
platform_set_drvdata(pdev, info);
spin_lock_init(&info->controller.lock);
init_waitqueue_head(&info->controller.wq);
info->pdev = pdev;
info->gpmc_cs = pdata->cs;
info->reg = pdata->reg;
info->mtd.priv = &info->nand;
info->mtd.name = dev_name(&pdev->dev);
info->mtd.owner = THIS_MODULE;
info->nand.options = pdata->devsize;
info->nand.options |= NAND_SKIP_BBTSCAN;
#ifdef CONFIG_MTD_NAND_OMAP_BCH
info->of_node = pdata->of_node;
#endif
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
err = -EINVAL;
dev_err(&pdev->dev, "error getting memory resource\n");
goto out_free_info;
}
info->phys_base = res->start;
info->mem_size = resource_size(res);
if (!request_mem_region(info->phys_base, info->mem_size,
pdev->dev.driver->name)) {
err = -EBUSY;
goto out_free_info;
}
info->nand.IO_ADDR_R = ioremap(info->phys_base, info->mem_size);
if (!info->nand.IO_ADDR_R) {
err = -ENOMEM;
goto out_release_mem_region;
}
info->nand.controller = &info->controller;
info->nand.IO_ADDR_W = info->nand.IO_ADDR_R;
info->nand.cmd_ctrl = omap_hwcontrol;
if (pdata->dev_ready) {
info->nand.dev_ready = omap_dev_ready;
info->nand.chip_delay = 0;
} else {
info->nand.waitfunc = omap_wait;
info->nand.chip_delay = 50;
}
switch (pdata->xfer_type) {
case NAND_OMAP_PREFETCH_POLLED:
info->nand.read_buf = omap_read_buf_pref;
info->nand.write_buf = omap_write_buf_pref;
break;
case NAND_OMAP_POLLED:
if (info->nand.options & NAND_BUSWIDTH_16) {
info->nand.read_buf = omap_read_buf16;
info->nand.write_buf = omap_write_buf16;
} else {
info->nand.read_buf = omap_read_buf8;
info->nand.write_buf = omap_write_buf8;
}
break;
case NAND_OMAP_PREFETCH_DMA:
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
sig = OMAP24XX_DMA_GPMC;
info->dma = dma_request_channel(mask, omap_dma_filter_fn, &sig);
if (!info->dma) {
dev_err(&pdev->dev, "DMA engine request failed\n");
err = -ENXIO;
goto out_release_mem_region;
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
goto out_release_mem_region;
}
info->nand.read_buf = omap_read_buf_dma_pref;
info->nand.write_buf = omap_write_buf_dma_pref;
}
break;
case NAND_OMAP_PREFETCH_IRQ:
info->gpmc_irq_fifo = platform_get_irq(pdev, 0);
if (info->gpmc_irq_fifo <= 0) {
dev_err(&pdev->dev, "error getting fifo irq\n");
err = -ENODEV;
goto out_release_mem_region;
}
err = request_irq(info->gpmc_irq_fifo, omap_nand_irq,
IRQF_SHARED, "gpmc-nand-fifo", info);
if (err) {
dev_err(&pdev->dev, "requesting irq(%d) error:%d",
info->gpmc_irq_fifo, err);
info->gpmc_irq_fifo = 0;
goto out_release_mem_region;
}
info->gpmc_irq_count = platform_get_irq(pdev, 1);
if (info->gpmc_irq_count <= 0) {
dev_err(&pdev->dev, "error getting count irq\n");
err = -ENODEV;
goto out_release_mem_region;
}
err = request_irq(info->gpmc_irq_count, omap_nand_irq,
IRQF_SHARED, "gpmc-nand-count", info);
if (err) {
dev_err(&pdev->dev, "requesting irq(%d) error:%d",
info->gpmc_irq_count, err);
info->gpmc_irq_count = 0;
goto out_release_mem_region;
}
info->nand.read_buf = omap_read_buf_irq_pref;
info->nand.write_buf = omap_write_buf_irq_pref;
break;
default:
dev_err(&pdev->dev,
"xfer_type(%d) not supported!\n", pdata->xfer_type);
err = -EINVAL;
goto out_release_mem_region;
}
if (pdata->ecc_opt == OMAP_ECC_HAMMING_CODE_DEFAULT)
info->nand.ecc.mode = NAND_ECC_SOFT;
else if ((pdata->ecc_opt == OMAP_ECC_HAMMING_CODE_HW) ||
(pdata->ecc_opt == OMAP_ECC_HAMMING_CODE_HW_ROMCODE)) {
info->nand.ecc.bytes = 3;
info->nand.ecc.size = 512;
info->nand.ecc.strength = 1;
info->nand.ecc.calculate = omap_calculate_ecc;
info->nand.ecc.hwctl = omap_enable_hwecc;
info->nand.ecc.correct = omap_correct_data;
info->nand.ecc.mode = NAND_ECC_HW;
} else if ((pdata->ecc_opt == OMAP_ECC_BCH4_CODE_HW) ||
(pdata->ecc_opt == OMAP_ECC_BCH8_CODE_HW)) {
err = omap3_init_bch(&info->mtd, pdata->ecc_opt);
if (err) {
err = -EINVAL;
goto out_release_mem_region;
}
}
if (nand_scan_ident(&info->mtd, 1, NULL)) {
info->nand.options ^= NAND_BUSWIDTH_16;
if (nand_scan_ident(&info->mtd, 1, NULL)) {
err = -ENXIO;
goto out_release_mem_region;
}
}
if (pdata->ecc_opt == OMAP_ECC_HAMMING_CODE_HW_ROMCODE) {
if (info->nand.options & NAND_BUSWIDTH_16)
offset = 2;
else {
offset = 1;
info->nand.badblock_pattern = &bb_descrip_flashbased;
}
omap_oobinfo.eccbytes = 3 * (info->mtd.oobsize/16);
for (i = 0; i < omap_oobinfo.eccbytes; i++)
omap_oobinfo.eccpos[i] = i+offset;
omap_oobinfo.oobfree->offset = offset + omap_oobinfo.eccbytes;
omap_oobinfo.oobfree->length = info->mtd.oobsize -
(offset + omap_oobinfo.eccbytes);
info->nand.ecc.layout = &omap_oobinfo;
} else if ((pdata->ecc_opt == OMAP_ECC_BCH4_CODE_HW) ||
(pdata->ecc_opt == OMAP_ECC_BCH8_CODE_HW)) {
err = omap3_init_bch_tail(&info->mtd);
if (err) {
err = -EINVAL;
goto out_release_mem_region;
}
}
if (nand_scan_tail(&info->mtd)) {
err = -ENXIO;
goto out_release_mem_region;
}
ppdata.of_node = pdata->of_node;
mtd_device_parse_register(&info->mtd, NULL, &ppdata, pdata->parts,
pdata->nr_parts);
platform_set_drvdata(pdev, &info->mtd);
return 0;
out_release_mem_region:
if (info->dma)
dma_release_channel(info->dma);
if (info->gpmc_irq_count > 0)
free_irq(info->gpmc_irq_count, info);
if (info->gpmc_irq_fifo > 0)
free_irq(info->gpmc_irq_fifo, info);
release_mem_region(info->phys_base, info->mem_size);
out_free_info:
kfree(info);
return err;
}
static int omap_nand_remove(struct platform_device *pdev)
{
struct mtd_info *mtd = platform_get_drvdata(pdev);
struct omap_nand_info *info = container_of(mtd, struct omap_nand_info,
mtd);
omap3_free_bch(&info->mtd);
platform_set_drvdata(pdev, NULL);
if (info->dma)
dma_release_channel(info->dma);
if (info->gpmc_irq_count > 0)
free_irq(info->gpmc_irq_count, info);
if (info->gpmc_irq_fifo > 0)
free_irq(info->gpmc_irq_fifo, info);
nand_release(&info->mtd);
iounmap(info->nand.IO_ADDR_R);
release_mem_region(info->phys_base, info->mem_size);
kfree(info);
return 0;
}
