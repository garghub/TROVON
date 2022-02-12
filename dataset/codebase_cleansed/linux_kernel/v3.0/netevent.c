int register_netevent_notifier(struct notifier_block *nb)
{
int err;
err = atomic_notifier_chain_register(&netevent_notif_chain, nb);
return err;
}
int unregister_netevent_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&netevent_notif_chain, nb);
}
int call_netevent_notifiers(unsigned long val, void *v)
{
return atomic_notifier_call_chain(&netevent_notif_chain, val, v);
}
