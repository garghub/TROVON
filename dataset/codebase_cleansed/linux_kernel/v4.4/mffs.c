int\r\nmffs(u32 *frD)\r\n{\r\nfrD[1] = __FPU_FPSCR;\r\n#ifdef DEBUG\r\nprintk("%s: frD %p: %08x.%08x\n", __func__, frD, frD[0], frD[1]);\r\n#endif\r\nreturn 0;\r\n}
