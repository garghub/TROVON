static irqreturn_t bch_irq(int irq, void *cookie)
{
struct gpmi_nand_data *this = cookie;
gpmi_clear_bch(this);
complete(&this->bch_done);
return IRQ_HANDLED;
}
static inline int get_ecc_strength(struct gpmi_nand_data *this)
{
struct bch_geometry *geo = &this->bch_geometry;
struct mtd_info *mtd = &this->mtd;
int ecc_strength;
ecc_strength = ((mtd->oobsize - geo->metadata_size) * 8)
/ (geo->gf_len * geo->ecc_chunk_count);
return round_down(ecc_strength, 2);
}
int common_nfc_set_geometry(struct gpmi_nand_data *this)
{
struct bch_geometry *geo = &this->bch_geometry;
struct mtd_info *mtd = &this->mtd;
unsigned int metadata_size;
unsigned int status_size;
unsigned int block_mark_bit_offset;
geo->metadata_size = 10;
geo->gf_len = 13;
geo->ecc_chunk_size = 512;
while (geo->ecc_chunk_size < mtd->oobsize)
geo->ecc_chunk_size *= 2;
geo->ecc_chunk_count = mtd->writesize / geo->ecc_chunk_size;
geo->ecc_strength = get_ecc_strength(this);
if (!geo->ecc_strength) {
pr_err("We get a wrong ECC strength.\n");
return -EINVAL;
}
geo->page_size = mtd->writesize + mtd->oobsize;
geo->payload_size = mtd->writesize;
metadata_size = ALIGN(geo->metadata_size, 4);
status_size = ALIGN(geo->ecc_chunk_count, 4);
geo->auxiliary_size = metadata_size + status_size;
geo->auxiliary_status_offset = metadata_size;
if (!this->swap_block_mark)
return 0;
block_mark_bit_offset = mtd->writesize * 8 -
(geo->ecc_strength * geo->gf_len * (geo->ecc_chunk_count - 1)
+ geo->metadata_size * 8);
geo->block_mark_byte_offset = block_mark_bit_offset / 8;
geo->block_mark_bit_offset = block_mark_bit_offset % 8;
return 0;
}
struct dma_chan *get_dma_chan(struct gpmi_nand_data *this)
{
int chipnr = this->current_chip;
return this->dma_chans[chipnr];
}
void prepare_data_dma(struct gpmi_nand_data *this, enum dma_data_direction dr)
{
struct scatterlist *sgl = &this->data_sgl;
int ret;
this->direct_dma_map_ok = true;
sg_init_one(sgl, this->upper_buf, this->upper_len);
ret = dma_map_sg(this->dev, sgl, 1, dr);
if (ret == 0) {
sg_init_one(sgl, this->data_buffer_dma, PAGE_SIZE);
if (dr == DMA_TO_DEVICE)
memcpy(this->data_buffer_dma, this->upper_buf,
this->upper_len);
ret = dma_map_sg(this->dev, sgl, 1, dr);
if (ret == 0)
pr_err("map failed.\n");
this->direct_dma_map_ok = false;
}
}
static void dma_irq_callback(void *param)
{
struct gpmi_nand_data *this = param;
struct completion *dma_c = &this->dma_done;
complete(dma_c);
switch (this->dma_type) {
case DMA_FOR_COMMAND:
dma_unmap_sg(this->dev, &this->cmd_sgl, 1, DMA_TO_DEVICE);
break;
case DMA_FOR_READ_DATA:
dma_unmap_sg(this->dev, &this->data_sgl, 1, DMA_FROM_DEVICE);
if (this->direct_dma_map_ok == false)
memcpy(this->upper_buf, this->data_buffer_dma,
this->upper_len);
break;
case DMA_FOR_WRITE_DATA:
dma_unmap_sg(this->dev, &this->data_sgl, 1, DMA_TO_DEVICE);
break;
case DMA_FOR_READ_ECC_PAGE:
case DMA_FOR_WRITE_ECC_PAGE:
break;
default:
pr_err("in wrong DMA operation.\n");
}
}
int start_dma_without_bch_irq(struct gpmi_nand_data *this,
struct dma_async_tx_descriptor *desc)
{
struct completion *dma_c = &this->dma_done;
int err;
init_completion(dma_c);
desc->callback = dma_irq_callback;
desc->callback_param = this;
dmaengine_submit(desc);
err = wait_for_completion_timeout(dma_c, msecs_to_jiffies(1000));
if (!err) {
pr_err("DMA timeout, last DMA :%d\n", this->last_dma_type);
gpmi_dump_info(this);
return -ETIMEDOUT;
}
return 0;
}
int start_dma_with_bch_irq(struct gpmi_nand_data *this,
struct dma_async_tx_descriptor *desc)
{
struct completion *bch_c = &this->bch_done;
int err;
init_completion(bch_c);
start_dma_without_bch_irq(this, desc);
err = wait_for_completion_timeout(bch_c, msecs_to_jiffies(1000));
if (!err) {
pr_err("BCH timeout, last DMA :%d\n", this->last_dma_type);
gpmi_dump_info(this);
return -ETIMEDOUT;
}
return 0;
}
static int __devinit
acquire_register_block(struct gpmi_nand_data *this, const char *res_name)
{
struct platform_device *pdev = this->pdev;
struct resources *res = &this->resources;
struct resource *r;
void *p;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, res_name);
if (!r) {
pr_err("Can't get resource for %s\n", res_name);
return -ENXIO;
}
p = ioremap(r->start, resource_size(r));
if (!p) {
pr_err("Can't remap %s\n", res_name);
return -ENOMEM;
}
if (!strcmp(res_name, GPMI_NAND_GPMI_REGS_ADDR_RES_NAME))
res->gpmi_regs = p;
else if (!strcmp(res_name, GPMI_NAND_BCH_REGS_ADDR_RES_NAME))
res->bch_regs = p;
else
pr_err("unknown resource name : %s\n", res_name);
return 0;
}
static void release_register_block(struct gpmi_nand_data *this)
{
struct resources *res = &this->resources;
if (res->gpmi_regs)
iounmap(res->gpmi_regs);
if (res->bch_regs)
iounmap(res->bch_regs);
res->gpmi_regs = NULL;
res->bch_regs = NULL;
}
static int __devinit
acquire_bch_irq(struct gpmi_nand_data *this, irq_handler_t irq_h)
{
struct platform_device *pdev = this->pdev;
struct resources *res = &this->resources;
const char *res_name = GPMI_NAND_BCH_INTERRUPT_RES_NAME;
struct resource *r;
int err;
r = platform_get_resource_byname(pdev, IORESOURCE_IRQ, res_name);
if (!r) {
pr_err("Can't get resource for %s\n", res_name);
return -ENXIO;
}
err = request_irq(r->start, irq_h, 0, res_name, this);
if (err) {
pr_err("Can't own %s\n", res_name);
return err;
}
res->bch_low_interrupt = r->start;
res->bch_high_interrupt = r->end;
return 0;
}
static void release_bch_irq(struct gpmi_nand_data *this)
{
struct resources *res = &this->resources;
int i = res->bch_low_interrupt;
for (; i <= res->bch_high_interrupt; i++)
free_irq(i, this);
}
static bool gpmi_dma_filter(struct dma_chan *chan, void *param)
{
struct gpmi_nand_data *this = param;
struct resource *r = this->private;
if (!mxs_dma_is_apbh(chan))
return false;
if (r->start <= chan->chan_id && chan->chan_id <= r->end) {
chan->private = &this->dma_data;
return true;
}
return false;
}
static void release_dma_channels(struct gpmi_nand_data *this)
{
unsigned int i;
for (i = 0; i < DMA_CHANS; i++)
if (this->dma_chans[i]) {
dma_release_channel(this->dma_chans[i]);
this->dma_chans[i] = NULL;
}
}
static int __devinit acquire_dma_channels(struct gpmi_nand_data *this)
{
struct platform_device *pdev = this->pdev;
struct gpmi_nand_platform_data *pdata = this->pdata;
struct resources *res = &this->resources;
struct resource *r, *r_dma;
unsigned int i;
r = platform_get_resource_byname(pdev, IORESOURCE_DMA,
GPMI_NAND_DMA_CHANNELS_RES_NAME);
r_dma = platform_get_resource_byname(pdev, IORESOURCE_IRQ,
GPMI_NAND_DMA_INTERRUPT_RES_NAME);
if (!r || !r_dma) {
pr_err("Can't get resource for DMA\n");
return -ENXIO;
}
this->private = r;
for (i = r->start; i <= r->end; i++) {
struct dma_chan *dma_chan;
dma_cap_mask_t mask;
if (i - r->start >= pdata->max_chip_count)
break;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
if (r_dma->start == r_dma->end) {
if (i == r->start)
this->dma_data.chan_irq = r_dma->start;
else
this->dma_data.chan_irq = NO_IRQ;
} else
this->dma_data.chan_irq = r_dma->start + (i - r->start);
dma_chan = dma_request_channel(mask, gpmi_dma_filter, this);
if (!dma_chan)
goto acquire_err;
this->dma_chans[i - r->start] = dma_chan;
}
res->dma_low_channel = r->start;
res->dma_high_channel = i;
return 0;
acquire_err:
pr_err("Can't acquire DMA channel %u\n", i);
release_dma_channels(this);
return -EINVAL;
}
static int __devinit acquire_resources(struct gpmi_nand_data *this)
{
struct resources *res = &this->resources;
int ret;
ret = acquire_register_block(this, GPMI_NAND_GPMI_REGS_ADDR_RES_NAME);
if (ret)
goto exit_regs;
ret = acquire_register_block(this, GPMI_NAND_BCH_REGS_ADDR_RES_NAME);
if (ret)
goto exit_regs;
ret = acquire_bch_irq(this, bch_irq);
if (ret)
goto exit_regs;
ret = acquire_dma_channels(this);
if (ret)
goto exit_dma_channels;
res->clock = clk_get(&this->pdev->dev, NULL);
if (IS_ERR(res->clock)) {
pr_err("can not get the clock\n");
ret = -ENOENT;
goto exit_clock;
}
return 0;
exit_clock:
release_dma_channels(this);
exit_dma_channels:
release_bch_irq(this);
exit_regs:
release_register_block(this);
return ret;
}
static void release_resources(struct gpmi_nand_data *this)
{
struct resources *r = &this->resources;
clk_put(r->clock);
release_register_block(this);
release_bch_irq(this);
release_dma_channels(this);
}
static int __devinit init_hardware(struct gpmi_nand_data *this)
{
int ret;
struct nand_timing safe_timing = {
.data_setup_in_ns = 80,
.data_hold_in_ns = 60,
.address_setup_in_ns = 25,
.gpmi_sample_delay_in_ns = 6,
.tREA_in_ns = -1,
.tRLOH_in_ns = -1,
.tRHOH_in_ns = -1,
};
ret = gpmi_init(this);
if (ret)
return ret;
this->timing = safe_timing;
return 0;
}
static int read_page_prepare(struct gpmi_nand_data *this,
void *destination, unsigned length,
void *alt_virt, dma_addr_t alt_phys, unsigned alt_size,
void **use_virt, dma_addr_t *use_phys)
{
struct device *dev = this->dev;
if (virt_addr_valid(destination)) {
dma_addr_t dest_phys;
dest_phys = dma_map_single(dev, destination,
length, DMA_FROM_DEVICE);
if (dma_mapping_error(dev, dest_phys)) {
if (alt_size < length) {
pr_err("Alternate buffer is too small\n");
return -ENOMEM;
}
goto map_failed;
}
*use_virt = destination;
*use_phys = dest_phys;
this->direct_dma_map_ok = true;
return 0;
}
map_failed:
*use_virt = alt_virt;
*use_phys = alt_phys;
this->direct_dma_map_ok = false;
return 0;
}
static inline void read_page_end(struct gpmi_nand_data *this,
void *destination, unsigned length,
void *alt_virt, dma_addr_t alt_phys, unsigned alt_size,
void *used_virt, dma_addr_t used_phys)
{
if (this->direct_dma_map_ok)
dma_unmap_single(this->dev, used_phys, length, DMA_FROM_DEVICE);
}
static inline void read_page_swap_end(struct gpmi_nand_data *this,
void *destination, unsigned length,
void *alt_virt, dma_addr_t alt_phys, unsigned alt_size,
void *used_virt, dma_addr_t used_phys)
{
if (!this->direct_dma_map_ok)
memcpy(destination, alt_virt, length);
}
static int send_page_prepare(struct gpmi_nand_data *this,
const void *source, unsigned length,
void *alt_virt, dma_addr_t alt_phys, unsigned alt_size,
const void **use_virt, dma_addr_t *use_phys)
{
struct device *dev = this->dev;
if (virt_addr_valid(source)) {
dma_addr_t source_phys;
source_phys = dma_map_single(dev, (void *)source, length,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, source_phys)) {
if (alt_size < length) {
pr_err("Alternate buffer is too small\n");
return -ENOMEM;
}
goto map_failed;
}
*use_virt = source;
*use_phys = source_phys;
return 0;
}
map_failed:
memcpy(alt_virt, source, length);
*use_virt = alt_virt;
*use_phys = alt_phys;
return 0;
}
static void send_page_end(struct gpmi_nand_data *this,
const void *source, unsigned length,
void *alt_virt, dma_addr_t alt_phys, unsigned alt_size,
const void *used_virt, dma_addr_t used_phys)
{
struct device *dev = this->dev;
if (used_virt == source)
dma_unmap_single(dev, used_phys, length, DMA_TO_DEVICE);
}
static void gpmi_free_dma_buffer(struct gpmi_nand_data *this)
{
struct device *dev = this->dev;
if (this->page_buffer_virt && virt_addr_valid(this->page_buffer_virt))
dma_free_coherent(dev, this->page_buffer_size,
this->page_buffer_virt,
this->page_buffer_phys);
kfree(this->cmd_buffer);
kfree(this->data_buffer_dma);
this->cmd_buffer = NULL;
this->data_buffer_dma = NULL;
this->page_buffer_virt = NULL;
this->page_buffer_size = 0;
}
static int gpmi_alloc_dma_buffer(struct gpmi_nand_data *this)
{
struct bch_geometry *geo = &this->bch_geometry;
struct device *dev = this->dev;
this->cmd_buffer = kzalloc(PAGE_SIZE, GFP_DMA);
if (this->cmd_buffer == NULL)
goto error_alloc;
this->data_buffer_dma = kzalloc(PAGE_SIZE, GFP_DMA);
if (this->data_buffer_dma == NULL)
goto error_alloc;
this->page_buffer_size = geo->payload_size + geo->auxiliary_size;
this->page_buffer_virt = dma_alloc_coherent(dev, this->page_buffer_size,
&this->page_buffer_phys, GFP_DMA);
if (!this->page_buffer_virt)
goto error_alloc;
this->payload_virt = this->page_buffer_virt;
this->payload_phys = this->page_buffer_phys;
this->auxiliary_virt = this->payload_virt + geo->payload_size;
this->auxiliary_phys = this->payload_phys + geo->payload_size;
return 0;
error_alloc:
gpmi_free_dma_buffer(this);
pr_err("allocate DMA buffer ret!!\n");
return -ENOMEM;
}
static void gpmi_cmd_ctrl(struct mtd_info *mtd, int data, unsigned int ctrl)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
int ret;
if ((ctrl & (NAND_ALE | NAND_CLE))) {
if (data != NAND_CMD_NONE)
this->cmd_buffer[this->command_length++] = data;
return;
}
if (!this->command_length)
return;
ret = gpmi_send_command(this);
if (ret)
pr_err("Chip: %u, Error %d\n", this->current_chip, ret);
this->command_length = 0;
}
static int gpmi_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
return gpmi_is_ready(this, this->current_chip);
}
static void gpmi_select_chip(struct mtd_info *mtd, int chipnr)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
if ((this->current_chip < 0) && (chipnr >= 0))
gpmi_begin(this);
else if ((this->current_chip >= 0) && (chipnr < 0))
gpmi_end(this);
this->current_chip = chipnr;
}
static void gpmi_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
pr_debug("len is %d\n", len);
this->upper_buf = buf;
this->upper_len = len;
gpmi_read_data(this);
}
static void gpmi_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
pr_debug("len is %d\n", len);
this->upper_buf = (uint8_t *)buf;
this->upper_len = len;
gpmi_send_data(this);
}
static uint8_t gpmi_read_byte(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
uint8_t *buf = this->data_buffer_dma;
gpmi_read_buf(mtd, buf, 1);
return buf[0];
}
static void block_mark_swapping(struct gpmi_nand_data *this,
void *payload, void *auxiliary)
{
struct bch_geometry *nfc_geo = &this->bch_geometry;
unsigned char *p;
unsigned char *a;
unsigned int bit;
unsigned char mask;
unsigned char from_data;
unsigned char from_oob;
if (!this->swap_block_mark)
return;
bit = nfc_geo->block_mark_bit_offset;
p = payload + nfc_geo->block_mark_byte_offset;
a = auxiliary;
from_data = (p[0] >> bit) | (p[1] << (8 - bit));
from_oob = a[0];
a[0] = from_data;
mask = (0x1 << bit) - 1;
p[0] = (p[0] & mask) | (from_oob << bit);
mask = ~0 << bit;
p[1] = (p[1] & mask) | (from_oob >> (8 - bit));
}
static int gpmi_ecc_read_page(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int page)
{
struct gpmi_nand_data *this = chip->priv;
struct bch_geometry *nfc_geo = &this->bch_geometry;
void *payload_virt;
dma_addr_t payload_phys;
void *auxiliary_virt;
dma_addr_t auxiliary_phys;
unsigned int i;
unsigned char *status;
unsigned int failed;
unsigned int corrected;
int ret;
pr_debug("page number is : %d\n", page);
ret = read_page_prepare(this, buf, mtd->writesize,
this->payload_virt, this->payload_phys,
nfc_geo->payload_size,
&payload_virt, &payload_phys);
if (ret) {
pr_err("Inadequate DMA buffer\n");
ret = -ENOMEM;
return ret;
}
auxiliary_virt = this->auxiliary_virt;
auxiliary_phys = this->auxiliary_phys;
ret = gpmi_read_page(this, payload_phys, auxiliary_phys);
read_page_end(this, buf, mtd->writesize,
this->payload_virt, this->payload_phys,
nfc_geo->payload_size,
payload_virt, payload_phys);
if (ret) {
pr_err("Error in ECC-based read: %d\n", ret);
goto exit_nfc;
}
block_mark_swapping(this, payload_virt, auxiliary_virt);
failed = 0;
corrected = 0;
status = auxiliary_virt + nfc_geo->auxiliary_status_offset;
for (i = 0; i < nfc_geo->ecc_chunk_count; i++, status++) {
if ((*status == STATUS_GOOD) || (*status == STATUS_ERASED))
continue;
if (*status == STATUS_UNCORRECTABLE) {
failed++;
continue;
}
corrected += *status;
}
if (failed || corrected >= (nfc_geo->ecc_strength - 1)) {
mtd->ecc_stats.failed += failed;
mtd->ecc_stats.corrected += corrected;
}
memset(chip->oob_poi, ~0, mtd->oobsize);
chip->oob_poi[0] = ((uint8_t *) auxiliary_virt)[0];
read_page_swap_end(this, buf, mtd->writesize,
this->payload_virt, this->payload_phys,
nfc_geo->payload_size,
payload_virt, payload_phys);
exit_nfc:
return ret;
}
static void gpmi_ecc_write_page(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf)
{
struct gpmi_nand_data *this = chip->priv;
struct bch_geometry *nfc_geo = &this->bch_geometry;
const void *payload_virt;
dma_addr_t payload_phys;
const void *auxiliary_virt;
dma_addr_t auxiliary_phys;
int ret;
pr_debug("ecc write page.\n");
if (this->swap_block_mark) {
memcpy(this->payload_virt, buf, mtd->writesize);
payload_virt = this->payload_virt;
payload_phys = this->payload_phys;
memcpy(this->auxiliary_virt, chip->oob_poi,
nfc_geo->auxiliary_size);
auxiliary_virt = this->auxiliary_virt;
auxiliary_phys = this->auxiliary_phys;
block_mark_swapping(this,
(void *) payload_virt, (void *) auxiliary_virt);
} else {
ret = send_page_prepare(this,
buf, mtd->writesize,
this->payload_virt, this->payload_phys,
nfc_geo->payload_size,
&payload_virt, &payload_phys);
if (ret) {
pr_err("Inadequate payload DMA buffer\n");
return;
}
ret = send_page_prepare(this,
chip->oob_poi, mtd->oobsize,
this->auxiliary_virt, this->auxiliary_phys,
nfc_geo->auxiliary_size,
&auxiliary_virt, &auxiliary_phys);
if (ret) {
pr_err("Inadequate auxiliary DMA buffer\n");
goto exit_auxiliary;
}
}
ret = gpmi_send_page(this, payload_phys, auxiliary_phys);
if (ret)
pr_err("Error in ECC-based write: %d\n", ret);
if (!this->swap_block_mark) {
send_page_end(this, chip->oob_poi, mtd->oobsize,
this->auxiliary_virt, this->auxiliary_phys,
nfc_geo->auxiliary_size,
auxiliary_virt, auxiliary_phys);
exit_auxiliary:
send_page_end(this, buf, mtd->writesize,
this->payload_virt, this->payload_phys,
nfc_geo->payload_size,
payload_virt, payload_phys);
}
}
static int gpmi_ecc_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page, int sndcmd)
{
struct gpmi_nand_data *this = chip->priv;
pr_debug("page number is %d\n", page);
memset(chip->oob_poi, ~0, mtd->oobsize);
chip->cmdfunc(mtd, NAND_CMD_READ0, mtd->writesize, page);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
if (!this->swap_block_mark) {
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
chip->oob_poi[0] = chip->read_byte(mtd);
}
return true;
}
static int
gpmi_ecc_write_oob(struct mtd_info *mtd, struct nand_chip *chip, int page)
{
return -EPERM;
}
static int gpmi_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
int block, ret = 0;
uint8_t *block_mark;
int column, page, status, chipnr;
block = (int)(ofs >> chip->bbt_erase_shift);
if (chip->bbt)
chip->bbt[block >> 2] |= 0x01 << ((block & 0x03) << 1);
if (chip->options & NAND_BBT_USE_FLASH)
ret = nand_update_bbt(mtd, ofs);
else {
chipnr = (int)(ofs >> chip->chip_shift);
chip->select_chip(mtd, chipnr);
column = this->swap_block_mark ? mtd->writesize : 0;
block_mark = this->data_buffer_dma;
block_mark[0] = 0;
page = (int)(ofs >> chip->page_shift);
chip->cmdfunc(mtd, NAND_CMD_SEQIN, column, page);
chip->write_buf(mtd, block_mark, 1);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL)
ret = -EIO;
chip->select_chip(mtd, -1);
}
if (!ret)
mtd->ecc_stats.badblocks++;
return ret;
}
static int __devinit nand_boot_set_geometry(struct gpmi_nand_data *this)
{
struct boot_rom_geometry *geometry = &this->rom_geometry;
geometry->stride_size_in_pages = 64;
geometry->search_area_stride_exponent = 2;
return 0;
}
static int __devinit mx23_check_transcription_stamp(struct gpmi_nand_data *this)
{
struct boot_rom_geometry *rom_geo = &this->rom_geometry;
struct device *dev = this->dev;
struct mtd_info *mtd = &this->mtd;
struct nand_chip *chip = &this->nand;
unsigned int search_area_size_in_strides;
unsigned int stride;
unsigned int page;
loff_t byte;
uint8_t *buffer = chip->buffers->databuf;
int saved_chip_number;
int found_an_ncb_fingerprint = false;
search_area_size_in_strides = 1 << rom_geo->search_area_stride_exponent;
saved_chip_number = this->current_chip;
chip->select_chip(mtd, 0);
dev_dbg(dev, "Scanning for an NCB fingerprint...\n");
for (stride = 0; stride < search_area_size_in_strides; stride++) {
page = stride * rom_geo->stride_size_in_pages;
byte = page * mtd->writesize;
dev_dbg(dev, "Looking for a fingerprint in page 0x%x\n", page);
chip->cmdfunc(mtd, NAND_CMD_READ0, 12, page);
chip->read_buf(mtd, buffer, strlen(fingerprint));
if (!memcmp(buffer, fingerprint, strlen(fingerprint))) {
found_an_ncb_fingerprint = true;
break;
}
}
chip->select_chip(mtd, saved_chip_number);
if (found_an_ncb_fingerprint)
dev_dbg(dev, "\tFound a fingerprint\n");
else
dev_dbg(dev, "\tNo fingerprint found\n");
return found_an_ncb_fingerprint;
}
static int __devinit mx23_write_transcription_stamp(struct gpmi_nand_data *this)
{
struct device *dev = this->dev;
struct boot_rom_geometry *rom_geo = &this->rom_geometry;
struct mtd_info *mtd = &this->mtd;
struct nand_chip *chip = &this->nand;
unsigned int block_size_in_pages;
unsigned int search_area_size_in_strides;
unsigned int search_area_size_in_pages;
unsigned int search_area_size_in_blocks;
unsigned int block;
unsigned int stride;
unsigned int page;
loff_t byte;
uint8_t *buffer = chip->buffers->databuf;
int saved_chip_number;
int status;
block_size_in_pages = mtd->erasesize / mtd->writesize;
search_area_size_in_strides = 1 << rom_geo->search_area_stride_exponent;
search_area_size_in_pages = search_area_size_in_strides *
rom_geo->stride_size_in_pages;
search_area_size_in_blocks =
(search_area_size_in_pages + (block_size_in_pages - 1)) /
block_size_in_pages;
dev_dbg(dev, "Search Area Geometry :\n");
dev_dbg(dev, "\tin Blocks : %u\n", search_area_size_in_blocks);
dev_dbg(dev, "\tin Strides: %u\n", search_area_size_in_strides);
dev_dbg(dev, "\tin Pages : %u\n", search_area_size_in_pages);
saved_chip_number = this->current_chip;
chip->select_chip(mtd, 0);
dev_dbg(dev, "Erasing the search area...\n");
for (block = 0; block < search_area_size_in_blocks; block++) {
page = block * block_size_in_pages;
dev_dbg(dev, "\tErasing block 0x%x\n", block);
chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page);
chip->cmdfunc(mtd, NAND_CMD_ERASE2, -1, -1);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL)
dev_err(dev, "[%s] Erase failed.\n", __func__);
}
memset(buffer, ~0, mtd->writesize);
memset(chip->oob_poi, ~0, mtd->oobsize);
memcpy(buffer + 12, fingerprint, strlen(fingerprint));
dev_dbg(dev, "Writing NCB fingerprints...\n");
for (stride = 0; stride < search_area_size_in_strides; stride++) {
page = stride * rom_geo->stride_size_in_pages;
byte = page * mtd->writesize;
dev_dbg(dev, "Writing an NCB fingerprint in page 0x%x\n", page);
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0x00, page);
chip->ecc.write_page_raw(mtd, chip, buffer);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
status = chip->waitfunc(mtd, chip);
if (status & NAND_STATUS_FAIL)
dev_err(dev, "[%s] Write failed.\n", __func__);
}
chip->select_chip(mtd, saved_chip_number);
return 0;
}
static int __devinit mx23_boot_init(struct gpmi_nand_data *this)
{
struct device *dev = this->dev;
struct nand_chip *chip = &this->nand;
struct mtd_info *mtd = &this->mtd;
unsigned int block_count;
unsigned int block;
int chipnr;
int page;
loff_t byte;
uint8_t block_mark;
int ret = 0;
if (mx23_check_transcription_stamp(this))
return 0;
dev_dbg(dev, "Transcribing bad block marks...\n");
block_count = chip->chipsize >> chip->phys_erase_shift;
for (block = 0; block < block_count; block++) {
chipnr = block >> (chip->chip_shift - chip->phys_erase_shift);
page = block << (chip->phys_erase_shift - chip->page_shift);
byte = block << chip->phys_erase_shift;
chip->select_chip(mtd, chipnr);
chip->cmdfunc(mtd, NAND_CMD_READ0, mtd->writesize, page);
block_mark = chip->read_byte(mtd);
chip->select_chip(mtd, -1);
if (block_mark != 0xff) {
dev_dbg(dev, "Transcribing mark in block %u\n", block);
ret = chip->block_markbad(mtd, byte);
if (ret)
dev_err(dev, "Failed to mark block bad with "
"ret %d\n", ret);
}
}
mx23_write_transcription_stamp(this);
return 0;
}
static int __devinit nand_boot_init(struct gpmi_nand_data *this)
{
nand_boot_set_geometry(this);
if (GPMI_IS_MX23(this))
return mx23_boot_init(this);
return 0;
}
static int __devinit gpmi_set_geometry(struct gpmi_nand_data *this)
{
int ret;
gpmi_free_dma_buffer(this);
ret = bch_set_geometry(this);
if (ret) {
pr_err("set geometry ret : %d\n", ret);
return ret;
}
return gpmi_alloc_dma_buffer(this);
}
static int gpmi_pre_bbt_scan(struct gpmi_nand_data *this)
{
int ret;
if (GPMI_IS_MX23(this))
this->swap_block_mark = false;
else
this->swap_block_mark = true;
ret = gpmi_set_geometry(this);
if (ret)
return ret;
return nand_boot_init(this);
}
static int gpmi_scan_bbt(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct gpmi_nand_data *this = chip->priv;
int ret;
ret = gpmi_pre_bbt_scan(this);
if (ret)
return ret;
return nand_default_bbt(mtd);
}
void gpmi_nfc_exit(struct gpmi_nand_data *this)
{
nand_release(&this->mtd);
gpmi_free_dma_buffer(this);
}
static int __devinit gpmi_nfc_init(struct gpmi_nand_data *this)
{
struct gpmi_nand_platform_data *pdata = this->pdata;
struct mtd_info *mtd = &this->mtd;
struct nand_chip *chip = &this->nand;
int ret;
this->current_chip = -1;
mtd->priv = chip;
mtd->name = "gpmi-nand";
mtd->owner = THIS_MODULE;
chip->priv = this;
chip->select_chip = gpmi_select_chip;
chip->cmd_ctrl = gpmi_cmd_ctrl;
chip->dev_ready = gpmi_dev_ready;
chip->read_byte = gpmi_read_byte;
chip->read_buf = gpmi_read_buf;
chip->write_buf = gpmi_write_buf;
chip->ecc.read_page = gpmi_ecc_read_page;
chip->ecc.write_page = gpmi_ecc_write_page;
chip->ecc.read_oob = gpmi_ecc_read_oob;
chip->ecc.write_oob = gpmi_ecc_write_oob;
chip->scan_bbt = gpmi_scan_bbt;
chip->badblock_pattern = &gpmi_bbt_descr;
chip->block_markbad = gpmi_block_markbad;
chip->options |= NAND_NO_SUBPAGE_WRITE;
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.size = 1;
chip->ecc.layout = &gpmi_hw_ecclayout;
this->bch_geometry.payload_size = 1024;
this->bch_geometry.auxiliary_size = 128;
ret = gpmi_alloc_dma_buffer(this);
if (ret)
goto err_out;
ret = nand_scan(mtd, pdata->max_chip_count);
if (ret) {
pr_err("Chip scan failed\n");
goto err_out;
}
ret = mtd_device_parse_register(mtd, NULL, NULL,
pdata->partitions, pdata->partition_count);
if (ret)
goto err_out;
return 0;
err_out:
gpmi_nfc_exit(this);
return ret;
}
static int __devinit gpmi_nand_probe(struct platform_device *pdev)
{
struct gpmi_nand_platform_data *pdata = pdev->dev.platform_data;
struct gpmi_nand_data *this;
int ret;
this = kzalloc(sizeof(*this), GFP_KERNEL);
if (!this) {
pr_err("Failed to allocate per-device memory\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, this);
this->pdev = pdev;
this->dev = &pdev->dev;
this->pdata = pdata;
if (pdata->platform_init) {
ret = pdata->platform_init();
if (ret)
goto platform_init_error;
}
ret = acquire_resources(this);
if (ret)
goto exit_acquire_resources;
ret = init_hardware(this);
if (ret)
goto exit_nfc_init;
ret = gpmi_nfc_init(this);
if (ret)
goto exit_nfc_init;
return 0;
exit_nfc_init:
release_resources(this);
platform_init_error:
exit_acquire_resources:
platform_set_drvdata(pdev, NULL);
kfree(this);
return ret;
}
static int __exit gpmi_nand_remove(struct platform_device *pdev)
{
struct gpmi_nand_data *this = platform_get_drvdata(pdev);
gpmi_nfc_exit(this);
release_resources(this);
platform_set_drvdata(pdev, NULL);
kfree(this);
return 0;
}
static int __init gpmi_nand_init(void)
{
int err;
err = platform_driver_register(&gpmi_nand_driver);
if (err == 0)
printk(KERN_INFO "GPMI NAND driver registered. (IMX)\n");
else
pr_err("i.MX GPMI NAND driver registration failed\n");
return err;
}
static void __exit gpmi_nand_exit(void)
{
platform_driver_unregister(&gpmi_nand_driver);
}
