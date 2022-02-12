void user_return_notifier_register(struct user_return_notifier *urn)
{
set_tsk_thread_flag(current, TIF_USER_RETURN_NOTIFY);
hlist_add_head(&urn->link, this_cpu_ptr(&return_notifier_list));
}
void user_return_notifier_unregister(struct user_return_notifier *urn)
{
hlist_del(&urn->link);
if (hlist_empty(this_cpu_ptr(&return_notifier_list)))
clear_tsk_thread_flag(current, TIF_USER_RETURN_NOTIFY);
}
void fire_user_return_notifiers(void)
{
struct user_return_notifier *urn;
struct hlist_node *tmp2;
struct hlist_head *head;
head = &get_cpu_var(return_notifier_list);
hlist_for_each_entry_safe(urn, tmp2, head, link)
urn->on_user_return(urn);
put_cpu_var(return_notifier_list);
}
