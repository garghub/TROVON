void cs5536_pci_conf_write4(int function, int reg, u32 value)
{
if ((function <= CS5536_FUNC_START) || (function >= CS5536_FUNC_END))
return;
if ((reg < 0) || (reg > 0x100) || ((reg & 0x03) != 0))
return;
if (vsm_conf_write[function] != NULL)
vsm_conf_write[function](reg, value);
}
u32 cs5536_pci_conf_read4(int function, int reg)
{
u32 data = 0;
if ((function <= CS5536_FUNC_START) || (function >= CS5536_FUNC_END))
return 0;
if ((reg < 0) || ((reg & 0x03) != 0))
return 0;
if (reg > 0x100)
return 0xffffffff;
if (vsm_conf_read[function] != NULL)
data = vsm_conf_read[function](reg);
return data;
}
