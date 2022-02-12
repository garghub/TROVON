int xt_register_target(struct xt_target *target)
{
u_int8_t af = target->family;
mutex_lock(&xt[af].mutex);
list_add(&target->list, &xt[af].target);
mutex_unlock(&xt[af].mutex);
return 0;
}
void
xt_unregister_target(struct xt_target *target)
{
u_int8_t af = target->family;
mutex_lock(&xt[af].mutex);
list_del(&target->list);
mutex_unlock(&xt[af].mutex);
}
int
xt_register_targets(struct xt_target *target, unsigned int n)
{
unsigned int i;
int err = 0;
for (i = 0; i < n; i++) {
err = xt_register_target(&target[i]);
if (err)
goto err;
}
return err;
err:
if (i > 0)
xt_unregister_targets(target, i);
return err;
}
void
xt_unregister_targets(struct xt_target *target, unsigned int n)
{
while (n-- > 0)
xt_unregister_target(&target[n]);
}
int xt_register_match(struct xt_match *match)
{
u_int8_t af = match->family;
mutex_lock(&xt[af].mutex);
list_add(&match->list, &xt[af].match);
mutex_unlock(&xt[af].mutex);
return 0;
}
void
xt_unregister_match(struct xt_match *match)
{
u_int8_t af = match->family;
mutex_lock(&xt[af].mutex);
list_del(&match->list);
mutex_unlock(&xt[af].mutex);
}
int
xt_register_matches(struct xt_match *match, unsigned int n)
{
unsigned int i;
int err = 0;
for (i = 0; i < n; i++) {
err = xt_register_match(&match[i]);
if (err)
goto err;
}
return err;
err:
if (i > 0)
xt_unregister_matches(match, i);
return err;
}
void
xt_unregister_matches(struct xt_match *match, unsigned int n)
{
while (n-- > 0)
xt_unregister_match(&match[n]);
}
struct xt_match *xt_find_match(u8 af, const char *name, u8 revision)
{
struct xt_match *m;
int err = -ENOENT;
mutex_lock(&xt[af].mutex);
list_for_each_entry(m, &xt[af].match, list) {
if (strcmp(m->name, name) == 0) {
if (m->revision == revision) {
if (try_module_get(m->me)) {
mutex_unlock(&xt[af].mutex);
return m;
}
} else
err = -EPROTOTYPE;
}
}
mutex_unlock(&xt[af].mutex);
if (af != NFPROTO_UNSPEC)
return xt_find_match(NFPROTO_UNSPEC, name, revision);
return ERR_PTR(err);
}
struct xt_match *
xt_request_find_match(uint8_t nfproto, const char *name, uint8_t revision)
{
struct xt_match *match;
match = xt_find_match(nfproto, name, revision);
if (IS_ERR(match)) {
request_module("%st_%s", xt_prefix[nfproto], name);
match = xt_find_match(nfproto, name, revision);
}
return match;
}
struct xt_target *xt_find_target(u8 af, const char *name, u8 revision)
{
struct xt_target *t;
int err = -ENOENT;
mutex_lock(&xt[af].mutex);
list_for_each_entry(t, &xt[af].target, list) {
if (strcmp(t->name, name) == 0) {
if (t->revision == revision) {
if (try_module_get(t->me)) {
mutex_unlock(&xt[af].mutex);
return t;
}
} else
err = -EPROTOTYPE;
}
}
mutex_unlock(&xt[af].mutex);
if (af != NFPROTO_UNSPEC)
return xt_find_target(NFPROTO_UNSPEC, name, revision);
return ERR_PTR(err);
}
struct xt_target *xt_request_find_target(u8 af, const char *name, u8 revision)
{
struct xt_target *target;
target = xt_find_target(af, name, revision);
if (IS_ERR(target)) {
request_module("%st_%s", xt_prefix[af], name);
target = xt_find_target(af, name, revision);
}
return target;
}
static int xt_obj_to_user(u16 __user *psize, u16 size,
void __user *pname, const char *name,
u8 __user *prev, u8 rev)
{
if (put_user(size, psize))
return -EFAULT;
if (copy_to_user(pname, name, strlen(name) + 1))
return -EFAULT;
if (put_user(rev, prev))
return -EFAULT;
return 0;
}
int xt_data_to_user(void __user *dst, const void *src,
int usersize, int size, int aligned_size)
{
usersize = usersize ? : size;
if (copy_to_user(dst, src, usersize))
return -EFAULT;
if (usersize != aligned_size &&
clear_user(dst + usersize, aligned_size - usersize))
return -EFAULT;
return 0;
}
int xt_match_to_user(const struct xt_entry_match *m,
struct xt_entry_match __user *u)
{
return XT_OBJ_TO_USER(u, m, match, 0) ||
XT_DATA_TO_USER(u, m, match);
}
int xt_target_to_user(const struct xt_entry_target *t,
struct xt_entry_target __user *u)
{
return XT_OBJ_TO_USER(u, t, target, 0) ||
XT_DATA_TO_USER(u, t, target);
}
static int match_revfn(u8 af, const char *name, u8 revision, int *bestp)
{
const struct xt_match *m;
int have_rev = 0;
list_for_each_entry(m, &xt[af].match, list) {
if (strcmp(m->name, name) == 0) {
if (m->revision > *bestp)
*bestp = m->revision;
if (m->revision == revision)
have_rev = 1;
}
}
if (af != NFPROTO_UNSPEC && !have_rev)
return match_revfn(NFPROTO_UNSPEC, name, revision, bestp);
return have_rev;
}
static int target_revfn(u8 af, const char *name, u8 revision, int *bestp)
{
const struct xt_target *t;
int have_rev = 0;
list_for_each_entry(t, &xt[af].target, list) {
if (strcmp(t->name, name) == 0) {
if (t->revision > *bestp)
*bestp = t->revision;
if (t->revision == revision)
have_rev = 1;
}
}
if (af != NFPROTO_UNSPEC && !have_rev)
return target_revfn(NFPROTO_UNSPEC, name, revision, bestp);
return have_rev;
}
int xt_find_revision(u8 af, const char *name, u8 revision, int target,
int *err)
{
int have_rev, best = -1;
mutex_lock(&xt[af].mutex);
if (target == 1)
have_rev = target_revfn(af, name, revision, &best);
else
have_rev = match_revfn(af, name, revision, &best);
mutex_unlock(&xt[af].mutex);
if (best == -1) {
*err = -ENOENT;
return 0;
}
*err = best;
if (!have_rev)
*err = -EPROTONOSUPPORT;
return 1;
}
static char *
textify_hooks(char *buf, size_t size, unsigned int mask, uint8_t nfproto)
{
static const char *const inetbr_names[] = {
"PREROUTING", "INPUT", "FORWARD",
"OUTPUT", "POSTROUTING", "BROUTING",
};
static const char *const arp_names[] = {
"INPUT", "FORWARD", "OUTPUT",
};
const char *const *names;
unsigned int i, max;
char *p = buf;
bool np = false;
int res;
names = (nfproto == NFPROTO_ARP) ? arp_names : inetbr_names;
max = (nfproto == NFPROTO_ARP) ? ARRAY_SIZE(arp_names) :
ARRAY_SIZE(inetbr_names);
*p = '\0';
for (i = 0; i < max; ++i) {
if (!(mask & (1 << i)))
continue;
res = snprintf(p, size, "%s%s", np ? "/" : "", names[i]);
if (res > 0) {
size -= res;
p += res;
}
np = true;
}
return buf;
}
int xt_check_match(struct xt_mtchk_param *par,
unsigned int size, u_int8_t proto, bool inv_proto)
{
int ret;
if (XT_ALIGN(par->match->matchsize) != size &&
par->match->matchsize != -1) {
pr_err("%s_tables: %s.%u match: invalid size "
"%u (kernel) != (user) %u\n",
xt_prefix[par->family], par->match->name,
par->match->revision,
XT_ALIGN(par->match->matchsize), size);
return -EINVAL;
}
if (par->match->table != NULL &&
strcmp(par->match->table, par->table) != 0) {
pr_err("%s_tables: %s match: only valid in %s table, not %s\n",
xt_prefix[par->family], par->match->name,
par->match->table, par->table);
return -EINVAL;
}
if (par->match->hooks && (par->hook_mask & ~par->match->hooks) != 0) {
char used[64], allow[64];
pr_err("%s_tables: %s match: used from hooks %s, but only "
"valid from %s\n",
xt_prefix[par->family], par->match->name,
textify_hooks(used, sizeof(used), par->hook_mask,
par->family),
textify_hooks(allow, sizeof(allow), par->match->hooks,
par->family));
return -EINVAL;
}
if (par->match->proto && (par->match->proto != proto || inv_proto)) {
pr_err("%s_tables: %s match: only valid for protocol %u\n",
xt_prefix[par->family], par->match->name,
par->match->proto);
return -EINVAL;
}
if (par->match->checkentry != NULL) {
ret = par->match->checkentry(par);
if (ret < 0)
return ret;
else if (ret > 0)
return -EIO;
}
return 0;
}
static int xt_check_entry_match(const char *match, const char *target,
const size_t alignment)
{
const struct xt_entry_match *pos;
int length = target - match;
if (length == 0)
return 0;
pos = (struct xt_entry_match *)match;
do {
if ((unsigned long)pos % alignment)
return -EINVAL;
if (length < (int)sizeof(struct xt_entry_match))
return -EINVAL;
if (pos->u.match_size < sizeof(struct xt_entry_match))
return -EINVAL;
if (pos->u.match_size > length)
return -EINVAL;
length -= pos->u.match_size;
pos = ((void *)((char *)(pos) + (pos)->u.match_size));
} while (length > 0);
return 0;
}
int xt_compat_add_offset(u_int8_t af, unsigned int offset, int delta)
{
struct xt_af *xp = &xt[af];
if (!xp->compat_tab) {
if (!xp->number)
return -EINVAL;
xp->compat_tab = vmalloc(sizeof(struct compat_delta) * xp->number);
if (!xp->compat_tab)
return -ENOMEM;
xp->cur = 0;
}
if (xp->cur >= xp->number)
return -EINVAL;
if (xp->cur)
delta += xp->compat_tab[xp->cur - 1].delta;
xp->compat_tab[xp->cur].offset = offset;
xp->compat_tab[xp->cur].delta = delta;
xp->cur++;
return 0;
}
void xt_compat_flush_offsets(u_int8_t af)
{
if (xt[af].compat_tab) {
vfree(xt[af].compat_tab);
xt[af].compat_tab = NULL;
xt[af].number = 0;
xt[af].cur = 0;
}
}
int xt_compat_calc_jump(u_int8_t af, unsigned int offset)
{
struct compat_delta *tmp = xt[af].compat_tab;
int mid, left = 0, right = xt[af].cur - 1;
while (left <= right) {
mid = (left + right) >> 1;
if (offset > tmp[mid].offset)
left = mid + 1;
else if (offset < tmp[mid].offset)
right = mid - 1;
else
return mid ? tmp[mid - 1].delta : 0;
}
return left ? tmp[left - 1].delta : 0;
}
void xt_compat_init_offsets(u_int8_t af, unsigned int number)
{
xt[af].number = number;
xt[af].cur = 0;
}
int xt_compat_match_offset(const struct xt_match *match)
{
u_int16_t csize = match->compatsize ? : match->matchsize;
return XT_ALIGN(match->matchsize) - COMPAT_XT_ALIGN(csize);
}
void xt_compat_match_from_user(struct xt_entry_match *m, void **dstptr,
unsigned int *size)
{
const struct xt_match *match = m->u.kernel.match;
struct compat_xt_entry_match *cm = (struct compat_xt_entry_match *)m;
int pad, off = xt_compat_match_offset(match);
u_int16_t msize = cm->u.user.match_size;
char name[sizeof(m->u.user.name)];
m = *dstptr;
memcpy(m, cm, sizeof(*cm));
if (match->compat_from_user)
match->compat_from_user(m->data, cm->data);
else
memcpy(m->data, cm->data, msize - sizeof(*cm));
pad = XT_ALIGN(match->matchsize) - match->matchsize;
if (pad > 0)
memset(m->data + match->matchsize, 0, pad);
msize += off;
m->u.user.match_size = msize;
strlcpy(name, match->name, sizeof(name));
module_put(match->me);
strncpy(m->u.user.name, name, sizeof(m->u.user.name));
*size += off;
*dstptr += msize;
}
int xt_compat_match_to_user(const struct xt_entry_match *m,
void __user **dstptr, unsigned int *size)
{
const struct xt_match *match = m->u.kernel.match;
struct compat_xt_entry_match __user *cm = *dstptr;
int off = xt_compat_match_offset(match);
u_int16_t msize = m->u.user.match_size - off;
if (XT_OBJ_TO_USER(cm, m, match, msize))
return -EFAULT;
if (match->compat_to_user) {
if (match->compat_to_user((void __user *)cm->data, m->data))
return -EFAULT;
} else {
if (COMPAT_XT_DATA_TO_USER(cm, m, match, msize - sizeof(*cm)))
return -EFAULT;
}
*size -= off;
*dstptr += msize;
return 0;
}
int xt_compat_check_entry_offsets(const void *base, const char *elems,
unsigned int target_offset,
unsigned int next_offset)
{
long size_of_base_struct = elems - (const char *)base;
const struct compat_xt_entry_target *t;
const char *e = base;
if (target_offset < size_of_base_struct)
return -EINVAL;
if (target_offset + sizeof(*t) > next_offset)
return -EINVAL;
t = (void *)(e + target_offset);
if (t->u.target_size < sizeof(*t))
return -EINVAL;
if (target_offset + t->u.target_size > next_offset)
return -EINVAL;
if (strcmp(t->u.user.name, XT_STANDARD_TARGET) == 0 &&
COMPAT_XT_ALIGN(target_offset + sizeof(struct compat_xt_standard_target)) != next_offset)
return -EINVAL;
BUILD_BUG_ON(sizeof(struct compat_xt_entry_match) != sizeof(struct xt_entry_match));
return xt_check_entry_match(elems, base + target_offset,
__alignof__(struct compat_xt_entry_match));
}
int xt_check_entry_offsets(const void *base,
const char *elems,
unsigned int target_offset,
unsigned int next_offset)
{
long size_of_base_struct = elems - (const char *)base;
const struct xt_entry_target *t;
const char *e = base;
if (target_offset < size_of_base_struct)
return -EINVAL;
if (target_offset + sizeof(*t) > next_offset)
return -EINVAL;
t = (void *)(e + target_offset);
if (t->u.target_size < sizeof(*t))
return -EINVAL;
if (target_offset + t->u.target_size > next_offset)
return -EINVAL;
if (strcmp(t->u.user.name, XT_STANDARD_TARGET) == 0 &&
XT_ALIGN(target_offset + sizeof(struct xt_standard_target)) != next_offset)
return -EINVAL;
return xt_check_entry_match(elems, base + target_offset,
__alignof__(struct xt_entry_match));
}
unsigned int *xt_alloc_entry_offsets(unsigned int size)
{
return kvmalloc_array(size, sizeof(unsigned int), GFP_KERNEL | __GFP_ZERO);
}
bool xt_find_jump_offset(const unsigned int *offsets,
unsigned int target, unsigned int size)
{
int m, low = 0, hi = size;
while (hi > low) {
m = (low + hi) / 2u;
if (offsets[m] > target)
hi = m;
else if (offsets[m] < target)
low = m + 1;
else
return true;
}
return false;
}
int xt_check_target(struct xt_tgchk_param *par,
unsigned int size, u_int8_t proto, bool inv_proto)
{
int ret;
if (XT_ALIGN(par->target->targetsize) != size) {
pr_err("%s_tables: %s.%u target: invalid size "
"%u (kernel) != (user) %u\n",
xt_prefix[par->family], par->target->name,
par->target->revision,
XT_ALIGN(par->target->targetsize), size);
return -EINVAL;
}
if (par->target->table != NULL &&
strcmp(par->target->table, par->table) != 0) {
pr_err("%s_tables: %s target: only valid in %s table, not %s\n",
xt_prefix[par->family], par->target->name,
par->target->table, par->table);
return -EINVAL;
}
if (par->target->hooks && (par->hook_mask & ~par->target->hooks) != 0) {
char used[64], allow[64];
pr_err("%s_tables: %s target: used from hooks %s, but only "
"usable from %s\n",
xt_prefix[par->family], par->target->name,
textify_hooks(used, sizeof(used), par->hook_mask,
par->family),
textify_hooks(allow, sizeof(allow), par->target->hooks,
par->family));
return -EINVAL;
}
if (par->target->proto && (par->target->proto != proto || inv_proto)) {
pr_err("%s_tables: %s target: only valid for protocol %u\n",
xt_prefix[par->family], par->target->name,
par->target->proto);
return -EINVAL;
}
if (par->target->checkentry != NULL) {
ret = par->target->checkentry(par);
if (ret < 0)
return ret;
else if (ret > 0)
return -EIO;
}
return 0;
}
void *xt_copy_counters_from_user(const void __user *user, unsigned int len,
struct xt_counters_info *info, bool compat)
{
void *mem;
u64 size;
#ifdef CONFIG_COMPAT
if (compat) {
struct compat_xt_counters_info compat_tmp;
if (len <= sizeof(compat_tmp))
return ERR_PTR(-EINVAL);
len -= sizeof(compat_tmp);
if (copy_from_user(&compat_tmp, user, sizeof(compat_tmp)) != 0)
return ERR_PTR(-EFAULT);
strlcpy(info->name, compat_tmp.name, sizeof(info->name));
info->num_counters = compat_tmp.num_counters;
user += sizeof(compat_tmp);
} else
#endif
{
if (len <= sizeof(*info))
return ERR_PTR(-EINVAL);
len -= sizeof(*info);
if (copy_from_user(info, user, sizeof(*info)) != 0)
return ERR_PTR(-EFAULT);
info->name[sizeof(info->name) - 1] = '\0';
user += sizeof(*info);
}
size = sizeof(struct xt_counters);
size *= info->num_counters;
if (size != (u64)len)
return ERR_PTR(-EINVAL);
mem = vmalloc(len);
if (!mem)
return ERR_PTR(-ENOMEM);
if (copy_from_user(mem, user, len) == 0)
return mem;
vfree(mem);
return ERR_PTR(-EFAULT);
}
int xt_compat_target_offset(const struct xt_target *target)
{
u_int16_t csize = target->compatsize ? : target->targetsize;
return XT_ALIGN(target->targetsize) - COMPAT_XT_ALIGN(csize);
}
void xt_compat_target_from_user(struct xt_entry_target *t, void **dstptr,
unsigned int *size)
{
const struct xt_target *target = t->u.kernel.target;
struct compat_xt_entry_target *ct = (struct compat_xt_entry_target *)t;
int pad, off = xt_compat_target_offset(target);
u_int16_t tsize = ct->u.user.target_size;
char name[sizeof(t->u.user.name)];
t = *dstptr;
memcpy(t, ct, sizeof(*ct));
if (target->compat_from_user)
target->compat_from_user(t->data, ct->data);
else
memcpy(t->data, ct->data, tsize - sizeof(*ct));
pad = XT_ALIGN(target->targetsize) - target->targetsize;
if (pad > 0)
memset(t->data + target->targetsize, 0, pad);
tsize += off;
t->u.user.target_size = tsize;
strlcpy(name, target->name, sizeof(name));
module_put(target->me);
strncpy(t->u.user.name, name, sizeof(t->u.user.name));
*size += off;
*dstptr += tsize;
}
int xt_compat_target_to_user(const struct xt_entry_target *t,
void __user **dstptr, unsigned int *size)
{
const struct xt_target *target = t->u.kernel.target;
struct compat_xt_entry_target __user *ct = *dstptr;
int off = xt_compat_target_offset(target);
u_int16_t tsize = t->u.user.target_size - off;
if (XT_OBJ_TO_USER(ct, t, target, tsize))
return -EFAULT;
if (target->compat_to_user) {
if (target->compat_to_user((void __user *)ct->data, t->data))
return -EFAULT;
} else {
if (COMPAT_XT_DATA_TO_USER(ct, t, target, tsize - sizeof(*ct)))
return -EFAULT;
}
*size -= off;
*dstptr += tsize;
return 0;
}
struct xt_table_info *xt_alloc_table_info(unsigned int size)
{
struct xt_table_info *info = NULL;
size_t sz = sizeof(*info) + size;
if (sz < sizeof(*info))
return NULL;
if ((SMP_ALIGN(size) >> PAGE_SHIFT) + 2 > totalram_pages)
return NULL;
if (sz <= (PAGE_SIZE << PAGE_ALLOC_COSTLY_ORDER))
info = kmalloc(sz, GFP_KERNEL | __GFP_NOWARN | __GFP_NORETRY);
if (!info) {
info = __vmalloc(sz, GFP_KERNEL | __GFP_NOWARN | __GFP_NORETRY,
PAGE_KERNEL);
if (!info)
return NULL;
}
memset(info, 0, sizeof(*info));
info->size = size;
return info;
}
void xt_free_table_info(struct xt_table_info *info)
{
int cpu;
if (info->jumpstack != NULL) {
for_each_possible_cpu(cpu)
kvfree(info->jumpstack[cpu]);
kvfree(info->jumpstack);
}
kvfree(info);
}
struct xt_table *xt_find_table_lock(struct net *net, u_int8_t af,
const char *name)
{
struct xt_table *t, *found = NULL;
mutex_lock(&xt[af].mutex);
list_for_each_entry(t, &net->xt.tables[af], list)
if (strcmp(t->name, name) == 0 && try_module_get(t->me))
return t;
if (net == &init_net)
goto out;
list_for_each_entry(t, &init_net.xt.tables[af], list) {
if (strcmp(t->name, name))
continue;
if (!try_module_get(t->me)) {
mutex_unlock(&xt[af].mutex);
return NULL;
}
mutex_unlock(&xt[af].mutex);
if (t->table_init(net) != 0) {
module_put(t->me);
return NULL;
}
found = t;
mutex_lock(&xt[af].mutex);
break;
}
if (!found)
goto out;
list_for_each_entry(t, &net->xt.tables[af], list)
if (strcmp(t->name, name) == 0)
return t;
module_put(found->me);
out:
mutex_unlock(&xt[af].mutex);
return NULL;
}
void xt_table_unlock(struct xt_table *table)
{
mutex_unlock(&xt[table->af].mutex);
}
void xt_compat_lock(u_int8_t af)
{
mutex_lock(&xt[af].compat_mutex);
}
void xt_compat_unlock(u_int8_t af)
{
mutex_unlock(&xt[af].compat_mutex);
}
static int xt_jumpstack_alloc(struct xt_table_info *i)
{
unsigned int size;
int cpu;
size = sizeof(void **) * nr_cpu_ids;
if (size > PAGE_SIZE)
i->jumpstack = kvzalloc(size, GFP_KERNEL);
else
i->jumpstack = kzalloc(size, GFP_KERNEL);
if (i->jumpstack == NULL)
return -ENOMEM;
if (i->stacksize == 0)
return 0;
size = sizeof(void *) * i->stacksize * 2u;
for_each_possible_cpu(cpu) {
i->jumpstack[cpu] = kvmalloc_node(size, GFP_KERNEL,
cpu_to_node(cpu));
if (i->jumpstack[cpu] == NULL)
return -ENOMEM;
}
return 0;
}
struct xt_table_info *
xt_replace_table(struct xt_table *table,
unsigned int num_counters,
struct xt_table_info *newinfo,
int *error)
{
struct xt_table_info *private;
int ret;
ret = xt_jumpstack_alloc(newinfo);
if (ret < 0) {
*error = ret;
return NULL;
}
local_bh_disable();
private = table->private;
if (num_counters != private->number) {
pr_debug("num_counters != table->private->number (%u/%u)\n",
num_counters, private->number);
local_bh_enable();
*error = -EAGAIN;
return NULL;
}
newinfo->initial_entries = private->initial_entries;
smp_wmb();
table->private = newinfo;
local_bh_enable();
#ifdef CONFIG_AUDIT
if (audit_enabled) {
struct audit_buffer *ab;
ab = audit_log_start(current->audit_context, GFP_KERNEL,
AUDIT_NETFILTER_CFG);
if (ab) {
audit_log_format(ab, "table=%s family=%u entries=%u",
table->name, table->af,
private->number);
audit_log_end(ab);
}
}
#endif
return private;
}
struct xt_table *xt_register_table(struct net *net,
const struct xt_table *input_table,
struct xt_table_info *bootstrap,
struct xt_table_info *newinfo)
{
int ret;
struct xt_table_info *private;
struct xt_table *t, *table;
table = kmemdup(input_table, sizeof(struct xt_table), GFP_KERNEL);
if (!table) {
ret = -ENOMEM;
goto out;
}
mutex_lock(&xt[table->af].mutex);
list_for_each_entry(t, &net->xt.tables[table->af], list) {
if (strcmp(t->name, table->name) == 0) {
ret = -EEXIST;
goto unlock;
}
}
table->private = bootstrap;
if (!xt_replace_table(table, 0, newinfo, &ret))
goto unlock;
private = table->private;
pr_debug("table->private->number = %u\n", private->number);
private->initial_entries = private->number;
list_add(&table->list, &net->xt.tables[table->af]);
mutex_unlock(&xt[table->af].mutex);
return table;
unlock:
mutex_unlock(&xt[table->af].mutex);
kfree(table);
out:
return ERR_PTR(ret);
}
void *xt_unregister_table(struct xt_table *table)
{
struct xt_table_info *private;
mutex_lock(&xt[table->af].mutex);
private = table->private;
list_del(&table->list);
mutex_unlock(&xt[table->af].mutex);
kfree(table);
return private;
}
static void *xt_table_seq_start(struct seq_file *seq, loff_t *pos)
{
struct xt_names_priv *priv = seq->private;
struct net *net = seq_file_net(seq);
u_int8_t af = priv->af;
mutex_lock(&xt[af].mutex);
return seq_list_start(&net->xt.tables[af], *pos);
}
static void *xt_table_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct xt_names_priv *priv = seq->private;
struct net *net = seq_file_net(seq);
u_int8_t af = priv->af;
return seq_list_next(v, &net->xt.tables[af], pos);
}
static void xt_table_seq_stop(struct seq_file *seq, void *v)
{
struct xt_names_priv *priv = seq->private;
u_int8_t af = priv->af;
mutex_unlock(&xt[af].mutex);
}
static int xt_table_seq_show(struct seq_file *seq, void *v)
{
struct xt_table *table = list_entry(v, struct xt_table, list);
if (*table->name)
seq_printf(seq, "%s\n", table->name);
return 0;
}
static int xt_table_open(struct inode *inode, struct file *file)
{
int ret;
struct xt_names_priv *priv;
ret = seq_open_net(inode, file, &xt_table_seq_ops,
sizeof(struct xt_names_priv));
if (!ret) {
priv = ((struct seq_file *)file->private_data)->private;
priv->af = (unsigned long)PDE_DATA(inode);
}
return ret;
}
static void *xt_mttg_seq_next(struct seq_file *seq, void *v, loff_t *ppos,
bool is_target)
{
static const uint8_t next_class[] = {
[MTTG_TRAV_NFP_UNSPEC] = MTTG_TRAV_NFP_SPEC,
[MTTG_TRAV_NFP_SPEC] = MTTG_TRAV_DONE,
};
struct nf_mttg_trav *trav = seq->private;
switch (trav->class) {
case MTTG_TRAV_INIT:
trav->class = MTTG_TRAV_NFP_UNSPEC;
mutex_lock(&xt[NFPROTO_UNSPEC].mutex);
trav->head = trav->curr = is_target ?
&xt[NFPROTO_UNSPEC].target : &xt[NFPROTO_UNSPEC].match;
break;
case MTTG_TRAV_NFP_UNSPEC:
trav->curr = trav->curr->next;
if (trav->curr != trav->head)
break;
mutex_unlock(&xt[NFPROTO_UNSPEC].mutex);
mutex_lock(&xt[trav->nfproto].mutex);
trav->head = trav->curr = is_target ?
&xt[trav->nfproto].target : &xt[trav->nfproto].match;
trav->class = next_class[trav->class];
break;
case MTTG_TRAV_NFP_SPEC:
trav->curr = trav->curr->next;
if (trav->curr != trav->head)
break;
default:
return NULL;
}
if (ppos != NULL)
++*ppos;
return trav;
}
static void *xt_mttg_seq_start(struct seq_file *seq, loff_t *pos,
bool is_target)
{
struct nf_mttg_trav *trav = seq->private;
unsigned int j;
trav->class = MTTG_TRAV_INIT;
for (j = 0; j < *pos; ++j)
if (xt_mttg_seq_next(seq, NULL, NULL, is_target) == NULL)
return NULL;
return trav;
}
static void xt_mttg_seq_stop(struct seq_file *seq, void *v)
{
struct nf_mttg_trav *trav = seq->private;
switch (trav->class) {
case MTTG_TRAV_NFP_UNSPEC:
mutex_unlock(&xt[NFPROTO_UNSPEC].mutex);
break;
case MTTG_TRAV_NFP_SPEC:
mutex_unlock(&xt[trav->nfproto].mutex);
break;
}
}
static void *xt_match_seq_start(struct seq_file *seq, loff_t *pos)
{
return xt_mttg_seq_start(seq, pos, false);
}
static void *xt_match_seq_next(struct seq_file *seq, void *v, loff_t *ppos)
{
return xt_mttg_seq_next(seq, v, ppos, false);
}
static int xt_match_seq_show(struct seq_file *seq, void *v)
{
const struct nf_mttg_trav *trav = seq->private;
const struct xt_match *match;
switch (trav->class) {
case MTTG_TRAV_NFP_UNSPEC:
case MTTG_TRAV_NFP_SPEC:
if (trav->curr == trav->head)
return 0;
match = list_entry(trav->curr, struct xt_match, list);
if (*match->name)
seq_printf(seq, "%s\n", match->name);
}
return 0;
}
static int xt_match_open(struct inode *inode, struct file *file)
{
struct nf_mttg_trav *trav;
trav = __seq_open_private(file, &xt_match_seq_ops, sizeof(*trav));
if (!trav)
return -ENOMEM;
trav->nfproto = (unsigned long)PDE_DATA(inode);
return 0;
}
static void *xt_target_seq_start(struct seq_file *seq, loff_t *pos)
{
return xt_mttg_seq_start(seq, pos, true);
}
static void *xt_target_seq_next(struct seq_file *seq, void *v, loff_t *ppos)
{
return xt_mttg_seq_next(seq, v, ppos, true);
}
static int xt_target_seq_show(struct seq_file *seq, void *v)
{
const struct nf_mttg_trav *trav = seq->private;
const struct xt_target *target;
switch (trav->class) {
case MTTG_TRAV_NFP_UNSPEC:
case MTTG_TRAV_NFP_SPEC:
if (trav->curr == trav->head)
return 0;
target = list_entry(trav->curr, struct xt_target, list);
if (*target->name)
seq_printf(seq, "%s\n", target->name);
}
return 0;
}
static int xt_target_open(struct inode *inode, struct file *file)
{
struct nf_mttg_trav *trav;
trav = __seq_open_private(file, &xt_target_seq_ops, sizeof(*trav));
if (!trav)
return -ENOMEM;
trav->nfproto = (unsigned long)PDE_DATA(inode);
return 0;
}
struct nf_hook_ops *
xt_hook_ops_alloc(const struct xt_table *table, nf_hookfn *fn)
{
unsigned int hook_mask = table->valid_hooks;
uint8_t i, num_hooks = hweight32(hook_mask);
uint8_t hooknum;
struct nf_hook_ops *ops;
if (!num_hooks)
return ERR_PTR(-EINVAL);
ops = kcalloc(num_hooks, sizeof(*ops), GFP_KERNEL);
if (ops == NULL)
return ERR_PTR(-ENOMEM);
for (i = 0, hooknum = 0; i < num_hooks && hook_mask != 0;
hook_mask >>= 1, ++hooknum) {
if (!(hook_mask & 1))
continue;
ops[i].hook = fn;
ops[i].pf = table->af;
ops[i].hooknum = hooknum;
ops[i].priority = table->priority;
++i;
}
return ops;
}
int xt_proto_init(struct net *net, u_int8_t af)
{
#ifdef CONFIG_PROC_FS
char buf[XT_FUNCTION_MAXNAMELEN];
struct proc_dir_entry *proc;
kuid_t root_uid;
kgid_t root_gid;
#endif
if (af >= ARRAY_SIZE(xt_prefix))
return -EINVAL;
#ifdef CONFIG_PROC_FS
root_uid = make_kuid(net->user_ns, 0);
root_gid = make_kgid(net->user_ns, 0);
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_TABLES, sizeof(buf));
proc = proc_create_data(buf, 0440, net->proc_net, &xt_table_ops,
(void *)(unsigned long)af);
if (!proc)
goto out;
if (uid_valid(root_uid) && gid_valid(root_gid))
proc_set_user(proc, root_uid, root_gid);
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_MATCHES, sizeof(buf));
proc = proc_create_data(buf, 0440, net->proc_net, &xt_match_ops,
(void *)(unsigned long)af);
if (!proc)
goto out_remove_tables;
if (uid_valid(root_uid) && gid_valid(root_gid))
proc_set_user(proc, root_uid, root_gid);
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_TARGETS, sizeof(buf));
proc = proc_create_data(buf, 0440, net->proc_net, &xt_target_ops,
(void *)(unsigned long)af);
if (!proc)
goto out_remove_matches;
if (uid_valid(root_uid) && gid_valid(root_gid))
proc_set_user(proc, root_uid, root_gid);
#endif
return 0;
#ifdef CONFIG_PROC_FS
out_remove_matches:
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_MATCHES, sizeof(buf));
remove_proc_entry(buf, net->proc_net);
out_remove_tables:
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_TABLES, sizeof(buf));
remove_proc_entry(buf, net->proc_net);
out:
return -1;
#endif
}
void xt_proto_fini(struct net *net, u_int8_t af)
{
#ifdef CONFIG_PROC_FS
char buf[XT_FUNCTION_MAXNAMELEN];
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_TABLES, sizeof(buf));
remove_proc_entry(buf, net->proc_net);
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_TARGETS, sizeof(buf));
remove_proc_entry(buf, net->proc_net);
strlcpy(buf, xt_prefix[af], sizeof(buf));
strlcat(buf, FORMAT_MATCHES, sizeof(buf));
remove_proc_entry(buf, net->proc_net);
#endif
}
bool xt_percpu_counter_alloc(struct xt_percpu_counter_alloc_state *state,
struct xt_counters *counter)
{
BUILD_BUG_ON(XT_PCPU_BLOCK_SIZE < (sizeof(*counter) * 2));
if (nr_cpu_ids <= 1)
return true;
if (!state->mem) {
state->mem = __alloc_percpu(XT_PCPU_BLOCK_SIZE,
XT_PCPU_BLOCK_SIZE);
if (!state->mem)
return false;
}
counter->pcnt = (__force unsigned long)(state->mem + state->off);
state->off += sizeof(*counter);
if (state->off > (XT_PCPU_BLOCK_SIZE - sizeof(*counter))) {
state->mem = NULL;
state->off = 0;
}
return true;
}
void xt_percpu_counter_free(struct xt_counters *counters)
{
unsigned long pcnt = counters->pcnt;
if (nr_cpu_ids > 1 && (pcnt & (XT_PCPU_BLOCK_SIZE - 1)) == 0)
free_percpu((void __percpu *)pcnt);
}
static int __net_init xt_net_init(struct net *net)
{
int i;
for (i = 0; i < NFPROTO_NUMPROTO; i++)
INIT_LIST_HEAD(&net->xt.tables[i]);
return 0;
}
static int __init xt_init(void)
{
unsigned int i;
int rv;
for_each_possible_cpu(i) {
seqcount_init(&per_cpu(xt_recseq, i));
}
xt = kmalloc(sizeof(struct xt_af) * NFPROTO_NUMPROTO, GFP_KERNEL);
if (!xt)
return -ENOMEM;
for (i = 0; i < NFPROTO_NUMPROTO; i++) {
mutex_init(&xt[i].mutex);
#ifdef CONFIG_COMPAT
mutex_init(&xt[i].compat_mutex);
xt[i].compat_tab = NULL;
#endif
INIT_LIST_HEAD(&xt[i].target);
INIT_LIST_HEAD(&xt[i].match);
}
rv = register_pernet_subsys(&xt_net_ops);
if (rv < 0)
kfree(xt);
return rv;
}
static void __exit xt_fini(void)
{
unregister_pernet_subsys(&xt_net_ops);
kfree(xt);
}
