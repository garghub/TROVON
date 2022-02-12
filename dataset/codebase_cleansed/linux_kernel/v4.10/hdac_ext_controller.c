void snd_hdac_ext_bus_ppcap_enable(struct hdac_ext_bus *ebus, bool enable)
{
struct hdac_bus *bus = &ebus->bus;
if (!bus->ppcap) {
dev_err(bus->dev, "Address of PP capability is NULL");
return;
}
if (enable)
snd_hdac_updatel(bus->ppcap, AZX_REG_PP_PPCTL, 0, AZX_PPCTL_GPROCEN);
else
snd_hdac_updatel(bus->ppcap, AZX_REG_PP_PPCTL, AZX_PPCTL_GPROCEN, 0);
}
void snd_hdac_ext_bus_ppcap_int_enable(struct hdac_ext_bus *ebus, bool enable)
{
struct hdac_bus *bus = &ebus->bus;
if (!bus->ppcap) {
dev_err(bus->dev, "Address of PP capability is NULL\n");
return;
}
if (enable)
snd_hdac_updatel(bus->ppcap, AZX_REG_PP_PPCTL, 0, AZX_PPCTL_PIE);
else
snd_hdac_updatel(bus->ppcap, AZX_REG_PP_PPCTL, AZX_PPCTL_PIE, 0);
}
int snd_hdac_ext_bus_get_ml_capabilities(struct hdac_ext_bus *ebus)
{
int idx;
u32 link_count;
struct hdac_ext_link *hlink;
struct hdac_bus *bus = &ebus->bus;
link_count = readl(bus->mlcap + AZX_REG_ML_MLCD) + 1;
dev_dbg(bus->dev, "In %s Link count: %d\n", __func__, link_count);
for (idx = 0; idx < link_count; idx++) {
hlink = kzalloc(sizeof(*hlink), GFP_KERNEL);
if (!hlink)
return -ENOMEM;
hlink->index = idx;
hlink->bus = bus;
hlink->ml_addr = bus->mlcap + AZX_ML_BASE +
(AZX_ML_INTERVAL * idx);
hlink->lcaps = readl(hlink->ml_addr + AZX_REG_ML_LCAP);
hlink->lsdiid = readw(hlink->ml_addr + AZX_REG_ML_LSDIID);
hlink->ref_count = 1;
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
int snd_hdac_ext_bus_link_get(struct hdac_ext_bus *ebus,
struct hdac_ext_link *link)
{
int ret = 0;
mutex_lock(&ebus->lock);
if (++link->ref_count == 1) {
if (!ebus->cmd_dma_state) {
snd_hdac_bus_init_cmd_io(&ebus->bus);
ebus->cmd_dma_state = true;
}
ret = snd_hdac_ext_bus_link_power_up(link);
}
mutex_unlock(&ebus->lock);
return ret;
}
int snd_hdac_ext_bus_link_put(struct hdac_ext_bus *ebus,
struct hdac_ext_link *link)
{
int ret = 0;
struct hdac_ext_link *hlink;
bool link_up = false;
mutex_lock(&ebus->lock);
if (--link->ref_count == 0) {
ret = snd_hdac_ext_bus_link_power_down(link);
list_for_each_entry(hlink, &ebus->hlink_list, list) {
if (hlink->ref_count) {
link_up = true;
break;
}
}
if (!link_up) {
snd_hdac_bus_stop_cmd_io(&ebus->bus);
ebus->cmd_dma_state = false;
}
}
mutex_unlock(&ebus->lock);
return ret;
}
