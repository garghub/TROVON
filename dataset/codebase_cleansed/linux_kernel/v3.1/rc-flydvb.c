static int __init init_rc_map_flydvb(void)\r\n{\r\nreturn rc_map_register(&flydvb_map);\r\n}\r\nstatic void __exit exit_rc_map_flydvb(void)\r\n{\r\nrc_map_unregister(&flydvb_map);\r\n}
