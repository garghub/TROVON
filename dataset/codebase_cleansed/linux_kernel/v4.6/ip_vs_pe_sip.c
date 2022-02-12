static const char *ip_vs_dbg_callid(char *buf, size_t buf_len,
const char *callid, size_t callid_len,
int *idx)
{
size_t max_len = 64;
size_t len = min3(max_len, callid_len, buf_len - *idx - 1);
memcpy(buf + *idx, callid, len);
buf[*idx+len] = '\0';
*idx += len + 1;
return buf + *idx - len;
}
static int get_callid(const char *dptr, unsigned int dataoff,
unsigned int datalen,
unsigned int *matchoff, unsigned int *matchlen)
{
while (1) {
int ret = ct_sip_get_header(NULL, dptr, dataoff, datalen,
SIP_HDR_CALL_ID, matchoff,
matchlen);
if (ret > 0)
break;
if (!ret)
return -EINVAL;
dataoff += *matchoff;
}
if (*matchlen > IP_VS_PEDATA_MAXLEN)
return -EINVAL;
if (*matchoff + *matchlen == datalen)
return -EINVAL;
if (*(dptr + *matchoff + *matchlen) != '\r' &&
*(dptr + *matchoff + *matchlen) != '\n')
return -EINVAL;
IP_VS_DBG_BUF(9, "SIP callid %s (%d bytes)\n",
IP_VS_DEBUG_CALLID(dptr + *matchoff, *matchlen),
*matchlen);
return 0;
}
static int
ip_vs_sip_fill_param(struct ip_vs_conn_param *p, struct sk_buff *skb)
{
struct ip_vs_iphdr iph;
unsigned int dataoff, datalen, matchoff, matchlen;
const char *dptr;
int retc;
retc = ip_vs_fill_iph_skb(p->af, skb, false, &iph);
if (!retc || iph.protocol != IPPROTO_UDP)
return -EINVAL;
dataoff = iph.len + sizeof(struct udphdr);
if (dataoff >= skb->len)
return -EINVAL;
retc = skb_linearize(skb);
if (retc < 0)
return retc;
dptr = skb->data + dataoff;
datalen = skb->len - dataoff;
if (get_callid(dptr, 0, datalen, &matchoff, &matchlen))
return -EINVAL;
p->pe_data = kmemdup(dptr + matchoff, matchlen, GFP_ATOMIC);
if (!p->pe_data)
return -ENOMEM;
p->pe_data_len = matchlen;
return 0;
}
static bool ip_vs_sip_ct_match(const struct ip_vs_conn_param *p,
struct ip_vs_conn *ct)
{
bool ret = false;
if (ct->af == p->af &&
ip_vs_addr_equal(p->af, p->caddr, &ct->caddr) &&
ip_vs_addr_equal(p->protocol == IPPROTO_IP ? AF_UNSPEC : p->af,
p->vaddr, &ct->vaddr) &&
ct->vport == p->vport &&
ct->flags & IP_VS_CONN_F_TEMPLATE &&
ct->protocol == p->protocol &&
ct->pe_data && ct->pe_data_len == p->pe_data_len &&
!memcmp(ct->pe_data, p->pe_data, p->pe_data_len))
ret = true;
IP_VS_DBG_BUF(9, "SIP template match %s %s->%s:%d %s\n",
ip_vs_proto_name(p->protocol),
IP_VS_DEBUG_CALLID(p->pe_data, p->pe_data_len),
IP_VS_DBG_ADDR(p->af, p->vaddr), ntohs(p->vport),
ret ? "hit" : "not hit");
return ret;
}
static u32 ip_vs_sip_hashkey_raw(const struct ip_vs_conn_param *p,
u32 initval, bool inverse)
{
return jhash(p->pe_data, p->pe_data_len, initval);
}
static int ip_vs_sip_show_pe_data(const struct ip_vs_conn *cp, char *buf)
{
memcpy(buf, cp->pe_data, cp->pe_data_len);
return cp->pe_data_len;
}
static int __init ip_vs_sip_init(void)
{
return register_ip_vs_pe(&ip_vs_sip_pe);
}
static void __exit ip_vs_sip_cleanup(void)
{
unregister_ip_vs_pe(&ip_vs_sip_pe);
synchronize_rcu();
}
