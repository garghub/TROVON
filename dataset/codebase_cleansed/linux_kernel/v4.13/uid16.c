static int groups16_to_user(old_gid_t __user *grouplist,
struct group_info *group_info)
{
struct user_namespace *user_ns = current_user_ns();
int i;
old_gid_t group;
kgid_t kgid;
for (i = 0; i < group_info->ngroups; i++) {
kgid = group_info->gid[i];
group = high2lowgid(from_kgid_munged(user_ns, kgid));
if (put_user(group, grouplist+i))
return -EFAULT;
}
return 0;
}
static int groups16_from_user(struct group_info *group_info,
old_gid_t __user *grouplist)
{
struct user_namespace *user_ns = current_user_ns();
int i;
old_gid_t group;
kgid_t kgid;
for (i = 0; i < group_info->ngroups; i++) {
if (get_user(group, grouplist+i))
return -EFAULT;
kgid = make_kgid(user_ns, low2highgid(group));
if (!gid_valid(kgid))
return -EINVAL;
group_info->gid[i] = kgid;
}
return 0;
}
