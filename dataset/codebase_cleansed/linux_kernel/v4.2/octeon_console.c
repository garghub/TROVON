static inline u64 __cvmx_bootmem_desc_get(struct octeon_device *oct,
u64 base,
u32 offset,
u32 size)
{
base = (1ull << 63) | (base + offset);
switch (size) {
case 4:
return octeon_read_device_mem32(oct, base);
case 8:
return octeon_read_device_mem64(oct, base);
default:
return 0;
}
}
static void CVMX_BOOTMEM_NAMED_GET_NAME(struct octeon_device *oct,
u64 addr,
char *str,
u32 len)
{
addr += offsetof(struct cvmx_bootmem_named_block_desc, name);
octeon_pci_read_core_mem(oct, addr, str, len);
str[len] = 0;
}
static int __cvmx_bootmem_check_version(struct octeon_device *oct,
u32 exact_match)
{
u32 major_version;
u32 minor_version;
if (!oct->bootmem_desc_addr)
oct->bootmem_desc_addr =
octeon_read_device_mem64(oct,
BOOTLOADER_PCI_READ_DESC_ADDR);
major_version =
(u32)CVMX_BOOTMEM_DESC_GET_FIELD(oct, major_version);
minor_version =
(u32)CVMX_BOOTMEM_DESC_GET_FIELD(oct, minor_version);
dev_dbg(&oct->pci_dev->dev, "%s: major_version=%d\n", __func__,
major_version);
if ((major_version > 3) ||
(exact_match && major_version != exact_match)) {
dev_err(&oct->pci_dev->dev, "bootmem ver mismatch %d.%d addr:0x%llx\n",
major_version, minor_version,
CAST_ULL(oct->bootmem_desc_addr));
return -1;
} else {
return 0;
}
}
static const struct cvmx_bootmem_named_block_desc
*__cvmx_bootmem_find_named_block_flags(struct octeon_device *oct,
const char *name, u32 flags)
{
struct cvmx_bootmem_named_block_desc *desc =
&oct->bootmem_named_block_desc;
u64 named_addr = cvmx_bootmem_phy_named_block_find(oct, name, flags);
if (named_addr) {
desc->base_addr = CVMX_BOOTMEM_NAMED_GET_FIELD(oct, named_addr,
base_addr);
desc->size =
CVMX_BOOTMEM_NAMED_GET_FIELD(oct, named_addr, size);
strncpy(desc->name, name, sizeof(desc->name));
desc->name[sizeof(desc->name) - 1] = 0;
return &oct->bootmem_named_block_desc;
} else {
return NULL;
}
}
static u64 cvmx_bootmem_phy_named_block_find(struct octeon_device *oct,
const char *name,
u32 flags)
{
u64 result = 0;
__cvmx_bootmem_lock(flags);
if (!__cvmx_bootmem_check_version(oct, 3)) {
u32 i;
u64 named_block_array_addr =
CVMX_BOOTMEM_DESC_GET_FIELD(oct,
named_block_array_addr);
u32 num_blocks = (u32)
CVMX_BOOTMEM_DESC_GET_FIELD(oct, nb_num_blocks);
u32 name_length = (u32)
CVMX_BOOTMEM_DESC_GET_FIELD(oct, named_block_name_len);
u64 named_addr = named_block_array_addr;
for (i = 0; i < num_blocks; i++) {
u64 named_size =
CVMX_BOOTMEM_NAMED_GET_FIELD(oct, named_addr,
size);
if (name && named_size) {
char *name_tmp =
kmalloc(name_length + 1, GFP_KERNEL);
CVMX_BOOTMEM_NAMED_GET_NAME(oct, named_addr,
name_tmp,
name_length);
if (!strncmp(name, name_tmp, name_length)) {
result = named_addr;
kfree(name_tmp);
break;
}
kfree(name_tmp);
} else if (!name && !named_size) {
result = named_addr;
break;
}
named_addr +=
sizeof(struct cvmx_bootmem_named_block_desc);
}
}
__cvmx_bootmem_unlock(flags);
return result;
}
static int octeon_named_block_find(struct octeon_device *oct, const char *name,
u64 *base_addr, u64 *size)
{
const struct cvmx_bootmem_named_block_desc *named_block;
octeon_remote_lock();
named_block = __cvmx_bootmem_find_named_block_flags(oct, name, 0);
octeon_remote_unlock();
if (named_block) {
*base_addr = named_block->base_addr;
*size = named_block->size;
return 0;
}
return 1;
}
static void octeon_remote_lock(void)
{
}
static void octeon_remote_unlock(void)
{
}
int octeon_console_send_cmd(struct octeon_device *oct, char *cmd_str,
u32 wait_hundredths)
{
u32 len = strlen(cmd_str);
dev_dbg(&oct->pci_dev->dev, "sending \"%s\" to bootloader\n", cmd_str);
if (len > BOOTLOADER_PCI_WRITE_BUFFER_STR_LEN - 1) {
dev_err(&oct->pci_dev->dev, "Command string too long, max length is: %d\n",
BOOTLOADER_PCI_WRITE_BUFFER_STR_LEN - 1);
return -1;
}
if (octeon_wait_for_bootloader(oct, wait_hundredths) != 0) {
dev_err(&oct->pci_dev->dev, "Bootloader not ready for command.\n");
return -1;
}
octeon_remote_lock();
octeon_pci_write_core_mem(oct, BOOTLOADER_PCI_READ_BUFFER_DATA_ADDR,
(u8 *)cmd_str, len);
octeon_write_device_mem32(oct, BOOTLOADER_PCI_READ_BUFFER_LEN_ADDR,
len);
octeon_write_device_mem32(oct, BOOTLOADER_PCI_READ_BUFFER_OWNER_ADDR,
OCTEON_PCI_IO_BUF_OWNER_OCTEON);
if (octeon_wait_for_bootloader(oct, 200) != 0) {
octeon_remote_unlock();
dev_err(&oct->pci_dev->dev, "Bootloader did not accept command.\n");
return -1;
}
octeon_remote_unlock();
return 0;
}
int octeon_wait_for_bootloader(struct octeon_device *oct,
u32 wait_time_hundredths)
{
dev_dbg(&oct->pci_dev->dev, "waiting %d0 ms for bootloader\n",
wait_time_hundredths);
if (octeon_mem_access_ok(oct))
return -1;
while (wait_time_hundredths > 0 &&
octeon_read_device_mem32(oct,
BOOTLOADER_PCI_READ_BUFFER_OWNER_ADDR)
!= OCTEON_PCI_IO_BUF_OWNER_HOST) {
if (--wait_time_hundredths <= 0)
return -1;
schedule_timeout_uninterruptible(HZ / 100);
}
return 0;
}
static void octeon_console_handle_result(struct octeon_device *oct,
size_t console_num,
char *buffer, s32 bytes_read)
{
struct octeon_console *console;
console = &oct->console[console_num];
console->waiting = 0;
}
static void output_console_line(struct octeon_device *oct,
struct octeon_console *console,
size_t console_num,
char *console_buffer,
s32 bytes_read)
{
char *line;
s32 i;
line = console_buffer;
for (i = 0; i < bytes_read; i++) {
if (console_buffer[i] == '\n') {
console_buffer[i] = '\0';
if (console->leftover[0]) {
dev_info(&oct->pci_dev->dev, "%lu: %s%s\n",
console_num, console->leftover,
line);
console->leftover[0] = '\0';
} else {
dev_info(&oct->pci_dev->dev, "%lu: %s\n",
console_num, line);
}
line = &console_buffer[i + 1];
}
}
if (line != &console_buffer[bytes_read]) {
console_buffer[bytes_read] = '\0';
strcpy(console->leftover, line);
}
}
static void check_console(struct work_struct *work)
{
s32 bytes_read, tries, total_read;
struct octeon_console *console;
struct cavium_wk *wk = (struct cavium_wk *)work;
struct octeon_device *oct = (struct octeon_device *)wk->ctxptr;
size_t console_num = wk->ctxul;
u32 delay;
console = &oct->console[console_num];
tries = 0;
total_read = 0;
do {
bytes_read =
octeon_console_read(oct, console_num, console_buffer,
sizeof(console_buffer) - 1, 0);
if (bytes_read > 0) {
total_read += bytes_read;
if (console->waiting) {
octeon_console_handle_result(oct, console_num,
console_buffer,
bytes_read);
}
if (octeon_console_debug_enabled(console_num)) {
output_console_line(oct, console, console_num,
console_buffer, bytes_read);
}
} else if (bytes_read < 0) {
dev_err(&oct->pci_dev->dev, "Error reading console %lu, ret=%d\n",
console_num, bytes_read);
}
tries++;
} while ((bytes_read > 0) && (tries < 16));
if (octeon_console_debug_enabled(console_num) &&
(total_read == 0) && (console->leftover[0])) {
dev_info(&oct->pci_dev->dev, "%lu: %s\n",
console_num, console->leftover);
console->leftover[0] = '\0';
}
delay = OCTEON_CONSOLE_POLL_INTERVAL_MS;
schedule_delayed_work(&wk->work, msecs_to_jiffies(delay));
}
int octeon_init_consoles(struct octeon_device *oct)
{
int ret = 0;
u64 addr, size;
ret = octeon_mem_access_ok(oct);
if (ret) {
dev_err(&oct->pci_dev->dev, "Memory access not okay'\n");
return ret;
}
ret = octeon_named_block_find(oct, OCTEON_PCI_CONSOLE_BLOCK_NAME, &addr,
&size);
if (ret) {
dev_err(&oct->pci_dev->dev, "Could not find console '%s'\n",
OCTEON_PCI_CONSOLE_BLOCK_NAME);
return ret;
}
oct->num_consoles = octeon_read_device_mem32(oct,
addr + offsetof(struct octeon_pci_console_desc,
num_consoles));
oct->console_desc_addr = addr;
dev_dbg(&oct->pci_dev->dev, "Initialized consoles. %d available\n",
oct->num_consoles);
return ret;
}
int octeon_add_console(struct octeon_device *oct, u32 console_num)
{
int ret = 0;
u32 delay;
u64 coreaddr;
struct delayed_work *work;
struct octeon_console *console;
if (console_num >= oct->num_consoles) {
dev_err(&oct->pci_dev->dev,
"trying to read from console number %d when only 0 to %d exist\n",
console_num, oct->num_consoles);
} else {
console = &oct->console[console_num];
console->waiting = 0;
coreaddr = oct->console_desc_addr + console_num * 8 +
offsetof(struct octeon_pci_console_desc,
console_addr_array);
console->addr = octeon_read_device_mem64(oct, coreaddr);
coreaddr = console->addr + offsetof(struct octeon_pci_console,
buf_size);
console->buffer_size = octeon_read_device_mem32(oct, coreaddr);
coreaddr = console->addr + offsetof(struct octeon_pci_console,
input_base_addr);
console->input_base_addr =
octeon_read_device_mem64(oct, coreaddr);
coreaddr = console->addr + offsetof(struct octeon_pci_console,
output_base_addr);
console->output_base_addr =
octeon_read_device_mem64(oct, coreaddr);
console->leftover[0] = '\0';
work = &oct->console_poll_work[console_num].work;
INIT_DELAYED_WORK(work, check_console);
oct->console_poll_work[console_num].ctxptr = (void *)oct;
oct->console_poll_work[console_num].ctxul = console_num;
delay = OCTEON_CONSOLE_POLL_INTERVAL_MS;
schedule_delayed_work(work, msecs_to_jiffies(delay));
if (octeon_console_debug_enabled(console_num)) {
ret = octeon_console_send_cmd(oct,
"setenv pci_console_active 1",
2000);
}
console->active = 1;
}
return ret;
}
void octeon_remove_consoles(struct octeon_device *oct)
{
u32 i;
struct octeon_console *console;
for (i = 0; i < oct->num_consoles; i++) {
console = &oct->console[i];
if (!console->active)
continue;
cancel_delayed_work_sync(&oct->console_poll_work[i].
work);
console->addr = 0;
console->buffer_size = 0;
console->input_base_addr = 0;
console->output_base_addr = 0;
}
oct->num_consoles = 0;
}
static inline int octeon_console_free_bytes(u32 buffer_size,
u32 wr_idx,
u32 rd_idx)
{
if (rd_idx >= buffer_size || wr_idx >= buffer_size)
return -1;
return ((buffer_size - 1) - (wr_idx - rd_idx)) % buffer_size;
}
static inline int octeon_console_avail_bytes(u32 buffer_size,
u32 wr_idx,
u32 rd_idx)
{
if (rd_idx >= buffer_size || wr_idx >= buffer_size)
return -1;
return buffer_size - 1 -
octeon_console_free_bytes(buffer_size, wr_idx, rd_idx);
}
int octeon_console_read(struct octeon_device *oct, u32 console_num,
char *buffer, u32 buf_size, u32 flags)
{
int bytes_to_read;
u32 rd_idx, wr_idx;
struct octeon_console *console;
if (console_num >= oct->num_consoles) {
dev_err(&oct->pci_dev->dev, "Attempted to read from disabled console %d\n",
console_num);
return 0;
}
console = &oct->console[console_num];
rd_idx = octeon_read_device_mem32(oct, console->addr +
offsetof(struct octeon_pci_console, output_read_index));
wr_idx = octeon_read_device_mem32(oct, console->addr +
offsetof(struct octeon_pci_console, output_write_index));
bytes_to_read = octeon_console_avail_bytes(console->buffer_size,
wr_idx, rd_idx);
if (bytes_to_read <= 0)
return bytes_to_read;
bytes_to_read = MIN(bytes_to_read, (s32)buf_size);
if (rd_idx + bytes_to_read >= console->buffer_size)
bytes_to_read = console->buffer_size - rd_idx;
octeon_pci_read_core_mem(oct, console->output_base_addr + rd_idx,
buffer, bytes_to_read);
octeon_write_device_mem32(oct, console->addr +
offsetof(struct octeon_pci_console,
output_read_index),
(rd_idx + bytes_to_read) %
console->buffer_size);
return bytes_to_read;
}
