bool __list_add_valid(struct list_head *new, struct list_head *prev,
struct list_head *next)
{
CHECK_DATA_CORRUPTION(next->prev != prev,
"list_add corruption. next->prev should be prev (%p), but was %p. (next=%p).\n",
prev, next->prev, next);
CHECK_DATA_CORRUPTION(prev->next != next,
"list_add corruption. prev->next should be next (%p), but was %p. (prev=%p).\n",
next, prev->next, prev);
CHECK_DATA_CORRUPTION(new == prev || new == next,
"list_add double add: new=%p, prev=%p, next=%p.\n",
new, prev, next);
return true;
}
bool __list_del_entry_valid(struct list_head *entry)
{
struct list_head *prev, *next;
prev = entry->prev;
next = entry->next;
CHECK_DATA_CORRUPTION(next == LIST_POISON1,
"list_del corruption, %p->next is LIST_POISON1 (%p)\n",
entry, LIST_POISON1);
CHECK_DATA_CORRUPTION(prev == LIST_POISON2,
"list_del corruption, %p->prev is LIST_POISON2 (%p)\n",
entry, LIST_POISON2);
CHECK_DATA_CORRUPTION(prev->next != entry,
"list_del corruption. prev->next should be %p, but was %p\n",
entry, prev->next);
CHECK_DATA_CORRUPTION(next->prev != entry,
"list_del corruption. next->prev should be %p, but was %p\n",
entry, next->prev);
return true;
}
