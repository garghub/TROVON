static void omap24xxcam_dmahw_ack_all(unsigned long base)
{
u32 csr;
int i;
for (i = 0; i < NUM_CAMDMA_CHANNELS; ++i) {
csr = omap24xxcam_reg_in(base, CAMDMA_CSR(i));
omap24xxcam_reg_out(base, CAMDMA_CSR(i), csr);
}
omap24xxcam_reg_out(base, CAMDMA_IRQSTATUS_L0, 0xf);
}
static u32 omap24xxcam_dmahw_ack_ch(unsigned long base, int dmach)
{
u32 csr;
csr = omap24xxcam_reg_in(base, CAMDMA_CSR(dmach));
omap24xxcam_reg_out(base, CAMDMA_CSR(dmach), csr);
omap24xxcam_reg_out(base, CAMDMA_IRQSTATUS_L0, (1 << dmach));
return csr;
}
static int omap24xxcam_dmahw_running(unsigned long base, int dmach)
{
return omap24xxcam_reg_in(base, CAMDMA_CCR(dmach)) & CAMDMA_CCR_ENABLE;
}
static void omap24xxcam_dmahw_transfer_setup(unsigned long base, int dmach,
dma_addr_t start, u32 len)
{
omap24xxcam_reg_out(base, CAMDMA_CCR(dmach),
CAMDMA_CCR_SEL_SRC_DST_SYNC
| CAMDMA_CCR_BS
| CAMDMA_CCR_DST_AMODE_POST_INC
| CAMDMA_CCR_SRC_AMODE_POST_INC
| CAMDMA_CCR_FS
| CAMDMA_CCR_WR_ACTIVE
| CAMDMA_CCR_RD_ACTIVE
| CAMDMA_CCR_SYNCHRO_CAMERA);
omap24xxcam_reg_out(base, CAMDMA_CLNK_CTRL(dmach), 0);
omap24xxcam_reg_out(base, CAMDMA_CEN(dmach), len);
omap24xxcam_reg_out(base, CAMDMA_CFN(dmach), 1);
omap24xxcam_reg_out(base, CAMDMA_CSDP(dmach),
CAMDMA_CSDP_WRITE_MODE_POSTED
| CAMDMA_CSDP_DST_BURST_EN_32
| CAMDMA_CSDP_DST_PACKED
| CAMDMA_CSDP_SRC_BURST_EN_32
| CAMDMA_CSDP_SRC_PACKED
| CAMDMA_CSDP_DATA_TYPE_8BITS);
omap24xxcam_reg_out(base, CAMDMA_CSSA(dmach), 0);
omap24xxcam_reg_out(base, CAMDMA_CDSA(dmach), start);
omap24xxcam_reg_out(base, CAMDMA_CSEI(dmach), 0);
omap24xxcam_reg_out(base, CAMDMA_CSFI(dmach), DMA_THRESHOLD);
omap24xxcam_reg_out(base, CAMDMA_CDEI(dmach), 0);
omap24xxcam_reg_out(base, CAMDMA_CDFI(dmach), 0);
omap24xxcam_reg_out(base, CAMDMA_CSR(dmach),
CAMDMA_CSR_MISALIGNED_ERR
| CAMDMA_CSR_SECURE_ERR
| CAMDMA_CSR_TRANS_ERR
| CAMDMA_CSR_BLOCK
| CAMDMA_CSR_DROP);
omap24xxcam_reg_out(base, CAMDMA_CICR(dmach),
CAMDMA_CICR_MISALIGNED_ERR_IE
| CAMDMA_CICR_SECURE_ERR_IE
| CAMDMA_CICR_TRANS_ERR_IE
| CAMDMA_CICR_BLOCK_IE
| CAMDMA_CICR_DROP_IE);
}
static void omap24xxcam_dmahw_transfer_start(unsigned long base, int dmach)
{
omap24xxcam_reg_out(base, CAMDMA_CCR(dmach),
CAMDMA_CCR_SEL_SRC_DST_SYNC
| CAMDMA_CCR_BS
| CAMDMA_CCR_DST_AMODE_POST_INC
| CAMDMA_CCR_SRC_AMODE_POST_INC
| CAMDMA_CCR_ENABLE
| CAMDMA_CCR_FS
| CAMDMA_CCR_SYNCHRO_CAMERA);
}
static void omap24xxcam_dmahw_transfer_chain(unsigned long base, int dmach,
int free_dmach)
{
int prev_dmach, ch;
if (dmach == 0)
prev_dmach = NUM_CAMDMA_CHANNELS - 1;
else
prev_dmach = dmach - 1;
omap24xxcam_reg_out(base, CAMDMA_CLNK_CTRL(prev_dmach),
CAMDMA_CLNK_CTRL_ENABLE_LNK | dmach);
ch = (dmach + free_dmach) % NUM_CAMDMA_CHANNELS;
while (!(omap24xxcam_reg_in(base, CAMDMA_CCR(ch))
& CAMDMA_CCR_ENABLE)) {
if (ch == dmach) {
omap24xxcam_dmahw_transfer_start(base, dmach);
break;
} else
ch = (ch + 1) % NUM_CAMDMA_CHANNELS;
}
}
static void omap24xxcam_dmahw_abort_ch(unsigned long base, int dmach)
{
omap24xxcam_reg_out(base, CAMDMA_CICR(dmach), 0);
omap24xxcam_reg_merge(base, CAMDMA_CLNK_CTRL(dmach), 0,
CAMDMA_CLNK_CTRL_ENABLE_LNK);
omap24xxcam_reg_merge(base, CAMDMA_CCR(dmach), 0, CAMDMA_CCR_ENABLE);
}
static void omap24xxcam_dmahw_init(unsigned long base)
{
omap24xxcam_reg_out(base, CAMDMA_OCP_SYSCONFIG,
CAMDMA_OCP_SYSCONFIG_MIDLEMODE_FSTANDBY
| CAMDMA_OCP_SYSCONFIG_SIDLEMODE_FIDLE
| CAMDMA_OCP_SYSCONFIG_AUTOIDLE);
omap24xxcam_reg_merge(base, CAMDMA_GCR, 0x10,
CAMDMA_GCR_MAX_CHANNEL_FIFO_DEPTH);
omap24xxcam_reg_out(base, CAMDMA_IRQENABLE_L0, 0xf);
}
static int omap24xxcam_dma_start(struct omap24xxcam_dma *dma, dma_addr_t start,
u32 len, dma_callback_t callback, void *arg)
{
unsigned long flags;
int dmach;
spin_lock_irqsave(&dma->lock, flags);
if (!dma->free_dmach || atomic_read(&dma->dma_stop)) {
spin_unlock_irqrestore(&dma->lock, flags);
return -EBUSY;
}
dmach = dma->next_dmach;
dma->ch_state[dmach].callback = callback;
dma->ch_state[dmach].arg = arg;
omap24xxcam_dmahw_transfer_setup(dma->base, dmach, start, len);
if (dma->free_dmach < NUM_CAMDMA_CHANNELS) {
omap24xxcam_dmahw_transfer_chain(dma->base, dmach,
dma->free_dmach);
} else {
omap24xxcam_dmahw_transfer_start(dma->base, dmach);
}
dma->next_dmach = (dma->next_dmach + 1) % NUM_CAMDMA_CHANNELS;
dma->free_dmach--;
spin_unlock_irqrestore(&dma->lock, flags);
return 0;
}
static void omap24xxcam_dma_abort(struct omap24xxcam_dma *dma, u32 csr)
{
unsigned long flags;
int dmach, i, free_dmach;
dma_callback_t callback;
void *arg;
spin_lock_irqsave(&dma->lock, flags);
dmach = (dma->next_dmach + dma->free_dmach) % NUM_CAMDMA_CHANNELS;
for (i = 0; i < NUM_CAMDMA_CHANNELS; i++) {
omap24xxcam_dmahw_abort_ch(dma->base, dmach);
dmach = (dmach + 1) % NUM_CAMDMA_CHANNELS;
}
free_dmach = dma->free_dmach;
while ((dma->free_dmach < NUM_CAMDMA_CHANNELS) &&
(free_dmach < NUM_CAMDMA_CHANNELS)) {
dmach = (dma->next_dmach + dma->free_dmach)
% NUM_CAMDMA_CHANNELS;
callback = dma->ch_state[dmach].callback;
arg = dma->ch_state[dmach].arg;
dma->free_dmach++;
free_dmach++;
if (callback) {
spin_unlock(&dma->lock);
(*callback) (dma, csr, arg);
spin_lock(&dma->lock);
}
}
spin_unlock_irqrestore(&dma->lock, flags);
}
static void omap24xxcam_dma_stop(struct omap24xxcam_dma *dma, u32 csr)
{
atomic_inc(&dma->dma_stop);
omap24xxcam_dma_abort(dma, csr);
atomic_dec(&dma->dma_stop);
}
void omap24xxcam_dma_isr(struct omap24xxcam_dma *dma)
{
int dmach;
dma_callback_t callback;
void *arg;
u32 csr;
const u32 csr_error = CAMDMA_CSR_MISALIGNED_ERR
| CAMDMA_CSR_SUPERVISOR_ERR | CAMDMA_CSR_SECURE_ERR
| CAMDMA_CSR_TRANS_ERR | CAMDMA_CSR_DROP;
spin_lock(&dma->lock);
if (dma->free_dmach == NUM_CAMDMA_CHANNELS) {
omap24xxcam_dmahw_ack_all(dma->base);
spin_unlock(&dma->lock);
return;
}
while (dma->free_dmach < NUM_CAMDMA_CHANNELS) {
dmach = (dma->next_dmach + dma->free_dmach)
% NUM_CAMDMA_CHANNELS;
if (omap24xxcam_dmahw_running(dma->base, dmach)) {
break;
}
csr = omap24xxcam_dmahw_ack_ch(dma->base, dmach);
if (csr & csr_error) {
spin_unlock(&dma->lock);
omap24xxcam_dma_stop(dma, csr);
return;
} else {
callback = dma->ch_state[dmach].callback;
arg = dma->ch_state[dmach].arg;
dma->free_dmach++;
if (callback) {
spin_unlock(&dma->lock);
(*callback) (dma, csr, arg);
spin_lock(&dma->lock);
}
}
}
spin_unlock(&dma->lock);
omap24xxcam_sgdma_process(
container_of(dma, struct omap24xxcam_sgdma, dma));
}
void omap24xxcam_dma_hwinit(struct omap24xxcam_dma *dma)
{
unsigned long flags;
spin_lock_irqsave(&dma->lock, flags);
omap24xxcam_dmahw_init(dma->base);
spin_unlock_irqrestore(&dma->lock, flags);
}
static void omap24xxcam_dma_init(struct omap24xxcam_dma *dma,
unsigned long base)
{
int ch;
spin_lock_init(&dma->lock);
dma->base = base;
dma->free_dmach = NUM_CAMDMA_CHANNELS;
dma->next_dmach = 0;
for (ch = 0; ch < NUM_CAMDMA_CHANNELS; ch++) {
dma->ch_state[ch].callback = NULL;
dma->ch_state[ch].arg = NULL;
}
}
static void omap24xxcam_sgdma_callback(struct omap24xxcam_dma *dma, u32 csr,
void *arg)
{
struct omap24xxcam_sgdma *sgdma =
container_of(dma, struct omap24xxcam_sgdma, dma);
int sgslot = (int)arg;
struct sgdma_state *sg_state;
const u32 csr_error = CAMDMA_CSR_MISALIGNED_ERR
| CAMDMA_CSR_SUPERVISOR_ERR | CAMDMA_CSR_SECURE_ERR
| CAMDMA_CSR_TRANS_ERR | CAMDMA_CSR_DROP;
spin_lock(&sgdma->lock);
del_timer(&sgdma->reset_timer);
sg_state = sgdma->sg_state + sgslot;
if (!sg_state->queued_sglist) {
spin_unlock(&sgdma->lock);
printk(KERN_ERR "%s: sgdma completed when none queued!\n",
__func__);
return;
}
sg_state->csr |= csr;
if (!--sg_state->queued_sglist) {
if ((sg_state->next_sglist == sg_state->sglen)
|| (sg_state->csr & csr_error)) {
sgdma_callback_t callback = sg_state->callback;
void *arg = sg_state->arg;
u32 sg_csr = sg_state->csr;
sgdma->free_sgdma++;
if (callback) {
spin_unlock(&sgdma->lock);
(*callback) (sgdma, sg_csr, arg);
return;
}
}
}
spin_unlock(&sgdma->lock);
}
void omap24xxcam_sgdma_process(struct omap24xxcam_sgdma *sgdma)
{
unsigned long flags;
int queued_sgdma, sgslot;
struct sgdma_state *sg_state;
const u32 csr_error = CAMDMA_CSR_MISALIGNED_ERR
| CAMDMA_CSR_SUPERVISOR_ERR | CAMDMA_CSR_SECURE_ERR
| CAMDMA_CSR_TRANS_ERR | CAMDMA_CSR_DROP;
spin_lock_irqsave(&sgdma->lock, flags);
queued_sgdma = NUM_SG_DMA - sgdma->free_sgdma;
sgslot = (sgdma->next_sgdma + sgdma->free_sgdma) % NUM_SG_DMA;
while (queued_sgdma > 0) {
sg_state = sgdma->sg_state + sgslot;
while ((sg_state->next_sglist < sg_state->sglen) &&
!(sg_state->csr & csr_error)) {
const struct scatterlist *sglist;
unsigned int len;
sglist = sg_state->sglist + sg_state->next_sglist;
if (sg_state->next_sglist + 1 == sg_state->sglen) {
len = sg_state->len - sg_state->bytes_read;
} else {
len = sg_dma_len(sglist);
}
if (omap24xxcam_dma_start(&sgdma->dma,
sg_dma_address(sglist),
len,
omap24xxcam_sgdma_callback,
(void *)sgslot)) {
spin_unlock_irqrestore(&sgdma->lock, flags);
return;
} else {
unsigned long expires;
sg_state->next_sglist++;
sg_state->bytes_read += len;
sg_state->queued_sglist++;
expires = jiffies + HZ;
mod_timer(&sgdma->reset_timer, expires);
}
}
queued_sgdma--;
sgslot = (sgslot + 1) % NUM_SG_DMA;
}
spin_unlock_irqrestore(&sgdma->lock, flags);
}
int omap24xxcam_sgdma_queue(struct omap24xxcam_sgdma *sgdma,
const struct scatterlist *sglist, int sglen,
int len, sgdma_callback_t callback, void *arg)
{
unsigned long flags;
struct sgdma_state *sg_state;
if ((sglen < 0) || ((sglen > 0) && !sglist))
return -EINVAL;
spin_lock_irqsave(&sgdma->lock, flags);
if (!sgdma->free_sgdma) {
spin_unlock_irqrestore(&sgdma->lock, flags);
return -EBUSY;
}
sg_state = sgdma->sg_state + sgdma->next_sgdma;
sg_state->sglist = sglist;
sg_state->sglen = sglen;
sg_state->next_sglist = 0;
sg_state->bytes_read = 0;
sg_state->len = len;
sg_state->queued_sglist = 0;
sg_state->csr = 0;
sg_state->callback = callback;
sg_state->arg = arg;
sgdma->next_sgdma = (sgdma->next_sgdma + 1) % NUM_SG_DMA;
sgdma->free_sgdma--;
spin_unlock_irqrestore(&sgdma->lock, flags);
omap24xxcam_sgdma_process(sgdma);
return 0;
}
void omap24xxcam_sgdma_sync(struct omap24xxcam_sgdma *sgdma)
{
unsigned long flags;
int sgslot;
struct sgdma_state *sg_state;
u32 csr = CAMDMA_CSR_TRANS_ERR;
omap24xxcam_dma_stop(&sgdma->dma, csr);
spin_lock_irqsave(&sgdma->lock, flags);
if (sgdma->free_sgdma < NUM_SG_DMA) {
sgslot = (sgdma->next_sgdma + sgdma->free_sgdma) % NUM_SG_DMA;
sg_state = sgdma->sg_state + sgslot;
if (sg_state->next_sglist != 0) {
sgdma_callback_t callback = sg_state->callback;
void *arg = sg_state->arg;
sgdma->free_sgdma++;
if (callback) {
spin_unlock(&sgdma->lock);
(*callback) (sgdma, csr, arg);
spin_lock(&sgdma->lock);
}
}
}
spin_unlock_irqrestore(&sgdma->lock, flags);
}
void omap24xxcam_sgdma_init(struct omap24xxcam_sgdma *sgdma,
unsigned long base,
void (*reset_callback)(unsigned long data),
unsigned long reset_callback_data)
{
int sg;
spin_lock_init(&sgdma->lock);
sgdma->free_sgdma = NUM_SG_DMA;
sgdma->next_sgdma = 0;
for (sg = 0; sg < NUM_SG_DMA; sg++) {
sgdma->sg_state[sg].sglen = 0;
sgdma->sg_state[sg].next_sglist = 0;
sgdma->sg_state[sg].bytes_read = 0;
sgdma->sg_state[sg].queued_sglist = 0;
sgdma->sg_state[sg].csr = 0;
sgdma->sg_state[sg].callback = NULL;
sgdma->sg_state[sg].arg = NULL;
}
omap24xxcam_dma_init(&sgdma->dma, base);
setup_timer(&sgdma->reset_timer, reset_callback, reset_callback_data);
}
