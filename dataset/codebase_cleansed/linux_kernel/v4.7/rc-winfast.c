static int __init init_rc_map_winfast(void)\r\n{\r\nreturn rc_map_register(&winfast_map);\r\n}\r\nstatic void __exit exit_rc_map_winfast(void)\r\n{\r\nrc_map_unregister(&winfast_map);\r\n}
