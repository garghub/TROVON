void seq_printf_with_thousands_grouping(struct seq_file *seq, long v)
{
if (unlikely(v >= 1000000)) {
seq_printf(seq, "%ld,", v / 1000000);
v /= 1000000;
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
if (mdev->state.conn == C_VERIFY_S ||
mdev->state.conn == C_VERIFY_T)
bit_pos = bm_bits - mdev->ov_left;
else
bit_pos = mdev->bm_resync_fo;
seq_printf(seq,
"\t%3d%% sector pos: %llu/%llu\n",
(int)(bit_pos / (bm_bits/100+1)),
(unsigned long long)bit_pos * BM_SECT_PER_BIT,
(unsigned long long)bm_bits * BM_SECT_PER_BIT);
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
int i, hole = 0;
const char *sn;
struct drbd_conf *mdev;
static char write_ordering_chars[] = {
[WO_none] = 'n',
[WO_drain_io] = 'd',
[WO_bdev_flush] = 'f',
};
seq_printf(seq, "version: " REL_VERSION " (api:%d/proto:%d-%d)\n%s\n",
API_VERSION, PRO_VERSION_MIN, PRO_VERSION_MAX, drbd_buildtag());
for (i = 0; i < minor_count; i++) {
mdev = minor_to_mdev(i);
if (!mdev) {
hole = 1;
continue;
}
if (hole) {
hole = 0;
seq_printf(seq, "\n");
}
sn = drbd_conn_str(mdev->state.conn);
if (mdev->state.conn == C_STANDALONE &&
mdev->state.disk == D_DISKLESS &&
mdev->state.role == R_SECONDARY) {
seq_printf(seq, "%2d: cs:Unconfigured\n", i);
} else {
seq_printf(seq,
"%2d: cs:%s ro:%s/%s ds:%s/%s %c %c%c%c%c%c%c\n"
" ns:%u nr:%u dw:%u dr:%u al:%u bm:%u "
"lo:%d pe:%d ua:%d ap:%d ep:%d wo:%c",
i, sn,
drbd_role_str(mdev->state.role),
drbd_role_str(mdev->state.peer),
drbd_disk_str(mdev->state.disk),
drbd_disk_str(mdev->state.pdsk),
(mdev->net_conf == NULL ? ' ' :
(mdev->net_conf->wire_protocol - DRBD_PROT_A+'A')),
is_susp(mdev->state) ? 's' : 'r',
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
mdev->epochs,
write_ordering_chars[mdev->write_ordering]
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
