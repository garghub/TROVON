static ssize_t pdc_debugfs_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *offp)
{
struct pdc_state *pdcs;
char *buf;
ssize_t ret, out_offset, out_count;
out_count = 512;
buf = kmalloc(out_count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
pdcs = filp->private_data;
out_offset = 0;
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"SPU %u stats:\n", pdcs->pdc_idx);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"PDC requests............%u\n",
pdcs->pdc_requests);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"PDC responses...........%u\n",
pdcs->pdc_replies);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"Tx err ring full........%u\n",
pdcs->txnobuf);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"Rx err ring full........%u\n",
pdcs->rxnobuf);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"Receive overflow........%u\n",
pdcs->rx_oflow);
if (out_offset > out_count)
out_offset = out_count;
ret = simple_read_from_buffer(ubuf, count, offp, buf, out_offset);
kfree(buf);
return ret;
}
static void pdc_setup_debugfs(struct pdc_state *pdcs)
{
char spu_stats_name[16];
if (!debugfs_initialized())
return;
snprintf(spu_stats_name, 16, "pdc%d_stats", pdcs->pdc_idx);
if (!debugfs_dir)
debugfs_dir = debugfs_create_dir(KBUILD_MODNAME, NULL);
pdcs->debugfs_stats = debugfs_create_file(spu_stats_name, S_IRUSR,
debugfs_dir, pdcs,
&pdc_debugfs_stats);
}
static void pdc_free_debugfs(void)
{
if (debugfs_dir && simple_empty(debugfs_dir)) {
debugfs_remove_recursive(debugfs_dir);
debugfs_dir = NULL;
}
}
static inline void
pdc_build_rxd(struct pdc_state *pdcs, dma_addr_t dma_addr,
u32 buf_len, u32 flags)
{
struct device *dev = &pdcs->pdev->dev;
dev_dbg(dev,
"Writing rx descriptor for PDC %u at index %u with length %u. flags %#x\n",
pdcs->pdc_idx, pdcs->rxout, buf_len, flags);
iowrite32(lower_32_bits(dma_addr),
(void *)&pdcs->rxd_64[pdcs->rxout].addrlow);
iowrite32(upper_32_bits(dma_addr),
(void *)&pdcs->rxd_64[pdcs->rxout].addrhigh);
iowrite32(flags, (void *)&pdcs->rxd_64[pdcs->rxout].ctrl1);
iowrite32(buf_len, (void *)&pdcs->rxd_64[pdcs->rxout].ctrl2);
pdcs->rxout = NEXTRXD(pdcs->rxout, pdcs->nrxpost);
}
static inline void
pdc_build_txd(struct pdc_state *pdcs, dma_addr_t dma_addr, u32 buf_len,
u32 flags)
{
struct device *dev = &pdcs->pdev->dev;
dev_dbg(dev,
"Writing tx descriptor for PDC %u at index %u with length %u, flags %#x\n",
pdcs->pdc_idx, pdcs->txout, buf_len, flags);
iowrite32(lower_32_bits(dma_addr),
(void *)&pdcs->txd_64[pdcs->txout].addrlow);
iowrite32(upper_32_bits(dma_addr),
(void *)&pdcs->txd_64[pdcs->txout].addrhigh);
iowrite32(flags, (void *)&pdcs->txd_64[pdcs->txout].ctrl1);
iowrite32(buf_len, (void *)&pdcs->txd_64[pdcs->txout].ctrl2);
pdcs->txout = NEXTTXD(pdcs->txout, pdcs->ntxpost);
}
static int
pdc_receive(struct pdc_state *pdcs, struct brcm_message *mssg)
{
struct device *dev = &pdcs->pdev->dev;
u32 len, rx_status;
u32 num_frags;
int i;
u8 *resp_hdr;
u32 frags_rdy;
u32 rx_idx;
dma_addr_t resp_hdr_daddr;
spin_lock(&pdcs->pdc_lock);
frags_rdy = NRXDACTIVE(pdcs->rxin, pdcs->last_rx_curr, pdcs->nrxpost);
if ((frags_rdy == 0) || (frags_rdy < pdcs->rxin_numd[pdcs->rxin])) {
pdcs->last_rx_curr =
(ioread32((void *)&pdcs->rxregs_64->status0) &
CRYPTO_D64_RS0_CD_MASK) / RING_ENTRY_SIZE;
frags_rdy = NRXDACTIVE(pdcs->rxin, pdcs->last_rx_curr,
pdcs->nrxpost);
if ((frags_rdy == 0) ||
(frags_rdy < pdcs->rxin_numd[pdcs->rxin])) {
spin_unlock(&pdcs->pdc_lock);
return -EAGAIN;
}
rmb();
}
num_frags = pdcs->txin_numd[pdcs->txin];
dma_unmap_sg(dev, pdcs->src_sg[pdcs->txin],
sg_nents(pdcs->src_sg[pdcs->txin]), DMA_TO_DEVICE);
for (i = 0; i < num_frags; i++)
pdcs->txin = NEXTTXD(pdcs->txin, pdcs->ntxpost);
dev_dbg(dev, "PDC %u reclaimed %d tx descriptors",
pdcs->pdc_idx, num_frags);
rx_idx = pdcs->rxin;
num_frags = pdcs->rxin_numd[rx_idx];
mssg->ctx = pdcs->rxp_ctx[rx_idx];
pdcs->rxp_ctx[rx_idx] = NULL;
resp_hdr = pdcs->resp_hdr[rx_idx];
resp_hdr_daddr = pdcs->resp_hdr_daddr[rx_idx];
dma_unmap_sg(dev, pdcs->dst_sg[rx_idx],
sg_nents(pdcs->dst_sg[rx_idx]), DMA_FROM_DEVICE);
for (i = 0; i < num_frags; i++)
pdcs->rxin = NEXTRXD(pdcs->rxin, pdcs->nrxpost);
spin_unlock(&pdcs->pdc_lock);
dev_dbg(dev, "PDC %u reclaimed %d rx descriptors",
pdcs->pdc_idx, num_frags);
dev_dbg(dev,
"PDC %u txin %u, txout %u, rxin %u, rxout %u, last_rx_curr %u\n",
pdcs->pdc_idx, pdcs->txin, pdcs->txout, pdcs->rxin,
pdcs->rxout, pdcs->last_rx_curr);
if (pdcs->pdc_resp_hdr_len == PDC_SPUM_RESP_HDR_LEN) {
rx_status = *((u32 *)resp_hdr);
len = rx_status & RX_STATUS_LEN;
dev_dbg(dev,
"SPU response length %u bytes", len);
if (unlikely(((rx_status & RX_STATUS_OVERFLOW) || (!len)))) {
if (rx_status & RX_STATUS_OVERFLOW) {
dev_err_ratelimited(dev,
"crypto receive overflow");
pdcs->rx_oflow++;
} else {
dev_info_ratelimited(dev, "crypto rx len = 0");
}
return -EIO;
}
}
dma_pool_free(pdcs->rx_buf_pool, resp_hdr, resp_hdr_daddr);
pdcs->pdc_replies++;
if (num_frags > 0)
return PDC_SUCCESS;
else
return -EIO;
}
static int pdc_tx_list_sg_add(struct pdc_state *pdcs, struct scatterlist *sg)
{
u32 flags = 0;
u32 eot;
u32 tx_avail;
u32 num_desc;
u32 desc_w = 0;
u32 bufcnt;
dma_addr_t databufptr;
num_desc = (u32)sg_nents(sg);
tx_avail = pdcs->ntxpost - NTXDACTIVE(pdcs->txin, pdcs->txout,
pdcs->ntxpost);
if (unlikely(num_desc > tx_avail)) {
pdcs->txnobuf++;
return -ENOSPC;
}
if (pdcs->tx_msg_start == pdcs->txout) {
pdcs->txin_numd[pdcs->tx_msg_start] = 0;
pdcs->src_sg[pdcs->txout] = sg;
flags = D64_CTRL1_SOF;
}
while (sg) {
if (unlikely(pdcs->txout == (pdcs->ntxd - 1)))
eot = D64_CTRL1_EOT;
else
eot = 0;
bufcnt = sg_dma_len(sg);
databufptr = sg_dma_address(sg);
while (bufcnt > PDC_DMA_BUF_MAX) {
pdc_build_txd(pdcs, databufptr, PDC_DMA_BUF_MAX,
flags | eot);
desc_w++;
bufcnt -= PDC_DMA_BUF_MAX;
databufptr += PDC_DMA_BUF_MAX;
if (unlikely(pdcs->txout == (pdcs->ntxd - 1)))
eot = D64_CTRL1_EOT;
else
eot = 0;
}
sg = sg_next(sg);
if (!sg)
flags |= (D64_CTRL1_EOF | D64_CTRL1_IOC);
pdc_build_txd(pdcs, databufptr, bufcnt, flags | eot);
desc_w++;
flags &= ~D64_CTRL1_SOF;
}
pdcs->txin_numd[pdcs->tx_msg_start] += desc_w;
return PDC_SUCCESS;
}
static int pdc_tx_list_final(struct pdc_state *pdcs)
{
wmb();
iowrite32(pdcs->rxout << 4, (void *)&pdcs->rxregs_64->ptr);
iowrite32(pdcs->txout << 4, (void *)&pdcs->txregs_64->ptr);
pdcs->pdc_requests++;
return PDC_SUCCESS;
}
static int pdc_rx_list_init(struct pdc_state *pdcs, struct scatterlist *dst_sg,
void *ctx)
{
u32 flags = 0;
u32 rx_avail;
u32 rx_pkt_cnt = 1;
dma_addr_t daddr;
void *vaddr;
rx_avail = pdcs->nrxpost - NRXDACTIVE(pdcs->rxin, pdcs->rxout,
pdcs->nrxpost);
if (unlikely(rx_pkt_cnt > rx_avail)) {
pdcs->rxnobuf++;
return -ENOSPC;
}
vaddr = dma_pool_zalloc(pdcs->rx_buf_pool, GFP_ATOMIC, &daddr);
if (!vaddr)
return -ENOMEM;
pdcs->rx_msg_start = pdcs->rxout;
pdcs->tx_msg_start = pdcs->txout;
flags = D64_CTRL1_SOF;
pdcs->rxin_numd[pdcs->rx_msg_start] = 1;
if (unlikely(pdcs->rxout == (pdcs->nrxd - 1)))
flags |= D64_CTRL1_EOT;
pdcs->rxp_ctx[pdcs->rxout] = ctx;
pdcs->dst_sg[pdcs->rxout] = dst_sg;
pdcs->resp_hdr[pdcs->rxout] = vaddr;
pdcs->resp_hdr_daddr[pdcs->rxout] = daddr;
pdc_build_rxd(pdcs, daddr, pdcs->pdc_resp_hdr_len, flags);
return PDC_SUCCESS;
}
static int pdc_rx_list_sg_add(struct pdc_state *pdcs, struct scatterlist *sg)
{
u32 flags = 0;
u32 rx_avail;
u32 num_desc;
u32 desc_w = 0;
u32 bufcnt;
dma_addr_t databufptr;
num_desc = (u32)sg_nents(sg);
rx_avail = pdcs->nrxpost - NRXDACTIVE(pdcs->rxin, pdcs->rxout,
pdcs->nrxpost);
if (unlikely(num_desc > rx_avail)) {
pdcs->rxnobuf++;
return -ENOSPC;
}
while (sg) {
if (unlikely(pdcs->rxout == (pdcs->nrxd - 1)))
flags = D64_CTRL1_EOT;
else
flags = 0;
bufcnt = sg_dma_len(sg);
databufptr = sg_dma_address(sg);
while (bufcnt > PDC_DMA_BUF_MAX) {
pdc_build_rxd(pdcs, databufptr, PDC_DMA_BUF_MAX, flags);
desc_w++;
bufcnt -= PDC_DMA_BUF_MAX;
databufptr += PDC_DMA_BUF_MAX;
if (unlikely(pdcs->rxout == (pdcs->nrxd - 1)))
flags = D64_CTRL1_EOT;
else
flags = 0;
}
pdc_build_rxd(pdcs, databufptr, bufcnt, flags);
desc_w++;
sg = sg_next(sg);
}
pdcs->rxin_numd[pdcs->rx_msg_start] += desc_w;
return PDC_SUCCESS;
}
static irqreturn_t pdc_irq_handler(int irq, void *cookie)
{
struct pdc_state *pdcs = cookie;
u32 intstatus = ioread32(pdcs->pdc_reg_vbase + PDC_INTSTATUS_OFFSET);
if (intstatus & PDC_XMTINTEN_0)
set_bit(PDC_XMTINT_0, &pdcs->intstatus);
if (intstatus & PDC_RCVINTEN_0)
set_bit(PDC_RCVINT_0, &pdcs->intstatus);
iowrite32(intstatus, pdcs->pdc_reg_vbase + PDC_INTSTATUS_OFFSET);
if (pdcs && (irq == pdcs->pdc_irq) && (intstatus & PDC_INTMASK))
return IRQ_WAKE_THREAD;
return IRQ_NONE;
}
static irqreturn_t pdc_irq_thread(int irq, void *cookie)
{
struct pdc_state *pdcs = cookie;
struct mbox_controller *mbc;
struct mbox_chan *chan;
bool tx_int;
bool rx_int;
int rx_status;
struct brcm_message mssg;
tx_int = test_and_clear_bit(PDC_XMTINT_0, &pdcs->intstatus);
rx_int = test_and_clear_bit(PDC_RCVINT_0, &pdcs->intstatus);
if (pdcs && (tx_int || rx_int)) {
dev_dbg(&pdcs->pdev->dev,
"%s() got irq %d with tx_int %s, rx_int %s",
__func__, irq,
tx_int ? "set" : "clear", rx_int ? "set" : "clear");
mbc = &pdcs->mbc;
chan = &mbc->chans[0];
if (tx_int) {
dev_dbg(&pdcs->pdev->dev, "%s(): tx done", __func__);
mbox_chan_txdone(chan, PDC_SUCCESS);
}
if (rx_int) {
while (1) {
memset(&mssg, 0, sizeof(mssg));
mssg.type = BRCM_MESSAGE_SPU;
rx_status = pdc_receive(pdcs, &mssg);
if (rx_status >= 0) {
dev_dbg(&pdcs->pdev->dev,
"%s(): invoking client rx cb",
__func__);
mbox_chan_received_data(chan, &mssg);
} else {
dev_dbg(&pdcs->pdev->dev,
"%s(): no SPU response available",
__func__);
break;
}
}
}
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int pdc_ring_init(struct pdc_state *pdcs, int ringset)
{
int i;
int err = PDC_SUCCESS;
struct dma64 *dma_reg;
struct device *dev = &pdcs->pdev->dev;
struct pdc_ring_alloc tx;
struct pdc_ring_alloc rx;
tx.vbase = dma_pool_zalloc(pdcs->ring_pool, GFP_KERNEL, &tx.dmabase);
if (!tx.vbase) {
err = -ENOMEM;
goto done;
}
rx.vbase = dma_pool_zalloc(pdcs->ring_pool, GFP_KERNEL, &rx.dmabase);
if (!rx.vbase) {
err = -ENOMEM;
goto fail_dealloc;
}
dev_dbg(dev, " - base DMA addr of tx ring %pad", &tx.dmabase);
dev_dbg(dev, " - base virtual addr of tx ring %p", tx.vbase);
dev_dbg(dev, " - base DMA addr of rx ring %pad", &rx.dmabase);
dev_dbg(dev, " - base virtual addr of rx ring %p", rx.vbase);
spin_lock(&pdcs->pdc_lock);
memcpy(&pdcs->tx_ring_alloc, &tx, sizeof(tx));
memcpy(&pdcs->rx_ring_alloc, &rx, sizeof(rx));
pdcs->rxin = 0;
pdcs->rx_msg_start = 0;
pdcs->last_rx_curr = 0;
pdcs->rxout = 0;
pdcs->txin = 0;
pdcs->tx_msg_start = 0;
pdcs->txout = 0;
pdcs->txd_64 = (struct dma64dd *)pdcs->tx_ring_alloc.vbase;
pdcs->rxd_64 = (struct dma64dd *)pdcs->rx_ring_alloc.vbase;
dma_reg = &pdcs->regs->dmaregs[ringset];
iowrite32(lower_32_bits(pdcs->tx_ring_alloc.dmabase),
(void *)&dma_reg->dmaxmt.addrlow);
iowrite32(upper_32_bits(pdcs->tx_ring_alloc.dmabase),
(void *)&dma_reg->dmaxmt.addrhigh);
iowrite32(lower_32_bits(pdcs->rx_ring_alloc.dmabase),
(void *)&dma_reg->dmarcv.addrlow);
iowrite32(upper_32_bits(pdcs->rx_ring_alloc.dmabase),
(void *)&dma_reg->dmarcv.addrhigh);
for (i = 0; i < PDC_RING_ENTRIES; i++) {
if (i != pdcs->ntxpost) {
iowrite32(D64_CTRL1_SOF | D64_CTRL1_EOF,
(void *)&pdcs->txd_64[i].ctrl1);
} else {
iowrite32(D64_CTRL1_SOF | D64_CTRL1_EOF |
D64_CTRL1_EOT,
(void *)&pdcs->txd_64[i].ctrl1);
}
if (i != pdcs->nrxpost) {
iowrite32(D64_CTRL1_SOF,
(void *)&pdcs->rxd_64[i].ctrl1);
} else {
iowrite32(D64_CTRL1_SOF | D64_CTRL1_EOT,
(void *)&pdcs->rxd_64[i].ctrl1);
}
}
spin_unlock(&pdcs->pdc_lock);
return PDC_SUCCESS;
fail_dealloc:
dma_pool_free(pdcs->ring_pool, tx.vbase, tx.dmabase);
done:
return err;
}
static void pdc_ring_free(struct pdc_state *pdcs)
{
if (pdcs->tx_ring_alloc.vbase) {
dma_pool_free(pdcs->ring_pool, pdcs->tx_ring_alloc.vbase,
pdcs->tx_ring_alloc.dmabase);
pdcs->tx_ring_alloc.vbase = NULL;
}
if (pdcs->rx_ring_alloc.vbase) {
dma_pool_free(pdcs->ring_pool, pdcs->rx_ring_alloc.vbase,
pdcs->rx_ring_alloc.dmabase);
pdcs->rx_ring_alloc.vbase = NULL;
}
}
static int pdc_send_data(struct mbox_chan *chan, void *data)
{
struct pdc_state *pdcs = chan->con_priv;
struct device *dev = &pdcs->pdev->dev;
struct brcm_message *mssg = data;
int err = PDC_SUCCESS;
int src_nent;
int dst_nent;
int nent;
if (mssg->type != BRCM_MESSAGE_SPU)
return -ENOTSUPP;
src_nent = sg_nents(mssg->spu.src);
if (src_nent) {
nent = dma_map_sg(dev, mssg->spu.src, src_nent, DMA_TO_DEVICE);
if (nent == 0)
return -EIO;
}
dst_nent = sg_nents(mssg->spu.dst);
if (dst_nent) {
nent = dma_map_sg(dev, mssg->spu.dst, dst_nent,
DMA_FROM_DEVICE);
if (nent == 0) {
dma_unmap_sg(dev, mssg->spu.src, src_nent,
DMA_TO_DEVICE);
return -EIO;
}
}
spin_lock(&pdcs->pdc_lock);
err = pdc_rx_list_init(pdcs, mssg->spu.dst, mssg->ctx);
err |= pdc_rx_list_sg_add(pdcs, mssg->spu.dst);
err |= pdc_tx_list_sg_add(pdcs, mssg->spu.src);
err |= pdc_tx_list_final(pdcs);
spin_unlock(&pdcs->pdc_lock);
if (err)
dev_err(&pdcs->pdev->dev,
"%s failed with error %d", __func__, err);
return err;
}
static int pdc_startup(struct mbox_chan *chan)
{
return pdc_ring_init(chan->con_priv, PDC_RINGSET);
}
static void pdc_shutdown(struct mbox_chan *chan)
{
struct pdc_state *pdcs = chan->con_priv;
if (!pdcs)
return;
dev_dbg(&pdcs->pdev->dev,
"Shutdown mailbox channel for PDC %u", pdcs->pdc_idx);
pdc_ring_free(pdcs);
}
static
void pdc_hw_init(struct pdc_state *pdcs)
{
struct platform_device *pdev;
struct device *dev;
struct dma64 *dma_reg;
int ringset = PDC_RINGSET;
pdev = pdcs->pdev;
dev = &pdev->dev;
dev_dbg(dev, "PDC %u initial values:", pdcs->pdc_idx);
dev_dbg(dev, "state structure: %p",
pdcs);
dev_dbg(dev, " - base virtual addr of hw regs %p",
pdcs->pdc_reg_vbase);
pdcs->regs = (struct pdc_regs *)pdcs->pdc_reg_vbase;
pdcs->txregs_64 = (struct dma64_regs *)
(void *)(((u8 *)pdcs->pdc_reg_vbase) +
PDC_TXREGS_OFFSET + (sizeof(struct dma64) * ringset));
pdcs->rxregs_64 = (struct dma64_regs *)
(void *)(((u8 *)pdcs->pdc_reg_vbase) +
PDC_RXREGS_OFFSET + (sizeof(struct dma64) * ringset));
pdcs->ntxd = PDC_RING_ENTRIES;
pdcs->nrxd = PDC_RING_ENTRIES;
pdcs->ntxpost = PDC_RING_ENTRIES - 1;
pdcs->nrxpost = PDC_RING_ENTRIES - 1;
pdcs->regs->intmask = 0;
dma_reg = &pdcs->regs->dmaregs[ringset];
iowrite32(0, (void *)&dma_reg->dmaxmt.ptr);
iowrite32(0, (void *)&dma_reg->dmarcv.ptr);
iowrite32(PDC_TX_CTL, (void *)&dma_reg->dmaxmt.control);
iowrite32(PDC_RX_CTL + (pdcs->rx_status_len << 1),
(void *)&dma_reg->dmarcv.control);
if (pdcs->pdc_resp_hdr_len == PDC_SPU2_RESP_HDR_LEN)
iowrite32(PDC_CKSUM_CTRL,
pdcs->pdc_reg_vbase + PDC_CKSUM_CTRL_OFFSET);
}
static int pdc_rx_buf_pool_create(struct pdc_state *pdcs)
{
struct platform_device *pdev;
struct device *dev;
pdev = pdcs->pdev;
dev = &pdev->dev;
pdcs->pdc_resp_hdr_len = pdcs->rx_status_len;
if (pdcs->use_bcm_hdr)
pdcs->pdc_resp_hdr_len += BCM_HDR_LEN;
pdcs->rx_buf_pool = dma_pool_create("pdc rx bufs", dev,
pdcs->pdc_resp_hdr_len,
RX_BUF_ALIGN, 0);
if (!pdcs->rx_buf_pool)
return -ENOMEM;
return PDC_SUCCESS;
}
static int pdc_interrupts_init(struct pdc_state *pdcs)
{
struct platform_device *pdev = pdcs->pdev;
struct device *dev = &pdev->dev;
struct device_node *dn = pdev->dev.of_node;
int err;
pdcs->intstatus = 0;
iowrite32(PDC_INTMASK, pdcs->pdc_reg_vbase + PDC_INTMASK_OFFSET);
iowrite32(PDC_LAZY_INT, pdcs->pdc_reg_vbase + PDC_RCVLAZY0_OFFSET);
pdcs->pdc_irq = irq_of_parse_and_map(dn, 0);
dev_dbg(dev, "pdc device %s irq %u for pdcs %p",
dev_name(dev), pdcs->pdc_irq, pdcs);
err = devm_request_threaded_irq(dev, pdcs->pdc_irq,
pdc_irq_handler,
pdc_irq_thread, 0, dev_name(dev), pdcs);
if (err) {
dev_err(dev, "threaded tx IRQ %u request failed with err %d\n",
pdcs->pdc_irq, err);
return err;
}
return PDC_SUCCESS;
}
static int pdc_mb_init(struct pdc_state *pdcs)
{
struct device *dev = &pdcs->pdev->dev;
struct mbox_controller *mbc;
int chan_index;
int err;
mbc = &pdcs->mbc;
mbc->dev = dev;
mbc->ops = &pdc_mbox_chan_ops;
mbc->num_chans = 1;
mbc->chans = devm_kcalloc(dev, mbc->num_chans, sizeof(*mbc->chans),
GFP_KERNEL);
if (!mbc->chans)
return -ENOMEM;
mbc->txdone_irq = true;
mbc->txdone_poll = false;
for (chan_index = 0; chan_index < mbc->num_chans; chan_index++)
mbc->chans[chan_index].con_priv = pdcs;
err = mbox_controller_register(mbc);
if (err) {
dev_crit(dev,
"Failed to register PDC mailbox controller. Error %d.",
err);
return err;
}
return 0;
}
static int pdc_dt_read(struct platform_device *pdev, struct pdc_state *pdcs)
{
struct device *dev = &pdev->dev;
struct device_node *dn = pdev->dev.of_node;
int err;
err = of_property_read_u32(dn, "brcm,rx-status-len",
&pdcs->rx_status_len);
if (err < 0)
dev_err(dev,
"%s failed to get DMA receive status length from device tree",
__func__);
pdcs->use_bcm_hdr = of_property_read_bool(dn, "brcm,use-bcm-hdr");
return 0;
}
static int pdc_probe(struct platform_device *pdev)
{
int err = 0;
struct device *dev = &pdev->dev;
struct resource *pdc_regs;
struct pdc_state *pdcs;
pdcs = devm_kzalloc(dev, sizeof(*pdcs), GFP_KERNEL);
if (!pdcs) {
err = -ENOMEM;
goto cleanup;
}
spin_lock_init(&pdcs->pdc_lock);
pdcs->pdev = pdev;
platform_set_drvdata(pdev, pdcs);
pdcs->pdc_idx = pdcg.num_spu;
pdcg.num_spu++;
err = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (err) {
dev_warn(dev, "PDC device cannot perform DMA. Error %d.", err);
goto cleanup;
}
pdcs->ring_pool = dma_pool_create("pdc rings", dev, PDC_RING_SIZE,
RING_ALIGN, 0);
if (!pdcs->ring_pool) {
err = -ENOMEM;
goto cleanup;
}
err = pdc_dt_read(pdev, pdcs);
if (err)
goto cleanup_ring_pool;
pdc_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!pdc_regs) {
err = -ENODEV;
goto cleanup_ring_pool;
}
dev_dbg(dev, "PDC register region res.start = %pa, res.end = %pa",
&pdc_regs->start, &pdc_regs->end);
pdcs->pdc_reg_vbase = devm_ioremap_resource(&pdev->dev, pdc_regs);
if (IS_ERR(pdcs->pdc_reg_vbase)) {
err = PTR_ERR(pdcs->pdc_reg_vbase);
dev_err(&pdev->dev, "Failed to map registers: %d\n", err);
goto cleanup_ring_pool;
}
err = pdc_rx_buf_pool_create(pdcs);
if (err)
goto cleanup_ring_pool;
pdc_hw_init(pdcs);
err = pdc_interrupts_init(pdcs);
if (err)
goto cleanup_buf_pool;
err = pdc_mb_init(pdcs);
if (err)
goto cleanup_buf_pool;
pdcs->debugfs_stats = NULL;
pdc_setup_debugfs(pdcs);
dev_dbg(dev, "pdc_probe() successful");
return PDC_SUCCESS;
cleanup_buf_pool:
dma_pool_destroy(pdcs->rx_buf_pool);
cleanup_ring_pool:
dma_pool_destroy(pdcs->ring_pool);
cleanup:
return err;
}
static int pdc_remove(struct platform_device *pdev)
{
struct pdc_state *pdcs = platform_get_drvdata(pdev);
pdc_free_debugfs();
mbox_controller_unregister(&pdcs->mbc);
dma_pool_destroy(pdcs->rx_buf_pool);
dma_pool_destroy(pdcs->ring_pool);
return 0;
}
