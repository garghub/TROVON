static int em_nbyte_change(struct tcf_proto *tp, void *data, int data_len,
struct tcf_ematch *em)
{
struct tcf_em_nbyte *nbyte = data;
if (data_len < sizeof(*nbyte) ||
data_len < (sizeof(*nbyte) + nbyte->len))
return -EINVAL;
em->datalen = sizeof(*nbyte) + nbyte->len;
em->data = (unsigned long)kmemdup(data, em->datalen, GFP_KERNEL);
if (em->data == 0UL)
return -ENOBUFS;
return 0;
}
static int em_nbyte_match(struct sk_buff *skb, struct tcf_ematch *em,
struct tcf_pkt_info *info)
{
struct nbyte_data *nbyte = (struct nbyte_data *) em->data;
unsigned char *ptr = tcf_get_base_ptr(skb, nbyte->hdr.layer);
ptr += nbyte->hdr.off;
if (!tcf_valid_offset(skb, ptr, nbyte->hdr.len))
return 0;
return !memcmp(ptr + nbyte->hdr.off, nbyte->pattern, nbyte->hdr.len);
}
static int __init init_em_nbyte(void)
{
return tcf_em_register(&em_nbyte_ops);
}
static void __exit exit_em_nbyte(void)
{
tcf_em_unregister(&em_nbyte_ops);
}
