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
return nor->write_reg(nor, SPINOR_OP_WRSR, nor->cmd_buf, 1);
}
static inline int write_enable(struct spi_nor *nor)
{
return nor->write_reg(nor, SPINOR_OP_WREN, NULL, 0);
}
static inline int write_disable(struct spi_nor *nor)
{
return nor->write_reg(nor, SPINOR_OP_WRDI, NULL, 0);
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
case SNOR_MFR_MICRON:
need_wren = true;
case SNOR_MFR_MACRONIX:
case SNOR_MFR_WINBOND:
if (need_wren)
write_enable(nor);
cmd = enable ? SPINOR_OP_EN4B : SPINOR_OP_EX4B;
status = nor->write_reg(nor, cmd, NULL, 0);
if (need_wren)
write_disable(nor);
return status;
default:
nor->cmd_buf[0] = enable << 7;
return nor->write_reg(nor, SPINOR_OP_BRWR, nor->cmd_buf, 1);
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
static int spi_nor_wait_till_ready_with_timeout(struct spi_nor *nor,
unsigned long timeout_jiffies)
{
unsigned long deadline;
int timeout = 0, ret;
deadline = jiffies + timeout_jiffies;
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
static int spi_nor_wait_till_ready(struct spi_nor *nor)
{
return spi_nor_wait_till_ready_with_timeout(nor,
DEFAULT_READY_WAIT_JIFFIES);
}
static int erase_chip(struct spi_nor *nor)
{
dev_dbg(nor->dev, " %lldKiB\n", (long long)(nor->mtd.size >> 10));
return nor->write_reg(nor, SPINOR_OP_CHIP_ERASE, NULL, 0);
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
static int spi_nor_erase_sector(struct spi_nor *nor, u32 addr)
{
u8 buf[SPI_NOR_MAX_ADDR_WIDTH];
int i;
if (nor->erase)
return nor->erase(nor, addr);
for (i = nor->addr_width - 1; i >= 0; i--) {
buf[i] = addr & 0xff;
addr >>= 8;
}
return nor->write_reg(nor, nor->erase_opcode, buf, nor->addr_width);
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
unsigned long timeout;
write_enable(nor);
if (erase_chip(nor)) {
ret = -EIO;
goto erase_err;
}
timeout = max(CHIP_ERASE_2MB_READY_WAIT_JIFFIES,
CHIP_ERASE_2MB_READY_WAIT_JIFFIES *
(unsigned long)(mtd->size / SZ_2M));
ret = spi_nor_wait_till_ready_with_timeout(nor, timeout);
if (ret)
goto erase_err;
} else {
while (len) {
write_enable(nor);
ret = spi_nor_erase_sector(nor, addr);
if (ret)
goto erase_err;
addr += mtd->erasesize;
len -= mtd->erasesize;
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto erase_err;
}
}
write_disable(nor);
erase_err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_ERASE);
instr->state = ret ? MTD_ERASE_FAILED : MTD_ERASE_DONE;
mtd_erase_callback(instr);
return ret;
}
static void stm_get_locked_range(struct spi_nor *nor, u8 sr, loff_t *ofs,
uint64_t *len)
{
struct mtd_info *mtd = &nor->mtd;
u8 mask = SR_BP2 | SR_BP1 | SR_BP0;
int shift = ffs(mask) - 1;
int pow;
if (!(sr & mask)) {
*ofs = 0;
*len = 0;
} else {
pow = ((sr & mask) ^ mask) >> shift;
*len = mtd->size >> pow;
if (nor->flags & SNOR_F_HAS_SR_TB && sr & SR_TB)
*ofs = 0;
else
*ofs = mtd->size - *len;
}
}
static int stm_check_lock_status_sr(struct spi_nor *nor, loff_t ofs, uint64_t len,
u8 sr, bool locked)
{
loff_t lock_offs;
uint64_t lock_len;
if (!len)
return 1;
stm_get_locked_range(nor, sr, &lock_offs, &lock_len);
if (locked)
return (ofs + len <= lock_offs + lock_len) && (ofs >= lock_offs);
else
return (ofs >= lock_offs + lock_len) || (ofs + len <= lock_offs);
}
static int stm_is_locked_sr(struct spi_nor *nor, loff_t ofs, uint64_t len,
u8 sr)
{
return stm_check_lock_status_sr(nor, ofs, len, sr, true);
}
static int stm_is_unlocked_sr(struct spi_nor *nor, loff_t ofs, uint64_t len,
u8 sr)
{
return stm_check_lock_status_sr(nor, ofs, len, sr, false);
}
static int stm_lock(struct spi_nor *nor, loff_t ofs, uint64_t len)
{
struct mtd_info *mtd = &nor->mtd;
int status_old, status_new;
u8 mask = SR_BP2 | SR_BP1 | SR_BP0;
u8 shift = ffs(mask) - 1, pow, val;
loff_t lock_len;
bool can_be_top = true, can_be_bottom = nor->flags & SNOR_F_HAS_SR_TB;
bool use_top;
int ret;
status_old = read_sr(nor);
if (status_old < 0)
return status_old;
if (stm_is_locked_sr(nor, ofs, len, status_old))
return 0;
if (!stm_is_locked_sr(nor, 0, ofs, status_old))
can_be_bottom = false;
if (!stm_is_locked_sr(nor, ofs + len, mtd->size - (ofs + len),
status_old))
can_be_top = false;
if (!can_be_bottom && !can_be_top)
return -EINVAL;
use_top = can_be_top;
if (use_top)
lock_len = mtd->size - ofs;
else
lock_len = ofs + len;
pow = ilog2(mtd->size) - ilog2(lock_len);
val = mask - (pow << shift);
if (val & ~mask)
return -EINVAL;
if (!(val & mask))
return -EINVAL;
status_new = (status_old & ~mask & ~SR_TB) | val;
status_new |= SR_SRWD;
if (!use_top)
status_new |= SR_TB;
if (status_new == status_old)
return 0;
if ((status_new & mask) < (status_old & mask))
return -EINVAL;
write_enable(nor);
ret = write_sr(nor, status_new);
if (ret)
return ret;
return spi_nor_wait_till_ready(nor);
}
static int stm_unlock(struct spi_nor *nor, loff_t ofs, uint64_t len)
{
struct mtd_info *mtd = &nor->mtd;
int status_old, status_new;
u8 mask = SR_BP2 | SR_BP1 | SR_BP0;
u8 shift = ffs(mask) - 1, pow, val;
loff_t lock_len;
bool can_be_top = true, can_be_bottom = nor->flags & SNOR_F_HAS_SR_TB;
bool use_top;
int ret;
status_old = read_sr(nor);
if (status_old < 0)
return status_old;
if (stm_is_unlocked_sr(nor, ofs, len, status_old))
return 0;
if (!stm_is_unlocked_sr(nor, 0, ofs, status_old))
can_be_top = false;
if (!stm_is_unlocked_sr(nor, ofs + len, mtd->size - (ofs + len),
status_old))
can_be_bottom = false;
if (!can_be_bottom && !can_be_top)
return -EINVAL;
use_top = can_be_top;
if (use_top)
lock_len = mtd->size - (ofs + len);
else
lock_len = ofs;
pow = ilog2(mtd->size) - order_base_2(lock_len);
if (lock_len == 0) {
val = 0;
} else {
val = mask - (pow << shift);
if (val & ~mask)
return -EINVAL;
}
status_new = (status_old & ~mask & ~SR_TB) | val;
if (lock_len == 0)
status_new &= ~SR_SRWD;
if (!use_top)
status_new |= SR_TB;
if (status_new == status_old)
return 0;
if ((status_new & mask) > (status_old & mask))
return -EINVAL;
write_enable(nor);
ret = write_sr(nor, status_new);
if (ret)
return ret;
return spi_nor_wait_till_ready(nor);
}
static int stm_is_locked(struct spi_nor *nor, loff_t ofs, uint64_t len)
{
int status;
status = read_sr(nor);
if (status < 0)
return status;
return stm_is_locked_sr(nor, ofs, len, status);
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
static int spi_nor_is_locked(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
int ret;
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_UNLOCK);
if (ret)
return ret;
ret = nor->flash_is_locked(nor, ofs, len);
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
dev_dbg(nor->dev, "error %d reading JEDEC ID\n", tmp);
return ERR_PTR(tmp);
}
for (tmp = 0; tmp < ARRAY_SIZE(spi_nor_ids) - 1; tmp++) {
info = &spi_nor_ids[tmp];
if (info->id_len) {
if (!memcmp(info->id, id, info->id_len))
return &spi_nor_ids[tmp];
}
}
dev_err(nor->dev, "unrecognized JEDEC id bytes: %02x, %02x, %02x\n",
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
while (len) {
ret = nor->read(nor, from, len, buf);
if (ret == 0) {
ret = -EIO;
goto read_err;
}
if (ret < 0)
goto read_err;
WARN_ON(ret > len);
*retlen += ret;
buf += ret;
from += ret;
len -= ret;
}
ret = 0;
read_err:
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
ret = nor->write(nor, to, 1, buf);
if (ret < 0)
goto sst_write_err;
WARN(ret != 1, "While writing 1 byte written %i bytes\n",
(int)ret);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto sst_write_err;
}
to += actual;
for (; actual < len - 1; actual += 2) {
nor->program_opcode = SPINOR_OP_AAI_WP;
ret = nor->write(nor, to, 2, buf + actual);
if (ret < 0)
goto sst_write_err;
WARN(ret != 2, "While writing 2 bytes written %i bytes\n",
(int)ret);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto sst_write_err;
to += 2;
nor->sst_write_second = true;
}
nor->sst_write_second = false;
write_disable(nor);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto sst_write_err;
if (actual != len) {
write_enable(nor);
nor->program_opcode = SPINOR_OP_BP;
ret = nor->write(nor, to, 1, buf + actual);
if (ret < 0)
goto sst_write_err;
WARN(ret != 1, "While writing 1 byte written %i bytes\n",
(int)ret);
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto sst_write_err;
write_disable(nor);
actual += 1;
}
sst_write_err:
*retlen += actual;
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_WRITE);
return ret;
}
static int spi_nor_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
size_t page_offset, page_remain, i;
ssize_t ret;
dev_dbg(nor->dev, "to 0x%08x, len %zd\n", (u32)to, len);
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_WRITE);
if (ret)
return ret;
for (i = 0; i < len; ) {
ssize_t written;
page_offset = (to + i) & (nor->page_size - 1);
WARN_ONCE(page_offset,
"Writing at offset %zu into a NOR page. Writing partial pages may decrease reliability and increase wear of NOR flash.",
page_offset);
page_remain = min_t(size_t,
nor->page_size - page_offset, len - i);
write_enable(nor);
ret = nor->write(nor, to + i, page_remain, buf + i);
if (ret < 0)
goto write_err;
written = ret;
ret = spi_nor_wait_till_ready(nor);
if (ret)
goto write_err;
*retlen += written;
i += written;
if (written != page_remain) {
dev_err(nor->dev,
"While writing %zu bytes written %zd bytes\n",
page_remain, written);
ret = -EIO;
goto write_err;
}
}
write_err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_WRITE);
return ret;
}
static int macronix_quad_enable(struct spi_nor *nor)
{
int ret, val;
val = read_sr(nor);
if (val < 0)
return val;
write_enable(nor);
write_sr(nor, val | SR_QUAD_EN_MX);
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
return nor->write_reg(nor, SPINOR_OP_WRSR, nor->cmd_buf, 2);
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
static int set_quad_mode(struct spi_nor *nor, const struct flash_info *info)
{
int status;
switch (JEDEC_MFR(info)) {
case SNOR_MFR_MACRONIX:
status = macronix_quad_enable(nor);
if (status) {
dev_err(nor->dev, "Macronix quad-read not enabled\n");
return -EINVAL;
}
return status;
case SNOR_MFR_MICRON:
return 0;
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
!nor->read_reg || !nor->write_reg) {
pr_err("spi-nor: please fill all the necessary fields!\n");
return -EINVAL;
}
return 0;
}
int spi_nor_scan(struct spi_nor *nor, const char *name, enum read_mode mode)
{
const struct flash_info *info = NULL;
struct device *dev = nor->dev;
struct mtd_info *mtd = &nor->mtd;
struct device_node *np = spi_nor_get_flash_node(nor);
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
if (JEDEC_MFR(info) == SNOR_MFR_ATMEL ||
JEDEC_MFR(info) == SNOR_MFR_INTEL ||
JEDEC_MFR(info) == SNOR_MFR_SST ||
info->flags & SPI_NOR_HAS_LOCK) {
write_enable(nor);
write_sr(nor, 0);
spi_nor_wait_till_ready(nor);
}
if (!mtd->name)
mtd->name = dev_name(dev);
mtd->priv = nor;
mtd->type = MTD_NORFLASH;
mtd->writesize = 1;
mtd->flags = MTD_CAP_NORFLASH;
mtd->size = info->sector_size * info->n_sectors;
mtd->_erase = spi_nor_erase;
mtd->_read = spi_nor_read;
if (JEDEC_MFR(info) == SNOR_MFR_MICRON ||
info->flags & SPI_NOR_HAS_LOCK) {
nor->flash_lock = stm_lock;
nor->flash_unlock = stm_unlock;
nor->flash_is_locked = stm_is_locked;
}
if (nor->flash_lock && nor->flash_unlock && nor->flash_is_locked) {
mtd->_lock = spi_nor_lock;
mtd->_unlock = spi_nor_unlock;
mtd->_is_locked = spi_nor_is_locked;
}
if (info->flags & SST_WRITE)
mtd->_write = sst_write;
else
mtd->_write = spi_nor_write;
if (info->flags & USE_FSR)
nor->flags |= SNOR_F_USE_FSR;
if (info->flags & SPI_NOR_HAS_TB)
nor->flags |= SNOR_F_HAS_SR_TB;
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
if (JEDEC_MFR(info) == SNOR_MFR_SPANSION) {
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
if (nor->addr_width > SPI_NOR_MAX_ADDR_WIDTH) {
dev_err(dev, "address width is too large: %u\n",
nor->addr_width);
return -EINVAL;
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
