static void seq_set_overflow(struct seq_file *m)
{
m->count = m->size;
}
static void *seq_buf_alloc(unsigned long size)
{
void *buf;
gfp_t gfp = GFP_KERNEL;
if (size > PAGE_SIZE)
gfp |= __GFP_NORETRY | __GFP_NOWARN;
buf = kmalloc(size, gfp);
if (!buf && size > PAGE_SIZE)
buf = vmalloc(size);
return buf;
}
int seq_open(struct file *file, const struct seq_operations *op)
{
struct seq_file *p;
WARN_ON(file->private_data);
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
file->private_data = p;
mutex_init(&p->lock);
p->op = op;
p->file = file;
file->f_version = 0;
file->f_mode &= ~FMODE_PWRITE;
return 0;
}
static int traverse(struct seq_file *m, loff_t offset)
{
loff_t pos = 0, index;
int error = 0;
void *p;
m->version = 0;
index = 0;
m->count = m->from = 0;
if (!offset) {
m->index = index;
return 0;
}
if (!m->buf) {
m->buf = seq_buf_alloc(m->size = PAGE_SIZE);
if (!m->buf)
return -ENOMEM;
}
p = m->op->start(m, &index);
while (p) {
error = PTR_ERR(p);
if (IS_ERR(p))
break;
error = m->op->show(m, p);
if (error < 0)
break;
if (unlikely(error)) {
error = 0;
m->count = 0;
}
if (seq_has_overflowed(m))
goto Eoverflow;
if (pos + m->count > offset) {
m->from = offset - pos;
m->count -= m->from;
m->index = index;
break;
}
pos += m->count;
m->count = 0;
if (pos == offset) {
index++;
m->index = index;
break;
}
p = m->op->next(m, p, &index);
}
m->op->stop(m, p);
m->index = index;
return error;
Eoverflow:
m->op->stop(m, p);
kvfree(m->buf);
m->count = 0;
m->buf = seq_buf_alloc(m->size <<= 1);
return !m->buf ? -ENOMEM : -EAGAIN;
}
ssize_t seq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
struct seq_file *m = file->private_data;
size_t copied = 0;
loff_t pos;
size_t n;
void *p;
int err = 0;
mutex_lock(&m->lock);
m->version = file->f_version;
if (*ppos == 0)
m->index = 0;
if (unlikely(*ppos != m->read_pos)) {
while ((err = traverse(m, *ppos)) == -EAGAIN)
;
if (err) {
m->read_pos = 0;
m->version = 0;
m->index = 0;
m->count = 0;
goto Done;
} else {
m->read_pos = *ppos;
}
}
if (!m->buf) {
m->buf = seq_buf_alloc(m->size = PAGE_SIZE);
if (!m->buf)
goto Enomem;
}
if (m->count) {
n = min(m->count, size);
err = copy_to_user(buf, m->buf + m->from, n);
if (err)
goto Efault;
m->count -= n;
m->from += n;
size -= n;
buf += n;
copied += n;
if (!m->count) {
m->from = 0;
m->index++;
}
if (!size)
goto Done;
}
pos = m->index;
p = m->op->start(m, &pos);
while (1) {
err = PTR_ERR(p);
if (!p || IS_ERR(p))
break;
err = m->op->show(m, p);
if (err < 0)
break;
if (unlikely(err))
m->count = 0;
if (unlikely(!m->count)) {
p = m->op->next(m, p, &pos);
m->index = pos;
continue;
}
if (m->count < m->size)
goto Fill;
m->op->stop(m, p);
kvfree(m->buf);
m->count = 0;
m->buf = seq_buf_alloc(m->size <<= 1);
if (!m->buf)
goto Enomem;
m->version = 0;
pos = m->index;
p = m->op->start(m, &pos);
}
m->op->stop(m, p);
m->count = 0;
goto Done;
Fill:
while (m->count < size) {
size_t offs = m->count;
loff_t next = pos;
p = m->op->next(m, p, &next);
if (!p || IS_ERR(p)) {
err = PTR_ERR(p);
break;
}
err = m->op->show(m, p);
if (seq_has_overflowed(m) || err) {
m->count = offs;
if (likely(err <= 0))
break;
}
pos = next;
}
m->op->stop(m, p);
n = min(m->count, size);
err = copy_to_user(buf, m->buf, n);
if (err)
goto Efault;
copied += n;
m->count -= n;
if (m->count)
m->from = n;
else
pos++;
m->index = pos;
Done:
if (!copied)
copied = err;
else {
*ppos += copied;
m->read_pos += copied;
}
file->f_version = m->version;
mutex_unlock(&m->lock);
return copied;
Enomem:
err = -ENOMEM;
goto Done;
Efault:
err = -EFAULT;
goto Done;
}
loff_t seq_lseek(struct file *file, loff_t offset, int whence)
{
struct seq_file *m = file->private_data;
loff_t retval = -EINVAL;
mutex_lock(&m->lock);
m->version = file->f_version;
switch (whence) {
case SEEK_CUR:
offset += file->f_pos;
case SEEK_SET:
if (offset < 0)
break;
retval = offset;
if (offset != m->read_pos) {
while ((retval = traverse(m, offset)) == -EAGAIN)
;
if (retval) {
file->f_pos = 0;
m->read_pos = 0;
m->version = 0;
m->index = 0;
m->count = 0;
} else {
m->read_pos = offset;
retval = file->f_pos = offset;
}
} else {
file->f_pos = offset;
}
}
file->f_version = m->version;
mutex_unlock(&m->lock);
return retval;
}
int seq_release(struct inode *inode, struct file *file)
{
struct seq_file *m = file->private_data;
kvfree(m->buf);
kfree(m);
return 0;
}
void seq_escape(struct seq_file *m, const char *s, const char *esc)
{
char *buf;
size_t size = seq_get_buf(m, &buf);
int ret;
ret = string_escape_str(s, buf, size, ESCAPE_OCTAL, esc);
seq_commit(m, ret < size ? ret : -1);
}
void seq_vprintf(struct seq_file *m, const char *f, va_list args)
{
int len;
if (m->count < m->size) {
len = vsnprintf(m->buf + m->count, m->size - m->count, f, args);
if (m->count + len < m->size) {
m->count += len;
return;
}
}
seq_set_overflow(m);
}
void seq_printf(struct seq_file *m, const char *f, ...)
{
va_list args;
va_start(args, f);
seq_vprintf(m, f, args);
va_end(args);
}
char *mangle_path(char *s, const char *p, const char *esc)
{
while (s <= p) {
char c = *p++;
if (!c) {
return s;
} else if (!strchr(esc, c)) {
*s++ = c;
} else if (s + 4 > p) {
break;
} else {
*s++ = '\\';
*s++ = '0' + ((c & 0300) >> 6);
*s++ = '0' + ((c & 070) >> 3);
*s++ = '0' + (c & 07);
}
}
return NULL;
}
int seq_path(struct seq_file *m, const struct path *path, const char *esc)
{
char *buf;
size_t size = seq_get_buf(m, &buf);
int res = -1;
if (size) {
char *p = d_path(path, buf, size);
if (!IS_ERR(p)) {
char *end = mangle_path(buf, p, esc);
if (end)
res = end - buf;
}
}
seq_commit(m, res);
return res;
}
int seq_file_path(struct seq_file *m, struct file *file, const char *esc)
{
return seq_path(m, &file->f_path, esc);
}
int seq_path_root(struct seq_file *m, const struct path *path,
const struct path *root, const char *esc)
{
char *buf;
size_t size = seq_get_buf(m, &buf);
int res = -ENAMETOOLONG;
if (size) {
char *p;
p = __d_path(path, root, buf, size);
if (!p)
return SEQ_SKIP;
res = PTR_ERR(p);
if (!IS_ERR(p)) {
char *end = mangle_path(buf, p, esc);
if (end)
res = end - buf;
else
res = -ENAMETOOLONG;
}
}
seq_commit(m, res);
return res < 0 && res != -ENAMETOOLONG ? res : 0;
}
int seq_dentry(struct seq_file *m, struct dentry *dentry, const char *esc)
{
char *buf;
size_t size = seq_get_buf(m, &buf);
int res = -1;
if (size) {
char *p = dentry_path(dentry, buf, size);
if (!IS_ERR(p)) {
char *end = mangle_path(buf, p, esc);
if (end)
res = end - buf;
}
}
seq_commit(m, res);
return res;
}
static void *single_start(struct seq_file *p, loff_t *pos)
{
return NULL + (*pos == 0);
}
static void *single_next(struct seq_file *p, void *v, loff_t *pos)
{
++*pos;
return NULL;
}
static void single_stop(struct seq_file *p, void *v)
{
}
int single_open(struct file *file, int (*show)(struct seq_file *, void *),
void *data)
{
struct seq_operations *op = kmalloc(sizeof(*op), GFP_KERNEL);
int res = -ENOMEM;
if (op) {
op->start = single_start;
op->next = single_next;
op->stop = single_stop;
op->show = show;
res = seq_open(file, op);
if (!res)
((struct seq_file *)file->private_data)->private = data;
else
kfree(op);
}
return res;
}
int single_open_size(struct file *file, int (*show)(struct seq_file *, void *),
void *data, size_t size)
{
char *buf = seq_buf_alloc(size);
int ret;
if (!buf)
return -ENOMEM;
ret = single_open(file, show, data);
if (ret) {
kvfree(buf);
return ret;
}
((struct seq_file *)file->private_data)->buf = buf;
((struct seq_file *)file->private_data)->size = size;
return 0;
}
int single_release(struct inode *inode, struct file *file)
{
const struct seq_operations *op = ((struct seq_file *)file->private_data)->op;
int res = seq_release(inode, file);
kfree(op);
return res;
}
int seq_release_private(struct inode *inode, struct file *file)
{
struct seq_file *seq = file->private_data;
kfree(seq->private);
seq->private = NULL;
return seq_release(inode, file);
}
void *__seq_open_private(struct file *f, const struct seq_operations *ops,
int psize)
{
int rc;
void *private;
struct seq_file *seq;
private = kzalloc(psize, GFP_KERNEL);
if (private == NULL)
goto out;
rc = seq_open(f, ops);
if (rc < 0)
goto out_free;
seq = f->private_data;
seq->private = private;
return private;
out_free:
kfree(private);
out:
return NULL;
}
int seq_open_private(struct file *filp, const struct seq_operations *ops,
int psize)
{
return __seq_open_private(filp, ops, psize) ? 0 : -ENOMEM;
}
void seq_putc(struct seq_file *m, char c)
{
if (m->count >= m->size)
return;
m->buf[m->count++] = c;
}
void seq_puts(struct seq_file *m, const char *s)
{
int len = strlen(s);
if (m->count + len >= m->size) {
seq_set_overflow(m);
return;
}
memcpy(m->buf + m->count, s, len);
m->count += len;
}
void seq_put_decimal_ull(struct seq_file *m, const char *delimiter,
unsigned long long num)
{
int len;
if (m->count + 2 >= m->size)
goto overflow;
len = strlen(delimiter);
if (m->count + len >= m->size)
goto overflow;
memcpy(m->buf + m->count, delimiter, len);
m->count += len;
if (m->count + 1 >= m->size)
goto overflow;
if (num < 10) {
m->buf[m->count++] = num + '0';
return;
}
len = num_to_str(m->buf + m->count, m->size - m->count, num);
if (!len)
goto overflow;
m->count += len;
return;
overflow:
seq_set_overflow(m);
}
void seq_put_decimal_ll(struct seq_file *m, const char *delimiter, long long num)
{
int len;
if (m->count + 3 >= m->size)
goto overflow;
len = strlen(delimiter);
if (m->count + len >= m->size)
goto overflow;
memcpy(m->buf + m->count, delimiter, len);
m->count += len;
if (m->count + 2 >= m->size)
goto overflow;
if (num < 0) {
m->buf[m->count++] = '-';
num = -num;
}
if (num < 10) {
m->buf[m->count++] = num + '0';
return;
}
len = num_to_str(m->buf + m->count, m->size - m->count, num);
if (!len)
goto overflow;
m->count += len;
return;
overflow:
seq_set_overflow(m);
}
int seq_write(struct seq_file *seq, const void *data, size_t len)
{
if (seq->count + len < seq->size) {
memcpy(seq->buf + seq->count, data, len);
seq->count += len;
return 0;
}
seq_set_overflow(seq);
return -1;
}
void seq_pad(struct seq_file *m, char c)
{
int size = m->pad_until - m->count;
if (size > 0)
seq_printf(m, "%*s", size, "");
if (c)
seq_putc(m, c);
}
void seq_hex_dump(struct seq_file *m, const char *prefix_str, int prefix_type,
int rowsize, int groupsize, const void *buf, size_t len,
bool ascii)
{
const u8 *ptr = buf;
int i, linelen, remaining = len;
char *buffer;
size_t size;
int ret;
if (rowsize != 16 && rowsize != 32)
rowsize = 16;
for (i = 0; i < len && !seq_has_overflowed(m); i += rowsize) {
linelen = min(remaining, rowsize);
remaining -= rowsize;
switch (prefix_type) {
case DUMP_PREFIX_ADDRESS:
seq_printf(m, "%s%p: ", prefix_str, ptr + i);
break;
case DUMP_PREFIX_OFFSET:
seq_printf(m, "%s%.8x: ", prefix_str, i);
break;
default:
seq_printf(m, "%s", prefix_str);
break;
}
size = seq_get_buf(m, &buffer);
ret = hex_dump_to_buffer(ptr + i, linelen, rowsize, groupsize,
buffer, size, ascii);
seq_commit(m, ret < size ? ret : -1);
seq_putc(m, '\n');
}
}
struct list_head *seq_list_start(struct list_head *head, loff_t pos)
{
struct list_head *lh;
list_for_each(lh, head)
if (pos-- == 0)
return lh;
return NULL;
}
struct list_head *seq_list_start_head(struct list_head *head, loff_t pos)
{
if (!pos)
return head;
return seq_list_start(head, pos - 1);
}
struct list_head *seq_list_next(void *v, struct list_head *head, loff_t *ppos)
{
struct list_head *lh;
lh = ((struct list_head *)v)->next;
++*ppos;
return lh == head ? NULL : lh;
}
struct hlist_node *seq_hlist_start(struct hlist_head *head, loff_t pos)
{
struct hlist_node *node;
hlist_for_each(node, head)
if (pos-- == 0)
return node;
return NULL;
}
struct hlist_node *seq_hlist_start_head(struct hlist_head *head, loff_t pos)
{
if (!pos)
return SEQ_START_TOKEN;
return seq_hlist_start(head, pos - 1);
}
struct hlist_node *seq_hlist_next(void *v, struct hlist_head *head,
loff_t *ppos)
{
struct hlist_node *node = v;
++*ppos;
if (v == SEQ_START_TOKEN)
return head->first;
else
return node->next;
}
struct hlist_node *seq_hlist_start_rcu(struct hlist_head *head,
loff_t pos)
{
struct hlist_node *node;
__hlist_for_each_rcu(node, head)
if (pos-- == 0)
return node;
return NULL;
}
struct hlist_node *seq_hlist_start_head_rcu(struct hlist_head *head,
loff_t pos)
{
if (!pos)
return SEQ_START_TOKEN;
return seq_hlist_start_rcu(head, pos - 1);
}
struct hlist_node *seq_hlist_next_rcu(void *v,
struct hlist_head *head,
loff_t *ppos)
{
struct hlist_node *node = v;
++*ppos;
if (v == SEQ_START_TOKEN)
return rcu_dereference(head->first);
else
return rcu_dereference(node->next);
}
struct hlist_node *
seq_hlist_start_percpu(struct hlist_head __percpu *head, int *cpu, loff_t pos)
{
struct hlist_node *node;
for_each_possible_cpu(*cpu) {
hlist_for_each(node, per_cpu_ptr(head, *cpu)) {
if (pos-- == 0)
return node;
}
}
return NULL;
}
struct hlist_node *
seq_hlist_next_percpu(void *v, struct hlist_head __percpu *head,
int *cpu, loff_t *pos)
{
struct hlist_node *node = v;
++*pos;
if (node->next)
return node->next;
for (*cpu = cpumask_next(*cpu, cpu_possible_mask); *cpu < nr_cpu_ids;
*cpu = cpumask_next(*cpu, cpu_possible_mask)) {
struct hlist_head *bucket = per_cpu_ptr(head, *cpu);
if (!hlist_empty(bucket))
return bucket->first;
}
return NULL;
}
