struct dma_async_tx_descriptor *
ops_run_partial_parity(struct stripe_head *sh, struct raid5_percpu *percpu,
struct dma_async_tx_descriptor *tx)
{
int disks = sh->disks;
struct page **srcs = flex_array_get(percpu->scribble, 0);
int count = 0, pd_idx = sh->pd_idx, i;
struct async_submit_ctl submit;
pr_debug("%s: stripe %llu\n", __func__, (unsigned long long)sh->sector);
if (sh->reconstruct_state == reconstruct_state_prexor_drain_run) {
srcs[count++] = sh->dev[pd_idx].page;
} else if (sh->reconstruct_state == reconstruct_state_drain_run) {
for (i = disks; i--;) {
struct r5dev *dev = &sh->dev[i];
if (test_bit(R5_UPTODATE, &dev->flags))
srcs[count++] = dev->page;
}
} else {
return tx;
}
init_async_submit(&submit, ASYNC_TX_FENCE|ASYNC_TX_XOR_ZERO_DST, tx,
NULL, sh, flex_array_get(percpu->scribble, 0)
+ sizeof(struct page *) * (sh->disks + 2));
if (count == 1)
tx = async_memcpy(sh->ppl_page, srcs[0], 0, 0, PAGE_SIZE,
&submit);
else
tx = async_xor(sh->ppl_page, srcs, 0, count, PAGE_SIZE,
&submit);
return tx;
}
static void *ppl_io_pool_alloc(gfp_t gfp_mask, void *pool_data)
{
struct kmem_cache *kc = pool_data;
struct ppl_io_unit *io;
io = kmem_cache_alloc(kc, gfp_mask);
if (!io)
return NULL;
io->header_page = alloc_page(gfp_mask);
if (!io->header_page) {
kmem_cache_free(kc, io);
return NULL;
}
return io;
}
static void ppl_io_pool_free(void *element, void *pool_data)
{
struct kmem_cache *kc = pool_data;
struct ppl_io_unit *io = element;
__free_page(io->header_page);
kmem_cache_free(kc, io);
}
static struct ppl_io_unit *ppl_new_iounit(struct ppl_log *log,
struct stripe_head *sh)
{
struct ppl_conf *ppl_conf = log->ppl_conf;
struct ppl_io_unit *io;
struct ppl_header *pplhdr;
struct page *header_page;
io = mempool_alloc(ppl_conf->io_pool, GFP_NOWAIT);
if (!io)
return NULL;
header_page = io->header_page;
memset(io, 0, sizeof(*io));
io->header_page = header_page;
io->log = log;
INIT_LIST_HEAD(&io->log_sibling);
INIT_LIST_HEAD(&io->stripe_list);
atomic_set(&io->pending_stripes, 0);
bio_init(&io->bio, io->biovec, PPL_IO_INLINE_BVECS);
pplhdr = page_address(io->header_page);
clear_page(pplhdr);
memset(pplhdr->reserved, 0xff, PPL_HDR_RESERVED);
pplhdr->signature = cpu_to_le32(ppl_conf->signature);
io->seq = atomic64_add_return(1, &ppl_conf->seq);
pplhdr->generation = cpu_to_le64(io->seq);
return io;
}
static int ppl_log_stripe(struct ppl_log *log, struct stripe_head *sh)
{
struct ppl_io_unit *io = log->current_io;
struct ppl_header_entry *e = NULL;
struct ppl_header *pplhdr;
int i;
sector_t data_sector = 0;
int data_disks = 0;
unsigned int entry_space = (log->rdev->ppl.size << 9) - PPL_HEADER_SIZE;
struct r5conf *conf = sh->raid_conf;
pr_debug("%s: stripe: %llu\n", __func__, (unsigned long long)sh->sector);
if (io && (io->pp_size == entry_space ||
io->entries_count == PPL_HDR_MAX_ENTRIES)) {
pr_debug("%s: add io_unit blocked by seq: %llu\n",
__func__, io->seq);
io = NULL;
}
if (!io) {
io = ppl_new_iounit(log, sh);
if (!io)
return -ENOMEM;
spin_lock_irq(&log->io_list_lock);
list_add_tail(&io->log_sibling, &log->io_list);
spin_unlock_irq(&log->io_list_lock);
log->current_io = io;
}
for (i = 0; i < sh->disks; i++) {
struct r5dev *dev = &sh->dev[i];
if (i != sh->pd_idx && test_bit(R5_Wantwrite, &dev->flags)) {
if (!data_disks || dev->sector < data_sector)
data_sector = dev->sector;
data_disks++;
}
}
BUG_ON(!data_disks);
pr_debug("%s: seq: %llu data_sector: %llu data_disks: %d\n", __func__,
io->seq, (unsigned long long)data_sector, data_disks);
pplhdr = page_address(io->header_page);
if (io->entries_count > 0) {
struct ppl_header_entry *last =
&pplhdr->entries[io->entries_count - 1];
struct stripe_head *sh_last = list_last_entry(
&io->stripe_list, struct stripe_head, log_list);
u64 data_sector_last = le64_to_cpu(last->data_sector);
u32 data_size_last = le32_to_cpu(last->data_size);
if ((sh->sector == sh_last->sector + STRIPE_SECTORS) &&
(data_sector >> ilog2(conf->chunk_sectors) ==
data_sector_last >> ilog2(conf->chunk_sectors)) &&
((data_sector - data_sector_last) * data_disks ==
data_size_last >> 9))
e = last;
}
if (!e) {
e = &pplhdr->entries[io->entries_count++];
e->data_sector = cpu_to_le64(data_sector);
e->parity_disk = cpu_to_le32(sh->pd_idx);
e->checksum = cpu_to_le32(~0);
}
le32_add_cpu(&e->data_size, data_disks << PAGE_SHIFT);
if (!test_bit(STRIPE_FULL_WRITE, &sh->state)) {
le32_add_cpu(&e->pp_size, PAGE_SIZE);
io->pp_size += PAGE_SIZE;
e->checksum = cpu_to_le32(crc32c_le(le32_to_cpu(e->checksum),
page_address(sh->ppl_page),
PAGE_SIZE));
}
list_add_tail(&sh->log_list, &io->stripe_list);
atomic_inc(&io->pending_stripes);
sh->ppl_io = io;
return 0;
}
int ppl_write_stripe(struct r5conf *conf, struct stripe_head *sh)
{
struct ppl_conf *ppl_conf = conf->log_private;
struct ppl_io_unit *io = sh->ppl_io;
struct ppl_log *log;
if (io || test_bit(STRIPE_SYNCING, &sh->state) || !sh->ppl_page ||
!test_bit(R5_Wantwrite, &sh->dev[sh->pd_idx].flags) ||
!test_bit(R5_Insync, &sh->dev[sh->pd_idx].flags)) {
clear_bit(STRIPE_LOG_TRAPPED, &sh->state);
return -EAGAIN;
}
log = &ppl_conf->child_logs[sh->pd_idx];
mutex_lock(&log->io_mutex);
if (!log->rdev || test_bit(Faulty, &log->rdev->flags)) {
mutex_unlock(&log->io_mutex);
return -EAGAIN;
}
set_bit(STRIPE_LOG_TRAPPED, &sh->state);
clear_bit(STRIPE_DELAYED, &sh->state);
atomic_inc(&sh->count);
if (ppl_log_stripe(log, sh)) {
spin_lock_irq(&ppl_conf->no_mem_stripes_lock);
list_add_tail(&sh->log_list, &ppl_conf->no_mem_stripes);
spin_unlock_irq(&ppl_conf->no_mem_stripes_lock);
}
mutex_unlock(&log->io_mutex);
return 0;
}
static void ppl_log_endio(struct bio *bio)
{
struct ppl_io_unit *io = bio->bi_private;
struct ppl_log *log = io->log;
struct ppl_conf *ppl_conf = log->ppl_conf;
struct stripe_head *sh, *next;
pr_debug("%s: seq: %llu\n", __func__, io->seq);
if (bio->bi_status)
md_error(ppl_conf->mddev, log->rdev);
list_for_each_entry_safe(sh, next, &io->stripe_list, log_list) {
list_del_init(&sh->log_list);
set_bit(STRIPE_HANDLE, &sh->state);
raid5_release_stripe(sh);
}
}
static void ppl_submit_iounit_bio(struct ppl_io_unit *io, struct bio *bio)
{
char b[BDEVNAME_SIZE];
pr_debug("%s: seq: %llu size: %u sector: %llu dev: %s\n",
__func__, io->seq, bio->bi_iter.bi_size,
(unsigned long long)bio->bi_iter.bi_sector,
bdevname(bio->bi_bdev, b));
submit_bio(bio);
}
static void ppl_submit_iounit(struct ppl_io_unit *io)
{
struct ppl_log *log = io->log;
struct ppl_conf *ppl_conf = log->ppl_conf;
struct ppl_header *pplhdr = page_address(io->header_page);
struct bio *bio = &io->bio;
struct stripe_head *sh;
int i;
bio->bi_private = io;
if (!log->rdev || test_bit(Faulty, &log->rdev->flags)) {
ppl_log_endio(bio);
return;
}
for (i = 0; i < io->entries_count; i++) {
struct ppl_header_entry *e = &pplhdr->entries[i];
pr_debug("%s: seq: %llu entry: %d data_sector: %llu pp_size: %u data_size: %u\n",
__func__, io->seq, i, le64_to_cpu(e->data_sector),
le32_to_cpu(e->pp_size), le32_to_cpu(e->data_size));
e->data_sector = cpu_to_le64(le64_to_cpu(e->data_sector) >>
ilog2(ppl_conf->block_size >> 9));
e->checksum = cpu_to_le32(~le32_to_cpu(e->checksum));
}
pplhdr->entries_count = cpu_to_le32(io->entries_count);
pplhdr->checksum = cpu_to_le32(~crc32c_le(~0, pplhdr, PPL_HEADER_SIZE));
bio->bi_end_io = ppl_log_endio;
bio->bi_opf = REQ_OP_WRITE | REQ_FUA;
bio->bi_bdev = log->rdev->bdev;
bio->bi_iter.bi_sector = log->rdev->ppl.sector;
bio_add_page(bio, io->header_page, PAGE_SIZE, 0);
list_for_each_entry(sh, &io->stripe_list, log_list) {
if (test_bit(STRIPE_FULL_WRITE, &sh->state))
continue;
if (!bio_add_page(bio, sh->ppl_page, PAGE_SIZE, 0)) {
struct bio *prev = bio;
bio = bio_alloc_bioset(GFP_NOIO, BIO_MAX_PAGES,
ppl_conf->bs);
bio->bi_opf = prev->bi_opf;
bio->bi_bdev = prev->bi_bdev;
bio->bi_iter.bi_sector = bio_end_sector(prev);
bio_add_page(bio, sh->ppl_page, PAGE_SIZE, 0);
bio_chain(bio, prev);
ppl_submit_iounit_bio(io, prev);
}
}
ppl_submit_iounit_bio(io, bio);
}
static void ppl_submit_current_io(struct ppl_log *log)
{
struct ppl_io_unit *io;
spin_lock_irq(&log->io_list_lock);
io = list_first_entry_or_null(&log->io_list, struct ppl_io_unit,
log_sibling);
if (io && io->submitted)
io = NULL;
spin_unlock_irq(&log->io_list_lock);
if (io) {
io->submitted = true;
if (io == log->current_io)
log->current_io = NULL;
ppl_submit_iounit(io);
}
}
void ppl_write_stripe_run(struct r5conf *conf)
{
struct ppl_conf *ppl_conf = conf->log_private;
struct ppl_log *log;
int i;
for (i = 0; i < ppl_conf->count; i++) {
log = &ppl_conf->child_logs[i];
mutex_lock(&log->io_mutex);
ppl_submit_current_io(log);
mutex_unlock(&log->io_mutex);
}
}
static void ppl_io_unit_finished(struct ppl_io_unit *io)
{
struct ppl_log *log = io->log;
struct ppl_conf *ppl_conf = log->ppl_conf;
unsigned long flags;
pr_debug("%s: seq: %llu\n", __func__, io->seq);
local_irq_save(flags);
spin_lock(&log->io_list_lock);
list_del(&io->log_sibling);
spin_unlock(&log->io_list_lock);
mempool_free(io, ppl_conf->io_pool);
spin_lock(&ppl_conf->no_mem_stripes_lock);
if (!list_empty(&ppl_conf->no_mem_stripes)) {
struct stripe_head *sh;
sh = list_first_entry(&ppl_conf->no_mem_stripes,
struct stripe_head, log_list);
list_del_init(&sh->log_list);
set_bit(STRIPE_HANDLE, &sh->state);
raid5_release_stripe(sh);
}
spin_unlock(&ppl_conf->no_mem_stripes_lock);
local_irq_restore(flags);
}
void ppl_stripe_write_finished(struct stripe_head *sh)
{
struct ppl_io_unit *io;
io = sh->ppl_io;
sh->ppl_io = NULL;
if (io && atomic_dec_and_test(&io->pending_stripes))
ppl_io_unit_finished(io);
}
static void ppl_xor(int size, struct page *page1, struct page *page2)
{
struct async_submit_ctl submit;
struct dma_async_tx_descriptor *tx;
struct page *xor_srcs[] = { page1, page2 };
init_async_submit(&submit, ASYNC_TX_ACK|ASYNC_TX_XOR_DROP_DST,
NULL, NULL, NULL, NULL);
tx = async_xor(page1, xor_srcs, 0, 2, size, &submit);
async_tx_quiesce(&tx);
}
static int ppl_recover_entry(struct ppl_log *log, struct ppl_header_entry *e,
sector_t ppl_sector)
{
struct ppl_conf *ppl_conf = log->ppl_conf;
struct mddev *mddev = ppl_conf->mddev;
struct r5conf *conf = mddev->private;
int block_size = ppl_conf->block_size;
struct page *page1;
struct page *page2;
sector_t r_sector_first;
sector_t r_sector_last;
int strip_sectors;
int data_disks;
int i;
int ret = 0;
char b[BDEVNAME_SIZE];
unsigned int pp_size = le32_to_cpu(e->pp_size);
unsigned int data_size = le32_to_cpu(e->data_size);
page1 = alloc_page(GFP_KERNEL);
page2 = alloc_page(GFP_KERNEL);
if (!page1 || !page2) {
ret = -ENOMEM;
goto out;
}
r_sector_first = le64_to_cpu(e->data_sector) * (block_size >> 9);
if ((pp_size >> 9) < conf->chunk_sectors) {
if (pp_size > 0) {
data_disks = data_size / pp_size;
strip_sectors = pp_size >> 9;
} else {
data_disks = conf->raid_disks - conf->max_degraded;
strip_sectors = (data_size >> 9) / data_disks;
}
r_sector_last = r_sector_first +
(data_disks - 1) * conf->chunk_sectors +
strip_sectors;
} else {
data_disks = conf->raid_disks - conf->max_degraded;
strip_sectors = conf->chunk_sectors;
r_sector_last = r_sector_first + (data_size >> 9);
}
pr_debug("%s: array sector first: %llu last: %llu\n", __func__,
(unsigned long long)r_sector_first,
(unsigned long long)r_sector_last);
if (block_size == 512 &&
(r_sector_first & (STRIPE_SECTORS - 1)) == 0 &&
(r_sector_last & (STRIPE_SECTORS - 1)) == 0)
block_size = STRIPE_SIZE;
for (i = 0; i < strip_sectors; i += (block_size >> 9)) {
bool update_parity = false;
sector_t parity_sector;
struct md_rdev *parity_rdev;
struct stripe_head sh;
int disk;
int indent = 0;
pr_debug("%s:%*s iter %d start\n", __func__, indent, "", i);
indent += 2;
memset(page_address(page1), 0, PAGE_SIZE);
for (disk = 0; disk < data_disks; disk++) {
int dd_idx;
struct md_rdev *rdev;
sector_t sector;
sector_t r_sector = r_sector_first + i +
(disk * conf->chunk_sectors);
pr_debug("%s:%*s data member disk %d start\n",
__func__, indent, "", disk);
indent += 2;
if (r_sector >= r_sector_last) {
pr_debug("%s:%*s array sector %llu doesn't need parity update\n",
__func__, indent, "",
(unsigned long long)r_sector);
indent -= 2;
continue;
}
update_parity = true;
sector = raid5_compute_sector(conf, r_sector, 0,
&dd_idx, NULL);
pr_debug("%s:%*s processing array sector %llu => data member disk %d, sector %llu\n",
__func__, indent, "",
(unsigned long long)r_sector, dd_idx,
(unsigned long long)sector);
rdev = conf->disks[dd_idx].rdev;
if (!rdev) {
pr_debug("%s:%*s data member disk %d missing\n",
__func__, indent, "", dd_idx);
update_parity = false;
break;
}
pr_debug("%s:%*s reading data member disk %s sector %llu\n",
__func__, indent, "", bdevname(rdev->bdev, b),
(unsigned long long)sector);
if (!sync_page_io(rdev, sector, block_size, page2,
REQ_OP_READ, 0, false)) {
md_error(mddev, rdev);
pr_debug("%s:%*s read failed!\n", __func__,
indent, "");
ret = -EIO;
goto out;
}
ppl_xor(block_size, page1, page2);
indent -= 2;
}
if (!update_parity)
continue;
if (pp_size > 0) {
pr_debug("%s:%*s reading pp disk sector %llu\n",
__func__, indent, "",
(unsigned long long)(ppl_sector + i));
if (!sync_page_io(log->rdev,
ppl_sector - log->rdev->data_offset + i,
block_size, page2, REQ_OP_READ, 0,
false)) {
pr_debug("%s:%*s read failed!\n", __func__,
indent, "");
md_error(mddev, log->rdev);
ret = -EIO;
goto out;
}
ppl_xor(block_size, page1, page2);
}
parity_sector = raid5_compute_sector(conf, r_sector_first + i,
0, &disk, &sh);
BUG_ON(sh.pd_idx != le32_to_cpu(e->parity_disk));
parity_rdev = conf->disks[sh.pd_idx].rdev;
BUG_ON(parity_rdev->bdev->bd_dev != log->rdev->bdev->bd_dev);
pr_debug("%s:%*s write parity at sector %llu, disk %s\n",
__func__, indent, "",
(unsigned long long)parity_sector,
bdevname(parity_rdev->bdev, b));
if (!sync_page_io(parity_rdev, parity_sector, block_size,
page1, REQ_OP_WRITE, 0, false)) {
pr_debug("%s:%*s parity write error!\n", __func__,
indent, "");
md_error(mddev, parity_rdev);
ret = -EIO;
goto out;
}
}
out:
if (page1)
__free_page(page1);
if (page2)
__free_page(page2);
return ret;
}
static int ppl_recover(struct ppl_log *log, struct ppl_header *pplhdr)
{
struct ppl_conf *ppl_conf = log->ppl_conf;
struct md_rdev *rdev = log->rdev;
struct mddev *mddev = rdev->mddev;
sector_t ppl_sector = rdev->ppl.sector + (PPL_HEADER_SIZE >> 9);
struct page *page;
int i;
int ret = 0;
page = alloc_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
for (i = 0; i < le32_to_cpu(pplhdr->entries_count); i++) {
struct ppl_header_entry *e = &pplhdr->entries[i];
u32 pp_size = le32_to_cpu(e->pp_size);
sector_t sector = ppl_sector;
int ppl_entry_sectors = pp_size >> 9;
u32 crc, crc_stored;
pr_debug("%s: disk: %d entry: %d ppl_sector: %llu pp_size: %u\n",
__func__, rdev->raid_disk, i,
(unsigned long long)ppl_sector, pp_size);
crc = ~0;
crc_stored = le32_to_cpu(e->checksum);
while (pp_size) {
int s = pp_size > PAGE_SIZE ? PAGE_SIZE : pp_size;
if (!sync_page_io(rdev, sector - rdev->data_offset,
s, page, REQ_OP_READ, 0, false)) {
md_error(mddev, rdev);
ret = -EIO;
goto out;
}
crc = crc32c_le(crc, page_address(page), s);
pp_size -= s;
sector += s >> 9;
}
crc = ~crc;
if (crc != crc_stored) {
pr_debug("%s: ppl entry crc does not match: stored: 0x%x calculated: 0x%x\n",
__func__, crc_stored, crc);
ppl_conf->mismatch_count++;
} else {
ret = ppl_recover_entry(log, e, ppl_sector);
if (ret)
goto out;
ppl_conf->recovered_entries++;
}
ppl_sector += ppl_entry_sectors;
}
ret = blkdev_issue_flush(rdev->bdev, GFP_KERNEL, NULL);
out:
__free_page(page);
return ret;
}
static int ppl_write_empty_header(struct ppl_log *log)
{
struct page *page;
struct ppl_header *pplhdr;
struct md_rdev *rdev = log->rdev;
int ret = 0;
pr_debug("%s: disk: %d ppl_sector: %llu\n", __func__,
rdev->raid_disk, (unsigned long long)rdev->ppl.sector);
page = alloc_page(GFP_NOIO | __GFP_ZERO);
if (!page)
return -ENOMEM;
pplhdr = page_address(page);
memset(pplhdr->reserved, 0xff, PPL_HDR_RESERVED);
pplhdr->signature = cpu_to_le32(log->ppl_conf->signature);
pplhdr->checksum = cpu_to_le32(~crc32c_le(~0, pplhdr, PAGE_SIZE));
if (!sync_page_io(rdev, rdev->ppl.sector - rdev->data_offset,
PPL_HEADER_SIZE, page, REQ_OP_WRITE | REQ_SYNC |
REQ_FUA, 0, false)) {
md_error(rdev->mddev, rdev);
ret = -EIO;
}
__free_page(page);
return ret;
}
static int ppl_load_distributed(struct ppl_log *log)
{
struct ppl_conf *ppl_conf = log->ppl_conf;
struct md_rdev *rdev = log->rdev;
struct mddev *mddev = rdev->mddev;
struct page *page;
struct ppl_header *pplhdr;
u32 crc, crc_stored;
u32 signature;
int ret = 0;
pr_debug("%s: disk: %d\n", __func__, rdev->raid_disk);
page = alloc_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
if (!sync_page_io(rdev, rdev->ppl.sector - rdev->data_offset,
PAGE_SIZE, page, REQ_OP_READ, 0, false)) {
md_error(mddev, rdev);
ret = -EIO;
goto out;
}
pplhdr = page_address(page);
crc_stored = le32_to_cpu(pplhdr->checksum);
pplhdr->checksum = 0;
crc = ~crc32c_le(~0, pplhdr, PAGE_SIZE);
if (crc_stored != crc) {
pr_debug("%s: ppl header crc does not match: stored: 0x%x calculated: 0x%x\n",
__func__, crc_stored, crc);
ppl_conf->mismatch_count++;
goto out;
}
signature = le32_to_cpu(pplhdr->signature);
if (mddev->external) {
ppl_conf->signature = signature;
} else if (ppl_conf->signature != signature) {
pr_debug("%s: ppl header signature does not match: stored: 0x%x configured: 0x%x\n",
__func__, signature, ppl_conf->signature);
ppl_conf->mismatch_count++;
goto out;
}
if (!mddev->pers && mddev->recovery_cp != MaxSector)
ret = ppl_recover(log, pplhdr);
out:
if (!ret && !mddev->pers)
ret = ppl_write_empty_header(log);
__free_page(page);
pr_debug("%s: return: %d mismatch_count: %d recovered_entries: %d\n",
__func__, ret, ppl_conf->mismatch_count,
ppl_conf->recovered_entries);
return ret;
}
static int ppl_load(struct ppl_conf *ppl_conf)
{
int ret = 0;
u32 signature = 0;
bool signature_set = false;
int i;
for (i = 0; i < ppl_conf->count; i++) {
struct ppl_log *log = &ppl_conf->child_logs[i];
if (!log->rdev)
continue;
ret = ppl_load_distributed(log);
if (ret)
break;
if (ppl_conf->mddev->external) {
if (!signature_set) {
signature = ppl_conf->signature;
signature_set = true;
} else if (signature != ppl_conf->signature) {
pr_warn("md/raid:%s: PPL header signature does not match on all member drives\n",
mdname(ppl_conf->mddev));
ret = -EINVAL;
break;
}
}
}
pr_debug("%s: return: %d mismatch_count: %d recovered_entries: %d\n",
__func__, ret, ppl_conf->mismatch_count,
ppl_conf->recovered_entries);
return ret;
}
static void __ppl_exit_log(struct ppl_conf *ppl_conf)
{
clear_bit(MD_HAS_PPL, &ppl_conf->mddev->flags);
kfree(ppl_conf->child_logs);
if (ppl_conf->bs)
bioset_free(ppl_conf->bs);
mempool_destroy(ppl_conf->io_pool);
kmem_cache_destroy(ppl_conf->io_kc);
kfree(ppl_conf);
}
void ppl_exit_log(struct r5conf *conf)
{
struct ppl_conf *ppl_conf = conf->log_private;
if (ppl_conf) {
__ppl_exit_log(ppl_conf);
conf->log_private = NULL;
}
}
static int ppl_validate_rdev(struct md_rdev *rdev)
{
char b[BDEVNAME_SIZE];
int ppl_data_sectors;
int ppl_size_new;
ppl_data_sectors = rdev->ppl.size - (PPL_HEADER_SIZE >> 9);
if (ppl_data_sectors > 0)
ppl_data_sectors = rounddown(ppl_data_sectors, STRIPE_SECTORS);
if (ppl_data_sectors <= 0) {
pr_warn("md/raid:%s: PPL space too small on %s\n",
mdname(rdev->mddev), bdevname(rdev->bdev, b));
return -ENOSPC;
}
ppl_size_new = ppl_data_sectors + (PPL_HEADER_SIZE >> 9);
if ((rdev->ppl.sector < rdev->data_offset &&
rdev->ppl.sector + ppl_size_new > rdev->data_offset) ||
(rdev->ppl.sector >= rdev->data_offset &&
rdev->data_offset + rdev->sectors > rdev->ppl.sector)) {
pr_warn("md/raid:%s: PPL space overlaps with data on %s\n",
mdname(rdev->mddev), bdevname(rdev->bdev, b));
return -EINVAL;
}
if (!rdev->mddev->external &&
((rdev->ppl.offset > 0 && rdev->ppl.offset < (rdev->sb_size >> 9)) ||
(rdev->ppl.offset <= 0 && rdev->ppl.offset + ppl_size_new > 0))) {
pr_warn("md/raid:%s: PPL space overlaps with superblock on %s\n",
mdname(rdev->mddev), bdevname(rdev->bdev, b));
return -EINVAL;
}
rdev->ppl.size = ppl_size_new;
return 0;
}
int ppl_init_log(struct r5conf *conf)
{
struct ppl_conf *ppl_conf;
struct mddev *mddev = conf->mddev;
int ret = 0;
int i;
bool need_cache_flush = false;
pr_debug("md/raid:%s: enabling distributed Partial Parity Log\n",
mdname(conf->mddev));
if (PAGE_SIZE != 4096)
return -EINVAL;
if (mddev->level != 5) {
pr_warn("md/raid:%s PPL is not compatible with raid level %d\n",
mdname(mddev), mddev->level);
return -EINVAL;
}
if (mddev->bitmap_info.file || mddev->bitmap_info.offset) {
pr_warn("md/raid:%s PPL is not compatible with bitmap\n",
mdname(mddev));
return -EINVAL;
}
if (test_bit(MD_HAS_JOURNAL, &mddev->flags)) {
pr_warn("md/raid:%s PPL is not compatible with journal\n",
mdname(mddev));
return -EINVAL;
}
ppl_conf = kzalloc(sizeof(struct ppl_conf), GFP_KERNEL);
if (!ppl_conf)
return -ENOMEM;
ppl_conf->mddev = mddev;
ppl_conf->io_kc = KMEM_CACHE(ppl_io_unit, 0);
if (!ppl_conf->io_kc) {
ret = -ENOMEM;
goto err;
}
ppl_conf->io_pool = mempool_create(conf->raid_disks, ppl_io_pool_alloc,
ppl_io_pool_free, ppl_conf->io_kc);
if (!ppl_conf->io_pool) {
ret = -ENOMEM;
goto err;
}
ppl_conf->bs = bioset_create(conf->raid_disks, 0, BIOSET_NEED_BVECS);
if (!ppl_conf->bs) {
ret = -ENOMEM;
goto err;
}
ppl_conf->count = conf->raid_disks;
ppl_conf->child_logs = kcalloc(ppl_conf->count, sizeof(struct ppl_log),
GFP_KERNEL);
if (!ppl_conf->child_logs) {
ret = -ENOMEM;
goto err;
}
atomic64_set(&ppl_conf->seq, 0);
INIT_LIST_HEAD(&ppl_conf->no_mem_stripes);
spin_lock_init(&ppl_conf->no_mem_stripes_lock);
if (!mddev->external) {
ppl_conf->signature = ~crc32c_le(~0, mddev->uuid, sizeof(mddev->uuid));
ppl_conf->block_size = 512;
} else {
ppl_conf->block_size = queue_logical_block_size(mddev->queue);
}
for (i = 0; i < ppl_conf->count; i++) {
struct ppl_log *log = &ppl_conf->child_logs[i];
struct md_rdev *rdev = conf->disks[i].rdev;
mutex_init(&log->io_mutex);
spin_lock_init(&log->io_list_lock);
INIT_LIST_HEAD(&log->io_list);
log->ppl_conf = ppl_conf;
log->rdev = rdev;
if (rdev) {
struct request_queue *q;
ret = ppl_validate_rdev(rdev);
if (ret)
goto err;
q = bdev_get_queue(rdev->bdev);
if (test_bit(QUEUE_FLAG_WC, &q->queue_flags))
need_cache_flush = true;
}
}
if (need_cache_flush)
pr_warn("md/raid:%s: Volatile write-back cache should be disabled on all member drives when using PPL!\n",
mdname(mddev));
ret = ppl_load(ppl_conf);
if (ret) {
goto err;
} else if (!mddev->pers &&
mddev->recovery_cp == 0 && !mddev->degraded &&
ppl_conf->recovered_entries > 0 &&
ppl_conf->mismatch_count == 0) {
mddev->recovery_cp = MaxSector;
set_bit(MD_SB_CHANGE_CLEAN, &mddev->sb_flags);
} else if (mddev->pers && ppl_conf->mismatch_count > 0) {
ret = -EINVAL;
goto err;
}
conf->log_private = ppl_conf;
set_bit(MD_HAS_PPL, &ppl_conf->mddev->flags);
return 0;
err:
__ppl_exit_log(ppl_conf);
return ret;
}
int ppl_modify_log(struct r5conf *conf, struct md_rdev *rdev, bool add)
{
struct ppl_conf *ppl_conf = conf->log_private;
struct ppl_log *log;
int ret = 0;
char b[BDEVNAME_SIZE];
if (!rdev)
return -EINVAL;
pr_debug("%s: disk: %d operation: %s dev: %s\n",
__func__, rdev->raid_disk, add ? "add" : "remove",
bdevname(rdev->bdev, b));
if (rdev->raid_disk < 0)
return 0;
if (rdev->raid_disk >= ppl_conf->count)
return -ENODEV;
log = &ppl_conf->child_logs[rdev->raid_disk];
mutex_lock(&log->io_mutex);
if (add) {
ret = ppl_validate_rdev(rdev);
if (!ret) {
log->rdev = rdev;
ret = ppl_write_empty_header(log);
}
} else {
log->rdev = NULL;
}
mutex_unlock(&log->io_mutex);
return ret;
}
