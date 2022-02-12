void hfi1_exp_tid_group_init(struct exp_tid_set *set)
{
INIT_LIST_HEAD(&set->list);
set->count = 0;
}
int hfi1_alloc_ctxt_rcv_groups(struct hfi1_ctxtdata *rcd)
{
struct hfi1_devdata *dd = rcd->dd;
u32 tidbase;
struct tid_group *grp;
int i;
tidbase = rcd->expected_base;
for (i = 0; i < rcd->expected_count /
dd->rcv_entries.group_size; i++) {
grp = kzalloc(sizeof(*grp), GFP_KERNEL);
if (!grp)
goto bail;
grp->size = dd->rcv_entries.group_size;
grp->base = tidbase;
tid_group_add_tail(grp, &rcd->tid_group_list);
tidbase += dd->rcv_entries.group_size;
}
return 0;
bail:
hfi1_free_ctxt_rcv_groups(rcd);
return -ENOMEM;
}
void hfi1_free_ctxt_rcv_groups(struct hfi1_ctxtdata *rcd)
{
struct tid_group *grp, *gptr;
WARN_ON(!EXP_TID_SET_EMPTY(rcd->tid_full_list));
WARN_ON(!EXP_TID_SET_EMPTY(rcd->tid_used_list));
list_for_each_entry_safe(grp, gptr, &rcd->tid_group_list.list, list) {
tid_group_remove(grp, &rcd->tid_group_list);
kfree(grp);
}
hfi1_clear_tids(rcd);
}
