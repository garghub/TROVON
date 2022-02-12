static int ocsp_check_delegated(X509 *x)
{
if ((X509_get_extension_flags(x) & EXFLAG_XKUSAGE)
&& (X509_get_extended_key_usage(x) & XKU_OCSP_SIGN))
return 1;
OCSPerr(OCSP_F_OCSP_CHECK_DELEGATED, OCSP_R_MISSING_OCSPSIGNING_USAGE);
return 0;
}
