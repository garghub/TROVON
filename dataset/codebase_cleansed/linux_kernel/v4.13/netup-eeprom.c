int netup_eeprom_read(struct i2c_adapter *i2c_adap, u8 addr)
{
int ret;
unsigned char buf[2];
struct i2c_msg msg[] = {
{
.addr = EEPROM_I2C_ADDR,
.flags = 0,
.buf = &buf[0],
.len = 1
}, {
.addr = EEPROM_I2C_ADDR,
.flags = I2C_M_RD,
.buf = &buf[1],
.len = 1
}
};
buf[0] = addr;
buf[1] = 0x0;
ret = i2c_transfer(i2c_adap, msg, 2);
if (ret != 2) {
pr_err("eeprom i2c read error, status=%d\n", ret);
return -1;
}
return buf[1];
}
int netup_eeprom_write(struct i2c_adapter *i2c_adap, u8 addr, u8 data)
{
int ret;
unsigned char bufw[2];
struct i2c_msg msg[] = {
{
.addr = EEPROM_I2C_ADDR,
.flags = 0,
.buf = &bufw[0],
.len = 2
}
};
bufw[0] = addr;
bufw[1] = data;
ret = i2c_transfer(i2c_adap, msg, 1);
if (ret != 1) {
pr_err("eeprom i2c write error, status=%d\n", ret);
return -1;
}
mdelay(10);
return 0;
}
void netup_get_card_info(struct i2c_adapter *i2c_adap,
struct netup_card_info *cinfo)
{
int i, j;
cinfo->rev = netup_eeprom_read(i2c_adap, 63);
for (i = 64, j = 0; i < 70; i++, j++)
cinfo->port[0].mac[j] = netup_eeprom_read(i2c_adap, i);
for (i = 70, j = 0; i < 76; i++, j++)
cinfo->port[1].mac[j] = netup_eeprom_read(i2c_adap, i);
}
