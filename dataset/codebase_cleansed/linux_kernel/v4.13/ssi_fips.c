int ssi_fips_get_state(enum cc_fips_state_t *p_state)
{
int rc = 0;
if (!p_state)
return -EINVAL;
rc = ssi_fips_ext_get_state(p_state);
return rc;
}
int ssi_fips_get_error(enum cc_fips_error *p_err)
{
int rc = 0;
if (!p_err)
return -EINVAL;
rc = ssi_fips_ext_get_error(p_err);
return rc;
}
