static int stw481x_get_pctl_reg(struct stw481x *stw481x, u8 reg)
{
u8 msb = (reg >> 3) & 0x03;
u8 lsb = (reg << 5) & 0xe0;
unsigned int val;
u8 vrfy;
int ret;
ret = regmap_write(stw481x->map, STW_PCTL_REG_HI, msb);
if (ret)
return ret;
ret = regmap_write(stw481x->map, STW_PCTL_REG_LO, lsb);
if (ret)
return ret;
ret = regmap_read(stw481x->map, STW_PCTL_REG_HI, &val);
if (ret)
return ret;
vrfy = (val & 0x03) << 3;
ret = regmap_read(stw481x->map, STW_PCTL_REG_LO, &val);
if (ret)
return ret;
vrfy |= ((val >> 5) & 0x07);
if (vrfy != reg)
return -EIO;
return (val >> 1) & 0x0f;
}
static int stw481x_startup(struct stw481x *stw481x)
{
u8 vcore_val[] = { 100, 105, 110, 115, 120, 122, 124, 126, 128,
130, 132, 134, 136, 138, 140, 145 };
u8 vpll_val[] = { 105, 120, 130, 180 };
u8 vaux_val[] = { 15, 18, 25, 28 };
u8 vcore;
u8 vcore_slp;
u8 vpll;
u8 vaux;
bool vaux_en;
bool it_warn;
int ret;
unsigned int val;
ret = regmap_read(stw481x->map, STW_CONF1, &val);
if (ret)
return ret;
vaux_en = !!(val & STW_CONF1_PDN_VAUX);
it_warn = !!(val & STW_CONF1_IT_WARN);
dev_info(&stw481x->client->dev, "voltages %s\n",
(val & STW_CONF1_V_MONITORING) ? "OK" : "LOW");
dev_info(&stw481x->client->dev, "MMC level shifter %s\n",
(val & STW_CONF1_MMC_LS_STATUS) ? "high impedance" : "ON");
dev_info(&stw481x->client->dev, "VMMC: %s\n",
(val & STW_CONF1_PDN_VMMC) ? "ON" : "disabled");
dev_info(&stw481x->client->dev, "STw481x power control registers:\n");
ret = stw481x_get_pctl_reg(stw481x, STW_PC_VCORE_SEL);
if (ret < 0)
return ret;
vcore = ret & 0x0f;
ret = stw481x_get_pctl_reg(stw481x, STW_PC_VAUX_SEL);
if (ret < 0)
return ret;
vaux = (ret >> 2) & 3;
vpll = (ret >> 4) & 1;
ret = stw481x_get_pctl_reg(stw481x, STW_PC_VPLL_SEL);
if (ret < 0)
return ret;
vpll |= (ret >> 1) & 2;
dev_info(&stw481x->client->dev, "VCORE: %u.%uV %s\n",
vcore_val[vcore] / 100, vcore_val[vcore] % 100,
(ret & 4) ? "ON" : "OFF");
dev_info(&stw481x->client->dev, "VPLL: %u.%uV %s\n",
vpll_val[vpll] / 100, vpll_val[vpll] % 100,
(ret & 0x10) ? "ON" : "OFF");
dev_info(&stw481x->client->dev, "VAUX: %u.%uV %s\n",
vaux_val[vaux] / 10, vaux_val[vaux] % 10,
vaux_en ? "ON" : "OFF");
ret = regmap_read(stw481x->map, STW_CONF2, &val);
if (ret)
return ret;
dev_info(&stw481x->client->dev, "TWARN: %s threshold, %s\n",
it_warn ? "below" : "above",
(val & STW_CONF2_MASK_TWARN) ?
"enabled" : "mask through VDDOK");
dev_info(&stw481x->client->dev, "VMMC: %s\n",
(val & STW_CONF2_VMMC_EXT) ? "internal" : "external");
dev_info(&stw481x->client->dev, "IT WAKE UP: %s\n",
(val & STW_CONF2_MASK_IT_WAKE_UP) ? "enabled" : "masked");
dev_info(&stw481x->client->dev, "GPO1: %s\n",
(val & STW_CONF2_GPO1) ? "low" : "high impedance");
dev_info(&stw481x->client->dev, "GPO2: %s\n",
(val & STW_CONF2_GPO2) ? "low" : "high impedance");
ret = regmap_read(stw481x->map, STW_VCORE_SLEEP, &val);
if (ret)
return ret;
vcore_slp = val & 0x0f;
dev_info(&stw481x->client->dev, "VCORE SLEEP: %u.%uV\n",
vcore_val[vcore_slp] / 100, vcore_val[vcore_slp] % 100);
return 0;
}
static int stw481x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct stw481x *stw481x;
int ret;
int i;
stw481x = devm_kzalloc(&client->dev, sizeof(*stw481x), GFP_KERNEL);
if (!stw481x)
return -ENOMEM;
i2c_set_clientdata(client, stw481x);
stw481x->client = client;
stw481x->map = devm_regmap_init_i2c(client, &stw481x_regmap_config);
ret = stw481x_startup(stw481x);
if (ret) {
dev_err(&client->dev, "chip initialization failed\n");
return ret;
}
for (i = 0; i < ARRAY_SIZE(stw481x_cells); i++) {
stw481x_cells[i].platform_data = stw481x;
stw481x_cells[i].pdata_size = sizeof(*stw481x);
}
ret = mfd_add_devices(&client->dev, 0, stw481x_cells,
ARRAY_SIZE(stw481x_cells), NULL, 0, NULL);
if (ret)
return ret;
dev_info(&client->dev, "initialized STw481x device\n");
return ret;
}
static int stw481x_remove(struct i2c_client *client)
{
mfd_remove_devices(&client->dev);
return 0;
}
