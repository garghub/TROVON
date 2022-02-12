static void init_packet_head(void)
{
INIT_LIST_HEAD(&packet_data_head.list);
rbu_data.packet_read_count = 0;
rbu_data.num_packets = 0;
rbu_data.packetsize = 0;
rbu_data.imagesize = 0;
}
static int create_packet(void *data, size_t length)
{
struct packet_data *newpacket;
int ordernum = 0;
int retval = 0;
unsigned int packet_array_size = 0;
void **invalid_addr_packet_array = NULL;
void *packet_data_temp_buf = NULL;
unsigned int idx = 0;
pr_debug("create_packet: entry \n");
if (!rbu_data.packetsize) {
pr_debug("create_packet: packetsize not specified\n");
retval = -EINVAL;
goto out_noalloc;
}
spin_unlock(&rbu_data.lock);
newpacket = kzalloc(sizeof (struct packet_data), GFP_KERNEL);
if (!newpacket) {
printk(KERN_WARNING
"dell_rbu:%s: failed to allocate new "
"packet\n", __func__);
retval = -ENOMEM;
spin_lock(&rbu_data.lock);
goto out_noalloc;
}
ordernum = get_order(length);
packet_array_size = max(
(unsigned int)(allocation_floor / rbu_data.packetsize),
(unsigned int)1);
invalid_addr_packet_array = kzalloc(packet_array_size * sizeof(void*),
GFP_KERNEL);
if (!invalid_addr_packet_array) {
printk(KERN_WARNING
"dell_rbu:%s: failed to allocate "
"invalid_addr_packet_array \n",
__func__);
retval = -ENOMEM;
spin_lock(&rbu_data.lock);
goto out_alloc_packet;
}
while (!packet_data_temp_buf) {
packet_data_temp_buf = (unsigned char *)
__get_free_pages(GFP_KERNEL, ordernum);
if (!packet_data_temp_buf) {
printk(KERN_WARNING
"dell_rbu:%s: failed to allocate new "
"packet\n", __func__);
retval = -ENOMEM;
spin_lock(&rbu_data.lock);
goto out_alloc_packet_array;
}
if ((unsigned long)virt_to_phys(packet_data_temp_buf)
< allocation_floor) {
pr_debug("packet 0x%lx below floor at 0x%lx.\n",
(unsigned long)virt_to_phys(
packet_data_temp_buf),
allocation_floor);
invalid_addr_packet_array[idx++] = packet_data_temp_buf;
packet_data_temp_buf = NULL;
}
}
spin_lock(&rbu_data.lock);
newpacket->data = packet_data_temp_buf;
pr_debug("create_packet: newpacket at physical addr %lx\n",
(unsigned long)virt_to_phys(newpacket->data));
newpacket->length = length;
newpacket->ordernum = ordernum;
++rbu_data.num_packets;
INIT_LIST_HEAD(&newpacket->list);
list_add_tail(&newpacket->list, &packet_data_head.list);
memcpy(newpacket->data, data, length);
pr_debug("create_packet: exit \n");
out_alloc_packet_array:
for (;idx>0;idx--) {
pr_debug("freeing unused packet below floor 0x%lx.\n",
(unsigned long)virt_to_phys(
invalid_addr_packet_array[idx-1]));
free_pages((unsigned long)invalid_addr_packet_array[idx-1],
ordernum);
}
kfree(invalid_addr_packet_array);
out_alloc_packet:
if (retval)
kfree(newpacket);
out_noalloc:
return retval;
}
static int packetize_data(const u8 *data, size_t length)
{
int rc = 0;
int done = 0;
int packet_length;
u8 *temp;
u8 *end = (u8 *) data + length;
pr_debug("packetize_data: data length %zd\n", length);
if (!rbu_data.packetsize) {
printk(KERN_WARNING
"dell_rbu: packetsize not specified\n");
return -EIO;
}
temp = (u8 *) data;
while (!done) {
if ((temp + rbu_data.packetsize) < end)
packet_length = rbu_data.packetsize;
else {
packet_length = end - temp;
done = 1;
}
if ((rc = create_packet(temp, packet_length)))
return rc;
pr_debug("%p:%td\n", temp, (end - temp));
temp += packet_length;
}
rbu_data.imagesize = length;
return rc;
}
static int do_packet_read(char *data, struct list_head *ptemp_list,
int length, int bytes_read, int *list_read_count)
{
void *ptemp_buf;
struct packet_data *newpacket = NULL;
int bytes_copied = 0;
int j = 0;
newpacket = list_entry(ptemp_list, struct packet_data, list);
*list_read_count += newpacket->length;
if (*list_read_count > bytes_read) {
j = newpacket->length - (*list_read_count - bytes_read);
ptemp_buf = (u8 *) newpacket->data + j;
if (length > (*list_read_count - bytes_read))
bytes_copied = (*list_read_count - bytes_read);
else
bytes_copied = length;
memcpy(data, ptemp_buf, bytes_copied);
}
return bytes_copied;
}
static int packet_read_list(char *data, size_t * pread_length)
{
struct list_head *ptemp_list;
int temp_count = 0;
int bytes_copied = 0;
int bytes_read = 0;
int remaining_bytes = 0;
char *pdest = data;
if (0 == rbu_data.num_packets)
return -ENOMEM;
remaining_bytes = *pread_length;
bytes_read = rbu_data.packet_read_count;
ptemp_list = (&packet_data_head.list)->next;
while (!list_empty(ptemp_list)) {
bytes_copied = do_packet_read(pdest, ptemp_list,
remaining_bytes, bytes_read, &temp_count);
remaining_bytes -= bytes_copied;
bytes_read += bytes_copied;
pdest += bytes_copied;
if (remaining_bytes == 0)
break;
ptemp_list = ptemp_list->next;
}
*pread_length = bytes_read - rbu_data.packet_read_count;
rbu_data.packet_read_count = bytes_read;
return 0;
}
static void packet_empty_list(void)
{
struct list_head *ptemp_list;
struct list_head *pnext_list;
struct packet_data *newpacket;
ptemp_list = (&packet_data_head.list)->next;
while (!list_empty(ptemp_list)) {
newpacket =
list_entry(ptemp_list, struct packet_data, list);
pnext_list = ptemp_list->next;
list_del(ptemp_list);
ptemp_list = pnext_list;
memset(newpacket->data, 0, rbu_data.packetsize);
free_pages((unsigned long) newpacket->data,
newpacket->ordernum);
kfree(newpacket);
}
rbu_data.packet_read_count = 0;
rbu_data.num_packets = 0;
rbu_data.imagesize = 0;
}
static void img_update_free(void)
{
if (!rbu_data.image_update_buffer)
return;
memset(rbu_data.image_update_buffer, 0,
rbu_data.image_update_buffer_size);
if (rbu_data.dma_alloc == 1)
dma_free_coherent(NULL, rbu_data.bios_image_size,
rbu_data.image_update_buffer, dell_rbu_dmaaddr);
else
free_pages((unsigned long) rbu_data.image_update_buffer,
rbu_data.image_update_ordernum);
rbu_data.image_update_ordernum = -1;
rbu_data.image_update_buffer = NULL;
rbu_data.image_update_buffer_size = 0;
rbu_data.bios_image_size = 0;
rbu_data.dma_alloc = 0;
}
static int img_update_realloc(unsigned long size)
{
unsigned char *image_update_buffer = NULL;
unsigned long rc;
unsigned long img_buf_phys_addr;
int ordernum;
int dma_alloc = 0;
if (rbu_data.image_update_buffer_size >= size) {
if ((size != 0) && (rbu_data.image_update_buffer == NULL)) {
printk(KERN_ERR "dell_rbu:%s: corruption "
"check failed\n", __func__);
return -EINVAL;
}
return 0;
}
img_update_free();
spin_unlock(&rbu_data.lock);
ordernum = get_order(size);
image_update_buffer =
(unsigned char *) __get_free_pages(GFP_KERNEL, ordernum);
img_buf_phys_addr =
(unsigned long) virt_to_phys(image_update_buffer);
if (img_buf_phys_addr > BIOS_SCAN_LIMIT) {
free_pages((unsigned long) image_update_buffer, ordernum);
ordernum = -1;
image_update_buffer = dma_alloc_coherent(NULL, size,
&dell_rbu_dmaaddr, GFP_KERNEL);
dma_alloc = 1;
}
spin_lock(&rbu_data.lock);
if (image_update_buffer != NULL) {
rbu_data.image_update_buffer = image_update_buffer;
rbu_data.image_update_buffer_size = size;
rbu_data.bios_image_size =
rbu_data.image_update_buffer_size;
rbu_data.image_update_ordernum = ordernum;
rbu_data.dma_alloc = dma_alloc;
rc = 0;
} else {
pr_debug("Not enough memory for image update:"
"size = %ld\n", size);
rc = -ENOMEM;
}
return rc;
}
static ssize_t read_packet_data(char *buffer, loff_t pos, size_t count)
{
int retval;
size_t bytes_left;
size_t data_length;
char *ptempBuf = buffer;
if (rbu_data.num_packets == 0) {
pr_debug("read_packet_data: no packets written\n");
retval = -ENOMEM;
goto read_rbu_data_exit;
}
if (pos > rbu_data.imagesize) {
retval = 0;
printk(KERN_WARNING "dell_rbu:read_packet_data: "
"data underrun\n");
goto read_rbu_data_exit;
}
bytes_left = rbu_data.imagesize - pos;
data_length = min(bytes_left, count);
if ((retval = packet_read_list(ptempBuf, &data_length)) < 0)
goto read_rbu_data_exit;
if ((pos + count) > rbu_data.imagesize) {
rbu_data.packet_read_count = 0;
retval = bytes_left;
} else
retval = count;
read_rbu_data_exit:
return retval;
}
static ssize_t read_rbu_mono_data(char *buffer, loff_t pos, size_t count)
{
if ((rbu_data.image_update_buffer == NULL) ||
(rbu_data.bios_image_size == 0)) {
pr_debug("read_rbu_data_mono: image_update_buffer %p ,"
"bios_image_size %lu\n",
rbu_data.image_update_buffer,
rbu_data.bios_image_size);
return -ENOMEM;
}
return memory_read_from_buffer(buffer, count, &pos,
rbu_data.image_update_buffer, rbu_data.bios_image_size);
}
static ssize_t read_rbu_data(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
ssize_t ret_count = 0;
spin_lock(&rbu_data.lock);
if (!strcmp(image_type, "mono"))
ret_count = read_rbu_mono_data(buffer, pos, count);
else if (!strcmp(image_type, "packet"))
ret_count = read_packet_data(buffer, pos, count);
else
pr_debug("read_rbu_data: invalid image type specified\n");
spin_unlock(&rbu_data.lock);
return ret_count;
}
static void callbackfn_rbu(const struct firmware *fw, void *context)
{
rbu_data.entry_created = 0;
if (!fw)
return;
if (!fw->size)
goto out;
spin_lock(&rbu_data.lock);
if (!strcmp(image_type, "mono")) {
if (!img_update_realloc(fw->size))
memcpy(rbu_data.image_update_buffer,
fw->data, fw->size);
} else if (!strcmp(image_type, "packet")) {
packet_empty_list();
if (packetize_data(fw->data, fw->size))
packet_empty_list();
} else
pr_debug("invalid image type specified.\n");
spin_unlock(&rbu_data.lock);
out:
release_firmware(fw);
}
static ssize_t read_rbu_image_type(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
int size = 0;
if (!pos)
size = scnprintf(buffer, count, "%s\n", image_type);
return size;
}
static ssize_t write_rbu_image_type(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
int rc = count;
int req_firm_rc = 0;
int i;
spin_lock(&rbu_data.lock);
for (i = 0; i < count; ++i)
if (buffer[i] == '\n' || buffer[i] == ' ') {
buffer[i] = '\0';
break;
}
if (i == count)
buffer[count] = '\0';
if (strstr(buffer, "mono"))
strcpy(image_type, "mono");
else if (strstr(buffer, "packet"))
strcpy(image_type, "packet");
else if (strstr(buffer, "init")) {
if (!rbu_data.entry_created) {
spin_unlock(&rbu_data.lock);
req_firm_rc = request_firmware_nowait(THIS_MODULE,
FW_ACTION_NOHOTPLUG, "dell_rbu",
&rbu_device->dev, GFP_KERNEL, &context,
callbackfn_rbu);
if (req_firm_rc) {
printk(KERN_ERR
"dell_rbu:%s request_firmware_nowait"
" failed %d\n", __func__, rc);
rc = -EIO;
} else
rbu_data.entry_created = 1;
spin_lock(&rbu_data.lock);
}
} else {
printk(KERN_WARNING "dell_rbu: image_type is invalid\n");
spin_unlock(&rbu_data.lock);
return -EINVAL;
}
packet_empty_list();
img_update_free();
spin_unlock(&rbu_data.lock);
return rc;
}
static ssize_t read_rbu_packet_size(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
int size = 0;
if (!pos) {
spin_lock(&rbu_data.lock);
size = scnprintf(buffer, count, "%lu\n", rbu_data.packetsize);
spin_unlock(&rbu_data.lock);
}
return size;
}
static ssize_t write_rbu_packet_size(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
unsigned long temp;
spin_lock(&rbu_data.lock);
packet_empty_list();
sscanf(buffer, "%lu", &temp);
if (temp < 0xffffffff)
rbu_data.packetsize = temp;
spin_unlock(&rbu_data.lock);
return count;
}
static int __init dcdrbu_init(void)
{
int rc;
spin_lock_init(&rbu_data.lock);
init_packet_head();
rbu_device = platform_device_register_simple("dell_rbu", -1, NULL, 0);
if (IS_ERR(rbu_device)) {
printk(KERN_ERR
"dell_rbu:%s:platform_device_register_simple "
"failed\n", __func__);
return PTR_ERR(rbu_device);
}
rc = sysfs_create_bin_file(&rbu_device->dev.kobj, &rbu_data_attr);
if (rc)
goto out_devreg;
rc = sysfs_create_bin_file(&rbu_device->dev.kobj, &rbu_image_type_attr);
if (rc)
goto out_data;
rc = sysfs_create_bin_file(&rbu_device->dev.kobj,
&rbu_packet_size_attr);
if (rc)
goto out_imtype;
rbu_data.entry_created = 0;
return 0;
out_imtype:
sysfs_remove_bin_file(&rbu_device->dev.kobj, &rbu_image_type_attr);
out_data:
sysfs_remove_bin_file(&rbu_device->dev.kobj, &rbu_data_attr);
out_devreg:
platform_device_unregister(rbu_device);
return rc;
}
static __exit void dcdrbu_exit(void)
{
spin_lock(&rbu_data.lock);
packet_empty_list();
img_update_free();
spin_unlock(&rbu_data.lock);
platform_device_unregister(rbu_device);
}
