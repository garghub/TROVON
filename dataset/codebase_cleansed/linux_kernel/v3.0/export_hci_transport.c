int ar6000_register_hci_transport(struct hci_transport_callbacks *hciTransCallbacks)
{
ar6kHciTransCallbacks = *hciTransCallbacks;
_HCI_TransportAttach = HCI_TransportAttach;
_HCI_TransportDetach = HCI_TransportDetach;
_HCI_TransportAddReceivePkts = HCI_TransportAddReceivePkts;
_HCI_TransportSendPkt = HCI_TransportSendPkt;
_HCI_TransportStop = HCI_TransportStop;
_HCI_TransportStart = HCI_TransportStart;
_HCI_TransportEnableDisableAsyncRecv = HCI_TransportEnableDisableAsyncRecv;
_HCI_TransportRecvHCIEventSync = HCI_TransportRecvHCIEventSync;
_HCI_TransportSetBaudRate = HCI_TransportSetBaudRate;
_HCI_TransportEnablePowerMgmt = HCI_TransportEnablePowerMgmt;
return 0;
}
int
ar6000_get_hif_dev(struct hif_device *device, void *config)
{
int status;
status = HIFConfigureDevice(device,
HIF_DEVICE_GET_OS_DEVICE,
(struct hif_device_os_device_info *)config,
sizeof(struct hif_device_os_device_info));
return status;
}
int ar6000_set_uart_config(struct hif_device *hifDevice,
u32 scale,
u32 step)
{
u32 regAddress;
u32 regVal;
int status;
regAddress = WLAN_UART_BASE_ADDRESS | UART_CLKDIV_ADDRESS;
regVal = ((u32)scale << 16) | step;
status = ar6000_WriteRegDiag(hifDevice, &regAddress, &regVal);
return status;
}
int ar6000_get_core_clock_config(struct hif_device *hifDevice, u32 *data)
{
u32 regAddress;
int status;
regAddress = WLAN_RTC_BASE_ADDRESS | WLAN_CPU_CLOCK_ADDRESS;
status = ar6000_ReadRegDiag(hifDevice, &regAddress, data);
return status;
}
