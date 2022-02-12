static bool rt2800pci_hwcrypt_disabled(struct rt2x00_dev *rt2x00dev)
{
return modparam_nohwcrypt;
}
static void rt2800pci_mcu_status(struct rt2x00_dev *rt2x00dev, const u8 token)
{
unsigned int i;
u32 reg;
if (rt2x00_is_soc(rt2x00dev))
return;
for (i = 0; i < 200; i++) {
rt2x00mmio_register_read(rt2x00dev, H2M_MAILBOX_CID, &reg);
if ((rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD0) == token) ||
(rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD1) == token) ||
(rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD2) == token) ||
(rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD3) == token))
break;
udelay(REGISTER_BUSY_DELAY);
}
if (i == 200)
rt2x00_err(rt2x00dev, "MCU request failed, no response from hardware\n");
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);
}
static void rt2800pci_eepromregister_read(struct eeprom_93cx6 *eeprom)
{
struct rt2x00_dev *rt2x00dev = eeprom->data;
u32 reg;
rt2x00mmio_register_read(rt2x00dev, E2PROM_CSR, &reg);
eeprom->reg_data_in = !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_IN);
eeprom->reg_data_out = !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_OUT);
eeprom->reg_data_clock =
!!rt2x00_get_field32(reg, E2PROM_CSR_DATA_CLOCK);
eeprom->reg_chip_select =
!!rt2x00_get_field32(reg, E2PROM_CSR_CHIP_SELECT);
}
static void rt2800pci_eepromregister_write(struct eeprom_93cx6 *eeprom)
{
struct rt2x00_dev *rt2x00dev = eeprom->data;
u32 reg = 0;
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_IN, !!eeprom->reg_data_in);
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_OUT, !!eeprom->reg_data_out);
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_CLOCK,
!!eeprom->reg_data_clock);
rt2x00_set_field32(&reg, E2PROM_CSR_CHIP_SELECT,
!!eeprom->reg_chip_select);
rt2x00mmio_register_write(rt2x00dev, E2PROM_CSR, reg);
}
static int rt2800pci_read_eeprom_pci(struct rt2x00_dev *rt2x00dev)
{
struct eeprom_93cx6 eeprom;
u32 reg;
rt2x00mmio_register_read(rt2x00dev, E2PROM_CSR, &reg);
eeprom.data = rt2x00dev;
eeprom.register_read = rt2800pci_eepromregister_read;
eeprom.register_write = rt2800pci_eepromregister_write;
switch (rt2x00_get_field32(reg, E2PROM_CSR_TYPE))
{
case 0:
eeprom.width = PCI_EEPROM_WIDTH_93C46;
break;
case 1:
eeprom.width = PCI_EEPROM_WIDTH_93C66;
break;
default:
eeprom.width = PCI_EEPROM_WIDTH_93C86;
break;
}
eeprom.reg_data_in = 0;
eeprom.reg_data_out = 0;
eeprom.reg_data_clock = 0;
eeprom.reg_chip_select = 0;
eeprom_93cx6_multiread(&eeprom, EEPROM_BASE, rt2x00dev->eeprom,
EEPROM_SIZE / sizeof(u16));
return 0;
}
static int rt2800pci_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
return rt2800_efuse_detect(rt2x00dev);
}
static inline int rt2800pci_read_eeprom_efuse(struct rt2x00_dev *rt2x00dev)
{
return rt2800_read_eeprom_efuse(rt2x00dev);
}
static char *rt2800pci_get_firmware_name(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00_rt(rt2x00dev, RT3290))
return FIRMWARE_RT3290;
else
return FIRMWARE_RT2860;
}
static int rt2800pci_write_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
u32 reg;
reg = 0;
rt2x00_set_field32(&reg, PBF_SYS_CTRL_HOST_RAM_WRITE, 1);
rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, reg);
rt2x00mmio_register_multiwrite(rt2x00dev, FIRMWARE_IMAGE_BASE,
data, len);
rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000);
rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00001);
rt2x00mmio_register_write(rt2x00dev, H2M_BBP_AGENT, 0);
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CSR, 0);
return 0;
}
static int rt2800pci_enable_radio(struct rt2x00_dev *rt2x00dev)
{
int retval;
retval = rt2800mmio_enable_radio(rt2x00dev);
if (retval)
return retval;
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);
rt2800_mcu_request(rt2x00dev, MCU_SLEEP, TOKEN_RADIO_OFF, 0xff, 0x02);
rt2800pci_mcu_status(rt2x00dev, TOKEN_RADIO_OFF);
rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, TOKEN_WAKEUP, 0, 0);
rt2800pci_mcu_status(rt2x00dev, TOKEN_WAKEUP);
return retval;
}
static int rt2800pci_set_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
if (state == STATE_AWAKE) {
rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, TOKEN_WAKEUP,
0, 0x02);
rt2800pci_mcu_status(rt2x00dev, TOKEN_WAKEUP);
} else if (state == STATE_SLEEP) {
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_STATUS,
0xffffffff);
rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CID,
0xffffffff);
rt2800_mcu_request(rt2x00dev, MCU_SLEEP, TOKEN_SLEEP,
0xff, 0x01);
}
return 0;
}
static int rt2800pci_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
retval = rt2800pci_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt2800pci_set_state(rt2x00dev, STATE_SLEEP);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
rt2800mmio_toggle_irq(rt2x00dev, state);
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = rt2800pci_set_state(rt2x00dev, state);
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
static int rt2800pci_read_eeprom(struct rt2x00_dev *rt2x00dev)
{
int retval;
if (rt2800pci_efuse_detect(rt2x00dev))
retval = rt2800pci_read_eeprom_efuse(rt2x00dev);
else
retval = rt2800pci_read_eeprom_pci(rt2x00dev);
return retval;
}
static int rt2800pci_probe(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
return rt2x00pci_probe(pci_dev, &rt2800pci_ops);
}
