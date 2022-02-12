static int __init init_rc_map_flyvideo(void)\r\n{\r\nreturn rc_map_register(&flyvideo_map);\r\n}\r\nstatic void __exit exit_rc_map_flyvideo(void)\r\n{\r\nrc_map_unregister(&flyvideo_map);\r\n}
