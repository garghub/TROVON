int is_valid_bugaddr(unsigned long eip)\r\n{\r\nunsigned short ud2;\r\nif (probe_kernel_address((unsigned short __user *)eip, ud2))\r\nreturn 0;\r\nreturn ud2 == 0x0b0f;\r\n}
