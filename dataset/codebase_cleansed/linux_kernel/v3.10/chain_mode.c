static unsigned int stmmac_jumbo_frm(void *p, struct sk_buff *skb, int csum)
{
struct stmmac_priv *priv = (struct stmmac_priv *)p;
unsigned int txsize = priv->dma_tx_size;
unsigned int entry = priv->cur_tx % txsize;
struct dma_desc *desc = priv->dma_tx + entry;
unsigned int nopaged_len = skb_headlen(skb);
unsigned int bmax;
unsigned int i = 1, len;
if (priv->plat->enh_desc)
bmax = BUF_SIZE_8KiB;
else
bmax = BUF_SIZE_2KiB;
len = nopaged_len - bmax;
desc->des2 = dma_map_single(priv->device, skb->data,
bmax, DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry] = desc->des2;
priv->hw->desc->prepare_tx_desc(desc, 1, bmax, csum, STMMAC_CHAIN_MODE);
while (len != 0) {
entry = (++priv->cur_tx) % txsize;
desc = priv->dma_tx + entry;
if (len > bmax) {
desc->des2 = dma_map_single(priv->device,
(skb->data + bmax * i),
bmax, DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry] = desc->des2;
priv->hw->desc->prepare_tx_desc(desc, 0, bmax, csum,
STMMAC_CHAIN_MODE);
priv->hw->desc->set_tx_owner(desc);
priv->tx_skbuff[entry] = NULL;
len -= bmax;
i++;
} else {
desc->des2 = dma_map_single(priv->device,
(skb->data + bmax * i), len,
DMA_TO_DEVICE);
priv->tx_skbuff_dma[entry] = desc->des2;
priv->hw->desc->prepare_tx_desc(desc, 0, len, csum,
STMMAC_CHAIN_MODE);
priv->hw->desc->set_tx_owner(desc);
priv->tx_skbuff[entry] = NULL;
len = 0;
}
}
return entry;
}
static unsigned int stmmac_is_jumbo_frm(int len, int enh_desc)
{
unsigned int ret = 0;
if ((enh_desc && (len > BUF_SIZE_8KiB)) ||
(!enh_desc && (len > BUF_SIZE_2KiB))) {
ret = 1;
}
return ret;
}
static void stmmac_init_dma_chain(void *des, dma_addr_t phy_addr,
unsigned int size, unsigned int extend_desc)
{
int i;
dma_addr_t dma_phy = phy_addr;
if (extend_desc) {
struct dma_extended_desc *p = (struct dma_extended_desc *)des;
for (i = 0; i < (size - 1); i++) {
dma_phy += sizeof(struct dma_extended_desc);
p->basic.des3 = (unsigned int)dma_phy;
p++;
}
p->basic.des3 = (unsigned int)phy_addr;
} else {
struct dma_desc *p = (struct dma_desc *)des;
for (i = 0; i < (size - 1); i++) {
dma_phy += sizeof(struct dma_desc);
p->des3 = (unsigned int)dma_phy;
p++;
}
p->des3 = (unsigned int)phy_addr;
}
}
static void stmmac_refill_desc3(void *priv_ptr, struct dma_desc *p)
{
struct stmmac_priv *priv = (struct stmmac_priv *)priv_ptr;
if (priv->hwts_rx_en && !priv->extend_desc)
p->des3 = (unsigned int)(priv->dma_rx_phy +
(((priv->dirty_rx) + 1) %
priv->dma_rx_size) *
sizeof(struct dma_desc));
}
static void stmmac_clean_desc3(void *priv_ptr, struct dma_desc *p)
{
struct stmmac_priv *priv = (struct stmmac_priv *)priv_ptr;
if (priv->hw->desc->get_tx_ls(p) && !priv->extend_desc)
p->des3 = (unsigned int)(priv->dma_tx_phy +
(((priv->dirty_tx + 1) %
priv->dma_tx_size) *
sizeof(struct dma_desc)));
}
