static int shrink_tnc(struct ubifs_info *c, int nr, int age, int *contention)
{
int total_freed = 0;
struct ubifs_znode *znode, *zprev;
int time = get_seconds();
ubifs_assert(mutex_is_locked(&c->umount_mutex));
ubifs_assert(mutex_is_locked(&c->tnc_mutex));
if (!c->zroot.znode || atomic_long_read(&c->clean_zn_cnt) == 0)
return 0;
zprev = NULL;
znode = ubifs_tnc_levelorder_next(c->zroot.znode, NULL);
while (znode && total_freed < nr &&
atomic_long_read(&c->clean_zn_cnt) > 0) {
int freed;
if (znode->cnext) {
*contention = 1;
} else if (!ubifs_zn_dirty(znode) &&
abs(time - znode->time) >= age) {
if (znode->parent)
znode->parent->zbranch[znode->iip].znode = NULL;
else
c->zroot.znode = NULL;
freed = ubifs_destroy_tnc_subtree(znode);
atomic_long_sub(freed, &ubifs_clean_zn_cnt);
atomic_long_sub(freed, &c->clean_zn_cnt);
ubifs_assert(atomic_long_read(&c->clean_zn_cnt) >= 0);
total_freed += freed;
znode = zprev;
}
if (unlikely(!c->zroot.znode))
break;
zprev = znode;
znode = ubifs_tnc_levelorder_next(c->zroot.znode, znode);
cond_resched();
}
return total_freed;
}
static int shrink_tnc_trees(int nr, int age, int *contention)
{
struct ubifs_info *c;
struct list_head *p;
unsigned int run_no;
int freed = 0;
spin_lock(&ubifs_infos_lock);
do {
run_no = ++shrinker_run_no;
} while (run_no == 0);
p = ubifs_infos.next;
while (p != &ubifs_infos) {
c = list_entry(p, struct ubifs_info, infos_list);
if (c->shrinker_run_no == run_no)
break;
if (!mutex_trylock(&c->umount_mutex)) {
*contention = 1;
p = p->next;
continue;
}
if (!mutex_trylock(&c->tnc_mutex)) {
mutex_unlock(&c->umount_mutex);
*contention = 1;
p = p->next;
continue;
}
spin_unlock(&ubifs_infos_lock);
c->shrinker_run_no = run_no;
freed += shrink_tnc(c, nr, age, contention);
mutex_unlock(&c->tnc_mutex);
spin_lock(&ubifs_infos_lock);
p = p->next;
list_move_tail(&c->infos_list, &ubifs_infos);
mutex_unlock(&c->umount_mutex);
if (freed >= nr)
break;
}
spin_unlock(&ubifs_infos_lock);
return freed;
}
static int kick_a_thread(void)
{
int i;
struct ubifs_info *c;
spin_lock(&ubifs_infos_lock);
for (i = 0; i < 2; i++) {
list_for_each_entry(c, &ubifs_infos, infos_list) {
long dirty_zn_cnt;
if (!mutex_trylock(&c->umount_mutex)) {
spin_unlock(&ubifs_infos_lock);
return -1;
}
dirty_zn_cnt = atomic_long_read(&c->dirty_zn_cnt);
if (!dirty_zn_cnt || c->cmt_state == COMMIT_BROKEN ||
c->ro_mount || c->ro_error) {
mutex_unlock(&c->umount_mutex);
continue;
}
if (c->cmt_state != COMMIT_RESTING) {
spin_unlock(&ubifs_infos_lock);
mutex_unlock(&c->umount_mutex);
return -1;
}
if (i == 1) {
list_move_tail(&c->infos_list, &ubifs_infos);
spin_unlock(&ubifs_infos_lock);
ubifs_request_bg_commit(c);
mutex_unlock(&c->umount_mutex);
return -1;
}
mutex_unlock(&c->umount_mutex);
}
}
spin_unlock(&ubifs_infos_lock);
return 0;
}
int ubifs_shrinker(struct shrinker *shrink, struct shrink_control *sc)
{
int nr = sc->nr_to_scan;
int freed, contention = 0;
long clean_zn_cnt = atomic_long_read(&ubifs_clean_zn_cnt);
if (nr == 0)
return clean_zn_cnt >= 0 ? clean_zn_cnt : 1;
if (!clean_zn_cnt) {
dbg_tnc("no clean znodes, kick a thread");
return kick_a_thread();
}
freed = shrink_tnc_trees(nr, OLD_ZNODE_AGE, &contention);
if (freed >= nr)
goto out;
dbg_tnc("not enough old znodes, try to free young ones");
freed += shrink_tnc_trees(nr - freed, YOUNG_ZNODE_AGE, &contention);
if (freed >= nr)
goto out;
dbg_tnc("not enough young znodes, free all");
freed += shrink_tnc_trees(nr - freed, 0, &contention);
if (!freed && contention) {
dbg_tnc("freed nothing, but contention");
return -1;
}
out:
dbg_tnc("%d znodes were freed, requested %d", freed, nr);
return freed;
}
