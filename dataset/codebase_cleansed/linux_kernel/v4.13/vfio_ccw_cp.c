static int pfn_array_pin(struct pfn_array *pa, struct device *mdev)
{
int i, ret;
if (pa->pa_nr <= 0) {
pa->pa_nr = 0;
return 0;
}
pa->pa_iova_pfn[0] = pa->pa_iova >> PAGE_SHIFT;
for (i = 1; i < pa->pa_nr; i++)
pa->pa_iova_pfn[i] = pa->pa_iova_pfn[i - 1] + 1;
ret = vfio_pin_pages(mdev, pa->pa_iova_pfn, pa->pa_nr,
IOMMU_READ | IOMMU_WRITE, pa->pa_pfn);
if (ret > 0 && ret != pa->pa_nr) {
vfio_unpin_pages(mdev, pa->pa_iova_pfn, ret);
pa->pa_nr = 0;
return 0;
}
return ret;
}
static void pfn_array_unpin_free(struct pfn_array *pa, struct device *mdev)
{
vfio_unpin_pages(mdev, pa->pa_iova_pfn, pa->pa_nr);
pa->pa_nr = 0;
kfree(pa->pa_iova_pfn);
}
static int pfn_array_alloc_pin(struct pfn_array *pa, struct device *mdev,
u64 iova, unsigned int len)
{
int ret = 0;
if (!len || pa->pa_nr)
return -EINVAL;
pa->pa_iova = iova;
pa->pa_nr = ((iova & ~PAGE_MASK) + len + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
if (!pa->pa_nr)
return -EINVAL;
pa->pa_iova_pfn = kcalloc(pa->pa_nr,
sizeof(*pa->pa_iova_pfn) +
sizeof(*pa->pa_pfn),
GFP_KERNEL);
if (unlikely(!pa->pa_iova_pfn))
return -ENOMEM;
pa->pa_pfn = pa->pa_iova_pfn + pa->pa_nr;
ret = pfn_array_pin(pa, mdev);
if (ret > 0)
return ret;
else if (!ret)
ret = -EINVAL;
kfree(pa->pa_iova_pfn);
return ret;
}
static int pfn_array_table_init(struct pfn_array_table *pat, int nr)
{
pat->pat_pa = kcalloc(nr, sizeof(*pat->pat_pa), GFP_KERNEL);
if (unlikely(ZERO_OR_NULL_PTR(pat->pat_pa))) {
pat->pat_nr = 0;
return -ENOMEM;
}
pat->pat_nr = nr;
return 0;
}
static void pfn_array_table_unpin_free(struct pfn_array_table *pat,
struct device *mdev)
{
int i;
for (i = 0; i < pat->pat_nr; i++)
pfn_array_unpin_free(pat->pat_pa + i, mdev);
if (pat->pat_nr) {
kfree(pat->pat_pa);
pat->pat_pa = NULL;
pat->pat_nr = 0;
}
}
static bool pfn_array_table_iova_pinned(struct pfn_array_table *pat,
unsigned long iova)
{
struct pfn_array *pa = pat->pat_pa;
unsigned long iova_pfn = iova >> PAGE_SHIFT;
int i, j;
for (i = 0; i < pat->pat_nr; i++, pa++)
for (j = 0; j < pa->pa_nr; j++)
if (pa->pa_iova_pfn[i] == iova_pfn)
return true;
return false;
}
static inline void pfn_array_table_idal_create_words(
struct pfn_array_table *pat,
unsigned long *idaws)
{
struct pfn_array *pa;
int i, j, k;
k = 0;
for (i = 0; i < pat->pat_nr; i++) {
pa = pat->pat_pa + i;
for (j = 0; j < pa->pa_nr; j++) {
idaws[k] = pa->pa_pfn[j] << PAGE_SHIFT;
if (k == 0)
idaws[k] += pa->pa_iova & (PAGE_SIZE - 1);
k++;
}
}
}
static long copy_from_iova(struct device *mdev,
void *to, u64 iova,
unsigned long n)
{
struct pfn_array pa = {0};
u64 from;
int i, ret;
unsigned long l, m;
ret = pfn_array_alloc_pin(&pa, mdev, iova, n);
if (ret <= 0)
return ret;
l = n;
for (i = 0; i < pa.pa_nr; i++) {
from = pa.pa_pfn[i] << PAGE_SHIFT;
m = PAGE_SIZE;
if (i == 0) {
from += iova & (PAGE_SIZE - 1);
m -= iova & (PAGE_SIZE - 1);
}
m = min(l, m);
memcpy(to + (n - l), (void *)from, m);
l -= m;
if (l == 0)
break;
}
pfn_array_unpin_free(&pa, mdev);
return l;
}
static long copy_ccw_from_iova(struct channel_program *cp,
struct ccw1 *to, u64 iova,
unsigned long len)
{
struct ccw0 ccw0;
struct ccw1 *pccw1;
int ret;
int i;
ret = copy_from_iova(cp->mdev, to, iova, len * sizeof(struct ccw1));
if (ret)
return ret;
if (!cp->orb.cmd.fmt) {
pccw1 = to;
for (i = 0; i < len; i++) {
ccw0 = *(struct ccw0 *)pccw1;
if ((pccw1->cmd_code & 0x0f) == CCW_CMD_TIC) {
pccw1->cmd_code = CCW_CMD_TIC;
pccw1->flags = 0;
pccw1->count = 0;
} else {
pccw1->cmd_code = ccw0.cmd_code;
pccw1->flags = ccw0.flags;
pccw1->count = ccw0.count;
}
pccw1->cda = ccw0.cda;
pccw1++;
}
}
return ret;
}
static struct ccwchain *ccwchain_alloc(struct channel_program *cp, int len)
{
struct ccwchain *chain;
void *data;
size_t size;
size = ((sizeof(*chain) + 7L) & -8L) +
sizeof(*chain->ch_ccw) * len +
sizeof(*chain->ch_pat) * len;
chain = kzalloc(size, GFP_DMA | GFP_KERNEL);
if (!chain)
return NULL;
data = (u8 *)chain + ((sizeof(*chain) + 7L) & -8L);
chain->ch_ccw = (struct ccw1 *)data;
data = (u8 *)(chain->ch_ccw) + sizeof(*chain->ch_ccw) * len;
chain->ch_pat = (struct pfn_array_table *)data;
chain->ch_len = len;
list_add_tail(&chain->next, &cp->ccwchain_list);
return chain;
}
static void ccwchain_free(struct ccwchain *chain)
{
list_del(&chain->next);
kfree(chain);
}
static void ccwchain_cda_free(struct ccwchain *chain, int idx)
{
struct ccw1 *ccw = chain->ch_ccw + idx;
if (!ccw->count)
return;
kfree((void *)(u64)ccw->cda);
}
static void cp_unpin_free(struct channel_program *cp)
{
struct ccwchain *chain, *temp;
int i;
list_for_each_entry_safe(chain, temp, &cp->ccwchain_list, next) {
for (i = 0; i < chain->ch_len; i++) {
pfn_array_table_unpin_free(chain->ch_pat + i,
cp->mdev);
ccwchain_cda_free(chain, i);
}
ccwchain_free(chain);
}
}
static int ccwchain_calc_length(u64 iova, struct channel_program *cp)
{
struct ccw1 *ccw, *p;
int cnt;
p = ccw = kcalloc(CCWCHAIN_LEN_MAX, sizeof(*ccw), GFP_KERNEL);
if (!ccw)
return -ENOMEM;
cnt = copy_ccw_from_iova(cp, ccw, iova, CCWCHAIN_LEN_MAX);
if (cnt) {
kfree(ccw);
return cnt;
}
cnt = 0;
do {
cnt++;
if ((!ccw_is_chain(ccw)) && (!ccw_is_tic(ccw)))
break;
ccw++;
} while (cnt < CCWCHAIN_LEN_MAX + 1);
if (cnt == CCWCHAIN_LEN_MAX + 1)
cnt = -EINVAL;
kfree(p);
return cnt;
}
static int tic_target_chain_exists(struct ccw1 *tic, struct channel_program *cp)
{
struct ccwchain *chain;
u32 ccw_head, ccw_tail;
list_for_each_entry(chain, &cp->ccwchain_list, next) {
ccw_head = chain->ch_iova;
ccw_tail = ccw_head + (chain->ch_len - 1) * sizeof(struct ccw1);
if ((ccw_head <= tic->cda) && (tic->cda <= ccw_tail))
return 1;
}
return 0;
}
static int ccwchain_handle_tic(struct ccw1 *tic, struct channel_program *cp)
{
struct ccwchain *chain;
int len, ret;
if (tic_target_chain_exists(tic, cp))
return 0;
len = ccwchain_calc_length(tic->cda, cp);
if (len < 0)
return len;
chain = ccwchain_alloc(cp, len);
if (!chain)
return -ENOMEM;
chain->ch_iova = tic->cda;
ret = copy_ccw_from_iova(cp, chain->ch_ccw, tic->cda, len);
if (ret) {
ccwchain_free(chain);
return ret;
}
return ccwchain_loop_tic(chain, cp);
}
static int ccwchain_loop_tic(struct ccwchain *chain, struct channel_program *cp)
{
struct ccw1 *tic;
int i, ret;
for (i = 0; i < chain->ch_len; i++) {
tic = chain->ch_ccw + i;
if (!ccw_is_tic(tic))
continue;
ret = ccwchain_handle_tic(tic, cp);
if (ret)
return ret;
}
return 0;
}
static int ccwchain_fetch_tic(struct ccwchain *chain,
int idx,
struct channel_program *cp)
{
struct ccw1 *ccw = chain->ch_ccw + idx;
struct ccwchain *iter;
u32 ccw_head, ccw_tail;
list_for_each_entry(iter, &cp->ccwchain_list, next) {
ccw_head = iter->ch_iova;
ccw_tail = ccw_head + (iter->ch_len - 1) * sizeof(struct ccw1);
if ((ccw_head <= ccw->cda) && (ccw->cda <= ccw_tail)) {
ccw->cda = (__u32) (addr_t) (((char *)iter->ch_ccw) +
(ccw->cda - ccw_head));
return 0;
}
}
return -EFAULT;
}
static int ccwchain_fetch_direct(struct ccwchain *chain,
int idx,
struct channel_program *cp)
{
struct ccw1 *ccw;
struct pfn_array_table *pat;
unsigned long *idaws;
int idaw_nr;
ccw = chain->ch_ccw + idx;
pat = chain->ch_pat + idx;
if (pfn_array_table_init(pat, 1))
return -ENOMEM;
idaw_nr = pfn_array_alloc_pin(pat->pat_pa, cp->mdev,
ccw->cda, ccw->count);
if (idaw_nr < 0)
return idaw_nr;
idaws = kcalloc(idaw_nr, sizeof(*idaws), GFP_DMA | GFP_KERNEL);
if (!idaws) {
pfn_array_table_unpin_free(pat, cp->mdev);
return -ENOMEM;
}
ccw->cda = (__u32) virt_to_phys(idaws);
ccw->flags |= CCW_FLAG_IDA;
pfn_array_table_idal_create_words(pat, idaws);
return 0;
}
static int ccwchain_fetch_idal(struct ccwchain *chain,
int idx,
struct channel_program *cp)
{
struct ccw1 *ccw;
struct pfn_array_table *pat;
unsigned long *idaws;
u64 idaw_iova;
unsigned int idaw_nr, idaw_len;
int i, ret;
ccw = chain->ch_ccw + idx;
ret = copy_from_iova(cp->mdev, &idaw_iova, ccw->cda, sizeof(idaw_iova));
if (ret)
return ret;
idaw_nr = idal_nr_words((void *)(idaw_iova), ccw->count);
idaw_len = idaw_nr * sizeof(*idaws);
pat = chain->ch_pat + idx;
ret = pfn_array_table_init(pat, idaw_nr);
if (ret)
return ret;
idaws = kzalloc(idaw_len, GFP_DMA | GFP_KERNEL);
if (!idaws) {
ret = -ENOMEM;
goto out_unpin;
}
ret = copy_from_iova(cp->mdev, idaws, ccw->cda, idaw_len);
if (ret)
goto out_free_idaws;
ccw->cda = virt_to_phys(idaws);
for (i = 0; i < idaw_nr; i++) {
idaw_iova = *(idaws + i);
if (IS_ERR_VALUE(idaw_iova)) {
ret = -EFAULT;
goto out_free_idaws;
}
ret = pfn_array_alloc_pin(pat->pat_pa + i, cp->mdev,
idaw_iova, 1);
if (ret < 0)
goto out_free_idaws;
}
pfn_array_table_idal_create_words(pat, idaws);
return 0;
out_free_idaws:
kfree(idaws);
out_unpin:
pfn_array_table_unpin_free(pat, cp->mdev);
return ret;
}
static int ccwchain_fetch_one(struct ccwchain *chain,
int idx,
struct channel_program *cp)
{
struct ccw1 *ccw = chain->ch_ccw + idx;
if (ccw_is_test(ccw) || ccw_is_noop(ccw))
return 0;
if (ccw_is_tic(ccw))
return ccwchain_fetch_tic(chain, idx, cp);
if (ccw_is_idal(ccw))
return ccwchain_fetch_idal(chain, idx, cp);
return ccwchain_fetch_direct(chain, idx, cp);
}
int cp_init(struct channel_program *cp, struct device *mdev, union orb *orb)
{
u64 iova = orb->cmd.cpa;
struct ccwchain *chain;
int len, ret;
if (!orb->cmd.pfch || !orb->cmd.c64 || orb->cmd.i2k)
return -EOPNOTSUPP;
INIT_LIST_HEAD(&cp->ccwchain_list);
memcpy(&cp->orb, orb, sizeof(*orb));
cp->mdev = mdev;
len = ccwchain_calc_length(iova, cp);
if (len < 0)
return len;
chain = ccwchain_alloc(cp, len);
if (!chain)
return -ENOMEM;
chain->ch_iova = iova;
ret = copy_ccw_from_iova(cp, chain->ch_ccw, iova, len);
if (ret) {
ccwchain_free(chain);
return ret;
}
ret = ccwchain_loop_tic(chain, cp);
if (ret)
cp_unpin_free(cp);
return ret;
}
void cp_free(struct channel_program *cp)
{
cp_unpin_free(cp);
}
int cp_prefetch(struct channel_program *cp)
{
struct ccwchain *chain;
int len, idx, ret;
list_for_each_entry(chain, &cp->ccwchain_list, next) {
len = chain->ch_len;
for (idx = 0; idx < len; idx++) {
ret = ccwchain_fetch_one(chain, idx, cp);
if (ret)
return ret;
}
}
return 0;
}
union orb *cp_get_orb(struct channel_program *cp, u32 intparm, u8 lpm)
{
union orb *orb;
struct ccwchain *chain;
struct ccw1 *cpa;
orb = &cp->orb;
orb->cmd.intparm = intparm;
orb->cmd.fmt = 1;
orb->cmd.key = PAGE_DEFAULT_KEY >> 4;
if (orb->cmd.lpm == 0)
orb->cmd.lpm = lpm;
chain = list_first_entry(&cp->ccwchain_list, struct ccwchain, next);
cpa = chain->ch_ccw;
orb->cmd.cpa = (__u32) __pa(cpa);
return orb;
}
void cp_update_scsw(struct channel_program *cp, union scsw *scsw)
{
struct ccwchain *chain;
u32 cpa = scsw->cmd.cpa;
u32 ccw_head, ccw_tail;
list_for_each_entry(chain, &cp->ccwchain_list, next) {
ccw_head = (u32)(u64)chain->ch_ccw;
ccw_tail = (u32)(u64)(chain->ch_ccw + chain->ch_len - 1);
if ((ccw_head <= cpa) && (cpa <= ccw_tail)) {
cpa = chain->ch_iova + (cpa - ccw_head);
break;
}
}
scsw->cmd.cpa = cpa;
}
bool cp_iova_pinned(struct channel_program *cp, u64 iova)
{
struct ccwchain *chain;
int i;
list_for_each_entry(chain, &cp->ccwchain_list, next) {
for (i = 0; i < chain->ch_len; i++)
if (pfn_array_table_iova_pinned(chain->ch_pat + i,
iova))
return true;
}
return false;
}
