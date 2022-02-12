static void sendbyte(struct l3_pins *adap, unsigned int byte)
{
int i;
for (i = 0; i < 8; i++) {
adap->setclk(0);
udelay(adap->data_hold);
adap->setdat(byte & 1);
udelay(adap->data_setup);
adap->setclk(1);
udelay(adap->clock_high);
byte >>= 1;
}
}
static void sendbytes(struct l3_pins *adap, const u8 *buf,
int len)
{
int i;
for (i = 0; i < len; i++) {
if (i) {
udelay(adap->mode_hold);
adap->setmode(0);
udelay(adap->mode);
}
adap->setmode(1);
udelay(adap->mode_setup);
sendbyte(adap, buf[i]);
}
}
int l3_write(struct l3_pins *adap, u8 addr, u8 *data, int len)
{
adap->setclk(1);
adap->setdat(1);
adap->setmode(1);
udelay(adap->mode);
adap->setmode(0);
udelay(adap->mode_setup);
sendbyte(adap, addr);
udelay(adap->mode_hold);
sendbytes(adap, data, len);
adap->setclk(1);
adap->setdat(1);
adap->setmode(0);
return len;
}
