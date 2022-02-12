static int iwch_finish_mem_reg(struct iwch_mr *mhp, u32 stag)
{
u32 mmid;
mhp->attr.state = 1;
mhp->attr.stag = stag;
mmid = stag >> 8;
mhp->ibmr.rkey = mhp->ibmr.lkey = stag;
PDBG("%s mmid 0x%x mhp %p\n", __func__, mmid, mhp);
return insert_handle(mhp->rhp, &mhp->rhp->mmidr, mhp, mmid);
}
int iwch_register_mem(struct iwch_dev *rhp, struct iwch_pd *php,
struct iwch_mr *mhp, int shift)
{
u32 stag;
int ret;
if (cxio_register_phys_mem(&rhp->rdev,
&stag, mhp->attr.pdid,
mhp->attr.perms,
mhp->attr.zbva,
mhp->attr.va_fbo,
mhp->attr.len,
shift - 12,
mhp->attr.pbl_size, mhp->attr.pbl_addr))
return -ENOMEM;
ret = iwch_finish_mem_reg(mhp, stag);
if (ret)
cxio_dereg_mem(&rhp->rdev, mhp->attr.stag, mhp->attr.pbl_size,
mhp->attr.pbl_addr);
return ret;
}
int iwch_reregister_mem(struct iwch_dev *rhp, struct iwch_pd *php,
struct iwch_mr *mhp,
int shift,
int npages)
{
u32 stag;
int ret;
if (npages > mhp->attr.pbl_size)
return -ENOMEM;
stag = mhp->attr.stag;
if (cxio_reregister_phys_mem(&rhp->rdev,
&stag, mhp->attr.pdid,
mhp->attr.perms,
mhp->attr.zbva,
mhp->attr.va_fbo,
mhp->attr.len,
shift - 12,
mhp->attr.pbl_size, mhp->attr.pbl_addr))
return -ENOMEM;
ret = iwch_finish_mem_reg(mhp, stag);
if (ret)
cxio_dereg_mem(&rhp->rdev, mhp->attr.stag, mhp->attr.pbl_size,
mhp->attr.pbl_addr);
return ret;
}
int iwch_alloc_pbl(struct iwch_mr *mhp, int npages)
{
mhp->attr.pbl_addr = cxio_hal_pblpool_alloc(&mhp->rhp->rdev,
npages << 3);
if (!mhp->attr.pbl_addr)
return -ENOMEM;
mhp->attr.pbl_size = npages;
return 0;
}
void iwch_free_pbl(struct iwch_mr *mhp)
{
cxio_hal_pblpool_free(&mhp->rhp->rdev, mhp->attr.pbl_addr,
mhp->attr.pbl_size << 3);
}
int iwch_write_pbl(struct iwch_mr *mhp, __be64 *pages, int npages, int offset)
{
return cxio_write_pbl(&mhp->rhp->rdev, pages,
mhp->attr.pbl_addr + (offset << 3), npages);
}
int build_phys_page_list(struct ib_phys_buf *buffer_list,
int num_phys_buf,
u64 *iova_start,
u64 *total_size,
int *npages,
int *shift,
__be64 **page_list)
{
u64 mask;
int i, j, n;
mask = 0;
*total_size = 0;
for (i = 0; i < num_phys_buf; ++i) {
if (i != 0 && buffer_list[i].addr & ~PAGE_MASK)
return -EINVAL;
if (i != 0 && i != num_phys_buf - 1 &&
(buffer_list[i].size & ~PAGE_MASK))
return -EINVAL;
*total_size += buffer_list[i].size;
if (i > 0)
mask |= buffer_list[i].addr;
else
mask |= buffer_list[i].addr & PAGE_MASK;
if (i != num_phys_buf - 1)
mask |= buffer_list[i].addr + buffer_list[i].size;
else
mask |= (buffer_list[i].addr + buffer_list[i].size +
PAGE_SIZE - 1) & PAGE_MASK;
}
if (*total_size > 0xFFFFFFFFULL)
return -ENOMEM;
for (*shift = PAGE_SHIFT; *shift < 27; ++(*shift))
if ((1ULL << *shift) & mask)
break;
buffer_list[0].size += buffer_list[0].addr & ((1ULL << *shift) - 1);
buffer_list[0].addr &= ~0ull << *shift;
*npages = 0;
for (i = 0; i < num_phys_buf; ++i)
*npages += (buffer_list[i].size +
(1ULL << *shift) - 1) >> *shift;
if (!*npages)
return -EINVAL;
*page_list = kmalloc(sizeof(u64) * *npages, GFP_KERNEL);
if (!*page_list)
return -ENOMEM;
n = 0;
for (i = 0; i < num_phys_buf; ++i)
for (j = 0;
j < (buffer_list[i].size + (1ULL << *shift) - 1) >> *shift;
++j)
(*page_list)[n++] = cpu_to_be64(buffer_list[i].addr +
((u64) j << *shift));
PDBG("%s va 0x%llx mask 0x%llx shift %d len %lld pbl_size %d\n",
__func__, (unsigned long long) *iova_start,
(unsigned long long) mask, *shift, (unsigned long long) *total_size,
*npages);
return 0;
}
