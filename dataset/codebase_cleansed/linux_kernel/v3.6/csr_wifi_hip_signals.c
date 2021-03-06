s32 SigGetSize(const CSR_SIGNAL *aSignal)
{
switch (aSignal->SignalPrimitiveHeader.SignalId)
{
case CSR_MA_PACKET_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_PACKET_REQUEST);
case CSR_MA_PACKET_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_PACKET_CONFIRM);
case CSR_MA_PACKET_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_PACKET_INDICATION);
case CSR_MA_PACKET_CANCEL_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_PACKET_CANCEL_REQUEST);
case CSR_MA_VIF_AVAILABILITY_RESPONSE_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_VIF_AVAILABILITY_RESPONSE);
case CSR_MA_VIF_AVAILABILITY_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_VIF_AVAILABILITY_INDICATION);
case CSR_MA_PACKET_ERROR_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MA_PACKET_ERROR_INDICATION);
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_RESET_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_RESET_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_RESET_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_RESET_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_GET_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_GET_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_NEXT_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_GET_NEXT_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_NEXT_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_GET_NEXT_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_POWERMGT_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_POWERMGT_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_POWERMGT_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_POWERMGT_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SCAN_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SCAN_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_HL_SYNC_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_HL_SYNC_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_MEASURE_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_MEASURE_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_MEASURE_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SETKEYS_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SETKEYS_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SETKEYS_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SETKEYS_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DELETEKEYS_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DELETEKEYS_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DELETEKEYS_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DELETEKEYS_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_AUTONOMOUS_SCAN_LOSS_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_AUTONOMOUS_SCAN_LOSS_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECTED_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_CONNECTED_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_CANCEL_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SCAN_CANCEL_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CANCEL_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_HL_SYNC_CANCEL_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CANCEL_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_HL_SYNC_CANCEL_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_PERIODIC_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_PERIODIC_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_PERIODIC_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_PERIODIC_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_PERIODIC_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_PERIODIC_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_PERIODIC_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_PERIODIC_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_AUTONOMOUS_SCAN_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_AUTONOMOUS_SCAN_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_AUTONOMOUS_SCAN_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_AUTONOMOUS_SCAN_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_AUTONOMOUS_SCAN_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_AUTONOMOUS_SCAN_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_AUTONOMOUS_SCAN_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_AUTONOMOUS_SCAN_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_PACKET_FILTER_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_PACKET_FILTER_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_PACKET_FILTER_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_PACKET_FILTER_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_MEASURE_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_STOP_MEASURE_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_MEASURE_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_STOP_MEASURE_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_PAUSE_AUTONOMOUS_SCAN_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_PAUSE_AUTONOMOUS_SCAN_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_AUTONOMOUS_SCAN_DONE_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_AUTONOMOUS_SCAN_DONE_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TRIGGERED_GET_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_TRIGGERED_GET_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TRIGGERED_GET_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_TRIGGERED_GET_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TRIGGERED_GET_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_TRIGGERED_GET_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TRIGGERED_GET_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_TRIGGERED_GET_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_TRIGGERED_GET_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_TRIGGERED_GET_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_BLACKOUT_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_BLACKOUT_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_BLACKOUT_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_BLACKOUT_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_BLACKOUT_ENDED_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_BLACKOUT_ENDED_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_BLACKOUT_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_BLACKOUT_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_BLACKOUT_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_BLACKOUT_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_RX_TRIGGER_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_RX_TRIGGER_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_RX_TRIGGER_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_RX_TRIGGER_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_RX_TRIGGER_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_RX_TRIGGER_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_RX_TRIGGER_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_RX_TRIGGER_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECT_STATUS_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_CONNECT_STATUS_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECT_STATUS_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_CONNECT_STATUS_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MODIFY_BSS_PARAMETER_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_MODIFY_BSS_PARAMETER_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MODIFY_BSS_PARAMETER_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_MODIFY_BSS_PARAMETER_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TEMPLATE_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_TEMPLATE_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TEMPLATE_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_TEMPLATE_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONFIG_QUEUE_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_CONFIG_QUEUE_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONFIG_QUEUE_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_CONFIG_QUEUE_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TSPEC_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_TSPEC_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TSPEC_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_TSPEC_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TSPEC_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_TSPEC_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TSPEC_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_DEL_TSPEC_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_START_AGGREGATION_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_START_AGGREGATION_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_START_AGGREGATION_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_START_AGGREGATION_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_BLOCKACK_ERROR_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_BLOCKACK_ERROR_INDICATION);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_AGGREGATION_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_STOP_AGGREGATION_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_AGGREGATION_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_STOP_AGGREGATION_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SM_START_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SM_START_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SM_START_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SM_START_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_LEAVE_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_LEAVE_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_LEAVE_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_LEAVE_CONFIRM);
#endif
case CSR_MLME_SET_TIM_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_TIM_REQUEST);
case CSR_MLME_SET_TIM_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_TIM_CONFIRM);
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_KEY_SEQUENCE_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_GET_KEY_SEQUENCE_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_KEY_SEQUENCE_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_GET_KEY_SEQUENCE_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CHANNEL_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_CHANNEL_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CHANNEL_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_SET_CHANNEL_CONFIRM);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_MULTICAST_ADDRESS_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_MULTICAST_ADDRESS_REQUEST);
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_MULTICAST_ADDRESS_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_MLME_ADD_MULTICAST_ADDRESS_CONFIRM);
#endif
case CSR_DEBUG_STRING_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_DEBUG_STRING_INDICATION);
case CSR_DEBUG_WORD16_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_DEBUG_WORD16_INDICATION);
case CSR_DEBUG_GENERIC_REQUEST_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_DEBUG_GENERIC_REQUEST);
case CSR_DEBUG_GENERIC_CONFIRM_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_DEBUG_GENERIC_CONFIRM);
case CSR_DEBUG_GENERIC_INDICATION_ID:
return offsetof(struct CSR_SIGNAL_PRIMITIVE, u) + sizeof(CSR_DEBUG_GENERIC_INDICATION);
default:
return 0;
}
}
s32 SigGetDataRefs(CSR_SIGNAL *aSignal, CSR_DATAREF **aDataRef)
{
s32 numRefs = 0;
switch (aSignal->SignalPrimitiveHeader.SignalId)
{
case CSR_MA_PACKET_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MaPacketRequest.Data;
aDataRef[numRefs++] = &aSignal->u.MaPacketRequest.Dummydataref2;
break;
case CSR_MA_PACKET_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MaPacketConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MaPacketConfirm.Dummydataref2;
break;
case CSR_MA_PACKET_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MaPacketIndication.Data;
aDataRef[numRefs++] = &aSignal->u.MaPacketIndication.Dummydataref2;
break;
case CSR_MA_PACKET_CANCEL_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MaPacketCancelRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MaPacketCancelRequest.Dummydataref2;
break;
case CSR_MA_VIF_AVAILABILITY_RESPONSE_ID:
aDataRef[numRefs++] = &aSignal->u.MaVifAvailabilityResponse.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MaVifAvailabilityResponse.Dummydataref2;
break;
case CSR_MA_VIF_AVAILABILITY_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MaVifAvailabilityIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MaVifAvailabilityIndication.Dummydataref2;
break;
case CSR_MA_PACKET_ERROR_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MaPacketErrorIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MaPacketErrorIndication.Dummydataref2;
break;
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_RESET_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeResetRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeResetRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_RESET_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeResetConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeResetConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeGetRequest.MibAttribute;
aDataRef[numRefs++] = &aSignal->u.MlmeGetRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeGetConfirm.MibAttributeValue;
aDataRef[numRefs++] = &aSignal->u.MlmeGetConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetRequest.MibAttributeValue;
aDataRef[numRefs++] = &aSignal->u.MlmeSetRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetConfirm.MibAttributeValue;
aDataRef[numRefs++] = &aSignal->u.MlmeSetConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_NEXT_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeGetNextRequest.MibAttribute;
aDataRef[numRefs++] = &aSignal->u.MlmeGetNextRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_NEXT_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeGetNextConfirm.MibAttributeValue;
aDataRef[numRefs++] = &aSignal->u.MlmeGetNextConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_POWERMGT_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmePowermgtRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmePowermgtRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_POWERMGT_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmePowermgtConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmePowermgtConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeScanRequest.ChannelList;
aDataRef[numRefs++] = &aSignal->u.MlmeScanRequest.InformationElements;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeScanConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeScanConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeMeasureRequest.MeasurementRequestSet;
aDataRef[numRefs++] = &aSignal->u.MlmeMeasureRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeMeasureConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeMeasureConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeMeasureIndication.MeasurementReportSet;
aDataRef[numRefs++] = &aSignal->u.MlmeMeasureIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SETKEYS_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetkeysRequest.Key;
aDataRef[numRefs++] = &aSignal->u.MlmeSetkeysRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SETKEYS_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetkeysConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSetkeysConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DELETEKEYS_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDeletekeysRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDeletekeysRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DELETEKEYS_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDeletekeysConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDeletekeysConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_AUTONOMOUS_SCAN_LOSS_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAutonomousScanLossIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAutonomousScanLossIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECTED_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeConnectedIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeConnectedIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_CANCEL_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeScanCancelRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeScanCancelRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CANCEL_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncCancelRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncCancelRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CANCEL_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncCancelConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeHlSyncCancelConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_PERIODIC_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddPeriodicRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddPeriodicRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_PERIODIC_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddPeriodicConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddPeriodicConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_PERIODIC_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelPeriodicRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelPeriodicRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_PERIODIC_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelPeriodicConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelPeriodicConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_AUTONOMOUS_SCAN_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddAutonomousScanRequest.ChannelList;
aDataRef[numRefs++] = &aSignal->u.MlmeAddAutonomousScanRequest.InformationElements;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_AUTONOMOUS_SCAN_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddAutonomousScanConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddAutonomousScanConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_AUTONOMOUS_SCAN_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelAutonomousScanRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelAutonomousScanRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_AUTONOMOUS_SCAN_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelAutonomousScanConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelAutonomousScanConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_PACKET_FILTER_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetPacketFilterRequest.InformationElements;
aDataRef[numRefs++] = &aSignal->u.MlmeSetPacketFilterRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_PACKET_FILTER_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetPacketFilterConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSetPacketFilterConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_MEASURE_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeStopMeasureRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeStopMeasureRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_MEASURE_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeStopMeasureConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeStopMeasureConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmePauseAutonomousScanRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmePauseAutonomousScanRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmePauseAutonomousScanConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmePauseAutonomousScanConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_AUTONOMOUS_SCAN_DONE_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAutonomousScanDoneIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAutonomousScanDoneIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TRIGGERED_GET_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddTriggeredGetRequest.MibAttribute;
aDataRef[numRefs++] = &aSignal->u.MlmeAddTriggeredGetRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TRIGGERED_GET_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddTriggeredGetConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddTriggeredGetConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TRIGGERED_GET_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelTriggeredGetRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelTriggeredGetRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TRIGGERED_GET_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelTriggeredGetConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelTriggeredGetConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_TRIGGERED_GET_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeTriggeredGetIndication.MibAttributeValue;
aDataRef[numRefs++] = &aSignal->u.MlmeTriggeredGetIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_BLACKOUT_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddBlackoutRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddBlackoutRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_BLACKOUT_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddBlackoutConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddBlackoutConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_BLACKOUT_ENDED_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeBlackoutEndedIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeBlackoutEndedIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_BLACKOUT_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelBlackoutRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelBlackoutRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_BLACKOUT_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelBlackoutConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelBlackoutConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_RX_TRIGGER_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddRxTriggerRequest.InformationElements;
aDataRef[numRefs++] = &aSignal->u.MlmeAddRxTriggerRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_RX_TRIGGER_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddRxTriggerConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddRxTriggerConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_RX_TRIGGER_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelRxTriggerRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelRxTriggerRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_RX_TRIGGER_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelRxTriggerConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelRxTriggerConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECT_STATUS_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeConnectStatusRequest.InformationElements;
aDataRef[numRefs++] = &aSignal->u.MlmeConnectStatusRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECT_STATUS_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeConnectStatusConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeConnectStatusConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MODIFY_BSS_PARAMETER_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeModifyBssParameterRequest.Data;
aDataRef[numRefs++] = &aSignal->u.MlmeModifyBssParameterRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MODIFY_BSS_PARAMETER_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeModifyBssParameterConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeModifyBssParameterConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TEMPLATE_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddTemplateRequest.Data1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddTemplateRequest.Data2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TEMPLATE_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddTemplateConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddTemplateConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONFIG_QUEUE_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeConfigQueueRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeConfigQueueRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONFIG_QUEUE_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeConfigQueueConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeConfigQueueConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TSPEC_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddTspecRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddTspecRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TSPEC_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddTspecConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddTspecConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TSPEC_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelTspecRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelTspecRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TSPEC_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeDelTspecConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeDelTspecConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_START_AGGREGATION_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeStartAggregationRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeStartAggregationRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_START_AGGREGATION_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeStartAggregationConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeStartAggregationConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_BLOCKACK_ERROR_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeBlockackErrorIndication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeBlockackErrorIndication.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_AGGREGATION_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeStopAggregationRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeStopAggregationRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_AGGREGATION_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeStopAggregationConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeStopAggregationConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SM_START_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSmStartRequest.Beacon;
aDataRef[numRefs++] = &aSignal->u.MlmeSmStartRequest.BssParameters;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SM_START_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSmStartConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSmStartConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_LEAVE_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeLeaveRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeLeaveRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_LEAVE_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeLeaveConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeLeaveConfirm.Dummydataref2;
break;
#endif
case CSR_MLME_SET_TIM_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetTimRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSetTimRequest.Dummydataref2;
break;
case CSR_MLME_SET_TIM_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetTimConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSetTimConfirm.Dummydataref2;
break;
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_KEY_SEQUENCE_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeGetKeySequenceRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeGetKeySequenceRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_KEY_SEQUENCE_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeGetKeySequenceConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeGetKeySequenceConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CHANNEL_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetChannelRequest.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSetChannelRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CHANNEL_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeSetChannelConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeSetChannelConfirm.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_MULTICAST_ADDRESS_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddMulticastAddressRequest.Data;
aDataRef[numRefs++] = &aSignal->u.MlmeAddMulticastAddressRequest.Dummydataref2;
break;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_MULTICAST_ADDRESS_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.MlmeAddMulticastAddressConfirm.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.MlmeAddMulticastAddressConfirm.Dummydataref2;
break;
#endif
case CSR_DEBUG_STRING_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.DebugStringIndication.DebugMessage;
aDataRef[numRefs++] = &aSignal->u.DebugStringIndication.Dummydataref2;
break;
case CSR_DEBUG_WORD16_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.DebugWord16Indication.Dummydataref1;
aDataRef[numRefs++] = &aSignal->u.DebugWord16Indication.Dummydataref2;
break;
case CSR_DEBUG_GENERIC_REQUEST_ID:
aDataRef[numRefs++] = &aSignal->u.DebugGenericRequest.DebugVariable;
aDataRef[numRefs++] = &aSignal->u.DebugGenericRequest.Dummydataref2;
break;
case CSR_DEBUG_GENERIC_CONFIRM_ID:
aDataRef[numRefs++] = &aSignal->u.DebugGenericConfirm.DebugVariable;
aDataRef[numRefs++] = &aSignal->u.DebugGenericConfirm.Dummydataref2;
break;
case CSR_DEBUG_GENERIC_INDICATION_ID:
aDataRef[numRefs++] = &aSignal->u.DebugGenericIndication.DebugVariable;
aDataRef[numRefs++] = &aSignal->u.DebugGenericIndication.Dummydataref2;
break;
default:
return 0;
}
return numRefs;
}
u32 SigGetFilterPos(u16 aSigID)
{
switch (aSigID)
{
case CSR_MA_PACKET_REQUEST_ID:
return 0x00000001;
case CSR_MA_PACKET_CONFIRM_ID:
return 0x00000002;
case CSR_MA_PACKET_INDICATION_ID:
return 0x00000004;
case CSR_MA_PACKET_CANCEL_REQUEST_ID:
return 0x00000008;
case CSR_MA_VIF_AVAILABILITY_RESPONSE_ID:
return 0x00000010;
case CSR_MA_VIF_AVAILABILITY_INDICATION_ID:
return 0x00000020;
case CSR_MA_PACKET_ERROR_INDICATION_ID:
return 0x00000040;
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_RESET_REQUEST_ID:
return 0x00000080;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_RESET_CONFIRM_ID:
return 0x00000100;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_REQUEST_ID:
return 0x00000200;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_CONFIRM_ID:
return 0x00000400;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_REQUEST_ID:
return 0x00000800;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CONFIRM_ID:
return 0x00001000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_NEXT_REQUEST_ID:
return 0x00002000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_NEXT_CONFIRM_ID:
return 0x00004000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_POWERMGT_REQUEST_ID:
return 0x00008000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_POWERMGT_CONFIRM_ID:
return 0x00010001;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_REQUEST_ID:
return 0x00010002;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_CONFIRM_ID:
return 0x00010004;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_REQUEST_ID:
return 0x00010008;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CONFIRM_ID:
return 0x00010010;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_REQUEST_ID:
return 0x00010020;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_CONFIRM_ID:
return 0x00010040;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MEASURE_INDICATION_ID:
return 0x00010080;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SETKEYS_REQUEST_ID:
return 0x00010100;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SETKEYS_CONFIRM_ID:
return 0x00010200;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DELETEKEYS_REQUEST_ID:
return 0x00010400;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DELETEKEYS_CONFIRM_ID:
return 0x00010800;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_AUTONOMOUS_SCAN_LOSS_INDICATION_ID:
return 0x00011000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECTED_INDICATION_ID:
return 0x00012000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SCAN_CANCEL_REQUEST_ID:
return 0x00014000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CANCEL_REQUEST_ID:
return 0x00018000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_HL_SYNC_CANCEL_CONFIRM_ID:
return 0x00020001;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_PERIODIC_REQUEST_ID:
return 0x00020002;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_PERIODIC_CONFIRM_ID:
return 0x00020004;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_PERIODIC_REQUEST_ID:
return 0x00020008;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_PERIODIC_CONFIRM_ID:
return 0x00020010;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_AUTONOMOUS_SCAN_REQUEST_ID:
return 0x00020020;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_AUTONOMOUS_SCAN_CONFIRM_ID:
return 0x00020040;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_AUTONOMOUS_SCAN_REQUEST_ID:
return 0x00020080;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_AUTONOMOUS_SCAN_CONFIRM_ID:
return 0x00020100;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_PACKET_FILTER_REQUEST_ID:
return 0x00020200;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_PACKET_FILTER_CONFIRM_ID:
return 0x00020400;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_MEASURE_REQUEST_ID:
return 0x00020800;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_MEASURE_CONFIRM_ID:
return 0x00021000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_REQUEST_ID:
return 0x00022000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_PAUSE_AUTONOMOUS_SCAN_CONFIRM_ID:
return 0x00024000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_AUTONOMOUS_SCAN_DONE_INDICATION_ID:
return 0x00028000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TRIGGERED_GET_REQUEST_ID:
return 0x00030001;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TRIGGERED_GET_CONFIRM_ID:
return 0x00030002;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TRIGGERED_GET_REQUEST_ID:
return 0x00030004;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TRIGGERED_GET_CONFIRM_ID:
return 0x00030008;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_TRIGGERED_GET_INDICATION_ID:
return 0x00030010;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_BLACKOUT_REQUEST_ID:
return 0x00030020;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_BLACKOUT_CONFIRM_ID:
return 0x00030040;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_BLACKOUT_ENDED_INDICATION_ID:
return 0x00030080;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_BLACKOUT_REQUEST_ID:
return 0x00030100;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_BLACKOUT_CONFIRM_ID:
return 0x00030200;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_RX_TRIGGER_REQUEST_ID:
return 0x00030400;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_RX_TRIGGER_CONFIRM_ID:
return 0x00030800;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_RX_TRIGGER_REQUEST_ID:
return 0x00031000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_RX_TRIGGER_CONFIRM_ID:
return 0x00032000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECT_STATUS_REQUEST_ID:
return 0x00034000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONNECT_STATUS_CONFIRM_ID:
return 0x00038000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MODIFY_BSS_PARAMETER_REQUEST_ID:
return 0x00040001;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_MODIFY_BSS_PARAMETER_CONFIRM_ID:
return 0x00040002;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TEMPLATE_REQUEST_ID:
return 0x00040004;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TEMPLATE_CONFIRM_ID:
return 0x00040008;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONFIG_QUEUE_REQUEST_ID:
return 0x00040010;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_CONFIG_QUEUE_CONFIRM_ID:
return 0x00040020;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TSPEC_REQUEST_ID:
return 0x00040040;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_TSPEC_CONFIRM_ID:
return 0x00040080;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TSPEC_REQUEST_ID:
return 0x00040100;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_DEL_TSPEC_CONFIRM_ID:
return 0x00040200;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_START_AGGREGATION_REQUEST_ID:
return 0x00040400;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_START_AGGREGATION_CONFIRM_ID:
return 0x00040800;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_BLOCKACK_ERROR_INDICATION_ID:
return 0x00041000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_AGGREGATION_REQUEST_ID:
return 0x00042000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_STOP_AGGREGATION_CONFIRM_ID:
return 0x00044000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SM_START_REQUEST_ID:
return 0x00048000;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SM_START_CONFIRM_ID:
return 0x00050001;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_LEAVE_REQUEST_ID:
return 0x00050002;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_LEAVE_CONFIRM_ID:
return 0x00050004;
#endif
case CSR_MLME_SET_TIM_REQUEST_ID:
return 0x00050008;
case CSR_MLME_SET_TIM_CONFIRM_ID:
return 0x00050010;
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_KEY_SEQUENCE_REQUEST_ID:
return 0x00050020;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_GET_KEY_SEQUENCE_CONFIRM_ID:
return 0x00050040;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CHANNEL_REQUEST_ID:
return 0x00050080;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_SET_CHANNEL_CONFIRM_ID:
return 0x00050100;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_MULTICAST_ADDRESS_REQUEST_ID:
return 0x00050200;
#endif
#ifdef CSR_WIFI_HIP_FULL_SIGNAL_SET
case CSR_MLME_ADD_MULTICAST_ADDRESS_CONFIRM_ID:
return 0x00050400;
#endif
case CSR_DEBUG_STRING_INDICATION_ID:
return 0x00050800;
case CSR_DEBUG_WORD16_INDICATION_ID:
return 0x00051000;
case CSR_DEBUG_GENERIC_REQUEST_ID:
return 0x00052000;
case CSR_DEBUG_GENERIC_CONFIRM_ID:
return 0x00054000;
case CSR_DEBUG_GENERIC_INDICATION_ID:
return 0x00058000;
default:
break;
}
return 0xffffffff;
}
