void dlm_add_requestqueue(struct dlm_ls *ls, int nodeid, struct dlm_message *ms)
{
struct rq_entry *e;
int length = ms->m_header.h_length - sizeof(struct dlm_message);
e = kmalloc(sizeof(struct rq_entry) + length, GFP_NOFS);
if (!e) {
log_print("dlm_add_requestqueue: out of memory len %d", length);
return;
}
e->recover_seq = ls->ls_recover_seq & 0xFFFFFFFF;
e->nodeid = nodeid;
memcpy(&e->request, ms, ms->m_header.h_length);
mutex_lock(&ls->ls_requestqueue_mutex);
list_add_tail(&e->list, &ls->ls_requestqueue);
mutex_unlock(&ls->ls_requestqueue_mutex);
}
int dlm_process_requestqueue(struct dlm_ls *ls)
{
struct rq_entry *e;
struct dlm_message *ms;
int error = 0;
mutex_lock(&ls->ls_requestqueue_mutex);
for (;;) {
if (list_empty(&ls->ls_requestqueue)) {
mutex_unlock(&ls->ls_requestqueue_mutex);
error = 0;
break;
}
e = list_entry(ls->ls_requestqueue.next, struct rq_entry, list);
mutex_unlock(&ls->ls_requestqueue_mutex);
ms = &e->request;
log_limit(ls, "dlm_process_requestqueue msg %d from %d "
"lkid %x remid %x result %d seq %u",
ms->m_type, ms->m_header.h_nodeid,
ms->m_lkid, ms->m_remid, ms->m_result,
e->recover_seq);
dlm_receive_message_saved(ls, &e->request, e->recover_seq);
mutex_lock(&ls->ls_requestqueue_mutex);
list_del(&e->list);
kfree(e);
if (dlm_locking_stopped(ls)) {
log_debug(ls, "process_requestqueue abort running");
mutex_unlock(&ls->ls_requestqueue_mutex);
error = -EINTR;
break;
}
schedule();
}
return error;
}
void dlm_wait_requestqueue(struct dlm_ls *ls)
{
for (;;) {
mutex_lock(&ls->ls_requestqueue_mutex);
if (list_empty(&ls->ls_requestqueue))
break;
mutex_unlock(&ls->ls_requestqueue_mutex);
schedule();
}
mutex_unlock(&ls->ls_requestqueue_mutex);
}
static int purge_request(struct dlm_ls *ls, struct dlm_message *ms, int nodeid)
{
uint32_t type = ms->m_type;
if (!ls->ls_count)
return 1;
if (dlm_is_removed(ls, nodeid))
return 1;
if (type == DLM_MSG_REMOVE ||
type == DLM_MSG_LOOKUP ||
type == DLM_MSG_LOOKUP_REPLY)
return 1;
if (!dlm_no_directory(ls))
return 0;
return 1;
}
void dlm_purge_requestqueue(struct dlm_ls *ls)
{
struct dlm_message *ms;
struct rq_entry *e, *safe;
mutex_lock(&ls->ls_requestqueue_mutex);
list_for_each_entry_safe(e, safe, &ls->ls_requestqueue, list) {
ms = &e->request;
if (purge_request(ls, ms, e->nodeid)) {
list_del(&e->list);
kfree(e);
}
}
mutex_unlock(&ls->ls_requestqueue_mutex);
}
