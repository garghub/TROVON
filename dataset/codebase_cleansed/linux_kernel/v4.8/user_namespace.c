static void set_cred_user_ns(struct cred *cred, struct user_namespace *user_ns)
{
cred->securebits = SECUREBITS_DEFAULT;
cred->cap_inheritable = CAP_EMPTY_SET;
cred->cap_permitted = CAP_FULL_SET;
cred->cap_effective = CAP_FULL_SET;
cred->cap_ambient = CAP_EMPTY_SET;
cred->cap_bset = CAP_FULL_SET;
#ifdef CONFIG_KEYS
key_put(cred->request_key_auth);
cred->request_key_auth = NULL;
#endif
cred->user_ns = user_ns;
}
int create_user_ns(struct cred *new)
{
struct user_namespace *ns, *parent_ns = new->user_ns;
kuid_t owner = new->euid;
kgid_t group = new->egid;
int ret;
if (parent_ns->level > 32)
return -EUSERS;
if (current_chrooted())
return -EPERM;
if (!kuid_has_mapping(parent_ns, owner) ||
!kgid_has_mapping(parent_ns, group))
return -EPERM;
ns = kmem_cache_zalloc(user_ns_cachep, GFP_KERNEL);
if (!ns)
return -ENOMEM;
ret = ns_alloc_inum(&ns->ns);
if (ret) {
kmem_cache_free(user_ns_cachep, ns);
return ret;
}
ns->ns.ops = &userns_operations;
atomic_set(&ns->count, 1);
ns->parent = parent_ns;
ns->level = parent_ns->level + 1;
ns->owner = owner;
ns->group = group;
mutex_lock(&userns_state_mutex);
ns->flags = parent_ns->flags;
mutex_unlock(&userns_state_mutex);
set_cred_user_ns(new, ns);
#ifdef CONFIG_PERSISTENT_KEYRINGS
init_rwsem(&ns->persistent_keyring_register_sem);
#endif
return 0;
}
int unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
struct cred *cred;
int err = -ENOMEM;
if (!(unshare_flags & CLONE_NEWUSER))
return 0;
cred = prepare_creds();
if (cred) {
err = create_user_ns(cred);
if (err)
put_cred(cred);
else
*new_cred = cred;
}
return err;
}
void free_user_ns(struct user_namespace *ns)
{
struct user_namespace *parent;
do {
parent = ns->parent;
#ifdef CONFIG_PERSISTENT_KEYRINGS
key_put(ns->persistent_keyring_register);
#endif
ns_free_inum(&ns->ns);
kmem_cache_free(user_ns_cachep, ns);
ns = parent;
} while (atomic_dec_and_test(&parent->count));
}
static u32 map_id_range_down(struct uid_gid_map *map, u32 id, u32 count)
{
unsigned idx, extents;
u32 first, last, id2;
id2 = id + count - 1;
extents = map->nr_extents;
smp_rmb();
for (idx = 0; idx < extents; idx++) {
first = map->extent[idx].first;
last = first + map->extent[idx].count - 1;
if (id >= first && id <= last &&
(id2 >= first && id2 <= last))
break;
}
if (idx < extents)
id = (id - first) + map->extent[idx].lower_first;
else
id = (u32) -1;
return id;
}
static u32 map_id_down(struct uid_gid_map *map, u32 id)
{
unsigned idx, extents;
u32 first, last;
extents = map->nr_extents;
smp_rmb();
for (idx = 0; idx < extents; idx++) {
first = map->extent[idx].first;
last = first + map->extent[idx].count - 1;
if (id >= first && id <= last)
break;
}
if (idx < extents)
id = (id - first) + map->extent[idx].lower_first;
else
id = (u32) -1;
return id;
}
static u32 map_id_up(struct uid_gid_map *map, u32 id)
{
unsigned idx, extents;
u32 first, last;
extents = map->nr_extents;
smp_rmb();
for (idx = 0; idx < extents; idx++) {
first = map->extent[idx].lower_first;
last = first + map->extent[idx].count - 1;
if (id >= first && id <= last)
break;
}
if (idx < extents)
id = (id - first) + map->extent[idx].first;
else
id = (u32) -1;
return id;
}
kuid_t make_kuid(struct user_namespace *ns, uid_t uid)
{
return KUIDT_INIT(map_id_down(&ns->uid_map, uid));
}
uid_t from_kuid(struct user_namespace *targ, kuid_t kuid)
{
return map_id_up(&targ->uid_map, __kuid_val(kuid));
}
uid_t from_kuid_munged(struct user_namespace *targ, kuid_t kuid)
{
uid_t uid;
uid = from_kuid(targ, kuid);
if (uid == (uid_t) -1)
uid = overflowuid;
return uid;
}
kgid_t make_kgid(struct user_namespace *ns, gid_t gid)
{
return KGIDT_INIT(map_id_down(&ns->gid_map, gid));
}
gid_t from_kgid(struct user_namespace *targ, kgid_t kgid)
{
return map_id_up(&targ->gid_map, __kgid_val(kgid));
}
gid_t from_kgid_munged(struct user_namespace *targ, kgid_t kgid)
{
gid_t gid;
gid = from_kgid(targ, kgid);
if (gid == (gid_t) -1)
gid = overflowgid;
return gid;
}
kprojid_t make_kprojid(struct user_namespace *ns, projid_t projid)
{
return KPROJIDT_INIT(map_id_down(&ns->projid_map, projid));
}
projid_t from_kprojid(struct user_namespace *targ, kprojid_t kprojid)
{
return map_id_up(&targ->projid_map, __kprojid_val(kprojid));
}
projid_t from_kprojid_munged(struct user_namespace *targ, kprojid_t kprojid)
{
projid_t projid;
projid = from_kprojid(targ, kprojid);
if (projid == (projid_t) -1)
projid = OVERFLOW_PROJID;
return projid;
}
static int uid_m_show(struct seq_file *seq, void *v)
{
struct user_namespace *ns = seq->private;
struct uid_gid_extent *extent = v;
struct user_namespace *lower_ns;
uid_t lower;
lower_ns = seq_user_ns(seq);
if ((lower_ns == ns) && lower_ns->parent)
lower_ns = lower_ns->parent;
lower = from_kuid(lower_ns, KUIDT_INIT(extent->lower_first));
seq_printf(seq, "%10u %10u %10u\n",
extent->first,
lower,
extent->count);
return 0;
}
static int gid_m_show(struct seq_file *seq, void *v)
{
struct user_namespace *ns = seq->private;
struct uid_gid_extent *extent = v;
struct user_namespace *lower_ns;
gid_t lower;
lower_ns = seq_user_ns(seq);
if ((lower_ns == ns) && lower_ns->parent)
lower_ns = lower_ns->parent;
lower = from_kgid(lower_ns, KGIDT_INIT(extent->lower_first));
seq_printf(seq, "%10u %10u %10u\n",
extent->first,
lower,
extent->count);
return 0;
}
static int projid_m_show(struct seq_file *seq, void *v)
{
struct user_namespace *ns = seq->private;
struct uid_gid_extent *extent = v;
struct user_namespace *lower_ns;
projid_t lower;
lower_ns = seq_user_ns(seq);
if ((lower_ns == ns) && lower_ns->parent)
lower_ns = lower_ns->parent;
lower = from_kprojid(lower_ns, KPROJIDT_INIT(extent->lower_first));
seq_printf(seq, "%10u %10u %10u\n",
extent->first,
lower,
extent->count);
return 0;
}
static void *m_start(struct seq_file *seq, loff_t *ppos,
struct uid_gid_map *map)
{
struct uid_gid_extent *extent = NULL;
loff_t pos = *ppos;
if (pos < map->nr_extents)
extent = &map->extent[pos];
return extent;
}
static void *uid_m_start(struct seq_file *seq, loff_t *ppos)
{
struct user_namespace *ns = seq->private;
return m_start(seq, ppos, &ns->uid_map);
}
static void *gid_m_start(struct seq_file *seq, loff_t *ppos)
{
struct user_namespace *ns = seq->private;
return m_start(seq, ppos, &ns->gid_map);
}
static void *projid_m_start(struct seq_file *seq, loff_t *ppos)
{
struct user_namespace *ns = seq->private;
return m_start(seq, ppos, &ns->projid_map);
}
static void *m_next(struct seq_file *seq, void *v, loff_t *pos)
{
(*pos)++;
return seq->op->start(seq, pos);
}
static void m_stop(struct seq_file *seq, void *v)
{
return;
}
static bool mappings_overlap(struct uid_gid_map *new_map,
struct uid_gid_extent *extent)
{
u32 upper_first, lower_first, upper_last, lower_last;
unsigned idx;
upper_first = extent->first;
lower_first = extent->lower_first;
upper_last = upper_first + extent->count - 1;
lower_last = lower_first + extent->count - 1;
for (idx = 0; idx < new_map->nr_extents; idx++) {
u32 prev_upper_first, prev_lower_first;
u32 prev_upper_last, prev_lower_last;
struct uid_gid_extent *prev;
prev = &new_map->extent[idx];
prev_upper_first = prev->first;
prev_lower_first = prev->lower_first;
prev_upper_last = prev_upper_first + prev->count - 1;
prev_lower_last = prev_lower_first + prev->count - 1;
if ((prev_upper_first <= upper_last) &&
(prev_upper_last >= upper_first))
return true;
if ((prev_lower_first <= lower_last) &&
(prev_lower_last >= lower_first))
return true;
}
return false;
}
static ssize_t map_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos,
int cap_setid,
struct uid_gid_map *map,
struct uid_gid_map *parent_map)
{
struct seq_file *seq = file->private_data;
struct user_namespace *ns = seq->private;
struct uid_gid_map new_map;
unsigned idx;
struct uid_gid_extent *extent = NULL;
char *kbuf = NULL, *pos, *next_line;
ssize_t ret = -EINVAL;
mutex_lock(&userns_state_mutex);
ret = -EPERM;
if (map->nr_extents != 0)
goto out;
if (cap_valid(cap_setid) && !file_ns_capable(file, ns, CAP_SYS_ADMIN))
goto out;
ret = -EINVAL;
if ((*ppos != 0) || (count >= PAGE_SIZE))
goto out;
kbuf = memdup_user_nul(buf, count);
if (IS_ERR(kbuf)) {
ret = PTR_ERR(kbuf);
kbuf = NULL;
goto out;
}
ret = -EINVAL;
pos = kbuf;
new_map.nr_extents = 0;
for (; pos; pos = next_line) {
extent = &new_map.extent[new_map.nr_extents];
next_line = strchr(pos, '\n');
if (next_line) {
*next_line = '\0';
next_line++;
if (*next_line == '\0')
next_line = NULL;
}
pos = skip_spaces(pos);
extent->first = simple_strtoul(pos, &pos, 10);
if (!isspace(*pos))
goto out;
pos = skip_spaces(pos);
extent->lower_first = simple_strtoul(pos, &pos, 10);
if (!isspace(*pos))
goto out;
pos = skip_spaces(pos);
extent->count = simple_strtoul(pos, &pos, 10);
if (*pos && !isspace(*pos))
goto out;
pos = skip_spaces(pos);
if (*pos != '\0')
goto out;
if ((extent->first == (u32) -1) ||
(extent->lower_first == (u32) -1))
goto out;
if ((extent->first + extent->count) <= extent->first)
goto out;
if ((extent->lower_first + extent->count) <=
extent->lower_first)
goto out;
if (mappings_overlap(&new_map, extent))
goto out;
new_map.nr_extents++;
if ((new_map.nr_extents == UID_GID_MAP_MAX_EXTENTS) &&
(next_line != NULL))
goto out;
}
if (new_map.nr_extents == 0)
goto out;
ret = -EPERM;
if (!new_idmap_permitted(file, ns, cap_setid, &new_map))
goto out;
for (idx = 0; idx < new_map.nr_extents; idx++) {
u32 lower_first;
extent = &new_map.extent[idx];
lower_first = map_id_range_down(parent_map,
extent->lower_first,
extent->count);
if (lower_first == (u32) -1)
goto out;
extent->lower_first = lower_first;
}
memcpy(map->extent, new_map.extent,
new_map.nr_extents*sizeof(new_map.extent[0]));
smp_wmb();
map->nr_extents = new_map.nr_extents;
*ppos = count;
ret = count;
out:
mutex_unlock(&userns_state_mutex);
kfree(kbuf);
return ret;
}
ssize_t proc_uid_map_write(struct file *file, const char __user *buf,
size_t size, loff_t *ppos)
{
struct seq_file *seq = file->private_data;
struct user_namespace *ns = seq->private;
struct user_namespace *seq_ns = seq_user_ns(seq);
if (!ns->parent)
return -EPERM;
if ((seq_ns != ns) && (seq_ns != ns->parent))
return -EPERM;
return map_write(file, buf, size, ppos, CAP_SETUID,
&ns->uid_map, &ns->parent->uid_map);
}
ssize_t proc_gid_map_write(struct file *file, const char __user *buf,
size_t size, loff_t *ppos)
{
struct seq_file *seq = file->private_data;
struct user_namespace *ns = seq->private;
struct user_namespace *seq_ns = seq_user_ns(seq);
if (!ns->parent)
return -EPERM;
if ((seq_ns != ns) && (seq_ns != ns->parent))
return -EPERM;
return map_write(file, buf, size, ppos, CAP_SETGID,
&ns->gid_map, &ns->parent->gid_map);
}
ssize_t proc_projid_map_write(struct file *file, const char __user *buf,
size_t size, loff_t *ppos)
{
struct seq_file *seq = file->private_data;
struct user_namespace *ns = seq->private;
struct user_namespace *seq_ns = seq_user_ns(seq);
if (!ns->parent)
return -EPERM;
if ((seq_ns != ns) && (seq_ns != ns->parent))
return -EPERM;
return map_write(file, buf, size, ppos, -1,
&ns->projid_map, &ns->parent->projid_map);
}
static bool new_idmap_permitted(const struct file *file,
struct user_namespace *ns, int cap_setid,
struct uid_gid_map *new_map)
{
const struct cred *cred = file->f_cred;
if ((new_map->nr_extents == 1) && (new_map->extent[0].count == 1) &&
uid_eq(ns->owner, cred->euid)) {
u32 id = new_map->extent[0].lower_first;
if (cap_setid == CAP_SETUID) {
kuid_t uid = make_kuid(ns->parent, id);
if (uid_eq(uid, cred->euid))
return true;
} else if (cap_setid == CAP_SETGID) {
kgid_t gid = make_kgid(ns->parent, id);
if (!(ns->flags & USERNS_SETGROUPS_ALLOWED) &&
gid_eq(gid, cred->egid))
return true;
}
}
if (!cap_valid(cap_setid))
return true;
if (ns_capable(ns->parent, cap_setid) &&
file_ns_capable(file, ns->parent, cap_setid))
return true;
return false;
}
int proc_setgroups_show(struct seq_file *seq, void *v)
{
struct user_namespace *ns = seq->private;
unsigned long userns_flags = ACCESS_ONCE(ns->flags);
seq_printf(seq, "%s\n",
(userns_flags & USERNS_SETGROUPS_ALLOWED) ?
"allow" : "deny");
return 0;
}
ssize_t proc_setgroups_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct seq_file *seq = file->private_data;
struct user_namespace *ns = seq->private;
char kbuf[8], *pos;
bool setgroups_allowed;
ssize_t ret;
ret = -EINVAL;
if ((*ppos != 0) || (count >= sizeof(kbuf)))
goto out;
ret = -EFAULT;
if (copy_from_user(kbuf, buf, count))
goto out;
kbuf[count] = '\0';
pos = kbuf;
ret = -EINVAL;
if (strncmp(pos, "allow", 5) == 0) {
pos += 5;
setgroups_allowed = true;
}
else if (strncmp(pos, "deny", 4) == 0) {
pos += 4;
setgroups_allowed = false;
}
else
goto out;
pos = skip_spaces(pos);
if (*pos != '\0')
goto out;
ret = -EPERM;
mutex_lock(&userns_state_mutex);
if (setgroups_allowed) {
if (!(ns->flags & USERNS_SETGROUPS_ALLOWED))
goto out_unlock;
} else {
if (ns->gid_map.nr_extents != 0)
goto out_unlock;
ns->flags &= ~USERNS_SETGROUPS_ALLOWED;
}
mutex_unlock(&userns_state_mutex);
*ppos = count;
ret = count;
out:
return ret;
out_unlock:
mutex_unlock(&userns_state_mutex);
goto out;
}
bool userns_may_setgroups(const struct user_namespace *ns)
{
bool allowed;
mutex_lock(&userns_state_mutex);
allowed = ns->gid_map.nr_extents != 0;
allowed = allowed && (ns->flags & USERNS_SETGROUPS_ALLOWED);
mutex_unlock(&userns_state_mutex);
return allowed;
}
bool current_in_userns(const struct user_namespace *target_ns)
{
struct user_namespace *ns;
for (ns = current_user_ns(); ns; ns = ns->parent) {
if (ns == target_ns)
return true;
}
return false;
}
static inline struct user_namespace *to_user_ns(struct ns_common *ns)
{
return container_of(ns, struct user_namespace, ns);
}
static struct ns_common *userns_get(struct task_struct *task)
{
struct user_namespace *user_ns;
rcu_read_lock();
user_ns = get_user_ns(__task_cred(task)->user_ns);
rcu_read_unlock();
return user_ns ? &user_ns->ns : NULL;
}
static void userns_put(struct ns_common *ns)
{
put_user_ns(to_user_ns(ns));
}
static int userns_install(struct nsproxy *nsproxy, struct ns_common *ns)
{
struct user_namespace *user_ns = to_user_ns(ns);
struct cred *cred;
if (user_ns == current_user_ns())
return -EINVAL;
if (!thread_group_empty(current))
return -EINVAL;
if (current->fs->users != 1)
return -EINVAL;
if (!ns_capable(user_ns, CAP_SYS_ADMIN))
return -EPERM;
cred = prepare_creds();
if (!cred)
return -ENOMEM;
put_user_ns(cred->user_ns);
set_cred_user_ns(cred, get_user_ns(user_ns));
return commit_creds(cred);
}
static __init int user_namespaces_init(void)
{
user_ns_cachep = KMEM_CACHE(user_namespace, SLAB_PANIC);
return 0;
}
