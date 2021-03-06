static int
mraid_mm_open(struct inode *inode, struct file *filep)
{
if (!capable(CAP_SYS_ADMIN)) return (-EACCES);
return 0;
}
static int
mraid_mm_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
uioc_t *kioc;
char signature[EXT_IOCTL_SIGN_SZ] = {0};
int rval;
mraid_mmadp_t *adp;
uint8_t old_ioctl;
int drvrcmd_rval;
void __user *argp = (void __user *)arg;
if ((_IOC_TYPE(cmd) != MEGAIOC_MAGIC) && (cmd != USCSICMD)) {
return (-EINVAL);
}
if (copy_from_user(signature, argp, EXT_IOCTL_SIGN_SZ)) {
con_log(CL_ANN, (KERN_WARNING
"megaraid cmm: copy from usr addr failed\n"));
return (-EFAULT);
}
if (memcmp(signature, EXT_IOCTL_SIGN, EXT_IOCTL_SIGN_SZ) == 0)
old_ioctl = 0;
else
old_ioctl = 1;
if (!old_ioctl )
return (-EINVAL);
rval = handle_drvrcmd(argp, old_ioctl, &drvrcmd_rval);
if (rval < 0)
return rval;
else if (rval == 0)
return drvrcmd_rval;
rval = 0;
if ((adp = mraid_mm_get_adapter(argp, &rval)) == NULL) {
return rval;
}
if (!adp->quiescent) {
con_log(CL_ANN, (KERN_WARNING
"megaraid cmm: controller cannot accept cmds due to "
"earlier errors\n" ));
return -EFAULT;
}
kioc = mraid_mm_alloc_kioc(adp);
if (!kioc)
return -ENXIO;
if ((rval = mimd_to_kioc(argp, adp, kioc))) {
mraid_mm_dealloc_kioc(adp, kioc);
return rval;
}
kioc->done = ioctl_done;
if ((rval = lld_ioctl(adp, kioc))) {
if (!kioc->timedout)
mraid_mm_dealloc_kioc(adp, kioc);
return rval;
}
rval = kioc_to_mimd(kioc, argp);
mraid_mm_dealloc_kioc(adp, kioc);
return rval;
}
static long
mraid_mm_unlocked_ioctl(struct file *filep, unsigned int cmd,
unsigned long arg)
{
int err;
mutex_lock(&mraid_mm_mutex);
err = mraid_mm_ioctl(filep, cmd, arg);
mutex_unlock(&mraid_mm_mutex);
return err;
}
static mraid_mmadp_t *
mraid_mm_get_adapter(mimd_t __user *umimd, int *rval)
{
mraid_mmadp_t *adapter;
mimd_t mimd;
uint32_t adapno;
int iterator;
if (copy_from_user(&mimd, umimd, sizeof(mimd_t))) {
*rval = -EFAULT;
return NULL;
}
adapno = GETADAP(mimd.ui.fcs.adapno);
if (adapno >= adapters_count_g) {
*rval = -ENODEV;
return NULL;
}
adapter = NULL;
iterator = 0;
list_for_each_entry(adapter, &adapters_list_g, list) {
if (iterator++ == adapno) break;
}
if (!adapter) {
*rval = -ENODEV;
return NULL;
}
return adapter;
}
static int
handle_drvrcmd(void __user *arg, uint8_t old_ioctl, int *rval)
{
mimd_t __user *umimd;
mimd_t kmimd;
uint8_t opcode;
uint8_t subopcode;
if (old_ioctl)
goto old_packet;
else
goto new_packet;
new_packet:
return (-ENOTSUPP);
old_packet:
*rval = 0;
umimd = arg;
if (copy_from_user(&kmimd, umimd, sizeof(mimd_t)))
return (-EFAULT);
opcode = kmimd.ui.fcs.opcode;
subopcode = kmimd.ui.fcs.subopcode;
if (opcode != 0x82)
return 1;
switch (subopcode) {
case MEGAIOC_QDRVRVER:
if (copy_to_user(kmimd.data, &drvr_ver, sizeof(uint32_t)))
return (-EFAULT);
return 0;
case MEGAIOC_QNADAP:
*rval = adapters_count_g;
if (copy_to_user(kmimd.data, &adapters_count_g,
sizeof(uint32_t)))
return (-EFAULT);
return 0;
default:
return 1;
}
return 0;
}
static int
mimd_to_kioc(mimd_t __user *umimd, mraid_mmadp_t *adp, uioc_t *kioc)
{
mbox64_t *mbox64;
mbox_t *mbox;
mraid_passthru_t *pthru32;
uint32_t adapno;
uint8_t opcode;
uint8_t subopcode;
mimd_t mimd;
if (copy_from_user(&mimd, umimd, sizeof(mimd_t)))
return (-EFAULT);
if ((mimd.mbox[0] == MBOXCMD_PASSTHRU64) ||
(mimd.mbox[0] == MBOXCMD_EXTPTHRU))
return (-EINVAL);
opcode = mimd.ui.fcs.opcode;
subopcode = mimd.ui.fcs.subopcode;
adapno = GETADAP(mimd.ui.fcs.adapno);
if (adapno >= adapters_count_g)
return (-ENODEV);
kioc->adapno = adapno;
kioc->mb_type = MBOX_LEGACY;
kioc->app_type = APPTYPE_MIMD;
switch (opcode) {
case 0x82:
if (subopcode == MEGAIOC_QADAPINFO) {
kioc->opcode = GET_ADAP_INFO;
kioc->data_dir = UIOC_RD;
kioc->xferlen = sizeof(mraid_hba_info_t);
if (mraid_mm_attach_buf(adp, kioc, kioc->xferlen))
return (-ENOMEM);
}
else {
con_log(CL_ANN, (KERN_WARNING
"megaraid cmm: Invalid subop\n"));
return (-EINVAL);
}
break;
case 0x81:
kioc->opcode = MBOX_CMD;
kioc->xferlen = mimd.ui.fcs.length;
kioc->user_data_len = kioc->xferlen;
kioc->user_data = mimd.ui.fcs.buffer;
if (mraid_mm_attach_buf(adp, kioc, kioc->xferlen))
return (-ENOMEM);
if (mimd.outlen) kioc->data_dir = UIOC_RD;
if (mimd.inlen) kioc->data_dir |= UIOC_WR;
break;
case 0x80:
kioc->opcode = MBOX_CMD;
kioc->xferlen = (mimd.outlen > mimd.inlen) ?
mimd.outlen : mimd.inlen;
kioc->user_data_len = kioc->xferlen;
kioc->user_data = mimd.data;
if (mraid_mm_attach_buf(adp, kioc, kioc->xferlen))
return (-ENOMEM);
if (mimd.outlen) kioc->data_dir = UIOC_RD;
if (mimd.inlen) kioc->data_dir |= UIOC_WR;
break;
default:
return (-EINVAL);
}
if (opcode == 0x82)
return 0;
mbox64 = (mbox64_t *)((unsigned long)kioc->cmdbuf);
mbox = &mbox64->mbox32;
memcpy(mbox, mimd.mbox, 14);
if (mbox->cmd != MBOXCMD_PASSTHRU) {
mbox->xferaddr = (uint32_t)kioc->buf_paddr;
if (kioc->data_dir & UIOC_WR) {
if (copy_from_user(kioc->buf_vaddr, kioc->user_data,
kioc->xferlen)) {
return (-EFAULT);
}
}
return 0;
}
pthru32 = kioc->pthru32;
kioc->user_pthru = &umimd->pthru;
mbox->xferaddr = (uint32_t)kioc->pthru32_h;
if (copy_from_user(pthru32, kioc->user_pthru,
sizeof(mraid_passthru_t))) {
return (-EFAULT);
}
pthru32->dataxferaddr = kioc->buf_paddr;
if (kioc->data_dir & UIOC_WR) {
if (pthru32->dataxferlen > kioc->xferlen)
return -EINVAL;
if (copy_from_user(kioc->buf_vaddr, kioc->user_data,
pthru32->dataxferlen)) {
return (-EFAULT);
}
}
return 0;
}
static int
mraid_mm_attach_buf(mraid_mmadp_t *adp, uioc_t *kioc, int xferlen)
{
mm_dmapool_t *pool;
int right_pool = -1;
unsigned long flags;
int i;
kioc->pool_index = -1;
kioc->buf_vaddr = NULL;
kioc->buf_paddr = 0;
kioc->free_buf = 0;
for (i = 0; i < MAX_DMA_POOLS; i++) {
pool = &adp->dma_pool_list[i];
if (xferlen > pool->buf_size)
continue;
if (right_pool == -1)
right_pool = i;
spin_lock_irqsave(&pool->lock, flags);
if (!pool->in_use) {
pool->in_use = 1;
kioc->pool_index = i;
kioc->buf_vaddr = pool->vaddr;
kioc->buf_paddr = pool->paddr;
spin_unlock_irqrestore(&pool->lock, flags);
return 0;
}
else {
spin_unlock_irqrestore(&pool->lock, flags);
continue;
}
}
if (right_pool == -1)
return -EINVAL;
pool = &adp->dma_pool_list[right_pool];
spin_lock_irqsave(&pool->lock, flags);
kioc->pool_index = right_pool;
kioc->free_buf = 1;
kioc->buf_vaddr = pci_pool_alloc(pool->handle, GFP_KERNEL,
&kioc->buf_paddr);
spin_unlock_irqrestore(&pool->lock, flags);
if (!kioc->buf_vaddr)
return -ENOMEM;
return 0;
}
static uioc_t *
mraid_mm_alloc_kioc(mraid_mmadp_t *adp)
{
uioc_t *kioc;
struct list_head* head;
unsigned long flags;
down(&adp->kioc_semaphore);
spin_lock_irqsave(&adp->kioc_pool_lock, flags);
head = &adp->kioc_pool;
if (list_empty(head)) {
up(&adp->kioc_semaphore);
spin_unlock_irqrestore(&adp->kioc_pool_lock, flags);
con_log(CL_ANN, ("megaraid cmm: kioc list empty!\n"));
return NULL;
}
kioc = list_entry(head->next, uioc_t, list);
list_del_init(&kioc->list);
spin_unlock_irqrestore(&adp->kioc_pool_lock, flags);
memset((caddr_t)(unsigned long)kioc->cmdbuf, 0, sizeof(mbox64_t));
memset((caddr_t) kioc->pthru32, 0, sizeof(mraid_passthru_t));
kioc->buf_vaddr = NULL;
kioc->buf_paddr = 0;
kioc->pool_index =-1;
kioc->free_buf = 0;
kioc->user_data = NULL;
kioc->user_data_len = 0;
kioc->user_pthru = NULL;
kioc->timedout = 0;
return kioc;
}
static void
mraid_mm_dealloc_kioc(mraid_mmadp_t *adp, uioc_t *kioc)
{
mm_dmapool_t *pool;
unsigned long flags;
if (kioc->pool_index != -1) {
pool = &adp->dma_pool_list[kioc->pool_index];
spin_lock_irqsave(&pool->lock, flags);
if (kioc->free_buf == 1)
pci_pool_free(pool->handle, kioc->buf_vaddr,
kioc->buf_paddr);
else
pool->in_use = 0;
spin_unlock_irqrestore(&pool->lock, flags);
}
spin_lock_irqsave(&adp->kioc_pool_lock, flags);
list_add(&kioc->list, &adp->kioc_pool);
spin_unlock_irqrestore(&adp->kioc_pool_lock, flags);
up(&adp->kioc_semaphore);
return;
}
static int
lld_ioctl(mraid_mmadp_t *adp, uioc_t *kioc)
{
int rval;
struct timer_list timer;
struct timer_list *tp = NULL;
kioc->status = -ENODATA;
rval = adp->issue_uioc(adp->drvr_data, kioc, IOCTL_ISSUE);
if (rval) return rval;
if (adp->timeout > 0) {
tp = &timer;
init_timer(tp);
tp->function = lld_timedout;
tp->data = (unsigned long)kioc;
tp->expires = jiffies + adp->timeout * HZ;
add_timer(tp);
}
wait_event(wait_q, (kioc->status != -ENODATA));
if (tp) {
del_timer_sync(tp);
}
if (kioc->timedout) {
adp->quiescent = 0;
}
return kioc->status;
}
static void
ioctl_done(uioc_t *kioc)
{
uint32_t adapno;
int iterator;
mraid_mmadp_t* adapter;
if (kioc->status == -ENODATA) {
con_log(CL_ANN, (KERN_WARNING
"megaraid cmm: lld didn't change status!\n"));
kioc->status = -EINVAL;
}
if (kioc->timedout) {
iterator = 0;
adapter = NULL;
adapno = kioc->adapno;
con_log(CL_ANN, ( KERN_WARNING "megaraid cmm: completed "
"ioctl that was timedout before\n"));
list_for_each_entry(adapter, &adapters_list_g, list) {
if (iterator++ == adapno) break;
}
kioc->timedout = 0;
if (adapter) {
mraid_mm_dealloc_kioc( adapter, kioc );
}
}
else {
wake_up(&wait_q);
}
}
static void
lld_timedout(unsigned long ptr)
{
uioc_t *kioc = (uioc_t *)ptr;
kioc->status = -ETIME;
kioc->timedout = 1;
con_log(CL_ANN, (KERN_WARNING "megaraid cmm: ioctl timed out\n"));
wake_up(&wait_q);
}
static int
kioc_to_mimd(uioc_t *kioc, mimd_t __user *mimd)
{
mimd_t kmimd;
uint8_t opcode;
uint8_t subopcode;
mbox64_t *mbox64;
mraid_passthru_t __user *upthru32;
mraid_passthru_t *kpthru32;
mcontroller_t cinfo;
mraid_hba_info_t *hinfo;
if (copy_from_user(&kmimd, mimd, sizeof(mimd_t)))
return (-EFAULT);
opcode = kmimd.ui.fcs.opcode;
subopcode = kmimd.ui.fcs.subopcode;
if (opcode == 0x82) {
switch (subopcode) {
case MEGAIOC_QADAPINFO:
hinfo = (mraid_hba_info_t *)(unsigned long)
kioc->buf_vaddr;
hinfo_to_cinfo(hinfo, &cinfo);
if (copy_to_user(kmimd.data, &cinfo, sizeof(cinfo)))
return (-EFAULT);
return 0;
default:
return (-EINVAL);
}
return 0;
}
mbox64 = (mbox64_t *)(unsigned long)kioc->cmdbuf;
if (kioc->user_pthru) {
upthru32 = kioc->user_pthru;
kpthru32 = kioc->pthru32;
if (copy_to_user(&upthru32->scsistatus,
&kpthru32->scsistatus,
sizeof(uint8_t))) {
return (-EFAULT);
}
}
if (kioc->user_data) {
if (copy_to_user(kioc->user_data, kioc->buf_vaddr,
kioc->user_data_len)) {
return (-EFAULT);
}
}
if (copy_to_user(&mimd->mbox[17],
&mbox64->mbox32.status, sizeof(uint8_t))) {
return (-EFAULT);
}
return 0;
}
static void
hinfo_to_cinfo(mraid_hba_info_t *hinfo, mcontroller_t *cinfo)
{
if (!hinfo || !cinfo)
return;
cinfo->base = hinfo->baseport;
cinfo->irq = hinfo->irq;
cinfo->numldrv = hinfo->num_ldrv;
cinfo->pcibus = hinfo->pci_bus;
cinfo->pcidev = hinfo->pci_slot;
cinfo->pcifun = PCI_FUNC(hinfo->pci_dev_fn);
cinfo->pciid = hinfo->pci_device_id;
cinfo->pcivendor = hinfo->pci_vendor_id;
cinfo->pcislot = hinfo->pci_slot;
cinfo->uid = hinfo->unique_id;
}
int
mraid_mm_register_adp(mraid_mmadp_t *lld_adp)
{
mraid_mmadp_t *adapter;
mbox64_t *mbox_list;
uioc_t *kioc;
uint32_t rval;
int i;
if (lld_adp->drvr_type != DRVRTYPE_MBOX)
return (-EINVAL);
adapter = kzalloc(sizeof(mraid_mmadp_t), GFP_KERNEL);
if (!adapter)
return -ENOMEM;
adapter->unique_id = lld_adp->unique_id;
adapter->drvr_type = lld_adp->drvr_type;
adapter->drvr_data = lld_adp->drvr_data;
adapter->pdev = lld_adp->pdev;
adapter->issue_uioc = lld_adp->issue_uioc;
adapter->timeout = lld_adp->timeout;
adapter->max_kioc = lld_adp->max_kioc;
adapter->quiescent = 1;
adapter->kioc_list = kmalloc(sizeof(uioc_t) * lld_adp->max_kioc,
GFP_KERNEL);
adapter->mbox_list = kmalloc(sizeof(mbox64_t) * lld_adp->max_kioc,
GFP_KERNEL);
adapter->pthru_dma_pool = pci_pool_create("megaraid mm pthru pool",
adapter->pdev,
sizeof(mraid_passthru_t),
16, 0);
if (!adapter->kioc_list || !adapter->mbox_list ||
!adapter->pthru_dma_pool) {
con_log(CL_ANN, (KERN_WARNING
"megaraid cmm: out of memory, %s %d\n", __func__,
__LINE__));
rval = (-ENOMEM);
goto memalloc_error;
}
INIT_LIST_HEAD(&adapter->kioc_pool);
spin_lock_init(&adapter->kioc_pool_lock);
sema_init(&adapter->kioc_semaphore, lld_adp->max_kioc);
mbox_list = (mbox64_t *)adapter->mbox_list;
for (i = 0; i < lld_adp->max_kioc; i++) {
kioc = adapter->kioc_list + i;
kioc->cmdbuf = (uint64_t)(unsigned long)(mbox_list + i);
kioc->pthru32 = pci_pool_alloc(adapter->pthru_dma_pool,
GFP_KERNEL, &kioc->pthru32_h);
if (!kioc->pthru32) {
con_log(CL_ANN, (KERN_WARNING
"megaraid cmm: out of memory, %s %d\n",
__func__, __LINE__));
rval = (-ENOMEM);
goto pthru_dma_pool_error;
}
list_add_tail(&kioc->list, &adapter->kioc_pool);
}
if ((rval = mraid_mm_setup_dma_pools(adapter)) != 0) {
goto dma_pool_error;
}
list_add_tail(&adapter->list, &adapters_list_g);
adapters_count_g++;
return 0;
dma_pool_error:
pthru_dma_pool_error:
for (i = 0; i < lld_adp->max_kioc; i++) {
kioc = adapter->kioc_list + i;
if (kioc->pthru32) {
pci_pool_free(adapter->pthru_dma_pool, kioc->pthru32,
kioc->pthru32_h);
}
}
memalloc_error:
kfree(adapter->kioc_list);
kfree(adapter->mbox_list);
if (adapter->pthru_dma_pool)
pci_pool_destroy(adapter->pthru_dma_pool);
kfree(adapter);
return rval;
}
uint32_t
mraid_mm_adapter_app_handle(uint32_t unique_id)
{
mraid_mmadp_t *adapter;
mraid_mmadp_t *tmp;
int index = 0;
list_for_each_entry_safe(adapter, tmp, &adapters_list_g, list) {
if (adapter->unique_id == unique_id) {
return MKADAP(index);
}
index++;
}
return 0;
}
static int
mraid_mm_setup_dma_pools(mraid_mmadp_t *adp)
{
mm_dmapool_t *pool;
int bufsize;
int i;
bufsize = MRAID_MM_INIT_BUFF_SIZE;
for (i = 0; i < MAX_DMA_POOLS; i++){
pool = &adp->dma_pool_list[i];
pool->buf_size = bufsize;
spin_lock_init(&pool->lock);
pool->handle = pci_pool_create("megaraid mm data buffer",
adp->pdev, bufsize, 16, 0);
if (!pool->handle) {
goto dma_pool_setup_error;
}
pool->vaddr = pci_pool_alloc(pool->handle, GFP_KERNEL,
&pool->paddr);
if (!pool->vaddr)
goto dma_pool_setup_error;
bufsize = bufsize * 2;
}
return 0;
dma_pool_setup_error:
mraid_mm_teardown_dma_pools(adp);
return (-ENOMEM);
}
int
mraid_mm_unregister_adp(uint32_t unique_id)
{
mraid_mmadp_t *adapter;
mraid_mmadp_t *tmp;
list_for_each_entry_safe(adapter, tmp, &adapters_list_g, list) {
if (adapter->unique_id == unique_id) {
adapters_count_g--;
list_del_init(&adapter->list);
mraid_mm_free_adp_resources(adapter);
kfree(adapter);
con_log(CL_ANN, (
"megaraid cmm: Unregistered one adapter:%#x\n",
unique_id));
return 0;
}
}
return (-ENODEV);
}
static void
mraid_mm_free_adp_resources(mraid_mmadp_t *adp)
{
uioc_t *kioc;
int i;
mraid_mm_teardown_dma_pools(adp);
for (i = 0; i < adp->max_kioc; i++) {
kioc = adp->kioc_list + i;
pci_pool_free(adp->pthru_dma_pool, kioc->pthru32,
kioc->pthru32_h);
}
kfree(adp->kioc_list);
kfree(adp->mbox_list);
pci_pool_destroy(adp->pthru_dma_pool);
return;
}
static void
mraid_mm_teardown_dma_pools(mraid_mmadp_t *adp)
{
int i;
mm_dmapool_t *pool;
for (i = 0; i < MAX_DMA_POOLS; i++) {
pool = &adp->dma_pool_list[i];
if (pool->handle) {
if (pool->vaddr)
pci_pool_free(pool->handle, pool->vaddr,
pool->paddr);
pci_pool_destroy(pool->handle);
pool->handle = NULL;
}
}
return;
}
static int __init
mraid_mm_init(void)
{
int err;
con_log(CL_ANN, (KERN_INFO "megaraid cmm: %s %s\n",
LSI_COMMON_MOD_VERSION, LSI_COMMON_MOD_EXT_VERSION));
err = misc_register(&megaraid_mm_dev);
if (err < 0) {
con_log(CL_ANN, ("megaraid cmm: cannot register misc device\n"));
return err;
}
init_waitqueue_head(&wait_q);
INIT_LIST_HEAD(&adapters_list_g);
return 0;
}
static long
mraid_mm_compat_ioctl(struct file *filep, unsigned int cmd,
unsigned long arg)
{
int err;
err = mraid_mm_ioctl(filep, cmd, arg);
return err;
}
static void __exit
mraid_mm_exit(void)
{
con_log(CL_DLEVEL1 , ("exiting common mod\n"));
misc_deregister(&megaraid_mm_dev);
}
