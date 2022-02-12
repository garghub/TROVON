static bool rt2800soc_hwcrypt_disabled(struct rt2x00_dev *rt2x00dev)
{
return modparam_nohwcrypt;
}
static void rt2800soc_disable_radio(struct rt2x00_dev *rt2x00dev)
{
rt2800_disable_radio(rt2x00dev);
rt2x00mmio_register_write(rt2x00dev, PWR_PIN_CFG, 0);
rt2x00mmio_register_write(rt2x00dev, TX_PIN_CFG, 0);
}
static int rt2800soc_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
retval = rt2800mmio_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt2800soc_disable_radio(rt2x00dev);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
rt2800mmio_toggle_irq(rt2x00dev, state);
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = 0;
break;
default:
retval = -ENOTSUPP;
break;
}
if (unlikely(retval))
rt2x00_err(rt2x00dev, "Device failed to enter state %d (%d)\n",
state, retval);
return retval;
}
static int rt2800soc_read_eeprom(struct rt2x00_dev *rt2x00dev)
{
void __iomem *base_addr = ioremap(0x1F040000, EEPROM_SIZE);
if (!base_addr)
return -ENOMEM;
memcpy_fromio(rt2x00dev->eeprom, base_addr, EEPROM_SIZE);
iounmap(base_addr);
return 0;
}
static char *rt2800soc_get_firmware_name(struct rt2x00_dev *rt2x00dev)
{
WARN_ON_ONCE(1);
return NULL;
}
static int rt2800soc_load_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
WARN_ON_ONCE(1);
return 0;
}
static int rt2800soc_check_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
WARN_ON_ONCE(1);
return 0;
}
static int rt2800soc_write_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
WARN_ON_ONCE(1);
return 0;
}
static int rt2800soc_probe(struct platform_device *pdev)
{
return rt2x00soc_probe(pdev, &rt2800soc_ops);
}
