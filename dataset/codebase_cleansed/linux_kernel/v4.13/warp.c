static int __init warp_device_probe(void)
{
of_platform_bus_probe(NULL, warp_of_bus, NULL);
return 0;
}
static int __init warp_probe(void)
{
if (!of_machine_is_compatible("pika,warp"))
return 0;
ISA_DMA_THRESHOLD = ~0L;
return 1;
}
static int __init warp_post_info(void)
{
struct device_node *np;
void __iomem *fpga;
u32 post1, post2;
np = of_find_compatible_node(NULL, NULL, "pika,fpga-sd");
if (np == NULL)
return -ENOENT;
fpga = of_iomap(np, 0);
of_node_put(np);
if (fpga == NULL)
return -ENOENT;
post1 = in_be32(fpga + 0x40);
post2 = in_be32(fpga + 0x44);
iounmap(fpga);
if (post1 || post2)
printk(KERN_INFO "Warp POST %08x %08x\n", post1, post2);
else
printk(KERN_INFO "Warp POST OK\n");
return 0;
}
int pika_dtm_register_shutdown(void (*func)(void *arg), void *arg)
{
struct dtm_shutdown *shutdown;
shutdown = kmalloc(sizeof(struct dtm_shutdown), GFP_KERNEL);
if (shutdown == NULL)
return -ENOMEM;
shutdown->func = func;
shutdown->arg = arg;
list_add(&shutdown->list, &dtm_shutdown_list);
return 0;
}
int pika_dtm_unregister_shutdown(void (*func)(void *arg), void *arg)
{
struct dtm_shutdown *shutdown;
list_for_each_entry(shutdown, &dtm_shutdown_list, list)
if (shutdown->func == func && shutdown->arg == arg) {
list_del(&shutdown->list);
kfree(shutdown);
return 0;
}
return -EINVAL;
}
static irqreturn_t temp_isr(int irq, void *context)
{
struct dtm_shutdown *shutdown;
int value = 1;
local_irq_disable();
gpio_set_value(green_led, 0);
list_for_each_entry(shutdown, &dtm_shutdown_list, list)
shutdown->func(shutdown->arg);
printk(KERN_EMERG "\n\nCritical Temperature Shutdown\n\n");
while (1) {
if (dtm_fpga) {
unsigned reset = in_be32(dtm_fpga + 0x14);
out_be32(dtm_fpga + 0x14, reset);
}
gpio_set_value(red_led, value);
value ^= 1;
mdelay(500);
}
return IRQ_HANDLED;
}
static int pika_setup_leds(void)
{
struct device_node *np, *child;
np = of_find_compatible_node(NULL, NULL, "gpio-leds");
if (!np) {
printk(KERN_ERR __FILE__ ": Unable to find leds\n");
return -ENOENT;
}
for_each_child_of_node(np, child)
if (strcmp(child->name, "green") == 0)
green_led = of_get_gpio(child, 0);
else if (strcmp(child->name, "red") == 0)
red_led = of_get_gpio(child, 0);
of_node_put(np);
return 0;
}
static void pika_setup_critical_temp(struct device_node *np,
struct i2c_client *client)
{
int irq, rc;
pika_setup_leds();
i2c_smbus_write_byte_data(client, 2, 65);
i2c_smbus_write_byte_data(client, 3, 0);
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
printk(KERN_ERR __FILE__ ": Unable to get ad7414 irq\n");
return;
}
rc = request_irq(irq, temp_isr, 0, "ad7414", NULL);
if (rc) {
printk(KERN_ERR __FILE__
": Unable to request ad7414 irq %d = %d\n", irq, rc);
return;
}
}
static inline void pika_dtm_check_fan(void __iomem *fpga)
{
static int fan_state;
u32 fan = in_be32(fpga + 0x34) & (1 << 14);
if (fan_state != fan) {
fan_state = fan;
if (fan)
printk(KERN_WARNING "Fan rotation error detected."
" Please check hardware.\n");
}
}
static int pika_dtm_thread(void __iomem *fpga)
{
struct device_node *np;
struct i2c_client *client;
np = of_find_compatible_node(NULL, NULL, "adi,ad7414");
if (np == NULL)
return -ENOENT;
client = of_find_i2c_device_by_node(np);
if (client == NULL) {
of_node_put(np);
return -ENOENT;
}
pika_setup_critical_temp(np, client);
of_node_put(np);
printk(KERN_INFO "Warp DTM thread running.\n");
while (!kthread_should_stop()) {
int val;
val = i2c_smbus_read_word_data(client, 0);
if (val < 0)
dev_dbg(&client->dev, "DTM read temp failed.\n");
else {
s16 temp = swab16(val);
out_be32(fpga + 0x20, temp);
}
pika_dtm_check_fan(fpga);
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(HZ);
}
return 0;
}
static int __init pika_dtm_start(void)
{
struct task_struct *dtm_thread;
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "pika,fpga");
if (np == NULL)
return -ENOENT;
dtm_fpga = of_iomap(np, 0);
of_node_put(np);
if (dtm_fpga == NULL)
return -ENOENT;
warp_post_info();
dtm_thread = kthread_run(pika_dtm_thread, dtm_fpga, "pika-dtm");
if (IS_ERR(dtm_thread)) {
iounmap(dtm_fpga);
return PTR_ERR(dtm_thread);
}
return 0;
}
int pika_dtm_register_shutdown(void (*func)(void *arg), void *arg)
{
return 0;
}
int pika_dtm_unregister_shutdown(void (*func)(void *arg), void *arg)
{
return 0;
}
