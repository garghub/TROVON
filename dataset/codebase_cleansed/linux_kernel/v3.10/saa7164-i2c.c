static int i2c_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
struct saa7164_i2c *bus = i2c_adap->algo_data;
struct saa7164_dev *dev = bus->dev;
int i, retval = 0;
dprintk(DBGLVL_I2C, "%s(num = %d)\n", __func__, num);
for (i = 0 ; i < num; i++) {
dprintk(DBGLVL_I2C, "%s(num = %d) addr = 0x%02x len = 0x%x\n",
__func__, num, msgs[i].addr, msgs[i].len);
if (msgs[i].flags & I2C_M_RD) {
printk(KERN_ERR "%s() Unsupported - Yet\n", __func__);
continue;
} else if (i + 1 < num && (msgs[i + 1].flags & I2C_M_RD) &&
msgs[i].addr == msgs[i + 1].addr) {
retval = saa7164_api_i2c_read(bus, msgs[i].addr,
msgs[i].len, msgs[i].buf,
msgs[i+1].len, msgs[i+1].buf
);
i++;
if (retval < 0)
goto err;
} else {
retval = saa7164_api_i2c_write(bus, msgs[i].addr,
msgs[i].len, msgs[i].buf);
}
if (retval < 0)
goto err;
}
return num;
err:
return retval;
}
static u32 saa7164_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C;
}
int saa7164_i2c_register(struct saa7164_i2c *bus)
{
struct saa7164_dev *dev = bus->dev;
dprintk(DBGLVL_I2C, "%s(bus = %d)\n", __func__, bus->nr);
bus->i2c_adap = saa7164_i2c_adap_template;
bus->i2c_client = saa7164_i2c_client_template;
bus->i2c_adap.dev.parent = &dev->pci->dev;
strlcpy(bus->i2c_adap.name, bus->dev->name,
sizeof(bus->i2c_adap.name));
bus->i2c_adap.algo_data = bus;
i2c_set_adapdata(&bus->i2c_adap, bus);
i2c_add_adapter(&bus->i2c_adap);
bus->i2c_client.adapter = &bus->i2c_adap;
if (0 != bus->i2c_rc)
printk(KERN_ERR "%s: i2c bus %d register FAILED\n",
dev->name, bus->nr);
return bus->i2c_rc;
}
int saa7164_i2c_unregister(struct saa7164_i2c *bus)
{
i2c_del_adapter(&bus->i2c_adap);
return 0;
}
