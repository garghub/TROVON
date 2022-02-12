static bool tb_cap_is_basic(struct tb_cap_any *cap)
{
return cap->basic.cap != 5;
}
static bool tb_cap_is_long(struct tb_cap_any *cap)
{
return !tb_cap_is_basic(cap)
&& cap->extended_short.next == 0
&& cap->extended_short.length == 0;
}
static enum tb_cap tb_cap(struct tb_cap_any *cap)
{
if (tb_cap_is_basic(cap))
return cap->basic.cap;
else
return cap->extended_short.cap;
}
static u32 tb_cap_next(struct tb_cap_any *cap, u32 offset)
{
int next;
if (offset == 1) {
next = cap->basic.next;
} else {
if (tb_cap_is_basic(cap))
next = cap->basic.next;
else if (!tb_cap_is_long(cap))
next = cap->extended_short.next;
else
next = cap->extended_long.next;
}
if (next == offset)
return 0;
return next;
}
int tb_find_cap(struct tb_port *port, enum tb_cfg_space space, enum tb_cap cap)
{
u32 offset = 1;
struct tb_cap_any header;
int res;
int retries = 10;
while (retries--) {
res = tb_port_read(port, &header, space, offset, 1);
if (res) {
if (space == TB_CFG_PORT && offset == 0xa
&& port->config.type == TB_TYPE_DP_HDMI_OUT) {
offset = 0x39;
continue;
}
return res;
}
if (offset != 1) {
if (tb_cap(&header) == cap)
return offset;
if (tb_cap_is_long(&header)) {
res = tb_port_read(port, &header, space,
offset, 2);
if (res)
return res;
}
}
offset = tb_cap_next(&header, offset);
if (!offset)
return 0;
}
tb_port_WARN(port,
"run out of retries while looking for cap %#x in config space %d, last offset: %#x\n",
cap, space, offset);
return -EIO;
}
