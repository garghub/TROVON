static int __init zcrypt_init(void)
{
int rc;
rc = ap_module_init();
if (rc)
goto out;
rc = zcrypt_api_init();
if (rc)
goto out_ap;
rc = zcrypt_pcica_init();
if (rc)
goto out_api;
rc = zcrypt_pcicc_init();
if (rc)
goto out_pcica;
rc = zcrypt_pcixcc_init();
if (rc)
goto out_pcicc;
rc = zcrypt_cex2a_init();
if (rc)
goto out_pcixcc;
return 0;
out_pcixcc:
zcrypt_pcixcc_exit();
out_pcicc:
zcrypt_pcicc_exit();
out_pcica:
zcrypt_pcica_exit();
out_api:
zcrypt_api_exit();
out_ap:
ap_module_exit();
out:
return rc;
}
static void __exit zcrypt_exit(void)
{
zcrypt_cex2a_exit();
zcrypt_pcixcc_exit();
zcrypt_pcicc_exit();
zcrypt_pcica_exit();
zcrypt_api_exit();
ap_module_exit();
}
