static unsigned int stmmac_jumbo_frm(void *p, struct sk_buff *skb, int csum)
{
struct stmmac_priv *priv = (struct stmmac_priv *) p;
unsigned int txsize = priv->dma_tx_size;
unsigned int entry = priv->cur_tx % txsize;
struct dma_desc *desc = priv->dma_tx + entry;
unsigned int nopaged_len = skb_headlen(skb);
unsigned int bmax, len;
if (priv->plat->enh_desc)
bmax = BUF_SIZE_8KiB;
else
bmax = BUF_SIZE_2KiB;
len = nopaged_len - bmax;
if (nopaged_len > BUF_SIZE_8KiB) {
desc->des2 = dma_map_single(priv->device, skb->data,
bmax, DMA_TO_DEVICE);
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 1, bmax,
csum);
wmb();
entry = (++priv->cur_tx) % txsize;
desc = priv->dma_tx + entry;
desc->des2 = dma_map_single(priv->device, skb->data + bmax,
len, DMA_TO_DEVICE);
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum);
wmb();
priv->hw->desc->set_tx_owner(desc);
priv->tx_skbuff[entry] = NULL;
} else {
desc->des2 = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 1, nopaged_len, csum);
}
return entry;
}
static unsigned int stmmac_is_jumbo_frm(int len, int enh_desc)
{
unsigned int ret = 0;
if (len >= BUF_SIZE_4KiB)
ret = 1;
return ret;
}
static void stmmac_refill_desc3(int bfsize, struct dma_desc *p)
{
if (bfsize >= BUF_SIZE_8KiB)
p->des3 = p->des2 + BUF_SIZE_8KiB;
}
static void stmmac_init_desc3(int des3_as_data_buf, struct dma_desc *p)
{
if (unlikely(des3_as_data_buf))
p->des3 = p->des2 + BUF_SIZE_8KiB;
}
static void stmmac_init_dma_chain(struct dma_desc *des, dma_addr_t phy_addr,
unsigned int size)
{
}
static void stmmac_clean_desc3(struct dma_desc *p)
{
if (unlikely(p->des3))
p->des3 = 0;
}
static int stmmac_set_16kib_bfsize(int mtu)
{
int ret = 0;
if (unlikely(mtu >= BUF_SIZE_8KiB))
ret = BUF_SIZE_16KiB;
return ret;
}
