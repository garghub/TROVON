static irqreturn_t mxc_nfc_irq(int irq, void *dev_id)
{
struct mxc_nand_host *host = dev_id;
if (!host->check_int(host))
return IRQ_NONE;
host->irq_control(host, 0);
complete(&host->op_completion);
return IRQ_HANDLED;
}
static int check_int_v3(struct mxc_nand_host *host)
{
uint32_t tmp;
tmp = readl(NFC_V3_IPC);
if (!(tmp & NFC_V3_IPC_INT))
return 0;
tmp &= ~NFC_V3_IPC_INT;
writel(tmp, NFC_V3_IPC);
return 1;
}
static int check_int_v1_v2(struct mxc_nand_host *host)
{
uint32_t tmp;
tmp = readw(NFC_V1_V2_CONFIG2);
if (!(tmp & NFC_V1_V2_CONFIG2_INT))
return 0;
if (!cpu_is_mx21())
writew(tmp & ~NFC_V1_V2_CONFIG2_INT, NFC_V1_V2_CONFIG2);
return 1;
}
static void irq_control_mx21(struct mxc_nand_host *host, int activate)
{
if (activate)
enable_irq(host->irq);
else
disable_irq_nosync(host->irq);
}
static void irq_control_v1_v2(struct mxc_nand_host *host, int activate)
{
uint16_t tmp;
tmp = readw(NFC_V1_V2_CONFIG1);
if (activate)
tmp &= ~NFC_V1_V2_CONFIG1_INT_MSK;
else
tmp |= NFC_V1_V2_CONFIG1_INT_MSK;
writew(tmp, NFC_V1_V2_CONFIG1);
}
static void irq_control_v3(struct mxc_nand_host *host, int activate)
{
uint32_t tmp;
tmp = readl(NFC_V3_CONFIG2);
if (activate)
tmp &= ~NFC_V3_CONFIG2_INT_MSK;
else
tmp |= NFC_V3_CONFIG2_INT_MSK;
writel(tmp, NFC_V3_CONFIG2);
}
static void wait_op_done(struct mxc_nand_host *host, int useirq)
{
int max_retries = 8000;
if (useirq) {
if (!host->check_int(host)) {
INIT_COMPLETION(host->op_completion);
host->irq_control(host, 1);
wait_for_completion(&host->op_completion);
}
} else {
while (max_retries-- > 0) {
if (host->check_int(host))
break;
udelay(1);
}
if (max_retries < 0)
pr_debug("%s: INT not set\n", __func__);
}
}
static void send_cmd_v3(struct mxc_nand_host *host, uint16_t cmd, int useirq)
{
writel(cmd, NFC_V3_FLASH_CMD);
writel(NFC_CMD, NFC_V3_LAUNCH);
wait_op_done(host, useirq);
}
static void send_cmd_v1_v2(struct mxc_nand_host *host, uint16_t cmd, int useirq)
{
pr_debug("send_cmd(host, 0x%x, %d)\n", cmd, useirq);
writew(cmd, NFC_V1_V2_FLASH_CMD);
writew(NFC_CMD, NFC_V1_V2_CONFIG2);
if (cpu_is_mx21() && (cmd == NAND_CMD_RESET)) {
int max_retries = 100;
while (max_retries-- > 0) {
if (readw(NFC_V1_V2_CONFIG2) == 0) {
break;
}
udelay(1);
}
if (max_retries < 0)
pr_debug("%s: RESET failed\n", __func__);
} else {
wait_op_done(host, useirq);
}
}
static void send_addr_v3(struct mxc_nand_host *host, uint16_t addr, int islast)
{
writel(addr, NFC_V3_FLASH_ADDR0);
writel(NFC_ADDR, NFC_V3_LAUNCH);
wait_op_done(host, 0);
}
static void send_addr_v1_v2(struct mxc_nand_host *host, uint16_t addr, int islast)
{
pr_debug("send_addr(host, 0x%x %d)\n", addr, islast);
writew(addr, NFC_V1_V2_FLASH_ADDR);
writew(NFC_ADDR, NFC_V1_V2_CONFIG2);
wait_op_done(host, islast);
}
static void send_page_v3(struct mtd_info *mtd, unsigned int ops)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint32_t tmp;
tmp = readl(NFC_V3_CONFIG1);
tmp &= ~(7 << 4);
writel(tmp, NFC_V3_CONFIG1);
writel(ops, NFC_V3_LAUNCH);
wait_op_done(host, false);
}
static void send_page_v1_v2(struct mtd_info *mtd, unsigned int ops)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
int bufs, i;
if (nfc_is_v1() && mtd->writesize > 512)
bufs = 4;
else
bufs = 1;
for (i = 0; i < bufs; i++) {
writew((host->active_cs << 4) | i, NFC_V1_V2_BUF_ADDR);
writew(ops, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
}
}
static void send_read_id_v3(struct mxc_nand_host *host)
{
writel(NFC_ID, NFC_V3_LAUNCH);
wait_op_done(host, true);
memcpy(host->data_buf, host->main_area0, 16);
}
static void send_read_id_v1_v2(struct mxc_nand_host *host)
{
struct nand_chip *this = &host->nand;
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
writew(NFC_ID, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
memcpy(host->data_buf, host->main_area0, 16);
if (this->options & NAND_BUSWIDTH_16) {
host->data_buf[1] = host->data_buf[2];
host->data_buf[2] = host->data_buf[4];
host->data_buf[3] = host->data_buf[6];
host->data_buf[4] = host->data_buf[8];
host->data_buf[5] = host->data_buf[10];
}
}
static uint16_t get_dev_status_v3(struct mxc_nand_host *host)
{
writew(NFC_STATUS, NFC_V3_LAUNCH);
wait_op_done(host, true);
return readl(NFC_V3_CONFIG1) >> 16;
}
static uint16_t get_dev_status_v1_v2(struct mxc_nand_host *host)
{
void __iomem *main_buf = host->main_area0;
uint32_t store;
uint16_t ret;
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
store = readl(main_buf);
writew(NFC_STATUS, NFC_V1_V2_CONFIG2);
wait_op_done(host, true);
ret = readw(main_buf);
writel(store, main_buf);
return ret;
}
static int mxc_nand_dev_ready(struct mtd_info *mtd)
{
return 1;
}
static void mxc_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
}
static int mxc_nand_correct_data_v1(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t ecc_status = readw(NFC_V1_V2_ECC_STATUS_RESULT);
if (((ecc_status & 0x3) == 2) || ((ecc_status >> 2) == 2)) {
pr_debug("MXC_NAND: HWECC uncorrectable 2-bit ECC error\n");
return -1;
}
return 0;
}
static int mxc_nand_correct_data_v2_v3(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
u32 ecc_stat, err;
int no_subpages = 1;
int ret = 0;
u8 ecc_bit_mask, err_limit;
ecc_bit_mask = (host->eccsize == 4) ? 0x7 : 0xf;
err_limit = (host->eccsize == 4) ? 0x4 : 0x8;
no_subpages = mtd->writesize >> 9;
if (nfc_is_v21())
ecc_stat = readl(NFC_V1_V2_ECC_STATUS_RESULT);
else
ecc_stat = readl(NFC_V3_ECC_STATUS_RESULT);
do {
err = ecc_stat & ecc_bit_mask;
if (err > err_limit) {
printk(KERN_WARNING "UnCorrectable RS-ECC Error\n");
return -1;
} else {
ret += err;
}
ecc_stat >>= 4;
} while (--no_subpages);
mtd->ecc_stats.corrected += ret;
pr_debug("%d Symbol Correctable RS-ECC Error\n", ret);
return ret;
}
static int mxc_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
return 0;
}
static u_char mxc_nand_read_byte(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint8_t ret;
if (host->status_request)
return host->get_dev_status(host) & 0xFF;
ret = *(uint8_t *)(host->data_buf + host->buf_start);
host->buf_start++;
return ret;
}
static uint16_t mxc_nand_read_word(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t ret;
ret = *(uint16_t *)(host->data_buf + host->buf_start);
host->buf_start += 2;
return ret;
}
static void mxc_nand_write_buf(struct mtd_info *mtd,
const u_char *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
u16 col = host->buf_start;
int n = mtd->oobsize + mtd->writesize - col;
n = min(n, len);
memcpy(host->data_buf + col, buf, n);
host->buf_start += n;
}
static void mxc_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
u16 col = host->buf_start;
int n = mtd->oobsize + mtd->writesize - col;
n = min(n, len);
memcpy(buf, host->data_buf + col, n);
host->buf_start += n;
}
static int mxc_nand_verify_buf(struct mtd_info *mtd,
const u_char *buf, int len)
{
return -EFAULT;
}
static void mxc_nand_select_chip(struct mtd_info *mtd, int chip)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
if (chip == -1) {
if (host->clk_act) {
clk_disable(host->clk);
host->clk_act = 0;
}
return;
}
if (!host->clk_act) {
clk_enable(host->clk);
host->clk_act = 1;
}
if (nfc_is_v21()) {
host->active_cs = chip;
writew(host->active_cs << 4, NFC_V1_V2_BUF_ADDR);
}
}
static void copy_spare(struct mtd_info *mtd, bool bfrom)
{
struct nand_chip *this = mtd->priv;
struct mxc_nand_host *host = this->priv;
u16 i, j;
u16 n = mtd->writesize >> 9;
u8 *d = host->data_buf + mtd->writesize;
u8 *s = host->spare0;
u16 t = host->spare_len;
j = (mtd->oobsize / n >> 1) << 1;
if (bfrom) {
for (i = 0; i < n - 1; i++)
memcpy(d + i * j, s + i * t, j);
memcpy(d + i * j, s + i * t, mtd->oobsize - i * j);
} else {
for (i = 0; i < n - 1; i++)
memcpy(&s[i * t], &d[i * j], j);
memcpy(&s[i * t], &d[i * j], mtd->oobsize - i * j);
}
}
static void mxc_do_addr_cycle(struct mtd_info *mtd, int column, int page_addr)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
if (column != -1) {
host->send_addr(host, 0, page_addr == -1);
if (mtd->writesize > 512)
host->send_addr(host, 0, false);
}
if (page_addr != -1) {
host->send_addr(host, (page_addr & 0xff), false);
if (mtd->writesize > 512) {
if (mtd->size >= 0x10000000) {
host->send_addr(host, (page_addr >> 8) & 0xff, false);
host->send_addr(host, (page_addr >> 16) & 0xff, true);
} else
host->send_addr(host, (page_addr >> 8) & 0xff, true);
} else {
if (mtd->size >= 0x4000000) {
host->send_addr(host, (page_addr >> 8) & 0xff, false);
host->send_addr(host, (page_addr >> 16) & 0xff, true);
} else
host->send_addr(host, (page_addr >> 8) & 0xff, true);
}
}
}
static int get_eccsize(struct mtd_info *mtd)
{
int oobbytes_per_512 = 0;
oobbytes_per_512 = mtd->oobsize * 512 / mtd->writesize;
if (oobbytes_per_512 < 26)
return 4;
else
return 8;
}
static void preset_v1_v2(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
uint16_t config1 = 0;
if (nand_chip->ecc.mode == NAND_ECC_HW)
config1 |= NFC_V1_V2_CONFIG1_ECC_EN;
if (nfc_is_v21())
config1 |= NFC_V2_CONFIG1_FP_INT;
if (!cpu_is_mx21())
config1 |= NFC_V1_V2_CONFIG1_INT_MSK;
if (nfc_is_v21() && mtd->writesize) {
uint16_t pages_per_block = mtd->erasesize / mtd->writesize;
host->eccsize = get_eccsize(mtd);
if (host->eccsize == 4)
config1 |= NFC_V2_CONFIG1_ECC_MODE_4;
config1 |= NFC_V2_CONFIG1_PPB(ffs(pages_per_block) - 6);
} else {
host->eccsize = 1;
}
writew(config1, NFC_V1_V2_CONFIG1);
writew(0x2, NFC_V1_V2_CONFIG);
if (nfc_is_v21()) {
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR0);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR1);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR2);
writew(0x0, NFC_V21_UNLOCKSTART_BLKADDR3);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR0);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR1);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR2);
writew(0xffff, NFC_V21_UNLOCKEND_BLKADDR3);
} else if (nfc_is_v1()) {
writew(0x0, NFC_V1_UNLOCKSTART_BLKADDR);
writew(0xffff, NFC_V1_UNLOCKEND_BLKADDR);
} else
BUG();
writew(0x4, NFC_V1_V2_WRPROT);
}
static void preset_v3(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct mxc_nand_host *host = chip->priv;
uint32_t config2, config3;
int i, addr_phases;
writel(NFC_V3_CONFIG1_RBA(0), NFC_V3_CONFIG1);
writel(NFC_V3_IPC_CREQ, NFC_V3_IPC);
writel(NFC_V3_WRPROT_BLS_UNLOCK | NFC_V3_WRPROT_UNLOCK,
NFC_V3_WRPROT);
for (i = 0; i < NAND_MAX_CHIPS; i++)
writel(0x0 | (0xffff << 16),
NFC_V3_WRPROT_UNLOCK_BLK_ADD0 + (i << 2));
writel(0, NFC_V3_IPC);
config2 = NFC_V3_CONFIG2_ONE_CYCLE |
NFC_V3_CONFIG2_2CMD_PHASES |
NFC_V3_CONFIG2_SPAS(mtd->oobsize >> 1) |
NFC_V3_CONFIG2_ST_CMD(0x70) |
NFC_V3_CONFIG2_INT_MSK |
NFC_V3_CONFIG2_NUM_ADDR_PHASE0;
if (chip->ecc.mode == NAND_ECC_HW)
config2 |= NFC_V3_CONFIG2_ECC_EN;
addr_phases = fls(chip->pagemask) >> 3;
if (mtd->writesize == 2048) {
config2 |= NFC_V3_CONFIG2_PS_2048;
config2 |= NFC_V3_CONFIG2_NUM_ADDR_PHASE1(addr_phases);
} else if (mtd->writesize == 4096) {
config2 |= NFC_V3_CONFIG2_PS_4096;
config2 |= NFC_V3_CONFIG2_NUM_ADDR_PHASE1(addr_phases);
} else {
config2 |= NFC_V3_CONFIG2_PS_512;
config2 |= NFC_V3_CONFIG2_NUM_ADDR_PHASE1(addr_phases - 1);
}
if (mtd->writesize) {
config2 |= NFC_V3_CONFIG2_PPB(ffs(mtd->erasesize / mtd->writesize) - 6);
host->eccsize = get_eccsize(mtd);
if (host->eccsize == 8)
config2 |= NFC_V3_CONFIG2_ECC_MODE_8;
}
writel(config2, NFC_V3_CONFIG2);
config3 = NFC_V3_CONFIG3_NUM_OF_DEVICES(0) |
NFC_V3_CONFIG3_NO_SDMA |
NFC_V3_CONFIG3_RBB_MODE |
NFC_V3_CONFIG3_SBB(6) |
NFC_V3_CONFIG3_ADD_OP(0);
if (!(chip->options & NAND_BUSWIDTH_16))
config3 |= NFC_V3_CONFIG3_FW8;
writel(config3, NFC_V3_CONFIG3);
writel(0, NFC_V3_DELAY_LINE);
}
static void mxc_nand_command(struct mtd_info *mtd, unsigned command,
int column, int page_addr)
{
struct nand_chip *nand_chip = mtd->priv;
struct mxc_nand_host *host = nand_chip->priv;
pr_debug("mxc_nand_command (cmd = 0x%x, col = 0x%x, page = 0x%x)\n",
command, column, page_addr);
host->status_request = false;
switch (command) {
case NAND_CMD_RESET:
host->preset(mtd);
host->send_cmd(host, command, false);
break;
case NAND_CMD_STATUS:
host->buf_start = 0;
host->status_request = true;
host->send_cmd(host, command, true);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
if (command == NAND_CMD_READ0)
host->buf_start = column;
else
host->buf_start = column + mtd->writesize;
command = NAND_CMD_READ0;
host->send_cmd(host, command, false);
mxc_do_addr_cycle(mtd, column, page_addr);
if (mtd->writesize > 512)
host->send_cmd(host, NAND_CMD_READSTART, true);
host->send_page(mtd, NFC_OUTPUT);
memcpy(host->data_buf, host->main_area0, mtd->writesize);
copy_spare(mtd, true);
break;
case NAND_CMD_SEQIN:
if (column >= mtd->writesize)
mxc_nand_command(mtd, NAND_CMD_READ0, 0, page_addr);
host->buf_start = column;
host->send_cmd(host, command, false);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
case NAND_CMD_PAGEPROG:
memcpy(host->main_area0, host->data_buf, mtd->writesize);
copy_spare(mtd, false);
host->send_page(mtd, NFC_INPUT);
host->send_cmd(host, command, true);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
case NAND_CMD_READID:
host->send_cmd(host, command, true);
mxc_do_addr_cycle(mtd, column, page_addr);
host->send_read_id(host);
host->buf_start = column;
break;
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
host->send_cmd(host, command, false);
mxc_do_addr_cycle(mtd, column, page_addr);
break;
}
}
static int __init mxcnd_probe(struct platform_device *pdev)
{
struct nand_chip *this;
struct mtd_info *mtd;
struct mxc_nand_platform_data *pdata = pdev->dev.platform_data;
struct mxc_nand_host *host;
struct resource *res;
int err = 0;
struct nand_ecclayout *oob_smallpage, *oob_largepage;
host = kzalloc(sizeof(struct mxc_nand_host) + NAND_MAX_PAGESIZE +
NAND_MAX_OOBSIZE, GFP_KERNEL);
if (!host)
return -ENOMEM;
host->data_buf = (uint8_t *)(host + 1);
host->dev = &pdev->dev;
this = &host->nand;
mtd = &host->mtd;
mtd->priv = this;
mtd->owner = THIS_MODULE;
mtd->dev.parent = &pdev->dev;
mtd->name = DRIVER_NAME;
this->chip_delay = 5;
this->priv = host;
this->dev_ready = mxc_nand_dev_ready;
this->cmdfunc = mxc_nand_command;
this->select_chip = mxc_nand_select_chip;
this->read_byte = mxc_nand_read_byte;
this->read_word = mxc_nand_read_word;
this->write_buf = mxc_nand_write_buf;
this->read_buf = mxc_nand_read_buf;
this->verify_buf = mxc_nand_verify_buf;
host->clk = clk_get(&pdev->dev, "nfc");
if (IS_ERR(host->clk)) {
err = PTR_ERR(host->clk);
goto eclk;
}
clk_enable(host->clk);
host->clk_act = 1;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
err = -ENODEV;
goto eres;
}
host->base = ioremap(res->start, resource_size(res));
if (!host->base) {
err = -ENOMEM;
goto eres;
}
host->main_area0 = host->base;
if (nfc_is_v1() || nfc_is_v21()) {
host->preset = preset_v1_v2;
host->send_cmd = send_cmd_v1_v2;
host->send_addr = send_addr_v1_v2;
host->send_page = send_page_v1_v2;
host->send_read_id = send_read_id_v1_v2;
host->get_dev_status = get_dev_status_v1_v2;
host->check_int = check_int_v1_v2;
if (cpu_is_mx21())
host->irq_control = irq_control_mx21;
else
host->irq_control = irq_control_v1_v2;
}
if (nfc_is_v21()) {
host->regs = host->base + 0x1e00;
host->spare0 = host->base + 0x1000;
host->spare_len = 64;
oob_smallpage = &nandv2_hw_eccoob_smallpage;
oob_largepage = &nandv2_hw_eccoob_largepage;
this->ecc.bytes = 9;
} else if (nfc_is_v1()) {
host->regs = host->base + 0xe00;
host->spare0 = host->base + 0x800;
host->spare_len = 16;
oob_smallpage = &nandv1_hw_eccoob_smallpage;
oob_largepage = &nandv1_hw_eccoob_largepage;
this->ecc.bytes = 3;
host->eccsize = 1;
} else if (nfc_is_v3_2()) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
err = -ENODEV;
goto eirq;
}
host->regs_ip = ioremap(res->start, resource_size(res));
if (!host->regs_ip) {
err = -ENOMEM;
goto eirq;
}
host->regs_axi = host->base + 0x1e00;
host->spare0 = host->base + 0x1000;
host->spare_len = 64;
host->preset = preset_v3;
host->send_cmd = send_cmd_v3;
host->send_addr = send_addr_v3;
host->send_page = send_page_v3;
host->send_read_id = send_read_id_v3;
host->check_int = check_int_v3;
host->get_dev_status = get_dev_status_v3;
host->irq_control = irq_control_v3;
oob_smallpage = &nandv2_hw_eccoob_smallpage;
oob_largepage = &nandv2_hw_eccoob_largepage;
} else
BUG();
this->ecc.size = 512;
this->ecc.layout = oob_smallpage;
if (pdata->hw_ecc) {
this->ecc.calculate = mxc_nand_calculate_ecc;
this->ecc.hwctl = mxc_nand_enable_hwecc;
if (nfc_is_v1())
this->ecc.correct = mxc_nand_correct_data_v1;
else
this->ecc.correct = mxc_nand_correct_data_v2_v3;
this->ecc.mode = NAND_ECC_HW;
} else {
this->ecc.mode = NAND_ECC_SOFT;
}
if (pdata->width == 2)
this->options |= NAND_BUSWIDTH_16;
if (pdata->flash_bbt) {
this->bbt_td = &bbt_main_descr;
this->bbt_md = &bbt_mirror_descr;
this->bbt_options |= NAND_BBT_USE_FLASH;
}
init_completion(&host->op_completion);
host->irq = platform_get_irq(pdev, 0);
if (cpu_is_mx21())
irq_control_v1_v2(host, 0);
else
host->irq_control(host, 0);
err = request_irq(host->irq, mxc_nfc_irq, IRQF_DISABLED, DRIVER_NAME, host);
if (err)
goto eirq;
host->irq_control(host, 0);
if (cpu_is_mx21())
irq_control_v1_v2(host, 1);
if (nand_scan_ident(mtd, nfc_is_v21() ? 4 : 1, NULL)) {
err = -ENXIO;
goto escan;
}
host->preset(mtd);
if (mtd->writesize == 2048)
this->ecc.layout = oob_largepage;
if (nfc_is_v21() && mtd->writesize == 4096)
this->ecc.layout = &nandv2_hw_eccoob_4k;
if (nand_scan_tail(mtd)) {
err = -ENXIO;
goto escan;
}
mtd_device_parse_register(mtd, part_probes, 0,
pdata->parts, pdata->nr_parts);
platform_set_drvdata(pdev, host);
return 0;
escan:
free_irq(host->irq, host);
eirq:
if (host->regs_ip)
iounmap(host->regs_ip);
iounmap(host->base);
eres:
clk_put(host->clk);
eclk:
kfree(host);
return err;
}
static int __devexit mxcnd_remove(struct platform_device *pdev)
{
struct mxc_nand_host *host = platform_get_drvdata(pdev);
clk_put(host->clk);
platform_set_drvdata(pdev, NULL);
nand_release(&host->mtd);
free_irq(host->irq, host);
if (host->regs_ip)
iounmap(host->regs_ip);
iounmap(host->base);
kfree(host);
return 0;
}
static int __init mxc_nd_init(void)
{
return platform_driver_probe(&mxcnd_driver, mxcnd_probe);
}
static void __exit mxc_nd_cleanup(void)
{
platform_driver_unregister(&mxcnd_driver);
}
