static unsigned int sel_ib_pkey_hashfn(u16 pkey)
{
return (pkey & (SEL_PKEY_HASH_SIZE - 1));
}
static struct sel_ib_pkey *sel_ib_pkey_find(u64 subnet_prefix, u16 pkey_num)
{
unsigned int idx;
struct sel_ib_pkey *pkey;
idx = sel_ib_pkey_hashfn(pkey_num);
list_for_each_entry_rcu(pkey, &sel_ib_pkey_hash[idx].list, list) {
if (pkey->psec.pkey == pkey_num &&
pkey->psec.subnet_prefix == subnet_prefix)
return pkey;
}
return NULL;
}
static void sel_ib_pkey_insert(struct sel_ib_pkey *pkey)
{
unsigned int idx;
idx = sel_ib_pkey_hashfn(pkey->psec.pkey);
list_add_rcu(&pkey->list, &sel_ib_pkey_hash[idx].list);
if (sel_ib_pkey_hash[idx].size == SEL_PKEY_HASH_BKT_LIMIT) {
struct sel_ib_pkey *tail;
tail = list_entry(
rcu_dereference_protected(
sel_ib_pkey_hash[idx].list.prev,
lockdep_is_held(&sel_ib_pkey_lock)),
struct sel_ib_pkey, list);
list_del_rcu(&tail->list);
kfree_rcu(tail, rcu);
} else {
sel_ib_pkey_hash[idx].size++;
}
}
static int sel_ib_pkey_sid_slow(u64 subnet_prefix, u16 pkey_num, u32 *sid)
{
int ret;
struct sel_ib_pkey *pkey;
struct sel_ib_pkey *new = NULL;
unsigned long flags;
spin_lock_irqsave(&sel_ib_pkey_lock, flags);
pkey = sel_ib_pkey_find(subnet_prefix, pkey_num);
if (pkey) {
*sid = pkey->psec.sid;
spin_unlock_irqrestore(&sel_ib_pkey_lock, flags);
return 0;
}
ret = security_ib_pkey_sid(subnet_prefix, pkey_num, sid);
if (ret)
goto out;
new = kzalloc(sizeof(*new), GFP_ATOMIC);
if (!new)
goto out;
new->psec.subnet_prefix = subnet_prefix;
new->psec.pkey = pkey_num;
new->psec.sid = *sid;
sel_ib_pkey_insert(new);
out:
spin_unlock_irqrestore(&sel_ib_pkey_lock, flags);
return ret;
}
int sel_ib_pkey_sid(u64 subnet_prefix, u16 pkey_num, u32 *sid)
{
struct sel_ib_pkey *pkey;
rcu_read_lock();
pkey = sel_ib_pkey_find(subnet_prefix, pkey_num);
if (pkey) {
*sid = pkey->psec.sid;
rcu_read_unlock();
return 0;
}
rcu_read_unlock();
return sel_ib_pkey_sid_slow(subnet_prefix, pkey_num, sid);
}
void sel_ib_pkey_flush(void)
{
unsigned int idx;
struct sel_ib_pkey *pkey, *pkey_tmp;
unsigned long flags;
spin_lock_irqsave(&sel_ib_pkey_lock, flags);
for (idx = 0; idx < SEL_PKEY_HASH_SIZE; idx++) {
list_for_each_entry_safe(pkey, pkey_tmp,
&sel_ib_pkey_hash[idx].list, list) {
list_del_rcu(&pkey->list);
kfree_rcu(pkey, rcu);
}
sel_ib_pkey_hash[idx].size = 0;
}
spin_unlock_irqrestore(&sel_ib_pkey_lock, flags);
}
static __init int sel_ib_pkey_init(void)
{
int iter;
if (!selinux_enabled)
return 0;
for (iter = 0; iter < SEL_PKEY_HASH_SIZE; iter++) {
INIT_LIST_HEAD(&sel_ib_pkey_hash[iter].list);
sel_ib_pkey_hash[iter].size = 0;
}
return 0;
}
