void ldlm_ibits_policy_wire_to_local(const union ldlm_wire_policy_data *wpolicy,
union ldlm_policy_data *lpolicy)
{
memset(lpolicy, 0, sizeof(*lpolicy));
lpolicy->l_inodebits.bits = wpolicy->l_inodebits.bits;
}
void ldlm_ibits_policy_local_to_wire(const union ldlm_policy_data *lpolicy,
union ldlm_wire_policy_data *wpolicy)
{
memset(wpolicy, 0, sizeof(*wpolicy));
wpolicy->l_inodebits.bits = lpolicy->l_inodebits.bits;
}
