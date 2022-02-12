int ssi_fips_ext_get_state(ssi_fips_state_t *p_state)
{
int rc = 0;
if (p_state == NULL) {
return -EINVAL;
}
*p_state = fips_state;
return rc;
}
int ssi_fips_ext_get_error(ssi_fips_error_t *p_err)
{
int rc = 0;
if (p_err == NULL) {
return -EINVAL;
}
*p_err = fips_error;
return rc;
}
int ssi_fips_ext_set_state(ssi_fips_state_t state)
{
fips_state = state;
return 0;
}
int ssi_fips_ext_set_error(ssi_fips_error_t err)
{
fips_error = err;
return 0;
}
