int InterfaceIdleModeRespond(struct bcm_mini_adapter *Adapter,
unsigned int *puiBuffer)
{
int status = STATUS_SUCCESS;
unsigned int uiRegRead = 0;
int bytes;
if (ntohl(*puiBuffer) == GO_TO_IDLE_MODE_PAYLOAD) {
if (ntohl(*(puiBuffer+1)) == 0) {
status = wrmalt(Adapter, SW_ABORT_IDLEMODE_LOC,
&uiRegRead, sizeof(uiRegRead));
if (status)
return status;
if (Adapter->ulPowerSaveMode ==
DEVICE_POWERSAVE_MODE_AS_MANUAL_CLOCK_GATING) {
uiRegRead = 0x00000000;
status = wrmalt(Adapter,
DEBUG_INTERRUPT_GENERATOR_REGISTOR,
&uiRegRead, sizeof(uiRegRead));
if (status)
return status;
}
else if (Adapter->ulPowerSaveMode !=
DEVICE_POWERSAVE_MODE_AS_PROTOCOL_IDLE_MODE) {
bytes = rdmalt(Adapter, DEVICE_INT_OUT_EP_REG0,
&uiRegRead, sizeof(uiRegRead));
if (bytes < 0) {
status = bytes;
return status;
}
bytes = rdmalt(Adapter, DEVICE_INT_OUT_EP_REG1,
&uiRegRead, sizeof(uiRegRead));
if (bytes < 0) {
status = bytes;
return status;
}
}
Adapter->IdleMode = false;
Adapter->bTriedToWakeUpFromlowPowerMode = false;
wake_up(&Adapter->lowpower_mode_wait_queue);
} else {
if (TRUE == Adapter->IdleMode)
return status;
uiRegRead = 0;
if (Adapter->chip_id == BCS220_2 ||
Adapter->chip_id == BCS220_2BC ||
Adapter->chip_id == BCS250_BC ||
Adapter->chip_id == BCS220_3) {
bytes = rdmalt(Adapter, HPM_CONFIG_MSW,
&uiRegRead, sizeof(uiRegRead));
if (bytes < 0) {
status = bytes;
return status;
}
uiRegRead |= (1<<17);
status = wrmalt(Adapter, HPM_CONFIG_MSW,
&uiRegRead, sizeof(uiRegRead));
if (status)
return status;
}
SendIdleModeResponse(Adapter);
}
} else if (ntohl(*puiBuffer) == IDLE_MODE_SF_UPDATE_MSG) {
OverrideServiceFlowParams(Adapter, puiBuffer);
}
return status;
}
static int InterfaceAbortIdlemode(struct bcm_mini_adapter *Adapter,
unsigned int Pattern)
{
int status = STATUS_SUCCESS;
unsigned int value;
unsigned int chip_id;
unsigned long timeout = 0, itr = 0;
int lenwritten = 0;
unsigned char aucAbortPattern[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF};
struct bcm_interface_adapter *psInterfaceAdapter =
Adapter->pvInterfaceAdapter;
if ((TRUE == psInterfaceAdapter->bSuspended) &&
(TRUE == Adapter->bDoSuspend))
status = usb_autopm_get_interface(
psInterfaceAdapter->interface);
if ((Adapter->ulPowerSaveMode ==
DEVICE_POWERSAVE_MODE_AS_MANUAL_CLOCK_GATING) ||
(Adapter->ulPowerSaveMode ==
DEVICE_POWERSAVE_MODE_AS_PROTOCOL_IDLE_MODE)) {
status = wrmalt(Adapter, SW_ABORT_IDLEMODE_LOC,
&Pattern, sizeof(Pattern));
if (status)
return status;
}
if (Adapter->ulPowerSaveMode ==
DEVICE_POWERSAVE_MODE_AS_MANUAL_CLOCK_GATING) {
value = 0x80000000;
status = wrmalt(Adapter,
DEBUG_INTERRUPT_GENERATOR_REGISTOR,
&value, sizeof(value));
if (status)
return status;
} else if (Adapter->ulPowerSaveMode !=
DEVICE_POWERSAVE_MODE_AS_PROTOCOL_IDLE_MODE) {
status = usb_interrupt_msg(psInterfaceAdapter->udev,
usb_sndintpipe(psInterfaceAdapter->udev,
psInterfaceAdapter->sIntrOut.int_out_endpointAddr),
aucAbortPattern,
8,
&lenwritten,
5000);
if (status)
return status;
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
IDLE_MODE, DBG_LVL_ALL,
"NOB Sent down :%d", lenwritten);
timeout = jiffies + msecs_to_jiffies(50);
while (time_after(timeout, jiffies)) {
itr++;
rdmalt(Adapter, CHIP_ID_REG, &chip_id, sizeof(UINT));
if (0xbece3200 == (chip_id&~(0xF0)))
chip_id = chip_id&~(0xF0);
if (chip_id == Adapter->chip_id)
break;
}
if (time_before(timeout, jiffies))
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
IDLE_MODE, DBG_LVL_ALL,
"Not able to read chip-id even after 25 msec");
else
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
IDLE_MODE, DBG_LVL_ALL,
"Number of completed iteration to read chip-id :%lu", itr);
status = wrmalt(Adapter, SW_ABORT_IDLEMODE_LOC,
&Pattern, sizeof(status));
if (status)
return status;
}
return status;
}
int InterfaceIdleModeWakeup(struct bcm_mini_adapter *Adapter)
{
if (Adapter->bTriedToWakeUpFromlowPowerMode) {
BCM_DEBUG_PRINT(Adapter, DBG_TYPE_OTHERS,
IDLE_MODE, DBG_LVL_ALL,
"Wake up already attempted.. ignoring\n");
} else {
Adapter->bTriedToWakeUpFromlowPowerMode = TRUE;
InterfaceAbortIdlemode(Adapter, Adapter->usIdleModePattern);
}
return 0;
}
void InterfaceHandleShutdownModeWakeup(struct bcm_mini_adapter *Adapter)
{
unsigned int uiRegVal = 0;
INT Status = 0;
int bytes;
if (Adapter->ulPowerSaveMode ==
DEVICE_POWERSAVE_MODE_AS_MANUAL_CLOCK_GATING) {
uiRegVal = 0;
Status = wrmalt(Adapter,
DEBUG_INTERRUPT_GENERATOR_REGISTOR,
&uiRegVal, sizeof(uiRegVal));
if (Status)
return;
}
else {
bytes = rdmalt(Adapter,
DEVICE_INT_OUT_EP_REG0,
&uiRegVal, sizeof(uiRegVal));
if (bytes < 0) {
Status = bytes;
return;
}
bytes = rdmalt(Adapter,
DEVICE_INT_OUT_EP_REG1,
&uiRegVal, sizeof(uiRegVal));
if (bytes < 0) {
Status = bytes;
return;
}
}
}
