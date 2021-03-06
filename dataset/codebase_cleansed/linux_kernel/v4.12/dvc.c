static void rsnd_dvc_activation(struct rsnd_mod *mod)
{
rsnd_mod_write(mod, DVC_SWRSR, 0);
rsnd_mod_write(mod, DVC_SWRSR, 1);
}
static void rsnd_dvc_halt(struct rsnd_mod *mod)
{
rsnd_mod_write(mod, DVC_DVUIR, 1);
rsnd_mod_write(mod, DVC_SWRSR, 0);
}
static void rsnd_dvc_volume_parameter(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
u32 val[RSND_MAX_CHANNELS];
int i;
if (dvc->ren.val)
for (i = 0; i < RSND_MAX_CHANNELS; i++)
val[i] = dvc->volume.cfg.max;
else
for (i = 0; i < RSND_MAX_CHANNELS; i++)
val[i] = dvc->volume.val[i];
rsnd_mod_write(mod, DVC_VOL0R, val[0]);
rsnd_mod_write(mod, DVC_VOL1R, val[1]);
rsnd_mod_write(mod, DVC_VOL2R, val[2]);
rsnd_mod_write(mod, DVC_VOL3R, val[3]);
rsnd_mod_write(mod, DVC_VOL4R, val[4]);
rsnd_mod_write(mod, DVC_VOL5R, val[5]);
rsnd_mod_write(mod, DVC_VOL6R, val[6]);
rsnd_mod_write(mod, DVC_VOL7R, val[7]);
}
static void rsnd_dvc_volume_init(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
u32 adinr = 0;
u32 dvucr = 0;
u32 vrctr = 0;
u32 vrpdr = 0;
u32 vrdbr = 0;
adinr = rsnd_get_adinr_bit(mod, io) |
rsnd_runtime_channel_after_ctu(io);
dvucr |= 0x101;
if (dvc->ren.val) {
dvucr |= 0x10;
vrctr = 0xff;
vrpdr = rsnd_dvc_get_vrpdr(dvc);
vrdbr = rsnd_dvc_get_vrdbr(dvc);
}
rsnd_mod_write(mod, DVC_DVUIR, 1);
rsnd_mod_write(mod, DVC_ADINR, adinr);
rsnd_mod_write(mod, DVC_DVUCR, dvucr);
rsnd_mod_write(mod, DVC_VRCTR, vrctr);
rsnd_mod_write(mod, DVC_VRPDR, vrpdr);
rsnd_mod_write(mod, DVC_VRDBR, vrdbr);
rsnd_dvc_volume_parameter(io, mod);
rsnd_mod_write(mod, DVC_DVUIR, 0);
}
static void rsnd_dvc_volume_update(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
u32 zcmcr = 0;
u32 vrpdr = 0;
u32 vrdbr = 0;
int i;
for (i = 0; i < dvc->mute.cfg.size; i++)
zcmcr |= (!!dvc->mute.cfg.val[i]) << i;
if (dvc->ren.val) {
vrpdr = rsnd_dvc_get_vrpdr(dvc);
vrdbr = rsnd_dvc_get_vrdbr(dvc);
}
rsnd_mod_write(mod, DVC_DVUER, 0);
rsnd_mod_write(mod, DVC_ZCMCR, zcmcr);
rsnd_mod_write(mod, DVC_VRPDR, vrpdr);
rsnd_mod_write(mod, DVC_VRDBR, vrdbr);
rsnd_dvc_volume_parameter(io, mod);
rsnd_mod_write(mod, DVC_DVUER, 1);
}
static int rsnd_dvc_probe_(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
return rsnd_cmd_attach(io, rsnd_mod_id(mod));
}
static int rsnd_dvc_init(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
rsnd_mod_power_on(mod);
rsnd_dvc_activation(mod);
rsnd_dvc_volume_init(io, mod);
rsnd_dvc_volume_update(io, mod);
return 0;
}
static int rsnd_dvc_quit(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
rsnd_dvc_halt(mod);
rsnd_mod_power_off(mod);
return 0;
}
static int rsnd_dvc_pcm_new(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct snd_soc_pcm_runtime *rtd)
{
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
int is_play = rsnd_io_is_play(io);
int slots = rsnd_get_slot(io);
int ret;
ret = rsnd_kctrl_new_m(mod, io, rtd,
is_play ?
"DVC Out Playback Volume" : "DVC In Capture Volume",
rsnd_dvc_volume_update,
&dvc->volume, slots,
0x00800000 - 1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_m(mod, io, rtd,
is_play ?
"DVC Out Mute Switch" : "DVC In Mute Switch",
rsnd_dvc_volume_update,
&dvc->mute, slots,
1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_s(mod, io, rtd,
is_play ?
"DVC Out Ramp Switch" : "DVC In Ramp Switch",
rsnd_dvc_volume_update,
&dvc->ren, 1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_e(mod, io, rtd,
is_play ?
"DVC Out Ramp Up Rate" : "DVC In Ramp Up Rate",
rsnd_dvc_volume_update,
&dvc->rup,
dvc_ramp_rate);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_e(mod, io, rtd,
is_play ?
"DVC Out Ramp Down Rate" : "DVC In Ramp Down Rate",
rsnd_dvc_volume_update,
&dvc->rdown,
dvc_ramp_rate);
if (ret < 0)
return ret;
return 0;
}
static struct dma_chan *rsnd_dvc_dma_req(struct rsnd_dai_stream *io,
struct rsnd_mod *mod)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
return rsnd_dma_request_channel(rsnd_dvc_of_node(priv),
mod, "tx");
}
struct rsnd_mod *rsnd_dvc_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_dvc_nr(priv)))
id = 0;
return rsnd_mod_get(rsnd_dvc_get(priv, id));
}
int rsnd_dvc_probe(struct rsnd_priv *priv)
{
struct device_node *node;
struct device_node *np;
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_dvc *dvc;
struct clk *clk;
char name[RSND_DVC_NAME_SIZE];
int i, nr, ret;
if (rsnd_is_gen1(priv))
return 0;
node = rsnd_dvc_of_node(priv);
if (!node)
return 0;
nr = of_get_child_count(node);
if (!nr) {
ret = -EINVAL;
goto rsnd_dvc_probe_done;
}
dvc = devm_kzalloc(dev, sizeof(*dvc) * nr, GFP_KERNEL);
if (!dvc) {
ret = -ENOMEM;
goto rsnd_dvc_probe_done;
}
priv->dvc_nr = nr;
priv->dvc = dvc;
i = 0;
ret = 0;
for_each_child_of_node(node, np) {
dvc = rsnd_dvc_get(priv, i);
snprintf(name, RSND_DVC_NAME_SIZE, "%s.%d",
DVC_NAME, i);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
goto rsnd_dvc_probe_done;
}
ret = rsnd_mod_init(priv, rsnd_mod_get(dvc), &rsnd_dvc_ops,
clk, rsnd_mod_get_status, RSND_MOD_DVC, i);
if (ret)
goto rsnd_dvc_probe_done;
i++;
}
rsnd_dvc_probe_done:
of_node_put(node);
return ret;
}
void rsnd_dvc_remove(struct rsnd_priv *priv)
{
struct rsnd_dvc *dvc;
int i;
for_each_rsnd_dvc(dvc, priv, i) {
rsnd_mod_quit(rsnd_mod_get(dvc));
}
}
