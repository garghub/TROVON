static int __init init_rc_map_imon_pad(void)\r\n{\r\nreturn rc_map_register(&imon_pad_map);\r\n}\r\nstatic void __exit exit_rc_map_imon_pad(void)\r\n{\r\nrc_map_unregister(&imon_pad_map);\r\n}
