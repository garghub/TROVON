static int cpu_has_dma(void)
{
return cpu_is_at91sam9rl() || cpu_is_at91sam9g45();
}
static void atmel_nand_enable(struct atmel_nand_host *host)
{
if (gpio_is_valid(host->board.enable_pin))
gpio_set_value(host->board.enable_pin, 0);
}
static void atmel_nand_disable(struct atmel_nand_host *host)
{
if (gpio_is_valid(host->board.enable_pin))
gpio_set_value(host->board.enable_pin, 1);
}
static void atmel_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_NCE)
atmel_nand_enable(host);
else
atmel_nand_disable(host);
}
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, host->io_base + (1 << host->board.cle));
else
writeb(cmd, host->io_base + (1 << host->board.ale));
}
static int atmel_nand_device_ready(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
return gpio_get_value(host->board.rdy_pin) ^
!!host->board.rdy_pin_active_low;
}
static void atmel_read_buf8(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_readsb(nand_chip->IO_ADDR_R, buf, len);
}
static void atmel_read_buf16(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_readsw(nand_chip->IO_ADDR_R, buf, len / 2);
}
static void atmel_write_buf8(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_writesb(nand_chip->IO_ADDR_W, buf, len);
}
static void atmel_write_buf16(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
__raw_writesw(nand_chip->IO_ADDR_W, buf, len / 2);
}
static void dma_complete_func(void *completion)
{
complete(completion);
}
static int atmel_nand_dma_op(struct mtd_info *mtd, void *buf, int len,
int is_read)
{
struct dma_device *dma_dev;
enum dma_ctrl_flags flags;
dma_addr_t dma_src_addr, dma_dst_addr, phys_addr;
struct dma_async_tx_descriptor *tx = NULL;
dma_cookie_t cookie;
struct nand_chip *chip = mtd->priv;
struct atmel_nand_host *host = chip->priv;
void *p = buf;
int err = -EIO;
enum dma_data_direction dir = is_read ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
if (buf >= high_memory)
goto err_buf;
dma_dev = host->dma_chan->device;
flags = DMA_CTRL_ACK | DMA_PREP_INTERRUPT | DMA_COMPL_SKIP_SRC_UNMAP |
DMA_COMPL_SKIP_DEST_UNMAP;
phys_addr = dma_map_single(dma_dev->dev, p, len, dir);
if (dma_mapping_error(dma_dev->dev, phys_addr)) {
dev_err(host->dev, "Failed to dma_map_single\n");
goto err_buf;
}
if (is_read) {
dma_src_addr = host->io_phys;
dma_dst_addr = phys_addr;
} else {
dma_src_addr = phys_addr;
dma_dst_addr = host->io_phys;
}
tx = dma_dev->device_prep_dma_memcpy(host->dma_chan, dma_dst_addr,
dma_src_addr, len, flags);
if (!tx) {
dev_err(host->dev, "Failed to prepare DMA memcpy\n");
goto err_dma;
}
init_completion(&host->comp);
tx->callback = dma_complete_func;
tx->callback_param = &host->comp;
cookie = tx->tx_submit(tx);
if (dma_submit_error(cookie)) {
dev_err(host->dev, "Failed to do DMA tx_submit\n");
goto err_dma;
}
dma_async_issue_pending(host->dma_chan);
wait_for_completion(&host->comp);
err = 0;
err_dma:
dma_unmap_single(dma_dev->dev, phys_addr, len, dir);
err_buf:
if (err != 0)
dev_warn(host->dev, "Fall back to CPU I/O\n");
return err;
}
static void atmel_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct atmel_nand_host *host = chip->priv;
if (use_dma && len > mtd->oobsize)
if (atmel_nand_dma_op(mtd, buf, len, 1) == 0)
return;
if (host->board.bus_width_16)
atmel_read_buf16(mtd, buf, len);
else
atmel_read_buf8(mtd, buf, len);
}
static void atmel_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct atmel_nand_host *host = chip->priv;
if (use_dma && len > mtd->oobsize)
if (atmel_nand_dma_op(mtd, (void *)buf, len, 0) == 0)
return;
if (host->board.bus_width_16)
atmel_write_buf16(mtd, buf, len);
else
atmel_write_buf8(mtd, buf, len);
}
static int atmel_nand_calculate(struct mtd_info *mtd,
const u_char *dat, unsigned char *ecc_code)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
unsigned int ecc_value;
ecc_value = ecc_readl(host->ecc, PR);
ecc_code[0] = ecc_value & 0xFF;
ecc_code[1] = (ecc_value >> 8) & 0xFF;
ecc_value = ecc_readl(host->ecc, NPR) & ATMEL_ECC_NPARITY;
ecc_code[2] = ecc_value & 0xFF;
ecc_code[3] = (ecc_value >> 8) & 0xFF;
return 0;
}
static int atmel_nand_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
int eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
uint32_t *eccpos = chip->ecc.layout->eccpos;
uint8_t *p = buf;
uint8_t *oob = chip->oob_poi;
uint8_t *ecc_pos;
int stat;
unsigned int max_bitflips = 0;
if (cpu_is_at32ap7000()) {
struct atmel_nand_host *host = chip->priv;
ecc_writel(host->ecc, CR, ATMEL_ECC_RST);
}
chip->read_buf(mtd, p, eccsize);
if (eccpos[0] != 0) {
chip->cmdfunc(mtd, NAND_CMD_RNDOUT,
mtd->writesize + eccpos[0], -1);
}
ecc_pos = oob + eccpos[0];
chip->read_buf(mtd, ecc_pos, eccbytes);
stat = chip->ecc.correct(mtd, p, oob, NULL);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize, -1);
chip->read_buf(mtd, oob, mtd->oobsize);
return max_bitflips;
}
static int atmel_nand_correct(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *isnull)
{
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
unsigned int ecc_status;
unsigned int ecc_word, ecc_bit;
ecc_status = ecc_readl(host->ecc, SR);
if (likely(!(ecc_status & ATMEL_ECC_RECERR)))
return 0;
ecc_bit = ecc_readl(host->ecc, PR) & ATMEL_ECC_BITADDR;
ecc_word = ecc_readl(host->ecc, PR) & ATMEL_ECC_WORDADDR;
ecc_word >>= 4;
if (ecc_status & ATMEL_ECC_MULERR) {
if ((ecc_bit == ATMEL_ECC_BITADDR)
&& (ecc_word == (ATMEL_ECC_WORDADDR >> 4))) {
return 0;
}
dev_dbg(host->dev, "atmel_nand : multiple errors detected."
" Unable to correct.\n");
return -EIO;
}
if (ecc_status & ATMEL_ECC_ECCERR) {
dev_dbg(host->dev, "atmel_nand : one bit error on ECC code."
" Nothing to correct\n");
return 0;
}
dev_dbg(host->dev, "atmel_nand : one bit error on data."
" (word offset in the page :"
" 0x%x bit offset : 0x%x)\n",
ecc_word, ecc_bit);
if (nand_chip->options & NAND_BUSWIDTH_16) {
((unsigned short *) dat)[ecc_word] ^= (1 << ecc_bit);
} else {
dat[ecc_word] ^= (1 << ecc_bit);
}
dev_dbg(host->dev, "atmel_nand : error corrected\n");
return 1;
}
static void atmel_nand_hwctl(struct mtd_info *mtd, int mode)
{
if (cpu_is_at32ap7000()) {
struct nand_chip *nand_chip = mtd->priv;
struct atmel_nand_host *host = nand_chip->priv;
ecc_writel(host->ecc, CR, ATMEL_ECC_RST);
}
}
static int __devinit atmel_of_init_port(struct atmel_nand_host *host,
struct device_node *np)
{
u32 val;
int ecc_mode;
struct atmel_nand_data *board = &host->board;
enum of_gpio_flags flags;
if (of_property_read_u32(np, "atmel,nand-addr-offset", &val) == 0) {
if (val >= 32) {
dev_err(host->dev, "invalid addr-offset %u\n", val);
return -EINVAL;
}
board->ale = val;
}
if (of_property_read_u32(np, "atmel,nand-cmd-offset", &val) == 0) {
if (val >= 32) {
dev_err(host->dev, "invalid cmd-offset %u\n", val);
return -EINVAL;
}
board->cle = val;
}
ecc_mode = of_get_nand_ecc_mode(np);
board->ecc_mode = ecc_mode < 0 ? NAND_ECC_SOFT : ecc_mode;
board->on_flash_bbt = of_get_nand_on_flash_bbt(np);
if (of_get_nand_bus_width(np) == 16)
board->bus_width_16 = 1;
board->rdy_pin = of_get_gpio_flags(np, 0, &flags);
board->rdy_pin_active_low = (flags == OF_GPIO_ACTIVE_LOW);
board->enable_pin = of_get_gpio(np, 1);
board->det_pin = of_get_gpio(np, 2);
return 0;
}
static int __devinit atmel_of_init_port(struct atmel_nand_host *host,
struct device_node *np)
{
return -EINVAL;
}
static int __init atmel_nand_probe(struct platform_device *pdev)
{
struct atmel_nand_host *host;
struct mtd_info *mtd;
struct nand_chip *nand_chip;
struct resource *regs;
struct resource *mem;
struct mtd_part_parser_data ppdata = {};
int res;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
printk(KERN_ERR "atmel_nand: can't get I/O resource mem\n");
return -ENXIO;
}
host = kzalloc(sizeof(struct atmel_nand_host), GFP_KERNEL);
if (!host) {
printk(KERN_ERR "atmel_nand: failed to allocate device structure.\n");
return -ENOMEM;
}
host->io_phys = (dma_addr_t)mem->start;
host->io_base = ioremap(mem->start, resource_size(mem));
if (host->io_base == NULL) {
printk(KERN_ERR "atmel_nand: ioremap failed\n");
res = -EIO;
goto err_nand_ioremap;
}
mtd = &host->mtd;
nand_chip = &host->nand_chip;
host->dev = &pdev->dev;
if (pdev->dev.of_node) {
res = atmel_of_init_port(host, pdev->dev.of_node);
if (res)
goto err_nand_ioremap;
} else {
memcpy(&host->board, pdev->dev.platform_data,
sizeof(struct atmel_nand_data));
}
nand_chip->priv = host;
mtd->priv = nand_chip;
mtd->owner = THIS_MODULE;
nand_chip->IO_ADDR_R = host->io_base;
nand_chip->IO_ADDR_W = host->io_base;
nand_chip->cmd_ctrl = atmel_nand_cmd_ctrl;
if (gpio_is_valid(host->board.rdy_pin))
nand_chip->dev_ready = atmel_nand_device_ready;
nand_chip->ecc.mode = host->board.ecc_mode;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!regs && nand_chip->ecc.mode == NAND_ECC_HW) {
printk(KERN_ERR "atmel_nand: can't get I/O resource "
"regs\nFalling back on software ECC\n");
nand_chip->ecc.mode = NAND_ECC_SOFT;
}
if (nand_chip->ecc.mode == NAND_ECC_HW) {
host->ecc = ioremap(regs->start, resource_size(regs));
if (host->ecc == NULL) {
printk(KERN_ERR "atmel_nand: ioremap failed\n");
res = -EIO;
goto err_ecc_ioremap;
}
nand_chip->ecc.calculate = atmel_nand_calculate;
nand_chip->ecc.correct = atmel_nand_correct;
nand_chip->ecc.hwctl = atmel_nand_hwctl;
nand_chip->ecc.read_page = atmel_nand_read_page;
nand_chip->ecc.bytes = 4;
nand_chip->ecc.strength = 1;
}
nand_chip->chip_delay = 20;
if (host->board.bus_width_16)
nand_chip->options |= NAND_BUSWIDTH_16;
nand_chip->read_buf = atmel_read_buf;
nand_chip->write_buf = atmel_write_buf;
platform_set_drvdata(pdev, host);
atmel_nand_enable(host);
if (gpio_is_valid(host->board.det_pin)) {
if (gpio_get_value(host->board.det_pin)) {
printk(KERN_INFO "No SmartMedia card inserted.\n");
res = -ENXIO;
goto err_no_card;
}
}
if (host->board.on_flash_bbt || on_flash_bbt) {
printk(KERN_INFO "atmel_nand: Use On Flash BBT\n");
nand_chip->bbt_options |= NAND_BBT_USE_FLASH;
}
if (!cpu_has_dma())
use_dma = 0;
if (use_dma) {
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_MEMCPY, mask);
host->dma_chan = dma_request_channel(mask, NULL, NULL);
if (!host->dma_chan) {
dev_err(host->dev, "Failed to request DMA channel\n");
use_dma = 0;
}
}
if (use_dma)
dev_info(host->dev, "Using %s for DMA transfers.\n",
dma_chan_name(host->dma_chan));
else
dev_info(host->dev, "No DMA support for NAND access.\n");
if (nand_scan_ident(mtd, 1, NULL)) {
res = -ENXIO;
goto err_scan_ident;
}
if (nand_chip->ecc.mode == NAND_ECC_HW) {
nand_chip->ecc.size = mtd->writesize;
switch (mtd->writesize) {
case 512:
nand_chip->ecc.layout = &atmel_oobinfo_small;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_528);
break;
case 1024:
nand_chip->ecc.layout = &atmel_oobinfo_large;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_1056);
break;
case 2048:
nand_chip->ecc.layout = &atmel_oobinfo_large;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_2112);
break;
case 4096:
nand_chip->ecc.layout = &atmel_oobinfo_large;
ecc_writel(host->ecc, MR, ATMEL_ECC_PAGESIZE_4224);
break;
default:
nand_chip->ecc.mode = NAND_ECC_SOFT;
nand_chip->ecc.calculate = NULL;
nand_chip->ecc.correct = NULL;
nand_chip->ecc.hwctl = NULL;
nand_chip->ecc.read_page = NULL;
nand_chip->ecc.postpad = 0;
nand_chip->ecc.prepad = 0;
nand_chip->ecc.bytes = 0;
break;
}
}
if (nand_scan_tail(mtd)) {
res = -ENXIO;
goto err_scan_tail;
}
mtd->name = "atmel_nand";
ppdata.of_node = pdev->dev.of_node;
res = mtd_device_parse_register(mtd, NULL, &ppdata,
host->board.parts, host->board.num_parts);
if (!res)
return res;
err_scan_tail:
err_scan_ident:
err_no_card:
atmel_nand_disable(host);
platform_set_drvdata(pdev, NULL);
if (host->dma_chan)
dma_release_channel(host->dma_chan);
if (host->ecc)
iounmap(host->ecc);
err_ecc_ioremap:
iounmap(host->io_base);
err_nand_ioremap:
kfree(host);
return res;
}
static int __exit atmel_nand_remove(struct platform_device *pdev)
{
struct atmel_nand_host *host = platform_get_drvdata(pdev);
struct mtd_info *mtd = &host->mtd;
nand_release(mtd);
atmel_nand_disable(host);
if (host->ecc)
iounmap(host->ecc);
if (host->dma_chan)
dma_release_channel(host->dma_chan);
iounmap(host->io_base);
kfree(host);
return 0;
}
static int __init atmel_nand_init(void)
{
return platform_driver_probe(&atmel_nand_driver, atmel_nand_probe);
}
static void __exit atmel_nand_exit(void)
{
platform_driver_unregister(&atmel_nand_driver);
}
