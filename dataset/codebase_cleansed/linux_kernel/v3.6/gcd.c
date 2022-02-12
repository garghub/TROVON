unsigned long gcd(unsigned long a, unsigned long b)\r\n{\r\nunsigned long r;\r\nif (a < b)\r\nswap(a, b);\r\nwhile ((r = a % b) != 0) {\r\na = b;\r\nb = r;\r\n}\r\nreturn b;\r\n}
