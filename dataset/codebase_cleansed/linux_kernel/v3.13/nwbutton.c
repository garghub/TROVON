int button_add_callback (void (*callback) (void), int count)
{
int lp = 0;
if (callback_count == 32) {
return -ENOMEM;
}
if (!callback) {
return -EINVAL;
}
callback_count++;
for (; (button_callback_list [lp].callback); lp++);
button_callback_list [lp].callback = callback;
button_callback_list [lp].count = count;
return 0;
}
int button_del_callback (void (*callback) (void))
{
int lp = 31;
if (!callback) {
return -EINVAL;
}
while (lp >= 0) {
if ((button_callback_list [lp].callback) == callback) {
button_callback_list [lp].callback = NULL;
button_callback_list [lp].count = 0;
callback_count--;
return 0;
}
lp--;
}
return -EINVAL;
}
static void button_consume_callbacks (int bpcount)
{
int lp = 0;
for (; lp <= 31; lp++) {
if ((button_callback_list [lp].count) == bpcount) {
if (button_callback_list [lp].callback) {
button_callback_list[lp].callback();
}
}
}
}
static void button_sequence_finished (unsigned long parameters)
{
#ifdef CONFIG_NWBUTTON_REBOOT
if (button_press_count == reboot_count)
kill_cad_pid(SIGINT, 1);
#endif
button_consume_callbacks (button_press_count);
bcount = sprintf (button_output_buffer, "%d\n", button_press_count);
button_press_count = 0;
wake_up_interruptible (&button_wait_queue);
}
static irqreturn_t button_handler (int irq, void *dev_id)
{
button_press_count++;
mod_timer(&button_timer, jiffies + bdelay);
return IRQ_HANDLED;
}
static int button_read (struct file *filp, char __user *buffer,
size_t count, loff_t *ppos)
{
interruptible_sleep_on (&button_wait_queue);
return (copy_to_user (buffer, &button_output_buffer, bcount))
? -EFAULT : bcount;
}
static int __init nwbutton_init(void)
{
if (!machine_is_netwinder())
return -ENODEV;
printk (KERN_INFO "NetWinder Button Driver Version %s (C) Alex Holden "
"<alex@linuxhacker.org> 1998.\n", VERSION);
if (misc_register (&button_misc_device)) {
printk (KERN_WARNING "nwbutton: Couldn't register device 10, "
"%d.\n", BUTTON_MINOR);
return -EBUSY;
}
if (request_irq (IRQ_NETWINDER_BUTTON, button_handler, 0,
"nwbutton", NULL)) {
printk (KERN_WARNING "nwbutton: IRQ %d is not free.\n",
IRQ_NETWINDER_BUTTON);
misc_deregister (&button_misc_device);
return -EIO;
}
return 0;
}
static void __exit nwbutton_exit (void)
{
free_irq (IRQ_NETWINDER_BUTTON, NULL);
misc_deregister (&button_misc_device);
}
