static void tcmu_cmd_free_data(struct tcmu_cmd *tcmu_cmd, uint32_t len)
{
struct tcmu_dev *udev = tcmu_cmd->tcmu_dev;
uint32_t i;
for (i = 0; i < len; i++)
clear_bit(tcmu_cmd->dbi[i], udev->data_bitmap);
}
static inline bool tcmu_get_empty_block(struct tcmu_dev *udev,
struct tcmu_cmd *tcmu_cmd)
{
struct page *page;
int ret, dbi;
dbi = find_first_zero_bit(udev->data_bitmap, udev->dbi_thresh);
if (dbi == udev->dbi_thresh)
return false;
page = radix_tree_lookup(&udev->data_blocks, dbi);
if (!page) {
if (atomic_add_return(1, &global_db_count) >
TCMU_GLOBAL_MAX_BLOCKS) {
atomic_dec(&global_db_count);
return false;
}
page = alloc_page(GFP_KERNEL);
if (!page)
return false;
ret = radix_tree_insert(&udev->data_blocks, dbi, page);
if (ret) {
__free_page(page);
return false;
}
}
if (dbi > udev->dbi_max)
udev->dbi_max = dbi;
set_bit(dbi, udev->data_bitmap);
tcmu_cmd_set_dbi(tcmu_cmd, dbi);
return true;
}
static bool tcmu_get_empty_blocks(struct tcmu_dev *udev,
struct tcmu_cmd *tcmu_cmd)
{
int i;
udev->waiting_global = false;
for (i = tcmu_cmd->dbi_cur; i < tcmu_cmd->dbi_cnt; i++) {
if (!tcmu_get_empty_block(udev, tcmu_cmd))
goto err;
}
return true;
err:
udev->waiting_global = true;
wake_up(&unmap_wait);
return false;
}
static inline struct page *
tcmu_get_block_page(struct tcmu_dev *udev, uint32_t dbi)
{
return radix_tree_lookup(&udev->data_blocks, dbi);
}
static inline void tcmu_free_cmd(struct tcmu_cmd *tcmu_cmd)
{
kfree(tcmu_cmd->dbi);
kmem_cache_free(tcmu_cmd_cache, tcmu_cmd);
}
static inline size_t tcmu_cmd_get_data_length(struct tcmu_cmd *tcmu_cmd)
{
struct se_cmd *se_cmd = tcmu_cmd->se_cmd;
size_t data_length = round_up(se_cmd->data_length, DATA_BLOCK_SIZE);
if (se_cmd->se_cmd_flags & SCF_BIDI) {
BUG_ON(!(se_cmd->t_bidi_data_sg && se_cmd->t_bidi_data_nents));
data_length += round_up(se_cmd->t_bidi_data_sg->length,
DATA_BLOCK_SIZE);
}
return data_length;
}
static inline uint32_t tcmu_cmd_get_block_cnt(struct tcmu_cmd *tcmu_cmd)
{
size_t data_length = tcmu_cmd_get_data_length(tcmu_cmd);
return data_length / DATA_BLOCK_SIZE;
}
static struct tcmu_cmd *tcmu_alloc_cmd(struct se_cmd *se_cmd)
{
struct se_device *se_dev = se_cmd->se_dev;
struct tcmu_dev *udev = TCMU_DEV(se_dev);
struct tcmu_cmd *tcmu_cmd;
int cmd_id;
tcmu_cmd = kmem_cache_zalloc(tcmu_cmd_cache, GFP_KERNEL);
if (!tcmu_cmd)
return NULL;
tcmu_cmd->se_cmd = se_cmd;
tcmu_cmd->tcmu_dev = udev;
if (udev->cmd_time_out)
tcmu_cmd->deadline = jiffies +
msecs_to_jiffies(udev->cmd_time_out);
tcmu_cmd_reset_dbi_cur(tcmu_cmd);
tcmu_cmd->dbi_cnt = tcmu_cmd_get_block_cnt(tcmu_cmd);
tcmu_cmd->dbi = kcalloc(tcmu_cmd->dbi_cnt, sizeof(uint32_t),
GFP_KERNEL);
if (!tcmu_cmd->dbi) {
kmem_cache_free(tcmu_cmd_cache, tcmu_cmd);
return NULL;
}
idr_preload(GFP_KERNEL);
spin_lock_irq(&udev->commands_lock);
cmd_id = idr_alloc(&udev->commands, tcmu_cmd, 0,
USHRT_MAX, GFP_NOWAIT);
spin_unlock_irq(&udev->commands_lock);
idr_preload_end();
if (cmd_id < 0) {
tcmu_free_cmd(tcmu_cmd);
return NULL;
}
tcmu_cmd->cmd_id = cmd_id;
return tcmu_cmd;
}
static inline void tcmu_flush_dcache_range(void *vaddr, size_t size)
{
unsigned long offset = offset_in_page(vaddr);
size = round_up(size+offset, PAGE_SIZE);
vaddr -= offset;
while (size) {
flush_dcache_page(virt_to_page(vaddr));
size -= PAGE_SIZE;
}
}
static inline size_t spc_used(size_t head, size_t tail, size_t size)
{
int diff = head - tail;
if (diff >= 0)
return diff;
else
return size + diff;
}
static inline size_t spc_free(size_t head, size_t tail, size_t size)
{
return (size - spc_used(head, tail, size) - 1);
}
static inline size_t head_to_end(size_t head, size_t size)
{
return size - head;
}
static inline void new_iov(struct iovec **iov, int *iov_cnt,
struct tcmu_dev *udev)
{
struct iovec *iovec;
if (*iov_cnt != 0)
(*iov)++;
(*iov_cnt)++;
iovec = *iov;
memset(iovec, 0, sizeof(struct iovec));
}
static inline size_t get_block_offset_user(struct tcmu_dev *dev,
int dbi, int remaining)
{
return dev->data_off + dbi * DATA_BLOCK_SIZE +
DATA_BLOCK_SIZE - remaining;
}
static inline size_t iov_tail(struct tcmu_dev *udev, struct iovec *iov)
{
return (size_t)iov->iov_base + iov->iov_len;
}
static int scatter_data_area(struct tcmu_dev *udev,
struct tcmu_cmd *tcmu_cmd, struct scatterlist *data_sg,
unsigned int data_nents, struct iovec **iov,
int *iov_cnt, bool copy_data)
{
int i, dbi;
int block_remaining = 0;
void *from, *to = NULL;
size_t copy_bytes, to_offset, offset;
struct scatterlist *sg;
struct page *page;
for_each_sg(data_sg, sg, data_nents, i) {
int sg_remaining = sg->length;
from = kmap_atomic(sg_page(sg)) + sg->offset;
while (sg_remaining > 0) {
if (block_remaining == 0) {
if (to)
kunmap_atomic(to);
block_remaining = DATA_BLOCK_SIZE;
dbi = tcmu_cmd_get_dbi(tcmu_cmd);
page = tcmu_get_block_page(udev, dbi);
to = kmap_atomic(page);
}
copy_bytes = min_t(size_t, sg_remaining,
block_remaining);
to_offset = get_block_offset_user(udev, dbi,
block_remaining);
offset = DATA_BLOCK_SIZE - block_remaining;
to = (void *)(unsigned long)to + offset;
if (*iov_cnt != 0 &&
to_offset == iov_tail(udev, *iov)) {
(*iov)->iov_len += copy_bytes;
} else {
new_iov(iov, iov_cnt, udev);
(*iov)->iov_base = (void __user *)to_offset;
(*iov)->iov_len = copy_bytes;
}
if (copy_data) {
memcpy(to, from + sg->length - sg_remaining,
copy_bytes);
tcmu_flush_dcache_range(to, copy_bytes);
}
sg_remaining -= copy_bytes;
block_remaining -= copy_bytes;
}
kunmap_atomic(from - sg->offset);
}
if (to)
kunmap_atomic(to);
return 0;
}
static void gather_data_area(struct tcmu_dev *udev, struct tcmu_cmd *cmd,
bool bidi)
{
struct se_cmd *se_cmd = cmd->se_cmd;
int i, dbi;
int block_remaining = 0;
void *from = NULL, *to;
size_t copy_bytes, offset;
struct scatterlist *sg, *data_sg;
struct page *page;
unsigned int data_nents;
uint32_t count = 0;
if (!bidi) {
data_sg = se_cmd->t_data_sg;
data_nents = se_cmd->t_data_nents;
} else {
count = DIV_ROUND_UP(se_cmd->data_length, DATA_BLOCK_SIZE);
data_sg = se_cmd->t_bidi_data_sg;
data_nents = se_cmd->t_bidi_data_nents;
}
tcmu_cmd_set_dbi_cur(cmd, count);
for_each_sg(data_sg, sg, data_nents, i) {
int sg_remaining = sg->length;
to = kmap_atomic(sg_page(sg)) + sg->offset;
while (sg_remaining > 0) {
if (block_remaining == 0) {
if (from)
kunmap_atomic(from);
block_remaining = DATA_BLOCK_SIZE;
dbi = tcmu_cmd_get_dbi(cmd);
page = tcmu_get_block_page(udev, dbi);
from = kmap_atomic(page);
}
copy_bytes = min_t(size_t, sg_remaining,
block_remaining);
offset = DATA_BLOCK_SIZE - block_remaining;
from = (void *)(unsigned long)from + offset;
tcmu_flush_dcache_range(from, copy_bytes);
memcpy(to + sg->length - sg_remaining, from,
copy_bytes);
sg_remaining -= copy_bytes;
block_remaining -= copy_bytes;
}
kunmap_atomic(to - sg->offset);
}
if (from)
kunmap_atomic(from);
}
static inline size_t spc_bitmap_free(unsigned long *bitmap, uint32_t thresh)
{
return DATA_BLOCK_SIZE * (thresh - bitmap_weight(bitmap, thresh));
}
static bool is_ring_space_avail(struct tcmu_dev *udev, struct tcmu_cmd *cmd,
size_t cmd_size, size_t data_needed)
{
struct tcmu_mailbox *mb = udev->mb_addr;
uint32_t blocks_needed = (data_needed + DATA_BLOCK_SIZE - 1)
/ DATA_BLOCK_SIZE;
size_t space, cmd_needed;
u32 cmd_head;
tcmu_flush_dcache_range(mb, sizeof(*mb));
cmd_head = mb->cmd_head % udev->cmdr_size;
if (head_to_end(cmd_head, udev->cmdr_size) >= cmd_size)
cmd_needed = cmd_size;
else
cmd_needed = cmd_size + head_to_end(cmd_head, udev->cmdr_size);
space = spc_free(cmd_head, udev->cmdr_last_cleaned, udev->cmdr_size);
if (space < cmd_needed) {
pr_debug("no cmd space: %u %u %u\n", cmd_head,
udev->cmdr_last_cleaned, udev->cmdr_size);
return false;
}
space = spc_bitmap_free(udev->data_bitmap, udev->dbi_thresh);
if (space < data_needed) {
unsigned long blocks_left = DATA_BLOCK_BITS - udev->dbi_thresh;
unsigned long grow;
if (blocks_left < blocks_needed) {
pr_debug("no data space: only %lu available, but ask for %zu\n",
blocks_left * DATA_BLOCK_SIZE,
data_needed);
return false;
}
if (!udev->dbi_thresh) {
uint32_t init_thresh = DATA_BLOCK_INIT_BITS;
udev->dbi_thresh = max(blocks_needed, init_thresh);
} else {
grow = max(blocks_needed, udev->dbi_thresh / 2);
udev->dbi_thresh += grow;
if (udev->dbi_thresh > DATA_BLOCK_BITS)
udev->dbi_thresh = DATA_BLOCK_BITS;
}
}
if (!tcmu_get_empty_blocks(udev, cmd))
return false;
return true;
}
static inline size_t tcmu_cmd_get_base_cmd_size(size_t iov_cnt)
{
return max(offsetof(struct tcmu_cmd_entry, req.iov[iov_cnt]),
sizeof(struct tcmu_cmd_entry));
}
static inline size_t tcmu_cmd_get_cmd_size(struct tcmu_cmd *tcmu_cmd,
size_t base_command_size)
{
struct se_cmd *se_cmd = tcmu_cmd->se_cmd;
size_t command_size;
command_size = base_command_size +
round_up(scsi_command_size(se_cmd->t_task_cdb),
TCMU_OP_ALIGN_SIZE);
WARN_ON(command_size & (TCMU_OP_ALIGN_SIZE-1));
return command_size;
}
static sense_reason_t
tcmu_queue_cmd_ring(struct tcmu_cmd *tcmu_cmd)
{
struct tcmu_dev *udev = tcmu_cmd->tcmu_dev;
struct se_cmd *se_cmd = tcmu_cmd->se_cmd;
size_t base_command_size, command_size;
struct tcmu_mailbox *mb;
struct tcmu_cmd_entry *entry;
struct iovec *iov;
int iov_cnt, ret;
uint32_t cmd_head;
uint64_t cdb_off;
bool copy_to_data_area;
size_t data_length = tcmu_cmd_get_data_length(tcmu_cmd);
if (test_bit(TCMU_DEV_BIT_BROKEN, &udev->flags))
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
base_command_size = tcmu_cmd_get_base_cmd_size(tcmu_cmd->dbi_cnt);
command_size = tcmu_cmd_get_cmd_size(tcmu_cmd, base_command_size);
mutex_lock(&udev->cmdr_lock);
mb = udev->mb_addr;
cmd_head = mb->cmd_head % udev->cmdr_size;
if ((command_size > (udev->cmdr_size / 2)) ||
data_length > udev->data_size) {
pr_warn("TCMU: Request of size %zu/%zu is too big for %u/%zu "
"cmd ring/data area\n", command_size, data_length,
udev->cmdr_size, udev->data_size);
mutex_unlock(&udev->cmdr_lock);
return TCM_INVALID_CDB_FIELD;
}
while (!is_ring_space_avail(udev, tcmu_cmd, command_size, data_length)) {
int ret;
DEFINE_WAIT(__wait);
prepare_to_wait(&udev->wait_cmdr, &__wait, TASK_INTERRUPTIBLE);
pr_debug("sleeping for ring space\n");
mutex_unlock(&udev->cmdr_lock);
if (udev->cmd_time_out)
ret = schedule_timeout(
msecs_to_jiffies(udev->cmd_time_out));
else
ret = schedule_timeout(msecs_to_jiffies(TCMU_TIME_OUT));
finish_wait(&udev->wait_cmdr, &__wait);
if (!ret) {
pr_warn("tcmu: command timed out\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
mutex_lock(&udev->cmdr_lock);
cmd_head = mb->cmd_head % udev->cmdr_size;
}
if (head_to_end(cmd_head, udev->cmdr_size) < command_size) {
size_t pad_size = head_to_end(cmd_head, udev->cmdr_size);
entry = (void *) mb + CMDR_OFF + cmd_head;
tcmu_flush_dcache_range(entry, sizeof(*entry));
tcmu_hdr_set_op(&entry->hdr.len_op, TCMU_OP_PAD);
tcmu_hdr_set_len(&entry->hdr.len_op, pad_size);
entry->hdr.cmd_id = 0;
entry->hdr.kflags = 0;
entry->hdr.uflags = 0;
UPDATE_HEAD(mb->cmd_head, pad_size, udev->cmdr_size);
cmd_head = mb->cmd_head % udev->cmdr_size;
WARN_ON(cmd_head != 0);
}
entry = (void *) mb + CMDR_OFF + cmd_head;
tcmu_flush_dcache_range(entry, sizeof(*entry));
tcmu_hdr_set_op(&entry->hdr.len_op, TCMU_OP_CMD);
entry->hdr.cmd_id = tcmu_cmd->cmd_id;
entry->hdr.kflags = 0;
entry->hdr.uflags = 0;
tcmu_cmd_reset_dbi_cur(tcmu_cmd);
iov = &entry->req.iov[0];
iov_cnt = 0;
copy_to_data_area = (se_cmd->data_direction == DMA_TO_DEVICE
|| se_cmd->se_cmd_flags & SCF_BIDI);
ret = scatter_data_area(udev, tcmu_cmd, se_cmd->t_data_sg,
se_cmd->t_data_nents, &iov, &iov_cnt,
copy_to_data_area);
if (ret) {
tcmu_cmd_free_data(tcmu_cmd, tcmu_cmd->dbi_cnt);
mutex_unlock(&udev->cmdr_lock);
pr_err("tcmu: alloc and scatter data failed\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
entry->req.iov_cnt = iov_cnt;
entry->req.iov_dif_cnt = 0;
if (se_cmd->se_cmd_flags & SCF_BIDI) {
iov_cnt = 0;
iov++;
ret = scatter_data_area(udev, tcmu_cmd,
se_cmd->t_bidi_data_sg,
se_cmd->t_bidi_data_nents,
&iov, &iov_cnt, false);
if (ret) {
tcmu_cmd_free_data(tcmu_cmd, tcmu_cmd->dbi_cnt);
mutex_unlock(&udev->cmdr_lock);
pr_err("tcmu: alloc and scatter bidi data failed\n");
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
}
entry->req.iov_bidi_cnt = iov_cnt;
}
base_command_size = tcmu_cmd_get_base_cmd_size(entry->req.iov_cnt +
entry->req.iov_bidi_cnt);
command_size = tcmu_cmd_get_cmd_size(tcmu_cmd, base_command_size);
tcmu_hdr_set_len(&entry->hdr.len_op, command_size);
cdb_off = CMDR_OFF + cmd_head + base_command_size;
memcpy((void *) mb + cdb_off, se_cmd->t_task_cdb, scsi_command_size(se_cmd->t_task_cdb));
entry->req.cdb_off = cdb_off;
tcmu_flush_dcache_range(entry, sizeof(*entry));
UPDATE_HEAD(mb->cmd_head, command_size, udev->cmdr_size);
tcmu_flush_dcache_range(mb, sizeof(*mb));
mutex_unlock(&udev->cmdr_lock);
uio_event_notify(&udev->uio_info);
if (udev->cmd_time_out)
mod_timer(&udev->timeout, round_jiffies_up(jiffies +
msecs_to_jiffies(udev->cmd_time_out)));
return TCM_NO_SENSE;
}
static sense_reason_t
tcmu_queue_cmd(struct se_cmd *se_cmd)
{
struct se_device *se_dev = se_cmd->se_dev;
struct tcmu_dev *udev = TCMU_DEV(se_dev);
struct tcmu_cmd *tcmu_cmd;
sense_reason_t ret;
tcmu_cmd = tcmu_alloc_cmd(se_cmd);
if (!tcmu_cmd)
return TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
ret = tcmu_queue_cmd_ring(tcmu_cmd);
if (ret != TCM_NO_SENSE) {
pr_err("TCMU: Could not queue command\n");
spin_lock_irq(&udev->commands_lock);
idr_remove(&udev->commands, tcmu_cmd->cmd_id);
spin_unlock_irq(&udev->commands_lock);
tcmu_free_cmd(tcmu_cmd);
}
return ret;
}
static void tcmu_handle_completion(struct tcmu_cmd *cmd, struct tcmu_cmd_entry *entry)
{
struct se_cmd *se_cmd = cmd->se_cmd;
struct tcmu_dev *udev = cmd->tcmu_dev;
if (test_bit(TCMU_CMD_BIT_EXPIRED, &cmd->flags))
goto out;
tcmu_cmd_reset_dbi_cur(cmd);
if (entry->hdr.uflags & TCMU_UFLAG_UNKNOWN_OP) {
pr_warn("TCMU: Userspace set UNKNOWN_OP flag on se_cmd %p\n",
cmd->se_cmd);
entry->rsp.scsi_status = SAM_STAT_CHECK_CONDITION;
} else if (entry->rsp.scsi_status == SAM_STAT_CHECK_CONDITION) {
memcpy(se_cmd->sense_buffer, entry->rsp.sense_buffer,
se_cmd->scsi_sense_length);
} else if (se_cmd->se_cmd_flags & SCF_BIDI) {
gather_data_area(udev, cmd, true);
} else if (se_cmd->data_direction == DMA_FROM_DEVICE) {
gather_data_area(udev, cmd, false);
} else if (se_cmd->data_direction == DMA_TO_DEVICE) {
} else if (se_cmd->data_direction != DMA_NONE) {
pr_warn("TCMU: data direction was %d!\n",
se_cmd->data_direction);
}
target_complete_cmd(cmd->se_cmd, entry->rsp.scsi_status);
out:
cmd->se_cmd = NULL;
tcmu_cmd_free_data(cmd, cmd->dbi_cnt);
tcmu_free_cmd(cmd);
}
static unsigned int tcmu_handle_completions(struct tcmu_dev *udev)
{
struct tcmu_mailbox *mb;
int handled = 0;
if (test_bit(TCMU_DEV_BIT_BROKEN, &udev->flags)) {
pr_err("ring broken, not handling completions\n");
return 0;
}
mb = udev->mb_addr;
tcmu_flush_dcache_range(mb, sizeof(*mb));
while (udev->cmdr_last_cleaned != ACCESS_ONCE(mb->cmd_tail)) {
struct tcmu_cmd_entry *entry = (void *) mb + CMDR_OFF + udev->cmdr_last_cleaned;
struct tcmu_cmd *cmd;
tcmu_flush_dcache_range(entry, sizeof(*entry));
if (tcmu_hdr_get_op(entry->hdr.len_op) == TCMU_OP_PAD) {
UPDATE_HEAD(udev->cmdr_last_cleaned,
tcmu_hdr_get_len(entry->hdr.len_op),
udev->cmdr_size);
continue;
}
WARN_ON(tcmu_hdr_get_op(entry->hdr.len_op) != TCMU_OP_CMD);
spin_lock(&udev->commands_lock);
cmd = idr_remove(&udev->commands, entry->hdr.cmd_id);
spin_unlock(&udev->commands_lock);
if (!cmd) {
pr_err("cmd_id not found, ring is broken\n");
set_bit(TCMU_DEV_BIT_BROKEN, &udev->flags);
break;
}
tcmu_handle_completion(cmd, entry);
UPDATE_HEAD(udev->cmdr_last_cleaned,
tcmu_hdr_get_len(entry->hdr.len_op),
udev->cmdr_size);
handled++;
}
if (mb->cmd_tail == mb->cmd_head)
del_timer(&udev->timeout);
wake_up(&udev->wait_cmdr);
return handled;
}
static int tcmu_check_expired_cmd(int id, void *p, void *data)
{
struct tcmu_cmd *cmd = p;
if (test_bit(TCMU_CMD_BIT_EXPIRED, &cmd->flags))
return 0;
if (!time_after(jiffies, cmd->deadline))
return 0;
set_bit(TCMU_CMD_BIT_EXPIRED, &cmd->flags);
target_complete_cmd(cmd->se_cmd, SAM_STAT_CHECK_CONDITION);
cmd->se_cmd = NULL;
return 0;
}
static void tcmu_device_timedout(unsigned long data)
{
struct tcmu_dev *udev = (struct tcmu_dev *)data;
unsigned long flags;
spin_lock_irqsave(&udev->commands_lock, flags);
idr_for_each(&udev->commands, tcmu_check_expired_cmd, NULL);
spin_unlock_irqrestore(&udev->commands_lock, flags);
wake_up(&unmap_wait);
}
static int tcmu_attach_hba(struct se_hba *hba, u32 host_id)
{
struct tcmu_hba *tcmu_hba;
tcmu_hba = kzalloc(sizeof(struct tcmu_hba), GFP_KERNEL);
if (!tcmu_hba)
return -ENOMEM;
tcmu_hba->host_id = host_id;
hba->hba_ptr = tcmu_hba;
return 0;
}
static void tcmu_detach_hba(struct se_hba *hba)
{
kfree(hba->hba_ptr);
hba->hba_ptr = NULL;
}
static struct se_device *tcmu_alloc_device(struct se_hba *hba, const char *name)
{
struct tcmu_dev *udev;
udev = kzalloc(sizeof(struct tcmu_dev), GFP_KERNEL);
if (!udev)
return NULL;
kref_init(&udev->kref);
udev->name = kstrdup(name, GFP_KERNEL);
if (!udev->name) {
kfree(udev);
return NULL;
}
udev->hba = hba;
udev->cmd_time_out = TCMU_TIME_OUT;
init_waitqueue_head(&udev->wait_cmdr);
mutex_init(&udev->cmdr_lock);
idr_init(&udev->commands);
spin_lock_init(&udev->commands_lock);
setup_timer(&udev->timeout, tcmu_device_timedout,
(unsigned long)udev);
return &udev->se_dev;
}
static int tcmu_irqcontrol(struct uio_info *info, s32 irq_on)
{
struct tcmu_dev *tcmu_dev = container_of(info, struct tcmu_dev, uio_info);
mutex_lock(&tcmu_dev->cmdr_lock);
tcmu_handle_completions(tcmu_dev);
mutex_unlock(&tcmu_dev->cmdr_lock);
return 0;
}
static int tcmu_find_mem_index(struct vm_area_struct *vma)
{
struct tcmu_dev *udev = vma->vm_private_data;
struct uio_info *info = &udev->uio_info;
if (vma->vm_pgoff < MAX_UIO_MAPS) {
if (info->mem[vma->vm_pgoff].size == 0)
return -1;
return (int)vma->vm_pgoff;
}
return -1;
}
static struct page *tcmu_try_get_block_page(struct tcmu_dev *udev, uint32_t dbi)
{
struct page *page;
int ret;
mutex_lock(&udev->cmdr_lock);
page = tcmu_get_block_page(udev, dbi);
if (likely(page)) {
mutex_unlock(&udev->cmdr_lock);
return page;
}
pr_warn("Block(%u) out of cmd's iov[] has been touched!\n", dbi);
pr_warn("Mostly it will be a bug of userspace, please have a check!\n");
if (dbi >= udev->dbi_thresh) {
udev->dbi_thresh = dbi + 1;
udev->dbi_max = dbi;
}
page = radix_tree_lookup(&udev->data_blocks, dbi);
if (!page) {
page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!page) {
mutex_unlock(&udev->cmdr_lock);
return NULL;
}
ret = radix_tree_insert(&udev->data_blocks, dbi, page);
if (ret) {
mutex_unlock(&udev->cmdr_lock);
__free_page(page);
return NULL;
}
atomic_inc(&global_db_count);
}
mutex_unlock(&udev->cmdr_lock);
return page;
}
static int tcmu_vma_fault(struct vm_fault *vmf)
{
struct tcmu_dev *udev = vmf->vma->vm_private_data;
struct uio_info *info = &udev->uio_info;
struct page *page;
unsigned long offset;
void *addr;
int mi = tcmu_find_mem_index(vmf->vma);
if (mi < 0)
return VM_FAULT_SIGBUS;
offset = (vmf->pgoff - mi) << PAGE_SHIFT;
if (offset < udev->data_off) {
addr = (void *)(unsigned long)info->mem[mi].addr + offset;
page = vmalloc_to_page(addr);
} else {
uint32_t dbi;
dbi = (offset - udev->data_off) / DATA_BLOCK_SIZE;
page = tcmu_try_get_block_page(udev, dbi);
if (!page)
return VM_FAULT_NOPAGE;
}
get_page(page);
vmf->page = page;
return 0;
}
static int tcmu_mmap(struct uio_info *info, struct vm_area_struct *vma)
{
struct tcmu_dev *udev = container_of(info, struct tcmu_dev, uio_info);
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_ops = &tcmu_vm_ops;
vma->vm_private_data = udev;
if (vma_pages(vma) != (TCMU_RING_SIZE >> PAGE_SHIFT))
return -EINVAL;
return 0;
}
static int tcmu_open(struct uio_info *info, struct inode *inode)
{
struct tcmu_dev *udev = container_of(info, struct tcmu_dev, uio_info);
if (test_and_set_bit(TCMU_DEV_BIT_OPEN, &udev->flags))
return -EBUSY;
udev->inode = inode;
pr_debug("open\n");
return 0;
}
static void tcmu_dev_call_rcu(struct rcu_head *p)
{
struct se_device *dev = container_of(p, struct se_device, rcu_head);
struct tcmu_dev *udev = TCMU_DEV(dev);
kfree(udev->uio_info.name);
kfree(udev->name);
kfree(udev);
}
static void tcmu_dev_kref_release(struct kref *kref)
{
struct tcmu_dev *udev = container_of(kref, struct tcmu_dev, kref);
struct se_device *dev = &udev->se_dev;
call_rcu(&dev->rcu_head, tcmu_dev_call_rcu);
}
static int tcmu_release(struct uio_info *info, struct inode *inode)
{
struct tcmu_dev *udev = container_of(info, struct tcmu_dev, uio_info);
clear_bit(TCMU_DEV_BIT_OPEN, &udev->flags);
pr_debug("close\n");
kref_put(&udev->kref, tcmu_dev_kref_release);
return 0;
}
static int tcmu_netlink_event(enum tcmu_genl_cmd cmd, const char *name, int minor)
{
struct sk_buff *skb;
void *msg_header;
int ret = -ENOMEM;
skb = genlmsg_new(NLMSG_GOODSIZE, GFP_KERNEL);
if (!skb)
return ret;
msg_header = genlmsg_put(skb, 0, 0, &tcmu_genl_family, 0, cmd);
if (!msg_header)
goto free_skb;
ret = nla_put_string(skb, TCMU_ATTR_DEVICE, name);
if (ret < 0)
goto free_skb;
ret = nla_put_u32(skb, TCMU_ATTR_MINOR, minor);
if (ret < 0)
goto free_skb;
genlmsg_end(skb, msg_header);
ret = genlmsg_multicast_allns(&tcmu_genl_family, skb, 0,
TCMU_MCGRP_CONFIG, GFP_KERNEL);
if (ret == -ESRCH)
ret = 0;
return ret;
free_skb:
nlmsg_free(skb);
return ret;
}
static int tcmu_configure_device(struct se_device *dev)
{
struct tcmu_dev *udev = TCMU_DEV(dev);
struct tcmu_hba *hba = udev->hba->hba_ptr;
struct uio_info *info;
struct tcmu_mailbox *mb;
size_t size;
size_t used;
int ret = 0;
char *str;
info = &udev->uio_info;
size = snprintf(NULL, 0, "tcm-user/%u/%s/%s", hba->host_id, udev->name,
udev->dev_config);
size += 1;
str = kmalloc(size, GFP_KERNEL);
if (!str)
return -ENOMEM;
used = snprintf(str, size, "tcm-user/%u/%s", hba->host_id, udev->name);
if (udev->dev_config[0])
snprintf(str + used, size - used, "/%s", udev->dev_config);
info->name = str;
udev->mb_addr = vzalloc(CMDR_SIZE);
if (!udev->mb_addr) {
ret = -ENOMEM;
goto err_vzalloc;
}
udev->cmdr_size = CMDR_SIZE - CMDR_OFF;
udev->data_off = CMDR_SIZE;
udev->data_size = DATA_SIZE;
udev->dbi_thresh = 0;
udev->waiting_global = false;
mb = udev->mb_addr;
mb->version = TCMU_MAILBOX_VERSION;
mb->flags = TCMU_MAILBOX_FLAG_CAP_OOOC;
mb->cmdr_off = CMDR_OFF;
mb->cmdr_size = udev->cmdr_size;
WARN_ON(!PAGE_ALIGNED(udev->data_off));
WARN_ON(udev->data_size % PAGE_SIZE);
WARN_ON(udev->data_size % DATA_BLOCK_SIZE);
INIT_RADIX_TREE(&udev->data_blocks, GFP_KERNEL);
info->version = __stringify(TCMU_MAILBOX_VERSION);
info->mem[0].name = "tcm-user command & data buffer";
info->mem[0].addr = (phys_addr_t)(uintptr_t)udev->mb_addr;
info->mem[0].size = TCMU_RING_SIZE;
info->mem[0].memtype = UIO_MEM_NONE;
info->irqcontrol = tcmu_irqcontrol;
info->irq = UIO_IRQ_CUSTOM;
info->mmap = tcmu_mmap;
info->open = tcmu_open;
info->release = tcmu_release;
ret = uio_register_device(tcmu_root_device, info);
if (ret)
goto err_register;
if (dev->dev_attrib.hw_block_size == 0)
dev->dev_attrib.hw_block_size = 512;
if (!dev->dev_attrib.hw_max_sectors)
dev->dev_attrib.hw_max_sectors = 128;
dev->dev_attrib.hw_queue_depth = 128;
kref_get(&udev->kref);
ret = tcmu_netlink_event(TCMU_CMD_ADDED_DEVICE, udev->uio_info.name,
udev->uio_info.uio_dev->minor);
if (ret)
goto err_netlink;
mutex_lock(&root_udev_mutex);
list_add(&udev->node, &root_udev);
mutex_unlock(&root_udev_mutex);
return 0;
err_netlink:
kref_put(&udev->kref, tcmu_dev_kref_release);
uio_unregister_device(&udev->uio_info);
err_register:
vfree(udev->mb_addr);
err_vzalloc:
kfree(info->name);
info->name = NULL;
return ret;
}
static int tcmu_check_and_free_pending_cmd(struct tcmu_cmd *cmd)
{
if (test_bit(TCMU_CMD_BIT_EXPIRED, &cmd->flags)) {
kmem_cache_free(tcmu_cmd_cache, cmd);
return 0;
}
return -EINVAL;
}
static bool tcmu_dev_configured(struct tcmu_dev *udev)
{
return udev->uio_info.uio_dev ? true : false;
}
static void tcmu_blocks_release(struct tcmu_dev *udev)
{
int i;
struct page *page;
mutex_lock(&udev->cmdr_lock);
for (i = 0; i <= udev->dbi_max; i++) {
page = radix_tree_delete(&udev->data_blocks, i);
if (page) {
__free_page(page);
atomic_dec(&global_db_count);
}
}
mutex_unlock(&udev->cmdr_lock);
}
static void tcmu_free_device(struct se_device *dev)
{
struct tcmu_dev *udev = TCMU_DEV(dev);
struct tcmu_cmd *cmd;
bool all_expired = true;
int i;
del_timer_sync(&udev->timeout);
mutex_lock(&root_udev_mutex);
list_del(&udev->node);
mutex_unlock(&root_udev_mutex);
vfree(udev->mb_addr);
spin_lock_irq(&udev->commands_lock);
idr_for_each_entry(&udev->commands, cmd, i) {
if (tcmu_check_and_free_pending_cmd(cmd) != 0)
all_expired = false;
}
idr_destroy(&udev->commands);
spin_unlock_irq(&udev->commands_lock);
WARN_ON(!all_expired);
tcmu_blocks_release(udev);
if (tcmu_dev_configured(udev)) {
tcmu_netlink_event(TCMU_CMD_REMOVED_DEVICE, udev->uio_info.name,
udev->uio_info.uio_dev->minor);
uio_unregister_device(&udev->uio_info);
}
kref_put(&udev->kref, tcmu_dev_kref_release);
}
static int tcmu_set_dev_attrib(substring_t *arg, u32 *dev_attrib)
{
unsigned long tmp_ul;
char *arg_p;
int ret;
arg_p = match_strdup(arg);
if (!arg_p)
return -ENOMEM;
ret = kstrtoul(arg_p, 0, &tmp_ul);
kfree(arg_p);
if (ret < 0) {
pr_err("kstrtoul() failed for dev attrib\n");
return ret;
}
if (!tmp_ul) {
pr_err("dev attrib must be nonzero\n");
return -EINVAL;
}
*dev_attrib = tmp_ul;
return 0;
}
static ssize_t tcmu_set_configfs_dev_params(struct se_device *dev,
const char *page, ssize_t count)
{
struct tcmu_dev *udev = TCMU_DEV(dev);
char *orig, *ptr, *opts, *arg_p;
substring_t args[MAX_OPT_ARGS];
int ret = 0, token;
opts = kstrdup(page, GFP_KERNEL);
if (!opts)
return -ENOMEM;
orig = opts;
while ((ptr = strsep(&opts, ",\n")) != NULL) {
if (!*ptr)
continue;
token = match_token(ptr, tokens, args);
switch (token) {
case Opt_dev_config:
if (match_strlcpy(udev->dev_config, &args[0],
TCMU_CONFIG_LEN) == 0) {
ret = -EINVAL;
break;
}
pr_debug("TCMU: Referencing Path: %s\n", udev->dev_config);
break;
case Opt_dev_size:
arg_p = match_strdup(&args[0]);
if (!arg_p) {
ret = -ENOMEM;
break;
}
ret = kstrtoul(arg_p, 0, (unsigned long *) &udev->dev_size);
kfree(arg_p);
if (ret < 0)
pr_err("kstrtoul() failed for dev_size=\n");
break;
case Opt_hw_block_size:
ret = tcmu_set_dev_attrib(&args[0],
&(dev->dev_attrib.hw_block_size));
break;
case Opt_hw_max_sectors:
ret = tcmu_set_dev_attrib(&args[0],
&(dev->dev_attrib.hw_max_sectors));
break;
default:
break;
}
if (ret)
break;
}
kfree(orig);
return (!ret) ? count : ret;
}
static ssize_t tcmu_show_configfs_dev_params(struct se_device *dev, char *b)
{
struct tcmu_dev *udev = TCMU_DEV(dev);
ssize_t bl = 0;
bl = sprintf(b + bl, "Config: %s ",
udev->dev_config[0] ? udev->dev_config : "NULL");
bl += sprintf(b + bl, "Size: %zu\n", udev->dev_size);
return bl;
}
static sector_t tcmu_get_blocks(struct se_device *dev)
{
struct tcmu_dev *udev = TCMU_DEV(dev);
return div_u64(udev->dev_size - dev->dev_attrib.block_size,
dev->dev_attrib.block_size);
}
static sense_reason_t
tcmu_parse_cdb(struct se_cmd *cmd)
{
return passthrough_parse_cdb(cmd, tcmu_queue_cmd);
}
static ssize_t tcmu_cmd_time_out_show(struct config_item *item, char *page)
{
struct se_dev_attrib *da = container_of(to_config_group(item),
struct se_dev_attrib, da_group);
struct tcmu_dev *udev = container_of(da->da_dev,
struct tcmu_dev, se_dev);
return snprintf(page, PAGE_SIZE, "%lu\n", udev->cmd_time_out / MSEC_PER_SEC);
}
static ssize_t tcmu_cmd_time_out_store(struct config_item *item, const char *page,
size_t count)
{
struct se_dev_attrib *da = container_of(to_config_group(item),
struct se_dev_attrib, da_group);
struct tcmu_dev *udev = container_of(da->da_dev,
struct tcmu_dev, se_dev);
u32 val;
int ret;
if (da->da_dev->export_count) {
pr_err("Unable to set tcmu cmd_time_out while exports exist\n");
return -EINVAL;
}
ret = kstrtou32(page, 0, &val);
if (ret < 0)
return ret;
udev->cmd_time_out = val * MSEC_PER_SEC;
return count;
}
static int unmap_thread_fn(void *data)
{
struct tcmu_dev *udev;
loff_t off;
uint32_t start, end, block;
struct page *page;
int i;
while (1) {
DEFINE_WAIT(__wait);
prepare_to_wait(&unmap_wait, &__wait, TASK_INTERRUPTIBLE);
schedule();
finish_wait(&unmap_wait, &__wait);
if (kthread_should_stop())
break;
mutex_lock(&root_udev_mutex);
list_for_each_entry(udev, &root_udev, node) {
mutex_lock(&udev->cmdr_lock);
tcmu_handle_completions(udev);
if (udev->waiting_global || !udev->dbi_thresh) {
mutex_unlock(&udev->cmdr_lock);
continue;
}
end = udev->dbi_max + 1;
block = find_last_bit(udev->data_bitmap, end);
if (block == udev->dbi_max) {
mutex_unlock(&udev->cmdr_lock);
continue;
} else if (block == end) {
udev->dbi_thresh = start = 0;
udev->dbi_max = 0;
} else {
udev->dbi_thresh = start = block + 1;
udev->dbi_max = block;
}
off = udev->data_off + start * DATA_BLOCK_SIZE;
unmap_mapping_range(udev->inode->i_mapping, off, 0, 1);
for (i = start; i < end; i++) {
page = radix_tree_delete(&udev->data_blocks, i);
if (page) {
__free_page(page);
atomic_dec(&global_db_count);
}
}
mutex_unlock(&udev->cmdr_lock);
}
list_for_each_entry(udev, &root_udev, node) {
if (udev->waiting_global)
wake_up(&udev->wait_cmdr);
}
mutex_unlock(&root_udev_mutex);
}
return 0;
}
static int __init tcmu_module_init(void)
{
int ret, i, len = 0;
BUILD_BUG_ON((sizeof(struct tcmu_cmd_entry) % TCMU_OP_ALIGN_SIZE) != 0);
tcmu_cmd_cache = kmem_cache_create("tcmu_cmd_cache",
sizeof(struct tcmu_cmd),
__alignof__(struct tcmu_cmd),
0, NULL);
if (!tcmu_cmd_cache)
return -ENOMEM;
tcmu_root_device = root_device_register("tcm_user");
if (IS_ERR(tcmu_root_device)) {
ret = PTR_ERR(tcmu_root_device);
goto out_free_cache;
}
ret = genl_register_family(&tcmu_genl_family);
if (ret < 0) {
goto out_unreg_device;
}
for (i = 0; passthrough_attrib_attrs[i] != NULL; i++) {
len += sizeof(struct configfs_attribute *);
}
len += sizeof(struct configfs_attribute *) * 2;
tcmu_attrs = kzalloc(len, GFP_KERNEL);
if (!tcmu_attrs) {
ret = -ENOMEM;
goto out_unreg_genl;
}
for (i = 0; passthrough_attrib_attrs[i] != NULL; i++) {
tcmu_attrs[i] = passthrough_attrib_attrs[i];
}
tcmu_attrs[i] = &tcmu_attr_cmd_time_out;
tcmu_ops.tb_dev_attrib_attrs = tcmu_attrs;
ret = transport_backend_register(&tcmu_ops);
if (ret)
goto out_attrs;
init_waitqueue_head(&unmap_wait);
unmap_thread = kthread_run(unmap_thread_fn, NULL, "tcmu_unmap");
if (IS_ERR(unmap_thread)) {
ret = PTR_ERR(unmap_thread);
goto out_unreg_transport;
}
return 0;
out_unreg_transport:
target_backend_unregister(&tcmu_ops);
out_attrs:
kfree(tcmu_attrs);
out_unreg_genl:
genl_unregister_family(&tcmu_genl_family);
out_unreg_device:
root_device_unregister(tcmu_root_device);
out_free_cache:
kmem_cache_destroy(tcmu_cmd_cache);
return ret;
}
static void __exit tcmu_module_exit(void)
{
kthread_stop(unmap_thread);
target_backend_unregister(&tcmu_ops);
kfree(tcmu_attrs);
genl_unregister_family(&tcmu_genl_family);
root_device_unregister(tcmu_root_device);
kmem_cache_destroy(tcmu_cmd_cache);
}
