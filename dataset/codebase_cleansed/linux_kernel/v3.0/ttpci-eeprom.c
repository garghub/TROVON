static int check_mac_tt(u8 *buf)
{
int i;
u16 tmp = 0xffff;
for (i = 0; i < 8; i++) {
tmp = (tmp << 8) | ((tmp >> 8) ^ buf[i]);
tmp ^= (tmp >> 4) & 0x0f;
tmp ^= (tmp << 12) ^ ((tmp & 0xff) << 5);
}
tmp ^= 0xffff;
return (((tmp >> 8) ^ buf[8]) | ((tmp & 0xff) ^ buf[9]));
}
static int getmac_tt(u8 * decodedMAC, u8 * encodedMAC)
{
u8 xor[20] = { 0x72, 0x23, 0x68, 0x19, 0x5c, 0xa8, 0x71, 0x2c,
0x54, 0xd3, 0x7b, 0xf1, 0x9E, 0x23, 0x16, 0xf6,
0x1d, 0x36, 0x64, 0x78};
u8 data[20];
int i;
memcpy(data, encodedMAC, 20);
for (i = 0; i < 20; i++)
data[i] ^= xor[i];
for (i = 0; i < 10; i++)
data[i] = ((data[2 * i + 1] << 8) | data[2 * i])
>> ((data[2 * i + 1] >> 6) & 3);
if (check_mac_tt(data))
return -ENODEV;
decodedMAC[0] = data[2]; decodedMAC[1] = data[1]; decodedMAC[2] = data[0];
decodedMAC[3] = data[6]; decodedMAC[4] = data[5]; decodedMAC[5] = data[4];
return 0;
}
static int ttpci_eeprom_read_encodedMAC(struct i2c_adapter *adapter, u8 * encodedMAC)
{
int ret;
u8 b0[] = { 0xcc };
struct i2c_msg msg[] = {
{ .addr = 0x50, .flags = 0, .buf = b0, .len = 1 },
{ .addr = 0x50, .flags = I2C_M_RD, .buf = encodedMAC, .len = 20 }
};
ret = i2c_transfer(adapter, msg, 2);
if (ret != 2)
return (-ENODEV);
return 0;
}
int ttpci_eeprom_parse_mac(struct i2c_adapter *adapter, u8 *proposed_mac)
{
int ret, i;
u8 encodedMAC[20];
u8 decodedMAC[6];
ret = ttpci_eeprom_read_encodedMAC(adapter, encodedMAC);
if (ret != 0) {
dprintk("Couldn't read from EEPROM: not there?\n");
memset(proposed_mac, 0, 6);
return ret;
}
ret = getmac_tt(decodedMAC, encodedMAC);
if( ret != 0 ) {
dprintk("adapter failed MAC signature check\n");
dprintk("encoded MAC from EEPROM was " );
for(i=0; i<19; i++) {
dprintk( "%.2x:", encodedMAC[i]);
}
dprintk("%.2x\n", encodedMAC[19]);
memset(proposed_mac, 0, 6);
return ret;
}
memcpy(proposed_mac, decodedMAC, 6);
dprintk("adapter has MAC addr = %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
decodedMAC[0], decodedMAC[1], decodedMAC[2],
decodedMAC[3], decodedMAC[4], decodedMAC[5]);
return 0;
}
