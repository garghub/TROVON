static void qlcnic_read_dump_reg(u32 addr, void __iomem *bar0, u32 *data)
{
u32 dest;
void __iomem *window_reg;
dest = addr & 0xFFFF0000;
window_reg = bar0 + QLCNIC_FW_DUMP_REG1;
writel(dest, window_reg);
readl(window_reg);
window_reg = bar0 + QLCNIC_FW_DUMP_REG2 + LSW(addr);
*data = readl(window_reg);
}
static void qlcnic_write_dump_reg(u32 addr, void __iomem *bar0, u32 data)
{
u32 dest;
void __iomem *window_reg;
dest = addr & 0xFFFF0000;
window_reg = bar0 + QLCNIC_FW_DUMP_REG1;
writel(dest, window_reg);
readl(window_reg);
window_reg = bar0 + QLCNIC_FW_DUMP_REG2 + LSW(addr);
writel(data, window_reg);
readl(window_reg);
}
static u32 qlcnic_dump_crb(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i;
u32 addr, data;
struct __crb *crb = &entry->region.crb;
void __iomem *base = adapter->ahw->pci_base0;
addr = crb->addr;
for (i = 0; i < crb->no_ops; i++) {
qlcnic_read_dump_reg(addr, base, &data);
*buffer++ = cpu_to_le32(addr);
*buffer++ = cpu_to_le32(data);
addr += crb->stride;
}
return crb->no_ops * 2 * sizeof(u32);
}
static u32 qlcnic_dump_ctrl(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i, k, timeout = 0;
void __iomem *base = adapter->ahw->pci_base0;
u32 addr, data;
u8 no_ops;
struct __ctrl *ctr = &entry->region.ctrl;
struct qlcnic_dump_template_hdr *t_hdr = adapter->ahw->fw_dump.tmpl_hdr;
addr = ctr->addr;
no_ops = ctr->no_ops;
for (i = 0; i < no_ops; i++) {
k = 0;
for (k = 0; k < 8; k++) {
if (!(ctr->opcode & (1 << k)))
continue;
switch (1 << k) {
case QLCNIC_DUMP_WCRB:
qlcnic_write_dump_reg(addr, base, ctr->val1);
break;
case QLCNIC_DUMP_RWCRB:
qlcnic_read_dump_reg(addr, base, &data);
qlcnic_write_dump_reg(addr, base, data);
break;
case QLCNIC_DUMP_ANDCRB:
qlcnic_read_dump_reg(addr, base, &data);
qlcnic_write_dump_reg(addr, base,
data & ctr->val2);
break;
case QLCNIC_DUMP_ORCRB:
qlcnic_read_dump_reg(addr, base, &data);
qlcnic_write_dump_reg(addr, base,
data | ctr->val3);
break;
case QLCNIC_DUMP_POLLCRB:
while (timeout <= ctr->timeout) {
qlcnic_read_dump_reg(addr, base, &data);
if ((data & ctr->val2) == ctr->val1)
break;
msleep(1);
timeout++;
}
if (timeout > ctr->timeout) {
dev_info(&adapter->pdev->dev,
"Timed out, aborting poll CRB\n");
return -EINVAL;
}
break;
case QLCNIC_DUMP_RD_SAVE:
if (ctr->index_a)
addr = t_hdr->saved_state[ctr->index_a];
qlcnic_read_dump_reg(addr, base, &data);
t_hdr->saved_state[ctr->index_v] = data;
break;
case QLCNIC_DUMP_WRT_SAVED:
if (ctr->index_v)
data = t_hdr->saved_state[ctr->index_v];
else
data = ctr->val1;
if (ctr->index_a)
addr = t_hdr->saved_state[ctr->index_a];
qlcnic_write_dump_reg(addr, base, data);
break;
case QLCNIC_DUMP_MOD_SAVE_ST:
data = t_hdr->saved_state[ctr->index_v];
data <<= ctr->shl_val;
data >>= ctr->shr_val;
if (ctr->val2)
data &= ctr->val2;
data |= ctr->val3;
data += ctr->val1;
t_hdr->saved_state[ctr->index_v] = data;
break;
default:
dev_info(&adapter->pdev->dev,
"Unknown opcode\n");
break;
}
}
addr += ctr->stride;
}
return 0;
}
static u32 qlcnic_dump_mux(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int loop;
u32 val, data = 0;
struct __mux *mux = &entry->region.mux;
void __iomem *base = adapter->ahw->pci_base0;
val = mux->val;
for (loop = 0; loop < mux->no_ops; loop++) {
qlcnic_write_dump_reg(mux->addr, base, val);
qlcnic_read_dump_reg(mux->read_addr, base, &data);
*buffer++ = cpu_to_le32(val);
*buffer++ = cpu_to_le32(data);
val += mux->val_stride;
}
return 2 * mux->no_ops * sizeof(u32);
}
static u32 qlcnic_dump_que(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i, loop;
u32 cnt, addr, data, que_id = 0;
void __iomem *base = adapter->ahw->pci_base0;
struct __queue *que = &entry->region.que;
addr = que->read_addr;
cnt = que->read_addr_cnt;
for (loop = 0; loop < que->no_ops; loop++) {
qlcnic_write_dump_reg(que->sel_addr, base, que_id);
addr = que->read_addr;
for (i = 0; i < cnt; i++) {
qlcnic_read_dump_reg(addr, base, &data);
*buffer++ = cpu_to_le32(data);
addr += que->read_addr_stride;
}
que_id += que->stride;
}
return que->no_ops * cnt * sizeof(u32);
}
static u32 qlcnic_dump_ocm(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i;
u32 data;
void __iomem *addr;
struct __ocm *ocm = &entry->region.ocm;
addr = adapter->ahw->pci_base0 + ocm->read_addr;
for (i = 0; i < ocm->no_ops; i++) {
data = readl(addr);
*buffer++ = cpu_to_le32(data);
addr += ocm->read_addr_stride;
}
return ocm->no_ops * sizeof(u32);
}
static u32 qlcnic_read_rom(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i, count = 0;
u32 fl_addr, size, val, lck_val, addr;
struct __mem *rom = &entry->region.mem;
void __iomem *base = adapter->ahw->pci_base0;
fl_addr = rom->addr;
size = rom->size/4;
lock_try:
lck_val = readl(base + QLCNIC_FLASH_SEM2_LK);
if (!lck_val && count < MAX_CTL_CHECK) {
msleep(10);
count++;
goto lock_try;
}
writel(adapter->ahw->pci_func, (base + QLCNIC_FLASH_LOCK_ID));
for (i = 0; i < size; i++) {
addr = fl_addr & 0xFFFF0000;
qlcnic_write_dump_reg(FLASH_ROM_WINDOW, base, addr);
addr = LSW(fl_addr) + FLASH_ROM_DATA;
qlcnic_read_dump_reg(addr, base, &val);
fl_addr += 4;
*buffer++ = cpu_to_le32(val);
}
readl(base + QLCNIC_FLASH_SEM2_ULK);
return rom->size;
}
static u32 qlcnic_dump_l1_cache(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i;
u32 cnt, val, data, addr;
void __iomem *base = adapter->ahw->pci_base0;
struct __cache *l1 = &entry->region.cache;
val = l1->init_tag_val;
for (i = 0; i < l1->no_ops; i++) {
qlcnic_write_dump_reg(l1->addr, base, val);
qlcnic_write_dump_reg(l1->ctrl_addr, base, LSW(l1->ctrl_val));
addr = l1->read_addr;
cnt = l1->read_addr_num;
while (cnt) {
qlcnic_read_dump_reg(addr, base, &data);
*buffer++ = cpu_to_le32(data);
addr += l1->read_addr_stride;
cnt--;
}
val += l1->stride;
}
return l1->no_ops * l1->read_addr_num * sizeof(u32);
}
static u32 qlcnic_dump_l2_cache(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
int i;
u32 cnt, val, data, addr;
u8 poll_mask, poll_to, time_out = 0;
void __iomem *base = adapter->ahw->pci_base0;
struct __cache *l2 = &entry->region.cache;
val = l2->init_tag_val;
poll_mask = LSB(MSW(l2->ctrl_val));
poll_to = MSB(MSW(l2->ctrl_val));
for (i = 0; i < l2->no_ops; i++) {
qlcnic_write_dump_reg(l2->addr, base, val);
if (LSW(l2->ctrl_val))
qlcnic_write_dump_reg(l2->ctrl_addr, base,
LSW(l2->ctrl_val));
if (!poll_mask)
goto skip_poll;
do {
qlcnic_read_dump_reg(l2->ctrl_addr, base, &data);
if (!(data & poll_mask))
break;
msleep(1);
time_out++;
} while (time_out <= poll_to);
if (time_out > poll_to) {
dev_err(&adapter->pdev->dev,
"Timeout exceeded in %s, aborting dump\n",
__func__);
return -EINVAL;
}
skip_poll:
addr = l2->read_addr;
cnt = l2->read_addr_num;
while (cnt) {
qlcnic_read_dump_reg(addr, base, &data);
*buffer++ = cpu_to_le32(data);
addr += l2->read_addr_stride;
cnt--;
}
val += l2->stride;
}
return l2->no_ops * l2->read_addr_num * sizeof(u32);
}
static u32 qlcnic_read_memory(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
u32 addr, data, test, ret = 0;
int i, reg_read;
struct __mem *mem = &entry->region.mem;
void __iomem *base = adapter->ahw->pci_base0;
reg_read = mem->size;
addr = mem->addr;
if ((addr & 0xf) || (reg_read%16)) {
dev_info(&adapter->pdev->dev,
"Unaligned memory addr:0x%x size:0x%x\n",
addr, reg_read);
return -EINVAL;
}
mutex_lock(&adapter->ahw->mem_lock);
while (reg_read != 0) {
qlcnic_write_dump_reg(MIU_TEST_ADDR_LO, base, addr);
qlcnic_write_dump_reg(MIU_TEST_ADDR_HI, base, 0);
qlcnic_write_dump_reg(MIU_TEST_CTR, base,
TA_CTL_ENABLE | TA_CTL_START);
for (i = 0; i < MAX_CTL_CHECK; i++) {
qlcnic_read_dump_reg(MIU_TEST_CTR, base, &test);
if (!(test & TA_CTL_BUSY))
break;
}
if (i == MAX_CTL_CHECK) {
if (printk_ratelimit()) {
dev_err(&adapter->pdev->dev,
"failed to read through agent\n");
ret = -EINVAL;
goto out;
}
}
for (i = 0; i < 4; i++) {
qlcnic_read_dump_reg(MIU_TEST_READ_DATA[i], base,
&data);
*buffer++ = cpu_to_le32(data);
}
addr += 16;
reg_read -= 16;
ret += 16;
}
out:
mutex_unlock(&adapter->ahw->mem_lock);
return mem->size;
}
static u32 qlcnic_dump_nop(struct qlcnic_adapter *adapter,
struct qlcnic_dump_entry *entry, __le32 *buffer)
{
entry->hdr.flags |= QLCNIC_DUMP_SKIP;
return 0;
}
static int
qlcnic_valid_dump_entry(struct device *dev, struct qlcnic_dump_entry *entry,
u32 size)
{
int ret = 1;
if (size != entry->hdr.cap_size) {
dev_info(dev,
"Invalid dump, Type:%d\tMask:%d\tSize:%dCap_size:%d\n",
entry->hdr.type, entry->hdr.mask, size, entry->hdr.cap_size);
dev_info(dev, "Aborting further dump capture\n");
ret = 0;
}
return ret;
}
int qlcnic_dump_fw(struct qlcnic_adapter *adapter)
{
__le32 *buffer;
char mesg[64];
char *msg[] = {mesg, NULL};
int i, k, ops_cnt, ops_index, dump_size = 0;
u32 entry_offset, dump, no_entries, buf_offset = 0;
struct qlcnic_dump_entry *entry;
struct qlcnic_fw_dump *fw_dump = &adapter->ahw->fw_dump;
struct qlcnic_dump_template_hdr *tmpl_hdr = fw_dump->tmpl_hdr;
if (fw_dump->clr) {
dev_info(&adapter->pdev->dev,
"Previous dump not cleared, not capturing dump\n");
return -EIO;
}
for (i = 2, k = 1; (i & QLCNIC_DUMP_MASK_MAX); i <<= 1, k++)
if (i & tmpl_hdr->drv_cap_mask)
dump_size += tmpl_hdr->cap_sizes[k];
if (!dump_size)
return -EIO;
fw_dump->data = vzalloc(dump_size);
if (!fw_dump->data) {
dev_info(&adapter->pdev->dev,
"Unable to allocate (%d KB) for fw dump\n",
dump_size / 1024);
return -ENOMEM;
}
buffer = fw_dump->data;
fw_dump->size = dump_size;
no_entries = tmpl_hdr->num_entries;
ops_cnt = ARRAY_SIZE(fw_dump_ops);
entry_offset = tmpl_hdr->offset;
tmpl_hdr->sys_info[0] = QLCNIC_DRIVER_VERSION;
tmpl_hdr->sys_info[1] = adapter->fw_version;
for (i = 0; i < no_entries; i++) {
entry = (void *)tmpl_hdr + entry_offset;
if (!(entry->hdr.mask & tmpl_hdr->drv_cap_mask)) {
entry->hdr.flags |= QLCNIC_DUMP_SKIP;
entry_offset += entry->hdr.offset;
continue;
}
ops_index = 0;
while (ops_index < ops_cnt) {
if (entry->hdr.type == fw_dump_ops[ops_index].opcode)
break;
ops_index++;
}
if (ops_index == ops_cnt) {
dev_info(&adapter->pdev->dev,
"Invalid entry type %d, exiting dump\n",
entry->hdr.type);
goto error;
}
dump = fw_dump_ops[ops_index].handler(adapter, entry, buffer);
if (dump && !qlcnic_valid_dump_entry(&adapter->pdev->dev, entry,
dump))
entry->hdr.flags |= QLCNIC_DUMP_SKIP;
buf_offset += entry->hdr.cap_size;
entry_offset += entry->hdr.offset;
buffer = fw_dump->data + buf_offset;
}
if (dump_size != buf_offset) {
dev_info(&adapter->pdev->dev,
"Captured(%d) and expected size(%d) do not match\n",
buf_offset, dump_size);
goto error;
} else {
fw_dump->clr = 1;
snprintf(mesg, sizeof(mesg), "FW_DUMP=%s",
adapter->netdev->name);
dev_info(&adapter->pdev->dev, "Dump data, %d bytes captured\n",
fw_dump->size);
kobject_uevent_env(&adapter->pdev->dev.kobj, KOBJ_CHANGE, msg);
return 0;
}
error:
vfree(fw_dump->data);
return -EINVAL;
}
