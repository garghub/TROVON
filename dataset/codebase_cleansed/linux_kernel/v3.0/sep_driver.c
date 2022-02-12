static void sep_dump_message(struct sep_device *sep)
{
int count;
u32 *p = sep->shared_addr;
for (count = 0; count < 12 * 4; count += 4)
dev_dbg(&sep->pdev->dev, "Word %d of the message is %x\n",
count, *p++);
}
static int sep_map_and_alloc_shared_area(struct sep_device *sep)
{
sep->shared_addr = dma_alloc_coherent(&sep->pdev->dev,
sep->shared_size,
&sep->shared_bus, GFP_KERNEL);
if (!sep->shared_addr) {
dev_warn(&sep->pdev->dev,
"shared memory dma_alloc_coherent failed\n");
return -ENOMEM;
}
dev_dbg(&sep->pdev->dev,
"shared_addr %zx bytes @%p (bus %llx)\n",
sep->shared_size, sep->shared_addr,
(unsigned long long)sep->shared_bus);
return 0;
}
static void sep_unmap_and_free_shared_area(struct sep_device *sep)
{
dma_free_coherent(&sep->pdev->dev, sep->shared_size,
sep->shared_addr, sep->shared_bus);
}
static void *sep_shared_bus_to_virt(struct sep_device *sep,
dma_addr_t bus_address)
{
return sep->shared_addr + (bus_address - sep->shared_bus);
}
static int sep_singleton_open(struct inode *inode_ptr, struct file *file_ptr)
{
struct sep_device *sep;
sep = sep_dev;
file_ptr->private_data = sep;
if (test_and_set_bit(0, &sep->singleton_access_flag))
return -EBUSY;
return 0;
}
static int sep_open(struct inode *inode, struct file *filp)
{
struct sep_device *sep;
sep = sep_dev;
filp->private_data = sep;
return 0;
}
static int sep_singleton_release(struct inode *inode, struct file *filp)
{
struct sep_device *sep = filp->private_data;
clear_bit(0, &sep->singleton_access_flag);
return 0;
}
static int sep_request_daemon_open(struct inode *inode, struct file *filp)
{
struct sep_device *sep = sep_dev;
int error = 0;
filp->private_data = sep;
if (test_and_set_bit(0, &sep->request_daemon_open))
error = -EBUSY;
return error;
}
static int sep_request_daemon_release(struct inode *inode, struct file *filp)
{
struct sep_device *sep = filp->private_data;
dev_dbg(&sep->pdev->dev, "Request daemon release for pid %d\n",
current->pid);
clear_bit(0, &sep->request_daemon_open);
return 0;
}
static int sep_req_daemon_send_reply_command_handler(struct sep_device *sep)
{
unsigned long lck_flags;
sep_dump_message(sep);
spin_lock_irqsave(&sep->snd_rply_lck, lck_flags);
sep->send_ct++;
sep->reply_ct++;
sep_write_reg(sep, HW_HOST_HOST_SEP_GPR2_REG_ADDR, sep->send_ct);
sep->send_ct++;
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
dev_dbg(&sep->pdev->dev,
"sep_req_daemon_send_reply send_ct %lx reply_ct %lx\n",
sep->send_ct, sep->reply_ct);
return 0;
}
static int sep_free_dma_table_data_handler(struct sep_device *sep)
{
int count;
int dcb_counter;
struct sep_dma_resource *dma;
for (dcb_counter = 0; dcb_counter < sep->nr_dcb_creat; dcb_counter++) {
dma = &sep->dma_res_arr[dcb_counter];
if (dma->in_map_array) {
for (count = 0; count < dma->in_num_pages; count++) {
dma_unmap_page(&sep->pdev->dev,
dma->in_map_array[count].dma_addr,
dma->in_map_array[count].size,
DMA_TO_DEVICE);
}
kfree(dma->in_map_array);
}
if (dma->out_map_array) {
for (count = 0; count < dma->out_num_pages; count++) {
dma_unmap_page(&sep->pdev->dev,
dma->out_map_array[count].dma_addr,
dma->out_map_array[count].size,
DMA_FROM_DEVICE);
}
kfree(dma->out_map_array);
}
if (dma->in_page_array) {
for (count = 0; count < dma->in_num_pages; count++) {
flush_dcache_page(dma->in_page_array[count]);
page_cache_release(dma->in_page_array[count]);
}
kfree(dma->in_page_array);
}
if (dma->out_page_array) {
for (count = 0; count < dma->out_num_pages; count++) {
if (!PageReserved(dma->out_page_array[count]))
SetPageDirty(dma->out_page_array[count]);
flush_dcache_page(dma->out_page_array[count]);
page_cache_release(dma->out_page_array[count]);
}
kfree(dma->out_page_array);
}
dma->in_page_array = NULL;
dma->out_page_array = NULL;
dma->in_num_pages = 0;
dma->out_num_pages = 0;
dma->in_map_array = NULL;
dma->out_map_array = NULL;
dma->in_map_num_entries = 0;
dma->out_map_num_entries = 0;
}
sep->nr_dcb_creat = 0;
sep->num_lli_tables_created = 0;
return 0;
}
static int sep_request_daemon_mmap(struct file *filp,
struct vm_area_struct *vma)
{
struct sep_device *sep = filp->private_data;
dma_addr_t bus_address;
int error = 0;
if ((vma->vm_end - vma->vm_start) > SEP_DRIVER_MMMAP_AREA_SIZE) {
error = -EINVAL;
goto end_function;
}
bus_address = sep->shared_bus;
if (remap_pfn_range(vma, vma->vm_start, bus_address >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot)) {
dev_warn(&sep->pdev->dev, "remap_page_range failed\n");
error = -EAGAIN;
goto end_function;
}
end_function:
return error;
}
static unsigned int sep_request_daemon_poll(struct file *filp,
poll_table *wait)
{
u32 mask = 0;
u32 retval2;
unsigned long lck_flags;
struct sep_device *sep = filp->private_data;
poll_wait(filp, &sep->event_request_daemon, wait);
dev_dbg(&sep->pdev->dev, "daemon poll: send_ct is %lx reply ct is %lx\n",
sep->send_ct, sep->reply_ct);
spin_lock_irqsave(&sep->snd_rply_lck, lck_flags);
if (sep->send_ct == sep->reply_ct) {
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
retval2 = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR2_REG_ADDR);
dev_dbg(&sep->pdev->dev,
"daemon poll: data check (GPR2) is %x\n", retval2);
if ((retval2 >> 30) & 0x1) {
dev_dbg(&sep->pdev->dev, "daemon poll: PRINTF request in\n");
mask |= POLLIN;
goto end_function;
}
if (retval2 >> 31) {
dev_dbg(&sep->pdev->dev, "daemon poll: NVS request in\n");
mask |= POLLPRI | POLLWRNORM;
}
} else {
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
dev_dbg(&sep->pdev->dev,
"daemon poll: no reply received; returning 0\n");
mask = 0;
}
end_function:
return mask;
}
static int sep_release(struct inode *inode, struct file *filp)
{
struct sep_device *sep = filp->private_data;
dev_dbg(&sep->pdev->dev, "Release for pid %d\n", current->pid);
mutex_lock(&sep->sep_mutex);
if (sep->pid_doing_transaction == current->pid) {
clear_bit(SEP_MMAP_LOCK_BIT, &sep->in_use_flags);
clear_bit(SEP_SEND_MSG_LOCK_BIT, &sep->in_use_flags);
sep_free_dma_table_data_handler(sep);
wake_up(&sep->event);
sep->pid_doing_transaction = 0;
}
mutex_unlock(&sep->sep_mutex);
return 0;
}
static int sep_mmap(struct file *filp, struct vm_area_struct *vma)
{
dma_addr_t bus_addr;
struct sep_device *sep = filp->private_data;
unsigned long error = 0;
wait_event_interruptible(sep->event,
test_and_set_bit(SEP_MMAP_LOCK_BIT,
&sep->in_use_flags) == 0);
if (signal_pending(current)) {
error = -EINTR;
goto end_function_with_error;
}
mutex_lock(&sep->sep_mutex);
sep->pid_doing_transaction = current->pid;
mutex_unlock(&sep->sep_mutex);
sep->data_pool_bytes_allocated = 0;
sep->num_of_data_allocations = 0;
if ((vma->vm_end - vma->vm_start) > SEP_DRIVER_MMMAP_AREA_SIZE) {
error = -EINVAL;
goto end_function_with_error;
}
dev_dbg(&sep->pdev->dev, "shared_addr is %p\n", sep->shared_addr);
bus_addr = sep->shared_bus;
if (remap_pfn_range(vma, vma->vm_start, bus_addr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot)) {
dev_warn(&sep->pdev->dev, "remap_page_range failed\n");
error = -EAGAIN;
goto end_function_with_error;
}
goto end_function;
end_function_with_error:
clear_bit(SEP_MMAP_LOCK_BIT, &sep->in_use_flags);
mutex_lock(&sep->sep_mutex);
sep->pid_doing_transaction = 0;
mutex_unlock(&sep->sep_mutex);
wake_up(&sep->event);
end_function:
return error;
}
static unsigned int sep_poll(struct file *filp, poll_table *wait)
{
u32 mask = 0;
u32 retval = 0;
u32 retval2 = 0;
unsigned long lck_flags;
struct sep_device *sep = filp->private_data;
mutex_lock(&sep->sep_mutex);
if (current->pid != sep->pid_doing_transaction) {
dev_dbg(&sep->pdev->dev, "poll; wrong pid\n");
mask = POLLERR;
mutex_unlock(&sep->sep_mutex);
goto end_function;
}
mutex_unlock(&sep->sep_mutex);
if (!test_bit(SEP_SEND_MSG_LOCK_BIT, &sep->in_use_flags)) {
mask = POLLERR;
goto end_function;
}
dev_dbg(&sep->pdev->dev, "poll: calling wait sep_event\n");
poll_wait(filp, &sep->event, wait);
dev_dbg(&sep->pdev->dev, "poll: send_ct is %lx reply ct is %lx\n",
sep->send_ct, sep->reply_ct);
retval2 = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR3_REG_ADDR);
if (retval2 != 0x0) {
dev_warn(&sep->pdev->dev, "poll; poll error %x\n", retval2);
mask |= POLLERR;
goto end_function;
}
spin_lock_irqsave(&sep->snd_rply_lck, lck_flags);
if (sep->send_ct == sep->reply_ct) {
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
retval = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR2_REG_ADDR);
dev_dbg(&sep->pdev->dev, "poll: data ready check (GPR2) %x\n",
retval);
if ((retval >> 30) & 0x1) {
dev_dbg(&sep->pdev->dev, "poll: SEP printf request\n");
wake_up(&sep->event_request_daemon);
goto end_function;
}
if (retval >> 31) {
dev_dbg(&sep->pdev->dev, "poll: SEP request\n");
wake_up(&sep->event_request_daemon);
} else {
dev_dbg(&sep->pdev->dev, "poll: normal return\n");
clear_bit(SEP_SEND_MSG_LOCK_BIT, &sep->in_use_flags);
sep_dump_message(sep);
dev_dbg(&sep->pdev->dev,
"poll; SEP reply POLLIN | POLLRDNORM\n");
mask |= POLLIN | POLLRDNORM;
}
} else {
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
dev_dbg(&sep->pdev->dev,
"poll; no reply received; returning mask of 0\n");
mask = 0;
}
end_function:
return mask;
}
static u32 *sep_time_address(struct sep_device *sep)
{
return sep->shared_addr + SEP_DRIVER_SYSTEM_TIME_MEMORY_OFFSET_IN_BYTES;
}
static unsigned long sep_set_time(struct sep_device *sep)
{
struct timeval time;
u32 *time_addr;
do_gettimeofday(&time);
time_addr = sep_time_address(sep);
time_addr[0] = SEP_TIME_VAL_TOKEN;
time_addr[1] = time.tv_sec;
dev_dbg(&sep->pdev->dev, "time.tv_sec is %lu\n", time.tv_sec);
dev_dbg(&sep->pdev->dev, "time_addr is %p\n", time_addr);
dev_dbg(&sep->pdev->dev, "sep->shared_addr is %p\n", sep->shared_addr);
return time.tv_sec;
}
static int sep_set_caller_id_handler(struct sep_device *sep, unsigned long arg)
{
void __user *hash;
int error = 0;
int i;
struct caller_id_struct command_args;
for (i = 0; i < SEP_CALLER_ID_TABLE_NUM_ENTRIES; i++) {
if (sep->caller_id_table[i].pid == 0)
break;
}
if (i == SEP_CALLER_ID_TABLE_NUM_ENTRIES) {
dev_dbg(&sep->pdev->dev, "no more caller id entries left\n");
dev_dbg(&sep->pdev->dev, "maximum number is %d\n",
SEP_CALLER_ID_TABLE_NUM_ENTRIES);
error = -EUSERS;
goto end_function;
}
if (copy_from_user(&command_args, (void __user *)arg,
sizeof(command_args))) {
error = -EFAULT;
goto end_function;
}
hash = (void __user *)(unsigned long)command_args.callerIdAddress;
if (!command_args.pid || !command_args.callerIdSizeInBytes) {
error = -EINVAL;
goto end_function;
}
dev_dbg(&sep->pdev->dev, "pid is %x\n", command_args.pid);
dev_dbg(&sep->pdev->dev, "callerIdSizeInBytes is %x\n",
command_args.callerIdSizeInBytes);
if (command_args.callerIdSizeInBytes >
SEP_CALLER_ID_HASH_SIZE_IN_BYTES) {
error = -EMSGSIZE;
goto end_function;
}
sep->caller_id_table[i].pid = command_args.pid;
if (copy_from_user(sep->caller_id_table[i].callerIdHash,
hash, command_args.callerIdSizeInBytes))
error = -EFAULT;
end_function:
return error;
}
static int sep_set_current_caller_id(struct sep_device *sep)
{
int i;
u32 *hash_buf_ptr;
memset(sep->shared_addr + SEP_CALLER_ID_OFFSET_BYTES,
0, SEP_CALLER_ID_HASH_SIZE_IN_BYTES);
for (i = 0; i < SEP_CALLER_ID_TABLE_NUM_ENTRIES; i++) {
if (sep->caller_id_table[i].pid == current->pid) {
dev_dbg(&sep->pdev->dev, "Caller Id found\n");
memcpy(sep->shared_addr + SEP_CALLER_ID_OFFSET_BYTES,
(void *)(sep->caller_id_table[i].callerIdHash),
SEP_CALLER_ID_HASH_SIZE_IN_BYTES);
break;
}
}
hash_buf_ptr = (u32 *)sep->shared_addr +
SEP_CALLER_ID_OFFSET_BYTES;
for (i = 0; i < SEP_CALLER_ID_HASH_SIZE_IN_WORDS; i++)
hash_buf_ptr[i] = cpu_to_le32(hash_buf_ptr[i]);
return 0;
}
static int sep_send_command_handler(struct sep_device *sep)
{
unsigned long lck_flags;
int error = 0;
if (test_and_set_bit(SEP_SEND_MSG_LOCK_BIT, &sep->in_use_flags)) {
error = -EPROTO;
goto end_function;
}
sep_set_time(sep);
sep_set_current_caller_id(sep);
sep_dump_message(sep);
spin_lock_irqsave(&sep->snd_rply_lck, lck_flags);
sep->send_ct++;
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
dev_dbg(&sep->pdev->dev,
"sep_send_command_handler send_ct %lx reply_ct %lx\n",
sep->send_ct, sep->reply_ct);
sep_write_reg(sep, HW_HOST_HOST_SEP_GPR0_REG_ADDR, 0x2);
end_function:
return error;
}
static int sep_allocate_data_pool_memory_handler(struct sep_device *sep,
unsigned long arg)
{
int error = 0;
struct alloc_struct command_args;
u32 *token_addr;
if (copy_from_user(&command_args, (void __user *)arg,
sizeof(struct alloc_struct))) {
error = -EFAULT;
goto end_function;
}
if ((sep->data_pool_bytes_allocated + command_args.num_bytes) >
SEP_DRIVER_DATA_POOL_SHARED_AREA_SIZE_IN_BYTES) {
error = -ENOMEM;
goto end_function;
}
dev_dbg(&sep->pdev->dev,
"data pool bytes_allocated: %x\n", (int)sep->data_pool_bytes_allocated);
dev_dbg(&sep->pdev->dev,
"offset: %x\n", SEP_DRIVER_DATA_POOL_AREA_OFFSET_IN_BYTES);
command_args.offset = SEP_DRIVER_DATA_POOL_AREA_OFFSET_IN_BYTES +
sep->data_pool_bytes_allocated;
token_addr = (u32 *)(sep->shared_addr +
SEP_DRIVER_DATA_POOL_ALLOCATION_OFFSET_IN_BYTES +
(sep->num_of_data_allocations)*2*sizeof(u32));
token_addr[0] = SEP_DATA_POOL_POINTERS_VAL_TOKEN;
token_addr[1] = (u32)sep->shared_bus +
SEP_DRIVER_DATA_POOL_AREA_OFFSET_IN_BYTES +
sep->data_pool_bytes_allocated;
error = copy_to_user((void *)arg, (void *)&command_args,
sizeof(struct alloc_struct));
if (error) {
error = -EFAULT;
goto end_function;
}
sep->data_pool_bytes_allocated += command_args.num_bytes;
sep->num_of_data_allocations += 1;
end_function:
return error;
}
static int sep_lock_kernel_pages(struct sep_device *sep,
unsigned long kernel_virt_addr,
u32 data_size,
struct sep_lli_entry **lli_array_ptr,
int in_out_flag)
{
int error = 0;
struct sep_lli_entry *lli_array;
struct sep_dma_map *map_array;
dev_dbg(&sep->pdev->dev, "lock kernel pages kernel_virt_addr is %08lx\n",
(unsigned long)kernel_virt_addr);
dev_dbg(&sep->pdev->dev, "data_size is %x\n", data_size);
lli_array = kmalloc(sizeof(struct sep_lli_entry), GFP_ATOMIC);
if (!lli_array) {
error = -ENOMEM;
goto end_function;
}
map_array = kmalloc(sizeof(struct sep_dma_map), GFP_ATOMIC);
if (!map_array) {
error = -ENOMEM;
goto end_function_with_error;
}
map_array[0].dma_addr =
dma_map_single(&sep->pdev->dev, (void *)kernel_virt_addr,
data_size, DMA_BIDIRECTIONAL);
map_array[0].size = data_size;
lli_array[0].bus_address = (u32)map_array[0].dma_addr;
lli_array[0].block_size = map_array[0].size;
dev_dbg(&sep->pdev->dev,
"lli_array[0].bus_address is %08lx, lli_array[0].block_size is %x\n",
(unsigned long)lli_array[0].bus_address,
lli_array[0].block_size);
if (in_out_flag == SEP_DRIVER_IN_FLAG) {
*lli_array_ptr = lli_array;
sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages = 1;
sep->dma_res_arr[sep->nr_dcb_creat].in_page_array = NULL;
sep->dma_res_arr[sep->nr_dcb_creat].in_map_array = map_array;
sep->dma_res_arr[sep->nr_dcb_creat].in_map_num_entries = 1;
} else {
*lli_array_ptr = lli_array;
sep->dma_res_arr[sep->nr_dcb_creat].out_num_pages = 1;
sep->dma_res_arr[sep->nr_dcb_creat].out_page_array = NULL;
sep->dma_res_arr[sep->nr_dcb_creat].out_map_array = map_array;
sep->dma_res_arr[sep->nr_dcb_creat].out_map_num_entries = 1;
}
goto end_function;
end_function_with_error:
kfree(lli_array);
end_function:
return error;
}
static int sep_lock_user_pages(struct sep_device *sep,
u32 app_virt_addr,
u32 data_size,
struct sep_lli_entry **lli_array_ptr,
int in_out_flag)
{
int error = 0;
u32 count;
int result;
u32 end_page;
u32 start_page;
u32 num_pages;
struct page **page_array;
struct sep_lli_entry *lli_array;
struct sep_dma_map *map_array;
enum dma_data_direction dir;
end_page = (app_virt_addr + data_size - 1) >> PAGE_SHIFT;
start_page = app_virt_addr >> PAGE_SHIFT;
num_pages = end_page - start_page + 1;
dev_dbg(&sep->pdev->dev, "lock user pages app_virt_addr is %x\n", app_virt_addr);
dev_dbg(&sep->pdev->dev, "data_size is %x\n", data_size);
dev_dbg(&sep->pdev->dev, "start_page is %x\n", start_page);
dev_dbg(&sep->pdev->dev, "end_page is %x\n", end_page);
dev_dbg(&sep->pdev->dev, "num_pages is %x\n", num_pages);
page_array = kmalloc(sizeof(struct page *) * num_pages, GFP_ATOMIC);
if (!page_array) {
error = -ENOMEM;
goto end_function;
}
map_array = kmalloc(sizeof(struct sep_dma_map) * num_pages, GFP_ATOMIC);
if (!map_array) {
dev_warn(&sep->pdev->dev, "kmalloc for map_array failed\n");
error = -ENOMEM;
goto end_function_with_error1;
}
lli_array = kmalloc(sizeof(struct sep_lli_entry) * num_pages,
GFP_ATOMIC);
if (!lli_array) {
dev_warn(&sep->pdev->dev, "kmalloc for lli_array failed\n");
error = -ENOMEM;
goto end_function_with_error2;
}
down_read(&current->mm->mmap_sem);
result = get_user_pages(current, current->mm, app_virt_addr,
num_pages,
((in_out_flag == SEP_DRIVER_IN_FLAG) ? 0 : 1),
0, page_array, NULL);
up_read(&current->mm->mmap_sem);
if (result != num_pages) {
dev_warn(&sep->pdev->dev,
"not all pages locked by get_user_pages\n");
error = -ENOMEM;
goto end_function_with_error3;
}
dev_dbg(&sep->pdev->dev, "get_user_pages succeeded\n");
if (in_out_flag == SEP_DRIVER_IN_FLAG)
dir = DMA_TO_DEVICE;
else
dir = DMA_FROM_DEVICE;
for (count = 0; count < num_pages; count++) {
map_array[count].dma_addr =
dma_map_page(&sep->pdev->dev, page_array[count],
0, PAGE_SIZE, DMA_BIDIRECTIONAL);
map_array[count].size = PAGE_SIZE;
lli_array[count].bus_address = (u32)map_array[count].dma_addr;
lli_array[count].block_size = PAGE_SIZE;
dev_warn(&sep->pdev->dev, "lli_array[%x].bus_address is %08lx, lli_array[%x].block_size is %x\n",
count, (unsigned long)lli_array[count].bus_address,
count, lli_array[count].block_size);
}
lli_array[0].bus_address =
lli_array[0].bus_address + (app_virt_addr & (~PAGE_MASK));
if ((PAGE_SIZE - (app_virt_addr & (~PAGE_MASK))) >= data_size)
lli_array[0].block_size = data_size;
else
lli_array[0].block_size =
PAGE_SIZE - (app_virt_addr & (~PAGE_MASK));
dev_dbg(&sep->pdev->dev,
"lli_array[0].bus_address is %08lx, lli_array[0].block_size is %x\n",
(unsigned long)lli_array[count].bus_address,
lli_array[count].block_size);
if (num_pages > 1) {
lli_array[num_pages - 1].block_size =
(app_virt_addr + data_size) & (~PAGE_MASK);
if (lli_array[num_pages - 1].block_size == 0)
lli_array[num_pages - 1].block_size = PAGE_SIZE;
dev_warn(&sep->pdev->dev,
"lli_array[%x].bus_address is "
"%08lx, lli_array[%x].block_size is %x\n",
num_pages - 1,
(unsigned long)lli_array[num_pages -1].bus_address,
num_pages - 1,
lli_array[num_pages -1].block_size);
}
if (in_out_flag == SEP_DRIVER_IN_FLAG) {
*lli_array_ptr = lli_array;
sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages = num_pages;
sep->dma_res_arr[sep->nr_dcb_creat].in_page_array = page_array;
sep->dma_res_arr[sep->nr_dcb_creat].in_map_array = map_array;
sep->dma_res_arr[sep->nr_dcb_creat].in_map_num_entries =
num_pages;
} else {
*lli_array_ptr = lli_array;
sep->dma_res_arr[sep->nr_dcb_creat].out_num_pages = num_pages;
sep->dma_res_arr[sep->nr_dcb_creat].out_page_array =
page_array;
sep->dma_res_arr[sep->nr_dcb_creat].out_map_array = map_array;
sep->dma_res_arr[sep->nr_dcb_creat].out_map_num_entries =
num_pages;
}
goto end_function;
end_function_with_error3:
kfree(lli_array);
end_function_with_error2:
kfree(map_array);
end_function_with_error1:
kfree(page_array);
end_function:
return error;
}
static u32 sep_calculate_lli_table_max_size(struct sep_device *sep,
struct sep_lli_entry *lli_in_array_ptr,
u32 num_array_entries,
u32 *last_table_flag)
{
u32 counter;
u32 table_data_size = 0;
u32 next_table_data_size;
*last_table_flag = 0;
for (counter = 0;
(counter < (SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP - 1)) &&
(counter < num_array_entries); counter++)
table_data_size += lli_in_array_ptr[counter].block_size;
if (counter == num_array_entries) {
*last_table_flag = 1;
goto end_function;
}
next_table_data_size = 0;
for (; counter < num_array_entries; counter++) {
next_table_data_size += lli_in_array_ptr[counter].block_size;
if (next_table_data_size >= SEP_DRIVER_MIN_DATA_SIZE_PER_TABLE)
break;
}
if (next_table_data_size &&
next_table_data_size < SEP_DRIVER_MIN_DATA_SIZE_PER_TABLE)
table_data_size -= (SEP_DRIVER_MIN_DATA_SIZE_PER_TABLE -
next_table_data_size);
end_function:
return table_data_size;
}
static void sep_build_lli_table(struct sep_device *sep,
struct sep_lli_entry *lli_array_ptr,
struct sep_lli_entry *lli_table_ptr,
u32 *num_processed_entries_ptr,
u32 *num_table_entries_ptr,
u32 table_data_size)
{
u32 curr_table_data_size;
u32 array_counter;
curr_table_data_size = 0;
array_counter = 0;
*num_table_entries_ptr = 1;
dev_dbg(&sep->pdev->dev, "build lli table table_data_size is %x\n", table_data_size);
while (curr_table_data_size < table_data_size) {
(*num_table_entries_ptr)++;
lli_table_ptr->bus_address =
cpu_to_le32(lli_array_ptr[array_counter].bus_address);
lli_table_ptr->block_size =
cpu_to_le32(lli_array_ptr[array_counter].block_size);
curr_table_data_size += lli_array_ptr[array_counter].block_size;
dev_dbg(&sep->pdev->dev, "lli_table_ptr is %p\n",
lli_table_ptr);
dev_dbg(&sep->pdev->dev, "lli_table_ptr->bus_address is %08lx\n",
(unsigned long)lli_table_ptr->bus_address);
dev_dbg(&sep->pdev->dev, "lli_table_ptr->block_size is %x\n",
lli_table_ptr->block_size);
if (curr_table_data_size > table_data_size) {
dev_dbg(&sep->pdev->dev,
"curr_table_data_size too large\n");
lli_table_ptr->block_size -=
cpu_to_le32((curr_table_data_size - table_data_size));
lli_array_ptr[array_counter].bus_address +=
cpu_to_le32(lli_table_ptr->block_size);
lli_array_ptr[array_counter].block_size =
(curr_table_data_size - table_data_size);
} else
array_counter++;
dev_dbg(&sep->pdev->dev,
"lli_table_ptr->bus_address is %08lx\n",
(unsigned long)lli_table_ptr->bus_address);
dev_dbg(&sep->pdev->dev,
"lli_table_ptr->block_size is %x\n",
lli_table_ptr->block_size);
lli_table_ptr++;
}
lli_table_ptr->bus_address = 0xffffffff;
lli_table_ptr->block_size = 0;
*num_processed_entries_ptr += array_counter;
}
static dma_addr_t sep_shared_area_virt_to_bus(struct sep_device *sep,
void *virt_address)
{
dev_dbg(&sep->pdev->dev, "sh virt to phys v %p\n", virt_address);
dev_dbg(&sep->pdev->dev, "sh virt to phys p %08lx\n",
(unsigned long)
sep->shared_bus + (virt_address - sep->shared_addr));
return sep->shared_bus + (size_t)(virt_address - sep->shared_addr);
}
static void *sep_shared_area_bus_to_virt(struct sep_device *sep,
dma_addr_t bus_address)
{
dev_dbg(&sep->pdev->dev, "shared bus to virt b=%lx v=%lx\n",
(unsigned long)bus_address, (unsigned long)(sep->shared_addr +
(size_t)(bus_address - sep->shared_bus)));
return sep->shared_addr + (size_t)(bus_address - sep->shared_bus);
}
static void sep_debug_print_lli_tables(struct sep_device *sep,
struct sep_lli_entry *lli_table_ptr,
unsigned long num_table_entries,
unsigned long table_data_size)
{
unsigned long table_count = 1;
unsigned long entries_count = 0;
dev_dbg(&sep->pdev->dev, "sep_debug_print_lli_tables start\n");
while ((unsigned long) lli_table_ptr->bus_address != 0xffffffff) {
dev_dbg(&sep->pdev->dev,
"lli table %08lx, table_data_size is %lu\n",
table_count, table_data_size);
dev_dbg(&sep->pdev->dev, "num_table_entries is %lu\n",
num_table_entries);
for (entries_count = 0; entries_count < num_table_entries;
entries_count++, lli_table_ptr++) {
dev_dbg(&sep->pdev->dev,
"lli_table_ptr address is %08lx\n",
(unsigned long) lli_table_ptr);
dev_dbg(&sep->pdev->dev,
"phys address is %08lx block size is %x\n",
(unsigned long)lli_table_ptr->bus_address,
lli_table_ptr->block_size);
}
lli_table_ptr--;
dev_dbg(&sep->pdev->dev,
"phys lli_table_ptr->block_size is %x\n",
lli_table_ptr->block_size);
dev_dbg(&sep->pdev->dev,
"phys lli_table_ptr->physical_address is %08lu\n",
(unsigned long)lli_table_ptr->bus_address);
table_data_size = lli_table_ptr->block_size & 0xffffff;
num_table_entries = (lli_table_ptr->block_size >> 24) & 0xff;
dev_dbg(&sep->pdev->dev,
"phys table_data_size is %lu num_table_entries is"
" %lu bus_address is%lu\n", table_data_size,
num_table_entries, (unsigned long)lli_table_ptr->bus_address);
if ((unsigned long)lli_table_ptr->bus_address != 0xffffffff)
lli_table_ptr = (struct sep_lli_entry *)
sep_shared_bus_to_virt(sep,
(unsigned long)lli_table_ptr->bus_address);
table_count++;
}
dev_dbg(&sep->pdev->dev, "sep_debug_print_lli_tables end\n");
}
static void sep_prepare_empty_lli_table(struct sep_device *sep,
dma_addr_t *lli_table_addr_ptr,
u32 *num_entries_ptr,
u32 *table_data_size_ptr)
{
struct sep_lli_entry *lli_table_ptr;
lli_table_ptr =
(struct sep_lli_entry *)(sep->shared_addr +
SYNCHRONIC_DMA_TABLES_AREA_OFFSET_BYTES +
sep->num_lli_tables_created * sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP);
lli_table_ptr->bus_address = 0;
lli_table_ptr->block_size = 0;
lli_table_ptr++;
lli_table_ptr->bus_address = 0xFFFFFFFF;
lli_table_ptr->block_size = 0;
*lli_table_addr_ptr = sep->shared_bus +
SYNCHRONIC_DMA_TABLES_AREA_OFFSET_BYTES +
sep->num_lli_tables_created *
sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP;
*num_entries_ptr = 2;
*table_data_size_ptr = 0;
sep->num_lli_tables_created++;
}
static int sep_prepare_input_dma_table(struct sep_device *sep,
unsigned long app_virt_addr,
u32 data_size,
u32 block_size,
dma_addr_t *lli_table_ptr,
u32 *num_entries_ptr,
u32 *table_data_size_ptr,
bool is_kva)
{
int error = 0;
struct sep_lli_entry *info_entry_ptr;
struct sep_lli_entry *lli_array_ptr;
u32 current_entry = 0;
u32 sep_lli_entries = 0;
struct sep_lli_entry *in_lli_table_ptr;
u32 table_data_size = 0;
u32 last_table_flag = 0;
u32 num_entries_in_table = 0;
void *lli_table_alloc_addr = 0;
dev_dbg(&sep->pdev->dev, "prepare intput dma table data_size is %x\n", data_size);
dev_dbg(&sep->pdev->dev, "block_size is %x\n", block_size);
sep->dma_res_arr[sep->nr_dcb_creat].in_page_array = NULL;
sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages = 0;
lli_table_alloc_addr = (void *)(sep->shared_addr +
SYNCHRONIC_DMA_TABLES_AREA_OFFSET_BYTES +
sep->num_lli_tables_created * sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP);
if (data_size == 0) {
sep_prepare_empty_lli_table(sep, lli_table_ptr,
num_entries_ptr, table_data_size_ptr);
goto update_dcb_counter;
}
if (is_kva == true)
error = sep_lock_kernel_pages(sep, app_virt_addr,
data_size, &lli_array_ptr, SEP_DRIVER_IN_FLAG);
else
error = sep_lock_user_pages(sep, app_virt_addr,
data_size, &lli_array_ptr, SEP_DRIVER_IN_FLAG);
if (error)
goto end_function;
dev_dbg(&sep->pdev->dev, "output sep_in_num_pages is %x\n",
sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages);
current_entry = 0;
info_entry_ptr = NULL;
sep_lli_entries = sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages;
while (current_entry < sep_lli_entries) {
in_lli_table_ptr =
(struct sep_lli_entry *)lli_table_alloc_addr;
lli_table_alloc_addr += sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP;
if (lli_table_alloc_addr >
((void *)sep->shared_addr +
SYNCHRONIC_DMA_TABLES_AREA_OFFSET_BYTES +
SYNCHRONIC_DMA_TABLES_AREA_SIZE_BYTES)) {
error = -ENOMEM;
goto end_function_error;
}
sep->num_lli_tables_created++;
table_data_size = sep_calculate_lli_table_max_size(sep,
&lli_array_ptr[current_entry],
(sep_lli_entries - current_entry),
&last_table_flag);
if (!last_table_flag)
table_data_size =
(table_data_size / block_size) * block_size;
dev_dbg(&sep->pdev->dev, "output table_data_size is %x\n",
table_data_size);
sep_build_lli_table(sep, &lli_array_ptr[current_entry],
in_lli_table_ptr,
&current_entry, &num_entries_in_table, table_data_size);
if (info_entry_ptr == NULL) {
*lli_table_ptr = sep_shared_area_virt_to_bus(sep,
in_lli_table_ptr);
*num_entries_ptr = num_entries_in_table;
*table_data_size_ptr = table_data_size;
dev_dbg(&sep->pdev->dev,
"output lli_table_in_ptr is %08lx\n",
(unsigned long)*lli_table_ptr);
} else {
info_entry_ptr->bus_address =
sep_shared_area_virt_to_bus(sep,
in_lli_table_ptr);
info_entry_ptr->block_size =
((num_entries_in_table) << 24) |
(table_data_size);
}
info_entry_ptr = in_lli_table_ptr + num_entries_in_table - 1;
}
sep_debug_print_lli_tables(sep, (struct sep_lli_entry *)
sep_shared_area_bus_to_virt(sep, *lli_table_ptr),
*num_entries_ptr, *table_data_size_ptr);
kfree(lli_array_ptr);
update_dcb_counter:
sep->nr_dcb_creat++;
goto end_function;
end_function_error:
kfree(sep->dma_res_arr[sep->nr_dcb_creat].in_map_array);
kfree(lli_array_ptr);
kfree(sep->dma_res_arr[sep->nr_dcb_creat].in_page_array);
end_function:
return error;
}
static int sep_construct_dma_tables_from_lli(
struct sep_device *sep,
struct sep_lli_entry *lli_in_array,
u32 sep_in_lli_entries,
struct sep_lli_entry *lli_out_array,
u32 sep_out_lli_entries,
u32 block_size,
dma_addr_t *lli_table_in_ptr,
dma_addr_t *lli_table_out_ptr,
u32 *in_num_entries_ptr,
u32 *out_num_entries_ptr,
u32 *table_data_size_ptr)
{
void *lli_table_alloc_addr = 0;
struct sep_lli_entry *in_lli_table_ptr = NULL;
struct sep_lli_entry *out_lli_table_ptr = NULL;
struct sep_lli_entry *info_in_entry_ptr = NULL;
struct sep_lli_entry *info_out_entry_ptr = NULL;
u32 current_in_entry = 0;
u32 current_out_entry = 0;
u32 in_table_data_size = 0;
u32 out_table_data_size = 0;
u32 last_table_flag = 0;
u32 table_data_size = 0;
u32 num_entries_in_table = 0;
u32 num_entries_out_table = 0;
lli_table_alloc_addr = (void *)(sep->shared_addr +
SYNCHRONIC_DMA_TABLES_AREA_OFFSET_BYTES +
(sep->num_lli_tables_created *
(sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP)));
while (current_in_entry < sep_in_lli_entries) {
in_lli_table_ptr =
(struct sep_lli_entry *)lli_table_alloc_addr;
lli_table_alloc_addr += sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP;
out_lli_table_ptr =
(struct sep_lli_entry *)lli_table_alloc_addr;
if ((lli_table_alloc_addr + sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP) >
((void *)sep->shared_addr +
SYNCHRONIC_DMA_TABLES_AREA_OFFSET_BYTES +
SYNCHRONIC_DMA_TABLES_AREA_SIZE_BYTES)) {
dev_warn(&sep->pdev->dev, "dma table limit overrun\n");
return -ENOMEM;
}
sep->num_lli_tables_created += 2;
lli_table_alloc_addr += sizeof(struct sep_lli_entry) *
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP;
in_table_data_size =
sep_calculate_lli_table_max_size(sep,
&lli_in_array[current_in_entry],
(sep_in_lli_entries - current_in_entry),
&last_table_flag);
out_table_data_size =
sep_calculate_lli_table_max_size(sep,
&lli_out_array[current_out_entry],
(sep_out_lli_entries - current_out_entry),
&last_table_flag);
dev_dbg(&sep->pdev->dev,
"construct tables from lli in_table_data_size is %x\n",
in_table_data_size);
dev_dbg(&sep->pdev->dev,
"construct tables from lli out_table_data_size is %x\n",
out_table_data_size);
table_data_size = in_table_data_size;
if (!last_table_flag) {
if (table_data_size > out_table_data_size)
table_data_size = out_table_data_size;
table_data_size = (table_data_size / block_size) *
block_size;
}
sep_build_lli_table(sep, &lli_in_array[current_in_entry],
in_lli_table_ptr,
&current_in_entry,
&num_entries_in_table,
table_data_size);
sep_build_lli_table(sep, &lli_out_array[current_out_entry],
out_lli_table_ptr,
&current_out_entry,
&num_entries_out_table,
table_data_size);
if (info_in_entry_ptr == NULL) {
*lli_table_in_ptr =
sep_shared_area_virt_to_bus(sep, in_lli_table_ptr);
*in_num_entries_ptr = num_entries_in_table;
*lli_table_out_ptr =
sep_shared_area_virt_to_bus(sep,
out_lli_table_ptr);
*out_num_entries_ptr = num_entries_out_table;
*table_data_size_ptr = table_data_size;
dev_dbg(&sep->pdev->dev,
"output lli_table_in_ptr is %08lx\n",
(unsigned long)*lli_table_in_ptr);
dev_dbg(&sep->pdev->dev,
"output lli_table_out_ptr is %08lx\n",
(unsigned long)*lli_table_out_ptr);
} else {
info_in_entry_ptr->bus_address =
sep_shared_area_virt_to_bus(sep,
in_lli_table_ptr);
info_in_entry_ptr->block_size =
((num_entries_in_table) << 24) |
(table_data_size);
info_out_entry_ptr->bus_address =
sep_shared_area_virt_to_bus(sep,
out_lli_table_ptr);
info_out_entry_ptr->block_size =
((num_entries_out_table) << 24) |
(table_data_size);
dev_dbg(&sep->pdev->dev,
"output lli_table_in_ptr:%08lx %08x\n",
(unsigned long)info_in_entry_ptr->bus_address,
info_in_entry_ptr->block_size);
dev_dbg(&sep->pdev->dev,
"output lli_table_out_ptr:%08lx %08x\n",
(unsigned long)info_out_entry_ptr->bus_address,
info_out_entry_ptr->block_size);
}
info_in_entry_ptr = in_lli_table_ptr +
num_entries_in_table - 1;
info_out_entry_ptr = out_lli_table_ptr +
num_entries_out_table - 1;
dev_dbg(&sep->pdev->dev,
"output num_entries_out_table is %x\n",
(u32)num_entries_out_table);
dev_dbg(&sep->pdev->dev,
"output info_in_entry_ptr is %lx\n",
(unsigned long)info_in_entry_ptr);
dev_dbg(&sep->pdev->dev,
"output info_out_entry_ptr is %lx\n",
(unsigned long)info_out_entry_ptr);
}
sep_debug_print_lli_tables(sep,
(struct sep_lli_entry *)
sep_shared_area_bus_to_virt(sep, *lli_table_in_ptr),
*in_num_entries_ptr,
*table_data_size_ptr);
sep_debug_print_lli_tables(sep,
(struct sep_lli_entry *)
sep_shared_area_bus_to_virt(sep, *lli_table_out_ptr),
*out_num_entries_ptr,
*table_data_size_ptr);
return 0;
}
static int sep_prepare_input_output_dma_table(struct sep_device *sep,
unsigned long app_virt_in_addr,
unsigned long app_virt_out_addr,
u32 data_size,
u32 block_size,
dma_addr_t *lli_table_in_ptr,
dma_addr_t *lli_table_out_ptr,
u32 *in_num_entries_ptr,
u32 *out_num_entries_ptr,
u32 *table_data_size_ptr,
bool is_kva)
{
int error = 0;
struct sep_lli_entry *lli_in_array;
struct sep_lli_entry *lli_out_array;
if (data_size == 0) {
sep_prepare_empty_lli_table(sep, lli_table_in_ptr,
in_num_entries_ptr, table_data_size_ptr);
sep_prepare_empty_lli_table(sep, lli_table_out_ptr,
out_num_entries_ptr, table_data_size_ptr);
goto update_dcb_counter;
}
sep->dma_res_arr[sep->nr_dcb_creat].in_page_array = NULL;
sep->dma_res_arr[sep->nr_dcb_creat].out_page_array = NULL;
if (is_kva == true) {
error = sep_lock_kernel_pages(sep, app_virt_in_addr,
data_size, &lli_in_array, SEP_DRIVER_IN_FLAG);
if (error) {
dev_warn(&sep->pdev->dev,
"lock kernel for in failed\n");
goto end_function;
}
error = sep_lock_kernel_pages(sep, app_virt_out_addr,
data_size, &lli_out_array, SEP_DRIVER_OUT_FLAG);
if (error) {
dev_warn(&sep->pdev->dev,
"lock kernel for out failed\n");
goto end_function;
}
}
else {
error = sep_lock_user_pages(sep, app_virt_in_addr,
data_size, &lli_in_array, SEP_DRIVER_IN_FLAG);
if (error) {
dev_warn(&sep->pdev->dev,
"sep_lock_user_pages for input virtual buffer failed\n");
goto end_function;
}
error = sep_lock_user_pages(sep, app_virt_out_addr,
data_size, &lli_out_array, SEP_DRIVER_OUT_FLAG);
if (error) {
dev_warn(&sep->pdev->dev,
"sep_lock_user_pages for output virtual buffer failed\n");
goto end_function_free_lli_in;
}
}
dev_dbg(&sep->pdev->dev, "prep input output dma table sep_in_num_pages is %x\n",
sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages);
dev_dbg(&sep->pdev->dev, "sep_out_num_pages is %x\n",
sep->dma_res_arr[sep->nr_dcb_creat].out_num_pages);
dev_dbg(&sep->pdev->dev, "SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP is %x\n",
SEP_DRIVER_ENTRIES_PER_TABLE_IN_SEP);
error = sep_construct_dma_tables_from_lli(sep, lli_in_array,
sep->dma_res_arr[sep->nr_dcb_creat].in_num_pages,
lli_out_array,
sep->dma_res_arr[sep->nr_dcb_creat].out_num_pages,
block_size, lli_table_in_ptr, lli_table_out_ptr,
in_num_entries_ptr, out_num_entries_ptr, table_data_size_ptr);
if (error) {
dev_warn(&sep->pdev->dev,
"sep_construct_dma_tables_from_lli failed\n");
goto end_function_with_error;
}
kfree(lli_out_array);
kfree(lli_in_array);
update_dcb_counter:
sep->nr_dcb_creat++;
goto end_function;
end_function_with_error:
kfree(sep->dma_res_arr[sep->nr_dcb_creat].out_map_array);
kfree(sep->dma_res_arr[sep->nr_dcb_creat].out_page_array);
kfree(lli_out_array);
end_function_free_lli_in:
kfree(sep->dma_res_arr[sep->nr_dcb_creat].in_map_array);
kfree(sep->dma_res_arr[sep->nr_dcb_creat].in_page_array);
kfree(lli_in_array);
end_function:
return error;
}
static int sep_prepare_input_output_dma_table_in_dcb(struct sep_device *sep,
unsigned long app_in_address,
unsigned long app_out_address,
u32 data_in_size,
u32 block_size,
u32 tail_block_size,
bool isapplet,
bool is_kva)
{
int error = 0;
u32 tail_size = 0;
struct sep_dcblock *dcb_table_ptr = NULL;
dma_addr_t in_first_mlli_address = 0;
u32 in_first_num_entries = 0;
dma_addr_t out_first_mlli_address = 0;
u32 out_first_num_entries = 0;
u32 first_data_size = 0;
if (sep->nr_dcb_creat == SEP_MAX_NUM_SYNC_DMA_OPS) {
dev_warn(&sep->pdev->dev, "no more DCBs available\n");
error = -ENOSPC;
goto end_function;
}
dcb_table_ptr = (struct sep_dcblock *)(sep->shared_addr +
SEP_DRIVER_SYSTEM_DCB_MEMORY_OFFSET_IN_BYTES +
(sep->nr_dcb_creat * sizeof(struct sep_dcblock)));
dcb_table_ptr->input_mlli_address = 0;
dcb_table_ptr->input_mlli_num_entries = 0;
dcb_table_ptr->input_mlli_data_size = 0;
dcb_table_ptr->output_mlli_address = 0;
dcb_table_ptr->output_mlli_num_entries = 0;
dcb_table_ptr->output_mlli_data_size = 0;
dcb_table_ptr->tail_data_size = 0;
dcb_table_ptr->out_vr_tail_pt = 0;
if (isapplet == true) {
if (data_in_size < SEP_DRIVER_MIN_DATA_SIZE_PER_TABLE) {
if (is_kva == true) {
memcpy(dcb_table_ptr->tail_data,
(void *)app_in_address, data_in_size);
} else {
if (copy_from_user(dcb_table_ptr->tail_data,
(void __user *)app_in_address,
data_in_size)) {
error = -EFAULT;
goto end_function;
}
}
dcb_table_ptr->tail_data_size = data_in_size;
if (app_out_address)
dcb_table_ptr->out_vr_tail_pt =
(aligned_u64)app_out_address;
tail_size = 0x0;
data_in_size = 0x0;
} else {
if (!app_out_address) {
tail_size = data_in_size % block_size;
if (!tail_size) {
if (tail_block_size == block_size)
tail_size = block_size;
}
} else {
tail_size = 0;
}
}
if (tail_size) {
if (is_kva == true) {
memcpy(dcb_table_ptr->tail_data,
(void *)(app_in_address + data_in_size -
tail_size), tail_size);
} else {
if (copy_from_user(dcb_table_ptr->tail_data,
(void *)(app_in_address +
data_in_size - tail_size), tail_size)) {
error = -EFAULT;
goto end_function;
}
}
if (app_out_address)
dcb_table_ptr->out_vr_tail_pt =
(aligned_u64)app_out_address + data_in_size
- tail_size;
dcb_table_ptr->tail_data_size = tail_size;
data_in_size = (data_in_size - tail_size);
}
}
if (app_out_address) {
error = sep_prepare_input_output_dma_table(sep,
app_in_address,
app_out_address,
data_in_size,
block_size,
&in_first_mlli_address,
&out_first_mlli_address,
&in_first_num_entries,
&out_first_num_entries,
&first_data_size,
is_kva);
} else {
error = sep_prepare_input_dma_table(sep,
app_in_address,
data_in_size,
block_size,
&in_first_mlli_address,
&in_first_num_entries,
&first_data_size,
is_kva);
}
if (error) {
dev_warn(&sep->pdev->dev, "prepare DMA table call failed from prepare DCB call\n");
goto end_function;
}
dcb_table_ptr->input_mlli_address = in_first_mlli_address;
dcb_table_ptr->input_mlli_num_entries = in_first_num_entries;
dcb_table_ptr->input_mlli_data_size = first_data_size;
dcb_table_ptr->output_mlli_address = out_first_mlli_address;
dcb_table_ptr->output_mlli_num_entries = out_first_num_entries;
dcb_table_ptr->output_mlli_data_size = first_data_size;
end_function:
return error;
}
static int sep_free_dma_tables_and_dcb(struct sep_device *sep, bool isapplet,
bool is_kva)
{
int i = 0;
int error = 0;
int error_temp = 0;
struct sep_dcblock *dcb_table_ptr;
unsigned long pt_hold;
void *tail_pt;
if (isapplet == true) {
dcb_table_ptr = (struct sep_dcblock *)
(sep->shared_addr +
SEP_DRIVER_SYSTEM_DCB_MEMORY_OFFSET_IN_BYTES);
for (i = 0; i < sep->nr_dcb_creat; i++, dcb_table_ptr++) {
if (dcb_table_ptr->out_vr_tail_pt) {
pt_hold = (unsigned long)dcb_table_ptr->out_vr_tail_pt;
tail_pt = (void *)pt_hold;
if (is_kva == true) {
memcpy(tail_pt,
dcb_table_ptr->tail_data,
dcb_table_ptr->tail_data_size);
} else {
error_temp = copy_to_user(
tail_pt,
dcb_table_ptr->tail_data,
dcb_table_ptr->tail_data_size);
}
if (error_temp) {
error = -EFAULT;
break;
}
}
}
}
sep_free_dma_table_data_handler(sep);
return error;
}
static int sep_get_static_pool_addr_handler(struct sep_device *sep)
{
u32 *static_pool_addr = NULL;
static_pool_addr = (u32 *)(sep->shared_addr +
SEP_DRIVER_SYSTEM_RAR_MEMORY_OFFSET_IN_BYTES);
static_pool_addr[0] = SEP_STATIC_POOL_VAL_TOKEN;
static_pool_addr[1] = (u32)sep->shared_bus +
SEP_DRIVER_STATIC_AREA_OFFSET_IN_BYTES;
dev_dbg(&sep->pdev->dev, "static pool segment: physical %x\n",
(u32)static_pool_addr[1]);
return 0;
}
static int sep_end_transaction_handler(struct sep_device *sep)
{
memset((void *)(sep->shared_addr +
SEP_DRIVER_DATA_POOL_ALLOCATION_OFFSET_IN_BYTES),
0, sep->num_of_data_allocations*2*sizeof(u32));
sep_free_dma_table_data_handler(sep);
clear_bit(SEP_MMAP_LOCK_BIT, &sep->in_use_flags);
mutex_lock(&sep->sep_mutex);
sep->pid_doing_transaction = 0;
mutex_unlock(&sep->sep_mutex);
wake_up(&sep->event);
return 0;
}
static int sep_prepare_dcb_handler(struct sep_device *sep, unsigned long arg)
{
int error;
struct build_dcb_struct command_args;
if (copy_from_user(&command_args, (void __user *)arg,
sizeof(struct build_dcb_struct))) {
error = -EFAULT;
goto end_function;
}
dev_dbg(&sep->pdev->dev, "prep dcb handler app_in_address is %08llx\n",
command_args.app_in_address);
dev_dbg(&sep->pdev->dev, "app_out_address is %08llx\n",
command_args.app_out_address);
dev_dbg(&sep->pdev->dev, "data_size is %x\n",
command_args.data_in_size);
dev_dbg(&sep->pdev->dev, "block_size is %x\n",
command_args.block_size);
dev_dbg(&sep->pdev->dev, "tail block_size is %x\n",
command_args.tail_block_size);
error = sep_prepare_input_output_dma_table_in_dcb(sep,
(unsigned long)command_args.app_in_address,
(unsigned long)command_args.app_out_address,
command_args.data_in_size, command_args.block_size,
command_args.tail_block_size, true, false);
end_function:
return error;
}
static int sep_free_dcb_handler(struct sep_device *sep)
{
return sep_free_dma_tables_and_dcb(sep, false, false);
}
static int sep_rar_prepare_output_msg_handler(struct sep_device *sep,
unsigned long arg)
{
int error = 0;
struct rar_hndl_to_bus_struct command_args;
dma_addr_t rar_bus = 0;
u32 *rar_addr;
if (copy_from_user(&command_args, (void __user *)arg,
sizeof(command_args))) {
error = -EFAULT;
goto end_function;
}
if (command_args.rar_handle)
return -EOPNOTSUPP;
dev_dbg(&sep->pdev->dev, "rar msg; rar_addr_bus = %x\n", (u32)rar_bus);
rar_addr = (u32 *)(sep->shared_addr +
SEP_DRIVER_SYSTEM_RAR_MEMORY_OFFSET_IN_BYTES);
rar_addr[0] = SEP_RAR_VAL_TOKEN;
rar_addr[1] = rar_bus;
end_function:
return error;
}
static long sep_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
int error = 0;
struct sep_device *sep = filp->private_data;
mutex_lock(&sep->sep_mutex);
if ((current->pid != sep->pid_doing_transaction) &&
(sep->pid_doing_transaction != 0)) {
dev_dbg(&sep->pdev->dev, "ioctl pid is not owner\n");
error = -EACCES;
goto end_function;
}
mutex_unlock(&sep->sep_mutex);
if (_IOC_TYPE(cmd) != SEP_IOC_MAGIC_NUMBER)
return -ENOTTY;
mutex_lock(&sep->ioctl_mutex);
switch (cmd) {
case SEP_IOCSENDSEPCOMMAND:
error = sep_send_command_handler(sep);
break;
case SEP_IOCALLOCDATAPOLL:
error = sep_allocate_data_pool_memory_handler(sep, arg);
break;
case SEP_IOCGETSTATICPOOLADDR:
error = sep_get_static_pool_addr_handler(sep);
break;
case SEP_IOCENDTRANSACTION:
error = sep_end_transaction_handler(sep);
break;
case SEP_IOCRARPREPAREMESSAGE:
error = sep_rar_prepare_output_msg_handler(sep, arg);
break;
case SEP_IOCPREPAREDCB:
error = sep_prepare_dcb_handler(sep, arg);
break;
case SEP_IOCFREEDCB:
error = sep_free_dcb_handler(sep);
break;
default:
error = -ENOTTY;
break;
}
end_function:
mutex_unlock(&sep->ioctl_mutex);
return error;
}
static long sep_singleton_ioctl(struct file *filp, u32 cmd, unsigned long arg)
{
long error = 0;
struct sep_device *sep = filp->private_data;
if (_IOC_TYPE(cmd) != SEP_IOC_MAGIC_NUMBER)
return -ENOTTY;
mutex_lock(&sep->sep_mutex);
if ((current->pid != sep->pid_doing_transaction) &&
(sep->pid_doing_transaction != 0)) {
dev_dbg(&sep->pdev->dev, "singleton ioctl pid is not owner\n");
mutex_unlock(&sep->sep_mutex);
return -EACCES;
}
mutex_unlock(&sep->sep_mutex);
switch (cmd) {
case SEP_IOCTLSETCALLERID:
mutex_lock(&sep->ioctl_mutex);
error = sep_set_caller_id_handler(sep, arg);
mutex_unlock(&sep->ioctl_mutex);
break;
default:
error = sep_ioctl(filp, cmd, arg);
break;
}
return error;
}
static long sep_request_daemon_ioctl(struct file *filp, u32 cmd,
unsigned long arg)
{
long error;
struct sep_device *sep = filp->private_data;
if (_IOC_TYPE(cmd) != SEP_IOC_MAGIC_NUMBER)
return -ENOTTY;
mutex_lock(&sep->ioctl_mutex);
switch (cmd) {
case SEP_IOCSENDSEPRPLYCOMMAND:
error = sep_req_daemon_send_reply_command_handler(sep);
break;
case SEP_IOCENDTRANSACTION:
error = 0;
break;
default:
error = -ENOTTY;
}
mutex_unlock(&sep->ioctl_mutex);
return error;
}
static irqreturn_t sep_inthandler(int irq, void *dev_id)
{
irqreturn_t int_error = IRQ_HANDLED;
unsigned long lck_flags;
u32 reg_val, reg_val2 = 0;
struct sep_device *sep = dev_id;
reg_val = sep_read_reg(sep, HW_HOST_IRR_REG_ADDR);
if (reg_val & (0x1 << 13)) {
spin_lock_irqsave(&sep->snd_rply_lck, lck_flags);
sep->reply_ct++;
spin_unlock_irqrestore(&sep->snd_rply_lck, lck_flags);
dev_dbg(&sep->pdev->dev, "sep int: send_ct %lx reply_ct %lx\n",
sep->send_ct, sep->reply_ct);
reg_val2 = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR2_REG_ADDR);
dev_dbg(&sep->pdev->dev,
"SEP Interrupt - reg2 is %08x\n", reg_val2);
if ((reg_val2 >> 30) & 0x1) {
dev_dbg(&sep->pdev->dev, "int: printf request\n");
wake_up(&sep->event_request_daemon);
} else if (reg_val2 >> 31) {
dev_dbg(&sep->pdev->dev, "int: daemon request\n");
wake_up(&sep->event_request_daemon);
} else {
dev_dbg(&sep->pdev->dev, "int: SEP reply\n");
wake_up(&sep->event);
}
} else {
dev_dbg(&sep->pdev->dev, "int: not SEP interrupt\n");
int_error = IRQ_NONE;
}
if (int_error == IRQ_HANDLED)
sep_write_reg(sep, HW_HOST_ICR_REG_ADDR, reg_val);
return int_error;
}
static int sep_reconfig_shared_area(struct sep_device *sep)
{
int ret_val;
unsigned long end_time;
dev_dbg(&sep->pdev->dev, "reconfig shared; sending %08llx to sep\n",
(unsigned long long)sep->shared_bus);
sep_write_reg(sep, HW_HOST_HOST_SEP_GPR1_REG_ADDR, sep->shared_bus);
ret_val = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR1_REG_ADDR);
end_time = jiffies + (WAIT_TIME * HZ);
while ((time_before(jiffies, end_time)) && (ret_val != 0xffffffff) &&
(ret_val != sep->shared_bus))
ret_val = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR1_REG_ADDR);
if (ret_val != sep->shared_bus) {
dev_warn(&sep->pdev->dev, "could not reconfig shared area\n");
dev_warn(&sep->pdev->dev, "result was %x\n", ret_val);
ret_val = -ENOMEM;
} else
ret_val = 0;
dev_dbg(&sep->pdev->dev, "reconfig shared area end\n");
return ret_val;
}
static int sep_register_driver_with_fs(struct sep_device *sep)
{
int ret_val;
sep->miscdev_sep.minor = MISC_DYNAMIC_MINOR;
sep->miscdev_sep.name = SEP_DEV_NAME;
sep->miscdev_sep.fops = &sep_file_operations;
sep->miscdev_singleton.minor = MISC_DYNAMIC_MINOR;
sep->miscdev_singleton.name = SEP_DEV_SINGLETON;
sep->miscdev_singleton.fops = &singleton_file_operations;
sep->miscdev_daemon.minor = MISC_DYNAMIC_MINOR;
sep->miscdev_daemon.name = SEP_DEV_DAEMON;
sep->miscdev_daemon.fops = &daemon_file_operations;
ret_val = misc_register(&sep->miscdev_sep);
if (ret_val) {
dev_warn(&sep->pdev->dev, "misc reg fails for SEP %x\n",
ret_val);
return ret_val;
}
ret_val = misc_register(&sep->miscdev_singleton);
if (ret_val) {
dev_warn(&sep->pdev->dev, "misc reg fails for sing %x\n",
ret_val);
misc_deregister(&sep->miscdev_sep);
return ret_val;
}
ret_val = misc_register(&sep->miscdev_daemon);
if (ret_val) {
dev_warn(&sep->pdev->dev, "misc reg fails for dmn %x\n",
ret_val);
misc_deregister(&sep->miscdev_sep);
misc_deregister(&sep->miscdev_singleton);
return ret_val;
}
return ret_val;
}
static int __devinit sep_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int error = 0;
struct sep_device *sep;
if (sep_dev != NULL) {
dev_warn(&pdev->dev, "only one SEP supported.\n");
return -EBUSY;
}
error = pci_enable_device(pdev);
if (error) {
dev_warn(&pdev->dev, "error enabling pci device\n");
goto end_function;
}
sep_dev = kzalloc(sizeof(struct sep_device), GFP_ATOMIC);
if (sep_dev == NULL) {
dev_warn(&pdev->dev,
"can't kmalloc the sep_device structure\n");
error = -ENOMEM;
goto end_function_disable_device;
}
sep = sep_dev;
sep->pdev = pci_dev_get(pdev);
init_waitqueue_head(&sep->event);
init_waitqueue_head(&sep->event_request_daemon);
spin_lock_init(&sep->snd_rply_lck);
mutex_init(&sep->sep_mutex);
mutex_init(&sep->ioctl_mutex);
dev_dbg(&sep->pdev->dev, "sep probe: PCI obtained, device being prepared\n");
dev_dbg(&sep->pdev->dev, "revision is %d\n", sep->pdev->revision);
sep->reg_physical_addr = pci_resource_start(sep->pdev, 0);
if (!sep->reg_physical_addr) {
dev_warn(&sep->pdev->dev, "Error getting register start\n");
error = -ENODEV;
goto end_function_free_sep_dev;
}
sep->reg_physical_end = pci_resource_end(sep->pdev, 0);
if (!sep->reg_physical_end) {
dev_warn(&sep->pdev->dev, "Error getting register end\n");
error = -ENODEV;
goto end_function_free_sep_dev;
}
sep->reg_addr = ioremap_nocache(sep->reg_physical_addr,
(size_t)(sep->reg_physical_end - sep->reg_physical_addr + 1));
if (!sep->reg_addr) {
dev_warn(&sep->pdev->dev, "Error getting register virtual\n");
error = -ENODEV;
goto end_function_free_sep_dev;
}
dev_dbg(&sep->pdev->dev,
"Register area start %llx end %llx virtual %p\n",
(unsigned long long)sep->reg_physical_addr,
(unsigned long long)sep->reg_physical_end,
sep->reg_addr);
sep->shared_size = SEP_DRIVER_MESSAGE_SHARED_AREA_SIZE_IN_BYTES +
SYNCHRONIC_DMA_TABLES_AREA_SIZE_BYTES +
SEP_DRIVER_DATA_POOL_SHARED_AREA_SIZE_IN_BYTES +
SEP_DRIVER_STATIC_AREA_SIZE_IN_BYTES +
SEP_DRIVER_SYSTEM_DATA_MEMORY_SIZE_IN_BYTES;
if (sep_map_and_alloc_shared_area(sep)) {
error = -ENOMEM;
goto end_function_error;
}
sep_write_reg(sep, HW_HOST_ICR_REG_ADDR, 0xFFFFFFFF);
sep_write_reg(sep, HW_HOST_IMR_REG_ADDR, (~(0x1 << 13)));
sep->reply_ct = sep_read_reg(sep, HW_HOST_SEP_HOST_GPR2_REG_ADDR);
sep->reply_ct &= 0x3FFFFFFF;
sep->send_ct = sep->reply_ct;
error = request_irq(pdev->irq, sep_inthandler, IRQF_SHARED,
"sep_driver", sep);
if (error)
goto end_function_deallocate_sep_shared_area;
if (sep->pdev->revision == 4) {
error = sep_reconfig_shared_area(sep);
if (error)
goto end_function_free_irq;
}
error = sep_register_driver_with_fs(sep);
if (error == 0)
return 0;
end_function_free_irq:
free_irq(pdev->irq, sep);
end_function_deallocate_sep_shared_area:
sep_unmap_and_free_shared_area(sep);
end_function_error:
iounmap(sep->reg_addr);
end_function_free_sep_dev:
pci_dev_put(sep_dev->pdev);
kfree(sep_dev);
sep_dev = NULL;
end_function_disable_device:
pci_disable_device(pdev);
end_function:
return error;
}
static void sep_remove(struct pci_dev *pdev)
{
struct sep_device *sep = sep_dev;
misc_deregister(&sep->miscdev_sep);
misc_deregister(&sep->miscdev_singleton);
misc_deregister(&sep->miscdev_daemon);
free_irq(sep->pdev->irq, sep);
sep_unmap_and_free_shared_area(sep_dev);
iounmap((void *) sep_dev->reg_addr);
}
static int __init sep_init(void)
{
return pci_register_driver(&sep_pci_driver);
}
static void __exit sep_exit(void)
{
pci_unregister_driver(&sep_pci_driver);
}
