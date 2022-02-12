int ssi_fips_get_state(ssi_fips_state_t *p_state)
{
int rc = 0;
if (p_state == NULL) {
return -EINVAL;
}
rc = ssi_fips_ext_get_state(p_state);
return rc;
}
int ssi_fips_get_error(ssi_fips_error_t *p_err)
{
int rc = 0;
if (p_err == NULL) {
return -EINVAL;
}
rc = ssi_fips_ext_get_error(p_err);
return rc;
}
