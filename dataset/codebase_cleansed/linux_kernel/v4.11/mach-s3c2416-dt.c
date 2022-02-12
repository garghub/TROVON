static void __init s3c2416_dt_map_io(void)\r\n{\r\ns3c24xx_init_io(NULL, 0);\r\n}\r\nstatic void __init s3c2416_dt_machine_init(void)\r\n{\r\ns3c_pm_init();\r\n}
