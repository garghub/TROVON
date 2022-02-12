static int read_sr(struct spi_nor *nor)
{
int ret;
u8 val;
ret = nor->read_reg(nor, SPINOR_OP_RDSR, &val, 1);
if (ret < 0) {
pr_err("error %d reading SR\n", (int) ret);
return ret;
}
return val;
}
static int read_fsr(struct spi_nor *nor)
{
int ret;
u8 val;
ret = nor->read_reg(nor, SPINOR_OP_RDFSR, &val, 1);
if (ret < 0) {
pr_err("error %d reading FSR\n", ret);
return ret;
}
return val;
}
static int read_cr(struct spi_nor *nor)
{
int ret;
u8 val;
ret = nor->read_reg(nor, SPINOR_OP_RDCR, &val, 1);
if (ret < 0) {
dev_err(nor->dev, "error %d reading CR\n", ret);
return ret;
}
return val;
}
static inline int spi_nor_read_dummy_cycles(struct spi_nor *nor)
{
switch (nor->flash_read) {
case SPI_NOR_FAST:
case SPI_NOR_DUAL:
case SPI_NOR_QUAD:
return 8;
case SPI_NOR_NORMAL:
return 0;
}
return 0;
}
static inline int write_sr(struct spi_nor *nor, u8 val)
{
nor->cmd_buf[0] = val;
return nor->write_reg(nor, SPINOR_OP_WRSR, nor->cmd_buf, 1, 0);
}
static inline int write_enable(struct spi_nor *nor)
{
return nor->write_reg(nor, SPINOR_OP_WREN, NULL, 0, 0);
}
static inline int write_disable(struct spi_nor *nor)
{
return nor->write_reg(nor, SPINOR_OP_WRDI, NULL, 0, 0);
}
static inline struct spi_nor *mtd_to_spi_nor(struct mtd_info *mtd)
{
return mtd->priv;
}
static inline int set_4byte(struct spi_nor *nor, const struct flash_info *info,
int enable)
{
int status;
bool need_wren = false;
u8 cmd;
switch (JEDEC_MFR(info)) {
case CFI_MFR_ST:
need_wren = true;
case CFI_MFR_MACRONIX:
case 0xEF :
if (need_wren)
write_enable(nor);
cmd = enable ? SPINOR_OP_EN4B : SPINOR_OP_EX4B;
status = nor->write_reg(nor, cmd, NULL, 0, 0);
if (need_wren)
write_disable(nor);
return status;
default:
nor->cmd_buf[0] = enable << 7;
return nor->write_reg(nor, SPINOR_OP_BRWR, nor->cmd_buf, 1, 0);
}
}
static inline int spi_nor_sr_ready(struct spi_nor *nor)
{
int sr = read_sr(nor);
if (sr < 0)
return sr;
else
return !(sr & SR_WIP);
}
static inline int spi_nor_fsr_ready(struct spi_nor *nor)
{
int fsr = read_fsr(nor);
if (fsr < 0)
return fsr;
else
return fsr & FSR_READY;
}
static int spi_nor_ready(struct spi_nor *nor)
{
int sr, fsr;
sr = spi_nor_sr_ready(nor);
if (sr < 0)
return sr;
fsr = nor->flags & SNOR_F_USE_FSR ? spi_nor_fsr_ready(nor) : 1;
if (fsr < 0)
return fsr;
return sr && fsr;
}
static int spi_nor_wait_till_ready(struct spi_nor *nor)
{
unsigned long deadline;
int timeout = 0, ret;
deadline = jiffies + MAX_READY_WAIT_JIFFIES;
while (!timeout) {
if (time_after_eq(jiffies, deadline))
timeout = 1;
ret = spi_nor_ready(nor);
if (ret < 0)
return ret;
if (ret)
return 0;
cond_resched();
}
dev_err(nor->dev, "flash operation timed out\n");
return -ETIMEDOUT;
}
static int erase_chip(struct spi_nor *nor)
{
dev_dbg(nor->dev, " %lldKiB\n", (long long)(nor->mtd->size >> 10));
return nor->write_reg(nor, SPINOR_OP_CHIP_ERASE, NULL, 0, 0);
}
static int spi_nor_lock_and_prep(struct spi_nor *nor, enum spi_nor_ops ops)
{
int ret = 0;
mutex_lock(&nor->lock);
if (nor->prepare) {
ret = nor->prepare(nor, ops);
if (ret) {
dev_err(nor->dev, "failed in the preparation.\n");
mutex_unlock(&nor->lock);
return ret;
}
}
return ret;
}
static void spi_nor_unlock_and_unprep(struct spi_nor *nor, enum spi_nor_ops ops)
{
if (nor->unprepare)
nor->unprepare(nor, ops);
mutex_unlock(&nor->lock);
}
static int spi_nor_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
u32 addr, len;
uint32_t rem;
int ret;
dev_dbg(nor->dev, "at 0x%llx, len %lld\n", (long long)instr->addr,
(long long)instr->len);
div_u64_rem(instr->len, mtd->erasesize, &rem);
if (rem)
return -EINVAL;
addr = instr->addr;
len = instr->len;
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_ERASE);
if (ret)
return ret;
if (len == mtd->size) {
write_enable(nor);
if (erase_chip(nor)) {
ret = -EIO;
goto erase_err;
}
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto erase_err;
} else {
while (len) {
write_enable(nor);
if (nor->erase(nor, addr)) {
ret = -EIO;
goto erase_err;
}
addr += mtd->erasesize;
len -= mtd->erasesize;
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto erase_err;
}
}
write_disable(nor);
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_ERASE);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return ret;
erase_err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_ERASE);
instr->state = MTD_ERASE_FAILED;
return ret;
}
static int stm_lock(struct spi_nor *nor, loff_t ofs, uint64_t len)
{
struct mtd_info *mtd = nor->mtd;
uint32_t offset = ofs;
uint8_t status_old, status_new;
int ret = 0;
status_old = read_sr(nor);
if (offset < mtd->size - (mtd->size / 2))
status_new = status_old | SR_BP2 | SR_BP1 | SR_BP0;
else if (offset < mtd->size - (mtd->size / 4))
status_new = (status_old & ~SR_BP0) | SR_BP2 | SR_BP1;
else if (offset < mtd->size - (mtd->size / 8))
status_new = (status_old & ~SR_BP1) | SR_BP2 | SR_BP0;
else if (offset < mtd->size - (mtd->size / 16))
status_new = (status_old & ~(SR_BP0 | SR_BP1)) | SR_BP2;
else if (offset < mtd->size - (mtd->size / 32))
status_new = (status_old & ~SR_BP2) | SR_BP1 | SR_BP0;
else if (offset < mtd->size - (mtd->size / 64))
status_new = (status_old & ~(SR_BP2 | SR_BP0)) | SR_BP1;
else
status_new = (status_old & ~(SR_BP2 | SR_BP1)) | SR_BP0;
if ((status_new & (SR_BP2 | SR_BP1 | SR_BP0)) >
(status_old & (SR_BP2 | SR_BP1 | SR_BP0))) {
write_enable(nor);
ret = write_sr(nor, status_new);
}
return ret;
}
static int stm_unlock(struct spi_nor *nor, loff_t ofs, uint64_t len)
{
struct mtd_info *mtd = nor->mtd;
uint32_t offset = ofs;
uint8_t status_old, status_new;
int ret = 0;
status_old = read_sr(nor);
if (offset+len > mtd->size - (mtd->size / 64))
status_new = status_old & ~(SR_BP2 | SR_BP1 | SR_BP0);
else if (offset+len > mtd->size - (mtd->size / 32))
status_new = (status_old & ~(SR_BP2 | SR_BP1)) | SR_BP0;
else if (offset+len > mtd->size - (mtd->size / 16))
status_new = (status_old & ~(SR_BP2 | SR_BP0)) | SR_BP1;
else if (offset+len > mtd->size - (mtd->size / 8))
status_new = (status_old & ~SR_BP2) | SR_BP1 | SR_BP0;
else if (offset+len > mtd->size - (mtd->size / 4))
status_new = (status_old & ~(SR_BP0 | SR_BP1)) | SR_BP2;
else if (offset+len > mtd->size - (mtd->size / 2))
status_new = (status_old & ~SR_BP1) | SR_BP2 | SR_BP0;
else
status_new = (status_old & ~SR_BP0) | SR_BP2 | SR_BP1;
if ((status_new & (SR_BP2 | SR_BP1 | SR_BP0)) <
(status_old & (SR_BP2 | SR_BP1 | SR_BP0))) {
write_enable(nor);
ret = write_sr(nor, status_new);
}
return ret;
}
static int spi_nor_lock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
int ret;
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_LOCK);
if (ret)
return ret;
ret = nor->flash_lock(nor, ofs, len);
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_UNLOCK);
return ret;
}
static int spi_nor_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
int ret;
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_UNLOCK);
if (ret)
return ret;
ret = nor->flash_unlock(nor, ofs, len);
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_LOCK);
return ret;
}
static const struct flash_info *spi_nor_read_id(struct spi_nor *nor)
{
int tmp;
u8 id[SPI_NOR_MAX_ID_LEN];
const struct flash_info *info;
tmp = nor->read_reg(nor, SPINOR_OP_RDID, id, SPI_NOR_MAX_ID_LEN);
if (tmp < 0) {
dev_dbg(nor->dev, " error %d reading JEDEC ID\n", tmp);
return ERR_PTR(tmp);
}
for (tmp = 0; tmp < ARRAY_SIZE(spi_nor_ids) - 1; tmp++) {
info = &spi_nor_ids[tmp];
if (info->id_len) {
if (!memcmp(info->id, id, info->id_len))
return &spi_nor_ids[tmp];
}
}
dev_err(nor->dev, "unrecognized JEDEC id bytes: %02x, %2x, %2x\n",
id[0], id[1], id[2]);
return ERR_PTR(-ENODEV);
}
static int spi_nor_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
int ret;
dev_dbg(nor->dev, "from 0x%08x, len %zd\n", (u32)from, len);
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_READ);
if (ret)
return ret;
ret = nor->read(nor, from, len, retlen, buf);
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_READ);
return ret;
}
static int sst_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
size_t actual;
int ret;
dev_dbg(nor->dev, "to 0x%08x, len %zd\n", (u32)to, len);
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_WRITE);
if (ret)
return ret;
write_enable(nor);
nor->sst_write_second = false;
actual = to % 2;
if (actual) {
nor->program_opcode = SPINOR_OP_BP;
nor->write(nor, to, 1, retlen, buf);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto time_out;
}
to += actual;
for (; actual < len - 1; actual += 2) {
nor->program_opcode = SPINOR_OP_AAI_WP;
nor->write(nor, to, 2, retlen, buf + actual);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto time_out;
to += 2;
nor->sst_write_second = true;
}
nor->sst_write_second = false;
write_disable(nor);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto time_out;
if (actual != len) {
write_enable(nor);
nor->program_opcode = SPINOR_OP_BP;
nor->write(nor, to, 1, retlen, buf + actual);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto time_out;
write_disable(nor);
}
time_out:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_WRITE);
return ret;
}
static int spi_nor_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
u32 page_offset, page_size, i;
int ret;
dev_dbg(nor->dev, "to 0x%08x, len %zd\n", (u32)to, len);
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_WRITE);
if (ret)
return ret;
write_enable(nor);
page_offset = to & (nor->page_size - 1);
if (page_offset + len <= nor->page_size) {
nor->write(nor, to, len, retlen, buf);
} else {
page_size = nor->page_size - page_offset;
nor->write(nor, to, page_size, retlen, buf);
for (i = page_size; i < len; i += page_size) {
page_size = len - i;
if (page_size > nor->page_size)
page_size = nor->page_size;
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto write_err;
write_enable(nor);
nor->write(nor, to + i, page_size, retlen, buf + i);
}
}
ret = spi_nor_wait_till_ready(nor);
write_err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_WRITE);
return ret;
}
static int macronix_quad_enable(struct spi_nor *nor)
{
int ret, val;
val = read_sr(nor);
write_enable(nor);
nor->cmd_buf[0] = val | SR_QUAD_EN_MX;
nor->write_reg(nor, SPINOR_OP_WRSR, nor->cmd_buf, 1, 0);
if (spi_nor_wait_till_ready(nor))
return 1;
ret = read_sr(nor);
if (!(ret > 0 && (ret & SR_QUAD_EN_MX))) {
dev_err(nor->dev, "Macronix Quad bit not set\n");
return -EINVAL;
}
return 0;
}
static int write_sr_cr(struct spi_nor *nor, u16 val)
{
nor->cmd_buf[0] = val & 0xff;
nor->cmd_buf[1] = (val >> 8);
return nor->write_reg(nor, SPINOR_OP_WRSR, nor->cmd_buf, 2, 0);
}
static int spansion_quad_enable(struct spi_nor *nor)
{
int ret;
int quad_en = CR_QUAD_EN_SPAN << 8;
write_enable(nor);
ret = write_sr_cr(nor, quad_en);
if (ret < 0) {
dev_err(nor->dev,
"error while writing configuration register\n");
return -EINVAL;
}
ret = read_cr(nor);
if (!(ret > 0 && (ret & CR_QUAD_EN_SPAN))) {
dev_err(nor->dev, "Spansion Quad bit not set\n");
return -EINVAL;
}
return 0;
}
static int micron_quad_enable(struct spi_nor *nor)
{
int ret;
u8 val;
ret = nor->read_reg(nor, SPINOR_OP_RD_EVCR, &val, 1);
if (ret < 0) {
dev_err(nor->dev, "error %d reading EVCR\n", ret);
return ret;
}
write_enable(nor);
nor->cmd_buf[0] = val & ~EVCR_QUAD_EN_MICRON;
ret = nor->write_reg(nor, SPINOR_OP_WD_EVCR, nor->cmd_buf, 1, 0);
if (ret < 0) {
dev_err(nor->dev, "error while writing EVCR register\n");
return ret;
}
ret = spi_nor_wait_till_ready(nor);
if (ret)
return ret;
ret = nor->read_reg(nor, SPINOR_OP_RD_EVCR, &val, 1);
if (ret < 0) {
dev_err(nor->dev, "error %d reading EVCR\n", ret);
return ret;
}
if (val & EVCR_QUAD_EN_MICRON) {
dev_err(nor->dev, "Micron EVCR Quad bit not clear\n");
return -EINVAL;
}
return 0;
}
static int set_quad_mode(struct spi_nor *nor, const struct flash_info *info)
{
int status;
switch (JEDEC_MFR(info)) {
case CFI_MFR_MACRONIX:
status = macronix_quad_enable(nor);
if (status) {
dev_err(nor->dev, "Macronix quad-read not enabled\n");
return -EINVAL;
}
return status;
case CFI_MFR_ST:
status = micron_quad_enable(nor);
if (status) {
dev_err(nor->dev, "Micron quad-read not enabled\n");
return -EINVAL;
}
return status;
default:
status = spansion_quad_enable(nor);
if (status) {
dev_err(nor->dev, "Spansion quad-read not enabled\n");
return -EINVAL;
}
return status;
}
}
static int spi_nor_check(struct spi_nor *nor)
{
if (!nor->dev || !nor->read || !nor->write ||
!nor->read_reg || !nor->write_reg || !nor->erase) {
pr_err("spi-nor: please fill all the necessary fields!\n");
return -EINVAL;
}
return 0;
}
int spi_nor_scan(struct spi_nor *nor, const char *name, enum read_mode mode)
{
const struct flash_info *info = NULL;
struct device *dev = nor->dev;
struct mtd_info *mtd = nor->mtd;
struct device_node *np = dev->of_node;
int ret;
int i;
ret = spi_nor_check(nor);
if (ret)
return ret;
if (name)
info = spi_nor_match_id(name);
if (!info)
info = spi_nor_read_id(nor);
if (IS_ERR_OR_NULL(info))
return -ENOENT;
if (name && info->id_len) {
const struct flash_info *jinfo;
jinfo = spi_nor_read_id(nor);
if (IS_ERR(jinfo)) {
return PTR_ERR(jinfo);
} else if (jinfo != info) {
dev_warn(dev, "found %s, expected %s\n",
jinfo->name, info->name);
info = jinfo;
}
}
mutex_init(&nor->lock);
if (JEDEC_MFR(info) == CFI_MFR_ATMEL ||
JEDEC_MFR(info) == CFI_MFR_INTEL ||
JEDEC_MFR(info) == CFI_MFR_SST) {
write_enable(nor);
write_sr(nor, 0);
}
if (!mtd->name)
mtd->name = dev_name(dev);
mtd->type = MTD_NORFLASH;
mtd->writesize = 1;
mtd->flags = MTD_CAP_NORFLASH;
mtd->size = info->sector_size * info->n_sectors;
mtd->_erase = spi_nor_erase;
mtd->_read = spi_nor_read;
if (JEDEC_MFR(info) == CFI_MFR_ST) {
nor->flash_lock = stm_lock;
nor->flash_unlock = stm_unlock;
}
if (nor->flash_lock && nor->flash_unlock) {
mtd->_lock = spi_nor_lock;
mtd->_unlock = spi_nor_unlock;
}
if (info->flags & SST_WRITE)
mtd->_write = sst_write;
else
mtd->_write = spi_nor_write;
if (info->flags & USE_FSR)
nor->flags |= SNOR_F_USE_FSR;
#ifdef CONFIG_MTD_SPI_NOR_USE_4K_SECTORS
if (info->flags & SECT_4K) {
nor->erase_opcode = SPINOR_OP_BE_4K;
mtd->erasesize = 4096;
} else if (info->flags & SECT_4K_PMC) {
nor->erase_opcode = SPINOR_OP_BE_4K_PMC;
mtd->erasesize = 4096;
} else
#endif
{
nor->erase_opcode = SPINOR_OP_SE;
mtd->erasesize = info->sector_size;
}
if (info->flags & SPI_NOR_NO_ERASE)
mtd->flags |= MTD_NO_ERASE;
mtd->dev.parent = dev;
nor->page_size = info->page_size;
mtd->writebufsize = nor->page_size;
if (np) {
if (of_property_read_bool(np, "m25p,fast-read"))
nor->flash_read = SPI_NOR_FAST;
else
nor->flash_read = SPI_NOR_NORMAL;
} else {
nor->flash_read = SPI_NOR_FAST;
}
if (info->flags & SPI_NOR_NO_FR)
nor->flash_read = SPI_NOR_NORMAL;
if (mode == SPI_NOR_QUAD && info->flags & SPI_NOR_QUAD_READ) {
ret = set_quad_mode(nor, info);
if (ret) {
dev_err(dev, "quad mode not supported\n");
return ret;
}
nor->flash_read = SPI_NOR_QUAD;
} else if (mode == SPI_NOR_DUAL && info->flags & SPI_NOR_DUAL_READ) {
nor->flash_read = SPI_NOR_DUAL;
}
switch (nor->flash_read) {
case SPI_NOR_QUAD:
nor->read_opcode = SPINOR_OP_READ_1_1_4;
break;
case SPI_NOR_DUAL:
nor->read_opcode = SPINOR_OP_READ_1_1_2;
break;
case SPI_NOR_FAST:
nor->read_opcode = SPINOR_OP_READ_FAST;
break;
case SPI_NOR_NORMAL:
nor->read_opcode = SPINOR_OP_READ;
break;
default:
dev_err(dev, "No Read opcode defined\n");
return -EINVAL;
}
nor->program_opcode = SPINOR_OP_PP;
if (info->addr_width)
nor->addr_width = info->addr_width;
else if (mtd->size > 0x1000000) {
nor->addr_width = 4;
if (JEDEC_MFR(info) == CFI_MFR_AMD) {
switch (nor->flash_read) {
case SPI_NOR_QUAD:
nor->read_opcode = SPINOR_OP_READ4_1_1_4;
break;
case SPI_NOR_DUAL:
nor->read_opcode = SPINOR_OP_READ4_1_1_2;
break;
case SPI_NOR_FAST:
nor->read_opcode = SPINOR_OP_READ4_FAST;
break;
case SPI_NOR_NORMAL:
nor->read_opcode = SPINOR_OP_READ4;
break;
}
nor->program_opcode = SPINOR_OP_PP_4B;
nor->erase_opcode = SPINOR_OP_SE_4B;
mtd->erasesize = info->sector_size;
} else
set_4byte(nor, info, 1);
} else {
nor->addr_width = 3;
}
nor->read_dummy = spi_nor_read_dummy_cycles(nor);
dev_info(dev, "%s (%lld Kbytes)\n", info->name,
(long long)mtd->size >> 10);
dev_dbg(dev,
"mtd .name = %s, .size = 0x%llx (%lldMiB), "
".erasesize = 0x%.8x (%uKiB) .numeraseregions = %d\n",
mtd->name, (long long)mtd->size, (long long)(mtd->size >> 20),
mtd->erasesize, mtd->erasesize / 1024, mtd->numeraseregions);
if (mtd->numeraseregions)
for (i = 0; i < mtd->numeraseregions; i++)
dev_dbg(dev,
"mtd.eraseregions[%d] = { .offset = 0x%llx, "
".erasesize = 0x%.8x (%uKiB), "
".numblocks = %d }\n",
i, (long long)mtd->eraseregions[i].offset,
mtd->eraseregions[i].erasesize,
mtd->eraseregions[i].erasesize / 1024,
mtd->eraseregions[i].numblocks);
return 0;
}
static const struct flash_info *spi_nor_match_id(const char *name)
{
const struct flash_info *id = spi_nor_ids;
while (id->name) {
if (!strcmp(name, id->name))
return id;
id++;
}
return NULL;
}
