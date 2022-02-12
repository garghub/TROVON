u32 prandom_u32(void)
{
abort();
}
static struct new_utsname *init_utsname(void)
{
static struct new_utsname n = (struct new_utsname) {
.release = "liblockdep",
.version = LIBLOCKDEP_VERSION,
};
return &n;
}
