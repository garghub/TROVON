static void nand_dma_handler(DMA_Device_t dev, int reason, void *userData)
{
complete(&nand_comp);
}
static int nand_dma_init(void)
{
int rc;
rc = dma_set_device_handler(DMA_DEVICE_NAND_MEM_TO_MEM,
nand_dma_handler, NULL);
if (rc != 0) {
printk(KERN_ERR "dma_set_device_handler failed: %d\n", rc);
return rc;
}
virtPtr =
dma_alloc_coherent(NULL, DMA_MAX_BUFLEN, &physPtr, GFP_KERNEL);
if (virtPtr == NULL) {
printk(KERN_ERR "NAND - Failed to allocate memory for DMA buffer\n");
return -ENOMEM;
}
return 0;
}
static void nand_dma_term(void)
{
if (virtPtr != NULL)
dma_free_coherent(NULL, DMA_MAX_BUFLEN, virtPtr, physPtr);
}
static void nand_dma_read(void *buf, int len)
{
int offset = 0;
int tmp_len = 0;
int len_left = len;
DMA_Handle_t hndl;
if (virtPtr == NULL)
panic("nand_dma_read: virtPtr == NULL\n");
if ((void *)physPtr == NULL)
panic("nand_dma_read: physPtr == NULL\n");
hndl = dma_request_channel(DMA_DEVICE_NAND_MEM_TO_MEM);
if (hndl < 0) {
printk(KERN_ERR
"nand_dma_read: unable to allocate dma channel: %d\n",
(int)hndl);
panic("\n");
}
while (len_left > 0) {
if (len_left > DMA_MAX_LEN) {
tmp_len = DMA_MAX_LEN;
len_left -= DMA_MAX_LEN;
} else {
tmp_len = len_left;
len_left = 0;
}
init_completion(&nand_comp);
dma_transfer_mem_to_mem(hndl, REG_NAND_DATA_PADDR,
physPtr + offset, tmp_len);
wait_for_completion(&nand_comp);
offset += tmp_len;
}
dma_free_channel(hndl);
if (buf != NULL)
memcpy(buf, virtPtr, len);
}
static void nand_dma_write(const void *buf, int len)
{
int offset = 0;
int tmp_len = 0;
int len_left = len;
DMA_Handle_t hndl;
if (buf == NULL)
panic("nand_dma_write: buf == NULL\n");
if (virtPtr == NULL)
panic("nand_dma_write: virtPtr == NULL\n");
if ((void *)physPtr == NULL)
panic("nand_dma_write: physPtr == NULL\n");
memcpy(virtPtr, buf, len);
hndl = dma_request_channel(DMA_DEVICE_NAND_MEM_TO_MEM);
if (hndl < 0) {
printk(KERN_ERR
"nand_dma_write: unable to allocate dma channel: %d\n",
(int)hndl);
panic("\n");
}
while (len_left > 0) {
if (len_left > DMA_MAX_LEN) {
tmp_len = DMA_MAX_LEN;
len_left -= DMA_MAX_LEN;
} else {
tmp_len = len_left;
len_left = 0;
}
init_completion(&nand_comp);
dma_transfer_mem_to_mem(hndl, physPtr + offset,
REG_NAND_DATA_PADDR, tmp_len);
wait_for_completion(&nand_comp);
offset += tmp_len;
}
dma_free_channel(hndl);
}
static int nand_dev_ready(struct mtd_info *mtd)
{
return nand_bcm_umi_dev_ready();
}
int bcm_umi_nand_inithw(void)
{
REG_UMI_NAND_TCR &= ~0x7ffff;
REG_UMI_NAND_TCR |= HW_CFG_NAND_TCR;
#if !defined(CONFIG_MTD_NAND_BCM_UMI_HWCS)
REG_UMI_NAND_TCR |= REG_UMI_NAND_TCR_CS_SWCTRL;
#endif
REG_UMI_NAND_RCSR |= REG_UMI_NAND_RCSR_CS_ASSERTED;
REG_UMI_NAND_TCR &= ~REG_UMI_NAND_TCR_WORD16;
REG_UMI_MMD_ICR |= REG_UMI_MMD_ICR_FLASH_WP;
writel(NAND_CMD_RESET, bcm_umi_io_base + REG_NAND_CMD_OFFSET);
nand_bcm_umi_wait_till_ready();
#if NAND_ECC_BCH
nand_bcm_umi_bch_config_ecc(NAND_ECC_NUM_BYTES);
#endif
return 0;
}
static void bcm_umi_nand_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *chip = mtd->priv;
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_CLE) {
chip->IO_ADDR_W = bcm_umi_io_base + REG_NAND_CMD_OFFSET;
goto CMD;
}
if (ctrl & NAND_ALE) {
chip->IO_ADDR_W =
bcm_umi_io_base + REG_NAND_ADDR_OFFSET;
goto CMD;
}
chip->IO_ADDR_W = bcm_umi_io_base + REG_NAND_DATA8_OFFSET;
}
CMD:
if (cmd != NAND_CMD_NONE)
writeb(cmd, chip->IO_ADDR_W);
}
static void bcm_umi_nand_write_buf(struct mtd_info *mtd, const u_char * buf,
int len)
{
if (USE_DIRECT_IO(len)) {
int i;
struct nand_chip *this = mtd->priv;
for (i = 0; i < len; i++)
writeb(buf[i], this->IO_ADDR_W);
}
#if USE_DMA
else
nand_dma_write(buf, len);
#endif
}
static void bcm_umi_nand_read_buf(struct mtd_info *mtd, u_char * buf, int len)
{
if (USE_DIRECT_IO(len)) {
int i;
struct nand_chip *this = mtd->priv;
for (i = 0; i < len; i++)
buf[i] = readb(this->IO_ADDR_R);
}
#if USE_DMA
else
nand_dma_read(buf, len);
#endif
}
static int bcm_umi_nand_verify_buf(struct mtd_info *mtd, const u_char * buf,
int len)
{
struct nand_chip *chip = mtd->priv;
int ret = chip->ecc.read_page(mtd, chip, readbackbuf, 0);
if (ret < 0)
return -EFAULT;
else {
if (memcmp(readbackbuf, buf, len) == 0)
return 0;
return -EFAULT;
}
return 0;
}
static int __devinit bcm_umi_nand_probe(struct platform_device *pdev)
{
struct nand_chip *this;
struct resource *r;
int err = 0;
printk(gBanner);
board_mtd =
kmalloc(sizeof(struct mtd_info) + sizeof(struct nand_chip),
GFP_KERNEL);
if (!board_mtd) {
printk(KERN_WARNING
"Unable to allocate NAND MTD device structure.\n");
return -ENOMEM;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
err = -ENXIO;
goto out_free;
}
bcm_umi_io_base = ioremap(r->start, resource_size(r));
if (!bcm_umi_io_base) {
printk(KERN_ERR "ioremap to access BCM UMI NAND chip failed\n");
err = -EIO;
goto out_free;
}
this = (struct nand_chip *)(&board_mtd[1]);
memset((char *)board_mtd, 0, sizeof(struct mtd_info));
memset((char *)this, 0, sizeof(struct nand_chip));
board_mtd->priv = this;
if (bcm_umi_nand_inithw() < 0) {
printk(KERN_ERR "BCM UMI NAND chip could not be initialized\n");
err = -EIO;
goto out_unmap;
}
this->IO_ADDR_W = bcm_umi_io_base + REG_NAND_DATA8_OFFSET;
this->IO_ADDR_R = bcm_umi_io_base + REG_NAND_DATA8_OFFSET;
this->chip_delay = 0;
this->dev_ready = nand_dev_ready;
this->options = 0;
this->write_buf = bcm_umi_nand_write_buf;
this->read_buf = bcm_umi_nand_read_buf;
this->verify_buf = bcm_umi_nand_verify_buf;
this->cmd_ctrl = bcm_umi_nand_hwcontrol;
this->ecc.mode = NAND_ECC_HW;
this->ecc.size = 512;
this->ecc.bytes = NAND_ECC_NUM_BYTES;
#if NAND_ECC_BCH
this->ecc.read_page = bcm_umi_bch_read_page_hwecc;
this->ecc.write_page = bcm_umi_bch_write_page_hwecc;
#else
this->ecc.correct = nand_correct_data512;
this->ecc.calculate = bcm_umi_hamming_get_hw_ecc;
this->ecc.hwctl = bcm_umi_hamming_enable_hwecc;
#endif
#if USE_DMA
err = nand_dma_init();
if (err != 0)
goto out_unmap;
#endif
err = nand_scan_ident(board_mtd, 1, NULL);
if (err) {
printk(KERN_ERR "nand_scan failed: %d\n", err);
goto out_unmap;
}
switch (board_mtd->writesize) {
case 4096:
this->ecc.layout = &nand_hw_eccoob_4096;
break;
case 2048:
this->ecc.layout = &nand_hw_eccoob_2048;
break;
case 512:
this->ecc.layout = &nand_hw_eccoob_512;
break;
default:
{
printk(KERN_ERR "NAND - Unrecognized pagesize: %d\n",
board_mtd->writesize);
err = -EINVAL;
goto out_unmap;
}
}
#if NAND_ECC_BCH
if (board_mtd->writesize > 512) {
if (this->bbt_options & NAND_BBT_USE_FLASH)
largepage_bbt.options = NAND_BBT_SCAN2NDPAGE;
this->badblock_pattern = &largepage_bbt;
}
this->ecc.strength = 6;
#endif
err = nand_scan_tail(board_mtd);
if (err) {
printk(KERN_ERR "nand_scan failed: %d\n", err);
goto out_unmap;
}
board_mtd->name = "bcm_umi-nand";
mtd_device_parse_register(board_mtd, NULL, NULL, NULL, 0);
return 0;
out_unmap:
iounmap(bcm_umi_io_base);
out_free:
kfree(board_mtd);
return err;
}
static int bcm_umi_nand_remove(struct platform_device *pdev)
{
#if USE_DMA
nand_dma_term();
#endif
nand_release(board_mtd);
iounmap(bcm_umi_io_base);
kfree(board_mtd);
return 0;
}
static int bcm_umi_nand_suspend(struct platform_device *pdev,
pm_message_t state)
{
printk(KERN_ERR "MTD NAND suspend is being called\n");
return 0;
}
static int bcm_umi_nand_resume(struct platform_device *pdev)
{
printk(KERN_ERR "MTD NAND resume is being called\n");
return 0;
}
