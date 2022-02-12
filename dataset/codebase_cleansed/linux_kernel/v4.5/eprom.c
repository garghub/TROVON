static void write_enable(struct hfi1_devdata *dd)
{
write_csr(dd, ASIC_GPIO_OUT,
read_csr(dd, ASIC_GPIO_OUT) | EPROM_WP_N);
write_csr(dd, ASIC_GPIO_OE,
read_csr(dd, ASIC_GPIO_OE) | EPROM_WP_N);
}
static void write_disable(struct hfi1_devdata *dd)
{
write_csr(dd, ASIC_GPIO_OUT,
read_csr(dd, ASIC_GPIO_OUT) & ~EPROM_WP_N);
write_csr(dd, ASIC_GPIO_OE,
read_csr(dd, ASIC_GPIO_OE) & ~EPROM_WP_N);
}
static int wait_for_not_busy(struct hfi1_devdata *dd)
{
unsigned long count = 0;
u64 reg;
int ret = 0;
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_READ_SR1);
while (1) {
udelay(WAIT_SLEEP_US);
usleep_range(WAIT_SLEEP_US - 5, WAIT_SLEEP_US + 5);
count++;
reg = read_csr(dd, ASIC_EEP_DATA);
if ((reg & SR1_BUSY) == 0)
break;
if (count > COUNT_DELAY_SEC(200)) {
dd_dev_err(dd, "waited too long for SPI FLASH busy to clear - failing\n");
ret = -ETIMEDOUT;
break;
}
}
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_NOP);
return ret;
}
static u32 read_device_id(struct hfi1_devdata *dd)
{
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_READ_MANUF_DEV_ID);
return (u32)read_csr(dd, ASIC_EEP_DATA);
}
static int erase_chip(struct hfi1_devdata *dd)
{
int ret;
write_enable(dd);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_WRITE_ENABLE);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_CHIP_ERASE);
ret = wait_for_not_busy(dd);
write_disable(dd);
return ret;
}
static int erase_range(struct hfi1_devdata *dd, u32 start, u32 len)
{
u32 end = start + len;
int ret = 0;
if (end < start)
return -EINVAL;
if ((start & MASK_4KB) || (end & MASK_4KB)) {
dd_dev_err(dd,
"%s: non-aligned range (0x%x,0x%x) for a 4KB erase\n",
__func__, start, end);
return -EINVAL;
}
write_enable(dd);
while (start < end) {
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_WRITE_ENABLE);
if (((start & MASK_64KB) == 0) && (start + SIZE_64KB <= end)) {
write_csr(dd, ASIC_EEP_ADDR_CMD,
CMD_SECTOR_ERASE_64KB(start));
start += SIZE_64KB;
} else if (((start & MASK_32KB) == 0) &&
(start + SIZE_32KB <= end)) {
write_csr(dd, ASIC_EEP_ADDR_CMD,
CMD_SECTOR_ERASE_32KB(start));
start += SIZE_32KB;
} else {
write_csr(dd, ASIC_EEP_ADDR_CMD,
CMD_SECTOR_ERASE_4KB(start));
start += SIZE_4KB;
}
ret = wait_for_not_busy(dd);
if (ret)
goto done;
}
done:
write_disable(dd);
return ret;
}
static void read_page(struct hfi1_devdata *dd, u32 offset, u32 *result)
{
int i;
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_READ_DATA(offset));
for (i = 0; i < EP_PAGE_SIZE/sizeof(u32); i++)
result[i] = (u32)read_csr(dd, ASIC_EEP_DATA);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_NOP);
}
static int read_length(struct hfi1_devdata *dd, u32 start, u32 len, u64 addr)
{
u32 offset;
u32 buffer[EP_PAGE_SIZE/sizeof(u32)];
int ret = 0;
if ((start & EEP_PAGE_MASK) || (len & EEP_PAGE_MASK))
return -EINVAL;
for (offset = 0; offset < len; offset += EP_PAGE_SIZE) {
read_page(dd, start + offset, buffer);
if (copy_to_user((void __user *)(addr + offset),
buffer, EP_PAGE_SIZE)) {
ret = -EFAULT;
goto done;
}
}
done:
return ret;
}
static int write_page(struct hfi1_devdata *dd, u32 offset, u32 *data)
{
int i;
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_WRITE_ENABLE);
write_csr(dd, ASIC_EEP_DATA, data[0]);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_PAGE_PROGRAM(offset));
for (i = 1; i < EP_PAGE_SIZE/sizeof(u32); i++)
write_csr(dd, ASIC_EEP_DATA, data[i]);
return wait_for_not_busy(dd);
}
static int write_length(struct hfi1_devdata *dd, u32 start, u32 len, u64 addr)
{
u32 offset;
u32 buffer[EP_PAGE_SIZE/sizeof(u32)];
int ret = 0;
if ((start & EEP_PAGE_MASK) || (len & EEP_PAGE_MASK))
return -EINVAL;
write_enable(dd);
for (offset = 0; offset < len; offset += EP_PAGE_SIZE) {
if (copy_from_user(buffer, (void __user *)(addr + offset),
EP_PAGE_SIZE)) {
ret = -EFAULT;
goto done;
}
ret = write_page(dd, start + offset, buffer);
if (ret)
goto done;
}
done:
write_disable(dd);
return ret;
}
static inline u32 extract_rlen(u32 composite)
{
return (composite & 0xffff) * EP_PAGE_SIZE;
}
static inline u32 extract_rstart(u32 composite)
{
return (composite >> 16) * EP_PAGE_SIZE;
}
int handle_eprom_command(const struct hfi1_cmd *cmd)
{
struct hfi1_devdata *dd;
u32 dev_id;
u32 rlen;
u32 rstart;
int ret = 0;
dd = hfi1_lookup(0);
if (!dd) {
pr_err("%s: cannot find unit 0!\n", __func__);
return -EINVAL;
}
mutex_lock(&eprom_mutex);
if (!eprom_available) {
ret = -ENOSYS;
goto done_asic;
}
ret = acquire_hw_mutex(dd);
if (ret) {
dd_dev_err(dd,
"%s: unable to acquire hw mutex, no EPROM support\n",
__func__);
goto done_asic;
}
dd_dev_info(dd, "%s: cmd: type %d, len 0x%x, addr 0x%016llx\n",
__func__, cmd->type, cmd->len, cmd->addr);
switch (cmd->type) {
case HFI1_CMD_EP_INFO:
if (cmd->len != sizeof(u32)) {
ret = -ERANGE;
break;
}
dev_id = read_device_id(dd);
if (copy_to_user((void __user *)cmd->addr, &dev_id,
sizeof(u32)))
ret = -EFAULT;
break;
case HFI1_CMD_EP_ERASE_CHIP:
ret = erase_chip(dd);
break;
case HFI1_CMD_EP_ERASE_RANGE:
rlen = extract_rlen(cmd->len);
rstart = extract_rstart(cmd->len);
ret = erase_range(dd, rstart, rlen);
break;
case HFI1_CMD_EP_READ_RANGE:
rlen = extract_rlen(cmd->len);
rstart = extract_rstart(cmd->len);
ret = read_length(dd, rstart, rlen, cmd->addr);
break;
case HFI1_CMD_EP_WRITE_RANGE:
rlen = extract_rlen(cmd->len);
rstart = extract_rstart(cmd->len);
ret = write_length(dd, rstart, rlen, cmd->addr);
break;
default:
dd_dev_err(dd, "%s: unexpected command %d\n",
__func__, cmd->type);
ret = -EINVAL;
break;
}
release_hw_mutex(dd);
done_asic:
mutex_unlock(&eprom_mutex);
return ret;
}
int eprom_init(struct hfi1_devdata *dd)
{
int ret = 0;
if (dd->pcidev->device != PCI_DEVICE_ID_INTEL0)
return 0;
mutex_lock(&eprom_mutex);
if (eprom_available)
goto done_asic;
ret = acquire_hw_mutex(dd);
if (ret) {
dd_dev_err(dd,
"%s: unable to acquire hw mutex, no EPROM support\n",
__func__);
goto done_asic;
}
write_csr(dd, ASIC_EEP_CTL_STAT,
ASIC_EEP_CTL_STAT_EP_RESET_SMASK);
write_csr(dd, ASIC_EEP_CTL_STAT,
EP_SPEED_FULL << ASIC_EEP_CTL_STAT_RATE_SPI_SHIFT);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_RELEASE_POWERDOWN_NOID);
eprom_available = 1;
release_hw_mutex(dd);
done_asic:
mutex_unlock(&eprom_mutex);
return ret;
}
