void cx25821_card_setup(struct cx25821_dev *dev)
{
static u8 eeprom[256];
if (dev->i2c_bus[0].i2c_rc == 0) {
dev->i2c_bus[0].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[0].i2c_client, eeprom,
sizeof(eeprom));
}
}
