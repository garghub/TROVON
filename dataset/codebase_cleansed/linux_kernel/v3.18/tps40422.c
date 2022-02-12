static int tps40422_probe(struct i2c_client *client,\r\nconst struct i2c_device_id *id)\r\n{\r\nreturn pmbus_do_probe(client, id, &tps40422_info);\r\n}
