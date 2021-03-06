static int rsnd_ssiu_init(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
struct rsnd_dai *rdai = rsnd_io_to_rdai(io);
u32 multi_ssi_slaves = rsnd_ssi_multi_slaves_runtime(io);
int use_busif = rsnd_ssi_use_busif(io);
int id = rsnd_mod_id(mod);
u32 mask1, val1;
u32 mask2, val2;
switch (id) {
case 0:
case 1:
case 2:
case 3:
case 4:
rsnd_mod_write(mod, SSI_SYS_STATUS0, 0xf << (id * 4));
rsnd_mod_write(mod, SSI_SYS_STATUS2, 0xf << (id * 4));
rsnd_mod_write(mod, SSI_SYS_STATUS4, 0xf << (id * 4));
rsnd_mod_write(mod, SSI_SYS_STATUS6, 0xf << (id * 4));
break;
case 9:
rsnd_mod_write(mod, SSI_SYS_STATUS1, 0xf << 4);
rsnd_mod_write(mod, SSI_SYS_STATUS3, 0xf << 4);
rsnd_mod_write(mod, SSI_SYS_STATUS5, 0xf << 4);
rsnd_mod_write(mod, SSI_SYS_STATUS7, 0xf << 4);
break;
}
rsnd_mod_bset(mod, SSI_MODE0, (1 << id), !use_busif << id);
mask1 = (1 << 4) | (1 << 20);
mask2 = (1 << 4);
val1 = val2 = 0;
if (id == 8) {
} else if (rsnd_ssi_is_pin_sharing(io)) {
int shift = -1;
switch (id) {
case 1:
shift = 0;
break;
case 2:
shift = 2;
break;
case 4:
shift = 16;
break;
default:
return -EINVAL;
}
mask1 |= 0x3 << shift;
val1 = rsnd_rdai_is_clk_master(rdai) ?
0x2 << shift : 0x1 << shift;
} else if (multi_ssi_slaves) {
mask2 |= 0x00000007;
mask1 |= 0x0000000f;
switch (multi_ssi_slaves) {
case 0x0206:
val2 = (1 << 4) |
(rsnd_rdai_is_clk_master(rdai) ? 0x2 : 0x1);
case 0x0006:
val1 = rsnd_rdai_is_clk_master(rdai) ?
0xa : 0x5;
if (!val2)
val1 |= (1 << 4);
}
}
rsnd_mod_bset(mod, SSI_MODE1, mask1, val1);
rsnd_mod_bset(mod, SSI_MODE2, mask2, val2);
return 0;
}
static int rsnd_ssiu_init_gen2(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
int ret;
ret = rsnd_ssiu_init(mod, io, priv);
if (ret < 0)
return ret;
if (rsnd_runtime_is_ssi_tdm(io)) {
rsnd_mod_write(mod, SSI_MODE, 0x1);
}
if (rsnd_ssi_use_busif(io)) {
rsnd_mod_write(mod, SSI_BUSIF_ADINR,
rsnd_get_adinr_bit(mod, io) |
(rsnd_io_is_play(io) ?
rsnd_runtime_channel_after_ctu(io) :
rsnd_runtime_channel_original(io)));
rsnd_mod_write(mod, SSI_BUSIF_MODE, 1);
rsnd_mod_write(mod, SSI_BUSIF_DALIGN,
rsnd_get_dalign(mod, io));
}
return 0;
}
static int rsnd_ssiu_start_gen2(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
if (!rsnd_ssi_use_busif(io))
return 0;
rsnd_mod_write(mod, SSI_CTRL, 0x1);
if (rsnd_ssi_multi_slaves_runtime(io))
rsnd_mod_write(mod, SSI_CONTROL, 0x1);
return 0;
}
static int rsnd_ssiu_stop_gen2(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
if (!rsnd_ssi_use_busif(io))
return 0;
rsnd_mod_write(mod, SSI_CTRL, 0);
if (rsnd_ssi_multi_slaves_runtime(io))
rsnd_mod_write(mod, SSI_CONTROL, 0);
return 0;
}
static struct rsnd_mod *rsnd_ssiu_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_ssiu_nr(priv)))
id = 0;
return rsnd_mod_get((struct rsnd_ssiu *)(priv->ssiu) + id);
}
int rsnd_ssiu_attach(struct rsnd_dai_stream *io,
struct rsnd_mod *ssi_mod)
{
struct rsnd_priv *priv = rsnd_io_to_priv(io);
struct rsnd_mod *mod = rsnd_ssiu_mod_get(priv, rsnd_mod_id(ssi_mod));
rsnd_mod_confirm_ssi(ssi_mod);
return rsnd_dai_connect(mod, io, mod->type);
}
int rsnd_ssiu_probe(struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_ssiu *ssiu;
static struct rsnd_mod_ops *ops;
int i, nr, ret;
nr = priv->ssi_nr;
ssiu = devm_kzalloc(dev, sizeof(*ssiu) * nr, GFP_KERNEL);
if (!ssiu)
return -ENOMEM;
priv->ssiu = ssiu;
priv->ssiu_nr = nr;
if (rsnd_is_gen1(priv))
ops = &rsnd_ssiu_ops_gen1;
else
ops = &rsnd_ssiu_ops_gen2;
for_each_rsnd_ssiu(ssiu, priv, i) {
ret = rsnd_mod_init(priv, rsnd_mod_get(ssiu),
ops, NULL, rsnd_mod_get_status,
RSND_MOD_SSIU, i);
if (ret)
return ret;
}
return 0;
}
void rsnd_ssiu_remove(struct rsnd_priv *priv)
{
struct rsnd_ssiu *ssiu;
int i;
for_each_rsnd_ssiu(ssiu, priv, i) {
rsnd_mod_quit(rsnd_mod_get(ssiu));
}
}
