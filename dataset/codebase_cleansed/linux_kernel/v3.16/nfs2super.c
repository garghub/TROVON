static int __init init_nfs_v2(void)\r\n{\r\nregister_nfs_version(&nfs_v2);\r\nreturn 0;\r\n}\r\nstatic void __exit exit_nfs_v2(void)\r\n{\r\nunregister_nfs_version(&nfs_v2);\r\n}
