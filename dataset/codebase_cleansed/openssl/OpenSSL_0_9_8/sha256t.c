int main(int argc, char *argv[])
{
printf("No SHA256 support\n");
return(0);
}
int main ()
{ unsigned char md[SHA256_DIGEST_LENGTH];
int i;
EVP_MD_CTX evp;
fprintf(stdout,"Testing SHA-256 ");
EVP_Digest ("abc",3,md,NULL,EVP_sha256(),NULL);
if (memcmp(md,app_b1,sizeof(app_b1)))
{ fflush(stdout);
fprintf(stderr,"\nTEST 1 of 3 failed.\n");
return 1;
}
else
fprintf(stdout,"."); fflush(stdout);
EVP_Digest ("abcdbcde""cdefdefg""efghfghi""ghijhijk"
"ijkljklm""klmnlmno""mnopnopq",56,md,NULL,EVP_sha256(),NULL);
if (memcmp(md,app_b2,sizeof(app_b2)))
{ fflush(stdout);
fprintf(stderr,"\nTEST 2 of 3 failed.\n");
return 1;
}
else
fprintf(stdout,"."); fflush(stdout);
EVP_MD_CTX_init (&evp);
EVP_DigestInit_ex (&evp,EVP_sha256(),NULL);
for (i=0;i<1000000;i+=160)
EVP_DigestUpdate (&evp, "aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa"
"aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa"
"aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa"
"aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa"
"aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa",
(1000000-i)<160?1000000-i:160);
EVP_DigestFinal_ex (&evp,md,NULL);
EVP_MD_CTX_cleanup (&evp);
if (memcmp(md,app_b3,sizeof(app_b3)))
{ fflush(stdout);
fprintf(stderr,"\nTEST 3 of 3 failed.\n");
return 1;
}
else
fprintf(stdout,"."); fflush(stdout);
fprintf(stdout," passed.\n"); fflush(stdout);
fprintf(stdout,"Testing SHA-224 ");
EVP_Digest ("abc",3,md,NULL,EVP_sha224(),NULL);
if (memcmp(md,addenum_1,sizeof(addenum_1)))
{ fflush(stdout);
fprintf(stderr,"\nTEST 1 of 3 failed.\n");
return 1;
}
else
fprintf(stdout,"."); fflush(stdout);
EVP_Digest ("abcdbcde""cdefdefg""efghfghi""ghijhijk"
"ijkljklm""klmnlmno""mnopnopq",56,md,NULL,EVP_sha224(),NULL);
if (memcmp(md,addenum_2,sizeof(addenum_2)))
{ fflush(stdout);
fprintf(stderr,"\nTEST 2 of 3 failed.\n");
return 1;
}
else
fprintf(stdout,"."); fflush(stdout);
EVP_MD_CTX_init (&evp);
EVP_DigestInit_ex (&evp,EVP_sha224(),NULL);
for (i=0;i<1000000;i+=64)
EVP_DigestUpdate (&evp, "aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa"
"aaaaaaaa""aaaaaaaa""aaaaaaaa""aaaaaaaa",
(1000000-i)<64?1000000-i:64);
EVP_DigestFinal_ex (&evp,md,NULL);
EVP_MD_CTX_cleanup (&evp);
if (memcmp(md,addenum_3,sizeof(addenum_3)))
{ fflush(stdout);
fprintf(stderr,"\nTEST 3 of 3 failed.\n");
return 1;
}
else
fprintf(stdout,"."); fflush(stdout);
fprintf(stdout," passed.\n"
