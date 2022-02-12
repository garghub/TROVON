static unsigned int classify(const struct sk_buff *skb)
{
if (likely(skb->dev && skb->dev->phydev &&
skb->dev->phydev->drv))
return ptp_classify_raw(skb);
else
return PTP_CLASS_NONE;
}
void skb_clone_tx_timestamp(struct sk_buff *skb)
{
struct phy_device *phydev;
struct sk_buff *clone;
unsigned int type;
if (!skb->sk)
return;
type = classify(skb);
if (type == PTP_CLASS_NONE)
return;
phydev = skb->dev->phydev;
if (likely(phydev->drv->txtstamp)) {
clone = skb_clone_sk(skb);
if (!clone)
return;
phydev->drv->txtstamp(phydev, clone, type);
}
}
bool skb_defer_rx_timestamp(struct sk_buff *skb)
{
struct phy_device *phydev;
unsigned int type;
if (skb_headroom(skb) < ETH_HLEN)
return false;
__skb_push(skb, ETH_HLEN);
type = classify(skb);
__skb_pull(skb, ETH_HLEN);
if (type == PTP_CLASS_NONE)
return false;
phydev = skb->dev->phydev;
if (likely(phydev->drv->rxtstamp))
return phydev->drv->rxtstamp(phydev, skb, type);
return false;
}
