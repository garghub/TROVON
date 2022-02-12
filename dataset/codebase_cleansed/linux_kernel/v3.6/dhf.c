int
check_comp_fw(memimage *fw)
{
CFG_RANGE20_STRCT *p;
int rc = HCF_SUCCESS;
CFG_RANGE_SPEC_STRCT *i;
switch (fw->identity->typ) {
case CFG_FW_IDENTITY:
case COMP_ID_FW_AP_FAKE:
break;
default:
MMDASSERT(DO_ASSERT, fw->identity->typ)
rc = DHF_ERR_INCOMP_FW;
return rc;
}
p = fw->compat;
i = NULL;
while (p->len && i == NULL) {
if (p->typ == CFG_MFI_ACT_RANGES_STA) {
i = mmd_check_comp((void *)p, &mfi_sup);
}
p++;
}
MMDASSERT(i, 0)
if (i) {
p = fw->compat;
i = NULL;
while (p->len && i == NULL) {
if (p->typ == CFG_CFI_ACT_RANGES_STA) {
i = mmd_check_comp((void *)p, &cfi_sup);
}
p++;
}
MMDASSERT(i, 0)
}
if (i == NULL) {
rc = DHF_ERR_INCOMP_FW;
}
return rc;
}
int
dhf_download_binary(memimage *fw)
{
int rc = HCF_SUCCESS;
CFG_PROG_STRCT *p;
int i;
for (i = 0; i < sizeof(signature) && fw->signature[i] == signature[i]; i++)
;
if (i != sizeof(signature) ||
fw->signature[i] != 0x01 ||
fw->signature[i+1] != ( 'L'))
rc = DHF_ERR_INCOMP_FW;
else {
fw->codep = (CFG_PROG_STRCT FAR*)((char *)fw->codep + (hcf_32)fw);
fw->identity = (CFG_IDENTITY_STRCT FAR*)((char *)fw->identity + (hcf_32)fw);
fw->compat = (CFG_RANGE20_STRCT FAR*)((char *)fw->compat + (hcf_32)fw);
for (i = 0; fw->p[i]; i++)
fw->p[i] = ((char *)fw->p[i] + (hcf_32)fw);
p = fw->codep;
while (p->len) {
p->host_addr = (char *)p->host_addr + (hcf_32)fw;
p++;
}
}
return rc;
}
int
dhf_download_fw(void *ifbp, memimage *fw)
{
int rc = HCF_SUCCESS;
LTV_INFO_STRUCT_PTR pp = ltv_info;
CFG_PROG_STRCT *p = fw->codep;
LTVP ltvp;
int i;
MMDASSERT(fw != NULL, 0)
for (i = 0; i < sizeof(signature) && fw->signature[i] == signature[i]; i++)
;
if (i != sizeof(signature) ||
fw->signature[i] != 0x01 ||
(fw->signature[i+1] != 'C' && fw->signature[i+1] != ( 'L')))
rc = DHF_ERR_INCOMP_FW;
while ((rc == HCF_SUCCESS) && ((ltvp = pp->ltvp) != NULL)) {
ltvp->len = pp++->len;
rc = GET_INFO(ltvp);
MMDASSERT(rc == HCF_SUCCESS, rc)
MMDASSERT(rc == HCF_SUCCESS, ltvp->typ)
MMDASSERT(rc == HCF_SUCCESS, ltvp->len)
}
if (rc == HCF_SUCCESS)
rc = check_comp_fw(fw);
if (rc == HCF_SUCCESS) {
while (rc == HCF_SUCCESS && p->len) {
rc = PUT_INFO(p);
p++;
}
}
MMDASSERT(rc == HCF_SUCCESS, rc)
return rc;
}
