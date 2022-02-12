static unsigned int get_time_pit(void)
{
unsigned long flags;
unsigned int count;
raw_spin_lock_irqsave(&i8253_lock, flags);
outb_p(0x00, 0x43);
count = inb_p(0x40);
count |= inb_p(0x40) << 8;
raw_spin_unlock_irqrestore(&i8253_lock, flags);
return count;
}
static int gameport_measure_speed(struct gameport *gameport)
{
unsigned int i, t, tx;
u64 t1, t2, t3;
unsigned long flags;
if (gameport_open(gameport, NULL, GAMEPORT_MODE_RAW))
return 0;
tx = ~0;
for (i = 0; i < 50; i++) {
local_irq_save(flags);
t1 = ktime_get_ns();
for (t = 0; t < 50; t++)
gameport_read(gameport);
t2 = ktime_get_ns();
t3 = ktime_get_ns();
local_irq_restore(flags);
udelay(i * 10);
t = (t2 - t1) - (t3 - t2);
if (t < tx)
tx = t;
}
gameport_close(gameport);
t = 1000000 * 50;
if (tx)
t /= tx;
return t;
}
static int old_gameport_measure_speed(struct gameport *gameport)
{
#if defined(__i386__)
unsigned int i, t, t1, t2, t3, tx;
unsigned long flags;
if (gameport_open(gameport, NULL, GAMEPORT_MODE_RAW))
return 0;
tx = 1 << 30;
for(i = 0; i < 50; i++) {
local_irq_save(flags);
GET_TIME(t1);
for (t = 0; t < 50; t++) gameport_read(gameport);
GET_TIME(t2);
GET_TIME(t3);
local_irq_restore(flags);
udelay(i * 10);
if ((t = DELTA(t2,t1) - DELTA(t3,t2)) < tx) tx = t;
}
gameport_close(gameport);
return 59659 / (tx < 1 ? 1 : tx);
#elif defined (__x86_64__)
unsigned int i, t;
unsigned long tx, t1, t2, flags;
if (gameport_open(gameport, NULL, GAMEPORT_MODE_RAW))
return 0;
tx = 1 << 30;
for(i = 0; i < 50; i++) {
local_irq_save(flags);
rdtscl(t1);
for (t = 0; t < 50; t++) gameport_read(gameport);
rdtscl(t2);
local_irq_restore(flags);
udelay(i * 10);
if (t2 - t1 < tx) tx = t2 - t1;
}
gameport_close(gameport);
return (this_cpu_read(cpu_info.loops_per_jiffy) *
(unsigned long)HZ / (1000 / 50)) / (tx < 1 ? 1 : tx);
#else
unsigned int j, t = 0;
if (gameport_open(gameport, NULL, GAMEPORT_MODE_RAW))
return 0;
j = jiffies; while (j == jiffies);
j = jiffies; while (j == jiffies) { t++; gameport_read(gameport); }
gameport_close(gameport);
return t * HZ / 1000;
#endif
}
void gameport_start_polling(struct gameport *gameport)
{
spin_lock(&gameport->timer_lock);
if (!gameport->poll_cnt++) {
BUG_ON(!gameport->poll_handler);
BUG_ON(!gameport->poll_interval);
mod_timer(&gameport->poll_timer, jiffies + msecs_to_jiffies(gameport->poll_interval));
}
spin_unlock(&gameport->timer_lock);
}
void gameport_stop_polling(struct gameport *gameport)
{
spin_lock(&gameport->timer_lock);
if (!--gameport->poll_cnt)
del_timer(&gameport->poll_timer);
spin_unlock(&gameport->timer_lock);
}
static void gameport_run_poll_handler(unsigned long d)
{
struct gameport *gameport = (struct gameport *)d;
gameport->poll_handler(gameport);
if (gameport->poll_cnt)
mod_timer(&gameport->poll_timer, jiffies + msecs_to_jiffies(gameport->poll_interval));
}
static int gameport_bind_driver(struct gameport *gameport, struct gameport_driver *drv)
{
int error;
gameport->dev.driver = &drv->driver;
if (drv->connect(gameport, drv)) {
gameport->dev.driver = NULL;
return -ENODEV;
}
error = device_bind_driver(&gameport->dev);
if (error) {
dev_warn(&gameport->dev,
"device_bind_driver() failed for %s (%s) and %s, error: %d\n",
gameport->phys, gameport->name,
drv->description, error);
drv->disconnect(gameport);
gameport->dev.driver = NULL;
return error;
}
return 0;
}
static void gameport_find_driver(struct gameport *gameport)
{
int error;
error = device_attach(&gameport->dev);
if (error < 0)
dev_warn(&gameport->dev,
"device_attach() failed for %s (%s), error: %d\n",
gameport->phys, gameport->name, error);
}
static struct gameport_event *gameport_get_event(void)
{
struct gameport_event *event = NULL;
unsigned long flags;
spin_lock_irqsave(&gameport_event_lock, flags);
if (!list_empty(&gameport_event_list)) {
event = list_first_entry(&gameport_event_list,
struct gameport_event, node);
list_del_init(&event->node);
}
spin_unlock_irqrestore(&gameport_event_lock, flags);
return event;
}
static void gameport_free_event(struct gameport_event *event)
{
module_put(event->owner);
kfree(event);
}
static void gameport_remove_duplicate_events(struct gameport_event *event)
{
struct gameport_event *e, *next;
unsigned long flags;
spin_lock_irqsave(&gameport_event_lock, flags);
list_for_each_entry_safe(e, next, &gameport_event_list, node) {
if (event->object == e->object) {
if (event->type != e->type)
break;
list_del_init(&e->node);
gameport_free_event(e);
}
}
spin_unlock_irqrestore(&gameport_event_lock, flags);
}
static void gameport_handle_events(struct work_struct *work)
{
struct gameport_event *event;
mutex_lock(&gameport_mutex);
if ((event = gameport_get_event())) {
switch (event->type) {
case GAMEPORT_REGISTER_PORT:
gameport_add_port(event->object);
break;
case GAMEPORT_ATTACH_DRIVER:
gameport_attach_driver(event->object);
break;
}
gameport_remove_duplicate_events(event);
gameport_free_event(event);
}
mutex_unlock(&gameport_mutex);
}
static int gameport_queue_event(void *object, struct module *owner,
enum gameport_event_type event_type)
{
unsigned long flags;
struct gameport_event *event;
int retval = 0;
spin_lock_irqsave(&gameport_event_lock, flags);
list_for_each_entry_reverse(event, &gameport_event_list, node) {
if (event->object == object) {
if (event->type == event_type)
goto out;
break;
}
}
event = kmalloc(sizeof(struct gameport_event), GFP_ATOMIC);
if (!event) {
pr_err("Not enough memory to queue event %d\n", event_type);
retval = -ENOMEM;
goto out;
}
if (!try_module_get(owner)) {
pr_warning("Can't get module reference, dropping event %d\n",
event_type);
kfree(event);
retval = -EINVAL;
goto out;
}
event->type = event_type;
event->object = object;
event->owner = owner;
list_add_tail(&event->node, &gameport_event_list);
queue_work(system_long_wq, &gameport_event_work);
out:
spin_unlock_irqrestore(&gameport_event_lock, flags);
return retval;
}
static void gameport_remove_pending_events(void *object)
{
struct gameport_event *event, *next;
unsigned long flags;
spin_lock_irqsave(&gameport_event_lock, flags);
list_for_each_entry_safe(event, next, &gameport_event_list, node) {
if (event->object == object) {
list_del_init(&event->node);
gameport_free_event(event);
}
}
spin_unlock_irqrestore(&gameport_event_lock, flags);
}
static struct gameport *gameport_get_pending_child(struct gameport *parent)
{
struct gameport_event *event;
struct gameport *gameport, *child = NULL;
unsigned long flags;
spin_lock_irqsave(&gameport_event_lock, flags);
list_for_each_entry(event, &gameport_event_list, node) {
if (event->type == GAMEPORT_REGISTER_PORT) {
gameport = event->object;
if (gameport->parent == parent) {
child = gameport;
break;
}
}
}
spin_unlock_irqrestore(&gameport_event_lock, flags);
return child;
}
static ssize_t gameport_description_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct gameport *gameport = to_gameport_port(dev);
return sprintf(buf, "%s\n", gameport->name);
}
static ssize_t drvctl_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct gameport *gameport = to_gameport_port(dev);
struct device_driver *drv;
int error;
error = mutex_lock_interruptible(&gameport_mutex);
if (error)
return error;
if (!strncmp(buf, "none", count)) {
gameport_disconnect_port(gameport);
} else if (!strncmp(buf, "reconnect", count)) {
gameport_reconnect_port(gameport);
} else if (!strncmp(buf, "rescan", count)) {
gameport_disconnect_port(gameport);
gameport_find_driver(gameport);
} else if ((drv = driver_find(buf, &gameport_bus)) != NULL) {
gameport_disconnect_port(gameport);
error = gameport_bind_driver(gameport, to_gameport_driver(drv));
} else {
error = -EINVAL;
}
mutex_unlock(&gameport_mutex);
return error ? error : count;
}
static void gameport_release_port(struct device *dev)
{
struct gameport *gameport = to_gameport_port(dev);
kfree(gameport);
module_put(THIS_MODULE);
}
void gameport_set_phys(struct gameport *gameport, const char *fmt, ...)
{
va_list args;
va_start(args, fmt);
vsnprintf(gameport->phys, sizeof(gameport->phys), fmt, args);
va_end(args);
}
static void gameport_init_port(struct gameport *gameport)
{
static atomic_t gameport_no = ATOMIC_INIT(-1);
__module_get(THIS_MODULE);
mutex_init(&gameport->drv_mutex);
device_initialize(&gameport->dev);
dev_set_name(&gameport->dev, "gameport%lu",
(unsigned long)atomic_inc_return(&gameport_no));
gameport->dev.bus = &gameport_bus;
gameport->dev.release = gameport_release_port;
if (gameport->parent)
gameport->dev.parent = &gameport->parent->dev;
INIT_LIST_HEAD(&gameport->node);
spin_lock_init(&gameport->timer_lock);
init_timer(&gameport->poll_timer);
gameport->poll_timer.function = gameport_run_poll_handler;
gameport->poll_timer.data = (unsigned long)gameport;
}
static void gameport_add_port(struct gameport *gameport)
{
int error;
if (gameport->parent)
gameport->parent->child = gameport;
gameport->speed = use_ktime ?
gameport_measure_speed(gameport) :
old_gameport_measure_speed(gameport);
list_add_tail(&gameport->node, &gameport_list);
if (gameport->io)
dev_info(&gameport->dev, "%s is %s, io %#x, speed %dkHz\n",
gameport->name, gameport->phys, gameport->io, gameport->speed);
else
dev_info(&gameport->dev, "%s is %s, speed %dkHz\n",
gameport->name, gameport->phys, gameport->speed);
error = device_add(&gameport->dev);
if (error)
dev_err(&gameport->dev,
"device_add() failed for %s (%s), error: %d\n",
gameport->phys, gameport->name, error);
}
static void gameport_destroy_port(struct gameport *gameport)
{
struct gameport *child;
child = gameport_get_pending_child(gameport);
if (child) {
gameport_remove_pending_events(child);
put_device(&child->dev);
}
if (gameport->parent) {
gameport->parent->child = NULL;
gameport->parent = NULL;
}
if (device_is_registered(&gameport->dev))
device_del(&gameport->dev);
list_del_init(&gameport->node);
gameport_remove_pending_events(gameport);
put_device(&gameport->dev);
}
static void gameport_reconnect_port(struct gameport *gameport)
{
do {
if (!gameport->drv || !gameport->drv->reconnect || gameport->drv->reconnect(gameport)) {
gameport_disconnect_port(gameport);
gameport_find_driver(gameport);
break;
}
gameport = gameport->child;
} while (gameport);
}
static void gameport_disconnect_port(struct gameport *gameport)
{
struct gameport *s, *parent;
if (gameport->child) {
for (s = gameport; s->child; s = s->child)
;
do {
parent = s->parent;
device_release_driver(&s->dev);
gameport_destroy_port(s);
} while ((s = parent) != gameport);
}
device_release_driver(&gameport->dev);
}
void __gameport_register_port(struct gameport *gameport, struct module *owner)
{
gameport_init_port(gameport);
gameport_queue_event(gameport, owner, GAMEPORT_REGISTER_PORT);
}
void gameport_unregister_port(struct gameport *gameport)
{
mutex_lock(&gameport_mutex);
gameport_disconnect_port(gameport);
gameport_destroy_port(gameport);
mutex_unlock(&gameport_mutex);
}
static ssize_t description_show(struct device_driver *drv, char *buf)
{
struct gameport_driver *driver = to_gameport_driver(drv);
return sprintf(buf, "%s\n", driver->description ? driver->description : "(none)");
}
static int gameport_driver_probe(struct device *dev)
{
struct gameport *gameport = to_gameport_port(dev);
struct gameport_driver *drv = to_gameport_driver(dev->driver);
drv->connect(gameport, drv);
return gameport->drv ? 0 : -ENODEV;
}
static int gameport_driver_remove(struct device *dev)
{
struct gameport *gameport = to_gameport_port(dev);
struct gameport_driver *drv = to_gameport_driver(dev->driver);
drv->disconnect(gameport);
return 0;
}
static void gameport_attach_driver(struct gameport_driver *drv)
{
int error;
error = driver_attach(&drv->driver);
if (error)
pr_err("driver_attach() failed for %s, error: %d\n",
drv->driver.name, error);
}
int __gameport_register_driver(struct gameport_driver *drv, struct module *owner,
const char *mod_name)
{
int error;
drv->driver.bus = &gameport_bus;
drv->driver.owner = owner;
drv->driver.mod_name = mod_name;
drv->ignore = true;
error = driver_register(&drv->driver);
if (error) {
pr_err("driver_register() failed for %s, error: %d\n",
drv->driver.name, error);
return error;
}
drv->ignore = false;
error = gameport_queue_event(drv, NULL, GAMEPORT_ATTACH_DRIVER);
if (error) {
driver_unregister(&drv->driver);
return error;
}
return 0;
}
void gameport_unregister_driver(struct gameport_driver *drv)
{
struct gameport *gameport;
mutex_lock(&gameport_mutex);
drv->ignore = true;
gameport_remove_pending_events(drv);
start_over:
list_for_each_entry(gameport, &gameport_list, node) {
if (gameport->drv == drv) {
gameport_disconnect_port(gameport);
gameport_find_driver(gameport);
goto start_over;
}
}
driver_unregister(&drv->driver);
mutex_unlock(&gameport_mutex);
}
static int gameport_bus_match(struct device *dev, struct device_driver *drv)
{
struct gameport_driver *gameport_drv = to_gameport_driver(drv);
return !gameport_drv->ignore;
}
static void gameport_set_drv(struct gameport *gameport, struct gameport_driver *drv)
{
mutex_lock(&gameport->drv_mutex);
gameport->drv = drv;
mutex_unlock(&gameport->drv_mutex);
}
int gameport_open(struct gameport *gameport, struct gameport_driver *drv, int mode)
{
if (gameport->open) {
if (gameport->open(gameport, mode)) {
return -1;
}
} else {
if (mode != GAMEPORT_MODE_RAW)
return -1;
}
gameport_set_drv(gameport, drv);
return 0;
}
void gameport_close(struct gameport *gameport)
{
del_timer_sync(&gameport->poll_timer);
gameport->poll_handler = NULL;
gameport->poll_interval = 0;
gameport_set_drv(gameport, NULL);
if (gameport->close)
gameport->close(gameport);
}
static int __init gameport_init(void)
{
int error;
error = bus_register(&gameport_bus);
if (error) {
pr_err("failed to register gameport bus, error: %d\n", error);
return error;
}
return 0;
}
static void __exit gameport_exit(void)
{
bus_unregister(&gameport_bus);
cancel_work_sync(&gameport_event_work);
}
