int\r\nstfiwx(u32 *frS, void *ea)\r\n{\r\n#ifdef DEBUG\r\nprintk("%s: %p %p\n", __func__, frS, ea);\r\n#endif\r\nif (copy_to_user(ea, &frS[1], sizeof(frS[1])))\r\nreturn -EFAULT;\r\nreturn 0;\r\n}
