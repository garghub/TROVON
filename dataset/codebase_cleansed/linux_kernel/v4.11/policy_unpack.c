static void audit_cb(struct audit_buffer *ab, void *va)
{
struct common_audit_data *sa = va;
if (aad(sa)->iface.ns) {
audit_log_format(ab, " ns=");
audit_log_untrustedstring(ab, aad(sa)->iface.ns);
}
if (aad(sa)->iface.name) {
audit_log_format(ab, " name=");
audit_log_untrustedstring(ab, aad(sa)->iface.name);
}
if (aad(sa)->iface.pos)
audit_log_format(ab, " offset=%ld", aad(sa)->iface.pos);
}
static int audit_iface(struct aa_profile *new, const char *ns_name,
const char *name, const char *info, struct aa_ext *e,
int error)
{
struct aa_profile *profile = __aa_current_profile();
DEFINE_AUDIT_DATA(sa, LSM_AUDIT_DATA_NONE, NULL);
if (e)
aad(&sa)->iface.pos = e->pos - e->start;
aad(&sa)->iface.ns = ns_name;
if (new)
aad(&sa)->iface.name = new->base.hname;
else
aad(&sa)->iface.name = name;
aad(&sa)->info = info;
aad(&sa)->error = error;
return aa_audit(AUDIT_APPARMOR_STATUS, profile, &sa, audit_cb);
}
void aa_loaddata_kref(struct kref *kref)
{
struct aa_loaddata *d = container_of(kref, struct aa_loaddata, count);
if (d) {
kzfree(d->hash);
kvfree(d);
}
}
static bool inbounds(struct aa_ext *e, size_t size)
{
return (size <= e->end - e->pos);
}
static size_t unpack_u16_chunk(struct aa_ext *e, char **chunk)
{
size_t size = 0;
if (!inbounds(e, sizeof(u16)))
return 0;
size = le16_to_cpu(get_unaligned((__le16 *) e->pos));
e->pos += sizeof(__le16);
if (!inbounds(e, size))
return 0;
*chunk = e->pos;
e->pos += size;
return size;
}
static bool unpack_X(struct aa_ext *e, enum aa_code code)
{
if (!inbounds(e, 1))
return 0;
if (*(u8 *) e->pos != code)
return 0;
e->pos++;
return 1;
}
static bool unpack_nameX(struct aa_ext *e, enum aa_code code, const char *name)
{
void *pos = e->pos;
if (unpack_X(e, AA_NAME)) {
char *tag = NULL;
size_t size = unpack_u16_chunk(e, &tag);
if (name && (!size || strcmp(name, tag)))
goto fail;
} else if (name) {
goto fail;
}
if (unpack_X(e, code))
return 1;
fail:
e->pos = pos;
return 0;
}
static bool unpack_u32(struct aa_ext *e, u32 *data, const char *name)
{
if (unpack_nameX(e, AA_U32, name)) {
if (!inbounds(e, sizeof(u32)))
return 0;
if (data)
*data = le32_to_cpu(get_unaligned((__le32 *) e->pos));
e->pos += sizeof(u32);
return 1;
}
return 0;
}
static bool unpack_u64(struct aa_ext *e, u64 *data, const char *name)
{
if (unpack_nameX(e, AA_U64, name)) {
if (!inbounds(e, sizeof(u64)))
return 0;
if (data)
*data = le64_to_cpu(get_unaligned((__le64 *) e->pos));
e->pos += sizeof(u64);
return 1;
}
return 0;
}
static size_t unpack_array(struct aa_ext *e, const char *name)
{
if (unpack_nameX(e, AA_ARRAY, name)) {
int size;
if (!inbounds(e, sizeof(u16)))
return 0;
size = (int)le16_to_cpu(get_unaligned((__le16 *) e->pos));
e->pos += sizeof(u16);
return size;
}
return 0;
}
static size_t unpack_blob(struct aa_ext *e, char **blob, const char *name)
{
if (unpack_nameX(e, AA_BLOB, name)) {
u32 size;
if (!inbounds(e, sizeof(u32)))
return 0;
size = le32_to_cpu(get_unaligned((__le32 *) e->pos));
e->pos += sizeof(u32);
if (inbounds(e, (size_t) size)) {
*blob = e->pos;
e->pos += size;
return size;
}
}
return 0;
}
static int unpack_str(struct aa_ext *e, const char **string, const char *name)
{
char *src_str;
size_t size = 0;
void *pos = e->pos;
*string = NULL;
if (unpack_nameX(e, AA_STRING, name)) {
size = unpack_u16_chunk(e, &src_str);
if (size) {
if (src_str[size - 1] != 0)
goto fail;
*string = src_str;
}
}
return size;
fail:
e->pos = pos;
return 0;
}
static int unpack_strdup(struct aa_ext *e, char **string, const char *name)
{
const char *tmp;
void *pos = e->pos;
int res = unpack_str(e, &tmp, name);
*string = NULL;
if (!res)
return 0;
*string = kmemdup(tmp, res, GFP_KERNEL);
if (!*string) {
e->pos = pos;
return 0;
}
return res;
}
static bool verify_accept(struct aa_dfa *dfa, int flags)
{
int i;
for (i = 0; i < dfa->tables[YYTD_ID_ACCEPT]->td_lolen; i++) {
int mode = ACCEPT_TABLE(dfa)[i];
if (mode & ~DFA_VALID_PERM_MASK)
return 0;
if (ACCEPT_TABLE2(dfa)[i] & ~DFA_VALID_PERM2_MASK)
return 0;
}
return 1;
}
static struct aa_dfa *unpack_dfa(struct aa_ext *e)
{
char *blob = NULL;
size_t size;
struct aa_dfa *dfa = NULL;
size = unpack_blob(e, &blob, "aadfa");
if (size) {
size_t sz = blob - (char *) e->start -
((e->pos - e->start) & 7);
size_t pad = ALIGN(sz, 8) - sz;
int flags = TO_ACCEPT1_FLAG(YYTD_DATA32) |
TO_ACCEPT2_FLAG(YYTD_DATA32) | DFA_FLAG_VERIFY_STATES;
dfa = aa_dfa_unpack(blob + pad, size - pad, flags);
if (IS_ERR(dfa))
return dfa;
if (!verify_accept(dfa, flags))
goto fail;
}
return dfa;
fail:
aa_put_dfa(dfa);
return ERR_PTR(-EPROTO);
}
static bool unpack_trans_table(struct aa_ext *e, struct aa_profile *profile)
{
void *pos = e->pos;
if (unpack_nameX(e, AA_STRUCT, "xtable")) {
int i, size;
size = unpack_array(e, NULL);
if (size > 16 - 4)
goto fail;
profile->file.trans.table = kzalloc(sizeof(char *) * size,
GFP_KERNEL);
if (!profile->file.trans.table)
goto fail;
profile->file.trans.size = size;
for (i = 0; i < size; i++) {
char *str;
int c, j, size2 = unpack_strdup(e, &str, NULL);
if (!size2)
goto fail;
profile->file.trans.table[i] = str;
if (isspace(*str))
goto fail;
for (c = j = 0; j < size2 - 2; j++) {
if (!str[j])
c++;
}
if (*str == ':') {
if (c != 1)
goto fail;
if (!str[1])
goto fail;
} else if (c)
goto fail;
}
if (!unpack_nameX(e, AA_ARRAYEND, NULL))
goto fail;
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
}
return 1;
fail:
aa_free_domain_entries(&profile->file.trans);
e->pos = pos;
return 0;
}
static bool unpack_rlimits(struct aa_ext *e, struct aa_profile *profile)
{
void *pos = e->pos;
if (unpack_nameX(e, AA_STRUCT, "rlimits")) {
int i, size;
u32 tmp = 0;
if (!unpack_u32(e, &tmp, NULL))
goto fail;
profile->rlimits.mask = tmp;
size = unpack_array(e, NULL);
if (size > RLIM_NLIMITS)
goto fail;
for (i = 0; i < size; i++) {
u64 tmp2 = 0;
int a = aa_map_resource(i);
if (!unpack_u64(e, &tmp2, NULL))
goto fail;
profile->rlimits.limits[a].rlim_max = tmp2;
}
if (!unpack_nameX(e, AA_ARRAYEND, NULL))
goto fail;
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
}
return 1;
fail:
e->pos = pos;
return 0;
}
static void *kvmemdup(const void *src, size_t len)
{
void *p = kvmalloc(len);
if (p)
memcpy(p, src, len);
return p;
}
static u32 strhash(const void *data, u32 len, u32 seed)
{
const char * const *key = data;
return jhash(*key, strlen(*key), seed);
}
static int datacmp(struct rhashtable_compare_arg *arg, const void *obj)
{
const struct aa_data *data = obj;
const char * const *key = arg->key;
return strcmp(data->key, *key);
}
static struct aa_profile *unpack_profile(struct aa_ext *e, char **ns_name)
{
struct aa_profile *profile = NULL;
const char *tmpname, *tmpns = NULL, *name = NULL;
size_t ns_len;
struct rhashtable_params params = { 0 };
char *key = NULL;
struct aa_data *data;
int i, error = -EPROTO;
kernel_cap_t tmpcap;
u32 tmp;
*ns_name = NULL;
if (!unpack_nameX(e, AA_STRUCT, "profile"))
goto fail;
if (!unpack_str(e, &name, NULL))
goto fail;
if (*name == '\0')
goto fail;
tmpname = aa_splitn_fqname(name, strlen(name), &tmpns, &ns_len);
if (tmpns) {
*ns_name = kstrndup(tmpns, ns_len, GFP_KERNEL);
if (!*ns_name)
goto fail;
name = tmpname;
}
profile = aa_alloc_profile(name, GFP_KERNEL);
if (!profile)
return ERR_PTR(-ENOMEM);
(void) unpack_str(e, &profile->rename, "rename");
(void) unpack_str(e, &profile->attach, "attach");
profile->xmatch = unpack_dfa(e);
if (IS_ERR(profile->xmatch)) {
error = PTR_ERR(profile->xmatch);
profile->xmatch = NULL;
goto fail;
}
if (profile->xmatch) {
if (!unpack_u32(e, &tmp, NULL))
goto fail;
profile->xmatch_len = tmp;
}
if (!unpack_nameX(e, AA_STRUCT, "flags"))
goto fail;
if (!unpack_u32(e, &tmp, NULL))
goto fail;
if (tmp & PACKED_FLAG_HAT)
profile->flags |= PFLAG_HAT;
if (!unpack_u32(e, &tmp, NULL))
goto fail;
if (tmp == PACKED_MODE_COMPLAIN || (e->version & FORCE_COMPLAIN_FLAG))
profile->mode = APPARMOR_COMPLAIN;
else if (tmp == PACKED_MODE_KILL)
profile->mode = APPARMOR_KILL;
else if (tmp == PACKED_MODE_UNCONFINED)
profile->mode = APPARMOR_UNCONFINED;
if (!unpack_u32(e, &tmp, NULL))
goto fail;
if (tmp)
profile->audit = AUDIT_ALL;
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
if (unpack_u32(e, &profile->path_flags, "path_flags"))
profile->path_flags |= profile->flags & PFLAG_MEDIATE_DELETED;
else
profile->path_flags = PFLAG_MEDIATE_DELETED;
if (!unpack_u32(e, &(profile->caps.allow.cap[0]), NULL))
goto fail;
if (!unpack_u32(e, &(profile->caps.audit.cap[0]), NULL))
goto fail;
if (!unpack_u32(e, &(profile->caps.quiet.cap[0]), NULL))
goto fail;
if (!unpack_u32(e, &tmpcap.cap[0], NULL))
goto fail;
if (unpack_nameX(e, AA_STRUCT, "caps64")) {
if (!unpack_u32(e, &(profile->caps.allow.cap[1]), NULL))
goto fail;
if (!unpack_u32(e, &(profile->caps.audit.cap[1]), NULL))
goto fail;
if (!unpack_u32(e, &(profile->caps.quiet.cap[1]), NULL))
goto fail;
if (!unpack_u32(e, &(tmpcap.cap[1]), NULL))
goto fail;
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
}
if (unpack_nameX(e, AA_STRUCT, "capsx")) {
if (!unpack_u32(e, &(profile->caps.extended.cap[0]), NULL))
goto fail;
if (!unpack_u32(e, &(profile->caps.extended.cap[1]), NULL))
goto fail;
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
}
if (!unpack_rlimits(e, profile))
goto fail;
if (unpack_nameX(e, AA_STRUCT, "policydb")) {
profile->policy.dfa = unpack_dfa(e);
if (IS_ERR(profile->policy.dfa)) {
error = PTR_ERR(profile->policy.dfa);
profile->policy.dfa = NULL;
goto fail;
} else if (!profile->policy.dfa) {
error = -EPROTO;
goto fail;
}
if (!unpack_u32(e, &profile->policy.start[0], "start"))
profile->policy.start[0] = DFA_START;
for (i = AA_CLASS_FILE; i <= AA_CLASS_LAST; i++) {
profile->policy.start[i] =
aa_dfa_next(profile->policy.dfa,
profile->policy.start[0],
i);
}
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
} else
profile->policy.dfa = aa_get_dfa(nulldfa);
profile->file.dfa = unpack_dfa(e);
if (IS_ERR(profile->file.dfa)) {
error = PTR_ERR(profile->file.dfa);
profile->file.dfa = NULL;
goto fail;
} else if (profile->file.dfa) {
if (!unpack_u32(e, &profile->file.start, "dfa_start"))
profile->file.start = DFA_START;
} else if (profile->policy.dfa &&
profile->policy.start[AA_CLASS_FILE]) {
profile->file.dfa = aa_get_dfa(profile->policy.dfa);
profile->file.start = profile->policy.start[AA_CLASS_FILE];
} else
profile->file.dfa = aa_get_dfa(nulldfa);
if (!unpack_trans_table(e, profile))
goto fail;
if (unpack_nameX(e, AA_STRUCT, "data")) {
profile->data = kzalloc(sizeof(*profile->data), GFP_KERNEL);
if (!profile->data)
goto fail;
params.nelem_hint = 3;
params.key_len = sizeof(void *);
params.key_offset = offsetof(struct aa_data, key);
params.head_offset = offsetof(struct aa_data, head);
params.hashfn = strhash;
params.obj_cmpfn = datacmp;
if (rhashtable_init(profile->data, &params))
goto fail;
while (unpack_strdup(e, &key, NULL)) {
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
kzfree(key);
goto fail;
}
data->key = key;
data->size = unpack_blob(e, &data->data, NULL);
data->data = kvmemdup(data->data, data->size);
if (data->size && !data->data) {
kzfree(data->key);
kzfree(data);
goto fail;
}
rhashtable_insert_fast(profile->data, &data->head,
profile->data->p);
}
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
}
if (!unpack_nameX(e, AA_STRUCTEND, NULL))
goto fail;
return profile;
fail:
if (profile)
name = NULL;
else if (!name)
name = "unknown";
audit_iface(profile, NULL, name, "failed to unpack profile", e,
error);
aa_free_profile(profile);
return ERR_PTR(error);
}
static int verify_header(struct aa_ext *e, int required, const char **ns)
{
int error = -EPROTONOSUPPORT;
const char *name = NULL;
*ns = NULL;
if (!unpack_u32(e, &e->version, "version")) {
if (required) {
audit_iface(NULL, NULL, NULL, "invalid profile format",
e, error);
return error;
}
}
if (VERSION_LT(e->version, v5) && VERSION_GT(e->version, v7)) {
audit_iface(NULL, NULL, NULL, "unsupported interface version",
e, error);
return error;
}
if (unpack_str(e, &name, "namespace")) {
if (*name == '\0') {
audit_iface(NULL, NULL, NULL, "invalid namespace name",
e, error);
return error;
}
if (*ns && strcmp(*ns, name))
audit_iface(NULL, NULL, NULL, "invalid ns change", e,
error);
else if (!*ns)
*ns = name;
}
return 0;
}
static bool verify_xindex(int xindex, int table_size)
{
int index, xtype;
xtype = xindex & AA_X_TYPE_MASK;
index = xindex & AA_X_INDEX_MASK;
if (xtype == AA_X_TABLE && index >= table_size)
return 0;
return 1;
}
static bool verify_dfa_xindex(struct aa_dfa *dfa, int table_size)
{
int i;
for (i = 0; i < dfa->tables[YYTD_ID_ACCEPT]->td_lolen; i++) {
if (!verify_xindex(dfa_user_xindex(dfa, i), table_size))
return 0;
if (!verify_xindex(dfa_other_xindex(dfa, i), table_size))
return 0;
}
return 1;
}
static int verify_profile(struct aa_profile *profile)
{
if (profile->file.dfa &&
!verify_dfa_xindex(profile->file.dfa,
profile->file.trans.size)) {
audit_iface(profile, NULL, NULL, "Invalid named transition",
NULL, -EPROTO);
return -EPROTO;
}
return 0;
}
void aa_load_ent_free(struct aa_load_ent *ent)
{
if (ent) {
aa_put_profile(ent->rename);
aa_put_profile(ent->old);
aa_put_profile(ent->new);
kfree(ent->ns_name);
kzfree(ent);
}
}
struct aa_load_ent *aa_load_ent_alloc(void)
{
struct aa_load_ent *ent = kzalloc(sizeof(*ent), GFP_KERNEL);
if (ent)
INIT_LIST_HEAD(&ent->list);
return ent;
}
int aa_unpack(struct aa_loaddata *udata, struct list_head *lh,
const char **ns)
{
struct aa_load_ent *tmp, *ent;
struct aa_profile *profile = NULL;
int error;
struct aa_ext e = {
.start = udata->data,
.end = udata->data + udata->size,
.pos = udata->data,
};
*ns = NULL;
while (e.pos < e.end) {
char *ns_name = NULL;
void *start;
error = verify_header(&e, e.pos == e.start, ns);
if (error)
goto fail;
start = e.pos;
profile = unpack_profile(&e, &ns_name);
if (IS_ERR(profile)) {
error = PTR_ERR(profile);
goto fail;
}
error = verify_profile(profile);
if (error)
goto fail_profile;
if (aa_g_hash_policy)
error = aa_calc_profile_hash(profile, e.version, start,
e.pos - start);
if (error)
goto fail_profile;
ent = aa_load_ent_alloc();
if (!ent) {
error = -ENOMEM;
goto fail_profile;
}
ent->new = profile;
ent->ns_name = ns_name;
list_add_tail(&ent->list, lh);
}
udata->abi = e.version & K_ABI_MASK;
if (aa_g_hash_policy) {
udata->hash = aa_calc_hash(udata->data, udata->size);
if (IS_ERR(udata->hash)) {
error = PTR_ERR(udata->hash);
udata->hash = NULL;
goto fail;
}
}
return 0;
fail_profile:
aa_put_profile(profile);
fail:
list_for_each_entry_safe(ent, tmp, lh, list) {
list_del_init(&ent->list);
aa_load_ent_free(ent);
}
return error;
}
