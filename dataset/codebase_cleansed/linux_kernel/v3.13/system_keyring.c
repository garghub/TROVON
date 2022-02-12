static __init int system_trusted_keyring_init(void)
{
pr_notice("Initialise system trusted keyring\n");
system_trusted_keyring =
keyring_alloc(".system_keyring",
KUIDT_INIT(0), KGIDT_INIT(0), current_cred(),
((KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ | KEY_USR_SEARCH),
KEY_ALLOC_NOT_IN_QUOTA, NULL);
if (IS_ERR(system_trusted_keyring))
panic("Can't allocate system trusted keyring\n");
set_bit(KEY_FLAG_TRUSTED_ONLY, &system_trusted_keyring->flags);
return 0;
}
static __init int load_system_certificate_list(void)
{
key_ref_t key;
const u8 *p, *end;
size_t plen;
pr_notice("Loading compiled-in X.509 certificates\n");
p = system_certificate_list;
end = p + system_certificate_list_size;
while (p < end) {
if (end - p < 4)
goto dodgy_cert;
if (p[0] != 0x30 &&
p[1] != 0x82)
goto dodgy_cert;
plen = (p[2] << 8) | p[3];
plen += 4;
if (plen > end - p)
goto dodgy_cert;
key = key_create_or_update(make_key_ref(system_trusted_keyring, 1),
"asymmetric",
NULL,
p,
plen,
((KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ),
KEY_ALLOC_NOT_IN_QUOTA |
KEY_ALLOC_TRUSTED);
if (IS_ERR(key)) {
pr_err("Problem loading in-kernel X.509 certificate (%ld)\n",
PTR_ERR(key));
} else {
pr_notice("Loaded X.509 cert '%s'\n",
key_ref_to_ptr(key)->description);
key_ref_put(key);
}
p += plen;
}
return 0;
dodgy_cert:
pr_err("Problem parsing in-kernel X.509 certificate list\n");
return 0;
}
