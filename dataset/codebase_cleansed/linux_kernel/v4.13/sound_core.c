static inline int init_oss_soundcore(void) { return 0; }
static inline void cleanup_oss_soundcore(void) { }
static char *sound_devnode(struct device *dev, umode_t *mode)
{
if (MAJOR(dev->devt) == SOUND_MAJOR)
return NULL;
return kasprintf(GFP_KERNEL, "snd/%s", dev_name(dev));
}
static int __init init_soundcore(void)
{
int rc;
rc = init_oss_soundcore();
if (rc)
return rc;
sound_class = class_create(THIS_MODULE, "sound");
if (IS_ERR(sound_class)) {
cleanup_oss_soundcore();
return PTR_ERR(sound_class);
}
sound_class->devnode = sound_devnode;
return 0;
}
static void __exit cleanup_soundcore(void)
{
cleanup_oss_soundcore();
class_destroy(sound_class);
}
static int __sound_insert_unit(struct sound_unit * s, struct sound_unit **list, const struct file_operations *fops, int index, int low, int top)
{
int n=low;
if (index < 0) {
while (*list && (*list)->unit_minor<n)
list=&((*list)->next);
while(n<top)
{
if(*list==NULL || (*list)->unit_minor>n)
break;
list=&((*list)->next);
n+=SOUND_STEP;
}
if(n>=top)
return -ENOENT;
} else {
n = low+(index*16);
while (*list) {
if ((*list)->unit_minor==n)
return -EBUSY;
if ((*list)->unit_minor>n)
break;
list=&((*list)->next);
}
}
s->unit_minor=n;
s->unit_fops=fops;
s->next=*list;
*list=s;
return n;
}
static struct sound_unit *__sound_remove_unit(struct sound_unit **list, int unit)
{
while(*list)
{
struct sound_unit *p=*list;
if(p->unit_minor==unit)
{
*list=p->next;
return p;
}
list=&(p->next);
}
printk(KERN_ERR "Sound device %d went missing!\n", unit);
return NULL;
}
static int sound_insert_unit(struct sound_unit **list, const struct file_operations *fops, int index, int low, int top, const char *name, umode_t mode, struct device *dev)
{
struct sound_unit *s = kmalloc(sizeof(*s), GFP_KERNEL);
int r;
if (!s)
return -ENOMEM;
spin_lock(&sound_loader_lock);
retry:
r = __sound_insert_unit(s, list, fops, index, low, top);
spin_unlock(&sound_loader_lock);
if (r < 0)
goto fail;
else if (r < SOUND_STEP)
sprintf(s->name, "sound/%s", name);
else
sprintf(s->name, "sound/%s%d", name, r / SOUND_STEP);
if (!preclaim_oss) {
r = __register_chrdev(SOUND_MAJOR, s->unit_minor, 1, s->name,
&soundcore_fops);
if (r < 0) {
spin_lock(&sound_loader_lock);
__sound_remove_unit(list, s->unit_minor);
if (index < 0) {
low = s->unit_minor + SOUND_STEP;
goto retry;
}
spin_unlock(&sound_loader_lock);
return -EBUSY;
}
}
device_create(sound_class, dev, MKDEV(SOUND_MAJOR, s->unit_minor),
NULL, "%s", s->name+6);
return s->unit_minor;
fail:
kfree(s);
return r;
}
static void sound_remove_unit(struct sound_unit **list, int unit)
{
struct sound_unit *p;
spin_lock(&sound_loader_lock);
p = __sound_remove_unit(list, unit);
spin_unlock(&sound_loader_lock);
if (p) {
if (!preclaim_oss)
__unregister_chrdev(SOUND_MAJOR, p->unit_minor, 1,
p->name);
device_destroy(sound_class, MKDEV(SOUND_MAJOR, p->unit_minor));
kfree(p);
}
}
int register_sound_special_device(const struct file_operations *fops, int unit,
struct device *dev)
{
const int chain = unit % SOUND_STEP;
int max_unit = 256;
const char *name;
char _name[16];
switch (chain) {
case 0:
name = "mixer";
break;
case 1:
name = "sequencer";
if (unit >= SOUND_STEP)
goto __unknown;
max_unit = unit + 1;
break;
case 2:
name = "midi";
break;
case 3:
name = "dsp";
break;
case 4:
name = "audio";
break;
case 5:
name = "dspW";
break;
case 8:
name = "sequencer2";
if (unit >= SOUND_STEP)
goto __unknown;
max_unit = unit + 1;
break;
case 9:
name = "dmmidi";
break;
case 10:
name = "dmfm";
break;
case 12:
name = "adsp";
break;
case 13:
name = "amidi";
break;
case 14:
name = "admmidi";
break;
default:
{
__unknown:
sprintf(_name, "unknown%d", chain);
if (unit >= SOUND_STEP)
strcat(_name, "-");
name = _name;
}
break;
}
return sound_insert_unit(&chains[chain], fops, -1, unit, max_unit,
name, S_IRUSR | S_IWUSR, dev);
}
int register_sound_special(const struct file_operations *fops, int unit)
{
return register_sound_special_device(fops, unit, NULL);
}
int register_sound_mixer(const struct file_operations *fops, int dev)
{
return sound_insert_unit(&chains[0], fops, dev, 0, 128,
"mixer", S_IRUSR | S_IWUSR, NULL);
}
int register_sound_midi(const struct file_operations *fops, int dev)
{
return sound_insert_unit(&chains[2], fops, dev, 2, 130,
"midi", S_IRUSR | S_IWUSR, NULL);
}
int register_sound_dsp(const struct file_operations *fops, int dev)
{
return sound_insert_unit(&chains[3], fops, dev, 3, 131,
"dsp", S_IWUSR | S_IRUSR, NULL);
}
void unregister_sound_special(int unit)
{
sound_remove_unit(&chains[unit % SOUND_STEP], unit);
}
void unregister_sound_mixer(int unit)
{
sound_remove_unit(&chains[0], unit);
}
void unregister_sound_midi(int unit)
{
sound_remove_unit(&chains[2], unit);
}
void unregister_sound_dsp(int unit)
{
sound_remove_unit(&chains[3], unit);
}
static struct sound_unit *__look_for_unit(int chain, int unit)
{
struct sound_unit *s;
s=chains[chain];
while(s && s->unit_minor <= unit)
{
if(s->unit_minor==unit)
return s;
s=s->next;
}
return NULL;
}
static int soundcore_open(struct inode *inode, struct file *file)
{
int chain;
int unit = iminor(inode);
struct sound_unit *s;
const struct file_operations *new_fops = NULL;
chain=unit&0x0F;
if(chain==4 || chain==5)
{
unit&=0xF0;
unit|=3;
chain=3;
}
spin_lock(&sound_loader_lock);
s = __look_for_unit(chain, unit);
if (s)
new_fops = fops_get(s->unit_fops);
if (preclaim_oss && !new_fops) {
spin_unlock(&sound_loader_lock);
request_module("sound-slot-%i", unit>>4);
request_module("sound-service-%i-%i", unit>>4, chain);
if (request_module("char-major-%d-%d", SOUND_MAJOR, unit) > 0)
request_module("char-major-%d", SOUND_MAJOR);
spin_lock(&sound_loader_lock);
s = __look_for_unit(chain, unit);
if (s)
new_fops = fops_get(s->unit_fops);
}
spin_unlock(&sound_loader_lock);
if (new_fops) {
int err = 0;
replace_fops(file, new_fops);
if (file->f_op->open)
err = file->f_op->open(inode,file);
return err;
}
return -ENODEV;
}
static void cleanup_oss_soundcore(void)
{
unregister_chrdev(SOUND_MAJOR, "sound");
}
static int __init init_oss_soundcore(void)
{
if (preclaim_oss &&
register_chrdev(SOUND_MAJOR, "sound", &soundcore_fops) < 0) {
printk(KERN_ERR "soundcore: sound device already in use.\n");
return -EBUSY;
}
return 0;
}
