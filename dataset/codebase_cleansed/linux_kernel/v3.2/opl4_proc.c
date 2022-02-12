static int snd_opl4_mem_proc_open(struct snd_info_entry *entry,
unsigned short mode, void **file_private_data)
{
struct snd_opl4 *opl4 = entry->private_data;
mutex_lock(&opl4->access_mutex);
if (opl4->memory_access) {
mutex_unlock(&opl4->access_mutex);
return -EBUSY;
}
opl4->memory_access++;
mutex_unlock(&opl4->access_mutex);
return 0;
}
static int snd_opl4_mem_proc_release(struct snd_info_entry *entry,
unsigned short mode, void *file_private_data)
{
struct snd_opl4 *opl4 = entry->private_data;
mutex_lock(&opl4->access_mutex);
opl4->memory_access--;
mutex_unlock(&opl4->access_mutex);
return 0;
}
static ssize_t snd_opl4_mem_proc_read(struct snd_info_entry *entry,
void *file_private_data,
struct file *file, char __user *_buf,
size_t count, loff_t pos)
{
struct snd_opl4 *opl4 = entry->private_data;
char* buf;
buf = vmalloc(count);
if (!buf)
return -ENOMEM;
snd_opl4_read_memory(opl4, buf, pos, count);
if (copy_to_user(_buf, buf, count)) {
vfree(buf);
return -EFAULT;
}
vfree(buf);
return count;
}
static ssize_t snd_opl4_mem_proc_write(struct snd_info_entry *entry,
void *file_private_data,
struct file *file,
const char __user *_buf,
size_t count, loff_t pos)
{
struct snd_opl4 *opl4 = entry->private_data;
char *buf;
buf = vmalloc(count);
if (!buf)
return -ENOMEM;
if (copy_from_user(buf, _buf, count)) {
vfree(buf);
return -EFAULT;
}
snd_opl4_write_memory(opl4, buf, pos, count);
vfree(buf);
return count;
}
int snd_opl4_create_proc(struct snd_opl4 *opl4)
{
struct snd_info_entry *entry;
entry = snd_info_create_card_entry(opl4->card, "opl4-mem", opl4->card->proc_root);
if (entry) {
if (opl4->hardware < OPL3_HW_OPL4_ML) {
entry->mode |= S_IWUSR;
entry->size = 4 * 1024 * 1024;
} else {
entry->size = 1 * 1024 * 1024;
}
entry->content = SNDRV_INFO_CONTENT_DATA;
entry->c.ops = &snd_opl4_mem_proc_ops;
entry->module = THIS_MODULE;
entry->private_data = opl4;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
entry = NULL;
}
}
opl4->proc_entry = entry;
return 0;
}
void snd_opl4_free_proc(struct snd_opl4 *opl4)
{
snd_info_free_entry(opl4->proc_entry);
}
