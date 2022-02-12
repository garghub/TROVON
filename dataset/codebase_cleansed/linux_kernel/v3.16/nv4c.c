static void\r\nnv4c_mc_msi_rearm(struct nouveau_mc *pmc)\r\n{\r\nstruct nv04_mc_priv *priv = (void *)pmc;\r\nnv_wr08(priv, 0x088050, 0xff);\r\n}
