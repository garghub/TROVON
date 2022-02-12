static inline unsigned int hinfc_read(struct hinfc_host *host, unsigned int reg)
{
return readl(host->iobase + reg);
}
static inline void hinfc_write(struct hinfc_host *host, unsigned int value,
unsigned int reg)
{
writel(value, host->iobase + reg);
}
static void wait_controller_finished(struct hinfc_host *host)
{
unsigned long timeout = jiffies + HINFC504_NFC_TIMEOUT;
int val;
while (time_before(jiffies, timeout)) {
val = hinfc_read(host, HINFC504_STATUS);
if (host->command == NAND_CMD_ERASE2) {
while (!(val & HINFC504_READY)) {
usleep_range(500, 1000);
val = hinfc_read(host, HINFC504_STATUS);
}
return;
}
if (val & HINFC504_READY)
return;
}
dev_err(host->dev, "Wait NAND controller exec cmd timeout.\n");
}
static void hisi_nfc_dma_transfer(struct hinfc_host *host, int todev)
{
struct mtd_info *mtd = &host->mtd;
struct nand_chip *chip = mtd->priv;
unsigned long val;
int ret;
hinfc_write(host, host->dma_buffer, HINFC504_DMA_ADDR_DATA);
hinfc_write(host, host->dma_oob, HINFC504_DMA_ADDR_OOB);
if (chip->ecc.mode == NAND_ECC_NONE) {
hinfc_write(host, ((mtd->oobsize & HINFC504_DMA_LEN_OOB_MASK)
<< HINFC504_DMA_LEN_OOB_SHIFT), HINFC504_DMA_LEN);
hinfc_write(host, HINFC504_DMA_PARA_DATA_RW_EN
| HINFC504_DMA_PARA_OOB_RW_EN, HINFC504_DMA_PARA);
} else {
if (host->command == NAND_CMD_READOOB)
hinfc_write(host, HINFC504_DMA_PARA_OOB_RW_EN
| HINFC504_DMA_PARA_OOB_EDC_EN
| HINFC504_DMA_PARA_OOB_ECC_EN, HINFC504_DMA_PARA);
else
hinfc_write(host, HINFC504_DMA_PARA_DATA_RW_EN
| HINFC504_DMA_PARA_OOB_RW_EN
| HINFC504_DMA_PARA_DATA_EDC_EN
| HINFC504_DMA_PARA_OOB_EDC_EN
| HINFC504_DMA_PARA_DATA_ECC_EN
| HINFC504_DMA_PARA_OOB_ECC_EN, HINFC504_DMA_PARA);
}
val = (HINFC504_DMA_CTRL_DMA_START | HINFC504_DMA_CTRL_BURST4_EN
| HINFC504_DMA_CTRL_BURST8_EN | HINFC504_DMA_CTRL_BURST16_EN
| HINFC504_DMA_CTRL_DATA_AREA_EN | HINFC504_DMA_CTRL_OOB_AREA_EN
| ((host->addr_cycle == 4 ? 1 : 0)
<< HINFC504_DMA_CTRL_ADDR_NUM_SHIFT)
| ((host->chipselect & HINFC504_DMA_CTRL_CS_MASK)
<< HINFC504_DMA_CTRL_CS_SHIFT));
if (todev)
val |= HINFC504_DMA_CTRL_WE;
init_completion(&host->cmd_complete);
hinfc_write(host, val, HINFC504_DMA_CTRL);
ret = wait_for_completion_timeout(&host->cmd_complete,
HINFC504_NFC_DMA_TIMEOUT);
if (!ret) {
dev_err(host->dev, "DMA operation(irq) timeout!\n");
val = hinfc_read(host, HINFC504_DMA_CTRL);
if (!(val & HINFC504_DMA_CTRL_DMA_START))
dev_err(host->dev, "DMA is already done but without irq ACK!\n");
else
dev_err(host->dev, "DMA is really timeout!\n");
}
}
static int hisi_nfc_send_cmd_pageprog(struct hinfc_host *host)
{
host->addr_value[0] &= 0xffff0000;
hinfc_write(host, host->addr_value[0], HINFC504_ADDRL);
hinfc_write(host, host->addr_value[1], HINFC504_ADDRH);
hinfc_write(host, NAND_CMD_PAGEPROG << 8 | NAND_CMD_SEQIN,
HINFC504_CMD);
hisi_nfc_dma_transfer(host, 1);
return 0;
}
static int hisi_nfc_send_cmd_readstart(struct hinfc_host *host)
{
struct mtd_info *mtd = &host->mtd;
if ((host->addr_value[0] == host->cache_addr_value[0]) &&
(host->addr_value[1] == host->cache_addr_value[1]))
return 0;
host->addr_value[0] &= 0xffff0000;
hinfc_write(host, host->addr_value[0], HINFC504_ADDRL);
hinfc_write(host, host->addr_value[1], HINFC504_ADDRH);
hinfc_write(host, NAND_CMD_READSTART << 8 | NAND_CMD_READ0,
HINFC504_CMD);
hinfc_write(host, 0, HINFC504_LOG_READ_ADDR);
hinfc_write(host, mtd->writesize + mtd->oobsize,
HINFC504_LOG_READ_LEN);
hisi_nfc_dma_transfer(host, 0);
host->cache_addr_value[0] = host->addr_value[0];
host->cache_addr_value[1] = host->addr_value[1];
return 0;
}
static int hisi_nfc_send_cmd_erase(struct hinfc_host *host)
{
hinfc_write(host, host->addr_value[0], HINFC504_ADDRL);
hinfc_write(host, (NAND_CMD_ERASE2 << 8) | NAND_CMD_ERASE1,
HINFC504_CMD);
hinfc_write(host, HINFC504_OP_WAIT_READY_EN
| HINFC504_OP_CMD2_EN
| HINFC504_OP_CMD1_EN
| HINFC504_OP_ADDR_EN
| ((host->chipselect & HINFC504_OP_NF_CS_MASK)
<< HINFC504_OP_NF_CS_SHIFT)
| ((host->addr_cycle & HINFC504_OP_ADDR_CYCLE_MASK)
<< HINFC504_OP_ADDR_CYCLE_SHIFT),
HINFC504_OP);
wait_controller_finished(host);
return 0;
}
static int hisi_nfc_send_cmd_readid(struct hinfc_host *host)
{
hinfc_write(host, HINFC504_NANDINFO_LEN, HINFC504_DATA_NUM);
hinfc_write(host, NAND_CMD_READID, HINFC504_CMD);
hinfc_write(host, 0, HINFC504_ADDRL);
hinfc_write(host, HINFC504_OP_CMD1_EN | HINFC504_OP_ADDR_EN
| HINFC504_OP_READ_DATA_EN
| ((host->chipselect & HINFC504_OP_NF_CS_MASK)
<< HINFC504_OP_NF_CS_SHIFT)
| 1 << HINFC504_OP_ADDR_CYCLE_SHIFT, HINFC504_OP);
wait_controller_finished(host);
return 0;
}
static int hisi_nfc_send_cmd_status(struct hinfc_host *host)
{
hinfc_write(host, HINFC504_NANDINFO_LEN, HINFC504_DATA_NUM);
hinfc_write(host, NAND_CMD_STATUS, HINFC504_CMD);
hinfc_write(host, HINFC504_OP_CMD1_EN
| HINFC504_OP_READ_DATA_EN
| ((host->chipselect & HINFC504_OP_NF_CS_MASK)
<< HINFC504_OP_NF_CS_SHIFT),
HINFC504_OP);
wait_controller_finished(host);
return 0;
}
static int hisi_nfc_send_cmd_reset(struct hinfc_host *host, int chipselect)
{
hinfc_write(host, NAND_CMD_RESET, HINFC504_CMD);
hinfc_write(host, HINFC504_OP_CMD1_EN
| ((chipselect & HINFC504_OP_NF_CS_MASK)
<< HINFC504_OP_NF_CS_SHIFT)
| HINFC504_OP_WAIT_READY_EN,
HINFC504_OP);
wait_controller_finished(host);
return 0;
}
static void hisi_nfc_select_chip(struct mtd_info *mtd, int chipselect)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
if (chipselect < 0)
return;
host->chipselect = chipselect;
}
static uint8_t hisi_nfc_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
if (host->command == NAND_CMD_STATUS)
return *(uint8_t *)(host->mmio);
host->offset++;
if (host->command == NAND_CMD_READID)
return *(uint8_t *)(host->mmio + host->offset - 1);
return *(uint8_t *)(host->buffer + host->offset - 1);
}
static u16 hisi_nfc_read_word(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
host->offset += 2;
return *(u16 *)(host->buffer + host->offset - 2);
}
static void
hisi_nfc_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
memcpy(host->buffer + host->offset, buf, len);
host->offset += len;
}
static void hisi_nfc_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
memcpy(buf, host->buffer + host->offset, len);
host->offset += len;
}
static void set_addr(struct mtd_info *mtd, int column, int page_addr)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
unsigned int command = host->command;
host->addr_cycle = 0;
host->addr_value[0] = 0;
host->addr_value[1] = 0;
if (column != -1) {
if (chip->options & NAND_BUSWIDTH_16 &&
!nand_opcode_8bits(command))
column >>= 1;
host->addr_value[0] = column & 0xffff;
host->addr_cycle = 2;
}
if (page_addr != -1) {
host->addr_value[0] |= (page_addr & 0xffff)
<< (host->addr_cycle * 8);
host->addr_cycle += 2;
if (chip->chipsize > (128 << 20)) {
host->addr_cycle += 1;
if (host->command == NAND_CMD_ERASE1)
host->addr_value[0] |= ((page_addr >> 16) & 0xff) << 16;
else
host->addr_value[1] |= ((page_addr >> 16) & 0xff);
}
}
}
static void hisi_nfc_cmdfunc(struct mtd_info *mtd, unsigned command, int column,
int page_addr)
{
struct nand_chip *chip = mtd->priv;
struct hinfc_host *host = chip->priv;
int is_cache_invalid = 1;
unsigned int flag = 0;
host->command = command;
switch (command) {
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
if (command == NAND_CMD_READ0)
host->offset = column;
else
host->offset = column + mtd->writesize;
is_cache_invalid = 0;
set_addr(mtd, column, page_addr);
hisi_nfc_send_cmd_readstart(host);
break;
case NAND_CMD_SEQIN:
host->offset = column;
set_addr(mtd, column, page_addr);
break;
case NAND_CMD_ERASE1:
set_addr(mtd, column, page_addr);
break;
case NAND_CMD_PAGEPROG:
hisi_nfc_send_cmd_pageprog(host);
break;
case NAND_CMD_ERASE2:
hisi_nfc_send_cmd_erase(host);
break;
case NAND_CMD_READID:
host->offset = column;
memset(host->mmio, 0, 0x10);
hisi_nfc_send_cmd_readid(host);
break;
case NAND_CMD_STATUS:
flag = hinfc_read(host, HINFC504_CON);
if (chip->ecc.mode == NAND_ECC_HW)
hinfc_write(host,
flag & ~(HINFC504_CON_ECCTYPE_MASK <<
HINFC504_CON_ECCTYPE_SHIFT), HINFC504_CON);
host->offset = 0;
memset(host->mmio, 0, 0x10);
hisi_nfc_send_cmd_status(host);
hinfc_write(host, flag, HINFC504_CON);
break;
case NAND_CMD_RESET:
hisi_nfc_send_cmd_reset(host, host->chipselect);
break;
default:
dev_err(host->dev, "Error: unsupported cmd(cmd=%x, col=%x, page=%x)\n",
command, column, page_addr);
}
if (is_cache_invalid) {
host->cache_addr_value[0] = ~0;
host->cache_addr_value[1] = ~0;
}
}
static irqreturn_t hinfc_irq_handle(int irq, void *devid)
{
struct hinfc_host *host = devid;
unsigned int flag;
flag = hinfc_read(host, HINFC504_INTS);
host->irq_status |= flag;
if (flag & HINFC504_INTS_DMA) {
hinfc_write(host, HINFC504_INTCLR_DMA, HINFC504_INTCLR);
complete(&host->cmd_complete);
} else if (flag & HINFC504_INTS_CE) {
hinfc_write(host, HINFC504_INTCLR_CE, HINFC504_INTCLR);
} else if (flag & HINFC504_INTS_UE) {
hinfc_write(host, HINFC504_INTCLR_UE, HINFC504_INTCLR);
}
return IRQ_HANDLED;
}
static int hisi_nand_read_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf, int oob_required, int page)
{
struct hinfc_host *host = chip->priv;
int max_bitflips = 0, stat = 0, stat_max = 0, status_ecc;
int stat_1, stat_2;
chip->read_buf(mtd, buf, mtd->writesize);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
if (host->irq_status & HINFC504_INTS_UE) {
mtd->ecc_stats.failed++;
} else if (host->irq_status & HINFC504_INTS_CE) {
switch (chip->ecc.strength) {
case 16:
status_ecc = hinfc_read(host, HINFC504_ECC_STATUS) >>
HINFC504_ECC_16_BIT_SHIFT & 0x0fff;
stat_2 = status_ecc & 0x3f;
stat_1 = status_ecc >> 6 & 0x3f;
stat = stat_1 + stat_2;
stat_max = max_t(int, stat_1, stat_2);
}
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(int, max_bitflips, stat_max);
}
host->irq_status = 0;
return max_bitflips;
}
static int hisi_nand_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
struct hinfc_host *host = chip->priv;
chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
if (host->irq_status & HINFC504_INTS_UE) {
host->irq_status = 0;
return -EBADMSG;
}
host->irq_status = 0;
return 0;
}
static int hisi_nand_write_page_hwecc(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf, int oob_required,
int page)
{
chip->write_buf(mtd, buf, mtd->writesize);
if (oob_required)
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static void hisi_nfc_host_init(struct hinfc_host *host)
{
struct nand_chip *chip = &host->chip;
unsigned int flag = 0;
host->version = hinfc_read(host, HINFC_VERSION);
host->addr_cycle = 0;
host->addr_value[0] = 0;
host->addr_value[1] = 0;
host->cache_addr_value[0] = ~0;
host->cache_addr_value[1] = ~0;
host->chipselect = 0;
flag = HINFC504_CON_OP_MODE_NORMAL | HINFC504_CON_READY_BUSY_SEL
| ((0x001 & HINFC504_CON_PAGESIZE_MASK)
<< HINFC504_CON_PAGEISZE_SHIFT)
| ((0x0 & HINFC504_CON_ECCTYPE_MASK)
<< HINFC504_CON_ECCTYPE_SHIFT)
| ((chip->options & NAND_BUSWIDTH_16) ?
HINFC504_CON_BUS_WIDTH : 0);
hinfc_write(host, flag, HINFC504_CON);
memset(host->mmio, 0xff, HINFC504_BUFFER_BASE_ADDRESS_LEN);
hinfc_write(host, SET_HINFC504_PWIDTH(HINFC504_W_LATCH,
HINFC504_R_LATCH, HINFC504_RW_LATCH), HINFC504_PWIDTH);
hinfc_write(host, HINFC504_INTEN_DMA, HINFC504_INTEN);
}
static int hisi_nfc_ecc_probe(struct hinfc_host *host)
{
unsigned int flag;
int size, strength, ecc_bits;
struct device *dev = host->dev;
struct nand_chip *chip = &host->chip;
struct mtd_info *mtd = &host->mtd;
struct device_node *np = host->dev->of_node;
size = of_get_nand_ecc_step_size(np);
strength = of_get_nand_ecc_strength(np);
if (size != 1024) {
dev_err(dev, "error ecc size: %d\n", size);
return -EINVAL;
}
if ((size == 1024) && ((strength != 8) && (strength != 16) &&
(strength != 24) && (strength != 40))) {
dev_err(dev, "ecc size and strength do not match\n");
return -EINVAL;
}
chip->ecc.size = size;
chip->ecc.strength = strength;
chip->ecc.read_page = hisi_nand_read_page_hwecc;
chip->ecc.read_oob = hisi_nand_read_oob;
chip->ecc.write_page = hisi_nand_write_page_hwecc;
switch (chip->ecc.strength) {
case 16:
ecc_bits = 6;
if (mtd->writesize == 2048)
chip->ecc.layout = &nand_ecc_2K_16bits;
break;
default:
dev_err(dev, "not support strength: %d\n", chip->ecc.strength);
return -EINVAL;
}
flag = hinfc_read(host, HINFC504_CON);
flag |= ((ecc_bits & HINFC504_CON_ECCTYPE_MASK)
<< HINFC504_CON_ECCTYPE_SHIFT);
hinfc_write(host, flag, HINFC504_CON);
flag = hinfc_read(host, HINFC504_INTEN) & 0xfff;
hinfc_write(host, flag | HINFC504_INTEN_UE | HINFC504_INTEN_CE,
HINFC504_INTEN);
return 0;
}
static int hisi_nfc_probe(struct platform_device *pdev)
{
int ret = 0, irq, buswidth, flag, max_chips = HINFC504_MAX_CHIP;
struct device *dev = &pdev->dev;
struct hinfc_host *host;
struct nand_chip *chip;
struct mtd_info *mtd;
struct resource *res;
struct device_node *np = dev->of_node;
struct mtd_part_parser_data ppdata;
host = devm_kzalloc(dev, sizeof(*host), GFP_KERNEL);
if (!host)
return -ENOMEM;
host->dev = dev;
platform_set_drvdata(pdev, host);
chip = &host->chip;
mtd = &host->mtd;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "no IRQ resource defined\n");
ret = -ENXIO;
goto err_res;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->iobase = devm_ioremap_resource(dev, res);
if (IS_ERR(host->iobase)) {
ret = PTR_ERR(host->iobase);
goto err_res;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
host->mmio = devm_ioremap_resource(dev, res);
if (IS_ERR(host->mmio)) {
ret = PTR_ERR(host->mmio);
dev_err(dev, "devm_ioremap_resource[1] fail\n");
goto err_res;
}
mtd->priv = chip;
mtd->name = "hisi_nand";
mtd->dev.parent = &pdev->dev;
chip->priv = host;
chip->cmdfunc = hisi_nfc_cmdfunc;
chip->select_chip = hisi_nfc_select_chip;
chip->read_byte = hisi_nfc_read_byte;
chip->read_word = hisi_nfc_read_word;
chip->write_buf = hisi_nfc_write_buf;
chip->read_buf = hisi_nfc_read_buf;
chip->chip_delay = HINFC504_CHIP_DELAY;
chip->ecc.mode = of_get_nand_ecc_mode(np);
buswidth = of_get_nand_bus_width(np);
if (buswidth == 16)
chip->options |= NAND_BUSWIDTH_16;
hisi_nfc_host_init(host);
ret = devm_request_irq(dev, irq, hinfc_irq_handle, 0x0, "nandc", host);
if (ret) {
dev_err(dev, "failed to request IRQ\n");
goto err_res;
}
ret = nand_scan_ident(mtd, max_chips, NULL);
if (ret) {
ret = -ENODEV;
goto err_res;
}
host->buffer = dmam_alloc_coherent(dev, mtd->writesize + mtd->oobsize,
&host->dma_buffer, GFP_KERNEL);
if (!host->buffer) {
ret = -ENOMEM;
goto err_res;
}
host->dma_oob = host->dma_buffer + mtd->writesize;
memset(host->buffer, 0xff, mtd->writesize + mtd->oobsize);
flag = hinfc_read(host, HINFC504_CON);
flag &= ~(HINFC504_CON_PAGESIZE_MASK << HINFC504_CON_PAGEISZE_SHIFT);
switch (mtd->writesize) {
case 2048:
flag |= (0x001 << HINFC504_CON_PAGEISZE_SHIFT); break;
default:
dev_err(dev, "NON-2KB page size nand flash\n");
ret = -EINVAL;
goto err_res;
}
hinfc_write(host, flag, HINFC504_CON);
if (chip->ecc.mode == NAND_ECC_HW)
hisi_nfc_ecc_probe(host);
ret = nand_scan_tail(mtd);
if (ret) {
dev_err(dev, "nand_scan_tail failed: %d\n", ret);
goto err_res;
}
ppdata.of_node = np;
ret = mtd_device_parse_register(mtd, NULL, &ppdata, NULL, 0);
if (ret) {
dev_err(dev, "Err MTD partition=%d\n", ret);
goto err_mtd;
}
return 0;
err_mtd:
nand_release(mtd);
err_res:
return ret;
}
static int hisi_nfc_remove(struct platform_device *pdev)
{
struct hinfc_host *host = platform_get_drvdata(pdev);
struct mtd_info *mtd = &host->mtd;
nand_release(mtd);
return 0;
}
static int hisi_nfc_suspend(struct device *dev)
{
struct hinfc_host *host = dev_get_drvdata(dev);
unsigned long timeout = jiffies + HINFC504_NFC_PM_TIMEOUT;
while (time_before(jiffies, timeout)) {
if (((hinfc_read(host, HINFC504_STATUS) & 0x1) == 0x0) &&
(hinfc_read(host, HINFC504_DMA_CTRL) &
HINFC504_DMA_CTRL_DMA_START)) {
cond_resched();
return 0;
}
}
dev_err(host->dev, "nand controller suspend timeout.\n");
return -EAGAIN;
}
static int hisi_nfc_resume(struct device *dev)
{
int cs;
struct hinfc_host *host = dev_get_drvdata(dev);
struct nand_chip *chip = &host->chip;
for (cs = 0; cs < chip->numchips; cs++)
hisi_nfc_send_cmd_reset(host, cs);
hinfc_write(host, SET_HINFC504_PWIDTH(HINFC504_W_LATCH,
HINFC504_R_LATCH, HINFC504_RW_LATCH), HINFC504_PWIDTH);
return 0;
}
