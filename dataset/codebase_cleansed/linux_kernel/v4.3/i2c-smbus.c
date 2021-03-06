static int smbus_do_alert(struct device *dev, void *addrp)\r\n{\r\nstruct i2c_client *client = i2c_verify_client(dev);\r\nstruct alert_data *data = addrp;\r\nstruct i2c_driver *driver;\r\nif (!client || client->addr != data->addr)\r\nreturn 0;\r\nif (client->flags & I2C_CLIENT_TEN)\r\nreturn 0;\r\ndevice_lock(dev);\r\nif (client->dev.driver) {\r\ndriver = to_i2c_driver(client->dev.driver);\r\nif (driver->alert)\r\ndriver->alert(client, data->flag);\r\nelse\r\ndev_warn(&client->dev, "no driver alert()!\n");\r\n} else\r\ndev_dbg(&client->dev, "alert with no driver\n");\r\ndevice_unlock(dev);\r\nreturn -EBUSY;\r\n}\r\nstatic void smbus_alert(struct work_struct *work)\r\n{\r\nstruct i2c_smbus_alert *alert;\r\nstruct i2c_client *ara;\r\nunsigned short prev_addr = 0;\r\nalert = container_of(work, struct i2c_smbus_alert, alert);\r\nara = alert->ara;\r\nfor (;;) {\r\ns32 status;\r\nstruct alert_data data;\r\nstatus = i2c_smbus_read_byte(ara);\r\nif (status < 0)\r\nbreak;\r\ndata.flag = status & 1;\r\ndata.addr = status >> 1;\r\nif (data.addr == prev_addr) {\r\ndev_warn(&ara->dev, "Duplicate SMBALERT# from dev "\r\n"0x%02x, skipping\n", data.addr);\r\nbreak;\r\n}\r\ndev_dbg(&ara->dev, "SMBALERT# from dev 0x%02x, flag %d\n",\r\ndata.addr, data.flag);\r\ndevice_for_each_child(&ara->adapter->dev, &data,\r\nsmbus_do_alert);\r\nprev_addr = data.addr;\r\n}\r\nif (!alert->alert_edge_triggered)\r\nenable_irq(alert->irq);\r\n}\r\nstatic irqreturn_t smbalert_irq(int irq, void *d)\r\n{\r\nstruct i2c_smbus_alert *alert = d;\r\nif (!alert->alert_edge_triggered)\r\ndisable_irq_nosync(irq);\r\nschedule_work(&alert->alert);\r\nreturn IRQ_HANDLED;\r\n}\r\nstatic int smbalert_probe(struct i2c_client *ara,\r\nconst struct i2c_device_id *id)\r\n{\r\nstruct i2c_smbus_alert_setup *setup = dev_get_platdata(&ara->dev);\r\nstruct i2c_smbus_alert *alert;\r\nstruct i2c_adapter *adapter = ara->adapter;\r\nint res;\r\nalert = devm_kzalloc(&ara->dev, sizeof(struct i2c_smbus_alert),\r\nGFP_KERNEL);\r\nif (!alert)\r\nreturn -ENOMEM;\r\nalert->alert_edge_triggered = setup->alert_edge_triggered;\r\nalert->irq = setup->irq;\r\nINIT_WORK(&alert->alert, smbus_alert);\r\nalert->ara = ara;\r\nif (setup->irq > 0) {\r\nres = devm_request_irq(&ara->dev, setup->irq, smbalert_irq,\r\n0, "smbus_alert", alert);\r\nif (res)\r\nreturn res;\r\n}\r\ni2c_set_clientdata(ara, alert);\r\ndev_info(&adapter->dev, "supports SMBALERT#, %s trigger\n",\r\nsetup->alert_edge_triggered ? "edge" : "level");\r\nreturn 0;\r\n}\r\nstatic int smbalert_remove(struct i2c_client *ara)\r\n{\r\nstruct i2c_smbus_alert *alert = i2c_get_clientdata(ara);\r\ncancel_work_sync(&alert->alert);\r\nreturn 0;\r\n}\r\nstruct i2c_client *i2c_setup_smbus_alert(struct i2c_adapter *adapter,\r\nstruct i2c_smbus_alert_setup *setup)\r\n{\r\nstruct i2c_board_info ara_board_info = {\r\nI2C_BOARD_INFO("smbus_alert", 0x0c),\r\n.platform_data = setup,\r\n};\r\nreturn i2c_new_device(adapter, &ara_board_info);\r\n}\r\nint i2c_handle_smbus_alert(struct i2c_client *ara)\r\n{\r\nstruct i2c_smbus_alert *alert = i2c_get_clientdata(ara);\r\nreturn schedule_work(&alert->alert);\r\n}
