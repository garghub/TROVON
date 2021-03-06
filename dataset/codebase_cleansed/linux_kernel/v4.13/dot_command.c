void ibmasm_receive_message(struct service_processor *sp, void *message, int message_size)
{
u32 size;
struct dot_command_header *header = (struct dot_command_header *)message;
if (message_size == 0)
return;
size = get_dot_command_size(message);
if (size == 0)
return;
if (size > message_size)
size = message_size;
switch (header->type) {
case sp_event:
ibmasm_receive_event(sp, message, size);
break;
case sp_command_response:
ibmasm_receive_command_response(sp, message, size);
break;
case sp_heartbeat:
ibmasm_receive_heartbeat(sp, message, size);
break;
default:
dev_err(sp->dev, "Received unknown message from service processor\n");
}
}
int ibmasm_send_driver_vpd(struct service_processor *sp)
{
struct command *command;
struct dot_command_header *header;
u8 *vpd_command;
u8 *vpd_data;
int result = 0;
command = ibmasm_new_command(sp, INIT_BUFFER_SIZE);
if (command == NULL)
return -ENOMEM;
header = (struct dot_command_header *)command->buffer;
header->type = sp_write;
header->command_size = 4;
header->data_size = 16;
header->status = 0;
header->reserved = 0;
vpd_command = command->buffer + sizeof(struct dot_command_header);
vpd_command[0] = 0x4;
vpd_command[1] = 0x3;
vpd_command[2] = 0x5;
vpd_command[3] = 0xa;
vpd_data = vpd_command + header->command_size;
vpd_data[0] = 0;
strcat(vpd_data, IBMASM_DRIVER_VPD);
vpd_data[10] = 0;
vpd_data[15] = 0;
ibmasm_exec_command(sp, command);
ibmasm_wait_for_response(command, IBMASM_CMD_TIMEOUT_NORMAL);
if (command->status != IBMASM_CMD_COMPLETE)
result = -ENODEV;
command_put(command);
return result;
}
int ibmasm_send_os_state(struct service_processor *sp, int os_state)
{
struct command *cmd;
struct os_state_command *os_state_cmd;
int result = 0;
cmd = ibmasm_new_command(sp, sizeof(struct os_state_command));
if (cmd == NULL)
return -ENOMEM;
os_state_cmd = (struct os_state_command *)cmd->buffer;
os_state_cmd->header.type = sp_write;
os_state_cmd->header.command_size = 3;
os_state_cmd->header.data_size = 1;
os_state_cmd->header.status = 0;
os_state_cmd->command[0] = 4;
os_state_cmd->command[1] = 3;
os_state_cmd->command[2] = 6;
os_state_cmd->data = os_state;
ibmasm_exec_command(sp, cmd);
ibmasm_wait_for_response(cmd, IBMASM_CMD_TIMEOUT_NORMAL);
if (cmd->status != IBMASM_CMD_COMPLETE)
result = -ENODEV;
command_put(cmd);
return result;
}
