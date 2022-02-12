static void gennvm_blocks_free(struct nvm_dev *dev)
{
struct gen_nvm *gn = dev->mp;
struct gen_lun *lun;
int i;
gennvm_for_each_lun(gn, lun, i) {
if (!lun->vlun.blocks)
break;
vfree(lun->vlun.blocks);
}
}
static void gennvm_luns_free(struct nvm_dev *dev)
{
struct gen_nvm *gn = dev->mp;
kfree(gn->luns);
}
static int gennvm_luns_init(struct nvm_dev *dev, struct gen_nvm *gn)
{
struct gen_lun *lun;
int i;
gn->luns = kcalloc(dev->nr_luns, sizeof(struct gen_lun), GFP_KERNEL);
if (!gn->luns)
return -ENOMEM;
gennvm_for_each_lun(gn, lun, i) {
spin_lock_init(&lun->vlun.lock);
INIT_LIST_HEAD(&lun->free_list);
INIT_LIST_HEAD(&lun->used_list);
INIT_LIST_HEAD(&lun->bb_list);
lun->reserved_blocks = 2;
lun->vlun.id = i;
lun->vlun.lun_id = i % dev->luns_per_chnl;
lun->vlun.chnl_id = i / dev->luns_per_chnl;
lun->vlun.nr_free_blocks = dev->blks_per_lun;
lun->vlun.nr_open_blocks = 0;
lun->vlun.nr_closed_blocks = 0;
lun->vlun.nr_bad_blocks = 0;
}
return 0;
}
static int gennvm_block_bb(struct ppa_addr ppa, int nr_blocks, u8 *blks,
void *private)
{
struct gen_nvm *gn = private;
struct nvm_dev *dev = gn->dev;
struct gen_lun *lun;
struct nvm_block *blk;
int i;
lun = &gn->luns[(dev->luns_per_chnl * ppa.g.ch) + ppa.g.lun];
for (i = 0; i < nr_blocks; i++) {
if (blks[i] == 0)
continue;
blk = &lun->vlun.blocks[i];
if (!blk) {
pr_err("gennvm: BB data is out of bounds.\n");
return -EINVAL;
}
list_move_tail(&blk->list, &lun->bb_list);
lun->vlun.nr_bad_blocks++;
lun->vlun.nr_free_blocks--;
}
return 0;
}
static int gennvm_block_map(u64 slba, u32 nlb, __le64 *entries, void *private)
{
struct nvm_dev *dev = private;
struct gen_nvm *gn = dev->mp;
sector_t max_pages = dev->total_pages * (dev->sec_size >> 9);
u64 elba = slba + nlb;
struct gen_lun *lun;
struct nvm_block *blk;
u64 i;
int lun_id;
if (unlikely(elba > dev->total_pages)) {
pr_err("gennvm: L2P data from device is out of bounds!\n");
return -EINVAL;
}
for (i = 0; i < nlb; i++) {
u64 pba = le64_to_cpu(entries[i]);
if (unlikely(pba >= max_pages && pba != U64_MAX)) {
pr_err("gennvm: L2P data entry is out of bounds!\n");
return -EINVAL;
}
if (!pba)
continue;
lun_id = div_u64(pba, dev->sec_per_lun);
lun = &gn->luns[lun_id];
pba = pba - (dev->sec_per_lun * lun_id);
blk = &lun->vlun.blocks[div_u64(pba, dev->sec_per_blk)];
if (!blk->state) {
list_move_tail(&blk->list, &lun->used_list);
blk->state = NVM_BLK_ST_OPEN;
lun->vlun.nr_free_blocks--;
lun->vlun.nr_open_blocks++;
}
}
return 0;
}
static int gennvm_blocks_init(struct nvm_dev *dev, struct gen_nvm *gn)
{
struct gen_lun *lun;
struct nvm_block *block;
sector_t lun_iter, blk_iter, cur_block_id = 0;
int ret;
gennvm_for_each_lun(gn, lun, lun_iter) {
lun->vlun.blocks = vzalloc(sizeof(struct nvm_block) *
dev->blks_per_lun);
if (!lun->vlun.blocks)
return -ENOMEM;
for (blk_iter = 0; blk_iter < dev->blks_per_lun; blk_iter++) {
block = &lun->vlun.blocks[blk_iter];
INIT_LIST_HEAD(&block->list);
block->lun = &lun->vlun;
block->id = cur_block_id++;
if (unlikely(lun_iter == 0 && blk_iter == 0)) {
lun->vlun.nr_free_blocks--;
continue;
}
list_add_tail(&block->list, &lun->free_list);
}
if (dev->ops->get_bb_tbl) {
struct ppa_addr ppa;
ppa.ppa = 0;
ppa.g.ch = lun->vlun.chnl_id;
ppa.g.lun = lun->vlun.id;
ppa = generic_to_dev_addr(dev, ppa);
ret = dev->ops->get_bb_tbl(dev, ppa,
dev->blks_per_lun,
gennvm_block_bb, gn);
if (ret)
pr_err("gennvm: could not read BB table\n");
}
}
if (dev->ops->get_l2p_tbl) {
ret = dev->ops->get_l2p_tbl(dev, 0, dev->total_pages,
gennvm_block_map, dev);
if (ret) {
pr_err("gennvm: could not read L2P table.\n");
pr_warn("gennvm: default block initialization");
}
}
return 0;
}
static void gennvm_free(struct nvm_dev *dev)
{
gennvm_blocks_free(dev);
gennvm_luns_free(dev);
kfree(dev->mp);
dev->mp = NULL;
}
static int gennvm_register(struct nvm_dev *dev)
{
struct gen_nvm *gn;
int ret;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
gn = kzalloc(sizeof(struct gen_nvm), GFP_KERNEL);
if (!gn)
return -ENOMEM;
gn->dev = dev;
gn->nr_luns = dev->nr_luns;
dev->mp = gn;
ret = gennvm_luns_init(dev, gn);
if (ret) {
pr_err("gennvm: could not initialize luns\n");
goto err;
}
ret = gennvm_blocks_init(dev, gn);
if (ret) {
pr_err("gennvm: could not initialize blocks\n");
goto err;
}
return 1;
err:
gennvm_free(dev);
module_put(THIS_MODULE);
return ret;
}
static void gennvm_unregister(struct nvm_dev *dev)
{
gennvm_free(dev);
module_put(THIS_MODULE);
}
static struct nvm_block *gennvm_get_blk_unlocked(struct nvm_dev *dev,
struct nvm_lun *vlun, unsigned long flags)
{
struct gen_lun *lun = container_of(vlun, struct gen_lun, vlun);
struct nvm_block *blk = NULL;
int is_gc = flags & NVM_IOTYPE_GC;
assert_spin_locked(&vlun->lock);
if (list_empty(&lun->free_list)) {
pr_err_ratelimited("gennvm: lun %u have no free pages available",
lun->vlun.id);
goto out;
}
if (!is_gc && lun->vlun.nr_free_blocks < lun->reserved_blocks)
goto out;
blk = list_first_entry(&lun->free_list, struct nvm_block, list);
list_move_tail(&blk->list, &lun->used_list);
blk->state = NVM_BLK_ST_OPEN;
lun->vlun.nr_free_blocks--;
lun->vlun.nr_open_blocks++;
out:
return blk;
}
static struct nvm_block *gennvm_get_blk(struct nvm_dev *dev,
struct nvm_lun *vlun, unsigned long flags)
{
struct nvm_block *blk;
spin_lock(&vlun->lock);
blk = gennvm_get_blk_unlocked(dev, vlun, flags);
spin_unlock(&vlun->lock);
return blk;
}
static void gennvm_put_blk_unlocked(struct nvm_dev *dev, struct nvm_block *blk)
{
struct nvm_lun *vlun = blk->lun;
struct gen_lun *lun = container_of(vlun, struct gen_lun, vlun);
assert_spin_locked(&vlun->lock);
if (blk->state & NVM_BLK_ST_OPEN) {
list_move_tail(&blk->list, &lun->free_list);
lun->vlun.nr_open_blocks--;
lun->vlun.nr_free_blocks++;
blk->state = NVM_BLK_ST_FREE;
} else if (blk->state & NVM_BLK_ST_CLOSED) {
list_move_tail(&blk->list, &lun->free_list);
lun->vlun.nr_closed_blocks--;
lun->vlun.nr_free_blocks++;
blk->state = NVM_BLK_ST_FREE;
} else if (blk->state & NVM_BLK_ST_BAD) {
list_move_tail(&blk->list, &lun->bb_list);
lun->vlun.nr_bad_blocks++;
blk->state = NVM_BLK_ST_BAD;
} else {
WARN_ON_ONCE(1);
pr_err("gennvm: erroneous block type (%lu -> %u)\n",
blk->id, blk->state);
list_move_tail(&blk->list, &lun->bb_list);
lun->vlun.nr_bad_blocks++;
blk->state = NVM_BLK_ST_BAD;
}
}
static void gennvm_put_blk(struct nvm_dev *dev, struct nvm_block *blk)
{
struct nvm_lun *vlun = blk->lun;
spin_lock(&vlun->lock);
gennvm_put_blk_unlocked(dev, blk);
spin_unlock(&vlun->lock);
}
static void gennvm_blk_set_type(struct nvm_dev *dev, struct ppa_addr *ppa,
int type)
{
struct gen_nvm *gn = dev->mp;
struct gen_lun *lun;
struct nvm_block *blk;
if (unlikely(ppa->g.ch > dev->nr_chnls ||
ppa->g.lun > dev->luns_per_chnl ||
ppa->g.blk > dev->blks_per_lun)) {
WARN_ON_ONCE(1);
pr_err("gennvm: ppa broken (ch: %u > %u lun: %u > %u blk: %u > %u",
ppa->g.ch, dev->nr_chnls,
ppa->g.lun, dev->luns_per_chnl,
ppa->g.blk, dev->blks_per_lun);
return;
}
lun = &gn->luns[ppa->g.lun * ppa->g.ch];
blk = &lun->vlun.blocks[ppa->g.blk];
blk->state = type;
}
static void gennvm_mark_blk_bad(struct nvm_dev *dev, struct nvm_rq *rqd)
{
int i;
if (!dev->ops->set_bb_tbl)
return;
if (dev->ops->set_bb_tbl(dev, rqd, 1))
return;
nvm_addr_to_generic_mode(dev, rqd);
if (rqd->nr_pages > 1)
for (i = 0; i < rqd->nr_pages; i++)
gennvm_blk_set_type(dev, &rqd->ppa_list[i],
NVM_BLK_ST_BAD);
else
gennvm_blk_set_type(dev, &rqd->ppa_addr, NVM_BLK_ST_BAD);
}
static void gennvm_end_io(struct nvm_rq *rqd)
{
struct nvm_tgt_instance *ins = rqd->ins;
switch (rqd->error) {
case NVM_RSP_SUCCESS:
case NVM_RSP_ERR_EMPTYPAGE:
break;
case NVM_RSP_ERR_FAILWRITE:
gennvm_mark_blk_bad(rqd->dev, rqd);
}
ins->tt->end_io(rqd);
}
static int gennvm_submit_io(struct nvm_dev *dev, struct nvm_rq *rqd)
{
if (!dev->ops->submit_io)
return -ENODEV;
nvm_generic_to_addr_mode(dev, rqd);
rqd->dev = dev;
rqd->end_io = gennvm_end_io;
return dev->ops->submit_io(dev, rqd);
}
static int gennvm_erase_blk(struct nvm_dev *dev, struct nvm_block *blk,
unsigned long flags)
{
struct ppa_addr addr = block_to_ppa(dev, blk);
return nvm_erase_ppa(dev, &addr, 1);
}
static struct nvm_lun *gennvm_get_lun(struct nvm_dev *dev, int lunid)
{
struct gen_nvm *gn = dev->mp;
return &gn->luns[lunid].vlun;
}
static void gennvm_lun_info_print(struct nvm_dev *dev)
{
struct gen_nvm *gn = dev->mp;
struct gen_lun *lun;
unsigned int i;
gennvm_for_each_lun(gn, lun, i) {
spin_lock(&lun->vlun.lock);
pr_info("%s: lun%8u\t%u\t%u\t%u\t%u\n",
dev->name, i,
lun->vlun.nr_free_blocks,
lun->vlun.nr_open_blocks,
lun->vlun.nr_closed_blocks,
lun->vlun.nr_bad_blocks);
spin_unlock(&lun->vlun.lock);
}
}
static int __init gennvm_module_init(void)
{
return nvm_register_mgr(&gennvm);
}
static void gennvm_module_exit(void)
{
nvm_unregister_mgr(&gennvm);
}
