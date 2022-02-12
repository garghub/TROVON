static inline u32 nand_readreg(struct brcmnand_controller *ctrl, u32 offs)
{
return brcmnand_readl(ctrl->nand_base + offs);
}
static inline void nand_writereg(struct brcmnand_controller *ctrl, u32 offs,
u32 val)
{
brcmnand_writel(val, ctrl->nand_base + offs);
}
static int brcmnand_revision_init(struct brcmnand_controller *ctrl)
{
static const unsigned int block_sizes_v6[] = { 8, 16, 128, 256, 512, 1024, 2048, 0 };
static const unsigned int block_sizes_v4[] = { 16, 128, 8, 512, 256, 1024, 2048, 0 };
static const unsigned int page_sizes[] = { 512, 2048, 4096, 8192, 0 };
ctrl->nand_version = nand_readreg(ctrl, 0) & 0xffff;
if (ctrl->nand_version < 0x0400) {
dev_err(ctrl->dev, "version %#x not supported\n",
ctrl->nand_version);
return -ENODEV;
}
if (ctrl->nand_version >= 0x0701)
ctrl->reg_offsets = brcmnand_regs_v71;
else if (ctrl->nand_version >= 0x0600)
ctrl->reg_offsets = brcmnand_regs_v60;
else if (ctrl->nand_version >= 0x0500)
ctrl->reg_offsets = brcmnand_regs_v50;
else if (ctrl->nand_version >= 0x0400)
ctrl->reg_offsets = brcmnand_regs_v40;
if (ctrl->nand_version >= 0x0701)
ctrl->reg_spacing = 0x14;
else
ctrl->reg_spacing = 0x10;
if (ctrl->nand_version >= 0x0701) {
ctrl->cs_offsets = brcmnand_cs_offsets_v71;
} else {
ctrl->cs_offsets = brcmnand_cs_offsets;
if (ctrl->nand_version <= 0x0500)
ctrl->cs0_offsets = brcmnand_cs_offsets_cs0;
}
if (ctrl->nand_version >= 0x0701) {
ctrl->max_page_size = 16 * 1024;
ctrl->max_block_size = 2 * 1024 * 1024;
} else {
ctrl->page_sizes = page_sizes;
if (ctrl->nand_version >= 0x0600)
ctrl->block_sizes = block_sizes_v6;
else
ctrl->block_sizes = block_sizes_v4;
if (ctrl->nand_version < 0x0400) {
ctrl->max_page_size = 4096;
ctrl->max_block_size = 512 * 1024;
}
}
if (ctrl->nand_version >= 0x0600)
ctrl->max_oob = 64;
else if (ctrl->nand_version >= 0x0500)
ctrl->max_oob = 32;
else
ctrl->max_oob = 16;
if (ctrl->nand_version >= 0x0600 && ctrl->nand_version != 0x0601)
ctrl->features |= BRCMNAND_HAS_PREFETCH;
if (ctrl->nand_version >= 0x0700)
ctrl->features |= BRCMNAND_HAS_CACHE_MODE;
if (ctrl->nand_version >= 0x0500)
ctrl->features |= BRCMNAND_HAS_1K_SECTORS;
if (ctrl->nand_version >= 0x0700)
ctrl->features |= BRCMNAND_HAS_WP;
else if (of_property_read_bool(ctrl->dev->of_node, "brcm,nand-has-wp"))
ctrl->features |= BRCMNAND_HAS_WP;
return 0;
}
static inline u32 brcmnand_read_reg(struct brcmnand_controller *ctrl,
enum brcmnand_reg reg)
{
u16 offs = ctrl->reg_offsets[reg];
if (offs)
return nand_readreg(ctrl, offs);
else
return 0;
}
static inline void brcmnand_write_reg(struct brcmnand_controller *ctrl,
enum brcmnand_reg reg, u32 val)
{
u16 offs = ctrl->reg_offsets[reg];
if (offs)
nand_writereg(ctrl, offs, val);
}
static inline void brcmnand_rmw_reg(struct brcmnand_controller *ctrl,
enum brcmnand_reg reg, u32 mask, unsigned
int shift, u32 val)
{
u32 tmp = brcmnand_read_reg(ctrl, reg);
tmp &= ~mask;
tmp |= val << shift;
brcmnand_write_reg(ctrl, reg, tmp);
}
static inline u32 brcmnand_read_fc(struct brcmnand_controller *ctrl, int word)
{
return __raw_readl(ctrl->nand_fc + word * 4);
}
static inline void brcmnand_write_fc(struct brcmnand_controller *ctrl,
int word, u32 val)
{
__raw_writel(val, ctrl->nand_fc + word * 4);
}
static inline u16 brcmnand_cs_offset(struct brcmnand_controller *ctrl, int cs,
enum brcmnand_cs_reg reg)
{
u16 offs_cs0 = ctrl->reg_offsets[BRCMNAND_CS0_BASE];
u16 offs_cs1 = ctrl->reg_offsets[BRCMNAND_CS1_BASE];
u8 cs_offs;
if (cs == 0 && ctrl->cs0_offsets)
cs_offs = ctrl->cs0_offsets[reg];
else
cs_offs = ctrl->cs_offsets[reg];
if (cs && offs_cs1)
return offs_cs1 + (cs - 1) * ctrl->reg_spacing + cs_offs;
return offs_cs0 + cs * ctrl->reg_spacing + cs_offs;
}
static inline u32 brcmnand_count_corrected(struct brcmnand_controller *ctrl)
{
if (ctrl->nand_version < 0x0600)
return 1;
return brcmnand_read_reg(ctrl, BRCMNAND_CORR_COUNT);
}
static void brcmnand_wr_corr_thresh(struct brcmnand_host *host, u8 val)
{
struct brcmnand_controller *ctrl = host->ctrl;
unsigned int shift = 0, bits;
enum brcmnand_reg reg = BRCMNAND_CORR_THRESHOLD;
int cs = host->cs;
if (ctrl->nand_version >= 0x0600)
bits = 6;
else if (ctrl->nand_version >= 0x0500)
bits = 5;
else
bits = 4;
if (ctrl->nand_version >= 0x0600) {
if (cs >= 5)
reg = BRCMNAND_CORR_THRESHOLD_EXT;
shift = (cs % 5) * bits;
}
brcmnand_rmw_reg(ctrl, reg, (bits - 1) << shift, shift, val);
}
static inline int brcmnand_cmd_shift(struct brcmnand_controller *ctrl)
{
if (ctrl->nand_version < 0x0700)
return 24;
return 0;
}
static inline u32 brcmnand_spare_area_mask(struct brcmnand_controller *ctrl)
{
if (ctrl->nand_version >= 0x0600)
return GENMASK(6, 0);
else
return GENMASK(5, 0);
}
static inline u32 brcmnand_ecc_level_mask(struct brcmnand_controller *ctrl)
{
u32 mask = (ctrl->nand_version >= 0x0600) ? 0x1f : 0x0f;
return mask << NAND_ACC_CONTROL_ECC_SHIFT;
}
static void brcmnand_set_ecc_enabled(struct brcmnand_host *host, int en)
{
struct brcmnand_controller *ctrl = host->ctrl;
u16 offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_ACC_CONTROL);
u32 acc_control = nand_readreg(ctrl, offs);
u32 ecc_flags = ACC_CONTROL_WR_ECC | ACC_CONTROL_RD_ECC;
if (en) {
acc_control |= ecc_flags;
acc_control |= host->hwcfg.ecc_level
<< NAND_ACC_CONTROL_ECC_SHIFT;
} else {
acc_control &= ~ecc_flags;
acc_control &= ~brcmnand_ecc_level_mask(ctrl);
}
nand_writereg(ctrl, offs, acc_control);
}
static inline int brcmnand_sector_1k_shift(struct brcmnand_controller *ctrl)
{
if (ctrl->nand_version >= 0x0600)
return 7;
else if (ctrl->nand_version >= 0x0500)
return 6;
else
return -1;
}
static int brcmnand_get_sector_size_1k(struct brcmnand_host *host)
{
struct brcmnand_controller *ctrl = host->ctrl;
int shift = brcmnand_sector_1k_shift(ctrl);
u16 acc_control_offs = brcmnand_cs_offset(ctrl, host->cs,
BRCMNAND_CS_ACC_CONTROL);
if (shift < 0)
return 0;
return (nand_readreg(ctrl, acc_control_offs) >> shift) & 0x1;
}
static void brcmnand_set_sector_size_1k(struct brcmnand_host *host, int val)
{
struct brcmnand_controller *ctrl = host->ctrl;
int shift = brcmnand_sector_1k_shift(ctrl);
u16 acc_control_offs = brcmnand_cs_offset(ctrl, host->cs,
BRCMNAND_CS_ACC_CONTROL);
u32 tmp;
if (shift < 0)
return;
tmp = nand_readreg(ctrl, acc_control_offs);
tmp &= ~(1 << shift);
tmp |= (!!val) << shift;
nand_writereg(ctrl, acc_control_offs, tmp);
}
static inline void brcmnand_set_wp(struct brcmnand_controller *ctrl, bool en)
{
u32 val = en ? CS_SELECT_NAND_WP : 0;
brcmnand_rmw_reg(ctrl, BRCMNAND_CS_SELECT, CS_SELECT_NAND_WP, 0, val);
}
static inline bool has_flash_dma(struct brcmnand_controller *ctrl)
{
return ctrl->flash_dma_base;
}
static inline bool flash_dma_buf_ok(const void *buf)
{
return buf && !is_vmalloc_addr(buf) &&
likely(IS_ALIGNED((uintptr_t)buf, 4));
}
static inline void flash_dma_writel(struct brcmnand_controller *ctrl, u8 offs,
u32 val)
{
brcmnand_writel(val, ctrl->flash_dma_base + offs);
}
static inline u32 flash_dma_readl(struct brcmnand_controller *ctrl, u8 offs)
{
return brcmnand_readl(ctrl->flash_dma_base + offs);
}
static inline bool is_hamming_ecc(struct brcmnand_cfg *cfg)
{
return cfg->sector_size_1k == 0 && cfg->spare_area_size == 16 &&
cfg->ecc_level == 15;
}
static struct nand_ecclayout *brcmnand_create_layout(int ecc_level,
struct brcmnand_host *host)
{
struct brcmnand_cfg *cfg = &host->hwcfg;
int i, j;
struct nand_ecclayout *layout;
int req;
int sectors;
int sas;
int idx1, idx2;
layout = devm_kzalloc(&host->pdev->dev, sizeof(*layout), GFP_KERNEL);
if (!layout)
return NULL;
sectors = cfg->page_size / (512 << cfg->sector_size_1k);
sas = cfg->spare_area_size << cfg->sector_size_1k;
if (is_hamming_ecc(cfg)) {
for (i = 0, idx1 = 0, idx2 = 0; i < sectors; i++) {
if (i == 0) {
layout->oobfree[idx2].offset = i * sas + 1;
if (cfg->page_size == 512)
layout->oobfree[idx2].offset--;
layout->oobfree[idx2].length = 5;
} else {
layout->oobfree[idx2].offset = i * sas;
layout->oobfree[idx2].length = 6;
}
idx2++;
layout->eccpos[idx1++] = i * sas + 6;
layout->eccpos[idx1++] = i * sas + 7;
layout->eccpos[idx1++] = i * sas + 8;
layout->oobfree[idx2].offset = i * sas + 9;
layout->oobfree[idx2].length = 7;
idx2++;
if (idx1 >= MTD_MAX_ECCPOS_ENTRIES_LARGE ||
idx2 >= MTD_MAX_OOBFREE_ENTRIES_LARGE - 1)
break;
}
return layout;
}
req = DIV_ROUND_UP(ecc_level * 14, 8);
if (req >= sas) {
dev_err(&host->pdev->dev,
"error: ECC too large for OOB (ECC bytes %d, spare sector %d)\n",
req, sas);
return NULL;
}
layout->eccbytes = req * sectors;
for (i = 0, idx1 = 0, idx2 = 0; i < sectors; i++) {
for (j = sas - req; j < sas && idx1 <
MTD_MAX_ECCPOS_ENTRIES_LARGE; j++, idx1++)
layout->eccpos[idx1] = i * sas + j;
if (i == 0) {
if (cfg->page_size == 512 && (sas - req >= 6)) {
layout->oobfree[idx2].offset = 0;
layout->oobfree[idx2].length = 5;
idx2++;
if (sas - req > 6) {
layout->oobfree[idx2].offset = 6;
layout->oobfree[idx2].length =
sas - req - 6;
idx2++;
}
} else if (sas > req + 1) {
layout->oobfree[idx2].offset = i * sas + 1;
layout->oobfree[idx2].length = sas - req - 1;
idx2++;
}
} else if (sas > req) {
layout->oobfree[idx2].offset = i * sas;
layout->oobfree[idx2].length = sas - req;
idx2++;
}
if (idx1 >= MTD_MAX_ECCPOS_ENTRIES_LARGE ||
idx2 >= MTD_MAX_OOBFREE_ENTRIES_LARGE - 1)
break;
}
return layout;
}
static struct nand_ecclayout *brcmstb_choose_ecc_layout(
struct brcmnand_host *host)
{
struct nand_ecclayout *layout;
struct brcmnand_cfg *p = &host->hwcfg;
unsigned int ecc_level = p->ecc_level;
if (p->sector_size_1k)
ecc_level <<= 1;
layout = brcmnand_create_layout(ecc_level, host);
if (!layout) {
dev_err(&host->pdev->dev,
"no proper ecc_layout for this NAND cfg\n");
return NULL;
}
return layout;
}
static void brcmnand_wp(struct mtd_info *mtd, int wp)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
if ((ctrl->features & BRCMNAND_HAS_WP) && wp_on == 1) {
static int old_wp = -1;
if (old_wp != wp) {
dev_dbg(ctrl->dev, "WP %s\n", wp ? "on" : "off");
old_wp = wp;
}
brcmnand_set_wp(ctrl, wp);
}
}
static inline u8 oob_reg_read(struct brcmnand_controller *ctrl, u32 offs)
{
u16 offset0, offset10, reg_offs;
offset0 = ctrl->reg_offsets[BRCMNAND_OOB_READ_BASE];
offset10 = ctrl->reg_offsets[BRCMNAND_OOB_READ_10_BASE];
if (offs >= ctrl->max_oob)
return 0x77;
if (offs >= 16 && offset10)
reg_offs = offset10 + ((offs - 0x10) & ~0x03);
else
reg_offs = offset0 + (offs & ~0x03);
return nand_readreg(ctrl, reg_offs) >> (24 - ((offs & 0x03) << 3));
}
static inline void oob_reg_write(struct brcmnand_controller *ctrl, u32 offs,
u32 data)
{
u16 offset0, offset10, reg_offs;
offset0 = ctrl->reg_offsets[BRCMNAND_OOB_WRITE_BASE];
offset10 = ctrl->reg_offsets[BRCMNAND_OOB_WRITE_10_BASE];
if (offs >= ctrl->max_oob)
return;
if (offs >= 16 && offset10)
reg_offs = offset10 + ((offs - 0x10) & ~0x03);
else
reg_offs = offset0 + (offs & ~0x03);
nand_writereg(ctrl, reg_offs, data);
}
static int read_oob_from_regs(struct brcmnand_controller *ctrl, int i, u8 *oob,
int sas, int sector_1k)
{
int tbytes = sas << sector_1k;
int j;
if (sector_1k && (i & 0x01))
tbytes = max(0, tbytes - (int)ctrl->max_oob);
tbytes = min_t(int, tbytes, ctrl->max_oob);
for (j = 0; j < tbytes; j++)
oob[j] = oob_reg_read(ctrl, j);
return tbytes;
}
static int write_oob_to_regs(struct brcmnand_controller *ctrl, int i,
const u8 *oob, int sas, int sector_1k)
{
int tbytes = sas << sector_1k;
int j;
if (sector_1k && (i & 0x01))
tbytes = max(0, tbytes - (int)ctrl->max_oob);
tbytes = min_t(int, tbytes, ctrl->max_oob);
for (j = 0; j < tbytes; j += 4)
oob_reg_write(ctrl, j,
(oob[j + 0] << 24) |
(oob[j + 1] << 16) |
(oob[j + 2] << 8) |
(oob[j + 3] << 0));
return tbytes;
}
static irqreturn_t brcmnand_ctlrdy_irq(int irq, void *data)
{
struct brcmnand_controller *ctrl = data;
if (ctrl->dma_pending)
return IRQ_HANDLED;
complete(&ctrl->done);
return IRQ_HANDLED;
}
static irqreturn_t brcmnand_irq(int irq, void *data)
{
struct brcmnand_controller *ctrl = data;
if (ctrl->soc->ctlrdy_ack(ctrl->soc))
return brcmnand_ctlrdy_irq(irq, data);
return IRQ_NONE;
}
static irqreturn_t brcmnand_dma_irq(int irq, void *data)
{
struct brcmnand_controller *ctrl = data;
complete(&ctrl->dma_done);
return IRQ_HANDLED;
}
static void brcmnand_send_cmd(struct brcmnand_host *host, int cmd)
{
struct brcmnand_controller *ctrl = host->ctrl;
u32 intfc;
dev_dbg(ctrl->dev, "send native cmd %d addr_lo 0x%x\n", cmd,
brcmnand_read_reg(ctrl, BRCMNAND_CMD_ADDRESS));
BUG_ON(ctrl->cmd_pending != 0);
ctrl->cmd_pending = cmd;
intfc = brcmnand_read_reg(ctrl, BRCMNAND_INTFC_STATUS);
BUG_ON(!(intfc & INTFC_CTLR_READY));
mb();
brcmnand_write_reg(ctrl, BRCMNAND_CMD_START,
cmd << brcmnand_cmd_shift(ctrl));
}
static void brcmnand_cmd_ctrl(struct mtd_info *mtd, int dat,
unsigned int ctrl)
{
}
static int brcmnand_waitfunc(struct mtd_info *mtd, struct nand_chip *this)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
unsigned long timeo = msecs_to_jiffies(100);
dev_dbg(ctrl->dev, "wait on native cmd %d\n", ctrl->cmd_pending);
if (ctrl->cmd_pending &&
wait_for_completion_timeout(&ctrl->done, timeo) <= 0) {
u32 cmd = brcmnand_read_reg(ctrl, BRCMNAND_CMD_START)
>> brcmnand_cmd_shift(ctrl);
dev_err_ratelimited(ctrl->dev,
"timeout waiting for command %#02x\n", cmd);
dev_err_ratelimited(ctrl->dev, "intfc status %08x\n",
brcmnand_read_reg(ctrl, BRCMNAND_INTFC_STATUS));
}
ctrl->cmd_pending = 0;
return brcmnand_read_reg(ctrl, BRCMNAND_INTFC_STATUS) &
INTFC_FLASH_STATUS;
}
static int brcmnand_low_level_op(struct brcmnand_host *host,
enum brcmnand_llop_type type, u32 data,
bool last_op)
{
struct mtd_info *mtd = nand_to_mtd(&host->chip);
struct nand_chip *chip = &host->chip;
struct brcmnand_controller *ctrl = host->ctrl;
u32 tmp;
tmp = data & LLOP_DATA_MASK;
switch (type) {
case LL_OP_CMD:
tmp |= LLOP_WE | LLOP_CLE;
break;
case LL_OP_ADDR:
tmp |= LLOP_WE | LLOP_ALE;
break;
case LL_OP_WR:
tmp |= LLOP_WE;
break;
case LL_OP_RD:
tmp |= LLOP_RE;
break;
}
if (last_op)
tmp |= LLOP_RETURN_IDLE;
dev_dbg(ctrl->dev, "ll_op cmd %#x\n", tmp);
brcmnand_write_reg(ctrl, BRCMNAND_LL_OP, tmp);
(void)brcmnand_read_reg(ctrl, BRCMNAND_LL_OP);
brcmnand_send_cmd(host, CMD_LOW_LEVEL_OP);
return brcmnand_waitfunc(mtd, chip);
}
static void brcmnand_cmdfunc(struct mtd_info *mtd, unsigned command,
int column, int page_addr)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
u64 addr = (u64)page_addr << chip->page_shift;
int native_cmd = 0;
if (command == NAND_CMD_READID || command == NAND_CMD_PARAM ||
command == NAND_CMD_RNDOUT)
addr = (u64)column;
else if (page_addr < 0)
addr = 0;
dev_dbg(ctrl->dev, "cmd 0x%x addr 0x%llx\n", command,
(unsigned long long)addr);
host->last_cmd = command;
host->last_byte = 0;
host->last_addr = addr;
switch (command) {
case NAND_CMD_RESET:
native_cmd = CMD_FLASH_RESET;
break;
case NAND_CMD_STATUS:
native_cmd = CMD_STATUS_READ;
break;
case NAND_CMD_READID:
native_cmd = CMD_DEVICE_ID_READ;
break;
case NAND_CMD_READOOB:
native_cmd = CMD_SPARE_AREA_READ;
break;
case NAND_CMD_ERASE1:
native_cmd = CMD_BLOCK_ERASE;
brcmnand_wp(mtd, 0);
break;
case NAND_CMD_PARAM:
native_cmd = CMD_PARAMETER_READ;
break;
case NAND_CMD_SET_FEATURES:
case NAND_CMD_GET_FEATURES:
brcmnand_low_level_op(host, LL_OP_CMD, command, false);
brcmnand_low_level_op(host, LL_OP_ADDR, column, false);
break;
case NAND_CMD_RNDOUT:
native_cmd = CMD_PARAMETER_CHANGE_COL;
addr &= ~((u64)(FC_BYTES - 1));
if (brcmnand_get_sector_size_1k(host)) {
host->hwcfg.sector_size_1k =
brcmnand_get_sector_size_1k(host);
brcmnand_set_sector_size_1k(host, 0);
}
break;
}
if (!native_cmd)
return;
brcmnand_write_reg(ctrl, BRCMNAND_CMD_EXT_ADDRESS,
(host->cs << 16) | ((addr >> 32) & 0xffff));
(void)brcmnand_read_reg(ctrl, BRCMNAND_CMD_EXT_ADDRESS);
brcmnand_write_reg(ctrl, BRCMNAND_CMD_ADDRESS, lower_32_bits(addr));
(void)brcmnand_read_reg(ctrl, BRCMNAND_CMD_ADDRESS);
brcmnand_send_cmd(host, native_cmd);
brcmnand_waitfunc(mtd, chip);
if (native_cmd == CMD_PARAMETER_READ ||
native_cmd == CMD_PARAMETER_CHANGE_COL) {
u32 *flash_cache = (u32 *)ctrl->flash_cache;
int i;
brcmnand_soc_data_bus_prepare(ctrl->soc);
for (i = 0; i < FC_WORDS; i++)
flash_cache[i] = be32_to_cpu(brcmnand_read_fc(ctrl, i));
brcmnand_soc_data_bus_unprepare(ctrl->soc);
if (host->hwcfg.sector_size_1k)
brcmnand_set_sector_size_1k(host,
host->hwcfg.sector_size_1k);
}
if (command == NAND_CMD_ERASE1)
brcmnand_wp(mtd, 1);
}
static uint8_t brcmnand_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
uint8_t ret = 0;
int addr, offs;
switch (host->last_cmd) {
case NAND_CMD_READID:
if (host->last_byte < 4)
ret = brcmnand_read_reg(ctrl, BRCMNAND_ID) >>
(24 - (host->last_byte << 3));
else if (host->last_byte < 8)
ret = brcmnand_read_reg(ctrl, BRCMNAND_ID_EXT) >>
(56 - (host->last_byte << 3));
break;
case NAND_CMD_READOOB:
ret = oob_reg_read(ctrl, host->last_byte);
break;
case NAND_CMD_STATUS:
ret = brcmnand_read_reg(ctrl, BRCMNAND_INTFC_STATUS) &
INTFC_FLASH_STATUS;
if (wp_on)
ret |= NAND_STATUS_WP;
break;
case NAND_CMD_PARAM:
case NAND_CMD_RNDOUT:
addr = host->last_addr + host->last_byte;
offs = addr & (FC_BYTES - 1);
if (host->last_byte > 0 && offs == 0)
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, addr, -1);
ret = ctrl->flash_cache[offs];
break;
case NAND_CMD_GET_FEATURES:
if (host->last_byte >= ONFI_SUBFEATURE_PARAM_LEN) {
ret = 0;
} else {
bool last = host->last_byte ==
ONFI_SUBFEATURE_PARAM_LEN - 1;
brcmnand_low_level_op(host, LL_OP_RD, 0, last);
ret = brcmnand_read_reg(ctrl, BRCMNAND_LL_RDATA) & 0xff;
}
}
dev_dbg(ctrl->dev, "read byte = 0x%02x\n", ret);
host->last_byte++;
return ret;
}
static void brcmnand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
int i;
for (i = 0; i < len; i++, buf++)
*buf = brcmnand_read_byte(mtd);
}
static void brcmnand_write_buf(struct mtd_info *mtd, const uint8_t *buf,
int len)
{
int i;
struct nand_chip *chip = mtd_to_nand(mtd);
struct brcmnand_host *host = nand_get_controller_data(chip);
switch (host->last_cmd) {
case NAND_CMD_SET_FEATURES:
for (i = 0; i < len; i++)
brcmnand_low_level_op(host, LL_OP_WR, buf[i],
(i + 1) == len);
break;
default:
BUG();
break;
}
}
static int brcmnand_fill_dma_desc(struct brcmnand_host *host,
struct brcm_nand_dma_desc *desc, u64 addr,
dma_addr_t buf, u32 len, u8 dma_cmd,
bool begin, bool end,
dma_addr_t next_desc)
{
memset(desc, 0, sizeof(*desc));
desc->next_desc = lower_32_bits(next_desc);
desc->next_desc_ext = upper_32_bits(next_desc);
desc->cmd_irq = (dma_cmd << 24) |
(end ? (0x03 << 8) : 0) |
(!!begin) | ((!!end) << 1);
#ifdef CONFIG_CPU_BIG_ENDIAN
desc->cmd_irq |= 0x01 << 12;
#endif
desc->dram_addr = lower_32_bits(buf);
desc->dram_addr_ext = upper_32_bits(buf);
desc->tfr_len = len;
desc->total_len = len;
desc->flash_addr = lower_32_bits(addr);
desc->flash_addr_ext = upper_32_bits(addr);
desc->cs = host->cs;
desc->status_valid = 0x01;
return 0;
}
static void brcmnand_dma_run(struct brcmnand_host *host, dma_addr_t desc)
{
struct brcmnand_controller *ctrl = host->ctrl;
unsigned long timeo = msecs_to_jiffies(100);
flash_dma_writel(ctrl, FLASH_DMA_FIRST_DESC, lower_32_bits(desc));
(void)flash_dma_readl(ctrl, FLASH_DMA_FIRST_DESC);
flash_dma_writel(ctrl, FLASH_DMA_FIRST_DESC_EXT, upper_32_bits(desc));
(void)flash_dma_readl(ctrl, FLASH_DMA_FIRST_DESC_EXT);
ctrl->dma_pending = true;
mb();
flash_dma_writel(ctrl, FLASH_DMA_CTRL, 0x03);
if (wait_for_completion_timeout(&ctrl->dma_done, timeo) <= 0) {
dev_err(ctrl->dev,
"timeout waiting for DMA; status %#x, error status %#x\n",
flash_dma_readl(ctrl, FLASH_DMA_STATUS),
flash_dma_readl(ctrl, FLASH_DMA_ERROR_STATUS));
}
ctrl->dma_pending = false;
flash_dma_writel(ctrl, FLASH_DMA_CTRL, 0);
}
static int brcmnand_dma_trans(struct brcmnand_host *host, u64 addr, u32 *buf,
u32 len, u8 dma_cmd)
{
struct brcmnand_controller *ctrl = host->ctrl;
dma_addr_t buf_pa;
int dir = dma_cmd == CMD_PAGE_READ ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
buf_pa = dma_map_single(ctrl->dev, buf, len, dir);
if (dma_mapping_error(ctrl->dev, buf_pa)) {
dev_err(ctrl->dev, "unable to map buffer for DMA\n");
return -ENOMEM;
}
brcmnand_fill_dma_desc(host, ctrl->dma_desc, addr, buf_pa, len,
dma_cmd, true, true, 0);
brcmnand_dma_run(host, ctrl->dma_pa);
dma_unmap_single(ctrl->dev, buf_pa, len, dir);
if (ctrl->dma_desc->status_valid & FLASH_DMA_ECC_ERROR)
return -EBADMSG;
else if (ctrl->dma_desc->status_valid & FLASH_DMA_CORR_ERROR)
return -EUCLEAN;
return 0;
}
static int brcmnand_read_by_pio(struct mtd_info *mtd, struct nand_chip *chip,
u64 addr, unsigned int trans, u32 *buf,
u8 *oob, u64 *err_addr)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
int i, j, ret = 0;
brcmnand_write_reg(ctrl, BRCMNAND_UNCORR_ADDR, 0);
brcmnand_write_reg(ctrl, BRCMNAND_CORR_ADDR, 0);
brcmnand_write_reg(ctrl, BRCMNAND_UNCORR_EXT_ADDR, 0);
brcmnand_write_reg(ctrl, BRCMNAND_CORR_EXT_ADDR, 0);
brcmnand_write_reg(ctrl, BRCMNAND_CMD_EXT_ADDRESS,
(host->cs << 16) | ((addr >> 32) & 0xffff));
(void)brcmnand_read_reg(ctrl, BRCMNAND_CMD_EXT_ADDRESS);
for (i = 0; i < trans; i++, addr += FC_BYTES) {
brcmnand_write_reg(ctrl, BRCMNAND_CMD_ADDRESS,
lower_32_bits(addr));
(void)brcmnand_read_reg(ctrl, BRCMNAND_CMD_ADDRESS);
brcmnand_send_cmd(host, CMD_PAGE_READ);
brcmnand_waitfunc(mtd, chip);
if (likely(buf)) {
brcmnand_soc_data_bus_prepare(ctrl->soc);
for (j = 0; j < FC_WORDS; j++, buf++)
*buf = brcmnand_read_fc(ctrl, j);
brcmnand_soc_data_bus_unprepare(ctrl->soc);
}
if (oob)
oob += read_oob_from_regs(ctrl, i, oob,
mtd->oobsize / trans,
host->hwcfg.sector_size_1k);
if (!ret) {
*err_addr = brcmnand_read_reg(ctrl,
BRCMNAND_UNCORR_ADDR) |
((u64)(brcmnand_read_reg(ctrl,
BRCMNAND_UNCORR_EXT_ADDR)
& 0xffff) << 32);
if (*err_addr)
ret = -EBADMSG;
}
if (!ret) {
*err_addr = brcmnand_read_reg(ctrl,
BRCMNAND_CORR_ADDR) |
((u64)(brcmnand_read_reg(ctrl,
BRCMNAND_CORR_EXT_ADDR)
& 0xffff) << 32);
if (*err_addr)
ret = -EUCLEAN;
}
}
return ret;
}
static int brcmnand_read(struct mtd_info *mtd, struct nand_chip *chip,
u64 addr, unsigned int trans, u32 *buf, u8 *oob)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
u64 err_addr = 0;
int err;
dev_dbg(ctrl->dev, "read %llx -> %p\n", (unsigned long long)addr, buf);
brcmnand_write_reg(ctrl, BRCMNAND_UNCORR_COUNT, 0);
if (has_flash_dma(ctrl) && !oob && flash_dma_buf_ok(buf)) {
err = brcmnand_dma_trans(host, addr, buf, trans * FC_BYTES,
CMD_PAGE_READ);
if (err) {
if (mtd_is_bitflip_or_eccerr(err))
err_addr = addr;
else
return -EIO;
}
} else {
if (oob)
memset(oob, 0x99, mtd->oobsize);
err = brcmnand_read_by_pio(mtd, chip, addr, trans, buf,
oob, &err_addr);
}
if (mtd_is_eccerr(err)) {
dev_dbg(ctrl->dev, "uncorrectable error at 0x%llx\n",
(unsigned long long)err_addr);
mtd->ecc_stats.failed++;
return 0;
}
if (mtd_is_bitflip(err)) {
unsigned int corrected = brcmnand_count_corrected(ctrl);
dev_dbg(ctrl->dev, "corrected error at 0x%llx\n",
(unsigned long long)err_addr);
mtd->ecc_stats.corrected += corrected;
return max(mtd->bitflip_threshold, corrected);
}
return 0;
}
static int brcmnand_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
u8 *oob = oob_required ? (u8 *)chip->oob_poi : NULL;
return brcmnand_read(mtd, chip, host->last_addr,
mtd->writesize >> FC_SHIFT, (u32 *)buf, oob);
}
static int brcmnand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
u8 *oob = oob_required ? (u8 *)chip->oob_poi : NULL;
int ret;
brcmnand_set_ecc_enabled(host, 0);
ret = brcmnand_read(mtd, chip, host->last_addr,
mtd->writesize >> FC_SHIFT, (u32 *)buf, oob);
brcmnand_set_ecc_enabled(host, 1);
return ret;
}
static int brcmnand_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
return brcmnand_read(mtd, chip, (u64)page << chip->page_shift,
mtd->writesize >> FC_SHIFT,
NULL, (u8 *)chip->oob_poi);
}
static int brcmnand_read_oob_raw(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
brcmnand_set_ecc_enabled(host, 0);
brcmnand_read(mtd, chip, (u64)page << chip->page_shift,
mtd->writesize >> FC_SHIFT,
NULL, (u8 *)chip->oob_poi);
brcmnand_set_ecc_enabled(host, 1);
return 0;
}
static int brcmnand_write(struct mtd_info *mtd, struct nand_chip *chip,
u64 addr, const u32 *buf, u8 *oob)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
struct brcmnand_controller *ctrl = host->ctrl;
unsigned int i, j, trans = mtd->writesize >> FC_SHIFT;
int status, ret = 0;
dev_dbg(ctrl->dev, "write %llx <- %p\n", (unsigned long long)addr, buf);
if (unlikely((unsigned long)buf & 0x03)) {
dev_warn(ctrl->dev, "unaligned buffer: %p\n", buf);
buf = (u32 *)((unsigned long)buf & ~0x03);
}
brcmnand_wp(mtd, 0);
for (i = 0; i < ctrl->max_oob; i += 4)
oob_reg_write(ctrl, i, 0xffffffff);
if (has_flash_dma(ctrl) && !oob && flash_dma_buf_ok(buf)) {
if (brcmnand_dma_trans(host, addr, (u32 *)buf,
mtd->writesize, CMD_PROGRAM_PAGE))
ret = -EIO;
goto out;
}
brcmnand_write_reg(ctrl, BRCMNAND_CMD_EXT_ADDRESS,
(host->cs << 16) | ((addr >> 32) & 0xffff));
(void)brcmnand_read_reg(ctrl, BRCMNAND_CMD_EXT_ADDRESS);
for (i = 0; i < trans; i++, addr += FC_BYTES) {
brcmnand_write_reg(ctrl, BRCMNAND_CMD_ADDRESS,
lower_32_bits(addr));
(void)brcmnand_read_reg(ctrl, BRCMNAND_CMD_ADDRESS);
if (buf) {
brcmnand_soc_data_bus_prepare(ctrl->soc);
for (j = 0; j < FC_WORDS; j++, buf++)
brcmnand_write_fc(ctrl, j, *buf);
brcmnand_soc_data_bus_unprepare(ctrl->soc);
} else if (oob) {
for (j = 0; j < FC_WORDS; j++)
brcmnand_write_fc(ctrl, j, 0xffffffff);
}
if (oob) {
oob += write_oob_to_regs(ctrl, i, oob,
mtd->oobsize / trans,
host->hwcfg.sector_size_1k);
}
brcmnand_send_cmd(host, CMD_PROGRAM_PAGE);
status = brcmnand_waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL) {
dev_info(ctrl->dev, "program failed at %llx\n",
(unsigned long long)addr);
ret = -EIO;
goto out;
}
}
out:
brcmnand_wp(mtd, 1);
return ret;
}
static int brcmnand_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required, int page)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
void *oob = oob_required ? chip->oob_poi : NULL;
brcmnand_write(mtd, chip, host->last_addr, (const u32 *)buf, oob);
return 0;
}
static int brcmnand_write_page_raw(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf,
int oob_required, int page)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
void *oob = oob_required ? chip->oob_poi : NULL;
brcmnand_set_ecc_enabled(host, 0);
brcmnand_write(mtd, chip, host->last_addr, (const u32 *)buf, oob);
brcmnand_set_ecc_enabled(host, 1);
return 0;
}
static int brcmnand_write_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
return brcmnand_write(mtd, chip, (u64)page << chip->page_shift,
NULL, chip->oob_poi);
}
static int brcmnand_write_oob_raw(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
struct brcmnand_host *host = nand_get_controller_data(chip);
int ret;
brcmnand_set_ecc_enabled(host, 0);
ret = brcmnand_write(mtd, chip, (u64)page << chip->page_shift, NULL,
(u8 *)chip->oob_poi);
brcmnand_set_ecc_enabled(host, 1);
return ret;
}
static int brcmnand_set_cfg(struct brcmnand_host *host,
struct brcmnand_cfg *cfg)
{
struct brcmnand_controller *ctrl = host->ctrl;
struct nand_chip *chip = &host->chip;
u16 cfg_offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_CFG);
u16 cfg_ext_offs = brcmnand_cs_offset(ctrl, host->cs,
BRCMNAND_CS_CFG_EXT);
u16 acc_control_offs = brcmnand_cs_offset(ctrl, host->cs,
BRCMNAND_CS_ACC_CONTROL);
u8 block_size = 0, page_size = 0, device_size = 0;
u32 tmp;
if (ctrl->block_sizes) {
int i, found;
for (i = 0, found = 0; ctrl->block_sizes[i]; i++)
if (ctrl->block_sizes[i] * 1024 == cfg->block_size) {
block_size = i;
found = 1;
}
if (!found) {
dev_warn(ctrl->dev, "invalid block size %u\n",
cfg->block_size);
return -EINVAL;
}
} else {
block_size = ffs(cfg->block_size) - ffs(BRCMNAND_MIN_BLOCKSIZE);
}
if (cfg->block_size < BRCMNAND_MIN_BLOCKSIZE || (ctrl->max_block_size &&
cfg->block_size > ctrl->max_block_size)) {
dev_warn(ctrl->dev, "invalid block size %u\n",
cfg->block_size);
block_size = 0;
}
if (ctrl->page_sizes) {
int i, found;
for (i = 0, found = 0; ctrl->page_sizes[i]; i++)
if (ctrl->page_sizes[i] == cfg->page_size) {
page_size = i;
found = 1;
}
if (!found) {
dev_warn(ctrl->dev, "invalid page size %u\n",
cfg->page_size);
return -EINVAL;
}
} else {
page_size = ffs(cfg->page_size) - ffs(BRCMNAND_MIN_PAGESIZE);
}
if (cfg->page_size < BRCMNAND_MIN_PAGESIZE || (ctrl->max_page_size &&
cfg->page_size > ctrl->max_page_size)) {
dev_warn(ctrl->dev, "invalid page size %u\n", cfg->page_size);
return -EINVAL;
}
if (fls64(cfg->device_size) < fls64(BRCMNAND_MIN_DEVSIZE)) {
dev_warn(ctrl->dev, "invalid device size 0x%llx\n",
(unsigned long long)cfg->device_size);
return -EINVAL;
}
device_size = fls64(cfg->device_size) - fls64(BRCMNAND_MIN_DEVSIZE);
tmp = (cfg->blk_adr_bytes << CFG_BLK_ADR_BYTES_SHIFT) |
(cfg->col_adr_bytes << CFG_COL_ADR_BYTES_SHIFT) |
(cfg->ful_adr_bytes << CFG_FUL_ADR_BYTES_SHIFT) |
(!!(cfg->device_width == 16) << CFG_BUS_WIDTH_SHIFT) |
(device_size << CFG_DEVICE_SIZE_SHIFT);
if (cfg_offs == cfg_ext_offs) {
tmp |= (page_size << CFG_PAGE_SIZE_SHIFT) |
(block_size << CFG_BLK_SIZE_SHIFT);
nand_writereg(ctrl, cfg_offs, tmp);
} else {
nand_writereg(ctrl, cfg_offs, tmp);
tmp = (page_size << CFG_EXT_PAGE_SIZE_SHIFT) |
(block_size << CFG_EXT_BLK_SIZE_SHIFT);
nand_writereg(ctrl, cfg_ext_offs, tmp);
}
tmp = nand_readreg(ctrl, acc_control_offs);
tmp &= ~brcmnand_ecc_level_mask(ctrl);
tmp |= cfg->ecc_level << NAND_ACC_CONTROL_ECC_SHIFT;
tmp &= ~brcmnand_spare_area_mask(ctrl);
tmp |= cfg->spare_area_size;
nand_writereg(ctrl, acc_control_offs, tmp);
brcmnand_set_sector_size_1k(host, cfg->sector_size_1k);
brcmnand_wr_corr_thresh(host, DIV_ROUND_UP(chip->ecc.strength * 3, 4));
return 0;
}
static void brcmnand_print_cfg(char *buf, struct brcmnand_cfg *cfg)
{
buf += sprintf(buf,
"%lluMiB total, %uKiB blocks, %u%s pages, %uB OOB, %u-bit",
(unsigned long long)cfg->device_size >> 20,
cfg->block_size >> 10,
cfg->page_size >= 1024 ? cfg->page_size >> 10 : cfg->page_size,
cfg->page_size >= 1024 ? "KiB" : "B",
cfg->spare_area_size, cfg->device_width);
if (is_hamming_ecc(cfg))
sprintf(buf, ", Hamming ECC");
else if (cfg->sector_size_1k)
sprintf(buf, ", BCH-%u (1KiB sector)", cfg->ecc_level << 1);
else
sprintf(buf, ", BCH-%u", cfg->ecc_level);
}
static inline int get_blk_adr_bytes(u64 size, u32 writesize)
{
return ALIGN(ilog2(size) - ilog2(writesize), 8) >> 3;
}
static int brcmnand_setup_dev(struct brcmnand_host *host)
{
struct mtd_info *mtd = nand_to_mtd(&host->chip);
struct nand_chip *chip = &host->chip;
struct brcmnand_controller *ctrl = host->ctrl;
struct brcmnand_cfg *cfg = &host->hwcfg;
char msg[128];
u32 offs, tmp, oob_sector;
int ret;
memset(cfg, 0, sizeof(*cfg));
ret = of_property_read_u32(nand_get_flash_node(chip),
"brcm,nand-oob-sector-size",
&oob_sector);
if (ret) {
cfg->spare_area_size = mtd->oobsize /
(mtd->writesize >> FC_SHIFT);
} else {
cfg->spare_area_size = oob_sector;
}
if (cfg->spare_area_size > ctrl->max_oob)
cfg->spare_area_size = ctrl->max_oob;
mtd->oobsize = cfg->spare_area_size * (mtd->writesize >> FC_SHIFT);
cfg->device_size = mtd->size;
cfg->block_size = mtd->erasesize;
cfg->page_size = mtd->writesize;
cfg->device_width = (chip->options & NAND_BUSWIDTH_16) ? 16 : 8;
cfg->col_adr_bytes = 2;
cfg->blk_adr_bytes = get_blk_adr_bytes(mtd->size, mtd->writesize);
switch (chip->ecc.size) {
case 512:
if (chip->ecc.strength == 1)
cfg->ecc_level = 15;
else
cfg->ecc_level = chip->ecc.strength;
cfg->sector_size_1k = 0;
break;
case 1024:
if (!(ctrl->features & BRCMNAND_HAS_1K_SECTORS)) {
dev_err(ctrl->dev, "1KB sectors not supported\n");
return -EINVAL;
}
if (chip->ecc.strength & 0x1) {
dev_err(ctrl->dev,
"odd ECC not supported with 1KB sectors\n");
return -EINVAL;
}
cfg->ecc_level = chip->ecc.strength >> 1;
cfg->sector_size_1k = 1;
break;
default:
dev_err(ctrl->dev, "unsupported ECC size: %d\n",
chip->ecc.size);
return -EINVAL;
}
cfg->ful_adr_bytes = cfg->blk_adr_bytes;
if (mtd->writesize > 512)
cfg->ful_adr_bytes += cfg->col_adr_bytes;
else
cfg->ful_adr_bytes += 1;
ret = brcmnand_set_cfg(host, cfg);
if (ret)
return ret;
brcmnand_set_ecc_enabled(host, 1);
brcmnand_print_cfg(msg, cfg);
dev_info(ctrl->dev, "detected %s\n", msg);
offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_ACC_CONTROL);
tmp = nand_readreg(ctrl, offs);
tmp &= ~ACC_CONTROL_PARTIAL_PAGE;
tmp &= ~ACC_CONTROL_RD_ERASED;
tmp &= ~ACC_CONTROL_FAST_PGM_RDIN;
if (ctrl->features & BRCMNAND_HAS_PREFETCH) {
if (has_flash_dma(ctrl))
tmp &= ~ACC_CONTROL_PREFETCH;
else
tmp |= ACC_CONTROL_PREFETCH;
}
nand_writereg(ctrl, offs, tmp);
return 0;
}
static int brcmnand_init_cs(struct brcmnand_host *host, struct device_node *dn)
{
struct brcmnand_controller *ctrl = host->ctrl;
struct platform_device *pdev = host->pdev;
struct mtd_info *mtd;
struct nand_chip *chip;
int ret;
u16 cfg_offs;
ret = of_property_read_u32(dn, "reg", &host->cs);
if (ret) {
dev_err(&pdev->dev, "can't get chip-select\n");
return -ENXIO;
}
mtd = nand_to_mtd(&host->chip);
chip = &host->chip;
nand_set_flash_node(chip, dn);
nand_set_controller_data(chip, host);
mtd->name = devm_kasprintf(&pdev->dev, GFP_KERNEL, "brcmnand.%d",
host->cs);
mtd->owner = THIS_MODULE;
mtd->dev.parent = &pdev->dev;
chip->IO_ADDR_R = (void __iomem *)0xdeadbeef;
chip->IO_ADDR_W = (void __iomem *)0xdeadbeef;
chip->cmd_ctrl = brcmnand_cmd_ctrl;
chip->cmdfunc = brcmnand_cmdfunc;
chip->waitfunc = brcmnand_waitfunc;
chip->read_byte = brcmnand_read_byte;
chip->read_buf = brcmnand_read_buf;
chip->write_buf = brcmnand_write_buf;
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.read_page = brcmnand_read_page;
chip->ecc.write_page = brcmnand_write_page;
chip->ecc.read_page_raw = brcmnand_read_page_raw;
chip->ecc.write_page_raw = brcmnand_write_page_raw;
chip->ecc.write_oob_raw = brcmnand_write_oob_raw;
chip->ecc.read_oob_raw = brcmnand_read_oob_raw;
chip->ecc.read_oob = brcmnand_read_oob;
chip->ecc.write_oob = brcmnand_write_oob;
chip->controller = &ctrl->controller;
cfg_offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_CFG);
nand_writereg(ctrl, cfg_offs,
nand_readreg(ctrl, cfg_offs) & ~CFG_BUS_WIDTH);
if (nand_scan_ident(mtd, 1, NULL))
return -ENXIO;
chip->options |= NAND_NO_SUBPAGE_WRITE;
chip->options |= NAND_USE_BOUNCE_BUFFER;
if (of_get_nand_on_flash_bbt(dn))
chip->bbt_options |= NAND_BBT_USE_FLASH | NAND_BBT_NO_OOB;
if (brcmnand_setup_dev(host))
return -ENXIO;
chip->ecc.size = host->hwcfg.sector_size_1k ? 1024 : 512;
mtd->bitflip_threshold = 1;
chip->ecc.layout = brcmstb_choose_ecc_layout(host);
if (!chip->ecc.layout)
return -ENXIO;
if (nand_scan_tail(mtd))
return -ENXIO;
return mtd_device_register(mtd, NULL, 0);
}
static void brcmnand_save_restore_cs_config(struct brcmnand_host *host,
int restore)
{
struct brcmnand_controller *ctrl = host->ctrl;
u16 cfg_offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_CFG);
u16 cfg_ext_offs = brcmnand_cs_offset(ctrl, host->cs,
BRCMNAND_CS_CFG_EXT);
u16 acc_control_offs = brcmnand_cs_offset(ctrl, host->cs,
BRCMNAND_CS_ACC_CONTROL);
u16 t1_offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_TIMING1);
u16 t2_offs = brcmnand_cs_offset(ctrl, host->cs, BRCMNAND_CS_TIMING2);
if (restore) {
nand_writereg(ctrl, cfg_offs, host->hwcfg.config);
if (cfg_offs != cfg_ext_offs)
nand_writereg(ctrl, cfg_ext_offs,
host->hwcfg.config_ext);
nand_writereg(ctrl, acc_control_offs, host->hwcfg.acc_control);
nand_writereg(ctrl, t1_offs, host->hwcfg.timing_1);
nand_writereg(ctrl, t2_offs, host->hwcfg.timing_2);
} else {
host->hwcfg.config = nand_readreg(ctrl, cfg_offs);
if (cfg_offs != cfg_ext_offs)
host->hwcfg.config_ext =
nand_readreg(ctrl, cfg_ext_offs);
host->hwcfg.acc_control = nand_readreg(ctrl, acc_control_offs);
host->hwcfg.timing_1 = nand_readreg(ctrl, t1_offs);
host->hwcfg.timing_2 = nand_readreg(ctrl, t2_offs);
}
}
static int brcmnand_suspend(struct device *dev)
{
struct brcmnand_controller *ctrl = dev_get_drvdata(dev);
struct brcmnand_host *host;
list_for_each_entry(host, &ctrl->host_list, node)
brcmnand_save_restore_cs_config(host, 0);
ctrl->nand_cs_nand_select = brcmnand_read_reg(ctrl, BRCMNAND_CS_SELECT);
ctrl->nand_cs_nand_xor = brcmnand_read_reg(ctrl, BRCMNAND_CS_XOR);
ctrl->corr_stat_threshold =
brcmnand_read_reg(ctrl, BRCMNAND_CORR_THRESHOLD);
if (has_flash_dma(ctrl))
ctrl->flash_dma_mode = flash_dma_readl(ctrl, FLASH_DMA_MODE);
return 0;
}
static int brcmnand_resume(struct device *dev)
{
struct brcmnand_controller *ctrl = dev_get_drvdata(dev);
struct brcmnand_host *host;
if (has_flash_dma(ctrl)) {
flash_dma_writel(ctrl, FLASH_DMA_MODE, ctrl->flash_dma_mode);
flash_dma_writel(ctrl, FLASH_DMA_ERROR_STATUS, 0);
}
brcmnand_write_reg(ctrl, BRCMNAND_CS_SELECT, ctrl->nand_cs_nand_select);
brcmnand_write_reg(ctrl, BRCMNAND_CS_XOR, ctrl->nand_cs_nand_xor);
brcmnand_write_reg(ctrl, BRCMNAND_CORR_THRESHOLD,
ctrl->corr_stat_threshold);
if (ctrl->soc) {
ctrl->soc->ctlrdy_ack(ctrl->soc);
ctrl->soc->ctlrdy_set_enabled(ctrl->soc, true);
}
list_for_each_entry(host, &ctrl->host_list, node) {
struct nand_chip *chip = &host->chip;
struct mtd_info *mtd = nand_to_mtd(chip);
brcmnand_save_restore_cs_config(host, 1);
chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
}
return 0;
}
int brcmnand_probe(struct platform_device *pdev, struct brcmnand_soc *soc)
{
struct device *dev = &pdev->dev;
struct device_node *dn = dev->of_node, *child;
struct brcmnand_controller *ctrl;
struct resource *res;
int ret;
if (!dn)
return -ENODEV;
if (!of_match_node(brcmnand_of_match, dn))
return -ENODEV;
ctrl = devm_kzalloc(dev, sizeof(*ctrl), GFP_KERNEL);
if (!ctrl)
return -ENOMEM;
dev_set_drvdata(dev, ctrl);
ctrl->dev = dev;
init_completion(&ctrl->done);
init_completion(&ctrl->dma_done);
spin_lock_init(&ctrl->controller.lock);
init_waitqueue_head(&ctrl->controller.wq);
INIT_LIST_HEAD(&ctrl->host_list);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctrl->nand_base = devm_ioremap_resource(dev, res);
if (IS_ERR(ctrl->nand_base))
return PTR_ERR(ctrl->nand_base);
ctrl->clk = devm_clk_get(dev, "nand");
if (!IS_ERR(ctrl->clk)) {
ret = clk_prepare_enable(ctrl->clk);
if (ret)
return ret;
} else {
ret = PTR_ERR(ctrl->clk);
if (ret == -EPROBE_DEFER)
return ret;
ctrl->clk = NULL;
}
ret = brcmnand_revision_init(ctrl);
if (ret)
goto err;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand-cache");
if (res) {
ctrl->nand_fc = devm_ioremap_resource(dev, res);
if (IS_ERR(ctrl->nand_fc)) {
ret = PTR_ERR(ctrl->nand_fc);
goto err;
}
} else {
ctrl->nand_fc = ctrl->nand_base +
ctrl->reg_offsets[BRCMNAND_FC_BASE];
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "flash-dma");
if (res) {
ctrl->flash_dma_base = devm_ioremap_resource(dev, res);
if (IS_ERR(ctrl->flash_dma_base)) {
ret = PTR_ERR(ctrl->flash_dma_base);
goto err;
}
flash_dma_writel(ctrl, FLASH_DMA_MODE, 1);
flash_dma_writel(ctrl, FLASH_DMA_ERROR_STATUS, 0);
ctrl->dma_desc = dmam_alloc_coherent(dev,
sizeof(*ctrl->dma_desc),
&ctrl->dma_pa, GFP_KERNEL);
if (!ctrl->dma_desc) {
ret = -ENOMEM;
goto err;
}
ctrl->dma_irq = platform_get_irq(pdev, 1);
if ((int)ctrl->dma_irq < 0) {
dev_err(dev, "missing FLASH_DMA IRQ\n");
ret = -ENODEV;
goto err;
}
ret = devm_request_irq(dev, ctrl->dma_irq,
brcmnand_dma_irq, 0, DRV_NAME,
ctrl);
if (ret < 0) {
dev_err(dev, "can't allocate IRQ %d: error %d\n",
ctrl->dma_irq, ret);
goto err;
}
dev_info(dev, "enabling FLASH_DMA\n");
}
brcmnand_rmw_reg(ctrl, BRCMNAND_CS_SELECT,
CS_SELECT_AUTO_DEVICE_ID_CFG | 0xff, 0, 0);
brcmnand_rmw_reg(ctrl, BRCMNAND_CS_XOR, 0xff, 0, 0);
if (ctrl->features & BRCMNAND_HAS_WP) {
if (wp_on == 2)
brcmnand_set_wp(ctrl, false);
} else {
wp_on = 0;
}
ctrl->irq = platform_get_irq(pdev, 0);
if ((int)ctrl->irq < 0) {
dev_err(dev, "no IRQ defined\n");
ret = -ENODEV;
goto err;
}
if (soc) {
ctrl->soc = soc;
ret = devm_request_irq(dev, ctrl->irq, brcmnand_irq, 0,
DRV_NAME, ctrl);
ctrl->soc->ctlrdy_ack(ctrl->soc);
ctrl->soc->ctlrdy_set_enabled(ctrl->soc, true);
} else {
ret = devm_request_irq(dev, ctrl->irq, brcmnand_ctlrdy_irq, 0,
DRV_NAME, ctrl);
}
if (ret < 0) {
dev_err(dev, "can't allocate IRQ %d: error %d\n",
ctrl->irq, ret);
goto err;
}
for_each_available_child_of_node(dn, child) {
if (of_device_is_compatible(child, "brcm,nandcs")) {
struct brcmnand_host *host;
host = devm_kzalloc(dev, sizeof(*host), GFP_KERNEL);
if (!host) {
of_node_put(child);
ret = -ENOMEM;
goto err;
}
host->pdev = pdev;
host->ctrl = ctrl;
ret = brcmnand_init_cs(host, child);
if (ret) {
devm_kfree(dev, host);
continue;
}
list_add_tail(&host->node, &ctrl->host_list);
}
}
if (list_empty(&ctrl->host_list)) {
ret = -ENODEV;
goto err;
}
return 0;
err:
clk_disable_unprepare(ctrl->clk);
return ret;
}
int brcmnand_remove(struct platform_device *pdev)
{
struct brcmnand_controller *ctrl = dev_get_drvdata(&pdev->dev);
struct brcmnand_host *host;
list_for_each_entry(host, &ctrl->host_list, node)
nand_release(nand_to_mtd(&host->chip));
clk_disable_unprepare(ctrl->clk);
dev_set_drvdata(&pdev->dev, NULL);
return 0;
}
