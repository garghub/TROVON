int
sisfb_mode_rate_to_dclock(struct SiS_Private *SiS_Pr, unsigned char modeno,
unsigned char rateindex)
{
unsigned short ModeNo = modeno;
unsigned short ModeIdIndex = 0, ClockIndex = 0;
unsigned short RRTI = 0;
int Clock;
if(!SiSInitPtr(SiS_Pr)) return 65000;
if(rateindex > 0) rateindex--;
#ifdef CONFIG_FB_SIS_315
switch(ModeNo) {
case 0x5a: ModeNo = 0x50; break;
case 0x5b: ModeNo = 0x56;
}
#endif
if(!(SiS_SearchModeID(SiS_Pr, &ModeNo, &ModeIdIndex))) {
printk(KERN_ERR "Could not find mode %x\n", ModeNo);
return 65000;
}
RRTI = SiS_Pr->SiS_EModeIDTable[ModeIdIndex].REFindex;
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & HaveWideTiming) {
if(SiS_Pr->SiS_UseWide == 1) {
ClockIndex = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRTVCLK_WIDE;
} else {
RRTI += rateindex;
ClockIndex = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRTVCLK_NORM;
}
} else {
RRTI += rateindex;
ClockIndex = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRTVCLK;
}
Clock = SiS_Pr->SiS_VCLKData[ClockIndex].CLOCK * 1000;
return Clock;
}
int
sisfb_mode_rate_to_ddata(struct SiS_Private *SiS_Pr, unsigned char modeno,
unsigned char rateindex, struct fb_var_screeninfo *var)
{
unsigned short ModeNo = modeno;
unsigned short ModeIdIndex = 0, index = 0, RRTI = 0;
int j;
if(!SiSInitPtr(SiS_Pr)) return 0;
if(rateindex > 0) rateindex--;
#ifdef CONFIG_FB_SIS_315
switch(ModeNo) {
case 0x5a: ModeNo = 0x50; break;
case 0x5b: ModeNo = 0x56;
}
#endif
if(!(SiS_SearchModeID(SiS_Pr, &ModeNo, &ModeIdIndex))) return 0;
RRTI = SiS_Pr->SiS_EModeIDTable[ModeIdIndex].REFindex;
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & HaveWideTiming) {
if(SiS_Pr->SiS_UseWide == 1) {
index = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRT1CRTC_WIDE;
} else {
RRTI += rateindex;
index = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRT1CRTC_NORM;
}
} else {
RRTI += rateindex;
index = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRT1CRTC;
}
SiS_Generic_ConvertCRData(SiS_Pr,
(unsigned char *)&SiS_Pr->SiS_CRT1Table[index].CR[0],
SiS_Pr->SiS_RefIndex[RRTI].XRes,
SiS_Pr->SiS_RefIndex[RRTI].YRes,
var, false);
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & 0x8000)
var->sync &= ~FB_SYNC_VERT_HIGH_ACT;
else
var->sync |= FB_SYNC_VERT_HIGH_ACT;
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & 0x4000)
var->sync &= ~FB_SYNC_HOR_HIGH_ACT;
else
var->sync |= FB_SYNC_HOR_HIGH_ACT;
var->vmode = FB_VMODE_NONINTERLACED;
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & 0x0080)
var->vmode = FB_VMODE_INTERLACED;
else {
j = 0;
while(SiS_Pr->SiS_EModeIDTable[j].Ext_ModeID != 0xff) {
if(SiS_Pr->SiS_EModeIDTable[j].Ext_ModeID ==
SiS_Pr->SiS_RefIndex[RRTI].ModeID) {
if(SiS_Pr->SiS_EModeIDTable[j].Ext_ModeFlag & DoubleScanMode) {
var->vmode = FB_VMODE_DOUBLE;
}
break;
}
j++;
}
}
if((var->vmode & FB_VMODE_MASK) == FB_VMODE_INTERLACED) {
#if 0
var->upper_margin <<= 1;
var->lower_margin <<= 1;
var->vsync_len <<= 1;
#endif
} else if((var->vmode & FB_VMODE_MASK) == FB_VMODE_DOUBLE) {
var->upper_margin >>= 1;
var->lower_margin >>= 1;
var->vsync_len >>= 1;
}
return 1;
}
bool
sisfb_gettotalfrommode(struct SiS_Private *SiS_Pr, unsigned char modeno, int *htotal,
int *vtotal, unsigned char rateindex)
{
unsigned short ModeNo = modeno;
unsigned short ModeIdIndex = 0, CRT1Index = 0;
unsigned short RRTI = 0;
unsigned char sr_data, cr_data, cr_data2;
if(!SiSInitPtr(SiS_Pr)) return false;
if(rateindex > 0) rateindex--;
#ifdef CONFIG_FB_SIS_315
switch(ModeNo) {
case 0x5a: ModeNo = 0x50; break;
case 0x5b: ModeNo = 0x56;
}
#endif
if(!(SiS_SearchModeID(SiS_Pr, &ModeNo, &ModeIdIndex))) return false;
RRTI = SiS_Pr->SiS_EModeIDTable[ModeIdIndex].REFindex;
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & HaveWideTiming) {
if(SiS_Pr->SiS_UseWide == 1) {
CRT1Index = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRT1CRTC_WIDE;
} else {
RRTI += rateindex;
CRT1Index = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRT1CRTC_NORM;
}
} else {
RRTI += rateindex;
CRT1Index = SiS_Pr->SiS_RefIndex[RRTI].Ext_CRT1CRTC;
}
sr_data = SiS_Pr->SiS_CRT1Table[CRT1Index].CR[14];
cr_data = SiS_Pr->SiS_CRT1Table[CRT1Index].CR[0];
*htotal = (((cr_data & 0xff) | ((unsigned short) (sr_data & 0x03) << 8)) + 5) * 8;
sr_data = SiS_Pr->SiS_CRT1Table[CRT1Index].CR[13];
cr_data = SiS_Pr->SiS_CRT1Table[CRT1Index].CR[6];
cr_data2 = SiS_Pr->SiS_CRT1Table[CRT1Index].CR[7];
*vtotal = ((cr_data & 0xFF) |
((unsigned short)(cr_data2 & 0x01) << 8) |
((unsigned short)(cr_data2 & 0x20) << 4) |
((unsigned short)(sr_data & 0x01) << 10)) + 2;
if(SiS_Pr->SiS_RefIndex[RRTI].Ext_InfoFlag & InterlaceMode)
*vtotal *= 2;
return true;
}
