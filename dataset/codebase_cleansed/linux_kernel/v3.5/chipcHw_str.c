const char *chipcHw_getGpioPinFunctionStr(int pin)\r\n{\r\nif ((pin < 0) || (pin >= chipcHw_GPIO_COUNT)) {\r\nreturn "";\r\n}\r\nreturn gMuxStr[chipcHw_getGpioPinFunction(pin)];\r\n}
