static int panic_happened(struct notifier_block *n, unsigned long val, void *v)
{
suspend_heartbeats = 1;
return 0;
}
void ibmasm_register_panic_notifier(void)
{
atomic_notifier_chain_register(&panic_notifier_list, &panic_notifier);
}
void ibmasm_unregister_panic_notifier(void)
{
atomic_notifier_chain_unregister(&panic_notifier_list,
&panic_notifier);
}
int ibmasm_heartbeat_init(struct service_processor *sp)
{
sp->heartbeat = ibmasm_new_command(sp, HEARTBEAT_BUFFER_SIZE);
if (sp->heartbeat == NULL)
return -ENOMEM;
return 0;
}
void ibmasm_heartbeat_exit(struct service_processor *sp)
{
char tsbuf[32];
dbg("%s:%d at %s\n", __func__, __LINE__, get_timestamp(tsbuf));
ibmasm_wait_for_response(sp->heartbeat, IBMASM_CMD_TIMEOUT_NORMAL);
dbg("%s:%d at %s\n", __func__, __LINE__, get_timestamp(tsbuf));
suspend_heartbeats = 1;
command_put(sp->heartbeat);
}
void ibmasm_receive_heartbeat(struct service_processor *sp, void *message, size_t size)
{
struct command *cmd = sp->heartbeat;
struct dot_command_header *header = (struct dot_command_header *)cmd->buffer;
char tsbuf[32];
dbg("%s:%d at %s\n", __func__, __LINE__, get_timestamp(tsbuf));
if (suspend_heartbeats)
return;
cmd->status = IBMASM_CMD_PENDING;
size = min(size, cmd->buffer_size);
memcpy_fromio(cmd->buffer, message, size);
header->type = sp_write;
ibmasm_exec_command(sp, cmd);
}
