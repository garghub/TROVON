void saa7164_card_list(struct saa7164_dev *dev)
{
int i;
if (0 == dev->pci->subsystem_vendor &&
0 == dev->pci->subsystem_device) {
printk(KERN_ERR
"%s: Board has no valid PCIe Subsystem ID and can't\n"
"%s: be autodetected. Pass card=<n> insmod option to\n"
"%s: workaround that. Send complaints to the vendor\n"
"%s: of the TV card. Best regards,\n"
"%s: -- tux\n",
dev->name, dev->name, dev->name, dev->name, dev->name);
} else {
printk(KERN_ERR
"%s: Your board isn't known (yet) to the driver.\n"
"%s: Try to pick one of the existing card configs via\n"
"%s: card=<n> insmod option. Updating to the latest\n"
"%s: version might help as well.\n",
dev->name, dev->name, dev->name, dev->name);
}
printk(KERN_ERR "%s: Here are valid choices for the card=<n> insmod option:\n",
dev->name);
for (i = 0; i < saa7164_bcount; i++)
printk(KERN_ERR "%s: card=%d -> %s\n",
dev->name, i, saa7164_boards[i].name);
}
void saa7164_gpio_setup(struct saa7164_dev *dev)
{
switch (dev->board) {
case SAA7164_BOARD_HAUPPAUGE_HVR2200:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_2:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_3:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_4:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_5:
case SAA7164_BOARD_HAUPPAUGE_HVR2250:
case SAA7164_BOARD_HAUPPAUGE_HVR2250_2:
case SAA7164_BOARD_HAUPPAUGE_HVR2250_3:
case SAA7164_BOARD_HAUPPAUGE_HVR2255proto:
case SAA7164_BOARD_HAUPPAUGE_HVR2255:
case SAA7164_BOARD_HAUPPAUGE_HVR2205:
saa7164_api_clear_gpiobit(dev, PCIEBRIDGE_UNITID, 2);
saa7164_api_clear_gpiobit(dev, PCIEBRIDGE_UNITID, 3);
msleep(20);
saa7164_api_set_gpiobit(dev, PCIEBRIDGE_UNITID, 2);
saa7164_api_set_gpiobit(dev, PCIEBRIDGE_UNITID, 3);
break;
}
}
static void hauppauge_eeprom(struct saa7164_dev *dev, u8 *eeprom_data)
{
struct tveeprom tv;
tveeprom_hauppauge_analog(&tv, eeprom_data);
switch (tv.model) {
case 88001:
case 88021:
break;
case 88041:
break;
case 88061:
break;
case 89519:
case 89609:
break;
case 89619:
break;
case 151009:
break;
case 151609:
break;
case 151061:
break;
default:
printk(KERN_ERR "%s: Warning: Unknown Hauppauge model #%d\n",
dev->name, tv.model);
break;
}
printk(KERN_INFO "%s: Hauppauge eeprom: model=%d\n", dev->name,
tv.model);
}
void saa7164_card_setup(struct saa7164_dev *dev)
{
static u8 eeprom[256];
if (dev->i2c_bus[0].i2c_rc == 0) {
if (saa7164_api_read_eeprom(dev, &eeprom[0],
sizeof(eeprom)) < 0)
return;
}
switch (dev->board) {
case SAA7164_BOARD_HAUPPAUGE_HVR2200:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_2:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_3:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_4:
case SAA7164_BOARD_HAUPPAUGE_HVR2200_5:
case SAA7164_BOARD_HAUPPAUGE_HVR2250:
case SAA7164_BOARD_HAUPPAUGE_HVR2250_2:
case SAA7164_BOARD_HAUPPAUGE_HVR2250_3:
case SAA7164_BOARD_HAUPPAUGE_HVR2255proto:
case SAA7164_BOARD_HAUPPAUGE_HVR2255:
case SAA7164_BOARD_HAUPPAUGE_HVR2205:
hauppauge_eeprom(dev, &eeprom[0]);
break;
}
}
int saa7164_i2caddr_to_unitid(struct saa7164_i2c *bus, int addr)
{
struct saa7164_dev *dev = bus->dev;
struct saa7164_unit *unit;
int i;
for (i = 0; i < SAA7164_MAX_UNITS; i++) {
unit = &saa7164_boards[dev->board].unit[i];
if (unit->type == SAA7164_UNIT_UNDEFINED)
continue;
if ((bus->nr == unit->i2c_bus_nr) &&
(addr == unit->i2c_bus_addr))
return unit->id;
}
return -1;
}
int saa7164_i2caddr_to_reglen(struct saa7164_i2c *bus, int addr)
{
struct saa7164_dev *dev = bus->dev;
struct saa7164_unit *unit;
int i;
for (i = 0; i < SAA7164_MAX_UNITS; i++) {
unit = &saa7164_boards[dev->board].unit[i];
if (unit->type == SAA7164_UNIT_UNDEFINED)
continue;
if ((bus->nr == unit->i2c_bus_nr) &&
(addr == unit->i2c_bus_addr))
return unit->i2c_reg_len;
}
return -1;
}
char *saa7164_unitid_name(struct saa7164_dev *dev, u8 unitid)
{
char *undefed = "UNDEFINED";
char *bridge = "BRIDGE";
struct saa7164_unit *unit;
int i;
if (unitid == 0)
return bridge;
for (i = 0; i < SAA7164_MAX_UNITS; i++) {
unit = &saa7164_boards[dev->board].unit[i];
if (unit->type == SAA7164_UNIT_UNDEFINED)
continue;
if (unitid == unit->id)
return unit->name;
}
return undefed;
}
