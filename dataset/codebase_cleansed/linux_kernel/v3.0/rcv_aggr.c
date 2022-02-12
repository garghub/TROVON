void *
aggr_init(ALLOC_NETBUFS netbuf_allocator)
{
struct aggr_info *p_aggr = NULL;
struct rxtid *rxtid;
u8 i;
int status = 0;
A_PRINTF("In aggr_init..\n");
do {
p_aggr = A_MALLOC(sizeof(struct aggr_info));
if(!p_aggr) {
A_PRINTF("Failed to allocate memory for aggr_node\n");
status = A_ERROR;
break;
}
A_MEMZERO(p_aggr, sizeof(struct aggr_info));
p_aggr->aggr_sz = AGGR_SZ_DEFAULT;
A_INIT_TIMER(&p_aggr->timer, aggr_timeout, p_aggr);
p_aggr->timerScheduled = false;
A_NETBUF_QUEUE_INIT(&p_aggr->freeQ);
p_aggr->netbuf_allocator = netbuf_allocator;
p_aggr->netbuf_allocator(&p_aggr->freeQ, AGGR_NUM_OF_FREE_NETBUFS);
for(i = 0; i < NUM_OF_TIDS; i++) {
rxtid = AGGR_GET_RXTID(p_aggr, i);
rxtid->aggr = false;
rxtid->progress = false;
rxtid->timerMon = false;
A_NETBUF_QUEUE_INIT(&rxtid->q);
A_MUTEX_INIT(&rxtid->lock);
}
}while(false);
A_PRINTF("going out of aggr_init..status %s\n",
(status == 0) ? "OK":"Error");
if (status) {
aggr_module_destroy(p_aggr);
}
return ((status == 0) ? p_aggr : NULL);
}
static void
aggr_delete_tid_state(struct aggr_info *p_aggr, u8 tid)
{
struct rxtid *rxtid;
struct rxtid_stats *stats;
A_ASSERT(tid < NUM_OF_TIDS && p_aggr);
rxtid = AGGR_GET_RXTID(p_aggr, tid);
stats = AGGR_GET_RXTID_STATS(p_aggr, tid);
if(rxtid->aggr) {
aggr_deque_frms(p_aggr, tid, 0, ALL_SEQNO);
}
rxtid->aggr = false;
rxtid->progress = false;
rxtid->timerMon = false;
rxtid->win_sz = 0;
rxtid->seq_next = 0;
rxtid->hold_q_sz = 0;
if(rxtid->hold_q) {
kfree(rxtid->hold_q);
rxtid->hold_q = NULL;
}
A_MEMZERO(stats, sizeof(struct rxtid_stats));
}
void
aggr_module_destroy(void *cntxt)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
struct rxtid *rxtid;
u8 i, k;
A_PRINTF("%s(): aggr = %p\n",_A_FUNCNAME_, p_aggr);
A_ASSERT(p_aggr);
if(p_aggr) {
if(p_aggr->timerScheduled) {
A_UNTIMEOUT(&p_aggr->timer);
p_aggr->timerScheduled = false;
}
for(i = 0; i < NUM_OF_TIDS; i++) {
rxtid = AGGR_GET_RXTID(p_aggr, i);
if(rxtid->hold_q) {
for(k = 0; k< rxtid->hold_q_sz; k++) {
if(rxtid->hold_q[k].osbuf) {
A_NETBUF_FREE(rxtid->hold_q[k].osbuf);
}
}
kfree(rxtid->hold_q);
}
while(A_NETBUF_QUEUE_SIZE(&rxtid->q)) {
A_NETBUF_FREE(A_NETBUF_DEQUEUE(&rxtid->q));
}
if (A_IS_MUTEX_VALID(&rxtid->lock)) {
A_MUTEX_DELETE(&rxtid->lock);
}
}
while(A_NETBUF_QUEUE_SIZE(&p_aggr->freeQ)) {
A_NETBUF_FREE(A_NETBUF_DEQUEUE(&p_aggr->freeQ));
}
kfree(p_aggr);
}
A_PRINTF("out aggr_module_destroy\n");
}
void
aggr_register_rx_dispatcher(void *cntxt, void * dev, RX_CALLBACK fn)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
A_ASSERT(p_aggr && fn && dev);
p_aggr->rx_fn = fn;
p_aggr->dev = dev;
}
void
aggr_process_bar(void *cntxt, u8 tid, u16 seq_no)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
struct rxtid_stats *stats;
A_ASSERT(p_aggr);
stats = AGGR_GET_RXTID_STATS(p_aggr, tid);
stats->num_bar++;
aggr_deque_frms(p_aggr, tid, seq_no, ALL_SEQNO);
}
void
aggr_recv_addba_req_evt(void *cntxt, u8 tid, u16 seq_no, u8 win_sz)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
struct rxtid *rxtid;
struct rxtid_stats *stats;
A_ASSERT(p_aggr);
rxtid = AGGR_GET_RXTID(p_aggr, tid);
stats = AGGR_GET_RXTID_STATS(p_aggr, tid);
A_PRINTF("%s(): win_sz = %d aggr %d\n", _A_FUNCNAME_, win_sz, rxtid->aggr);
if(win_sz < AGGR_WIN_SZ_MIN || win_sz > AGGR_WIN_SZ_MAX) {
A_PRINTF("win_sz %d, tid %d\n", win_sz, tid);
}
if(rxtid->aggr) {
aggr_delete_tid_state(p_aggr, tid);
}
rxtid->seq_next = seq_no;
rxtid->hold_q = A_MALLOC(HOLD_Q_SZ(win_sz));
if((rxtid->hold_q == NULL)) {
A_PRINTF("Failed to allocate memory, tid = %d\n", tid);
A_ASSERT(0);
}
A_MEMZERO(rxtid->hold_q, HOLD_Q_SZ(win_sz));
rxtid->win_sz = win_sz;
rxtid->hold_q_sz = TID_WINDOW_SZ(win_sz);
if(A_NETBUF_QUEUE_SIZE(&rxtid->q) != 0) {
A_PRINTF("ERROR: Frames still on queue ?\n");
A_ASSERT(0);
}
rxtid->aggr = true;
}
void
aggr_recv_delba_req_evt(void *cntxt, u8 tid)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
struct rxtid *rxtid;
A_ASSERT(p_aggr);
A_PRINTF("%s(): tid %d\n", _A_FUNCNAME_, tid);
rxtid = AGGR_GET_RXTID(p_aggr, tid);
if(rxtid->aggr) {
aggr_delete_tid_state(p_aggr, tid);
}
}
static void
aggr_deque_frms(struct aggr_info *p_aggr, u8 tid, u16 seq_no, u8 order)
{
struct rxtid *rxtid;
struct osbuf_hold_q *node;
u16 idx, idx_end, seq_end;
struct rxtid_stats *stats;
A_ASSERT(p_aggr);
rxtid = AGGR_GET_RXTID(p_aggr, tid);
stats = AGGR_GET_RXTID_STATS(p_aggr, tid);
idx = AGGR_WIN_IDX(rxtid->seq_next, rxtid->hold_q_sz);
seq_end = (seq_no) ? seq_no : rxtid->seq_next;
idx_end = AGGR_WIN_IDX(seq_end, rxtid->hold_q_sz);
A_MUTEX_LOCK(&rxtid->lock);
do {
node = &rxtid->hold_q[idx];
if((order == CONTIGUOUS_SEQNO) && (!node->osbuf))
break;
if(node->osbuf) {
if(node->is_amsdu) {
aggr_slice_amsdu(p_aggr, rxtid, &node->osbuf);
} else {
A_NETBUF_ENQUEUE(&rxtid->q, node->osbuf);
}
node->osbuf = NULL;
} else {
stats->num_hole++;
}
rxtid->seq_next = IEEE80211_NEXT_SEQ_NO(rxtid->seq_next);
idx = AGGR_WIN_IDX(rxtid->seq_next, rxtid->hold_q_sz);
} while(idx != idx_end);
A_MUTEX_UNLOCK(&rxtid->lock);
stats->num_delivered += A_NETBUF_QUEUE_SIZE(&rxtid->q);
aggr_dispatch_frames(p_aggr, &rxtid->q);
}
static void *
aggr_get_osbuf(struct aggr_info *p_aggr)
{
void *buf = NULL;
if (A_NETBUF_QUEUE_SIZE(&p_aggr->freeQ) < (AGGR_NUM_OF_FREE_NETBUFS >> 2)) {
p_aggr->netbuf_allocator(&p_aggr->freeQ, AGGR_NUM_OF_FREE_NETBUFS);
}
if (A_NETBUF_QUEUE_SIZE(&p_aggr->freeQ)) {
buf = A_NETBUF_DEQUEUE(&p_aggr->freeQ);
}
return buf;
}
static void
aggr_slice_amsdu(struct aggr_info *p_aggr, struct rxtid *rxtid, void **osbuf)
{
void *new_buf;
u16 frame_8023_len, payload_8023_len, mac_hdr_len, amsdu_len;
u8 *framep;
mac_hdr_len = sizeof(ATH_MAC_HDR);
framep = A_NETBUF_DATA(*osbuf) + mac_hdr_len;
amsdu_len = A_NETBUF_LEN(*osbuf) - mac_hdr_len;
while(amsdu_len > mac_hdr_len) {
payload_8023_len = A_BE2CPU16(((ATH_MAC_HDR *)framep)->typeOrLen);
#define MAX_MSDU_SUBFRAME_PAYLOAD_LEN 1508
#define MIN_MSDU_SUBFRAME_PAYLOAD_LEN 46
if(payload_8023_len < MIN_MSDU_SUBFRAME_PAYLOAD_LEN || payload_8023_len > MAX_MSDU_SUBFRAME_PAYLOAD_LEN) {
A_PRINTF("802.3 AMSDU frame bound check failed. len %d\n", payload_8023_len);
break;
}
frame_8023_len = payload_8023_len + mac_hdr_len;
new_buf = aggr_get_osbuf(p_aggr);
if(new_buf == NULL) {
A_PRINTF("No buffer available \n");
break;
}
memcpy(A_NETBUF_DATA(new_buf), framep, frame_8023_len);
A_NETBUF_PUT(new_buf, frame_8023_len);
if (wmi_dot3_2_dix(new_buf) != 0) {
A_PRINTF("dot3_2_dix err..\n");
A_NETBUF_FREE(new_buf);
break;
}
A_NETBUF_ENQUEUE(&rxtid->q, new_buf);
if ((amsdu_len - frame_8023_len) == 0) {
break;
}
frame_8023_len = ((frame_8023_len + 3) & ~3);
framep += frame_8023_len;
amsdu_len -= frame_8023_len;
}
A_NETBUF_FREE(*osbuf);
*osbuf = NULL;
}
void
aggr_process_recv_frm(void *cntxt, u8 tid, u16 seq_no, bool is_amsdu, void **osbuf)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
struct rxtid *rxtid;
struct rxtid_stats *stats;
u16 idx, st, cur, end;
u16 *log_idx;
struct osbuf_hold_q *node;
PACKET_LOG *log;
A_ASSERT(p_aggr);
A_ASSERT(tid < NUM_OF_TIDS);
rxtid = AGGR_GET_RXTID(p_aggr, tid);
stats = AGGR_GET_RXTID_STATS(p_aggr, tid);
stats->num_into_aggr++;
if(!rxtid->aggr) {
if(is_amsdu) {
aggr_slice_amsdu(p_aggr, rxtid, osbuf);
stats->num_amsdu++;
aggr_dispatch_frames(p_aggr, &rxtid->q);
}
return;
}
st = rxtid->seq_next;
cur = seq_no;
end = (st + rxtid->hold_q_sz-1) & IEEE80211_MAX_SEQ_NO;
log = &p_aggr->pkt_log;
log_idx = &log->last_idx;
log->info[*log_idx].cur = cur;
log->info[*log_idx].st = st;
log->info[*log_idx].end = end;
*log_idx = IEEE80211_NEXT_SEQ_NO(*log_idx);
if(((st < end) && (cur < st || cur > end)) ||
((st > end) && (cur > end) && (cur < st))) {
u16 extended_end;
extended_end = (end + rxtid->hold_q_sz-1) & IEEE80211_MAX_SEQ_NO;
if(((end < extended_end) && (cur < end || cur > extended_end)) ||
((end > extended_end) && (cur > extended_end) && (cur < end))) {
aggr_deque_frms(p_aggr, tid, 0, ALL_SEQNO);
if(cur >= rxtid->hold_q_sz-1) {
rxtid->seq_next = cur - (rxtid->hold_q_sz-1);
}else{
rxtid->seq_next = IEEE80211_MAX_SEQ_NO - (rxtid->hold_q_sz-2 - cur);
}
} else {
if(cur >= rxtid->hold_q_sz-1) {
st = cur - (rxtid->hold_q_sz-1);
}else{
st = IEEE80211_MAX_SEQ_NO - (rxtid->hold_q_sz-2 - cur);
}
aggr_deque_frms(p_aggr, tid, st, ALL_SEQNO);
}
stats->num_oow++;
}
idx = AGGR_WIN_IDX(seq_no, rxtid->hold_q_sz);
node = &rxtid->hold_q[idx];
A_MUTEX_LOCK(&rxtid->lock);
if(node->osbuf) {
A_NETBUF_FREE(node->osbuf);
stats->num_dups++;
}
node->osbuf = *osbuf;
node->is_amsdu = is_amsdu;
node->seq_no = seq_no;
if(node->is_amsdu) {
stats->num_amsdu++;
} else {
stats->num_mpdu++;
}
A_MUTEX_UNLOCK(&rxtid->lock);
*osbuf = NULL;
aggr_deque_frms(p_aggr, tid, 0, CONTIGUOUS_SEQNO);
if(p_aggr->timerScheduled) {
rxtid->progress = true;
}else{
for(idx=0 ; idx<rxtid->hold_q_sz ; idx++) {
if(rxtid->hold_q[idx].osbuf) {
p_aggr->timerScheduled = true;
A_TIMEOUT_MS(&p_aggr->timer, AGGR_RX_TIMEOUT, 0);
rxtid->progress = false;
rxtid->timerMon = true;
break;
}
}
}
}
void
aggr_reset_state(void *cntxt)
{
u8 tid;
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
A_ASSERT(p_aggr);
for(tid=0 ; tid<NUM_OF_TIDS ; tid++) {
aggr_delete_tid_state(p_aggr, tid);
}
}
static void
aggr_timeout(unsigned long arg)
{
u8 i,j;
struct aggr_info *p_aggr = (struct aggr_info *)arg;
struct rxtid *rxtid;
struct rxtid_stats *stats;
for(i = 0; i < NUM_OF_TIDS; i++) {
rxtid = AGGR_GET_RXTID(p_aggr, i);
stats = AGGR_GET_RXTID_STATS(p_aggr, i);
if(rxtid->aggr == false ||
rxtid->timerMon == false ||
rxtid->progress == true) {
continue;
}
stats->num_timeouts++;
A_PRINTF("TO: st %d end %d\n", rxtid->seq_next, ((rxtid->seq_next + rxtid->hold_q_sz-1) & IEEE80211_MAX_SEQ_NO));
aggr_deque_frms(p_aggr, i, 0, ALL_SEQNO);
}
p_aggr->timerScheduled = false;
for(i = 0; i < NUM_OF_TIDS; i++) {
rxtid = AGGR_GET_RXTID(p_aggr, i);
if(rxtid->aggr == true && rxtid->hold_q) {
for(j = 0 ; j < rxtid->hold_q_sz ; j++)
{
if(rxtid->hold_q[j].osbuf)
{
p_aggr->timerScheduled = true;
rxtid->timerMon = true;
rxtid->progress = false;
break;
}
}
if(j >= rxtid->hold_q_sz) {
rxtid->timerMon = false;
}
}
}
if(p_aggr->timerScheduled) {
A_TIMEOUT_MS(&p_aggr->timer, AGGR_RX_TIMEOUT, 0);
}
}
static void
aggr_dispatch_frames(struct aggr_info *p_aggr, A_NETBUF_QUEUE_T *q)
{
void *osbuf;
while((osbuf = A_NETBUF_DEQUEUE(q))) {
p_aggr->rx_fn(p_aggr->dev, osbuf);
}
}
void
aggr_dump_stats(void *cntxt, PACKET_LOG **log_buf)
{
struct aggr_info *p_aggr = (struct aggr_info *)cntxt;
struct rxtid *rxtid;
struct rxtid_stats *stats;
u8 i;
*log_buf = &p_aggr->pkt_log;
A_PRINTF("\n\n================================================\n");
A_PRINTF("tid: num_into_aggr, dups, oow, mpdu, amsdu, delivered, timeouts, holes, bar, seq_next\n");
for(i = 0; i < NUM_OF_TIDS; i++) {
stats = AGGR_GET_RXTID_STATS(p_aggr, i);
rxtid = AGGR_GET_RXTID(p_aggr, i);
A_PRINTF("%d: %d %d %d %d %d %d %d %d %d : %d\n", i, stats->num_into_aggr, stats->num_dups,
stats->num_oow, stats->num_mpdu,
stats->num_amsdu, stats->num_delivered, stats->num_timeouts,
stats->num_hole, stats->num_bar,
rxtid->seq_next);
}
A_PRINTF("================================================\n\n");
}
