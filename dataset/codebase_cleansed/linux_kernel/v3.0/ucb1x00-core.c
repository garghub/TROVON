void ucb1x00_io_set_dir(struct ucb1x00 *ucb, unsigned int in, unsigned int out)
{
unsigned long flags;
spin_lock_irqsave(&ucb->io_lock, flags);
ucb->io_dir |= out;
ucb->io_dir &= ~in;
ucb1x00_reg_write(ucb, UCB_IO_DIR, ucb->io_dir);
spin_unlock_irqrestore(&ucb->io_lock, flags);
}
void ucb1x00_io_write(struct ucb1x00 *ucb, unsigned int set, unsigned int clear)
{
unsigned long flags;
spin_lock_irqsave(&ucb->io_lock, flags);
ucb->io_out |= set;
ucb->io_out &= ~clear;
ucb1x00_reg_write(ucb, UCB_IO_DATA, ucb->io_out);
spin_unlock_irqrestore(&ucb->io_lock, flags);
}
unsigned int ucb1x00_io_read(struct ucb1x00 *ucb)
{
return ucb1x00_reg_read(ucb, UCB_IO_DATA);
}
static void ucb1x00_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct ucb1x00 *ucb = container_of(chip, struct ucb1x00, gpio);
unsigned long flags;
spin_lock_irqsave(&ucb->io_lock, flags);
if (value)
ucb->io_out |= 1 << offset;
else
ucb->io_out &= ~(1 << offset);
ucb1x00_reg_write(ucb, UCB_IO_DATA, ucb->io_out);
spin_unlock_irqrestore(&ucb->io_lock, flags);
}
static int ucb1x00_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct ucb1x00 *ucb = container_of(chip, struct ucb1x00, gpio);
return ucb1x00_reg_read(ucb, UCB_IO_DATA) & (1 << offset);
}
static int ucb1x00_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct ucb1x00 *ucb = container_of(chip, struct ucb1x00, gpio);
unsigned long flags;
spin_lock_irqsave(&ucb->io_lock, flags);
ucb->io_dir &= ~(1 << offset);
ucb1x00_reg_write(ucb, UCB_IO_DIR, ucb->io_dir);
spin_unlock_irqrestore(&ucb->io_lock, flags);
return 0;
}
static int ucb1x00_gpio_direction_output(struct gpio_chip *chip, unsigned offset
, int value)
{
struct ucb1x00 *ucb = container_of(chip, struct ucb1x00, gpio);
unsigned long flags;
spin_lock_irqsave(&ucb->io_lock, flags);
ucb->io_dir |= (1 << offset);
ucb1x00_reg_write(ucb, UCB_IO_DIR, ucb->io_dir);
if (value)
ucb->io_out |= 1 << offset;
else
ucb->io_out &= ~(1 << offset);
ucb1x00_reg_write(ucb, UCB_IO_DATA, ucb->io_out);
spin_unlock_irqrestore(&ucb->io_lock, flags);
return 0;
}
void ucb1x00_adc_enable(struct ucb1x00 *ucb)
{
down(&ucb->adc_sem);
ucb->adc_cr |= UCB_ADC_ENA;
ucb1x00_enable(ucb);
ucb1x00_reg_write(ucb, UCB_ADC_CR, ucb->adc_cr);
}
unsigned int ucb1x00_adc_read(struct ucb1x00 *ucb, int adc_channel, int sync)
{
unsigned int val;
if (sync)
adc_channel |= UCB_ADC_SYNC_ENA;
ucb1x00_reg_write(ucb, UCB_ADC_CR, ucb->adc_cr | adc_channel);
ucb1x00_reg_write(ucb, UCB_ADC_CR, ucb->adc_cr | adc_channel | UCB_ADC_START);
for (;;) {
val = ucb1x00_reg_read(ucb, UCB_ADC_DATA);
if (val & UCB_ADC_DAT_VAL)
break;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(1);
}
return UCB_ADC_DAT(val);
}
void ucb1x00_adc_disable(struct ucb1x00 *ucb)
{
ucb->adc_cr &= ~UCB_ADC_ENA;
ucb1x00_reg_write(ucb, UCB_ADC_CR, ucb->adc_cr);
ucb1x00_disable(ucb);
up(&ucb->adc_sem);
}
static irqreturn_t ucb1x00_irq(int irqnr, void *devid)
{
struct ucb1x00 *ucb = devid;
struct ucb1x00_irq *irq;
unsigned int isr, i;
ucb1x00_enable(ucb);
isr = ucb1x00_reg_read(ucb, UCB_IE_STATUS);
ucb1x00_reg_write(ucb, UCB_IE_CLEAR, isr);
ucb1x00_reg_write(ucb, UCB_IE_CLEAR, 0);
for (i = 0, irq = ucb->irq_handler; i < 16 && isr; i++, isr >>= 1, irq++)
if (isr & 1 && irq->fn)
irq->fn(i, irq->devid);
ucb1x00_disable(ucb);
return IRQ_HANDLED;
}
int ucb1x00_hook_irq(struct ucb1x00 *ucb, unsigned int idx, void (*fn)(int, void *), void *devid)
{
struct ucb1x00_irq *irq;
int ret = -EINVAL;
if (idx < 16) {
irq = ucb->irq_handler + idx;
ret = -EBUSY;
spin_lock_irq(&ucb->lock);
if (irq->fn == NULL) {
irq->devid = devid;
irq->fn = fn;
ret = 0;
}
spin_unlock_irq(&ucb->lock);
}
return ret;
}
void ucb1x00_enable_irq(struct ucb1x00 *ucb, unsigned int idx, int edges)
{
unsigned long flags;
if (idx < 16) {
spin_lock_irqsave(&ucb->lock, flags);
ucb1x00_enable(ucb);
if (edges & UCB_RISING) {
ucb->irq_ris_enbl |= 1 << idx;
ucb1x00_reg_write(ucb, UCB_IE_RIS, ucb->irq_ris_enbl);
}
if (edges & UCB_FALLING) {
ucb->irq_fal_enbl |= 1 << idx;
ucb1x00_reg_write(ucb, UCB_IE_FAL, ucb->irq_fal_enbl);
}
ucb1x00_disable(ucb);
spin_unlock_irqrestore(&ucb->lock, flags);
}
}
void ucb1x00_disable_irq(struct ucb1x00 *ucb, unsigned int idx, int edges)
{
unsigned long flags;
if (idx < 16) {
spin_lock_irqsave(&ucb->lock, flags);
ucb1x00_enable(ucb);
if (edges & UCB_RISING) {
ucb->irq_ris_enbl &= ~(1 << idx);
ucb1x00_reg_write(ucb, UCB_IE_RIS, ucb->irq_ris_enbl);
}
if (edges & UCB_FALLING) {
ucb->irq_fal_enbl &= ~(1 << idx);
ucb1x00_reg_write(ucb, UCB_IE_FAL, ucb->irq_fal_enbl);
}
ucb1x00_disable(ucb);
spin_unlock_irqrestore(&ucb->lock, flags);
}
}
int ucb1x00_free_irq(struct ucb1x00 *ucb, unsigned int idx, void *devid)
{
struct ucb1x00_irq *irq;
int ret;
if (idx >= 16)
goto bad;
irq = ucb->irq_handler + idx;
ret = -ENOENT;
spin_lock_irq(&ucb->lock);
if (irq->devid == devid) {
ucb->irq_ris_enbl &= ~(1 << idx);
ucb->irq_fal_enbl &= ~(1 << idx);
ucb1x00_enable(ucb);
ucb1x00_reg_write(ucb, UCB_IE_RIS, ucb->irq_ris_enbl);
ucb1x00_reg_write(ucb, UCB_IE_FAL, ucb->irq_fal_enbl);
ucb1x00_disable(ucb);
irq->fn = NULL;
irq->devid = NULL;
ret = 0;
}
spin_unlock_irq(&ucb->lock);
return ret;
bad:
printk(KERN_ERR "Freeing bad UCB1x00 irq %d\n", idx);
return -EINVAL;
}
static int ucb1x00_add_dev(struct ucb1x00 *ucb, struct ucb1x00_driver *drv)
{
struct ucb1x00_dev *dev;
int ret = -ENOMEM;
dev = kmalloc(sizeof(struct ucb1x00_dev), GFP_KERNEL);
if (dev) {
dev->ucb = ucb;
dev->drv = drv;
ret = drv->add(dev);
if (ret == 0) {
list_add(&dev->dev_node, &ucb->devs);
list_add(&dev->drv_node, &drv->devs);
} else {
kfree(dev);
}
}
return ret;
}
static void ucb1x00_remove_dev(struct ucb1x00_dev *dev)
{
dev->drv->remove(dev);
list_del(&dev->dev_node);
list_del(&dev->drv_node);
kfree(dev);
}
static int ucb1x00_detect_irq(struct ucb1x00 *ucb)
{
unsigned long mask;
mask = probe_irq_on();
if (!mask) {
probe_irq_off(mask);
return NO_IRQ;
}
ucb1x00_reg_write(ucb, UCB_IE_RIS, UCB_IE_ADC);
ucb1x00_reg_write(ucb, UCB_IE_FAL, UCB_IE_ADC);
ucb1x00_reg_write(ucb, UCB_IE_CLEAR, 0xffff);
ucb1x00_reg_write(ucb, UCB_IE_CLEAR, 0);
ucb1x00_reg_write(ucb, UCB_ADC_CR, UCB_ADC_ENA);
ucb1x00_reg_write(ucb, UCB_ADC_CR, UCB_ADC_ENA | UCB_ADC_START);
while ((ucb1x00_reg_read(ucb, UCB_ADC_DATA) & UCB_ADC_DAT_VAL) == 0);
ucb1x00_reg_write(ucb, UCB_ADC_CR, 0);
ucb1x00_reg_write(ucb, UCB_IE_RIS, 0);
ucb1x00_reg_write(ucb, UCB_IE_FAL, 0);
ucb1x00_reg_write(ucb, UCB_IE_CLEAR, 0xffff);
ucb1x00_reg_write(ucb, UCB_IE_CLEAR, 0);
return probe_irq_off(mask);
}
static void ucb1x00_release(struct device *dev)
{
struct ucb1x00 *ucb = classdev_to_ucb1x00(dev);
kfree(ucb);
}
static int ucb1x00_probe(struct mcp *mcp)
{
struct ucb1x00 *ucb;
struct ucb1x00_driver *drv;
unsigned int id;
int ret = -ENODEV;
int temp;
mcp_enable(mcp);
id = mcp_reg_read(mcp, UCB_ID);
if (id != UCB_ID_1200 && id != UCB_ID_1300 && id != UCB_ID_TC35143) {
printk(KERN_WARNING "UCB1x00 ID not found: %04x\n", id);
goto err_disable;
}
ucb = kzalloc(sizeof(struct ucb1x00), GFP_KERNEL);
ret = -ENOMEM;
if (!ucb)
goto err_disable;
ucb->dev.class = &ucb1x00_class;
ucb->dev.parent = &mcp->attached_device;
dev_set_name(&ucb->dev, "ucb1x00");
spin_lock_init(&ucb->lock);
spin_lock_init(&ucb->io_lock);
sema_init(&ucb->adc_sem, 1);
ucb->id = id;
ucb->mcp = mcp;
ucb->irq = ucb1x00_detect_irq(ucb);
if (ucb->irq == NO_IRQ) {
printk(KERN_ERR "UCB1x00: IRQ probe failed\n");
ret = -ENODEV;
goto err_free;
}
ucb->gpio.base = -1;
if (mcp->gpio_base != 0) {
ucb->gpio.label = dev_name(&ucb->dev);
ucb->gpio.base = mcp->gpio_base;
ucb->gpio.ngpio = 10;
ucb->gpio.set = ucb1x00_gpio_set;
ucb->gpio.get = ucb1x00_gpio_get;
ucb->gpio.direction_input = ucb1x00_gpio_direction_input;
ucb->gpio.direction_output = ucb1x00_gpio_direction_output;
ret = gpiochip_add(&ucb->gpio);
if (ret)
goto err_free;
} else
dev_info(&ucb->dev, "gpio_base not set so no gpiolib support");
ret = request_irq(ucb->irq, ucb1x00_irq, IRQF_TRIGGER_RISING,
"UCB1x00", ucb);
if (ret) {
printk(KERN_ERR "ucb1x00: unable to grab irq%d: %d\n",
ucb->irq, ret);
goto err_gpio;
}
mcp_set_drvdata(mcp, ucb);
ret = device_register(&ucb->dev);
if (ret)
goto err_irq;
INIT_LIST_HEAD(&ucb->devs);
mutex_lock(&ucb1x00_mutex);
list_add(&ucb->node, &ucb1x00_devices);
list_for_each_entry(drv, &ucb1x00_drivers, node) {
ucb1x00_add_dev(ucb, drv);
}
mutex_unlock(&ucb1x00_mutex);
goto out;
err_irq:
free_irq(ucb->irq, ucb);
err_gpio:
if (ucb->gpio.base != -1)
temp = gpiochip_remove(&ucb->gpio);
err_free:
kfree(ucb);
err_disable:
mcp_disable(mcp);
out:
return ret;
}
static void ucb1x00_remove(struct mcp *mcp)
{
struct ucb1x00 *ucb = mcp_get_drvdata(mcp);
struct list_head *l, *n;
int ret;
mutex_lock(&ucb1x00_mutex);
list_del(&ucb->node);
list_for_each_safe(l, n, &ucb->devs) {
struct ucb1x00_dev *dev = list_entry(l, struct ucb1x00_dev, dev_node);
ucb1x00_remove_dev(dev);
}
mutex_unlock(&ucb1x00_mutex);
if (ucb->gpio.base != -1) {
ret = gpiochip_remove(&ucb->gpio);
if (ret)
dev_err(&ucb->dev, "Can't remove gpio chip: %d\n", ret);
}
free_irq(ucb->irq, ucb);
device_unregister(&ucb->dev);
}
int ucb1x00_register_driver(struct ucb1x00_driver *drv)
{
struct ucb1x00 *ucb;
INIT_LIST_HEAD(&drv->devs);
mutex_lock(&ucb1x00_mutex);
list_add(&drv->node, &ucb1x00_drivers);
list_for_each_entry(ucb, &ucb1x00_devices, node) {
ucb1x00_add_dev(ucb, drv);
}
mutex_unlock(&ucb1x00_mutex);
return 0;
}
void ucb1x00_unregister_driver(struct ucb1x00_driver *drv)
{
struct list_head *n, *l;
mutex_lock(&ucb1x00_mutex);
list_del(&drv->node);
list_for_each_safe(l, n, &drv->devs) {
struct ucb1x00_dev *dev = list_entry(l, struct ucb1x00_dev, drv_node);
ucb1x00_remove_dev(dev);
}
mutex_unlock(&ucb1x00_mutex);
}
static int ucb1x00_suspend(struct mcp *mcp, pm_message_t state)
{
struct ucb1x00 *ucb = mcp_get_drvdata(mcp);
struct ucb1x00_dev *dev;
mutex_lock(&ucb1x00_mutex);
list_for_each_entry(dev, &ucb->devs, dev_node) {
if (dev->drv->suspend)
dev->drv->suspend(dev, state);
}
mutex_unlock(&ucb1x00_mutex);
return 0;
}
static int ucb1x00_resume(struct mcp *mcp)
{
struct ucb1x00 *ucb = mcp_get_drvdata(mcp);
struct ucb1x00_dev *dev;
ucb1x00_reg_write(ucb, UCB_IO_DIR, ucb->io_dir);
mutex_lock(&ucb1x00_mutex);
list_for_each_entry(dev, &ucb->devs, dev_node) {
if (dev->drv->resume)
dev->drv->resume(dev);
}
mutex_unlock(&ucb1x00_mutex);
return 0;
}
static int __init ucb1x00_init(void)
{
int ret = class_register(&ucb1x00_class);
if (ret == 0) {
ret = mcp_driver_register(&ucb1x00_driver);
if (ret)
class_unregister(&ucb1x00_class);
}
return ret;
}
static void __exit ucb1x00_exit(void)
{
mcp_driver_unregister(&ucb1x00_driver);
class_unregister(&ucb1x00_class);
}
