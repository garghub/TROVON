int __init tegra114_cpuidle_init(void)\r\n{\r\nreturn cpuidle_register(&tegra_idle_driver, NULL);\r\n}
