int register_dcbevent_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&dcbevent_notif_chain, nb);
}
int unregister_dcbevent_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&dcbevent_notif_chain, nb);
}
int call_dcbevent_notifiers(unsigned long val, void *v)
{
return atomic_notifier_call_chain(&dcbevent_notif_chain, val, v);
}
