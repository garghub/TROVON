int snd_hdac_ext_bus_parse_capabilities(struct hdac_ext_bus *ebus)
{
unsigned int cur_cap;
unsigned int offset;
struct hdac_bus *bus = &ebus->bus;
unsigned int counter = 0;
offset = snd_hdac_chip_readl(bus, LLCH);
do {
cur_cap = _snd_hdac_chip_read(l, bus, offset);
dev_dbg(bus->dev, "Capability version: 0x%x\n",
((cur_cap & AZX_CAP_HDR_VER_MASK) >> AZX_CAP_HDR_VER_OFF));
dev_dbg(bus->dev, "HDA capability ID: 0x%x\n",
(cur_cap & AZX_CAP_HDR_ID_MASK) >> AZX_CAP_HDR_ID_OFF);
switch ((cur_cap & AZX_CAP_HDR_ID_MASK) >> AZX_CAP_HDR_ID_OFF) {
case AZX_ML_CAP_ID:
dev_dbg(bus->dev, "Found ML capability\n");
ebus->mlcap = bus->remap_addr + offset;
break;
case AZX_GTS_CAP_ID:
dev_dbg(bus->dev, "Found GTS capability offset=%x\n", offset);
ebus->gtscap = bus->remap_addr + offset;
break;
case AZX_PP_CAP_ID:
dev_dbg(bus->dev, "Found PP capability offset=%x\n", offset);
ebus->ppcap = bus->remap_addr + offset;
break;
case AZX_SPB_CAP_ID:
dev_dbg(bus->dev, "Found SPB capability\n");
ebus->spbcap = bus->remap_addr + offset;
break;
case AZX_DRSM_CAP_ID:
dev_dbg(bus->dev, "Found DRSM capability\n");
ebus->drsmcap = bus->remap_addr + offset;
break;
default:
dev_dbg(bus->dev, "Unknown capability %d\n", cur_cap);
break;
}
counter++;
if (counter > HDAC_MAX_CAPS) {
dev_err(bus->dev, "We exceeded HDAC Ext capablities!!!\n");
break;
}
offset = cur_cap & AZX_CAP_HDR_NXT_PTR_MASK;
} while (offset);
return 0;
}
void snd_hdac_ext_bus_ppcap_enable(struct hdac_ext_bus *ebus, bool enable)
{
struct hdac_bus *bus = &ebus->bus;
if (!ebus->ppcap) {
dev_err(bus->dev, "Address of PP capability is NULL");
return;
}
if (enable)
snd_hdac_updatel(ebus->ppcap, AZX_REG_PP_PPCTL, 0, AZX_PPCTL_GPROCEN);
else
snd_hdac_updatel(ebus->ppcap, AZX_REG_PP_PPCTL, AZX_PPCTL_GPROCEN, 0);
}
void snd_hdac_ext_bus_ppcap_int_enable(struct hdac_ext_bus *ebus, bool enable)
{
struct hdac_bus *bus = &ebus->bus;
if (!ebus->ppcap) {
dev_err(bus->dev, "Address of PP capability is NULL\n");
return;
}
if (enable)
snd_hdac_updatel(ebus->ppcap, AZX_REG_PP_PPCTL, 0, AZX_PPCTL_PIE);
else
snd_hdac_updatel(ebus->ppcap, AZX_REG_PP_PPCTL, AZX_PPCTL_PIE, 0);
}
int snd_hdac_ext_bus_get_ml_capabilities(struct hdac_ext_bus *ebus)
{
int idx;
u32 link_count;
struct hdac_ext_link *hlink;
struct hdac_bus *bus = &ebus->bus;
link_count = readl(ebus->mlcap + AZX_REG_ML_MLCD) + 1;
dev_dbg(bus->dev, "In %s Link count: %d\n", __func__, link_count);
for (idx = 0; idx < link_count; idx++) {
hlink = kzalloc(sizeof(*hlink), GFP_KERNEL);
if (!hlink)
return -ENOMEM;
hlink->index = idx;
hlink->bus = bus;
hlink->ml_addr = ebus->mlcap + AZX_ML_BASE +
(AZX_ML_INTERVAL * idx);
hlink->lcaps = readl(hlink->ml_addr + AZX_REG_ML_LCAP);
hlink->lsdiid = readw(hlink->ml_addr + AZX_REG_ML_LSDIID);
list_add_tail(&hlink->list, &ebus->hlink_list);
}
return 0;
}
void snd_hdac_link_free_all(struct hdac_ext_bus *ebus)
{
struct hdac_ext_link *l;
while (!list_empty(&ebus->hlink_list)) {
l = list_first_entry(&ebus->hlink_list, struct hdac_ext_link, list);
list_del(&l->list);
kfree(l);
}
}
struct hdac_ext_link *snd_hdac_ext_bus_get_link(struct hdac_ext_bus *ebus,
const char *codec_name)
{
int i;
struct hdac_ext_link *hlink = NULL;
int bus_idx, addr;
if (sscanf(codec_name, "ehdaudio%dD%d", &bus_idx, &addr) != 2)
return NULL;
if (ebus->idx != bus_idx)
return NULL;
list_for_each_entry(hlink, &ebus->hlink_list, list) {
for (i = 0; i < HDA_MAX_CODECS; i++) {
if (hlink->lsdiid & (0x1 << addr))
return hlink;
}
}
return NULL;
}
static int check_hdac_link_power_active(struct hdac_ext_link *link, bool enable)
{
int timeout;
u32 val;
int mask = (1 << AZX_MLCTL_CPA);
udelay(3);
timeout = 150;
do {
val = readl(link->ml_addr + AZX_REG_ML_LCTL);
if (enable) {
if (((val & mask) >> AZX_MLCTL_CPA))
return 0;
} else {
if (!((val & mask) >> AZX_MLCTL_CPA))
return 0;
}
udelay(3);
} while (--timeout);
return -EIO;
}
int snd_hdac_ext_bus_link_power_up(struct hdac_ext_link *link)
{
snd_hdac_updatel(link->ml_addr, AZX_REG_ML_LCTL, 0, AZX_MLCTL_SPA);
return check_hdac_link_power_active(link, true);
}
int snd_hdac_ext_bus_link_power_down(struct hdac_ext_link *link)
{
snd_hdac_updatel(link->ml_addr, AZX_REG_ML_LCTL, AZX_MLCTL_SPA, 0);
return check_hdac_link_power_active(link, false);
}
int snd_hdac_ext_bus_link_power_up_all(struct hdac_ext_bus *ebus)
{
struct hdac_ext_link *hlink = NULL;
int ret;
list_for_each_entry(hlink, &ebus->hlink_list, list) {
snd_hdac_updatel(hlink->ml_addr,
AZX_REG_ML_LCTL, 0, AZX_MLCTL_SPA);
ret = check_hdac_link_power_active(hlink, true);
if (ret < 0)
return ret;
}
return 0;
}
int snd_hdac_ext_bus_link_power_down_all(struct hdac_ext_bus *ebus)
{
struct hdac_ext_link *hlink = NULL;
int ret;
list_for_each_entry(hlink, &ebus->hlink_list, list) {
snd_hdac_updatel(hlink->ml_addr, AZX_REG_ML_LCTL, AZX_MLCTL_SPA, 0);
ret = check_hdac_link_power_active(hlink, false);
if (ret < 0)
return ret;
}
return 0;
}
