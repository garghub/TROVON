int tb_port_find_cap(struct tb_port *port, enum tb_port_cap cap)
{
u32 offset;
if (port->config.type == TB_TYPE_DP_HDMI_OUT)
offset = 0x39;
else
offset = 0x1;
do {
struct tb_cap_any header;
int ret;
ret = tb_port_read(port, &header, TB_CFG_PORT, offset, 1);
if (ret)
return ret;
if (header.basic.cap == cap)
return offset;
offset = header.basic.next;
} while (offset);
return -ENOENT;
}
static int tb_switch_find_cap(struct tb_switch *sw, enum tb_switch_cap cap)
{
int offset = sw->config.first_cap_offset;
while (offset > 0 && offset < CAP_OFFSET_MAX) {
struct tb_cap_any header;
int ret;
ret = tb_sw_read(sw, &header, TB_CFG_SWITCH, offset, 1);
if (ret)
return ret;
if (header.basic.cap == cap)
return offset;
offset = header.basic.next;
}
return -ENOENT;
}
int tb_switch_find_vse_cap(struct tb_switch *sw, enum tb_switch_vse_cap vsec)
{
struct tb_cap_any header;
int offset;
offset = tb_switch_find_cap(sw, TB_SWITCH_CAP_VSE);
if (offset < 0)
return offset;
while (offset > 0 && offset < VSE_CAP_OFFSET_MAX) {
int ret;
ret = tb_sw_read(sw, &header, TB_CFG_SWITCH, offset, 2);
if (ret)
return ret;
if (offset >= CAP_OFFSET_MAX) {
if (header.extended_long.vsec_id == vsec)
return offset;
offset = header.extended_long.next;
} else {
if (header.extended_short.vsec_id == vsec)
return offset;
if (!header.extended_short.length)
return -ENOENT;
offset = header.extended_short.next;
}
}
return -ENOENT;
}
