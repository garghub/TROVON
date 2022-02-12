int fb_register_client(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&fb_notifier_list, nb);
}
int fb_unregister_client(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&fb_notifier_list, nb);
}
int fb_notifier_call_chain(unsigned long val, void *v)
{
return blocking_notifier_call_chain(&fb_notifier_list, val, v);
}
