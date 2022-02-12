static void intel_spi_dump_regs(struct intel_spi *ispi)
{
u32 value;
int i;
dev_dbg(ispi->dev, "BFPREG=0x%08x\n", readl(ispi->base + BFPREG));
value = readl(ispi->base + HSFSTS_CTL);
dev_dbg(ispi->dev, "HSFSTS_CTL=0x%08x\n", value);
if (value & HSFSTS_CTL_FLOCKDN)
dev_dbg(ispi->dev, "-> Locked\n");
dev_dbg(ispi->dev, "FADDR=0x%08x\n", readl(ispi->base + FADDR));
dev_dbg(ispi->dev, "DLOCK=0x%08x\n", readl(ispi->base + DLOCK));
for (i = 0; i < 16; i++)
dev_dbg(ispi->dev, "FDATA(%d)=0x%08x\n",
i, readl(ispi->base + FDATA(i)));
dev_dbg(ispi->dev, "FRACC=0x%08x\n", readl(ispi->base + FRACC));
for (i = 0; i < ispi->nregions; i++)
dev_dbg(ispi->dev, "FREG(%d)=0x%08x\n", i,
readl(ispi->base + FREG(i)));
for (i = 0; i < PR_NUM; i++)
dev_dbg(ispi->dev, "PR(%d)=0x%08x\n", i,
readl(ispi->pregs + PR(i)));
value = readl(ispi->sregs + SSFSTS_CTL);
dev_dbg(ispi->dev, "SSFSTS_CTL=0x%08x\n", value);
dev_dbg(ispi->dev, "PREOP_OPTYPE=0x%08x\n",
readl(ispi->sregs + PREOP_OPTYPE));
dev_dbg(ispi->dev, "OPMENU0=0x%08x\n", readl(ispi->sregs + OPMENU0));
dev_dbg(ispi->dev, "OPMENU1=0x%08x\n", readl(ispi->sregs + OPMENU1));
if (ispi->info->type == INTEL_SPI_BYT)
dev_dbg(ispi->dev, "BCR=0x%08x\n", readl(ispi->base + BYT_BCR));
dev_dbg(ispi->dev, "Protected regions:\n");
for (i = 0; i < PR_NUM; i++) {
u32 base, limit;
value = readl(ispi->pregs + PR(i));
if (!(value & (PR_WPE | PR_RPE)))
continue;
limit = (value & PR_LIMIT_MASK) >> PR_LIMIT_SHIFT;
base = value & PR_BASE_MASK;
dev_dbg(ispi->dev, " %02d base: 0x%08x limit: 0x%08x [%c%c]\n",
i, base << 12, (limit << 12) | 0xfff,
value & PR_WPE ? 'W' : '.',
value & PR_RPE ? 'R' : '.');
}
dev_dbg(ispi->dev, "Flash regions:\n");
for (i = 0; i < ispi->nregions; i++) {
u32 region, base, limit;
region = readl(ispi->base + FREG(i));
base = region & FREG_BASE_MASK;
limit = (region & FREG_LIMIT_MASK) >> FREG_LIMIT_SHIFT;
if (base >= limit || (i > 0 && limit == 0))
dev_dbg(ispi->dev, " %02d disabled\n", i);
else
dev_dbg(ispi->dev, " %02d base: 0x%08x limit: 0x%08x\n",
i, base << 12, (limit << 12) | 0xfff);
}
dev_dbg(ispi->dev, "Using %cW sequencer for register access\n",
ispi->swseq ? 'S' : 'H');
}
static int intel_spi_read_block(struct intel_spi *ispi, void *buf, size_t size)
{
size_t bytes;
int i = 0;
if (size > INTEL_SPI_FIFO_SZ)
return -EINVAL;
while (size > 0) {
bytes = min_t(size_t, size, 4);
memcpy_fromio(buf, ispi->base + FDATA(i), bytes);
size -= bytes;
buf += bytes;
i++;
}
return 0;
}
static int intel_spi_write_block(struct intel_spi *ispi, const void *buf,
size_t size)
{
size_t bytes;
int i = 0;
if (size > INTEL_SPI_FIFO_SZ)
return -EINVAL;
while (size > 0) {
bytes = min_t(size_t, size, 4);
memcpy_toio(ispi->base + FDATA(i), buf, bytes);
size -= bytes;
buf += bytes;
i++;
}
return 0;
}
static int intel_spi_wait_hw_busy(struct intel_spi *ispi)
{
u32 val;
return readl_poll_timeout(ispi->base + HSFSTS_CTL, val,
!(val & HSFSTS_CTL_SCIP), 0,
INTEL_SPI_TIMEOUT * 1000);
}
static int intel_spi_wait_sw_busy(struct intel_spi *ispi)
{
u32 val;
return readl_poll_timeout(ispi->sregs + SSFSTS_CTL, val,
!(val & SSFSTS_CTL_SCIP), 0,
INTEL_SPI_TIMEOUT * 1000);
}
static int intel_spi_init(struct intel_spi *ispi)
{
u32 opmenu0, opmenu1, val;
int i;
switch (ispi->info->type) {
case INTEL_SPI_BYT:
ispi->sregs = ispi->base + BYT_SSFSTS_CTL;
ispi->pregs = ispi->base + BYT_PR;
ispi->nregions = BYT_FREG_NUM;
if (writeable) {
val = readl(ispi->base + BYT_BCR);
if (!(val & BYT_BCR_WPD)) {
val |= BYT_BCR_WPD;
writel(val, ispi->base + BYT_BCR);
val = readl(ispi->base + BYT_BCR);
}
ispi->writeable = !!(val & BYT_BCR_WPD);
}
break;
case INTEL_SPI_LPT:
ispi->sregs = ispi->base + LPT_SSFSTS_CTL;
ispi->pregs = ispi->base + LPT_PR;
ispi->nregions = LPT_FREG_NUM;
break;
case INTEL_SPI_BXT:
ispi->sregs = ispi->base + BXT_SSFSTS_CTL;
ispi->pregs = ispi->base + BXT_PR;
ispi->nregions = BXT_FREG_NUM;
ispi->erase_64k = true;
break;
default:
return -EINVAL;
}
val = readl(ispi->base + HSFSTS_CTL);
val &= ~HSFSTS_CTL_FSMIE;
writel(val, ispi->base + HSFSTS_CTL);
opmenu0 = readl(ispi->sregs + OPMENU0);
opmenu1 = readl(ispi->sregs + OPMENU1);
if (opmenu0 && opmenu1) {
for (i = 0; i < ARRAY_SIZE(ispi->opcodes) / 2; i++) {
ispi->opcodes[i] = opmenu0 >> i * 8;
ispi->opcodes[i + 4] = opmenu1 >> i * 8;
}
val = readl(ispi->sregs + PREOP_OPTYPE);
ispi->preopcodes[0] = val;
ispi->preopcodes[1] = val >> 8;
val = readl(ispi->sregs + SSFSTS_CTL);
val &= ~SSFSTS_CTL_FSMIE;
writel(val, ispi->sregs + SSFSTS_CTL);
ispi->swseq = true;
}
intel_spi_dump_regs(ispi);
return 0;
}
static int intel_spi_opcode_index(struct intel_spi *ispi, u8 opcode)
{
int i;
for (i = 0; i < ARRAY_SIZE(ispi->opcodes); i++)
if (ispi->opcodes[i] == opcode)
return i;
return -EINVAL;
}
static int intel_spi_hw_cycle(struct intel_spi *ispi, u8 opcode, u8 *buf,
int len)
{
u32 val, status;
int ret;
val = readl(ispi->base + HSFSTS_CTL);
val &= ~(HSFSTS_CTL_FCYCLE_MASK | HSFSTS_CTL_FDBC_MASK);
switch (opcode) {
case SPINOR_OP_RDID:
val |= HSFSTS_CTL_FCYCLE_RDID;
break;
case SPINOR_OP_WRSR:
val |= HSFSTS_CTL_FCYCLE_WRSR;
break;
case SPINOR_OP_RDSR:
val |= HSFSTS_CTL_FCYCLE_RDSR;
break;
default:
return -EINVAL;
}
val |= (len - 1) << HSFSTS_CTL_FDBC_SHIFT;
val |= HSFSTS_CTL_FCERR | HSFSTS_CTL_FDONE;
val |= HSFSTS_CTL_FGO;
writel(val, ispi->base + HSFSTS_CTL);
ret = intel_spi_wait_hw_busy(ispi);
if (ret)
return ret;
status = readl(ispi->base + HSFSTS_CTL);
if (status & HSFSTS_CTL_FCERR)
return -EIO;
else if (status & HSFSTS_CTL_AEL)
return -EACCES;
return 0;
}
static int intel_spi_sw_cycle(struct intel_spi *ispi, u8 opcode, u8 *buf,
int len)
{
u32 val, status;
int ret;
ret = intel_spi_opcode_index(ispi, opcode);
if (ret < 0)
return ret;
val = (len << SSFSTS_CTL_DBC_SHIFT) | SSFSTS_CTL_DS;
val |= ret << SSFSTS_CTL_COP_SHIFT;
val |= SSFSTS_CTL_FCERR | SSFSTS_CTL_FDONE;
val |= SSFSTS_CTL_SCGO;
writel(val, ispi->sregs + SSFSTS_CTL);
ret = intel_spi_wait_sw_busy(ispi);
if (ret)
return ret;
status = readl(ispi->base + SSFSTS_CTL);
if (status & SSFSTS_CTL_FCERR)
return -EIO;
else if (status & SSFSTS_CTL_AEL)
return -EACCES;
return 0;
}
static int intel_spi_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct intel_spi *ispi = nor->priv;
int ret;
writel(0, ispi->base + FADDR);
if (ispi->swseq)
ret = intel_spi_sw_cycle(ispi, opcode, buf, len);
else
ret = intel_spi_hw_cycle(ispi, opcode, buf, len);
if (ret)
return ret;
return intel_spi_read_block(ispi, buf, len);
}
static int intel_spi_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct intel_spi *ispi = nor->priv;
int ret;
if (opcode == SPINOR_OP_WREN)
return 0;
writel(0, ispi->base + FADDR);
ret = intel_spi_write_block(ispi, buf, len);
if (ret)
return ret;
if (ispi->swseq)
return intel_spi_sw_cycle(ispi, opcode, buf, len);
return intel_spi_hw_cycle(ispi, opcode, buf, len);
}
static ssize_t intel_spi_read(struct spi_nor *nor, loff_t from, size_t len,
u_char *read_buf)
{
struct intel_spi *ispi = nor->priv;
size_t block_size, retlen = 0;
u32 val, status;
ssize_t ret;
switch (nor->read_opcode) {
case SPINOR_OP_READ:
case SPINOR_OP_READ_FAST:
break;
default:
return -EINVAL;
}
while (len > 0) {
block_size = min_t(size_t, len, INTEL_SPI_FIFO_SZ);
writel(from, ispi->base + FADDR);
val = readl(ispi->base + HSFSTS_CTL);
val &= ~(HSFSTS_CTL_FDBC_MASK | HSFSTS_CTL_FCYCLE_MASK);
val |= HSFSTS_CTL_AEL | HSFSTS_CTL_FCERR | HSFSTS_CTL_FDONE;
val |= (block_size - 1) << HSFSTS_CTL_FDBC_SHIFT;
val |= HSFSTS_CTL_FCYCLE_READ;
val |= HSFSTS_CTL_FGO;
writel(val, ispi->base + HSFSTS_CTL);
ret = intel_spi_wait_hw_busy(ispi);
if (ret)
return ret;
status = readl(ispi->base + HSFSTS_CTL);
if (status & HSFSTS_CTL_FCERR)
ret = -EIO;
else if (status & HSFSTS_CTL_AEL)
ret = -EACCES;
if (ret < 0) {
dev_err(ispi->dev, "read error: %llx: %#x\n", from,
status);
return ret;
}
ret = intel_spi_read_block(ispi, read_buf, block_size);
if (ret)
return ret;
len -= block_size;
from += block_size;
retlen += block_size;
read_buf += block_size;
}
return retlen;
}
static ssize_t intel_spi_write(struct spi_nor *nor, loff_t to, size_t len,
const u_char *write_buf)
{
struct intel_spi *ispi = nor->priv;
size_t block_size, retlen = 0;
u32 val, status;
ssize_t ret;
while (len > 0) {
block_size = min_t(size_t, len, INTEL_SPI_FIFO_SZ);
writel(to, ispi->base + FADDR);
val = readl(ispi->base + HSFSTS_CTL);
val &= ~(HSFSTS_CTL_FDBC_MASK | HSFSTS_CTL_FCYCLE_MASK);
val |= HSFSTS_CTL_AEL | HSFSTS_CTL_FCERR | HSFSTS_CTL_FDONE;
val |= (block_size - 1) << HSFSTS_CTL_FDBC_SHIFT;
val |= HSFSTS_CTL_FCYCLE_WRITE;
if (ispi->preopcodes[1] == SPINOR_OP_WREN)
val |= SSFSTS_CTL_SPOP;
val |= SSFSTS_CTL_ACS;
writel(val, ispi->base + HSFSTS_CTL);
ret = intel_spi_write_block(ispi, write_buf, block_size);
if (ret) {
dev_err(ispi->dev, "failed to write block\n");
return ret;
}
val = readl(ispi->base + HSFSTS_CTL);
writel(val | HSFSTS_CTL_FGO, ispi->base + HSFSTS_CTL);
ret = intel_spi_wait_hw_busy(ispi);
if (ret) {
dev_err(ispi->dev, "timeout\n");
return ret;
}
status = readl(ispi->base + HSFSTS_CTL);
if (status & HSFSTS_CTL_FCERR)
ret = -EIO;
else if (status & HSFSTS_CTL_AEL)
ret = -EACCES;
if (ret < 0) {
dev_err(ispi->dev, "write error: %llx: %#x\n", to,
status);
return ret;
}
len -= block_size;
to += block_size;
retlen += block_size;
write_buf += block_size;
}
return retlen;
}
static int intel_spi_erase(struct spi_nor *nor, loff_t offs)
{
size_t erase_size, len = nor->mtd.erasesize;
struct intel_spi *ispi = nor->priv;
u32 val, status, cmd;
int ret;
if (len >= SZ_64K && ispi->erase_64k) {
cmd = HSFSTS_CTL_FCYCLE_ERASE_64K;
erase_size = SZ_64K;
} else {
cmd = HSFSTS_CTL_FCYCLE_ERASE;
erase_size = SZ_4K;
}
while (len > 0) {
writel(offs, ispi->base + FADDR);
val = readl(ispi->base + HSFSTS_CTL);
val &= ~(HSFSTS_CTL_FDBC_MASK | HSFSTS_CTL_FCYCLE_MASK);
val |= HSFSTS_CTL_AEL | HSFSTS_CTL_FCERR | HSFSTS_CTL_FDONE;
val |= cmd;
val |= HSFSTS_CTL_FGO;
writel(val, ispi->base + HSFSTS_CTL);
ret = intel_spi_wait_hw_busy(ispi);
if (ret)
return ret;
status = readl(ispi->base + HSFSTS_CTL);
if (status & HSFSTS_CTL_FCERR)
return -EIO;
else if (status & HSFSTS_CTL_AEL)
return -EACCES;
offs += erase_size;
len -= erase_size;
}
return 0;
}
static bool intel_spi_is_protected(const struct intel_spi *ispi,
unsigned int base, unsigned int limit)
{
int i;
for (i = 0; i < PR_NUM; i++) {
u32 pr_base, pr_limit, pr_value;
pr_value = readl(ispi->pregs + PR(i));
if (!(pr_value & (PR_WPE | PR_RPE)))
continue;
pr_limit = (pr_value & PR_LIMIT_MASK) >> PR_LIMIT_SHIFT;
pr_base = pr_value & PR_BASE_MASK;
if (pr_base >= base && pr_limit <= limit)
return true;
}
return false;
}
static void intel_spi_fill_partition(struct intel_spi *ispi,
struct mtd_partition *part)
{
u64 end;
int i;
memset(part, 0, sizeof(*part));
part->size = 4096;
part->name = "BIOS";
for (i = 1; i < ispi->nregions; i++) {
u32 region, base, limit;
region = readl(ispi->base + FREG(i));
base = region & FREG_BASE_MASK;
limit = (region & FREG_LIMIT_MASK) >> FREG_LIMIT_SHIFT;
if (base >= limit || limit == 0)
continue;
if (intel_spi_is_protected(ispi, base, limit))
ispi->writeable = false;
end = (limit << 12) + 4096;
if (end > part->size)
part->size = end;
}
}
struct intel_spi *intel_spi_probe(struct device *dev,
struct resource *mem, const struct intel_spi_boardinfo *info)
{
struct mtd_partition part;
struct intel_spi *ispi;
int ret;
if (!info || !mem)
return ERR_PTR(-EINVAL);
ispi = devm_kzalloc(dev, sizeof(*ispi), GFP_KERNEL);
if (!ispi)
return ERR_PTR(-ENOMEM);
ispi->base = devm_ioremap_resource(dev, mem);
if (IS_ERR(ispi->base))
return ERR_CAST(ispi->base);
ispi->dev = dev;
ispi->info = info;
ispi->writeable = info->writeable;
ret = intel_spi_init(ispi);
if (ret)
return ERR_PTR(ret);
ispi->nor.dev = ispi->dev;
ispi->nor.priv = ispi;
ispi->nor.read_reg = intel_spi_read_reg;
ispi->nor.write_reg = intel_spi_write_reg;
ispi->nor.read = intel_spi_read;
ispi->nor.write = intel_spi_write;
ispi->nor.erase = intel_spi_erase;
ret = spi_nor_scan(&ispi->nor, NULL, SPI_NOR_NORMAL);
if (ret) {
dev_info(dev, "failed to locate the chip\n");
return ERR_PTR(ret);
}
intel_spi_fill_partition(ispi, &part);
if (!ispi->writeable || !writeable)
ispi->nor.mtd.flags &= ~MTD_WRITEABLE;
ret = mtd_device_parse_register(&ispi->nor.mtd, NULL, NULL, &part, 1);
if (ret)
return ERR_PTR(ret);
return ispi;
}
int intel_spi_remove(struct intel_spi *ispi)
{
return mtd_device_unregister(&ispi->nor.mtd);
}
