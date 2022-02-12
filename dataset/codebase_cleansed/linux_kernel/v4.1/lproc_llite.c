static int ll_blksize_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
struct obd_statfs osfs;
int rc;
LASSERT(sb != NULL);
rc = ll_statfs_internal(sb, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc)
seq_printf(m, "%u\n", osfs.os_bsize);
return rc;
}
static int ll_kbytestotal_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
struct obd_statfs osfs;
int rc;
LASSERT(sb != NULL);
rc = ll_statfs_internal(sb, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_blocks;
while (blk_size >>= 1)
result <<= 1;
seq_printf(m, "%llu\n", result);
}
return rc;
}
static int ll_kbytesfree_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
struct obd_statfs osfs;
int rc;
LASSERT(sb != NULL);
rc = ll_statfs_internal(sb, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_bfree;
while (blk_size >>= 1)
result <<= 1;
seq_printf(m, "%llu\n", result);
}
return rc;
}
static int ll_kbytesavail_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
struct obd_statfs osfs;
int rc;
LASSERT(sb != NULL);
rc = ll_statfs_internal(sb, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_bavail;
while (blk_size >>= 1)
result <<= 1;
seq_printf(m, "%llu\n", result);
}
return rc;
}
static int ll_filestotal_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
struct obd_statfs osfs;
int rc;
LASSERT(sb != NULL);
rc = ll_statfs_internal(sb, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc)
seq_printf(m, "%llu\n", osfs.os_files);
return rc;
}
static int ll_filesfree_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
struct obd_statfs osfs;
int rc;
LASSERT(sb != NULL);
rc = ll_statfs_internal(sb, &osfs,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
OBD_STATFS_NODELAY);
if (!rc)
seq_printf(m, "%llu\n", osfs.os_ffree);
return rc;
}
static int ll_client_type_seq_show(struct seq_file *m, void *v)
{
struct ll_sb_info *sbi = ll_s2sbi((struct super_block *)m->private);
LASSERT(sbi != NULL);
if (sbi->ll_flags & LL_SBI_RMT_CLIENT)
seq_puts(m, "remote client\n");
else
seq_puts(m, "local client\n");
return 0;
}
static int ll_fstype_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
LASSERT(sb != NULL);
seq_printf(m, "%s\n", sb->s_type->name);
return 0;
}
static int ll_sb_uuid_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = (struct super_block *)m->private;
LASSERT(sb != NULL);
seq_printf(m, "%s\n", ll_s2sbi(sb)->ll_sb_uuid.uuid);
return 0;
}
static int ll_site_stats_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
return cl_site_stats_print(lu2cl_site(ll_s2sbi(sb)->ll_site), m);
}
static int ll_max_readahead_mb_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
long pages_number;
int mult;
spin_lock(&sbi->ll_lock);
pages_number = sbi->ll_ra_info.ra_max_pages;
spin_unlock(&sbi->ll_lock);
mult = 1 << (20 - PAGE_CACHE_SHIFT);
return lprocfs_seq_read_frac_helper(m, pages_number, mult);
}
static ssize_t ll_max_readahead_mb_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int mult, rc, pages_number;
mult = 1 << (20 - PAGE_CACHE_SHIFT);
rc = lprocfs_write_frac_helper(buffer, count, &pages_number, mult);
if (rc)
return rc;
if (pages_number < 0 || pages_number > totalram_pages / 2) {
CERROR("can't set file readahead more than %lu MB\n",
totalram_pages >> (20 - PAGE_CACHE_SHIFT + 1));
return -ERANGE;
}
spin_lock(&sbi->ll_lock);
sbi->ll_ra_info.ra_max_pages = pages_number;
spin_unlock(&sbi->ll_lock);
return count;
}
static int ll_max_readahead_per_file_mb_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
long pages_number;
int mult;
spin_lock(&sbi->ll_lock);
pages_number = sbi->ll_ra_info.ra_max_pages_per_file;
spin_unlock(&sbi->ll_lock);
mult = 1 << (20 - PAGE_CACHE_SHIFT);
return lprocfs_seq_read_frac_helper(m, pages_number, mult);
}
static ssize_t ll_max_readahead_per_file_mb_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int mult, rc, pages_number;
mult = 1 << (20 - PAGE_CACHE_SHIFT);
rc = lprocfs_write_frac_helper(buffer, count, &pages_number, mult);
if (rc)
return rc;
if (pages_number < 0 ||
pages_number > sbi->ll_ra_info.ra_max_pages) {
CERROR("can't set file readahead more than max_read_ahead_mb %lu MB\n",
sbi->ll_ra_info.ra_max_pages);
return -ERANGE;
}
spin_lock(&sbi->ll_lock);
sbi->ll_ra_info.ra_max_pages_per_file = pages_number;
spin_unlock(&sbi->ll_lock);
return count;
}
static int ll_max_read_ahead_whole_mb_seq_show(struct seq_file *m, void *unused)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
long pages_number;
int mult;
spin_lock(&sbi->ll_lock);
pages_number = sbi->ll_ra_info.ra_max_read_ahead_whole_pages;
spin_unlock(&sbi->ll_lock);
mult = 1 << (20 - PAGE_CACHE_SHIFT);
return lprocfs_seq_read_frac_helper(m, pages_number, mult);
}
static ssize_t ll_max_read_ahead_whole_mb_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int mult, rc, pages_number;
mult = 1 << (20 - PAGE_CACHE_SHIFT);
rc = lprocfs_write_frac_helper(buffer, count, &pages_number, mult);
if (rc)
return rc;
if (pages_number < 0 ||
pages_number > sbi->ll_ra_info.ra_max_pages_per_file) {
CERROR("can't set max_read_ahead_whole_mb more than max_read_ahead_per_file_mb: %lu\n",
sbi->ll_ra_info.ra_max_pages_per_file >> (20 - PAGE_CACHE_SHIFT));
return -ERANGE;
}
spin_lock(&sbi->ll_lock);
sbi->ll_ra_info.ra_max_read_ahead_whole_pages = pages_number;
spin_unlock(&sbi->ll_lock);
return count;
}
static int ll_max_cached_mb_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
struct cl_client_cache *cache = &sbi->ll_cache;
int shift = 20 - PAGE_CACHE_SHIFT;
int max_cached_mb;
int unused_mb;
max_cached_mb = cache->ccc_lru_max >> shift;
unused_mb = atomic_read(&cache->ccc_lru_left) >> shift;
seq_printf(m,
"users: %d\n"
"max_cached_mb: %d\n"
"used_mb: %d\n"
"unused_mb: %d\n"
"reclaim_count: %u\n",
atomic_read(&cache->ccc_users),
max_cached_mb,
max_cached_mb - unused_mb,
unused_mb,
cache->ccc_lru_shrinkers);
return 0;
}
static ssize_t ll_max_cached_mb_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
struct cl_client_cache *cache = &sbi->ll_cache;
int mult, rc, pages_number;
int diff = 0;
int nrpages = 0;
char kernbuf[128];
if (count >= sizeof(kernbuf))
return -EINVAL;
if (copy_from_user(kernbuf, buffer, count))
return -EFAULT;
kernbuf[count] = 0;
mult = 1 << (20 - PAGE_CACHE_SHIFT);
buffer += lprocfs_find_named_value(kernbuf, "max_cached_mb:", &count) -
kernbuf;
rc = lprocfs_write_frac_helper(buffer, count, &pages_number, mult);
if (rc)
return rc;
if (pages_number < 0 || pages_number > totalram_pages) {
CERROR("%s: can't set max cache more than %lu MB\n",
ll_get_fsname(sb, NULL, 0),
totalram_pages >> (20 - PAGE_CACHE_SHIFT));
return -ERANGE;
}
spin_lock(&sbi->ll_lock);
diff = pages_number - cache->ccc_lru_max;
spin_unlock(&sbi->ll_lock);
if (diff >= 0) {
atomic_add(diff, &cache->ccc_lru_left);
rc = 0;
goto out;
}
diff = -diff;
while (diff > 0) {
int tmp;
do {
int ov, nv;
ov = atomic_read(&cache->ccc_lru_left);
if (ov == 0)
break;
nv = ov > diff ? ov - diff : 0;
rc = atomic_cmpxchg(&cache->ccc_lru_left, ov, nv);
if (likely(ov == rc)) {
diff -= ov - nv;
nrpages += ov - nv;
break;
}
} while (1);
if (diff <= 0)
break;
if (sbi->ll_dt_exp == NULL) {
rc = -ENODEV;
break;
}
tmp = diff << 1;
rc = obd_set_info_async(NULL, sbi->ll_dt_exp,
sizeof(KEY_CACHE_LRU_SHRINK),
KEY_CACHE_LRU_SHRINK,
sizeof(tmp), &tmp, NULL);
if (rc < 0)
break;
}
out:
if (rc >= 0) {
spin_lock(&sbi->ll_lock);
cache->ccc_lru_max = pages_number;
spin_unlock(&sbi->ll_lock);
rc = count;
} else {
atomic_add(nrpages, &cache->ccc_lru_left);
}
return rc;
}
static int ll_checksum_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
seq_printf(m, "%u\n", (sbi->ll_flags & LL_SBI_CHECKSUM) ? 1 : 0);
return 0;
}
static ssize_t ll_checksum_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int val, rc;
if (!sbi->ll_dt_exp)
return -EAGAIN;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
if (val)
sbi->ll_flags |= LL_SBI_CHECKSUM;
else
sbi->ll_flags &= ~LL_SBI_CHECKSUM;
rc = obd_set_info_async(NULL, sbi->ll_dt_exp, sizeof(KEY_CHECKSUM),
KEY_CHECKSUM, sizeof(val), &val, NULL);
if (rc)
CWARN("Failed to set OSC checksum flags: %d\n", rc);
return count;
}
static int ll_max_rw_chunk_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
seq_printf(m, "%lu\n", ll_s2sbi(sb)->ll_max_rw_chunk);
return 0;
}
static ssize_t ll_max_rw_chunk_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
int rc, val;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
ll_s2sbi(sb)->ll_max_rw_chunk = val;
return count;
}
static int ll_rd_track_id(struct seq_file *m, enum stats_track_type type)
{
struct super_block *sb = m->private;
if (ll_s2sbi(sb)->ll_stats_track_type == type)
seq_printf(m, "%d\n", ll_s2sbi(sb)->ll_stats_track_id);
else if (ll_s2sbi(sb)->ll_stats_track_type == STATS_TRACK_ALL)
seq_puts(m, "0 (all)\n");
else
seq_puts(m, "untracked\n");
return 0;
}
static int ll_wr_track_id(const char __user *buffer, unsigned long count,
void *data, enum stats_track_type type)
{
struct super_block *sb = data;
int rc, pid;
rc = lprocfs_write_helper(buffer, count, &pid);
if (rc)
return rc;
ll_s2sbi(sb)->ll_stats_track_id = pid;
if (pid == 0)
ll_s2sbi(sb)->ll_stats_track_type = STATS_TRACK_ALL;
else
ll_s2sbi(sb)->ll_stats_track_type = type;
lprocfs_clear_stats(ll_s2sbi(sb)->ll_stats);
return count;
}
static int ll_track_pid_seq_show(struct seq_file *m, void *v)
{
return ll_rd_track_id(m, STATS_TRACK_PID);
}
static ssize_t ll_track_pid_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct seq_file *seq = file->private_data;
return ll_wr_track_id(buffer, count, seq->private, STATS_TRACK_PID);
}
static int ll_track_ppid_seq_show(struct seq_file *m, void *v)
{
return ll_rd_track_id(m, STATS_TRACK_PPID);
}
static ssize_t ll_track_ppid_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct seq_file *seq = file->private_data;
return ll_wr_track_id(buffer, count, seq->private, STATS_TRACK_PPID);
}
static int ll_track_gid_seq_show(struct seq_file *m, void *v)
{
return ll_rd_track_id(m, STATS_TRACK_GID);
}
static ssize_t ll_track_gid_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct seq_file *seq = file->private_data;
return ll_wr_track_id(buffer, count, seq->private, STATS_TRACK_GID);
}
static int ll_statahead_max_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
seq_printf(m, "%u\n", sbi->ll_sa_max);
return 0;
}
static ssize_t ll_statahead_max_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int val, rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
if (val >= 0 && val <= LL_SA_RPC_MAX)
sbi->ll_sa_max = val;
else
CERROR("Bad statahead_max value %d. Valid values are in the range [0, %d]\n",
val, LL_SA_RPC_MAX);
return count;
}
static int ll_statahead_agl_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
seq_printf(m, "%u\n", sbi->ll_flags & LL_SBI_AGL_ENABLED ? 1 : 0);
return 0;
}
static ssize_t ll_statahead_agl_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int val, rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
if (val)
sbi->ll_flags |= LL_SBI_AGL_ENABLED;
else
sbi->ll_flags &= ~LL_SBI_AGL_ENABLED;
return count;
}
static int ll_statahead_stats_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
seq_printf(m,
"statahead total: %u\n"
"statahead wrong: %u\n"
"agl total: %u\n",
atomic_read(&sbi->ll_sa_total),
atomic_read(&sbi->ll_sa_wrong),
atomic_read(&sbi->ll_agl_total));
return 0;
}
static int ll_lazystatfs_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
seq_printf(m, "%u\n", sbi->ll_flags & LL_SBI_LAZYSTATFS ? 1 : 0);
return 0;
}
static ssize_t ll_lazystatfs_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct super_block *sb = ((struct seq_file *)file->private_data)->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int val, rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
if (val)
sbi->ll_flags |= LL_SBI_LAZYSTATFS;
else
sbi->ll_flags &= ~LL_SBI_LAZYSTATFS;
return count;
}
static int ll_max_easize_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
unsigned int ealen;
int rc;
rc = ll_get_max_mdsize(sbi, &ealen);
if (rc)
return rc;
seq_printf(m, "%u\n", ealen);
return 0;
}
static int ll_default_easize_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
unsigned int ealen;
int rc;
rc = ll_get_default_mdsize(sbi, &ealen);
if (rc)
return rc;
seq_printf(m, "%u\n", ealen);
return 0;
}
static int ll_max_cookiesize_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
unsigned int cookielen;
int rc;
rc = ll_get_max_cookiesize(sbi, &cookielen);
if (rc)
return rc;
seq_printf(m, "%u\n", cookielen);
return 0;
}
static int ll_default_cookiesize_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
unsigned int cookielen;
int rc;
rc = ll_get_default_cookiesize(sbi, &cookielen);
if (rc)
return rc;
seq_printf(m, "%u\n", cookielen);
return 0;
}
static int ll_sbi_flags_seq_show(struct seq_file *m, void *v)
{
const char *str[] = LL_SBI_FLAGS;
struct super_block *sb = m->private;
int flags = ll_s2sbi(sb)->ll_flags;
int i = 0;
while (flags != 0) {
if (ARRAY_SIZE(str) <= i) {
CERROR("%s: Revise array LL_SBI_FLAGS to match sbi flags please.\n",
ll_get_fsname(sb, NULL, 0));
return -EINVAL;
}
if (flags & 0x1)
seq_printf(m, "%s ", str[i]);
flags >>= 1;
++i;
}
seq_printf(m, "\b\n");
return 0;
}
static int ll_xattr_cache_seq_show(struct seq_file *m, void *v)
{
struct super_block *sb = m->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
seq_printf(m, "%u\n", sbi->ll_xattr_cache_enabled);
return 0;
}
static ssize_t ll_xattr_cache_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct seq_file *seq = file->private_data;
struct super_block *sb = seq->private;
struct ll_sb_info *sbi = ll_s2sbi(sb);
int val, rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
if (val != 0 && val != 1)
return -ERANGE;
if (val == 1 && !(sbi->ll_flags & LL_SBI_XATTR_CACHE))
return -ENOTSUPP;
sbi->ll_xattr_cache_enabled = val;
return count;
}
void ll_stats_ops_tally(struct ll_sb_info *sbi, int op, int count)
{
if (!sbi->ll_stats)
return;
if (sbi->ll_stats_track_type == STATS_TRACK_ALL)
lprocfs_counter_add(sbi->ll_stats, op, count);
else if (sbi->ll_stats_track_type == STATS_TRACK_PID &&
sbi->ll_stats_track_id == current->pid)
lprocfs_counter_add(sbi->ll_stats, op, count);
else if (sbi->ll_stats_track_type == STATS_TRACK_PPID &&
sbi->ll_stats_track_id == current->real_parent->pid)
lprocfs_counter_add(sbi->ll_stats, op, count);
else if (sbi->ll_stats_track_type == STATS_TRACK_GID &&
sbi->ll_stats_track_id ==
from_kgid(&init_user_ns, current_gid()))
lprocfs_counter_add(sbi->ll_stats, op, count);
}
int lprocfs_register_mountpoint(struct proc_dir_entry *parent,
struct super_block *sb, char *osc, char *mdc)
{
struct lprocfs_vars lvars[2];
struct lustre_sb_info *lsi = s2lsi(sb);
struct ll_sb_info *sbi = ll_s2sbi(sb);
struct obd_device *obd;
struct proc_dir_entry *dir;
char name[MAX_STRING_SIZE + 1], *ptr;
int err, id, len, rc;
memset(lvars, 0, sizeof(lvars));
name[MAX_STRING_SIZE] = '\0';
lvars[0].name = name;
LASSERT(sbi != NULL);
LASSERT(mdc != NULL);
LASSERT(osc != NULL);
len = strlen(lsi->lsi_lmd->lmd_profile);
ptr = strrchr(lsi->lsi_lmd->lmd_profile, '-');
if (ptr && (strcmp(ptr, "-client") == 0))
len -= 7;
snprintf(name, MAX_STRING_SIZE, "%.*s-%p", len,
lsi->lsi_lmd->lmd_profile, sb);
sbi->ll_proc_root = lprocfs_register(name, parent, NULL, NULL);
if (IS_ERR(sbi->ll_proc_root)) {
err = PTR_ERR(sbi->ll_proc_root);
sbi->ll_proc_root = NULL;
return err;
}
rc = lprocfs_seq_create(sbi->ll_proc_root, "dump_page_cache", 0444,
&vvp_dump_pgcache_file_ops, sbi);
if (rc)
CWARN("Error adding the dump_page_cache file\n");
rc = lprocfs_seq_create(sbi->ll_proc_root, "extents_stats", 0644,
&ll_rw_extents_stats_fops, sbi);
if (rc)
CWARN("Error adding the extent_stats file\n");
rc = lprocfs_seq_create(sbi->ll_proc_root, "extents_stats_per_process",
0644, &ll_rw_extents_stats_pp_fops, sbi);
if (rc)
CWARN("Error adding the extents_stats_per_process file\n");
rc = lprocfs_seq_create(sbi->ll_proc_root, "offset_stats", 0644,
&ll_rw_offset_stats_fops, sbi);
if (rc)
CWARN("Error adding the offset_stats file\n");
sbi->ll_stats = lprocfs_alloc_stats(LPROC_LL_FILE_OPCODES,
LPROCFS_STATS_FLAG_NONE);
if (sbi->ll_stats == NULL) {
err = -ENOMEM;
goto out;
}
for (id = 0; id < LPROC_LL_FILE_OPCODES; id++) {
__u32 type = llite_opcode_table[id].type;
void *ptr = NULL;
if (type & LPROCFS_TYPE_REGS)
ptr = "regs";
else if (type & LPROCFS_TYPE_BYTES)
ptr = "bytes";
else if (type & LPROCFS_TYPE_PAGES)
ptr = "pages";
lprocfs_counter_init(sbi->ll_stats,
llite_opcode_table[id].opcode,
(type & LPROCFS_CNTR_AVGMINMAX),
llite_opcode_table[id].opname, ptr);
}
err = lprocfs_register_stats(sbi->ll_proc_root, "stats", sbi->ll_stats);
if (err)
goto out;
sbi->ll_ra_stats = lprocfs_alloc_stats(ARRAY_SIZE(ra_stat_string),
LPROCFS_STATS_FLAG_NONE);
if (sbi->ll_ra_stats == NULL) {
err = -ENOMEM;
goto out;
}
for (id = 0; id < ARRAY_SIZE(ra_stat_string); id++)
lprocfs_counter_init(sbi->ll_ra_stats, id, 0,
ra_stat_string[id], "pages");
err = lprocfs_register_stats(sbi->ll_proc_root, "read_ahead_stats",
sbi->ll_ra_stats);
if (err)
goto out;
err = lprocfs_add_vars(sbi->ll_proc_root, lprocfs_llite_obd_vars, sb);
if (err)
goto out;
obd = class_name2obd(mdc);
LASSERT(obd != NULL);
LASSERT(obd->obd_magic == OBD_DEVICE_MAGIC);
LASSERT(obd->obd_type->typ_name != NULL);
dir = proc_mkdir(obd->obd_type->typ_name, sbi->ll_proc_root);
if (dir == NULL) {
err = -ENOMEM;
goto out;
}
snprintf(name, MAX_STRING_SIZE, "common_name");
lvars[0].fops = &llite_name_fops;
err = lprocfs_add_vars(dir, lvars, obd);
if (err)
goto out;
snprintf(name, MAX_STRING_SIZE, "uuid");
lvars[0].fops = &llite_uuid_fops;
err = lprocfs_add_vars(dir, lvars, obd);
if (err)
goto out;
obd = class_name2obd(osc);
LASSERT(obd != NULL);
LASSERT(obd->obd_magic == OBD_DEVICE_MAGIC);
LASSERT(obd->obd_type->typ_name != NULL);
dir = proc_mkdir(obd->obd_type->typ_name, sbi->ll_proc_root);
if (dir == NULL) {
err = -ENOMEM;
goto out;
}
snprintf(name, MAX_STRING_SIZE, "common_name");
lvars[0].fops = &llite_name_fops;
err = lprocfs_add_vars(dir, lvars, obd);
if (err)
goto out;
snprintf(name, MAX_STRING_SIZE, "uuid");
lvars[0].fops = &llite_uuid_fops;
err = lprocfs_add_vars(dir, lvars, obd);
out:
if (err) {
lprocfs_remove(&sbi->ll_proc_root);
lprocfs_free_stats(&sbi->ll_ra_stats);
lprocfs_free_stats(&sbi->ll_stats);
}
return err;
}
void lprocfs_unregister_mountpoint(struct ll_sb_info *sbi)
{
if (sbi->ll_proc_root) {
lprocfs_remove(&sbi->ll_proc_root);
lprocfs_free_stats(&sbi->ll_ra_stats);
lprocfs_free_stats(&sbi->ll_stats);
}
}
static void ll_display_extents_info(struct ll_rw_extents_info *io_extents,
struct seq_file *seq, int which)
{
unsigned long read_tot = 0, write_tot = 0, read_cum, write_cum;
unsigned long start, end, r, w;
char *unitp = "KMGTPEZY";
int i, units = 10;
struct per_process_info *pp_info = &io_extents->pp_extents[which];
read_cum = 0;
write_cum = 0;
start = 0;
for (i = 0; i < LL_HIST_MAX; i++) {
read_tot += pp_info->pp_r_hist.oh_buckets[i];
write_tot += pp_info->pp_w_hist.oh_buckets[i];
}
for (i = 0; i < LL_HIST_MAX; i++) {
r = pp_info->pp_r_hist.oh_buckets[i];
w = pp_info->pp_w_hist.oh_buckets[i];
read_cum += r;
write_cum += w;
end = 1 << (i + LL_HIST_START - units);
seq_printf(seq, "%4lu%c - %4lu%c%c: %14lu %4lu %4lu | %14lu %4lu %4lu\n",
start, *unitp, end, *unitp,
(i == LL_HIST_MAX - 1) ? '+' : ' ',
r, pct(r, read_tot), pct(read_cum, read_tot),
w, pct(w, write_tot), pct(write_cum, write_tot));
start = end;
if (start == 1<<10) {
start = 1;
units += 10;
unitp++;
}
if (read_cum == read_tot && write_cum == write_tot)
break;
}
}
static int ll_rw_extents_stats_pp_seq_show(struct seq_file *seq, void *v)
{
struct timeval now;
struct ll_sb_info *sbi = seq->private;
struct ll_rw_extents_info *io_extents = &sbi->ll_rw_extents_info;
int k;
do_gettimeofday(&now);
if (!sbi->ll_rw_stats_on) {
seq_printf(seq, "disabled\n"
"write anything in this file to activate, then 0 or \"[D/d]isabled\" to deactivate\n");
return 0;
}
seq_printf(seq, "snapshot_time: %lu.%lu (secs.usecs)\n",
now.tv_sec, (unsigned long)now.tv_usec);
seq_printf(seq, "%15s %19s | %20s\n", " ", "read", "write");
seq_printf(seq, "%13s %14s %4s %4s | %14s %4s %4s\n",
"extents", "calls", "%", "cum%",
"calls", "%", "cum%");
spin_lock(&sbi->ll_pp_extent_lock);
for (k = 0; k < LL_PROCESS_HIST_MAX; k++) {
if (io_extents->pp_extents[k].pid != 0) {
seq_printf(seq, "\nPID: %d\n",
io_extents->pp_extents[k].pid);
ll_display_extents_info(io_extents, seq, k);
}
}
spin_unlock(&sbi->ll_pp_extent_lock);
return 0;
}
static ssize_t ll_rw_extents_stats_pp_seq_write(struct file *file,
const char __user *buf,
size_t len,
loff_t *off)
{
struct seq_file *seq = file->private_data;
struct ll_sb_info *sbi = seq->private;
struct ll_rw_extents_info *io_extents = &sbi->ll_rw_extents_info;
int i;
int value = 1, rc = 0;
if (len == 0)
return -EINVAL;
rc = lprocfs_write_helper(buf, len, &value);
if (rc < 0 && len < 16) {
char kernbuf[16];
if (copy_from_user(kernbuf, buf, len))
return -EFAULT;
kernbuf[len] = 0;
if (kernbuf[len - 1] == '\n')
kernbuf[len - 1] = 0;
if (strcmp(kernbuf, "disabled") == 0 ||
strcmp(kernbuf, "Disabled") == 0)
value = 0;
}
if (value == 0)
sbi->ll_rw_stats_on = 0;
else
sbi->ll_rw_stats_on = 1;
spin_lock(&sbi->ll_pp_extent_lock);
for (i = 0; i < LL_PROCESS_HIST_MAX; i++) {
io_extents->pp_extents[i].pid = 0;
lprocfs_oh_clear(&io_extents->pp_extents[i].pp_r_hist);
lprocfs_oh_clear(&io_extents->pp_extents[i].pp_w_hist);
}
spin_unlock(&sbi->ll_pp_extent_lock);
return len;
}
static int ll_rw_extents_stats_seq_show(struct seq_file *seq, void *v)
{
struct timeval now;
struct ll_sb_info *sbi = seq->private;
struct ll_rw_extents_info *io_extents = &sbi->ll_rw_extents_info;
do_gettimeofday(&now);
if (!sbi->ll_rw_stats_on) {
seq_printf(seq, "disabled\n"
"write anything in this file to activate, then 0 or \"[D/d]isabled\" to deactivate\n");
return 0;
}
seq_printf(seq, "snapshot_time: %lu.%lu (secs.usecs)\n",
now.tv_sec, (unsigned long)now.tv_usec);
seq_printf(seq, "%15s %19s | %20s\n", " ", "read", "write");
seq_printf(seq, "%13s %14s %4s %4s | %14s %4s %4s\n",
"extents", "calls", "%", "cum%",
"calls", "%", "cum%");
spin_lock(&sbi->ll_lock);
ll_display_extents_info(io_extents, seq, LL_PROCESS_HIST_MAX);
spin_unlock(&sbi->ll_lock);
return 0;
}
static ssize_t ll_rw_extents_stats_seq_write(struct file *file,
const char __user *buf,
size_t len, loff_t *off)
{
struct seq_file *seq = file->private_data;
struct ll_sb_info *sbi = seq->private;
struct ll_rw_extents_info *io_extents = &sbi->ll_rw_extents_info;
int i;
int value = 1, rc = 0;
if (len == 0)
return -EINVAL;
rc = lprocfs_write_helper(buf, len, &value);
if (rc < 0 && len < 16) {
char kernbuf[16];
if (copy_from_user(kernbuf, buf, len))
return -EFAULT;
kernbuf[len] = 0;
if (kernbuf[len - 1] == '\n')
kernbuf[len - 1] = 0;
if (strcmp(kernbuf, "disabled") == 0 ||
strcmp(kernbuf, "Disabled") == 0)
value = 0;
}
if (value == 0)
sbi->ll_rw_stats_on = 0;
else
sbi->ll_rw_stats_on = 1;
spin_lock(&sbi->ll_pp_extent_lock);
for (i = 0; i <= LL_PROCESS_HIST_MAX; i++) {
io_extents->pp_extents[i].pid = 0;
lprocfs_oh_clear(&io_extents->pp_extents[i].pp_r_hist);
lprocfs_oh_clear(&io_extents->pp_extents[i].pp_w_hist);
}
spin_unlock(&sbi->ll_pp_extent_lock);
return len;
}
void ll_rw_stats_tally(struct ll_sb_info *sbi, pid_t pid,
struct ll_file_data *file, loff_t pos,
size_t count, int rw)
{
int i, cur = -1;
struct ll_rw_process_info *process;
struct ll_rw_process_info *offset;
int *off_count = &sbi->ll_rw_offset_entry_count;
int *process_count = &sbi->ll_offset_process_count;
struct ll_rw_extents_info *io_extents = &sbi->ll_rw_extents_info;
if (!sbi->ll_rw_stats_on)
return;
process = sbi->ll_rw_process_info;
offset = sbi->ll_rw_offset_info;
spin_lock(&sbi->ll_pp_extent_lock);
for (i = 0; i < LL_PROCESS_HIST_MAX; i++) {
if (io_extents->pp_extents[i].pid == pid) {
cur = i;
break;
}
}
if (cur == -1) {
sbi->ll_extent_process_count =
(sbi->ll_extent_process_count + 1) % LL_PROCESS_HIST_MAX;
cur = sbi->ll_extent_process_count;
io_extents->pp_extents[cur].pid = pid;
lprocfs_oh_clear(&io_extents->pp_extents[cur].pp_r_hist);
lprocfs_oh_clear(&io_extents->pp_extents[cur].pp_w_hist);
}
for(i = 0; (count >= (1 << LL_HIST_START << i)) &&
(i < (LL_HIST_MAX - 1)); i++);
if (rw == 0) {
io_extents->pp_extents[cur].pp_r_hist.oh_buckets[i]++;
io_extents->pp_extents[LL_PROCESS_HIST_MAX].pp_r_hist.oh_buckets[i]++;
} else {
io_extents->pp_extents[cur].pp_w_hist.oh_buckets[i]++;
io_extents->pp_extents[LL_PROCESS_HIST_MAX].pp_w_hist.oh_buckets[i]++;
}
spin_unlock(&sbi->ll_pp_extent_lock);
spin_lock(&sbi->ll_process_lock);
for (i = 0; i < LL_PROCESS_HIST_MAX; i++) {
if (process[i].rw_pid == pid) {
if (process[i].rw_last_file != file) {
process[i].rw_range_start = pos;
process[i].rw_last_file_pos = pos + count;
process[i].rw_smallest_extent = count;
process[i].rw_largest_extent = count;
process[i].rw_offset = 0;
process[i].rw_last_file = file;
spin_unlock(&sbi->ll_process_lock);
return;
}
if (process[i].rw_last_file_pos != pos) {
*off_count =
(*off_count + 1) % LL_OFFSET_HIST_MAX;
offset[*off_count].rw_op = process[i].rw_op;
offset[*off_count].rw_pid = pid;
offset[*off_count].rw_range_start =
process[i].rw_range_start;
offset[*off_count].rw_range_end =
process[i].rw_last_file_pos;
offset[*off_count].rw_smallest_extent =
process[i].rw_smallest_extent;
offset[*off_count].rw_largest_extent =
process[i].rw_largest_extent;
offset[*off_count].rw_offset =
process[i].rw_offset;
process[i].rw_op = rw;
process[i].rw_range_start = pos;
process[i].rw_smallest_extent = count;
process[i].rw_largest_extent = count;
process[i].rw_offset = pos -
process[i].rw_last_file_pos;
}
if (process[i].rw_smallest_extent > count)
process[i].rw_smallest_extent = count;
if (process[i].rw_largest_extent < count)
process[i].rw_largest_extent = count;
process[i].rw_last_file_pos = pos + count;
spin_unlock(&sbi->ll_process_lock);
return;
}
}
*process_count = (*process_count + 1) % LL_PROCESS_HIST_MAX;
process[*process_count].rw_pid = pid;
process[*process_count].rw_op = rw;
process[*process_count].rw_range_start = pos;
process[*process_count].rw_last_file_pos = pos + count;
process[*process_count].rw_smallest_extent = count;
process[*process_count].rw_largest_extent = count;
process[*process_count].rw_offset = 0;
process[*process_count].rw_last_file = file;
spin_unlock(&sbi->ll_process_lock);
}
static int ll_rw_offset_stats_seq_show(struct seq_file *seq, void *v)
{
struct timeval now;
struct ll_sb_info *sbi = seq->private;
struct ll_rw_process_info *offset = sbi->ll_rw_offset_info;
struct ll_rw_process_info *process = sbi->ll_rw_process_info;
int i;
do_gettimeofday(&now);
if (!sbi->ll_rw_stats_on) {
seq_printf(seq, "disabled\n"
"write anything in this file to activate, then 0 or \"[D/d]isabled\" to deactivate\n");
return 0;
}
spin_lock(&sbi->ll_process_lock);
seq_printf(seq, "snapshot_time: %lu.%lu (secs.usecs)\n",
now.tv_sec, (unsigned long)now.tv_usec);
seq_printf(seq, "%3s %10s %14s %14s %17s %17s %14s\n",
"R/W", "PID", "RANGE START", "RANGE END",
"SMALLEST EXTENT", "LARGEST EXTENT", "OFFSET");
for (i = 0; i < LL_OFFSET_HIST_MAX; i++) {
if (offset[i].rw_pid != 0)
seq_printf(seq,
"%3c %10d %14Lu %14Lu %17lu %17lu %14Lu",
offset[i].rw_op == READ ? 'R' : 'W',
offset[i].rw_pid,
offset[i].rw_range_start,
offset[i].rw_range_end,
(unsigned long)offset[i].rw_smallest_extent,
(unsigned long)offset[i].rw_largest_extent,
offset[i].rw_offset);
}
for (i = 0; i < LL_PROCESS_HIST_MAX; i++) {
if (process[i].rw_pid != 0)
seq_printf(seq,
"%3c %10d %14Lu %14Lu %17lu %17lu %14Lu",
process[i].rw_op == READ ? 'R' : 'W',
process[i].rw_pid,
process[i].rw_range_start,
process[i].rw_last_file_pos,
(unsigned long)process[i].rw_smallest_extent,
(unsigned long)process[i].rw_largest_extent,
process[i].rw_offset);
}
spin_unlock(&sbi->ll_process_lock);
return 0;
}
static ssize_t ll_rw_offset_stats_seq_write(struct file *file,
const char __user *buf,
size_t len, loff_t *off)
{
struct seq_file *seq = file->private_data;
struct ll_sb_info *sbi = seq->private;
struct ll_rw_process_info *process_info = sbi->ll_rw_process_info;
struct ll_rw_process_info *offset_info = sbi->ll_rw_offset_info;
int value = 1, rc = 0;
if (len == 0)
return -EINVAL;
rc = lprocfs_write_helper(buf, len, &value);
if (rc < 0 && len < 16) {
char kernbuf[16];
if (copy_from_user(kernbuf, buf, len))
return -EFAULT;
kernbuf[len] = 0;
if (kernbuf[len - 1] == '\n')
kernbuf[len - 1] = 0;
if (strcmp(kernbuf, "disabled") == 0 ||
strcmp(kernbuf, "Disabled") == 0)
value = 0;
}
if (value == 0)
sbi->ll_rw_stats_on = 0;
else
sbi->ll_rw_stats_on = 1;
spin_lock(&sbi->ll_process_lock);
sbi->ll_offset_process_count = 0;
sbi->ll_rw_offset_entry_count = 0;
memset(process_info, 0, sizeof(struct ll_rw_process_info) *
LL_PROCESS_HIST_MAX);
memset(offset_info, 0, sizeof(struct ll_rw_process_info) *
LL_OFFSET_HIST_MAX);
spin_unlock(&sbi->ll_process_lock);
return len;
}
void lprocfs_llite_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->module_vars = NULL;
lvars->obd_vars = lprocfs_llite_obd_vars;
}
