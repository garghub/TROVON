void fscache_objlist_add(struct fscache_object *obj)
{
struct fscache_object *xobj;
struct rb_node **p = &fscache_object_list.rb_node, *parent = NULL;
write_lock(&fscache_object_list_lock);
while (*p) {
parent = *p;
xobj = rb_entry(parent, struct fscache_object, objlist_link);
if (obj < xobj)
p = &(*p)->rb_left;
else if (obj > xobj)
p = &(*p)->rb_right;
else
BUG();
}
rb_link_node(&obj->objlist_link, parent, p);
rb_insert_color(&obj->objlist_link, &fscache_object_list);
write_unlock(&fscache_object_list_lock);
}
void fscache_object_destroy(struct fscache_object *obj)
{
write_lock(&fscache_object_list_lock);
BUG_ON(RB_EMPTY_ROOT(&fscache_object_list));
rb_erase(&obj->objlist_link, &fscache_object_list);
write_unlock(&fscache_object_list_lock);
}
static struct fscache_object *fscache_objlist_lookup(loff_t *_pos)
{
struct fscache_object *pobj, *obj = NULL, *minobj = NULL;
struct rb_node *p;
unsigned long pos;
if (*_pos >= (unsigned long) ERR_PTR(-ENOENT))
return NULL;
pos = *_pos;
if (pos == 0)
return (struct fscache_object *)(long)++(*_pos);
if (pos < 3)
return (struct fscache_object *)pos;
pobj = (struct fscache_object *)pos;
p = fscache_object_list.rb_node;
while (p) {
obj = rb_entry(p, struct fscache_object, objlist_link);
if (pobj < obj) {
if (!minobj || minobj > obj)
minobj = obj;
p = p->rb_left;
} else if (pobj > obj) {
p = p->rb_right;
} else {
minobj = obj;
break;
}
obj = NULL;
}
if (!minobj)
*_pos = (unsigned long) ERR_PTR(-ENOENT);
else if (minobj != obj)
*_pos = (unsigned long) minobj;
return minobj;
}
static void *fscache_objlist_start(struct seq_file *m, loff_t *_pos)
__acquires(&fscache_object_list_lock
static void *fscache_objlist_next(struct seq_file *m, void *v, loff_t *_pos)
{
(*_pos)++;
return fscache_objlist_lookup(_pos);
}
static void fscache_objlist_stop(struct seq_file *m, void *v)
__releases(&fscache_object_list_lock
static int fscache_objlist_show(struct seq_file *m, void *v)
{
struct fscache_objlist_data *data = m->private;
struct fscache_object *obj = v;
unsigned long config = data->config;
uint16_t keylen, auxlen;
char _type[3], *type;
bool no_cookie;
u8 *buf = data->buf, *p;
if ((unsigned long) v == 1) {
seq_puts(m, "OBJECT PARENT STAT CHLDN OPS OOP IPR EX READS"
" EM EV F S"
" | NETFS_COOKIE_DEF TY FL NETFS_DATA");
if (config & (FSCACHE_OBJLIST_CONFIG_KEY |
FSCACHE_OBJLIST_CONFIG_AUX))
seq_puts(m, " ");
if (config & FSCACHE_OBJLIST_CONFIG_KEY)
seq_puts(m, "OBJECT_KEY");
if ((config & (FSCACHE_OBJLIST_CONFIG_KEY |
FSCACHE_OBJLIST_CONFIG_AUX)) ==
(FSCACHE_OBJLIST_CONFIG_KEY | FSCACHE_OBJLIST_CONFIG_AUX))
seq_puts(m, ", ");
if (config & FSCACHE_OBJLIST_CONFIG_AUX)
seq_puts(m, "AUX_DATA");
seq_puts(m, "\n");
return 0;
}
if ((unsigned long) v == 2) {
seq_puts(m, "======== ======== ==== ===== === === === == ====="
" == == = ="
" | ================ == == ================");
if (config & (FSCACHE_OBJLIST_CONFIG_KEY |
FSCACHE_OBJLIST_CONFIG_AUX))
seq_puts(m, " ================");
seq_puts(m, "\n");
return 0;
}
#define FILTER(criterion, _yes, _no) \
do { \
unsigned long yes = FSCACHE_OBJLIST_CONFIG_##_yes; \
unsigned long no = FSCACHE_OBJLIST_CONFIG_##_no; \
if (criterion) { \
if (!(config & yes)) \
return 0; \
} else { \
if (!(config & no)) \
return 0; \
} \
} while(0)
if (~config) {
FILTER(obj->cookie,
COOKIE, NOCOOKIE);
FILTER(obj->state != FSCACHE_OBJECT_ACTIVE ||
obj->n_ops != 0 ||
obj->n_obj_ops != 0 ||
obj->flags ||
!list_empty(&obj->dependents),
BUSY, IDLE);
FILTER(test_bit(FSCACHE_OBJECT_PENDING_WRITE, &obj->flags),
PENDWR, NOPENDWR);
FILTER(atomic_read(&obj->n_reads),
READS, NOREADS);
FILTER(obj->events & obj->event_mask,
EVENTS, NOEVENTS);
FILTER(work_busy(&obj->work), WORK, NOWORK);
}
seq_printf(m,
"%8x %8x %s %5u %3u %3u %3u %2u %5u %2lx %2lx %1lx %1x | ",
obj->debug_id,
obj->parent ? obj->parent->debug_id : -1,
fscache_object_states_short[obj->state],
obj->n_children,
obj->n_ops,
obj->n_obj_ops,
obj->n_in_progress,
obj->n_exclusive,
atomic_read(&obj->n_reads),
obj->event_mask,
obj->events,
obj->flags,
work_busy(&obj->work));
no_cookie = true;
keylen = auxlen = 0;
if (obj->cookie) {
spin_lock(&obj->lock);
if (obj->cookie) {
switch (obj->cookie->def->type) {
case 0:
type = "IX";
break;
case 1:
type = "DT";
break;
default:
sprintf(_type, "%02u",
obj->cookie->def->type);
type = _type;
break;
}
seq_printf(m, "%-16s %s %2lx %16p",
obj->cookie->def->name,
type,
obj->cookie->flags,
obj->cookie->netfs_data);
if (obj->cookie->def->get_key &&
config & FSCACHE_OBJLIST_CONFIG_KEY)
keylen = obj->cookie->def->get_key(
obj->cookie->netfs_data,
buf, 400);
if (obj->cookie->def->get_aux &&
config & FSCACHE_OBJLIST_CONFIG_AUX)
auxlen = obj->cookie->def->get_aux(
obj->cookie->netfs_data,
buf + keylen, 512 - keylen);
no_cookie = false;
}
spin_unlock(&obj->lock);
if (!no_cookie && (keylen > 0 || auxlen > 0)) {
seq_printf(m, " ");
for (p = buf; keylen > 0; keylen--)
seq_printf(m, "%02x", *p++);
if (auxlen > 0) {
if (config & FSCACHE_OBJLIST_CONFIG_KEY)
seq_printf(m, ", ");
for (; auxlen > 0; auxlen--)
seq_printf(m, "%02x", *p++);
}
}
}
if (no_cookie)
seq_printf(m, "<no_cookie>\n");
else
seq_printf(m, "\n");
return 0;
}
static void fscache_objlist_config(struct fscache_objlist_data *data)
{
#ifdef CONFIG_KEYS
struct user_key_payload *confkey;
unsigned long config;
struct key *key;
const char *buf;
int len;
key = request_key(&key_type_user, "fscache:objlist", NULL);
if (IS_ERR(key))
goto no_config;
config = 0;
rcu_read_lock();
confkey = key->payload.data;
buf = confkey->data;
for (len = confkey->datalen - 1; len >= 0; len--) {
switch (buf[len]) {
case 'K': config |= FSCACHE_OBJLIST_CONFIG_KEY; break;
case 'A': config |= FSCACHE_OBJLIST_CONFIG_AUX; break;
case 'C': config |= FSCACHE_OBJLIST_CONFIG_COOKIE; break;
case 'c': config |= FSCACHE_OBJLIST_CONFIG_NOCOOKIE; break;
case 'B': config |= FSCACHE_OBJLIST_CONFIG_BUSY; break;
case 'b': config |= FSCACHE_OBJLIST_CONFIG_IDLE; break;
case 'W': config |= FSCACHE_OBJLIST_CONFIG_PENDWR; break;
case 'w': config |= FSCACHE_OBJLIST_CONFIG_NOPENDWR; break;
case 'R': config |= FSCACHE_OBJLIST_CONFIG_READS; break;
case 'r': config |= FSCACHE_OBJLIST_CONFIG_NOREADS; break;
case 'S': config |= FSCACHE_OBJLIST_CONFIG_WORK; break;
case 's': config |= FSCACHE_OBJLIST_CONFIG_NOWORK; break;
}
}
rcu_read_unlock();
key_put(key);
if (!(config & (FSCACHE_OBJLIST_CONFIG_COOKIE | FSCACHE_OBJLIST_CONFIG_NOCOOKIE)))
config |= FSCACHE_OBJLIST_CONFIG_COOKIE | FSCACHE_OBJLIST_CONFIG_NOCOOKIE;
if (!(config & (FSCACHE_OBJLIST_CONFIG_BUSY | FSCACHE_OBJLIST_CONFIG_IDLE)))
config |= FSCACHE_OBJLIST_CONFIG_BUSY | FSCACHE_OBJLIST_CONFIG_IDLE;
if (!(config & (FSCACHE_OBJLIST_CONFIG_PENDWR | FSCACHE_OBJLIST_CONFIG_NOPENDWR)))
config |= FSCACHE_OBJLIST_CONFIG_PENDWR | FSCACHE_OBJLIST_CONFIG_NOPENDWR;
if (!(config & (FSCACHE_OBJLIST_CONFIG_READS | FSCACHE_OBJLIST_CONFIG_NOREADS)))
config |= FSCACHE_OBJLIST_CONFIG_READS | FSCACHE_OBJLIST_CONFIG_NOREADS;
if (!(config & (FSCACHE_OBJLIST_CONFIG_EVENTS | FSCACHE_OBJLIST_CONFIG_NOEVENTS)))
config |= FSCACHE_OBJLIST_CONFIG_EVENTS | FSCACHE_OBJLIST_CONFIG_NOEVENTS;
if (!(config & (FSCACHE_OBJLIST_CONFIG_WORK | FSCACHE_OBJLIST_CONFIG_NOWORK)))
config |= FSCACHE_OBJLIST_CONFIG_WORK | FSCACHE_OBJLIST_CONFIG_NOWORK;
data->config = config;
return;
no_config:
#endif
data->config = ULONG_MAX;
}
static int fscache_objlist_open(struct inode *inode, struct file *file)
{
struct fscache_objlist_data *data;
struct seq_file *m;
int ret;
ret = seq_open(file, &fscache_objlist_ops);
if (ret < 0)
return ret;
m = file->private_data;
data = kmalloc(sizeof(struct fscache_objlist_data), GFP_KERNEL);
if (!data) {
seq_release(inode, file);
return -ENOMEM;
}
fscache_objlist_config(data);
m->private = data;
return 0;
}
static int fscache_objlist_release(struct inode *inode, struct file *file)
{
struct seq_file *m = file->private_data;
kfree(m->private);
m->private = NULL;
return seq_release(inode, file);
}
