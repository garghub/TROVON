int iwl_trans_send_cmd_pdu(struct iwl_trans *trans, u8 id,
u32 flags, u16 len, const void *data)
{
struct iwl_host_cmd cmd = {
.id = id,
.len = { len, },
.data = { data, },
.flags = flags,
};
return iwl_trans_send_cmd(trans, &cmd);
}
