int dviInit(
unsigned char edgeSelect,
unsigned char busSelect,
unsigned char dualEdgeClkSelect,
unsigned char hsyncEnable,
unsigned char vsyncEnable,
unsigned char deskewEnable,
unsigned char deskewSetting,
unsigned char continuousSyncEnable,
unsigned char pllFilterEnable,
unsigned char pllFilterValue
)
{
dvi_ctrl_device_t *pCurrentDviCtrl;
pCurrentDviCtrl = g_dcftSupportedDviController;
if (pCurrentDviCtrl->pfnInit != NULL) {
return pCurrentDviCtrl->pfnInit(edgeSelect, busSelect, dualEdgeClkSelect, hsyncEnable,
vsyncEnable, deskewEnable, deskewSetting, continuousSyncEnable,
pllFilterEnable, pllFilterValue);
}
return -1;
}
unsigned short dviGetVendorID(void)
{
dvi_ctrl_device_t *pCurrentDviCtrl;
pCurrentDviCtrl = g_dcftSupportedDviController;
if (pCurrentDviCtrl != (dvi_ctrl_device_t *)0)
return pCurrentDviCtrl->pfnGetVendorId();
return 0x0000;
}
unsigned short dviGetDeviceID(void)
{
dvi_ctrl_device_t *pCurrentDviCtrl;
pCurrentDviCtrl = g_dcftSupportedDviController;
if (pCurrentDviCtrl != (dvi_ctrl_device_t *)0)
return pCurrentDviCtrl->pfnGetDeviceId();
return 0x0000;
}
