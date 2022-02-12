static __devinit int wlf_gf_module_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
int ret, i, j, id, rev;
ret = i2c_smbus_read_byte_data(i2c, 0);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID: %d\n", ret);
return ret;
}
id = (ret & 0xfe) >> 2;
rev = ret & 0x3;
for (i = 0; i < ARRAY_SIZE(gf_mods); i++)
if (id == gf_mods[i].id)
break;
if (i < ARRAY_SIZE(gf_mods)) {
dev_info(&i2c->dev, "%s revision %d\n",
gf_mods[i].name, rev + 1);
for (j = 0; j < gf_mods[i].num_i2c_devs; j++) {
if (!i2c_new_device(i2c->adapter,
&(gf_mods[i].i2c_devs[j])))
dev_err(&i2c->dev,
"Failed to register dev: %d\n", ret);
}
} else {
dev_warn(&i2c->dev, "Unknown module ID %d revision %d\n",
id, rev);
}
return 0;
}
static int __init wlf_gf_module_register(void)
{
return i2c_add_driver(&wlf_gf_module_driver);
}
