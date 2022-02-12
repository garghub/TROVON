static void read_page(struct hfi1_devdata *dd, u32 offset, u32 *result)
{
int i;
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_READ_DATA(offset));
for (i = 0; i < EP_PAGE_DWORDS; i++)
result[i] = (u32)read_csr(dd, ASIC_EEP_DATA);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_NOP);
}
static int read_length(struct hfi1_devdata *dd, u32 start, u32 len, void *dest)
{
u32 buffer[EP_PAGE_DWORDS];
u32 end;
u32 start_offset;
u32 read_start;
u32 bytes;
if (len == 0)
return 0;
end = start + len;
if (end > (1 << CMD_SHIFT))
return -EINVAL;
start_offset = start & EP_PAGE_MASK;
if (start_offset) {
read_start = start & ~EP_PAGE_MASK;
read_page(dd, read_start, buffer);
bytes = EP_PAGE_SIZE - start_offset;
if (len <= bytes) {
memcpy(dest, (u8 *)buffer + start_offset, len);
return 0;
}
memcpy(dest, (u8 *)buffer + start_offset, bytes);
start += bytes;
len -= bytes;
dest += bytes;
}
while (len >= EP_PAGE_SIZE) {
read_page(dd, start, buffer);
memcpy(dest, buffer, EP_PAGE_SIZE);
start += EP_PAGE_SIZE;
len -= EP_PAGE_SIZE;
dest += EP_PAGE_SIZE;
}
if (len) {
read_page(dd, start, buffer);
memcpy(dest, buffer, len);
}
return 0;
}
int eprom_init(struct hfi1_devdata *dd)
{
int ret = 0;
if (dd->pcidev->device != PCI_DEVICE_ID_INTEL0)
return 0;
ret = acquire_chip_resource(dd, CR_EPROM, EPROM_TIMEOUT);
if (ret) {
dd_dev_err(dd,
"%s: unable to acquire EPROM resource, no EPROM support\n",
__func__);
goto done_asic;
}
write_csr(dd, ASIC_EEP_CTL_STAT, ASIC_EEP_CTL_STAT_EP_RESET_SMASK);
write_csr(dd, ASIC_EEP_CTL_STAT,
EP_SPEED_FULL << ASIC_EEP_CTL_STAT_RATE_SPI_SHIFT);
write_csr(dd, ASIC_EEP_ADDR_CMD, CMD_RELEASE_POWERDOWN_NOID);
dd->eprom_available = true;
release_chip_resource(dd, CR_EPROM);
done_asic:
return ret;
}
static int read_partition_platform_config(struct hfi1_devdata *dd, void **data,
u32 *size)
{
void *buffer;
void *p;
u32 length;
int ret;
buffer = kmalloc(P1_SIZE, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
ret = read_length(dd, P1_START, P1_SIZE, buffer);
if (ret) {
kfree(buffer);
return ret;
}
p = strnstr(buffer, IMAGE_TRAIL_MAGIC, P1_SIZE);
if (p)
length = p - buffer;
else
length = P1_SIZE;
*data = buffer;
*size = length;
return 0;
}
int eprom_read_platform_config(struct hfi1_devdata *dd, void **data, u32 *size)
{
u32 directory[EP_PAGE_DWORDS];
int ret;
if (!dd->eprom_available)
return -ENXIO;
ret = acquire_chip_resource(dd, CR_EPROM, EPROM_TIMEOUT);
if (ret)
return -EBUSY;
ret = read_length(dd, P1_START - EP_PAGE_SIZE, EP_PAGE_SIZE, directory);
if (ret)
goto done;
if (directory[EP_PAGE_DWORDS - 1] == 0) {
ret = read_partition_platform_config(dd, data, size);
goto done;
}
ret = -ENOENT;
done:
release_chip_resource(dd, CR_EPROM);
return ret;
}
