struct group_info *groups_alloc(int gidsetsize)
{
struct group_info *group_info;
int nblocks;
int i;
nblocks = (gidsetsize + NGROUPS_PER_BLOCK - 1) / NGROUPS_PER_BLOCK;
nblocks = nblocks ? : 1;
group_info = kmalloc(sizeof(*group_info) + nblocks*sizeof(gid_t *), GFP_USER);
if (!group_info)
return NULL;
group_info->ngroups = gidsetsize;
group_info->nblocks = nblocks;
atomic_set(&group_info->usage, 1);
if (gidsetsize <= NGROUPS_SMALL)
group_info->blocks[0] = group_info->small_block;
else {
for (i = 0; i < nblocks; i++) {
kgid_t *b;
b = (void *)__get_free_page(GFP_USER);
if (!b)
goto out_undo_partial_alloc;
group_info->blocks[i] = b;
}
}
return group_info;
out_undo_partial_alloc:
while (--i >= 0) {
free_page((unsigned long)group_info->blocks[i]);
}
kfree(group_info);
return NULL;
}
void groups_free(struct group_info *group_info)
{
if (group_info->blocks[0] != group_info->small_block) {
int i;
for (i = 0; i < group_info->nblocks; i++)
free_page((unsigned long)group_info->blocks[i]);
}
kfree(group_info);
}
static int groups_to_user(gid_t __user *grouplist,
const struct group_info *group_info)
{
struct user_namespace *user_ns = current_user_ns();
int i;
unsigned int count = group_info->ngroups;
for (i = 0; i < count; i++) {
gid_t gid;
gid = from_kgid_munged(user_ns, GROUP_AT(group_info, i));
if (put_user(gid, grouplist+i))
return -EFAULT;
}
return 0;
}
static int groups_from_user(struct group_info *group_info,
gid_t __user *grouplist)
{
struct user_namespace *user_ns = current_user_ns();
int i;
unsigned int count = group_info->ngroups;
for (i = 0; i < count; i++) {
gid_t gid;
kgid_t kgid;
if (get_user(gid, grouplist+i))
return -EFAULT;
kgid = make_kgid(user_ns, gid);
if (!gid_valid(kgid))
return -EINVAL;
GROUP_AT(group_info, i) = kgid;
}
return 0;
}
static void groups_sort(struct group_info *group_info)
{
int base, max, stride;
int gidsetsize = group_info->ngroups;
for (stride = 1; stride < gidsetsize; stride = 3 * stride + 1)
;
stride /= 3;
while (stride) {
max = gidsetsize - stride;
for (base = 0; base < max; base++) {
int left = base;
int right = left + stride;
kgid_t tmp = GROUP_AT(group_info, right);
while (left >= 0 && gid_gt(GROUP_AT(group_info, left), tmp)) {
GROUP_AT(group_info, right) =
GROUP_AT(group_info, left);
right = left;
left -= stride;
}
GROUP_AT(group_info, right) = tmp;
}
stride /= 3;
}
}
int groups_search(const struct group_info *group_info, kgid_t grp)
{
unsigned int left, right;
if (!group_info)
return 0;
left = 0;
right = group_info->ngroups;
while (left < right) {
unsigned int mid = (left+right)/2;
if (gid_gt(grp, GROUP_AT(group_info, mid)))
left = mid + 1;
else if (gid_lt(grp, GROUP_AT(group_info, mid)))
right = mid;
else
return 1;
}
return 0;
}
void set_groups(struct cred *new, struct group_info *group_info)
{
put_group_info(new->group_info);
groups_sort(group_info);
get_group_info(group_info);
new->group_info = group_info;
}
int set_current_groups(struct group_info *group_info)
{
struct cred *new;
new = prepare_creds();
if (!new)
return -ENOMEM;
set_groups(new, group_info);
return commit_creds(new);
}
int in_group_p(kgid_t grp)
{
const struct cred *cred = current_cred();
int retval = 1;
if (!gid_eq(grp, cred->fsgid))
retval = groups_search(cred->group_info, grp);
return retval;
}
int in_egroup_p(kgid_t grp)
{
const struct cred *cred = current_cred();
int retval = 1;
if (!gid_eq(grp, cred->egid))
retval = groups_search(cred->group_info, grp);
return retval;
}
