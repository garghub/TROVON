static struct ltc4215_data *ltc4215_update_device(struct device *dev)\r\n{\r\nstruct i2c_client *client = to_i2c_client(dev);\r\nstruct ltc4215_data *data = i2c_get_clientdata(client);\r\ns32 val;\r\nint i;\r\nmutex_lock(&data->update_lock);\r\nif (time_after(jiffies, data->last_updated + HZ / 10) || !data->valid) {\r\ndev_dbg(&client->dev, "Starting ltc4215 update\n");\r\nfor (i = 0; i < ARRAY_SIZE(data->regs); i++) {\r\nval = i2c_smbus_read_byte_data(client, i);\r\nif (unlikely(val < 0))\r\ndata->regs[i] = 0;\r\nelse\r\ndata->regs[i] = val;\r\n}\r\ndata->last_updated = jiffies;\r\ndata->valid = 1;\r\n}\r\nmutex_unlock(&data->update_lock);\r\nreturn data;\r\n}\r\nstatic int ltc4215_get_voltage(struct device *dev, u8 reg)\r\n{\r\nstruct ltc4215_data *data = ltc4215_update_device(dev);\r\nconst u8 regval = data->regs[reg];\r\nu32 voltage = 0;\r\nswitch (reg) {\r\ncase LTC4215_SENSE:\r\nvoltage = regval * 151 / 1000;\r\nbreak;\r\ncase LTC4215_SOURCE:\r\nvoltage = regval * 605 / 10;\r\nbreak;\r\ncase LTC4215_ADIN:\r\nvoltage = regval * 482 * 125 / 1000;\r\nbreak;\r\ndefault:\r\nWARN_ON_ONCE(1);\r\nbreak;\r\n}\r\nreturn voltage;\r\n}\r\nstatic unsigned int ltc4215_get_current(struct device *dev)\r\n{\r\nstruct ltc4215_data *data = ltc4215_update_device(dev);\r\nconst unsigned int voltage = data->regs[LTC4215_SENSE] * 151;\r\nconst unsigned int curr = voltage / 4;\r\nreturn curr;\r\n}\r\nstatic ssize_t ltc4215_show_voltage(struct device *dev,\r\nstruct device_attribute *da,\r\nchar *buf)\r\n{\r\nstruct sensor_device_attribute *attr = to_sensor_dev_attr(da);\r\nconst int voltage = ltc4215_get_voltage(dev, attr->index);\r\nreturn snprintf(buf, PAGE_SIZE, "%d\n", voltage);\r\n}\r\nstatic ssize_t ltc4215_show_current(struct device *dev,\r\nstruct device_attribute *da,\r\nchar *buf)\r\n{\r\nconst unsigned int curr = ltc4215_get_current(dev);\r\nreturn snprintf(buf, PAGE_SIZE, "%u\n", curr);\r\n}\r\nstatic ssize_t ltc4215_show_power(struct device *dev,\r\nstruct device_attribute *da,\r\nchar *buf)\r\n{\r\nconst unsigned int curr = ltc4215_get_current(dev);\r\nconst int output_voltage = ltc4215_get_voltage(dev, LTC4215_ADIN);\r\nconst unsigned int power = abs(output_voltage * curr);\r\nreturn snprintf(buf, PAGE_SIZE, "%u\n", power);\r\n}\r\nstatic ssize_t ltc4215_show_alarm(struct device *dev,\r\nstruct device_attribute *da,\r\nchar *buf)\r\n{\r\nstruct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);\r\nstruct ltc4215_data *data = ltc4215_update_device(dev);\r\nconst u8 reg = data->regs[attr->index];\r\nconst u32 mask = attr->nr;\r\nreturn snprintf(buf, PAGE_SIZE, "%u\n", (reg & mask) ? 1 : 0);\r\n}\r\nstatic int ltc4215_probe(struct i2c_client *client,\r\nconst struct i2c_device_id *id)\r\n{\r\nstruct i2c_adapter *adapter = client->adapter;\r\nstruct ltc4215_data *data;\r\nint ret;\r\nif (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))\r\nreturn -ENODEV;\r\ndata = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);\r\nif (!data)\r\nreturn -ENOMEM;\r\ni2c_set_clientdata(client, data);\r\nmutex_init(&data->update_lock);\r\ni2c_smbus_write_byte_data(client, LTC4215_FAULT, 0x00);\r\nret = sysfs_create_group(&client->dev.kobj, &ltc4215_group);\r\nif (ret)\r\nreturn ret;\r\ndata->hwmon_dev = hwmon_device_register(&client->dev);\r\nif (IS_ERR(data->hwmon_dev)) {\r\nret = PTR_ERR(data->hwmon_dev);\r\ngoto out_hwmon_device_register;\r\n}\r\nreturn 0;\r\nout_hwmon_device_register:\r\nsysfs_remove_group(&client->dev.kobj, &ltc4215_group);\r\nreturn ret;\r\n}\r\nstatic int ltc4215_remove(struct i2c_client *client)\r\n{\r\nstruct ltc4215_data *data = i2c_get_clientdata(client);\r\nhwmon_device_unregister(data->hwmon_dev);\r\nsysfs_remove_group(&client->dev.kobj, &ltc4215_group);\r\nreturn 0;\r\n}
