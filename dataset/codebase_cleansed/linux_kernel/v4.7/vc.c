static void pci_vc_save_restore_dwords(struct pci_dev *dev, int pos,
u32 *buf, int dwords, bool save)
{
int i;
for (i = 0; i < dwords; i++, buf++) {
if (save)
pci_read_config_dword(dev, pos + (i * 4), buf);
else
pci_write_config_dword(dev, pos + (i * 4), *buf);
}
}
static void pci_vc_load_arb_table(struct pci_dev *dev, int pos)
{
u16 ctrl;
pci_read_config_word(dev, pos + PCI_VC_PORT_CTRL, &ctrl);
pci_write_config_word(dev, pos + PCI_VC_PORT_CTRL,
ctrl | PCI_VC_PORT_CTRL_LOAD_TABLE);
if (pci_wait_for_pending(dev, pos + PCI_VC_PORT_STATUS,
PCI_VC_PORT_STATUS_TABLE))
return;
dev_err(&dev->dev, "VC arbitration table failed to load\n");
}
static void pci_vc_load_port_arb_table(struct pci_dev *dev, int pos, int res)
{
int ctrl_pos, status_pos;
u32 ctrl;
ctrl_pos = pos + PCI_VC_RES_CTRL + (res * PCI_CAP_VC_PER_VC_SIZEOF);
status_pos = pos + PCI_VC_RES_STATUS + (res * PCI_CAP_VC_PER_VC_SIZEOF);
pci_read_config_dword(dev, ctrl_pos, &ctrl);
pci_write_config_dword(dev, ctrl_pos,
ctrl | PCI_VC_RES_CTRL_LOAD_TABLE);
if (pci_wait_for_pending(dev, status_pos, PCI_VC_RES_STATUS_TABLE))
return;
dev_err(&dev->dev, "VC%d port arbitration table failed to load\n", res);
}
static void pci_vc_enable(struct pci_dev *dev, int pos, int res)
{
int ctrl_pos, status_pos, id, pos2, evcc, i, ctrl_pos2, status_pos2;
u32 ctrl, header, cap1, ctrl2;
struct pci_dev *link = NULL;
if (!dev->has_secondary_link)
return;
ctrl_pos = pos + PCI_VC_RES_CTRL + (res * PCI_CAP_VC_PER_VC_SIZEOF);
status_pos = pos + PCI_VC_RES_STATUS + (res * PCI_CAP_VC_PER_VC_SIZEOF);
pci_read_config_dword(dev, ctrl_pos, &ctrl);
id = ctrl & PCI_VC_RES_CTRL_ID;
pci_read_config_dword(dev, pos, &header);
if (PCI_EXT_CAP_ID(header) == PCI_EXT_CAP_ID_VC9 ||
pci_is_root_bus(dev->bus))
goto enable;
pos2 = pci_find_ext_capability(dev->bus->self, PCI_EXT_CAP_ID_VC);
if (!pos2)
goto enable;
pci_read_config_dword(dev->bus->self, pos2 + PCI_VC_PORT_CAP1, &cap1);
evcc = cap1 & PCI_VC_CAP1_EVCC;
for (i = 1; i < evcc + 1; i++) {
ctrl_pos2 = pos2 + PCI_VC_RES_CTRL +
(i * PCI_CAP_VC_PER_VC_SIZEOF);
status_pos2 = pos2 + PCI_VC_RES_STATUS +
(i * PCI_CAP_VC_PER_VC_SIZEOF);
pci_read_config_dword(dev->bus->self, ctrl_pos2, &ctrl2);
if ((ctrl2 & PCI_VC_RES_CTRL_ID) == id) {
link = dev->bus->self;
break;
}
}
if (!link)
goto enable;
if (ctrl2 & PCI_VC_RES_CTRL_ENABLE) {
ctrl2 &= ~PCI_VC_RES_CTRL_ENABLE;
pci_write_config_dword(link, ctrl_pos2, ctrl2);
}
ctrl2 |= PCI_VC_RES_CTRL_ENABLE;
pci_write_config_dword(link, ctrl_pos2, ctrl2);
enable:
ctrl |= PCI_VC_RES_CTRL_ENABLE;
pci_write_config_dword(dev, ctrl_pos, ctrl);
if (!pci_wait_for_pending(dev, status_pos, PCI_VC_RES_STATUS_NEGO))
dev_err(&dev->dev, "VC%d negotiation stuck pending\n", id);
if (link && !pci_wait_for_pending(link, status_pos2,
PCI_VC_RES_STATUS_NEGO))
dev_err(&link->dev, "VC%d negotiation stuck pending\n", id);
}
static int pci_vc_do_save_buffer(struct pci_dev *dev, int pos,
struct pci_cap_saved_state *save_state,
bool save)
{
u32 cap1;
char evcc, lpevcc, parb_size;
int i, len = 0;
u8 *buf = save_state ? (u8 *)save_state->cap.data : NULL;
if (buf && save_state->cap.size !=
pci_vc_do_save_buffer(dev, pos, NULL, save)) {
dev_err(&dev->dev,
"VC save buffer size does not match @0x%x\n", pos);
return -ENOMEM;
}
pci_read_config_dword(dev, pos + PCI_VC_PORT_CAP1, &cap1);
evcc = cap1 & PCI_VC_CAP1_EVCC;
lpevcc = (cap1 & PCI_VC_CAP1_LPEVCC) >> 4;
parb_size = 1 << ((cap1 & PCI_VC_CAP1_ARB_SIZE) >> 10);
if (buf) {
if (save)
pci_read_config_word(dev, pos + PCI_VC_PORT_CTRL,
(u16 *)buf);
else
pci_write_config_word(dev, pos + PCI_VC_PORT_CTRL,
*(u16 *)buf);
buf += 4;
}
len += 4;
if (lpevcc) {
u32 cap2;
int vcarb_offset;
pci_read_config_dword(dev, pos + PCI_VC_PORT_CAP2, &cap2);
vcarb_offset = ((cap2 & PCI_VC_CAP2_ARB_OFF) >> 24) * 16;
if (vcarb_offset) {
int size, vcarb_phases = 0;
if (cap2 & PCI_VC_CAP2_128_PHASE)
vcarb_phases = 128;
else if (cap2 & PCI_VC_CAP2_64_PHASE)
vcarb_phases = 64;
else if (cap2 & PCI_VC_CAP2_32_PHASE)
vcarb_phases = 32;
size = ((lpevcc + 1) * vcarb_phases * 4) / 8;
if (size && buf) {
pci_vc_save_restore_dwords(dev,
pos + vcarb_offset,
(u32 *)buf,
size / 4, save);
if (!save)
pci_vc_load_arb_table(dev, pos);
buf += size;
}
len += size;
}
}
for (i = 0; i < evcc + 1; i++) {
u32 cap;
int parb_offset;
pci_read_config_dword(dev, pos + PCI_VC_RES_CAP +
(i * PCI_CAP_VC_PER_VC_SIZEOF), &cap);
parb_offset = ((cap & PCI_VC_RES_CAP_ARB_OFF) >> 24) * 16;
if (parb_offset) {
int size, parb_phases = 0;
if (cap & PCI_VC_RES_CAP_256_PHASE)
parb_phases = 256;
else if (cap & (PCI_VC_RES_CAP_128_PHASE |
PCI_VC_RES_CAP_128_PHASE_TB))
parb_phases = 128;
else if (cap & PCI_VC_RES_CAP_64_PHASE)
parb_phases = 64;
else if (cap & PCI_VC_RES_CAP_32_PHASE)
parb_phases = 32;
size = (parb_size * parb_phases) / 8;
if (size && buf) {
pci_vc_save_restore_dwords(dev,
pos + parb_offset,
(u32 *)buf,
size / 4, save);
buf += size;
}
len += size;
}
if (buf) {
int ctrl_pos = pos + PCI_VC_RES_CTRL +
(i * PCI_CAP_VC_PER_VC_SIZEOF);
if (save)
pci_read_config_dword(dev, ctrl_pos,
(u32 *)buf);
else {
u32 tmp, ctrl = *(u32 *)buf;
pci_read_config_dword(dev, ctrl_pos, &tmp);
tmp &= PCI_VC_RES_CTRL_ENABLE;
tmp |= ctrl & ~PCI_VC_RES_CTRL_ENABLE;
pci_write_config_dword(dev, ctrl_pos, tmp);
if (ctrl & PCI_VC_RES_CTRL_ARB_SELECT)
pci_vc_load_port_arb_table(dev, pos, i);
if ((ctrl ^ tmp) & PCI_VC_RES_CTRL_ENABLE)
pci_vc_enable(dev, pos, i);
}
buf += 4;
}
len += 4;
}
return buf ? 0 : len;
}
int pci_save_vc_state(struct pci_dev *dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(vc_caps); i++) {
int pos, ret;
struct pci_cap_saved_state *save_state;
pos = pci_find_ext_capability(dev, vc_caps[i].id);
if (!pos)
continue;
save_state = pci_find_saved_ext_cap(dev, vc_caps[i].id);
if (!save_state) {
dev_err(&dev->dev, "%s buffer not found in %s\n",
vc_caps[i].name, __func__);
return -ENOMEM;
}
ret = pci_vc_do_save_buffer(dev, pos, save_state, true);
if (ret) {
dev_err(&dev->dev, "%s save unsuccessful %s\n",
vc_caps[i].name, __func__);
return ret;
}
}
return 0;
}
void pci_restore_vc_state(struct pci_dev *dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(vc_caps); i++) {
int pos;
struct pci_cap_saved_state *save_state;
pos = pci_find_ext_capability(dev, vc_caps[i].id);
save_state = pci_find_saved_ext_cap(dev, vc_caps[i].id);
if (!save_state || !pos)
continue;
pci_vc_do_save_buffer(dev, pos, save_state, false);
}
}
void pci_allocate_vc_save_buffers(struct pci_dev *dev)
{
int i;
for (i = 0; i < ARRAY_SIZE(vc_caps); i++) {
int len, pos = pci_find_ext_capability(dev, vc_caps[i].id);
if (!pos)
continue;
len = pci_vc_do_save_buffer(dev, pos, NULL, false);
if (pci_add_ext_cap_save_buffer(dev, vc_caps[i].id, len))
dev_err(&dev->dev,
"unable to preallocate %s save buffer\n",
vc_caps[i].name);
}
}
