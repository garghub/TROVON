void dm_kobject_release(struct kobject *kobj)\r\n{\r\ncomplete(dm_get_completion_from_kobject(kobj));\r\n}
