void locks_start_grace(struct lock_manager *lm)
{
spin_lock(&grace_lock);
list_add(&lm->list, &grace_list);
spin_unlock(&grace_lock);
}
void locks_end_grace(struct lock_manager *lm)
{
spin_lock(&grace_lock);
list_del_init(&lm->list);
spin_unlock(&grace_lock);
}
int locks_in_grace(void)
{
return !list_empty(&grace_list);
}
