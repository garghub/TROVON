int llc_mac_hdr_init(struct sk_buff *skb,
const unsigned char *sa, const unsigned char *da)
{
int rc = -EINVAL;
switch (skb->dev->type) {
case ARPHRD_IEEE802_TR:
case ARPHRD_ETHER:
case ARPHRD_LOOPBACK:
rc = dev_hard_header(skb, skb->dev, ETH_P_802_2, da, sa,
skb->len);
if (rc > 0)
rc = 0;
break;
default:
WARN(1, "device type not supported: %d\n", skb->dev->type);
}
return rc;
}
int llc_build_and_send_ui_pkt(struct llc_sap *sap, struct sk_buff *skb,
unsigned char *dmac, unsigned char dsap)
{
int rc;
llc_pdu_header_init(skb, LLC_PDU_TYPE_U, sap->laddr.lsap,
dsap, LLC_PDU_CMD);
llc_pdu_init_as_ui_cmd(skb);
rc = llc_mac_hdr_init(skb, skb->dev->dev_addr, dmac);
if (likely(!rc))
rc = dev_queue_xmit(skb);
return rc;
}
