static void calipso_cache_entry_free(struct calipso_map_cache_entry *entry)
{
if (entry->lsm_data)
netlbl_secattr_cache_free(entry->lsm_data);
kfree(entry->key);
kfree(entry);
}
static u32 calipso_map_cache_hash(const unsigned char *key, u32 key_len)
{
return jhash(key, key_len, 0);
}
static int __init calipso_cache_init(void)
{
u32 iter;
calipso_cache = kcalloc(CALIPSO_CACHE_BUCKETS,
sizeof(struct calipso_map_cache_bkt),
GFP_KERNEL);
if (!calipso_cache)
return -ENOMEM;
for (iter = 0; iter < CALIPSO_CACHE_BUCKETS; iter++) {
spin_lock_init(&calipso_cache[iter].lock);
calipso_cache[iter].size = 0;
INIT_LIST_HEAD(&calipso_cache[iter].list);
}
return 0;
}
static void calipso_cache_invalidate(void)
{
struct calipso_map_cache_entry *entry, *tmp_entry;
u32 iter;
for (iter = 0; iter < CALIPSO_CACHE_BUCKETS; iter++) {
spin_lock_bh(&calipso_cache[iter].lock);
list_for_each_entry_safe(entry,
tmp_entry,
&calipso_cache[iter].list, list) {
list_del(&entry->list);
calipso_cache_entry_free(entry);
}
calipso_cache[iter].size = 0;
spin_unlock_bh(&calipso_cache[iter].lock);
}
}
static int calipso_cache_check(const unsigned char *key,
u32 key_len,
struct netlbl_lsm_secattr *secattr)
{
u32 bkt;
struct calipso_map_cache_entry *entry;
struct calipso_map_cache_entry *prev_entry = NULL;
u32 hash;
if (!calipso_cache_enabled)
return -ENOENT;
hash = calipso_map_cache_hash(key, key_len);
bkt = hash & (CALIPSO_CACHE_BUCKETS - 1);
spin_lock_bh(&calipso_cache[bkt].lock);
list_for_each_entry(entry, &calipso_cache[bkt].list, list) {
if (entry->hash == hash &&
entry->key_len == key_len &&
memcmp(entry->key, key, key_len) == 0) {
entry->activity += 1;
refcount_inc(&entry->lsm_data->refcount);
secattr->cache = entry->lsm_data;
secattr->flags |= NETLBL_SECATTR_CACHE;
secattr->type = NETLBL_NLTYPE_CALIPSO;
if (!prev_entry) {
spin_unlock_bh(&calipso_cache[bkt].lock);
return 0;
}
if (prev_entry->activity > 0)
prev_entry->activity -= 1;
if (entry->activity > prev_entry->activity &&
entry->activity - prev_entry->activity >
CALIPSO_CACHE_REORDERLIMIT) {
__list_del(entry->list.prev, entry->list.next);
__list_add(&entry->list,
prev_entry->list.prev,
&prev_entry->list);
}
spin_unlock_bh(&calipso_cache[bkt].lock);
return 0;
}
prev_entry = entry;
}
spin_unlock_bh(&calipso_cache[bkt].lock);
return -ENOENT;
}
static int calipso_cache_add(const unsigned char *calipso_ptr,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val = -EPERM;
u32 bkt;
struct calipso_map_cache_entry *entry = NULL;
struct calipso_map_cache_entry *old_entry = NULL;
u32 calipso_ptr_len;
if (!calipso_cache_enabled || calipso_cache_bucketsize <= 0)
return 0;
calipso_ptr_len = calipso_ptr[1];
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return -ENOMEM;
entry->key = kmemdup(calipso_ptr + 2, calipso_ptr_len, GFP_ATOMIC);
if (!entry->key) {
ret_val = -ENOMEM;
goto cache_add_failure;
}
entry->key_len = calipso_ptr_len;
entry->hash = calipso_map_cache_hash(calipso_ptr, calipso_ptr_len);
refcount_inc(&secattr->cache->refcount);
entry->lsm_data = secattr->cache;
bkt = entry->hash & (CALIPSO_CACHE_BUCKETS - 1);
spin_lock_bh(&calipso_cache[bkt].lock);
if (calipso_cache[bkt].size < calipso_cache_bucketsize) {
list_add(&entry->list, &calipso_cache[bkt].list);
calipso_cache[bkt].size += 1;
} else {
old_entry = list_entry(calipso_cache[bkt].list.prev,
struct calipso_map_cache_entry, list);
list_del(&old_entry->list);
list_add(&entry->list, &calipso_cache[bkt].list);
calipso_cache_entry_free(old_entry);
}
spin_unlock_bh(&calipso_cache[bkt].lock);
return 0;
cache_add_failure:
if (entry)
calipso_cache_entry_free(entry);
return ret_val;
}
static struct calipso_doi *calipso_doi_search(u32 doi)
{
struct calipso_doi *iter;
list_for_each_entry_rcu(iter, &calipso_doi_list, list)
if (iter->doi == doi && refcount_read(&iter->refcount))
return iter;
return NULL;
}
static int calipso_doi_add(struct calipso_doi *doi_def,
struct netlbl_audit *audit_info)
{
int ret_val = -EINVAL;
u32 doi;
u32 doi_type;
struct audit_buffer *audit_buf;
doi = doi_def->doi;
doi_type = doi_def->type;
if (doi_def->doi == CALIPSO_DOI_UNKNOWN)
goto doi_add_return;
refcount_set(&doi_def->refcount, 1);
spin_lock(&calipso_doi_list_lock);
if (calipso_doi_search(doi_def->doi)) {
spin_unlock(&calipso_doi_list_lock);
ret_val = -EEXIST;
goto doi_add_return;
}
list_add_tail_rcu(&doi_def->list, &calipso_doi_list);
spin_unlock(&calipso_doi_list_lock);
ret_val = 0;
doi_add_return:
audit_buf = netlbl_audit_start(AUDIT_MAC_CALIPSO_ADD, audit_info);
if (audit_buf) {
const char *type_str;
switch (doi_type) {
case CALIPSO_MAP_PASS:
type_str = "pass";
break;
default:
type_str = "(unknown)";
}
audit_log_format(audit_buf,
" calipso_doi=%u calipso_type=%s res=%u",
doi, type_str, ret_val == 0 ? 1 : 0);
audit_log_end(audit_buf);
}
return ret_val;
}
static void calipso_doi_free(struct calipso_doi *doi_def)
{
kfree(doi_def);
}
static void calipso_doi_free_rcu(struct rcu_head *entry)
{
struct calipso_doi *doi_def;
doi_def = container_of(entry, struct calipso_doi, rcu);
calipso_doi_free(doi_def);
}
static int calipso_doi_remove(u32 doi, struct netlbl_audit *audit_info)
{
int ret_val;
struct calipso_doi *doi_def;
struct audit_buffer *audit_buf;
spin_lock(&calipso_doi_list_lock);
doi_def = calipso_doi_search(doi);
if (!doi_def) {
spin_unlock(&calipso_doi_list_lock);
ret_val = -ENOENT;
goto doi_remove_return;
}
if (!refcount_dec_and_test(&doi_def->refcount)) {
spin_unlock(&calipso_doi_list_lock);
ret_val = -EBUSY;
goto doi_remove_return;
}
list_del_rcu(&doi_def->list);
spin_unlock(&calipso_doi_list_lock);
call_rcu(&doi_def->rcu, calipso_doi_free_rcu);
ret_val = 0;
doi_remove_return:
audit_buf = netlbl_audit_start(AUDIT_MAC_CALIPSO_DEL, audit_info);
if (audit_buf) {
audit_log_format(audit_buf,
" calipso_doi=%u res=%u",
doi, ret_val == 0 ? 1 : 0);
audit_log_end(audit_buf);
}
return ret_val;
}
static struct calipso_doi *calipso_doi_getdef(u32 doi)
{
struct calipso_doi *doi_def;
rcu_read_lock();
doi_def = calipso_doi_search(doi);
if (!doi_def)
goto doi_getdef_return;
if (!refcount_inc_not_zero(&doi_def->refcount))
doi_def = NULL;
doi_getdef_return:
rcu_read_unlock();
return doi_def;
}
static void calipso_doi_putdef(struct calipso_doi *doi_def)
{
if (!doi_def)
return;
if (!refcount_dec_and_test(&doi_def->refcount))
return;
spin_lock(&calipso_doi_list_lock);
list_del_rcu(&doi_def->list);
spin_unlock(&calipso_doi_list_lock);
call_rcu(&doi_def->rcu, calipso_doi_free_rcu);
}
static int calipso_doi_walk(u32 *skip_cnt,
int (*callback)(struct calipso_doi *doi_def,
void *arg),
void *cb_arg)
{
int ret_val = -ENOENT;
u32 doi_cnt = 0;
struct calipso_doi *iter_doi;
rcu_read_lock();
list_for_each_entry_rcu(iter_doi, &calipso_doi_list, list)
if (refcount_read(&iter_doi->refcount) > 0) {
if (doi_cnt++ < *skip_cnt)
continue;
ret_val = callback(iter_doi, cb_arg);
if (ret_val < 0) {
doi_cnt--;
goto doi_walk_return;
}
}
doi_walk_return:
rcu_read_unlock();
*skip_cnt = doi_cnt;
return ret_val;
}
bool calipso_validate(const struct sk_buff *skb, const unsigned char *option)
{
struct calipso_doi *doi_def;
bool ret_val;
u16 crc, len = option[1] + 2;
static const u8 zero[2];
crc = crc_ccitt(0xffff, option, 8);
crc = crc_ccitt(crc, zero, sizeof(zero));
if (len > 10)
crc = crc_ccitt(crc, option + 10, len - 10);
crc = ~crc;
if (option[8] != (crc & 0xff) || option[9] != ((crc >> 8) & 0xff))
return false;
rcu_read_lock();
doi_def = calipso_doi_search(get_unaligned_be32(option + 2));
ret_val = !!doi_def;
rcu_read_unlock();
return ret_val;
}
static int calipso_map_cat_hton(const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr,
unsigned char *net_cat,
u32 net_cat_len)
{
int spot = -1;
u32 net_spot_max = 0;
u32 net_clen_bits = net_cat_len * 8;
for (;;) {
spot = netlbl_catmap_walk(secattr->attr.mls.cat,
spot + 1);
if (spot < 0)
break;
if (spot >= net_clen_bits)
return -ENOSPC;
netlbl_bitmap_setbit(net_cat, spot, 1);
if (spot > net_spot_max)
net_spot_max = spot;
}
return (net_spot_max / 32 + 1) * 4;
}
static int calipso_map_cat_ntoh(const struct calipso_doi *doi_def,
const unsigned char *net_cat,
u32 net_cat_len,
struct netlbl_lsm_secattr *secattr)
{
int ret_val;
int spot = -1;
u32 net_clen_bits = net_cat_len * 8;
for (;;) {
spot = netlbl_bitmap_walk(net_cat,
net_clen_bits,
spot + 1,
1);
if (spot < 0) {
if (spot == -2)
return -EFAULT;
return 0;
}
ret_val = netlbl_catmap_setbit(&secattr->attr.mls.cat,
spot,
GFP_ATOMIC);
if (ret_val != 0)
return ret_val;
}
return -EINVAL;
}
static int calipso_pad_write(unsigned char *buf, unsigned int offset,
unsigned int count)
{
if (WARN_ON_ONCE(count >= 8))
return -EINVAL;
switch (count) {
case 0:
break;
case 1:
buf[offset] = IPV6_TLV_PAD1;
break;
default:
buf[offset] = IPV6_TLV_PADN;
buf[offset + 1] = count - 2;
if (count > 2)
memset(buf + offset + 2, 0, count - 2);
break;
}
return 0;
}
static int calipso_genopt(unsigned char *buf, u32 start, u32 buf_len,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
u32 len, pad;
u16 crc;
static const unsigned char padding[4] = {2, 1, 0, 3};
unsigned char *calipso;
pad = padding[start & 3];
if (buf_len <= start + pad + CALIPSO_HDR_LEN)
return -ENOSPC;
if ((secattr->flags & NETLBL_SECATTR_MLS_LVL) == 0)
return -EPERM;
len = CALIPSO_HDR_LEN;
if (secattr->flags & NETLBL_SECATTR_MLS_CAT) {
ret_val = calipso_map_cat_hton(doi_def,
secattr,
buf + start + pad + len,
buf_len - start - pad - len);
if (ret_val < 0)
return ret_val;
len += ret_val;
}
calipso_pad_write(buf, start, pad);
calipso = buf + start + pad;
calipso[0] = IPV6_TLV_CALIPSO;
calipso[1] = len - 2;
*(__be32 *)(calipso + 2) = htonl(doi_def->doi);
calipso[6] = (len - CALIPSO_HDR_LEN) / 4;
calipso[7] = secattr->attr.mls.lvl,
crc = ~crc_ccitt(0xffff, calipso, len);
calipso[8] = crc & 0xff;
calipso[9] = (crc >> 8) & 0xff;
return pad + len;
}
static int calipso_opt_update(struct sock *sk, struct ipv6_opt_hdr *hop)
{
struct ipv6_txoptions *old = txopt_get(inet6_sk(sk)), *txopts;
txopts = ipv6_renew_options_kern(sk, old, IPV6_HOPOPTS,
hop, hop ? ipv6_optlen(hop) : 0);
txopt_put(old);
if (IS_ERR(txopts))
return PTR_ERR(txopts);
txopts = ipv6_update_options(sk, txopts);
if (txopts) {
atomic_sub(txopts->tot_len, &sk->sk_omem_alloc);
txopt_put(txopts);
}
return 0;
}
static int calipso_tlv_len(struct ipv6_opt_hdr *opt, unsigned int offset)
{
unsigned char *tlv = (unsigned char *)opt;
unsigned int opt_len = ipv6_optlen(opt), tlv_len;
if (offset < sizeof(*opt) || offset >= opt_len)
return -EINVAL;
if (tlv[offset] == IPV6_TLV_PAD1)
return 1;
if (offset + 1 >= opt_len)
return -EINVAL;
tlv_len = tlv[offset + 1] + 2;
if (offset + tlv_len > opt_len)
return -EINVAL;
return tlv_len;
}
static int calipso_opt_find(struct ipv6_opt_hdr *hop, unsigned int *start,
unsigned int *end)
{
int ret_val = -ENOENT, tlv_len;
unsigned int opt_len, offset, offset_s = 0, offset_e = 0;
unsigned char *opt = (unsigned char *)hop;
opt_len = ipv6_optlen(hop);
offset = sizeof(*hop);
while (offset < opt_len) {
tlv_len = calipso_tlv_len(hop, offset);
if (tlv_len < 0)
return tlv_len;
switch (opt[offset]) {
case IPV6_TLV_PAD1:
case IPV6_TLV_PADN:
if (offset_e)
offset_e = offset;
break;
case IPV6_TLV_CALIPSO:
ret_val = 0;
offset_e = offset;
break;
default:
if (offset_e == 0)
offset_s = offset;
else
goto out;
}
offset += tlv_len;
}
out:
if (offset_s)
*start = offset_s + calipso_tlv_len(hop, offset_s);
else
*start = sizeof(*hop);
if (offset_e)
*end = offset_e + calipso_tlv_len(hop, offset_e);
else
*end = opt_len;
return ret_val;
}
static struct ipv6_opt_hdr *
calipso_opt_insert(struct ipv6_opt_hdr *hop,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
unsigned int start, end, buf_len, pad, hop_len;
struct ipv6_opt_hdr *new;
int ret_val;
if (hop) {
hop_len = ipv6_optlen(hop);
ret_val = calipso_opt_find(hop, &start, &end);
if (ret_val && ret_val != -ENOENT)
return ERR_PTR(ret_val);
} else {
hop_len = 0;
start = sizeof(*hop);
end = 0;
}
buf_len = hop_len + start - end + CALIPSO_OPT_LEN_MAX_WITH_PAD;
new = kzalloc(buf_len, GFP_ATOMIC);
if (!new)
return ERR_PTR(-ENOMEM);
if (start > sizeof(*hop))
memcpy(new, hop, start);
ret_val = calipso_genopt((unsigned char *)new, start, buf_len, doi_def,
secattr);
if (ret_val < 0) {
kfree(new);
return ERR_PTR(ret_val);
}
buf_len = start + ret_val;
pad = ((buf_len & 4) + (end & 7)) & 7;
calipso_pad_write((unsigned char *)new, buf_len, pad);
buf_len += pad;
if (end != hop_len) {
memcpy((char *)new + buf_len, (char *)hop + end, hop_len - end);
buf_len += hop_len - end;
}
new->nexthdr = 0;
new->hdrlen = buf_len / 8 - 1;
return new;
}
static int calipso_opt_del(struct ipv6_opt_hdr *hop,
struct ipv6_opt_hdr **new)
{
int ret_val;
unsigned int start, end, delta, pad, hop_len;
ret_val = calipso_opt_find(hop, &start, &end);
if (ret_val)
return ret_val;
hop_len = ipv6_optlen(hop);
if (start == sizeof(*hop) && end == hop_len) {
*new = NULL;
return 0;
}
delta = (end - start) & ~7;
*new = kzalloc(hop_len - delta, GFP_ATOMIC);
if (!*new)
return -ENOMEM;
memcpy(*new, hop, start);
(*new)->hdrlen -= delta / 8;
pad = (end - start) & 7;
calipso_pad_write((unsigned char *)*new, start, pad);
if (end != hop_len)
memcpy((char *)*new + start + pad, (char *)hop + end,
hop_len - end);
return 0;
}
static int calipso_opt_getattr(const unsigned char *calipso,
struct netlbl_lsm_secattr *secattr)
{
int ret_val = -ENOMSG;
u32 doi, len = calipso[1], cat_len = calipso[6] * 4;
struct calipso_doi *doi_def;
if (cat_len + 8 > len)
return -EINVAL;
if (calipso_cache_check(calipso + 2, calipso[1], secattr) == 0)
return 0;
doi = get_unaligned_be32(calipso + 2);
rcu_read_lock();
doi_def = calipso_doi_search(doi);
if (!doi_def)
goto getattr_return;
secattr->attr.mls.lvl = calipso[7];
secattr->flags |= NETLBL_SECATTR_MLS_LVL;
if (cat_len) {
ret_val = calipso_map_cat_ntoh(doi_def,
calipso + 10,
cat_len,
secattr);
if (ret_val != 0) {
netlbl_catmap_free(secattr->attr.mls.cat);
goto getattr_return;
}
secattr->flags |= NETLBL_SECATTR_MLS_CAT;
}
secattr->type = NETLBL_NLTYPE_CALIPSO;
getattr_return:
rcu_read_unlock();
return ret_val;
}
static int calipso_sock_getattr(struct sock *sk,
struct netlbl_lsm_secattr *secattr)
{
struct ipv6_opt_hdr *hop;
int opt_len, len, ret_val = -ENOMSG, offset;
unsigned char *opt;
struct ipv6_txoptions *txopts = txopt_get(inet6_sk(sk));
if (!txopts || !txopts->hopopt)
goto done;
hop = txopts->hopopt;
opt = (unsigned char *)hop;
opt_len = ipv6_optlen(hop);
offset = sizeof(*hop);
while (offset < opt_len) {
len = calipso_tlv_len(hop, offset);
if (len < 0) {
ret_val = len;
goto done;
}
switch (opt[offset]) {
case IPV6_TLV_CALIPSO:
if (len < CALIPSO_HDR_LEN)
ret_val = -EINVAL;
else
ret_val = calipso_opt_getattr(&opt[offset],
secattr);
goto done;
default:
offset += len;
break;
}
}
done:
txopt_put(txopts);
return ret_val;
}
static int calipso_sock_setattr(struct sock *sk,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
struct ipv6_opt_hdr *old, *new;
struct ipv6_txoptions *txopts = txopt_get(inet6_sk(sk));
old = NULL;
if (txopts)
old = txopts->hopopt;
new = calipso_opt_insert(old, doi_def, secattr);
txopt_put(txopts);
if (IS_ERR(new))
return PTR_ERR(new);
ret_val = calipso_opt_update(sk, new);
kfree(new);
return ret_val;
}
static void calipso_sock_delattr(struct sock *sk)
{
struct ipv6_opt_hdr *new_hop;
struct ipv6_txoptions *txopts = txopt_get(inet6_sk(sk));
if (!txopts || !txopts->hopopt)
goto done;
if (calipso_opt_del(txopts->hopopt, &new_hop))
goto done;
calipso_opt_update(sk, new_hop);
kfree(new_hop);
done:
txopt_put(txopts);
}
static int calipso_req_setattr(struct request_sock *req,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
struct ipv6_txoptions *txopts;
struct inet_request_sock *req_inet = inet_rsk(req);
struct ipv6_opt_hdr *old, *new;
struct sock *sk = sk_to_full_sk(req_to_sk(req));
if (req_inet->ipv6_opt && req_inet->ipv6_opt->hopopt)
old = req_inet->ipv6_opt->hopopt;
else
old = NULL;
new = calipso_opt_insert(old, doi_def, secattr);
if (IS_ERR(new))
return PTR_ERR(new);
txopts = ipv6_renew_options_kern(sk, req_inet->ipv6_opt, IPV6_HOPOPTS,
new, new ? ipv6_optlen(new) : 0);
kfree(new);
if (IS_ERR(txopts))
return PTR_ERR(txopts);
txopts = xchg(&req_inet->ipv6_opt, txopts);
if (txopts) {
atomic_sub(txopts->tot_len, &sk->sk_omem_alloc);
txopt_put(txopts);
}
return 0;
}
static void calipso_req_delattr(struct request_sock *req)
{
struct inet_request_sock *req_inet = inet_rsk(req);
struct ipv6_opt_hdr *new;
struct ipv6_txoptions *txopts;
struct sock *sk = sk_to_full_sk(req_to_sk(req));
if (!req_inet->ipv6_opt || !req_inet->ipv6_opt->hopopt)
return;
if (calipso_opt_del(req_inet->ipv6_opt->hopopt, &new))
return;
txopts = ipv6_renew_options_kern(sk, req_inet->ipv6_opt, IPV6_HOPOPTS,
new, new ? ipv6_optlen(new) : 0);
if (!IS_ERR(txopts)) {
txopts = xchg(&req_inet->ipv6_opt, txopts);
if (txopts) {
atomic_sub(txopts->tot_len, &sk->sk_omem_alloc);
txopt_put(txopts);
}
}
kfree(new);
}
static unsigned char *calipso_skbuff_optptr(const struct sk_buff *skb)
{
const struct ipv6hdr *ip6_hdr = ipv6_hdr(skb);
int offset;
if (ip6_hdr->nexthdr != NEXTHDR_HOP)
return NULL;
offset = ipv6_find_tlv(skb, sizeof(*ip6_hdr), IPV6_TLV_CALIPSO);
if (offset >= 0)
return (unsigned char *)ip6_hdr + offset;
return NULL;
}
static int calipso_skbuff_setattr(struct sk_buff *skb,
const struct calipso_doi *doi_def,
const struct netlbl_lsm_secattr *secattr)
{
int ret_val;
struct ipv6hdr *ip6_hdr;
struct ipv6_opt_hdr *hop;
unsigned char buf[CALIPSO_MAX_BUFFER];
int len_delta, new_end, pad, payload;
unsigned int start, end;
ip6_hdr = ipv6_hdr(skb);
if (ip6_hdr->nexthdr == NEXTHDR_HOP) {
hop = (struct ipv6_opt_hdr *)(ip6_hdr + 1);
ret_val = calipso_opt_find(hop, &start, &end);
if (ret_val && ret_val != -ENOENT)
return ret_val;
} else {
start = 0;
end = 0;
}
memset(buf, 0, sizeof(buf));
ret_val = calipso_genopt(buf, start & 3, sizeof(buf), doi_def, secattr);
if (ret_val < 0)
return ret_val;
new_end = start + ret_val;
pad = ((new_end & 4) + (end & 7)) & 7;
len_delta = new_end - (int)end + pad;
ret_val = skb_cow(skb, skb_headroom(skb) + len_delta);
if (ret_val < 0)
return ret_val;
ip6_hdr = ipv6_hdr(skb);
if (len_delta) {
if (len_delta > 0)
skb_push(skb, len_delta);
else
skb_pull(skb, -len_delta);
memmove((char *)ip6_hdr - len_delta, ip6_hdr,
sizeof(*ip6_hdr) + start);
skb_reset_network_header(skb);
ip6_hdr = ipv6_hdr(skb);
payload = ntohs(ip6_hdr->payload_len);
ip6_hdr->payload_len = htons(payload + len_delta);
}
hop = (struct ipv6_opt_hdr *)(ip6_hdr + 1);
if (start == 0) {
struct ipv6_opt_hdr *new_hop = (struct ipv6_opt_hdr *)buf;
new_hop->nexthdr = ip6_hdr->nexthdr;
new_hop->hdrlen = len_delta / 8 - 1;
ip6_hdr->nexthdr = NEXTHDR_HOP;
} else {
hop->hdrlen += len_delta / 8;
}
memcpy((char *)hop + start, buf + (start & 3), new_end - start);
calipso_pad_write((unsigned char *)hop, new_end, pad);
return 0;
}
static int calipso_skbuff_delattr(struct sk_buff *skb)
{
int ret_val;
struct ipv6hdr *ip6_hdr;
struct ipv6_opt_hdr *old_hop;
u32 old_hop_len, start = 0, end = 0, delta, size, pad;
if (!calipso_skbuff_optptr(skb))
return 0;
ret_val = skb_cow(skb, skb_headroom(skb));
if (ret_val < 0)
return ret_val;
ip6_hdr = ipv6_hdr(skb);
old_hop = (struct ipv6_opt_hdr *)(ip6_hdr + 1);
old_hop_len = ipv6_optlen(old_hop);
ret_val = calipso_opt_find(old_hop, &start, &end);
if (ret_val)
return ret_val;
if (start == sizeof(*old_hop) && end == old_hop_len) {
delta = old_hop_len;
size = sizeof(*ip6_hdr);
ip6_hdr->nexthdr = old_hop->nexthdr;
} else {
delta = (end - start) & ~7;
if (delta)
old_hop->hdrlen -= delta / 8;
pad = (end - start) & 7;
size = sizeof(*ip6_hdr) + start + pad;
calipso_pad_write((unsigned char *)old_hop, start, pad);
}
if (delta) {
skb_pull(skb, delta);
memmove((char *)ip6_hdr + delta, ip6_hdr, size);
skb_reset_network_header(skb);
}
return 0;
}
int __init calipso_init(void)
{
int ret_val;
ret_val = calipso_cache_init();
if (!ret_val)
netlbl_calipso_ops_register(&ops);
return ret_val;
}
void calipso_exit(void)
{
netlbl_calipso_ops_register(NULL);
calipso_cache_invalidate();
kfree(calipso_cache);
}
