static void
nv4c_mc_msi_rearm(struct nouveau_mc *pmc)
{
struct nv04_mc_priv *priv = (void *)pmc;
nv_wr08(priv, 0x088050, 0xff);
}
