static inline int avc_hash(u32 ssid, u32 tsid, u16 tclass)
{
return (ssid ^ (tsid<<2) ^ (tclass<<4)) & (AVC_CACHE_SLOTS - 1);
}
static void avc_dump_av(struct audit_buffer *ab, u16 tclass, u32 av)
{
const char **perms;
int i, perm;
if (av == 0) {
audit_log_format(ab, " null");
return;
}
perms = secclass_map[tclass-1].perms;
audit_log_format(ab, " {");
i = 0;
perm = 1;
while (i < (sizeof(av) * 8)) {
if ((perm & av) && perms[i]) {
audit_log_format(ab, " %s", perms[i]);
av &= ~perm;
}
i++;
perm <<= 1;
}
if (av)
audit_log_format(ab, " 0x%x", av);
audit_log_format(ab, " }");
}
static void avc_dump_query(struct audit_buffer *ab, u32 ssid, u32 tsid, u16 tclass)
{
int rc;
char *scontext;
u32 scontext_len;
rc = security_sid_to_context(ssid, &scontext, &scontext_len);
if (rc)
audit_log_format(ab, "ssid=%d", ssid);
else {
audit_log_format(ab, "scontext=%s", scontext);
kfree(scontext);
}
rc = security_sid_to_context(tsid, &scontext, &scontext_len);
if (rc)
audit_log_format(ab, " tsid=%d", tsid);
else {
audit_log_format(ab, " tcontext=%s", scontext);
kfree(scontext);
}
BUG_ON(tclass >= ARRAY_SIZE(secclass_map));
audit_log_format(ab, " tclass=%s", secclass_map[tclass-1].name);
}
void __init avc_init(void)
{
int i;
for (i = 0; i < AVC_CACHE_SLOTS; i++) {
INIT_HLIST_HEAD(&avc_cache.slots[i]);
spin_lock_init(&avc_cache.slots_lock[i]);
}
atomic_set(&avc_cache.active_nodes, 0);
atomic_set(&avc_cache.lru_hint, 0);
avc_node_cachep = kmem_cache_create("avc_node", sizeof(struct avc_node),
0, SLAB_PANIC, NULL);
audit_log(current->audit_context, GFP_KERNEL, AUDIT_KERNEL, "AVC INITIALIZED\n");
}
int avc_get_hash_stats(char *page)
{
int i, chain_len, max_chain_len, slots_used;
struct avc_node *node;
struct hlist_head *head;
rcu_read_lock();
slots_used = 0;
max_chain_len = 0;
for (i = 0; i < AVC_CACHE_SLOTS; i++) {
head = &avc_cache.slots[i];
if (!hlist_empty(head)) {
struct hlist_node *next;
slots_used++;
chain_len = 0;
hlist_for_each_entry_rcu(node, next, head, list)
chain_len++;
if (chain_len > max_chain_len)
max_chain_len = chain_len;
}
}
rcu_read_unlock();
return scnprintf(page, PAGE_SIZE, "entries: %d\nbuckets used: %d/%d\n"
"longest chain: %d\n",
atomic_read(&avc_cache.active_nodes),
slots_used, AVC_CACHE_SLOTS, max_chain_len);
}
static void avc_node_free(struct rcu_head *rhead)
{
struct avc_node *node = container_of(rhead, struct avc_node, rhead);
kmem_cache_free(avc_node_cachep, node);
avc_cache_stats_incr(frees);
}
static void avc_node_delete(struct avc_node *node)
{
hlist_del_rcu(&node->list);
call_rcu(&node->rhead, avc_node_free);
atomic_dec(&avc_cache.active_nodes);
}
static void avc_node_kill(struct avc_node *node)
{
kmem_cache_free(avc_node_cachep, node);
avc_cache_stats_incr(frees);
atomic_dec(&avc_cache.active_nodes);
}
static void avc_node_replace(struct avc_node *new, struct avc_node *old)
{
hlist_replace_rcu(&old->list, &new->list);
call_rcu(&old->rhead, avc_node_free);
atomic_dec(&avc_cache.active_nodes);
}
static inline int avc_reclaim_node(void)
{
struct avc_node *node;
int hvalue, try, ecx;
unsigned long flags;
struct hlist_head *head;
struct hlist_node *next;
spinlock_t *lock;
for (try = 0, ecx = 0; try < AVC_CACHE_SLOTS; try++) {
hvalue = atomic_inc_return(&avc_cache.lru_hint) & (AVC_CACHE_SLOTS - 1);
head = &avc_cache.slots[hvalue];
lock = &avc_cache.slots_lock[hvalue];
if (!spin_trylock_irqsave(lock, flags))
continue;
rcu_read_lock();
hlist_for_each_entry(node, next, head, list) {
avc_node_delete(node);
avc_cache_stats_incr(reclaims);
ecx++;
if (ecx >= AVC_CACHE_RECLAIM) {
rcu_read_unlock();
spin_unlock_irqrestore(lock, flags);
goto out;
}
}
rcu_read_unlock();
spin_unlock_irqrestore(lock, flags);
}
out:
return ecx;
}
static struct avc_node *avc_alloc_node(void)
{
struct avc_node *node;
node = kmem_cache_zalloc(avc_node_cachep, GFP_ATOMIC);
if (!node)
goto out;
INIT_HLIST_NODE(&node->list);
avc_cache_stats_incr(allocations);
if (atomic_inc_return(&avc_cache.active_nodes) > avc_cache_threshold)
avc_reclaim_node();
out:
return node;
}
static void avc_node_populate(struct avc_node *node, u32 ssid, u32 tsid, u16 tclass, struct av_decision *avd)
{
node->ae.ssid = ssid;
node->ae.tsid = tsid;
node->ae.tclass = tclass;
memcpy(&node->ae.avd, avd, sizeof(node->ae.avd));
}
static inline struct avc_node *avc_search_node(u32 ssid, u32 tsid, u16 tclass)
{
struct avc_node *node, *ret = NULL;
int hvalue;
struct hlist_head *head;
struct hlist_node *next;
hvalue = avc_hash(ssid, tsid, tclass);
head = &avc_cache.slots[hvalue];
hlist_for_each_entry_rcu(node, next, head, list) {
if (ssid == node->ae.ssid &&
tclass == node->ae.tclass &&
tsid == node->ae.tsid) {
ret = node;
break;
}
}
return ret;
}
static struct avc_node *avc_lookup(u32 ssid, u32 tsid, u16 tclass)
{
struct avc_node *node;
avc_cache_stats_incr(lookups);
node = avc_search_node(ssid, tsid, tclass);
if (node)
return node;
avc_cache_stats_incr(misses);
return NULL;
}
static int avc_latest_notif_update(int seqno, int is_insert)
{
int ret = 0;
static DEFINE_SPINLOCK(notif_lock);
unsigned long flag;
spin_lock_irqsave(&notif_lock, flag);
if (is_insert) {
if (seqno < avc_cache.latest_notif) {
printk(KERN_WARNING "SELinux: avc: seqno %d < latest_notif %d\n",
seqno, avc_cache.latest_notif);
ret = -EAGAIN;
}
} else {
if (seqno > avc_cache.latest_notif)
avc_cache.latest_notif = seqno;
}
spin_unlock_irqrestore(&notif_lock, flag);
return ret;
}
static struct avc_node *avc_insert(u32 ssid, u32 tsid, u16 tclass, struct av_decision *avd)
{
struct avc_node *pos, *node = NULL;
int hvalue;
unsigned long flag;
if (avc_latest_notif_update(avd->seqno, 1))
goto out;
node = avc_alloc_node();
if (node) {
struct hlist_head *head;
struct hlist_node *next;
spinlock_t *lock;
hvalue = avc_hash(ssid, tsid, tclass);
avc_node_populate(node, ssid, tsid, tclass, avd);
head = &avc_cache.slots[hvalue];
lock = &avc_cache.slots_lock[hvalue];
spin_lock_irqsave(lock, flag);
hlist_for_each_entry(pos, next, head, list) {
if (pos->ae.ssid == ssid &&
pos->ae.tsid == tsid &&
pos->ae.tclass == tclass) {
avc_node_replace(node, pos);
goto found;
}
}
hlist_add_head_rcu(&node->list, head);
found:
spin_unlock_irqrestore(lock, flag);
}
out:
return node;
}
static void avc_audit_pre_callback(struct audit_buffer *ab, void *a)
{
struct common_audit_data *ad = a;
audit_log_format(ab, "avc: %s ",
ad->selinux_audit_data.denied ? "denied" : "granted");
avc_dump_av(ab, ad->selinux_audit_data.tclass,
ad->selinux_audit_data.audited);
audit_log_format(ab, " for ");
}
static void avc_audit_post_callback(struct audit_buffer *ab, void *a)
{
struct common_audit_data *ad = a;
audit_log_format(ab, " ");
avc_dump_query(ab, ad->selinux_audit_data.ssid,
ad->selinux_audit_data.tsid,
ad->selinux_audit_data.tclass);
}
int avc_audit(u32 ssid, u32 tsid,
u16 tclass, u32 requested,
struct av_decision *avd, int result, struct common_audit_data *a,
unsigned flags)
{
struct common_audit_data stack_data;
u32 denied, audited;
denied = requested & ~avd->allowed;
if (denied) {
audited = denied & avd->auditdeny;
if (a &&
a->selinux_audit_data.auditdeny &&
!(a->selinux_audit_data.auditdeny & avd->auditdeny))
audited = 0;
} else if (result)
audited = denied = requested;
else
audited = requested & avd->auditallow;
if (!audited)
return 0;
if (!a) {
a = &stack_data;
COMMON_AUDIT_DATA_INIT(a, NONE);
}
if ((a->type == LSM_AUDIT_DATA_INODE) &&
(flags & MAY_NOT_BLOCK))
return -ECHILD;
a->selinux_audit_data.tclass = tclass;
a->selinux_audit_data.requested = requested;
a->selinux_audit_data.ssid = ssid;
a->selinux_audit_data.tsid = tsid;
a->selinux_audit_data.audited = audited;
a->selinux_audit_data.denied = denied;
a->lsm_pre_audit = avc_audit_pre_callback;
a->lsm_post_audit = avc_audit_post_callback;
common_lsm_audit(a);
return 0;
}
int avc_add_callback(int (*callback)(u32 event, u32 ssid, u32 tsid,
u16 tclass, u32 perms,
u32 *out_retained),
u32 events, u32 ssid, u32 tsid,
u16 tclass, u32 perms)
{
struct avc_callback_node *c;
int rc = 0;
c = kmalloc(sizeof(*c), GFP_ATOMIC);
if (!c) {
rc = -ENOMEM;
goto out;
}
c->callback = callback;
c->events = events;
c->ssid = ssid;
c->tsid = tsid;
c->perms = perms;
c->next = avc_callbacks;
avc_callbacks = c;
out:
return rc;
}
static inline int avc_sidcmp(u32 x, u32 y)
{
return (x == y || x == SECSID_WILD || y == SECSID_WILD);
}
static int avc_update_node(u32 event, u32 perms, u32 ssid, u32 tsid, u16 tclass,
u32 seqno)
{
int hvalue, rc = 0;
unsigned long flag;
struct avc_node *pos, *node, *orig = NULL;
struct hlist_head *head;
struct hlist_node *next;
spinlock_t *lock;
node = avc_alloc_node();
if (!node) {
rc = -ENOMEM;
goto out;
}
hvalue = avc_hash(ssid, tsid, tclass);
head = &avc_cache.slots[hvalue];
lock = &avc_cache.slots_lock[hvalue];
spin_lock_irqsave(lock, flag);
hlist_for_each_entry(pos, next, head, list) {
if (ssid == pos->ae.ssid &&
tsid == pos->ae.tsid &&
tclass == pos->ae.tclass &&
seqno == pos->ae.avd.seqno){
orig = pos;
break;
}
}
if (!orig) {
rc = -ENOENT;
avc_node_kill(node);
goto out_unlock;
}
avc_node_populate(node, ssid, tsid, tclass, &orig->ae.avd);
switch (event) {
case AVC_CALLBACK_GRANT:
node->ae.avd.allowed |= perms;
break;
case AVC_CALLBACK_TRY_REVOKE:
case AVC_CALLBACK_REVOKE:
node->ae.avd.allowed &= ~perms;
break;
case AVC_CALLBACK_AUDITALLOW_ENABLE:
node->ae.avd.auditallow |= perms;
break;
case AVC_CALLBACK_AUDITALLOW_DISABLE:
node->ae.avd.auditallow &= ~perms;
break;
case AVC_CALLBACK_AUDITDENY_ENABLE:
node->ae.avd.auditdeny |= perms;
break;
case AVC_CALLBACK_AUDITDENY_DISABLE:
node->ae.avd.auditdeny &= ~perms;
break;
}
avc_node_replace(node, orig);
out_unlock:
spin_unlock_irqrestore(lock, flag);
out:
return rc;
}
static void avc_flush(void)
{
struct hlist_head *head;
struct hlist_node *next;
struct avc_node *node;
spinlock_t *lock;
unsigned long flag;
int i;
for (i = 0; i < AVC_CACHE_SLOTS; i++) {
head = &avc_cache.slots[i];
lock = &avc_cache.slots_lock[i];
spin_lock_irqsave(lock, flag);
rcu_read_lock();
hlist_for_each_entry(node, next, head, list)
avc_node_delete(node);
rcu_read_unlock();
spin_unlock_irqrestore(lock, flag);
}
}
int avc_ss_reset(u32 seqno)
{
struct avc_callback_node *c;
int rc = 0, tmprc;
avc_flush();
for (c = avc_callbacks; c; c = c->next) {
if (c->events & AVC_CALLBACK_RESET) {
tmprc = c->callback(AVC_CALLBACK_RESET,
0, 0, 0, 0, NULL);
if (!rc)
rc = tmprc;
}
}
avc_latest_notif_update(seqno, 0);
return rc;
}
int avc_has_perm_noaudit(u32 ssid, u32 tsid,
u16 tclass, u32 requested,
unsigned flags,
struct av_decision *avd)
{
struct avc_node *node;
int rc = 0;
u32 denied;
BUG_ON(!requested);
rcu_read_lock();
node = avc_lookup(ssid, tsid, tclass);
if (unlikely(!node)) {
rcu_read_unlock();
security_compute_av(ssid, tsid, tclass, avd);
rcu_read_lock();
node = avc_insert(ssid, tsid, tclass, avd);
} else {
memcpy(avd, &node->ae.avd, sizeof(*avd));
avd = &node->ae.avd;
}
denied = requested & ~(avd->allowed);
if (denied) {
if (flags & AVC_STRICT)
rc = -EACCES;
else if (!selinux_enforcing || (avd->flags & AVD_FLAGS_PERMISSIVE))
avc_update_node(AVC_CALLBACK_GRANT, requested, ssid,
tsid, tclass, avd->seqno);
else
rc = -EACCES;
}
rcu_read_unlock();
return rc;
}
int avc_has_perm_flags(u32 ssid, u32 tsid, u16 tclass,
u32 requested, struct common_audit_data *auditdata,
unsigned flags)
{
struct av_decision avd;
int rc, rc2;
rc = avc_has_perm_noaudit(ssid, tsid, tclass, requested, 0, &avd);
rc2 = avc_audit(ssid, tsid, tclass, requested, &avd, rc, auditdata,
flags);
if (rc2)
return rc2;
return rc;
}
u32 avc_policy_seqno(void)
{
return avc_cache.latest_notif;
}
void avc_disable(void)
{
if (avc_node_cachep) {
avc_flush();
}
}
