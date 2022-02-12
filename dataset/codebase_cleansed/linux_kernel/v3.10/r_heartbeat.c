void ibmasm_init_reverse_heartbeat(struct service_processor *sp, struct reverse_heartbeat *rhb)
{
init_waitqueue_head(&rhb->wait);
rhb->stopped = 0;
}
int ibmasm_start_reverse_heartbeat(struct service_processor *sp, struct reverse_heartbeat *rhb)
{
struct command *cmd;
int times_failed = 0;
int result = 1;
cmd = ibmasm_new_command(sp, sizeof rhb_dot_cmd);
if (!cmd)
return -ENOMEM;
while (times_failed < 3) {
memcpy(cmd->buffer, (void *)&rhb_dot_cmd, sizeof rhb_dot_cmd);
cmd->status = IBMASM_CMD_PENDING;
ibmasm_exec_command(sp, cmd);
ibmasm_wait_for_response(cmd, IBMASM_CMD_TIMEOUT_NORMAL);
if (cmd->status != IBMASM_CMD_COMPLETE)
times_failed++;
wait_event_interruptible_timeout(rhb->wait,
rhb->stopped,
REVERSE_HEARTBEAT_TIMEOUT * HZ);
if (signal_pending(current) || rhb->stopped) {
result = -EINTR;
break;
}
}
command_put(cmd);
rhb->stopped = 0;
return result;
}
void ibmasm_stop_reverse_heartbeat(struct reverse_heartbeat *rhb)
{
rhb->stopped = 1;
wake_up_interruptible(&rhb->wait);
}
