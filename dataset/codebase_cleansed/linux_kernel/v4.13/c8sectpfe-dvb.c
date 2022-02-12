static inline const char *dvb_card_str(unsigned int c)
{
switch (c) {
case STV0367_TDA18212_NIMA_1: return "STV0367_TDA18212_NIMA_1";
case STV0367_TDA18212_NIMA_2: return "STV0367_TDA18212_NIMA_2";
case STV0367_TDA18212_NIMB_1: return "STV0367_TDA18212_NIMB_1";
case STV0367_TDA18212_NIMB_2: return "STV0367_TDA18212_NIMB_2";
case STV0903_6110_LNB24_NIMA: return "STV0903_6110_LNB24_NIMA";
case STV0903_6110_LNB24_NIMB: return "STV0903_6110_LNB24_NIMB";
default: return "unknown dvb frontend card";
}
}
int c8sectpfe_frontend_attach(struct dvb_frontend **fe,
struct c8sectpfe *c8sectpfe,
struct channel_info *tsin, int chan_num)
{
struct tda18212_config *tda18212;
const struct stv6110x_devctl *fe2;
struct i2c_client *client;
struct i2c_board_info tda18212_info = {
.type = "tda18212",
.addr = 0x60,
};
if (!tsin)
return -EINVAL;
switch (tsin->dvb_card) {
case STV0367_TDA18212_NIMA_1:
case STV0367_TDA18212_NIMA_2:
case STV0367_TDA18212_NIMB_1:
case STV0367_TDA18212_NIMB_2:
if (tsin->dvb_card == STV0367_TDA18212_NIMA_1)
*fe = dvb_attach(stv0367ter_attach,
&stv0367_tda18212_config[0],
tsin->i2c_adapter);
else if (tsin->dvb_card == STV0367_TDA18212_NIMB_1)
*fe = dvb_attach(stv0367ter_attach,
&stv0367_tda18212_config[1],
tsin->i2c_adapter);
else
*fe = dvb_attach(stv0367ter_attach,
&stv0367_tda18212_config[2],
tsin->i2c_adapter);
if (!*fe) {
dev_err(c8sectpfe->device,
"%s: stv0367ter_attach failed for NIM card %s\n"
, __func__, dvb_card_str(tsin->dvb_card));
return -ENODEV;
};
(*fe)->ops.init(*fe);
tda18212 = devm_kzalloc(c8sectpfe->device,
sizeof(struct tda18212_config),
GFP_KERNEL);
if (!tda18212) {
dev_err(c8sectpfe->device,
"%s: devm_kzalloc failed\n", __func__);
return -ENOMEM;
}
memcpy(tda18212, &tda18212_conf,
sizeof(struct tda18212_config));
tda18212->fe = (*fe);
tda18212_info.platform_data = tda18212;
request_module("tda18212");
client = i2c_new_device(tsin->i2c_adapter, &tda18212_info);
if (!client || !client->dev.driver) {
dvb_frontend_detach(*fe);
return -ENODEV;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dvb_frontend_detach(*fe);
return -ENODEV;
}
tsin->i2c_client = client;
break;
case STV0903_6110_LNB24_NIMA:
*fe = dvb_attach(stv090x_attach, &stv090x_config,
tsin->i2c_adapter, STV090x_DEMODULATOR_0);
if (!*fe) {
dev_err(c8sectpfe->device, "%s: stv090x_attach failed\n"
"\tfor NIM card %s\n",
__func__, dvb_card_str(tsin->dvb_card));
return -ENODEV;
}
fe2 = dvb_attach(stv6110x_attach, *fe,
&stv6110x_config, tsin->i2c_adapter);
if (!fe2) {
dev_err(c8sectpfe->device,
"%s: stv6110x_attach failed for NIM card %s\n"
, __func__, dvb_card_str(tsin->dvb_card));
return -ENODEV;
};
stv090x_config.tuner_init = fe2->tuner_init;
stv090x_config.tuner_set_mode = fe2->tuner_set_mode;
stv090x_config.tuner_set_frequency = fe2->tuner_set_frequency;
stv090x_config.tuner_get_frequency = fe2->tuner_get_frequency;
stv090x_config.tuner_set_bandwidth = fe2->tuner_set_bandwidth;
stv090x_config.tuner_get_bandwidth = fe2->tuner_get_bandwidth;
stv090x_config.tuner_set_bbgain = fe2->tuner_set_bbgain;
stv090x_config.tuner_get_bbgain = fe2->tuner_get_bbgain;
stv090x_config.tuner_set_refclk = fe2->tuner_set_refclk;
stv090x_config.tuner_get_status = fe2->tuner_get_status;
dvb_attach(lnbh24_attach, *fe, tsin->i2c_adapter, 0, 0, 0x9);
break;
default:
dev_err(c8sectpfe->device,
"%s: DVB frontend card %s not yet supported\n",
__func__, dvb_card_str(tsin->dvb_card));
return -ENODEV;
}
(*fe)->id = chan_num;
dev_info(c8sectpfe->device,
"DVB frontend card %s successfully attached",
dvb_card_str(tsin->dvb_card));
return 0;
}
