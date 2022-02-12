static int max20751_probe(struct i2c_client *client,\r\nconst struct i2c_device_id *id)\r\n{\r\nreturn pmbus_do_probe(client, id, &max20751_info);\r\n}
