static inline struct tegra_hsp *
to_tegra_hsp(struct mbox_controller *mbox)
{
return container_of(mbox, struct tegra_hsp, mbox);
}
static inline u32 tegra_hsp_readl(struct tegra_hsp *hsp, unsigned int offset)
{
return readl(hsp->regs + offset);
}
static inline void tegra_hsp_writel(struct tegra_hsp *hsp, u32 value,
unsigned int offset)
{
writel(value, hsp->regs + offset);
}
static inline u32 tegra_hsp_channel_readl(struct tegra_hsp_channel *channel,
unsigned int offset)
{
return readl(channel->regs + offset);
}
static inline void tegra_hsp_channel_writel(struct tegra_hsp_channel *channel,
u32 value, unsigned int offset)
{
writel(value, channel->regs + offset);
}
static bool tegra_hsp_doorbell_can_ring(struct tegra_hsp_doorbell *db)
{
u32 value;
value = tegra_hsp_channel_readl(&db->channel, HSP_DB_ENABLE);
return (value & BIT(TEGRA_HSP_DB_MASTER_CCPLEX)) != 0;
}
static struct tegra_hsp_doorbell *
__tegra_hsp_doorbell_get(struct tegra_hsp *hsp, unsigned int master)
{
struct tegra_hsp_doorbell *entry;
list_for_each_entry(entry, &hsp->doorbells, list)
if (entry->master == master)
return entry;
return NULL;
}
static struct tegra_hsp_doorbell *
tegra_hsp_doorbell_get(struct tegra_hsp *hsp, unsigned int master)
{
struct tegra_hsp_doorbell *db;
unsigned long flags;
spin_lock_irqsave(&hsp->lock, flags);
db = __tegra_hsp_doorbell_get(hsp, master);
spin_unlock_irqrestore(&hsp->lock, flags);
return db;
}
static irqreturn_t tegra_hsp_doorbell_irq(int irq, void *data)
{
struct tegra_hsp *hsp = data;
struct tegra_hsp_doorbell *db;
unsigned long master, value;
db = tegra_hsp_doorbell_get(hsp, TEGRA_HSP_DB_MASTER_CCPLEX);
if (!db)
return IRQ_NONE;
value = tegra_hsp_channel_readl(&db->channel, HSP_DB_PENDING);
tegra_hsp_channel_writel(&db->channel, value, HSP_DB_PENDING);
spin_lock(&hsp->lock);
for_each_set_bit(master, &value, hsp->mbox.num_chans) {
struct tegra_hsp_doorbell *db;
db = __tegra_hsp_doorbell_get(hsp, master);
if (db && db->channel.chan)
mbox_chan_received_data(db->channel.chan, NULL);
}
spin_unlock(&hsp->lock);
return IRQ_HANDLED;
}
static struct tegra_hsp_channel *
tegra_hsp_doorbell_create(struct tegra_hsp *hsp, const char *name,
unsigned int master, unsigned int index)
{
struct tegra_hsp_doorbell *db;
unsigned int offset;
unsigned long flags;
db = kzalloc(sizeof(*db), GFP_KERNEL);
if (!db)
return ERR_PTR(-ENOMEM);
offset = (1 + (hsp->num_sm / 2) + hsp->num_ss + hsp->num_as) << 16;
offset += index * 0x100;
db->channel.regs = hsp->regs + offset;
db->channel.hsp = hsp;
db->name = kstrdup_const(name, GFP_KERNEL);
db->master = master;
db->index = index;
spin_lock_irqsave(&hsp->lock, flags);
list_add_tail(&db->list, &hsp->doorbells);
spin_unlock_irqrestore(&hsp->lock, flags);
return &db->channel;
}
static void __tegra_hsp_doorbell_destroy(struct tegra_hsp_doorbell *db)
{
list_del(&db->list);
kfree_const(db->name);
kfree(db);
}
static int tegra_hsp_doorbell_send_data(struct mbox_chan *chan, void *data)
{
struct tegra_hsp_doorbell *db = chan->con_priv;
tegra_hsp_channel_writel(&db->channel, 1, HSP_DB_TRIGGER);
return 0;
}
static int tegra_hsp_doorbell_startup(struct mbox_chan *chan)
{
struct tegra_hsp_doorbell *db = chan->con_priv;
struct tegra_hsp *hsp = db->channel.hsp;
struct tegra_hsp_doorbell *ccplex;
unsigned long flags;
u32 value;
if (db->master >= hsp->mbox.num_chans) {
dev_err(hsp->mbox.dev,
"invalid master ID %u for HSP channel\n",
db->master);
return -EINVAL;
}
ccplex = tegra_hsp_doorbell_get(hsp, TEGRA_HSP_DB_MASTER_CCPLEX);
if (!ccplex)
return -ENODEV;
if (!tegra_hsp_doorbell_can_ring(db))
return -ENODEV;
spin_lock_irqsave(&hsp->lock, flags);
value = tegra_hsp_channel_readl(&ccplex->channel, HSP_DB_ENABLE);
value |= BIT(db->master);
tegra_hsp_channel_writel(&ccplex->channel, value, HSP_DB_ENABLE);
spin_unlock_irqrestore(&hsp->lock, flags);
return 0;
}
static void tegra_hsp_doorbell_shutdown(struct mbox_chan *chan)
{
struct tegra_hsp_doorbell *db = chan->con_priv;
struct tegra_hsp *hsp = db->channel.hsp;
struct tegra_hsp_doorbell *ccplex;
unsigned long flags;
u32 value;
ccplex = tegra_hsp_doorbell_get(hsp, TEGRA_HSP_DB_MASTER_CCPLEX);
if (!ccplex)
return;
spin_lock_irqsave(&hsp->lock, flags);
value = tegra_hsp_channel_readl(&ccplex->channel, HSP_DB_ENABLE);
value &= ~BIT(db->master);
tegra_hsp_channel_writel(&ccplex->channel, value, HSP_DB_ENABLE);
spin_unlock_irqrestore(&hsp->lock, flags);
}
static struct mbox_chan *of_tegra_hsp_xlate(struct mbox_controller *mbox,
const struct of_phandle_args *args)
{
struct tegra_hsp_channel *channel = ERR_PTR(-ENODEV);
struct tegra_hsp *hsp = to_tegra_hsp(mbox);
unsigned int type = args->args[0];
unsigned int master = args->args[1];
struct tegra_hsp_doorbell *db;
struct mbox_chan *chan;
unsigned long flags;
unsigned int i;
switch (type) {
case TEGRA_HSP_MBOX_TYPE_DB:
db = tegra_hsp_doorbell_get(hsp, master);
if (db)
channel = &db->channel;
break;
default:
break;
}
if (IS_ERR(channel))
return ERR_CAST(channel);
spin_lock_irqsave(&hsp->lock, flags);
for (i = 0; i < hsp->mbox.num_chans; i++) {
chan = &hsp->mbox.chans[i];
if (!chan->con_priv) {
chan->con_priv = channel;
channel->chan = chan;
break;
}
chan = NULL;
}
spin_unlock_irqrestore(&hsp->lock, flags);
return chan ?: ERR_PTR(-EBUSY);
}
static void tegra_hsp_remove_doorbells(struct tegra_hsp *hsp)
{
struct tegra_hsp_doorbell *db, *tmp;
unsigned long flags;
spin_lock_irqsave(&hsp->lock, flags);
list_for_each_entry_safe(db, tmp, &hsp->doorbells, list)
__tegra_hsp_doorbell_destroy(db);
spin_unlock_irqrestore(&hsp->lock, flags);
}
static int tegra_hsp_add_doorbells(struct tegra_hsp *hsp)
{
const struct tegra_hsp_db_map *map = hsp->soc->map;
struct tegra_hsp_channel *channel;
while (map->name) {
channel = tegra_hsp_doorbell_create(hsp, map->name,
map->master, map->index);
if (IS_ERR(channel)) {
tegra_hsp_remove_doorbells(hsp);
return PTR_ERR(channel);
}
map++;
}
return 0;
}
static int tegra_hsp_probe(struct platform_device *pdev)
{
struct tegra_hsp *hsp;
struct resource *res;
u32 value;
int err;
hsp = devm_kzalloc(&pdev->dev, sizeof(*hsp), GFP_KERNEL);
if (!hsp)
return -ENOMEM;
hsp->soc = of_device_get_match_data(&pdev->dev);
INIT_LIST_HEAD(&hsp->doorbells);
spin_lock_init(&hsp->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hsp->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hsp->regs))
return PTR_ERR(hsp->regs);
value = tegra_hsp_readl(hsp, HSP_INT_DIMENSIONING);
hsp->num_sm = (value >> HSP_nSM_SHIFT) & HSP_nINT_MASK;
hsp->num_ss = (value >> HSP_nSS_SHIFT) & HSP_nINT_MASK;
hsp->num_as = (value >> HSP_nAS_SHIFT) & HSP_nINT_MASK;
hsp->num_db = (value >> HSP_nDB_SHIFT) & HSP_nINT_MASK;
hsp->num_si = (value >> HSP_nSI_SHIFT) & HSP_nINT_MASK;
err = platform_get_irq_byname(pdev, "doorbell");
if (err < 0) {
dev_err(&pdev->dev, "failed to get doorbell IRQ: %d\n", err);
return err;
}
hsp->irq = err;
hsp->mbox.of_xlate = of_tegra_hsp_xlate;
hsp->mbox.num_chans = 32;
hsp->mbox.dev = &pdev->dev;
hsp->mbox.txdone_irq = false;
hsp->mbox.txdone_poll = false;
hsp->mbox.ops = &tegra_hsp_doorbell_ops;
hsp->mbox.chans = devm_kcalloc(&pdev->dev, hsp->mbox.num_chans,
sizeof(*hsp->mbox.chans),
GFP_KERNEL);
if (!hsp->mbox.chans)
return -ENOMEM;
err = tegra_hsp_add_doorbells(hsp);
if (err < 0) {
dev_err(&pdev->dev, "failed to add doorbells: %d\n", err);
return err;
}
platform_set_drvdata(pdev, hsp);
err = mbox_controller_register(&hsp->mbox);
if (err) {
dev_err(&pdev->dev, "failed to register mailbox: %d\n", err);
tegra_hsp_remove_doorbells(hsp);
return err;
}
err = devm_request_irq(&pdev->dev, hsp->irq, tegra_hsp_doorbell_irq,
IRQF_NO_SUSPEND, dev_name(&pdev->dev), hsp);
if (err < 0) {
dev_err(&pdev->dev, "failed to request IRQ#%u: %d\n",
hsp->irq, err);
return err;
}
return 0;
}
static int tegra_hsp_remove(struct platform_device *pdev)
{
struct tegra_hsp *hsp = platform_get_drvdata(pdev);
mbox_controller_unregister(&hsp->mbox);
tegra_hsp_remove_doorbells(hsp);
return 0;
}
static int __init tegra_hsp_init(void)
{
return platform_driver_register(&tegra_hsp_driver);
}
