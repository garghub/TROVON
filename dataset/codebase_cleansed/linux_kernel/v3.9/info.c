int snd_info_check_reserved_words(const char *str)
{
static char *reserved[] =
{
"version",
"meminfo",
"memdebug",
"detect",
"devices",
"oss",
"cards",
"timers",
"synth",
"pcm",
"seq",
NULL
};
char **xstr = reserved;
while (*xstr) {
if (!strcmp(*xstr, str))
return 0;
xstr++;
}
if (!strncmp(str, "card", 4))
return 0;
return 1;
}
static int resize_info_buffer(struct snd_info_buffer *buffer,
unsigned int nsize)
{
char *nbuf;
nsize = PAGE_ALIGN(nsize);
nbuf = krealloc(buffer->buffer, nsize, GFP_KERNEL);
if (! nbuf)
return -ENOMEM;
buffer->buffer = nbuf;
buffer->len = nsize;
return 0;
}
int snd_iprintf(struct snd_info_buffer *buffer, const char *fmt, ...)
{
va_list args;
int len, res;
int err = 0;
might_sleep();
if (buffer->stop || buffer->error)
return 0;
len = buffer->len - buffer->size;
va_start(args, fmt);
for (;;) {
va_list ap;
va_copy(ap, args);
res = vsnprintf(buffer->buffer + buffer->curr, len, fmt, ap);
va_end(ap);
if (res < len)
break;
err = resize_info_buffer(buffer, buffer->len + PAGE_SIZE);
if (err < 0)
break;
len = buffer->len - buffer->size;
}
va_end(args);
if (err < 0)
return err;
buffer->curr += res;
buffer->size += res;
return res;
}
static void snd_remove_proc_entry(struct proc_dir_entry *parent,
struct proc_dir_entry *de)
{
if (de)
remove_proc_entry(de->name, parent);
}
static loff_t snd_info_entry_llseek(struct file *file, loff_t offset, int orig)
{
struct snd_info_private_data *data;
struct snd_info_entry *entry;
loff_t ret = -EINVAL, size;
data = file->private_data;
entry = data->entry;
mutex_lock(&entry->access);
if (entry->content == SNDRV_INFO_CONTENT_DATA &&
entry->c.ops->llseek) {
offset = entry->c.ops->llseek(entry,
data->file_private_data,
file, offset, orig);
goto out;
}
if (entry->content == SNDRV_INFO_CONTENT_DATA)
size = entry->size;
else
size = 0;
switch (orig) {
case SEEK_SET:
break;
case SEEK_CUR:
offset += file->f_pos;
break;
case SEEK_END:
if (!size)
goto out;
offset += size;
break;
default:
goto out;
}
if (offset < 0)
goto out;
if (size && offset > size)
offset = size;
file->f_pos = offset;
ret = offset;
out:
mutex_unlock(&entry->access);
return ret;
}
static ssize_t snd_info_entry_read(struct file *file, char __user *buffer,
size_t count, loff_t * offset)
{
struct snd_info_private_data *data;
struct snd_info_entry *entry;
struct snd_info_buffer *buf;
size_t size = 0;
loff_t pos;
data = file->private_data;
if (snd_BUG_ON(!data))
return -ENXIO;
pos = *offset;
if (pos < 0 || (long) pos != pos || (ssize_t) count < 0)
return -EIO;
if ((unsigned long) pos + (unsigned long) count < (unsigned long) pos)
return -EIO;
entry = data->entry;
switch (entry->content) {
case SNDRV_INFO_CONTENT_TEXT:
buf = data->rbuffer;
if (buf == NULL)
return -EIO;
if (pos >= buf->size)
return 0;
size = buf->size - pos;
size = min(count, size);
if (copy_to_user(buffer, buf->buffer + pos, size))
return -EFAULT;
break;
case SNDRV_INFO_CONTENT_DATA:
if (pos >= entry->size)
return 0;
if (entry->c.ops->read) {
size = entry->size - pos;
size = min(count, size);
size = entry->c.ops->read(entry,
data->file_private_data,
file, buffer, size, pos);
}
break;
}
if ((ssize_t) size > 0)
*offset = pos + size;
return size;
}
static ssize_t snd_info_entry_write(struct file *file, const char __user *buffer,
size_t count, loff_t * offset)
{
struct snd_info_private_data *data;
struct snd_info_entry *entry;
struct snd_info_buffer *buf;
ssize_t size = 0;
loff_t pos;
data = file->private_data;
if (snd_BUG_ON(!data))
return -ENXIO;
entry = data->entry;
pos = *offset;
if (pos < 0 || (long) pos != pos || (ssize_t) count < 0)
return -EIO;
if ((unsigned long) pos + (unsigned long) count < (unsigned long) pos)
return -EIO;
switch (entry->content) {
case SNDRV_INFO_CONTENT_TEXT:
buf = data->wbuffer;
if (buf == NULL)
return -EIO;
mutex_lock(&entry->access);
if (pos + count >= buf->len) {
if (resize_info_buffer(buf, pos + count)) {
mutex_unlock(&entry->access);
return -ENOMEM;
}
}
if (copy_from_user(buf->buffer + pos, buffer, count)) {
mutex_unlock(&entry->access);
return -EFAULT;
}
buf->size = pos + count;
mutex_unlock(&entry->access);
size = count;
break;
case SNDRV_INFO_CONTENT_DATA:
if (entry->c.ops->write && count > 0) {
size_t maxsize = entry->size - pos;
count = min(count, maxsize);
size = entry->c.ops->write(entry,
data->file_private_data,
file, buffer, count, pos);
}
break;
}
if ((ssize_t) size > 0)
*offset = pos + size;
return size;
}
static int snd_info_entry_open(struct inode *inode, struct file *file)
{
struct snd_info_entry *entry;
struct snd_info_private_data *data;
struct snd_info_buffer *buffer;
struct proc_dir_entry *p;
int mode, err;
mutex_lock(&info_mutex);
p = PDE(inode);
entry = p == NULL ? NULL : (struct snd_info_entry *)p->data;
if (entry == NULL || ! entry->p) {
mutex_unlock(&info_mutex);
return -ENODEV;
}
if (!try_module_get(entry->module)) {
err = -EFAULT;
goto __error1;
}
mode = file->f_flags & O_ACCMODE;
if (mode == O_RDONLY || mode == O_RDWR) {
if ((entry->content == SNDRV_INFO_CONTENT_DATA &&
entry->c.ops->read == NULL)) {
err = -ENODEV;
goto __error;
}
}
if (mode == O_WRONLY || mode == O_RDWR) {
if ((entry->content == SNDRV_INFO_CONTENT_DATA &&
entry->c.ops->write == NULL)) {
err = -ENODEV;
goto __error;
}
}
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (data == NULL) {
err = -ENOMEM;
goto __error;
}
data->entry = entry;
switch (entry->content) {
case SNDRV_INFO_CONTENT_TEXT:
if (mode == O_RDONLY || mode == O_RDWR) {
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (buffer == NULL)
goto __nomem;
data->rbuffer = buffer;
buffer->len = PAGE_SIZE;
buffer->buffer = kmalloc(buffer->len, GFP_KERNEL);
if (buffer->buffer == NULL)
goto __nomem;
}
if (mode == O_WRONLY || mode == O_RDWR) {
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (buffer == NULL)
goto __nomem;
data->wbuffer = buffer;
buffer->len = PAGE_SIZE;
buffer->buffer = kmalloc(buffer->len, GFP_KERNEL);
if (buffer->buffer == NULL)
goto __nomem;
}
break;
case SNDRV_INFO_CONTENT_DATA:
if (entry->c.ops->open) {
if ((err = entry->c.ops->open(entry, mode,
&data->file_private_data)) < 0) {
kfree(data);
goto __error;
}
}
break;
}
file->private_data = data;
mutex_unlock(&info_mutex);
if (entry->content == SNDRV_INFO_CONTENT_TEXT &&
(mode == O_RDONLY || mode == O_RDWR)) {
if (entry->c.text.read) {
mutex_lock(&entry->access);
entry->c.text.read(entry, data->rbuffer);
mutex_unlock(&entry->access);
}
}
return 0;
__nomem:
if (data->rbuffer) {
kfree(data->rbuffer->buffer);
kfree(data->rbuffer);
}
if (data->wbuffer) {
kfree(data->wbuffer->buffer);
kfree(data->wbuffer);
}
kfree(data);
err = -ENOMEM;
__error:
module_put(entry->module);
__error1:
mutex_unlock(&info_mutex);
return err;
}
static int snd_info_entry_release(struct inode *inode, struct file *file)
{
struct snd_info_entry *entry;
struct snd_info_private_data *data;
int mode;
mode = file->f_flags & O_ACCMODE;
data = file->private_data;
entry = data->entry;
switch (entry->content) {
case SNDRV_INFO_CONTENT_TEXT:
if (data->rbuffer) {
kfree(data->rbuffer->buffer);
kfree(data->rbuffer);
}
if (data->wbuffer) {
if (entry->c.text.write) {
entry->c.text.write(entry, data->wbuffer);
if (data->wbuffer->error) {
snd_printk(KERN_WARNING "data write error to %s (%i)\n",
entry->name,
data->wbuffer->error);
}
}
kfree(data->wbuffer->buffer);
kfree(data->wbuffer);
}
break;
case SNDRV_INFO_CONTENT_DATA:
if (entry->c.ops->release)
entry->c.ops->release(entry, mode,
data->file_private_data);
break;
}
module_put(entry->module);
kfree(data);
return 0;
}
static unsigned int snd_info_entry_poll(struct file *file, poll_table * wait)
{
struct snd_info_private_data *data;
struct snd_info_entry *entry;
unsigned int mask;
data = file->private_data;
if (data == NULL)
return 0;
entry = data->entry;
mask = 0;
switch (entry->content) {
case SNDRV_INFO_CONTENT_DATA:
if (entry->c.ops->poll)
return entry->c.ops->poll(entry,
data->file_private_data,
file, wait);
if (entry->c.ops->read)
mask |= POLLIN | POLLRDNORM;
if (entry->c.ops->write)
mask |= POLLOUT | POLLWRNORM;
break;
}
return mask;
}
static long snd_info_entry_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct snd_info_private_data *data;
struct snd_info_entry *entry;
data = file->private_data;
if (data == NULL)
return 0;
entry = data->entry;
switch (entry->content) {
case SNDRV_INFO_CONTENT_DATA:
if (entry->c.ops->ioctl)
return entry->c.ops->ioctl(entry,
data->file_private_data,
file, cmd, arg);
break;
}
return -ENOTTY;
}
static int snd_info_entry_mmap(struct file *file, struct vm_area_struct *vma)
{
struct inode *inode = file_inode(file);
struct snd_info_private_data *data;
struct snd_info_entry *entry;
data = file->private_data;
if (data == NULL)
return 0;
entry = data->entry;
switch (entry->content) {
case SNDRV_INFO_CONTENT_DATA:
if (entry->c.ops->mmap)
return entry->c.ops->mmap(entry,
data->file_private_data,
inode, file, vma);
break;
}
return -ENXIO;
}
int __init snd_info_init(void)
{
struct proc_dir_entry *p;
p = proc_mkdir("asound", NULL);
if (p == NULL)
return -ENOMEM;
snd_proc_root = p;
#ifdef CONFIG_SND_OSSEMUL
{
struct snd_info_entry *entry;
if ((entry = snd_info_create_module_entry(THIS_MODULE, "oss", NULL)) == NULL)
return -ENOMEM;
entry->mode = S_IFDIR | S_IRUGO | S_IXUGO;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
return -ENOMEM;
}
snd_oss_root = entry;
}
#endif
#if defined(CONFIG_SND_SEQUENCER) || defined(CONFIG_SND_SEQUENCER_MODULE)
{
struct snd_info_entry *entry;
if ((entry = snd_info_create_module_entry(THIS_MODULE, "seq", NULL)) == NULL)
return -ENOMEM;
entry->mode = S_IFDIR | S_IRUGO | S_IXUGO;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
return -ENOMEM;
}
snd_seq_root = entry;
}
#endif
snd_info_version_init();
snd_minor_info_init();
snd_minor_info_oss_init();
snd_card_info_init();
return 0;
}
int __exit snd_info_done(void)
{
snd_card_info_done();
snd_minor_info_oss_done();
snd_minor_info_done();
snd_info_version_done();
if (snd_proc_root) {
#if defined(CONFIG_SND_SEQUENCER) || defined(CONFIG_SND_SEQUENCER_MODULE)
snd_info_free_entry(snd_seq_root);
#endif
#ifdef CONFIG_SND_OSSEMUL
snd_info_free_entry(snd_oss_root);
#endif
snd_remove_proc_entry(NULL, snd_proc_root);
}
return 0;
}
int snd_info_card_create(struct snd_card *card)
{
char str[8];
struct snd_info_entry *entry;
if (snd_BUG_ON(!card))
return -ENXIO;
sprintf(str, "card%i", card->number);
if ((entry = snd_info_create_module_entry(card->module, str, NULL)) == NULL)
return -ENOMEM;
entry->mode = S_IFDIR | S_IRUGO | S_IXUGO;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
return -ENOMEM;
}
card->proc_root = entry;
return 0;
}
int snd_info_card_register(struct snd_card *card)
{
struct proc_dir_entry *p;
if (snd_BUG_ON(!card))
return -ENXIO;
if (!strcmp(card->id, card->proc_root->name))
return 0;
p = proc_symlink(card->id, snd_proc_root, card->proc_root->name);
if (p == NULL)
return -ENOMEM;
card->proc_root_link = p;
return 0;
}
void snd_info_card_id_change(struct snd_card *card)
{
mutex_lock(&info_mutex);
if (card->proc_root_link) {
snd_remove_proc_entry(snd_proc_root, card->proc_root_link);
card->proc_root_link = NULL;
}
if (strcmp(card->id, card->proc_root->name))
card->proc_root_link = proc_symlink(card->id,
snd_proc_root,
card->proc_root->name);
mutex_unlock(&info_mutex);
}
void snd_info_card_disconnect(struct snd_card *card)
{
if (!card)
return;
mutex_lock(&info_mutex);
if (card->proc_root_link) {
snd_remove_proc_entry(snd_proc_root, card->proc_root_link);
card->proc_root_link = NULL;
}
if (card->proc_root)
snd_info_disconnect(card->proc_root);
mutex_unlock(&info_mutex);
}
int snd_info_card_free(struct snd_card *card)
{
if (!card)
return 0;
snd_info_free_entry(card->proc_root);
card->proc_root = NULL;
return 0;
}
int snd_info_get_line(struct snd_info_buffer *buffer, char *line, int len)
{
int c = -1;
if (len <= 0 || buffer->stop || buffer->error)
return 1;
while (--len > 0) {
c = buffer->buffer[buffer->curr++];
if (c == '\n') {
if (buffer->curr >= buffer->size)
buffer->stop = 1;
break;
}
*line++ = c;
if (buffer->curr >= buffer->size) {
buffer->stop = 1;
break;
}
}
while (c != '\n' && !buffer->stop) {
c = buffer->buffer[buffer->curr++];
if (buffer->curr >= buffer->size)
buffer->stop = 1;
}
*line = '\0';
return 0;
}
const char *snd_info_get_str(char *dest, const char *src, int len)
{
int c;
while (*src == ' ' || *src == '\t')
src++;
if (*src == '"' || *src == '\'') {
c = *src++;
while (--len > 0 && *src && *src != c) {
*dest++ = *src++;
}
if (*src == c)
src++;
} else {
while (--len > 0 && *src && *src != ' ' && *src != '\t') {
*dest++ = *src++;
}
}
*dest = 0;
while (*src == ' ' || *src == '\t')
src++;
return src;
}
static struct snd_info_entry *snd_info_create_entry(const char *name)
{
struct snd_info_entry *entry;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (entry == NULL)
return NULL;
entry->name = kstrdup(name, GFP_KERNEL);
if (entry->name == NULL) {
kfree(entry);
return NULL;
}
entry->mode = S_IFREG | S_IRUGO;
entry->content = SNDRV_INFO_CONTENT_TEXT;
mutex_init(&entry->access);
INIT_LIST_HEAD(&entry->children);
INIT_LIST_HEAD(&entry->list);
return entry;
}
struct snd_info_entry *snd_info_create_module_entry(struct module * module,
const char *name,
struct snd_info_entry *parent)
{
struct snd_info_entry *entry = snd_info_create_entry(name);
if (entry) {
entry->module = module;
entry->parent = parent;
}
return entry;
}
struct snd_info_entry *snd_info_create_card_entry(struct snd_card *card,
const char *name,
struct snd_info_entry * parent)
{
struct snd_info_entry *entry = snd_info_create_entry(name);
if (entry) {
entry->module = card->module;
entry->card = card;
entry->parent = parent;
}
return entry;
}
static void snd_info_disconnect(struct snd_info_entry *entry)
{
struct list_head *p, *n;
struct proc_dir_entry *root;
list_for_each_safe(p, n, &entry->children) {
snd_info_disconnect(list_entry(p, struct snd_info_entry, list));
}
if (! entry->p)
return;
list_del_init(&entry->list);
root = entry->parent == NULL ? snd_proc_root : entry->parent->p;
snd_BUG_ON(!root);
snd_remove_proc_entry(root, entry->p);
entry->p = NULL;
}
static int snd_info_dev_free_entry(struct snd_device *device)
{
struct snd_info_entry *entry = device->device_data;
snd_info_free_entry(entry);
return 0;
}
static int snd_info_dev_register_entry(struct snd_device *device)
{
struct snd_info_entry *entry = device->device_data;
return snd_info_register(entry);
}
int snd_card_proc_new(struct snd_card *card, const char *name,
struct snd_info_entry **entryp)
{
static struct snd_device_ops ops = {
.dev_free = snd_info_dev_free_entry,
.dev_register = snd_info_dev_register_entry,
};
struct snd_info_entry *entry;
int err;
entry = snd_info_create_card_entry(card, name, card->proc_root);
if (! entry)
return -ENOMEM;
if ((err = snd_device_new(card, SNDRV_DEV_INFO, entry, &ops)) < 0) {
snd_info_free_entry(entry);
return err;
}
if (entryp)
*entryp = entry;
return 0;
}
void snd_info_free_entry(struct snd_info_entry * entry)
{
if (entry == NULL)
return;
if (entry->p) {
mutex_lock(&info_mutex);
snd_info_disconnect(entry);
mutex_unlock(&info_mutex);
}
kfree(entry->name);
if (entry->private_free)
entry->private_free(entry);
kfree(entry);
}
int snd_info_register(struct snd_info_entry * entry)
{
struct proc_dir_entry *root, *p = NULL;
if (snd_BUG_ON(!entry))
return -ENXIO;
root = entry->parent == NULL ? snd_proc_root : entry->parent->p;
mutex_lock(&info_mutex);
p = create_proc_entry(entry->name, entry->mode, root);
if (!p) {
mutex_unlock(&info_mutex);
return -ENOMEM;
}
if (!S_ISDIR(entry->mode))
p->proc_fops = &snd_info_entry_operations;
p->size = entry->size;
p->data = entry;
entry->p = p;
if (entry->parent)
list_add_tail(&entry->list, &entry->parent->children);
mutex_unlock(&info_mutex);
return 0;
}
static void snd_info_version_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
snd_iprintf(buffer,
"Advanced Linux Sound Architecture Driver Version k%s.\n",
init_utsname()->release);
}
static int __init snd_info_version_init(void)
{
struct snd_info_entry *entry;
entry = snd_info_create_module_entry(THIS_MODULE, "version", NULL);
if (entry == NULL)
return -ENOMEM;
entry->c.text.read = snd_info_version_read;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
return -ENOMEM;
}
snd_info_version_entry = entry;
return 0;
}
static int __exit snd_info_version_done(void)
{
snd_info_free_entry(snd_info_version_entry);
return 0;
}
