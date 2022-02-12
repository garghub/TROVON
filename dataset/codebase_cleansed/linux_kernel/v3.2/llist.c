bool llist_add_batch(struct llist_node *new_first, struct llist_node *new_last,
struct llist_head *head)
{
struct llist_node *entry, *old_entry;
entry = head->first;
for (;;) {
old_entry = entry;
new_last->next = entry;
entry = cmpxchg(&head->first, old_entry, new_first);
if (entry == old_entry)
break;
}
return old_entry == NULL;
}
struct llist_node *llist_del_first(struct llist_head *head)
{
struct llist_node *entry, *old_entry, *next;
entry = head->first;
for (;;) {
if (entry == NULL)
return NULL;
old_entry = entry;
next = entry->next;
entry = cmpxchg(&head->first, old_entry, next);
if (entry == old_entry)
break;
}
return entry;
}
