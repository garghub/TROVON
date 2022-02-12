int __init hypervisor_init(void)\r\n{\r\nhypervisor_kobj = kobject_create_and_add("hypervisor", NULL);\r\nif (!hypervisor_kobj)\r\nreturn -ENOMEM;\r\nreturn 0;\r\n}
