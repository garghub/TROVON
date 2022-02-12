static void marshal_virt_to_resize(struct dk_cxlflash_uvirtual *virt,
struct dk_cxlflash_resize *resize)
{
resize->hdr = virt->hdr;
resize->context_id = virt->context_id;
resize->rsrc_handle = virt->rsrc_handle;
resize->req_size = virt->lun_size;
resize->last_lba = virt->last_lba;
}
static void marshal_clone_to_rele(struct dk_cxlflash_clone *clone,
struct dk_cxlflash_release *release)
{
release->hdr = clone->hdr;
release->context_id = clone->context_id_dst;
}
static int ba_init(struct ba_lun *ba_lun)
{
struct ba_lun_info *bali = NULL;
int lun_size_au = 0, i = 0;
int last_word_underflow = 0;
u64 *lam;
pr_debug("%s: Initializing LUN: lun_id = %llX, "
"ba_lun->lsize = %lX, ba_lun->au_size = %lX\n",
__func__, ba_lun->lun_id, ba_lun->lsize, ba_lun->au_size);
lun_size_au = ba_lun->lsize / ba_lun->au_size;
if (lun_size_au == 0) {
pr_debug("%s: Requested LUN size of 0!\n", __func__);
return -EINVAL;
}
bali = kzalloc(sizeof(struct ba_lun_info), GFP_KERNEL);
if (unlikely(!bali)) {
pr_err("%s: Failed to allocate lun_info for lun_id %llX\n",
__func__, ba_lun->lun_id);
return -ENOMEM;
}
bali->total_aus = lun_size_au;
bali->lun_bmap_size = lun_size_au / BITS_PER_LONG;
if (lun_size_au % BITS_PER_LONG)
bali->lun_bmap_size++;
bali->lun_alloc_map = kzalloc((bali->lun_bmap_size * sizeof(u64)),
GFP_KERNEL);
if (unlikely(!bali->lun_alloc_map)) {
pr_err("%s: Failed to allocate lun allocation map: "
"lun_id = %llX\n", __func__, ba_lun->lun_id);
kfree(bali);
return -ENOMEM;
}
bali->free_aun_cnt = lun_size_au;
for (i = 0; i < bali->lun_bmap_size; i++)
bali->lun_alloc_map[i] = 0xFFFFFFFFFFFFFFFFULL;
last_word_underflow = (bali->lun_bmap_size * BITS_PER_LONG);
last_word_underflow -= bali->free_aun_cnt;
if (last_word_underflow > 0) {
lam = &bali->lun_alloc_map[bali->lun_bmap_size - 1];
for (i = (HIBIT - last_word_underflow + 1);
i < BITS_PER_LONG;
i++)
clear_bit(i, (ulong *)lam);
}
bali->free_high_idx = bali->lun_bmap_size;
bali->aun_clone_map = kzalloc((bali->total_aus * sizeof(u8)),
GFP_KERNEL);
if (unlikely(!bali->aun_clone_map)) {
pr_err("%s: Failed to allocate clone map: lun_id = %llX\n",
__func__, ba_lun->lun_id);
kfree(bali->lun_alloc_map);
kfree(bali);
return -ENOMEM;
}
ba_lun->ba_lun_handle = bali;
pr_debug("%s: Successfully initialized the LUN: "
"lun_id = %llX, bitmap size = %X, free_aun_cnt = %llX\n",
__func__, ba_lun->lun_id, bali->lun_bmap_size,
bali->free_aun_cnt);
return 0;
}
static int find_free_range(u32 low,
u32 high,
struct ba_lun_info *bali, int *bit_word)
{
int i;
u64 bit_pos = -1;
ulong *lam, num_bits;
for (i = low; i < high; i++)
if (bali->lun_alloc_map[i] != 0) {
lam = (ulong *)&bali->lun_alloc_map[i];
num_bits = (sizeof(*lam) * BITS_PER_BYTE);
bit_pos = find_first_bit(lam, num_bits);
pr_devel("%s: Found free bit %llX in LUN "
"map entry %llX at bitmap index = %X\n",
__func__, bit_pos, bali->lun_alloc_map[i],
i);
*bit_word = i;
bali->free_aun_cnt--;
clear_bit(bit_pos, lam);
break;
}
return bit_pos;
}
static u64 ba_alloc(struct ba_lun *ba_lun)
{
u64 bit_pos = -1;
int bit_word = 0;
struct ba_lun_info *bali = NULL;
bali = ba_lun->ba_lun_handle;
pr_debug("%s: Received block allocation request: "
"lun_id = %llX, free_aun_cnt = %llX\n",
__func__, ba_lun->lun_id, bali->free_aun_cnt);
if (bali->free_aun_cnt == 0) {
pr_debug("%s: No space left on LUN: lun_id = %llX\n",
__func__, ba_lun->lun_id);
return -1ULL;
}
bit_pos = find_free_range(bali->free_curr_idx,
bali->free_high_idx, bali, &bit_word);
if (bit_pos == -1) {
bit_pos = find_free_range(bali->free_low_idx,
bali->free_curr_idx,
bali, &bit_word);
if (bit_pos == -1) {
pr_debug("%s: Could not find an allocation unit on LUN:"
" lun_id = %llX\n", __func__, ba_lun->lun_id);
return -1ULL;
}
}
if (bit_pos == HIBIT)
bali->free_curr_idx = bit_word + 1;
else
bali->free_curr_idx = bit_word;
pr_debug("%s: Allocating AU number %llX, on lun_id %llX, "
"free_aun_cnt = %llX\n", __func__,
((bit_word * BITS_PER_LONG) + bit_pos), ba_lun->lun_id,
bali->free_aun_cnt);
return (u64) ((bit_word * BITS_PER_LONG) + bit_pos);
}
static int validate_alloc(struct ba_lun_info *bali, u64 aun)
{
int idx = 0, bit_pos = 0;
idx = aun / BITS_PER_LONG;
bit_pos = aun % BITS_PER_LONG;
if (test_bit(bit_pos, (ulong *)&bali->lun_alloc_map[idx]))
return -1;
return 0;
}
static int ba_free(struct ba_lun *ba_lun, u64 to_free)
{
int idx = 0, bit_pos = 0;
struct ba_lun_info *bali = NULL;
bali = ba_lun->ba_lun_handle;
if (validate_alloc(bali, to_free)) {
pr_debug("%s: The AUN %llX is not allocated on lun_id %llX\n",
__func__, to_free, ba_lun->lun_id);
return -1;
}
pr_debug("%s: Received a request to free AU %llX on lun_id %llX, "
"free_aun_cnt = %llX\n", __func__, to_free, ba_lun->lun_id,
bali->free_aun_cnt);
if (bali->aun_clone_map[to_free] > 0) {
pr_debug("%s: AUN %llX on lun_id %llX has been cloned. Clone "
"count = %X\n", __func__, to_free, ba_lun->lun_id,
bali->aun_clone_map[to_free]);
bali->aun_clone_map[to_free]--;
return 0;
}
idx = to_free / BITS_PER_LONG;
bit_pos = to_free % BITS_PER_LONG;
set_bit(bit_pos, (ulong *)&bali->lun_alloc_map[idx]);
bali->free_aun_cnt++;
if (idx < bali->free_low_idx)
bali->free_low_idx = idx;
else if (idx > bali->free_high_idx)
bali->free_high_idx = idx;
pr_debug("%s: Successfully freed AU at bit_pos %X, bit map index %X on "
"lun_id %llX, free_aun_cnt = %llX\n", __func__, bit_pos, idx,
ba_lun->lun_id, bali->free_aun_cnt);
return 0;
}
static int ba_clone(struct ba_lun *ba_lun, u64 to_clone)
{
struct ba_lun_info *bali = ba_lun->ba_lun_handle;
if (validate_alloc(bali, to_clone)) {
pr_debug("%s: AUN %llX is not allocated on lun_id %llX\n",
__func__, to_clone, ba_lun->lun_id);
return -1;
}
pr_debug("%s: Received a request to clone AUN %llX on lun_id %llX\n",
__func__, to_clone, ba_lun->lun_id);
if (bali->aun_clone_map[to_clone] == MAX_AUN_CLONE_CNT) {
pr_debug("%s: AUN %llX on lun_id %llX hit max clones already\n",
__func__, to_clone, ba_lun->lun_id);
return -1;
}
bali->aun_clone_map[to_clone]++;
return 0;
}
static u64 ba_space(struct ba_lun *ba_lun)
{
struct ba_lun_info *bali = ba_lun->ba_lun_handle;
return bali->free_aun_cnt;
}
void cxlflash_ba_terminate(struct ba_lun *ba_lun)
{
struct ba_lun_info *bali = ba_lun->ba_lun_handle;
if (bali) {
kfree(bali->aun_clone_map);
kfree(bali->lun_alloc_map);
kfree(bali);
ba_lun->ba_lun_handle = NULL;
}
}
static int init_vlun(struct llun_info *lli)
{
int rc = 0;
struct glun_info *gli = lli->parent;
struct blka *blka = &gli->blka;
memset(blka, 0, sizeof(*blka));
mutex_init(&blka->mutex);
blka->ba_lun.lun_id = lli->lun_index;
blka->ba_lun.lsize = gli->max_lba + 1;
blka->ba_lun.lba_size = gli->blk_len;
blka->ba_lun.au_size = MC_CHUNK_SIZE;
blka->nchunk = blka->ba_lun.lsize / MC_CHUNK_SIZE;
rc = ba_init(&blka->ba_lun);
if (unlikely(rc))
pr_debug("%s: cannot init block_alloc, rc=%d\n", __func__, rc);
pr_debug("%s: returning rc=%d lli=%p\n", __func__, rc, lli);
return rc;
}
static int write_same16(struct scsi_device *sdev,
u64 lba,
u32 nblks)
{
u8 *cmd_buf = NULL;
u8 *scsi_cmd = NULL;
u8 *sense_buf = NULL;
int rc = 0;
int result = 0;
int ws_limit = SISLITE_MAX_WS_BLOCKS;
u64 offset = lba;
int left = nblks;
u32 to = sdev->request_queue->rq_timeout;
struct cxlflash_cfg *cfg = (struct cxlflash_cfg *)sdev->host->hostdata;
struct device *dev = &cfg->dev->dev;
cmd_buf = kzalloc(CMD_BUFSIZE, GFP_KERNEL);
scsi_cmd = kzalloc(MAX_COMMAND_SIZE, GFP_KERNEL);
sense_buf = kzalloc(SCSI_SENSE_BUFFERSIZE, GFP_KERNEL);
if (unlikely(!cmd_buf || !scsi_cmd || !sense_buf)) {
rc = -ENOMEM;
goto out;
}
while (left > 0) {
scsi_cmd[0] = WRITE_SAME_16;
put_unaligned_be64(offset, &scsi_cmd[2]);
put_unaligned_be32(ws_limit < left ? ws_limit : left,
&scsi_cmd[10]);
up_read(&cfg->ioctl_rwsem);
result = scsi_execute(sdev, scsi_cmd, DMA_TO_DEVICE, cmd_buf,
CMD_BUFSIZE, sense_buf, to, CMD_RETRIES,
0, NULL);
down_read(&cfg->ioctl_rwsem);
rc = check_state(cfg);
if (rc) {
dev_err(dev, "%s: Failed state! result=0x08%X\n",
__func__, result);
rc = -ENODEV;
goto out;
}
if (result) {
dev_err_ratelimited(dev, "%s: command failed for "
"offset %lld result=0x%x\n",
__func__, offset, result);
rc = -EIO;
goto out;
}
left -= ws_limit;
offset += ws_limit;
}
out:
kfree(cmd_buf);
kfree(scsi_cmd);
kfree(sense_buf);
pr_debug("%s: returning rc=%d\n", __func__, rc);
return rc;
}
static int grow_lxt(struct afu *afu,
struct scsi_device *sdev,
ctx_hndl_t ctxid,
res_hndl_t rhndl,
struct sisl_rht_entry *rhte,
u64 *new_size)
{
struct sisl_lxt_entry *lxt = NULL, *lxt_old = NULL;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct blka *blka = &gli->blka;
u32 av_size;
u32 ngrps, ngrps_old;
u64 aun;
u64 delta = *new_size - rhte->lxt_cnt;
u64 my_new_size;
int i, rc = 0;
mutex_lock(&blka->mutex);
av_size = ba_space(&blka->ba_lun);
if (unlikely(av_size <= 0)) {
pr_debug("%s: ba_space error: av_size %d\n", __func__, av_size);
mutex_unlock(&blka->mutex);
rc = -ENOSPC;
goto out;
}
if (av_size < delta)
delta = av_size;
lxt_old = rhte->lxt_start;
ngrps_old = LXT_NUM_GROUPS(rhte->lxt_cnt);
ngrps = LXT_NUM_GROUPS(rhte->lxt_cnt + delta);
if (ngrps != ngrps_old) {
lxt = kzalloc((sizeof(*lxt) * LXT_GROUP_SIZE * ngrps),
GFP_KERNEL);
if (unlikely(!lxt)) {
mutex_unlock(&blka->mutex);
rc = -ENOMEM;
goto out;
}
memcpy(lxt, lxt_old, (sizeof(*lxt) * rhte->lxt_cnt));
} else
lxt = lxt_old;
my_new_size = rhte->lxt_cnt + delta;
for (i = rhte->lxt_cnt; i < my_new_size; i++) {
aun = ba_alloc(&blka->ba_lun);
if ((aun == -1ULL) || (aun >= blka->nchunk))
pr_debug("%s: ba_alloc error: allocated chunk# %llX, "
"max %llX\n", __func__, aun, blka->nchunk - 1);
lxt[i].rlba_base = ((aun << MC_CHUNK_SHIFT) |
(lli->lun_index << LXT_LUNIDX_SHIFT) |
(RHT_PERM_RW << LXT_PERM_SHIFT |
lli->port_sel));
}
mutex_unlock(&blka->mutex);
dma_wmb();
rhte->lxt_start = lxt;
dma_wmb();
rhte->lxt_cnt = my_new_size;
dma_wmb();
cxlflash_afu_sync(afu, ctxid, rhndl, AFU_LW_SYNC);
if (lxt != lxt_old)
kfree(lxt_old);
*new_size = my_new_size;
out:
pr_debug("%s: returning rc=%d\n", __func__, rc);
return rc;
}
static int shrink_lxt(struct afu *afu,
struct scsi_device *sdev,
res_hndl_t rhndl,
struct sisl_rht_entry *rhte,
struct ctx_info *ctxi,
u64 *new_size)
{
struct sisl_lxt_entry *lxt, *lxt_old;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct blka *blka = &gli->blka;
ctx_hndl_t ctxid = DECODE_CTXID(ctxi->ctxid);
bool needs_ws = ctxi->rht_needs_ws[rhndl];
bool needs_sync = !ctxi->err_recovery_active;
u32 ngrps, ngrps_old;
u64 aun;
u64 delta = rhte->lxt_cnt - *new_size;
u64 my_new_size;
int i, rc = 0;
lxt_old = rhte->lxt_start;
ngrps_old = LXT_NUM_GROUPS(rhte->lxt_cnt);
ngrps = LXT_NUM_GROUPS(rhte->lxt_cnt - delta);
if (ngrps != ngrps_old) {
if (ngrps) {
lxt = kzalloc((sizeof(*lxt) * LXT_GROUP_SIZE * ngrps),
GFP_KERNEL);
if (unlikely(!lxt)) {
rc = -ENOMEM;
goto out;
}
memcpy(lxt, lxt_old,
(sizeof(*lxt) * (rhte->lxt_cnt - delta)));
} else
lxt = NULL;
} else
lxt = lxt_old;
my_new_size = rhte->lxt_cnt - delta;
rhte->lxt_cnt = my_new_size;
dma_wmb();
rhte->lxt_start = lxt;
dma_wmb();
if (needs_sync)
cxlflash_afu_sync(afu, ctxid, rhndl, AFU_HW_SYNC);
if (needs_ws) {
ctxi->unavail = true;
mutex_unlock(&ctxi->mutex);
}
mutex_lock(&blka->mutex);
for (i = delta - 1; i >= 0; i--) {
aun = (lxt_old[my_new_size + i].rlba_base & SISL_ASTATUS_MASK);
aun = (aun >> MC_CHUNK_SHIFT);
if (needs_ws)
write_same16(sdev, aun, MC_CHUNK_SIZE);
ba_free(&blka->ba_lun, aun);
}
mutex_unlock(&blka->mutex);
if (needs_ws) {
mutex_lock(&ctxi->mutex);
ctxi->unavail = false;
}
if (lxt != lxt_old)
kfree(lxt_old);
*new_size = my_new_size;
out:
pr_debug("%s: returning rc=%d\n", __func__, rc);
return rc;
}
int _cxlflash_vlun_resize(struct scsi_device *sdev,
struct ctx_info *ctxi,
struct dk_cxlflash_resize *resize)
{
struct cxlflash_cfg *cfg = (struct cxlflash_cfg *)sdev->host->hostdata;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct afu *afu = cfg->afu;
bool put_ctx = false;
res_hndl_t rhndl = resize->rsrc_handle;
u64 new_size;
u64 nsectors;
u64 ctxid = DECODE_CTXID(resize->context_id),
rctxid = resize->context_id;
struct sisl_rht_entry *rhte;
int rc = 0;
nsectors = (resize->req_size * CXLFLASH_BLOCK_SIZE) / gli->blk_len;
new_size = DIV_ROUND_UP(nsectors, MC_CHUNK_SIZE);
pr_debug("%s: ctxid=%llu rhndl=0x%llx, req_size=0x%llx,"
"new_size=%llx\n", __func__, ctxid, resize->rsrc_handle,
resize->req_size, new_size);
if (unlikely(gli->mode != MODE_VIRTUAL)) {
pr_debug("%s: LUN mode does not support resize! (%d)\n",
__func__, gli->mode);
rc = -EINVAL;
goto out;
}
if (!ctxi) {
ctxi = get_context(cfg, rctxid, lli, CTX_CTRL_ERR_FALLBACK);
if (unlikely(!ctxi)) {
pr_debug("%s: Bad context! (%llu)\n", __func__, ctxid);
rc = -EINVAL;
goto out;
}
put_ctx = true;
}
rhte = get_rhte(ctxi, rhndl, lli);
if (unlikely(!rhte)) {
pr_debug("%s: Bad resource handle! (%u)\n", __func__, rhndl);
rc = -EINVAL;
goto out;
}
if (new_size > rhte->lxt_cnt)
rc = grow_lxt(afu, sdev, ctxid, rhndl, rhte, &new_size);
else if (new_size < rhte->lxt_cnt)
rc = shrink_lxt(afu, sdev, rhndl, rhte, ctxi, &new_size);
resize->hdr.return_flags = 0;
resize->last_lba = (new_size * MC_CHUNK_SIZE * gli->blk_len);
resize->last_lba /= CXLFLASH_BLOCK_SIZE;
resize->last_lba--;
out:
if (put_ctx)
put_context(ctxi);
pr_debug("%s: resized to %lld returning rc=%d\n",
__func__, resize->last_lba, rc);
return rc;
}
int cxlflash_vlun_resize(struct scsi_device *sdev,
struct dk_cxlflash_resize *resize)
{
return _cxlflash_vlun_resize(sdev, NULL, resize);
}
void cxlflash_restore_luntable(struct cxlflash_cfg *cfg)
{
struct llun_info *lli, *temp;
u32 chan;
u32 lind;
struct afu *afu = cfg->afu;
struct sisl_global_map __iomem *agm = &afu->afu_map->global;
mutex_lock(&global.mutex);
list_for_each_entry_safe(lli, temp, &cfg->lluns, list) {
if (!lli->in_table)
continue;
lind = lli->lun_index;
if (lli->port_sel == BOTH_PORTS) {
writeq_be(lli->lun_id[0], &agm->fc_port[0][lind]);
writeq_be(lli->lun_id[1], &agm->fc_port[1][lind]);
pr_debug("%s: Virtual LUN on slot %d id0=%llx, "
"id1=%llx\n", __func__, lind,
lli->lun_id[0], lli->lun_id[1]);
} else {
chan = PORT2CHAN(lli->port_sel);
writeq_be(lli->lun_id[chan], &agm->fc_port[chan][lind]);
pr_debug("%s: Virtual LUN on slot %d chan=%d, "
"id=%llx\n", __func__, lind, chan,
lli->lun_id[chan]);
}
}
mutex_unlock(&global.mutex);
}
static int init_luntable(struct cxlflash_cfg *cfg, struct llun_info *lli)
{
u32 chan;
u32 lind;
int rc = 0;
struct afu *afu = cfg->afu;
struct sisl_global_map __iomem *agm = &afu->afu_map->global;
mutex_lock(&global.mutex);
if (lli->in_table)
goto out;
if (lli->port_sel == BOTH_PORTS) {
if ((cfg->promote_lun_index == cfg->last_lun_index[0]) ||
(cfg->promote_lun_index == cfg->last_lun_index[1])) {
rc = -ENOSPC;
goto out;
}
lind = lli->lun_index = cfg->promote_lun_index;
writeq_be(lli->lun_id[0], &agm->fc_port[0][lind]);
writeq_be(lli->lun_id[1], &agm->fc_port[1][lind]);
cfg->promote_lun_index++;
pr_debug("%s: Virtual LUN on slot %d id0=%llx, id1=%llx\n",
__func__, lind, lli->lun_id[0], lli->lun_id[1]);
} else {
chan = PORT2CHAN(lli->port_sel);
if (cfg->promote_lun_index == cfg->last_lun_index[chan]) {
rc = -ENOSPC;
goto out;
}
lind = lli->lun_index = cfg->last_lun_index[chan];
writeq_be(lli->lun_id[chan], &agm->fc_port[chan][lind]);
cfg->last_lun_index[chan]--;
pr_debug("%s: Virtual LUN on slot %d chan=%d, id=%llx\n",
__func__, lind, chan, lli->lun_id[chan]);
}
lli->in_table = true;
out:
mutex_unlock(&global.mutex);
pr_debug("%s: returning rc=%d\n", __func__, rc);
return rc;
}
int cxlflash_disk_virtual_open(struct scsi_device *sdev, void *arg)
{
struct cxlflash_cfg *cfg = (struct cxlflash_cfg *)sdev->host->hostdata;
struct device *dev = &cfg->dev->dev;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct dk_cxlflash_uvirtual *virt = (struct dk_cxlflash_uvirtual *)arg;
struct dk_cxlflash_resize resize;
u64 ctxid = DECODE_CTXID(virt->context_id),
rctxid = virt->context_id;
u64 lun_size = virt->lun_size;
u64 last_lba = 0;
u64 rsrc_handle = -1;
int rc = 0;
struct ctx_info *ctxi = NULL;
struct sisl_rht_entry *rhte = NULL;
pr_debug("%s: ctxid=%llu ls=0x%llx\n", __func__, ctxid, lun_size);
mutex_lock(&gli->mutex);
if (gli->mode == MODE_NONE) {
rc = init_vlun(lli);
if (rc) {
dev_err(dev, "%s: call to init_vlun failed rc=%d!\n",
__func__, rc);
rc = -ENOMEM;
goto err0;
}
}
rc = cxlflash_lun_attach(gli, MODE_VIRTUAL, true);
if (unlikely(rc)) {
dev_err(dev, "%s: Failed to attach to LUN! (VIRTUAL)\n",
__func__);
goto err0;
}
mutex_unlock(&gli->mutex);
rc = init_luntable(cfg, lli);
if (rc) {
dev_err(dev, "%s: call to init_luntable failed rc=%d!\n",
__func__, rc);
goto err1;
}
ctxi = get_context(cfg, rctxid, lli, 0);
if (unlikely(!ctxi)) {
dev_err(dev, "%s: Bad context! (%llu)\n", __func__, ctxid);
rc = -EINVAL;
goto err1;
}
rhte = rhte_checkout(ctxi, lli);
if (unlikely(!rhte)) {
dev_err(dev, "%s: too many opens for this context\n", __func__);
rc = -EMFILE;
goto err1;
}
rsrc_handle = (rhte - ctxi->rht_start);
rhte->nmask = MC_RHT_NMASK;
rhte->fp = SISL_RHT_FP(0U, ctxi->rht_perms);
marshal_virt_to_resize(virt, &resize);
resize.rsrc_handle = rsrc_handle;
rc = _cxlflash_vlun_resize(sdev, ctxi, &resize);
if (rc) {
dev_err(dev, "%s: resize failed rc %d\n", __func__, rc);
goto err2;
}
last_lba = resize.last_lba;
if (virt->hdr.flags & DK_CXLFLASH_UVIRTUAL_NEED_WRITE_SAME)
ctxi->rht_needs_ws[rsrc_handle] = true;
virt->hdr.return_flags = 0;
virt->last_lba = last_lba;
virt->rsrc_handle = rsrc_handle;
if (lli->port_sel == BOTH_PORTS)
virt->hdr.return_flags |= DK_CXLFLASH_ALL_PORTS_ACTIVE;
out:
if (likely(ctxi))
put_context(ctxi);
pr_debug("%s: returning handle 0x%llx rc=%d llba %lld\n",
__func__, rsrc_handle, rc, last_lba);
return rc;
err2:
rhte_checkin(ctxi, rhte);
err1:
cxlflash_lun_detach(gli);
goto out;
err0:
cxlflash_ba_terminate(&gli->blka.ba_lun);
mutex_unlock(&gli->mutex);
goto out;
}
static int clone_lxt(struct afu *afu,
struct blka *blka,
ctx_hndl_t ctxid,
res_hndl_t rhndl,
struct sisl_rht_entry *rhte,
struct sisl_rht_entry *rhte_src)
{
struct sisl_lxt_entry *lxt;
u32 ngrps;
u64 aun;
int i, j;
ngrps = LXT_NUM_GROUPS(rhte_src->lxt_cnt);
if (ngrps) {
lxt = kzalloc((sizeof(*lxt) * LXT_GROUP_SIZE * ngrps),
GFP_KERNEL);
if (unlikely(!lxt))
return -ENOMEM;
memcpy(lxt, rhte_src->lxt_start,
(sizeof(*lxt) * rhte_src->lxt_cnt));
mutex_lock(&blka->mutex);
for (i = 0; i < rhte_src->lxt_cnt; i++) {
aun = (lxt[i].rlba_base >> MC_CHUNK_SHIFT);
if (ba_clone(&blka->ba_lun, aun) == -1ULL) {
for (j = 0; j < i; j++) {
aun = (lxt[j].rlba_base >>
MC_CHUNK_SHIFT);
ba_free(&blka->ba_lun, aun);
}
mutex_unlock(&blka->mutex);
kfree(lxt);
return -EIO;
}
}
mutex_unlock(&blka->mutex);
} else {
lxt = NULL;
}
dma_wmb();
rhte->lxt_start = lxt;
dma_wmb();
rhte->lxt_cnt = rhte_src->lxt_cnt;
dma_wmb();
cxlflash_afu_sync(afu, ctxid, rhndl, AFU_LW_SYNC);
pr_debug("%s: returning\n", __func__);
return 0;
}
int cxlflash_disk_clone(struct scsi_device *sdev,
struct dk_cxlflash_clone *clone)
{
struct cxlflash_cfg *cfg = (struct cxlflash_cfg *)sdev->host->hostdata;
struct llun_info *lli = sdev->hostdata;
struct glun_info *gli = lli->parent;
struct blka *blka = &gli->blka;
struct afu *afu = cfg->afu;
struct dk_cxlflash_release release = { { 0 }, 0 };
struct ctx_info *ctxi_src = NULL,
*ctxi_dst = NULL;
struct lun_access *lun_access_src, *lun_access_dst;
u32 perms;
u64 ctxid_src = DECODE_CTXID(clone->context_id_src),
ctxid_dst = DECODE_CTXID(clone->context_id_dst),
rctxid_src = clone->context_id_src,
rctxid_dst = clone->context_id_dst;
int adap_fd_src = clone->adap_fd_src;
int i, j;
int rc = 0;
bool found;
LIST_HEAD(sidecar);
pr_debug("%s: ctxid_src=%llu ctxid_dst=%llu adap_fd_src=%d\n",
__func__, ctxid_src, ctxid_dst, adap_fd_src);
if (unlikely(rctxid_src == rctxid_dst)) {
rc = -EINVAL;
goto out;
}
if (unlikely(gli->mode != MODE_VIRTUAL)) {
rc = -EINVAL;
pr_debug("%s: Clone not supported on physical LUNs! (%d)\n",
__func__, gli->mode);
goto out;
}
ctxi_src = get_context(cfg, rctxid_src, lli, CTX_CTRL_CLONE);
ctxi_dst = get_context(cfg, rctxid_dst, lli, 0);
if (unlikely(!ctxi_src || !ctxi_dst)) {
pr_debug("%s: Bad context! (%llu,%llu)\n", __func__,
ctxid_src, ctxid_dst);
rc = -EINVAL;
goto out;
}
if (unlikely(adap_fd_src != ctxi_src->lfd)) {
pr_debug("%s: Invalid source adapter fd! (%d)\n",
__func__, adap_fd_src);
rc = -EINVAL;
goto out;
}
for (i = 0; i < MAX_RHT_PER_CONTEXT; i++)
if (ctxi_dst->rht_start[i].nmask != 0) {
rc = -EINVAL;
goto out;
}
list_for_each_entry(lun_access_src, &ctxi_src->luns, list) {
found = false;
list_for_each_entry(lun_access_dst, &ctxi_dst->luns, list)
if (lun_access_dst->sdev == lun_access_src->sdev) {
found = true;
break;
}
if (!found) {
lun_access_dst = kzalloc(sizeof(*lun_access_dst),
GFP_KERNEL);
if (unlikely(!lun_access_dst)) {
pr_err("%s: Unable to allocate lun_access!\n",
__func__);
rc = -ENOMEM;
goto out;
}
*lun_access_dst = *lun_access_src;
list_add(&lun_access_dst->list, &sidecar);
}
}
if (unlikely(!ctxi_src->rht_out)) {
pr_debug("%s: Nothing to clone!\n", __func__);
goto out_success;
}
perms = ctxi_dst->rht_perms;
for (i = 0; i < MAX_RHT_PER_CONTEXT; i++) {
if (ctxi_src->rht_out == ctxi_dst->rht_out)
break;
if (ctxi_src->rht_start[i].nmask == 0)
continue;
ctxi_dst->rht_out++;
ctxi_dst->rht_start[i].nmask = ctxi_src->rht_start[i].nmask;
ctxi_dst->rht_start[i].fp =
SISL_RHT_FP_CLONE(ctxi_src->rht_start[i].fp, perms);
ctxi_dst->rht_lun[i] = ctxi_src->rht_lun[i];
rc = clone_lxt(afu, blka, ctxid_dst, i,
&ctxi_dst->rht_start[i],
&ctxi_src->rht_start[i]);
if (rc) {
marshal_clone_to_rele(clone, &release);
for (j = 0; j < i; j++) {
release.rsrc_handle = j;
_cxlflash_disk_release(sdev, ctxi_dst,
&release);
}
rhte_checkin(ctxi_dst, &ctxi_dst->rht_start[i]);
goto err;
}
cxlflash_lun_attach(gli, gli->mode, false);
}
out_success:
list_splice(&sidecar, &ctxi_dst->luns);
sys_close(adap_fd_src);
out:
if (ctxi_src)
put_context(ctxi_src);
if (ctxi_dst)
put_context(ctxi_dst);
pr_debug("%s: returning rc=%d\n", __func__, rc);
return rc;
err:
list_for_each_entry_safe(lun_access_src, lun_access_dst, &sidecar, list)
kfree(lun_access_src);
goto out;
}
