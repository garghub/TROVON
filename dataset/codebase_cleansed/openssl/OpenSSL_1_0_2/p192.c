main()
{
DH *dh;
dh = DH_new();
dh->p = BN_bin2bn(data, sizeof(data), NULL);
dh->g = BN_new();
BN_set_word(dh->g, 3);
PEM_write_DHparams(stdout, dh);
}
