static int ioctl_send_fib(struct aac_dev * dev, void __user *arg)
{
struct hw_fib * kfib;
struct fib *fibptr;
struct hw_fib * hw_fib = (struct hw_fib *)0;
dma_addr_t hw_fib_pa = (dma_addr_t)0LL;
unsigned int size, osize;
int retval;
if (dev->in_reset) {
return -EBUSY;
}
fibptr = aac_fib_alloc(dev);
if(fibptr == NULL) {
return -ENOMEM;
}
kfib = fibptr->hw_fib_va;
if (copy_from_user((void *)kfib, arg, sizeof(struct aac_fibhdr))) {
aac_fib_free(fibptr);
return -EFAULT;
}
osize = size = le16_to_cpu(kfib->header.Size) +
sizeof(struct aac_fibhdr);
if (size < le16_to_cpu(kfib->header.SenderSize))
size = le16_to_cpu(kfib->header.SenderSize);
if (size > dev->max_fib_size) {
dma_addr_t daddr;
if (size > 2048) {
retval = -EINVAL;
goto cleanup;
}
kfib = pci_alloc_consistent(dev->pdev, size, &daddr);
if (!kfib) {
retval = -ENOMEM;
goto cleanup;
}
hw_fib = fibptr->hw_fib_va;
hw_fib_pa = fibptr->hw_fib_pa;
fibptr->hw_fib_va = kfib;
fibptr->hw_fib_pa = daddr;
memset(((char *)kfib) + dev->max_fib_size, 0, size - dev->max_fib_size);
memcpy(kfib, hw_fib, dev->max_fib_size);
}
if (copy_from_user(kfib, arg, size)) {
retval = -EFAULT;
goto cleanup;
}
if ((osize != le16_to_cpu(kfib->header.Size) +
sizeof(struct aac_fibhdr))
|| (size < le16_to_cpu(kfib->header.SenderSize))) {
retval = -EINVAL;
goto cleanup;
}
if (kfib->header.Command == cpu_to_le16(TakeABreakPt)) {
aac_adapter_interrupt(dev);
kfib->header.XferState = 0;
} else {
retval = aac_fib_send(le16_to_cpu(kfib->header.Command), fibptr,
le16_to_cpu(kfib->header.Size) , FsaNormal,
1, 1, NULL, NULL);
if (retval) {
goto cleanup;
}
if (aac_fib_complete(fibptr) != 0) {
retval = -EINVAL;
goto cleanup;
}
}
retval = 0;
if (copy_to_user(arg, (void *)kfib, size))
retval = -EFAULT;
cleanup:
if (hw_fib) {
pci_free_consistent(dev->pdev, size, kfib, fibptr->hw_fib_pa);
fibptr->hw_fib_pa = hw_fib_pa;
fibptr->hw_fib_va = hw_fib;
}
if (retval != -ERESTARTSYS)
aac_fib_free(fibptr);
return retval;
}
static int open_getadapter_fib(struct aac_dev * dev, void __user *arg)
{
struct aac_fib_context * fibctx;
int status;
fibctx = kmalloc(sizeof(struct aac_fib_context), GFP_KERNEL);
if (fibctx == NULL) {
status = -ENOMEM;
} else {
unsigned long flags;
struct list_head * entry;
struct aac_fib_context * context;
fibctx->type = FSAFS_NTC_GET_ADAPTER_FIB_CONTEXT;
fibctx->size = sizeof(struct aac_fib_context);
fibctx->unique = (u32)((ulong)fibctx & 0xFFFFFFFF);
sema_init(&fibctx->wait_sem, 0);
fibctx->wait = 0;
fibctx->count = 0;
INIT_LIST_HEAD(&fibctx->fib_list);
fibctx->jiffies = jiffies/HZ;
spin_lock_irqsave(&dev->fib_lock, flags);
entry = dev->fib_list.next;
while (entry != &dev->fib_list) {
context = list_entry(entry, struct aac_fib_context, next);
if (context->unique == fibctx->unique) {
fibctx->unique++;
entry = dev->fib_list.next;
} else {
entry = entry->next;
}
}
list_add_tail(&fibctx->next, &dev->fib_list);
spin_unlock_irqrestore(&dev->fib_lock, flags);
if (copy_to_user(arg, &fibctx->unique,
sizeof(fibctx->unique))) {
status = -EFAULT;
} else {
status = 0;
}
}
return status;
}
static int next_getadapter_fib(struct aac_dev * dev, void __user *arg)
{
struct fib_ioctl f;
struct fib *fib;
struct aac_fib_context *fibctx;
int status;
struct list_head * entry;
unsigned long flags;
if(copy_from_user((void *)&f, arg, sizeof(struct fib_ioctl)))
return -EFAULT;
spin_lock_irqsave(&dev->fib_lock, flags);
entry = dev->fib_list.next;
fibctx = NULL;
while (entry != &dev->fib_list) {
fibctx = list_entry(entry, struct aac_fib_context, next);
if (fibctx->unique == f.fibctx) {
break;
}
entry = entry->next;
fibctx = NULL;
}
if (!fibctx) {
spin_unlock_irqrestore(&dev->fib_lock, flags);
dprintk ((KERN_INFO "Fib Context not found\n"));
return -EINVAL;
}
if((fibctx->type != FSAFS_NTC_GET_ADAPTER_FIB_CONTEXT) ||
(fibctx->size != sizeof(struct aac_fib_context))) {
spin_unlock_irqrestore(&dev->fib_lock, flags);
dprintk ((KERN_INFO "Fib Context corrupt?\n"));
return -EINVAL;
}
status = 0;
return_fib:
if (!list_empty(&fibctx->fib_list)) {
entry = fibctx->fib_list.next;
list_del(entry);
fib = list_entry(entry, struct fib, fiblink);
fibctx->count--;
spin_unlock_irqrestore(&dev->fib_lock, flags);
if (copy_to_user(f.fib, fib->hw_fib_va, sizeof(struct hw_fib))) {
kfree(fib->hw_fib_va);
kfree(fib);
return -EFAULT;
}
kfree(fib->hw_fib_va);
kfree(fib);
status = 0;
} else {
spin_unlock_irqrestore(&dev->fib_lock, flags);
status = !dev->aif_thread;
if (status && !dev->in_reset && dev->queues && dev->fsa_dev) {
kthread_stop(dev->thread);
ssleep(1);
dev->aif_thread = 0;
dev->thread = kthread_run(aac_command_thread, dev,
"%s", dev->name);
ssleep(1);
}
if (f.wait) {
if(down_interruptible(&fibctx->wait_sem) < 0) {
status = -ERESTARTSYS;
} else {
spin_lock_irqsave(&dev->fib_lock, flags);
goto return_fib;
}
} else {
status = -EAGAIN;
}
}
fibctx->jiffies = jiffies/HZ;
return status;
}
int aac_close_fib_context(struct aac_dev * dev, struct aac_fib_context * fibctx)
{
struct fib *fib;
while (!list_empty(&fibctx->fib_list)) {
struct list_head * entry;
entry = fibctx->fib_list.next;
list_del(entry);
fib = list_entry(entry, struct fib, fiblink);
fibctx->count--;
kfree(fib->hw_fib_va);
kfree(fib);
}
list_del(&fibctx->next);
fibctx->type = 0;
kfree(fibctx);
return 0;
}
static int close_getadapter_fib(struct aac_dev * dev, void __user *arg)
{
struct aac_fib_context *fibctx;
int status;
unsigned long flags;
struct list_head * entry;
entry = dev->fib_list.next;
fibctx = NULL;
while(entry != &dev->fib_list) {
fibctx = list_entry(entry, struct aac_fib_context, next);
if (fibctx->unique == (u32)(uintptr_t)arg)
break;
entry = entry->next;
fibctx = NULL;
}
if (!fibctx)
return 0;
if((fibctx->type != FSAFS_NTC_GET_ADAPTER_FIB_CONTEXT) ||
(fibctx->size != sizeof(struct aac_fib_context)))
return -EINVAL;
spin_lock_irqsave(&dev->fib_lock, flags);
status = aac_close_fib_context(dev, fibctx);
spin_unlock_irqrestore(&dev->fib_lock, flags);
return status;
}
static int check_revision(struct aac_dev *dev, void __user *arg)
{
struct revision response;
char *driver_version = aac_driver_version;
u32 version;
response.compat = 1;
version = (simple_strtol(driver_version,
&driver_version, 10) << 24) | 0x00000400;
version += simple_strtol(driver_version + 1, &driver_version, 10) << 16;
version += simple_strtol(driver_version + 1, NULL, 10);
response.version = cpu_to_le32(version);
# ifdef AAC_DRIVER_BUILD
response.build = cpu_to_le32(AAC_DRIVER_BUILD);
# else
response.build = cpu_to_le32(9999);
# endif
if (copy_to_user(arg, &response, sizeof(response)))
return -EFAULT;
return 0;
}
static int aac_send_raw_srb(struct aac_dev* dev, void __user * arg)
{
struct fib* srbfib;
int status;
struct aac_srb *srbcmd = NULL;
struct user_aac_srb *user_srbcmd = NULL;
struct user_aac_srb __user *user_srb = arg;
struct aac_srb_reply __user *user_reply;
struct aac_srb_reply* reply;
u32 fibsize = 0;
u32 flags = 0;
s32 rcode = 0;
u32 data_dir;
void __user *sg_user[32];
void *sg_list[32];
u32 sg_indx = 0;
u32 byte_count = 0;
u32 actual_fibsize64, actual_fibsize = 0;
int i;
if (dev->in_reset) {
dprintk((KERN_DEBUG"aacraid: send raw srb -EBUSY\n"));
return -EBUSY;
}
if (!capable(CAP_SYS_ADMIN)){
dprintk((KERN_DEBUG"aacraid: No permission to send raw srb\n"));
return -EPERM;
}
if (!(srbfib = aac_fib_alloc(dev))) {
return -ENOMEM;
}
aac_fib_init(srbfib);
srbfib->hw_fib_va->header.XferState &= ~cpu_to_le32(FastResponseCapable);
srbcmd = (struct aac_srb*) fib_data(srbfib);
memset(sg_list, 0, sizeof(sg_list));
if(copy_from_user(&fibsize, &user_srb->count,sizeof(u32))){
dprintk((KERN_DEBUG"aacraid: Could not copy data size from user\n"));
rcode = -EFAULT;
goto cleanup;
}
if ((fibsize < (sizeof(struct user_aac_srb) - sizeof(struct user_sgentry))) ||
(fibsize > (dev->max_fib_size - sizeof(struct aac_fibhdr)))) {
rcode = -EINVAL;
goto cleanup;
}
user_srbcmd = kmalloc(fibsize, GFP_KERNEL);
if (!user_srbcmd) {
dprintk((KERN_DEBUG"aacraid: Could not make a copy of the srb\n"));
rcode = -ENOMEM;
goto cleanup;
}
if(copy_from_user(user_srbcmd, user_srb,fibsize)){
dprintk((KERN_DEBUG"aacraid: Could not copy srb from user\n"));
rcode = -EFAULT;
goto cleanup;
}
user_reply = arg+fibsize;
flags = user_srbcmd->flags;
srbcmd->function = cpu_to_le32(SRBF_ExecuteScsi);
srbcmd->channel = cpu_to_le32(user_srbcmd->channel);
srbcmd->id = cpu_to_le32(user_srbcmd->id);
srbcmd->lun = cpu_to_le32(user_srbcmd->lun);
srbcmd->timeout = cpu_to_le32(user_srbcmd->timeout);
srbcmd->flags = cpu_to_le32(flags);
srbcmd->retry_limit = 0;
srbcmd->cdb_size = cpu_to_le32(user_srbcmd->cdb_size);
memcpy(srbcmd->cdb, user_srbcmd->cdb, sizeof(srbcmd->cdb));
switch (flags & (SRB_DataIn | SRB_DataOut)) {
case SRB_DataOut:
data_dir = DMA_TO_DEVICE;
break;
case (SRB_DataIn | SRB_DataOut):
data_dir = DMA_BIDIRECTIONAL;
break;
case SRB_DataIn:
data_dir = DMA_FROM_DEVICE;
break;
default:
data_dir = DMA_NONE;
}
if (user_srbcmd->sg.count > ARRAY_SIZE(sg_list)) {
dprintk((KERN_DEBUG"aacraid: too many sg entries %d\n",
le32_to_cpu(srbcmd->sg.count)));
rcode = -EINVAL;
goto cleanup;
}
actual_fibsize = sizeof(struct aac_srb) - sizeof(struct sgentry) +
((user_srbcmd->sg.count & 0xff) * sizeof(struct sgentry));
actual_fibsize64 = actual_fibsize + (user_srbcmd->sg.count & 0xff) *
(sizeof(struct sgentry64) - sizeof(struct sgentry));
if ((actual_fibsize != fibsize) && (actual_fibsize64 != fibsize)) {
dprintk((KERN_DEBUG"aacraid: Bad Size specified in "
"Raw SRB command calculated fibsize=%lu;%lu "
"user_srbcmd->sg.count=%d aac_srb=%lu sgentry=%lu;%lu "
"issued fibsize=%d\n",
actual_fibsize, actual_fibsize64, user_srbcmd->sg.count,
sizeof(struct aac_srb), sizeof(struct sgentry),
sizeof(struct sgentry64), fibsize));
rcode = -EINVAL;
goto cleanup;
}
if ((data_dir == DMA_NONE) && user_srbcmd->sg.count) {
dprintk((KERN_DEBUG"aacraid: SG with no direction specified in Raw SRB command\n"));
rcode = -EINVAL;
goto cleanup;
}
byte_count = 0;
if (dev->adapter_info.options & AAC_OPT_SGMAP_HOST64) {
struct user_sgmap64* upsg = (struct user_sgmap64*)&user_srbcmd->sg;
struct sgmap64* psg = (struct sgmap64*)&srbcmd->sg;
if (actual_fibsize64 == fibsize) {
actual_fibsize = actual_fibsize64;
for (i = 0; i < upsg->count; i++) {
u64 addr;
void* p;
if (upsg->sg[i].count >
((dev->adapter_info.options &
AAC_OPT_NEW_COMM) ?
(dev->scsi_host_ptr->max_sectors << 9) :
65536)) {
rcode = -EINVAL;
goto cleanup;
}
p = kmalloc(upsg->sg[i].count,GFP_KERNEL|__GFP_DMA);
if(!p) {
dprintk((KERN_DEBUG"aacraid: Could not allocate SG buffer - size = %d buffer number %d of %d\n",
upsg->sg[i].count,i,upsg->count));
rcode = -ENOMEM;
goto cleanup;
}
addr = (u64)upsg->sg[i].addr[0];
addr += ((u64)upsg->sg[i].addr[1]) << 32;
sg_user[i] = (void __user *)(uintptr_t)addr;
sg_list[i] = p;
sg_indx = i;
if (flags & SRB_DataOut) {
if(copy_from_user(p,sg_user[i],upsg->sg[i].count)){
dprintk((KERN_DEBUG"aacraid: Could not copy sg data from user\n"));
rcode = -EFAULT;
goto cleanup;
}
}
addr = pci_map_single(dev->pdev, p, upsg->sg[i].count, data_dir);
psg->sg[i].addr[0] = cpu_to_le32(addr & 0xffffffff);
psg->sg[i].addr[1] = cpu_to_le32(addr>>32);
byte_count += upsg->sg[i].count;
psg->sg[i].count = cpu_to_le32(upsg->sg[i].count);
}
} else {
struct user_sgmap* usg;
usg = kmemdup(upsg,
actual_fibsize - sizeof(struct aac_srb)
+ sizeof(struct sgmap), GFP_KERNEL);
if (!usg) {
dprintk((KERN_DEBUG"aacraid: Allocation error in Raw SRB command\n"));
rcode = -ENOMEM;
goto cleanup;
}
actual_fibsize = actual_fibsize64;
for (i = 0; i < usg->count; i++) {
u64 addr;
void* p;
if (usg->sg[i].count >
((dev->adapter_info.options &
AAC_OPT_NEW_COMM) ?
(dev->scsi_host_ptr->max_sectors << 9) :
65536)) {
kfree(usg);
rcode = -EINVAL;
goto cleanup;
}
p = kmalloc(usg->sg[i].count,GFP_KERNEL|__GFP_DMA);
if(!p) {
dprintk((KERN_DEBUG "aacraid: Could not allocate SG buffer - size = %d buffer number %d of %d\n",
usg->sg[i].count,i,usg->count));
kfree(usg);
rcode = -ENOMEM;
goto cleanup;
}
sg_user[i] = (void __user *)(uintptr_t)usg->sg[i].addr;
sg_list[i] = p;
sg_indx = i;
if (flags & SRB_DataOut) {
if(copy_from_user(p,sg_user[i],upsg->sg[i].count)){
kfree (usg);
dprintk((KERN_DEBUG"aacraid: Could not copy sg data from user\n"));
rcode = -EFAULT;
goto cleanup;
}
}
addr = pci_map_single(dev->pdev, p, usg->sg[i].count, data_dir);
psg->sg[i].addr[0] = cpu_to_le32(addr & 0xffffffff);
psg->sg[i].addr[1] = cpu_to_le32(addr>>32);
byte_count += usg->sg[i].count;
psg->sg[i].count = cpu_to_le32(usg->sg[i].count);
}
kfree (usg);
}
srbcmd->count = cpu_to_le32(byte_count);
if (user_srbcmd->sg.count)
psg->count = cpu_to_le32(sg_indx+1);
else
psg->count = 0;
status = aac_fib_send(ScsiPortCommand64, srbfib, actual_fibsize, FsaNormal, 1, 1,NULL,NULL);
} else {
struct user_sgmap* upsg = &user_srbcmd->sg;
struct sgmap* psg = &srbcmd->sg;
if (actual_fibsize64 == fibsize) {
struct user_sgmap64* usg = (struct user_sgmap64 *)upsg;
for (i = 0; i < upsg->count; i++) {
uintptr_t addr;
void* p;
if (usg->sg[i].count >
((dev->adapter_info.options &
AAC_OPT_NEW_COMM) ?
(dev->scsi_host_ptr->max_sectors << 9) :
65536)) {
rcode = -EINVAL;
goto cleanup;
}
p = kmalloc(usg->sg[i].count,GFP_KERNEL|__GFP_DMA);
if(!p) {
dprintk((KERN_DEBUG"aacraid: Could not allocate SG buffer - size = %d buffer number %d of %d\n",
usg->sg[i].count,i,usg->count));
rcode = -ENOMEM;
goto cleanup;
}
addr = (u64)usg->sg[i].addr[0];
addr += ((u64)usg->sg[i].addr[1]) << 32;
sg_user[i] = (void __user *)addr;
sg_list[i] = p;
sg_indx = i;
if (flags & SRB_DataOut) {
if(copy_from_user(p,sg_user[i],usg->sg[i].count)){
dprintk((KERN_DEBUG"aacraid: Could not copy sg data from user\n"));
rcode = -EFAULT;
goto cleanup;
}
}
addr = pci_map_single(dev->pdev, p, usg->sg[i].count, data_dir);
psg->sg[i].addr = cpu_to_le32(addr & 0xffffffff);
byte_count += usg->sg[i].count;
psg->sg[i].count = cpu_to_le32(usg->sg[i].count);
}
} else {
for (i = 0; i < upsg->count; i++) {
dma_addr_t addr;
void* p;
if (upsg->sg[i].count >
((dev->adapter_info.options &
AAC_OPT_NEW_COMM) ?
(dev->scsi_host_ptr->max_sectors << 9) :
65536)) {
rcode = -EINVAL;
goto cleanup;
}
p = kmalloc(upsg->sg[i].count, GFP_KERNEL);
if (!p) {
dprintk((KERN_DEBUG"aacraid: Could not allocate SG buffer - size = %d buffer number %d of %d\n",
upsg->sg[i].count, i, upsg->count));
rcode = -ENOMEM;
goto cleanup;
}
sg_user[i] = (void __user *)(uintptr_t)upsg->sg[i].addr;
sg_list[i] = p;
sg_indx = i;
if (flags & SRB_DataOut) {
if(copy_from_user(p, sg_user[i],
upsg->sg[i].count)) {
dprintk((KERN_DEBUG"aacraid: Could not copy sg data from user\n"));
rcode = -EFAULT;
goto cleanup;
}
}
addr = pci_map_single(dev->pdev, p,
upsg->sg[i].count, data_dir);
psg->sg[i].addr = cpu_to_le32(addr);
byte_count += upsg->sg[i].count;
psg->sg[i].count = cpu_to_le32(upsg->sg[i].count);
}
}
srbcmd->count = cpu_to_le32(byte_count);
if (user_srbcmd->sg.count)
psg->count = cpu_to_le32(sg_indx+1);
else
psg->count = 0;
status = aac_fib_send(ScsiPortCommand, srbfib, actual_fibsize, FsaNormal, 1, 1, NULL, NULL);
}
if (status == -ERESTARTSYS) {
rcode = -ERESTARTSYS;
goto cleanup;
}
if (status != 0){
dprintk((KERN_DEBUG"aacraid: Could not send raw srb fib to hba\n"));
rcode = -ENXIO;
goto cleanup;
}
if (flags & SRB_DataIn) {
for(i = 0 ; i <= sg_indx; i++){
byte_count = le32_to_cpu(
(dev->adapter_info.options & AAC_OPT_SGMAP_HOST64)
? ((struct sgmap64*)&srbcmd->sg)->sg[i].count
: srbcmd->sg.sg[i].count);
if(copy_to_user(sg_user[i], sg_list[i], byte_count)){
dprintk((KERN_DEBUG"aacraid: Could not copy sg data to user\n"));
rcode = -EFAULT;
goto cleanup;
}
}
}
reply = (struct aac_srb_reply *) fib_data(srbfib);
if(copy_to_user(user_reply,reply,sizeof(struct aac_srb_reply))){
dprintk((KERN_DEBUG"aacraid: Could not copy reply to user\n"));
rcode = -EFAULT;
goto cleanup;
}
cleanup:
kfree(user_srbcmd);
for(i=0; i <= sg_indx; i++){
kfree(sg_list[i]);
}
if (rcode != -ERESTARTSYS) {
aac_fib_complete(srbfib);
aac_fib_free(srbfib);
}
return rcode;
}
static int aac_get_pci_info(struct aac_dev* dev, void __user *arg)
{
struct aac_pci_info pci_info;
pci_info.bus = dev->pdev->bus->number;
pci_info.slot = PCI_SLOT(dev->pdev->devfn);
if (copy_to_user(arg, &pci_info, sizeof(struct aac_pci_info))) {
dprintk((KERN_DEBUG "aacraid: Could not copy pci info\n"));
return -EFAULT;
}
return 0;
}
int aac_do_ioctl(struct aac_dev * dev, int cmd, void __user *arg)
{
int status;
mutex_lock(&dev->ioctl_mutex);
if (dev->adapter_shutdown) {
status = -EACCES;
goto cleanup;
}
status = aac_dev_ioctl(dev, cmd, arg);
if (status != -ENOTTY)
goto cleanup;
switch (cmd) {
case FSACTL_MINIPORT_REV_CHECK:
status = check_revision(dev, arg);
break;
case FSACTL_SEND_LARGE_FIB:
case FSACTL_SENDFIB:
status = ioctl_send_fib(dev, arg);
break;
case FSACTL_OPEN_GET_ADAPTER_FIB:
status = open_getadapter_fib(dev, arg);
break;
case FSACTL_GET_NEXT_ADAPTER_FIB:
status = next_getadapter_fib(dev, arg);
break;
case FSACTL_CLOSE_GET_ADAPTER_FIB:
status = close_getadapter_fib(dev, arg);
break;
case FSACTL_SEND_RAW_SRB:
status = aac_send_raw_srb(dev,arg);
break;
case FSACTL_GET_PCI_INFO:
status = aac_get_pci_info(dev,arg);
break;
default:
status = -ENOTTY;
break;
}
cleanup:
mutex_unlock(&dev->ioctl_mutex);
return status;
}
