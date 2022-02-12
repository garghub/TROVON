int fre(void *frD, void *frB)\r\n{\r\n#ifdef DEBUG\r\nprintk("%s: %p %p\n", __func__, frD, frB);\r\n#endif\r\nreturn -ENOSYS;\r\n}
