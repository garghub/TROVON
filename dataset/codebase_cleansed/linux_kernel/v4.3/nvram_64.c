int nvram_write_os_partition(struct nvram_os_partition *part,
char *buff, int length,
unsigned int err_type,
unsigned int error_log_cnt)
{
int rc;
loff_t tmp_index;
struct err_log_info info;
if (part->index == -1)
return -ESPIPE;
if (length > part->size)
length = part->size;
info.error_type = cpu_to_be32(err_type);
info.seq_num = cpu_to_be32(error_log_cnt);
tmp_index = part->index;
rc = ppc_md.nvram_write((char *)&info, sizeof(struct err_log_info),
&tmp_index);
if (rc <= 0) {
pr_err("%s: Failed nvram_write (%d)\n", __func__, rc);
return rc;
}
rc = ppc_md.nvram_write(buff, length, &tmp_index);
if (rc <= 0) {
pr_err("%s: Failed nvram_write (%d)\n", __func__, rc);
return rc;
}
return 0;
}
int nvram_read_partition(struct nvram_os_partition *part, char *buff,
int length, unsigned int *err_type,
unsigned int *error_log_cnt)
{
int rc;
loff_t tmp_index;
struct err_log_info info;
if (part->index == -1)
return -1;
if (length > part->size)
length = part->size;
tmp_index = part->index;
if (part->os_partition) {
rc = ppc_md.nvram_read((char *)&info,
sizeof(struct err_log_info),
&tmp_index);
if (rc <= 0) {
pr_err("%s: Failed nvram_read (%d)\n", __func__, rc);
return rc;
}
}
rc = ppc_md.nvram_read(buff, length, &tmp_index);
if (rc <= 0) {
pr_err("%s: Failed nvram_read (%d)\n", __func__, rc);
return rc;
}
if (part->os_partition) {
*error_log_cnt = be32_to_cpu(info.seq_num);
*err_type = be32_to_cpu(info.error_type);
}
return 0;
}
int __init nvram_init_os_partition(struct nvram_os_partition *part)
{
loff_t p;
int size;
p = nvram_find_partition(part->name, NVRAM_SIG_OS, &size);
if (p && size < part->min_size) {
pr_info("nvram: Found too small %s partition,"
" removing it...\n", part->name);
nvram_remove_partition(part->name, NVRAM_SIG_OS, NULL);
p = 0;
}
if (!p) {
p = nvram_create_partition(part->name, NVRAM_SIG_OS,
part->req_size, part->min_size);
if (p == -ENOSPC) {
pr_info("nvram: No room to create %s partition, "
"deleting any obsolete OS partitions...\n",
part->name);
nvram_remove_partition(NULL, NVRAM_SIG_OS,
nvram_os_partitions);
p = nvram_create_partition(part->name, NVRAM_SIG_OS,
part->req_size, part->min_size);
}
}
if (p <= 0) {
pr_err("nvram: Failed to find or create %s"
" partition, err %d\n", part->name, (int)p);
return -1;
}
part->index = p;
part->size = nvram_get_partition_size(p) - sizeof(struct err_log_info);
return 0;
}
static int nvram_compress(const void *in, void *out, size_t inlen,
size_t outlen)
{
int err, ret;
ret = -EIO;
err = zlib_deflateInit2(&stream, COMPR_LEVEL, Z_DEFLATED, WINDOW_BITS,
MEM_LEVEL, Z_DEFAULT_STRATEGY);
if (err != Z_OK)
goto error;
stream.next_in = in;
stream.avail_in = inlen;
stream.total_in = 0;
stream.next_out = out;
stream.avail_out = outlen;
stream.total_out = 0;
err = zlib_deflate(&stream, Z_FINISH);
if (err != Z_STREAM_END)
goto error;
err = zlib_deflateEnd(&stream);
if (err != Z_OK)
goto error;
if (stream.total_out >= stream.total_in)
goto error;
ret = stream.total_out;
error:
return ret;
}
static int zip_oops(size_t text_len)
{
struct oops_log_info *oops_hdr = (struct oops_log_info *)oops_buf;
int zipped_len = nvram_compress(big_oops_buf, oops_data, text_len,
oops_data_sz);
if (zipped_len < 0) {
pr_err("nvram: compression failed; returned %d\n", zipped_len);
pr_err("nvram: logging uncompressed oops/panic report\n");
return -1;
}
oops_hdr->version = cpu_to_be16(OOPS_HDR_VERSION);
oops_hdr->report_length = cpu_to_be16(zipped_len);
oops_hdr->timestamp = cpu_to_be64(ktime_get_real_seconds());
return 0;
}
static int nvram_pstore_open(struct pstore_info *psi)
{
read_type = -1;
return 0;
}
static int nvram_pstore_write(enum pstore_type_id type,
enum kmsg_dump_reason reason,
u64 *id, unsigned int part, int count,
bool compressed, size_t size,
struct pstore_info *psi)
{
int rc;
unsigned int err_type = ERR_TYPE_KERNEL_PANIC;
struct oops_log_info *oops_hdr = (struct oops_log_info *) oops_buf;
if (part > 1 || (type != PSTORE_TYPE_DMESG))
return -1;
if (clobbering_unread_rtas_event())
return -1;
oops_hdr->version = cpu_to_be16(OOPS_HDR_VERSION);
oops_hdr->report_length = cpu_to_be16(size);
oops_hdr->timestamp = cpu_to_be64(ktime_get_real_seconds());
if (compressed)
err_type = ERR_TYPE_KERNEL_PANIC_GZ;
rc = nvram_write_os_partition(&oops_log_partition, oops_buf,
(int) (sizeof(*oops_hdr) + size), err_type, count);
if (rc != 0)
return rc;
*id = part;
return 0;
}
static ssize_t nvram_pstore_read(u64 *id, enum pstore_type_id *type,
int *count, struct timespec *time, char **buf,
bool *compressed, struct pstore_info *psi)
{
struct oops_log_info *oops_hdr;
unsigned int err_type, id_no, size = 0;
struct nvram_os_partition *part = NULL;
char *buff = NULL;
int sig = 0;
loff_t p;
read_type++;
switch (nvram_type_ids[read_type]) {
case PSTORE_TYPE_DMESG:
part = &oops_log_partition;
*type = PSTORE_TYPE_DMESG;
break;
case PSTORE_TYPE_PPC_COMMON:
sig = NVRAM_SIG_SYS;
part = &common_partition;
*type = PSTORE_TYPE_PPC_COMMON;
*id = PSTORE_TYPE_PPC_COMMON;
time->tv_sec = 0;
time->tv_nsec = 0;
break;
#ifdef CONFIG_PPC_PSERIES
case PSTORE_TYPE_PPC_RTAS:
part = &rtas_log_partition;
*type = PSTORE_TYPE_PPC_RTAS;
time->tv_sec = last_rtas_event;
time->tv_nsec = 0;
break;
case PSTORE_TYPE_PPC_OF:
sig = NVRAM_SIG_OF;
part = &of_config_partition;
*type = PSTORE_TYPE_PPC_OF;
*id = PSTORE_TYPE_PPC_OF;
time->tv_sec = 0;
time->tv_nsec = 0;
break;
#endif
#ifdef CONFIG_PPC_POWERNV
case PSTORE_TYPE_PPC_OPAL:
sig = NVRAM_SIG_FW;
part = &skiboot_partition;
*type = PSTORE_TYPE_PPC_OPAL;
*id = PSTORE_TYPE_PPC_OPAL;
time->tv_sec = 0;
time->tv_nsec = 0;
break;
#endif
default:
return 0;
}
if (!part->os_partition) {
p = nvram_find_partition(part->name, sig, &size);
if (p <= 0) {
pr_err("nvram: Failed to find partition %s, "
"err %d\n", part->name, (int)p);
return 0;
}
part->index = p;
part->size = size;
}
buff = kmalloc(part->size, GFP_KERNEL);
if (!buff)
return -ENOMEM;
if (nvram_read_partition(part, buff, part->size, &err_type, &id_no)) {
kfree(buff);
return 0;
}
*count = 0;
if (part->os_partition)
*id = id_no;
if (nvram_type_ids[read_type] == PSTORE_TYPE_DMESG) {
size_t length, hdr_size;
oops_hdr = (struct oops_log_info *)buff;
if (be16_to_cpu(oops_hdr->version) < OOPS_HDR_VERSION) {
hdr_size = sizeof(u16);
length = be16_to_cpu(oops_hdr->version);
time->tv_sec = 0;
time->tv_nsec = 0;
} else {
hdr_size = sizeof(*oops_hdr);
length = be16_to_cpu(oops_hdr->report_length);
time->tv_sec = be64_to_cpu(oops_hdr->timestamp);
time->tv_nsec = 0;
}
*buf = kmemdup(buff + hdr_size, length, GFP_KERNEL);
if (*buf == NULL)
return -ENOMEM;
kfree(buff);
if (err_type == ERR_TYPE_KERNEL_PANIC_GZ)
*compressed = true;
else
*compressed = false;
return length;
}
*buf = buff;
return part->size;
}
static int nvram_pstore_init(void)
{
int rc = 0;
if (machine_is(pseries)) {
nvram_type_ids[2] = PSTORE_TYPE_PPC_RTAS;
nvram_type_ids[3] = PSTORE_TYPE_PPC_OF;
} else
nvram_type_ids[2] = PSTORE_TYPE_PPC_OPAL;
nvram_pstore_info.buf = oops_data;
nvram_pstore_info.bufsize = oops_data_sz;
spin_lock_init(&nvram_pstore_info.buf_lock);
rc = pstore_register(&nvram_pstore_info);
if (rc && (rc != -EPERM))
pr_err("nvram: pstore_register() failed, returned %d. "
"Defaults to kmsg_dump\n", rc);
return rc;
}
static int nvram_pstore_init(void)
{
return -1;
}
void __init nvram_init_oops_partition(int rtas_partition_exists)
{
int rc;
rc = nvram_init_os_partition(&oops_log_partition);
if (rc != 0) {
#ifdef CONFIG_PPC_PSERIES
if (!rtas_partition_exists) {
pr_err("nvram: Failed to initialize oops partition!");
return;
}
pr_notice("nvram: Using %s partition to log both"
" RTAS errors and oops/panic reports\n",
rtas_log_partition.name);
memcpy(&oops_log_partition, &rtas_log_partition,
sizeof(rtas_log_partition));
#else
pr_err("nvram: Failed to initialize oops partition!");
return;
#endif
}
oops_buf = kmalloc(oops_log_partition.size, GFP_KERNEL);
if (!oops_buf) {
pr_err("nvram: No memory for %s partition\n",
oops_log_partition.name);
return;
}
oops_data = oops_buf + sizeof(struct oops_log_info);
oops_data_sz = oops_log_partition.size - sizeof(struct oops_log_info);
rc = nvram_pstore_init();
if (!rc)
return;
big_oops_buf_sz = (oops_data_sz * 100) / 45;
big_oops_buf = kmalloc(big_oops_buf_sz, GFP_KERNEL);
if (big_oops_buf) {
stream.workspace = kmalloc(zlib_deflate_workspacesize(
WINDOW_BITS, MEM_LEVEL), GFP_KERNEL);
if (!stream.workspace) {
pr_err("nvram: No memory for compression workspace; "
"skipping compression of %s partition data\n",
oops_log_partition.name);
kfree(big_oops_buf);
big_oops_buf = NULL;
}
} else {
pr_err("No memory for uncompressed %s data; "
"skipping compression\n", oops_log_partition.name);
stream.workspace = NULL;
}
rc = kmsg_dump_register(&nvram_kmsg_dumper);
if (rc != 0) {
pr_err("nvram: kmsg_dump_register() failed; returned %d\n", rc);
kfree(oops_buf);
kfree(big_oops_buf);
kfree(stream.workspace);
}
}
static void oops_to_nvram(struct kmsg_dumper *dumper,
enum kmsg_dump_reason reason)
{
struct oops_log_info *oops_hdr = (struct oops_log_info *)oops_buf;
static unsigned int oops_count = 0;
static bool panicking = false;
static DEFINE_SPINLOCK(lock);
unsigned long flags;
size_t text_len;
unsigned int err_type = ERR_TYPE_KERNEL_PANIC_GZ;
int rc = -1;
switch (reason) {
case KMSG_DUMP_RESTART:
case KMSG_DUMP_HALT:
case KMSG_DUMP_POWEROFF:
return;
case KMSG_DUMP_OOPS:
break;
case KMSG_DUMP_PANIC:
panicking = true;
break;
case KMSG_DUMP_EMERG:
if (panicking)
return;
break;
default:
pr_err("%s: ignoring unrecognized KMSG_DUMP_* reason %d\n",
__func__, (int) reason);
return;
}
if (clobbering_unread_rtas_event())
return;
if (!spin_trylock_irqsave(&lock, flags))
return;
if (big_oops_buf) {
kmsg_dump_get_buffer(dumper, false,
big_oops_buf, big_oops_buf_sz, &text_len);
rc = zip_oops(text_len);
}
if (rc != 0) {
kmsg_dump_rewind(dumper);
kmsg_dump_get_buffer(dumper, false,
oops_data, oops_data_sz, &text_len);
err_type = ERR_TYPE_KERNEL_PANIC;
oops_hdr->version = cpu_to_be16(OOPS_HDR_VERSION);
oops_hdr->report_length = cpu_to_be16(text_len);
oops_hdr->timestamp = cpu_to_be64(ktime_get_real_seconds());
}
(void) nvram_write_os_partition(&oops_log_partition, oops_buf,
(int) (sizeof(*oops_hdr) + text_len), err_type,
++oops_count);
spin_unlock_irqrestore(&lock, flags);
}
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
