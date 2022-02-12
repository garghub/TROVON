static inline int aead_entries(void)
{
return ARRAY_SIZE(aead_list);
}
static inline int aalg_entries(void)
{
return ARRAY_SIZE(aalg_list);
}
static inline int ealg_entries(void)
{
return ARRAY_SIZE(ealg_list);
}
static inline int calg_entries(void)
{
return ARRAY_SIZE(calg_list);
}
static struct xfrm_algo_desc *xfrm_find_algo(
const struct xfrm_algo_list *algo_list,
int match(const struct xfrm_algo_desc *entry, const void *data),
const void *data, int probe)
{
struct xfrm_algo_desc *list = algo_list->algs;
int i, status;
for (i = 0; i < algo_list->entries; i++) {
if (!match(list + i, data))
continue;
if (list[i].available)
return &list[i];
if (!probe)
break;
status = crypto_has_alg(list[i].name, algo_list->type,
algo_list->mask);
if (!status)
break;
list[i].available = status;
return &list[i];
}
return NULL;
}
static int xfrm_alg_id_match(const struct xfrm_algo_desc *entry,
const void *data)
{
return entry->desc.sadb_alg_id == (unsigned long)data;
}
struct xfrm_algo_desc *xfrm_aalg_get_byid(int alg_id)
{
return xfrm_find_algo(&xfrm_aalg_list, xfrm_alg_id_match,
(void *)(unsigned long)alg_id, 1);
}
struct xfrm_algo_desc *xfrm_ealg_get_byid(int alg_id)
{
return xfrm_find_algo(&xfrm_ealg_list, xfrm_alg_id_match,
(void *)(unsigned long)alg_id, 1);
}
struct xfrm_algo_desc *xfrm_calg_get_byid(int alg_id)
{
return xfrm_find_algo(&xfrm_calg_list, xfrm_alg_id_match,
(void *)(unsigned long)alg_id, 1);
}
static int xfrm_alg_name_match(const struct xfrm_algo_desc *entry,
const void *data)
{
const char *name = data;
return name && (!strcmp(name, entry->name) ||
(entry->compat && !strcmp(name, entry->compat)));
}
struct xfrm_algo_desc *xfrm_aalg_get_byname(const char *name, int probe)
{
return xfrm_find_algo(&xfrm_aalg_list, xfrm_alg_name_match, name,
probe);
}
struct xfrm_algo_desc *xfrm_ealg_get_byname(const char *name, int probe)
{
return xfrm_find_algo(&xfrm_ealg_list, xfrm_alg_name_match, name,
probe);
}
struct xfrm_algo_desc *xfrm_calg_get_byname(const char *name, int probe)
{
return xfrm_find_algo(&xfrm_calg_list, xfrm_alg_name_match, name,
probe);
}
static int xfrm_aead_name_match(const struct xfrm_algo_desc *entry,
const void *data)
{
const struct xfrm_aead_name *aead = data;
const char *name = aead->name;
return aead->icvbits == entry->uinfo.aead.icv_truncbits && name &&
!strcmp(name, entry->name);
}
struct xfrm_algo_desc *xfrm_aead_get_byname(const char *name, int icv_len, int probe)
{
struct xfrm_aead_name data = {
.name = name,
.icvbits = icv_len,
};
return xfrm_find_algo(&xfrm_aead_list, xfrm_aead_name_match, &data,
probe);
}
struct xfrm_algo_desc *xfrm_aalg_get_byidx(unsigned int idx)
{
if (idx >= aalg_entries())
return NULL;
return &aalg_list[idx];
}
struct xfrm_algo_desc *xfrm_ealg_get_byidx(unsigned int idx)
{
if (idx >= ealg_entries())
return NULL;
return &ealg_list[idx];
}
void xfrm_probe_algs(void)
{
int i, status;
BUG_ON(in_softirq());
for (i = 0; i < aalg_entries(); i++) {
status = crypto_has_hash(aalg_list[i].name, 0,
CRYPTO_ALG_ASYNC);
if (aalg_list[i].available != status)
aalg_list[i].available = status;
}
for (i = 0; i < ealg_entries(); i++) {
status = crypto_has_ablkcipher(ealg_list[i].name, 0, 0);
if (ealg_list[i].available != status)
ealg_list[i].available = status;
}
for (i = 0; i < calg_entries(); i++) {
status = crypto_has_comp(calg_list[i].name, 0,
CRYPTO_ALG_ASYNC);
if (calg_list[i].available != status)
calg_list[i].available = status;
}
}
int xfrm_count_pfkey_auth_supported(void)
{
int i, n;
for (i = 0, n = 0; i < aalg_entries(); i++)
if (aalg_list[i].available && aalg_list[i].pfkey_supported)
n++;
return n;
}
int xfrm_count_pfkey_enc_supported(void)
{
int i, n;
for (i = 0, n = 0; i < ealg_entries(); i++)
if (ealg_list[i].available && ealg_list[i].pfkey_supported)
n++;
return n;
}
