static struct sk_buff *brcm_tag_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u16 queue = skb_get_queue_mapping(skb);
u8 *brcm_tag;
if (skb_cow_head(skb, BRCM_TAG_LEN) < 0)
return NULL;
skb_push(skb, BRCM_TAG_LEN);
memmove(skb->data, skb->data + BRCM_TAG_LEN, 2 * ETH_ALEN);
brcm_tag = skb->data + 2 * ETH_ALEN;
brcm_tag[0] = (1 << BRCM_OPCODE_SHIFT) |
((queue & BRCM_IG_TC_MASK) << BRCM_IG_TC_SHIFT);
brcm_tag[1] = 0;
brcm_tag[2] = 0;
if (p->dp->index == 8)
brcm_tag[2] = BRCM_IG_DSTMAP2_MASK;
brcm_tag[3] = (1 << p->dp->index) & BRCM_IG_DSTMAP1_MASK;
return skb;
}
static struct sk_buff *brcm_tag_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_port *cpu_dp = dsa_get_cpu_port(dst);
struct dsa_switch *ds = cpu_dp->ds;
int source_port;
u8 *brcm_tag;
if (unlikely(!pskb_may_pull(skb, BRCM_TAG_LEN)))
return NULL;
brcm_tag = skb->data - 2;
if (unlikely((brcm_tag[0] >> BRCM_OPCODE_SHIFT) & BRCM_OPCODE_MASK))
return NULL;
if (unlikely(brcm_tag[2] & BRCM_EG_RC_RSVD))
return NULL;
source_port = brcm_tag[3] & BRCM_EG_PID_MASK;
if (source_port >= ds->num_ports || !ds->ports[source_port].netdev)
return NULL;
skb_pull_rcsum(skb, BRCM_TAG_LEN);
memmove(skb->data - ETH_HLEN,
skb->data - ETH_HLEN - BRCM_TAG_LEN,
2 * ETH_ALEN);
skb->dev = ds->ports[source_port].netdev;
return skb;
}
