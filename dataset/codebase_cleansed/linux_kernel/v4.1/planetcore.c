void planetcore_prepare_table(char *table)
{
do {
if (*table == '\n')
*table = 0;
table++;
} while (*(table - 1) || *table != '\n');
*table = 0;
}
const char *planetcore_get_key(const char *table, const char *key)
{
int keylen = strlen(key);
do {
if (!strncmp(table, key, keylen) && table[keylen] == '=')
return table + keylen + 1;
table += strlen(table) + 1;
} while (strlen(table) != 0);
return NULL;
}
int planetcore_get_decimal(const char *table, const char *key, u64 *val)
{
const char *str = planetcore_get_key(table, key);
if (!str)
return 0;
*val = strtoull(str, NULL, 10);
return 1;
}
int planetcore_get_hex(const char *table, const char *key, u64 *val)
{
const char *str = planetcore_get_key(table, key);
if (!str)
return 0;
*val = strtoull(str, NULL, 16);
return 1;
}
void planetcore_set_mac_addrs(const char *table)
{
u8 addr[4][6];
u64 int_addr;
u32 i;
int j;
if (!planetcore_get_hex(table, PLANETCORE_KEY_MAC_ADDR, &int_addr))
return;
for (i = 0; i < 4; i++) {
u64 this_dev_addr = (int_addr & ~0x000000c00000) |
mac_table[i];
for (j = 5; j >= 0; j--) {
addr[i][j] = this_dev_addr & 0xff;
this_dev_addr >>= 8;
}
dt_fixup_mac_address(i, addr[i]);
}
}
void planetcore_set_stdout_path(const char *table)
{
char *path;
const char *label;
void *node, *chosen;
label = planetcore_get_key(table, PLANETCORE_KEY_SERIAL_PORT);
if (!label)
return;
node = find_node_by_prop_value_str(NULL, "linux,planetcore-label",
label);
if (!node)
return;
path = get_path(node, prop_buf, MAX_PROP_LEN);
if (!path)
return;
chosen = finddevice("/chosen");
if (!chosen)
chosen = create_node(NULL, "chosen");
if (!chosen)
return;
setprop_str(chosen, "linux,stdout-path", path);
}
