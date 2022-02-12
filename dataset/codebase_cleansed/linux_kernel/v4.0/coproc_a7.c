static int __init coproc_a7_init(void)\r\n{\r\nkvm_register_target_coproc_table(&a7_target_table);\r\nreturn 0;\r\n}
