static int cpu_has_dma(void)
{
return cpu_is_at91sam9rl() || cpu_is_at91sam9g45();
}
static void atmel_nand_enable(struct atmel_nand_host *host)
{
if (gpio_is_valid(host->board.enable_pin))
gpio_set_value(host->board.enable_pin, 0);
}
static void atmel_nand_disable(struct atmel_nand_host *host)
{
if (gpio_is_valid(host->board.enable_pin))
gpio_set_value(host->board.enable_pin, 1);
}
static void atmel_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_NCE)
atmel_nand_enable(host);
else
atmel_nand_disable(host);
}
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, host->io_base + (1 << host->board.cle));
else
writeb(cmd, host->io_base + (1 << host->board.ale));
}
static int atmel_nand_device_ready(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
return gpio_get_value(host->board.rdy_pin) ^
!!host->board.rdy_pin_active_low;
}
static void atmel_read_buf8(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_readsb(nand_chip->IO_ADDR_R, buf, len);
}
static void atmel_read_buf16(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_readsw(nand_chip->IO_ADDR_R, buf, len / 2);
}
static void atmel_write_buf8(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_writesb(nand_chip->IO_ADDR_W, buf, len);
}
static void atmel_write_buf16(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_writesw(nand_chip->IO_ADDR_W, buf, len / 2);
}
static void dma_complete_func(void *completion)
{
complete(completion);
}
static int atmel_nand_dma_op(struct mtd_info *mtd, void *buf, int len,
int is_read)
{
struct dma_device *dma_dev;
enum dma_ctrl_flags flags;
dma_addr_t dma_src_addr, dma_dst_addr, phys_addr;
struct dma_async_tx_descriptor *tx = NULL;
dma_cookie_t cookie;
struct nand_chip *chip = mtd->priv;
struct atmel_nand_host *host = chip->priv;
void *p = buf;
int err = -EIO;
enum dma_data_direction dir = is_read ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
if (buf >= high_memory)
goto err_buf;
dma_dev = host->dma_chan->device;
flags = DMA_CTRL_ACK | DMA_PREP_INTERRUPT | DMA_COMPL_SKIP_SRC_UNMAP |
DMA_COMPL_SKIP_DEST_UNMAP;
phys_addr = dma_map_single(dma_dev->dev, p, len, dir);
if (dma_mapping_error(dma_dev->dev, phys_addr)) {
dev_err(host->dev, "Failed to dma_map_single\n");
goto err_buf;
}
if (is_read) {
dma_src_addr = host->io_phys;
dma_dst_addr = phys_addr;
} else {
dma_src_addr = phys_addr;
dma_dst_addr = host->io_phys;
}
tx = dma_dev->device_prep_dma_memcpy(host->dma_chan, dma_dst_addr,
dma_src_addr, len, flags);
if (!tx) {
dev_err(host->dev, "Failed to prepare DMA memcpy\n");
goto err_dma;
}
init_completion(&host->comp);
tx->callback = dma_complete_func;
tx->callback_param = &host->comp;
cookie = tx->tx_submit(tx);
if (dma_submit_error(cookie)) {
dev_err(host->dev, "Failed to do DMA tx_submit\n");
goto err_dma;
}
dma_async_issue_pending(host->dma_chan);
wait_for_completion(&host->comp);
err = 0;
err_dma:
dma_unmap_single(dma_dev->dev, phys_addr, len, dir);
err_buf:
if (err != 0)
dev_warn(host->dev, "Fall back to CPU I/O\n");
return err;
}
static void atmel_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct atmel_nand_host *host = chip->priv;
if (use_dma && len > mtd->oobsize)
if (atmel_nand_dma_op(mtd, buf, len, 1) == 0)
return;
if (host->board.bus_width_16)
atmel_read_buf16(mtd, buf, len);
else
atmel_read_buf8(mtd, buf, len);
}
static void atmel_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct atmel_nand_host *host = chip->priv;
if (use_dma && len > mtd->oobsize)
if (atmel_nand_dma_op(mtd, (void *)buf, len, 0) == 0)
return;
if (host->board.bus_width_16)
atmel_write_buf16(mtd, buf, len);
else
atmel_write_buf8(mtd, buf, len);
}
static int pmecc_get_ecc_bytes(int cap, int sector_size)
{
int m = 12 + sector_size / 512;
return (m * cap + 7) / 8;
}
static void pmecc_config_ecc_layout(struct nand_ecclayout *layout,
int oobsize, int ecc_len)
{
int i;
layout->eccbytes = ecc_len;
for (i = 0; i < ecc_len; i++)
layout->eccpos[i] = oobsize - ecc_len + i;
layout->oobfree[0].offset = 2;
layout->oobfree[0].length =
oobsize - ecc_len - layout->oobfree[0].offset;
}
static void __iomem *pmecc_get_alpha_to(struct atmel_nand_host *host)
{
int table_size;
table_size = host->pmecc_sector_size == 512 ?
PMECC_LOOKUP_TABLE_SIZE_512 : PMECC_LOOKUP_TABLE_SIZE_1024;
return host->pmecc_rom_base + host->pmecc_lookup_table_offset +
table_size * sizeof(int16_t);
}
static void pmecc_data_free(struct atmel_nand_host *host)
{
kfree(host->pmecc_partial_syn);
kfree(host->pmecc_si);
kfree(host->pmecc_lmu);
kfree(host->pmecc_smu);
kfree(host->pmecc_mu);
kfree(host->pmecc_dmu);
kfree(host->pmecc_delta);
}
static int pmecc_data_alloc(struct atmel_nand_host *host)
{
const int cap = host->pmecc_corr_cap;
host->pmecc_partial_syn = kzalloc((2 * cap + 1) * sizeof(int16_t),
GFP_KERNEL);
host->pmecc_si = kzalloc((2 * cap + 1) * sizeof(int16_t), GFP_KERNEL);
host->pmecc_lmu = kzalloc((cap + 1) * sizeof(int16_t), GFP_KERNEL);
host->pmecc_smu = kzalloc((cap + 2) * (2 * cap + 1) * sizeof(int16_t),
GFP_KERNEL);
host->pmecc_mu = kzalloc((cap + 1) * sizeof(int), GFP_KERNEL);
host->pmecc_dmu = kzalloc((cap + 1) * sizeof(int), GFP_KERNEL);
host->pmecc_delta = kzalloc((cap + 1) * sizeof(int), GFP_KERNEL);
if (host->pmecc_partial_syn &&
host->pmecc_si &&
host->pmecc_lmu &&
host->pmecc_smu &&
host->pmecc_mu &&
host->pmecc_dmu &&
host->pmecc_delta)
return 0;
pmecc_data_free(host);
return -ENOMEM;
}
static void pmecc_gen_syndrome(struct mtd_info *mtd, int sector)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
int i;
uint32_t value;
for (i = 0; i < host->pmecc_corr_cap; i++) {
value = pmecc_readl_rem_relaxed(host->ecc, sector, i / 2);
if (i & 1)
value >>= 16;
value &= 0xffff;
host->pmecc_partial_syn[(2 * i) + 1] = (int16_t)value;
}
}
static void pmecc_substitute(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
int16_t __iomem *alpha_to = host->pmecc_alpha_to;
int16_t __iomem *index_of = host->pmecc_index_of;
int16_t *partial_syn = host->pmecc_partial_syn;
const int cap = host->pmecc_corr_cap;
int16_t *si;
int i, j;
si = host->pmecc_si;
memset(&si[1], 0, sizeof(int16_t) * (2 * cap - 1));
for (i = 1; i < 2 * cap; i += 2) {
for (j = 0; j < host->pmecc_degree; j++) {
if (partial_syn[i] & ((unsigned short)0x1 << j))
si[i] = readw_relaxed(alpha_to + i * j) ^ si[i];
}
}
for (i = 2, j = 1; j <= cap; i = ++j << 1) {
if (si[j] == 0) {
si[i] = 0;
} else {
int16_t tmp;
tmp = readw_relaxed(index_of + si[j]);
tmp = (tmp * 2) % host->pmecc_cw_len;
si[i] = readw_relaxed(alpha_to + tmp);
}
}
return;
}
static void pmecc_get_sigma(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
int16_t *lmu = host->pmecc_lmu;
int16_t *si = host->pmecc_si;
int *mu = host->pmecc_mu;
int *dmu = host->pmecc_dmu;
int *delta = host->pmecc_delta;
int cw_len = host->pmecc_cw_len;
const int16_t cap = host->pmecc_corr_cap;
const int num = 2 * cap + 1;
int16_t __iomem *index_of = host->pmecc_index_of;
int16_t __iomem *alpha_to = host->pmecc_alpha_to;
int i, j, k;
uint32_t dmu_0_count, tmp;
int16_t *smu = host->pmecc_smu;
int ro;
int largest;
int diff;
dmu_0_count = 0;
mu[0] = -1;
memset(smu, 0, sizeof(int16_t) * num);
smu[0] = 1;
dmu[0] = 1;
lmu[0] = 0;
delta[0] = (mu[0] * 2 - lmu[0]) >> 1;
mu[1] = 0;
memset(&smu[num], 0, sizeof(int16_t) * num);
smu[num] = 1;
dmu[1] = si[1];
lmu[1] = 0;
delta[1] = (mu[1] * 2 - lmu[1]) >> 1;
memset(&smu[(cap + 1) * num], 0, sizeof(int16_t) * num);
for (i = 1; i <= cap; i++) {
mu[i + 1] = i << 1;
if (dmu[i] == 0) {
dmu_0_count++;
tmp = ((cap - (lmu[i] >> 1) - 1) / 2);
if ((cap - (lmu[i] >> 1) - 1) & 0x1)
tmp += 2;
else
tmp += 1;
if (dmu_0_count == tmp) {
for (j = 0; j <= (lmu[i] >> 1) + 1; j++)
smu[(cap + 1) * num + j] =
smu[i * num + j];
lmu[cap + 1] = lmu[i];
return;
}
for (j = 0; j <= lmu[i] >> 1; j++)
smu[(i + 1) * num + j] = smu[i * num + j];
lmu[i + 1] = lmu[i];
} else {
ro = 0;
largest = -1;
for (j = 0; j < i; j++) {
if ((dmu[j]) && (delta[j] > largest)) {
largest = delta[j];
ro = j;
}
}
diff = (mu[i] - mu[ro]);
if ((lmu[i] >> 1) > ((lmu[ro] >> 1) + diff))
lmu[i + 1] = lmu[i];
else
lmu[i + 1] = ((lmu[ro] >> 1) + diff) * 2;
for (k = 0; k < num; k++)
smu[(i + 1) * num + k] = 0;
for (k = 0; k <= lmu[ro] >> 1; k++) {
int16_t a, b, c;
if (!(smu[ro * num + k] && dmu[i]))
continue;
a = readw_relaxed(index_of + dmu[i]);
b = readw_relaxed(index_of + dmu[ro]);
c = readw_relaxed(index_of + smu[ro * num + k]);
tmp = a + (cw_len - b) + c;
a = readw_relaxed(alpha_to + tmp % cw_len);
smu[(i + 1) * num + (k + diff)] = a;
}
for (k = 0; k <= lmu[i] >> 1; k++)
smu[(i + 1) * num + k] ^= smu[i * num + k];
}
delta[i + 1] = (mu[i + 1] * 2 - lmu[i + 1]) >> 1;
if (i >= cap)
continue;
for (k = 0; k <= (lmu[i + 1] >> 1); k++) {
tmp = 2 * (i - 1);
if (k == 0) {
dmu[i + 1] = si[tmp + 3];
} else if (smu[(i + 1) * num + k] && si[tmp + 3 - k]) {
int16_t a, b, c;
a = readw_relaxed(index_of +
smu[(i + 1) * num + k]);
b = si[2 * (i - 1) + 3 - k];
c = readw_relaxed(index_of + b);
tmp = a + c;
tmp %= cw_len;
dmu[i + 1] = readw_relaxed(alpha_to + tmp) ^
dmu[i + 1];
}
}
}
return;
}
static int pmecc_err_location(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
unsigned long end_time;
const int cap = host->pmecc_corr_cap;
const int num = 2 * cap + 1;
int sector_size = host->pmecc_sector_size;
int err_nbr = 0;
int roots_nbr;
int i;
uint32_t val;
int16_t *smu = host->pmecc_smu;
pmerrloc_writel(host->pmerrloc_base, ELDIS, PMERRLOC_DISABLE);
for (i = 0; i <= host->pmecc_lmu[cap + 1] >> 1; i++) {
pmerrloc_writel_sigma_relaxed(host->pmerrloc_base, i,
smu[(cap + 1) * num + i]);
err_nbr++;
}
val = (err_nbr - 1) << 16;
if (sector_size == 1024)
val |= 1;
pmerrloc_writel(host->pmerrloc_base, ELCFG, val);
pmerrloc_writel(host->pmerrloc_base, ELEN,
sector_size * 8 + host->pmecc_degree * cap);
end_time = jiffies + msecs_to_jiffies(PMECC_MAX_TIMEOUT_MS);
while (!(pmerrloc_readl_relaxed(host->pmerrloc_base, ELISR)
& PMERRLOC_CALC_DONE)) {
if (unlikely(time_after(jiffies, end_time))) {
dev_err(host->dev, "PMECC: Timeout to calculate error location.\n");
return -1;
}
cpu_relax();
}
roots_nbr = (pmerrloc_readl_relaxed(host->pmerrloc_base, ELISR)
& PMERRLOC_ERR_NUM_MASK) >> 8;
if (roots_nbr == host->pmecc_lmu[cap + 1] >> 1)
return err_nbr - 1;
return -1;
}
static void pmecc_correct_data(struct mtd_info *mtd, uint8_t *buf, uint8_t *ecc,
int sector_num, int extra_bytes, int err_nbr)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
int i = 0;
int byte_pos, bit_pos, sector_size, pos;
uint32_t tmp;
uint8_t err_byte;
sector_size = host->pmecc_sector_size;
while (err_nbr) {
tmp = pmerrloc_readl_el_relaxed(host->pmerrloc_base, i) - 1;
byte_pos = tmp / 8;
bit_pos = tmp % 8;
if (byte_pos >= (sector_size + extra_bytes))
BUG();
if (byte_pos < sector_size) {
err_byte = *(buf + byte_pos);
*(buf + byte_pos) ^= (1 << bit_pos);
pos = sector_num * host->pmecc_sector_size + byte_pos;
dev_info(host->dev, "Bit flip in data area, byte_pos: %d, bit_pos: %d, 0x%02x -> 0x%02x\n",
pos, bit_pos, err_byte, *(buf + byte_pos));
} else {
tmp = sector_num * host->pmecc_bytes_per_sector
+ (byte_pos - sector_size);
err_byte = ecc[tmp];
ecc[tmp] ^= (1 << bit_pos);
pos = tmp + nand_chip->ecc.layout->eccpos[0];
dev_info(host->dev, "Bit flip in OOB, oob_byte_pos: %d, bit_pos: %d, 0x%02x -> 0x%02x\n",
pos, bit_pos, err_byte, ecc[tmp]);
}
i++;
err_nbr--;
}
return;
}
static int pmecc_correction(struct mtd_info *mtd, u32 pmecc_stat, uint8_t *buf,
u8 *ecc)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
int i, err_nbr, eccbytes;
uint8_t *buf_pos;
int total_err = 0;
eccbytes = nand_chip->ecc.bytes;
for (i = 0; i < eccbytes; i++)
if (ecc[i] != 0xff)
goto normal_check;
return 0;
normal_check:
for (i = 0; i < host->pmecc_sector_number; i++) {
err_nbr = 0;
if (pmecc_stat & 0x1) {
buf_pos = buf + i * host->pmecc_sector_size;
pmecc_gen_syndrome(mtd, i);
pmecc_substitute(mtd);
pmecc_get_sigma(mtd);
err_nbr = pmecc_err_location(mtd);
if (err_nbr == -1) {
dev_err(host->dev, "PMECC: Too many errors\n");
mtd->ecc_stats.failed++;
return -EIO;
} else {
pmecc_correct_data(mtd, buf_pos, ecc, i,
host->pmecc_bytes_per_sector, err_nbr);
mtd->ecc_stats.corrected += err_nbr;
total_err += err_nbr;
}
}
pmecc_stat >>= 1;
}
return total_err;
}
static int atmel_nand_pmecc_read_page(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf, int oob_required, int page)
{
struct atmel_nand_host *host = chip->priv;
int eccsize = chip->ecc.size;
uint8_t *oob = chip->oob_poi;
uint32_t *eccpos = chip->ecc.layout->eccpos;
uint32_t stat;
unsigned long end_time;
int bitflips = 0;
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_RST);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DISABLE);
pmecc_writel(host->ecc, CFG, (pmecc_readl_relaxed(host->ecc, CFG)
& ~PMECC_CFG_WRITE_OP) | PMECC_CFG_AUTO_ENABLE);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_ENABLE);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DATA);
chip->read_buf(mtd, buf, eccsize);
chip->read_buf(mtd, oob, mtd->oobsize);
end_time = jiffies + msecs_to_jiffies(PMECC_MAX_TIMEOUT_MS);
while ((pmecc_readl_relaxed(host->ecc, SR) & PMECC_SR_BUSY)) {
if (unlikely(time_after(jiffies, end_time))) {
dev_err(host->dev, "PMECC: Timeout to get error status.\n");
return -EIO;
}
cpu_relax();
}
stat = pmecc_readl_relaxed(host->ecc, ISR);
if (stat != 0) {
bitflips = pmecc_correction(mtd, stat, buf, &oob[eccpos[0]]);
if (bitflips < 0)
return 0;
}
return bitflips;
}
static int atmel_nand_pmecc_write_page(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf, int oob_required)
{
struct atmel_nand_host *host = chip->priv;
uint32_t *eccpos = chip->ecc.layout->eccpos;
int i, j;
unsigned long end_time;
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_RST);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DISABLE);
pmecc_writel(host->ecc, CFG, (pmecc_readl_relaxed(host->ecc, CFG) |
PMECC_CFG_WRITE_OP) & ~PMECC_CFG_AUTO_ENABLE);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_ENABLE);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DATA);
chip->write_buf(mtd, (u8 *)buf, mtd->writesize);
end_time = jiffies + msecs_to_jiffies(PMECC_MAX_TIMEOUT_MS);
while ((pmecc_readl_relaxed(host->ecc, SR) & PMECC_SR_BUSY)) {
if (unlikely(time_after(jiffies, end_time))) {
dev_err(host->dev, "PMECC: Timeout to get ECC value.\n");
return -EIO;
}
cpu_relax();
}
for (i = 0; i < host->pmecc_sector_number; i++) {
for (j = 0; j < host->pmecc_bytes_per_sector; j++) {
int pos;
pos = i * host->pmecc_bytes_per_sector + j;
chip->oob_poi[eccpos[pos]] =
pmecc_readb_ecc_relaxed(host->ecc, i, j);
}
}
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static void atmel_pmecc_core_init(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
uint32_t val = 0;
struct nand_ecclayout *ecc_layout;
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_RST);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DISABLE);
switch (host->pmecc_corr_cap) {
case 2:
val = PMECC_CFG_BCH_ERR2;
break;
case 4:
val = PMECC_CFG_BCH_ERR4;
break;
case 8:
val = PMECC_CFG_BCH_ERR8;
break;
case 12:
val = PMECC_CFG_BCH_ERR12;
break;
case 24:
val = PMECC_CFG_BCH_ERR24;
break;
}
if (host->pmecc_sector_size == 512)
val |= PMECC_CFG_SECTOR512;
else if (host->pmecc_sector_size == 1024)
val |= PMECC_CFG_SECTOR1024;
switch (host->pmecc_sector_number) {
case 1:
val |= PMECC_CFG_PAGE_1SECTOR;
break;
case 2:
val |= PMECC_CFG_PAGE_2SECTORS;
break;
case 4:
val |= PMECC_CFG_PAGE_4SECTORS;
break;
case 8:
val |= PMECC_CFG_PAGE_8SECTORS;
break;
}
val |= (PMECC_CFG_READ_OP | PMECC_CFG_SPARE_DISABLE
| PMECC_CFG_AUTO_DISABLE);
pmecc_writel(host->ecc, CFG, val);
ecc_layout = nand_chip->ecc.layout;
pmecc_writel(host->ecc, SAREA, mtd->oobsize - 1);
pmecc_writel(host->ecc, SADDR, ecc_layout->eccpos[0]);
pmecc_writel(host->ecc, EADDR,
ecc_layout->eccpos[ecc_layout->eccbytes - 1]);
pmecc_writel(host->ecc, CLK, 2);
pmecc_writel(host->ecc, IDR, 0xff);
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_ENABLE);
}
static int get_onfi_ecc_param(struct nand_chip *chip,
int *ecc_bits, int *sector_size)
{
*ecc_bits = *sector_size = 0;
if (chip->onfi_params.ecc_bits == 0xff)
return -1;
*ecc_bits = chip->onfi_params.ecc_bits;
*sector_size = 512;
return 0;
}
static int pmecc_choose_ecc(struct atmel_nand_host *host,
int *cap, int *sector_size)
{
*cap = *sector_size = 0;
if (host->nand_chip.onfi_version) {
if (!get_onfi_ecc_param(&host->nand_chip, cap, sector_size))
dev_info(host->dev, "ONFI params, minimum required ECC: %d bits in %d bytes\n",
*cap, *sector_size);
else
dev_info(host->dev, "NAND chip ECC reqirement is in Extended ONFI parameter, we don't support yet.\n");
} else {
dev_info(host->dev, "NAND chip is not ONFI compliant, assume ecc_bits is 2 in 512 bytes");
}
if (*cap == 0 && *sector_size == 0) {
*cap = 2;
*sector_size = 512;
}
if (host->pmecc_corr_cap == 0) {
if (*cap <= 2)
host->pmecc_corr_cap = 2;
else if (*cap <= 4)
host->pmecc_corr_cap = 4;
else if (*cap < 8)
host->pmecc_corr_cap = 8;
else if (*cap < 12)
host->pmecc_corr_cap = 12;
else if (*cap < 24)
host->pmecc_corr_cap = 24;
else
return -EINVAL;
}
if (host->pmecc_sector_size == 0) {
if (*sector_size >= 1024)
host->pmecc_sector_size = 1024;
else if (*sector_size >= 512)
host->pmecc_sector_size = 512;
else
return -EINVAL;
}
return 0;
}
static int __init atmel_pmecc_nand_init_params(struct platform_device *pdev,
struct atmel_nand_host *host)
{
struct mtd_info *mtd = &host->mtd;
struct nand_chip *nand_chip = &host->nand_chip;
struct resource *regs, *regs_pmerr, *regs_rom;
int cap, sector_size, err_no;
err_no = pmecc_choose_ecc(host, &cap, &sector_size);
if (err_no) {
dev_err(host->dev, "The NAND flash's ECC requirement are not support!");
return err_no;
}
if (cap != host->pmecc_corr_cap ||
sector_size != host->pmecc_sector_size)
dev_info(host->dev, "WARNING: Be Caution! Using different PMECC parameters from Nand ONFI ECC reqirement.\n");
cap = host->pmecc_corr_cap;
sector_size = host->pmecc_sector_size;
host->pmecc_lookup_table_offset = (sector_size == 512) ?
host->pmecc_lookup_table_offset_512 :
host->pmecc_lookup_table_offset_1024;
dev_info(host->dev, "Initialize PMECC params, cap: %d, sector: %d\n",
cap, sector_size);
regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!regs) {
dev_warn(host->dev,
"Can't get I/O resource regs for PMECC controller, rolling back on software ECC\n");
nand_chip->ecc.mode = NAND_ECC_SOFT;
return 0;
}
host->ecc = ioremap(regs->start, resource_size(regs));
if (host->ecc == NULL) {
dev_err(host->dev, "ioremap failed\n");
err_no = -EIO;
goto err_pmecc_ioremap;
}
regs_pmerr = platform_get_resource(pdev, IORESOURCE_MEM, 2);
regs_rom = platform_get_resource(pdev, IORESOURCE_MEM, 3);
if (regs_pmerr && regs_rom) {
host->pmerrloc_base = ioremap(regs_pmerr->start,
resource_size(regs_pmerr));
host->pmecc_rom_base = ioremap(regs_rom->start,
resource_size(regs_rom));
}
if (!host->pmerrloc_base || !host->pmecc_rom_base) {
dev_err(host->dev,
"Can not get I/O resource for PMECC ERRLOC controller or ROM!\n");
err_no = -EIO;
goto err_pmloc_ioremap;
}
nand_chip->ecc.size = mtd->writesize;
switch (mtd->writesize) {
case 2048:
host->pmecc_degree = PMECC_GF_DIMENSION_13;
host->pmecc_cw_len = (1 << host->pmecc_degree) - 1;
host->pmecc_sector_number = mtd->writesize / sector_size;
host->pmecc_bytes_per_sector = pmecc_get_ecc_bytes(
cap, sector_size);
host->pmecc_alpha_to = pmecc_get_alpha_to(host);
host->pmecc_index_of = host->pmecc_rom_base +
host->pmecc_lookup_table_offset;
nand_chip->ecc.steps = 1;
nand_chip->ecc.strength = cap;
nand_chip->ecc.bytes = host->pmecc_bytes_per_sector *
host->pmecc_sector_number;
if (nand_chip->ecc.bytes > mtd->oobsize - 2) {
dev_err(host->dev, "No room for ECC bytes\n");
err_no = -EINVAL;
goto err_no_ecc_room;
}
pmecc_config_ecc_layout(&atmel_pmecc_oobinfo,
mtd->oobsize,
nand_chip->ecc.bytes);
nand_chip->ecc.layout = &atmel_pmecc_oobinfo;
break;
case 512:
case 1024:
case 4096:
dev_warn(host->dev,
"Unsupported page size for PMECC, use Software ECC\n");
default:
nand_chip->ecc.mode = NAND_ECC_SOFT;
return 0;
}
err_no = pmecc_data_alloc(host);
if (err_no) {
dev_err(host->dev,
"Cannot allocate memory for PMECC computation!\n");
goto err_pmecc_data_alloc;
}
nand_chip->ecc.read_page = atmel_nand_pmecc_read_page;
nand_chip->ecc.write_page = atmel_nand_pmecc_write_page;
atmel_pmecc_core_init(mtd);
return 0;
err_pmecc_data_alloc:
err_no_ecc_room:
err_pmloc_ioremap:
iounmap(host->ecc);
if (host->pmerrloc_base)
iounmap(host->pmerrloc_base);
if (host->pmecc_rom_base)
iounmap(host->pmecc_rom_base);
err_pmecc_ioremap:
return err_no;
}
static int atmel_nand_calculate(struct mtd_info *mtd,
const u_char *dat, unsigned char *ecc_code)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
unsigned int ecc_value;
ecc_value = ecc_readl(host->ecc, PR);
ecc_code[0] = ecc_value & 0xFF;
ecc_code[1] = (ecc_value >> 8) & 0xFF;
ecc_value = ecc_readl(host->ecc, NPR) & ATMEL_ECC_NPARITY;
ecc_code[2] = ecc_value & 0xFF;
ecc_code[3] = (ecc_value >> 8) & 0xFF;
return 0;
}
static int atmel_nand_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
int eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
uint32_t *eccpos = chip->ecc.layout->eccpos;
uint8_t *p = buf;
uint8_t *oob = chip->oob_poi;
uint8_t *ecc_pos;
int stat;
unsigned int max_bitflips = 0;
if (cpu_is_at32ap7000()) {
struct atmel_nand_host *host = chip->priv;
ecc_writel(host->ecc, CR, ATMEL_ECC_RST);
}
chip->read_buf(mtd, p, eccsize);
if (eccpos[0] != 0) {
chip->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + eccpos[0], -1);
}
ecc_pos = oob + eccpos[0];
chip->read_buf(mtd, ecc_pos, eccbytes);
stat = chip->ecc.correct(mtd, p, oob, NULL);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize, -1);
chip->read_buf(mtd, oob, mtd->oobsize);
return max_bitflips;
}
static int atmel_nand_correct(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *isnull)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
unsigned int ecc_status;
unsigned int ecc_word, ecc_bit;
ecc_status = ecc_readl(host->ecc, SR);
if (likely(!(ecc_status & ATMEL_ECC_RECERR)))
return 0;
ecc_bit = ecc_readl(host->ecc, PR) & ATMEL_ECC_BITADDR;
ecc_word = ecc_readl(host->ecc, PR) & ATMEL_ECC_WORDADDR;
ecc_word >>= 4;
if (ecc_status & ATMEL_ECC_MULERR) {
if ((ecc_bit == ATMEL_ECC_BITADDR)
&& (ecc_word == (ATMEL_ECC_WORDADDR >> 4))) {
return 0;
}
dev_dbg(host->dev, "atmel_nand : multiple errors detected."
" Unable to correct.\n");
return -EIO;
}
if (ecc_status & ATMEL_ECC_ECCERR) {
dev_dbg(host->dev, "atmel_nand : one bit error on ECC code."
" Nothing to correct\n");
return 0;
}
dev_dbg(host->dev, "atmel_nand : one bit error on data."
" (word offset in the page :"
" 0x%x bit offset : 0x%x)\n",
ecc_word, ecc_bit);
if (nand_chip->options & NAND_BUSWIDTH_16) {
((unsigned short *) dat)[ecc_word] ^= (1 << ecc_bit);
} else {
dat[ecc_word] ^= (1 << ecc_bit);
}
dev_dbg(host->dev, "atmel_nand : error corrected\n");
return 1;
}
static void atmel_nand_hwctl(struct mtd_info *mtd, int mode)
{
if (cpu_is_at32ap7000()) {
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
ecc_writel(host->ecc, CR, ATMEL_ECC_RST);
}
}
static int atmel_of_init_port(struct atmel_nand_host *host,
struct device_node *np)
{
u32 val;
u32 offset[2];
int ecc_mode;
struct atmel_nand_data *board = &host->board;
enum of_gpio_flags flags;
if (of_property_read_u32(np, "atmel,nand-addr-offset", &val) == 0) {
if (val >= 32) {
dev_err(host->dev, "invalid addr-offset %u\n", val);
return -EINVAL;
}
board->ale = val;
}
if (of_property_read_u32(np, "atmel,nand-cmd-offset", &val) == 0) {
if (val >= 32) {
dev_err(host->dev, "invalid cmd-offset %u\n", val);
return -EINVAL;
}
board->cle = val;
}
ecc_mode = of_get_nand_ecc_mode(np);
board->ecc_mode = ecc_mode < 0 ? NAND_ECC_SOFT : ecc_mode;
board->on_flash_bbt = of_get_nand_on_flash_bbt(np);
if (of_get_nand_bus_width(np) == 16)
board->bus_width_16 = 1;
board->rdy_pin = of_get_gpio_flags(np, 0, &flags);
board->rdy_pin_active_low = (flags == OF_GPIO_ACTIVE_LOW);
board->enable_pin = of_get_gpio(np, 1);
board->det_pin = of_get_gpio(np, 2);
host->has_pmecc = of_property_read_bool(np, "atmel,has-pmecc");
if (!(board->ecc_mode == NAND_ECC_HW) || !host->has_pmecc)
return 0;
if (of_property_read_u32(np, "atmel,pmecc-cap", &val) == 0) {
if ((val != 2) && (val != 4) && (val != 8) && (val != 12) &&
(val != 24)) {
dev_err(host->dev,
"Unsupported PMECC correction capability: %d; should be 2, 4, 8, 12 or 24\n",
val);
return -EINVAL;
}
host->pmecc_corr_cap = (u8)val;
}
if (of_property_read_u32(np, "atmel,pmecc-sector-size", &val) == 0) {
if ((val != 512) && (val != 1024)) {
dev_err(host->dev,
"Unsupported PMECC sector size: %d; should be 512 or 1024 bytes\n",
val);
return -EINVAL;
}
host->pmecc_sector_size = (u16)val;
}
if (of_property_read_u32_array(np, "atmel,pmecc-lookup-table-offset",
offset, 2) != 0) {
dev_err(host->dev, "Cannot get PMECC lookup table offset\n");
return -EINVAL;
}
if (!offset[0] && !offset[1]) {
dev_err(host->dev, "Invalid PMECC lookup table offset\n");
return -EINVAL;
}
host->pmecc_lookup_table_offset_512 = offset[0];
host->pmecc_lookup_table_offset_1024 = offset[1];
return 0;
}
static int atmel_of_init_port(struct atmel_nand_host *host,
struct device_node *np)
{
return -EINVAL;
}
static int __init atmel_hw_nand_init_params(struct platform_device *pdev,
struct atmel_nand_host *host)
{
struct mtd_info *mtd = &host->mtd;
struct nand_chip *nand_chip = &host->nand_chip;
struct resource *regs;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!regs) {
dev_err(host->dev,
"Can't get I/O resource regs, use software ECC\n");
nand_chip->ecc.mode = NAND_ECC_SOFT;
return 0;
}
host->ecc = ioremap(regs->start, resource_size(regs));
if (host->ecc == NULL) {
dev_err(host->dev, "ioremap failed\n");
return -EIO;
}
nand_chip->ecc.size = mtd->writesize;
switch (mtd->writesize) {
case 512:
nand_chip->ecc.layout = &atmel_oobinfo_small;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_528);
break;
case 1024:
nand_chip->ecc.layout = &atmel_oobinfo_large;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_1056);
break;
case 2048:
nand_chip->ecc.layout = &atmel_oobinfo_large;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_2112);
break;
case 4096:
nand_chip->ecc.layout = &atmel_oobinfo_large;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_4224);
break;
default:
nand_chip->ecc.mode = NAND_ECC_SOFT;
return 0;
}
nand_chip->ecc.calculate = atmel_nand_calculate;
nand_chip->ecc.correct = atmel_nand_correct;
nand_chip->ecc.hwctl = atmel_nand_hwctl;
nand_chip->ecc.read_page = atmel_nand_read_page;
nand_chip->ecc.bytes = 4;
nand_chip->ecc.strength = 1;
return 0;
}
static int __init atmel_nand_probe(struct platform_device *pdev)
{
struct atmel_nand_host *host;
struct mtd_info *mtd;
struct nand_chip *nand_chip;
struct resource *mem;
struct mtd_part_parser_data ppdata = {};
int res;
struct pinctrl *pinctrl;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
printk(KERN_ERR "atmel_nand: can't get I/O resource mem\n");
return -ENXIO;
}
host = kzalloc(sizeof(struct atmel_nand_host), GFP_KERNEL);
if (!host) {
printk(KERN_ERR "atmel_nand: failed to allocate device structure.\n");
return -ENOMEM;
}
host->io_phys = (dma_addr_t)mem->start;
host->io_base = ioremap(mem->start, resource_size(mem));
if (host->io_base == NULL) {
printk(KERN_ERR "atmel_nand: ioremap failed\n");
res = -EIO;
goto err_nand_ioremap;
}
mtd = &host->mtd;
nand_chip = &host->nand_chip;
host->dev = &pdev->dev;
if (pdev->dev.of_node) {
res = atmel_of_init_port(host, pdev->dev.of_node);
if (res)
goto err_ecc_ioremap;
} else {
memcpy(&host->board, pdev->dev.platform_data,
sizeof(struct atmel_nand_data));
}
nand_chip->priv = host;
mtd->priv = nand_chip;
mtd->owner = THIS_MODULE;
nand_chip->IO_ADDR_R = host->io_base;
nand_chip->IO_ADDR_W = host->io_base;
nand_chip->cmd_ctrl = atmel_nand_cmd_ctrl;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
dev_err(host->dev, "Failed to request pinctrl\n");
res = PTR_ERR(pinctrl);
goto err_ecc_ioremap;
}
if (gpio_is_valid(host->board.rdy_pin)) {
res = gpio_request(host->board.rdy_pin, "nand_rdy");
if (res < 0) {
dev_err(&pdev->dev,
"can't request rdy gpio %d\n",
host->board.rdy_pin);
goto err_ecc_ioremap;
}
res = gpio_direction_input(host->board.rdy_pin);
if (res < 0) {
dev_err(&pdev->dev,
"can't request input direction rdy gpio %d\n",
host->board.rdy_pin);
goto err_ecc_ioremap;
}
nand_chip->dev_ready = atmel_nand_device_ready;
}
if (gpio_is_valid(host->board.enable_pin)) {
res = gpio_request(host->board.enable_pin, "nand_enable");
if (res < 0) {
dev_err(&pdev->dev,
"can't request enable gpio %d\n",
host->board.enable_pin);
goto err_ecc_ioremap;
}
res = gpio_direction_output(host->board.enable_pin, 1);
if (res < 0) {
dev_err(&pdev->dev,
"can't request output direction enable gpio %d\n",
host->board.enable_pin);
goto err_ecc_ioremap;
}
}
nand_chip->ecc.mode = host->board.ecc_mode;
nand_chip->chip_delay = 20;
if (host->board.bus_width_16)
nand_chip->options |= NAND_BUSWIDTH_16;
nand_chip->read_buf = atmel_read_buf;
nand_chip->write_buf = atmel_write_buf;
platform_set_drvdata(pdev, host);
atmel_nand_enable(host);
if (gpio_is_valid(host->board.det_pin)) {
res = gpio_request(host->board.det_pin, "nand_det");
if (res < 0) {
dev_err(&pdev->dev,
"can't request det gpio %d\n",
host->board.det_pin);
goto err_no_card;
}
res = gpio_direction_input(host->board.det_pin);
if (res < 0) {
dev_err(&pdev->dev,
"can't request input direction det gpio %d\n",
host->board.det_pin);
goto err_no_card;
}
if (gpio_get_value(host->board.det_pin)) {
printk(KERN_INFO "No SmartMedia card inserted.\n");
res = -ENXIO;
goto err_no_card;
}
}
if (host->board.on_flash_bbt || on_flash_bbt) {
printk(KERN_INFO "atmel_nand: Use On Flash BBT\n");
nand_chip->bbt_options |= NAND_BBT_USE_FLASH;
}
if (!cpu_has_dma())
use_dma = 0;
if (use_dma) {
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_MEMCPY, mask);
host->dma_chan = dma_request_channel(mask, NULL, NULL);
if (!host->dma_chan) {
dev_err(host->dev, "Failed to request DMA channel\n");
use_dma = 0;
}
}
if (use_dma)
dev_info(host->dev, "Using %s for DMA transfers.\n",
dma_chan_name(host->dma_chan));
else
dev_info(host->dev, "No DMA support for NAND access.\n");
if (nand_scan_ident(mtd, 1, NULL)) {
res = -ENXIO;
goto err_scan_ident;
}
if (nand_chip->ecc.mode == NAND_ECC_HW) {
if (host->has_pmecc)
res = atmel_pmecc_nand_init_params(pdev, host);
else
res = atmel_hw_nand_init_params(pdev, host);
if (res != 0)
goto err_hw_ecc;
}
if (nand_scan_tail(mtd)) {
res = -ENXIO;
goto err_scan_tail;
}
mtd->name = "atmel_nand";
ppdata.of_node = pdev->dev.of_node;
res = mtd_device_parse_register(mtd, NULL, &ppdata,
host->board.parts, host->board.num_parts);
if (!res)
return res;
err_scan_tail:
if (host->has_pmecc && host->nand_chip.ecc.mode == NAND_ECC_HW) {
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DISABLE);
pmecc_data_free(host);
}
if (host->ecc)
iounmap(host->ecc);
if (host->pmerrloc_base)
iounmap(host->pmerrloc_base);
if (host->pmecc_rom_base)
iounmap(host->pmecc_rom_base);
err_hw_ecc:
err_scan_ident:
err_no_card:
atmel_nand_disable(host);
platform_set_drvdata(pdev, NULL);
if (host->dma_chan)
dma_release_channel(host->dma_chan);
err_ecc_ioremap:
iounmap(host->io_base);
err_nand_ioremap:
kfree(host);
return res;
}
static int __exit atmel_nand_remove(struct platform_device *pdev)
{
struct atmel_nand_host *host = platform_get_drvdata(pdev);
struct mtd_info *mtd = &host->mtd;
nand_release(mtd);
atmel_nand_disable(host);
if (host->has_pmecc && host->nand_chip.ecc.mode == NAND_ECC_HW) {
pmecc_writel(host->ecc, CTRL, PMECC_CTRL_DISABLE);
pmerrloc_writel(host->pmerrloc_base, ELDIS,
PMERRLOC_DISABLE);
pmecc_data_free(host);
}
if (gpio_is_valid(host->board.det_pin))
gpio_free(host->board.det_pin);
if (gpio_is_valid(host->board.enable_pin))
gpio_free(host->board.enable_pin);
if (gpio_is_valid(host->board.rdy_pin))
gpio_free(host->board.rdy_pin);
if (host->ecc)
iounmap(host->ecc);
if (host->pmecc_rom_base)
iounmap(host->pmecc_rom_base);
if (host->pmerrloc_base)
iounmap(host->pmerrloc_base);
if (host->dma_chan)
dma_release_channel(host->dma_chan);
iounmap(host->io_base);
kfree(host);
return 0;
}
