void *ife_encode(struct sk_buff *skb, u16 metalen)
{
int hdrm = metalen + IFE_METAHDRLEN;
int total_push = hdrm + skb->dev->hard_header_len;
struct ifeheadr *ifehdr;
struct ethhdr *iethh;
int skboff = 0;
int err;
err = skb_cow_head(skb, total_push);
if (unlikely(err))
return NULL;
iethh = (struct ethhdr *) skb->data;
__skb_push(skb, total_push);
memcpy(skb->data, iethh, skb->dev->hard_header_len);
skb_reset_mac_header(skb);
skboff += skb->dev->hard_header_len;
ifehdr = (struct ifeheadr *) (skb->data + skboff);
metalen += IFE_METAHDRLEN;
ifehdr->metalen = htons(metalen);
return ifehdr->tlv_data;
}
void *ife_decode(struct sk_buff *skb, u16 *metalen)
{
struct ifeheadr *ifehdr;
int total_pull;
u16 ifehdrln;
ifehdr = (struct ifeheadr *) (skb->data + skb->dev->hard_header_len);
ifehdrln = ntohs(ifehdr->metalen);
total_pull = skb->dev->hard_header_len + ifehdrln;
if (unlikely(ifehdrln < 2))
return NULL;
if (unlikely(!pskb_may_pull(skb, total_pull)))
return NULL;
skb_set_mac_header(skb, total_pull);
__skb_pull(skb, total_pull);
*metalen = ifehdrln - IFE_METAHDRLEN;
return &ifehdr->tlv_data;
}
void *ife_tlv_meta_decode(void *skbdata, u16 *attrtype, u16 *dlen, u16 *totlen)
{
struct meta_tlvhdr *tlv = (struct meta_tlvhdr *) skbdata;
*dlen = ntohs(tlv->len) - NLA_HDRLEN;
*attrtype = ntohs(tlv->type);
if (totlen)
*totlen = nla_total_size(*dlen);
return skbdata + sizeof(struct meta_tlvhdr);
}
void *ife_tlv_meta_next(void *skbdata)
{
struct meta_tlvhdr *tlv = (struct meta_tlvhdr *) skbdata;
u16 tlvlen = ntohs(tlv->len);
tlvlen = NLA_ALIGN(tlvlen);
return skbdata + tlvlen;
}
int ife_tlv_meta_encode(void *skbdata, u16 attrtype, u16 dlen, const void *dval)
{
__be32 *tlv = (__be32 *) (skbdata);
u16 totlen = nla_total_size(dlen);
char *dptr = (char *) tlv + NLA_HDRLEN;
u32 htlv = attrtype << 16 | (dlen + NLA_HDRLEN);
*tlv = htonl(htlv);
memset(dptr, 0, totlen - NLA_HDRLEN);
memcpy(dptr, dval, dlen);
return totlen;
}
