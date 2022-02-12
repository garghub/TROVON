static int ocsp_check_delegated(X509 *x, int flags)
{
X509_check_purpose(x, -1, 0);
if ((x->ex_flags & EXFLAG_XKUSAGE) &&
(x->ex_xkusage & XKU_OCSP_SIGN))
return 1;
OCSPerr(OCSP_F_OCSP_CHECK_DELEGATED, OCSP_R_MISSING_OCSPSIGNING_USAGE);
return 0;
}
