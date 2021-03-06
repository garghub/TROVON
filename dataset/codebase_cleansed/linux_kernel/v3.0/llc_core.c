static struct llc_sap *llc_sap_alloc(void)
{
struct llc_sap *sap = kzalloc(sizeof(*sap), GFP_ATOMIC);
int i;
if (sap) {
sap->state = LLC_SAP_STATE_ACTIVE;
spin_lock_init(&sap->sk_lock);
for (i = 0; i < LLC_SK_LADDR_HASH_ENTRIES; i++)
INIT_HLIST_NULLS_HEAD(&sap->sk_laddr_hash[i], i);
atomic_set(&sap->refcnt, 1);
}
return sap;
}
static struct llc_sap *__llc_sap_find(unsigned char sap_value)
{
struct llc_sap* sap;
list_for_each_entry(sap, &llc_sap_list, node)
if (sap->laddr.lsap == sap_value)
goto out;
sap = NULL;
out:
return sap;
}
struct llc_sap *llc_sap_find(unsigned char sap_value)
{
struct llc_sap *sap;
rcu_read_lock_bh();
sap = __llc_sap_find(sap_value);
if (sap)
llc_sap_hold(sap);
rcu_read_unlock_bh();
return sap;
}
struct llc_sap *llc_sap_open(unsigned char lsap,
int (*func)(struct sk_buff *skb,
struct net_device *dev,
struct packet_type *pt,
struct net_device *orig_dev))
{
struct llc_sap *sap = NULL;
spin_lock_bh(&llc_sap_list_lock);
if (__llc_sap_find(lsap))
goto out;
sap = llc_sap_alloc();
if (!sap)
goto out;
sap->laddr.lsap = lsap;
sap->rcv_func = func;
list_add_tail_rcu(&sap->node, &llc_sap_list);
out:
spin_unlock_bh(&llc_sap_list_lock);
return sap;
}
void llc_sap_close(struct llc_sap *sap)
{
WARN_ON(sap->sk_count);
spin_lock_bh(&llc_sap_list_lock);
list_del_rcu(&sap->node);
spin_unlock_bh(&llc_sap_list_lock);
synchronize_rcu();
kfree(sap);
}
static int __init llc_init(void)
{
dev_add_pack(&llc_packet_type);
dev_add_pack(&llc_tr_packet_type);
return 0;
}
static void __exit llc_exit(void)
{
dev_remove_pack(&llc_packet_type);
dev_remove_pack(&llc_tr_packet_type);
}
