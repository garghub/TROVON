static int __init init_rc_map_eztv(void)\r\n{\r\nreturn rc_map_register(&eztv_map);\r\n}\r\nstatic void __exit exit_rc_map_eztv(void)\r\n{\r\nrc_map_unregister(&eztv_map);\r\n}
