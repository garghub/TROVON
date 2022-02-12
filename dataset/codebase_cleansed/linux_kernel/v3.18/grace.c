void
locks_start_grace(struct net *net, struct lock_manager *lm)
{
struct list_head *grace_list = net_generic(net, grace_net_id);
spin_lock(&grace_lock);
list_add(&lm->list, grace_list);
spin_unlock(&grace_lock);
}
void
locks_end_grace(struct lock_manager *lm)
{
spin_lock(&grace_lock);
list_del_init(&lm->list);
spin_unlock(&grace_lock);
}
int
locks_in_grace(struct net *net)
{
struct list_head *grace_list = net_generic(net, grace_net_id);
return !list_empty(grace_list);
}
static int __net_init
grace_init_net(struct net *net)
{
struct list_head *grace_list = net_generic(net, grace_net_id);
INIT_LIST_HEAD(grace_list);
return 0;
}
static void __net_exit
grace_exit_net(struct net *net)
{
struct list_head *grace_list = net_generic(net, grace_net_id);
BUG_ON(!list_empty(grace_list));
}
static int __init
init_grace(void)
{
return register_pernet_subsys(&grace_net_ops);
}
static void __exit
exit_grace(void)
{
unregister_pernet_subsys(&grace_net_ops);
}
