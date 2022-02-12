static inline int dataflash_status(struct spi_device *spi)
{
return spi_w8r8(spi, OP_READ_STATUS);
}
static int dataflash_waitready(struct spi_device *spi)
{
int status;
for (;;) {
status = dataflash_status(spi);
if (status < 0) {
dev_dbg(&spi->dev, "status %d?\n", status);
status = 0;
}
if (status & (1 << 7))
return status;
msleep(3);
}
}
static int dataflash_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct dataflash *priv = mtd->priv;
struct spi_device *spi = priv->spi;
struct spi_transfer x = { };
struct spi_message msg;
unsigned blocksize = priv->page_size << 3;
u8 *command;
u32 rem;
dev_dbg(&spi->dev, "erase addr=0x%llx len 0x%llx\n",
(long long)instr->addr, (long long)instr->len);
div_u64_rem(instr->len, priv->page_size, &rem);
if (rem)
return -EINVAL;
div_u64_rem(instr->addr, priv->page_size, &rem);
if (rem)
return -EINVAL;
spi_message_init(&msg);
x.tx_buf = command = priv->command;
x.len = 4;
spi_message_add_tail(&x, &msg);
mutex_lock(&priv->lock);
while (instr->len > 0) {
unsigned int pageaddr;
int status;
int do_block;
pageaddr = div_u64(instr->addr, priv->page_size);
do_block = (pageaddr & 0x7) == 0 && instr->len >= blocksize;
pageaddr = pageaddr << priv->page_offset;
command[0] = do_block ? OP_ERASE_BLOCK : OP_ERASE_PAGE;
command[1] = (u8)(pageaddr >> 16);
command[2] = (u8)(pageaddr >> 8);
command[3] = 0;
dev_dbg(&spi->dev, "ERASE %s: (%x) %x %x %x [%i]\n",
do_block ? "block" : "page",
command[0], command[1], command[2], command[3],
pageaddr);
status = spi_sync(spi, &msg);
(void) dataflash_waitready(spi);
if (status < 0) {
dev_err(&spi->dev, "erase %x, err %d\n",
pageaddr, status);
continue;
}
if (do_block) {
instr->addr += blocksize;
instr->len -= blocksize;
} else {
instr->addr += priv->page_size;
instr->len -= priv->page_size;
}
}
mutex_unlock(&priv->lock);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return 0;
}
static int dataflash_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct dataflash *priv = mtd->priv;
struct spi_transfer x[2] = { };
struct spi_message msg;
unsigned int addr;
u8 *command;
int status;
dev_dbg(&priv->spi->dev, "read 0x%x..0x%x\n",
(unsigned int)from, (unsigned int)(from + len));
addr = (((unsigned)from / priv->page_size) << priv->page_offset)
+ ((unsigned)from % priv->page_size);
command = priv->command;
dev_dbg(&priv->spi->dev, "READ: (%x) %x %x %x\n",
command[0], command[1], command[2], command[3]);
spi_message_init(&msg);
x[0].tx_buf = command;
x[0].len = 8;
spi_message_add_tail(&x[0], &msg);
x[1].rx_buf = buf;
x[1].len = len;
spi_message_add_tail(&x[1], &msg);
mutex_lock(&priv->lock);
command[0] = OP_READ_CONTINUOUS;
command[1] = (u8)(addr >> 16);
command[2] = (u8)(addr >> 8);
command[3] = (u8)(addr >> 0);
status = spi_sync(priv->spi, &msg);
mutex_unlock(&priv->lock);
if (status >= 0) {
*retlen = msg.actual_length - 8;
status = 0;
} else
dev_dbg(&priv->spi->dev, "read %x..%x --> %d\n",
(unsigned)from, (unsigned)(from + len),
status);
return status;
}
static int dataflash_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t * retlen, const u_char * buf)
{
struct dataflash *priv = mtd->priv;
struct spi_device *spi = priv->spi;
struct spi_transfer x[2] = { };
struct spi_message msg;
unsigned int pageaddr, addr, offset, writelen;
size_t remaining = len;
u_char *writebuf = (u_char *) buf;
int status = -EINVAL;
u8 *command;
dev_dbg(&spi->dev, "write 0x%x..0x%x\n",
(unsigned int)to, (unsigned int)(to + len));
spi_message_init(&msg);
x[0].tx_buf = command = priv->command;
x[0].len = 4;
spi_message_add_tail(&x[0], &msg);
pageaddr = ((unsigned)to / priv->page_size);
offset = ((unsigned)to % priv->page_size);
if (offset + len > priv->page_size)
writelen = priv->page_size - offset;
else
writelen = len;
mutex_lock(&priv->lock);
while (remaining > 0) {
dev_dbg(&spi->dev, "write @ %i:%i len=%i\n",
pageaddr, offset, writelen);
addr = pageaddr << priv->page_offset;
if (writelen != priv->page_size) {
command[0] = OP_TRANSFER_BUF1;
command[1] = (addr & 0x00FF0000) >> 16;
command[2] = (addr & 0x0000FF00) >> 8;
command[3] = 0;
dev_dbg(&spi->dev, "TRANSFER: (%x) %x %x %x\n",
command[0], command[1], command[2], command[3]);
status = spi_sync(spi, &msg);
if (status < 0)
dev_dbg(&spi->dev, "xfer %u -> %d\n",
addr, status);
(void) dataflash_waitready(priv->spi);
}
addr += offset;
command[0] = OP_PROGRAM_VIA_BUF1;
command[1] = (addr & 0x00FF0000) >> 16;
command[2] = (addr & 0x0000FF00) >> 8;
command[3] = (addr & 0x000000FF);
dev_dbg(&spi->dev, "PROGRAM: (%x) %x %x %x\n",
command[0], command[1], command[2], command[3]);
x[1].tx_buf = writebuf;
x[1].len = writelen;
spi_message_add_tail(x + 1, &msg);
status = spi_sync(spi, &msg);
spi_transfer_del(x + 1);
if (status < 0)
dev_dbg(&spi->dev, "pgm %u/%u -> %d\n",
addr, writelen, status);
(void) dataflash_waitready(priv->spi);
#ifdef CONFIG_MTD_DATAFLASH_WRITE_VERIFY
addr = pageaddr << priv->page_offset;
command[0] = OP_COMPARE_BUF1;
command[1] = (addr & 0x00FF0000) >> 16;
command[2] = (addr & 0x0000FF00) >> 8;
command[3] = 0;
dev_dbg(&spi->dev, "COMPARE: (%x) %x %x %x\n",
command[0], command[1], command[2], command[3]);
status = spi_sync(spi, &msg);
if (status < 0)
dev_dbg(&spi->dev, "compare %u -> %d\n",
addr, status);
status = dataflash_waitready(priv->spi);
if (status & (1 << 6)) {
dev_err(&spi->dev, "compare page %u, err %d\n",
pageaddr, status);
remaining = 0;
status = -EIO;
break;
} else
status = 0;
#endif
remaining = remaining - writelen;
pageaddr++;
offset = 0;
writebuf += writelen;
*retlen += writelen;
if (remaining > priv->page_size)
writelen = priv->page_size;
else
writelen = remaining;
}
mutex_unlock(&priv->lock);
return status;
}
static int dataflash_get_otp_info(struct mtd_info *mtd, size_t len,
size_t *retlen, struct otp_info *info)
{
info->start = 0;
info->length = 64;
info->locked = 1;
*retlen = sizeof(*info);
return 0;
}
static ssize_t otp_read(struct spi_device *spi, unsigned base,
u8 *buf, loff_t off, size_t len)
{
struct spi_message m;
size_t l;
u8 *scratch;
struct spi_transfer t;
int status;
if (off > 64)
return -EINVAL;
if ((off + len) > 64)
len = 64 - off;
spi_message_init(&m);
l = 4 + base + off + len;
scratch = kzalloc(l, GFP_KERNEL);
if (!scratch)
return -ENOMEM;
scratch[0] = OP_READ_SECURITY;
memset(&t, 0, sizeof t);
t.tx_buf = scratch;
t.rx_buf = scratch;
t.len = l;
spi_message_add_tail(&t, &m);
dataflash_waitready(spi);
status = spi_sync(spi, &m);
if (status >= 0) {
memcpy(buf, scratch + 4 + base + off, len);
status = len;
}
kfree(scratch);
return status;
}
static int dataflash_read_fact_otp(struct mtd_info *mtd,
loff_t from, size_t len, size_t *retlen, u_char *buf)
{
struct dataflash *priv = mtd->priv;
int status;
mutex_lock(&priv->lock);
status = otp_read(priv->spi, 64, buf, from, len);
mutex_unlock(&priv->lock);
if (status < 0)
return status;
*retlen = status;
return 0;
}
static int dataflash_read_user_otp(struct mtd_info *mtd,
loff_t from, size_t len, size_t *retlen, u_char *buf)
{
struct dataflash *priv = mtd->priv;
int status;
mutex_lock(&priv->lock);
status = otp_read(priv->spi, 0, buf, from, len);
mutex_unlock(&priv->lock);
if (status < 0)
return status;
*retlen = status;
return 0;
}
static int dataflash_write_user_otp(struct mtd_info *mtd,
loff_t from, size_t len, size_t *retlen, u_char *buf)
{
struct spi_message m;
const size_t l = 4 + 64;
u8 *scratch;
struct spi_transfer t;
struct dataflash *priv = mtd->priv;
int status;
if (from >= 64) {
*retlen = 0;
return 0;
}
if ((from + len) > 64)
len = 64 - from;
scratch = kzalloc(l, GFP_KERNEL);
if (!scratch)
return -ENOMEM;
scratch[0] = OP_WRITE_SECURITY;
memcpy(scratch + 4 + from, buf, len);
spi_message_init(&m);
memset(&t, 0, sizeof t);
t.tx_buf = scratch;
t.len = l;
spi_message_add_tail(&t, &m);
mutex_lock(&priv->lock);
dataflash_waitready(priv->spi);
status = spi_sync(priv->spi, &m);
mutex_unlock(&priv->lock);
kfree(scratch);
if (status >= 0) {
status = 0;
*retlen = len;
}
return status;
}
static char *otp_setup(struct mtd_info *device, char revision)
{
device->_get_fact_prot_info = dataflash_get_otp_info;
device->_read_fact_prot_reg = dataflash_read_fact_otp;
device->_get_user_prot_info = dataflash_get_otp_info;
device->_read_user_prot_reg = dataflash_read_user_otp;
if (revision > 'c')
device->_write_user_prot_reg = dataflash_write_user_otp;
return ", OTP";
}
static char *otp_setup(struct mtd_info *device, char revision)
{
return " (OTP)";
}
static int add_dataflash_otp(struct spi_device *spi, char *name, int nr_pages,
int pagesize, int pageoffset, char revision)
{
struct dataflash *priv;
struct mtd_info *device;
struct flash_platform_data *pdata = dev_get_platdata(&spi->dev);
char *otp_tag = "";
int err = 0;
priv = kzalloc(sizeof *priv, GFP_KERNEL);
if (!priv)
return -ENOMEM;
mutex_init(&priv->lock);
priv->spi = spi;
priv->page_size = pagesize;
priv->page_offset = pageoffset;
sprintf(priv->name, "spi%d.%d-%s",
spi->master->bus_num, spi->chip_select,
name);
device = &priv->mtd;
device->name = (pdata && pdata->name) ? pdata->name : priv->name;
device->size = nr_pages * pagesize;
device->erasesize = pagesize;
device->writesize = pagesize;
device->type = MTD_DATAFLASH;
device->flags = MTD_WRITEABLE;
device->_erase = dataflash_erase;
device->_read = dataflash_read;
device->_write = dataflash_write;
device->priv = priv;
device->dev.parent = &spi->dev;
mtd_set_of_node(device, spi->dev.of_node);
if (revision >= 'c')
otp_tag = otp_setup(device, revision);
dev_info(&spi->dev, "%s (%lld KBytes) pagesize %d bytes%s\n",
name, (long long)((device->size + 1023) >> 10),
pagesize, otp_tag);
spi_set_drvdata(spi, priv);
err = mtd_device_register(device,
pdata ? pdata->parts : NULL,
pdata ? pdata->nr_parts : 0);
if (!err)
return 0;
kfree(priv);
return err;
}
static inline int add_dataflash(struct spi_device *spi, char *name,
int nr_pages, int pagesize, int pageoffset)
{
return add_dataflash_otp(spi, name, nr_pages, pagesize,
pageoffset, 0);
}
static struct flash_info *jedec_lookup(struct spi_device *spi,
u64 jedec, bool use_extid)
{
struct flash_info *info;
int status;
for (info = dataflash_data;
info < dataflash_data + ARRAY_SIZE(dataflash_data);
info++) {
if (use_extid && !(info->flags & SUP_EXTID))
continue;
if (info->jedec_id == jedec) {
dev_dbg(&spi->dev, "OTP, sector protect%s\n",
(info->flags & SUP_POW2PS) ?
", binary pagesize" : "");
if (info->flags & SUP_POW2PS) {
status = dataflash_status(spi);
if (status < 0) {
dev_dbg(&spi->dev, "status error %d\n",
status);
return ERR_PTR(status);
}
if (status & 0x1) {
if (info->flags & IS_POW2PS)
return info;
} else {
if (!(info->flags & IS_POW2PS))
return info;
}
} else
return info;
}
}
return ERR_PTR(-ENODEV);
}
static struct flash_info *jedec_probe(struct spi_device *spi)
{
int ret;
u8 code = OP_READ_ID;
u64 jedec;
u8 id[sizeof(jedec)] = {0};
const unsigned int id_size = 5;
struct flash_info *info;
ret = spi_write_then_read(spi, &code, 1, id, id_size);
if (ret < 0) {
dev_dbg(&spi->dev, "error %d reading JEDEC ID\n", ret);
return ERR_PTR(ret);
}
if (id[0] != CFI_MFR_ATMEL)
return NULL;
jedec = be64_to_cpup((__be64 *)id);
info = jedec_lookup(spi, jedec >> DATAFLASH_SHIFT_EXTID, true);
if (!IS_ERR(info))
return info;
info = jedec_lookup(spi, jedec >> DATAFLASH_SHIFT_ID, false);
if (!IS_ERR(info))
return info;
dev_warn(&spi->dev, "JEDEC id %016llx not handled\n", jedec);
return ERR_PTR(-ENODEV);
}
static int dataflash_probe(struct spi_device *spi)
{
int status;
struct flash_info *info;
info = jedec_probe(spi);
if (IS_ERR(info))
return PTR_ERR(info);
if (info != NULL)
return add_dataflash_otp(spi, info->name, info->nr_pages,
info->pagesize, info->pageoffset,
(info->flags & SUP_POW2PS) ? 'd' : 'c');
status = dataflash_status(spi);
if (status <= 0 || status == 0xff) {
dev_dbg(&spi->dev, "status error %d\n", status);
if (status == 0 || status == 0xff)
status = -ENODEV;
return status;
}
switch (status & 0x3c) {
case 0x0c:
status = add_dataflash(spi, "AT45DB011B", 512, 264, 9);
break;
case 0x14:
status = add_dataflash(spi, "AT45DB021B", 1024, 264, 9);
break;
case 0x1c:
status = add_dataflash(spi, "AT45DB041x", 2048, 264, 9);
break;
case 0x24:
status = add_dataflash(spi, "AT45DB081B", 4096, 264, 9);
break;
case 0x2c:
status = add_dataflash(spi, "AT45DB161x", 4096, 528, 10);
break;
case 0x34:
status = add_dataflash(spi, "AT45DB321x", 8192, 528, 10);
break;
case 0x38:
case 0x3c:
status = add_dataflash(spi, "AT45DB642x", 8192, 1056, 11);
break;
default:
dev_info(&spi->dev, "unsupported device (%x)\n",
status & 0x3c);
status = -ENODEV;
}
if (status < 0)
dev_dbg(&spi->dev, "add_dataflash --> %d\n", status);
return status;
}
static int dataflash_remove(struct spi_device *spi)
{
struct dataflash *flash = spi_get_drvdata(spi);
int status;
dev_dbg(&spi->dev, "remove\n");
status = mtd_device_unregister(&flash->mtd);
if (status == 0)
kfree(flash);
return status;
}
