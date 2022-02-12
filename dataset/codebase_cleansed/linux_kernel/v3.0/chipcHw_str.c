const char *chipcHw_getGpioPinFunctionStr(int pin)
{
if ((pin < 0) || (pin >= chipcHw_GPIO_COUNT)) {
return "";
}
return gMuxStr[chipcHw_getGpioPinFunction(pin)];
}
