static void kbit_to_gw_bandwidth(int down, int up, long *gw_srv_class)
{
int mdown = 0, tdown, tup, difference;
uint8_t sbit, part;
*gw_srv_class = 0;
difference = 0x0FFFFFFF;
for (sbit = 0; sbit < 2; sbit++) {
for (part = 0; part < 16; part++) {
tdown = 32 * (sbit + 2) * (1 << part);
if (abs(tdown - down) < difference) {
*gw_srv_class = (sbit << 7) + (part << 3);
difference = abs(tdown - down);
mdown = tdown;
}
}
}
difference = 0x0FFFFFFF;
for (part = 0; part < 8; part++) {
tup = ((part + 1) * (mdown)) / 8;
if (abs(tup - up) < difference) {
*gw_srv_class = (*gw_srv_class & 0xF8) | part;
difference = abs(tup - up);
}
}
}
void gw_bandwidth_to_kbit(uint8_t gw_srv_class, int *down, int *up)
{
char sbit = (gw_srv_class & 0x80) >> 7;
char dpart = (gw_srv_class & 0x78) >> 3;
char upart = (gw_srv_class & 0x07);
if (!gw_srv_class) {
*down = 0;
*up = 0;
return;
}
*down = 32 * (sbit + 2) * (1 << dpart);
*up = ((upart + 1) * (*down)) / 8;
}
static bool parse_gw_bandwidth(struct net_device *net_dev, char *buff,
long *up, long *down)
{
int ret, multi = 1;
char *slash_ptr, *tmp_ptr;
slash_ptr = strchr(buff, '/');
if (slash_ptr)
*slash_ptr = 0;
if (strlen(buff) > 4) {
tmp_ptr = buff + strlen(buff) - 4;
if (strnicmp(tmp_ptr, "mbit", 4) == 0)
multi = 1024;
if ((strnicmp(tmp_ptr, "kbit", 4) == 0) ||
(multi > 1))
*tmp_ptr = '\0';
}
ret = strict_strtoul(buff, 10, down);
if (ret) {
bat_err(net_dev,
"Download speed of gateway mode invalid: %s\n",
buff);
return false;
}
*down *= multi;
if (slash_ptr) {
multi = 1;
if (strlen(slash_ptr + 1) > 4) {
tmp_ptr = slash_ptr + 1 - 4 + strlen(slash_ptr + 1);
if (strnicmp(tmp_ptr, "mbit", 4) == 0)
multi = 1024;
if ((strnicmp(tmp_ptr, "kbit", 4) == 0) ||
(multi > 1))
*tmp_ptr = '\0';
}
ret = strict_strtoul(slash_ptr + 1, 10, up);
if (ret) {
bat_err(net_dev,
"Upload speed of gateway mode invalid: "
"%s\n", slash_ptr + 1);
return false;
}
*up *= multi;
}
return true;
}
ssize_t gw_bandwidth_set(struct net_device *net_dev, char *buff, size_t count)
{
struct bat_priv *bat_priv = netdev_priv(net_dev);
long gw_bandwidth_tmp = 0, up = 0, down = 0;
bool ret;
ret = parse_gw_bandwidth(net_dev, buff, &up, &down);
if (!ret)
goto end;
if ((!down) || (down < 256))
down = 2000;
if (!up)
up = down / 5;
kbit_to_gw_bandwidth(down, up, &gw_bandwidth_tmp);
gw_bandwidth_to_kbit((uint8_t)gw_bandwidth_tmp,
(int *)&down, (int *)&up);
gw_deselect(bat_priv);
bat_info(net_dev, "Changing gateway bandwidth from: '%i' to: '%ld' "
"(propagating: %ld%s/%ld%s)\n",
atomic_read(&bat_priv->gw_bandwidth), gw_bandwidth_tmp,
(down > 2048 ? down / 1024 : down),
(down > 2048 ? "MBit" : "KBit"),
(up > 2048 ? up / 1024 : up),
(up > 2048 ? "MBit" : "KBit"));
atomic_set(&bat_priv->gw_bandwidth, gw_bandwidth_tmp);
end:
return count;
}
