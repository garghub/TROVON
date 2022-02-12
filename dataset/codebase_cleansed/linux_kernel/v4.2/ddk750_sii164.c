unsigned short sii164GetVendorID(void)
{
unsigned short vendorID;
vendorID = ((unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_VENDOR_ID_HIGH) << 8) |
(unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_VENDOR_ID_LOW);
return vendorID;
}
unsigned short sii164GetDeviceID(void)
{
unsigned short deviceID;
deviceID = ((unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_DEVICE_ID_HIGH) << 8) |
(unsigned short) i2cReadReg(SII164_I2C_ADDRESS, SII164_DEVICE_ID_LOW);
return deviceID;
}
long sii164InitChip(
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
unsigned char config;
#ifdef USE_HW_I2C
hwI2CInit(1);
#else
swI2CInit(DEFAULT_I2C_SCL, DEFAULT_I2C_SDA);
#endif
if ((sii164GetVendorID() == SII164_VENDOR_ID) && (sii164GetDeviceID() == SII164_DEVICE_ID))
{
if (edgeSelect == 0)
config = SII164_CONFIGURATION_LATCH_FALLING;
else
config = SII164_CONFIGURATION_LATCH_RISING;
if (busSelect == 0)
config |= SII164_CONFIGURATION_BUS_12BITS;
else
config |= SII164_CONFIGURATION_BUS_24BITS;
if (dualEdgeClkSelect == 0)
config |= SII164_CONFIGURATION_CLOCK_SINGLE;
else
config |= SII164_CONFIGURATION_CLOCK_DUAL;
if (hsyncEnable == 0)
config |= SII164_CONFIGURATION_HSYNC_FORCE_LOW;
else
config |= SII164_CONFIGURATION_HSYNC_AS_IS;
if (vsyncEnable == 0)
config |= SII164_CONFIGURATION_VSYNC_FORCE_LOW;
else
config |= SII164_CONFIGURATION_VSYNC_AS_IS;
i2cWriteReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION, config);
if (deskewEnable == 0)
config = SII164_DESKEW_DISABLE;
else
config = SII164_DESKEW_ENABLE;
switch (deskewSetting)
{
case 0:
config |= SII164_DESKEW_1_STEP;
break;
case 1:
config |= SII164_DESKEW_2_STEP;
break;
case 2:
config |= SII164_DESKEW_3_STEP;
break;
case 3:
config |= SII164_DESKEW_4_STEP;
break;
case 4:
config |= SII164_DESKEW_5_STEP;
break;
case 5:
config |= SII164_DESKEW_6_STEP;
break;
case 6:
config |= SII164_DESKEW_7_STEP;
break;
case 7:
config |= SII164_DESKEW_8_STEP;
break;
}
i2cWriteReg(SII164_I2C_ADDRESS, SII164_DESKEW, config);
if (continuousSyncEnable == 0)
config = SII164_PLL_FILTER_SYNC_CONTINUOUS_DISABLE;
else
config = SII164_PLL_FILTER_SYNC_CONTINUOUS_ENABLE;
if (pllFilterEnable == 0)
config |= SII164_PLL_FILTER_DISABLE;
else
config |= SII164_PLL_FILTER_ENABLE;
config |= ((pllFilterValue & 0x07) << 1);
i2cWriteReg(SII164_I2C_ADDRESS, SII164_PLL, config);
config = i2cReadReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION);
config |= SII164_CONFIGURATION_POWER_NORMAL;
i2cWriteReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION, config);
return 0;
}
return (-1);
}
void sii164ResetChip(void)
{
sii164SetPower(0);
sii164SetPower(1);
}
char *sii164GetChipString(void)
{
return gDviCtrlChipName;
}
void sii164SetPower(
unsigned char powerUp
)
{
unsigned char config;
config = i2cReadReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION);
if (powerUp == 1)
{
config &= ~SII164_CONFIGURATION_POWER_MASK;
config |= SII164_CONFIGURATION_POWER_NORMAL;
i2cWriteReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION, config);
}
else
{
config &= ~SII164_CONFIGURATION_POWER_MASK;
config |= SII164_CONFIGURATION_POWER_DOWN;
i2cWriteReg(SII164_I2C_ADDRESS, SII164_CONFIGURATION, config);
}
}
static void sii164SelectHotPlugDetectionMode(
sii164_hot_plug_mode_t hotPlugMode
)
{
unsigned char detectReg;
detectReg = i2cReadReg(SII164_I2C_ADDRESS, SII164_DETECT) & ~SII164_DETECT_MONITOR_SENSE_OUTPUT_FLAG;
switch (hotPlugMode)
{
case SII164_HOTPLUG_DISABLE:
detectReg |= SII164_DETECT_MONITOR_SENSE_OUTPUT_HIGH;
break;
case SII164_HOTPLUG_USE_MDI:
detectReg &= ~SII164_DETECT_INTERRUPT_MASK;
detectReg |= SII164_DETECT_INTERRUPT_BY_HTPLG_PIN;
detectReg |= SII164_DETECT_MONITOR_SENSE_OUTPUT_MDI;
break;
case SII164_HOTPLUG_USE_RSEN:
detectReg |= SII164_DETECT_MONITOR_SENSE_OUTPUT_RSEN;
break;
case SII164_HOTPLUG_USE_HTPLG:
detectReg |= SII164_DETECT_MONITOR_SENSE_OUTPUT_HTPLG;
break;
}
i2cWriteReg(SII164_I2C_ADDRESS, SII164_DETECT, detectReg);
}
void sii164EnableHotPlugDetection(
unsigned char enableHotPlug
)
{
unsigned char detectReg;
detectReg = i2cReadReg(SII164_I2C_ADDRESS, SII164_DETECT);
if (enableHotPlug != 0)
sii164SelectHotPlugDetectionMode(SII164_HOTPLUG_USE_MDI);
else
sii164SelectHotPlugDetectionMode(SII164_HOTPLUG_DISABLE);
}
unsigned char sii164IsConnected(void)
{
unsigned char hotPlugValue;
hotPlugValue = i2cReadReg(SII164_I2C_ADDRESS, SII164_DETECT) & SII164_DETECT_HOT_PLUG_STATUS_MASK;
if (hotPlugValue == SII164_DETECT_HOT_PLUG_STATUS_ON)
return 1;
else
return 0;
}
unsigned char sii164CheckInterrupt(void)
{
unsigned char detectReg;
detectReg = i2cReadReg(SII164_I2C_ADDRESS, SII164_DETECT) & SII164_DETECT_MONITOR_STATE_MASK;
if (detectReg == SII164_DETECT_MONITOR_STATE_CHANGE)
return 1;
else
return 0;
}
void sii164ClearInterrupt(void)
{
unsigned char detectReg;
detectReg = i2cReadReg(SII164_I2C_ADDRESS, SII164_DETECT);
i2cWriteReg(SII164_I2C_ADDRESS, SII164_DETECT, detectReg | SII164_DETECT_MONITOR_STATE_CLEAR);
}
