unsigned char ec_read(unsigned short addr)
{
unsigned char value;
unsigned long flags;
spin_lock_irqsave(&index_access_lock, flags);
outb((addr & 0xff00) >> 8, EC_IO_PORT_HIGH);
outb((addr & 0x00ff), EC_IO_PORT_LOW);
value = inb(EC_IO_PORT_DATA);
spin_unlock_irqrestore(&index_access_lock, flags);
return value;
}
void ec_write(unsigned short addr, unsigned char val)
{
unsigned long flags;
spin_lock_irqsave(&index_access_lock, flags);
outb((addr & 0xff00) >> 8, EC_IO_PORT_HIGH);
outb((addr & 0x00ff), EC_IO_PORT_LOW);
outb(val, EC_IO_PORT_DATA);
inb(EC_IO_PORT_DATA);
spin_unlock_irqrestore(&index_access_lock, flags);
return;
}
int ec_query_seq(unsigned char cmd)
{
int timeout;
unsigned char status;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&port_access_lock, flags);
udelay(EC_REG_DELAY);
outb(cmd, EC_CMD_PORT);
udelay(EC_REG_DELAY);
timeout = EC_CMD_TIMEOUT;
status = inb(EC_STS_PORT);
while (timeout-- && (status & (1 << 1))) {
status = inb(EC_STS_PORT);
udelay(EC_REG_DELAY);
}
spin_unlock_irqrestore(&port_access_lock, flags);
if (timeout <= 0) {
printk(KERN_ERR "%s: deadable error : timeout...\n", __func__);
ret = -EINVAL;
} else
printk(KERN_INFO
"(%x/%d)ec issued command %d status : 0x%x\n",
timeout, EC_CMD_TIMEOUT - timeout, cmd, status);
return ret;
}
int ec_query_event_num(void)
{
return ec_query_seq(CMD_GET_EVENT_NUM);
}
int ec_get_event_num(void)
{
int timeout = 100;
unsigned char value;
unsigned char status;
udelay(EC_REG_DELAY);
status = inb(EC_STS_PORT);
udelay(EC_REG_DELAY);
while (timeout-- && !(status & (1 << 0))) {
status = inb(EC_STS_PORT);
udelay(EC_REG_DELAY);
}
if (timeout <= 0) {
pr_info("%s: get event number timeout.\n", __func__);
return -EINVAL;
}
value = inb(EC_DAT_PORT);
udelay(EC_REG_DELAY);
return value;
}
