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
return 1;
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
static inline int set_4byte(struct spi_nor *nor, u32 jedec_id, int enable)
{
int status;
bool need_wren = false;
u8 cmd;
switch (JEDEC_MFR(jedec_id)) {
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
static int spi_nor_wait_till_ready(struct spi_nor *nor)
{
unsigned long deadline;
int sr;
deadline = jiffies + MAX_READY_WAIT_JIFFIES;
do {
cond_resched();
sr = read_sr(nor);
if (sr < 0)
break;
else if (!(sr & SR_WIP))
return 0;
} while (!time_after_eq(jiffies, deadline));
return -ETIMEDOUT;
}
static int spi_nor_wait_till_fsr_ready(struct spi_nor *nor)
{
unsigned long deadline;
int sr;
int fsr;
deadline = jiffies + MAX_READY_WAIT_JIFFIES;
do {
cond_resched();
sr = read_sr(nor);
if (sr < 0) {
break;
} else if (!(sr & SR_WIP)) {
fsr = read_fsr(nor);
if (fsr < 0)
break;
if (fsr & FSR_READY)
return 0;
}
} while (!time_after_eq(jiffies, deadline));
return -ETIMEDOUT;
}
static int wait_till_ready(struct spi_nor *nor)
{
return nor->wait_till_ready(nor);
}
static int erase_chip(struct spi_nor *nor)
{
int ret;
dev_dbg(nor->dev, " %lldKiB\n", (long long)(nor->mtd->size >> 10));
ret = wait_till_ready(nor);
if (ret)
return ret;
write_enable(nor);
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
if (erase_chip(nor)) {
ret = -EIO;
goto erase_err;
}
} else {
while (len) {
if (nor->erase(nor, addr)) {
ret = -EIO;
goto erase_err;
}
addr += mtd->erasesize;
len -= mtd->erasesize;
}
}
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_ERASE);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return ret;
erase_err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_ERASE);
instr->state = MTD_ERASE_FAILED;
return ret;
}
static int spi_nor_lock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
uint32_t offset = ofs;
uint8_t status_old, status_new;
int ret = 0;
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_LOCK);
if (ret)
return ret;
ret = wait_till_ready(nor);
if (ret)
goto err;
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
if (ret)
goto err;
}
err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_LOCK);
return ret;
}
static int spi_nor_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct spi_nor *nor = mtd_to_spi_nor(mtd);
uint32_t offset = ofs;
uint8_t status_old, status_new;
int ret = 0;
ret = spi_nor_lock_and_prep(nor, SPI_NOR_OPS_UNLOCK);
if (ret)
return ret;
ret = wait_till_ready(nor);
if (ret)
goto err;
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
if (ret)
goto err;
}
err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_UNLOCK);
return ret;
}
static const struct spi_device_id *spi_nor_read_id(struct spi_nor *nor)
{
int tmp;
u8 id[5];
u32 jedec;
u16 ext_jedec;
struct flash_info *info;
tmp = nor->read_reg(nor, SPINOR_OP_RDID, id, 5);
if (tmp < 0) {
dev_dbg(nor->dev, " error %d reading JEDEC ID\n", tmp);
return ERR_PTR(tmp);
}
jedec = id[0];
jedec = jedec << 8;
jedec |= id[1];
jedec = jedec << 8;
jedec |= id[2];
ext_jedec = id[3] << 8 | id[4];
for (tmp = 0; tmp < ARRAY_SIZE(spi_nor_ids) - 1; tmp++) {
info = (void *)spi_nor_ids[tmp].driver_data;
if (info->jedec_id == jedec) {
if (info->ext_id == 0 || info->ext_id == ext_jedec)
return &spi_nor_ids[tmp];
}
}
dev_err(nor->dev, "unrecognized JEDEC id %06x\n", jedec);
return ERR_PTR(-ENODEV);
}
static const struct spi_device_id *jedec_probe(struct spi_nor *nor)
{
return nor->read_id(nor);
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
ret = wait_till_ready(nor);
if (ret)
goto time_out;
write_enable(nor);
nor->sst_write_second = false;
actual = to % 2;
if (actual) {
nor->program_opcode = SPINOR_OP_BP;
nor->write(nor, to, 1, retlen, buf);
ret = wait_till_ready(nor);
if (ret)
goto time_out;
}
to += actual;
for (; actual < len - 1; actual += 2) {
nor->program_opcode = SPINOR_OP_AAI_WP;
nor->write(nor, to, 2, retlen, buf + actual);
ret = wait_till_ready(nor);
if (ret)
goto time_out;
to += 2;
nor->sst_write_second = true;
}
nor->sst_write_second = false;
write_disable(nor);
ret = wait_till_ready(nor);
if (ret)
goto time_out;
if (actual != len) {
write_enable(nor);
nor->program_opcode = SPINOR_OP_BP;
nor->write(nor, to, 1, retlen, buf + actual);
ret = wait_till_ready(nor);
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
ret = wait_till_ready(nor);
if (ret)
goto write_err;
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
wait_till_ready(nor);
write_enable(nor);
nor->write(nor, to + i, page_size, retlen, buf + i);
}
}
write_err:
spi_nor_unlock_and_unprep(nor, SPI_NOR_OPS_WRITE);
return 0;
}
static int macronix_quad_enable(struct spi_nor *nor)
{
int ret, val;
val = read_sr(nor);
write_enable(nor);
nor->cmd_buf[0] = val | SR_QUAD_EN_MX;
nor->write_reg(nor, SPINOR_OP_WRSR, nor->cmd_buf, 1, 0);
if (wait_till_ready(nor))
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
static int set_quad_mode(struct spi_nor *nor, u32 jedec_id)
{
int status;
switch (JEDEC_MFR(jedec_id)) {
case CFI_MFR_MACRONIX:
status = macronix_quad_enable(nor);
if (status) {
dev_err(nor->dev, "Macronix quad-read not enabled\n");
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
if (!nor->read_id)
nor->read_id = spi_nor_read_id;
if (!nor->wait_till_ready)
nor->wait_till_ready = spi_nor_wait_till_ready;
return 0;
}
int spi_nor_scan(struct spi_nor *nor, const struct spi_device_id *id,
enum read_mode mode)
{
struct flash_info *info;
struct flash_platform_data *data;
struct device *dev = nor->dev;
struct mtd_info *mtd = nor->mtd;
struct device_node *np = dev->of_node;
int ret;
int i;
ret = spi_nor_check(nor);
if (ret)
return ret;
data = dev_get_platdata(dev);
if (data && data->type) {
const struct spi_device_id *plat_id;
for (i = 0; i < ARRAY_SIZE(spi_nor_ids) - 1; i++) {
plat_id = &spi_nor_ids[i];
if (strcmp(data->type, plat_id->name))
continue;
break;
}
if (i < ARRAY_SIZE(spi_nor_ids) - 1)
id = plat_id;
else
dev_warn(dev, "unrecognized id %s\n", data->type);
}
info = (void *)id->driver_data;
if (info->jedec_id) {
const struct spi_device_id *jid;
jid = jedec_probe(nor);
if (IS_ERR(jid)) {
return PTR_ERR(jid);
} else if (jid != id) {
dev_warn(dev, "found %s, expected %s\n",
jid->name, id->name);
id = jid;
info = (void *)jid->driver_data;
}
}
mutex_init(&nor->lock);
if (JEDEC_MFR(info->jedec_id) == CFI_MFR_ATMEL ||
JEDEC_MFR(info->jedec_id) == CFI_MFR_INTEL ||
JEDEC_MFR(info->jedec_id) == CFI_MFR_SST) {
write_enable(nor);
write_sr(nor, 0);
}
if (data && data->name)
mtd->name = data->name;
else
mtd->name = dev_name(dev);
mtd->type = MTD_NORFLASH;
mtd->writesize = 1;
mtd->flags = MTD_CAP_NORFLASH;
mtd->size = info->sector_size * info->n_sectors;
mtd->_erase = spi_nor_erase;
mtd->_read = spi_nor_read;
if (JEDEC_MFR(info->jedec_id) == CFI_MFR_ST) {
mtd->_lock = spi_nor_lock;
mtd->_unlock = spi_nor_unlock;
}
if (info->flags & SST_WRITE)
mtd->_write = sst_write;
else
mtd->_write = spi_nor_write;
if ((info->flags & USE_FSR) &&
nor->wait_till_ready == spi_nor_wait_till_ready)
nor->wait_till_ready = spi_nor_wait_till_fsr_ready;
if (info->flags & SECT_4K) {
nor->erase_opcode = SPINOR_OP_BE_4K;
mtd->erasesize = 4096;
} else if (info->flags & SECT_4K_PMC) {
nor->erase_opcode = SPINOR_OP_BE_4K_PMC;
mtd->erasesize = 4096;
} else {
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
ret = set_quad_mode(nor, info->jedec_id);
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
if (JEDEC_MFR(info->jedec_id) == CFI_MFR_AMD) {
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
set_4byte(nor, info->jedec_id, 1);
} else {
nor->addr_width = 3;
}
nor->read_dummy = spi_nor_read_dummy_cycles(nor);
dev_info(dev, "%s (%lld Kbytes)\n", id->name,
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
const struct spi_device_id *spi_nor_match_id(char *name)
{
const struct spi_device_id *id = spi_nor_ids;
while (id->name[0]) {
if (!strcmp(name, id->name))
return id;
id++;
}
return NULL;
}
