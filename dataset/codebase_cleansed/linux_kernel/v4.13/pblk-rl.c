static void pblk_rl_kick_u_timer(struct pblk_rl *rl)
{
mod_timer(&rl->u_timer, jiffies + msecs_to_jiffies(5000));
}
int pblk_rl_is_limit(struct pblk_rl *rl)
{
int rb_space;
rb_space = atomic_read(&rl->rb_space);
return (rb_space == 0);
}
int pblk_rl_user_may_insert(struct pblk_rl *rl, int nr_entries)
{
int rb_user_cnt = atomic_read(&rl->rb_user_cnt);
int rb_space = atomic_read(&rl->rb_space);
if (unlikely(rb_space >= 0) && (rb_space - nr_entries < 0))
return NVM_IO_ERR;
if (rb_user_cnt >= rl->rb_user_max)
return NVM_IO_REQUEUE;
return NVM_IO_OK;
}
void pblk_rl_inserted(struct pblk_rl *rl, int nr_entries)
{
int rb_space = atomic_read(&rl->rb_space);
if (unlikely(rb_space >= 0))
atomic_sub(nr_entries, &rl->rb_space);
}
int pblk_rl_gc_may_insert(struct pblk_rl *rl, int nr_entries)
{
int rb_gc_cnt = atomic_read(&rl->rb_gc_cnt);
int rb_user_active;
rb_user_active = READ_ONCE(rl->rb_user_active);
return (!(rb_gc_cnt >= rl->rb_gc_max && rb_user_active));
}
void pblk_rl_user_in(struct pblk_rl *rl, int nr_entries)
{
atomic_add(nr_entries, &rl->rb_user_cnt);
smp_store_release(&rl->rb_user_active, 1);
pblk_rl_kick_u_timer(rl);
}
void pblk_rl_gc_in(struct pblk_rl *rl, int nr_entries)
{
atomic_add(nr_entries, &rl->rb_gc_cnt);
}
void pblk_rl_out(struct pblk_rl *rl, int nr_user, int nr_gc)
{
atomic_sub(nr_user, &rl->rb_user_cnt);
atomic_sub(nr_gc, &rl->rb_gc_cnt);
}
unsigned long pblk_rl_nr_free_blks(struct pblk_rl *rl)
{
return atomic_read(&rl->free_blocks);
}
static int pblk_rl_update_rates(struct pblk_rl *rl, unsigned long max)
{
unsigned long free_blocks = pblk_rl_nr_free_blks(rl);
if (free_blocks >= rl->high) {
rl->rb_user_max = max;
rl->rb_gc_max = 0;
rl->rb_state = PBLK_RL_HIGH;
} else if (free_blocks < rl->high) {
int shift = rl->high_pw - rl->rb_windows_pw;
int user_windows = free_blocks >> shift;
int user_max = user_windows << PBLK_MAX_REQ_ADDRS_PW;
rl->rb_user_max = user_max;
rl->rb_gc_max = max - user_max;
if (free_blocks <= rl->rsv_blocks) {
rl->rb_user_max = 0;
rl->rb_gc_max = max;
}
rl->rb_state = PBLK_RL_LOW;
}
return rl->rb_state;
}
void pblk_rl_free_lines_inc(struct pblk_rl *rl, struct pblk_line *line)
{
struct pblk *pblk = container_of(rl, struct pblk, rl);
int blk_in_line = atomic_read(&line->blk_in_line);
int ret;
atomic_add(blk_in_line, &rl->free_blocks);
ret = pblk_rl_update_rates(rl, rl->rb_budget);
if (ret == (PBLK_RL_MID | PBLK_RL_LOW))
pblk_gc_should_start(pblk);
else
pblk_gc_should_stop(pblk);
}
void pblk_rl_free_lines_dec(struct pblk_rl *rl, struct pblk_line *line)
{
int blk_in_line = atomic_read(&line->blk_in_line);
atomic_sub(blk_in_line, &rl->free_blocks);
}
void pblk_gc_should_kick(struct pblk *pblk)
{
struct pblk_rl *rl = &pblk->rl;
int ret;
ret = pblk_rl_update_rates(rl, rl->rb_budget);
if (ret == (PBLK_RL_MID | PBLK_RL_LOW))
pblk_gc_should_start(pblk);
else
pblk_gc_should_stop(pblk);
}
int pblk_rl_high_thrs(struct pblk_rl *rl)
{
return rl->high;
}
int pblk_rl_low_thrs(struct pblk_rl *rl)
{
return rl->low;
}
int pblk_rl_sysfs_rate_show(struct pblk_rl *rl)
{
return rl->rb_user_max;
}
static void pblk_rl_u_timer(unsigned long data)
{
struct pblk_rl *rl = (struct pblk_rl *)data;
smp_store_release(&rl->rb_user_active, 0);
}
void pblk_rl_free(struct pblk_rl *rl)
{
del_timer(&rl->u_timer);
}
void pblk_rl_init(struct pblk_rl *rl, int budget)
{
struct pblk *pblk = container_of(rl, struct pblk, rl);
struct pblk_line_meta *lm = &pblk->lm;
int min_blocks = lm->blk_per_line * PBLK_GC_RSV_LINE;
unsigned int rb_windows;
rl->high = rl->total_blocks / PBLK_USER_HIGH_THRS;
rl->high_pw = get_count_order(rl->high);
rl->low = rl->total_blocks / PBLK_USER_LOW_THRS;
if (rl->low < min_blocks)
rl->low = min_blocks;
rl->rsv_blocks = min_blocks;
rb_windows = budget / PBLK_MAX_REQ_ADDRS;
rl->rb_windows_pw = get_count_order(rb_windows);
rl->rb_budget = budget;
rl->rb_user_max = budget;
rl->rb_gc_max = 0;
rl->rb_state = PBLK_RL_HIGH;
atomic_set(&rl->rb_user_cnt, 0);
atomic_set(&rl->rb_gc_cnt, 0);
atomic_set(&rl->rb_space, -1);
setup_timer(&rl->u_timer, pblk_rl_u_timer, (unsigned long)rl);
rl->rb_user_active = 0;
rl->rb_gc_active = 0;
}
