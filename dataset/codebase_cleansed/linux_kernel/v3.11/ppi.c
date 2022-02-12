static irqreturn_t ppi_irq_err(int irq, void *dev_id)
{
struct ppi_if *ppi = dev_id;
const struct ppi_info *info = ppi->info;
switch (info->type) {
case PPI_TYPE_PPI:
{
struct bfin_ppi_regs *reg = info->base;
unsigned short status;
status = bfin_read16(&reg->status);
if (status & 0x3000)
ppi->err = true;
bfin_write16(&reg->status, 0xff00);
break;
}
case PPI_TYPE_EPPI:
{
struct bfin_eppi_regs *reg = info->base;
unsigned short status;
status = bfin_read16(&reg->status);
if (status & 0x2)
ppi->err = true;
bfin_write16(&reg->status, 0xffff);
break;
}
case PPI_TYPE_EPPI3:
{
struct bfin_eppi3_regs *reg = info->base;
unsigned long stat;
stat = bfin_read32(&reg->stat);
if (stat & 0x2)
ppi->err = true;
bfin_write32(&reg->stat, 0xc0ff);
break;
}
default:
break;
}
return IRQ_HANDLED;
}
static int ppi_attach_irq(struct ppi_if *ppi, irq_handler_t handler)
{
const struct ppi_info *info = ppi->info;
int ret;
ret = request_dma(info->dma_ch, "PPI_DMA");
if (ret) {
pr_err("Unable to allocate DMA channel for PPI\n");
return ret;
}
set_dma_callback(info->dma_ch, handler, ppi);
if (ppi->err_int) {
ret = request_irq(info->irq_err, ppi_irq_err, 0, "PPI ERROR", ppi);
if (ret) {
pr_err("Unable to allocate IRQ for PPI\n");
free_dma(info->dma_ch);
}
}
return ret;
}
static void ppi_detach_irq(struct ppi_if *ppi)
{
const struct ppi_info *info = ppi->info;
if (ppi->err_int)
free_irq(info->irq_err, ppi);
free_dma(info->dma_ch);
}
static int ppi_start(struct ppi_if *ppi)
{
const struct ppi_info *info = ppi->info;
enable_dma(info->dma_ch);
ppi->ppi_control |= PORT_EN;
switch (info->type) {
case PPI_TYPE_PPI:
{
struct bfin_ppi_regs *reg = info->base;
bfin_write16(&reg->control, ppi->ppi_control);
break;
}
case PPI_TYPE_EPPI:
{
struct bfin_eppi_regs *reg = info->base;
bfin_write32(&reg->control, ppi->ppi_control);
break;
}
case PPI_TYPE_EPPI3:
{
struct bfin_eppi3_regs *reg = info->base;
bfin_write32(&reg->ctl, ppi->ppi_control);
break;
}
default:
return -EINVAL;
}
SSYNC();
return 0;
}
static int ppi_stop(struct ppi_if *ppi)
{
const struct ppi_info *info = ppi->info;
ppi->ppi_control &= ~PORT_EN;
switch (info->type) {
case PPI_TYPE_PPI:
{
struct bfin_ppi_regs *reg = info->base;
bfin_write16(&reg->control, ppi->ppi_control);
break;
}
case PPI_TYPE_EPPI:
{
struct bfin_eppi_regs *reg = info->base;
bfin_write32(&reg->control, ppi->ppi_control);
break;
}
case PPI_TYPE_EPPI3:
{
struct bfin_eppi3_regs *reg = info->base;
bfin_write32(&reg->ctl, ppi->ppi_control);
break;
}
default:
return -EINVAL;
}
clear_dma_irqstat(info->dma_ch);
disable_dma(info->dma_ch);
SSYNC();
return 0;
}
static int ppi_set_params(struct ppi_if *ppi, struct ppi_params *params)
{
const struct ppi_info *info = ppi->info;
int dma32 = 0;
int dma_config, bytes_per_line;
int hcount, hdelay, samples_per_line;
bytes_per_line = params->width * params->bpp / 8;
hcount = params->width * params->bpp / params->dlen;
hdelay = params->hdelay * params->bpp / params->dlen;
samples_per_line = params->line * params->bpp / params->dlen;
if (params->int_mask == 0xFFFFFFFF)
ppi->err_int = false;
else
ppi->err_int = true;
dma_config = (DMA_FLOW_STOP | RESTART | DMA2D | DI_EN_Y);
ppi->ppi_control = params->ppi_control & ~PORT_EN;
if (!(ppi->ppi_control & PORT_DIR))
dma_config |= WNR;
switch (info->type) {
case PPI_TYPE_PPI:
{
struct bfin_ppi_regs *reg = info->base;
if (params->ppi_control & DMA32)
dma32 = 1;
bfin_write16(&reg->control, ppi->ppi_control);
bfin_write16(&reg->count, samples_per_line - 1);
bfin_write16(&reg->frame, params->frame);
break;
}
case PPI_TYPE_EPPI:
{
struct bfin_eppi_regs *reg = info->base;
if ((params->ppi_control & PACK_EN)
|| (params->ppi_control & 0x38000) > DLEN_16)
dma32 = 1;
bfin_write32(&reg->control, ppi->ppi_control);
bfin_write16(&reg->line, samples_per_line);
bfin_write16(&reg->frame, params->frame);
bfin_write16(&reg->hdelay, hdelay);
bfin_write16(&reg->vdelay, params->vdelay);
bfin_write16(&reg->hcount, hcount);
bfin_write16(&reg->vcount, params->height);
break;
}
case PPI_TYPE_EPPI3:
{
struct bfin_eppi3_regs *reg = info->base;
if ((params->ppi_control & PACK_EN)
|| (params->ppi_control & 0x70000) > DLEN_16)
dma32 = 1;
bfin_write32(&reg->ctl, ppi->ppi_control);
bfin_write32(&reg->line, samples_per_line);
bfin_write32(&reg->frame, params->frame);
bfin_write32(&reg->hdly, hdelay);
bfin_write32(&reg->vdly, params->vdelay);
bfin_write32(&reg->hcnt, hcount);
bfin_write32(&reg->vcnt, params->height);
if (params->int_mask)
bfin_write32(&reg->imsk, params->int_mask & 0xFF);
if (ppi->ppi_control & PORT_DIR) {
u32 hsync_width, vsync_width, vsync_period;
hsync_width = params->hsync
* params->bpp / params->dlen;
vsync_width = params->vsync * samples_per_line;
vsync_period = samples_per_line * params->frame;
bfin_write32(&reg->fs1_wlhb, hsync_width);
bfin_write32(&reg->fs1_paspl, samples_per_line);
bfin_write32(&reg->fs2_wlvb, vsync_width);
bfin_write32(&reg->fs2_palpf, vsync_period);
}
break;
}
default:
return -EINVAL;
}
if (dma32) {
dma_config |= WDSIZE_32 | PSIZE_32;
set_dma_x_count(info->dma_ch, bytes_per_line >> 2);
set_dma_x_modify(info->dma_ch, 4);
set_dma_y_modify(info->dma_ch, 4);
} else {
dma_config |= WDSIZE_16 | PSIZE_16;
set_dma_x_count(info->dma_ch, bytes_per_line >> 1);
set_dma_x_modify(info->dma_ch, 2);
set_dma_y_modify(info->dma_ch, 2);
}
set_dma_y_count(info->dma_ch, params->height);
set_dma_config(info->dma_ch, dma_config);
SSYNC();
return 0;
}
static void ppi_update_addr(struct ppi_if *ppi, unsigned long addr)
{
set_dma_start_addr(ppi->info->dma_ch, addr);
}
struct ppi_if *ppi_create_instance(const struct ppi_info *info)
{
struct ppi_if *ppi;
if (!info || !info->pin_req)
return NULL;
if (peripheral_request_list(info->pin_req, KBUILD_MODNAME)) {
pr_err("request peripheral failed\n");
return NULL;
}
ppi = kzalloc(sizeof(*ppi), GFP_KERNEL);
if (!ppi) {
peripheral_free_list(info->pin_req);
pr_err("unable to allocate memory for ppi handle\n");
return NULL;
}
ppi->ops = &ppi_ops;
ppi->info = info;
pr_info("ppi probe success\n");
return ppi;
}
void ppi_delete_instance(struct ppi_if *ppi)
{
peripheral_free_list(ppi->info->pin_req);
kfree(ppi);
}
