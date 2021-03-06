int pblk_write_to_cache(struct pblk *pblk, struct bio *bio, unsigned long flags)
{
struct pblk_w_ctx w_ctx;
sector_t lba = pblk_get_lba(bio);
unsigned int bpos, pos;
int nr_entries = pblk_get_secs(bio);
int i, ret;
retry:
ret = pblk_rb_may_write_user(&pblk->rwb, bio, nr_entries, &bpos);
if (ret == NVM_IO_REQUEUE) {
io_schedule();
goto retry;
}
if (unlikely(!bio_has_data(bio)))
goto out;
w_ctx.flags = flags;
pblk_ppa_set_empty(&w_ctx.ppa);
for (i = 0; i < nr_entries; i++) {
void *data = bio_data(bio);
w_ctx.lba = lba + i;
pos = pblk_rb_wrap_pos(&pblk->rwb, bpos + i);
pblk_rb_write_entry_user(&pblk->rwb, data, w_ctx, pos);
bio_advance(bio, PBLK_EXPOSED_PAGE_SIZE);
}
#ifdef CONFIG_NVM_DEBUG
atomic_long_add(nr_entries, &pblk->inflight_writes);
atomic_long_add(nr_entries, &pblk->req_writes);
#endif
out:
pblk_write_should_kick(pblk);
return ret;
}
int pblk_write_gc_to_cache(struct pblk *pblk, void *data, u64 *lba_list,
unsigned int nr_entries, unsigned int nr_rec_entries,
struct pblk_line *gc_line, unsigned long flags)
{
struct pblk_w_ctx w_ctx;
unsigned int bpos, pos;
int i, valid_entries;
retry:
if (!pblk_rb_may_write_gc(&pblk->rwb, nr_rec_entries, &bpos)) {
io_schedule();
goto retry;
}
w_ctx.flags = flags;
pblk_ppa_set_empty(&w_ctx.ppa);
for (i = 0, valid_entries = 0; i < nr_entries; i++) {
if (lba_list[i] == ADDR_EMPTY)
continue;
w_ctx.lba = lba_list[i];
pos = pblk_rb_wrap_pos(&pblk->rwb, bpos + valid_entries);
pblk_rb_write_entry_gc(&pblk->rwb, data, w_ctx, gc_line, pos);
data += PBLK_EXPOSED_PAGE_SIZE;
valid_entries++;
}
WARN_ONCE(nr_rec_entries != valid_entries,
"pblk: inconsistent GC write\n");
#ifdef CONFIG_NVM_DEBUG
atomic_long_add(valid_entries, &pblk->inflight_writes);
atomic_long_add(valid_entries, &pblk->recov_gc_writes);
#endif
pblk_write_should_kick(pblk);
return NVM_IO_OK;
}
