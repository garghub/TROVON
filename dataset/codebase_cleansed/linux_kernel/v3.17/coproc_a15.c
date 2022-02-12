static int __init coproc_a15_init(void)\r\n{\r\nkvm_register_target_coproc_table(&a15_target_table);\r\nreturn 0;\r\n}
