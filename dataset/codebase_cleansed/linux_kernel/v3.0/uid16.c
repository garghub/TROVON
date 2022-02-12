static int groups16_to_user(old_gid_t __user *grouplist,
struct group_info *group_info)
{
int i;
old_gid_t group;
for (i = 0; i < group_info->ngroups; i++) {
group = high2lowgid(GROUP_AT(group_info, i));
if (put_user(group, grouplist+i))
return -EFAULT;
}
return 0;
}
static int groups16_from_user(struct group_info *group_info,
old_gid_t __user *grouplist)
{
int i;
old_gid_t group;
for (i = 0; i < group_info->ngroups; i++) {
if (get_user(group, grouplist+i))
return -EFAULT;
GROUP_AT(group_info, i) = low2highgid(group);
}
return 0;
}
