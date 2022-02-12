struct group_info *groups_alloc(int gidsetsize)
{
struct group_info *gi;
unsigned int len;
len = sizeof(struct group_info) + sizeof(kgid_t) * gidsetsize;
gi = kmalloc(len, GFP_KERNEL_ACCOUNT|__GFP_NOWARN|__GFP_NORETRY);
if (!gi)
gi = __vmalloc(len, GFP_KERNEL_ACCOUNT, PAGE_KERNEL);
if (!gi)
return NULL;
atomic_set(&gi->usage, 1);
gi->ngroups = gidsetsize;
return gi;
}
void groups_free(struct group_info *group_info)
{
kvfree(group_info);
}
static int groups_to_user(gid_t __user *grouplist,
const struct group_info *group_info)
{
struct user_namespace *user_ns = current_user_ns();
int i;
unsigned int count = group_info->ngroups;
for (i = 0; i < count; i++) {
gid_t gid;
gid = from_kgid_munged(user_ns, group_info->gid[i]);
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
group_info->gid[i] = kgid;
}
return 0;
}
static int gid_cmp(const void *_a, const void *_b)
{
kgid_t a = *(kgid_t *)_a;
kgid_t b = *(kgid_t *)_b;
return gid_gt(a, b) - gid_lt(a, b);
}
static void groups_sort(struct group_info *group_info)
{
sort(group_info->gid, group_info->ngroups, sizeof(*group_info->gid),
gid_cmp, NULL);
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
if (gid_gt(grp, group_info->gid[mid]))
left = mid + 1;
else if (gid_lt(grp, group_info->gid[mid]))
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
bool may_setgroups(void)
{
struct user_namespace *user_ns = current_user_ns();
return ns_capable(user_ns, CAP_SETGID) &&
userns_may_setgroups(user_ns);
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
