static int __init init_rc_map_streamzap(void)\r\n{\r\nreturn rc_map_register(&streamzap_map);\r\n}\r\nstatic void __exit exit_rc_map_streamzap(void)\r\n{\r\nrc_map_unregister(&streamzap_map);\r\n}
