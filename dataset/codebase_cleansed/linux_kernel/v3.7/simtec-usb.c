static void
usb_simtec_powercontrol(int port, int to)
{
pr_debug("usb_simtec_powercontrol(%d,%d)\n", port, to);
power_state[port] = to;
if (power_state[0] && power_state[1])
gpio_set_value(S3C2410_GPB(4), 0);
else
gpio_set_value(S3C2410_GPB(4), 1);
}
static irqreturn_t
usb_simtec_ocirq(int irq, void *pw)
{
struct s3c2410_hcd_info *info = pw;
if (gpio_get_value(S3C2410_GPG(10)) == 0) {
pr_debug("usb_simtec: over-current irq (oc detected)\n");
s3c2410_usb_report_oc(info, 3);
} else {
pr_debug("usb_simtec: over-current irq (oc cleared)\n");
s3c2410_usb_report_oc(info, 0);
}
return IRQ_HANDLED;
}
static void usb_simtec_enableoc(struct s3c2410_hcd_info *info, int on)
{
int ret;
if (on) {
ret = request_irq(IRQ_USBOC, usb_simtec_ocirq,
IRQF_DISABLED | IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
"USB Over-current", info);
if (ret != 0) {
printk(KERN_ERR "failed to request usb oc irq\n");
}
} else {
free_irq(IRQ_USBOC, info);
}
}
int __init usb_simtec_init(void)
{
int ret;
printk("USB Power Control, Copyright 2004 Simtec Electronics\n");
ret = gpio_request(S3C2410_GPB(4), "USB power control");
if (ret < 0) {
pr_err("%s: failed to get GPB4\n", __func__);
return ret;
}
ret = gpio_request(S3C2410_GPG(10), "USB overcurrent");
if (ret < 0) {
pr_err("%s: failed to get GPG10\n", __func__);
gpio_free(S3C2410_GPB(4));
return ret;
}
gpio_direction_output(S3C2410_GPB(4), 1);
gpio_direction_input(S3C2410_GPG(10));
s3c_ohci_set_platdata(&usb_simtec_info);
return 0;
}
