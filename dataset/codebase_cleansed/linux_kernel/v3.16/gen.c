static int rsnd_regmap_write32(void *context, const void *_data, size_t count)
{
struct rsnd_priv *priv = context;
struct device *dev = rsnd_priv_to_dev(priv);
u32 *data = (u32 *)_data;
u32 val = data[1];
void __iomem *reg = (void *)data[0];
iowrite32(val, reg);
dev_dbg(dev, "w %p : %08x\n", reg, val);
return 0;
}
static int rsnd_regmap_read32(void *context,
const void *_data, size_t reg_size,
void *_val, size_t val_size)
{
struct rsnd_priv *priv = context;
struct device *dev = rsnd_priv_to_dev(priv);
u32 *data = (u32 *)_data;
u32 *val = (u32 *)_val;
void __iomem *reg = (void *)data[0];
*val = ioread32(reg);
dev_dbg(dev, "r %p : %08x\n", reg, *val);
return 0;
}
static int rsnd_is_accessible_reg(struct rsnd_priv *priv,
struct rsnd_gen *gen, enum rsnd_reg reg)
{
if (!gen->regs[reg]) {
struct device *dev = rsnd_priv_to_dev(priv);
dev_err(dev, "unsupported register access %x\n", reg);
return 0;
}
return 1;
}
u32 rsnd_read(struct rsnd_priv *priv,
struct rsnd_mod *mod, enum rsnd_reg reg)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
u32 val;
if (!rsnd_is_accessible_reg(priv, gen, reg))
return 0;
regmap_fields_read(gen->regs[reg], rsnd_mod_id(mod), &val);
return val;
}
void rsnd_write(struct rsnd_priv *priv,
struct rsnd_mod *mod,
enum rsnd_reg reg, u32 data)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
if (!rsnd_is_accessible_reg(priv, gen, reg))
return;
regmap_fields_write(gen->regs[reg], rsnd_mod_id(mod), data);
}
void rsnd_bset(struct rsnd_priv *priv, struct rsnd_mod *mod,
enum rsnd_reg reg, u32 mask, u32 data)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
if (!rsnd_is_accessible_reg(priv, gen, reg))
return;
regmap_fields_update_bits(gen->regs[reg], rsnd_mod_id(mod),
mask, data);
}
static int rsnd_gen_regmap_init(struct rsnd_priv *priv,
struct rsnd_gen *gen,
struct reg_field *regf)
{
int i;
struct device *dev = rsnd_priv_to_dev(priv);
struct regmap_config regc;
memset(&regc, 0, sizeof(regc));
regc.reg_bits = 32;
regc.val_bits = 32;
gen->regmap = devm_regmap_init(dev, &rsnd_regmap_bus, priv, &regc);
if (IS_ERR(gen->regmap)) {
dev_err(dev, "regmap error %ld\n", PTR_ERR(gen->regmap));
return PTR_ERR(gen->regmap);
}
for (i = 0; i < RSND_REG_MAX; i++) {
gen->regs[i] = NULL;
if (!regf[i].reg)
continue;
gen->regs[i] = devm_regmap_field_alloc(dev, gen->regmap, regf[i]);
if (IS_ERR(gen->regs[i]))
return PTR_ERR(gen->regs[i]);
}
return 0;
}
void rsnd_gen_dma_addr(struct rsnd_priv *priv,
struct rsnd_dma *dma,
struct dma_slave_config *cfg,
int is_play, int slave_id)
{
struct platform_device *pdev = rsnd_priv_to_pdev(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_mod *mod = rsnd_dma_to_mod(dma);
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
dma_addr_t ssi_reg = platform_get_resource(pdev,
IORESOURCE_MEM, RSND_GEN2_SSI)->start;
dma_addr_t src_reg = platform_get_resource(pdev,
IORESOURCE_MEM, RSND_GEN2_SCU)->start;
int is_ssi = !!(rsnd_io_to_mod_ssi(io) == mod);
int use_src = !!rsnd_io_to_mod_src(io);
int use_dvc = !!rsnd_io_to_mod_dvc(io);
int id = rsnd_mod_id(mod);
struct dma_addr {
dma_addr_t src_addr;
dma_addr_t dst_addr;
} dma_addrs[2][2][3] = {
{
{{ 0, 0 },
{ RDMA_SRC_O_N(src, id), 0 },
{ RDMA_CMD_O_N(src, id), 0 }},
{{ 0, 0, },
{ 0, RDMA_SRC_I_N(src, id) },
{ 0, RDMA_SRC_I_N(src, id) }}
}, {
{{ RDMA_SSI_O_N(ssi, id), 0 },
{ RDMA_SSI_O_P(ssi, id), RDMA_SRC_I_P(src, id) },
{ RDMA_SSI_O_P(ssi, id), RDMA_SRC_I_P(src, id) }},
{{ 0, RDMA_SSI_I_N(ssi, id) },
{ RDMA_SRC_O_P(src, id), RDMA_SSI_I_P(ssi, id) },
{ RDMA_CMD_O_P(src, id), RDMA_SSI_I_P(ssi, id) }}
}
};
cfg->slave_id = slave_id;
cfg->src_addr = 0;
cfg->dst_addr = 0;
cfg->direction = is_play ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM;
if (rsnd_is_gen1(priv))
return;
if (use_dvc & !use_src) {
dev_err(dev, "DVC is selected without SRC\n");
return;
}
cfg->src_addr = dma_addrs[is_ssi][is_play][use_src + use_dvc].src_addr;
cfg->dst_addr = dma_addrs[is_ssi][is_play][use_src + use_dvc].dst_addr;
dev_dbg(dev, "dma%d addr - src : %x / dst : %x\n",
id, cfg->src_addr, cfg->dst_addr);
}
static int rsnd_gen2_regmap_init(struct rsnd_priv *priv, struct rsnd_gen *gen)
{
struct reg_field regf[RSND_REG_MAX] = {
RSND_GEN2_S_REG(gen, SSIU, SSI_MODE0, 0x800),
RSND_GEN2_S_REG(gen, SSIU, SSI_MODE1, 0x804),
RSND_GEN2_M_REG(gen, SSIU, SSI_BUSIF_MODE, 0x0, 0x80),
RSND_GEN2_M_REG(gen, SSIU, SSI_BUSIF_ADINR,0x4, 0x80),
RSND_GEN2_M_REG(gen, SSIU, SSI_CTRL, 0x10, 0x80),
RSND_GEN2_M_REG(gen, SSIU, INT_ENABLE, 0x18, 0x80),
RSND_GEN2_M_REG(gen, SCU, SRC_BUSIF_MODE, 0x0, 0x20),
RSND_GEN2_M_REG(gen, SCU, SRC_ROUTE_MODE0,0xc, 0x20),
RSND_GEN2_M_REG(gen, SCU, SRC_CTRL, 0x10, 0x20),
RSND_GEN2_M_REG(gen, SCU, CMD_ROUTE_SLCT, 0x18c, 0x20),
RSND_GEN2_M_REG(gen, SCU, CMD_CTRL, 0x190, 0x20),
RSND_GEN2_M_REG(gen, SCU, SRC_SWRSR, 0x200, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_SRCIR, 0x204, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_ADINR, 0x214, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_IFSCR, 0x21c, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_IFSVR, 0x220, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_SRCCR, 0x224, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_BSDSR, 0x22c, 0x40),
RSND_GEN2_M_REG(gen, SCU, SRC_BSISR, 0x238, 0x40),
RSND_GEN2_M_REG(gen, SCU, DVC_SWRSR, 0xe00, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_DVUIR, 0xe04, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_ADINR, 0xe08, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_DVUCR, 0xe10, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_ZCMCR, 0xe14, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_VOL0R, 0xe28, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_VOL1R, 0xe2c, 0x100),
RSND_GEN2_M_REG(gen, SCU, DVC_DVUER, 0xe48, 0x100),
RSND_GEN2_S_REG(gen, ADG, BRRA, 0x00),
RSND_GEN2_S_REG(gen, ADG, BRRB, 0x04),
RSND_GEN2_S_REG(gen, ADG, SSICKR, 0x08),
RSND_GEN2_S_REG(gen, ADG, AUDIO_CLK_SEL0, 0x0c),
RSND_GEN2_S_REG(gen, ADG, AUDIO_CLK_SEL1, 0x10),
RSND_GEN2_S_REG(gen, ADG, AUDIO_CLK_SEL2, 0x14),
RSND_GEN2_S_REG(gen, ADG, DIV_EN, 0x30),
RSND_GEN2_S_REG(gen, ADG, SRCIN_TIMSEL0, 0x34),
RSND_GEN2_S_REG(gen, ADG, SRCIN_TIMSEL1, 0x38),
RSND_GEN2_S_REG(gen, ADG, SRCIN_TIMSEL2, 0x3c),
RSND_GEN2_S_REG(gen, ADG, SRCIN_TIMSEL3, 0x40),
RSND_GEN2_S_REG(gen, ADG, SRCIN_TIMSEL4, 0x44),
RSND_GEN2_S_REG(gen, ADG, SRCOUT_TIMSEL0, 0x48),
RSND_GEN2_S_REG(gen, ADG, SRCOUT_TIMSEL1, 0x4c),
RSND_GEN2_S_REG(gen, ADG, SRCOUT_TIMSEL2, 0x50),
RSND_GEN2_S_REG(gen, ADG, SRCOUT_TIMSEL3, 0x54),
RSND_GEN2_S_REG(gen, ADG, SRCOUT_TIMSEL4, 0x58),
RSND_GEN2_S_REG(gen, ADG, CMDOUT_TIMSEL, 0x5c),
RSND_GEN2_M_REG(gen, SSI, SSICR, 0x00, 0x40),
RSND_GEN2_M_REG(gen, SSI, SSISR, 0x04, 0x40),
RSND_GEN2_M_REG(gen, SSI, SSITDR, 0x08, 0x40),
RSND_GEN2_M_REG(gen, SSI, SSIRDR, 0x0c, 0x40),
RSND_GEN2_M_REG(gen, SSI, SSIWSR, 0x20, 0x40),
};
return rsnd_gen_regmap_init(priv, gen, regf);
}
static int rsnd_gen2_probe(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
struct resource *scu_res;
struct resource *adg_res;
struct resource *ssiu_res;
struct resource *ssi_res;
int ret;
scu_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN2_SCU);
adg_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN2_ADG);
ssiu_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN2_SSIU);
ssi_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN2_SSI);
gen->base[RSND_GEN2_SCU] = devm_ioremap_resource(dev, scu_res);
gen->base[RSND_GEN2_ADG] = devm_ioremap_resource(dev, adg_res);
gen->base[RSND_GEN2_SSIU] = devm_ioremap_resource(dev, ssiu_res);
gen->base[RSND_GEN2_SSI] = devm_ioremap_resource(dev, ssi_res);
if (IS_ERR(gen->base[RSND_GEN2_SCU]) ||
IS_ERR(gen->base[RSND_GEN2_ADG]) ||
IS_ERR(gen->base[RSND_GEN2_SSIU]) ||
IS_ERR(gen->base[RSND_GEN2_SSI]))
return -ENODEV;
ret = rsnd_gen2_regmap_init(priv, gen);
if (ret < 0)
return ret;
dev_dbg(dev, "Gen2 device probed\n");
dev_dbg(dev, "SCU : %pap => %p\n", &scu_res->start,
gen->base[RSND_GEN2_SCU]);
dev_dbg(dev, "ADG : %pap => %p\n", &adg_res->start,
gen->base[RSND_GEN2_ADG]);
dev_dbg(dev, "SSIU : %pap => %p\n", &ssiu_res->start,
gen->base[RSND_GEN2_SSIU]);
dev_dbg(dev, "SSI : %pap => %p\n", &ssi_res->start,
gen->base[RSND_GEN2_SSI]);
return 0;
}
static int rsnd_gen1_regmap_init(struct rsnd_priv *priv, struct rsnd_gen *gen)
{
struct reg_field regf[RSND_REG_MAX] = {
RSND_GEN1_S_REG(gen, SRU, SRC_ROUTE_SEL, 0x00),
RSND_GEN1_S_REG(gen, SRU, SRC_TMG_SEL0, 0x08),
RSND_GEN1_S_REG(gen, SRU, SRC_TMG_SEL1, 0x0c),
RSND_GEN1_S_REG(gen, SRU, SRC_TMG_SEL2, 0x10),
RSND_GEN1_S_REG(gen, SRU, SRC_ROUTE_CTRL, 0xc0),
RSND_GEN1_S_REG(gen, SRU, SSI_MODE0, 0xD0),
RSND_GEN1_S_REG(gen, SRU, SSI_MODE1, 0xD4),
RSND_GEN1_M_REG(gen, SRU, SRC_BUSIF_MODE, 0x20, 0x4),
RSND_GEN1_M_REG(gen, SRU, SRC_ROUTE_MODE0,0x50, 0x8),
RSND_GEN1_M_REG(gen, SRU, SRC_SWRSR, 0x200, 0x40),
RSND_GEN1_M_REG(gen, SRU, SRC_SRCIR, 0x204, 0x40),
RSND_GEN1_M_REG(gen, SRU, SRC_ADINR, 0x214, 0x40),
RSND_GEN1_M_REG(gen, SRU, SRC_IFSCR, 0x21c, 0x40),
RSND_GEN1_M_REG(gen, SRU, SRC_IFSVR, 0x220, 0x40),
RSND_GEN1_M_REG(gen, SRU, SRC_SRCCR, 0x224, 0x40),
RSND_GEN1_M_REG(gen, SRU, SRC_MNFSR, 0x228, 0x40),
RSND_GEN1_S_REG(gen, ADG, BRRA, 0x00),
RSND_GEN1_S_REG(gen, ADG, BRRB, 0x04),
RSND_GEN1_S_REG(gen, ADG, SSICKR, 0x08),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL0, 0x0c),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL1, 0x10),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL3, 0x18),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL4, 0x1c),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL5, 0x20),
RSND_GEN1_M_REG(gen, SSI, SSICR, 0x00, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSISR, 0x04, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSITDR, 0x08, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSIRDR, 0x0c, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSIWSR, 0x20, 0x40),
};
return rsnd_gen_regmap_init(priv, gen, regf);
}
static int rsnd_gen1_probe(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
struct resource *sru_res;
struct resource *adg_res;
struct resource *ssi_res;
int ret;
sru_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN1_SRU);
adg_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN1_ADG);
ssi_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN1_SSI);
gen->base[RSND_GEN1_SRU] = devm_ioremap_resource(dev, sru_res);
gen->base[RSND_GEN1_ADG] = devm_ioremap_resource(dev, adg_res);
gen->base[RSND_GEN1_SSI] = devm_ioremap_resource(dev, ssi_res);
if (IS_ERR(gen->base[RSND_GEN1_SRU]) ||
IS_ERR(gen->base[RSND_GEN1_ADG]) ||
IS_ERR(gen->base[RSND_GEN1_SSI]))
return -ENODEV;
ret = rsnd_gen1_regmap_init(priv, gen);
if (ret < 0)
return ret;
dev_dbg(dev, "Gen1 device probed\n");
dev_dbg(dev, "SRU : %pap => %p\n", &sru_res->start,
gen->base[RSND_GEN1_SRU]);
dev_dbg(dev, "ADG : %pap => %p\n", &adg_res->start,
gen->base[RSND_GEN1_ADG]);
dev_dbg(dev, "SSI : %pap => %p\n", &ssi_res->start,
gen->base[RSND_GEN1_SSI]);
return 0;
}
static void rsnd_of_parse_gen(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct rcar_snd_info *info = priv->info;
if (!of_data)
return;
info->flags = of_data->flags;
}
int rsnd_gen_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_gen *gen;
int ret;
rsnd_of_parse_gen(pdev, of_data, priv);
gen = devm_kzalloc(dev, sizeof(*gen), GFP_KERNEL);
if (!gen) {
dev_err(dev, "GEN allocate failed\n");
return -ENOMEM;
}
priv->gen = gen;
ret = -ENODEV;
if (rsnd_is_gen1(priv))
ret = rsnd_gen1_probe(pdev, priv);
else if (rsnd_is_gen2(priv))
ret = rsnd_gen2_probe(pdev, priv);
if (ret < 0)
dev_err(dev, "unknown generation R-Car sound device\n");
return ret;
}
