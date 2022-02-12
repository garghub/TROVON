static inline struct qcom_nand_host *to_qcom_nand_host(struct nand_chip *chip)
{
return container_of(chip, struct qcom_nand_host, chip);
}
static inline struct qcom_nand_controller *
get_qcom_nand_controller(struct nand_chip *chip)
{
return container_of(chip->controller, struct qcom_nand_controller,
controller);
}
static inline u32 nandc_read(struct qcom_nand_controller *nandc, int offset)
{
return ioread32(nandc->base + offset);
}
static inline void nandc_write(struct qcom_nand_controller *nandc, int offset,
u32 val)
{
iowrite32(val, nandc->base + offset);
}
static __le32 *offset_to_nandc_reg(struct nandc_regs *regs, int offset)
{
switch (offset) {
case NAND_FLASH_CMD:
return &regs->cmd;
case NAND_ADDR0:
return &regs->addr0;
case NAND_ADDR1:
return &regs->addr1;
case NAND_FLASH_CHIP_SELECT:
return &regs->chip_sel;
case NAND_EXEC_CMD:
return &regs->exec;
case NAND_FLASH_STATUS:
return &regs->clrflashstatus;
case NAND_DEV0_CFG0:
return &regs->cfg0;
case NAND_DEV0_CFG1:
return &regs->cfg1;
case NAND_DEV0_ECC_CFG:
return &regs->ecc_bch_cfg;
case NAND_READ_STATUS:
return &regs->clrreadstatus;
case NAND_DEV_CMD1:
return &regs->cmd1;
case NAND_DEV_CMD1_RESTORE:
return &regs->orig_cmd1;
case NAND_DEV_CMD_VLD:
return &regs->vld;
case NAND_DEV_CMD_VLD_RESTORE:
return &regs->orig_vld;
case NAND_EBI2_ECC_BUF_CFG:
return &regs->ecc_buf_cfg;
default:
return NULL;
}
}
static void nandc_set_reg(struct qcom_nand_controller *nandc, int offset,
u32 val)
{
struct nandc_regs *regs = nandc->regs;
__le32 *reg;
reg = offset_to_nandc_reg(regs, offset);
if (reg)
*reg = cpu_to_le32(val);
}
static void set_address(struct qcom_nand_host *host, u16 column, int page)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
if (chip->options & NAND_BUSWIDTH_16)
column >>= 1;
nandc_set_reg(nandc, NAND_ADDR0, page << 16 | column);
nandc_set_reg(nandc, NAND_ADDR1, page >> 16 & 0xff);
}
static void update_rw_regs(struct qcom_nand_host *host, int num_cw, bool read)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
u32 cmd, cfg0, cfg1, ecc_bch_cfg;
if (read) {
if (host->use_ecc)
cmd = PAGE_READ_WITH_ECC | PAGE_ACC | LAST_PAGE;
else
cmd = PAGE_READ | PAGE_ACC | LAST_PAGE;
} else {
cmd = PROGRAM_PAGE | PAGE_ACC | LAST_PAGE;
}
if (host->use_ecc) {
cfg0 = (host->cfg0 & ~(7U << CW_PER_PAGE)) |
(num_cw - 1) << CW_PER_PAGE;
cfg1 = host->cfg1;
ecc_bch_cfg = host->ecc_bch_cfg;
} else {
cfg0 = (host->cfg0_raw & ~(7U << CW_PER_PAGE)) |
(num_cw - 1) << CW_PER_PAGE;
cfg1 = host->cfg1_raw;
ecc_bch_cfg = 1 << ECC_CFG_ECC_DISABLE;
}
nandc_set_reg(nandc, NAND_FLASH_CMD, cmd);
nandc_set_reg(nandc, NAND_DEV0_CFG0, cfg0);
nandc_set_reg(nandc, NAND_DEV0_CFG1, cfg1);
nandc_set_reg(nandc, NAND_DEV0_ECC_CFG, ecc_bch_cfg);
nandc_set_reg(nandc, NAND_EBI2_ECC_BUF_CFG, host->ecc_buf_cfg);
nandc_set_reg(nandc, NAND_FLASH_STATUS, host->clrflashstatus);
nandc_set_reg(nandc, NAND_READ_STATUS, host->clrreadstatus);
nandc_set_reg(nandc, NAND_EXEC_CMD, 1);
}
static int prep_dma_desc(struct qcom_nand_controller *nandc, bool read,
int reg_off, const void *vaddr, int size,
bool flow_control)
{
struct desc_info *desc;
struct dma_async_tx_descriptor *dma_desc;
struct scatterlist *sgl;
struct dma_slave_config slave_conf;
enum dma_transfer_direction dir_eng;
int ret;
desc = kzalloc(sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
sgl = &desc->sgl;
sg_init_one(sgl, vaddr, size);
if (read) {
dir_eng = DMA_DEV_TO_MEM;
desc->dir = DMA_FROM_DEVICE;
} else {
dir_eng = DMA_MEM_TO_DEV;
desc->dir = DMA_TO_DEVICE;
}
ret = dma_map_sg(nandc->dev, sgl, 1, desc->dir);
if (ret == 0) {
ret = -ENOMEM;
goto err;
}
memset(&slave_conf, 0x00, sizeof(slave_conf));
slave_conf.device_fc = flow_control;
if (read) {
slave_conf.src_maxburst = 16;
slave_conf.src_addr = nandc->base_dma + reg_off;
slave_conf.slave_id = nandc->data_crci;
} else {
slave_conf.dst_maxburst = 16;
slave_conf.dst_addr = nandc->base_dma + reg_off;
slave_conf.slave_id = nandc->cmd_crci;
}
ret = dmaengine_slave_config(nandc->chan, &slave_conf);
if (ret) {
dev_err(nandc->dev, "failed to configure dma channel\n");
goto err;
}
dma_desc = dmaengine_prep_slave_sg(nandc->chan, sgl, 1, dir_eng, 0);
if (!dma_desc) {
dev_err(nandc->dev, "failed to prepare desc\n");
ret = -EINVAL;
goto err;
}
desc->dma_desc = dma_desc;
list_add_tail(&desc->node, &nandc->desc_list);
return 0;
err:
kfree(desc);
return ret;
}
static int read_reg_dma(struct qcom_nand_controller *nandc, int first,
int num_regs)
{
bool flow_control = false;
void *vaddr;
int size;
if (first == NAND_READ_ID || first == NAND_FLASH_STATUS)
flow_control = true;
size = num_regs * sizeof(u32);
vaddr = nandc->reg_read_buf + nandc->reg_read_pos;
nandc->reg_read_pos += num_regs;
return prep_dma_desc(nandc, true, first, vaddr, size, flow_control);
}
static int write_reg_dma(struct qcom_nand_controller *nandc, int first,
int num_regs)
{
bool flow_control = false;
struct nandc_regs *regs = nandc->regs;
void *vaddr;
int size;
vaddr = offset_to_nandc_reg(regs, first);
if (first == NAND_FLASH_CMD)
flow_control = true;
if (first == NAND_DEV_CMD1_RESTORE)
first = NAND_DEV_CMD1;
if (first == NAND_DEV_CMD_VLD_RESTORE)
first = NAND_DEV_CMD_VLD;
size = num_regs * sizeof(u32);
return prep_dma_desc(nandc, false, first, vaddr, size, flow_control);
}
static int read_data_dma(struct qcom_nand_controller *nandc, int reg_off,
const u8 *vaddr, int size)
{
return prep_dma_desc(nandc, true, reg_off, vaddr, size, false);
}
static int write_data_dma(struct qcom_nand_controller *nandc, int reg_off,
const u8 *vaddr, int size)
{
return prep_dma_desc(nandc, false, reg_off, vaddr, size, false);
}
static void config_cw_read(struct qcom_nand_controller *nandc)
{
write_reg_dma(nandc, NAND_FLASH_CMD, 3);
write_reg_dma(nandc, NAND_DEV0_CFG0, 3);
write_reg_dma(nandc, NAND_EBI2_ECC_BUF_CFG, 1);
write_reg_dma(nandc, NAND_EXEC_CMD, 1);
read_reg_dma(nandc, NAND_FLASH_STATUS, 2);
read_reg_dma(nandc, NAND_ERASED_CW_DETECT_STATUS, 1);
}
static void config_cw_write_pre(struct qcom_nand_controller *nandc)
{
write_reg_dma(nandc, NAND_FLASH_CMD, 3);
write_reg_dma(nandc, NAND_DEV0_CFG0, 3);
write_reg_dma(nandc, NAND_EBI2_ECC_BUF_CFG, 1);
}
static void config_cw_write_post(struct qcom_nand_controller *nandc)
{
write_reg_dma(nandc, NAND_EXEC_CMD, 1);
read_reg_dma(nandc, NAND_FLASH_STATUS, 1);
write_reg_dma(nandc, NAND_FLASH_STATUS, 1);
write_reg_dma(nandc, NAND_READ_STATUS, 1);
}
static int nandc_param(struct qcom_nand_host *host)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
nandc_set_reg(nandc, NAND_FLASH_CMD, PAGE_READ | PAGE_ACC | LAST_PAGE);
nandc_set_reg(nandc, NAND_ADDR0, 0);
nandc_set_reg(nandc, NAND_ADDR1, 0);
nandc_set_reg(nandc, NAND_DEV0_CFG0, 0 << CW_PER_PAGE
| 512 << UD_SIZE_BYTES
| 5 << NUM_ADDR_CYCLES
| 0 << SPARE_SIZE_BYTES);
nandc_set_reg(nandc, NAND_DEV0_CFG1, 7 << NAND_RECOVERY_CYCLES
| 0 << CS_ACTIVE_BSY
| 17 << BAD_BLOCK_BYTE_NUM
| 1 << BAD_BLOCK_IN_SPARE_AREA
| 2 << WR_RD_BSY_GAP
| 0 << WIDE_FLASH
| 1 << DEV0_CFG1_ECC_DISABLE);
nandc_set_reg(nandc, NAND_EBI2_ECC_BUF_CFG, 1 << ECC_CFG_ECC_DISABLE);
nandc_set_reg(nandc, NAND_DEV_CMD_VLD,
(nandc->vld & ~(1 << READ_START_VLD))
| 0 << READ_START_VLD);
nandc_set_reg(nandc, NAND_DEV_CMD1,
(nandc->cmd1 & ~(0xFF << READ_ADDR))
| NAND_CMD_PARAM << READ_ADDR);
nandc_set_reg(nandc, NAND_EXEC_CMD, 1);
nandc_set_reg(nandc, NAND_DEV_CMD1_RESTORE, nandc->cmd1);
nandc_set_reg(nandc, NAND_DEV_CMD_VLD_RESTORE, nandc->vld);
write_reg_dma(nandc, NAND_DEV_CMD_VLD, 1);
write_reg_dma(nandc, NAND_DEV_CMD1, 1);
nandc->buf_count = 512;
memset(nandc->data_buffer, 0xff, nandc->buf_count);
config_cw_read(nandc);
read_data_dma(nandc, FLASH_BUF_ACC, nandc->data_buffer,
nandc->buf_count);
write_reg_dma(nandc, NAND_DEV_CMD1_RESTORE, 1);
write_reg_dma(nandc, NAND_DEV_CMD_VLD_RESTORE, 1);
return 0;
}
static int erase_block(struct qcom_nand_host *host, int page_addr)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
nandc_set_reg(nandc, NAND_FLASH_CMD,
BLOCK_ERASE | PAGE_ACC | LAST_PAGE);
nandc_set_reg(nandc, NAND_ADDR0, page_addr);
nandc_set_reg(nandc, NAND_ADDR1, 0);
nandc_set_reg(nandc, NAND_DEV0_CFG0,
host->cfg0_raw & ~(7 << CW_PER_PAGE));
nandc_set_reg(nandc, NAND_DEV0_CFG1, host->cfg1_raw);
nandc_set_reg(nandc, NAND_EXEC_CMD, 1);
nandc_set_reg(nandc, NAND_FLASH_STATUS, host->clrflashstatus);
nandc_set_reg(nandc, NAND_READ_STATUS, host->clrreadstatus);
write_reg_dma(nandc, NAND_FLASH_CMD, 3);
write_reg_dma(nandc, NAND_DEV0_CFG0, 2);
write_reg_dma(nandc, NAND_EXEC_CMD, 1);
read_reg_dma(nandc, NAND_FLASH_STATUS, 1);
write_reg_dma(nandc, NAND_FLASH_STATUS, 1);
write_reg_dma(nandc, NAND_READ_STATUS, 1);
return 0;
}
static int read_id(struct qcom_nand_host *host, int column)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
if (column == -1)
return 0;
nandc_set_reg(nandc, NAND_FLASH_CMD, FETCH_ID);
nandc_set_reg(nandc, NAND_ADDR0, column);
nandc_set_reg(nandc, NAND_ADDR1, 0);
nandc_set_reg(nandc, NAND_FLASH_CHIP_SELECT, DM_EN);
nandc_set_reg(nandc, NAND_EXEC_CMD, 1);
write_reg_dma(nandc, NAND_FLASH_CMD, 4);
write_reg_dma(nandc, NAND_EXEC_CMD, 1);
read_reg_dma(nandc, NAND_READ_ID, 1);
return 0;
}
static int reset(struct qcom_nand_host *host)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
nandc_set_reg(nandc, NAND_FLASH_CMD, RESET_DEVICE);
nandc_set_reg(nandc, NAND_EXEC_CMD, 1);
write_reg_dma(nandc, NAND_FLASH_CMD, 1);
write_reg_dma(nandc, NAND_EXEC_CMD, 1);
read_reg_dma(nandc, NAND_FLASH_STATUS, 1);
return 0;
}
static int submit_descs(struct qcom_nand_controller *nandc)
{
struct desc_info *desc;
dma_cookie_t cookie = 0;
list_for_each_entry(desc, &nandc->desc_list, node)
cookie = dmaengine_submit(desc->dma_desc);
if (dma_sync_wait(nandc->chan, cookie) != DMA_COMPLETE)
return -ETIMEDOUT;
return 0;
}
static void free_descs(struct qcom_nand_controller *nandc)
{
struct desc_info *desc, *n;
list_for_each_entry_safe(desc, n, &nandc->desc_list, node) {
list_del(&desc->node);
dma_unmap_sg(nandc->dev, &desc->sgl, 1, desc->dir);
kfree(desc);
}
}
static void clear_read_regs(struct qcom_nand_controller *nandc)
{
nandc->reg_read_pos = 0;
memset(nandc->reg_read_buf, 0,
MAX_REG_RD * sizeof(*nandc->reg_read_buf));
}
static void pre_command(struct qcom_nand_host *host, int command)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
nandc->buf_count = 0;
nandc->buf_start = 0;
host->use_ecc = false;
host->last_command = command;
clear_read_regs(nandc);
}
static void parse_erase_write_errors(struct qcom_nand_host *host, int command)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int num_cw;
int i;
num_cw = command == NAND_CMD_PAGEPROG ? ecc->steps : 1;
for (i = 0; i < num_cw; i++) {
u32 flash_status = le32_to_cpu(nandc->reg_read_buf[i]);
if (flash_status & FS_MPU_ERR)
host->status &= ~NAND_STATUS_WP;
if (flash_status & FS_OP_ERR || (i == (num_cw - 1) &&
(flash_status &
FS_DEVICE_STS_ERR)))
host->status |= NAND_STATUS_FAIL;
}
}
static void post_command(struct qcom_nand_host *host, int command)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
switch (command) {
case NAND_CMD_READID:
memcpy(nandc->data_buffer, nandc->reg_read_buf,
nandc->buf_count);
break;
case NAND_CMD_PAGEPROG:
case NAND_CMD_ERASE1:
parse_erase_write_errors(host, command);
break;
default:
break;
}
}
static void qcom_nandc_command(struct mtd_info *mtd, unsigned int command,
int column, int page_addr)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
bool wait = false;
int ret = 0;
pre_command(host, command);
switch (command) {
case NAND_CMD_RESET:
ret = reset(host);
wait = true;
break;
case NAND_CMD_READID:
nandc->buf_count = 4;
ret = read_id(host, column);
wait = true;
break;
case NAND_CMD_PARAM:
ret = nandc_param(host);
wait = true;
break;
case NAND_CMD_ERASE1:
ret = erase_block(host, page_addr);
wait = true;
break;
case NAND_CMD_READ0:
WARN_ON(column != 0);
host->use_ecc = true;
set_address(host, 0, page_addr);
update_rw_regs(host, ecc->steps, true);
break;
case NAND_CMD_SEQIN:
WARN_ON(column != 0);
set_address(host, 0, page_addr);
break;
case NAND_CMD_PAGEPROG:
case NAND_CMD_STATUS:
case NAND_CMD_NONE:
default:
break;
}
if (ret) {
dev_err(nandc->dev, "failure executing command %d\n",
command);
free_descs(nandc);
return;
}
if (wait) {
ret = submit_descs(nandc);
if (ret)
dev_err(nandc->dev,
"failure submitting descs for command %d\n",
command);
}
free_descs(nandc);
post_command(host, command);
}
static bool erased_chunk_check_and_fixup(u8 *data_buf, int data_len)
{
u8 empty1, empty2;
empty1 = data_buf[3];
empty2 = data_buf[175];
if ((empty1 == 0x54 && empty2 == 0xff) ||
(empty1 == 0xff && empty2 == 0x54)) {
data_buf[3] = 0xff;
data_buf[175] = 0xff;
}
if (memchr_inv(data_buf, 0xff, data_len)) {
data_buf[3] = empty1;
data_buf[175] = empty2;
return false;
}
return true;
}
static int parse_read_errors(struct qcom_nand_host *host, u8 *data_buf,
u8 *oob_buf)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct mtd_info *mtd = nand_to_mtd(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
unsigned int max_bitflips = 0;
struct read_stats *buf;
int i;
buf = (struct read_stats *)nandc->reg_read_buf;
for (i = 0; i < ecc->steps; i++, buf++) {
u32 flash, buffer, erased_cw;
int data_len, oob_len;
if (i == (ecc->steps - 1)) {
data_len = ecc->size - ((ecc->steps - 1) << 2);
oob_len = ecc->steps << 2;
} else {
data_len = host->cw_data;
oob_len = 0;
}
flash = le32_to_cpu(buf->flash);
buffer = le32_to_cpu(buf->buffer);
erased_cw = le32_to_cpu(buf->erased_cw);
if (flash & (FS_OP_ERR | FS_MPU_ERR)) {
bool erased;
if (host->bch_enabled) {
erased = (erased_cw & ERASED_CW) == ERASED_CW ?
true : false;
} else {
erased = erased_chunk_check_and_fixup(data_buf,
data_len);
}
if (erased) {
data_buf += data_len;
if (oob_buf)
oob_buf += oob_len + ecc->bytes;
continue;
}
if (buffer & BS_UNCORRECTABLE_BIT) {
int ret, ecclen, extraooblen;
void *eccbuf;
eccbuf = oob_buf ? oob_buf + oob_len : NULL;
ecclen = oob_buf ? host->ecc_bytes_hw : 0;
extraooblen = oob_buf ? oob_len : 0;
ret = nand_check_erased_ecc_chunk(data_buf,
data_len, eccbuf, ecclen, oob_buf,
extraooblen, ecc->strength);
if (ret < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += ret;
max_bitflips =
max_t(unsigned int, max_bitflips, ret);
}
}
} else {
unsigned int stat;
stat = buffer & BS_CORRECTABLE_ERR_MSK;
mtd->ecc_stats.corrected += stat;
max_bitflips = max(max_bitflips, stat);
}
data_buf += data_len;
if (oob_buf)
oob_buf += oob_len + ecc->bytes;
}
return max_bitflips;
}
static int read_page_ecc(struct qcom_nand_host *host, u8 *data_buf,
u8 *oob_buf)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int i, ret;
for (i = 0; i < ecc->steps; i++) {
int data_size, oob_size;
if (i == (ecc->steps - 1)) {
data_size = ecc->size - ((ecc->steps - 1) << 2);
oob_size = (ecc->steps << 2) + host->ecc_bytes_hw +
host->spare_bytes;
} else {
data_size = host->cw_data;
oob_size = host->ecc_bytes_hw + host->spare_bytes;
}
config_cw_read(nandc);
if (data_buf)
read_data_dma(nandc, FLASH_BUF_ACC, data_buf,
data_size);
if (oob_buf) {
int j;
for (j = 0; j < host->bbm_size; j++)
*oob_buf++ = 0xff;
read_data_dma(nandc, FLASH_BUF_ACC + data_size,
oob_buf, oob_size);
}
if (data_buf)
data_buf += data_size;
if (oob_buf)
oob_buf += oob_size;
}
ret = submit_descs(nandc);
if (ret)
dev_err(nandc->dev, "failure to read page/oob\n");
free_descs(nandc);
return ret;
}
static int copy_last_cw(struct qcom_nand_host *host, int page)
{
struct nand_chip *chip = &host->chip;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int size;
int ret;
clear_read_regs(nandc);
size = host->use_ecc ? host->cw_data : host->cw_size;
memset(nandc->data_buffer, 0xff, size);
set_address(host, host->cw_size * (ecc->steps - 1), page);
update_rw_regs(host, 1, true);
config_cw_read(nandc);
read_data_dma(nandc, FLASH_BUF_ACC, nandc->data_buffer, size);
ret = submit_descs(nandc);
if (ret)
dev_err(nandc->dev, "failed to copy last codeword\n");
free_descs(nandc);
return ret;
}
static int qcom_nandc_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
u8 *data_buf, *oob_buf = NULL;
int ret;
data_buf = buf;
oob_buf = oob_required ? chip->oob_poi : NULL;
ret = read_page_ecc(host, data_buf, oob_buf);
if (ret) {
dev_err(nandc->dev, "failure to read page\n");
return ret;
}
return parse_read_errors(host, data_buf, oob_buf);
}
static int qcom_nandc_read_page_raw(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf,
int oob_required, int page)
{
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
u8 *data_buf, *oob_buf;
struct nand_ecc_ctrl *ecc = &chip->ecc;
int i, ret;
data_buf = buf;
oob_buf = chip->oob_poi;
host->use_ecc = false;
update_rw_regs(host, ecc->steps, true);
for (i = 0; i < ecc->steps; i++) {
int data_size1, data_size2, oob_size1, oob_size2;
int reg_off = FLASH_BUF_ACC;
data_size1 = mtd->writesize - host->cw_size * (ecc->steps - 1);
oob_size1 = host->bbm_size;
if (i == (ecc->steps - 1)) {
data_size2 = ecc->size - data_size1 -
((ecc->steps - 1) << 2);
oob_size2 = (ecc->steps << 2) + host->ecc_bytes_hw +
host->spare_bytes;
} else {
data_size2 = host->cw_data - data_size1;
oob_size2 = host->ecc_bytes_hw + host->spare_bytes;
}
config_cw_read(nandc);
read_data_dma(nandc, reg_off, data_buf, data_size1);
reg_off += data_size1;
data_buf += data_size1;
read_data_dma(nandc, reg_off, oob_buf, oob_size1);
reg_off += oob_size1;
oob_buf += oob_size1;
read_data_dma(nandc, reg_off, data_buf, data_size2);
reg_off += data_size2;
data_buf += data_size2;
read_data_dma(nandc, reg_off, oob_buf, oob_size2);
oob_buf += oob_size2;
}
ret = submit_descs(nandc);
if (ret)
dev_err(nandc->dev, "failure to read raw page\n");
free_descs(nandc);
return 0;
}
static int qcom_nandc_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int ret;
clear_read_regs(nandc);
host->use_ecc = true;
set_address(host, 0, page);
update_rw_regs(host, ecc->steps, true);
ret = read_page_ecc(host, NULL, chip->oob_poi);
if (ret)
dev_err(nandc->dev, "failure to read oob\n");
return ret;
}
static int qcom_nandc_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required, int page)
{
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
u8 *data_buf, *oob_buf;
int i, ret;
clear_read_regs(nandc);
data_buf = (u8 *)buf;
oob_buf = chip->oob_poi;
host->use_ecc = true;
update_rw_regs(host, ecc->steps, false);
for (i = 0; i < ecc->steps; i++) {
int data_size, oob_size;
if (i == (ecc->steps - 1)) {
data_size = ecc->size - ((ecc->steps - 1) << 2);
oob_size = (ecc->steps << 2) + host->ecc_bytes_hw +
host->spare_bytes;
} else {
data_size = host->cw_data;
oob_size = ecc->bytes;
}
config_cw_write_pre(nandc);
write_data_dma(nandc, FLASH_BUF_ACC, data_buf, data_size);
if (i == (ecc->steps - 1)) {
oob_buf += host->bbm_size;
write_data_dma(nandc, FLASH_BUF_ACC + data_size,
oob_buf, oob_size);
}
config_cw_write_post(nandc);
data_buf += data_size;
oob_buf += oob_size;
}
ret = submit_descs(nandc);
if (ret)
dev_err(nandc->dev, "failure to write page\n");
free_descs(nandc);
return ret;
}
static int qcom_nandc_write_page_raw(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf,
int oob_required, int page)
{
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
u8 *data_buf, *oob_buf;
int i, ret;
clear_read_regs(nandc);
data_buf = (u8 *)buf;
oob_buf = chip->oob_poi;
host->use_ecc = false;
update_rw_regs(host, ecc->steps, false);
for (i = 0; i < ecc->steps; i++) {
int data_size1, data_size2, oob_size1, oob_size2;
int reg_off = FLASH_BUF_ACC;
data_size1 = mtd->writesize - host->cw_size * (ecc->steps - 1);
oob_size1 = host->bbm_size;
if (i == (ecc->steps - 1)) {
data_size2 = ecc->size - data_size1 -
((ecc->steps - 1) << 2);
oob_size2 = (ecc->steps << 2) + host->ecc_bytes_hw +
host->spare_bytes;
} else {
data_size2 = host->cw_data - data_size1;
oob_size2 = host->ecc_bytes_hw + host->spare_bytes;
}
config_cw_write_pre(nandc);
write_data_dma(nandc, reg_off, data_buf, data_size1);
reg_off += data_size1;
data_buf += data_size1;
write_data_dma(nandc, reg_off, oob_buf, oob_size1);
reg_off += oob_size1;
oob_buf += oob_size1;
write_data_dma(nandc, reg_off, data_buf, data_size2);
reg_off += data_size2;
data_buf += data_size2;
write_data_dma(nandc, reg_off, oob_buf, oob_size2);
oob_buf += oob_size2;
config_cw_write_post(nandc);
}
ret = submit_descs(nandc);
if (ret)
dev_err(nandc->dev, "failure to write raw page\n");
free_descs(nandc);
return ret;
}
static int qcom_nandc_write_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
u8 *oob = chip->oob_poi;
int data_size, oob_size;
int ret, status = 0;
host->use_ecc = true;
ret = copy_last_cw(host, page);
if (ret)
return ret;
clear_read_regs(nandc);
data_size = ecc->size - ((ecc->steps - 1) << 2);
oob_size = mtd->oobavail;
mtd_ooblayout_get_databytes(mtd, nandc->data_buffer + data_size, oob,
0, mtd->oobavail);
set_address(host, host->cw_size * (ecc->steps - 1), page);
update_rw_regs(host, 1, false);
config_cw_write_pre(nandc);
write_data_dma(nandc, FLASH_BUF_ACC, nandc->data_buffer,
data_size + oob_size);
config_cw_write_post(nandc);
ret = submit_descs(nandc);
free_descs(nandc);
if (ret) {
dev_err(nandc->dev, "failure to write oob\n");
return -EIO;
}
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
static int qcom_nandc_block_bad(struct mtd_info *mtd, loff_t ofs)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int page, ret, bbpos, bad = 0;
u32 flash_status;
page = (int)(ofs >> chip->page_shift) & chip->pagemask;
host->use_ecc = false;
ret = copy_last_cw(host, page);
if (ret)
goto err;
flash_status = le32_to_cpu(nandc->reg_read_buf[0]);
if (flash_status & (FS_OP_ERR | FS_MPU_ERR)) {
dev_warn(nandc->dev, "error when trying to read BBM\n");
goto err;
}
bbpos = mtd->writesize - host->cw_size * (ecc->steps - 1);
bad = nandc->data_buffer[bbpos] != 0xff;
if (chip->options & NAND_BUSWIDTH_16)
bad = bad || (nandc->data_buffer[bbpos + 1] != 0xff);
err:
return bad;
}
static int qcom_nandc_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
int page, ret, status = 0;
clear_read_regs(nandc);
memset(nandc->data_buffer, 0x00, host->cw_size);
page = (int)(ofs >> chip->page_shift) & chip->pagemask;
host->use_ecc = false;
set_address(host, host->cw_size * (ecc->steps - 1), page);
update_rw_regs(host, 1, false);
config_cw_write_pre(nandc);
write_data_dma(nandc, FLASH_BUF_ACC, nandc->data_buffer, host->cw_size);
config_cw_write_post(nandc);
ret = submit_descs(nandc);
free_descs(nandc);
if (ret) {
dev_err(nandc->dev, "failure to update BBM\n");
return -EIO;
}
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
return status & NAND_STATUS_FAIL ? -EIO : 0;
}
static uint8_t qcom_nandc_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
u8 *buf = nandc->data_buffer;
u8 ret = 0x0;
if (host->last_command == NAND_CMD_STATUS) {
ret = host->status;
host->status = NAND_STATUS_READY | NAND_STATUS_WP;
return ret;
}
if (nandc->buf_start < nandc->buf_count)
ret = buf[nandc->buf_start++];
return ret;
}
static void qcom_nandc_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
int real_len = min_t(size_t, len, nandc->buf_count - nandc->buf_start);
memcpy(buf, nandc->data_buffer + nandc->buf_start, real_len);
nandc->buf_start += real_len;
}
static void qcom_nandc_write_buf(struct mtd_info *mtd, const uint8_t *buf,
int len)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
int real_len = min_t(size_t, len, nandc->buf_count - nandc->buf_start);
memcpy(nandc->data_buffer + nandc->buf_start, buf, real_len);
nandc->buf_start += real_len;
}
static void qcom_nandc_select_chip(struct mtd_info *mtd, int chipnr)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
if (chipnr <= 0)
return;
dev_warn(nandc->dev, "invalid chip select\n");
}
static int qcom_nand_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (section > 1)
return -ERANGE;
if (!section) {
oobregion->length = (ecc->bytes * (ecc->steps - 1)) +
host->bbm_size;
oobregion->offset = 0;
} else {
oobregion->length = host->ecc_bytes_hw + host->spare_bytes;
oobregion->offset = mtd->oobsize - oobregion->length;
}
return 0;
}
static int qcom_nand_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct qcom_nand_host *host = to_qcom_nand_host(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (section)
return -ERANGE;
oobregion->length = ecc->steps * 4;
oobregion->offset = ((ecc->steps - 1) * ecc->bytes) + host->bbm_size;
return 0;
}
static int qcom_nand_host_setup(struct qcom_nand_host *host)
{
struct nand_chip *chip = &host->chip;
struct mtd_info *mtd = nand_to_mtd(chip);
struct nand_ecc_ctrl *ecc = &chip->ecc;
struct qcom_nand_controller *nandc = get_qcom_nand_controller(chip);
int cwperpage, bad_block_byte;
bool wide_bus;
int ecc_mode = 1;
if (ecc->size != NANDC_STEP_SIZE) {
dev_err(nandc->dev, "invalid ecc size\n");
return -EINVAL;
}
wide_bus = chip->options & NAND_BUSWIDTH_16 ? true : false;
if (ecc->strength >= 8) {
host->bch_enabled = true;
ecc_mode = 1;
if (wide_bus) {
host->ecc_bytes_hw = 14;
host->spare_bytes = 0;
host->bbm_size = 2;
} else {
host->ecc_bytes_hw = 13;
host->spare_bytes = 2;
host->bbm_size = 1;
}
} else {
if (nandc->ecc_modes & ECC_BCH_4BIT) {
host->bch_enabled = true;
ecc_mode = 0;
if (wide_bus) {
host->ecc_bytes_hw = 8;
host->spare_bytes = 2;
host->bbm_size = 2;
} else {
host->ecc_bytes_hw = 7;
host->spare_bytes = 4;
host->bbm_size = 1;
}
} else {
host->ecc_bytes_hw = 10;
if (wide_bus) {
host->spare_bytes = 0;
host->bbm_size = 2;
} else {
host->spare_bytes = 1;
host->bbm_size = 1;
}
}
}
ecc->bytes = host->ecc_bytes_hw + host->spare_bytes + host->bbm_size;
ecc->read_page = qcom_nandc_read_page;
ecc->read_page_raw = qcom_nandc_read_page_raw;
ecc->read_oob = qcom_nandc_read_oob;
ecc->write_page = qcom_nandc_write_page;
ecc->write_page_raw = qcom_nandc_write_page_raw;
ecc->write_oob = qcom_nandc_write_oob;
ecc->mode = NAND_ECC_HW;
mtd_set_ooblayout(mtd, &qcom_nand_ooblayout_ops);
cwperpage = mtd->writesize / ecc->size;
host->cw_data = 516;
host->cw_size = host->cw_data + ecc->bytes;
if (ecc->bytes * (mtd->writesize / ecc->size) > mtd->oobsize) {
dev_err(nandc->dev, "ecc data doesn't fit in OOB area\n");
return -EINVAL;
}
bad_block_byte = mtd->writesize - host->cw_size * (cwperpage - 1) + 1;
host->cfg0 = (cwperpage - 1) << CW_PER_PAGE
| host->cw_data << UD_SIZE_BYTES
| 0 << DISABLE_STATUS_AFTER_WRITE
| 5 << NUM_ADDR_CYCLES
| host->ecc_bytes_hw << ECC_PARITY_SIZE_BYTES_RS
| 0 << STATUS_BFR_READ
| 1 << SET_RD_MODE_AFTER_STATUS
| host->spare_bytes << SPARE_SIZE_BYTES;
host->cfg1 = 7 << NAND_RECOVERY_CYCLES
| 0 << CS_ACTIVE_BSY
| bad_block_byte << BAD_BLOCK_BYTE_NUM
| 0 << BAD_BLOCK_IN_SPARE_AREA
| 2 << WR_RD_BSY_GAP
| wide_bus << WIDE_FLASH
| host->bch_enabled << ENABLE_BCH_ECC;
host->cfg0_raw = (cwperpage - 1) << CW_PER_PAGE
| host->cw_size << UD_SIZE_BYTES
| 5 << NUM_ADDR_CYCLES
| 0 << SPARE_SIZE_BYTES;
host->cfg1_raw = 7 << NAND_RECOVERY_CYCLES
| 0 << CS_ACTIVE_BSY
| 17 << BAD_BLOCK_BYTE_NUM
| 1 << BAD_BLOCK_IN_SPARE_AREA
| 2 << WR_RD_BSY_GAP
| wide_bus << WIDE_FLASH
| 1 << DEV0_CFG1_ECC_DISABLE;
host->ecc_bch_cfg = host->bch_enabled << ECC_CFG_ECC_DISABLE
| 0 << ECC_SW_RESET
| host->cw_data << ECC_NUM_DATA_BYTES
| 1 << ECC_FORCE_CLK_OPEN
| ecc_mode << ECC_MODE
| host->ecc_bytes_hw << ECC_PARITY_SIZE_BYTES_BCH;
host->ecc_buf_cfg = 0x203 << NUM_STEPS;
host->clrflashstatus = FS_READY_BSY_N;
host->clrreadstatus = 0xc0;
dev_dbg(nandc->dev,
"cfg0 %x cfg1 %x ecc_buf_cfg %x ecc_bch cfg %x cw_size %d cw_data %d strength %d parity_bytes %d steps %d\n",
host->cfg0, host->cfg1, host->ecc_buf_cfg, host->ecc_bch_cfg,
host->cw_size, host->cw_data, ecc->strength, ecc->bytes,
cwperpage);
return 0;
}
static int qcom_nandc_alloc(struct qcom_nand_controller *nandc)
{
int ret;
ret = dma_set_coherent_mask(nandc->dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(nandc->dev, "failed to set DMA mask\n");
return ret;
}
nandc->buf_size = 532;
nandc->data_buffer = devm_kzalloc(nandc->dev, nandc->buf_size,
GFP_KERNEL);
if (!nandc->data_buffer)
return -ENOMEM;
nandc->regs = devm_kzalloc(nandc->dev, sizeof(*nandc->regs),
GFP_KERNEL);
if (!nandc->regs)
return -ENOMEM;
nandc->reg_read_buf = devm_kzalloc(nandc->dev,
MAX_REG_RD * sizeof(*nandc->reg_read_buf),
GFP_KERNEL);
if (!nandc->reg_read_buf)
return -ENOMEM;
nandc->chan = dma_request_slave_channel(nandc->dev, "rxtx");
if (!nandc->chan) {
dev_err(nandc->dev, "failed to request slave channel\n");
return -ENODEV;
}
INIT_LIST_HEAD(&nandc->desc_list);
INIT_LIST_HEAD(&nandc->host_list);
spin_lock_init(&nandc->controller.lock);
init_waitqueue_head(&nandc->controller.wq);
return 0;
}
static void qcom_nandc_unalloc(struct qcom_nand_controller *nandc)
{
dma_release_channel(nandc->chan);
}
static int qcom_nandc_setup(struct qcom_nand_controller *nandc)
{
nandc_write(nandc, SFLASHC_BURST_CFG, 0);
nandc_write(nandc, NAND_FLASH_CHIP_SELECT, DM_EN);
nandc->cmd1 = nandc_read(nandc, NAND_DEV_CMD1);
nandc->vld = nandc_read(nandc, NAND_DEV_CMD_VLD);
return 0;
}
static int qcom_nand_host_init(struct qcom_nand_controller *nandc,
struct qcom_nand_host *host,
struct device_node *dn)
{
struct nand_chip *chip = &host->chip;
struct mtd_info *mtd = nand_to_mtd(chip);
struct device *dev = nandc->dev;
int ret;
ret = of_property_read_u32(dn, "reg", &host->cs);
if (ret) {
dev_err(dev, "can't get chip-select\n");
return -ENXIO;
}
nand_set_flash_node(chip, dn);
mtd->name = devm_kasprintf(dev, GFP_KERNEL, "qcom_nand.%d", host->cs);
mtd->owner = THIS_MODULE;
mtd->dev.parent = dev;
chip->cmdfunc = qcom_nandc_command;
chip->select_chip = qcom_nandc_select_chip;
chip->read_byte = qcom_nandc_read_byte;
chip->read_buf = qcom_nandc_read_buf;
chip->write_buf = qcom_nandc_write_buf;
chip->block_bad = qcom_nandc_block_bad;
chip->block_markbad = qcom_nandc_block_markbad;
chip->controller = &nandc->controller;
chip->options |= NAND_NO_SUBPAGE_WRITE | NAND_USE_BOUNCE_BUFFER |
NAND_SKIP_BBTSCAN;
host->status = NAND_STATUS_READY | NAND_STATUS_WP;
ret = nand_scan_ident(mtd, 1, NULL);
if (ret)
return ret;
ret = qcom_nand_host_setup(host);
if (ret)
return ret;
ret = nand_scan_tail(mtd);
if (ret)
return ret;
return mtd_device_register(mtd, NULL, 0);
}
static int qcom_nandc_parse_dt(struct platform_device *pdev)
{
struct qcom_nand_controller *nandc = platform_get_drvdata(pdev);
struct device_node *np = nandc->dev->of_node;
int ret;
ret = of_property_read_u32(np, "qcom,cmd-crci", &nandc->cmd_crci);
if (ret) {
dev_err(nandc->dev, "command CRCI unspecified\n");
return ret;
}
ret = of_property_read_u32(np, "qcom,data-crci", &nandc->data_crci);
if (ret) {
dev_err(nandc->dev, "data CRCI unspecified\n");
return ret;
}
return 0;
}
static int qcom_nandc_probe(struct platform_device *pdev)
{
struct qcom_nand_controller *nandc;
struct qcom_nand_host *host;
const void *dev_data;
struct device *dev = &pdev->dev;
struct device_node *dn = dev->of_node, *child;
struct resource *res;
int ret;
nandc = devm_kzalloc(&pdev->dev, sizeof(*nandc), GFP_KERNEL);
if (!nandc)
return -ENOMEM;
platform_set_drvdata(pdev, nandc);
nandc->dev = dev;
dev_data = of_device_get_match_data(dev);
if (!dev_data) {
dev_err(&pdev->dev, "failed to get device data\n");
return -ENODEV;
}
nandc->ecc_modes = (unsigned long)dev_data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nandc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(nandc->base))
return PTR_ERR(nandc->base);
nandc->base_dma = phys_to_dma(dev, (phys_addr_t)res->start);
nandc->core_clk = devm_clk_get(dev, "core");
if (IS_ERR(nandc->core_clk))
return PTR_ERR(nandc->core_clk);
nandc->aon_clk = devm_clk_get(dev, "aon");
if (IS_ERR(nandc->aon_clk))
return PTR_ERR(nandc->aon_clk);
ret = qcom_nandc_parse_dt(pdev);
if (ret)
return ret;
ret = qcom_nandc_alloc(nandc);
if (ret)
return ret;
ret = clk_prepare_enable(nandc->core_clk);
if (ret)
goto err_core_clk;
ret = clk_prepare_enable(nandc->aon_clk);
if (ret)
goto err_aon_clk;
ret = qcom_nandc_setup(nandc);
if (ret)
goto err_setup;
for_each_available_child_of_node(dn, child) {
if (of_device_is_compatible(child, "qcom,nandcs")) {
host = devm_kzalloc(dev, sizeof(*host), GFP_KERNEL);
if (!host) {
of_node_put(child);
ret = -ENOMEM;
goto err_cs_init;
}
ret = qcom_nand_host_init(nandc, host, child);
if (ret) {
devm_kfree(dev, host);
continue;
}
list_add_tail(&host->node, &nandc->host_list);
}
}
if (list_empty(&nandc->host_list)) {
ret = -ENODEV;
goto err_cs_init;
}
return 0;
err_cs_init:
list_for_each_entry(host, &nandc->host_list, node)
nand_release(nand_to_mtd(&host->chip));
err_setup:
clk_disable_unprepare(nandc->aon_clk);
err_aon_clk:
clk_disable_unprepare(nandc->core_clk);
err_core_clk:
qcom_nandc_unalloc(nandc);
return ret;
}
static int qcom_nandc_remove(struct platform_device *pdev)
{
struct qcom_nand_controller *nandc = platform_get_drvdata(pdev);
struct qcom_nand_host *host;
list_for_each_entry(host, &nandc->host_list, node)
nand_release(nand_to_mtd(&host->chip));
qcom_nandc_unalloc(nandc);
clk_disable_unprepare(nandc->aon_clk);
clk_disable_unprepare(nandc->core_clk);
return 0;
}
