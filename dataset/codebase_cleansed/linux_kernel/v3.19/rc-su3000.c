static int __init init_rc_map_su3000(void)\r\n{\r\nreturn rc_map_register(&su3000_map);\r\n}\r\nstatic void __exit exit_rc_map_su3000(void)\r\n{\r\nrc_map_unregister(&su3000_map);\r\n}
