const char *lookup_bulkcmd_name(u16 id)
{
if (id < 9)
return Unifi_bulkcmd_names[id].name;
if (id == 15)
return "Padding";
return "UNKNOWN";
}
