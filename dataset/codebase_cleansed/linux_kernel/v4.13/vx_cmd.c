void vx_init_rmh(struct vx_rmh *rmh, unsigned int cmd)
{
if (snd_BUG_ON(cmd >= CMD_LAST_INDEX))
return;
rmh->LgCmd = vx_dsp_cmds[cmd].length;
rmh->LgStat = vx_dsp_cmds[cmd].st_length;
rmh->DspStat = vx_dsp_cmds[cmd].st_type;
rmh->Cmd[0] = vx_dsp_cmds[cmd].opcode;
}
