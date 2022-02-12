struct nfp_nsp_identify *__nfp_nsp_identify(struct nfp_nsp *nsp)
{
struct nfp_nsp_identify *nspi = NULL;
struct nsp_identify *ni;
int ret;
if (nfp_nsp_get_abi_ver_minor(nsp) < 15)
return NULL;
ni = kzalloc(sizeof(*ni), GFP_KERNEL);
if (!ni)
return NULL;
ret = nfp_nsp_read_identify(nsp, ni, sizeof(*ni));
if (ret < 0) {
nfp_err(nfp_nsp_cpp(nsp), "reading bsp version failed %d\n",
ret);
goto exit_free;
}
nspi = kzalloc(sizeof(*nspi), GFP_KERNEL);
if (!nspi)
goto exit_free;
memcpy(nspi->version, ni->version, sizeof(nspi->version));
nspi->version[sizeof(nspi->version) - 1] = '\0';
nspi->flags = ni->flags;
nspi->br_primary = ni->br_primary;
nspi->br_secondary = ni->br_secondary;
nspi->br_nsp = ni->br_nsp;
nspi->primary = le16_to_cpu(ni->primary);
nspi->secondary = le16_to_cpu(ni->secondary);
nspi->nsp = le16_to_cpu(ni->nsp);
exit_free:
kfree(ni);
return nspi;
}
