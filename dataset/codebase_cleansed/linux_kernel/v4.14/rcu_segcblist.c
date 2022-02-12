void rcu_cblist_init(struct rcu_cblist *rclp)
{
rclp->head = NULL;
rclp->tail = &rclp->head;
rclp->len = 0;
rclp->len_lazy = 0;
}
struct rcu_head *rcu_cblist_dequeue(struct rcu_cblist *rclp)
{
struct rcu_head *rhp;
rhp = rclp->head;
if (!rhp)
return NULL;
rclp->len--;
rclp->head = rhp->next;
if (!rclp->head)
rclp->tail = &rclp->head;
return rhp;
}
void rcu_segcblist_init(struct rcu_segcblist *rsclp)
{
int i;
BUILD_BUG_ON(RCU_NEXT_TAIL + 1 != ARRAY_SIZE(rsclp->gp_seq));
BUILD_BUG_ON(ARRAY_SIZE(rsclp->tails) != ARRAY_SIZE(rsclp->gp_seq));
rsclp->head = NULL;
for (i = 0; i < RCU_CBLIST_NSEGS; i++)
rsclp->tails[i] = &rsclp->head;
rsclp->len = 0;
rsclp->len_lazy = 0;
}
void rcu_segcblist_disable(struct rcu_segcblist *rsclp)
{
WARN_ON_ONCE(!rcu_segcblist_empty(rsclp));
WARN_ON_ONCE(rcu_segcblist_n_cbs(rsclp));
WARN_ON_ONCE(rcu_segcblist_n_lazy_cbs(rsclp));
rsclp->tails[RCU_NEXT_TAIL] = NULL;
}
bool rcu_segcblist_ready_cbs(struct rcu_segcblist *rsclp)
{
return rcu_segcblist_is_enabled(rsclp) &&
&rsclp->head != rsclp->tails[RCU_DONE_TAIL];
}
bool rcu_segcblist_pend_cbs(struct rcu_segcblist *rsclp)
{
return rcu_segcblist_is_enabled(rsclp) &&
!rcu_segcblist_restempty(rsclp, RCU_DONE_TAIL);
}
struct rcu_head *rcu_segcblist_first_cb(struct rcu_segcblist *rsclp)
{
if (rcu_segcblist_is_enabled(rsclp))
return rsclp->head;
return NULL;
}
struct rcu_head *rcu_segcblist_first_pend_cb(struct rcu_segcblist *rsclp)
{
if (rcu_segcblist_is_enabled(rsclp))
return *rsclp->tails[RCU_DONE_TAIL];
return NULL;
}
void rcu_segcblist_enqueue(struct rcu_segcblist *rsclp,
struct rcu_head *rhp, bool lazy)
{
WRITE_ONCE(rsclp->len, rsclp->len + 1);
if (lazy)
rsclp->len_lazy++;
smp_mb();
rhp->next = NULL;
*rsclp->tails[RCU_NEXT_TAIL] = rhp;
rsclp->tails[RCU_NEXT_TAIL] = &rhp->next;
}
bool rcu_segcblist_entrain(struct rcu_segcblist *rsclp,
struct rcu_head *rhp, bool lazy)
{
int i;
if (rcu_segcblist_n_cbs(rsclp) == 0)
return false;
WRITE_ONCE(rsclp->len, rsclp->len + 1);
if (lazy)
rsclp->len_lazy++;
smp_mb();
rhp->next = NULL;
for (i = RCU_NEXT_TAIL; i > RCU_DONE_TAIL; i--)
if (rsclp->tails[i] != rsclp->tails[i - 1])
break;
*rsclp->tails[i] = rhp;
for (; i <= RCU_NEXT_TAIL; i++)
rsclp->tails[i] = &rhp->next;
return true;
}
void rcu_segcblist_extract_count(struct rcu_segcblist *rsclp,
struct rcu_cblist *rclp)
{
rclp->len_lazy += rsclp->len_lazy;
rclp->len += rsclp->len;
rsclp->len_lazy = 0;
WRITE_ONCE(rsclp->len, 0);
}
void rcu_segcblist_extract_done_cbs(struct rcu_segcblist *rsclp,
struct rcu_cblist *rclp)
{
int i;
if (!rcu_segcblist_ready_cbs(rsclp))
return;
*rclp->tail = rsclp->head;
rsclp->head = *rsclp->tails[RCU_DONE_TAIL];
*rsclp->tails[RCU_DONE_TAIL] = NULL;
rclp->tail = rsclp->tails[RCU_DONE_TAIL];
for (i = RCU_CBLIST_NSEGS - 1; i >= RCU_DONE_TAIL; i--)
if (rsclp->tails[i] == rsclp->tails[RCU_DONE_TAIL])
rsclp->tails[i] = &rsclp->head;
}
void rcu_segcblist_extract_pend_cbs(struct rcu_segcblist *rsclp,
struct rcu_cblist *rclp)
{
int i;
if (!rcu_segcblist_pend_cbs(rsclp))
return;
*rclp->tail = *rsclp->tails[RCU_DONE_TAIL];
rclp->tail = rsclp->tails[RCU_NEXT_TAIL];
*rsclp->tails[RCU_DONE_TAIL] = NULL;
for (i = RCU_DONE_TAIL + 1; i < RCU_CBLIST_NSEGS; i++)
rsclp->tails[i] = rsclp->tails[RCU_DONE_TAIL];
}
void rcu_segcblist_insert_count(struct rcu_segcblist *rsclp,
struct rcu_cblist *rclp)
{
rsclp->len_lazy += rclp->len_lazy;
WRITE_ONCE(rsclp->len, rsclp->len + rclp->len);
rclp->len_lazy = 0;
rclp->len = 0;
}
void rcu_segcblist_insert_done_cbs(struct rcu_segcblist *rsclp,
struct rcu_cblist *rclp)
{
int i;
if (!rclp->head)
return;
*rclp->tail = rsclp->head;
rsclp->head = rclp->head;
for (i = RCU_DONE_TAIL; i < RCU_CBLIST_NSEGS; i++)
if (&rsclp->head == rsclp->tails[i])
rsclp->tails[i] = rclp->tail;
else
break;
rclp->head = NULL;
rclp->tail = &rclp->head;
}
void rcu_segcblist_insert_pend_cbs(struct rcu_segcblist *rsclp,
struct rcu_cblist *rclp)
{
if (!rclp->head)
return;
*rsclp->tails[RCU_NEXT_TAIL] = rclp->head;
rsclp->tails[RCU_NEXT_TAIL] = rclp->tail;
rclp->head = NULL;
rclp->tail = &rclp->head;
}
void rcu_segcblist_advance(struct rcu_segcblist *rsclp, unsigned long seq)
{
int i, j;
WARN_ON_ONCE(!rcu_segcblist_is_enabled(rsclp));
if (rcu_segcblist_restempty(rsclp, RCU_DONE_TAIL))
return;
for (i = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++) {
if (ULONG_CMP_LT(seq, rsclp->gp_seq[i]))
break;
rsclp->tails[RCU_DONE_TAIL] = rsclp->tails[i];
}
if (i == RCU_WAIT_TAIL)
return;
for (j = RCU_WAIT_TAIL; j < i; j++)
rsclp->tails[j] = rsclp->tails[RCU_DONE_TAIL];
for (j = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++, j++) {
if (rsclp->tails[j] == rsclp->tails[RCU_NEXT_TAIL])
break;
rsclp->tails[j] = rsclp->tails[i];
rsclp->gp_seq[j] = rsclp->gp_seq[i];
}
}
bool rcu_segcblist_accelerate(struct rcu_segcblist *rsclp, unsigned long seq)
{
int i;
WARN_ON_ONCE(!rcu_segcblist_is_enabled(rsclp));
if (rcu_segcblist_restempty(rsclp, RCU_DONE_TAIL))
return false;
for (i = RCU_NEXT_READY_TAIL; i > RCU_DONE_TAIL; i--)
if (rsclp->tails[i] != rsclp->tails[i - 1] &&
ULONG_CMP_LT(rsclp->gp_seq[i], seq))
break;
if (++i >= RCU_NEXT_TAIL)
return false;
for (; i < RCU_NEXT_TAIL; i++) {
rsclp->tails[i] = rsclp->tails[RCU_NEXT_TAIL];
rsclp->gp_seq[i] = seq;
}
return true;
}
bool rcu_segcblist_future_gp_needed(struct rcu_segcblist *rsclp,
unsigned long seq)
{
int i;
for (i = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++)
if (rsclp->tails[i - 1] != rsclp->tails[i] &&
ULONG_CMP_LT(seq, rsclp->gp_seq[i]))
return true;
return false;
}
void rcu_segcblist_merge(struct rcu_segcblist *dst_rsclp,
struct rcu_segcblist *src_rsclp)
{
struct rcu_cblist donecbs;
struct rcu_cblist pendcbs;
rcu_cblist_init(&donecbs);
rcu_cblist_init(&pendcbs);
rcu_segcblist_extract_count(src_rsclp, &donecbs);
rcu_segcblist_extract_done_cbs(src_rsclp, &donecbs);
rcu_segcblist_extract_pend_cbs(src_rsclp, &pendcbs);
rcu_segcblist_insert_count(dst_rsclp, &donecbs);
rcu_segcblist_insert_done_cbs(dst_rsclp, &donecbs);
rcu_segcblist_insert_pend_cbs(dst_rsclp, &pendcbs);
rcu_segcblist_init(src_rsclp);
}
