static int clear_poll_bit(void __iomem *addr, u32 mask)
{
int timeout = 0x400;
writel(mask, addr + MXS_CLR_ADDR);
udelay(1);
while ((readl(addr) & mask) && --timeout)
;
return !timeout;
}
static int gpmi_reset_block(void __iomem *reset_addr, bool just_enable)
{
int ret;
int timeout = 0x400;
ret = clear_poll_bit(reset_addr, MODULE_SFTRST);
if (unlikely(ret))
goto error;
writel(MODULE_CLKGATE, reset_addr + MXS_CLR_ADDR);
if (!just_enable) {
writel(MODULE_SFTRST, reset_addr + MXS_SET_ADDR);
udelay(1);
while ((!(readl(reset_addr) & MODULE_CLKGATE)) && --timeout)
;
if (unlikely(!timeout))
goto error;
}
ret = clear_poll_bit(reset_addr, MODULE_SFTRST);
if (unlikely(ret))
goto error;
ret = clear_poll_bit(reset_addr, MODULE_CLKGATE);
if (unlikely(ret))
goto error;
return 0;
error:
pr_err("%s(%p): module reset timeout\n", __func__, reset_addr);
return -ETIMEDOUT;
}
static int __gpmi_enable_clk(struct gpmi_nand_data *this, bool v)
{
struct clk *clk;
int ret;
int i;
for (i = 0; i < GPMI_CLK_MAX; i++) {
clk = this->resources.clock[i];
if (!clk)
break;
if (v) {
ret = clk_prepare_enable(clk);
if (ret)
goto err_clk;
} else {
clk_disable_unprepare(clk);
}
}
return 0;
err_clk:
for (; i > 0; i--)
clk_disable_unprepare(this->resources.clock[i - 1]);
return ret;
}
int gpmi_init(struct gpmi_nand_data *this)
{
struct resources *r = &this->resources;
int ret;
ret = gpmi_enable_clk(this);
if (ret)
goto err_out;
ret = gpmi_reset_block(r->gpmi_regs, false);
if (ret)
goto err_out;
ret = gpmi_reset_block(r->bch_regs, GPMI_IS_MX23(this));
if (ret)
goto err_out;
writel(BM_GPMI_CTRL1_GPMI_MODE, r->gpmi_regs + HW_GPMI_CTRL1_CLR);
writel(BM_GPMI_CTRL1_ATA_IRQRDY_POLARITY,
r->gpmi_regs + HW_GPMI_CTRL1_SET);
writel(BM_GPMI_CTRL1_DEV_RESET, r->gpmi_regs + HW_GPMI_CTRL1_SET);
writel(BM_GPMI_CTRL1_BCH_MODE, r->gpmi_regs + HW_GPMI_CTRL1_SET);
gpmi_disable_clk(this);
return 0;
err_out:
return ret;
}
void gpmi_dump_info(struct gpmi_nand_data *this)
{
struct resources *r = &this->resources;
struct bch_geometry *geo = &this->bch_geometry;
u32 reg;
int i;
pr_err("Show GPMI registers :\n");
for (i = 0; i <= HW_GPMI_DEBUG / 0x10 + 1; i++) {
reg = readl(r->gpmi_regs + i * 0x10);
pr_err("offset 0x%.3x : 0x%.8x\n", i * 0x10, reg);
}
pr_err("BCH Geometry :\n");
pr_err("GF length : %u\n", geo->gf_len);
pr_err("ECC Strength : %u\n", geo->ecc_strength);
pr_err("Page Size in Bytes : %u\n", geo->page_size);
pr_err("Metadata Size in Bytes : %u\n", geo->metadata_size);
pr_err("ECC Chunk Size in Bytes: %u\n", geo->ecc_chunk_size);
pr_err("ECC Chunk Count : %u\n", geo->ecc_chunk_count);
pr_err("Payload Size in Bytes : %u\n", geo->payload_size);
pr_err("Auxiliary Size in Bytes: %u\n", geo->auxiliary_size);
pr_err("Auxiliary Status Offset: %u\n", geo->auxiliary_status_offset);
pr_err("Block Mark Byte Offset : %u\n", geo->block_mark_byte_offset);
pr_err("Block Mark Bit Offset : %u\n", geo->block_mark_bit_offset);
}
int bch_set_geometry(struct gpmi_nand_data *this)
{
struct resources *r = &this->resources;
struct bch_geometry *bch_geo = &this->bch_geometry;
unsigned int block_count;
unsigned int block_size;
unsigned int metadata_size;
unsigned int ecc_strength;
unsigned int page_size;
int ret;
if (common_nfc_set_geometry(this))
return !0;
block_count = bch_geo->ecc_chunk_count - 1;
block_size = bch_geo->ecc_chunk_size;
metadata_size = bch_geo->metadata_size;
ecc_strength = bch_geo->ecc_strength >> 1;
page_size = bch_geo->page_size;
ret = gpmi_enable_clk(this);
if (ret)
goto err_out;
ret = gpmi_reset_block(r->bch_regs, GPMI_IS_MX23(this));
if (ret)
goto err_out;
writel(BF_BCH_FLASH0LAYOUT0_NBLOCKS(block_count)
| BF_BCH_FLASH0LAYOUT0_META_SIZE(metadata_size)
| BF_BCH_FLASH0LAYOUT0_ECC0(ecc_strength, this)
| BF_BCH_FLASH0LAYOUT0_DATA0_SIZE(block_size, this),
r->bch_regs + HW_BCH_FLASH0LAYOUT0);
writel(BF_BCH_FLASH0LAYOUT1_PAGE_SIZE(page_size)
| BF_BCH_FLASH0LAYOUT1_ECCN(ecc_strength, this)
| BF_BCH_FLASH0LAYOUT1_DATAN_SIZE(block_size, this),
r->bch_regs + HW_BCH_FLASH0LAYOUT1);
writel(0, r->bch_regs + HW_BCH_LAYOUTSELECT);
writel(BM_BCH_CTRL_COMPLETE_IRQ_EN,
r->bch_regs + HW_BCH_CTRL_SET);
gpmi_disable_clk(this);
return 0;
err_out:
return ret;
}
static unsigned int ns_to_cycles(unsigned int time,
unsigned int period, unsigned int min)
{
unsigned int k;
k = (time + period - 1) / period;
return max(k, min);
}
static int gpmi_nfc_compute_hardware_timing(struct gpmi_nand_data *this,
struct gpmi_nfc_hardware_timing *hw)
{
struct timing_threshod *nfc = &timing_default_threshold;
struct resources *r = &this->resources;
struct nand_chip *nand = &this->nand;
struct nand_timing target = this->timing;
bool improved_timing_is_available;
unsigned long clock_frequency_in_hz;
unsigned int clock_period_in_ns;
bool dll_use_half_periods;
unsigned int dll_delay_shift;
unsigned int max_sample_delay_in_ns;
unsigned int address_setup_in_cycles;
unsigned int data_setup_in_ns;
unsigned int data_setup_in_cycles;
unsigned int data_hold_in_cycles;
int ideal_sample_delay_in_ns;
unsigned int sample_delay_factor;
int tEYE;
unsigned int min_prop_delay_in_ns = DEF_MIN_PROP_DELAY;
unsigned int max_prop_delay_in_ns = DEF_MAX_PROP_DELAY;
if (nand->numchips > 2) {
target.data_setup_in_ns += 10;
target.data_hold_in_ns += 10;
target.address_setup_in_ns += 10;
} else if (nand->numchips > 1) {
target.data_setup_in_ns += 5;
target.data_hold_in_ns += 5;
target.address_setup_in_ns += 5;
}
improved_timing_is_available =
(target.tREA_in_ns >= 0) &&
(target.tRLOH_in_ns >= 0) &&
(target.tRHOH_in_ns >= 0) ;
nfc->clock_frequency_in_hz = clk_get_rate(r->clock[0]);
clock_frequency_in_hz = nfc->clock_frequency_in_hz;
clock_period_in_ns = NSEC_PER_SEC / clock_frequency_in_hz;
data_setup_in_cycles = ns_to_cycles(target.data_setup_in_ns,
clock_period_in_ns, 1);
data_hold_in_cycles = ns_to_cycles(target.data_hold_in_ns,
clock_period_in_ns, 1);
address_setup_in_cycles = ns_to_cycles(target.address_setup_in_ns,
clock_period_in_ns, 0);
if (clock_period_in_ns > (nfc->max_dll_clock_period_in_ns >> 1)) {
dll_use_half_periods = true;
dll_delay_shift = 3 + 1;
} else {
dll_use_half_periods = false;
dll_delay_shift = 3;
}
if (clock_period_in_ns > nfc->max_dll_clock_period_in_ns)
max_sample_delay_in_ns = 0;
else {
max_sample_delay_in_ns =
(nfc->max_sample_delay_factor * clock_period_in_ns) >>
dll_delay_shift;
if (max_sample_delay_in_ns > nfc->max_dll_delay_in_ns)
max_sample_delay_in_ns = nfc->max_dll_delay_in_ns;
}
if (!improved_timing_is_available) {
ideal_sample_delay_in_ns = target.gpmi_sample_delay_in_ns +
nfc->internal_data_setup_in_ns;
while ((ideal_sample_delay_in_ns > max_sample_delay_in_ns) &&
(data_setup_in_cycles < nfc->max_data_setup_cycles)) {
data_setup_in_cycles++;
ideal_sample_delay_in_ns -= clock_period_in_ns;
if (ideal_sample_delay_in_ns < 0)
ideal_sample_delay_in_ns = 0;
}
sample_delay_factor =
ns_to_cycles(
ideal_sample_delay_in_ns << dll_delay_shift,
clock_period_in_ns, 0);
if (sample_delay_factor > nfc->max_sample_delay_factor)
sample_delay_factor = nfc->max_sample_delay_factor;
goto return_results;
}
max_prop_delay_in_ns += nfc->internal_data_setup_in_ns;
data_setup_in_ns = clock_period_in_ns * data_setup_in_cycles;
tEYE = (int)min_prop_delay_in_ns + (int)target.tRHOH_in_ns +
(int)data_setup_in_ns;
tEYE -= (int)max_prop_delay_in_ns + (int)target.tREA_in_ns;
while ((tEYE <= 0) &&
(data_setup_in_cycles < nfc->max_data_setup_cycles)) {
data_setup_in_cycles++;
data_setup_in_ns += clock_period_in_ns;
tEYE += clock_period_in_ns;
}
ideal_sample_delay_in_ns =
((int)max_prop_delay_in_ns +
(int)target.tREA_in_ns +
(int)min_prop_delay_in_ns +
(int)target.tRHOH_in_ns -
(int)data_setup_in_ns) >> 1;
if (ideal_sample_delay_in_ns < 0)
ideal_sample_delay_in_ns = 0;
while ((ideal_sample_delay_in_ns > max_sample_delay_in_ns) &&
(data_setup_in_cycles < nfc->max_data_setup_cycles)) {
data_setup_in_cycles++;
data_setup_in_ns += clock_period_in_ns;
tEYE += clock_period_in_ns;
ideal_sample_delay_in_ns -= (clock_period_in_ns >> 1);
if (ideal_sample_delay_in_ns < 0)
ideal_sample_delay_in_ns = 0;
}
sample_delay_factor =
ns_to_cycles(ideal_sample_delay_in_ns << dll_delay_shift,
clock_period_in_ns, 0);
if (sample_delay_factor > nfc->max_sample_delay_factor)
sample_delay_factor = nfc->max_sample_delay_factor;
#define IDEAL_DELAY ((int) ideal_sample_delay_in_ns)
#define QUANTIZED_DELAY \
((int) ((sample_delay_factor * clock_period_in_ns) >> \
dll_delay_shift))
#define DELAY_ERROR (abs(QUANTIZED_DELAY - IDEAL_DELAY))
#define SAMPLE_IS_NOT_WITHIN_THE_EYE (DELAY_ERROR > (tEYE >> 1))
while (SAMPLE_IS_NOT_WITHIN_THE_EYE &&
(data_setup_in_cycles < nfc->max_data_setup_cycles)) {
if (QUANTIZED_DELAY > IDEAL_DELAY) {
if (sample_delay_factor != 0)
sample_delay_factor--;
continue;
}
data_setup_in_cycles++;
data_setup_in_ns += clock_period_in_ns;
tEYE += clock_period_in_ns;
ideal_sample_delay_in_ns -= (clock_period_in_ns >> 1);
ideal_sample_delay_in_ns -= clock_period_in_ns;
if (ideal_sample_delay_in_ns < 0)
ideal_sample_delay_in_ns = 0;
sample_delay_factor =
ns_to_cycles(
ideal_sample_delay_in_ns << dll_delay_shift,
clock_period_in_ns, 0);
if (sample_delay_factor > nfc->max_sample_delay_factor)
sample_delay_factor = nfc->max_sample_delay_factor;
}
return_results:
hw->data_setup_in_cycles = data_setup_in_cycles;
hw->data_hold_in_cycles = data_hold_in_cycles;
hw->address_setup_in_cycles = address_setup_in_cycles;
hw->use_half_periods = dll_use_half_periods;
hw->sample_delay_factor = sample_delay_factor;
hw->device_busy_timeout = GPMI_DEFAULT_BUSY_TIMEOUT;
hw->wrn_dly_sel = BV_GPMI_CTRL1_WRN_DLY_SEL_4_TO_8NS;
return 0;
}
static void gpmi_compute_edo_timing(struct gpmi_nand_data *this,
struct gpmi_nfc_hardware_timing *hw)
{
struct resources *r = &this->resources;
unsigned long rate = clk_get_rate(r->clock[0]);
int mode = this->timing_mode;
int dll_threshold = 16;
unsigned long delay;
unsigned long clk_period;
int t_rea;
int c = 4;
int t_rp;
int rp;
hw->data_setup_in_cycles = 1;
hw->data_hold_in_cycles = 1;
hw->address_setup_in_cycles = ((mode == 5) ? 1 : 0);
hw->device_busy_timeout = 0x9000;
hw->wrn_dly_sel = BV_GPMI_CTRL1_WRN_DLY_SEL_NO_DELAY;
if (GPMI_IS_MX6Q(this))
dll_threshold = 12;
clk_period = NSEC_PER_SEC / (rate / 10);
dll_threshold *= 10;
t_rea = ((mode == 5) ? 16 : 20) * 10;
c *= 10;
t_rp = clk_period * 1;
if (clk_period > dll_threshold) {
hw->use_half_periods = 1;
rp = clk_period / 2;
} else {
hw->use_half_periods = 0;
rp = clk_period;
}
delay = (((t_rea + c - t_rp) * 8) * 10) / rp;
delay = (delay + 5) / 10;
hw->sample_delay_factor = delay;
}
static int enable_edo_mode(struct gpmi_nand_data *this, int mode)
{
struct resources *r = &this->resources;
struct nand_chip *nand = &this->nand;
struct mtd_info *mtd = &this->mtd;
uint8_t feature[ONFI_SUBFEATURE_PARAM_LEN] = {};
unsigned long rate;
int ret;
nand->select_chip(mtd, 0);
feature[0] = mode;
ret = nand->onfi_set_features(mtd, nand,
ONFI_FEATURE_ADDR_TIMING_MODE, feature);
if (ret)
goto err_out;
memset(feature, 0, ONFI_SUBFEATURE_PARAM_LEN);
ret = nand->onfi_get_features(mtd, nand,
ONFI_FEATURE_ADDR_TIMING_MODE, feature);
if (ret || feature[0] != mode)
goto err_out;
nand->select_chip(mtd, -1);
rate = (mode == 5) ? 100000000 : 80000000;
clk_set_rate(r->clock[0], rate);
this->flags &= ~GPMI_TIMING_INIT_OK;
this->flags |= GPMI_ASYNC_EDO_ENABLED;
this->timing_mode = mode;
dev_info(this->dev, "enable the asynchronous EDO mode %d\n", mode);
return 0;
err_out:
nand->select_chip(mtd, -1);
dev_err(this->dev, "mode:%d ,failed in set feature.\n", mode);
return -EINVAL;
}
int gpmi_extra_init(struct gpmi_nand_data *this)
{
struct nand_chip *chip = &this->nand;
if (GPMI_IS_MX6Q(this) && chip->onfi_version) {
int mode = onfi_get_async_timing_mode(chip);
if (mode & ONFI_TIMING_MODE_5)
mode = 5;
else if (mode & ONFI_TIMING_MODE_4)
mode = 4;
else
return 0;
return enable_edo_mode(this, mode);
}
return 0;
}
void gpmi_begin(struct gpmi_nand_data *this)
{
struct resources *r = &this->resources;
void __iomem *gpmi_regs = r->gpmi_regs;
unsigned int clock_period_in_ns;
uint32_t reg;
unsigned int dll_wait_time_in_us;
struct gpmi_nfc_hardware_timing hw;
int ret;
ret = gpmi_enable_clk(this);
if (ret) {
pr_err("We failed in enable the clk\n");
goto err_out;
}
if (this->flags & GPMI_TIMING_INIT_OK)
return;
this->flags |= GPMI_TIMING_INIT_OK;
if (this->flags & GPMI_ASYNC_EDO_ENABLED)
gpmi_compute_edo_timing(this, &hw);
else
gpmi_nfc_compute_hardware_timing(this, &hw);
reg = BF_GPMI_TIMING0_ADDRESS_SETUP(hw.address_setup_in_cycles) |
BF_GPMI_TIMING0_DATA_HOLD(hw.data_hold_in_cycles) |
BF_GPMI_TIMING0_DATA_SETUP(hw.data_setup_in_cycles) ;
writel(reg, gpmi_regs + HW_GPMI_TIMING0);
writel(BF_GPMI_TIMING1_BUSY_TIMEOUT(hw.device_busy_timeout),
gpmi_regs + HW_GPMI_TIMING1);
writel(BM_GPMI_CTRL1_WRN_DLY_SEL, gpmi_regs + HW_GPMI_CTRL1_CLR);
writel(BF_GPMI_CTRL1_WRN_DLY_SEL(hw.wrn_dly_sel),
gpmi_regs + HW_GPMI_CTRL1_SET);
writel(BM_GPMI_CTRL1_DLL_ENABLE, gpmi_regs + HW_GPMI_CTRL1_CLR);
reg = BM_GPMI_CTRL1_RDN_DELAY | BM_GPMI_CTRL1_HALF_PERIOD;
writel(reg, gpmi_regs + HW_GPMI_CTRL1_CLR);
if (!hw.sample_delay_factor)
return;
reg = ((hw.use_half_periods) ? BM_GPMI_CTRL1_HALF_PERIOD : 0)
| BF_GPMI_CTRL1_RDN_DELAY(hw.sample_delay_factor);
writel(reg, gpmi_regs + HW_GPMI_CTRL1_SET);
writel(BM_GPMI_CTRL1_DLL_ENABLE, gpmi_regs + HW_GPMI_CTRL1_SET);
clock_period_in_ns = NSEC_PER_SEC / clk_get_rate(r->clock[0]);
dll_wait_time_in_us = (clock_period_in_ns * 64) / 1000;
if (!dll_wait_time_in_us)
dll_wait_time_in_us = 1;
udelay(dll_wait_time_in_us);
err_out:
return;
}
void gpmi_end(struct gpmi_nand_data *this)
{
gpmi_disable_clk(this);
}
void gpmi_clear_bch(struct gpmi_nand_data *this)
{
struct resources *r = &this->resources;
writel(BM_BCH_CTRL_COMPLETE_IRQ, r->bch_regs + HW_BCH_CTRL_CLR);
}
int gpmi_is_ready(struct gpmi_nand_data *this, unsigned chip)
{
struct resources *r = &this->resources;
uint32_t mask = 0;
uint32_t reg = 0;
if (GPMI_IS_MX23(this)) {
mask = MX23_BM_GPMI_DEBUG_READY0 << chip;
reg = readl(r->gpmi_regs + HW_GPMI_DEBUG);
} else if (GPMI_IS_MX28(this) || GPMI_IS_MX6Q(this)) {
mask = MX28_BF_GPMI_STAT_READY_BUSY(1 << chip);
reg = readl(r->gpmi_regs + HW_GPMI_STAT);
} else
pr_err("unknow arch.\n");
return reg & mask;
}
static inline void set_dma_type(struct gpmi_nand_data *this,
enum dma_ops_type type)
{
this->last_dma_type = this->dma_type;
this->dma_type = type;
}
int gpmi_send_command(struct gpmi_nand_data *this)
{
struct dma_chan *channel = get_dma_chan(this);
struct dma_async_tx_descriptor *desc;
struct scatterlist *sgl;
int chip = this->current_chip;
u32 pio[3];
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(BV_GPMI_CTRL0_COMMAND_MODE__WRITE)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(BV_GPMI_CTRL0_ADDRESS__NAND_CLE)
| BM_GPMI_CTRL0_ADDRESS_INCREMENT
| BF_GPMI_CTRL0_XFER_COUNT(this->command_length);
pio[1] = pio[2] = 0;
desc = dmaengine_prep_slave_sg(channel,
(struct scatterlist *)pio,
ARRAY_SIZE(pio), DMA_TRANS_NONE, 0);
if (!desc) {
pr_err("step 1 error\n");
return -1;
}
sgl = &this->cmd_sgl;
sg_init_one(sgl, this->cmd_buffer, this->command_length);
dma_map_sg(this->dev, sgl, 1, DMA_TO_DEVICE);
desc = dmaengine_prep_slave_sg(channel,
sgl, 1, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
pr_err("step 2 error\n");
return -1;
}
set_dma_type(this, DMA_FOR_COMMAND);
return start_dma_without_bch_irq(this, desc);
}
int gpmi_send_data(struct gpmi_nand_data *this)
{
struct dma_async_tx_descriptor *desc;
struct dma_chan *channel = get_dma_chan(this);
int chip = this->current_chip;
uint32_t command_mode;
uint32_t address;
u32 pio[2];
command_mode = BV_GPMI_CTRL0_COMMAND_MODE__WRITE;
address = BV_GPMI_CTRL0_ADDRESS__NAND_DATA;
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(command_mode)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(address)
| BF_GPMI_CTRL0_XFER_COUNT(this->upper_len);
pio[1] = 0;
desc = dmaengine_prep_slave_sg(channel, (struct scatterlist *)pio,
ARRAY_SIZE(pio), DMA_TRANS_NONE, 0);
if (!desc) {
pr_err("step 1 error\n");
return -1;
}
prepare_data_dma(this, DMA_TO_DEVICE);
desc = dmaengine_prep_slave_sg(channel, &this->data_sgl,
1, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
pr_err("step 2 error\n");
return -1;
}
set_dma_type(this, DMA_FOR_WRITE_DATA);
return start_dma_without_bch_irq(this, desc);
}
int gpmi_read_data(struct gpmi_nand_data *this)
{
struct dma_async_tx_descriptor *desc;
struct dma_chan *channel = get_dma_chan(this);
int chip = this->current_chip;
u32 pio[2];
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(BV_GPMI_CTRL0_COMMAND_MODE__READ)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(BV_GPMI_CTRL0_ADDRESS__NAND_DATA)
| BF_GPMI_CTRL0_XFER_COUNT(this->upper_len);
pio[1] = 0;
desc = dmaengine_prep_slave_sg(channel,
(struct scatterlist *)pio,
ARRAY_SIZE(pio), DMA_TRANS_NONE, 0);
if (!desc) {
pr_err("step 1 error\n");
return -1;
}
prepare_data_dma(this, DMA_FROM_DEVICE);
desc = dmaengine_prep_slave_sg(channel, &this->data_sgl,
1, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
pr_err("step 2 error\n");
return -1;
}
set_dma_type(this, DMA_FOR_READ_DATA);
return start_dma_without_bch_irq(this, desc);
}
int gpmi_send_page(struct gpmi_nand_data *this,
dma_addr_t payload, dma_addr_t auxiliary)
{
struct bch_geometry *geo = &this->bch_geometry;
uint32_t command_mode;
uint32_t address;
uint32_t ecc_command;
uint32_t buffer_mask;
struct dma_async_tx_descriptor *desc;
struct dma_chan *channel = get_dma_chan(this);
int chip = this->current_chip;
u32 pio[6];
command_mode = BV_GPMI_CTRL0_COMMAND_MODE__WRITE;
address = BV_GPMI_CTRL0_ADDRESS__NAND_DATA;
ecc_command = BV_GPMI_ECCCTRL_ECC_CMD__BCH_ENCODE;
buffer_mask = BV_GPMI_ECCCTRL_BUFFER_MASK__BCH_PAGE |
BV_GPMI_ECCCTRL_BUFFER_MASK__BCH_AUXONLY;
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(command_mode)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(address)
| BF_GPMI_CTRL0_XFER_COUNT(0);
pio[1] = 0;
pio[2] = BM_GPMI_ECCCTRL_ENABLE_ECC
| BF_GPMI_ECCCTRL_ECC_CMD(ecc_command)
| BF_GPMI_ECCCTRL_BUFFER_MASK(buffer_mask);
pio[3] = geo->page_size;
pio[4] = payload;
pio[5] = auxiliary;
desc = dmaengine_prep_slave_sg(channel,
(struct scatterlist *)pio,
ARRAY_SIZE(pio), DMA_TRANS_NONE,
DMA_CTRL_ACK);
if (!desc) {
pr_err("step 2 error\n");
return -1;
}
set_dma_type(this, DMA_FOR_WRITE_ECC_PAGE);
return start_dma_with_bch_irq(this, desc);
}
int gpmi_read_page(struct gpmi_nand_data *this,
dma_addr_t payload, dma_addr_t auxiliary)
{
struct bch_geometry *geo = &this->bch_geometry;
uint32_t command_mode;
uint32_t address;
uint32_t ecc_command;
uint32_t buffer_mask;
struct dma_async_tx_descriptor *desc;
struct dma_chan *channel = get_dma_chan(this);
int chip = this->current_chip;
u32 pio[6];
command_mode = BV_GPMI_CTRL0_COMMAND_MODE__WAIT_FOR_READY;
address = BV_GPMI_CTRL0_ADDRESS__NAND_DATA;
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(command_mode)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(address)
| BF_GPMI_CTRL0_XFER_COUNT(0);
pio[1] = 0;
desc = dmaengine_prep_slave_sg(channel,
(struct scatterlist *)pio, 2,
DMA_TRANS_NONE, 0);
if (!desc) {
pr_err("step 1 error\n");
return -1;
}
command_mode = BV_GPMI_CTRL0_COMMAND_MODE__READ;
address = BV_GPMI_CTRL0_ADDRESS__NAND_DATA;
ecc_command = BV_GPMI_ECCCTRL_ECC_CMD__BCH_DECODE;
buffer_mask = BV_GPMI_ECCCTRL_BUFFER_MASK__BCH_PAGE
| BV_GPMI_ECCCTRL_BUFFER_MASK__BCH_AUXONLY;
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(command_mode)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(address)
| BF_GPMI_CTRL0_XFER_COUNT(geo->page_size);
pio[1] = 0;
pio[2] = BM_GPMI_ECCCTRL_ENABLE_ECC
| BF_GPMI_ECCCTRL_ECC_CMD(ecc_command)
| BF_GPMI_ECCCTRL_BUFFER_MASK(buffer_mask);
pio[3] = geo->page_size;
pio[4] = payload;
pio[5] = auxiliary;
desc = dmaengine_prep_slave_sg(channel,
(struct scatterlist *)pio,
ARRAY_SIZE(pio), DMA_TRANS_NONE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
pr_err("step 2 error\n");
return -1;
}
command_mode = BV_GPMI_CTRL0_COMMAND_MODE__WAIT_FOR_READY;
address = BV_GPMI_CTRL0_ADDRESS__NAND_DATA;
pio[0] = BF_GPMI_CTRL0_COMMAND_MODE(command_mode)
| BM_GPMI_CTRL0_WORD_LENGTH
| BF_GPMI_CTRL0_CS(chip, this)
| BF_GPMI_CTRL0_LOCK_CS(LOCK_CS_ENABLE, this)
| BF_GPMI_CTRL0_ADDRESS(address)
| BF_GPMI_CTRL0_XFER_COUNT(geo->page_size);
pio[1] = 0;
pio[2] = 0;
desc = dmaengine_prep_slave_sg(channel,
(struct scatterlist *)pio, 3,
DMA_TRANS_NONE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
pr_err("step 3 error\n");
return -1;
}
set_dma_type(this, DMA_FOR_READ_ECC_PAGE);
return start_dma_with_bch_irq(this, desc);
}
