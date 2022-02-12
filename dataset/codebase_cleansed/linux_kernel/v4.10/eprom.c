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
static int read_segment_platform_config(struct hfi1_devdata *dd,
void *directory, void **data, u32 *size)
{
struct hfi1_eprom_footer *footer;
struct hfi1_eprom_table_entry *table;
struct hfi1_eprom_table_entry *entry;
void *buffer = NULL;
void *table_buffer = NULL;
int ret, i;
u32 directory_size;
u32 seg_base, seg_offset;
u32 bytes_available, ncopied, to_copy;
footer = (struct hfi1_eprom_footer *)
(directory + EP_PAGE_SIZE - sizeof(*footer));
if (footer->version != FOOTER_VERSION)
return -EINVAL;
if (footer->oprom_size >= SEG_SIZE)
return -EINVAL;
if (footer->num_table_entries >
MAX_TABLE_ENTRIES(SEG_SIZE - footer->oprom_size))
return -EINVAL;
directory_size = DIRECTORY_SIZE(footer->num_table_entries);
if (directory_size <= EP_PAGE_SIZE) {
table = (struct hfi1_eprom_table_entry *)
(directory + EP_PAGE_SIZE - directory_size);
} else {
table_buffer = kmalloc(directory_size, GFP_KERNEL);
if (!table_buffer)
return -ENOMEM;
ret = read_length(dd, SEG_SIZE - directory_size,
directory_size, table_buffer);
if (ret)
goto done;
table = table_buffer;
}
for (entry = NULL, i = 0; i < footer->num_table_entries; i++) {
if (table[i].type == HFI1_EFT_PLATFORM_CONFIG) {
entry = &table[i];
break;
}
}
if (!entry) {
ret = -ENOENT;
goto done;
}
if (entry->size > (4 * 1024)) {
dd_dev_err(dd, "Bad configuration file size 0x%x\n",
entry->size);
ret = -EINVAL;
goto done;
}
if (entry->offset + entry->size < entry->offset) {
dd_dev_err(dd,
"Bad configuration file start + size 0x%x+0x%x\n",
entry->offset, entry->size);
ret = -EINVAL;
goto done;
}
buffer = kmalloc(entry->size, GFP_KERNEL);
if (!buffer) {
ret = -ENOMEM;
goto done;
}
seg_offset = entry->offset % SEG_SIZE;
seg_base = entry->offset - seg_offset;
ncopied = 0;
while (ncopied < entry->size) {
bytes_available = SEG_SIZE - seg_offset;
if (seg_base == 0) {
if (bytes_available <= directory_size) {
dd_dev_err(dd,
"Bad configuration file - offset 0x%x within footer+table\n",
entry->offset);
ret = -EINVAL;
goto done;
}
bytes_available -= directory_size;
}
to_copy = entry->size - ncopied;
if (to_copy > bytes_available)
to_copy = bytes_available;
ret = read_length(dd, seg_base + seg_offset, to_copy,
buffer + ncopied);
if (ret)
goto done;
ncopied += to_copy;
seg_offset = footer->oprom_size;
seg_base += SEG_SIZE;
}
ret = 0;
*data = buffer;
*size = entry->size;
done:
kfree(table_buffer);
if (ret)
kfree(buffer);
return ret;
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
ret = read_length(dd, SEG_SIZE - EP_PAGE_SIZE, EP_PAGE_SIZE, directory);
if (ret)
goto done;
if (directory[EP_PAGE_DWORDS - 1] == FOOTER_MAGIC) {
ret = read_segment_platform_config(dd, directory, data, size);
} else {
ret = read_partition_platform_config(dd, data, size);
}
done:
release_chip_resource(dd, CR_EPROM);
return ret;
}
