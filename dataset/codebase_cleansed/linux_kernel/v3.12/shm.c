void shm_init_ns(struct ipc_namespace *ns)
{
ns->shm_ctlmax = SHMMAX;
ns->shm_ctlall = SHMALL;
ns->shm_ctlmni = SHMMNI;
ns->shm_rmid_forced = 0;
ns->shm_tot = 0;
ipc_init_ids(&shm_ids(ns));
}
static void do_shm_rmid(struct ipc_namespace *ns, struct kern_ipc_perm *ipcp)
{
struct shmid_kernel *shp;
shp = container_of(ipcp, struct shmid_kernel, shm_perm);
if (shp->shm_nattch){
shp->shm_perm.mode |= SHM_DEST;
shp->shm_perm.key = IPC_PRIVATE;
shm_unlock(shp);
} else
shm_destroy(ns, shp);
}
void shm_exit_ns(struct ipc_namespace *ns)
{
free_ipcs(ns, &shm_ids(ns), do_shm_rmid);
idr_destroy(&ns->ids[IPC_SHM_IDS].ipcs_idr);
}
static int __init ipc_ns_init(void)
{
shm_init_ns(&init_ipc_ns);
return 0;
}
void __init shm_init (void)
{
ipc_init_proc_interface("sysvipc/shm",
#if BITS_PER_LONG <= 32
" key shmid perms size cpid lpid nattch uid gid cuid cgid atime dtime ctime rss swap\n",
#else
" key shmid perms size cpid lpid nattch uid gid cuid cgid atime dtime ctime rss swap\n",
#endif
IPC_SHM_IDS, sysvipc_shm_proc_show);
}
static inline struct shmid_kernel *shm_obtain_object(struct ipc_namespace *ns, int id)
{
struct kern_ipc_perm *ipcp = ipc_obtain_object(&shm_ids(ns), id);
if (IS_ERR(ipcp))
return ERR_CAST(ipcp);
return container_of(ipcp, struct shmid_kernel, shm_perm);
}
static inline struct shmid_kernel *shm_obtain_object_check(struct ipc_namespace *ns, int id)
{
struct kern_ipc_perm *ipcp = ipc_obtain_object_check(&shm_ids(ns), id);
if (IS_ERR(ipcp))
return ERR_CAST(ipcp);
return container_of(ipcp, struct shmid_kernel, shm_perm);
}
static inline struct shmid_kernel *shm_lock(struct ipc_namespace *ns, int id)
{
struct kern_ipc_perm *ipcp = ipc_lock(&shm_ids(ns), id);
if (IS_ERR(ipcp))
return (struct shmid_kernel *)ipcp;
return container_of(ipcp, struct shmid_kernel, shm_perm);
}
static inline void shm_lock_by_ptr(struct shmid_kernel *ipcp)
{
rcu_read_lock();
ipc_lock_object(&ipcp->shm_perm);
}
static void shm_rcu_free(struct rcu_head *head)
{
struct ipc_rcu *p = container_of(head, struct ipc_rcu, rcu);
struct shmid_kernel *shp = ipc_rcu_to_struct(p);
security_shm_free(shp);
ipc_rcu_free(head);
}
static inline void shm_rmid(struct ipc_namespace *ns, struct shmid_kernel *s)
{
ipc_rmid(&shm_ids(ns), &s->shm_perm);
}
static void shm_open(struct vm_area_struct *vma)
{
struct file *file = vma->vm_file;
struct shm_file_data *sfd = shm_file_data(file);
struct shmid_kernel *shp;
shp = shm_lock(sfd->ns, sfd->id);
BUG_ON(IS_ERR(shp));
shp->shm_atim = get_seconds();
shp->shm_lprid = task_tgid_vnr(current);
shp->shm_nattch++;
shm_unlock(shp);
}
static void shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
ns->shm_tot -= (shp->shm_segsz + PAGE_SIZE - 1) >> PAGE_SHIFT;
shm_rmid(ns, shp);
shm_unlock(shp);
if (!is_file_hugepages(shp->shm_file))
shmem_lock(shp->shm_file, 0, shp->mlock_user);
else if (shp->mlock_user)
user_shm_unlock(file_inode(shp->shm_file)->i_size,
shp->mlock_user);
fput (shp->shm_file);
ipc_rcu_putref(shp, shm_rcu_free);
}
static bool shm_may_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
return (shp->shm_nattch == 0) &&
(ns->shm_rmid_forced ||
(shp->shm_perm.mode & SHM_DEST));
}
static void shm_close(struct vm_area_struct *vma)
{
struct file * file = vma->vm_file;
struct shm_file_data *sfd = shm_file_data(file);
struct shmid_kernel *shp;
struct ipc_namespace *ns = sfd->ns;
down_write(&shm_ids(ns).rwsem);
shp = shm_lock(ns, sfd->id);
BUG_ON(IS_ERR(shp));
shp->shm_lprid = task_tgid_vnr(current);
shp->shm_dtim = get_seconds();
shp->shm_nattch--;
if (shm_may_destroy(ns, shp))
shm_destroy(ns, shp);
else
shm_unlock(shp);
up_write(&shm_ids(ns).rwsem);
}
static int shm_try_destroy_current(int id, void *p, void *data)
{
struct ipc_namespace *ns = data;
struct kern_ipc_perm *ipcp = p;
struct shmid_kernel *shp = container_of(ipcp, struct shmid_kernel, shm_perm);
if (shp->shm_creator != current)
return 0;
shp->shm_creator = NULL;
if (!ns->shm_rmid_forced)
return 0;
if (shm_may_destroy(ns, shp)) {
shm_lock_by_ptr(shp);
shm_destroy(ns, shp);
}
return 0;
}
static int shm_try_destroy_orphaned(int id, void *p, void *data)
{
struct ipc_namespace *ns = data;
struct kern_ipc_perm *ipcp = p;
struct shmid_kernel *shp = container_of(ipcp, struct shmid_kernel, shm_perm);
if (shp->shm_creator != NULL)
return 0;
if (shm_may_destroy(ns, shp)) {
shm_lock_by_ptr(shp);
shm_destroy(ns, shp);
}
return 0;
}
void shm_destroy_orphaned(struct ipc_namespace *ns)
{
down_write(&shm_ids(ns).rwsem);
if (shm_ids(ns).in_use)
idr_for_each(&shm_ids(ns).ipcs_idr, &shm_try_destroy_orphaned, ns);
up_write(&shm_ids(ns).rwsem);
}
void exit_shm(struct task_struct *task)
{
struct ipc_namespace *ns = task->nsproxy->ipc_ns;
if (shm_ids(ns).in_use == 0)
return;
down_write(&shm_ids(ns).rwsem);
if (shm_ids(ns).in_use)
idr_for_each(&shm_ids(ns).ipcs_idr, &shm_try_destroy_current, ns);
up_write(&shm_ids(ns).rwsem);
}
static int shm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct file *file = vma->vm_file;
struct shm_file_data *sfd = shm_file_data(file);
return sfd->vm_ops->fault(vma, vmf);
}
static int shm_set_policy(struct vm_area_struct *vma, struct mempolicy *new)
{
struct file *file = vma->vm_file;
struct shm_file_data *sfd = shm_file_data(file);
int err = 0;
if (sfd->vm_ops->set_policy)
err = sfd->vm_ops->set_policy(vma, new);
return err;
}
static struct mempolicy *shm_get_policy(struct vm_area_struct *vma,
unsigned long addr)
{
struct file *file = vma->vm_file;
struct shm_file_data *sfd = shm_file_data(file);
struct mempolicy *pol = NULL;
if (sfd->vm_ops->get_policy)
pol = sfd->vm_ops->get_policy(vma, addr);
else if (vma->vm_policy)
pol = vma->vm_policy;
return pol;
}
static int shm_mmap(struct file * file, struct vm_area_struct * vma)
{
struct shm_file_data *sfd = shm_file_data(file);
int ret;
ret = sfd->file->f_op->mmap(sfd->file, vma);
if (ret != 0)
return ret;
sfd->vm_ops = vma->vm_ops;
#ifdef CONFIG_MMU
BUG_ON(!sfd->vm_ops->fault);
#endif
vma->vm_ops = &shm_vm_ops;
shm_open(vma);
return ret;
}
static int shm_release(struct inode *ino, struct file *file)
{
struct shm_file_data *sfd = shm_file_data(file);
put_ipc_ns(sfd->ns);
shm_file_data(file) = NULL;
kfree(sfd);
return 0;
}
static int shm_fsync(struct file *file, loff_t start, loff_t end, int datasync)
{
struct shm_file_data *sfd = shm_file_data(file);
if (!sfd->file->f_op->fsync)
return -EINVAL;
return sfd->file->f_op->fsync(sfd->file, start, end, datasync);
}
static long shm_fallocate(struct file *file, int mode, loff_t offset,
loff_t len)
{
struct shm_file_data *sfd = shm_file_data(file);
if (!sfd->file->f_op->fallocate)
return -EOPNOTSUPP;
return sfd->file->f_op->fallocate(file, mode, offset, len);
}
static unsigned long shm_get_unmapped_area(struct file *file,
unsigned long addr, unsigned long len, unsigned long pgoff,
unsigned long flags)
{
struct shm_file_data *sfd = shm_file_data(file);
return sfd->file->f_op->get_unmapped_area(sfd->file, addr, len,
pgoff, flags);
}
int is_file_shm_hugepages(struct file *file)
{
return file->f_op == &shm_file_operations_huge;
}
static int newseg(struct ipc_namespace *ns, struct ipc_params *params)
{
key_t key = params->key;
int shmflg = params->flg;
size_t size = params->u.size;
int error;
struct shmid_kernel *shp;
size_t numpages = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
struct file * file;
char name[13];
int id;
vm_flags_t acctflag = 0;
if (size < SHMMIN || size > ns->shm_ctlmax)
return -EINVAL;
if (ns->shm_tot + numpages > ns->shm_ctlall)
return -ENOSPC;
shp = ipc_rcu_alloc(sizeof(*shp));
if (!shp)
return -ENOMEM;
shp->shm_perm.key = key;
shp->shm_perm.mode = (shmflg & S_IRWXUGO);
shp->mlock_user = NULL;
shp->shm_perm.security = NULL;
error = security_shm_alloc(shp);
if (error) {
ipc_rcu_putref(shp, ipc_rcu_free);
return error;
}
sprintf (name, "SYSV%08x", key);
if (shmflg & SHM_HUGETLB) {
struct hstate *hs;
size_t hugesize;
hs = hstate_sizelog((shmflg >> SHM_HUGE_SHIFT) & SHM_HUGE_MASK);
if (!hs) {
error = -EINVAL;
goto no_file;
}
hugesize = ALIGN(size, huge_page_size(hs));
if (shmflg & SHM_NORESERVE)
acctflag = VM_NORESERVE;
file = hugetlb_file_setup(name, hugesize, acctflag,
&shp->mlock_user, HUGETLB_SHMFS_INODE,
(shmflg >> SHM_HUGE_SHIFT) & SHM_HUGE_MASK);
} else {
if ((shmflg & SHM_NORESERVE) &&
sysctl_overcommit_memory != OVERCOMMIT_NEVER)
acctflag = VM_NORESERVE;
file = shmem_file_setup(name, size, acctflag);
}
error = PTR_ERR(file);
if (IS_ERR(file))
goto no_file;
id = ipc_addid(&shm_ids(ns), &shp->shm_perm, ns->shm_ctlmni);
if (id < 0) {
error = id;
goto no_id;
}
shp->shm_cprid = task_tgid_vnr(current);
shp->shm_lprid = 0;
shp->shm_atim = shp->shm_dtim = 0;
shp->shm_ctim = get_seconds();
shp->shm_segsz = size;
shp->shm_nattch = 0;
shp->shm_file = file;
shp->shm_creator = current;
file_inode(file)->i_ino = shp->shm_perm.id;
ns->shm_tot += numpages;
error = shp->shm_perm.id;
ipc_unlock_object(&shp->shm_perm);
rcu_read_unlock();
return error;
no_id:
if (is_file_hugepages(file) && shp->mlock_user)
user_shm_unlock(size, shp->mlock_user);
fput(file);
no_file:
ipc_rcu_putref(shp, shm_rcu_free);
return error;
}
static inline int shm_security(struct kern_ipc_perm *ipcp, int shmflg)
{
struct shmid_kernel *shp;
shp = container_of(ipcp, struct shmid_kernel, shm_perm);
return security_shm_associate(shp, shmflg);
}
static inline int shm_more_checks(struct kern_ipc_perm *ipcp,
struct ipc_params *params)
{
struct shmid_kernel *shp;
shp = container_of(ipcp, struct shmid_kernel, shm_perm);
if (shp->shm_segsz < params->u.size)
return -EINVAL;
return 0;
}
static inline unsigned long copy_shmid_to_user(void __user *buf, struct shmid64_ds *in, int version)
{
switch(version) {
case IPC_64:
return copy_to_user(buf, in, sizeof(*in));
case IPC_OLD:
{
struct shmid_ds out;
memset(&out, 0, sizeof(out));
ipc64_perm_to_ipc_perm(&in->shm_perm, &out.shm_perm);
out.shm_segsz = in->shm_segsz;
out.shm_atime = in->shm_atime;
out.shm_dtime = in->shm_dtime;
out.shm_ctime = in->shm_ctime;
out.shm_cpid = in->shm_cpid;
out.shm_lpid = in->shm_lpid;
out.shm_nattch = in->shm_nattch;
return copy_to_user(buf, &out, sizeof(out));
}
default:
return -EINVAL;
}
}
static inline unsigned long
copy_shmid_from_user(struct shmid64_ds *out, void __user *buf, int version)
{
switch(version) {
case IPC_64:
if (copy_from_user(out, buf, sizeof(*out)))
return -EFAULT;
return 0;
case IPC_OLD:
{
struct shmid_ds tbuf_old;
if (copy_from_user(&tbuf_old, buf, sizeof(tbuf_old)))
return -EFAULT;
out->shm_perm.uid = tbuf_old.shm_perm.uid;
out->shm_perm.gid = tbuf_old.shm_perm.gid;
out->shm_perm.mode = tbuf_old.shm_perm.mode;
return 0;
}
default:
return -EINVAL;
}
}
static inline unsigned long copy_shminfo_to_user(void __user *buf, struct shminfo64 *in, int version)
{
switch(version) {
case IPC_64:
return copy_to_user(buf, in, sizeof(*in));
case IPC_OLD:
{
struct shminfo out;
if(in->shmmax > INT_MAX)
out.shmmax = INT_MAX;
else
out.shmmax = (int)in->shmmax;
out.shmmin = in->shmmin;
out.shmmni = in->shmmni;
out.shmseg = in->shmseg;
out.shmall = in->shmall;
return copy_to_user(buf, &out, sizeof(out));
}
default:
return -EINVAL;
}
}
static void shm_add_rss_swap(struct shmid_kernel *shp,
unsigned long *rss_add, unsigned long *swp_add)
{
struct inode *inode;
inode = file_inode(shp->shm_file);
if (is_file_hugepages(shp->shm_file)) {
struct address_space *mapping = inode->i_mapping;
struct hstate *h = hstate_file(shp->shm_file);
*rss_add += pages_per_huge_page(h) * mapping->nrpages;
} else {
#ifdef CONFIG_SHMEM
struct shmem_inode_info *info = SHMEM_I(inode);
spin_lock(&info->lock);
*rss_add += inode->i_mapping->nrpages;
*swp_add += info->swapped;
spin_unlock(&info->lock);
#else
*rss_add += inode->i_mapping->nrpages;
#endif
}
}
static void shm_get_stat(struct ipc_namespace *ns, unsigned long *rss,
unsigned long *swp)
{
int next_id;
int total, in_use;
*rss = 0;
*swp = 0;
in_use = shm_ids(ns).in_use;
for (total = 0, next_id = 0; total < in_use; next_id++) {
struct kern_ipc_perm *ipc;
struct shmid_kernel *shp;
ipc = idr_find(&shm_ids(ns).ipcs_idr, next_id);
if (ipc == NULL)
continue;
shp = container_of(ipc, struct shmid_kernel, shm_perm);
shm_add_rss_swap(shp, rss, swp);
total++;
}
}
static int shmctl_down(struct ipc_namespace *ns, int shmid, int cmd,
struct shmid_ds __user *buf, int version)
{
struct kern_ipc_perm *ipcp;
struct shmid64_ds shmid64;
struct shmid_kernel *shp;
int err;
if (cmd == IPC_SET) {
if (copy_shmid_from_user(&shmid64, buf, version))
return -EFAULT;
}
down_write(&shm_ids(ns).rwsem);
rcu_read_lock();
ipcp = ipcctl_pre_down_nolock(ns, &shm_ids(ns), shmid, cmd,
&shmid64.shm_perm, 0);
if (IS_ERR(ipcp)) {
err = PTR_ERR(ipcp);
goto out_unlock1;
}
shp = container_of(ipcp, struct shmid_kernel, shm_perm);
err = security_shm_shmctl(shp, cmd);
if (err)
goto out_unlock1;
switch (cmd) {
case IPC_RMID:
ipc_lock_object(&shp->shm_perm);
do_shm_rmid(ns, ipcp);
goto out_up;
case IPC_SET:
ipc_lock_object(&shp->shm_perm);
err = ipc_update_perm(&shmid64.shm_perm, ipcp);
if (err)
goto out_unlock0;
shp->shm_ctim = get_seconds();
break;
default:
err = -EINVAL;
goto out_unlock1;
}
out_unlock0:
ipc_unlock_object(&shp->shm_perm);
out_unlock1:
rcu_read_unlock();
out_up:
up_write(&shm_ids(ns).rwsem);
return err;
}
static int shmctl_nolock(struct ipc_namespace *ns, int shmid,
int cmd, int version, void __user *buf)
{
int err;
struct shmid_kernel *shp;
if (cmd == IPC_INFO || cmd == SHM_INFO) {
err = security_shm_shmctl(NULL, cmd);
if (err)
return err;
}
switch (cmd) {
case IPC_INFO:
{
struct shminfo64 shminfo;
memset(&shminfo, 0, sizeof(shminfo));
shminfo.shmmni = shminfo.shmseg = ns->shm_ctlmni;
shminfo.shmmax = ns->shm_ctlmax;
shminfo.shmall = ns->shm_ctlall;
shminfo.shmmin = SHMMIN;
if(copy_shminfo_to_user (buf, &shminfo, version))
return -EFAULT;
down_read(&shm_ids(ns).rwsem);
err = ipc_get_maxid(&shm_ids(ns));
up_read(&shm_ids(ns).rwsem);
if(err<0)
err = 0;
goto out;
}
case SHM_INFO:
{
struct shm_info shm_info;
memset(&shm_info, 0, sizeof(shm_info));
down_read(&shm_ids(ns).rwsem);
shm_info.used_ids = shm_ids(ns).in_use;
shm_get_stat (ns, &shm_info.shm_rss, &shm_info.shm_swp);
shm_info.shm_tot = ns->shm_tot;
shm_info.swap_attempts = 0;
shm_info.swap_successes = 0;
err = ipc_get_maxid(&shm_ids(ns));
up_read(&shm_ids(ns).rwsem);
if (copy_to_user(buf, &shm_info, sizeof(shm_info))) {
err = -EFAULT;
goto out;
}
err = err < 0 ? 0 : err;
goto out;
}
case SHM_STAT:
case IPC_STAT:
{
struct shmid64_ds tbuf;
int result;
rcu_read_lock();
if (cmd == SHM_STAT) {
shp = shm_obtain_object(ns, shmid);
if (IS_ERR(shp)) {
err = PTR_ERR(shp);
goto out_unlock;
}
result = shp->shm_perm.id;
} else {
shp = shm_obtain_object_check(ns, shmid);
if (IS_ERR(shp)) {
err = PTR_ERR(shp);
goto out_unlock;
}
result = 0;
}
err = -EACCES;
if (ipcperms(ns, &shp->shm_perm, S_IRUGO))
goto out_unlock;
err = security_shm_shmctl(shp, cmd);
if (err)
goto out_unlock;
memset(&tbuf, 0, sizeof(tbuf));
kernel_to_ipc64_perm(&shp->shm_perm, &tbuf.shm_perm);
tbuf.shm_segsz = shp->shm_segsz;
tbuf.shm_atime = shp->shm_atim;
tbuf.shm_dtime = shp->shm_dtim;
tbuf.shm_ctime = shp->shm_ctim;
tbuf.shm_cpid = shp->shm_cprid;
tbuf.shm_lpid = shp->shm_lprid;
tbuf.shm_nattch = shp->shm_nattch;
rcu_read_unlock();
if (copy_shmid_to_user(buf, &tbuf, version))
err = -EFAULT;
else
err = result;
goto out;
}
default:
return -EINVAL;
}
out_unlock:
rcu_read_unlock();
out:
return err;
}
long do_shmat(int shmid, char __user *shmaddr, int shmflg, ulong *raddr,
unsigned long shmlba)
{
struct shmid_kernel *shp;
unsigned long addr;
unsigned long size;
struct file * file;
int err;
unsigned long flags;
unsigned long prot;
int acc_mode;
struct ipc_namespace *ns;
struct shm_file_data *sfd;
struct path path;
fmode_t f_mode;
unsigned long populate = 0;
err = -EINVAL;
if (shmid < 0)
goto out;
else if ((addr = (ulong)shmaddr)) {
if (addr & (shmlba - 1)) {
if (shmflg & SHM_RND)
addr &= ~(shmlba - 1);
else
#ifndef __ARCH_FORCE_SHMLBA
if (addr & ~PAGE_MASK)
#endif
goto out;
}
flags = MAP_SHARED | MAP_FIXED;
} else {
if ((shmflg & SHM_REMAP))
goto out;
flags = MAP_SHARED;
}
if (shmflg & SHM_RDONLY) {
prot = PROT_READ;
acc_mode = S_IRUGO;
f_mode = FMODE_READ;
} else {
prot = PROT_READ | PROT_WRITE;
acc_mode = S_IRUGO | S_IWUGO;
f_mode = FMODE_READ | FMODE_WRITE;
}
if (shmflg & SHM_EXEC) {
prot |= PROT_EXEC;
acc_mode |= S_IXUGO;
}
ns = current->nsproxy->ipc_ns;
rcu_read_lock();
shp = shm_obtain_object_check(ns, shmid);
if (IS_ERR(shp)) {
err = PTR_ERR(shp);
goto out_unlock;
}
err = -EACCES;
if (ipcperms(ns, &shp->shm_perm, acc_mode))
goto out_unlock;
err = security_shm_shmat(shp, shmaddr, shmflg);
if (err)
goto out_unlock;
ipc_lock_object(&shp->shm_perm);
path = shp->shm_file->f_path;
path_get(&path);
shp->shm_nattch++;
size = i_size_read(path.dentry->d_inode);
ipc_unlock_object(&shp->shm_perm);
rcu_read_unlock();
err = -ENOMEM;
sfd = kzalloc(sizeof(*sfd), GFP_KERNEL);
if (!sfd) {
path_put(&path);
goto out_nattch;
}
file = alloc_file(&path, f_mode,
is_file_hugepages(shp->shm_file) ?
&shm_file_operations_huge :
&shm_file_operations);
err = PTR_ERR(file);
if (IS_ERR(file)) {
kfree(sfd);
path_put(&path);
goto out_nattch;
}
file->private_data = sfd;
file->f_mapping = shp->shm_file->f_mapping;
sfd->id = shp->shm_perm.id;
sfd->ns = get_ipc_ns(ns);
sfd->file = shp->shm_file;
sfd->vm_ops = NULL;
err = security_mmap_file(file, prot, flags);
if (err)
goto out_fput;
down_write(&current->mm->mmap_sem);
if (addr && !(shmflg & SHM_REMAP)) {
err = -EINVAL;
if (find_vma_intersection(current->mm, addr, addr + size))
goto invalid;
if (addr < current->mm->start_stack &&
addr > current->mm->start_stack - size - PAGE_SIZE * 5)
goto invalid;
}
addr = do_mmap_pgoff(file, addr, size, prot, flags, 0, &populate);
*raddr = addr;
err = 0;
if (IS_ERR_VALUE(addr))
err = (long)addr;
invalid:
up_write(&current->mm->mmap_sem);
if (populate)
mm_populate(addr, populate);
out_fput:
fput(file);
out_nattch:
down_write(&shm_ids(ns).rwsem);
shp = shm_lock(ns, shmid);
BUG_ON(IS_ERR(shp));
shp->shm_nattch--;
if (shm_may_destroy(ns, shp))
shm_destroy(ns, shp);
else
shm_unlock(shp);
up_write(&shm_ids(ns).rwsem);
return err;
out_unlock:
rcu_read_unlock();
out:
return err;
}
static int sysvipc_shm_proc_show(struct seq_file *s, void *it)
{
struct user_namespace *user_ns = seq_user_ns(s);
struct shmid_kernel *shp = it;
unsigned long rss = 0, swp = 0;
shm_add_rss_swap(shp, &rss, &swp);
#if BITS_PER_LONG <= 32
#define SIZE_SPEC "%10lu"
#else
#define SIZE_SPEC "%21lu"
#endif
return seq_printf(s,
"%10d %10d %4o " SIZE_SPEC " %5u %5u "
"%5lu %5u %5u %5u %5u %10lu %10lu %10lu "
SIZE_SPEC " " SIZE_SPEC "\n",
shp->shm_perm.key,
shp->shm_perm.id,
shp->shm_perm.mode,
shp->shm_segsz,
shp->shm_cprid,
shp->shm_lprid,
shp->shm_nattch,
from_kuid_munged(user_ns, shp->shm_perm.uid),
from_kgid_munged(user_ns, shp->shm_perm.gid),
from_kuid_munged(user_ns, shp->shm_perm.cuid),
from_kgid_munged(user_ns, shp->shm_perm.cgid),
shp->shm_atim,
shp->shm_dtim,
shp->shm_ctim,
rss * PAGE_SIZE,
swp * PAGE_SIZE);
}
