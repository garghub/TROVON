static inline int is_valid_mmap(u64 token)
{
return (HFI1_MMAP_TOKEN_GET(MAGIC, token) == HFI1_MMAP_MAGIC);
}
static int hfi1_file_open(struct inode *inode, struct file *fp)
{
struct hfi1_filedata *fd;
struct hfi1_devdata *dd = container_of(inode->i_cdev,
struct hfi1_devdata,
user_cdev);
if (!atomic_inc_not_zero(&dd->user_refcount))
return -ENXIO;
kobject_get(&dd->kobj);
fd = kzalloc(sizeof(*fd), GFP_KERNEL);
if (fd) {
fd->rec_cpu_num = -1;
fd->mm = current->mm;
mmgrab(fd->mm);
fp->private_data = fd;
} else {
fp->private_data = NULL;
if (atomic_dec_and_test(&dd->user_refcount))
complete(&dd->user_comp);
return -ENOMEM;
}
return 0;
}
static long hfi1_file_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_user_info uinfo;
struct hfi1_tid_info tinfo;
int ret = 0;
unsigned long addr;
int uval = 0;
unsigned long ul_uval = 0;
u16 uval16 = 0;
hfi1_cdbg(IOCTL, "IOCTL recv: 0x%x", cmd);
if (cmd != HFI1_IOCTL_ASSIGN_CTXT &&
cmd != HFI1_IOCTL_GET_VERS &&
!uctxt)
return -EINVAL;
switch (cmd) {
case HFI1_IOCTL_ASSIGN_CTXT:
if (uctxt)
return -EINVAL;
if (copy_from_user(&uinfo,
(struct hfi1_user_info __user *)arg,
sizeof(uinfo)))
return -EFAULT;
ret = assign_ctxt(fp, &uinfo);
if (ret < 0)
return ret;
ret = setup_ctxt(fp);
if (ret)
return ret;
ret = user_init(fp);
break;
case HFI1_IOCTL_CTXT_INFO:
ret = get_ctxt_info(fp, (void __user *)(unsigned long)arg,
sizeof(struct hfi1_ctxt_info));
break;
case HFI1_IOCTL_USER_INFO:
ret = get_base_info(fp, (void __user *)(unsigned long)arg,
sizeof(struct hfi1_base_info));
break;
case HFI1_IOCTL_CREDIT_UPD:
if (uctxt)
sc_return_credits(uctxt->sc);
break;
case HFI1_IOCTL_TID_UPDATE:
if (copy_from_user(&tinfo,
(struct hfi11_tid_info __user *)arg,
sizeof(tinfo)))
return -EFAULT;
ret = hfi1_user_exp_rcv_setup(fp, &tinfo);
if (!ret) {
addr = arg + offsetof(struct hfi1_tid_info, tidcnt);
if (copy_to_user((void __user *)addr, &tinfo.tidcnt,
sizeof(tinfo.tidcnt) +
sizeof(tinfo.length)))
ret = -EFAULT;
}
break;
case HFI1_IOCTL_TID_FREE:
if (copy_from_user(&tinfo,
(struct hfi11_tid_info __user *)arg,
sizeof(tinfo)))
return -EFAULT;
ret = hfi1_user_exp_rcv_clear(fp, &tinfo);
if (ret)
break;
addr = arg + offsetof(struct hfi1_tid_info, tidcnt);
if (copy_to_user((void __user *)addr, &tinfo.tidcnt,
sizeof(tinfo.tidcnt)))
ret = -EFAULT;
break;
case HFI1_IOCTL_TID_INVAL_READ:
if (copy_from_user(&tinfo,
(struct hfi11_tid_info __user *)arg,
sizeof(tinfo)))
return -EFAULT;
ret = hfi1_user_exp_rcv_invalid(fp, &tinfo);
if (ret)
break;
addr = arg + offsetof(struct hfi1_tid_info, tidcnt);
if (copy_to_user((void __user *)addr, &tinfo.tidcnt,
sizeof(tinfo.tidcnt)))
ret = -EFAULT;
break;
case HFI1_IOCTL_RECV_CTRL:
ret = get_user(uval, (int __user *)arg);
if (ret != 0)
return -EFAULT;
ret = manage_rcvq(uctxt, fd->subctxt, uval);
break;
case HFI1_IOCTL_POLL_TYPE:
ret = get_user(uval, (int __user *)arg);
if (ret != 0)
return -EFAULT;
uctxt->poll_type = (typeof(uctxt->poll_type))uval;
break;
case HFI1_IOCTL_ACK_EVENT:
ret = get_user(ul_uval, (unsigned long __user *)arg);
if (ret != 0)
return -EFAULT;
ret = user_event_ack(uctxt, fd->subctxt, ul_uval);
break;
case HFI1_IOCTL_SET_PKEY:
ret = get_user(uval16, (u16 __user *)arg);
if (ret != 0)
return -EFAULT;
if (HFI1_CAP_IS_USET(PKEY_CHECK))
ret = set_ctxt_pkey(uctxt, fd->subctxt, uval16);
else
return -EPERM;
break;
case HFI1_IOCTL_CTXT_RESET: {
struct send_context *sc;
struct hfi1_devdata *dd;
if (!uctxt || !uctxt->dd || !uctxt->sc)
return -EINVAL;
dd = uctxt->dd;
sc = uctxt->sc;
wait_event_interruptible_timeout(
sc->halt_wait, (sc->flags & SCF_HALTED),
msecs_to_jiffies(SEND_CTXT_HALT_TIMEOUT));
if (!(sc->flags & SCF_HALTED))
return -ENOLCK;
if (sc->flags & SCF_FROZEN) {
wait_event_interruptible_timeout(
dd->event_queue,
!(ACCESS_ONCE(dd->flags) & HFI1_FROZEN),
msecs_to_jiffies(SEND_CTXT_HALT_TIMEOUT));
if (dd->flags & HFI1_FROZEN)
return -ENOLCK;
if (dd->flags & HFI1_FORCED_FREEZE)
return -ENODEV;
sc_disable(sc);
ret = sc_enable(sc);
hfi1_rcvctrl(dd, HFI1_RCVCTRL_CTXT_ENB,
uctxt->ctxt);
} else {
ret = sc_restart(sc);
}
if (!ret)
sc_return_credits(sc);
break;
}
case HFI1_IOCTL_GET_VERS:
uval = HFI1_USER_SWVERSION;
if (put_user(uval, (int __user *)arg))
return -EFAULT;
break;
default:
return -EINVAL;
}
return ret;
}
static ssize_t hfi1_write_iter(struct kiocb *kiocb, struct iov_iter *from)
{
struct hfi1_filedata *fd = kiocb->ki_filp->private_data;
struct hfi1_user_sdma_pkt_q *pq = fd->pq;
struct hfi1_user_sdma_comp_q *cq = fd->cq;
int done = 0, reqs = 0;
unsigned long dim = from->nr_segs;
if (!cq || !pq)
return -EIO;
if (!iter_is_iovec(from) || !dim)
return -EINVAL;
hfi1_cdbg(SDMA, "SDMA request from %u:%u (%lu)",
fd->uctxt->ctxt, fd->subctxt, dim);
if (atomic_read(&pq->n_reqs) == pq->n_max_reqs)
return -ENOSPC;
while (dim) {
int ret;
unsigned long count = 0;
ret = hfi1_user_sdma_process_request(
kiocb->ki_filp, (struct iovec *)(from->iov + done),
dim, &count);
if (ret) {
reqs = ret;
break;
}
dim -= count;
done += count;
reqs++;
}
return reqs;
}
static int hfi1_file_mmap(struct file *fp, struct vm_area_struct *vma)
{
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_devdata *dd;
unsigned long flags;
u64 token = vma->vm_pgoff << PAGE_SHIFT,
memaddr = 0;
void *memvirt = NULL;
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
memlen = PAGE_ALIGN(uctxt->sc->credits * PIO_BLOCK_SIZE);
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
memvirt = dd->cr_base[uctxt->numa_id].va;
memaddr = virt_to_phys(memvirt) +
(((u64)uctxt->sc->hw_free -
(u64)dd->cr_base[uctxt->numa_id].va) & PAGE_MASK);
memlen = PAGE_SIZE;
flags &= ~VM_MAYWRITE;
flags |= VM_DONTCOPY | VM_DONTEXPAND;
mapio = 1;
break;
case RCV_HDRQ:
memlen = uctxt->rcvhdrq_size;
memvirt = uctxt->rcvhdrq;
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
memlen = uctxt->egrbufs.buffers[i].len;
memvirt = uctxt->egrbufs.buffers[i].addr;
ret = remap_pfn_range(
vma, addr,
PFN_DOWN(__pa(memvirt)),
memlen,
vma->vm_page_prot);
if (ret < 0)
goto done;
addr += memlen;
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
memlen = PAGE_SIZE;
memvirt = (void *)uctxt->rcvhdrtail_kvaddr;
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
memlen = PAGE_ALIGN(sizeof(*cq->comps) * cq->nentries);
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
if (vmf) {
vma->vm_pgoff = PFN_DOWN(memaddr);
vma->vm_ops = &vm_ops;
ret = 0;
} else if (mapio) {
ret = io_remap_pfn_range(vma, vma->vm_start,
PFN_DOWN(memaddr),
memlen,
vma->vm_page_prot);
} else if (memvirt) {
ret = remap_pfn_range(vma, vma->vm_start,
PFN_DOWN(__pa(memvirt)),
memlen,
vma->vm_page_prot);
} else {
ret = remap_pfn_range(vma, vma->vm_start,
PFN_DOWN(memaddr),
memlen,
vma->vm_page_prot);
}
done:
return ret;
}
static int vma_fault(struct vm_fault *vmf)
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
struct hfi1_devdata *dd = container_of(inode->i_cdev,
struct hfi1_devdata,
user_cdev);
unsigned long flags, *ev;
fp->private_data = NULL;
if (!uctxt)
goto done;
hfi1_cdbg(PROC, "freeing ctxt %u:%u", uctxt->ctxt, fdata->subctxt);
mutex_lock(&hfi1_mutex);
flush_wc();
hfi1_user_sdma_free_queues(fdata);
hfi1_put_proc_affinity(fdata->rec_cpu_num);
ev = dd->events + ((uctxt->ctxt - dd->first_user_ctxt) *
HFI1_MAX_SHARED_CTXTS) + fdata->subctxt;
*ev = 0;
if (--uctxt->cnt) {
uctxt->active_slaves &= ~(1 << fdata->subctxt);
mutex_unlock(&hfi1_mutex);
goto done;
}
spin_lock_irqsave(&dd->uctxt_lock, flags);
hfi1_rcvctrl(dd, HFI1_RCVCTRL_CTXT_DIS |
HFI1_RCVCTRL_TIDFLOW_DIS |
HFI1_RCVCTRL_INTRAVAIL_DIS |
HFI1_RCVCTRL_TAILUPD_DIS |
HFI1_RCVCTRL_ONE_PKT_EGR_DIS |
HFI1_RCVCTRL_NO_RHQ_DROP_DIS |
HFI1_RCVCTRL_NO_EGR_DROP_DIS, uctxt->ctxt);
hfi1_clear_ctxt_jkey(dd, uctxt->ctxt);
write_kctxt_csr(dd, uctxt->sc->hw_context, SEND_CTXT_CHECK_ENABLE,
hfi1_pkt_default_send_ctxt_mask(dd, uctxt->sc->type));
sc_disable(uctxt->sc);
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
dd->rcd[uctxt->ctxt] = NULL;
hfi1_user_exp_rcv_free(fdata);
hfi1_clear_ctxt_pkey(dd, uctxt->ctxt);
uctxt->rcvwait_to = 0;
uctxt->piowait_to = 0;
uctxt->rcvnowait = 0;
uctxt->pionowait = 0;
uctxt->event_flags = 0;
hfi1_stats.sps_ctxts--;
if (++dd->freectxts == dd->num_user_contexts)
aspm_enable_all(dd);
mutex_unlock(&hfi1_mutex);
hfi1_free_ctxtdata(dd, uctxt);
done:
mmdrop(fdata->mm);
kobject_put(&dd->kobj);
if (atomic_dec_and_test(&dd->user_refcount))
complete(&dd->user_comp);
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
unsigned int swmajor, swminor;
swmajor = uinfo->userversion >> 16;
if (swmajor != HFI1_USER_SWMAJOR) {
ret = -ENODEV;
goto done;
}
swminor = uinfo->userversion & 0xffff;
mutex_lock(&hfi1_mutex);
if (uinfo->subctxt_cnt) {
struct hfi1_filedata *fd = fp->private_data;
ret = find_shared_ctxt(fp, uinfo);
if (ret < 0)
goto done_unlock;
if (ret) {
fd->rec_cpu_num =
hfi1_get_proc_affinity(fd->uctxt->numa_id);
}
}
if (!ret) {
i_minor = iminor(file_inode(fp)) - HFI1_USER_MINOR_BASE;
ret = get_user_context(fp, uinfo, i_minor);
}
done_unlock:
mutex_unlock(&hfi1_mutex);
done:
return ret;
}
static int get_user_context(struct file *fp, struct hfi1_user_info *uinfo,
int devno)
{
struct hfi1_devdata *dd = NULL;
int devmax, npresent, nup;
devmax = hfi1_count_units(&npresent, &nup);
if (!npresent)
return -ENXIO;
if (!nup)
return -ENETDOWN;
dd = hfi1_lookup(devno);
if (!dd)
return -ENODEV;
else if (!dd->freectxts)
return -EBUSY;
return allocate_ctxt(fp, dd, uinfo);
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
int ret, numa;
if (dd->flags & HFI1_FROZEN) {
return -EIO;
}
for (ctxt = dd->first_user_ctxt; ctxt < dd->num_rcv_contexts; ctxt++)
if (!dd->rcd[ctxt])
break;
if (ctxt == dd->num_rcv_contexts)
return -EBUSY;
fd->rec_cpu_num = hfi1_get_proc_affinity(dd->node);
if (fd->rec_cpu_num != -1)
numa = cpu_to_node(fd->rec_cpu_num);
else
numa = numa_node_id();
uctxt = hfi1_create_ctxtdata(dd->pport, ctxt, numa);
if (!uctxt) {
dd_dev_err(dd,
"Unable to allocate ctxtdata memory, failing open\n");
return -ENOMEM;
}
hfi1_cdbg(PROC, "[%u:%u] pid %u assigned to CPU %d (NUMA %u)",
uctxt->ctxt, fd->subctxt, current->pid, fd->rec_cpu_num,
uctxt->numa_id);
uctxt->sc = sc_alloc(dd, SC_USER, uctxt->rcvhdrqentsize,
uctxt->dd->node);
if (!uctxt->sc) {
ret = -ENOMEM;
goto ctxdata_free;
}
hfi1_cdbg(PROC, "allocated send context %u(%u)\n", uctxt->sc->sw_index,
uctxt->sc->hw_context);
ret = sc_enable(uctxt->sc);
if (ret)
goto ctxdata_free;
if (uinfo->subctxt_cnt && !fd->subctxt) {
ret = init_subctxts(uctxt, uinfo);
if (ret)
goto ctxdata_free;
}
uctxt->userversion = uinfo->userversion;
uctxt->flags = hfi1_cap_mask;
init_waitqueue_head(&uctxt->wait);
strlcpy(uctxt->comm, current->comm, sizeof(uctxt->comm));
memcpy(uctxt->uuid, uinfo->uuid, sizeof(uctxt->uuid));
uctxt->jkey = generate_jkey(current_uid());
INIT_LIST_HEAD(&uctxt->sdma_queues);
spin_lock_init(&uctxt->sdma_qlock);
hfi1_stats.sps_ctxts++;
if (dd->freectxts-- == dd->num_user_contexts)
aspm_disable_all(dd);
fd->uctxt = uctxt;
return 0;
ctxdata_free:
dd->rcd[ctxt] = NULL;
hfi1_free_ctxtdata(dd, uctxt);
return ret;
}
static int init_subctxts(struct hfi1_ctxtdata *uctxt,
const struct hfi1_user_info *uinfo)
{
unsigned num_subctxts;
num_subctxts = uinfo->subctxt_cnt;
if (num_subctxts > HFI1_MAX_SHARED_CTXTS)
return -EINVAL;
uctxt->subctxt_cnt = uinfo->subctxt_cnt;
uctxt->subctxt_id = uinfo->subctxt_id;
uctxt->active_slaves = 1;
uctxt->redirect_seq_cnt = 1;
set_bit(HFI1_CTXT_MASTER_UNINIT, &uctxt->event_flags);
return 0;
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
unsigned int rcvctrl_ops = 0;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
if (!test_bit(HFI1_CTXT_SETUP_DONE, &uctxt->event_flags))
return -EFAULT;
uctxt->urgent = 0;
uctxt->urgent_poll = 0;
if (uctxt->rcvhdrtail_kvaddr)
clear_rcvhdrtail(uctxt);
hfi1_set_ctxt_jkey(uctxt->dd, uctxt->ctxt, uctxt->jkey);
rcvctrl_ops = HFI1_RCVCTRL_CTXT_ENB;
if (HFI1_CAP_UGET_MASK(uctxt->flags, HDRSUPP))
rcvctrl_ops |= HFI1_RCVCTRL_TIDFLOW_ENB;
if (!HFI1_CAP_UGET_MASK(uctxt->flags, MULTI_PKT_EGR))
rcvctrl_ops |= HFI1_RCVCTRL_ONE_PKT_EGR_ENB;
if (HFI1_CAP_UGET_MASK(uctxt->flags, NODROP_EGR_FULL))
rcvctrl_ops |= HFI1_RCVCTRL_NO_EGR_DROP_ENB;
if (HFI1_CAP_UGET_MASK(uctxt->flags, NODROP_RHQ_FULL))
rcvctrl_ops |= HFI1_RCVCTRL_NO_RHQ_DROP_ENB;
if (HFI1_CAP_UGET_MASK(uctxt->flags, DMA_RTAIL))
rcvctrl_ops |= HFI1_RCVCTRL_TAILUPD_ENB;
else
rcvctrl_ops |= HFI1_RCVCTRL_TAILUPD_DIS;
hfi1_rcvctrl(uctxt->dd, rcvctrl_ops, uctxt->ctxt);
if (uctxt->subctxt_cnt) {
clear_bit(HFI1_CTXT_MASTER_UNINIT, &uctxt->event_flags);
wake_up(&uctxt->wait);
}
return 0;
}
static int get_ctxt_info(struct file *fp, void __user *ubase, __u32 len)
{
struct hfi1_ctxt_info cinfo;
struct hfi1_filedata *fd = fp->private_data;
struct hfi1_ctxtdata *uctxt = fd->uctxt;
int ret = 0;
memset(&cinfo, 0, sizeof(cinfo));
cinfo.runtime_flags = (((uctxt->flags >> HFI1_CAP_MISC_SHIFT) &
HFI1_CAP_MISC_MASK) << HFI1_CAP_USER_SHIFT) |
HFI1_CAP_UGET_MASK(uctxt->flags, MASK) |
HFI1_CAP_KGET_MASK(uctxt->flags, K2U);
if (!fd->handler)
cinfo.runtime_flags |= HFI1_CAP_TID_UNMAP;
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
} else {
ret = wait_event_interruptible(uctxt->wait, !test_bit(
HFI1_CTXT_MASTER_UNINIT,
&uctxt->event_flags));
if (ret)
goto done;
}
ret = hfi1_user_sdma_alloc_queues(uctxt, fp);
if (ret)
goto done;
ret = hfi1_user_exp_rcv_init(fp);
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
uctxt->egrbufs.rcvtids[0].dma);
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
} else {
pollflag = POLLIN | POLLRDNORM;
}
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
} else {
rcvctrl_op = HFI1_RCVCTRL_CTXT_DIS;
}
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
static void user_remove(struct hfi1_devdata *dd)
{
hfi1_cdev_cleanup(&dd->user_cdev, &dd->user_device);
}
static int user_add(struct hfi1_devdata *dd)
{
char name[10];
int ret;
snprintf(name, sizeof(name), "%s_%d", class_name(), dd->unit);
ret = hfi1_cdev_init(dd->unit, name, &hfi1_file_ops,
&dd->user_cdev, &dd->user_device,
true, &dd->kobj);
if (ret)
user_remove(dd);
return ret;
}
int hfi1_device_create(struct hfi1_devdata *dd)
{
return user_add(dd);
}
void hfi1_device_remove(struct hfi1_devdata *dd)
{
user_remove(dd);
}
