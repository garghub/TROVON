void seq_printf_with_thousands_grouping(struct seq_file *seq, long v)
{
if (unlikely(v >= 1000000)) {
seq_printf(seq, "%ld,", v / 1000000);
v %= 1000000;
seq_printf(seq, "%03ld,%03ld", v/1000, v % 1000);
} else if (likely(v >= 1000))
seq_printf(seq, "%ld,%03ld", v/1000, v % 1000);
else
seq_printf(seq, "%ld", v);
}
static void drbd_syncer_progress(struct drbd_conf *mdev, struct seq_file *seq)
{
unsigned long db, dt, dbdt, rt, rs_left;
unsigned int res;
int i, x, y;
int stalled = 0;
drbd_get_syncer_progress(mdev, &rs_left, &res);
x = res/50;
y = 20-x;
seq_printf(seq, "\t[");
for (i = 1; i < x; i++)
seq_printf(seq, "=");
seq_printf(seq, ">");
for (i = 0; i < y; i++)
seq_printf(seq, ".");
seq_printf(seq, "] ");
if (mdev->state.conn == C_VERIFY_S || mdev->state.conn == C_VERIFY_T)
seq_printf(seq, "verified:");
else
seq_printf(seq, "sync'ed:");
seq_printf(seq, "%3u.%u%% ", res / 10, res % 10);
if (mdev->rs_total > (4UL << (30 - BM_BLOCK_SHIFT)))
seq_printf(seq, "(%lu/%lu)M",
(unsigned long) Bit2KB(rs_left >> 10),
(unsigned long) Bit2KB(mdev->rs_total >> 10));
else
seq_printf(seq, "(%lu/%lu)K\n\t",
(unsigned long) Bit2KB(rs_left),
(unsigned long) Bit2KB(mdev->rs_total));
i = (mdev->rs_last_mark + 2) % DRBD_SYNC_MARKS;
dt = (jiffies - mdev->rs_mark_time[i]) / HZ;
if (dt > (DRBD_SYNC_MARK_STEP * DRBD_SYNC_MARKS))
stalled = 1;
if (!dt)
dt++;
db = mdev->rs_mark_left[i] - rs_left;
rt = (dt * (rs_left / (db/100+1)))/100;
seq_printf(seq, "finish: %lu:%02lu:%02lu",
rt / 3600, (rt % 3600) / 60, rt % 60);
dbdt = Bit2KB(db/dt);
seq_printf(seq, " speed: ");
seq_printf_with_thousands_grouping(seq, dbdt);
seq_printf(seq, " (");
if (proc_details >= 1) {
i = (mdev->rs_last_mark + DRBD_SYNC_MARKS-1) % DRBD_SYNC_MARKS;
dt = (jiffies - mdev->rs_mark_time[i]) / HZ;
if (!dt)
dt++;
db = mdev->rs_mark_left[i] - rs_left;
dbdt = Bit2KB(db/dt);
seq_printf_with_thousands_grouping(seq, dbdt);
seq_printf(seq, " -- ");
}
dt = (jiffies - mdev->rs_start - mdev->rs_paused) / HZ;
if (dt == 0)
dt = 1;
db = mdev->rs_total - rs_left;
dbdt = Bit2KB(db/dt);
seq_printf_with_thousands_grouping(seq, dbdt);
seq_printf(seq, ")");
if (mdev->state.conn == C_SYNC_TARGET ||
mdev->state.conn == C_VERIFY_S) {
seq_printf(seq, " want: ");
seq_printf_with_thousands_grouping(seq, mdev->c_sync_rate);
}
seq_printf(seq, " K/sec%s\n", stalled ? " (stalled)" : "");
if (proc_details >= 1) {
unsigned long bm_bits = drbd_bm_bits(mdev);
unsigned long bit_pos;
unsigned long long stop_sector = 0;
if (mdev->state.conn == C_VERIFY_S ||
mdev->state.conn == C_VERIFY_T) {
bit_pos = bm_bits - mdev->ov_left;
if (verify_can_do_stop_sector(mdev))
stop_sector = mdev->ov_stop_sector;
} else
bit_pos = mdev->bm_resync_fo;
seq_printf(seq,
"\t%3d%% sector pos: %llu/%llu",
(int)(bit_pos / (bm_bits/100+1)),
(unsigned long long)bit_pos * BM_SECT_PER_BIT,
(unsigned long long)bm_bits * BM_SECT_PER_BIT);
if (stop_sector != 0 && stop_sector != ULLONG_MAX)
seq_printf(seq, " stop sector: %llu", stop_sector);
seq_printf(seq, "\n");
}
}
static void resync_dump_detail(struct seq_file *seq, struct lc_element *e)
{
struct bm_extent *bme = lc_entry(e, struct bm_extent, lce);
seq_printf(seq, "%5d %s %s\n", bme->rs_left,
bme->flags & BME_NO_WRITES ? "NO_WRITES" : "---------",
bme->flags & BME_LOCKED ? "LOCKED" : "------"
);
}
static int drbd_seq_show(struct seq_file *seq, void *v)
{
int i, prev_i = -1;
const char *sn;
struct drbd_conf *mdev;
struct net_conf *nc;
char wp;
static char write_ordering_chars[] = {
[WO_none] = 'n',
[WO_drain_io] = 'd',
[WO_bdev_flush] = 'f',
};
seq_printf(seq, "version: " REL_VERSION " (api:%d/proto:%d-%d)\n%s\n",
API_VERSION, PRO_VERSION_MIN, PRO_VERSION_MAX, drbd_buildtag());
rcu_read_lock();
idr_for_each_entry(&minors, mdev, i) {
if (prev_i != i - 1)
seq_printf(seq, "\n");
prev_i = i;
sn = drbd_conn_str(mdev->state.conn);
if (mdev->state.conn == C_STANDALONE &&
mdev->state.disk == D_DISKLESS &&
mdev->state.role == R_SECONDARY) {
seq_printf(seq, "%2d: cs:Unconfigured\n", i);
} else {
bdi_rw_congested(&mdev->rq_queue->backing_dev_info);
nc = rcu_dereference(mdev->tconn->net_conf);
wp = nc ? nc->wire_protocol - DRBD_PROT_A + 'A' : ' ';
seq_printf(seq,
"%2d: cs:%s ro:%s/%s ds:%s/%s %c %c%c%c%c%c%c\n"
" ns:%u nr:%u dw:%u dr:%u al:%u bm:%u "
"lo:%d pe:%d ua:%d ap:%d ep:%d wo:%c",
i, sn,
drbd_role_str(mdev->state.role),
drbd_role_str(mdev->state.peer),
drbd_disk_str(mdev->state.disk),
drbd_disk_str(mdev->state.pdsk),
wp,
drbd_suspended(mdev) ? 's' : 'r',
mdev->state.aftr_isp ? 'a' : '-',
mdev->state.peer_isp ? 'p' : '-',
mdev->state.user_isp ? 'u' : '-',
mdev->congestion_reason ?: '-',
test_bit(AL_SUSPENDED, &mdev->flags) ? 's' : '-',
mdev->send_cnt/2,
mdev->recv_cnt/2,
mdev->writ_cnt/2,
mdev->read_cnt/2,
mdev->al_writ_cnt,
mdev->bm_writ_cnt,
atomic_read(&mdev->local_cnt),
atomic_read(&mdev->ap_pending_cnt) +
atomic_read(&mdev->rs_pending_cnt),
atomic_read(&mdev->unacked_cnt),
atomic_read(&mdev->ap_bio_cnt),
mdev->tconn->epochs,
write_ordering_chars[mdev->tconn->write_ordering]
);
seq_printf(seq, " oos:%llu\n",
Bit2KB((unsigned long long)
drbd_bm_total_weight(mdev)));
}
if (mdev->state.conn == C_SYNC_SOURCE ||
mdev->state.conn == C_SYNC_TARGET ||
mdev->state.conn == C_VERIFY_S ||
mdev->state.conn == C_VERIFY_T)
drbd_syncer_progress(mdev, seq);
if (proc_details >= 1 && get_ldev_if_state(mdev, D_FAILED)) {
lc_seq_printf_stats(seq, mdev->resync);
lc_seq_printf_stats(seq, mdev->act_log);
put_ldev(mdev);
}
if (proc_details >= 2) {
if (mdev->resync) {
lc_seq_dump_details(seq, mdev->resync, "rs_left",
resync_dump_detail);
}
}
}
rcu_read_unlock();
return 0;
}
static int drbd_proc_open(struct inode *inode, struct file *file)
{
if (try_module_get(THIS_MODULE))
return single_open(file, drbd_seq_show, PDE(inode)->data);
return -ENODEV;
}
static int drbd_proc_release(struct inode *inode, struct file *file)
{
module_put(THIS_MODULE);
return single_release(inode, file);
}
