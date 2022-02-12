static int nrs_fifo_start(struct ptlrpc_nrs_policy *policy)
{
struct nrs_fifo_head *head;
OBD_CPT_ALLOC_PTR(head, nrs_pol2cptab(policy), nrs_pol2cptid(policy));
if (head == NULL)
return -ENOMEM;
INIT_LIST_HEAD(&head->fh_list);
policy->pol_private = head;
return 0;
}
static void nrs_fifo_stop(struct ptlrpc_nrs_policy *policy)
{
struct nrs_fifo_head *head = policy->pol_private;
LASSERT(head != NULL);
LASSERT(list_empty(&head->fh_list));
OBD_FREE_PTR(head);
}
static int nrs_fifo_res_get(struct ptlrpc_nrs_policy *policy,
struct ptlrpc_nrs_request *nrq,
const struct ptlrpc_nrs_resource *parent,
struct ptlrpc_nrs_resource **resp, bool moving_req)
{
*resp = &((struct nrs_fifo_head *)policy->pol_private)->fh_res;
return 1;
}
static
struct ptlrpc_nrs_request * nrs_fifo_req_get(struct ptlrpc_nrs_policy *policy,
bool peek, bool force)
{
struct nrs_fifo_head *head = policy->pol_private;
struct ptlrpc_nrs_request *nrq;
nrq = unlikely(list_empty(&head->fh_list)) ? NULL :
list_entry(head->fh_list.next, struct ptlrpc_nrs_request,
nr_u.fifo.fr_list);
if (likely(!peek && nrq != NULL)) {
struct ptlrpc_request *req = container_of(nrq,
struct ptlrpc_request,
rq_nrq);
list_del_init(&nrq->nr_u.fifo.fr_list);
CDEBUG(D_RPCTRACE, "NRS start %s request from %s, seq: "LPU64
"\n", policy->pol_desc->pd_name,
libcfs_id2str(req->rq_peer), nrq->nr_u.fifo.fr_sequence);
}
return nrq;
}
static int nrs_fifo_req_add(struct ptlrpc_nrs_policy *policy,
struct ptlrpc_nrs_request *nrq)
{
struct nrs_fifo_head *head;
head = container_of(nrs_request_resource(nrq), struct nrs_fifo_head,
fh_res);
nrq->nr_u.fifo.fr_sequence = head->fh_sequence++;
list_add_tail(&nrq->nr_u.fifo.fr_list, &head->fh_list);
return 0;
}
static void nrs_fifo_req_del(struct ptlrpc_nrs_policy *policy,
struct ptlrpc_nrs_request *nrq)
{
LASSERT(!list_empty(&nrq->nr_u.fifo.fr_list));
list_del_init(&nrq->nr_u.fifo.fr_list);
}
static void nrs_fifo_req_stop(struct ptlrpc_nrs_policy *policy,
struct ptlrpc_nrs_request *nrq)
{
struct ptlrpc_request *req = container_of(nrq, struct ptlrpc_request,
rq_nrq);
CDEBUG(D_RPCTRACE, "NRS stop %s request from %s, seq: "LPU64"\n",
policy->pol_desc->pd_name, libcfs_id2str(req->rq_peer),
nrq->nr_u.fifo.fr_sequence);
}
