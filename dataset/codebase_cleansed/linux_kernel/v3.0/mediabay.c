static u8
ohare_mb_content(struct media_bay_info *bay)
{
return (MB_IN32(bay, OHARE_MBCR) >> 12) & 7;
}
static u8
heathrow_mb_content(struct media_bay_info *bay)
{
return (MB_IN32(bay, HEATHROW_MBCR) >> 12) & 7;
}
static u8
keylargo_mb_content(struct media_bay_info *bay)
{
int new_gpio;
new_gpio = MB_IN8(bay, KL_GPIO_MEDIABAY_IRQ) & KEYLARGO_GPIO_INPUT_DATA;
if (new_gpio) {
bay->cached_gpio = new_gpio;
return MB_NO;
} else if (bay->cached_gpio != new_gpio) {
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_ENABLE);
(void)MB_IN32(bay, KEYLARGO_MBCR);
udelay(5);
MB_BIC(bay, KEYLARGO_MBCR, 0x0000000F);
(void)MB_IN32(bay, KEYLARGO_MBCR);
udelay(5);
bay->cached_gpio = new_gpio;
}
return (MB_IN32(bay, KEYLARGO_MBCR) >> 4) & 7;
}
static void
ohare_mb_power(struct media_bay_info* bay, int on_off)
{
if (on_off) {
MB_BIC(bay, OHARE_FCR, OH_BAY_RESET_N);
MB_BIC(bay, OHARE_FCR, OH_BAY_POWER_N);
} else {
MB_BIC(bay, OHARE_FCR, OH_BAY_DEV_MASK);
MB_BIC(bay, OHARE_FCR, OH_FLOPPY_ENABLE);
MB_BIS(bay, OHARE_FCR, OH_BAY_POWER_N);
MB_BIS(bay, OHARE_FCR, OH_BAY_RESET_N);
MB_BIS(bay, OHARE_FCR, OH_IDE1_RESET_N);
}
MB_BIC(bay, OHARE_MBCR, 0x00000F00);
}
static void
heathrow_mb_power(struct media_bay_info* bay, int on_off)
{
if (on_off) {
MB_BIC(bay, HEATHROW_FCR, HRW_BAY_RESET_N);
MB_BIC(bay, HEATHROW_FCR, HRW_BAY_POWER_N);
} else {
MB_BIC(bay, HEATHROW_FCR, HRW_BAY_DEV_MASK);
MB_BIC(bay, HEATHROW_FCR, HRW_SWIM_ENABLE);
MB_BIS(bay, HEATHROW_FCR, HRW_BAY_POWER_N);
MB_BIS(bay, HEATHROW_FCR, HRW_BAY_RESET_N);
MB_BIS(bay, HEATHROW_FCR, HRW_IDE1_RESET_N);
}
MB_BIC(bay, HEATHROW_MBCR, 0x00000F00);
}
static void
keylargo_mb_power(struct media_bay_info* bay, int on_off)
{
if (on_off) {
MB_BIC(bay, KEYLARGO_MBCR, KL_MBCR_MB0_DEV_RESET);
MB_BIC(bay, KEYLARGO_MBCR, KL_MBCR_MB0_DEV_POWER);
} else {
MB_BIC(bay, KEYLARGO_MBCR, KL_MBCR_MB0_DEV_MASK);
MB_BIC(bay, KEYLARGO_FCR1, KL1_EIDE0_ENABLE);
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_DEV_POWER);
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_DEV_RESET);
MB_BIS(bay, KEYLARGO_FCR1, KL1_EIDE0_RESET_N);
}
MB_BIC(bay, KEYLARGO_MBCR, 0x0000000F);
}
static int
ohare_mb_setup_bus(struct media_bay_info* bay, u8 device_id)
{
switch(device_id) {
case MB_FD:
case MB_FD1:
MB_BIS(bay, OHARE_FCR, OH_BAY_FLOPPY_ENABLE);
MB_BIS(bay, OHARE_FCR, OH_FLOPPY_ENABLE);
return 0;
case MB_CD:
MB_BIC(bay, OHARE_FCR, OH_IDE1_RESET_N);
MB_BIS(bay, OHARE_FCR, OH_BAY_IDE_ENABLE);
return 0;
case MB_PCI:
MB_BIS(bay, OHARE_FCR, OH_BAY_PCI_ENABLE);
return 0;
}
return -ENODEV;
}
static int
heathrow_mb_setup_bus(struct media_bay_info* bay, u8 device_id)
{
switch(device_id) {
case MB_FD:
case MB_FD1:
MB_BIS(bay, HEATHROW_FCR, HRW_BAY_FLOPPY_ENABLE);
MB_BIS(bay, HEATHROW_FCR, HRW_SWIM_ENABLE);
return 0;
case MB_CD:
MB_BIC(bay, HEATHROW_FCR, HRW_IDE1_RESET_N);
MB_BIS(bay, HEATHROW_FCR, HRW_BAY_IDE_ENABLE);
return 0;
case MB_PCI:
MB_BIS(bay, HEATHROW_FCR, HRW_BAY_PCI_ENABLE);
return 0;
}
return -ENODEV;
}
static int
keylargo_mb_setup_bus(struct media_bay_info* bay, u8 device_id)
{
switch(device_id) {
case MB_CD:
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_IDE_ENABLE);
MB_BIC(bay, KEYLARGO_FCR1, KL1_EIDE0_RESET_N);
MB_BIS(bay, KEYLARGO_FCR1, KL1_EIDE0_ENABLE);
return 0;
case MB_PCI:
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_PCI_ENABLE);
return 0;
case MB_SOUND:
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_SOUND_ENABLE);
return 0;
}
return -ENODEV;
}
static void
ohare_mb_un_reset(struct media_bay_info* bay)
{
MB_BIS(bay, OHARE_FCR, OH_BAY_RESET_N);
}
static void keylargo_mb_init(struct media_bay_info *bay)
{
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_ENABLE);
}
static void heathrow_mb_un_reset(struct media_bay_info* bay)
{
MB_BIS(bay, HEATHROW_FCR, HRW_BAY_RESET_N);
}
static void keylargo_mb_un_reset(struct media_bay_info* bay)
{
MB_BIS(bay, KEYLARGO_MBCR, KL_MBCR_MB0_DEV_RESET);
}
static void ohare_mb_un_reset_ide(struct media_bay_info* bay)
{
MB_BIS(bay, OHARE_FCR, OH_IDE1_RESET_N);
}
static void heathrow_mb_un_reset_ide(struct media_bay_info* bay)
{
MB_BIS(bay, HEATHROW_FCR, HRW_IDE1_RESET_N);
}
static void keylargo_mb_un_reset_ide(struct media_bay_info* bay)
{
MB_BIS(bay, KEYLARGO_FCR1, KL1_EIDE0_RESET_N);
}
static inline void set_mb_power(struct media_bay_info* bay, int onoff)
{
if (onoff) {
bay->ops->power(bay, 1);
bay->state = mb_powering_up;
pr_debug("mediabay%d: powering up\n", bay->index);
} else {
bay->ops->power(bay, 0);
bay->state = mb_powering_down;
pr_debug("mediabay%d: powering down\n", bay->index);
}
bay->timer = msecs_to_jiffies(MB_POWER_DELAY);
}
static void poll_media_bay(struct media_bay_info* bay)
{
int id = bay->ops->content(bay);
static char *mb_content_types[] = {
"a floppy drive",
"a floppy drive",
"an unsuported audio device",
"an ATA device",
"an unsupported PCI device",
"an unknown device",
};
if (id != bay->last_value) {
bay->last_value = id;
bay->value_count = 0;
return;
}
if (id == bay->content_id)
return;
bay->value_count += msecs_to_jiffies(MB_POLL_DELAY);
if (bay->value_count >= msecs_to_jiffies(MB_STABLE_DELAY)) {
if ((id != MB_NO) && (bay->content_id != MB_NO)) {
id = MB_NO;
pr_debug("mediabay%d: forcing MB_NO\n", bay->index);
}
pr_debug("mediabay%d: switching to %d\n", bay->index, id);
set_mb_power(bay, id != MB_NO);
bay->content_id = id;
if (id >= MB_NO || id < 0)
printk(KERN_INFO "mediabay%d: Bay is now empty\n", bay->index);
else
printk(KERN_INFO "mediabay%d: Bay contains %s\n",
bay->index, mb_content_types[id]);
}
}
int check_media_bay(struct macio_dev *baydev)
{
struct media_bay_info* bay;
int id;
if (baydev == NULL)
return MB_NO;
bay = macio_get_drvdata(baydev);
if (bay == NULL)
return MB_NO;
id = bay->content_id;
if (bay->state != mb_up)
return MB_NO;
if (id == MB_FD1)
return MB_FD;
return id;
}
void lock_media_bay(struct macio_dev *baydev)
{
struct media_bay_info* bay;
if (baydev == NULL)
return;
bay = macio_get_drvdata(baydev);
if (bay == NULL)
return;
mutex_lock(&bay->lock);
bay->user_lock = 1;
}
void unlock_media_bay(struct macio_dev *baydev)
{
struct media_bay_info* bay;
if (baydev == NULL)
return;
bay = macio_get_drvdata(baydev);
if (bay == NULL)
return;
if (bay->user_lock) {
bay->user_lock = 0;
mutex_unlock(&bay->lock);
}
}
static int mb_broadcast_hotplug(struct device *dev, void *data)
{
struct media_bay_info* bay = data;
struct macio_dev *mdev;
struct macio_driver *drv;
int state;
if (dev->bus != &macio_bus_type)
return 0;
state = bay->state == mb_up ? bay->content_id : MB_NO;
if (state == MB_FD1)
state = MB_FD;
mdev = to_macio_device(dev);
drv = to_macio_driver(dev->driver);
if (dev->driver && drv->mediabay_event)
drv->mediabay_event(mdev, state);
return 0;
}
static void media_bay_step(int i)
{
struct media_bay_info* bay = &media_bays[i];
if (bay->state != mb_powering_down)
poll_media_bay(bay);
if (bay->timer != 0) {
bay->timer -= msecs_to_jiffies(MB_POLL_DELAY);
if (bay->timer > 0)
return;
bay->timer = 0;
}
switch(bay->state) {
case mb_powering_up:
if (bay->ops->setup_bus(bay, bay->last_value) < 0) {
pr_debug("mediabay%d: device not supported (kind:%d)\n",
i, bay->content_id);
set_mb_power(bay, 0);
break;
}
bay->timer = msecs_to_jiffies(MB_RESET_DELAY);
bay->state = mb_enabling_bay;
pr_debug("mediabay%d: enabling (kind:%d)\n", i, bay->content_id);
break;
case mb_enabling_bay:
bay->ops->un_reset(bay);
bay->timer = msecs_to_jiffies(MB_SETUP_DELAY);
bay->state = mb_resetting;
pr_debug("mediabay%d: releasing bay reset (kind:%d)\n",
i, bay->content_id);
break;
case mb_resetting:
if (bay->content_id != MB_CD) {
pr_debug("mediabay%d: bay is up (kind:%d)\n", i,
bay->content_id);
bay->state = mb_up;
device_for_each_child(&bay->mdev->ofdev.dev,
bay, mb_broadcast_hotplug);
break;
}
pr_debug("mediabay%d: releasing ATA reset (kind:%d)\n",
i, bay->content_id);
bay->ops->un_reset_ide(bay);
bay->timer = msecs_to_jiffies(MB_IDE_WAIT);
bay->state = mb_ide_resetting;
break;
case mb_ide_resetting:
pr_debug("mediabay%d: bay is up (kind:%d)\n", i, bay->content_id);
bay->state = mb_up;
device_for_each_child(&bay->mdev->ofdev.dev,
bay, mb_broadcast_hotplug);
break;
case mb_powering_down:
bay->state = mb_empty;
device_for_each_child(&bay->mdev->ofdev.dev,
bay, mb_broadcast_hotplug);
pr_debug("mediabay%d: end of power down\n", i);
break;
}
}
static int media_bay_task(void *x)
{
int i;
while (!kthread_should_stop()) {
for (i = 0; i < media_bay_count; ++i) {
mutex_lock(&media_bays[i].lock);
if (!media_bays[i].sleeping)
media_bay_step(i);
mutex_unlock(&media_bays[i].lock);
}
msleep_interruptible(MB_POLL_DELAY);
}
return 0;
}
static int __devinit media_bay_attach(struct macio_dev *mdev, const struct of_device_id *match)
{
struct media_bay_info* bay;
u32 __iomem *regbase;
struct device_node *ofnode;
unsigned long base;
int i;
ofnode = mdev->ofdev.dev.of_node;
if (macio_resource_count(mdev) < 1)
return -ENODEV;
if (macio_request_resources(mdev, "media-bay"))
return -EBUSY;
base = macio_resource_start(mdev, 0) & 0xffff0000u;
regbase = (u32 __iomem *)ioremap(base, 0x100);
if (regbase == NULL) {
macio_release_resources(mdev);
return -ENOMEM;
}
i = media_bay_count++;
bay = &media_bays[i];
bay->mdev = mdev;
bay->base = regbase;
bay->index = i;
bay->ops = match->data;
bay->sleeping = 0;
mutex_init(&bay->lock);
if (bay->ops->init)
bay->ops->init(bay);
printk(KERN_INFO "mediabay%d: Registered %s media-bay\n", i, bay->ops->name);
set_mb_power(bay, 0);
msleep(MB_POWER_DELAY);
bay->content_id = MB_NO;
bay->last_value = bay->ops->content(bay);
bay->value_count = msecs_to_jiffies(MB_STABLE_DELAY);
bay->state = mb_empty;
macio_set_drvdata(mdev, bay);
if (i == 0)
kthread_run(media_bay_task, NULL, "media-bay");
return 0;
}
static int media_bay_suspend(struct macio_dev *mdev, pm_message_t state)
{
struct media_bay_info *bay = macio_get_drvdata(mdev);
if (state.event != mdev->ofdev.dev.power.power_state.event
&& (state.event & PM_EVENT_SLEEP)) {
mutex_lock(&bay->lock);
bay->sleeping = 1;
set_mb_power(bay, 0);
mutex_unlock(&bay->lock);
msleep(MB_POLL_DELAY);
mdev->ofdev.dev.power.power_state = state;
}
return 0;
}
static int media_bay_resume(struct macio_dev *mdev)
{
struct media_bay_info *bay = macio_get_drvdata(mdev);
if (mdev->ofdev.dev.power.power_state.event != PM_EVENT_ON) {
mdev->ofdev.dev.power.power_state = PMSG_ON;
mutex_lock(&bay->lock);
set_mb_power(bay, 0);
msleep(MB_POWER_DELAY);
if (bay->ops->content(bay) != bay->content_id) {
printk("mediabay%d: Content changed during sleep...\n", bay->index);
mutex_unlock(&bay->lock);
return 0;
}
set_mb_power(bay, 1);
bay->last_value = bay->content_id;
bay->value_count = msecs_to_jiffies(MB_STABLE_DELAY);
bay->timer = msecs_to_jiffies(MB_POWER_DELAY);
do {
msleep(MB_POLL_DELAY);
media_bay_step(bay->index);
} while((bay->state != mb_empty) &&
(bay->state != mb_up));
bay->sleeping = 0;
mutex_unlock(&bay->lock);
}
return 0;
}
static int __init media_bay_init(void)
{
int i;
for (i=0; i<MAX_BAYS; i++) {
memset((char *)&media_bays[i], 0, sizeof(struct media_bay_info));
media_bays[i].content_id = -1;
}
if (!machine_is(powermac))
return 0;
macio_register_driver(&media_bay_driver);
return 0;
}
