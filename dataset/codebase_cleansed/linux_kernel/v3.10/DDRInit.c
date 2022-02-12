int ddr_init(struct bcm_mini_adapter *Adapter)
{
struct bcm_ddr_setting *psDDRSetting=NULL;
ULONG RegCount=0;
UINT value = 0;
UINT uiResetValue = 0;
UINT uiClockSetting = 0;
int retval = STATUS_SUCCESS;
switch (Adapter->chip_id)
{
case 0xbece3200:
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting=asT3LP_DDRSetting80MHz;
RegCount=(sizeof(asT3LP_DDRSetting80MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_100_MHZ:
psDDRSetting=asT3LP_DDRSetting100MHz;
RegCount=(sizeof(asT3LP_DDRSetting100MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_133_MHZ:
psDDRSetting=asT3LP_DDRSetting133MHz;
RegCount=(sizeof(asT3LP_DDRSetting133MHz)/
sizeof(struct bcm_ddr_setting));
if(Adapter->bMipsConfig == MIPS_200_MHZ)
{
uiClockSetting = 0x03F13652;
}
else
{
uiClockSetting = 0x03F1365B;
}
break;
default:
return -EINVAL;
}
break;
case T3LPB:
case BCS220_2:
case BCS220_2BC:
case BCS250_BC:
case BCS220_3 :
if( (Adapter->chip_id != BCS220_2) &&
(Adapter->chip_id != BCS220_2BC) &&
(Adapter->chip_id != BCS220_3) )
{
retval= rdmalt(Adapter,(UINT)0x0f000830, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue |= 0x44;
retval = wrmalt(Adapter,(UINT)0x0f000830, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, WRM, DBG_LVL_ALL, "%s:%d WRM failed\n", __FUNCTION__, __LINE__);
return retval;
}
}
switch(Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3LPB_DDRSetting80MHz;
RegCount=(sizeof(asT3B_DDRSetting80MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_100_MHZ:
psDDRSetting=asT3LPB_DDRSetting100MHz;
RegCount=(sizeof(asT3B_DDRSetting100MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_133_MHZ:
psDDRSetting = asT3LPB_DDRSetting133MHz;
RegCount=(sizeof(asT3B_DDRSetting133MHz)/
sizeof(struct bcm_ddr_setting));
if(Adapter->bMipsConfig == MIPS_200_MHZ)
{
uiClockSetting = 0x03F13652;
}
else
{
uiClockSetting = 0x03F1365B;
}
break;
case DDR_160_MHZ:
psDDRSetting = asT3LPB_DDRSetting160MHz;
RegCount = sizeof(asT3LPB_DDRSetting160MHz)/sizeof(struct bcm_ddr_setting);
if(Adapter->bMipsConfig == MIPS_200_MHZ)
{
uiClockSetting = 0x03F137D2;
}
else
{
uiClockSetting = 0x03F137DB;
}
}
break;
case 0xbece0110:
case 0xbece0120:
case 0xbece0121:
case 0xbece0130:
case 0xbece0300:
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_INITEXIT, DRV_ENTRY, DBG_LVL_ALL, "DDR Setting: %x\n", Adapter->DDRSetting);
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3_DDRSetting80MHz;
RegCount = (sizeof(asT3_DDRSetting80MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_100_MHZ:
psDDRSetting = asT3_DDRSetting100MHz;
RegCount = (sizeof(asT3_DDRSetting100MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_133_MHZ:
psDDRSetting = asT3_DDRSetting133MHz;
RegCount = (sizeof(asT3_DDRSetting133MHz)/
sizeof(struct bcm_ddr_setting));
break;
default:
return -EINVAL;
}
case 0xbece0310:
{
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3B_DDRSetting80MHz;
RegCount=(sizeof(asT3B_DDRSetting80MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_100_MHZ:
psDDRSetting=asT3B_DDRSetting100MHz;
RegCount=(sizeof(asT3B_DDRSetting100MHz)/
sizeof(struct bcm_ddr_setting));
break;
case DDR_133_MHZ:
if(Adapter->bDPLLConfig == PLL_266_MHZ)
{
memcpy(asT3B_DDRSetting133MHz, asDPLL_266MHZ,
sizeof(asDPLL_266MHZ));
psDDRSetting = asT3B_DDRSetting133MHz;
RegCount=(sizeof(asT3B_DDRSetting133MHz)/
sizeof(struct bcm_ddr_setting));
}
else
{
psDDRSetting = asT3B_DDRSetting133MHz;
RegCount=(sizeof(asT3B_DDRSetting133MHz)/
sizeof(struct bcm_ddr_setting));
if(Adapter->bMipsConfig == MIPS_200_MHZ)
{
uiClockSetting = 0x07F13652;
}
else
{
uiClockSetting = 0x07F1365B;
}
}
break;
default:
return -EINVAL;
}
break;
}
default:
return -EINVAL;
}
value=0;
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_INITEXIT, DRV_ENTRY, DBG_LVL_ALL, "Register Count is =%lu\n", RegCount);
while(RegCount && !retval)
{
if(uiClockSetting && psDDRSetting->ulRegAddress == MIPS_CLOCK_REG)
{
value = uiClockSetting;
}
else
{
value = psDDRSetting->ulRegValue;
}
retval = wrmalt(Adapter, psDDRSetting->ulRegAddress, &value, sizeof(value));
if(STATUS_SUCCESS != retval) {
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_PRINTK, 0, 0,"%s:%d\n", __FUNCTION__, __LINE__);
break;
}
RegCount--;
psDDRSetting++;
}
if(Adapter->chip_id >= 0xbece3300 )
{
mdelay(3);
if( (Adapter->chip_id != BCS220_2)&&
(Adapter->chip_id != BCS220_2BC)&&
(Adapter->chip_id != BCS220_3))
{
uiResetValue = 0x01010001;
retval = wrmalt(Adapter, (UINT)0x0F007018, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x00040020;
retval = wrmalt(Adapter, (UINT)0x0F007094, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x01020101;
retval = wrmalt(Adapter, (UINT)0x0F00701c, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x01010000;
retval = wrmalt(Adapter, (UINT)0x0F007018, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
}
mdelay(3);
if(Adapter->PmuMode == HYBRID_MODE_7C)
{
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x1322a8;
retval = wrmalt(Adapter, (UINT)0x0f000d1c, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_PRINTK, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x132296;
retval = wrmalt(Adapter, (UINT)0x0f000d14, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
}
else if(Adapter->PmuMode == HYBRID_MODE_6 )
{
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x6003229a;
retval = wrmalt(Adapter, (UINT)0x0f000d14, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
retval = rdmalt(Adapter,(UINT)0x0f000c00, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
uiResetValue = 0x1322a8;
retval = wrmalt(Adapter, (UINT)0x0f000d1c, &uiResetValue, sizeof(uiResetValue));
if(retval < 0) {
BCM_DEBUG_PRINT(Adapter,CMHOST, RDM, DBG_LVL_ALL, "%s:%d RDM failed\n", __FUNCTION__, __LINE__);
return retval;
}
}
}
Adapter->bDDRInitDone = TRUE;
return retval;
}
int download_ddr_settings(struct bcm_mini_adapter *Adapter)
{
struct bcm_ddr_setting *psDDRSetting=NULL;
ULONG RegCount=0;
unsigned long ul_ddr_setting_load_addr = DDR_DUMP_INTERNAL_DEVICE_MEMORY;
UINT value = 0;
int retval = STATUS_SUCCESS;
BOOLEAN bOverrideSelfRefresh = FALSE;
switch (Adapter->chip_id)
{
case 0xbece3200:
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3LP_DDRSetting80MHz;
RegCount = ARRAY_SIZE(asT3LP_DDRSetting80MHz);
RegCount -= T3LP_SKIP_CLOCK_PROGRAM_DUMP_80MHZ ;
psDDRSetting += T3LP_SKIP_CLOCK_PROGRAM_DUMP_80MHZ;
break;
case DDR_100_MHZ:
psDDRSetting = asT3LP_DDRSetting100MHz;
RegCount = ARRAY_SIZE(asT3LP_DDRSetting100MHz);
RegCount -= T3LP_SKIP_CLOCK_PROGRAM_DUMP_100MHZ ;
psDDRSetting += T3LP_SKIP_CLOCK_PROGRAM_DUMP_100MHZ;
break;
case DDR_133_MHZ:
bOverrideSelfRefresh = TRUE;
psDDRSetting = asT3LP_DDRSetting133MHz;
RegCount = ARRAY_SIZE(asT3LP_DDRSetting133MHz);
RegCount -= T3LP_SKIP_CLOCK_PROGRAM_DUMP_133MHZ ;
psDDRSetting += T3LP_SKIP_CLOCK_PROGRAM_DUMP_133MHZ;
break;
default:
return -EINVAL;
}
break;
case T3LPB:
case BCS220_2:
case BCS220_2BC:
case BCS250_BC:
case BCS220_3 :
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3LPB_DDRSetting80MHz;
RegCount=ARRAY_SIZE(asT3LPB_DDRSetting80MHz);
RegCount -= T3LPB_SKIP_CLOCK_PROGRAM_DUMP_80MHZ ;
psDDRSetting += T3LPB_SKIP_CLOCK_PROGRAM_DUMP_80MHZ;
break;
case DDR_100_MHZ:
psDDRSetting = asT3LPB_DDRSetting100MHz;
RegCount = ARRAY_SIZE(asT3LPB_DDRSetting100MHz);
RegCount -= T3LPB_SKIP_CLOCK_PROGRAM_DUMP_100MHZ ;
psDDRSetting += T3LPB_SKIP_CLOCK_PROGRAM_DUMP_100MHZ;
break;
case DDR_133_MHZ:
bOverrideSelfRefresh = TRUE;
psDDRSetting = asT3LPB_DDRSetting133MHz;
RegCount = ARRAY_SIZE(asT3LPB_DDRSetting133MHz);
RegCount -= T3LPB_SKIP_CLOCK_PROGRAM_DUMP_133MHZ ;
psDDRSetting += T3LPB_SKIP_CLOCK_PROGRAM_DUMP_133MHZ;
break;
case DDR_160_MHZ:
bOverrideSelfRefresh = TRUE;
psDDRSetting = asT3LPB_DDRSetting160MHz;
RegCount = ARRAY_SIZE(asT3LPB_DDRSetting160MHz);
RegCount -= T3LPB_SKIP_CLOCK_PROGRAM_DUMP_160MHZ;
psDDRSetting += T3LPB_SKIP_CLOCK_PROGRAM_DUMP_160MHZ;
break;
default:
return -EINVAL;
}
break;
case 0xbece0300:
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3_DDRSetting80MHz;
RegCount = ARRAY_SIZE(asT3_DDRSetting80MHz);
RegCount-=T3_SKIP_CLOCK_PROGRAM_DUMP_80MHZ ;
psDDRSetting += T3_SKIP_CLOCK_PROGRAM_DUMP_80MHZ;
break;
case DDR_100_MHZ:
psDDRSetting = asT3_DDRSetting100MHz;
RegCount = ARRAY_SIZE(asT3_DDRSetting100MHz);
RegCount-=T3_SKIP_CLOCK_PROGRAM_DUMP_100MHZ ;
psDDRSetting += T3_SKIP_CLOCK_PROGRAM_DUMP_100MHZ;
break;
case DDR_133_MHZ:
psDDRSetting = asT3_DDRSetting133MHz;
RegCount = ARRAY_SIZE(asT3_DDRSetting133MHz);
RegCount-=T3_SKIP_CLOCK_PROGRAM_DUMP_133MHZ ;
psDDRSetting += T3_SKIP_CLOCK_PROGRAM_DUMP_133MHZ ;
break;
default:
return -EINVAL;
}
break;
case 0xbece0310:
{
switch (Adapter->DDRSetting)
{
case DDR_80_MHZ:
psDDRSetting = asT3B_DDRSetting80MHz;
RegCount = ARRAY_SIZE(asT3B_DDRSetting80MHz);
RegCount -= T3B_SKIP_CLOCK_PROGRAM_DUMP_80MHZ ;
psDDRSetting += T3B_SKIP_CLOCK_PROGRAM_DUMP_80MHZ;
break;
case DDR_100_MHZ:
psDDRSetting = asT3B_DDRSetting100MHz;
RegCount = ARRAY_SIZE(asT3B_DDRSetting100MHz);
RegCount -= T3B_SKIP_CLOCK_PROGRAM_DUMP_100MHZ ;
psDDRSetting += T3B_SKIP_CLOCK_PROGRAM_DUMP_100MHZ;
break;
case DDR_133_MHZ:
bOverrideSelfRefresh = TRUE;
psDDRSetting = asT3B_DDRSetting133MHz;
RegCount = ARRAY_SIZE(asT3B_DDRSetting133MHz);
RegCount -= T3B_SKIP_CLOCK_PROGRAM_DUMP_133MHZ ;
psDDRSetting += T3B_SKIP_CLOCK_PROGRAM_DUMP_133MHZ;
break;
}
break;
}
default:
return -EINVAL;
}
value =RegCount ;
retval = wrmalt(Adapter, ul_ddr_setting_load_addr, &value, sizeof(value));
if(retval)
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_PRINTK, 0, 0,"%s:%d\n", __FUNCTION__, __LINE__);
return retval;
}
ul_ddr_setting_load_addr+=sizeof(ULONG);
value =(0x1d1e0dd0);
retval = wrmalt(Adapter, ul_ddr_setting_load_addr, &value, sizeof(value));
if(retval)
{
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_PRINTK, 0, 0,"%s:%d\n", __FUNCTION__, __LINE__);
return retval;
}
ul_ddr_setting_load_addr+=sizeof(ULONG);
RegCount*=(sizeof(struct bcm_ddr_setting)/sizeof(ULONG));
while(RegCount && !retval)
{
value = psDDRSetting->ulRegAddress ;
retval = wrmalt( Adapter, ul_ddr_setting_load_addr, &value, sizeof(value));
ul_ddr_setting_load_addr+=sizeof(ULONG);
if(!retval)
{
if(bOverrideSelfRefresh && (psDDRSetting->ulRegAddress == 0x0F007018))
{
value = (psDDRSetting->ulRegValue |(1<<8));
if(STATUS_SUCCESS != wrmalt(Adapter, ul_ddr_setting_load_addr,
&value, sizeof(value))){
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_PRINTK, 0, 0,"%s:%d\n", __FUNCTION__, __LINE__);
break;
}
}
else
{
value = psDDRSetting->ulRegValue;
if(STATUS_SUCCESS != wrmalt(Adapter, ul_ddr_setting_load_addr ,
&value, sizeof(value))){
BCM_DEBUG_PRINT(Adapter,DBG_TYPE_PRINTK, 0, 0,"%s:%d\n", __FUNCTION__, __LINE__);
break;
}
}
}
ul_ddr_setting_load_addr+=sizeof(ULONG);
RegCount--;
psDDRSetting++;
}
return retval;
}
