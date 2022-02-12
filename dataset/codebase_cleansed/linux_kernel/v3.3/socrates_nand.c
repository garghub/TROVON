static void socrates_nand_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
struct socrates_nand_host *host = this->priv;
for (i = 0; i < len; i++) {
out_be32(host->io_base, FPGA_NAND_ENABLE |
FPGA_NAND_CMD_WRITE |
(buf[i] << FPGA_NAND_DATA_SHIFT));
}
}
static void socrates_nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
int i;
struct nand_chip *this = mtd->priv;
struct socrates_nand_host *host = this->priv;
uint32_t val;
val = FPGA_NAND_ENABLE | FPGA_NAND_CMD_READ;
out_be32(host->io_base, val);
for (i = 0; i < len; i++) {
buf[i] = (in_be32(host->io_base) >>
FPGA_NAND_DATA_SHIFT) & 0xff;
}
}
static uint8_t socrates_nand_read_byte(struct mtd_info *mtd)
{
uint8_t byte;
socrates_nand_read_buf(mtd, &byte, sizeof(byte));
return byte;
}
static uint16_t socrates_nand_read_word(struct mtd_info *mtd)
{
uint16_t word;
socrates_nand_read_buf(mtd, (uint8_t *)&word, sizeof(word));
return word;
}
static int socrates_nand_verify_buf(struct mtd_info *mtd, const u8 *buf,
int len)
{
int i;
for (i = 0; i < len; i++) {
if (buf[i] != socrates_nand_read_byte(mtd))
return -EFAULT;
}
return 0;
}
static void socrates_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *nand_chip = mtd->priv;
struct socrates_nand_host *host = nand_chip->priv;
uint32_t val;
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
val = FPGA_NAND_CMD_COMMAND;
else
val = FPGA_NAND_CMD_ADDR;
if (ctrl & NAND_NCE)
val |= FPGA_NAND_ENABLE;
val |= (cmd & 0xff) << FPGA_NAND_DATA_SHIFT;
out_be32(host->io_base, val);
}
static int socrates_nand_device_ready(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct socrates_nand_host *host = nand_chip->priv;
if (in_be32(host->io_base) & FPGA_NAND_BUSY)
return 0;
return 1;
}
static int __devinit socrates_nand_probe(struct platform_device *ofdev)
{
struct socrates_nand_host *host;
struct mtd_info *mtd;
struct nand_chip *nand_chip;
int res;
struct mtd_part_parser_data ppdata;
host = kzalloc(sizeof(struct socrates_nand_host), GFP_KERNEL);
if (!host) {
printk(KERN_ERR
"socrates_nand: failed to allocate device structure.\n");
return -ENOMEM;
}
host->io_base = of_iomap(ofdev->dev.of_node, 0);
if (host->io_base == NULL) {
printk(KERN_ERR "socrates_nand: ioremap failed\n");
kfree(host);
return -EIO;
}
mtd = &host->mtd;
nand_chip = &host->nand_chip;
host->dev = &ofdev->dev;
nand_chip->priv = host;
mtd->priv = nand_chip;
mtd->name = "socrates_nand";
mtd->owner = THIS_MODULE;
mtd->dev.parent = &ofdev->dev;
ppdata.of_node = ofdev->dev.of_node;
nand_chip->IO_ADDR_R = (void *)0xdeadbeef;
nand_chip->IO_ADDR_W = (void *)0xdeadbeef;
nand_chip->cmd_ctrl = socrates_nand_cmd_ctrl;
nand_chip->read_byte = socrates_nand_read_byte;
nand_chip->read_word = socrates_nand_read_word;
nand_chip->write_buf = socrates_nand_write_buf;
nand_chip->read_buf = socrates_nand_read_buf;
nand_chip->verify_buf = socrates_nand_verify_buf;
nand_chip->dev_ready = socrates_nand_device_ready;
nand_chip->ecc.mode = NAND_ECC_SOFT;
nand_chip->chip_delay = 20;
dev_set_drvdata(&ofdev->dev, host);
if (nand_scan_ident(mtd, 1, NULL)) {
res = -ENXIO;
goto out;
}
if (nand_scan_tail(mtd)) {
res = -ENXIO;
goto out;
}
res = mtd_device_parse_register(mtd, NULL, &ppdata, NULL, 0);
if (!res)
return res;
nand_release(mtd);
out:
dev_set_drvdata(&ofdev->dev, NULL);
iounmap(host->io_base);
kfree(host);
return res;
}
static int __devexit socrates_nand_remove(struct platform_device *ofdev)
{
struct socrates_nand_host *host = dev_get_drvdata(&ofdev->dev);
struct mtd_info *mtd = &host->mtd;
nand_release(mtd);
dev_set_drvdata(&ofdev->dev, NULL);
iounmap(host->io_base);
kfree(host);
return 0;
}
