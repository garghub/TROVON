static int __init wait_scan_init(void)\r\n{\r\nwait_for_device_probe();\r\nscsi_complete_async_scans();\r\nreturn 0;\r\n}\r\nstatic void __exit wait_scan_exit(void)\r\n{\r\n}
