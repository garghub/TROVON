int prime_main(int argc, char **argv)
{
BIGNUM *bn = NULL;
int hex = 0, checks = 20, generate = 0, bits = 0, safe = 0, ret = 1;
char *prog;
OPTION_CHOICE o;
prog = opt_init(argc, argv, prime_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(prime_options);
ret = 0;
goto end;
case OPT_HEX:
hex = 1;
break;
case OPT_GENERATE:
generate = 1;
break;
case OPT_BITS:
bits = atoi(opt_arg());
break;
case OPT_SAFE:
safe = 1;
break;
case OPT_CHECKS:
checks = atoi(opt_arg());
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
if (argc == 0 && !generate) {
BIO_printf(bio_err, "%s: No prime specified\n", prog);
goto end;
}
if (generate) {
char *s;
if (!bits) {
BIO_printf(bio_err, "Specify the number of bits.\n");
goto end;
}
bn = BN_new();
if (bn == NULL) {
BIO_printf(bio_err, "Out of memory.\n");
goto end;
}
if (!BN_generate_prime_ex(bn, bits, safe, NULL, NULL, NULL)) {
BIO_printf(bio_err, "Failed to generate prime.\n");
goto end;
}
s = hex ? BN_bn2hex(bn) : BN_bn2dec(bn);
if (s == NULL) {
BIO_printf(bio_err, "Out of memory.\n");
goto end;
}
BIO_printf(bio_out, "%s\n", s);
OPENSSL_free(s);
} else {
for ( ; *argv; argv++) {
int r;
if (hex)
r = BN_hex2bn(&bn, argv[0]);
else
r = BN_dec2bn(&bn, argv[0]);
if(!r) {
BIO_printf(bio_err, "Failed to process value (%s)\n", argv[0]);
goto end;
}
BN_print(bio_out, bn);
BIO_printf(bio_out, " (%s) %s prime\n",
argv[0],
BN_is_prime_ex(bn, checks, NULL, NULL)
? "is" : "is not");
}
}
ret = 0;
end:
BN_free(bn);
return ret;
}
