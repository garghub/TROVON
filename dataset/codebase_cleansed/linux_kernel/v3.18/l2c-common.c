void outer_disable(void)\r\n{\r\nWARN_ON(!irqs_disabled());\r\nWARN_ON(num_online_cpus() > 1);\r\nif (outer_cache.disable)\r\nouter_cache.disable();\r\n}
