static void ll_cl_fini(struct ll_cl_context *lcc)
{
struct lu_env *env = lcc->lcc_env;
struct cl_io *io = lcc->lcc_io;
struct cl_page *page = lcc->lcc_page;
LASSERT(lcc->lcc_cookie == current);
LASSERT(env != NULL);
if (page != NULL) {
lu_ref_del(&page->cp_reference, "cl_io", io);
cl_page_put(env, page);
}
cl_env_put(env, &lcc->lcc_refcheck);
}
static struct ll_cl_context *ll_cl_init(struct file *file,
struct page *vmpage, int create)
{
struct ll_cl_context *lcc;
struct lu_env *env;
struct cl_io *io;
struct cl_object *clob;
struct ccc_io *cio;
int refcheck;
int result = 0;
clob = ll_i2info(vmpage->mapping->host)->lli_clob;
LASSERT(clob != NULL);
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return ERR_CAST(env);
lcc = &vvp_env_info(env)->vti_io_ctx;
memset(lcc, 0, sizeof(*lcc));
lcc->lcc_env = env;
lcc->lcc_refcheck = refcheck;
lcc->lcc_cookie = current;
cio = ccc_env_io(env);
io = cio->cui_cl.cis_io;
if (io == NULL && create) {
struct inode *inode = vmpage->mapping->host;
loff_t pos;
if (mutex_trylock(&inode->i_mutex)) {
mutex_unlock(&(inode)->i_mutex);
CERROR("Proc %s is dirting page w/o inode lock, this"
"will break truncate.\n", current->comm);
dump_stack();
LBUG();
return ERR_PTR(-EIO);
}
io = ccc_env_thread_io(env);
ll_io_init(io, file, 1);
io->ci_lockreq = CILR_NEVER;
pos = (vmpage->index << PAGE_CACHE_SHIFT);
result = cl_io_rw_init(env, io, CIT_WRITE, pos, PAGE_CACHE_SIZE);
if (result == 0) {
cio->cui_fd = LUSTRE_FPRIVATE(file);
cio->cui_iter = NULL;
result = cl_io_iter_init(env, io);
if (result == 0) {
result = cl_io_lock(env, io);
if (result == 0)
result = cl_io_start(env, io);
}
} else
result = io->ci_result;
}
lcc->lcc_io = io;
if (io == NULL)
result = -EIO;
if (result == 0) {
struct cl_page *page;
LASSERT(io != NULL);
LASSERT(io->ci_state == CIS_IO_GOING);
LASSERT(cio->cui_fd == LUSTRE_FPRIVATE(file));
page = cl_page_find(env, clob, vmpage->index, vmpage,
CPT_CACHEABLE);
if (!IS_ERR(page)) {
lcc->lcc_page = page;
lu_ref_add(&page->cp_reference, "cl_io", io);
result = 0;
} else
result = PTR_ERR(page);
}
if (result) {
ll_cl_fini(lcc);
lcc = ERR_PTR(result);
}
CDEBUG(D_VFSTRACE, "%lu@"DFID" -> %d %p %p\n",
vmpage->index, PFID(lu_object_fid(&clob->co_lu)), result,
env, io);
return lcc;
}
static struct ll_cl_context *ll_cl_get(void)
{
struct ll_cl_context *lcc;
struct lu_env *env;
int refcheck;
env = cl_env_get(&refcheck);
LASSERT(!IS_ERR(env));
lcc = &vvp_env_info(env)->vti_io_ctx;
LASSERT(env == lcc->lcc_env);
LASSERT(current == lcc->lcc_cookie);
cl_env_put(env, &refcheck);
return lcc;
}
int ll_prepare_write(struct file *file, struct page *vmpage, unsigned from,
unsigned to)
{
struct ll_cl_context *lcc;
int result;
lcc = ll_cl_init(file, vmpage, 1);
if (!IS_ERR(lcc)) {
struct lu_env *env = lcc->lcc_env;
struct cl_io *io = lcc->lcc_io;
struct cl_page *page = lcc->lcc_page;
cl_page_assume(env, io, page);
result = cl_io_prepare_write(env, io, page, from, to);
if (result == 0) {
cl_page_get(page);
lu_ref_add(&page->cp_reference, "prepare_write",
current);
} else {
cl_page_unassume(env, io, page);
ll_cl_fini(lcc);
}
} else {
result = PTR_ERR(lcc);
}
return result;
}
int ll_commit_write(struct file *file, struct page *vmpage, unsigned from,
unsigned to)
{
struct ll_cl_context *lcc;
struct lu_env *env;
struct cl_io *io;
struct cl_page *page;
int result = 0;
lcc = ll_cl_get();
env = lcc->lcc_env;
page = lcc->lcc_page;
io = lcc->lcc_io;
LASSERT(cl_page_is_owned(page, io));
LASSERT(from <= to);
if (from != to)
result = cl_io_commit_write(env, io, page, from, to);
if (cl_page_is_owned(page, io))
cl_page_unassume(env, io, page);
lu_ref_del(&page->cp_reference, "prepare_write", current);
cl_page_put(env, page);
ll_cl_fini(lcc);
return result;
}
struct obd_capa *cl_capa_lookup(struct inode *inode, enum cl_req_type crt)
{
__u64 opc;
opc = crt == CRT_WRITE ? CAPA_OPC_OSS_WRITE : CAPA_OPC_OSS_RW;
return ll_osscapa_get(inode, opc);
}
static unsigned long ll_ra_count_get(struct ll_sb_info *sbi,
struct ra_io_arg *ria,
unsigned long pages)
{
struct ll_ra_info *ra = &sbi->ll_ra_info;
long ret;
ret = min(ra->ra_max_pages - atomic_read(&ra->ra_cur_pages), pages);
if (ret < 0 || ret < min_t(long, PTLRPC_MAX_BRW_PAGES, pages))
GOTO(out, ret = 0);
if (ria->ria_pages == 0) {
long beyond_rpc = (ria->ria_start + ret) % PTLRPC_MAX_BRW_PAGES;
if ( beyond_rpc < ret)
ret -= beyond_rpc;
}
if (atomic_add_return(ret, &ra->ra_cur_pages) > ra->ra_max_pages) {
atomic_sub(ret, &ra->ra_cur_pages);
ret = 0;
}
out:
return ret;
}
void ll_ra_count_put(struct ll_sb_info *sbi, unsigned long len)
{
struct ll_ra_info *ra = &sbi->ll_ra_info;
atomic_sub(len, &ra->ra_cur_pages);
}
static void ll_ra_stats_inc_sbi(struct ll_sb_info *sbi, enum ra_stat which)
{
LASSERTF(which >= 0 && which < _NR_RA_STAT, "which: %u\n", which);
lprocfs_counter_incr(sbi->ll_ra_stats, which);
}
void ll_ra_stats_inc(struct address_space *mapping, enum ra_stat which)
{
struct ll_sb_info *sbi = ll_i2sbi(mapping->host);
ll_ra_stats_inc_sbi(sbi, which);
}
static int index_in_window(unsigned long index, unsigned long point,
unsigned long before, unsigned long after)
{
unsigned long start = point - before, end = point + after;
if (start > point)
start = 0;
if (end < point)
end = ~0;
return start <= index && index <= end;
}
static struct ll_readahead_state *ll_ras_get(struct file *f)
{
struct ll_file_data *fd;
fd = LUSTRE_FPRIVATE(f);
return &fd->fd_ras;
}
void ll_ra_read_in(struct file *f, struct ll_ra_read *rar)
{
struct ll_readahead_state *ras;
ras = ll_ras_get(f);
spin_lock(&ras->ras_lock);
ras->ras_requests++;
ras->ras_request_index = 0;
ras->ras_consecutive_requests++;
rar->lrr_reader = current;
list_add(&rar->lrr_linkage, &ras->ras_read_beads);
spin_unlock(&ras->ras_lock);
}
void ll_ra_read_ex(struct file *f, struct ll_ra_read *rar)
{
struct ll_readahead_state *ras;
ras = ll_ras_get(f);
spin_lock(&ras->ras_lock);
list_del_init(&rar->lrr_linkage);
spin_unlock(&ras->ras_lock);
}
static struct ll_ra_read *ll_ra_read_get_locked(struct ll_readahead_state *ras)
{
struct ll_ra_read *scan;
list_for_each_entry(scan, &ras->ras_read_beads, lrr_linkage) {
if (scan->lrr_reader == current)
return scan;
}
return NULL;
}
struct ll_ra_read *ll_ra_read_get(struct file *f)
{
struct ll_readahead_state *ras;
struct ll_ra_read *bead;
ras = ll_ras_get(f);
spin_lock(&ras->ras_lock);
bead = ll_ra_read_get_locked(ras);
spin_unlock(&ras->ras_lock);
return bead;
}
static int cl_read_ahead_page(const struct lu_env *env, struct cl_io *io,
struct cl_page_list *queue, struct cl_page *page,
struct page *vmpage)
{
struct ccc_page *cp;
int rc;
rc = 0;
cl_page_assume(env, io, page);
lu_ref_add(&page->cp_reference, "ra", current);
cp = cl2ccc_page(cl_page_at(page, &vvp_device_type));
if (!cp->cpg_defer_uptodate && !PageUptodate(vmpage)) {
rc = cl_page_is_under_lock(env, io, page);
if (rc == -EBUSY) {
cp->cpg_defer_uptodate = 1;
cp->cpg_ra_used = 0;
cl_page_list_add(queue, page);
rc = 1;
} else {
cl_page_delete(env, page);
rc = -ENOLCK;
}
} else {
cl_page_unassume(env, io, page);
}
lu_ref_del(&page->cp_reference, "ra", current);
cl_page_put(env, page);
return rc;
}
static int ll_read_ahead_page(const struct lu_env *env, struct cl_io *io,
struct cl_page_list *queue,
pgoff_t index, struct address_space *mapping)
{
struct page *vmpage;
struct cl_object *clob = ll_i2info(mapping->host)->lli_clob;
struct cl_page *page;
enum ra_stat which = _NR_RA_STAT;
int rc = 0;
const char *msg = NULL;
vmpage = grab_cache_page_nowait(mapping, index);
if (vmpage != NULL) {
if (vmpage->mapping == mapping) {
page = cl_page_find(env, clob, vmpage->index,
vmpage, CPT_CACHEABLE);
if (!IS_ERR(page)) {
rc = cl_read_ahead_page(env, io, queue,
page, vmpage);
if (rc == -ENOLCK) {
which = RA_STAT_FAILED_MATCH;
msg = "lock match failed";
}
} else {
which = RA_STAT_FAILED_GRAB_PAGE;
msg = "cl_page_find failed";
}
} else {
which = RA_STAT_WRONG_GRAB_PAGE;
msg = "g_c_p_n returned invalid page";
}
if (rc != 1)
unlock_page(vmpage);
page_cache_release(vmpage);
} else {
which = RA_STAT_FAILED_GRAB_PAGE;
msg = "g_c_p_n failed";
}
if (msg != NULL) {
ll_ra_stats_inc(mapping, which);
CDEBUG(D_READA, "%s\n", msg);
}
return rc;
}
static inline int stride_io_mode(struct ll_readahead_state *ras)
{
return ras->ras_consecutive_stride_requests > 1;
}
static unsigned long
stride_pg_count(pgoff_t st_off, unsigned long st_len, unsigned long st_pgs,
unsigned long off, unsigned long length)
{
__u64 start = off > st_off ? off - st_off : 0;
__u64 end = off + length > st_off ? off + length - st_off : 0;
unsigned long start_left = 0;
unsigned long end_left = 0;
unsigned long pg_count;
if (st_len == 0 || length == 0 || end == 0)
return length;
start_left = do_div(start, st_len);
if (start_left < st_pgs)
start_left = st_pgs - start_left;
else
start_left = 0;
end_left = do_div(end, st_len);
if (end_left > st_pgs)
end_left = st_pgs;
CDEBUG(D_READA, "start %llu, end %llu start_left %lu end_left %lu \n",
start, end, start_left, end_left);
if (start == end)
pg_count = end_left - (st_pgs - start_left);
else
pg_count = start_left + st_pgs * (end - start - 1) + end_left;
CDEBUG(D_READA, "st_off %lu, st_len %lu st_pgs %lu off %lu length %lu"
"pgcount %lu\n", st_off, st_len, st_pgs, off, length, pg_count);
return pg_count;
}
static int ria_page_count(struct ra_io_arg *ria)
{
__u64 length = ria->ria_end >= ria->ria_start ?
ria->ria_end - ria->ria_start + 1 : 0;
return stride_pg_count(ria->ria_stoff, ria->ria_length,
ria->ria_pages, ria->ria_start,
length);
}
static int ras_inside_ra_window(unsigned long idx, struct ra_io_arg *ria)
{
return ria->ria_length == 0 || ria->ria_length == ria->ria_pages ||
(idx >= ria->ria_stoff && (idx - ria->ria_stoff) %
ria->ria_length < ria->ria_pages);
}
static int ll_read_ahead_pages(const struct lu_env *env,
struct cl_io *io, struct cl_page_list *queue,
struct ra_io_arg *ria,
unsigned long *reserved_pages,
struct address_space *mapping,
unsigned long *ra_end)
{
int rc, count = 0, stride_ria;
unsigned long page_idx;
LASSERT(ria != NULL);
RIA_DEBUG(ria);
stride_ria = ria->ria_length > ria->ria_pages && ria->ria_pages > 0;
for (page_idx = ria->ria_start; page_idx <= ria->ria_end &&
*reserved_pages > 0; page_idx++) {
if (ras_inside_ra_window(page_idx, ria)) {
rc = ll_read_ahead_page(env, io, queue,
page_idx, mapping);
if (rc == 1) {
(*reserved_pages)--;
count ++;
} else if (rc == -ENOLCK)
break;
} else if (stride_ria) {
pgoff_t offset;
LASSERTF(page_idx > ria->ria_stoff, "Invalid page_idx %lu"
"rs %lu re %lu ro %lu rl %lu rp %lu\n", page_idx,
ria->ria_start, ria->ria_end, ria->ria_stoff,
ria->ria_length, ria->ria_pages);
offset = page_idx - ria->ria_stoff;
offset = offset % (ria->ria_length);
if (offset > ria->ria_pages) {
page_idx += ria->ria_length - offset;
CDEBUG(D_READA, "i %lu skip %lu \n", page_idx,
ria->ria_length - offset);
continue;
}
}
}
*ra_end = page_idx;
return count;
}
int ll_readahead(const struct lu_env *env, struct cl_io *io,
struct ll_readahead_state *ras, struct address_space *mapping,
struct cl_page_list *queue, int flags)
{
struct vvp_io *vio = vvp_env_io(env);
struct vvp_thread_info *vti = vvp_env_info(env);
struct cl_attr *attr = ccc_env_thread_attr(env);
unsigned long start = 0, end = 0, reserved;
unsigned long ra_end, len;
struct inode *inode;
struct ll_ra_read *bead;
struct ra_io_arg *ria = &vti->vti_ria;
struct ll_inode_info *lli;
struct cl_object *clob;
int ret = 0;
__u64 kms;
inode = mapping->host;
lli = ll_i2info(inode);
clob = lli->lli_clob;
memset(ria, 0, sizeof(*ria));
cl_object_attr_lock(clob);
ret = cl_object_attr_get(env, clob, attr);
cl_object_attr_unlock(clob);
if (ret != 0)
return ret;
kms = attr->cat_kms;
if (kms == 0) {
ll_ra_stats_inc(mapping, RA_STAT_ZERO_LEN);
return 0;
}
spin_lock(&ras->ras_lock);
if (vio->cui_ra_window_set)
bead = &vio->cui_bead;
else
bead = NULL;
if (bead != NULL && ras->ras_window_start + ras->ras_window_len <
bead->lrr_start + bead->lrr_count) {
ras->ras_window_len = bead->lrr_start + bead->lrr_count -
ras->ras_window_start;
}
if (ras->ras_window_len) {
start = ras->ras_next_readahead;
end = ras->ras_window_start + ras->ras_window_len - 1;
}
if (end != 0) {
unsigned long rpc_boundary;
rpc_boundary = ((end + 1) & (~(PTLRPC_MAX_BRW_PAGES - 1)));
if (rpc_boundary > 0)
rpc_boundary--;
if (rpc_boundary > start)
end = rpc_boundary;
end = min(end, (unsigned long)((kms - 1) >> PAGE_CACHE_SHIFT));
ras->ras_next_readahead = max(end, end + 1);
RAS_CDEBUG(ras);
}
ria->ria_start = start;
ria->ria_end = end;
if (stride_io_mode(ras)) {
ria->ria_stoff = ras->ras_stride_offset;
ria->ria_length = ras->ras_stride_length;
ria->ria_pages = ras->ras_stride_pages;
}
spin_unlock(&ras->ras_lock);
if (end == 0) {
ll_ra_stats_inc(mapping, RA_STAT_ZERO_WINDOW);
return 0;
}
len = ria_page_count(ria);
if (len == 0)
return 0;
reserved = ll_ra_count_get(ll_i2sbi(inode), ria, len);
if (reserved < len)
ll_ra_stats_inc(mapping, RA_STAT_MAX_IN_FLIGHT);
CDEBUG(D_READA, "reserved page %lu ra_cur %d ra_max %lu\n", reserved,
atomic_read(&ll_i2sbi(inode)->ll_ra_info.ra_cur_pages),
ll_i2sbi(inode)->ll_ra_info.ra_max_pages);
ret = ll_read_ahead_pages(env, io, queue,
ria, &reserved, mapping, &ra_end);
LASSERTF(reserved >= 0, "reserved %lu\n", reserved);
if (reserved != 0)
ll_ra_count_put(ll_i2sbi(inode), reserved);
if (ra_end == end + 1 && ra_end == (kms >> PAGE_CACHE_SHIFT))
ll_ra_stats_inc(mapping, RA_STAT_EOF);
CDEBUG(D_READA, "ra_end %lu end %lu stride end %lu \n",
ra_end, end, ria->ria_end);
if (ra_end != end + 1) {
spin_lock(&ras->ras_lock);
if (ra_end < ras->ras_next_readahead &&
index_in_window(ra_end, ras->ras_window_start, 0,
ras->ras_window_len)) {
ras->ras_next_readahead = ra_end;
RAS_CDEBUG(ras);
}
spin_unlock(&ras->ras_lock);
}
return ret;
}
static void ras_set_start(struct inode *inode, struct ll_readahead_state *ras,
unsigned long index)
{
ras->ras_window_start = index & (~(RAS_INCREASE_STEP(inode) - 1));
}
static void ras_reset(struct inode *inode, struct ll_readahead_state *ras,
unsigned long index)
{
ras->ras_last_readpage = index;
ras->ras_consecutive_requests = 0;
ras->ras_consecutive_pages = 0;
ras->ras_window_len = 0;
ras_set_start(inode, ras, index);
ras->ras_next_readahead = max(ras->ras_window_start, index);
RAS_CDEBUG(ras);
}
static void ras_stride_reset(struct ll_readahead_state *ras)
{
ras->ras_consecutive_stride_requests = 0;
ras->ras_stride_length = 0;
ras->ras_stride_pages = 0;
RAS_CDEBUG(ras);
}
void ll_readahead_init(struct inode *inode, struct ll_readahead_state *ras)
{
spin_lock_init(&ras->ras_lock);
ras_reset(inode, ras, 0);
ras->ras_requests = 0;
INIT_LIST_HEAD(&ras->ras_read_beads);
}
static int index_in_stride_window(struct ll_readahead_state *ras,
unsigned long index)
{
unsigned long stride_gap;
if (ras->ras_stride_length == 0 || ras->ras_stride_pages == 0 ||
ras->ras_stride_pages == ras->ras_stride_length)
return 0;
stride_gap = index - ras->ras_last_readpage - 1;
if (stride_gap == 0)
return ras->ras_consecutive_pages + 1 <= ras->ras_stride_pages;
return (ras->ras_stride_length - ras->ras_stride_pages) == stride_gap &&
ras->ras_consecutive_pages == ras->ras_stride_pages;
}
static void ras_update_stride_detector(struct ll_readahead_state *ras,
unsigned long index)
{
unsigned long stride_gap = index - ras->ras_last_readpage - 1;
if (!stride_io_mode(ras) && (stride_gap != 0 ||
ras->ras_consecutive_stride_requests == 0)) {
ras->ras_stride_pages = ras->ras_consecutive_pages;
ras->ras_stride_length = stride_gap +ras->ras_consecutive_pages;
}
LASSERT(ras->ras_request_index == 0);
LASSERT(ras->ras_consecutive_stride_requests == 0);
if (index <= ras->ras_last_readpage) {
ras_stride_reset(ras);
return;
}
ras->ras_stride_pages = ras->ras_consecutive_pages;
ras->ras_stride_length = stride_gap +ras->ras_consecutive_pages;
RAS_CDEBUG(ras);
return;
}
static unsigned long
stride_page_count(struct ll_readahead_state *ras, unsigned long len)
{
return stride_pg_count(ras->ras_stride_offset, ras->ras_stride_length,
ras->ras_stride_pages, ras->ras_stride_offset,
len);
}
static void ras_stride_increase_window(struct ll_readahead_state *ras,
struct ll_ra_info *ra,
unsigned long inc_len)
{
unsigned long left, step, window_len;
unsigned long stride_len;
LASSERT(ras->ras_stride_length > 0);
LASSERTF(ras->ras_window_start + ras->ras_window_len
>= ras->ras_stride_offset, "window_start %lu, window_len %lu"
" stride_offset %lu\n", ras->ras_window_start,
ras->ras_window_len, ras->ras_stride_offset);
stride_len = ras->ras_window_start + ras->ras_window_len -
ras->ras_stride_offset;
left = stride_len % ras->ras_stride_length;
window_len = ras->ras_window_len - left;
if (left < ras->ras_stride_pages)
left += inc_len;
else
left = ras->ras_stride_pages + inc_len;
LASSERT(ras->ras_stride_pages != 0);
step = left / ras->ras_stride_pages;
left %= ras->ras_stride_pages;
window_len += step * ras->ras_stride_length + left;
if (stride_page_count(ras, window_len) <= ra->ra_max_pages_per_file)
ras->ras_window_len = window_len;
RAS_CDEBUG(ras);
}
static void ras_increase_window(struct inode *inode,
struct ll_readahead_state *ras,
struct ll_ra_info *ra)
{
if (stride_io_mode(ras))
ras_stride_increase_window(ras, ra, RAS_INCREASE_STEP(inode));
else
ras->ras_window_len = min(ras->ras_window_len +
RAS_INCREASE_STEP(inode),
ra->ra_max_pages_per_file);
}
void ras_update(struct ll_sb_info *sbi, struct inode *inode,
struct ll_readahead_state *ras, unsigned long index,
unsigned hit)
{
struct ll_ra_info *ra = &sbi->ll_ra_info;
int zero = 0, stride_detect = 0, ra_miss = 0;
spin_lock(&ras->ras_lock);
ll_ra_stats_inc_sbi(sbi, hit ? RA_STAT_HIT : RA_STAT_MISS);
if (!index_in_window(index, ras->ras_last_readpage, 8, 8)) {
zero = 1;
ll_ra_stats_inc_sbi(sbi, RA_STAT_DISTANT_READPAGE);
} else if (!hit && ras->ras_window_len &&
index < ras->ras_next_readahead &&
index_in_window(index, ras->ras_window_start, 0,
ras->ras_window_len)) {
ra_miss = 1;
ll_ra_stats_inc_sbi(sbi, RA_STAT_MISS_IN_WINDOW);
}
if (ras->ras_requests == 2 && !ras->ras_request_index) {
__u64 kms_pages;
kms_pages = (i_size_read(inode) + PAGE_CACHE_SIZE - 1) >>
PAGE_CACHE_SHIFT;
CDEBUG(D_READA, "kmsp %llu mwp %lu mp %lu\n", kms_pages,
ra->ra_max_read_ahead_whole_pages, ra->ra_max_pages_per_file);
if (kms_pages &&
kms_pages <= ra->ra_max_read_ahead_whole_pages) {
ras->ras_window_start = 0;
ras->ras_last_readpage = 0;
ras->ras_next_readahead = 0;
ras->ras_window_len = min(ra->ra_max_pages_per_file,
ra->ra_max_read_ahead_whole_pages);
GOTO(out_unlock, 0);
}
}
if (zero) {
if (!index_in_stride_window(ras, index)) {
if (ras->ras_consecutive_stride_requests == 0 &&
ras->ras_request_index == 0) {
ras_update_stride_detector(ras, index);
ras->ras_consecutive_stride_requests++;
} else {
ras_stride_reset(ras);
}
ras_reset(inode, ras, index);
ras->ras_consecutive_pages++;
GOTO(out_unlock, 0);
} else {
ras->ras_consecutive_pages = 0;
ras->ras_consecutive_requests = 0;
if (++ras->ras_consecutive_stride_requests > 1)
stride_detect = 1;
RAS_CDEBUG(ras);
}
} else {
if (ra_miss) {
if (index_in_stride_window(ras, index) &&
stride_io_mode(ras)) {
if (index != ras->ras_last_readpage + 1)
ras->ras_consecutive_pages = 0;
ras_reset(inode, ras, index);
RAS_CDEBUG(ras);
} else {
ras_reset(inode, ras, index);
ras->ras_consecutive_pages++;
ras_stride_reset(ras);
GOTO(out_unlock, 0);
}
} else if (stride_io_mode(ras)) {
if (!index_in_stride_window(ras, index)) {
ras_stride_reset(ras);
ras->ras_window_len = 0;
ras->ras_next_readahead = index;
}
}
}
ras->ras_consecutive_pages++;
ras->ras_last_readpage = index;
ras_set_start(inode, ras, index);
if (stride_io_mode(ras))
ras->ras_next_readahead = max(index, ras->ras_next_readahead);
else
ras->ras_next_readahead = max(ras->ras_window_start,
ras->ras_next_readahead);
RAS_CDEBUG(ras);
if (!ras->ras_window_len && ras->ras_consecutive_pages == 4) {
ras->ras_window_len = RAS_INCREASE_STEP(inode);
GOTO(out_unlock, 0);
}
if (ras->ras_consecutive_stride_requests == 2 && stride_detect) {
ras->ras_next_readahead = max(index, ras->ras_next_readahead);
ras->ras_stride_offset = index;
ras->ras_window_len = RAS_INCREASE_STEP(inode);
}
if ((ras->ras_consecutive_requests > 1 || stride_detect) &&
!ras->ras_request_index)
ras_increase_window(inode, ras, ra);
out_unlock:
RAS_CDEBUG(ras);
ras->ras_request_index++;
spin_unlock(&ras->ras_lock);
return;
}
int ll_writepage(struct page *vmpage, struct writeback_control *wbc)
{
struct inode *inode = vmpage->mapping->host;
struct ll_inode_info *lli = ll_i2info(inode);
struct lu_env *env;
struct cl_io *io;
struct cl_page *page;
struct cl_object *clob;
struct cl_env_nest nest;
bool redirtied = false;
bool unlocked = false;
int result;
LASSERT(PageLocked(vmpage));
LASSERT(!PageWriteback(vmpage));
LASSERT(ll_i2dtexp(inode) != NULL);
env = cl_env_nested_get(&nest);
if (IS_ERR(env))
GOTO(out, result = PTR_ERR(env));
clob = ll_i2info(inode)->lli_clob;
LASSERT(clob != NULL);
io = ccc_env_thread_io(env);
io->ci_obj = clob;
io->ci_ignore_layout = 1;
result = cl_io_init(env, io, CIT_MISC, clob);
if (result == 0) {
page = cl_page_find(env, clob, vmpage->index,
vmpage, CPT_CACHEABLE);
if (!IS_ERR(page)) {
lu_ref_add(&page->cp_reference, "writepage",
current);
cl_page_assume(env, io, page);
result = cl_page_flush(env, io, page);
if (result != 0) {
if (!PageError(vmpage)) {
redirty_page_for_writepage(wbc, vmpage);
result = 0;
redirtied = true;
}
}
cl_page_disown(env, io, page);
unlocked = true;
lu_ref_del(&page->cp_reference,
"writepage", current);
cl_page_put(env, page);
} else {
result = PTR_ERR(page);
}
}
cl_io_fini(env, io);
if (redirtied && wbc->sync_mode == WB_SYNC_ALL) {
loff_t offset = cl_offset(clob, vmpage->index);
result = cl_sync_file_range(inode, offset,
offset + PAGE_CACHE_SIZE - 1,
CL_FSYNC_LOCAL, 1);
if (result > 0) {
wbc->nr_to_write -= result - 1;
result = 0;
}
}
cl_env_nested_put(&nest, env);
GOTO(out, result);
out:
if (result < 0) {
if (!lli->lli_async_rc)
lli->lli_async_rc = result;
SetPageError(vmpage);
if (!unlocked)
unlock_page(vmpage);
}
return result;
}
int ll_writepages(struct address_space *mapping, struct writeback_control *wbc)
{
struct inode *inode = mapping->host;
struct ll_sb_info *sbi = ll_i2sbi(inode);
loff_t start;
loff_t end;
enum cl_fsync_mode mode;
int range_whole = 0;
int result;
int ignore_layout = 0;
if (wbc->range_cyclic) {
start = mapping->writeback_index << PAGE_CACHE_SHIFT;
end = OBD_OBJECT_EOF;
} else {
start = wbc->range_start;
end = wbc->range_end;
if (end == LLONG_MAX) {
end = OBD_OBJECT_EOF;
range_whole = start == 0;
}
}
mode = CL_FSYNC_NONE;
if (wbc->sync_mode == WB_SYNC_ALL)
mode = CL_FSYNC_LOCAL;
if (sbi->ll_umounting)
ignore_layout = 1;
result = cl_sync_file_range(inode, start, end, mode, ignore_layout);
if (result > 0) {
wbc->nr_to_write -= result;
result = 0;
}
if (wbc->range_cyclic || (range_whole && wbc->nr_to_write > 0)) {
if (end == OBD_OBJECT_EOF)
end = i_size_read(inode);
mapping->writeback_index = (end >> PAGE_CACHE_SHIFT) + 1;
}
return result;
}
int ll_readpage(struct file *file, struct page *vmpage)
{
struct ll_cl_context *lcc;
int result;
lcc = ll_cl_init(file, vmpage, 0);
if (!IS_ERR(lcc)) {
struct lu_env *env = lcc->lcc_env;
struct cl_io *io = lcc->lcc_io;
struct cl_page *page = lcc->lcc_page;
LASSERT(page->cp_type == CPT_CACHEABLE);
if (likely(!PageUptodate(vmpage))) {
cl_page_assume(env, io, page);
result = cl_io_read_page(env, io, page);
} else {
unlock_page(vmpage);
result = 0;
}
ll_cl_fini(lcc);
} else {
unlock_page(vmpage);
result = PTR_ERR(lcc);
}
return result;
}
