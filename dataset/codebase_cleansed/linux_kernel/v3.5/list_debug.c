void __list_add(struct list_head *new,
struct list_head *prev,
struct list_head *next)
{
WARN(next->prev != prev,
"list_add corruption. next->prev should be "
"prev (%p), but was %p. (next=%p).\n",
prev, next->prev, next);
WARN(prev->next != next,
"list_add corruption. prev->next should be "
"next (%p), but was %p. (prev=%p).\n",
next, prev->next, prev);
WARN(new == prev || new == next,
"list_add double add: new=%p, prev=%p, next=%p.\n",
new, prev, next);
next->prev = new;
new->next = next;
new->prev = prev;
prev->next = new;
}
void __list_del_entry(struct list_head *entry)
{
struct list_head *prev, *next;
prev = entry->prev;
next = entry->next;
if (WARN(next == LIST_POISON1,
"list_del corruption, %p->next is LIST_POISON1 (%p)\n",
entry, LIST_POISON1) ||
WARN(prev == LIST_POISON2,
"list_del corruption, %p->prev is LIST_POISON2 (%p)\n",
entry, LIST_POISON2) ||
WARN(prev->next != entry,
"list_del corruption. prev->next should be %p, "
"but was %p\n", entry, prev->next) ||
WARN(next->prev != entry,
"list_del corruption. next->prev should be %p, "
"but was %p\n", entry, next->prev))
return;
__list_del(prev, next);
}
void list_del(struct list_head *entry)
{
__list_del_entry(entry);
entry->next = LIST_POISON1;
entry->prev = LIST_POISON2;
}
void __list_add_rcu(struct list_head *new,
struct list_head *prev, struct list_head *next)
{
WARN(next->prev != prev,
"list_add_rcu corruption. next->prev should be "
"prev (%p), but was %p. (next=%p).\n",
prev, next->prev, next);
WARN(prev->next != next,
"list_add_rcu corruption. prev->next should be "
"next (%p), but was %p. (prev=%p).\n",
next, prev->next, prev);
new->next = next;
new->prev = prev;
rcu_assign_pointer(list_next_rcu(prev), new);
next->prev = new;
}
