static void add_ordered_member(struct dlm_ls *ls, struct dlm_member *new)
{
struct dlm_member *memb = NULL;
struct list_head *tmp;
struct list_head *newlist = &new->list;
struct list_head *head = &ls->ls_nodes;
list_for_each(tmp, head) {
memb = list_entry(tmp, struct dlm_member, list);
if (new->nodeid < memb->nodeid)
break;
}
if (!memb)
list_add_tail(newlist, head);
else {
newlist->prev = tmp->prev;
newlist->next = tmp;
tmp->prev->next = newlist;
tmp->prev = newlist;
}
}
static int dlm_add_member(struct dlm_ls *ls, int nodeid)
{
struct dlm_member *memb;
int w, error;
memb = kzalloc(sizeof(struct dlm_member), GFP_NOFS);
if (!memb)
return -ENOMEM;
w = dlm_node_weight(ls->ls_name, nodeid);
if (w < 0) {
kfree(memb);
return w;
}
error = dlm_lowcomms_connect_node(nodeid);
if (error < 0) {
kfree(memb);
return error;
}
memb->nodeid = nodeid;
memb->weight = w;
add_ordered_member(ls, memb);
ls->ls_num_nodes++;
return 0;
}
static void dlm_remove_member(struct dlm_ls *ls, struct dlm_member *memb)
{
list_move(&memb->list, &ls->ls_nodes_gone);
ls->ls_num_nodes--;
}
int dlm_is_member(struct dlm_ls *ls, int nodeid)
{
struct dlm_member *memb;
list_for_each_entry(memb, &ls->ls_nodes, list) {
if (memb->nodeid == nodeid)
return 1;
}
return 0;
}
int dlm_is_removed(struct dlm_ls *ls, int nodeid)
{
struct dlm_member *memb;
list_for_each_entry(memb, &ls->ls_nodes_gone, list) {
if (memb->nodeid == nodeid)
return 1;
}
return 0;
}
static void clear_memb_list(struct list_head *head)
{
struct dlm_member *memb;
while (!list_empty(head)) {
memb = list_entry(head->next, struct dlm_member, list);
list_del(&memb->list);
kfree(memb);
}
}
void dlm_clear_members(struct dlm_ls *ls)
{
clear_memb_list(&ls->ls_nodes);
ls->ls_num_nodes = 0;
}
void dlm_clear_members_gone(struct dlm_ls *ls)
{
clear_memb_list(&ls->ls_nodes_gone);
}
static void make_member_array(struct dlm_ls *ls)
{
struct dlm_member *memb;
int i, w, x = 0, total = 0, all_zero = 0, *array;
kfree(ls->ls_node_array);
ls->ls_node_array = NULL;
list_for_each_entry(memb, &ls->ls_nodes, list) {
if (memb->weight)
total += memb->weight;
}
if (!total) {
total = ls->ls_num_nodes;
all_zero = 1;
}
ls->ls_total_weight = total;
array = kmalloc(sizeof(int) * total, GFP_NOFS);
if (!array)
return;
list_for_each_entry(memb, &ls->ls_nodes, list) {
if (!all_zero && !memb->weight)
continue;
if (all_zero)
w = 1;
else
w = memb->weight;
DLM_ASSERT(x < total, printk("total %d x %d\n", total, x););
for (i = 0; i < w; i++)
array[x++] = memb->nodeid;
}
ls->ls_node_array = array;
}
static int ping_members(struct dlm_ls *ls)
{
struct dlm_member *memb;
int error = 0;
list_for_each_entry(memb, &ls->ls_nodes, list) {
error = dlm_recovery_stopped(ls);
if (error)
break;
error = dlm_rcom_status(ls, memb->nodeid);
if (error)
break;
}
if (error)
log_debug(ls, "ping_members aborted %d last nodeid %d",
error, ls->ls_recover_nodeid);
return error;
}
int dlm_recover_members(struct dlm_ls *ls, struct dlm_recover *rv, int *neg_out)
{
struct dlm_member *memb, *safe;
int i, error, found, pos = 0, neg = 0, low = -1;
list_for_each_entry(memb, &ls->ls_nodes_gone, list) {
log_debug(ls, "prev removed member %d", memb->nodeid);
neg++;
}
list_for_each_entry_safe(memb, safe, &ls->ls_nodes, list) {
found = 0;
for (i = 0; i < rv->node_count; i++) {
if (memb->nodeid == rv->nodeids[i]) {
found = 1;
break;
}
}
if (!found) {
neg++;
dlm_remove_member(ls, memb);
log_debug(ls, "remove member %d", memb->nodeid);
}
}
for (i = 0; i < rv->new_count; i++) {
if (!dlm_is_member(ls, rv->new[i]))
continue;
log_debug(ls, "new nodeid %d is a re-added member", rv->new[i]);
memb = kzalloc(sizeof(struct dlm_member), GFP_NOFS);
if (!memb)
return -ENOMEM;
memb->nodeid = rv->new[i];
list_add_tail(&memb->list, &ls->ls_nodes_gone);
neg++;
}
for (i = 0; i < rv->node_count; i++) {
if (dlm_is_member(ls, rv->nodeids[i]))
continue;
dlm_add_member(ls, rv->nodeids[i]);
pos++;
log_debug(ls, "add member %d", rv->nodeids[i]);
}
list_for_each_entry(memb, &ls->ls_nodes, list) {
if (low == -1 || memb->nodeid < low)
low = memb->nodeid;
}
ls->ls_low_nodeid = low;
make_member_array(ls);
dlm_set_recover_status(ls, DLM_RS_NODES);
*neg_out = neg;
error = ping_members(ls);
if (!error || error == -EPROTO) {
ls->ls_members_result = error;
complete(&ls->ls_members_done);
}
if (error)
goto out;
error = dlm_recover_members_wait(ls);
out:
log_debug(ls, "total members %d error %d", ls->ls_num_nodes, error);
return error;
}
int dlm_ls_stop(struct dlm_ls *ls)
{
int new;
down_write(&ls->ls_recv_active);
spin_lock(&ls->ls_recover_lock);
set_bit(LSFL_RECOVERY_STOP, &ls->ls_flags);
new = test_and_clear_bit(LSFL_RUNNING, &ls->ls_flags);
ls->ls_recover_seq++;
spin_unlock(&ls->ls_recover_lock);
up_write(&ls->ls_recv_active);
if (new)
down_write(&ls->ls_in_recovery);
dlm_recoverd_suspend(ls);
ls->ls_recover_status = 0;
dlm_recoverd_resume(ls);
if (!ls->ls_recover_begin)
ls->ls_recover_begin = jiffies;
return 0;
}
int dlm_ls_start(struct dlm_ls *ls)
{
struct dlm_recover *rv = NULL, *rv_old;
int *ids = NULL, *new = NULL;
int error, ids_count = 0, new_count = 0;
rv = kzalloc(sizeof(struct dlm_recover), GFP_NOFS);
if (!rv)
return -ENOMEM;
error = dlm_nodeid_list(ls->ls_name, &ids, &ids_count,
&new, &new_count);
if (error < 0)
goto fail;
spin_lock(&ls->ls_recover_lock);
if (!dlm_locking_stopped(ls)) {
spin_unlock(&ls->ls_recover_lock);
log_error(ls, "start ignored: lockspace running");
error = -EINVAL;
goto fail;
}
rv->nodeids = ids;
rv->node_count = ids_count;
rv->new = new;
rv->new_count = new_count;
rv->seq = ++ls->ls_recover_seq;
rv_old = ls->ls_recover_args;
ls->ls_recover_args = rv;
spin_unlock(&ls->ls_recover_lock);
if (rv_old) {
log_error(ls, "unused recovery %llx %d",
(unsigned long long)rv_old->seq, rv_old->node_count);
kfree(rv_old->nodeids);
kfree(rv_old->new);
kfree(rv_old);
}
dlm_recoverd_kick(ls);
return 0;
fail:
kfree(rv);
kfree(ids);
kfree(new);
return error;
}
