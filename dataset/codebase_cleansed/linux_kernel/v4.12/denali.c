static inline struct denali_nand_info *mtd_to_denali(struct mtd_info *mtd)
{
return container_of(mtd_to_nand(mtd), struct denali_nand_info, nand);
}
static void index_addr(struct denali_nand_info *denali,
uint32_t address, uint32_t data)
{
iowrite32(address, denali->flash_mem);
iowrite32(data, denali->flash_mem + 0x10);
}
static void index_addr_read_data(struct denali_nand_info *denali,
uint32_t address, uint32_t *pdata)
{
iowrite32(address, denali->flash_mem);
*pdata = ioread32(denali->flash_mem + 0x10);
}
static void reset_buf(struct denali_nand_info *denali)
{
denali->buf.head = denali->buf.tail = 0;
}
static void write_byte_to_buf(struct denali_nand_info *denali, uint8_t byte)
{
denali->buf.buf[denali->buf.tail++] = byte;
}
static void read_status(struct denali_nand_info *denali)
{
uint32_t cmd;
reset_buf(denali);
cmd = ioread32(denali->flash_reg + WRITE_PROTECT);
if (cmd)
write_byte_to_buf(denali, NAND_STATUS_WP);
else
write_byte_to_buf(denali, 0);
}
static void reset_bank(struct denali_nand_info *denali)
{
uint32_t irq_status;
uint32_t irq_mask = INTR__RST_COMP | INTR__TIME_OUT;
clear_interrupts(denali);
iowrite32(1 << denali->flash_bank, denali->flash_reg + DEVICE_RESET);
irq_status = wait_for_irq(denali, irq_mask);
if (irq_status & INTR__TIME_OUT)
dev_err(denali->dev, "reset bank failed.\n");
}
static uint16_t denali_nand_reset(struct denali_nand_info *denali)
{
int i;
for (i = 0; i < denali->max_banks; i++)
iowrite32(INTR__RST_COMP | INTR__TIME_OUT,
denali->flash_reg + INTR_STATUS(i));
for (i = 0; i < denali->max_banks; i++) {
iowrite32(1 << i, denali->flash_reg + DEVICE_RESET);
while (!(ioread32(denali->flash_reg + INTR_STATUS(i)) &
(INTR__RST_COMP | INTR__TIME_OUT)))
cpu_relax();
if (ioread32(denali->flash_reg + INTR_STATUS(i)) &
INTR__TIME_OUT)
dev_dbg(denali->dev,
"NAND Reset operation timed out on bank %d\n", i);
}
for (i = 0; i < denali->max_banks; i++)
iowrite32(INTR__RST_COMP | INTR__TIME_OUT,
denali->flash_reg + INTR_STATUS(i));
return PASS;
}
static void nand_onfi_timing_set(struct denali_nand_info *denali,
uint16_t mode)
{
uint16_t Trea[6] = {40, 30, 25, 20, 20, 16};
uint16_t Trp[6] = {50, 25, 17, 15, 12, 10};
uint16_t Treh[6] = {30, 15, 15, 10, 10, 7};
uint16_t Trc[6] = {100, 50, 35, 30, 25, 20};
uint16_t Trhoh[6] = {0, 15, 15, 15, 15, 15};
uint16_t Trloh[6] = {0, 0, 0, 0, 5, 5};
uint16_t Tcea[6] = {100, 45, 30, 25, 25, 25};
uint16_t Tadl[6] = {200, 100, 100, 100, 70, 70};
uint16_t Trhw[6] = {200, 100, 100, 100, 100, 100};
uint16_t Trhz[6] = {200, 100, 100, 100, 100, 100};
uint16_t Twhr[6] = {120, 80, 80, 60, 60, 60};
uint16_t Tcs[6] = {70, 35, 25, 25, 20, 15};
uint16_t data_invalid_rhoh, data_invalid_rloh, data_invalid;
uint16_t dv_window = 0;
uint16_t en_lo, en_hi;
uint16_t acc_clks;
uint16_t addr_2_data, re_2_we, re_2_re, we_2_re, cs_cnt;
en_lo = CEIL_DIV(Trp[mode], CLK_X);
en_hi = CEIL_DIV(Treh[mode], CLK_X);
#if ONFI_BLOOM_TIME
if ((en_hi * CLK_X) < (Treh[mode] + 2))
en_hi++;
#endif
if ((en_lo + en_hi) * CLK_X < Trc[mode])
en_lo += CEIL_DIV((Trc[mode] - (en_lo + en_hi) * CLK_X), CLK_X);
if ((en_lo + en_hi) < CLK_MULTI)
en_lo += CLK_MULTI - en_lo - en_hi;
while (dv_window < 8) {
data_invalid_rhoh = en_lo * CLK_X + Trhoh[mode];
data_invalid_rloh = (en_lo + en_hi) * CLK_X + Trloh[mode];
data_invalid = data_invalid_rhoh < data_invalid_rloh ?
data_invalid_rhoh : data_invalid_rloh;
dv_window = data_invalid - Trea[mode];
if (dv_window < 8)
en_lo++;
}
acc_clks = CEIL_DIV(Trea[mode], CLK_X);
while (acc_clks * CLK_X - Trea[mode] < 3)
acc_clks++;
if (data_invalid - acc_clks * CLK_X < 2)
dev_warn(denali->dev, "%s, Line %d: Warning!\n",
__FILE__, __LINE__);
addr_2_data = CEIL_DIV(Tadl[mode], CLK_X);
re_2_we = CEIL_DIV(Trhw[mode], CLK_X);
re_2_re = CEIL_DIV(Trhz[mode], CLK_X);
we_2_re = CEIL_DIV(Twhr[mode], CLK_X);
cs_cnt = CEIL_DIV((Tcs[mode] - Trp[mode]), CLK_X);
if (cs_cnt == 0)
cs_cnt = 1;
if (Tcea[mode]) {
while (cs_cnt * CLK_X + Trea[mode] < Tcea[mode])
cs_cnt++;
}
#if MODE5_WORKAROUND
if (mode == 5)
acc_clks = 5;
#endif
if (ioread32(denali->flash_reg + MANUFACTURER_ID) == 0 &&
ioread32(denali->flash_reg + DEVICE_ID) == 0x88)
acc_clks = 6;
iowrite32(acc_clks, denali->flash_reg + ACC_CLKS);
iowrite32(re_2_we, denali->flash_reg + RE_2_WE);
iowrite32(re_2_re, denali->flash_reg + RE_2_RE);
iowrite32(we_2_re, denali->flash_reg + WE_2_RE);
iowrite32(addr_2_data, denali->flash_reg + ADDR_2_DATA);
iowrite32(en_lo, denali->flash_reg + RDWR_EN_LO_CNT);
iowrite32(en_hi, denali->flash_reg + RDWR_EN_HI_CNT);
iowrite32(cs_cnt, denali->flash_reg + CS_SETUP_CNT);
}
static uint16_t get_onfi_nand_para(struct denali_nand_info *denali)
{
int i;
if (!(ioread32(denali->flash_reg + ONFI_TIMING_MODE) &
ONFI_TIMING_MODE__VALUE))
return FAIL;
for (i = 5; i > 0; i--) {
if (ioread32(denali->flash_reg + ONFI_TIMING_MODE) &
(0x01 << i))
break;
}
nand_onfi_timing_set(denali, i);
return PASS;
}
static void get_samsung_nand_para(struct denali_nand_info *denali,
uint8_t device_id)
{
if (device_id == 0xd3) {
iowrite32(5, denali->flash_reg + ACC_CLKS);
iowrite32(20, denali->flash_reg + RE_2_WE);
iowrite32(12, denali->flash_reg + WE_2_RE);
iowrite32(14, denali->flash_reg + ADDR_2_DATA);
iowrite32(3, denali->flash_reg + RDWR_EN_LO_CNT);
iowrite32(2, denali->flash_reg + RDWR_EN_HI_CNT);
iowrite32(2, denali->flash_reg + CS_SETUP_CNT);
}
}
static void get_toshiba_nand_para(struct denali_nand_info *denali)
{
if ((ioread32(denali->flash_reg + DEVICE_MAIN_AREA_SIZE) == 4096) &&
(ioread32(denali->flash_reg + DEVICE_SPARE_AREA_SIZE) == 64))
iowrite32(216, denali->flash_reg + DEVICE_SPARE_AREA_SIZE);
}
static void get_hynix_nand_para(struct denali_nand_info *denali,
uint8_t device_id)
{
switch (device_id) {
case 0xD5:
case 0xD7:
iowrite32(128, denali->flash_reg + PAGES_PER_BLOCK);
iowrite32(4096, denali->flash_reg + DEVICE_MAIN_AREA_SIZE);
iowrite32(224, denali->flash_reg + DEVICE_SPARE_AREA_SIZE);
iowrite32(0, denali->flash_reg + DEVICE_WIDTH);
break;
default:
dev_warn(denali->dev,
"Unknown Hynix NAND (Device ID: 0x%x).\n"
"Will use default parameter values instead.\n",
device_id);
}
}
static void find_valid_banks(struct denali_nand_info *denali)
{
uint32_t id[denali->max_banks];
int i;
denali->total_used_banks = 1;
for (i = 0; i < denali->max_banks; i++) {
index_addr(denali, MODE_11 | (i << 24) | 0, 0x90);
index_addr(denali, MODE_11 | (i << 24) | 1, 0);
index_addr_read_data(denali, MODE_11 | (i << 24) | 2, &id[i]);
dev_dbg(denali->dev,
"Return 1st ID for bank[%d]: %x\n", i, id[i]);
if (i == 0) {
if (!(id[i] & 0x0ff))
break;
} else {
if ((id[i] & 0x0ff) == (id[0] & 0x0ff))
denali->total_used_banks++;
else
break;
}
}
if (denali->platform == INTEL_CE4100) {
if (denali->total_used_banks != 1) {
dev_err(denali->dev,
"Sorry, Intel CE4100 only supports a single NAND device.\n");
BUG();
}
}
dev_dbg(denali->dev,
"denali->total_used_banks: %d\n", denali->total_used_banks);
}
static void detect_max_banks(struct denali_nand_info *denali)
{
uint32_t features = ioread32(denali->flash_reg + FEATURES);
denali->max_banks = 1 << (features & FEATURES__N_BANKS);
if (denali->revision < 0x0501)
denali->max_banks <<= 1;
}
static uint16_t denali_nand_timing_set(struct denali_nand_info *denali)
{
uint16_t status = PASS;
uint32_t id_bytes[8], addr;
uint8_t maf_id, device_id;
int i;
addr = MODE_11 | BANK(denali->flash_bank);
index_addr(denali, addr | 0, 0x90);
index_addr(denali, addr | 1, 0);
for (i = 0; i < 8; i++)
index_addr_read_data(denali, addr | 2, &id_bytes[i]);
maf_id = id_bytes[0];
device_id = id_bytes[1];
if (ioread32(denali->flash_reg + ONFI_DEVICE_NO_OF_LUNS) &
ONFI_DEVICE_NO_OF_LUNS__ONFI_DEVICE) {
if (FAIL == get_onfi_nand_para(denali))
return FAIL;
} else if (maf_id == 0xEC) {
get_samsung_nand_para(denali, device_id);
} else if (maf_id == 0x98) {
get_toshiba_nand_para(denali);
} else if (maf_id == 0xAD) {
get_hynix_nand_para(denali, device_id);
}
dev_info(denali->dev,
"Dump timing register values:\n"
"acc_clks: %d, re_2_we: %d, re_2_re: %d\n"
"we_2_re: %d, addr_2_data: %d, rdwr_en_lo_cnt: %d\n"
"rdwr_en_hi_cnt: %d, cs_setup_cnt: %d\n",
ioread32(denali->flash_reg + ACC_CLKS),
ioread32(denali->flash_reg + RE_2_WE),
ioread32(denali->flash_reg + RE_2_RE),
ioread32(denali->flash_reg + WE_2_RE),
ioread32(denali->flash_reg + ADDR_2_DATA),
ioread32(denali->flash_reg + RDWR_EN_LO_CNT),
ioread32(denali->flash_reg + RDWR_EN_HI_CNT),
ioread32(denali->flash_reg + CS_SETUP_CNT));
find_valid_banks(denali);
if (onfi_timing_mode != NAND_DEFAULT_TIMINGS)
nand_onfi_timing_set(denali, onfi_timing_mode);
return status;
}
static void denali_set_intr_modes(struct denali_nand_info *denali,
uint16_t INT_ENABLE)
{
if (INT_ENABLE)
iowrite32(1, denali->flash_reg + GLOBAL_INT_ENABLE);
else
iowrite32(0, denali->flash_reg + GLOBAL_INT_ENABLE);
}
static inline bool is_flash_bank_valid(int flash_bank)
{
return flash_bank >= 0 && flash_bank < 4;
}
static void denali_irq_init(struct denali_nand_info *denali)
{
uint32_t int_mask;
int i;
denali_set_intr_modes(denali, false);
int_mask = DENALI_IRQ_ALL;
for (i = 0; i < denali->max_banks; ++i)
iowrite32(0xFFFF, denali->flash_reg + INTR_STATUS(i));
denali_irq_enable(denali, int_mask);
}
static void denali_irq_cleanup(int irqnum, struct denali_nand_info *denali)
{
denali_set_intr_modes(denali, false);
}
static void denali_irq_enable(struct denali_nand_info *denali,
uint32_t int_mask)
{
int i;
for (i = 0; i < denali->max_banks; ++i)
iowrite32(int_mask, denali->flash_reg + INTR_EN(i));
}
static inline uint32_t denali_irq_detected(struct denali_nand_info *denali)
{
return read_interrupt_status(denali) & DENALI_IRQ_ALL;
}
static inline void clear_interrupt(struct denali_nand_info *denali,
uint32_t irq_mask)
{
uint32_t intr_status_reg;
intr_status_reg = INTR_STATUS(denali->flash_bank);
iowrite32(irq_mask, denali->flash_reg + intr_status_reg);
}
static void clear_interrupts(struct denali_nand_info *denali)
{
uint32_t status;
spin_lock_irq(&denali->irq_lock);
status = read_interrupt_status(denali);
clear_interrupt(denali, status);
denali->irq_status = 0x0;
spin_unlock_irq(&denali->irq_lock);
}
static uint32_t read_interrupt_status(struct denali_nand_info *denali)
{
uint32_t intr_status_reg;
intr_status_reg = INTR_STATUS(denali->flash_bank);
return ioread32(denali->flash_reg + intr_status_reg);
}
static irqreturn_t denali_isr(int irq, void *dev_id)
{
struct denali_nand_info *denali = dev_id;
uint32_t irq_status;
irqreturn_t result = IRQ_NONE;
spin_lock(&denali->irq_lock);
if (is_flash_bank_valid(denali->flash_bank)) {
irq_status = denali_irq_detected(denali);
if (irq_status != 0) {
clear_interrupt(denali, irq_status);
denali->irq_status |= irq_status;
complete(&denali->complete);
result = IRQ_HANDLED;
}
}
spin_unlock(&denali->irq_lock);
return result;
}
static uint32_t wait_for_irq(struct denali_nand_info *denali, uint32_t irq_mask)
{
unsigned long comp_res;
uint32_t intr_status;
unsigned long timeout = msecs_to_jiffies(1000);
do {
comp_res =
wait_for_completion_timeout(&denali->complete, timeout);
spin_lock_irq(&denali->irq_lock);
intr_status = denali->irq_status;
if (intr_status & irq_mask) {
denali->irq_status &= ~irq_mask;
spin_unlock_irq(&denali->irq_lock);
break;
}
spin_unlock_irq(&denali->irq_lock);
} while (comp_res != 0);
if (comp_res == 0) {
pr_err("timeout occurred, status = 0x%x, mask = 0x%x\n",
intr_status, irq_mask);
intr_status = 0;
}
return intr_status;
}
static void setup_ecc_for_xfer(struct denali_nand_info *denali, bool ecc_en,
bool transfer_spare)
{
int ecc_en_flag, transfer_spare_flag;
ecc_en_flag = ecc_en ? ECC_ENABLE__FLAG : 0;
transfer_spare_flag = transfer_spare ? TRANSFER_SPARE_REG__FLAG : 0;
iowrite32(ecc_en_flag, denali->flash_reg + ECC_ENABLE);
iowrite32(transfer_spare_flag, denali->flash_reg + TRANSFER_SPARE_REG);
}
static int denali_send_pipeline_cmd(struct denali_nand_info *denali,
bool ecc_en, bool transfer_spare,
int access_type, int op)
{
int status = PASS;
uint32_t addr, cmd;
setup_ecc_for_xfer(denali, ecc_en, transfer_spare);
clear_interrupts(denali);
addr = BANK(denali->flash_bank) | denali->page;
if (op == DENALI_WRITE && access_type != SPARE_ACCESS) {
cmd = MODE_01 | addr;
iowrite32(cmd, denali->flash_mem);
} else if (op == DENALI_WRITE && access_type == SPARE_ACCESS) {
cmd = MODE_10 | addr;
index_addr(denali, cmd, access_type);
cmd = MODE_01 | addr;
iowrite32(cmd, denali->flash_mem);
} else if (op == DENALI_READ) {
cmd = MODE_10 | addr;
index_addr(denali, cmd, access_type);
cmd = MODE_01 | addr;
iowrite32(cmd, denali->flash_mem);
}
return status;
}
static int write_data_to_flash_mem(struct denali_nand_info *denali,
const uint8_t *buf, int len)
{
uint32_t *buf32;
int i;
BUG_ON((len % 4) != 0);
buf32 = (uint32_t *)buf;
for (i = 0; i < len / 4; i++)
iowrite32(*buf32++, denali->flash_mem + 0x10);
return i * 4;
}
static int read_data_from_flash_mem(struct denali_nand_info *denali,
uint8_t *buf, int len)
{
uint32_t *buf32;
int i;
BUG_ON((len % 4) != 0);
buf32 = (uint32_t *)buf;
for (i = 0; i < len / 4; i++)
*buf32++ = ioread32(denali->flash_mem + 0x10);
return i * 4;
}
static int write_oob_data(struct mtd_info *mtd, uint8_t *buf, int page)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
uint32_t irq_status;
uint32_t irq_mask = INTR__PROGRAM_COMP | INTR__PROGRAM_FAIL;
int status = 0;
denali->page = page;
if (denali_send_pipeline_cmd(denali, false, false, SPARE_ACCESS,
DENALI_WRITE) == PASS) {
write_data_to_flash_mem(denali, buf, mtd->oobsize);
irq_status = wait_for_irq(denali, irq_mask);
if (irq_status == 0) {
dev_err(denali->dev, "OOB write failed\n");
status = -EIO;
}
} else {
dev_err(denali->dev, "unable to send pipeline command\n");
status = -EIO;
}
return status;
}
static void read_oob_data(struct mtd_info *mtd, uint8_t *buf, int page)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
uint32_t irq_mask = INTR__LOAD_COMP;
uint32_t irq_status, addr, cmd;
denali->page = page;
if (denali_send_pipeline_cmd(denali, false, true, SPARE_ACCESS,
DENALI_READ) == PASS) {
read_data_from_flash_mem(denali, buf, mtd->oobsize);
irq_status = wait_for_irq(denali, irq_mask);
if (irq_status == 0)
dev_err(denali->dev, "page on OOB timeout %d\n",
denali->page);
addr = BANK(denali->flash_bank) | denali->page;
cmd = MODE_10 | addr;
index_addr(denali, cmd, MAIN_ACCESS);
}
}
static int denali_check_erased_page(struct mtd_info *mtd,
struct nand_chip *chip, uint8_t *buf,
unsigned long uncor_ecc_flags,
unsigned int max_bitflips)
{
uint8_t *ecc_code = chip->buffers->ecccode;
int ecc_steps = chip->ecc.steps;
int ecc_size = chip->ecc.size;
int ecc_bytes = chip->ecc.bytes;
int i, ret, stat;
ret = mtd_ooblayout_get_eccbytes(mtd, ecc_code, chip->oob_poi, 0,
chip->ecc.total);
if (ret)
return ret;
for (i = 0; i < ecc_steps; i++) {
if (!(uncor_ecc_flags & BIT(i)))
continue;
stat = nand_check_erased_ecc_chunk(buf, ecc_size,
ecc_code, ecc_bytes,
NULL, 0,
chip->ecc.strength);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
buf += ecc_size;
ecc_code += ecc_bytes;
}
return max_bitflips;
}
static int denali_hw_ecc_fixup(struct mtd_info *mtd,
struct denali_nand_info *denali,
unsigned long *uncor_ecc_flags)
{
struct nand_chip *chip = mtd_to_nand(mtd);
int bank = denali->flash_bank;
uint32_t ecc_cor;
unsigned int max_bitflips;
ecc_cor = ioread32(denali->flash_reg + ECC_COR_INFO(bank));
ecc_cor >>= ECC_COR_INFO__SHIFT(bank);
if (ecc_cor & ECC_COR_INFO__UNCOR_ERR) {
*uncor_ecc_flags = GENMASK(chip->ecc.steps - 1, 0);
return 0;
}
max_bitflips = ecc_cor & ECC_COR_INFO__MAX_ERRORS;
mtd->ecc_stats.corrected += max_bitflips;
return max_bitflips;
}
static int denali_sw_ecc_fixup(struct mtd_info *mtd,
struct denali_nand_info *denali,
unsigned long *uncor_ecc_flags, uint8_t *buf)
{
unsigned int bitflips = 0;
unsigned int max_bitflips = 0;
uint32_t err_addr, err_cor_info;
unsigned int err_byte, err_sector, err_device;
uint8_t err_cor_value;
unsigned int prev_sector = 0;
denali_set_intr_modes(denali, false);
do {
err_addr = ioread32(denali->flash_reg + ECC_ERROR_ADDRESS);
err_sector = ECC_SECTOR(err_addr);
err_byte = ECC_BYTE(err_addr);
err_cor_info = ioread32(denali->flash_reg + ERR_CORRECTION_INFO);
err_cor_value = ECC_CORRECTION_VALUE(err_cor_info);
err_device = ECC_ERR_DEVICE(err_cor_info);
if (err_sector != prev_sector)
bitflips = 0;
if (ECC_ERROR_UNCORRECTABLE(err_cor_info)) {
*uncor_ecc_flags |= BIT(err_sector);
} else if (err_byte < ECC_SECTOR_SIZE) {
int offset;
unsigned int flips_in_byte;
offset = (err_sector * ECC_SECTOR_SIZE + err_byte) *
denali->devnum + err_device;
flips_in_byte = hweight8(buf[offset] ^ err_cor_value);
buf[offset] ^= err_cor_value;
mtd->ecc_stats.corrected += flips_in_byte;
bitflips += flips_in_byte;
max_bitflips = max(max_bitflips, bitflips);
}
prev_sector = err_sector;
} while (!ECC_LAST_ERR(err_cor_info));
while (!(read_interrupt_status(denali) & INTR__ECC_TRANSACTION_DONE))
cpu_relax();
clear_interrupts(denali);
denali_set_intr_modes(denali, true);
return max_bitflips;
}
static void denali_enable_dma(struct denali_nand_info *denali, bool en)
{
iowrite32(en ? DMA_ENABLE__FLAG : 0, denali->flash_reg + DMA_ENABLE);
ioread32(denali->flash_reg + DMA_ENABLE);
}
static void denali_setup_dma64(struct denali_nand_info *denali, int op)
{
uint32_t mode;
const int page_count = 1;
uint64_t addr = denali->buf.dma_buf;
mode = MODE_10 | BANK(denali->flash_bank) | denali->page;
index_addr(denali, mode, 0x01002000 | (64 << 16) | op | page_count);
index_addr(denali, mode, addr);
index_addr(denali, mode, addr >> 32);
}
static void denali_setup_dma32(struct denali_nand_info *denali, int op)
{
uint32_t mode;
const int page_count = 1;
uint32_t addr = denali->buf.dma_buf;
mode = MODE_10 | BANK(denali->flash_bank);
index_addr(denali, mode | denali->page, 0x2000 | op | page_count);
index_addr(denali, mode | ((addr >> 16) << 8), 0x2200);
index_addr(denali, mode | ((addr & 0xffff) << 8), 0x2300);
index_addr(denali, mode | 0x14000, 0x2400);
}
static void denali_setup_dma(struct denali_nand_info *denali, int op)
{
if (denali->caps & DENALI_CAP_DMA_64BIT)
denali_setup_dma64(denali, op);
else
denali_setup_dma32(denali, op);
}
static int write_page(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, bool raw_xfer)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
dma_addr_t addr = denali->buf.dma_buf;
size_t size = mtd->writesize + mtd->oobsize;
uint32_t irq_status;
uint32_t irq_mask = INTR__DMA_CMD_COMP | INTR__PROGRAM_FAIL;
setup_ecc_for_xfer(denali, !raw_xfer, raw_xfer);
memcpy(denali->buf.buf, buf, mtd->writesize);
if (raw_xfer) {
memcpy(denali->buf.buf + mtd->writesize,
chip->oob_poi,
mtd->oobsize);
}
dma_sync_single_for_device(denali->dev, addr, size, DMA_TO_DEVICE);
clear_interrupts(denali);
denali_enable_dma(denali, true);
denali_setup_dma(denali, DENALI_WRITE);
irq_status = wait_for_irq(denali, irq_mask);
if (irq_status == 0) {
dev_err(denali->dev, "timeout on write_page (type = %d)\n",
raw_xfer);
denali->status = NAND_STATUS_FAIL;
}
denali_enable_dma(denali, false);
dma_sync_single_for_cpu(denali->dev, addr, size, DMA_TO_DEVICE);
return 0;
}
static int denali_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required, int page)
{
return write_page(mtd, chip, buf, false);
}
static int denali_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
const uint8_t *buf, int oob_required,
int page)
{
return write_page(mtd, chip, buf, true);
}
static int denali_write_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
return write_oob_data(mtd, chip->oob_poi, page);
}
static int denali_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
read_oob_data(mtd, chip->oob_poi, page);
return 0;
}
static int denali_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
dma_addr_t addr = denali->buf.dma_buf;
size_t size = mtd->writesize + mtd->oobsize;
uint32_t irq_status;
uint32_t irq_mask = denali->caps & DENALI_CAP_HW_ECC_FIXUP ?
INTR__DMA_CMD_COMP | INTR__ECC_UNCOR_ERR :
INTR__ECC_TRANSACTION_DONE | INTR__ECC_ERR;
unsigned long uncor_ecc_flags = 0;
int stat = 0;
if (page != denali->page) {
dev_err(denali->dev,
"IN %s: page %d is not equal to denali->page %d",
__func__, page, denali->page);
BUG();
}
setup_ecc_for_xfer(denali, true, false);
denali_enable_dma(denali, true);
dma_sync_single_for_device(denali->dev, addr, size, DMA_FROM_DEVICE);
clear_interrupts(denali);
denali_setup_dma(denali, DENALI_READ);
irq_status = wait_for_irq(denali, irq_mask);
dma_sync_single_for_cpu(denali->dev, addr, size, DMA_FROM_DEVICE);
memcpy(buf, denali->buf.buf, mtd->writesize);
if (denali->caps & DENALI_CAP_HW_ECC_FIXUP)
stat = denali_hw_ecc_fixup(mtd, denali, &uncor_ecc_flags);
else if (irq_status & INTR__ECC_ERR)
stat = denali_sw_ecc_fixup(mtd, denali, &uncor_ecc_flags, buf);
denali_enable_dma(denali, false);
if (stat < 0)
return stat;
if (uncor_ecc_flags) {
read_oob_data(mtd, chip->oob_poi, denali->page);
stat = denali_check_erased_page(mtd, chip, buf,
uncor_ecc_flags, stat);
}
return stat;
}
static int denali_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
dma_addr_t addr = denali->buf.dma_buf;
size_t size = mtd->writesize + mtd->oobsize;
uint32_t irq_mask = INTR__DMA_CMD_COMP;
if (page != denali->page) {
dev_err(denali->dev,
"IN %s: page %d is not equal to denali->page %d",
__func__, page, denali->page);
BUG();
}
setup_ecc_for_xfer(denali, false, true);
denali_enable_dma(denali, true);
dma_sync_single_for_device(denali->dev, addr, size, DMA_FROM_DEVICE);
clear_interrupts(denali);
denali_setup_dma(denali, DENALI_READ);
wait_for_irq(denali, irq_mask);
dma_sync_single_for_cpu(denali->dev, addr, size, DMA_FROM_DEVICE);
denali_enable_dma(denali, false);
memcpy(buf, denali->buf.buf, mtd->writesize);
memcpy(chip->oob_poi, denali->buf.buf + mtd->writesize, mtd->oobsize);
return 0;
}
static uint8_t denali_read_byte(struct mtd_info *mtd)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
uint8_t result = 0xff;
if (denali->buf.head < denali->buf.tail)
result = denali->buf.buf[denali->buf.head++];
return result;
}
static void denali_select_chip(struct mtd_info *mtd, int chip)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
spin_lock_irq(&denali->irq_lock);
denali->flash_bank = chip;
spin_unlock_irq(&denali->irq_lock);
}
static int denali_waitfunc(struct mtd_info *mtd, struct nand_chip *chip)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
int status = denali->status;
denali->status = 0;
return status;
}
static int denali_erase(struct mtd_info *mtd, int page)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
uint32_t cmd, irq_status;
clear_interrupts(denali);
cmd = MODE_10 | BANK(denali->flash_bank) | page;
index_addr(denali, cmd, 0x1);
irq_status = wait_for_irq(denali, INTR__ERASE_COMP | INTR__ERASE_FAIL);
return irq_status & INTR__ERASE_FAIL ? NAND_STATUS_FAIL : PASS;
}
static void denali_cmdfunc(struct mtd_info *mtd, unsigned int cmd, int col,
int page)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
uint32_t addr, id;
int i;
switch (cmd) {
case NAND_CMD_PAGEPROG:
break;
case NAND_CMD_STATUS:
read_status(denali);
break;
case NAND_CMD_READID:
case NAND_CMD_PARAM:
reset_buf(denali);
addr = MODE_11 | BANK(denali->flash_bank);
index_addr(denali, addr | 0, 0x90);
index_addr(denali, addr | 1, col);
for (i = 0; i < 8; i++) {
index_addr_read_data(denali, addr | 2, &id);
write_byte_to_buf(denali, id);
}
break;
case NAND_CMD_READ0:
case NAND_CMD_SEQIN:
denali->page = page;
break;
case NAND_CMD_RESET:
reset_bank(denali);
break;
case NAND_CMD_READOOB:
break;
default:
pr_err(": unsupported command received 0x%x\n", cmd);
break;
}
}
static void denali_hw_init(struct denali_nand_info *denali)
{
if (!denali->revision)
denali->revision =
swab16(ioread32(denali->flash_reg + REVISION));
denali->bbtskipbytes = ioread32(denali->flash_reg +
SPARE_AREA_SKIP_BYTES);
detect_max_banks(denali);
denali_nand_reset(denali);
iowrite32(0x0F, denali->flash_reg + RB_PIN_ENABLED);
iowrite32(CHIP_EN_DONT_CARE__FLAG,
denali->flash_reg + CHIP_ENABLE_DONT_CARE);
iowrite32(0xffff, denali->flash_reg + SPARE_AREA_MARKER);
iowrite32(0, denali->flash_reg + TWO_ROW_ADDR_CYCLES);
iowrite32(1, denali->flash_reg + ECC_ENABLE);
denali_nand_timing_set(denali);
denali_irq_init(denali);
}
static int denali_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
struct nand_chip *chip = mtd_to_nand(mtd);
if (section)
return -ERANGE;
oobregion->offset = denali->bbtskipbytes;
oobregion->length = chip->ecc.total;
return 0;
}
static int denali_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct denali_nand_info *denali = mtd_to_denali(mtd);
struct nand_chip *chip = mtd_to_nand(mtd);
if (section)
return -ERANGE;
oobregion->offset = chip->ecc.total + denali->bbtskipbytes;
oobregion->length = mtd->oobsize - oobregion->offset;
return 0;
}
static void denali_drv_init(struct denali_nand_info *denali)
{
init_completion(&denali->complete);
spin_lock_init(&denali->irq_lock);
denali->flash_bank = CHIP_SELECT_INVALID;
denali->irq_status = 0;
}
static int denali_multidev_fixup(struct denali_nand_info *denali)
{
struct nand_chip *chip = &denali->nand;
struct mtd_info *mtd = nand_to_mtd(chip);
denali->devnum = ioread32(denali->flash_reg + DEVICES_CONNECTED);
if (denali->devnum == 0) {
denali->devnum = 1;
iowrite32(1, denali->flash_reg + DEVICES_CONNECTED);
}
if (denali->devnum == 1)
return 0;
if (denali->devnum != 2) {
dev_err(denali->dev, "unsupported number of devices %d\n",
denali->devnum);
return -EINVAL;
}
mtd->size <<= 1;
mtd->erasesize <<= 1;
mtd->writesize <<= 1;
mtd->oobsize <<= 1;
chip->chipsize <<= 1;
chip->page_shift += 1;
chip->phys_erase_shift += 1;
chip->bbt_erase_shift += 1;
chip->chip_shift += 1;
chip->pagemask <<= 1;
chip->ecc.size <<= 1;
chip->ecc.bytes <<= 1;
chip->ecc.strength <<= 1;
denali->bbtskipbytes <<= 1;
return 0;
}
int denali_init(struct denali_nand_info *denali)
{
struct nand_chip *chip = &denali->nand;
struct mtd_info *mtd = nand_to_mtd(chip);
int ret;
if (denali->platform == INTEL_CE4100) {
if (onfi_timing_mode < -1 || onfi_timing_mode > 1) {
pr_err("Intel CE4100 only supports ONFI timing mode 1 or below\n");
return -EINVAL;
}
}
denali->buf.buf = devm_kzalloc(denali->dev, PAGE_SIZE,
GFP_DMA | GFP_KERNEL);
if (!denali->buf.buf)
return -ENOMEM;
mtd->dev.parent = denali->dev;
denali_hw_init(denali);
denali_drv_init(denali);
ret = devm_request_irq(denali->dev, denali->irq, denali_isr,
IRQF_SHARED, DENALI_NAND_NAME, denali);
if (ret) {
dev_err(denali->dev, "Unable to request IRQ\n");
return ret;
}
denali_set_intr_modes(denali, true);
nand_set_flash_node(chip, denali->dev->of_node);
if (!mtd->name)
mtd->name = "denali-nand";
chip->select_chip = denali_select_chip;
chip->cmdfunc = denali_cmdfunc;
chip->read_byte = denali_read_byte;
chip->waitfunc = denali_waitfunc;
ret = nand_scan_ident(mtd, denali->max_banks, NULL);
if (ret)
goto failed_req_irq;
devm_kfree(denali->dev, denali->buf.buf);
denali->buf.buf = devm_kzalloc(denali->dev,
mtd->writesize + mtd->oobsize,
GFP_KERNEL);
if (!denali->buf.buf) {
ret = -ENOMEM;
goto failed_req_irq;
}
ret = dma_set_mask(denali->dev,
DMA_BIT_MASK(denali->caps & DENALI_CAP_DMA_64BIT ?
64 : 32));
if (ret) {
dev_err(denali->dev, "No usable DMA configuration\n");
goto failed_req_irq;
}
denali->buf.dma_buf = dma_map_single(denali->dev, denali->buf.buf,
mtd->writesize + mtd->oobsize,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(denali->dev, denali->buf.dma_buf)) {
dev_err(denali->dev, "Failed to map DMA buffer\n");
ret = -EIO;
goto failed_req_irq;
}
chip->bbt_td = &bbt_main_descr;
chip->bbt_md = &bbt_mirror_descr;
chip->bbt_options |= NAND_BBT_USE_FLASH;
chip->options |= NAND_SKIP_BBTSCAN;
chip->ecc.mode = NAND_ECC_HW_SYNDROME;
chip->options |= NAND_NO_SUBPAGE_WRITE;
if (!nand_is_slc(chip) &&
(mtd->oobsize > (denali->bbtskipbytes +
ECC_15BITS * (mtd->writesize /
ECC_SECTOR_SIZE)))) {
chip->ecc.strength = 15;
chip->ecc.bytes = ECC_15BITS;
iowrite32(15, denali->flash_reg + ECC_CORRECTION);
} else if (mtd->oobsize < (denali->bbtskipbytes +
ECC_8BITS * (mtd->writesize /
ECC_SECTOR_SIZE))) {
pr_err("Your NAND chip OOB is not large enough to contain 8bit ECC correction codes");
goto failed_req_irq;
} else {
chip->ecc.strength = 8;
chip->ecc.bytes = ECC_8BITS;
iowrite32(8, denali->flash_reg + ECC_CORRECTION);
}
mtd_set_ooblayout(mtd, &denali_ooblayout_ops);
chip->ecc.size = ECC_SECTOR_SIZE;
chip->ecc.read_page = denali_read_page;
chip->ecc.read_page_raw = denali_read_page_raw;
chip->ecc.write_page = denali_write_page;
chip->ecc.write_page_raw = denali_write_page_raw;
chip->ecc.read_oob = denali_read_oob;
chip->ecc.write_oob = denali_write_oob;
chip->erase = denali_erase;
ret = denali_multidev_fixup(denali);
if (ret)
goto failed_req_irq;
ret = nand_scan_tail(mtd);
if (ret)
goto failed_req_irq;
ret = mtd_device_register(mtd, NULL, 0);
if (ret) {
dev_err(denali->dev, "Failed to register MTD: %d\n", ret);
goto failed_req_irq;
}
return 0;
failed_req_irq:
denali_irq_cleanup(denali->irq, denali);
return ret;
}
void denali_remove(struct denali_nand_info *denali)
{
struct mtd_info *mtd = nand_to_mtd(&denali->nand);
int bufsize = mtd->writesize + mtd->oobsize;
nand_release(mtd);
denali_irq_cleanup(denali->irq, denali);
dma_unmap_single(denali->dev, denali->buf.dma_buf, bufsize,
DMA_BIDIRECTIONAL);
}
