int cxd2820r_set_frontend_c(struct dvb_frontend *fe)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nstruct dtv_frontend_properties *c = &fe->dtv_property_cache;\r\nint ret, i;\r\nu8 buf[2];\r\nu32 if_freq;\r\nu16 if_ctl;\r\nu64 num;\r\nstruct reg_val_mask tab[] = {\r\n{ 0x00080, 0x01, 0xff },\r\n{ 0x00081, 0x05, 0xff },\r\n{ 0x00085, 0x07, 0xff },\r\n{ 0x00088, 0x01, 0xff },\r\n{ 0x00082, 0x20, 0x60 },\r\n{ 0x1016a, 0x48, 0xff },\r\n{ 0x100a5, 0x00, 0x01 },\r\n{ 0x10020, 0x06, 0x07 },\r\n{ 0x10059, 0x50, 0xff },\r\n{ 0x10087, 0x0c, 0x3c },\r\n{ 0x1008b, 0x07, 0xff },\r\n{ 0x1001f, priv->cfg.if_agc_polarity << 7, 0x80 },\r\n{ 0x10070, priv->cfg.ts_mode, 0xff },\r\n{ 0x10071, !priv->cfg.ts_clock_inv << 4, 0x10 },\r\n};\r\ndev_dbg(&priv->i2c->dev, "%s: frequency=%d symbol_rate=%d\n", __func__,\r\nc->frequency, c->symbol_rate);\r\nif (fe->ops.tuner_ops.set_params)\r\nfe->ops.tuner_ops.set_params(fe);\r\nif (priv->delivery_system != SYS_DVBC_ANNEX_A) {\r\nfor (i = 0; i < ARRAY_SIZE(tab); i++) {\r\nret = cxd2820r_wr_reg_mask(priv, tab[i].reg,\r\ntab[i].val, tab[i].mask);\r\nif (ret)\r\ngoto error;\r\n}\r\n}\r\npriv->delivery_system = SYS_DVBC_ANNEX_A;\r\npriv->ber_running = false;\r\nif (fe->ops.tuner_ops.get_if_frequency) {\r\nret = fe->ops.tuner_ops.get_if_frequency(fe, &if_freq);\r\nif (ret)\r\ngoto error;\r\n} else\r\nif_freq = 0;\r\ndev_dbg(&priv->i2c->dev, "%s: if_freq=%d\n", __func__, if_freq);\r\nnum = if_freq / 1000;\r\nnum *= 0x4000;\r\nif_ctl = 0x4000 - DIV_ROUND_CLOSEST_ULL(num, 41000);\r\nbuf[0] = (if_ctl >> 8) & 0x3f;\r\nbuf[1] = (if_ctl >> 0) & 0xff;\r\nret = cxd2820r_wr_regs(priv, 0x10042, buf, 2);\r\nif (ret)\r\ngoto error;\r\nret = cxd2820r_wr_reg(priv, 0x000ff, 0x08);\r\nif (ret)\r\ngoto error;\r\nret = cxd2820r_wr_reg(priv, 0x000fe, 0x01);\r\nif (ret)\r\ngoto error;\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_get_frontend_c(struct dvb_frontend *fe)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nstruct dtv_frontend_properties *c = &fe->dtv_property_cache;\r\nint ret;\r\nu8 buf[2];\r\nret = cxd2820r_rd_regs(priv, 0x1001a, buf, 2);\r\nif (ret)\r\ngoto error;\r\nc->symbol_rate = 2500 * ((buf[0] & 0x0f) << 8 | buf[1]);\r\nret = cxd2820r_rd_reg(priv, 0x10019, &buf[0]);\r\nif (ret)\r\ngoto error;\r\nswitch ((buf[0] >> 0) & 0x07) {\r\ncase 0:\r\nc->modulation = QAM_16;\r\nbreak;\r\ncase 1:\r\nc->modulation = QAM_32;\r\nbreak;\r\ncase 2:\r\nc->modulation = QAM_64;\r\nbreak;\r\ncase 3:\r\nc->modulation = QAM_128;\r\nbreak;\r\ncase 4:\r\nc->modulation = QAM_256;\r\nbreak;\r\n}\r\nswitch ((buf[0] >> 7) & 0x01) {\r\ncase 0:\r\nc->inversion = INVERSION_OFF;\r\nbreak;\r\ncase 1:\r\nc->inversion = INVERSION_ON;\r\nbreak;\r\n}\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_read_ber_c(struct dvb_frontend *fe, u32 *ber)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nint ret;\r\nu8 buf[3], start_ber = 0;\r\n*ber = 0;\r\nif (priv->ber_running) {\r\nret = cxd2820r_rd_regs(priv, 0x10076, buf, sizeof(buf));\r\nif (ret)\r\ngoto error;\r\nif ((buf[2] >> 7) & 0x01 || (buf[2] >> 4) & 0x01) {\r\n*ber = (buf[2] & 0x0f) << 16 | buf[1] << 8 | buf[0];\r\nstart_ber = 1;\r\n}\r\n} else {\r\npriv->ber_running = true;\r\nstart_ber = 1;\r\n}\r\nif (start_ber) {\r\nret = cxd2820r_wr_reg(priv, 0x10079, 0x01);\r\nif (ret)\r\ngoto error;\r\n}\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_read_signal_strength_c(struct dvb_frontend *fe,\r\nu16 *strength)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nint ret;\r\nu8 buf[2];\r\nu16 tmp;\r\nret = cxd2820r_rd_regs(priv, 0x10049, buf, sizeof(buf));\r\nif (ret)\r\ngoto error;\r\ntmp = (buf[0] & 0x03) << 8 | buf[1];\r\ntmp = (~tmp & 0x03ff);\r\nif (tmp == 512)\r\ntmp = 0;\r\nelse if (tmp > 350)\r\ntmp = 350;\r\n*strength = tmp * 0xffff / (350-0);\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_read_snr_c(struct dvb_frontend *fe, u16 *snr)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nint ret;\r\nu8 tmp;\r\nunsigned int A, B;\r\nret = cxd2820r_rd_reg(priv, 0x10019, &tmp);\r\nif (ret)\r\ngoto error;\r\nif (((tmp >> 0) & 0x03) % 2) {\r\nA = 875;\r\nB = 650;\r\n} else {\r\nA = 950;\r\nB = 760;\r\n}\r\nret = cxd2820r_rd_reg(priv, 0x1004d, &tmp);\r\nif (ret)\r\ngoto error;\r\n#define CXD2820R_LOG2_E_24 24204406\r\nif (tmp)\r\n*snr = A * (intlog2(B / tmp) >> 5) / (CXD2820R_LOG2_E_24 >> 5)\r\n/ 10;\r\nelse\r\n*snr = 0;\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_read_ucblocks_c(struct dvb_frontend *fe, u32 *ucblocks)\r\n{\r\n*ucblocks = 0;\r\nreturn 0;\r\n}\r\nint cxd2820r_read_status_c(struct dvb_frontend *fe, enum fe_status *status)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nint ret;\r\nu8 buf[2];\r\n*status = 0;\r\nret = cxd2820r_rd_regs(priv, 0x10088, buf, sizeof(buf));\r\nif (ret)\r\ngoto error;\r\nif (((buf[0] >> 0) & 0x01) == 1) {\r\n*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |\r\nFE_HAS_VITERBI | FE_HAS_SYNC;\r\nif (((buf[1] >> 3) & 0x01) == 1) {\r\n*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |\r\nFE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;\r\n}\r\n}\r\ndev_dbg(&priv->i2c->dev, "%s: lock=%02x %02x\n", __func__, buf[0],\r\nbuf[1]);\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_init_c(struct dvb_frontend *fe)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nint ret;\r\nret = cxd2820r_wr_reg(priv, 0x00085, 0x07);\r\nif (ret)\r\ngoto error;\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_sleep_c(struct dvb_frontend *fe)\r\n{\r\nstruct cxd2820r_priv *priv = fe->demodulator_priv;\r\nint ret, i;\r\nstruct reg_val_mask tab[] = {\r\n{ 0x000ff, 0x1f, 0xff },\r\n{ 0x00085, 0x00, 0xff },\r\n{ 0x00088, 0x01, 0xff },\r\n{ 0x00081, 0x00, 0xff },\r\n{ 0x00080, 0x00, 0xff },\r\n};\r\ndev_dbg(&priv->i2c->dev, "%s\n", __func__);\r\npriv->delivery_system = SYS_UNDEFINED;\r\nfor (i = 0; i < ARRAY_SIZE(tab); i++) {\r\nret = cxd2820r_wr_reg_mask(priv, tab[i].reg, tab[i].val,\r\ntab[i].mask);\r\nif (ret)\r\ngoto error;\r\n}\r\nreturn ret;\r\nerror:\r\ndev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);\r\nreturn ret;\r\n}\r\nint cxd2820r_get_tune_settings_c(struct dvb_frontend *fe,\r\nstruct dvb_frontend_tune_settings *s)\r\n{\r\ns->min_delay_ms = 500;\r\ns->step_size = 0;\r\ns->max_drift = 0;\r\nreturn 0;\r\n}
