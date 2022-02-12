static inline void hsu_chan_disable(struct hsu_dma_chan *hsuc)
{
hsu_chan_writel(hsuc, HSU_CH_CR, 0);
}
static inline void hsu_chan_enable(struct hsu_dma_chan *hsuc)
{
u32 cr = HSU_CH_CR_CHA;
if (hsuc->direction == DMA_MEM_TO_DEV)
cr &= ~HSU_CH_CR_CHD;
else if (hsuc->direction == DMA_DEV_TO_MEM)
cr |= HSU_CH_CR_CHD;
hsu_chan_writel(hsuc, HSU_CH_CR, cr);
}
static void hsu_dma_chan_start(struct hsu_dma_chan *hsuc)
{
struct dma_slave_config *config = &hsuc->config;
struct hsu_dma_desc *desc = hsuc->desc;
u32 bsr = 0, mtsr = 0;
u32 dcr = HSU_CH_DCR_CHSOE | HSU_CH_DCR_CHEI;
unsigned int i, count;
if (hsuc->direction == DMA_MEM_TO_DEV) {
bsr = config->dst_maxburst;
mtsr = config->src_addr_width;
} else if (hsuc->direction == DMA_DEV_TO_MEM) {
bsr = config->src_maxburst;
mtsr = config->dst_addr_width;
}
hsu_chan_disable(hsuc);
hsu_chan_writel(hsuc, HSU_CH_DCR, 0);
hsu_chan_writel(hsuc, HSU_CH_BSR, bsr);
hsu_chan_writel(hsuc, HSU_CH_MTSR, mtsr);
count = desc->nents - desc->active;
for (i = 0; i < count && i < HSU_DMA_CHAN_NR_DESC; i++) {
hsu_chan_writel(hsuc, HSU_CH_DxSAR(i), desc->sg[i].addr);
hsu_chan_writel(hsuc, HSU_CH_DxTSR(i), desc->sg[i].len);
dcr |= HSU_CH_DCR_DESCA(i);
dcr |= HSU_CH_DCR_CHTOI(i);
desc->active++;
}
dcr |= HSU_CH_DCR_CHSOD(count - 1);
dcr |= HSU_CH_DCR_CHDI(count - 1);
hsu_chan_writel(hsuc, HSU_CH_DCR, dcr);
hsu_chan_enable(hsuc);
}
static void hsu_dma_stop_channel(struct hsu_dma_chan *hsuc)
{
hsu_chan_disable(hsuc);
hsu_chan_writel(hsuc, HSU_CH_DCR, 0);
}
static void hsu_dma_start_channel(struct hsu_dma_chan *hsuc)
{
hsu_dma_chan_start(hsuc);
}
static void hsu_dma_start_transfer(struct hsu_dma_chan *hsuc)
{
struct virt_dma_desc *vdesc;
vdesc = vchan_next_desc(&hsuc->vchan);
if (!vdesc) {
hsuc->desc = NULL;
return;
}
list_del(&vdesc->node);
hsuc->desc = to_hsu_dma_desc(vdesc);
hsu_dma_start_channel(hsuc);
}
int hsu_dma_get_status(struct hsu_dma_chip *chip, unsigned short nr,
u32 *status)
{
struct hsu_dma_chan *hsuc;
unsigned long flags;
u32 sr;
if (nr >= chip->hsu->nr_channels)
return -EINVAL;
hsuc = &chip->hsu->chan[nr];
spin_lock_irqsave(&hsuc->vchan.lock, flags);
sr = hsu_chan_readl(hsuc, HSU_CH_SR);
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
sr &= ~(HSU_CH_SR_DESCE_ANY | HSU_CH_SR_CDESC_ANY);
if (!sr)
return -EIO;
if (sr & HSU_CH_SR_DESCTO_ANY)
udelay(2);
sr &= ~HSU_CH_SR_DESCTO_ANY;
*status = sr;
return sr ? 0 : 1;
}
irqreturn_t hsu_dma_do_irq(struct hsu_dma_chip *chip, unsigned short nr,
u32 status)
{
struct hsu_dma_chan *hsuc;
struct hsu_dma_desc *desc;
unsigned long flags;
if (nr >= chip->hsu->nr_channels)
return IRQ_NONE;
hsuc = &chip->hsu->chan[nr];
spin_lock_irqsave(&hsuc->vchan.lock, flags);
desc = hsuc->desc;
if (desc) {
if (status & HSU_CH_SR_CHE) {
desc->status = DMA_ERROR;
} else if (desc->active < desc->nents) {
hsu_dma_start_channel(hsuc);
} else {
vchan_cookie_complete(&desc->vdesc);
desc->status = DMA_COMPLETE;
hsu_dma_start_transfer(hsuc);
}
}
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
return IRQ_HANDLED;
}
static struct hsu_dma_desc *hsu_dma_alloc_desc(unsigned int nents)
{
struct hsu_dma_desc *desc;
desc = kzalloc(sizeof(*desc), GFP_NOWAIT);
if (!desc)
return NULL;
desc->sg = kcalloc(nents, sizeof(*desc->sg), GFP_NOWAIT);
if (!desc->sg) {
kfree(desc);
return NULL;
}
return desc;
}
static void hsu_dma_desc_free(struct virt_dma_desc *vdesc)
{
struct hsu_dma_desc *desc = to_hsu_dma_desc(vdesc);
kfree(desc->sg);
kfree(desc);
}
static struct dma_async_tx_descriptor *hsu_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
struct hsu_dma_desc *desc;
struct scatterlist *sg;
unsigned int i;
desc = hsu_dma_alloc_desc(sg_len);
if (!desc)
return NULL;
for_each_sg(sgl, sg, sg_len, i) {
desc->sg[i].addr = sg_dma_address(sg);
desc->sg[i].len = sg_dma_len(sg);
desc->length += sg_dma_len(sg);
}
desc->nents = sg_len;
desc->direction = direction;
desc->status = DMA_IN_PROGRESS;
return vchan_tx_prep(&hsuc->vchan, &desc->vdesc, flags);
}
static void hsu_dma_issue_pending(struct dma_chan *chan)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&hsuc->vchan.lock, flags);
if (vchan_issue_pending(&hsuc->vchan) && !hsuc->desc)
hsu_dma_start_transfer(hsuc);
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
}
static size_t hsu_dma_active_desc_size(struct hsu_dma_chan *hsuc)
{
struct hsu_dma_desc *desc = hsuc->desc;
size_t bytes = 0;
int i;
for (i = desc->active; i < desc->nents; i++)
bytes += desc->sg[i].len;
i = HSU_DMA_CHAN_NR_DESC - 1;
do {
bytes += hsu_chan_readl(hsuc, HSU_CH_DxTSR(i));
} while (--i >= 0);
return bytes;
}
static enum dma_status hsu_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *state)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
struct virt_dma_desc *vdesc;
enum dma_status status;
size_t bytes;
unsigned long flags;
status = dma_cookie_status(chan, cookie, state);
if (status == DMA_COMPLETE)
return status;
spin_lock_irqsave(&hsuc->vchan.lock, flags);
vdesc = vchan_find_desc(&hsuc->vchan, cookie);
if (hsuc->desc && cookie == hsuc->desc->vdesc.tx.cookie) {
bytes = hsu_dma_active_desc_size(hsuc);
dma_set_residue(state, bytes);
status = hsuc->desc->status;
} else if (vdesc) {
bytes = to_hsu_dma_desc(vdesc)->length;
dma_set_residue(state, bytes);
}
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
return status;
}
static int hsu_dma_slave_config(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
if (!is_slave_direction(config->direction))
return -EINVAL;
memcpy(&hsuc->config, config, sizeof(hsuc->config));
return 0;
}
static int hsu_dma_pause(struct dma_chan *chan)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&hsuc->vchan.lock, flags);
if (hsuc->desc && hsuc->desc->status == DMA_IN_PROGRESS) {
hsu_chan_disable(hsuc);
hsuc->desc->status = DMA_PAUSED;
}
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
return 0;
}
static int hsu_dma_resume(struct dma_chan *chan)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&hsuc->vchan.lock, flags);
if (hsuc->desc && hsuc->desc->status == DMA_PAUSED) {
hsuc->desc->status = DMA_IN_PROGRESS;
hsu_chan_enable(hsuc);
}
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
return 0;
}
static int hsu_dma_terminate_all(struct dma_chan *chan)
{
struct hsu_dma_chan *hsuc = to_hsu_dma_chan(chan);
unsigned long flags;
LIST_HEAD(head);
spin_lock_irqsave(&hsuc->vchan.lock, flags);
hsu_dma_stop_channel(hsuc);
if (hsuc->desc) {
hsu_dma_desc_free(&hsuc->desc->vdesc);
hsuc->desc = NULL;
}
vchan_get_all_descriptors(&hsuc->vchan, &head);
spin_unlock_irqrestore(&hsuc->vchan.lock, flags);
vchan_dma_desc_free_list(&hsuc->vchan, &head);
return 0;
}
static void hsu_dma_free_chan_resources(struct dma_chan *chan)
{
vchan_free_chan_resources(to_virt_chan(chan));
}
int hsu_dma_probe(struct hsu_dma_chip *chip)
{
struct hsu_dma *hsu;
void __iomem *addr = chip->regs + chip->offset;
unsigned short i;
int ret;
hsu = devm_kzalloc(chip->dev, sizeof(*hsu), GFP_KERNEL);
if (!hsu)
return -ENOMEM;
chip->hsu = hsu;
hsu->nr_channels = (chip->length - chip->offset) / HSU_DMA_CHAN_LENGTH;
hsu->chan = devm_kcalloc(chip->dev, hsu->nr_channels,
sizeof(*hsu->chan), GFP_KERNEL);
if (!hsu->chan)
return -ENOMEM;
INIT_LIST_HEAD(&hsu->dma.channels);
for (i = 0; i < hsu->nr_channels; i++) {
struct hsu_dma_chan *hsuc = &hsu->chan[i];
hsuc->vchan.desc_free = hsu_dma_desc_free;
vchan_init(&hsuc->vchan, &hsu->dma);
hsuc->direction = (i & 0x1) ? DMA_DEV_TO_MEM : DMA_MEM_TO_DEV;
hsuc->reg = addr + i * HSU_DMA_CHAN_LENGTH;
}
dma_cap_set(DMA_SLAVE, hsu->dma.cap_mask);
dma_cap_set(DMA_PRIVATE, hsu->dma.cap_mask);
hsu->dma.device_free_chan_resources = hsu_dma_free_chan_resources;
hsu->dma.device_prep_slave_sg = hsu_dma_prep_slave_sg;
hsu->dma.device_issue_pending = hsu_dma_issue_pending;
hsu->dma.device_tx_status = hsu_dma_tx_status;
hsu->dma.device_config = hsu_dma_slave_config;
hsu->dma.device_pause = hsu_dma_pause;
hsu->dma.device_resume = hsu_dma_resume;
hsu->dma.device_terminate_all = hsu_dma_terminate_all;
hsu->dma.src_addr_widths = HSU_DMA_BUSWIDTHS;
hsu->dma.dst_addr_widths = HSU_DMA_BUSWIDTHS;
hsu->dma.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
hsu->dma.residue_granularity = DMA_RESIDUE_GRANULARITY_BURST;
hsu->dma.dev = chip->dev;
dma_set_max_seg_size(hsu->dma.dev, HSU_CH_DxTSR_MASK);
ret = dma_async_device_register(&hsu->dma);
if (ret)
return ret;
dev_info(chip->dev, "Found HSU DMA, %d channels\n", hsu->nr_channels);
return 0;
}
int hsu_dma_remove(struct hsu_dma_chip *chip)
{
struct hsu_dma *hsu = chip->hsu;
unsigned short i;
dma_async_device_unregister(&hsu->dma);
for (i = 0; i < hsu->nr_channels; i++) {
struct hsu_dma_chan *hsuc = &hsu->chan[i];
tasklet_kill(&hsuc->vchan.task);
}
return 0;
}
