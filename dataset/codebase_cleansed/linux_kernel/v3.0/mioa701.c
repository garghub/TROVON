static int mio_gpio_request(struct gpio_ress *gpios, int size)
{
int i, rc = 0;
int gpio;
int dir;
for (i = 0; (!rc) && (i < size); i++) {
gpio = gpios[i].gpio;
dir = gpios[i].dir;
rc = gpio_request(gpio, gpios[i].desc);
if (rc) {
printk(KERN_ERR "Error requesting GPIO %d(%s) : %d\n",
gpio, gpios[i].desc, rc);
continue;
}
if (dir)
gpio_direction_output(gpio, gpios[i].init);
else
gpio_direction_input(gpio);
}
while ((rc) && (--i >= 0))
gpio_free(gpios[i].gpio);
return rc;
}
static void mio_gpio_free(struct gpio_ress *gpios, int size)
{
int i;
for (i = 0; i < size; i++)
gpio_free(gpios[i].gpio);
}
static void mioa701_lcd_power(int on, struct fb_var_screeninfo *si)
{
gpio_set_value(GPIO87_LCD_POWER, on);
}
static int is_gsm_on(void)
{
int is_on;
is_on = !!gpio_get_value(GPIO25_GSM_MOD_ON_STATE);
return is_on;
}
irqreturn_t gsm_on_irq(int irq, void *p)
{
printk(KERN_DEBUG "Mioa701: GSM status changed to %s\n",
is_gsm_on() ? "on" : "off");
return IRQ_HANDLED;
}
static int __init gsm_init(void)
{
int rc;
rc = mio_gpio_request(ARRAY_AND_SIZE(gsm_gpios));
if (rc)
goto err_gpio;
rc = request_irq(gpio_to_irq(GPIO25_GSM_MOD_ON_STATE), gsm_on_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"GSM XS200 Power Irq", NULL);
if (rc)
goto err_irq;
gpio_set_wake(GPIO113_GSM_EVENT, 1);
return 0;
err_irq:
printk(KERN_ERR "Mioa701: Can't request GSM_ON irq\n");
mio_gpio_free(ARRAY_AND_SIZE(gsm_gpios));
err_gpio:
printk(KERN_ERR "Mioa701: gsm not available\n");
return rc;
}
static void gsm_exit(void)
{
free_irq(gpio_to_irq(GPIO25_GSM_MOD_ON_STATE), NULL);
mio_gpio_free(ARRAY_AND_SIZE(gsm_gpios));
}
static int is_usb_connected(void)
{
return !gpio_get_value(GPIO13_nUSB_DETECT);
}
static void install_bootstrap(void)
{
int i;
u32 *rom_bootstrap = phys_to_virt(RESUME_VECTOR_ADDR);
u32 *src = &mioa701_bootstrap;
for (i = 0; i < BOOTSTRAP_WORDS; i++)
rom_bootstrap[i] = src[i];
}
static int mioa701_sys_suspend(void)
{
int i = 0, is_bt_on;
u32 *mem_resume_vector = phys_to_virt(RESUME_VECTOR_ADDR);
u32 *mem_resume_enabler = phys_to_virt(RESUME_ENABLE_ADDR);
u32 *mem_resume_bt = phys_to_virt(RESUME_BT_ADDR);
u32 *mem_resume_unknown = phys_to_virt(RESUME_UNKNOWN_ADDR);
is_bt_on = !!gpio_get_value(GPIO83_BT_ON);
pxa2xx_mfp_set_lpm(GPIO83_BT_ON,
is_bt_on ? MFP_LPM_DRIVE_HIGH : MFP_LPM_DRIVE_LOW);
for (i = 0; i < BOOTSTRAP_WORDS; i++)
save_buffer[i] = mem_resume_vector[i];
save_buffer[i++] = *mem_resume_enabler;
save_buffer[i++] = *mem_resume_bt;
save_buffer[i++] = *mem_resume_unknown;
*mem_resume_enabler = RESUME_ENABLE_VAL;
*mem_resume_bt = is_bt_on;
install_bootstrap();
return 0;
}
static void mioa701_sys_resume(void)
{
int i = 0;
u32 *mem_resume_vector = phys_to_virt(RESUME_VECTOR_ADDR);
u32 *mem_resume_enabler = phys_to_virt(RESUME_ENABLE_ADDR);
u32 *mem_resume_bt = phys_to_virt(RESUME_BT_ADDR);
u32 *mem_resume_unknown = phys_to_virt(RESUME_UNKNOWN_ADDR);
for (i = 0; i < BOOTSTRAP_WORDS; i++)
mem_resume_vector[i] = save_buffer[i];
*mem_resume_enabler = save_buffer[i++];
*mem_resume_bt = save_buffer[i++];
*mem_resume_unknown = save_buffer[i++];
}
static int __init bootstrap_init(void)
{
int save_size = mioa701_bootstrap_lg + (sizeof(u32) * 3);
register_syscore_ops(&mioa701_syscore_ops);
save_buffer = kmalloc(save_size, GFP_KERNEL);
if (!save_buffer)
return -ENOMEM;
printk(KERN_INFO "MioA701: allocated %d bytes for bootstrap\n",
save_size);
return 0;
}
static void bootstrap_exit(void)
{
kfree(save_buffer);
unregister_syscore_ops(&mioa701_syscore_ops);
printk(KERN_CRIT "Unregistering mioa701 suspend will hang next"
"resume !!!\n");
}
static int is_ac_connected(void)
{
return gpio_get_value(GPIO96_AC_DETECT);
}
static void mioa701_set_charge(int flags)
{
gpio_set_value(GPIO9_CHARGE_EN, (flags == PDA_POWER_CHARGE_USB));
}
static void mioa701_poweroff(void)
{
mioa701_machine_exit();
arm_machine_restart('s', NULL);
}
static void mioa701_restart(char c, const char *cmd)
{
mioa701_machine_exit();
arm_machine_restart('s', cmd);
}
static void __init mioa701_machine_init(void)
{
PSLR = 0xff100000;
PCFR = PCFR_DC_EN | PCFR_GPR_EN | PCFR_OPDE;
RTTR = 32768 - 1;
UP2OCR = UP2OCR_HXOE;
pxa2xx_mfp_config(ARRAY_AND_SIZE(mioa701_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
mio_gpio_request(ARRAY_AND_SIZE(global_gpios));
bootstrap_init();
pxa_set_fb_info(NULL, &mioa701_pxafb_info);
pxa_set_mci_info(&mioa701_mci_info);
pxa_set_keypad_info(&mioa701_keypad_info);
pxa_set_udc_info(&mioa701_udc_info);
pxa_set_ac97_info(&mioa701_ac97_info);
pm_power_off = mioa701_poweroff;
arm_pm_restart = mioa701_restart;
platform_add_devices(devices, ARRAY_SIZE(devices));
gsm_init();
i2c_register_board_info(1, ARRAY_AND_SIZE(mioa701_pi2c_devices));
pxa_set_i2c_info(&i2c_pdata);
pxa27x_set_i2c_power_info(NULL);
pxa_set_camera_info(&mioa701_pxacamera_platform_data);
}
static void mioa701_machine_exit(void)
{
bootstrap_exit();
gsm_exit();
}
