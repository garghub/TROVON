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
struct sock *sk = skb->sk;
unsigned int type;
if (!sk)
return;
type = classify(skb);
switch (type) {
case PTP_CLASS_V1_IPV4:
case PTP_CLASS_V1_IPV6:
case PTP_CLASS_V2_IPV4:
case PTP_CLASS_V2_IPV6:
case PTP_CLASS_V2_L2:
case PTP_CLASS_V2_VLAN:
phydev = skb->dev->phydev;
if (likely(phydev->drv->txtstamp)) {
if (!atomic_inc_not_zero(&sk->sk_refcnt))
return;
clone = skb_clone(skb, GFP_ATOMIC);
if (!clone) {
sock_put(sk);
return;
}
clone->sk = sk;
phydev->drv->txtstamp(phydev, clone, type);
}
break;
default:
break;
}
}
void skb_complete_tx_timestamp(struct sk_buff *skb,
struct skb_shared_hwtstamps *hwtstamps)
{
struct sock *sk = skb->sk;
struct sock_exterr_skb *serr;
int err;
if (!hwtstamps) {
sock_put(sk);
kfree_skb(skb);
return;
}
*skb_hwtstamps(skb) = *hwtstamps;
serr = SKB_EXT_ERR(skb);
memset(serr, 0, sizeof(*serr));
serr->ee.ee_errno = ENOMSG;
serr->ee.ee_origin = SO_EE_ORIGIN_TIMESTAMPING;
skb->sk = NULL;
err = sock_queue_err_skb(sk, skb);
sock_put(sk);
if (err)
kfree_skb(skb);
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
switch (type) {
case PTP_CLASS_V1_IPV4:
case PTP_CLASS_V1_IPV6:
case PTP_CLASS_V2_IPV4:
case PTP_CLASS_V2_IPV6:
case PTP_CLASS_V2_L2:
case PTP_CLASS_V2_VLAN:
phydev = skb->dev->phydev;
if (likely(phydev->drv->rxtstamp))
return phydev->drv->rxtstamp(phydev, skb, type);
break;
default:
break;
}
return false;
}
