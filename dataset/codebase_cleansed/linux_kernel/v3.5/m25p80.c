static inline struct m25p *mtd_to_m25p(struct mtd_info *mtd)
{
return container_of(mtd, struct m25p, mtd);
}
static int read_sr(struct m25p *flash)
{
ssize_t retval;
u8 code = OPCODE_RDSR;
u8 val;
retval = spi_write_then_read(flash->spi, &code, 1, &val, 1);
if (retval < 0) {
dev_err(&flash->spi->dev, "error %d reading SR\n",
(int) retval);
return retval;
}
return val;
}
static int write_sr(struct m25p *flash, u8 val)
{
flash->command[0] = OPCODE_WRSR;
flash->command[1] = val;
return spi_write(flash->spi, flash->command, 2);
}
static inline int write_enable(struct m25p *flash)
{
u8 code = OPCODE_WREN;
return spi_write_then_read(flash->spi, &code, 1, NULL, 0);
}
static inline int write_disable(struct m25p *flash)
{
u8 code = OPCODE_WRDI;
return spi_write_then_read(flash->spi, &code, 1, NULL, 0);
}
static inline int set_4byte(struct m25p *flash, u32 jedec_id, int enable)
{
switch (JEDEC_MFR(jedec_id)) {
case CFI_MFR_MACRONIX:
flash->command[0] = enable ? OPCODE_EN4B : OPCODE_EX4B;
return spi_write(flash->spi, flash->command, 1);
default:
flash->command[0] = OPCODE_BRWR;
flash->command[1] = enable << 7;
return spi_write(flash->spi, flash->command, 2);
}
}
static int wait_till_ready(struct m25p *flash)
{
unsigned long deadline;
int sr;
deadline = jiffies + MAX_READY_WAIT_JIFFIES;
do {
if ((sr = read_sr(flash)) < 0)
break;
else if (!(sr & SR_WIP))
return 0;
cond_resched();
} while (!time_after_eq(jiffies, deadline));
return 1;
}
static int erase_chip(struct m25p *flash)
{
pr_debug("%s: %s %lldKiB\n", dev_name(&flash->spi->dev), __func__,
(long long)(flash->mtd.size >> 10));
if (wait_till_ready(flash))
return 1;
write_enable(flash);
flash->command[0] = OPCODE_CHIP_ERASE;
spi_write(flash->spi, flash->command, 1);
return 0;
}
static void m25p_addr2cmd(struct m25p *flash, unsigned int addr, u8 *cmd)
{
cmd[1] = addr >> (flash->addr_width * 8 - 8);
cmd[2] = addr >> (flash->addr_width * 8 - 16);
cmd[3] = addr >> (flash->addr_width * 8 - 24);
cmd[4] = addr >> (flash->addr_width * 8 - 32);
}
static int m25p_cmdsz(struct m25p *flash)
{
return 1 + flash->addr_width;
}
static int erase_sector(struct m25p *flash, u32 offset)
{
pr_debug("%s: %s %dKiB at 0x%08x\n", dev_name(&flash->spi->dev),
__func__, flash->mtd.erasesize / 1024, offset);
if (wait_till_ready(flash))
return 1;
write_enable(flash);
flash->command[0] = flash->erase_opcode;
m25p_addr2cmd(flash, offset, flash->command);
spi_write(flash->spi, flash->command, m25p_cmdsz(flash));
return 0;
}
static int m25p80_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct m25p *flash = mtd_to_m25p(mtd);
u32 addr,len;
uint32_t rem;
pr_debug("%s: %s at 0x%llx, len %lld\n", dev_name(&flash->spi->dev),
__func__, (long long)instr->addr,
(long long)instr->len);
div_u64_rem(instr->len, mtd->erasesize, &rem);
if (rem)
return -EINVAL;
addr = instr->addr;
len = instr->len;
mutex_lock(&flash->lock);
if (len == flash->mtd.size) {
if (erase_chip(flash)) {
instr->state = MTD_ERASE_FAILED;
mutex_unlock(&flash->lock);
return -EIO;
}
} else {
while (len) {
if (erase_sector(flash, addr)) {
instr->state = MTD_ERASE_FAILED;
mutex_unlock(&flash->lock);
return -EIO;
}
addr += mtd->erasesize;
len -= mtd->erasesize;
}
}
mutex_unlock(&flash->lock);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return 0;
}
static int m25p80_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct m25p *flash = mtd_to_m25p(mtd);
struct spi_transfer t[2];
struct spi_message m;
pr_debug("%s: %s from 0x%08x, len %zd\n", dev_name(&flash->spi->dev),
__func__, (u32)from, len);
spi_message_init(&m);
memset(t, 0, (sizeof t));
t[0].tx_buf = flash->command;
t[0].len = m25p_cmdsz(flash) + FAST_READ_DUMMY_BYTE;
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = len;
spi_message_add_tail(&t[1], &m);
mutex_lock(&flash->lock);
if (wait_till_ready(flash)) {
mutex_unlock(&flash->lock);
return 1;
}
flash->command[0] = OPCODE_READ;
m25p_addr2cmd(flash, from, flash->command);
spi_sync(flash->spi, &m);
*retlen = m.actual_length - m25p_cmdsz(flash) - FAST_READ_DUMMY_BYTE;
mutex_unlock(&flash->lock);
return 0;
}
static int m25p80_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct m25p *flash = mtd_to_m25p(mtd);
u32 page_offset, page_size;
struct spi_transfer t[2];
struct spi_message m;
pr_debug("%s: %s to 0x%08x, len %zd\n", dev_name(&flash->spi->dev),
__func__, (u32)to, len);
spi_message_init(&m);
memset(t, 0, (sizeof t));
t[0].tx_buf = flash->command;
t[0].len = m25p_cmdsz(flash);
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = buf;
spi_message_add_tail(&t[1], &m);
mutex_lock(&flash->lock);
if (wait_till_ready(flash)) {
mutex_unlock(&flash->lock);
return 1;
}
write_enable(flash);
flash->command[0] = OPCODE_PP;
m25p_addr2cmd(flash, to, flash->command);
page_offset = to & (flash->page_size - 1);
if (page_offset + len <= flash->page_size) {
t[1].len = len;
spi_sync(flash->spi, &m);
*retlen = m.actual_length - m25p_cmdsz(flash);
} else {
u32 i;
page_size = flash->page_size - page_offset;
t[1].len = page_size;
spi_sync(flash->spi, &m);
*retlen = m.actual_length - m25p_cmdsz(flash);
for (i = page_size; i < len; i += page_size) {
page_size = len - i;
if (page_size > flash->page_size)
page_size = flash->page_size;
m25p_addr2cmd(flash, to + i, flash->command);
t[1].tx_buf = buf + i;
t[1].len = page_size;
wait_till_ready(flash);
write_enable(flash);
spi_sync(flash->spi, &m);
*retlen += m.actual_length - m25p_cmdsz(flash);
}
}
mutex_unlock(&flash->lock);
return 0;
}
static int sst_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct m25p *flash = mtd_to_m25p(mtd);
struct spi_transfer t[2];
struct spi_message m;
size_t actual;
int cmd_sz, ret;
pr_debug("%s: %s to 0x%08x, len %zd\n", dev_name(&flash->spi->dev),
__func__, (u32)to, len);
spi_message_init(&m);
memset(t, 0, (sizeof t));
t[0].tx_buf = flash->command;
t[0].len = m25p_cmdsz(flash);
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = buf;
spi_message_add_tail(&t[1], &m);
mutex_lock(&flash->lock);
ret = wait_till_ready(flash);
if (ret)
goto time_out;
write_enable(flash);
actual = to % 2;
if (actual) {
flash->command[0] = OPCODE_BP;
m25p_addr2cmd(flash, to, flash->command);
t[1].len = 1;
spi_sync(flash->spi, &m);
ret = wait_till_ready(flash);
if (ret)
goto time_out;
*retlen += m.actual_length - m25p_cmdsz(flash);
}
to += actual;
flash->command[0] = OPCODE_AAI_WP;
m25p_addr2cmd(flash, to, flash->command);
cmd_sz = m25p_cmdsz(flash);
for (; actual < len - 1; actual += 2) {
t[0].len = cmd_sz;
t[1].len = 2;
t[1].tx_buf = buf + actual;
spi_sync(flash->spi, &m);
ret = wait_till_ready(flash);
if (ret)
goto time_out;
*retlen += m.actual_length - cmd_sz;
cmd_sz = 1;
to += 2;
}
write_disable(flash);
ret = wait_till_ready(flash);
if (ret)
goto time_out;
if (actual != len) {
write_enable(flash);
flash->command[0] = OPCODE_BP;
m25p_addr2cmd(flash, to, flash->command);
t[0].len = m25p_cmdsz(flash);
t[1].len = 1;
t[1].tx_buf = buf + actual;
spi_sync(flash->spi, &m);
ret = wait_till_ready(flash);
if (ret)
goto time_out;
*retlen += m.actual_length - m25p_cmdsz(flash);
write_disable(flash);
}
time_out:
mutex_unlock(&flash->lock);
return ret;
}
static const struct spi_device_id *__devinit jedec_probe(struct spi_device *spi)
{
int tmp;
u8 code = OPCODE_RDID;
u8 id[5];
u32 jedec;
u16 ext_jedec;
struct flash_info *info;
tmp = spi_write_then_read(spi, &code, 1, id, 5);
if (tmp < 0) {
pr_debug("%s: error %d reading JEDEC ID\n",
dev_name(&spi->dev), tmp);
return ERR_PTR(tmp);
}
jedec = id[0];
jedec = jedec << 8;
jedec |= id[1];
jedec = jedec << 8;
jedec |= id[2];
ext_jedec = id[3] << 8 | id[4];
for (tmp = 0; tmp < ARRAY_SIZE(m25p_ids) - 1; tmp++) {
info = (void *)m25p_ids[tmp].driver_data;
if (info->jedec_id == jedec) {
if (info->ext_id != 0 && info->ext_id != ext_jedec)
continue;
return &m25p_ids[tmp];
}
}
dev_err(&spi->dev, "unrecognized JEDEC id %06x\n", jedec);
return ERR_PTR(-ENODEV);
}
static int __devinit m25p_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct flash_platform_data *data;
struct m25p *flash;
struct flash_info *info;
unsigned i;
struct mtd_part_parser_data ppdata;
#ifdef CONFIG_MTD_OF_PARTS
if (!of_device_is_available(spi->dev.of_node))
return -ENODEV;
#endif
data = spi->dev.platform_data;
if (data && data->type) {
const struct spi_device_id *plat_id;
for (i = 0; i < ARRAY_SIZE(m25p_ids) - 1; i++) {
plat_id = &m25p_ids[i];
if (strcmp(data->type, plat_id->name))
continue;
break;
}
if (i < ARRAY_SIZE(m25p_ids) - 1)
id = plat_id;
else
dev_warn(&spi->dev, "unrecognized id %s\n", data->type);
}
info = (void *)id->driver_data;
if (info->jedec_id) {
const struct spi_device_id *jid;
jid = jedec_probe(spi);
if (IS_ERR(jid)) {
return PTR_ERR(jid);
} else if (jid != id) {
dev_warn(&spi->dev, "found %s, expected %s\n",
jid->name, id->name);
id = jid;
info = (void *)jid->driver_data;
}
}
flash = kzalloc(sizeof *flash, GFP_KERNEL);
if (!flash)
return -ENOMEM;
flash->command = kmalloc(MAX_CMD_SIZE + FAST_READ_DUMMY_BYTE, GFP_KERNEL);
if (!flash->command) {
kfree(flash);
return -ENOMEM;
}
flash->spi = spi;
mutex_init(&flash->lock);
dev_set_drvdata(&spi->dev, flash);
if (JEDEC_MFR(info->jedec_id) == CFI_MFR_ATMEL ||
JEDEC_MFR(info->jedec_id) == CFI_MFR_INTEL ||
JEDEC_MFR(info->jedec_id) == CFI_MFR_SST) {
write_enable(flash);
write_sr(flash, 0);
}
if (data && data->name)
flash->mtd.name = data->name;
else
flash->mtd.name = dev_name(&spi->dev);
flash->mtd.type = MTD_NORFLASH;
flash->mtd.writesize = 1;
flash->mtd.flags = MTD_CAP_NORFLASH;
flash->mtd.size = info->sector_size * info->n_sectors;
flash->mtd._erase = m25p80_erase;
flash->mtd._read = m25p80_read;
if (JEDEC_MFR(info->jedec_id) == CFI_MFR_SST)
flash->mtd._write = sst_write;
else
flash->mtd._write = m25p80_write;
if (info->flags & SECT_4K) {
flash->erase_opcode = OPCODE_BE_4K;
flash->mtd.erasesize = 4096;
} else {
flash->erase_opcode = OPCODE_SE;
flash->mtd.erasesize = info->sector_size;
}
if (info->flags & M25P_NO_ERASE)
flash->mtd.flags |= MTD_NO_ERASE;
ppdata.of_node = spi->dev.of_node;
flash->mtd.dev.parent = &spi->dev;
flash->page_size = info->page_size;
flash->mtd.writebufsize = flash->page_size;
if (info->addr_width)
flash->addr_width = info->addr_width;
else {
if (flash->mtd.size > 0x1000000) {
flash->addr_width = 4;
set_4byte(flash, info->jedec_id, 1);
} else
flash->addr_width = 3;
}
dev_info(&spi->dev, "%s (%lld Kbytes)\n", id->name,
(long long)flash->mtd.size >> 10);
pr_debug("mtd .name = %s, .size = 0x%llx (%lldMiB) "
".erasesize = 0x%.8x (%uKiB) .numeraseregions = %d\n",
flash->mtd.name,
(long long)flash->mtd.size, (long long)(flash->mtd.size >> 20),
flash->mtd.erasesize, flash->mtd.erasesize / 1024,
flash->mtd.numeraseregions);
if (flash->mtd.numeraseregions)
for (i = 0; i < flash->mtd.numeraseregions; i++)
pr_debug("mtd.eraseregions[%d] = { .offset = 0x%llx, "
".erasesize = 0x%.8x (%uKiB), "
".numblocks = %d }\n",
i, (long long)flash->mtd.eraseregions[i].offset,
flash->mtd.eraseregions[i].erasesize,
flash->mtd.eraseregions[i].erasesize / 1024,
flash->mtd.eraseregions[i].numblocks);
return mtd_device_parse_register(&flash->mtd, NULL, &ppdata,
data ? data->parts : NULL,
data ? data->nr_parts : 0);
}
static int __devexit m25p_remove(struct spi_device *spi)
{
struct m25p *flash = dev_get_drvdata(&spi->dev);
int status;
status = mtd_device_unregister(&flash->mtd);
if (status == 0) {
kfree(flash->command);
kfree(flash);
}
return 0;
}
