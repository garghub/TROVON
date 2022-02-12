int ssi_fips_ext_get_state(enum cc_fips_state_t *p_state)
{
int rc = 0;
if (!p_state)
return -EINVAL;
*p_state = fips_state;
return rc;
}
int ssi_fips_ext_get_error(enum cc_fips_error *p_err)
{
int rc = 0;
if (!p_err)
return -EINVAL;
*p_err = fips_error;
return rc;
}
int ssi_fips_ext_set_state(enum cc_fips_state_t state)
{
fips_state = state;
return 0;
}
int ssi_fips_ext_set_error(enum cc_fips_error err)
{
fips_error = err;
return 0;
}
