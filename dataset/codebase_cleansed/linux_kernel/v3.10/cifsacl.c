static int
cifs_idmap_key_instantiate(struct key *key, struct key_preparsed_payload *prep)
{
char *payload;
if (prep->datalen <= sizeof(key->payload)) {
key->payload.value = 0;
memcpy(&key->payload.value, prep->data, prep->datalen);
key->datalen = prep->datalen;
return 0;
}
payload = kmemdup(prep->data, prep->datalen, GFP_KERNEL);
if (!payload)
return -ENOMEM;
key->payload.data = payload;
key->datalen = prep->datalen;
return 0;
}
static inline void
cifs_idmap_key_destroy(struct key *key)
{
if (key->datalen > sizeof(key->payload))
kfree(key->payload.data);
}
static char *
sid_to_key_str(struct cifs_sid *sidptr, unsigned int type)
{
int i, len;
unsigned int saval;
char *sidstr, *strptr;
unsigned long long id_auth_val;
sidstr = kmalloc(3 + SID_STRING_BASE_SIZE +
(SID_STRING_SUBAUTH_SIZE * sidptr->num_subauth),
GFP_KERNEL);
if (!sidstr)
return sidstr;
strptr = sidstr;
len = sprintf(strptr, "%cs:S-%hhu", type == SIDOWNER ? 'o' : 'g',
sidptr->revision);
strptr += len;
id_auth_val = (unsigned long long)sidptr->authority[5];
id_auth_val |= (unsigned long long)sidptr->authority[4] << 8;
id_auth_val |= (unsigned long long)sidptr->authority[3] << 16;
id_auth_val |= (unsigned long long)sidptr->authority[2] << 24;
id_auth_val |= (unsigned long long)sidptr->authority[1] << 32;
id_auth_val |= (unsigned long long)sidptr->authority[0] << 48;
if (id_auth_val <= UINT_MAX)
len = sprintf(strptr, "-%llu", id_auth_val);
else
len = sprintf(strptr, "-0x%llx", id_auth_val);
strptr += len;
for (i = 0; i < sidptr->num_subauth; ++i) {
saval = le32_to_cpu(sidptr->sub_auth[i]);
len = sprintf(strptr, "-%u", saval);
strptr += len;
}
return sidstr;
}
static int
compare_sids(const struct cifs_sid *ctsid, const struct cifs_sid *cwsid)
{
int i;
int num_subauth, num_sat, num_saw;
if ((!ctsid) || (!cwsid))
return 1;
if (ctsid->revision != cwsid->revision) {
if (ctsid->revision > cwsid->revision)
return 1;
else
return -1;
}
for (i = 0; i < NUM_AUTHS; ++i) {
if (ctsid->authority[i] != cwsid->authority[i]) {
if (ctsid->authority[i] > cwsid->authority[i])
return 1;
else
return -1;
}
}
num_sat = ctsid->num_subauth;
num_saw = cwsid->num_subauth;
num_subauth = num_sat < num_saw ? num_sat : num_saw;
if (num_subauth) {
for (i = 0; i < num_subauth; ++i) {
if (ctsid->sub_auth[i] != cwsid->sub_auth[i]) {
if (le32_to_cpu(ctsid->sub_auth[i]) >
le32_to_cpu(cwsid->sub_auth[i]))
return 1;
else
return -1;
}
}
}
return 0;
}
static void
cifs_copy_sid(struct cifs_sid *dst, const struct cifs_sid *src)
{
int i;
dst->revision = src->revision;
dst->num_subauth = min_t(u8, src->num_subauth, SID_MAX_SUB_AUTHORITIES);
for (i = 0; i < NUM_AUTHS; ++i)
dst->authority[i] = src->authority[i];
for (i = 0; i < dst->num_subauth; ++i)
dst->sub_auth[i] = src->sub_auth[i];
}
static int
id_to_sid(unsigned int cid, uint sidtype, struct cifs_sid *ssid)
{
int rc;
struct key *sidkey;
struct cifs_sid *ksid;
unsigned int ksid_size;
char desc[3 + 10 + 1];
const struct cred *saved_cred;
rc = snprintf(desc, sizeof(desc), "%ci:%u",
sidtype == SIDOWNER ? 'o' : 'g', cid);
if (rc >= sizeof(desc))
return -EINVAL;
rc = 0;
saved_cred = override_creds(root_cred);
sidkey = request_key(&cifs_idmap_key_type, desc, "");
if (IS_ERR(sidkey)) {
rc = -EINVAL;
cifs_dbg(FYI, "%s: Can't map %cid %u to a SID\n",
__func__, sidtype == SIDOWNER ? 'u' : 'g', cid);
goto out_revert_creds;
} else if (sidkey->datalen < CIFS_SID_BASE_SIZE) {
rc = -EIO;
cifs_dbg(FYI, "%s: Downcall contained malformed key (datalen=%hu)\n",
__func__, sidkey->datalen);
goto invalidate_key;
}
ksid = sidkey->datalen <= sizeof(sidkey->payload) ?
(struct cifs_sid *)&sidkey->payload.value :
(struct cifs_sid *)sidkey->payload.data;
ksid_size = CIFS_SID_BASE_SIZE + (ksid->num_subauth * sizeof(__le32));
if (ksid_size > sidkey->datalen) {
rc = -EIO;
cifs_dbg(FYI, "%s: Downcall contained malformed key (datalen=%hu, ksid_size=%u)\n",
__func__, sidkey->datalen, ksid_size);
goto invalidate_key;
}
cifs_copy_sid(ssid, ksid);
out_key_put:
key_put(sidkey);
out_revert_creds:
revert_creds(saved_cred);
return rc;
invalidate_key:
key_invalidate(sidkey);
goto out_key_put;
}
static int
sid_to_id(struct cifs_sb_info *cifs_sb, struct cifs_sid *psid,
struct cifs_fattr *fattr, uint sidtype)
{
int rc;
struct key *sidkey;
char *sidstr;
const struct cred *saved_cred;
kuid_t fuid = cifs_sb->mnt_uid;
kgid_t fgid = cifs_sb->mnt_gid;
if (unlikely(psid->num_subauth > SID_MAX_SUB_AUTHORITIES)) {
cifs_dbg(FYI, "%s: %u subauthorities is too many!\n",
__func__, psid->num_subauth);
return -EIO;
}
sidstr = sid_to_key_str(psid, sidtype);
if (!sidstr)
return -ENOMEM;
saved_cred = override_creds(root_cred);
sidkey = request_key(&cifs_idmap_key_type, sidstr, "");
if (IS_ERR(sidkey)) {
rc = -EINVAL;
cifs_dbg(FYI, "%s: Can't map SID %s to a %cid\n",
__func__, sidstr, sidtype == SIDOWNER ? 'u' : 'g');
goto out_revert_creds;
}
BUILD_BUG_ON(sizeof(uid_t) != sizeof(gid_t));
if (sidkey->datalen != sizeof(uid_t)) {
rc = -EIO;
cifs_dbg(FYI, "%s: Downcall contained malformed key (datalen=%hu)\n",
__func__, sidkey->datalen);
key_invalidate(sidkey);
goto out_key_put;
}
if (sidtype == SIDOWNER) {
kuid_t uid;
uid_t id;
memcpy(&id, &sidkey->payload.value, sizeof(uid_t));
uid = make_kuid(&init_user_ns, id);
if (uid_valid(uid))
fuid = uid;
} else {
kgid_t gid;
gid_t id;
memcpy(&id, &sidkey->payload.value, sizeof(gid_t));
gid = make_kgid(&init_user_ns, id);
if (gid_valid(gid))
fgid = gid;
}
out_key_put:
key_put(sidkey);
out_revert_creds:
revert_creds(saved_cred);
kfree(sidstr);
if (sidtype == SIDOWNER)
fattr->cf_uid = fuid;
else
fattr->cf_gid = fgid;
return 0;
}
int
init_cifs_idmap(void)
{
struct cred *cred;
struct key *keyring;
int ret;
cifs_dbg(FYI, "Registering the %s key type\n",
cifs_idmap_key_type.name);
cred = prepare_kernel_cred(NULL);
if (!cred)
return -ENOMEM;
keyring = keyring_alloc(".cifs_idmap",
GLOBAL_ROOT_UID, GLOBAL_ROOT_GID, cred,
(KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ,
KEY_ALLOC_NOT_IN_QUOTA, NULL);
if (IS_ERR(keyring)) {
ret = PTR_ERR(keyring);
goto failed_put_cred;
}
ret = register_key_type(&cifs_idmap_key_type);
if (ret < 0)
goto failed_put_key;
set_bit(KEY_FLAG_ROOT_CAN_CLEAR, &keyring->flags);
cred->thread_keyring = keyring;
cred->jit_keyring = KEY_REQKEY_DEFL_THREAD_KEYRING;
root_cred = cred;
cifs_dbg(FYI, "cifs idmap keyring: %d\n", key_serial(keyring));
return 0;
failed_put_key:
key_put(keyring);
failed_put_cred:
put_cred(cred);
return ret;
}
void
exit_cifs_idmap(void)
{
key_revoke(root_cred->thread_keyring);
unregister_key_type(&cifs_idmap_key_type);
put_cred(root_cred);
cifs_dbg(FYI, "Unregistered %s key type\n", cifs_idmap_key_type.name);
}
static void copy_sec_desc(const struct cifs_ntsd *pntsd,
struct cifs_ntsd *pnntsd, __u32 sidsoffset)
{
struct cifs_sid *owner_sid_ptr, *group_sid_ptr;
struct cifs_sid *nowner_sid_ptr, *ngroup_sid_ptr;
pnntsd->revision = pntsd->revision;
pnntsd->type = pntsd->type;
pnntsd->dacloffset = cpu_to_le32(sizeof(struct cifs_ntsd));
pnntsd->sacloffset = 0;
pnntsd->osidoffset = cpu_to_le32(sidsoffset);
pnntsd->gsidoffset = cpu_to_le32(sidsoffset + sizeof(struct cifs_sid));
owner_sid_ptr = (struct cifs_sid *)((char *)pntsd +
le32_to_cpu(pntsd->osidoffset));
nowner_sid_ptr = (struct cifs_sid *)((char *)pnntsd + sidsoffset);
cifs_copy_sid(nowner_sid_ptr, owner_sid_ptr);
group_sid_ptr = (struct cifs_sid *)((char *)pntsd +
le32_to_cpu(pntsd->gsidoffset));
ngroup_sid_ptr = (struct cifs_sid *)((char *)pnntsd + sidsoffset +
sizeof(struct cifs_sid));
cifs_copy_sid(ngroup_sid_ptr, group_sid_ptr);
return;
}
static void access_flags_to_mode(__le32 ace_flags, int type, umode_t *pmode,
umode_t *pbits_to_set)
{
__u32 flags = le32_to_cpu(ace_flags);
if (type == ACCESS_DENIED) {
if (flags & GENERIC_ALL)
*pbits_to_set &= ~S_IRWXUGO;
if ((flags & GENERIC_WRITE) ||
((flags & FILE_WRITE_RIGHTS) == FILE_WRITE_RIGHTS))
*pbits_to_set &= ~S_IWUGO;
if ((flags & GENERIC_READ) ||
((flags & FILE_READ_RIGHTS) == FILE_READ_RIGHTS))
*pbits_to_set &= ~S_IRUGO;
if ((flags & GENERIC_EXECUTE) ||
((flags & FILE_EXEC_RIGHTS) == FILE_EXEC_RIGHTS))
*pbits_to_set &= ~S_IXUGO;
return;
} else if (type != ACCESS_ALLOWED) {
cifs_dbg(VFS, "unknown access control type %d\n", type);
return;
}
if (flags & GENERIC_ALL) {
*pmode |= (S_IRWXUGO & (*pbits_to_set));
cifs_dbg(NOISY, "all perms\n");
return;
}
if ((flags & GENERIC_WRITE) ||
((flags & FILE_WRITE_RIGHTS) == FILE_WRITE_RIGHTS))
*pmode |= (S_IWUGO & (*pbits_to_set));
if ((flags & GENERIC_READ) ||
((flags & FILE_READ_RIGHTS) == FILE_READ_RIGHTS))
*pmode |= (S_IRUGO & (*pbits_to_set));
if ((flags & GENERIC_EXECUTE) ||
((flags & FILE_EXEC_RIGHTS) == FILE_EXEC_RIGHTS))
*pmode |= (S_IXUGO & (*pbits_to_set));
cifs_dbg(NOISY, "access flags 0x%x mode now 0x%x\n", flags, *pmode);
return;
}
static void mode_to_access_flags(umode_t mode, umode_t bits_to_use,
__u32 *pace_flags)
{
*pace_flags = 0x0;
mode &= bits_to_use;
if (mode & S_IRUGO)
*pace_flags |= SET_FILE_READ_RIGHTS;
if (mode & S_IWUGO)
*pace_flags |= SET_FILE_WRITE_RIGHTS;
if (mode & S_IXUGO)
*pace_flags |= SET_FILE_EXEC_RIGHTS;
cifs_dbg(NOISY, "mode: 0x%x, access flags now 0x%x\n",
mode, *pace_flags);
return;
}
static __u16 fill_ace_for_sid(struct cifs_ace *pntace,
const struct cifs_sid *psid, __u64 nmode, umode_t bits)
{
int i;
__u16 size = 0;
__u32 access_req = 0;
pntace->type = ACCESS_ALLOWED;
pntace->flags = 0x0;
mode_to_access_flags(nmode, bits, &access_req);
if (!access_req)
access_req = SET_MINIMUM_RIGHTS;
pntace->access_req = cpu_to_le32(access_req);
pntace->sid.revision = psid->revision;
pntace->sid.num_subauth = psid->num_subauth;
for (i = 0; i < NUM_AUTHS; i++)
pntace->sid.authority[i] = psid->authority[i];
for (i = 0; i < psid->num_subauth; i++)
pntace->sid.sub_auth[i] = psid->sub_auth[i];
size = 1 + 1 + 2 + 4 + 1 + 1 + 6 + (psid->num_subauth * 4);
pntace->size = cpu_to_le16(size);
return size;
}
static void dump_ace(struct cifs_ace *pace, char *end_of_acl)
{
int num_subauth;
if (le16_to_cpu(pace->size) < 16) {
cifs_dbg(VFS, "ACE too small %d\n", le16_to_cpu(pace->size));
return;
}
if (end_of_acl < (char *)pace + le16_to_cpu(pace->size)) {
cifs_dbg(VFS, "ACL too small to parse ACE\n");
return;
}
num_subauth = pace->sid.num_subauth;
if (num_subauth) {
int i;
cifs_dbg(FYI, "ACE revision %d num_auth %d type %d flags %d size %d\n",
pace->sid.revision, pace->sid.num_subauth, pace->type,
pace->flags, le16_to_cpu(pace->size));
for (i = 0; i < num_subauth; ++i) {
cifs_dbg(FYI, "ACE sub_auth[%d]: 0x%x\n",
i, le32_to_cpu(pace->sid.sub_auth[i]));
}
}
return;
}
static void parse_dacl(struct cifs_acl *pdacl, char *end_of_acl,
struct cifs_sid *pownersid, struct cifs_sid *pgrpsid,
struct cifs_fattr *fattr)
{
int i;
int num_aces = 0;
int acl_size;
char *acl_base;
struct cifs_ace **ppace;
if (!pdacl) {
fattr->cf_mode |= S_IRWXUGO;
return;
}
if (end_of_acl < (char *)pdacl + le16_to_cpu(pdacl->size)) {
cifs_dbg(VFS, "ACL too small to parse DACL\n");
return;
}
cifs_dbg(NOISY, "DACL revision %d size %d num aces %d\n",
le16_to_cpu(pdacl->revision), le16_to_cpu(pdacl->size),
le32_to_cpu(pdacl->num_aces));
fattr->cf_mode &= ~(S_IRWXUGO);
acl_base = (char *)pdacl;
acl_size = sizeof(struct cifs_acl);
num_aces = le32_to_cpu(pdacl->num_aces);
if (num_aces > 0) {
umode_t user_mask = S_IRWXU;
umode_t group_mask = S_IRWXG;
umode_t other_mask = S_IRWXU | S_IRWXG | S_IRWXO;
if (num_aces > ULONG_MAX / sizeof(struct cifs_ace *))
return;
ppace = kmalloc(num_aces * sizeof(struct cifs_ace *),
GFP_KERNEL);
if (!ppace)
return;
for (i = 0; i < num_aces; ++i) {
ppace[i] = (struct cifs_ace *) (acl_base + acl_size);
#ifdef CONFIG_CIFS_DEBUG2
dump_ace(ppace[i], end_of_acl);
#endif
if (compare_sids(&(ppace[i]->sid), pownersid) == 0)
access_flags_to_mode(ppace[i]->access_req,
ppace[i]->type,
&fattr->cf_mode,
&user_mask);
if (compare_sids(&(ppace[i]->sid), pgrpsid) == 0)
access_flags_to_mode(ppace[i]->access_req,
ppace[i]->type,
&fattr->cf_mode,
&group_mask);
if (compare_sids(&(ppace[i]->sid), &sid_everyone) == 0)
access_flags_to_mode(ppace[i]->access_req,
ppace[i]->type,
&fattr->cf_mode,
&other_mask);
if (compare_sids(&(ppace[i]->sid), &sid_authusers) == 0)
access_flags_to_mode(ppace[i]->access_req,
ppace[i]->type,
&fattr->cf_mode,
&other_mask);
acl_base = (char *)ppace[i];
acl_size = le16_to_cpu(ppace[i]->size);
}
kfree(ppace);
}
return;
}
static int set_chmod_dacl(struct cifs_acl *pndacl, struct cifs_sid *pownersid,
struct cifs_sid *pgrpsid, __u64 nmode)
{
u16 size = 0;
struct cifs_acl *pnndacl;
pnndacl = (struct cifs_acl *)((char *)pndacl + sizeof(struct cifs_acl));
size += fill_ace_for_sid((struct cifs_ace *) ((char *)pnndacl + size),
pownersid, nmode, S_IRWXU);
size += fill_ace_for_sid((struct cifs_ace *)((char *)pnndacl + size),
pgrpsid, nmode, S_IRWXG);
size += fill_ace_for_sid((struct cifs_ace *)((char *)pnndacl + size),
&sid_everyone, nmode, S_IRWXO);
pndacl->size = cpu_to_le16(size + sizeof(struct cifs_acl));
pndacl->num_aces = cpu_to_le32(3);
return 0;
}
static int parse_sid(struct cifs_sid *psid, char *end_of_acl)
{
if (end_of_acl < (char *)psid + 8) {
cifs_dbg(VFS, "ACL too small to parse SID %p\n", psid);
return -EINVAL;
}
#ifdef CONFIG_CIFS_DEBUG2
if (psid->num_subauth) {
int i;
cifs_dbg(FYI, "SID revision %d num_auth %d\n",
psid->revision, psid->num_subauth);
for (i = 0; i < psid->num_subauth; i++) {
cifs_dbg(FYI, "SID sub_auth[%d]: 0x%x\n",
i, le32_to_cpu(psid->sub_auth[i]));
}
cifs_dbg(FYI, "RID 0x%x\n",
le32_to_cpu(psid->sub_auth[psid->num_subauth-1]));
}
#endif
return 0;
}
static int parse_sec_desc(struct cifs_sb_info *cifs_sb,
struct cifs_ntsd *pntsd, int acl_len, struct cifs_fattr *fattr)
{
int rc = 0;
struct cifs_sid *owner_sid_ptr, *group_sid_ptr;
struct cifs_acl *dacl_ptr;
char *end_of_acl = ((char *)pntsd) + acl_len;
__u32 dacloffset;
if (pntsd == NULL)
return -EIO;
owner_sid_ptr = (struct cifs_sid *)((char *)pntsd +
le32_to_cpu(pntsd->osidoffset));
group_sid_ptr = (struct cifs_sid *)((char *)pntsd +
le32_to_cpu(pntsd->gsidoffset));
dacloffset = le32_to_cpu(pntsd->dacloffset);
dacl_ptr = (struct cifs_acl *)((char *)pntsd + dacloffset);
cifs_dbg(NOISY, "revision %d type 0x%x ooffset 0x%x goffset 0x%x sacloffset 0x%x dacloffset 0x%x\n",
pntsd->revision, pntsd->type, le32_to_cpu(pntsd->osidoffset),
le32_to_cpu(pntsd->gsidoffset),
le32_to_cpu(pntsd->sacloffset), dacloffset);
rc = parse_sid(owner_sid_ptr, end_of_acl);
if (rc) {
cifs_dbg(FYI, "%s: Error %d parsing Owner SID\n", __func__, rc);
return rc;
}
rc = sid_to_id(cifs_sb, owner_sid_ptr, fattr, SIDOWNER);
if (rc) {
cifs_dbg(FYI, "%s: Error %d mapping Owner SID to uid\n",
__func__, rc);
return rc;
}
rc = parse_sid(group_sid_ptr, end_of_acl);
if (rc) {
cifs_dbg(FYI, "%s: Error %d mapping Owner SID to gid\n",
__func__, rc);
return rc;
}
rc = sid_to_id(cifs_sb, group_sid_ptr, fattr, SIDGROUP);
if (rc) {
cifs_dbg(FYI, "%s: Error %d mapping Group SID to gid\n",
__func__, rc);
return rc;
}
if (dacloffset)
parse_dacl(dacl_ptr, end_of_acl, owner_sid_ptr,
group_sid_ptr, fattr);
else
cifs_dbg(FYI, "no ACL\n");
return rc;
}
static int build_sec_desc(struct cifs_ntsd *pntsd, struct cifs_ntsd *pnntsd,
__u32 secdesclen, __u64 nmode, kuid_t uid, kgid_t gid, int *aclflag)
{
int rc = 0;
__u32 dacloffset;
__u32 ndacloffset;
__u32 sidsoffset;
struct cifs_sid *owner_sid_ptr, *group_sid_ptr;
struct cifs_sid *nowner_sid_ptr, *ngroup_sid_ptr;
struct cifs_acl *dacl_ptr = NULL;
struct cifs_acl *ndacl_ptr = NULL;
if (nmode != NO_CHANGE_64) {
owner_sid_ptr = (struct cifs_sid *)((char *)pntsd +
le32_to_cpu(pntsd->osidoffset));
group_sid_ptr = (struct cifs_sid *)((char *)pntsd +
le32_to_cpu(pntsd->gsidoffset));
dacloffset = le32_to_cpu(pntsd->dacloffset);
dacl_ptr = (struct cifs_acl *)((char *)pntsd + dacloffset);
ndacloffset = sizeof(struct cifs_ntsd);
ndacl_ptr = (struct cifs_acl *)((char *)pnntsd + ndacloffset);
ndacl_ptr->revision = dacl_ptr->revision;
ndacl_ptr->size = 0;
ndacl_ptr->num_aces = 0;
rc = set_chmod_dacl(ndacl_ptr, owner_sid_ptr, group_sid_ptr,
nmode);
sidsoffset = ndacloffset + le16_to_cpu(ndacl_ptr->size);
copy_sec_desc(pntsd, pnntsd, sidsoffset);
*aclflag = CIFS_ACL_DACL;
} else {
memcpy(pnntsd, pntsd, secdesclen);
if (uid_valid(uid)) {
uid_t id;
owner_sid_ptr = (struct cifs_sid *)((char *)pnntsd +
le32_to_cpu(pnntsd->osidoffset));
nowner_sid_ptr = kmalloc(sizeof(struct cifs_sid),
GFP_KERNEL);
if (!nowner_sid_ptr)
return -ENOMEM;
id = from_kuid(&init_user_ns, uid);
rc = id_to_sid(id, SIDOWNER, nowner_sid_ptr);
if (rc) {
cifs_dbg(FYI, "%s: Mapping error %d for owner id %d\n",
__func__, rc, id);
kfree(nowner_sid_ptr);
return rc;
}
cifs_copy_sid(owner_sid_ptr, nowner_sid_ptr);
kfree(nowner_sid_ptr);
*aclflag = CIFS_ACL_OWNER;
}
if (gid_valid(gid)) {
gid_t id;
group_sid_ptr = (struct cifs_sid *)((char *)pnntsd +
le32_to_cpu(pnntsd->gsidoffset));
ngroup_sid_ptr = kmalloc(sizeof(struct cifs_sid),
GFP_KERNEL);
if (!ngroup_sid_ptr)
return -ENOMEM;
id = from_kgid(&init_user_ns, gid);
rc = id_to_sid(id, SIDGROUP, ngroup_sid_ptr);
if (rc) {
cifs_dbg(FYI, "%s: Mapping error %d for group id %d\n",
__func__, rc, id);
kfree(ngroup_sid_ptr);
return rc;
}
cifs_copy_sid(group_sid_ptr, ngroup_sid_ptr);
kfree(ngroup_sid_ptr);
*aclflag = CIFS_ACL_GROUP;
}
}
return rc;
}
static struct cifs_ntsd *get_cifs_acl_by_fid(struct cifs_sb_info *cifs_sb,
__u16 fid, u32 *pacllen)
{
struct cifs_ntsd *pntsd = NULL;
unsigned int xid;
int rc;
struct tcon_link *tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink))
return ERR_CAST(tlink);
xid = get_xid();
rc = CIFSSMBGetCIFSACL(xid, tlink_tcon(tlink), fid, &pntsd, pacllen);
free_xid(xid);
cifs_put_tlink(tlink);
cifs_dbg(FYI, "%s: rc = %d ACL len %d\n", __func__, rc, *pacllen);
if (rc)
return ERR_PTR(rc);
return pntsd;
}
static struct cifs_ntsd *get_cifs_acl_by_path(struct cifs_sb_info *cifs_sb,
const char *path, u32 *pacllen)
{
struct cifs_ntsd *pntsd = NULL;
int oplock = 0;
unsigned int xid;
int rc, create_options = 0;
__u16 fid;
struct cifs_tcon *tcon;
struct tcon_link *tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink))
return ERR_CAST(tlink);
tcon = tlink_tcon(tlink);
xid = get_xid();
if (backup_cred(cifs_sb))
create_options |= CREATE_OPEN_BACKUP_INTENT;
rc = CIFSSMBOpen(xid, tcon, path, FILE_OPEN, READ_CONTROL,
create_options, &fid, &oplock, NULL, cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR);
if (!rc) {
rc = CIFSSMBGetCIFSACL(xid, tcon, fid, &pntsd, pacllen);
CIFSSMBClose(xid, tcon, fid);
}
cifs_put_tlink(tlink);
free_xid(xid);
cifs_dbg(FYI, "%s: rc = %d ACL len %d\n", __func__, rc, *pacllen);
if (rc)
return ERR_PTR(rc);
return pntsd;
}
struct cifs_ntsd *get_cifs_acl(struct cifs_sb_info *cifs_sb,
struct inode *inode, const char *path,
u32 *pacllen)
{
struct cifs_ntsd *pntsd = NULL;
struct cifsFileInfo *open_file = NULL;
if (inode)
open_file = find_readable_file(CIFS_I(inode), true);
if (!open_file)
return get_cifs_acl_by_path(cifs_sb, path, pacllen);
pntsd = get_cifs_acl_by_fid(cifs_sb, open_file->fid.netfid, pacllen);
cifsFileInfo_put(open_file);
return pntsd;
}
int set_cifs_acl(struct cifs_ntsd *pnntsd, __u32 acllen,
struct inode *inode, const char *path, int aclflag)
{
int oplock = 0;
unsigned int xid;
int rc, access_flags, create_options = 0;
__u16 fid;
struct cifs_tcon *tcon;
struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
struct tcon_link *tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink))
return PTR_ERR(tlink);
tcon = tlink_tcon(tlink);
xid = get_xid();
if (backup_cred(cifs_sb))
create_options |= CREATE_OPEN_BACKUP_INTENT;
if (aclflag == CIFS_ACL_OWNER || aclflag == CIFS_ACL_GROUP)
access_flags = WRITE_OWNER;
else
access_flags = WRITE_DAC;
rc = CIFSSMBOpen(xid, tcon, path, FILE_OPEN, access_flags,
create_options, &fid, &oplock, NULL, cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR);
if (rc) {
cifs_dbg(VFS, "Unable to open file to set ACL\n");
goto out;
}
rc = CIFSSMBSetCIFSACL(xid, tcon, fid, pnntsd, acllen, aclflag);
cifs_dbg(NOISY, "SetCIFSACL rc = %d\n", rc);
CIFSSMBClose(xid, tcon, fid);
out:
free_xid(xid);
cifs_put_tlink(tlink);
return rc;
}
int
cifs_acl_to_fattr(struct cifs_sb_info *cifs_sb, struct cifs_fattr *fattr,
struct inode *inode, const char *path, const __u16 *pfid)
{
struct cifs_ntsd *pntsd = NULL;
u32 acllen = 0;
int rc = 0;
cifs_dbg(NOISY, "converting ACL to mode for %s\n", path);
if (pfid)
pntsd = get_cifs_acl_by_fid(cifs_sb, *pfid, &acllen);
else
pntsd = get_cifs_acl(cifs_sb, inode, path, &acllen);
if (IS_ERR(pntsd)) {
rc = PTR_ERR(pntsd);
cifs_dbg(VFS, "%s: error %d getting sec desc\n", __func__, rc);
} else {
rc = parse_sec_desc(cifs_sb, pntsd, acllen, fattr);
kfree(pntsd);
if (rc)
cifs_dbg(VFS, "parse sec desc failed rc = %d\n", rc);
}
return rc;
}
int
id_mode_to_cifs_acl(struct inode *inode, const char *path, __u64 nmode,
kuid_t uid, kgid_t gid)
{
int rc = 0;
int aclflag = CIFS_ACL_DACL;
__u32 secdesclen = 0;
struct cifs_ntsd *pntsd = NULL;
struct cifs_ntsd *pnntsd = NULL;
cifs_dbg(NOISY, "set ACL from mode for %s\n", path);
pntsd = get_cifs_acl(CIFS_SB(inode->i_sb), inode, path, &secdesclen);
if (IS_ERR(pntsd)) {
rc = PTR_ERR(pntsd);
cifs_dbg(VFS, "%s: error %d getting sec desc\n", __func__, rc);
goto out;
}
secdesclen = max_t(u32, secdesclen, DEFAULT_SEC_DESC_LEN);
pnntsd = kmalloc(secdesclen, GFP_KERNEL);
if (!pnntsd) {
kfree(pntsd);
return -ENOMEM;
}
rc = build_sec_desc(pntsd, pnntsd, secdesclen, nmode, uid, gid,
&aclflag);
cifs_dbg(NOISY, "build_sec_desc rc: %d\n", rc);
if (!rc) {
rc = set_cifs_acl(pnntsd, secdesclen, inode, path, aclflag);
cifs_dbg(NOISY, "set_cifs_acl rc: %d\n", rc);
}
kfree(pnntsd);
kfree(pntsd);
out:
return rc;
}
