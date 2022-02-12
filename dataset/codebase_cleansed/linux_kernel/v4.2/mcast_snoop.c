static int ipv6_mc_check_ip6hdr(struct sk_buff *skb)
{
const struct ipv6hdr *ip6h;
unsigned int len;
unsigned int offset = skb_network_offset(skb) + sizeof(*ip6h);
if (!pskb_may_pull(skb, offset))
return -EINVAL;
ip6h = ipv6_hdr(skb);
if (ip6h->version != 6)
return -EINVAL;
len = offset + ntohs(ip6h->payload_len);
if (skb->len < len || len <= offset)
return -EINVAL;
return 0;
}
static int ipv6_mc_check_exthdrs(struct sk_buff *skb)
{
const struct ipv6hdr *ip6h;
int offset;
u8 nexthdr;
__be16 frag_off;
ip6h = ipv6_hdr(skb);
if (ip6h->nexthdr != IPPROTO_HOPOPTS)
return -ENOMSG;
nexthdr = ip6h->nexthdr;
offset = skb_network_offset(skb) + sizeof(*ip6h);
offset = ipv6_skip_exthdr(skb, offset, &nexthdr, &frag_off);
if (offset < 0)
return -EINVAL;
if (nexthdr != IPPROTO_ICMPV6)
return -ENOMSG;
skb_set_transport_header(skb, offset);
return 0;
}
static int ipv6_mc_check_mld_reportv2(struct sk_buff *skb)
{
unsigned int len = skb_transport_offset(skb);
len += sizeof(struct mld2_report);
return pskb_may_pull(skb, len) ? 0 : -EINVAL;
}
static int ipv6_mc_check_mld_query(struct sk_buff *skb)
{
struct mld_msg *mld;
unsigned int len = skb_transport_offset(skb);
if (!(ipv6_addr_type(&ipv6_hdr(skb)->saddr) & IPV6_ADDR_LINKLOCAL))
return -EINVAL;
len += sizeof(struct mld_msg);
if (skb->len < len)
return -EINVAL;
if (skb->len != len) {
len += sizeof(struct mld2_query) - sizeof(struct mld_msg);
if (skb->len < len || !pskb_may_pull(skb, len))
return -EINVAL;
}
mld = (struct mld_msg *)skb_transport_header(skb);
if (ipv6_addr_any(&mld->mld_mca) &&
!ipv6_addr_is_ll_all_nodes(&ipv6_hdr(skb)->daddr))
return -EINVAL;
return 0;
}
static int ipv6_mc_check_mld_msg(struct sk_buff *skb)
{
struct mld_msg *mld = (struct mld_msg *)skb_transport_header(skb);
switch (mld->mld_type) {
case ICMPV6_MGM_REDUCTION:
case ICMPV6_MGM_REPORT:
return 0;
case ICMPV6_MLD2_REPORT:
return ipv6_mc_check_mld_reportv2(skb);
case ICMPV6_MGM_QUERY:
return ipv6_mc_check_mld_query(skb);
default:
return -ENOMSG;
}
}
static inline __sum16 ipv6_mc_validate_checksum(struct sk_buff *skb)
{
return skb_checksum_validate(skb, IPPROTO_ICMPV6, ip6_compute_pseudo);
}
static int __ipv6_mc_check_mld(struct sk_buff *skb,
struct sk_buff **skb_trimmed)
{
struct sk_buff *skb_chk = NULL;
unsigned int transport_len;
unsigned int len = skb_transport_offset(skb) + sizeof(struct mld_msg);
int ret = -EINVAL;
transport_len = ntohs(ipv6_hdr(skb)->payload_len);
transport_len -= skb_transport_offset(skb) - sizeof(struct ipv6hdr);
skb_chk = skb_checksum_trimmed(skb, transport_len,
ipv6_mc_validate_checksum);
if (!skb_chk)
goto err;
if (!pskb_may_pull(skb_chk, len))
goto err;
ret = ipv6_mc_check_mld_msg(skb_chk);
if (ret)
goto err;
if (skb_trimmed)
*skb_trimmed = skb_chk;
else if (skb_chk != skb)
kfree_skb(skb_chk);
ret = 0;
err:
if (ret && skb_chk && skb_chk != skb)
kfree_skb(skb_chk);
return ret;
}
int ipv6_mc_check_mld(struct sk_buff *skb, struct sk_buff **skb_trimmed)
{
int ret;
ret = ipv6_mc_check_ip6hdr(skb);
if (ret < 0)
return ret;
ret = ipv6_mc_check_exthdrs(skb);
if (ret < 0)
return ret;
return __ipv6_mc_check_mld(skb, skb_trimmed);
}
