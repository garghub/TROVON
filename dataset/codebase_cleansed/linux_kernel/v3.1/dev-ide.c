void s3c_ide_set_platdata(struct s3c_ide_platdata *pdata)\r\n{\r\ns3c_set_platdata(pdata, sizeof(struct s3c_ide_platdata),\r\n&s3c_device_cfcon);\r\n}
