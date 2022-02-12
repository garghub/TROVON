static int __init init_rc_map_behold(void)\r\n{\r\nreturn rc_map_register(&behold_map);\r\n}\r\nstatic void __exit exit_rc_map_behold(void)\r\n{\r\nrc_map_unregister(&behold_map);\r\n}
