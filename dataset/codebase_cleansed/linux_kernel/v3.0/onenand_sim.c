static void onenand_lock_handle(struct onenand_chip *this, int cmd)
{
int block_lock_scheme;
int status;
status = ONENAND_GET_WP_STATUS(this);
block_lock_scheme = !(this->options & ONENAND_HAS_CONT_LOCK);
switch (cmd) {
case ONENAND_CMD_UNLOCK:
case ONENAND_CMD_UNLOCK_ALL:
if (block_lock_scheme)
ONENAND_SET_WP_STATUS(ONENAND_WP_US, this);
else
ONENAND_SET_WP_STATUS(status | ONENAND_WP_US, this);
break;
case ONENAND_CMD_LOCK:
if (block_lock_scheme)
ONENAND_SET_WP_STATUS(ONENAND_WP_LS, this);
else
ONENAND_SET_WP_STATUS(status | ONENAND_WP_LS, this);
break;
case ONENAND_CMD_LOCK_TIGHT:
if (block_lock_scheme)
ONENAND_SET_WP_STATUS(ONENAND_WP_LTS, this);
else
ONENAND_SET_WP_STATUS(status | ONENAND_WP_LTS, this);
break;
default:
break;
}
}
static void onenand_bootram_handle(struct onenand_chip *this, int cmd)
{
switch (cmd) {
case ONENAND_CMD_READID:
writew(manuf_id, this->base);
writew(device_id, this->base + 2);
writew(version_id, this->base + 4);
break;
default:
break;
}
}
static void onenand_update_interrupt(struct onenand_chip *this, int cmd)
{
int interrupt = ONENAND_INT_MASTER;
switch (cmd) {
case ONENAND_CMD_READ:
case ONENAND_CMD_READOOB:
interrupt |= ONENAND_INT_READ;
break;
case ONENAND_CMD_PROG:
case ONENAND_CMD_PROGOOB:
interrupt |= ONENAND_INT_WRITE;
break;
case ONENAND_CMD_ERASE:
interrupt |= ONENAND_INT_ERASE;
break;
case ONENAND_CMD_RESET:
interrupt |= ONENAND_INT_RESET;
break;
default:
break;
}
writew(interrupt, this->base + ONENAND_REG_INTERRUPT);
}
static int onenand_check_overwrite(void *dest, void *src, size_t count)
{
unsigned int *s = (unsigned int *) src;
unsigned int *d = (unsigned int *) dest;
int i;
count >>= 2;
for (i = 0; i < count; i++)
if ((*s++ ^ *d++) != 0)
return 1;
return 0;
}
static void onenand_data_handle(struct onenand_chip *this, int cmd,
int dataram, unsigned int offset)
{
struct mtd_info *mtd = &info->mtd;
struct onenand_flash *flash = this->priv;
int main_offset, spare_offset, die = 0;
void __iomem *src;
void __iomem *dest;
unsigned int i;
static int pi_operation;
int erasesize, rgn;
if (dataram) {
main_offset = mtd->writesize;
spare_offset = mtd->oobsize;
} else {
main_offset = 0;
spare_offset = 0;
}
if (pi_operation) {
die = readw(this->base + ONENAND_REG_START_ADDRESS2);
die >>= ONENAND_DDP_SHIFT;
}
switch (cmd) {
case FLEXONENAND_CMD_PI_ACCESS:
pi_operation = 1;
break;
case ONENAND_CMD_RESET:
pi_operation = 0;
break;
case ONENAND_CMD_READ:
src = ONENAND_CORE(flash) + offset;
dest = ONENAND_MAIN_AREA(this, main_offset);
if (pi_operation) {
writew(boundary[die], this->base + ONENAND_DATARAM);
break;
}
memcpy(dest, src, mtd->writesize);
case ONENAND_CMD_READOOB:
src = ONENAND_CORE_SPARE(flash, this, offset);
dest = ONENAND_SPARE_AREA(this, spare_offset);
memcpy(dest, src, mtd->oobsize);
break;
case ONENAND_CMD_PROG:
src = ONENAND_MAIN_AREA(this, main_offset);
dest = ONENAND_CORE(flash) + offset;
if (pi_operation) {
boundary[die] = readw(this->base + ONENAND_DATARAM);
break;
}
for (i = 0; i < (1 << mtd->subpage_sft); i++) {
int off = i * this->subpagesize;
if (!memcmp(src + off, ffchars, this->subpagesize))
continue;
if (memcmp(dest + off, ffchars, this->subpagesize) &&
onenand_check_overwrite(dest + off, src + off, this->subpagesize))
printk(KERN_ERR "over-write happened at 0x%08x\n", offset);
memcpy(dest + off, src + off, this->subpagesize);
}
case ONENAND_CMD_PROGOOB:
src = ONENAND_SPARE_AREA(this, spare_offset);
if (!memcmp(src, ffchars, mtd->oobsize))
break;
dest = ONENAND_CORE_SPARE(flash, this, offset);
if (memcmp(dest, ffchars, mtd->oobsize) &&
onenand_check_overwrite(dest, src, mtd->oobsize))
printk(KERN_ERR "OOB: over-write happened at 0x%08x\n",
offset);
memcpy(dest, src, mtd->oobsize);
break;
case ONENAND_CMD_ERASE:
if (pi_operation)
break;
if (FLEXONENAND(this)) {
rgn = flexonenand_region(mtd, offset);
erasesize = mtd->eraseregions[rgn].erasesize;
} else
erasesize = mtd->erasesize;
memset(ONENAND_CORE(flash) + offset, 0xff, erasesize);
memset(ONENAND_CORE_SPARE(flash, this, offset), 0xff,
(erasesize >> 5));
break;
default:
break;
}
}
static void onenand_command_handle(struct onenand_chip *this, int cmd)
{
unsigned long offset = 0;
int block = -1, page = -1, bufferram = -1;
int dataram = 0;
switch (cmd) {
case ONENAND_CMD_UNLOCK:
case ONENAND_CMD_LOCK:
case ONENAND_CMD_LOCK_TIGHT:
case ONENAND_CMD_UNLOCK_ALL:
onenand_lock_handle(this, cmd);
break;
case ONENAND_CMD_BUFFERRAM:
return;
default:
block = (int) readw(this->base + ONENAND_REG_START_ADDRESS1);
if (block & (1 << ONENAND_DDP_SHIFT)) {
block &= ~(1 << ONENAND_DDP_SHIFT);
block += this->chipsize >> (this->erase_shift + 1);
}
if (cmd == ONENAND_CMD_ERASE)
break;
page = (int) readw(this->base + ONENAND_REG_START_ADDRESS8);
page = (page >> ONENAND_FPA_SHIFT);
bufferram = (int) readw(this->base + ONENAND_REG_START_BUFFER);
bufferram >>= ONENAND_BSA_SHIFT;
bufferram &= ONENAND_BSA_DATARAM1;
dataram = (bufferram == ONENAND_BSA_DATARAM1) ? 1 : 0;
break;
}
if (block != -1)
offset = onenand_addr(this, block);
if (page != -1)
offset += page << this->page_shift;
onenand_data_handle(this, cmd, dataram, offset);
onenand_update_interrupt(this, cmd);
}
static void onenand_writew(unsigned short value, void __iomem * addr)
{
struct onenand_chip *this = info->mtd.priv;
if (addr < this->base + ONENAND_DATARAM) {
onenand_bootram_handle(this, value);
return;
}
if (addr == this->base + ONENAND_REG_COMMAND)
onenand_command_handle(this, value);
writew(value, addr);
}
static int __init flash_init(struct onenand_flash *flash)
{
int density, size;
int buffer_size;
flash->base = kzalloc(131072, GFP_KERNEL);
if (!flash->base) {
printk(KERN_ERR "Unable to allocate base address.\n");
return -ENOMEM;
}
density = device_id >> ONENAND_DEVICE_DENSITY_SHIFT;
density &= ONENAND_DEVICE_DENSITY_MASK;
size = ((16 << 20) << density);
ONENAND_CORE(flash) = vmalloc(size + (size >> 5));
if (!ONENAND_CORE(flash)) {
printk(KERN_ERR "Unable to allocate nand core address.\n");
kfree(flash->base);
return -ENOMEM;
}
memset(ONENAND_CORE(flash), 0xff, size + (size >> 5));
writew(manuf_id, flash->base + ONENAND_REG_MANUFACTURER_ID);
writew(device_id, flash->base + ONENAND_REG_DEVICE_ID);
writew(version_id, flash->base + ONENAND_REG_VERSION_ID);
writew(technology_id, flash->base + ONENAND_REG_TECHNOLOGY);
if (density < 2 && (!CONFIG_FLEXONENAND))
buffer_size = 0x0400;
else
buffer_size = 0x0800;
writew(buffer_size, flash->base + ONENAND_REG_DATA_BUFFER_SIZE);
return 0;
}
static void flash_exit(struct onenand_flash *flash)
{
vfree(ONENAND_CORE(flash));
kfree(flash->base);
}
static int __init onenand_sim_init(void)
{
ffchars = kmalloc(MAX_ONENAND_PAGESIZE, GFP_KERNEL);
if (!ffchars) {
printk(KERN_ERR "Unable to allocate ff chars.\n");
return -ENOMEM;
}
memset(ffchars, 0xff, MAX_ONENAND_PAGESIZE);
info = kzalloc(sizeof(struct onenand_info), GFP_KERNEL);
if (!info) {
printk(KERN_ERR "Unable to allocate core structures.\n");
kfree(ffchars);
return -ENOMEM;
}
info->onenand.write_word = onenand_writew;
if (flash_init(&info->flash)) {
printk(KERN_ERR "Unable to allocate flash.\n");
kfree(ffchars);
kfree(info);
return -ENOMEM;
}
info->parts = os_partitions;
info->onenand.base = info->flash.base;
info->onenand.priv = &info->flash;
info->mtd.name = "OneNAND simulator";
info->mtd.priv = &info->onenand;
info->mtd.owner = THIS_MODULE;
if (onenand_scan(&info->mtd, 1)) {
flash_exit(&info->flash);
kfree(ffchars);
kfree(info);
return -ENXIO;
}
mtd_device_register(&info->mtd, info->parts,
ARRAY_SIZE(os_partitions));
return 0;
}
static void __exit onenand_sim_exit(void)
{
struct onenand_chip *this = info->mtd.priv;
struct onenand_flash *flash = this->priv;
onenand_release(&info->mtd);
flash_exit(flash);
kfree(ffchars);
kfree(info);
}
