static int isl6271a_get_voltage(struct regulator_dev *dev)\r\n{\r\nstruct isl_pmic *pmic = rdev_get_drvdata(dev);\r\nint idx, data;\r\nmutex_lock(&pmic->mtx);\r\nidx = i2c_smbus_read_byte(pmic->client);\r\nif (idx < 0) {\r\ndev_err(&pmic->client->dev, "Error getting voltage\n");\r\ndata = idx;\r\ngoto out;\r\n}\r\ndata = ISL6271A_VOLTAGE_MIN + (ISL6271A_VOLTAGE_STEP * (idx & 0xf));\r\nout:\r\nmutex_unlock(&pmic->mtx);\r\nreturn data;\r\n}\r\nstatic int isl6271a_set_voltage(struct regulator_dev *dev,\r\nint minuV, int maxuV,\r\nunsigned *selector)\r\n{\r\nstruct isl_pmic *pmic = rdev_get_drvdata(dev);\r\nint vsel, err, data;\r\nif (minuV < ISL6271A_VOLTAGE_MIN || minuV > ISL6271A_VOLTAGE_MAX)\r\nreturn -EINVAL;\r\nif (maxuV < ISL6271A_VOLTAGE_MIN || maxuV > ISL6271A_VOLTAGE_MAX)\r\nreturn -EINVAL;\r\nvsel = minuV - (minuV % ISL6271A_VOLTAGE_STEP);\r\nif (vsel < minuV)\r\nvsel += ISL6271A_VOLTAGE_STEP;\r\ndata = (vsel - ISL6271A_VOLTAGE_MIN) / ISL6271A_VOLTAGE_STEP;\r\n*selector = data;\r\nmutex_lock(&pmic->mtx);\r\nerr = i2c_smbus_write_byte(pmic->client, data);\r\nif (err < 0)\r\ndev_err(&pmic->client->dev, "Error setting voltage\n");\r\nmutex_unlock(&pmic->mtx);\r\nreturn err;\r\n}\r\nstatic int isl6271a_list_voltage(struct regulator_dev *dev, unsigned selector)\r\n{\r\nreturn ISL6271A_VOLTAGE_MIN + (ISL6271A_VOLTAGE_STEP * selector);\r\n}\r\nstatic int isl6271a_get_fixed_voltage(struct regulator_dev *dev)\r\n{\r\nint id = rdev_get_id(dev);\r\nreturn (id == 1) ? 1100000 : 1300000;\r\n}\r\nstatic int isl6271a_list_fixed_voltage(struct regulator_dev *dev, unsigned selector)\r\n{\r\nint id = rdev_get_id(dev);\r\nreturn (id == 1) ? 1100000 : 1300000;\r\n}\r\nstatic int __devinit isl6271a_probe(struct i2c_client *i2c,\r\nconst struct i2c_device_id *id)\r\n{\r\nstruct regulator_init_data *init_data = i2c->dev.platform_data;\r\nstruct isl_pmic *pmic;\r\nint err, i;\r\nif (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA))\r\nreturn -EIO;\r\nif (!init_data) {\r\ndev_err(&i2c->dev, "no platform data supplied\n");\r\nreturn -EIO;\r\n}\r\npmic = kzalloc(sizeof(struct isl_pmic), GFP_KERNEL);\r\nif (!pmic)\r\nreturn -ENOMEM;\r\npmic->client = i2c;\r\nmutex_init(&pmic->mtx);\r\nfor (i = 0; i < 3; i++) {\r\npmic->rdev[i] = regulator_register(&isl_rd[i], &i2c->dev,\r\ninit_data, pmic);\r\nif (IS_ERR(pmic->rdev[i])) {\r\ndev_err(&i2c->dev, "failed to register %s\n", id->name);\r\nerr = PTR_ERR(pmic->rdev[i]);\r\ngoto error;\r\n}\r\n}\r\ni2c_set_clientdata(i2c, pmic);\r\nreturn 0;\r\nerror:\r\nwhile (--i >= 0)\r\nregulator_unregister(pmic->rdev[i]);\r\nkfree(pmic);\r\nreturn err;\r\n}\r\nstatic int __devexit isl6271a_remove(struct i2c_client *i2c)\r\n{\r\nstruct isl_pmic *pmic = i2c_get_clientdata(i2c);\r\nint i;\r\nfor (i = 0; i < 3; i++)\r\nregulator_unregister(pmic->rdev[i]);\r\nkfree(pmic);\r\nreturn 0;\r\n}\r\nstatic int __init isl6271a_init(void)\r\n{\r\nreturn i2c_add_driver(&isl6271a_i2c_driver);\r\n}\r\nstatic void __exit isl6271a_cleanup(void)\r\n{\r\ni2c_del_driver(&isl6271a_i2c_driver);\r\n}
