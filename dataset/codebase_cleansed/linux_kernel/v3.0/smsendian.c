void smsendian_handle_tx_message(void *buffer)
{
#ifdef __BIG_ENDIAN
struct SmsMsgData_ST *msg = (struct SmsMsgData_ST *)buffer;
int i;
int msgWords;
switch (msg->xMsgHeader.msgType) {
case MSG_SMS_DATA_DOWNLOAD_REQ:
{
msg->msgData[0] = le32_to_cpu(msg->msgData[0]);
break;
}
default:
msgWords = (msg->xMsgHeader.msgLength -
sizeof(struct SmsMsgHdr_ST))/4;
for (i = 0; i < msgWords; i++)
msg->msgData[i] = le32_to_cpu(msg->msgData[i]);
break;
}
#endif
}
void smsendian_handle_rx_message(void *buffer)
{
#ifdef __BIG_ENDIAN
struct SmsMsgData_ST *msg = (struct SmsMsgData_ST *)buffer;
int i;
int msgWords;
switch (msg->xMsgHeader.msgType) {
case MSG_SMS_GET_VERSION_EX_RES:
{
struct SmsVersionRes_ST *ver =
(struct SmsVersionRes_ST *) msg;
ver->ChipModel = le16_to_cpu(ver->ChipModel);
break;
}
case MSG_SMS_DVBT_BDA_DATA:
case MSG_SMS_DAB_CHANNEL:
case MSG_SMS_DATA_MSG:
{
break;
}
default:
{
msgWords = (msg->xMsgHeader.msgLength -
sizeof(struct SmsMsgHdr_ST))/4;
for (i = 0; i < msgWords; i++)
msg->msgData[i] = le32_to_cpu(msg->msgData[i]);
break;
}
}
#endif
}
void smsendian_handle_message_header(void *msg)
{
#ifdef __BIG_ENDIAN
struct SmsMsgHdr_ST *phdr = (struct SmsMsgHdr_ST *)msg;
phdr->msgType = le16_to_cpu(phdr->msgType);
phdr->msgLength = le16_to_cpu(phdr->msgLength);
phdr->msgFlags = le16_to_cpu(phdr->msgFlags);
#endif
}
