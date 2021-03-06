static void *esp_alloc_tmp(struct crypto_aead *aead, int nfrags, int extralen)
{
unsigned int len;
len = extralen;
len += crypto_aead_ivsize(aead);
if (len) {
len += crypto_aead_alignmask(aead) &
~(crypto_tfm_ctx_alignment() - 1);
len = ALIGN(len, crypto_tfm_ctx_alignment());
}
len += sizeof(struct aead_request) + crypto_aead_reqsize(aead);
len = ALIGN(len, __alignof__(struct scatterlist));
len += sizeof(struct scatterlist) * nfrags;
return kmalloc(len, GFP_ATOMIC);
}
static inline void *esp_tmp_extra(void *tmp)
{
return PTR_ALIGN(tmp, __alignof__(struct esp_output_extra));
}
static inline u8 *esp_tmp_iv(struct crypto_aead *aead, void *tmp, int extralen)
{
return crypto_aead_ivsize(aead) ?
PTR_ALIGN((u8 *)tmp + extralen,
crypto_aead_alignmask(aead) + 1) : tmp + extralen;
}
static inline struct aead_request *esp_tmp_req(struct crypto_aead *aead, u8 *iv)
{
struct aead_request *req;
req = (void *)PTR_ALIGN(iv + crypto_aead_ivsize(aead),
crypto_tfm_ctx_alignment());
aead_request_set_tfm(req, aead);
return req;
}
static inline struct scatterlist *esp_req_sg(struct crypto_aead *aead,
struct aead_request *req)
{
return (void *)ALIGN((unsigned long)(req + 1) +
crypto_aead_reqsize(aead),
__alignof__(struct scatterlist));
}
static void esp_ssg_unref(struct xfrm_state *x, void *tmp)
{
struct esp_output_extra *extra = esp_tmp_extra(tmp);
struct crypto_aead *aead = x->data;
int extralen = 0;
u8 *iv;
struct aead_request *req;
struct scatterlist *sg;
if (x->props.flags & XFRM_STATE_ESN)
extralen += sizeof(*extra);
extra = esp_tmp_extra(tmp);
iv = esp_tmp_iv(aead, tmp, extralen);
req = esp_tmp_req(aead, iv);
if (req->src != req->dst)
for (sg = sg_next(req->src); sg; sg = sg_next(sg))
put_page(sg_page(sg));
}
static void esp_output_done(struct crypto_async_request *base, int err)
{
struct sk_buff *skb = base->data;
void *tmp;
struct dst_entry *dst = skb_dst(skb);
struct xfrm_state *x = dst->xfrm;
tmp = ESP_SKB_CB(skb)->tmp;
esp_ssg_unref(x, tmp);
kfree(tmp);
xfrm_output_resume(skb, err);
}
static void esp_restore_header(struct sk_buff *skb, unsigned int offset)
{
struct ip_esp_hdr *esph = (void *)(skb->data + offset);
void *tmp = ESP_SKB_CB(skb)->tmp;
__be32 *seqhi = esp_tmp_extra(tmp);
esph->seq_no = esph->spi;
esph->spi = *seqhi;
}
static void esp_output_restore_header(struct sk_buff *skb)
{
void *tmp = ESP_SKB_CB(skb)->tmp;
struct esp_output_extra *extra = esp_tmp_extra(tmp);
esp_restore_header(skb, skb_transport_offset(skb) + extra->esphoff -
sizeof(__be32));
}
static struct ip_esp_hdr *esp_output_set_extra(struct sk_buff *skb,
struct xfrm_state *x,
struct ip_esp_hdr *esph,
struct esp_output_extra *extra)
{
if ((x->props.flags & XFRM_STATE_ESN)) {
__u32 seqhi;
struct xfrm_offload *xo = xfrm_offload(skb);
if (xo)
seqhi = xo->seq.hi;
else
seqhi = XFRM_SKB_CB(skb)->seq.output.hi;
extra->esphoff = (unsigned char *)esph -
skb_transport_header(skb);
esph = (struct ip_esp_hdr *)((unsigned char *)esph - 4);
extra->seqhi = esph->spi;
esph->seq_no = htonl(seqhi);
}
esph->spi = x->id.spi;
return esph;
}
static void esp_output_done_esn(struct crypto_async_request *base, int err)
{
struct sk_buff *skb = base->data;
esp_output_restore_header(skb);
esp_output_done(base, err);
}
static void esp_output_fill_trailer(u8 *tail, int tfclen, int plen, __u8 proto)
{
if (tfclen) {
memset(tail, 0, tfclen);
tail += tfclen;
}
do {
int i;
for (i = 0; i < plen - 2; i++)
tail[i] = i + 1;
} while (0);
tail[plen - 2] = plen - 2;
tail[plen - 1] = proto;
}
static void esp_output_udp_encap(struct xfrm_state *x, struct sk_buff *skb, struct esp_info *esp)
{
int encap_type;
struct udphdr *uh;
__be32 *udpdata32;
__be16 sport, dport;
struct xfrm_encap_tmpl *encap = x->encap;
struct ip_esp_hdr *esph = esp->esph;
spin_lock_bh(&x->lock);
sport = encap->encap_sport;
dport = encap->encap_dport;
encap_type = encap->encap_type;
spin_unlock_bh(&x->lock);
uh = (struct udphdr *)esph;
uh->source = sport;
uh->dest = dport;
uh->len = htons(skb->len + esp->tailen
- skb_transport_offset(skb));
uh->check = 0;
switch (encap_type) {
default:
case UDP_ENCAP_ESPINUDP:
esph = (struct ip_esp_hdr *)(uh + 1);
break;
case UDP_ENCAP_ESPINUDP_NON_IKE:
udpdata32 = (__be32 *)(uh + 1);
udpdata32[0] = udpdata32[1] = 0;
esph = (struct ip_esp_hdr *)(udpdata32 + 2);
break;
}
*skb_mac_header(skb) = IPPROTO_UDP;
esp->esph = esph;
}
int esp_output_head(struct xfrm_state *x, struct sk_buff *skb, struct esp_info *esp)
{
u8 *tail;
u8 *vaddr;
int nfrags;
int esph_offset;
struct page *page;
struct sk_buff *trailer;
int tailen = esp->tailen;
if (x->encap)
esp_output_udp_encap(x, skb, esp);
if (!skb_cloned(skb)) {
if (tailen <= skb_availroom(skb)) {
nfrags = 1;
trailer = skb;
tail = skb_tail_pointer(trailer);
goto skip_cow;
} else if ((skb_shinfo(skb)->nr_frags < MAX_SKB_FRAGS)
&& !skb_has_frag_list(skb)) {
int allocsize;
struct sock *sk = skb->sk;
struct page_frag *pfrag = &x->xfrag;
esp->inplace = false;
allocsize = ALIGN(tailen, L1_CACHE_BYTES);
spin_lock_bh(&x->lock);
if (unlikely(!skb_page_frag_refill(allocsize, pfrag, GFP_ATOMIC))) {
spin_unlock_bh(&x->lock);
goto cow;
}
page = pfrag->page;
get_page(page);
vaddr = kmap_atomic(page);
tail = vaddr + pfrag->offset;
esp_output_fill_trailer(tail, esp->tfclen, esp->plen, esp->proto);
kunmap_atomic(vaddr);
spin_unlock_bh(&x->lock);
nfrags = skb_shinfo(skb)->nr_frags;
__skb_fill_page_desc(skb, nfrags, page, pfrag->offset,
tailen);
skb_shinfo(skb)->nr_frags = ++nfrags;
pfrag->offset = pfrag->offset + allocsize;
nfrags++;
skb->len += tailen;
skb->data_len += tailen;
skb->truesize += tailen;
if (sk)
atomic_add(tailen, &sk->sk_wmem_alloc);
goto out;
}
}
cow:
esph_offset = (unsigned char *)esp->esph - skb_transport_header(skb);
nfrags = skb_cow_data(skb, tailen, &trailer);
if (nfrags < 0)
goto out;
tail = skb_tail_pointer(trailer);
esp->esph = (struct ip_esp_hdr *)(skb_transport_header(skb) + esph_offset);
skip_cow:
esp_output_fill_trailer(tail, esp->tfclen, esp->plen, esp->proto);
pskb_put(skb, trailer, tailen);
out:
return nfrags;
}
int esp_output_tail(struct xfrm_state *x, struct sk_buff *skb, struct esp_info *esp)
{
u8 *iv;
int alen;
void *tmp;
int ivlen;
int assoclen;
int extralen;
struct page *page;
struct ip_esp_hdr *esph;
struct crypto_aead *aead;
struct aead_request *req;
struct scatterlist *sg, *dsg;
struct esp_output_extra *extra;
int err = -ENOMEM;
assoclen = sizeof(struct ip_esp_hdr);
extralen = 0;
if (x->props.flags & XFRM_STATE_ESN) {
extralen += sizeof(*extra);
assoclen += sizeof(__be32);
}
aead = x->data;
alen = crypto_aead_authsize(aead);
ivlen = crypto_aead_ivsize(aead);
tmp = esp_alloc_tmp(aead, esp->nfrags + 2, extralen);
if (!tmp)
goto error;
extra = esp_tmp_extra(tmp);
iv = esp_tmp_iv(aead, tmp, extralen);
req = esp_tmp_req(aead, iv);
sg = esp_req_sg(aead, req);
if (esp->inplace)
dsg = sg;
else
dsg = &sg[esp->nfrags];
esph = esp_output_set_extra(skb, x, esp->esph, extra);
esp->esph = esph;
sg_init_table(sg, esp->nfrags);
skb_to_sgvec(skb, sg,
(unsigned char *)esph - skb->data,
assoclen + ivlen + esp->clen + alen);
if (!esp->inplace) {
int allocsize;
struct page_frag *pfrag = &x->xfrag;
allocsize = ALIGN(skb->data_len, L1_CACHE_BYTES);
spin_lock_bh(&x->lock);
if (unlikely(!skb_page_frag_refill(allocsize, pfrag, GFP_ATOMIC))) {
spin_unlock_bh(&x->lock);
goto error;
}
skb_shinfo(skb)->nr_frags = 1;
page = pfrag->page;
get_page(page);
__skb_fill_page_desc(skb, 0, page, pfrag->offset, skb->data_len);
pfrag->offset = pfrag->offset + allocsize;
spin_unlock_bh(&x->lock);
sg_init_table(dsg, skb_shinfo(skb)->nr_frags + 1);
skb_to_sgvec(skb, dsg,
(unsigned char *)esph - skb->data,
assoclen + ivlen + esp->clen + alen);
}
if ((x->props.flags & XFRM_STATE_ESN))
aead_request_set_callback(req, 0, esp_output_done_esn, skb);
else
aead_request_set_callback(req, 0, esp_output_done, skb);
aead_request_set_crypt(req, sg, dsg, ivlen + esp->clen, iv);
aead_request_set_ad(req, assoclen);
memset(iv, 0, ivlen);
memcpy(iv + ivlen - min(ivlen, 8), (u8 *)&esp->seqno + 8 - min(ivlen, 8),
min(ivlen, 8));
ESP_SKB_CB(skb)->tmp = tmp;
err = crypto_aead_encrypt(req);
switch (err) {
case -EINPROGRESS:
goto error;
case -EBUSY:
err = NET_XMIT_DROP;
break;
case 0:
if ((x->props.flags & XFRM_STATE_ESN))
esp_output_restore_header(skb);
}
if (sg != dsg)
esp_ssg_unref(x, tmp);
kfree(tmp);
error:
return err;
}
static int esp_output(struct xfrm_state *x, struct sk_buff *skb)
{
int alen;
int blksize;
struct ip_esp_hdr *esph;
struct crypto_aead *aead;
struct esp_info esp;
esp.inplace = true;
esp.proto = *skb_mac_header(skb);
*skb_mac_header(skb) = IPPROTO_ESP;
aead = x->data;
alen = crypto_aead_authsize(aead);
esp.tfclen = 0;
if (x->tfcpad) {
struct xfrm_dst *dst = (struct xfrm_dst *)skb_dst(skb);
u32 padto;
padto = min(x->tfcpad, esp4_get_mtu(x, dst->child_mtu_cached));
if (skb->len < padto)
esp.tfclen = padto - skb->len;
}
blksize = ALIGN(crypto_aead_blocksize(aead), 4);
esp.clen = ALIGN(skb->len + 2 + esp.tfclen, blksize);
esp.plen = esp.clen - skb->len - esp.tfclen;
esp.tailen = esp.tfclen + esp.plen + alen;
esp.esph = ip_esp_hdr(skb);
esp.nfrags = esp_output_head(x, skb, &esp);
if (esp.nfrags < 0)
return esp.nfrags;
esph = esp.esph;
esph->spi = x->id.spi;
esph->seq_no = htonl(XFRM_SKB_CB(skb)->seq.output.low);
esp.seqno = cpu_to_be64(XFRM_SKB_CB(skb)->seq.output.low +
((u64)XFRM_SKB_CB(skb)->seq.output.hi << 32));
skb_push(skb, -skb_network_offset(skb));
return esp_output_tail(x, skb, &esp);
}
int esp_input_done2(struct sk_buff *skb, int err)
{
const struct iphdr *iph;
struct xfrm_state *x = xfrm_input_state(skb);
struct xfrm_offload *xo = xfrm_offload(skb);
struct crypto_aead *aead = x->data;
int alen = crypto_aead_authsize(aead);
int hlen = sizeof(struct ip_esp_hdr) + crypto_aead_ivsize(aead);
int elen = skb->len - hlen;
int ihl;
u8 nexthdr[2];
int padlen;
if (!xo || (xo && !(xo->flags & CRYPTO_DONE)))
kfree(ESP_SKB_CB(skb)->tmp);
if (unlikely(err))
goto out;
if (skb_copy_bits(skb, skb->len-alen-2, nexthdr, 2))
BUG();
err = -EINVAL;
padlen = nexthdr[0];
if (padlen + 2 + alen >= elen)
goto out;
iph = ip_hdr(skb);
ihl = iph->ihl * 4;
if (x->encap) {
struct xfrm_encap_tmpl *encap = x->encap;
struct udphdr *uh = (void *)(skb_network_header(skb) + ihl);
if (iph->saddr != x->props.saddr.a4 ||
uh->source != encap->encap_sport) {
xfrm_address_t ipaddr;
ipaddr.a4 = iph->saddr;
km_new_mapping(x, &ipaddr, uh->source);
}
if (x->props.mode == XFRM_MODE_TRANSPORT)
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
pskb_trim(skb, skb->len - alen - padlen - 2);
__skb_pull(skb, hlen);
if (x->props.mode == XFRM_MODE_TUNNEL)
skb_reset_transport_header(skb);
else
skb_set_transport_header(skb, -ihl);
err = nexthdr[1];
if (err == IPPROTO_NONE)
err = -EINVAL;
out:
return err;
}
static void esp_input_done(struct crypto_async_request *base, int err)
{
struct sk_buff *skb = base->data;
xfrm_input_resume(skb, esp_input_done2(skb, err));
}
static void esp_input_restore_header(struct sk_buff *skb)
{
esp_restore_header(skb, 0);
__skb_pull(skb, 4);
}
static void esp_input_set_header(struct sk_buff *skb, __be32 *seqhi)
{
struct xfrm_state *x = xfrm_input_state(skb);
struct ip_esp_hdr *esph = (struct ip_esp_hdr *)skb->data;
if ((x->props.flags & XFRM_STATE_ESN)) {
esph = (void *)skb_push(skb, 4);
*seqhi = esph->spi;
esph->spi = esph->seq_no;
esph->seq_no = XFRM_SKB_CB(skb)->seq.input.hi;
}
}
static void esp_input_done_esn(struct crypto_async_request *base, int err)
{
struct sk_buff *skb = base->data;
esp_input_restore_header(skb);
esp_input_done(base, err);
}
static int esp_input(struct xfrm_state *x, struct sk_buff *skb)
{
struct ip_esp_hdr *esph;
struct crypto_aead *aead = x->data;
struct aead_request *req;
struct sk_buff *trailer;
int ivlen = crypto_aead_ivsize(aead);
int elen = skb->len - sizeof(*esph) - ivlen;
int nfrags;
int assoclen;
int seqhilen;
__be32 *seqhi;
void *tmp;
u8 *iv;
struct scatterlist *sg;
int err = -EINVAL;
if (!pskb_may_pull(skb, sizeof(*esph) + ivlen))
goto out;
if (elen <= 0)
goto out;
assoclen = sizeof(*esph);
seqhilen = 0;
if (x->props.flags & XFRM_STATE_ESN) {
seqhilen += sizeof(__be32);
assoclen += seqhilen;
}
if (!skb_cloned(skb)) {
if (!skb_is_nonlinear(skb)) {
nfrags = 1;
goto skip_cow;
} else if (!skb_has_frag_list(skb)) {
nfrags = skb_shinfo(skb)->nr_frags;
nfrags++;
goto skip_cow;
}
}
err = skb_cow_data(skb, 0, &trailer);
if (err < 0)
goto out;
nfrags = err;
skip_cow:
err = -ENOMEM;
tmp = esp_alloc_tmp(aead, nfrags, seqhilen);
if (!tmp)
goto out;
ESP_SKB_CB(skb)->tmp = tmp;
seqhi = esp_tmp_extra(tmp);
iv = esp_tmp_iv(aead, tmp, seqhilen);
req = esp_tmp_req(aead, iv);
sg = esp_req_sg(aead, req);
esp_input_set_header(skb, seqhi);
sg_init_table(sg, nfrags);
skb_to_sgvec(skb, sg, 0, skb->len);
skb->ip_summed = CHECKSUM_NONE;
if ((x->props.flags & XFRM_STATE_ESN))
aead_request_set_callback(req, 0, esp_input_done_esn, skb);
else
aead_request_set_callback(req, 0, esp_input_done, skb);
aead_request_set_crypt(req, sg, sg, elen + ivlen, iv);
aead_request_set_ad(req, assoclen);
err = crypto_aead_decrypt(req);
if (err == -EINPROGRESS)
goto out;
if ((x->props.flags & XFRM_STATE_ESN))
esp_input_restore_header(skb);
err = esp_input_done2(skb, err);
out:
return err;
}
static u32 esp4_get_mtu(struct xfrm_state *x, int mtu)
{
struct crypto_aead *aead = x->data;
u32 blksize = ALIGN(crypto_aead_blocksize(aead), 4);
unsigned int net_adj;
switch (x->props.mode) {
case XFRM_MODE_TRANSPORT:
case XFRM_MODE_BEET:
net_adj = sizeof(struct iphdr);
break;
case XFRM_MODE_TUNNEL:
net_adj = 0;
break;
default:
BUG();
}
return ((mtu - x->props.header_len - crypto_aead_authsize(aead) -
net_adj) & ~(blksize - 1)) + net_adj - 2;
}
static int esp4_err(struct sk_buff *skb, u32 info)
{
struct net *net = dev_net(skb->dev);
const struct iphdr *iph = (const struct iphdr *)skb->data;
struct ip_esp_hdr *esph = (struct ip_esp_hdr *)(skb->data+(iph->ihl<<2));
struct xfrm_state *x;
switch (icmp_hdr(skb)->type) {
case ICMP_DEST_UNREACH:
if (icmp_hdr(skb)->code != ICMP_FRAG_NEEDED)
return 0;
case ICMP_REDIRECT:
break;
default:
return 0;
}
x = xfrm_state_lookup(net, skb->mark, (const xfrm_address_t *)&iph->daddr,
esph->spi, IPPROTO_ESP, AF_INET);
if (!x)
return 0;
if (icmp_hdr(skb)->type == ICMP_DEST_UNREACH)
ipv4_update_pmtu(skb, net, info, 0, 0, IPPROTO_ESP, 0);
else
ipv4_redirect(skb, net, 0, 0, IPPROTO_ESP, 0);
xfrm_state_put(x);
return 0;
}
static void esp_destroy(struct xfrm_state *x)
{
struct crypto_aead *aead = x->data;
if (!aead)
return;
crypto_free_aead(aead);
}
static int esp_init_aead(struct xfrm_state *x)
{
char aead_name[CRYPTO_MAX_ALG_NAME];
struct crypto_aead *aead;
int err;
u32 mask = 0;
err = -ENAMETOOLONG;
if (snprintf(aead_name, CRYPTO_MAX_ALG_NAME, "%s(%s)",
x->geniv, x->aead->alg_name) >= CRYPTO_MAX_ALG_NAME)
goto error;
if (x->xso.offload_handle)
mask |= CRYPTO_ALG_ASYNC;
aead = crypto_alloc_aead(aead_name, 0, mask);
err = PTR_ERR(aead);
if (IS_ERR(aead))
goto error;
x->data = aead;
err = crypto_aead_setkey(aead, x->aead->alg_key,
(x->aead->alg_key_len + 7) / 8);
if (err)
goto error;
err = crypto_aead_setauthsize(aead, x->aead->alg_icv_len / 8);
if (err)
goto error;
error:
return err;
}
static int esp_init_authenc(struct xfrm_state *x)
{
struct crypto_aead *aead;
struct crypto_authenc_key_param *param;
struct rtattr *rta;
char *key;
char *p;
char authenc_name[CRYPTO_MAX_ALG_NAME];
unsigned int keylen;
int err;
u32 mask = 0;
err = -EINVAL;
if (!x->ealg)
goto error;
err = -ENAMETOOLONG;
if ((x->props.flags & XFRM_STATE_ESN)) {
if (snprintf(authenc_name, CRYPTO_MAX_ALG_NAME,
"%s%sauthencesn(%s,%s)%s",
x->geniv ?: "", x->geniv ? "(" : "",
x->aalg ? x->aalg->alg_name : "digest_null",
x->ealg->alg_name,
x->geniv ? ")" : "") >= CRYPTO_MAX_ALG_NAME)
goto error;
} else {
if (snprintf(authenc_name, CRYPTO_MAX_ALG_NAME,
"%s%sauthenc(%s,%s)%s",
x->geniv ?: "", x->geniv ? "(" : "",
x->aalg ? x->aalg->alg_name : "digest_null",
x->ealg->alg_name,
x->geniv ? ")" : "") >= CRYPTO_MAX_ALG_NAME)
goto error;
}
if (x->xso.offload_handle)
mask |= CRYPTO_ALG_ASYNC;
aead = crypto_alloc_aead(authenc_name, 0, mask);
err = PTR_ERR(aead);
if (IS_ERR(aead))
goto error;
x->data = aead;
keylen = (x->aalg ? (x->aalg->alg_key_len + 7) / 8 : 0) +
(x->ealg->alg_key_len + 7) / 8 + RTA_SPACE(sizeof(*param));
err = -ENOMEM;
key = kmalloc(keylen, GFP_KERNEL);
if (!key)
goto error;
p = key;
rta = (void *)p;
rta->rta_type = CRYPTO_AUTHENC_KEYA_PARAM;
rta->rta_len = RTA_LENGTH(sizeof(*param));
param = RTA_DATA(rta);
p += RTA_SPACE(sizeof(*param));
if (x->aalg) {
struct xfrm_algo_desc *aalg_desc;
memcpy(p, x->aalg->alg_key, (x->aalg->alg_key_len + 7) / 8);
p += (x->aalg->alg_key_len + 7) / 8;
aalg_desc = xfrm_aalg_get_byname(x->aalg->alg_name, 0);
BUG_ON(!aalg_desc);
err = -EINVAL;
if (aalg_desc->uinfo.auth.icv_fullbits / 8 !=
crypto_aead_authsize(aead)) {
pr_info("ESP: %s digestsize %u != %hu\n",
x->aalg->alg_name,
crypto_aead_authsize(aead),
aalg_desc->uinfo.auth.icv_fullbits / 8);
goto free_key;
}
err = crypto_aead_setauthsize(
aead, x->aalg->alg_trunc_len / 8);
if (err)
goto free_key;
}
param->enckeylen = cpu_to_be32((x->ealg->alg_key_len + 7) / 8);
memcpy(p, x->ealg->alg_key, (x->ealg->alg_key_len + 7) / 8);
err = crypto_aead_setkey(aead, key, keylen);
free_key:
kfree(key);
error:
return err;
}
static int esp_init_state(struct xfrm_state *x)
{
struct crypto_aead *aead;
u32 align;
int err;
x->data = NULL;
if (x->aead)
err = esp_init_aead(x);
else
err = esp_init_authenc(x);
if (err)
goto error;
aead = x->data;
x->props.header_len = sizeof(struct ip_esp_hdr) +
crypto_aead_ivsize(aead);
if (x->props.mode == XFRM_MODE_TUNNEL)
x->props.header_len += sizeof(struct iphdr);
else if (x->props.mode == XFRM_MODE_BEET && x->sel.family != AF_INET6)
x->props.header_len += IPV4_BEET_PHMAXLEN;
if (x->encap) {
struct xfrm_encap_tmpl *encap = x->encap;
switch (encap->encap_type) {
default:
goto error;
case UDP_ENCAP_ESPINUDP:
x->props.header_len += sizeof(struct udphdr);
break;
case UDP_ENCAP_ESPINUDP_NON_IKE:
x->props.header_len += sizeof(struct udphdr) + 2 * sizeof(u32);
break;
}
}
align = ALIGN(crypto_aead_blocksize(aead), 4);
x->props.trailer_len = align + 1 + crypto_aead_authsize(aead);
error:
return err;
}
static int esp4_rcv_cb(struct sk_buff *skb, int err)
{
return 0;
}
static int __init esp4_init(void)
{
if (xfrm_register_type(&esp_type, AF_INET) < 0) {
pr_info("%s: can't add xfrm type\n", __func__);
return -EAGAIN;
}
if (xfrm4_protocol_register(&esp4_protocol, IPPROTO_ESP) < 0) {
pr_info("%s: can't add protocol\n", __func__);
xfrm_unregister_type(&esp_type, AF_INET);
return -EAGAIN;
}
return 0;
}
static void __exit esp4_fini(void)
{
if (xfrm4_protocol_deregister(&esp4_protocol, IPPROTO_ESP) < 0)
pr_info("%s: can't remove protocol\n", __func__);
if (xfrm_unregister_type(&esp_type, AF_INET) < 0)
pr_info("%s: can't remove xfrm type\n", __func__);
}
