static int __init init_rc_map_purpletv(void)\r\n{\r\nreturn rc_map_register(&purpletv_map);\r\n}\r\nstatic void __exit exit_rc_map_purpletv(void)\r\n{\r\nrc_map_unregister(&purpletv_map);\r\n}
