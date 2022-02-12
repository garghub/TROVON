unsigned long lcm(unsigned long a, unsigned long b)\r\n{\r\nif (a && b)\r\nreturn (a * b) / gcd(a, b);\r\nelse if (b)\r\nreturn b;\r\nreturn a;\r\n}
