static inline int is_valid_mmap(u64 token)
{
return (HFI1_MMAP_TOKEN_GET(MAGIC, token) == HFI1_MMAP_MAGIC);
}
static int hfi1_file_open(struct inode *inode, struct file *fp)
{
fp->private_data = kzalloc(sizeof(struct hfi1_filedata), GFP_KERNEL);
if (fp->private_data)
((struct hfi1_filedata *)fp->private_data)->rec_cpu_num = -1;
return fp->private_data ? 0 : -ENOMEM;
}
static ssize_t hfi1_file_write(struct file *fp, const char __user *data,
size_t count, loff_t *offset)
{
const struct hfi1_cmd __user *ucmd;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_cmd cmd;
struct hfi1_user_info uinfo;
struct hfi1_tid_info tinfo;
ssize_t consumed = 0, copy = 0, ret = 0;
void *dest = NULL;
__u64 user_val = 0;
int uctxt_required = 1;
int must_be_root = 0;
if (count < sizeof(cmd)) {
ret = -EINVAL;
goto bail;
}
ucmd = (const struct hfi1_cmd __user *)data;
if (copy_from_user(&cmd, ucmd, sizeof(cmd))) {
ret = -EFAULT;
goto bail;
}
consumed = sizeof(cmd);
switch (cmd.type) {
case HFI1_CMD_ASSIGN_CTXT:
uctxt_required = 0;
copy = sizeof(uinfo);
dest = &uinfo;
break;
case HFI1_CMD_SDMA_STATUS_UPD:
case HFI1_CMD_CREDIT_UPD:
copy = 0;
break;
case HFI1_CMD_TID_UPDATE:
case HFI1_CMD_TID_FREE:
copy = sizeof(tinfo);
dest = &tinfo;
break;
case HFI1_CMD_USER_INFO:
case HFI1_CMD_RECV_CTRL:
case HFI1_CMD_POLL_TYPE:
case HFI1_CMD_ACK_EVENT:
case HFI1_CMD_CTXT_INFO:
case HFI1_CMD_SET_PKEY:
case HFI1_CMD_CTXT_RESET:
copy = 0;
user_val = cmd.addr;
break;
case HFI1_CMD_EP_INFO:
case HFI1_CMD_EP_ERASE_CHIP:
case HFI1_CMD_EP_ERASE_RANGE:
case HFI1_CMD_EP_READ_RANGE:
case HFI1_CMD_EP_WRITE_RANGE:
uctxt_required = 0;
must_be_root = 1;
copy = 0;
break;
default:
ret = -EINVAL;
goto bail;
}
if (copy) {
if (copy_from_user(dest, (void __user *)cmd.addr, copy)) {
ret = -EFAULT;
goto bail;
}
consumed += copy;
}
if (uctxt_required && !uctxt) {
ret = -EINVAL;
goto bail;
}
if (must_be_root && !capable(CAP_SYS_ADMIN)) {
ret = -EPERM;
goto bail;
}
switch (cmd.type) {
case HFI1_CMD_ASSIGN_CTXT:
ret = assign_ctxt(fp, &uinfo);
if (ret < 0)
goto bail;
ret = setup_ctxt(fp);
if (ret)
goto bail;
ret = user_init(fp);
break;
case HFI1_CMD_CTXT_INFO:
ret = get_ctxt_info(fp, (void __user *)(unsigned long)
user_val, cmd.len);
break;
case HFI1_CMD_USER_INFO:
ret = get_base_info(fp, (void __user *)(unsigned long)
user_val, cmd.len);
break;
case HFI1_CMD_SDMA_STATUS_UPD:
break;
case HFI1_CMD_CREDIT_UPD:
if (uctxt && uctxt->sc)
sc_return_credits(uctxt->sc);
break;
case HFI1_CMD_TID_UPDATE:
ret = exp_tid_setup(fp, &tinfo);
if (!ret) {
unsigned long addr;
addr = (unsigned long)cmd.addr +
offsetof(struct hfi1_tid_info, tidcnt);
if (copy_to_user((void __user *)addr, &tinfo.tidcnt,
sizeof(tinfo.tidcnt) +
sizeof(tinfo.length)))
ret = -EFAULT;
}
break;
case HFI1_CMD_TID_FREE:
ret = exp_tid_free(fp, &tinfo);
break;
case HFI1_CMD_RECV_CTRL:
ret = manage_rcvq(uctxt, fd->subctxt, (int)user_val);
break;
case HFI1_CMD_POLL_TYPE:
uctxt->poll_type = (typeof(uctxt->poll_type))user_val;
break;
case HFI1_CMD_ACK_EVENT:
ret = user_event_ack(uctxt, fd->subctxt, user_val);
break;
case HFI1_CMD_SET_PKEY:
if (HFI1_CAP_IS_USET(PKEY_CHECK))
ret = set_ctxt_pkey(uctxt, fd->subctxt, user_val);
else
ret = -EPERM;
break;
case HFI1_CMD_CTXT_RESET: {
struct send_context *sc;
struct hfi1_devdata *dd;
if (!uctxt || !uctxt->dd || !uctxt->sc) {
ret = -EINVAL;
break;
}
dd = uctxt->dd;
sc = uctxt->sc;
wait_event_interruptible_timeout(
sc->halt_wait, (sc->flags & SCF_HALTED),
msecs_to_jiffies(SEND_CTXT_HALT_TIMEOUT));
if (!(sc->flags & SCF_HALTED)) {
ret = -ENOLCK;
break;
}
if (sc->flags & SCF_FROZEN) {
wait_event_interruptible_timeout(
dd->event_queue,
!(ACCESS_ONCE(dd->flags) & HFI1_FROZEN),
msecs_to_jiffies(SEND_CTXT_HALT_TIMEOUT));
if (dd->flags & HFI1_FROZEN) {
ret = -ENOLCK;
break;
}
if (dd->flags & HFI1_FORCED_FREEZE) {
ret = -ENODEV;
break;
}
sc_disable(sc);
ret = sc_enable(sc);
hfi1_rcvctrl(dd, HFI1_RCVCTRL_CTXT_ENB,
uctxt->ctxt);
} else
ret = sc_restart(sc);
if (!ret)
sc_return_credits(sc);
break;
}
case HFI1_CMD_EP_INFO:
case HFI1_CMD_EP_ERASE_CHIP:
case HFI1_CMD_EP_ERASE_RANGE:
case HFI1_CMD_EP_READ_RANGE:
case HFI1_CMD_EP_WRITE_RANGE:
ret = handle_eprom_command(&cmd);
break;
}
if (ret >= 0)
ret = consumed;
bail:
return ret;
}
static ssize_t hfi1_write_iter(struct kiocb *kiocb, struct iov_iter *from)
{
struct hfi1_filedata *fd = kiocb->ki_filp->private_data;
struct hfi1_user_sdma_pkt_q *pq = fd->pq;
struct hfi1_user_sdma_comp_q *cq = fd->cq;
int ret = 0, done = 0, reqs = 0;
unsigned long dim = from->nr_segs;
if (!cq || !pq) {
ret = -EIO;
goto done;
}
if (!iter_is_iovec(from) || !dim) {
ret = -EINVAL;
goto done;
}
hfi1_cdbg(SDMA, "SDMA request from %u:%u (%lu)",
fd->uctxt->ctxt, fd->subctxt, dim);
if (atomic_read(&pq->n_reqs) == pq->n_max_reqs) {
ret = -ENOSPC;
goto done;
}
while (dim) {
unsigned long count = 0;
ret = hfi1_user_sdma_process_request(
kiocb->ki_filp, (struct iovec *)(from->iov + done),
dim, &count);
if (ret)
goto done;
dim -= count;
done += count;
reqs++;
}
done:
return ret ? ret : reqs;
}
static int hfi1_file_mmap(struct file *fp, struct vm_area_struct *vma)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd;
unsigned long flags, pfn;
u64 token = vma->vm_pgoff << PAGE_SHIFT,
memaddr = 0;
u8 subctxt, mapio = 0, vmf = 0, type;
ssize_t memlen = 0;
int ret = 0;
u16 ctxt;
if (!is_valid_mmap(token) || !uctxt ||
!(vma->vm_flags & VM_SHARED)) {
ret = -EINVAL;
goto done;
}
dd = uctxt->dd;
ctxt = HFI1_MMAP_TOKEN_GET(CTXT, token);
subctxt = HFI1_MMAP_TOKEN_GET(SUBCTXT, token);
type = HFI1_MMAP_TOKEN_GET(TYPE, token);
if (ctxt != uctxt->ctxt || subctxt != fd->subctxt) {
ret = -EINVAL;
goto done;
}
flags = vma->vm_flags;
switch (type) {
case PIO_BUFS:
case PIO_BUFS_SOP:
memaddr = ((dd->physaddr + TXE_PIO_SEND) +
(uctxt->sc->hw_context * BIT(16))) +
(type == PIO_BUFS_SOP ?
(TXE_PIO_SIZE / 2) : 0);
memlen = ALIGN(uctxt->sc->credits * PIO_BLOCK_SIZE,
PAGE_SIZE);
flags &= ~VM_MAYREAD;
flags |= VM_DONTCOPY | VM_DONTEXPAND;
vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
mapio = 1;
break;
case PIO_CRED:
if (flags & VM_WRITE) {
ret = -EPERM;
goto done;
}
memaddr = dd->cr_base[uctxt->numa_id].pa +
(((u64)uctxt->sc->hw_free -
(u64)dd->cr_base[uctxt->numa_id].va) & PAGE_MASK);
memlen = PAGE_SIZE;
flags &= ~VM_MAYWRITE;
flags |= VM_DONTCOPY | VM_DONTEXPAND;
mapio = 1;
break;
case RCV_HDRQ:
memaddr = uctxt->rcvhdrq_phys;
memlen = uctxt->rcvhdrq_size;
break;
case RCV_EGRBUF: {
unsigned long addr;
int i;
memlen = uctxt->egrbufs.size;
if ((vma->vm_end - vma->vm_start) != memlen) {
dd_dev_err(dd, "Eager buffer map size invalid (%lu != %lu)\n",
(vma->vm_end - vma->vm_start), memlen);
ret = -EINVAL;
goto done;
}
if (vma->vm_flags & VM_WRITE) {
ret = -EPERM;
goto done;
}
vma->vm_flags &= ~VM_MAYWRITE;
addr = vma->vm_start;
for (i = 0 ; i < uctxt->egrbufs.numbufs; i++) {
ret = remap_pfn_range(
vma, addr,
uctxt->egrbufs.buffers[i].phys >> PAGE_SHIFT,
uctxt->egrbufs.buffers[i].len,
vma->vm_page_prot);
if (ret < 0)
goto done;
addr += uctxt->egrbufs.buffers[i].len;
}
ret = 0;
goto done;
}
case UREGS:
memaddr = (unsigned long)
(dd->physaddr + RXE_PER_CONTEXT_USER)
+ (uctxt->ctxt * RXE_PER_CONTEXT_SIZE);
memlen = PAGE_SIZE;
flags |= VM_DONTCOPY | VM_DONTEXPAND;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
mapio = 1;
break;
case EVENTS:
memaddr = (unsigned long)(dd->events +
((uctxt->ctxt - dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS)) & PAGE_MASK;
memlen = PAGE_SIZE;
flags |= VM_IO | VM_DONTEXPAND;
vmf = 1;
break;
case STATUS:
memaddr = kvirt_to_phys((void *)dd->status);
memlen = PAGE_SIZE;
flags |= VM_IO | VM_DONTEXPAND;
break;
case RTAIL:
if (!HFI1_CAP_IS_USET(DMA_RTAIL)) {
ret = -EINVAL;
goto done;
}
if (flags & VM_WRITE) {
ret = -EPERM;
goto done;
}
memaddr = uctxt->rcvhdrqtailaddr_phys;
memlen = PAGE_SIZE;
flags &= ~VM_MAYWRITE;
break;
case SUBCTXT_UREGS:
memaddr = (u64)uctxt->subctxt_uregbase;
memlen = PAGE_SIZE;
flags |= VM_IO | VM_DONTEXPAND;
vmf = 1;
break;
case SUBCTXT_RCV_HDRQ:
memaddr = (u64)uctxt->subctxt_rcvhdr_base;
memlen = uctxt->rcvhdrq_size * uctxt->subctxt_cnt;
flags |= VM_IO | VM_DONTEXPAND;
vmf = 1;
break;
case SUBCTXT_EGRBUF:
memaddr = (u64)uctxt->subctxt_rcvegrbuf;
memlen = uctxt->egrbufs.size * uctxt->subctxt_cnt;
flags |= VM_IO | VM_DONTEXPAND;
flags &= ~VM_MAYWRITE;
vmf = 1;
break;
case SDMA_COMP: {
struct hfi1_user_sdma_comp_q *cq = fd->cq;
if (!cq) {
ret = -EFAULT;
goto done;
}
memaddr = (u64)cq->comps;
memlen = ALIGN(sizeof(*cq->comps) * cq->nentries, PAGE_SIZE);
flags |= VM_IO | VM_DONTEXPAND;
vmf = 1;
break;
}
default:
ret = -EINVAL;
break;
}
if ((vma->vm_end - vma->vm_start) != memlen) {
hfi1_cdbg(PROC, "%u:%u Memory size mismatch %lu:%lu",
uctxt->ctxt, fd->subctxt,
(vma->vm_end - vma->vm_start), memlen);
ret = -EINVAL;
goto done;
}
vma->vm_flags = flags;
hfi1_cdbg(PROC,
"%u:%u type:%u io/vf:%d/%d, addr:0x%llx, len:%lu(%lu), flags:0x%lx\n",
ctxt, subctxt, type, mapio, vmf, memaddr, memlen,
vma->vm_end - vma->vm_start, vma->vm_flags);
pfn = (unsigned long)(memaddr >> PAGE_SHIFT);
if (vmf) {
vma->vm_pgoff = pfn;
vma->vm_ops = &vm_ops;
ret = 0;
} else if (mapio) {
ret = io_remap_pfn_range(vma, vma->vm_start, pfn, memlen,
vma->vm_page_prot);
} else {
ret = remap_pfn_range(vma, vma->vm_start, pfn, memlen,
vma->vm_page_prot);
}
done:
return ret;
}
static int vma_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct page *page;
page = vmalloc_to_page((void *)(vmf->pgoff << PAGE_SHIFT));
if (!page)
return VM_FAULT_SIGBUS;
get_page(page);
vmf->page = page;
return 0;
}
static unsigned int hfi1_poll(struct file *fp, struct poll_table_struct *pt)
{
struct hfi1_ctxtdata *uctxt;
unsigned pollflag;
uctxt = ((struct hfi1_filedata *)fp->private_data)->uctxt;
if (!uctxt)
pollflag = POLLERR;
else if (uctxt->poll_type == HFI1_POLL_TYPE_URGENT)
pollflag = poll_urgent(fp, pt);
else if (uctxt->poll_type == HFI1_POLL_TYPE_ANYRCV)
pollflag = poll_next(fp, pt);
else
pollflag = POLLERR;
return pollflag;
}
static int hfi1_file_close(struct inode *inode, struct file *fp)
{
struct hfi1_filedata *fdata = fp->private_data;
struct hfi1_ctxtdata *uctxt = fdata->uctxt;
struct hfi1_devdata *dd;
unsigned long flags, *ev;
fp->private_data = NULL;
if (!uctxt)
goto done;
hfi1_cdbg(PROC, "freeing ctxt %u:%u", uctxt->ctxt, fdata->subctxt);
dd = uctxt->dd;
mutex_lock(&hfi1_mutex);
flush_wc();
hfi1_user_sdma_free_queues(fdata);
ev = dd->events + ((uctxt->ctxt - dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS) + fdata->subctxt;
*ev = 0;
if (--uctxt->cnt) {
uctxt->active_slaves &= ~(1 << fdata->subctxt);
uctxt->subpid[fdata->subctxt] = 0;
mutex_unlock(&hfi1_mutex);
goto done;
}
spin_lock_irqsave(&dd->uctxt_lock, flags);
hfi1_rcvctrl(dd, HFI1_RCVCTRL_CTXT_DIS |
HFI1_RCVCTRL_TIDFLOW_DIS |
HFI1_RCVCTRL_INTRAVAIL_DIS |
HFI1_RCVCTRL_ONE_PKT_EGR_DIS |
HFI1_RCVCTRL_NO_RHQ_DROP_DIS |
HFI1_RCVCTRL_NO_EGR_DROP_DIS, uctxt->ctxt);
hfi1_clear_ctxt_jkey(dd, uctxt->ctxt);
write_kctxt_csr(dd, uctxt->sc->hw_context, SEND_CTXT_CHECK_ENABLE,
hfi1_pkt_default_send_ctxt_mask(dd, uctxt->sc->type));
sc_disable(uctxt->sc);
uctxt->pid = 0;
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
dd->rcd[uctxt->ctxt] = NULL;
uctxt->rcvwait_to = 0;
uctxt->piowait_to = 0;
uctxt->rcvnowait = 0;
uctxt->pionowait = 0;
uctxt->event_flags = 0;
hfi1_clear_tids(uctxt);
hfi1_clear_ctxt_pkey(dd, uctxt->ctxt);
if (uctxt->tid_pg_list)
unlock_exp_tids(uctxt);
hfi1_stats.sps_ctxts--;
dd->freectxts++;
mutex_unlock(&hfi1_mutex);
hfi1_free_ctxtdata(dd, uctxt);
done:
kfree(fdata);
return 0;
}
static u64 kvirt_to_phys(void *addr)
{
struct page *page;
u64 paddr = 0;
page = vmalloc_to_page(addr);
if (page)
paddr = page_to_pfn(page) << PAGE_SHIFT;
return paddr;
}
static int assign_ctxt(struct file *fp, struct hfi1_user_info *uinfo)
{
int i_minor, ret = 0;
unsigned swmajor, swminor, alg = HFI1_ALG_ACROSS;
swmajor = uinfo->userversion >> 16;
if (swmajor != HFI1_USER_SWMAJOR) {
ret = -ENODEV;
goto done;
}
swminor = uinfo->userversion & 0xffff;
if (uinfo->hfi1_alg < HFI1_ALG_COUNT)
alg = uinfo->hfi1_alg;
mutex_lock(&hfi1_mutex);
if (uinfo->subctxt_cnt)
ret = find_shared_ctxt(fp, uinfo);
if (!ret) {
i_minor = iminor(file_inode(fp)) - HFI1_USER_MINOR_BASE;
ret = get_user_context(fp, uinfo, i_minor - 1, alg);
}
mutex_unlock(&hfi1_mutex);
done:
return ret;
}
static int usable_device(struct hfi1_devdata *dd)
{
struct hfi1_pportdata *ppd = dd->pport;
return driver_lstate(ppd) == IB_PORT_ACTIVE;
}
static int get_user_context(struct file *fp, struct hfi1_user_info *uinfo,
int devno, unsigned alg)
{
struct hfi1_devdata *dd = NULL;
int ret = 0, devmax, npresent, nup, dev;
devmax = hfi1_count_units(&npresent, &nup);
if (!npresent) {
ret = -ENXIO;
goto done;
}
if (!nup) {
ret = -ENETDOWN;
goto done;
}
if (devno >= 0) {
dd = hfi1_lookup(devno);
if (!dd)
ret = -ENODEV;
else if (!dd->freectxts)
ret = -EBUSY;
} else {
struct hfi1_devdata *pdd;
if (alg == HFI1_ALG_ACROSS) {
unsigned free = 0U;
for (dev = 0; dev < devmax; dev++) {
pdd = hfi1_lookup(dev);
if (!pdd)
continue;
if (!usable_device(pdd))
continue;
if (pdd->freectxts &&
pdd->freectxts > free) {
dd = pdd;
free = pdd->freectxts;
}
}
} else {
for (dev = 0; dev < devmax; dev++) {
pdd = hfi1_lookup(dev);
if (!pdd)
continue;
if (!usable_device(pdd))
continue;
if (pdd->freectxts) {
dd = pdd;
break;
}
}
}
if (!dd)
ret = -EBUSY;
}
done:
return ret ? ret : allocate_ctxt(fp, dd, uinfo);
}
static int find_shared_ctxt(struct file *fp,
const struct hfi1_user_info *uinfo)
{
int devmax, ndev, i;
int ret = 0;
struct hfi1_filedata *fd = fp->private_data;
devmax = hfi1_count_units(NULL, NULL);
for (ndev = 0; ndev < devmax; ndev++) {
struct hfi1_devdata *dd = hfi1_lookup(ndev);
if (!(dd && (dd->flags & HFI1_PRESENT) && dd->kregbase))
continue;
for (i = dd->first_user_ctxt; i < dd->num_rcv_contexts; i++) {
struct hfi1_ctxtdata *uctxt = dd->rcd[i];
if (!uctxt || !uctxt->cnt)
continue;
if (memcmp(uctxt->uuid, uinfo->uuid,
sizeof(uctxt->uuid)) ||
uctxt->jkey != generate_jkey(current_uid()) ||
uctxt->subctxt_id != uinfo->subctxt_id ||
uctxt->subctxt_cnt != uinfo->subctxt_cnt)
continue;
if (uctxt->userversion != uinfo->userversion ||
uctxt->cnt >= uctxt->subctxt_cnt) {
ret = -EINVAL;
goto done;
}
fd->uctxt = uctxt;
fd->subctxt = uctxt->cnt++;
uctxt->subpid[fd->subctxt] = current->pid;
uctxt->active_slaves |= 1 << fd->subctxt;
ret = 1;
goto done;
}
}
done:
return ret;
}
static int allocate_ctxt(struct file *fp, struct hfi1_devdata *dd,
struct hfi1_user_info *uinfo)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt;
unsigned ctxt;
int ret;
if (dd->flags & HFI1_FROZEN) {
return -EIO;
}
for (ctxt = dd->first_user_ctxt; ctxt < dd->num_rcv_contexts; ctxt++)
if (!dd->rcd[ctxt])
break;
if (ctxt == dd->num_rcv_contexts)
return -EBUSY;
uctxt = hfi1_create_ctxtdata(dd->pport, ctxt);
if (!uctxt) {
dd_dev_err(dd,
"Unable to allocate ctxtdata memory, failing open\n");
return -ENOMEM;
}
uctxt->sc = sc_alloc(dd, SC_USER, uctxt->rcvhdrqentsize,
uctxt->numa_id);
if (!uctxt->sc)
return -ENOMEM;
hfi1_cdbg(PROC, "allocated send context %u(%u)\n", uctxt->sc->sw_index,
uctxt->sc->hw_context);
ret = sc_enable(uctxt->sc);
if (ret)
return ret;
if (uinfo->subctxt_cnt && !fd->subctxt) {
ret = init_subctxts(uctxt, uinfo);
if (ret)
return ret;
}
uctxt->userversion = uinfo->userversion;
uctxt->pid = current->pid;
uctxt->flags = HFI1_CAP_UGET(MASK);
init_waitqueue_head(&uctxt->wait);
strlcpy(uctxt->comm, current->comm, sizeof(uctxt->comm));
memcpy(uctxt->uuid, uinfo->uuid, sizeof(uctxt->uuid));
uctxt->jkey = generate_jkey(current_uid());
INIT_LIST_HEAD(&uctxt->sdma_queues);
spin_lock_init(&uctxt->sdma_qlock);
hfi1_stats.sps_ctxts++;
dd->freectxts--;
fd->uctxt = uctxt;
return 0;
}
static int init_subctxts(struct hfi1_ctxtdata *uctxt,
const struct hfi1_user_info *uinfo)
{
int ret = 0;
unsigned num_subctxts;
num_subctxts = uinfo->subctxt_cnt;
if (num_subctxts > HFI1_MAX_SHARED_CTXTS) {
ret = -EINVAL;
goto bail;
}
uctxt->subctxt_cnt = uinfo->subctxt_cnt;
uctxt->subctxt_id = uinfo->subctxt_id;
uctxt->active_slaves = 1;
uctxt->redirect_seq_cnt = 1;
set_bit(HFI1_CTXT_MASTER_UNINIT, &uctxt->event_flags);
bail:
return ret;
}
static int setup_subctxt(struct hfi1_ctxtdata *uctxt)
{
int ret = 0;
unsigned num_subctxts = uctxt->subctxt_cnt;
uctxt->subctxt_uregbase = vmalloc_user(PAGE_SIZE);
if (!uctxt->subctxt_uregbase) {
ret = -ENOMEM;
goto bail;
}
uctxt->subctxt_rcvhdr_base = vmalloc_user(uctxt->rcvhdrq_size *
num_subctxts);
if (!uctxt->subctxt_rcvhdr_base) {
ret = -ENOMEM;
goto bail_ureg;
}
uctxt->subctxt_rcvegrbuf = vmalloc_user(uctxt->egrbufs.size *
num_subctxts);
if (!uctxt->subctxt_rcvegrbuf) {
ret = -ENOMEM;
goto bail_rhdr;
}
goto bail;
bail_rhdr:
vfree(uctxt->subctxt_rcvhdr_base);
bail_ureg:
vfree(uctxt->subctxt_uregbase);
uctxt->subctxt_uregbase = NULL;
bail:
return ret;
}
static int user_init(struct file *fp)
{
int ret;
unsigned int rcvctrl_ops = 0;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
if (!test_bit(HFI1_CTXT_SETUP_DONE, &uctxt->event_flags)) {
ret = -EFAULT;
goto done;
}
if (fd->subctxt) {
ret = wait_event_interruptible(uctxt->wait,
!test_bit(HFI1_CTXT_MASTER_UNINIT,
&uctxt->event_flags));
goto done;
}
uctxt->urgent = 0;
uctxt->urgent_poll = 0;
if (uctxt->rcvhdrtail_kvaddr)
clear_rcvhdrtail(uctxt);
hfi1_set_ctxt_jkey(uctxt->dd, uctxt->ctxt, uctxt->jkey);
rcvctrl_ops = HFI1_RCVCTRL_CTXT_ENB;
if (HFI1_CAP_KGET_MASK(uctxt->flags, HDRSUPP))
rcvctrl_ops |= HFI1_RCVCTRL_TIDFLOW_ENB;
if (!HFI1_CAP_KGET_MASK(uctxt->flags, MULTI_PKT_EGR))
rcvctrl_ops |= HFI1_RCVCTRL_ONE_PKT_EGR_ENB;
if (HFI1_CAP_KGET_MASK(uctxt->flags, NODROP_EGR_FULL))
rcvctrl_ops |= HFI1_RCVCTRL_NO_EGR_DROP_ENB;
if (HFI1_CAP_KGET_MASK(uctxt->flags, NODROP_RHQ_FULL))
rcvctrl_ops |= HFI1_RCVCTRL_NO_RHQ_DROP_ENB;
if (HFI1_CAP_KGET_MASK(uctxt->flags, DMA_RTAIL))
rcvctrl_ops |= HFI1_RCVCTRL_TAILUPD_ENB;
hfi1_rcvctrl(uctxt->dd, rcvctrl_ops, uctxt->ctxt);
if (uctxt->subctxt_cnt) {
clear_bit(HFI1_CTXT_MASTER_UNINIT, &uctxt->event_flags);
wake_up(&uctxt->wait);
}
ret = 0;
done:
return ret;
}
static int get_ctxt_info(struct file *fp, void __user *ubase, __u32 len)
{
struct hfi1_ctxt_info cinfo;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
int ret = 0;
memset(&cinfo, 0, sizeof(cinfo));
ret = hfi1_get_base_kinfo(uctxt, &cinfo);
if (ret < 0)
goto done;
cinfo.num_active = hfi1_count_active_units();
cinfo.unit = uctxt->dd->unit;
cinfo.ctxt = uctxt->ctxt;
cinfo.subctxt = fd->subctxt;
cinfo.rcvtids = roundup(uctxt->egrbufs.alloced,
uctxt->dd->rcv_entries.group_size) +
uctxt->expected_count;
cinfo.credits = uctxt->sc->credits;
cinfo.numa_node = uctxt->numa_id;
cinfo.rec_cpu = fd->rec_cpu_num;
cinfo.send_ctxt = uctxt->sc->hw_context;
cinfo.egrtids = uctxt->egrbufs.alloced;
cinfo.rcvhdrq_cnt = uctxt->rcvhdrq_cnt;
cinfo.rcvhdrq_entsize = uctxt->rcvhdrqentsize << 2;
cinfo.sdma_ring_size = fd->cq->nentries;
cinfo.rcvegr_size = uctxt->egrbufs.rcvtid_size;
trace_hfi1_ctxt_info(uctxt->dd, uctxt->ctxt, fd->subctxt, cinfo);
if (copy_to_user(ubase, &cinfo, sizeof(cinfo)))
ret = -EFAULT;
done:
return ret;
}
static int setup_ctxt(struct file *fp)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
int ret = 0;
if (!uctxt->subctxt_cnt || !fd->subctxt) {
ret = hfi1_init_ctxt(uctxt->sc);
if (ret)
goto done;
ret = hfi1_create_rcvhdrq(dd, uctxt);
if (ret)
goto done;
ret = hfi1_setup_eagerbufs(uctxt);
if (ret)
goto done;
if (uctxt->subctxt_cnt && !fd->subctxt) {
ret = setup_subctxt(uctxt);
if (ret)
goto done;
}
uctxt->tid_pg_list = vzalloc(uctxt->expected_count *
sizeof(struct page **));
if (!uctxt->tid_pg_list) {
ret = -ENOMEM;
goto done;
}
uctxt->physshadow = vzalloc(uctxt->expected_count *
sizeof(*uctxt->physshadow));
if (!uctxt->physshadow) {
ret = -ENOMEM;
goto done;
}
atomic_set(&uctxt->tidcursor, 0);
uctxt->numtidgroups = uctxt->expected_count /
dd->rcv_entries.group_size;
uctxt->tidmapcnt = uctxt->numtidgroups / BITS_PER_LONG +
!!(uctxt->numtidgroups % BITS_PER_LONG);
uctxt->tidusemap = kzalloc_node(uctxt->tidmapcnt *
sizeof(*uctxt->tidusemap),
GFP_KERNEL, uctxt->numa_id);
if (!uctxt->tidusemap) {
ret = -ENOMEM;
goto done;
}
if (uctxt->numtidgroups % BITS_PER_LONG)
uctxt->tidusemap[uctxt->tidmapcnt - 1] =
~((1ULL << (uctxt->numtidgroups %
BITS_PER_LONG)) - 1);
trace_hfi1_exp_tid_map(uctxt->ctxt, fd->subctxt, 0,
uctxt->tidusemap, uctxt->tidmapcnt);
}
ret = hfi1_user_sdma_alloc_queues(uctxt, fp);
if (ret)
goto done;
set_bit(HFI1_CTXT_SETUP_DONE, &uctxt->event_flags);
done:
return ret;
}
static int get_base_info(struct file *fp, void __user *ubase, __u32 len)
{
struct hfi1_base_info binfo;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
ssize_t sz;
unsigned offset;
int ret = 0;
trace_hfi1_uctxtdata(uctxt->dd, uctxt);
memset(&binfo, 0, sizeof(binfo));
binfo.hw_version = dd->revision;
binfo.sw_version = HFI1_KERN_SWVERSION;
binfo.bthqp = kdeth_qp;
binfo.jkey = uctxt->jkey;
offset = ((u64)uctxt->sc->hw_free -
(u64)dd->cr_base[uctxt->numa_id].va) % PAGE_SIZE;
binfo.sc_credits_addr = HFI1_MMAP_TOKEN(PIO_CRED, uctxt->ctxt,
fd->subctxt, offset);
binfo.pio_bufbase = HFI1_MMAP_TOKEN(PIO_BUFS, uctxt->ctxt,
fd->subctxt,
uctxt->sc->base_addr);
binfo.pio_bufbase_sop = HFI1_MMAP_TOKEN(PIO_BUFS_SOP,
uctxt->ctxt,
fd->subctxt,
uctxt->sc->base_addr);
binfo.rcvhdr_bufbase = HFI1_MMAP_TOKEN(RCV_HDRQ, uctxt->ctxt,
fd->subctxt,
uctxt->rcvhdrq);
binfo.rcvegr_bufbase = HFI1_MMAP_TOKEN(RCV_EGRBUF, uctxt->ctxt,
fd->subctxt,
uctxt->egrbufs.rcvtids[0].phys);
binfo.sdma_comp_bufbase = HFI1_MMAP_TOKEN(SDMA_COMP, uctxt->ctxt,
fd->subctxt, 0);
binfo.user_regbase = HFI1_MMAP_TOKEN(UREGS, uctxt->ctxt,
fd->subctxt, 0);
offset = offset_in_page((((uctxt->ctxt - dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS) + fd->subctxt) *
sizeof(*dd->events));
binfo.events_bufbase = HFI1_MMAP_TOKEN(EVENTS, uctxt->ctxt,
fd->subctxt,
offset);
binfo.status_bufbase = HFI1_MMAP_TOKEN(STATUS, uctxt->ctxt,
fd->subctxt,
dd->status);
if (HFI1_CAP_IS_USET(DMA_RTAIL))
binfo.rcvhdrtail_base = HFI1_MMAP_TOKEN(RTAIL, uctxt->ctxt,
fd->subctxt, 0);
if (uctxt->subctxt_cnt) {
binfo.subctxt_uregbase = HFI1_MMAP_TOKEN(SUBCTXT_UREGS,
uctxt->ctxt,
fd->subctxt, 0);
binfo.subctxt_rcvhdrbuf = HFI1_MMAP_TOKEN(SUBCTXT_RCV_HDRQ,
uctxt->ctxt,
fd->subctxt, 0);
binfo.subctxt_rcvegrbuf = HFI1_MMAP_TOKEN(SUBCTXT_EGRBUF,
uctxt->ctxt,
fd->subctxt, 0);
}
sz = (len < sizeof(binfo)) ? len : sizeof(binfo);
if (copy_to_user(ubase, &binfo, sz))
ret = -EFAULT;
return ret;
}
static unsigned int poll_urgent(struct file *fp,
struct poll_table_struct *pt)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned pollflag;
poll_wait(fp, &uctxt->wait, pt);
spin_lock_irq(&dd->uctxt_lock);
if (uctxt->urgent != uctxt->urgent_poll) {
pollflag = POLLIN | POLLRDNORM;
uctxt->urgent_poll = uctxt->urgent;
} else {
pollflag = 0;
set_bit(HFI1_CTXT_WAITING_URG, &uctxt->event_flags);
}
spin_unlock_irq(&dd->uctxt_lock);
return pollflag;
}
static unsigned int poll_next(struct file *fp,
struct poll_table_struct *pt)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned pollflag;
poll_wait(fp, &uctxt->wait, pt);
spin_lock_irq(&dd->uctxt_lock);
if (hdrqempty(uctxt)) {
set_bit(HFI1_CTXT_WAITING_RCV, &uctxt->event_flags);
hfi1_rcvctrl(dd, HFI1_RCVCTRL_INTRAVAIL_ENB, uctxt->ctxt);
pollflag = 0;
} else
pollflag = POLLIN | POLLRDNORM;
spin_unlock_irq(&dd->uctxt_lock);
return pollflag;
}
int hfi1_set_uevent_bits(struct hfi1_pportdata *ppd, const int evtbit)
{
struct hfi1_ctxtdata *uctxt;
struct hfi1_devdata *dd = ppd->dd;
unsigned ctxt;
int ret = 0;
unsigned long flags;
if (!dd->events) {
ret = -EINVAL;
goto done;
}
spin_lock_irqsave(&dd->uctxt_lock, flags);
for (ctxt = dd->first_user_ctxt; ctxt < dd->num_rcv_contexts;
ctxt++) {
uctxt = dd->rcd[ctxt];
if (uctxt) {
unsigned long *evs = dd->events +
(uctxt->ctxt - dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS;
int i;
set_bit(evtbit, evs);
for (i = 1; i < uctxt->subctxt_cnt; i++)
set_bit(evtbit, evs + i);
}
}
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
done:
return ret;
}
static int manage_rcvq(struct hfi1_ctxtdata *uctxt, unsigned subctxt,
int start_stop)
{
struct hfi1_devdata *dd = uctxt->dd;
unsigned int rcvctrl_op;
if (subctxt)
goto bail;
if (start_stop) {
if (uctxt->rcvhdrtail_kvaddr)
clear_rcvhdrtail(uctxt);
rcvctrl_op = HFI1_RCVCTRL_CTXT_ENB;
} else
rcvctrl_op = HFI1_RCVCTRL_CTXT_DIS;
hfi1_rcvctrl(dd, rcvctrl_op, uctxt->ctxt);
bail:
return 0;
}
static int user_event_ack(struct hfi1_ctxtdata *uctxt, int subctxt,
unsigned long events)
{
int i;
struct hfi1_devdata *dd = uctxt->dd;
unsigned long *evs;
if (!dd->events)
return 0;
evs = dd->events + ((uctxt->ctxt - dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS) + subctxt;
for (i = 0; i <= _HFI1_MAX_EVENT_BIT; i++) {
if (!test_bit(i, &events))
continue;
clear_bit(i, evs);
}
return 0;
}
static inline u8 tzcnt(u64 value)
{
return value ? __builtin_ctzl(value) : sizeof(value) * 8;
}
static inline unsigned num_free_groups(unsigned long map, u16 *start)
{
unsigned free;
u16 bitidx = *start;
if (bitidx >= BITS_PER_LONG)
return 0;
map &= ~((1ULL << bitidx) - 1);
free = tzcnt(map) - bitidx;
while (!free && bitidx < BITS_PER_LONG) {
map &= ~(1ULL << bitidx);
free = tzcnt(map) - ++bitidx;
}
*start = bitidx;
return free;
}
static int exp_tid_setup(struct file *fp, struct hfi1_tid_info *tinfo)
{
int ret = 0;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned tid, mapped = 0, npages, ngroups, exp_groups,
tidpairs = uctxt->expected_count / 2;
struct page **pages;
unsigned long vaddr, tidmap[uctxt->tidmapcnt];
dma_addr_t *phys;
u32 tidlist[tidpairs], pairidx = 0, tidcursor;
u16 useidx, idx, bitidx, tidcnt = 0;
vaddr = tinfo->vaddr;
if (offset_in_page(vaddr)) {
ret = -EINVAL;
goto bail;
}
npages = num_user_pages(vaddr, tinfo->length);
if (!npages) {
ret = -EINVAL;
goto bail;
}
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr,
npages * PAGE_SIZE)) {
dd_dev_err(dd, "Fail vaddr %p, %u pages, !access_ok\n",
(void *)vaddr, npages);
ret = -EFAULT;
goto bail;
}
memset(tidmap, 0, sizeof(tidmap[0]) * uctxt->tidmapcnt);
memset(tidlist, 0, sizeof(tidlist[0]) * tidpairs);
exp_groups = uctxt->expected_count / dd->rcv_entries.group_size;
tidcursor = atomic_read(&uctxt->tidcursor);
useidx = (tidcursor >> 16) & 0xffff;
bitidx = tidcursor & 0xffff;
for (mapped = 0, idx = 0;
mapped < npages && idx <= uctxt->tidmapcnt;) {
u64 i, offset = 0;
unsigned free, pinned, pmapped = 0, bits_used;
u16 grp;
spin_lock(&uctxt->exp_lock);
if (uctxt->tidusemap[useidx] == -1ULL ||
bitidx >= BITS_PER_LONG) {
useidx = (useidx + 1) % uctxt->tidmapcnt;
idx++;
bitidx = 0;
spin_unlock(&uctxt->exp_lock);
continue;
}
ngroups = ((npages - mapped) / dd->rcv_entries.group_size) +
!!((npages - mapped) % dd->rcv_entries.group_size);
free = num_free_groups(uctxt->tidusemap[useidx], &bitidx);
if (!free) {
spin_unlock(&uctxt->exp_lock);
continue;
}
bits_used = min(free, ngroups);
tidmap[useidx] |= ((1ULL << bits_used) - 1) << bitidx;
uctxt->tidusemap[useidx] |= tidmap[useidx];
spin_unlock(&uctxt->exp_lock);
offset = ((useidx * BITS_PER_LONG) + bitidx) *
dd->rcv_entries.group_size;
pages = uctxt->tid_pg_list + offset;
phys = uctxt->physshadow + offset;
tid = uctxt->expected_base + offset;
pinned = min((bits_used * dd->rcv_entries.group_size),
(npages - mapped));
ret = hfi1_acquire_user_pages(vaddr + (mapped * PAGE_SIZE),
pinned, true, pages);
if (ret) {
dd_dev_info(dd,
"Failed to lock addr %p, %u pages: errno %d\n",
(void *) vaddr, pinned, -ret);
spin_lock(&uctxt->exp_lock);
uctxt->tidusemap[useidx] &=
~(((1ULL << bits_used) - 1) << bitidx);
spin_unlock(&uctxt->exp_lock);
goto done;
}
ngroups = (pinned / dd->rcv_entries.group_size) +
!!(pinned % dd->rcv_entries.group_size);
for (i = 0, grp = 0; grp < ngroups; i++, grp++) {
unsigned j;
u32 pair_size = 0, tidsize;
for (j = 0; j < dd->rcv_entries.group_size &&
pmapped < pinned; j++, pmapped++, tid++) {
tidsize = PAGE_SIZE;
phys[pmapped] = hfi1_map_page(dd->pcidev,
pages[pmapped], 0,
tidsize, PCI_DMA_FROMDEVICE);
trace_hfi1_exp_rcv_set(uctxt->ctxt,
fd->subctxt,
tid, vaddr,
phys[pmapped],
pages[pmapped]);
hfi1_put_tid(dd, tid, PT_EXPECTED,
phys[pmapped],
ilog2(tidsize >> PAGE_SHIFT) + 1);
pair_size += tidsize >> PAGE_SHIFT;
EXP_TID_RESET(tidlist[pairidx], LEN, pair_size);
if (!(tid % 2)) {
tidlist[pairidx] |=
EXP_TID_SET(IDX,
(tid - uctxt->expected_base)
/ 2);
tidlist[pairidx] |=
EXP_TID_SET(CTRL, 1);
tidcnt++;
} else {
tidlist[pairidx] |=
EXP_TID_SET(CTRL, 2);
pair_size = 0;
pairidx++;
}
}
flush_wc();
}
mapped += pinned;
atomic_set(&uctxt->tidcursor,
(((useidx & 0xffffff) << 16) |
((bitidx + bits_used) & 0xffffff)));
}
trace_hfi1_exp_tid_map(uctxt->ctxt, fd->subctxt, 0, uctxt->tidusemap,
uctxt->tidmapcnt);
done:
if (mapped) {
if (copy_to_user((void __user *)(unsigned long)tinfo->tidlist,
tidlist, sizeof(tidlist[0]) * tidcnt)) {
ret = -EFAULT;
goto done;
}
if (copy_to_user((void __user *)(unsigned long)tinfo->tidmap,
tidmap, sizeof(tidmap[0]) * uctxt->tidmapcnt))
ret = -EFAULT;
}
bail:
tinfo->length = mapped * PAGE_SIZE;
tinfo->tidcnt = tidcnt;
return ret;
}
static int exp_tid_free(struct file *fp, struct hfi1_tid_info *tinfo)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd = uctxt->dd;
unsigned long tidmap[uctxt->tidmapcnt];
struct page **pages;
dma_addr_t *phys;
u16 idx, bitidx, tid;
int ret = 0;
if (copy_from_user(&tidmap, (void __user *)(unsigned long)
tinfo->tidmap,
sizeof(tidmap[0]) * uctxt->tidmapcnt)) {
ret = -EFAULT;
goto done;
}
for (idx = 0; idx < uctxt->tidmapcnt; idx++) {
unsigned long map;
bitidx = 0;
if (!tidmap[idx])
continue;
map = tidmap[idx];
while ((bitidx = tzcnt(map)) < BITS_PER_LONG) {
int i, pcount = 0;
struct page *pshadow[dd->rcv_entries.group_size];
unsigned offset = ((idx * BITS_PER_LONG) + bitidx) *
dd->rcv_entries.group_size;
pages = uctxt->tid_pg_list + offset;
phys = uctxt->physshadow + offset;
tid = uctxt->expected_base + offset;
for (i = 0; i < dd->rcv_entries.group_size;
i++, tid++) {
if (pages[i]) {
hfi1_put_tid(dd, tid, PT_INVALID,
0, 0);
trace_hfi1_exp_rcv_free(uctxt->ctxt,
fd->subctxt,
tid, phys[i],
pages[i]);
pci_unmap_page(dd->pcidev, phys[i],
PAGE_SIZE, PCI_DMA_FROMDEVICE);
pshadow[pcount] = pages[i];
pages[i] = NULL;
pcount++;
phys[i] = 0;
}
}
flush_wc();
hfi1_release_user_pages(pshadow, pcount, true);
clear_bit(bitidx, &uctxt->tidusemap[idx]);
map &= ~(1ULL<<bitidx);
}
}
trace_hfi1_exp_tid_map(uctxt->ctxt, fd->subctxt, 1, uctxt->tidusemap,
uctxt->tidmapcnt);
done:
return ret;
}
static void unlock_exp_tids(struct hfi1_ctxtdata *uctxt)
{
struct hfi1_devdata *dd = uctxt->dd;
unsigned tid;
dd_dev_info(dd, "ctxt %u unlocking any locked expTID pages\n",
uctxt->ctxt);
for (tid = 0; tid < uctxt->expected_count; tid++) {
struct page *p = uctxt->tid_pg_list[tid];
dma_addr_t phys;
if (!p)
continue;
phys = uctxt->physshadow[tid];
uctxt->physshadow[tid] = 0;
uctxt->tid_pg_list[tid] = NULL;
pci_unmap_page(dd->pcidev, phys, PAGE_SIZE, PCI_DMA_FROMDEVICE);
hfi1_release_user_pages(&p, 1, true);
}
}
static int set_ctxt_pkey(struct hfi1_ctxtdata *uctxt, unsigned subctxt,
u16 pkey)
{
int ret = -ENOENT, i, intable = 0;
struct hfi1_pportdata *ppd = uctxt->ppd;
struct hfi1_devdata *dd = uctxt->dd;
if (pkey == LIM_MGMT_P_KEY || pkey == FULL_MGMT_P_KEY) {
ret = -EINVAL;
goto done;
}
for (i = 0; i < ARRAY_SIZE(ppd->pkeys); i++)
if (pkey == ppd->pkeys[i]) {
intable = 1;
break;
}
if (intable)
ret = hfi1_set_ctxt_pkey(dd, uctxt->ctxt, pkey);
done:
return ret;
}
static int ui_open(struct inode *inode, struct file *filp)
{
struct hfi1_devdata *dd;
dd = container_of(inode->i_cdev, struct hfi1_devdata, ui_cdev);
filp->private_data = dd;
return 0;
}
static int ui_release(struct inode *inode, struct file *filp)
{
return 0;
}
static loff_t ui_lseek(struct file *filp, loff_t offset, int whence)
{
struct hfi1_devdata *dd = filp->private_data;
switch (whence) {
case SEEK_SET:
break;
case SEEK_CUR:
offset += filp->f_pos;
break;
case SEEK_END:
offset = ((dd->kregend - dd->kregbase) + DC8051_DATA_MEM_SIZE) -
offset;
break;
default:
return -EINVAL;
}
if (offset < 0)
return -EINVAL;
if (offset >= (dd->kregend - dd->kregbase) + DC8051_DATA_MEM_SIZE)
return -EINVAL;
filp->f_pos = offset;
return filp->f_pos;
}
static ssize_t ui_read(struct file *filp, char __user *buf, size_t count,
loff_t *f_pos)
{
struct hfi1_devdata *dd = filp->private_data;
void __iomem *base = dd->kregbase;
unsigned long total, csr_off,
barlen = (dd->kregend - dd->kregbase);
u64 data;
if ((count % 8) != 0)
return -EINVAL;
if ((*f_pos % 8) != 0)
return -EINVAL;
if ((unsigned long)buf % 8 != 0)
return -EINVAL;
if (*f_pos + count > (barlen + DC8051_DATA_MEM_SIZE))
return -EINVAL;
if (*f_pos < barlen)
base += *f_pos;
csr_off = *f_pos;
for (total = 0; total < count; total += 8, csr_off += 8) {
if (is_lcb_offset(csr_off)) {
if (read_lcb_csr(dd, csr_off, (u64 *)&data))
break;
}
else if (csr_off == ASIC_GPIO_CLEAR
|| csr_off == ASIC_GPIO_FORCE
|| csr_off == ASIC_QSFP1_CLEAR
|| csr_off == ASIC_QSFP1_FORCE
|| csr_off == ASIC_QSFP2_CLEAR
|| csr_off == ASIC_QSFP2_FORCE)
data = 0;
else if (csr_off >= barlen) {
if (read_8051_data(dd,
(u32)(csr_off - barlen),
sizeof(data), &data))
break;
} else
data = readq(base + total);
if (put_user(data, (unsigned long __user *)(buf + total)))
break;
}
*f_pos += total;
return total;
}
static ssize_t ui_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
struct hfi1_devdata *dd = filp->private_data;
void __iomem *base;
unsigned long total, data, csr_off;
int in_lcb;
if ((count % 8) != 0)
return -EINVAL;
if ((*f_pos % 8) != 0)
return -EINVAL;
if ((unsigned long)buf % 8 != 0)
return -EINVAL;
if (*f_pos + count > dd->kregend - dd->kregbase)
return -EINVAL;
base = (void __iomem *)dd->kregbase + *f_pos;
csr_off = *f_pos;
in_lcb = 0;
for (total = 0; total < count; total += 8, csr_off += 8) {
if (get_user(data, (unsigned long __user *)(buf + total)))
break;
if (is_lcb_offset(csr_off)) {
if (!in_lcb) {
int ret = acquire_lcb_access(dd, 1);
if (ret)
break;
in_lcb = 1;
}
} else {
if (in_lcb) {
release_lcb_access(dd, 1);
in_lcb = 0;
}
}
writeq(data, base + total);
}
if (in_lcb)
release_lcb_access(dd, 1);
*f_pos += total;
return total;
}
static void user_remove(struct hfi1_devdata *dd)
{
if (atomic_dec_return(&user_count) == 0)
hfi1_cdev_cleanup(&wildcard_cdev, &wildcard_device);
hfi1_cdev_cleanup(&dd->user_cdev, &dd->user_device);
hfi1_cdev_cleanup(&dd->ui_cdev, &dd->ui_device);
}
static int user_add(struct hfi1_devdata *dd)
{
char name[10];
int ret;
if (atomic_inc_return(&user_count) == 1) {
ret = hfi1_cdev_init(0, class_name(), &hfi1_file_ops,
&wildcard_cdev, &wildcard_device,
true);
if (ret)
goto done;
}
snprintf(name, sizeof(name), "%s_%d", class_name(), dd->unit);
ret = hfi1_cdev_init(dd->unit + 1, name, &hfi1_file_ops,
&dd->user_cdev, &dd->user_device,
true);
if (ret)
goto done;
if (create_ui) {
snprintf(name, sizeof(name),
"%s_ui%d", class_name(), dd->unit);
ret = hfi1_cdev_init(dd->unit + UI_OFFSET, name, &ui_file_ops,
&dd->ui_cdev, &dd->ui_device,
false);
if (ret)
goto done;
}
return 0;
done:
user_remove(dd);
return ret;
}
int hfi1_device_create(struct hfi1_devdata *dd)
{
int r, ret;
r = user_add(dd);
ret = hfi1_diag_add(dd);
if (r && !ret)
ret = r;
return ret;
}
void hfi1_device_remove(struct hfi1_devdata *dd)
{
user_remove(dd);
hfi1_diag_remove(dd);
}
