static inline u32 rcventry2tidinfo(u32 rcventry)
{
u32 pair = rcventry & ~0x1;
return EXP_TID_SET(IDX, pair >> 1) |
EXP_TID_SET(CTRL, 1 << (rcventry - pair));
}
static inline void exp_tid_group_init(struct exp_tid_set *set)
{
INIT_LIST_HEAD(&set->list);
set->count = 0;
}
static inline void tid_group_remove(struct tid_group *grp,
struct exp_tid_set *set)
{
list_del_init(&grp->list);
set->count--;
}
static inline void tid_group_add_tail(struct tid_group *grp,
struct exp_tid_set *set)
{
list_add_tail(&grp->list, &set->list);
set->count++;
}
static inline struct tid_group *tid_group_pop(struct exp_tid_set *set)
{
struct tid_group *grp =
list_first_entry(&set->list, struct tid_group, list);
list_del_init(&grp->list);
set->count--;
return grp;
}
static inline void tid_group_move(struct tid_group *group,
struct exp_tid_set *s1,
struct exp_tid_set *s2)
{
tid_group_remove(group, s1);
tid_group_add_tail(group, s2);
}
int hfi1_user_exp_rcv_init(struct file *fp)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned tidbase;
int i, ret = 0;
spin_lock_init(&fd->tid_lock);
spin_lock_init(&fd->invalid_lock);
fd->tid_rb_root = RB_ROOT;
if (!uctxt->subctxt_cnt || !fd->subctxt) {
exp_tid_group_init(&uctxt->tid_group_list);
exp_tid_group_init(&uctxt->tid_used_list);
exp_tid_group_init(&uctxt->tid_full_list);
tidbase = uctxt->expected_base;
for (i = 0; i < uctxt->expected_count /
dd->rcv_entries.group_size; i++) {
struct tid_group *grp;
grp = kzalloc(sizeof(*grp), GFP_KERNEL);
if (!grp) {
ret = -ENOMEM;
goto done;
}
grp->size = dd->rcv_entries.group_size;
grp->base = tidbase;
tid_group_add_tail(grp, &uctxt->tid_group_list);
tidbase += dd->rcv_entries.group_size;
}
}
fd->entry_to_rb = kcalloc(uctxt->expected_count,
sizeof(struct rb_node *),
GFP_KERNEL);
if (!fd->entry_to_rb)
return -ENOMEM;
if (!HFI1_CAP_IS_USET(TID_UNMAP)) {
fd->invalid_tid_idx = 0;
fd->invalid_tids = kzalloc(uctxt->expected_count *
sizeof(u32), GFP_KERNEL);
if (!fd->invalid_tids) {
ret = -ENOMEM;
goto done;
}
ret = hfi1_mmu_rb_register(&fd->tid_rb_root, &tid_rb_ops);
if (ret) {
dd_dev_info(dd,
"Failed MMU notifier registration %d\n",
ret);
HFI1_CAP_USET(TID_UNMAP);
ret = 0;
}
}
spin_lock(&fd->tid_lock);
if (uctxt->subctxt_cnt && !HFI1_CAP_IS_USET(TID_UNMAP)) {
u16 remainder;
fd->tid_limit = uctxt->expected_count / uctxt->subctxt_cnt;
remainder = uctxt->expected_count % uctxt->subctxt_cnt;
if (remainder && fd->subctxt < remainder)
fd->tid_limit++;
} else {
fd->tid_limit = uctxt->expected_count;
}
spin_unlock(&fd->tid_lock);
done:
return ret;
}
int hfi1_user_exp_rcv_free(struct hfi1_filedata *fd)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct tid_group *grp, *gptr;
if (!test_bit(HFI1_CTXT_SETUP_DONE, &uctxt->event_flags))
return 0;
if (!HFI1_CAP_IS_USET(TID_UNMAP))
hfi1_mmu_rb_unregister(&fd->tid_rb_root);
kfree(fd->invalid_tids);
if (!uctxt->cnt) {
if (!EXP_TID_SET_EMPTY(uctxt->tid_full_list))
unlock_exp_tids(uctxt, &uctxt->tid_full_list,
&fd->tid_rb_root);
if (!EXP_TID_SET_EMPTY(uctxt->tid_used_list))
unlock_exp_tids(uctxt, &uctxt->tid_used_list,
&fd->tid_rb_root);
list_for_each_entry_safe(grp, gptr, &uctxt->tid_group_list.list,
list) {
list_del_init(&grp->list);
kfree(grp);
}
hfi1_clear_tids(uctxt);
}
kfree(fd->entry_to_rb);
return 0;
}
static inline void rcv_array_wc_fill(struct hfi1_devdata *dd, u32 index)
{
if ((dd->flags & HFI1_PRESENT) && dd->rcvarray_wc)
writeq(0, dd->rcvarray_wc + (index * 8));
}
int hfi1_user_exp_rcv_setup(struct file *fp, struct hfi1_tid_info *tinfo)
{
int ret = 0, need_group = 0, pinned;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned npages, ngroups, pageidx = 0, pageset_count, npagesets,
tididx = 0, mapped, mapped_pages = 0;
unsigned long vaddr = tinfo->vaddr;
struct page **pages = NULL;
u32 *tidlist = NULL;
struct tid_pageset *pagesets = NULL;
npages = num_user_pages(vaddr, tinfo->length);
if (!npages)
return -EINVAL;
if (npages > uctxt->expected_count) {
dd_dev_err(dd, "Expected buffer too big\n");
return -EINVAL;
}
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr,
npages * PAGE_SIZE)) {
dd_dev_err(dd, "Fail vaddr %p, %u pages, !access_ok\n",
(void *)vaddr, npages);
return -EFAULT;
}
pagesets = kcalloc(uctxt->expected_count, sizeof(*pagesets),
GFP_KERNEL);
if (!pagesets)
return -ENOMEM;
pages = kcalloc(npages, sizeof(*pages), GFP_KERNEL);
if (!pages) {
ret = -ENOMEM;
goto bail;
}
if (!hfi1_can_pin_pages(dd, fd->tid_n_pinned, npages)) {
ret = -ENOMEM;
goto bail;
}
pinned = hfi1_acquire_user_pages(vaddr, npages, true, pages);
if (pinned <= 0) {
ret = pinned;
goto bail;
}
fd->tid_n_pinned += npages;
npagesets = find_phys_blocks(pages, pinned, pagesets);
spin_lock(&fd->tid_lock);
if (fd->tid_used + npagesets > fd->tid_limit)
pageset_count = fd->tid_limit - fd->tid_used;
else
pageset_count = npagesets;
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
ret = program_rcvarray(fp, vaddr, grp, pagesets,
pageidx, dd->rcv_entries.group_size,
pages, tidlist, &tididx, &mapped);
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
ret = program_rcvarray(fp, vaddr, grp, pagesets,
pageidx, use, pages, tidlist,
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
hfi1_user_exp_rcv_clear(fp, tinfo);
tinfo->tidlist = 0;
ret = -EFAULT;
goto bail;
}
}
if (mapped_pages != pinned) {
hfi1_release_user_pages(current->mm, &pages[mapped_pages],
pinned - mapped_pages,
false);
fd->tid_n_pinned -= pinned - mapped_pages;
}
bail:
kfree(pagesets);
kfree(pages);
kfree(tidlist);
return ret > 0 ? 0 : ret;
}
int hfi1_user_exp_rcv_clear(struct file *fp, struct hfi1_tid_info *tinfo)
{
int ret = 0;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
u32 *tidinfo;
unsigned tididx;
tidinfo = kcalloc(tinfo->tidcnt, sizeof(*tidinfo), GFP_KERNEL);
if (!tidinfo)
return -ENOMEM;
if (copy_from_user(tidinfo, (void __user *)(unsigned long)
tinfo->tidlist, sizeof(tidinfo[0]) *
tinfo->tidcnt)) {
ret = -EFAULT;
goto done;
}
mutex_lock(&uctxt->exp_lock);
for (tididx = 0; tididx < tinfo->tidcnt; tididx++) {
ret = unprogram_rcvarray(fp, tidinfo[tididx], NULL);
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
done:
kfree(tidinfo);
return ret;
}
int hfi1_user_exp_rcv_invalid(struct file *fp, struct hfi1_tid_info *tinfo)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
unsigned long *ev = uctxt->dd->events +
(((uctxt->ctxt - uctxt->dd->first_user_ctxt) *
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
static u32 find_phys_blocks(struct page **pages, unsigned npages,
struct tid_pageset *list)
{
unsigned pagecount, pageidx, setcount = 0, i;
unsigned long pfn, this_pfn;
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
static int program_rcvarray(struct file *fp, unsigned long vaddr,
struct tid_group *grp,
struct tid_pageset *sets,
unsigned start, u16 count, struct page **pages,
u32 *tidlist, unsigned *tididx, unsigned *pmapped)
{
struct hfi1_filedata *fd = fp->private_data;
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
npages = sets[setidx].count;
pageidx = sets[setidx].idx;
ret = set_rcvarray_entry(fp, vaddr + (pageidx * PAGE_SIZE),
rcventry, grp, pages + pageidx,
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
static int set_rcvarray_entry(struct file *fp, unsigned long vaddr,
u32 rcventry, struct tid_group *grp,
struct page **pages, unsigned npages)
{
int ret;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct tid_rb_node *node;
struct hfi1_devdata *dd = uctxt->dd;
struct rb_root *root = &fd->tid_rb_root;
dma_addr_t phys;
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
node->mmu.addr = vaddr;
node->mmu.len = npages * PAGE_SIZE;
node->phys = page_to_phys(pages[0]);
node->npages = npages;
node->rcventry = rcventry;
node->dma_addr = phys;
node->grp = grp;
node->freed = false;
memcpy(node->pages, pages, sizeof(struct page *) * npages);
if (HFI1_CAP_IS_USET(TID_UNMAP))
ret = mmu_rb_insert(root, &node->mmu);
else
ret = hfi1_mmu_rb_insert(root, &node->mmu);
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
static int unprogram_rcvarray(struct file *fp, u32 tidinfo,
struct tid_group **grp)
{
struct hfi1_filedata *fd = fp->private_data;
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
if (HFI1_CAP_IS_USET(TID_UNMAP))
mmu_rb_remove(&fd->tid_rb_root, &node->mmu, NULL);
else
hfi1_mmu_rb_remove(&fd->tid_rb_root, &node->mmu);
if (grp)
*grp = node->grp;
clear_tid_node(fd, fd->subctxt, node);
return 0;
}
static void clear_tid_node(struct hfi1_filedata *fd, u16 subctxt,
struct tid_rb_node *node)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
trace_hfi1_exp_tid_unreg(uctxt->ctxt, fd->subctxt, node->rcventry,
node->npages, node->mmu.addr, node->phys,
node->dma_addr);
hfi1_put_tid(dd, node->rcventry, PT_INVALID, 0, 0);
flush_wc();
pci_unmap_single(dd->pcidev, node->dma_addr, node->mmu.len,
PCI_DMA_FROMDEVICE);
hfi1_release_user_pages(current->mm, node->pages, node->npages, true);
fd->tid_n_pinned -= node->npages;
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
struct exp_tid_set *set, struct rb_root *root)
{
struct tid_group *grp, *ptr;
struct hfi1_filedata *fd = container_of(root, struct hfi1_filedata,
tid_rb_root);
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
if (HFI1_CAP_IS_USET(TID_UNMAP))
mmu_rb_remove(&fd->tid_rb_root,
&node->mmu, NULL);
else
hfi1_mmu_rb_remove(&fd->tid_rb_root,
&node->mmu);
clear_tid_node(fd, -1, node);
}
}
}
}
static int mmu_rb_invalidate(struct rb_root *root, struct mmu_rb_node *mnode)
{
struct hfi1_filedata *fdata =
container_of(root, struct hfi1_filedata, tid_rb_root);
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
(((uctxt->ctxt - uctxt->dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS) + fdata->subctxt);
set_bit(_HFI1_EVENT_TID_MMU_NOTIFY_BIT, ev);
}
fdata->invalid_tid_idx++;
}
spin_unlock(&fdata->invalid_lock);
return 0;
}
static int mmu_rb_insert(struct rb_root *root, struct mmu_rb_node *node)
{
struct hfi1_filedata *fdata =
container_of(root, struct hfi1_filedata, tid_rb_root);
struct tid_rb_node *tnode =
container_of(node, struct tid_rb_node, mmu);
u32 base = fdata->uctxt->expected_base;
fdata->entry_to_rb[tnode->rcventry - base] = tnode;
return 0;
}
static void mmu_rb_remove(struct rb_root *root, struct mmu_rb_node *node,
struct mm_struct *mm)
{
struct hfi1_filedata *fdata =
container_of(root, struct hfi1_filedata, tid_rb_root);
struct tid_rb_node *tnode =
container_of(node, struct tid_rb_node, mmu);
u32 base = fdata->uctxt->expected_base;
fdata->entry_to_rb[tnode->rcventry - base] = NULL;
}
