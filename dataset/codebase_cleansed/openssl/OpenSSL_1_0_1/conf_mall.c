void OPENSSL_load_builtin_modules(void)\r\n{\r\nASN1_add_oid_module();\r\n#ifndef OPENSSL_NO_ENGINE\r\nENGINE_add_conf_module();\r\n#endif\r\n}
