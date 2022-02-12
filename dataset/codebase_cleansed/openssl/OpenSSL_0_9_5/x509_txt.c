const char *X509_verify_cert_error_string(long n)
{
static char buf[100];
switch ((int)n)
{
case X509_V_OK:
return("ok");
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
return("unable to get issuer certificate");
case X509_V_ERR_UNABLE_TO_GET_CRL:
return("unable to get certificate CRL");
case X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE:
return("unable to decrypt certificate's signature");
case X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE:
return("unable to decrypt CRL's's signature");
case X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY:
return("unable to decode issuer public key");
case X509_V_ERR_CERT_SIGNATURE_FAILURE:
return("certificate signature failure");
case X509_V_ERR_CRL_SIGNATURE_FAILURE:
return("CRL signature failure");
case X509_V_ERR_CERT_NOT_YET_VALID:
return("certificate is not yet valid");
case X509_V_ERR_CRL_NOT_YET_VALID:
return("CRL is not yet valid");
case X509_V_ERR_CERT_HAS_EXPIRED:
return("Certificate has expired");
case X509_V_ERR_CRL_HAS_EXPIRED:
return("CRL has expired");
case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
return("format error in certificate's notBefore field");
case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
return("format error in certificate's notAfter field");
case X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD:
return("format error in CRL's lastUpdate field");
case X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD:
return("format error in CRL's nextUpdate field");
case X509_V_ERR_OUT_OF_MEM:
return("out of memory");
case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
return("self signed certificate");
case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
return("self signed certificate in certificate chain");
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY:
return("unable to get local issuer certificate");
case X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE:
return("unable to verify the first certificate");
case X509_V_ERR_CERT_CHAIN_TOO_LONG:
return("certificate chain too long");
case X509_V_ERR_CERT_REVOKED:
return("certificate revoked");
case X509_V_ERR_INVALID_CA:
return ("invalid CA certificate");
case X509_V_ERR_PATH_LENGTH_EXCEEDED:
return ("path length constraint exceeded");
case X509_V_ERR_INVALID_PURPOSE:
return ("unsupported certificate purpose");
case X509_V_ERR_CERT_UNTRUSTED:
return ("certificate not trusted");
case X509_V_ERR_CERT_REJECTED:
return ("certificate rejected");
case X509_V_ERR_APPLICATION_VERIFICATION:
return("application verification failure");
default:
sprintf(buf,"error number %ld",n);
return(buf);
}
}
