static loff_t dev_nvram_llseek(struct file *file, loff_t offset, int origin)
{
int size;
if (ppc_md.nvram_size == NULL)
return -ENODEV;
size = ppc_md.nvram_size();
switch (origin) {
case 1:
offset += file->f_pos;
break;
case 2:
offset += size;
break;
}
if (offset < 0)
return -EINVAL;
file->f_pos = offset;
return file->f_pos;
}
static ssize_t dev_nvram_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
ssize_t ret;
char *tmp = NULL;
ssize_t size;
if (!ppc_md.nvram_size) {
ret = -ENODEV;
goto out;
}
size = ppc_md.nvram_size();
if (size < 0) {
ret = size;
goto out;
}
if (*ppos >= size) {
ret = 0;
goto out;
}
count = min_t(size_t, count, size - *ppos);
count = min(count, PAGE_SIZE);
tmp = kmalloc(count, GFP_KERNEL);
if (!tmp) {
ret = -ENOMEM;
goto out;
}
ret = ppc_md.nvram_read(tmp, count, ppos);
if (ret <= 0)
goto out;
if (copy_to_user(buf, tmp, ret))
ret = -EFAULT;
out:
kfree(tmp);
return ret;
}
static ssize_t dev_nvram_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
ssize_t ret;
char *tmp = NULL;
ssize_t size;
ret = -ENODEV;
if (!ppc_md.nvram_size)
goto out;
ret = 0;
size = ppc_md.nvram_size();
if (*ppos >= size || size < 0)
goto out;
count = min_t(size_t, count, size - *ppos);
count = min(count, PAGE_SIZE);
ret = -ENOMEM;
tmp = kmalloc(count, GFP_KERNEL);
if (!tmp)
goto out;
ret = -EFAULT;
if (copy_from_user(tmp, buf, count))
goto out;
ret = ppc_md.nvram_write(tmp, count, ppos);
out:
kfree(tmp);
return ret;
}
static long dev_nvram_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
switch(cmd) {
#ifdef CONFIG_PPC_PMAC
case OBSOLETE_PMAC_NVRAM_GET_OFFSET:
printk(KERN_WARNING "nvram: Using obsolete PMAC_NVRAM_GET_OFFSET ioctl\n");
case IOC_NVRAM_GET_OFFSET: {
int part, offset;
if (!machine_is(powermac))
return -EINVAL;
if (copy_from_user(&part, (void __user*)arg, sizeof(part)) != 0)
return -EFAULT;
if (part < pmac_nvram_OF || part > pmac_nvram_NR)
return -EINVAL;
offset = pmac_get_partition(part);
if (offset < 0)
return offset;
if (copy_to_user((void __user*)arg, &offset, sizeof(offset)) != 0)
return -EFAULT;
return 0;
}
#endif
default:
return -EINVAL;
}
}
static void __init nvram_print_partitions(char * label)
{
struct nvram_partition * tmp_part;
printk(KERN_WARNING "--------%s---------\n", label);
printk(KERN_WARNING "indx\t\tsig\tchks\tlen\tname\n");
list_for_each_entry(tmp_part, &nvram_partitions, partition) {
printk(KERN_WARNING "%4d \t%02x\t%02x\t%d\t%12.12s\n",
tmp_part->index, tmp_part->header.signature,
tmp_part->header.checksum, tmp_part->header.length,
tmp_part->header.name);
}
}
static int __init nvram_write_header(struct nvram_partition * part)
{
loff_t tmp_index;
int rc;
struct nvram_header phead;
memcpy(&phead, &part->header, NVRAM_HEADER_LEN);
phead.length = cpu_to_be16(phead.length);
tmp_index = part->index;
rc = ppc_md.nvram_write((char *)&phead, NVRAM_HEADER_LEN, &tmp_index);
return rc;
}
static unsigned char __init nvram_checksum(struct nvram_header *p)
{
unsigned int c_sum, c_sum2;
unsigned short *sp = (unsigned short *)p->name;
c_sum = p->signature + p->length + sp[0] + sp[1] + sp[2] + sp[3] + sp[4] + sp[5];
c_sum = ((c_sum & 0xffff) + (c_sum >> 16)) & 0xffff;
c_sum2 = (c_sum >> 8) + (c_sum << 8);
c_sum = ((c_sum + c_sum2) >> 8) & 0xff;
return c_sum;
}
static int nvram_can_remove_partition(struct nvram_partition *part,
const char *name, int sig, const char *exceptions[])
{
if (part->header.signature != sig)
return 0;
if (name) {
if (strncmp(name, part->header.name, 12))
return 0;
} else if (exceptions) {
const char **except;
for (except = exceptions; *except; except++) {
if (!strncmp(*except, part->header.name, 12))
return 0;
}
}
return 1;
}
int __init nvram_remove_partition(const char *name, int sig,
const char *exceptions[])
{
struct nvram_partition *part, *prev, *tmp;
int rc;
list_for_each_entry(part, &nvram_partitions, partition) {
if (!nvram_can_remove_partition(part, name, sig, exceptions))
continue;
part->header.signature = NVRAM_SIG_FREE;
strncpy(part->header.name, "wwwwwwwwwwww", 12);
part->header.checksum = nvram_checksum(&part->header);
rc = nvram_write_header(part);
if (rc <= 0) {
printk(KERN_ERR "nvram_remove_partition: nvram_write failed (%d)\n", rc);
return rc;
}
}
prev = NULL;
list_for_each_entry_safe(part, tmp, &nvram_partitions, partition) {
if (part->header.signature != NVRAM_SIG_FREE) {
prev = NULL;
continue;
}
if (prev) {
prev->header.length += part->header.length;
prev->header.checksum = nvram_checksum(&part->header);
rc = nvram_write_header(part);
if (rc <= 0) {
printk(KERN_ERR "nvram_remove_partition: nvram_write failed (%d)\n", rc);
return rc;
}
list_del(&part->partition);
kfree(part);
} else
prev = part;
}
return 0;
}
loff_t __init nvram_create_partition(const char *name, int sig,
int req_size, int min_size)
{
struct nvram_partition *part;
struct nvram_partition *new_part;
struct nvram_partition *free_part = NULL;
static char nv_init_vals[16];
loff_t tmp_index;
long size = 0;
int rc;
req_size = _ALIGN_UP(req_size, NVRAM_BLOCK_LEN) / NVRAM_BLOCK_LEN;
min_size = _ALIGN_UP(min_size, NVRAM_BLOCK_LEN) / NVRAM_BLOCK_LEN;
if (min_size == 0)
min_size = req_size;
if (min_size > req_size)
return -EINVAL;
req_size += 1;
min_size += 1;
list_for_each_entry(part, &nvram_partitions, partition) {
if (part->header.signature != NVRAM_SIG_FREE)
continue;
if (part->header.length >= req_size) {
size = req_size;
free_part = part;
break;
}
if (part->header.length > size &&
part->header.length >= min_size) {
size = part->header.length;
free_part = part;
}
}
if (!size)
return -ENOSPC;
new_part = kmalloc(sizeof(*new_part), GFP_KERNEL);
if (!new_part) {
pr_err("nvram_create_os_partition: kmalloc failed\n");
return -ENOMEM;
}
new_part->index = free_part->index;
new_part->header.signature = sig;
new_part->header.length = size;
strncpy(new_part->header.name, name, 12);
new_part->header.checksum = nvram_checksum(&new_part->header);
rc = nvram_write_header(new_part);
if (rc <= 0) {
pr_err("nvram_create_os_partition: nvram_write_header "
"failed (%d)\n", rc);
return rc;
}
list_add_tail(&new_part->partition, &free_part->partition);
if (free_part->header.length > size) {
free_part->index += size * NVRAM_BLOCK_LEN;
free_part->header.length -= size;
free_part->header.checksum = nvram_checksum(&free_part->header);
rc = nvram_write_header(free_part);
if (rc <= 0) {
pr_err("nvram_create_os_partition: nvram_write_header "
"failed (%d)\n", rc);
return rc;
}
} else {
list_del(&free_part->partition);
kfree(free_part);
}
for (tmp_index = new_part->index + NVRAM_HEADER_LEN;
tmp_index < ((size - 1) * NVRAM_BLOCK_LEN);
tmp_index += NVRAM_BLOCK_LEN) {
rc = ppc_md.nvram_write(nv_init_vals, NVRAM_BLOCK_LEN, &tmp_index);
if (rc <= 0) {
pr_err("nvram_create_partition: nvram_write failed (%d)\n", rc);
return rc;
}
}
return new_part->index + NVRAM_HEADER_LEN;
}
int nvram_get_partition_size(loff_t data_index)
{
struct nvram_partition *part;
list_for_each_entry(part, &nvram_partitions, partition) {
if (part->index + NVRAM_HEADER_LEN == data_index)
return (part->header.length - 1) * NVRAM_BLOCK_LEN;
}
return -1;
}
loff_t nvram_find_partition(const char *name, int sig, int *out_size)
{
struct nvram_partition *p;
list_for_each_entry(p, &nvram_partitions, partition) {
if (p->header.signature == sig &&
(!name || !strncmp(p->header.name, name, 12))) {
if (out_size)
*out_size = (p->header.length - 1) *
NVRAM_BLOCK_LEN;
return p->index + NVRAM_HEADER_LEN;
}
}
return 0;
}
int __init nvram_scan_partitions(void)
{
loff_t cur_index = 0;
struct nvram_header phead;
struct nvram_partition * tmp_part;
unsigned char c_sum;
char * header;
int total_size;
int err;
if (ppc_md.nvram_size == NULL || ppc_md.nvram_size() <= 0)
return -ENODEV;
total_size = ppc_md.nvram_size();
header = kmalloc(NVRAM_HEADER_LEN, GFP_KERNEL);
if (!header) {
printk(KERN_ERR "nvram_scan_partitions: Failed kmalloc\n");
return -ENOMEM;
}
while (cur_index < total_size) {
err = ppc_md.nvram_read(header, NVRAM_HEADER_LEN, &cur_index);
if (err != NVRAM_HEADER_LEN) {
printk(KERN_ERR "nvram_scan_partitions: Error parsing "
"nvram partitions\n");
goto out;
}
cur_index -= NVRAM_HEADER_LEN;
memcpy(&phead, header, NVRAM_HEADER_LEN);
phead.length = be16_to_cpu(phead.length);
err = 0;
c_sum = nvram_checksum(&phead);
if (c_sum != phead.checksum) {
printk(KERN_WARNING "WARNING: nvram partition checksum"
" was %02x, should be %02x!\n",
phead.checksum, c_sum);
printk(KERN_WARNING "Terminating nvram partition scan\n");
goto out;
}
if (!phead.length) {
printk(KERN_WARNING "WARNING: nvram corruption "
"detected: 0-length partition\n");
goto out;
}
tmp_part = kmalloc(sizeof(struct nvram_partition), GFP_KERNEL);
err = -ENOMEM;
if (!tmp_part) {
printk(KERN_ERR "nvram_scan_partitions: kmalloc failed\n");
goto out;
}
memcpy(&tmp_part->header, &phead, NVRAM_HEADER_LEN);
tmp_part->index = cur_index;
list_add_tail(&tmp_part->partition, &nvram_partitions);
cur_index += phead.length * NVRAM_BLOCK_LEN;
}
err = 0;
#ifdef DEBUG_NVRAM
nvram_print_partitions("NVRAM Partitions");
#endif
out:
kfree(header);
return err;
}
static int __init nvram_init(void)
{
int rc;
BUILD_BUG_ON(NVRAM_BLOCK_LEN != 16);
if (ppc_md.nvram_size == NULL || ppc_md.nvram_size() <= 0)
return -ENODEV;
rc = misc_register(&nvram_dev);
if (rc != 0) {
printk(KERN_ERR "nvram_init: failed to register device\n");
return rc;
}
return rc;
}
static void __exit nvram_cleanup(void)
{
misc_deregister( &nvram_dev );
}
