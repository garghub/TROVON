asmlinkage long sys_arm_fadvise64_64(int fd, int advice,\r\nloff_t offset, loff_t len)\r\n{\r\nreturn sys_fadvise64_64(fd, offset, len, advice);\r\n}
