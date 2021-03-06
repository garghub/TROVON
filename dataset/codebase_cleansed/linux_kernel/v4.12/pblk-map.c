static void pblk_map_page_data(struct pblk *pblk, unsigned int sentry,
struct ppa_addr *ppa_list,
unsigned long *lun_bitmap,
struct pblk_sec_meta *meta_list,
unsigned int valid_secs)
{
struct pblk_line *line = pblk_line_get_data(pblk);
struct line_emeta *emeta = line->emeta;
struct pblk_w_ctx *w_ctx;
__le64 *lba_list = pblk_line_emeta_to_lbas(emeta);
u64 paddr;
int nr_secs = pblk->min_write_pgs;
int i;
paddr = pblk_alloc_page(pblk, line, nr_secs);
for (i = 0; i < nr_secs; i++, paddr++) {
ppa_list[i] = addr_to_gen_ppa(pblk, paddr, line->id);
if (i < valid_secs) {
kref_get(&line->ref);
w_ctx = pblk_rb_w_ctx(&pblk->rwb, sentry + i);
w_ctx->ppa = ppa_list[i];
meta_list[i].lba = cpu_to_le64(w_ctx->lba);
lba_list[paddr] = cpu_to_le64(w_ctx->lba);
le64_add_cpu(&line->emeta->nr_valid_lbas, 1);
} else {
meta_list[i].lba = cpu_to_le64(ADDR_EMPTY);
lba_list[paddr] = cpu_to_le64(ADDR_EMPTY);
pblk_map_pad_invalidate(pblk, line, paddr);
}
}
if (pblk_line_is_full(line)) {
line = pblk_line_replace_data(pblk);
if (!line)
return;
}
pblk_down_rq(pblk, ppa_list, nr_secs, lun_bitmap);
}
void pblk_map_rq(struct pblk *pblk, struct nvm_rq *rqd, unsigned int sentry,
unsigned long *lun_bitmap, unsigned int valid_secs,
unsigned int off)
{
struct pblk_sec_meta *meta_list = rqd->meta_list;
unsigned int map_secs;
int min = pblk->min_write_pgs;
int i;
for (i = off; i < rqd->nr_ppas; i += min) {
map_secs = (i + min > valid_secs) ? (valid_secs % min) : min;
pblk_map_page_data(pblk, sentry + i, &rqd->ppa_list[i],
lun_bitmap, &meta_list[i], map_secs);
}
}
void pblk_map_erase_rq(struct pblk *pblk, struct nvm_rq *rqd,
unsigned int sentry, unsigned long *lun_bitmap,
unsigned int valid_secs, struct ppa_addr *erase_ppa)
{
struct nvm_tgt_dev *dev = pblk->dev;
struct nvm_geo *geo = &dev->geo;
struct pblk_line *e_line = pblk_line_get_data_next(pblk);
struct pblk_sec_meta *meta_list = rqd->meta_list;
unsigned int map_secs;
int min = pblk->min_write_pgs;
int i, erase_lun;
for (i = 0; i < rqd->nr_ppas; i += min) {
map_secs = (i + min > valid_secs) ? (valid_secs % min) : min;
pblk_map_page_data(pblk, sentry + i, &rqd->ppa_list[i],
lun_bitmap, &meta_list[i], map_secs);
erase_lun = rqd->ppa_list[i].g.lun * geo->nr_chnls +
rqd->ppa_list[i].g.ch;
if (!test_bit(erase_lun, e_line->erase_bitmap)) {
if (down_trylock(&pblk->erase_sem))
continue;
set_bit(erase_lun, e_line->erase_bitmap);
atomic_dec(&e_line->left_eblks);
*erase_ppa = rqd->ppa_list[i];
erase_ppa->g.blk = e_line->id;
return pblk_map_rq(pblk, rqd, sentry, lun_bitmap,
valid_secs, i + min);
}
}
if (unlikely(ppa_empty(*erase_ppa))) {
struct pblk_line_meta *lm = &pblk->lm;
i = find_first_zero_bit(e_line->erase_bitmap, lm->blk_per_line);
if (i == lm->blk_per_line)
return;
set_bit(i, e_line->erase_bitmap);
atomic_dec(&e_line->left_eblks);
*erase_ppa = pblk->luns[i].bppa;
erase_ppa->g.blk = e_line->id;
}
}
