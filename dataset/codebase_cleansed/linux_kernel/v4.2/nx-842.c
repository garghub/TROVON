int nx842_constraints(struct nx842_constraints *c)
{
memcpy(c, nx842_platform_driver()->constraints, sizeof(*c));
return 0;
}
size_t nx842_workmem_size(void)
{
return nx842_platform_driver()->workmem_size;
}
int nx842_compress(const unsigned char *in, unsigned int ilen,
unsigned char *out, unsigned int *olen, void *wmem)
{
return nx842_platform_driver()->compress(in, ilen, out, olen, wmem);
}
int nx842_decompress(const unsigned char *in, unsigned int ilen,
unsigned char *out, unsigned int *olen, void *wmem)
{
return nx842_platform_driver()->decompress(in, ilen, out, olen, wmem);
}
static __init int nx842_init(void)
{
request_module("nx-compress-powernv");
request_module("nx-compress-pseries");
if (!nx842_platform_driver_get()) {
pr_err("no nx842 driver found.\n");
return -ENODEV;
}
return 0;
}
static void __exit nx842_exit(void)
{
nx842_platform_driver_put();
}
