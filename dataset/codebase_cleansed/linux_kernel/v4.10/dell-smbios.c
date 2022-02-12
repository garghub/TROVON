int dell_smbios_error(int value)
{
switch (value) {
case 0:
return 0;
case -1:
return -EIO;
case -2:
return -ENXIO;
default:
return -EINVAL;
}
}
struct calling_interface_buffer *dell_smbios_get_buffer(void)
{
mutex_lock(&buffer_mutex);
dell_smbios_clear_buffer();
return buffer;
}
void dell_smbios_clear_buffer(void)
{
memset(buffer, 0, sizeof(struct calling_interface_buffer));
}
void dell_smbios_release_buffer(void)
{
mutex_unlock(&buffer_mutex);
}
void dell_smbios_send_request(int class, int select)
{
struct smi_cmd command;
command.magic = SMI_CMD_MAGIC;
command.command_address = da_command_address;
command.command_code = da_command_code;
command.ebx = virt_to_phys(buffer);
command.ecx = 0x42534931;
buffer->class = class;
buffer->select = select;
dcdbas_smi_request(&command);
}
struct calling_interface_token *dell_smbios_find_token(int tokenid)
{
int i;
for (i = 0; i < da_num_tokens; i++) {
if (da_tokens[i].tokenID == tokenid)
return &da_tokens[i];
}
return NULL;
}
static void __init parse_da_table(const struct dmi_header *dm)
{
int tokens = (dm->length-11)/sizeof(struct calling_interface_token)-1;
struct calling_interface_token *new_da_tokens;
struct calling_interface_structure *table =
container_of(dm, struct calling_interface_structure, header);
if (dm->length < 17)
return;
da_command_address = table->cmdIOAddress;
da_command_code = table->cmdIOCode;
new_da_tokens = krealloc(da_tokens, (da_num_tokens + tokens) *
sizeof(struct calling_interface_token),
GFP_KERNEL);
if (!new_da_tokens)
return;
da_tokens = new_da_tokens;
memcpy(da_tokens+da_num_tokens, table->tokens,
sizeof(struct calling_interface_token) * tokens);
da_num_tokens += tokens;
}
static void __init find_tokens(const struct dmi_header *dm, void *dummy)
{
switch (dm->type) {
case 0xd4:
case 0xd5:
case 0xd6:
break;
case 0xda:
parse_da_table(dm);
break;
}
}
static int __init dell_smbios_init(void)
{
int ret;
dmi_walk(find_tokens, NULL);
if (!da_tokens) {
pr_info("Unable to find dmi tokens\n");
return -ENODEV;
}
buffer = (void *)__get_free_page(GFP_KERNEL | GFP_DMA32);
if (!buffer) {
ret = -ENOMEM;
goto fail_buffer;
}
return 0;
fail_buffer:
kfree(da_tokens);
return ret;
}
static void __exit dell_smbios_exit(void)
{
kfree(da_tokens);
free_page((unsigned long)buffer);
}
