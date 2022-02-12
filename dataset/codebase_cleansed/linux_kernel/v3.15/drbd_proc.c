static void seq_printf_with_thousands_grouping(struct seq_file *seq, long v)
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
static void drbd_syncer_progress(struct drbd_device *device, struct seq_file *seq)
{
unsigned long db, dt, dbdt, rt, rs_left;
unsigned int res;
int i, x, y;
int stalled = 0;
drbd_get_syncer_progress(device, &rs_left, &res);
x = res/50;
y = 20-x;
seq_printf(seq, "\t[");
for (i = 1; i < x; i++)
seq_printf(seq, "=");
seq_printf(seq, ">");
for (i = 0; i < y; i++)
seq_printf(seq, ".");
seq_printf(seq, "] ");
if (device->state.conn == C_VERIFY_S || device->state.conn == C_VERIFY_T)
seq_printf(seq, "verified:");
else
seq_printf(seq, "sync'ed:");
seq_printf(seq, "%3u.%u%% ", res / 10, res % 10);
if (device->rs_total > (4UL << (30 - BM_BLOCK_SHIFT)))
seq_printf(seq, "(%lu/%lu)M",
(unsigned long) Bit2KB(rs_left >> 10),
(unsigned long) Bit2KB(device->rs_total >> 10));
else
seq_printf(seq, "(%lu/%lu)K\n\t",
(unsigned long) Bit2KB(rs_left),
(unsigned long) Bit2KB(device->rs_total));
i = (device->rs_last_mark + 2) % DRBD_SYNC_MARKS;
dt = (jiffies - device->rs_mark_time[i]) / HZ;
if (dt > (DRBD_SYNC_MARK_STEP * DRBD_SYNC_MARKS))
stalled = 1;
if (!dt)
dt++;
db = device->rs_mark_left[i] - rs_left;
rt = (dt * (rs_left / (db/100+1)))/100;
seq_printf(seq, "finish: %lu:%02lu:%02lu",
rt / 3600, (rt % 3600) / 60, rt % 60);
dbdt = Bit2KB(db/dt);
seq_printf(seq, " speed: ");
seq_printf_with_thousands_grouping(seq, dbdt);
seq_printf(seq, " (");
if (proc_details >= 1) {
i = (device->rs_last_mark + DRBD_SYNC_MARKS-1) % DRBD_SYNC_MARKS;
dt = (jiffies - device->rs_mark_time[i]) / HZ;
if (!dt)
dt++;
db = device->rs_mark_left[i] - rs_left;
dbdt = Bit2KB(db/dt);
seq_printf_with_thousands_grouping(seq, dbdt);
seq_printf(seq, " -- ");
}
dt = (jiffies - device->rs_start - device->rs_paused) / HZ;
if (dt == 0)
dt = 1;
db = device->rs_total - rs_left;
dbdt = Bit2KB(db/dt);
seq_printf_with_thousands_grouping(seq, dbdt);
seq_printf(seq, ")");
if (device->state.conn == C_SYNC_TARGET ||
device->state.conn == C_VERIFY_S) {
seq_printf(seq, " want: ");
seq_printf_with_thousands_grouping(seq, device->c_sync_rate);
}
seq_printf(seq, " K/sec%s\n", stalled ? " (stalled)" : "");
if (proc_details >= 1) {
unsigned long bm_bits = drbd_bm_bits(device);
unsigned long bit_pos;
unsigned long long stop_sector = 0;
if (device->state.conn == C_VERIFY_S ||
device->state.conn == C_VERIFY_T) {
bit_pos = bm_bits - device->ov_left;
if (verify_can_do_stop_sector(device))
stop_sector = device->ov_stop_sector;
} else
bit_pos = device->bm_resync_fo;
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
struct drbd_device *device;
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
idr_for_each_entry(&drbd_devices, device, i) {
if (prev_i != i - 1)
seq_printf(seq, "\n");
prev_i = i;
sn = drbd_conn_str(device->state.conn);
if (device->state.conn == C_STANDALONE &&
device->state.disk == D_DISKLESS &&
device->state.role == R_SECONDARY) {
seq_printf(seq, "%2d: cs:Unconfigured\n", i);
} else {
bdi_rw_congested(&device->rq_queue->backing_dev_info);
nc = rcu_dereference(first_peer_device(device)->connection->net_conf);
wp = nc ? nc->wire_protocol - DRBD_PROT_A + 'A' : ' ';
seq_printf(seq,
"%2d: cs:%s ro:%s/%s ds:%s/%s %c %c%c%c%c%c%c\n"
" ns:%u nr:%u dw:%u dr:%u al:%u bm:%u "
"lo:%d pe:%d ua:%d ap:%d ep:%d wo:%c",
i, sn,
drbd_role_str(device->state.role),
drbd_role_str(device->state.peer),
drbd_disk_str(device->state.disk),
drbd_disk_str(device->state.pdsk),
wp,
drbd_suspended(device) ? 's' : 'r',
device->state.aftr_isp ? 'a' : '-',
device->state.peer_isp ? 'p' : '-',
device->state.user_isp ? 'u' : '-',
device->congestion_reason ?: '-',
test_bit(AL_SUSPENDED, &device->flags) ? 's' : '-',
device->send_cnt/2,
device->recv_cnt/2,
device->writ_cnt/2,
device->read_cnt/2,
device->al_writ_cnt,
device->bm_writ_cnt,
atomic_read(&device->local_cnt),
atomic_read(&device->ap_pending_cnt) +
atomic_read(&device->rs_pending_cnt),
atomic_read(&device->unacked_cnt),
atomic_read(&device->ap_bio_cnt),
first_peer_device(device)->connection->epochs,
write_ordering_chars[first_peer_device(device)->connection->write_ordering]
);
seq_printf(seq, " oos:%llu\n",
Bit2KB((unsigned long long)
drbd_bm_total_weight(device)));
}
if (device->state.conn == C_SYNC_SOURCE ||
device->state.conn == C_SYNC_TARGET ||
device->state.conn == C_VERIFY_S ||
device->state.conn == C_VERIFY_T)
drbd_syncer_progress(device, seq);
if (proc_details >= 1 && get_ldev_if_state(device, D_FAILED)) {
lc_seq_printf_stats(seq, device->resync);
lc_seq_printf_stats(seq, device->act_log);
put_ldev(device);
}
if (proc_details >= 2) {
if (device->resync) {
lc_seq_dump_details(seq, device->resync, "rs_left",
resync_dump_detail);
}
}
}
rcu_read_unlock();
return 0;
}
static int drbd_proc_open(struct inode *inode, struct file *file)
{
int err;
if (try_module_get(THIS_MODULE)) {
err = single_open(file, drbd_seq_show, PDE_DATA(inode));
if (err)
module_put(THIS_MODULE);
return err;
}
return -ENODEV;
}
static int drbd_proc_release(struct inode *inode, struct file *file)
{
module_put(THIS_MODULE);
return single_release(inode, file);
}
