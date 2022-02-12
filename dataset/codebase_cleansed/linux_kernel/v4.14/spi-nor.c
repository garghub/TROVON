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
static u8 spi_nor_convert_opcode(u8 opcode, const u8 table[][2], size_t size)
{
size_t i;
for (i = 0; i < size; i++)
if (table[i][0] == opcode)
return table[i][1];
return opcode;
}
static inline u8 spi_nor_convert_3to4_read(u8 opcode)
{
static const u8 spi_nor_3to4_read[][2] = {
{ SPINOR_OP_READ, SPINOR_OP_READ_4B },
{ SPINOR_OP_READ_FAST, SPINOR_OP_READ_FAST_4B },
{ SPINOR_OP_READ_1_1_2, SPINOR_OP_READ_1_1_2_4B },
{ SPINOR_OP_READ_1_2_2, SPINOR_OP_READ_1_2_2_4B },
{ SPINOR_OP_READ_1_1_4, SPINOR_OP_READ_1_1_4_4B },
{ SPINOR_OP_READ_1_4_4, SPINOR_OP_READ_1_4_4_4B },
{ SPINOR_OP_READ_1_1_1_DTR, SPINOR_OP_READ_1_1_1_DTR_4B },
{ SPINOR_OP_READ_1_2_2_DTR, SPINOR_OP_READ_1_2_2_DTR_4B },
{ SPINOR_OP_READ_1_4_4_DTR, SPINOR_OP_READ_1_4_4_DTR_4B },
};
return spi_nor_convert_opcode(opcode, spi_nor_3to4_read,
ARRAY_SIZE(spi_nor_3to4_read));
}
static inline u8 spi_nor_convert_3to4_program(u8 opcode)
{
static const u8 spi_nor_3to4_program[][2] = {
{ SPINOR_OP_PP, SPINOR_OP_PP_4B },
{ SPINOR_OP_PP_1_1_4, SPINOR_OP_PP_1_1_4_4B },
{ SPINOR_OP_PP_1_4_4, SPINOR_OP_PP_1_4_4_4B },
};
return spi_nor_convert_opcode(opcode, spi_nor_3to4_program,
ARRAY_SIZE(spi_nor_3to4_program));
}
static inline u8 spi_nor_convert_3to4_erase(u8 opcode)
{
static const u8 spi_nor_3to4_erase[][2] = {
{ SPINOR_OP_BE_4K, SPINOR_OP_BE_4K_4B },
{ SPINOR_OP_BE_32K, SPINOR_OP_BE_32K_4B },
{ SPINOR_OP_SE, SPINOR_OP_SE_4B },
};
return spi_nor_convert_opcode(opcode, spi_nor_3to4_erase,
ARRAY_SIZE(spi_nor_3to4_erase));
}
static void spi_nor_set_4byte_opcodes(struct spi_nor *nor,
const struct flash_info *info)
{
switch (JEDEC_MFR(info)) {
case SNOR_MFR_SPANSION:
nor->erase_opcode = SPINOR_OP_SE;
nor->mtd.erasesize = info->sector_size;
break;
default:
break;
}
nor->read_opcode = spi_nor_convert_3to4_read(nor->read_opcode);
nor->program_opcode = spi_nor_convert_3to4_program(nor->program_opcode);
nor->erase_opcode = spi_nor_convert_3to4_erase(nor->erase_opcode);
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
static int s3an_sr_ready(struct spi_nor *nor)
{
int ret;
u8 val;
ret = nor->read_reg(nor, SPINOR_OP_XRDSR, &val, 1);
if (ret < 0) {
dev_err(nor->dev, "error %d reading XRDSR\n", (int) ret);
return ret;
}
return !!(val & XSR_RDY);
}
static inline int spi_nor_sr_ready(struct spi_nor *nor)
{
int sr = read_sr(nor);
if (sr < 0)
return sr;
if (nor->flags & SNOR_F_USE_CLSR && sr & (SR_E_ERR | SR_P_ERR)) {
if (sr & SR_E_ERR)
dev_err(nor->dev, "Erase Error occurred\n");
else
dev_err(nor->dev, "Programming Error occurred\n");
nor->write_reg(nor, SPINOR_OP_CLSR, NULL, 0);
return -EIO;
}
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
if (nor->flags & SNOR_F_READY_XSR_RDY)
sr = s3an_sr_ready(nor);
else
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
static loff_t spi_nor_s3an_addr_convert(struct spi_nor *nor, unsigned int addr)
{
unsigned int offset;
unsigned int page;
offset = addr % nor->page_size;
page = addr / nor->page_size;
page <<= (nor->page_size > 512) ? 10 : 9;
return page | offset;
}
static int spi_nor_erase_sector(struct spi_nor *nor, u32 addr)
{
u8 buf[SPI_NOR_MAX_ADDR_WIDTH];
int i;
if (nor->flags & SNOR_F_S3AN_ADDR_DEFAULT)
addr = spi_nor_s3an_addr_convert(nor, addr);
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
if (len == mtd->size && !(nor->flags & SNOR_F_NO_OP_CHIP_ERASE)) {
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
loff_t addr = from;
if (nor->flags & SNOR_F_S3AN_ADDR_DEFAULT)
addr = spi_nor_s3an_addr_convert(nor, addr);
ret = nor->read(nor, addr, len, buf);
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
loff_t addr = to + i;
if (hweight32(nor->page_size) == 1) {
page_offset = addr & (nor->page_size - 1);
} else {
uint64_t aux = addr;
page_offset = do_div(aux, nor->page_size);
}
page_remain = min_t(size_t,
nor->page_size - page_offset, len - i);
if (nor->flags & SNOR_F_S3AN_ADDR_DEFAULT)
addr = spi_nor_s3an_addr_convert(nor, addr);
write_enable(nor);
ret = nor->write(nor, addr, page_remain, buf + i);
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
if (val & SR_QUAD_EN_MX)
return 0;
write_enable(nor);
write_sr(nor, val | SR_QUAD_EN_MX);
ret = spi_nor_wait_till_ready(nor);
if (ret)
return ret;
ret = read_sr(nor);
if (!(ret > 0 && (ret & SR_QUAD_EN_MX))) {
dev_err(nor->dev, "Macronix Quad bit not set\n");
return -EINVAL;
}
return 0;
}
static int write_sr_cr(struct spi_nor *nor, u8 *sr_cr)
{
int ret;
write_enable(nor);
ret = nor->write_reg(nor, SPINOR_OP_WRSR, sr_cr, 2);
if (ret < 0) {
dev_err(nor->dev,
"error while writing configuration register\n");
return -EINVAL;
}
ret = spi_nor_wait_till_ready(nor);
if (ret) {
dev_err(nor->dev,
"timeout while writing configuration register\n");
return ret;
}
return 0;
}
static int spansion_quad_enable(struct spi_nor *nor)
{
u8 sr_cr[2] = {0, CR_QUAD_EN_SPAN};
int ret;
ret = write_sr_cr(nor, sr_cr);
if (ret)
return ret;
ret = read_cr(nor);
if (!(ret > 0 && (ret & CR_QUAD_EN_SPAN))) {
dev_err(nor->dev, "Spansion Quad bit not set\n");
return -EINVAL;
}
return 0;
}
static int spansion_no_read_cr_quad_enable(struct spi_nor *nor)
{
u8 sr_cr[2];
int ret;
ret = read_sr(nor);
if (ret < 0) {
dev_err(nor->dev, "error while reading status register\n");
return -EINVAL;
}
sr_cr[0] = ret;
sr_cr[1] = CR_QUAD_EN_SPAN;
return write_sr_cr(nor, sr_cr);
}
static int spansion_read_cr_quad_enable(struct spi_nor *nor)
{
struct device *dev = nor->dev;
u8 sr_cr[2];
int ret;
ret = read_cr(nor);
if (ret < 0) {
dev_err(dev, "error while reading configuration register\n");
return -EINVAL;
}
if (ret & CR_QUAD_EN_SPAN)
return 0;
sr_cr[1] = ret | CR_QUAD_EN_SPAN;
ret = read_sr(nor);
if (ret < 0) {
dev_err(dev, "error while reading status register\n");
return -EINVAL;
}
sr_cr[0] = ret;
ret = write_sr_cr(nor, sr_cr);
if (ret)
return ret;
ret = read_cr(nor);
if (!(ret > 0 && (ret & CR_QUAD_EN_SPAN))) {
dev_err(nor->dev, "Spansion Quad bit not set\n");
return -EINVAL;
}
return 0;
}
static int sr2_bit7_quad_enable(struct spi_nor *nor)
{
u8 sr2;
int ret;
ret = nor->read_reg(nor, SPINOR_OP_RDSR2, &sr2, 1);
if (ret)
return ret;
if (sr2 & SR2_QUAD_EN_BIT7)
return 0;
sr2 |= SR2_QUAD_EN_BIT7;
write_enable(nor);
ret = nor->write_reg(nor, SPINOR_OP_WRSR2, &sr2, 1);
if (ret < 0) {
dev_err(nor->dev, "error while writing status register 2\n");
return -EINVAL;
}
ret = spi_nor_wait_till_ready(nor);
if (ret < 0) {
dev_err(nor->dev, "timeout while writing status register 2\n");
return ret;
}
ret = nor->read_reg(nor, SPINOR_OP_RDSR2, &sr2, 1);
if (!(ret > 0 && (sr2 & SR2_QUAD_EN_BIT7))) {
dev_err(nor->dev, "SR2 Quad bit not set\n");
return -EINVAL;
}
return 0;
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
static int s3an_nor_scan(const struct flash_info *info, struct spi_nor *nor)
{
int ret;
u8 val;
ret = nor->read_reg(nor, SPINOR_OP_XRDSR, &val, 1);
if (ret < 0) {
dev_err(nor->dev, "error %d reading XRDSR\n", (int) ret);
return ret;
}
nor->erase_opcode = SPINOR_OP_XSE;
nor->program_opcode = SPINOR_OP_XPP;
nor->read_opcode = SPINOR_OP_READ;
nor->flags |= SNOR_F_NO_OP_CHIP_ERASE;
if (val & XSR_PAGESIZE) {
nor->page_size = (nor->page_size == 264) ? 256 : 512;
nor->mtd.writebufsize = nor->page_size;
nor->mtd.size = 8 * nor->page_size * info->n_sectors;
nor->mtd.erasesize = 8 * nor->page_size;
} else {
nor->flags |= SNOR_F_S3AN_ADDR_DEFAULT;
}
return 0;
}
static void
spi_nor_set_read_settings(struct spi_nor_read_command *read,
u8 num_mode_clocks,
u8 num_wait_states,
u8 opcode,
enum spi_nor_protocol proto)
{
read->num_mode_clocks = num_mode_clocks;
read->num_wait_states = num_wait_states;
read->opcode = opcode;
read->proto = proto;
}
static void
spi_nor_set_pp_settings(struct spi_nor_pp_command *pp,
u8 opcode,
enum spi_nor_protocol proto)
{
pp->opcode = opcode;
pp->proto = proto;
}
static int spi_nor_read_sfdp(struct spi_nor *nor, u32 addr,
size_t len, void *buf)
{
u8 addr_width, read_opcode, read_dummy;
int ret;
read_opcode = nor->read_opcode;
addr_width = nor->addr_width;
read_dummy = nor->read_dummy;
nor->read_opcode = SPINOR_OP_RDSFDP;
nor->addr_width = 3;
nor->read_dummy = 8;
while (len) {
ret = nor->read(nor, addr, len, (u8 *)buf);
if (!ret || ret > len) {
ret = -EIO;
goto read_err;
}
if (ret < 0)
goto read_err;
buf += ret;
addr += ret;
len -= ret;
}
ret = 0;
read_err:
nor->read_opcode = read_opcode;
nor->addr_width = addr_width;
nor->read_dummy = read_dummy;
return ret;
}
static int spi_nor_read_sfdp_dma_unsafe(struct spi_nor *nor, u32 addr,
size_t len, void *buf)
{
void *dma_safe_buf;
int ret;
dma_safe_buf = kmalloc(len, GFP_KERNEL);
if (!dma_safe_buf)
return -ENOMEM;
ret = spi_nor_read_sfdp(nor, addr, len, dma_safe_buf);
memcpy(buf, dma_safe_buf, len);
kfree(dma_safe_buf);
return ret;
}
static inline void
spi_nor_set_read_settings_from_bfpt(struct spi_nor_read_command *read,
u16 half,
enum spi_nor_protocol proto)
{
read->num_mode_clocks = (half >> 5) & 0x07;
read->num_wait_states = (half >> 0) & 0x1f;
read->opcode = (half >> 8) & 0xff;
read->proto = proto;
}
static int spi_nor_parse_bfpt(struct spi_nor *nor,
const struct sfdp_parameter_header *bfpt_header,
struct spi_nor_flash_parameter *params)
{
struct mtd_info *mtd = &nor->mtd;
struct sfdp_bfpt bfpt;
size_t len;
int i, cmd, err;
u32 addr;
u16 half;
if (bfpt_header->length < BFPT_DWORD_MAX_JESD216)
return -EINVAL;
len = min_t(size_t, sizeof(bfpt),
bfpt_header->length * sizeof(u32));
addr = SFDP_PARAM_HEADER_PTP(bfpt_header);
memset(&bfpt, 0, sizeof(bfpt));
err = spi_nor_read_sfdp_dma_unsafe(nor, addr, len, &bfpt);
if (err < 0)
return err;
for (i = 0; i < BFPT_DWORD_MAX; i++)
bfpt.dwords[i] = le32_to_cpu(bfpt.dwords[i]);
switch (bfpt.dwords[BFPT_DWORD(1)] & BFPT_DWORD1_ADDRESS_BYTES_MASK) {
case BFPT_DWORD1_ADDRESS_BYTES_3_ONLY:
nor->addr_width = 3;
break;
case BFPT_DWORD1_ADDRESS_BYTES_4_ONLY:
nor->addr_width = 4;
break;
default:
break;
}
params->size = bfpt.dwords[BFPT_DWORD(2)];
if (params->size & BIT(31)) {
params->size &= ~BIT(31);
if (params->size > 63)
return -EINVAL;
params->size = 1ULL << params->size;
} else {
params->size++;
}
params->size >>= 3;
for (i = 0; i < ARRAY_SIZE(sfdp_bfpt_reads); i++) {
const struct sfdp_bfpt_read *rd = &sfdp_bfpt_reads[i];
struct spi_nor_read_command *read;
if (!(bfpt.dwords[rd->supported_dword] & rd->supported_bit)) {
params->hwcaps.mask &= ~rd->hwcaps;
continue;
}
params->hwcaps.mask |= rd->hwcaps;
cmd = spi_nor_hwcaps_read2cmd(rd->hwcaps);
read = &params->reads[cmd];
half = bfpt.dwords[rd->settings_dword] >> rd->settings_shift;
spi_nor_set_read_settings_from_bfpt(read, half, rd->proto);
}
for (i = 0; i < ARRAY_SIZE(sfdp_bfpt_erases); i++) {
const struct sfdp_bfpt_erase *er = &sfdp_bfpt_erases[i];
u32 erasesize;
u8 opcode;
half = bfpt.dwords[er->dword] >> er->shift;
erasesize = half & 0xff;
if (!erasesize)
continue;
erasesize = 1U << erasesize;
opcode = (half >> 8) & 0xff;
#ifdef CONFIG_MTD_SPI_NOR_USE_4K_SECTORS
if (erasesize == SZ_4K) {
nor->erase_opcode = opcode;
mtd->erasesize = erasesize;
break;
}
#endif
if (!mtd->erasesize || mtd->erasesize < erasesize) {
nor->erase_opcode = opcode;
mtd->erasesize = erasesize;
}
}
if (bfpt_header->length < BFPT_DWORD_MAX)
return 0;
params->page_size = bfpt.dwords[BFPT_DWORD(11)];
params->page_size &= BFPT_DWORD11_PAGE_SIZE_MASK;
params->page_size >>= BFPT_DWORD11_PAGE_SIZE_SHIFT;
params->page_size = 1U << params->page_size;
switch (bfpt.dwords[BFPT_DWORD(15)] & BFPT_DWORD15_QER_MASK) {
case BFPT_DWORD15_QER_NONE:
params->quad_enable = NULL;
break;
case BFPT_DWORD15_QER_SR2_BIT1_BUGGY:
case BFPT_DWORD15_QER_SR2_BIT1_NO_RD:
params->quad_enable = spansion_no_read_cr_quad_enable;
break;
case BFPT_DWORD15_QER_SR1_BIT6:
params->quad_enable = macronix_quad_enable;
break;
case BFPT_DWORD15_QER_SR2_BIT7:
params->quad_enable = sr2_bit7_quad_enable;
break;
case BFPT_DWORD15_QER_SR2_BIT1:
params->quad_enable = spansion_read_cr_quad_enable;
break;
default:
return -EINVAL;
}
return 0;
}
static int spi_nor_parse_sfdp(struct spi_nor *nor,
struct spi_nor_flash_parameter *params)
{
const struct sfdp_parameter_header *param_header, *bfpt_header;
struct sfdp_parameter_header *param_headers = NULL;
struct sfdp_header header;
struct device *dev = nor->dev;
size_t psize;
int i, err;
err = spi_nor_read_sfdp_dma_unsafe(nor, 0, sizeof(header), &header);
if (err < 0)
return err;
if (le32_to_cpu(header.signature) != SFDP_SIGNATURE ||
header.major != SFDP_JESD216_MAJOR ||
header.minor < SFDP_JESD216_MINOR)
return -EINVAL;
bfpt_header = &header.bfpt_header;
if (SFDP_PARAM_HEADER_ID(bfpt_header) != SFDP_BFPT_ID ||
bfpt_header->major != SFDP_JESD216_MAJOR)
return -EINVAL;
if (header.nph) {
psize = header.nph * sizeof(*param_headers);
param_headers = kmalloc(psize, GFP_KERNEL);
if (!param_headers)
return -ENOMEM;
err = spi_nor_read_sfdp(nor, sizeof(header),
psize, param_headers);
if (err < 0) {
dev_err(dev, "failed to read SFDP parameter headers\n");
goto exit;
}
}
for (i = 0; i < header.nph; i++) {
param_header = &param_headers[i];
if (SFDP_PARAM_HEADER_ID(param_header) == SFDP_BFPT_ID &&
param_header->major == SFDP_JESD216_MAJOR &&
(param_header->minor > bfpt_header->minor ||
(param_header->minor == bfpt_header->minor &&
param_header->length > bfpt_header->length)))
bfpt_header = param_header;
}
err = spi_nor_parse_bfpt(nor, bfpt_header, params);
if (err)
goto exit;
for (i = 0; i < header.nph; i++) {
param_header = &param_headers[i];
switch (SFDP_PARAM_HEADER_ID(param_header)) {
case SFDP_SECTOR_MAP_ID:
dev_info(dev, "non-uniform erase sector maps are not supported yet.\n");
break;
default:
break;
}
if (err)
goto exit;
}
exit:
kfree(param_headers);
return err;
}
static int spi_nor_init_params(struct spi_nor *nor,
const struct flash_info *info,
struct spi_nor_flash_parameter *params)
{
memset(params, 0, sizeof(*params));
params->size = info->sector_size * info->n_sectors;
params->page_size = info->page_size;
params->hwcaps.mask |= SNOR_HWCAPS_READ;
spi_nor_set_read_settings(&params->reads[SNOR_CMD_READ],
0, 0, SPINOR_OP_READ,
SNOR_PROTO_1_1_1);
if (!(info->flags & SPI_NOR_NO_FR)) {
params->hwcaps.mask |= SNOR_HWCAPS_READ_FAST;
spi_nor_set_read_settings(&params->reads[SNOR_CMD_READ_FAST],
0, 8, SPINOR_OP_READ_FAST,
SNOR_PROTO_1_1_1);
}
if (info->flags & SPI_NOR_DUAL_READ) {
params->hwcaps.mask |= SNOR_HWCAPS_READ_1_1_2;
spi_nor_set_read_settings(&params->reads[SNOR_CMD_READ_1_1_2],
0, 8, SPINOR_OP_READ_1_1_2,
SNOR_PROTO_1_1_2);
}
if (info->flags & SPI_NOR_QUAD_READ) {
params->hwcaps.mask |= SNOR_HWCAPS_READ_1_1_4;
spi_nor_set_read_settings(&params->reads[SNOR_CMD_READ_1_1_4],
0, 8, SPINOR_OP_READ_1_1_4,
SNOR_PROTO_1_1_4);
}
params->hwcaps.mask |= SNOR_HWCAPS_PP;
spi_nor_set_pp_settings(&params->page_programs[SNOR_CMD_PP],
SPINOR_OP_PP, SNOR_PROTO_1_1_1);
if (params->hwcaps.mask & (SNOR_HWCAPS_READ_QUAD |
SNOR_HWCAPS_PP_QUAD)) {
switch (JEDEC_MFR(info)) {
case SNOR_MFR_MACRONIX:
params->quad_enable = macronix_quad_enable;
break;
case SNOR_MFR_MICRON:
break;
default:
params->quad_enable = spansion_quad_enable;
break;
}
}
nor->addr_width = 0;
nor->mtd.erasesize = 0;
if ((info->flags & (SPI_NOR_DUAL_READ | SPI_NOR_QUAD_READ)) &&
!(info->flags & SPI_NOR_SKIP_SFDP)) {
struct spi_nor_flash_parameter sfdp_params;
memcpy(&sfdp_params, params, sizeof(sfdp_params));
if (spi_nor_parse_sfdp(nor, &sfdp_params)) {
nor->addr_width = 0;
nor->mtd.erasesize = 0;
} else {
memcpy(params, &sfdp_params, sizeof(*params));
}
}
return 0;
}
static int spi_nor_hwcaps2cmd(u32 hwcaps, const int table[][2], size_t size)
{
size_t i;
for (i = 0; i < size; i++)
if (table[i][0] == (int)hwcaps)
return table[i][1];
return -EINVAL;
}
static int spi_nor_hwcaps_read2cmd(u32 hwcaps)
{
static const int hwcaps_read2cmd[][2] = {
{ SNOR_HWCAPS_READ, SNOR_CMD_READ },
{ SNOR_HWCAPS_READ_FAST, SNOR_CMD_READ_FAST },
{ SNOR_HWCAPS_READ_1_1_1_DTR, SNOR_CMD_READ_1_1_1_DTR },
{ SNOR_HWCAPS_READ_1_1_2, SNOR_CMD_READ_1_1_2 },
{ SNOR_HWCAPS_READ_1_2_2, SNOR_CMD_READ_1_2_2 },
{ SNOR_HWCAPS_READ_2_2_2, SNOR_CMD_READ_2_2_2 },
{ SNOR_HWCAPS_READ_1_2_2_DTR, SNOR_CMD_READ_1_2_2_DTR },
{ SNOR_HWCAPS_READ_1_1_4, SNOR_CMD_READ_1_1_4 },
{ SNOR_HWCAPS_READ_1_4_4, SNOR_CMD_READ_1_4_4 },
{ SNOR_HWCAPS_READ_4_4_4, SNOR_CMD_READ_4_4_4 },
{ SNOR_HWCAPS_READ_1_4_4_DTR, SNOR_CMD_READ_1_4_4_DTR },
{ SNOR_HWCAPS_READ_1_1_8, SNOR_CMD_READ_1_1_8 },
{ SNOR_HWCAPS_READ_1_8_8, SNOR_CMD_READ_1_8_8 },
{ SNOR_HWCAPS_READ_8_8_8, SNOR_CMD_READ_8_8_8 },
{ SNOR_HWCAPS_READ_1_8_8_DTR, SNOR_CMD_READ_1_8_8_DTR },
};
return spi_nor_hwcaps2cmd(hwcaps, hwcaps_read2cmd,
ARRAY_SIZE(hwcaps_read2cmd));
}
static int spi_nor_hwcaps_pp2cmd(u32 hwcaps)
{
static const int hwcaps_pp2cmd[][2] = {
{ SNOR_HWCAPS_PP, SNOR_CMD_PP },
{ SNOR_HWCAPS_PP_1_1_4, SNOR_CMD_PP_1_1_4 },
{ SNOR_HWCAPS_PP_1_4_4, SNOR_CMD_PP_1_4_4 },
{ SNOR_HWCAPS_PP_4_4_4, SNOR_CMD_PP_4_4_4 },
{ SNOR_HWCAPS_PP_1_1_8, SNOR_CMD_PP_1_1_8 },
{ SNOR_HWCAPS_PP_1_8_8, SNOR_CMD_PP_1_8_8 },
{ SNOR_HWCAPS_PP_8_8_8, SNOR_CMD_PP_8_8_8 },
};
return spi_nor_hwcaps2cmd(hwcaps, hwcaps_pp2cmd,
ARRAY_SIZE(hwcaps_pp2cmd));
}
static int spi_nor_select_read(struct spi_nor *nor,
const struct spi_nor_flash_parameter *params,
u32 shared_hwcaps)
{
int cmd, best_match = fls(shared_hwcaps & SNOR_HWCAPS_READ_MASK) - 1;
const struct spi_nor_read_command *read;
if (best_match < 0)
return -EINVAL;
cmd = spi_nor_hwcaps_read2cmd(BIT(best_match));
if (cmd < 0)
return -EINVAL;
read = &params->reads[cmd];
nor->read_opcode = read->opcode;
nor->read_proto = read->proto;
nor->read_dummy = read->num_mode_clocks + read->num_wait_states;
return 0;
}
static int spi_nor_select_pp(struct spi_nor *nor,
const struct spi_nor_flash_parameter *params,
u32 shared_hwcaps)
{
int cmd, best_match = fls(shared_hwcaps & SNOR_HWCAPS_PP_MASK) - 1;
const struct spi_nor_pp_command *pp;
if (best_match < 0)
return -EINVAL;
cmd = spi_nor_hwcaps_pp2cmd(BIT(best_match));
if (cmd < 0)
return -EINVAL;
pp = &params->page_programs[cmd];
nor->program_opcode = pp->opcode;
nor->write_proto = pp->proto;
return 0;
}
static int spi_nor_select_erase(struct spi_nor *nor,
const struct flash_info *info)
{
struct mtd_info *mtd = &nor->mtd;
if (mtd->erasesize)
return 0;
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
return 0;
}
static int spi_nor_setup(struct spi_nor *nor, const struct flash_info *info,
const struct spi_nor_flash_parameter *params,
const struct spi_nor_hwcaps *hwcaps)
{
u32 ignored_mask, shared_mask;
bool enable_quad_io;
int err;
shared_mask = hwcaps->mask & params->hwcaps.mask;
ignored_mask = (SNOR_HWCAPS_READ_2_2_2 |
SNOR_HWCAPS_READ_4_4_4 |
SNOR_HWCAPS_READ_8_8_8 |
SNOR_HWCAPS_PP_4_4_4 |
SNOR_HWCAPS_PP_8_8_8);
if (shared_mask & ignored_mask) {
dev_dbg(nor->dev,
"SPI n-n-n protocols are not supported yet.\n");
shared_mask &= ~ignored_mask;
}
err = spi_nor_select_read(nor, params, shared_mask);
if (err) {
dev_err(nor->dev,
"can't select read settings supported by both the SPI controller and memory.\n");
return err;
}
err = spi_nor_select_pp(nor, params, shared_mask);
if (err) {
dev_err(nor->dev,
"can't select write settings supported by both the SPI controller and memory.\n");
return err;
}
err = spi_nor_select_erase(nor, info);
if (err) {
dev_err(nor->dev,
"can't select erase settings supported by both the SPI controller and memory.\n");
return err;
}
enable_quad_io = (spi_nor_get_protocol_width(nor->read_proto) == 4 ||
spi_nor_get_protocol_width(nor->write_proto) == 4);
if (enable_quad_io && params->quad_enable) {
err = params->quad_enable(nor);
if (err) {
dev_err(nor->dev, "quad mode not supported\n");
return err;
}
}
return 0;
}
int spi_nor_scan(struct spi_nor *nor, const char *name,
const struct spi_nor_hwcaps *hwcaps)
{
struct spi_nor_flash_parameter params;
const struct flash_info *info = NULL;
struct device *dev = nor->dev;
struct mtd_info *mtd = &nor->mtd;
struct device_node *np = spi_nor_get_flash_node(nor);
int ret;
int i;
ret = spi_nor_check(nor);
if (ret)
return ret;
nor->reg_proto = SNOR_PROTO_1_1_1;
nor->read_proto = SNOR_PROTO_1_1_1;
nor->write_proto = SNOR_PROTO_1_1_1;
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
if (info->flags & SPI_S3AN)
nor->flags |= SNOR_F_READY_XSR_RDY;
ret = spi_nor_init_params(nor, info, &params);
if (ret)
return ret;
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
mtd->size = params.size;
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
if (info->flags & NO_CHIP_ERASE)
nor->flags |= SNOR_F_NO_OP_CHIP_ERASE;
if (info->flags & USE_CLSR)
nor->flags |= SNOR_F_USE_CLSR;
if (info->flags & SPI_NOR_NO_ERASE)
mtd->flags |= MTD_NO_ERASE;
mtd->dev.parent = dev;
nor->page_size = params.page_size;
mtd->writebufsize = nor->page_size;
if (np) {
if (of_property_read_bool(np, "m25p,fast-read"))
params.hwcaps.mask |= SNOR_HWCAPS_READ_FAST;
else
params.hwcaps.mask &= ~SNOR_HWCAPS_READ_FAST;
} else {
params.hwcaps.mask |= SNOR_HWCAPS_READ_FAST;
}
if (info->flags & SPI_NOR_NO_FR)
params.hwcaps.mask &= ~SNOR_HWCAPS_READ_FAST;
ret = spi_nor_setup(nor, info, &params, hwcaps);
if (ret)
return ret;
if (nor->addr_width) {
} else if (info->addr_width) {
nor->addr_width = info->addr_width;
} else if (mtd->size > 0x1000000) {
nor->addr_width = 4;
if (JEDEC_MFR(info) == SNOR_MFR_SPANSION ||
info->flags & SPI_NOR_4B_OPCODES)
spi_nor_set_4byte_opcodes(nor, info);
else
set_4byte(nor, info, 1);
} else {
nor->addr_width = 3;
}
if (nor->addr_width > SPI_NOR_MAX_ADDR_WIDTH) {
dev_err(dev, "address width is too large: %u\n",
nor->addr_width);
return -EINVAL;
}
if (info->flags & SPI_S3AN) {
ret = s3an_nor_scan(info, nor);
if (ret)
return ret;
}
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
