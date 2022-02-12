static int stmmac_jumbo_frm(void *p, struct sk_buff *skb, int csum)
{
struct stmmac_priv *priv = (struct stmmac_priv *)p;
unsigned int entry = priv->cur_tx;
struct dma_desc *desc;
unsigned int nopaged_len = skb_headlen(skb);
unsigned int bmax, len;
if (priv->extend_desc)
desc = (struct dma_desc *)(priv->dma_etx + entry);
else
desc = priv->dma_tx + entry;
if (priv->plat->enh_desc)
bmax = BUF_SIZE_8KiB;
else
bmax = BUF_SIZE_2KiB;
len = nopaged_len - bmax;
if (nopaged_len > BUF_SIZE_8KiB) {
desc->des2 = dma_map_single(priv->device, skb->data,
bmax, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, desc->des2))
return -1;
priv->tx_skbuff_dma[entry].buf = desc->des2;
priv->tx_skbuff_dma[entry].len = bmax;
priv->tx_skbuff_dma[entry].is_jumbo = true;
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 1, bmax, csum,
STMMAC_RING_MODE, 0, false);
priv->tx_skbuff[entry] = NULL;
entry = STMMAC_GET_ENTRY(entry, DMA_TX_SIZE);
if (priv->extend_desc)
desc = (struct dma_desc *)(priv->dma_etx + entry);
else
desc = priv->dma_tx + entry;
desc->des2 = dma_map_single(priv->device, skb->data + bmax,
len, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, desc->des2))
return -1;
priv->tx_skbuff_dma[entry].buf = desc->des2;
priv->tx_skbuff_dma[entry].len = len;
priv->tx_skbuff_dma[entry].is_jumbo = true;
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum,
STMMAC_RING_MODE, 1, true);
} else {
desc->des2 = dma_map_single(priv->device, skb->data,
nopaged_len, DMA_TO_DEVICE);
if (dma_mapping_error(priv->device, desc->des2))
return -1;
priv->tx_skbuff_dma[entry].buf = desc->des2;
priv->tx_skbuff_dma[entry].len = nopaged_len;
priv->tx_skbuff_dma[entry].is_jumbo = true;
desc->des3 = desc->des2 + BUF_SIZE_4KiB;
priv->hw->desc->prepare_tx_desc(desc, 1, nopaged_len, csum,
STMMAC_RING_MODE, 0, true);
}
priv->cur_tx = entry;
return entry;
}
static unsigned int stmmac_is_jumbo_frm(int len, int enh_desc)
{
unsigned int ret = 0;
if (len >= BUF_SIZE_4KiB)
ret = 1;
return ret;
}
static void stmmac_refill_desc3(void *priv_ptr, struct dma_desc *p)
{
struct stmmac_priv *priv = (struct stmmac_priv *)priv_ptr;
if (priv->dma_buf_sz >= BUF_SIZE_8KiB)
p->des3 = p->des2 + BUF_SIZE_8KiB;
}
static void stmmac_init_desc3(struct dma_desc *p)
{
p->des3 = p->des2 + BUF_SIZE_8KiB;
}
static void stmmac_clean_desc3(void *priv_ptr, struct dma_desc *p)
{
struct stmmac_priv *priv = (struct stmmac_priv *)priv_ptr;
unsigned int entry = priv->dirty_tx;
if (unlikely(priv->tx_skbuff_dma[entry].is_jumbo ||
(priv->tx_skbuff_dma[entry].last_segment &&
!priv->extend_desc && priv->hwts_tx_en)))
p->des3 = 0;
}
static int stmmac_set_16kib_bfsize(int mtu)
{
int ret = 0;
if (unlikely(mtu >= BUF_SIZE_8KiB))
ret = BUF_SIZE_16KiB;
return ret;
}
