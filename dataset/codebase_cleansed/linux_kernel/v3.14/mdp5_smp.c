int mdp5_smp_request(struct mdp5_kms *mdp5_kms,
enum mdp5_client_id cid, int nblks)
{
struct mdp5_client_smp_state *ps = &mdp5_kms->smp_client_state[cid];
int i, ret, avail, cur_nblks, cnt = mdp5_kms->smp_blk_cnt;
unsigned long flags;
spin_lock_irqsave(&smp_lock, flags);
avail = cnt - bitmap_weight(mdp5_kms->smp_state, cnt);
if (nblks > avail) {
ret = -ENOSPC;
goto fail;
}
cur_nblks = bitmap_weight(ps->pending, cnt);
if (nblks > cur_nblks) {
for (i = cur_nblks; i < nblks; i++) {
int blk = find_first_zero_bit(mdp5_kms->smp_state, cnt);
set_bit(blk, ps->pending);
set_bit(blk, mdp5_kms->smp_state);
}
} else {
for (i = cur_nblks; i > nblks; i--) {
int blk = find_first_bit(ps->pending, cnt);
clear_bit(blk, ps->pending);
}
}
fail:
spin_unlock_irqrestore(&smp_lock, flags);
return 0;
}
static void update_smp_state(struct mdp5_kms *mdp5_kms,
enum mdp5_client_id cid, mdp5_smp_state_t *assigned)
{
int cnt = mdp5_kms->smp_blk_cnt;
uint32_t blk, val;
for_each_set_bit(blk, *assigned, cnt) {
int idx = blk / 3;
int fld = blk % 3;
val = mdp5_read(mdp5_kms, REG_MDP5_SMP_ALLOC_W_REG(idx));
switch (fld) {
case 0:
val &= ~MDP5_SMP_ALLOC_W_REG_CLIENT0__MASK;
val |= MDP5_SMP_ALLOC_W_REG_CLIENT0(cid);
break;
case 1:
val &= ~MDP5_SMP_ALLOC_W_REG_CLIENT1__MASK;
val |= MDP5_SMP_ALLOC_W_REG_CLIENT1(cid);
break;
case 2:
val &= ~MDP5_SMP_ALLOC_W_REG_CLIENT2__MASK;
val |= MDP5_SMP_ALLOC_W_REG_CLIENT2(cid);
break;
}
mdp5_write(mdp5_kms, REG_MDP5_SMP_ALLOC_W_REG(idx), val);
mdp5_write(mdp5_kms, REG_MDP5_SMP_ALLOC_R_REG(idx), val);
}
}
void mdp5_smp_configure(struct mdp5_kms *mdp5_kms, enum mdp5_client_id cid)
{
struct mdp5_client_smp_state *ps = &mdp5_kms->smp_client_state[cid];
int cnt = mdp5_kms->smp_blk_cnt;
mdp5_smp_state_t assigned;
bitmap_or(assigned, ps->inuse, ps->pending, cnt);
update_smp_state(mdp5_kms, cid, &assigned);
}
void mdp5_smp_commit(struct mdp5_kms *mdp5_kms, enum mdp5_client_id cid)
{
struct mdp5_client_smp_state *ps = &mdp5_kms->smp_client_state[cid];
int cnt = mdp5_kms->smp_blk_cnt;
mdp5_smp_state_t released;
if (bitmap_andnot(released, ps->inuse, ps->pending, cnt)) {
unsigned long flags;
spin_lock_irqsave(&smp_lock, flags);
bitmap_andnot(mdp5_kms->smp_state, mdp5_kms->smp_state,
released, cnt);
spin_unlock_irqrestore(&smp_lock, flags);
update_smp_state(mdp5_kms, CID_UNUSED, &released);
}
bitmap_copy(ps->inuse, ps->pending, cnt);
}
