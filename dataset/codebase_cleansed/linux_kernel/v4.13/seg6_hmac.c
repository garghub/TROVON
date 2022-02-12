static int seg6_hmac_cmpfn(struct rhashtable_compare_arg *arg, const void *obj)
{
const struct seg6_hmac_info *hinfo = obj;
return (hinfo->hmackeyid != *(__u32 *)arg->key);
}
static inline void seg6_hinfo_release(struct seg6_hmac_info *hinfo)
{
kfree_rcu(hinfo, rcu);
}
static void seg6_free_hi(void *ptr, void *arg)
{
struct seg6_hmac_info *hinfo = (struct seg6_hmac_info *)ptr;
if (hinfo)
seg6_hinfo_release(hinfo);
}
static struct sr6_tlv_hmac *seg6_get_tlv_hmac(struct ipv6_sr_hdr *srh)
{
struct sr6_tlv_hmac *tlv;
if (srh->hdrlen < (srh->first_segment + 1) * 2 + 5)
return NULL;
if (!sr_has_hmac(srh))
return NULL;
tlv = (struct sr6_tlv_hmac *)
((char *)srh + ((srh->hdrlen + 1) << 3) - 40);
if (tlv->tlvhdr.type != SR6_TLV_HMAC || tlv->tlvhdr.len != 38)
return NULL;
return tlv;
}
static struct seg6_hmac_algo *__hmac_get_algo(u8 alg_id)
{
struct seg6_hmac_algo *algo;
int i, alg_count;
alg_count = sizeof(hmac_algos) / sizeof(struct seg6_hmac_algo);
for (i = 0; i < alg_count; i++) {
algo = &hmac_algos[i];
if (algo->alg_id == alg_id)
return algo;
}
return NULL;
}
static int __do_hmac(struct seg6_hmac_info *hinfo, const char *text, u8 psize,
u8 *output, int outlen)
{
struct seg6_hmac_algo *algo;
struct crypto_shash *tfm;
struct shash_desc *shash;
int ret, dgsize;
algo = __hmac_get_algo(hinfo->alg_id);
if (!algo)
return -ENOENT;
tfm = *this_cpu_ptr(algo->tfms);
dgsize = crypto_shash_digestsize(tfm);
if (dgsize > outlen) {
pr_debug("sr-ipv6: __do_hmac: digest size too big (%d / %d)\n",
dgsize, outlen);
return -ENOMEM;
}
ret = crypto_shash_setkey(tfm, hinfo->secret, hinfo->slen);
if (ret < 0) {
pr_debug("sr-ipv6: crypto_shash_setkey failed: err %d\n", ret);
goto failed;
}
shash = *this_cpu_ptr(algo->shashs);
shash->tfm = tfm;
ret = crypto_shash_digest(shash, text, psize, output);
if (ret < 0) {
pr_debug("sr-ipv6: crypto_shash_digest failed: err %d\n", ret);
goto failed;
}
return dgsize;
failed:
return ret;
}
int seg6_hmac_compute(struct seg6_hmac_info *hinfo, struct ipv6_sr_hdr *hdr,
struct in6_addr *saddr, u8 *output)
{
__be32 hmackeyid = cpu_to_be32(hinfo->hmackeyid);
u8 tmp_out[SEG6_HMAC_MAX_DIGESTSIZE];
int plen, i, dgsize, wrsize;
char *ring, *off;
plen = 16 + 1 + 1 + 4 + (hdr->first_segment + 1) * 16;
if (plen >= SEG6_HMAC_RING_SIZE)
return -EMSGSIZE;
local_bh_disable();
ring = this_cpu_ptr(hmac_ring);
off = ring;
memcpy(off, saddr, 16);
off += 16;
*off++ = hdr->first_segment;
*off++ = hdr->flags;
memcpy(off, &hmackeyid, 4);
off += 4;
for (i = 0; i < hdr->first_segment + 1; i++) {
memcpy(off, hdr->segments + i, 16);
off += 16;
}
dgsize = __do_hmac(hinfo, ring, plen, tmp_out,
SEG6_HMAC_MAX_DIGESTSIZE);
local_bh_enable();
if (dgsize < 0)
return dgsize;
wrsize = SEG6_HMAC_FIELD_LEN;
if (wrsize > dgsize)
wrsize = dgsize;
memset(output, 0, SEG6_HMAC_FIELD_LEN);
memcpy(output, tmp_out, wrsize);
return 0;
}
bool seg6_hmac_validate_skb(struct sk_buff *skb)
{
u8 hmac_output[SEG6_HMAC_FIELD_LEN];
struct net *net = dev_net(skb->dev);
struct seg6_hmac_info *hinfo;
struct sr6_tlv_hmac *tlv;
struct ipv6_sr_hdr *srh;
struct inet6_dev *idev;
idev = __in6_dev_get(skb->dev);
srh = (struct ipv6_sr_hdr *)skb_transport_header(skb);
tlv = seg6_get_tlv_hmac(srh);
if (idev->cnf.seg6_require_hmac > 0 && !tlv)
return false;
if (idev->cnf.seg6_require_hmac < 0)
return true;
if (idev->cnf.seg6_require_hmac == 0 && !tlv)
return true;
hinfo = seg6_hmac_info_lookup(net, be32_to_cpu(tlv->hmackeyid));
if (!hinfo)
return false;
if (seg6_hmac_compute(hinfo, srh, &ipv6_hdr(skb)->saddr, hmac_output))
return false;
if (memcmp(hmac_output, tlv->hmac, SEG6_HMAC_FIELD_LEN) != 0)
return false;
return true;
}
struct seg6_hmac_info *seg6_hmac_info_lookup(struct net *net, u32 key)
{
struct seg6_pernet_data *sdata = seg6_pernet(net);
struct seg6_hmac_info *hinfo;
hinfo = rhashtable_lookup_fast(&sdata->hmac_infos, &key, rht_params);
return hinfo;
}
int seg6_hmac_info_add(struct net *net, u32 key, struct seg6_hmac_info *hinfo)
{
struct seg6_pernet_data *sdata = seg6_pernet(net);
int err;
err = rhashtable_lookup_insert_fast(&sdata->hmac_infos, &hinfo->node,
rht_params);
return err;
}
int seg6_hmac_info_del(struct net *net, u32 key)
{
struct seg6_pernet_data *sdata = seg6_pernet(net);
struct seg6_hmac_info *hinfo;
int err = -ENOENT;
hinfo = rhashtable_lookup_fast(&sdata->hmac_infos, &key, rht_params);
if (!hinfo)
goto out;
err = rhashtable_remove_fast(&sdata->hmac_infos, &hinfo->node,
rht_params);
if (err)
goto out;
seg6_hinfo_release(hinfo);
out:
return err;
}
int seg6_push_hmac(struct net *net, struct in6_addr *saddr,
struct ipv6_sr_hdr *srh)
{
struct seg6_hmac_info *hinfo;
struct sr6_tlv_hmac *tlv;
int err = -ENOENT;
tlv = seg6_get_tlv_hmac(srh);
if (!tlv)
return -EINVAL;
rcu_read_lock();
hinfo = seg6_hmac_info_lookup(net, be32_to_cpu(tlv->hmackeyid));
if (!hinfo)
goto out;
memset(tlv->hmac, 0, SEG6_HMAC_FIELD_LEN);
err = seg6_hmac_compute(hinfo, srh, saddr, tlv->hmac);
out:
rcu_read_unlock();
return err;
}
static int seg6_hmac_init_algo(void)
{
struct seg6_hmac_algo *algo;
struct crypto_shash *tfm;
struct shash_desc *shash;
int i, alg_count, cpu;
alg_count = sizeof(hmac_algos) / sizeof(struct seg6_hmac_algo);
for (i = 0; i < alg_count; i++) {
struct crypto_shash **p_tfm;
int shsize;
algo = &hmac_algos[i];
algo->tfms = alloc_percpu(struct crypto_shash *);
if (!algo->tfms)
return -ENOMEM;
for_each_possible_cpu(cpu) {
tfm = crypto_alloc_shash(algo->name, 0, GFP_KERNEL);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
p_tfm = per_cpu_ptr(algo->tfms, cpu);
*p_tfm = tfm;
}
p_tfm = raw_cpu_ptr(algo->tfms);
tfm = *p_tfm;
shsize = sizeof(*shash) + crypto_shash_descsize(tfm);
algo->shashs = alloc_percpu(struct shash_desc *);
if (!algo->shashs)
return -ENOMEM;
for_each_possible_cpu(cpu) {
shash = kzalloc_node(shsize, GFP_KERNEL,
cpu_to_node(cpu));
if (!shash)
return -ENOMEM;
*per_cpu_ptr(algo->shashs, cpu) = shash;
}
}
return 0;
}
int __init seg6_hmac_init(void)
{
return seg6_hmac_init_algo();
}
int __net_init seg6_hmac_net_init(struct net *net)
{
struct seg6_pernet_data *sdata = seg6_pernet(net);
rhashtable_init(&sdata->hmac_infos, &rht_params);
return 0;
}
void seg6_hmac_exit(void)
{
struct seg6_hmac_algo *algo = NULL;
int i, alg_count, cpu;
alg_count = sizeof(hmac_algos) / sizeof(struct seg6_hmac_algo);
for (i = 0; i < alg_count; i++) {
algo = &hmac_algos[i];
for_each_possible_cpu(cpu) {
struct crypto_shash *tfm;
struct shash_desc *shash;
shash = *per_cpu_ptr(algo->shashs, cpu);
kfree(shash);
tfm = *per_cpu_ptr(algo->tfms, cpu);
crypto_free_shash(tfm);
}
free_percpu(algo->tfms);
free_percpu(algo->shashs);
}
}
void __net_exit seg6_hmac_net_exit(struct net *net)
{
struct seg6_pernet_data *sdata = seg6_pernet(net);
rhashtable_free_and_destroy(&sdata->hmac_infos, seg6_free_hi, NULL);
}
