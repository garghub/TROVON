void ldlm_ibits_policy_wire_to_local(const ldlm_wire_policy_data_t *wpolicy,
ldlm_policy_data_t *lpolicy)
{
memset(lpolicy, 0, sizeof(*lpolicy));
lpolicy->l_inodebits.bits = wpolicy->l_inodebits.bits;
}
void ldlm_ibits_policy_local_to_wire(const ldlm_policy_data_t *lpolicy,
ldlm_wire_policy_data_t *wpolicy)
{
memset(wpolicy, 0, sizeof(*wpolicy));
wpolicy->l_inodebits.bits = lpolicy->l_inodebits.bits;
}
