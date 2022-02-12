static u_char au_read_byte(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
u_char ret = readb(this->IO_ADDR_R);
au_sync();
return ret;
}
static void au_write_byte(struct mtd_info *mtd, u_char byte)
{
struct nand_chip *this = mtd->priv;
writeb(byte, this->IO_ADDR_W);
au_sync();
}
static u_char au_read_byte16(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
u_char ret = (u_char) cpu_to_le16(readw(this->IO_ADDR_R));
au_sync();
return ret;
}
static void au_write_byte16(struct mtd_info *mtd, u_char byte)
{
struct nand_chip *this = mtd->priv;
writew(le16_to_cpu((u16) byte), this->IO_ADDR_W);
au_sync();
}
static u16 au_read_word(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
u16 ret = readw(this->IO_ADDR_R);
au_sync();
return ret;
}
static void au_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
for (i = 0; i < len; i++) {
writeb(buf[i], this->IO_ADDR_W);
au_sync();
}
}
static void au_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
for (i = 0; i < len; i++) {
buf[i] = readb(this->IO_ADDR_R);
au_sync();
}
}
static int au_verify_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
for (i = 0; i < len; i++) {
if (buf[i] != readb(this->IO_ADDR_R))
return -EFAULT;
au_sync();
}
return 0;
}
static void au_write_buf16(struct mtd_info *mtd, const u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
u16 *p = (u16 *) buf;
len >>= 1;
for (i = 0; i < len; i++) {
writew(p[i], this->IO_ADDR_W);
au_sync();
}
}
static void au_read_buf16(struct mtd_info *mtd, u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
u16 *p = (u16 *) buf;
len >>= 1;
for (i = 0; i < len; i++) {
p[i] = readw(this->IO_ADDR_R);
au_sync();
}
}
static int au_verify_buf16(struct mtd_info *mtd, const u_char *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
u16 *p = (u16 *) buf;
len >>= 1;
for (i = 0; i < len; i++) {
if (p[i] != readw(this->IO_ADDR_R))
return -EFAULT;
au_sync();
}
return 0;
}
static void au1550_hwcontrol(struct mtd_info *mtd, int cmd)
{
register struct nand_chip *this = mtd->priv;
switch (cmd) {
case NAND_CTL_SETCLE:
this->IO_ADDR_W = p_nand + MEM_STNAND_CMD;
break;
case NAND_CTL_CLRCLE:
this->IO_ADDR_W = p_nand + MEM_STNAND_DATA;
break;
case NAND_CTL_SETALE:
this->IO_ADDR_W = p_nand + MEM_STNAND_ADDR;
break;
case NAND_CTL_CLRALE:
this->IO_ADDR_W = p_nand + MEM_STNAND_DATA;
udelay(1);
break;
case NAND_CTL_SETNCE:
au_writel((1 << (4 + NAND_CS)), MEM_STNDCTL);
break;
case NAND_CTL_CLRNCE:
au_writel(0, MEM_STNDCTL);
break;
}
this->IO_ADDR_R = this->IO_ADDR_W;
au_sync();
}
int au1550_device_ready(struct mtd_info *mtd)
{
int ret = (au_readl(MEM_STSTAT) & 0x1) ? 1 : 0;
au_sync();
return ret;
}
static void au1550_select_chip(struct mtd_info *mtd, int chip)
{
}
static void au1550_command(struct mtd_info *mtd, unsigned command, int column, int page_addr)
{
register struct nand_chip *this = mtd->priv;
int ce_override = 0, i;
ulong flags;
au1550_hwcontrol(mtd, NAND_CTL_SETCLE);
if (command == NAND_CMD_SEQIN) {
int readcmd;
if (column >= mtd->writesize) {
column -= mtd->writesize;
readcmd = NAND_CMD_READOOB;
} else if (column < 256) {
readcmd = NAND_CMD_READ0;
} else {
column -= 256;
readcmd = NAND_CMD_READ1;
}
au1550_write_byte(mtd, readcmd);
}
au1550_write_byte(mtd, command);
au1550_hwcontrol(mtd, NAND_CTL_CLRCLE);
if (column != -1 || page_addr != -1) {
au1550_hwcontrol(mtd, NAND_CTL_SETALE);
if (column != -1) {
if (this->options & NAND_BUSWIDTH_16)
column >>= 1;
au1550_write_byte(mtd, column);
}
if (page_addr != -1) {
au1550_write_byte(mtd, (u8)(page_addr & 0xff));
if (command == NAND_CMD_READ0 ||
command == NAND_CMD_READ1 ||
command == NAND_CMD_READOOB) {
ce_override = 1;
local_irq_save(flags);
au1550_hwcontrol(mtd, NAND_CTL_SETNCE);
}
au1550_write_byte(mtd, (u8)(page_addr >> 8));
if (this->chipsize > (32 << 20))
au1550_write_byte(mtd, (u8)((page_addr >> 16) & 0x0f));
}
au1550_hwcontrol(mtd, NAND_CTL_CLRALE);
}
switch (command) {
case NAND_CMD_PAGEPROG:
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
case NAND_CMD_SEQIN:
case NAND_CMD_STATUS:
return;
case NAND_CMD_RESET:
break;
case NAND_CMD_READ0:
case NAND_CMD_READ1:
case NAND_CMD_READOOB:
if (unlikely(!ce_override))
break;
ndelay(100);
for (i = this->chip_delay; !this->dev_ready(mtd) && i > 0; --i)
udelay(1);
au1550_hwcontrol(mtd, NAND_CTL_CLRNCE);
local_irq_restore(flags);
return;
}
ndelay(100);
while(!this->dev_ready(mtd));
}
static int __init au1xxx_nand_init(void)
{
struct nand_chip *this;
u16 boot_swapboot = 0;
int retval;
u32 mem_staddr;
u32 nand_phys;
au1550_mtd = kzalloc(sizeof(struct mtd_info) + sizeof(struct nand_chip), GFP_KERNEL);
if (!au1550_mtd) {
printk("Unable to allocate NAND MTD dev structure.\n");
return -ENOMEM;
}
this = (struct nand_chip *)(&au1550_mtd[1]);
au1550_mtd->priv = this;
au1550_mtd->owner = THIS_MODULE;
au_writel(0, MEM_STNDCTL);
#ifdef CONFIG_MIPS_PB1550
gpio_direction_input(206);
boot_swapboot = (au_readl(MEM_STSTAT) & (0x7 << 1)) | ((bcsr_read(BCSR_STATUS) >> 6) & 0x1);
switch (boot_swapboot) {
case 0:
case 2:
case 8:
case 0xC:
case 0xD:
nand_width = 0;
break;
case 1:
case 9:
case 3:
case 0xE:
case 0xF:
nand_width = 1;
break;
default:
printk("Pb1550 NAND: bad boot:swap\n");
retval = -EINVAL;
goto outmem;
}
#endif
#ifdef NAND_STCFG
if (NAND_CS == 0) {
au_writel(NAND_STCFG, MEM_STCFG0);
au_writel(NAND_STTIME, MEM_STTIME0);
au_writel(NAND_STADDR, MEM_STADDR0);
}
if (NAND_CS == 1) {
au_writel(NAND_STCFG, MEM_STCFG1);
au_writel(NAND_STTIME, MEM_STTIME1);
au_writel(NAND_STADDR, MEM_STADDR1);
}
if (NAND_CS == 2) {
au_writel(NAND_STCFG, MEM_STCFG2);
au_writel(NAND_STTIME, MEM_STTIME2);
au_writel(NAND_STADDR, MEM_STADDR2);
}
if (NAND_CS == 3) {
au_writel(NAND_STCFG, MEM_STCFG3);
au_writel(NAND_STTIME, MEM_STTIME3);
au_writel(NAND_STADDR, MEM_STADDR3);
}
#endif
mem_staddr = 0x00000000;
if (((au_readl(MEM_STCFG0) & 0x7) == 0x5) && (NAND_CS == 0))
mem_staddr = au_readl(MEM_STADDR0);
else if (((au_readl(MEM_STCFG1) & 0x7) == 0x5) && (NAND_CS == 1))
mem_staddr = au_readl(MEM_STADDR1);
else if (((au_readl(MEM_STCFG2) & 0x7) == 0x5) && (NAND_CS == 2))
mem_staddr = au_readl(MEM_STADDR2);
else if (((au_readl(MEM_STCFG3) & 0x7) == 0x5) && (NAND_CS == 3))
mem_staddr = au_readl(MEM_STADDR3);
if (mem_staddr == 0x00000000) {
printk("Au1xxx NAND: ERROR WITH NAND CHIP-SELECT\n");
kfree(au1550_mtd);
return 1;
}
nand_phys = (mem_staddr << 4) & 0xFFFC0000;
p_nand = ioremap(nand_phys, 0x1000);
if (NAND_CS == 0)
nand_width = au_readl(MEM_STCFG0) & (1 << 22);
if (NAND_CS == 1)
nand_width = au_readl(MEM_STCFG1) & (1 << 22);
if (NAND_CS == 2)
nand_width = au_readl(MEM_STCFG2) & (1 << 22);
if (NAND_CS == 3)
nand_width = au_readl(MEM_STCFG3) & (1 << 22);
this->dev_ready = au1550_device_ready;
this->select_chip = au1550_select_chip;
this->cmdfunc = au1550_command;
this->chip_delay = 30;
this->ecc.mode = NAND_ECC_SOFT;
this->options = NAND_NO_AUTOINCR;
if (!nand_width)
this->options |= NAND_BUSWIDTH_16;
this->read_byte = (!nand_width) ? au_read_byte16 : au_read_byte;
au1550_write_byte = (!nand_width) ? au_write_byte16 : au_write_byte;
this->read_word = au_read_word;
this->write_buf = (!nand_width) ? au_write_buf16 : au_write_buf;
this->read_buf = (!nand_width) ? au_read_buf16 : au_read_buf;
this->verify_buf = (!nand_width) ? au_verify_buf16 : au_verify_buf;
if (nand_scan(au1550_mtd, 1)) {
retval = -ENXIO;
goto outio;
}
mtd_device_register(au1550_mtd, partition_info,
ARRAY_SIZE(partition_info));
return 0;
outio:
iounmap(p_nand);
outmem:
kfree(au1550_mtd);
return retval;
}
static void __exit au1550_cleanup(void)
{
nand_release(au1550_mtd);
kfree(au1550_mtd);
iounmap(p_nand);
}
