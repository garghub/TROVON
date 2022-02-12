void snd_hdac_ext_stream_init(struct hdac_ext_bus *ebus,
struct hdac_ext_stream *stream,
int idx, int direction, int tag)
{
struct hdac_bus *bus = &ebus->bus;
if (ebus->ppcap) {
stream->pphc_addr = ebus->ppcap + AZX_PPHC_BASE +
AZX_PPHC_INTERVAL * idx;
stream->pplc_addr = ebus->ppcap + AZX_PPLC_BASE +
AZX_PPLC_MULTI * ebus->num_streams +
AZX_PPLC_INTERVAL * idx;
}
if (ebus->spbcap) {
stream->spib_addr = ebus->spbcap + AZX_SPB_BASE +
AZX_SPB_INTERVAL * idx +
AZX_SPB_SPIB;
stream->fifo_addr = ebus->spbcap + AZX_SPB_BASE +
AZX_SPB_INTERVAL * idx +
AZX_SPB_MAXFIFO;
}
stream->decoupled = false;
snd_hdac_stream_init(bus, &stream->hstream, idx, direction, tag);
}
int snd_hdac_ext_stream_init_all(struct hdac_ext_bus *ebus, int start_idx,
int num_stream, int dir)
{
int stream_tag = 0;
int i, tag, idx = start_idx;
for (i = 0; i < num_stream; i++) {
struct hdac_ext_stream *stream =
kzalloc(sizeof(*stream), GFP_KERNEL);
if (!stream)
return -ENOMEM;
tag = ++stream_tag;
snd_hdac_ext_stream_init(ebus, stream, idx, dir, tag);
idx++;
}
return 0;
}
void snd_hdac_stream_free_all(struct hdac_ext_bus *ebus)
{
struct hdac_stream *s;
struct hdac_ext_stream *stream;
struct hdac_bus *bus = ebus_to_hbus(ebus);
while (!list_empty(&bus->stream_list)) {
s = list_first_entry(&bus->stream_list, struct hdac_stream, list);
stream = stream_to_hdac_ext_stream(s);
list_del(&s->list);
kfree(stream);
}
}
void snd_hdac_ext_stream_decouple(struct hdac_ext_bus *ebus,
struct hdac_ext_stream *stream, bool decouple)
{
struct hdac_stream *hstream = &stream->hstream;
struct hdac_bus *bus = &ebus->bus;
spin_lock_irq(&bus->reg_lock);
if (decouple)
snd_hdac_updatel(ebus->ppcap, AZX_REG_PP_PPCTL, 0,
AZX_PPCTL_PROCEN(hstream->index));
else
snd_hdac_updatel(ebus->ppcap, AZX_REG_PP_PPCTL,
AZX_PPCTL_PROCEN(hstream->index), 0);
stream->decoupled = decouple;
spin_unlock_irq(&bus->reg_lock);
}
void snd_hdac_ext_link_stream_start(struct hdac_ext_stream *stream)
{
snd_hdac_updatel(stream->pplc_addr, AZX_REG_PPLCCTL, 0, AZX_PPLCCTL_RUN);
}
void snd_hdac_ext_link_stream_clear(struct hdac_ext_stream *stream)
{
snd_hdac_updatel(stream->pplc_addr, AZX_REG_PPLCCTL, AZX_PPLCCTL_RUN, 0);
}
void snd_hdac_ext_link_stream_reset(struct hdac_ext_stream *stream)
{
unsigned char val;
int timeout;
snd_hdac_ext_link_stream_clear(stream);
snd_hdac_updatel(stream->pplc_addr, AZX_REG_PPLCCTL, 0, AZX_PPLCCTL_STRST);
udelay(3);
timeout = 50;
do {
val = readl(stream->pplc_addr + AZX_REG_PPLCCTL) &
AZX_PPLCCTL_STRST;
if (val)
break;
udelay(3);
} while (--timeout);
val &= ~AZX_PPLCCTL_STRST;
writel(val, stream->pplc_addr + AZX_REG_PPLCCTL);
udelay(3);
timeout = 50;
do {
val = readl(stream->pplc_addr + AZX_REG_PPLCCTL) & AZX_PPLCCTL_STRST;
if (!val)
break;
udelay(3);
} while (--timeout);
}
int snd_hdac_ext_link_stream_setup(struct hdac_ext_stream *stream, int fmt)
{
struct hdac_stream *hstream = &stream->hstream;
unsigned int val;
snd_hdac_ext_link_stream_clear(stream);
val = readl(stream->pplc_addr + AZX_REG_PPLCCTL);
val = (val & ~AZX_PPLCCTL_STRM_MASK) |
(hstream->stream_tag << AZX_PPLCCTL_STRM_SHIFT);
writel(val, stream->pplc_addr + AZX_REG_PPLCCTL);
writew(fmt, stream->pplc_addr + AZX_REG_PPLCFMT);
return 0;
}
void snd_hdac_ext_link_set_stream_id(struct hdac_ext_link *link,
int stream)
{
snd_hdac_updatew(link->ml_addr, AZX_REG_ML_LOSIDV, (1 << stream), 0);
}
void snd_hdac_ext_link_clear_stream_id(struct hdac_ext_link *link,
int stream)
{
snd_hdac_updatew(link->ml_addr, AZX_REG_ML_LOSIDV, 0, (1 << stream));
}
static struct hdac_ext_stream *
hdac_ext_link_stream_assign(struct hdac_ext_bus *ebus,
struct snd_pcm_substream *substream)
{
struct hdac_ext_stream *res = NULL;
struct hdac_stream *stream = NULL;
struct hdac_bus *hbus = &ebus->bus;
if (!ebus->ppcap) {
dev_err(hbus->dev, "stream type not supported\n");
return NULL;
}
list_for_each_entry(stream, &hbus->stream_list, list) {
struct hdac_ext_stream *hstream = container_of(stream,
struct hdac_ext_stream,
hstream);
if (stream->direction != substream->stream)
continue;
if (hstream->decoupled && !hstream->link_locked) {
res = hstream;
break;
}
if (!hstream->link_locked) {
snd_hdac_ext_stream_decouple(ebus, hstream, true);
res = hstream;
break;
}
}
if (res) {
spin_lock_irq(&hbus->reg_lock);
res->link_locked = 1;
res->link_substream = substream;
spin_unlock_irq(&hbus->reg_lock);
}
return res;
}
static struct hdac_ext_stream *
hdac_ext_host_stream_assign(struct hdac_ext_bus *ebus,
struct snd_pcm_substream *substream)
{
struct hdac_ext_stream *res = NULL;
struct hdac_stream *stream = NULL;
struct hdac_bus *hbus = &ebus->bus;
if (!ebus->ppcap) {
dev_err(hbus->dev, "stream type not supported\n");
return NULL;
}
list_for_each_entry(stream, &hbus->stream_list, list) {
struct hdac_ext_stream *hstream = container_of(stream,
struct hdac_ext_stream,
hstream);
if (stream->direction != substream->stream)
continue;
if (!stream->opened) {
if (!hstream->decoupled)
snd_hdac_ext_stream_decouple(ebus, hstream, true);
res = hstream;
break;
}
}
if (res) {
spin_lock_irq(&hbus->reg_lock);
res->hstream.opened = 1;
res->hstream.running = 0;
res->hstream.substream = substream;
spin_unlock_irq(&hbus->reg_lock);
}
return res;
}
struct hdac_ext_stream *snd_hdac_ext_stream_assign(struct hdac_ext_bus *ebus,
struct snd_pcm_substream *substream,
int type)
{
struct hdac_ext_stream *hstream = NULL;
struct hdac_stream *stream = NULL;
struct hdac_bus *hbus = &ebus->bus;
switch (type) {
case HDAC_EXT_STREAM_TYPE_COUPLED:
stream = snd_hdac_stream_assign(hbus, substream);
if (stream)
hstream = container_of(stream,
struct hdac_ext_stream, hstream);
return hstream;
case HDAC_EXT_STREAM_TYPE_HOST:
return hdac_ext_host_stream_assign(ebus, substream);
case HDAC_EXT_STREAM_TYPE_LINK:
return hdac_ext_link_stream_assign(ebus, substream);
default:
return NULL;
}
}
void snd_hdac_ext_stream_release(struct hdac_ext_stream *stream, int type)
{
struct hdac_bus *bus = stream->hstream.bus;
struct hdac_ext_bus *ebus = hbus_to_ebus(bus);
switch (type) {
case HDAC_EXT_STREAM_TYPE_COUPLED:
snd_hdac_stream_release(&stream->hstream);
break;
case HDAC_EXT_STREAM_TYPE_HOST:
if (stream->decoupled) {
snd_hdac_ext_stream_decouple(ebus, stream, false);
snd_hdac_stream_release(&stream->hstream);
}
break;
case HDAC_EXT_STREAM_TYPE_LINK:
if (stream->decoupled)
snd_hdac_ext_stream_decouple(ebus, stream, false);
spin_lock_irq(&bus->reg_lock);
stream->link_locked = 0;
stream->link_substream = NULL;
spin_unlock_irq(&bus->reg_lock);
break;
default:
dev_dbg(bus->dev, "Invalid type %d\n", type);
}
}
void snd_hdac_ext_stream_spbcap_enable(struct hdac_ext_bus *ebus,
bool enable, int index)
{
u32 mask = 0;
u32 register_mask = 0;
struct hdac_bus *bus = &ebus->bus;
if (!ebus->spbcap) {
dev_err(bus->dev, "Address of SPB capability is NULL");
return;
}
mask |= (1 << index);
register_mask = readl(ebus->spbcap + AZX_REG_SPB_SPBFCCTL);
mask |= register_mask;
if (enable)
snd_hdac_updatel(ebus->spbcap, AZX_REG_SPB_SPBFCCTL, 0, mask);
else
snd_hdac_updatel(ebus->spbcap, AZX_REG_SPB_SPBFCCTL, mask, 0);
}
int snd_hdac_ext_stream_set_spib(struct hdac_ext_bus *ebus,
struct hdac_ext_stream *stream, u32 value)
{
struct hdac_bus *bus = &ebus->bus;
if (!ebus->spbcap) {
dev_err(bus->dev, "Address of SPB capability is NULL");
return -EINVAL;
}
writel(value, stream->spib_addr);
return 0;
}
int snd_hdac_ext_stream_get_spbmaxfifo(struct hdac_ext_bus *ebus,
struct hdac_ext_stream *stream)
{
struct hdac_bus *bus = &ebus->bus;
if (!ebus->spbcap) {
dev_err(bus->dev, "Address of SPB capability is NULL");
return -EINVAL;
}
return readl(stream->fifo_addr);
}
void snd_hdac_ext_stop_streams(struct hdac_ext_bus *ebus)
{
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct hdac_stream *stream;
if (bus->chip_init) {
list_for_each_entry(stream, &bus->stream_list, list)
snd_hdac_stream_stop(stream);
snd_hdac_bus_stop_chip(bus);
}
}
