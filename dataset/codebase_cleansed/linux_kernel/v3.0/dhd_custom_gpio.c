int dhd_customer_oob_irq_map(unsigned long *irq_flags_ptr)
{
int host_oob_irq = 0;
#ifdef CUSTOMER_HW2
host_oob_irq = wifi_get_irq_number(irq_flags_ptr);
#else
#if defined(CUSTOM_OOB_GPIO_NUM)
if (dhd_oob_gpio_num < 0)
dhd_oob_gpio_num = CUSTOM_OOB_GPIO_NUM;
#endif
if (dhd_oob_gpio_num < 0) {
WL_ERROR("%s: ERROR customer specific Host GPIO is NOT defined\n",
__func__);
return dhd_oob_gpio_num;
}
WL_ERROR("%s: customer specific Host GPIO number is (%d)\n",
__func__, dhd_oob_gpio_num);
#if defined CUSTOMER_HW
host_oob_irq = MSM_GPIO_TO_INT(dhd_oob_gpio_num);
#elif defined CUSTOMER_HW3
gpio_request(dhd_oob_gpio_num, "oob irq");
host_oob_irq = gpio_to_irq(dhd_oob_gpio_num);
gpio_direction_input(dhd_oob_gpio_num);
#endif
#endif
return host_oob_irq;
}
void dhd_customer_gpio_wlan_ctrl(int onoff)
{
switch (onoff) {
case WLAN_RESET_OFF:
WL_TRACE("%s: call customer specific GPIO to insert WLAN RESET\n",
__func__);
#ifdef CUSTOMER_HW
bcm_wlan_power_off(2);
#endif
#ifdef CUSTOMER_HW2
wifi_set_power(0, 0);
#endif
WL_ERROR("=========== WLAN placed in RESET ========\n");
break;
case WLAN_RESET_ON:
WL_TRACE("%s: callc customer specific GPIO to remove WLAN RESET\n",
__func__);
#ifdef CUSTOMER_HW
bcm_wlan_power_on(2);
#endif
#ifdef CUSTOMER_HW2
wifi_set_power(1, 0);
#endif
WL_ERROR("=========== WLAN going back to live ========\n");
break;
case WLAN_POWER_OFF:
WL_TRACE("%s: call customer specific GPIO to turn off WL_REG_ON\n",
__func__);
#ifdef CUSTOMER_HW
bcm_wlan_power_off(1);
#endif
break;
case WLAN_POWER_ON:
WL_TRACE("%s: call customer specific GPIO to turn on WL_REG_ON\n",
__func__);
#ifdef CUSTOMER_HW
bcm_wlan_power_on(1);
#endif
udelay(200);
break;
}
}
int dhd_custom_get_mac_address(unsigned char *buf)
{
WL_TRACE("%s Enter\n", __func__);
if (!buf)
return -EINVAL;
#ifdef EXAMPLE_GET_MAC
{
u8 ea_example[ETH_ALEN] = {0x00, 0x11, 0x22, 0x33, 0x44, 0xFF};
memcpy(buf, ea_example, ETH_ALEN);
}
#endif
return 0;
}
