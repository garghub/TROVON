static int __init init_rc_map_pixelview(void)\r\n{\r\nreturn rc_map_register(&pixelview_map);\r\n}\r\nstatic void __exit exit_rc_map_pixelview(void)\r\n{\r\nrc_map_unregister(&pixelview_map);\r\n}
