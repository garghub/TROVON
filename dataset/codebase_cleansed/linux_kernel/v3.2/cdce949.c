int cdce_set_rate(struct clk *clk, unsigned long rate)
{
int i, ret = 0;
struct cdce_freq *freq_table = output_list[clk->lpsc].freq_table;
struct cdce_reg *regs = NULL;
if (!cdce_i2c_client)
return -ENODEV;
if (!freq_table)
return -EINVAL;
for (i = 0; i < output_list[clk->lpsc].size; i++) {
if (freq_table[i].frequency == rate / 1000) {
regs = freq_table[i].reglist;
break;
}
}
if (!regs)
return -EINVAL;
mutex_lock(&cdce_mutex);
for (i = 0; regs[i].addr; i++) {
ret = i2c_smbus_write_byte_data(cdce_i2c_client,
regs[i].addr | 0x80, regs[i].val);
if (ret)
break;
}
mutex_unlock(&cdce_mutex);
if (!ret)
clk->rate = rate;
return ret;
}
static int cdce_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
cdce_i2c_client = client;
return 0;
}
static int __devexit cdce_remove(struct i2c_client *client)
{
cdce_i2c_client = NULL;
return 0;
}
static int __init cdce_init(void)
{
return i2c_add_driver(&cdce_driver);
}
static void __exit cdce_exit(void)
{
i2c_del_driver(&cdce_driver);
}
