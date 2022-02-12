void llist_add(struct llist_node *new, struct llist_head *head)
{
struct llist_node *entry, *old_entry;
#ifndef CONFIG_ARCH_HAVE_NMI_SAFE_CMPXCHG
BUG_ON(in_nmi());
#endif
entry = head->first;
do {
old_entry = entry;
new->next = entry;
cpu_relax();
} while ((entry = cmpxchg(&head->first, old_entry, new)) != old_entry);
}
void llist_add_batch(struct llist_node *new_first, struct llist_node *new_last,
struct llist_head *head)
{
struct llist_node *entry, *old_entry;
#ifndef CONFIG_ARCH_HAVE_NMI_SAFE_CMPXCHG
BUG_ON(in_nmi());
#endif
entry = head->first;
do {
old_entry = entry;
new_last->next = entry;
cpu_relax();
} while ((entry = cmpxchg(&head->first, old_entry, new_first)) != old_entry);
}
struct llist_node *llist_del_first(struct llist_head *head)
{
struct llist_node *entry, *old_entry, *next;
#ifndef CONFIG_ARCH_HAVE_NMI_SAFE_CMPXCHG
BUG_ON(in_nmi());
#endif
entry = head->first;
do {
if (entry == NULL)
return NULL;
old_entry = entry;
next = entry->next;
cpu_relax();
} while ((entry = cmpxchg(&head->first, old_entry, next)) != old_entry);
return entry;
}
struct llist_node *llist_del_all(struct llist_head *head)
{
#ifndef CONFIG_ARCH_HAVE_NMI_SAFE_CMPXCHG
BUG_ON(in_nmi());
#endif
return xchg(&head->first, NULL);
}
