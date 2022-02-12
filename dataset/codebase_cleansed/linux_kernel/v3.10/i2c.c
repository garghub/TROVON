void
i2c_start(void)
{
i2c_dir_out();
i2c_delay(CLOCK_HIGH_TIME/6);
i2c_data(I2C_DATA_HIGH);
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME);
i2c_data(I2C_DATA_LOW);
i2c_delay(START_CONDITION_HOLD_TIME);
i2c_clk(I2C_CLOCK_LOW);
i2c_delay(CLOCK_LOW_TIME);
}
void
i2c_stop(void)
{
i2c_dir_out();
i2c_clk(I2C_CLOCK_LOW);
i2c_data(I2C_DATA_LOW);
i2c_delay(CLOCK_LOW_TIME*2);
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME*2);
i2c_data(I2C_DATA_HIGH);
i2c_delay(STOP_CONDITION_HOLD_TIME);
i2c_dir_in();
}
void
i2c_outbyte(unsigned char x)
{
int i;
i2c_dir_out();
for (i = 0; i < 8; i++) {
if (x & 0x80) {
i2c_data(I2C_DATA_HIGH);
} else {
i2c_data(I2C_DATA_LOW);
}
i2c_delay(CLOCK_LOW_TIME/2);
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME);
i2c_clk(I2C_CLOCK_LOW);
i2c_delay(CLOCK_LOW_TIME/2);
x <<= 1;
}
i2c_data(I2C_DATA_LOW);
i2c_delay(CLOCK_LOW_TIME/2);
i2c_dir_in();
}
unsigned char
i2c_inbyte(void)
{
unsigned char aBitByte = 0;
int i;
i2c_disable();
i2c_dir_in();
i2c_delay(CLOCK_HIGH_TIME/2);
aBitByte |= i2c_getbit();
i2c_enable();
i2c_delay(CLOCK_LOW_TIME/2);
for (i = 1; i < 8; i++) {
aBitByte <<= 1;
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME);
i2c_clk(I2C_CLOCK_LOW);
i2c_delay(CLOCK_LOW_TIME);
i2c_disable();
i2c_dir_in();
i2c_delay(CLOCK_HIGH_TIME/2);
aBitByte |= i2c_getbit();
i2c_enable();
i2c_delay(CLOCK_LOW_TIME/2);
}
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME);
i2c_clk(I2C_CLOCK_LOW);
return aBitByte;
}
int
i2c_getack(void)
{
int ack = 1;
i2c_dir_out();
i2c_data(I2C_DATA_HIGH);
i2c_dir_in();
i2c_delay(CLOCK_HIGH_TIME/4);
i2c_clk(I2C_CLOCK_HIGH);
#if 0
i2c_clk(1);
i2c_data(1);
i2c_data(1);
i2c_disable();
i2c_dir_in();
#endif
i2c_delay(CLOCK_HIGH_TIME/2);
if (i2c_getbit())
ack = 0;
i2c_delay(CLOCK_HIGH_TIME/2);
if (!ack) {
if (!i2c_getbit())
ack = 1;
i2c_delay(CLOCK_HIGH_TIME/2);
}
#if 0
i2c_data(I2C_DATA_LOW);
i2c_enable();
i2c_dir_out();
#endif
i2c_clk(I2C_CLOCK_LOW);
i2c_delay(CLOCK_HIGH_TIME/4);
i2c_dir_out();
i2c_data(I2C_DATA_HIGH);
i2c_delay(CLOCK_LOW_TIME/2);
return ack;
}
void
i2c_sendack(void)
{
i2c_delay(CLOCK_LOW_TIME);
i2c_dir_out();
i2c_data(I2C_DATA_LOW);
i2c_delay(CLOCK_HIGH_TIME/6);
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME);
i2c_clk(I2C_CLOCK_LOW);
i2c_delay(CLOCK_LOW_TIME/6);
i2c_data(I2C_DATA_HIGH);
i2c_delay(CLOCK_LOW_TIME);
i2c_dir_in();
}
void
i2c_sendnack(void)
{
i2c_delay(CLOCK_LOW_TIME);
i2c_dir_out();
i2c_data(I2C_DATA_HIGH);
i2c_delay(CLOCK_HIGH_TIME/6);
i2c_clk(I2C_CLOCK_HIGH);
i2c_delay(CLOCK_HIGH_TIME);
i2c_clk(I2C_CLOCK_LOW);
i2c_delay(CLOCK_LOW_TIME);
i2c_dir_in();
}
int
i2c_write(unsigned char theSlave, void *data, size_t nbytes)
{
int error, cntr = 3;
unsigned char bytes_wrote = 0;
unsigned char value;
unsigned long flags;
spin_lock_irqsave(&i2c_lock, flags);
do {
error = 0;
i2c_start();
i2c_outbyte((theSlave & 0xfe));
if (!i2c_getack())
error = 1;
for (bytes_wrote = 0; bytes_wrote < nbytes; bytes_wrote++) {
memcpy(&value, data + bytes_wrote, sizeof value);
i2c_outbyte(value);
if (!i2c_getack())
error |= 4;
}
i2c_stop();
} while (error && cntr--);
i2c_delay(CLOCK_LOW_TIME);
spin_unlock_irqrestore(&i2c_lock, flags);
return -error;
}
int
i2c_read(unsigned char theSlave, void *data, size_t nbytes)
{
unsigned char b = 0;
unsigned char bytes_read = 0;
int error, cntr = 3;
unsigned long flags;
spin_lock_irqsave(&i2c_lock, flags);
do {
error = 0;
memset(data, 0, nbytes);
i2c_start();
i2c_outbyte((theSlave | 0x01));
if (!i2c_getack())
error = 1;
for (bytes_read = 0; bytes_read < nbytes; bytes_read++) {
b = i2c_inbyte();
memcpy(data + bytes_read, &b, sizeof b);
if (bytes_read < (nbytes - 1))
i2c_sendack();
}
i2c_sendnack();
i2c_stop();
} while (error && cntr--);
spin_unlock_irqrestore(&i2c_lock, flags);
return -error;
}
int
i2c_writereg(unsigned char theSlave, unsigned char theReg,
unsigned char theValue)
{
int error, cntr = 3;
unsigned long flags;
spin_lock_irqsave(&i2c_lock, flags);
do {
error = 0;
i2c_start();
i2c_outbyte((theSlave & 0xfe));
if(!i2c_getack())
error = 1;
i2c_dir_out();
i2c_outbyte(theReg);
if(!i2c_getack())
error |= 2;
i2c_outbyte(theValue);
if(!i2c_getack())
error |= 4;
i2c_stop();
} while(error && cntr--);
i2c_delay(CLOCK_LOW_TIME);
spin_unlock_irqrestore(&i2c_lock, flags);
return -error;
}
unsigned char
i2c_readreg(unsigned char theSlave, unsigned char theReg)
{
unsigned char b = 0;
int error, cntr = 3;
unsigned long flags;
spin_lock_irqsave(&i2c_lock, flags);
do {
error = 0;
i2c_start();
i2c_outbyte((theSlave & 0xfe));
if(!i2c_getack())
error = 1;
i2c_dir_out();
i2c_outbyte(theReg);
if(!i2c_getack())
error |= 2;
i2c_delay(CLOCK_LOW_TIME);
i2c_start();
i2c_outbyte(theSlave | 0x01);
if(!i2c_getack())
error |= 4;
b = i2c_inbyte();
i2c_sendnack();
i2c_stop();
} while(error && cntr--);
spin_unlock_irqrestore(&i2c_lock, flags);
return b;
}
static int
i2c_open(struct inode *inode, struct file *filp)
{
return 0;
}
static int
i2c_release(struct inode *inode, struct file *filp)
{
return 0;
}
static long
i2c_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int ret;
if(_IOC_TYPE(cmd) != ETRAXI2C_IOCTYPE) {
return -ENOTTY;
}
switch (_IOC_NR(cmd)) {
case I2C_WRITEREG:
D(printk("i2cw %d %d %d\n",
I2C_ARGSLAVE(arg),
I2C_ARGREG(arg),
I2C_ARGVALUE(arg)));
mutex_lock(&i2c_mutex);
ret = i2c_writereg(I2C_ARGSLAVE(arg),
I2C_ARGREG(arg),
I2C_ARGVALUE(arg));
mutex_unlock(&i2c_mutex);
return ret;
case I2C_READREG:
{
unsigned char val;
D(printk("i2cr %d %d ",
I2C_ARGSLAVE(arg),
I2C_ARGREG(arg)));
mutex_lock(&i2c_mutex);
val = i2c_readreg(I2C_ARGSLAVE(arg), I2C_ARGREG(arg));
mutex_unlock(&i2c_mutex);
D(printk("= %d\n", val));
return val;
}
default:
return -EINVAL;
}
return 0;
}
static int __init i2c_init(void)
{
static int res;
static int first = 1;
if (!first)
return res;
first = 0;
res = crisv32_io_get_name(&cris_i2c_data,
CONFIG_ETRAX_V32_I2C_DATA_PORT);
if (res < 0)
return res;
res = crisv32_io_get_name(&cris_i2c_clk, CONFIG_ETRAX_V32_I2C_CLK_PORT);
crisv32_io_set_dir(&cris_i2c_clk, crisv32_io_dir_out);
return res;
}
static int __init i2c_register(void)
{
int res;
res = i2c_init();
if (res < 0)
return res;
res = register_chrdev(I2C_MAJOR, i2c_name, &i2c_fops);
if (res < 0) {
printk(KERN_ERR "i2c: couldn't get a major number.\n");
return res;
}
printk(KERN_INFO
"I2C driver v2.2, (c) 1999-2007 Axis Communications AB\n");
return 0;
}
