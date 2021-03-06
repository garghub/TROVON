static void empty_fifo(struct sh_flctl *flctl)
{
writel(flctl->flintdmacr_base | AC1CLR | AC0CLR, FLINTDMACR(flctl));
writel(flctl->flintdmacr_base, FLINTDMACR(flctl));
}
static void start_translation(struct sh_flctl *flctl)
{
writeb(TRSTRT, FLTRCR(flctl));
}
static void timeout_error(struct sh_flctl *flctl, const char *str)
{
dev_err(&flctl->pdev->dev, "Timeout occurred in %s\n", str);
}
static void wait_completion(struct sh_flctl *flctl)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
while (timeout--) {
if (readb(FLTRCR(flctl)) & TREND) {
writeb(0x0, FLTRCR(flctl));
return;
}
udelay(1);
}
timeout_error(flctl, __func__);
writeb(0x0, FLTRCR(flctl));
}
static void set_addr(struct mtd_info *mtd, int column, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint32_t addr = 0;
if (column == -1) {
addr = page_addr;
} else if (page_addr != -1) {
if (flctl->chip.options & NAND_BUSWIDTH_16)
column >>= 1;
if (flctl->page_size) {
addr = column & 0x0FFF;
addr |= (page_addr & 0xff) << 16;
addr |= ((page_addr >> 8) & 0xff) << 24;
if (flctl->rw_ADRCNT == ADRCNT2_E) {
uint32_t addr2;
addr2 = (page_addr >> 16) & 0xff;
writel(addr2, FLADR2(flctl));
}
} else {
addr = column;
addr |= (page_addr & 0xff) << 8;
addr |= ((page_addr >> 8) & 0xff) << 16;
addr |= ((page_addr >> 16) & 0xff) << 24;
}
}
writel(addr, FLADR(flctl));
}
static void wait_rfifo_ready(struct sh_flctl *flctl)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
while (timeout--) {
uint32_t val;
val = readl(FLDTCNTR(flctl)) >> 16;
if (val & 0xFF)
return;
udelay(1);
}
timeout_error(flctl, __func__);
}
static void wait_wfifo_ready(struct sh_flctl *flctl)
{
uint32_t len, timeout = LOOP_TIMEOUT_MAX;
while (timeout--) {
len = (readl(FLDTCNTR(flctl)) >> 16) & 0xFF;
if (len >= 4)
return;
udelay(1);
}
timeout_error(flctl, __func__);
}
static enum flctl_ecc_res_t wait_recfifo_ready
(struct sh_flctl *flctl, int sector_number)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
void __iomem *ecc_reg[4];
int i;
int state = FL_SUCCESS;
uint32_t data, size;
while (timeout--) {
size = readl(FLDTCNTR(flctl)) >> 24;
if ((size & 0xFF) == 4)
return state;
if (!(readl(FL4ECCCR(flctl)) & _4ECCEND)) {
udelay(1);
continue;
}
if (readl(FL4ECCCR(flctl)) & _4ECCFA) {
for (i = 0; i < 512; i++) {
if (flctl->done_buff[i] != 0xff) {
state = FL_ERROR;
break;
}
}
if (state == FL_SUCCESS)
dev_dbg(&flctl->pdev->dev,
"reading empty sector %d, ecc error ignored\n",
sector_number);
writel(0, FL4ECCCR(flctl));
continue;
}
ecc_reg[0] = FL4ECCRESULT0(flctl);
ecc_reg[1] = FL4ECCRESULT1(flctl);
ecc_reg[2] = FL4ECCRESULT2(flctl);
ecc_reg[3] = FL4ECCRESULT3(flctl);
for (i = 0; i < 3; i++) {
uint8_t org;
int index;
data = readl(ecc_reg[i]);
if (flctl->page_size)
index = (512 * sector_number) +
(data >> 16);
else
index = data >> 16;
org = flctl->done_buff[index];
flctl->done_buff[index] = org ^ (data & 0xFF);
}
state = FL_REPAIRABLE;
writel(0, FL4ECCCR(flctl));
}
timeout_error(flctl, __func__);
return FL_TIMEOUT;
}
static void wait_wecfifo_ready(struct sh_flctl *flctl)
{
uint32_t timeout = LOOP_TIMEOUT_MAX;
uint32_t len;
while (timeout--) {
len = (readl(FLDTCNTR(flctl)) >> 24) & 0xFF;
if (len >= 4)
return;
udelay(1);
}
timeout_error(flctl, __func__);
}
static void read_datareg(struct sh_flctl *flctl, int offset)
{
unsigned long data;
unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];
wait_completion(flctl);
data = readl(FLDATAR(flctl));
*buf = le32_to_cpu(data);
}
static void read_fiforeg(struct sh_flctl *flctl, int rlen, int offset)
{
int i, len_4align;
unsigned long *buf = (unsigned long *)&flctl->done_buff[offset];
len_4align = (rlen + 3) / 4;
for (i = 0; i < len_4align; i++) {
wait_rfifo_ready(flctl);
buf[i] = readl(FLDTFIFO(flctl));
buf[i] = be32_to_cpu(buf[i]);
}
}
static enum flctl_ecc_res_t read_ecfiforeg
(struct sh_flctl *flctl, uint8_t *buff, int sector)
{
int i;
enum flctl_ecc_res_t res;
unsigned long *ecc_buf = (unsigned long *)buff;
res = wait_recfifo_ready(flctl , sector);
if (res != FL_ERROR) {
for (i = 0; i < 4; i++) {
ecc_buf[i] = readl(FLECFIFO(flctl));
ecc_buf[i] = be32_to_cpu(ecc_buf[i]);
}
}
return res;
}
static void write_fiforeg(struct sh_flctl *flctl, int rlen, int offset)
{
int i, len_4align;
unsigned long *data = (unsigned long *)&flctl->done_buff[offset];
void *fifo_addr = (void *)FLDTFIFO(flctl);
len_4align = (rlen + 3) / 4;
for (i = 0; i < len_4align; i++) {
wait_wfifo_ready(flctl);
writel(cpu_to_be32(data[i]), fifo_addr);
}
}
static void write_ec_fiforeg(struct sh_flctl *flctl, int rlen, int offset)
{
int i, len_4align;
unsigned long *data = (unsigned long *)&flctl->done_buff[offset];
len_4align = (rlen + 3) / 4;
for (i = 0; i < len_4align; i++) {
wait_wecfifo_ready(flctl);
writel(cpu_to_be32(data[i]), FLECFIFO(flctl));
}
}
static void set_cmd_regs(struct mtd_info *mtd, uint32_t cmd, uint32_t flcmcdr_val)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint32_t flcmncr_val = flctl->flcmncr_base & ~SEL_16BIT;
uint32_t flcmdcr_val, addr_len_bytes = 0;
if (flctl->page_size)
flcmncr_val |= SNAND_E;
else
flcmncr_val &= ~SNAND_E;
flcmdcr_val = DOCMD1_E | DOADR_E;
switch (cmd) {
case NAND_CMD_ERASE1:
addr_len_bytes = flctl->erase_ADRCNT;
flcmdcr_val |= DOCMD2_E;
break;
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
case NAND_CMD_RNDOUT:
addr_len_bytes = flctl->rw_ADRCNT;
flcmdcr_val |= CDSRC_E;
if (flctl->chip.options & NAND_BUSWIDTH_16)
flcmncr_val |= SEL_16BIT;
break;
case NAND_CMD_SEQIN:
flcmdcr_val &= ~DOADR_E;
break;
case NAND_CMD_PAGEPROG:
addr_len_bytes = flctl->rw_ADRCNT;
flcmdcr_val |= DOCMD2_E | CDSRC_E | SELRW;
if (flctl->chip.options & NAND_BUSWIDTH_16)
flcmncr_val |= SEL_16BIT;
break;
case NAND_CMD_READID:
flcmncr_val &= ~SNAND_E;
flcmdcr_val |= CDSRC_E;
addr_len_bytes = ADRCNT_1;
break;
case NAND_CMD_STATUS:
case NAND_CMD_RESET:
flcmncr_val &= ~SNAND_E;
flcmdcr_val &= ~(DOADR_E | DOSR_E);
break;
default:
break;
}
flcmdcr_val |= addr_len_bytes;
writel(flcmncr_val, FLCMNCR(flctl));
writel(flcmdcr_val, FLCMDCR(flctl));
writel(flcmcdr_val, FLCMCDR(flctl));
}
static int flctl_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
chip->read_buf(mtd, buf, mtd->writesize);
if (oob_required)
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int flctl_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required)
{
chip->write_buf(mtd, buf, mtd->writesize);
chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static void execmd_read_page_sector(struct mtd_info *mtd, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int sector, page_sectors;
enum flctl_ecc_res_t ecc_result;
page_sectors = flctl->page_size ? 4 : 1;
set_cmd_regs(mtd, NAND_CMD_READ0,
(NAND_CMD_READSTART << 8) | NAND_CMD_READ0);
writel(readl(FLCMNCR(flctl)) | ACM_SACCES_MODE | _4ECCCORRECT,
FLCMNCR(flctl));
writel(readl(FLCMDCR(flctl)) | page_sectors, FLCMDCR(flctl));
writel(page_addr << 2, FLADR(flctl));
empty_fifo(flctl);
start_translation(flctl);
for (sector = 0; sector < page_sectors; sector++) {
read_fiforeg(flctl, 512, 512 * sector);
ecc_result = read_ecfiforeg(flctl,
&flctl->done_buff[mtd->writesize + 16 * sector],
sector);
switch (ecc_result) {
case FL_REPAIRABLE:
dev_info(&flctl->pdev->dev,
"applied ecc on page 0x%x", page_addr);
flctl->mtd.ecc_stats.corrected++;
break;
case FL_ERROR:
dev_warn(&flctl->pdev->dev,
"page 0x%x contains corrupted data\n",
page_addr);
flctl->mtd.ecc_stats.failed++;
break;
default:
;
}
}
wait_completion(flctl);
writel(readl(FLCMNCR(flctl)) & ~(ACM_SACCES_MODE | _4ECCCORRECT),
FLCMNCR(flctl));
}
static void execmd_read_oob(struct mtd_info *mtd, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int page_sectors = flctl->page_size ? 4 : 1;
int i;
set_cmd_regs(mtd, NAND_CMD_READ0,
(NAND_CMD_READSTART << 8) | NAND_CMD_READ0);
empty_fifo(flctl);
for (i = 0; i < page_sectors; i++) {
set_addr(mtd, (512 + 16) * i + 512 , page_addr);
writel(16, FLDTCNTR(flctl));
start_translation(flctl);
read_fiforeg(flctl, 16, 16 * i);
wait_completion(flctl);
}
}
static void execmd_write_page_sector(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int page_addr = flctl->seqin_page_addr;
int sector, page_sectors;
page_sectors = flctl->page_size ? 4 : 1;
set_cmd_regs(mtd, NAND_CMD_PAGEPROG,
(NAND_CMD_PAGEPROG << 8) | NAND_CMD_SEQIN);
empty_fifo(flctl);
writel(readl(FLCMNCR(flctl)) | ACM_SACCES_MODE, FLCMNCR(flctl));
writel(readl(FLCMDCR(flctl)) | page_sectors, FLCMDCR(flctl));
writel(page_addr << 2, FLADR(flctl));
start_translation(flctl);
for (sector = 0; sector < page_sectors; sector++) {
write_fiforeg(flctl, 512, 512 * sector);
write_ec_fiforeg(flctl, 16, mtd->writesize + 16 * sector);
}
wait_completion(flctl);
writel(readl(FLCMNCR(flctl)) & ~ACM_SACCES_MODE, FLCMNCR(flctl));
}
static void execmd_write_oob(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int page_addr = flctl->seqin_page_addr;
int sector, page_sectors;
page_sectors = flctl->page_size ? 4 : 1;
set_cmd_regs(mtd, NAND_CMD_PAGEPROG,
(NAND_CMD_PAGEPROG << 8) | NAND_CMD_SEQIN);
for (sector = 0; sector < page_sectors; sector++) {
empty_fifo(flctl);
set_addr(mtd, sector * 528 + 512, page_addr);
writel(16, FLDTCNTR(flctl));
start_translation(flctl);
write_fiforeg(flctl, 16, 16 * sector);
wait_completion(flctl);
}
}
static void flctl_cmdfunc(struct mtd_info *mtd, unsigned int command,
int column, int page_addr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
uint32_t read_cmd = 0;
pm_runtime_get_sync(&flctl->pdev->dev);
flctl->read_bytes = 0;
if (command != NAND_CMD_PAGEPROG)
flctl->index = 0;
switch (command) {
case NAND_CMD_READ1:
case NAND_CMD_READ0:
if (flctl->hwecc) {
execmd_read_page_sector(mtd, page_addr);
break;
}
if (flctl->page_size)
set_cmd_regs(mtd, command, (NAND_CMD_READSTART << 8)
| command);
else
set_cmd_regs(mtd, command, command);
set_addr(mtd, 0, page_addr);
flctl->read_bytes = mtd->writesize + mtd->oobsize;
if (flctl->chip.options & NAND_BUSWIDTH_16)
column >>= 1;
flctl->index += column;
goto read_normal_exit;
case NAND_CMD_READOOB:
if (flctl->hwecc) {
execmd_read_oob(mtd, page_addr);
break;
}
if (flctl->page_size) {
set_cmd_regs(mtd, command, (NAND_CMD_READSTART << 8)
| NAND_CMD_READ0);
set_addr(mtd, mtd->writesize, page_addr);
} else {
set_cmd_regs(mtd, command, command);
set_addr(mtd, 0, page_addr);
}
flctl->read_bytes = mtd->oobsize;
goto read_normal_exit;
case NAND_CMD_RNDOUT:
if (flctl->hwecc)
break;
if (flctl->page_size)
set_cmd_regs(mtd, command, (NAND_CMD_RNDOUTSTART << 8)
| command);
else
set_cmd_regs(mtd, command, command);
set_addr(mtd, column, 0);
flctl->read_bytes = mtd->writesize + mtd->oobsize - column;
goto read_normal_exit;
case NAND_CMD_READID:
set_cmd_regs(mtd, command, command);
if (flctl->chip.options & NAND_BUSWIDTH_16)
column <<= 1;
set_addr(mtd, column, 0);
flctl->read_bytes = 8;
writel(flctl->read_bytes, FLDTCNTR(flctl));
empty_fifo(flctl);
start_translation(flctl);
read_fiforeg(flctl, flctl->read_bytes, 0);
wait_completion(flctl);
break;
case NAND_CMD_ERASE1:
flctl->erase1_page_addr = page_addr;
break;
case NAND_CMD_ERASE2:
set_cmd_regs(mtd, NAND_CMD_ERASE1,
(command << 8) | NAND_CMD_ERASE1);
set_addr(mtd, -1, flctl->erase1_page_addr);
start_translation(flctl);
wait_completion(flctl);
break;
case NAND_CMD_SEQIN:
if (!flctl->page_size) {
if (column >= mtd->writesize) {
column -= mtd->writesize;
read_cmd = NAND_CMD_READOOB;
} else if (column < 256) {
read_cmd = NAND_CMD_READ0;
} else {
column -= 256;
read_cmd = NAND_CMD_READ1;
}
}
flctl->seqin_column = column;
flctl->seqin_page_addr = page_addr;
flctl->seqin_read_cmd = read_cmd;
break;
case NAND_CMD_PAGEPROG:
empty_fifo(flctl);
if (!flctl->page_size) {
set_cmd_regs(mtd, NAND_CMD_SEQIN,
flctl->seqin_read_cmd);
set_addr(mtd, -1, -1);
writel(0, FLDTCNTR(flctl));
start_translation(flctl);
wait_completion(flctl);
}
if (flctl->hwecc) {
if (flctl->seqin_column == mtd->writesize)
execmd_write_oob(mtd);
else if (!flctl->seqin_column)
execmd_write_page_sector(mtd);
else
printk(KERN_ERR "Invalid address !?\n");
break;
}
set_cmd_regs(mtd, command, (command << 8) | NAND_CMD_SEQIN);
set_addr(mtd, flctl->seqin_column, flctl->seqin_page_addr);
writel(flctl->index, FLDTCNTR(flctl));
start_translation(flctl);
write_fiforeg(flctl, flctl->index, 0);
wait_completion(flctl);
break;
case NAND_CMD_STATUS:
set_cmd_regs(mtd, command, command);
set_addr(mtd, -1, -1);
flctl->read_bytes = 1;
writel(flctl->read_bytes, FLDTCNTR(flctl));
start_translation(flctl);
read_datareg(flctl, 0);
break;
case NAND_CMD_RESET:
set_cmd_regs(mtd, command, command);
set_addr(mtd, -1, -1);
writel(0, FLDTCNTR(flctl));
start_translation(flctl);
wait_completion(flctl);
break;
default:
break;
}
goto runtime_exit;
read_normal_exit:
writel(flctl->read_bytes, FLDTCNTR(flctl));
empty_fifo(flctl);
start_translation(flctl);
read_fiforeg(flctl, flctl->read_bytes, 0);
wait_completion(flctl);
runtime_exit:
pm_runtime_put_sync(&flctl->pdev->dev);
return;
}
static void flctl_select_chip(struct mtd_info *mtd, int chipnr)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int ret;
switch (chipnr) {
case -1:
flctl->flcmncr_base &= ~CE0_ENABLE;
pm_runtime_get_sync(&flctl->pdev->dev);
writel(flctl->flcmncr_base, FLCMNCR(flctl));
if (flctl->qos_request) {
dev_pm_qos_remove_request(&flctl->pm_qos);
flctl->qos_request = 0;
}
pm_runtime_put_sync(&flctl->pdev->dev);
break;
case 0:
flctl->flcmncr_base |= CE0_ENABLE;
if (!flctl->qos_request) {
ret = dev_pm_qos_add_request(&flctl->pdev->dev,
&flctl->pm_qos, 100);
if (ret < 0)
dev_err(&flctl->pdev->dev,
"PM QoS request failed: %d\n", ret);
flctl->qos_request = 1;
}
if (flctl->holden) {
pm_runtime_get_sync(&flctl->pdev->dev);
writel(HOLDEN, FLHOLDCR(flctl));
pm_runtime_put_sync(&flctl->pdev->dev);
}
break;
default:
BUG();
}
}
static void flctl_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int index = flctl->index;
memcpy(&flctl->done_buff[index], buf, len);
flctl->index += len;
}
static uint8_t flctl_read_byte(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int index = flctl->index;
uint8_t data;
data = flctl->done_buff[index];
flctl->index++;
return data;
}
static uint16_t flctl_read_word(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int index = flctl->index;
uint16_t data;
uint16_t *buf = (uint16_t *)&flctl->done_buff[index];
data = *buf;
flctl->index += 2;
return data;
}
static void flctl_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
int index = flctl->index;
memcpy(buf, &flctl->done_buff[index], len);
flctl->index += len;
}
static int flctl_chip_init_tail(struct mtd_info *mtd)
{
struct sh_flctl *flctl = mtd_to_flctl(mtd);
struct nand_chip *chip = &flctl->chip;
if (mtd->writesize == 512) {
flctl->page_size = 0;
if (chip->chipsize > (32 << 20)) {
flctl->rw_ADRCNT = ADRCNT_4;
flctl->erase_ADRCNT = ADRCNT_3;
} else if (chip->chipsize > (2 << 16)) {
flctl->rw_ADRCNT = ADRCNT_3;
flctl->erase_ADRCNT = ADRCNT_2;
} else {
flctl->rw_ADRCNT = ADRCNT_2;
flctl->erase_ADRCNT = ADRCNT_1;
}
} else {
flctl->page_size = 1;
if (chip->chipsize > (128 << 20)) {
flctl->rw_ADRCNT = ADRCNT2_E;
flctl->erase_ADRCNT = ADRCNT_3;
} else if (chip->chipsize > (8 << 16)) {
flctl->rw_ADRCNT = ADRCNT_4;
flctl->erase_ADRCNT = ADRCNT_2;
} else {
flctl->rw_ADRCNT = ADRCNT_3;
flctl->erase_ADRCNT = ADRCNT_1;
}
}
if (flctl->hwecc) {
if (mtd->writesize == 512) {
chip->ecc.layout = &flctl_4secc_oob_16;
chip->badblock_pattern = &flctl_4secc_smallpage;
} else {
chip->ecc.layout = &flctl_4secc_oob_64;
chip->badblock_pattern = &flctl_4secc_largepage;
}
chip->ecc.size = 512;
chip->ecc.bytes = 10;
chip->ecc.strength = 4;
chip->ecc.read_page = flctl_read_page_hwecc;
chip->ecc.write_page = flctl_write_page_hwecc;
chip->ecc.mode = NAND_ECC_HW;
flctl->flcmncr_base |= _4ECCEN;
} else {
chip->ecc.mode = NAND_ECC_SOFT;
}
return 0;
}
static irqreturn_t flctl_handle_flste(int irq, void *dev_id)
{
struct sh_flctl *flctl = dev_id;
dev_err(&flctl->pdev->dev, "flste irq: %x\n", readl(FLINTDMACR(flctl)));
writel(flctl->flintdmacr_base, FLINTDMACR(flctl));
return IRQ_HANDLED;
}
static int __devinit flctl_probe(struct platform_device *pdev)
{
struct resource *res;
struct sh_flctl *flctl;
struct mtd_info *flctl_mtd;
struct nand_chip *nand;
struct sh_flctl_platform_data *pdata;
int ret = -ENXIO;
int irq;
pdata = pdev->dev.platform_data;
if (pdata == NULL) {
dev_err(&pdev->dev, "no platform data defined\n");
return -EINVAL;
}
flctl = kzalloc(sizeof(struct sh_flctl), GFP_KERNEL);
if (!flctl) {
dev_err(&pdev->dev, "failed to allocate driver data\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get I/O memory\n");
goto err_iomap;
}
flctl->reg = ioremap(res->start, resource_size(res));
if (flctl->reg == NULL) {
dev_err(&pdev->dev, "failed to remap I/O memory\n");
goto err_iomap;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get flste irq data\n");
goto err_flste;
}
ret = request_irq(irq, flctl_handle_flste, IRQF_SHARED, "flste", flctl);
if (ret) {
dev_err(&pdev->dev, "request interrupt failed.\n");
goto err_flste;
}
platform_set_drvdata(pdev, flctl);
flctl_mtd = &flctl->mtd;
nand = &flctl->chip;
flctl_mtd->priv = nand;
flctl->pdev = pdev;
flctl->hwecc = pdata->has_hwecc;
flctl->holden = pdata->use_holden;
flctl->flcmncr_base = pdata->flcmncr_val;
flctl->flintdmacr_base = flctl->hwecc ? (STERINTE | ECERB) : STERINTE;
nand->chip_delay = 20;
nand->read_byte = flctl_read_byte;
nand->write_buf = flctl_write_buf;
nand->read_buf = flctl_read_buf;
nand->select_chip = flctl_select_chip;
nand->cmdfunc = flctl_cmdfunc;
if (pdata->flcmncr_val & SEL_16BIT) {
nand->options |= NAND_BUSWIDTH_16;
nand->read_word = flctl_read_word;
}
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
ret = nand_scan_ident(flctl_mtd, 1, NULL);
if (ret)
goto err_chip;
ret = flctl_chip_init_tail(flctl_mtd);
if (ret)
goto err_chip;
ret = nand_scan_tail(flctl_mtd);
if (ret)
goto err_chip;
mtd_device_register(flctl_mtd, pdata->parts, pdata->nr_parts);
return 0;
err_chip:
pm_runtime_disable(&pdev->dev);
free_irq(irq, flctl);
err_flste:
iounmap(flctl->reg);
err_iomap:
kfree(flctl);
return ret;
}
static int __devexit flctl_remove(struct platform_device *pdev)
{
struct sh_flctl *flctl = platform_get_drvdata(pdev);
nand_release(&flctl->mtd);
pm_runtime_disable(&pdev->dev);
free_irq(platform_get_irq(pdev, 0), flctl);
iounmap(flctl->reg);
kfree(flctl);
return 0;
}
static int __init flctl_nand_init(void)
{
return platform_driver_probe(&flctl_driver, flctl_probe);
}
static void __exit flctl_nand_cleanup(void)
{
platform_driver_unregister(&flctl_driver);
}
