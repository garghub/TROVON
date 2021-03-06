static void snd_seq_device_info(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct ops_list *ops;
mutex_lock(&ops_mutex);
list_for_each_entry(ops, &opslist, list) {
snd_iprintf(buffer, "snd-%s%s%s%s,%d\n",
ops->id,
ops->driver & DRIVER_LOADED ? ",loaded" : (ops->driver == DRIVER_EMPTY ? ",empty" : ""),
ops->driver & DRIVER_REQUESTED ? ",requested" : "",
ops->driver & DRIVER_LOCKED ? ",locked" : "",
ops->num_devices);
}
mutex_unlock(&ops_mutex);
}
void snd_seq_autoload_lock(void)
{
snd_seq_in_init++;
}
void snd_seq_autoload_unlock(void)
{
snd_seq_in_init--;
}
void snd_seq_device_load_drivers(void)
{
#ifdef CONFIG_MODULES
struct ops_list *ops;
if (snd_seq_in_init)
return;
mutex_lock(&ops_mutex);
list_for_each_entry(ops, &opslist, list) {
if (! (ops->driver & DRIVER_LOADED) &&
! (ops->driver & DRIVER_REQUESTED)) {
ops->used++;
mutex_unlock(&ops_mutex);
ops->driver |= DRIVER_REQUESTED;
request_module("snd-%s", ops->id);
mutex_lock(&ops_mutex);
ops->used--;
}
}
mutex_unlock(&ops_mutex);
#endif
}
int snd_seq_device_new(struct snd_card *card, int device, char *id, int argsize,
struct snd_seq_device **result)
{
struct snd_seq_device *dev;
struct ops_list *ops;
int err;
static struct snd_device_ops dops = {
.dev_free = snd_seq_device_dev_free,
.dev_register = snd_seq_device_dev_register,
.dev_disconnect = snd_seq_device_dev_disconnect,
};
if (result)
*result = NULL;
if (snd_BUG_ON(!id))
return -EINVAL;
ops = find_driver(id, 1);
if (ops == NULL)
return -ENOMEM;
dev = kzalloc(sizeof(*dev)*2 + argsize, GFP_KERNEL);
if (dev == NULL) {
unlock_driver(ops);
return -ENOMEM;
}
dev->card = card;
dev->device = device;
strlcpy(dev->id, id, sizeof(dev->id));
dev->argsize = argsize;
dev->status = SNDRV_SEQ_DEVICE_FREE;
mutex_lock(&ops->reg_mutex);
list_add_tail(&dev->list, &ops->dev_list);
ops->num_devices++;
mutex_unlock(&ops->reg_mutex);
unlock_driver(ops);
if ((err = snd_device_new(card, SNDRV_DEV_SEQUENCER, dev, &dops)) < 0) {
snd_seq_device_free(dev);
return err;
}
if (result)
*result = dev;
return 0;
}
static int snd_seq_device_free(struct snd_seq_device *dev)
{
struct ops_list *ops;
if (snd_BUG_ON(!dev))
return -EINVAL;
ops = find_driver(dev->id, 0);
if (ops == NULL)
return -ENXIO;
mutex_lock(&ops->reg_mutex);
list_del(&dev->list);
ops->num_devices--;
mutex_unlock(&ops->reg_mutex);
free_device(dev, ops);
if (dev->private_free)
dev->private_free(dev);
kfree(dev);
unlock_driver(ops);
return 0;
}
static int snd_seq_device_dev_free(struct snd_device *device)
{
struct snd_seq_device *dev = device->device_data;
return snd_seq_device_free(dev);
}
static int snd_seq_device_dev_register(struct snd_device *device)
{
struct snd_seq_device *dev = device->device_data;
struct ops_list *ops;
ops = find_driver(dev->id, 0);
if (ops == NULL)
return -ENOENT;
if (ops->driver & DRIVER_LOADED)
init_device(dev, ops);
unlock_driver(ops);
return 0;
}
static int snd_seq_device_dev_disconnect(struct snd_device *device)
{
struct snd_seq_device *dev = device->device_data;
struct ops_list *ops;
ops = find_driver(dev->id, 0);
if (ops == NULL)
return -ENOENT;
free_device(dev, ops);
unlock_driver(ops);
return 0;
}
int snd_seq_device_register_driver(char *id, struct snd_seq_dev_ops *entry,
int argsize)
{
struct ops_list *ops;
struct snd_seq_device *dev;
if (id == NULL || entry == NULL ||
entry->init_device == NULL || entry->free_device == NULL)
return -EINVAL;
snd_seq_autoload_lock();
ops = find_driver(id, 1);
if (ops == NULL) {
snd_seq_autoload_unlock();
return -ENOMEM;
}
if (ops->driver & DRIVER_LOADED) {
snd_printk(KERN_WARNING "driver_register: driver '%s' already exists\n", id);
unlock_driver(ops);
snd_seq_autoload_unlock();
return -EBUSY;
}
mutex_lock(&ops->reg_mutex);
ops->ops = *entry;
ops->driver |= DRIVER_LOADED;
ops->argsize = argsize;
list_for_each_entry(dev, &ops->dev_list, list) {
init_device(dev, ops);
}
mutex_unlock(&ops->reg_mutex);
unlock_driver(ops);
snd_seq_autoload_unlock();
return 0;
}
static struct ops_list * create_driver(char *id)
{
struct ops_list *ops;
ops = kzalloc(sizeof(*ops), GFP_KERNEL);
if (ops == NULL)
return ops;
strlcpy(ops->id, id, sizeof(ops->id));
mutex_init(&ops->reg_mutex);
lockdep_set_class(&ops->reg_mutex, (struct lock_class_key *)id);
ops->driver = DRIVER_EMPTY;
INIT_LIST_HEAD(&ops->dev_list);
ops->used = 1;
mutex_lock(&ops_mutex);
list_add_tail(&ops->list, &opslist);
num_ops++;
mutex_unlock(&ops_mutex);
return ops;
}
int snd_seq_device_unregister_driver(char *id)
{
struct ops_list *ops;
struct snd_seq_device *dev;
ops = find_driver(id, 0);
if (ops == NULL)
return -ENXIO;
if (! (ops->driver & DRIVER_LOADED) ||
(ops->driver & DRIVER_LOCKED)) {
snd_printk(KERN_ERR "driver_unregister: cannot unload driver '%s': status=%x\n",
id, ops->driver);
unlock_driver(ops);
return -EBUSY;
}
mutex_lock(&ops->reg_mutex);
ops->driver |= DRIVER_LOCKED;
list_for_each_entry(dev, &ops->dev_list, list) {
free_device(dev, ops);
}
ops->driver = 0;
if (ops->num_init_devices > 0)
snd_printk(KERN_ERR "free_driver: init_devices > 0!! (%d)\n",
ops->num_init_devices);
mutex_unlock(&ops->reg_mutex);
unlock_driver(ops);
remove_drivers();
return 0;
}
static void remove_drivers(void)
{
struct list_head *head;
mutex_lock(&ops_mutex);
head = opslist.next;
while (head != &opslist) {
struct ops_list *ops = list_entry(head, struct ops_list, list);
if (! (ops->driver & DRIVER_LOADED) &&
ops->used == 0 && ops->num_devices == 0) {
head = head->next;
list_del(&ops->list);
kfree(ops);
num_ops--;
} else
head = head->next;
}
mutex_unlock(&ops_mutex);
}
static int init_device(struct snd_seq_device *dev, struct ops_list *ops)
{
if (! (ops->driver & DRIVER_LOADED))
return 0;
if (dev->status != SNDRV_SEQ_DEVICE_FREE)
return 0;
if (ops->argsize != dev->argsize) {
snd_printk(KERN_ERR "incompatible device '%s' for plug-in '%s' (%d %d)\n",
dev->name, ops->id, ops->argsize, dev->argsize);
return -EINVAL;
}
if (ops->ops.init_device(dev) >= 0) {
dev->status = SNDRV_SEQ_DEVICE_REGISTERED;
ops->num_init_devices++;
} else {
snd_printk(KERN_ERR "init_device failed: %s: %s\n",
dev->name, dev->id);
}
return 0;
}
static int free_device(struct snd_seq_device *dev, struct ops_list *ops)
{
int result;
if (! (ops->driver & DRIVER_LOADED))
return 0;
if (dev->status != SNDRV_SEQ_DEVICE_REGISTERED)
return 0;
if (ops->argsize != dev->argsize) {
snd_printk(KERN_ERR "incompatible device '%s' for plug-in '%s' (%d %d)\n",
dev->name, ops->id, ops->argsize, dev->argsize);
return -EINVAL;
}
if ((result = ops->ops.free_device(dev)) >= 0 || result == -ENXIO) {
dev->status = SNDRV_SEQ_DEVICE_FREE;
dev->driver_data = NULL;
ops->num_init_devices--;
} else {
snd_printk(KERN_ERR "free_device failed: %s: %s\n",
dev->name, dev->id);
}
return 0;
}
static struct ops_list * find_driver(char *id, int create_if_empty)
{
struct ops_list *ops;
mutex_lock(&ops_mutex);
list_for_each_entry(ops, &opslist, list) {
if (strcmp(ops->id, id) == 0) {
ops->used++;
mutex_unlock(&ops_mutex);
return ops;
}
}
mutex_unlock(&ops_mutex);
if (create_if_empty)
return create_driver(id);
return NULL;
}
static void unlock_driver(struct ops_list *ops)
{
mutex_lock(&ops_mutex);
ops->used--;
mutex_unlock(&ops_mutex);
}
static int __init alsa_seq_device_init(void)
{
#ifdef CONFIG_PROC_FS
info_entry = snd_info_create_module_entry(THIS_MODULE, "drivers",
snd_seq_root);
if (info_entry == NULL)
return -ENOMEM;
info_entry->content = SNDRV_INFO_CONTENT_TEXT;
info_entry->c.text.read = snd_seq_device_info;
if (snd_info_register(info_entry) < 0) {
snd_info_free_entry(info_entry);
return -ENOMEM;
}
#endif
return 0;
}
static void __exit alsa_seq_device_exit(void)
{
remove_drivers();
#ifdef CONFIG_PROC_FS
snd_info_free_entry(info_entry);
#endif
if (num_ops)
snd_printk(KERN_ERR "drivers not released (%d)\n", num_ops);
}
