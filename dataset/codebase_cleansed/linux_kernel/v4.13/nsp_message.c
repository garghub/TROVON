static void nsp_message_in(struct scsi_cmnd *SCpnt)
{
unsigned int base = SCpnt->device->host->io_port;
nsp_hw_data *data = (nsp_hw_data *)SCpnt->device->host->hostdata;
unsigned char data_reg, control_reg;
int ret, len;
ret = 16;
len = 0;
nsp_dbg(NSP_DEBUG_MSGINOCCUR, "msgin loop");
do {
data_reg = nsp_index_read(base, SCSIDATAIN);
control_reg = nsp_index_read(base, SCSIBUSCTRL);
control_reg |= SCSI_ACK;
nsp_index_write(base, SCSIBUSCTRL, control_reg);
nsp_negate_signal(SCpnt, BUSMON_REQ, "msgin<REQ>");
data->MsgBuffer[len] = data_reg; len++;
control_reg = nsp_index_read(base, SCSIBUSCTRL);
control_reg &= ~SCSI_ACK;
nsp_index_write(base, SCSIBUSCTRL, control_reg);
ret = nsp_expect_signal(SCpnt, BUSPHASE_MESSAGE_IN, BUSMON_REQ);
} while (ret > 0 && MSGBUF_SIZE > len);
data->MsgLen = len;
}
static void nsp_message_out(struct scsi_cmnd *SCpnt)
{
nsp_hw_data *data = (nsp_hw_data *)SCpnt->device->host->hostdata;
int ret = 1;
int len = data->MsgLen;
nsp_dbg(NSP_DEBUG_MSGOUTOCCUR, "msgout loop");
do {
if (nsp_xfer(SCpnt, BUSPHASE_MESSAGE_OUT)) {
nsp_msg(KERN_DEBUG, "msgout: xfer short");
}
ret = nsp_expect_signal(SCpnt, BUSPHASE_MESSAGE_OUT, BUSMON_REQ);
} while (ret > 0 && len-- > 0);
}
