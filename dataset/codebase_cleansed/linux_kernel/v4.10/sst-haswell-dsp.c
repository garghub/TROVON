static int hsw_parse_module(struct sst_dsp *dsp, struct sst_fw *fw,
struct fw_module_header *module)
{
struct dma_block_info *block;
struct sst_module *mod;
struct sst_module_template template;
int count, ret;
void __iomem *ram;
if (module->type != SST_HSW_MODULE_BASE_FW
&& module->type != SST_HSW_MODULE_PCM_SYSTEM
&& module->type != SST_HSW_MODULE_PCM
&& module->type != SST_HSW_MODULE_PCM_REFERENCE
&& module->type != SST_HSW_MODULE_PCM_CAPTURE
&& module->type != SST_HSW_MODULE_WAVES
&& module->type != SST_HSW_MODULE_LPAL)
return 0;
dev_dbg(dsp->dev, "new module sign 0x%s size 0x%x blocks 0x%x type 0x%x\n",
module->signature, module->mod_size,
module->blocks, module->type);
dev_dbg(dsp->dev, " entrypoint 0x%x\n", module->entry_point);
dev_dbg(dsp->dev, " persistent 0x%x scratch 0x%x\n",
module->info.persistent_size, module->info.scratch_size);
memset(&template, 0, sizeof(template));
template.id = module->type;
template.entry = module->entry_point - 4;
template.persistent_size = module->info.persistent_size;
template.scratch_size = module->info.scratch_size;
mod = sst_module_new(fw, &template, NULL);
if (mod == NULL)
return -ENOMEM;
block = (void *)module + sizeof(*module);
for (count = 0; count < module->blocks; count++) {
if (block->size <= 0) {
dev_err(dsp->dev,
"error: block %d size invalid\n", count);
sst_module_free(mod);
return -EINVAL;
}
switch (block->type) {
case SST_HSW_IRAM:
ram = dsp->addr.lpe;
mod->offset =
block->ram_offset + dsp->addr.iram_offset;
mod->type = SST_MEM_IRAM;
break;
case SST_HSW_DRAM:
case SST_HSW_REGS:
ram = dsp->addr.lpe;
mod->offset = block->ram_offset;
mod->type = SST_MEM_DRAM;
break;
default:
dev_err(dsp->dev, "error: bad type 0x%x for block 0x%x\n",
block->type, count);
sst_module_free(mod);
return -EINVAL;
}
mod->size = block->size;
mod->data = (void *)block + sizeof(*block);
mod->data_offset = mod->data - fw->dma_buf;
dev_dbg(dsp->dev, "module block %d type 0x%x "
"size 0x%x ==> ram %p offset 0x%x\n",
count, mod->type, block->size, ram,
block->ram_offset);
ret = sst_module_alloc_blocks(mod);
if (ret < 0) {
dev_err(dsp->dev, "error: could not allocate blocks for module %d\n",
count);
sst_module_free(mod);
return ret;
}
block = (void *)block + sizeof(*block) + block->size;
}
mod->state = SST_MODULE_STATE_LOADED;
return 0;
}
static int hsw_parse_fw_image(struct sst_fw *sst_fw)
{
struct fw_header *header;
struct fw_module_header *module;
struct sst_dsp *dsp = sst_fw->dsp;
int ret, count;
header = (struct fw_header *)sst_fw->dma_buf;
if ((strncmp(header->signature, SST_HSW_FW_SIGN, 4) != 0) ||
(sst_fw->size != header->file_size + sizeof(*header))) {
dev_err(dsp->dev, "error: invalid fw sign/filesize mismatch\n");
return -EINVAL;
}
dev_dbg(dsp->dev, "header size=0x%x modules=0x%x fmt=0x%x size=%zu\n",
header->file_size, header->modules,
header->file_format, sizeof(*header));
module = (void *)sst_fw->dma_buf + sizeof(*header);
for (count = 0; count < header->modules; count++) {
ret = hsw_parse_module(dsp, sst_fw, module);
if (ret < 0) {
dev_err(dsp->dev, "error: invalid module %d\n", count);
return ret;
}
module = (void *)module + sizeof(*module) + module->mod_size;
}
return 0;
}
static irqreturn_t hsw_irq(int irq, void *context)
{
struct sst_dsp *sst = (struct sst_dsp *) context;
u32 isr;
int ret = IRQ_NONE;
spin_lock(&sst->spinlock);
isr = sst_dsp_shim_read_unlocked(sst, SST_ISRX);
if (isr & SST_ISRX_DONE) {
trace_sst_irq_done(isr,
sst_dsp_shim_read_unlocked(sst, SST_IMRX));
sst_dsp_shim_update_bits_unlocked(sst, SST_IMRX,
SST_IMRX_DONE, SST_IMRX_DONE);
ret = IRQ_WAKE_THREAD;
}
if (isr & SST_ISRX_BUSY) {
trace_sst_irq_busy(isr,
sst_dsp_shim_read_unlocked(sst, SST_IMRX));
sst_dsp_shim_update_bits_unlocked(sst, SST_IMRX,
SST_IMRX_BUSY, SST_IMRX_BUSY);
ret = IRQ_WAKE_THREAD;
}
spin_unlock(&sst->spinlock);
return ret;
}
static void hsw_set_dsp_D3(struct sst_dsp *sst)
{
u32 val;
u32 reg;
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
reg &= ~(SST_VDRTCL2_DCLCGE | SST_VDRTCL2_DTCGE);
writel(reg, sst->addr.pci_cfg + SST_VDRTCTL2);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL0);
val |= SST_VDRTCL0_DSRAMPGE_MASK |
SST_VDRTCL0_ISRAMPGE_MASK;
val &= ~(SST_VDRTCL0_D3PGD | SST_VDRTCL0_D3SRAMPGD);
writel(val, sst->addr.pci_cfg + SST_VDRTCTL0);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
val |= SST_VDRTCL2_APLLSE_MASK;
writel(val, sst->addr.pci_cfg + SST_VDRTCTL2);
sst_dsp_shim_update_bits_unlocked(sst, SST_CLKCTL,
SST_CLKCTL_MASK, 0);
val = readl(sst->addr.pci_cfg + SST_PMCS);
val |= SST_PMCS_PS_MASK;
writel(val, sst->addr.pci_cfg + SST_PMCS);
udelay(50);
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
reg |= SST_VDRTCL2_DCLCGE | SST_VDRTCL2_DTCGE;
writel(reg, sst->addr.pci_cfg + SST_VDRTCTL2);
udelay(50);
}
static void hsw_reset(struct sst_dsp *sst)
{
sst_dsp_shim_update_bits_unlocked(sst, SST_CSR,
SST_CSR_RST | SST_CSR_STALL,
SST_CSR_RST | SST_CSR_STALL);
mdelay(10);
sst_dsp_shim_update_bits_unlocked(sst, SST_CSR,
SST_CSR_RST | SST_CSR_STALL, SST_CSR_STALL);
}
static int hsw_set_dsp_D0(struct sst_dsp *sst)
{
int tries = 10;
u32 reg, fw_dump_bit;
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
reg &= ~(SST_VDRTCL2_DCLCGE | SST_VDRTCL2_DTCGE);
writel(reg, sst->addr.pci_cfg + SST_VDRTCTL2);
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL0);
reg |= SST_VDRTCL0_D3PGD;
writel(reg, sst->addr.pci_cfg + SST_VDRTCTL0);
reg = readl(sst->addr.pci_cfg + SST_PMCS);
reg &= ~SST_PMCS_PS_MASK;
writel(reg, sst->addr.pci_cfg + SST_PMCS);
while (tries--) {
reg = readl(sst->addr.pci_cfg + SST_PMCS) & SST_PMCS_PS_MASK;
if (reg == 0)
goto finish;
msleep(1);
}
return -ENODEV;
finish:
sst_dsp_shim_update_bits_unlocked(sst, SST_CSR,
SST_CSR_S1IOCS | SST_CSR_SBCS1 | SST_CSR_LPCS, 0x0);
sst_dsp_shim_update_bits_unlocked(sst,
SST_CSR, SST_CSR_STALL | SST_CSR_DCS_MASK,
SST_CSR_STALL | SST_CSR_DCS(4));
sst_dsp_shim_update_bits_unlocked(sst, SST_CLKCTL,
SST_CLKCTL_MASK | SST_CLKCTL_DCPLCG | SST_CLKCTL_SCOE0,
SST_CLKCTL_MASK | SST_CLKCTL_DCPLCG | SST_CLKCTL_SCOE0);
hsw_reset(sst);
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
reg |= SST_VDRTCL2_DCLCGE | SST_VDRTCL2_DTCGE;
writel(reg, sst->addr.pci_cfg + SST_VDRTCTL2);
udelay(50);
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
reg &= ~SST_VDRTCL2_APLLSE_MASK;
writel(reg, sst->addr.pci_cfg + SST_VDRTCTL2);
reg = readl(sst->addr.pci_cfg + SST_VDRTCTL0);
reg |= SST_VDRTCL0_DSRAMPGE_MASK | SST_VDRTCL0_ISRAMPGE_MASK;
fw_dump_bit = 1 << SST_VDRTCL0_DSRAMPGE_SHIFT;
writel(reg & ~fw_dump_bit, sst->addr.pci_cfg + SST_VDRTCTL0);
sst_dsp_shim_update_bits_unlocked(sst, SST_CSR2, SST_CSR2_SDFD_SSP1,
SST_CSR2_SDFD_SSP1);
sst_dsp_shim_update_bits(sst, SST_HMDC,
SST_HMDC_HDDA_E0_ALLCH | SST_HMDC_HDDA_E1_ALLCH,
SST_HMDC_HDDA_E0_ALLCH | SST_HMDC_HDDA_E1_ALLCH);
sst_dsp_shim_update_bits(sst, SST_IMRX, (SST_IMRX_BUSY | SST_IMRX_DONE),
0x0);
sst_dsp_shim_update_bits(sst, SST_IMRD, (SST_IMRD_DONE | SST_IMRD_BUSY |
SST_IMRD_SSP0 | SST_IMRD_DMAC), 0x0);
sst_dsp_shim_write(sst, SST_IPCX, 0x0);
sst_dsp_shim_write(sst, SST_IPCD, 0x0);
sst_dsp_shim_write(sst, 0x80, 0x6);
sst_dsp_shim_write(sst, 0xe0, 0x300a);
return 0;
}
static void hsw_boot(struct sst_dsp *sst)
{
sst_dsp_shim_update_bits(sst, SST_HMDC,
SST_HMDC_HDDA_E0_ALLCH | SST_HMDC_HDDA_E1_ALLCH, 0);
sst_dsp_shim_update_bits_unlocked(sst, SST_CSR, SST_CSR_STALL, 0x0);
}
static void hsw_stall(struct sst_dsp *sst)
{
sst_dsp_shim_update_bits(sst, SST_CSR,
SST_CSR_24MHZ_LPCS | SST_CSR_STALL,
SST_CSR_STALL | SST_CSR_24MHZ_LPCS);
}
static void hsw_sleep(struct sst_dsp *sst)
{
dev_dbg(sst->dev, "HSW_PM dsp runtime suspend\n");
sst_dsp_shim_update_bits(sst, SST_CSR,
SST_CSR_24MHZ_LPCS | SST_CSR_RST | SST_CSR_STALL,
SST_CSR_RST | SST_CSR_STALL | SST_CSR_24MHZ_LPCS);
hsw_set_dsp_D3(sst);
dev_dbg(sst->dev, "HSW_PM dsp runtime suspend exit\n");
}
static int hsw_wake(struct sst_dsp *sst)
{
int ret;
dev_dbg(sst->dev, "HSW_PM dsp runtime resume\n");
ret = hsw_set_dsp_D0(sst);
if (ret < 0)
return ret;
dev_dbg(sst->dev, "HSW_PM dsp runtime resume exit\n");
return 0;
}
static int hsw_acpi_resource_map(struct sst_dsp *sst, struct sst_pdata *pdata)
{
sst->addr.lpe_base = pdata->lpe_base;
sst->addr.lpe = ioremap(pdata->lpe_base, pdata->lpe_size);
if (!sst->addr.lpe)
return -ENODEV;
sst->addr.pci_cfg = ioremap(pdata->pcicfg_base, pdata->pcicfg_size);
if (!sst->addr.pci_cfg) {
iounmap(sst->addr.lpe);
return -ENODEV;
}
sst->addr.shim = sst->addr.lpe + sst->addr.shim_offset;
return 0;
}
static u32 hsw_block_get_bit(struct sst_mem_block *block)
{
u32 bit = 0, shift = 0, index;
struct sst_dsp *sst = block->dsp;
for (index = 0; index < ARRAY_SIZE(sram_shift); index++) {
if (sram_shift[index].dev_id == sst->id)
break;
}
if (index < ARRAY_SIZE(sram_shift)) {
switch (block->type) {
case SST_MEM_DRAM:
shift = sram_shift[index].dram_shift;
break;
case SST_MEM_IRAM:
shift = sram_shift[index].iram_shift;
break;
default:
shift = 0;
}
} else
shift = 0;
bit = 1 << (block->index + shift);
return bit;
}
static void sst_mem_block_dummy_read(struct sst_mem_block *block)
{
u32 size;
u8 tmp_buf[4];
struct sst_dsp *sst = block->dsp;
size = block->size > 4 ? 4 : block->size;
memcpy_fromio(tmp_buf, sst->addr.lpe + block->offset, size);
}
static int hsw_block_enable(struct sst_mem_block *block)
{
struct sst_dsp *sst = block->dsp;
u32 bit, val;
if (block->users++ > 0)
return 0;
dev_dbg(block->dsp->dev, " enabled block %d:%d at offset 0x%x\n",
block->type, block->index, block->offset);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
val &= ~SST_VDRTCL2_DCLCGE;
writel(val, sst->addr.pci_cfg + SST_VDRTCTL2);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL0);
bit = hsw_block_get_bit(block);
writel(val & ~bit, sst->addr.pci_cfg + SST_VDRTCTL0);
udelay(10);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
val |= SST_VDRTCL2_DCLCGE;
writel(val, sst->addr.pci_cfg + SST_VDRTCTL2);
udelay(50);
sst_mem_block_dummy_read(block);
return 0;
}
static int hsw_block_disable(struct sst_mem_block *block)
{
struct sst_dsp *sst = block->dsp;
u32 bit, val;
if (--block->users > 0)
return 0;
dev_dbg(block->dsp->dev, " disabled block %d:%d at offset 0x%x\n",
block->type, block->index, block->offset);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
val &= ~SST_VDRTCL2_DCLCGE;
writel(val, sst->addr.pci_cfg + SST_VDRTCTL2);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL0);
bit = hsw_block_get_bit(block);
if (bit != (1 << SST_VDRTCL0_DSRAMPGE_SHIFT))
writel(val | bit, sst->addr.pci_cfg + SST_VDRTCTL0);
udelay(10);
val = readl(sst->addr.pci_cfg + SST_VDRTCTL2);
val |= SST_VDRTCL2_DCLCGE;
writel(val, sst->addr.pci_cfg + SST_VDRTCTL2);
udelay(50);
return 0;
}
static int hsw_init(struct sst_dsp *sst, struct sst_pdata *pdata)
{
const struct sst_adsp_memregion *region;
struct device *dev;
int ret = -ENODEV, i, j, region_count;
u32 offset, size, fw_dump_bit;
dev = sst->dma_dev;
switch (sst->id) {
case SST_DEV_ID_LYNX_POINT:
region = lp_region;
region_count = ARRAY_SIZE(lp_region);
sst->addr.iram_offset = SST_LP_IRAM_OFFSET;
sst->addr.dsp_iram_offset = SST_LPT_DSP_IRAM_OFFSET;
sst->addr.dsp_dram_offset = SST_LPT_DSP_DRAM_OFFSET;
sst->addr.shim_offset = SST_LP_SHIM_OFFSET;
break;
case SST_DEV_ID_WILDCAT_POINT:
region = wpt_region;
region_count = ARRAY_SIZE(wpt_region);
sst->addr.iram_offset = SST_WPT_IRAM_OFFSET;
sst->addr.dsp_iram_offset = SST_WPT_DSP_IRAM_OFFSET;
sst->addr.dsp_dram_offset = SST_WPT_DSP_DRAM_OFFSET;
sst->addr.shim_offset = SST_WPT_SHIM_OFFSET;
break;
default:
dev_err(dev, "error: failed to get mem resources\n");
return ret;
}
ret = hsw_acpi_resource_map(sst, pdata);
if (ret < 0) {
dev_err(dev, "error: failed to map resources\n");
return ret;
}
ret = hsw_set_dsp_D0(sst);
if (ret < 0) {
dev_err(dev, "error: failed to set DSP D0 and reset SHIM\n");
return ret;
}
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(31));
if (ret)
return ret;
for (i = 0; i < region_count; i++) {
offset = region[i].start;
size = (region[i].end - region[i].start) / region[i].blocks;
for (j = 0; j < region[i].blocks; j++) {
sst_mem_block_register(sst, offset, size,
region[i].type, &sst_hsw_ops, j, sst);
offset += size;
}
}
fw_dump_bit = 1 << SST_VDRTCL0_DSRAMPGE_SHIFT;
writel(0xffffffff & ~fw_dump_bit, sst->addr.pci_cfg + SST_VDRTCTL0);
return 0;
}
static void hsw_free(struct sst_dsp *sst)
{
sst_mem_block_unregister_all(sst);
iounmap(sst->addr.lpe);
iounmap(sst->addr.pci_cfg);
}
