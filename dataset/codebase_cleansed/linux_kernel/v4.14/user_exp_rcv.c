int hfi1_user_exp_rcv_init(struct hfi1_filedata *fd,
struct hfi1_ctxtdata *uctxt)
{
struct hfi1_devdata *dd = uctxt->dd;
int ret = 0;
spin_lock_init(&fd->tid_lock);
spin_lock_init(&fd->invalid_lock);
fd->entry_to_rb = kcalloc(uctxt->expected_count,
sizeof(struct rb_node *),
GFP_KERNEL);
if (!fd->entry_to_rb)
return -ENOMEM;
if (!HFI1_CAP_UGET_MASK(uctxt->flags, TID_UNMAP)) {
fd->invalid_tid_idx = 0;
fd->invalid_tids = kcalloc(uctxt->expected_count,
sizeof(*fd->invalid_tids),
GFP_KERNEL);
if (!fd->invalid_tids) {
kfree(fd->entry_to_rb);
fd->entry_to_rb = NULL;
return -ENOMEM;
}
ret = hfi1_mmu_rb_register(fd, fd->mm, &tid_rb_ops,
dd->pport->hfi1_wq,
&fd->handler);
if (ret) {
dd_dev_info(dd,
"Failed MMU notifier registration %d\n",
ret);
ret = 0;
}
}
spin_lock(&fd->tid_lock);
if (uctxt->subctxt_cnt && fd->handler) {
u16 remainder;
fd->tid_limit = uctxt->expected_count / uctxt->subctxt_cnt;
remainder = uctxt->expected_count % uctxt->subctxt_cnt;
if (remainder && fd->subctxt < remainder)
fd->tid_limit++;
} else {
fd->tid_limit = uctxt->expected_count;
}
spin_unlock(&fd->tid_lock);
return ret;
}
void hfi1_user_exp_rcv_free(struct hfi1_filedata *fd)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
if (fd->handler) {
hfi1_mmu_rb_unregister(fd->handler);
} else {
if (!EXP_TID_SET_EMPTY(uctxt->tid_full_list))
unlock_exp_tids(uctxt, &uctxt->tid_full_list, fd);
if (!EXP_TID_SET_EMPTY(uctxt->tid_used_list))
unlock_exp_tids(uctxt, &uctxt->tid_used_list, fd);
}
kfree(fd->invalid_tids);
fd->invalid_tids = NULL;
kfree(fd->entry_to_rb);
fd->entry_to_rb = NULL;
}
static void unpin_rcv_pages(struct hfi1_filedata *fd,
struct tid_user_buf *tidbuf,
struct tid_rb_node *node,
unsigned int idx,
unsigned int npages,
bool mapped)
{
struct page **pages;
struct hfi1_devdata *dd = fd->uctxt->dd;
if (mapped) {
pci_unmap_single(dd->pcidev, node->dma_addr,
node->mmu.len, PCI_DMA_FROMDEVICE);
pages = &node->pages[idx];
} else {
pages = &tidbuf->pages[idx];
}
hfi1_release_user_pages(fd->mm, pages, npages, mapped);
fd->tid_n_pinned -= npages;
}
static int pin_rcv_pages(struct hfi1_filedata *fd, struct tid_user_buf *tidbuf)
{
int pinned;
unsigned int npages;
unsigned long vaddr = tidbuf->vaddr;
struct page **pages = NULL;
struct hfi1_devdata *dd = fd->uctxt->dd;
npages = num_user_pages(vaddr, tidbuf->length);
if (!npages)
return -EINVAL;
if (npages > fd->uctxt->expected_count) {
dd_dev_err(dd, "Expected buffer too big\n");
return -EINVAL;
}
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr,
npages * PAGE_SIZE)) {
dd_dev_err(dd, "Fail vaddr %p, %u pages, !access_ok\n",
(void *)vaddr, npages);
return -EFAULT;
}
pages = kcalloc(npages, sizeof(*pages), GFP_KERNEL);
if (!pages)
return -ENOMEM;
if (!hfi1_can_pin_pages(dd, fd->mm, fd->tid_n_pinned, npages)) {
kfree(pages);
return -ENOMEM;
}
pinned = hfi1_acquire_user_pages(fd->mm, vaddr, npages, true, pages);
if (pinned <= 0) {
kfree(pages);
return pinned;
}
tidbuf->pages = pages;
tidbuf->npages = npages;
fd->tid_n_pinned += pinned;
return pinned;
}
int hfi1_user_exp_rcv_setup(struct hfi1_filedata *fd,
struct hfi1_tid_info *tinfo)
{
int ret = 0, need_group = 0, pinned;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned int ngroups, pageidx = 0, pageset_count,
tididx = 0, mapped, mapped_pages = 0;
u32 *tidlist = NULL;
struct tid_user_buf *tidbuf;
tidbuf = kzalloc(sizeof(*tidbuf), GFP_KERNEL);
if (!tidbuf)
return -ENOMEM;
tidbuf->vaddr = tinfo->vaddr;
tidbuf->length = tinfo->length;
tidbuf->psets = kcalloc(uctxt->expected_count, sizeof(*tidbuf->psets),
GFP_KERNEL);
if (!tidbuf->psets) {
kfree(tidbuf);
return -ENOMEM;
}
pinned = pin_rcv_pages(fd, tidbuf);
if (pinned <= 0) {
kfree(tidbuf->psets);
kfree(tidbuf);
return pinned;
}
tidbuf->n_psets = find_phys_blocks(tidbuf, pinned);
spin_lock(&fd->tid_lock);
if (fd->tid_used + tidbuf->n_psets > fd->tid_limit)
pageset_count = fd->tid_limit - fd->tid_used;
else
pageset_count = tidbuf->n_psets;
spin_unlock(&fd->tid_lock);
if (!pageset_count)
goto bail;
ngroups = pageset_count / dd->rcv_entries.group_size;
tidlist = kcalloc(pageset_count, sizeof(*tidlist), GFP_KERNEL);
if (!tidlist) {
ret = -ENOMEM;
goto nomem;
}
tididx = 0;
mutex_lock(&uctxt->exp_lock);
while (ngroups && uctxt->tid_group_list.count) {
struct tid_group *grp =
tid_group_pop(&uctxt->tid_group_list);
ret = program_rcvarray(fd, tidbuf, grp,
pageidx, dd->rcv_entries.group_size,
tidlist, &tididx, &mapped);
if (ret <= 0) {
tid_group_add_tail(grp, &uctxt->tid_group_list);
hfi1_cdbg(TID,
"Failed to program RcvArray group %d", ret);
goto unlock;
}
tid_group_add_tail(grp, &uctxt->tid_full_list);
ngroups--;
pageidx += ret;
mapped_pages += mapped;
}
while (pageidx < pageset_count) {
struct tid_group *grp, *ptr;
if (!uctxt->tid_used_list.count || need_group) {
if (!uctxt->tid_group_list.count)
goto unlock;
grp = tid_group_pop(&uctxt->tid_group_list);
tid_group_add_tail(grp, &uctxt->tid_used_list);
need_group = 0;
}
list_for_each_entry_safe(grp, ptr, &uctxt->tid_used_list.list,
list) {
unsigned use = min_t(unsigned, pageset_count - pageidx,
grp->size - grp->used);
ret = program_rcvarray(fd, tidbuf, grp,
pageidx, use, tidlist,
&tididx, &mapped);
if (ret < 0) {
hfi1_cdbg(TID,
"Failed to program RcvArray entries %d",
ret);
ret = -EFAULT;
goto unlock;
} else if (ret > 0) {
if (grp->used == grp->size)
tid_group_move(grp,
&uctxt->tid_used_list,
&uctxt->tid_full_list);
pageidx += ret;
mapped_pages += mapped;
need_group = 0;
if (pageidx >= pageset_count)
break;
} else if (WARN_ON(ret == 0)) {
need_group = 1;
}
}
}
unlock:
mutex_unlock(&uctxt->exp_lock);
nomem:
hfi1_cdbg(TID, "total mapped: tidpairs:%u pages:%u (%d)", tididx,
mapped_pages, ret);
if (tididx) {
spin_lock(&fd->tid_lock);
fd->tid_used += tididx;
spin_unlock(&fd->tid_lock);
tinfo->tidcnt = tididx;
tinfo->length = mapped_pages * PAGE_SIZE;
if (copy_to_user((void __user *)(unsigned long)tinfo->tidlist,
tidlist, sizeof(tidlist[0]) * tididx)) {
tinfo->tidlist = (unsigned long)&tidlist;
hfi1_user_exp_rcv_clear(fd, tinfo);
tinfo->tidlist = 0;
ret = -EFAULT;
goto bail;
}
}
if (mapped_pages != pinned)
unpin_rcv_pages(fd, tidbuf, NULL, mapped_pages,
(pinned - mapped_pages), false);
bail:
kfree(tidbuf->psets);
kfree(tidlist);
kfree(tidbuf->pages);
kfree(tidbuf);
return ret > 0 ? 0 : ret;
}
int hfi1_user_exp_rcv_clear(struct hfi1_filedata *fd,
struct hfi1_tid_info *tinfo)
{
int ret = 0;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
u32 *tidinfo;
unsigned tididx;
if (unlikely(tinfo->tidcnt > fd->tid_used))
return -EINVAL;
tidinfo = memdup_user((void __user *)(unsigned long)tinfo->tidlist,
sizeof(tidinfo[0]) * tinfo->tidcnt);
if (IS_ERR(tidinfo))
return PTR_ERR(tidinfo);
mutex_lock(&uctxt->exp_lock);
for (tididx = 0; tididx < tinfo->tidcnt; tididx++) {
ret = unprogram_rcvarray(fd, tidinfo[tididx], NULL);
if (ret) {
hfi1_cdbg(TID, "Failed to unprogram rcv array %d",
ret);
break;
}
}
spin_lock(&fd->tid_lock);
fd->tid_used -= tididx;
spin_unlock(&fd->tid_lock);
tinfo->tidcnt = tididx;
mutex_unlock(&uctxt->exp_lock);
kfree(tidinfo);
return ret;
}
int hfi1_user_exp_rcv_invalid(struct hfi1_filedata *fd,
struct hfi1_tid_info *tinfo)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
unsigned long *ev = uctxt->dd->events +
(((uctxt->ctxt - uctxt->dd->first_dyn_alloc_ctxt) *
HFI1_MAX_SHARED_CTXTS) + fd->subctxt);
u32 *array;
int ret = 0;
if (!fd->invalid_tids)
return -EINVAL;
array = kcalloc(uctxt->expected_count, sizeof(*array), GFP_KERNEL);
if (!array)
return -EFAULT;
spin_lock(&fd->invalid_lock);
if (fd->invalid_tid_idx) {
memcpy(array, fd->invalid_tids, sizeof(*array) *
fd->invalid_tid_idx);
memset(fd->invalid_tids, 0, sizeof(*fd->invalid_tids) *
fd->invalid_tid_idx);
tinfo->tidcnt = fd->invalid_tid_idx;
fd->invalid_tid_idx = 0;
clear_bit(_HFI1_EVENT_TID_MMU_NOTIFY_BIT, ev);
} else {
tinfo->tidcnt = 0;
}
spin_unlock(&fd->invalid_lock);
if (tinfo->tidcnt) {
if (copy_to_user((void __user *)tinfo->tidlist,
array, sizeof(*array) * tinfo->tidcnt))
ret = -EFAULT;
}
kfree(array);
return ret;
}
static u32 find_phys_blocks(struct tid_user_buf *tidbuf, unsigned int npages)
{
unsigned pagecount, pageidx, setcount = 0, i;
unsigned long pfn, this_pfn;
struct page **pages = tidbuf->pages;
struct tid_pageset *list = tidbuf->psets;
if (!npages)
return 0;
pfn = page_to_pfn(pages[0]);
for (pageidx = 0, pagecount = 1, i = 1; i <= npages; i++) {
this_pfn = i < npages ? page_to_pfn(pages[i]) : 0;
if (this_pfn != ++pfn) {
while (pagecount) {
int maxpages = pagecount;
u32 bufsize = pagecount * PAGE_SIZE;
if (bufsize > MAX_EXPECTED_BUFFER)
maxpages =
MAX_EXPECTED_BUFFER >>
PAGE_SHIFT;
else if (!is_power_of_2(bufsize))
maxpages =
rounddown_pow_of_two(bufsize) >>
PAGE_SHIFT;
list[setcount].idx = pageidx;
list[setcount].count = maxpages;
pagecount -= maxpages;
pageidx += maxpages;
setcount++;
}
pageidx = i;
pagecount = 1;
pfn = this_pfn;
} else {
pagecount++;
}
}
return setcount;
}
static int program_rcvarray(struct hfi1_filedata *fd, struct tid_user_buf *tbuf,
struct tid_group *grp,
unsigned int start, u16 count,
u32 *tidlist, unsigned int *tididx,
unsigned int *pmapped)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
u16 idx;
u32 tidinfo = 0, rcventry, useidx = 0;
int mapped = 0;
if (count > grp->size)
return -EINVAL;
for (idx = 0; idx < grp->size; idx++) {
if (!(grp->map & (1 << idx))) {
useidx = idx;
break;
}
rcv_array_wc_fill(dd, grp->base + idx);
}
idx = 0;
while (idx < count) {
u16 npages, pageidx, setidx = start + idx;
int ret = 0;
if (useidx >= grp->size) {
break;
} else if (grp->map & (1 << useidx)) {
rcv_array_wc_fill(dd, grp->base + useidx);
useidx++;
continue;
}
rcventry = grp->base + useidx;
npages = tbuf->psets[setidx].count;
pageidx = tbuf->psets[setidx].idx;
ret = set_rcvarray_entry(fd, tbuf,
rcventry, grp, pageidx,
npages);
if (ret)
return ret;
mapped += npages;
tidinfo = rcventry2tidinfo(rcventry - uctxt->expected_base) |
EXP_TID_SET(LEN, npages);
tidlist[(*tididx)++] = tidinfo;
grp->used++;
grp->map |= 1 << useidx++;
idx++;
}
for (; useidx < grp->size; useidx++)
rcv_array_wc_fill(dd, grp->base + useidx);
*pmapped = mapped;
return idx;
}
static int set_rcvarray_entry(struct hfi1_filedata *fd,
struct tid_user_buf *tbuf,
u32 rcventry, struct tid_group *grp,
u16 pageidx, unsigned int npages)
{
int ret;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct tid_rb_node *node;
struct hfi1_devdata *dd = uctxt->dd;
dma_addr_t phys;
struct page **pages = tbuf->pages + pageidx;
node = kzalloc(sizeof(*node) + (sizeof(struct page *) * npages),
GFP_KERNEL);
if (!node)
return -ENOMEM;
phys = pci_map_single(dd->pcidev,
__va(page_to_phys(pages[0])),
npages * PAGE_SIZE, PCI_DMA_FROMDEVICE);
if (dma_mapping_error(&dd->pcidev->dev, phys)) {
dd_dev_err(dd, "Failed to DMA map Exp Rcv pages 0x%llx\n",
phys);
kfree(node);
return -EFAULT;
}
node->mmu.addr = tbuf->vaddr + (pageidx * PAGE_SIZE);
node->mmu.len = npages * PAGE_SIZE;
node->phys = page_to_phys(pages[0]);
node->npages = npages;
node->rcventry = rcventry;
node->dma_addr = phys;
node->grp = grp;
node->freed = false;
memcpy(node->pages, pages, sizeof(struct page *) * npages);
if (!fd->handler)
ret = tid_rb_insert(fd, &node->mmu);
else
ret = hfi1_mmu_rb_insert(fd->handler, &node->mmu);
if (ret) {
hfi1_cdbg(TID, "Failed to insert RB node %u 0x%lx, 0x%lx %d",
node->rcventry, node->mmu.addr, node->phys, ret);
pci_unmap_single(dd->pcidev, phys, npages * PAGE_SIZE,
PCI_DMA_FROMDEVICE);
kfree(node);
return -EFAULT;
}
hfi1_put_tid(dd, rcventry, PT_EXPECTED, phys, ilog2(npages) + 1);
trace_hfi1_exp_tid_reg(uctxt->ctxt, fd->subctxt, rcventry, npages,
node->mmu.addr, node->phys, phys);
return 0;
}
static int unprogram_rcvarray(struct hfi1_filedata *fd, u32 tidinfo,
struct tid_group **grp)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
struct tid_rb_node *node;
u8 tidctrl = EXP_TID_GET(tidinfo, CTRL);
u32 tididx = EXP_TID_GET(tidinfo, IDX) << 1, rcventry;
if (tididx >= uctxt->expected_count) {
dd_dev_err(dd, "Invalid RcvArray entry (%u) index for ctxt %u\n",
tididx, uctxt->ctxt);
return -EINVAL;
}
if (tidctrl == 0x3)
return -EINVAL;
rcventry = tididx + (tidctrl - 1);
node = fd->entry_to_rb[rcventry];
if (!node || node->rcventry != (uctxt->expected_base + rcventry))
return -EBADF;
if (grp)
*grp = node->grp;
if (!fd->handler)
cacheless_tid_rb_remove(fd, node);
else
hfi1_mmu_rb_remove(fd->handler, &node->mmu);
return 0;
}
static void clear_tid_node(struct hfi1_filedata *fd, struct tid_rb_node *node)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
trace_hfi1_exp_tid_unreg(uctxt->ctxt, fd->subctxt, node->rcventry,
node->npages, node->mmu.addr, node->phys,
node->dma_addr);
hfi1_put_tid(dd, node->rcventry, PT_INVALID_FLUSH, 0, 0);
unpin_rcv_pages(fd, NULL, node, 0, node->npages, true);
node->grp->used--;
node->grp->map &= ~(1 << (node->rcventry - node->grp->base));
if (node->grp->used == node->grp->size - 1)
tid_group_move(node->grp, &uctxt->tid_full_list,
&uctxt->tid_used_list);
else if (!node->grp->used)
tid_group_move(node->grp, &uctxt->tid_used_list,
&uctxt->tid_group_list);
kfree(node);
}
static void unlock_exp_tids(struct hfi1_ctxtdata *uctxt,
struct exp_tid_set *set,
struct hfi1_filedata *fd)
{
struct tid_group *grp, *ptr;
int i;
list_for_each_entry_safe(grp, ptr, &set->list, list) {
list_del_init(&grp->list);
for (i = 0; i < grp->size; i++) {
if (grp->map & (1 << i)) {
u16 rcventry = grp->base + i;
struct tid_rb_node *node;
node = fd->entry_to_rb[rcventry -
uctxt->expected_base];
if (!node || node->rcventry != rcventry)
continue;
cacheless_tid_rb_remove(fd, node);
}
}
}
}
static int tid_rb_invalidate(void *arg, struct mmu_rb_node *mnode)
{
struct hfi1_filedata *fdata = arg;
struct hfi1_ctxtdata *uctxt = fdata->uctxt;
struct tid_rb_node *node =
container_of(mnode, struct tid_rb_node, mmu);
if (node->freed)
return 0;
trace_hfi1_exp_tid_inval(uctxt->ctxt, fdata->subctxt, node->mmu.addr,
node->rcventry, node->npages, node->dma_addr);
node->freed = true;
spin_lock(&fdata->invalid_lock);
if (fdata->invalid_tid_idx < uctxt->expected_count) {
fdata->invalid_tids[fdata->invalid_tid_idx] =
rcventry2tidinfo(node->rcventry - uctxt->expected_base);
fdata->invalid_tids[fdata->invalid_tid_idx] |=
EXP_TID_SET(LEN, node->npages);
if (!fdata->invalid_tid_idx) {
unsigned long *ev;
ev = uctxt->dd->events +
(((uctxt->ctxt - uctxt->dd->first_dyn_alloc_ctxt) *
HFI1_MAX_SHARED_CTXTS) + fdata->subctxt);
set_bit(_HFI1_EVENT_TID_MMU_NOTIFY_BIT, ev);
}
fdata->invalid_tid_idx++;
}
spin_unlock(&fdata->invalid_lock);
return 0;
}
static int tid_rb_insert(void *arg, struct mmu_rb_node *node)
{
struct hfi1_filedata *fdata = arg;
struct tid_rb_node *tnode =
container_of(node, struct tid_rb_node, mmu);
u32 base = fdata->uctxt->expected_base;
fdata->entry_to_rb[tnode->rcventry - base] = tnode;
return 0;
}
static void cacheless_tid_rb_remove(struct hfi1_filedata *fdata,
struct tid_rb_node *tnode)
{
u32 base = fdata->uctxt->expected_base;
fdata->entry_to_rb[tnode->rcventry - base] = NULL;
clear_tid_node(fdata, tnode);
}
static void tid_rb_remove(void *arg, struct mmu_rb_node *node)
{
struct hfi1_filedata *fdata = arg;
struct tid_rb_node *tnode =
container_of(node, struct tid_rb_node, mmu);
cacheless_tid_rb_remove(fdata, tnode);
}
