static inline struct qib_fmr *to_ifmr(struct ib_fmr *ibfmr)
{
return container_of(ibfmr, struct qib_fmr, ibfmr);
}
static int init_qib_mregion(struct qib_mregion *mr, struct ib_pd *pd,
int count)
{
int m, i = 0;
int rval = 0;
m = (count + QIB_SEGSZ - 1) / QIB_SEGSZ;
for (; i < m; i++) {
mr->map[i] = kzalloc(sizeof *mr->map[0], GFP_KERNEL);
if (!mr->map[i])
goto bail;
}
mr->mapsz = m;
init_completion(&mr->comp);
atomic_set(&mr->refcount, 1);
mr->pd = pd;
mr->max_segs = count;
out:
return rval;
bail:
while (i)
kfree(mr->map[--i]);
rval = -ENOMEM;
goto out;
}
static void deinit_qib_mregion(struct qib_mregion *mr)
{
int i = mr->mapsz;
mr->mapsz = 0;
while (i)
kfree(mr->map[--i]);
}
struct ib_mr *qib_get_dma_mr(struct ib_pd *pd, int acc)
{
struct qib_mr *mr = NULL;
struct ib_mr *ret;
int rval;
if (to_ipd(pd)->user) {
ret = ERR_PTR(-EPERM);
goto bail;
}
mr = kzalloc(sizeof *mr, GFP_KERNEL);
if (!mr) {
ret = ERR_PTR(-ENOMEM);
goto bail;
}
rval = init_qib_mregion(&mr->mr, pd, 0);
if (rval) {
ret = ERR_PTR(rval);
goto bail;
}
rval = qib_alloc_lkey(&mr->mr, 1);
if (rval) {
ret = ERR_PTR(rval);
goto bail_mregion;
}
mr->mr.access_flags = acc;
ret = &mr->ibmr;
done:
return ret;
bail_mregion:
deinit_qib_mregion(&mr->mr);
bail:
kfree(mr);
goto done;
}
static struct qib_mr *alloc_mr(int count, struct ib_pd *pd)
{
struct qib_mr *mr;
int rval = -ENOMEM;
int m;
m = (count + QIB_SEGSZ - 1) / QIB_SEGSZ;
mr = kzalloc(sizeof *mr + m * sizeof mr->mr.map[0], GFP_KERNEL);
if (!mr)
goto bail;
rval = init_qib_mregion(&mr->mr, pd, count);
if (rval)
goto bail;
rval = qib_alloc_lkey(&mr->mr, 0);
if (rval)
goto bail_mregion;
mr->ibmr.lkey = mr->mr.lkey;
mr->ibmr.rkey = mr->mr.lkey;
done:
return mr;
bail_mregion:
deinit_qib_mregion(&mr->mr);
bail:
kfree(mr);
mr = ERR_PTR(rval);
goto done;
}
struct ib_mr *qib_reg_phys_mr(struct ib_pd *pd,
struct ib_phys_buf *buffer_list,
int num_phys_buf, int acc, u64 *iova_start)
{
struct qib_mr *mr;
int n, m, i;
struct ib_mr *ret;
mr = alloc_mr(num_phys_buf, pd);
if (IS_ERR(mr)) {
ret = (struct ib_mr *)mr;
goto bail;
}
mr->mr.user_base = *iova_start;
mr->mr.iova = *iova_start;
mr->mr.access_flags = acc;
m = 0;
n = 0;
for (i = 0; i < num_phys_buf; i++) {
mr->mr.map[m]->segs[n].vaddr = (void *) buffer_list[i].addr;
mr->mr.map[m]->segs[n].length = buffer_list[i].size;
mr->mr.length += buffer_list[i].size;
n++;
if (n == QIB_SEGSZ) {
m++;
n = 0;
}
}
ret = &mr->ibmr;
bail:
return ret;
}
struct ib_mr *qib_reg_user_mr(struct ib_pd *pd, u64 start, u64 length,
u64 virt_addr, int mr_access_flags,
struct ib_udata *udata)
{
struct qib_mr *mr;
struct ib_umem *umem;
struct scatterlist *sg;
int n, m, entry;
struct ib_mr *ret;
if (length == 0) {
ret = ERR_PTR(-EINVAL);
goto bail;
}
umem = ib_umem_get(pd->uobject->context, start, length,
mr_access_flags, 0);
if (IS_ERR(umem))
return (void *) umem;
n = umem->nmap;
mr = alloc_mr(n, pd);
if (IS_ERR(mr)) {
ret = (struct ib_mr *)mr;
ib_umem_release(umem);
goto bail;
}
mr->mr.user_base = start;
mr->mr.iova = virt_addr;
mr->mr.length = length;
mr->mr.offset = umem->offset;
mr->mr.access_flags = mr_access_flags;
mr->umem = umem;
if (is_power_of_2(umem->page_size))
mr->mr.page_shift = ilog2(umem->page_size);
m = 0;
n = 0;
for_each_sg(umem->sg_head.sgl, sg, umem->nmap, entry) {
void *vaddr;
vaddr = page_address(sg_page(sg));
if (!vaddr) {
ret = ERR_PTR(-EINVAL);
goto bail;
}
mr->mr.map[m]->segs[n].vaddr = vaddr;
mr->mr.map[m]->segs[n].length = umem->page_size;
n++;
if (n == QIB_SEGSZ) {
m++;
n = 0;
}
}
ret = &mr->ibmr;
bail:
return ret;
}
int qib_dereg_mr(struct ib_mr *ibmr)
{
struct qib_mr *mr = to_imr(ibmr);
int ret = 0;
unsigned long timeout;
qib_free_lkey(&mr->mr);
qib_put_mr(&mr->mr);
timeout = wait_for_completion_timeout(&mr->mr.comp,
5 * HZ);
if (!timeout) {
qib_get_mr(&mr->mr);
ret = -EBUSY;
goto out;
}
deinit_qib_mregion(&mr->mr);
if (mr->umem)
ib_umem_release(mr->umem);
kfree(mr);
out:
return ret;
}
struct ib_mr *qib_alloc_fast_reg_mr(struct ib_pd *pd, int max_page_list_len)
{
struct qib_mr *mr;
mr = alloc_mr(max_page_list_len, pd);
if (IS_ERR(mr))
return (struct ib_mr *)mr;
return &mr->ibmr;
}
struct ib_fast_reg_page_list *
qib_alloc_fast_reg_page_list(struct ib_device *ibdev, int page_list_len)
{
unsigned size = page_list_len * sizeof(u64);
struct ib_fast_reg_page_list *pl;
if (size > PAGE_SIZE)
return ERR_PTR(-EINVAL);
pl = kzalloc(sizeof *pl, GFP_KERNEL);
if (!pl)
return ERR_PTR(-ENOMEM);
pl->page_list = kzalloc(size, GFP_KERNEL);
if (!pl->page_list)
goto err_free;
return pl;
err_free:
kfree(pl);
return ERR_PTR(-ENOMEM);
}
void qib_free_fast_reg_page_list(struct ib_fast_reg_page_list *pl)
{
kfree(pl->page_list);
kfree(pl);
}
struct ib_fmr *qib_alloc_fmr(struct ib_pd *pd, int mr_access_flags,
struct ib_fmr_attr *fmr_attr)
{
struct qib_fmr *fmr;
int m;
struct ib_fmr *ret;
int rval = -ENOMEM;
m = (fmr_attr->max_pages + QIB_SEGSZ - 1) / QIB_SEGSZ;
fmr = kzalloc(sizeof *fmr + m * sizeof fmr->mr.map[0], GFP_KERNEL);
if (!fmr)
goto bail;
rval = init_qib_mregion(&fmr->mr, pd, fmr_attr->max_pages);
if (rval)
goto bail;
rval = qib_alloc_lkey(&fmr->mr, 0);
if (rval)
goto bail_mregion;
fmr->ibfmr.rkey = fmr->mr.lkey;
fmr->ibfmr.lkey = fmr->mr.lkey;
fmr->mr.access_flags = mr_access_flags;
fmr->mr.max_segs = fmr_attr->max_pages;
fmr->mr.page_shift = fmr_attr->page_shift;
ret = &fmr->ibfmr;
done:
return ret;
bail_mregion:
deinit_qib_mregion(&fmr->mr);
bail:
kfree(fmr);
ret = ERR_PTR(rval);
goto done;
}
int qib_map_phys_fmr(struct ib_fmr *ibfmr, u64 *page_list,
int list_len, u64 iova)
{
struct qib_fmr *fmr = to_ifmr(ibfmr);
struct qib_lkey_table *rkt;
unsigned long flags;
int m, n, i;
u32 ps;
int ret;
i = atomic_read(&fmr->mr.refcount);
if (i > 2)
return -EBUSY;
if (list_len > fmr->mr.max_segs) {
ret = -EINVAL;
goto bail;
}
rkt = &to_idev(ibfmr->device)->lk_table;
spin_lock_irqsave(&rkt->lock, flags);
fmr->mr.user_base = iova;
fmr->mr.iova = iova;
ps = 1 << fmr->mr.page_shift;
fmr->mr.length = list_len * ps;
m = 0;
n = 0;
for (i = 0; i < list_len; i++) {
fmr->mr.map[m]->segs[n].vaddr = (void *) page_list[i];
fmr->mr.map[m]->segs[n].length = ps;
if (++n == QIB_SEGSZ) {
m++;
n = 0;
}
}
spin_unlock_irqrestore(&rkt->lock, flags);
ret = 0;
bail:
return ret;
}
int qib_unmap_fmr(struct list_head *fmr_list)
{
struct qib_fmr *fmr;
struct qib_lkey_table *rkt;
unsigned long flags;
list_for_each_entry(fmr, fmr_list, ibfmr.list) {
rkt = &to_idev(fmr->ibfmr.device)->lk_table;
spin_lock_irqsave(&rkt->lock, flags);
fmr->mr.user_base = 0;
fmr->mr.iova = 0;
fmr->mr.length = 0;
spin_unlock_irqrestore(&rkt->lock, flags);
}
return 0;
}
int qib_dealloc_fmr(struct ib_fmr *ibfmr)
{
struct qib_fmr *fmr = to_ifmr(ibfmr);
int ret = 0;
unsigned long timeout;
qib_free_lkey(&fmr->mr);
qib_put_mr(&fmr->mr);
timeout = wait_for_completion_timeout(&fmr->mr.comp,
5 * HZ);
if (!timeout) {
qib_get_mr(&fmr->mr);
ret = -EBUSY;
goto out;
}
deinit_qib_mregion(&fmr->mr);
kfree(fmr);
out:
return ret;
}
void mr_rcu_callback(struct rcu_head *list)
{
struct qib_mregion *mr = container_of(list, struct qib_mregion, list);
complete(&mr->comp);
}
