static void delay(int delay)
{
while (delay--);
}
static void send_bit(unsigned char bit)
{
scl_lo;
delay(TXX);
if (bit)
sda_hi;
else
sda_lo;
delay(TXX);
scl_hi;
delay(TXX);
}
static void send_ack(void)
{
send_bit(0);
}
static void send_byte(unsigned char byte)
{
int i = 0;
for (i = 7; i >= 0; i--)
send_bit((byte >> i) & 0x01);
}
static void send_start(void)
{
sda_hi;
delay(TXX);
scl_hi;
delay(TXX);
sda_lo;
delay(TXX);
}
static void send_stop(void)
{
sda_lo;
delay(TXX);
scl_hi;
delay(TXX);
sda_hi;
delay(TXX);
}
static void do_idle(void)
{
sda_hi;
scl_hi;
vcc_off;
}
static int recv_bit(void)
{
int status;
scl_lo;
delay(TXX);
sda_hi;
delay(TXX);
scl_hi;
delay(TXX);
return 1;
}
static unsigned char recv_byte(void) {
int i;
unsigned char byte=0;
for (i=7;i>=0;i--)
byte |= (recv_bit() << i);
return byte;
}
static int recv_ack(void)
{
unsigned int ack;
ack = (unsigned int)recv_bit();
scl_lo;
if (ack) {
do_idle();
printk(KERN_ERR "Error reading the Atmel 24C32/24C64 EEPROM\n");
return -1;
}
return ack;
}
int read_eeprom(char *buffer, int eeprom_size, int size)
{
int i = 0, err;
send_start();
send_byte(W_HEADER);
recv_ack();
if (eeprom_size > 2048) {
send_byte(0x00);
recv_ack();
}
send_start();
send_byte(R_HEADER);
err = recv_ack();
if (err == -1)
return err;
for (i = 0; i < size; i++) {
*buffer++ = recv_byte();
send_ack();
}
send_stop();
}
