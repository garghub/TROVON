static bool src_proto(enum protocol_type type)
{
return type == PROTOCOLID_ISCSI ||
type == PROTOCOLID_ROCE;
}
static bool tm_cid_proto(enum protocol_type type)
{
return type == PROTOCOLID_ISCSI ||
type == PROTOCOLID_ROCE;
}
static void qed_cxt_cdu_iids(struct qed_cxt_mngr *p_mngr,
struct qed_cdu_iids *iids)
{
u32 type;
for (type = 0; type < MAX_CONN_TYPES; type++) {
iids->pf_cids += p_mngr->conn_cfg[type].cid_count;
iids->per_vf_cids += p_mngr->conn_cfg[type].cids_per_vf;
}
}
static void qed_cxt_src_iids(struct qed_cxt_mngr *p_mngr,
struct qed_src_iids *iids)
{
u32 i;
for (i = 0; i < MAX_CONN_TYPES; i++) {
if (!src_proto(i))
continue;
iids->pf_cids += p_mngr->conn_cfg[i].cid_count;
iids->per_vf_cids += p_mngr->conn_cfg[i].cids_per_vf;
}
}
static void qed_cxt_tm_iids(struct qed_cxt_mngr *p_mngr,
struct qed_tm_iids *iids)
{
u32 i, j;
for (i = 0; i < MAX_CONN_TYPES; i++) {
struct qed_conn_type_cfg *p_cfg = &p_mngr->conn_cfg[i];
if (tm_cid_proto(i)) {
iids->pf_cids += p_cfg->cid_count;
iids->per_vf_cids += p_cfg->cids_per_vf;
}
}
iids->pf_cids = roundup(iids->pf_cids, TM_ALIGN);
iids->per_vf_cids = roundup(iids->per_vf_cids, TM_ALIGN);
iids->per_vf_tids = roundup(iids->per_vf_tids, TM_ALIGN);
for (iids->pf_tids_total = 0, j = 0; j < NUM_TASK_PF_SEGMENTS; j++) {
iids->pf_tids[j] = roundup(iids->pf_tids[j], TM_ALIGN);
iids->pf_tids_total += iids->pf_tids[j];
}
}
static void qed_cxt_qm_iids(struct qed_hwfn *p_hwfn,
struct qed_qm_iids *iids)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
struct qed_tid_seg *segs;
u32 vf_cids = 0, type, j;
u32 vf_tids = 0;
for (type = 0; type < MAX_CONN_TYPES; type++) {
iids->cids += p_mngr->conn_cfg[type].cid_count;
vf_cids += p_mngr->conn_cfg[type].cids_per_vf;
segs = p_mngr->conn_cfg[type].tid_seg;
for (j = 0; j < NUM_TASK_PF_SEGMENTS; j++)
iids->tids += segs[j].count;
vf_tids += segs[NUM_TASK_PF_SEGMENTS].count;
}
iids->vf_cids += vf_cids * p_mngr->vf_count;
iids->tids += vf_tids * p_mngr->vf_count;
DP_VERBOSE(p_hwfn, QED_MSG_ILT,
"iids: CIDS %08x vf_cids %08x tids %08x vf_tids %08x\n",
iids->cids, iids->vf_cids, iids->tids, vf_tids);
}
static struct qed_tid_seg *qed_cxt_tid_seg_info(struct qed_hwfn *p_hwfn,
u32 seg)
{
struct qed_cxt_mngr *p_cfg = p_hwfn->p_cxt_mngr;
u32 i;
for (i = 0; i < MAX_CONN_TYPES; i++)
if (p_cfg->conn_cfg[i].tid_seg[seg].count)
return &p_cfg->conn_cfg[i].tid_seg[seg];
return NULL;
}
static void qed_cxt_set_srq_count(struct qed_hwfn *p_hwfn, u32 num_srqs)
{
struct qed_cxt_mngr *p_mgr = p_hwfn->p_cxt_mngr;
p_mgr->srq_count = num_srqs;
}
static u32 qed_cxt_get_srq_count(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mgr = p_hwfn->p_cxt_mngr;
return p_mgr->srq_count;
}
static void qed_cxt_set_proto_cid_count(struct qed_hwfn *p_hwfn,
enum protocol_type type,
u32 cid_count, u32 vf_cid_cnt)
{
struct qed_cxt_mngr *p_mgr = p_hwfn->p_cxt_mngr;
struct qed_conn_type_cfg *p_conn = &p_mgr->conn_cfg[type];
p_conn->cid_count = roundup(cid_count, DQ_RANGE_ALIGN);
p_conn->cids_per_vf = roundup(vf_cid_cnt, DQ_RANGE_ALIGN);
if (type == PROTOCOLID_ROCE) {
u32 page_sz = p_mgr->clients[ILT_CLI_CDUC].p_size.val;
u32 cxt_size = CONN_CXT_SIZE(p_hwfn);
u32 elems_per_page = ILT_PAGE_IN_BYTES(page_sz) / cxt_size;
p_conn->cid_count = roundup(p_conn->cid_count, elems_per_page);
}
}
u32 qed_cxt_get_proto_cid_count(struct qed_hwfn *p_hwfn,
enum protocol_type type, u32 *vf_cid)
{
if (vf_cid)
*vf_cid = p_hwfn->p_cxt_mngr->conn_cfg[type].cids_per_vf;
return p_hwfn->p_cxt_mngr->conn_cfg[type].cid_count;
}
u32 qed_cxt_get_proto_cid_start(struct qed_hwfn *p_hwfn,
enum protocol_type type)
{
return p_hwfn->p_cxt_mngr->acquired[type].start_cid;
}
u32 qed_cxt_get_proto_tid_count(struct qed_hwfn *p_hwfn,
enum protocol_type type)
{
u32 cnt = 0;
int i;
for (i = 0; i < TASK_SEGMENTS; i++)
cnt += p_hwfn->p_cxt_mngr->conn_cfg[type].tid_seg[i].count;
return cnt;
}
static void qed_cxt_set_proto_tid_count(struct qed_hwfn *p_hwfn,
enum protocol_type proto,
u8 seg,
u8 seg_type, u32 count, bool has_fl)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
struct qed_tid_seg *p_seg = &p_mngr->conn_cfg[proto].tid_seg[seg];
p_seg->count = count;
p_seg->has_fl_mem = has_fl;
p_seg->type = seg_type;
}
static void qed_ilt_cli_blk_fill(struct qed_ilt_client_cfg *p_cli,
struct qed_ilt_cli_blk *p_blk,
u32 start_line, u32 total_size, u32 elem_size)
{
u32 ilt_size = ILT_PAGE_IN_BYTES(p_cli->p_size.val);
if (p_blk->total_size)
return;
p_blk->total_size = total_size;
p_blk->real_size_in_page = 0;
if (elem_size)
p_blk->real_size_in_page = (ilt_size / elem_size) * elem_size;
p_blk->start_line = start_line;
}
static void qed_ilt_cli_adv_line(struct qed_hwfn *p_hwfn,
struct qed_ilt_client_cfg *p_cli,
struct qed_ilt_cli_blk *p_blk,
u32 *p_line, enum ilt_clients client_id)
{
if (!p_blk->total_size)
return;
if (!p_cli->active)
p_cli->first.val = *p_line;
p_cli->active = true;
*p_line += DIV_ROUND_UP(p_blk->total_size, p_blk->real_size_in_page);
p_cli->last.val = *p_line - 1;
DP_VERBOSE(p_hwfn, QED_MSG_ILT,
"ILT[Client %d] - Lines: [%08x - %08x]. Block - Size %08x [Real %08x] Start line %d\n",
client_id, p_cli->first.val,
p_cli->last.val, p_blk->total_size,
p_blk->real_size_in_page, p_blk->start_line);
}
static u32 qed_ilt_get_dynamic_line_cnt(struct qed_hwfn *p_hwfn,
enum ilt_clients ilt_client)
{
u32 cid_count = p_hwfn->p_cxt_mngr->conn_cfg[PROTOCOLID_ROCE].cid_count;
struct qed_ilt_client_cfg *p_cli;
u32 lines_to_skip = 0;
u32 cxts_per_p;
if (ilt_client == ILT_CLI_CDUC) {
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC];
cxts_per_p = ILT_PAGE_IN_BYTES(p_cli->p_size.val) /
(u32) CONN_CXT_SIZE(p_hwfn);
lines_to_skip = cid_count / cxts_per_p;
}
return lines_to_skip;
}
int qed_cxt_cfg_ilt_compute(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 curr_line, total, i, task_size, line;
struct qed_ilt_client_cfg *p_cli;
struct qed_ilt_cli_blk *p_blk;
struct qed_cdu_iids cdu_iids;
struct qed_src_iids src_iids;
struct qed_qm_iids qm_iids;
struct qed_tm_iids tm_iids;
struct qed_tid_seg *p_seg;
memset(&qm_iids, 0, sizeof(qm_iids));
memset(&cdu_iids, 0, sizeof(cdu_iids));
memset(&src_iids, 0, sizeof(src_iids));
memset(&tm_iids, 0, sizeof(tm_iids));
p_mngr->pf_start_line = RESC_START(p_hwfn, QED_ILT);
DP_VERBOSE(p_hwfn, QED_MSG_ILT,
"hwfn [%d] - Set context manager starting line to be 0x%08x\n",
p_hwfn->my_id, p_hwfn->p_cxt_mngr->pf_start_line);
p_cli = &p_mngr->clients[ILT_CLI_CDUC];
curr_line = p_mngr->pf_start_line;
p_cli->pf_total_lines = 0;
qed_cxt_cdu_iids(p_mngr, &cdu_iids);
p_blk = &p_cli->pf_blks[CDUC_BLK];
total = cdu_iids.pf_cids * CONN_CXT_SIZE(p_hwfn);
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line,
total, CONN_CXT_SIZE(p_hwfn));
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line, ILT_CLI_CDUC);
p_cli->pf_total_lines = curr_line - p_blk->start_line;
p_blk->dynamic_line_cnt = qed_ilt_get_dynamic_line_cnt(p_hwfn,
ILT_CLI_CDUC);
p_blk = &p_cli->vf_blks[CDUC_BLK];
total = cdu_iids.per_vf_cids * CONN_CXT_SIZE(p_hwfn);
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line,
total, CONN_CXT_SIZE(p_hwfn));
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line, ILT_CLI_CDUC);
p_cli->vf_total_lines = curr_line - p_blk->start_line;
for (i = 1; i < p_mngr->vf_count; i++)
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUC);
p_cli = &p_mngr->clients[ILT_CLI_CDUT];
p_cli->first.val = curr_line;
for (i = 0; i < NUM_TASK_PF_SEGMENTS; i++) {
p_seg = qed_cxt_tid_seg_info(p_hwfn, i);
if (!p_seg || p_seg->count == 0)
continue;
p_blk = &p_cli->pf_blks[CDUT_SEG_BLK(i)];
total = p_seg->count * p_mngr->task_type_size[p_seg->type];
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line, total,
p_mngr->task_type_size[p_seg->type]);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUT);
}
for (i = 0; i < NUM_TASK_PF_SEGMENTS; i++) {
p_seg = qed_cxt_tid_seg_info(p_hwfn, i);
if (!p_seg || p_seg->count == 0)
continue;
p_blk = &p_cli->pf_blks[CDUT_FL_SEG_BLK(i, PF)];
if (!p_seg->has_fl_mem) {
line = p_cli->pf_blks[CDUT_SEG_BLK(i)].start_line;
qed_ilt_cli_blk_fill(p_cli, p_blk, line, 0, 0);
continue;
}
total = p_seg->count * p_mngr->task_type_size[p_seg->type];
qed_ilt_cli_blk_fill(p_cli, p_blk,
curr_line, total,
p_mngr->task_type_size[p_seg->type]);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUT);
}
p_cli->pf_total_lines = curr_line - p_cli->pf_blks[0].start_line;
p_seg = qed_cxt_tid_seg_info(p_hwfn, TASK_SEGMENT_VF);
if (p_seg && p_seg->count) {
total = p_seg->count * p_mngr->task_type_size[p_seg->type];
p_blk = &p_cli->vf_blks[CDUT_SEG_BLK(0)];
qed_ilt_cli_blk_fill(p_cli, p_blk,
curr_line, total,
p_mngr->task_type_size[p_seg->type]);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUT);
p_blk = &p_cli->vf_blks[CDUT_FL_SEG_BLK(0, VF)];
if (!p_seg->has_fl_mem) {
line = p_cli->vf_blks[CDUT_SEG_BLK(0)].start_line;
qed_ilt_cli_blk_fill(p_cli, p_blk, line, 0, 0);
} else {
task_size = p_mngr->task_type_size[p_seg->type];
qed_ilt_cli_blk_fill(p_cli, p_blk,
curr_line, total, task_size);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUT);
}
p_cli->vf_total_lines = curr_line -
p_cli->vf_blks[0].start_line;
for (i = 1; i < p_mngr->vf_count; i++) {
p_blk = &p_cli->vf_blks[CDUT_SEG_BLK(0)];
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUT);
p_blk = &p_cli->vf_blks[CDUT_FL_SEG_BLK(0, VF)];
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_CDUT);
}
}
p_cli = &p_mngr->clients[ILT_CLI_QM];
p_blk = &p_cli->pf_blks[0];
qed_cxt_qm_iids(p_hwfn, &qm_iids);
total = qed_qm_pf_mem_size(p_hwfn->rel_pf_id, qm_iids.cids,
qm_iids.vf_cids, qm_iids.tids,
p_hwfn->qm_info.num_pqs,
p_hwfn->qm_info.num_vf_pqs);
DP_VERBOSE(p_hwfn,
QED_MSG_ILT,
"QM ILT Info, (cids=%d, vf_cids=%d, tids=%d, num_pqs=%d, num_vf_pqs=%d, memory_size=%d)\n",
qm_iids.cids,
qm_iids.vf_cids,
qm_iids.tids,
p_hwfn->qm_info.num_pqs, p_hwfn->qm_info.num_vf_pqs, total);
qed_ilt_cli_blk_fill(p_cli, p_blk,
curr_line, total * 0x1000,
QM_PQ_ELEMENT_SIZE);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line, ILT_CLI_QM);
p_cli->pf_total_lines = curr_line - p_blk->start_line;
p_cli = &p_mngr->clients[ILT_CLI_SRC];
qed_cxt_src_iids(p_mngr, &src_iids);
total = src_iids.pf_cids + src_iids.per_vf_cids * p_mngr->vf_count;
if (total) {
u32 local_max = max_t(u32, total,
SRC_MIN_NUM_ELEMS);
total = roundup_pow_of_two(local_max);
p_blk = &p_cli->pf_blks[0];
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line,
total * sizeof(struct src_ent),
sizeof(struct src_ent));
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_SRC);
p_cli->pf_total_lines = curr_line - p_blk->start_line;
}
p_cli = &p_mngr->clients[ILT_CLI_TM];
qed_cxt_tm_iids(p_mngr, &tm_iids);
total = tm_iids.pf_cids + tm_iids.pf_tids_total;
if (total) {
p_blk = &p_cli->pf_blks[0];
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line,
total * TM_ELEM_SIZE, TM_ELEM_SIZE);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_TM);
p_cli->pf_total_lines = curr_line - p_blk->start_line;
}
total = tm_iids.per_vf_cids + tm_iids.per_vf_tids;
if (total) {
p_blk = &p_cli->vf_blks[0];
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line,
total * TM_ELEM_SIZE, TM_ELEM_SIZE);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_TM);
p_cli->pf_total_lines = curr_line - p_blk->start_line;
for (i = 1; i < p_mngr->vf_count; i++)
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_TM);
}
total = qed_cxt_get_srq_count(p_hwfn);
if (total) {
p_cli = &p_mngr->clients[ILT_CLI_TSDM];
p_blk = &p_cli->pf_blks[SRQ_BLK];
qed_ilt_cli_blk_fill(p_cli, p_blk, curr_line,
total * SRQ_CXT_SIZE, SRQ_CXT_SIZE);
qed_ilt_cli_adv_line(p_hwfn, p_cli, p_blk, &curr_line,
ILT_CLI_TSDM);
p_cli->pf_total_lines = curr_line - p_blk->start_line;
}
if (curr_line - p_hwfn->p_cxt_mngr->pf_start_line >
RESC_NUM(p_hwfn, QED_ILT)) {
DP_ERR(p_hwfn, "too many ilt lines...#lines=%d\n",
curr_line - p_hwfn->p_cxt_mngr->pf_start_line);
return -EINVAL;
}
return 0;
}
static void qed_cxt_src_t2_free(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 i;
if (!p_mngr->t2)
return;
for (i = 0; i < p_mngr->t2_num_pages; i++)
if (p_mngr->t2[i].p_virt)
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
p_mngr->t2[i].size,
p_mngr->t2[i].p_virt,
p_mngr->t2[i].p_phys);
kfree(p_mngr->t2);
p_mngr->t2 = NULL;
}
static int qed_cxt_src_t2_alloc(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 conn_num, total_size, ent_per_page, psz, i;
struct qed_ilt_client_cfg *p_src;
struct qed_src_iids src_iids;
struct qed_dma_mem *p_t2;
int rc;
memset(&src_iids, 0, sizeof(src_iids));
p_src = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_SRC];
if (!p_src->active)
return 0;
qed_cxt_src_iids(p_mngr, &src_iids);
conn_num = src_iids.pf_cids + src_iids.per_vf_cids * p_mngr->vf_count;
total_size = conn_num * sizeof(struct src_ent);
psz = ILT_PAGE_IN_BYTES(p_src->p_size.val);
p_mngr->t2_num_pages = DIV_ROUND_UP(total_size, psz);
p_mngr->t2 = kcalloc(p_mngr->t2_num_pages, sizeof(struct qed_dma_mem),
GFP_KERNEL);
if (!p_mngr->t2) {
rc = -ENOMEM;
goto t2_fail;
}
for (i = 0; i < p_mngr->t2_num_pages; i++) {
u32 size = min_t(u32, total_size, psz);
void **p_virt = &p_mngr->t2[i].p_virt;
*p_virt = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
size,
&p_mngr->t2[i].p_phys, GFP_KERNEL);
if (!p_mngr->t2[i].p_virt) {
rc = -ENOMEM;
goto t2_fail;
}
memset(*p_virt, 0, size);
p_mngr->t2[i].size = size;
total_size -= size;
}
ent_per_page = psz / sizeof(struct src_ent);
p_mngr->first_free = (u64) p_mngr->t2[0].p_phys;
p_t2 = &p_mngr->t2[(conn_num - 1) / ent_per_page];
p_mngr->last_free = (u64) p_t2->p_phys +
((conn_num - 1) & (ent_per_page - 1)) * sizeof(struct src_ent);
for (i = 0; i < p_mngr->t2_num_pages; i++) {
u32 ent_num = min_t(u32,
ent_per_page,
conn_num);
struct src_ent *entries = p_mngr->t2[i].p_virt;
u64 p_ent_phys = (u64) p_mngr->t2[i].p_phys, val;
u32 j;
for (j = 0; j < ent_num - 1; j++) {
val = p_ent_phys + (j + 1) * sizeof(struct src_ent);
entries[j].next = cpu_to_be64(val);
}
if (i < p_mngr->t2_num_pages - 1)
val = (u64) p_mngr->t2[i + 1].p_phys;
else
val = 0;
entries[j].next = cpu_to_be64(val);
conn_num -= ent_num;
}
return 0;
t2_fail:
qed_cxt_src_t2_free(p_hwfn);
return rc;
}
static u32 qed_cxt_ilt_shadow_size(struct qed_ilt_client_cfg *ilt_clients)
{
u32 size = 0;
u32 i;
for_each_ilt_valid_client(i, ilt_clients)
size += (ilt_clients[i].last.val - ilt_clients[i].first.val + 1);
return size;
}
static void qed_ilt_shadow_free(struct qed_hwfn *p_hwfn)
{
struct qed_ilt_client_cfg *p_cli = p_hwfn->p_cxt_mngr->clients;
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 ilt_size, i;
ilt_size = qed_cxt_ilt_shadow_size(p_cli);
for (i = 0; p_mngr->ilt_shadow && i < ilt_size; i++) {
struct qed_dma_mem *p_dma = &p_mngr->ilt_shadow[i];
if (p_dma->p_virt)
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
p_dma->size, p_dma->p_virt,
p_dma->p_phys);
p_dma->p_virt = NULL;
}
kfree(p_mngr->ilt_shadow);
}
static int qed_ilt_blk_alloc(struct qed_hwfn *p_hwfn,
struct qed_ilt_cli_blk *p_blk,
enum ilt_clients ilt_client,
u32 start_line_offset)
{
struct qed_dma_mem *ilt_shadow = p_hwfn->p_cxt_mngr->ilt_shadow;
u32 lines, line, sz_left, lines_to_skip = 0;
if ((p_hwfn->hw_info.personality == QED_PCI_ETH_ROCE) &&
((ilt_client == ILT_CLI_CDUT) || ilt_client == ILT_CLI_TSDM))
return 0;
lines_to_skip = p_blk->dynamic_line_cnt;
if (!p_blk->total_size)
return 0;
sz_left = p_blk->total_size;
lines = DIV_ROUND_UP(sz_left, p_blk->real_size_in_page) - lines_to_skip;
line = p_blk->start_line + start_line_offset -
p_hwfn->p_cxt_mngr->pf_start_line + lines_to_skip;
for (; lines; lines--) {
dma_addr_t p_phys;
void *p_virt;
u32 size;
size = min_t(u32, sz_left, p_blk->real_size_in_page);
p_virt = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
size, &p_phys, GFP_KERNEL);
if (!p_virt)
return -ENOMEM;
memset(p_virt, 0, size);
ilt_shadow[line].p_phys = p_phys;
ilt_shadow[line].p_virt = p_virt;
ilt_shadow[line].size = size;
DP_VERBOSE(p_hwfn, QED_MSG_ILT,
"ILT shadow: Line [%d] Physical 0x%llx Virtual %p Size %d\n",
line, (u64)p_phys, p_virt, size);
sz_left -= size;
line++;
}
return 0;
}
static int qed_ilt_shadow_alloc(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
struct qed_ilt_client_cfg *clients = p_mngr->clients;
struct qed_ilt_cli_blk *p_blk;
u32 size, i, j, k;
int rc;
size = qed_cxt_ilt_shadow_size(clients);
p_mngr->ilt_shadow = kcalloc(size, sizeof(struct qed_dma_mem),
GFP_KERNEL);
if (!p_mngr->ilt_shadow) {
rc = -ENOMEM;
goto ilt_shadow_fail;
}
DP_VERBOSE(p_hwfn, QED_MSG_ILT,
"Allocated 0x%x bytes for ilt shadow\n",
(u32)(size * sizeof(struct qed_dma_mem)));
for_each_ilt_valid_client(i, clients) {
for (j = 0; j < ILT_CLI_PF_BLOCKS; j++) {
p_blk = &clients[i].pf_blks[j];
rc = qed_ilt_blk_alloc(p_hwfn, p_blk, i, 0);
if (rc)
goto ilt_shadow_fail;
}
for (k = 0; k < p_mngr->vf_count; k++) {
for (j = 0; j < ILT_CLI_VF_BLOCKS; j++) {
u32 lines = clients[i].vf_total_lines * k;
p_blk = &clients[i].vf_blks[j];
rc = qed_ilt_blk_alloc(p_hwfn, p_blk, i, lines);
if (rc)
goto ilt_shadow_fail;
}
}
}
return 0;
ilt_shadow_fail:
qed_ilt_shadow_free(p_hwfn);
return rc;
}
static void qed_cid_map_free(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 type;
for (type = 0; type < MAX_CONN_TYPES; type++) {
kfree(p_mngr->acquired[type].cid_map);
p_mngr->acquired[type].max_count = 0;
p_mngr->acquired[type].start_cid = 0;
}
}
static int qed_cid_map_alloc(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 start_cid = 0;
u32 type;
for (type = 0; type < MAX_CONN_TYPES; type++) {
u32 cid_cnt = p_hwfn->p_cxt_mngr->conn_cfg[type].cid_count;
u32 size;
if (cid_cnt == 0)
continue;
size = DIV_ROUND_UP(cid_cnt,
sizeof(unsigned long) * BITS_PER_BYTE) *
sizeof(unsigned long);
p_mngr->acquired[type].cid_map = kzalloc(size, GFP_KERNEL);
if (!p_mngr->acquired[type].cid_map)
goto cid_map_fail;
p_mngr->acquired[type].max_count = cid_cnt;
p_mngr->acquired[type].start_cid = start_cid;
p_hwfn->p_cxt_mngr->conn_cfg[type].cid_start = start_cid;
DP_VERBOSE(p_hwfn, QED_MSG_CXT,
"Type %08x start: %08x count %08x\n",
type, p_mngr->acquired[type].start_cid,
p_mngr->acquired[type].max_count);
start_cid += cid_cnt;
}
return 0;
cid_map_fail:
qed_cid_map_free(p_hwfn);
return -ENOMEM;
}
int qed_cxt_mngr_alloc(struct qed_hwfn *p_hwfn)
{
struct qed_ilt_client_cfg *clients;
struct qed_cxt_mngr *p_mngr;
u32 i;
p_mngr = kzalloc(sizeof(*p_mngr), GFP_KERNEL);
if (!p_mngr)
return -ENOMEM;
clients = p_mngr->clients;
clients[ILT_CLI_CDUC].first.reg = ILT_CFG_REG(CDUC, FIRST_ILT);
clients[ILT_CLI_CDUC].last.reg = ILT_CFG_REG(CDUC, LAST_ILT);
clients[ILT_CLI_CDUC].p_size.reg = ILT_CFG_REG(CDUC, P_SIZE);
clients[ILT_CLI_QM].first.reg = ILT_CFG_REG(QM, FIRST_ILT);
clients[ILT_CLI_QM].last.reg = ILT_CFG_REG(QM, LAST_ILT);
clients[ILT_CLI_QM].p_size.reg = ILT_CFG_REG(QM, P_SIZE);
clients[ILT_CLI_TM].first.reg = ILT_CFG_REG(TM, FIRST_ILT);
clients[ILT_CLI_TM].last.reg = ILT_CFG_REG(TM, LAST_ILT);
clients[ILT_CLI_TM].p_size.reg = ILT_CFG_REG(TM, P_SIZE);
clients[ILT_CLI_SRC].first.reg = ILT_CFG_REG(SRC, FIRST_ILT);
clients[ILT_CLI_SRC].last.reg = ILT_CFG_REG(SRC, LAST_ILT);
clients[ILT_CLI_SRC].p_size.reg = ILT_CFG_REG(SRC, P_SIZE);
clients[ILT_CLI_CDUT].first.reg = ILT_CFG_REG(CDUT, FIRST_ILT);
clients[ILT_CLI_CDUT].last.reg = ILT_CFG_REG(CDUT, LAST_ILT);
clients[ILT_CLI_CDUT].p_size.reg = ILT_CFG_REG(CDUT, P_SIZE);
clients[ILT_CLI_TSDM].first.reg = ILT_CFG_REG(TSDM, FIRST_ILT);
clients[ILT_CLI_TSDM].last.reg = ILT_CFG_REG(TSDM, LAST_ILT);
clients[ILT_CLI_TSDM].p_size.reg = ILT_CFG_REG(TSDM, P_SIZE);
for (i = 0; i < ILT_CLI_MAX; i++)
p_mngr->clients[i].p_size.val = ILT_DEFAULT_HW_P_SIZE;
p_mngr->task_type_size[0] = TYPE0_TASK_CXT_SIZE(p_hwfn);
p_mngr->task_type_size[1] = TYPE1_TASK_CXT_SIZE(p_hwfn);
if (p_hwfn->cdev->p_iov_info)
p_mngr->vf_count = p_hwfn->cdev->p_iov_info->total_vfs;
mutex_init(&p_mngr->mutex);
p_hwfn->p_cxt_mngr = p_mngr;
return 0;
}
int qed_cxt_tables_alloc(struct qed_hwfn *p_hwfn)
{
int rc;
rc = qed_ilt_shadow_alloc(p_hwfn);
if (rc)
goto tables_alloc_fail;
rc = qed_cxt_src_t2_alloc(p_hwfn);
if (rc)
goto tables_alloc_fail;
rc = qed_cid_map_alloc(p_hwfn);
if (rc)
goto tables_alloc_fail;
return 0;
tables_alloc_fail:
qed_cxt_mngr_free(p_hwfn);
return rc;
}
void qed_cxt_mngr_free(struct qed_hwfn *p_hwfn)
{
if (!p_hwfn->p_cxt_mngr)
return;
qed_cid_map_free(p_hwfn);
qed_cxt_src_t2_free(p_hwfn);
qed_ilt_shadow_free(p_hwfn);
kfree(p_hwfn->p_cxt_mngr);
p_hwfn->p_cxt_mngr = NULL;
}
void qed_cxt_mngr_setup(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
int type;
for (type = 0; type < MAX_CONN_TYPES; type++) {
u32 cid_cnt = p_hwfn->p_cxt_mngr->conn_cfg[type].cid_count;
if (cid_cnt == 0)
continue;
memset(p_mngr->acquired[type].cid_map, 0,
DIV_ROUND_UP(cid_cnt,
sizeof(unsigned long) * BITS_PER_BYTE) *
sizeof(unsigned long));
}
}
static void qed_cdu_init_common(struct qed_hwfn *p_hwfn)
{
u32 page_sz, elems_per_page, block_waste, cxt_size, cdu_params = 0;
page_sz = p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC].p_size.val;
cxt_size = CONN_CXT_SIZE(p_hwfn);
elems_per_page = ILT_PAGE_IN_BYTES(page_sz) / cxt_size;
block_waste = ILT_PAGE_IN_BYTES(page_sz) - elems_per_page * cxt_size;
SET_FIELD(cdu_params, CDUC_CXT_SIZE, cxt_size);
SET_FIELD(cdu_params, CDUC_BLOCK_WASTE, block_waste);
SET_FIELD(cdu_params, CDUC_NCIB, elems_per_page);
STORE_RT_REG(p_hwfn, CDU_REG_CID_ADDR_PARAMS_RT_OFFSET, cdu_params);
page_sz = p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUT].p_size.val;
cxt_size = p_hwfn->p_cxt_mngr->task_type_size[0];
elems_per_page = ILT_PAGE_IN_BYTES(page_sz) / cxt_size;
block_waste = ILT_PAGE_IN_BYTES(page_sz) - elems_per_page * cxt_size;
cdu_params = 0;
SET_FIELD(cdu_params, CDUT_TYPE0_CXT_SIZE, (cxt_size >> 3));
SET_FIELD(cdu_params, CDUT_TYPE0_BLOCK_WASTE, (block_waste >> 3));
SET_FIELD(cdu_params, CDUT_TYPE0_NCIB, elems_per_page);
STORE_RT_REG(p_hwfn, CDU_REG_SEGMENT0_PARAMS_RT_OFFSET, cdu_params);
cxt_size = p_hwfn->p_cxt_mngr->task_type_size[1];
elems_per_page = ILT_PAGE_IN_BYTES(page_sz) / cxt_size;
block_waste = ILT_PAGE_IN_BYTES(page_sz) - elems_per_page * cxt_size;
cdu_params = 0;
SET_FIELD(cdu_params, CDUT_TYPE1_CXT_SIZE, (cxt_size >> 3));
SET_FIELD(cdu_params, CDUT_TYPE1_BLOCK_WASTE, (block_waste >> 3));
SET_FIELD(cdu_params, CDUT_TYPE1_NCIB, elems_per_page);
STORE_RT_REG(p_hwfn, CDU_REG_SEGMENT1_PARAMS_RT_OFFSET, cdu_params);
}
static void qed_cdu_init_pf(struct qed_hwfn *p_hwfn)
{
struct qed_ilt_client_cfg *p_cli;
struct qed_tid_seg *p_seg;
u32 cdu_seg_params, offset;
int i;
static const u32 rt_type_offset_arr[] = {
CDU_REG_PF_SEG0_TYPE_OFFSET_RT_OFFSET,
CDU_REG_PF_SEG1_TYPE_OFFSET_RT_OFFSET,
CDU_REG_PF_SEG2_TYPE_OFFSET_RT_OFFSET,
CDU_REG_PF_SEG3_TYPE_OFFSET_RT_OFFSET
};
static const u32 rt_type_offset_fl_arr[] = {
CDU_REG_PF_FL_SEG0_TYPE_OFFSET_RT_OFFSET,
CDU_REG_PF_FL_SEG1_TYPE_OFFSET_RT_OFFSET,
CDU_REG_PF_FL_SEG2_TYPE_OFFSET_RT_OFFSET,
CDU_REG_PF_FL_SEG3_TYPE_OFFSET_RT_OFFSET
};
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUT];
for (i = 0; i < NUM_TASK_PF_SEGMENTS; i++) {
p_seg = qed_cxt_tid_seg_info(p_hwfn, i);
if (!p_seg)
continue;
offset = (ILT_PAGE_IN_BYTES(p_cli->p_size.val) *
(p_cli->pf_blks[CDUT_SEG_BLK(i)].start_line -
p_cli->first.val)) / CDUT_SEG_ALIGNMET_IN_BYTES;
cdu_seg_params = 0;
SET_FIELD(cdu_seg_params, CDU_SEG_REG_TYPE, p_seg->type);
SET_FIELD(cdu_seg_params, CDU_SEG_REG_OFFSET, offset);
STORE_RT_REG(p_hwfn, rt_type_offset_arr[i], cdu_seg_params);
offset = (ILT_PAGE_IN_BYTES(p_cli->p_size.val) *
(p_cli->pf_blks[CDUT_FL_SEG_BLK(i, PF)].start_line -
p_cli->first.val)) / CDUT_SEG_ALIGNMET_IN_BYTES;
cdu_seg_params = 0;
SET_FIELD(cdu_seg_params, CDU_SEG_REG_TYPE, p_seg->type);
SET_FIELD(cdu_seg_params, CDU_SEG_REG_OFFSET, offset);
STORE_RT_REG(p_hwfn, rt_type_offset_fl_arr[i], cdu_seg_params);
}
}
void qed_qm_init_pf(struct qed_hwfn *p_hwfn)
{
struct qed_qm_pf_rt_init_params params;
struct qed_qm_info *qm_info = &p_hwfn->qm_info;
struct qed_qm_iids iids;
memset(&iids, 0, sizeof(iids));
qed_cxt_qm_iids(p_hwfn, &iids);
memset(&params, 0, sizeof(params));
params.port_id = p_hwfn->port_id;
params.pf_id = p_hwfn->rel_pf_id;
params.max_phys_tcs_per_port = qm_info->max_phys_tcs_per_port;
params.is_first_pf = p_hwfn->first_on_engine;
params.num_pf_cids = iids.cids;
params.num_vf_cids = iids.vf_cids;
params.start_pq = qm_info->start_pq;
params.num_pf_pqs = qm_info->num_pqs - qm_info->num_vf_pqs;
params.num_vf_pqs = qm_info->num_vf_pqs;
params.start_vport = qm_info->start_vport;
params.num_vports = qm_info->num_vports;
params.pf_wfq = qm_info->pf_wfq;
params.pf_rl = qm_info->pf_rl;
params.pq_params = qm_info->qm_pq_params;
params.vport_params = qm_info->qm_vport_params;
qed_qm_pf_rt_init(p_hwfn, p_hwfn->p_main_ptt, &params);
}
static int qed_cm_init_pf(struct qed_hwfn *p_hwfn)
{
union qed_qm_pq_params pq_params;
u16 pq;
memset(&pq_params, 0, sizeof(pq_params));
pq_params.core.tc = LB_TC;
pq = qed_get_qm_pq(p_hwfn, PROTOCOLID_CORE, &pq_params);
STORE_RT_REG(p_hwfn, XCM_REG_CON_PHY_Q3_RT_OFFSET, pq);
return 0;
}
static void qed_dq_init_pf(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 dq_pf_max_cid = 0, dq_vf_max_cid = 0;
dq_pf_max_cid += (p_mngr->conn_cfg[0].cid_count >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_0_RT_OFFSET, dq_pf_max_cid);
dq_vf_max_cid += (p_mngr->conn_cfg[0].cids_per_vf >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_0_RT_OFFSET, dq_vf_max_cid);
dq_pf_max_cid += (p_mngr->conn_cfg[1].cid_count >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_1_RT_OFFSET, dq_pf_max_cid);
dq_vf_max_cid += (p_mngr->conn_cfg[1].cids_per_vf >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_1_RT_OFFSET, dq_vf_max_cid);
dq_pf_max_cid += (p_mngr->conn_cfg[2].cid_count >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_2_RT_OFFSET, dq_pf_max_cid);
dq_vf_max_cid += (p_mngr->conn_cfg[2].cids_per_vf >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_2_RT_OFFSET, dq_vf_max_cid);
dq_pf_max_cid += (p_mngr->conn_cfg[3].cid_count >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_3_RT_OFFSET, dq_pf_max_cid);
dq_vf_max_cid += (p_mngr->conn_cfg[3].cids_per_vf >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_3_RT_OFFSET, dq_vf_max_cid);
dq_pf_max_cid += (p_mngr->conn_cfg[4].cid_count >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_4_RT_OFFSET, dq_pf_max_cid);
dq_vf_max_cid += (p_mngr->conn_cfg[4].cids_per_vf >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_4_RT_OFFSET, dq_vf_max_cid);
dq_pf_max_cid += (p_mngr->conn_cfg[5].cid_count >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_5_RT_OFFSET, dq_pf_max_cid);
dq_vf_max_cid += (p_mngr->conn_cfg[5].cids_per_vf >> DQ_RANGE_SHIFT);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_5_RT_OFFSET, dq_vf_max_cid);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_6_RT_OFFSET, dq_pf_max_cid);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_6_RT_OFFSET, dq_vf_max_cid);
STORE_RT_REG(p_hwfn, DORQ_REG_PF_MAX_ICID_7_RT_OFFSET, dq_pf_max_cid);
STORE_RT_REG(p_hwfn, DORQ_REG_VF_MAX_ICID_7_RT_OFFSET, dq_vf_max_cid);
}
static void qed_ilt_bounds_init(struct qed_hwfn *p_hwfn)
{
struct qed_ilt_client_cfg *ilt_clients;
int i;
ilt_clients = p_hwfn->p_cxt_mngr->clients;
for_each_ilt_valid_client(i, ilt_clients) {
STORE_RT_REG(p_hwfn,
ilt_clients[i].first.reg,
ilt_clients[i].first.val);
STORE_RT_REG(p_hwfn,
ilt_clients[i].last.reg, ilt_clients[i].last.val);
STORE_RT_REG(p_hwfn,
ilt_clients[i].p_size.reg,
ilt_clients[i].p_size.val);
}
}
static void qed_ilt_vf_bounds_init(struct qed_hwfn *p_hwfn)
{
struct qed_ilt_client_cfg *p_cli;
u32 blk_factor;
if (p_hwfn->cdev->p_iov_info) {
struct qed_hw_sriov_info *p_iov = p_hwfn->cdev->p_iov_info;
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_VF_BASE_RT_OFFSET,
p_iov->first_vf_in_pf);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_VF_LAST_ILT_RT_OFFSET,
p_iov->first_vf_in_pf + p_iov->total_vfs);
}
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC];
blk_factor = ilog2(ILT_PAGE_IN_BYTES(p_cli->p_size.val) >> 10);
if (p_cli->active) {
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_CDUC_BLOCKS_FACTOR_RT_OFFSET,
blk_factor);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_CDUC_NUMBER_OF_PF_BLOCKS_RT_OFFSET,
p_cli->pf_total_lines);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_CDUC_VF_BLOCKS_RT_OFFSET,
p_cli->vf_total_lines);
}
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUT];
blk_factor = ilog2(ILT_PAGE_IN_BYTES(p_cli->p_size.val) >> 10);
if (p_cli->active) {
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_CDUT_BLOCKS_FACTOR_RT_OFFSET,
blk_factor);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_CDUT_NUMBER_OF_PF_BLOCKS_RT_OFFSET,
p_cli->pf_total_lines);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_CDUT_VF_BLOCKS_RT_OFFSET,
p_cli->vf_total_lines);
}
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_TM];
blk_factor = ilog2(ILT_PAGE_IN_BYTES(p_cli->p_size.val) >> 10);
if (p_cli->active) {
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_TM_BLOCKS_FACTOR_RT_OFFSET, blk_factor);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_TM_NUMBER_OF_PF_BLOCKS_RT_OFFSET,
p_cli->pf_total_lines);
STORE_RT_REG(p_hwfn,
PSWRQ2_REG_TM_VF_BLOCKS_RT_OFFSET,
p_cli->vf_total_lines);
}
}
static void qed_ilt_init_pf(struct qed_hwfn *p_hwfn)
{
struct qed_ilt_client_cfg *clients;
struct qed_cxt_mngr *p_mngr;
struct qed_dma_mem *p_shdw;
u32 line, rt_offst, i;
qed_ilt_bounds_init(p_hwfn);
qed_ilt_vf_bounds_init(p_hwfn);
p_mngr = p_hwfn->p_cxt_mngr;
p_shdw = p_mngr->ilt_shadow;
clients = p_hwfn->p_cxt_mngr->clients;
for_each_ilt_valid_client(i, clients) {
line = clients[i].first.val - p_mngr->pf_start_line;
rt_offst = PSWRQ2_REG_ILT_MEMORY_RT_OFFSET +
clients[i].first.val * ILT_ENTRY_IN_REGS;
for (; line <= clients[i].last.val - p_mngr->pf_start_line;
line++, rt_offst += ILT_ENTRY_IN_REGS) {
u64 ilt_hw_entry = 0;
if (p_shdw[line].p_virt) {
SET_FIELD(ilt_hw_entry, ILT_ENTRY_VALID, 1ULL);
SET_FIELD(ilt_hw_entry, ILT_ENTRY_PHY_ADDR,
(p_shdw[line].p_phys >> 12));
DP_VERBOSE(p_hwfn, QED_MSG_ILT,
"Setting RT[0x%08x] from ILT[0x%08x] [Client is %d] to Physical addr: 0x%llx\n",
rt_offst, line, i,
(u64)(p_shdw[line].p_phys >> 12));
}
STORE_RT_REG_AGG(p_hwfn, rt_offst, ilt_hw_entry);
}
}
}
static void qed_src_init_pf(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 rounded_conn_num, conn_num, conn_max;
struct qed_src_iids src_iids;
memset(&src_iids, 0, sizeof(src_iids));
qed_cxt_src_iids(p_mngr, &src_iids);
conn_num = src_iids.pf_cids + src_iids.per_vf_cids * p_mngr->vf_count;
if (!conn_num)
return;
conn_max = max_t(u32, conn_num, SRC_MIN_NUM_ELEMS);
rounded_conn_num = roundup_pow_of_two(conn_max);
STORE_RT_REG(p_hwfn, SRC_REG_COUNTFREE_RT_OFFSET, conn_num);
STORE_RT_REG(p_hwfn, SRC_REG_NUMBER_HASH_BITS_RT_OFFSET,
ilog2(rounded_conn_num));
STORE_RT_REG_AGG(p_hwfn, SRC_REG_FIRSTFREE_RT_OFFSET,
p_hwfn->p_cxt_mngr->first_free);
STORE_RT_REG_AGG(p_hwfn, SRC_REG_LASTFREE_RT_OFFSET,
p_hwfn->p_cxt_mngr->last_free);
}
static void qed_tm_init_pf(struct qed_hwfn *p_hwfn)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 active_seg_mask = 0, tm_offset, rt_reg;
struct qed_tm_iids tm_iids;
u64 cfg_word;
u8 i;
memset(&tm_iids, 0, sizeof(tm_iids));
qed_cxt_tm_iids(p_mngr, &tm_iids);
for (i = 0; i < p_mngr->vf_count; i++) {
cfg_word = 0;
SET_FIELD(cfg_word, TM_CFG_NUM_IDS, tm_iids.per_vf_cids);
SET_FIELD(cfg_word, TM_CFG_PRE_SCAN_OFFSET, 0);
SET_FIELD(cfg_word, TM_CFG_PARENT_PF, p_hwfn->rel_pf_id);
SET_FIELD(cfg_word, TM_CFG_CID_PRE_SCAN_ROWS, 0);
rt_reg = TM_REG_CONFIG_CONN_MEM_RT_OFFSET +
(sizeof(cfg_word) / sizeof(u32)) *
(p_hwfn->cdev->p_iov_info->first_vf_in_pf + i);
STORE_RT_REG_AGG(p_hwfn, rt_reg, cfg_word);
}
cfg_word = 0;
SET_FIELD(cfg_word, TM_CFG_NUM_IDS, tm_iids.pf_cids);
SET_FIELD(cfg_word, TM_CFG_PRE_SCAN_OFFSET, 0);
SET_FIELD(cfg_word, TM_CFG_PARENT_PF, 0);
SET_FIELD(cfg_word, TM_CFG_CID_PRE_SCAN_ROWS, 0);
rt_reg = TM_REG_CONFIG_CONN_MEM_RT_OFFSET +
(sizeof(cfg_word) / sizeof(u32)) *
(NUM_OF_VFS(p_hwfn->cdev) + p_hwfn->rel_pf_id);
STORE_RT_REG_AGG(p_hwfn, rt_reg, cfg_word);
STORE_RT_REG(p_hwfn, TM_REG_PF_ENABLE_CONN_RT_OFFSET,
tm_iids.pf_cids ? 0x1 : 0x0);
tm_offset = tm_iids.per_vf_cids;
for (i = 0; i < p_mngr->vf_count; i++) {
cfg_word = 0;
SET_FIELD(cfg_word, TM_CFG_NUM_IDS, tm_iids.per_vf_tids);
SET_FIELD(cfg_word, TM_CFG_PRE_SCAN_OFFSET, 0);
SET_FIELD(cfg_word, TM_CFG_PARENT_PF, p_hwfn->rel_pf_id);
SET_FIELD(cfg_word, TM_CFG_TID_OFFSET, tm_offset);
SET_FIELD(cfg_word, TM_CFG_TID_PRE_SCAN_ROWS, (u64) 0);
rt_reg = TM_REG_CONFIG_TASK_MEM_RT_OFFSET +
(sizeof(cfg_word) / sizeof(u32)) *
(p_hwfn->cdev->p_iov_info->first_vf_in_pf + i);
STORE_RT_REG_AGG(p_hwfn, rt_reg, cfg_word);
}
tm_offset = tm_iids.pf_cids;
for (i = 0; i < NUM_TASK_PF_SEGMENTS; i++) {
cfg_word = 0;
SET_FIELD(cfg_word, TM_CFG_NUM_IDS, tm_iids.pf_tids[i]);
SET_FIELD(cfg_word, TM_CFG_PRE_SCAN_OFFSET, 0);
SET_FIELD(cfg_word, TM_CFG_PARENT_PF, 0);
SET_FIELD(cfg_word, TM_CFG_TID_OFFSET, tm_offset);
SET_FIELD(cfg_word, TM_CFG_TID_PRE_SCAN_ROWS, (u64) 0);
rt_reg = TM_REG_CONFIG_TASK_MEM_RT_OFFSET +
(sizeof(cfg_word) / sizeof(u32)) *
(NUM_OF_VFS(p_hwfn->cdev) +
p_hwfn->rel_pf_id * NUM_TASK_PF_SEGMENTS + i);
STORE_RT_REG_AGG(p_hwfn, rt_reg, cfg_word);
active_seg_mask |= (tm_iids.pf_tids[i] ? BIT(i) : 0);
tm_offset += tm_iids.pf_tids[i];
}
if (p_hwfn->hw_info.personality == QED_PCI_ETH_ROCE)
active_seg_mask = 0;
STORE_RT_REG(p_hwfn, TM_REG_PF_ENABLE_TASK_RT_OFFSET, active_seg_mask);
}
void qed_cxt_hw_init_common(struct qed_hwfn *p_hwfn)
{
qed_cdu_init_common(p_hwfn);
}
void qed_cxt_hw_init_pf(struct qed_hwfn *p_hwfn)
{
qed_qm_init_pf(p_hwfn);
qed_cm_init_pf(p_hwfn);
qed_dq_init_pf(p_hwfn);
qed_cdu_init_pf(p_hwfn);
qed_ilt_init_pf(p_hwfn);
qed_src_init_pf(p_hwfn);
qed_tm_init_pf(p_hwfn);
}
int qed_cxt_acquire_cid(struct qed_hwfn *p_hwfn,
enum protocol_type type, u32 *p_cid)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 rel_cid;
if (type >= MAX_CONN_TYPES || !p_mngr->acquired[type].cid_map) {
DP_NOTICE(p_hwfn, "Invalid protocol type %d", type);
return -EINVAL;
}
rel_cid = find_first_zero_bit(p_mngr->acquired[type].cid_map,
p_mngr->acquired[type].max_count);
if (rel_cid >= p_mngr->acquired[type].max_count) {
DP_NOTICE(p_hwfn, "no CID available for protocol %d\n", type);
return -EINVAL;
}
__set_bit(rel_cid, p_mngr->acquired[type].cid_map);
*p_cid = rel_cid + p_mngr->acquired[type].start_cid;
return 0;
}
static bool qed_cxt_test_cid_acquired(struct qed_hwfn *p_hwfn,
u32 cid, enum protocol_type *p_type)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
struct qed_cid_acquired_map *p_map;
enum protocol_type p;
u32 rel_cid;
for (p = 0; p < MAX_CONN_TYPES; p++) {
p_map = &p_mngr->acquired[p];
if (!p_map->cid_map)
continue;
if (cid >= p_map->start_cid &&
cid < p_map->start_cid + p_map->max_count)
break;
}
*p_type = p;
if (p == MAX_CONN_TYPES) {
DP_NOTICE(p_hwfn, "Invalid CID %d", cid);
return false;
}
rel_cid = cid - p_map->start_cid;
if (!test_bit(rel_cid, p_map->cid_map)) {
DP_NOTICE(p_hwfn, "CID %d not acquired", cid);
return false;
}
return true;
}
void qed_cxt_release_cid(struct qed_hwfn *p_hwfn, u32 cid)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
enum protocol_type type;
bool b_acquired;
u32 rel_cid;
b_acquired = qed_cxt_test_cid_acquired(p_hwfn, cid, &type);
if (!b_acquired)
return;
rel_cid = cid - p_mngr->acquired[type].start_cid;
__clear_bit(rel_cid, p_mngr->acquired[type].cid_map);
}
int qed_cxt_get_cid_info(struct qed_hwfn *p_hwfn, struct qed_cxt_info *p_info)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 conn_cxt_size, hw_p_size, cxts_per_p, line;
enum protocol_type type;
bool b_acquired;
b_acquired = qed_cxt_test_cid_acquired(p_hwfn, p_info->iid, &type);
if (!b_acquired)
return -EINVAL;
p_info->type = type;
hw_p_size = p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC].p_size.val;
conn_cxt_size = CONN_CXT_SIZE(p_hwfn);
cxts_per_p = ILT_PAGE_IN_BYTES(hw_p_size) / conn_cxt_size;
line = p_info->iid / cxts_per_p;
if (!p_mngr->ilt_shadow[line].p_virt)
return -EINVAL;
p_info->p_cxt = p_mngr->ilt_shadow[line].p_virt +
p_info->iid % cxts_per_p * conn_cxt_size;
DP_VERBOSE(p_hwfn, (QED_MSG_ILT | QED_MSG_CXT),
"Accessing ILT shadow[%d]: CXT pointer is at %p (for iid %d)\n",
p_info->iid / cxts_per_p, p_info->p_cxt, p_info->iid);
return 0;
}
static void qed_rdma_set_pf_params(struct qed_hwfn *p_hwfn,
struct qed_rdma_pf_params *p_params)
{
u32 num_cons, num_tasks, num_qps, num_mrs, num_srqs;
enum protocol_type proto;
num_mrs = min_t(u32, RDMA_MAX_TIDS, p_params->num_mrs);
num_tasks = num_mrs;
num_srqs = min_t(u32, 32 * 1024, p_params->num_srqs);
switch (p_hwfn->hw_info.personality) {
case QED_PCI_ETH_ROCE:
num_qps = min_t(u32, ROCE_MAX_QPS, p_params->num_qps);
num_cons = num_qps * 2;
proto = PROTOCOLID_ROCE;
break;
default:
return;
}
if (num_cons && num_tasks) {
qed_cxt_set_proto_cid_count(p_hwfn, proto, num_cons, 0);
qed_cxt_set_proto_tid_count(p_hwfn, PROTOCOLID_ROCE,
QED_CXT_ROCE_TID_SEG, 1,
num_tasks, false);
qed_cxt_set_srq_count(p_hwfn, num_srqs);
} else {
DP_INFO(p_hwfn->cdev,
"RDMA personality used without setting params!\n");
}
}
int qed_cxt_set_pf_params(struct qed_hwfn *p_hwfn)
{
u32 core_cids = 1;
if (p_hwfn->using_ll2)
core_cids += 4;
qed_cxt_set_proto_cid_count(p_hwfn, PROTOCOLID_CORE, core_cids, 0);
switch (p_hwfn->hw_info.personality) {
case QED_PCI_ETH_ROCE:
{
qed_rdma_set_pf_params(p_hwfn,
&p_hwfn->
pf_params.rdma_pf_params);
}
case QED_PCI_ETH:
{
struct qed_eth_pf_params *p_params =
&p_hwfn->pf_params.eth_pf_params;
qed_cxt_set_proto_cid_count(p_hwfn, PROTOCOLID_ETH,
p_params->num_cons, 1);
break;
}
case QED_PCI_ISCSI:
{
struct qed_iscsi_pf_params *p_params;
p_params = &p_hwfn->pf_params.iscsi_pf_params;
if (p_params->num_cons && p_params->num_tasks) {
qed_cxt_set_proto_cid_count(p_hwfn,
PROTOCOLID_ISCSI,
p_params->num_cons,
0);
qed_cxt_set_proto_tid_count(p_hwfn,
PROTOCOLID_ISCSI,
QED_CXT_ISCSI_TID_SEG,
0,
p_params->num_tasks,
true);
} else {
DP_INFO(p_hwfn->cdev,
"Iscsi personality used without setting params!\n");
}
break;
}
default:
return -EINVAL;
}
return 0;
}
int qed_cxt_get_tid_mem_info(struct qed_hwfn *p_hwfn,
struct qed_tid_mem *p_info)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
u32 proto, seg, total_lines, i, shadow_line;
struct qed_ilt_client_cfg *p_cli;
struct qed_ilt_cli_blk *p_fl_seg;
struct qed_tid_seg *p_seg_info;
switch (p_hwfn->hw_info.personality) {
case QED_PCI_ISCSI:
proto = PROTOCOLID_ISCSI;
seg = QED_CXT_ISCSI_TID_SEG;
break;
default:
return -EINVAL;
}
p_cli = &p_mngr->clients[ILT_CLI_CDUT];
if (!p_cli->active)
return -EINVAL;
p_seg_info = &p_mngr->conn_cfg[proto].tid_seg[seg];
if (!p_seg_info->has_fl_mem)
return -EINVAL;
p_fl_seg = &p_cli->pf_blks[CDUT_FL_SEG_BLK(seg, PF)];
total_lines = DIV_ROUND_UP(p_fl_seg->total_size,
p_fl_seg->real_size_in_page);
for (i = 0; i < total_lines; i++) {
shadow_line = i + p_fl_seg->start_line -
p_hwfn->p_cxt_mngr->pf_start_line;
p_info->blocks[i] = p_mngr->ilt_shadow[shadow_line].p_virt;
}
p_info->waste = ILT_PAGE_IN_BYTES(p_cli->p_size.val) -
p_fl_seg->real_size_in_page;
p_info->tid_size = p_mngr->task_type_size[p_seg_info->type];
p_info->num_tids_per_block = p_fl_seg->real_size_in_page /
p_info->tid_size;
return 0;
}
int
qed_cxt_dynamic_ilt_alloc(struct qed_hwfn *p_hwfn,
enum qed_cxt_elem_type elem_type, u32 iid)
{
u32 reg_offset, shadow_line, elem_size, hw_p_size, elems_per_p, line;
struct qed_ilt_client_cfg *p_cli;
struct qed_ilt_cli_blk *p_blk;
struct qed_ptt *p_ptt;
dma_addr_t p_phys;
u64 ilt_hw_entry;
void *p_virt;
int rc = 0;
switch (elem_type) {
case QED_ELEM_CXT:
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC];
elem_size = CONN_CXT_SIZE(p_hwfn);
p_blk = &p_cli->pf_blks[CDUC_BLK];
break;
case QED_ELEM_SRQ:
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_TSDM];
elem_size = SRQ_CXT_SIZE;
p_blk = &p_cli->pf_blks[SRQ_BLK];
break;
case QED_ELEM_TASK:
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUT];
elem_size = TYPE1_TASK_CXT_SIZE(p_hwfn);
p_blk = &p_cli->pf_blks[CDUT_SEG_BLK(QED_CXT_ROCE_TID_SEG)];
break;
default:
DP_NOTICE(p_hwfn, "-EINVALID elem type = %d", elem_type);
return -EINVAL;
}
hw_p_size = p_cli->p_size.val;
elems_per_p = ILT_PAGE_IN_BYTES(hw_p_size) / elem_size;
line = p_blk->start_line + (iid / elems_per_p);
shadow_line = line - p_hwfn->p_cxt_mngr->pf_start_line;
mutex_lock(&p_hwfn->p_cxt_mngr->mutex);
if (p_hwfn->p_cxt_mngr->ilt_shadow[shadow_line].p_virt)
goto out0;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt) {
DP_NOTICE(p_hwfn,
"QED_TIME_OUT on ptt acquire - dynamic allocation");
rc = -EBUSY;
goto out0;
}
p_virt = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
p_blk->real_size_in_page,
&p_phys, GFP_KERNEL);
if (!p_virt) {
rc = -ENOMEM;
goto out1;
}
memset(p_virt, 0, p_blk->real_size_in_page);
if (elem_type == QED_ELEM_TASK) {
u32 elem_i;
u8 *elem_start = (u8 *)p_virt;
union type1_task_context *elem;
for (elem_i = 0; elem_i < elems_per_p; elem_i++) {
elem = (union type1_task_context *)elem_start;
SET_FIELD(elem->roce_ctx.tdif_context.flags1,
TDIF_TASK_CONTEXT_REFTAGMASK, 0xf);
elem_start += TYPE1_TASK_CXT_SIZE(p_hwfn);
}
}
p_hwfn->p_cxt_mngr->ilt_shadow[shadow_line].p_virt = p_virt;
p_hwfn->p_cxt_mngr->ilt_shadow[shadow_line].p_phys = p_phys;
p_hwfn->p_cxt_mngr->ilt_shadow[shadow_line].size =
p_blk->real_size_in_page;
reg_offset = PSWRQ2_REG_ILT_MEMORY +
(line * ILT_REG_SIZE_IN_BYTES * ILT_ENTRY_IN_REGS);
ilt_hw_entry = 0;
SET_FIELD(ilt_hw_entry, ILT_ENTRY_VALID, 1ULL);
SET_FIELD(ilt_hw_entry,
ILT_ENTRY_PHY_ADDR,
(p_hwfn->p_cxt_mngr->ilt_shadow[shadow_line].p_phys >> 12));
qed_dmae_host2grc(p_hwfn, p_ptt, (u64) (uintptr_t)&ilt_hw_entry,
reg_offset, sizeof(ilt_hw_entry) / sizeof(u32), 0);
if (elem_type == QED_ELEM_CXT) {
u32 last_cid_allocated = (1 + (iid / elems_per_p)) *
elems_per_p;
qed_wr(p_hwfn, p_ptt, PRS_REG_ROCE_DEST_QP_MAX_PF,
last_cid_allocated - 1);
if (!p_hwfn->b_rdma_enabled_in_prs) {
qed_wr(p_hwfn, p_ptt, p_hwfn->rdma_prs_search_reg, 1);
p_hwfn->b_rdma_enabled_in_prs = true;
}
}
out1:
qed_ptt_release(p_hwfn, p_ptt);
out0:
mutex_unlock(&p_hwfn->p_cxt_mngr->mutex);
return rc;
}
static int
qed_cxt_free_ilt_range(struct qed_hwfn *p_hwfn,
enum qed_cxt_elem_type elem_type,
u32 start_iid, u32 count)
{
u32 start_line, end_line, shadow_start_line, shadow_end_line;
u32 reg_offset, elem_size, hw_p_size, elems_per_p;
struct qed_ilt_client_cfg *p_cli;
struct qed_ilt_cli_blk *p_blk;
u32 end_iid = start_iid + count;
struct qed_ptt *p_ptt;
u64 ilt_hw_entry = 0;
u32 i;
switch (elem_type) {
case QED_ELEM_CXT:
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUC];
elem_size = CONN_CXT_SIZE(p_hwfn);
p_blk = &p_cli->pf_blks[CDUC_BLK];
break;
case QED_ELEM_SRQ:
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_TSDM];
elem_size = SRQ_CXT_SIZE;
p_blk = &p_cli->pf_blks[SRQ_BLK];
break;
case QED_ELEM_TASK:
p_cli = &p_hwfn->p_cxt_mngr->clients[ILT_CLI_CDUT];
elem_size = TYPE1_TASK_CXT_SIZE(p_hwfn);
p_blk = &p_cli->pf_blks[CDUT_SEG_BLK(QED_CXT_ROCE_TID_SEG)];
break;
default:
DP_NOTICE(p_hwfn, "-EINVALID elem type = %d", elem_type);
return -EINVAL;
}
hw_p_size = p_cli->p_size.val;
elems_per_p = ILT_PAGE_IN_BYTES(hw_p_size) / elem_size;
start_line = p_blk->start_line + (start_iid / elems_per_p);
end_line = p_blk->start_line + (end_iid / elems_per_p);
if (((end_iid + 1) / elems_per_p) != (end_iid / elems_per_p))
end_line--;
shadow_start_line = start_line - p_hwfn->p_cxt_mngr->pf_start_line;
shadow_end_line = end_line - p_hwfn->p_cxt_mngr->pf_start_line;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt) {
DP_NOTICE(p_hwfn,
"QED_TIME_OUT on ptt acquire - dynamic allocation");
return -EBUSY;
}
for (i = shadow_start_line; i < shadow_end_line; i++) {
if (!p_hwfn->p_cxt_mngr->ilt_shadow[i].p_virt)
continue;
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
p_hwfn->p_cxt_mngr->ilt_shadow[i].size,
p_hwfn->p_cxt_mngr->ilt_shadow[i].p_virt,
p_hwfn->p_cxt_mngr->ilt_shadow[i].p_phys);
p_hwfn->p_cxt_mngr->ilt_shadow[i].p_virt = NULL;
p_hwfn->p_cxt_mngr->ilt_shadow[i].p_phys = 0;
p_hwfn->p_cxt_mngr->ilt_shadow[i].size = 0;
reg_offset = PSWRQ2_REG_ILT_MEMORY +
((start_line++) * ILT_REG_SIZE_IN_BYTES *
ILT_ENTRY_IN_REGS);
qed_dmae_host2grc(p_hwfn, p_ptt,
(u64) (uintptr_t) &ilt_hw_entry,
reg_offset,
sizeof(ilt_hw_entry) / sizeof(u32),
0);
}
qed_ptt_release(p_hwfn, p_ptt);
return 0;
}
int qed_cxt_free_proto_ilt(struct qed_hwfn *p_hwfn, enum protocol_type proto)
{
int rc;
u32 cid;
rc = qed_cxt_free_ilt_range(p_hwfn, QED_ELEM_CXT,
qed_cxt_get_proto_cid_start(p_hwfn,
proto),
qed_cxt_get_proto_cid_count(p_hwfn,
proto, &cid));
if (rc)
return rc;
rc = qed_cxt_free_ilt_range(p_hwfn, QED_ELEM_TASK, 0,
qed_cxt_get_proto_tid_count(p_hwfn, proto));
if (rc)
return rc;
rc = qed_cxt_free_ilt_range(p_hwfn, QED_ELEM_SRQ, 0,
qed_cxt_get_srq_count(p_hwfn));
return rc;
}
int qed_cxt_get_task_ctx(struct qed_hwfn *p_hwfn,
u32 tid, u8 ctx_type, void **pp_task_ctx)
{
struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
struct qed_ilt_client_cfg *p_cli;
struct qed_ilt_cli_blk *p_seg;
struct qed_tid_seg *p_seg_info;
u32 proto, seg;
u32 total_lines;
u32 tid_size, ilt_idx;
u32 num_tids_per_block;
switch (p_hwfn->hw_info.personality) {
case QED_PCI_ISCSI:
proto = PROTOCOLID_ISCSI;
seg = QED_CXT_ISCSI_TID_SEG;
break;
default:
return -EINVAL;
}
p_cli = &p_mngr->clients[ILT_CLI_CDUT];
if (!p_cli->active)
return -EINVAL;
p_seg_info = &p_mngr->conn_cfg[proto].tid_seg[seg];
if (ctx_type == QED_CTX_WORKING_MEM) {
p_seg = &p_cli->pf_blks[CDUT_SEG_BLK(seg)];
} else if (ctx_type == QED_CTX_FL_MEM) {
if (!p_seg_info->has_fl_mem)
return -EINVAL;
p_seg = &p_cli->pf_blks[CDUT_FL_SEG_BLK(seg, PF)];
} else {
return -EINVAL;
}
total_lines = DIV_ROUND_UP(p_seg->total_size, p_seg->real_size_in_page);
tid_size = p_mngr->task_type_size[p_seg_info->type];
num_tids_per_block = p_seg->real_size_in_page / tid_size;
if (total_lines < tid / num_tids_per_block)
return -EINVAL;
ilt_idx = tid / num_tids_per_block + p_seg->start_line -
p_mngr->pf_start_line;
*pp_task_ctx = (u8 *)p_mngr->ilt_shadow[ilt_idx].p_virt +
(tid % num_tids_per_block) * tid_size;
return 0;
}
