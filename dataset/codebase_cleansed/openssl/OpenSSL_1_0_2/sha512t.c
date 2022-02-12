int main(int argc, char *argv[])
{
printf("No SHA512 support\n");
return (0);
}
int main(int argc, char **argv)
{
unsigned char md[SHA512_DIGEST_LENGTH];
int i;
EVP_MD_CTX evp;
# ifdef OPENSSL_IA32_SSE2
{
char *env;
if ((env = getenv("OPENSSL_ia32cap")))
OPENSSL_ia32cap = strtoul(env, NULL, 0);
}
# endif
fprintf(stdout, "Testing SHA-512 ");
EVP_Digest("abc", 3, md, NULL, EVP_sha512(), NULL);
if (memcmp(md, app_c1, sizeof(app_c1))) {
fflush(stdout);
fprintf(stderr, "\nTEST 1 of 3 failed.\n");
return 1;
} else
fprintf(stdout, ".");
fflush(stdout);
EVP_Digest("abcdefgh" "bcdefghi" "cdefghij" "defghijk"
"efghijkl" "fghijklm" "ghijklmn" "hijklmno"
"ijklmnop" "jklmnopq" "klmnopqr" "lmnopqrs"
"mnopqrst" "nopqrstu", 112, md, NULL, EVP_sha512(), NULL);
if (memcmp(md, app_c2, sizeof(app_c2))) {
fflush(stdout);
fprintf(stderr, "\nTEST 2 of 3 failed.\n");
return 1;
} else
fprintf(stdout, ".");
fflush(stdout);
EVP_MD_CTX_init(&evp);
EVP_DigestInit_ex(&evp, EVP_sha512(), NULL);
for (i = 0; i < 1000000; i += 288)
EVP_DigestUpdate(&evp, "aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa",
(1000000 - i) < 288 ? 1000000 - i : 288);
EVP_DigestFinal_ex(&evp, md, NULL);
EVP_MD_CTX_cleanup(&evp);
if (memcmp(md, app_c3, sizeof(app_c3))) {
fflush(stdout);
fprintf(stderr, "\nTEST 3 of 3 failed.\n");
return 1;
} else
fprintf(stdout, ".");
fflush(stdout);
fprintf(stdout, " passed.\n");
fflush(stdout);
fprintf(stdout, "Testing SHA-384 ");
EVP_Digest("abc", 3, md, NULL, EVP_sha384(), NULL);
if (memcmp(md, app_d1, sizeof(app_d1))) {
fflush(stdout);
fprintf(stderr, "\nTEST 1 of 3 failed.\n");
return 1;
} else
fprintf(stdout, ".");
fflush(stdout);
EVP_Digest("abcdefgh" "bcdefghi" "cdefghij" "defghijk"
"efghijkl" "fghijklm" "ghijklmn" "hijklmno"
"ijklmnop" "jklmnopq" "klmnopqr" "lmnopqrs"
"mnopqrst" "nopqrstu", 112, md, NULL, EVP_sha384(), NULL);
if (memcmp(md, app_d2, sizeof(app_d2))) {
fflush(stdout);
fprintf(stderr, "\nTEST 2 of 3 failed.\n");
return 1;
} else
fprintf(stdout, ".");
fflush(stdout);
EVP_MD_CTX_init(&evp);
EVP_DigestInit_ex(&evp, EVP_sha384(), NULL);
for (i = 0; i < 1000000; i += 64)
EVP_DigestUpdate(&evp, "aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa"
"aaaaaaaa" "aaaaaaaa" "aaaaaaaa" "aaaaaaaa",
(1000000 - i) < 64 ? 1000000 - i : 64);
EVP_DigestFinal_ex(&evp, md, NULL);
EVP_MD_CTX_cleanup(&evp);
if (memcmp(md, app_d3, sizeof(app_d3))) {
fflush(stdout);
fprintf(stderr, "\nTEST 3 of 3 failed.\n");
return 1;
} else
fprintf(stdout, ".");
fflush(stdout);
fprintf(stdout, " passed.\n");
fflush(stdout);
return 0;
}
