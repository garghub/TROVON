static unsigned char __init e2a(unsigned char x)
{
switch (x) {
case 0x81 ... 0x89:
return x - 0x81 + 'a';
case 0x91 ... 0x99:
return x - 0x91 + 'j';
case 0xA2 ... 0xA9:
return x - 0xA2 + 's';
case 0xC1 ... 0xC9:
return x - 0xC1 + 'A';
case 0xD1 ... 0xD9:
return x - 0xD1 + 'J';
case 0xE2 ... 0xE9:
return x - 0xE2 + 'S';
case 0xF0 ... 0xF9:
return x - 0xF0 + '0';
}
return ' ';
}
static unsigned char * __init strne2a(unsigned char *dest,
const unsigned char *src, size_t n)
{
int i;
n = strnlen(src, n);
for (i = 0; i < n; i++)
dest[i] = e2a(src[i]);
return dest;
}
static struct iseries_flat_dt * __init dt_init(void)
{
struct iseries_flat_dt *dt;
unsigned long str_len;
str_len = __dt_strings_end - __dt_strings_start;
dt = (struct iseries_flat_dt *)ALIGN(klimit, 8);
dt->header.off_mem_rsvmap =
offsetof(struct iseries_flat_dt, reserve_map);
dt->header.off_dt_strings = ALIGN(sizeof(*dt), 8);
dt->header.off_dt_struct = dt->header.off_dt_strings
+ ALIGN(str_len, 8);
dt_data = (void *)((unsigned long)dt + dt->header.off_dt_struct);
dt->header.dt_strings_size = str_len;
dt->header.boot_cpuid_phys = smp_processor_id();
memcpy((char *)dt + dt->header.off_dt_strings, __dt_strings_start,
str_len);
dt->header.magic = OF_DT_HEADER;
dt->header.version = 0x10;
dt->header.last_comp_version = 0x10;
dt->reserve_map[0] = 0;
dt->reserve_map[1] = 0;
return dt;
}
static void __init dt_push_u32(struct iseries_flat_dt *dt, u32 value)
{
*((u32 *)dt_data) = value;
dt_data += sizeof(u32);
}
static void __init dt_push_u64(struct iseries_flat_dt *dt, u64 value)
{
*((u64 *)dt_data) = value;
dt_data += sizeof(u64);
}
static void __init dt_push_bytes(struct iseries_flat_dt *dt, const char *data,
int len)
{
memcpy(dt_data, data, len);
dt_data += ALIGN(len, 4);
}
static void __init dt_start_node(struct iseries_flat_dt *dt, const char *name)
{
dt_push_u32(dt, OF_DT_BEGIN_NODE);
dt_push_bytes(dt, name, strlen(name) + 1);
}
static void __init __dt_prop(struct iseries_flat_dt *dt, const char *name,
const void *data, int len)
{
unsigned long offset;
dt_push_u32(dt, OF_DT_PROP);
dt_push_u32(dt, len);
offset = name - __dt_strings_start;
dt_push_u32(dt, (u32)offset);
dt_push_bytes(dt, data, len);
}
static void __init __dt_prop_u32(struct iseries_flat_dt *dt, const char *name,
u32 data)
{
__dt_prop(dt, name, &data, sizeof(u32));
}
static void __init __maybe_unused __dt_prop_u64(struct iseries_flat_dt *dt,
const char *name, u64 data)
{
__dt_prop(dt, name, &data, sizeof(u64));
}
static void __init dt_cpus(struct iseries_flat_dt *dt)
{
unsigned char buf[32];
unsigned char *p;
unsigned int i, index;
struct IoHriProcessorVpd *d;
u32 pft_size[2];
snprintf(buf, 32, "PowerPC,%s", cur_cpu_spec->cpu_name);
p = strchr(buf, ' ');
if (!p) p = buf + strlen(buf);
dt_start_node(dt, "cpus");
dt_prop_u32(dt, "#address-cells", 1);
dt_prop_u32(dt, "#size-cells", 0);
pft_size[0] = 0;
pft_size[1] = __ilog2(HvCallHpt_getHptPages() * HW_PAGE_SIZE);
for (i = 0; i < NR_LPPACAS; i++) {
if (lppaca[i].dyn_proc_status >= 2)
continue;
snprintf(p, 32 - (p - buf), "@%d", i);
dt_start_node(dt, buf);
dt_prop_str(dt, "device_type", device_type_cpu);
index = lppaca[i].dyn_hv_phys_proc_index;
d = &xIoHriProcessorVpd[index];
dt_prop_u32(dt, "i-cache-size", d->xInstCacheSize * 1024);
dt_prop_u32(dt, "i-cache-line-size", d->xInstCacheOperandSize);
dt_prop_u32(dt, "d-cache-size", d->xDataL1CacheSizeKB * 1024);
dt_prop_u32(dt, "d-cache-line-size", d->xDataCacheOperandSize);
dt_prop_u32(dt, "clock-frequency",
((1UL << 34) * 1000000) / d->xProcFreq);
dt_prop_u32(dt, "timebase-frequency",
((1UL << 32) * 1000000) / d->xTimeBaseFreq);
dt_prop_u32(dt, "reg", i);
dt_prop_u32_list(dt, "ibm,pft-size", pft_size, 2);
dt_end_node(dt);
}
dt_end_node(dt);
}
static void __init dt_model(struct iseries_flat_dt *dt)
{
char buf[16] = "IBM,";
strne2a(buf + 4, xItExtVpdPanel.mfgID + 2, 2);
strne2a(buf + 6, xItExtVpdPanel.systemSerial + 1, 5);
buf[11] = '\0';
dt_prop_str(dt, "system-id", buf);
strne2a(buf + 4, xItExtVpdPanel.machineType, 4);
buf[8] = '\0';
dt_prop_str(dt, "model", buf);
dt_prop_str(dt, "compatible", "IBM,iSeries");
dt_prop_u32(dt, "ibm,partition-no", HvLpConfig_getLpIndex());
}
static void __init dt_initrd(struct iseries_flat_dt *dt)
{
#ifdef CONFIG_BLK_DEV_INITRD
if (naca.xRamDisk) {
dt_prop_u64(dt, "linux,initrd-start", (u64)naca.xRamDisk);
dt_prop_u64(dt, "linux,initrd-end",
(u64)naca.xRamDisk + naca.xRamDiskSize * HW_PAGE_SIZE);
}
#endif
}
static void __init dt_do_vdevice(struct iseries_flat_dt *dt,
const char *name, u32 reg, int unit,
const char *type, const char *compat, int end)
{
char buf[32];
snprintf(buf, 32, "%s@%08x", name, reg + ((unit >= 0) ? unit : 0));
dt_start_node(dt, buf);
dt_prop_str(dt, "device_type", type);
if (compat)
dt_prop_str(dt, "compatible", compat);
dt_prop_u32(dt, "reg", reg + ((unit >= 0) ? unit : 0));
if (unit >= 0)
dt_prop_u32(dt, "linux,unit_address", unit);
if (end)
dt_end_node(dt);
}
static void __init dt_vdevices(struct iseries_flat_dt *dt)
{
u32 reg = 0;
HvLpIndexMap vlan_map;
int i;
dt_start_node(dt, "vdevice");
dt_prop_str(dt, "device_type", device_type_vdevice);
dt_prop_str(dt, "compatible", "IBM,iSeries-vdevice");
dt_prop_u32(dt, "#address-cells", 1);
dt_prop_u32(dt, "#size-cells", 0);
dt_do_vdevice(dt, "vty", reg, -1, device_type_serial,
"IBM,iSeries-vty", 1);
reg++;
dt_do_vdevice(dt, "v-scsi", reg, -1, device_type_vscsi,
"IBM,v-scsi", 1);
reg++;
vlan_map = HvLpConfig_getVirtualLanIndexMap();
for (i = 0; i < HVMAXARCHITECTEDVIRTUALLANS; i++) {
unsigned char mac_addr[ETH_ALEN];
if ((vlan_map & (0x8000 >> i)) == 0)
continue;
dt_do_vdevice(dt, "l-lan", reg, i, device_type_network,
"IBM,iSeries-l-lan", 0);
mac_addr[0] = 0x02;
mac_addr[1] = 0x01;
mac_addr[2] = 0xff;
mac_addr[3] = i;
mac_addr[4] = 0xff;
mac_addr[5] = HvLpConfig_getLpIndex_outline();
dt_prop(dt, "local-mac-address", (char *)mac_addr, ETH_ALEN);
dt_prop(dt, "mac-address", (char *)mac_addr, ETH_ALEN);
dt_prop_u32(dt, "max-frame-size", 9000);
dt_prop_u32(dt, "address-bits", 48);
dt_end_node(dt);
}
dt_end_node(dt);
}
static struct pci_class_name * __init dt_find_pci_class_name(u16 class_code)
{
struct pci_class_name *cp;
for (cp = pci_class_name;
cp < &pci_class_name[ARRAY_SIZE(pci_class_name)]; cp++)
if (cp->code == class_code)
return cp;
return NULL;
}
static void __init scan_bridge_slot(struct iseries_flat_dt *dt,
HvBusNumber bus, struct HvCallPci_BridgeInfo *bridge_info)
{
HvSubBusNumber sub_bus = bridge_info->subBusNumber;
u16 vendor_id;
u16 device_id;
u32 class_id;
int err;
char buf[32];
u32 reg[5];
int id_sel = ISERIES_GET_DEVICE_FROM_SUBBUS(sub_bus);
int function = ISERIES_GET_FUNCTION_FROM_SUBBUS(sub_bus);
HvAgentId eads_id_sel = ISERIES_PCI_AGENTID(id_sel, function);
u8 devfn;
struct pci_class_name *cp;
for (id_sel = 1; id_sel <= bridge_info->maxAgents; id_sel++) {
for (function = 0; function < 8; function++) {
HvAgentId agent_id = ISERIES_PCI_AGENTID(id_sel,
function);
err = HvCallXm_connectBusUnit(bus, sub_bus,
agent_id, 0);
if (err) {
if (err != 0x302)
DBG("connectBusUnit(%x, %x, %x) %x\n",
bus, sub_bus, agent_id, err);
continue;
}
err = HvCallPci_configLoad16(bus, sub_bus, agent_id,
PCI_VENDOR_ID, &vendor_id);
if (err) {
DBG("ReadVendor(%x, %x, %x) %x\n",
bus, sub_bus, agent_id, err);
continue;
}
err = HvCallPci_configLoad16(bus, sub_bus, agent_id,
PCI_DEVICE_ID, &device_id);
if (err) {
DBG("ReadDevice(%x, %x, %x) %x\n",
bus, sub_bus, agent_id, err);
continue;
}
err = HvCallPci_configLoad32(bus, sub_bus, agent_id,
PCI_CLASS_REVISION , &class_id);
if (err) {
DBG("ReadClass(%x, %x, %x) %x\n",
bus, sub_bus, agent_id, err);
continue;
}
devfn = PCI_DEVFN(ISERIES_ENCODE_DEVICE(eads_id_sel),
function);
cp = dt_find_pci_class_name(class_id >> 16);
if (cp && cp->name)
strncpy(buf, cp->name, sizeof(buf) - 1);
else
snprintf(buf, sizeof(buf), "pci%x,%x",
vendor_id, device_id);
buf[sizeof(buf) - 1] = '\0';
snprintf(buf + strlen(buf), sizeof(buf) - strlen(buf),
"@%x", PCI_SLOT(devfn));
buf[sizeof(buf) - 1] = '\0';
if (function != 0)
snprintf(buf + strlen(buf),
sizeof(buf) - strlen(buf),
",%x", function);
dt_start_node(dt, buf);
reg[0] = (bus << 16) | (devfn << 8);
reg[1] = 0;
reg[2] = 0;
reg[3] = 0;
reg[4] = 0;
dt_prop_u32_list(dt, "reg", reg, 5);
if (cp && (cp->type || cp->name))
dt_prop_str(dt, "device_type",
cp->type ? cp->type : cp->name);
dt_prop_u32(dt, "vendor-id", vendor_id);
dt_prop_u32(dt, "device-id", device_id);
dt_prop_u32(dt, "class-code", class_id >> 8);
dt_prop_u32(dt, "revision-id", class_id & 0xff);
dt_prop_u32(dt, "linux,subbus", sub_bus);
dt_prop_u32(dt, "linux,agent-id", agent_id);
dt_prop_u32(dt, "linux,logical-slot-number",
bridge_info->logicalSlotNumber);
dt_end_node(dt);
}
}
}
static void __init scan_bridge(struct iseries_flat_dt *dt, HvBusNumber bus,
HvSubBusNumber sub_bus, int id_sel)
{
struct HvCallPci_BridgeInfo bridge_info;
HvAgentId agent_id;
int function;
int ret;
for (function = 0; function < 8; ++function) {
agent_id = ISERIES_PCI_AGENTID(id_sel, function);
ret = HvCallXm_connectBusUnit(bus, sub_bus, agent_id, 0);
if (ret != 0) {
if (ret != 0xb)
DBG("connectBusUnit(%x, %x, %x) %x\n",
bus, sub_bus, agent_id, ret);
continue;
}
DBG("found device at bus %d idsel %d func %d (AgentId %x)\n",
bus, id_sel, function, agent_id);
ret = HvCallPci_getBusUnitInfo(bus, sub_bus, agent_id,
iseries_hv_addr(&bridge_info),
sizeof(struct HvCallPci_BridgeInfo));
if (ret != 0)
continue;
DBG("bridge info: type %x subbus %x "
"maxAgents %x maxsubbus %x logslot %x\n",
bridge_info.busUnitInfo.deviceType,
bridge_info.subBusNumber,
bridge_info.maxAgents,
bridge_info.maxSubBusNumber,
bridge_info.logicalSlotNumber);
if (bridge_info.busUnitInfo.deviceType ==
HvCallPci_BridgeDevice)
scan_bridge_slot(dt, bus, &bridge_info);
else
DBG("PCI: Invalid Bridge Configuration(0x%02X)",
bridge_info.busUnitInfo.deviceType);
}
}
static void __init scan_phb(struct iseries_flat_dt *dt, HvBusNumber bus)
{
struct HvCallPci_DeviceInfo dev_info;
const HvSubBusNumber sub_bus = 0;
int err;
int id_sel;
const int max_agents = 8;
for (id_sel = 1; id_sel < max_agents; ++id_sel) {
err = HvCallPci_getDeviceInfo(bus, sub_bus, id_sel,
iseries_hv_addr(&dev_info),
sizeof(struct HvCallPci_DeviceInfo));
if (err) {
if (err != 0x302)
DBG("getDeviceInfo(%x, %x, %x) %x\n",
bus, sub_bus, id_sel, err);
continue;
}
if (dev_info.deviceType != HvCallPci_NodeDevice) {
DBG("PCI: Invalid System Configuration"
"(0x%02X) for bus 0x%02x id 0x%02x.\n",
dev_info.deviceType, bus, id_sel);
continue;
}
scan_bridge(dt, bus, sub_bus, id_sel);
}
}
static void __init dt_pci_devices(struct iseries_flat_dt *dt)
{
HvBusNumber bus;
char buf[32];
u32 buses[2];
int phb_num = 0;
for (bus = 0; bus < 256; bus++) {
int err = HvCallXm_testBus(bus);
if (err) {
if (err != 0x0301)
DBG("Unexpected Return on Probe(0x%02X) "
"0x%04X\n", bus, err);
continue;
}
DBG("bus %d appears to exist\n", bus);
snprintf(buf, 32, "pci@%d", phb_num);
dt_start_node(dt, buf);
dt_prop_str(dt, "device_type", device_type_pci);
dt_prop_str(dt, "compatible", "IBM,iSeries-Logical-PHB");
dt_prop_u32(dt, "#address-cells", 3);
dt_prop_u32(dt, "#size-cells", 2);
buses[0] = buses[1] = bus;
dt_prop_u32_list(dt, "bus-range", buses, 2);
scan_phb(dt, bus);
dt_end_node(dt);
phb_num++;
}
}
static void dt_finish(struct iseries_flat_dt *dt)
{
dt_push_u32(dt, OF_DT_END);
dt->header.totalsize = (unsigned long)dt_data - (unsigned long)dt;
klimit = ALIGN((unsigned long)dt_data, 8);
}
void * __init build_flat_dt(unsigned long phys_mem_size)
{
struct iseries_flat_dt *iseries_dt;
u64 tmp[2];
iseries_dt = dt_init();
dt_start_node(iseries_dt, "");
dt_prop_u32(iseries_dt, "#address-cells", 2);
dt_prop_u32(iseries_dt, "#size-cells", 2);
dt_model(iseries_dt);
dt_start_node(iseries_dt, "memory@0");
dt_prop_str(iseries_dt, "device_type", device_type_memory);
tmp[0] = 0;
tmp[1] = phys_mem_size;
dt_prop_u64_list(iseries_dt, "reg", tmp, 2);
dt_end_node(iseries_dt);
dt_start_node(iseries_dt, "chosen");
dt_prop_str(iseries_dt, "bootargs", cmd_line);
dt_initrd(iseries_dt);
dt_end_node(iseries_dt);
dt_cpus(iseries_dt);
dt_vdevices(iseries_dt);
dt_pci_devices(iseries_dt);
dt_end_node(iseries_dt);
dt_finish(iseries_dt);
return iseries_dt;
}
