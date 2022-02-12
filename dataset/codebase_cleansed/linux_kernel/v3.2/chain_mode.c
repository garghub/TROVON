unsigned int stmmac_jumbo_frm(void *p, struct sk_buff *skb, int csum)
{
struct stmmac_priv *priv = (struct stmmac_priv *) p;
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
priv->hw->desc->prepare_tx_desc(desc, 1, bmax, csum);
while (len != 0) {
entry = (++priv->cur_tx) % txsize;
desc = priv->dma_tx + entry;
if (len > bmax) {
desc->des2 = dma_map_single(priv->device,
(skb->data + bmax * i),
bmax, DMA_TO_DEVICE);
priv->hw->desc->prepare_tx_desc(desc, 0, bmax,
csum);
priv->hw->desc->set_tx_owner(desc);
priv->tx_skbuff[entry] = NULL;
len -= bmax;
i++;
} else {
desc->des2 = dma_map_single(priv->device,
(skb->data + bmax * i), len,
DMA_TO_DEVICE);
priv->hw->desc->prepare_tx_desc(desc, 0, len,
csum);
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
static void stmmac_refill_desc3(int bfsize, struct dma_desc *p)
{
}
static void stmmac_init_desc3(int des3_as_data_buf, struct dma_desc *p)
{
}
static void stmmac_clean_desc3(struct dma_desc *p)
{
}
static void stmmac_init_dma_chain(struct dma_desc *des, dma_addr_t phy_addr,
unsigned int size)
{
int i;
struct dma_desc *p = des;
dma_addr_t dma_phy = phy_addr;
for (i = 0; i < (size - 1); i++) {
dma_phy += sizeof(struct dma_desc);
p->des3 = (unsigned int)dma_phy;
p++;
}
p->des3 = (unsigned int)phy_addr;
}
static int stmmac_set_16kib_bfsize(int mtu)
{
return 0;
}
