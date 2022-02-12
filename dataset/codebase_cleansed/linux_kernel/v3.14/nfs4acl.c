static u32
mask_from_posix(unsigned short perm, unsigned int flags)
{
int mask = NFS4_ANYONE_MODE;
if (flags & NFS4_ACL_OWNER)
mask |= NFS4_OWNER_MODE;
if (perm & ACL_READ)
mask |= NFS4_READ_MODE;
if (perm & ACL_WRITE)
mask |= NFS4_WRITE_MODE;
if ((perm & ACL_WRITE) && (flags & NFS4_ACL_DIR))
mask |= NFS4_ACE_DELETE_CHILD;
if (perm & ACL_EXECUTE)
mask |= NFS4_EXECUTE_MODE;
return mask;
}
static u32
deny_mask_from_posix(unsigned short perm, u32 flags)
{
u32 mask = 0;
if (perm & ACL_READ)
mask |= NFS4_READ_MODE;
if (perm & ACL_WRITE)
mask |= NFS4_WRITE_MODE;
if ((perm & ACL_WRITE) && (flags & NFS4_ACL_DIR))
mask |= NFS4_ACE_DELETE_CHILD;
if (perm & ACL_EXECUTE)
mask |= NFS4_EXECUTE_MODE;
return mask;
}
static void
low_mode_from_nfs4(u32 perm, unsigned short *mode, unsigned int flags)
{
u32 write_mode = NFS4_WRITE_MODE;
if (flags & NFS4_ACL_DIR)
write_mode |= NFS4_ACE_DELETE_CHILD;
*mode = 0;
if ((perm & NFS4_READ_MODE) == NFS4_READ_MODE)
*mode |= ACL_READ;
if ((perm & write_mode) == write_mode)
*mode |= ACL_WRITE;
if ((perm & NFS4_EXECUTE_MODE) == NFS4_EXECUTE_MODE)
*mode |= ACL_EXECUTE;
}
int
nfsd4_get_nfs4_acl(struct svc_rqst *rqstp, struct dentry *dentry,
struct nfs4_acl **acl)
{
struct inode *inode = dentry->d_inode;
int error = 0;
struct posix_acl *pacl = NULL, *dpacl = NULL;
unsigned int flags = 0;
int size = 0;
pacl = get_acl(inode, ACL_TYPE_ACCESS);
if (!pacl) {
pacl = posix_acl_from_mode(inode->i_mode, GFP_KERNEL);
if (IS_ERR(pacl))
return PTR_ERR(pacl);
}
size += 2 * pacl->a_count;
if (S_ISDIR(inode->i_mode)) {
flags = NFS4_ACL_DIR;
dpacl = get_acl(inode, ACL_TYPE_DEFAULT);
if (dpacl)
size += 2 * dpacl->a_count;
}
*acl = nfs4_acl_new(size);
if (*acl == NULL) {
error = -ENOMEM;
goto out;
}
_posix_to_nfsv4_one(pacl, *acl, flags & ~NFS4_ACL_TYPE_DEFAULT);
if (dpacl)
_posix_to_nfsv4_one(dpacl, *acl, flags | NFS4_ACL_TYPE_DEFAULT);
out:
posix_acl_release(pacl);
posix_acl_release(dpacl);
return error;
}
static void
summarize_posix_acl(struct posix_acl *acl, struct posix_acl_summary *pas)
{
struct posix_acl_entry *pa, *pe;
memset(pas, 0, sizeof(*pas));
pas->mask = 07;
pe = acl->a_entries + acl->a_count;
FOREACH_ACL_ENTRY(pa, acl, pe) {
switch (pa->e_tag) {
case ACL_USER_OBJ:
pas->owner = pa->e_perm;
break;
case ACL_GROUP_OBJ:
pas->group = pa->e_perm;
break;
case ACL_USER:
pas->users |= pa->e_perm;
break;
case ACL_GROUP:
pas->groups |= pa->e_perm;
break;
case ACL_OTHER:
pas->other = pa->e_perm;
break;
case ACL_MASK:
pas->mask = pa->e_perm;
break;
}
}
pas->users &= pas->mask;
pas->group &= pas->mask;
pas->groups &= pas->mask;
}
static void
_posix_to_nfsv4_one(struct posix_acl *pacl, struct nfs4_acl *acl,
unsigned int flags)
{
struct posix_acl_entry *pa, *group_owner_entry;
struct nfs4_ace *ace;
struct posix_acl_summary pas;
unsigned short deny;
int eflag = ((flags & NFS4_ACL_TYPE_DEFAULT) ?
NFS4_INHERITANCE_FLAGS | NFS4_ACE_INHERIT_ONLY_ACE : 0);
BUG_ON(pacl->a_count < 3);
summarize_posix_acl(pacl, &pas);
pa = pacl->a_entries;
ace = acl->aces + acl->naces;
deny = ~pas.owner;
deny &= pas.users | pas.group | pas.groups | pas.other;
if (deny) {
ace->type = NFS4_ACE_ACCESS_DENIED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = deny_mask_from_posix(deny, flags);
ace->whotype = NFS4_ACL_WHO_OWNER;
ace++;
acl->naces++;
}
ace->type = NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = mask_from_posix(pa->e_perm, flags | NFS4_ACL_OWNER);
ace->whotype = NFS4_ACL_WHO_OWNER;
ace++;
acl->naces++;
pa++;
while (pa->e_tag == ACL_USER) {
deny = ~(pa->e_perm & pas.mask);
deny &= pas.groups | pas.group | pas.other;
if (deny) {
ace->type = NFS4_ACE_ACCESS_DENIED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = deny_mask_from_posix(deny, flags);
ace->whotype = NFS4_ACL_WHO_NAMED;
ace->who_uid = pa->e_uid;
ace++;
acl->naces++;
}
ace->type = NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = mask_from_posix(pa->e_perm & pas.mask,
flags);
ace->whotype = NFS4_ACL_WHO_NAMED;
ace->who_uid = pa->e_uid;
ace++;
acl->naces++;
pa++;
}
group_owner_entry = pa;
ace->type = NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = mask_from_posix(pas.group, flags);
ace->whotype = NFS4_ACL_WHO_GROUP;
ace++;
acl->naces++;
pa++;
while (pa->e_tag == ACL_GROUP) {
ace->type = NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE;
ace->flag = eflag | NFS4_ACE_IDENTIFIER_GROUP;
ace->access_mask = mask_from_posix(pa->e_perm & pas.mask,
flags);
ace->whotype = NFS4_ACL_WHO_NAMED;
ace->who_gid = pa->e_gid;
ace++;
acl->naces++;
pa++;
}
pa = group_owner_entry;
deny = ~pas.group & pas.other;
if (deny) {
ace->type = NFS4_ACE_ACCESS_DENIED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = deny_mask_from_posix(deny, flags);
ace->whotype = NFS4_ACL_WHO_GROUP;
ace++;
acl->naces++;
}
pa++;
while (pa->e_tag == ACL_GROUP) {
deny = ~(pa->e_perm & pas.mask);
deny &= pas.other;
if (deny) {
ace->type = NFS4_ACE_ACCESS_DENIED_ACE_TYPE;
ace->flag = eflag | NFS4_ACE_IDENTIFIER_GROUP;
ace->access_mask = deny_mask_from_posix(deny, flags);
ace->whotype = NFS4_ACL_WHO_NAMED;
ace->who_gid = pa->e_gid;
ace++;
acl->naces++;
}
pa++;
}
if (pa->e_tag == ACL_MASK)
pa++;
ace->type = NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE;
ace->flag = eflag;
ace->access_mask = mask_from_posix(pa->e_perm, flags);
ace->whotype = NFS4_ACL_WHO_EVERYONE;
acl->naces++;
}
static bool
pace_gt(struct posix_acl_entry *pace1, struct posix_acl_entry *pace2)
{
if (pace1->e_tag != pace2->e_tag)
return pace1->e_tag > pace2->e_tag;
if (pace1->e_tag == ACL_USER)
return uid_gt(pace1->e_uid, pace2->e_uid);
if (pace1->e_tag == ACL_GROUP)
return gid_gt(pace1->e_gid, pace2->e_gid);
return false;
}
static void
sort_pacl_range(struct posix_acl *pacl, int start, int end) {
int sorted = 0, i;
struct posix_acl_entry tmp;
while (!sorted) {
sorted = 1;
for (i = start; i < end; i++) {
if (pace_gt(&pacl->a_entries[i],
&pacl->a_entries[i+1])) {
sorted = 0;
tmp = pacl->a_entries[i];
pacl->a_entries[i] = pacl->a_entries[i+1];
pacl->a_entries[i+1] = tmp;
}
}
}
}
static void
sort_pacl(struct posix_acl *pacl)
{
int i, j;
if (pacl->a_count <= 4)
return;
i = 1;
while (pacl->a_entries[i].e_tag == ACL_USER)
i++;
sort_pacl_range(pacl, 1, i-1);
BUG_ON(pacl->a_entries[i].e_tag != ACL_GROUP_OBJ);
j = ++i;
while (pacl->a_entries[j].e_tag == ACL_GROUP)
j++;
sort_pacl_range(pacl, i, j-1);
return;
}
static int
init_state(struct posix_acl_state *state, int cnt)
{
int alloc;
memset(state, 0, sizeof(struct posix_acl_state));
state->empty = 1;
alloc = sizeof(struct posix_ace_state_array)
+ cnt*sizeof(struct posix_user_ace_state);
state->users = kzalloc(alloc, GFP_KERNEL);
if (!state->users)
return -ENOMEM;
state->groups = kzalloc(alloc, GFP_KERNEL);
if (!state->groups) {
kfree(state->users);
return -ENOMEM;
}
return 0;
}
static void
free_state(struct posix_acl_state *state) {
kfree(state->users);
kfree(state->groups);
}
static inline void add_to_mask(struct posix_acl_state *state, struct posix_ace_state *astate)
{
state->mask.allow |= astate->allow;
}
static inline int check_deny(u32 mask, int isowner)
{
if (mask & (NFS4_ACE_READ_ATTRIBUTES | NFS4_ACE_READ_ACL))
return -EINVAL;
if (!isowner)
return 0;
if (mask & (NFS4_ACE_WRITE_ATTRIBUTES | NFS4_ACE_WRITE_ACL))
return -EINVAL;
return 0;
}
static struct posix_acl *
posix_state_to_acl(struct posix_acl_state *state, unsigned int flags)
{
struct posix_acl_entry *pace;
struct posix_acl *pacl;
int nace;
int i, error = 0;
if (state->empty && (flags & NFS4_ACL_TYPE_DEFAULT)) {
pacl = posix_acl_alloc(0, GFP_KERNEL);
return pacl ? pacl : ERR_PTR(-ENOMEM);
}
nace = 4 + state->users->n + state->groups->n;
pacl = posix_acl_alloc(nace, GFP_KERNEL);
if (!pacl)
return ERR_PTR(-ENOMEM);
pace = pacl->a_entries;
pace->e_tag = ACL_USER_OBJ;
error = check_deny(state->owner.deny, 1);
if (error)
goto out_err;
low_mode_from_nfs4(state->owner.allow, &pace->e_perm, flags);
for (i=0; i < state->users->n; i++) {
pace++;
pace->e_tag = ACL_USER;
error = check_deny(state->users->aces[i].perms.deny, 0);
if (error)
goto out_err;
low_mode_from_nfs4(state->users->aces[i].perms.allow,
&pace->e_perm, flags);
pace->e_uid = state->users->aces[i].uid;
add_to_mask(state, &state->users->aces[i].perms);
}
pace++;
pace->e_tag = ACL_GROUP_OBJ;
error = check_deny(state->group.deny, 0);
if (error)
goto out_err;
low_mode_from_nfs4(state->group.allow, &pace->e_perm, flags);
add_to_mask(state, &state->group);
for (i=0; i < state->groups->n; i++) {
pace++;
pace->e_tag = ACL_GROUP;
error = check_deny(state->groups->aces[i].perms.deny, 0);
if (error)
goto out_err;
low_mode_from_nfs4(state->groups->aces[i].perms.allow,
&pace->e_perm, flags);
pace->e_gid = state->groups->aces[i].gid;
add_to_mask(state, &state->groups->aces[i].perms);
}
pace++;
pace->e_tag = ACL_MASK;
low_mode_from_nfs4(state->mask.allow, &pace->e_perm, flags);
pace++;
pace->e_tag = ACL_OTHER;
error = check_deny(state->other.deny, 0);
if (error)
goto out_err;
low_mode_from_nfs4(state->other.allow, &pace->e_perm, flags);
return pacl;
out_err:
posix_acl_release(pacl);
return ERR_PTR(error);
}
static inline void allow_bits(struct posix_ace_state *astate, u32 mask)
{
astate->allow |= mask & ~astate->deny;
}
static inline void deny_bits(struct posix_ace_state *astate, u32 mask)
{
astate->deny |= mask & ~astate->allow;
}
static int find_uid(struct posix_acl_state *state, kuid_t uid)
{
struct posix_ace_state_array *a = state->users;
int i;
for (i = 0; i < a->n; i++)
if (uid_eq(a->aces[i].uid, uid))
return i;
a->n++;
a->aces[i].uid = uid;
a->aces[i].perms.allow = state->everyone.allow;
a->aces[i].perms.deny = state->everyone.deny;
return i;
}
static int find_gid(struct posix_acl_state *state, kgid_t gid)
{
struct posix_ace_state_array *a = state->groups;
int i;
for (i = 0; i < a->n; i++)
if (gid_eq(a->aces[i].gid, gid))
return i;
a->n++;
a->aces[i].gid = gid;
a->aces[i].perms.allow = state->everyone.allow;
a->aces[i].perms.deny = state->everyone.deny;
return i;
}
static void deny_bits_array(struct posix_ace_state_array *a, u32 mask)
{
int i;
for (i=0; i < a->n; i++)
deny_bits(&a->aces[i].perms, mask);
}
static void allow_bits_array(struct posix_ace_state_array *a, u32 mask)
{
int i;
for (i=0; i < a->n; i++)
allow_bits(&a->aces[i].perms, mask);
}
static void process_one_v4_ace(struct posix_acl_state *state,
struct nfs4_ace *ace)
{
u32 mask = ace->access_mask;
int i;
state->empty = 0;
switch (ace2type(ace)) {
case ACL_USER_OBJ:
if (ace->type == NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE) {
allow_bits(&state->owner, mask);
} else {
deny_bits(&state->owner, mask);
}
break;
case ACL_USER:
i = find_uid(state, ace->who_uid);
if (ace->type == NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE) {
allow_bits(&state->users->aces[i].perms, mask);
} else {
deny_bits(&state->users->aces[i].perms, mask);
mask = state->users->aces[i].perms.deny;
deny_bits(&state->owner, mask);
}
break;
case ACL_GROUP_OBJ:
if (ace->type == NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE) {
allow_bits(&state->group, mask);
} else {
deny_bits(&state->group, mask);
mask = state->group.deny;
deny_bits(&state->owner, mask);
deny_bits(&state->everyone, mask);
deny_bits_array(state->users, mask);
deny_bits_array(state->groups, mask);
}
break;
case ACL_GROUP:
i = find_gid(state, ace->who_gid);
if (ace->type == NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE) {
allow_bits(&state->groups->aces[i].perms, mask);
} else {
deny_bits(&state->groups->aces[i].perms, mask);
mask = state->groups->aces[i].perms.deny;
deny_bits(&state->owner, mask);
deny_bits(&state->group, mask);
deny_bits(&state->everyone, mask);
deny_bits_array(state->users, mask);
deny_bits_array(state->groups, mask);
}
break;
case ACL_OTHER:
if (ace->type == NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE) {
allow_bits(&state->owner, mask);
allow_bits(&state->group, mask);
allow_bits(&state->other, mask);
allow_bits(&state->everyone, mask);
allow_bits_array(state->users, mask);
allow_bits_array(state->groups, mask);
} else {
deny_bits(&state->owner, mask);
deny_bits(&state->group, mask);
deny_bits(&state->other, mask);
deny_bits(&state->everyone, mask);
deny_bits_array(state->users, mask);
deny_bits_array(state->groups, mask);
}
}
}
static int nfs4_acl_nfsv4_to_posix(struct nfs4_acl *acl,
struct posix_acl **pacl, struct posix_acl **dpacl,
unsigned int flags)
{
struct posix_acl_state effective_acl_state, default_acl_state;
struct nfs4_ace *ace;
int ret;
ret = init_state(&effective_acl_state, acl->naces);
if (ret)
return ret;
ret = init_state(&default_acl_state, acl->naces);
if (ret)
goto out_estate;
ret = -EINVAL;
for (ace = acl->aces; ace < acl->aces + acl->naces; ace++) {
if (ace->type != NFS4_ACE_ACCESS_ALLOWED_ACE_TYPE &&
ace->type != NFS4_ACE_ACCESS_DENIED_ACE_TYPE)
goto out_dstate;
if (ace->flag & ~NFS4_SUPPORTED_FLAGS)
goto out_dstate;
if ((ace->flag & NFS4_INHERITANCE_FLAGS) == 0) {
process_one_v4_ace(&effective_acl_state, ace);
continue;
}
if (!(flags & NFS4_ACL_DIR))
goto out_dstate;
process_one_v4_ace(&default_acl_state, ace);
if (!(ace->flag & NFS4_ACE_INHERIT_ONLY_ACE))
process_one_v4_ace(&effective_acl_state, ace);
}
*pacl = posix_state_to_acl(&effective_acl_state, flags);
if (IS_ERR(*pacl)) {
ret = PTR_ERR(*pacl);
*pacl = NULL;
goto out_dstate;
}
*dpacl = posix_state_to_acl(&default_acl_state,
flags | NFS4_ACL_TYPE_DEFAULT);
if (IS_ERR(*dpacl)) {
ret = PTR_ERR(*dpacl);
*dpacl = NULL;
posix_acl_release(*pacl);
*pacl = NULL;
goto out_dstate;
}
sort_pacl(*pacl);
sort_pacl(*dpacl);
ret = 0;
out_dstate:
free_state(&default_acl_state);
out_estate:
free_state(&effective_acl_state);
return ret;
}
__be32
nfsd4_set_nfs4_acl(struct svc_rqst *rqstp, struct svc_fh *fhp,
struct nfs4_acl *acl)
{
__be32 error;
int host_error;
struct dentry *dentry;
struct inode *inode;
struct posix_acl *pacl = NULL, *dpacl = NULL;
unsigned int flags = 0;
error = fh_verify(rqstp, fhp, 0, NFSD_MAY_SATTR);
if (error)
return error;
dentry = fhp->fh_dentry;
inode = dentry->d_inode;
if (!inode->i_op->set_acl || !IS_POSIXACL(inode))
return nfserr_attrnotsupp;
if (S_ISDIR(inode->i_mode))
flags = NFS4_ACL_DIR;
host_error = nfs4_acl_nfsv4_to_posix(acl, &pacl, &dpacl, flags);
if (host_error == -EINVAL)
return nfserr_attrnotsupp;
if (host_error < 0)
goto out_nfserr;
host_error = inode->i_op->set_acl(inode, pacl, ACL_TYPE_ACCESS);
if (host_error < 0)
goto out_release;
if (S_ISDIR(inode->i_mode)) {
host_error = inode->i_op->set_acl(inode, dpacl,
ACL_TYPE_DEFAULT);
}
out_release:
posix_acl_release(pacl);
posix_acl_release(dpacl);
out_nfserr:
if (host_error == -EOPNOTSUPP)
return nfserr_attrnotsupp;
else
return nfserrno(host_error);
}
static short
ace2type(struct nfs4_ace *ace)
{
switch (ace->whotype) {
case NFS4_ACL_WHO_NAMED:
return (ace->flag & NFS4_ACE_IDENTIFIER_GROUP ?
ACL_GROUP : ACL_USER);
case NFS4_ACL_WHO_OWNER:
return ACL_USER_OBJ;
case NFS4_ACL_WHO_GROUP:
return ACL_GROUP_OBJ;
case NFS4_ACL_WHO_EVERYONE:
return ACL_OTHER;
}
BUG();
return -1;
}
struct nfs4_acl *
nfs4_acl_new(int n)
{
struct nfs4_acl *acl;
acl = kmalloc(sizeof(*acl) + n*sizeof(struct nfs4_ace), GFP_KERNEL);
if (acl == NULL)
return NULL;
acl->naces = 0;
return acl;
}
int
nfs4_acl_get_whotype(char *p, u32 len)
{
int i;
for (i = 0; i < ARRAY_SIZE(s2t_map); i++) {
if (s2t_map[i].stringlen == len &&
0 == memcmp(s2t_map[i].string, p, len))
return s2t_map[i].type;
}
return NFS4_ACL_WHO_NAMED;
}
__be32 nfs4_acl_write_who(int who, __be32 **p, int *len)
{
int i;
int bytes;
for (i = 0; i < ARRAY_SIZE(s2t_map); i++) {
if (s2t_map[i].type != who)
continue;
bytes = 4 + (XDR_QUADLEN(s2t_map[i].stringlen) << 2);
if (bytes > *len)
return nfserr_resource;
*p = xdr_encode_opaque(*p, s2t_map[i].string,
s2t_map[i].stringlen);
*len -= bytes;
return 0;
}
WARN_ON_ONCE(1);
return -1;
}
