static int __init init_rc_map(void)\r\n{\r\nreturn rc_map_register(&technisat_usb2_map);\r\n}\r\nstatic void __exit exit_rc_map(void)\r\n{\r\nrc_map_unregister(&technisat_usb2_map);\r\n}
