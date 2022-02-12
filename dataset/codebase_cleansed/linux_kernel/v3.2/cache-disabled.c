asmlinkage long sys_cacheflush(unsigned long start, unsigned long end)\r\n{\r\nif (end < start)\r\nreturn -EINVAL;\r\nreturn 0;\r\n}
